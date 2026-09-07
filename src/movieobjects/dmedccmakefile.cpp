// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmedccmakefile.cpp
// Functions: 107
// ============================================================

#include "movieobjects\dmedccmakefile.h"

//------------------------------------------------------------------------------
// Address: 0x004ACD30
// Name: private: virtual void CDmeDCCMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::DestroyOutputElement(CDmeDCCMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushFile = true;
}

//------------------------------------------------------------------------------
// Address: 0x004ACD40
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetSourceTypes(CDmeMayaModelMakefile *this)
{
  return s_pMayaModelSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x004ACD50
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetSourceTypes(CDmeMayaAnimationMakefile *this)
{
  return s_pMayaAnimationSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x004ACD60
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetMakefileType(CDmeMayaModelMakefile *this)
{
  return &s_MayaModelMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x004ACD70
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetMakefileType(CDmeMayaAnimationMakefile *this)
{
  return &s_MayaAnimationMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x004ACD80
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetSourceTypes(CDmeXSIMakefile *this)
{
  return s_pXSISourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x004ACD90
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetMakefileType(CDmeXSIMakefile *this)
{
  return &s_XSIMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x004ACDA0
// Name: protected: void CDmeSourceDCCFile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::OnConstruction(CDmeSourceDCCFile *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_RootDCCObjects,
    pOwner: this,
    pAttributeName: "rootDCCObjects",
    nFlags: 0);
  value = 0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "exportType", type: AT_INT, pMemory: &this->m_ExportType);
  this->m_ExportType.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameStart",
         type: AT_FLOAT,
         pMemory: &this->m_FrameStart);
  this->m_FrameStart.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (float *)&value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "frameEnd", type: AT_FLOAT, pMemory: &this->m_FrameEnd);
  this->m_FrameEnd.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, (float *)&value);
  value = 1065353216;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameIncrement",
         type: AT_FLOAT,
         pMemory: &this->m_FrameIncrement);
  this->m_FrameIncrement.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, (float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x004ACE70
// Name: private: virtual class CDmElement __near * CDmeDCCMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeDCCMakefile::CreateOutputElement(CDmeDCCMakefile *this)
{
  bool v2; // zf
  DmElementHandle_t v3; // esi
  CDmElement *v4; // eax
  DmFileId_t m_fileId; // esi
  IDataModel_vtbl *v6; // edi
  int v7; // eax
  CDmElement *v8; // eax
  int v9; // esi
  CUtlSymbolLarge *v11; // eax
  CDmElement *pRoot; // [esp+8h] [ebp-8h] BYREF
  CDmeHandle<CDmeDCCMakefile,0> hMakefileOld; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bFlushFile || (v2 = this->m_fileId == DMFILEID_INVALID, this->m_bFlushFile = false, v2) )
  {
    v11 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pRoot, a3: "makefile");
    return FindReferringElement<CDmElement>(
             pElement: (CExpressionCalculator *)this,
             symAttrName: (CUtlSymbolLarge)v11->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  else
  {
    hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
    v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
    if ( v3 != DMELEMENT_HANDLE_INVALID )
    {
      CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      hMakefileOld.m_handle = v3;
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
      if ( v4 != nullptr && !v4->IsA(this: v4, a2: CDmeDCCMakefile::m_classType) )
        hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
      CDmeElementRefHelper::Ref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
    }
    m_fileId = this->m_fileId;
    g_pDataModel->UnloadFile(this: g_pDataModel, a2: m_fileId);
    pRoot = nullptr;
    v6 = g_pDataModel->__vftable;
    v7 = ((int (__thiscall *)(IDataModel *, DmFileId_t, _DWORD, _DWORD, CDmElement **, int, _DWORD))g_pDataModel->GetFileName)(
           a1: g_pDataModel,
           a2: m_fileId,
           a3: 0,
           a4: 0,
           a5: &pRoot,
           a6: 1,
           a7: 0);
    if ( ((int (__thiscall *)(IDataModel *, int))v6->RestoreFromFile)(a1: g_pDataModel, a2: v7) == -1
      || g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle) == nullptr )
    {
      if ( g_pDataModel != nullptr )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return nullptr;
    }
    else
    {
      *((_BYTE *)&g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle)[1].m_ref + 8) = 0;
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle);
      v9 = ((int (__thiscall *)(CDmElement *))v8->__vftable[1].Resolve)(a1: v8);
      if ( g_pDataModel != nullptr )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return (CDmElement *)v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AD000
// Name: public: virtual void CDmeDCCMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::GetOutputs(
        CDmeDCCMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString src; // [esp+314h] [ebp-10h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetMakefilePath(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.dmx", pOutputDir, pOutputName);
      CUtlString::CUtlString(this: &src, pString: pFullPath);
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: fullPaths, elem: fullPaths->m_Size, &src);
      src.m_Storage.m_nActualLength = 0;
      if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AD140
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
// Address: 0x004AD170
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
// Address: 0x004AD560
// Name: protected: virtual void CDmeMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformConstruction(CDmeMakefile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMakefile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004AD570
// Name: private: virtual char const __near * CDmeMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetOutputDirectoryID(CDmeMakefile *this)
{
  return "makefilegamedir:";
}

//------------------------------------------------------------------------------
// Address: 0x004AD580
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
// Address: 0x004AD5B0
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
// Address: 0x004AD5F0
// Name: protected: virtual int CDmeMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::AllocatedSize(CDmeMakefile *this)
{
  return 108;
}

//------------------------------------------------------------------------------
// Address: 0x004AD650
// Name: public: virtual bool CDmeSourceDCCFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceDCCFile::IsA(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AD680
// Name: public: virtual int CDmeSourceDCCFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceDCCFile::GetInheritanceDepth(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AD720
// Name: public: virtual bool CDmeSourceMayaFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaFile::IsA(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AD760
// Name: public: virtual int CDmeSourceMayaFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaFile::GetInheritanceDepth(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AD7C0
// Name: protected: virtual void CDmeSourceDCCFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::PerformConstruction(CDmeSourceXSIFile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004AD830
// Name: public: virtual bool CDmeSourceMayaModelFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaModelFile::IsA(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AD870
// Name: public: virtual int CDmeSourceMayaModelFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaModelFile::GetInheritanceDepth(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AD8E0
// Name: protected: virtual void CDmeSource::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::PerformDestruction(CDmeShape *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004AD900
// Name: protected: virtual void CDmeSourceMayaModelFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaModelFile::PerformConstruction(CDmeSourceMayaModelFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004AD990
// Name: public: virtual bool CDmeSourceMayaAnimationFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaAnimationFile::IsA(CDmeSourceMayaAnimationFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AD9D0
// Name: public: virtual int CDmeSourceMayaAnimationFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaAnimationFile::GetInheritanceDepth(
        CDmeSourceMayaAnimationFile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADA40
// Name: protected: virtual void CDmeSourceMayaAnimationFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaAnimationFile::PerformConstruction(CDmeSourceMayaAnimationFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 1;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004ADAD0
// Name: public: virtual bool CDmeSourceXSIFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceXSIFile::IsA(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADB10
// Name: public: virtual int CDmeSourceXSIFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceXSIFile::GetInheritanceDepth(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADBC0
// Name: private: virtual char const __near * CDmeDCCMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeDCCMakefile::GetOutputDirectoryID(CDmeDCCMakefile *this)
{
  return "makefiledir:..\\dmx";
}

//------------------------------------------------------------------------------
// Address: 0x004ADBD0
// Name: public: virtual bool CDmeDCCMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDCCMakefile::IsA(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADC00
// Name: public: virtual int CDmeDCCMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::GetInheritanceDepth(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADC50
// Name: protected: virtual void CDmeMayaAnimationMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaAnimationMakefile::PerformConstruction(CDmeMayaAnimationMakefile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMakefile::OnConstruction(this);
  this->m_bFlushFile = false;
}

//------------------------------------------------------------------------------
// Address: 0x004ADCC0
// Name: public: virtual bool CDmeMayaMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaMakefile::IsA(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADD00
// Name: public: virtual int CDmeMayaMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaMakefile::GetInheritanceDepth(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADDB0
// Name: public: virtual bool CDmeXSIMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeXSIMakefile::IsA(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADDF0
// Name: public: virtual int CDmeXSIMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeXSIMakefile::GetInheritanceDepth(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADEA0
// Name: public: virtual bool CDmeMayaModelMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaModelMakefile::IsA(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADEE0
// Name: public: virtual int CDmeMayaModelMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaModelMakefile::GetInheritanceDepth(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADF50
// Name: protected: virtual void CDmeMayaModelMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaModelMakefile::PerformDestruction(CDmeMayaAnimationMakefile *this)
{
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004ADFB0
// Name: public: virtual bool CDmeMayaAnimationMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaAnimationMakefile::IsA(CDmeMayaAnimationMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADFF0
// Name: public: virtual int CDmeMayaAnimationMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaAnimationMakefile::GetInheritanceDepth(
        CDmeMayaAnimationMakefile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AE060
// Name: protected: virtual int CDmeDCCMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::AllocatedSize(CDmeMayaAnimationMakefile *this)
{
  return 112;
}

//------------------------------------------------------------------------------
// Address: 0x004B4540
// Name: protected: virtual void CDmeSource::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::PerformConstruction(CDmeSourceCollisionModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004B4550
// Name: protected: virtual int CDmeSource::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::AllocatedSize(CDmeSourceCollisionModel *this)
{
  return 72;
}

//------------------------------------------------------------------------------
// Address: 0x005ABB00
// Name: _dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceDCCFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceDCCFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABB60
// Name: _dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABBC0
// Name: _dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaModelFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaModelFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABC20
// Name: _dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaAnimationFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaAnimationFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABC80
// Name: _dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceXSIFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceXSIFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABCE0
// Name: _dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDCCMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDCCMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABD40
// Name: _dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABDA0
// Name: _dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaModelMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaModelMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABE00
// Name: _dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaAnimationMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaAnimationMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABE60
// Name: _dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeXSIMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeXSIMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC100
// Name: _dynamic_initializer_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSource::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSource pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSource::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC160
// Name: _dynamic_initializer_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMakefile::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AFA80
// Name: _dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceDCCFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AFA90
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AFAA0
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaModelFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AFAB0
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaAnimationFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AFAC0
// Name: _dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceXSIFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AFAD0
// Name: _dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDCCMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AFAE0
// Name: _dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AFAF0
// Name: _dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaModelMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AFB00
// Name: _dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaAnimationMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AFB10
// Name: _dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeXSIMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AFC80
// Name: _dynamic_atexit_destructor_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSource::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AFC90
// Name: _dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ABB30
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABB40
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceDCCFile_Helper,
           classname: "DmeSourceDCCFile",
           pFactory: &g_CDmeSourceDCCFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ABB90
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABBA0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaFile_Helper,
           classname: "DmeSourceMayaFile",
           pFactory: &g_CDmeSourceMayaFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ABBF0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABC00
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaModelFile_Helper,
           classname: "DmeSourceMayaModelFile",
           pFactory: &g_CDmeSourceMayaModelFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ABC50
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABC60
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaAnimationFile_Helper,
           classname: "DmeSourceMayaAnimationFile",
           pFactory: &g_CDmeSourceMayaAnimationFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ABCB0
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABCC0
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceXSIFile_Helper,
           classname: "DmeSourceXSIFile",
           pFactory: &g_CDmeSourceXSIFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ABD10
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDCCMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABD20
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDCCMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDCCMakefile_Helper,
           classname: "DmeDCCMakefile",
           pFactory: &g_CDmeDCCMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ABD70
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABD80
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaMakefile_Helper,
           classname: "DmeMayaMakefile",
           pFactory: &g_CDmeMayaMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ABDD0
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABDE0
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaModelMakefile_Helper,
           classname: "DmeMayaModelMakefile",
           pFactory: &g_CDmeMayaModelMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ABE30
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABE40
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaAnimationMakefile_Helper,
           classname: "DmeMayaAnimationMakefile",
           pFactory: &g_CDmeMayaAnimationMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ABE90
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeXSIMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABEA0
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeXSIMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeXSIMakefile_Helper,
           classname: "DmeXSIMakefile",
           pFactory: &g_CDmeXSIMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AC130
// Name: _dynamic_initializer_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSource_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSource_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC140
// Name: _dynamic_initializer_for__g_CDmeSource_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSource_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSource_Helper,
           classname: "DmeSource",
           pFactory: &g_CDmeSource_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AC190
// Name: _dynamic_initializer_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC1A0
// Name: _dynamic_initializer_for__g_CDmeMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMakefile_Helper,
           classname: "DmeMakefile",
           pFactory: &g_CDmeMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AFB20
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AFB30
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaModelFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AFB40
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaAnimationFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AFB50
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceXSIFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AFB60
// Name: _dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDCCMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AFB70
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AFB80
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaModelMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AFB90
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaAnimationMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AFBA0
// Name: _dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeXSIMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AFBB0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceDCCFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AFCA0
// Name: _dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AFCB0
// Name: _dynamic_atexit_destructor_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSource_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSource_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00506C30
// Name: private: virtual void CDmeDCCMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::DestroyOutputElement(CDmeDCCMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushFile = true;
}

//------------------------------------------------------------------------------
// Address: 0x00506C40
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetSourceTypes(CDmeMayaModelMakefile *this)
{
  return s_pMayaModelSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00506C50
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetSourceTypes(CDmeMayaAnimationMakefile *this)
{
  return s_pMayaAnimationSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00506C60
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetMakefileType(CDmeMayaModelMakefile *this)
{
  return &s_MayaModelMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00506C70
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetMakefileType(CDmeMayaAnimationMakefile *this)
{
  return &s_MayaAnimationMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00506C80
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetSourceTypes(CDmeXSIMakefile *this)
{
  return s_pXSISourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00506C90
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetMakefileType(CDmeXSIMakefile *this)
{
  return &s_XSIMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00506CA0
// Name: protected: void CDmeSourceDCCFile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::OnConstruction(CDmeSourceDCCFile *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_RootDCCObjects,
    pOwner: this,
    pAttributeName: "rootDCCObjects",
    nFlags: 0);
  value = 0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "exportType", type: AT_INT, pMemory: &this->m_ExportType);
  this->m_ExportType.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameStart",
         type: AT_FLOAT,
         pMemory: &this->m_FrameStart);
  this->m_FrameStart.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (const float *)&value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "frameEnd", type: AT_FLOAT, pMemory: &this->m_FrameEnd);
  this->m_FrameEnd.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, (const float *)&value);
  value = 1065353216;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameIncrement",
         type: AT_FLOAT,
         pMemory: &this->m_FrameIncrement);
  this->m_FrameIncrement.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, (const float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x00506D70
// Name: private: virtual class CDmElement __near * CDmeDCCMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeDCCMakefile::CreateOutputElement(CDmeDCCMakefile *this)
{
  bool v2; // zf
  DmElementHandle_t BufferType; // esi
  CDmElement *v4; // eax
  DmFileId_t m_fileId; // esi
  IDataModel_vtbl *v6; // edi
  int v7; // eax
  CDmElement *v8; // eax
  int v9; // esi
  CUtlSymbolLarge *v11; // eax
  CDmElement *pRoot; // [esp+8h] [ebp-8h] BYREF
  CDmeHandle<CDmeDCCMakefile,0> hMakefileOld; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bFlushFile || (v2 = this->m_fileId == DMFILEID_INVALID, this->m_bFlushFile = false, v2) )
  {
    v11 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pRoot, a3: "makefile");
    return FindReferringElement<CDmElement>(
             pElement: (CExpressionCalculator *)this,
             symAttrName: (CUtlSymbolLarge)v11->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  else
  {
    hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
    BufferType = CCodecBuffer_Block::GetBufferType((CExpressionCalculator *)this);
    if ( BufferType != DMELEMENT_HANDLE_INVALID )
    {
      CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      hMakefileOld.m_handle = BufferType;
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: BufferType);
      if ( v4 != nullptr && !v4->IsA(this: v4, a2: CDmeDCCMakefile::m_classType) )
        hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
      CDmeElementRefHelper::Ref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
    }
    m_fileId = this->m_fileId;
    g_pDataModel->UnloadFile(this: g_pDataModel, a2: m_fileId);
    pRoot = nullptr;
    v6 = g_pDataModel->__vftable;
    v7 = ((int (__thiscall *)(IDataModel *, DmFileId_t, _DWORD, _DWORD, CDmElement **, int, _DWORD))g_pDataModel->GetFileName)(
           a1: g_pDataModel,
           a2: m_fileId,
           a3: 0,
           a4: 0,
           a5: &pRoot,
           a6: 1,
           a7: 0);
    if ( ((int (__thiscall *)(IDataModel *, int))v6->RestoreFromFile)(a1: g_pDataModel, a2: v7) == -1
      || g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle) == nullptr )
    {
      if ( g_pDataModel != nullptr )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return nullptr;
    }
    else
    {
      *((_BYTE *)&g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle)[1].m_ref + 8) = 0;
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle);
      v9 = ((int (__thiscall *)(CDmElement *))v8->__vftable[1].Resolve)(a1: v8);
      if ( g_pDataModel != nullptr )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return (CDmElement *)v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00506F00
// Name: public: virtual void CDmeDCCMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::GetOutputs(
        CDmeDCCMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString src; // [esp+314h] [ebp-10h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetMakefilePath(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.dmx", pOutputDir, pOutputName);
      CUtlString::CUtlString(this: &src, pString: pFullPath);
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: fullPaths, elem: fullPaths->m_Size, &src);
      src.m_Storage.m_nActualLength = 0;
      if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005073A0
// Name: public: virtual bool CDmeSourceDCCFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceDCCFile::IsA(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005073D0
// Name: public: virtual int CDmeSourceDCCFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceDCCFile::GetInheritanceDepth(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507470
// Name: public: virtual bool CDmeSourceMayaFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaFile::IsA(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005074B0
// Name: public: virtual int CDmeSourceMayaFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaFile::GetInheritanceDepth(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507560
// Name: public: virtual bool CDmeSourceMayaModelFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaModelFile::IsA(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005075A0
// Name: public: virtual int CDmeSourceMayaModelFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaModelFile::GetInheritanceDepth(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507610
// Name: protected: virtual void CDmeSourceMayaModelFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaModelFile::PerformConstruction(CDmeSourceMayaModelFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005076A0
// Name: public: virtual bool CDmeSourceMayaAnimationFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaAnimationFile::IsA(CDmeSourceMayaAnimationFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005076E0
// Name: public: virtual int CDmeSourceMayaAnimationFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaAnimationFile::GetInheritanceDepth(
        CDmeSourceMayaAnimationFile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507750
// Name: protected: virtual void CDmeSourceMayaAnimationFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaAnimationFile::PerformConstruction(CDmeSourceMayaAnimationFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 1;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005077E0
// Name: public: virtual bool CDmeSourceXSIFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceXSIFile::IsA(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507820
// Name: public: virtual int CDmeSourceXSIFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceXSIFile::GetInheritanceDepth(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507880
// Name: protected: virtual void CDmeSourceMayaAnimationFile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaAnimationFile::PerformDestruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00507890
// Name: protected: virtual void CDmeSourceDCCFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::PerformConstruction(CDmeSourceXSIFile *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00507900
// Name: private: virtual char const __near * CDmeDCCMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeDCCMakefile::GetOutputDirectoryID(CDmeDCCMakefile *this)
{
  return "makefiledir:..\\dmx";
}

//------------------------------------------------------------------------------
// Address: 0x00507910
// Name: public: virtual bool CDmeDCCMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDCCMakefile::IsA(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507940
// Name: public: virtual int CDmeDCCMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::GetInheritanceDepth(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507990
// Name: protected: virtual void CDmeMayaAnimationMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaAnimationMakefile::PerformConstruction(CDmeMayaAnimationMakefile *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeMakefile::OnConstruction(this);
  this->m_bFlushFile = false;
}

//------------------------------------------------------------------------------
// Address: 0x00507A00
// Name: public: virtual bool CDmeMayaMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaMakefile::IsA(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507A40
// Name: public: virtual int CDmeMayaMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaMakefile::GetInheritanceDepth(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507AF0
// Name: public: virtual bool CDmeXSIMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeXSIMakefile::IsA(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507B30
// Name: public: virtual int CDmeXSIMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeXSIMakefile::GetInheritanceDepth(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507BE0
// Name: public: virtual bool CDmeMayaModelMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaModelMakefile::IsA(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507C20
// Name: public: virtual int CDmeMayaModelMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaModelMakefile::GetInheritanceDepth(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507C90
// Name: protected: virtual void CDmeMayaModelMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaModelMakefile::PerformDestruction(CDmeMayaAnimationMakefile *this)
{
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00507CF0
// Name: public: virtual bool CDmeMayaAnimationMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaAnimationMakefile::IsA(CDmeMayaAnimationMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507D30
// Name: public: virtual int CDmeMayaAnimationMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaAnimationMakefile::GetInheritanceDepth(
        CDmeMayaAnimationMakefile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507DA0
// Name: protected: virtual int CDmeDCCMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::AllocatedSize(CDmeMayaAnimationMakefile *this)
{
  return 112;
}

//------------------------------------------------------------------------------
// Address: 0x0067D530
// Name: _dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceDCCFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceDCCFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D590
// Name: _dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D5F0
// Name: _dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaModelFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaModelFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D650
// Name: _dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaAnimationFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaAnimationFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D6B0
// Name: _dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceXSIFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceXSIFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D710
// Name: _dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDCCMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDCCMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D770
// Name: _dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D7D0
// Name: _dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaModelMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaModelMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D830
// Name: _dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaAnimationMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaAnimationMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D890
// Name: _dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeXSIMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeXSIMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682050
// Name: _dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceDCCFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682060
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682070
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaModelFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682080
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaAnimationFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682090
// Name: _dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceXSIFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006820A0
// Name: _dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDCCMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006820B0
// Name: _dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006820C0
// Name: _dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaModelMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006820D0
// Name: _dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaAnimationMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006820E0
// Name: _dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeXSIMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067D560
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D570
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceDCCFile_Helper,
           classname: "DmeSourceDCCFile",
           pFactory: &g_CDmeSourceDCCFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067D5C0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D5D0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaFile_Helper,
           classname: "DmeSourceMayaFile",
           pFactory: &g_CDmeSourceMayaFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067D620
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D630
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaModelFile_Helper,
           classname: "DmeSourceMayaModelFile",
           pFactory: &g_CDmeSourceMayaModelFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067D680
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D690
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaAnimationFile_Helper,
           classname: "DmeSourceMayaAnimationFile",
           pFactory: &g_CDmeSourceMayaAnimationFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067D6E0
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D6F0
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceXSIFile_Helper,
           classname: "DmeSourceXSIFile",
           pFactory: &g_CDmeSourceXSIFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067D740
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDCCMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D750
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDCCMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDCCMakefile_Helper,
           classname: "DmeDCCMakefile",
           pFactory: &g_CDmeDCCMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067D7A0
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D7B0
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaMakefile_Helper,
           classname: "DmeMayaMakefile",
           pFactory: &g_CDmeMayaMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067D800
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D810
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaModelMakefile_Helper,
           classname: "DmeMayaModelMakefile",
           pFactory: &g_CDmeMayaModelMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067D860
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D870
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaAnimationMakefile_Helper,
           classname: "DmeMayaAnimationMakefile",
           pFactory: &g_CDmeMayaAnimationMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067D8C0
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeXSIMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D8D0
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeXSIMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeXSIMakefile_Helper,
           classname: "DmeXSIMakefile",
           pFactory: &g_CDmeXSIMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006820F0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSourceMayaFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682100
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSourceMayaModelFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682110
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSourceMayaAnimationFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682120
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSourceXSIFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682130
// Name: _dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeDCCMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682140
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMayaMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682150
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMayaModelMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682160
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMayaAnimationMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682170
// Name: _dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeXSIMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682180
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSourceDCCFile_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104D7410
// Name: private: virtual void CDmeDCCMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::DestroyOutputElement(CDmeDCCMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushFile = true;
}

//------------------------------------------------------------------------------
// Address: 0x104D7420
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetSourceTypes(CDmeMayaModelMakefile *this)
{
  return s_pMayaModelSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x104D7430
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetSourceTypes(CDmeMayaAnimationMakefile *this)
{
  return s_pMayaAnimationSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x104D7440
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetMakefileType(CDmeMayaModelMakefile *this)
{
  return &s_MayaModelMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x104D7450
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetMakefileType(CDmeMayaAnimationMakefile *this)
{
  return &s_MayaAnimationMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x104D7460
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetSourceTypes(CDmeXSIMakefile *this)
{
  return s_pXSISourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x104D7470
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetMakefileType(CDmeXSIMakefile *this)
{
  return &s_XSIMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x104D7480
// Name: protected: void CDmeSourceDCCFile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::OnConstruction(CDmeSourceDCCFile *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_RootDCCObjects,
    pOwner: this,
    pAttributeName: "rootDCCObjects",
    nFlags: 0);
  value = 0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "exportType", type: AT_INT, pMemory: &this->m_ExportType);
  this->m_ExportType.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameStart",
         type: AT_FLOAT,
         pMemory: &this->m_FrameStart);
  this->m_FrameStart.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (float *)&value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "frameEnd", type: AT_FLOAT, pMemory: &this->m_FrameEnd);
  this->m_FrameEnd.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, (float *)&value);
  value = 1065353216;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameIncrement",
         type: AT_FLOAT,
         pMemory: &this->m_FrameIncrement);
  this->m_FrameIncrement.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, (float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x104D7550
// Name: private: virtual class CDmElement __near * CDmeDCCMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeDCCMakefile::CreateOutputElement(CDmeDCCMakefile *this)
{
  bool v2; // zf
  DmElementHandle_t BufferType; // esi
  CDmElement *v4; // eax
  DmFileId_t m_fileId; // esi
  IDataModel_vtbl *v6; // edi
  int v7; // eax
  CDmElement *v8; // eax
  int v9; // esi
  CUtlSymbolLarge *v11; // eax
  CDmElement *pRoot; // [esp+8h] [ebp-8h] BYREF
  CDmeHandle<CDmeDCCMakefile,0> hMakefileOld; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bFlushFile || (v2 = this->m_fileId == DMFILEID_INVALID, this->m_bFlushFile = false, v2) )
  {
    v11 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pRoot, a3: "makefile");
    return FindReferringElement<CDmElement>(
             pElement: (CExpressionCalculator *)this,
             symAttrName: (CUtlSymbolLarge)v11->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  else
  {
    hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
    BufferType = CCodecBuffer_Block::GetBufferType((CExpressionCalculator *)this);
    if ( BufferType != DMELEMENT_HANDLE_INVALID )
    {
      CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      hMakefileOld.m_handle = BufferType;
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: BufferType);
      if ( v4 != nullptr && !v4->IsA(this: v4, a2: CDmeDCCMakefile::m_classType) )
        hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
      CDmeElementRefHelper::Ref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
    }
    m_fileId = this->m_fileId;
    g_pDataModel->UnloadFile(this: g_pDataModel, a2: m_fileId);
    pRoot = nullptr;
    v6 = g_pDataModel->__vftable;
    v7 = ((int (__thiscall *)(IDataModel *, DmFileId_t, _DWORD, _DWORD, CDmElement **, int, _DWORD))g_pDataModel->GetFileName)(
           a1: g_pDataModel,
           a2: m_fileId,
           a3: 0,
           a4: 0,
           a5: &pRoot,
           a6: 1,
           a7: 0);
    if ( ((int (__thiscall *)(IDataModel *, int))v6->RestoreFromFile)(a1: g_pDataModel, a2: v7) == -1
      || g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle) == nullptr )
    {
      if ( g_pDataModel != nullptr )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return nullptr;
    }
    else
    {
      *((_BYTE *)&g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle)[1].m_ref + 8) = 0;
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle);
      v9 = ((int (__thiscall *)(CDmElement *))v8->__vftable[1].Resolve)(a1: v8);
      if ( g_pDataModel != nullptr )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return (CDmElement *)v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D76E0
// Name: public: virtual void CDmeDCCMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::GetOutputs(
        CDmeDCCMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString src; // [esp+314h] [ebp-10h] BYREF

  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetMakefilePath(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      V_snprintf(pDest: pFullPath, maxLen: 0x104u, pFormat: "%s\\%s.dmx", pOutputDir, pOutputName);
      CUtlString::CUtlString(this: &src, pString: pFullPath);
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: fullPaths, elem: fullPaths->m_Size, &src);
      src.m_Storage.m_nActualLength = 0;
      if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D7B80
// Name: public: virtual bool CDmeSourceDCCFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceDCCFile::IsA(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D7BB0
// Name: public: virtual int CDmeSourceDCCFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceDCCFile::GetInheritanceDepth(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D7C60
// Name: public: virtual bool CDmeSourceMayaFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaFile::IsA(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D7CA0
// Name: public: virtual int CDmeSourceMayaFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaFile::GetInheritanceDepth(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D7D00
// Name: protected: virtual void CDmeSourceDCCFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::PerformConstruction(CDmeSourceXSIFile *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x104D7D70
// Name: public: virtual bool CDmeSourceMayaModelFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaModelFile::IsA(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D7DB0
// Name: public: virtual int CDmeSourceMayaModelFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaModelFile::GetInheritanceDepth(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D7E20
// Name: protected: virtual void CDmeSourceMayaModelFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaModelFile::PerformConstruction(CDmeSourceMayaModelFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x104D7EB0
// Name: public: virtual bool CDmeSourceMayaAnimationFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaAnimationFile::IsA(CDmeSourceMayaAnimationFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D7EF0
// Name: public: virtual int CDmeSourceMayaAnimationFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaAnimationFile::GetInheritanceDepth(
        CDmeSourceMayaAnimationFile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D7F60
// Name: protected: virtual void CDmeSourceMayaAnimationFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaAnimationFile::PerformConstruction(CDmeSourceMayaAnimationFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 1;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x104D7FF0
// Name: public: virtual bool CDmeSourceXSIFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceXSIFile::IsA(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D8030
// Name: public: virtual int CDmeSourceXSIFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceXSIFile::GetInheritanceDepth(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D80E0
// Name: private: virtual char const __near * CDmeDCCMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeDCCMakefile::GetOutputDirectoryID(CDmeDCCMakefile *this)
{
  return "makefiledir:..\\dmx";
}

//------------------------------------------------------------------------------
// Address: 0x104D80F0
// Name: public: virtual bool CDmeDCCMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDCCMakefile::IsA(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D8120
// Name: public: virtual int CDmeDCCMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::GetInheritanceDepth(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D81C0
// Name: public: virtual bool CDmeMayaMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaMakefile::IsA(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D8200
// Name: public: virtual int CDmeMayaMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaMakefile::GetInheritanceDepth(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D82B0
// Name: public: virtual bool CDmeXSIMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeXSIMakefile::IsA(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D82F0
// Name: public: virtual int CDmeXSIMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeXSIMakefile::GetInheritanceDepth(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D83A0
// Name: public: virtual bool CDmeMayaModelMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaModelMakefile::IsA(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D83E0
// Name: public: virtual int CDmeMayaModelMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaModelMakefile::GetInheritanceDepth(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D8450
// Name: protected: virtual void CDmeMayaAnimationMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaAnimationMakefile::PerformConstruction(CDmeMayaAnimationMakefile *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeMakefile::OnConstruction(this);
  this->m_bFlushFile = false;
}

//------------------------------------------------------------------------------
// Address: 0x104D84C0
// Name: public: virtual bool CDmeMayaAnimationMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaAnimationMakefile::IsA(CDmeMayaAnimationMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D8500
// Name: public: virtual int CDmeMayaAnimationMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaAnimationMakefile::GetInheritanceDepth(
        CDmeMayaAnimationMakefile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104D8570
// Name: protected: virtual void CDmeMayaModelMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaModelMakefile::PerformDestruction(CDmeMakefile *this)
{
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
}

//------------------------------------------------------------------------------
// Address: 0x104EF8C0
// Name: protected: virtual int CDmeDCCMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::AllocatedSize(CDmeMayaAnimationMakefile *this)
{
  return 112;
}

//------------------------------------------------------------------------------
// Address: 0x105C6FF0
// Name: _dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceDCCFile::s_Allocator,
    blockSize: 0x80u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceDCCFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7050
// Name: _dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaFile::s_Allocator,
    blockSize: 0x80u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C70B0
// Name: _dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaModelFile::s_Allocator,
    blockSize: 0x80u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaModelFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7110
// Name: _dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaAnimationFile::s_Allocator,
    blockSize: 0x80u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaAnimationFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7170
// Name: _dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceXSIFile::s_Allocator,
    blockSize: 0x80u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceXSIFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C71D0
// Name: _dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDCCMakefile::s_Allocator,
    blockSize: 0x70u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDCCMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7230
// Name: _dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaMakefile::s_Allocator,
    blockSize: 0x70u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7290
// Name: _dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaModelMakefile::s_Allocator,
    blockSize: 0x70u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaModelMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C72F0
// Name: _dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaAnimationMakefile::s_Allocator,
    blockSize: 0x70u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaAnimationMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7350
// Name: _dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeXSIMakefile::s_Allocator,
    blockSize: 0x70u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeXSIMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CCD70
// Name: _dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceDCCFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCD80
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCD90
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaModelFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCDA0
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaAnimationFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCDB0
// Name: _dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceXSIFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCDC0
// Name: _dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDCCMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCDD0
// Name: _dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCDE0
// Name: _dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaModelMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCDF0
// Name: _dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaAnimationMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCE00
// Name: _dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeXSIMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C7020
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7030
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceDCCFile_Helper,
           classname: "DmeSourceDCCFile",
           pFactory: &g_CDmeSourceDCCFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C7080
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7090
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaFile_Helper,
           classname: "DmeSourceMayaFile",
           pFactory: &g_CDmeSourceMayaFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C70E0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C70F0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaModelFile_Helper,
           classname: "DmeSourceMayaModelFile",
           pFactory: &g_CDmeSourceMayaModelFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C7140
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7150
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaAnimationFile_Helper,
           classname: "DmeSourceMayaAnimationFile",
           pFactory: &g_CDmeSourceMayaAnimationFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C71A0
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C71B0
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceXSIFile_Helper,
           classname: "DmeSourceXSIFile",
           pFactory: &g_CDmeSourceXSIFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C7200
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDCCMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7210
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDCCMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDCCMakefile_Helper,
           classname: "DmeDCCMakefile",
           pFactory: &g_CDmeDCCMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C7260
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7270
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaMakefile_Helper,
           classname: "DmeMayaMakefile",
           pFactory: &g_CDmeMayaMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C72C0
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C72D0
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaModelMakefile_Helper,
           classname: "DmeMayaModelMakefile",
           pFactory: &g_CDmeMayaModelMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C7320
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7330
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaAnimationMakefile_Helper,
           classname: "DmeMayaAnimationMakefile",
           pFactory: &g_CDmeMayaAnimationMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C7380
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeXSIMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7390
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeXSIMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeXSIMakefile_Helper,
           classname: "DmeXSIMakefile",
           pFactory: &g_CDmeXSIMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CCE10
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeSourceMayaFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCE20
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeSourceMayaModelFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCE30
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeSourceMayaAnimationFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCE40
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeSourceXSIFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCE50
// Name: _dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeDCCMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCE60
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeMayaMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCE70
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeMayaModelMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCE80
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeMayaAnimationMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCE90
// Name: _dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeXSIMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCEA0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeSourceDCCFile_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004B9300
// Name: private: virtual void CDmeDCCMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::DestroyOutputElement(CDmeDCCMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushFile = true;
}

//------------------------------------------------------------------------------
// Address: 0x004B9310
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetSourceTypes(CDmeMayaModelMakefile *this)
{
  return s_pMayaModelSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x004B9320
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetSourceTypes(CDmeMayaAnimationMakefile *this)
{
  return s_pMayaAnimationSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x004B9330
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetMakefileType(CDmeMayaModelMakefile *this)
{
  return &s_MayaModelMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x004B9340
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetMakefileType(CDmeMayaAnimationMakefile *this)
{
  return &s_MayaAnimationMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x004B9350
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetSourceTypes(CDmeXSIMakefile *this)
{
  return s_pXSISourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x004B9360
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetMakefileType(CDmeXSIMakefile *this)
{
  return &s_XSIMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x004B9370
// Name: protected: void CDmeSourceDCCFile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::OnConstruction(CDmeSourceDCCFile *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_RootDCCObjects,
    pOwner: this,
    pAttributeName: "rootDCCObjects",
    nFlags: 0);
  value = 0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "exportType", type: AT_INT, pMemory: &this->m_ExportType);
  this->m_ExportType.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameStart",
         type: AT_FLOAT,
         pMemory: &this->m_FrameStart);
  this->m_FrameStart.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (float *)&value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "frameEnd", type: AT_FLOAT, pMemory: &this->m_FrameEnd);
  this->m_FrameEnd.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, (float *)&value);
  value = 1065353216;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameIncrement",
         type: AT_FLOAT,
         pMemory: &this->m_FrameIncrement);
  this->m_FrameIncrement.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, (float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x004B9440
// Name: private: virtual class CDmElement __near * CDmeDCCMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeDCCMakefile::CreateOutputElement(CDmeDCCMakefile *this)
{
  bool v2; // zf
  DmElementHandle_t Handle; // esi
  int v4; // eax
  DmFileId_t m_fileId; // esi
  int v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // esi
  CUtlSymbolLarge *v11; // eax
  CDmElement *pRoot; // [esp+8h] [ebp-8h] BYREF
  CDmeHandle<CDmeDCCMakefile,0> hMakefileOld; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bFlushFile || (v2 = this->m_fileId == DMFILEID_INVALID, this->m_bFlushFile = false, v2) )
  {
    v11 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElement **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                               a1: g_pDataModel.u,
                               a2: &pRoot,
                               a3: "makefile");
    return FindReferringElement<CDmElement>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v11->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  else
  {
    hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
    Handle = CDmElement::GetHandle(this);
    if ( Handle != DMELEMENT_HANDLE_INVALID )
    {
      CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      hMakefileOld.m_handle = Handle;
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: Handle);
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeDCCMakefile::m_classType.u) == 0 )
      {
        hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
      }
      CDmeElementRefHelper::Ref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
    }
    m_fileId = this->m_fileId;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id + 408))(
      a1: g_pDataModel.u,
      a2: m_fileId);
    pRoot = nullptr;
    v6 = *(_DWORD *)g_pDataModel.u.m_Id;
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t, _DWORD, _DWORD, CDmElement **, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 364))(
           a1: g_pDataModel.u,
           a2: m_fileId,
           a3: 0,
           a4: 0,
           a5: &pRoot,
           a6: 1,
           a7: 0);
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v6 + 188))(a1: g_pDataModel.u, a2: v7) == -1
      || (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: hMakefileOld.m_handle) == 0 )
    {
      if ( g_pDataModel.u.m_Id != 0 )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return nullptr;
    }
    else
    {
      *(_BYTE *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
                   a1: g_pDataModel.u,
                   a2: hMakefileOld.m_handle)
               + 104) = 0;
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: hMakefileOld.m_handle);
      v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 68))(a1: v8);
      if ( g_pDataModel.u.m_Id != 0 )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return (CDmElement *)v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B95D0
// Name: public: virtual void CDmeDCCMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::GetOutputs(
        CDmeDCCMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString src; // [esp+314h] [ebp-10h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetMakefilePath(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.dmx", pOutputDir, pOutputName);
      CUtlString::CUtlString(this: &src, pString: pFullPath);
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: fullPaths, elem: fullPaths->m_Size, &src);
      src.m_Storage.m_nActualLength = 0;
      if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9A70
// Name: public: virtual bool CDmeSourceDCCFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceDCCFile::IsA(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9AA0
// Name: public: virtual int CDmeSourceDCCFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceDCCFile::GetInheritanceDepth(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9B40
// Name: public: virtual bool CDmeSourceMayaFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaFile::IsA(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9B80
// Name: public: virtual int CDmeSourceMayaFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaFile::GetInheritanceDepth(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9C30
// Name: public: virtual bool CDmeSourceMayaModelFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaModelFile::IsA(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9C70
// Name: public: virtual int CDmeSourceMayaModelFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaModelFile::GetInheritanceDepth(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9CE0
// Name: protected: virtual int CDmeSourceMayaAnimationFile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaAnimationFile::AllocatedSize(CDmeSourceXSIFile *this)
{
  return 128;
}

//------------------------------------------------------------------------------
// Address: 0x004B9CF0
// Name: protected: virtual void CDmeSourceMayaModelFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaModelFile::PerformConstruction(CDmeSourceMayaModelFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004B9D80
// Name: public: virtual bool CDmeSourceMayaAnimationFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaAnimationFile::IsA(CDmeSourceMayaAnimationFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9DC0
// Name: public: virtual int CDmeSourceMayaAnimationFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaAnimationFile::GetInheritanceDepth(
        CDmeSourceMayaAnimationFile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9E30
// Name: protected: virtual void CDmeSourceMayaAnimationFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaAnimationFile::PerformConstruction(CDmeSourceMayaAnimationFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 1;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004B9EC0
// Name: public: virtual bool CDmeSourceXSIFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceXSIFile::IsA(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9F00
// Name: public: virtual int CDmeSourceXSIFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceXSIFile::GetInheritanceDepth(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9F60
// Name: protected: virtual void CDmeSourceDCCFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::PerformConstruction(CDmeSourceXSIFile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004B9FD0
// Name: private: virtual char const __near * CDmeDCCMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeDCCMakefile::GetOutputDirectoryID(CDmeDCCMakefile *this)
{
  return "makefiledir:..\\dmx";
}

//------------------------------------------------------------------------------
// Address: 0x004B9FE0
// Name: public: virtual bool CDmeDCCMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDCCMakefile::IsA(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BA010
// Name: public: virtual int CDmeDCCMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::GetInheritanceDepth(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BA060
// Name: protected: virtual int CDmeDCCMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::AllocatedSize(CDmeMayaAnimationMakefile *this)
{
  return 112;
}

//------------------------------------------------------------------------------
// Address: 0x004BA0C0
// Name: public: virtual bool CDmeMayaMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaMakefile::IsA(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BA100
// Name: public: virtual int CDmeMayaMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaMakefile::GetInheritanceDepth(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BA1B0
// Name: public: virtual bool CDmeXSIMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeXSIMakefile::IsA(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BA1F0
// Name: public: virtual int CDmeXSIMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeXSIMakefile::GetInheritanceDepth(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BA250
// Name: protected: virtual void CDmeMayaModelMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaModelMakefile::PerformDestruction(CDmeMayaAnimationMakefile *this)
{
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004BA2B0
// Name: public: virtual bool CDmeMayaModelMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaModelMakefile::IsA(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BA2F0
// Name: public: virtual int CDmeMayaModelMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaModelMakefile::GetInheritanceDepth(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BA3B0
// Name: public: virtual bool CDmeMayaAnimationMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaAnimationMakefile::IsA(CDmeMayaAnimationMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BA3F0
// Name: public: virtual int CDmeMayaAnimationMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaAnimationMakefile::GetInheritanceDepth(
        CDmeMayaAnimationMakefile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BA460
// Name: protected: virtual void CDmeMayaAnimationMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaAnimationMakefile::PerformConstruction(CDmeMayaAnimationMakefile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMakefile::OnConstruction(this);
  this->m_bFlushFile = false;
}

//------------------------------------------------------------------------------
// Address: 0x0059AF50
// Name: _dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceDCCFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceDCCFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AFB0
// Name: _dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B020
// Name: _dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaModelFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaModelFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B080
// Name: _dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaAnimationFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaAnimationFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B0E0
// Name: _dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceXSIFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceXSIFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B140
// Name: _dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDCCMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDCCMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B1A0
// Name: _dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B200
// Name: _dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaModelMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaModelMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B260
// Name: _dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaAnimationMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaAnimationMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B2C0
// Name: _dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeXSIMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeXSIMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059ED30
// Name: _dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceDCCFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059ED40
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059ED50
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaModelFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059ED60
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaAnimationFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059ED70
// Name: _dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceXSIFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059ED80
// Name: _dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDCCMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059ED90
// Name: _dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059EDA0
// Name: _dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaModelMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059EDB0
// Name: _dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaAnimationMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059EDC0
// Name: _dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeXSIMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059AF80
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AF90
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceDCCFile_Helper,
           classname: "DmeSourceDCCFile",
           pFactory: &g_CDmeSourceDCCFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059AFE0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B000
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaFile_Helper,
           classname: "DmeSourceMayaFile",
           pFactory: &g_CDmeSourceMayaFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059B050
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B060
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaModelFile_Helper,
           classname: "DmeSourceMayaModelFile",
           pFactory: &g_CDmeSourceMayaModelFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059B0B0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B0C0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaAnimationFile_Helper,
           classname: "DmeSourceMayaAnimationFile",
           pFactory: &g_CDmeSourceMayaAnimationFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059B110
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B120
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceXSIFile_Helper,
           classname: "DmeSourceXSIFile",
           pFactory: &g_CDmeSourceXSIFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059B170
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDCCMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B180
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDCCMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDCCMakefile_Helper,
           classname: "DmeDCCMakefile",
           pFactory: &g_CDmeDCCMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059B1D0
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B1E0
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaMakefile_Helper,
           classname: "DmeMayaMakefile",
           pFactory: &g_CDmeMayaMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059B230
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B240
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaModelMakefile_Helper,
           classname: "DmeMayaModelMakefile",
           pFactory: &g_CDmeMayaModelMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059B290
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B2A0
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaAnimationMakefile_Helper,
           classname: "DmeMayaAnimationMakefile",
           pFactory: &g_CDmeMayaAnimationMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059B2F0
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeXSIMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B300
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeXSIMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeXSIMakefile_Helper,
           classname: "DmeXSIMakefile",
           pFactory: &g_CDmeXSIMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059EDD0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059EDE0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaModelFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059EDF0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaAnimationFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059EE00
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceXSIFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059EE10
// Name: _dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDCCMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059EE20
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059EE30
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaModelMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059EE40
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaAnimationMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059EE50
// Name: _dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeXSIMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059EE60
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceDCCFile_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x0050D8E0
// Name: private: virtual void CDmeDCCMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::DestroyOutputElement(CDmeDCCMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushFile = true;
}

//------------------------------------------------------------------------------
// Address: 0x0050D8F0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetSourceTypes(CDmeMayaModelMakefile *this)
{
  return s_pMayaModelSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x0050D900
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetSourceTypes(CDmeMayaAnimationMakefile *this)
{
  return s_pMayaAnimationSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x0050D910
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetMakefileType(CDmeMayaModelMakefile *this)
{
  return &s_MayaModelMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x0050D920
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetMakefileType(CDmeMayaAnimationMakefile *this)
{
  return &s_MayaAnimationMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x0050D930
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetSourceTypes(CDmeXSIMakefile *this)
{
  return s_pXSISourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x0050D940
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetMakefileType(CDmeXSIMakefile *this)
{
  return &s_XSIMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x0050D950
// Name: protected: void CDmeSourceDCCFile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::OnConstruction(CDmeSourceDCCFile *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_RootDCCObjects,
    pOwner: this,
    pAttributeName: "rootDCCObjects",
    nFlags: 0);
  value = 0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "exportType", type: AT_INT, pMemory: &this->m_ExportType);
  this->m_ExportType.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameStart",
         type: AT_FLOAT,
         pMemory: &this->m_FrameStart);
  this->m_FrameStart.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (float *)&value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "frameEnd", type: AT_FLOAT, pMemory: &this->m_FrameEnd);
  this->m_FrameEnd.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, (float *)&value);
  value = 1065353216;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameIncrement",
         type: AT_FLOAT,
         pMemory: &this->m_FrameIncrement);
  this->m_FrameIncrement.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, (float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x0050DA20
// Name: private: virtual class CDmElement __near * CDmeDCCMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeDCCMakefile::CreateOutputElement(CDmeDCCMakefile *this)
{
  bool v2; // zf
  DmElementHandle_t v3; // esi
  int v4; // eax
  DmFileId_t m_fileId; // esi
  int v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // esi
  CUtlSymbolLarge *v11; // eax
  CDmElement *pRoot; // [esp+8h] [ebp-8h] BYREF
  CDmeHandle<CDmeDCCMakefile,0> hMakefileOld; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bFlushFile || (v2 = this->m_fileId == DMFILEID_INVALID, this->m_bFlushFile = false, v2) )
  {
    v11 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElement **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                               a1: g_pDataModel.u,
                               a2: &pRoot,
                               a3: "makefile");
    return FindReferringElement<CDmElement>(
             pElement: (CExpressionCalculator *)this,
             symAttrName: (CUtlSymbolLarge)v11->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  else
  {
    hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
    v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
    if ( v3 != DMELEMENT_HANDLE_INVALID )
    {
      CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      hMakefileOld.m_handle = v3;
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: v3);
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeDCCMakefile::m_classType.u) == 0 )
      {
        hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
      }
      CDmeElementRefHelper::Ref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
    }
    m_fileId = this->m_fileId;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id + 408))(
      a1: g_pDataModel.u,
      a2: m_fileId);
    pRoot = nullptr;
    v6 = *(_DWORD *)g_pDataModel.u.m_Id;
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t, _DWORD, _DWORD, CDmElement **, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 364))(
           a1: g_pDataModel.u,
           a2: m_fileId,
           a3: 0,
           a4: 0,
           a5: &pRoot,
           a6: 1,
           a7: 0);
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v6 + 188))(a1: g_pDataModel.u, a2: v7) == -1
      || (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: hMakefileOld.m_handle) == 0 )
    {
      if ( g_pDataModel.u.m_Id != 0 )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return nullptr;
    }
    else
    {
      *(_BYTE *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
                   a1: g_pDataModel.u,
                   a2: hMakefileOld.m_handle)
               + 104) = 0;
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: hMakefileOld.m_handle);
      v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 68))(a1: v8);
      if ( g_pDataModel.u.m_Id != 0 )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return (CDmElement *)v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050DBB0
// Name: public: virtual void CDmeDCCMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::GetOutputs(
        CDmeDCCMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString src; // [esp+314h] [ebp-10h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetMakefilePath(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.dmx", pOutputDir, pOutputName);
      CUtlString::CUtlString(this: &src, pString: pFullPath);
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: fullPaths, elem: fullPaths->m_Size, &src);
      src.m_Storage.m_nActualLength = 0;
      if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050E050
// Name: public: virtual bool CDmeSourceDCCFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceDCCFile::IsA(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E080
// Name: public: virtual int CDmeSourceDCCFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceDCCFile::GetInheritanceDepth(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E120
// Name: public: virtual bool CDmeSourceMayaFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaFile::IsA(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E160
// Name: public: virtual int CDmeSourceMayaFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaFile::GetInheritanceDepth(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E1C0
// Name: protected: virtual void CDmeSourceDCCFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::PerformConstruction(CDmeSourceXSIFile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0050E230
// Name: public: virtual bool CDmeSourceMayaModelFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaModelFile::IsA(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E270
// Name: public: virtual int CDmeSourceMayaModelFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaModelFile::GetInheritanceDepth(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E2E0
// Name: protected: virtual int CDmeSourceMayaAnimationFile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaAnimationFile::AllocatedSize(CDmeSourceXSIFile *this)
{
  return 128;
}

//------------------------------------------------------------------------------
// Address: 0x0050E2F0
// Name: protected: virtual void CDmeSourceMayaModelFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaModelFile::PerformConstruction(CDmeSourceMayaModelFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0050E380
// Name: public: virtual bool CDmeSourceMayaAnimationFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaAnimationFile::IsA(CDmeSourceMayaAnimationFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E3C0
// Name: public: virtual int CDmeSourceMayaAnimationFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaAnimationFile::GetInheritanceDepth(
        CDmeSourceMayaAnimationFile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E430
// Name: protected: virtual void CDmeSourceMayaAnimationFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaAnimationFile::PerformConstruction(CDmeSourceMayaAnimationFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 1;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0050E4C0
// Name: public: virtual bool CDmeSourceXSIFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceXSIFile::IsA(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E500
// Name: public: virtual int CDmeSourceXSIFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceXSIFile::GetInheritanceDepth(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E5B0
// Name: private: virtual char const __near * CDmeDCCMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeDCCMakefile::GetOutputDirectoryID(CDmeDCCMakefile *this)
{
  return "makefiledir:..\\dmx";
}

//------------------------------------------------------------------------------
// Address: 0x0050E5C0
// Name: public: virtual bool CDmeDCCMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDCCMakefile::IsA(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E5F0
// Name: public: virtual int CDmeDCCMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::GetInheritanceDepth(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E640
// Name: protected: virtual void CDmeMayaAnimationMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaAnimationMakefile::PerformConstruction(CDmeMayaAnimationMakefile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMakefile::OnConstruction(this);
  this->m_bFlushFile = false;
}

//------------------------------------------------------------------------------
// Address: 0x0050E6B0
// Name: public: virtual bool CDmeMayaMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaMakefile::IsA(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E6F0
// Name: public: virtual int CDmeMayaMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaMakefile::GetInheritanceDepth(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E750
// Name: protected: virtual int CDmeDCCMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::AllocatedSize(CDmeMayaAnimationMakefile *this)
{
  return 112;
}

//------------------------------------------------------------------------------
// Address: 0x0050E7B0
// Name: public: virtual bool CDmeXSIMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeXSIMakefile::IsA(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E7F0
// Name: public: virtual int CDmeXSIMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeXSIMakefile::GetInheritanceDepth(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E850
// Name: protected: virtual void CDmeMayaModelMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaModelMakefile::PerformDestruction(CDmeMayaAnimationMakefile *this)
{
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0050E8B0
// Name: public: virtual bool CDmeMayaModelMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaModelMakefile::IsA(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E8F0
// Name: public: virtual int CDmeMayaModelMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaModelMakefile::GetInheritanceDepth(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E9B0
// Name: public: virtual bool CDmeMayaAnimationMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaAnimationMakefile::IsA(CDmeMayaAnimationMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E9F0
// Name: public: virtual int CDmeMayaAnimationMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaAnimationMakefile::GetInheritanceDepth(
        CDmeMayaAnimationMakefile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F0510
// Name: _dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceDCCFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceDCCFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0570
// Name: _dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F05D0
// Name: _dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaModelFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaModelFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0630
// Name: _dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaAnimationFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaAnimationFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0690
// Name: _dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceXSIFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceXSIFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F06F0
// Name: _dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDCCMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDCCMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0750
// Name: _dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F07B0
// Name: _dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaModelMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaModelMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0810
// Name: _dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaAnimationMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaAnimationMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0870
// Name: _dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeXSIMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeXSIMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4300
// Name: _dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceDCCFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4310
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4320
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaModelFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4330
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaAnimationFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4340
// Name: _dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceXSIFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4350
// Name: _dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDCCMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4360
// Name: _dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4370
// Name: _dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaModelMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4380
// Name: _dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaAnimationMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4390
// Name: _dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeXSIMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F0540
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0550
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceDCCFile_Helper,
           classname: "DmeSourceDCCFile",
           pFactory: &g_CDmeSourceDCCFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F05A0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F05B0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaFile_Helper,
           classname: "DmeSourceMayaFile",
           pFactory: &g_CDmeSourceMayaFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F0600
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0610
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaModelFile_Helper,
           classname: "DmeSourceMayaModelFile",
           pFactory: &g_CDmeSourceMayaModelFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F0660
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0670
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaAnimationFile_Helper,
           classname: "DmeSourceMayaAnimationFile",
           pFactory: &g_CDmeSourceMayaAnimationFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F06C0
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F06D0
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceXSIFile_Helper,
           classname: "DmeSourceXSIFile",
           pFactory: &g_CDmeSourceXSIFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F0720
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDCCMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0730
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDCCMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDCCMakefile_Helper,
           classname: "DmeDCCMakefile",
           pFactory: &g_CDmeDCCMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F0780
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0790
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaMakefile_Helper,
           classname: "DmeMayaMakefile",
           pFactory: &g_CDmeMayaMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F07E0
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F07F0
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaModelMakefile_Helper,
           classname: "DmeMayaModelMakefile",
           pFactory: &g_CDmeMayaModelMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F0840
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0850
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaAnimationMakefile_Helper,
           classname: "DmeMayaAnimationMakefile",
           pFactory: &g_CDmeMayaAnimationMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F08A0
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeXSIMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F08B0
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeXSIMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeXSIMakefile_Helper,
           classname: "DmeXSIMakefile",
           pFactory: &g_CDmeXSIMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F43A0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F43B0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaModelFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F43C0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaAnimationFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F43D0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceXSIFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F43E0
// Name: _dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDCCMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F43F0
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4400
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaModelMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4410
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaAnimationMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4420
// Name: _dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeXSIMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4430
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceDCCFile_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00471A70
// Name: protected: virtual void CDmeSourceMayaAnimationFile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaAnimationFile::PerformDestruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00471F70
// Name: private: virtual void CDmeDCCMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::DestroyOutputElement(CDmeDCCMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushFile = true;
}

//------------------------------------------------------------------------------
// Address: 0x00471F80
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetSourceTypes(CDmeMayaModelMakefile *this)
{
  return s_pMayaModelSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00471F90
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetSourceTypes(CDmeMayaAnimationMakefile *this)
{
  return s_pMayaAnimationSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00471FA0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetMakefileType(CDmeMayaModelMakefile *this)
{
  return &s_MayaModelMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00471FB0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetMakefileType(CDmeMayaAnimationMakefile *this)
{
  return &s_MayaAnimationMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00471FC0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetSourceTypes(CDmeXSIMakefile *this)
{
  return s_pXSISourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00471FD0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetMakefileType(CDmeXSIMakefile *this)
{
  return &s_XSIMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00471FF0
// Name: protected: void CDmeSourceDCCFile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::OnConstruction(CDmeSourceDCCFile *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_RootDCCObjects,
    pOwner: this,
    pAttributeName: "rootDCCObjects",
    nFlags: 0);
  value = 0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "exportType", type: AT_INT, pMemory: &this->m_ExportType);
  this->m_ExportType.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameStart",
         type: AT_FLOAT,
         pMemory: &this->m_FrameStart);
  this->m_FrameStart.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (float *)&value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "frameEnd", type: AT_FLOAT, pMemory: &this->m_FrameEnd);
  this->m_FrameEnd.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, (float *)&value);
  value = 1065353216;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameIncrement",
         type: AT_FLOAT,
         pMemory: &this->m_FrameIncrement);
  this->m_FrameIncrement.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, (float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x004720C0
// Name: private: virtual class CDmElement __near * CDmeDCCMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeDCCMakefile::CreateOutputElement(CDmeDCCMakefile *this)
{
  bool v2; // zf
  DmElementHandle_t v3; // esi
  CDmElement *v4; // eax
  DmFileId_t m_fileId; // esi
  IDataModel_vtbl *v6; // edi
  int v7; // eax
  CDmElement *v8; // eax
  int v9; // esi
  CUtlSymbolLarge *v11; // eax
  CDmElement *pRoot; // [esp+8h] [ebp-8h] BYREF
  CDmeHandle<CDmeDCCMakefile,0> hMakefileOld; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bFlushFile || (v2 = this->m_fileId == DMFILEID_INVALID, this->m_bFlushFile = false, v2) )
  {
    v11 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pRoot, a3: "makefile");
    return FindReferringElement<CDmElement>(
             pElement: (CExpressionCalculator *)this,
             symAttrName: (CUtlSymbolLarge)v11->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  else
  {
    hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
    v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
    if ( v3 != DMELEMENT_HANDLE_INVALID )
    {
      CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      hMakefileOld.m_handle = v3;
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
      if ( v4 != nullptr && !v4->IsA(this: v4, a2: CDmeDCCMakefile::m_classType) )
        hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
      CDmeElementRefHelper::Ref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
    }
    m_fileId = this->m_fileId;
    g_pDataModel->UnloadFile(this: g_pDataModel, a2: m_fileId);
    pRoot = nullptr;
    v6 = g_pDataModel->__vftable;
    v7 = ((int (__thiscall *)(IDataModel *, DmFileId_t, _DWORD, _DWORD, CDmElement **, int, _DWORD))g_pDataModel->GetFileName)(
           a1: g_pDataModel,
           a2: m_fileId,
           a3: 0,
           a4: 0,
           a5: &pRoot,
           a6: 1,
           a7: 0);
    if ( ((int (__thiscall *)(IDataModel *, int))v6->RestoreFromFile)(a1: g_pDataModel, a2: v7) == -1
      || g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle) == nullptr )
    {
      if ( g_pDataModel != nullptr )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return nullptr;
    }
    else
    {
      *((_BYTE *)&g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle)[1].m_ref + 8) = 0;
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle);
      v9 = ((int (__thiscall *)(CDmElement *))v8->__vftable[1].Resolve)(a1: v8);
      if ( g_pDataModel != nullptr )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return (CDmElement *)v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472250
// Name: public: virtual void CDmeDCCMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::GetOutputs(
        CDmeDCCMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString src; // [esp+314h] [ebp-10h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetMakefilePath(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.dmx", pOutputDir, pOutputName);
      CUtlString::CUtlString(this: &src, pString: pFullPath);
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: fullPaths, elem: fullPaths->m_Size, &src);
      src.m_Storage.m_nActualLength = 0;
      if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472720
// Name: public: virtual bool CDmeSourceDCCFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceDCCFile::IsA(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00472750
// Name: public: virtual int CDmeSourceDCCFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceDCCFile::GetInheritanceDepth(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00472800
// Name: public: virtual bool CDmeSourceMayaFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaFile::IsA(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00472840
// Name: public: virtual int CDmeSourceMayaFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaFile::GetInheritanceDepth(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004728F0
// Name: public: virtual bool CDmeSourceMayaModelFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaModelFile::IsA(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00472930
// Name: public: virtual int CDmeSourceMayaModelFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaModelFile::GetInheritanceDepth(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004729A0
// Name: protected: virtual void CDmeSourceMayaModelFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaModelFile::PerformConstruction(CDmeSourceMayaModelFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00472A30
// Name: public: virtual bool CDmeSourceMayaAnimationFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaAnimationFile::IsA(CDmeSourceMayaAnimationFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00472A70
// Name: public: virtual int CDmeSourceMayaAnimationFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaAnimationFile::GetInheritanceDepth(
        CDmeSourceMayaAnimationFile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00472AE0
// Name: protected: virtual void CDmeSourceMayaAnimationFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaAnimationFile::PerformConstruction(CDmeSourceMayaAnimationFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 1;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00472B70
// Name: public: virtual bool CDmeSourceXSIFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceXSIFile::IsA(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00472BB0
// Name: public: virtual int CDmeSourceXSIFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceXSIFile::GetInheritanceDepth(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00472C10
// Name: protected: virtual void CDmeSourceDCCFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::PerformConstruction(CDmeSourceXSIFile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00472C80
// Name: private: virtual char const __near * CDmeDCCMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeDCCMakefile::GetOutputDirectoryID(CDmeDCCMakefile *this)
{
  return "makefiledir:..\\dmx";
}

//------------------------------------------------------------------------------
// Address: 0x00472C90
// Name: public: virtual bool CDmeDCCMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDCCMakefile::IsA(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00472CC0
// Name: public: virtual int CDmeDCCMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::GetInheritanceDepth(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00472D60
// Name: public: virtual bool CDmeMayaMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaMakefile::IsA(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00472DA0
// Name: public: virtual int CDmeMayaMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaMakefile::GetInheritanceDepth(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00472E00
// Name: protected: virtual int CDmeDCCMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::AllocatedSize(CDmeMayaAnimationMakefile *this)
{
  return 112;
}

//------------------------------------------------------------------------------
// Address: 0x00472E60
// Name: public: virtual bool CDmeXSIMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeXSIMakefile::IsA(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00472EA0
// Name: public: virtual int CDmeXSIMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeXSIMakefile::GetInheritanceDepth(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00472F00
// Name: protected: virtual void CDmeMayaModelMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaModelMakefile::PerformDestruction(CDmeMayaAnimationMakefile *this)
{
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00472F60
// Name: public: virtual bool CDmeMayaModelMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaModelMakefile::IsA(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00472FA0
// Name: public: virtual int CDmeMayaModelMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaModelMakefile::GetInheritanceDepth(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00473060
// Name: public: virtual bool CDmeMayaAnimationMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaAnimationMakefile::IsA(CDmeMayaAnimationMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004730A0
// Name: public: virtual int CDmeMayaAnimationMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaAnimationMakefile::GetInheritanceDepth(
        CDmeMayaAnimationMakefile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00473110
// Name: protected: virtual void CDmeMayaAnimationMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaAnimationMakefile::PerformConstruction(CDmeMayaAnimationMakefile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMakefile::OnConstruction(this);
  this->m_bFlushFile = false;
}

//------------------------------------------------------------------------------
// Address: 0x0056A110
// Name: _dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceDCCFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceDCCFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A170
// Name: _dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A1D0
// Name: _dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaModelFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaModelFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A230
// Name: _dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaAnimationFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaAnimationFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A290
// Name: _dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceXSIFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceXSIFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A2F0
// Name: _dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDCCMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDCCMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A350
// Name: _dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A3B0
// Name: _dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaModelMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaModelMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A410
// Name: _dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaAnimationMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaAnimationMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A470
// Name: _dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeXSIMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeXSIMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056E230
// Name: _dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceDCCFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056E240
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056E250
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaModelFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056E260
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaAnimationFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056E270
// Name: _dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceXSIFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056E280
// Name: _dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDCCMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056E290
// Name: _dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056E2A0
// Name: _dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaModelMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056E2B0
// Name: _dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaAnimationMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056E2C0
// Name: _dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeXSIMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056A140
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A150
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceDCCFile_Helper,
           classname: "DmeSourceDCCFile",
           pFactory: &g_CDmeSourceDCCFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056A1A0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A1B0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaFile_Helper,
           classname: "DmeSourceMayaFile",
           pFactory: &g_CDmeSourceMayaFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056A200
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A210
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaModelFile_Helper,
           classname: "DmeSourceMayaModelFile",
           pFactory: &g_CDmeSourceMayaModelFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056A260
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A270
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaAnimationFile_Helper,
           classname: "DmeSourceMayaAnimationFile",
           pFactory: &g_CDmeSourceMayaAnimationFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056A2C0
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A2D0
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceXSIFile_Helper,
           classname: "DmeSourceXSIFile",
           pFactory: &g_CDmeSourceXSIFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056A320
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDCCMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A330
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDCCMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDCCMakefile_Helper,
           classname: "DmeDCCMakefile",
           pFactory: &g_CDmeDCCMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056A380
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A390
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaMakefile_Helper,
           classname: "DmeMayaMakefile",
           pFactory: &g_CDmeMayaMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056A3E0
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A3F0
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaModelMakefile_Helper,
           classname: "DmeMayaModelMakefile",
           pFactory: &g_CDmeMayaModelMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056A440
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A450
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaAnimationMakefile_Helper,
           classname: "DmeMayaAnimationMakefile",
           pFactory: &g_CDmeMayaAnimationMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056A4A0
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeXSIMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056A4B0
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeXSIMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeXSIMakefile_Helper,
           classname: "DmeXSIMakefile",
           pFactory: &g_CDmeXSIMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056E2D0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056E2E0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaModelFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056E2F0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaAnimationFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056E300
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceXSIFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056E310
// Name: _dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDCCMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056E320
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056E330
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaModelMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056E340
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaAnimationMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056E350
// Name: _dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeXSIMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056E360
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceDCCFile_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00475950
// Name: protected: virtual void CDmeSourceMayaAnimationFile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaAnimationFile::PerformDestruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00475CB0
// Name: private: virtual void CDmeDCCMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::DestroyOutputElement(CDmeDCCMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushFile = true;
}

//------------------------------------------------------------------------------
// Address: 0x00475CC0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetSourceTypes(CDmeMayaModelMakefile *this)
{
  return s_pMayaModelSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00475CD0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetSourceTypes(CDmeMayaAnimationMakefile *this)
{
  return s_pMayaAnimationSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00475CE0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetMakefileType(CDmeMayaModelMakefile *this)
{
  return &s_MayaModelMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00475CF0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetMakefileType(CDmeMayaAnimationMakefile *this)
{
  return &s_MayaAnimationMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00475D00
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetSourceTypes(CDmeXSIMakefile *this)
{
  return s_pXSISourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00475D10
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetMakefileType(CDmeXSIMakefile *this)
{
  return &s_XSIMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00475D20
// Name: protected: void CDmeSourceDCCFile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::OnConstruction(CDmeSourceDCCFile *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_RootDCCObjects,
    pOwner: this,
    pAttributeName: "rootDCCObjects",
    nFlags: 0);
  value = 0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "exportType", type: AT_INT, pMemory: &this->m_ExportType);
  this->m_ExportType.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameStart",
         type: AT_FLOAT,
         pMemory: &this->m_FrameStart);
  this->m_FrameStart.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (const float *)&value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "frameEnd", type: AT_FLOAT, pMemory: &this->m_FrameEnd);
  this->m_FrameEnd.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, (const float *)&value);
  value = 1065353216;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameIncrement",
         type: AT_FLOAT,
         pMemory: &this->m_FrameIncrement);
  this->m_FrameIncrement.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, (const float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x00475DF0
// Name: private: virtual class CDmElement __near * CDmeDCCMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeDCCMakefile::CreateOutputElement(CDmeDCCMakefile *this)
{
  bool v2; // zf
  DmElementHandle_t v3; // esi
  CDmElement *v4; // eax
  DmFileId_t m_fileId; // esi
  IDataModel_vtbl *v6; // edi
  int v7; // eax
  CDmElement *v8; // eax
  int v9; // esi
  CUtlSymbolLarge *v11; // eax
  CDmElement *pRoot; // [esp+8h] [ebp-8h] BYREF
  CDmeHandle<CDmeDCCMakefile,0> hMakefileOld; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bFlushFile || (v2 = this->m_fileId == DMFILEID_INVALID, this->m_bFlushFile = false, v2) )
  {
    v11 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pRoot, a3: "makefile");
    return FindReferringElement<CDmElement>(
             pElement: (CExpressionCalculator *)this,
             symAttrName: (CUtlSymbolLarge)v11->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  else
  {
    hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
    v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
    if ( v3 != DMELEMENT_HANDLE_INVALID )
    {
      CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      hMakefileOld.m_handle = v3;
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
      if ( v4 != nullptr && !v4->IsA(this: v4, a2: CDmeDCCMakefile::m_classType) )
        hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
      CDmeElementRefHelper::Ref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
    }
    m_fileId = this->m_fileId;
    g_pDataModel->UnloadFile(this: g_pDataModel, a2: m_fileId);
    pRoot = nullptr;
    v6 = g_pDataModel->__vftable;
    v7 = ((int (__thiscall *)(IDataModel *, DmFileId_t, _DWORD, _DWORD, CDmElement **, int, _DWORD))g_pDataModel->GetFileName)(
           a1: g_pDataModel,
           a2: m_fileId,
           a3: 0,
           a4: 0,
           a5: &pRoot,
           a6: 1,
           a7: 0);
    if ( ((int (__thiscall *)(IDataModel *, int))v6->RestoreFromFile)(a1: g_pDataModel, a2: v7) == -1
      || g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle) == nullptr )
    {
      if ( g_pDataModel != nullptr )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return nullptr;
    }
    else
    {
      *((_BYTE *)&g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle)[1].m_ref + 8) = 0;
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle);
      v9 = ((int (__thiscall *)(CDmElement *))v8->__vftable[1].Resolve)(a1: v8);
      if ( g_pDataModel != nullptr )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return (CDmElement *)v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475F80
// Name: public: virtual void CDmeDCCMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::GetOutputs(
        CDmeDCCMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString src; // [esp+314h] [ebp-10h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetMakefilePath(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.dmx", pOutputDir, pOutputName);
      CUtlString::CUtlString(this: &src, pString: pFullPath);
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: fullPaths, elem: fullPaths->m_Size, &src);
      src.m_Storage.m_nActualLength = 0;
      if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00476420
// Name: public: virtual bool CDmeSourceDCCFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceDCCFile::IsA(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476450
// Name: public: virtual int CDmeSourceDCCFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceDCCFile::GetInheritanceDepth(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004764F0
// Name: public: virtual bool CDmeSourceMayaFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaFile::IsA(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476530
// Name: public: virtual int CDmeSourceMayaFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaFile::GetInheritanceDepth(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476590
// Name: protected: virtual void CDmeSourceDCCFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::PerformConstruction(CDmeSourceXSIFile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00476600
// Name: public: virtual bool CDmeSourceMayaModelFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaModelFile::IsA(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476640
// Name: public: virtual int CDmeSourceMayaModelFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaModelFile::GetInheritanceDepth(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004766B0
// Name: protected: virtual void CDmeSourceMayaModelFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaModelFile::PerformConstruction(CDmeSourceMayaModelFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00476740
// Name: public: virtual bool CDmeSourceMayaAnimationFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaAnimationFile::IsA(CDmeSourceMayaAnimationFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476780
// Name: public: virtual int CDmeSourceMayaAnimationFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaAnimationFile::GetInheritanceDepth(
        CDmeSourceMayaAnimationFile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004767F0
// Name: protected: virtual void CDmeSourceMayaAnimationFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaAnimationFile::PerformConstruction(CDmeSourceMayaAnimationFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 1;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00476880
// Name: public: virtual bool CDmeSourceXSIFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceXSIFile::IsA(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004768C0
// Name: public: virtual int CDmeSourceXSIFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceXSIFile::GetInheritanceDepth(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476970
// Name: private: virtual char const __near * CDmeDCCMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeDCCMakefile::GetOutputDirectoryID(CDmeDCCMakefile *this)
{
  return "makefiledir:..\\dmx";
}

//------------------------------------------------------------------------------
// Address: 0x00476980
// Name: public: virtual bool CDmeDCCMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDCCMakefile::IsA(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004769B0
// Name: public: virtual int CDmeDCCMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::GetInheritanceDepth(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476A50
// Name: public: virtual bool CDmeMayaMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaMakefile::IsA(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476A90
// Name: public: virtual int CDmeMayaMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaMakefile::GetInheritanceDepth(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476AF0
// Name: protected: virtual void CDmeMayaAnimationMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaAnimationMakefile::PerformConstruction(CDmeMayaAnimationMakefile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMakefile::OnConstruction(this);
  this->m_bFlushFile = false;
}

//------------------------------------------------------------------------------
// Address: 0x00476B60
// Name: public: virtual bool CDmeXSIMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeXSIMakefile::IsA(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476BA0
// Name: public: virtual int CDmeXSIMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeXSIMakefile::GetInheritanceDepth(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476C00
// Name: protected: virtual void CDmeMayaModelMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaModelMakefile::PerformDestruction(CDmeMayaAnimationMakefile *this)
{
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00476C10
// Name: protected: virtual int CDmeDCCMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::AllocatedSize(CDmeMayaAnimationMakefile *this)
{
  return 112;
}

//------------------------------------------------------------------------------
// Address: 0x00476C70
// Name: public: virtual bool CDmeMayaModelMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaModelMakefile::IsA(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476CB0
// Name: public: virtual int CDmeMayaModelMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaModelMakefile::GetInheritanceDepth(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476D70
// Name: public: virtual bool CDmeMayaAnimationMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaAnimationMakefile::IsA(CDmeMayaAnimationMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00476DB0
// Name: public: virtual int CDmeMayaAnimationMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaAnimationMakefile::GetInheritanceDepth(
        CDmeMayaAnimationMakefile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0057A210
// Name: _dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceDCCFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceDCCFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A270
// Name: _dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A2D0
// Name: _dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaModelFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaModelFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A330
// Name: _dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaAnimationFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaAnimationFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A390
// Name: _dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceXSIFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceXSIFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A3F0
// Name: _dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDCCMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDCCMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A450
// Name: _dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A4B0
// Name: _dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaModelMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaModelMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A510
// Name: _dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaAnimationMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaAnimationMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A570
// Name: _dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeXSIMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeXSIMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E360
// Name: _dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceDCCFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E370
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E380
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaModelFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E390
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaAnimationFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E3A0
// Name: _dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceXSIFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E3B0
// Name: _dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDCCMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E3C0
// Name: _dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E3D0
// Name: _dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaModelMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E3E0
// Name: _dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaAnimationMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E3F0
// Name: _dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeXSIMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057A240
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A250
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceDCCFile_Helper,
           classname: "DmeSourceDCCFile",
           pFactory: &g_CDmeSourceDCCFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057A2A0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A2B0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaFile_Helper,
           classname: "DmeSourceMayaFile",
           pFactory: &g_CDmeSourceMayaFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057A300
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A310
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaModelFile_Helper,
           classname: "DmeSourceMayaModelFile",
           pFactory: &g_CDmeSourceMayaModelFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057A360
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A370
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaAnimationFile_Helper,
           classname: "DmeSourceMayaAnimationFile",
           pFactory: &g_CDmeSourceMayaAnimationFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057A3C0
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A3D0
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceXSIFile_Helper,
           classname: "DmeSourceXSIFile",
           pFactory: &g_CDmeSourceXSIFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057A420
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDCCMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A430
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDCCMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDCCMakefile_Helper,
           classname: "DmeDCCMakefile",
           pFactory: &g_CDmeDCCMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057A480
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A490
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaMakefile_Helper,
           classname: "DmeMayaMakefile",
           pFactory: &g_CDmeMayaMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057A4E0
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A4F0
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaModelMakefile_Helper,
           classname: "DmeMayaModelMakefile",
           pFactory: &g_CDmeMayaModelMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057A540
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A550
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaAnimationMakefile_Helper,
           classname: "DmeMayaAnimationMakefile",
           pFactory: &g_CDmeMayaAnimationMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057A5A0
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeXSIMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A5B0
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeXSIMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeXSIMakefile_Helper,
           classname: "DmeXSIMakefile",
           pFactory: &g_CDmeXSIMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E400
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E410
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaModelFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E420
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaAnimationFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E430
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceXSIFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E440
// Name: _dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDCCMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E450
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E460
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaModelMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E470
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaAnimationMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E480
// Name: _dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeXSIMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E490
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceDCCFile_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005D6E40
// Name: private: virtual void CDmeDCCMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::DestroyOutputElement(CDmeDCCMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushFile = true;
}

//------------------------------------------------------------------------------
// Address: 0x005D6E50
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetSourceTypes(CDmeMayaModelMakefile *this)
{
  return s_pMayaModelSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x005D6E60
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetSourceTypes(CDmeMayaAnimationMakefile *this)
{
  return s_pMayaAnimationSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x005D6E70
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetMakefileType(CDmeMayaModelMakefile *this)
{
  return &s_MayaModelMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x005D6E80
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetMakefileType(CDmeMayaAnimationMakefile *this)
{
  return &s_MayaAnimationMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x005D6E90
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetSourceTypes(CDmeXSIMakefile *this)
{
  return s_pXSISourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x005D6EA0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetMakefileType(CDmeXSIMakefile *this)
{
  return &s_XSIMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x005D6EB0
// Name: protected: void CDmeSourceDCCFile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::OnConstruction(CDmeSourceDCCFile *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_RootDCCObjects,
    pOwner: this,
    pAttributeName: "rootDCCObjects",
    nFlags: 0);
  value = 0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "exportType", type: AT_INT, pMemory: &this->m_ExportType);
  this->m_ExportType.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameStart",
         type: AT_FLOAT,
         pMemory: &this->m_FrameStart);
  this->m_FrameStart.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (const float *)&value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "frameEnd", type: AT_FLOAT, pMemory: &this->m_FrameEnd);
  this->m_FrameEnd.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, (const float *)&value);
  value = 1065353216;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameIncrement",
         type: AT_FLOAT,
         pMemory: &this->m_FrameIncrement);
  this->m_FrameIncrement.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, (const float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x005D6F80
// Name: private: virtual class CDmElement __near * CDmeDCCMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeDCCMakefile::CreateOutputElement(CDmeDCCMakefile *this)
{
  bool v2; // zf
  DmElementHandle_t BufferType; // esi
  int v4; // eax
  DmFileId_t m_fileId; // esi
  int v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // esi
  CUtlSymbolLarge *v11; // eax
  CDmElement *pRoot; // [esp+8h] [ebp-8h] BYREF
  CDmeHandle<CDmeDCCMakefile,0> hMakefileOld; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bFlushFile || (v2 = this->m_fileId == DMFILEID_INVALID, this->m_bFlushFile = false, v2) )
  {
    v11 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElement **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                               a1: g_pDataModel.u,
                               a2: &pRoot,
                               a3: "makefile");
    return FindReferringElement<CDmElement>(
             pElement: (CExpressionCalculator *)this,
             symAttrName: (CUtlSymbolLarge)v11->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  else
  {
    hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
    BufferType = CCodecBuffer_Block::GetBufferType((CExpressionCalculator *)this);
    if ( BufferType != DMELEMENT_HANDLE_INVALID )
    {
      CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      hMakefileOld.m_handle = BufferType;
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: BufferType);
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeDCCMakefile::m_classType.u) == 0 )
      {
        hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
      }
      CDmeElementRefHelper::Ref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
    }
    m_fileId = this->m_fileId;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id + 408))(
      a1: g_pDataModel.u,
      a2: m_fileId);
    pRoot = nullptr;
    v6 = *(_DWORD *)g_pDataModel.u.m_Id;
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t, _DWORD, _DWORD, CDmElement **, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 364))(
           a1: g_pDataModel.u,
           a2: m_fileId,
           a3: 0,
           a4: 0,
           a5: &pRoot,
           a6: 1,
           a7: 0);
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v6 + 188))(a1: g_pDataModel.u, a2: v7) == -1
      || (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: hMakefileOld.m_handle) == 0 )
    {
      if ( g_pDataModel.u.m_Id != 0 )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return nullptr;
    }
    else
    {
      *(_BYTE *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
                   a1: g_pDataModel.u,
                   a2: hMakefileOld.m_handle)
               + 104) = 0;
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: hMakefileOld.m_handle);
      v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 68))(a1: v8);
      if ( g_pDataModel.u.m_Id != 0 )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return (CDmElement *)v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D7110
// Name: public: virtual void CDmeDCCMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::GetOutputs(
        CDmeDCCMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString src; // [esp+314h] [ebp-10h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetMakefilePath(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.dmx", pOutputDir, pOutputName);
      CUtlString::CUtlString(this: &src, pString: pFullPath);
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: fullPaths, elem: fullPaths->m_Size, &src);
      src.m_Storage.m_nActualLength = 0;
      if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D75B0
// Name: public: virtual bool CDmeSourceDCCFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceDCCFile::IsA(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D75E0
// Name: public: virtual int CDmeSourceDCCFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceDCCFile::GetInheritanceDepth(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D7680
// Name: public: virtual bool CDmeSourceMayaFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaFile::IsA(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D76C0
// Name: public: virtual int CDmeSourceMayaFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaFile::GetInheritanceDepth(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D7720
// Name: protected: virtual void CDmeSourceDCCFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::PerformConstruction(CDmeSourceXSIFile *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005D7790
// Name: public: virtual bool CDmeSourceMayaModelFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaModelFile::IsA(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D77D0
// Name: public: virtual int CDmeSourceMayaModelFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaModelFile::GetInheritanceDepth(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D7850
// Name: protected: virtual void CDmeSourceMayaModelFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaModelFile::PerformConstruction(CDmeSourceMayaModelFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005D78E0
// Name: public: virtual bool CDmeSourceMayaAnimationFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaAnimationFile::IsA(CDmeSourceMayaAnimationFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D7920
// Name: public: virtual int CDmeSourceMayaAnimationFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaAnimationFile::GetInheritanceDepth(
        CDmeSourceMayaAnimationFile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D7990
// Name: protected: virtual void CDmeSourceMayaAnimationFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaAnimationFile::PerformConstruction(CDmeSourceMayaAnimationFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 1;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005D7A20
// Name: public: virtual bool CDmeSourceXSIFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceXSIFile::IsA(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D7A60
// Name: public: virtual int CDmeSourceXSIFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceXSIFile::GetInheritanceDepth(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D7B10
// Name: private: virtual char const __near * CDmeDCCMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeDCCMakefile::GetOutputDirectoryID(CDmeDCCMakefile *this)
{
  return "makefiledir:..\\dmx";
}

//------------------------------------------------------------------------------
// Address: 0x005D7B20
// Name: public: virtual bool CDmeDCCMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDCCMakefile::IsA(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D7B50
// Name: public: virtual int CDmeDCCMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::GetInheritanceDepth(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D7BF0
// Name: public: virtual bool CDmeMayaMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaMakefile::IsA(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D7C30
// Name: public: virtual int CDmeMayaMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaMakefile::GetInheritanceDepth(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D7C90
// Name: protected: virtual void CDmeMayaAnimationMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaAnimationMakefile::PerformConstruction(CDmeMayaAnimationMakefile *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeMakefile::OnConstruction(this);
  this->m_bFlushFile = false;
}

//------------------------------------------------------------------------------
// Address: 0x005D7CB0
// Name: protected: virtual int CDmeDCCMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::AllocatedSize(CDmeMayaAnimationMakefile *this)
{
  return 112;
}

//------------------------------------------------------------------------------
// Address: 0x005D7D10
// Name: public: virtual bool CDmeXSIMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeXSIMakefile::IsA(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D7D50
// Name: public: virtual int CDmeXSIMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeXSIMakefile::GetInheritanceDepth(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D7DB0
// Name: protected: virtual void CDmeMayaModelMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaModelMakefile::PerformDestruction(CDmeMayaAnimationMakefile *this)
{
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005D7E10
// Name: public: virtual bool CDmeMayaModelMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaModelMakefile::IsA(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D7E50
// Name: public: virtual int CDmeMayaModelMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaModelMakefile::GetInheritanceDepth(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D7F10
// Name: public: virtual bool CDmeMayaAnimationMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaAnimationMakefile::IsA(CDmeMayaAnimationMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D7F50
// Name: public: virtual int CDmeMayaAnimationMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaAnimationMakefile::GetInheritanceDepth(
        CDmeMayaAnimationMakefile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006B07D0
// Name: _dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceDCCFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceDCCFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0830
// Name: _dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0890
// Name: _dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaModelFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaModelFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B08F0
// Name: _dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaAnimationFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaAnimationFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0950
// Name: _dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceXSIFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceXSIFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B09B0
// Name: _dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDCCMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDCCMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0A10
// Name: _dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0A70
// Name: _dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaModelMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaModelMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0AD0
// Name: _dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaAnimationMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaAnimationMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0B30
// Name: _dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeXSIMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeXSIMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B51D0
// Name: _dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceDCCFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B51E0
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B51F0
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaModelFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5200
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaAnimationFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5210
// Name: _dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceXSIFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5220
// Name: _dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDCCMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5230
// Name: _dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5240
// Name: _dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaModelMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5250
// Name: _dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaAnimationMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5260
// Name: _dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeXSIMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B0800
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0810
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceDCCFile_Helper,
           classname: "DmeSourceDCCFile",
           pFactory: &g_CDmeSourceDCCFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B0860
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0870
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaFile_Helper,
           classname: "DmeSourceMayaFile",
           pFactory: &g_CDmeSourceMayaFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B08C0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B08D0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaModelFile_Helper,
           classname: "DmeSourceMayaModelFile",
           pFactory: &g_CDmeSourceMayaModelFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B0920
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0930
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaAnimationFile_Helper,
           classname: "DmeSourceMayaAnimationFile",
           pFactory: &g_CDmeSourceMayaAnimationFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B0980
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0990
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceXSIFile_Helper,
           classname: "DmeSourceXSIFile",
           pFactory: &g_CDmeSourceXSIFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B09E0
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDCCMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B09F0
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDCCMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDCCMakefile_Helper,
           classname: "DmeDCCMakefile",
           pFactory: &g_CDmeDCCMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B0A40
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0A50
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaMakefile_Helper,
           classname: "DmeMayaMakefile",
           pFactory: &g_CDmeMayaMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B0AA0
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0AB0
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaModelMakefile_Helper,
           classname: "DmeMayaModelMakefile",
           pFactory: &g_CDmeMayaModelMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B0B00
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0B10
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaAnimationMakefile_Helper,
           classname: "DmeMayaAnimationMakefile",
           pFactory: &g_CDmeMayaAnimationMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B0B60
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeXSIMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0B70
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeXSIMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeXSIMakefile_Helper,
           classname: "DmeXSIMakefile",
           pFactory: &g_CDmeXSIMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5270
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSourceMayaFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5280
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSourceMayaModelFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5290
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSourceMayaAnimationFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B52A0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSourceXSIFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B52B0
// Name: _dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeDCCMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B52C0
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMayaMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B52D0
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMayaModelMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B52E0
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMayaAnimationMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B52F0
// Name: _dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeXSIMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5300
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSourceDCCFile_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x004769A0
// Name: private: virtual void CDmeDCCMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::DestroyOutputElement(CDmeDCCMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushFile = true;
}

//------------------------------------------------------------------------------
// Address: 0x004769C0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetSourceTypes(CDmeMayaAnimationMakefile *this)
{
  return s_pMayaAnimationSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x004769D0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetMakefileType(CDmeMayaModelMakefile *this)
{
  return &s_MayaModelMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x004769E0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetMakefileType(CDmeMayaAnimationMakefile *this)
{
  return &s_MayaAnimationMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x004769F0
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetSourceTypes(CDmeXSIMakefile *this)
{
  return s_pXSISourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00476A00
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetMakefileType(CDmeXSIMakefile *this)
{
  return &s_XSIMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00476A10
// Name: protected: void CDmeSourceDCCFile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::OnConstruction(CDmeSourceDCCFile *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_RootDCCObjects,
    pOwner: this,
    pAttributeName: "rootDCCObjects",
    nFlags: 0);
  value = 0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "exportType", type: AT_INT, pMemory: &this->m_ExportType);
  this->m_ExportType.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameStart",
         type: AT_FLOAT,
         pMemory: &this->m_FrameStart);
  this->m_FrameStart.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (const float *)&value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "frameEnd", type: AT_FLOAT, pMemory: &this->m_FrameEnd);
  this->m_FrameEnd.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, (const float *)&value);
  value = 1065353216;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameIncrement",
         type: AT_FLOAT,
         pMemory: &this->m_FrameIncrement);
  this->m_FrameIncrement.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, (const float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x00476AE0
// Name: private: virtual class CDmElement __near * CDmeDCCMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeDCCMakefile::CreateOutputElement(CDmeDCCMakefile *this)
{
  bool v2; // zf
  DmElementHandle_t v3; // esi
  CDmElement *v4; // eax
  DmFileId_t m_fileId; // esi
  IDataModel_vtbl *v6; // edi
  int v7; // eax
  CDmElement *v8; // eax
  int v9; // esi
  CUtlSymbolLarge *v11; // eax
  CDmElement *pRoot; // [esp+8h] [ebp-8h] BYREF
  CDmeHandle<CDmeDCCMakefile,0> hMakefileOld; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bFlushFile || (v2 = this->m_fileId == DMFILEID_INVALID, this->m_bFlushFile = false, v2) )
  {
    v11 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pRoot, a3: "makefile");
    return FindReferringElement<CDmElement>(
             pElement: (CExpressionCalculator *)this,
             symAttrName: (CUtlSymbolLarge)v11->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  else
  {
    hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
    v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
    if ( v3 != DMELEMENT_HANDLE_INVALID )
    {
      CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      hMakefileOld.m_handle = v3;
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
      if ( v4 != nullptr && !v4->IsA(this: v4, a2: CDmeDCCMakefile::m_classType) )
        hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
      CDmeElementRefHelper::Ref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
    }
    m_fileId = this->m_fileId;
    g_pDataModel->UnloadFile(this: g_pDataModel, a2: m_fileId);
    pRoot = nullptr;
    v6 = g_pDataModel->__vftable;
    v7 = ((int (__thiscall *)(IDataModel *, DmFileId_t, _DWORD, _DWORD, CDmElement **, int, _DWORD))g_pDataModel->GetFileName)(
           a1: g_pDataModel,
           a2: m_fileId,
           a3: 0,
           a4: 0,
           a5: &pRoot,
           a6: 1,
           a7: 0);
    if ( ((int (__thiscall *)(IDataModel *, int))v6->RestoreFromFile)(a1: g_pDataModel, a2: v7) == -1
      || g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle) == nullptr )
    {
      if ( g_pDataModel != nullptr )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return nullptr;
    }
    else
    {
      *((_BYTE *)&g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle)[1].m_ref + 8) = 0;
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle);
      v9 = ((int (__thiscall *)(CDmElement *))v8->__vftable[1].Resolve)(a1: v8);
      if ( g_pDataModel != nullptr )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return (CDmElement *)v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477150
// Name: public: virtual bool CDmeSourceDCCFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceDCCFile::IsA(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00477180
// Name: public: virtual int CDmeSourceDCCFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceDCCFile::GetInheritanceDepth(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00477220
// Name: public: virtual bool CDmeSourceMayaFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaFile::IsA(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00477260
// Name: public: virtual int CDmeSourceMayaFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaFile::GetInheritanceDepth(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004772C0
// Name: protected: virtual void CDmeSourceDCCFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::PerformConstruction(CDmeSourceXSIFile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00477330
// Name: public: virtual bool CDmeSourceMayaModelFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaModelFile::IsA(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00477370
// Name: public: virtual int CDmeSourceMayaModelFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaModelFile::GetInheritanceDepth(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004773E0
// Name: protected: virtual void CDmeSourceMayaModelFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaModelFile::PerformConstruction(CDmeSourceMayaModelFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00477470
// Name: public: virtual bool CDmeSourceMayaAnimationFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaAnimationFile::IsA(CDmeSourceMayaAnimationFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004774B0
// Name: public: virtual int CDmeSourceMayaAnimationFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaAnimationFile::GetInheritanceDepth(
        CDmeSourceMayaAnimationFile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00477520
// Name: protected: virtual void CDmeSourceMayaAnimationFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaAnimationFile::PerformConstruction(CDmeSourceMayaAnimationFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 1;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004775B0
// Name: public: virtual bool CDmeSourceXSIFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceXSIFile::IsA(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004775F0
// Name: public: virtual int CDmeSourceXSIFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceXSIFile::GetInheritanceDepth(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004776A0
// Name: private: virtual char const __near * CDmeDCCMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeDCCMakefile::GetOutputDirectoryID(CDmeDCCMakefile *this)
{
  return "makefiledir:..\\dmx";
}

//------------------------------------------------------------------------------
// Address: 0x004776B0
// Name: public: virtual bool CDmeDCCMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDCCMakefile::IsA(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004776E0
// Name: public: virtual int CDmeDCCMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::GetInheritanceDepth(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00477730
// Name: protected: virtual void CDmeMayaAnimationMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaAnimationMakefile::PerformConstruction(CDmeMayaAnimationMakefile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMakefile::OnConstruction(this);
  this->m_bFlushFile = false;
}

//------------------------------------------------------------------------------
// Address: 0x004777A0
// Name: public: virtual bool CDmeMayaMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaMakefile::IsA(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004777E0
// Name: public: virtual int CDmeMayaMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaMakefile::GetInheritanceDepth(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00477840
// Name: protected: virtual void CDmeMayaModelMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaModelMakefile::PerformDestruction(CDmeMayaAnimationMakefile *this)
{
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004778A0
// Name: public: virtual bool CDmeXSIMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeXSIMakefile::IsA(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004778E0
// Name: public: virtual int CDmeXSIMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeXSIMakefile::GetInheritanceDepth(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00477990
// Name: public: virtual bool CDmeMayaModelMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaModelMakefile::IsA(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004779D0
// Name: public: virtual int CDmeMayaModelMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaModelMakefile::GetInheritanceDepth(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00477A40
// Name: protected: virtual int CDmeDCCMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::AllocatedSize(CDmeMayaAnimationMakefile *this)
{
  return 112;
}

//------------------------------------------------------------------------------
// Address: 0x00477AA0
// Name: public: virtual bool CDmeMayaAnimationMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaAnimationMakefile::IsA(CDmeMayaAnimationMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00477AE0
// Name: public: virtual int CDmeMayaAnimationMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaAnimationMakefile::GetInheritanceDepth(
        CDmeMayaAnimationMakefile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0057C200
// Name: _dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceDCCFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceDCCFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C260
// Name: _dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C2C0
// Name: _dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaModelFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaModelFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C320
// Name: _dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaAnimationFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaAnimationFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C380
// Name: _dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceXSIFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceXSIFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C3E0
// Name: _dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDCCMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDCCMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C440
// Name: _dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C4A0
// Name: _dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaModelMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaModelMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C500
// Name: _dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaAnimationMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaAnimationMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C560
// Name: _dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeXSIMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeXSIMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580340
// Name: _dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceDCCFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580350
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580360
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaModelFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580370
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaAnimationFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580380
// Name: _dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceXSIFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580390
// Name: _dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDCCMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005803A0
// Name: _dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005803B0
// Name: _dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaModelMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005803C0
// Name: _dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaAnimationMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005803D0
// Name: _dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeXSIMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057C230
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C240
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceDCCFile_Helper,
           classname: "DmeSourceDCCFile",
           pFactory: &g_CDmeSourceDCCFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C290
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C2A0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaFile_Helper,
           classname: "DmeSourceMayaFile",
           pFactory: &g_CDmeSourceMayaFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C2F0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C300
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaModelFile_Helper,
           classname: "DmeSourceMayaModelFile",
           pFactory: &g_CDmeSourceMayaModelFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C350
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C360
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaAnimationFile_Helper,
           classname: "DmeSourceMayaAnimationFile",
           pFactory: &g_CDmeSourceMayaAnimationFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C3B0
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C3C0
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceXSIFile_Helper,
           classname: "DmeSourceXSIFile",
           pFactory: &g_CDmeSourceXSIFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C410
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDCCMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C420
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDCCMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDCCMakefile_Helper,
           classname: "DmeDCCMakefile",
           pFactory: &g_CDmeDCCMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C470
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C480
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaMakefile_Helper,
           classname: "DmeMayaMakefile",
           pFactory: &g_CDmeMayaMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C4D0
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C4E0
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaModelMakefile_Helper,
           classname: "DmeMayaModelMakefile",
           pFactory: &g_CDmeMayaModelMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C530
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C540
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaAnimationMakefile_Helper,
           classname: "DmeMayaAnimationMakefile",
           pFactory: &g_CDmeMayaAnimationMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C590
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeXSIMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C5A0
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeXSIMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeXSIMakefile_Helper,
           classname: "DmeXSIMakefile",
           pFactory: &g_CDmeXSIMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005803E0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005803F0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaModelFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580400
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaAnimationFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580410
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceXSIFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580420
// Name: _dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDCCMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580430
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580440
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaModelMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580450
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaAnimationMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580460
// Name: _dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeXSIMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580470
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceDCCFile_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x00506910
// Name: private: virtual void CDmeDCCMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::DestroyOutputElement(CDmeDCCMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushFile = true;
}

//------------------------------------------------------------------------------
// Address: 0x00506920
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetSourceTypes(CDmeMayaModelMakefile *this)
{
  return s_pMayaModelSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00506930
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetSourceTypes(CDmeMayaAnimationMakefile *this)
{
  return s_pMayaAnimationSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00506940
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetMakefileType(CDmeMayaModelMakefile *this)
{
  return &s_MayaModelMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00506950
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetMakefileType(CDmeMayaAnimationMakefile *this)
{
  return &s_MayaAnimationMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00506960
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetSourceTypes(CDmeXSIMakefile *this)
{
  return s_pXSISourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00506970
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetMakefileType(CDmeXSIMakefile *this)
{
  return &s_XSIMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00506980
// Name: protected: void CDmeSourceDCCFile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::OnConstruction(CDmeSourceDCCFile *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_RootDCCObjects,
    pOwner: this,
    pAttributeName: "rootDCCObjects",
    nFlags: 0);
  value = 0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "exportType", type: AT_INT, pMemory: &this->m_ExportType);
  this->m_ExportType.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameStart",
         type: AT_FLOAT,
         pMemory: &this->m_FrameStart);
  this->m_FrameStart.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (float *)&value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "frameEnd", type: AT_FLOAT, pMemory: &this->m_FrameEnd);
  this->m_FrameEnd.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, (float *)&value);
  value = 1065353216;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameIncrement",
         type: AT_FLOAT,
         pMemory: &this->m_FrameIncrement);
  this->m_FrameIncrement.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, (float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x00506A50
// Name: private: virtual class CDmElement __near * CDmeDCCMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeDCCMakefile::CreateOutputElement(CDmeDCCMakefile *this)
{
  bool v2; // zf
  DmElementHandle_t v3; // esi
  int v4; // eax
  DmFileId_t m_fileId; // esi
  int v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // esi
  CUtlSymbolLarge *v11; // eax
  CDmElement *pRoot; // [esp+8h] [ebp-8h] BYREF
  CDmeHandle<CDmeDCCMakefile,0> hMakefileOld; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bFlushFile || (v2 = this->m_fileId == DMFILEID_INVALID, this->m_bFlushFile = false, v2) )
  {
    v11 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElement **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                               a1: g_pDataModel.u,
                               a2: &pRoot,
                               a3: "makefile");
    return FindReferringElement<CDmElement>(
             pElement: (CExpressionCalculator *)this,
             symAttrName: (CUtlSymbolLarge)v11->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  else
  {
    hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
    v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
    if ( v3 != DMELEMENT_HANDLE_INVALID )
    {
      CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      hMakefileOld.m_handle = v3;
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: v3);
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeDCCMakefile::m_classType.u) == 0 )
      {
        hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
      }
      CDmeElementRefHelper::Ref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
    }
    m_fileId = this->m_fileId;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id + 408))(
      a1: g_pDataModel.u,
      a2: m_fileId);
    pRoot = nullptr;
    v6 = *(_DWORD *)g_pDataModel.u.m_Id;
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t, _DWORD, _DWORD, CDmElement **, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 364))(
           a1: g_pDataModel.u,
           a2: m_fileId,
           a3: 0,
           a4: 0,
           a5: &pRoot,
           a6: 1,
           a7: 0);
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v6 + 188))(a1: g_pDataModel.u, a2: v7) == -1
      || (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: hMakefileOld.m_handle) == 0 )
    {
      if ( g_pDataModel.u.m_Id != 0 )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return nullptr;
    }
    else
    {
      *(_BYTE *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
                   a1: g_pDataModel.u,
                   a2: hMakefileOld.m_handle)
               + 104) = 0;
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: hMakefileOld.m_handle);
      v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 68))(a1: v8);
      if ( g_pDataModel.u.m_Id != 0 )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return (CDmElement *)v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00506BE0
// Name: public: virtual void CDmeDCCMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::GetOutputs(
        CDmeDCCMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString src; // [esp+314h] [ebp-10h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetMakefilePath(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.dmx", pOutputDir, pOutputName);
      CUtlString::CUtlString(this: &src, pString: pFullPath);
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: fullPaths, elem: fullPaths->m_Size, &src);
      src.m_Storage.m_nActualLength = 0;
      if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00507090
// Name: public: virtual bool CDmeSourceDCCFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceDCCFile::IsA(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005070C0
// Name: public: virtual int CDmeSourceDCCFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceDCCFile::GetInheritanceDepth(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507160
// Name: public: virtual bool CDmeSourceMayaFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaFile::IsA(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005071A0
// Name: public: virtual int CDmeSourceMayaFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaFile::GetInheritanceDepth(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507200
// Name: protected: virtual void CDmeSourceDCCFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::PerformConstruction(CDmeSourceXSIFile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00507270
// Name: public: virtual bool CDmeSourceMayaModelFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaModelFile::IsA(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005072B0
// Name: public: virtual int CDmeSourceMayaModelFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaModelFile::GetInheritanceDepth(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507320
// Name: protected: virtual void CDmeSourceMayaModelFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaModelFile::PerformConstruction(CDmeSourceMayaModelFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005073B0
// Name: public: virtual bool CDmeSourceMayaAnimationFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaAnimationFile::IsA(CDmeSourceMayaAnimationFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005073F0
// Name: public: virtual int CDmeSourceMayaAnimationFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaAnimationFile::GetInheritanceDepth(
        CDmeSourceMayaAnimationFile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507460
// Name: protected: virtual int CDmeSourceMayaAnimationFile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaAnimationFile::AllocatedSize(CDmeSourceXSIFile *this)
{
  return 128;
}

//------------------------------------------------------------------------------
// Address: 0x00507500
// Name: public: virtual bool CDmeSourceXSIFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceXSIFile::IsA(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507540
// Name: public: virtual int CDmeSourceXSIFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceXSIFile::GetInheritanceDepth(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005075F0
// Name: private: virtual char const __near * CDmeDCCMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeDCCMakefile::GetOutputDirectoryID(CDmeDCCMakefile *this)
{
  return "makefiledir:..\\dmx";
}

//------------------------------------------------------------------------------
// Address: 0x00507600
// Name: public: virtual bool CDmeDCCMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDCCMakefile::IsA(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507630
// Name: public: virtual int CDmeDCCMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::GetInheritanceDepth(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005076D0
// Name: public: virtual bool CDmeMayaMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaMakefile::IsA(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507710
// Name: public: virtual int CDmeMayaMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaMakefile::GetInheritanceDepth(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005077C0
// Name: public: virtual bool CDmeXSIMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeXSIMakefile::IsA(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507800
// Name: public: virtual int CDmeXSIMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeXSIMakefile::GetInheritanceDepth(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507860
// Name: protected: virtual void CDmeMayaModelMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaModelMakefile::PerformDestruction(CDmeMayaAnimationMakefile *this)
{
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005078C0
// Name: public: virtual bool CDmeMayaModelMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaModelMakefile::IsA(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507970
// Name: protected: virtual void CDmeMayaAnimationMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaAnimationMakefile::PerformConstruction(CDmeMayaAnimationMakefile *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMakefile::OnConstruction(this);
  this->m_bFlushFile = false;
}

//------------------------------------------------------------------------------
// Address: 0x005079F0
// Name: public: virtual bool CDmeMayaAnimationMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaAnimationMakefile::IsA(CDmeMayaAnimationMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00507A30
// Name: public: virtual int CDmeMayaAnimationMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaAnimationMakefile::GetInheritanceDepth(
        CDmeMayaAnimationMakefile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E93B0
// Name: _dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceDCCFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceDCCFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9410
// Name: _dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9470
// Name: _dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaModelFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaModelFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E94D0
// Name: _dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaAnimationFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaAnimationFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9530
// Name: _dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceXSIFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceXSIFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9590
// Name: _dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDCCMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDCCMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E95F0
// Name: _dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9650
// Name: _dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaModelMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaModelMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E96B0
// Name: _dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaAnimationMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaAnimationMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9710
// Name: _dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeXSIMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeXSIMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED1A0
// Name: _dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceDCCFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED1B0
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED1C0
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaModelFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED1D0
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaAnimationFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED1E0
// Name: _dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceXSIFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED1F0
// Name: _dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDCCMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED200
// Name: _dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED210
// Name: _dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaModelMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED220
// Name: _dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaAnimationMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED230
// Name: _dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeXSIMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E93E0
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E93F0
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceDCCFile_Helper,
           classname: "DmeSourceDCCFile",
           pFactory: &g_CDmeSourceDCCFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E9440
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9450
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaFile_Helper,
           classname: "DmeSourceMayaFile",
           pFactory: &g_CDmeSourceMayaFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E94A0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E94B0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaModelFile_Helper,
           classname: "DmeSourceMayaModelFile",
           pFactory: &g_CDmeSourceMayaModelFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E9500
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9510
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaAnimationFile_Helper,
           classname: "DmeSourceMayaAnimationFile",
           pFactory: &g_CDmeSourceMayaAnimationFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E9560
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9570
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceXSIFile_Helper,
           classname: "DmeSourceXSIFile",
           pFactory: &g_CDmeSourceXSIFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E95C0
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDCCMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E95D0
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDCCMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDCCMakefile_Helper,
           classname: "DmeDCCMakefile",
           pFactory: &g_CDmeDCCMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E9620
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9630
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaMakefile_Helper,
           classname: "DmeMayaMakefile",
           pFactory: &g_CDmeMayaMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E9680
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9690
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaModelMakefile_Helper,
           classname: "DmeMayaModelMakefile",
           pFactory: &g_CDmeMayaModelMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E96E0
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E96F0
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaAnimationMakefile_Helper,
           classname: "DmeMayaAnimationMakefile",
           pFactory: &g_CDmeMayaAnimationMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E9740
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeXSIMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9750
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeXSIMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeXSIMakefile_Helper,
           classname: "DmeXSIMakefile",
           pFactory: &g_CDmeXSIMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED240
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED250
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaModelFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED260
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaAnimationFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED270
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceXSIFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED280
// Name: _dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDCCMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED290
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED2A0
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaModelMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED2B0
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaAnimationMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED2C0
// Name: _dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeXSIMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED2D0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceDCCFile_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0047F7A0
// Name: protected: virtual void CDmeSourceMayaAnimationFile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaAnimationFile::PerformDestruction(CDmeShape *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00480C30
// Name: private: virtual void CDmeDCCMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::DestroyOutputElement(CDmeDCCMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushFile = true;
}

//------------------------------------------------------------------------------
// Address: 0x00480C40
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetSourceTypes(CDmeMayaModelMakefile *this)
{
  return s_pMayaModelSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00480C50
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetSourceTypes(CDmeMayaAnimationMakefile *this)
{
  return s_pMayaAnimationSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00480C60
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetMakefileType(CDmeMayaModelMakefile *this)
{
  return &s_MayaModelMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00480C70
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetMakefileType(CDmeMayaAnimationMakefile *this)
{
  return &s_MayaAnimationMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00480C80
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetSourceTypes(CDmeXSIMakefile *this)
{
  return s_pXSISourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00480C90
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetMakefileType(CDmeXSIMakefile *this)
{
  return &s_XSIMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00480CA0
// Name: protected: void CDmeSourceDCCFile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::OnConstruction(CDmeSourceDCCFile *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_RootDCCObjects,
    pOwner: this,
    pAttributeName: "rootDCCObjects",
    nFlags: 0);
  value = 0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "exportType", type: AT_INT, pMemory: &this->m_ExportType);
  this->m_ExportType.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameStart",
         type: AT_FLOAT,
         pMemory: &this->m_FrameStart);
  this->m_FrameStart.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (const float *)&value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "frameEnd", type: AT_FLOAT, pMemory: &this->m_FrameEnd);
  this->m_FrameEnd.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, (const float *)&value);
  value = 1065353216;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameIncrement",
         type: AT_FLOAT,
         pMemory: &this->m_FrameIncrement);
  this->m_FrameIncrement.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, (const float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x00480D70
// Name: private: virtual class CDmElement __near * CDmeDCCMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeDCCMakefile::CreateOutputElement(CDmeDCCMakefile *this)
{
  bool v2; // zf
  DmElementHandle_t v3; // esi
  CDmElement *v4; // eax
  DmFileId_t m_fileId; // esi
  IDataModel_vtbl *v6; // edi
  int v7; // eax
  CDmElement *v8; // eax
  int v9; // esi
  CUtlSymbolLarge *v11; // eax
  CDmElement *pRoot; // [esp+8h] [ebp-8h] BYREF
  CDmeHandle<CDmeDCCMakefile,0> hMakefileOld; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bFlushFile || (v2 = this->m_fileId == DMFILEID_INVALID, this->m_bFlushFile = false, v2) )
  {
    v11 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pRoot, a3: "makefile");
    return FindReferringElement<CDmElement>(
             pElement: (CExpressionCalculator *)this,
             symAttrName: (CUtlSymbolLarge)v11->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  else
  {
    hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
    v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
    if ( v3 != DMELEMENT_HANDLE_INVALID )
    {
      CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      hMakefileOld.m_handle = v3;
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
      if ( v4 != nullptr && !v4->IsA(this: v4, a2: CDmeDCCMakefile::m_classType) )
        hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
      CDmeElementRefHelper::Ref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
    }
    m_fileId = this->m_fileId;
    g_pDataModel->UnloadFile(this: g_pDataModel, a2: m_fileId);
    pRoot = nullptr;
    v6 = g_pDataModel->__vftable;
    v7 = ((int (__thiscall *)(IDataModel *, DmFileId_t, _DWORD, _DWORD, CDmElement **, int, _DWORD))g_pDataModel->GetFileName)(
           a1: g_pDataModel,
           a2: m_fileId,
           a3: 0,
           a4: 0,
           a5: &pRoot,
           a6: 1,
           a7: 0);
    if ( ((int (__thiscall *)(IDataModel *, int))v6->RestoreFromFile)(a1: g_pDataModel, a2: v7) == -1
      || g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle) == nullptr )
    {
      if ( g_pDataModel != nullptr )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return nullptr;
    }
    else
    {
      *((_BYTE *)&g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle)[1].m_ref + 8) = 0;
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle);
      v9 = ((int (__thiscall *)(CDmElement *))v8->__vftable[1].Resolve)(a1: v8);
      if ( g_pDataModel != nullptr )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return (CDmElement *)v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480F00
// Name: public: virtual void CDmeDCCMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::GetOutputs(
        CDmeDCCMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString src; // [esp+314h] [ebp-10h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetMakefilePath(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.dmx", pOutputDir, pOutputName);
      CUtlString::CUtlString(this: &src, pString: pFullPath);
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: fullPaths, elem: fullPaths->m_Size, &src);
      src.m_Storage.m_nActualLength = 0;
      if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004813A0
// Name: public: virtual bool CDmeSourceDCCFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceDCCFile::IsA(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004813D0
// Name: public: virtual int CDmeSourceDCCFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceDCCFile::GetInheritanceDepth(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00481420
// Name: protected: virtual void CDmeSourceDCCFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::PerformConstruction(CDmeSourceXSIFile *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00481490
// Name: public: virtual bool CDmeSourceMayaFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaFile::IsA(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004814D0
// Name: public: virtual int CDmeSourceMayaFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaFile::GetInheritanceDepth(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00481580
// Name: public: virtual bool CDmeSourceMayaModelFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaModelFile::IsA(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004815C0
// Name: public: virtual int CDmeSourceMayaModelFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaModelFile::GetInheritanceDepth(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00481640
// Name: protected: virtual void CDmeSourceMayaModelFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaModelFile::PerformConstruction(CDmeSourceMayaModelFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004816D0
// Name: public: virtual bool CDmeSourceMayaAnimationFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaAnimationFile::IsA(CDmeSourceMayaAnimationFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00481710
// Name: public: virtual int CDmeSourceMayaAnimationFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaAnimationFile::GetInheritanceDepth(
        CDmeSourceMayaAnimationFile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00481780
// Name: protected: virtual void CDmeSourceMayaAnimationFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaAnimationFile::PerformConstruction(CDmeSourceMayaAnimationFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 1;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00481810
// Name: public: virtual bool CDmeSourceXSIFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceXSIFile::IsA(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00481850
// Name: public: virtual int CDmeSourceXSIFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceXSIFile::GetInheritanceDepth(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00481900
// Name: private: virtual char const __near * CDmeDCCMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeDCCMakefile::GetOutputDirectoryID(CDmeDCCMakefile *this)
{
  return "makefiledir:..\\dmx";
}

//------------------------------------------------------------------------------
// Address: 0x00481910
// Name: public: virtual bool CDmeDCCMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDCCMakefile::IsA(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00481940
// Name: public: virtual int CDmeDCCMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::GetInheritanceDepth(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004819E0
// Name: public: virtual bool CDmeMayaMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaMakefile::IsA(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00481A20
// Name: public: virtual int CDmeMayaMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaMakefile::GetInheritanceDepth(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00481A80
// Name: protected: virtual void CDmeMayaModelMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaModelMakefile::PerformDestruction(CDmeMayaAnimationMakefile *this)
{
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00481AE0
// Name: public: virtual bool CDmeXSIMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeXSIMakefile::IsA(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00481B20
// Name: public: virtual int CDmeXSIMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeXSIMakefile::GetInheritanceDepth(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00481BD0
// Name: public: virtual bool CDmeMayaModelMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaModelMakefile::IsA(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00481C10
// Name: public: virtual int CDmeMayaModelMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaModelMakefile::GetInheritanceDepth(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00481CD0
// Name: public: virtual bool CDmeMayaAnimationMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaAnimationMakefile::IsA(CDmeMayaAnimationMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00481D10
// Name: public: virtual int CDmeMayaAnimationMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaAnimationMakefile::GetInheritanceDepth(
        CDmeMayaAnimationMakefile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00481D80
// Name: protected: virtual void CDmeMayaAnimationMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaAnimationMakefile::PerformConstruction(CDmeMayaAnimationMakefile *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeMakefile::OnConstruction(this);
  this->m_bFlushFile = false;
}

//------------------------------------------------------------------------------
// Address: 0x00532150
// Name: protected: virtual int CDmeDCCMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::AllocatedSize(CDmeMayaAnimationMakefile *this)
{
  return 112;
}

//------------------------------------------------------------------------------
// Address: 0x00579AB0
// Name: _dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceDCCFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceDCCFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00579B10
// Name: _dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00579B70
// Name: _dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaModelFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaModelFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00579BD0
// Name: _dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaAnimationFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaAnimationFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00579C30
// Name: _dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceXSIFile::s_Allocator,
    blockSize: 128,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceXSIFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00579C90
// Name: _dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDCCMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDCCMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00579CF0
// Name: _dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00579D50
// Name: _dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaModelMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaModelMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00579DB0
// Name: _dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaAnimationMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaAnimationMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00579E10
// Name: _dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeXSIMakefile::s_Allocator,
    blockSize: 112,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeXSIMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DA50
// Name: _dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceDCCFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057DA60
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057DA70
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaModelFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057DA80
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaAnimationFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057DA90
// Name: _dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceXSIFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057DAA0
// Name: _dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDCCMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057DAB0
// Name: _dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057DAC0
// Name: _dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaModelMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057DAD0
// Name: _dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaAnimationMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057DAE0
// Name: _dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeXSIMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00579AE0
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579AF0
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceDCCFile_Helper,
           classname: "DmeSourceDCCFile",
           pFactory: &g_CDmeSourceDCCFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579B40
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579B50
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaFile_Helper,
           classname: "DmeSourceMayaFile",
           pFactory: &g_CDmeSourceMayaFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579BA0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579BB0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaModelFile_Helper,
           classname: "DmeSourceMayaModelFile",
           pFactory: &g_CDmeSourceMayaModelFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579C00
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579C10
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaAnimationFile_Helper,
           classname: "DmeSourceMayaAnimationFile",
           pFactory: &g_CDmeSourceMayaAnimationFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579C60
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579C70
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceXSIFile_Helper,
           classname: "DmeSourceXSIFile",
           pFactory: &g_CDmeSourceXSIFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579CC0
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDCCMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579CD0
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDCCMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDCCMakefile_Helper,
           classname: "DmeDCCMakefile",
           pFactory: &g_CDmeDCCMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579D20
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579D30
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaMakefile_Helper,
           classname: "DmeMayaMakefile",
           pFactory: &g_CDmeMayaMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579D80
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579D90
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaModelMakefile_Helper,
           classname: "DmeMayaModelMakefile",
           pFactory: &g_CDmeMayaModelMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579DE0
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579DF0
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaAnimationMakefile_Helper,
           classname: "DmeMayaAnimationMakefile",
           pFactory: &g_CDmeMayaAnimationMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579E40
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeXSIMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579E50
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeXSIMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeXSIMakefile_Helper,
           classname: "DmeXSIMakefile",
           pFactory: &g_CDmeXSIMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057DAF0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057DB00
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaModelFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057DB10
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceMayaAnimationFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057DB20
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceXSIFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057DB30
// Name: _dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDCCMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057DB40
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057DB50
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaModelMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057DB60
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMayaAnimationMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057DB70
// Name: _dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeXSIMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057DB80
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSourceDCCFile_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x005836C0
// Name: protected: virtual void CDmeSourceMayaAnimationFile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaAnimationFile::PerformDestruction(CDmeSourceAnimation *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00583A20
// Name: private: virtual void CDmeDCCMakefile::DestroyOutputElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::DestroyOutputElement(CDmeDCCMakefile *this, CDmElement *pOutput)
{
  this->m_bFlushFile = true;
}

//------------------------------------------------------------------------------
// Address: 0x00583A30
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetSourceTypes(CDmeMayaModelMakefile *this)
{
  return s_pMayaModelSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00583A40
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetSourceTypes(CDmeMayaAnimationMakefile *this)
{
  return s_pMayaAnimationSourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00583A50
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaModelMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaModelMakefile::GetMakefileType(CDmeMayaModelMakefile *this)
{
  return &s_MayaModelMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00583A60
// Name: public: virtual struct DmeMakefileType_t __near * CDmeMayaAnimationMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeMayaAnimationMakefile::GetMakefileType(CDmeMayaAnimationMakefile *this)
{
  return &s_MayaAnimationMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00583A70
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetSourceTypes(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetSourceTypes(CDmeXSIMakefile *this)
{
  return s_pXSISourceTypes;
}

//------------------------------------------------------------------------------
// Address: 0x00583A80
// Name: public: virtual struct DmeMakefileType_t __near * CDmeXSIMakefile::GetMakefileType(void)
// Source: json
//------------------------------------------------------------------------------
DmeMakefileType_t *__thiscall CDmeXSIMakefile::GetMakefileType(CDmeXSIMakefile *this)
{
  return &s_XSIMakefileType;
}

//------------------------------------------------------------------------------
// Address: 0x00583A90
// Name: protected: void CDmeSourceDCCFile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::OnConstruction(CDmeSourceDCCFile *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  CDmaDecorator<CUtlSymbolLarge,CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>>::Init(
    this: (CDmaDecorator<CUtlSymbolLarge,CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > > *)&this->m_RootDCCObjects,
    pOwner: this,
    pAttributeName: "rootDCCObjects",
    nFlags: 0);
  value = 0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "exportType", type: AT_INT, pMemory: &this->m_ExportType);
  this->m_ExportType.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  value = 0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameStart",
         type: AT_FLOAT,
         pMemory: &this->m_FrameStart);
  this->m_FrameStart.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (float *)&value);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "frameEnd", type: AT_FLOAT, pMemory: &this->m_FrameEnd);
  this->m_FrameEnd.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, (float *)&value);
  value = 1065353216;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "frameIncrement",
         type: AT_FLOAT,
         pMemory: &this->m_FrameIncrement);
  this->m_FrameIncrement.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, (float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x00583B60
// Name: private: virtual class CDmElement __near * CDmeDCCMakefile::CreateOutputElement(void)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeDCCMakefile::CreateOutputElement(CDmeDCCMakefile *this)
{
  bool v2; // zf
  DmElementHandle_t CenterVertIndex; // esi
  CDmElement *v4; // eax
  DmFileId_t m_fileId; // esi
  IDataModel_vtbl *v6; // edi
  int v7; // eax
  CDmElement *v8; // eax
  int v9; // esi
  CUtlSymbolLarge *v11; // eax
  CDmElement *pRoot; // [esp+8h] [ebp-8h] BYREF
  CDmeHandle<CDmeDCCMakefile,0> hMakefileOld; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->m_bFlushFile || (v2 = this->m_fileId == DMFILEID_INVALID, this->m_bFlushFile = false, v2) )
  {
    v11 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pRoot, a3: "makefile");
    return FindReferringElement<CDmElement>(
             pElement: (CVTFTexture *)this,
             symAttrName: (CUtlSymbolLarge)v11->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  else
  {
    hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
    CenterVertIndex = CCoreDispNode::GetCenterVertIndex((CVTFTexture *)this);
    if ( CenterVertIndex != DMELEMENT_HANDLE_INVALID )
    {
      CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      hMakefileOld.m_handle = CenterVertIndex;
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: CenterVertIndex);
      if ( v4 != nullptr && !v4->IsA(this: v4, a2: CDmeDCCMakefile::m_classType) )
        hMakefileOld.m_handle = DMELEMENT_HANDLE_INVALID;
      CDmeElementRefHelper::Ref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
    }
    m_fileId = this->m_fileId;
    g_pDataModel->UnloadFile(this: g_pDataModel, a2: m_fileId);
    pRoot = nullptr;
    v6 = g_pDataModel->__vftable;
    v7 = ((int (__thiscall *)(IDataModel *, DmFileId_t, _DWORD, _DWORD, CDmElement **, int, _DWORD))g_pDataModel->GetFileName)(
           a1: g_pDataModel,
           a2: m_fileId,
           a3: 0,
           a4: 0,
           a5: &pRoot,
           a6: 1,
           a7: 0);
    if ( ((int (__thiscall *)(IDataModel *, int))v6->RestoreFromFile)(a1: g_pDataModel, a2: v7) == -1
      || g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle) == nullptr )
    {
      if ( g_pDataModel != nullptr )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return nullptr;
    }
    else
    {
      *((_BYTE *)&g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle)[1].m_ref + 8) = 0;
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: hMakefileOld.m_handle);
      v9 = ((int (__thiscall *)(CDmElement *))v8->__vftable[1].Resolve)(a1: v8);
      if ( g_pDataModel != nullptr )
        CDmeElementRefHelper::Unref(this: &hMakefileOld, hElement: hMakefileOld.m_handle, handleType: HT_WEAK);
      return (CDmElement *)v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00583CF0
// Name: public: virtual void CDmeDCCMakefile::GetOutputs(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeDCCMakefile::GetOutputs(
        CDmeDCCMakefile *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *fullPaths)
{
  const char *FileName; // eax
  char pFullPath[260]; // [esp+8h] [ebp-31Ch] BYREF
  char pOutputName[260]; // [esp+10Ch] [ebp-218h] BYREF
  char pOutputDir[260]; // [esp+210h] [ebp-114h] BYREF
  CUtlString src; // [esp+314h] [ebp-10h] BYREF

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)fullPaths);
  FileName = CDmeMakefile::GetFileName(this);
  V_FileBase(in: FileName, out: pOutputName, maxlen: 260);
  if ( pOutputName[0] != 0 )
  {
    CDmeMakefile::GetMakefilePath(this, pFullPath: pOutputDir, nBufLen: 260);
    if ( pOutputDir[0] != 0 )
    {
      V_StripTrailingSlash(ppath: pOutputDir);
      V_snprintf(pDest: pFullPath, maxLen: 260, pFormat: "%s\\%s.dmx", pOutputDir, pOutputName);
      CUtlString::CUtlString(this: &src, pString: pFullPath);
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: fullPaths, elem: fullPaths->m_Size, &src);
      src.m_Storage.m_nActualLength = 0;
      if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00584190
// Name: public: virtual bool CDmeSourceDCCFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceDCCFile::IsA(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005841C0
// Name: public: virtual int CDmeSourceDCCFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceDCCFile::GetInheritanceDepth(CDmeSourceDCCFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00584210
// Name: protected: virtual void CDmeSourceDCCFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFile::PerformConstruction(CDmeSourceXSIFile *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00584280
// Name: public: virtual bool CDmeSourceMayaFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaFile::IsA(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005842C0
// Name: public: virtual int CDmeSourceMayaFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaFile::GetInheritanceDepth(CDmeSourceMayaFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00584370
// Name: public: virtual bool CDmeSourceMayaModelFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaModelFile::IsA(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005843B0
// Name: public: virtual int CDmeSourceMayaModelFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaModelFile::GetInheritanceDepth(CDmeSourceMayaModelFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaModelFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00584420
// Name: protected: virtual void CDmeSourceMayaModelFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaModelFile::PerformConstruction(CDmeSourceMayaModelFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005844B0
// Name: public: virtual bool CDmeSourceMayaAnimationFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceMayaAnimationFile::IsA(CDmeSourceMayaAnimationFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005844F0
// Name: public: virtual int CDmeSourceMayaAnimationFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceMayaAnimationFile::GetInheritanceDepth(
        CDmeSourceMayaAnimationFile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceMayaAnimationFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceMayaFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00584560
// Name: protected: virtual void CDmeSourceMayaAnimationFile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceMayaAnimationFile::PerformConstruction(CDmeSourceMayaAnimationFile *this)
{
  CDmAttribute *m_pAttribute; // ecx
  int value; // [esp+4h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeSource::OnConstruction(this);
  CDmeSourceDCCFile::OnConstruction(this);
  m_pAttribute = this->m_ExportType.m_pAttribute;
  value = 1;
  CDmAttribute::SetValue<int>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005845F0
// Name: public: virtual bool CDmeSourceXSIFile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSourceXSIFile::IsA(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00584630
// Name: public: virtual int CDmeSourceXSIFile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSourceXSIFile::GetInheritanceDepth(CDmeSourceXSIFile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSourceXSIFile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeSourceDCCFile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005846E0
// Name: private: virtual char const __near * CDmeDCCMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeDCCMakefile::GetOutputDirectoryID(CDmeDCCMakefile *this)
{
  return "makefiledir:..\\dmx";
}

//------------------------------------------------------------------------------
// Address: 0x005846F0
// Name: public: virtual bool CDmeDCCMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDCCMakefile::IsA(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00584720
// Name: public: virtual int CDmeDCCMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::GetInheritanceDepth(CDmeDCCMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00584770
// Name: protected: virtual int CDmeDCCMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDCCMakefile::AllocatedSize(CDmeMayaAnimationMakefile *this)
{
  return 112;
}

//------------------------------------------------------------------------------
// Address: 0x005847D0
// Name: public: virtual bool CDmeMayaMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaMakefile::IsA(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00584810
// Name: public: virtual int CDmeMayaMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaMakefile::GetInheritanceDepth(CDmeMayaMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00584870
// Name: protected: virtual void CDmeMayaAnimationMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaAnimationMakefile::PerformConstruction(CDmeMayaAnimationMakefile *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeMakefile::OnConstruction(this);
  this->m_bFlushFile = false;
}

//------------------------------------------------------------------------------
// Address: 0x005848E0
// Name: public: virtual bool CDmeXSIMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeXSIMakefile::IsA(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00584920
// Name: public: virtual int CDmeXSIMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeXSIMakefile::GetInheritanceDepth(CDmeXSIMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeXSIMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005849D0
// Name: public: virtual bool CDmeMayaModelMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaModelMakefile::IsA(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00584A10
// Name: public: virtual int CDmeMayaModelMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaModelMakefile::GetInheritanceDepth(CDmeMayaModelMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaModelMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00584AD0
// Name: public: virtual bool CDmeMayaAnimationMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMayaAnimationMakefile::IsA(CDmeMayaAnimationMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00584B10
// Name: public: virtual int CDmeMayaAnimationMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMayaAnimationMakefile::GetInheritanceDepth(
        CDmeMayaAnimationMakefile *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMayaAnimationMakefile::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeMayaMakefile::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDCCMakefile::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00584B80
// Name: protected: virtual void CDmeMayaModelMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMayaModelMakefile::PerformDestruction(CDmeMayaAnimationMakefile *this)
{
  CDmeMakefile::OnDestruction(this);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x006B79C0
// Name: _dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceDCCFile::s_Allocator,
    blockSize: 0x80u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceDCCFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7A20
// Name: _dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaFile::s_Allocator,
    blockSize: 0x80u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7A80
// Name: _dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaModelFile::s_Allocator,
    blockSize: 0x80u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaModelFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7AE0
// Name: _dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceMayaAnimationFile::s_Allocator,
    blockSize: 0x80u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceMayaAnimationFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7B40
// Name: _dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSourceXSIFile::s_Allocator,
    blockSize: 0x80u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSourceXSIFile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7BA0
// Name: _dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDCCMakefile::s_Allocator,
    blockSize: 0x70u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDCCMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7C00
// Name: _dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaMakefile::s_Allocator,
    blockSize: 0x70u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7C60
// Name: _dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaModelMakefile::s_Allocator,
    blockSize: 0x70u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaModelMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7CC0
// Name: _dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMayaAnimationMakefile::s_Allocator,
    blockSize: 0x70u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMayaAnimationMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7D20
// Name: _dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeXSIMakefile::s_Allocator,
    blockSize: 0x70u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeXSIMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BC850
// Name: _dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceDCCFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceDCCFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC860
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC870
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaModelFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaModelFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC880
// Name: _dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceMayaAnimationFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceMayaAnimationFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC890
// Name: _dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSourceXSIFile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSourceXSIFile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC8A0
// Name: _dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDCCMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDCCMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC8B0
// Name: _dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC8C0
// Name: _dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaModelMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaModelMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC8D0
// Name: _dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMayaAnimationMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMayaAnimationMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC8E0
// Name: _dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeXSIMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeXSIMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B79F0
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceDCCFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7A00
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceDCCFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceDCCFile_Helper,
           classname: "DmeSourceDCCFile",
           pFactory: &g_CDmeSourceDCCFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B7A50
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7A60
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaFile_Helper,
           classname: "DmeSourceMayaFile",
           pFactory: &g_CDmeSourceMayaFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B7AB0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaModelFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7AC0
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaModelFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaModelFile_Helper,
           classname: "DmeSourceMayaModelFile",
           pFactory: &g_CDmeSourceMayaModelFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B7B10
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7B20
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceMayaAnimationFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceMayaAnimationFile_Helper,
           classname: "DmeSourceMayaAnimationFile",
           pFactory: &g_CDmeSourceMayaAnimationFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B7B70
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSourceXSIFile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7B80
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSourceXSIFile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSourceXSIFile_Helper,
           classname: "DmeSourceXSIFile",
           pFactory: &g_CDmeSourceXSIFile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B7BD0
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDCCMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7BE0
// Name: _dynamic_initializer_for__g_CDmeDCCMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDCCMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDCCMakefile_Helper,
           classname: "DmeDCCMakefile",
           pFactory: &g_CDmeDCCMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B7C30
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7C40
// Name: _dynamic_initializer_for__g_CDmeMayaMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaMakefile_Helper,
           classname: "DmeMayaMakefile",
           pFactory: &g_CDmeMayaMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B7C90
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaModelMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7CA0
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaModelMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaModelMakefile_Helper,
           classname: "DmeMayaModelMakefile",
           pFactory: &g_CDmeMayaModelMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B7CF0
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7D00
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMayaAnimationMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMayaAnimationMakefile_Helper,
           classname: "DmeMayaAnimationMakefile",
           pFactory: &g_CDmeMayaAnimationMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B7D50
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeXSIMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7D60
// Name: _dynamic_initializer_for__g_CDmeXSIMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeXSIMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeXSIMakefile_Helper,
           classname: "DmeXSIMakefile",
           pFactory: &g_CDmeXSIMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BC8F0
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaFile_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSourceMayaFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC900
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaModelFile_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSourceMayaModelFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC910
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceMayaAnimationFile_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSourceMayaAnimationFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC920
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceXSIFile_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSourceXSIFile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC930
// Name: _dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDCCMakefile_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeDCCMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC940
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaMakefile_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeMayaMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC950
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaModelMakefile_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeMayaModelMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC960
// Name: _dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMayaAnimationMakefile_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeMayaAnimationMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC970
// Name: _dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeXSIMakefile_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeXSIMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC980
// Name: _dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSourceDCCFile_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSourceDCCFile_Factory.m_CallBackList);
}

} // namespace vmap
