// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmemakefileutils.cpp
// Functions: 35
// ============================================================

#include "movieobjects\dmemakefileutils.h"

//------------------------------------------------------------------------------
// Address: 0x0051FBD0
// Name: class IDmeMakefileUtils __near * GetDefaultDmeMakefileUtils(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMakefileUtils *__cdecl GetDefaultDmeMakefileUtils()
{
  return &s_MakefileUtils;
}

//------------------------------------------------------------------------------
// Address: 0x0051FBE0
// Name: public: virtual void __near * CDmeMakefileUtils::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeMakefileUtils *__thiscall CDmeMakefileUtils::QueryInterface(CDmeMakefileUtils *this, const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmeMakeFileUtils001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0051FC10
// Name: public: virtual enum InitReturnVal_t CDmeMakefileUtils::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefileUtils::Init(CDmeMakefileUtils *this)
{
  this->InitializeFuncMaps(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0051FC20
// Name: private: class CCompileFuncAdapterBase __near * CDmeMakefileUtils::DetermineCompileAdapter(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
CCompileFuncAdapterBase *__thiscall CDmeMakefileUtils::DetermineCompileAdapter(
        CDmeMakefileUtils *this,
        CDmElement *pElement)
{
  int v2; // edi
  CDmeMakefileUtils::CompileFuncTree_t *v3; // eax
  CCompileFuncAdapterBase *m_pFirstAdapter; // esi
  int v5; // eax
  CCompileFuncAdapterBase *pBestAdapter; // [esp+Ch] [ebp-8h]
  CDmeMakefileUtils::CompileFuncTree_t *pTree; // [esp+10h] [ebp-4h]

  v2 = -1;
  pBestAdapter = nullptr;
  v3 = this->GetCompileTree(this);
  pTree = v3;
  if ( v3 == nullptr )
    return pBestAdapter;
  while ( 1 )
  {
    m_pFirstAdapter = v3->m_pFirstAdapter;
    if ( v3->m_pFirstAdapter != nullptr )
      break;
LABEL_12:
    pTree = v3->m_pBaseAdapterTree;
    if ( pTree == nullptr )
      return pBestAdapter;
    v3 = v3->m_pBaseAdapterTree;
  }
  while ( 1 )
  {
    v5 = ((int (__thiscall *)(_DWORD, _DWORD))pElement->GetInheritanceDepth)(
           a1: pElement,
           a2: (CUtlSymbolLarge)m_pFirstAdapter->m_ElementType.u.m_Id);
    if ( v5 >= 0 )
      break;
LABEL_10:
    m_pFirstAdapter = m_pFirstAdapter->m_pNext;
    if ( m_pFirstAdapter == nullptr )
    {
      v3 = pTree;
      goto LABEL_12;
    }
  }
  if ( v5 != 0 )
  {
    if ( v2 < 0 || v5 < v2 )
    {
      v2 = v5;
      pBestAdapter = m_pFirstAdapter;
    }
    goto LABEL_10;
  }
  return m_pFirstAdapter;
}

//------------------------------------------------------------------------------
// Address: 0x0051FCA0
// Name: private: class COpenEditorFuncAdapterBase __near * CDmeMakefileUtils::DetermineOpenEditorAdapter(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
COpenEditorFuncAdapterBase *__thiscall CDmeMakefileUtils::DetermineOpenEditorAdapter(
        CDmeMakefileUtils *this,
        CDmElement *pElement)
{
  int v2; // edi
  CDmeMakefileUtils::OpenEditorFuncTree_t *v3; // eax
  COpenEditorFuncAdapterBase *m_pFirstAdapter; // esi
  int v5; // eax
  COpenEditorFuncAdapterBase *pBestAdapter; // [esp+Ch] [ebp-8h]
  CDmeMakefileUtils::OpenEditorFuncTree_t *pTree; // [esp+10h] [ebp-4h]

  v2 = -1;
  pBestAdapter = nullptr;
  v3 = this->GetOpenEditorTree(this);
  pTree = v3;
  if ( v3 == nullptr )
    return pBestAdapter;
  while ( 1 )
  {
    m_pFirstAdapter = v3->m_pFirstAdapter;
    if ( v3->m_pFirstAdapter != nullptr )
      break;
LABEL_12:
    pTree = v3->m_pBaseAdapterTree;
    if ( pTree == nullptr )
      return pBestAdapter;
    v3 = v3->m_pBaseAdapterTree;
  }
  while ( 1 )
  {
    v5 = ((int (__thiscall *)(_DWORD, _DWORD))pElement->GetInheritanceDepth)(
           a1: pElement,
           a2: (CUtlSymbolLarge)m_pFirstAdapter->m_ElementType.u.m_Id);
    if ( v5 >= 0 )
      break;
LABEL_10:
    m_pFirstAdapter = m_pFirstAdapter->m_pNext;
    if ( m_pFirstAdapter == nullptr )
    {
      v3 = pTree;
      goto LABEL_12;
    }
  }
  if ( v5 != 0 )
  {
    if ( v2 < 0 || v5 < v2 )
    {
      v2 = v5;
      pBestAdapter = m_pFirstAdapter;
    }
    goto LABEL_10;
  }
  return m_pFirstAdapter;
}

//------------------------------------------------------------------------------
// Address: 0x0051FD20
// Name: public: virtual void CDmeMakefileUtils::PerformOpenEditor(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefileUtils::PerformOpenEditor(CDmeMakefileUtils *this, CDmElement *pElement)
{
  COpenEditorFuncAdapterBase *v2; // eax

  v2 = CDmeMakefileUtils::DetermineOpenEditorAdapter(this, pElement);
  if ( v2 != nullptr )
    v2->OpenEditor(this: v2, a2: pElement);
}

//------------------------------------------------------------------------------
// Address: 0x0051FD40
// Name: public: virtual bool CDmeMakefileUtils::IsCurrentlyCompiling(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeMakefileUtils::IsCurrentlyCompiling(CDmeMakefileUtils *this)
{
  return this->m_CompilationStep != NOT_COMPILING;
}

//------------------------------------------------------------------------------
// Address: 0x0051FD50
// Name: public: virtual int CDmeMakefileUtils::GetCompileOutputSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefileUtils::GetCompileOutputSize(CDmeMakefileUtils *this)
{
  IPipeRead *v2; // eax

  if ( this->m_hCompileProcess == nullptr )
    return 0;
  v2 = this->m_hCompileProcess->GetStdout(this: this->m_hCompileProcess);
  return v2->GetNumBytesAvailable(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0051FD70
// Name: public: virtual void CCompileFuncAdapter<class CDmeMakefileUtils,class CDmElement>::InitializeAdapter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCompileFuncAdapter<CDmeMakefileUtils,CDmElement>::InitializeAdapter(
        CCompileFuncAdapter<CDmeMakefileUtils,CDmElement> *this)
{
  this->m_ElementType = CDmElement::m_classType;
  if ( this->m_pNext != nullptr )
    this->m_pNext->InitializeAdapter(this: this->m_pNext);
}

//------------------------------------------------------------------------------
// Address: 0x0051FD90
// Name: public: virtual void CCompileFuncAdapter<class CDmeMakefileUtils,class CDmeMakefile>::InitializeAdapter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCompileFuncAdapter<CDmeMakefileUtils,CDmeMakefile>::InitializeAdapter(
        CCompileFuncAdapter<CDmeMakefileUtils,CDmeMakefile> *this)
{
  this->m_ElementType = CDmeMakefile::m_classType;
  if ( this->m_pNext != nullptr )
    this->m_pNext->InitializeAdapter(this: this->m_pNext);
}

//------------------------------------------------------------------------------
// Address: 0x0051FDB0
// Name: public: virtual void CCompileFuncAdapter<class CDmeMakefileUtils,class CDmeMDLMakefile>::InitializeAdapter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCompileFuncAdapter<CDmeMakefileUtils,CDmeMDLMakefile>::InitializeAdapter(
        CCompileFuncAdapter<CDmeMakefileUtils,CDmeMDLMakefile> *this)
{
  this->m_ElementType = CDmeMDLMakefile::m_classType;
  if ( this->m_pNext != nullptr )
    this->m_pNext->InitializeAdapter(this: this->m_pNext);
}

//------------------------------------------------------------------------------
// Address: 0x0051FDD0
// Name: public: virtual void CCompileFuncAdapter<class CDmeMakefileUtils,class CDmeMayaMakefile>::InitializeAdapter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCompileFuncAdapter<CDmeMakefileUtils,CDmeMayaMakefile>::InitializeAdapter(
        CCompileFuncAdapter<CDmeMakefileUtils,CDmeMayaMakefile> *this)
{
  this->m_ElementType = CDmeMayaMakefile::m_classType;
  if ( this->m_pNext != nullptr )
    this->m_pNext->InitializeAdapter(this: this->m_pNext);
}

//------------------------------------------------------------------------------
// Address: 0x0051FDF0
// Name: public: virtual void COpenEditorFuncAdapter<class CDmeMakefileUtils,class CDmeSourceMayaFile>::InitializeAdapter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COpenEditorFuncAdapter<CDmeMakefileUtils,CDmeSourceMayaFile>::InitializeAdapter(
        COpenEditorFuncAdapter<CDmeMakefileUtils,CDmeSourceMayaFile> *this)
{
  this->m_ElementType = CDmeSourceMayaFile::m_classType;
  if ( this->m_pNext != nullptr )
    this->m_pNext->InitializeAdapter(this: this->m_pNext);
}

//------------------------------------------------------------------------------
// Address: 0x0051FEC0
// Name: public: virtual bool CCompileFuncAdapter<class CDmeMakefileUtils,class CDmElement>::PerformCompilationStep(class CDmElement __near *,enum CompilationStep_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCompileFuncAdapter<CDmeMakefileUtils,CDmElement>::PerformCompilationStep(
        CCompileFuncAdapter<CDmeMakefileUtils,CDmElement> *this,
        CDmElement *pElement,
        CompilationStep_t step)
{
  return pElement != nullptr
      && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
           a1: pElement,
           a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id);
}

//------------------------------------------------------------------------------
// Address: 0x0051FF80
// Name: private: bool CDmeMakefileUtils::PerformCompilationStep(enum CompilationStep_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefileUtils::PerformCompilationStep(CDmeMakefileUtils *this, CompilationStep_t step)
{
  int v3; // edi
  CDmeMakefileUtils::CompileInfo_t *v4; // esi
  int v5; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  this->m_CompilationStep = step;
  v3 = 0;
  nCount = this->m_CompileTasks.m_Size;
  if ( nCount <= 0 )
    return 1;
  while ( 1 )
  {
    v4 = &this->m_CompileTasks.m_Memory.m_pMemory[v3];
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: v4->m_hElement.m_handle) != 0 )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: v4->m_hElement.m_handle);
      if ( !v4->m_pAdapter->PerformCompilationStep(this: v4->m_pAdapter, a2: (CDmElement *)v5, a3: step) )
        break;
    }
    if ( ++v3 >= nCount )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00520000
// Name: protected: void CDmeMakefileUtils::OpenEditor(class CDmeSourceMayaFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefileUtils::OpenEditor(CDmeMakefileUtils *this, CDmeSourceMayaFile *pDmeSourceDCCFile)
{
  CUtlSymbolLarge *v2; // eax
  CDmeMayaMakefile *Referring; // eax
  char pMayaCommand[1024]; // [esp+4h] [ebp-508h] BYREF
  char pSourcePath[260]; // [esp+404h] [ebp-108h] BYREF
  _BYTE v6[4]; // [esp+508h] [ebp-4h] BYREF

  v2 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                            a1: g_pDataModel.u,
                            a2: v6,
                            a3: "sources");
  Referring = FindReferringElement<CDmeMayaMakefile>(
                pElement: pDmeSourceDCCFile,
                symAttrName: (CUtlSymbolLarge)v2->u.m_Id,
                bMustBeInSameFile: true,
                depth: TD_ALL);
  if ( Referring != nullptr )
  {
    CDmeMakefile::GetSourceFullPath(this: Referring, pSource: pDmeSourceDCCFile, pFullPath: pSourcePath, nBufLen: 260);
    V_FixSlashes(pname: pSourcePath, separator: 47);
    V_snprintf(pDest: pMayaCommand, maxLen: 1024, pFormat: "maya.exe -file \"%s\"", pSourcePath);
    g_pProcessUtils->StartProcess_2(this: g_pProcessUtils, a2: pMayaCommand, a3: 1, a4: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005200A0
// Name: public: virtual void COpenEditorFuncAdapter<class CDmeMakefileUtils,class CDmeSourceMayaFile>::OpenEditor(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COpenEditorFuncAdapter<CDmeMakefileUtils,CDmeSourceMayaFile>::OpenEditor(
        COpenEditorFuncAdapter<CDmeMakefileUtils,CDmeSourceMayaFile> *this,
        CDmeSourceMayaFile *pElement)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeSourceMayaFile::m_classType.u.m_Id) )
  {
    CDmeMakefileUtils::OpenEditor(this: CDmeMakefileUtils::m_pSingleton, pDmeSourceDCCFile: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520200
// Name: private: void CDmeMakefileUtils::StartNextCompileTask(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefileUtils::StartNextCompileTask(CDmeMakefileUtils *this)
{
  int v2; // eax
  CDmeMakefileUtils::CompileInfo_t *m_pMemory; // ecx
  CDmeMakefileUtils::CompileInfo_t *v4; // edi
  int v5; // eax

  v2 = ++this->m_nCurrentCompileTask;
  if ( v2 == this->m_CompileTasks.m_Size )
  {
    CDmeMakefileUtils::PerformCompilationStep(this, step: AFTER_COMPILATION_SUCCEEDED);
    this->m_nCurrentCompileTask = -1;
    CUtlVector<CDmeMakefileUtils::CompileInfo_t,CUtlMemory<CDmeMakefileUtils::CompileInfo_t,int>>::RemoveAll(this: &this->m_CompileTasks);
  }
  else
  {
    m_pMemory = this->m_CompileTasks.m_Memory.m_pMemory;
    this->m_hCompileProcess = nullptr;
    v4 = &m_pMemory[v2];
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: v4->m_hElement.m_handle);
    if ( !v4->m_pAdapter->PerformCompilationStep(this: v4->m_pAdapter, a2: (CDmElement *)v5, a3: PERFORMING_COMPILATION)
      || this->m_hCompileProcess == nullptr )
    {
      this->AbortCurrentCompilation(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520270
// Name: public: virtual void CDmeMakefileUtils::AbortCurrentCompilation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefileUtils::AbortCurrentCompilation(CDmeMakefileUtils *this)
{
  IProcess *m_hCompileProcess; // ecx

  m_hCompileProcess = this->m_hCompileProcess;
  if ( m_hCompileProcess != nullptr )
  {
    m_hCompileProcess->Abort(this: m_hCompileProcess);
    this->m_hCompileProcess->Release(this: this->m_hCompileProcess);
    this->m_hCompileProcess = nullptr;
  }
  if ( this->IsCurrentlyCompiling(this) )
  {
    CDmeMakefileUtils::PerformCompilationStep(this, step: AFTER_COMPILATION_FAILED);
    this->m_nCurrentCompileTask = -1;
    CUtlVector<CDmeMakefileUtils::CompileInfo_t,CUtlMemory<CDmeMakefileUtils::CompileInfo_t,int>>::RemoveAll(this: &this->m_CompileTasks);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005202C0
// Name: public: virtual enum CompilationState_t CDmeMakefileUtils::UpdateCompilation(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefileUtils::UpdateCompilation(CDmeMakefileUtils *this, char *pOutputBuf, int nBufLen)
{
  IPipeRead *v5; // eax
  const char *v6; // eax
  int v7; // eax
  IProcess *m_hCompileProcess; // ecx
  bool v9; // bl
  CompilationStep_t m_CompilationStep; // eax
  CUtlString sOutput; // [esp+4h] [ebp-10h] BYREF

  switch ( this->m_CompilationStep )
  {
    case BUILDING_STANDARD_DEPENDENCIES:
    case BUILDING_ALL_DEPENDENCIES:
    case BEFORE_COMPILATION:
      return 1;
    case AFTER_COMPILATION_FAILED:
      this->m_CompilationStep = NOT_COMPILING;
      return 2;
    case AFTER_COMPILATION_SUCCEEDED:
      this->m_CompilationStep = NOT_COMPILING;
      return 0;
    default:
      if ( this->m_hCompileProcess != nullptr )
      {
        if ( nBufLen > 0 )
        {
          CUtlString::CUtlString(this: &sOutput);
          v5 = this->m_hCompileProcess->GetStdout(this: this->m_hCompileProcess);
          v5->ReadAvailable_2(this: v5, a2: &sOutput, a3: 0x7FFFFFFF);
          v6 = CUtlString::operator char const *(this: &sOutput);
          V_strncpy(pDest: pOutputBuf, pSrc: v6, maxLen: nBufLen);
          V_TranslateLineFeedsToUnix(pStr: pOutputBuf);
          sOutput.m_Storage.m_nActualLength = 0;
          if ( sOutput.m_Storage.m_Memory.m_nGrowSize >= 0 && sOutput.m_Storage.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sOutput.m_Storage.m_Memory.m_pMemory);
        }
        if ( this->m_hCompileProcess->IsComplete(this: this->m_hCompileProcess) )
        {
          v7 = this->m_hCompileProcess->GetExitCode(this: this->m_hCompileProcess);
          m_hCompileProcess = this->m_hCompileProcess;
          this->m_nExitCode = v7;
          v9 = v7 == 0;
          m_hCompileProcess->Release(this: m_hCompileProcess);
          this->m_hCompileProcess = nullptr;
          if ( v9 )
          {
            CDmeMakefileUtils::StartNextCompileTask(this);
            m_CompilationStep = this->m_CompilationStep;
            if ( m_CompilationStep != PERFORMING_COMPILATION )
            {
              this->m_CompilationStep = NOT_COMPILING;
              return m_CompilationStep != AFTER_COMPILATION_SUCCEEDED ? 2 : 0;
            }
          }
          else
          {
            this->AbortCurrentCompilation(this);
          }
        }
        return 1;
      }
      if ( nBufLen > 0 )
        *pOutputBuf = 0;
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520420
// Name: public: virtual void CTier2AppSystem<class IDmeMakefileUtils,0>::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2AppSystem<IDmeMakefileUtils,0>::Shutdown(CTier2AppSystem<IDmeMakefileUtils,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x00520430
// Name: protected: virtual struct CDmeMakefileUtils::CompileFuncTree_t __near * CDmeMakefileUtils::GetCompileTree(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMakefileUtils::CompileFuncTree_t *__thiscall CDmeMakefileUtils::GetCompileTree(CDmeMakefileUtils *this)
{
  return &CDmeMakefileUtils::m_CompileFuncTree;
}

//------------------------------------------------------------------------------
// Address: 0x00520440
// Name: protected: virtual struct CDmeMakefileUtils::OpenEditorFuncTree_t __near * CDmeMakefileUtils::GetOpenEditorTree(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMakefileUtils::OpenEditorFuncTree_t *__thiscall CDmeMakefileUtils::GetOpenEditorTree(CDmeMakefileUtils *this)
{
  return &CDmeMakefileUtils::m_OpenEditorFuncTree;
}

//------------------------------------------------------------------------------
// Address: 0x00520450
// Name: protected: virtual void CDmeMakefileUtils::InitializeFuncMaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefileUtils::InitializeFuncMaps(CDmeMakefileUtils *this)
{
  CDmeMakefileUtils::m_pSingleton = this;
  CDmeMakefileUtils::m_CompileFuncTree.m_pBaseAdapterTree = nullptr;
  CDmeMakefileUtils::m_CompileFuncTree.m_pFirstAdapter->InitializeAdapter(this: CDmeMakefileUtils::m_CompileFuncTree.m_pFirstAdapter);
  CDmeMakefileUtils::m_OpenEditorFuncTree.m_pBaseAdapterTree = nullptr;
  CDmeMakefileUtils::m_OpenEditorFuncTree.m_pFirstAdapter->InitializeAdapter(this: CDmeMakefileUtils::m_OpenEditorFuncTree.m_pFirstAdapter);
}

//------------------------------------------------------------------------------
// Address: 0x005204A0
// Name: public: virtual bool CTier3AppSystem<class IDmeMakefileUtils,0>::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTier3AppSystem<IDmeMakefileUtils,0>::Connect(
        CTier3AppSystem<IDmeMakefileUtils,0> *this,
        void *(__cdecl *factory)(const char *, int *))
{
  vgui::PropertyPage *v2; // ecx
  void *(__cdecl *v4)(const char *, int *); // [esp+0h] [ebp-8h] BYREF
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+4h] [ebp-4h] BYREF

  v4 = factory;
  pFactoryList = factory;
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConnectTier2Libraries(pFactoryList: &v4, nFactoryCount: 1);
  CDmeFXClip::OnDestruction(this: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005204E0
// Name: public: virtual void CTier3AppSystem<class IDmeMakefileUtils,0>::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier3AppSystem<IDmeMakefileUtils,0>::Disconnect(CTier3AppSystem<IDmeMakefileUtils,0> *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x005204F0
// Name: public: virtual void CDmeMakefileUtils::PerformCompile(class CDmElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefileUtils::PerformCompile(
        CDmeMakefileUtils *this,
        CDmElement *pElement,
        bool bBuildAllDependencies)
{
  CCompileFuncAdapterBase *v4; // eax
  int v5; // eax
  CDmeMakefileUtils::CompileInfo_t *v6; // ebx
  DmElementHandle_t BufferType; // eax
  CCompileFuncAdapterBase *pAdapter; // [esp+8h] [ebp-4h]
  int bBuildAllDependenciesa; // [esp+18h] [ebp+Ch]

  if ( this->IsCurrentlyCompiling(this) )
    this->AbortCurrentCompilation(this);
  v4 = CDmeMakefileUtils::DetermineCompileAdapter(this, pElement);
  pAdapter = v4;
  if ( v4 != nullptr )
  {
    this->m_CompilationStep = bBuildAllDependencies;
    if ( v4->PerformCompilationStep(this: v4, a2: pElement, a3: (CompilationStep_t)bBuildAllDependencies)
      && ((v5 = CUtlVector<CDmeMakefileUtils::CompileInfo_t,CUtlMemory<CDmeMakefileUtils::CompileInfo_t,int>>::InsertBefore(
                  this: &this->m_CompileTasks,
                  elem: this->m_CompileTasks.m_Size),
           v6 = &this->m_CompileTasks.m_Memory.m_pMemory[v5],
           bBuildAllDependenciesa = v5 * 8,
           pElement == nullptr)
        ? (BufferType = DMELEMENT_HANDLE_INVALID)
        : (BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pElement)),
          CDmeHandle<CDmElement,0>::Set(this: &v6->m_hElement, h: BufferType),
          *(CCompileFuncAdapterBase **)((char *)&this->m_CompileTasks.m_Memory.m_pMemory->m_pAdapter
                                      + bBuildAllDependenciesa) = pAdapter,
          CDmeMakefileUtils::PerformCompilationStep(this, step: BEFORE_COMPILATION) != 0) )
    {
      this->m_CompilationStep = PERFORMING_COMPILATION;
      CDmeMakefileUtils::StartNextCompileTask(this);
    }
    else
    {
      this->AbortCurrentCompilation(this);
    }
  }
  else
  {
    this->m_CompilationStep = AFTER_COMPILATION_FAILED;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520820
// Name: public: CDmeMakefileUtils::CDmeMakefileUtils(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMakefileUtils *__thiscall CDmeMakefileUtils::CDmeMakefileUtils(CDmeMakefileUtils *this)
{
  CDmeMakefileUtils *result; // eax
  CCompileFuncAdapter<CDmeMakefileUtils,CDmElement> *p_m_CDmElementCompileAdapter; // ecx

  result = this;
  this->__vftable = (CDmeMakefileUtils_vtbl *)&CDmeMakefileUtils::`vftable';
  this->m_CDmElementCompileAdapter.m_ElementType.u.m_Id = -1;
  this->m_CDmElementCompileAdapter.__vftable = (CCompileFuncAdapter<CDmeMakefileUtils,CDmElement>_vtbl *)&CCompileFuncAdapter<CDmeMakefileUtils,CDmElement>::`vftable';
  p_m_CDmElementCompileAdapter = &this->m_CDmElementCompileAdapter;
  p_m_CDmElementCompileAdapter->m_pNext = CDmeMakefileUtils::m_CompileFuncTree.m_pFirstAdapter;
  CDmeMakefileUtils::m_CompileFuncTree.m_pFirstAdapter = p_m_CDmElementCompileAdapter;
  result->m_CDmeMakefileCompileAdapter.m_ElementType.u.m_Id = -1;
  result->m_CDmeMakefileCompileAdapter.__vftable = (CCompileFuncAdapter<CDmeMakefileUtils,CDmeMakefile>_vtbl *)&CCompileFuncAdapter<CDmeMakefileUtils,CDmeMakefile>::`vftable';
  result->m_CDmeMakefileCompileAdapter.m_pNext = CDmeMakefileUtils::m_CompileFuncTree.m_pFirstAdapter;
  CDmeMakefileUtils::m_CompileFuncTree.m_pFirstAdapter = &result->m_CDmeMakefileCompileAdapter;
  result->m_CDmeMDLMakefileCompileAdapter.m_ElementType.u.m_Id = -1;
  result->m_CDmeMDLMakefileCompileAdapter.__vftable = (CCompileFuncAdapter<CDmeMakefileUtils,CDmeMDLMakefile>_vtbl *)&CCompileFuncAdapter<CDmeMakefileUtils,CDmeMDLMakefile>::`vftable';
  result->m_CDmeMDLMakefileCompileAdapter.m_pNext = CDmeMakefileUtils::m_CompileFuncTree.m_pFirstAdapter;
  CDmeMakefileUtils::m_CompileFuncTree.m_pFirstAdapter = &result->m_CDmeMDLMakefileCompileAdapter;
  result->m_CDmeMayaMakefileCompileAdapter.m_ElementType.u.m_Id = -1;
  result->m_CDmeMayaMakefileCompileAdapter.__vftable = (CCompileFuncAdapter<CDmeMakefileUtils,CDmeMayaMakefile>_vtbl *)&CCompileFuncAdapter<CDmeMakefileUtils,CDmeMayaMakefile>::`vftable';
  result->m_CDmeMayaMakefileCompileAdapter.m_pNext = CDmeMakefileUtils::m_CompileFuncTree.m_pFirstAdapter;
  CDmeMakefileUtils::m_CompileFuncTree.m_pFirstAdapter = &result->m_CDmeMayaMakefileCompileAdapter;
  result->m_CDmeSourceMayaFileOpenEditorAdapter.m_ElementType.u.m_Id = -1;
  result->m_CDmeSourceMayaFileOpenEditorAdapter.__vftable = (COpenEditorFuncAdapter<CDmeMakefileUtils,CDmeSourceMayaFile>_vtbl *)&COpenEditorFuncAdapter<CDmeMakefileUtils,CDmeSourceMayaFile>::`vftable';
  result->m_CDmeSourceMayaFileOpenEditorAdapter.m_pNext = CDmeMakefileUtils::m_OpenEditorFuncTree.m_pFirstAdapter;
  CDmeMakefileUtils::m_OpenEditorFuncTree.m_pFirstAdapter = &result->m_CDmeSourceMayaFileOpenEditorAdapter;
  result->m_CompileTasks.m_Memory.m_pMemory = nullptr;
  result->m_CompileTasks.m_Memory.m_nAllocationCount = 0;
  result->m_CompileTasks.m_Memory.m_nGrowSize = 0;
  result->m_CompileTasks.m_Size = 0;
  result->m_CompileTasks.m_pElements = nullptr;
  result->m_CompilationStep = NOT_COMPILING;
  result->m_hCompileProcess = nullptr;
  result->m_nCurrentCompileTask = -1;
  result->m_nExitCode = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005208E0
// Name: private: bool CDmeMakefileUtils::AddCompileDependencies(class CDmeMakefile __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefileUtils::AddCompileDependencies(
        CDmeMakefileUtils *this,
        CDmeTransform *pMakefile,
        bool bBuildAllDependencies)
{
  CDmeMakefile *v3; // esi
  int v5; // ebx
  CUtlString *v6; // eax
  CDmeSource *Source; // eax
  CDmeMakefile *DependentMakefile; // esi
  IBaseFileSystem_vtbl *v9; // edi
  const char *v10; // eax
  CDmeMakefileUtils *v11; // edi
  CCompileFuncAdapterBase *v12; // ebx
  CUtlVector<CDmeMakefileUtils::CompileInfo_t,CUtlMemory<CDmeMakefileUtils::CompileInfo_t,int> > *p_m_CompileTasks; // esi
  int v14; // eax
  CDmeMakefileUtils::CompileInfo_t *m_pMemory; // edi
  CDmeHandle<CDmElement,0> *p_m_hElement; // edi
  DmElementHandle_t BufferType; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > outputs; // [esp+8h] [ebp-28h] BYREF
  int nCount; // [esp+1Ch] [ebp-14h]
  int v20; // [esp+20h] [ebp-10h]
  CDmeMakefile *pDependentMakefile; // [esp+24h] [ebp-Ch]
  CDmeMakefileUtils *v22; // [esp+28h] [ebp-8h]
  int i; // [esp+2Ch] [ebp-4h]

  v3 = (CDmeMakefile *)pMakefile;
  v22 = this;
  if ( pMakefile == nullptr )
    return 1;
  memset(&outputs, 0, sizeof(outputs));
  v5 = 0;
  nCount = (int)CDmeTrack::GetClipCount(this: pMakefile);
  i = 0;
  if ( nCount > 0 )
  {
    while ( 1 )
    {
      Source = CDmeMakefile::GetSource(this: v3, nIndex: v5);
      if ( Source != nullptr )
      {
        DependentMakefile = CDmeSource::GetDependentMakefile(this: Source);
        pDependentMakefile = DependentMakefile;
        if ( DependentMakefile != nullptr )
        {
          if ( bBuildAllDependencies
            || (DependentMakefile->GetOutputs(this: DependentMakefile, a2: &outputs), outputs.m_Size > 0)
            && (v9 = g_pFullFileSystem->IBaseFileSystem::__vftable,
                v10 = CUtlString::operator char const *(this: outputs.m_Memory.m_pMemory),
                v9->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v10, a3: nullptr)) )
          {
            v11 = v22;
            v12 = CDmeMakefileUtils::DetermineCompileAdapter(this: v22, pElement: DependentMakefile);
            if ( v12 != nullptr
              && !v12->PerformCompilationStep(
                    this: v12,
                    a2: DependentMakefile,
                    a3: (CompilationStep_t)bBuildAllDependencies) )
            {
              CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: &outputs);
              return 0;
            }
            p_m_CompileTasks = &v11->m_CompileTasks;
            v14 = CUtlVector<CDmeMakefileUtils::CompileInfo_t,CUtlMemory<CDmeMakefileUtils::CompileInfo_t,int>>::InsertBefore(
                    this: &v11->m_CompileTasks,
                    elem: v11->m_CompileTasks.m_Size);
            m_pMemory = v11->m_CompileTasks.m_Memory.m_pMemory;
            v20 = 8 * v14;
            p_m_hElement = &m_pMemory[v14].m_hElement;
            BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pDependentMakefile);
            CDmeHandle<CDmElement,0>::Set(this: p_m_hElement, h: BufferType);
            p_m_CompileTasks->m_Memory.m_pMemory[v20 / 8u].m_pAdapter = v12;
            v5 = i;
          }
        }
      }
      i = ++v5;
      if ( v5 >= nCount )
        break;
      v3 = (CDmeMakefile *)pMakefile;
    }
  }
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &outputs);
  v6 = outputs.m_Memory.m_pMemory;
  if ( outputs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( outputs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outputs.m_Memory.m_pMemory);
      v6 = nullptr;
      outputs.m_Memory.m_pMemory = nullptr;
    }
    outputs.m_Memory.m_nAllocationCount = 0;
  }
  outputs.m_pElements = v6;
  if ( outputs.m_Memory.m_nGrowSize >= 0 && v6 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00520A70
// Name: protected: bool CDmeMakefileUtils::PerformCompilationStep(class CDmeMDLMakefile __near *,enum CompilationStep_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefileUtils::PerformCompilationStep(
        CDmeMakefileUtils *this,
        CDmeMDLMakefile *pMakeFile,
        CompilationStep_t step)
{
  char result; // al
  const char *FileName; // eax
  IProcess *v6; // eax
  char pStudioMDLCmd[260]; // [esp+4h] [ebp-208h] BYREF
  char pBinDirectory[260]; // [esp+108h] [ebp-104h] BYREF

  if ( step == PERFORMING_COMPILATION )
  {
    GetModSubdirectory(pSubDir: "..\\bin", pBuf: pBinDirectory, nBufLen: 260);
    V_RemoveDotSlashes(pFilename: pBinDirectory, separator: 92);
    FileName = CDmeMakefile::GetFileName(this: pMakeFile);
    V_snprintf(pDest: pStudioMDLCmd, maxLen: 260, pFormat: "%s\\studiomdl.exe %s", pBinDirectory, FileName);
    v6 = g_pProcessUtils->StartProcess_2(this: g_pProcessUtils, a2: pStudioMDLCmd, a3: 1, a4: 0);
    this->m_hCompileProcess = v6;
    if ( v6 == nullptr )
      this->m_CompilationStep = AFTER_COMPILATION_FAILED;
    return 1;
  }
  else
  {
    switch ( step )
    {
      case BUILDING_STANDARD_DEPENDENCIES:
        result = CDmeMakefileUtils::AddCompileDependencies(
                   this,
                   pMakefile: (CDmeTransform *)pMakeFile,
                   bBuildAllDependencies: false);
        break;
      case BUILDING_ALL_DEPENDENCIES:
        result = CDmeMakefileUtils::AddCompileDependencies(
                   this,
                   pMakefile: (CDmeTransform *)pMakeFile,
                   bBuildAllDependencies: true);
        break;
      case BEFORE_COMPILATION:
        CDmeMakefile::PreCompile(this: pMakeFile);
        result = 1;
        break;
      case AFTER_COMPILATION_SUCCEEDED:
        CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)pMakeFile);
        result = 1;
        break;
      default:
        return 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00520B80
// Name: protected: bool CDmeMakefileUtils::PerformCompilationStep(class CDmeMayaMakefile __near *,enum CompilationStep_t)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CDmeMakefileUtils::PerformCompilationStep@<al>(
        CDmeMakefileUtils *this@<ecx>,
        int a2@<esi>,
        CDmeMayaMakefile *pMakeFile,
        CompilationStep_t step)
{
  char result; // al
  int v5; // edi
  int v6; // esi
  const char *rhs; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *FileName; // eax
  int v12; // ebx
  const char *v13; // eax
  const char *v14; // eax
  int v15; // eax
  CDmeMakefileUtils *v16; // ecx
  char pMayaCommand[1024]; // [esp+18h] [ebp-6B0h] BYREF
  char pFileName[260]; // [esp+418h] [ebp-2B0h] BYREF
  char pSourcePath[260]; // [esp+51Ch] [ebp-1ACh] BYREF
  char pObjectId[128]; // [esp+620h] [ebp-A8h] BYREF
  CDmeMakefileUtils *v21; // [esp+6A0h] [ebp-28h]
  CUtlVector<CDmeHandle<CDmeSourceMayaFile,0>,CUtlMemory<CDmeHandle<CDmeSourceMayaFile,0>,int> > sources; // [esp+6A4h] [ebp-24h] BYREF
  CUtlString mayaCommand; // [esp+6B8h] [ebp-10h] BYREF

  v21 = this;
  if ( step == PERFORMING_COMPILATION )
  {
    CUtlString::CUtlString(this: &mayaCommand);
    CUtlString::operator=(this: &mayaCommand, src: "vsDmxIO -export");
    v5 = 0;
    memset(&sources, 0, sizeof(sources));
    CDmeMakefile::GetSources<CDmeSourceMayaFile>(this: pMakeFile, &sources);
    if ( sources.m_Size != 0 )
    {
      v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
             a1: g_pDataModel.u,
             a2: sources.m_Memory.m_pMemory->m_handle,
             a3: a2);
      CUtlString::operator+=(this: &mayaCommand, rhs: " -selection");
      UniqueIdToString(id: &pMakeFile->m_Id, pBuf: pObjectId, nMaxLen: 128);
      CUtlString::operator+=(this: &mayaCommand, rhs: " -makefileObjectId \\\"");
      CUtlString::operator+=(this: &mayaCommand, rhs: pObjectId);
      CUtlString::operator+=(this: &mayaCommand, rhs: "\\\"");
      CUtlString::operator+=(this: &mayaCommand, rhs: " -");
      rhs = *(const char **)(*(_DWORD *)(v6 + 100) + 20);
      if ( rhs == (const char *)-1 )
        rhs = defaultValue;
      CUtlString::operator+=(this: &mayaCommand, rhs);
      if ( *(_DWORD *)(v6 + 96) == 1 )
      {
        CUtlString::operator+=(this: &mayaCommand, rhs: " skeletalAnimation");
        CUtlString::operator+=(this: &mayaCommand, rhs: " -");
        v8 = *(const char **)(*(_DWORD *)(v6 + 108) + 20);
        if ( v8 == (const char *)-1 )
          v8 = defaultValue;
        CUtlString::operator+=(this: &mayaCommand, rhs: v8);
        CUtlString::operator+=(this: &mayaCommand, rhs: " ");
        CUtlString::operator+=(this: &mayaCommand, rhs: *(float *)(v6 + 104));
        CUtlString::operator+=(this: &mayaCommand, rhs: " -");
        v9 = *(const char **)(*(_DWORD *)(v6 + 116) + 20);
        if ( v9 == (const char *)-1 )
          v9 = defaultValue;
        CUtlString::operator+=(this: &mayaCommand, rhs: v9);
        CUtlString::operator+=(this: &mayaCommand, rhs: " ");
        CUtlString::operator+=(this: &mayaCommand, rhs: *(float *)(v6 + 112));
        CUtlString::operator+=(this: &mayaCommand, rhs: " -");
        v10 = *(const char **)(*(_DWORD *)(v6 + 124) + 20);
        if ( v10 == (const char *)-1 )
          v10 = defaultValue;
        CUtlString::operator+=(this: &mayaCommand, rhs: v10);
        CUtlString::operator+=(this: &mayaCommand, rhs: " ");
        CUtlString::operator+=(this: &mayaCommand, rhs: *(float *)(v6 + 120));
      }
      else
      {
        CUtlString::operator+=(this: &mayaCommand, rhs: " model");
      }
      FileName = CDmeMakefile::GetFileName(this: pMakeFile);
      V_strncpy(pDest: pFileName, pSrc: FileName, maxLen: 260);
      V_FixSlashes(pname: pFileName, separator: 47);
      CUtlString::operator+=(this: &mayaCommand, rhs: " -filename \\\"");
      CUtlString::operator+=(this: &mayaCommand, rhs: pFileName);
      CUtlString::operator+=(this: &mayaCommand, rhs: "\\\"");
      v12 = *(_DWORD *)(v6 + 84);
      if ( v12 > 0 )
      {
        do
        {
          CUtlString::operator+=(this: &mayaCommand, rhs: " ");
          v13 = *(const char **)(*(_DWORD *)(v6 + 72) + 4 * v5);
          if ( v13 == (const char *)-1 )
            v13 = defaultValue;
          CUtlString::operator+=(this: &mayaCommand, rhs: v13);
          ++v5;
        }
        while ( v5 < v12 );
      }
      CDmeMakefile::GetSourceFullPath(this: pMakeFile, pSource: (CDmeSource *)v6, pFullPath: pSourcePath, nBufLen: 260);
      V_FixSlashes(pname: pSourcePath, separator: 47);
      v14 = CUtlString::Get(this: &mayaCommand);
      V_snprintf(
        pDest: pMayaCommand,
        maxLen: 1024,
        pFormat: "mayabatch.exe -batch -file \"%s\" -command \"%s\"",
        pSourcePath,
        v14);
      v15 = ((int (__thiscall *)(IProcessUtils *, char *, int))g_pProcessUtils->StartProcess_2)(
              a1: g_pProcessUtils,
              a2: pMayaCommand,
              a3: 1);
      v16 = v21;
      v21->m_hCompileProcess = (IProcess *)v15;
      if ( v15 == 0 )
        v16->m_CompilationStep = AFTER_COMPILATION_FAILED;
      CUtlVector<CDmeHandle<CDmeSourceMayaFile,0>,CUtlMemory<CDmeHandle<CDmeSourceMayaFile,0>,int>>::Purge(this: &sources);
      if ( sources.m_Memory.m_nGrowSize >= 0 && sources.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sources.m_Memory.m_pMemory);
      mayaCommand.m_Storage.m_nActualLength = 0;
      if ( mayaCommand.m_Storage.m_Memory.m_nGrowSize >= 0 && mayaCommand.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: mayaCommand.m_Storage.m_Memory.m_pMemory);
      return 1;
    }
    else
    {
      CUtlVector<CDmeHandle<CDmeSourceMayaFile,0>,CUtlMemory<CDmeHandle<CDmeSourceMayaFile,0>,int>>::Purge(this: &sources);
      if ( sources.m_Memory.m_nGrowSize >= 0 && sources.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sources.m_Memory.m_pMemory);
      mayaCommand.m_Storage.m_nActualLength = 0;
      if ( mayaCommand.m_Storage.m_Memory.m_nGrowSize >= 0 && mayaCommand.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: mayaCommand.m_Storage.m_Memory.m_pMemory);
      return 0;
    }
  }
  else
  {
    switch ( step )
    {
      case BUILDING_STANDARD_DEPENDENCIES:
        result = CDmeMakefileUtils::AddCompileDependencies(
                   this,
                   pMakefile: (CDmeTransform *)pMakeFile,
                   bBuildAllDependencies: false);
        break;
      case BUILDING_ALL_DEPENDENCIES:
        result = CDmeMakefileUtils::AddCompileDependencies(
                   this,
                   pMakefile: (CDmeTransform *)pMakeFile,
                   bBuildAllDependencies: true);
        break;
      case BEFORE_COMPILATION:
        CDmeMakefile::PreCompile(this: pMakeFile);
        result = 1;
        break;
      case AFTER_COMPILATION_SUCCEEDED:
        CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)pMakeFile);
        goto LABEL_7;
      default:
LABEL_7:
        result = 1;
        break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00520F70
// Name: public: virtual bool CCompileFuncAdapter<class CDmeMakefileUtils,class CDmeMakefile>::PerformCompilationStep(class CDmElement __near *,enum CompilationStep_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCompileFuncAdapter<CDmeMakefileUtils,CDmeMakefile>::PerformCompilationStep(
        CCompileFuncAdapter<CDmeMakefileUtils,CDmeMakefile> *this,
        CDmeTransform *pElement,
        CompilationStep_t step)
{
  char result; // al

  if ( pElement == nullptr
    || !((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
          a1: pElement,
          a2: (CUtlSymbolLarge)CDmeMakefile::m_classType.u.m_Id) )
  {
    return 0;
  }
  switch ( step )
  {
    case BUILDING_STANDARD_DEPENDENCIES:
      result = CDmeMakefileUtils::AddCompileDependencies(
                 this: CDmeMakefileUtils::m_pSingleton,
                 pMakefile: pElement,
                 bBuildAllDependencies: false);
      break;
    case BUILDING_ALL_DEPENDENCIES:
      result = CDmeMakefileUtils::AddCompileDependencies(
                 this: CDmeMakefileUtils::m_pSingleton,
                 pMakefile: pElement,
                 bBuildAllDependencies: true);
      break;
    case BEFORE_COMPILATION:
      CDmeMakefile::PreCompile(this: (CDmeMakefile *)pElement);
      result = 1;
      break;
    case AFTER_COMPILATION_SUCCEEDED:
      CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)pElement);
      goto LABEL_8;
    default:
LABEL_8:
      result = 1;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00521010
// Name: public: virtual bool CCompileFuncAdapter<class CDmeMakefileUtils,class CDmeMDLMakefile>::PerformCompilationStep(class CDmElement __near *,enum CompilationStep_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCompileFuncAdapter<CDmeMakefileUtils,CDmeMDLMakefile>::PerformCompilationStep(
        CCompileFuncAdapter<CDmeMakefileUtils,CDmeMDLMakefile> *this,
        CDmeMDLMakefile *pElement,
        CompilationStep_t step)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeMDLMakefile::m_classType.u.m_Id) )
  {
    return CDmeMakefileUtils::PerformCompilationStep(this: CDmeMakefileUtils::m_pSingleton, pMakeFile: pElement, step);
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00521050
// Name: public: virtual bool CCompileFuncAdapter<class CDmeMakefileUtils,class CDmeMayaMakefile>::PerformCompilationStep(class CDmElement __near *,enum CompilationStep_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCompileFuncAdapter<CDmeMakefileUtils,CDmeMayaMakefile>::PerformCompilationStep(
        CCompileFuncAdapter<CDmeMakefileUtils,CDmeMayaMakefile> *this,
        CDmeMayaMakefile *pElement,
        CompilationStep_t step)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeMayaMakefile::m_classType.u.m_Id) )
  {
    return CDmeMakefileUtils::PerformCompilationStep(
             this: CDmeMakefileUtils::m_pSingleton,
             a2: (int)pElement,
             pMakeFile: pElement,
             step);
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051FEF0
// Name: class CDmeMayaMakefile __near * FindReferringElement<class CDmeMayaMakefile>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaMakefile *__cdecl FindReferringElement<CDmeMayaMakefile>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeMayaMakefile *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = *(_DWORD *)g_pDataModel.u.m_Id;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v4 + 436))(a1: g_pDataModel.u, a2: BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeMayaMakefile>(
               this: &it,
               symAttrName,
               bMustBeInSameFile,
               depth);
    if ( result != nullptr )
      break;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 440))(
           a1: g_pDataModel.u,
           a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}
