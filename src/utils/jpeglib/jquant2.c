// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jquant2.c
// Functions: 15
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100114F0
// Name: prescan_quantize
// Source: json
//------------------------------------------------------------------------------
void __cdecl prescan_quantize(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  unsigned int output_width; // eax
  void (__cdecl *finish_pass)(jpeg_decompress_struct *); // ebx
  int v6; // edi
  unsigned __int8 *v7; // ecx
  unsigned int v8; // esi
  int v9; // eax
  int v10; // edx
  bool v11; // zf
  _WORD *v12; // eax
  unsigned int width; // [esp+10h] [ebp+8h]

  output_width = cinfo->output_width;
  finish_pass = cinfo->cquantize[1].finish_pass;
  v6 = 0;
  for ( width = output_width; v6 < num_rows; ++v6 )
  {
    v7 = input_buf[v6];
    v8 = output_width;
    if ( output_width != 0 )
    {
      do
      {
        v9 = (v7[2] >> 3) + 32 * (v7[1] >> 2);
        v10 = *((_DWORD *)finish_pass + (*v7 >> 3));
        v11 = (*(_WORD *)(v10 + 2 * v9))++ == 0xFFFF;
        v12 = (_WORD *)(v10 + 2 * v9);
        if ( v11 )
          --*v12;
        v7 += 3;
        --v8;
      }
      while ( v8 != 0 );
      output_width = width;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011560
// Name: update_box
// Source: json
//------------------------------------------------------------------------------
void __cdecl update_box(box *boxp)
{
  jpeg_decompress_struct *cinfo; // ecx
  int v2; // ebx
  int v3; // edi
  int v4; // esi
  int v5; // edx
  __int16 *v6; // ecx
  int v7; // eax
  __int16 v8; // bx
  int v9; // esi
  int v10; // edx
  __int16 *v11; // ecx
  int v12; // eax
  __int16 v13; // bx
  int v14; // esi
  int v15; // edx
  unsigned __int16 *v16; // eax
  int v17; // ecx
  __int16 v18; // bx
  int v19; // esi
  int v20; // edx
  unsigned __int16 *v21; // eax
  int v22; // ecx
  __int16 v23; // bx
  int v24; // eax
  int v25; // edx
  int v26; // esi
  int v27; // ecx
  unsigned __int16 *v28; // eax
  int v29; // eax
  int v30; // edx
  int v31; // esi
  int v32; // ecx
  unsigned __int16 *v33; // eax
  int v34; // edi
  int v35; // eax
  int v36; // ebx
  int v37; // ecx
  int v38; // edx
  _WORD *v39; // eax
  int v40; // ecx
  int ccount; // [esp+Ch] [ebp-24h]
  int c2max; // [esp+10h] [ebp-20h]
  unsigned __int16 (**histogram)[32]; // [esp+14h] [ebp-1Ch]
  int c0min; // [esp+18h] [ebp-18h]
  int c0mina; // [esp+18h] [ebp-18h]
  int c0; // [esp+1Ch] [ebp-14h]
  int c0a; // [esp+1Ch] [ebp-14h]
  int c0b; // [esp+1Ch] [ebp-14h]
  int c0c; // [esp+1Ch] [ebp-14h]
  int c0d; // [esp+1Ch] [ebp-14h]
  int c0e; // [esp+1Ch] [ebp-14h]
  int c0f; // [esp+1Ch] [ebp-14h]
  int c1max; // [esp+20h] [ebp-10h]
  int c0max; // [esp+24h] [ebp-Ch]
  int c1min; // [esp+28h] [ebp-8h]
  int c2min; // [esp+2Ch] [ebp-4h]

  v2 = boxp->c2min;
  histogram = (unsigned __int16 (**)[32])cinfo->cquantize[1].finish_pass;
  v3 = boxp->c2max;
  c1min = boxp->c1min;
  c0min = boxp->c0min;
  c0max = boxp->c0max;
  c1max = boxp->c1max;
  c2min = v2;
  c2max = v3;
  if ( boxp->c0min < c0max )
  {
    c0 = boxp->c0min;
    while ( 1 )
    {
      v4 = boxp->c1min;
      if ( c1min <= c1max )
        break;
LABEL_9:
      if ( ++c0 > c0max )
        goto LABEL_12;
    }
    v5 = (int)&histogram[c0][c1min][v2];
    while ( 1 )
    {
      v6 = (__int16 *)v5;
      v7 = v2;
      if ( c2min <= v3 )
        break;
LABEL_8:
      v2 = boxp->c2min;
      ++v4;
      v5 += 64;
      if ( v4 > c1max )
        goto LABEL_9;
    }
    while ( 1 )
    {
      v8 = *v6++;
      if ( v8 != 0 )
        break;
      if ( ++v7 > v3 )
        goto LABEL_8;
    }
    v2 = boxp->c2min;
    c0min = c0;
    boxp->c0min = c0;
LABEL_12:
    if ( c0max > c0min )
    {
      c0a = c0max;
      while ( 1 )
      {
        v9 = c1min;
        if ( c1min <= c1max )
          break;
LABEL_20:
        if ( --c0a < c0min )
          goto have_c0max;
      }
      v10 = (int)&histogram[c0a][c1min][v2];
      while ( 1 )
      {
        v11 = (__int16 *)v10;
        v12 = v2;
        if ( c2min <= v3 )
          break;
LABEL_19:
        v2 = c2min;
        ++v9;
        v10 += 64;
        if ( v9 > c1max )
          goto LABEL_20;
      }
      while ( 1 )
      {
        v13 = *v11++;
        if ( v13 != 0 )
          break;
        if ( ++v12 > v3 )
          goto LABEL_19;
      }
      v2 = c2min;
      c0max = c0a;
      boxp->c0max = c0a;
    }
  }
have_c0max:
  if ( c1min < c1max )
  {
    c0b = c1min;
    v14 = v2 + 32 * c1min;
    while ( 1 )
    {
      v15 = c0min;
      if ( c0min <= c0max )
        break;
LABEL_30:
      v14 += 32;
      if ( ++c0b > c1max )
        goto have_c1min;
    }
    while ( 1 )
    {
      v16 = &(*histogram[v15])[v14];
      v17 = v2;
      if ( c2min <= v3 )
        break;
LABEL_29:
      v2 = c2min;
      if ( ++v15 > c0max )
        goto LABEL_30;
    }
    while ( 1 )
    {
      v18 = *v16++;
      if ( v18 != 0 )
        break;
      if ( ++v17 > v3 )
        goto LABEL_29;
    }
    v2 = c2min;
    c1min = c0b;
    boxp->c1min = c0b;
have_c1min:
    if ( c1max > c1min )
    {
      c0c = c1max;
      v19 = v2 + 32 * c1max;
      while ( 1 )
      {
        v20 = c0min;
        if ( c0min <= c0max )
          break;
LABEL_40:
        v19 -= 32;
        if ( --c0c < c1min )
          goto have_c1max;
      }
      while ( 1 )
      {
        v21 = &(*histogram[v20])[v19];
        v22 = v2;
        if ( c2min <= v3 )
          break;
LABEL_39:
        v2 = c2min;
        if ( ++v20 > c0max )
          goto LABEL_40;
      }
      while ( 1 )
      {
        v23 = *v21++;
        if ( v23 != 0 )
          break;
        if ( ++v22 > v3 )
          goto LABEL_39;
      }
      v2 = c2min;
      c1max = c0c;
      boxp->c1max = c0c;
    }
  }
have_c1max:
  if ( v2 < v3 )
  {
    v24 = v2;
    c0d = v2;
    while ( 1 )
    {
      v25 = c0min;
      if ( c0min <= c0max )
        break;
LABEL_52:
      c0d = ++v24;
      if ( v24 > v3 )
        goto have_c2min;
    }
    v26 = v24 + 32 * c1min;
    while ( 1 )
    {
      v27 = c1min;
      v28 = &(*histogram[v25])[v26];
      if ( c1min <= c1max )
        break;
LABEL_50:
      if ( ++v25 > c0max )
      {
        v3 = c2max;
        v24 = c0d;
        goto LABEL_52;
      }
    }
    while ( *v28 == 0 )
    {
      ++v27;
      v28 += 32;
      if ( v27 > c1max )
        goto LABEL_50;
    }
    v2 = c0d;
    v3 = c2max;
    c2min = c0d;
    boxp->c2min = c0d;
have_c2min:
    if ( v3 > v2 )
    {
      v29 = v3;
      c0e = v3;
      while ( 1 )
      {
        v30 = c0min;
        if ( c0min <= c0max )
          break;
LABEL_64:
        c0e = --v29;
        if ( v29 < v2 )
          goto have_c2max;
      }
      v31 = v29 + 32 * c1min;
      while ( 1 )
      {
        v32 = c1min;
        v33 = &(*histogram[v30])[v31];
        if ( c1min <= c1max )
          break;
LABEL_62:
        if ( ++v30 > c0max )
        {
          v29 = c0e;
          v3 = c2max;
          goto LABEL_64;
        }
      }
      while ( *v33 == 0 )
      {
        ++v32;
        v33 += 32;
        if ( v32 > c1max )
          goto LABEL_62;
      }
      v3 = c0e;
      c2max = c0e;
      boxp->c2max = c0e;
    }
  }
have_c2max:
  v34 = v3 - v2;
  v35 = c0min;
  v36 = 0;
  boxp->volume = 16 * (c0max - c0min) * 16 * (c0max - c0min)
               + 12 * (c1max - c1min) * 12 * (c1max - c1min)
               + 8 * v34 * 8 * v34;
  ccount = 0;
  c0f = c0min;
  if ( c0min > c0max )
  {
    boxp->colorcount = 0;
  }
  else
  {
    v37 = c1min;
    do
    {
      if ( v37 <= c1max )
      {
        v38 = (int)&histogram[v35][v37][c2min];
        c0mina = c1max - c1min + 1;
        do
        {
          v36 = ccount;
          v39 = (_WORD *)v38;
          if ( c2min <= c2max )
          {
            v40 = v34 + 1;
            do
            {
              if ( *v39 != 0 )
                ++v36;
              ++v39;
              --v40;
            }
            while ( v40 != 0 );
            ccount = v36;
          }
          v38 += 64;
          --c0mina;
        }
        while ( c0mina != 0 );
        v35 = c0f;
        v37 = c1min;
      }
      c0f = ++v35;
    }
    while ( v35 <= c0max );
    boxp->colorcount = v36;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100118D0
// Name: median_cut
// Source: json
//------------------------------------------------------------------------------
int __cdecl median_cut(jpeg_decompress_struct *cinfo, box *boxlist, int numboxes, int desired_colors)
{
  int v4; // ecx
  int result; // eax
  box *v6; // edx
  int *p_c1max; // esi
  int v8; // ebx
  int *p_colorcount; // edx
  int j; // ecx
  int *p_volume; // edx
  int i; // ecx
  int v13; // edx
  int v14; // ebx
  int v15; // ebx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  box *boxp; // [esp+0h] [ebp-8h]
  int v20; // [esp+4h] [ebp-4h]

  v4 = desired_colors;
  result = numboxes;
  v6 = boxlist;
  if ( numboxes < desired_colors )
  {
    v20 = 2 * numboxes;
    p_c1max = &boxlist[numboxes].c1max;
    while ( 1 )
    {
      v8 = 0;
      boxp = nullptr;
      if ( v20 > v4 )
      {
        if ( result > 0 )
        {
          p_volume = &v6->volume;
          for ( i = result; i != 0; --i )
          {
            if ( *p_volume > v8 )
            {
              boxp = (box *)(p_volume - 6);
              v8 = *p_volume;
            }
            p_volume += 8;
          }
        }
      }
      else if ( result > 0 )
      {
        p_colorcount = &v6->colorcount;
        for ( j = result; j != 0; --j )
        {
          if ( *p_colorcount > v8 && *(p_colorcount - 1) > 0 )
          {
            boxp = (box *)(p_colorcount - 7);
            v8 = *p_colorcount;
          }
          p_colorcount += 8;
        }
      }
      if ( boxp == nullptr )
        break;
      *(p_c1max - 2) = boxp->c0max;
      *p_c1max = boxp->c1max;
      p_c1max[2] = boxp->c2max;
      *(p_c1max - 3) = boxp->c0min;
      *(p_c1max - 1) = boxp->c1min;
      p_c1max[1] = boxp->c2min;
      v13 = 12 * (boxp->c1max - boxp->c1min);
      v14 = 1;
      if ( 16 * (boxp->c0max - boxp->c0min) > v13 )
      {
        v13 = 16 * (boxp->c0max - boxp->c0min);
        v14 = 0;
      }
      if ( 8 * (boxp->c2max - boxp->c2min) > v13 )
        v14 = 2;
      if ( v14 != 0 )
      {
        v15 = v14 - 1;
        if ( v15 != 0 )
        {
          if ( v15 == 1 )
          {
            v16 = (boxp->c2min + boxp->c2max) / 2;
            boxp->c2max = v16;
            p_c1max[1] = v16 + 1;
          }
        }
        else
        {
          v17 = (boxp->c1min + boxp->c1max) / 2;
          boxp->c1max = v17;
          *(p_c1max - 1) = v17 + 1;
        }
      }
      else
      {
        v18 = (boxp->c0min + boxp->c0max) / 2;
        boxp->c0max = v18;
        *(p_c1max - 3) = v18 + 1;
      }
      update_box(boxp);
      update_box(boxp: (box *)(p_c1max - 3));
      v4 = desired_colors;
      v20 += 2;
      result = numboxes + 1;
      p_c1max += 8;
      numboxes = result;
      if ( result >= desired_colors )
        break;
      v6 = boxlist;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011A40
// Name: compute_color
// Source: json
//------------------------------------------------------------------------------
void __usercall compute_color(box *boxp@<eax>, jpeg_decompress_struct *cinfo, int icolor)
{
  int v3; // edx
  int v4; // ebx
  int v5; // esi
  int v6; // ecx
  int v7; // edi
  int c0min; // eax
  unsigned __int16 *v9; // ebx
  int v10; // edx
  int v11; // eax
  int v12; // esi
  int v13; // ecx
  int v14; // edx
  int v15; // eax
  int c0max; // [esp+Ch] [ebp-3Ch]
  int c1min; // [esp+10h] [ebp-38h]
  int c2min; // [esp+18h] [ebp-30h]
  int c0; // [esp+20h] [ebp-28h]
  int v20; // [esp+24h] [ebp-24h]
  unsigned __int16 *v21; // [esp+28h] [ebp-20h]
  int c2max; // [esp+2Ch] [ebp-1Ch]
  int c1max; // [esp+30h] [ebp-18h]
  int c2total; // [esp+34h] [ebp-14h]
  int c1total; // [esp+38h] [ebp-10h]
  int c0total; // [esp+3Ch] [ebp-Ch]
  int v27; // [esp+40h] [ebp-8h]
  int total; // [esp+44h] [ebp-4h]

  v3 = boxp->c0max;
  v4 = boxp->c2max;
  v5 = 0;
  v6 = boxp->c1min;
  c1max = boxp->c1max;
  v7 = boxp->c2min;
  c0min = boxp->c0min;
  total = 0;
  c0total = 0;
  c1total = 0;
  c2total = 0;
  c0max = v3;
  c1min = v6;
  c2min = v7;
  c2max = v4;
  c0 = c0min;
  if ( c0min <= v3 )
  {
    v27 = 8 * c0min + 4;
    do
    {
      if ( v6 <= c1max )
      {
        v9 = (unsigned __int16 *)(*((_DWORD *)cinfo->cquantize[1].finish_pass + c0min) + 2 * (v7 + 32 * v6));
        v10 = c2max;
        v11 = c1max - v6 + 1;
        v12 = 4 * v6 + 2;
        v21 = v9;
        v20 = v11;
        do
        {
          if ( v7 <= v10 )
          {
            v13 = 8 * v7 + 4;
            v14 = v10 - v7 + 1;
            do
            {
              v15 = *v9++;
              if ( v15 != 0 )
              {
                c0total += v15 * v27;
                total += v15;
                c1total += v15 * v12;
                c2total += v15 * v13;
                v7 = c2min;
              }
              v13 += 8;
              --v14;
            }
            while ( v14 != 0 );
            v6 = c1min;
            v10 = c2max;
            v11 = v20;
          }
          v9 = v21 + 32;
          v12 += 4;
          --v11;
          v21 += 32;
          v20 = v11;
        }
        while ( v11 != 0 );
        v5 = total;
        v3 = c0max;
        c0min = c0;
      }
      v27 += 8;
      c0 = ++c0min;
    }
    while ( c0min <= v3 );
  }
  (*cinfo->colormap)[icolor] = ((v5 >> 1) + c0total) / v5;
  *(_BYTE *)(icolor + *((_DWORD *)cinfo->colormap + 1)) = ((v5 >> 1) + c1total) / v5;
  *(_BYTE *)(icolor + *((_DWORD *)cinfo->colormap + 2)) = ((v5 >> 1) + c2total) / v5;
}

//------------------------------------------------------------------------------
// Address: 0x10011B90
// Name: select_colors
// Source: json
//------------------------------------------------------------------------------
void __usercall select_colors(jpeg_common_struct *cinfo@<edi>, int desired_colors)
{
  box *v2; // esi
  int v3; // eax
  int v4; // ebx
  jpeg_error_mgr *err; // ecx
  int numboxes; // [esp+10h] [ebp+8h]

  v2 = (box *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 32 * desired_colors);
  v2->c0max = 31;
  v2->c2max = 31;
  v2->c0min = 0;
  v2->c1min = 0;
  v2->c1max = 63;
  v2->c2min = 0;
  update_box(boxp: v2);
  v3 = median_cut((jpeg_decompress_struct *)cinfo, boxlist: v2, numboxes: 1, desired_colors);
  v4 = 0;
  numboxes = v3;
  if ( v3 > 0 )
  {
    do
      compute_color(boxp: v2++, (jpeg_decompress_struct *)cinfo, icolor: v4++);
    while ( v4 < numboxes );
    v3 = numboxes;
  }
  err = cinfo->err;
  *(_DWORD *)&cinfo[4].is_decompressor = v3;
  err->msg_code = 96;
  cinfo->err->msg_parm.i[0] = v3;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10011C20
// Name: find_nearby_colors
// Source: json
//------------------------------------------------------------------------------
int __usercall find_nearby_colors@<eax>(
        jpeg_decompress_struct *cinfo@<eax>,
        int minc1@<ecx>,
        int minc0,
        int minc2,
        unsigned __int8 *colorlist)
{
  int v5; // ebx
  int actual_number_of_colors; // esi
  int v8; // ecx
  unsigned __int8 **colormap; // eax
  unsigned __int8 *v10; // edx
  unsigned __int8 *v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // esi
  int v19; // eax
  int v20; // ecx
  int v21; // esi
  int v22; // ecx
  int v23; // eax
  int v24; // edx
  int result; // eax
  int j; // ecx
  int mindist[256]; // [esp+Ch] [ebp-428h]
  unsigned __int8 *v28; // [esp+40Ch] [ebp-28h]
  int numcolors; // [esp+410h] [ebp-24h]
  int centerc0; // [esp+414h] [ebp-20h]
  int centerc2; // [esp+418h] [ebp-1Ch]
  unsigned __int8 *v32; // [esp+41Ch] [ebp-18h]
  int maxc2; // [esp+420h] [ebp-14h]
  unsigned __int8 *v34; // [esp+424h] [ebp-10h]
  int centerc1; // [esp+428h] [ebp-Ch]
  int minmaxdist; // [esp+42Ch] [ebp-8h]
  int i; // [esp+430h] [ebp-4h]

  v5 = minc2;
  actual_number_of_colors = cinfo->actual_number_of_colors;
  v8 = minc0;
  centerc0 = (2 * minc0 + 24) >> 1;
  centerc1 = (2 * minc1 + 28) >> 1;
  numcolors = actual_number_of_colors;
  centerc2 = (2 * minc2 + 24) >> 1;
  minmaxdist = 0x7FFFFFFF;
  i = 0;
  if ( actual_number_of_colors > 0 )
  {
    colormap = cinfo->colormap;
    v28 = *colormap;
    v10 = colormap[1];
    v11 = colormap[2];
    v32 = v10;
    v34 = v11;
    while ( 1 )
    {
      v12 = v28[i];
      if ( v12 < v8 )
        break;
      v18 = v8 + 24;
      if ( v12 > v8 + 24 )
      {
        v13 = 2 * (v12 - v18) * 2 * (v12 - v18);
        goto LABEL_5;
      }
      v13 = 0;
      if ( v12 > centerc0 )
        goto LABEL_5;
      v14 = v12 - v18;
LABEL_6:
      v15 = v32[i];
      v16 = 2 * v14 * 2 * v14;
      if ( v15 < minc1 )
      {
        v5 = minc2;
        v13 += 3 * (v15 - minc1) * 3 * (v15 - minc1);
        v17 = v15 - (minc1 + 28);
        goto LABEL_15;
      }
      if ( v15 > minc1 + 28 )
      {
        v5 = minc2;
        v13 += 3 * (v15 - (minc1 + 28)) * 3 * (v15 - (minc1 + 28));
LABEL_14:
        v17 = v15 - minc1;
        goto LABEL_15;
      }
      if ( v15 > centerc1 )
        goto LABEL_14;
      v17 = v15 - (minc1 + 28);
LABEL_15:
      v19 = 3 * v17 * 3 * v17 + v16;
      v20 = v34[i];
      if ( v20 >= v5 )
      {
        maxc2 = v5 + 24;
        if ( v20 <= v5 + 24 )
        {
          if ( v20 <= centerc2 )
          {
            v22 = v20 - (v5 + 24);
            goto LABEL_22;
          }
        }
        else
        {
          v5 = minc2;
          v13 += (v20 - maxc2) * (v20 - maxc2);
        }
        v22 = v20 - v5;
      }
      else
      {
        v21 = v20 - v5;
        v5 = minc2;
        v13 += v21 * v21;
        v22 = v20 - (minc2 + 24);
      }
LABEL_22:
      v23 = v22 * v22 + v19;
      v8 = minc0;
      mindist[i] = v13;
      v24 = minmaxdist;
      if ( v23 < minmaxdist )
      {
        v24 = v23;
        minmaxdist = v23;
      }
      ++i;
      actual_number_of_colors = numcolors;
      if ( i >= numcolors )
        goto LABEL_29;
    }
    v13 = 2 * (v12 - v8) * 2 * (v12 - v8);
    v8 += 24;
LABEL_5:
    v14 = v12 - v8;
    goto LABEL_6;
  }
  v24 = minmaxdist;
LABEL_29:
  result = 0;
  for ( j = 0; j < actual_number_of_colors; ++j )
  {
    if ( mindist[j] <= v24 )
      colorlist[result++] = j;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011DB0
// Name: find_best_colors
// Source: json
//------------------------------------------------------------------------------
void __cdecl find_best_colors(
        jpeg_decompress_struct *cinfo,
        int minc0,
        int minc1,
        int minc2,
        int numcolors,
        unsigned __int8 *colorlist,
        unsigned __int8 *bestcolor)
{
  int v7; // eax
  int v8; // edx
  unsigned __int8 **colormap; // edi
  int v10; // ecx
  int v11; // eax
  int v12; // esi
  int v13; // edi
  int v14; // ebx
  unsigned __int8 *v15; // ecx
  int v16; // ebx
  int *v17; // eax
  int v18; // esi
  int v19; // edi
  int v20; // edi
  int v21; // edi
  int v22; // esi
  int v23; // ebx
  int v24; // edi
  int v25; // edi
  int v26; // edi
  int v27; // esi
  int v28; // ebx
  int v29; // edi
  int v30; // ebx
  int v31; // edi
  int v32; // edi
  int v33; // esi
  int v34; // edi
  int v35; // edi
  int v36; // edi
  bool v37; // zf
  bool v38; // sf
  int bestdist[128]; // [esp+4h] [ebp-228h] BYREF
  int inc1; // [esp+204h] [ebp-28h]
  int v41; // [esp+208h] [ebp-24h]
  int xx0; // [esp+20Ch] [ebp-20h]
  int i; // [esp+210h] [ebp-1Ch]
  int v44; // [esp+214h] [ebp-18h]
  int ic0; // [esp+218h] [ebp-14h]
  int dist0; // [esp+21Ch] [ebp-10h]
  int v47; // [esp+220h] [ebp-Ch]
  int xx1; // [esp+224h] [ebp-8h]
  int inc2; // [esp+228h] [ebp-4h]

  memset32(bestdist, 0x7FFFFFFF, 0x80u);
  v7 = 0;
  for ( i = 0; v7 < numcolors; i = v7 )
  {
    v8 = colorlist[v7];
    colormap = cinfo->colormap;
    v10 = 3 * (minc1 - colormap[1][v8]);
    v11 = minc2 - colormap[2][v8];
    v12 = 2 * (minc0 - (*colormap)[v8]);
    v13 = v12 * v12 + v10 * v10 + v11 * v11;
    v14 = 3 * v10 + 18;
    v15 = bestcolor;
    inc2 = 16 * (v11 + 4);
    xx0 = 32 * (v12 + 8);
    v16 = 8 * v14;
    dist0 = v13;
    inc1 = v16;
    v17 = bestdist;
    ic0 = 3;
    v47 = inc2 + 128;
    while ( 1 )
    {
      v18 = v13;
      xx1 = v16;
      v44 = 2;
      do
      {
        if ( v18 < *v17 )
        {
          *v17 = v18;
          *v15 = v8;
        }
        v19 = v18 + inc2;
        if ( v18 + inc2 < v17[1] )
        {
          v17[1] = v19;
          v15[1] = v8;
        }
        v20 = v47 + v19;
        if ( v20 < v17[2] )
        {
          v17[2] = v20;
          v15[2] = v8;
        }
        v21 = inc2 + 256 + v20;
        if ( v21 < v17[3] )
        {
          v17[3] = v21;
          v15[3] = v8;
        }
        v22 = xx1 + v18;
        if ( v22 < v17[4] )
        {
          v17[4] = v22;
          v15[4] = v8;
        }
        v23 = inc2;
        v24 = v22 + inc2;
        if ( v22 + inc2 < v17[5] )
        {
          v17[5] = v24;
          v15[5] = v8;
        }
        v25 = v23 + 128 + v24;
        if ( v25 < v17[6] )
        {
          v17[6] = v25;
          v15[6] = v8;
        }
        v26 = inc2 + 256 + v25;
        v41 = inc2 + 256;
        if ( v26 < v17[7] )
        {
          v17[7] = v26;
          v15[7] = v8;
        }
        v27 = v22 + xx1 + 288;
        if ( v27 < v17[8] )
        {
          v17[8] = v27;
          v15[8] = v8;
        }
        v28 = inc2;
        v29 = v27 + inc2;
        if ( v27 + inc2 < v17[9] )
        {
          v17[9] = v29;
          v15[9] = v8;
        }
        v30 = v28 + 128;
        v31 = v30 + v29;
        v47 = v30;
        if ( v31 < v17[10] )
        {
          v17[10] = v31;
          v15[10] = v8;
        }
        v32 = v41 + v31;
        if ( v32 < v17[11] )
        {
          v17[11] = v32;
          v15[11] = v8;
        }
        v33 = v27 + xx1 + 576;
        if ( v33 < v17[12] )
        {
          v17[12] = v33;
          v15[12] = v8;
        }
        v34 = v33 + inc2;
        if ( v33 + inc2 < v17[13] )
        {
          v17[13] = v34;
          v15[13] = v8;
        }
        v35 = v47 + v34;
        if ( v35 < v17[14] )
        {
          v17[14] = v35;
          v15[14] = v8;
        }
        v36 = v41 + v35;
        if ( v36 < v17[15] )
        {
          v17[15] = v36;
          v15[15] = v8;
        }
        v18 = v33 + xx1 + 864;
        v17 += 16;
        v15 += 16;
        v37 = v44-- == 1;
        xx1 += 1152;
      }
      while ( !v37 );
      v13 = xx0 + dist0;
      v38 = --ic0 < 0;
      dist0 += xx0;
      xx0 += 512;
      if ( v38 )
        break;
      v16 = inc1;
    }
    v7 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011FE0
// Name: fill_inverse_cmap
// Source: json
//------------------------------------------------------------------------------
void __usercall fill_inverse_cmap(int c1@<eax>, jpeg_decompress_struct *cinfo, int c0, int c2)
{
  int v4; // esi
  int nearby_colors; // eax
  unsigned __int8 *v6; // eax
  unsigned __int16 (**v7)[32]; // esi
  int v8; // edx
  int i; // edi
  unsigned __int16 *v10; // ecx
  unsigned __int16 *v11; // ecx
  int v12; // ecx
  unsigned __int16 *v13; // ecx
  _WORD *v14; // ecx
  unsigned __int16 *v15; // ecx
  _WORD *v16; // ecx
  __int16 v17; // bx
  unsigned __int8 colorlist[256]; // [esp+Ch] [ebp-188h] BYREF
  unsigned __int8 bestcolor[128]; // [esp+10Ch] [ebp-88h] BYREF
  int minc2; // [esp+18Ch] [ebp-8h]
  unsigned __int16 (**histogram)[32]; // [esp+190h] [ebp-4h]
  int c0b; // [esp+1A0h] [ebp+Ch]
  int c0a; // [esp+1A0h] [ebp+Ch]
  int c2b; // [esp+1A4h] [ebp+10h]
  int c2a; // [esp+1A4h] [ebp+10h]

  c2b = c2 >> 2;
  histogram = (unsigned __int16 (**)[32])cinfo->cquantize[1].finish_pass;
  v4 = c1 >> 3;
  c0b = c0 >> 2;
  minc2 = 32 * c2b + 4;
  nearby_colors = find_nearby_colors(cinfo, minc1: 32 * (c1 >> 3) + 2, minc0: 32 * c0b + 4, minc2, colorlist);
  find_best_colors(
    cinfo,
    minc0: 32 * c0b + 4,
    minc1: 32 * v4 + 2,
    minc2,
    numcolors: nearby_colors,
    colorlist,
    bestcolor);
  c2a = 2 * (4 * c2b + (v4 << 8));
  v6 = bestcolor;
  v7 = &histogram[4 * c0b];
  for ( c0a = 4; c0a != 0; --c0a )
  {
    v8 = c2a;
    for ( i = 2; i != 0; --i )
    {
      v10 = (unsigned __int16 *)*v7;
      *(unsigned __int16 *)((char *)v10 + v8) = *v6 + 1;
      *(unsigned __int16 *)((char *)v10 + v8 + 2) = v6[1] + 1;
      *(unsigned __int16 *)((char *)v10 + v8 + 4) = v6[2] + 1;
      *(unsigned __int16 *)((char *)v10 + v8 + 6) = v6[3] + 1;
      v11 = (unsigned __int16 *)*v7;
      *(unsigned __int16 *)((char *)v11 + v8 + 64) = v6[4] + 1;
      *(unsigned __int16 *)((char *)v11 + v8 + 66) = v6[5] + 1;
      v12 = (int)v11 + v8 + 64;
      *(_WORD *)(v12 + 4) = v6[6] + 1;
      *(_WORD *)(v12 + 6) = v6[7] + 1;
      v13 = (unsigned __int16 *)*v7;
      *(unsigned __int16 *)((char *)v13 + v8 + 128) = v6[8] + 1;
      v14 = (unsigned __int16 *)((char *)v13 + v8 + 128);
      v14[1] = v6[9] + 1;
      v14[2] = v6[10] + 1;
      v14[3] = v6[11] + 1;
      v15 = (unsigned __int16 *)*v7;
      *(unsigned __int16 *)((char *)v15 + v8 + 192) = v6[12] + 1;
      v16 = (unsigned __int16 *)((char *)v15 + v8 + 192);
      v16[1] = v6[13] + 1;
      v16[2] = v6[14] + 1;
      v17 = v6[15] + 1;
      v6 += 16;
      v8 += 256;
      v16[3] = v17;
    }
    ++v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012190
// Name: pass2_no_dither
// Source: json
//------------------------------------------------------------------------------
void __cdecl pass2_no_dither(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  unsigned int output_width; // esi
  unsigned __int8 **v5; // edx
  int v6; // ebx
  unsigned __int8 *v7; // edi
  int v8; // esi
  int v9; // ecx
  int v10; // edx
  unsigned __int16 *v11; // eax
  bool v12; // zf
  void (__cdecl *finish_pass)(jpeg_decompress_struct *); // edi
  int v14; // esi
  int v15; // edi
  int nearby_colors; // eax
  unsigned __int8 *v17; // eax
  int *v18; // esi
  int v19; // edx
  int i; // edi
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  int v24; // ecx
  _WORD *v25; // ecx
  int v26; // ecx
  _WORD *v27; // ecx
  __int16 v28; // bx
  char v29; // dl
  unsigned __int8 *v30; // eax
  unsigned __int8 colorlist[256]; // [esp+4h] [ebp-1B0h] BYREF
  unsigned __int8 bestcolor[128]; // [esp+104h] [ebp-B0h] BYREF
  unsigned __int8 *inptr; // [esp+184h] [ebp-30h]
  unsigned __int16 (**histogram)[32]; // [esp+188h] [ebp-2Ch]
  unsigned int width; // [esp+18Ch] [ebp-28h]
  int v36; // [esp+190h] [ebp-24h]
  int v37; // [esp+194h] [ebp-20h]
  unsigned __int16 *cachep; // [esp+198h] [ebp-1Ch]
  void (__cdecl *v39)(jpeg_decompress_struct *); // [esp+19Ch] [ebp-18h]
  unsigned __int8 *outptr; // [esp+1A0h] [ebp-14h]
  unsigned int col; // [esp+1A4h] [ebp-10h]
  int v42; // [esp+1A8h] [ebp-Ch]
  unsigned __int8 **v43; // [esp+1ACh] [ebp-8h]
  int v44; // [esp+1B0h] [ebp-4h]
  int num_rowsb; // [esp+1C8h] [ebp+14h]
  int num_rowsa; // [esp+1C8h] [ebp+14h]

  output_width = cinfo->output_width;
  histogram = (unsigned __int16 (**)[32])cinfo->cquantize[1].finish_pass;
  width = output_width;
  if ( num_rows > 0 )
  {
    v5 = output_buf;
    v6 = (char *)input_buf - (char *)output_buf;
    v43 = output_buf;
    v37 = (char *)input_buf - (char *)output_buf;
    v42 = num_rows;
    do
    {
      v7 = *(unsigned __int8 **)((char *)v5 + v6);
      outptr = *v5;
      col = output_width;
      if ( output_width != 0 )
      {
        do
        {
          v8 = v7[1] >> 2;
          v9 = *v7 >> 3;
          v10 = v7[2] >> 3;
          v11 = &histogram[v9][v8][v10];
          v7 += 3;
          v12 = *v11 == 0;
          inptr = v7;
          cachep = v11;
          if ( v12 )
          {
            finish_pass = cinfo->cquantize[1].finish_pass;
            v36 = v9 >> 2;
            v39 = finish_pass;
            v14 = v8 >> 3;
            v44 = v10 >> 2;
            v15 = 32 * (v9 >> 2) + 4;
            num_rowsb = 32 * (v10 >> 2) + 4;
            nearby_colors = find_nearby_colors(cinfo, minc1: 32 * v14 + 2, minc0: v15, minc2: num_rowsb, colorlist);
            find_best_colors(
              cinfo,
              minc0: v15,
              minc1: 32 * v14 + 2,
              minc2: num_rowsb,
              numcolors: nearby_colors,
              colorlist,
              bestcolor);
            v44 = 2 * (4 * v44 + (v14 << 8));
            v17 = bestcolor;
            v18 = (int *)((char *)v39 + 16 * v36);
            for ( num_rowsa = 4; num_rowsa != 0; --num_rowsa )
            {
              v19 = v44;
              for ( i = 2; i != 0; --i )
              {
                v21 = *v18;
                *(_WORD *)(v21 + v19) = *v17 + 1;
                *(_WORD *)(v21 + v19 + 2) = v17[1] + 1;
                *(_WORD *)(v21 + v19 + 4) = v17[2] + 1;
                *(_WORD *)(v19 + v21 + 6) = v17[3] + 1;
                v22 = *v18;
                *(_WORD *)(v19 + v22 + 64) = v17[4] + 1;
                *(_WORD *)(v19 + v22 + 66) = v17[5] + 1;
                v23 = v19 + v22 + 64;
                *(_WORD *)(v23 + 4) = v17[6] + 1;
                *(_WORD *)(v23 + 6) = v17[7] + 1;
                v24 = *v18;
                *(_WORD *)(v19 + v24 + 128) = v17[8] + 1;
                v25 = (_WORD *)(v19 + v24 + 128);
                v25[1] = v17[9] + 1;
                v25[2] = v17[10] + 1;
                v25[3] = v17[11] + 1;
                v26 = *v18;
                *(_WORD *)(v19 + v26 + 192) = v17[12] + 1;
                v27 = (_WORD *)(v19 + v26 + 192);
                v27[1] = v17[13] + 1;
                v27[2] = v17[14] + 1;
                v28 = v17[15] + 1;
                v17 += 16;
                v19 += 256;
                v27[3] = v28;
              }
              ++v18;
            }
            v7 = inptr;
            v11 = cachep;
          }
          v29 = *(_BYTE *)v11;
          v30 = outptr;
          *outptr = v29 - 1;
          v12 = col-- == 1;
          outptr = v30 + 1;
        }
        while ( !v12 );
        v5 = v43;
        v6 = v37;
        output_width = width;
      }
      ++v5;
      v12 = v42-- == 1;
      v43 = v5;
    }
    while ( !v12 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100123E0
// Name: pass2_fs_dither
// Source: json
//------------------------------------------------------------------------------
void __cdecl pass2_fs_dither(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        unsigned __int8 *num_rows)
{
  unsigned int output_width; // edx
  jpeg_color_quantizer *p_pub; // esi
  unsigned __int8 **colormap; // eax
  int *finish_pass; // ecx
  int v8; // ebx
  __int16 *v9; // eax
  int v10; // esi
  int v11; // edi
  int v12; // esi
  int v13; // edi
  int v14; // ebx
  int v15; // ecx
  unsigned __int16 *v16; // edx
  bool v17; // zf
  unsigned __int16 *v18; // ecx
  int v19; // eax
  int v20; // edi
  int v21; // ebx
  int v22; // eax
  int v23; // esi
  int v24; // eax
  int v25; // eax
  unsigned __int8 *colormap2; // [esp+8h] [ebp-64h]
  unsigned __int8 *colormap1; // [esp+Ch] [ebp-60h]
  unsigned __int8 *colormap0; // [esp+10h] [ebp-5Ch]
  unsigned __int16 *cachep; // [esp+14h] [ebp-58h]
  unsigned __int16 (**histogram)[32]; // [esp+1Ch] [ebp-50h]
  int v31; // [esp+20h] [ebp-4Ch]
  unsigned __int8 *v32; // [esp+24h] [ebp-48h]
  my_cquantizer *cquantize; // [esp+28h] [ebp-44h]
  int *error_limit; // [esp+2Ch] [ebp-40h]
  unsigned int width; // [esp+30h] [ebp-3Ch]
  unsigned int col; // [esp+34h] [ebp-38h]
  int dir; // [esp+38h] [ebp-34h]
  __int16 belowerr2; // [esp+3Ch] [ebp-30h]
  __int16 belowerr1; // [esp+40h] [ebp-2Ch]
  __int16 belowerr0; // [esp+44h] [ebp-28h]
  unsigned __int8 **v41; // [esp+48h] [ebp-24h]
  __int16 bpreverr2; // [esp+4Ch] [ebp-20h]
  __int16 bpreverr1; // [esp+50h] [ebp-1Ch]
  __int16 bpreverr0; // [esp+54h] [ebp-18h]
  unsigned __int8 *range_limit; // [esp+58h] [ebp-14h]
  unsigned __int8 *outptr; // [esp+5Ch] [ebp-10h]
  int dir3; // [esp+60h] [ebp-Ch]
  int bnexterr; // [esp+64h] [ebp-8h]
  __int16 *errorptr; // [esp+68h] [ebp-4h]
  unsigned __int8 *inptr; // [esp+80h] [ebp+14h]

  output_width = cinfo->output_width;
  p_pub = cinfo->cquantize;
  histogram = (unsigned __int16 (**)[32])p_pub[1].finish_pass;
  colormap = cinfo->colormap;
  colormap0 = *colormap;
  colormap2 = colormap[2];
  range_limit = cinfo->sample_range_limit;
  finish_pass = (int *)p_pub[2].finish_pass;
  cquantize = (my_cquantizer *)p_pub;
  width = output_width;
  error_limit = finish_pass;
  colormap1 = colormap[1];
  if ( (int)num_rows > 0 )
  {
    v31 = (char *)input_buf - (char *)output_buf;
    v41 = output_buf;
    v32 = num_rows;
    v8 = 0;
    do
    {
      inptr = *(unsigned __int8 **)((char *)v41 + v31);
      outptr = *v41;
      if ( LOBYTE(p_pub[2].color_quantize) != 0 )
      {
        outptr = &(*v41)[output_width - 1];
        v9 = (__int16 *)((char *)p_pub[2].start_pass + 6 * output_width + 6);
        inptr = &(*(unsigned __int8 **)((char *)v41 + v31))[2 * output_width - 3 + output_width];
        dir = -1;
        dir3 = -3;
        errorptr = v9;
        LOBYTE(p_pub[2].color_quantize) = 0;
      }
      else
      {
        dir = 1;
        dir3 = 3;
        errorptr = (__int16 *)p_pub[2].start_pass;
        LOBYTE(p_pub[2].color_quantize) = 1;
        v9 = errorptr;
      }
      output_width = width;
      v10 = 0;
      v11 = 0;
      belowerr2 = 0;
      belowerr1 = 0;
      belowerr0 = 0;
      bpreverr2 = 0;
      bpreverr1 = 0;
      bpreverr0 = 0;
      col = width;
      if ( width != 0 )
      {
        do
        {
          v12 = range_limit[*inptr + finish_pass[(v9[dir3] + v10 + 8) >> 4]];
          v13 = range_limit[inptr[1] + finish_pass[(v9[dir3 + 1] + v11 + 8) >> 4]];
          v14 = range_limit[inptr[2] + finish_pass[(v9[dir3 + 2] + v8 + 8) >> 4]];
          v15 = (v14 >> 3) + 32 * (v13 >> 2);
          v16 = (unsigned __int16 *)histogram[v12 >> 3];
          v17 = v16[v15] == 0;
          v18 = &v16[v15];
          cachep = v18;
          if ( v17 )
          {
            fill_inverse_cmap(c1: v13 >> 2, cinfo, c0: v12 >> 3, c2: v14 >> 3);
            v18 = cachep;
          }
          v19 = *v18 - 1;
          *outptr = v19;
          v20 = v13 - colormap1[v19];
          v21 = v14 - colormap2[v19];
          bnexterr = v12 - colormap0[v19];
          *errorptr = 3 * bnexterr + bpreverr0;
          v22 = 6 * bnexterr;
          v23 = 9 * bnexterr;
          bpreverr0 = 9 * bnexterr + belowerr0;
          belowerr0 = bnexterr;
          LOWORD(bnexterr) = v20;
          v20 *= 3;
          errorptr[1] = v20 + bpreverr1;
          v10 = v22 + v23;
          v24 = 2 * v20;
          v20 *= 3;
          bpreverr1 = v20 + belowerr1;
          belowerr1 = bnexterr;
          LOWORD(bnexterr) = v21;
          v21 *= 3;
          v11 = v24 + v20;
          errorptr[2] = v21 + bpreverr2;
          v25 = 2 * v21;
          v21 *= 3;
          bpreverr2 = v21 + belowerr2;
          v8 = v25 + v21;
          inptr += dir3;
          belowerr2 = bnexterr;
          outptr += dir;
          v17 = col-- == 1;
          v9 = &errorptr[dir3];
          finish_pass = error_limit;
          errorptr = v9;
        }
        while ( !v17 );
        output_width = width;
      }
      ++v41;
      p_pub = &cquantize->pub;
      *v9 = bpreverr0;
      v9[1] = bpreverr1;
      v8 = 0;
      v17 = v32-- == (unsigned __int8 *)1;
      v9[2] = bpreverr2;
    }
    while ( !v17 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012660
// Name: init_error_limit
// Source: json
//------------------------------------------------------------------------------
void __usercall init_error_limit(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_color_quantizer *v1; // esi
  int v2; // eax
  int v3; // edx
  int v4; // ecx
  int v5; // edi
  _DWORD *v6; // esi
  _DWORD *v7; // esi
  _DWORD *v8; // esi

  v1 = *(jpeg_color_quantizer **)&cinfo[17].is_decompressor;
  v2 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 2044) + 1020;
  v1[2].finish_pass = (void (__cdecl *)(jpeg_decompress_struct *))v2;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = (_DWORD *)v2;
  do
  {
    *(_DWORD *)(v2 + 4 * v4) = v3;
    *v6 = v5;
    ++v4;
    --v6;
    ++v3;
    --v5;
  }
  while ( v4 < 16 );
  if ( v4 < 48 )
  {
    v7 = (_DWORD *)(v2 - 4 * v4);
    do
    {
      *(_DWORD *)(v2 + 4 * v4) = v3;
      *v7 = -v3;
      ++v4;
      --v7;
      v3 += (v4 & 1) == 0;
    }
    while ( v4 < 48 );
  }
  if ( v4 <= 255 )
  {
    v8 = (_DWORD *)(v2 - 4 * v4);
    do
    {
      *(_DWORD *)(v2 + 4 * v4) = v3;
      *v8 = -v3;
      ++v4;
      --v8;
    }
    while ( v4 <= 255 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012700
// Name: finish_pass1
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass1(jpeg_common_struct *cinfo)
{
  jpeg_color_quantizer *v1; // esi

  v1 = *(jpeg_color_quantizer **)&cinfo[17].is_decompressor;
  cinfo[4].global_state = (int)v1[1].start_pass;
  select_colors(cinfo, desired_colors: (int)v1[1].color_quantize);
  LOBYTE(v1[1].new_color_map) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012740
// Name: start_pass_2_quant
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_2_quant(unsigned __int16 (**cinfo)[32], unsigned __int8 is_pre_scan)
{
  bool v3; // zf
  jpeg_color_quantizer *v4; // edi
  int v5; // ebx
  unsigned int v6; // ebx
  int i; // esi
  unsigned __int16 (**histogram)[32]; // [esp+10h] [ebp+8h]

  v3 = cinfo[19] == nullptr;
  v4 = (jpeg_color_quantizer *)cinfo[106];
  histogram = (unsigned __int16 (**)[32])v4[1].finish_pass;
  if ( !v3 )
    cinfo[19] = (unsigned __int16 (*)[32])2;
  if ( is_pre_scan != 0 )
  {
    v4->color_quantize = prescan_quantize;
    v4->finish_pass = (void (__cdecl *)(jpeg_decompress_struct *))finish_pass1;
    LOBYTE(v4[1].new_color_map) = 1;
  }
  else
  {
    if ( cinfo[19] == (unsigned __int16 (*)[32])2 )
      v4->color_quantize = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned __int8 **, int))pass2_fs_dither;
    else
      v4->color_quantize = pass2_no_dither;
    v4->finish_pass = (void (__cdecl *)(jpeg_decompress_struct *))jpeg_mem_term;
    v5 = (int)cinfo[28];
    if ( v5 < 1 )
    {
      *(_DWORD *)&(**cinfo)[10] = 56;
      *(_DWORD *)&(**cinfo)[12] = 1;
      ((void (__cdecl *)(unsigned __int16 (**)[32]))(**cinfo)[0])(a1: cinfo);
    }
    if ( v5 > 256 )
    {
      *(_DWORD *)&(**cinfo)[10] = 57;
      *(_DWORD *)&(**cinfo)[12] = 256;
      ((void (__cdecl *)(unsigned __int16 (**)[32]))(**cinfo)[0])(a1: cinfo);
    }
    if ( cinfo[19] == (unsigned __int16 (*)[32])2 )
    {
      v6 = 2 * (3 * (_DWORD)cinfo[23] + 6);
      if ( v4[2].start_pass == nullptr )
        v4[2].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8))(*(int (__cdecl **)(unsigned __int16 (**)[32], int, unsigned int))&(*cinfo[1])[2])(
                                                                                          a1: cinfo,
                                                                                          a2: 1,
                                                                                          a3: v6);
      jzero_far(target: v4[2].start_pass, bytestozero: v6);
      if ( v4[2].finish_pass == nullptr )
        init_error_limit((jpeg_common_struct *)cinfo);
      LOBYTE(v4[2].color_quantize) = 0;
    }
  }
  if ( LOBYTE(v4[1].new_color_map) != 0 )
  {
    for ( i = 0; i < 32; ++i )
      jzero_far(target: histogram[i], bytestozero: 0x1000u);
    LOBYTE(v4[1].new_color_map) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012860
// Name: new_color_map_2_quant
// Source: json
//------------------------------------------------------------------------------
void __cdecl new_color_map_2_quant(jpeg_decompress_struct *cinfo)
{
  LOBYTE(cinfo->cquantize[1].new_color_map) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012880
// Name: _jinit_2pass_quantizer
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_2pass_quantizer(jpeg_common_struct *cinfo)
{
  int v1; // edi
  int v2; // ebx
  signed int client_data; // ebx

  v1 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 44);
  *(_DWORD *)&cinfo[17].is_decompressor = v1;
  v2 = 0;
  *(_DWORD *)v1 = start_pass_2_quant;
  *(_DWORD *)(v1 + 12) = new_color_map_2_quant;
  *(_DWORD *)(v1 + 32) = 0;
  *(_DWORD *)(v1 + 40) = 0;
  if ( cinfo[4].mem != (jpeg_memory_mgr *)3 )
  {
    cinfo->err->msg_code = 47;
    cinfo->err->error_exit(a1: cinfo);
  }
  *(_DWORD *)(v1 + 24) = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 128);
  do
  {
    *(_DWORD *)(v2 + *(_DWORD *)(v1 + 24)) = cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: 4096);
    v2 += 4;
  }
  while ( v2 < 128 );
  *(_BYTE *)(v1 + 28) = 1;
  if ( *(&cinfo[3].is_decompressor + 2) != 0 )
  {
    client_data = (signed int)cinfo[3].client_data;
    if ( client_data < 8 )
    {
      cinfo->err->msg_code = 56;
      cinfo->err->msg_parm.i[0] = 8;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( client_data > 256 )
    {
      cinfo->err->msg_code = 57;
      cinfo->err->msg_parm.i[0] = 256;
      cinfo->err->error_exit(a1: cinfo);
    }
    *(_DWORD *)(v1 + 16) = cinfo->mem->alloc_sarray(a1: cinfo, a2: 1, a3: client_data, a4: 3);
    *(_DWORD *)(v1 + 20) = client_data;
  }
  else
  {
    *(_DWORD *)(v1 + 16) = 0;
  }
  if ( cinfo[3].mem != nullptr )
    cinfo[3].mem = (jpeg_memory_mgr *)2;
  if ( cinfo[3].mem == (jpeg_memory_mgr *)2 )
  {
    *(_DWORD *)(v1 + 32) = cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: 6 * (cinfo[3].global_state + 2));
    init_error_limit(cinfo);
  }
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1027A260
// Name: prescan_quantize
// Source: json
//------------------------------------------------------------------------------
void __cdecl prescan_quantize(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  unsigned int output_width; // eax
  void (__cdecl *finish_pass)(jpeg_decompress_struct *); // ebx
  int v6; // edi
  unsigned __int8 *v7; // ecx
  unsigned int v8; // esi
  int v9; // eax
  int v10; // edx
  bool v11; // zf
  _WORD *v12; // eax
  unsigned int width; // [esp+10h] [ebp+8h]

  output_width = cinfo->output_width;
  finish_pass = cinfo->cquantize[1].finish_pass;
  v6 = 0;
  for ( width = output_width; v6 < num_rows; ++v6 )
  {
    v7 = input_buf[v6];
    v8 = output_width;
    if ( output_width != 0 )
    {
      do
      {
        v9 = (v7[2] >> 3) + 32 * (v7[1] >> 2);
        v10 = *((_DWORD *)finish_pass + (*v7 >> 3));
        v11 = (*(_WORD *)(v10 + 2 * v9))++ == 0xFFFF;
        v12 = (_WORD *)(v10 + 2 * v9);
        if ( v11 )
          --*v12;
        v7 += 3;
        --v8;
      }
      while ( v8 != 0 );
      output_width = width;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027A2D0
// Name: update_box
// Source: json
//------------------------------------------------------------------------------
void __cdecl update_box(box *boxp)
{
  jpeg_decompress_struct *cinfo; // ecx
  int v2; // ebx
  int v3; // edi
  int v4; // esi
  int v5; // edx
  __int16 *v6; // ecx
  int v7; // eax
  __int16 v8; // bx
  int v9; // esi
  int v10; // edx
  __int16 *v11; // ecx
  int v12; // eax
  __int16 v13; // bx
  int v14; // esi
  int v15; // edx
  unsigned __int16 *v16; // eax
  int v17; // ecx
  __int16 v18; // bx
  int v19; // esi
  int v20; // edx
  unsigned __int16 *v21; // eax
  int v22; // ecx
  __int16 v23; // bx
  int v24; // eax
  int v25; // edx
  int v26; // esi
  int v27; // ecx
  unsigned __int16 *v28; // eax
  int v29; // eax
  int v30; // edx
  int v31; // esi
  int v32; // ecx
  unsigned __int16 *v33; // eax
  int v34; // edi
  int v35; // eax
  int v36; // ebx
  int v37; // ecx
  int v38; // edx
  _WORD *v39; // eax
  int v40; // ecx
  int ccount; // [esp+Ch] [ebp-24h]
  int c2max; // [esp+10h] [ebp-20h]
  unsigned __int16 (**histogram)[32]; // [esp+14h] [ebp-1Ch]
  int c0min; // [esp+18h] [ebp-18h]
  int c0mina; // [esp+18h] [ebp-18h]
  int c0; // [esp+1Ch] [ebp-14h]
  int c0a; // [esp+1Ch] [ebp-14h]
  int c0b; // [esp+1Ch] [ebp-14h]
  int c0c; // [esp+1Ch] [ebp-14h]
  int c0d; // [esp+1Ch] [ebp-14h]
  int c0e; // [esp+1Ch] [ebp-14h]
  int c0f; // [esp+1Ch] [ebp-14h]
  int c1max; // [esp+20h] [ebp-10h]
  int c0max; // [esp+24h] [ebp-Ch]
  int c1min; // [esp+28h] [ebp-8h]
  int c2min; // [esp+2Ch] [ebp-4h]

  v2 = boxp->c2min;
  histogram = (unsigned __int16 (**)[32])cinfo->cquantize[1].finish_pass;
  v3 = boxp->c2max;
  c1min = boxp->c1min;
  c0min = boxp->c0min;
  c0max = boxp->c0max;
  c1max = boxp->c1max;
  c2min = v2;
  c2max = v3;
  if ( boxp->c0min < c0max )
  {
    c0 = boxp->c0min;
    while ( 1 )
    {
      v4 = boxp->c1min;
      if ( c1min <= c1max )
        break;
LABEL_9:
      if ( ++c0 > c0max )
        goto LABEL_12;
    }
    v5 = (int)&histogram[c0][c1min][v2];
    while ( 1 )
    {
      v6 = (__int16 *)v5;
      v7 = v2;
      if ( c2min <= v3 )
        break;
LABEL_8:
      v2 = boxp->c2min;
      ++v4;
      v5 += 64;
      if ( v4 > c1max )
        goto LABEL_9;
    }
    while ( 1 )
    {
      v8 = *v6++;
      if ( v8 != 0 )
        break;
      if ( ++v7 > v3 )
        goto LABEL_8;
    }
    v2 = boxp->c2min;
    c0min = c0;
    boxp->c0min = c0;
LABEL_12:
    if ( c0max > c0min )
    {
      c0a = c0max;
      while ( 1 )
      {
        v9 = c1min;
        if ( c1min <= c1max )
          break;
LABEL_20:
        if ( --c0a < c0min )
          goto have_c0max;
      }
      v10 = (int)&histogram[c0a][c1min][v2];
      while ( 1 )
      {
        v11 = (__int16 *)v10;
        v12 = v2;
        if ( c2min <= v3 )
          break;
LABEL_19:
        v2 = c2min;
        ++v9;
        v10 += 64;
        if ( v9 > c1max )
          goto LABEL_20;
      }
      while ( 1 )
      {
        v13 = *v11++;
        if ( v13 != 0 )
          break;
        if ( ++v12 > v3 )
          goto LABEL_19;
      }
      v2 = c2min;
      c0max = c0a;
      boxp->c0max = c0a;
    }
  }
have_c0max:
  if ( c1min < c1max )
  {
    c0b = c1min;
    v14 = v2 + 32 * c1min;
    while ( 1 )
    {
      v15 = c0min;
      if ( c0min <= c0max )
        break;
LABEL_30:
      v14 += 32;
      if ( ++c0b > c1max )
        goto have_c1min;
    }
    while ( 1 )
    {
      v16 = &(*histogram[v15])[v14];
      v17 = v2;
      if ( c2min <= v3 )
        break;
LABEL_29:
      v2 = c2min;
      if ( ++v15 > c0max )
        goto LABEL_30;
    }
    while ( 1 )
    {
      v18 = *v16++;
      if ( v18 != 0 )
        break;
      if ( ++v17 > v3 )
        goto LABEL_29;
    }
    v2 = c2min;
    c1min = c0b;
    boxp->c1min = c0b;
have_c1min:
    if ( c1max > c1min )
    {
      c0c = c1max;
      v19 = v2 + 32 * c1max;
      while ( 1 )
      {
        v20 = c0min;
        if ( c0min <= c0max )
          break;
LABEL_40:
        v19 -= 32;
        if ( --c0c < c1min )
          goto have_c1max;
      }
      while ( 1 )
      {
        v21 = &(*histogram[v20])[v19];
        v22 = v2;
        if ( c2min <= v3 )
          break;
LABEL_39:
        v2 = c2min;
        if ( ++v20 > c0max )
          goto LABEL_40;
      }
      while ( 1 )
      {
        v23 = *v21++;
        if ( v23 != 0 )
          break;
        if ( ++v22 > v3 )
          goto LABEL_39;
      }
      v2 = c2min;
      c1max = c0c;
      boxp->c1max = c0c;
    }
  }
have_c1max:
  if ( v2 < v3 )
  {
    v24 = v2;
    c0d = v2;
    while ( 1 )
    {
      v25 = c0min;
      if ( c0min <= c0max )
        break;
LABEL_52:
      c0d = ++v24;
      if ( v24 > v3 )
        goto have_c2min;
    }
    v26 = v24 + 32 * c1min;
    while ( 1 )
    {
      v27 = c1min;
      v28 = &(*histogram[v25])[v26];
      if ( c1min <= c1max )
        break;
LABEL_50:
      if ( ++v25 > c0max )
      {
        v3 = c2max;
        v24 = c0d;
        goto LABEL_52;
      }
    }
    while ( *v28 == 0 )
    {
      ++v27;
      v28 += 32;
      if ( v27 > c1max )
        goto LABEL_50;
    }
    v2 = c0d;
    v3 = c2max;
    c2min = c0d;
    boxp->c2min = c0d;
have_c2min:
    if ( v3 > v2 )
    {
      v29 = v3;
      c0e = v3;
      while ( 1 )
      {
        v30 = c0min;
        if ( c0min <= c0max )
          break;
LABEL_64:
        c0e = --v29;
        if ( v29 < v2 )
          goto have_c2max;
      }
      v31 = v29 + 32 * c1min;
      while ( 1 )
      {
        v32 = c1min;
        v33 = &(*histogram[v30])[v31];
        if ( c1min <= c1max )
          break;
LABEL_62:
        if ( ++v30 > c0max )
        {
          v29 = c0e;
          v3 = c2max;
          goto LABEL_64;
        }
      }
      while ( *v33 == 0 )
      {
        ++v32;
        v33 += 32;
        if ( v32 > c1max )
          goto LABEL_62;
      }
      v3 = c0e;
      c2max = c0e;
      boxp->c2max = c0e;
    }
  }
have_c2max:
  v34 = v3 - v2;
  v35 = c0min;
  v36 = 0;
  boxp->volume = 16 * (c0max - c0min) * 16 * (c0max - c0min)
               + 12 * (c1max - c1min) * 12 * (c1max - c1min)
               + 8 * v34 * 8 * v34;
  ccount = 0;
  c0f = c0min;
  if ( c0min > c0max )
  {
    boxp->colorcount = 0;
  }
  else
  {
    v37 = c1min;
    do
    {
      if ( v37 <= c1max )
      {
        v38 = (int)&histogram[v35][v37][c2min];
        c0mina = c1max - c1min + 1;
        do
        {
          v36 = ccount;
          v39 = (_WORD *)v38;
          if ( c2min <= c2max )
          {
            v40 = v34 + 1;
            do
            {
              if ( *v39 != 0 )
                ++v36;
              ++v39;
              --v40;
            }
            while ( v40 != 0 );
            ccount = v36;
          }
          v38 += 64;
          --c0mina;
        }
        while ( c0mina != 0 );
        v35 = c0f;
        v37 = c1min;
      }
      c0f = ++v35;
    }
    while ( v35 <= c0max );
    boxp->colorcount = v36;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027A640
// Name: median_cut
// Source: json
//------------------------------------------------------------------------------
int __cdecl median_cut(jpeg_decompress_struct *cinfo, box *boxlist, int numboxes, int desired_colors)
{
  int v4; // ecx
  int result; // eax
  box *v6; // edx
  int *p_c1max; // esi
  int v8; // ebx
  int *p_colorcount; // edx
  int j; // ecx
  int *p_volume; // edx
  int i; // ecx
  int v13; // edx
  int v14; // ebx
  int v15; // ebx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  box *boxp; // [esp+0h] [ebp-8h]
  int v20; // [esp+4h] [ebp-4h]

  v4 = desired_colors;
  result = numboxes;
  v6 = boxlist;
  if ( numboxes < desired_colors )
  {
    v20 = 2 * numboxes;
    p_c1max = &boxlist[numboxes].c1max;
    while ( 1 )
    {
      v8 = 0;
      boxp = nullptr;
      if ( v20 > v4 )
      {
        if ( result > 0 )
        {
          p_volume = &v6->volume;
          for ( i = result; i != 0; --i )
          {
            if ( *p_volume > v8 )
            {
              boxp = (box *)(p_volume - 6);
              v8 = *p_volume;
            }
            p_volume += 8;
          }
        }
      }
      else if ( result > 0 )
      {
        p_colorcount = &v6->colorcount;
        for ( j = result; j != 0; --j )
        {
          if ( *p_colorcount > v8 && *(p_colorcount - 1) > 0 )
          {
            boxp = (box *)(p_colorcount - 7);
            v8 = *p_colorcount;
          }
          p_colorcount += 8;
        }
      }
      if ( boxp == nullptr )
        break;
      *(p_c1max - 2) = boxp->c0max;
      *p_c1max = boxp->c1max;
      p_c1max[2] = boxp->c2max;
      *(p_c1max - 3) = boxp->c0min;
      *(p_c1max - 1) = boxp->c1min;
      p_c1max[1] = boxp->c2min;
      v13 = 12 * (boxp->c1max - boxp->c1min);
      v14 = 1;
      if ( 16 * (boxp->c0max - boxp->c0min) > v13 )
      {
        v13 = 16 * (boxp->c0max - boxp->c0min);
        v14 = 0;
      }
      if ( 8 * (boxp->c2max - boxp->c2min) > v13 )
        v14 = 2;
      if ( v14 != 0 )
      {
        v15 = v14 - 1;
        if ( v15 != 0 )
        {
          if ( v15 == 1 )
          {
            v16 = (boxp->c2min + boxp->c2max) / 2;
            boxp->c2max = v16;
            p_c1max[1] = v16 + 1;
          }
        }
        else
        {
          v17 = (boxp->c1min + boxp->c1max) / 2;
          boxp->c1max = v17;
          *(p_c1max - 1) = v17 + 1;
        }
      }
      else
      {
        v18 = (boxp->c0min + boxp->c0max) / 2;
        boxp->c0max = v18;
        *(p_c1max - 3) = v18 + 1;
      }
      update_box(cinfo, boxp);
      update_box(cinfo, boxp: (box *)(p_c1max - 3));
      v4 = desired_colors;
      v20 += 2;
      result = numboxes + 1;
      p_c1max += 8;
      numboxes = result;
      if ( result >= desired_colors )
        break;
      v6 = boxlist;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1027A7B0
// Name: compute_color
// Source: json
//------------------------------------------------------------------------------
void __usercall compute_color(box *boxp@<eax>, jpeg_decompress_struct *cinfo, int icolor)
{
  int v3; // edx
  int v4; // ebx
  int v5; // esi
  int v6; // ecx
  int v7; // edi
  int c0min; // eax
  unsigned __int16 *v9; // ebx
  int v10; // edx
  int v11; // eax
  int v12; // esi
  int v13; // ecx
  int v14; // edx
  int v15; // eax
  int c0max; // [esp+Ch] [ebp-3Ch]
  int c1min; // [esp+10h] [ebp-38h]
  int c2min; // [esp+18h] [ebp-30h]
  int c0; // [esp+20h] [ebp-28h]
  int v20; // [esp+24h] [ebp-24h]
  unsigned __int16 *v21; // [esp+28h] [ebp-20h]
  int c2max; // [esp+2Ch] [ebp-1Ch]
  int c1max; // [esp+30h] [ebp-18h]
  int c2total; // [esp+34h] [ebp-14h]
  int c1total; // [esp+38h] [ebp-10h]
  int c0total; // [esp+3Ch] [ebp-Ch]
  int v27; // [esp+40h] [ebp-8h]
  int total; // [esp+44h] [ebp-4h]

  v3 = boxp->c0max;
  v4 = boxp->c2max;
  v5 = 0;
  v6 = boxp->c1min;
  c1max = boxp->c1max;
  v7 = boxp->c2min;
  c0min = boxp->c0min;
  total = 0;
  c0total = 0;
  c1total = 0;
  c2total = 0;
  c0max = v3;
  c1min = v6;
  c2min = v7;
  c2max = v4;
  c0 = c0min;
  if ( c0min <= v3 )
  {
    v27 = 8 * c0min + 4;
    do
    {
      if ( v6 <= c1max )
      {
        v9 = (unsigned __int16 *)(*((_DWORD *)cinfo->cquantize[1].finish_pass + c0min) + 2 * (v7 + 32 * v6));
        v10 = c2max;
        v11 = c1max - v6 + 1;
        v12 = 4 * v6 + 2;
        v21 = v9;
        v20 = v11;
        do
        {
          if ( v7 <= v10 )
          {
            v13 = 8 * v7 + 4;
            v14 = v10 - v7 + 1;
            do
            {
              v15 = *v9++;
              if ( v15 != 0 )
              {
                c0total += v15 * v27;
                total += v15;
                c1total += v15 * v12;
                c2total += v15 * v13;
                v7 = c2min;
              }
              v13 += 8;
              --v14;
            }
            while ( v14 != 0 );
            v6 = c1min;
            v10 = c2max;
            v11 = v20;
          }
          v9 = v21 + 32;
          v12 += 4;
          --v11;
          v21 += 32;
          v20 = v11;
        }
        while ( v11 != 0 );
        v5 = total;
        v3 = c0max;
        c0min = c0;
      }
      v27 += 8;
      c0 = ++c0min;
    }
    while ( c0min <= v3 );
  }
  (*cinfo->colormap)[icolor] = ((v5 >> 1) + c0total) / v5;
  *(_BYTE *)(icolor + *((_DWORD *)cinfo->colormap + 1)) = ((v5 >> 1) + c1total) / v5;
  *(_BYTE *)(icolor + *((_DWORD *)cinfo->colormap + 2)) = ((v5 >> 1) + c2total) / v5;
}

//------------------------------------------------------------------------------
// Address: 0x1027A900
// Name: select_colors
// Source: json
//------------------------------------------------------------------------------
void __usercall select_colors(jpeg_common_struct *cinfo@<edi>, int desired_colors)
{
  box *v2; // esi
  int v3; // eax
  int v4; // ebx
  jpeg_error_mgr *err; // ecx
  int numboxes; // [esp+10h] [ebp+8h]

  v2 = (box *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 32 * desired_colors);
  v2->c0max = 31;
  v2->c2max = 31;
  v2->c0min = 0;
  v2->c1min = 0;
  v2->c1max = 63;
  v2->c2min = 0;
  update_box((jpeg_decompress_struct *)cinfo, boxp: v2);
  v3 = median_cut((jpeg_decompress_struct *)cinfo, boxlist: v2, numboxes: 1, desired_colors);
  v4 = 0;
  numboxes = v3;
  if ( v3 > 0 )
  {
    do
      compute_color(boxp: v2++, (jpeg_decompress_struct *)cinfo, icolor: v4++);
    while ( v4 < numboxes );
    v3 = numboxes;
  }
  err = cinfo->err;
  *(_DWORD *)&cinfo[4].is_decompressor = v3;
  err->msg_code = 96;
  cinfo->err->msg_parm.i[0] = v3;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1027A990
// Name: find_nearby_colors
// Source: json
//------------------------------------------------------------------------------
int __usercall find_nearby_colors@<eax>(
        jpeg_decompress_struct *cinfo@<eax>,
        int minc1@<ecx>,
        int minc0,
        int minc2,
        unsigned __int8 *colorlist)
{
  int v5; // ebx
  int actual_number_of_colors; // esi
  int v8; // ecx
  unsigned __int8 **colormap; // eax
  unsigned __int8 *v10; // edx
  unsigned __int8 *v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // esi
  int v19; // eax
  int v20; // ecx
  int v21; // esi
  int v22; // ecx
  int v23; // eax
  int v24; // edx
  int result; // eax
  int j; // ecx
  int mindist[256]; // [esp+Ch] [ebp-428h]
  unsigned __int8 *v28; // [esp+40Ch] [ebp-28h]
  int numcolors; // [esp+410h] [ebp-24h]
  int centerc0; // [esp+414h] [ebp-20h]
  int centerc2; // [esp+418h] [ebp-1Ch]
  unsigned __int8 *v32; // [esp+41Ch] [ebp-18h]
  int maxc2; // [esp+420h] [ebp-14h]
  unsigned __int8 *v34; // [esp+424h] [ebp-10h]
  int centerc1; // [esp+428h] [ebp-Ch]
  int minmaxdist; // [esp+42Ch] [ebp-8h]
  int i; // [esp+430h] [ebp-4h]

  v5 = minc2;
  actual_number_of_colors = cinfo->actual_number_of_colors;
  v8 = minc0;
  centerc0 = (2 * minc0 + 24) >> 1;
  centerc1 = (2 * minc1 + 28) >> 1;
  numcolors = actual_number_of_colors;
  centerc2 = (2 * minc2 + 24) >> 1;
  minmaxdist = 0x7FFFFFFF;
  i = 0;
  if ( actual_number_of_colors > 0 )
  {
    colormap = cinfo->colormap;
    v28 = *colormap;
    v10 = colormap[1];
    v11 = colormap[2];
    v32 = v10;
    v34 = v11;
    while ( 1 )
    {
      v12 = v28[i];
      if ( v12 < v8 )
        break;
      v18 = v8 + 24;
      if ( v12 > v8 + 24 )
      {
        v13 = 2 * (v12 - v18) * 2 * (v12 - v18);
        goto LABEL_5;
      }
      v13 = 0;
      if ( v12 > centerc0 )
        goto LABEL_5;
      v14 = v12 - v18;
LABEL_6:
      v15 = v32[i];
      v16 = 2 * v14 * 2 * v14;
      if ( v15 < minc1 )
      {
        v5 = minc2;
        v13 += 3 * (v15 - minc1) * 3 * (v15 - minc1);
        v17 = v15 - (minc1 + 28);
        goto LABEL_15;
      }
      if ( v15 > minc1 + 28 )
      {
        v5 = minc2;
        v13 += 3 * (v15 - (minc1 + 28)) * 3 * (v15 - (minc1 + 28));
LABEL_14:
        v17 = v15 - minc1;
        goto LABEL_15;
      }
      if ( v15 > centerc1 )
        goto LABEL_14;
      v17 = v15 - (minc1 + 28);
LABEL_15:
      v19 = 3 * v17 * 3 * v17 + v16;
      v20 = v34[i];
      if ( v20 >= v5 )
      {
        maxc2 = v5 + 24;
        if ( v20 <= v5 + 24 )
        {
          if ( v20 <= centerc2 )
          {
            v22 = v20 - (v5 + 24);
            goto LABEL_22;
          }
        }
        else
        {
          v5 = minc2;
          v13 += (v20 - maxc2) * (v20 - maxc2);
        }
        v22 = v20 - v5;
      }
      else
      {
        v21 = v20 - v5;
        v5 = minc2;
        v13 += v21 * v21;
        v22 = v20 - (minc2 + 24);
      }
LABEL_22:
      v23 = v22 * v22 + v19;
      v8 = minc0;
      mindist[i] = v13;
      v24 = minmaxdist;
      if ( v23 < minmaxdist )
      {
        v24 = v23;
        minmaxdist = v23;
      }
      ++i;
      actual_number_of_colors = numcolors;
      if ( i >= numcolors )
        goto LABEL_29;
    }
    v13 = 2 * (v12 - v8) * 2 * (v12 - v8);
    v8 += 24;
LABEL_5:
    v14 = v12 - v8;
    goto LABEL_6;
  }
  v24 = minmaxdist;
LABEL_29:
  result = 0;
  for ( j = 0; j < actual_number_of_colors; ++j )
  {
    if ( mindist[j] <= v24 )
      colorlist[result++] = j;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1027AB20
// Name: find_best_colors
// Source: json
//------------------------------------------------------------------------------
void __cdecl find_best_colors(
        jpeg_decompress_struct *cinfo,
        int minc0,
        int minc1,
        int minc2,
        int numcolors,
        unsigned __int8 *colorlist,
        unsigned __int8 *bestcolor)
{
  int v7; // eax
  int v8; // edx
  unsigned __int8 **colormap; // edi
  int v10; // ecx
  int v11; // eax
  int v12; // esi
  int v13; // edi
  int v14; // ebx
  unsigned __int8 *v15; // ecx
  int v16; // ebx
  int *v17; // eax
  int v18; // esi
  int v19; // edi
  int v20; // edi
  int v21; // edi
  int v22; // esi
  int v23; // ebx
  int v24; // edi
  int v25; // edi
  int v26; // edi
  int v27; // esi
  int v28; // ebx
  int v29; // edi
  int v30; // ebx
  int v31; // edi
  int v32; // edi
  int v33; // esi
  int v34; // edi
  int v35; // edi
  int v36; // edi
  bool v37; // zf
  bool v38; // sf
  int bestdist[128]; // [esp+4h] [ebp-228h] BYREF
  int inc1; // [esp+204h] [ebp-28h]
  int v41; // [esp+208h] [ebp-24h]
  int xx0; // [esp+20Ch] [ebp-20h]
  int i; // [esp+210h] [ebp-1Ch]
  int v44; // [esp+214h] [ebp-18h]
  int ic0; // [esp+218h] [ebp-14h]
  int dist0; // [esp+21Ch] [ebp-10h]
  int v47; // [esp+220h] [ebp-Ch]
  int xx1; // [esp+224h] [ebp-8h]
  int inc2; // [esp+228h] [ebp-4h]

  memset32(bestdist, 0x7FFFFFFF, 0x80u);
  v7 = 0;
  for ( i = 0; v7 < numcolors; i = v7 )
  {
    v8 = colorlist[v7];
    colormap = cinfo->colormap;
    v10 = 3 * (minc1 - colormap[1][v8]);
    v11 = minc2 - colormap[2][v8];
    v12 = 2 * (minc0 - (*colormap)[v8]);
    v13 = v12 * v12 + v10 * v10 + v11 * v11;
    v14 = 3 * v10 + 18;
    v15 = bestcolor;
    inc2 = 16 * (v11 + 4);
    xx0 = 32 * (v12 + 8);
    v16 = 8 * v14;
    dist0 = v13;
    inc1 = v16;
    v17 = bestdist;
    ic0 = 3;
    v47 = inc2 + 128;
    while ( 1 )
    {
      v18 = v13;
      xx1 = v16;
      v44 = 2;
      do
      {
        if ( v18 < *v17 )
        {
          *v17 = v18;
          *v15 = v8;
        }
        v19 = v18 + inc2;
        if ( v18 + inc2 < v17[1] )
        {
          v17[1] = v19;
          v15[1] = v8;
        }
        v20 = v47 + v19;
        if ( v20 < v17[2] )
        {
          v17[2] = v20;
          v15[2] = v8;
        }
        v21 = inc2 + 256 + v20;
        if ( v21 < v17[3] )
        {
          v17[3] = v21;
          v15[3] = v8;
        }
        v22 = xx1 + v18;
        if ( v22 < v17[4] )
        {
          v17[4] = v22;
          v15[4] = v8;
        }
        v23 = inc2;
        v24 = v22 + inc2;
        if ( v22 + inc2 < v17[5] )
        {
          v17[5] = v24;
          v15[5] = v8;
        }
        v25 = v23 + 128 + v24;
        if ( v25 < v17[6] )
        {
          v17[6] = v25;
          v15[6] = v8;
        }
        v26 = inc2 + 256 + v25;
        v41 = inc2 + 256;
        if ( v26 < v17[7] )
        {
          v17[7] = v26;
          v15[7] = v8;
        }
        v27 = v22 + xx1 + 288;
        if ( v27 < v17[8] )
        {
          v17[8] = v27;
          v15[8] = v8;
        }
        v28 = inc2;
        v29 = v27 + inc2;
        if ( v27 + inc2 < v17[9] )
        {
          v17[9] = v29;
          v15[9] = v8;
        }
        v30 = v28 + 128;
        v31 = v30 + v29;
        v47 = v30;
        if ( v31 < v17[10] )
        {
          v17[10] = v31;
          v15[10] = v8;
        }
        v32 = v41 + v31;
        if ( v32 < v17[11] )
        {
          v17[11] = v32;
          v15[11] = v8;
        }
        v33 = v27 + xx1 + 576;
        if ( v33 < v17[12] )
        {
          v17[12] = v33;
          v15[12] = v8;
        }
        v34 = v33 + inc2;
        if ( v33 + inc2 < v17[13] )
        {
          v17[13] = v34;
          v15[13] = v8;
        }
        v35 = v47 + v34;
        if ( v35 < v17[14] )
        {
          v17[14] = v35;
          v15[14] = v8;
        }
        v36 = v41 + v35;
        if ( v36 < v17[15] )
        {
          v17[15] = v36;
          v15[15] = v8;
        }
        v18 = v33 + xx1 + 864;
        v17 += 16;
        v15 += 16;
        v37 = v44-- == 1;
        xx1 += 1152;
      }
      while ( !v37 );
      v13 = xx0 + dist0;
      v38 = --ic0 < 0;
      dist0 += xx0;
      xx0 += 512;
      if ( v38 )
        break;
      v16 = inc1;
    }
    v7 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027AD50
// Name: fill_inverse_cmap
// Source: json
//------------------------------------------------------------------------------
void __usercall fill_inverse_cmap(int c1@<eax>, jpeg_decompress_struct *cinfo, int c0, int c2)
{
  int v4; // esi
  int nearby_colors; // eax
  unsigned __int8 *v6; // eax
  unsigned __int16 (**v7)[32]; // esi
  int v8; // edx
  int i; // edi
  unsigned __int16 *v10; // ecx
  unsigned __int16 *v11; // ecx
  int v12; // ecx
  unsigned __int16 *v13; // ecx
  _WORD *v14; // ecx
  unsigned __int16 *v15; // ecx
  _WORD *v16; // ecx
  __int16 v17; // bx
  unsigned __int8 colorlist[256]; // [esp+Ch] [ebp-188h] BYREF
  unsigned __int8 bestcolor[128]; // [esp+10Ch] [ebp-88h] BYREF
  int minc2; // [esp+18Ch] [ebp-8h]
  unsigned __int16 (**histogram)[32]; // [esp+190h] [ebp-4h]
  int c0b; // [esp+1A0h] [ebp+Ch]
  int c0a; // [esp+1A0h] [ebp+Ch]
  int c2b; // [esp+1A4h] [ebp+10h]
  int c2a; // [esp+1A4h] [ebp+10h]

  c2b = c2 >> 2;
  histogram = (unsigned __int16 (**)[32])cinfo->cquantize[1].finish_pass;
  v4 = c1 >> 3;
  c0b = c0 >> 2;
  minc2 = 32 * c2b + 4;
  nearby_colors = find_nearby_colors(cinfo, minc1: 32 * (c1 >> 3) + 2, minc0: 32 * c0b + 4, minc2, colorlist);
  find_best_colors(
    cinfo,
    minc0: 32 * c0b + 4,
    minc1: 32 * v4 + 2,
    minc2,
    numcolors: nearby_colors,
    colorlist,
    bestcolor);
  c2a = 2 * (4 * c2b + (v4 << 8));
  v6 = bestcolor;
  v7 = &histogram[4 * c0b];
  for ( c0a = 4; c0a != 0; --c0a )
  {
    v8 = c2a;
    for ( i = 2; i != 0; --i )
    {
      v10 = (unsigned __int16 *)*v7;
      *(unsigned __int16 *)((char *)v10 + v8) = *v6 + 1;
      *(unsigned __int16 *)((char *)v10 + v8 + 2) = v6[1] + 1;
      *(unsigned __int16 *)((char *)v10 + v8 + 4) = v6[2] + 1;
      *(unsigned __int16 *)((char *)v10 + v8 + 6) = v6[3] + 1;
      v11 = (unsigned __int16 *)*v7;
      *(unsigned __int16 *)((char *)v11 + v8 + 64) = v6[4] + 1;
      *(unsigned __int16 *)((char *)v11 + v8 + 66) = v6[5] + 1;
      v12 = (int)v11 + v8 + 64;
      *(_WORD *)(v12 + 4) = v6[6] + 1;
      *(_WORD *)(v12 + 6) = v6[7] + 1;
      v13 = (unsigned __int16 *)*v7;
      *(unsigned __int16 *)((char *)v13 + v8 + 128) = v6[8] + 1;
      v14 = (unsigned __int16 *)((char *)v13 + v8 + 128);
      v14[1] = v6[9] + 1;
      v14[2] = v6[10] + 1;
      v14[3] = v6[11] + 1;
      v15 = (unsigned __int16 *)*v7;
      *(unsigned __int16 *)((char *)v15 + v8 + 192) = v6[12] + 1;
      v16 = (unsigned __int16 *)((char *)v15 + v8 + 192);
      v16[1] = v6[13] + 1;
      v16[2] = v6[14] + 1;
      v17 = v6[15] + 1;
      v6 += 16;
      v8 += 256;
      v16[3] = v17;
    }
    ++v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027AF00
// Name: pass2_no_dither
// Source: json
//------------------------------------------------------------------------------
void __cdecl pass2_no_dither(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  unsigned int output_width; // esi
  unsigned __int8 **v5; // edx
  int v6; // ebx
  unsigned __int8 *v7; // edi
  int v8; // esi
  int v9; // ecx
  int v10; // edx
  unsigned __int16 *v11; // eax
  bool v12; // zf
  void (__cdecl *finish_pass)(jpeg_decompress_struct *); // edi
  int v14; // esi
  int v15; // edi
  int nearby_colors; // eax
  unsigned __int8 *v17; // eax
  int *v18; // esi
  int v19; // edx
  int i; // edi
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  int v24; // ecx
  _WORD *v25; // ecx
  int v26; // ecx
  _WORD *v27; // ecx
  __int16 v28; // bx
  char v29; // dl
  unsigned __int8 *v30; // eax
  unsigned __int8 colorlist[256]; // [esp+4h] [ebp-1B0h] BYREF
  unsigned __int8 bestcolor[128]; // [esp+104h] [ebp-B0h] BYREF
  unsigned __int8 *inptr; // [esp+184h] [ebp-30h]
  unsigned __int16 (**histogram)[32]; // [esp+188h] [ebp-2Ch]
  unsigned int width; // [esp+18Ch] [ebp-28h]
  int v36; // [esp+190h] [ebp-24h]
  int v37; // [esp+194h] [ebp-20h]
  unsigned __int16 *cachep; // [esp+198h] [ebp-1Ch]
  void (__cdecl *v39)(jpeg_decompress_struct *); // [esp+19Ch] [ebp-18h]
  unsigned __int8 *outptr; // [esp+1A0h] [ebp-14h]
  unsigned int col; // [esp+1A4h] [ebp-10h]
  int v42; // [esp+1A8h] [ebp-Ch]
  unsigned __int8 **v43; // [esp+1ACh] [ebp-8h]
  int v44; // [esp+1B0h] [ebp-4h]
  int num_rowsb; // [esp+1C8h] [ebp+14h]
  int num_rowsa; // [esp+1C8h] [ebp+14h]

  output_width = cinfo->output_width;
  histogram = (unsigned __int16 (**)[32])cinfo->cquantize[1].finish_pass;
  width = output_width;
  if ( num_rows > 0 )
  {
    v5 = output_buf;
    v6 = (char *)input_buf - (char *)output_buf;
    v43 = output_buf;
    v37 = (char *)input_buf - (char *)output_buf;
    v42 = num_rows;
    do
    {
      v7 = *(unsigned __int8 **)((char *)v5 + v6);
      outptr = *v5;
      col = output_width;
      if ( output_width != 0 )
      {
        do
        {
          v8 = v7[1] >> 2;
          v9 = *v7 >> 3;
          v10 = v7[2] >> 3;
          v11 = &histogram[v9][v8][v10];
          v7 += 3;
          v12 = *v11 == 0;
          inptr = v7;
          cachep = v11;
          if ( v12 )
          {
            finish_pass = cinfo->cquantize[1].finish_pass;
            v36 = v9 >> 2;
            v39 = finish_pass;
            v14 = v8 >> 3;
            v44 = v10 >> 2;
            v15 = 32 * (v9 >> 2) + 4;
            num_rowsb = 32 * (v10 >> 2) + 4;
            nearby_colors = find_nearby_colors(cinfo, minc1: 32 * v14 + 2, minc0: v15, minc2: num_rowsb, colorlist);
            find_best_colors(
              cinfo,
              minc0: v15,
              minc1: 32 * v14 + 2,
              minc2: num_rowsb,
              numcolors: nearby_colors,
              colorlist,
              bestcolor);
            v44 = 2 * (4 * v44 + (v14 << 8));
            v17 = bestcolor;
            v18 = (int *)((char *)v39 + 16 * v36);
            for ( num_rowsa = 4; num_rowsa != 0; --num_rowsa )
            {
              v19 = v44;
              for ( i = 2; i != 0; --i )
              {
                v21 = *v18;
                *(_WORD *)(v21 + v19) = *v17 + 1;
                *(_WORD *)(v21 + v19 + 2) = v17[1] + 1;
                *(_WORD *)(v21 + v19 + 4) = v17[2] + 1;
                *(_WORD *)(v19 + v21 + 6) = v17[3] + 1;
                v22 = *v18;
                *(_WORD *)(v19 + v22 + 64) = v17[4] + 1;
                *(_WORD *)(v19 + v22 + 66) = v17[5] + 1;
                v23 = v19 + v22 + 64;
                *(_WORD *)(v23 + 4) = v17[6] + 1;
                *(_WORD *)(v23 + 6) = v17[7] + 1;
                v24 = *v18;
                *(_WORD *)(v19 + v24 + 128) = v17[8] + 1;
                v25 = (_WORD *)(v19 + v24 + 128);
                v25[1] = v17[9] + 1;
                v25[2] = v17[10] + 1;
                v25[3] = v17[11] + 1;
                v26 = *v18;
                *(_WORD *)(v19 + v26 + 192) = v17[12] + 1;
                v27 = (_WORD *)(v19 + v26 + 192);
                v27[1] = v17[13] + 1;
                v27[2] = v17[14] + 1;
                v28 = v17[15] + 1;
                v17 += 16;
                v19 += 256;
                v27[3] = v28;
              }
              ++v18;
            }
            v7 = inptr;
            v11 = cachep;
          }
          v29 = *(_BYTE *)v11;
          v30 = outptr;
          *outptr = v29 - 1;
          v12 = col-- == 1;
          outptr = v30 + 1;
        }
        while ( !v12 );
        v5 = v43;
        v6 = v37;
        output_width = width;
      }
      ++v5;
      v12 = v42-- == 1;
      v43 = v5;
    }
    while ( !v12 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027B150
// Name: pass2_fs_dither
// Source: json
//------------------------------------------------------------------------------
void __cdecl pass2_fs_dither(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        unsigned __int8 *num_rows)
{
  unsigned int output_width; // edx
  jpeg_color_quantizer *p_pub; // esi
  unsigned __int8 **colormap; // eax
  int *finish_pass; // ecx
  int v8; // ebx
  __int16 *v9; // eax
  int v10; // esi
  int v11; // edi
  int v12; // esi
  int v13; // edi
  int v14; // ebx
  int v15; // ecx
  unsigned __int16 *v16; // edx
  bool v17; // zf
  unsigned __int16 *v18; // ecx
  int v19; // eax
  int v20; // edi
  int v21; // ebx
  int v22; // eax
  int v23; // esi
  int v24; // eax
  int v25; // eax
  unsigned __int8 *colormap2; // [esp+8h] [ebp-64h]
  unsigned __int8 *colormap1; // [esp+Ch] [ebp-60h]
  unsigned __int8 *colormap0; // [esp+10h] [ebp-5Ch]
  unsigned __int16 *cachep; // [esp+14h] [ebp-58h]
  unsigned __int16 (**histogram)[32]; // [esp+1Ch] [ebp-50h]
  int v31; // [esp+20h] [ebp-4Ch]
  unsigned __int8 *v32; // [esp+24h] [ebp-48h]
  my_cquantizer *cquantize; // [esp+28h] [ebp-44h]
  int *error_limit; // [esp+2Ch] [ebp-40h]
  unsigned int width; // [esp+30h] [ebp-3Ch]
  unsigned int col; // [esp+34h] [ebp-38h]
  int dir; // [esp+38h] [ebp-34h]
  __int16 belowerr2; // [esp+3Ch] [ebp-30h]
  __int16 belowerr1; // [esp+40h] [ebp-2Ch]
  __int16 belowerr0; // [esp+44h] [ebp-28h]
  unsigned __int8 **v41; // [esp+48h] [ebp-24h]
  __int16 bpreverr2; // [esp+4Ch] [ebp-20h]
  __int16 bpreverr1; // [esp+50h] [ebp-1Ch]
  __int16 bpreverr0; // [esp+54h] [ebp-18h]
  unsigned __int8 *range_limit; // [esp+58h] [ebp-14h]
  unsigned __int8 *outptr; // [esp+5Ch] [ebp-10h]
  int dir3; // [esp+60h] [ebp-Ch]
  int bnexterr; // [esp+64h] [ebp-8h]
  __int16 *errorptr; // [esp+68h] [ebp-4h]
  unsigned __int8 *inptr; // [esp+80h] [ebp+14h]

  output_width = cinfo->output_width;
  p_pub = cinfo->cquantize;
  histogram = (unsigned __int16 (**)[32])p_pub[1].finish_pass;
  colormap = cinfo->colormap;
  colormap0 = *colormap;
  colormap2 = colormap[2];
  range_limit = cinfo->sample_range_limit;
  finish_pass = (int *)p_pub[2].finish_pass;
  cquantize = (my_cquantizer *)p_pub;
  width = output_width;
  error_limit = finish_pass;
  colormap1 = colormap[1];
  if ( (int)num_rows > 0 )
  {
    v31 = (char *)input_buf - (char *)output_buf;
    v41 = output_buf;
    v32 = num_rows;
    v8 = 0;
    do
    {
      inptr = *(unsigned __int8 **)((char *)v41 + v31);
      outptr = *v41;
      if ( LOBYTE(p_pub[2].color_quantize) != 0 )
      {
        outptr = &(*v41)[output_width - 1];
        v9 = (__int16 *)((char *)p_pub[2].start_pass + 6 * output_width + 6);
        inptr = &(*(unsigned __int8 **)((char *)v41 + v31))[2 * output_width - 3 + output_width];
        dir = -1;
        dir3 = -3;
        errorptr = v9;
        LOBYTE(p_pub[2].color_quantize) = 0;
      }
      else
      {
        dir = 1;
        dir3 = 3;
        errorptr = (__int16 *)p_pub[2].start_pass;
        LOBYTE(p_pub[2].color_quantize) = 1;
        v9 = errorptr;
      }
      output_width = width;
      v10 = 0;
      v11 = 0;
      belowerr2 = 0;
      belowerr1 = 0;
      belowerr0 = 0;
      bpreverr2 = 0;
      bpreverr1 = 0;
      bpreverr0 = 0;
      col = width;
      if ( width != 0 )
      {
        do
        {
          v12 = range_limit[*inptr + finish_pass[(v9[dir3] + v10 + 8) >> 4]];
          v13 = range_limit[inptr[1] + finish_pass[(v9[dir3 + 1] + v11 + 8) >> 4]];
          v14 = range_limit[inptr[2] + finish_pass[(v9[dir3 + 2] + v8 + 8) >> 4]];
          v15 = (v14 >> 3) + 32 * (v13 >> 2);
          v16 = (unsigned __int16 *)histogram[v12 >> 3];
          v17 = v16[v15] == 0;
          v18 = &v16[v15];
          cachep = v18;
          if ( v17 )
          {
            fill_inverse_cmap(c1: v13 >> 2, cinfo, c0: v12 >> 3, c2: v14 >> 3);
            v18 = cachep;
          }
          v19 = *v18 - 1;
          *outptr = v19;
          v20 = v13 - colormap1[v19];
          v21 = v14 - colormap2[v19];
          bnexterr = v12 - colormap0[v19];
          *errorptr = 3 * bnexterr + bpreverr0;
          v22 = 6 * bnexterr;
          v23 = 9 * bnexterr;
          bpreverr0 = 9 * bnexterr + belowerr0;
          belowerr0 = bnexterr;
          LOWORD(bnexterr) = v20;
          v20 *= 3;
          errorptr[1] = v20 + bpreverr1;
          v10 = v22 + v23;
          v24 = 2 * v20;
          v20 *= 3;
          bpreverr1 = v20 + belowerr1;
          belowerr1 = bnexterr;
          LOWORD(bnexterr) = v21;
          v21 *= 3;
          v11 = v24 + v20;
          errorptr[2] = v21 + bpreverr2;
          v25 = 2 * v21;
          v21 *= 3;
          bpreverr2 = v21 + belowerr2;
          v8 = v25 + v21;
          inptr += dir3;
          belowerr2 = bnexterr;
          outptr += dir;
          v17 = col-- == 1;
          v9 = &errorptr[dir3];
          finish_pass = error_limit;
          errorptr = v9;
        }
        while ( !v17 );
        output_width = width;
      }
      ++v41;
      p_pub = &cquantize->pub;
      *v9 = bpreverr0;
      v9[1] = bpreverr1;
      v8 = 0;
      v17 = v32-- == (unsigned __int8 *)1;
      v9[2] = bpreverr2;
    }
    while ( !v17 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027B3D0
// Name: init_error_limit
// Source: json
//------------------------------------------------------------------------------
void __usercall init_error_limit(jpeg_common_struct *cinfo@<eax>)
{
  jpeg_color_quantizer *v1; // esi
  int v2; // eax
  int v3; // edx
  int v4; // ecx
  int v5; // edi
  _DWORD *v6; // esi
  _DWORD *v7; // esi
  _DWORD *v8; // esi

  v1 = *(jpeg_color_quantizer **)&cinfo[17].is_decompressor;
  v2 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 2044) + 1020;
  v1[2].finish_pass = (void (__cdecl *)(jpeg_decompress_struct *))v2;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = (_DWORD *)v2;
  do
  {
    *(_DWORD *)(v2 + 4 * v4) = v3;
    *v6 = v5;
    ++v4;
    --v6;
    ++v3;
    --v5;
  }
  while ( v4 < 16 );
  if ( v4 < 48 )
  {
    v7 = (_DWORD *)(v2 - 4 * v4);
    do
    {
      *(_DWORD *)(v2 + 4 * v4) = v3;
      *v7 = -v3;
      ++v4;
      --v7;
      v3 += (v4 & 1) == 0;
    }
    while ( v4 < 48 );
  }
  if ( v4 <= 255 )
  {
    v8 = (_DWORD *)(v2 - 4 * v4);
    do
    {
      *(_DWORD *)(v2 + 4 * v4) = v3;
      *v8 = -v3;
      ++v4;
      --v8;
    }
    while ( v4 <= 255 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027B470
// Name: finish_pass1
// Source: json
//------------------------------------------------------------------------------
void __cdecl finish_pass1(jpeg_common_struct *cinfo)
{
  jpeg_color_quantizer *v1; // esi

  v1 = *(jpeg_color_quantizer **)&cinfo[17].is_decompressor;
  cinfo[4].global_state = (int)v1[1].start_pass;
  select_colors(cinfo, desired_colors: (int)v1[1].color_quantize);
  LOBYTE(v1[1].new_color_map) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1027B4A0
// Name: start_pass_2_quant
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_2_quant(unsigned __int16 (**cinfo)[32], unsigned __int8 is_pre_scan)
{
  bool v3; // zf
  jpeg_color_quantizer *v4; // edi
  int v5; // ebx
  unsigned int v6; // ebx
  int i; // esi
  unsigned __int16 (**histogram)[32]; // [esp+10h] [ebp+8h]

  v3 = cinfo[19] == nullptr;
  v4 = (jpeg_color_quantizer *)cinfo[106];
  histogram = (unsigned __int16 (**)[32])v4[1].finish_pass;
  if ( !v3 )
    cinfo[19] = (unsigned __int16 (*)[32])2;
  if ( is_pre_scan != 0 )
  {
    v4->color_quantize = prescan_quantize;
    v4->finish_pass = finish_pass1;
    LOBYTE(v4[1].new_color_map) = 1;
  }
  else
  {
    if ( cinfo[19] == (unsigned __int16 (*)[32])2 )
      v4->color_quantize = pass2_fs_dither;
    else
      v4->color_quantize = pass2_no_dither;
    v4->finish_pass = (void (__cdecl *)(jpeg_decompress_struct *))C_BaseAnimating::ShutdownBoneSetupThreadPool;
    v5 = (int)cinfo[28];
    if ( v5 < 1 )
    {
      *(_DWORD *)&(**cinfo)[10] = 56;
      *(_DWORD *)&(**cinfo)[12] = 1;
      ((void (__cdecl *)(unsigned __int16 (**)[32]))(**cinfo)[0])(a1: cinfo);
    }
    if ( v5 > 256 )
    {
      *(_DWORD *)&(**cinfo)[10] = 57;
      *(_DWORD *)&(**cinfo)[12] = 256;
      ((void (__cdecl *)(unsigned __int16 (**)[32]))(**cinfo)[0])(a1: cinfo);
    }
    if ( cinfo[19] == (unsigned __int16 (*)[32])2 )
    {
      v6 = 2 * (3 * (_DWORD)cinfo[23] + 6);
      if ( v4[2].start_pass == nullptr )
        v4[2].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8))(*(int (__cdecl **)(unsigned __int16 (**)[32], int, unsigned int))&(*cinfo[1])[2])(
                                                                                          a1: cinfo,
                                                                                          a2: 1,
                                                                                          a3: v6);
      jzero_far(target: v4[2].start_pass, bytestozero: v6);
      if ( v4[2].finish_pass == nullptr )
        init_error_limit((jpeg_decompress_struct *)cinfo);
      LOBYTE(v4[2].color_quantize) = 0;
    }
  }
  if ( LOBYTE(v4[1].new_color_map) != 0 )
  {
    for ( i = 0; i < 32; ++i )
      jzero_far(target: histogram[i], bytestozero: 0x1000u);
    LOBYTE(v4[1].new_color_map) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027B5C0
// Name: new_color_map_2_quant
// Source: json
//------------------------------------------------------------------------------
void __cdecl new_color_map_2_quant(jpeg_decompress_struct *cinfo)
{
  LOBYTE(cinfo->cquantize[1].new_color_map) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1027B5E0
// Name: _jinit_2pass_quantizer
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_2pass_quantizer(jpeg_common_struct *cinfo)
{
  int v1; // edi
  int v2; // ebx
  signed int client_data; // ebx

  v1 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 44);
  *(_DWORD *)&cinfo[17].is_decompressor = v1;
  v2 = 0;
  *(_DWORD *)v1 = start_pass_2_quant;
  *(_DWORD *)(v1 + 12) = new_color_map_2_quant;
  *(_DWORD *)(v1 + 32) = 0;
  *(_DWORD *)(v1 + 40) = 0;
  if ( cinfo[4].mem != (jpeg_memory_mgr *)3 )
  {
    cinfo->err->msg_code = 47;
    cinfo->err->error_exit(a1: cinfo);
  }
  *(_DWORD *)(v1 + 24) = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 128);
  do
  {
    *(_DWORD *)(v2 + *(_DWORD *)(v1 + 24)) = cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: 4096);
    v2 += 4;
  }
  while ( v2 < 128 );
  *(_BYTE *)(v1 + 28) = 1;
  if ( *(&cinfo[3].is_decompressor + 2) != 0 )
  {
    client_data = (signed int)cinfo[3].client_data;
    if ( client_data < 8 )
    {
      cinfo->err->msg_code = 56;
      cinfo->err->msg_parm.i[0] = 8;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( client_data > 256 )
    {
      cinfo->err->msg_code = 57;
      cinfo->err->msg_parm.i[0] = 256;
      cinfo->err->error_exit(a1: cinfo);
    }
    *(_DWORD *)(v1 + 16) = cinfo->mem->alloc_sarray(a1: cinfo, a2: 1, a3: client_data, a4: 3);
    *(_DWORD *)(v1 + 20) = client_data;
  }
  else
  {
    *(_DWORD *)(v1 + 16) = 0;
  }
  if ( cinfo[3].mem != nullptr )
    cinfo[3].mem = (jpeg_memory_mgr *)2;
  if ( cinfo[3].mem == (jpeg_memory_mgr *)2 )
  {
    *(_DWORD *)(v1 + 32) = cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: 6 * (cinfo[3].global_state + 2));
    init_error_limit(cinfo);
  }
}

} // namespace client
