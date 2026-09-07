// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/height2ssbump/height2ssbump.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: PrintArgSummaryAndExit
// Source: json
//------------------------------------------------------------------------------
void __noreturn PrintArgSummaryAndExit()
{
  printf(format: "format is 'height2ssbump filename.tga bumpscale'\n");
  printf(format: "options:\n-r NUM\tSet the number of rays (default = 250. more rays take more time).\n");
  printf(format: "-n\tGenerate a conventional normal map\n");
  printf(format: "-d\tgenerate an ssbump detail texture\n");
  printf(format: "-A\tGenerate ambient occlusion in the alpha channel\n");
  printf(format: "-f NUM\tSet smoothing filter radius (0=no filter, default = 10)\n");
  printf(format: "-D\tWrite out the filtered result as filterd.tga\n");
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00401060
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v3; // edx
  const char **v4; // ecx
  int v5; // esi
  unsigned int v6; // ebx
  int v7; // edi
  const char *v8; // eax
  const char *v9; // eax
  int v10; // eax
  const char *v11; // ecx
  FloatBitMap_t *v12; // eax
  const char *v13; // ecx
  FloatBitMap_t *v14; // esi
  char *v15; // edx
  char v16; // al
  char *v17; // eax
  float bump_scale; // [esp+0h] [ebp-744h]
  float edge_threshold_value; // [esp+8h] [ebp-73Ch]
  char oname[1024]; // [esp+18h] [ebp-72Ch] BYREF
  FloatBitMap_t src_texture; // [esp+418h] [ebp-32Ch] BYREF
  float flFilterRadius; // [esp+73Ch] [ebp-8h]
  bool bWriteFiltered; // [esp+742h] [ebp-2h]
  bool bNormalOnly; // [esp+743h] [ebp-1h]

  InitCommandLineProgram(&argc, (char ***)&argv);
  v3 = argc;
  v4 = argv;
  v5 = 1;
  v6 = 0;
  bNormalOnly = false;
  flFilterRadius = 10.0;
  bWriteFiltered = false;
  v7 = 250;
  if ( argc > 1 )
  {
    while ( 2 )
    {
      v8 = v4[v5];
      if ( *v8 == 45 )
      {
        switch ( v8[1] )
        {
          case '?':
            goto $LN11;
          case 'A':
            v6 |= 1u;
            goto LABEL_10;
          case 'D':
            bWriteFiltered = true;
            goto LABEL_10;
          case 'd':
            v6 |= 2u;
            goto LABEL_10;
          case 'f':
            v11 = v4[++v5];
            flFilterRadius = atof(nptr: v11);
            v4 = argv;
            goto LABEL_10;
          case 'n':
            bNormalOnly = true;
            goto LABEL_10;
          case 'r':
            v9 = v4[++v5];
            v10 = atoi(nptr: v9);
            v4 = argv;
            v7 = v10;
LABEL_10:
            v3 = argc;
            if ( ++v5 >= argc )
              break;
            continue;
          default:
            printf(format: "unrecogized option %s\n", v4[v5]);
$LN11:
            PrintArgSummaryAndExit();
        }
      }
      break;
    }
  }
  argc = 1 - v5 + v3;
  argv = &v4[v5 - 1];
  if ( argc != 3 )
    PrintArgSummaryAndExit();
  _ReportProgress(a1: "reading src texture", a2: 0, a3: 0);
  FloatBitMap_t::FloatBitMap_t(this: &src_texture, tgafilename: argv[1]);
  if ( V_stristr(pStr: (char *)argv[1], pSearch: ".pfm") != nullptr )
    CSOAContainer::CopyAttrToAttr(this: &src_texture, nSrcAttributeIndex: 0, nDestAttributeIndex: 3);
  if ( flFilterRadius > 0.0 )
    FloatBitMap_t::TileableBilateralFilter(
      this: &src_texture,
      radius_in_pixels: (int)flFilterRadius,
      edge_threshold_value: 0.0078431377);
  if ( bWriteFiltered )
    FloatBitMap_t::WriteTGAFile(this: &src_texture, filename: "filtered.tga");
  if ( bNormalOnly )
  {
    edge_threshold_value = atof(nptr: argv[2]);
    v12 = FloatBitMap_t::ComputeBumpmapFromHeightInAlphaChannel(this: &src_texture, flBumpScale: edge_threshold_value);
  }
  else
  {
    bump_scale = atof(nptr: argv[2]);
    v12 = FloatBitMap_t::ComputeSelfShadowedBumpmapFromHeightInAlphaChannel(
            this: &src_texture,
            bump_scale,
            nrays_to_trace_per_pixel: v7,
            nOptionFlags: v6);
  }
  v13 = argv[1];
  v14 = v12;
  v15 = oname;
  do
  {
    v16 = *v13;
    *v15++ = *v13++;
  }
  while ( v16 != 0 );
  strchr(string: (unsigned __int8 *)oname, chr: 0x2Eu);
  if ( v17 == nullptr )
    v17 = &oname[strlen(oname)];
  if ( bNormalOnly )
    strcpy(v17, "-bump.tga");
  else
    strcpy(v17, "-ssbump.tga");
  FloatBitMap_t::WriteTGAFile(this: v14, filename: oname);
  if ( v14 != nullptr )
  {
    CSOAContainer::~CSOAContainer(this: v14);
    operator delete(p: v14);
  }
  CSOAContainer::~CSOAContainer(this: &src_texture);
  return 0;
}
