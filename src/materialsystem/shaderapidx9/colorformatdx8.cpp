// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapidx9/colorformatdx8.cpp
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10001040
// Name: enum _D3DFORMAT GetNearestD3DColorFormat(enum ImageFormat,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetNearestD3DColorFormat(
        ImageFormat fmt,
        bool isRenderTarget,
        bool bIsVertexTexture,
        bool bIsFilterableRequired)
{
  unsigned int v4; // eax
  IDirect3D9 *m_pD3D; // esi
  IDirect3D9_vtbl *v6; // ebx
  _D3DFORMAT v7; // eax
  int v8; // eax
  IDirect3D9 *v9; // esi
  IDirect3D9_vtbl *v10; // edi
  _D3DFORMAT v11; // eax
  unsigned int v13; // eax
  IDirect3D9 *v14; // esi
  IDirect3D9_vtbl *v15; // edi
  _D3DFORMAT v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // edi
  IDirect3D9 *v19; // esi
  IDirect3D9_vtbl *v20; // ebx
  _D3DFORMAT v21; // eax
  int v22; // eax
  IDirect3D9 *v23; // esi
  IDirect3D9_vtbl *v24; // ebx
  _D3DFORMAT v25; // eax
  int v26; // eax
  IDirect3D9 *v27; // esi
  IDirect3D9_vtbl *v28; // ebx
  _D3DFORMAT v29; // eax
  int v30; // eax
  IDirect3D9 *v31; // esi
  IDirect3D9_vtbl *v32; // ebx
  _D3DFORMAT v33; // eax
  int v34; // eax
  IDirect3D9 *v35; // esi
  IDirect3D9_vtbl *v36; // ebx
  _D3DFORMAT v37; // eax
  int v38; // eax
  IDirect3D9 *v39; // esi
  IDirect3D9_vtbl *v40; // edi
  _D3DFORMAT v41; // eax
  unsigned int v42; // eax
  unsigned int v43; // edi
  IDirect3D9 *v44; // esi
  IDirect3D9_vtbl *v45; // ebx
  _D3DFORMAT v46; // eax
  int v47; // eax
  IDirect3D9 *v48; // esi
  IDirect3D9_vtbl *v49; // ebx
  _D3DFORMAT v50; // eax
  int v51; // eax
  IDirect3D9 *v52; // esi
  IDirect3D9_vtbl *v53; // ebx
  _D3DFORMAT v54; // eax
  int v55; // eax
  IDirect3D9 *v56; // esi
  IDirect3D9_vtbl *v57; // ebx
  _D3DFORMAT v58; // eax
  int v59; // eax
  IDirect3D9 *v60; // esi
  IDirect3D9_vtbl *v61; // ebx
  _D3DFORMAT v62; // eax
  int v63; // eax
  IDirect3D9 *v64; // esi
  IDirect3D9_vtbl *v65; // edi
  _D3DFORMAT v66; // eax
  unsigned int v67; // eax
  unsigned int v68; // edi
  IDirect3D9 *v69; // esi
  IDirect3D9_vtbl *v70; // ebx
  _D3DFORMAT v71; // eax
  int v72; // eax
  IDirect3D9 *v73; // esi
  IDirect3D9_vtbl *v74; // ebx
  _D3DFORMAT v75; // eax
  int v76; // eax
  IDirect3D9 *v77; // esi
  IDirect3D9_vtbl *v78; // ebx
  _D3DFORMAT v79; // eax
  int v80; // eax
  IDirect3D9 *v81; // esi
  IDirect3D9_vtbl *v82; // ebx
  _D3DFORMAT v83; // eax
  int v84; // eax
  IDirect3D9 *v85; // esi
  IDirect3D9_vtbl *v86; // ebx
  _D3DFORMAT v87; // eax
  int v88; // eax
  IDirect3D9 *v89; // esi
  IDirect3D9_vtbl *v90; // edi
  _D3DFORMAT v91; // eax
  unsigned int v92; // eax
  unsigned int v93; // edi
  IDirect3D9 *v94; // esi
  IDirect3D9_vtbl *v95; // ebx
  _D3DFORMAT v96; // eax
  int v97; // eax
  IDirect3D9 *v98; // esi
  IDirect3D9_vtbl *v99; // ebx
  _D3DFORMAT v100; // eax
  int v101; // eax
  IDirect3D9 *v102; // esi
  IDirect3D9_vtbl *v103; // edi
  _D3DFORMAT v104; // eax
  unsigned int v105; // eax
  IDirect3D9 *v106; // esi
  IDirect3D9_vtbl *v107; // ebx
  _D3DFORMAT v108; // eax
  int v109; // eax
  IDirect3D9 *v110; // esi
  IDirect3D9_vtbl *v111; // edi
  _D3DFORMAT v112; // eax
  unsigned int v113; // eax
  IDirect3D9 *v114; // esi
  IDirect3D9_vtbl *v115; // ebx
  _D3DFORMAT v116; // eax
  int v117; // eax
  IDirect3D9 *v118; // esi
  IDirect3D9_vtbl *v119; // edi
  _D3DFORMAT v120; // eax
  unsigned int v121; // eax
  IDirect3D9 *v122; // esi
  IDirect3D9_vtbl *v123; // ebx
  _D3DFORMAT v124; // eax
  int v125; // eax
  IDirect3D9 *v126; // esi
  IDirect3D9_vtbl *v127; // edi
  _D3DFORMAT v128; // eax
  unsigned int v129; // eax
  IDirect3D9 *v130; // esi
  IDirect3D9_vtbl *v131; // ebx
  _D3DFORMAT v132; // eax
  int v133; // eax
  IDirect3D9 *v134; // esi
  IDirect3D9_vtbl *v135; // edi
  _D3DFORMAT v136; // eax
  unsigned int v137; // eax
  IDirect3D9 *v138; // esi
  IDirect3D9_vtbl *v139; // edi
  _D3DFORMAT v140; // eax
  unsigned int v141; // eax
  IDirect3D9 *v142; // esi
  IDirect3D9_vtbl *v143; // edi
  _D3DFORMAT v144; // eax
  unsigned int v145; // eax
  IDirect3D9 *v146; // esi
  IDirect3D9_vtbl *v147; // edi
  _D3DFORMAT v148; // eax
  unsigned int v149; // eax
  IDirect3D9 *v150; // esi
  IDirect3D9_vtbl *v151; // edi
  _D3DFORMAT v152; // eax
  unsigned int v153; // eax
  IDirect3D9 *v154; // esi
  IDirect3D9_vtbl *v155; // edi
  _D3DFORMAT v156; // eax
  unsigned int v157; // eax
  IDirect3D9 *v158; // esi
  IDirect3D9_vtbl *v159; // edi
  _D3DFORMAT v160; // eax
  unsigned int v161; // eax
  IDirect3D9 *v162; // esi
  IDirect3D9_vtbl *v163; // ebx
  _D3DFORMAT v164; // eax
  int v165; // eax
  IDirect3D9 *v166; // esi
  IDirect3D9_vtbl *v167; // edi
  _D3DFORMAT v168; // eax
  unsigned int v169; // eax
  IDirect3D9 *v170; // esi
  IDirect3D9_vtbl *v171; // ebx
  _D3DFORMAT v172; // eax
  int v173; // eax
  IDirect3D9 *v174; // esi
  IDirect3D9_vtbl *v175; // edi
  _D3DFORMAT v176; // eax
  unsigned int v177; // eax
  IDirect3D9 *v178; // esi
  IDirect3D9_vtbl *v179; // edi
  _D3DFORMAT v180; // eax
  unsigned int v181; // eax
  IDirect3D9 *v182; // esi
  IDirect3D9_vtbl *v183; // edi
  _D3DFORMAT v184; // eax
  unsigned int v185; // eax
  IDirect3D9 *v186; // edi
  IDirect3D9_vtbl *v187; // esi
  _D3DFORMAT v188; // eax
  int v189; // eax
  _D3DFORMAT v190; // eax
  int v191; // eax
  IDirect3D9 *v192; // edi
  IDirect3D9_vtbl *v193; // esi
  _D3DFORMAT v194; // eax
  unsigned int v195; // eax
  IDirect3D9 *v196; // edi
  IDirect3D9_vtbl *v197; // esi
  _D3DFORMAT v198; // eax
  int v199; // eax
  _D3DFORMAT v200; // eax
  int v201; // eax
  IDirect3D9 *v202; // edi
  IDirect3D9_vtbl *v203; // esi
  _D3DFORMAT v204; // eax
  unsigned int v205; // eax
  IDirect3D9 *v206; // esi
  IDirect3D9_vtbl *v207; // edi
  _D3DFORMAT v208; // eax
  unsigned int v209; // eax
  IDirect3D9 *v210; // esi
  IDirect3D9_vtbl *v211; // edi
  _D3DFORMAT v212; // eax
  unsigned int v213; // eax
  IDirect3D9 *v214; // esi
  IDirect3D9_vtbl *v215; // edi
  _D3DFORMAT v216; // eax
  unsigned int v217; // [esp-Ch] [ebp-18h]
  int v218; // [esp-Ch] [ebp-18h]
  unsigned int v219; // [esp-Ch] [ebp-18h]
  unsigned int v220; // [esp-Ch] [ebp-18h]
  int v221; // [esp-Ch] [ebp-18h]
  int v222; // [esp-Ch] [ebp-18h]
  int v223; // [esp-Ch] [ebp-18h]
  int v224; // [esp-Ch] [ebp-18h]
  int v225; // [esp-Ch] [ebp-18h]
  unsigned int v226; // [esp-Ch] [ebp-18h]
  int v227; // [esp-Ch] [ebp-18h]
  int v228; // [esp-Ch] [ebp-18h]
  int v229; // [esp-Ch] [ebp-18h]
  int v230; // [esp-Ch] [ebp-18h]
  int v231; // [esp-Ch] [ebp-18h]
  unsigned int v232; // [esp-Ch] [ebp-18h]
  int v233; // [esp-Ch] [ebp-18h]
  int v234; // [esp-Ch] [ebp-18h]
  int v235; // [esp-Ch] [ebp-18h]
  int v236; // [esp-Ch] [ebp-18h]
  int v237; // [esp-Ch] [ebp-18h]
  unsigned int v238; // [esp-Ch] [ebp-18h]
  int v239; // [esp-Ch] [ebp-18h]
  int v240; // [esp-Ch] [ebp-18h]
  unsigned int v241; // [esp-Ch] [ebp-18h]
  int v242; // [esp-Ch] [ebp-18h]
  unsigned int v243; // [esp-Ch] [ebp-18h]
  int v244; // [esp-Ch] [ebp-18h]
  unsigned int v245; // [esp-Ch] [ebp-18h]
  int v246; // [esp-Ch] [ebp-18h]
  unsigned int v247; // [esp-Ch] [ebp-18h]
  int v248; // [esp-Ch] [ebp-18h]
  unsigned int v249; // [esp-Ch] [ebp-18h]
  unsigned int v250; // [esp-Ch] [ebp-18h]
  unsigned int v251; // [esp-Ch] [ebp-18h]
  unsigned int v252; // [esp-Ch] [ebp-18h]
  unsigned int v253; // [esp-Ch] [ebp-18h]
  unsigned int v254; // [esp-Ch] [ebp-18h]
  unsigned int v255; // [esp-Ch] [ebp-18h]
  int v256; // [esp-Ch] [ebp-18h]
  unsigned int v257; // [esp-Ch] [ebp-18h]
  int v258; // [esp-Ch] [ebp-18h]
  unsigned int v259; // [esp-Ch] [ebp-18h]
  unsigned int v260; // [esp-Ch] [ebp-18h]
  unsigned int v261; // [esp-Ch] [ebp-18h]
  int v262; // [esp-Ch] [ebp-18h]
  unsigned int v263; // [esp-Ch] [ebp-18h]
  int v264; // [esp-Ch] [ebp-18h]
  unsigned int v265; // [esp-Ch] [ebp-18h]
  unsigned int v266; // [esp-Ch] [ebp-18h]
  unsigned int v267; // [esp-Ch] [ebp-18h]

  switch ( fmt )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_ABGR8888:
    case IMAGE_FORMAT_ARGB8888:
    case IMAGE_FORMAT_BGRA8888:
      v4 = isRenderTarget;
      if ( bIsVertexTexture )
        v4 |= 0x100000u;
      if ( bIsFilterableRequired )
        v4 |= 0x20000u;
      m_pD3D = g_pShaderDeviceMgrDx8->m_pD3D;
      v6 = m_pD3D->__vftable;
      v217 = v4;
      v7 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v6->CheckDeviceFormat(
             this: m_pD3D,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v7,
             a5: v217,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A8R8G8B8) >= 0 )
        return 21;
      v8 = isRenderTarget;
      if ( bIsVertexTexture )
        v8 = isRenderTarget | 0x100000;
      if ( bIsFilterableRequired )
        v8 |= 0x20000u;
      v9 = g_pShaderDeviceMgrDx8->m_pD3D;
      v10 = v9->__vftable;
      v218 = v8;
      v11 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v10->CheckDeviceFormat(
             this: v9,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v11,
             a5: v218,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A4R4G4B4) < 0 )
        return 0;
      return 26;
    case IMAGE_FORMAT_RGB888:
    case IMAGE_FORMAT_BGR888:
      goto $LN78;
    case IMAGE_FORMAT_RGB565:
    case IMAGE_FORMAT_BGR565:
      v42 = isRenderTarget;
      v43 = v42;
      if ( bIsVertexTexture )
        v42 |= 0x100000u;
      if ( bIsFilterableRequired )
        v42 |= 0x20000u;
      v44 = g_pShaderDeviceMgrDx8->m_pD3D;
      v45 = v44->__vftable;
      v226 = v42;
      v46 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v45->CheckDeviceFormat(
             this: v44,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v46,
             a5: v226,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_R5G6B5) >= 0 )
        return 23;
      v47 = isRenderTarget;
      if ( bIsVertexTexture )
        v47 = v43 | 0x100000;
      if ( bIsFilterableRequired )
        v47 |= 0x20000u;
      v48 = g_pShaderDeviceMgrDx8->m_pD3D;
      v49 = v48->__vftable;
      v227 = v47;
      v50 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v49->CheckDeviceFormat(
             this: v48,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v50,
             a5: v227,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_X1R5G5B5) >= 0 )
        return 24;
      v51 = isRenderTarget;
      if ( bIsVertexTexture )
        v51 = v43 | 0x100000;
      if ( bIsFilterableRequired )
        v51 |= 0x20000u;
      v52 = g_pShaderDeviceMgrDx8->m_pD3D;
      v53 = v52->__vftable;
      v228 = v51;
      v54 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v53->CheckDeviceFormat(
             this: v52,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v54,
             a5: v228,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A1R5G5B5) >= 0 )
        return 25;
      v55 = isRenderTarget;
      if ( bIsVertexTexture )
        v55 = v43 | 0x100000;
      if ( bIsFilterableRequired )
        v55 |= 0x20000u;
      v56 = g_pShaderDeviceMgrDx8->m_pD3D;
      v57 = v56->__vftable;
      v229 = v55;
      v58 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v57->CheckDeviceFormat(
             this: v56,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v58,
             a5: v229,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_R8G8B8) >= 0 )
        return 20;
      v59 = isRenderTarget;
      if ( bIsVertexTexture )
        v59 = v43 | 0x100000;
      if ( bIsFilterableRequired )
        v59 |= 0x20000u;
      v60 = g_pShaderDeviceMgrDx8->m_pD3D;
      v61 = v60->__vftable;
      v230 = v59;
      v62 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v61->CheckDeviceFormat(
             this: v60,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v62,
             a5: v230,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_X8R8G8B8) >= 0 )
        return 22;
      v63 = isRenderTarget;
      if ( bIsVertexTexture )
        v63 = v43 | 0x100000;
      if ( bIsFilterableRequired )
        v63 |= 0x20000u;
      v64 = g_pShaderDeviceMgrDx8->m_pD3D;
      v65 = v64->__vftable;
      v231 = v63;
      v66 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v65->CheckDeviceFormat(
             this: v64,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v66,
             a5: v231,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A8R8G8B8) < 0 )
        return 0;
      return 21;
    case IMAGE_FORMAT_I8:
      v113 = isRenderTarget;
      if ( bIsVertexTexture )
        v113 |= 0x100000u;
      if ( bIsFilterableRequired )
        v113 |= 0x20000u;
      v114 = g_pShaderDeviceMgrDx8->m_pD3D;
      v115 = v114->__vftable;
      v243 = v113;
      v116 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v115->CheckDeviceFormat(
             this: v114,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v116,
             a5: v243,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_L8) >= 0 )
        return 50;
      v117 = isRenderTarget;
      if ( bIsVertexTexture )
        v117 = isRenderTarget | 0x100000;
      if ( bIsFilterableRequired )
        v117 |= 0x20000u;
      v118 = g_pShaderDeviceMgrDx8->m_pD3D;
      v119 = v118->__vftable;
      v244 = v117;
      v120 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v119->CheckDeviceFormat(
             this: v118,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v120,
             a5: v244,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A8R8G8B8) < 0 )
        return 0;
      return 21;
    case IMAGE_FORMAT_IA88:
      v121 = isRenderTarget;
      if ( bIsVertexTexture )
        v121 |= 0x100000u;
      if ( bIsFilterableRequired )
        v121 |= 0x20000u;
      v122 = g_pShaderDeviceMgrDx8->m_pD3D;
      v123 = v122->__vftable;
      v245 = v121;
      v124 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v123->CheckDeviceFormat(
             this: v122,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v124,
             a5: v245,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A8L8) >= 0 )
        return 51;
      v125 = isRenderTarget;
      if ( bIsVertexTexture )
        v125 = isRenderTarget | 0x100000;
      if ( bIsFilterableRequired )
        v125 |= 0x20000u;
      v126 = g_pShaderDeviceMgrDx8->m_pD3D;
      v127 = v126->__vftable;
      v246 = v125;
      v128 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v127->CheckDeviceFormat(
             this: v126,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v128,
             a5: v246,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A8R8G8B8) < 0 )
        return 0;
      return 21;
    case IMAGE_FORMAT_A8:
      v129 = isRenderTarget;
      if ( bIsVertexTexture )
        v129 |= 0x100000u;
      if ( bIsFilterableRequired )
        v129 |= 0x20000u;
      v130 = g_pShaderDeviceMgrDx8->m_pD3D;
      v131 = v130->__vftable;
      v247 = v129;
      v132 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v131->CheckDeviceFormat(
             this: v130,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v132,
             a5: v247,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A8) >= 0 )
        return 28;
      v133 = isRenderTarget;
      if ( bIsVertexTexture )
        v133 = isRenderTarget | 0x100000;
      if ( bIsFilterableRequired )
        v133 |= 0x20000u;
      v134 = g_pShaderDeviceMgrDx8->m_pD3D;
      v135 = v134->__vftable;
      v248 = v133;
      v136 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v135->CheckDeviceFormat(
             this: v134,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v136,
             a5: v248,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A8R8G8B8) < 0 )
        return 0;
      return 21;
    case IMAGE_FORMAT_DXT1:
    case IMAGE_FORMAT_DXT1_ONEBITALPHA:
      v137 = isRenderTarget;
      if ( bIsVertexTexture )
        v137 |= 0x100000u;
      if ( bIsFilterableRequired )
        v137 |= 0x20000u;
      v138 = g_pShaderDeviceMgrDx8->m_pD3D;
      v139 = v138->__vftable;
      v249 = v137;
      v140 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v139->CheckDeviceFormat(
             this: v138,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v140,
             a5: v249,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_DXT1) < 0 )
        return 0;
      return 827611204;
    case IMAGE_FORMAT_DXT3:
      v141 = isRenderTarget;
      if ( bIsVertexTexture )
        v141 |= 0x100000u;
      if ( bIsFilterableRequired )
        v141 |= 0x20000u;
      v142 = g_pShaderDeviceMgrDx8->m_pD3D;
      v143 = v142->__vftable;
      v250 = v141;
      v144 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v143->CheckDeviceFormat(
             this: v142,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v144,
             a5: v250,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_DXT3) < 0 )
        return 0;
      return 861165636;
    case IMAGE_FORMAT_DXT5:
      v145 = isRenderTarget;
      if ( bIsVertexTexture )
        v145 |= 0x100000u;
      if ( bIsFilterableRequired )
        v145 |= 0x20000u;
      v146 = g_pShaderDeviceMgrDx8->m_pD3D;
      v147 = v146->__vftable;
      v251 = v145;
      v148 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v147->CheckDeviceFormat(
             this: v146,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v148,
             a5: v251,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_DXT5) < 0 )
        return 0;
      return 894720068;
    case IMAGE_FORMAT_BGRX8888:
      v13 = isRenderTarget;
      if ( bIsVertexTexture )
        v13 |= 0x100000u;
      if ( bIsFilterableRequired )
        v13 |= 0x20000u;
      v14 = g_pShaderDeviceMgrDx8->m_pD3D;
      v15 = v14->__vftable;
      v219 = v13;
      v16 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v15->CheckDeviceFormat(
             this: v14,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v16,
             a5: v219,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_X8R8G8B8) >= 0 )
        return 22;
$LN78:
      v17 = isRenderTarget;
      v18 = v17;
      if ( bIsVertexTexture )
        v17 |= 0x100000u;
      if ( bIsFilterableRequired )
        v17 |= 0x20000u;
      v19 = g_pShaderDeviceMgrDx8->m_pD3D;
      v20 = v19->__vftable;
      v220 = v17;
      v21 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v20->CheckDeviceFormat(
             this: v19,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v21,
             a5: v220,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_R8G8B8) >= 0 )
        return 20;
      v22 = isRenderTarget;
      if ( bIsVertexTexture )
        v22 = v18 | 0x100000;
      if ( bIsFilterableRequired )
        v22 |= 0x20000u;
      v23 = g_pShaderDeviceMgrDx8->m_pD3D;
      v24 = v23->__vftable;
      v221 = v22;
      v25 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v24->CheckDeviceFormat(
             this: v23,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v25,
             a5: v221,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_X8R8G8B8) >= 0 )
        return 22;
      v26 = isRenderTarget;
      if ( bIsVertexTexture )
        v26 = v18 | 0x100000;
      if ( bIsFilterableRequired )
        v26 |= 0x20000u;
      v27 = g_pShaderDeviceMgrDx8->m_pD3D;
      v28 = v27->__vftable;
      v222 = v26;
      v29 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v28->CheckDeviceFormat(
             this: v27,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v29,
             a5: v222,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A8R8G8B8) >= 0 )
        return 21;
      v30 = isRenderTarget;
      if ( bIsVertexTexture )
        v30 = v18 | 0x100000;
      if ( bIsFilterableRequired )
        v30 |= 0x20000u;
      v31 = g_pShaderDeviceMgrDx8->m_pD3D;
      v32 = v31->__vftable;
      v223 = v30;
      v33 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v32->CheckDeviceFormat(
             this: v31,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v33,
             a5: v223,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_R5G6B5) >= 0 )
        return 23;
      v34 = isRenderTarget;
      if ( bIsVertexTexture )
        v34 = v18 | 0x100000;
      if ( bIsFilterableRequired )
        v34 |= 0x20000u;
      v35 = g_pShaderDeviceMgrDx8->m_pD3D;
      v36 = v35->__vftable;
      v224 = v34;
      v37 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v36->CheckDeviceFormat(
             this: v35,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v37,
             a5: v224,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_X1R5G5B5) >= 0 )
        return 24;
      v38 = isRenderTarget;
      if ( bIsVertexTexture )
        v38 = v18 | 0x100000;
      if ( bIsFilterableRequired )
        v38 |= 0x20000u;
      v39 = g_pShaderDeviceMgrDx8->m_pD3D;
      v40 = v39->__vftable;
      v225 = v38;
      v41 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v40->CheckDeviceFormat(
             this: v39,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v41,
             a5: v225,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A1R5G5B5) < 0 )
        return 0;
      return 25;
    case IMAGE_FORMAT_BGRX5551:
      v67 = isRenderTarget;
      v68 = v67;
      if ( bIsVertexTexture )
        v67 |= 0x100000u;
      if ( bIsFilterableRequired )
        v67 |= 0x20000u;
      v69 = g_pShaderDeviceMgrDx8->m_pD3D;
      v70 = v69->__vftable;
      v232 = v67;
      v71 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v70->CheckDeviceFormat(
             this: v69,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v71,
             a5: v232,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_X1R5G5B5) >= 0 )
        return 24;
      v72 = isRenderTarget;
      if ( bIsVertexTexture )
        v72 = v68 | 0x100000;
      if ( bIsFilterableRequired )
        v72 |= 0x20000u;
      v73 = g_pShaderDeviceMgrDx8->m_pD3D;
      v74 = v73->__vftable;
      v233 = v72;
      v75 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v74->CheckDeviceFormat(
             this: v73,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v75,
             a5: v233,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A1R5G5B5) >= 0 )
        return 25;
      v76 = isRenderTarget;
      if ( bIsVertexTexture )
        v76 = v68 | 0x100000;
      if ( bIsFilterableRequired )
        v76 |= 0x20000u;
      v77 = g_pShaderDeviceMgrDx8->m_pD3D;
      v78 = v77->__vftable;
      v234 = v76;
      v79 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v78->CheckDeviceFormat(
             this: v77,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v79,
             a5: v234,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_R5G6B5) >= 0 )
        return 23;
      v80 = isRenderTarget;
      if ( bIsVertexTexture )
        v80 = v68 | 0x100000;
      if ( bIsFilterableRequired )
        v80 |= 0x20000u;
      v81 = g_pShaderDeviceMgrDx8->m_pD3D;
      v82 = v81->__vftable;
      v235 = v80;
      v83 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v82->CheckDeviceFormat(
             this: v81,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v83,
             a5: v235,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_R8G8B8) >= 0 )
        return 20;
      v84 = isRenderTarget;
      if ( bIsVertexTexture )
        v84 = v68 | 0x100000;
      if ( bIsFilterableRequired )
        v84 |= 0x20000u;
      v85 = g_pShaderDeviceMgrDx8->m_pD3D;
      v86 = v85->__vftable;
      v236 = v84;
      v87 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v86->CheckDeviceFormat(
             this: v85,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v87,
             a5: v236,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_X8R8G8B8) >= 0 )
        return 22;
      v88 = isRenderTarget;
      if ( bIsVertexTexture )
        v88 = v68 | 0x100000;
      if ( bIsFilterableRequired )
        v88 |= 0x20000u;
      v89 = g_pShaderDeviceMgrDx8->m_pD3D;
      v90 = v89->__vftable;
      v237 = v88;
      v91 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v90->CheckDeviceFormat(
             this: v89,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v91,
             a5: v237,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A8R8G8B8) < 0 )
        return 0;
      return 21;
    case IMAGE_FORMAT_BGRA4444:
      v105 = isRenderTarget;
      if ( bIsVertexTexture )
        v105 |= 0x100000u;
      if ( bIsFilterableRequired )
        v105 |= 0x20000u;
      v106 = g_pShaderDeviceMgrDx8->m_pD3D;
      v107 = v106->__vftable;
      v241 = v105;
      v108 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v107->CheckDeviceFormat(
             this: v106,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v108,
             a5: v241,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A4R4G4B4) >= 0 )
        return 26;
      v109 = isRenderTarget;
      if ( bIsVertexTexture )
        v109 = isRenderTarget | 0x100000;
      if ( bIsFilterableRequired )
        v109 |= 0x20000u;
      v110 = g_pShaderDeviceMgrDx8->m_pD3D;
      v111 = v110->__vftable;
      v242 = v109;
      v112 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v111->CheckDeviceFormat(
             this: v110,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v112,
             a5: v242,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A8R8G8B8) < 0 )
        return 0;
      return 21;
    case IMAGE_FORMAT_BGRA5551:
      v92 = isRenderTarget;
      v93 = v92;
      if ( bIsVertexTexture )
        v92 |= 0x100000u;
      if ( bIsFilterableRequired )
        v92 |= 0x20000u;
      v94 = g_pShaderDeviceMgrDx8->m_pD3D;
      v95 = v94->__vftable;
      v238 = v92;
      v96 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v95->CheckDeviceFormat(
             this: v94,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v96,
             a5: v238,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A1R5G5B5) >= 0 )
        return 25;
      v97 = isRenderTarget;
      if ( bIsVertexTexture )
        v97 = v93 | 0x100000;
      if ( bIsFilterableRequired )
        v97 |= 0x20000u;
      v98 = g_pShaderDeviceMgrDx8->m_pD3D;
      v99 = v98->__vftable;
      v239 = v97;
      v100 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v99->CheckDeviceFormat(
             this: v98,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v100,
             a5: v239,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A4R4G4B4) >= 0 )
        return 26;
      v101 = isRenderTarget;
      if ( bIsVertexTexture )
        v101 = v93 | 0x100000;
      if ( bIsFilterableRequired )
        v101 |= 0x20000u;
      v102 = g_pShaderDeviceMgrDx8->m_pD3D;
      v103 = v102->__vftable;
      v240 = v101;
      v104 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v103->CheckDeviceFormat(
             this: v102,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v104,
             a5: v240,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A8R8G8B8) < 0 )
        return 0;
      return 21;
    case IMAGE_FORMAT_UV88:
      v149 = isRenderTarget;
      if ( bIsVertexTexture )
        v149 |= 0x100000u;
      if ( bIsFilterableRequired )
        v149 |= 0x20000u;
      v150 = g_pShaderDeviceMgrDx8->m_pD3D;
      v151 = v150->__vftable;
      v252 = v149;
      v152 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v151->CheckDeviceFormat(
             this: v150,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v152,
             a5: v252,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_V8U8) < 0 )
        return 0;
      return 60;
    case IMAGE_FORMAT_UVWQ8888:
      v153 = isRenderTarget;
      if ( bIsVertexTexture )
        v153 |= 0x100000u;
      if ( bIsFilterableRequired )
        v153 |= 0x20000u;
      v154 = g_pShaderDeviceMgrDx8->m_pD3D;
      v155 = v154->__vftable;
      v253 = v153;
      v156 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v155->CheckDeviceFormat(
             this: v154,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v156,
             a5: v253,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_Q8W8V8U8) < 0 )
        return 0;
      return 63;
    case IMAGE_FORMAT_RGBA16161616F:
      v161 = isRenderTarget;
      if ( bIsVertexTexture )
        v161 |= 0x100000u;
      if ( bIsFilterableRequired )
        v161 |= 0x20000u;
      v162 = g_pShaderDeviceMgrDx8->m_pD3D;
      v163 = v162->__vftable;
      v255 = v161;
      v164 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v163->CheckDeviceFormat(
             this: v162,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v164,
             a5: v255,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A16B16G16R16F) >= 0 )
        return 113;
      v165 = isRenderTarget;
      if ( bIsVertexTexture )
        v165 = isRenderTarget | 0x100000;
      if ( bIsFilterableRequired )
        v165 |= 0x20000u;
      v166 = g_pShaderDeviceMgrDx8->m_pD3D;
      v167 = v166->__vftable;
      v256 = v165;
      v168 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v167->CheckDeviceFormat(
             this: v166,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v168,
             a5: v256,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A16B16G16R16) < 0 )
        return 0;
      return 36;
    case IMAGE_FORMAT_RGBA16161616:
      v169 = isRenderTarget;
      if ( bIsVertexTexture )
        v169 |= 0x100000u;
      if ( bIsFilterableRequired )
        v169 |= 0x20000u;
      v170 = g_pShaderDeviceMgrDx8->m_pD3D;
      v171 = v170->__vftable;
      v257 = v169;
      v172 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v171->CheckDeviceFormat(
             this: v170,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v172,
             a5: v257,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A16B16G16R16) >= 0 )
        return 36;
      v173 = isRenderTarget;
      if ( bIsVertexTexture )
        v173 = isRenderTarget | 0x100000;
      if ( bIsFilterableRequired )
        v173 |= 0x20000u;
      v174 = g_pShaderDeviceMgrDx8->m_pD3D;
      v175 = v174->__vftable;
      v258 = v173;
      v176 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v175->CheckDeviceFormat(
             this: v174,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v176,
             a5: v258,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A16B16G16R16F) < 0 )
        return 0;
      return 113;
    case IMAGE_FORMAT_UVLX8888:
      v157 = isRenderTarget;
      if ( bIsVertexTexture )
        v157 |= 0x100000u;
      if ( bIsFilterableRequired )
        v157 |= 0x20000u;
      v158 = g_pShaderDeviceMgrDx8->m_pD3D;
      v159 = v158->__vftable;
      v254 = v157;
      v160 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v159->CheckDeviceFormat(
             this: v158,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v160,
             a5: v254,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_X8L8V8U8) < 0 )
        return 0;
      return 62;
    case IMAGE_FORMAT_R32F:
      v177 = isRenderTarget;
      if ( bIsVertexTexture )
        v177 |= 0x100000u;
      if ( bIsFilterableRequired )
        v177 |= 0x20000u;
      v178 = g_pShaderDeviceMgrDx8->m_pD3D;
      v179 = v178->__vftable;
      v259 = v177;
      v180 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v179->CheckDeviceFormat(
             this: v178,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v180,
             a5: v259,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_R32F) < 0 )
        return 0;
      return 114;
    case IMAGE_FORMAT_RGBA32323232F:
      v181 = isRenderTarget;
      if ( bIsVertexTexture )
        v181 |= 0x100000u;
      if ( bIsFilterableRequired )
        v181 |= 0x20000u;
      v182 = g_pShaderDeviceMgrDx8->m_pD3D;
      v183 = v182->__vftable;
      v260 = v181;
      v184 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v183->CheckDeviceFormat(
             this: v182,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v184,
             a5: v260,
             a6: D3DRTYPE_TEXTURE,
             a7: D3DFMT_A32B32G32R32F) < 0 )
        return 0;
      return 116;
    case IMAGE_FORMAT_NULL:
      v205 = isRenderTarget;
      if ( bIsVertexTexture )
        v205 |= 0x100000u;
      v206 = g_pShaderDeviceMgrDx8->m_pD3D;
      v207 = v206->__vftable;
      v265 = v205;
      v208 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v207->CheckDeviceFormat(
             this: v206,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v208,
             a5: v265,
             a6: D3DRTYPE_TEXTURE,
             a7: (_D3DFORMAT)1280070990) < 0 )
        return 0;
      return 1280070990;
    case IMAGE_FORMAT_ATI2N:
      v209 = isRenderTarget;
      if ( bIsVertexTexture )
        v209 |= 0x100000u;
      if ( bIsFilterableRequired )
        v209 |= 0x20000u;
      v210 = g_pShaderDeviceMgrDx8->m_pD3D;
      v211 = v210->__vftable;
      v266 = v209;
      v212 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v211->CheckDeviceFormat(
             this: v210,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v212,
             a5: v266,
             a6: D3DRTYPE_TEXTURE,
             a7: (_D3DFORMAT)843666497) < 0 )
        return 0;
      return 843666497;
    case IMAGE_FORMAT_ATI1N:
      v213 = isRenderTarget;
      if ( bIsVertexTexture )
        v213 |= 0x100000u;
      if ( bIsFilterableRequired )
        v213 |= 0x20000u;
      v214 = g_pShaderDeviceMgrDx8->m_pD3D;
      v215 = v214->__vftable;
      v267 = v213;
      v216 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
      if ( v215->CheckDeviceFormat(
             this: v214,
             a2: g_DisplayAdapter,
             a3: g_DeviceType,
             a4: v216,
             a5: v267,
             a6: D3DRTYPE_TEXTURE,
             a7: (_D3DFORMAT)826889281) < 0 )
        return 0;
      return 826889281;
    case IMAGE_FORMAT_D16_SHADOW:
      if ( g_pHardwareConfig->m_Caps.m_VendorID != 4098 || (*((_BYTE *)&g_pHardwareConfig->m_Caps + 719) & 1) != 0 )
      {
        v191 = isRenderTarget;
        if ( bIsVertexTexture )
          v191 |= 0x100000u;
        if ( bIsFilterableRequired )
          v191 |= 0x20000u;
        v192 = g_pShaderDeviceMgrDx8->m_pD3D;
        v193 = v192->__vftable;
        if ( isRenderTarget )
          v262 = 2;
        else
          v262 = v191;
        v194 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
        if ( v193->CheckDeviceFormat(
               this: v192,
               a2: g_DisplayAdapter,
               a3: g_DeviceType,
               a4: v194,
               a5: v262,
               a6: D3DRTYPE_TEXTURE,
               a7: D3DFMT_D16) >= 0 )
          return 80;
      }
      else
      {
        v185 = isRenderTarget;
        if ( bIsVertexTexture )
          v185 |= 0x100000u;
        v186 = g_pShaderDeviceMgrDx8->m_pD3D;
        v187 = v186->__vftable;
        if ( isRenderTarget )
        {
          v188 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
          v189 = v187->CheckDeviceFormat(
                   this: v186,
                   a2: g_DisplayAdapter,
                   a3: g_DeviceType,
                   a4: v188,
                   a5: 2u,
                   a6: D3DRTYPE_TEXTURE,
                   a7: (_D3DFORMAT)909198916);
        }
        else
        {
          v261 = v185;
          v190 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
          v189 = v187->CheckDeviceFormat(
                   this: v186,
                   a2: g_DisplayAdapter,
                   a3: g_DeviceType,
                   a4: v190,
                   a5: v261,
                   a6: D3DRTYPE_TEXTURE,
                   a7: (_D3DFORMAT)909198916);
        }
        if ( v189 >= 0 )
          return 909198916;
      }
      return 0;
    case IMAGE_FORMAT_D24X8_SHADOW:
      if ( g_pHardwareConfig->m_Caps.m_VendorID != 4098 || (*((_BYTE *)&g_pHardwareConfig->m_Caps + 719) & 1) != 0 )
      {
        v201 = isRenderTarget;
        if ( bIsVertexTexture )
          v201 |= 0x100000u;
        if ( bIsFilterableRequired )
          v201 |= 0x20000u;
        v202 = g_pShaderDeviceMgrDx8->m_pD3D;
        v203 = v202->__vftable;
        if ( isRenderTarget )
          v264 = 2;
        else
          v264 = v201;
        v204 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
        if ( v203->CheckDeviceFormat(
               this: v202,
               a2: g_DisplayAdapter,
               a3: g_DeviceType,
               a4: v204,
               a5: v264,
               a6: D3DRTYPE_TEXTURE,
               a7: D3DFMT_D24S8) >= 0 )
          return 75;
      }
      else
      {
        v195 = isRenderTarget;
        if ( bIsVertexTexture )
          v195 |= 0x100000u;
        v196 = g_pShaderDeviceMgrDx8->m_pD3D;
        v197 = v196->__vftable;
        if ( isRenderTarget )
        {
          v198 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
          v199 = v197->CheckDeviceFormat(
                   this: v196,
                   a2: g_DisplayAdapter,
                   a3: g_DeviceType,
                   a4: v198,
                   a5: 2u,
                   a6: D3DRTYPE_TEXTURE,
                   a7: (_D3DFORMAT)875710020);
        }
        else
        {
          v263 = v195;
          v200 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
          v199 = v197->CheckDeviceFormat(
                   this: v196,
                   a2: g_DisplayAdapter,
                   a3: g_DeviceType,
                   a4: v200,
                   a5: v263,
                   a6: D3DRTYPE_TEXTURE,
                   a7: (_D3DFORMAT)875710020);
        }
        if ( v199 >= 0 )
          return 875710020;
      }
      return 0;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002430
// Name: void InitializeColorInformation(unsigned int,enum _D3DDEVTYPE,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitializeColorInformation(int displayAdapter, _D3DDEVTYPE deviceType, ImageFormat displayFormat)
{
  _D3DFORMAT *v3; // edi
  int i; // esi
  IDirect3D9 *m_pD3D; // esi
  IDirect3D9_vtbl *v6; // edi
  _D3DFORMAT v7; // eax
  int v8; // eax
  IDirect3D9 *v9; // esi
  IDirect3D9_vtbl *v10; // edi
  _D3DFORMAT v11; // eax
  int v12; // eax
  IDirect3D9 *v13; // esi
  IDirect3D9_vtbl *v14; // edi
  _D3DFORMAT v15; // eax
  int v16; // eax
  IDirect3D9 *v17; // esi
  IDirect3D9_vtbl *v18; // edi
  _D3DFORMAT v19; // eax
  int v20; // eax
  IDirect3D9 *v21; // esi
  IDirect3D9_vtbl *v22; // edi
  _D3DFORMAT v23; // eax
  int nRenderTarget; // [esp+18h] [ebp+8h]
  int nVertexTexture; // [esp+1Ch] [ebp+Ch]
  ImageFormat fmt; // [esp+20h] [ebp+10h]

  g_DisplayAdapter = displayAdapter;
  g_DeviceType = deviceType;
  g_DeviceFormat = displayFormat;
  fmt = IMAGE_FORMAT_RGBA8888;
  v3 = g_D3DColorFormat[0][0][0];
  do
  {
    for ( nVertexTexture = 0; nVertexTexture <= 1; ++nVertexTexture )
    {
      for ( nRenderTarget = 0; nRenderTarget <= 1; ++nRenderTarget )
      {
        for ( i = 0; i <= 1; ++i )
          *v3++ = GetNearestD3DColorFormat(
                    fmt,
                    isRenderTarget: nRenderTarget != 0,
                    bIsVertexTexture: nVertexTexture != 0,
                    bIsFilterableRequired: i != 0);
      }
    }
    ++fmt;
  }
  while ( (int)v3 < (int)&g_DeviceFormat );
  m_pD3D = g_pShaderDeviceMgrDx8->m_pD3D;
  v6 = m_pD3D->__vftable;
  v7 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
  v8 = v6->CheckDeviceFormat(
         this: m_pD3D,
         a2: g_DisplayAdapter,
         a3: g_DeviceType,
         a4: v7,
         a5: 2u,
         a6: D3DRTYPE_SURFACE,
         a7: D3DFMT_D24S8);
  v9 = g_pShaderDeviceMgrDx8->m_pD3D;
  v10 = v9->__vftable;
  g_bSupportsD24S8 = v8 >= 0;
  v11 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
  v12 = v10->CheckDeviceFormat(
          this: v9,
          a2: g_DisplayAdapter,
          a3: g_DeviceType,
          a4: v11,
          a5: 2u,
          a6: D3DRTYPE_SURFACE,
          a7: D3DFMT_D24X8);
  v13 = g_pShaderDeviceMgrDx8->m_pD3D;
  v14 = v13->__vftable;
  g_bSupportsD24X8 = v12 >= 0;
  v15 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
  v16 = v14->CheckDeviceFormat(
          this: v13,
          a2: g_DisplayAdapter,
          a3: g_DeviceType,
          a4: v15,
          a5: 2u,
          a6: D3DRTYPE_SURFACE,
          a7: D3DFMT_D16);
  v17 = g_pShaderDeviceMgrDx8->m_pD3D;
  v18 = v17->__vftable;
  g_bSupportsD16 = v16 >= 0;
  v19 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
  v20 = v18->CheckDeviceFormat(
          this: v17,
          a2: g_DisplayAdapter,
          a3: g_DeviceType,
          a4: v19,
          a5: 2u,
          a6: D3DRTYPE_SURFACE,
          a7: D3DFMT_D24X4S4);
  v21 = g_pShaderDeviceMgrDx8->m_pD3D;
  v22 = v21->__vftable;
  g_bSupportsD24X4S4 = v20 >= 0;
  v23 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
  g_bSupportsD15S1 = v22->CheckDeviceFormat(
                       this: v21,
                       a2: g_DisplayAdapter,
                       a3: g_DeviceType,
                       a4: v23,
                       a5: 2u,
                       a6: D3DRTYPE_SURFACE,
                       a7: D3DFMT_D15S1) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002610
// Name: enum _D3DFORMAT FindNearestSupportedFormat(enum ImageFormat,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
_D3DFORMAT __cdecl FindNearestSupportedFormat(
        ImageFormat format,
        bool bIsVertexTexture,
        bool bIsRenderTarget,
        bool bFilterableRequired)
{
  return g_D3DColorFormat[format][bIsVertexTexture][bIsRenderTarget][bFilterableRequired];
}

//------------------------------------------------------------------------------
// Address: 0x10002640
// Name: IsDepthFormatCompatible
// Source: json
//------------------------------------------------------------------------------
bool __usercall IsDepthFormatCompatible@<al>(
        ImageFormat displayFormat@<eax>,
        _D3DFORMAT depthFormat@<edi>,
        unsigned int nAdapter,
        ImageFormat renderTargetFormat)
{
  _D3DFORMAT v4; // esi
  _D3DFORMAT v5; // eax

  v4 = ImageLoader::ImageFormatToD3DFormat(format: displayFormat);
  v5 = ImageLoader::ImageFormatToD3DFormat(format: renderTargetFormat);
  return g_pShaderDeviceMgrDx8->m_pD3D->CheckDepthStencilMatch(
           this: g_pShaderDeviceMgrDx8->m_pD3D,
           a2: nAdapter,
           a3: D3DDEVTYPE_HAL,
           a4: v4,
           a5: v5,
           a6: depthFormat) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002680
// Name: enum _D3DFORMAT FindNearestSupportedDepthFormat(int,enum ImageFormat,enum ImageFormat,enum _D3DFORMAT)
// Source: json
//------------------------------------------------------------------------------
_D3DFORMAT __cdecl FindNearestSupportedDepthFormat(
        unsigned int nAdapter,
        ImageFormat displayFormat,
        ImageFormat renderTargetFormat,
        _D3DFORMAT depthFormat)
{
  int v4; // edi
  _D3DFORMAT result; // eax
  bool v6; // zf

  if ( depthFormat != D3DFMT_D24S8 )
  {
    if ( depthFormat == D3DFMT_D24X8 )
    {
      if ( g_bSupportsD24X8 )
      {
        v4 = 77;
        if ( IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D24X8, nAdapter, renderTargetFormat) )
          return v4;
      }
      if ( g_bSupportsD24S8 )
      {
        v4 = 75;
        if ( IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D24S8, nAdapter, renderTargetFormat) )
          return v4;
      }
      if ( g_bSupportsD24X4S4 )
      {
        v4 = 79;
        if ( IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D24X4S4, nAdapter, renderTargetFormat) )
          return v4;
      }
      if ( g_bSupportsD16 )
      {
        v4 = 80;
        if ( IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D16, nAdapter, renderTargetFormat) )
          return v4;
      }
      if ( g_bSupportsD15S1 )
      {
        v4 = 73;
        if ( IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D15S1, nAdapter, renderTargetFormat) )
          return v4;
      }
    }
    else if ( depthFormat == D3DFMT_D16 )
    {
      if ( !g_bSupportsD16
        || (v4 = 80, !IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D16, nAdapter, renderTargetFormat)) )
      {
        if ( !g_bSupportsD15S1
          || (v4 = 73, !IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D15S1, nAdapter, renderTargetFormat)) )
        {
          if ( !g_bSupportsD24X8
            || (v4 = 77, !IsDepthFormatCompatible(
                            displayFormat,
                            depthFormat: D3DFMT_D24X8,
                            nAdapter,
                            renderTargetFormat)) )
          {
            if ( !g_bSupportsD24S8
              || (v4 = 75,
                  !IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D24S8, nAdapter, renderTargetFormat)) )
            {
              if ( g_bSupportsD24X4S4
                && IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D24X4S4, nAdapter, renderTargetFormat) )
              {
                return D3DFMT_D24X4S4;
              }
              return D3DFMT_D16;
            }
          }
        }
      }
      return v4;
    }
    return D3DFMT_D16;
  }
  if ( g_bSupportsD24S8 )
  {
    v4 = 75;
    if ( IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D24S8, nAdapter, renderTargetFormat) )
      return v4;
  }
  if ( g_bSupportsD24X4S4 )
  {
    v4 = 79;
    if ( IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D24X4S4, nAdapter, renderTargetFormat) )
      return v4;
  }
  if ( g_bSupportsD15S1 )
  {
    v4 = 73;
    if ( IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D15S1, nAdapter, renderTargetFormat) )
      return v4;
  }
  if ( g_bSupportsD24X8 )
  {
    v4 = 77;
    if ( IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D24X8, nAdapter, renderTargetFormat) )
      return v4;
  }
  if ( !g_bSupportsD16 )
    return D3DFMT_D16;
  v6 = !IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D16, nAdapter, renderTargetFormat);
  result = D3DFMT_D16;
  if ( v6 )
    return D3DFMT_D16;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100028F0
// Name: IsFrameBufferFormatValid
// Source: json
//------------------------------------------------------------------------------
bool __usercall IsFrameBufferFormatValid@<al>(
        bool bIsWindowed@<dl>,
        unsigned int displayAdapter,
        _D3DDEVTYPE deviceType,
        _D3DFORMAT displayFormat,
        _D3DFORMAT backBufferFormat)
{
  return g_pShaderDeviceMgrDx8->m_pD3D->CheckDeviceType(
           this: g_pShaderDeviceMgrDx8->m_pD3D,
           a2: displayAdapter,
           a3: deviceType,
           a4: displayFormat,
           a5: backBufferFormat,
           a6: bIsWindowed) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002920
// Name: enum ImageFormat FindNearestSupportedBackBufferFormat(unsigned int,enum _D3DDEVTYPE,enum ImageFormat,enum ImageFormat,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindNearestSupportedBackBufferFormat(
        unsigned int displayAdapter,
        _D3DDEVTYPE deviceType,
        ImageFormat displayFormat,
        ImageFormat backBufferFormat,
        bool bIsWindowed)
{
  _D3DFORMAT v5; // esi
  bool v6; // bl
  _D3DDEVTYPE v7; // edi

  v5 = ImageLoader::ImageFormatToD3DFormat(format: displayFormat);
  switch ( backBufferFormat )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_ABGR8888:
    case IMAGE_FORMAT_ARGB8888:
    case IMAGE_FORMAT_BGRA8888:
    case IMAGE_FORMAT_BGRA4444:
      v6 = bIsWindowed;
      v7 = deviceType;
      if ( g_pShaderDeviceMgrDx8->m_pD3D->CheckDeviceType(
             this: g_pShaderDeviceMgrDx8->m_pD3D,
             a2: displayAdapter,
             a3: deviceType,
             a4: v5,
             a5: D3DFMT_A8R8G8B8,
             a6: bIsWindowed) >= 0 )
        return 12;
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_X8R8G8B8) )
      {
        return 16;
      }
      if ( !IsFrameBufferFormatValid(
              bIsWindowed,
              displayAdapter,
              deviceType,
              displayFormat: v5,
              backBufferFormat: D3DFMT_R5G6B5) )
        goto LABEL_8;
      return 17;
    case IMAGE_FORMAT_RGB888:
    case IMAGE_FORMAT_BGR888:
    case IMAGE_FORMAT_RGB888_BLUESCREEN:
    case IMAGE_FORMAT_BGRX8888:
      v6 = bIsWindowed;
      v7 = deviceType;
      if ( g_pShaderDeviceMgrDx8->m_pD3D->CheckDeviceType(
             this: g_pShaderDeviceMgrDx8->m_pD3D,
             a2: displayAdapter,
             a3: deviceType,
             a4: v5,
             a5: D3DFMT_X8R8G8B8,
             a6: bIsWindowed) >= 0 )
        return 16;
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_A8R8G8B8) )
      {
        return 12;
      }
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_R5G6B5) )
      {
        return 17;
      }
LABEL_8:
      if ( IsFrameBufferFormatValid(
             bIsWindowed: v6,
             displayAdapter,
             deviceType: v7,
             displayFormat: v5,
             backBufferFormat: D3DFMT_A1R5G5B5) )
      {
        return 21;
      }
      else
      {
        return IsFrameBufferFormatValid(
                 bIsWindowed: v6,
                 displayAdapter,
                 deviceType: v7,
                 displayFormat: v5,
                 backBufferFormat: D3DFMT_X1R5G5B5)
             ? 18
             : -1;
      }
    case IMAGE_FORMAT_RGB565:
    case IMAGE_FORMAT_BGR565:
      if ( g_pShaderDeviceMgrDx8->m_pD3D->CheckDeviceType(
             this: g_pShaderDeviceMgrDx8->m_pD3D,
             a2: displayAdapter,
             a3: deviceType,
             a4: v5,
             a5: D3DFMT_R5G6B5,
             a6: bIsWindowed) >= 0 )
        return 17;
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_A1R5G5B5) )
      {
        return 21;
      }
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_X1R5G5B5) )
      {
        return 18;
      }
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_X8R8G8B8) )
      {
        return 16;
      }
      return IsFrameBufferFormatValid(
               bIsWindowed,
               displayAdapter,
               deviceType,
               displayFormat: v5,
               backBufferFormat: D3DFMT_A8R8G8B8)
           ? 12
           : -1;
    case IMAGE_FORMAT_BGRX5551:
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_X1R5G5B5) )
      {
        return 18;
      }
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_A1R5G5B5) )
      {
        return 21;
      }
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_R5G6B5) )
      {
        return 17;
      }
      if ( !IsFrameBufferFormatValid(
              bIsWindowed,
              displayAdapter,
              deviceType,
              displayFormat: v5,
              backBufferFormat: D3DFMT_X8R8G8B8) )
        return IsFrameBufferFormatValid(
                 bIsWindowed,
                 displayAdapter,
                 deviceType,
                 displayFormat: v5,
                 backBufferFormat: D3DFMT_A8R8G8B8)
             ? 12
             : -1;
      return 16;
    case IMAGE_FORMAT_BGRA5551:
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_A1R5G5B5) )
      {
        return 21;
      }
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_X1R5G5B5) )
      {
        return 18;
      }
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_R5G6B5) )
      {
        return 17;
      }
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_A8R8G8B8) )
      {
        return 12;
      }
      return IsFrameBufferFormatValid(
               bIsWindowed,
               displayAdapter,
               deviceType,
               displayFormat: v5,
               backBufferFormat: D3DFMT_X8R8G8B8)
           ? 16
           : -1;
    default:
      return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002C40
// Name: __CreateCVBAllocTrackerIVBAllocTracker_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVBAllocTracker *__cdecl _CreateCVBAllocTrackerIVBAllocTracker_interface()
{
  return &s_VBAllocTracker;
}

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x100024F0
// Name: void InitializeColorInformation(unsigned int,enum _D3DDEVTYPE,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitializeColorInformation(int displayAdapter, _D3DDEVTYPE deviceType, ImageFormat displayFormat)
{
  ImageFormat v3; // ebp
  _D3DFORMAT *v4; // edi
  int i; // esi
  IDirect3D9 *m_pD3D; // esi
  IDirect3D9_vtbl *v7; // edi
  _D3DFORMAT v8; // eax
  int v9; // eax
  IDirect3D9 *v10; // esi
  IDirect3D9_vtbl *v11; // edi
  _D3DFORMAT v12; // eax
  int v13; // eax
  IDirect3D9 *v14; // esi
  IDirect3D9_vtbl *v15; // edi
  _D3DFORMAT v16; // eax
  int v17; // eax
  IDirect3D9 *v18; // esi
  IDirect3D9_vtbl *v19; // edi
  _D3DFORMAT v20; // eax
  int v21; // eax
  IDirect3D9 *v22; // esi
  IDirect3D9_vtbl *v23; // edi
  _D3DFORMAT v24; // eax
  int nRenderTarget; // [esp+14h] [ebp+4h]
  int nVertexTexture; // [esp+18h] [ebp+8h]

  g_DisplayAdapter = displayAdapter;
  g_DeviceType = deviceType;
  g_DeviceFormat = displayFormat;
  v3 = IMAGE_FORMAT_RGBA8888;
  v4 = g_D3DColorFormat[0][0][0];
  do
  {
    for ( nVertexTexture = 0; nVertexTexture <= 1; ++nVertexTexture )
    {
      for ( nRenderTarget = 0; nRenderTarget <= 1; ++nRenderTarget )
      {
        for ( i = 0; i <= 1; ++i )
          *v4++ = GetNearestD3DColorFormat(
                    fmt: v3,
                    isRenderTarget: nRenderTarget != 0,
                    bIsVertexTexture: nVertexTexture != 0,
                    bIsFilterableRequired: i != 0);
      }
    }
    ++v3;
  }
  while ( (int)v4 < (int)&g_DeviceFormat );
  m_pD3D = g_pShaderDeviceMgrDx8->m_pD3D;
  v7 = m_pD3D->__vftable;
  v8 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
  v9 = v7->CheckDeviceFormat(
         this: m_pD3D,
         a2: g_DisplayAdapter,
         a3: g_DeviceType,
         a4: v8,
         a5: 2u,
         a6: D3DRTYPE_SURFACE,
         a7: D3DFMT_D24S8);
  v10 = g_pShaderDeviceMgrDx8->m_pD3D;
  v11 = v10->__vftable;
  g_bSupportsD24S8 = v9 >= 0;
  v12 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
  v13 = v11->CheckDeviceFormat(
          this: v10,
          a2: g_DisplayAdapter,
          a3: g_DeviceType,
          a4: v12,
          a5: 2u,
          a6: D3DRTYPE_SURFACE,
          a7: D3DFMT_D24X8);
  v14 = g_pShaderDeviceMgrDx8->m_pD3D;
  v15 = v14->__vftable;
  g_bSupportsD24X8 = v13 >= 0;
  v16 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
  v17 = v15->CheckDeviceFormat(
          this: v14,
          a2: g_DisplayAdapter,
          a3: g_DeviceType,
          a4: v16,
          a5: 2u,
          a6: D3DRTYPE_SURFACE,
          a7: D3DFMT_D16);
  v18 = g_pShaderDeviceMgrDx8->m_pD3D;
  v19 = v18->__vftable;
  g_bSupportsD16 = v17 >= 0;
  v20 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
  v21 = v19->CheckDeviceFormat(
          this: v18,
          a2: g_DisplayAdapter,
          a3: g_DeviceType,
          a4: v20,
          a5: 2u,
          a6: D3DRTYPE_SURFACE,
          a7: D3DFMT_D24X4S4);
  v22 = g_pShaderDeviceMgrDx8->m_pD3D;
  v23 = v22->__vftable;
  g_bSupportsD24X4S4 = v21 >= 0;
  v24 = ImageLoader::ImageFormatToD3DFormat(format: g_DeviceFormat);
  g_bSupportsD15S1 = v23->CheckDeviceFormat(
                       this: v22,
                       a2: g_DisplayAdapter,
                       a3: g_DeviceType,
                       a4: v24,
                       a5: 2u,
                       a6: D3DRTYPE_SURFACE,
                       a7: D3DFMT_D15S1) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x100026E0
// Name: enum _D3DFORMAT FindNearestSupportedFormat(enum ImageFormat,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
_D3DFORMAT __cdecl FindNearestSupportedFormat(
        ImageFormat format,
        bool bIsVertexTexture,
        bool bIsRenderTarget,
        bool bFilterableRequired)
{
  return g_D3DColorFormat[format][bIsVertexTexture][bIsRenderTarget][bFilterableRequired];
}

//------------------------------------------------------------------------------
// Address: 0x10002710
// Name: IsDepthFormatCompatible
// Source: json
//------------------------------------------------------------------------------
bool __usercall IsDepthFormatCompatible@<al>(
        ImageFormat displayFormat@<eax>,
        _D3DFORMAT depthFormat@<edi>,
        unsigned int nAdapter,
        ImageFormat renderTargetFormat)
{
  _D3DFORMAT v4; // esi
  _D3DFORMAT v5; // eax

  v4 = ImageLoader::ImageFormatToD3DFormat(format: displayFormat);
  v5 = ImageLoader::ImageFormatToD3DFormat(format: renderTargetFormat);
  return g_pShaderDeviceMgrDx8->m_pD3D->CheckDepthStencilMatch(
           this: g_pShaderDeviceMgrDx8->m_pD3D,
           a2: nAdapter,
           a3: D3DDEVTYPE_HAL,
           a4: v4,
           a5: v5,
           a6: depthFormat) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002750
// Name: enum _D3DFORMAT FindNearestSupportedDepthFormat(int,enum ImageFormat,enum ImageFormat,enum _D3DFORMAT)
// Source: json
//------------------------------------------------------------------------------
_D3DFORMAT __cdecl FindNearestSupportedDepthFormat(
        unsigned int nAdapter,
        ImageFormat displayFormat,
        ImageFormat renderTargetFormat,
        _D3DFORMAT depthFormat)
{
  int v4; // edi
  _D3DFORMAT result; // eax
  bool v6; // zf

  if ( depthFormat != D3DFMT_D24S8 )
  {
    if ( depthFormat == D3DFMT_D24X8 )
    {
      if ( g_bSupportsD24X8 )
      {
        v4 = 77;
        if ( IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D24X8, nAdapter, renderTargetFormat) )
          return v4;
      }
      if ( g_bSupportsD24S8 )
      {
        v4 = 75;
        if ( IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D24S8, nAdapter, renderTargetFormat) )
          return v4;
      }
      if ( g_bSupportsD24X4S4 )
      {
        v4 = 79;
        if ( IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D24X4S4, nAdapter, renderTargetFormat) )
          return v4;
      }
      if ( g_bSupportsD16 )
      {
        v4 = 80;
        if ( IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D16, nAdapter, renderTargetFormat) )
          return v4;
      }
      if ( g_bSupportsD15S1 )
      {
        v4 = 73;
        if ( IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D15S1, nAdapter, renderTargetFormat) )
          return v4;
      }
    }
    else if ( depthFormat == D3DFMT_D16 )
    {
      if ( !g_bSupportsD16
        || (v4 = 80, !IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D16, nAdapter, renderTargetFormat)) )
      {
        if ( !g_bSupportsD15S1
          || (v4 = 73, !IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D15S1, nAdapter, renderTargetFormat)) )
        {
          if ( !g_bSupportsD24X8
            || (v4 = 77, !IsDepthFormatCompatible(
                            displayFormat,
                            depthFormat: D3DFMT_D24X8,
                            nAdapter,
                            renderTargetFormat)) )
          {
            if ( !g_bSupportsD24S8
              || (v4 = 75,
                  !IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D24S8, nAdapter, renderTargetFormat)) )
            {
              if ( g_bSupportsD24X4S4
                && IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D24X4S4, nAdapter, renderTargetFormat) )
              {
                return D3DFMT_D24X4S4;
              }
              return D3DFMT_D16;
            }
          }
        }
      }
      return v4;
    }
    return D3DFMT_D16;
  }
  if ( g_bSupportsD24S8 )
  {
    v4 = 75;
    if ( IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D24S8, nAdapter, renderTargetFormat) )
      return v4;
  }
  if ( g_bSupportsD24X4S4 )
  {
    v4 = 79;
    if ( IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D24X4S4, nAdapter, renderTargetFormat) )
      return v4;
  }
  if ( g_bSupportsD15S1 )
  {
    v4 = 73;
    if ( IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D15S1, nAdapter, renderTargetFormat) )
      return v4;
  }
  if ( g_bSupportsD24X8 )
  {
    v4 = 77;
    if ( IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D24X8, nAdapter, renderTargetFormat) )
      return v4;
  }
  if ( !g_bSupportsD16 )
    return D3DFMT_D16;
  v6 = !IsDepthFormatCompatible(displayFormat, depthFormat: D3DFMT_D16, nAdapter, renderTargetFormat);
  result = D3DFMT_D16;
  if ( v6 )
    return D3DFMT_D16;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100029A0
// Name: IsFrameBufferFormatValid
// Source: json
//------------------------------------------------------------------------------
bool __usercall IsFrameBufferFormatValid@<al>(
        bool bIsWindowed@<dl>,
        unsigned int displayAdapter,
        _D3DDEVTYPE deviceType,
        _D3DFORMAT displayFormat,
        _D3DFORMAT backBufferFormat)
{
  return g_pShaderDeviceMgrDx8->m_pD3D->CheckDeviceType(
           this: g_pShaderDeviceMgrDx8->m_pD3D,
           a2: displayAdapter,
           a3: deviceType,
           a4: displayFormat,
           a5: backBufferFormat,
           a6: bIsWindowed) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x100029E0
// Name: enum ImageFormat FindNearestSupportedBackBufferFormat(unsigned int,enum _D3DDEVTYPE,enum ImageFormat,enum ImageFormat,bool)
// Source: json
//------------------------------------------------------------------------------
ImageFormat __cdecl FindNearestSupportedBackBufferFormat(
        unsigned int displayAdapter,
        _D3DDEVTYPE deviceType,
        ImageFormat displayFormat,
        ImageFormat backBufferFormat,
        bool bIsWindowed)
{
  _D3DFORMAT v5; // esi
  bool v6; // bl
  _D3DDEVTYPE v7; // edi
  unsigned int v8; // ebp
  ImageFormat result; // eax
  _D3DDEVTYPE v10; // edi
  unsigned int v11; // ebp
  bool v12; // bl

  v5 = ImageLoader::ImageFormatToD3DFormat(format: displayFormat);
  switch ( backBufferFormat )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_ABGR8888:
    case IMAGE_FORMAT_ARGB8888:
    case IMAGE_FORMAT_BGRA8888:
    case IMAGE_FORMAT_BGRA4444:
      v6 = bIsWindowed;
      v7 = deviceType;
      v8 = displayAdapter;
      if ( g_pShaderDeviceMgrDx8->m_pD3D->CheckDeviceType(
             this: g_pShaderDeviceMgrDx8->m_pD3D,
             a2: displayAdapter,
             a3: deviceType,
             a4: v5,
             a5: D3DFMT_A8R8G8B8,
             a6: bIsWindowed) >= 0 )
        goto LABEL_3;
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_X8R8G8B8) )
      {
        goto LABEL_5;
      }
      if ( !IsFrameBufferFormatValid(
              bIsWindowed,
              displayAdapter,
              deviceType,
              displayFormat: v5,
              backBufferFormat: D3DFMT_R5G6B5) )
        goto LABEL_8;
      goto LABEL_7;
    case IMAGE_FORMAT_RGB888:
    case IMAGE_FORMAT_BGR888:
    case IMAGE_FORMAT_RGB888_BLUESCREEN:
    case IMAGE_FORMAT_BGRX8888:
      v6 = bIsWindowed;
      v7 = deviceType;
      v8 = displayAdapter;
      if ( g_pShaderDeviceMgrDx8->m_pD3D->CheckDeviceType(
             this: g_pShaderDeviceMgrDx8->m_pD3D,
             a2: displayAdapter,
             a3: deviceType,
             a4: v5,
             a5: D3DFMT_X8R8G8B8,
             a6: bIsWindowed) >= 0 )
        goto LABEL_5;
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_A8R8G8B8) )
      {
        goto LABEL_3;
      }
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_R5G6B5) )
      {
        goto LABEL_7;
      }
LABEL_8:
      if ( IsFrameBufferFormatValid(
             bIsWindowed: v6,
             displayAdapter: v8,
             deviceType: v7,
             displayFormat: v5,
             backBufferFormat: D3DFMT_A1R5G5B5) )
      {
LABEL_9:
        result = IMAGE_FORMAT_BGRA5551;
      }
      else
      {
        result = IsFrameBufferFormatValid(
                   bIsWindowed: v6,
                   displayAdapter: v8,
                   deviceType: v7,
                   displayFormat: v5,
                   backBufferFormat: D3DFMT_X1R5G5B5)
               ? IMAGE_FORMAT_BGRX5551
               : IMAGE_FORMAT_UNKNOWN;
      }
      break;
    case IMAGE_FORMAT_RGB565:
    case IMAGE_FORMAT_BGR565:
      v10 = deviceType;
      v11 = displayAdapter;
      v12 = bIsWindowed;
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_R5G6B5) )
      {
        goto LABEL_7;
      }
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_A1R5G5B5) )
      {
        goto LABEL_9;
      }
      if ( !IsFrameBufferFormatValid(
              bIsWindowed,
              displayAdapter,
              deviceType,
              displayFormat: v5,
              backBufferFormat: D3DFMT_X1R5G5B5) )
        goto LABEL_19;
LABEL_18:
      result = IMAGE_FORMAT_BGRX5551;
      break;
    case IMAGE_FORMAT_BGRX5551:
      v10 = deviceType;
      v11 = displayAdapter;
      v12 = bIsWindowed;
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_X1R5G5B5) )
      {
        goto LABEL_18;
      }
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_A1R5G5B5) )
      {
        goto LABEL_9;
      }
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_R5G6B5) )
      {
        result = IMAGE_FORMAT_BGR565;
      }
      else
      {
LABEL_19:
        if ( IsFrameBufferFormatValid(
               bIsWindowed: v12,
               displayAdapter: v11,
               deviceType: v10,
               displayFormat: v5,
               backBufferFormat: D3DFMT_X8R8G8B8) )
        {
LABEL_5:
          result = IMAGE_FORMAT_BGRX8888;
        }
        else
        {
          result = IsFrameBufferFormatValid(
                     bIsWindowed: v12,
                     displayAdapter: v11,
                     deviceType: v10,
                     displayFormat: v5,
                     backBufferFormat: D3DFMT_A8R8G8B8)
                 ? IMAGE_FORMAT_BGRA8888
                 : IMAGE_FORMAT_UNKNOWN;
        }
      }
      break;
    case IMAGE_FORMAT_BGRA5551:
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_A1R5G5B5) )
      {
        goto LABEL_9;
      }
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_X1R5G5B5) )
      {
        goto LABEL_18;
      }
      if ( IsFrameBufferFormatValid(
             bIsWindowed,
             displayAdapter,
             deviceType,
             displayFormat: v5,
             backBufferFormat: D3DFMT_R5G6B5) )
      {
LABEL_7:
        result = IMAGE_FORMAT_BGR565;
      }
      else if ( IsFrameBufferFormatValid(
                  bIsWindowed,
                  displayAdapter,
                  deviceType,
                  displayFormat: v5,
                  backBufferFormat: D3DFMT_A8R8G8B8) )
      {
LABEL_3:
        result = IMAGE_FORMAT_BGRA8888;
      }
      else
      {
        result = IsFrameBufferFormatValid(
                   bIsWindowed,
                   displayAdapter,
                   deviceType,
                   displayFormat: v5,
                   backBufferFormat: D3DFMT_X8R8G8B8)
               ? IMAGE_FORMAT_BGRX8888
               : IMAGE_FORMAT_UNKNOWN;
      }
      break;
    default:
      return IMAGE_FORMAT_UNKNOWN;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002CC0
// Name: __CreateCVBAllocTrackerIVBAllocTracker_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVBAllocTracker *__cdecl _CreateCVBAllocTrackerIVBAllocTracker_interface()
{
  return &s_VBAllocTracker;
}

} // namespace shaderapidx10
