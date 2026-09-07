// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/diff.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100D8090
// Name: void ApplyDiffs(unsigned char const __near *,unsigned char const __near *,int,int,int __near &,unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyDiffs(
        const unsigned __int8 *OldBlock,
        const unsigned __int8 *DiffList,
        int OldSize,
        const unsigned __int8 *DiffListSize,
        int *ResultListSize,
        unsigned __int8 *Output)
{
  const unsigned __int8 *v6; // ecx
  const unsigned __int8 *v7; // esi
  unsigned __int8 *v8; // edi
  char v9; // al
  unsigned __int8 *v10; // esi
  unsigned int v11; // ebx
  unsigned int v12; // ebx
  unsigned int v13; // eax
  int v14; // edx
  unsigned int v15; // ebx
  int v16; // ebx
  unsigned int v17; // ebx
  unsigned int copy_sza; // [esp+14h] [ebp+Ch]
  int copy_sz; // [esp+14h] [ebp+Ch]
  const unsigned __int8 *end_of_diff_list; // [esp+1Ch] [ebp+14h]

  v6 = OldBlock;
  v7 = DiffList;
  v8 = Output;
  end_of_diff_list = &DiffListSize[(_DWORD)DiffList];
  if ( DiffList < end_of_diff_list )
  {
    while ( 1 )
    {
      v9 = *v7;
      v10 = (unsigned __int8 *)(v7 + 1);
      if ( v9 != 0 )
      {
        if ( v9 >= 0 )
        {
          v17 = v9 & 0x7F;
          memcpy(dst: v8, src: v10, count: v17);
          v8 += v17;
          v7 = &v10[v17];
        }
        else
        {
          v12 = v9 & 0x7F;
          v13 = *v10;
          copy_sz = v13;
          if ( v12 != 0 )
          {
            if ( *v10 > 0x7Fu )
            {
              v13 |= 0xFFFFFF80;
              copy_sz = v13;
            }
            memcpy(dst: v8, src: (unsigned __int8 *)&v6[v13], count: v12);
            OldBlock += v12 + copy_sz;
            v8 += v12;
            v7 = v10 + 1;
          }
          else
          {
            v14 = v10[1];
            if ( *v10 != 0 )
            {
              v16 = v14 + (v10[2] << 8);
              if ( v16 > 0x7FFF )
                v16 |= 0xFFFF0000;
              memcpy(dst: v8, src: (unsigned __int8 *)&v6[v16], count: v13);
              OldBlock += copy_sz + v16;
              v8 += copy_sz;
              v7 = v10 + 3;
            }
            else
            {
              v15 = v14 + ((v10[2] + (v10[3] << 8)) << 8);
              memcpy(dst: v8, src: v10 + 4, count: v15);
              v7 = &v10[v15 + 4];
              v8 += v15;
            }
          }
        }
      }
      else
      {
        v11 = v10[2] + (v10[3] << 8);
        if ( v11 > 0x7FFF )
          v11 |= 0xFFFF0000;
        copy_sza = (unsigned __int16)(*v10 + (v10[1] << 8));
        memcpy(dst: v8, src: (unsigned __int8 *)&v6[v11], count: copy_sza);
        v8 += copy_sza;
        OldBlock += v11 + copy_sza;
        v7 = v10 + 4;
      }
      if ( v7 >= end_of_diff_list )
        break;
      v6 = OldBlock;
    }
  }
  *ResultListSize = v8 - Output;
}

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x1003F240
// Name: void ApplyDiffs(unsigned char const __near *,unsigned char const __near *,int,int,int __near &,unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyDiffs(
        const unsigned __int8 *OldBlock,
        const unsigned __int8 *DiffList,
        int OldSize,
        const unsigned __int8 *DiffListSize,
        int *ResultListSize,
        unsigned __int8 *Output)
{
  const unsigned __int8 *v6; // esi
  bool v7; // cf
  unsigned __int8 *v8; // edi
  char v9; // al
  unsigned __int8 *v10; // esi
  unsigned int v11; // ebx
  unsigned __int16 v12; // ax
  int v13; // ebp
  unsigned int v14; // eax
  unsigned int v15; // ebp
  int v16; // ebp
  unsigned int v17; // ebx
  unsigned int v18; // ebx
  unsigned int v19; // ebx
  unsigned int v20; // ebx
  const unsigned __int8 *end_of_diff_list; // [esp+18h] [ebp+10h]

  v6 = DiffList;
  v7 = DiffList < &DiffListSize[(int)DiffList];
  v8 = Output;
  end_of_diff_list = &DiffListSize[(_DWORD)DiffList];
  if ( v7 )
  {
    do
    {
      v9 = *v6;
      v10 = (unsigned __int8 *)(v6 + 1);
      if ( v9 != 0 )
      {
        if ( v9 >= 0 )
        {
          v20 = v9 & 0x7F;
          memcpy(dst: v8, src: v10, count: v20);
          v8 += v20;
          v6 = &v10[v20];
        }
        else
        {
          v14 = v9 & 0x7F;
          v15 = v14;
          if ( v14 != 0 )
          {
            v19 = *v10;
            if ( v19 > 0x7F )
              v19 |= 0xFFFFFF80;
            memcpy(dst: v8, src: (unsigned __int8 *)&OldBlock[v19], count: v14);
            OldBlock += v15 + v19;
            v8 += v15;
            v6 = v10 + 1;
          }
          else
          {
            v16 = *v10;
            if ( *v10 != 0 )
            {
              v18 = v10[1] + (v10[2] << 8);
              if ( v18 > 0x7FFF )
                v18 |= 0xFFFF0000;
              memcpy(dst: v8, src: (unsigned __int8 *)&OldBlock[v18], count: *v10);
              OldBlock += v16 + v18;
              v8 += v16;
              v6 = v10 + 3;
            }
            else
            {
              v17 = v10[1] + ((v10[2] + (v10[3] << 8)) << 8);
              memcpy(dst: v8, src: v10 + 4, count: v17);
              v6 = &v10[v17 + 4];
              v8 += v17;
            }
          }
        }
      }
      else
      {
        v11 = v10[2] + (v10[3] << 8);
        v12 = *v10 + (v10[1] << 8);
        if ( v11 > 0x7FFF )
          v11 |= 0xFFFF0000;
        v13 = v12;
        memcpy(dst: v8, src: (unsigned __int8 *)&OldBlock[v11], count: v12);
        v8 += v13;
        OldBlock += v11 + v13;
        v6 = v10 + 4;
      }
    }
    while ( v6 < end_of_diff_list );
  }
  *ResultListSize = v8 - Output;
}

} // namespace shaderapidx10
