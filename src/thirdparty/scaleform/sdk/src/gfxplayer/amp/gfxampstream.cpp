// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/amp/gfxampstream.cpp
// Functions: 23
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\amp\gfxampstream.h"

//------------------------------------------------------------------------------
// Address: 0x1007E720
// Name: public: virtual __int64 GFxAmpStream::LSeek(__int64,int)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall GFxAmpStream::LSeek(GFxAmpStream *this, __int64 a2, int offset_4)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101845B0
// Name: public: virtual int GFxAmpStream::SkipBytes(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxAmpStream::SkipBytes(GFxAmpStream *this, int a2)
{
  *((_DWORD *)this + 5) += a2;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x101845C0
// Name: public: virtual int GFxAmpStream::CopyFromStream(class GFile __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpStream::CopyFromStream(
        MaterialSystem_Config_t *this,
        MaterialSystem_Config_t *pbuffer,
        bool numBytes)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x101845D0
// Name: public: void GFxAmpStream::ReadString(class GString __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpStream::ReadString(GFxAmpStream *this, struct GString *a2)
{
  struct GString *v2; // edi
  void (__thiscall *v4)(GFxAmpStream *, struct GString **, int); // edx
  struct GString *i; // ebx
  void (__thiscall *v6)(GFxAmpStream *, char *, int); // edx

  v2 = a2;
  GString::Clear(this: a2);
  v4 = *(void (__thiscall **)(GFxAmpStream *, struct GString **, int))(*(_DWORD *)this + 40);
  a2 = nullptr;
  v4(a1: this, &a2, a3: 4);
  for ( i = a2; i != nullptr; i = (struct GString *)((char *)i - 1) )
  {
    v6 = *(void (__thiscall **)(GFxAmpStream *, char *, int))(*(_DWORD *)this + 40);
    HIBYTE(a2) = 0;
    v6(a1: this, a2: (char *)&a2 + 3, a3: 1);
    GString::AppendChar(this: (unsigned int *)v2, result: (CImagePacker *)SHIBYTE(a2));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10184630
// Name: public: void GFxAmpStream::WriteString(class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpStream::WriteString(GFxAmpStream *this, struct GString *Length)
{
  struct GString *v2; // ebx
  unsigned int i; // esi
  void (__thiscall *v5)(GFxAmpStream *, struct GString **, int); // edx

  v2 = Length;
  Length = (struct GString *)GString::GetLength(this: Length);
  (*(void (__thiscall **)(GFxAmpStream *, struct GString **, int))(*(_DWORD *)this + 36))(a1: this, a2: &Length, a3: 4);
  for ( i = 0; i < GString::GetLength(this: v2); ++i )
  {
    v5 = *(void (__thiscall **)(GFxAmpStream *, struct GString **, int))(*(_DWORD *)this + 36);
    LOBYTE(Length) = *(_BYTE *)((v2->HeapTypeBits & 0xFFFFFFFC) + i + 8);
    v5(a1: this, a2: &Length, a3: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10184690
// Name: public: void GFxAmpStream::Rewind(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpStream::Rewind(GFxAmpStream *this)
{
  *((_DWORD *)this + 5) = 4;
}

//------------------------------------------------------------------------------
// Address: 0x101846A0
// Name: public: unsigned int GFxAmpStream::FirstMessageSize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxAmpStream::FirstMessageSize(GFxAmpStream *this)
{
  int v2; // edi
  unsigned int result; // eax
  unsigned int v4; // [esp+8h] [ebp-4h] BYREF

  v2 = *((_DWORD *)this + 5);
  *((_DWORD *)this + 5) = 0;
  v4 = 0;
  (*(void (__thiscall **)(GFxAmpStream *, unsigned int *, int))(*(_DWORD *)this + 40))(a1: this, a2: &v4, a3: 4);
  result = v4;
  *((_DWORD *)this + 5) = v2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101846D0
// Name: public: virtual int GFxAmpStream::BytesAvailable(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxAmpStream::BytesAvailable(GFxAmpStream *this)
{
  return *((_DWORD *)this + 3) - *((_DWORD *)this + 5);
}

//------------------------------------------------------------------------------
// Address: 0x101846E0
// Name: public: virtual int GFxAmpStream::Read(unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxAmpStream::Read(GFxAmpStream *this, unsigned __int8 *dst, unsigned int count)
{
  memcpy(dst, src: (unsigned __int8 *)(*((_DWORD *)this + 5) + *((_DWORD *)this + 2)), count);
  *((_DWORD *)this + 5) += count;
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x10184820
// Name: public: GFxAmpStream::GFxAmpStream(void)
// Source: json
//------------------------------------------------------------------------------
GFxAmpStream *__thiscall GFxAmpStream::GFxAmpStream(GFxAmpStream *this)
{
  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxAmpStream::`vftable';
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10184850
// Name: public: virtual __int64 GFxAmpStream::LTell(void)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall GFxAmpStream::LTell(GFxAmpStream *this)
{
  return (*(int (__thiscall **)(GFxAmpStream *))(*(_DWORD *)this + 16))(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x10184860
// Name: public: void GFxAmpStream::Append(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxAmpStream::Append(GFxAmpStream *this, unsigned __int8 *a2, unsigned int a3)
{
  GArrayData<unsigned char,GAllocatorLH<unsigned char,2>,GArrayConstPolicy<0,4,1>>::Append(
    this: (unsigned int *)this + 2,
    a2,
    a3);
  *((_DWORD *)this + 5) = 4;
}

//------------------------------------------------------------------------------
// Address: 0x10184890
// Name: public: bool GFxAmpStream::PopFirstMessage(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxAmpStream::PopFirstMessage(GFxAmpStream *this)
{
  int v2; // edi
  unsigned int v3; // eax
  unsigned int v4; // ecx
  unsigned int v5; // edx
  unsigned int v7; // ecx
  unsigned int v8; // ebx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v2 = *((_DWORD *)this + 5);
  *((_DWORD *)this + 5) = 0;
  v9 = 0;
  (*(void (__thiscall **)(GFxAmpStream *, unsigned int *, int))(*(_DWORD *)this + 40))(a1: this, a2: &v9, a3: 4);
  v3 = v9;
  v4 = *((_DWORD *)this + 3);
  *((_DWORD *)this + 5) = v2;
  v5 = v3;
  if ( v3 > v4 )
    return 0;
  for ( ; v3 < v4; ++v3 )
    *(_BYTE *)(*((_DWORD *)this + 2) - v5 + v3) = *(_BYTE *)(*((_DWORD *)this + 2) + v3);
  v7 = v4 - v5;
  v8 = v7;
  if ( v7 >= *((_DWORD *)this + 3) )
  {
    if ( v7 >= *((_DWORD *)this + 4) )
      GArrayDataBase<unsigned char,GAllocatorLH<unsigned char,2>,GArrayConstPolicy<0,4,1>>::Reserve(
        this: (void **)this + 2,
        a2: (char *)this + 8,
        a3: v7 + (v7 >> 2));
  }
  else if ( v7 < *((_DWORD *)this + 4) >> 1 )
  {
    GArrayDataBase<unsigned char,GAllocatorLH<unsigned char,2>,GArrayConstPolicy<0,4,1>>::Reserve(
      this: (void **)this + 2,
      a2: (char *)this + 8,
      a3: v7);
  }
  *((_DWORD *)this + 3) = v8;
  *((_DWORD *)this + 5) = 4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10184930
// Name: public: GFxAmpStream::GFxAmpStream(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxAmpStream *__thiscall GFxAmpStream::GFxAmpStream(GFxAmpStream *this, unsigned __int8 *a2, unsigned int a3)
{
  unsigned int *v4; // ecx

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  v4 = (unsigned int *)((char *)this + 8);
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxAmpStream::`vftable';
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  *((_DWORD *)this + 5) = 0;
  GArrayData<unsigned char,GAllocatorLH<unsigned char,2>,GArrayConstPolicy<0,4,1>>::Append(this: v4, a2, a3);
  *((_DWORD *)this + 5) = 4;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10184980
// Name: public: virtual int GFxAmpStream::Write(unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxAmpStream::Write(GFxAmpStream *this, unsigned __int8 *src, unsigned int count)
{
  int v3; // edi
  unsigned int v4; // edi
  void **v5; // esi
  GFxAmpStream *v7; // [esp+Ch] [ebp-4h]

  v3 = *((_DWORD *)this + 3);
  v7 = this;
  if ( v3 != 0 )
    v4 = count + v3;
  else
    v4 = count + 4;
  v5 = (void **)((char *)this + 8);
  if ( v4 >= *((_DWORD *)this + 3) )
  {
    if ( v4 >= *((_DWORD *)this + 4) )
    {
      GArrayDataBase<unsigned char,GAllocatorLH<unsigned char,2>,GArrayConstPolicy<0,4,1>>::Reserve(
        this: v5,
        a2: v5,
        a3: v4 + (v4 >> 2));
      goto LABEL_9;
    }
  }
  else if ( v4 < *((_DWORD *)this + 4) >> 1 )
  {
    GArrayDataBase<unsigned char,GAllocatorLH<unsigned char,2>,GArrayConstPolicy<0,4,1>>::Reserve(
      this: v5,
      a2: v5,
      a3: v4);
LABEL_9:
    this = v7;
  }
  v5[1] = (void *)v4;
  *(_DWORD *)*v5 = v4;
  memcpy(dst: (unsigned __int8 *)*v5 + *((_DWORD *)this + 3) - count, src, count);
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x101DDECC
// Name: public: virtual unsigned long D3DXCore::CBuffer::GetBufferSize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall D3DXCore::CBuffer::GetBufferSize(D3DXCore::CBuffer *this)
{
  return *((_DWORD *)this + 2);
}

//------------------------------------------------------------------------------
// Address: 0x101DDEFC
// Name: public: virtual long D3DXCore::CBuffer::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXCore::CBuffer::QueryInterface(D3DXCore::CBuffer *this, const struct _GUID *a2, void **a3)
{
  *a3 = nullptr;
  if ( memcmp(a2, &IID_IUnknown, 0x10u) != 0 && memcmp(a2, &IID_ID3DXBuffer, 0x10u) != 0 )
    return -2147467262;
  *a3 = this;
  (*(void (__stdcall **)(D3DXCore::CBuffer *))(*(_DWORD *)this + 4))(a1: this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DDF45
// Name: public: D3DXCore::CBuffer::CBuffer(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXCore::CBuffer *__thiscall D3DXCore::CBuffer::CBuffer(D3DXCore::CBuffer *this)
{
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 2) = 0;
  *(_DWORD *)this = &D3DXCore::CBuffer::`vftable';
  *((_DWORD *)this + 1) = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DDF5D
// Name: public: static long D3DXCore::CBuffer::Create(unsigned long,class D3DXCore::CBuffer __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static int __stdcall D3DXCore::CBuffer::Create(unsigned int a1, struct D3DXCore::CBuffer **a2)
{
  D3DXCore::CBuffer *v3; // eax
  struct D3DXCore::CBuffer *v4; // esi
  int v5; // edi

  if ( a2 == nullptr )
    return -2005530516;
  v3 = (D3DXCore::CBuffer *)MemAlloc_Alloc(nSize: 0x10u);
  if ( v3 != nullptr )
    v4 = D3DXCore::CBuffer::CBuffer(this: v3);
  else
    v4 = nullptr;
  if ( v4 == nullptr )
    return -2147024882;
  v5 = (*(int (__thiscall **)(struct D3DXCore::CBuffer *, unsigned int))(*(_DWORD *)v4 + 24))(a1: v4, a2: a1);
  if ( v5 >= 0 )
  {
    *a2 = v4;
    return 0;
  }
  else
  {
    (*(void (__thiscall **)(struct D3DXCore::CBuffer *, int))(*(_DWORD *)v4 + 20))(a1: v4, a2: 1);
    return v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DDFBF
// Name: D3DXCreateBuffer(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXCreateBuffer(unsigned int a1, struct D3DXCore::CBuffer **a2)
{
  return D3DXCore::CBuffer::Create(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x101DDFCA
// Name: public: D3DXCore::CResource::CResource(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXCore::CResource *__thiscall D3DXCore::CResource::CResource(D3DXCore::CResource *this)
{
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DDFD7
// Name: public: D3DXCore::CResource::~CResource(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXCore::CResource::~CResource(HGDIOBJ *this)
{
  if ( *this != nullptr )
    DeleteObject(ho: *this);
}

//------------------------------------------------------------------------------
// Address: 0x101DDFE5
// Name: public: D3DXCore::CFile::CFile(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXCore::CFile *__thiscall D3DXCore::CFile::CFile(D3DXCore::CFile *this)
{
  *(_DWORD *)this = -1;
  *((_DWORD *)this + 1) = -1;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  return this;
}
