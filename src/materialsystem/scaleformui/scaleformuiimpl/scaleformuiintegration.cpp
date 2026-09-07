// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/scaleformuiimpl/scaleformuiintegration.cpp
// Functions: 53
// ============================================================

#include "materialsystem\scaleformui\scaleformuiimpl\scaleformuiintegration.h"

//------------------------------------------------------------------------------
// Address: 0x10004F60
// Name: public: static void __near * GRefCountBaseStatImpl<class GRefCountNTSImpl,3>::operator new(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GRefCountBaseStatImpl<GRefCountNTSImpl,3>::operator new(unsigned int sz)
{
  int v2; // [esp+0h] [ebp-4h] BYREF

  v2 = 3;
  return GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: sz, a3: (const GAllocDebugInfo *)&v2);
}

//------------------------------------------------------------------------------
// Address: 0x100117B0
// Name: void __near * MemAlloc_AllocAlignedUnattributed(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_AllocAlignedUnattributed(unsigned int size, unsigned int align)
{
  unsigned int v2; // eax
  void *result; // eax
  unsigned int v4; // esi

  v2 = align;
  if ( ((align - 1) & align) != 0 )
    return nullptr;
  if ( align <= 4 )
    v2 = 4;
  v4 = v2 - 1;
  result = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size + v2 - 1 + 4);
  if ( result != nullptr )
  {
    *(_DWORD *)((~v4 & ((unsigned int)result + v4 + 4)) - 4) = result;
    return (void *)(~v4 & ((unsigned int)result + v4 + 4));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011800
// Name: void __near * MemAlloc_ReallocAligned(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl MemAlloc_ReallocAligned(unsigned __int8 *ptr, unsigned int size, unsigned int align)
{
  void *v4; // ebx
  unsigned int v5; // esi
  unsigned __int8 *pResult; // [esp+10h] [ebp+10h]

  if ( ((align - 1) & align) != 0 )
    return nullptr;
  if ( ((align - 1) & (unsigned int)ptr) != 0 )
    return nullptr;
  if ( ptr == nullptr )
    return (unsigned __int8 *)MemAlloc_AllocAlignedUnattributed(size, align);
  v4 = *(void **)(((unsigned int)ptr & 0xFFFFFFFC) - 4);
  v5 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: v4);
  if ( v5 >= ptr - (_BYTE *)v4 + size )
    return ptr;
  pResult = (unsigned __int8 *)MemAlloc_AllocAlignedUnattributed(size, align);
  memcpy(dst: pResult, src: ptr, count: v5 - (ptr - (_BYTE *)v4));
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
  return pResult;
}

//------------------------------------------------------------------------------
// Address: 0x100118A0
// Name: public: virtual void __near * MySysAlloc::Alloc(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall MySysAlloc::Alloc(MySysAlloc *this, unsigned int size, unsigned int align)
{
  unsigned int v3; // eax
  void *result; // eax
  unsigned int v5; // esi

  v3 = align;
  if ( ((align - 1) & align) != 0 )
    return nullptr;
  if ( align <= 4 )
    v3 = 4;
  v5 = v3 - 1;
  result = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v3 - 1 + size + 4);
  if ( result != nullptr )
  {
    *(_DWORD *)((~v5 & ((unsigned int)result + v5 + 4)) - 4) = result;
    return (void *)(~v5 & ((unsigned int)result + v5 + 4));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011900
// Name: public: virtual void MySysAlloc::Free(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MySysAlloc::Free(MySysAlloc *this, unsigned int ptr, unsigned int size, unsigned int align)
{
  if ( ptr != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)((ptr & 0xFFFFFFFC) - 4));
}

//------------------------------------------------------------------------------
// Address: 0x10011930
// Name: public: virtual void __near * MySysAlloc::Realloc(void __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall MySysAlloc::Realloc(
        MySysAlloc *this,
        unsigned __int8 *oldPtr,
        unsigned int oldSize,
        unsigned int newSize,
        unsigned int align)
{
  return MemAlloc_ReallocAligned(ptr: oldPtr, size: newSize, align);
}

//------------------------------------------------------------------------------
// Address: 0x10011950
// Name: public: virtual void ScaleformTranslatorAdapter::Translate(class GFxTranslator::TranslateInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformTranslatorAdapter::Translate(
        ScaleformTranslatorAdapter *this,
        GFxTranslator::TranslateInfo *tinfo)
{
  GFxTranslator::TranslateInfo *v2; // esi
  const wchar_t *v3; // eax
  int v4; // edi
  void *v5; // esp
  const wchar_t *v6; // eax
  char v7[12]; // [esp+0h] [ebp-10h] BYREF
  const wchar_t *pkey; // [esp+Ch] [ebp-4h]

  v2 = tinfo;
  v3 = tinfo->pKey;
  pkey = v3;
  if ( v3 != nullptr && *v3 == 35 )
  {
    v4 = G_wcslen(pwch: v3) + 1;
    v5 = alloca(v4);
    _V_UnicodeToUTF8(a1: pkey, a2: v7, a3: v4);
    HIBYTE(tinfo) = 0;
    v6 = ScaleformUIImpl::Translate(this: &ScaleformUIImpl::m_Instance, key: v7, pIsHTML: (bool *)&tinfo + 3);
    GFxTranslator::TranslateInfo::SetResult(this: v2, pwch: v6, a3: 0xFFFFFFFF);
    v2->Flags |= 2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100119C0
// Name: public: virtual void ScaleformFunctionHandlerAdapter::Call(struct GFxFunctionHandler::Params const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFunctionHandlerAdapter::Call(
        ScaleformFunctionHandlerAdapter *this,
        const GFxFunctionHandler::Params *params)
{
  void (__thiscall **pUserData)(int, ScaleformUIImpl *, const GFxFunctionHandler::Params *); // eax

  pUserData = (void (__thiscall **)(int, ScaleformUIImpl *, const GFxFunctionHandler::Params *))params->pUserData;
  if ( pUserData != nullptr )
    pUserData[6](a1: (int)pUserData[7] + (_DWORD)pUserData[4], a2: &ScaleformUIImpl::m_Instance, a3: params);
}

//------------------------------------------------------------------------------
// Address: 0x100119F0
// Name: public: virtual void ScaleformCallbackHolder::OnDestroy(class GFxMovieView __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall ScaleformCallbackHolder::OnDestroy(
        ScaleformCallbackHolder *this,
        GFxMovieView *pmovie,
        GFxMovieView *pobject)
{
  GRefCountImpl::Release((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10011A00
// Name: public: virtual class GFile __near * ScaleformFileOpener::OpenFile(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
GFile *__thiscall ScaleformFileOpener::OpenFile(ScaleformFileOpener *this, const char *purl, int flags, int modes)
{
  return this->OpenFileEx(this, a2: purl, a3: nullptr, a4: flags, a5: modes);
}

//------------------------------------------------------------------------------
// Address: 0x10011A20
// Name: public: virtual __int64 ScaleformFileOpener::GetFileModifyTime(char const __near *)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall ScaleformFileOpener::GetFileModifyTime(ScaleformFileOpener *this, const char *purl)
{
  return (g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: purl, a3: "GAME") != 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10011A70
// Name: public: void GFxLogBase<class GFxLog>::LogError(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
void GFxLogBase<GFxLog>::LogError(GFxLogBase<GFxLog> *this, const char *pfmt, ...)
{
  va_list va; // [esp+10h] [ebp+10h] BYREF

  va_start(va, pfmt);
  if ( this != nullptr )
    (*(void (__thiscall **)(GFxLogBase<GFxLog> *, int, const char *, char *))(*((_DWORD *)this - 3) + 4))(
      a1: this - 3,
      a2: 16,
      a3: pfmt,
      a4: va);
  else
    (*(void (__stdcall **)(int, const char *, char *))(MEMORY[0] + 4))(a1: 16, a2: pfmt, a3: va);
}

//------------------------------------------------------------------------------
// Address: 0x10011AB0
// Name: public: GString::~GString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GString::~GString(GString *this)
{
  volatile LONG *v1; // esi

  v1 = (volatile LONG *)(this->HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v1 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v1);
}

//------------------------------------------------------------------------------
// Address: 0x10011AE0
// Name: public: virtual void ScaleformUILogging::LogMessageVarg(enum GFxLogConstants::LogMessageType,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUILogging::LogMessageVarg(
        ScaleformUILogging *this,
        GFxLogConstants::LogMessageType messageType,
        const char *pfmt,
        char *argList)
{
  int v4; // edi
  BOOL v5; // esi
  char formattedMessage[2048]; // [esp+8h] [ebp-800h] BYREF

  switch ( messageType & 0xF0 )
  {
    case ' ':
      v4 = LOG_SCALEFORM_SCRIPT;
      break;
    case '0':
      v4 = LOG_SCALEFORM_PARSE;
      break;
    case '@':
      v4 = LOG_SCALEFORM_AS;
      break;
    default:
      v4 = LOG_SCALEFORM;
      break;
  }
  v5 = (messageType & 3u) < 2;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: v4, a2: v5) != 0 )
  {
    _vsnprintf(string: formattedMessage, count: 0x800u, format: pfmt, ap: argList);
    _LoggingSystem_LogDirect(a1: v4, a2: v5, a3: -19276, a4: formattedMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011BE0
// Name: public: virtual class GImageInfoBase __near * ScaleformImageLoader::LoadImageA(char const __near *)
// Source: json
//------------------------------------------------------------------------------
GImageInfo *__thiscall ScaleformImageLoader::LoadImageA(ScaleformImageLoader *this, const char *purl)
{
  const char *v2; // edi
  unsigned __int64 v4; // rax
  ScaleformUIAvatarImage *AvatarImage; // esi
  GImageInfo *v6; // edi
  ScaleformTexture *Texture; // eax

  v2 = purl;
  if ( V_strncmp(s1: purl, s2: "img://avatar_", count: 13) != 0 )
    return nullptr;
  v4 = V_atoi64(str: v2 + 13);
  AvatarImage = ScaleformUIImpl::GetAvatarImage(this: (ScaleformUIImpl *)this->m_pScaleformUI, playerID: v4);
  if ( AvatarImage == nullptr )
    return nullptr;
  purl = (const char *)2;
  v6 = (GImageInfo *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 40, a3: &purl);
  if ( v6 == nullptr )
    return nullptr;
  Texture = ScaleformUIAvatarImage::GetTexture(this: AvatarImage);
  return GImageInfo::GImageInfo(this: v6, a2: Texture, a3: 0x40u, a4: 0x40u);
}

//------------------------------------------------------------------------------
// Address: 0x10011CA0
// Name: public: virtual GFile::~GFile(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall GFile::~GFile(GFile *this)
{
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10011CB0
// Name: public: virtual bool SFUIMemoryFile::IsValid(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SFUIMemoryFile::IsValid(SFUIMemoryFile *this)
{
  return this->m_valid;
}

//------------------------------------------------------------------------------
// Address: 0x10011CD0
// Name: public: virtual __int64 SFUIMemoryFile::LTell(void)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall SFUIMemoryFile::LTell(SFUIMemoryFile *this)
{
  return this->m_fileIndex;
}

//------------------------------------------------------------------------------
// Address: 0x10011CE0
// Name: public: virtual int SFUIMemoryFile::GetLength(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall SFUIMemoryFile::GetLength(SFUIMemoryFile *this)
{
  return this->m_fileSize;
}

//------------------------------------------------------------------------------
// Address: 0x10011CF0
// Name: public: virtual __int64 SFUIMemoryFile::LGetLength(void)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall SFUIMemoryFile::LGetLength(SFUIMemoryFile *this)
{
  return this->m_fileSize;
}

//------------------------------------------------------------------------------
// Address: 0x10011D00
// Name: public: virtual bool SFUIMemoryFile::Close(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SFUIMemoryFile::Close(SFUIMemoryFile *this)
{
  this->m_valid = false;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10011D10
// Name: public: virtual int SFUIMemoryFile::Read(unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall SFUIMemoryFile::Read(SFUIMemoryFile *this, unsigned __int8 *pbufer, int numBytes)
{
  int m_fileIndex; // ecx
  int m_fileSize; // eax
  int v6; // edi

  m_fileIndex = this->m_fileIndex;
  m_fileSize = this->m_fileSize;
  v6 = numBytes;
  if ( m_fileIndex + numBytes > m_fileSize )
    v6 = m_fileSize - m_fileIndex;
  if ( v6 > 0 )
  {
    _V_memcpy(dest: pbufer, src: &this->m_fileData[m_fileIndex], count: v6);
    this->m_fileIndex += v6;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10011D50
// Name: public: virtual int SFUIMemoryFile::SkipBytes(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall SFUIMemoryFile::SkipBytes(SFUIMemoryFile *this, int numBytes)
{
  int result; // eax
  int m_fileSize; // edx
  int m_fileIndex; // esi

  result = numBytes;
  m_fileSize = this->m_fileSize;
  m_fileIndex = this->m_fileIndex;
  if ( m_fileIndex + numBytes > m_fileSize )
    result = m_fileSize - m_fileIndex;
  this->m_fileIndex = result + m_fileIndex;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011D80
// Name: public: virtual int SFUIMemoryFile::BytesAvailable(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall SFUIMemoryFile::BytesAvailable(SFUIMemoryFile *this)
{
  return this->m_fileSize - this->m_fileIndex;
}

//------------------------------------------------------------------------------
// Address: 0x10011D90
// Name: public: virtual int SFUIMemoryFile::Seek(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall SFUIMemoryFile::Seek(SFUIMemoryFile *this, int offset, int origin)
{
  int result; // eax

  if ( origin != 0 )
  {
    if ( origin == 1 )
    {
      this->m_fileIndex += offset;
      return this->m_fileIndex;
    }
    if ( origin == 2 )
    {
      result = this->m_fileSize - offset;
      this->m_fileIndex = result;
      return result;
    }
  }
  else
  {
    this->m_fileIndex = offset;
  }
  return this->m_fileIndex;
}

//------------------------------------------------------------------------------
// Address: 0x10011DD0
// Name: public: virtual bool SFUIMemoryFile::ChangeSize(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SFUIMemoryFile::ChangeSize(SFUIMemoryFile *this, int newSize)
{
  if ( newSize > this->m_buffer.m_Memory.m_nAllocationCount )
    return 0;
  this->m_fileSize = newSize;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10011DF0
// Name: public: virtual SFUIMemoryFile::~SFUIMemoryFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFUIMemoryFile::~SFUIMemoryFile(SFUIMemoryFile *this)
{
  volatile LONG *v2; // esi

  if ( this->m_buffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_buffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_buffer.m_Memory.m_pMemory);
      this->m_buffer.m_Memory.m_pMemory = nullptr;
    }
    this->m_buffer.m_Memory.m_nAllocationCount = 0;
  }
  v2 = (volatile LONG *)(this->m_filePath.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10011EC0
// Name: public: virtual class GFile __near * ScaleformFileOpener::OpenFileEx(char const __near *,class GFxLog __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
GString *__userpurge ScaleformFileOpener::OpenFileEx@<eax>(
        ScaleformFileOpener *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const char *pfilename,
        GFxLog *plog,
        int flags,
        int modes)
{
  GString *v9; // eax
  GString *v10; // esi
  const char *v11; // ebx
  GString::DataDesc *pData; // edi
  int v13; // eax
  _DWORD *v14; // ecx

  if ( (flags & 0xFFFFFFDF) == 1 )
  {
    flags = 2;
    v9 = (GString *)((int (__thiscall *)(GMemoryHeap *, int, int *, int, int, int, ScaleformFileOpener *))GMemory::pGlobalHeap->Alloc_2)(
                      a1: GMemory::pGlobalHeap,
                      a2: 76,
                      a3: &flags,
                      a4: a3,
                      a5: a4,
                      a6: a2,
                      a7: this);
    v10 = v9;
    if ( v9 != nullptr )
    {
      v9->HeapTypeBits = (unsigned int)&GRefCountImplCore::`vftable';
      v9[1].HeapTypeBits = 1;
      v9->HeapTypeBits = (unsigned int)&SFUIMemoryFile::`vftable';
      GString::GString(this: v9 + 2, a2: pfilename);
      CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&v10[3], growSize: 0, initSize: 0, nFlags: 0);
    }
    else
    {
      v10 = nullptr;
    }
    v11 = ScaleformUIImpl::CorrectFlashFileName(this: &ScaleformUIImpl::m_Instance, name: pfilename);
    if ( g_pFullFileSystem->ReadFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: v11,
           a3: "GAME",
           a4: (CUtlBuffer *)&v10[3],
           a5: 0,
           a6: 0,
           a7: nullptr) )
    {
      pData = v10[3].pData;
      v13 = (int)v10[4].pData;
      v14 = (_DWORD *)(v10[2].HeapTypeBits & 0xFFFFFFFC);
      v10[15].HeapTypeBits = (unsigned int)pData;
      v10[16].HeapTypeBits = v13;
      v10[17].HeapTypeBits = 0;
      LOBYTE(v10[18].pData) = (*v14 & 0x7FFFFFFF) != 0 && pData != nullptr && v13 > 0;
    }
    else
    {
      GRefCountImpl::Release(this: (IShaderAPI *)v10);
      v10 = nullptr;
      if ( plog != nullptr )
        GFxLogBase<GFxLog>::LogError(
          this: &plog->GFxLogBase<GFxLog>,
          pfmt: "Error: GFxLoader failed to open '%s'\n",
          v11);
    }
    return v10;
  }
  else
  {
    if ( plog != nullptr )
      GFxLogBase<GFxLog>::LogError(
        this: &plog->GFxLogBase<GFxLog>,
        pfmt: "Error: GFxLoader cannot open '%s' for writing. writing is not supported\n",
        pfilename);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030B00
// Name: public: virtual unsigned int ScaleformTranslatorAdapter::GetCaps(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall ScaleformTranslatorAdapter::GetCaps(ScaleformTranslatorAdapter *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10067C30
// Name: public: void GFxLogBase<class GFxCharacter>::LogScriptWarning(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
int GFxLogBase<GFxCharacter>::LogScriptWarning(int a1, int a2, ...)
{
  int v2; // ecx
  int result; // eax
  va_list va; // [esp+10h] [ebp+10h] BYREF

  va_start(va, a2);
  if ( a1 != 0 )
    v2 = a1 - 12;
  else
    v2 = 0;
  result = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 168))(a1: v2);
  if ( result != 0 )
    return (*(int (__thiscall **)(int, int, int, char *))(*(_DWORD *)result + 4))(a1: result, a2: 33, a3: a2, a4: va);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006EBC0
// Name: public: void GFxLogBase<class GFxLog>::LogMessage(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLogBase<GFxLog>::LogMessage(
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pfmt,
        int this_4,
        int this_8)
{
  if ( pfmt != nullptr )
    (*(void (__thiscall **)(CMatRenderContextBase **, int, int, int *))(*((_DWORD *)&pfmt[-1].m_Proxy.m_pObject + 1) + 4))(
      a1: &pfmt[-1].m_Proxy.m_pObject + 1,
      a2: 18,
      a3: this_4,
      a4: &this_8);
  else
    (*(void (__stdcall **)(int, int, int *))(MEMORY[0] + 4))(a1: 18, a2: this_4, a3: &this_8);
}

//------------------------------------------------------------------------------
// Address: 0x10070010
// Name: public: void GFxLogBase<class GFxLog>::LogScriptWarning(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLogBase<GFxLog>::LogScriptWarning(
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pfmt,
        int this_4,
        int this_8)
{
  if ( pfmt != nullptr )
    (*(void (__thiscall **)(CMatRenderContextBase **, int, int, int *))(*((_DWORD *)&pfmt[-1].m_Proxy.m_pObject + 1) + 4))(
      a1: &pfmt[-1].m_Proxy.m_pObject + 1,
      a2: 33,
      a3: this_4,
      a4: &this_8);
  else
    (*(void (__stdcall **)(int, int, int *))(MEMORY[0] + 4))(a1: 33, a2: this_4, a3: &this_8);
}

//------------------------------------------------------------------------------
// Address: 0x10070050
// Name: public: void GFxLogBase<class GFxStream>::LogParse(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
char GFxLogBase<GFxStream>::LogParse(tagBITMAPINFOHEADER *this, int a2, ...)
{
  tagMETAFILEPICT *MaterialPage; // eax
  tagMETAFILEPICT *v4; // [esp+0h] [ebp-4h]
  va_list va; // [esp+14h] [ebp+10h] BYREF

  va_start(va, a2);
  LOBYTE(MaterialPage) = GFxStream::IsVerboseParse((GFxStream *)this);
  if ( (_BYTE)MaterialPage != 0 )
  {
    MaterialPage = CMaterialSubRect::GetMaterialPage(result: v4);
    if ( MaterialPage != nullptr )
      LOBYTE(MaterialPage) = (*(int (__thiscall **)(tagMETAFILEPICT *, int, int, char *))(MaterialPage->mm + 4))(
                               a1: MaterialPage,
                               a2: 48,
                               a3: a2,
                               a4: va);
  }
  return (char)MaterialPage;
}

//------------------------------------------------------------------------------
// Address: 0x10072140
// Name: public: void GFxLogBase<class GFxStream>::LogError(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
tagMETAFILEPICT *GFxLogBase<GFxStream>::LogError(tagBITMAPINFOHEADER *this, int a2, ...)
{
  tagMETAFILEPICT *result; // eax
  tagMETAFILEPICT *savedregs; // [esp+0h] [ebp+0h]
  va_list va; // [esp+10h] [ebp+10h] BYREF

  va_start(va, a2);
  result = CMaterialSubRect::GetMaterialPage(result: savedregs);
  if ( result != nullptr )
    return (tagMETAFILEPICT *)(*(int (__thiscall **)(tagMETAFILEPICT *, int, int, char *))(result->mm + 4))(
                                a1: result,
                                a2: 16,
                                a3: a2,
                                a4: va);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007ED60
// Name: public: void GFxLogBase<class GFxLog>::LogScriptError(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLogBase<GFxLog>::LogScriptError(
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pfmt,
        int this_4,
        int this_8)
{
  if ( pfmt != nullptr )
    (*(void (__thiscall **)(CMatRenderContextBase **, int, int, int *))(*((_DWORD *)&pfmt[-1].m_Proxy.m_pObject + 1) + 4))(
      a1: &pfmt[-1].m_Proxy.m_pObject + 1,
      a2: 32,
      a3: this_4,
      a4: &this_8);
  else
    (*(void (__stdcall **)(int, int, int *))(MEMORY[0] + 4))(a1: 32, a2: this_4, a3: &this_8);
}

//------------------------------------------------------------------------------
// Address: 0x10084390
// Name: public: void GFxLogBase<class GFxCharacter>::LogScriptError(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
int GFxLogBase<GFxCharacter>::LogScriptError(int a1, int a2, ...)
{
  int v2; // ecx
  int result; // eax
  va_list va; // [esp+10h] [ebp+10h] BYREF

  va_start(va, a2);
  if ( a1 != 0 )
    v2 = a1 - 12;
  else
    v2 = 0;
  result = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 168))(a1: v2);
  if ( result != 0 )
    return (*(int (__thiscall **)(int, int, int, char *))(*(_DWORD *)result + 4))(a1: result, a2: 32, a3: a2, a4: va);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10094BD0
// Name: public: void GFxLogBase<class GASFnCall>::LogScriptMessage(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxLogBase<GASFnCall>::LogScriptMessage(
        CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>::Iterator_t *this,
        GASFnCall *pfmt,
        int a3,
        char a4)
{
  struct GFxLog *Log; // eax

  Log = GASFnCall::GetLog(this: pfmt);
  if ( Log != nullptr )
    LOBYTE(Log) = ((bool (__thiscall *)(struct GFxLog *, int, int, char *))Log->LogMessageVarg)(
                    a1: Log,
                    a2: 34,
                    a3,
                    &a4);
  return (char)Log;
}

//------------------------------------------------------------------------------
// Address: 0x10094C00
// Name: public: void GFxLogBase<class GASEnvironment>::LogError(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
int GFxLogBase<GASEnvironment>::LogError(int a1, int a2, ...)
{
  int result; // eax
  va_list va; // [esp+10h] [ebp+10h] BYREF

  va_start(va, a2);
  result = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a1 + 116) + 168))(a1: *(_DWORD *)(a1 + 116));
  if ( result != 0 )
    return (*(int (__thiscall **)(int, int, int, char *))(*(_DWORD *)result + 4))(a1: result, a2: 16, a3: a2, a4: va);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10094C30
// Name: public: void GFxLogBase<class GFxStream>::LogParseAction(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
char GFxLogBase<GFxStream>::LogParseAction(tagBITMAPINFOHEADER *this, int a2, ...)
{
  tagMETAFILEPICT *MaterialPage; // eax
  tagMETAFILEPICT *v4; // [esp+0h] [ebp-4h]
  va_list va; // [esp+14h] [ebp+10h] BYREF

  va_start(va, a2);
  LOBYTE(MaterialPage) = GFxStream::IsVerboseParseAction((GFxStream *)this);
  if ( (_BYTE)MaterialPage != 0 )
  {
    MaterialPage = CMaterialSubRect::GetMaterialPage(result: v4);
    if ( MaterialPage != nullptr )
      LOBYTE(MaterialPage) = (*(int (__thiscall **)(tagMETAFILEPICT *, int, int, char *))(MaterialPage->mm + 4))(
                               a1: MaterialPage,
                               a2: 51,
                               a3: a2,
                               a4: va);
  }
  return (char)MaterialPage;
}

//------------------------------------------------------------------------------
// Address: 0x10094C70
// Name: public: void GFxLogBase<class GFxLoadProcess>::LogParse(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxLogBase<GFxLoadProcess>::LogParse(
        GArrayLH<GString,2,GArrayDefaultPolicy> *this,
        unsigned int pfmt,
        int a3,
        char a4)
{
  _DWORD *v4; // ecx
  _DWORD *result; // eax
  int v6; // ecx

  if ( pfmt != 0 )
    v4 = (_DWORD *)(pfmt - 20);
  else
    v4 = nullptr;
  if ( v4 == (_DWORD *)-20 )
    result = nullptr;
  else
    result = v4;
  if ( (result[6] & 1) != 0 )
  {
    result = (_DWORD *)v4[4];
    v6 = result[3];
    if ( v6 != 0 )
      return (*(void *(__thiscall **)(int, int, int, char *))(*(_DWORD *)v6 + 4))(a1: v6, a2: 48, a3, &a4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10094CC0
// Name: public: void GFxLogBase<class GFxLoadProcess>::LogParseAction(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxLogBase<GFxLoadProcess>::LogParseAction(
        GArrayLH<GString,2,GArrayDefaultPolicy> *this,
        unsigned int pfmt,
        int a3,
        char a4)
{
  int v4; // ecx
  int v5; // eax
  void *result; // eax
  int v7; // ecx

  if ( pfmt != 0 )
    v4 = pfmt - 20;
  else
    v4 = 0;
  if ( v4 == -20 )
    v5 = 0;
  else
    v5 = v4;
  result = (void *)(*(_DWORD *)(v5 + 24) >> 1);
  if ( ((unsigned __int8)result & 1) != 0 )
  {
    v7 = *(_DWORD *)(*(_DWORD *)(v4 + 16) + 12);
    if ( v7 != 0 )
      return (*(void *(__thiscall **)(int, int, int, char *))(*(_DWORD *)v7 + 4))(a1: v7, a2: 51, a3, &a4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B00A0
// Name: public: void GFxLogBase<class GFxCharacter>::LogError(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
int GFxLogBase<GFxCharacter>::LogError(int a1, int a2, ...)
{
  int v2; // ecx
  int result; // eax
  va_list va; // [esp+10h] [ebp+10h] BYREF

  va_start(va, a2);
  if ( a1 != 0 )
    v2 = a1 - 12;
  else
    v2 = 0;
  result = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 168))(a1: v2);
  if ( result != 0 )
    return (*(int (__thiscall **)(int, int, int, char *))(*(_DWORD *)result + 4))(a1: result, a2: 16, a3: a2, a4: va);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B00E0
// Name: public: void GFxLogBase<class GFxCharacter>::LogWarning(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
int GFxLogBase<GFxCharacter>::LogWarning(int a1, int a2, ...)
{
  int v2; // ecx
  int result; // eax
  va_list va; // [esp+10h] [ebp+10h] BYREF

  va_start(va, a2);
  if ( a1 != 0 )
    v2 = a1 - 12;
  else
    v2 = 0;
  result = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 168))(a1: v2);
  if ( result != 0 )
    return (*(int (__thiscall **)(int, int, int, char *))(*(_DWORD *)result + 4))(a1: result, a2: 17, a3: a2, a4: va);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D4190
// Name: public: void GFxLogBase<class GFxLog>::LogWarning(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLogBase<GFxLog>::LogWarning(
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pfmt,
        int this_4,
        int this_8)
{
  if ( pfmt != nullptr )
    (*(void (__thiscall **)(CMatRenderContextBase **, int, int, int *))(*((_DWORD *)&pfmt[-1].m_Proxy.m_pObject + 1) + 4))(
      a1: &pfmt[-1].m_Proxy.m_pObject + 1,
      a2: 17,
      a3: this_4,
      a4: &this_8);
  else
    (*(void (__stdcall **)(int, int, int *))(MEMORY[0] + 4))(a1: 17, a2: this_4, a3: &this_8);
}

//------------------------------------------------------------------------------
// Address: 0x100D4BD0
// Name: public: void GFxLogBase<class GFxStream>::LogWarning(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
tagMETAFILEPICT *GFxLogBase<GFxStream>::LogWarning(tagBITMAPINFOHEADER *this, int a2, ...)
{
  tagMETAFILEPICT *result; // eax
  tagMETAFILEPICT *savedregs; // [esp+0h] [ebp+0h]
  va_list va; // [esp+10h] [ebp+10h] BYREF

  va_start(va, a2);
  result = CMaterialSubRect::GetMaterialPage(result: savedregs);
  if ( result != nullptr )
    return (tagMETAFILEPICT *)(*(int (__thiscall **)(tagMETAFILEPICT *, int, int, char *))(result->mm + 4))(
                                a1: result,
                                a2: 17,
                                a3: a2,
                                a4: va);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DD710
// Name: public: void GFxLogBase<class GFxLoadProcess>::LogError(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxLogBase<GFxLoadProcess>::LogError(
        GArrayLH<GString,2,GArrayDefaultPolicy> *this,
        unsigned int pfmt,
        int a3,
        char a4)
{
  int v4; // eax
  _DWORD *result; // eax
  int v6; // ecx

  if ( pfmt != 0 )
    v4 = pfmt - 20;
  else
    v4 = 0;
  result = *(_DWORD **)(v4 + 16);
  v6 = result[3];
  if ( v6 != 0 )
    return (*(void *(__thiscall **)(int, int, int, char *))(*(_DWORD *)v6 + 4))(a1: v6, a2: 16, a3, &a4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100DD740
// Name: public: void GFxLogBase<class GFxLoadProcess>::LogWarning(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxLogBase<GFxLoadProcess>::LogWarning(
        GArrayLH<GString,2,GArrayDefaultPolicy> *this,
        unsigned int pfmt,
        int a3,
        char a4)
{
  int v4; // eax
  _DWORD *result; // eax
  int v6; // ecx

  if ( pfmt != 0 )
    v4 = pfmt - 20;
  else
    v4 = 0;
  result = *(_DWORD **)(v4 + 16);
  v6 = result[3];
  if ( v6 != 0 )
    return (*(void *(__thiscall **)(int, int, int, char *))(*(_DWORD *)v6 + 4))(a1: v6, a2: 17, a3, &a4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E61F0
// Name: public: virtual class GString GFxEditTextCharacter::TextDocumentListener::GetCharacterPath(void)
// Source: json
//------------------------------------------------------------------------------
struct GString __thiscall GFxEditTextCharacter::TextDocumentListener::GetCharacterPath(
        GFxEditTextCharacter::TextDocumentListener *this,
        CUtlMemory<CImagePacker,int> *a2)
{
  GString::GString(this: a2);
  GFxASCharacter::GetAbsolutePath(
    this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)((char *)this - 244),
    a2);
  return (struct GString)a2;
}

//------------------------------------------------------------------------------
// Address: 0x100FAC50
// Name: public: virtual char const __near * SFUIMemoryFile::GetFilePath(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SFUIMemoryFile::GetFilePath(SFUIMemoryFile *this)
{
  return (const char *)((this->m_filePath.HeapTypeBits & 0xFFFFFFFC) + 8);
}

//------------------------------------------------------------------------------
// Address: 0x1010D500
// Name: public: void GFxLogBase<class GFxLoadProcess>::LogScriptWarning(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxLogBase<GFxLoadProcess>::LogScriptWarning(
        GArrayLH<GString,2,GArrayDefaultPolicy> *this,
        unsigned int pfmt,
        int a3,
        char a4)
{
  int v4; // eax
  _DWORD *result; // eax
  int v6; // ecx

  if ( pfmt != 0 )
    v4 = pfmt - 20;
  else
    v4 = 0;
  result = *(_DWORD **)(v4 + 16);
  v6 = result[3];
  if ( v6 != 0 )
    return (*(void *(__thiscall **)(int, int, int, char *))(*(_DWORD *)v6 + 4))(a1: v6, a2: 33, a3, &a4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012E320
// Name: public: void GFxLogBase<class GASFnCall>::LogScriptWarning(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxLogBase<GASFnCall>::LogScriptWarning(
        CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>::Iterator_t *this,
        GASFnCall *pfmt,
        int a3,
        char a4)
{
  struct GFxLog *Log; // eax

  Log = GASFnCall::GetLog(this: pfmt);
  if ( Log != nullptr )
    LOBYTE(Log) = ((bool (__thiscall *)(struct GFxLog *, int, int, char *))Log->LogMessageVarg)(
                    a1: Log,
                    a2: 33,
                    a3,
                    &a4);
  return (char)Log;
}

//------------------------------------------------------------------------------
// Address: 0x10147B90
// Name: public: void GFxLogBase<class GFxStream>::LogParseShape(char const __near *,...)const
// Source: json
//------------------------------------------------------------------------------
char GFxLogBase<GFxStream>::LogParseShape(tagBITMAPINFOHEADER *this, int a2, ...)
{
  tagMETAFILEPICT *MaterialPage; // eax
  tagMETAFILEPICT *v4; // [esp+0h] [ebp-4h]
  va_list va; // [esp+14h] [ebp+10h] BYREF

  va_start(va, a2);
  LOBYTE(MaterialPage) = GFxStream::IsVerboseParseShape((GFxStream *)this);
  if ( (_BYTE)MaterialPage != 0 )
  {
    MaterialPage = CMaterialSubRect::GetMaterialPage(result: v4);
    if ( MaterialPage != nullptr )
      LOBYTE(MaterialPage) = (*(int (__thiscall **)(tagMETAFILEPICT *, int, int, char *))(MaterialPage->mm + 4))(
                               a1: MaterialPage,
                               a2: 49,
                               a3: a2,
                               a4: va);
  }
  return (char)MaterialPage;
}

//------------------------------------------------------------------------------
// Address: 0x1015EA60
// Name: public: static void __near * GRefCountBaseStatImpl<class GRefCountNTSImpl,324>::operator new(unsigned int,struct GMemAddressStub __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl GRefCountBaseStatImpl<GRefCountNTSImpl,324>::operator new(unsigned int sz, const void *adr)
{
  int v3; // [esp+0h] [ebp-4h] BYREF

  v3 = 324;
  return GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: adr, a3: sz, a4: &v3);
}
