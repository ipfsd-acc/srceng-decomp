// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxloaderimpl.cpp
// Functions: 42
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxloaderimpl.h"

//------------------------------------------------------------------------------
// Address: 0x10063F90
// Name: public: virtual class GFxResourceId GFxImageResource::GetBaseImageId(void)
// Source: json
//------------------------------------------------------------------------------
struct GFxResourceId __thiscall GFxImageResource::GetBaseImageId(GFxImageResource *this, _DWORD *a2)
{
  *a2 = 0;
  return (struct GFxResourceId)a2;
}

//------------------------------------------------------------------------------
// Address: 0x1006AD70
// Name: public: class GFxResource __near * GFxResourceLib::BindHandle::WaitForResolve(void)
// Source: json
//------------------------------------------------------------------------------
struct GFxResource *__thiscall GFxResourceLib::BindHandle::WaitForResolve(GFxResourceLib::BindHandle *this)
{
  GFxResource *pResource; // edi
  GFxResource *Value; // ebx

  if ( this->State == RS_Available )
  {
    InterlockedExchangeAdd(Addend: &this->pResource->RefCount.Value, Value: 1);
    return this->pResource;
  }
  else if ( this->State == RS_Error )
  {
    return nullptr;
  }
  else
  {
    pResource = this->pResource;
    GEvent::Wait(this: (CDbgFmtMsg *)&pResource[2].pLib);
    if ( pResource[1].RefCount.Value != 0 )
      InterlockedExchangeAdd(Addend: (volatile LONG *)(pResource[1].RefCount.Value + 4), Value: 1);
    Value = (GFxResource *)pResource[1].RefCount.Value;
    if ( Value != nullptr )
    {
      this->State = RS_Available;
      this->pResource = Value;
      InterlockedExchangeAdd(Addend: &Value->RefCount.Value, Value: 1);
      GRefCountImpl::Release(this: (IShaderAPI *)pResource);
      return Value;
    }
    else
    {
      this->State = RS_Error;
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006F320
// Name: int G_iswspace(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall G_iswspace(const CFileSystemPassThru *charCode)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1006F370
// Name: public: virtual class GFxResourceKey GFxResource::GetKey(void)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall GFxResource::GetKey(GFxResource *this, GFxValue *a2)
{
  GFxResourceKey::GFxResourceKey(this: a2);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x1006F390
// Name: public: GFxResourceLib::BindHandle::~BindHandle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxResourceLib::BindHandle::~BindHandle(CMemoryStack *this)
{
  if ( this->m_pNextAlloc == (unsigned __int8 *)1 )
  {
    GFxResource::Release(this: (IShaderDevice *)this->m_pCommitLimit);
  }
  else if ( (int)this->m_pNextAlloc >= 2 )
  {
    GRefCountImpl::Release(this: (IShaderAPI *)this->m_pCommitLimit);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006F3B0
// Name: public: void GFxLog::LogMessageByType(enum GFxLogConstants::LogMessageType,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void GFxLog::LogMessageByType(GFxLog *this, enum GFxLogConstants::LogMessageType a2, const char *a3, ...)
{
  va_list va; // [esp+14h] [ebp+14h] BYREF

  va_start(va, a3);
  this->LogMessageVarg(this, a2, a3, a4: va);
}

//------------------------------------------------------------------------------
// Address: 0x1006F3D0
// Name: public: static enum GFxFileConstants::FileFormatType GFxLoaderImpl::DetectFileFormat(class GFile __near *)
// Source: json
//------------------------------------------------------------------------------
static int __cdecl GFxLoaderImpl::DetectFileFormat(struct GFile *a1)
{
  struct GFile *v1; // esi
  int v3; // ebx
  int (__thiscall *Read)(GFile *, unsigned __int8 *, int); // edx
  int v5; // edi
  char v6; // al
  unsigned __int8 *v7; // eax
  const char *v8; // eax

  v1 = a1;
  if ( a1 == nullptr )
    return 0;
  v3 = a1->Tell(this: a1);
  Read = v1->Read;
  v5 = 1;
  a1 = nullptr;
  if ( Read(this: v1, a2: (unsigned __int8 *)&a1, a3: 4) > 0 )
  {
    switch ( (char)a1 )
    {
      case 67:
      case 70:
        v6 = BYTE1(a1);
        if ( BYTE1(a1) != 87 )
          goto LABEL_8;
        if ( BYTE2(a1) == 83 )
          v5 = 2;
        break;
      case 68:
        if ( *(_WORD *)((char *)&a1 + 1) == 21316 )
          v5 = 14;
        break;
      case 71:
        v6 = BYTE1(a1);
        if ( BYTE1(a1) == 73 )
        {
          if ( HIWORD(a1) == 14406 )
            v5 = 12;
        }
        else
        {
LABEL_8:
          if ( v6 == 70 && BYTE2(a1) == 88 )
            v5 = 3;
        }
        break;
      case -119:
        if ( *(_WORD *)((char *)&a1 + 1) == 20048 && HIBYTE(a1) == 71 )
          v5 = 11;
        break;
      case -1:
        if ( BYTE1(a1) == 0xD8 )
          v5 = 10;
        break;
      default:
        break;
    }
    v1->Seek(this: v1, a2: v3, a3: 0);
    if ( v5 == 1 )
    {
      v7 = (unsigned __int8 *)v1->GetFilePath(this: v1);
      if ( v7 != nullptr )
      {
        strrchr(string: v7, chr: 0x2Eu);
        if ( v8 != nullptr && GString::CompareNoCase(a1: v8, a2: ".tga") == 0 )
          return 13;
      }
    }
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1006F5D0
// Name: public: virtual bool GFxTranslator::OnWordWrapping(struct GFxTranslator::LineFormatDesc __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxTranslator::OnWordWrapping(CFileSystemPassThru *this, int pstr)
{
  unsigned int m_pFileSystemPassThru; // eax
  int v5; // eax
  const CFileSystemPassThru *v6; // ecx
  unsigned int v7; // ebx
  int v8; // eax
  unsigned int v9; // edi
  const CFileSystemPassThru *v10; // ecx
  __int16 v11; // ax
  float v12; // [esp+0h] [ebp-4h]
  int pstra; // [esp+Ch] [ebp+8h]
  int pstrb; // [esp+Ch] [ebp+8h]

  m_pFileSystemPassThru = (unsigned int)this->m_pFileSystemPassThru;
  if ( m_pFileSystemPassThru == 0 )
    return 0;
  if ( (m_pFileSystemPassThru & 7) != 0 && *(_DWORD *)(pstr + 16) != 0 )
  {
    LOBYTE(v5) = GFxWWHelper::FindWordWrapPos(wwMode: *(CJob **)pstr, wordWrapPos: m_pFileSystemPassThru);
    if ( v5 == -1 )
    {
      return 0;
    }
    else
    {
      *(_DWORD *)(pstr + 40) = v5;
      return 1;
    }
  }
  else if ( (m_pFileSystemPassThru & 8) != 0
         && (v6 = *(const CFileSystemPassThru **)(pstr + 40)) != nullptr
         && (v7 = *(_DWORD *)(pstr + 16),
             pstra = *(_DWORD *)pstr + 2 * *(_DWORD *)(pstr + 12),
             G_iswspace(charCode: v6),
             v9 = v8 != 0 ? *(_DWORD *)(pstr + 40) : 0,
             v7 > v9) )
  {
    v10 = (const CFileSystemPassThru *)pstra;
    for ( pstrb = pstra + 2 * v7 - 2; ; pstrb -= 2 )
    {
      G_towlower(charCode: v10);
      if ( v11 == 97 || v11 == 101 || v11 == 111 || v11 == 117 || v11 == 105 )
      {
        v10 = *(const CFileSystemPassThru **)(pstr + 8);
        v12 = *((float *)v10 + v7 - 1) + *(float *)(pstr + 32);
        if ( *(float *)(pstr + 20) > (double)v12 )
          break;
      }
      if ( --v7 <= v9 )
        return 0;
    }
    *(_DWORD *)(pstr + 40) = v7;
    *(_BYTE *)(pstr + 44) = 1;
    return 1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006F6E0
// Name: public: void GFxTranslator::TranslateInfo::SetResult(wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTranslator::TranslateInfo::SetResult(
        GFxTranslator::TranslateInfo *this,
        wchar_t *pwch,
        unsigned int a3)
{
  unsigned int v4; // ebx

  if ( pwch != nullptr )
  {
    v4 = a3;
    if ( a3 == -1 )
      v4 = G_wcslen(pwch);
    GFxWStringBuffer::Resize(this: this->pResult, a2: v4 + 1);
    G_wcsncpy(dest: this->pResult->pText, destsize: v4 + 1, count: pwch, _Count: v4);
    this->Flags |= 1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006F790
// Name: public: void GFxLoadProcess::SetBindProcess(class GFxMovieBindProcess __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoadProcess::SetBindProcess(GFxLoadProcess *this, IShaderDevice *a2)
{
  IShaderAPI *v3; // ecx
  VertexShaderHandle_t__ *v4; // [esp+0h] [ebp-8h]

  if ( a2 != nullptr )
    GRefCountImpl::AddRef(this: a2, a2: v4);
  v3 = (IShaderAPI *)*(this + 7);
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  *(this + 7) = (GFxLoadProcess)a2;
}

//------------------------------------------------------------------------------
// Address: 0x1006F7C0
// Name: public: GFxURLBuilder::LocationInfo::~LocationInfo(void)
// Source: json
//------------------------------------------------------------------------------
const CFunctorData0 *__thiscall GFxURLBuilder::LocationInfo::~LocationInfo(_DWORD *this)
{
  volatile LONG *v2; // esi
  unsigned int v3; // esi
  const CFunctorData0 *v4; // eax

  v2 = (volatile LONG *)(*(this + 2) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  v3 = *(this + 1) & 0xFFFFFFFC;
  v4 = (const CFunctorData0 *)(InterlockedExchangeAdd(Addend: (volatile LONG *)(v3 + 4), Value: -1) - 1);
  if ( v4 == nullptr )
    return ((const CFunctorData0 *(__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
             a1: GMemory::pGlobalHeap,
             a2: v3);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1006F810
// Name: public: void GFxLoaderImpl::UnRegisterLoadProcess(class GFxLoaderTask __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLoaderImpl::UnRegisterLoadProcess(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        CTSQueue<CFunctor *,0,1>::Node_t *ptask)
{
  unsigned int *p_m_nCurSerialNumber; // edi
  CCallQueueT<CTSQueue<CFunctor *,0,1> > *sequence; // eax

  p_m_nCurSerialNumber = &this->m_nCurSerialNumber;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_nCurSerialNumber);
  sequence = *(CCallQueueT<CTSQueue<CFunctor *,0,1> > **)&this->m_bNoQueue;
  if ( sequence != (CCallQueueT<CTSQueue<CFunctor *,0,1> > *)((char *)&this->m_queue.m_FreeNodes.m_Head.value64 + 4) )
  {
    while ( sequence->m_queue.m_Tail.value.pNode != ptask )
    {
      sequence = (CCallQueueT<CTSQueue<CFunctor *,0,1> > *)sequence->m_queue.m_Head.value.sequence;
      if ( sequence == (CCallQueueT<CTSQueue<CFunctor *,0,1> > *)((char *)&this->m_queue.m_FreeNodes.m_Head.value64 + 4) )
        goto LABEL_6;
    }
    sequence->m_queue.m_Head.value.pNode->elem = (CFunctor *)sequence->m_queue.m_Head.value.sequence;
    *(_DWORD *)sequence->m_queue.m_Head.value.sequence = sequence->m_queue.m_Head.value.pNode;
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: sequence);
  }
LABEL_6:
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)p_m_nCurSerialNumber);
}

//------------------------------------------------------------------------------
// Address: 0x1006F880
// Name: public: void GFxLoaderImpl::CancelLoading(void)
// Source: json
//------------------------------------------------------------------------------
ShaderAPIOcclusionQuery_t__ *__thiscall GFxLoaderImpl::CancelLoading(int this)
{
  ShaderAPIOcclusionQuery_t__ *v2; // eax
  IShaderAPI *v3; // ebx
  _DWORD *i; // esi

  v2 = (ShaderAPIOcclusionQuery_t__ *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(*(_DWORD *)(this + 20) + 8) + 12))(
                                        a1: *(_DWORD *)(this + 20) + 8,
                                        a2: 23);
  v3 = (IShaderAPI *)v2;
  if ( v2 != nullptr )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 36));
    for ( i = *(_DWORD **)(this + 32); i != (_DWORD *)(this + 28); i = *(_DWORD **)(this + 32) )
    {
      *(_DWORD *)(*i + 4) = i[1];
      *(_DWORD *)i[1] = *i;
      ((void (__thiscall *)(IShaderAPI *, _DWORD))v3->GetSceneFogMode)(a1: v3, a2: i[2]);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: i);
    }
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 36));
    return GRefCountImpl::Release(this: v3);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1006F910
// Name: s_OpenAndDetectFile
// Source: json
//------------------------------------------------------------------------------
IShaderAPI *__usercall s_OpenAndDetectFile@<eax>(
        const char *a1@<eax>,
        GFxLoadStates *a2@<ecx>,
        unsigned int a3@<ebx>,
        int *a4,
        _DWORD *a5,
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *a6)
{
  struct GFile *v7; // eax
  IShaderAPI *v8; // esi
  int v9; // eax
  void *v10; // esi
  int v12; // eax
  int v13; // eax
  int v14; // eax
  void *v15; // edi
  VertexShaderHandle_t__ *v16; // [esp+0h] [ebp-10h]
  CUtlMemory<CImagePacker,int> var8; // [esp+8h] [ebp-8h] BYREF

  v7 = GFxLoadStates::OpenFile(this: a2, a2: a1, a3);
  v8 = (IShaderAPI *)v7;
  if ( v7 != nullptr )
  {
    v12 = GFxLoaderImpl::DetectFileFormat(a1: v7);
    *a4 = v12;
    switch ( v12 )
    {
      case 2:
        if ( (a3 & 0x80000) == 0 )
          goto LABEL_7;
        GString::GString(
          this: (CUtlMemory<CImagePacker,int> *)&var8.m_nAllocationCount,
          pdata1: (int)"Error loading SWF file \"",
          pdata2: (int)a1);
        GString::operator=(this: a6, src: v13, a3: (int)v16);
        GString::~GString(this: (GString *)&var8.m_nAllocationCount);
        GRefCountImpl::Release(this: v8);
        return nullptr;
      case 3:
LABEL_7:
        *a5 = 1;
        goto LABEL_10;
      case 10:
      case 11:
      case 13:
      case 14:
        if ( (a3 & 0x10000) == 0 )
          goto LABEL_11;
        *a5 = 2;
LABEL_10:
        GRefCountImpl::AddRef(this: (IShaderDevice *)v8, a2: v16);
        GRefCountImpl::Release(this: v8);
        return v8;
      default:
LABEL_11:
        GString::GString(this: &var8, pdata1: (int)"Unknown file format at URL \"", pdata2: (int)a1);
        GString::operator=(this: a6, src: v14, a3: (int)v16);
        v15 = (void *)((int)var8.m_pMemory & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v15);
        GRefCountImpl::Release(this: v8);
        return nullptr;
    }
  }
  GString::GString(
    this: (CUtlMemory<CImagePacker,int> *)&var8.m_nAllocationCount,
    pdata1: (int)"GFxLoader failed to open \"",
    pdata2: (int)a1);
  GString::operator=(this: a6, src: v9, a3: (int)v16);
  v10 = (void *)(var8.m_nAllocationCount & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((var8.m_nAllocationCount & 0xFFFFFFFC) + 4), Value: -1) != 1 )
    return nullptr;
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v10);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006FA80
// Name: public: static class GFxMovieDefImpl __near * GFxLoaderImpl::BindMovieAndWait(class GFxMovieDefImpl __near *,class GFxMovieBindProcess __near *,class GFxLoadStates __near *,unsigned int,struct GFxLoaderImpl::LoadStackItem __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
IShaderDevice *__cdecl GFxLoaderImpl::BindMovieAndWait(
        IShaderDevice *result,
        int pls,
        int pls_4,
        char loadConstants,
        _SECURITY_QUALITY_OF_SERVICE *ploadStack)
{
  char v5; // al
  _SECURITY_QUALITY_OF_SERVICE *v6; // esi
  _SECURITY_QUALITY_OF_SERVICE *v7; // eax
  bool v8; // al
  unsigned int v9; // eax
  unsigned int v10; // eax
  const char *v11; // eax
  __int128 v13; // [esp+0h] [ebp-24h] OVERLAPPED BYREF

  if ( pls != 0 )
  {
    if ( (loadConstants & 1) != 0 || (GFxLoadStates::SubmitBackgroundTask(this: (CP4Factory *)pls_4), v5 == 0) )
      (*(void (__thiscall **)(int))(*(_DWORD *)pls + 4))(a1: pls);
  }
  v6 = ploadStack;
  v7 = ploadStack;
  if ( ploadStack == nullptr )
  {
LABEL_8:
    if ( (loadConstants & 1) != 0 )
    {
      v8 = GFxMovieDefImpl::BindTaskData::WaitForBindStateFlags(this: &result[7].ReleaseResources, result: 0x200u);
    }
    else
    {
      if ( (loadConstants & 2) == 0 )
        return result;
      v8 = GFxMovieDefImpl::BindTaskData::WaitForBindStateFlags(this: &result[7].ReleaseResources, result: 0x100u);
    }
    if ( !v8 )
      goto LABEL_20;
    return result;
  }
  while ( (IShaderDevice *)v7->Length != result )
  {
    v7 = (_SECURITY_QUALITY_OF_SERVICE *)v7->ImpersonationLevel;
    if ( v7 == nullptr )
      goto LABEL_8;
  }
  if ( v7->ImpersonationLevel == SecurityAnonymous )
    return result;
  if ( *(_DWORD *)(pls_4 + 12) == 0 )
  {
LABEL_20:
    GFxResource::Release(this: result);
    return nullptr;
  }
  GStringBuffer::GStringBuffer(result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GMemory::pGlobalHeap);
  do
  {
    v9 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v6->Length + 48))(a1: v6->Length);
    GStringBuffer::AppendString(
      this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&v13 + 12),
      putf8str: v9);
    GStringBuffer::AppendChar(
      this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&v13 + 12),
      ch: (CMatRenderContextBase *)0xA,
      srcSize: v13);
    v6 = (_SECURITY_QUALITY_OF_SERVICE *)v6->ImpersonationLevel;
  }
  while ( v6 != nullptr );
  v10 = ((int (__thiscall *)(IShaderDevice *))result->SetHardwareGammaRamp)(a1: result);
  GStringBuffer::AppendString(
    this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&v13 + 12),
    putf8str: v10);
  GStringBuffer::AppendChar(
    this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&v13 + 12),
    ch: (CMatRenderContextBase *)0xA,
    srcSize: v13);
  v11 = (const char *)HIDWORD(v13);
  if ( HIDWORD(v13) == 0 )
    v11 = (const char *)&pMem;
  GFxLogBase<GFxLog>::LogError(
    this: (GFxLogBase<GFxLog> *)(*(_DWORD *)(pls_4 + 12) + 12),
    pfmt: "Error: Recursive import detected. Import stack:\n%s",
    v11);
  GStringBuffer::~GStringBuffer(
    this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)((char *)&v13 + 12),
    a2: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)v13);
  GFxResource::Release(this: result);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006FBB0
// Name: private: static class GFxMovieDefImpl __near * GFxLoaderImpl::CreateMovieDefImpl(class GFxLoadStates __near *,class GFxMovieDataDef __near *,unsigned int,class GFxMovieBindProcess __near * __near *,bool,struct GFxLoaderImpl::LoadStackItem __near *,unsigned int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
static IShaderDevice *__cdecl GFxLoaderImpl::CreateMovieDefImpl(
        unsigned int loadConstants,
        IShaderDevice *a2,
        unsigned int a3,
        struct GFxMovieBindProcess **a4,
        bool checkCreate,
        _SECURITY_QUALITY_OF_SERVICE *ploadStack,
        unsigned int memoryArena,
        bool *justCreated)
{
  CLateBoundPtr<IMesh> v8; // ecx
  IShaderDevice *v9; // ebx
  unsigned int v10; // esi
  IShaderDevice *v11; // edi
  GFxMovieDefImpl *v12; // ecx
  IShaderDevice *v13; // edi
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),CFuncMemPolicyNone> *v14; // eax
  struct GFxMovieBindProcess *v15; // eax
  void *v16; // esi
  const char *Error; // eax
  __int128 v19; // [esp-Ch] [ebp-28h]
  _DWORD pbindStates[2]; // [esp+Ch] [ebp-10h] BYREF
  GFxResourceLib::BindHandle pbindStates_8; // [esp+14h] [ebp-8h] BYREF

  v9 = a2;
  v10 = loadConstants;
  v11 = *(IShaderDevice **)(loadConstants + 8);
  DWORD2(v19) = v11;
  pbindStates_8 = 0;
  DWORD1(v19) = a2;
  LODWORD(v19) = pbindStates;
  GFxMovieDefImpl::CreateMovieKey(pdataDef: v8, pbindStates: v19);
  if ( GFxResourceWeakLib::BindResourceKey(
         this: *(_DWORD *)(v10 + 56),
         result: (ShaderDeviceInfo_t *)&pbindStates_8,
         a3: (int)pbindStates) == 3 )
  {
    loadConstants = 2;
    v12 = (GFxMovieDefImpl *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 32, a3: &loadConstants);
    if ( v12 != nullptr )
    {
      v9 = a2;
      v13 = (IShaderDevice *)GFxMovieDefImpl::GFxMovieDefImpl(
                               this: v12,
                               a2,
                               a3: v11,
                               a4: *(IShaderDevice **)(v10 + 60),
                               a5: a3,
                               a6: *(struct GFxStateBagImpl **)(*(_DWORD *)(v10 + 60) + 20),
                               a7: (ExprNode *)GMemory::pGlobalHeap,
                               a8: false,
                               a9: memoryArena);
    }
    else
    {
      v13 = nullptr;
    }
    if ( justCreated != nullptr )
      *justCreated = true;
    if ( a4 != nullptr )
    {
      loadConstants = 2;
      v14 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),CFuncMemPolicyNone> *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 52, a3: &loadConstants);
      v15 = v14 != nullptr
          ? (struct GFxMovieBindProcess *)GFxMovieBindProcess::GFxMovieBindProcess(
                                            this: v14,
                                            pls: (tagENUMLOGFONTEXDVW *)v10,
                                            a3: (int)v13,
                                            ploadStack)
          : nullptr;
      *a4 = v15;
      if ( v15 == nullptr )
      {
        if ( v13 != nullptr )
          GFxResource::Release(this: v13);
        goto LABEL_14;
      }
    }
    if ( v13 == nullptr )
    {
LABEL_14:
      GString::GString(
        this: (CUtlMemory<CImagePacker,int> *)&loadConstants,
        pdata1: (int)"Failed to bind SWF file \"",
        pdata2: ((int)v9[8].IsAAEnabled & 0xFFFFFFFC) + 8);
      GFxResourceLib::ResourceSlot::CancelResolve(
        this: pbindStates_8.pSlot,
        a2: (const char *)((loadConstants & 0xFFFFFFFC) + 8));
      v16 = (void *)(loadConstants & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((loadConstants & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v16);
LABEL_16:
      if ( pbindStates[0] != 0 )
        (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)pbindStates[0] + 8))(a1: pbindStates[0], a2: pbindStates[1]);
      if ( pbindStates_8.State == RS_Available )
      {
        GFxResource::Release(this: (IShaderDevice *)pbindStates_8.pResource);
        return nullptr;
      }
      else
      {
        if ( pbindStates_8.State >= RS_WaitingResolve )
          GRefCountImpl::Release(this: (IShaderAPI *)pbindStates_8.pResource);
        return nullptr;
      }
    }
    GFxResourceLib::ResourceSlot::Resolve(this: pbindStates_8.pSlot, a2: (struct GFxResource *)v13);
  }
  else
  {
    v13 = (IShaderDevice *)GFxResourceLib::BindHandle::WaitForResolve(this: &pbindStates_8);
    if ( v13 == nullptr )
    {
      if ( *(_DWORD *)(v10 + 12) != 0 )
      {
        if ( pbindStates_8.State < RS_WaitingResolve )
          Error = (const char *)&pMem;
        else
          Error = (const char *)GFxResourceLib::ResourceSlot::GetError(this: (CUtlBinaryBlock *)pbindStates_8.pResource);
        GFxLogBase<GFxLog>::LogError(this: (GFxLogBase<GFxLog> *)(*(_DWORD *)(v10 + 12) + 12), pfmt: "Error: %s", Error);
      }
      goto LABEL_16;
    }
    if ( justCreated != nullptr )
      *justCreated = false;
  }
  if ( pbindStates[0] != 0 )
    (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)pbindStates[0] + 8))(a1: pbindStates[0], a2: pbindStates[1]);
  if ( pbindStates_8.State == RS_Available )
  {
    GFxResource::Release(this: (IShaderDevice *)pbindStates_8.pResource);
    return v13;
  }
  else
  {
    if ( pbindStates_8.State >= RS_WaitingResolve )
      GRefCountImpl::Release(this: (IShaderAPI *)pbindStates_8.pResource);
    return v13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006FDD0
// Name: public: static class GFxMovieDefImpl __near * GFxLoaderImpl::CreateMovie_LoadState(class GFxLoadStates __near *,class GFxMovieDataDef __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
IShaderDevice *__cdecl GFxLoaderImpl::CreateMovie_LoadState(
        tagNEWTEXTMETRICA *result,
        IShaderAPI *a2,
        unsigned int a3,
        unsigned int memoryArena)
{
  IShaderAPI *v4; // ebx
  char v5; // di
  IShaderDevice *MovieDefImpl; // eax
  IShaderAPI *v8; // esi
  IShaderDevice *v9; // edi

  v4 = a2;
  if ( a2 != nullptr )
    GFxLoadStates::SetRelativePathForDataDef(this: (GFxLoadStates *)result, (struct GFxMovieDataDef *)a2);
  v5 = a3;
  a2 = nullptr;
  MovieDefImpl = GFxLoaderImpl::CreateMovieDefImpl(
                   loadConstants: (unsigned int)result,
                   a2: (IShaderDevice *)v4,
                   a3,
                   a4: (struct GFxMovieBindProcess **)&a2,
                   checkCreate: false,
                   ploadStack: nullptr,
                   memoryArena,
                   justCreated: nullptr);
  if ( MovieDefImpl != nullptr )
  {
    v8 = a2;
    v9 = GFxLoaderImpl::BindMovieAndWait(
           result: MovieDefImpl,
           pls: (int)a2,
           pls_4: (int)result,
           loadConstants: v5,
           ploadStack: nullptr);
    if ( v8 != nullptr )
      GRefCountImpl::Release(this: v8);
    return v9;
  }
  else
  {
    if ( a2 != nullptr )
      GRefCountImpl::Release(this: a2);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006FE50
// Name: public: static class GImageInfoBase __near * GFxLoaderImpl::CreateStaticUserImage(void)
// Source: json
//------------------------------------------------------------------------------
static GImageInfo *GFxLoaderImpl::CreateStaticUserImage()
{
  GImage *v0; // eax
  struct GImage *v1; // esi
  char *v2; // eax
  int i; // ebx
  int j; // esi
  GImageInfo *v5; // eax
  GImageInfo *v6; // edi
  int v8; // [esp+8h] [ebp-10h] BYREF
  int v9; // [esp+Ch] [ebp-Ch]
  CBaseShader *v10; // [esp+10h] [ebp-8h]
  char *v11; // [esp+14h] [ebp-4h]

  v8 = 3;
  v0 = (GImage *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 48, a3: &v8);
  if ( v0 != nullptr )
  {
    v1 = GImage::GImage(this: v0, a2: IMAGE_FORMAT_ABGR8888, a3: 0x39u, a4: 0x24u);
    v10 = (CBaseShader *)v1;
    if ( v1 != nullptr )
    {
      v8 = 0;
      v2 = pstaticImage;
      do
      {
        v9 = 0;
        v11 = v2;
        do
        {
          for ( i = 0; i < 3; ++i )
          {
            for ( j = 0; j < 3; ++j )
              GImageBase::SetPixelRGBA(this: v10 + 2, x: (IMaterialVar **)(j + v9), y: i + v8);
          }
          ++v11;
          v9 += 3;
        }
        while ( v9 < 57 );
        v2 = v11;
        v8 += 3;
      }
      while ( (int)v11 < (int)&pstaticImage[228] );
      v1 = (struct GImage *)v10;
    }
  }
  else
  {
    v1 = nullptr;
  }
  v8 = 2;
  v5 = (GImageInfo *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 40, a3: &v8);
  if ( v5 != nullptr )
    v6 = GImageInfo::GImageInfo(this: v5, a2: v1, a3: false);
  else
    v6 = nullptr;
  if ( v1 != nullptr )
    GRefCountNTSImpl::Release(this: v1);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100700F0
// Name: public: GFxImageResource::GFxImageResource(class GImageInfoBase __near *,enum GFxResource::ResourceUse)
// Source: json
//------------------------------------------------------------------------------
GFxImageResource *__thiscall GFxImageResource::GFxImageResource(
        GFxImageResource *this,
        struct GImageInfoBase *a2,
        enum GFxResource::ResourceUse a3)
{
  GRefCountNTSImpl *v4; // ecx

  *this = (GFxImageResource)&GFxResource::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = 0;
  *this = (GFxImageResource)&GFxImageResource::`vftable';
  *((_DWORD *)this + 3) = 0;
  GFxResourceKey::GFxResourceKey(this: (GFxValue *)this + 1);
  if ( a2 != nullptr )
    ++a2->RefCount;
  v4 = *((GRefCountNTSImpl **)this + 3);
  if ( v4 != nullptr )
    GRefCountNTSImpl::Release(this: v4);
  *((_DWORD *)this + 3) = a2;
  *((_DWORD *)this + 6) = a3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10070150
// Name: public: virtual class GFxResourceKey GFxImageResource::GetKey(void)
// Source: json
//------------------------------------------------------------------------------
GFxResourceKey *__thiscall GFxImageResource::GetKey(GFxImageResource *this, GFxResourceKey *a2)
{
  GFxResourceKey::GFxResourceKey(this: a2, a2: (const struct GFxResourceKey *)this + 2);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10070170
// Name: public: virtual unsigned int GFxImageResource::GetResourceTypeCode(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxImageResource::GetResourceTypeCode(GFxImageResource *this)
{
  return *((_DWORD *)this + 6) | 0x100;
}

//------------------------------------------------------------------------------
// Address: 0x10070180
// Name: public: virtual GFxLoaderTask::~GFxLoaderTask(void)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall GFxLoaderTask::~GFxLoaderTask(CTSQueue<CFunctor *,0,1>::Node_t *this)
{
  int v2; // eax
  IShaderAPI *v3; // ecx

  v2 = *((_DWORD *)this + 4);
  this->pNext = (CTSQueue<CFunctor *,0,1>::Node_t *)&GFxLoaderTask::`vftable';
  GFxLoaderImpl::UnRegisterLoadProcess(this: *(CCallQueueT<CTSQueue<CFunctor *,0,1> > **)(v2 + 60), ptask: this);
  v3 = *((IShaderAPI **)this + 4);
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  this->pNext = (CTSQueue<CFunctor *,0,1>::Node_t *)&GFxTask::`vftable';
  return GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100701D0
// Name: private: virtual class GFxStateBag __near * GFxLoaderImpl::GetStateBagImpl(void)const
// Source: json
//------------------------------------------------------------------------------
struct GFxStateBag *__thiscall GFxLoaderImpl::GetStateBagImpl(GFxLoaderImpl *this)
{
  int v1; // eax

  v1 = *((_DWORD *)this + 3);
  if ( v1 != 0 )
    return (struct GFxStateBag *)(v1 + 8);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100701E0
// Name: public: static class GFxImageResource __near * GFxLoaderImpl::LoadMovieImage(char const __near *,class GFxImageLoader __near *,class GFxLog __near *,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
static GFxImageResource *__cdecl GFxLoaderImpl::LoadMovieImage(
        const char *a1,
        int a2,
        struct GFxLog *a3,
        struct GMemoryHeap *a4)
{
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v4; // ecx
  GImageInfo *StaticUserImage; // esi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // eax
  GFxImageResource *v7; // eax
  GFxImageResource *v8; // edi

  v4 = (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)a2;
  if ( a2 == 0
    || (StaticUserImage = (GImageInfo *)(*(int (__thiscall **)(int, const char *))(*(_DWORD *)a2 + 4))(a1: a2, a2: a1)) == nullptr )
  {
    if ( a3 != nullptr )
      GFxLogBase<GFxLog>::LogScriptWarning(
        this: v4,
        pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&a3->GFxLogBase<GFxLog>,
        this_4: (int)"Could not load user image \"%s\" - GFxImageLoader failed or not specified\n",
        this_8: (int)a1);
    StaticUserImage = GFxLoaderImpl::CreateStaticUserImage();
    if ( StaticUserImage == nullptr )
      goto LABEL_8;
  }
  Alloc_2 = a4->Alloc_2;
  a2 = 2;
  v7 = (GFxImageResource *)Alloc_2(this: a4, a2: 28u, a3: (const GAllocDebugInfo *)&a2);
  if ( v7 != nullptr )
    v8 = GFxImageResource::GFxImageResource(this: v7, a2: StaticUserImage, a3: Use_Bitmap);
  else
LABEL_8:
    v8 = nullptr;
  if ( StaticUserImage != nullptr )
    GRefCountNTSImpl::Release(this: StaticUserImage);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100703A0
// Name: public: GFxLoaderTask::GFxLoaderTask(class GFxLoadStates __near *,enum GFxTask::TaskId)
// Source: json
//------------------------------------------------------------------------------
tagENUMLOGFONTEXDVW *__thiscall GFxLoaderTask::GFxLoaderTask(
        void (__thiscall *this)(IShaderDevice *this),
        IShaderDevice *result,
        int a3)
{
  IShaderDevice_vtbl *v4; // edi
  void (__thiscall **v5)(IShaderDevice *); // eax
  void (__thiscall **v6)(IShaderDevice *); // ecx
  VertexShaderHandle_t__ *v8; // [esp+0h] [ebp-10h]
  int v9; // [esp+Ch] [ebp-4h] BYREF

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *(_DWORD *)this = &GFxTask::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = a3;
  *((_DWORD *)this + 3) = 0;
  *(_DWORD *)this = &GFxLoaderTask::`vftable';
  if ( result != nullptr )
    GRefCountImpl::AddRef(this: result, a2: v8);
  *((_DWORD *)this + 4) = result;
  v4 = result[15].__vftable;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&v4->IsAAEnabled);
  v9 = 2;
  v5 = (void (__thiscall **)(IShaderDevice *))GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 12, a3: &v9);
  if ( v5 != nullptr )
  {
    v5[2] = this;
    v6 = v5;
  }
  else
  {
    v6 = nullptr;
  }
  *v6 = v4->SpewDriverInfo;
  v6[1] = (void (__thiscall *)(IShaderDevice *))&v4->SpewDriverInfo;
  *((_DWORD *)v4->SpewDriverInfo + 1) = v6;
  v4->SpewDriverInfo = (void (__thiscall *)(IShaderDevice *))v6;
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&v4->IsAAEnabled);
  return (tagENUMLOGFONTEXDVW *)this;
}

//------------------------------------------------------------------------------
// Address: 0x10070500
// Name: public: GFxMovieImageLoadTask::GFxMovieImageLoadTask(class GFxMovieDataDef __near *,class GFxMovieDefImpl __near *,class GFile __near *,enum GFxFileConstants::FileFormatType,class GFxLoadStates __near *)
// Source: json
//------------------------------------------------------------------------------
GFxMovieImageLoadTask *__thiscall GFxMovieImageLoadTask::GFxMovieImageLoadTask(
        GFxMovieImageLoadTask *this,
        IShaderDevice *a2,
        IShaderDevice *a3,
        IShaderDevice *a4,
        enum GFxFileConstants::FileFormatType a5,
        IShaderDevice *result)
{
  VertexShaderHandle_t__ *v8; // [esp+0h] [ebp-8h]

  GFxLoaderTask::GFxLoaderTask((void (__thiscall *)(IShaderDevice *))this, result, a3: 131074);
  *(_DWORD *)this = &GFxMovieImageLoadTask::`vftable';
  if ( a2 != nullptr )
    GRefCountImpl::AddRef(this: a2, a2: v8);
  *((_DWORD *)this + 5) = a2;
  if ( a3 != nullptr )
    GRefCountImpl::AddRef(this: a3, a2: v8);
  *((_DWORD *)this + 6) = a3;
  if ( a4 != nullptr )
    GRefCountImpl::AddRef(this: a4, a2: v8);
  *((_DWORD *)this + 7) = a4;
  *((_DWORD *)this + 8) = a5;
  *((_DWORD *)this + 9) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10070570
// Name: public: virtual void GFxMovieImageLoadTask::Execute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieImageLoadTask::Execute(GFxMovieImageLoadTask *this)
{
  int v2; // eax
  int v3; // edi
  GRefCountNTSImpl *v4; // eax
  GRefCountNTSImpl *v5; // ecx
  int v6; // eax
  int v7; // ebx
  bool v8; // zf
  struct GImageInfoBase *v9; // ebx
  int (__thiscall *v10)(int, int, int *); // edx
  GFxImageResource *v11; // eax
  GFxImageResource *v12; // edi
  IShaderDevice *v13; // ecx
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v14; // ebx
  int v15; // edi
  unsigned int v16; // eax
  _DWORD *v17; // ecx
  GFxMovieDefImpl::BindTaskData *v18; // edi
  LONG v19; // eax
  CBitVecT<CFixedBitVecBase<64> > *v20; // [esp-8h] [ebp-50h]
  const CMemberFunctor1<COcclusionQueryMgr *,void (__thiscall COcclusionQueryMgr::*)(OcclusionQueryObjectHandle_t__ *),OcclusionQueryObjectHandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v21; // [esp-4h] [ebp-4Ch]
  _DWORD v22[10]; // [esp+Ch] [ebp-3Ch] BYREF
  int v23; // [esp+34h] [ebp-14h]
  char v24; // [esp+38h] [ebp-10h]
  GRefCountNTSImpl *v25; // [esp+3Ch] [ebp-Ch]
  int v26; // [esp+40h] [ebp-8h] BYREF
  GRefCountNTSImpl *v27; // [esp+44h] [ebp-4h]

  v2 = *((_DWORD *)this + 4);
  v3 = *(_DWORD *)(*(_DWORD *)(v2 + 56) + 40);
  v20 = *(CBitVecT<CFixedBitVecBase<64> > **)(v2 + 44);
  v27 = nullptr;
  GFxImageCreator::LoadBuiltinImage(pfile: v20);
  v5 = v4;
  v25 = v4;
  if ( v4 != nullptr )
  {
    v6 = *((_DWORD *)this + 4);
    v7 = *(_DWORD *)(v6 + 32);
    v22[0] = 1;
    v22[4] = v5;
    v22[2] = 0;
    v22[1] = 0;
    v22[3] = 1;
    v22[5] = 0;
    memset(&v22[7], 0, 12);
    v22[6] = v7;
    v23 = 0;
    v24 = 0;
    if ( *(_BYTE *)(v6 + 68) != 0 || (v8 = *(_DWORD *)(v6 + 24) == 0, v24 = 0, !v8) )
      v24 = 1;
    v23 = v3;
    v9 = (struct GImageInfoBase *)(*(int (__thiscall **)(_DWORD, _DWORD *))(**(_DWORD **)(*(_DWORD *)(v6 + 8) + 16) + 4))(
                                    a1: *(_DWORD *)(*(_DWORD *)(v6 + 8) + 16),
                                    a2: v22);
    v27 = v9;
    if ( v9 != nullptr )
    {
      v10 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
      v26 = 2;
      v11 = (GFxImageResource *)v10(a1: v3, a2: 28, a3: &v26);
      if ( v11 != nullptr )
        v12 = GFxImageResource::GFxImageResource(this: v11, a2: v9, a3: Use_Bitmap);
      else
        v12 = nullptr;
      v13 = *((IShaderDevice **)this + 9);
      if ( v13 != nullptr )
        GFxResource::Release(this: v13);
      *((_DWORD *)this + 9) = v12;
    }
  }
  v14 = *((CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)this
        + 9);
  if ( v14 != nullptr )
  {
    v15 = *((_DWORD *)this + 5);
    v16 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 7) + 24))(a1: *((_DWORD *)this + 7));
    GFxMovieDataDef::LoadTaskData::InitImageFileMovieDef(
      this: *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(v15 + 32),
      fileLength: v16,
      pimageResource: v14,
      a4: true);
    v17 = *((_DWORD **)this + 5);
    v18 = *(GFxMovieDefImpl::BindTaskData **)(*((_DWORD *)this + 6) + 28);
    v21 = *(const CMemberFunctor1<COcclusionQueryMgr *,void (__thiscall COcclusionQueryMgr::*)(OcclusionQueryObjectHandle_t__ *),OcclusionQueryObjectHandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(v17[8] + 40);
    v19 = (*(int (__thiscall **)(_DWORD *))(*v17 + 64))(a1: v17);
    GFxMovieDefImpl::BindTaskData::UpdateBindingFrame(this: v18, frame: v19, bytesLoaded: v21);
    GFxMovieDefImpl::BindTaskData::SetBindState(
      this: *(IMatRenderContextInternal ***)(*((_DWORD *)this + 6) + 28),
      newState: 0x302u);
  }
  else
  {
    GFxMovieDefImpl::BindTaskData::SetBindState(
      this: *(IMatRenderContextInternal ***)(*((_DWORD *)this + 6) + 28),
      newState: 4u);
  }
  if ( v27 != nullptr )
    GRefCountNTSImpl::Release(this: v27);
  if ( v25 != nullptr )
    GRefCountNTSImpl::Release(this: v25);
}

//------------------------------------------------------------------------------
// Address: 0x100706D0
// Name: public: virtual GFxMovieImageLoadTask::~GFxMovieImageLoadTask(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieImageLoadTask::~GFxMovieImageLoadTask(CTSQueue<CFunctor *,0,1>::Node_t *this)
{
  IShaderDevice *v2; // ecx
  IShaderAPI *v3; // ecx
  IShaderDevice *v4; // ecx
  IShaderDevice *v5; // ecx
  int v6; // eax
  IShaderAPI *v7; // ecx

  v2 = *((IShaderDevice **)this + 9);
  if ( v2 != nullptr )
    GFxResource::Release(this: v2);
  v3 = *((IShaderAPI **)this + 7);
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  v4 = *((IShaderDevice **)this + 6);
  if ( v4 != nullptr )
    GFxResource::Release(this: v4);
  v5 = *((IShaderDevice **)this + 5);
  if ( v5 != nullptr )
    GFxResource::Release(this: v5);
  v6 = *((_DWORD *)this + 4);
  this->pNext = (CTSQueue<CFunctor *,0,1>::Node_t *)&GFxLoaderTask::`vftable';
  GFxLoaderImpl::UnRegisterLoadProcess(this: *(CCallQueueT<CTSQueue<CFunctor *,0,1> > **)(v6 + 60), ptask: this);
  v7 = *((IShaderAPI **)this + 4);
  if ( v7 != nullptr )
    GRefCountImpl::Release(this: v7);
  this->pNext = (CTSQueue<CFunctor *,0,1>::Node_t *)&GFxTask::`vftable';
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10070760
// Name: public: static class GFxMovieDefImpl __near * GFxLoaderImpl::CreateMovie_LoadState(class GFxLoadStates __near *,struct GFxURLBuilder::LocationInfo const __near &,unsigned int,struct GFxLoaderImpl::LoadStackItem __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
static IShaderDevice *__cdecl GFxLoaderImpl::CreateMovie_LoadState(
        CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > a1)
{
  void (__cdecl **m_pMemory)(int); // esi
  void (__cdecl *v2)(int); // ecx
  void (__cdecl *v3)(int); // edx
  bool v4; // zf
  unsigned int m_nGrowSize; // eax
  struct GFxImageCreator *LoadTimeImageCreator; // eax
  IShaderDevice *v7; // ebx
  IShaderDevice *v8; // edi
  __int64 v9; // rax
  void *v10; // esi
  void *v11; // esi
  LONG v12; // eax
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  unsigned int v15; // ebx
  int v16; // eax
  int v17; // edi
  struct GFxMovieDataDef *v18; // ebx
  GFxLoadProcess *v19; // eax
  GFxLoadProcess *Process; // edi
  void *v21; // esi
  void *v22; // esi
  void (__cdecl ***p_m_pElements)(int); // eax
  IShaderAPI *m_pElements; // edi
  void *v25; // ebx
  int v26; // edi
  struct GFxResource *v27; // eax
  GFxLogBase<GFxLog> *v28; // esi
  const char *Error; // eax
  IShaderAPI *v30; // ebx
  char v31; // al
  IShaderAPI *m_nAllocationCount; // edi
  GFxMovieImageLoadTask *v33; // eax
  IShaderAPI *Task; // ebx
  char v35; // al
  void (__cdecl **v36)(int); // esi
  IShaderDevice *v37; // ebx
  void *v38; // esi
  int v39; // [esp-Ch] [ebp-58h]
  CMemberFuncProxy1<CTexture_MultipleRenderTarget *,void (__thiscall CTexture_MultipleRenderTarget::*)(char const *),char const *,CFuncMemPolicyNone> v40; // [esp+Ch] [ebp-40h] BYREF
  int v41; // [esp+24h] [ebp-28h] BYREF
  volatile int Value; // [esp+28h] [ebp-24h] BYREF
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > v43; // [esp+2Ch] [ebp-20h] BYREF
  GFxLoadProcess *v44; // [esp+40h] [ebp-Ch] BYREF
  CUtlMemory<CImagePacker,int> var8; // [esp+44h] [ebp-8h] BYREF

  GString::GString(this: &var8);
  m_pMemory = a1.m_Memory.m_pMemory;
  GFxLoadStates::BuildURL(result: (CP4Factory *)&var8);
  v2 = m_pMemory[2];
  v3 = m_pMemory[3];
  *((_QWORD *)&v40.m_pfnProxied + 1) = 0;
  v4 = *((_DWORD *)v2 + 10) == 0;
  v43.m_Memory.m_nGrowSize = 0;
  HIBYTE(var8.m_nAllocationCount) = 0;
  Value = 0;
  v43.m_pElements = nullptr;
  v44 = nullptr;
  v43.m_Memory.m_nAllocationCount = 0;
  *((_DWORD *)&v40.m_pObject + 1) = 0;
  m_nGrowSize = a1.m_Memory.m_nGrowSize;
  v41 = (int)v3;
  if ( !v4 )
  {
    m_nGrowSize = a1.m_Memory.m_nGrowSize | 0x11;
    a1.m_Memory.m_nGrowSize |= 0x11u;
  }
  if ( (m_nGrowSize & 0x20) != 0 || (HIBYTE(a1.m_Memory.m_pMemory) = 0, (m_nGrowSize & 0x10) == 0) )
    HIBYTE(a1.m_Memory.m_pMemory) = 1;
  LoadTimeImageCreator = GFxLoadStates::GetLoadTimeImageCreator(this: (GFxLoadStates *)m_pMemory, a2: m_nGrowSize);
  v7 = *((IShaderDevice **)m_pMemory[2] + 2);
  v8 = (IShaderDevice *)LoadTimeImageCreator;
  if ( v7 != nullptr )
    LODWORD(v9) = ((int (__thiscall *)(IShaderDevice *, unsigned int))v7->GetBackBufferFormat)(
                    a1: v7,
                    a2: ((int)var8.m_pMemory & 0xFFFFFFFC) + 8);
  else
    v9 = 0;
  GFxMovieDataDef::CreateMovieFileKey(
    result: &v40,
    a2: (char *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 8),
    modifyTime: v9,
    ppreprocessParams: v7,
    a5: v8,
    a6: *((IShaderDevice **)m_pMemory[2] + 8));
  if ( GFxResourceWeakLib::BindResourceKey(
         this: (int)m_pMemory[14],
         result: (ShaderDeviceInfo_t *)((char *)&v40.m_pfnProxied + 8),
         a3: (int)&v40) != 3 )
  {
    v27 = GFxResourceLib::BindHandle::WaitForResolve(this: (GFxResourceLib::BindHandle *)&v40.m_pfnProxied + 1);
    v43.m_Size = (int)v27;
    if ( v27 == nullptr )
    {
      v28 = (GFxLogBase<GFxLog> *)v41;
      if ( v41 != 0 )
      {
        if ( SDWORD2(v40.m_pfnProxied) < 2 )
          Error = (const char *)&pMem;
        else
          Error = (const char *)GFxResourceLib::ResourceSlot::GetError(this: (CUtlBinaryBlock *)HIDWORD(v40.m_pfnProxied));
        GFxLogBase<GFxLog>::LogError(this: v28 + 3, pfmt: "Error: %s", Error);
      }
      if ( LODWORD(v40.m_pfnProxied) != 0 )
        (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD(v40.m_pfnProxied) + 8))(
          a1: v40.m_pfnProxied,
          a2: DWORD1(v40.m_pfnProxied));
      if ( DWORD2(v40.m_pfnProxied) != 1 )
      {
        if ( SDWORD2(v40.m_pfnProxied) >= 2 )
          GRefCountImpl::Release(this: (IShaderAPI *)HIDWORD(v40.m_pfnProxied));
        goto LABEL_21;
      }
LABEL_69:
      GFxResource::Release(this: (IShaderDevice *)HIDWORD(v40.m_pfnProxied));
      goto LABEL_21;
    }
    Value = v27[2].RefCount.Value;
    GFxLoadStates::SetRelativePathForDataDef(this: (GFxLoadStates *)m_pMemory, a2: (struct GFxMovieDataDef *)v27);
LABEL_55:
    v26 = Value;
    HIBYTE(a1.m_Memory.m_pMemory) = 0;
    v43.m_Memory.m_nGrowSize = (int)GFxLoaderImpl::CreateMovieDefImpl(
                                      loadConstants: (unsigned int)m_pMemory,
                                      a2: (IShaderDevice *)v43.m_Size,
                                      a3: a1.m_Memory.m_nGrowSize,
                                      a4: Value == 1 ? (struct GFxMovieBindProcess **)&v43.m_pElements : nullptr,
                                      checkCreate: false,
                                      ploadStack: (_SECURITY_QUALITY_OF_SERVICE *)a1.m_Size,
                                      memoryArena: (unsigned int)a1.m_pElements,
                                      justCreated: (bool *)&a1.m_Memory.m_pMemory + 3);
    if ( v26 == 2 && HIBYTE(a1.m_Memory.m_pMemory) != 0 )
      HIBYTE(var8.m_nAllocationCount) = 1;
    m_pElements = (IShaderAPI *)v43.m_pElements;
    goto LABEL_59;
  }
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v43);
  v43.m_Memory.m_nAllocationCount = (int)s_OpenAndDetectFile(
                                           a1: (const char *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 8),
                                           a2: (GFxLoadStates *)m_pMemory,
                                           a3: a1.m_Memory.m_nGrowSize,
                                           a4: (int *)&v40.m_pObject + 1,
                                           a5: &Value,
                                           a6: &v43);
  if ( v43.m_Memory.m_nAllocationCount == 0 )
  {
    if ( v41 != 0 )
      GFxLogBase<GFxLog>::LogError(
        this: (GFxLogBase<GFxLog> *)(v41 + 12),
        pfmt: "%s",
        (const char *)(((int)v43.m_Memory.m_pMemory & 0xFFFFFFFC) + 8));
    GFxResourceLib::ResourceSlot::CancelResolve(
      this: (GFxResourceLib::ResourceSlot *)HIDWORD(v40.m_pfnProxied),
      a2: (const char *)(((int)v43.m_Memory.m_pMemory & 0xFFFFFFFC) + 8));
    v10 = (void *)((int)v43.m_Memory.m_pMemory & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)v43.m_Memory.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v10);
    if ( LODWORD(v40.m_pfnProxied) != 0 )
      (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD(v40.m_pfnProxied) + 8))(
        a1: v40.m_pfnProxied,
        a2: DWORD1(v40.m_pfnProxied));
    if ( DWORD2(v40.m_pfnProxied) != 1 )
    {
      if ( SDWORD2(v40.m_pfnProxied) >= 2 )
        GRefCountImpl::Release(this: (IShaderAPI *)HIDWORD(v40.m_pfnProxied));
      goto LABEL_21;
    }
    goto LABEL_69;
  }
  Alloc_2 = GMemory::pGlobalHeap->Alloc_2;
  v15 = (int)var8.m_pMemory & 0xFFFFFFFC;
  v40.m_pObject = (CTexture_MultipleRenderTarget *)2;
  v16 = (int)Alloc_2(this: GMemory::pGlobalHeap, a2: 36u, a3: (const GAllocDebugInfo *)&v40.m_pObject);
  v17 = Value;
  if ( v16 != 0 )
    v18 = (struct GFxMovieDataDef *)GFxMovieDataDef::GFxMovieDataDef(
                                      this: v16,
                                      a2: (struct GFxResourceKey *)&v40,
                                      a3: Value,
                                      a4: v15 + 8,
                                      a5: 0,
                                      a6: (a1.m_Memory.m_nGrowSize & 0x10000000) != 0,
                                      a7: (int)a1.m_pElements);
  else
    v18 = nullptr;
  v43.m_Size = (int)v18;
  if ( v18 == nullptr )
  {
LABEL_37:
    GString::GString(
      this: (CUtlMemory<CImagePacker,int> *)&a1.m_Memory.m_nGrowSize,
      pdata1: (int)"Failed to load SWF file \"",
      pdata2: ((int)var8.m_pMemory & 0xFFFFFFFC) + 8);
    GFxResourceLib::ResourceSlot::CancelResolve(
      this: (GFxResourceLib::ResourceSlot *)HIDWORD(v40.m_pfnProxied),
      a2: (const char *)((a1.m_Memory.m_nGrowSize & 0xFFFFFFFC) + 8));
    v21 = (void *)(a1.m_Memory.m_nGrowSize & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((a1.m_Memory.m_nGrowSize & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v21);
    v22 = (void *)((int)v43.m_Memory.m_pMemory & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)v43.m_Memory.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v22);
    if ( LODWORD(v40.m_pfnProxied) != 0 )
      (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD(v40.m_pfnProxied) + 8))(
        a1: v40.m_pfnProxied,
        a2: DWORD1(v40.m_pfnProxied));
    GRefCountImpl::Release(this: (IShaderAPI *)v43.m_Memory.m_nAllocationCount);
    if ( v43.m_Size != 0 )
      GFxResource::Release(this: (IShaderDevice *)v43.m_Size);
    if ( DWORD2(v40.m_pfnProxied) == 1 )
    {
      GFxResource::Release(this: (IShaderDevice *)HIDWORD(v40.m_pfnProxied));
      v11 = (void *)((int)var8.m_pMemory & 0xFFFFFFFC);
      v12 = InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 4), Value: -1);
      goto LABEL_22;
    }
    if ( SDWORD2(v40.m_pfnProxied) >= 2 )
      GRefCountImpl::Release(this: (IShaderAPI *)HIDWORD(v40.m_pfnProxied));
LABEL_21:
    v11 = (void *)((int)var8.m_pMemory & 0xFFFFFFFC);
    v12 = InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 4), Value: -1);
LABEL_22:
    if ( v12 == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
    return nullptr;
  }
  GFxLoadStates::SetRelativePathForDataDef(this: (GFxLoadStates *)m_pMemory, a2: v18);
  if ( v17 != 1 )
  {
    p_m_pElements = nullptr;
    goto LABEL_50;
  }
  v44 = (GFxLoadProcess *)2;
  v19 = (GFxLoadProcess *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 808, a3: &v44);
  if ( v19 != nullptr )
    Process = GFxLoadProcess::GFxLoadProcess(
                this: v19,
                a2: v18,
                a3: (struct GFxLoadStates *)m_pMemory,
                a4: a1.m_Memory.m_nGrowSize);
  else
    Process = nullptr;
  v44 = Process;
  if ( Process == nullptr )
    goto LABEL_36;
  if ( !GFxLoadProcess::BeginSWFLoading(
          this: (GFxAmpMsgHandler *)Process,
          pfile: (const GFxAmpMessageSourceRequest *)v43.m_Memory.m_nAllocationCount) )
  {
    GRefCountImpl::Release(this: (IShaderAPI *)Process);
LABEL_36:
    GFxResource::Release(this: (IShaderDevice *)v18);
    v43.m_Size = 0;
    goto LABEL_37;
  }
  if ( HIBYTE(a1.m_Memory.m_pMemory) != 0 )
  {
    p_m_pElements = &v43.m_pElements;
LABEL_50:
    v43.m_Memory.m_nGrowSize = (int)GFxLoaderImpl::CreateMovieDefImpl(
                                      loadConstants: (unsigned int)m_pMemory,
                                      a2: (IShaderDevice *)v18,
                                      a3: a1.m_Memory.m_nGrowSize,
                                      a4: (struct GFxMovieBindProcess **)p_m_pElements,
                                      checkCreate: true,
                                      ploadStack: (_SECURITY_QUALITY_OF_SERVICE *)a1.m_Size,
                                      memoryArena: (unsigned int)a1.m_pElements,
                                      justCreated: nullptr);
  }
  m_pElements = (IShaderAPI *)v43.m_pElements;
  GFxResourceLib::ResourceSlot::Resolve(
    this: (GFxResourceLib::ResourceSlot *)HIDWORD(v40.m_pfnProxied),
    a2: (struct GFxResource *)v18);
  v25 = (void *)((int)v43.m_Memory.m_pMemory & 0xFFFFFFFC);
  HIBYTE(var8.m_nAllocationCount) = 1;
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)v43.m_Memory.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v25);
  if ( HIBYTE(a1.m_Memory.m_pMemory) == 0 )
  {
    if ( v43.m_Memory.m_nGrowSize != 0 )
      goto LABEL_90;
    goto LABEL_55;
  }
LABEL_59:
  if ( v43.m_Memory.m_nGrowSize == 0 )
  {
    if ( LODWORD(v40.m_pfnProxied) != 0 )
      (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD(v40.m_pfnProxied) + 8))(
        a1: v40.m_pfnProxied,
        a2: DWORD1(v40.m_pfnProxied));
    if ( v43.m_Memory.m_nAllocationCount != 0 )
      GRefCountImpl::Release(this: (IShaderAPI *)v43.m_Memory.m_nAllocationCount);
    if ( v44 != nullptr )
      GRefCountImpl::Release(this: (IShaderAPI *)v44);
    if ( m_pElements != nullptr )
      GRefCountImpl::Release(this: m_pElements);
    GFxResource::Release(this: (IShaderDevice *)v43.m_Size);
    if ( DWORD2(v40.m_pfnProxied) != 1 )
    {
      if ( SDWORD2(v40.m_pfnProxied) >= 2 )
        GRefCountImpl::Release(this: (IShaderAPI *)HIDWORD(v40.m_pfnProxied));
      goto LABEL_21;
    }
    goto LABEL_69;
  }
  if ( HIBYTE(var8.m_nAllocationCount) == 0 )
  {
    m_nAllocationCount = (IShaderAPI *)v43.m_Memory.m_nAllocationCount;
LABEL_136:
    v39 = (int)m_pMemory;
    v36 = v43.m_pElements;
    v37 = GFxLoaderImpl::BindMovieAndWait(
            result: (IShaderDevice *)v43.m_Memory.m_nGrowSize,
            pls: (int)v43.m_pElements,
            pls_4: v39,
            loadConstants: a1.m_Memory.m_nGrowSize,
            ploadStack: (_SECURITY_QUALITY_OF_SERVICE *)a1.m_Size);
    if ( LODWORD(v40.m_pfnProxied) != 0 )
      (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD(v40.m_pfnProxied) + 8))(
        a1: v40.m_pfnProxied,
        a2: DWORD1(v40.m_pfnProxied));
    if ( m_nAllocationCount != nullptr )
      GRefCountImpl::Release(this: m_nAllocationCount);
    if ( v44 != nullptr )
      GRefCountImpl::Release(this: (IShaderAPI *)v44);
    if ( v36 != nullptr )
      GRefCountImpl::Release(this: (IShaderAPI *)v36);
    GFxResource::Release(this: (IShaderDevice *)v43.m_Size);
    if ( DWORD2(v40.m_pfnProxied) == 1 )
    {
      GFxResource::Release(this: (IShaderDevice *)HIDWORD(v40.m_pfnProxied));
    }
    else if ( SDWORD2(v40.m_pfnProxied) >= 2 )
    {
      GRefCountImpl::Release(this: (IShaderAPI *)HIDWORD(v40.m_pfnProxied));
    }
    v38 = (void *)((int)var8.m_pMemory & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v38);
    return v37;
  }
LABEL_90:
  if ( Value == 1 )
  {
    if ( (a1.m_Memory.m_nGrowSize & 0x30) != 0 )
    {
      v30 = nullptr;
    }
    else
    {
      v30 = m_pElements;
      if ( m_pElements == nullptr )
      {
LABEL_97:
        if ( (a1.m_Memory.m_nGrowSize & 1) != 0
          || (GFxLoadStates::SubmitBackgroundTask(this: (CP4Factory *)m_pMemory), v31 == 0) )
        {
          ((void (__thiscall *)(GFxLoadProcess *))(*v44)->RefCount)(a1: v44);
        }
        if ( v30 != nullptr )
        {
          if ( m_pElements != nullptr )
            GRefCountImpl::Release(this: m_pElements);
          v43.m_pElements = nullptr;
        }
        if ( v44 != nullptr )
          GRefCountImpl::Release(this: (IShaderAPI *)v44);
        v44 = nullptr;
        if ( v43.m_Memory.m_nAllocationCount != 0 )
          GRefCountImpl::Release(this: (IShaderAPI *)v43.m_Memory.m_nAllocationCount);
        m_nAllocationCount = nullptr;
        goto LABEL_136;
      }
      GFxLoadProcess::SetBindProcess(this: v44, a2: (IShaderDevice *)m_pElements);
    }
    if ( m_pElements != nullptr )
      v44[180] = (GFxLoadProcess)m_pElements[12].__vftable;
    goto LABEL_97;
  }
  m_nAllocationCount = (IShaderAPI *)v43.m_Memory.m_nAllocationCount;
  if ( v43.m_Memory.m_nAllocationCount == 0 )
  {
    GString::GString(this: (CUtlMemory<CImagePacker,int> *)&a1);
    m_nAllocationCount = s_OpenAndDetectFile(
                           a1: (const char *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 8),
                           a2: (GFxLoadStates *)m_pMemory,
                           a3: a1.m_Memory.m_nGrowSize,
                           a4: (int *)&v40.m_pObject + 1,
                           a5: &Value,
                           a6: &a1);
    if ( m_nAllocationCount == nullptr )
    {
      if ( v41 != 0 )
        GFxLogBase<GFxLog>::LogError(
          this: (GFxLogBase<GFxLog> *)(v41 + 12),
          pfmt: "%s",
          (const char *)(((int)a1.m_Memory.m_pMemory & 0xFFFFFFFC) + 8));
      GFxResource::Release(this: (IShaderDevice *)v43.m_Memory.m_nGrowSize);
      GString::~GString(this: (GString *)&a1);
      if ( LODWORD(v40.m_pfnProxied) != 0 )
        (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD(v40.m_pfnProxied) + 8))(
          a1: v40.m_pfnProxied,
          a2: DWORD1(v40.m_pfnProxied));
      goto LABEL_115;
    }
    GString::~GString(this: (GString *)&a1);
  }
  v41 = 2;
  v33 = (GFxMovieImageLoadTask *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 40, a3: &v41);
  if ( v33 != nullptr )
    Task = (IShaderAPI *)GFxMovieImageLoadTask::GFxMovieImageLoadTask(
                           this: v33,
                           a2: (IShaderDevice *)v43.m_Size,
                           a3: (IShaderDevice *)v43.m_Memory.m_nGrowSize,
                           a4: (IShaderDevice *)m_nAllocationCount,
                           a5: *((enum GFxFileConstants::FileFormatType *)&v40.m_pObject + 1),
                           result: (IShaderDevice *)m_pMemory);
  else
    Task = nullptr;
  if ( (a1.m_Memory.m_nGrowSize & 0x11) == 0
    && (GFxLoadStates::SubmitBackgroundTask(this: (CP4Factory *)m_pMemory), v35 != 0)
    || (((void (__thiscall *)(IShaderAPI *))Task->GetLightmapDimensions)(a1: Task), Task[9].__vftable != nullptr) )
  {
    if ( Task != nullptr )
      GRefCountImpl::Release(this: Task);
    goto LABEL_136;
  }
  if ( v43.m_Memory.m_nGrowSize != 0 )
    GFxResource::Release(this: (IShaderDevice *)v43.m_Memory.m_nGrowSize);
  GRefCountImpl::Release(this: Task);
  if ( LODWORD(v40.m_pfnProxied) != 0 )
    (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD(v40.m_pfnProxied) + 8))(
      a1: v40.m_pfnProxied,
      a2: DWORD1(v40.m_pfnProxied));
  if ( m_nAllocationCount != nullptr )
    GRefCountImpl::Release(this: m_nAllocationCount);
LABEL_115:
  if ( v44 != nullptr )
    GRefCountImpl::Release(this: (IShaderAPI *)v44);
  if ( v43.m_pElements != nullptr )
    GRefCountImpl::Release(this: (IShaderAPI *)v43.m_pElements);
  GFxResource::Release(this: (IShaderDevice *)v43.m_Size);
  GFxResourceLib::BindHandle::~BindHandle(this: (CMemoryStack *)((char *)&v40.m_pfnProxied + 8));
  GString::~GString(this: (GString *)&var8);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10070F40
// Name: public: GFxExporterInfoImpl::~GFxExporterInfoImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxExporterInfoImpl::~GFxExporterInfoImpl(void **this)
{
  volatile LONG *v2; // esi
  volatile LONG *v3; // esi

  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(this + 7));
  v2 = (volatile LONG *)((unsigned int)*(this + 6) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  v3 = (volatile LONG *)((unsigned int)*(this + 5) & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v3 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v3);
}

//------------------------------------------------------------------------------
// Address: 0x10070FA0
// Name: public: class GFxMovieDef __near * GFxLoaderImpl::CreateMovie(char const __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
struct GFxMovieDef *__thiscall GFxLoaderImpl::CreateMovie(
        GFxLoaderImpl *this,
        char *a2,
        unsigned int loadConstants,
        void (__cdecl **memoryArena)(int))
{
  GFxLoadStates *v5; // eax
  GFxLoadStates *States; // edi
  IShaderDevice *Movie_LoadState; // eax
  void *v9; // esi
  void *v10; // esi
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > v11; // [esp-14h] [ebp-30h]
  int v12; // [esp+Ch] [ebp-10h] BYREF
  GString v13; // [esp+10h] [ebp-Ch] BYREF
  CUtlMemory<CImagePacker,int> var8; // [esp+14h] [ebp-8h] BYREF
  unsigned int loadConstantsa; // [esp+28h] [ebp+Ch]

  var8.m_nAllocationCount = 2;
  v5 = (GFxLoadStates *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 84, a3: &var8.m_nAllocationCount);
  if ( v5 != nullptr )
    States = GFxLoadStates::GFxLoadStates(this: v5, a2: (struct GFxLoaderImpl *)this, a3: nullptr, a4: nullptr);
  else
    States = nullptr;
  if ( (loadConstants & 0x40) != 0 )
    *((_BYTE *)States + 68) = 1;
  if ( *((_DWORD *)States + 14) != 0 )
  {
    v12 = 0;
    GString::GString(this: &v13, a2);
    GString::GString(this: &var8);
    v11.m_pElements = memoryArena;
    *(_QWORD *)&v11.m_Memory.m_nGrowSize = loadConstants;
    *(_QWORD *)&v11.m_Memory.m_pMemory = __PAIR64__(&v12, (unsigned int)States);
    Movie_LoadState = GFxLoaderImpl::CreateMovie_LoadState(a1: v11);
    v9 = (void *)((int)var8.m_pMemory & 0xFFFFFFFC);
    loadConstantsa = (unsigned int)Movie_LoadState;
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)var8.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
    v10 = (void *)(v13.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v13.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v10);
    GRefCountImpl::Release(this: (IShaderAPI *)States);
    return (struct GFxMovieDef *)loadConstantsa;
  }
  else
  {
    GRefCountImpl::Release(this: (IShaderAPI *)States);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100712A0
// Name: public: GFxMovieHeaderData::GFxMovieHeaderData(void)
// Source: json
//------------------------------------------------------------------------------
GFxMovieHeaderData *__thiscall GFxMovieHeaderData::GFxMovieHeaderData(GFxMovieHeaderData *this)
{
  *((_DWORD *)this + 1) = -1;
  *(_DWORD *)this = 0;
  *((float *)this + 2) = 0.0;
  *((float *)this + 3) = 0.0;
  *((float *)this + 4) = 0.0;
  *((float *)this + 5) = 0.0;
  *((_DWORD *)this + 8) = 0;
  *((float *)this + 6) = 1.0;
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)((char *)this + 56));
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)this + 5);
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_WORD *)this + 24) = 0;
  *((_DWORD *)this + 7) = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10071300
// Name: public: GFxStateBagImpl::GFxStateBagImpl(class GFxStateBagImpl __near *)
// Source: json
//------------------------------------------------------------------------------
GFxStateBagImpl *__thiscall GFxStateBagImpl::GFxStateBagImpl(GFxStateBagImpl *this, IShaderDevice *a2)
{
  IShaderAPI *v3; // ecx
  VertexShaderHandle_t__ *v5; // [esp+0h] [ebp-8h]

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = &GFxStateBag::`vftable';
  *((_DWORD *)this + 4) = &GFxLogBase<GFxLoadProcess>::`vftable';
  *(_DWORD *)this = &GFxStateBagImpl::`vftable'{for `GRefCountBase<GFxStateBagImpl,2>'};
  *((_DWORD *)this + 2) = &GFxStateBagImpl::`vftable'{for `GFxStateBag'};
  *((_DWORD *)this + 4) = &GFxStateBagImpl::`vftable'{for `GFxLogBase<GFxStateBagImpl>'};
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 28), spinCount: 0);
  if ( a2 != nullptr )
    GRefCountImpl::AddRef(this: a2, a2: v5);
  v3 = *((IShaderAPI **)this + 5);
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  *((_DWORD *)this + 5) = a2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10071590
// Name: public: virtual class GFxState __near * GFxStateBagImpl::GetStateAddRef(enum GFxState::StateType)const
// Source: json
//------------------------------------------------------------------------------
IShaderDevice *__userpurge GFxStateBagImpl::GetStateAddRef@<eax>(ISteamUserStats *this@<ecx>, unsigned __int64 key)
{
  _RTL_CRITICAL_SECTION *v3; // ebx
  int v4; // esi
  const char *v5; // eax
  IShaderDevice **v6; // esi
  IShaderDevice *v7; // esi
  int v9; // edi
  unsigned __int64 v10; // [esp-8h] [ebp-14h]
  VertexShaderHandle_t__ *v11; // [esp+0h] [ebp-Ch]

  v3 = (_RTL_CRITICAL_SECTION *)(this + 5);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 5));
  v4 = *((_DWORD *)this + 4);
  if ( v4 != 0
    && (HIDWORD(v10) = key & *(_DWORD *)(v4 + 4),
        LODWORD(v10) = &key,
        (int)(v5 = GHashSetBase<GFxStateBagImpl::StatePtr,GFxStateBagImpl::StatePtrHashOp,GFxStateBagImpl::StatePtrHashOp,GAllocatorGH<GFxStateBagImpl::StatePtr,2>,GHashsetCachedEntry<GFxStateBagImpl::StatePtr,GFxStateBagImpl::StatePtrHashOp>>::findIndexCore<enum GFxState::StateType>(
                     this: this + 4,
                     key: v10)) >= 0)
    && (v6 = (IShaderDevice **)(v4 + 12 * (_DWORD)v5 + 16)) != nullptr )
  {
    GRefCountImpl::AddRef(this: *v6, a2: v11);
    v7 = *v6;
    LeaveCriticalSection(lpCriticalSection: v3);
    return v7;
  }
  else
  {
    LeaveCriticalSection(lpCriticalSection: v3);
    v9 = *((_DWORD *)this + 3);
    if ( v9 != 0 )
      return (IShaderDevice *)(*(struct GFxState *(__thiscall **)(int, _DWORD))(*(_DWORD *)(v9 + 8) + 12))(
                                a1: v9 + 8,
                                a2: key);
    else
      return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071610
// Name: public: virtual void GFxStateBagImpl::GetStatesAddRef(class GFxState __near * __near *,enum GFxState::StateType const __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxStateBagImpl::GetStatesAddRef(
        GFxStateBagImpl *this@<ecx>,
        VertexShaderHandle_t__ *a2@<edi>,
        struct GFxState **a3,
        const enum GFxState::StateType *pstates,
        unsigned int count)
{
  GFxStateBagImpl *v5; // esi
  struct GFxState **v6; // edi
  int v7; // ebx
  ISteamUserStats *v8; // ecx
  int v9; // esi
  const char *v10; // eax
  IShaderDevice **v11; // esi
  int v12; // eax
  unsigned __int64 v13; // [esp-10h] [ebp-20h]
  VertexShaderHandle_t__ *v14; // [esp-8h] [ebp-18h]
  unsigned int i; // [esp+4h] [ebp-Ch]
  bool notFound; // [esp+Fh] [ebp-1h]

  v5 = this;
  notFound = false;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 20));
  if ( count != 0 )
  {
    v14 = a2;
    v6 = a3;
    v7 = (char *)pstates - (char *)a3;
    for ( i = count; i != 0; --i )
    {
      if ( *v6 == nullptr )
      {
        v8 = (ISteamUserStats *)((char *)v5 + 16);
        v9 = *((_DWORD *)v5 + 4);
        if ( v9 != 0
          && (HIDWORD(v13) = *(unsigned int *)((char *)v6 + v7) & *(_DWORD *)(v9 + 4),
              LODWORD(v13) = (char *)v6 + v7,
              (int)(v10 = GHashSetBase<GFxStateBagImpl::StatePtr,GFxStateBagImpl::StatePtrHashOp,GFxStateBagImpl::StatePtrHashOp,GAllocatorGH<GFxStateBagImpl::StatePtr,2>,GHashsetCachedEntry<GFxStateBagImpl::StatePtr,GFxStateBagImpl::StatePtrHashOp>>::findIndexCore<enum GFxState::StateType>(
                            this: v8,
                            key: v13)) >= 0)
          && (v11 = (IShaderDevice **)(v9 + 12 * (_DWORD)v10 + 16)) != nullptr )
        {
          GRefCountImpl::AddRef(this: *v11, a2: v14);
          *v6 = (struct GFxState *)*v11;
        }
        else
        {
          notFound = true;
        }
        v5 = this;
      }
      ++v6;
    }
  }
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)v5 + 20));
  if ( notFound )
  {
    v12 = *((_DWORD *)v5 + 3);
    if ( v12 != 0 )
      (*(void (__thiscall **)(int, struct GFxState **, const enum GFxState::StateType *, unsigned int))(*(_DWORD *)(v12 + 8) + 16))(
        a1: v12 + 8,
        a2: a3,
        a3: pstates,
        a4: count);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100716C0
// Name: public: virtual void GFxStateBagImpl::SetState(enum GFxState::StateType,class GFxState __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStateBagImpl::SetState(IDirect3DDevice9 *this, int naturalIndex, IShaderDevice *a3)
{
  _RTL_CRITICAL_SECTION *v4; // ebx
  struct GFxState *v5; // esi
  VertexShaderHandle_t__ *v6; // [esp+0h] [ebp-Ch]

  v4 = (_RTL_CRITICAL_SECTION *)(this + 5);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 5));
  v5 = (struct GFxState *)a3;
  if ( a3 != nullptr )
  {
    GRefCountImpl::AddRef(this: a3, a2: v6);
    a3 = (IShaderDevice *)v5;
    GHashSetBase<GFxStateBagImpl::StatePtr,GFxStateBagImpl::StatePtrHashOp,GFxStateBagImpl::StatePtrHashOp,GAllocatorGH<GFxStateBagImpl::StatePtr,2>,GHashsetCachedEntry<GFxStateBagImpl::StatePtr,GFxStateBagImpl::StatePtrHashOp>>::Set<GFxStateBagImpl::StatePtr>(this: this + 4);
    GRefCountImpl::Release(this: (IShaderAPI *)v5);
  }
  else
  {
    GHashSetBase<GFxStateBagImpl::StatePtr,GFxStateBagImpl::StatePtrHashOp,GFxStateBagImpl::StatePtrHashOp,GAllocatorGH<GFxStateBagImpl::StatePtr,2>,GHashsetCachedEntry<GFxStateBagImpl::StatePtr,GFxStateBagImpl::StatePtrHashOp>>::RemoveAlt<enum GFxState::StateType>((int)&naturalIndex);
  }
  LeaveCriticalSection(lpCriticalSection: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10071790
// Name: public: void GFxExporterInfoImpl::SetData(unsigned short,enum GFxFileConstants::FileFormatType,char const __near *,char const __near *,unsigned int,class GArray<unsigned long,2,struct GArrayDefaultPolicy> const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxExporterInfoImpl::SetData(
        char *this,
        __int16 a2,
        int a3,
        int a4,
        int a5,
        int a6,
        CThreadSemaphore *a)
{
  unsigned int v8; // edx
  CVertexBuilder *v9; // esi

  *((_WORD *)this + 6) = a2;
  *(_DWORD *)this = a3;
  GString::operator=(this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)this + 1);
  GString::operator=(this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(this + 24));
  v8 = *((_DWORD *)this + 6) & 0xFFFFFFFC;
  *((_DWORD *)this + 1) = (*((_DWORD *)this + 5) & 0xFFFFFFFC) + 8;
  *((_DWORD *)this + 2) = v8 + 8;
  *((_DWORD *)this + 4) = a6;
  if ( a != nullptr )
  {
    GArrayBase<GArrayData<unsigned long,GAllocatorGH<unsigned long,2>,GArrayDefaultPolicy>>::operator=(
      this: (CThreadSemaphore *)(this + 28),
      a);
    return;
  }
  v9 = (CVertexBuilder *)(this + 28);
  if ( v9->m_VertexSize_BoneWeight == 0 )
  {
    if ( v9->m_VertexSize_BoneMatrixIndex == 0 )
      GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
        this: v9,
        pheapAddr: (ButtonCode_t)v9,
        newCapacity: 0);
    goto LABEL_10;
  }
  if ( (v9->m_VertexSize_BoneMatrixIndex & 0xFFFFFFFE) == 0 )
  {
LABEL_10:
    v9->m_VertexSize_BoneWeight = 0;
    return;
  }
  if ( v9->m_VertexSize_Position != 0 )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v9->m_VertexSize_Position);
    v9->m_VertexSize_Position = 0;
  }
  v9->m_VertexSize_BoneMatrixIndex = 0;
  v9->m_VertexSize_BoneWeight = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10071850
// Name: public: void GFxExporterInfoImpl::ReadExporterInfoTag(class GFxStream __near *,enum GFxTagType)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __userpurge GFxExporterInfoImpl::ReadExporterInfoTag@<al>(
        char *a1@<ecx>,
        CUtlMemory<CImagePacker,int> a2)
{
  CImagePacker *m_pMemory; // esi
  int v3; // eax
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // ecx
  int v15; // ecx
  int v16; // ecx
  unsigned int v17; // ebx
  int v18; // edi
  int *v19; // ebx
  int v20; // edi
  void *v21; // esi
  unsigned int v22; // esi
  int v23; // eax
  unsigned int flags; // [esp+8h] [ebp-24h] BYREF
  unsigned int v26; // [esp+Ch] [ebp-20h]
  unsigned int v27; // [esp+10h] [ebp-1Ch]
  char *v28; // [esp+14h] [ebp-18h]
  int v29; // [esp+18h] [ebp-14h]
  int v30; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  int v32; // [esp+24h] [ebp-8h]
  struct GString v33; // [esp+28h] [ebp-4h] BYREF

  m_pMemory = a2.m_pMemory;
  v3 = a2.m_pMemory->m_pLightmapWavefront[10] - a2.m_pMemory->m_pLightmapWavefront[9];
  v28 = a1;
  v32 = 0;
  BYTE1(a2.m_pMemory->m_pLightmapWavefront[3]) = 0;
  if ( v3 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v4 = m_pMemory->m_pLightmapWavefront[9];
  v5 = (unsigned __int16)(*(unsigned __int8 *)(m_pMemory->m_pLightmapWavefront[13] + v4)
                        | (*(unsigned __int8 *)(m_pMemory->m_pLightmapWavefront[13] + v4 + 1) << 8));
  v6 = v4 + 2;
  v30 = v5;
  m_pMemory->m_pLightmapWavefront[9] = v6;
  if ( (unsigned __int16)v5 >= 0x10Au )
  {
    v7 = m_pMemory->m_pLightmapWavefront[10] - v6;
    BYTE1(m_pMemory->m_pLightmapWavefront[3]) = 0;
    if ( v7 < 4 )
      GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
    v8 = m_pMemory->m_pLightmapWavefront[9];
    v9 = *(unsigned __int8 *)(v8 + m_pMemory->m_pLightmapWavefront[13])
       | ((*(unsigned __int8 *)(v8 + m_pMemory->m_pLightmapWavefront[13] + 1)
         | (*(unsigned __int16 *)(v8 + m_pMemory->m_pLightmapWavefront[13] + 2) << 8)) << 8);
    m_pMemory->m_pLightmapWavefront[9] = v8 + 4;
    v32 = v9;
  }
  v10 = m_pMemory->m_pLightmapWavefront[10] - m_pMemory->m_pLightmapWavefront[9];
  BYTE1(m_pMemory->m_pLightmapWavefront[3]) = 0;
  if ( v10 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v11 = m_pMemory->m_pLightmapWavefront[9];
  v29 = *(unsigned __int16 *)(m_pMemory->m_pLightmapWavefront[13] + v11);
  m_pMemory->m_pLightmapWavefront[9] = v11 + 2;
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v33);
  GString::GString(this: &a2);
  GFxStream::ReadStringWithLength(this: (GFxStream *)m_pMemory, a2: &v33);
  GFxStream::ReadStringWithLength(this: (GFxStream *)m_pMemory, (struct GString *)&a2);
  flags = 0;
  v26 = 0;
  v27 = 0;
  if ( (unsigned __int16)v5 >= 0x36Fu )
  {
    v12 = m_pMemory->m_pLightmapWavefront[10] - m_pMemory->m_pLightmapWavefront[9];
    BYTE1(m_pMemory->m_pLightmapWavefront[3]) = 0;
    if ( v12 < 2 )
      GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
    v13 = m_pMemory->m_pLightmapWavefront[9];
    v14 = *(unsigned __int16 *)(m_pMemory->m_pLightmapWavefront[13] + v13);
    m_pMemory->m_pLightmapWavefront[9] = v13 + 2;
    if ( (_WORD)v14 != 0 )
    {
      for ( i = v14; i != 0; --i )
      {
        v15 = m_pMemory->m_pLightmapWavefront[10] - m_pMemory->m_pLightmapWavefront[9];
        BYTE1(m_pMemory->m_pLightmapWavefront[3]) = 0;
        if ( v15 < 4 )
          GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
        v16 = m_pMemory->m_pLightmapWavefront[9];
        v17 = v26 + 1;
        v18 = *(unsigned __int8 *)(v16 + m_pMemory->m_pLightmapWavefront[13])
            | ((*(unsigned __int8 *)(v16 + m_pMemory->m_pLightmapWavefront[13] + 1)
              | (*(unsigned __int16 *)(v16 + m_pMemory->m_pLightmapWavefront[13] + 2) << 8)) << 8);
        m_pMemory->m_pLightmapWavefront[9] = v16 + 4;
        if ( v17 >= v26 )
        {
          if ( v17 >= v27 )
            GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
              this: (CVertexBuilder *)&flags,
              pheapAddr: (ButtonCode_t)&flags,
              newCapacity: v17 + (v17 >> 2));
        }
        else if ( v17 < v27 >> 1 )
        {
          GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
            this: (CVertexBuilder *)&flags,
            pheapAddr: (ButtonCode_t)&flags,
            newCapacity: v17);
        }
        v26 = v17;
        v19 = (int *)(flags + 4 * v17 - 4);
        if ( v19 != nullptr )
          *v19 = v18;
      }
      LOWORD(v5) = v30;
    }
  }
  v20 = (unsigned __int16)v29;
  GFxLogBase<GFxStream>::LogParse(
    this: (tagBITMAPINFOHEADER *)m_pMemory,
    a2: (int)"  ExportInfo: tagType = %d, tool ver = %d.%d, imgfmt = %d, prefix = '%s', swfname = '%s', flags = 0x%X\n",
    a2.m_nAllocationCount,
    BYTE1(v5),
    (unsigned __int8)v5,
    (unsigned __int16)v29,
    (const char *)((v33.HeapTypeBits & 0xFFFFFFFC) + 8),
    (const char *)(((int)a2.m_pMemory & 0xFFFFFFFC) + 8),
    v32);
  GFxExporterInfoImpl::SetData(
    this: v28,
    a2: v5,
    a3: v20,
    a4: ((int)a2.m_pMemory & 0xFFFFFFFC) + 8,
    a5: (v33.HeapTypeBits & 0xFFFFFFFC) + 8,
    a6: v32,
    a: (CThreadSemaphore *)&flags);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)flags);
  v21 = (void *)((int)a2.m_pMemory & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)a2.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v21);
  v22 = v33.HeapTypeBits & 0xFFFFFFFC;
  v23 = InterlockedExchangeAdd(Addend: (volatile LONG *)((v33.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) - 1;
  if ( v23 == 0 )
    LOBYTE(v23) = ((unsigned __int8 (__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
                    a1: GMemory::pGlobalHeap,
                    a2: v22);
  return v23;
}

//------------------------------------------------------------------------------
// Address: 0x10071B10
// Name: public: bool GFxSWFProcessInfo::Initialize(class GFile __near *,class GFxLog __near *,class GFxZlibSupportBase __near *,class GFxParseControl __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxSWFProcessInfo::Initialize(
        GFxStream *this,
        IShaderDevice *a2,
        GFxLog *a3,
        struct GFxZlibSupportBase *a4,
        struct GFxParseControl *a5,
        int parseMsg)
{
  IShaderDevice *v6; // edi
  void (__thiscall *Present)(IShaderDevice *); // edx
  void (__thiscall *v9)(IShaderDevice *); // edx
  _LUID_AND_ATTRIBUTES *v10; // ebx
  unsigned int v11; // eax
  _LUID_AND_ATTRIBUTES *v12; // edx
  int v13; // ecx
  struct GFile *v15; // ebx
  struct GFxZlibSupportBase *v16; // ebx
  GFxLog *v17; // edi
  int v18; // ecx
  _LUID_AND_ATTRIBUTES *v19; // eax
  int v20; // ecx
  double v21; // st7
  int v22; // eax
  _LUID_AND_ATTRIBUTES *v23; // edx
  _LUID_AND_ATTRIBUTES *v24; // eax
  bool v25; // zf
  GFxStream *v26; // edi
  CUtlMemory<CImagePacker,int> v27; // [esp-8h] [ebp-18h]
  VertexShaderHandle_t__ *v28; // [esp+0h] [ebp-10h]
  const IShaderDeviceMgr *v29; // [esp+0h] [ebp-10h]
  unsigned int v30; // [esp+Ch] [ebp-4h] BYREF

  v6 = a2;
  *(this + 145) = (GFxStream)a2->GetAspectRatioInfo(this: a2);
  Present = v6->Present;
  v30 = 0;
  ((void (__thiscall *)(IShaderDevice *, unsigned int *, int))Present)(a1: v6, a2: &v30, a3: 4);
  v9 = v6->Present;
  a2 = nullptr;
  ((void (__thiscall *)(IShaderDevice *, IShaderDevice **, int))v9)(a1: v6, &a2, a3: 4);
  v10 = (_LUID_AND_ATTRIBUTES *)a2;
  *(this + 146) = (GFxStream)((char *)*(this + 145) + (_DWORD)a2);
  v11 = v30;
  v12 = (_LUID_AND_ATTRIBUTES *)HIBYTE(v30);
  *(this + 147) = nullptr;
  *(this + 156) = nullptr;
  HIBYTE(a2) = (_BYTE)v11 == 67;
  v13 = v11 & 0xFFFFFF;
  *(this + 148) = (GFxStream)v10;
  *(this + 149) = (GFxStream)v12;
  if ( (v11 & 0xFFFFFF) != 0x535746 && v13 != 5461827 && v13 != 5785159 && v13 != 5785155 )
  {
    if ( a3 != nullptr )
      GFxLogBase<GFxLog>::LogError(
        this: &a3->GFxLogBase<GFxLog>,
        pfmt: "Error: GFxLoader read failed - file does not start with a SWF header\n");
    return 0;
  }
  if ( (v11 & 0xFF0000) == 0x580000 )
    *(this + 156) = (GFxStream)16;
  if ( HIBYTE(a2) != 0 )
    *(this + 156) = (GFxStream)((unsigned int)*(this + 156) | 1);
  if ( a3 != nullptr && a5 != nullptr && (a5->ParseFlags & 1) != 0 )
  {
    if ( (_BYTE)parseMsg != 0 )
      GFxLog::LogMessageByType(
        this: a3,
        a2: Log_Channel_Parse,
        a3: "SWF File version = %d, File length = %d\n",
        v12,
        v10);
  }
  else
  {
    LOBYTE(parseMsg) = 0;
  }
  GRefCountImpl::AddRef(this: v6, a2: v28);
  v15 = (struct GFile *)v6;
  if ( HIBYTE(a2) != 0 )
  {
    v16 = a4;
    if ( a4 == nullptr )
    {
      if ( a3 != nullptr )
        GFxLogBase<GFxLog>::LogError(
          this: &a3->GFxLogBase<GFxLog>,
          pfmt: "Error: GFxLoader - unable to read compressed SWF data; GFxZlibState is not set.\n");
      GRefCountImpl::Release(this: (IShaderAPI *)v6);
      return 0;
    }
    if ( (_BYTE)parseMsg != 0 )
      GFxLog::LogMessageByType(this: a3, a2: Log_Channel_Parse, a3: "SWF file is compressed.\n");
    v15 = v16->CreateZlibFile(this: v16, a2: (GFile *)v6);
    GRefCountImpl::Release(this: (IShaderAPI *)v6);
    *(this + 146) = (GFxStream)((char *)&(**(this + 148))[0] - 8);
  }
  v17 = a3;
  GFxStream::Initialize(this, a2: v15, a3, a4: a5);
  GFxStream::ReadRect(this, a2: (int)(this + 150));
  v18 = (char *)*(this + 12) - (char *)*(this + 11);
  *((_BYTE *)this + 21) = 0;
  if ( v18 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v19 = (_LUID_AND_ATTRIBUTES *)*(this + 11);
  v20 = (int)*(this + 12);
  parseMsg = *(unsigned __int16 *)((char *)&(**(this + 15))[0].Luid.LowPart + (_DWORD)v19);
  v19 = (_LUID_AND_ATTRIBUTES *)((char *)v19 + 2);
  v21 = (double)parseMsg;
  *(this + 11) = (GFxStream)v19;
  *((_BYTE *)this + 21) = 0;
  *((float *)this + 154) = v21 * 0.00390625;
  if ( v20 - (int)v19 < 2 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v22 = (int)*(this + 11);
  v23 = (_LUID_AND_ATTRIBUTES *)(unsigned __int16)(*((unsigned __int8 *)&(**(this + 15))[0].Luid.LowPart + v22)
                                                 | (*((unsigned __int8 *)&(**(this + 15))[0].Luid.LowPart + v22 + 1) << 8));
  v24 = (_LUID_AND_ATTRIBUTES *)(v22 + 2);
  v25 = (*(_BYTE *)(this + 156) & 0x10) == 0;
  *(this + 11) = (GFxStream)v24;
  *(this + 155) = (GFxStream)v23;
  if ( v25 || (char *)v24 + (char *)*(this + 13) - (char *)*(this + 12) >= (char *)*(this + 146) )
    goto LABEL_36;
  if ( GFxStream::OpenTag(result: v29) == (const IShaderDeviceMgr *)1000 )
  {
    v27.m_nAllocationCount = 1000;
    v26 = this + 157;
    v27.m_pMemory = (CImagePacker *)this;
    GFxExporterInfoImpl::ReadExporterInfoTag(a1: (char *)this + 628, a2: v27);
    if ( (*(*v26 != nullptr ? (_WORD *)(v26 + 3) : (_WORD *)12) & 0xFF00u) >= 0x300
      && (*(*v26 != nullptr ? (_WORD *)(v26 + 3) : (_WORD *)12) & 0xFF00u) <= 0x400 )
    {
      GFxStream::CloseTag(this);
LABEL_36:
      if ( v15 != nullptr )
        GRefCountImpl::Release(this: (IShaderAPI *)v15);
      return 1;
    }
    if ( a3 != nullptr )
      GFxLogBase<GFxLog>::LogError(
        this: &a3->GFxLogBase<GFxLog>,
        pfmt: "Error: GFxLoader read failed - incompatible GFX file, version 3-4.x expected\n");
  }
  else if ( v17 != nullptr )
  {
    GFxLogBase<GFxLog>::LogError(
      this: &v17->GFxLogBase<GFxLog>,
      pfmt: "Error: GFxLoader read failed - no ExporterInfo tag in GFX file header\n");
  }
  if ( v15 != nullptr )
    GRefCountImpl::Release(this: (IShaderAPI *)v15);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10071E30
// Name: public: GFxLoaderImpl::GFxLoaderImpl(class GFxResourceLib __near *,bool)
// Source: json
//------------------------------------------------------------------------------
tagDROPSTRUCT *__thiscall GFxLoaderImpl::GFxLoaderImpl(char *this, tagDROPSTRUCT *result, bool debugHeap)
{
  unsigned int wFmt; // edi
  IShaderAPI *v5; // ecx
  char *v6; // eax
  char *v7; // edi
  IShaderAPI *v8; // ecx
  IShaderAPI *v9; // ecx
  IShaderAPI *v10; // eax
  IShaderAPI *v11; // edi
  IShaderAPI *v12; // eax
  IShaderAPI *v13; // edi
  IMaterial *v14; // eax
  IShaderAPI *v15; // eax
  IShaderAPI *v16; // edi
  CBaseAutoPtr<IMatRenderContext> *v17; // eax
  IShaderAPI *v18; // eax
  IShaderAPI *v19; // edi
  GFxTextKeyMap *v20; // eax
  GenericThreadLocals::CThreadLocalPtr<IMatRenderContextInternal> *v21; // eax
  IShaderAPI *inited; // edi
  VertexShaderHandle_t__ *v24; // [esp+0h] [ebp-24h]
  int v25; // [esp+Ch] [ebp-18h] BYREF
  int v26; // [esp+10h] [ebp-14h] BYREF
  int v27; // [esp+14h] [ebp-10h] BYREF
  int v28; // [esp+18h] [ebp-Ch] BYREF
  int v29; // [esp+1Ch] [ebp-8h] BYREF
  int v30; // [esp+20h] [ebp-4h] BYREF

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = &GFxStateBag::`vftable';
  *((_DWORD *)this + 4) = &GFxLogBase<GFxLoadProcess>::`vftable';
  *(_DWORD *)this = &GFxLoaderImpl::`vftable'{for `GRefCountBase<GFxLoaderImpl,2>'};
  *((_DWORD *)this + 2) = &GFxLoaderImpl::`vftable'{for `GFxStateBag'};
  *((_DWORD *)this + 4) = &GFxLoaderImpl::`vftable'{for `GFxLogBase<GFxLoaderImpl>'};
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = this + 28;
  *((_DWORD *)this + 8) = this + 28;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)(this + 36), spinCount: 0);
  *(this + 60) = debugHeap;
  if ( result != nullptr )
  {
    wFmt = result->wFmt;
    if ( wFmt != 0 )
      GRefCountImpl::AddRef(this: (IShaderDevice *)result->wFmt, a2: v24);
    v5 = *((IShaderAPI **)this + 6);
    if ( v5 != nullptr )
      GRefCountImpl::Release(this: v5);
    *((_DWORD *)this + 6) = wFmt;
  }
  v30 = 2;
  v6 = (char *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 52, a3: &v30);
  v7 = v6;
  if ( v6 != nullptr )
  {
    *(_DWORD *)v6 = &GRefCountImplCore::`vftable';
    *((_DWORD *)v6 + 1) = 1;
    *((_DWORD *)v6 + 2) = &GFxStateBag::`vftable';
    *((_DWORD *)v6 + 4) = &GFxLogBase<GFxLoadProcess>::`vftable';
    *(_DWORD *)v6 = &GFxStateBagImpl::`vftable'{for `GRefCountBase<GFxStateBagImpl,2>'};
    *((_DWORD *)v6 + 2) = &GFxStateBagImpl::`vftable'{for `GFxStateBag'};
    *((_DWORD *)v6 + 4) = &GFxStateBagImpl::`vftable'{for `GFxLogBase<GFxStateBagImpl>'};
    *((_DWORD *)v6 + 5) = 0;
    *((_DWORD *)v6 + 6) = 0;
    GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)(v6 + 28), spinCount: 0);
    v8 = *((IShaderAPI **)v7 + 5);
    if ( v8 != nullptr )
      GRefCountImpl::Release(this: v8);
    *((_DWORD *)v7 + 5) = 0;
  }
  else
  {
    v7 = nullptr;
  }
  v9 = *((IShaderAPI **)this + 5);
  if ( v9 != nullptr )
    GRefCountImpl::Release(this: v9);
  *((_DWORD *)this + 5) = v7;
  if ( v7 != nullptr )
  {
    v29 = 2;
    v10 = (IShaderAPI *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 16, a3: &v29);
    if ( v10 != nullptr )
    {
      v10->__vftable = (IShaderAPI_vtbl *)&GRefCountImplCore::`vftable';
      v10[1].__vftable = (IShaderAPI_vtbl *)1;
      v10[2].__vftable = (IShaderAPI_vtbl *)4;
      v10[3].__vftable = (IShaderAPI_vtbl *)&GFxLogBase<GFxLog>::`vftable';
      v10->__vftable = (IShaderAPI_vtbl *)&GFxLog::`vftable'{for `GFxState'};
      v10[3].__vftable = (IShaderAPI_vtbl *)&GFxLog::`vftable'{for `GFxLogBase<GFxLog>'};
      v11 = v10;
    }
    else
    {
      v11 = nullptr;
    }
    (*(void (__thiscall **)(int, int, IShaderAPI *))(*(_DWORD *)(*((_DWORD *)this + 5) + 8) + 8))(
      a1: *((_DWORD *)this + 5) + 8,
      a2: 4,
      a3: v11);
    if ( v11 != nullptr )
      GRefCountImpl::Release(this: v11);
    v28 = 2;
    v12 = (IShaderAPI *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 16, a3: &v28);
    if ( v12 != nullptr )
    {
      v12->__vftable = (IShaderAPI_vtbl *)&GRefCountImplCore::`vftable';
      v12[1].__vftable = (IShaderAPI_vtbl *)1;
      v12[2].__vftable = (IShaderAPI_vtbl *)12;
      v12->__vftable = (IShaderAPI_vtbl *)&GFxImageCreator::`vftable';
      LOBYTE(v12[3].__vftable) = 0;
      v13 = v12;
    }
    else
    {
      v13 = nullptr;
    }
    (*(void (__thiscall **)(int, int, IShaderAPI *))(*(_DWORD *)(*((_DWORD *)this + 5) + 8) + 8))(
      a1: *((_DWORD *)this + 5) + 8,
      a2: 12,
      a3: v13);
    if ( v13 != nullptr )
      GRefCountImpl::Release(this: v13);
    (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)(*((_DWORD *)this + 5) + 8) + 8))(
      a1: *((_DWORD *)this + 5) + 8,
      a2: 17,
      a3: 0);
    v27 = 2;
    v14 = (IMaterial *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 76, a3: &v27);
    if ( v14 != nullptr )
    {
      GFxFontCacheManager::GFxFontCacheManager(this: v14, enableDynamicCache: (const IMaterial *)1);
      v16 = v15;
    }
    else
    {
      v16 = nullptr;
    }
    (*(void (__thiscall **)(int, int, IShaderAPI *))(*(_DWORD *)(*((_DWORD *)this + 5) + 8) + 8))(
      a1: *((_DWORD *)this + 5) + 8,
      a2: 18,
      a3: v16);
    if ( v16 != nullptr )
      GRefCountImpl::Release(this: v16);
    v26 = 2;
    v17 = (CBaseAutoPtr<IMatRenderContext> *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 32, a3: &v26);
    if ( v17 != nullptr )
    {
      LOBYTE(v18) = GFxTextClipboard::GFxTextClipboard(this: v17, a2: (int)v24);
      v19 = v18;
    }
    else
    {
      v19 = nullptr;
    }
    (*(void (__thiscall **)(int, int, IShaderAPI *))(*(_DWORD *)(*((_DWORD *)this + 5) + 8) + 8))(
      a1: *((_DWORD *)this + 5) + 8,
      a2: 24,
      a3: v19);
    if ( v19 != nullptr )
      GRefCountImpl::Release(this: v19);
    v25 = 2;
    v20 = (GFxTextKeyMap *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 24, a3: &v25);
    if ( v20 != nullptr )
      v21 = (GenericThreadLocals::CThreadLocalPtr<IMatRenderContextInternal> *)GFxTextKeyMap::GFxTextKeyMap(this: v20);
    else
      v21 = nullptr;
    inited = (IShaderAPI *)GFxTextKeyMap::InitWindowsKeyMap(this: v21);
    (*(void (__thiscall **)(int, int, IShaderAPI *))(*(_DWORD *)(*((_DWORD *)this + 5) + 8) + 8))(
      a1: *((_DWORD *)this + 5) + 8,
      a2: 25,
      a3: inited);
    if ( inited != nullptr )
      GRefCountImpl::Release(this: inited);
  }
  return (tagDROPSTRUCT *)this;
}

//------------------------------------------------------------------------------
// Address: 0x100DB640
// Name: public: GFxImageResource::GFxImageResource(class GImageInfoBase __near *,class GFxResourceKey const __near &,enum GFxResource::ResourceUse)
// Source: json
//------------------------------------------------------------------------------
GFxImageResource *__thiscall GFxImageResource::GFxImageResource(
        GFxImageResource *this,
        struct GImageInfoBase *a2,
        IShaderDevice *src,
        enum GFxResource::ResourceUse a4)
{
  GRefCountNTSImpl *v5; // ecx

  *this = (GFxImageResource)&GFxResource::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = 0;
  *this = (GFxImageResource)&GFxImageResource::`vftable';
  *((_DWORD *)this + 3) = 0;
  GFxResourceKey::GFxResourceKey(this: (GFxValue *)this + 1);
  if ( a2 != nullptr )
    ++a2->RefCount;
  v5 = *((GRefCountNTSImpl **)this + 3);
  if ( v5 != nullptr )
    GRefCountNTSImpl::Release(this: v5);
  *((_DWORD *)this + 3) = a2;
  GFxResourceKey::operator=(this: (IShaderDevice *)this + 4, src);
  *((_DWORD *)this + 6) = a4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013F980
// Name: public: GHashsetCachedEntry<class GPtr<class GFxVideoProvider>,class GFixedSizeHash<class GPtr<class GFxVideoProvider>>>::GHashsetCachedEntry<class GPtr<class GFxVideoProvider>,class GFixedSizeHash<class GPtr<class GFxVideoProvider>>>(class GHashsetCachedEntry<class GPtr<class GFxVideoProvider>,class GFixedSizeHash<class GPtr<class GFxVideoProvider>>> const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GHashsetCachedEntry<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>>::GHashsetCachedEntry<GPtr<GFxVideoProvider>,GFixedSizeHash<GPtr<GFxVideoProvider>>>(
        _DWORD *this,
        _DWORD *a2)
{
  _DWORD *result; // eax
  int v3; // edx

  result = this;
  *this = *a2;
  *(this + 1) = a2[1];
  v3 = a2[2];
  if ( v3 != 0 )
    ++*(_DWORD *)(v3 + 4);
  *(this + 2) = a2[2];
  return result;
}
