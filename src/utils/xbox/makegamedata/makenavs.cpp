// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/makegamedata/makenavs.cpp
// Functions: 9
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040BB90
// Name: bool ProcessDwords(class CUtlBuffer __near &,class CUtlBuffer __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ProcessDwords(CUtlBuffer *source, CUtlBuffer *target, unsigned int count)
{
  unsigned int i; // esi
  int v5; // [esp-Ch] [ebp-110h]
  unsigned int list[64]; // [esp+4h] [ebp-100h] BYREF

  if ( count == 0 )
    return 1;
  CUtlBuffer::Get(this: source, pMem: list, size: 4 * count);
  if ( source->m_Error != 0 )
    return 0;
  for ( i = 0; i < count; ++i )
  {
    v5 = list[i];
    if ( (target->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: target, pFmt: "%u", v5);
    else
      CUtlBuffer::PutTypeBin<int>(this: target, src: v5);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040BC10
// Name: bool ProcessLadders(class CUtlBuffer __near &,class CUtlBuffer __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ProcessLadders(CUtlBuffer *source, CUtlBuffer *target)
{
  CUtlBuffer *v2; // ebx
  int UnsignedInt; // edi
  unsigned int i; // ebx
  int v6; // edi
  unsigned int j; // ebx
  int v8; // edi
  int pMem[64]; // [esp+Ch] [ebp-104h] BYREF
  int inputBuffer; // [esp+10Ch] [ebp-4h] BYREF
  CUtlBuffer *targeta; // [esp+11Ch] [ebp+Ch]

  v2 = source;
  UnsignedInt = CUtlBuffer::GetUnsignedInt(this: source);
  if ( (target->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: target, pFmt: "%u", UnsignedInt);
  else
    CUtlBuffer::PutTypeBin<int>(this: target, src: UnsignedInt);
  if ( UnsignedInt != 0 )
  {
    for ( targeta = (CUtlBuffer *)UnsignedInt; targeta != nullptr; targeta = (CUtlBuffer *)((char *)targeta - 1) )
    {
      CUtlBuffer::Get(this: v2, pMem, size: 40);
      if ( v2->m_Error == 0 )
      {
        for ( i = 0; i < 0xA; ++i )
        {
          v6 = pMem[i];
          if ( (target->m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: target, pFmt: "%u", pMem[i]);
          }
          else
          {
            inputBuffer = pMem[i];
            if ( CUtlBuffer::CheckPut(this: target, nSize: 4) )
            {
              if ( (*(_BYTE *)&target->m_Byteswap & 1) != 0 )
                CByteswap::SwapBufferToTargetEndian<unsigned int>(
                  this: &target->m_Byteswap,
                  outputBuffer: (int *)&target->m_Memory.m_pMemory[target->m_Put - target->m_nOffset],
                  &inputBuffer,
                  count: 1);
              else
                *(_DWORD *)&target->m_Memory.m_pMemory[target->m_Put - target->m_nOffset] = v6;
              target->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: target, nPut: target->m_Put);
            }
          }
        }
        v2 = source;
      }
      CUtlBuffer::Get(this: v2, pMem, size: 20);
      if ( v2->m_Error == 0 )
      {
        for ( j = 0; j < 5; ++j )
        {
          v8 = pMem[j];
          if ( (target->m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: target, pFmt: "%u", pMem[j]);
          }
          else
          {
            inputBuffer = pMem[j];
            if ( CUtlBuffer::CheckPut(this: target, nSize: 4) )
            {
              if ( (*(_BYTE *)&target->m_Byteswap & 1) != 0 )
                CByteswap::SwapBufferToTargetEndian<unsigned int>(
                  this: &target->m_Byteswap,
                  outputBuffer: (int *)&target->m_Memory.m_pMemory[target->m_Put - target->m_nOffset],
                  &inputBuffer,
                  count: 1);
              else
                *(_DWORD *)&target->m_Memory.m_pMemory[target->m_Put - target->m_nOffset] = v8;
              target->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: target, nPut: target->m_Put);
            }
          }
        }
        v2 = source;
      }
    }
  }
  return v2->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040BDB0
// Name: bool ProcessCustomData(class CUtlBuffer __near &,class CUtlBuffer __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ProcessCustomData(CUtlBuffer *source, CUtlBuffer *target, unsigned int subVersion)
{
  int UnsignedInt; // eax

  if ( subVersion >= 7 )
  {
    UnsignedInt = CUtlBuffer::GetUnsignedInt(this: source);
    if ( (target->m_Flags & 1) == 0 )
    {
      CUtlBuffer::PutTypeBin<int>(this: target, src: UnsignedInt);
      return source->m_Error == 0;
    }
    CUtlBuffer::Printf(this: target, pFmt: "%u", UnsignedInt);
  }
  return source->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040BE00
// Name: bool ProcessBaseDirectory(class CUtlBuffer __near &,class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ProcessBaseDirectory(CUtlBuffer *source, CUtlBuffer *target)
{
  unsigned __int16 UnsignedShort; // ax
  CUtlBuffer *v4; // esi
  int v5; // edi
  unsigned __int16 v6; // ax
  int v7; // edi
  char buffer[256]; // [esp+Ch] [ebp-100h] BYREF
  CUtlBuffer *sourcea; // [esp+114h] [ebp+8h]

  UnsignedShort = CUtlBuffer::GetUnsignedShort(this: source);
  v4 = target;
  v5 = UnsignedShort;
  if ( (target->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: target, pFmt: "%hu", UnsignedShort);
  else
    CUtlBuffer::PutTypeBin<short>(this: target, src: UnsignedShort);
  if ( v5 > 0 )
  {
    for ( sourcea = (CUtlBuffer *)v5; sourcea != nullptr; sourcea = (CUtlBuffer *)((char *)sourcea - 1) )
    {
      v6 = CUtlBuffer::GetUnsignedShort(this: source);
      v7 = v6;
      if ( (v4->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v4, pFmt: "%hu", v6);
      }
      else
      {
        target = (CUtlBuffer *)v6;
        if ( CUtlBuffer::CheckPut(this: v4, nSize: 2) )
        {
          if ( (*(_BYTE *)&v4->m_Byteswap & 1) != 0 )
            CByteswap::SwapBufferToTargetEndian<unsigned short>(
              this: &v4->m_Byteswap,
              outputBuffer: &v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset],
              inputBuffer: (unsigned __int8 *)&target,
              count: 1);
          else
            *(_WORD *)&v4->m_Memory.m_pMemory[v4->m_Put - v4->m_nOffset] = v7;
          v4->m_Put += 2;
          CUtlBuffer::AddNullTermination(this: v4, nPut: v4->m_Put);
        }
      }
      CUtlBuffer::Get(this: source, pMem: buffer, size: v7);
      CUtlBuffer::Put(this: v4, pMem: buffer, size: v7);
    }
  }
  return source->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040BF00
// Name: bool ProcessPlaceDirectory(class CUtlBuffer __near &,class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ProcessPlaceDirectory(CUtlBuffer *source, CUtlBuffer *target, int version)
{
  unsigned __int8 UnsignedShort; // bl

  ProcessBaseDirectory(source, target);
  if ( version > 11 )
  {
    if ( (source->m_Flags & 1) != 0 )
    {
      UnsignedShort = CUtlBuffer::GetUnsignedShort(this: source);
    }
    else if ( CUtlBuffer::CheckGet(this: source, nSize: 1) )
    {
      UnsignedShort = source->m_Memory.m_pMemory[source->m_Get++ - source->m_nOffset];
    }
    else
    {
      UnsignedShort = 0;
    }
    if ( (target->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: target, pFmt: "%hu", UnsignedShort);
    }
    else if ( CUtlBuffer::CheckPut(this: target, nSize: 1) )
    {
      target->m_Memory.m_pMemory[target->m_Put - target->m_nOffset] = UnsignedShort;
      CUtlBuffer::AddNullTermination(this: target, nPut: ++target->m_Put);
      return source->m_Error == 0;
    }
  }
  return source->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040BFB0
// Name: bool ProcessNavArea(class CUtlBuffer __near &,class CUtlBuffer __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ProcessNavArea(int source, unsigned int target, unsigned int version)
{
  CUtlBuffer *v3; // edi
  int UnsignedInt; // eax
  CUtlBuffer *v5; // esi
  unsigned __int8 v6; // bl
  unsigned int j; // ebx
  CUtlBuffer *v8; // eax
  unsigned int v9; // ebx
  unsigned __int8 v10; // bl
  bool v11; // zf
  unsigned int v12; // ebx
  int v13; // eax
  int *v14; // eax
  unsigned __int8 v15; // bl
  unsigned __int8 v16; // bl
  CUtlBuffer *v17; // eax
  CUtlBuffer *v18; // ebx
  int *v19; // eax
  CUtlBuffer *v20; // eax
  CUtlBuffer *v21; // ebx
  int *v22; // eax
  unsigned __int8 v23; // bl
  CUtlBuffer *v24; // eax
  CUtlBuffer *v25; // ebx
  int *v26; // eax
  unsigned __int8 v27; // bl
  CUtlBuffer *v28; // eax
  CUtlBuffer *v29; // ebx
  int *v30; // eax
  unsigned __int8 v31; // bl
  unsigned __int8 v32; // bl
  unsigned __int8 v33; // bl
  unsigned __int8 v34; // bl
  unsigned int v35; // ebx
  unsigned int v36; // ebx
  int UnsignedShort; // [esp-8h] [ebp-118h]
  int Int; // [esp-8h] [ebp-118h]
  int v40; // [esp-8h] [ebp-118h]
  int v41; // [esp-8h] [ebp-118h]
  int v42; // [esp-8h] [ebp-118h]
  int v43; // [esp-8h] [ebp-118h]
  int v44; // [esp-8h] [ebp-118h]
  _DWORD pMem[64]; // [esp+8h] [ebp-108h] BYREF
  unsigned int k; // [esp+108h] [ebp-8h]
  unsigned int i; // [esp+10Ch] [ebp-4h]

  v3 = (CUtlBuffer *)source;
  UnsignedInt = CUtlBuffer::GetUnsignedInt(this: (CUtlBuffer *)source);
  v5 = (CUtlBuffer *)target;
  if ( (*(_BYTE *)(target + 21) & 1) != 0 )
    CUtlBuffer::Printf(this: (CUtlBuffer *)target, pFmt: "%u", UnsignedInt);
  else
    CUtlBuffer::PutTypeBin<int>(this: (CUtlBuffer *)target, src: UnsignedInt);
  if ( version > 8 )
  {
    if ( version >= 0xD )
    {
      Int = CUtlBuffer::GetInt(this: v3);
      if ( (v5->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v5, pFmt: "%d", Int);
      else
        CUtlBuffer::PutTypeBin<int>(this: v5, src: Int);
      goto LABEL_21;
    }
    UnsignedShort = (unsigned __int16)CUtlBuffer::GetUnsignedShort(this: v3);
    if ( (v5->m_Flags & 1) == 0 )
    {
      CUtlBuffer::PutTypeBin<short>(this: v5, src: UnsignedShort);
      goto LABEL_21;
    }
LABEL_14:
    CUtlBuffer::Printf(this: v5, pFmt: "%hu", UnsignedShort);
    goto LABEL_21;
  }
  if ( (v3->m_Flags & 1) != 0 )
  {
    v6 = CUtlBuffer::GetUnsignedShort(this: v3);
  }
  else if ( CUtlBuffer::CheckGet(this: v3, nSize: 1) )
  {
    v6 = v3->m_Memory.m_pMemory[v3->m_Get++ - v3->m_nOffset];
  }
  else
  {
    v6 = 0;
  }
  if ( (v5->m_Flags & 1) != 0 )
  {
    UnsignedShort = v6;
    goto LABEL_14;
  }
  if ( CUtlBuffer::CheckPut(this: v5, nSize: 1) )
  {
    v5->m_Memory.m_pMemory[v5->m_Put++ - v5->m_nOffset] = v6;
    CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
  }
LABEL_21:
  CUtlBuffer::Get(this: v3, pMem, size: 32);
  if ( v3->m_Error == 0 )
  {
    for ( j = 0; j < 8; ++j )
    {
      v40 = pMem[j];
      if ( (v5->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v5, pFmt: "%u", v40);
      else
        CUtlBuffer::PutTypeBin<int>(this: v5, src: v40);
    }
  }
  for ( source = 4; source != 0; --source )
  {
    v8 = (CUtlBuffer *)CUtlBuffer::GetUnsignedInt(this: v3);
    v9 = (unsigned int)v8;
    if ( (v5->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v5, pFmt: "%u", v8);
    }
    else
    {
      target = (unsigned int)v8;
      if ( CUtlBuffer::CheckPut(this: v5, nSize: 4) )
      {
        if ( (*(_BYTE *)&v5->m_Byteswap & 1) != 0 )
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this: &v5->m_Byteswap,
            outputBuffer: (int *)&v5->m_Memory.m_pMemory[v5->m_Put - v5->m_nOffset],
            inputBuffer: (int *)&target,
            count: 1);
        else
          *(_DWORD *)&v5->m_Memory.m_pMemory[v5->m_Put - v5->m_nOffset] = v9;
        v5->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
      }
    }
    ProcessDwords(source: v3, target: v5, count: v9);
  }
  if ( (v3->m_Flags & 1) != 0 )
  {
    v10 = CUtlBuffer::GetUnsignedShort(this: v3);
  }
  else if ( CUtlBuffer::CheckGet(this: v3, nSize: 1) )
  {
    v10 = v3->m_Memory.m_pMemory[v3->m_Get++ - v3->m_nOffset];
  }
  else
  {
    v10 = 0;
  }
  if ( (v5->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: v5, pFmt: "%hu", v10);
  }
  else if ( CUtlBuffer::CheckPut(this: v5, nSize: 1) )
  {
    v5->m_Memory.m_pMemory[v5->m_Put++ - v5->m_nOffset] = v10;
    CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
  }
  if ( v10 != 0 )
  {
    i = v10;
    while ( 1 )
    {
      CUtlBuffer::Get(this: v3, pMem, size: 16);
      if ( v3->m_Error == 0 )
        break;
LABEL_61:
      if ( (v3->m_Flags & 1) != 0 )
      {
        v15 = CUtlBuffer::GetUnsignedShort(this: v3);
      }
      else if ( CUtlBuffer::CheckGet(this: v3, nSize: 1) )
      {
        v15 = v3->m_Memory.m_pMemory[v3->m_Get++ - v3->m_nOffset];
      }
      else
      {
        v15 = 0;
      }
      if ( (v5->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v5, pFmt: "%hu", v15);
      }
      else if ( CUtlBuffer::CheckPut(this: v5, nSize: 1) )
      {
        v5->m_Memory.m_pMemory[v5->m_Put++ - v5->m_nOffset] = v15;
        CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
      }
      if ( --i == 0 )
        goto LABEL_71;
    }
    target = 0;
    while ( 1 )
    {
      v11 = (v5->m_Flags & 1) == 0;
      v12 = pMem[target];
      k = v12;
      if ( !v11 )
      {
        CUtlBuffer::Printf(this: v5, pFmt: "%u", v12);
        goto LABEL_60;
      }
      if ( CUtlBuffer::CheckPut(this: v5, nSize: 4) )
      {
        v13 = (int)&v5->m_Memory.m_pMemory[-v5->m_nOffset];
        if ( (*(_BYTE *)&v5->m_Byteswap & 1) == 0 )
        {
          *(_DWORD *)(v13 + v5->m_Put) = v12;
LABEL_58:
          v5->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
          goto LABEL_60;
        }
        v14 = (int *)(v5->m_Put + v13);
        if ( v14 == nullptr )
          goto LABEL_58;
        if ( (*(_BYTE *)&v5->m_Byteswap & 1) != 0 )
        {
          LOBYTE(source) = HIBYTE(k);
          BYTE1(source) = BYTE2(k);
          BYTE2(source) = BYTE1(v12);
          HIBYTE(source) = v12;
          _V_memcpy(dest: v14, src: &source, count: 4);
          v5->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
        }
        else
        {
          if ( v14 == &source )
            goto LABEL_58;
          *v14 = v12;
          v5->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
        }
      }
LABEL_60:
      if ( ++target >= 4 )
        goto LABEL_61;
    }
  }
LABEL_71:
  if ( version < 0xF )
  {
    if ( (v3->m_Flags & 1) != 0 )
    {
      v16 = CUtlBuffer::GetUnsignedShort(this: v3);
    }
    else if ( CUtlBuffer::CheckGet(this: v3, nSize: 1) )
    {
      v16 = v3->m_Memory.m_pMemory[v3->m_Get++ - v3->m_nOffset];
    }
    else
    {
      v16 = 0;
    }
    if ( (v5->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v5, pFmt: "%hu", v16);
    }
    else if ( CUtlBuffer::CheckPut(this: v5, nSize: 1) )
    {
      v5->m_Memory.m_pMemory[v5->m_Put++ - v5->m_nOffset] = v16;
      CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
    }
    i = 0;
    for ( k = v16; i < k; ++i )
    {
      v17 = (CUtlBuffer *)CUtlBuffer::GetUnsignedInt(this: v3);
      v11 = (v5->m_Flags & 1) == 0;
      v18 = v17;
      target = (unsigned int)v17;
      if ( v11 )
      {
        if ( !CUtlBuffer::CheckPut(this: v5, nSize: 4) )
          goto LABEL_93;
        if ( (*(_BYTE *)&v5->m_Byteswap & 1) != 0 )
        {
          v19 = (int *)&v5->m_Memory.m_pMemory[v5->m_Put - v5->m_nOffset];
          if ( v19 != nullptr )
          {
            if ( (*(_BYTE *)&v5->m_Byteswap & 1) != 0 )
            {
              LOBYTE(source) = HIBYTE(target);
              BYTE1(source) = BYTE2(target);
              BYTE2(source) = BYTE1(v18);
              HIBYTE(source) = (_BYTE)v18;
              _V_memcpy(dest: v19, src: &source, count: 4);
              v5->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
              goto LABEL_93;
            }
            if ( v19 != &source )
            {
              *v19 = (int)v18;
              v5->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
              goto LABEL_93;
            }
          }
        }
        else
        {
          *(_DWORD *)&v5->m_Memory.m_pMemory[v5->m_Put - v5->m_nOffset] = v18;
        }
        v5->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
      }
      else
      {
        CUtlBuffer::Printf(this: v5, pFmt: "%u", v17);
      }
LABEL_93:
      v20 = (CUtlBuffer *)CUtlBuffer::GetUnsignedInt(this: v3);
      v11 = (v5->m_Flags & 1) == 0;
      v21 = v20;
      target = (unsigned int)v20;
      if ( v11 )
      {
        if ( !CUtlBuffer::CheckPut(this: v5, nSize: 4) )
          goto LABEL_104;
        if ( (*(_BYTE *)&v5->m_Byteswap & 1) != 0 )
        {
          v22 = (int *)&v5->m_Memory.m_pMemory[v5->m_Put - v5->m_nOffset];
          if ( v22 != nullptr )
          {
            if ( (*(_BYTE *)&v5->m_Byteswap & 1) != 0 )
            {
              LOBYTE(source) = HIBYTE(target);
              BYTE1(source) = BYTE2(target);
              BYTE2(source) = BYTE1(v21);
              HIBYTE(source) = (_BYTE)v21;
              _V_memcpy(dest: v22, src: &source, count: 4);
              v5->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
              goto LABEL_104;
            }
            if ( v22 != &source )
            {
              *v22 = (int)v21;
              v5->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
              goto LABEL_104;
            }
          }
        }
        else
        {
          *(_DWORD *)&v5->m_Memory.m_pMemory[v5->m_Put - v5->m_nOffset] = v21;
        }
        v5->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
      }
      else
      {
        CUtlBuffer::Printf(this: v5, pFmt: "%u", v20);
      }
LABEL_104:
      if ( (v3->m_Flags & 1) != 0 )
      {
        v23 = CUtlBuffer::GetUnsignedShort(this: v3);
      }
      else if ( CUtlBuffer::CheckGet(this: v3, nSize: 1) )
      {
        v23 = v3->m_Memory.m_pMemory[v3->m_Get++ - v3->m_nOffset];
      }
      else
      {
        v23 = 0;
      }
      if ( (v5->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v5, pFmt: "%hu", v23);
      }
      else if ( CUtlBuffer::CheckPut(this: v5, nSize: 1) )
      {
        v5->m_Memory.m_pMemory[v5->m_Put++ - v5->m_nOffset] = v23;
        CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
      }
      v24 = (CUtlBuffer *)CUtlBuffer::GetUnsignedInt(this: v3);
      v11 = (v5->m_Flags & 1) == 0;
      v25 = v24;
      target = (unsigned int)v24;
      if ( !v11 )
      {
        CUtlBuffer::Printf(this: v5, pFmt: "%u", v24);
        goto LABEL_124;
      }
      if ( CUtlBuffer::CheckPut(this: v5, nSize: 4) )
      {
        if ( (*(_BYTE *)&v5->m_Byteswap & 1) == 0 )
        {
          *(_DWORD *)&v5->m_Memory.m_pMemory[v5->m_Put - v5->m_nOffset] = v25;
LABEL_122:
          v5->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
          goto LABEL_124;
        }
        v26 = (int *)&v5->m_Memory.m_pMemory[v5->m_Put - v5->m_nOffset];
        if ( v26 == nullptr )
          goto LABEL_122;
        if ( (*(_BYTE *)&v5->m_Byteswap & 1) != 0 )
        {
          LOBYTE(source) = HIBYTE(target);
          BYTE1(source) = BYTE2(target);
          BYTE2(source) = BYTE1(v25);
          HIBYTE(source) = (_BYTE)v25;
          _V_memcpy(dest: v26, src: &source, count: 4);
          v5->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
        }
        else
        {
          if ( v26 == &source )
            goto LABEL_122;
          *v26 = (int)v25;
          v5->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
        }
      }
LABEL_124:
      if ( (v3->m_Flags & 1) != 0 )
      {
        v27 = CUtlBuffer::GetUnsignedShort(this: v3);
      }
      else if ( CUtlBuffer::CheckGet(this: v3, nSize: 1) )
      {
        v27 = v3->m_Memory.m_pMemory[v3->m_Get++ - v3->m_nOffset];
      }
      else
      {
        v27 = 0;
      }
      if ( (v5->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v5, pFmt: "%hu", v27);
      }
      else if ( CUtlBuffer::CheckPut(this: v5, nSize: 1) )
      {
        v5->m_Memory.m_pMemory[v5->m_Put++ - v5->m_nOffset] = v27;
        CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
      }
    }
  }
  v28 = (CUtlBuffer *)CUtlBuffer::GetUnsignedInt(this: v3);
  v11 = (v5->m_Flags & 1) == 0;
  v29 = v28;
  target = (unsigned int)v28;
  if ( v11 )
  {
    if ( !CUtlBuffer::CheckPut(this: v5, nSize: 4) )
      goto LABEL_145;
    if ( (*(_BYTE *)&v5->m_Byteswap & 1) != 0 )
    {
      v30 = (int *)&v5->m_Memory.m_pMemory[v5->m_Put - v5->m_nOffset];
      if ( v30 != nullptr )
      {
        if ( (*(_BYTE *)&v5->m_Byteswap & 1) != 0 )
        {
          LOBYTE(source) = HIBYTE(target);
          BYTE1(source) = BYTE2(target);
          BYTE2(source) = BYTE1(v29);
          HIBYTE(source) = (_BYTE)v29;
          _V_memcpy(dest: v30, src: &source, count: 4);
          v5->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
          goto LABEL_145;
        }
        if ( v30 != &source )
        {
          *v30 = (int)v29;
          v5->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
          goto LABEL_145;
        }
      }
    }
    else
    {
      *(_DWORD *)&v5->m_Memory.m_pMemory[v5->m_Put - v5->m_nOffset] = v29;
    }
    v5->m_Put += 4;
    CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
  }
  else
  {
    CUtlBuffer::Printf(this: v5, pFmt: "%u", v28);
  }
LABEL_145:
  if ( v29 != nullptr )
  {
    for ( target = (unsigned int)v29; target != 0; --target )
    {
      v41 = CUtlBuffer::GetUnsignedInt(this: v3);
      if ( (v5->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v5, pFmt: "%u", v41);
      else
        CUtlBuffer::PutTypeBin<int>(this: v5, src: v41);
      if ( (v3->m_Flags & 1) != 0 )
      {
        v31 = CUtlBuffer::GetUnsignedShort(this: v3);
      }
      else if ( CUtlBuffer::CheckGet(this: v3, nSize: 1) )
      {
        v31 = v3->m_Memory.m_pMemory[v3->m_Get++ - v3->m_nOffset];
      }
      else
      {
        v31 = 0;
      }
      if ( (v5->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v5, pFmt: "%hu", v31);
      }
      else if ( CUtlBuffer::CheckPut(this: v5, nSize: 1) )
      {
        v5->m_Memory.m_pMemory[v5->m_Put++ - v5->m_nOffset] = v31;
        CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
      }
      v42 = CUtlBuffer::GetUnsignedInt(this: v3);
      if ( (v5->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v5, pFmt: "%u", v42);
      else
        CUtlBuffer::PutTypeBin<int>(this: v5, src: v42);
      if ( (v3->m_Flags & 1) != 0 )
      {
        v32 = CUtlBuffer::GetUnsignedShort(this: v3);
      }
      else if ( CUtlBuffer::CheckGet(this: v3, nSize: 1) )
      {
        v32 = v3->m_Memory.m_pMemory[v3->m_Get++ - v3->m_nOffset];
      }
      else
      {
        v32 = 0;
      }
      if ( (v5->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v5, pFmt: "%hu", v32);
      }
      else if ( CUtlBuffer::CheckPut(this: v5, nSize: 1) )
      {
        v5->m_Memory.m_pMemory[v5->m_Put++ - v5->m_nOffset] = v32;
        CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
      }
      if ( (v3->m_Flags & 1) != 0 )
      {
        v33 = CUtlBuffer::GetUnsignedShort(this: v3);
      }
      else if ( CUtlBuffer::CheckGet(this: v3, nSize: 1) )
      {
        v33 = v3->m_Memory.m_pMemory[v3->m_Get++ - v3->m_nOffset];
      }
      else
      {
        v33 = 0;
      }
      if ( (v5->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v5, pFmt: "%hu", v33);
      }
      else if ( CUtlBuffer::CheckPut(this: v5, nSize: 1) )
      {
        v5->m_Memory.m_pMemory[v5->m_Put++ - v5->m_nOffset] = v33;
        CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
      }
      if ( v33 != 0 )
      {
        for ( source = v33; source != 0; --source )
        {
          v43 = CUtlBuffer::GetUnsignedInt(this: v3);
          if ( (v5->m_Flags & 1) != 0 )
            CUtlBuffer::Printf(this: v5, pFmt: "%u", v43);
          else
            CUtlBuffer::PutTypeBin<int>(this: v5, src: v43);
          if ( (v3->m_Flags & 1) != 0 )
          {
            v34 = CUtlBuffer::GetUnsignedShort(this: v3);
          }
          else if ( CUtlBuffer::CheckGet(this: v3, nSize: 1) )
          {
            v34 = v3->m_Memory.m_pMemory[v3->m_Get++ - v3->m_nOffset];
          }
          else
          {
            v34 = 0;
          }
          if ( (v5->m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: v5, pFmt: "%hu", v34);
          }
          else if ( CUtlBuffer::CheckPut(this: v5, nSize: 1) )
          {
            v5->m_Memory.m_pMemory[v5->m_Put++ - v5->m_nOffset] = v34;
            CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
          }
        }
      }
    }
  }
  v44 = (unsigned __int16)CUtlBuffer::GetUnsignedShort(this: v3);
  if ( (v5->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v5, pFmt: "%hu", v44);
  else
    CUtlBuffer::PutTypeBin<short>(this: v5, src: v44);
  for ( source = 2; source != 0; --source )
  {
    v35 = CUtlBuffer::GetUnsignedInt(this: v3);
    if ( (v5->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v5, pFmt: "%u", v35);
    else
      CUtlBuffer::PutTypeBin<int>(this: v5, src: v35);
    ProcessDwords(source: v3, target: v5, count: v35);
  }
  v36 = version;
  if ( version >= 8 )
    ProcessDwords(source: v3, target: v5, count: 2u);
  if ( v36 >= 0xB )
    ProcessDwords(source: v3, target: v5, count: 4u);
  return v3->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040CAB0
// Name: bool ProcessAreas(class CUtlBuffer __near &,class CUtlBuffer __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ProcessAreas(CUtlBuffer *source, CUtlBuffer *target, unsigned int version, unsigned int subVersion)
{
  unsigned int v4; // ebx
  CUtlBuffer *v5; // esi
  unsigned int UnsignedInt; // eax
  bool v7; // zf
  unsigned int v8; // ebx
  unsigned int v9; // ebx
  int v10; // ebx
  CUtlBuffer *v11; // ebx
  int v12; // eax
  int v13; // ebx
  unsigned __int8 v14; // bl
  CUtlBuffer *v15; // eax
  CUtlBuffer *v16; // ebx
  int v18; // [esp-4h] [ebp-21Ch]
  int UnsignedShort; // [esp-4h] [ebp-21Ch]
  char pString[512]; // [esp+Ch] [ebp-20Ch] BYREF
  unsigned int count; // [esp+20Ch] [ebp-Ch]
  int inputBuffer; // [esp+210h] [ebp-8h] BYREF
  unsigned int i; // [esp+214h] [ebp-4h]

  v4 = subVersion;
  v5 = target;
  if ( subVersion >= 0xC )
  {
    CUtlBuffer::GetString(this: source, pString, nMaxChars: 511);
    CUtlBuffer::PutString(this: v5, pString);
  }
  if ( v4 >= 8 )
    ProcessBaseDirectory(source, target: v5);
  UnsignedInt = CUtlBuffer::GetUnsignedInt(this: source);
  v7 = (v5->m_Flags & 1) == 0;
  v8 = UnsignedInt;
  count = UnsignedInt;
  if ( v7 )
    CUtlBuffer::PutTypeBin<int>(this: v5, src: UnsignedInt);
  else
    CUtlBuffer::Printf(this: v5, pFmt: "%u", UnsignedInt);
  i = 0;
  if ( v8 == 0 )
    return source->m_Error == 0;
  while ( 1 )
  {
    v9 = subVersion;
    if ( !ProcessNavArea((int)source, target: (unsigned int)v5, version) )
      break;
    if ( v9 > 9 )
    {
      v10 = CUtlBuffer::GetUnsignedInt(this: source);
      if ( (v5->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v5, pFmt: "%u", v10);
      else
        CUtlBuffer::PutTypeBin<int>(this: v5, src: v10);
      if ( subVersion < 0xD )
      {
        v18 = CUtlBuffer::GetUnsignedInt(this: source);
        if ( (v5->m_Flags & 1) != 0 )
          CUtlBuffer::Printf(this: v5, pFmt: "%u", v18);
        else
          CUtlBuffer::PutTypeBin<int>(this: v5, src: v18);
      }
      UnsignedShort = (unsigned __int16)CUtlBuffer::GetUnsignedShort(this: source);
      if ( (v5->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v5, pFmt: "%hu", UnsignedShort);
      else
        CUtlBuffer::PutTypeBin<short>(this: v5, src: UnsignedShort);
      if ( (v10 & 8) != 0 )
        ProcessDwords(source, target: v5, count: 5u);
      v11 = (CUtlBuffer *)CUtlBuffer::GetUnsignedInt(this: source);
      if ( (v5->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v5, pFmt: "%u", v11);
      else
        CUtlBuffer::PutTypeBin<int>(this: v5, src: (int)v11);
      if ( v11 != nullptr )
      {
        for ( target = v11; target != nullptr; target = (CUtlBuffer *)((char *)target - 1) )
        {
          v12 = CUtlBuffer::GetUnsignedInt(this: source);
          v13 = v12;
          if ( (v5->m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: v5, pFmt: "%u", v12);
          }
          else
          {
            inputBuffer = v12;
            if ( CUtlBuffer::CheckPut(this: v5, nSize: 4) )
            {
              if ( (*(_BYTE *)&v5->m_Byteswap & 1) != 0 )
                CByteswap::SwapBufferToTargetEndian<unsigned int>(
                  this: &v5->m_Byteswap,
                  outputBuffer: (int *)&v5->m_Memory.m_pMemory[v5->m_Put - v5->m_nOffset],
                  &inputBuffer,
                  count: 1);
              else
                *(_DWORD *)&v5->m_Memory.m_pMemory[v5->m_Put - v5->m_nOffset] = v13;
              v5->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
            }
          }
          if ( (source->m_Flags & 1) != 0 )
          {
            v14 = CUtlBuffer::GetUnsignedShort(this: source);
          }
          else if ( CUtlBuffer::CheckGet(this: source, nSize: 1) )
          {
            v14 = source->m_Memory.m_pMemory[source->m_Get - source->m_nOffset];
            ++source->m_Get;
          }
          else
          {
            v14 = 0;
          }
          if ( (v5->m_Flags & 1) != 0 )
          {
            CUtlBuffer::Printf(this: v5, pFmt: "%hu", v14);
          }
          else if ( CUtlBuffer::CheckPut(this: v5, nSize: 1) )
          {
            v5->m_Memory.m_pMemory[v5->m_Put - v5->m_nOffset] = v14;
            CUtlBuffer::AddNullTermination(this: v5, nPut: ++v5->m_Put);
          }
        }
      }
    }
    if ( subVersion >= 0xB )
    {
      v15 = (CUtlBuffer *)CUtlBuffer::GetUnsignedInt(this: source);
      v16 = v15;
      if ( (v5->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v5, pFmt: "%u", v15);
      }
      else
      {
        target = v15;
        if ( CUtlBuffer::CheckPut(this: v5, nSize: 4) )
        {
          if ( (*(_BYTE *)&v5->m_Byteswap & 1) != 0 )
            CByteswap::SwapBufferToTargetEndian<unsigned int>(
              this: &v5->m_Byteswap,
              outputBuffer: (int *)&v5->m_Memory.m_pMemory[v5->m_Put - v5->m_nOffset],
              inputBuffer: (int *)&target,
              count: 1);
          else
            *(_DWORD *)&v5->m_Memory.m_pMemory[v5->m_Put - v5->m_nOffset] = v16;
          v5->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v5, nPut: v5->m_Put);
        }
      }
    }
    if ( ++i >= count )
      return source->m_Error == 0;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x0040CDB0
// Name: bool CreateTargetFile_CStrikeNAV(class CUtlBuffer __near &,class CUtlBuffer __near &,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CreateTargetFile_CStrikeNAV(
        CUtlBuffer *source,
        unsigned int target,
        const char *pTargetName,
        bool bWriteToZip)
{
  CUtlBuffer *v4; // edi
  unsigned __int16 UnsignedShort; // ax
  CUtlBuffer *v6; // esi
  CUtlBuffer *v7; // ebx
  unsigned __int16 v8; // ax
  int v9; // ebx
  unsigned __int8 v10; // bl
  CUtlBuffer *UnsignedInt; // eax
  bool v12; // zf
  CUtlBuffer *v13; // ebx
  CUtlBuffer *v14; // eax
  CUtlBuffer *v15; // ebx
  unsigned __int8 *v16; // eax
  CUtlBuffer *Int; // eax
  CUtlBuffer *v18; // ebx
  unsigned __int8 *v19; // eax
  int v20; // ebx
  unsigned __int8 *v21; // eax
  CUtlBuffer *v22; // eax
  unsigned int v23; // ebx
  unsigned int *v24; // eax
  unsigned __int8 v25; // bl
  int v26; // ebx
  unsigned __int8 *v27; // eax
  unsigned __int8 v28; // bl
  CUtlBuffer *v29; // eax
  CUtlBuffer *v30; // ebx
  unsigned __int8 *v31; // eax
  unsigned int v32; // eax
  unsigned int v33; // ebx
  unsigned __int8 *v34; // eax
  unsigned __int8 v35; // bl
  unsigned int v36; // eax
  unsigned int v37; // ebx
  unsigned __int8 *v38; // eax
  unsigned __int8 v39; // bl
  unsigned __int8 v40; // bl
  unsigned __int8 v41; // bl
  unsigned int v42; // ebx
  CUtlBuffer *v43; // ebx
  unsigned __int8 v44; // bl
  unsigned __int8 v45; // bl
  unsigned __int8 v46; // bl
  int v47; // eax
  int v48; // ebx
  int v50; // [esp-4h] [ebp-254h]
  int v51; // [esp-4h] [ebp-254h]
  int v52; // [esp-4h] [ebp-254h]
  int v53; // [esp-4h] [ebp-254h]
  int v54; // [esp-4h] [ebp-254h]
  int v55; // [esp-4h] [ebp-254h]
  int v56; // [esp-4h] [ebp-254h]
  char buffer[256]; // [esp+Ch] [ebp-244h] BYREF
  _DWORD pMem[64]; // [esp+10Ch] [ebp-144h] BYREF
  CUtlBuffer compressedBuffer; // [esp+20Ch] [ebp-44h] BYREF
  unsigned int numNavAreas; // [esp+23Ch] [ebp-14h]
  unsigned int i; // [esp+240h] [ebp-10h]
  unsigned __int8 c[4]; // [esp+244h] [ebp-Ch]
  unsigned int b4; // [esp+248h] [ebp-8h]
  int j; // [esp+24Ch] [ebp-4h]

  v4 = source;
  UnsignedShort = CUtlBuffer::GetUnsignedShort(this: source);
  v6 = (CUtlBuffer *)target;
  v7 = (CUtlBuffer *)UnsignedShort;
  if ( (*(_BYTE *)(target + 21) & 1) != 0 )
    CUtlBuffer::Printf(this: (CUtlBuffer *)target, pFmt: "%hu", UnsignedShort);
  else
    CUtlBuffer::PutTypeBin<short>(this: (CUtlBuffer *)target, src: UnsignedShort);
  if ( (int)v7 > 0 )
  {
    for ( source = v7; source != nullptr; source = (CUtlBuffer *)((char *)source - 1) )
    {
      v8 = CUtlBuffer::GetUnsignedShort(this: v4);
      v9 = v8;
      if ( (v6->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v6, pFmt: "%hu", v8);
      }
      else
      {
        target = v8;
        if ( CUtlBuffer::CheckPut(this: v6, nSize: 2) )
        {
          if ( (*(_BYTE *)&v6->m_Byteswap & 1) != 0 )
            CByteswap::SwapBufferToTargetEndian<unsigned short>(
              this: &v6->m_Byteswap,
              outputBuffer: &v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset],
              inputBuffer: (unsigned __int8 *)&target,
              count: 1);
          else
            *(_WORD *)&v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset] = v9;
          v6->m_Put += 2;
          CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
        }
      }
      CUtlBuffer::Get(this: v4, pMem: buffer, size: v9);
      CUtlBuffer::Put(this: v6, pMem: buffer, size: v9);
    }
  }
  if ( (v4->m_Flags & 1) != 0 )
  {
    v10 = CUtlBuffer::GetUnsignedShort(this: v4);
  }
  else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
  {
    v10 = v4->m_Memory.m_pMemory[v4->m_Get - v4->m_nOffset];
    ++v4->m_Get;
  }
  else
  {
    v10 = 0;
  }
  if ( (v6->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: v6, pFmt: "%hu", v10);
  }
  else if ( CUtlBuffer::CheckPut(this: v6, nSize: 1) )
  {
    v6->m_Memory.m_pMemory[v6->m_Put++ - v6->m_nOffset] = v10;
    CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
  }
  UnsignedInt = (CUtlBuffer *)CUtlBuffer::GetUnsignedInt(this: v4);
  v12 = (v6->m_Flags & 1) == 0;
  v13 = UnsignedInt;
  numNavAreas = (unsigned int)UnsignedInt;
  if ( v12 )
  {
    source = UnsignedInt;
    if ( CUtlBuffer::CheckPut(this: v6, nSize: 4) )
    {
      if ( (*(_BYTE *)&v6->m_Byteswap & 1) != 0 )
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &v6->m_Byteswap,
          outputBuffer: (int *)&v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset],
          inputBuffer: (int *)&source,
          count: 1);
      else
        *(_DWORD *)&v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset] = v13;
      v6->m_Put += 4;
      CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
    }
  }
  else
  {
    CUtlBuffer::Printf(this: v6, pFmt: "%u", UnsignedInt);
  }
  i = 0;
  if ( v13 == nullptr )
    goto LABEL_257;
  do
  {
    v14 = (CUtlBuffer *)CUtlBuffer::GetUnsignedInt(this: v4);
    v12 = (v6->m_Flags & 1) == 0;
    v15 = v14;
    target = (unsigned int)v14;
    if ( v12 )
    {
      if ( !CUtlBuffer::CheckPut(this: v6, nSize: 4) )
        goto LABEL_42;
      if ( (*(_BYTE *)&v6->m_Byteswap & 1) != 0 )
      {
        v16 = &v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset];
        if ( v16 != nullptr )
        {
          if ( (*(_BYTE *)&v6->m_Byteswap & 1) != 0 )
          {
            LOBYTE(source) = HIBYTE(target);
            BYTE1(source) = BYTE2(target);
            BYTE2(source) = BYTE1(v15);
            HIBYTE(source) = (_BYTE)v15;
            _V_memcpy(dest: v16, src: &source, count: 4);
            v6->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
            goto LABEL_42;
          }
          if ( v16 != (unsigned __int8 *)&source )
          {
            *(_DWORD *)v16 = v15;
            v6->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
            goto LABEL_42;
          }
        }
      }
      else
      {
        *(_DWORD *)&v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset] = v15;
      }
      v6->m_Put += 4;
      CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
    }
    else
    {
      CUtlBuffer::Printf(this: v6, pFmt: "%u", v14);
    }
LABEL_42:
    Int = (CUtlBuffer *)CUtlBuffer::GetInt(this: v4);
    v12 = (v6->m_Flags & 1) == 0;
    v18 = Int;
    target = (unsigned int)Int;
    if ( !v12 )
    {
      CUtlBuffer::Printf(this: v6, pFmt: "%d", Int);
      goto LABEL_53;
    }
    if ( CUtlBuffer::CheckPut(this: v6, nSize: 4) )
    {
      if ( (*(_BYTE *)&v6->m_Byteswap & 1) == 0 )
      {
        *(_DWORD *)&v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset] = v18;
LABEL_51:
        v6->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
        goto LABEL_53;
      }
      v19 = &v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset];
      if ( v19 == nullptr )
        goto LABEL_51;
      if ( (*(_BYTE *)&v6->m_Byteswap & 1) != 0 )
      {
        LOBYTE(source) = HIBYTE(target);
        BYTE1(source) = BYTE2(target);
        BYTE2(source) = BYTE1(v18);
        HIBYTE(source) = (_BYTE)v18;
        _V_memcpy(dest: v19, src: &source, count: 4);
        v6->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
      }
      else
      {
        if ( v19 == (unsigned __int8 *)&source )
          goto LABEL_51;
        *(_DWORD *)v19 = v18;
        v6->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
      }
    }
LABEL_53:
    CUtlBuffer::Get(this: v4, pMem, size: 32);
    if ( v4->m_Error == 0 )
    {
      for ( target = 0; target < 8; ++target )
      {
        v12 = (v6->m_Flags & 1) == 0;
        v20 = pMem[target];
        j = v20;
        if ( !v12 )
        {
          CUtlBuffer::Printf(this: v6, pFmt: "%u", v20);
          continue;
        }
        if ( CUtlBuffer::CheckPut(this: v6, nSize: 4) )
        {
          if ( (*(_BYTE *)&v6->m_Byteswap & 1) == 0 )
          {
            *(_DWORD *)&v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset] = v20;
LABEL_64:
            v6->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
            continue;
          }
          v21 = &v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset];
          if ( v21 == nullptr )
            goto LABEL_64;
          if ( (*(_BYTE *)&v6->m_Byteswap & 1) != 0 )
          {
            LOBYTE(source) = HIBYTE(j);
            BYTE1(source) = BYTE2(j);
            BYTE2(source) = BYTE1(v20);
            HIBYTE(source) = v20;
            _V_memcpy(dest: v21, src: &source, count: 4);
            v6->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
          }
          else
          {
            if ( v21 == (unsigned __int8 *)&source )
              goto LABEL_64;
            *(_DWORD *)v21 = v20;
            v6->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
          }
        }
      }
    }
    for ( j = 4; j != 0; --j )
    {
      v22 = (CUtlBuffer *)CUtlBuffer::GetUnsignedInt(this: v4);
      v12 = (v6->m_Flags & 1) == 0;
      v23 = (unsigned int)v22;
      target = (unsigned int)v22;
      if ( v12 )
      {
        if ( !CUtlBuffer::CheckPut(this: v6, nSize: 4) )
          goto LABEL_79;
        if ( (*(_BYTE *)&v6->m_Byteswap & 1) != 0 )
        {
          v24 = (unsigned int *)&v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset];
          if ( v24 != nullptr )
          {
            if ( (*(_BYTE *)&v6->m_Byteswap & 1) != 0 )
            {
              LOBYTE(source) = HIBYTE(target);
              BYTE1(source) = BYTE2(target);
              BYTE2(source) = BYTE1(v23);
              HIBYTE(source) = v23;
              _V_memcpy(dest: v24, src: &source, count: 4);
              v6->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
              goto LABEL_79;
            }
            if ( v24 != (unsigned int *)&source )
            {
              *v24 = v23;
              v6->m_Put += 4;
              CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
              goto LABEL_79;
            }
          }
        }
        else
        {
          *(_DWORD *)&v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset] = v23;
        }
        v6->m_Put += 4;
        CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
      }
      else
      {
        CUtlBuffer::Printf(this: v6, pFmt: "%u", v22);
      }
LABEL_79:
      ProcessDwords(source: v4, target: v6, count: v23);
    }
    if ( (v4->m_Flags & 1) != 0 )
    {
      v25 = CUtlBuffer::GetUnsignedShort(this: v4);
    }
    else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
    {
      v25 = v4->m_Memory.m_pMemory[v4->m_Get - v4->m_nOffset];
      ++v4->m_Get;
    }
    else
    {
      v25 = 0;
    }
    if ( (v6->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v6, pFmt: "%hu", v25);
    }
    else if ( CUtlBuffer::CheckPut(this: v6, nSize: 1) )
    {
      v6->m_Memory.m_pMemory[v6->m_Put++ - v6->m_nOffset] = v25;
      CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
    }
    if ( v25 != 0 )
    {
      b4 = v25;
      while ( 1 )
      {
        CUtlBuffer::Get(this: v4, pMem, size: 16);
        if ( v4->m_Error == 0 )
          break;
LABEL_105:
        if ( (v4->m_Flags & 1) != 0 )
        {
          v28 = CUtlBuffer::GetUnsignedShort(this: v4);
        }
        else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
        {
          v28 = v4->m_Memory.m_pMemory[v4->m_Get - v4->m_nOffset];
          ++v4->m_Get;
        }
        else
        {
          v28 = 0;
        }
        if ( (v6->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v6, pFmt: "%hu", v28);
        }
        else if ( CUtlBuffer::CheckPut(this: v6, nSize: 1) )
        {
          v6->m_Memory.m_pMemory[v6->m_Put++ - v6->m_nOffset] = v28;
          CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
        }
        if ( --b4 == 0 )
          goto LABEL_115;
      }
      target = 0;
      while ( 2 )
      {
        v12 = (v6->m_Flags & 1) == 0;
        v26 = pMem[target];
        j = v26;
        if ( v12 )
        {
          if ( !CUtlBuffer::CheckPut(this: v6, nSize: 4) )
            goto LABEL_104;
          if ( (*(_BYTE *)&v6->m_Byteswap & 1) != 0 )
          {
            v27 = &v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset];
            if ( v27 != nullptr )
            {
              if ( (*(_BYTE *)&v6->m_Byteswap & 1) != 0 )
              {
                LOBYTE(source) = HIBYTE(j);
                BYTE1(source) = BYTE2(j);
                BYTE2(source) = BYTE1(v26);
                HIBYTE(source) = v26;
                _V_memcpy(dest: v27, src: &source, count: 4);
                v6->m_Put += 4;
                CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
                goto LABEL_104;
              }
              if ( v27 != (unsigned __int8 *)&source )
              {
                *(_DWORD *)v27 = v26;
                v6->m_Put += 4;
                CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
                goto LABEL_104;
              }
            }
          }
          else
          {
            *(_DWORD *)&v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset] = v26;
          }
          v6->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
        }
        else
        {
          CUtlBuffer::Printf(this: v6, pFmt: "%u", v26);
        }
LABEL_104:
        if ( ++target >= 4 )
          goto LABEL_105;
        continue;
      }
    }
LABEL_115:
    v29 = (CUtlBuffer *)CUtlBuffer::GetUnsignedInt(this: v4);
    v12 = (v6->m_Flags & 1) == 0;
    v30 = v29;
    target = (unsigned int)v29;
    if ( v12 )
    {
      if ( !CUtlBuffer::CheckPut(this: v6, nSize: 4) )
        goto LABEL_126;
      if ( (*(_BYTE *)&v6->m_Byteswap & 1) != 0 )
      {
        v31 = &v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset];
        if ( v31 != nullptr )
        {
          if ( (*(_BYTE *)&v6->m_Byteswap & 1) != 0 )
          {
            LOBYTE(source) = HIBYTE(target);
            BYTE1(source) = BYTE2(target);
            BYTE2(source) = BYTE1(v30);
            HIBYTE(source) = (_BYTE)v30;
            _V_memcpy(dest: v31, src: &source, count: 4);
            v6->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
            goto LABEL_126;
          }
          if ( v31 != (unsigned __int8 *)&source )
          {
            *(_DWORD *)v31 = v30;
            v6->m_Put += 4;
            CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
            goto LABEL_126;
          }
        }
      }
      else
      {
        *(_DWORD *)&v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset] = v30;
      }
      v6->m_Put += 4;
      CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
    }
    else
    {
      CUtlBuffer::Printf(this: v6, pFmt: "%u", v29);
    }
LABEL_126:
    j = 0;
    if ( v30 != nullptr )
    {
      while ( 2 )
      {
        v32 = CUtlBuffer::GetUnsignedInt(this: v4);
        v12 = (v6->m_Flags & 1) == 0;
        v33 = v32;
        b4 = v32;
        if ( v12 )
        {
          if ( !CUtlBuffer::CheckPut(this: v6, nSize: 4) )
            goto LABEL_138;
          if ( (*(_BYTE *)&v6->m_Byteswap & 1) != 0 )
          {
            v34 = &v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset];
            if ( v34 != nullptr )
            {
              if ( (*(_BYTE *)&v6->m_Byteswap & 1) != 0 )
              {
                LOBYTE(source) = HIBYTE(b4);
                BYTE1(source) = BYTE2(b4);
                BYTE2(source) = BYTE1(v33);
                HIBYTE(source) = v33;
                _V_memcpy(dest: v34, src: &source, count: 4);
                v6->m_Put += 4;
                CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
                goto LABEL_138;
              }
              if ( v34 != (unsigned __int8 *)&source )
              {
                *(_DWORD *)v34 = v33;
                v6->m_Put += 4;
                CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
                goto LABEL_138;
              }
            }
          }
          else
          {
            *(_DWORD *)&v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset] = v33;
          }
          v6->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
        }
        else
        {
          CUtlBuffer::Printf(this: v6, pFmt: "%u", v32);
        }
LABEL_138:
        if ( (v4->m_Flags & 1) != 0 )
        {
          v35 = CUtlBuffer::GetUnsignedShort(this: v4);
        }
        else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
        {
          v35 = v4->m_Memory.m_pMemory[v4->m_Get - v4->m_nOffset];
          ++v4->m_Get;
        }
        else
        {
          v35 = 0;
        }
        if ( (v6->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v6, pFmt: "%hu", v35);
        }
        else if ( CUtlBuffer::CheckPut(this: v6, nSize: 1) )
        {
          v6->m_Memory.m_pMemory[v6->m_Put++ - v6->m_nOffset] = v35;
          CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
        }
        v36 = CUtlBuffer::GetUnsignedInt(this: v4);
        v12 = (v6->m_Flags & 1) == 0;
        v37 = v36;
        b4 = v36;
        if ( v12 )
        {
          if ( !CUtlBuffer::CheckPut(this: v6, nSize: 4) )
            goto LABEL_158;
          if ( (*(_BYTE *)&v6->m_Byteswap & 1) != 0 )
          {
            v38 = &v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset];
            if ( v38 != nullptr )
            {
              if ( (*(_BYTE *)&v6->m_Byteswap & 1) != 0 )
              {
                LOBYTE(source) = HIBYTE(b4);
                BYTE1(source) = BYTE2(b4);
                BYTE2(source) = BYTE1(v37);
                HIBYTE(source) = v37;
                _V_memcpy(dest: v38, src: &source, count: 4);
                v6->m_Put += 4;
                CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
                goto LABEL_158;
              }
              if ( v38 != (unsigned __int8 *)&source )
              {
                *(_DWORD *)v38 = v37;
                v6->m_Put += 4;
                CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
                goto LABEL_158;
              }
            }
          }
          else
          {
            *(_DWORD *)&v6->m_Memory.m_pMemory[v6->m_Put - v6->m_nOffset] = v37;
          }
          v6->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
        }
        else
        {
          CUtlBuffer::Printf(this: v6, pFmt: "%u", v36);
        }
LABEL_158:
        if ( (v4->m_Flags & 1) != 0 )
        {
          v39 = CUtlBuffer::GetUnsignedShort(this: v4);
        }
        else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
        {
          v39 = v4->m_Memory.m_pMemory[v4->m_Get - v4->m_nOffset];
          ++v4->m_Get;
        }
        else
        {
          v39 = 0;
        }
        if ( (v6->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v6, pFmt: "%hu", v39);
        }
        else if ( CUtlBuffer::CheckPut(this: v6, nSize: 1) )
        {
          v6->m_Memory.m_pMemory[v6->m_Put++ - v6->m_nOffset] = v39;
          CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
        }
        if ( (v4->m_Flags & 1) != 0 )
        {
          v40 = CUtlBuffer::GetUnsignedShort(this: v4);
        }
        else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
        {
          v40 = v4->m_Memory.m_pMemory[v4->m_Get - v4->m_nOffset];
          ++v4->m_Get;
        }
        else
        {
          v40 = 0;
        }
        if ( (v6->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v6, pFmt: "%hu", v40);
        }
        else if ( CUtlBuffer::CheckPut(this: v6, nSize: 1) )
        {
          v6->m_Memory.m_pMemory[v6->m_Put++ - v6->m_nOffset] = v40;
          CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
        }
        if ( v40 != 0 )
        {
          for ( source = (CUtlBuffer *)v40; source != nullptr; source = (CUtlBuffer *)((char *)source - 1) )
          {
            v50 = CUtlBuffer::GetUnsignedInt(this: v4);
            if ( (v6->m_Flags & 1) != 0 )
              CUtlBuffer::Printf(this: v6, pFmt: "%u", v50);
            else
              CUtlBuffer::PutTypeBin<int>(this: v6, src: v50);
            if ( (v4->m_Flags & 1) != 0 )
            {
              v41 = CUtlBuffer::GetUnsignedShort(this: v4);
            }
            else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
            {
              v41 = v4->m_Memory.m_pMemory[v4->m_Get - v4->m_nOffset];
              ++v4->m_Get;
            }
            else
            {
              v41 = 0;
            }
            if ( (v6->m_Flags & 1) != 0 )
            {
              CUtlBuffer::Printf(this: v6, pFmt: "%hu", v41);
            }
            else if ( CUtlBuffer::CheckPut(this: v6, nSize: 1) )
            {
              v6->m_Memory.m_pMemory[v6->m_Put++ - v6->m_nOffset] = v41;
              CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
            }
          }
        }
        if ( ++j >= target )
          break;
        continue;
      }
    }
    v51 = (unsigned __int16)CUtlBuffer::GetUnsignedShort(this: v4);
    if ( (v6->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v6, pFmt: "%hu", v51);
    else
      CUtlBuffer::PutTypeBin<short>(this: v6, src: v51);
    for ( source = (CUtlBuffer *)2; source != nullptr; source = (CUtlBuffer *)((char *)source - 1) )
    {
      v42 = CUtlBuffer::GetUnsignedInt(this: v4);
      if ( (v6->m_Flags & 1) != 0 )
        CUtlBuffer::Printf(this: v6, pFmt: "%u", v42);
      else
        CUtlBuffer::PutTypeBin<int>(this: v6, src: v42);
      ProcessDwords(source: v4, target: v6, count: v42);
    }
    ProcessDwords(source: v4, target: v6, count: 2u);
    ProcessDwords(source: v4, target: v6, count: 4u);
    v43 = (CUtlBuffer *)CUtlBuffer::GetUnsignedInt(this: v4);
    if ( (v6->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v6, pFmt: "%u", v43);
    else
      CUtlBuffer::PutTypeBin<int>(this: v6, src: (int)v43);
    if ( v43 != nullptr )
    {
      for ( source = v43; source != nullptr; source = (CUtlBuffer *)((char *)source - 1) )
      {
        v52 = CUtlBuffer::GetUnsignedInt(this: v4);
        if ( (v6->m_Flags & 1) != 0 )
          CUtlBuffer::Printf(this: v6, pFmt: "%u", v52);
        else
          CUtlBuffer::PutTypeBin<int>(this: v6, src: v52);
        if ( (v4->m_Flags & 1) != 0 )
        {
          v44 = CUtlBuffer::GetUnsignedShort(this: v4);
        }
        else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
        {
          v44 = v4->m_Memory.m_pMemory[v4->m_Get - v4->m_nOffset];
          ++v4->m_Get;
        }
        else
        {
          v44 = 0;
        }
        if ( (v6->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v6, pFmt: "%hu", v44);
        }
        else if ( CUtlBuffer::CheckPut(this: v6, nSize: 1) )
        {
          v6->m_Memory.m_pMemory[v6->m_Put++ - v6->m_nOffset] = v44;
          CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
        }
      }
    }
    v53 = CUtlBuffer::GetUnsignedInt(this: v4);
    if ( (v6->m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: v6, pFmt: "%u", v53);
    else
      CUtlBuffer::PutTypeBin<int>(this: v6, src: v53);
    if ( (v4->m_Flags & 1) != 0 )
    {
      v45 = CUtlBuffer::GetUnsignedShort(this: v4);
    }
    else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
    {
      v45 = v4->m_Memory.m_pMemory[v4->m_Get - v4->m_nOffset];
      ++v4->m_Get;
    }
    else
    {
      v45 = 0;
    }
    if ( (v6->m_Flags & 1) != 0 )
    {
      CUtlBuffer::Printf(this: v6, pFmt: "%hu", v45);
    }
    else if ( CUtlBuffer::CheckPut(this: v6, nSize: 1) )
    {
      v6->m_Memory.m_pMemory[v6->m_Put++ - v6->m_nOffset] = v45;
      CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
    }
    if ( v45 != 0 )
    {
      for ( source = (CUtlBuffer *)v45; source != nullptr; source = (CUtlBuffer *)((char *)source - 1) )
      {
        v54 = CUtlBuffer::GetUnsignedInt(this: v4);
        if ( (v6->m_Flags & 1) != 0 )
          CUtlBuffer::Printf(this: v6, pFmt: "%u", v54);
        else
          CUtlBuffer::PutTypeBin<int>(this: v6, src: v54);
        v55 = CUtlBuffer::GetUnsignedInt(this: v4);
        if ( (v6->m_Flags & 1) != 0 )
          CUtlBuffer::Printf(this: v6, pFmt: "%u", v55);
        else
          CUtlBuffer::PutTypeBin<int>(this: v6, src: v55);
        if ( (v4->m_Flags & 1) != 0 )
        {
          v46 = CUtlBuffer::GetUnsignedShort(this: v4);
        }
        else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
        {
          v46 = v4->m_Memory.m_pMemory[v4->m_Get - v4->m_nOffset];
          ++v4->m_Get;
        }
        else
        {
          v46 = 0;
        }
        if ( (v6->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v6, pFmt: "%hu", v46);
        }
        else if ( CUtlBuffer::CheckPut(this: v6, nSize: 1) )
        {
          v6->m_Memory.m_pMemory[v6->m_Put++ - v6->m_nOffset] = v46;
          CUtlBuffer::AddNullTermination(this: v6, nPut: v6->m_Put);
        }
        v56 = CUtlBuffer::GetUnsignedInt(this: v4);
        if ( (v6->m_Flags & 1) != 0 )
          CUtlBuffer::Printf(this: v6, pFmt: "%u", v56);
        else
          CUtlBuffer::PutTypeBin<int>(this: v6, src: v56);
        if ( (v4->m_Flags & 1) != 0 )
        {
          c[0] = CUtlBuffer::GetUnsignedShort(this: v4);
        }
        else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
        {
          v47 = v4->m_Get + 1;
          c[0] = v4->m_Memory.m_pMemory[v4->m_Get - v4->m_nOffset];
          v4->m_Get = v47;
        }
        else
        {
          c[0] = 0;
        }
        CUtlBuffer::PutUnsignedChar(this: v6, c: c[0]);
      }
    }
    ++i;
  }
  while ( i < numNavAreas );
LABEL_257:
  v48 = CUtlBuffer::GetUnsignedInt(this: v4);
  if ( (v6->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: v6, pFmt: "%u", v48);
  else
    CUtlBuffer::PutTypeBin<int>(this: v6, src: v48);
  for ( ; v48 != 0; --v48 )
  {
    ProcessDwords(source: v4, target: v6, count: 0xAu);
    ProcessDwords(source: v4, target: v6, count: 5u);
  }
  CUtlBuffer::SeekGet(this: v6, type: SEEK_HEAD, offset: 0);
  CUtlBuffer::CUtlBuffer(this: &compressedBuffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( CompressCallback(inputBuffer: (signed int)v6, outputBuffer: &compressedBuffer) != 0 )
    WriteBufferToFile(pTargetName, buffer: &compressedBuffer, bWriteToZip, writeMode: g_WriteModeForConversions);
  else
    WriteBufferToFile(pTargetName, buffer: v6, bWriteToZip, writeMode: g_WriteModeForConversions);
  if ( compressedBuffer.m_Memory.m_nGrowSize >= 0 && compressedBuffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: compressedBuffer.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040DD00
// Name: bool CreateTargetFile_NAV(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CreateTargetFile_NAV(const char *pSourceName, const char *pTargetName, bool bWriteToZip)
{
  unsigned int UnsignedInt; // eax
  unsigned int v5; // esi
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned __int8 UnsignedChar; // al
  char v10; // bl
  CUtlBuffer compressedBuffer; // [esp+4h] [ebp-90h] BYREF
  CUtlBuffer targetBuffer; // [esp+34h] [ebp-60h] BYREF
  CUtlBuffer sourceBuffer; // [esp+64h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &sourceBuffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( !ReadFileToBuffer(pSourceName, buffer: &sourceBuffer, bText: false, bNoOpenFailureWarning: false) )
    goto LABEL_4;
  if ( CUtlBuffer::GetUnsignedInt(this: &sourceBuffer) != -17958194 )
  {
    _Warning(a1: "ERROR: Invalid Nav-file signature.\n--> %s\n", pSourceName);
LABEL_4:
    if ( sourceBuffer.m_Memory.m_nGrowSize >= 0 && sourceBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuffer.m_Memory.m_pMemory);
    return 0;
  }
  UnsignedInt = CUtlBuffer::GetUnsignedInt(this: &sourceBuffer);
  v5 = UnsignedInt;
  if ( UnsignedInt - 9 > 7 )
  {
    _Warning(a1: "ERROR: Nav-file has unsupported version. ( %d )\n--> %s\n", UnsignedInt, pSourceName);
    if ( sourceBuffer.m_Memory.m_nGrowSize >= 0 && sourceBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuffer.m_Memory.m_pMemory);
    return 0;
  }
  else
  {
    v6 = 0;
    if ( UnsignedInt < 0xA
      || (v7 = CUtlBuffer::GetUnsignedInt(this: &sourceBuffer), v6 = v7, v7 >= 0xA) && v7 <= 0xE
      || v7 == 1 )
    {
      CUtlBuffer::CUtlBuffer(this: &targetBuffer, growSize: 0, initSize: 0, nFlags: 0);
      CUtlBuffer::SetBigEndian(this: &targetBuffer, bigEndian: true);
      CUtlBuffer::PutUnsignedInt(this: &targetBuffer, u: 0xFEEDFACE);
      CUtlBuffer::PutUnsignedInt(this: &targetBuffer, u: v5);
      if ( v5 >= 0xA )
        CUtlBuffer::PutUnsignedInt(this: &targetBuffer, u: v6);
      v8 = CUtlBuffer::GetUnsignedInt(this: &sourceBuffer);
      CUtlBuffer::PutUnsignedInt(this: &targetBuffer, u: v8);
      if ( v5 > 0xD )
      {
        UnsignedChar = CUtlBuffer::GetUnsignedChar(this: &sourceBuffer);
        CUtlBuffer::PutUnsignedChar(this: &targetBuffer, c: UnsignedChar);
      }
      if ( v6 == 1 )
      {
        v10 = CreateTargetFile_CStrikeNAV(
                source: &sourceBuffer,
                target: (unsigned int)&targetBuffer,
                pTargetName,
                bWriteToZip);
        CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &targetBuffer);
        CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &sourceBuffer);
        return v10;
      }
      else if ( ProcessPlaceDirectory(source: &sourceBuffer, target: &targetBuffer, version: v5)
             && ProcessAreas(source: &sourceBuffer, target: &targetBuffer, version: v5, subVersion: v6)
             && ProcessLadders(source: &sourceBuffer, target: &targetBuffer)
             && ProcessCustomData(source: &sourceBuffer, target: &targetBuffer, subVersion: v6) )
      {
        CUtlBuffer::SeekGet(this: &targetBuffer, type: SEEK_HEAD, offset: 0);
        CUtlBuffer::CUtlBuffer(this: &compressedBuffer, growSize: 0, initSize: 0, nFlags: 0);
        if ( CompressCallback(inputBuffer: (signed int)&targetBuffer, outputBuffer: &compressedBuffer) != 0 )
          WriteBufferToFile(pTargetName, buffer: &compressedBuffer, bWriteToZip, writeMode: g_WriteModeForConversions);
        else
          WriteBufferToFile(pTargetName, buffer: &targetBuffer, bWriteToZip, writeMode: g_WriteModeForConversions);
        CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &compressedBuffer);
        CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &targetBuffer);
        CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &sourceBuffer);
        return 1;
      }
      else
      {
        CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &targetBuffer);
        CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &sourceBuffer);
        return 0;
      }
    }
    else
    {
      _Warning(a1: "ERROR: Nav-file unexpected sub-Version. ( %d.%d )\n--> %s\n", v5, v7, pSourceName);
      CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &sourceBuffer);
      return 0;
    }
  }
}
