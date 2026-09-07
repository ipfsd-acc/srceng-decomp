// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gzlibfile.cpp
// Functions: 21
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gzlibfile.h"

//------------------------------------------------------------------------------
// Address: 0x100F9E10
// Name: public: virtual bool GZLibFile::IsValid(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GZLibFile::IsValid(GZLibFile *this)
{
  return *((_DWORD *)this + 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F9E20
// Name: public: virtual int GZLibFile::Tell(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GZLibFile::Tell(_DWORD *this)
{
  int v1; // eax

  v1 = *(this + 2);
  if ( v1 != 0 )
    return *(_DWORD *)(v1 + 76);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100F9E30
// Name: public: virtual int GZLibFile::GetLength(void)
// Source: json
//------------------------------------------------------------------------------
CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *__thiscall GZLibFile::GetLength(
        _DWORD *this)
{
  int v2; // eax
  int v4; // edi
  int v5; // ebx

  v2 = *(this + 2);
  if ( v2 == 0 || *(_DWORD *)(v2 + 72) != 0 )
    return nullptr;
  v4 = *(_DWORD *)(v2 + 76);
  v5 = (*(int (__thiscall **)(_DWORD *, _DWORD, int))(*this + 56))(a1: this, a2: 0, a3: 2);
  (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*this + 56))(a1: this, a2: v4, a3: 0);
  return (CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x100F9E70
// Name: public: virtual __int64 GZLibFile::LGetLength(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GZLibFile::LGetLength(CBitVecT<CFixedBitVecBase<32> > *this)
{
  (*(void (__thiscall **)(CBitVecT<CFixedBitVecBase<32> > *))(this->m_Ints[0] + 24))(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x100F9E80
// Name: public: virtual int GZLibFile::GetErrorCode(void)
// Source: json
//------------------------------------------------------------------------------
CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *__thiscall GZLibFile::GetErrorCode(
        _DWORD *this)
{
  int v1; // eax

  v1 = *(this + 2);
  if ( v1 != 0 )
    return *(CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> **)(v1 + 72);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100F9E90
// Name: public: virtual int GZLibFile::SkipBytes(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GZLibFile::SkipBytes(
        CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *this,
        const CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *numBytes)
{
  ((void (__thiscall *)(CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *, const CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *, int))this->m_Buckets.m_Memory.m_pMemory[2].m_pElements)(
    a1: this,
    a2: numBytes,
    a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100F9EB0
// Name: public: virtual int GZLibFile::BytesAvailable(void)
// Source: json
//------------------------------------------------------------------------------
CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *__thiscall GZLibFile::BytesAvailable(
        _DWORD *this)
{
  int v2; // eax
  int v4; // edi
  int v5; // ebx

  v2 = *(this + 2);
  if ( v2 == 0 || *(_DWORD *)(v2 + 72) != 0 )
    return nullptr;
  v4 = *(_DWORD *)(v2 + 76);
  v5 = (*(int (__thiscall **)(_DWORD *, _DWORD, int))(*this + 56))(a1: this, a2: 0, a3: 2);
  (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*this + 56))(a1: this, a2: v4, a3: 0);
  return (CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *)(v5 - v4);
}

//------------------------------------------------------------------------------
// Address: 0x100F9EF0
// Name: ZLibAllocFunc
// Source: json
//------------------------------------------------------------------------------
void *__cdecl ZLibAllocFunc(const void *a1, int a2, int a3)
{
  int v4; // [esp+0h] [ebp-4h] BYREF

  v4 = 2;
  return GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: a1, a3: a3 * a2, a4: &v4);
}

//------------------------------------------------------------------------------
// Address: 0x100F9F20
// Name: ZLibFreeFunc
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ZLibFreeFunc(void *__formal, void *address, void *addressa)
{
  return ((bool (__thiscall *)(GMemoryHeap *, void *))GMemory::pGlobalHeap->Free)(
           a1: GMemory::pGlobalHeap,
           a2: addressa);
}

//------------------------------------------------------------------------------
// Address: 0x100F9F40
// Name: private: static int GZLibFile::ZLib_InitStream(struct z_stream_s __near *,void __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
mstudioaimconstraint_t *__cdecl GZLibFile::ZLib_InitStream(
        mstudioaimconstraint_t *result,
        void *pallocowner,
        void *pbuffer,
        float bufferSize)
{
  LODWORD(result->m_qAimOffset.x) = pallocowner;
  LODWORD(result->m_slave.m_vBasePosition.z) = pbuffer;
  result->m_nTargetCount = (int)ZLibAllocFunc;
  result->m_nTargetIndex = (int)ZLibFreeFunc;
  result->m_slave.m_nBone = 0;
  result->m_slave.m_vBasePosition.x = 0.0;
  result->m_slave.m_qBaseOrientation.x = bufferSize;
  result->m_qAimOffset.y = 0.0;
  result->m_qAimOffset.z = 0.0;
  result->m_qAimOffset.w = 0.0;
  return (mstudioaimconstraint_t *)inflateInit_(a1: result, a2: "1.2.3", a3: 56);
}

//------------------------------------------------------------------------------
// Address: 0x100F9F90
// Name: public: GZLibFileImpl::GZLibFileImpl(class GFile __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *__thiscall GZLibFileImpl::GZLibFileImpl(
        CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *this,
        IShaderDevice *a2)
{
  bool v3; // zf
  CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *result; // eax

  this->m_Buckets.m_Memory.m_pMemory = nullptr;
  if ( a2 != nullptr )
  {
    GRefCountImpl::AddRef(this: a2);
    if ( this->m_Buckets.m_Memory.m_pMemory != nullptr )
      GRefCountImpl::Release(this: (IShaderAPI *)this->m_Buckets.m_Memory.m_pMemory);
  }
  this->m_Buckets.m_Memory.m_pMemory = (CUtlVector<studiohwdata_t *,CUtlMemory<studiohwdata_t *,int> > *)a2;
  *((_DWORD *)this + 15) = a2->GetAspectRatioInfo(this: a2);
  *((_DWORD *)this + 16) = 0;
  *((_BYTE *)this + 68) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 9) = ZLibAllocFunc;
  *((_DWORD *)this + 10) = ZLibFreeFunc;
  *((_DWORD *)this + 11) = this;
  this->m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_Buckets.m_pElements = nullptr;
  this->m_CompareFunc = nullptr;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  v3 = inflateInit_(a1: &this->m_Buckets.m_Memory.m_nAllocationCount, a2: "1.2.3", a3: 56) == 0;
  result = this;
  if ( v3 )
  {
    *((_DWORD *)this + 21) = 0;
    *((_DWORD *)this + 20) = 0;
    *((_DWORD *)this + 19) = 0;
  }
  else
  {
    *((_DWORD *)this + 18) = 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FA030
// Name: public: void GZLibFileImpl::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GZLibFileImpl::Reset(
        CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *this)
{
  int *p_m_nAllocationCount; // edi
  CUtlVector<studiohwdata_t *,CUtlMemory<studiohwdata_t *,int> > *m_pMemory; // ecx
  int v4; // edx

  p_m_nAllocationCount = &this->m_Buckets.m_Memory.m_nAllocationCount;
  *((_DWORD *)this + 18) = 0;
  *((_BYTE *)this + 68) = 0;
  if ( inflateReset(a1: &this->m_Buckets.m_Memory.m_nAllocationCount) != 0 )
  {
    *((_DWORD *)this + 18) = 1;
  }
  else
  {
    m_pMemory = this->m_Buckets.m_Memory.m_pMemory;
    v4 = *((_DWORD *)this + 15);
    *p_m_nAllocationCount = 0;
    this->m_Buckets.m_Memory.m_nGrowSize = 0;
    this->m_Buckets.m_pElements = nullptr;
    this->m_CompareFunc = nullptr;
    (*((void (__thiscall **)(CUtlVector<studiohwdata_t *,CUtlMemory<studiohwdata_t *,int> > *, int, _DWORD))m_pMemory->m_Memory.m_pMemory
     + 14))(
      a1: m_pMemory,
      a2: v4,
      a3: 0);
    *((_DWORD *)this + 16) = 0;
    *((_DWORD *)this + 21) = 0;
    *((_DWORD *)this + 20) = 0;
    *((_DWORD *)this + 19) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FA090
// Name: public: int GZLibFileImpl::InflateFromStream(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GZLibFileImpl::InflateFromStream(
        CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *this,
        CUtlVector<studiohwdata_t *,CUtlMemory<studiohwdata_t *,int> > *dst,
        bool (__cdecl *bytes)(studiohwdata_t *const *, studiohwdata_t *const *))
{
  int result; // eax
  int v5; // eax
  int v6; // eax

  if ( *((_DWORD *)this + 18) != 0 )
    return 0;
  this->m_Buckets.m_pElements = dst;
  this->m_CompareFunc = bytes;
  while ( 1 )
  {
    if ( this->m_Buckets.m_Memory.m_nGrowSize == 0 )
    {
      v5 = (*((int (__stdcall **)(char *, int))this->m_Buckets.m_Memory.m_pMemory->m_Memory.m_pMemory + 10))(
             a1: (char *)this + 2136,
             a2: 4096);
      if ( v5 == 0 )
        goto LABEL_13;
      this->m_Buckets.m_Memory.m_nAllocationCount = (int)this + 2136;
      this->m_Buckets.m_Memory.m_nGrowSize = v5;
    }
    v6 = inflate(a1: &this->m_Buckets.m_Memory.m_nAllocationCount, a2: 2);
    if ( v6 == 1 )
    {
      result = (char *)bytes - (char *)this->m_CompareFunc;
      *((_DWORD *)this + 16) += result;
      *((_BYTE *)this + 68) = 1;
      return result;
    }
    if ( v6 != 0 )
      break;
    if ( this->m_CompareFunc == nullptr )
    {
      result = (char *)bytes - (char *)this->m_CompareFunc;
      *((_DWORD *)this + 16) += result;
      return result;
    }
  }
  *((_DWORD *)this + 18) = 1;
LABEL_13:
  result = (char *)bytes - (char *)this->m_CompareFunc;
  *((_DWORD *)this + 16) += result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FA130
// Name: public: virtual char const __near * GZLibFile::GetFilePath(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GZLibFile::GetFilePath(studiohwdata_t *const *this)
{
  _DWORD *v1; // eax

  v1 = *((_DWORD **)this + 2);
  if ( v1 != nullptr )
    return (*(unsigned int (__thiscall **)(_DWORD))(*(_DWORD *)*v1 + 4))(a1: *v1);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100FA150
// Name: public: virtual bool GZLibFile::Close(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GZLibFile::Close(GZLibFile *this)
{
  _DWORD *v2; // esi
  int v4; // eax
  int v5; // ebx
  IShaderAPI **v6; // esi

  v2 = *((_DWORD **)this + 2);
  if ( v2 == nullptr )
    return false;
  if ( v2[2] != 0 )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v2 + 16))(a1: *v2);
    (*(void (__thiscall **)(_DWORD, int, _DWORD))(*(_DWORD *)*v2 + 56))(a1: *v2, a2: v4 - v2[2], a3: 0);
  }
  v5 = inflateEnd(a1: *((_DWORD *)this + 2) + 4);
  (*(void (__thiscall **)(_DWORD))(***((_DWORD ***)this + 2) + 72))(a1: **((_DWORD **)this + 2));
  v6 = *((IShaderAPI ***)this + 2);
  if ( v6 != nullptr )
  {
    if ( *v6 != nullptr )
      GRefCountImpl::Release(this: *v6);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
  }
  *((_DWORD *)this + 2) = 0;
  return v5 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100FA1D0
// Name: public: int GZLibFileImpl::Inflate(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GZLibFileImpl::Inflate(
        CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *this,
        unsigned __int8 *dst,
        int copySize)
{
  int v4; // eax
  int v5; // ecx
  bool (__cdecl *v6)(studiohwdata_t *const *, studiohwdata_t *const *); // edi
  signed int v7; // ecx
  signed int v8; // edx
  int v9; // ebx
  signed int v10; // eax
  unsigned int v11; // edi
  unsigned __int8 *v12; // ebx
  int v13; // edi
  signed int v15; // eax
  int v16; // eax
  int v17; // eax
  int backtrackDataSave; // [esp+Ch] [ebp-Ch]
  int backtrackDataPos; // [esp+10h] [ebp-8h]
  int backtrackDataPosa; // [esp+10h] [ebp-8h]
  int backtrackData; // [esp+14h] [ebp-4h]
  int copySizea; // [esp+24h] [ebp+Ch]

  v4 = *((_DWORD *)this + 19);
  v5 = *((_DWORD *)this + 16);
  v6 = (bool (__cdecl *)(studiohwdata_t *const *, studiohwdata_t *const *))copySize;
  backtrackDataPos = 0;
  if ( v4 >= v5 )
  {
    v12 = dst;
  }
  else
  {
    v7 = v5 - v4;
    backtrackDataPosa = v7;
    if ( v7 <= copySize )
    {
      backtrackData = v7;
      v8 = v7;
    }
    else
    {
      v8 = copySize;
      backtrackData = copySize;
    }
    v9 = *((_DWORD *)this + 20);
    v10 = v8;
    backtrackDataSave = v8;
    if ( v7 <= v9 )
    {
      v12 = dst;
    }
    else
    {
      v11 = v7 - v9;
      if ( v7 - v9 > v8 )
        v11 = v8;
      memcpy(dst, src: (unsigned __int8 *)this + v9 + *((_DWORD *)this + 21) - v7 + 88, count: v11);
      backtrackData -= v11;
      v10 = backtrackDataSave;
      v8 = backtrackData;
      v7 = backtrackDataPosa - v11;
      v12 = &dst[v11];
      v6 = (bool (__cdecl *)(studiohwdata_t *const *, studiohwdata_t *const *))copySize;
    }
    if ( v8 > 0 )
    {
      memcpy(dst: v12, src: (unsigned __int8 *)this + *((_DWORD *)this + 20) - v7 + 88, count: v8);
      v10 = backtrackDataSave;
      v6 = (bool (__cdecl *)(studiohwdata_t *const *, studiohwdata_t *const *))copySize;
      v12 += backtrackData;
    }
    v6 = (bool (__cdecl *)(studiohwdata_t *const *, studiohwdata_t *const *))((char *)v6 - v10);
    *((_DWORD *)this + 19) += v10;
    backtrackDataPos = v10;
  }
  if ( (int)v6 <= 0 )
    return backtrackDataPos;
  v13 = GZLibFileImpl::InflateFromStream(
          this,
          dst: (CUtlVector<studiohwdata_t *,CUtlMemory<studiohwdata_t *,int> > *)v12,
          bytes: v6);
  if ( v13 < 2048 )
  {
    if ( v13 > 0 )
    {
      v15 = 2048 - *((_DWORD *)this + 20);
      if ( v15 >= v13 )
      {
        copySizea = v13;
        v15 = v13;
      }
      else
      {
        copySizea = 2048 - *((_DWORD *)this + 20);
      }
      if ( v15 > 0 )
      {
        memcpy(dst: (unsigned __int8 *)this + *((_DWORD *)this + 20) + 88, src: v12, count: v15);
        v15 = copySizea;
        v12 += copySizea;
        *((_DWORD *)this + 20) += copySizea;
      }
      if ( v13 > v15 )
      {
        *((_DWORD *)this + 20) = v13 - v15;
        memcpy(dst: (unsigned __int8 *)this + 88, src: v12, count: v13 - v15);
      }
      v16 = *((_DWORD *)this + 21);
      if ( v16 < 2048 )
      {
        v17 = v13 + v16;
        *((_DWORD *)this + 21) = v17;
        if ( v17 > 2048 )
          *((_DWORD *)this + 21) = 2048;
      }
    }
    *((_DWORD *)this + 19) = *((_DWORD *)this + 16);
    return v13 + backtrackDataPos;
  }
  else
  {
    *((_DWORD *)this + 20) = 2048;
    *((_DWORD *)this + 21) = 2048;
    memcpy(dst: (unsigned __int8 *)this + 88, src: &v12[v13 - 2048], count: 0x800u);
    *((_DWORD *)this + 19) = *((_DWORD *)this + 16);
    return v13 + backtrackDataPos;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FA360
// Name: public: int GZLibFileImpl::SetPosition(int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GZLibFileImpl::SetPosition@<eax>(
        CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *this@<ecx>,
        int offset,
        int temp)
{
  int v4; // eax
  int v6; // eax
  unsigned int dst[1024]; // [esp+8h] [ebp-1004h] BYREF

  v4 = *((_DWORD *)this + 16);
  if ( offset >= v4 )
  {
    if ( offset > v4 )
      *((_DWORD *)this + 19) = v4;
  }
  else
  {
    if ( offset >= v4 - *((_DWORD *)this + 21) )
    {
      *((_DWORD *)this + 19) = offset;
      return offset;
    }
    GZLibFileImpl::Reset(this);
  }
  if ( *((_DWORD *)this + 19) < offset )
  {
    do
    {
      v6 = offset - *((_DWORD *)this + 19);
      if ( v6 >= 4096 )
        v6 = 4096;
    }
    while ( GZLibFileImpl::Inflate(this, (unsigned __int8 *)dst, copySize: v6) != 0 && *((_DWORD *)this + 19) < offset );
  }
  return *((_DWORD *)this + 19);
}

//------------------------------------------------------------------------------
// Address: 0x100FA400
// Name: public: virtual GZLibFile::~GZLibFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GZLibFile::~GZLibFile(IShaderAPI *this)
{
  _DWORD *v2; // esi
  int v3; // eax
  IShaderAPI **v4; // esi

  v2 = *((_DWORD **)this + 2);
  this->__vftable = (IShaderAPI_vtbl *)&GZLibFile::`vftable';
  if ( v2 != nullptr )
  {
    if ( v2[2] != 0 )
    {
      v3 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v2 + 16))(a1: *v2);
      (*(void (__thiscall **)(_DWORD, int, _DWORD))(*(_DWORD *)*v2 + 56))(a1: *v2, a2: v3 - v2[2], a3: 0);
    }
    inflateEnd(a1: *((_DWORD *)this + 2) + 4);
    v4 = *((IShaderAPI ***)this + 2);
    if ( v4 != nullptr )
    {
      if ( *v4 != nullptr )
        GRefCountImpl::Release(this: *v4);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
    }
  }
  GRefCountImplCore::~GRefCountImplCore(this);
}

//------------------------------------------------------------------------------
// Address: 0x100FA470
// Name: public: virtual int GZLibFile::Read(unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GZLibFile::Read(GZLibFile *this, unsigned __int8 *a2, int a3)
{
  CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *v3; // ecx

  v3 = *((CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> **)this
       + 2);
  if ( v3 != nullptr )
    return GZLibFileImpl::Inflate(this: v3, dst: a2, copySize: a3);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100FA490
// Name: public: virtual int GZLibFile::Seek(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GZLibFile::Seek(GZLibFile *this, int offset, int a3)
{
  CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *v4; // ecx
  int v6; // [esp+0h] [ebp-4h]
  int v7; // [esp+0h] [ebp-4h]

  v4 = *((CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> **)this
       + 2);
  if ( v4 == nullptr )
    return -1;
  if ( v4[2].m_Buckets.m_Memory.m_pMemory != nullptr )
    return v4[2].m_Buckets.m_Memory.m_nAllocationCount;
  if ( a3 != 0 )
  {
    if ( a3 == 1 )
    {
      GZLibFileImpl::SetPosition(this: v4, offset: v4[2].m_Buckets.m_Memory.m_nAllocationCount + offset, temp: v6);
      return *(_DWORD *)(*((_DWORD *)this + 2) + 76);
    }
    if ( a3 == 2 )
    {
      GZLibFileImpl::SetPosition(this: v4, offset: 0x7FFFFFFF, temp: v6);
      if ( offset != 0 )
      {
        GZLibFileImpl::SetPosition(
          this: *((CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> **)this
          + 2),
          offset: *(_DWORD *)(*((_DWORD *)this + 2) + 76) + offset,
          temp: v7);
        return *(_DWORD *)(*((_DWORD *)this + 2) + 76);
      }
    }
  }
  else
  {
    GZLibFileImpl::SetPosition(this: v4, offset, temp: v6);
  }
  return *(_DWORD *)(*((_DWORD *)this + 2) + 76);
}

//------------------------------------------------------------------------------
// Address: 0x100FA520
// Name: public: GZLibFile::GZLibFile(class GFile __near *)
// Source: json
//------------------------------------------------------------------------------
GZLibFile *__thiscall GZLibFile::GZLibFile(GZLibFile *this, studiohwdata_t **psourceFile)
{
  CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *v3; // eax
  int v5; // [esp+8h] [ebp-4h] BYREF

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GZLibFile::`vftable';
  *((_DWORD *)this + 2) = 0;
  if ( psourceFile != nullptr
    && ((unsigned __int8 (__thiscall *)(studiohwdata_t **))(*psourceFile)->m_pLODs)(a1: psourceFile) != 0 )
  {
    v5 = 2;
    v3 = (CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 6232, a4: &v5);
    if ( v3 != nullptr )
    {
      *((_DWORD *)this + 2) = GZLibFileImpl::GZLibFileImpl(this: v3, a2: (IShaderDevice *)psourceFile);
      return this;
    }
    *((_DWORD *)this + 2) = 0;
  }
  return this;
}
