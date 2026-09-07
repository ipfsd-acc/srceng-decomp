// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/grenderer/gimageinfo.cpp
// Functions: 24
// ============================================================

#include "thirdparty\scaleform\sdk\src\grenderer\gimageinfo.h"

//------------------------------------------------------------------------------
// Address: 0x100727B0
// Name: public: virtual unsigned int GImageInfo::GetWidth(void)const
// Source: json
//------------------------------------------------------------------------------
tagEMRCREATEDIBPATTERNBRUSHPT *__thiscall GImageInfo::GetWidth(_DWORD *this)
{
  tagEMRCREATEDIBPATTERNBRUSHPT *v1; // eax
  int v2; // ecx

  v1 = (tagEMRCREATEDIBPATTERNBRUSHPT *)*(this + 6);
  if ( v1 == nullptr )
  {
    v2 = *(this + 5);
    if ( v2 != 0 )
      return *(tagEMRCREATEDIBPATTERNBRUSHPT **)(v2 + 12);
    else
      return nullptr;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100727D0
// Name: public: virtual unsigned int GImageInfo::GetHeight(void)const
// Source: json
//------------------------------------------------------------------------------
tagEMRCREATEDIBPATTERNBRUSHPT *__thiscall GImageInfo::GetHeight(_DWORD *this)
{
  tagEMRCREATEDIBPATTERNBRUSHPT *v1; // eax
  int v2; // ecx

  v1 = (tagEMRCREATEDIBPATTERNBRUSHPT *)*(this + 7);
  if ( v1 == nullptr )
  {
    v2 = *(this + 5);
    if ( v2 != 0 )
      return *(tagEMRCREATEDIBPATTERNBRUSHPT **)(v2 + 16);
    else
      return nullptr;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100727F0
// Name: public: virtual unsigned int GImageInfo::GetBytes(void)const
// Source: json
//------------------------------------------------------------------------------
tagEMRCREATEDIBPATTERNBRUSHPT *__thiscall GImageInfo::GetBytes(_DWORD *this)
{
  int v2; // esi

  if ( *(this + 5) == 0 )
    return nullptr;
  v2 = *(this + 5);
  return (tagEMRCREATEDIBPATTERNBRUSHPT *)(GImageBase::GetBytesPerPixel(a1: *(enum ImageFormat *)(v2 + 8))
                                         * *(_DWORD *)(v2 + 12)
                                         * *(_DWORD *)(v2 + 16));
}

//------------------------------------------------------------------------------
// Address: 0x10072820
// Name: public: virtual bool GImageInfo::Recreate(class GRenderer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GImageInfo::Recreate(GImageInfo *this, struct GRenderer *a2)
{
  volatile int RefCount; // ecx
  GTexture *pObject; // edx
  bool result; // al

  RefCount = this->RefCount;
  result = false;
  if ( RefCount != 0 )
  {
    pObject = this->pTexture.pObject;
    if ( pObject != nullptr
      && (*(unsigned __int8 (__thiscall **)(volatile int, GTexture *, GTexture::ChangeHandler_vtbl *))(*(_DWORD *)RefCount + 4))(
           a1: RefCount,
           a2: pObject + 1,
           a3: this->GImageInfoBaseImpl::GImageInfoBase::GTexture::ChangeHandler::__vftable) != 0 )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10072850
// Name: public: virtual class GRect<int> GImageInfoBase::GetRect(void)const
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GImageInfoBase::GetRect(void *this, _DWORD *a2)
{
  int v3; // edi
  int v4; // ecx

  v3 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 8))(a1: this);
  v4 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 4))(a1: this);
  a2[3] = v3;
  *a2 = 0;
  a2[1] = 0;
  a2[2] = v4;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100728A0
// Name: public: virtual unsigned int GSubImageInfo::GetWidth(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GSubImageInfo::GetWidth(GSubImageInfo *this)
{
  return this->pBaseImage.pObject->GetWidth(this: this->pBaseImage.pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100728B0
// Name: public: virtual unsigned int GSubImageInfo::GetHeight(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GSubImageInfo::GetHeight(GSubImageInfo *this)
{
  return this->pBaseImage.pObject->GetHeight(this: this->pBaseImage.pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100728C0
// Name: public: virtual unsigned int GSubImageInfo::GetBytes(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GSubImageInfo::GetBytes(GSubImageInfo *this)
{
  return this->pBaseImage.pObject->GetBytes(this: this->pBaseImage.pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100728D0
// Name: public: virtual unsigned int GSubImageInfo::GetExternalBytes(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GSubImageInfo::GetExternalBytes(GSubImageInfo *this)
{
  return this->pBaseImage.pObject->GetExternalBytes(this: this->pBaseImage.pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100728E0
// Name: public: virtual class GTexture __near * GSubImageInfo::GetTexture(class GRenderer __near *)
// Source: json
//------------------------------------------------------------------------------
CStackTop_CopyParentStack *__thiscall GSubImageInfo::GetTexture(_DWORD **this, CStackTop_CopyParentStack *result)
{
  return (*(CStackTop_CopyParentStack *(__thiscall **)(_DWORD, CStackTop_CopyParentStack *))(**(this + 3) + 20))(
           a1: *(this + 3),
           a2: result);
}

//------------------------------------------------------------------------------
// Address: 0x100728F0
// Name: public: virtual class GRect<int> GSubImageInfo::GetRect(void)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GSubImageInfo::GetRect(CStackTop_CopyParentStack *this@<ecx>, void **a2, int a3)
{
  void *v3; // edx
  void *v4; // ecx

  *a2 = (void *)this->m_iParentStackTraceLength;
  a2[1] = *((void **)this + 5);
  v3 = *((void **)this + 6);
  v4 = *((void **)this + 7);
  a2[2] = v3;
  a2[3] = v4;
}

//------------------------------------------------------------------------------
// Address: 0x10072920
// Name: public: virtual class GImageInfoBase __near * GImageInfoBase::CreateSubImage(class GRect<int> const __near &,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GImageInfoBase::CreateSubImage(_DWORD *this, int *a2, int a3)
{
  int (__thiscall *v4)(int, int, int *); // eax
  _DWORD *result; // eax
  int v6; // edx
  int v7; // [esp+4h] [ebp-14h]
  int v8; // [esp+8h] [ebp-10h]
  int v9; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h] BYREF

  v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)a3 + 40);
  v10 = 2;
  result = (_DWORD *)v4(a1: a3, a2: 32, a3: &v10);
  if ( result == nullptr )
    return nullptr;
  v7 = *a2;
  v8 = a2[1];
  v6 = a2[2];
  v9 = a2[3];
  *result = &GRefCountImplCore::`vftable';
  result[1] = 1;
  result[2] = &GTexture::ChangeHandler::`vftable';
  *result = &GSubImageInfo::`vftable'{for `GRefCountBaseNTS<GImageInfoBase,2>'};
  result[2] = &GSubImageInfo::`vftable'{for `GTexture::ChangeHandler'};
  if ( this != nullptr )
    ++*(this + 1);
  result[3] = this;
  result[4] = v7;
  result[5] = v8;
  result[6] = v6;
  result[7] = v9;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100729C0
// Name: public: virtual class GImageInfoBase __near * GSubImageInfo::CreateSubImage(class GRect<int> const __near &,class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GSubImageInfo::CreateSubImage(CStackTop_CopyParentStack *this, int rect, int rect_4)
{
  int v4; // ebx
  int v5; // edi
  int (__thiscall *v6)(int, int, int *); // eax
  _DWORD *v7; // eax
  int v8; // [esp+24h] [ebp-8h]
  int v9; // [esp+28h] [ebp-4h]

  v4 = *((_DWORD *)this + 5) + *(_DWORD *)(rect + 4);
  v5 = this->m_iParentStackTraceLength + *(_DWORD *)rect;
  v8 = *(_DWORD *)(rect + 8);
  v6 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)rect_4 + 40);
  v9 = *(_DWORD *)(rect + 12);
  rect = 2;
  v7 = (_DWORD *)v6(a1: rect_4, a2: 32, a3: &rect);
  if ( v7 != nullptr )
  {
    *v7 = &GRefCountImplCore::`vftable';
    v7[1] = 1;
    v7[2] = &GTexture::ChangeHandler::`vftable';
    *v7 = &GSubImageInfo::`vftable'{for `GRefCountBaseNTS<GImageInfoBase,2>'};
    v7[2] = &GSubImageInfo::`vftable'{for `GTexture::ChangeHandler'};
    ++this->m_pStackBase;
    v7[3] = this;
    v7[4] = v5;
    v7[5] = v4;
    v7[6] = v8;
    v7[7] = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072AB0
// Name: public: virtual GImageInfoBaseImpl::~GImageInfoBaseImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GImageInfoBaseImpl::~GImageInfoBaseImpl(IShaderAPI *this)
{
  int v2; // ecx
  int v3; // edi

  v2 = *((_DWORD *)this + 3);
  this->__vftable = (IShaderAPI_vtbl *)&GImageInfoBaseImpl::`vftable'{for `GRefCountBaseNTS<GImageInfoBase,2>'};
  *((_DWORD *)this + 2) = &GImageInfoBaseImpl::`vftable'{for `GTexture::ChangeHandler'};
  if ( v2 != 0 )
    (*(void (__thiscall **)(int, IShaderAPI *))(*(_DWORD *)v2 + 44))(a1: v2, a2: this + 2);
  v3 = *((_DWORD *)this + 3);
  if ( v3 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v3 + 4), Value: -1) == 1 )
    (**(void (__thiscall ***)(int, int))v3)(a1: v3, a2: 1);
  *((_DWORD *)this + 2) = &GTexture::ChangeHandler::`vftable';
  GRefCountImplCore::~GRefCountImplCore(this);
}

//------------------------------------------------------------------------------
// Address: 0x10072B10
// Name: public: virtual class GTexture __near * GImageInfoBaseImpl::GetTexture(class GRenderer __near *)
// Source: json
//------------------------------------------------------------------------------
struct GTexture *__thiscall GImageInfoBaseImpl::GetTexture(GImageInfoBaseImpl *this, struct GRenderer *a2)
{
  struct GTexture *result; // eax
  GTexture *v5; // eax
  GTexture *pObject; // esi
  GTexture *v7; // esi
  GTexture *v8; // [esp+Ch] [ebp+8h]

  result = this->pTexture.pObject;
  if ( result == nullptr )
  {
    v5 = a2->CreateTexture(this: a2);
    pObject = this->pTexture.pObject;
    v8 = v5;
    if ( pObject != nullptr && InterlockedExchangeAdd(Addend: &pObject->RefCount.Value, Value: -1) == 1 )
      ((void (__thiscall *)(GTexture *, int))pObject->dtr_GTexture)(a1: pObject, a2: 1);
    this->pTexture.pObject = v8;
    if ( v8 != nullptr )
    {
      if ( this->Recreate(this: &this->GTexture::ChangeHandler, a2) )
      {
        this->pTexture.pObject->AddChangeHandler(this: this->pTexture.pObject, a2: &this->GTexture::ChangeHandler);
        return this->pTexture.pObject;
      }
      v7 = this->pTexture.pObject;
      if ( v7 != nullptr && InterlockedExchangeAdd(Addend: &v7->RefCount.Value, Value: -1) == 1 )
        ((void (__thiscall *)(GTexture *, int))v7->dtr_GTexture)(a1: v7, a2: 1);
      this->pTexture.pObject = nullptr;
    }
    return this->pTexture.pObject;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10072BC0
// Name: public: virtual void GImageInfoBaseImpl::OnChange(class GRenderer __near *,enum GTexture::ChangeHandler::EventType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GImageInfoBaseImpl::OnChange(
        GImageInfoBaseImpl *this,
        struct GRenderer *a2,
        enum GTexture::ChangeHandler::EventType a3)
{
  volatile int RefCount; // ecx
  volatile int v5; // edi

  RefCount = this->RefCount;
  if ( RefCount != 0 && a3 == 2 )
  {
    (*(void (__thiscall **)(volatile int, GImageInfoBaseImpl *))(*(_DWORD *)RefCount + 44))(
      a1: RefCount,
      a2: this != (GImageInfoBaseImpl *)8 ? this : nullptr);
    v5 = this->RefCount;
    if ( v5 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v5 + 4), Value: -1) == 1 )
      (**(void (__thiscall ***)(volatile int, int))v5)(a1: v5, a2: 1);
    this->RefCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072C20
// Name: public: GImageInfo::GImageInfo(class GImage __near *,bool)
// Source: json
//------------------------------------------------------------------------------
GImageInfo *__thiscall GImageInfo::GImageInfo(GImageInfo *this, struct GImage *a2, bool a3)
{
  unsigned int v4; // edi

  this->GImageInfoBaseImpl::GImageInfoBase::GRefCountBaseNTS<GImageInfoBase,2>::GRefCountBaseStatImpl<GRefCountNTSImpl,2>::GRefCountNTSImpl::GRefCountImplCore::__vftable = (GImageInfo_vtbl *)&GRefCountImplCore::`vftable';
  this->RefCount = 1;
  this->GImageInfoBaseImpl::GImageInfoBase::GTexture::ChangeHandler::__vftable = (GTexture::ChangeHandler_vtbl *)&GTexture::ChangeHandler::`vftable';
  this->pTexture.pObject = nullptr;
  this->GImageInfoBaseImpl::GImageInfoBase::GRefCountBaseNTS<GImageInfoBase,2>::GRefCountBaseStatImpl<GRefCountNTSImpl,2>::GRefCountNTSImpl::GRefCountImplCore::__vftable = (GImageInfo_vtbl *)&GImageInfo::`vftable'{for `GRefCountBaseNTS<GImageInfoBase,2>'};
  this->GImageInfoBaseImpl::GImageInfoBase::GTexture::ChangeHandler::__vftable = (GTexture::ChangeHandler_vtbl *)&GImageInfo::`vftable'{for `GTexture::ChangeHandler'};
  if ( a2 != nullptr )
    ++a2->RefCount;
  this->pImage.pObject = a2;
  this->TargetWidth = 0;
  this->TargetHeight = 0;
  this->ReleaseImage = a3;
  this->TextureUsage = 1;
  if ( (_S1_3 & 1) == 0 )
  {
    _S1_3 |= 1u;
    GLock::GLock(lpCriticalSection: &CriticalSection, spinCount: 0);
    atexit(func: (void (__cdecl *)())GImageInfo::GetNextImageId_::_2_::_dynamic_atexit_destructor_for__staticLock__);
  }
  EnterCriticalSection(lpCriticalSection: &CriticalSection);
  v4 = ++dword_103593BC;
  LeaveCriticalSection(lpCriticalSection: &CriticalSection);
  this->ImageId = v4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10072CE0
// Name: public: GImageInfo::GImageInfo(class GImage __near *,unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
GImageInfo *__thiscall GImageInfo::GImageInfo(
        GImageInfo *this,
        struct GImage *a2,
        unsigned int a3,
        unsigned int a4,
        bool a5)
{
  unsigned int v6; // edi

  this->GImageInfoBaseImpl::GImageInfoBase::GRefCountBaseNTS<GImageInfoBase,2>::GRefCountBaseStatImpl<GRefCountNTSImpl,2>::GRefCountNTSImpl::GRefCountImplCore::__vftable = (GImageInfo_vtbl *)&GRefCountImplCore::`vftable';
  this->RefCount = 1;
  this->GImageInfoBaseImpl::GImageInfoBase::GTexture::ChangeHandler::__vftable = (GTexture::ChangeHandler_vtbl *)&GTexture::ChangeHandler::`vftable';
  this->pTexture.pObject = nullptr;
  this->GImageInfoBaseImpl::GImageInfoBase::GRefCountBaseNTS<GImageInfoBase,2>::GRefCountBaseStatImpl<GRefCountNTSImpl,2>::GRefCountNTSImpl::GRefCountImplCore::__vftable = (GImageInfo_vtbl *)&GImageInfo::`vftable'{for `GRefCountBaseNTS<GImageInfoBase,2>'};
  this->GImageInfoBaseImpl::GImageInfoBase::GTexture::ChangeHandler::__vftable = (GTexture::ChangeHandler_vtbl *)&GImageInfo::`vftable'{for `GTexture::ChangeHandler'};
  if ( a2 != nullptr )
    ++a2->RefCount;
  this->pImage.pObject = a2;
  this->TargetWidth = a3;
  this->TargetHeight = a4;
  this->ReleaseImage = a5;
  this->TextureUsage = 1;
  if ( (_S1_3 & 1) == 0 )
  {
    _S1_3 |= 1u;
    GLock::GLock(lpCriticalSection: &CriticalSection, spinCount: 0);
    atexit(func: (void (__cdecl *)())GImageInfo::GetNextImageId_::_2_::_dynamic_atexit_destructor_for__staticLock__);
  }
  EnterCriticalSection(lpCriticalSection: &CriticalSection);
  v6 = ++dword_103593BC;
  LeaveCriticalSection(lpCriticalSection: &CriticalSection);
  this->ImageId = v6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10072D90
// Name: public: GImageInfo::GImageInfo(class GTexture __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GImageInfo *__thiscall GImageInfo::GImageInfo(GImageInfo *this, struct GTexture *a2, unsigned int a3, unsigned int a4)
{
  GTexture::ChangeHandler *v5; // edi
  unsigned int v6; // edi

  this->GImageInfoBaseImpl::GImageInfoBase::GRefCountBaseNTS<GImageInfoBase,2>::GRefCountBaseStatImpl<GRefCountNTSImpl,2>::GRefCountNTSImpl::GRefCountImplCore::__vftable = (GImageInfo_vtbl *)&GRefCountImplCore::`vftable';
  v5 = &this->GTexture::ChangeHandler;
  this->RefCount = 1;
  this->GImageInfoBaseImpl::GImageInfoBase::GTexture::ChangeHandler::__vftable = (GTexture::ChangeHandler_vtbl *)&GTexture::ChangeHandler::`vftable';
  this->GImageInfoBaseImpl::GImageInfoBase::GRefCountBaseNTS<GImageInfoBase,2>::GRefCountBaseStatImpl<GRefCountNTSImpl,2>::GRefCountNTSImpl::GRefCountImplCore::__vftable = (GImageInfo_vtbl *)&GImageInfoBaseImpl::`vftable'{for `GRefCountBaseNTS<GImageInfoBase,2>'};
  this->GImageInfoBaseImpl::GImageInfoBase::GTexture::ChangeHandler::__vftable = (GTexture::ChangeHandler_vtbl *)&GImageInfoBaseImpl::`vftable'{for `GTexture::ChangeHandler'};
  if ( a2 != nullptr )
    InterlockedExchangeAdd(Addend: &a2->RefCount.Value, Value: 1);
  this->pTexture.pObject = a2;
  if ( a2 != nullptr )
    a2->AddChangeHandler(this: a2, a2: v5);
  this->TextureUsage = 1;
  this->GImageInfoBaseImpl::GImageInfoBase::GRefCountBaseNTS<GImageInfoBase,2>::GRefCountBaseStatImpl<GRefCountNTSImpl,2>::GRefCountNTSImpl::GRefCountImplCore::__vftable = (GImageInfo_vtbl *)&GImageInfo::`vftable'{for `GRefCountBaseNTS<GImageInfoBase,2>'};
  v5->__vftable = (GTexture::ChangeHandler_vtbl *)&GImageInfo::`vftable'{for `GTexture::ChangeHandler'};
  this->pImage.pObject = nullptr;
  this->TargetWidth = a3;
  this->TargetHeight = a4;
  this->ReleaseImage = false;
  if ( (_S1_3 & 1) == 0 )
  {
    _S1_3 |= 1u;
    GLock::GLock(lpCriticalSection: &CriticalSection, spinCount: 0);
    atexit(func: (void (__cdecl *)())GImageInfo::GetNextImageId_::_2_::_dynamic_atexit_destructor_for__staticLock__);
  }
  EnterCriticalSection(lpCriticalSection: &CriticalSection);
  v6 = ++dword_103593BC;
  LeaveCriticalSection(lpCriticalSection: &CriticalSection);
  this->ImageId = v6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10072E60
// Name: public: void GImageInfo::SetTextureUsage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GImageInfo::SetTextureUsage(int this, _IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY *result)
{
  int v3; // ecx
  int v4; // edi

  if ( result != *(_IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY **)(this + 16) )
  {
    v3 = *(_DWORD *)(this + 12);
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 44))(a1: v3, a2: this + 8);
      v4 = *(_DWORD *)(this + 12);
      if ( v4 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v4 + 4), Value: -1) == 1 )
        (**(void (__thiscall ***)(int, int))v4)(a1: v4, a2: 1);
      *(_DWORD *)(this + 12) = 0;
    }
  }
  *(_DWORD *)(this + 16) = result;
}

//------------------------------------------------------------------------------
// Address: 0x10072EC0
// Name: public: virtual class GTexture __near * GImageInfo::GetTexture(class GRenderer __near *)
// Source: json
//------------------------------------------------------------------------------
_CREATE_THREAD_DEBUG_INFO *__thiscall GImageInfo::GetTexture(int this, _CREATE_THREAD_DEBUG_INFO *result)
{
  _CREATE_THREAD_DEBUG_INFO *v3; // eax
  int v5; // eax
  int v6; // edi
  int v7; // edi
  GRefCountNTSImpl *v8; // ecx
  _CREATE_THREAD_DEBUG_INFO *v9; // [esp+Ch] [ebp+8h]

  v3 = *(_CREATE_THREAD_DEBUG_INFO **)(this + 12);
  if ( v3 == nullptr && *(_DWORD *)(this + 20) != 0 )
  {
    v5 = (*((int (__thiscall **)(_CREATE_THREAD_DEBUG_INFO *))result->hThread + 2))(a1: result);
    v6 = *(_DWORD *)(this + 12);
    v9 = (_CREATE_THREAD_DEBUG_INFO *)v5;
    if ( v6 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v6 + 4), Value: -1) == 1 )
      (**(void (__thiscall ***)(int, int))v6)(a1: v6, a2: 1);
    *(_DWORD *)(this + 12) = v9;
    if ( v9 != nullptr )
    {
      if ( (*(unsigned __int8 (__thiscall **)(int, _CREATE_THREAD_DEBUG_INFO *))(*(_DWORD *)(this + 8) + 8))(
             a1: this + 8,
             a2: result) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(this + 12) + 40))(a1: *(_DWORD *)(this + 12), a2: this + 8);
      }
      else
      {
        v7 = *(_DWORD *)(this + 12);
        if ( v7 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v7 + 4), Value: -1) == 1 )
          (**(void (__thiscall ***)(int, int))v7)(a1: v7, a2: 1);
        *(_DWORD *)(this + 12) = 0;
      }
    }
    if ( *(_DWORD *)(this + 12) != 0 && *(_BYTE *)(this + 32) != 0 )
    {
      v8 = *(GRefCountNTSImpl **)(this + 20);
      if ( v8 != nullptr )
        GRefCountNTSImpl::Release(this: v8);
      *(_DWORD *)(this + 20) = 0;
    }
    return *(_CREATE_THREAD_DEBUG_INFO **)(this + 12);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10072F90
// Name: public: virtual void GImageInfo::OnChange(class GRenderer __near *,enum GTexture::ChangeHandler::EventType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GImageInfo::OnChange(
        GImageInfo *this,
        struct GRenderer *a2,
        enum GTexture::ChangeHandler::EventType a3)
{
  volatile int RefCount; // ecx
  volatile int v5; // edi
  volatile int v6; // ecx
  volatile int v7; // edi

  RefCount = this->RefCount;
  if ( RefCount != 0 && a3 == 2 )
  {
    (*(void (__thiscall **)(volatile int, GImageInfo *))(*(_DWORD *)RefCount + 44))(
      a1: RefCount,
      a2: this != (GImageInfo *)8 ? this : nullptr);
    v5 = this->RefCount;
    if ( v5 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v5 + 4), Value: -1) == 1 )
      (**(void (__thiscall ***)(volatile int, int))v5)(a1: v5, a2: 1);
    this->RefCount = 0;
  }
  v6 = this->RefCount;
  if ( v6 != 0 && a3 == Event_DataLost && this->pTexture.pObject == nullptr )
  {
    (*(void (__thiscall **)(volatile int, GImageInfo *))(*(_DWORD *)v6 + 44))(
      a1: v6,
      a2: this != (GImageInfo *)8 ? this : nullptr);
    v7 = this->RefCount;
    if ( v7 != 0 && InterlockedExchangeAdd(Addend: (volatile LONG *)(v7 + 4), Value: -1) == 1 )
      (**(void (__thiscall ***)(volatile int, int))v7)(a1: v7, a2: 1);
    this->RefCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10184710
// Name: public: virtual class GImageInfoBase __near * GSubImageInfo::GetBaseImage(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GSubImageInfo::GetBaseImage(CVTFTexture *this)
{
  return this->m_nWidth;
}

//------------------------------------------------------------------------------
// Address: 0x1028CA80
// Name: _GImageInfo::GetNextImageId_::_2_::_dynamic_atexit_destructor_for__staticLock__
// Source: json
//------------------------------------------------------------------------------
void GImageInfo::GetNextImageId_::_2_::_dynamic_atexit_destructor_for__staticLock__()
{
  GLock::~GLock(lpCriticalSection: &CriticalSection);
}
