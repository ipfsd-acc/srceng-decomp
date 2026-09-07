// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/dist2alpha/dist2alpha.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00401440
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v3; // edx
  const char **v4; // ecx
  int v5; // esi
  const char *v6; // eax
  char v7; // al
  const char *v8; // edx
  int v9; // edx
  const char **v10; // esi
  int v11; // ebx
  int v12; // edi
  double v13; // xmm0_8
  double v14; // st7
  int v15; // xmm7_4
  int v16; // eax
  int v17; // ecx
  int v18; // esi
  float v19; // xmm5_4
  float v20; // xmm4_4
  float v21; // xmm6_4
  int m_nColumns; // ecx
  float v23; // xmm0_4
  unsigned int v24; // edx
  unsigned __int8 *v25; // edi
  float v26; // xmm0_4
  double v27; // xmm1_8
  int v28; // edi
  int v29; // ebx
  int v30; // esi
  int v31; // edx
  int v32; // edi
  int v33; // ebx
  int v34; // esi
  int v35; // ecx
  int v36; // edx
  float v37; // xmm1_4
  float v38; // xmm0_4
  double v39; // xmm0_8
  float v40; // xmm0_4
  const char *X; // [esp+0h] [ebp-6B0h]
  FloatBitMap_t lores; // [esp+14h] [ebp-69Ch] BYREF
  FloatBitMap_t hires_image; // [esp+338h] [ebp-378h] BYREF
  unsigned int v45; // [esp+65Ch] [ebp-54h]
  int out_h; // [esp+664h] [ebp-4Ch]
  unsigned int v47; // [esp+668h] [ebp-48h]
  int v48; // [esp+66Ch] [ebp-44h]
  unsigned __int8 *v49; // [esp+670h] [ebp-40h]
  int out_w; // [esp+674h] [ebp-3Ch]
  int orig_y; // [esp+678h] [ebp-38h]
  int orig_x; // [esp+67Ch] [ebp-34h]
  int irad; // [esp+680h] [ebp-30h]
  int v54; // [esp+684h] [ebp-2Ch]
  int oy; // [esp+688h] [ebp-28h]
  int v56; // [esp+68Ch] [ebp-24h]
  int x; // [esp+690h] [ebp-20h]
  int comp; // [esp+694h] [ebp-1Ch]
  int y; // [esp+698h] [ebp-18h]
  int ox; // [esp+69Ch] [ebp-14h]
  bool bCodeChannel[4]; // [esp+6A0h] [ebp-10h]
  bool v62; // [esp+6A7h] [ebp-9h]
  int inside_test; // [esp+6A8h] [ebp-8h]
  bool bWrap; // [esp+6AFh] [ebp-1h]

  InitCommandLineProgram(&argc, (char ***)&argv);
  v3 = argc;
  v4 = argv;
  v5 = 1;
  *(float *)&inside_test = 1.0;
  bWrap = false;
  for ( *(_DWORD *)bCodeChannel = 0x1000000; v5 < v3; ++v5 )
  {
    v6 = v4[v5];
    if ( *v6 != 45 )
      break;
    v7 = v6[1];
    switch ( v7 )
    {
      case '4':
        *(_WORD *)bCodeChannel = 257;
        bCodeChannel[2] = true;
        break;
      case 's':
        v8 = v4[++v5];
        *(float *)&inside_test = atof(nptr: v8);
        v4 = argv;
        v3 = argc;
        break;
      case 'w':
LABEL_6:
        bWrap = true;
        break;
      default:
        printf(format: "unrecogized option %s\n", v4[v5]);
        exit(code: 1);
        goto LABEL_6;
    }
  }
  v9 = 1 - v5 + v3;
  v10 = &v4[v5 - 1];
  argc = v9;
  argv = v10;
  if ( v9 != 5 )
  {
    printf(format: "format is dist2alpha src_bm.tga dest_bm.tga dest_width dest_height\n");
    exit(code: 1);
  }
  FloatBitMap_t::FloatBitMap_t(this: &hires_image, tgafilename: v10[1]);
  v11 = atoi(nptr: argv[3]);
  X = argv[4];
  out_w = v11;
  v12 = atoi(nptr: X);
  out_h = v12;
  FloatBitMap_t::FloatBitMap_t(this: &lores, nWidth: v11, nHeight: v12, nDepth: 1, nAttributeMask: 15);
  v13 = 1.0 / (double)v11 * (double)hires_image.m_nColumns;
  if ( v13 <= 1.0 / (double)v12 * (double)hires_image.m_nRows )
    v13 = 1.0 / (double)v12 * (double)hires_image.m_nRows;
  *(float *)&inside_test = (float)(*(float *)&inside_test * 2.0) * v13;
  v14 = ceil(X: *(float *)&inside_test);
  v15 = inside_test;
  irad = (int)v14;
  v16 = 0;
  comp = 0;
  do
  {
    v17 = 0;
    for ( y = 0; v17 < v12; y = v17 )
    {
      v18 = 0;
      x = 0;
      if ( v11 > 0 )
      {
        v19 = (float)v17;
        v20 = (float)(v11 - 1);
        v21 = (float)(v12 - 1);
        v62 = bCodeChannel[v16];
        while ( 1 )
        {
          m_nColumns = hires_image.m_nColumns;
          v23 = (float)((float)(hires_image.m_nRows - 1) * v19) / v21;
          orig_x = (int)(float)((float)((float)(hires_image.m_nColumns - 1) * (float)v18) / v20);
          orig_y = (int)v23;
          if ( v62 )
          {
            v24 = hires_image.m_nRowStrideInBytes[v16];
            v25 = hires_image.m_pAttributePtrs[v16];
            v26 = 100000.0;
            v45 = hires_image.m_nStrideInBytes[v16];
            v47 = v24;
            v27 = *(float *)&v25[orig_x * v45 + orig_y * v24];
            v49 = v25;
            inside_test = v27 > 0.9;
            v28 = irad;
            v29 = -irad;
            v30 = -irad;
            v48 = -irad;
            oy = -irad;
            if ( -irad <= irad )
            {
              v54 = irad - orig_y;
              do
              {
                v31 = v29;
                ox = v29;
                if ( v29 <= v28 )
                {
                  v56 = orig_y + v30;
                  v32 = v29 + orig_x;
                  v33 = m_nColumns - v29 - orig_x - 1;
                  do
                  {
                    if ( bWrap || v32 >= 0 && v32 < m_nColumns && v56 >= 0 && v56 < hires_image.m_nRows )
                    {
                      v34 = v32;
                      if ( v32 < m_nColumns )
                      {
                        if ( v32 < 0 )
                          v34 = v32 + m_nColumns * (v33 / m_nColumns);
                      }
                      else
                      {
                        v34 = v32 % m_nColumns;
                      }
                      v35 = v56;
                      if ( v56 < hires_image.m_nRows )
                      {
                        if ( v56 < 0 )
                          v35 = v56 + hires_image.m_nRows * ((hires_image.m_nRows + v54 - 1) / hires_image.m_nRows);
                      }
                      else
                      {
                        v35 = v56 % hires_image.m_nRows;
                      }
                      v36 = 0;
                      if ( hires_image.m_nSlices <= 0 )
                        v36 = 0 % hires_image.m_nSlices;
                      if ( inside_test != *(float *)&v49[v35 * v47
                                                       + v36 * hires_image.m_nSliceStrideInBytes[comp]
                                                       + v34 * v45] > 0.9 )
                      {
                        v37 = fsqrt((float)(oy * oy + ox * ox));
                        if ( v26 > v37 )
                          v26 = v37;
                      }
                      m_nColumns = hires_image.m_nColumns;
                      v31 = ox;
                      v16 = comp;
                    }
                    ++v31;
                    --v33;
                    ++v32;
                    ox = v31;
                  }
                  while ( v31 <= irad );
                  v30 = oy;
                  v29 = v48;
                  v28 = irad;
                }
                --v54;
                oy = ++v30;
              }
              while ( v30 <= v28 );
            }
            v38 = (float)(v26 * 0.5) / *(float *)&v15;
            v39 = v38 <= 0.5 ? v38 : 0.5;
            v40 = v39;
            if ( *(float *)&inside_test == 0.0 )
              LODWORD(v40) ^= _mask__NegFloat_;
            *(float *)&lores.m_pAttributePtrs[v16][y * lores.m_nRowStrideInBytes[v16] + x * lores.m_nStrideInBytes[v16]] = v40 + 0.5;
          }
          else
          {
            *(float *)&lores.m_pAttributePtrs[v16][y * lores.m_nRowStrideInBytes[v16]
                                                 + v18 * lores.m_nStrideInBytes[v16]] = *(float *)&hires_image.m_pAttributePtrs[v16][(int)v23 * hires_image.m_nRowStrideInBytes[v16] + (int)(float)((float)((float)(hires_image.m_nColumns - 1) * (float)v18) / v20) * hires_image.m_nStrideInBytes[v16]];
          }
          if ( ++x >= out_w )
            break;
          v18 = x;
        }
        v17 = y;
        v11 = out_w;
        v12 = out_h;
      }
      ++v17;
    }
    comp = ++v16;
  }
  while ( v16 < 4 );
  FloatBitMap_t::WriteTGAFile(this: &lores, filename: argv[2]);
  CSOAContainer::~CSOAContainer(this: &lores);
  CSOAContainer::~CSOAContainer(this: &hires_image);
  return 0;
}
