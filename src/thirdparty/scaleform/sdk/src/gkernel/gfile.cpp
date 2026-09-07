// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gfile.cpp
// Functions: 17
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gfile.h"

//------------------------------------------------------------------------------
// Address: 0x100FB0C0
// Name: public: virtual int GBufferedFile::CopyFromStream(class GFile __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GBufferedFile::CopyFromStream(GBufferedFile *this, struct GFile *a2, int a3)
{
  int v3; // edi
  int result; // eax
  int v5; // esi
  int v6; // ecx
  int v7; // eax
  int v9; // [esp+Ch] [ebp-4008h]
  _BYTE v10[16384]; // [esp+10h] [ebp-4004h] BYREF

  v3 = a3;
  result = 0;
  v9 = 0;
  if ( a3 != 0 )
  {
    do
    {
      v5 = 0x4000;
      if ( v3 <= 0x4000 )
        v5 = v3;
      v6 = a2->Read(this: a2, a2: v10, a3: v5);
      v7 = 0;
      if ( v6 > 0 )
        v7 = this->Write(this, a2: v10, a3: v6);
      v9 += v7;
      v3 -= v7;
    }
    while ( v7 >= v5 && v3 != 0 );
    return v9;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10104260
// Name: char const __near * G_GetShortFilename(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IMatRenderContext *__cdecl G_GetShortFilename(IMatRenderContext *a1)
{
  IMatRenderContext *result; // eax
  unsigned int v2; // ecx
  char v3; // dl

  result = a1;
  v2 = strlen((const char *)a1);
  if ( v2 != 0 )
  {
    while ( 1 )
    {
      v3 = *((_BYTE *)&a1->__vftable + v2);
      if ( v3 == 92 || v3 == 47 )
        break;
      if ( --v2 == 0 )
        return result;
    }
    return (IMatRenderContext *)((char *)&a1->__vftable + v2 + 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101042A0
// Name: protected: void GBufferedFile::FlushBuffer(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GBufferedFile::FlushBuffer(int this)
{
  int v2; // eax
  bool v3; // cf
  int v4; // eax

  if ( *(_DWORD *)(this + 16) == 1 )
  {
    v4 = *(_DWORD *)(this + 20);
    if ( *(_DWORD *)(this + 24) != v4 )
      *(_QWORD *)(this + 32) = ((__int64 (__thiscall *)(_DWORD, int, int, int))*(_DWORD *)(**(_DWORD **)(this + 8) + 60))(
                                 a1: *(_DWORD *)(this + 8),
                                 a2: v4 - *(_DWORD *)(this + 24),
                                 a3: (v4 - *(_DWORD *)(this + 24)) >> 31,
                                 a4: 1);
    *(_DWORD *)(this + 24) = 0;
    *(_DWORD *)(this + 20) = 0;
    return 0;
  }
  else
  {
    v2 = *(_DWORD *)(this + 16) - 2;
    if ( *(_DWORD *)(this + 16) == 2 )
    {
      v2 = (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(this + 8) + 36))(
             a1: *(_DWORD *)(this + 8),
             a2: *(_DWORD *)(this + 12),
             a3: *(_DWORD *)(this + 20));
      v3 = __CFADD__(v2, *(_DWORD *)(this + 32));
      *(_DWORD *)(this + 32) += v2;
      *(_DWORD *)(this + 20) = 0;
      *(_DWORD *)(this + 36) += (v2 >> 31) + v3;
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10104300
// Name: public: virtual int GBufferedFile::Tell(void)
// Source: json
//------------------------------------------------------------------------------
CThreadSyncObject *__thiscall GBufferedFile::Tell(int this)
{
  CThreadSyncObject *v2; // eax

  if ( *(_DWORD *)(this + 16) == 1 )
    return (CThreadSyncObject *)(*(_DWORD *)(this + 20) + *(_DWORD *)(this + 32) - *(_DWORD *)(this + 24));
  v2 = (CThreadSyncObject *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 8) + 16))(a1: *(_DWORD *)(this + 8));
  if ( v2 != (CThreadSyncObject *)-1 && *(_DWORD *)(this + 16) == 2 )
    return (CThreadSyncObject *)((char *)v2 + *(_DWORD *)(this + 20));
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10104330
// Name: public: virtual __int64 GBufferedFile::LTell(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GBufferedFile::LTell(CThreadSyncObject *this)
{
  if ( *((_DWORD *)this + 4) != 1 )
    (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 2) + 20))(a1: *((_DWORD *)this + 2));
}

//------------------------------------------------------------------------------
// Address: 0x10104370
// Name: public: virtual int GBufferedFile::GetLength(void)
// Source: json
//------------------------------------------------------------------------------
CThreadSyncObject *__thiscall GBufferedFile::GetLength(int this)
{
  CThreadSyncObject *v2; // eax
  CThreadSyncObject *v3; // edi

  v2 = (CThreadSyncObject *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 8) + 24))(a1: *(_DWORD *)(this + 8));
  v3 = v2;
  if ( v2 != (CThreadSyncObject *)-1 && *(_DWORD *)(this + 16) == 2 )
  {
    v2 = (CThreadSyncObject *)(*(_DWORD *)(this + 20)
                             + (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 8) + 16))(a1: *(_DWORD *)(this + 8)));
    if ( (int)v2 <= (int)v3 )
      return v3;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101043B0
// Name: public: virtual __int64 GBufferedFile::LGetLength(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GBufferedFile::LGetLength(CThreadSyncObject *this)
{
  __int64 v2; // rax

  v2 = ((__int64 (__thiscall *)(_DWORD))*(_DWORD *)(**((_DWORD **)this + 2) + 28))(a1: *((_DWORD *)this + 2));
  if ( (HIDWORD(v2) & (unsigned int)v2) != 0xFFFFFFFF && *((_DWORD *)this + 4) == 2 )
    (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 2) + 20))(a1: *((_DWORD *)this + 2));
}

//------------------------------------------------------------------------------
// Address: 0x10104400
// Name: public: virtual int GBufferedFile::SkipBytes(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GBufferedFile::SkipBytes(CThreadSyncObject *this, int numBytes)
{
  int v2; // eax
  int v4; // edi
  int v5; // ecx
  int v6; // eax
  bool v7; // cf

  v2 = numBytes;
  v4 = 0;
  if ( *((_DWORD *)this + 4) == 1 )
  {
    v5 = *((_DWORD *)this + 5);
    v4 = *((_DWORD *)this + 6) - v5;
    if ( v4 >= numBytes )
      v4 = numBytes;
    *((_DWORD *)this + 5) = v4 + v5;
    v2 = numBytes - v4;
  }
  if ( v2 == 0 )
    return v4;
  v6 = (*(int (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 2) + 44))(a1: *((_DWORD *)this + 2), a2: v2);
  if ( v6 != -1 )
  {
    v4 += v6;
    v7 = __CFADD__(v6, *((_DWORD *)this + 8));
    *((_DWORD *)this + 8) += v6;
    *((_DWORD *)this + 6) = 0;
    *((_DWORD *)this + 5) = 0;
    *((_DWORD *)this + 9) += (v6 >> 31) + v7;
    return v4;
  }
  if ( v4 > 0 )
    return v4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10104470
// Name: public: virtual int GBufferedFile::BytesAvailable(void)
// Source: json
//------------------------------------------------------------------------------
CThreadSyncObject *__thiscall GBufferedFile::BytesAvailable(int this)
{
  CThreadSyncObject *v2; // eax

  v2 = (CThreadSyncObject *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 8) + 48))(a1: *(_DWORD *)(this + 8));
  if ( *(_DWORD *)(this + 16) == 1 )
    return (CThreadSyncObject *)((char *)v2 + *(_DWORD *)(this + 24) - *(_DWORD *)(this + 20));
  if ( *(_DWORD *)(this + 16) == 2 )
  {
    v2 = (CThreadSyncObject *)((char *)v2 - *(_DWORD *)(this + 20));
    if ( (int)v2 < 0 )
      return nullptr;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101044A0
// Name: public: virtual bool GBufferedFile::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GBufferedFile::Flush(CThreadSyncObject *this)
{
  GBufferedFile::FlushBuffer((int)this);
  return (*(void *(__thiscall **)(_DWORD))(**((_DWORD **)this + 2) + 52))(a1: *((_DWORD *)this + 2));
}

//------------------------------------------------------------------------------
// Address: 0x101044C0
// Name: public: virtual int GBufferedFile::Seek(int,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GBufferedFile::Seek(CThreadSyncObject *this, char *offset, int origin)
{
  int v4; // edi
  int v5; // edx
  unsigned int v6; // ecx
  char *v7; // edi
  unsigned int v8; // eax
  char *result; // eax
  unsigned int v10; // edi

  if ( *((_DWORD *)this + 4) != 1 )
  {
    GBufferedFile::FlushBuffer((int)this);
    result = offset;
LABEL_12:
    v4 = origin;
    goto LABEL_13;
  }
  v4 = origin;
  if ( origin == 1 )
  {
    v5 = *((_DWORD *)this + 5);
    v6 = *((_DWORD *)this + 6);
    v7 = &offset[v5];
    if ( (unsigned int)&offset[v5] <= v6 )
    {
      v8 = *((_DWORD *)this + 8) - v6;
      *((_DWORD *)this + 5) = v7;
      return &v7[v8];
    }
    v4 = 0;
    result = &offset[v5 + *((_DWORD *)this + 8) - v6];
    *((_DWORD *)this + 6) = 0;
    *((_DWORD *)this + 5) = 0;
    goto LABEL_13;
  }
  if ( origin == 0 )
  {
    result = offset;
    v10 = *((_DWORD *)this + 6);
    if ( v10 + (unsigned __int64)(unsigned int)offset - *((_QWORD *)this + 4) <= v10 )
    {
      *((_DWORD *)this + 5) = &offset[v10 - *((_DWORD *)this + 8)];
      return result;
    }
    *((_DWORD *)this + 6) = 0;
    *((_DWORD *)this + 5) = 0;
    goto LABEL_12;
  }
  GBufferedFile::FlushBuffer((int)this);
  result = offset;
LABEL_13:
  result = (char *)(*(int (__thiscall **)(_DWORD, char *, int))(**((_DWORD **)this + 2) + 56))(
                     a1: *((_DWORD *)this + 2),
                     a2: result,
                     a3: v4);
  *((_QWORD *)this + 4) = (int)result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10104580
// Name: public: virtual __int64 GBufferedFile::LSeek(__int64,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GBufferedFile::LSeek(CThreadSyncObject *this, __int64 offset, int origin)
{
  __int64 v4; // rax
  unsigned int v5; // ecx
  int v6; // edi
  __int64 v7; // kr00_8
  unsigned int v8; // edi

  if ( *((_DWORD *)this + 4) != 1 )
    goto LABEL_10;
  if ( origin != 1 )
  {
    if ( origin == 0 )
    {
      v8 = *((_DWORD *)this + 6);
      LODWORD(v4) = offset;
      if ( offset + (unsigned __int64)v8 - *((_QWORD *)this + 4) <= v8 )
      {
        *((_DWORD *)this + 5) = offset + v8 - *((_DWORD *)this + 8);
        return v4;
      }
      goto LABEL_6;
    }
LABEL_10:
    GBufferedFile::FlushBuffer((int)this);
    LODWORD(v4) = offset;
    goto LABEL_11;
  }
  HIDWORD(v4) = *((_DWORD *)this + 5);
  v5 = *((_DWORD *)this + 6);
  v6 = HIDWORD(v4) + offset;
  if ( HIDWORD(v4) + (int)offset > v5 )
  {
    v7 = HIDWORD(v4) + *((_QWORD *)this + 4) - v5;
    LODWORD(v4) = v7 + offset;
    HIDWORD(offset) = (unsigned __int64)(v7 + offset) >> 32;
    origin = 0;
LABEL_6:
    *((_DWORD *)this + 6) = 0;
    *((_DWORD *)this + 5) = 0;
LABEL_11:
    v4 = ((__int64 (__thiscall *)(_DWORD, _DWORD, _DWORD, int))*(_DWORD *)(**((_DWORD **)this + 2) + 60))(
           a1: *((_DWORD *)this + 2),
           a2: v4,
           a3: HIDWORD(offset),
           a4: origin);
    *((_QWORD *)this + 4) = v4;
    return v4;
  }
  v4 = *((_QWORD *)this + 4) - v5;
  *((_DWORD *)this + 5) = v6;
  LODWORD(v4) = v6 + v4;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10104650
// Name: public: virtual bool GBufferedFile::ChangeSize(int)
// Source: json
//------------------------------------------------------------------------------
CThreadSyncObject *__thiscall GBufferedFile::ChangeSize(_DWORD **this, CThreadSyncObject *result)
{
  GBufferedFile::FlushBuffer((int)this);
  return (*(CThreadSyncObject *(__thiscall **)(_DWORD, CThreadSyncObject *))(**(this + 2) + 64))(
           a1: *(this + 2),
           a2: result);
}

//------------------------------------------------------------------------------
// Address: 0x10104670
// Name: public: virtual bool GBufferedFile::Close(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GBufferedFile::Close(CThreadSyncObject *this)
{
  if ( *((_DWORD *)this + 4) == 1 )
  {
    *((_DWORD *)this + 4) = 0;
  }
  else if ( *((_DWORD *)this + 4) == 2 )
  {
    GBufferedFile::FlushBuffer((int)this);
  }
  return (*(void *(__thiscall **)(_DWORD))(**((_DWORD **)this + 2) + 72))(a1: *((_DWORD *)this + 2));
}

//------------------------------------------------------------------------------
// Address: 0x101046A0
// Name: public: virtual int GBufferedFile::Write(unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GBufferedFile::Write(GBufferedFile *this, unsigned __int8 *src, int numBytes)
{
  GFile *pObject; // ecx
  int result; // eax

  if ( this->BufferMode != WriteBuffer )
  {
    if ( this->pBuffer == nullptr )
      goto LABEL_8;
    GBufferedFile::FlushBuffer((int)this);
    pObject = this->pFile.pObject;
    if ( pObject == nullptr || !pObject->IsWritable(this: pObject) )
      goto LABEL_8;
    this->BufferMode = WriteBuffer;
    this->Pos = 0;
    this->DataSize = 0;
  }
  if ( (signed int)(8184 - this->Pos) >= numBytes || (GBufferedFile::FlushBuffer((int)this), numBytes <= 4096) )
  {
    memcpy(dst: &this->pBuffer[this->Pos], src, count: numBytes);
    this->Pos += numBytes;
    return numBytes;
  }
LABEL_8:
  result = this->pFile.pObject->Write(this: this->pFile.pObject, a2: src, a3: numBytes);
  if ( result > 0 )
    this->FilePos += result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10104760
// Name: public: virtual int GBufferedFile::Read(unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GBufferedFile::Read(int this, CThreadSyncObject *result, signed int numBytes)
{
  int v4; // eax
  int v5; // ebx
  unsigned __int8 *v6; // ecx
  int v7; // eax
  signed int v8; // edi
  int v9; // eax
  bool v10; // cf
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  unsigned __int8 *pdestBuffer; // [esp+14h] [ebp+8h]

  if ( *(_DWORD *)(this + 16) == 1 )
  {
LABEL_4:
    v4 = *(_DWORD *)(this + 20);
    v5 = *(_DWORD *)(this + 24) - v4;
    v6 = (unsigned __int8 *)(v4 + *(_DWORD *)(this + 12));
    if ( v5 < numBytes )
    {
      memcpy(dst: (unsigned __int8 *)result, src: v6, count: *(_DWORD *)(this + 24) - v4);
      pdestBuffer = (unsigned __int8 *)result + v5;
      v8 = numBytes - v5;
      *(_DWORD *)(this + 20) = *(_DWORD *)(this + 24);
      if ( numBytes - v5 <= 4096 )
      {
        if ( *(_DWORD *)(this + 16) == 1 )
        {
          v11 = (*(int (__thiscall **)(_DWORD, _DWORD, int))(**(_DWORD **)(this + 8) + 40))(
                  a1: *(_DWORD *)(this + 8),
                  a2: *(_DWORD *)(this + 12),
                  a3: 8184);
          *(_DWORD *)(this + 20) = 0;
          v12 = v11 < 0 ? 0 : v11;
          v10 = __CFADD__(v12, *(_DWORD *)(this + 32));
          *(_DWORD *)(this + 32) += v12;
          *(_DWORD *)(this + 24) = v12;
          *(_DWORD *)(this + 36) += v10;
        }
        v13 = *(_DWORD *)(this + 20);
        if ( *(_DWORD *)(this + 24) - v13 < v8 )
          v8 = *(_DWORD *)(this + 24) - v13;
        memcpy(dst: pdestBuffer, src: (unsigned __int8 *)(v13 + *(_DWORD *)(this + 12)), count: v8);
        *(_DWORD *)(this + 20) += v8;
        return v5 + v8;
      }
      else
      {
        v9 = (*(int (__thiscall **)(_DWORD, unsigned __int8 *, signed int))(**(_DWORD **)(this + 8) + 40))(
               a1: *(_DWORD *)(this + 8),
               a2: pdestBuffer,
               a3: v8);
        if ( v9 > 0 )
        {
          v10 = __CFADD__(v9, *(_DWORD *)(this + 32));
          *(_DWORD *)(this + 32) += v9;
          *(_DWORD *)(this + 24) = 0;
          *(_DWORD *)(this + 20) = 0;
          *(_DWORD *)(this + 36) += (v9 >> 31) + v10;
        }
        return v5 + (v9 != -1 ? v9 : 0);
      }
    }
    else
    {
      memcpy(dst: (unsigned __int8 *)result, src: v6, count: numBytes);
      *(_DWORD *)(this + 20) += numBytes;
      return numBytes;
    }
  }
  if ( *(_DWORD *)(this + 12) != 0 )
  {
    GBufferedFile::FlushBuffer(this);
    *(_DWORD *)(this + 16) = 1;
    *(_DWORD *)(this + 20) = 0;
    *(_DWORD *)(this + 24) = 0;
    goto LABEL_4;
  }
  v7 = (*(int (__thiscall **)(_DWORD, CThreadSyncObject *, signed int))(**(_DWORD **)(this + 8) + 40))(
         a1: *(_DWORD *)(this + 8),
         a2: result,
         a3: numBytes);
  if ( v7 > 0 )
    *(_QWORD *)(this + 32) += v7;
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101048F0
// Name: public: GBufferedFile::GBufferedFile(class GFile __near *)
// Source: json
//------------------------------------------------------------------------------
IClientMaterialSystem *__thiscall GBufferedFile::GBufferedFile(IClientMaterialSystem *this, IShaderDevice *pfile)
{
  int v4; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (IClientMaterialSystem_vtbl *)&GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  this->__vftable = (IClientMaterialSystem_vtbl *)&GDelegatedFile::`vftable';
  if ( pfile != nullptr )
    GRefCountImpl::AddRef(this: pfile);
  *((_DWORD *)this + 2) = pfile;
  this->__vftable = (IClientMaterialSystem_vtbl *)&GBufferedFile::`vftable';
  v4 = 2;
  *((_DWORD *)this + 3) = GMemory::pGlobalHeap->Alloc(this: GMemory::pGlobalHeap, a2: 8184, a3: 32, a4: &v4);
  *((_DWORD *)this + 4) = 0;
  *((_QWORD *)this + 4) = ((__int64 (__thiscall *)(IShaderDevice *))pfile->GetCurrentAdapter)(a1: pfile);
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  return this;
}
