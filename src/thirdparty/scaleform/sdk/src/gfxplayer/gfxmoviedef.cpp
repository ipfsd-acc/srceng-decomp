// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxmoviedef.cpp
// Functions: 116
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxmoviedef.h"

//------------------------------------------------------------------------------
// Address: 0x1003D120
// Name: public: virtual unsigned int GFxMovieDataDef::GetResourceTypeCode(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::GetResourceTypeCode(
        CMemberFuncProxyBase<CTexture *,void (__thiscall CTexture::*)(ITexture *),CFuncMemPolicyNone> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100D40B0
// Name: public: void GFxMovieDataDef::LoadTaskData::OnMovieDataDefRelease(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::LoadTaskData::OnMovieDataDefRelease(GFxMovieDataDef::LoadTaskData *this)
{
  if ( *((int *)this + 32) <= 1 )
    *((_BYTE *)this + 136) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D40D0
// Name: public: void GFxMovieDataDef::LoadTaskData::SetMetadata(unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::LoadTaskData::SetMetadata(
        CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *this,
        TextureLodOverride::OverrideInfo *pdata,
        unsigned int size)
{
  int v4; // ecx
  unsigned __int8 *v5; // eax
  int v6; // [esp+8h] [ebp-4h] BYREF

  v4 = *((_DWORD *)this + 7);
  v6 = 265;
  v5 = (unsigned __int8 *)(*(int (__thiscall **)(int, unsigned int, int *))(*(_DWORD *)v4 + 40))(
                            a1: v4,
                            a2: size,
                            a3: &v6);
  *((_DWORD *)this + 30) = v5;
  if ( v5 != nullptr )
  {
    *((_DWORD *)this + 31) = size;
    memcpy(dst: v5, src: (unsigned __int8 *)pdata, count: size);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4120
// Name: _GFxMovieBindProcess::BindNextFrame_::_114_::ImagePackVisitor::Visit
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxMovieBindProcess::BindNextFrame_::_114_::ImagePackVisitor::Visit(
        _DWORD **this,
        int a2,
        int a3,
        int a4,
        int a5)
{
  return (*(int (__thiscall **)(_DWORD, int, int))(**(this + 1) + 8))(a1: *(this + 1), a2: a3, a3: a5);
}

//------------------------------------------------------------------------------
// Address: 0x100D4140
// Name: public: class GFxMovieDefImpl __near * GFxMovieDefImpl::BindTaskData::GetMovieDefImplAddRef(void)
// Source: json
//------------------------------------------------------------------------------
struct GFxMovieDefImpl *__thiscall GFxMovieDefImpl::BindTaskData::GetMovieDefImplAddRef(
        GFxMovieDefImpl::BindTaskData *this)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  IShaderDevice *v3; // ecx
  int v4; // esi

  v2 = (_RTL_CRITICAL_SECTION *)(this + 20);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 20));
  v3 = (IShaderDevice *)*(this + 4);
  if ( v3 != nullptr && GFxResource::AddRef_NotZero(this: v3) != 0 )
  {
    v4 = (int)*(this + 4);
    LeaveCriticalSection(lpCriticalSection: v2);
    return (struct GFxMovieDefImpl *)v4;
  }
  else
  {
    LeaveCriticalSection(lpCriticalSection: v2);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4180
// Name: public: virtual void GFxMovieDataDefFileKeyInterface::AddRef(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFxMovieDataDefFileKeyInterface::AddRef(IShaderDevice *hdata)
{
  VertexShaderHandle_t__ *savedregs; // [esp+0h] [ebp+0h]

  GRefCountImpl::AddRef(this: hdata, a2: savedregs);
}

//------------------------------------------------------------------------------
// Address: 0x100D41D0
// Name: public: virtual class GString GFxResourceReport::GetResourceName(void)const
// Source: json
//------------------------------------------------------------------------------
struct GString __thiscall GFxResourceReport::GetResourceName(GFxResourceReport *this, CUtlMemory<CImagePacker,int> *a2)
{
  GString::GString(this: a2);
  return (struct GString)a2;
}

//------------------------------------------------------------------------------
// Address: 0x100D41F0
// Name: private: void __near * GFxDataAllocator::OverflowAlloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CP4File_vtbl *__thiscall GFxDataAllocator::OverflowAlloc(CP4File *this, unsigned int bytes)
{
  unsigned int v2; // edi
  int m_nGrowSize; // ecx
  int *v5; // eax
  CP4File_vtbl *result; // eax
  int v7; // ecx
  int v8; // eax

  v2 = bytes;
  if ( bytes > 0xFFA )
  {
    m_nGrowSize = this->m_sFilename.m_Storage.m_Memory.m_nGrowSize;
    bytes = 260;
    v5 = (int *)(*(int (__thiscall **)(int, unsigned int, unsigned int *))(*(_DWORD *)m_nGrowSize + 40))(
                  a1: m_nGrowSize,
                  a2: v2 + 4,
                  a3: &bytes);
    if ( v5 != nullptr )
    {
      *v5 = this->m_sFilename.m_Storage.m_Memory.m_nAllocationCount;
      this->m_sFilename.m_Storage.m_Memory.m_nAllocationCount = (int)v5;
      return (CP4File_vtbl *)(v5 + 1);
    }
    return nullptr;
  }
  if ( (unsigned __int8 *)bytes > this->m_sFilename.m_Storage.m_Memory.m_pMemory )
  {
    v7 = this->m_sFilename.m_Storage.m_Memory.m_nGrowSize;
    bytes = 260;
    v8 = (*(int (__thiscall **)(int, int, unsigned int *))(*(_DWORD *)v7 + 40))(a1: v7, a2: 8184, a3: &bytes);
    if ( v8 == 0 )
      return nullptr;
    *(_DWORD *)v8 = this->m_sFilename.m_Storage.m_Memory.m_nAllocationCount;
    this->m_sFilename.m_Storage.m_Memory.m_nAllocationCount = v8;
    this->__vftable = (CP4File_vtbl *)(v8 + 4);
    this->m_sFilename.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)8180;
  }
  result = this->__vftable;
  this->m_sFilename.m_Storage.m_Memory.m_pMemory -= v2;
  this->__vftable = (CP4File_vtbl *)((char *)result + v2);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D4280
// Name: public: virtual class GFxResourceKey GFxMovieDataDef::GetKey(void)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieDataDef::GetKey(
        CMemberFuncProxy1<CTexture_MultipleRenderTarget *,void (__thiscall CTexture_MultipleRenderTarget::*)(char const *),char const *,CFuncMemPolicyNone> *this@<ecx>,
        GFxResourceKey *a2,
        __int128 a3)
{
  GFxResourceKey::GFxResourceKey(this: a2, a2: (const struct GFxResourceKey *)(&this->m_pObject + 1));
}

//------------------------------------------------------------------------------
// Address: 0x100D42A0
// Name: public: virtual class GFxResourceReport __near * GFxMovieDataDef::GetResourceReport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::GetResourceReport(
        CMemberFuncProxy1<CTexture_MultipleRenderTarget *,void (__thiscall CTexture_MultipleRenderTarget::*)(char const *),char const *,CFuncMemPolicyNone> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100D42C0
// Name: public: virtual unsigned int GFxMovieDataDef::GetVersion(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::GetVersion(
        CMemberFuncProxyBase<CTexture *,void (__thiscall CTexture::*)(ITexture *),CFuncMemPolicyNone> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100D42D0
// Name: public: virtual unsigned int GFxMovieDataDef::GetLoadingFrame(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::GetLoadingFrame(
        CMemberFuncProxyBase<CTexture *,void (__thiscall CTexture::*)(ITexture *),CFuncMemPolicyNone> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100D42E0
// Name: public: virtual unsigned int GFxMovieDataDef::GetSWFFlags(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::GetSWFFlags(
        CMemberFuncProxyBase<CTexture *,void (__thiscall CTexture::*)(ITexture *),CFuncMemPolicyNone> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100D42F0
// Name: public: virtual unsigned int GFxMovieDataDef::GetFrameCount(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::GetFrameCount(
        CMemberFuncProxyBase<CTexture *,void (__thiscall CTexture::*)(ITexture *),CFuncMemPolicyNone> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100D4300
// Name: public: virtual class GFxSoundStreamDef __near * GFxMovieDataDef::GetSoundStream(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxMovieDataDef::GetSoundStream(CP4AutoEditAddFile *this)
{
  return *(void **)(*((_DWORD *)this + 8) + 284);
}

//------------------------------------------------------------------------------
// Address: 0x100D4310
// Name: public: virtual void GFxMovieDataDef::SetSoundStream(class GFxSoundStreamDef __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::SetSoundStream(GFxMovieDataDef *this, struct GFxSoundStreamDef *a2)
{
  int v2; // esi
  GRefCountNTSImpl *v3; // ecx

  v2 = *((_DWORD *)this + 8);
  v3 = *(GRefCountNTSImpl **)(v2 + 284);
  if ( v3 != nullptr )
    GRefCountNTSImpl::Release(this: v3);
  if ( a2 != nullptr )
    ++a2->m_nAllocationCount;
  *(_DWORD *)(v2 + 284) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x100D4340
// Name: public: virtual class GMemoryHeap __near * GFxMovieDataDef::GetResourceHeap(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxMovieDataDef::GetResourceHeap(
        CMemberFuncProxy1<CTexture_MultipleRenderTarget *,void (__thiscall CTexture_MultipleRenderTarget::*)(char const *),char const *,CFuncMemPolicyNone> *this)
{
  return this->m_pObject->m_nRefCount.m_value;
}

//------------------------------------------------------------------------------
// Address: 0x100D43D0
// Name: public: void GFxMovieDataDef::LoadTaskData::WaitForLoadFinish(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::LoadTaskData::WaitForLoadFinish(GFxMovieDataDef::LoadTaskData *this)
{
  int v1; // esi

  if ( *((int *)this + 32) <= 1 )
  {
    v1 = *((_DWORD *)this + 36);
    GMutex::Lock(this: (IMatRenderContextInternal *)(v1 + 8));
    while ( *(_BYTE *)(v1 + 32) == 0 )
      GWaitCondition::Wait(this: (GWaitCondition *)(v1 + 28), a2: (struct GMutex *)(v1 + 8), a3: 0xFFFFFFFF);
    GMutex::Unlock(this: (IMatRenderContextInternal *)(v1 + 8));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4410
// Name: public: void GFxMovieDataDef::LoadTaskData::WaitForFrame(unsigned int)
// Source: json
//------------------------------------------------------------------------------
IMaterialInternal *__thiscall GFxMovieDataDef::LoadTaskData::WaitForFrame(int *this, unsigned int frame)
{
  IMaterialInternal *result; // eax
  IMatRenderContextInternal *v4; // edi

  if ( *(this + 32) <= 1 )
  {
    result = (IMaterialInternal *)frame;
    if ( *(this + 33) <= frame )
    {
      v4 = (IMatRenderContextInternal *)*(this + 36);
      GMutex::Lock(this: v4 + 2);
      while ( *(this + 32) <= 1 )
      {
        if ( *(this + 33) > frame )
          break;
        GWaitCondition::Wait(
          this: (GWaitCondition *)(*(this + 36) + 28),
          a2: (struct GMutex *)(*(this + 36) + 8),
          a3: 0xFFFFFFFF);
      }
      return GMutex::Unlock(this: v4 + 2);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D4490
// Name: public: virtual void GFxMovieDataDef::LoadTaskData::SetLoadingPlaylistFrame(struct GFxTimelineDef::Frame const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::LoadTaskData::SetLoadingPlaylistFrame(
        CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *this,
        const CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *frame)
{
  _RTL_CRITICAL_SECTION *v3; // edi
  TextureLodOverride::OverrideInfo **v4; // eax

  v3 = (_RTL_CRITICAL_SECTION *)(this + 11);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 11));
  v4 = (TextureLodOverride::OverrideInfo **)(*((_DWORD *)this + 61) + 8 * *((_DWORD *)this + 33));
  *v4 = frame->m_Memory.m_pMemory;
  v4[1] = (TextureLodOverride::OverrideInfo *)frame->m_Memory.m_nAllocationCount;
  LeaveCriticalSection(lpCriticalSection: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100D44D0
// Name: public: virtual void GFxMovieDataDef::LoadTaskData::SetLoadingInitActionFrame(struct GFxTimelineDef::Frame const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::LoadTaskData::SetLoadingInitActionFrame(
        CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *this,
        const CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *frame)
{
  _RTL_CRITICAL_SECTION *v3; // edi
  TextureLodOverride::OverrideInfo **v4; // eax

  v3 = (_RTL_CRITICAL_SECTION *)(this + 11);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 11));
  v4 = (TextureLodOverride::OverrideInfo **)(*((_DWORD *)this + 64) + 8 * *((_DWORD *)this + 33));
  *v4 = frame->m_Memory.m_pMemory;
  v4[1] = (TextureLodOverride::OverrideInfo *)frame->m_Memory.m_nAllocationCount;
  ++*((_DWORD *)this + 67);
  LeaveCriticalSection(lpCriticalSection: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100D4520
// Name: public: struct GFxTimelineDef::Frame const GFxMovieDataDef::LoadTaskData::GetPlaylist(int)const
// Source: json
//------------------------------------------------------------------------------
const TextureLodOverride::OverrideInfo *__thiscall GFxMovieDataDef::LoadTaskData::GetPlaylist(
        CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *this,
        const TextureLodOverride::OverrideInfo *frameNumber,
        int frameNumbera)
{
  int v4; // eax
  int v5; // edx
  int v6; // ecx
  int v8; // ecx
  _RTL_CRITICAL_SECTION *v9; // edi
  int v10; // edx
  int v11; // ecx
  int v12; // edx

  if ( *((int *)this + 32) < 2 )
  {
    v9 = (_RTL_CRITICAL_SECTION *)(this + 11);
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 11));
    v10 = *((_DWORD *)this + 61);
    v11 = *(_DWORD *)(v10 + 8 * frameNumbera);
    v12 = *(_DWORD *)(v10 + 8 * frameNumbera + 4);
    *(_DWORD *)&frameNumber->x = v11;
    *(_DWORD *)&frameNumber[2].x = v12;
    LeaveCriticalSection(lpCriticalSection: v9);
    return frameNumber;
  }
  else
  {
    v4 = *((_DWORD *)this + 61);
    v5 = *(_DWORD *)(v4 + 8 * frameNumbera);
    v6 = v4 + 8 * frameNumbera;
    v8 = *(_DWORD *)(v6 + 4);
    *(_DWORD *)&frameNumber->x = v5;
    *(_DWORD *)&frameNumber[2].x = v8;
    return frameNumber;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4590
// Name: public: unsigned int GFxMovieDataDef::LoadTaskData::GetInitActionListSize(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *__thiscall GFxMovieDataDef::LoadTaskData::GetInitActionListSize(
        int this)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  int v3; // esi

  v2 = (_RTL_CRITICAL_SECTION *)(this + 220);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 220));
  v3 = *(_DWORD *)(this + 260);
  LeaveCriticalSection(lpCriticalSection: v2);
  return (const CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x100D45D0
// Name: public: virtual char const __near * GFxMovieDataDefFileKeyInterface::GetFileURL(void __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall GFxMovieDataDefFileKeyInterface::GetFileURL(GFxMovieDataDefFileKeyInterface *this, _DWORD *a2)
{
  return (const char *)((a2[2] & 0xFFFFFFFC) + 8);
}

//------------------------------------------------------------------------------
// Address: 0x100D45F0
// Name: public: bool GFxMovieDataDefFileKeyData::operator==(class GFxMovieDataDefFileKeyData __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxMovieDataDefFileKeyData::operator==(int this, _DWORD *a2)
{
  return *(_DWORD *)(this + 12) == a2[3]
      && *(_DWORD *)(this + 24) == a2[6]
      && *(_DWORD *)(this + 16) == a2[4]
      && *(_DWORD *)(this + 20) == a2[5]
      && GString::operator==(
           this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(this + 8),
           str: (int)(a2 + 2))
      && *(_DWORD *)(this + 28) == a2[7];
}

//------------------------------------------------------------------------------
// Address: 0x100D4650
// Name: public: virtual unsigned int GFxMovieDataDefFileKeyInterface::GetHashCode(void __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxMovieDataDefFileKeyInterface::GetHashCode(GFxMovieDataDefFileKeyInterface *this, _DWORD *a2)
{
  return (unsigned int)GString::BernsteinHashFunction(result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((a2[2] & 0xFFFFFFFC) + 8))
       ^ a2[3]
       ^ a2[6]
       ^ a2[7]
       ^ a2[4]
       ^ ((a2[3] ^ (unsigned int)(a2[6] ^ a2[7])) >> 7);
}

//------------------------------------------------------------------------------
// Address: 0x100D46A0
// Name: public: virtual bool GFxMovieDataDefFileKeyInterface::KeyEquals(void __near *,class GFxResourceKey const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxMovieDataDefFileKeyInterface::KeyEquals(
        GFxMovieDataDefFileKeyInterface *this,
        void *a2,
        const struct GFxResourceKey *a3)
{
  return this == (GFxMovieDataDefFileKeyInterface *)a3->pKeyInterface
      && GFxMovieDataDefFileKeyData::operator==(this: (int)a2, a2: (_DWORD *)a3->hKeyData);
}

//------------------------------------------------------------------------------
// Address: 0x100D46C0
// Name: public: virtual class GString GFxMovieDataDef::GetResourceName(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::GetResourceName(
        CMemberFuncProxy1<CTexture_MultipleRenderTarget *,void (__thiscall CTexture_MultipleRenderTarget::*)(char const *),char const *,CFuncMemPolicyNone> *this,
        GString *a2)
{
  const char *ShortFilename; // eax

  ShortFilename = (const char *)G_GetShortFilename();
  GString::GString(this: a2, a2: ShortFilename);
}

//------------------------------------------------------------------------------
// Address: 0x100D46F0
// Name: public: virtual class GFxMovieView __near * GFxMovieDefImpl::CreateInstance(struct GFxMovieDef::MemoryParams const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
struct GFxMovieView *__thiscall GFxMovieDefImpl::CreateInstance(
        GFxMovieDefImpl *this,
        const struct GFxMovieDef::MemoryParams *a2,
        int initFirstFrame)
{
  IMatRenderContext *ShortFilename; // eax
  IShaderAPI *v5; // edi
  int v6; // ebx
  void *v7; // esi
  int v9; // [esp+Ch] [ebp-4h] BYREF

  (*(void (__thiscall **)(GFxMovieDefImpl *, const char *))(*(_DWORD *)this + 48))(a1: this, a2: "\"");
  ShortFilename = G_GetShortFilename();
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&v9, pdata1: (int)"MovieView \"", pdata2: (int)ShortFilename);
  v5 = (IShaderAPI *)(*(int (__thiscall **)(GFxMovieDefImpl *, unsigned int, const struct GFxMovieDef::MemoryParams *))(*(_DWORD *)this + 88))(
                       a1: this,
                       a2: (v9 & 0xFFFFFFFC) + 8,
                       a3: a2);
  v6 = (*(int (__thiscall **)(GFxMovieDefImpl *, IShaderAPI *, int))(*(_DWORD *)this + 92))(
         a1: this,
         a2: v5,
         a3: initFirstFrame);
  GRefCountImpl::Release(this: v5);
  v7 = (void *)(v9 & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v9 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
  return (struct GFxMovieView *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x100D4790
// Name: public: virtual class GFxMovieView __near * GFxMovieDefImpl::CreateInstance(class GFxMovieDef::MemoryContext __near *,bool)
// Source: json
//------------------------------------------------------------------------------
struct GFxMovieView *__thiscall GFxMovieDefImpl::CreateInstance(
        GFxMovieDefImpl *this,
        int memContext,
        bool initFirstFrame)
{
  GStatBag *v3; // esi
  GFxMovieDef::MemoryContext_vtbl *v4; // ecx
  int (__thiscall *v5)(GFxMovieDef::MemoryContext_vtbl *, int, int *); // eax
  ScaleformRenderer *v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // ecx
  int (__thiscall *v10)(int, int, int *); // edx
  GFxFontLib::FontResult *v11; // eax
  struct GFxSprite *v12; // edi
  GImageInfo *v14; // ebx
  unsigned int v15; // eax
  bool v16; // [esp+18h] [ebp-10h]
  GColor v17; // [esp+18h] [ebp-10h]
  bool v18; // [esp+1Ch] [ebp-Ch]
  int v19; // [esp+24h] [ebp-4h] BYREF

  v3 = (GStatBag *)memContext;
  v4 = *(GFxMovieDef::MemoryContext_vtbl **)(memContext + 8);
  v5 = *((int (__thiscall **)(GFxMovieDef::MemoryContext_vtbl *, int, int *))v4->dtr_GRefCountImplCore + 10);
  memContext = 326;
  v6 = (ScaleformRenderer *)v5(a1: v4, a2: 10320, a3: &memContext);
  if ( v6 == nullptr )
    return nullptr;
  GFxMovieRoot::GFxMovieRoot(this: v6, memContext: v3, a3: v16);
  v8 = v7;
  if ( v7 == 0 )
    return nullptr;
  v9 = *(_DWORD *)(v7 + 32);
  v10 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v9 + 40);
  v19 = 322;
  v11 = (GFxFontLib::FontResult *)v10(a1: v9, a2: 488, a3: &v19);
  if ( v11 == nullptr || (v12 = (struct GFxSprite *)GFxSprite::GFxSprite(this: v11)) == nullptr )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 276))(a1: v8);
    return nullptr;
  }
  GFxSprite::SetLevel(result: nullptr);
  GFxMovieRoot::SetLevelMovie(this: (GFxMovieRoot *)v8, a2: 0, a3: v12);
  GFxMovieRoot::RegisterAuxASClasses(this: (ScaleformRenderer *)v8, sc: v17, xmlstate: v18);
  v14 = *(GImageInfo **)(v8 + 10308);
  v15 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 4))(a1: v8);
  GFxAmpViewStats::SetMovieDef(this: v14, movieDef: v15);
  if ( initFirstFrame )
    (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v8 + 148))(a1: v8, a2: 0.0, a3: 0);
  GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v12);
  return (struct GFxMovieView *)v8;
}

//------------------------------------------------------------------------------
// Address: 0x100D4880
// Name: public: void GFxMovieDefImpl::BindTaskData::OnMovieDefRelease(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialInternal *__thiscall GFxMovieDefImpl::BindTaskData::OnMovieDefRelease(
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,void *),IMaterial *,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  int v3; // edi
  IMatRenderContextInternal *v4; // esi
  int v6; // [esp+0h] [ebp-Ch]

  v2 = (_RTL_CRITICAL_SECTION *)(&this->m_Proxy.m_pObject + 1);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(&this->m_Proxy.m_pObject + 1));
  *((_DWORD *)this + 16) = 0;
  LeaveCriticalSection(lpCriticalSection: v2);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 80));
  LODWORD(this->m_Proxy.m_pfnProxied) = 0;
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 80));
  if ( (*((_DWORD *)this + 29) & 0xFu) <= 1 )
    *((_BYTE *)this + 132) = 1;
  v3 = *(_DWORD *)(this->m_iRefs + 32);
  v4 = *(IMatRenderContextInternal **)(v3 + 144);
  GMutex::Lock(this: v4 + 2);
  GWaitCondition::NotifyAll(this: (CUtlVector<int,CUtlMemory<int,int> > *)(*(_DWORD *)(v3 + 144) + 28), a2: v6);
  return GMutex::Unlock(this: v4 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x100D48F0
// Name: public: void GFxMovieDefImpl::BindTaskData::SetBindState(unsigned int)
// Source: json
//------------------------------------------------------------------------------
IMaterialInternal *__thiscall GFxMovieDefImpl::BindTaskData::SetBindState(
        IMatRenderContextInternal **this,
        unsigned int newState)
{
  IMatRenderContextInternal *v3; // esi
  CUtlVector<int,CUtlMemory<int,int> > *v4; // ecx
  int v6; // [esp+0h] [ebp-8h]

  v3 = *(this + 30);
  GMutex::Lock(this: v3 + 2);
  v4 = (CUtlVector<int,CUtlMemory<int,int> > *)&(*(this + 30))[7];
  *(this + 29) = (IMatRenderContextInternal *)newState;
  GWaitCondition::NotifyAll(this: v4, a2: v6);
  return GMutex::Unlock(this: v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x100D4930
// Name: public: bool GFxMovieDefImpl::BindTaskData::WaitForBindStateFlags(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxMovieDefImpl::BindTaskData::WaitForBindStateFlags(_DWORD *this, unsigned int result)
{
  IMatRenderContextInternal *v3; // edi
  bool v4; // bl

  v3 = (IMatRenderContextInternal *)*(this + 30);
  GMutex::Lock(this: v3 + 2);
  while ( (*(_BYTE *)(this + 29) & 0xFu) < 3 )
  {
    if ( (*(this + 29) & result) != 0 )
      break;
    GWaitCondition::Wait(
      this: (GWaitCondition *)(*(this + 30) + 28),
      a2: (struct GMutex *)(*(this + 30) + 8),
      a3: 0xFFFFFFFF);
  }
  v4 = (*(this + 29) & result) != 0;
  GMutex::Unlock(this: v3 + 2);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100D4990
// Name: public: bool GFxMovieDefBindStates::operator==(class GFxMovieDefBindStates __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDefBindStates::operator==(CReferenceToHandleTexture *this, bool other)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100D49F0
// Name: public: virtual unsigned int GFxMovieDefImplKeyInterface::GetHashCode(void __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxMovieDefImplKeyInterface::GetHashCode(GFxMovieDefImplKeyInterface *this, _DWORD *a2)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)a2[3];
  return a2[2]
       ^ v2[2]
       ^ v2[3]
       ^ v2[4]
       ^ v2[5]
       ^ v2[6]
       ^ v2[7]
       ^ v2[8]
       ^ v2[9]
       ^ v2[10]
       ^ ((a2[2] ^ v2[2] ^ v2[3] ^ v2[4] ^ v2[5] ^ v2[6] ^ v2[7] ^ v2[8] ^ (unsigned int)(v2[9] ^ v2[10])) >> 7);
}

//------------------------------------------------------------------------------
// Address: 0x100D4A30
// Name: public: virtual bool GFxMovieDefImplKeyInterface::KeyEquals(void __near *,class GFxResourceKey const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxMovieDefImplKeyInterface::KeyEquals(
        GFxMovieDefImplKeyInterface *this,
        CReferenceToHandleTexture **a2,
        const struct GFxResourceKey *a3)
{
  bool result; // al
  _DWORD *hKeyData; // eax
  char v5; // al

  if ( this != (GFxMovieDefImplKeyInterface *)a3->pKeyInterface )
    return false;
  hKeyData = a3->hKeyData;
  result = false;
  if ( a2[2] == (CReferenceToHandleTexture *)hKeyData[2] )
  {
    GFxMovieDefBindStates::operator==(this: a2[3], other: hKeyData[3]);
    if ( v5 != 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D4A70
// Name: public: bool GFxMovieDefImpl::DoesDirectlyImport(class GFxMovieDefImpl const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxMovieDefImpl::DoesDirectlyImport(GFxMovieDefImpl *this, const struct GFxMovieDefImpl *a2)
{
  _RTL_CRITICAL_SECTION *v3; // edi
  int v4; // esi
  unsigned int v5; // ecx
  unsigned int v6; // eax
  const struct GFxMovieDefImpl **v7; // edx

  v3 = (_RTL_CRITICAL_SECTION *)(*((_DWORD *)this + 7) + 80);
  EnterCriticalSection(lpCriticalSection: v3);
  v4 = *((_DWORD *)this + 7);
  v5 = *(_DWORD *)(v4 + 72);
  v6 = 0;
  if ( v5 != 0 )
  {
    v7 = *(const struct GFxMovieDefImpl ***)(v4 + 68);
    while ( *v7 != a2 )
    {
      ++v6;
      ++v7;
      if ( v6 >= v5 )
        goto LABEL_5;
    }
    LeaveCriticalSection(lpCriticalSection: v3);
    return 1;
  }
  else
  {
LABEL_5:
    LeaveCriticalSection(lpCriticalSection: v3);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4AC0
// Name: public: void GFxInitImportActions::ExecuteInContext(class GFxSprite __near *,class GFxMovieDefImpl __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxInitImportActions::ExecuteInContext(
        GFxInitImportActions *this,
        GMemoryFile *a2,
        struct GFxMovieDefImpl *pbindDef,
        bool recursiveCheck)
{
  unsigned int v4; // ebx
  int v5; // esi
  int v6; // esi
  __int64 v7; // [esp-4h] [ebp-10h]
  _RTL_CRITICAL_SECTION *v8; // [esp-4h] [ebp-10h]
  int v9; // [esp+4h] [ebp-8h]

  v4 = *((_DWORD *)this + 1);
  v5 = *((_DWORD *)pbindDef + 7);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v5 + 80));
  v8 = (_RTL_CRITICAL_SECTION *)(v5 + 80);
  if ( v4 < *(_DWORD *)(v5 + 72) )
  {
    v6 = *(_DWORD *)(*(_DWORD *)(v5 + 68) + 4 * v4);
    LeaveCriticalSection(lpCriticalSection: v8);
    if ( v6 != 0
      && *(int *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v6 + 28) + 12) + 32) + 268) > 0
      && (!recursiveCheck || v6 != a2->__vftable[1].Tell(this: a2)) )
    {
      LODWORD(v7) = v6;
      GFxSprite::ExecuteImportedInitActions(this: a2, psourceMovie: v7, pdataDef: v9);
    }
  }
  else
  {
    LeaveCriticalSection(lpCriticalSection: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4DA0
// Name: public: class GFxResource __near * GFxResourceHandle::GetResource(class GFxResourceBinding const __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge GFxResourceHandle::GetResource@<eax>(
        GFxResourceHandle *this@<ecx>,
        VertexShaderHandle_t__ *a2@<esi>,
        struct GFxResourceBinding *pbinding)
{
  unsigned int result; // eax
  char v4; // dl
  const char *v5; // esi
  IShaderDevice *v6; // ecx
  IShaderDevice *v7; // esi
  _ENUM_SERVICE_STATUSA *rbd; // [esp+0h] [ebp-8h] BYREF
  int v10; // [esp+4h] [ebp-4h]

  result = (unsigned int)*(this + 1);
  if ( *this != nullptr )
  {
    v4 = pbinding->m_Identifier[20];
    rbd = nullptr;
    v10 = 0;
    if ( v4 != 0 && result < *(_DWORD *)&pbinding->m_CurToken )
    {
      v5 = &pbinding->m_pExpression[8 * result];
      if ( *(_DWORD *)v5 != 0 )
        GRefCountImpl::AddRef(this: *(IShaderDevice **)v5, a2);
      v6 = *(IShaderDevice **)v5;
      rbd = *(_ENUM_SERVICE_STATUSA **)v5;
      v10 = *((_DWORD *)v5 + 1);
    }
    else
    {
      GFxResourceBinding::GetResourceData_Locked(this: pbinding, a2: (struct GFxResourceBindData *)&rbd, a3: result);
      v6 = (IShaderDevice *)rbd;
    }
    v7 = v6;
    if ( v6 != nullptr )
      GFxResource::Release(this: v6);
    return (unsigned int)v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D4E20
// Name: public: class GFxResource __near * GFxResourceHandle::GetResourceAndBinding(class GFxResourceBinding __near *,class GFxResourceBinding __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
IShaderDevice *__userpurge GFxResourceHandle::GetResourceAndBinding@<eax>(
        _DWORD *a1@<ecx>,
        VertexShaderHandle_t__ *a2@<esi>,
        _RATE_QUOTA_LIMIT *__return_ptr retstr,
        _RATE_QUOTA_LIMIT **a4)
{
  unsigned int v5; // eax
  unsigned __int8 RateData; // dl
  int v7; // esi
  IShaderDevice *v8; // ecx
  IShaderDevice *v9; // esi
  _ENUM_SERVICE_STATUSA *rbd; // [esp+0h] [ebp-8h] BYREF
  _RATE_QUOTA_LIMIT *v12; // [esp+4h] [ebp-4h]

  if ( *a1 != 0 )
  {
    v5 = a1[1];
    RateData = retstr[9].RateData;
    rbd = nullptr;
    v12 = nullptr;
    if ( RateData != 0 && v5 < retstr[1].RateData )
    {
      v7 = retstr[2].RateData + 8 * v5;
      if ( *(_DWORD *)v7 != 0 )
        GRefCountImpl::AddRef(this: *(IShaderDevice **)v7, a2);
      v8 = *(IShaderDevice **)v7;
      rbd = *(_ENUM_SERVICE_STATUSA **)v7;
      v12 = *(_RATE_QUOTA_LIMIT **)(v7 + 4);
    }
    else
    {
      GFxResourceBinding::GetResourceData_Locked(
        this: (GFxResourceBinding *)retstr,
        a2: (struct GFxResourceBindData *)&rbd,
        a3: v5);
      v8 = (IShaderDevice *)rbd;
    }
    *a4 = v12;
    v9 = v8;
    if ( v8 != nullptr )
      GFxResource::Release(this: v8);
    return v9;
  }
  else
  {
    *a4 = retstr;
    return (IShaderDevice *)a1[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4EF0
// Name: public: virtual struct GFxTimelineDef::Frame const GFxMovieDataDef::GetPlaylist(int)const
// Source: json
//------------------------------------------------------------------------------
TextureLodOverride::OverrideInfo *__thiscall GFxMovieDataDef::GetPlaylist(
        CP4AutoEditAddFile *this,
        TextureLodOverride::OverrideInfo *frameNumber,
        int frame)
{
  GFxMovieDataDef::LoadTaskData::GetPlaylist(
    this: *((CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)this + 8),
    frameNumber,
    frameNumbera: frame);
  return frameNumber;
}

//------------------------------------------------------------------------------
// Address: 0x100D4F10
// Name: public: virtual bool GFxMovieDataDef::GetInitActions(struct GFxTimelineDef::Frame __near *,int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxMovieDataDef::GetInitActions(
        CP4AutoEditAddFile *this,
        const CP4AutoEditAddFile *pframe,
        unsigned int frame)
{
  int v3; // esi
  int v5; // ecx
  _RTL_CRITICAL_SECTION *v6; // [esp-4h] [ebp-Ch]

  v3 = *((_DWORD *)this + 8);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v3 + 220));
  v6 = (_RTL_CRITICAL_SECTION *)(v3 + 220);
  if ( frame < *(_DWORD *)(v3 + 260) )
  {
    v5 = *(_DWORD *)(v3 + 256);
    pframe->m_spImpl.m_p = *(CP4File **)(v5 + 8 * frame);
    pframe[1].m_spImpl.m_p = *(CP4File **)(v5 + 8 * frame + 4);
    LeaveCriticalSection(lpCriticalSection: v6);
    return 1;
  }
  else
  {
    LeaveCriticalSection(lpCriticalSection: v6);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4F70
// Name: public: void GFxMovieBindProcess::SetBindState(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieBindProcess::SetBindState(GFxMovieBindProcess *this@<ecx>, int a2@<esi>, unsigned int a3)
{
  int v3; // edi
  IMatRenderContextInternal *v4; // esi
  CUtlVector<int,CUtlMemory<int,int> > *v5; // ecx

  v3 = *((_DWORD *)this + 8);
  if ( v3 != 0 )
  {
    v4 = *(IMatRenderContextInternal **)(v3 + 120);
    GMutex::Lock(this: v4 + 2);
    v5 = (CUtlVector<int,CUtlMemory<int,int> > *)(*(_DWORD *)(v3 + 120) + 28);
    *(_DWORD *)(v3 + 116) = a3;
    GWaitCondition::NotifyAll(this: v5, a2);
    GMutex::Unlock(this: v4 + 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4FB0
// Name: public: virtual unsigned int GFxShapeBaseCharacterDef::GetResourceTypeCode(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxShapeBaseCharacterDef::GetResourceTypeCode(string_t *this)
{
  return 34048;
}

//------------------------------------------------------------------------------
// Address: 0x100D5050
// Name: public: virtual void GFxShapeCharacterDef::GetShapeAndPathCounts(unsigned int __near *,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeCharacterDef::GetShapeAndPathCounts(
        CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(unsigned long,void *),unsigned long,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  (*(void (__thiscall **)(CMemberFuncProxy2<CMaterialVar *,void (__thiscall CMaterialVar::*)(unsigned long,void *),unsigned long,void *,CFuncMemPolicyNone> *))(LODWORD(this->m_Proxy.m_pfnProxied) + 68))(a1: &this->m_Proxy);
}

//------------------------------------------------------------------------------
// Address: 0x100D50D0
// Name: public: struct GFxMovieHeaderData __near & GFxMovieHeaderData::operator=(struct GFxMovieHeaderData const __near &)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GFxMovieHeaderData::operator=(float *this, int __that)
{
  float v5; // [esp+4h] [ebp-8h]
  float v6; // [esp+8h] [ebp-4h]
  float __thata; // [esp+14h] [ebp+8h]

  *this = *(float *)__that;
  *(this + 1) = *(float *)(__that + 4);
  __thata = *(float *)(__that + 12);
  v6 = *(float *)(__that + 16);
  v5 = *(float *)(__that + 20);
  *(this + 2) = *(float *)(__that + 8);
  *(this + 3) = __thata;
  *(this + 4) = v6;
  *(this + 5) = v5;
  *(this + 6) = *(float *)(__that + 24);
  *(this + 7) = *(float *)(__that + 28);
  *(this + 8) = *(float *)(__that + 32);
  GFxExporterInfoImpl::SetData(
    a1: *(_WORD *)(__that + 48),
    a2: *(_DWORD *)(__that + 36),
    a3: *(_DWORD *)(__that + 44),
    a4: *(_DWORD *)(__that + 40),
    a5: *(_DWORD *)(__that + 52),
    a: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D5150
// Name: public: virtual GFxMovieDefImpl::~GFxMovieDefImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDefImpl::~GFxMovieDefImpl(GFxMovieDefImpl *this)
{
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,void *),IMaterial *,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v2; // ecx
  IShaderAPI *v3; // ecx
  IShaderAPI *v4; // ecx
  IShaderAPI *v5; // ecx
  IShaderAPI *v6; // ecx

  v2 = *((CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,void *),IMaterial *,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)this
       + 7);
  *(_DWORD *)this = &GFxMovieDefImpl::`vftable'{for `GFxResource'};
  *((_DWORD *)this + 3) = &GFxMovieDefImpl::`vftable'{for `GFxStateBag'};
  GFxMovieDefImpl::BindTaskData::OnMovieDefRelease(this: v2);
  v3 = *((IShaderAPI **)this + 7);
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  v4 = *((IShaderAPI **)this + 6);
  if ( v4 != nullptr )
    GRefCountImpl::Release(this: v4);
  v5 = *((IShaderAPI **)this + 5);
  if ( v5 != nullptr )
    GRefCountImpl::Release(this: v5);
  v6 = *((IShaderAPI **)this + 4);
  if ( v6 != nullptr )
    GRefCountImpl::Release(this: v6);
  *(_DWORD *)this = &GFxResource::`vftable';
  *((_DWORD *)this + 3) = &GFxStateBag::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100D51B0
// Name: public: virtual unsigned int GFxMovieDefImpl::GetResourceTypeCode(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxMovieDefImpl::GetResourceTypeCode(
        CMemberFuncProxy0<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(void),CFuncMemPolicyNone> *this)
{
  return 768;
}

//------------------------------------------------------------------------------
// Address: 0x100D51D0
// Name: public: virtual class GMemoryHeap __near * GFxMovieDefImpl::GetLoadDataHeap(void)const
// Source: json
//------------------------------------------------------------------------------
struct GMemoryHeap *__thiscall GFxMovieDefImpl::GetLoadDataHeap(GFxMovieDefImpl *this)
{
  return *(struct GMemoryHeap **)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 7) + 12) + 32) + 28);
}

//------------------------------------------------------------------------------
// Address: 0x100D51E0
// Name: public: virtual class GMemoryHeap __near * GFxMovieDefImpl::GetBindDataHeap(void)const
// Source: json
//------------------------------------------------------------------------------
struct GMemoryHeap *__thiscall GFxMovieDefImpl::GetBindDataHeap(GFxMovieDefImpl *this)
{
  return *(struct GMemoryHeap **)(*((_DWORD *)this + 7) + 8);
}

//------------------------------------------------------------------------------
// Address: 0x100D51F0
// Name: public: virtual unsigned int GFxMovieDefImpl::GetFrameCount(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxMovieDefImpl::GetFrameCount(
        CMemberFuncProxy0<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(void),CFuncMemPolicyNone> *this,
        unsigned int a2)
{
  return (*(void *(__thiscall **)(_DWORD, unsigned int))(**(_DWORD **)(*((_DWORD *)this + 7) + 12) + 40))(
           a1: *(_DWORD *)(*((_DWORD *)this + 7) + 12),
           a2);
}

//------------------------------------------------------------------------------
// Address: 0x100D5200
// Name: public: virtual float GFxMovieDefImpl::GetFrameRate(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxMovieDefImpl::GetFrameRate(GFxMovieDefImpl *this)
{
  return *(float *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 7) + 12) + 32) + 64);
}

//------------------------------------------------------------------------------
// Address: 0x100D5210
// Name: public: virtual float GFxMovieDefImpl::GetWidth(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxMovieDefImpl::GetWidth(GFxMovieDefImpl *this)
{
  int v1; // eax
  float v3; // [esp+8h] [ebp-4h]
  float v4; // [esp+8h] [ebp-4h]

  v1 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 7) + 12) + 32);
  v3 = *(float *)(v1 + 56) - *(float *)(v1 + 48);
  v4 = v3 / 20.0;
  return (float)ceil(X: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100D5250
// Name: public: virtual float GFxMovieDefImpl::GetHeight(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxMovieDefImpl::GetHeight(GFxMovieDefImpl *this)
{
  int v1; // eax
  float v3; // [esp+8h] [ebp-4h]
  float v4; // [esp+8h] [ebp-4h]

  v1 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 7) + 12) + 32);
  v3 = *(float *)(v1 + 60) - *(float *)(v1 + 52);
  v4 = v3 / 20.0;
  return (float)ceil(X: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100D5290
// Name: public: virtual unsigned int GFxMovieDefImpl::GetVersion(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxMovieDefImpl::GetVersion(
        CMemberFuncProxy0<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(void),CFuncMemPolicyNone> *this,
        unsigned int a2)
{
  return (*(void *(__thiscall **)(_DWORD, unsigned int))(**(_DWORD **)(*((_DWORD *)this + 7) + 12) + 32))(
           a1: *(_DWORD *)(*((_DWORD *)this + 7) + 12),
           a2);
}

//------------------------------------------------------------------------------
// Address: 0x100D52A0
// Name: public: virtual unsigned int GFxMovieDefImpl::GetSWFFlags(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxMovieDefImpl::GetSWFFlags(
        CMemberFuncProxy0<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(void),CFuncMemPolicyNone> *this,
        unsigned int a2)
{
  return (*(void *(__thiscall **)(_DWORD, unsigned int))(**(_DWORD **)(*((_DWORD *)this + 7) + 12) + 68))(
           a1: *(_DWORD *)(*((_DWORD *)this + 7) + 12),
           a2);
}

//------------------------------------------------------------------------------
// Address: 0x100D52B0
// Name: public: virtual char const __near * GFxMovieDefImpl::GetFileURL(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall GFxMovieDefImpl::GetFileURL(GFxMovieDefImpl *this)
{
  return (const char *)((*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 7) + 12) + 32) + 36) & 0xFFFFFFFC) + 8);
}

//------------------------------------------------------------------------------
// Address: 0x100D52D0
// Name: public: virtual struct GFxExporterInfo const __near * GFxMovieDefImpl::GetExporterInfo(void)const
// Source: json
//------------------------------------------------------------------------------
CMatQueuedIndexBuffer *__thiscall GFxMovieDefImpl::GetExporterInfo(_DWORD *this)
{
  int v1; // ecx

  v1 = *(_DWORD *)(*(_DWORD *)(*(this + 7) + 12) + 32);
  return *(_DWORD *)(v1 + 76) != 0 ? (CMatQueuedIndexBuffer *)(v1 + 76) : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100D52F0
// Name: public: virtual class GFxStateBag __near * GFxMovieDefImpl::GetStateBagImpl(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDefImpl::GetStateBagImpl(CMatQueuedIndexBuffer *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100D5300
// Name: public: virtual unsigned int GFxMovieDefImpl::GetFileAttributesA(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxMovieDefImpl::GetFileAttributesA(
        CMemberFuncProxy0<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(void),CFuncMemPolicyNone> *this)
{
  return *(void **)(*(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 7) + 12) + 32) + 116);
}

//------------------------------------------------------------------------------
// Address: 0x100D5310
// Name: public: virtual class GMemoryHeap __near * GFxMovieDefImpl::GetImageHeap(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDefImpl::GetImageHeap(GFxMovieDefImpl *this)
{
  GFxMovieDataDef::LoadTaskData::GetImageHeap(this: *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(*(_DWORD *)(*((_DWORD *)this + 7) + 12) + 32));
}

//------------------------------------------------------------------------------
// Address: 0x100D5320
// Name: public: virtual class GRect<float> GFxMovieDefImpl::GetFrameRect(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
float *__thiscall GFxMovieDefImpl::GetFrameRect(_DWORD *this, float *a2)
{
  float *v2; // ecx

  v2 = *(float **)(*(_DWORD *)(*(this + 7) + 12) + 32);
  *a2 = v2[12] / 20.0;
  a2[1] = v2[13] / 20.0;
  a2[2] = v2[14] / 20.0;
  a2[3] = v2[15] / 20.0;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100D5360
// Name: public: virtual unsigned int GFxMovieDefImpl::GetLoadingFrame(void)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxMovieDefImpl::GetLoadingFrame(
        CMemberFuncProxy0<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(void),CFuncMemPolicyNone> *this)
{
  return *(void **)(*((_DWORD *)this + 7) + 124);
}

//------------------------------------------------------------------------------
// Address: 0x100D5370
// Name: public: virtual void GFxMovieDefImpl::WaitForLoadFinish(bool)const
// Source: json
//------------------------------------------------------------------------------
IMaterialInternal *__thiscall GFxMovieDefImpl::WaitForLoadFinish(CMatQueuedIndexBuffer *this, bool cancel)
{
  int v3; // esi

  GFxMovieDataDef::WaitForLoadFinish(this: *(GFxMovieDataDef **)(this->m_nIndexFormat + 12), a2: cancel);
  v3 = *(_DWORD *)(this->m_nIndexFormat + 120);
  GMutex::Lock(this: (IMatRenderContextInternal *)(v3 + 8));
  while ( *(_BYTE *)(v3 + 32) == 0 )
    GWaitCondition::Wait(this: (GWaitCondition *)(v3 + 28), a2: (struct GMutex *)(v3 + 8), a3: 0xFFFFFFFF);
  return GMutex::Unlock(this: (IMatRenderContextInternal *)(v3 + 8));
}

//------------------------------------------------------------------------------
// Address: 0x100D53C0
// Name: public: virtual void GFxMovieDefImpl::WaitForFrame(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
IMaterialInternal *__thiscall GFxMovieDefImpl::WaitForFrame(CMatQueuedIndexBuffer *this, unsigned int frame)
{
  return GFxMovieDataDef::LoadTaskData::WaitForFrame(
           this: *(int **)(*(_DWORD *)(this->m_nIndexFormat + 12) + 32),
           frame);
}

//------------------------------------------------------------------------------
// Address: 0x100D53E0
// Name: public: virtual unsigned int GFxMovieDefImpl::GetMetadata(char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge GFxMovieDefImpl::GetMetadata@<eax>(
        CMatQueuedIndexBuffer *this@<ecx>,
        unsigned __int8 *pbuff,
        unsigned int buffSize,
        IndexDesc_t *a4)
{
  int v4; // eax
  unsigned int v5; // esi
  unsigned __int8 *v7; // eax

  v4 = *(_DWORD *)(*(_DWORD *)(this->m_nIndexFormat + 12) + 32);
  v5 = buffSize;
  if ( pbuff == nullptr )
    return *(_DWORD *)(v4 + 124);
  if ( buffSize >= *(_DWORD *)(v4 + 124) )
    v5 = *(_DWORD *)(v4 + 124);
  v7 = *(unsigned __int8 **)(v4 + 120);
  if ( v7 != nullptr )
    memcpy(dst: pbuff, src: v7, count: v5);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100D5430
// Name: public: virtual void GFxInitImportActions::Execute(class GFxSprite __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxInitImportActions::Execute(GFxInitImportActions *this, GMemoryFile *a2)
{
  int v3; // esi
  unsigned int v4; // ebx
  int v5; // ebx
  __int64 v6; // [esp-4h] [ebp-10h]
  _RTL_CRITICAL_SECTION *v7; // [esp-4h] [ebp-10h]
  int v8; // [esp+4h] [ebp-8h]

  v3 = *(_DWORD *)(a2->__vftable[1].Tell(this: a2) + 28);
  v4 = *((_DWORD *)this + 1);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v3 + 80));
  v7 = (_RTL_CRITICAL_SECTION *)(v3 + 80);
  if ( v4 < *(_DWORD *)(v3 + 72) )
  {
    v5 = *(_DWORD *)(*(_DWORD *)(v3 + 68) + 4 * v4);
    LeaveCriticalSection(lpCriticalSection: v7);
    if ( v5 != 0 && *(int *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v5 + 28) + 12) + 32) + 268) > 0 )
    {
      LODWORD(v6) = v5;
      GFxSprite::ExecuteImportedInitActions(this: a2, psourceMovie: v6, pdataDef: v8);
    }
  }
  else
  {
    LeaveCriticalSection(lpCriticalSection: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5800
// Name: public: void GFxMovieDataDef::LoadTaskData::BeginSWFLoading(struct GFxMovieHeaderData const __near &)
// Source: json
//------------------------------------------------------------------------------
IMaterialInternal *__thiscall GFxMovieDataDef::LoadTaskData::BeginSWFLoading(
        CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *this,
        int header)
{
  IMatRenderContextInternal *v3; // edi
  int v4; // ebx
  CUtlVector<int,CUtlMemory<int,int> > *v5; // ecx
  int v7; // [esp+0h] [ebp-Ch]

  GFxMovieHeaderData::operator=(this: (float *)this + 10, __that: header);
  v3 = *((IMatRenderContextInternal **)this + 36);
  v4 = *((_DWORD *)this + 33);
  GMutex::Lock(this: v3 + 2);
  v5 = (CUtlVector<int,CUtlMemory<int,int> > *)(*((_DWORD *)this + 36) + 28);
  *((_DWORD *)this + 33) = v4;
  *((_DWORD *)this + 32) = 1;
  GWaitCondition::NotifyAll(this: v5, a2: v7);
  return GMutex::Unlock(this: v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x100D5890
// Name: public: GFxMovieDataDefFileKeyData::GFxMovieDataDefFileKeyData(char const __near *,__int64,class GFxFileOpener __near *,class GFxImageCreator __near *,class GFxPreprocessParams __near *)
// Source: json
//------------------------------------------------------------------------------
GFxMovieDataDefFileKeyData *__thiscall GFxMovieDataDefFileKeyData::GFxMovieDataDefFileKeyData(
        GFxMovieDataDefFileKeyData *this,
        const char *a2,
        __int64 a3,
        IShaderDevice *a4,
        IShaderDevice *a5,
        IShaderDevice *a6)
{
  IShaderAPI *v7; // ecx
  IShaderAPI *v8; // ecx
  IShaderAPI *v9; // ecx
  VertexShaderHandle_t__ *v11; // [esp+0h] [ebp-8h]

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxMovieDataDefFileKeyData::`vftable';
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)((char *)this + 8));
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  GString::operator=(this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)this + 8));
  *((_QWORD *)this + 2) = a3;
  if ( a4 != nullptr )
    GRefCountImpl::AddRef(this: a4, a2: v11);
  v7 = *((IShaderAPI **)this + 3);
  if ( v7 != nullptr )
    GRefCountImpl::Release(this: v7);
  *((_DWORD *)this + 3) = a4;
  if ( a5 != nullptr )
    GRefCountImpl::AddRef(this: a5, a2: v11);
  v8 = *((IShaderAPI **)this + 6);
  if ( v8 != nullptr )
    GRefCountImpl::Release(this: v8);
  *((_DWORD *)this + 6) = a5;
  if ( a6 != nullptr )
    GRefCountImpl::AddRef(this: a6, a2: v11);
  v9 = *((IShaderAPI **)this + 7);
  if ( v9 != nullptr )
    GRefCountImpl::Release(this: v9);
  *((_DWORD *)this + 7) = a6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D59C0
// Name: public: static class GFxResourceKey GFxMovieDataDef::CreateMovieFileKey(char const __near *,__int64,class GFxFileOpener __near *,class GFxImageCreator __near *,class GFxPreprocessParams __near *)
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxy1<CTexture_MultipleRenderTarget *,void (__thiscall CTexture_MultipleRenderTarget::*)(char const *),char const *,CFuncMemPolicyNone> *__cdecl GFxMovieDataDef::CreateMovieFileKey(
        CMemberFuncProxy1<CTexture_MultipleRenderTarget *,void (__thiscall CTexture_MultipleRenderTarget::*)(char const *),char const *,CFuncMemPolicyNone> *result,
        char *a2,
        __int64 modifyTime,
        IShaderDevice *ppreprocessParams,
        IShaderDevice *a5,
        IShaderDevice *a6)
{
  GFxMovieDataDefFileKeyData *v6; // eax
  IShaderAPI *v7; // esi
  int v9; // [esp+8h] [ebp-4h] BYREF

  v9 = 2;
  v6 = (GFxMovieDataDefFileKeyData *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 32, a3: &v9);
  if ( v6 != nullptr )
    v7 = (IShaderAPI *)GFxMovieDataDefFileKeyData::GFxMovieDataDefFileKeyData(
                         this: v6,
                         a2,
                         a3: modifyTime,
                         a4: ppreprocessParams,
                         a5,
                         a6);
  else
    v7 = nullptr;
  GFxResourceKey::GFxResourceKey(this: (GFxResourceKey *)result, a2: &GFxMovieDataDefFileKeyInterface_Instance, a3: v7);
  if ( v7 != nullptr )
    GRefCountImpl::Release(this: v7);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D5A60
// Name: public: virtual class GFxMovieDef::MemoryContext __near * GFxMovieDefImpl::CreateMemoryContext(char const __near *,struct GFxMovieDef::MemoryParams const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
struct GFxMovieDef::MemoryContext *__thiscall GFxMovieDefImpl::CreateMemoryContext(
        GFxMovieDefImpl *this,
        const char *a2,
        int a3,
        int debugHeap)
{
  const struct GFxMovieDef::MemoryParams *v4; // ebx
  struct GMemoryHeap *v5; // esi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  int v7; // eax
  int v8; // edi
  void *(__thiscall *v9)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  GASRefCountCollector *v10; // eax
  IShaderAPI *v11; // ecx
  GASRefCountCollector *v12; // eax
  void *(__thiscall *v13)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // edx
  GASStringManager *v14; // eax
  IShaderAPI *v15; // ecx
  GMemoryHeap::HeapDesc v17; // [esp+Ch] [ebp-20h] BYREF

  v4 = (const struct GFxMovieDef::MemoryParams *)a3;
  v17 = *(GMemoryHeap::HeapDesc *)a3;
  v17.Flags = v17.Flags & 0xFFFFFFFC | ((unsigned __int8)debugHeap != 0 ? 0x1000 : 0) | 2;
  v17.HeapId = 3;
  v17.Limit = 0x20000;
  v5 = GMemory::pGlobalHeap->CreateHeap(this: GMemory::pGlobalHeap, a2, a3: &v17);
  Alloc_2 = v5->Alloc_2;
  a3 = 2;
  v7 = (int)Alloc_2(this: v5, a2: 48u, (const GAllocDebugInfo *)&a3);
  v8 = 0;
  if ( v7 != 0 )
  {
    *(_DWORD *)v7 = &GRefCountImplCore::`vftable';
    *(_DWORD *)(v7 + 8) = 0;
    *(_DWORD *)(v7 + 4) = 1;
    *(_DWORD *)v7 = &GFxMovieRoot::MemoryContextImpl::`vftable';
    *(_DWORD *)(v7 + 12) = 0;
    *(_DWORD *)(v7 + 16) = 0;
    *(_DWORD *)(v7 + 20) = 0;
    *(float *)(v7 + 44) = 0.25;
    *(_DWORD *)(v7 + 32) = 0;
    *(_DWORD *)(v7 + 36) = 0;
    *(_DWORD *)(v7 + 40) = 0;
    *(_DWORD *)(v7 + 24) = &GFxMovieRoot::MemoryContextImpl::HeapLimit::`vftable';
    *(_DWORD *)(v7 + 28) = v7;
    v8 = v7;
  }
  *(_DWORD *)(v8 + 8) = v5;
  v9 = v5->Alloc_2;
  debugHeap = 323;
  v10 = (GASRefCountCollector *)v9(this: v5, a2: 76u, a3: (const GAllocDebugInfo *)&debugHeap);
  if ( v10 != nullptr )
    debugHeap = (int)GASRefCountCollector::GASRefCountCollector(this: v10);
  else
    debugHeap = 0;
  v11 = *(IShaderAPI **)(v8 + 12);
  if ( v11 != nullptr )
    GRefCountImpl::Release(this: v11);
  v12 = (GASRefCountCollector *)debugHeap;
  *(_DWORD *)(v8 + 12) = debugHeap;
  GASRefCountCollector::SetParams(this: v12, a2: v4->FramesBetweenCollections, a3: v4->MaxCollectionRoots);
  v13 = v5->Alloc_2;
  a2 = (const char *)323;
  v14 = (GASStringManager *)v13(this: v5, a2: 44u, a3: (const GAllocDebugInfo *)&a2);
  if ( v14 != nullptr )
    debugHeap = (int)GASStringManager::GASStringManager(this: v14, a2: v5);
  else
    debugHeap = 0;
  v15 = *(IShaderAPI **)(v8 + 16);
  if ( v15 != nullptr )
    GRefCountImpl::Release(this: v15);
  *(_DWORD *)(v8 + 16) = debugHeap;
  *(_DWORD *)(v8 + 32) = v4->Desc.Limit;
  *(float *)(v8 + 44) = v4->HeapLimitMultiplier;
  v5->SetLimitHandler(this: v5, a2: (GMemoryHeap::LimitHandler *)(v8 + 24));
  GMemoryHeap::ReleaseOnFree();
  return (struct GFxMovieDef::MemoryContext *)v8;
}

//------------------------------------------------------------------------------
// Address: 0x100D5BD0
// Name: public: void GFxMovieDefImpl::BindTaskData::UpdateBindingFrame(unsigned int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
LONG __thiscall GFxMovieDefImpl::BindTaskData::UpdateBindingFrame(
        GFxMovieDefImpl::BindTaskData *this,
        LONG frame,
        const CMemberFunctor1<COcclusionQueryMgr *,void (__thiscall COcclusionQueryMgr::*)(OcclusionQueryObjectHandle_t__ *),OcclusionQueryObjectHandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *bytesLoaded)
{
  *(this + 32) = bytesLoaded;
  return InterlockedExchange(Target: (volatile LONG *)this + 31, Value: frame);
}

//------------------------------------------------------------------------------
// Address: 0x100D5C30
// Name: public: static class GFxResourceKey GFxMovieDefImpl::CreateMovieKey(class GFxMovieDataDef __near *,class GFxMovieDefBindStates __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDefImpl::CreateMovieKey(CLateBoundPtr<IMesh> pdataDef, __int128 pbindStates)
{
  IShaderAPI *v2; // eax
  IShaderAPI *v3; // esi
  VertexShaderHandle_t__ *v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+8h] [ebp-4h] BYREF

  v5 = 2;
  v2 = (IShaderAPI *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 16, a3: &v5);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v2->__vftable = (IShaderAPI_vtbl *)&GRefCountImplCore::`vftable';
    v2[1].__vftable = (IShaderAPI_vtbl *)1;
    v2->__vftable = (IShaderAPI_vtbl *)&GFxMovieDefImplKey::`vftable';
    if ( DWORD1(pbindStates) != 0 )
      GRefCountImpl::AddRef(this: (IShaderDevice *)DWORD1(pbindStates), a2: v4);
    v3[2].__vftable = *(IShaderAPI_vtbl **)((char *)&pbindStates + 4);
    if ( DWORD2(pbindStates) != 0 )
      GRefCountImpl::AddRef(this: (IShaderDevice *)DWORD2(pbindStates), a2: v4);
    v3[3].__vftable = *(IShaderAPI_vtbl **)((char *)&pbindStates + 8);
  }
  else
  {
    v3 = nullptr;
  }
  GFxResourceKey::GFxResourceKey(this: (GFxResourceKey *)pbindStates, a2: &GFxMovieDefImplKeyInterface_Instance, a3: v3);
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100D5EE0
// Name: public: virtual class GFxResourceKey GFxMovieDefImpl::GetKey(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxMovieDefImpl::GetKey(GFxMovieDefImpl *this, int pbindStates)
{
  int v2; // eax
  CLateBoundPtr<IMesh> v3; // ecx
  __int128 v5; // [esp-Ch] [ebp-10h]

  v2 = *((_DWORD *)this + 6);
  v3.m_ppObject = *((IMesh ***)this + 7);
  DWORD2(v5) = v2;
  DWORD1(v5) = *((_DWORD *)v3.m_ppObject + 3);
  LODWORD(v5) = pbindStates;
  GFxMovieDefImpl::CreateMovieKey(pdataDef: v3, pbindStates: v5);
  return pbindStates;
}

//------------------------------------------------------------------------------
// Address: 0x100D5F10
// Name: public: bool GFxMovieDataDef::LoadTaskData::FinishLoadingFrame(class GFxLoadProcess __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxMovieDataDef::LoadTaskData::FinishLoadingFrame(
        CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *this,
        int success,
        bool finished)
{
  _DWORD *v5; // eax
  LONG v6; // edi
  _DWORD *v7; // eax
  IMatRenderContextInternal *v8; // ebx
  GFile *v10; // [esp+0h] [ebp-Ch]
  int v11; // [esp+0h] [ebp-Ch]
  unsigned int v12; // [esp+4h] [ebp-8h]
  char success_3; // [esp+17h] [ebp+Bh]

  GFxLoadProcess::CommitFrameTags(this: (GFxLoadProcess *)success);
  success_3 = 1;
  GFxLoadProcess::CreateFrameBindData(this: (GFxAmpCurrentState *)success, a2: v10, a3: v12);
  v6 = (LONG)v5;
  if ( v5 != nullptr )
  {
    *v5 = *((_DWORD *)this + 33);
    v7 = *(_DWORD **)(success + 804);
    if ( v7 == nullptr )
      v7 = (_DWORD *)(success + 40);
    *(_DWORD *)(v6 + 4) = v7[11] + v7[13] - v7[12] - *(_DWORD *)(success + 620);
  }
  v8 = *((IMatRenderContextInternal **)this + 36);
  GMutex::Lock(this: v8 + 2);
  if ( v6 == 0 )
  {
    *((_DWORD *)this + 32) = 4;
    success_3 = 0;
    goto LABEL_12;
  }
  if ( *((_DWORD *)this + 37) != 0 )
    InterlockedExchange(Target: (volatile LONG *)(*((_DWORD *)this + 38) + 32), Value: v6);
  else
    InterlockedExchange(Target: (volatile LONG *)this + 37, Value: v6);
  ++*((_DWORD *)this + 33);
  *((_DWORD *)this + 38) = v6;
  if ( finished )
  {
    *((_DWORD *)this + 32) = 2;
LABEL_12:
    if ( finished || success_3 == 0 )
      GWaitCondition::NotifyAll(this: (CUtlVector<int,CUtlMemory<int,int> > *)(*((_DWORD *)this + 36) + 28), a2: v11);
  }
  GMutex::Unlock(this: v8 + 2);
  return success_3;
}

//------------------------------------------------------------------------------
// Address: 0x100D64D0
// Name: public: virtual struct GFxCharPosInfoFlags GFxPlaceObjectUnpacked::GetFlags(void)const
// Source: json
//------------------------------------------------------------------------------
_BYTE *__thiscall GFxPlaceObjectUnpacked::GetFlags(_BYTE *this, _BYTE *a2)
{
  *a2 = *(this + 87);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100D6520
// Name: public: void GFxMovieDataDef::LoadTaskData::InitEmptyMovieDef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::LoadTaskData::InitEmptyMovieDef(GFxMovieDataDef::LoadTaskData *this)
{
  _RTL_CRITICAL_SECTION *v2; // edi
  IMatRenderContextInternal *v3; // edi
  int v4; // ebx
  CUtlVector<int,CUtlMemory<int,int> > *v5; // ecx
  int v6; // [esp+0h] [ebp-Ch]

  v2 = (_RTL_CRITICAL_SECTION *)((char *)this + 220);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 220));
  GArrayData<GFxTimelineDef::Frame,GAllocatorLH<GFxTimelineDef::Frame,2>,GArrayDefaultPolicy>::Resize(
    this: (GFxKeyboardState *)((char *)this + 244),
    newSize: *((GFxKeyboardState::IListener **)this + 17));
  GArrayData<GFxTimelineDef::Frame,GAllocatorLH<GFxTimelineDef::Frame,2>,GArrayDefaultPolicy>::Resize(
    this: (GFxKeyboardState *)((char *)this + 256),
    newSize: *((GFxKeyboardState::IListener **)this + 17));
  *((_DWORD *)this + 67) = 0;
  LeaveCriticalSection(lpCriticalSection: v2);
  v3 = *((IMatRenderContextInternal **)this + 36);
  v4 = *((_DWORD *)this + 17);
  GMutex::Lock(this: v3 + 2);
  v5 = (CUtlVector<int,CUtlMemory<int,int> > *)(*((_DWORD *)this + 36) + 28);
  *((_DWORD *)this + 33) = v4;
  *((_DWORD *)this + 32) = 2;
  GWaitCondition::NotifyAll(this: v5, a2: v6);
  GMutex::Unlock(this: v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x100D65A0
// Name: public: virtual GFxMovieDefImpl::BindTaskData::~BindTaskData(void)
// Source: json
//------------------------------------------------------------------------------
__int16 __usercall GFxMovieDefImpl::BindTaskData::~BindTaskData@<ax>(
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,void *),IMaterial *,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this@<ecx>,
        int a2@<ebx>)
{
  IMatRenderContextInternal *v3; // edi
  IShaderAPI *v4; // ecx
  int v5; // eax
  IShaderDevice **v6; // edi
  int v7; // ebx
  int v8; // eax
  IShaderDevice **v9; // edi
  int v10; // ebx
  IShaderDevice *m_iRefs; // ecx

  v3 = *((IMatRenderContextInternal **)this + 30);
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *,void *),IMaterial *,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)&GFxMovieDefImpl::BindTaskData::`vftable';
  GMutex::Lock(this: v3 + 2);
  GFxResourceBinding::Destroy(this: (CExpressionEvaluator *)((char *)&this->m_Proxy.m_pfnProxied + 8));
  GMutex::Unlock(this: v3 + 2);
  v4 = *((IShaderAPI **)this + 30);
  if ( v4 != nullptr )
    GRefCountImpl::Release(this: v4);
  v5 = *((_DWORD *)this + 27);
  v6 = (IShaderDevice **)(*((_DWORD *)this + 26) + 4 * v5 - 4);
  if ( v5 != 0 )
  {
    v7 = *((_DWORD *)this + 27);
    do
    {
      if ( *v6 != nullptr )
        GFxResource::Release(this: *v6);
      --v6;
      --v7;
    }
    while ( v7 != 0 );
  }
  ((void (__thiscall *)(GMemoryHeap *, _DWORD, int))GMemory::pGlobalHeap->Free)(
    a1: GMemory::pGlobalHeap,
    a2: *((_DWORD *)this + 26),
    a3: a2);
  GLock::~GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 80));
  v8 = *((_DWORD *)this + 18);
  v9 = (IShaderDevice **)(*((_DWORD *)this + 17) + 4 * v8 - 4);
  if ( v8 != 0 )
  {
    v10 = *((_DWORD *)this + 18);
    do
    {
      if ( *v9 != nullptr )
        GFxResource::Release(this: *v9);
      --v9;
      --v10;
    }
    while ( v10 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 17));
  GFxResourceBinding::~GFxResourceBinding(this: (CExpressionEvaluator *)((char *)&this->m_Proxy.m_pfnProxied + 8));
  m_iRefs = (IShaderDevice *)this->m_iRefs;
  if ( m_iRefs != nullptr )
    GFxResource::Release(this: m_iRefs);
  return GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100D6660
// Name: public: virtual void GFxMovieDefImpl::VisitResources(struct GFxMovieDef::ResourceVisitor __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDefImpl::VisitResources(
        GFxMovieDefImpl *this,
        struct GFxMovieDef::ResourceVisitor *a2,
        unsigned int a3)
{
  GFxMovieDefImpl *v3; // edi
  int v4; // eax
  bool v5; // cc
  int v6; // esi
  int v7; // eax
  VertexShaderHandle_t__ *v8; // esi
  unsigned int v9; // ecx
  unsigned int v10; // edx
  _DWORD *v11; // eax
  unsigned int v12; // ebx
  int v13; // eax
  unsigned int Resource; // eax
  bool v15; // zf
  int v16; // esi
  int v17; // ecx
  unsigned int v18; // eax
  unsigned int v19; // edx
  _DWORD *v20; // ecx
  int v21; // ecx
  unsigned int v22; // edi
  int v23; // esi
  IShaderDevice *v24; // ebx
  _DWORD *v25; // ecx
  LPCRITICAL_SECTION v26; // ecx
  int v27; // ecx
  unsigned int v28; // eax
  _DWORD *v29; // ecx
  unsigned int v30; // esi
  _DWORD *v31; // ebx
  int v32; // ecx
  int v33; // eax
  unsigned int v34; // edi
  IShaderDevice **v35; // esi
  int i; // ebx
  IShaderDevice **v37; // edi
  unsigned int j; // edi
  int v39; // ecx
  IShaderDevice **k; // edi
  struct GFxResourceBinding *v41; // [esp-4h] [ebp-38h]
  _RTL_CRITICAL_SECTION *v42; // [esp-4h] [ebp-38h]
  VertexShaderHandle_t__ *v43; // [esp+0h] [ebp-34h]
  _DWORD *v44; // [esp+Ch] [ebp-28h] BYREF
  int *v45; // [esp+10h] [ebp-24h]
  unsigned int v46; // [esp+14h] [ebp-20h]
  VertexShaderHandle_t__ *v47; // [esp+18h] [ebp-1Ch]
  int v48; // [esp+1Ch] [ebp-18h]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+20h] [ebp-14h]
  IShaderDevice **v50; // [esp+24h] [ebp-10h]
  GFxMovieDefImpl *v51; // [esp+28h] [ebp-Ch]
  int v52; // [esp+2Ch] [ebp-8h]
  unsigned int v53; // [esp+30h] [ebp-4h]

  v3 = this;
  v51 = this;
  if ( (a3 & 0x803F) != 0 )
  {
    v4 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 7) + 12) + 32);
    v5 = *(_DWORD *)(v4 + 128) < 2;
    v52 = 0;
    if ( v5 )
    {
      v52 = v4;
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v4 + 184));
    }
    v6 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v3 + 7) + 12) + 32);
    v7 = *(_DWORD *)(v6 + 208);
    v8 = (VertexShaderHandle_t__ *)(v6 + 208);
    if ( v7 != 0 )
    {
      v10 = *(_DWORD *)(v7 + 4);
      v9 = 0;
      v11 = (_DWORD *)(v7 + 8);
      do
      {
        if ( *v11 != -2 )
          break;
        ++v9;
        v11 += 4;
      }
      while ( v9 <= v10 );
    }
    else
    {
      v8 = nullptr;
      v9 = 0;
    }
    v12 = v9;
    v47 = v8;
    v48 = v9;
    while ( v47 != nullptr )
    {
      v13 = *(_DWORD *)v47;
      if ( *(_DWORD *)v47 == 0 || (signed int)v12 > *(_DWORD *)(v13 + 4) )
        break;
      v41 = (struct GFxResourceBinding *)(*((_DWORD *)v3 + 7) + 24);
      v50 = (IShaderDevice **)(16 * v12);
      Resource = GFxResourceHandle::GetResource(this: (GFxResourceHandle *)(16 * v12 + v13 + 16), a2: v8, pbinding: v41);
      v53 = Resource;
      if ( Resource != 0 )
      {
        v8 = (VertexShaderHandle_t__ *)(*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)Resource + 8))(a1: Resource);
        switch ( (*(unsigned __int16 (__thiscall **)(unsigned int))(*(_DWORD *)v53 + 8))(a1: v53) >> 8 )
        {
          case 1:
            if ( v8 == (VertexShaderHandle_t__ *)1 )
            {
              v15 = (a3 & 2) == 0;
              goto LABEL_23;
            }
            if ( v8 == (VertexShaderHandle_t__ *)2 )
            {
              v15 = (a3 & 4) == 0;
              goto LABEL_23;
            }
            goto LABEL_43;
          case 2:
            v15 = (a3 & 1) == 0;
            goto LABEL_23;
          case 4:
            v15 = (a3 & 0x10) == 0;
            goto LABEL_23;
          case 131:
            v15 = (a3 & 8) == 0;
            goto LABEL_23;
          case 132:
            v15 = (a3 & 0x20) == 0;
LABEL_23:
            if ( v15 )
              goto LABEL_43;
            v16 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v3 + 7) + 12) + 32);
            v17 = *(_DWORD *)(v16 + 212);
            v8 = (VertexShaderHandle_t__ *)(v16 + 212);
            v18 = 0;
            lpCriticalSection = nullptr;
            if ( v17 != 0 )
            {
              v19 = *(_DWORD *)(v17 + 4);
              v20 = (_DWORD *)(v17 + 8);
              do
              {
                if ( *v20 != -2 )
                  break;
                ++v18;
                v20 += 5;
              }
              while ( v18 <= v19 );
              v45 = (int *)v8;
            }
            else
            {
              v45 = nullptr;
            }
            break;
          default:
            goto LABEL_43;
        }
        while ( v45 != nullptr )
        {
          v21 = *v45;
          if ( *v45 == 0 )
            break;
          v22 = *(_DWORD *)(v21 + 4);
          if ( (int)v18 > (int)v22 )
            break;
          v23 = 5 * v18 + 5;
          v24 = *(IShaderDevice **)(v21 + 4 * v23);
          v8 = (VertexShaderHandle_t__ *)(v21 + 4 * v23);
          if ( v24 == *(IShaderDevice **)((char *)v50 + *(_DWORD *)v47 + 16) )
          {
            v8 = *((VertexShaderHandle_t__ **)v8 + 1);
            if ( v8 == (VertexShaderHandle_t__ *)*(IShaderDevice **)((char *)v50 + *(_DWORD *)v47 + 20) )
            {
              v26 = (LPCRITICAL_SECTION)((*(_DWORD *)(*v45 + 20 * v18 + 16) & 0xFFFFFFFC) + 8);
              goto LABEL_42;
            }
          }
          if ( ++v18 <= v22 )
          {
            v25 = (_DWORD *)(v21 + 20 * v18 + 8);
            do
            {
              if ( *v25 != -2 )
                break;
              ++v18;
              v25 += 5;
            }
            while ( v18 <= v22 );
          }
        }
        v26 = lpCriticalSection;
LABEL_42:
        ((void (__thiscall *)(struct GFxMovieDef::ResourceVisitor *, GFxMovieDefImpl *, unsigned int, _DWORD, LPCRITICAL_SECTION))a2->Visit)(
          a1: a2,
          a2: v51,
          a3: v53,
          a4: *(IShaderDevice **)((char *)v50 + *(_DWORD *)v47 + 12),
          a5: v26);
        v3 = v51;
        v12 = v48;
      }
LABEL_43:
      v27 = *(_DWORD *)v47;
      v28 = *(_DWORD *)(*(_DWORD *)v47 + 4);
      if ( (int)v12 <= (int)v28 )
      {
        v48 = ++v12;
        if ( v12 <= v28 )
        {
          v29 = (_DWORD *)(v27 + 16 * v12 + 8);
          do
          {
            if ( *v29 != -2 )
              break;
            ++v12;
            v29 += 4;
            v48 = v12;
          }
          while ( v12 <= v28 );
        }
      }
    }
    if ( v52 != 0 )
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v52 + 184));
  }
  if ( (a3 & 0x8000) != 0 )
  {
    v30 = 0;
    v31 = nullptr;
    v42 = (_RTL_CRITICAL_SECTION *)(*((_DWORD *)v3 + 7) + 80);
    v44 = nullptr;
    v45 = nullptr;
    v46 = 0;
    lpCriticalSection = v42;
    EnterCriticalSection(lpCriticalSection: v42);
    v32 = *((_DWORD *)v3 + 7);
    if ( *(_DWORD *)(v32 + 72) != 0 )
    {
      GArrayDataBase<GPtr<GFxMovieDefImpl>,GAllocatorGH<GPtr<GFxMovieDefImpl>,265>,GArrayDefaultPolicy>::Reserve(
        this: (void **)&v44,
        a2: (int)&v44,
        a3: *(_DWORD *)(v32 + 72));
      v30 = (unsigned int)v45;
      v31 = v44;
    }
    v33 = *((_DWORD *)v3 + 7);
    v15 = *(_DWORD *)(v33 + 72) == 0;
    v52 = 0;
    if ( !v15 )
    {
      while ( 1 )
      {
        v34 = v30 + 1;
        v50 = (IShaderDevice **)(*(_DWORD *)(v33 + 68) + 4 * v52);
        if ( v30 + 1 < v30 )
          break;
        if ( v34 >= v46 )
        {
          GArrayDataBase<GPtr<GFxMovieDefImpl>,GAllocatorGH<GPtr<GFxMovieDefImpl>,265>,GArrayDefaultPolicy>::Reserve(
            this: (void **)&v44,
            a2: (int)&v44,
            a3: v34 + (v34 >> 2));
LABEL_64:
          v31 = v44;
        }
        v30 = v34;
        v37 = (IShaderDevice **)&v31[v34 - 1];
        v45 = (int *)v30;
        if ( v37 != nullptr )
        {
          if ( *v50 != nullptr )
            GRefCountImpl::AddRef(this: *v50, a2: v43);
          *v37 = *v50;
        }
        v33 = *((_DWORD *)v51 + 7);
        if ( (unsigned int)++v52 >= *(_DWORD *)(v33 + 72) )
          goto LABEL_70;
      }
      v35 = (IShaderDevice **)&v31[v30 - 1];
      for ( i = -1; i != 0; --i )
      {
        if ( *v35 != nullptr )
          GFxResource::Release(this: *v35);
        --v35;
      }
      if ( v34 < v46 >> 1 )
        GArrayDataBase<GPtr<GFxMovieDefImpl>,GAllocatorGH<GPtr<GFxMovieDefImpl>,265>,GArrayDefaultPolicy>::Reserve(
          this: (void **)&v44,
          a2: (int)&v44,
          a3: v34);
      goto LABEL_64;
    }
LABEL_70:
    LeaveCriticalSection(lpCriticalSection);
    for ( j = 0; j < v30; ++j )
    {
      v39 = v31[j];
      if ( v39 != 0 )
        (*(void (__thiscall **)(int, struct GFxMovieDef::ResourceVisitor *, unsigned int))(*(_DWORD *)v39 + 104))(
          a1: v39,
          a2,
          a3);
    }
    for ( k = (IShaderDevice **)&v31[v30 - 1]; v30 != 0; --v30 )
    {
      if ( *k != nullptr )
        GFxResource::Release(this: *k);
      --k;
    }
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v31);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6BC0
// Name: class GFxPlaceObjectUnpacked __near * G_Construct<class GFxPlaceObjectUnpacked>(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_Construct<GFxPlaceObjectUnpacked>(int a1)
{
  const CMaterialDict::MissingMaterial_t *v2; // [esp+0h] [ebp-8h]

  if ( a1 == 0 )
    return 0;
  *(_DWORD *)a1 = &GFxPlaceObjectUnpacked::`vftable';
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 12) = 0;
  GRenderer::Cxform::Cxform();
  GMatrix2D::SetIdentity(result: v2);
  *(_DWORD *)(a1 + 80) = 0x40000;
  *(_BYTE *)(a1 + 87) = 0;
  *(float *)(a1 + 72) = 0.0;
  *(_WORD *)(a1 + 84) = 0;
  *(_DWORD *)(a1 + 76) = 0;
  *(_BYTE *)(a1 + 86) = 0;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x100D72C0
// Name: public: static bool GFxMovieDataDef::TranslateFrameString(class GFxStringHashLH<unsigned int,2,struct GString::NoCaseHashFunctor,struct GStringLH_HashNode<unsigned int,struct GString::NoCaseHashFunctor>,class GHashsetCachedNodeEntry<struct GStringLH_HashNode<unsigned int,struct GString::NoCaseHashFunctor>,struct GStringLH_HashNode<unsigned int,struct GString::NoCaseHashFunctor>::NodeHashF>> const __near &,char const __near *,unsigned int __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GFxMovieDataDef::TranslateFrameString(
        const CP4AutoEditAddFile *result,
        char *a2,
        unsigned int *frameNumber,
        bool translateNumbers)
{
  char *v4; // esi
  char v5; // al
  char v6; // dl
  char *v7; // ecx
  double v8; // st7
  char v10; // al
  void *v11; // esi
  char v12; // bl
  GString v13[2]; // [esp+4h] [ebp-Ch] BYREF
  char *tail; // [esp+Ch] [ebp-4h] BYREF

  v4 = a2;
  if ( a2 == nullptr )
    return 0;
  v5 = *a2;
  if ( *a2 == 0 )
    return 0;
  if ( translateNumbers )
  {
    v6 = 0;
    v7 = a2;
    do
    {
      if ( (unsigned __int8)(v5 - 48) > 9u )
      {
        if ( (v5 != 43 && v5 != 45 || v6 != 0) && v5 != 32 && v5 != 9 )
          goto translate_frame_label;
      }
      else
      {
        v6 = 1;
      }
      v5 = *++v7;
    }
    while ( v5 != 0 );
    tail = nullptr;
    v8 = G_strtod(a1: a2, a2: &tail);
    *(_QWORD *)&v13[0].pData = (__int64)v8;
    if ( tail == v4 || *tail != 0 )
    {
      return 0;
    }
    else
    {
      *frameNumber = (__int64)v8 - 1;
      return 1;
    }
  }
  else
  {
translate_frame_label:
    a2 = (char *)GString::GString(this: &v13[1], a2);
    v10 = GStringHashLH<unsigned int,2,GString::NoCaseHashFunctor,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GHashsetCachedNodeEntry<GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeHashF>>::GetAlt<GString::NoCaseKey>(
            a1: &a2,
            a2: frameNumber);
    v11 = (void *)(v13[1].HeapTypeBits & 0xFFFFFFFC);
    v12 = v10;
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v13[1].HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
    return v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D73B0
// Name: public: bool GFxMovieDataDef::LoadTaskData::GetLabeledFrame(char const __near *,unsigned int __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::LoadTaskData::GetLabeledFrame(
        CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *this,
        const TextureLodOverride::OverrideInfo *label,
        unsigned int *frameNumber,
        bool translateNumbers)
{
  _RTL_CRITICAL_SECTION *v5; // esi

  if ( *((int *)this + 32) < 2 )
  {
    v5 = (_RTL_CRITICAL_SECTION *)(this + 11);
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 11));
    GFxMovieDataDef::TranslateFrameString(
      result: (const CP4AutoEditAddFile *)this + 68,
      a2: &label->x,
      frameNumber,
      translateNumbers);
    LeaveCriticalSection(lpCriticalSection: v5);
  }
  else
  {
    GFxMovieDataDef::TranslateFrameString(
      result: (const CP4AutoEditAddFile *)this + 68,
      a2: &label->x,
      frameNumber,
      translateNumbers);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D7420
// Name: public: GFxMovieBindProcess::GFxMovieBindProcess(class GFxLoadStates __near *,class GFxMovieDefImpl __near *,struct GFxLoaderImpl::LoadStackItem __near *)
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),CFuncMemPolicyNone> *__thiscall GFxMovieBindProcess::GFxMovieBindProcess(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),CFuncMemPolicyNone> *this,
        tagENUMLOGFONTEXDVW *pls,
        int a3,
        _SECURITY_QUALITY_OF_SERVICE *ploadStack)
{
  int v5; // ebx
  IShaderDevice *v6; // ecx
  _SECURITY_QUALITY_OF_SERVICE *v7; // ecx
  int v8; // edx
  int v9; // ecx
  bool v10; // al
  int v11; // ebx
  int lfOrientation; // eax
  int v13; // eax
  int lfEscapement; // ecx
  int (__thiscall *v15)(int, CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),CFuncMemPolicyNone> *, _DWORD, tagCBT_CREATEWNDW **); // edx
  int v16; // eax
  GRefCountNTSImpl *v17; // ecx
  int v18; // edi
  _DWORD *v19; // eax
  VertexShaderHandle_t__ *v21; // [esp+0h] [ebp-3Ch]
  tagCBT_CREATEWNDW *icreateInfo; // [esp+Ch] [ebp-30h] BYREF
  int v23; // [esp+10h] [ebp-2Ch]
  int v24; // [esp+14h] [ebp-28h]
  int v25; // [esp+18h] [ebp-24h]
  int v26; // [esp+1Ch] [ebp-20h]
  int v27; // [esp+20h] [ebp-1Ch]
  int v28; // [esp+24h] [ebp-18h]
  int v29; // [esp+28h] [ebp-14h]
  int v30; // [esp+2Ch] [ebp-10h]
  int v31; // [esp+30h] [ebp-Ch]
  int v32; // [esp+34h] [ebp-8h]
  char v33; // [esp+38h] [ebp-4h]

  GFxLoaderTask::GFxLoaderTask(result: pls);
  v5 = a3;
  LODWORD(this->m_pfnProxied) = &GFxMovieBindProcess::`vftable';
  *((_DWORD *)&this->m_pObject + 1) = 0;
  *((_DWORD *)this + 6) = 589824;
  *((_DWORD *)this + 7) = 0;
  v6 = *(IShaderDevice **)(v5 + 28);
  if ( v6 != nullptr )
    GRefCountImpl::AddRef(this: v6, a2: v21);
  v7 = ploadStack;
  *((_DWORD *)this + 8) = *(_DWORD *)(v5 + 28);
  v8 = *((_DWORD *)this + 8);
  *((_DWORD *)this + 11) = v7;
  v9 = *(_DWORD *)(v8 + 12);
  *((_DWORD *)this + 9) = v9;
  v10 = ((*(int (__thiscall **)(int))(*(_DWORD *)v9 + 68))(a1: v9) & 0x10) != 0;
  *((_BYTE *)this + 40) = v10;
  v11 = *(_DWORD *)(pls->elfEnumLogfontEx.elfLogFont.lfEscapement + 40);
  if ( v11 == 0 || v10 )
  {
    *((_DWORD *)this + 12) = 0;
    return this;
  }
  else
  {
    v28 = *(_DWORD *)&pls->elfEnumLogfontEx.elfLogFont.lfFaceName[2];
    lfOrientation = pls->elfEnumLogfontEx.elfLogFont.lfOrientation;
    icreateInfo = (tagCBT_CREATEWNDW *)1;
    v26 = 0;
    v24 = 0;
    v23 = 1;
    v25 = 1;
    v32 = 0;
    v27 = 0;
    v29 = lfOrientation;
    v30 = 0;
    v31 = 0;
    if ( LOBYTE(pls->elfEnumLogfontEx.elfLogFont.lfFaceName[20]) != 0
      || (v33 = 0, *(_DWORD *)&pls->elfEnumLogfontEx.elfLogFont.lfOutPrecision != 0) )
    {
      v33 = 1;
    }
    v13 = (*(int (__thiscall **)(int))(*(_DWORD *)a3 + 72))(a1: a3);
    lfEscapement = pls->elfEnumLogfontEx.elfLogFont.lfEscapement;
    v15 = *(int (__thiscall **)(int, CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),CFuncMemPolicyNone> *, _DWORD, tagCBT_CREATEWNDW **))(*(_DWORD *)v11 + 8);
    v32 = v13;
    v16 = v15(a1: v11, a2: this + 1, a3: *(_DWORD *)(lfEscapement + 16), a4: &icreateInfo);
    v17 = *((GRefCountNTSImpl **)this + 7);
    v18 = v16;
    if ( v17 != nullptr )
      GRefCountNTSImpl::Release(this: v17);
    *((_DWORD *)this + 7) = v18;
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v18 + 4))(a1: v18, a2: *((_DWORD *)this + 8));
    a3 = 2;
    v19 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 4, &a3);
    if ( v19 != nullptr )
    {
      *v19 = 0;
      *((_DWORD *)this + 12) = v19;
    }
    else
    {
      *((_DWORD *)this + 12) = 0;
    }
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D7570
// Name: public: virtual void GFxMovieBindProcess::OnAbandon(bool)
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CFuncMemPolicyNone> *__userpurge GFxMovieBindProcess::OnAbandon@<eax>(
        int a1@<ecx>,
        int a2@<edi>,
        CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CFuncMemPolicyNone> *result)
{
  int v3; // esi
  IMatRenderContextInternal *v4; // edi
  CUtlVector<int,CUtlMemory<int,int> > *v5; // ecx
  CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CFuncMemPolicyNone> *v6; // eax

  v3 = *(_DWORD *)(a1 + 32);
  if ( v3 != 0 )
  {
    if ( (_BYTE)result != 0 )
    {
      *(_BYTE *)(v3 + 132) = 1;
    }
    else
    {
      v4 = *(IMatRenderContextInternal **)(v3 + 120);
      GMutex::Lock(this: v4 + 2);
      v5 = (CUtlVector<int,CUtlMemory<int,int> > *)(*(_DWORD *)(v3 + 120) + 28);
      *(_DWORD *)(v3 + 116) = 3;
      GWaitCondition::NotifyAll(this: v5, a2);
      return (CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CFuncMemPolicyNone> *)GMutex::Unlock(this: v4 + 2);
    }
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100D75C0
// Name: public: GFxMovieDefImpl::BindTaskData::BindTaskData(class GMemoryHeap __near *,class GFxMovieDataDef __near *,class GFxMovieDefImpl __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
GFxMovieDefImpl::BindTaskData *__thiscall GFxMovieDefImpl::BindTaskData::BindTaskData(
        GFxMovieDefImpl::BindTaskData *this,
        ExprNode *pheap,
        IShaderDevice *pdefImpl,
        struct GFxMovieDefImpl *a4,
        const CMemberFunctor1<COcclusionQueryMgr *,void (__thiscall COcclusionQueryMgr::*)(OcclusionQueryObjectHandle_t__ *),OcclusionQueryObjectHandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *loadFlags,
        bool fullyLoaded)
{
  IMatRenderContextInternal *v7; // eax
  IMatRenderContextInternal *v8; // edi
  IShaderAPI *v9; // ecx
  const CMemberFunctor1<COcclusionQueryMgr *,void (__thiscall COcclusionQueryMgr::*)(OcclusionQueryObjectHandle_t__ *),OcclusionQueryObjectHandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v10; // eax
  int v11; // ecx
  VertexShaderHandle_t__ *v13; // [esp+0h] [ebp-10h]
  int v14; // [esp+Ch] [ebp-4h] BYREF

  *this = (GFxMovieDefImpl::BindTaskData)&GRefCountImplCore::`vftable';
  *(this + 1) = (GFxMovieDefImpl::BindTaskData)1;
  *this = (GFxMovieDefImpl::BindTaskData)&GFxMovieDefImpl::BindTaskData::`vftable';
  *(this + 2) = (GFxMovieDefImpl::BindTaskData)pheap;
  if ( pdefImpl != nullptr )
    GRefCountImpl::AddRef(this: pdefImpl, a2: v13);
  *(this + 3) = (GFxMovieDefImpl::BindTaskData)pdefImpl;
  *(this + 4) = (GFxMovieDefImpl::BindTaskData)a4;
  GFxResourceBinding::GFxResourceBinding(this: (CExpressionEvaluator *)(this + 6), pheap);
  *(this + 17) = nullptr;
  *(this + 18) = nullptr;
  *(this + 19) = nullptr;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)(this + 20), spinCount: 0);
  *(this + 26) = nullptr;
  *(this + 27) = nullptr;
  *(this + 28) = nullptr;
  *(this + 30) = nullptr;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 9));
  *(this + 16) = (GFxMovieDefImpl::BindTaskData)a4;
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 9));
  *(this + 5) = loadFlags;
  *((_BYTE *)this + 132) = 0;
  *(this + 31) = nullptr;
  *(this + 32) = nullptr;
  *(this + 29) = nullptr;
  v14 = 265;
  v7 = (IMatRenderContextInternal *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 36, a3: &v14);
  v8 = v7;
  if ( v7 != nullptr )
  {
    v7->__vftable = (IMatRenderContextInternal_vtbl *)&GRefCountImplCore::`vftable';
    v7[1].__vftable = (IMatRenderContextInternal_vtbl *)1;
    v7->__vftable = (IMatRenderContextInternal_vtbl *)&GFxLoadUpdateSync::`vftable';
    GMutex::GMutex(this: v7 + 2, recursive: 1);
    GWaitCondition::GWaitCondition(this: (CUtlVector<int,CUtlMemory<int,int> > *)&v8[7]);
    LOBYTE(v8[8].__vftable) = 0;
  }
  else
  {
    v8 = nullptr;
  }
  v9 = (IShaderAPI *)*(this + 30);
  if ( v9 != nullptr )
    GRefCountImpl::Release(this: v9);
  *(this + 30) = (GFxMovieDefImpl::BindTaskData)v8;
  if ( fullyLoaded )
  {
    v10 = (const CMemberFunctor1<COcclusionQueryMgr *,void (__thiscall COcclusionQueryMgr::*)(OcclusionQueryObjectHandle_t__ *),OcclusionQueryObjectHandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(*(this + 3))->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable[4].AddRef(this: (struct CMemberFunctor1<COcclusionQueryMgr *,void (__thiscall COcclusionQueryMgr::*)(OcclusionQueryObjectHandle_t__ *),OcclusionQueryObjectHandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)*(this + 3));
    v11 = (int)*(this + 3);
    *(this + 31) = v10;
    *(this + 32) = *(GFxMovieDefImpl::BindTaskData *)(*(_DWORD *)(v11 + 32) + 40);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D7720
// Name: public: bool GFxMovieDefImpl::GetExportedResource(struct GFxResourceBindData __near *,class GString const __near &,class GFxMovieDefImpl __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxMovieDefImpl::GetExportedResource(
        _DWORD *this,
        CMatQueuedIndexBuffer *result,
        unsigned int a3,
        _IMAGE_SECTION_HEADER::<unnamed_type_Misc> ignoreDef)
{
  int v5; // eax
  int v6; // esi
  bool v7; // cc
  char v8; // bl
  IShaderDevice *Resource; // eax
  CMatQueuedIndexBuffer_vtbl *v10; // edi
  bool v11; // bl
  unsigned int v13; // ebx
  _RTL_CRITICAL_SECTION *v14; // esi
  int v15; // ecx
  int v16; // eax
  unsigned int v17; // ecx
  int v18; // eax
  IShaderDevice *v19; // esi
  int v20; // esi
  IShaderDevice **j; // esi
  void *v22; // edi
  IShaderDevice **v23; // esi
  VertexShaderHandle_t__ *v24; // [esp+0h] [ebp-28h]
  _DWORD *v25; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned int v26; // [esp+10h] [ebp-18h]
  int v27; // [esp+14h] [ebp-14h]
  _TRIVERTEX *hres; // [esp+18h] [ebp-10h] BYREF
  IShaderDevice *v29; // [esp+1Ch] [ebp-Ch]
  _RTL_CRITICAL_SECTION *v30; // [esp+20h] [ebp-8h]
  unsigned int i; // [esp+24h] [ebp-4h] BYREF

  v5 = *(_DWORD *)(*(_DWORD *)(*(this + 7) + 12) + 32);
  v6 = 0;
  v7 = *(_DWORD *)(v5 + 128) < 2;
  hres = nullptr;
  v29 = nullptr;
  if ( v7 )
  {
    v6 = v5;
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v5 + 184));
  }
  i = a3;
  v8 = GStringHashLH<GFxResourceHandle,2,GString::NoCaseHashFunctor,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GHashsetCachedNodeEntry<GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeHashF>>::GetAlt<GString::NoCaseKey>(
         a1: &i,
         a2: &hres);
  if ( v6 != 0 )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v6 + 184));
  if ( v8 != 0 )
  {
    if ( hres == (_TRIVERTEX *)1 )
    {
      GFxResourceBinding::GetResourceData(
        this: (GFxResourceBinding *)(*(this + 7) + 24),
        a2: (struct GFxResourceBindData *)result,
        a3: (unsigned int)v29);
    }
    else
    {
      result->m_pOwner = (CMatQueuedRenderContext *)(*(this + 7) + 24);
      Resource = (IShaderDevice *)GFxResourceHandle::GetResource(
                                    this: &hres,
                                    a2: (VertexShaderHandle_t__ *)result,
                                    pbinding: (struct GFxResourceBinding *)(*(this + 7) + 24));
      v10 = (CMatQueuedIndexBuffer_vtbl *)Resource;
      if ( Resource != nullptr )
        GRefCountImpl::AddRef(this: Resource, a2: v24);
      if ( result->__vftable != nullptr )
        GFxResource::Release(this: (IShaderDevice *)result->__vftable);
      result->__vftable = v10;
    }
    v11 = result->__vftable != nullptr;
    if ( hres == nullptr && v29 != nullptr )
      GFxResource::Release(this: v29);
    return v11;
  }
  else
  {
    v13 = 0;
    v14 = (_RTL_CRITICAL_SECTION *)(*(this + 7) + 80);
    v25 = nullptr;
    v26 = 0;
    v27 = 0;
    v30 = v14;
    EnterCriticalSection(lpCriticalSection: v14);
    v15 = *(this + 7);
    if ( *(_DWORD *)(v15 + 72) != 0 )
    {
      GArrayDataBase<GPtr<GFxMovieDefImpl>,GAllocatorGH<GPtr<GFxMovieDefImpl>,265>,GArrayDefaultPolicy>::Reserve(
        this: (void **)&v25,
        a2: (int)&v25,
        a3: *(_DWORD *)(v15 + 72));
      v13 = v26;
    }
    v16 = *(this + 7);
    v17 = 0;
    i = 0;
    if ( *(_DWORD *)(v16 + 72) != 0 )
    {
      do
      {
        v18 = *(_DWORD *)(v16 + 68);
        v19 = *(IShaderDevice **)(v18 + 4 * v17);
        if ( v19 != (IShaderDevice *)ignoreDef.PhysicalAddress )
        {
          if ( v19 != nullptr )
            GRefCountImpl::AddRef(this: *(IShaderDevice **)(v18 + 4 * v17), a2: v24);
          GArrayDataBase<GPtr<GFxMovieDefImpl>,GAllocatorGH<GPtr<GFxMovieDefImpl>,265>,GArrayDefaultPolicy>::ResizeNoConstruct(
            a1: (int)&v25,
            a2: (VertexShaderHandle_t__ *)(v13 + 1),
            a3: (int)&v25,
            a4: v13 + 1);
          v13 = v26;
          if ( &v25[v26] != (_DWORD *)4 )
          {
            if ( v19 != nullptr )
              GRefCountImpl::AddRef(this: v19, a2: v24);
            v25[v13 - 1] = v19;
          }
          if ( v19 != nullptr )
            GFxResource::Release(this: v19);
        }
        v16 = *(this + 7);
        v17 = i + 1;
        i = v17;
      }
      while ( v17 < *(_DWORD *)(v16 + 72) );
      v14 = v30;
    }
    LeaveCriticalSection(lpCriticalSection: v14);
    v20 = 0;
    if ( v13 != 0 )
    {
      while ( v25[v20] == 0 || (unsigned __int8)GFxMovieDefImpl::GetExportedResource(result) == 0 )
      {
        if ( ++v20 >= v13 )
          goto LABEL_35;
      }
      v22 = v25;
      v23 = (IShaderDevice **)&v25[v13 - 1];
      do
      {
        if ( *v23 != nullptr )
          GFxResource::Release(this: *v23);
        --v23;
        --v13;
      }
      while ( v13 != 0 );
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v22);
      if ( hres == nullptr && v29 != nullptr )
        GFxResource::Release(this: v29);
      return 1;
    }
    else
    {
LABEL_35:
      for ( j = (IShaderDevice **)&v25[v13 - 1]; v13 != 0; --v13 )
      {
        if ( *j != nullptr )
          GFxResource::Release(this: *j);
        --j;
      }
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v25);
      if ( hres == nullptr && v29 != nullptr )
        GFxResource::Release(this: v29);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D7970
// Name: public: class GString const __near * GFxMovieDefImpl::GetNameOfExportedResource(class GFxResourceId)const
// Source: json
//------------------------------------------------------------------------------
CMatQueuedIndexBuffer *__thiscall GFxMovieDefImpl::GetNameOfExportedResource(
        CMatQueuedIndexBuffer *this,
        const CMatQueuedIndexBuffer *rid)
{
  int v2; // ecx
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // esi

  v2 = *(_DWORD *)(this->m_nIndexFormat + 12);
  v3 = *(_DWORD *)(v2 + 32);
  v4 = 0;
  if ( *(int *)(v3 + 128) < 2 )
  {
    v4 = *(_DWORD *)(v2 + 32);
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v3 + 184));
  }
  v5 = GHashSetBase<GHashNode<GFxResourceId,GStringLH,GFixedSizeHash<GFxResourceId>>,GHashNode<GFxResourceId,GStringLH,GFixedSizeHash<GFxResourceId>>::NodeHashF,GHashNode<GFxResourceId,GStringLH,GFixedSizeHash<GFxResourceId>>::NodeAltHashF,GAllocatorLH<GFxResourceId,2>,GHashsetCachedNodeEntry<GHashNode<GFxResourceId,GStringLH,GFixedSizeHash<GFxResourceId>>,GHashNode<GFxResourceId,GStringLH,GFixedSizeHash<GFxResourceId>>::NodeHashF>>::GetAlt<GFxResourceId>(a1: &rid);
  if ( v5 != 0 )
    v6 = v5 + 4;
  else
    v6 = 0;
  if ( v4 != 0 )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v4 + 184));
  return (CMatQueuedIndexBuffer *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x100D79E0
// Name: public: virtual class GFxResource __near * GFxMovieDefImpl::GetResource(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
GString::DataDesc *__thiscall GFxMovieDefImpl::GetResource(CMatQueuedIndexBuffer *this, GString a2)
{
  GString::DataDesc *result; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // edi
  int v7; // edx
  void *v8; // esi
  unsigned int Resource; // esi
  void *v10; // edi
  int *v11; // [esp+4h] [ebp-Ch] BYREF
  int v12; // [esp+8h] [ebp-8h]
  GString *v13; // [esp+Ch] [ebp-4h] BYREF

  result = a2.pData;
  if ( a2.pData != nullptr )
  {
    GString::GString(this: &a2, a2: (const char *)a2.pData);
    v4 = *(_DWORD *)(this->m_nIndexFormat + 12);
    v5 = *(_DWORD *)(v4 + 32);
    v6 = 0;
    if ( *(int *)(v5 + 128) < 2 )
    {
      v6 = *(_DWORD *)(v4 + 32);
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v5 + 184));
    }
    v13 = &a2;
    GHashSetBase<GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<GFxResourceHandle,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeHashF>>::FindAlt<GString::NoCaseKey>(
      a1: &v11,
      a2: &v13);
    if ( v11 != nullptr && (v7 = *v11, *v11 != 0) && v12 <= *(_DWORD *)(v7 + 4) )
    {
      Resource = GFxResourceHandle::GetResource(
                   this: (GFxResourceHandle *)(v7 + 20 * v12 + 20),
                   a2: (VertexShaderHandle_t__ *)this,
                   pbinding: (struct GFxResourceBinding *)(this->m_nIndexFormat + 24));
      if ( v6 != 0 )
        LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v6 + 184));
      v10 = (void *)(a2.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((a2.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v10);
      return (GString::DataDesc *)Resource;
    }
    else
    {
      if ( v6 != 0 )
        LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v6 + 184));
      v8 = (void *)(a2.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((a2.HeapTypeBits & 0xFFFFFFFC) + 4), Value: -1) == 1 )
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v8);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D8220
// Name: public: virtual bool GFxMovieDataDef::GetLabeledFrame(char const __near *,unsigned int __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::GetLabeledFrame(
        CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **this,
        const TextureLodOverride::OverrideInfo *a2,
        unsigned int *frameNumber,
        bool translateNumbers)
{
  GFxMovieDataDef::LoadTaskData::GetLabeledFrame(this: *(this + 8), label: a2, frameNumber, translateNumbers);
}

//------------------------------------------------------------------------------
// Address: 0x100D8230
// Name: public: bool GFxMovieDataDef::LoadTaskData::GetResourceHandle(class GFxResourceHandle __near *,class GFxResourceId)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxMovieDataDef::LoadTaskData::GetResourceHandle(
        CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *this,
        _DWORD *phandle,
        unsigned int rid)
{
  CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *v4; // ebx
  int v5; // eax
  CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *v6; // esi
  int Index; // eax
  TextureLodOverride::OverrideInfo *m_pMemory; // ecx
  TextureLodOverride::OverrideInfo *v9; // esi
  IShaderDevice *v10; // ecx
  IShaderDevice *v11; // ecx
  VertexShaderHandle_t__ *v13; // [esp+0h] [ebp-8h]

  v4 = nullptr;
  if ( *((int *)this + 32) < 2 )
  {
    v4 = this;
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 184));
  }
  v5 = *((_DWORD *)this + 52);
  v6 = (CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *)((char *)this + 208);
  if ( v5 == 0
    || (Index = GHashSetBase<GHashNode<GFxResourceId,GFxResourceHandle,GFxResourceId::HashOp>,GHashNode<GFxResourceId,GFxResourceHandle,GFxResourceId::HashOp>::NodeHashF,GHashNode<GFxResourceId,GFxResourceHandle,GFxResourceId::HashOp>::NodeAltHashF,GAllocatorLH<GFxResourceId,2>,GHashsetNodeEntry<GHashNode<GFxResourceId,GFxResourceHandle,GFxResourceId::HashOp>,GHashNode<GFxResourceId,GFxResourceHandle,GFxResourceId::HashOp>::NodeHashF>>::findIndexCore<GFxResourceId>(
                  a1: &rid,
                  a2: *(_DWORD *)(v5 + 4) & (rid ^ (rid >> 8)))) < 0 )
  {
    v6 = nullptr;
    Index = 0;
  }
  if ( v6 != nullptr
    && (m_pMemory = v6->m_Memory.m_pMemory, v6->m_Memory.m_pMemory != nullptr)
    && Index <= *(_DWORD *)&m_pMemory[2].x )
  {
    v9 = &m_pMemory[8 * Index + 8];
    if ( *(_DWORD *)&v9->x == 0 )
    {
      v10 = *(IShaderDevice **)&v9[2].x;
      if ( v10 != nullptr )
        GRefCountImpl::AddRef(this: v10, a2: v13);
    }
    if ( *phandle == 0 )
    {
      v11 = (IShaderDevice *)phandle[1];
      if ( v11 != nullptr )
        GFxResource::Release(this: v11);
    }
    *phandle = *(_DWORD *)&v9->x;
    phandle[1] = *(_DWORD *)&v9[2].x;
    if ( v4 != nullptr )
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&v4[9].m_Memory.m_nAllocationCount);
    return 1;
  }
  else
  {
    if ( v4 != nullptr )
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&v4[9].m_Memory.m_nAllocationCount);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8300
// Name: public: GFxMovieDefImpl::GFxMovieDefImpl(class GFxMovieDataDef __near *,class GFxMovieDefBindStates __near *,class GFxLoaderImpl __near *,unsigned int,class GFxStateBagImpl __near *,class GMemoryHeap __near *,bool,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxMovieDefImpl *__thiscall GFxMovieDefImpl::GFxMovieDefImpl(
        GFxMovieDefImpl *this,
        IShaderDevice *a2,
        IShaderDevice *a3,
        IShaderDevice *a4,
        unsigned int a5,
        struct GFxStateBagImpl *a6,
        ExprNode *a7,
        bool a8,
        unsigned int a9)
{
  ExprNode *v9; // ebx
  GFxMovieDefImpl::BindTaskData *v11; // edi
  IMatRenderContext *ShortFilename; // eax
  GMemoryHeap *v13; // eax
  void *v14; // edi
  int (__thiscall *kind)(ExprNode *, int, int *); // edx
  GFxMovieDefImpl::BindTaskData *v16; // eax
  IShaderAPI *v17; // ecx
  IShaderAPI *v18; // ecx
  IShaderAPI *v19; // ecx
  GFxStateBagImpl *v20; // eax
  GFxStateBagImpl *v21; // edi
  IShaderAPI *v22; // ecx
  VertexShaderHandle_t__ *v24; // [esp+0h] [ebp-38h]
  _DWORD v25[8]; // [esp+Ch] [ebp-2Ch] BYREF
  int v26; // [esp+2Ch] [ebp-Ch] BYREF
  int v27; // [esp+30h] [ebp-8h] BYREF
  int v28; // [esp+34h] [ebp-4h] BYREF

  v9 = a7;
  *(_DWORD *)this = &GFxResource::`vftable';
  *((_DWORD *)this + 1) = 1;
  v11 = nullptr;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = &GFxStateBag::`vftable';
  *(_DWORD *)this = &GFxMovieDefImpl::`vftable'{for `GFxResource'};
  *((_DWORD *)this + 3) = &GFxMovieDefImpl::`vftable'{for `GFxStateBag'};
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  if ( a7 == nullptr )
  {
    ShortFilename = G_GetShortFilename();
    GString::GString(
      this: (CUtlMemory<CImagePacker,int> *)&v28,
      pdata1: (int)"MovieDef  \"",
      pdata2: (int)ShortFilename);
    v25[2] = 4096;
    v25[3] = 4096;
    v25[7] = a9;
    v25[5] = 0;
    v25[0] = HIWORD(a5) & 0x1000;
    v25[1] = 16;
    v25[4] = -1;
    v25[6] = 2;
    v13 = GMemory::pGlobalHeap->CreateHeap(this: GMemory::pGlobalHeap, a2: (v28 & 0xFFFFFFFC) + 8, a3: v25);
    v14 = (void *)(v28 & 0xFFFFFFFC);
    v9 = (ExprNode *)v13;
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v28 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v14);
    v11 = nullptr;
  }
  kind = (int (__thiscall *)(ExprNode *, int, int *))v9->left[2].kind;
  v27 = 2;
  v16 = (GFxMovieDefImpl::BindTaskData *)kind(a1: v9, a2: 136, a3: &v27);
  if ( v16 != nullptr )
    v11 = GFxMovieDefImpl::BindTaskData::BindTaskData(
            this: v16,
            pheap: v9,
            pdefImpl: a2,
            a4: this,
            loadFlags: (const CMemberFunctor1<COcclusionQueryMgr *,void (__thiscall COcclusionQueryMgr::*)(OcclusionQueryObjectHandle_t__ *),OcclusionQueryObjectHandle_t__ *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)a5,
            fullyLoaded: a8);
  v17 = *((IShaderAPI **)this + 7);
  if ( v17 != nullptr )
    GRefCountImpl::Release(this: v17);
  *((_DWORD *)this + 7) = v11;
  if ( a7 == nullptr )
    GMemoryHeap::ReleaseOnFree();
  if ( a4 != nullptr )
    GRefCountImpl::AddRef(this: a4, a2: v24);
  v18 = *((IShaderAPI **)this + 5);
  if ( v18 != nullptr )
    GRefCountImpl::Release(this: v18);
  *((_DWORD *)this + 5) = a4;
  if ( a3 != nullptr )
    GRefCountImpl::AddRef(this: a3, a2: v24);
  v19 = *((IShaderAPI **)this + 6);
  if ( v19 != nullptr )
    GRefCountImpl::Release(this: v19);
  *((_DWORD *)this + 6) = a3;
  v26 = 2;
  v20 = (GFxStateBagImpl *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 52, a3: &v26);
  if ( v20 != nullptr )
    v21 = GFxStateBagImpl::GFxStateBagImpl(this: v20, a2: a6);
  else
    v21 = nullptr;
  v22 = *((IShaderAPI **)this + 4);
  if ( v22 != nullptr )
    GRefCountImpl::Release(this: v22);
  *((_DWORD *)this + 4) = v21;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D84C0
// Name: public: virtual GFxMovieBindProcess::~GFxMovieBindProcess(void)
// Source: json
//------------------------------------------------------------------------------
_IMAGE_THUNK_DATA64 __thiscall GFxMovieBindProcess::~GFxMovieBindProcess(void *this)
{
  int v2; // eax
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  IMatRenderContextInternal *v6; // edi
  CUtlVector<int,CUtlMemory<int,int> > *v7; // ecx
  IShaderAPI *v8; // ecx
  void *v9; // edi
  GRefCountNTSImpl *v10; // ecx
  IShaderAPI *v11; // ecx
  GRefCountNTSImpl *v12; // ecx
  VertexShaderHandle_t__ *v14; // [esp+0h] [ebp-10h]
  int v15; // [esp+4h] [ebp-Ch]
  FileSystemSeek_t v16; // [esp+8h] [ebp-8h]
  int v17; // [esp+Ch] [ebp-4h]

  v2 = *((_DWORD *)this + 8);
  *(_DWORD *)this = &GFxMovieBindProcess::`vftable';
  if ( v2 != 0 )
  {
    v3 = *(_DWORD *)(v2 + 120);
    v17 = v3;
    if ( v3 != 0 )
      GRefCountImpl::AddRef(this: (IShaderDevice *)v3, a2: v14);
  }
  else
  {
    v17 = 0;
    v3 = 0;
  }
  v4 = *((_DWORD *)this + 8);
  if ( v4 != 0 )
  {
    if ( *(_DWORD *)(v4 + 116) == 1 )
    {
      v5 = *((_DWORD *)this + 8);
      v6 = *(IMatRenderContextInternal **)(v5 + 120);
      GMutex::Lock(this: v6 + 2);
      v7 = (CUtlVector<int,CUtlMemory<int,int> > *)(*(_DWORD *)(v5 + 120) + 28);
      *(_DWORD *)(v5 + 116) = 3;
      GWaitCondition::NotifyAll(this: v7, a2: (int)v14);
      GMutex::Unlock(this: v6 + 2);
      v3 = v17;
    }
    v8 = *((IShaderAPI **)this + 8);
    if ( v8 != nullptr )
      GRefCountImpl::Release(this: v8);
    *((_DWORD *)this + 8) = 0;
  }
  v9 = *((void **)this + 12);
  if ( v9 != nullptr )
  {
    GHashSetBase<unsigned short,GFixedSizeHash<unsigned short>,GFixedSizeHash<unsigned short>,GAllocatorGH<unsigned short,2>,GHashsetCachedEntry<unsigned short,GFixedSizeHash<unsigned short>>>::Clear(
      this: *((CInternalFileSystemPassThru<IBaseFileSystem> **)this + 12),
      a2: v14,
      a3: v15,
      a4: v16);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v9);
  }
  v10 = *((GRefCountNTSImpl **)this + 7);
  if ( v10 != nullptr )
    GRefCountNTSImpl::Release(this: v10);
  *((_DWORD *)this + 7) = 0;
  if ( v3 != 0 )
  {
    GMutex::Lock(this: (IMatRenderContextInternal *)(v3 + 8));
    *(_BYTE *)(v3 + 32) = 1;
    GWaitCondition::NotifyAll(this: (CUtlVector<int,CUtlMemory<int,int> > *)(v3 + 28), a2: (int)v14);
    GMutex::Unlock(this: (IMatRenderContextInternal *)(v3 + 8));
    GRefCountImpl::Release(this: (IShaderAPI *)v3);
  }
  v11 = *((IShaderAPI **)this + 8);
  if ( v11 != nullptr )
    GRefCountImpl::Release(this: v11);
  v12 = *((GRefCountNTSImpl **)this + 7);
  if ( v12 != nullptr )
    GRefCountNTSImpl::Release(this: v12);
  return GFxLoaderTask::~GFxLoaderTask();
}

//------------------------------------------------------------------------------
// Address: 0x100D8A30
// Name: public: GFxMovieDataDef::DefBindingData::~DefBindingData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::DefBindingData::~DefBindingData(CBaseFile *this)
{
  _DWORD *m_FileHandle; // edi
  CBaseFile *v3; // ebx
  volatile LONG *v4; // edi
  char *v5; // eax
  _DWORD *v6; // ebx
  volatile LONG *v7; // edi
  CBaseFile *v8; // eax
  CBaseFile *v9; // eax
  IShaderAPI *v10; // ecx
  void **p_m_FileHandle; // [esp+8h] [ebp-8h]
  char *i; // [esp+Ch] [ebp-4h]

  m_FileHandle = this->m_FileHandle;
  InterlockedExchange(Target: (volatile LONG *)this, Value: 0);
  for ( ; m_FileHandle != nullptr; m_FileHandle = (_DWORD *)m_FileHandle[8] )
    ;
  while ( *((_DWORD *)this + 2) != 0 )
  {
    v3 = *((CBaseFile **)this + 2);
    *(this + 2) = v3[6];
    v4 = (volatile LONG *)((int)v3[3].m_FileHandle & 0xFFFFFFFC);
    p_m_FileHandle = &v3->m_FileHandle;
    if ( InterlockedExchangeAdd(Addend: v4 + 1, Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v4);
    v5 = (char *)v3[1].m_FileHandle;
    v6 = (char *)v3->m_FileHandle + 12 * (_DWORD)v5 - 12;
    if ( v5 != nullptr )
    {
      for ( i = v5; i != nullptr; --i )
      {
        v7 = (volatile LONG *)(*v6 & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd(Addend: v7 + 1, Value: -1) == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v7);
        v6 -= 3;
      }
    }
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *p_m_FileHandle);
  }
  while ( *((_DWORD *)this + 6) != 0 )
  {
    v8 = *((CBaseFile **)this + 6);
    *(this + 6) = v8[3];
    if ( v8->m_FileHandle != nullptr )
      (*(void (__thiscall **)(void *, void *))(*(_DWORD *)v8->m_FileHandle + 8))(
        a1: v8->m_FileHandle,
        a2: v8[1].m_FileHandle);
  }
  while ( *((_DWORD *)this + 4) != 0 )
  {
    v9 = *((CBaseFile **)this + 4);
    *(this + 4) = v9[3];
    v10 = (IShaderAPI *)v9[1].m_FileHandle;
    if ( v10 != nullptr )
      GRefCountImpl::Release(this: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8B80
// Name: public: struct GFxCharacterCreateInfo GFxMovieDefImpl::GetCharacterCreateInfo(class GFxResourceId)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDefImpl::GetCharacterCreateInfo(
        CMatQueuedIndexBuffer *this,
        _RATE_QUOTA_LIMIT *rid,
        const IndexDesc_t *rh)
{
  _RATE_QUOTA_LIMIT *v3; // edi
  CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *v5; // ecx
  IShaderDevice *ResourceAndBinding; // esi
  const IndexDesc_t *v7; // [esp-4h] [ebp-14h]
  _TRIVERTEX *rha; // [esp+8h] [ebp-8h] BYREF
  IShaderDevice *v9; // [esp+Ch] [ebp-4h]

  v3 = rid;
  v7 = rh;
  v5 = *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(*(_DWORD *)(this->m_nIndexFormat + 12) + 32);
  rha = nullptr;
  v9 = nullptr;
  rid->RateData = 0;
  v3[1].RateData = 0;
  if ( GFxMovieDataDef::LoadTaskData::GetResourceHandle(this: v5, phandle: &rha, rid: (unsigned int)v7) != 0 )
  {
    ResourceAndBinding = GFxResourceHandle::GetResourceAndBinding(
                           a1: &rha,
                           a2: (VertexShaderHandle_t__ *)(this->m_nIndexFormat + 24),
                           retstr: (_RATE_QUOTA_LIMIT *)(this->m_nIndexFormat + 24),
                           a4: &rid);
    if ( ResourceAndBinding != nullptr
      && (ResourceAndBinding->GetBackBufferFormat(this: ResourceAndBinding) & 0x8000) != 0 )
    {
      v3[1].RateData = rid[10].RateData;
      v3->RateData = (unsigned int)ResourceAndBinding;
    }
  }
  if ( rha == nullptr && v9 != nullptr )
    GFxResource::Release(this: v9);
}

//------------------------------------------------------------------------------
// Address: 0x100D8CA0
// Name: public: virtual GFxMovieDataDef::LoadTaskData::~LoadTaskData(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100D8EA0
// Name: public: void GFxMovieDefImpl::BindTaskData::ResolveImport(class GFxImportData __near *,class GFxMovieDefImpl __near *,class GFxLoadStates __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDefImpl::BindTaskData::ResolveImport(
        GFxMovieDefImpl::BindTaskData *this,
        CUtlMemory<CImagePacker,int> *a2,
        IShaderDevice *a3,
        struct GFxLoadStates *a4,
        bool a5)
{
  _DWORD *v6; // esi
  GFxLogBase<GFxLog> *v7; // eax
  CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *v8; // ecx
  IMatRenderContextInternal *m_pHardwareContext; // esi
  char v10; // al
  _RTL_CRITICAL_SECTION *v11; // ebx
  _DWORD *v12; // esi
  IShaderDevice **v13; // esi
  IShaderDevice *v14; // ecx
  int v15; // eax
  IShaderDevice **v16; // esi
  MaterialIndexFormat_t m_nIndexFormat; // esi
  _DWORD *v18; // ebx
  _DWORD *v19; // edi
  int v20; // esi
  int v21; // eax
  const char *v22; // eax
  unsigned int v23; // eax
  int p_IsUsingGraphics; // ecx
  int v25; // esi
  void *v26; // esi
  unsigned int v27; // [esp-4h] [ebp-38h]
  const char *v28; // [esp-4h] [ebp-38h]
  VertexShaderHandle_t__ *v29; // [esp+0h] [ebp-34h]
  CMatQueuedIndexBuffer result; // [esp+Ch] [ebp-28h] BYREF
  struct GFxImportData *v31; // [esp+3Ch] [ebp+8h]
  struct GFxImportData *v32; // [esp+3Ch] [ebp+8h]
  struct GFxLoadStates *v33; // [esp+44h] [ebp+10h]
  char v34; // [esp+4Bh] [ebp+17h]

  result.m_nRTStartIndex = (int)this;
  HIBYTE(result.m_pRTDynamicIndexBuffer) = 0;
  result.m_nIndexFormat = MATERIAL_INDEX_FORMAT_16BIT;
  if ( a2->m_nAllocationCount == 0 )
    goto LABEL_30;
  v31 = nullptr;
  do
  {
    v6 = (_DWORD *)((char *)v31 + (unsigned int)a2->m_pMemory);
    result.__vftable = nullptr;
    result.m_pOwner = nullptr;
    if ( GFxMovieDefImpl::GetExportedResource(this: a3, &result, a3: (unsigned int)v6, ignoreDef: 0) != 0 )
    {
      v27 = v6[1];
      v8 = *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(*(_DWORD *)(result.m_nRTStartIndex + 12) + 32);
      result.m_pCallQueue = nullptr;
      result.m_pHardwareContext = nullptr;
      if ( GFxMovieDataDef::LoadTaskData::GetResourceHandle(this: v8, phandle: &result.m_pCallQueue, rid: v27) != 0 )
      {
        m_pHardwareContext = result.m_pHardwareContext;
        GFxResourceBinding::SetBindData(
          this: (GFxResourceBinding *)(result.m_nRTStartIndex + 24),
          a2: (unsigned int)result.m_pHardwareContext,
          a3: (const struct GFxResourceBindData *)&result);
        if ( result.m_pCallQueue == nullptr && m_pHardwareContext != nullptr )
          GFxResource::Release(this: (IShaderDevice *)m_pHardwareContext);
        v10 = 1;
      }
      else
      {
        if ( result.m_pCallQueue == nullptr && result.m_pHardwareContext != nullptr )
          GFxResource::Release(this: (IShaderDevice *)result.m_pHardwareContext);
        v10 = 0;
      }
      HIBYTE(result.m_pRTDynamicIndexBuffer) = v10;
    }
    else
    {
      v7 = *((GFxLogBase<GFxLog> **)a4 + 3);
      if ( v7 != nullptr )
        GFxLogBase<GFxLog>::LogError(
          this: v7 + 3,
          pfmt: "Import error: GFxResource '%s' is not exported from movie '%s'\n",
          (const char *)((*v6 & 0xFFFFFFFC) + 8),
          (const char *)(((int)a2[1].m_pMemory & 0xFFFFFFFC) + 8));
    }
    if ( result.__vftable != nullptr )
      GFxResource::Release(this: (IShaderDevice *)result.__vftable);
    v31 = (struct GFxImportData *)((char *)v31 + 12);
    ++result.m_nIndexFormat;
  }
  while ( result.m_nIndexFormat < (unsigned int)a2->m_nAllocationCount );
  if ( HIBYTE(result.m_pRTDynamicIndexBuffer) != 0 )
  {
    if ( a5 )
      return;
    v11 = (_RTL_CRITICAL_SECTION *)(result.m_nRTStartIndex + 80);
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(result.m_nRTStartIndex + 80));
    if ( a3 != nullptr )
      GRefCountImpl::AddRef(this: a3, a2: v29);
    v12 = (_DWORD *)(result.m_nRTStartIndex + 68);
    GArrayDataBase<GPtr<GFxMovieDefImpl>,GAllocatorLH<GPtr<GFxMovieDefImpl>,265>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: (GFxLoader::LoaderConfig *)(result.m_nRTStartIndex + 68),
      a2: (VertexShaderHandle_t__ *)v11,
      pheapAddr: (const GFxLoader::LoaderConfig *)(result.m_nRTStartIndex + 68),
      newSize: *(_DWORD *)(result.m_nRTStartIndex + 72) + 1);
    v13 = (IShaderDevice **)(*v12 + 4 * v12[1] - 4);
    v14 = a3;
    if ( v13 != nullptr )
    {
      if ( a3 != nullptr )
      {
        GRefCountImpl::AddRef(this: a3, a2: v29);
        v14 = a3;
      }
      *v13 = v14;
    }
    if ( v14 != nullptr )
      GFxResource::Release(this: v14);
    LeaveCriticalSection(lpCriticalSection: v11);
  }
  else
  {
LABEL_30:
    if ( a5 )
      return;
  }
  v34 = 0;
  GString::ToLower(this: a2 + 1);
  strstr(str1: (unsigned __int8 *)((*(_DWORD *)&result.m_bExternalIB & 0xFFFFFFFC) + 8), str2: "_glyphs");
  if ( v15 != 0 )
  {
    v34 = 1;
    if ( a3 != nullptr )
      GRefCountImpl::AddRef(this: a3, a2: v29);
    GArrayDataBase<GPtr<GFxMovieDefImpl>,GAllocatorGH<GPtr<GFxMovieDefImpl>,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: (CVertexBuilder *)((char *)a4 + 72),
      a2: nullptr,
      a3: (int)a4 + 72,
      a4: *((_DWORD *)a4 + 19) + 1);
    v16 = (IShaderDevice **)(*((_DWORD *)a4 + 18) + 4 * *((_DWORD *)a4 + 19) - 4);
    if ( *((_DWORD *)a4 + 18) + 4 * *((_DWORD *)a4 + 19) != 4 )
    {
      if ( a3 != nullptr )
        GRefCountImpl::AddRef(this: a3, a2: v29);
      *v16 = a3;
    }
    if ( a3 != nullptr )
      GFxResource::Release(this: a3);
  }
  m_nIndexFormat = *(_DWORD *)(*((_DWORD *)a3[7].GetBackBufferDimensions + 8) + 164);
  v32 = *(struct GFxImportData **)(*(_DWORD *)(*(_DWORD *)(result.m_nRTStartIndex + 12) + 32) + 164);
  result.m_nIndexFormat = m_nIndexFormat;
  if ( v32 != nullptr )
  {
    while ( 1 )
    {
      v18 = *((_DWORD **)v32 + 1);
      if ( (*(int (__thiscall **)(_DWORD *))(*v18 + 56))(a1: v18) == 0 || v34 != 0 )
      {
        v33 = (struct GFxLoadStates *)m_nIndexFormat;
        if ( m_nIndexFormat != MATERIAL_INDEX_FORMAT_16BIT )
        {
          while ( 1 )
          {
            v19 = *((_DWORD **)v33 + 1);
            if ( (*(int (__thiscall **)(_DWORD *))(*v19 + 56))(a1: v19) != 0 )
            {
              v20 = v19[5] & 0x303;
              v21 = (*(int (__thiscall **)(_DWORD *))(*v19 + 60))(a1: v19);
              if ( (v18[5] & (v20 & 0x10 | ((v20 & 0x300) != 0 ? 0x300 : 0) | 3)) == (v20 & 0x313) )
              {
                v28 = (const char *)v21;
                v22 = (const char *)(*(int (__thiscall **)(_DWORD *))(*v18 + 60))(a1: v18);
                if ( GString::CompareNoCase(a1: v22, a2: v28) == 0 )
                  break;
              }
            }
            v33 = *((struct GFxLoadStates **)v33 + 3);
            if ( v33 == nullptr )
              goto LABEL_61;
          }
          v23 = *((_DWORD *)v33 + 2);
          p_IsUsingGraphics = (int)&a3[7].IsUsingGraphics;
          result.m_pIndexData = nullptr;
          result.m_nIndices = 0;
          if ( *(_BYTE *)(p_IsUsingGraphics + 36) != 0 && v23 < *(_DWORD *)(p_IsUsingGraphics + 4) )
          {
            v25 = *(_DWORD *)(p_IsUsingGraphics + 8) + 8 * v23;
            if ( *(_DWORD *)v25 != 0 )
            {
              GRefCountImpl::AddRef(this: *(IShaderDevice **)v25, a2: v29);
              if ( result.m_pIndexData != nullptr )
                GFxResource::Release(this: (IShaderDevice *)result.m_pIndexData);
            }
            result.m_pIndexData = *(void **)v25;
            result.m_nIndices = *(_DWORD *)(v25 + 4);
          }
          else
          {
            GFxResourceBinding::GetResourceData_Locked(
              this: (GFxResourceBinding *)p_IsUsingGraphics,
              a2: (struct GFxResourceBindData *)&result.m_pIndexData,
              a3: v23);
          }
          if ( result.m_pIndexData != nullptr )
          {
            GFxResourceBinding::SetBindData(
              this: (GFxResourceBinding *)(result.m_nRTStartIndex + 24),
              a2: *((_DWORD *)v32 + 2),
              a3: (const struct GFxResourceBindData *)&result.m_pIndexData);
            if ( result.m_pIndexData != nullptr )
              GFxResource::Release(this: (IShaderDevice *)result.m_pIndexData);
          }
        }
      }
LABEL_61:
      v32 = *((struct GFxImportData **)v32 + 3);
      if ( v32 == nullptr )
        break;
      m_nIndexFormat = result.m_nIndexFormat;
    }
  }
  v26 = (void *)(*(_DWORD *)&result.m_bExternalIB & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((*(_DWORD *)&result.m_bExternalIB & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v26);
}

//------------------------------------------------------------------------------
// Address: 0x100D9220
// Name: public: bool GFxMovieDefImpl::BindTaskData::ResolveImportThroughFontLib(class GFxImportData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDefImpl::BindTaskData::ResolveImportThroughFontLib(
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,LightDesc_t const *),int,LightDesc_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        _DWORD *a2)
{
  IShaderDevice *v2; // edi
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,LightDesc_t const *),int,LightDesc_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v3; // ebx
  _DWORD *v4; // esi
  _RATE_QUOTA_LIMIT *v5; // ebx
  GFxFontData *v6; // eax
  GFxFontResource *v7; // eax
  _ENUM_SERVICE_STATUSA *v8; // ebx
  unsigned int v9; // esi
  IShaderDevice *v10; // esi
  IShaderDevice *v11; // ecx
  _ENUM_SERVICE_STATUSA *bindData; // [esp+Ch] [ebp-20h] BYREF
  _RATE_QUOTA_LIMIT *v13; // [esp+10h] [ebp-1Ch]
  int phandle; // [esp+14h] [ebp-18h] BYREF
  IShaderDevice *v15; // [esp+18h] [ebp-14h]
  int v16; // [esp+1Ch] [ebp-10h] BYREF
  unsigned int i; // [esp+20h] [ebp-Ch]
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,LightDesc_t const *),int,LightDesc_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v18; // [esp+24h] [ebp-8h]
  int v19; // [esp+28h] [ebp-4h]

  v2 = nullptr;
  v3 = this;
  v18 = this;
  i = 0;
  if ( a2[1] != 0 )
  {
    v19 = 0;
    while ( 1 )
    {
      v4 = (_DWORD *)(v19 + *a2);
      v5 = (_RATE_QUOTA_LIMIT *)&v3->m_Proxy.m_pfnProxied + 2;
      bindData = nullptr;
      v13 = v5;
      v16 = 261;
      v6 = (GFxFontData *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 64, a3: &v16);
      if ( v6 != nullptr )
        v2 = (IShaderDevice *)GFxFontData::GFxFontData(this: v6, _Src: (char *)((*v4 & 0xFFFFFFFC) + 8), a3: 0);
      v2[5].__vftable = (IShaderDevice_vtbl *)((int)v2[5].__vftable | 0x40);
      v16 = 2;
      v7 = (GFxFontResource *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 44, a3: &v16);
      if ( v7 != nullptr )
        v8 = (_ENUM_SERVICE_STATUSA *)GFxFontResource::GFxFontResource(this: v7, a2: v2, pbinding: v5);
      else
        v8 = nullptr;
      if ( bindData != nullptr )
        GFxResource::Release(this: (IShaderDevice *)bindData);
      bindData = v8;
      v9 = v4[1];
      v3 = v18;
      phandle = 0;
      v15 = nullptr;
      if ( GFxMovieDataDef::LoadTaskData::GetResourceHandle(
             this: *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(v18->m_iRefs + 32),
             &phandle,
             rid: v9) != 0 )
      {
        v10 = v15;
        GFxResourceBinding::SetBindData(
          this: (GFxResourceBinding *)((char *)&v3->m_Proxy.m_pfnProxied + 8),
          a2: (unsigned int)v15,
          a3: (const struct GFxResourceBindData *)&bindData);
        if ( phandle == 0 && v10 != nullptr )
        {
          v11 = v10;
LABEL_17:
          GFxResource::Release(this: v11);
        }
      }
      else if ( phandle == 0 )
      {
        v11 = v15;
        if ( v15 != nullptr )
          goto LABEL_17;
      }
      GRefCountImpl::Release(this: (IShaderAPI *)v2);
      if ( bindData != nullptr )
        GFxResource::Release(this: (IShaderDevice *)bindData);
      v19 += 12;
      if ( ++i >= a2[1] )
        break;
      v2 = nullptr;
    }
  }
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&v3[1].m_Proxy.m_pObject);
  GArrayDataBase<GPtr<GFxMovieDefImpl>,GAllocatorLH<GPtr<GFxMovieDefImpl>,265>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: (GFxLoader::LoaderConfig *)((char *)&v3[1].m_Proxy.m_pfnProxied + 4),
    a2: (VertexShaderHandle_t__ *)v3,
    pheapAddr: (const GFxLoader::LoaderConfig *)((char *)&v3[1].m_Proxy.m_pfnProxied + 4),
    newSize: DWORD2(v3[1].m_Proxy.m_pfnProxied) + 1);
  if ( DWORD1(v3[1].m_Proxy.m_pfnProxied) + 4 * DWORD2(v3[1].m_Proxy.m_pfnProxied) != 4 )
    *(_DWORD *)(DWORD1(v3[1].m_Proxy.m_pfnProxied) + 4 * DWORD2(v3[1].m_Proxy.m_pfnProxied) - 4) = 0;
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&v3[1].m_Proxy.m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100D9390
// Name: public: virtual class GFxFontResource __near * GFxMovieDefImpl::GetFontResource(char const __near *,unsigned int,struct GFxMovieDefImpl::SearchInfo __near *)
// Source: json
//------------------------------------------------------------------------------
IShaderDevice *__thiscall GFxMovieDefImpl::GetFontResource(
        GFxMovieDefImpl *this,
        char *a2,
        __int16 a3,
        struct GFxMovieDefImpl::SearchInfo *a4)
{
  int v4; // edx
  _DWORD *v5; // edi
  int v6; // ebx
  _DWORD *v7; // ecx
  const char *v8; // eax
  int v9; // ecx
  unsigned int v10; // eax
  int v11; // ebx
  IShaderDevice *v12; // eax
  const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v13; // edx
  _DWORD *v14; // ebx
  _DWORD *v15; // esi
  IShaderDevice *v17; // edi
  IShaderDevice_vtbl *v18; // ecx
  bool v19; // zf
  int v20; // esi
  unsigned int v21; // eax
  int v22; // ebx
  int Index; // eax
  int v24; // esi
  int v25; // ecx
  char v26; // dl
  int v27; // edi
  IShaderDevice *v28; // ecx
  const char *v29; // eax
  int v30; // ecx
  _DWORD *v31; // ebx
  int v32; // [esp-4h] [ebp-3Ch]
  VertexShaderHandle_t__ *v33; // [esp+0h] [ebp-38h]
  IShaderDevice *v34; // [esp+Ch] [ebp-2Ch] BYREF
  int v35; // [esp+10h] [ebp-28h]
  int phandle; // [esp+14h] [ebp-24h] BYREF
  IShaderDevice *v37; // [esp+18h] [ebp-20h]
  IShaderDevice *v38; // [esp+1Ch] [ebp-1Ch] BYREF
  const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v39; // [esp+20h] [ebp-18h]
  int v40; // [esp+24h] [ebp-14h]
  int v41; // [esp+28h] [ebp-10h]
  int v42; // [esp+2Ch] [ebp-Ch]
  GFxMovieDefImpl *v43; // [esp+30h] [ebp-8h]
  _DWORD *v44; // [esp+34h] [ebp-4h]

  v4 = *(_DWORD *)(*((_DWORD *)this + 7) + 12);
  v5 = *(_DWORD **)(*(_DWORD *)(v4 + 32) + 164);
  v43 = this;
  v41 = v4;
  if ( v5 != nullptr )
  {
    v6 = a3 & 0x313;
    v40 = v6;
    do
    {
      v7 = (_DWORD *)v5[1];
      if ( ((a3 & 0x10 | ((a3 & 0x300) != 0 ? 0x300 : 0) | 3) & v7[5]) == v6 )
      {
        v8 = (const char *)(*(int (__thiscall **)(_DWORD *))(*v7 + 60))(a1: v7);
        if ( GString::CompareNoCase(a1: v8, a2) == 0 )
        {
          v9 = *((_DWORD *)v43 + 7) + 24;
          v38 = nullptr;
          v39 = nullptr;
          v10 = v5[2];
          if ( *(_BYTE *)(v9 + 36) != 0 && v10 < *(_DWORD *)(v9 + 4) )
          {
            v11 = *(_DWORD *)(v9 + 8) + 8 * v10;
            if ( *(_DWORD *)v11 != 0 )
            {
              GRefCountImpl::AddRef(this: *(IShaderDevice **)v11, a2: v33);
              if ( v38 != nullptr )
                GFxResource::Release(this: v38);
            }
            v12 = *(IShaderDevice **)v11;
            v38 = *(IShaderDevice **)v11;
            v13 = *(const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > **)(v11 + 4);
            v6 = v40;
            v39 = v13;
          }
          else
          {
            GFxResourceBinding::GetResourceData_Locked(
              this: (GFxResourceBinding *)v9,
              a2: (struct GFxResourceBindData *)&v38,
              a3: v5[2]);
            v12 = v38;
          }
          if ( v12 != nullptr )
          {
            v17 = v12;
            if ( a4 != nullptr )
            {
              v18 = v12[3].__vftable;
              if ( ((int)v18->GetCurrentAdapter & 0x40) != 0 )
              {
                *(_DWORD *)a4 = 2;
              }
              else if ( (a3 & 3) != 0
                     && (v19 = (*((unsigned __int8 (__thiscall **)(IShaderDevice_vtbl *))v18->ReleaseResources + 16))(a1: v18) == 0,
                         v12 = v38,
                         v19) )
              {
                *(_DWORD *)a4 = 3;
              }
              else
              {
                *(_DWORD *)a4 = 1;
              }
            }
            if ( v12 != nullptr )
              GFxResource::Release(this: v12);
            return v17;
          }
        }
      }
      v5 = (_DWORD *)v5[3];
    }
    while ( v5 != nullptr );
    this = v43;
    v4 = v41;
  }
  v14 = *(_DWORD **)(*(_DWORD *)(v4 + 32) + 156);
  v44 = v14;
  if ( v14 != nullptr )
  {
    while ( 1 )
    {
      v40 = 0;
      if ( v14[1] != 0 )
        break;
LABEL_63:
      v44 = (_DWORD *)v14[6];
      if ( v44 == nullptr )
      {
        this = v43;
        goto LABEL_16;
      }
      v14 = v44;
    }
    v42 = 0;
    while ( a4 == nullptr )
    {
LABEL_42:
      v24 = v42;
      v32 = *v14;
      phandle = 0;
      v37 = nullptr;
      if ( GFxMovieDataDef::LoadTaskData::GetResourceHandle(
             this: *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(v41 + 32),
             &phandle,
             rid: *(_DWORD *)(v32 + v42 + 4)) != 0 )
      {
        v25 = *((_DWORD *)v43 + 7) + 24;
        if ( phandle != 0 )
        {
          v26 = *(_BYTE *)(*((_DWORD *)v43 + 7) + 60);
          v34 = nullptr;
          v35 = 0;
          if ( v26 != 0 && (unsigned int)v37 < *(_DWORD *)(v25 + 4) )
          {
            v27 = *(_DWORD *)(v25 + 8) + 8 * (_DWORD)v37;
            if ( *(_DWORD *)v27 != 0 )
            {
              GRefCountImpl::AddRef(this: *(IShaderDevice **)v27, a2: v33);
              if ( v34 != nullptr )
                GFxResource::Release(this: v34);
            }
            v28 = *(IShaderDevice **)v27;
            v34 = *(IShaderDevice **)v27;
            v35 = *(_DWORD *)(v27 + 4);
          }
          else
          {
            GFxResourceBinding::GetResourceData_Locked(
              this: (GFxResourceBinding *)v25,
              a2: (struct GFxResourceBindData *)&v34,
              a3: (unsigned int)v37);
            v28 = v34;
          }
          v17 = v28;
          if ( v28 != nullptr )
            GFxResource::Release(this: v28);
        }
        else
        {
          v17 = v37;
        }
        if ( v17 != nullptr
          && (v17->GetBackBufferFormat(this: v17) & 0xFF00) == 0x200
          && ((int)v17[3].GetCurrentAdapter & (a3 & 0x10 | ((a3 & 0x300) != 0 ? 0x300 : 0) | 3)) == (a3 & 0x313) )
        {
          if ( GString::CompareNoCase(a1: (const char *)((*(_DWORD *)(v24 + *v14) & 0xFFFFFFFC) + 8), a2) == 0
            || (v29 = (const char *)(*((int (__thiscall **)(IShaderDevice_vtbl *))v17[3].ReleaseResources + 15))(a1: v17[3].__vftable),
                GString::CompareNoCase(a1: v29, a2) == 0) )
          {
            if ( a4 != nullptr )
            {
              v30 = v14[3];
              v31 = v14 + 3;
              if ( (*(_DWORD *)(v30 & 0xFFFFFFFC) & 0x7FFFFFFFu) < 0xE
                || GString::CompareNoCase(
                     a1: (const char *)((*v31 & 0xFFFFFFFC) + (*(_DWORD *)(*v31 & 0xFFFFFFFC) & 0x7FFFFFFF) - 6),
                     a2: "gfxfontlib.swf") != 0 )
              {
                *(_DWORD *)a4 = 4;
              }
              else
              {
                *(_DWORD *)a4 = 5;
              }
              GString::operator=(
                this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)a4 + 8),
                src: (int)v31,
                a3: (int)v33);
            }
            if ( phandle == 0 && v37 != nullptr )
            {
              GFxResource::Release(this: v37);
              return v17;
            }
            return v17;
          }
        }
      }
      if ( phandle == 0 && v37 != nullptr )
        GFxResource::Release(this: v37);
      v42 += 12;
      if ( (unsigned int)++v40 >= v14[1] )
        goto LABEL_63;
    }
    v20 = (int)(v14 + 3);
    v21 = (unsigned int)GString::BernsteinHashFunctionCIS(result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((v14[3] & 0xFFFFFFFC) + 8));
    v22 = *((_DWORD *)a4 + 1);
    v39 = (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v21;
    if ( v22 != 0 )
    {
      Index = GHashSetBase<GString,GString::NoCaseHashFunctor,GString::NoCaseHashFunctor,GAllocatorGH<GString,2>,GHashsetCachedEntry<GString,GString::NoCaseHashFunctor>>::findIndexCore<GStringLH>(
                a1: v20,
                a2: v21 & *(_DWORD *)(v22 + 4));
      if ( Index >= 0 )
      {
        GString::operator=(
          this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(v22 + 12 * Index + 16),
          src: v20,
          a3: (int)v33);
LABEL_41:
        v14 = v44;
        goto LABEL_42;
      }
      v21 = (unsigned int)v39;
    }
    GHashSetBase<GString,GString::NoCaseHashFunctor,GString::NoCaseHashFunctor,GAllocatorGH<GString,2>,GHashsetCachedEntry<GString,GString::NoCaseHashFunctor>>::add<GStringLH>(
      a1: (char *)a4 + 4,
      a2: (char *)a4 + 4,
      a3: v20,
      a4: v21);
    goto LABEL_41;
  }
LABEL_16:
  v15 = (_DWORD *)(*(int (__thiscall **)(GFxMovieDefImpl *, char *))(*(_DWORD *)this + 108))(a1: this, a2);
  if ( v15 != nullptr
    && ((*(int (__thiscall **)(_DWORD *))(*v15 + 8))(a1: v15) & 0xFF00) == 0x200
    && (*(_DWORD *)(v15[3] + 20) & (a3 & 0x10 | ((a3 & 0x300) != 0 ? 0x300 : 0) | 3)) == (a3 & 0x313) )
  {
    if ( a4 != nullptr )
      *(_DWORD *)a4 = 6;
    return (IShaderDevice *)v15;
  }
  else
  {
    if ( a4 != nullptr )
      *(_DWORD *)a4 = 0;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D97D0
// Name: public: class GFxCharPosInfo __near & GFxCharPosInfo::operator=(class GFxCharPosInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
CMatQueuedMesh *__thiscall GFxCharPosInfo::operator=(CMatQueuedMesh *this, IStream *__that)
{
  _ULARGE_INTEGER v4; // [esp+0h] [ebp-Ch]

  GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::operator=(
    a1: this,
    this: __that,
    a: v4);
  qmemcpy(&this->m_pMSTActualMesh, &__that[3], 0x48u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D9880
// Name: public: void GFxMovieDataDef::LoadTaskData::AddResource(class GFxResourceId,class GFxResource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::LoadTaskData::AddResource(
        CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *this,
        unsigned int rid,
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pres)
{
  CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *v4; // edi
  VertexShaderHandle_t__ *v5; // [esp+0h] [ebp-18h]
  int v6[2]; // [esp+8h] [ebp-10h] BYREF
  int v7; // [esp+10h] [ebp-8h] BYREF
  IShaderDevice *v8; // [esp+14h] [ebp-4h]

  v4 = nullptr;
  if ( *((int *)this + 32) < 2 )
  {
    v4 = this;
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 184));
  }
  v7 = 0;
  v8 = (IShaderDevice *)pres;
  if ( pres != nullptr )
    GRefCountImpl::AddRef(this: (IShaderDevice *)pres, a2: v5);
  v6[1] = (int)&v7;
  v6[0] = (int)&rid;
  GHashSetBase<GHashNode<GFxResourceId,GFxResourceHandle,GFxResourceId::HashOp>,GHashNode<GFxResourceId,GFxResourceHandle,GFxResourceId::HashOp>::NodeHashF,GHashNode<GFxResourceId,GFxResourceHandle,GFxResourceId::HashOp>::NodeAltHashF,GAllocatorLH<GFxResourceId,2>,GHashsetNodeEntry<GHashNode<GFxResourceId,GFxResourceHandle,GFxResourceId::HashOp>,GHashNode<GFxResourceId,GFxResourceHandle,GFxResourceId::HashOp>::NodeHashF>>::add<GHashNode<GFxResourceId,GFxResourceHandle,GFxResourceId::HashOp>::NodeRef>(
    this: (GArrayBase<GArrayData<GFxTextKeyMap::KeyMapEntry,GAllocatorGH<GFxTextKeyMap::KeyMapEntry,2>,GArrayDefaultPolicy> > *)((char *)this + 208),
    pheapAddr: (GArrayBase<GArrayData<GFxTextKeyMap::KeyMapEntry,GAllocatorGH<GFxTextKeyMap::KeyMapEntry,2>,GArrayDefaultPolicy> > *)((char *)this + 208),
    a3: (int)v6,
    a4: rid ^ (rid >> 8));
  if ( v7 == 0 && v8 != nullptr )
    GFxResource::Release(this: v8);
  if ( v4 != nullptr )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&v4[9].m_Memory.m_nAllocationCount);
}

//------------------------------------------------------------------------------
// Address: 0x100D9910
// Name: public: class GFxResourceHandle GFxMovieDataDef::LoadTaskData::AddNewResourceHandle(class GFxResourceId)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GFxMovieDataDef::LoadTaskData::AddNewResourceHandle(int this, _DWORD *a2, unsigned int a3)
{
  int v4; // eax
  int v5; // ebx
  int v7[2]; // [esp+Ch] [ebp-8h] BYREF

  v4 = *(_DWORD *)(this + 180);
  *a2 = 1;
  a2[1] = v4;
  ++*(_DWORD *)(this + 180);
  v5 = 0;
  if ( *(int *)(this + 128) < 2 )
  {
    v5 = this;
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 184));
  }
  v7[0] = (int)&a3;
  v7[1] = (int)a2;
  GHashSetBase<GHashNode<GFxResourceId,GFxResourceHandle,GFxResourceId::HashOp>,GHashNode<GFxResourceId,GFxResourceHandle,GFxResourceId::HashOp>::NodeHashF,GHashNode<GFxResourceId,GFxResourceHandle,GFxResourceId::HashOp>::NodeAltHashF,GAllocatorLH<GFxResourceId,2>,GHashsetNodeEntry<GHashNode<GFxResourceId,GFxResourceHandle,GFxResourceId::HashOp>,GHashNode<GFxResourceId,GFxResourceHandle,GFxResourceId::HashOp>::NodeHashF>>::add<GHashNode<GFxResourceId,GFxResourceHandle,GFxResourceId::HashOp>::NodeRef>(
    this: (GArrayBase<GArrayData<GFxTextKeyMap::KeyMapEntry,GAllocatorGH<GFxTextKeyMap::KeyMapEntry,2>,GArrayDefaultPolicy> > *)(this + 208),
    pheapAddr: (GArrayBase<GArrayData<GFxTextKeyMap::KeyMapEntry,GAllocatorGH<GFxTextKeyMap::KeyMapEntry,2>,GArrayDefaultPolicy> > *)(this + 208),
    a3: (int)v7,
    a4: a3 ^ (a3 >> 8));
  if ( v5 != 0 )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v5 + 184));
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100D9990
// Name: public: enum GFxMovieDefImpl::BindStateType GFxMovieBindProcess::BindNextFrame(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall GFxMovieBindProcess::BindNextFrame@<eax>(
        int a1@<ecx>,
        struct GFxLoaderImpl::LoadStackItem *a2@<ebx>,
        unsigned int a3@<edi>)
{
  int v4; // eax
  int result; // eax
  int v6; // eax
  _DWORD *v7; // edi
  int v8; // ebx
  int v9; // eax
  int v10; // eax
  CP4AutoAddFile *v11; // eax
  int v12; // ecx
  bool v13; // zf
  struct GMemoryHeap *v14; // edx
  struct GMemoryHeap *pAutoRelease; // edi
  unsigned int v16; // ecx
  struct GFxMovieDefImpl *v17; // eax
  IShaderDevice *v18; // ebx
  IShaderAPI *v19; // edi
  int v20; // edx
  GFxImageLoader *v21; // eax
  int v22; // eax
  unsigned int v23; // ebx
  unsigned int v24; // ecx
  unsigned int *p_SelfSize; // edi
  struct GFxMovieDefImpl *Movie_LoadState; // edi
  _DWORD *v27; // eax
  _DWORD *v28; // ecx
  CP4AutoAddFile *v29; // ebx
  CP4File *m_p; // eax
  IShaderDevice *v31; // ebx
  int v32; // eax
  int *v33; // ebx
  GFxImageLoader *v34; // edx
  struct GMemoryHeap *v35; // eax
  int v36; // ecx
  int v37; // edx
  IShaderDevice *MovieDefImplAddRef; // edi
  int v39; // ecx
  _DWORD *v40; // edx
  char v41; // bl
  volatile unsigned int v42; // eax
  __int32 v43; // ebx
  int v44; // ecx
  int v45; // edi
  unsigned int v46; // ebx
  CUtlVector<int,CUtlMemory<int,int> > *v47; // ecx
  int v48; // edx
  int v49; // ebx
  IShaderAPI *v50; // ecx
  unsigned int v51; // ebx
  IMatRenderContextInternal **v52; // ebx
  _DWORD *v53; // ecx
  bool v54; // dl
  int v55; // ebx
  IMatRenderContextInternal *v56; // edi
  int v57; // edi
  int v58; // eax
  int v59; // edi
  _RTL_CRITICAL_SECTION *v60; // ebx
  IShaderDevice *v61; // ecx
  IShaderDevice *v62; // edi
  int v63; // ecx
  int v64; // edi
  unsigned int v65; // ebx
  CUtlVector<int,CUtlMemory<int,int> > *v66; // ecx
  _DWORD *v67; // edi
  int *v68; // ecx
  int v69; // ebx
  int v70; // eax
  int v71; // eax
  int v72; // edi
  void (__thiscall *v73)(unsigned int, _DWORD *); // edx
  void *v74; // edi
  int v75; // ecx
  int v76; // edi
  unsigned int v77; // ebx
  CUtlVector<int,CUtlMemory<int,int> > *v78; // ecx
  int v79; // eax
  int v80; // edi
  IShaderAPI *v81; // ecx
  CUtlMemory<CImagePacker,int> v82; // [esp-1Ch] [ebp-98h]
  CUtlMemory<CImagePacker,int> v83; // [esp-1Ch] [ebp-98h]
  struct GFxLoaderImpl::LoadStackItem *v84; // [esp-8h] [ebp-84h]
  const CFunctorData0 *v85; // [esp-8h] [ebp-84h]
  const CFunctorData0 *v86; // [esp-8h] [ebp-84h]
  unsigned int v87; // [esp-4h] [ebp-80h]
  _DWORD v88[5]; // [esp+4h] [ebp-78h] BYREF
  int v89; // [esp+18h] [ebp-64h] BYREF
  GFxURLBuilder::LocationInfo v90; // [esp+24h] [ebp-58h] BYREF
  int v91; // [esp+30h] [ebp-4Ch] BYREF
  unsigned int v92; // [esp+34h] [ebp-48h]
  unsigned int v93; // [esp+38h] [ebp-44h]
  _DWORD v94[2]; // [esp+3Ch] [ebp-40h] BYREF
  _DWORD v95[2]; // [esp+44h] [ebp-38h] BYREF
  _ENUM_SERVICE_STATUSA *rbd; // [esp+4Ch] [ebp-30h] BYREF
  int v97; // [esp+50h] [ebp-2Ch]
  _ENUM_SERVICE_STATUSA *bd; // [esp+54h] [ebp-28h] BYREF
  GFxImageLoader *pObject; // [esp+58h] [ebp-24h]
  IMatRenderContextInternal *v100; // [esp+5Ch] [ebp-20h]
  int recursive; // [esp+60h] [ebp-1Ch]
  unsigned int loadFlags; // [esp+64h] [ebp-18h]
  unsigned int ifont; // [esp+68h] [ebp-14h]
  GPtr<GFxImageLoader> pimportLoadStates; // [esp+6Ch] [ebp-10h]
  CP4AutoAddFile *pfontData; // [esp+70h] [ebp-Ch]
  _DWORD *v106; // [esp+74h] [ebp-8h]
  struct GMemoryHeap *v107; // [esp+78h] [ebp-4h]

  v4 = *(_DWORD *)(a1 + 32);
  if ( v4 == 0 )
    return 3;
  result = *(_DWORD *)(v4 + 116) & 0xF;
  if ( result != 1 )
  {
    if ( result != 0 )
      return result;
    GFxMovieBindProcess::SetBindState(
      this: (GFxMovieBindProcess *)a1,
      a2: a1,
      a3: *(_DWORD *)(*(_DWORD *)(a1 + 32) + 116) & 0xFFFFFFF0 | 1);
  }
  v6 = *(_DWORD *)(a1 + 20);
  v87 = a3;
  if ( v6 != 0 )
    v7 = *(_DWORD **)(v6 + 32);
  else
    v7 = *(_DWORD **)(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 32) + 148);
  v106 = v7;
  v84 = a2;
  if ( v7 != nullptr )
    goto LABEL_24;
  v8 = *(_DWORD *)(*(_DWORD *)(a1 + 36) + 32);
  ifont = *(_DWORD *)(v8 + 144) + 8;
  GMutex::Lock(this: (IMatRenderContextInternal *)ifont);
  v9 = *(_DWORD *)(a1 + 20);
  if ( v9 != 0 )
    v7 = *(_DWORD **)(v9 + 32);
  else
    v7 = *(_DWORD **)(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 32) + 148);
  v106 = v7;
  if ( v7 == nullptr )
  {
    do
    {
      if ( *(_DWORD *)(v8 + 128) != 1 || *(_BYTE *)(*(_DWORD *)(a1 + 32) + 132) != 0 )
        break;
      GWaitCondition::Wait(
        this: (GWaitCondition *)(*(_DWORD *)(v8 + 144) + 28),
        a2: (struct GMutex *)(*(_DWORD *)(v8 + 144) + 8),
        a3: 0xFFFFFFFF);
      v10 = *(_DWORD *)(a1 + 20);
      v7 = v10 != 0 ? *(_DWORD **)(v10 + 32) : *(_DWORD **)(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 32) + 148);
    }
    while ( v7 == nullptr );
    v106 = v7;
  }
  if ( *(_DWORD *)(v8 + 128) == 3 )
    *(_BYTE *)(*(_DWORD *)(a1 + 32) + 132) = 1;
  GMutex::Unlock(this: (IMatRenderContextInternal *)ifont);
  if ( v7 != nullptr )
  {
LABEL_24:
    if ( *(_BYTE *)(*(_DWORD *)(a1 + 32) + 132) == 0 )
    {
      v11 = *(CP4AutoAddFile **)(a1 + 16);
      v12 = *(_DWORD *)(a1 + 32);
      *(_DWORD *)(a1 + 20) = v7;
      pfontData = v11;
      loadFlags = *(_DWORD *)(v12 + 20);
      if ( (loadFlags & 0x100000) != 0
        || (v13 = v7[3] == 0, v14 = (struct GMemoryHeap *)v7[5], v107 = v14, ifont = 0, v13) )
      {
LABEL_62:
        v13 = v7[4] == 0;
        v32 = *(_DWORD *)(a1 + 32);
        v33 = (int *)v7[7];
        v34 = (GFxImageLoader *)(v32 + 24);
        v35 = *(struct GMemoryHeap **)(v32 + 8);
        pimportLoadStates.pObject = v34;
        v107 = v35;
        ifont = 0;
        if ( v13 )
        {
LABEL_81:
          if ( v7[2] != 0 )
          {
            v40 = (_DWORD *)v7[6];
            v91 = 0;
            v92 = 0;
            v93 = 0;
            v106 = v40;
            ifont = 0;
            do
            {
              v41 = (char)pimportLoadStates.pObject[3].__vftable;
              v42 = v106[2];
              rbd = nullptr;
              v97 = 0;
              if ( v41 != 0 && v42 < pimportLoadStates.pObject->RefCount )
              {
                v43 = pimportLoadStates.pObject->SType + 8 * v42;
                if ( *(_DWORD *)v43 != 0 )
                {
                  GRefCountImpl::AddRef(this: *(IShaderDevice **)v43, a2: (VertexShaderHandle_t__ *)v84);
                  if ( rbd != nullptr )
                    GFxResource::Release(this: (IShaderDevice *)rbd);
                }
                rbd = *(_ENUM_SERVICE_STATUSA **)v43;
                v97 = *(_DWORD *)(v43 + 4);
              }
              else
              {
                GFxResourceBinding::GetResourceData_Locked(
                  this: (GFxResourceBinding *)pimportLoadStates.pObject,
                  a2: (struct GFxResourceBindData *)&rbd,
                  a3: v42);
              }
              if ( rbd != nullptr )
              {
                v100 = (IMatRenderContextInternal *)rbd;
                v51 = v92 + 1;
                if ( v92 + 1 >= v92 )
                {
                  if ( v51 >= v93 )
                    GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                      this: (CVertexBuilder *)&v91,
                      pheapAddr: (ButtonCode_t)&v91,
                      newCapacity: v51 + (v51 >> 2));
                }
                else if ( v51 < v93 >> 1 )
                {
                  GArrayDataBase<GRenderer *,GAllocatorGH<GRenderer *,2>,GArrayDefaultPolicy>::Reserve(
                    this: (CVertexBuilder *)&v91,
                    pheapAddr: (ButtonCode_t)&v91,
                    newCapacity: v92 + 1);
                }
                v92 = v51;
                v52 = (IMatRenderContextInternal **)(v91 + 4 * v51 - 4);
                if ( v52 != nullptr )
                  *v52 = v100;
                if ( rbd != nullptr )
                  GFxResource::Release(this: (IShaderDevice *)rbd);
              }
              v53 = (_DWORD *)v106[3];
              ++ifont;
              v106 = v53;
            }
            while ( ifont < v7[2] );
            if ( v92 != 0 && pfontData[2].m_spImpl.m_p[1].m_sFilename.m_Storage.m_Memory.m_nAllocationCount != 0 )
            {
              v54 = LOBYTE(pfontData[17].m_spImpl.m_p) != 0 || pfontData[6].m_spImpl.m_p != nullptr;
              GFx_GenerateFontBitmaps(
                a1: (struct GFxFontPackParams *)pfontData[2].m_spImpl.m_p[1].m_sFilename.m_Storage.m_Memory.m_nAllocationCount,
                a2: (int)&v91,
                a3: (struct GFxImageCreator *)pfontData[2].m_spImpl.m_p->m_sFilename.m_Storage.m_nActualLength,
                a4: (struct GFxRenderConfig *)pfontData[8].m_spImpl.m_p,
                a5: (struct GFxLog *)pfontData[3].m_spImpl.m_p,
                a6: (struct GFxResourceId *)(a1 + 24),
                a7: v107,
                a8: v54);
            }
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v91);
          }
          *(_DWORD *)(*(_DWORD *)(a1 + 32) + 128) = v7[1];
          InterlockedExchange(
            Target: (volatile LONG *)(*(_DWORD *)(a1 + 32) + 124),
            Value: *(_DWORD *)(*(_DWORD *)(a1 + 32) + 124) + 1);
          if ( *(_DWORD *)(*(_DWORD *)(a1 + 32) + 124) == 1 )
          {
            v55 = *(_DWORD *)(a1 + 32);
            v100 = (IMatRenderContextInternal *)(*(_DWORD *)(v55 + 116) | 0x100);
            if ( v55 != 0 )
            {
              v56 = *(IMatRenderContextInternal **)(v55 + 120);
              GMutex::Lock(this: v56 + 2);
              *(_DWORD *)(v55 + 116) = v100;
              GWaitCondition::NotifyAll(
                this: (CUtlVector<int,CUtlMemory<int,int> > *)(*(_DWORD *)(v55 + 120) + 28),
                a2: (int)v84);
              GMutex::Unlock(this: v56 + 2);
            }
          }
          v57 = *(_DWORD *)(a1 + 32);
          if ( *(_DWORD *)(v57 + 124) == (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a1 + 36) + 40))(a1: *(_DWORD *)(a1 + 36)) )
          {
            *(_DWORD *)(*(_DWORD *)(a1 + 32) + 128) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 32) + 40);
            v58 = *(_DWORD *)(a1 + 28);
            if ( v58 != 0 )
            {
              v59 = *(_DWORD *)(a1 + 32);
              v60 = (_RTL_CRITICAL_SECTION *)(v59 + 80);
              v94[0] = &`GFxMovieBindProcess::BindNextFrame'::`114'::ImagePackVisitor::`vftable';
              v94[1] = v58;
              EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v59 + 80));
              v61 = *(IShaderDevice **)(v59 + 16);
              if ( v61 != nullptr && GFxResource::AddRef_NotZero(this: v61) != 0 )
              {
                v62 = *(IShaderDevice **)(v59 + 16);
                LeaveCriticalSection(lpCriticalSection: v60);
              }
              else
              {
                LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v59 + 80));
                v62 = nullptr;
              }
              ((void (__thiscall *)(IShaderDevice *, _DWORD *, int))v62->DestroyVertexBuffer)(a1: v62, a2: v94, a3: 2);
              GFxResource::Release(this: v62);
              v94[0] = &GString::InitStruct::`vftable';
            }
            v63 = *(_DWORD *)(a1 + 28);
            if ( v63 != 0 )
              (*(void (__thiscall **)(int))(*(_DWORD *)v63 + 16))(a1: v63);
            *(_BYTE *)(*(_DWORD *)(a1 + 32) + 60) = 1;
            v64 = *(_DWORD *)(a1 + 32);
            v65 = *(_DWORD *)(v64 + 116) & 0xFFFFFDF0 | 0x202;
            if ( v64 != 0 )
            {
              v100 = (IMatRenderContextInternal *)(*(_DWORD *)(v64 + 120) + 8);
              GMutex::Lock(this: v100);
              v66 = (CUtlVector<int,CUtlMemory<int,int> > *)(*(_DWORD *)(v64 + 120) + 28);
              *(_DWORD *)(v64 + 116) = v65;
              GWaitCondition::NotifyAll(this: v66, a2: (int)v84);
              GMutex::Unlock(this: v100);
            }
          }
          ifont = (unsigned int)pfontData[5].m_spImpl.m_p;
          if ( ifont != 0 )
          {
            v67 = *(_DWORD **)(a1 + 32);
            v68 = (int *)v67[3];
            v69 = v68[8];
            v70 = *v68;
            v100 = *(IMatRenderContextInternal **)(v69 + 40);
            loadFlags = (*(int (__thiscall **)(int *))(v70 + 40))(a1: v68);
            v71 = v67[31];
            v72 = v67[32];
            recursive = v71;
            GString::GString(result: (CImagePacker *)(v69 + 36));
            v88[2] = v100;
            v88[3] = recursive;
            v73 = *(void (__thiscall **)(unsigned int, _DWORD *))(*(_DWORD *)ifont + 4);
            v88[4] = loadFlags;
            v88[1] = v72;
            v73(a1: ifont, a2: v88);
            v74 = (void *)(v88[0] & 0xFFFFFFFC);
            if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v88[0] & 0xFFFFFFFC) + 4), Value: -1) == 1 )
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v74);
          }
          return *(_DWORD *)(*(_DWORD *)(a1 + 32) + 116) & 0xF;
        }
        while ( 1 )
        {
          v36 = *v33;
          if ( *v33 != 0 )
          {
            pObject = pimportLoadStates.pObject;
            v37 = v33[1];
            bd = nullptr;
            if ( (*(unsigned __int8 (__thiscall **)(int, int, _ENUM_SERVICE_STATUSA **, CP4AutoAddFile *, struct GMemoryHeap *))(*(_DWORD *)v36 + 12))(
                   a1: v36,
                   a2: v37,
                   a3: &bd,
                   a4: pfontData,
                   a5: v107) != 0 )
            {
              if ( *(_DWORD *)(a1 + 28) != 0
                && ((*((int (__thiscall **)(_ENUM_SERVICE_STATUSA *))bd->lpServiceName + 2))(a1: bd) & 0xFF00) == 0x100
                && GHashSetBase<unsigned int,GFixedSizeHash<unsigned int>,GFixedSizeHash<unsigned int>,GAllocatorLH<unsigned int,2>,GHashsetCachedEntry<unsigned int,GFixedSizeHash<unsigned int>>>::Get<unsigned int>(a1: v33 + 2) == 0
                && (*((unsigned __int8 (__thiscall **)(_ENUM_SERVICE_STATUSA *))bd->lpServiceName + 2))(a1: bd) == 1 )
              {
                MovieDefImplAddRef = (IShaderDevice *)GFxMovieDefImpl::BindTaskData::GetMovieDefImplAddRef(this: *(GFxMovieDefImpl::BindTaskData **)(a1 + 32));
                (*(void (__thiscall **)(_DWORD, int *, _ENUM_SERVICE_STATUSA *))(**(_DWORD **)(a1 + 28) + 12))(
                  a1: *(_DWORD *)(a1 + 28),
                  a2: v33,
                  a3: bd);
                if ( MovieDefImplAddRef != nullptr )
                  GFxResource::Release(this: MovieDefImplAddRef);
                v7 = v106;
              }
            }
            else if ( *(_BYTE *)(*(_DWORD *)(a1 + 32) + 132) != 0 )
            {
              v44 = *(_DWORD *)(a1 + 28);
              if ( v44 != 0 )
                (*(void (__thiscall **)(int))(*(_DWORD *)v44 + 16))(a1: v44);
              *(_BYTE *)(*(_DWORD *)(a1 + 32) + 60) = 1;
              v45 = *(_DWORD *)(a1 + 32);
              v46 = *(_DWORD *)(v45 + 116) & 0xFFFFFFF0 | 3;
              if ( v45 != 0 )
              {
                v100 = (IMatRenderContextInternal *)(*(_DWORD *)(v45 + 120) + 8);
                GMutex::Lock(this: v100);
                v47 = (CUtlVector<int,CUtlMemory<int,int> > *)(*(_DWORD *)(v45 + 120) + 28);
                *(_DWORD *)(v45 + 116) = v46;
                GWaitCondition::NotifyAll(this: v47, a2: (int)v84);
                GMutex::Unlock(this: v100);
              }
              v48 = *(_DWORD *)(a1 + 32);
              v49 = *(_DWORD *)(v48 + 120);
              if ( v49 != 0 )
                GRefCountImpl::AddRef(this: *(IShaderDevice **)(v48 + 120), a2: (VertexShaderHandle_t__ *)v84);
              v50 = *(IShaderAPI **)(a1 + 32);
              if ( v50 != nullptr )
                GRefCountImpl::Release(this: v50);
              *(_DWORD *)(a1 + 32) = 0;
              GMutex::Lock(this: (IMatRenderContextInternal *)(v49 + 8));
              *(_BYTE *)(v49 + 32) = 1;
              GWaitCondition::NotifyAll(this: (CUtlVector<int,CUtlMemory<int,int> > *)(v49 + 28), a2: (int)v84);
              GMutex::Unlock(this: (IMatRenderContextInternal *)(v49 + 8));
              GRefCountImpl::Release(this: (IShaderAPI *)v49);
              if ( bd != nullptr )
                GFxResource::Release(this: (IShaderDevice *)bd);
              return 3;
            }
            GFxResourceBinding::SetBindData(
              this: (GFxResourceBinding *)pimportLoadStates.pObject,
              a2: v33[2],
              a3: (const struct GFxResourceBindData *)&bd);
            if ( bd != nullptr )
              GFxResource::Release(this: (IShaderDevice *)bd);
          }
          v33 = (int *)v33[3];
          if ( ++ifont >= v7[4] )
            goto LABEL_81;
        }
      }
      pAutoRelease = v14;
      while ( 1 )
      {
        v16 = *(_DWORD *)(pAutoRelease->SelfSize & 0xFFFFFFFC) & 0x7FFFFFFF;
        if ( v16 < 0xE
          || GString::CompareNoCase(
               a1: (const char *)((pAutoRelease->SelfSize & 0xFFFFFFFC) + v16 - 6),
               a2: "gfxfontlib.swf") != 0 )
        {
          goto LABEL_34;
        }
        v17 = GFxMovieDefImpl::BindTaskData::GetMovieDefImplAddRef(this: *(GFxMovieDefImpl::BindTaskData **)(a1 + 32));
        v18 = (IShaderDevice *)v17;
        if ( v17 != nullptr )
        {
          v19 = (IShaderAPI *)(*(int (__thiscall **)(int, int))(*((_DWORD *)v17 + 3) + 12))(a1: (int)v17 + 12, a2: 19);
          if ( v19 == nullptr )
          {
            GFxResource::Release(this: v18);
            pAutoRelease = v107;
LABEL_34:
            GFxLoadStates::CloneForImport(this: (P4Client_t *)pfontData);
            v20 = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 16);
            pimportLoadStates.pObject = v21;
            v22 = *(_DWORD *)(a1 + 44);
            v23 = loadFlags | 1;
            v95[0] = v20;
            v95[1] = 0;
            if ( v22 != 0 )
            {
              for ( ; *(_DWORD *)(v22 + 4) != 0; v22 = *(_DWORD *)(v22 + 4) )
                ;
              *(_DWORD *)(v22 + 4) = v95;
            }
            else
            {
              *(_DWORD *)(a1 + 44) = v95;
            }
            if ( *(_BYTE *)(a1 + 40) == 0 )
              goto LABEL_43;
            v24 = *(_DWORD *)(pAutoRelease->SelfSize & 0xFFFFFFFC) & 0x7FFFFFFF;
            if ( v24 <= 4 )
              goto LABEL_43;
            if ( GString::CompareNoCase(a1: (const char *)((pAutoRelease->SelfSize & 0xFFFFFFFC) + v24 + 4), a2: ".swf") != 0 )
              goto LABEL_43;
            p_SelfSize = &v107->SelfSize;
            GFxURLBuilder::LocationInfo::LocationInfo(
              this: &v90,
              a2: File_Import,
              result: (CImagePacker *)&v107->SelfSize,
              a4: (const struct GString *)&pfontData[16]);
            GString::Clear(this: &v90.FileName);
            GString::AppendString(
              this: (CUtlMemory<CImagePacker,int> *)&v90.FileName,
              putf8str: (*p_SelfSize & 0xFFFFFFFC) + 8);
            GString::AppendString(this: (CUtlMemory<CImagePacker,int> *)&v90.FileName, putf8str: (int)".gfx");
            v82.m_nGrowSize = v23;
            *(_QWORD *)&v82.m_pMemory = __PAIR64__(&v90, (unsigned int)pimportLoadStates.pObject);
            Movie_LoadState = GFxLoaderImpl::CreateMovie_LoadState(
                                a1: v82,
                                a2: *(const struct GFxURLBuilder::LocationInfo **)(a1 + 44),
                                a3: 0,
                                a4: v84,
                                a5: v87);
            GFxURLBuilder::LocationInfo::~LocationInfo(result: v85);
            if ( Movie_LoadState == nullptr )
            {
LABEL_43:
              v89 = 1;
              GString::GString(result: (CImagePacker *)&v107->SelfSize);
              GString::GString(result: (CImagePacker *)&pfontData[16]);
              v83.m_nGrowSize = v23;
              *(_QWORD *)&v83.m_pMemory = __PAIR64__(&v89, (unsigned int)pimportLoadStates.pObject);
              Movie_LoadState = GFxLoaderImpl::CreateMovie_LoadState(
                                  a1: v83,
                                  a2: *(const struct GFxURLBuilder::LocationInfo **)(a1 + 44),
                                  a3: 0,
                                  a4: v84,
                                  a5: v87);
              GFxURLBuilder::LocationInfo::~LocationInfo(result: v86);
            }
            v27 = *(_DWORD **)(a1 + 44);
            if ( v27 == v95 )
            {
              *(_DWORD *)(a1 + 44) = 0;
            }
            else if ( v27[1] != 0 )
            {
              while ( 1 )
              {
                v28 = (_DWORD *)v27[1];
                if ( v28 == v95 )
                  break;
                v27 = (_DWORD *)v27[1];
                if ( v28[1] == 0 )
                  goto LABEL_51;
              }
              v27[1] = v28[1];
            }
LABEL_51:
            if ( Movie_LoadState == nullptr )
            {
              v39 = *(_DWORD *)(a1 + 28);
              if ( v39 != 0 )
                (*(void (__thiscall **)(int))(*(_DWORD *)v39 + 16))(a1: v39);
              *(_BYTE *)(*(_DWORD *)(a1 + 32) + 60) = 1;
              GFxMovieBindProcess::SetBindState(
                this: (GFxMovieBindProcess *)a1,
                a2: a1,
                a3: *(_DWORD *)(*(_DWORD *)(a1 + 32) + 116) & 0xFFFFFFF0 | 4);
              if ( pimportLoadStates.pObject != nullptr )
                GRefCountImpl::Release(this: (IShaderAPI *)pimportLoadStates.pObject);
              return 4;
            }
            v29 = pfontData;
            LOBYTE(recursive) = *((_DWORD *)Movie_LoadState + 7) == *(_DWORD *)(a1 + 32);
            if ( (_BYTE)recursive != 0 )
            {
              m_p = pfontData[3].m_spImpl.m_p;
              if ( m_p != nullptr )
                GFxLogBase<GFxLog>::LogWarning(
                  this: (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)((v107->SelfSize & 0xFFFFFFFC) + 8),
                  pfmt: (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int),ITexture *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)&m_p->m_sFilename.m_Storage.m_Memory.m_nGrowSize,
                  this_4: (int)"Warning: Self recursive import detected in '%s'\n",
                  this_8: (v107->SelfSize & 0xFFFFFFFC) + 8);
            }
            GFxMovieDefImpl::BindTaskData::ResolveImport(
              this: *(GFxMovieDefImpl::BindTaskData **)(a1 + 32),
              a2: (CUtlMemory<CImagePacker,int> *)v107,
              a3: (IShaderDevice *)Movie_LoadState,
              a4: (struct GFxLoadStates *)v29,
              a5: recursive);
            v100 = (IMatRenderContextInternal *)v29[2].m_spImpl.m_p[1].__vftable;
            if ( v100 != nullptr )
            {
              v31 = (IShaderDevice *)GFxMovieDefImpl::BindTaskData::GetMovieDefImplAddRef(this: *(GFxMovieDefImpl::BindTaskData **)(a1 + 32));
              if ( v31 != nullptr )
              {
                ((void (__thiscall *)(IMatRenderContextInternal *, IShaderDevice *, struct GFxMovieDefImpl *, unsigned int))v100[3].Release)(
                  a1: &v100[3],
                  a2: v31,
                  a3: Movie_LoadState,
                  a4: (v107->SelfSize & 0xFFFFFFFC) + 8);
                GFxResource::Release(this: v31);
              }
            }
            GFxResource::Release(this: (IShaderDevice *)Movie_LoadState);
            if ( pimportLoadStates.pObject != nullptr )
              GRefCountImpl::Release(this: (IShaderAPI *)pimportLoadStates.pObject);
            goto LABEL_60;
          }
          GFxMovieDefImpl::BindTaskData::ResolveImportThroughFontLib(
            this: *(CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,LightDesc_t const *),int,LightDesc_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(a1 + 32),
            a2: v107);
          GRefCountImpl::Release(this: v19);
          GFxResource::Release(this: v18);
        }
LABEL_60:
        pAutoRelease = (struct GMemoryHeap *)v107->pAutoRelease;
        ++ifont;
        v107 = pAutoRelease;
        if ( ifont >= v106[3] )
        {
          v7 = v106;
          goto LABEL_62;
        }
      }
    }
  }
  v75 = *(_DWORD *)(a1 + 28);
  if ( v75 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v75 + 16))(a1: v75);
  *(_BYTE *)(*(_DWORD *)(a1 + 32) + 60) = 1;
  v76 = *(_DWORD *)(a1 + 32);
  v77 = ((*(_BYTE *)(v76 + 132) == 0) + 3) | *(_DWORD *)(v76 + 116) & 0xFFFFFFF0;
  recursive = (*(_BYTE *)(v76 + 132) == 0) + 3;
  if ( v76 != 0 )
  {
    v100 = (IMatRenderContextInternal *)(*(_DWORD *)(v76 + 120) + 8);
    GMutex::Lock(this: v100);
    v78 = (CUtlVector<int,CUtlMemory<int,int> > *)(*(_DWORD *)(v76 + 120) + 28);
    *(_DWORD *)(v76 + 116) = v77;
    GWaitCondition::NotifyAll(this: v78, a2: (int)v84);
    GMutex::Unlock(this: v100);
  }
  v79 = *(_DWORD *)(a1 + 32);
  v80 = *(_DWORD *)(v79 + 120);
  if ( v80 != 0 )
    GRefCountImpl::AddRef(this: *(IShaderDevice **)(v79 + 120), a2: (VertexShaderHandle_t__ *)v84);
  v81 = *(IShaderAPI **)(a1 + 32);
  if ( v81 != nullptr )
    GRefCountImpl::Release(this: v81);
  *(_DWORD *)(a1 + 32) = 0;
  GMutex::Lock(this: (IMatRenderContextInternal *)(v80 + 8));
  *(_BYTE *)(v80 + 32) = 1;
  GWaitCondition::NotifyAll(this: (CUtlVector<int,CUtlMemory<int,int> > *)(v80 + 28), a2: (int)v84);
  GMutex::Unlock(this: (IMatRenderContextInternal *)(v80 + 8));
  GRefCountImpl::Release(this: (IShaderAPI *)v80);
  return recursive;
}

//------------------------------------------------------------------------------
// Address: 0x100DA370
// Name: public: virtual void GFxMovieBindProcess::Execute(void)
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),CFuncMemPolicyNone> *__usercall GFxMovieBindProcess::Execute@<eax>(
        int a1@<ecx>,
        struct GFxLoaderImpl::LoadStackItem *a2@<ebx>,
        unsigned int a3@<edi>)
{
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),CFuncMemPolicyNone> *Frame; // eax

  do
    Frame = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),CFuncMemPolicyNone> *)GFxMovieBindProcess::BindNextFrame(a1, a2, a3);
  while ( Frame == (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),CFuncMemPolicyNone> *)1 );
  return Frame;
}

//------------------------------------------------------------------------------
// Address: 0x100DA390
// Name: public: virtual void GFxPlaceObjectUnpacked::Unpack(struct GFxPlaceObjectBase::UnpackedData __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPlaceObjectUnpacked::Unpack(IStream *this, CMatQueuedMesh *a2)
{
  a2[1].m_nMSTActualVertexOffsetInBytes = 0;
  a2[1].IMesh::IIndexBuffer::__vftable = nullptr;
  a2[1].m_pMSTActualMesh = nullptr;
  GFxCharPosInfo::operator=(this: a2, __that: this + 1);
}

//------------------------------------------------------------------------------
// Address: 0x100DA3B0
// Name: public: GFxMovieDataDef::LoadTaskData::LoadTaskData(class GFxMovieDataDef __near *,char const __near *,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::LoadTaskData::LoadTaskData(
        CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *this,
        CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *pdataDef,
        int pdataDef_4,
        int pdataDef_8)
{
  int v5; // ecx
  int (__thiscall *v6)(int, int, int *); // edx
  _DWORD *v7; // eax
  FloatCubeMap_t *v8; // eax
  IMatRenderContextInternal *v9; // eax
  IMatRenderContextInternal *v10; // edi
  IShaderAPI *v11; // ecx
  int v12; // ecx
  int (__thiscall *v13)(int, int, int *); // edx
  GFxSpriteDef *v14; // eax
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v15; // edi
  int v16; // ecx
  int (__thiscall *v17)(int, int, int *); // edx
  const GArrayData<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *v18; // [esp+0h] [ebp-1Ch]
  int v19; // [esp+Ch] [ebp-10h] BYREF
  int v20; // [esp+10h] [ebp-Ch] BYREF
  int v21; // [esp+14h] [ebp-8h] BYREF
  int v22; // [esp+18h] [ebp-4h] BYREF
  GArrayData<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *pdataDef_8a; // [esp+2Ch] [ebp+10h]

  this->m_Memory.m_pMemory = (TextureLodOverride::OverrideInfo *)&GRefCountImplCore::`vftable';
  this->m_Memory.m_nAllocationCount = 1;
  *((_DWORD *)this + 5) = pdataDef_8;
  this->m_pElements = nullptr;
  this->m_Memory.m_nGrowSize = 0;
  this->m_Size = 0;
  *((_DWORD *)this + 7) = pdataDef_8;
  *((_DWORD *)this + 6) = 0;
  this->m_Memory.m_pMemory = (TextureLodOverride::OverrideInfo *)&GFxMovieDataDef::LoadTaskData::`vftable';
  *((_DWORD *)this + 8) = 0;
  GStringLH::GStringLH(this: (CFixedBitVecBase<128> *)((char *)this + 36), pdata: pdataDef_4);
  GFxMovieHeaderData::GFxMovieHeaderData(this: (GFxMovieHeaderData *)(this + 2));
  *((_DWORD *)this + 36) = 0;
  *((_DWORD *)this + 37) = 0;
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 39) = 0;
  *((_DWORD *)this + 40) = 0;
  *((_DWORD *)this + 41) = 0;
  *((_DWORD *)this + 42) = 0;
  *((_DWORD *)this + 43) = 0;
  *((_DWORD *)this + 44) = 0;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 184), spinCount: 0);
  *((_DWORD *)this + 52) = 0;
  *((_DWORD *)this + 53) = 0;
  *((_DWORD *)this + 54) = 0;
  GLock::GLock(lpCriticalSection: (LPCRITICAL_SECTION)(this + 11), spinCount: 0);
  *((_DWORD *)this + 61) = 0;
  *((_DWORD *)this + 62) = 0;
  *((_DWORD *)this + 63) = 0;
  *((_DWORD *)this + 64) = 0;
  *((_DWORD *)this + 65) = 0;
  *((_DWORD *)this + 66) = 0;
  *((_DWORD *)this + 68) = 0;
  *((_DWORD *)this + 69) = 327680;
  v5 = *((_DWORD *)this + 7);
  *((_DWORD *)this + 70) = 0;
  *((_DWORD *)this + 71) = 0;
  *((_DWORD *)this + 29) = 0;
  *((_DWORD *)this + 30) = 0;
  *((_DWORD *)this + 31) = 0;
  v6 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v5 + 40);
  v22 = 258;
  v7 = (_DWORD *)v6(a1: v5, a2: 12, a3: &v22);
  if ( v7 != nullptr )
    v8 = GFxPathAllocator::GFxPathAllocator(this: v7, result: (FloatCubeMap_t *)0x1FF8);
  else
    v8 = nullptr;
  *((_DWORD *)this + 6) = v8;
  *((_BYTE *)this + 136) = 0;
  *((_DWORD *)this + 32) = 0;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 35) = 0;
  *((_DWORD *)this + 45) = 0;
  *((_DWORD *)this + 67) = 0;
  v21 = 265;
  v9 = (IMatRenderContextInternal *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 36, a3: &v21);
  v10 = v9;
  if ( v9 != nullptr )
  {
    v9->__vftable = (IMatRenderContextInternal_vtbl *)&GRefCountImplCore::`vftable';
    v9[1].__vftable = (IMatRenderContextInternal_vtbl *)1;
    v9->__vftable = (IMatRenderContextInternal_vtbl *)&GFxLoadUpdateSync::`vftable';
    GMutex::GMutex(this: v9 + 2, recursive: 1);
    GWaitCondition::GWaitCondition(this: (CUtlVector<int,CUtlMemory<int,int> > *)&v10[7]);
    LOBYTE(v10[8].__vftable) = 0;
  }
  else
  {
    v10 = nullptr;
  }
  v11 = *((IShaderAPI **)this + 36);
  if ( v11 != nullptr )
    GRefCountImpl::Release(this: v11);
  *((_DWORD *)this + 36) = v10;
  v12 = *((_DWORD *)this + 7);
  v13 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v12 + 40);
  v20 = 2;
  v14 = (GFxSpriteDef *)v13(a1: v12, a2: 56, a3: &v20);
  if ( v14 != nullptr )
    v15 = (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GFxSpriteDef::GFxSpriteDef(this: v14, a2: (struct GFxMovieDataDef *)pdataDef);
  else
    v15 = nullptr;
  GFxSpriteDef::InitEmptyClipDef();
  GFxMovieDataDef::LoadTaskData::AddResource(this, rid: 0x10001u, pres: v15);
  v16 = *((_DWORD *)this + 7);
  v17 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v16 + 40);
  v19 = 2;
  if ( v17(a1: v16, a2: 88, a3: &v19) != 0 )
    pdataDef_8a = (GArrayData<GPtr<GFxAmpServer::ViewStats>,GAllocatorLH<GPtr<GFxAmpServer::ViewStats>,2>,GArrayDefaultPolicy> *)GFxEditTextCharacterDef::GFxEditTextCharacterDef(result: v18);
  else
    pdataDef_8a = nullptr;
  GFxEditTextCharacterDef::InitEmptyTextDef(this: pdataDef_8a, a2: v18);
  GFxMovieDataDef::LoadTaskData::AddResource(
    this,
    rid: 0x10002u,
    pres: (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)pdataDef_8a);
  if ( pdataDef_8a != nullptr )
    GFxResource::Release(this: (IShaderDevice *)pdataDef_8a);
  if ( v15 != nullptr )
    GFxResource::Release(this: (IShaderDevice *)v15);
}

//------------------------------------------------------------------------------
// Address: 0x100DA610
// Name: public: void GFxMovieDataDef::LoadTaskData::InitImageFileMovieDef(unsigned int,class GFxImageResource __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::LoadTaskData::InitImageFileMovieDef(
        CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *this,
        unsigned int fileLength,
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pimageResource,
        bool a4)
{
  int v5; // ecx
  int (__thiscall *v6)(int, int, int *); // edx
  old_bf_read *v7; // eax
  old_bf_read *v8; // edi
  int v9; // ecx
  TextureLodOverride::OverrideInfo *v10; // eax
  bool v11; // zf
  TextureLodOverride::OverrideInfo *v12; // eax
  void *v13; // eax
  IMatRenderContextInternal *v14; // ebx
  CUtlVector<int,CUtlMemory<int,int> > *v15; // ecx
  __int128 v16; // [esp-4h] [ebp-CCh]
  const CMaterialDict::MissingMaterial_t *v17; // [esp+20h] [ebp-A8h]
  CMemberFunctor1<CMatRenderContextBase *,bool (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> pos; // [esp+2Ch] [ebp-9Ch] BYREF
  int v19; // [esp+80h] [ebp-48h] BYREF
  void *ptagMem; // [esp+84h] [ebp-44h]
  int v21; // [esp+88h] [ebp-40h] BYREF

  *((_DWORD *)this + 10) = fileLength;
  GFxMovieDataDef::LoadTaskData::AddResource(this, rid: 0, pres: pimageResource);
  v5 = *((_DWORD *)this + 7);
  v6 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v5 + 40);
  v19 = 2;
  v7 = (old_bf_read *)v6(a1: v5, a2: 140, a3: &v19);
  v8 = v7;
  if ( v7 != nullptr )
  {
    v7->m_pData = (const unsigned __int8 *)&GFxResource::`vftable';
    v7->m_nDataBytes = 1;
    v7->m_nDataBits = 0;
    v7->m_iCurBit = 0x40000;
    v7->m_pData = (const unsigned __int8 *)&GFxShapeCharacterDef::`vftable';
    GFxShapeWithStyles::GFxShapeWithStyles(this: (int)&v7->m_bOverflow, result: (IClientUnknown *)0x1FF8);
  }
  else
  {
    v8 = nullptr;
  }
  GFxShapeCharacterDef::SetToImage(this: v8, pimage: (struct GFxImageResource *)pimageResource, a3: a4);
  v8->m_iCurBit = 1;
  GFxMovieDataDef::LoadTaskData::AddResource(
    this,
    rid: 1u,
    pres: (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMorph *),IMorph *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v8);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 11));
  GArrayData<GFxTimelineDef::Frame,GAllocatorLH<GFxTimelineDef::Frame,2>,GArrayDefaultPolicy>::Resize(
    this: (GFxKeyboardState *)((char *)this + 244),
    newSize: *((GFxKeyboardState::IListener **)this + 17));
  GArrayData<GFxTimelineDef::Frame,GAllocatorLH<GFxTimelineDef::Frame,2>,GArrayDefaultPolicy>::Resize(
    this: (GFxKeyboardState *)((char *)this + 256),
    newSize: *((GFxKeyboardState::IListener **)this + 17));
  *((_DWORD *)this + 67) = 0;
  v9 = *((_DWORD *)this + 5);
  v21 = 260;
  v10 = (TextureLodOverride::OverrideInfo *)(*(int (__thiscall **)(int, int, int *))(*(_DWORD *)v9 + 40))(
                                              a1: v9,
                                              a2: 96,
                                              a3: &v21);
  if ( v10 != nullptr )
  {
    *(_DWORD *)&v10->x = this->m_pElements;
    this->m_pElements = v10;
    v11 = &v10[2] == nullptr;
    v12 = v10 + 2;
    ptagMem = v12;
    if ( !v11 )
    {
      G_Construct<GFxPlaceObjectUnpacked>(a1: (int)&v12[2]);
      GMatrix2D::SetIdentity(result: v17);
      *((_QWORD *)&v16 + 1) = (unsigned int)GRenderer::Cxform::Cxform() | 0x100000000LL;
      *(_QWORD *)&v16 = 1;
      GFxCharPosInfo::GFxCharPosInfo(
        this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *,IMaterial *),IMesh *,IMaterial *,CFuncMemPolicyNone> *)&pos,
        chId: (CMatRenderContextBase *)1,
        depth: v16);
      GFxCharPosInfo::operator=(this: (CMatQueuedMesh *)((char *)ptagMem + 8), __that: (IStream *)&pos);
      v13 = ptagMem;
      *(_DWORD *)ptagMem = (char *)ptagMem + 4;
      **((_DWORD **)this + 61) = v13;
      *(_DWORD *)(*((_DWORD *)this + 61) + 4) = 1;
      GMemory::pGlobalHeap->Free(
        this: GMemory::pGlobalHeap,
        a2: pos.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable);
    }
  }
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 11));
  v14 = *((IMatRenderContextInternal **)this + 36);
  v21 = *((_DWORD *)this + 17);
  GMutex::Lock(this: v14 + 2);
  v15 = (CUtlVector<int,CUtlMemory<int,int> > *)(*((_DWORD *)this + 36) + 28);
  *((_DWORD *)this + 33) = v21;
  *((_DWORD *)this + 32) = 2;
  GWaitCondition::NotifyAll(this: v15, a2: (int)v17);
  GMutex::Unlock(this: v14 + 2);
  if ( v8 != nullptr )
    GFxResource::Release(this: (IShaderDevice *)v8);
}

//------------------------------------------------------------------------------
// Address: 0x100DA810
// Name: public: void GFxMovieDataDef::LoadTaskData::Read(class GFxLoadProcess __near *,class GFxMovieBindProcess __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::LoadTaskData::Read(
        CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *this,
        struct GFxLoadProcess *a2,
        struct GFxMovieBindProcess *a3)
{
  tagBITMAPINFOHEADER *v3; // eax
  tagBITMAPINFOHEADER *v5; // edi
  struct GFxLoaderImpl::LoadStackItem *v6; // ebx
  int v7; // ecx
  int v8; // ecx
  struct GFxLoaderImpl::LoadStackItem *v9; // eax
  int v10; // eax
  int v11; // edi
  int v12; // ebx
  void *v13; // edi
  void (__thiscall *v14)(CUtlDict<ITextureInternal *,unsigned short> *, unsigned __int16, HBITMAP__); // eax
  int v15; // ebx
  IMatRenderContextInternal *v16; // edi
  CUtlVector<int,CUtlMemory<int,int> > *v17; // ecx
  IMatRenderContextInternal *v18; // edi
  int v19; // ebx
  int v20; // eax
  CUtlVector<int,CUtlMemory<int,int> > *v21; // ecx
  int v22; // [esp+Ch] [ebp-5Ch]
  _DWORD v23[5]; // [esp+18h] [ebp-50h] BYREF
  IShaderDeviceDependentObject_vtbl *v24; // [esp+2Ch] [ebp-3Ch]
  int v25; // [esp+30h] [ebp-38h]
  int v26; // [esp+34h] [ebp-34h]
  struct GFxLoaderImpl::LoadStackItem *v27; // [esp+38h] [ebp-30h]
  unsigned int v28; // [esp+3Ch] [ebp-2Ch]
  struct GFxMovieBindProcess *v29; // [esp+40h] [ebp-28h]
  tagBITMAPINFOHEADER *v30; // [esp+44h] [ebp-24h]
  signed int v31; // [esp+48h] [ebp-20h]
  unsigned __int16 prenderer[2]; // [esp+4Ch] [ebp-1Ch]
  char v33; // [esp+53h] [ebp-15h]
  IShaderDeviceDependentObject pTagInfo; // [esp+54h] [ebp-14h] BYREF
  int v35; // [esp+58h] [ebp-10h]
  int v36; // [esp+5Ch] [ebp-Ch]
  int v37; // [esp+60h] [ebp-8h]

  v29 = a3;
  v3 = *((tagBITMAPINFOHEADER **)a2 + 201);
  *(_DWORD *)prenderer = a2;
  if ( v3 != nullptr )
  {
    v30 = v3;
    v5 = v3;
  }
  else
  {
    v5 = (tagBITMAPINFOHEADER *)((char *)a2 + 40);
    v30 = (tagBITMAPINFOHEADER *)((char *)a2 + 40);
  }
  v6 = (struct GFxLoaderImpl::LoadStackItem *)(this + 11);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 11));
  GArrayData<GFxTimelineDef::Frame,GAllocatorLH<GFxTimelineDef::Frame,2>,GArrayDefaultPolicy>::Resize(
    this: (GFxKeyboardState *)((char *)this + 244),
    newSize: *((GFxKeyboardState::IListener **)this + 17));
  GArrayData<GFxTimelineDef::Frame,GAllocatorLH<GFxTimelineDef::Frame,2>,GArrayDefaultPolicy>::Resize(
    this: (GFxKeyboardState *)((char *)this + 256),
    newSize: *((GFxKeyboardState::IListener **)this + 17));
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 11));
  GFxStream::LogParseClass(result: (tagEMRANGLEARC *)((char *)this + 48));
  GFxLogBase<GFxStream>::LogParse(
    this: v5,
    a2: (int)"Note: SWF Frame Rate = %f, Frames = %d\n",
    *((float *)this + 16),
    *((_DWORD *)this + 17));
  *((_DWORD *)this + 35) = 0;
  v31 = 0;
  v33 = 0;
  v28 = *((_DWORD *)this + 10) / 0x1Eu;
  if ( v28 < 0x2000 )
    v28 = 0x2000;
  v7 = *(_DWORD *)prenderer;
  if ( (unsigned int)(v5[1].biWidth + *(_DWORD *)&v5[1].biPlanes - v5[1].biHeight) < *(_DWORD *)(*(_DWORD *)prenderer
                                                                                               + 624) )
  {
    while ( 1 )
    {
      if ( *((_BYTE *)this + 136) != 0 )
      {
        GFxLoadProcess::CleanupFrameTags(this: (GFxLoadProcess *)v7);
        if ( v29 != nullptr )
        {
          v15 = *((_DWORD *)v29 + 8);
          if ( v15 != 0 )
          {
            v16 = *(IMatRenderContextInternal **)(v15 + 120);
            GMutex::Lock(this: v16 + 2);
            v17 = (CUtlVector<int,CUtlMemory<int,int> > *)(*(_DWORD *)(v15 + 120) + 28);
            *(_DWORD *)(v15 + 116) = 3;
            GWaitCondition::NotifyAll(this: v17, a2: v22);
            GMutex::Unlock(this: v16 + 2);
          }
        }
        v18 = *((IMatRenderContextInternal **)this + 36);
        v19 = *((_DWORD *)this + 33);
        GMutex::Lock(this: v18 + 2);
        *((_DWORD *)this + 32) = 3;
LABEL_44:
        v21 = (CUtlVector<int,CUtlMemory<int,int> > *)(*((_DWORD *)this + 36) + 28);
        *((_DWORD *)this + 33) = v19;
        GWaitCondition::NotifyAll(this: v21, a2: v22);
        GMutex::Unlock(this: v18 + 2);
        return;
      }
      GFxStream::OpenTag(this: (IShaderDeviceMgr *)v5, &pTagInfo);
      v8 = v36;
      v31 += v36;
      v6 = v9;
      v27 = v9;
      if ( v33 != 0 && (*((_DWORD *)this + 33) == 1 || v31 > (int)v28 || v36 > 0x2000) )
      {
        GWaitCondition::NotifyAll(this: (CUtlVector<int,CUtlMemory<int,int> > *)(*((_DWORD *)this + 36) + 28), a2: v22);
        v8 = v36;
        v33 = 0;
        v31 = 0;
      }
      v10 = *(_DWORD *)(*(_DWORD *)prenderer + 16);
      if ( *(_DWORD *)(v10 + 20) != 0 )
      {
        v11 = *(_DWORD *)(v10 + 20);
        v12 = v37;
        v26 = v8;
        v25 = v35;
        v24 = pTagInfo.__vftable;
        GString::GString(result: (CImagePacker *)((char *)this + 36));
        v23[1] = v24;
        v23[2] = v25;
        v23[3] = v26;
        v23[4] = v12;
        (*(void (__thiscall **)(int, _DWORD *, _DWORD))(*(_DWORD *)v11 + 8))(a1: v11, a2: v23, a3: 0);
        v13 = (void *)(v23[0] & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v23[0] & 0xFFFFFFFC) + 4), Value: -1) == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v13);
        v6 = v27;
        v5 = v30;
      }
      if ( v6 != (struct GFxLoaderImpl::LoadStackItem *)1 )
        break;
LABEL_25:
      GFxStream::CloseTag(this: (GFxStream *)v5);
      ++*((_DWORD *)this + 35);
      if ( v6 == (struct GFxLoaderImpl::LoadStackItem *)1 )
      {
        if ( GFxMovieDataDef::LoadTaskData::FinishLoadingFrame(this, success: *(int *)prenderer, finished: false) == 0 )
          return;
        v33 = 1;
        GFxLogBase<GFxStream>::LogParse(this: v5, a2: (int)"  ShowFrame\n");
        if ( v29 != nullptr )
          GFxMovieBindProcess::BindNextFrame(
            a1: (int)v29,
            a2: (struct GFxLoaderImpl::LoadStackItem *)1,
            a3: (unsigned int)v5);
      }
      else if ( v6 == nullptr
             && v5[1].biWidth + *(_DWORD *)&v5[1].biPlanes - v5[1].biHeight != *(_DWORD *)(*(_DWORD *)prenderer + 624) )
      {
        GFxLogBase<GFxStream>::LogWarning(
          this: v5,
          a2: (int)"Warning: GFxLoader - GFxStream-end tag hit, but not at the end of the file yet; stopping for safety\n");
        v7 = *(_DWORD *)prenderer;
        goto LABEL_38;
      }
      v7 = *(_DWORD *)prenderer;
      if ( (unsigned int)(v5[1].biWidth + *(_DWORD *)&v5[1].biPlanes - v5[1].biHeight) >= *(_DWORD *)(*(_DWORD *)prenderer + 624) )
        goto LABEL_38;
    }
    if ( (unsigned int)v6 >= 0x55 )
    {
      if ( (unsigned int)v6 - 1000 > 9 )
      {
LABEL_24:
        GFxLogBase<GFxStream>::LogParse(this: v5, a2: (int)"*** no tag loader for type %d\n", v6);
        GFxStream::LogTagBytes(this: (GFxStream *)v5);
        goto LABEL_25;
      }
      v14 = *((void (__thiscall **)(CUtlDict<ITextureInternal *,unsigned short> *, unsigned __int16, HBITMAP__))GFx_GFX_TagLoaderTable
            + (_DWORD)v6
            - 1000);
    }
    else
    {
      v14 = *((void (__thiscall **)(CUtlDict<ITextureInternal *,unsigned short> *, unsigned __int16, HBITMAP__))GFx_SWF_TagLoaderTable
            + (_DWORD)v6);
    }
    if ( v14 != nullptr )
    {
      v14(
        this: *(CUtlDict<ITextureInternal *,unsigned short> **)prenderer,
        prenderer: prenderer[0],
        ptext: (HBITMAP__)&pTagInfo);
      goto LABEL_25;
    }
    goto LABEL_24;
  }
LABEL_38:
  v20 = *(_DWORD *)(v7 + 760);
  if ( *(_DWORD *)(v7 + 12 * v20 + 772) == 0 && (v20 != 0 || *(_DWORD *)(v7 + 796) == 0) )
  {
    v18 = *((IMatRenderContextInternal **)this + 36);
    v19 = *((_DWORD *)this + 33);
    GMutex::Lock(this: v18 + 2);
    *((_DWORD *)this + 32) = 2;
    goto LABEL_44;
  }
  GFxMovieDataDef::LoadTaskData::FinishLoadingFrame(this, success: v7, finished: true);
  if ( v29 != nullptr )
    GFxMovieBindProcess::BindNextFrame(a1: (int)v29, a2: v6, a3: (unsigned int)v5);
}

//------------------------------------------------------------------------------
// Address: 0x100DAD70
// Name: public: GFxMovieDataDef::GFxMovieDataDef(class GFxResourceKey const __near &,enum GFxMovieDataDef::MovieDataType,char const __near *,class GMemoryHeap __near *,bool,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxMovieDataDef::GFxMovieDataDef(
        int this,
        struct GFxResourceKey *a2,
        int a3,
        int a4,
        int a5,
        char a6,
        int a7)
{
  int v8; // edi
  int v9; // ebx
  IMatRenderContext *ShortFilename; // eax
  GMemoryHeap *v11; // eax
  void *v12; // edi
  int (__thiscall *v13)(int, int, int *); // edx
  CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *v14; // eax
  int v15; // eax
  IShaderAPI *v16; // ecx
  _DWORD v18[8]; // [esp+Ch] [ebp-28h] BYREF
  int v19; // [esp+2Ch] [ebp-8h] BYREF
  int v20; // [esp+30h] [ebp-4h] BYREF

  *(_DWORD *)this = &GFxResource::`vftable';
  *(_DWORD *)(this + 4) = 1;
  v8 = 0;
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 12) = 0x40000;
  *(_DWORD *)(this + 16) = &GFxResourceReport::`vftable';
  *(_DWORD *)this = &GFxMovieDataDef::`vftable'{for `GFxTimelineDef'};
  *(_DWORD *)(this + 16) = &GFxMovieDataDef::`vftable'{for `GFxResourceReport'};
  GFxResourceKey::GFxResourceKey(this: (GFxResourceKey *)(this + 20), a2);
  v9 = a5;
  *(_DWORD *)(this + 28) = a3;
  *(_DWORD *)(this + 32) = 0;
  if ( a5 == 0 )
  {
    ShortFilename = G_GetShortFilename();
    GString::GString(
      this: (CUtlMemory<CImagePacker,int> *)&v20,
      pdata1: (int)"MovieData \"",
      pdata2: (int)ShortFilename);
    v18[0] = (a6 != 0 ? 0x1000 : 0) | 4;
    v18[7] = a7;
    v18[5] = 0;
    v18[3] = 0;
    v18[1] = 16;
    v18[4] = -1;
    v18[2] = 0x2000;
    v18[6] = 4;
    v11 = GMemory::pGlobalHeap->CreateHeap(this: GMemory::pGlobalHeap, a2: (v20 & 0xFFFFFFFC) + 8, a3: v18);
    v12 = (void *)(v20 & 0xFFFFFFFC);
    v9 = (int)v11;
    if ( InterlockedExchangeAdd(Addend: (volatile LONG *)((v20 & 0xFFFFFFFC) + 4), Value: -1) == 1 )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v12);
    v8 = 0;
  }
  v13 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v9 + 40);
  v19 = 265;
  v14 = (CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *)v13(a1: v9, a2: 288, a3: &v19);
  if ( v14 != nullptr )
  {
    GFxMovieDataDef::LoadTaskData::LoadTaskData(
      this: v14,
      pdataDef: (CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *)this,
      pdataDef_4: a4,
      pdataDef_8: v9);
    v8 = v15;
  }
  v16 = *(IShaderAPI **)(this + 32);
  if ( v16 != nullptr )
    GRefCountImpl::Release(this: v16);
  *(_DWORD *)(this + 32) = v8;
  if ( a5 == 0 )
    GMemoryHeap::ReleaseOnFree();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100DAEC0
// Name: public: virtual void GFxMovieDataDef::LoadTaskData::AddFrameName(class GString const __near &,class GFxLog __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::LoadTaskData::AddFrameName(
        CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *this,
        Frustum_t **name,
        int a3)
{
  _RTL_CRITICAL_SECTION *v4; // edi

  v4 = (_RTL_CRITICAL_SECTION *)(this + 11);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(this + 11));
  GStringHashLH<unsigned int,2,GString::NoCaseHashFunctor,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GHashsetCachedNodeEntry<GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeHashF>>::SetCaseInsensitive(
    this: (IVEngineClient *)this + 68,
    key: name,
    value: (int)this + 132);
  LeaveCriticalSection(lpCriticalSection: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100DAF00
// Name: public: void GFxMovieDataDef::LoadTaskData::ExportResource(class GString const __near &,class GFxResourceId,class GFxResourceHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieDataDef::LoadTaskData::ExportResource(
        GFxMovieDataDef::LoadTaskData *this,
        GPtr<GFxParseControl> *result,
        struct GFxResourceId a3,
        const struct GFxResourceHandle *a4)
{
  bool v5; // cc
  _DWORD v6[2]; // [esp+Ch] [ebp-14h] BYREF
  _DWORD v7[2]; // [esp+14h] [ebp-Ch] BYREF
  GFxMovieDataDef::LoadTaskData *v8; // [esp+1Ch] [ebp-4h]

  v5 = *((_DWORD *)this + 32) < 2;
  v8 = nullptr;
  if ( v5 )
  {
    v8 = this;
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)this + 184));
  }
  GStringHashLH<GFxResourceHandle,2,GString::NoCaseHashFunctor,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GHashsetCachedNodeEntry<GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeHashF>>::SetCaseInsensitive(result);
  a4 = (const struct GFxResourceHandle *)result;
  GHashSetBase<GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<GFxResourceHandle,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>,GStringLH_HashNode<GFxResourceHandle,GString::NoCaseHashFunctor>::NodeHashF>>::FindAlt<GString::NoCaseKey>(
    a1: v7,
    a2: &a4);
  v6[0] = &a3;
  v6[1] = *(_DWORD *)v7[0] + 20 * v7[1] + 16;
  GHashSetBase<GHashNode<GFxResourceId,GStringLH,GFixedSizeHash<GFxResourceId>>,GHashNode<GFxResourceId,GStringLH,GFixedSizeHash<GFxResourceId>>::NodeHashF,GHashNode<GFxResourceId,GStringLH,GFixedSizeHash<GFxResourceId>>::NodeAltHashF,GAllocatorLH<GFxResourceId,2>,GHashsetCachedNodeEntry<GHashNode<GFxResourceId,GStringLH,GFixedSizeHash<GFxResourceId>>,GHashNode<GFxResourceId,GStringLH,GFixedSizeHash<GFxResourceId>>::NodeHashF>>::Set<GHashNode<GFxResourceId,GStringLH,GFixedSizeHash<GFxResourceId>>::NodeRef>(
    a1: (char *)this + 216,
    a2: v6);
  if ( v8 != nullptr )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)v8 + 184));
}

//------------------------------------------------------------------------------
// Address: 0x100DAFA0
// Name: public: virtual void GFxMovieDefImpl::VisitImportedMovies(struct GFxMovieDef::ImportVisitor __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieDefImpl::VisitImportedMovies(
        CMatQueuedIndexBuffer *this@<ecx>,
        ButtonCode_t a2@<esi>,
        CMatQueuedRenderContext *visitor,
        IMatRenderContextInternal *visited)
{
  CMatQueuedIndexBuffer *v4; // ebx
  _DWORD *v5; // edi
  _RTL_CRITICAL_SECTION *v6; // esi
  MaterialIndexFormat_t m_nIndexFormat; // eax
  unsigned int v8; // ecx
  int v9; // ebx
  unsigned int v10; // eax
  int v11; // eax
  _DWORD *v13; // [esp+8h] [ebp-10h] BYREF
  CMatQueuedIndexBuffer *v14; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h] BYREF
  char v16; // [esp+17h] [ebp-1h] BYREF

  v4 = this;
  v5 = *(_DWORD **)(*(_DWORD *)(*(_DWORD *)(this->m_nIndexFormat + 12) + 32) + 156);
  v14 = this;
  if ( v5 != nullptr )
  {
    v15 = 0;
    while ( 1 )
    {
      v6 = (_RTL_CRITICAL_SECTION *)(v4->m_nIndexFormat + 80);
      EnterCriticalSection(lpCriticalSection: v6);
      m_nIndexFormat = v4->m_nIndexFormat;
      v8 = v5[5];
      if ( v8 >= *(_DWORD *)(m_nIndexFormat + 72) )
        break;
      v9 = *(_DWORD *)(*(_DWORD *)(m_nIndexFormat + 68) + 4 * v8);
      LeaveCriticalSection(lpCriticalSection: v6);
      v13 = v5 + 3;
      if ( v15 == 0
        || (v10 = (unsigned int)GString::BernsteinHashFunctionCIS(result: (const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((v5[3] & 0xFFFFFFFC) + 8)),
            (v11 = GHashSetBase<GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeHashF,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorLH<unsigned int,2>,GHashsetCachedNodeEntry<GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>,GStringLH_HashNode<unsigned int,GString::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<GString::NoCaseKey>(
                     a1: &v13,
                     a2: v10 & *(_DWORD *)(v15 + 4))) < 0)
        || v15 == 0
        || v11 > *(_DWORD *)(v15 + 4) )
      {
        if ( v9 != 0 )
          ((void (__thiscall *)(CMatQueuedRenderContext *, CMatQueuedIndexBuffer *, int, unsigned int))visitor->Release)(
            a1: visitor,
            a2: v14,
            a3: v9,
            a4: (v5[3] & 0xFFFFFFFC) + 8);
        v16 = 1;
        GStringHash<bool,GAllocatorGH<bool,2>>::SetCaseInsensitive(a1: v5 + 3, a2: &v16);
      }
      v5 = (_DWORD *)v5[6];
      if ( v5 == nullptr )
      {
        GHashSetBase<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<bool,2>,GHashsetCachedNodeEntry<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF>>::~GHashSetBase<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<bool,2>,GHashsetCachedNodeEntry<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF>>(
          this: (ScaleformUIImpl *)&v15,
          a2);
        return;
      }
      v4 = v14;
    }
    LeaveCriticalSection(lpCriticalSection: v6);
    GHashSetBase<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<bool,2>,GHashsetCachedNodeEntry<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF>>::~GHashSetBase<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeAltHashF,GAllocatorGH<bool,2>,GHashsetCachedNodeEntry<GHashNode<GString,bool,GString::NoCaseHashFunctor>,GHashNode<GString,bool,GString::NoCaseHashFunctor>::NodeHashF>>(
      this: (ScaleformUIImpl *)&v15,
      a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DDAD0
// Name: public: virtual void GFxShapeCharacterDef::SetRectBoundsLocal(class GRect<float> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeCharacterDef::SetRectBoundsLocal(
        old_bf_read *this,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *r,
        int a3,
        int a4,
        int a5)
{
  (*(void (__thiscall **)(bool *, CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *, int, int, int))(*(_DWORD *)&this->m_bOverflow + 8))(
    a1: &this->m_bOverflow,
    a2: r,
    a3,
    a4,
    a5);
}

//------------------------------------------------------------------------------
// Address: 0x1028BC90
// Name: _dynamic_initializer_for__GFxMovieDataDefFileKeyInterface_Instance__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__GFxMovieDataDefFileKeyInterface_Instance__()
{
  return atexit(func: (void (__cdecl *)())dynamic_atexit_destructor_for__GFxMovieDataDefFileKeyInterface_Instance__);
}

//------------------------------------------------------------------------------
// Address: 0x1028BCA0
// Name: _dynamic_initializer_for__GFxMovieDefImplKeyInterface_Instance__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__GFxMovieDefImplKeyInterface_Instance__()
{
  return atexit(func: (void (__cdecl *)())dynamic_atexit_destructor_for__GFxMovieDefImplKeyInterface_Instance__);
}

//------------------------------------------------------------------------------
// Address: 0x1028CAC0
// Name: _dynamic_atexit_destructor_for__GFxMovieDataDefFileKeyInterface_Instance__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__GFxMovieDataDefFileKeyInterface_Instance__()
{
  GFxMovieDataDefFileKeyInterface_Instance.__vftable = (GFxResourceKey::KeyInterface_vtbl *)&GFxResourceKey::KeyInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1028CAD0
// Name: _dynamic_atexit_destructor_for__GFxMovieDefImplKeyInterface_Instance__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void dynamic_atexit_destructor_for__GFxMovieDefImplKeyInterface_Instance__()
{
  GFxMovieDefImplKeyInterface_Instance.__vftable = (GFxResourceKey::KeyInterface_vtbl *)&GFxResourceKey::KeyInterface::`vftable';
}
