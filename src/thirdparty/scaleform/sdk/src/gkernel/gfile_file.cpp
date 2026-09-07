// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gfile_file.cpp
// Functions: 18
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gfile_file.h"

//------------------------------------------------------------------------------
// Address: 0x1007A910
// Name: public: virtual int GFILEFile::GetErrorCode(void)
// Source: json
//------------------------------------------------------------------------------
ImageFormat __thiscall GFILEFile::GetErrorCode(CVTFTexture *this)
{
  return this->m_Format;
}

//------------------------------------------------------------------------------
// Address: 0x100FAAD0
// Name: private: void GFILEFile::init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFILEFile::init(int this)
{
  int v2; // eax
  const char *v3; // ebx
  int Length; // eax
  wchar_t *v5; // edi
  _iobuf **v6; // ebx
  int v7; // eax
  bool v8; // zf
  const char *v10; // [esp-8h] [ebp-44h]
  int v11; // [esp+Ch] [ebp-30h] BYREF
  int v12; // [esp+10h] [ebp-2Ch]
  UINT uMode; // [esp+14h] [ebp-28h]
  CBitVecT<CFixedBitVecBase<32> > womode; // [esp+18h] [ebp-24h] BYREF

  v2 = *(_DWORD *)(this + 20);
  v3 = "rb";
  if ( (v2 & 4) != 0 )
  {
    if ( (v2 & 1) != 0 )
      v3 = "w+b";
    else
      v3 = "wb";
  }
  else if ( (v2 & 8) != 0 )
  {
    if ( (v2 & 1) != 0 )
      v3 = "a+b";
    else
      v3 = "ab";
  }
  else if ( (v2 & 2) != 0 )
  {
    v3 = "r+b";
  }
  if ( (*(_DWORD *)(this + 8) & 0xFFFFFFFC) != 0xFFFFFFF8
    && *(_BYTE *)((*(_DWORD *)(this + 8) & 0xFFFFFFFC) + 8) != 0
    && *(_BYTE *)((*(_DWORD *)(this + 8) & 0xFFFFFFFC) + 9) == 58 )
  {
    v12 = 1;
    uMode = SetErrorMode(uMode: 1u);
  }
  else
  {
    v12 = 0;
  }
  v10 = (const char *)((*(_DWORD *)(this + 8) & 0xFFFFFFFC) + 8);
  v11 = 2;
  Length = GUTF8Util::GetLength(length: v10, buflen: -1);
  v5 = (wchar_t *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 2 * Length + 2, a3: &v11);
  GUTF8Util::DecodeString(
    pbegin: v5,
    putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)((*(_DWORD *)(this + 8) & 0xFFFFFFFC) + 8),
    length: -1);
  GUTF8Util::DecodeString(
    pbegin: (wchar_t *)&womode,
    putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)v3,
    length: -1);
  v6 = (_iobuf **)(this + 16);
  _wfopen_s(pfile: (_iobuf **)(this + 16), file: v5, mode: (const wchar_t *)&womode);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
  if ( *(_DWORD *)(this + 16) != 0 )
    rewind(str: *v6);
  LOBYTE(v7) = *v6 != nullptr;
  *(_BYTE *)(this + 12) = v7;
  if ( (_BYTE)v7 != 0 )
  {
    *(_DWORD *)(this + 24) = 0;
  }
  else if ( *_errno() == 2 )
  {
    LOBYTE(v7) = 1;
    *(_DWORD *)(this + 24) = 4097;
  }
  else if ( *_errno() == 13 || *_errno() == 1 )
  {
    LOBYTE(v7) = 2;
    *(_DWORD *)(this + 24) = 4098;
  }
  else
  {
    v7 = (*_errno() == 28) + 4099;
    *(_DWORD *)(this + 24) = v7;
  }
  v8 = v12 == 0;
  *(_DWORD *)(this + 28) = 0;
  if ( !v8 )
    LOBYTE(v7) = SetErrorMode(uMode);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100FAC60
// Name: public: virtual bool GFILEFile::IsValid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFILEFile::IsValid(CBitVecT<CFixedBitVecBase<32> > *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100FAC70
// Name: public: virtual bool GFILEFile::IsWritable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFILEFile::IsWritable(CBitVecT<CFixedBitVecBase<32> > *this)
{
  (*(void (__thiscall **)(CBitVecT<CFixedBitVecBase<32> > *))(this->m_Ints[0] + 8))(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x100FAC90
// Name: public: virtual int GFILEFile::Tell(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFILEFile::Tell(_iobuf **this)
{
  int result; // eax
  int v3; // esi

  result = ftell(stream: *(this + 4));
  v3 = result;
  if ( result < 0 )
  {
    if ( *_errno() == 2 )
    {
      *(this + 6) = (_iobuf *)4097;
      return v3;
    }
    else if ( *_errno() == 13 || *_errno() == 1 )
    {
      *(this + 6) = (_iobuf *)4098;
      return v3;
    }
    else
    {
      *(this + 6) = (_iobuf *)((*_errno() == 28) + 4099);
      return v3;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FAD00
// Name: public: virtual __int64 GFILEFile::LTell(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFILEFile::LTell(CBitVecT<CFixedBitVecBase<32> > *this)
{
  if ( ftell(stream: *((_iobuf **)this + 4)) < 0 )
  {
    if ( *_errno() == 2 )
    {
      *((_DWORD *)this + 6) = 4097;
    }
    else if ( *_errno() == 13 || *_errno() == 1 )
    {
      *((_DWORD *)this + 6) = 4098;
    }
    else
    {
      *((_DWORD *)this + 6) = (*_errno() == 28) + 4099;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FAD70
// Name: public: virtual int GFILEFile::GetLength(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFILEFile::GetLength(GFILEFile *this)
{
  int v2; // edi
  int v3; // ebx

  v2 = (*(int (__thiscall **)(GFILEFile *))(*(_DWORD *)this + 16))(a1: this);
  if ( v2 < 0 )
    return -1;
  (*(void (__thiscall **)(GFILEFile *, _DWORD, int))(*(_DWORD *)this + 56))(a1: this, a2: 0, a3: 2);
  v3 = (*(int (__thiscall **)(GFILEFile *))(*(_DWORD *)this + 16))(a1: this);
  (*(void (__thiscall **)(GFILEFile *, int, _DWORD))(*(_DWORD *)this + 56))(a1: this, a2: v2, a3: 0);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100FADC0
// Name: public: virtual int GFILEFile::Write(unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFILEFile::Write(GFILEFile *this, const unsigned __int8 *buffer, int count)
{
  int v4; // eax
  signed int v5; // ebx
  _iobuf *v7; // [esp-4h] [ebp-10h]

  v4 = *((_DWORD *)this + 7);
  if ( v4 != 0 && v4 != 2 )
    fflush(stream: *((_iobuf **)this + 4));
  v7 = *((_iobuf **)this + 4);
  *((_DWORD *)this + 7) = 2;
  v5 = fwrite(buffer, size: 1u, count, stream: v7);
  if ( v5 < count )
  {
    if ( *_errno() == 2 )
    {
      *((_DWORD *)this + 6) = 4097;
      return v5;
    }
    if ( *_errno() != 13 && *_errno() != 1 )
    {
      *((_DWORD *)this + 6) = (*_errno() == 28) + 4099;
      return v5;
    }
    *((_DWORD *)this + 6) = 4098;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100FAE70
// Name: public: virtual int GFILEFile::Read(unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFILEFile::Read(
        CBitVecT<CFixedBitVecBase<32> > *this,
        CBitVecT<CFixedBitVecBase<32> > *pbuffer,
        int numBytes)
{
  _iobuf *v4; // [esp-4h] [ebp-10h]

  if ( *((_DWORD *)this + 7) >= 2u )
    fflush(stream: *((_iobuf **)this + 4));
  v4 = *((_iobuf **)this + 4);
  *((_DWORD *)this + 7) = 1;
  if ( (int)fread(buffer: pbuffer, elementSize: 1u, count: numBytes, stream: v4) < numBytes )
  {
    if ( *_errno() == 2 )
    {
      *((_DWORD *)this + 6) = 4097;
    }
    else if ( *_errno() == 13 || *_errno() == 1 )
    {
      *((_DWORD *)this + 6) = 4098;
    }
    else
    {
      *((_DWORD *)this + 6) = (*_errno() == 28) + 4099;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FAF20
// Name: public: virtual int GFILEFile::SkipBytes(int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GFILEFile::SkipBytes@<eax>(
        CBitVecT<CFixedBitVecBase<32> > *this@<ecx>,
        const CBitVecT<CFixedBitVecBase<32> > *numBytes,
        int a3)
{
  __int64 v4; // kr00_8
  int v5; // eax
  int v6; // edx

  v4 = ((__int64 (__thiscall *)(CBitVecT<CFixedBitVecBase<32> > *))*(_DWORD *)(this->m_Ints[0] + 20))(a1: this);
  v5 = (*(int (__thiscall **)(CBitVecT<CFixedBitVecBase<32> > *, const CBitVecT<CFixedBitVecBase<32> > *, int, int))(this->m_Ints[0] + 60))(
         a1: this,
         a2: numBytes,
         a3: (int)numBytes >> 31,
         a4: 1);
  if ( (HIDWORD(v4) & (unsigned int)v4) == 0xFFFFFFFF || (v6 & v5) == 0xFFFFFFFF )
    return -1;
  else
    return v5 - v4;
}

//------------------------------------------------------------------------------
// Address: 0x100FAF70
// Name: public: virtual int GFILEFile::BytesAvailable(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFILEFile::BytesAvailable(GFILEFile *this)
{
  __int64 v2; // kr00_8
  int v3; // eax
  int v4; // edx

  v2 = ((__int64 (__thiscall *)(GFILEFile *))*(_DWORD *)(*(_DWORD *)this + 20))(a1: this);
  v3 = (*(int (__thiscall **)(GFILEFile *))(*(_DWORD *)this + 28))(a1: this);
  if ( (HIDWORD(v2) & (unsigned int)v2) == 0xFFFFFFFF || (v4 & v3) == 0xFFFFFFFF )
  {
    if ( *_errno() == 2 )
    {
      *((_DWORD *)this + 6) = 4097;
      return 0;
    }
    else if ( *_errno() == 13 || *_errno() == 1 )
    {
      *((_DWORD *)this + 6) = 4098;
      return 0;
    }
    else
    {
      *((_DWORD *)this + 6) = (*_errno() == 28) + 4099;
      return 0;
    }
  }
  else
  {
    *((_DWORD *)this + 6) = 0;
    return v3 - v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FB000
// Name: public: virtual bool GFILEFile::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFILEFile::Flush(CBitVecT<CFixedBitVecBase<32> > *this)
{
  fflush(stream: *((_iobuf **)this + 4));
}

//------------------------------------------------------------------------------
// Address: 0x100FB020
// Name: public: virtual int GFILEFile::Seek(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFILEFile::Seek(CBitVecT<CFixedBitVecBase<32> > *this, int offset, int origin)
{
  int v3; // edi

  v3 = 0;
  if ( origin == 0 )
  {
    v3 = 0;
    goto LABEL_9;
  }
  if ( origin != 1 )
  {
    if ( origin == 2 )
    {
      v3 = 2;
      goto LABEL_5;
    }
LABEL_9:
    if ( offset == (*(int (__thiscall **)(CBitVecT<CFixedBitVecBase<32> > *))(this->m_Ints[0] + 16))(a1: this) )
      return (*(bool (__thiscall **)(CBitVecT<CFixedBitVecBase<32> > *))(this->m_Ints[0] + 16))(a1: this);
    goto LABEL_5;
  }
  v3 = 1;
LABEL_5:
  if ( fseek(stream: *((_iobuf **)this + 4), offset, whence: v3) != 0 )
    return -1;
  return (*(bool (__thiscall **)(CBitVecT<CFixedBitVecBase<32> > *))(this->m_Ints[0] + 16))(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x100FB090
// Name: public: virtual __int64 GFILEFile::LSeek(__int64,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFILEFile::LSeek(
        CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *this@<ecx>,
        int offset,
        int origin,
        int origina,
        bool (__cdecl *a5)(studiohwdata_t *const *, studiohwdata_t *const *),
        unsigned int (__cdecl *a6)(studiohwdata_t *const *))
{
  ((void (__thiscall *)(CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *, int, int))this->m_Buckets.m_Memory.m_pMemory[2].m_pElements)(
    a1: this,
    a2: offset,
    a3: origina);
}

//------------------------------------------------------------------------------
// Address: 0x100FB0B0
// Name: public: virtual bool GFILEFile::ChangeSize(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFILEFile::ChangeSize(CBitVecT<CFixedBitVecBase<32> > *this, unsigned int newSize)
{
  *((_DWORD *)this + 6) = 4099;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100FB160
// Name: public: virtual bool GFILEFile::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFILEFile::Close(CBitVecT<CFixedBitVecBase<32> > *this)
{
  if ( fclose(stream: *((_iobuf **)this + 4)) != 0 )
  {
    if ( *_errno() == 2 )
    {
      *((_DWORD *)this + 6) = 4097;
    }
    else if ( *_errno() == 13 || *_errno() == 1 )
    {
      *((_DWORD *)this + 6) = 4098;
    }
    else
    {
      *((_DWORD *)this + 6) = (*_errno() == 28) + 4099;
    }
  }
  else
  {
    *((_BYTE *)this + 12) = 0;
    *((_DWORD *)this + 4) = 0;
    *((_DWORD *)this + 6) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FB1E0
// Name: public: static bool GSysFile::GetFileStat(struct GFileStat __near *,class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
static char __cdecl GSysFile::GetFileStat(struct GFileStat *a1, const struct GString *a2)
{
  int Length; // eax
  wchar_t *v3; // esi
  int v4; // edi
  int st_atime; // eax
  int st_mtime; // edx
  int st_size; // ecx
  int st_mtime_high; // eax
  int st_size_high; // edx
  const char *v11; // [esp-8h] [ebp-54h]
  int v12; // [esp+Ch] [ebp-40h] BYREF
  _stat64 buf; // [esp+10h] [ebp-3Ch] BYREF

  v11 = (const char *)((a2->HeapTypeBits & 0xFFFFFFFC) + 8);
  v12 = 2;
  Length = GUTF8Util::GetLength(length: v11, buflen: -1);
  v3 = (wchar_t *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 2 * Length + 2, a3: &v12);
  GUTF8Util::DecodeString(
    pbegin: v3,
    putf8Buffer: (CUtlMap<char const *,int,unsigned short>::CKeyLess)((a2->HeapTypeBits & 0xFFFFFFFC) + 8),
    length: -1);
  v4 = _wstat64(name: v3, &buf);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
  if ( v4 != 0 )
    return 0;
  st_atime = buf.st_atime;
  st_mtime = buf.st_mtime;
  HIDWORD(a1->AccessTime) = HIDWORD(buf.st_atime);
  st_size = buf.st_size;
  LODWORD(a1->AccessTime) = st_atime;
  st_mtime_high = HIDWORD(buf.st_mtime);
  LODWORD(a1->FileSize) = st_size;
  LODWORD(a1->ModifyTime) = st_mtime;
  st_size_high = HIDWORD(buf.st_size);
  HIDWORD(a1->ModifyTime) = st_mtime_high;
  HIDWORD(a1->FileSize) = st_size_high;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FB310
// Name: class GFile __near * GFileFILEOpen(class GString const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
struct GFile *__cdecl GFileFILEOpen(CImagePacker *result, int flags)
{
  char *v2; // eax
  int v3; // esi
  int v5; // [esp+4h] [ebp-4h] BYREF

  v5 = 2;
  v2 = (char *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 32, a3: &v5);
  v3 = (int)v2;
  if ( v2 == nullptr )
    return nullptr;
  *(_DWORD *)v2 = &GRefCountImplCore::`vftable';
  *((_DWORD *)v2 + 1) = 1;
  *(_DWORD *)v2 = &GFILEFile::`vftable';
  GString::GString(this: (CCountedStringPoolBase<unsigned int> *)(v2 + 8), result);
  *(_DWORD *)(v3 + 20) = flags;
  GFILEFile::init(this: v3);
  return (struct GFile *)v3;
}
