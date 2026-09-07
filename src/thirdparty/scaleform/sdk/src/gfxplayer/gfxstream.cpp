// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxstream.cpp
// Functions: 40
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxstream.h"

//------------------------------------------------------------------------------
// Address: 0x100E1D50
// Name: public: int GFxStream::GetTagEndPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStream::GetTagEndPosition(IShaderDeviceMgr *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100E1D70
// Name: public: bool GFxStream::IsVerboseParse(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxStream::IsVerboseParse(GFxStream *this)
{
  return (unsigned int)*(this + 3) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E1D80
// Name: public: bool GFxStream::IsVerboseParseShape(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxStream::IsVerboseParseShape(GFxStream *this)
{
  return ((unsigned int)*(this + 3) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E1D90
// Name: public: bool GFxStream::IsVerboseParseAction(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxStream::IsVerboseParseAction(GFxStream *this)
{
  return ((unsigned int)*(this + 3) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E1DA0
// Name: public: unsigned int GFxStreamContext::ReadUInt(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxStreamContext::ReadUInt(GFxStreamContext *this, unsigned int a2)
{
  int v3; // ebx
  int v4; // edi
  unsigned int v5; // ebx
  char v6; // di
  unsigned int result; // eax
  int v8; // ecx
  int v9; // ecx
  int v10; // esi
  int v11; // ecx
  int v12; // eax
  int v13; // esi
  unsigned int v14; // ecx
  _BYTE *v15; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // esi
  unsigned int v19; // edi

  v3 = *((_DWORD *)this + 3);
  v4 = 1 << (8 - v3);
  v5 = a2 + v3;
  v6 = v4 - 1;
  switch ( a2 )
  {
    case 0u:
    case 0x21u:
    case 0x22u:
    case 0x23u:
      return 0;
    case 1u:
    case 2u:
    case 3u:
    case 4u:
    case 5u:
    case 6u:
    case 7u:
    case 8u:
      if ( v5 > 8 )
        goto LABEL_6;
      result = (unsigned __int8)(v6 & *(_BYTE *)(*((_DWORD *)this + 2) + *(_DWORD *)this));
      v8 = 8;
      goto LABEL_10;
    case 9u:
    case 0xAu:
    case 0xBu:
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
    case 0x10u:
      if ( v5 <= 0x10 )
      {
LABEL_6:
        v9 = *((_DWORD *)this + 2);
        result = *(unsigned __int8 *)(v9 + *(_DWORD *)this + 1)
               | ((unsigned __int8)(v6 & *(_BYTE *)(v9 + *(_DWORD *)this)) << 8);
        *((_DWORD *)this + 2) = v9 + 1;
        v8 = 16;
        goto LABEL_10;
      }
      v10 = *((_DWORD *)this + 2);
      v11 = *(unsigned __int8 *)(*(_DWORD *)this + v10 + 2);
      v12 = (*(unsigned __int8 *)(*(_DWORD *)this + v10 + 1)
           | ((unsigned __int8)(v6 & *(_BYTE *)(*(_DWORD *)this + v10)) << 8)) << 8;
LABEL_8:
      result = v11 | v12;
      v13 = v10 + 2;
      v8 = 24;
      goto LABEL_9;
    case 0x11u:
    case 0x12u:
    case 0x13u:
    case 0x14u:
    case 0x15u:
    case 0x16u:
    case 0x17u:
    case 0x18u:
      v10 = *((_DWORD *)this + 2);
      v15 = (_BYTE *)(v10 + *(_DWORD *)this);
      v12 = ((unsigned __int8)v15[1] | ((unsigned __int8)(v6 & *v15) << 8)) << 8;
      if ( v5 > 0x18 )
        goto LABEL_16;
      v11 = (unsigned __int8)v15[2];
      goto LABEL_8;
    case 0x19u:
    case 0x1Au:
    case 0x1Bu:
    case 0x1Cu:
    case 0x1Du:
    case 0x1Eu:
    case 0x1Fu:
    case 0x20u:
      if ( v5 > 0x20 )
      {
        v16 = *((_DWORD *)this + 2);
        v17 = *(_DWORD *)this;
        v18 = *(unsigned __int8 *)(*(_DWORD *)this + v16 + 3)
            | ((*(unsigned __int8 *)(*(_DWORD *)this + v16 + 2)
              | ((*(unsigned __int8 *)(*(_DWORD *)this + v16 + 1)
                | ((unsigned __int8)(v6 & *(_BYTE *)(*(_DWORD *)this + v16)) << 8)) << 8)) << 8);
        *((_DWORD *)this + 2) = v16 + 4;
        v19 = *(unsigned __int8 *)(v16 + 4 + v17);
        *((_DWORD *)this + 3) = v5 - 32;
        return (v18 << (v5 - 32)) | (v19 >> (8 - (v5 - 32)));
      }
      else
      {
        v10 = *((_DWORD *)this + 2);
        v15 = (_BYTE *)(v10 + *(_DWORD *)this);
        v12 = ((unsigned __int8)v15[1] | ((unsigned __int8)(v6 & *v15) << 8)) << 8;
LABEL_16:
        result = (unsigned __int8)v15[3] | (((unsigned __int8)v15[2] | v12) << 8);
        v13 = v10 + 3;
        v8 = 32;
LABEL_9:
        *((_DWORD *)this + 2) = v13;
LABEL_10:
        v14 = v8 - v5;
        if ( v14 != 0 )
        {
          *((_DWORD *)this + 3) = 8 - v14;
          result >>= v14;
        }
        else
        {
LABEL_19:
          ++*((_DWORD *)this + 2);
          *((_DWORD *)this + 3) = 0;
        }
      }
      return result;
    default:
      result = 0;
      goto LABEL_19;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1F40
// Name: public: virtual GFxStream::~GFxStream(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStream::~GFxStream(GFxStream *this)
{
  volatile LONG *v2; // edi
  IShaderAPI *v3; // ecx

  v2 = (volatile LONG *)((unsigned int)*(this + 6) & 0xFFFFFFFC);
  *this = (GFxStream)&GFxStream::`vftable';
  if ( InterlockedExchangeAdd(Addend: v2 + 1, Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v2);
  v3 = (IShaderAPI *)*(this + 4);
  if ( v3 != nullptr )
    GRefCountImpl::Release(this: v3);
  *this = (GFxStream)&GFxLogBase<GFxLoadProcess>::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100E1F90
// Name: public: void GFxStream::Initialize(class GFile __near *,class GFxLog __near *,class GFxParseControl __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStream::Initialize(
        GFxStream *this,
        IShaderDevice *a2,
        _LUID_AND_ATTRIBUTES *a3,
        _LUID_AND_ATTRIBUTES *a4)
{
  IShaderAPI *v5; // ecx
  _LUID_AND_ATTRIBUTES *LowPart; // eax
  unsigned __int8 *v7; // eax

  if ( a2 != nullptr )
    GRefCountImpl::AddRef(this: a2);
  v5 = (IShaderAPI *)*(this + 4);
  if ( v5 != nullptr )
    GRefCountImpl::Release(this: v5);
  *(this + 4) = (GFxStream)a2;
  *(this + 1) = (GFxStream)a3;
  *(this + 2) = (GFxStream)a4;
  if ( a4 != nullptr )
    LowPart = (_LUID_AND_ATTRIBUTES *)a4[1].Luid.LowPart;
  else
    LowPart = nullptr;
  *(this + 3) = (GFxStream)LowPart;
  *((_WORD *)this + 10) = 0;
  if ( a2 != nullptr )
  {
    v7 = (unsigned __int8 *)((int (__thiscall *)(IShaderDevice *))a2->ReacquireResources)(a1: a2);
    GString::operator=(
      this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(this + 6),
      a2: v7);
  }
  else
  {
    GString::Clear(this: (GString *)this + 6);
  }
  *(this + 10) = nullptr;
  *(this + 8) = nullptr;
  *(this + 9) = nullptr;
  *(this + 11) = nullptr;
  *(this + 12) = nullptr;
  *((_BYTE *)this + 56) = 0;
  if ( a2 != nullptr )
    *(this + 13) = (GFxStream)a2->GetAspectRatioInfo(this: a2);
  else
    *(this + 13) = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100E2030
// Name: public: void GFxStream::ShutDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStream::ShutDown(GFxStream *this)
{
  IShaderAPI *v2; // ecx

  GString::Clear(this: (GString *)this + 6);
  v2 = (IShaderAPI *)*(this + 4);
  if ( v2 != nullptr )
    GRefCountImpl::Release(this: v2);
  *(this + 4) = nullptr;
  *(this + 1) = nullptr;
  *(this + 2) = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100E2060
// Name: private: bool GFxStream::PopulateBuffer(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxStream::PopulateBuffer(int this, _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *result)
{
  int v3; // ecx
  unsigned int v4; // ecx
  unsigned int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // edi
  int v9; // eax
  int v10; // edx
  int v11; // ecx
  bool v12; // al
  int v13; // eax

  if ( *(_DWORD *)(this + 48) == 0 )
  {
    v3 = *(_DWORD *)(this + 16);
    if ( v3 != 0 )
    {
      *(_DWORD *)(this + 52) = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 16))(a1: v3);
      *(_BYTE *)(this + 56) = 0;
    }
  }
  v4 = *(_DWORD *)(this + 44);
  v5 = *(_DWORD *)(this + 48);
  if ( v4 >= v5 )
  {
    *(_DWORD *)(this + 48) = 0;
  }
  else
  {
    memmove(
      dst: *(unsigned __int8 **)(this + 60),
      src: (unsigned __int8 *)(*(_DWORD *)(this + 60) + v4),
      count: v5 - v4);
    *(_DWORD *)(this + 48) -= *(_DWORD *)(this + 44);
  }
  v6 = *(_DWORD *)(this + 16);
  *(_DWORD *)(this + 44) = 0;
  if ( v6 != 0 )
  {
    v7 = *(_DWORD *)(this + 48);
    v8 = *(_DWORD *)(this + 64) - v7;
    v9 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)v6 + 40))(a1: v6, a2: v7 + *(_DWORD *)(this + 60), a3: v8);
    if ( v9 >= v8 )
    {
      *(_DWORD *)(this + 48) += v9;
      *(_DWORD *)(this + 52) += v9;
      return true;
    }
    else
    {
      if ( v9 > 0 )
      {
        *(_DWORD *)(this + 48) += v9;
        *(_DWORD *)(this + 52) += v9;
      }
      memset(
        dst: (unsigned __int8 *)(*(_DWORD *)(this + 48) + *(_DWORD *)(this + 60)),
        value: 0,
        count: *(_DWORD *)(this + 64) - *(_DWORD *)(this + 48));
      v10 = *(_DWORD *)(this + 44);
      v11 = *(_DWORD *)(this + 48) - v10;
      v12 = (int)result <= v11;
      if ( v11 < (int)result )
        *(_DWORD *)(this + 48) = (char *)result + v10;
    }
  }
  else
  {
    *(_DWORD *)(this + 60) = this + 68;
    *(_DWORD *)(this + 64) = 512;
    memset(dst: (unsigned __int8 *)(this + 68), value: 0, count: 0x200u);
    v13 = *(_DWORD *)(this + 64);
    *(_DWORD *)(this + 52) += v13;
    *(_DWORD *)(this + 44) = 0;
    *(_DWORD *)(this + 48) = v13;
    return false;
  }
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x100E2160
// Name: private: bool GFxStream::PopulateBuffer1(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxStream::PopulateBuffer1(void *this)
{
  return GFxStream::PopulateBuffer((int)this, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)1);
}

//------------------------------------------------------------------------------
// Address: 0x100E2170
// Name: public: void GFxStream::SyncFileStream(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStream::SyncFileStream(GFxStream *this)
{
  _LUID_AND_ATTRIBUTES *v2; // eax

  v2 = (_LUID_AND_ATTRIBUTES *)(*(int (__thiscall **)(_DWORD, char *, _DWORD))((**(this + 4))[0].Luid.LowPart + 56))(
                                 a1: *(this + 4),
                                 a2: (char *)*(this + 11) + (char *)*(this + 13) - (char *)*(this + 12),
                                 a3: 0);
  if ( v2 != (_LUID_AND_ATTRIBUTES *)-1 )
  {
    *(this + 11) = nullptr;
    *(this + 13) = (GFxStream)v2;
    *(this + 12) = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E21B0
// Name: public: int GFxStream::ReadToBuffer(unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxStream::ReadToBuffer(GFxStream *this, unsigned __int8 *pdestBuf, unsigned int sz)
{
  unsigned int v4; // ebx
  unsigned int v5; // ecx
  unsigned int v6; // eax
  signed int v7; // edi
  unsigned int v8; // eax
  int v9; // eax

  v4 = 0;
  if ( *(this + 12) == nullptr )
  {
    *(this + 13) = (GFxStream)(*(int (__thiscall **)(_DWORD))((**(this + 4))[0].Luid.LowPart + 16))(a1: *(this + 4));
    *((_BYTE *)this + 56) = 0;
  }
  v5 = (unsigned int)*(this + 11);
  v6 = (unsigned int)*(this + 12);
  v7 = sz;
  if ( v5 < v6 )
  {
    v8 = v6 - v5;
    v4 = sz;
    if ( sz >= v8 )
      v4 = v8;
    memmove(dst: pdestBuf, src: (unsigned __int8 *)*(this + 15) + v5, count: v4);
    *(this + 11) = (GFxStream)((char *)*(this + 11) + v4);
    v7 = sz - v4;
    pdestBuf += v4;
  }
  if ( *(this + 11) >= *(this + 12) )
  {
    *(this + 12) = nullptr;
    *(this + 11) = nullptr;
  }
  if ( v7 != 0 )
  {
    v9 = (*(int (__thiscall **)(_DWORD, unsigned __int8 *, signed int))((**(this + 4))[0].Luid.LowPart + 40))(
           a1: *(this + 4),
           a2: pdestBuf,
           a3: v7);
    *(this + 13) = (GFxStream)((char *)*(this + 13) + v9);
    v4 += v9;
    if ( v9 < v7 )
      memset(dst: &pdestBuf[v9], value: 0, count: v7 - v9);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100E2250
// Name: public: void GFxStream::SetPosition(int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GFxStream::SetPosition@<eax>(IShaderDeviceMgr *this@<ecx>, int pos, int a3)
{
  int v4; // edx
  int v5; // eax
  int result; // eax

  v4 = *((_DWORD *)this + 13);
  v5 = *((_DWORD *)this + 12);
  *((_BYTE *)this + 21) = 0;
  if ( pos < v4 - v5 || pos >= v4 )
  {
    if ( *((_BYTE *)this + 56) != 0 || (result = v4 - v5 + *((_DWORD *)this + 11)) != pos )
    {
      result = (*(int (__thiscall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 4) + 56))(
                 a1: *((_DWORD *)this + 4),
                 a2: pos,
                 a3: 0);
      if ( result >= 0 )
      {
        *((_BYTE *)this + 56) = 0;
        *((_DWORD *)this + 11) = 0;
        *((_DWORD *)this + 12) = 0;
        *((_DWORD *)this + 13) = pos;
      }
    }
  }
  else
  {
    result = pos + v5 - v4;
    *((_DWORD *)this + 11) = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E22C0
// Name: public: void GFxStream::CloseTag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStream::CloseTag(GFxStream *this)
{
  int v2; // [esp+0h] [ebp-4h]

  *(this + 10) = (GFxStream)((char *)*(this + 10) - 1);
  GFxStream::SetPosition((IShaderDeviceMgr *)this, pos: (int)*(this + (_DWORD)*(this + 10) + 8), a3: v2);
  *((_BYTE *)this + 21) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E22E0
// Name: public: void GFxStreamContext::ReadMatrix(class GMatrix2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStreamContext::ReadMatrix(GFxStreamContext *this, CMaterialDict *pm)
{
  int v3; // edx
  int v4; // edi
  int v5; // eax
  unsigned int UInt; // edi
  unsigned int v7; // eax
  int v8; // ebx
  unsigned int v9; // eax
  int v10; // edx
  int v11; // edi
  int v12; // eax
  unsigned int v13; // edi
  unsigned int v14; // eax
  int v15; // ebx
  unsigned int v16; // eax
  signed int v17; // eax
  unsigned int v18; // edi
  unsigned int v19; // eax
  int v20; // ebx
  unsigned int v21; // eax
  int v22; // [esp+Ch] [ebp-4h]
  int v23; // [esp+Ch] [ebp-4h]
  int v24; // [esp+Ch] [ebp-4h]
  int v25; // [esp+Ch] [ebp-4h]
  int v26; // [esp+Ch] [ebp-4h]
  int v27; // [esp+Ch] [ebp-4h]

  if ( *((_DWORD *)this + 3) != 0 )
    ++*((_DWORD *)this + 2);
  *((_DWORD *)this + 3) = 0;
  GMatrix2D::SetIdentity(this: (float *)pm);
  v3 = *((_DWORD *)this + 3);
  v4 = *((_DWORD *)this + 2);
  v5 = *(unsigned __int8 *)(v4 + *(_DWORD *)this) & (1 << (7 - v3));
  *((_DWORD *)this + 3) = v3 + 1;
  if ( (unsigned int)(v3 + 1) >= 8 )
  {
    *((_DWORD *)this + 3) = 0;
    *((_DWORD *)this + 2) = v4 + 1;
  }
  if ( v5 != 0 )
  {
    UInt = GFxStreamContext::ReadUInt(this, a2: 5u);
    v7 = GFxStreamContext::ReadUInt(this, a2: UInt);
    v8 = 1 << (UInt - 1);
    v22 = v7;
    if ( (v8 & v7) != 0 )
      v22 = (-1 << UInt) | v7;
    *(float *)&pm->m_MaterialDict.m_LessFunc = (double)v22 * 0.0000152587890625;
    v9 = GFxStreamContext::ReadUInt(this, a2: UInt);
    v23 = v9;
    if ( (v8 & v9) != 0 )
      v23 = (-1 << UInt) | v9;
    *(float *)&pm->m_MaterialDict.m_Root = (double)v23 * 0.0000152587890625;
  }
  v10 = *((_DWORD *)this + 3);
  v11 = *((_DWORD *)this + 2);
  v12 = *(unsigned __int8 *)(v11 + *(_DWORD *)this) & (1 << (7 - v10));
  *((_DWORD *)this + 3) = v10 + 1;
  if ( (unsigned int)(v10 + 1) >= 8 )
  {
    *((_DWORD *)this + 3) = 0;
    *((_DWORD *)this + 2) = v11 + 1;
  }
  if ( v12 != 0 )
  {
    v13 = GFxStreamContext::ReadUInt(this, a2: 5u);
    v14 = GFxStreamContext::ReadUInt(this, a2: v13);
    v15 = 1 << (v13 - 1);
    v24 = v14;
    if ( (v15 & v14) != 0 )
      v24 = (-1 << v13) | v14;
    *(float *)&pm->m_MaterialDict.m_Elements.m_nGrowSize = (double)v24 * 0.0000152587890625;
    v16 = GFxStreamContext::ReadUInt(this, a2: v13);
    v25 = v16;
    if ( (v15 & v16) != 0 )
      v25 = (-1 << v13) | v16;
    *(float *)&pm->m_MaterialDict.m_Elements.m_pMemory = 0.0000152587890625 * (double)v25;
  }
  v17 = GFxStreamContext::ReadUInt(this, a2: 5u);
  v18 = v17;
  if ( v17 > 0 )
  {
    v19 = GFxStreamContext::ReadUInt(this, a2: v17);
    v20 = 1 << (v18 - 1);
    v26 = v19;
    if ( (v20 & v19) != 0 )
      v26 = (-1 << v18) | v19;
    *(float *)&pm->m_MaterialDict.m_Elements.m_nAllocationCount = (float)v26;
    v21 = GFxStreamContext::ReadUInt(this, a2: v18);
    v27 = v21;
    if ( (v20 & v21) != 0 )
      v27 = (-1 << v18) | v21;
    *(float *)&pm->m_MaterialDict.m_FirstFree = (float)v27;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E24A0
// Name: public: void GFxStreamContext::ReadCxformRgb(class GRenderer::Cxform __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStreamContext::ReadCxformRgb(GFxStreamContext *this, struct GRenderer::Cxform *a2)
{
  char *v3; // eax
  BOOL v4; // ecx
  char v5; // bl
  unsigned int UInt; // eax
  unsigned int v7; // edi
  unsigned int v8; // eax
  int v9; // ebx
  unsigned int v10; // eax
  unsigned int v11; // eax
  float *v12; // eax
  double v13; // st7
  unsigned int v14; // eax
  int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int hasAdd; // [esp+Ch] [ebp-8h]
  int v19; // [esp+10h] [ebp-4h]
  int v20; // [esp+10h] [ebp-4h]
  int v21; // [esp+10h] [ebp-4h]
  int v22; // [esp+10h] [ebp-4h]
  int v23; // [esp+10h] [ebp-4h]
  int v24; // [esp+10h] [ebp-4h]

  if ( *((_DWORD *)this + 3) != 0 )
    ++*((_DWORD *)this + 2);
  v3 = (char *)(*(_DWORD *)this + *((_DWORD *)this + 2));
  *((_DWORD *)this + 3) = 0;
  v4 = *v3 < 0;
  *((_DWORD *)this + 3) = 1;
  v5 = *v3;
  *((_DWORD *)this + 3) = 2;
  hasAdd = v4;
  UInt = GFxStreamContext::ReadUInt(this, a2: 4u);
  v7 = UInt;
  if ( (v5 & 0x40) != 0 )
  {
    v8 = GFxStreamContext::ReadUInt(this, a2: UInt);
    v9 = 1 << (v7 - 1);
    v19 = v8;
    if ( (v9 & v8) != 0 )
      v19 = (-1 << v7) | v8;
    a2->M_[0][0] = (double)v19 * 0.00390625;
    v10 = GFxStreamContext::ReadUInt(this, a2: v7);
    v20 = v10;
    if ( (v9 & v10) != 0 )
      v20 = (-1 << v7) | v10;
    a2->M_[1][0] = (double)v20 * 0.00390625;
    v11 = GFxStreamContext::ReadUInt(this, a2: v7);
    v21 = v11;
    if ( (v9 & v11) != 0 )
      v21 = (-1 << v7) | v11;
    v12 = (float *)a2;
    a2->M_[2][0] = 0.00390625 * (double)v21;
    v13 = 1.0;
  }
  else
  {
    v13 = 1.0;
    v12 = (float *)a2;
    a2->M_[0][0] = 1.0;
    a2->M_[1][0] = 1.0;
    a2->M_[2][0] = 1.0;
  }
  v12[6] = v13;
  if ( hasAdd != 0 )
  {
    v14 = GFxStreamContext::ReadUInt(this, a2: v7);
    v15 = 1 << (v7 - 1);
    v22 = v14;
    if ( (v15 & v14) != 0 )
      v22 = (-1 << v7) | v14;
    a2->M_[0][1] = (float)v22;
    v16 = GFxStreamContext::ReadUInt(this, a2: v7);
    v23 = v16;
    if ( (v15 & v16) != 0 )
      v23 = (-1 << v7) | v16;
    a2->M_[1][1] = (float)v23;
    v17 = GFxStreamContext::ReadUInt(this, a2: v7);
    v24 = v17;
    if ( (v15 & v17) != 0 )
      v24 = (-1 << v7) | v17;
    a2->M_[2][1] = (float)v24;
    a2->M_[3][1] = v13;
  }
  else
  {
    v12[1] = 0.0;
    v12[3] = 0.0;
    v12[5] = 0.0;
    v12[7] = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2640
// Name: public: void GFxStreamContext::ReadCxformRgba(class GRenderer::Cxform __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStreamContext::ReadCxformRgba(GFxStreamContext *this, struct GRenderer::Cxform *a2)
{
  char *v3; // eax
  BOOL v4; // ecx
  char v5; // bl
  unsigned int UInt; // eax
  unsigned int v7; // edi
  unsigned int v8; // eax
  float *v9; // ebx
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  double v13; // st7
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int hasAdd; // [esp+Ch] [ebp-Ch]
  int v19; // [esp+10h] [ebp-8h]
  int v20; // [esp+14h] [ebp-4h]
  int v21; // [esp+14h] [ebp-4h]
  struct GRenderer::Cxform *v22; // [esp+20h] [ebp+8h]
  struct GRenderer::Cxform *v23; // [esp+20h] [ebp+8h]
  struct GRenderer::Cxform *v24; // [esp+20h] [ebp+8h]
  struct GRenderer::Cxform *v25; // [esp+20h] [ebp+8h]
  struct GRenderer::Cxform *v26; // [esp+20h] [ebp+8h]
  struct GRenderer::Cxform *v27; // [esp+20h] [ebp+8h]
  struct GRenderer::Cxform *v28; // [esp+20h] [ebp+8h]

  if ( *((_DWORD *)this + 3) != 0 )
    ++*((_DWORD *)this + 2);
  v3 = (char *)(*(_DWORD *)this + *((_DWORD *)this + 2));
  *((_DWORD *)this + 3) = 0;
  v4 = *v3 < 0;
  *((_DWORD *)this + 3) = 1;
  v5 = *v3;
  *((_DWORD *)this + 3) = 2;
  hasAdd = v4;
  UInt = GFxStreamContext::ReadUInt(this, a2: 4u);
  v7 = UInt;
  if ( (v5 & 0x40) != 0 )
  {
    v8 = GFxStreamContext::ReadUInt(this, a2: UInt);
    v19 = v8;
    v20 = 1 << (v7 - 1);
    if ( (v20 & v8) != 0 )
      v19 = (-1 << v7) | v8;
    v9 = (float *)a2;
    a2->M_[0][0] = (double)v19 * 0.00390625;
    v10 = GFxStreamContext::ReadUInt(this, a2: v7);
    v22 = (struct GRenderer::Cxform *)v10;
    if ( (v10 & v20) != 0 )
      v22 = (struct GRenderer::Cxform *)((-1 << v7) | v10);
    v9[2] = (double)(int)v22 * 0.00390625;
    v11 = GFxStreamContext::ReadUInt(this, a2: v7);
    v23 = (struct GRenderer::Cxform *)v11;
    if ( (v11 & v20) != 0 )
      v23 = (struct GRenderer::Cxform *)((-1 << v7) | v11);
    v9[4] = (double)(int)v23 * 0.00390625;
    v12 = GFxStreamContext::ReadUInt(this, a2: v7);
    v24 = (struct GRenderer::Cxform *)v12;
    if ( (v12 & v20) != 0 )
      v24 = (struct GRenderer::Cxform *)((-1 << v7) | v12);
    v13 = 0.00390625 * (double)(int)v24;
  }
  else
  {
    v13 = 1.0;
    v9 = (float *)a2;
    a2->M_[0][0] = 1.0;
    a2->M_[1][0] = 1.0;
    a2->M_[2][0] = 1.0;
  }
  v9[6] = v13;
  if ( hasAdd != 0 )
  {
    v14 = GFxStreamContext::ReadUInt(this, a2: v7);
    v25 = (struct GRenderer::Cxform *)v14;
    v21 = 1 << (v7 - 1);
    if ( (v21 & v14) != 0 )
      v25 = (struct GRenderer::Cxform *)((-1 << v7) | v14);
    v9[1] = (float)(int)v25;
    v15 = GFxStreamContext::ReadUInt(this, a2: v7);
    v26 = (struct GRenderer::Cxform *)v15;
    if ( (v15 & v21) != 0 )
      v26 = (struct GRenderer::Cxform *)((-1 << v7) | v15);
    v9[3] = (float)(int)v26;
    v16 = GFxStreamContext::ReadUInt(this, a2: v7);
    v27 = (struct GRenderer::Cxform *)v16;
    if ( (v16 & v21) != 0 )
      v27 = (struct GRenderer::Cxform *)((-1 << v7) | v16);
    v9[5] = (float)(int)v27;
    v17 = GFxStreamContext::ReadUInt(this, a2: v7);
    v28 = (struct GRenderer::Cxform *)v17;
    if ( (v17 & v21) != 0 )
      v28 = (struct GRenderer::Cxform *)((-1 << v7) | v17);
    v9[7] = (float)(int)v28;
  }
  else
  {
    v9[1] = 0.0;
    v9[3] = 0.0;
    v9[5] = 0.0;
    v9[7] = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2810
// Name: public: GFxStream::GFxStream(class GFile __near *,class GMemoryHeap __near *,class GFxLog __near *,class GFxParseControl __near *)
// Source: json
//------------------------------------------------------------------------------
GFxStream *__thiscall GFxStream::GFxStream(GFxStream *this, IShaderDevice *a2, struct GMemoryHeap *a3, _LUID_AND_ATTRIBUTES *a4, _LUID_AND_ATTRIBUTES *a5)
{
  *this = (GFxStream)&GFxStream::`vftable';
  *(this + 4) = nullptr;
  GStringDH::GStringDH(this: (GStringDH *)this + 3, a2: a3);
  *(this + 15) = (GFxStream)(this + 17);
  *(this + 16) = (GFxStream)512;
  GFxStream::Initialize(this, a2, a3: a4, a4: a5);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E28C0
// Name: public: GFxStream::GFxStream(unsigned char const __near *,unsigned int,class GMemoryHeap __near *,class GFxLog __near *,class GFxParseControl __near *)
// Source: json
//------------------------------------------------------------------------------
GFxStream *__thiscall GFxStream::GFxStream(GFxStream *this, _LUID_AND_ATTRIBUTES *a2, _LUID_AND_ATTRIBUTES *bufSize, struct GMemoryHeap *a4, _LUID_AND_ATTRIBUTES *a5, _LUID_AND_ATTRIBUTES *a6)
{
  IShaderAPI *v7; // ecx
  _LUID_AND_ATTRIBUTES *LowPart; // eax
  _LUID_AND_ATTRIBUTES *v9; // eax

  *this = (GFxStream)&GFxStream::`vftable';
  *(this + 4) = nullptr;
  GStringDH::GStringDH(this: (GStringDH *)this + 3, a2: a4);
  *(this + 15) = (GFxStream)a2;
  if ( a2 != nullptr )
    *(this + 16) = (GFxStream)bufSize;
  else
    *(this + 16) = nullptr;
  v7 = (IShaderAPI *)*(this + 4);
  if ( v7 != nullptr )
    GRefCountImpl::Release(this: v7);
  *(this + 4) = nullptr;
  *(this + 1) = (GFxStream)a5;
  *(this + 2) = (GFxStream)a6;
  if ( a6 != nullptr )
    LowPart = (_LUID_AND_ATTRIBUTES *)a6[1].Luid.LowPart;
  else
    LowPart = nullptr;
  *(this + 3) = (GFxStream)LowPart;
  *((_WORD *)this + 10) = 0;
  GString::Clear(this: (GString *)this + 6);
  v9 = (_LUID_AND_ATTRIBUTES *)*(this + 16);
  *(this + 12) = (GFxStream)v9;
  *(this + 13) = (GFxStream)v9;
  *(this + 10) = nullptr;
  *(this + 8) = nullptr;
  *(this + 9) = nullptr;
  *(this + 11) = nullptr;
  *((_BYTE *)this + 56) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E2950
// Name: public: unsigned int GFxStream::ReadUInt(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxStream::ReadUInt(GFxStream *this, signed int value)
{
  int v2; // edi
  int v3; // ebx
  unsigned __int8 v5; // al
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  char v10; // cl
  unsigned __int8 v12; // dl
  char v13; // cl

  v2 = value;
  v3 = 0;
  if ( value <= 0 )
    return v3;
  while ( 1 )
  {
    v5 = *((_BYTE *)this + 21);
    if ( v5 == 0 )
    {
      v8 = (char *)*(this + 12) - (char *)*(this + 11);
      *((_BYTE *)this + 21) = 0;
      if ( v8 < 1 )
        GFxStream::PopulateBuffer((int)this, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)1);
      v9 = (int)*(this + 11);
      v10 = *((_BYTE *)&(**(this + 15))[0].Luid.LowPart + v9);
      *(this + 11) = (GFxStream)(v9 + 1);
      *((_BYTE *)this + 20) = v10;
      *((_BYTE *)this + 21) = 8;
      goto LABEL_8;
    }
    if ( v2 < v5 )
      break;
    v6 = v2 - v5;
    v7 = *((unsigned __int8 *)this + 20) << (v2 - v5);
    v2 = v6;
    *((_BYTE *)this + 21) = 0;
    v3 |= v7;
LABEL_8:
    if ( v2 <= 0 )
      return v3;
  }
  v12 = *((_BYTE *)this + 20);
  v13 = *((_BYTE *)this + 21) - v2;
  *((_BYTE *)this + 21) = v13;
  *((_BYTE *)this + 20) = v12 & ((1 << v13) - 1);
  return (v12 >> v13) | v3;
}

//------------------------------------------------------------------------------
// Address: 0x100E29F0
// Name: public: unsigned int GFxStream::ReadUInt1(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxStream::ReadUInt1(IShaderDeviceMgr *this)
{
  char v2; // al
  int v3; // eax
  unsigned __int8 v4; // cl
  int result; // eax
  char v6; // dl

  v2 = *((_BYTE *)this + 21);
  if ( v2 != 0 )
  {
    v6 = v2 - 1;
    *((_BYTE *)this + 21) = v2 - 1;
    result = *((unsigned __int8 *)this + 20) >> (v2 - 1);
    *((_BYTE *)this + 20) &= (1 << v6) - 1;
  }
  else
  {
    *((_BYTE *)this + 21) = 0;
    if ( *((_DWORD *)this + 12) - *((_DWORD *)this + 11) < 1 )
      GFxStream::PopulateBuffer((int)this, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)1);
    v3 = *((_DWORD *)this + 11);
    v4 = *(_BYTE *)(v3 + *((_DWORD *)this + 15));
    *((_DWORD *)this + 11) = v3 + 1;
    *((_BYTE *)this + 21) = 7;
    *((_BYTE *)this + 20) = v4 & 0x7F;
    return v4 >> 7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E2A50
// Name: public: int GFxStream::ReadSInt(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxStream::ReadSInt(GFxStream *this, const IShaderDeviceMgr *result)
{
  unsigned int UInt; // eax

  UInt = GFxStream::ReadUInt(this, value: (signed int)result);
  if ( ((1 << ((_BYTE)result - 1)) & UInt) != 0 )
    UInt |= -1 << (char)result;
  return UInt;
}

//------------------------------------------------------------------------------
// Address: 0x100E2A80
// Name: public: bool GFxStream::ReadStringWithLength(class GString __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxStream::ReadStringWithLength(GFxStream *this, CUtlMemory<CImagePacker,int> *a2)
{
  int v3; // eax
  int v4; // eax
  unsigned __int8 v5; // cl
  _DWORD v7[2]; // [esp+4h] [ebp-8h] BYREF

  v3 = (char *)*(this + 12) - (char *)*(this + 11);
  *((_BYTE *)this + 21) = 0;
  if ( v3 < 1 )
    GFxStream::PopulateBuffer((int)this, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)1);
  v4 = (int)*(this + 11);
  v5 = *((_BYTE *)&(**(this + 15))[0].Luid.LowPart + v4);
  *(this + 11) = (GFxStream)(v4 + 1);
  if ( v5 != 0 )
  {
    v7[0] = &`GFxStream::ReadStringWithLength'::`2'::StringReader::`vftable';
    v7[1] = this;
    GString::AssignString(this: a2, a2: (int)v7, size: v5);
    return 1;
  }
  else
  {
    GString::Clear(this: (GString *)a2);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2AF0
// Name: _GFxStream::ReadStringWithLength_::_2_::StringReader::InitString
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxStream::ReadStringWithLength_::_2_::StringReader::InitString(int *this, int a2, unsigned int a3)
{
  unsigned int i; // edi
  int v4; // esi
  int v5; // ecx
  int v6; // eax
  char v7; // cl
  int result; // eax

  for ( i = 0; i < a3; ++i )
  {
    v4 = *(this + 1);
    v5 = *(_DWORD *)(v4 + 48) - *(_DWORD *)(v4 + 44);
    *(_BYTE *)(v4 + 21) = 0;
    if ( v5 < 1 )
      GFxStream::PopulateBuffer(this: v4, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)1);
    v6 = *(_DWORD *)(v4 + 44);
    v7 = *(_BYTE *)(v6 + *(_DWORD *)(v4 + 60));
    *(_DWORD *)(v4 + 44) = v6 + 1;
    result = a2;
    *(_BYTE *)(i + a2) = v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E2B50
// Name: public: char __near * GFxStream::ReadStringWithLength(class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStream::ReadStringWithLength(IShaderDeviceMgr *this, char *buffer)
{
  int v3; // eax
  int v4; // eax
  unsigned __int8 v5; // cl
  int v6; // ebx
  int (__thiscall *v7)(char *, int, int *); // edx
  int v8; // edx
  int v9; // edi
  int v10; // eax
  int v11; // eax
  char v12; // cl
  int v13; // [esp+8h] [ebp-4h] BYREF
  char *buffera; // [esp+14h] [ebp+8h]

  v3 = *((_DWORD *)this + 12) - *((_DWORD *)this + 11);
  *((_BYTE *)this + 21) = 0;
  if ( v3 < 1 )
    GFxStream::PopulateBuffer((int)this, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)1);
  v4 = *((_DWORD *)this + 11);
  v5 = *(_BYTE *)(v4 + *((_DWORD *)this + 15));
  v6 = v5;
  *((_DWORD *)this + 11) = v4 + 1;
  if ( v5 != 0 )
  {
    v7 = *(int (__thiscall **)(char *, int, int *))(*(_DWORD *)buffer + 40);
    v13 = 2;
    v8 = v7(a1: buffer, a2: v5 + 1, a3: &v13);
    v9 = 0;
    for ( buffera = (char *)v8; v9 < v6; ++v9 )
    {
      v10 = *((_DWORD *)this + 12) - *((_DWORD *)this + 11);
      *((_BYTE *)this + 21) = 0;
      if ( v10 < 1 )
      {
        GFxStream::PopulateBuffer((int)this, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)1);
        v8 = (int)buffera;
      }
      v11 = *((_DWORD *)this + 11);
      v12 = *(_BYTE *)(v11 + *((_DWORD *)this + 15));
      *((_DWORD *)this + 11) = v11 + 1;
      *(_BYTE *)(v9 + v8) = v12;
    }
    *(_BYTE *)(v9 + v8) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2BF0
// Name: public: enum GFxTagType GFxStream::OpenTag(struct GFxTagInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStream::OpenTag(IShaderDeviceMgr *this, IShaderDeviceDependentObject *pTagInfo)
{
  int v3; // eax
  int v4; // edx
  int v5; // eax
  int v6; // ebx
  IShaderDeviceDependentObject_vtbl *v7; // edi
  int v8; // ebx
  int v9; // edx
  int v10; // edx
  IShaderDeviceDependentObject_vtbl *tagOffset; // [esp+Ch] [ebp-4h]

  v3 = *((_DWORD *)this + 12);
  v4 = *((_DWORD *)this + 11);
  tagOffset = (IShaderDeviceDependentObject_vtbl *)(v4 + *((_DWORD *)this + 13) - v3);
  *((_BYTE *)this + 21) = 0;
  if ( v3 - v4 < 2 )
    GFxStream::PopulateBuffer((int)this, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v5 = *((_DWORD *)this + 11);
  v6 = *(unsigned __int16 *)(*((_DWORD *)this + 15) + v5);
  v7 = (IShaderDeviceDependentObject_vtbl *)(v6 & 0x3F);
  v8 = v6 >> 6;
  *((_DWORD *)this + 11) = v5 + 2;
  if ( v7 == (IShaderDeviceDependentObject_vtbl *)63 )
  {
    v9 = *((_DWORD *)this + 12) - (v5 + 2);
    *((_BYTE *)this + 21) = 0;
    if ( v9 < 4 )
      GFxStream::PopulateBuffer((int)this, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
    v10 = *((_DWORD *)this + 11);
    v7 = (IShaderDeviceDependentObject_vtbl *)(*(unsigned __int8 *)(v10 + *((_DWORD *)this + 15))
                                             | ((((*(unsigned __int8 *)(*((_DWORD *)this + 15) + v10 + 2)
                                                 | (*(unsigned __int8 *)(*((_DWORD *)this + 15) + v10 + 3) << 8)) << 8)
                                               | *(unsigned __int8 *)(v10 + *((_DWORD *)this + 15) + 1)) << 8));
    *((_DWORD *)this + 11) = v10 + 4;
  }
  pTagInfo[1].__vftable = tagOffset;
  pTagInfo->__vftable = (IShaderDeviceDependentObject_vtbl *)v8;
  pTagInfo[2].__vftable = v7;
  pTagInfo[3].__vftable = (IShaderDeviceDependentObject_vtbl *)(*((_DWORD *)this + 11)
                                                              + *((_DWORD *)this + 13)
                                                              - *((_DWORD *)this + 12));
  if ( (*(_BYTE *)(this + 3) & 1) != 0 )
    GFxLogBase<GFxStream>::LogParse(
      (tagBITMAPINFOHEADER *)this,
      a2: (int)"---------------Tag type = %d, Tag length = %d, offset = %d\n",
      v8,
      v7,
      tagOffset);
  *((_DWORD *)this + (*((_DWORD *)this + 10))++ + 8) = (char *)v7
                                                     + *((_DWORD *)this + 11)
                                                     + *((_DWORD *)this + 13)
                                                     - *((_DWORD *)this + 12);
}

//------------------------------------------------------------------------------
// Address: 0x100E2CF0
// Name: public: enum GFxTagType GFxStream::OpenTag(void)
// Source: json
//------------------------------------------------------------------------------
const IShaderDeviceMgr *__thiscall GFxStream::OpenTag(int this)
{
  int v2; // eax
  int v3; // eax
  int v4; // ebx
  int v5; // edi
  int v6; // ebx
  int v7; // edx
  int v8; // edx

  v2 = *(_DWORD *)(this + 48) - *(_DWORD *)(this + 44);
  *(_BYTE *)(this + 21) = 0;
  if ( v2 < 2 )
    GFxStream::PopulateBuffer(this, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v3 = *(_DWORD *)(this + 44);
  v4 = *(unsigned __int16 *)(*(_DWORD *)(this + 60) + v3);
  v5 = v4 & 0x3F;
  v6 = v4 >> 6;
  *(_DWORD *)(this + 44) = v3 + 2;
  if ( v5 == 63 )
  {
    v7 = *(_DWORD *)(this + 48) - (v3 + 2);
    *(_BYTE *)(this + 21) = 0;
    if ( v7 < 4 )
      GFxStream::PopulateBuffer(this, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
    v8 = *(_DWORD *)(this + 44);
    v5 = *(unsigned __int8 *)(v8 + *(_DWORD *)(this + 60))
       | ((((*(unsigned __int8 *)(*(_DWORD *)(this + 60) + v8 + 2)
           | (*(unsigned __int8 *)(*(_DWORD *)(this + 60) + v8 + 3) << 8)) << 8)
         | *(unsigned __int8 *)(v8 + *(_DWORD *)(this + 60) + 1)) << 8);
    *(_DWORD *)(this + 44) = v8 + 4;
  }
  if ( (*(_BYTE *)(this + 12) & 1) != 0 )
    GFxLogBase<GFxStream>::LogParse(
      (tagBITMAPINFOHEADER *)this,
      a2: (int)"---------------Tag type = %d, Tag length = %d\n",
      v6,
      v5);
  *(_DWORD *)(this + 4 * (*(_DWORD *)(this + 40))++ + 32) = v5
                                                          + *(_DWORD *)(this + 44)
                                                          + *(_DWORD *)(this + 52)
                                                          - *(_DWORD *)(this + 48);
  return (const IShaderDeviceMgr *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x100E2DC0
// Name: public: void GFxStream::ReadMatrix(class GMatrix2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStream::ReadMatrix(GFxStream *this, struct GMatrix2D *a2)
{
  signed int UInt; // edi
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  signed int v7; // edi
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  signed int v11; // eax
  signed int v12; // edi
  int v13; // eax
  int v14; // ebx
  int v15; // eax
  int v16; // [esp+Ch] [ebp-4h]
  int v17; // [esp+Ch] [ebp-4h]
  int v18; // [esp+Ch] [ebp-4h]
  int v19; // [esp+Ch] [ebp-4h]
  int v20; // [esp+Ch] [ebp-4h]
  int v21; // [esp+Ch] [ebp-4h]

  *((_BYTE *)this + 21) = 0;
  GMatrix2D::SetIdentity(this: (float *)a2);
  if ( GFxStream::ReadUInt1((IShaderDeviceMgr *)this) != 0 )
  {
    UInt = GFxStream::ReadUInt(this, value: 5);
    v4 = GFxStream::ReadUInt(this, value: UInt);
    v5 = 1 << (UInt - 1);
    v16 = v4;
    if ( (v5 & v4) != 0 )
      v16 = (-1 << UInt) | v4;
    a2->M_[0][0] = (double)v16 * 0.0000152587890625;
    v6 = GFxStream::ReadUInt(this, value: UInt);
    v17 = v6;
    if ( (v5 & v6) != 0 )
      v17 = (-1 << UInt) | v6;
    a2->M_[1][1] = (double)v17 * 0.0000152587890625;
  }
  if ( GFxStream::ReadUInt1((IShaderDeviceMgr *)this) != 0 )
  {
    v7 = GFxStream::ReadUInt(this, value: 5);
    v8 = GFxStream::ReadUInt(this, value: v7);
    v9 = 1 << (v7 - 1);
    v18 = v8;
    if ( (v9 & v8) != 0 )
      v18 = (-1 << v7) | v8;
    a2->M_[1][0] = (double)v18 * 0.0000152587890625;
    v10 = GFxStream::ReadUInt(this, value: v7);
    v19 = v10;
    if ( (v9 & v10) != 0 )
      v19 = (-1 << v7) | v10;
    a2->M_[0][1] = (double)v19 * 0.0000152587890625;
  }
  v11 = GFxStream::ReadUInt(this, value: 5);
  v12 = v11;
  if ( v11 > 0 )
  {
    v13 = GFxStream::ReadUInt(this, value: v11);
    v14 = 1 << (v12 - 1);
    v20 = v13;
    if ( (v14 & v13) != 0 )
      v20 = (-1 << v12) | v13;
    a2->M_[0][2] = (float)v20;
    v15 = GFxStream::ReadUInt(this, value: v12);
    v21 = v15;
    if ( (v14 & v15) != 0 )
      v21 = (-1 << v12) | v15;
    a2->M_[1][2] = (float)v21;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2F30
// Name: public: void GFxStream::ReadCxformRgb(class GRenderer::Cxform __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStream::ReadCxformRgb(GFxStream *this, struct GRenderer::Cxform *a2)
{
  int UInt1; // ebx
  signed int UInt; // eax
  signed int v5; // esi
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  float *v10; // eax
  double v11; // st7
  int v12; // eax
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  unsigned int hasAdd; // [esp+Ch] [ebp-8h]
  int v17; // [esp+10h] [ebp-4h]
  int v18; // [esp+10h] [ebp-4h]
  int v19; // [esp+10h] [ebp-4h]
  int v20; // [esp+10h] [ebp-4h]
  int v21; // [esp+10h] [ebp-4h]
  int v22; // [esp+10h] [ebp-4h]

  *((_BYTE *)this + 21) = 0;
  hasAdd = GFxStream::ReadUInt1((IShaderDeviceMgr *)this);
  UInt1 = GFxStream::ReadUInt1((IShaderDeviceMgr *)this);
  UInt = GFxStream::ReadUInt(this, value: 4);
  v5 = UInt;
  if ( UInt1 != 0 )
  {
    v6 = GFxStream::ReadUInt(this, value: UInt);
    v7 = 1 << (v5 - 1);
    v17 = v6;
    if ( (v7 & v6) != 0 )
      v17 = (-1 << v5) | v6;
    a2->M_[0][0] = (double)v17 * 0.00390625;
    v8 = GFxStream::ReadUInt(this, value: v5);
    v18 = v8;
    if ( (v7 & v8) != 0 )
      v18 = (-1 << v5) | v8;
    a2->M_[1][0] = (double)v18 * 0.00390625;
    v9 = GFxStream::ReadUInt(this, value: v5);
    v19 = v9;
    if ( (v7 & v9) != 0 )
      v19 = (-1 << v5) | v9;
    v10 = (float *)a2;
    a2->M_[2][0] = (double)v19 * 0.00390625;
    v11 = 1.0;
  }
  else
  {
    v11 = 1.0;
    v10 = (float *)a2;
    a2->M_[0][0] = 1.0;
    a2->M_[1][0] = 1.0;
    a2->M_[2][0] = 1.0;
  }
  v10[6] = v11;
  if ( hasAdd != 0 )
  {
    v12 = GFxStream::ReadUInt(this, value: v5);
    v13 = 1 << (v5 - 1);
    v20 = v12;
    if ( (v13 & v12) != 0 )
      v20 = (-1 << v5) | v12;
    a2->M_[0][1] = (float)v20;
    v14 = GFxStream::ReadUInt(this, value: v5);
    v21 = v14;
    if ( (v13 & v14) != 0 )
      v21 = (-1 << v5) | v14;
    a2->M_[1][1] = (float)v21;
    v15 = GFxStream::ReadUInt(this, value: v5);
    v22 = v15;
    if ( (v13 & v15) != 0 )
      v22 = (-1 << v5) | v15;
    a2->M_[2][1] = (float)v22;
    a2->M_[3][1] = 1.0;
  }
  else
  {
    v10[1] = 0.0;
    v10[3] = 0.0;
    v10[5] = 0.0;
    v10[7] = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E30B0
// Name: public: void GFxStream::ReadCxformRgba(class GRenderer::Cxform __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStream::ReadCxformRgba(GFxStream *this, struct GRenderer::Cxform *a2)
{
  int UInt1; // ebx
  signed int UInt; // eax
  signed int v5; // esi
  int v6; // eax
  float *v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  double v11; // st7
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  unsigned int hasAdd; // [esp+Ch] [ebp-Ch]
  int v17; // [esp+10h] [ebp-8h]
  int v18; // [esp+14h] [ebp-4h]
  int v19; // [esp+14h] [ebp-4h]
  struct GRenderer::Cxform *v20; // [esp+20h] [ebp+8h]
  struct GRenderer::Cxform *v21; // [esp+20h] [ebp+8h]
  struct GRenderer::Cxform *v22; // [esp+20h] [ebp+8h]
  struct GRenderer::Cxform *v23; // [esp+20h] [ebp+8h]
  struct GRenderer::Cxform *v24; // [esp+20h] [ebp+8h]
  struct GRenderer::Cxform *v25; // [esp+20h] [ebp+8h]
  struct GRenderer::Cxform *v26; // [esp+20h] [ebp+8h]

  *((_BYTE *)this + 21) = 0;
  hasAdd = GFxStream::ReadUInt1((IShaderDeviceMgr *)this);
  UInt1 = GFxStream::ReadUInt1((IShaderDeviceMgr *)this);
  UInt = GFxStream::ReadUInt(this, value: 4);
  v5 = UInt;
  if ( UInt1 != 0 )
  {
    v6 = GFxStream::ReadUInt(this, value: UInt);
    v17 = v6;
    v18 = 1 << (v5 - 1);
    if ( (v18 & v6) != 0 )
      v17 = (-1 << v5) | v6;
    v7 = (float *)a2;
    a2->M_[0][0] = (double)v17 * 0.00390625;
    v8 = GFxStream::ReadUInt(this, value: v5);
    v20 = (struct GRenderer::Cxform *)v8;
    if ( (v8 & v18) != 0 )
      v20 = (struct GRenderer::Cxform *)((-1 << v5) | v8);
    v7[2] = (double)(int)v20 * 0.00390625;
    v9 = GFxStream::ReadUInt(this, value: v5);
    v21 = (struct GRenderer::Cxform *)v9;
    if ( (v9 & v18) != 0 )
      v21 = (struct GRenderer::Cxform *)((-1 << v5) | v9);
    v7[4] = (double)(int)v21 * 0.00390625;
    v10 = GFxStream::ReadUInt(this, value: v5);
    v22 = (struct GRenderer::Cxform *)v10;
    if ( (v10 & v18) != 0 )
      v22 = (struct GRenderer::Cxform *)((-1 << v5) | v10);
    v11 = (double)(int)v22 * 0.00390625;
  }
  else
  {
    v11 = 1.0;
    v7 = (float *)a2;
    a2->M_[0][0] = 1.0;
    a2->M_[1][0] = 1.0;
    a2->M_[2][0] = 1.0;
  }
  v7[6] = v11;
  if ( hasAdd != 0 )
  {
    v12 = GFxStream::ReadUInt(this, value: v5);
    v23 = (struct GRenderer::Cxform *)v12;
    v19 = 1 << (v5 - 1);
    if ( (v19 & v12) != 0 )
      v23 = (struct GRenderer::Cxform *)((-1 << v5) | v12);
    v7[1] = (float)(int)v23;
    v13 = GFxStream::ReadUInt(this, value: v5);
    v24 = (struct GRenderer::Cxform *)v13;
    if ( (v13 & v19) != 0 )
      v24 = (struct GRenderer::Cxform *)((-1 << v5) | v13);
    v7[3] = (float)(int)v24;
    v14 = GFxStream::ReadUInt(this, value: v5);
    v25 = (struct GRenderer::Cxform *)v14;
    if ( (v14 & v19) != 0 )
      v25 = (struct GRenderer::Cxform *)((-1 << v5) | v14);
    v7[5] = (float)(int)v25;
    v15 = GFxStream::ReadUInt(this, value: v5);
    v26 = (struct GRenderer::Cxform *)v15;
    if ( (v15 & v19) != 0 )
      v26 = (struct GRenderer::Cxform *)((-1 << v5) | v15);
    v7[7] = (float)(int)v26;
  }
  else
  {
    v7[1] = 0.0;
    v7[3] = 0.0;
    v7[5] = 0.0;
    v7[7] = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E3260
// Name: public: void GFxStream::ReadRect(class GRect<float> __near *)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GFxStream::ReadRect(GFxStream *this, float *a2)
{
  signed int UInt; // esi
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  float *result; // eax
  double v9; // st7
  int v10; // [esp+Ch] [ebp-4h]
  int v11; // [esp+Ch] [ebp-4h]
  int v12; // [esp+Ch] [ebp-4h]

  *((_BYTE *)this + 21) = 0;
  UInt = GFxStream::ReadUInt(this, value: 5);
  v4 = GFxStream::ReadUInt(this, value: UInt);
  v5 = 1 << (UInt - 1);
  v10 = v4;
  if ( (v5 & v4) != 0 )
    v10 = (-1 << UInt) | v4;
  *a2 = (float)v10;
  v6 = GFxStream::ReadUInt(this, value: UInt);
  v11 = v6;
  if ( (v5 & v6) != 0 )
    v11 = (-1 << UInt) | v6;
  a2[2] = (float)v11;
  v7 = GFxStream::ReadUInt(this, value: UInt);
  v12 = v7;
  if ( (v5 & v7) != 0 )
    v12 = (-1 << UInt) | v7;
  a2[1] = (float)v12;
  result = (float *)GFxStream::ReadUInt(this, value: UInt);
  if ( (v5 & (unsigned int)result) != 0 )
  {
    v9 = (double)(int)((-1 << UInt) | (unsigned int)result);
    result = a2;
  }
  else
  {
    v9 = (double)(int)result;
  }
  a2[3] = v9;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E3330
// Name: public: void GFxStream::ReadRgb(class GColor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStream::ReadRgb(GFxStream *this, struct GColor *a2)
{
  int v3; // eax
  int v4; // eax
  unsigned __int8 v5; // cl
  int v6; // edx
  int v7; // eax
  unsigned __int8 v8; // cl
  int v9; // edx
  int v10; // eax
  unsigned __int8 v11; // cl

  v3 = (char *)*(this + 12) - (char *)*(this + 11);
  *((_BYTE *)this + 21) = 0;
  if ( v3 < 1 )
    GFxStream::PopulateBuffer((int)this, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)1);
  v4 = (int)*(this + 11);
  v5 = *((_BYTE *)&(**(this + 15))[0].Luid.LowPart + v4);
  *(this + 11) = (GFxStream)(v4 + 1);
  a2->Channels.Red = v5;
  v6 = (char *)*(this + 12) - (char *)*(this + 11);
  *((_BYTE *)this + 21) = 0;
  if ( v6 < 1 )
    GFxStream::PopulateBuffer((int)this, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)1);
  v7 = (int)*(this + 11);
  v8 = *((_BYTE *)&(**(this + 15))[0].Luid.LowPart + v7);
  *(this + 11) = (GFxStream)(v7 + 1);
  a2->Channels.Green = v8;
  v9 = (char *)*(this + 12) - (char *)*(this + 11);
  *((_BYTE *)this + 21) = 0;
  if ( v9 < 1 )
    GFxStream::PopulateBuffer((int)this, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)1);
  v10 = (int)*(this + 11);
  v11 = *((_BYTE *)&(**(this + 15))[0].Luid.LowPart + v10);
  *(this + 11) = (GFxStream)(v10 + 1);
  a2->Channels.Blue = v11;
  a2->Channels.Alpha = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100E33C0
// Name: public: void GFxStream::ReadRgba(class GColor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStream::ReadRgba(GFxStream *this, struct GColor *a2)
{
  int v3; // eax
  int v4; // eax
  unsigned __int8 v5; // cl

  GFxStream::ReadRgb(this, a2);
  v3 = (char *)*(this + 12) - (char *)*(this + 11);
  *((_BYTE *)this + 21) = 0;
  if ( v3 < 1 )
    GFxStream::PopulateBuffer((int)this, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)1);
  v4 = (int)*(this + 11);
  v5 = *((_BYTE *)&(**(this + 15))[0].Luid.LowPart + v4);
  *(this + 11) = (GFxStream)(v4 + 1);
  a2->Channels.Alpha = v5;
}

//------------------------------------------------------------------------------
// Address: 0x100E3400
// Name: public: void GFxStream::LogParseClass(class GColor)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStream::LogParseClass(GFxStream *this, struct GColor a2)
{
  char v3[512]; // [esp+4h] [ebp-204h] BYREF

  GColor::Format(this: &a2, pbuffer: v3);
  GFxLogBase<GFxStream>::LogParse((tagBITMAPINFOHEADER *)this, a2: (int)"%s", v3);
}

//------------------------------------------------------------------------------
// Address: 0x100E3450
// Name: public: void GFxStream::LogParseClass(class GRect<float> const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxStream::LogParseClass(
        tagBITMAPINFOHEADER *this,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *result)
{
  double v4; // [esp+0h] [ebp-22Ch]
  float v5; // [esp+24h] [ebp-208h]
  char destsize[512]; // [esp+28h] [ebp-204h] BYREF

  v5 = *(float *)&result->m_Memory.m_pMemory / 20.0;
  v4 = v5;
  G_sprintf(
    dest: (unsigned __int16)this,
    destsize,
    destsizea: 0x200u,
    format: "xmin = %g, ymin = %g, xmax = %g, ymax = %g\n",
    ap: SLOBYTE(v4));
  return GFxLogBase<GFxStream>::LogParse(this, a2: (int)"%s", destsize);
}

//------------------------------------------------------------------------------
// Address: 0x100E3500
// Name: public: void GFxStream::LogParseClass(class GRenderer::Cxform const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStream::LogParseClass(GFxStream *this, const struct GRenderer::Cxform *a2)
{
  char v3[512]; // [esp+4h] [ebp-204h] BYREF

  GRenderer::Cxform::Format(this: a2, pbuffer: v3);
  GFxLogBase<GFxStream>::LogParse((tagBITMAPINFOHEADER *)this, a2: (int)"%s", v3);
}

//------------------------------------------------------------------------------
// Address: 0x100E3550
// Name: public: void GFxStream::LogParseClass(class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxStream::LogParseClass(
        tagBITMAPINFOHEADER *this,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *result)
{
  char v4[512]; // [esp+4h] [ebp-204h] BYREF

  GMatrix2D::Format(this: result, pbuffer: v4);
  return GFxLogBase<GFxStream>::LogParse(this, a2: (int)"%s", v4);
}

//------------------------------------------------------------------------------
// Address: 0x100E35A0
// Name: public: void GFxStream::LogTagBytes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStream::LogTagBytes(GFxStream *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // edx
  int v5; // eax
  unsigned int v6; // ebx
  int i; // edi
  int v8; // eax
  _BYTE v9[16]; // [esp+8h] [ebp-14h]

  v2 = 0;
  GFxStream::GetTagEndPosition((IShaderDeviceMgr *)this);
  if ( (int)*(this + 13) + (char *)*(this + 11) - (char *)*(this + 12) < v3 )
  {
    do
    {
      v4 = (char *)*(this + 12) - (char *)*(this + 11);
      *((_BYTE *)this + 21) = 0;
      if ( v4 < 1 )
        GFxStream::PopulateBuffer((int)this, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)1);
      v5 = (int)*(this + 11);
      v6 = *((unsigned __int8 *)&(**(this + 15))[0].Luid.LowPart + v5);
      *(this + 11) = (GFxStream)(v5 + 1);
      GFxLogBase<GFxStream>::LogParse((tagBITMAPINFOHEADER *)this, a2: (int)"%02X", v6);
      if ( v6 < 0x20 || v6 > 0x7F )
        LOBYTE(v6) = 46;
      v9[v2++] = v6;
      if ( v2 < 16 )
      {
        GFxLogBase<GFxStream>::LogParse((tagBITMAPINFOHEADER *)this, a2: (int)" ");
      }
      else
      {
        GFxLogBase<GFxStream>::LogParse((tagBITMAPINFOHEADER *)this, a2: (int)"    ");
        for ( i = 0; i < 16; ++i )
          GFxLogBase<GFxStream>::LogParse((tagBITMAPINFOHEADER *)this, a2: (int)"%c", (char)v9[i]);
        GFxLogBase<GFxStream>::LogParse((tagBITMAPINFOHEADER *)this, a2: (int)"\n");
        v2 = 0;
      }
      GFxStream::GetTagEndPosition((IShaderDeviceMgr *)this);
    }
    while ( (int)*(this + 13) + (char *)*(this + 11) - (char *)*(this + 12) < v8 );
    if ( v2 > 0 )
      GFxLogBase<GFxStream>::LogParse((tagBITMAPINFOHEADER *)this, a2: (int)"\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E36B0
// Name: public: bool GFxStream::ReadString(class GString __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxStream::ReadString(GFxStream *this, CUtlMemory<CImagePacker,int> *a2)
{
  unsigned int v2; // edi
  GFxStream *v3; // ebx
  char *v4; // esi
  int v5; // eax
  _LUID_AND_ATTRIBUTES *v6; // eax
  char v7; // cl
  unsigned int v8; // ebx
  unsigned int v9; // edi
  char *v10; // eax
  unsigned int v11; // eax
  char *v12; // eax
  unsigned int v13; // edi
  char *v15; // [esp+Ch] [ebp-18h] BYREF
  unsigned int v16; // [esp+10h] [ebp-14h]
  unsigned int v17; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch] BYREF
  GFxStream *v19; // [esp+1Ch] [ebp-8h]
  char v20; // [esp+23h] [ebp-1h]

  v2 = 0;
  v3 = this;
  v4 = nullptr;
  v19 = this;
  *((_BYTE *)this + 21) = 0;
  v15 = nullptr;
  v16 = 0;
  v17 = 0;
  while ( 1 )
  {
    v5 = (char *)v3[12] - (char *)v3[11];
    *((_BYTE *)v3 + 21) = 0;
    if ( v5 < 1 )
      GFxStream::PopulateBuffer(this: (int)v3, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)1);
    v6 = (_LUID_AND_ATTRIBUTES *)v3[11];
    v20 = *((_BYTE *)&(*v3[15])[0].Luid.LowPart + (_DWORD)v6);
    v7 = v20;
    v3[11] = (GFxStream)((char *)&v6->Luid.LowPart + 1);
    if ( v7 == 0 )
      break;
    v8 = v2 + 1;
    if ( v2 + 1 >= v2 )
    {
      if ( v8 >= v17 )
      {
        v11 = v8 + (v8 >> 2);
        if ( v11 != 0 )
        {
          v9 = 4 * ((v11 + 3) >> 2);
          if ( v4 != nullptr )
          {
            v10 = (char *)GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v4, a3: v9);
          }
          else
          {
            v18 = 2;
            v10 = (char *)((int (__stdcall *)(unsigned int, int *))GMemory::pGlobalHeap->Alloc_2)(a1: v9, a2: &v18);
          }
          goto LABEL_21;
        }
        if ( v4 != nullptr )
        {
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
          v4 = nullptr;
        }
LABEL_17:
        v17 = 0;
      }
    }
    else if ( v8 < v17 >> 1 )
    {
      if ( v2 != -1 )
      {
        v9 = 4 * ((v2 + 4) >> 2);
        if ( v4 != nullptr )
        {
          v10 = (char *)((int (__stdcall *)(char *, unsigned int))GMemory::pGlobalHeap->Realloc)(
                          a1: v4,
                          a2: 4 * ((v8 + 3) >> 2));
        }
        else
        {
          v18 = 2;
          v10 = (char *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 4 * ((v8 + 3) >> 2), a3: &v18);
        }
LABEL_21:
        v4 = v10;
        v17 = v9;
        goto LABEL_22;
      }
      if ( v4 == nullptr )
        goto LABEL_17;
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
      v4 = nullptr;
      v17 = 0;
    }
LABEL_22:
    v12 = &v4[v8 - 1];
    v16 = v8;
    v2 = v8;
    v3 = v19;
    if ( v12 != nullptr )
      *v12 = v20;
  }
  v13 = v2 + 1;
  v15 = v4;
  if ( v13 >= v16 )
  {
    if ( v13 >= v17 )
    {
      GArrayDataBase<unsigned char,GAllocatorGH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
        this: (void **)&v15,
        pheapAddr: (ButtonCode_t)&v15,
        newCapacity: v13 + (v13 >> 2));
LABEL_29:
      v4 = v15;
    }
  }
  else if ( v13 < v17 >> 1 )
  {
    GArrayDataBase<unsigned char,GAllocatorGH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
      this: (void **)&v15,
      pheapAddr: (ButtonCode_t)&v15,
      newCapacity: v13);
    goto LABEL_29;
  }
  if ( &v4[v13] != (char *)1 )
    v4[v13 - 1] = 0;
  if ( v13 != 0 )
  {
    GString::AssignString(this: a2, src: (unsigned __int8 *)v4, size: v13 - 1);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
    return 1;
  }
  else
  {
    GString::Clear(this: (GString *)a2);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E3870
// Name: public: char __near * GFxStream::ReadString(class GMemoryHeap __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxStream::ReadString(IShaderDeviceMgr *this, int a2)
{
  unsigned int v2; // edi
  IShaderDeviceMgr *v3; // ebx
  char *v4; // esi
  int v5; // eax
  IShaderDeviceMgr_vtbl *v6; // eax
  char v7; // cl
  unsigned int v8; // ebx
  unsigned int v9; // edi
  char *v10; // eax
  unsigned int v11; // eax
  char *v12; // eax
  unsigned int v13; // edi
  int (__thiscall *v14)(int, unsigned int, int *); // edx
  unsigned __int8 *v15; // ebx
  char *v16; // [esp+Ch] [ebp-18h] BYREF
  unsigned int v17; // [esp+10h] [ebp-14h]
  unsigned int v18; // [esp+14h] [ebp-10h]
  int v19; // [esp+18h] [ebp-Ch] BYREF
  IShaderDeviceMgr *v20; // [esp+1Ch] [ebp-8h]
  char c; // [esp+23h] [ebp-1h]

  v2 = 0;
  v3 = this;
  v4 = nullptr;
  v20 = this;
  *((_BYTE *)this + 21) = 0;
  v16 = nullptr;
  v17 = 0;
  v18 = 0;
  while ( 1 )
  {
    v5 = (char *)v3[12].__vftable - (char *)v3[11].__vftable;
    BYTE1(v3[5].__vftable) = 0;
    if ( v5 < 1 )
      GFxStream::PopulateBuffer(this: (int)v3, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)1);
    v6 = v3[11].__vftable;
    c = *((_BYTE *)&v6->Connect + (unsigned int)v3[15].__vftable);
    v7 = c;
    v3[11].__vftable = (IShaderDeviceMgr_vtbl *)((char *)&v6->Connect + 1);
    if ( v7 == 0 )
      break;
    v8 = v2 + 1;
    if ( v2 + 1 >= v2 )
    {
      if ( v8 >= v18 )
      {
        v11 = v8 + (v8 >> 2);
        if ( v11 != 0 )
        {
          v9 = 4 * ((v11 + 3) >> 2);
          if ( v4 != nullptr )
          {
            v10 = (char *)GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v4, a3: v9);
          }
          else
          {
            v19 = 2;
            v10 = (char *)((int (__stdcall *)(unsigned int, int *))GMemory::pGlobalHeap->Alloc_2)(a1: v9, a2: &v19);
          }
          goto LABEL_21;
        }
        if ( v4 != nullptr )
        {
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
          v4 = nullptr;
        }
LABEL_17:
        v18 = 0;
      }
    }
    else if ( v8 < v18 >> 1 )
    {
      if ( v2 != -1 )
      {
        v9 = 4 * ((v2 + 4) >> 2);
        if ( v4 != nullptr )
        {
          v10 = (char *)((int (__stdcall *)(char *, unsigned int))GMemory::pGlobalHeap->Realloc)(
                          a1: v4,
                          a2: 4 * ((v8 + 3) >> 2));
        }
        else
        {
          v19 = 2;
          v10 = (char *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 4 * ((v8 + 3) >> 2), a3: &v19);
        }
LABEL_21:
        v4 = v10;
        v18 = v9;
        goto LABEL_22;
      }
      if ( v4 == nullptr )
        goto LABEL_17;
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
      v4 = nullptr;
      v18 = 0;
    }
LABEL_22:
    v12 = &v4[v8 - 1];
    v17 = v8;
    v2 = v8;
    v3 = v20;
    if ( v12 != nullptr )
      *v12 = c;
  }
  v13 = v2 + 1;
  v16 = v4;
  if ( v13 >= v17 )
  {
    if ( v13 >= v18 )
    {
      GArrayDataBase<unsigned char,GAllocatorGH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
        this: (void **)&v16,
        pheapAddr: (ButtonCode_t)&v16,
        newCapacity: v13 + (v13 >> 2));
LABEL_29:
      v4 = v16;
    }
  }
  else if ( v13 < v18 >> 1 )
  {
    GArrayDataBase<unsigned char,GAllocatorGH<unsigned char,2>,GArrayDefaultPolicy>::Reserve(
      this: (void **)&v16,
      pheapAddr: (ButtonCode_t)&v16,
      newCapacity: v13);
    goto LABEL_29;
  }
  if ( &v4[v13] != (char *)1 )
    v4[v13 - 1] = 0;
  if ( v13 != 0 )
  {
    v14 = *(int (__thiscall **)(int, unsigned int, int *))(*(_DWORD *)a2 + 40);
    v19 = 2;
    v15 = (unsigned __int8 *)v14(a1: a2, a2: v13, a3: &v19);
    memcpy(dst: v15, src: (unsigned __int8 *)v4, count: v13);
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
}
