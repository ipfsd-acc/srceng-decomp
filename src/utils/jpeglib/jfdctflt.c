// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jfdctflt.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x102592B0
// Name: _jpeg_fdct_float
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_fdct_float(float *data)
{
  float v2; // xmm6_4
  float v3; // xmm5_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm6_4
  float v10; // xmm2_4
  float v11; // xmm7_4
  float v12; // xmm5_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm7_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm4_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm5_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm4_4
  float v27; // xmm6_4
  float v28; // xmm6_4
  float v29; // xmm5_4
  float v30; // xmm7_4
  float v31; // xmm4_4
  float v32; // xmm6_4
  float v33; // xmm5_4
  float v34; // xmm4_4
  float v35; // xmm7_4
  float v36; // xmm6_4
  float v37; // xmm5_4
  float v38; // xmm4_4
  float v39; // xmm6_4
  float v40; // xmm6_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm4_4
  float v44; // xmm6_4
  float v45; // xmm5_4
  float v46; // xmm4_4
  float v47; // xmm7_4
  float v48; // xmm6_4
  float v49; // xmm5_4
  float v50; // xmm4_4
  float v51; // xmm6_4
  float v52; // xmm5_4
  float v53; // xmm7_4
  float v54; // xmm4_4
  float v55; // xmm6_4
  float v56; // xmm5_4
  float v57; // xmm4_4
  float v58; // xmm6_4
  float v59; // xmm7_4
  float v60; // xmm5_4
  float v61; // xmm4_4
  float v62; // xmm5_4
  float v63; // xmm6_4
  float v64; // xmm4_4
  float v65; // xmm7_4
  float v66; // xmm6_4
  float v67; // xmm7_4
  float v68; // xmm6_4
  float v69; // xmm5_4
  float v70; // xmm4_4
  float v71; // xmm6_4
  float v72; // xmm5_4
  float v73; // xmm7_4
  float v74; // xmm4_4
  float v75; // xmm6_4
  float v76; // xmm7_4
  float v77; // xmm5_4
  float v78; // xmm4_4
  float v79; // xmm5_4
  float v80; // xmm6_4
  float v81; // xmm4_4
  float v82; // xmm7_4
  float v83; // xmm6_4
  float v84; // xmm7_4
  float v85; // xmm7_4
  float v86; // xmm6_4
  float v87; // xmm5_4
  float v88; // xmm4_4
  float v89; // xmm6_4
  float v90; // xmm5_4
  float v91; // xmm7_4
  float v92; // xmm4_4
  float v93; // xmm6_4
  float v94; // xmm5_4
  float v95; // xmm4_4
  float v96; // xmm5_4
  float v97; // xmm6_4
  float v98; // xmm7_4
  float v99; // xmm4_4
  float v100; // xmm7_4
  float v101; // xmm6_4
  float v102; // xmm7_4
  float v103; // xmm6_4
  float v104; // xmm5_4
  float v105; // xmm7_4
  float v106; // xmm4_4
  float v107; // xmm6_4
  float v108; // xmm5_4
  float v109; // xmm4_4
  float v110; // xmm7_4
  float v111; // xmm6_4
  float v112; // xmm5_4
  float v113; // xmm4_4
  float v114; // xmm5_4
  float v115; // xmm6_4
  float v116; // xmm7_4
  float v117; // xmm4_4
  float v118; // xmm7_4
  float v119; // xmm6_4
  float v120; // xmm7_4
  float v121; // xmm6_4
  float v122; // xmm5_4
  float v123; // xmm7_4
  float v124; // xmm4_4
  float v125; // xmm6_4
  float v126; // xmm5_4
  float v127; // xmm7_4
  float v128; // xmm6_4
  float v129; // xmm7_4
  float v130; // xmm4_4
  float v131; // xmm5_4
  float v132; // xmm6_4
  float v133; // xmm4_4
  float v134; // xmm7_4
  float v135; // xmm6_4
  float v136; // xmm7_4
  float v137; // xmm6_4
  float v138; // xmm5_4
  float v139; // xmm7_4
  float v140; // xmm4_4
  float v141; // xmm6_4
  float v142; // xmm5_4
  float v143; // xmm4_4
  float v144; // xmm7_4
  float v145; // xmm6_4
  float v146; // xmm5_4
  float v147; // xmm4_4
  float v148; // xmm5_4
  float v149; // xmm6_4
  float v150; // xmm7_4
  float v151; // xmm4_4
  float v152; // xmm7_4
  float v153; // xmm6_4
  float v154; // xmm7_4
  float v155; // xmm6_4
  float v156; // xmm7_4
  float v157; // xmm6_4
  float v158; // xmm5_4
  float v159; // xmm4_4
  float v160; // xmm6_4
  float v161; // xmm5_4
  float v162; // xmm4_4
  float v163; // xmm7_4
  float v164; // xmm6_4
  float v165; // xmm5_4
  float v166; // xmm4_4
  float v167; // xmm5_4
  float v168; // xmm6_4
  float v169; // xmm7_4
  float v170; // xmm4_4
  float v171; // xmm7_4
  float v172; // xmm6_4
  float v173; // xmm7_4
  float v174; // xmm6_4
  float v175; // xmm7_4
  float v176; // xmm6_4
  float v177; // xmm5_4
  float v178; // xmm4_4
  float v179; // xmm6_4
  float v180; // xmm5_4
  float v181; // xmm7_4
  float v182; // xmm4_4
  float v183; // xmm6_4
  float v184; // xmm5_4
  float v185; // xmm4_4
  float v186; // xmm5_4
  float v187; // xmm6_4
  float v188; // xmm7_4
  float v189; // xmm4_4
  float v190; // xmm7_4
  float v191; // xmm6_4
  float v192; // xmm7_4
  float v193; // xmm6_4
  float v194; // xmm7_4
  float v195; // xmm6_4
  float v196; // xmm5_4
  float v197; // xmm4_4
  float v198; // xmm6_4
  float v199; // xmm5_4
  float v200; // xmm4_4
  float v201; // xmm7_4
  float v202; // xmm6_4
  float v203; // xmm5_4
  float v204; // xmm4_4
  float v205; // xmm5_4
  float v206; // xmm6_4
  float v207; // xmm4_4
  float v208; // xmm7_4
  float v209; // xmm6_4
  float v210; // xmm7_4
  float v211; // xmm6_4
  float v212; // xmm7_4
  float v213; // xmm6_4
  float v214; // xmm5_4
  float v215; // xmm4_4
  float v216; // xmm6_4
  float v217; // xmm5_4
  float v218; // xmm4_4
  float v219; // xmm6_4
  float v220; // xmm7_4
  float v221; // xmm5_4
  float v222; // xmm4_4
  float v223; // xmm5_4
  float v224; // xmm6_4
  float v225; // xmm4_4
  float v226; // xmm7_4
  float v227; // xmm6_4
  float v228; // xmm7_4
  float v229; // xmm6_4
  float v230; // xmm7_4
  float v231; // xmm6_4
  float v232; // xmm5_4
  float v233; // xmm4_4
  float v234; // xmm6_4
  float v235; // xmm5_4
  float v236; // xmm4_4
  float v237; // xmm6_4
  float v238; // xmm7_4
  float v239; // xmm5_4
  float v240; // xmm4_4
  float v241; // xmm4_4
  float v242; // xmm7_4
  float v243; // xmm6_4
  float v244; // xmm7_4
  float v245; // xmm6_4
  float v246; // xmm7_4
  float v247; // xmm6_4
  float v248; // xmm5_4
  float v249; // xmm4_4
  float v250; // xmm6_4
  float v251; // xmm5_4
  float v252; // xmm4_4
  float v253; // xmm7_4
  float v254; // xmm6_4
  float v255; // xmm5_4
  float v256; // xmm4_4
  float v257; // xmm5_4
  float v258; // xmm6_4
  float v259; // xmm7_4
  float v260; // xmm4_4
  float v261; // xmm7_4
  float v262; // xmm6_4
  float v263; // xmm7_4
  float v264; // xmm6_4
  float v265; // xmm7_4
  float v266; // xmm6_4
  float v267; // xmm5_4
  float v268; // xmm4_4
  float v269; // xmm6_4
  float v270; // xmm1_4
  float v271; // xmm5_4
  float v272; // xmm4_4
  float v273; // [esp+0h] [ebp-24h]
  float v274; // [esp+0h] [ebp-24h]
  float v275; // [esp+0h] [ebp-24h]
  float v276; // [esp+0h] [ebp-24h]
  float v277; // [esp+0h] [ebp-24h]
  float v278; // [esp+0h] [ebp-24h]
  float v279; // [esp+0h] [ebp-24h]
  float v280; // [esp+0h] [ebp-24h]
  float v281; // [esp+0h] [ebp-24h]
  float v282; // [esp+0h] [ebp-24h]
  float v283; // [esp+0h] [ebp-24h]
  float v284; // [esp+0h] [ebp-24h]
  float v285; // [esp+0h] [ebp-24h]
  float v286; // [esp+0h] [ebp-24h]
  float v287; // [esp+0h] [ebp-24h]
  float v288; // [esp+0h] [ebp-24h]
  float v289; // [esp+0h] [ebp-24h]
  float v290; // [esp+0h] [ebp-24h]
  float v291; // [esp+0h] [ebp-24h]
  float v292; // [esp+0h] [ebp-24h]
  float v293; // [esp+0h] [ebp-24h]
  float v294; // [esp+0h] [ebp-24h]
  float v295; // [esp+0h] [ebp-24h]
  float v296; // [esp+0h] [ebp-24h]
  float v297; // [esp+0h] [ebp-24h]
  float v298; // [esp+0h] [ebp-24h]
  float v299; // [esp+0h] [ebp-24h]
  float v300; // [esp+0h] [ebp-24h]
  float tmp7; // [esp+4h] [ebp-20h]
  float tmp7a; // [esp+4h] [ebp-20h]
  float tmp7b; // [esp+4h] [ebp-20h]
  float tmp7c; // [esp+4h] [ebp-20h]
  float tmp7d; // [esp+4h] [ebp-20h]
  float tmp7e; // [esp+4h] [ebp-20h]
  float tmp7f; // [esp+4h] [ebp-20h]
  float tmp7g; // [esp+4h] [ebp-20h]
  float tmp7h; // [esp+4h] [ebp-20h]
  float tmp7i; // [esp+4h] [ebp-20h]
  float tmp7j; // [esp+4h] [ebp-20h]
  float tmp7k; // [esp+4h] [ebp-20h]
  float tmp7l; // [esp+4h] [ebp-20h]
  float tmp7m; // [esp+4h] [ebp-20h]
  float tmp7n; // [esp+4h] [ebp-20h]
  float tmp11; // [esp+8h] [ebp-1Ch]
  float tmp3; // [esp+Ch] [ebp-18h]
  float tmp3a; // [esp+Ch] [ebp-18h]
  float tmp3b; // [esp+Ch] [ebp-18h]
  float tmp3c; // [esp+Ch] [ebp-18h]
  float tmp3d; // [esp+Ch] [ebp-18h]
  float tmp3e; // [esp+Ch] [ebp-18h]
  float tmp3f; // [esp+Ch] [ebp-18h]
  float tmp3g; // [esp+Ch] [ebp-18h]
  float tmp3h; // [esp+Ch] [ebp-18h]
  float tmp3i; // [esp+Ch] [ebp-18h]
  float tmp3j; // [esp+Ch] [ebp-18h]
  float z4; // [esp+10h] [ebp-14h]
  float z4a; // [esp+10h] [ebp-14h]
  float z4b; // [esp+10h] [ebp-14h]
  float z4c; // [esp+10h] [ebp-14h]
  float z4d; // [esp+10h] [ebp-14h]
  float z4e; // [esp+10h] [ebp-14h]
  float z4f; // [esp+10h] [ebp-14h]
  float z4g; // [esp+10h] [ebp-14h]
  float z4h; // [esp+10h] [ebp-14h]
  float z4i; // [esp+10h] [ebp-14h]
  float z4j; // [esp+10h] [ebp-14h]
  float z4k; // [esp+10h] [ebp-14h]
  float z4l; // [esp+10h] [ebp-14h]
  float z4m; // [esp+10h] [ebp-14h]
  float z4n; // [esp+10h] [ebp-14h]
  float z2; // [esp+14h] [ebp-10h]
  float z2a; // [esp+14h] [ebp-10h]
  float z2b; // [esp+14h] [ebp-10h]
  float z2c; // [esp+14h] [ebp-10h]
  float z2d; // [esp+14h] [ebp-10h]
  float z2e; // [esp+14h] [ebp-10h]
  float z2f; // [esp+14h] [ebp-10h]
  float z2g; // [esp+14h] [ebp-10h]
  float z2h; // [esp+14h] [ebp-10h]
  float z2i; // [esp+14h] [ebp-10h]
  float z2j; // [esp+14h] [ebp-10h]
  float z2k; // [esp+14h] [ebp-10h]
  float z2l; // [esp+14h] [ebp-10h]
  float z2m; // [esp+14h] [ebp-10h]
  float z2n; // [esp+14h] [ebp-10h]
  float tmp4; // [esp+18h] [ebp-Ch]
  float tmp4a; // [esp+18h] [ebp-Ch]
  float tmp4b; // [esp+18h] [ebp-Ch]
  float tmp4c; // [esp+18h] [ebp-Ch]
  float tmp4d; // [esp+18h] [ebp-Ch]
  float tmp4e; // [esp+18h] [ebp-Ch]
  float tmp4f; // [esp+18h] [ebp-Ch]
  float tmp4g; // [esp+18h] [ebp-Ch]
  float tmp4h; // [esp+18h] [ebp-Ch]
  float tmp4i; // [esp+18h] [ebp-Ch]
  float tmp4j; // [esp+18h] [ebp-Ch]
  float tmp4k; // [esp+18h] [ebp-Ch]
  float tmp4l; // [esp+18h] [ebp-Ch]
  float tmp4m; // [esp+18h] [ebp-Ch]
  float tmp4n; // [esp+18h] [ebp-Ch]
  float tmp5; // [esp+1Ch] [ebp-8h]
  float tmp5a; // [esp+1Ch] [ebp-8h]
  float tmp5b; // [esp+1Ch] [ebp-8h]
  float tmp5c; // [esp+1Ch] [ebp-8h]
  float tmp5d; // [esp+1Ch] [ebp-8h]
  float tmp5e; // [esp+1Ch] [ebp-8h]
  float tmp5f; // [esp+1Ch] [ebp-8h]
  float tmp5g; // [esp+1Ch] [ebp-8h]
  float tmp5h; // [esp+1Ch] [ebp-8h]
  float tmp5i; // [esp+1Ch] [ebp-8h]
  float tmp5j; // [esp+1Ch] [ebp-8h]
  float tmp5k; // [esp+1Ch] [ebp-8h]
  float tmp5l; // [esp+1Ch] [ebp-8h]
  float tmp5m; // [esp+1Ch] [ebp-8h]
  float tmp5n; // [esp+1Ch] [ebp-8h]
  float tmp2; // [esp+20h] [ebp-4h]
  float tmp2a; // [esp+20h] [ebp-4h]
  float tmp2b; // [esp+20h] [ebp-4h]
  float tmp2c; // [esp+20h] [ebp-4h]
  float tmp2d; // [esp+20h] [ebp-4h]
  float tmp2e; // [esp+20h] [ebp-4h]
  float tmp2f; // [esp+20h] [ebp-4h]
  float tmp2g; // [esp+20h] [ebp-4h]
  float tmp2h; // [esp+20h] [ebp-4h]
  float tmp2i; // [esp+20h] [ebp-4h]
  float tmp2j; // [esp+20h] [ebp-4h]
  float tmp2k; // [esp+20h] [ebp-4h]
  float tmp2l; // [esp+20h] [ebp-4h]
  float tmp2m; // [esp+20h] [ebp-4h]
  float tmp2n; // [esp+20h] [ebp-4h]
  float tmp6; // [esp+2Ch] [ebp+8h]
  float tmp6a; // [esp+2Ch] [ebp+8h]
  float tmp6b; // [esp+2Ch] [ebp+8h]
  float tmp6c; // [esp+2Ch] [ebp+8h]
  float tmp6d; // [esp+2Ch] [ebp+8h]
  float tmp6e; // [esp+2Ch] [ebp+8h]
  float tmp6f; // [esp+2Ch] [ebp+8h]
  float tmp6g; // [esp+2Ch] [ebp+8h]
  float tmp6h; // [esp+2Ch] [ebp+8h]
  float tmp6i; // [esp+2Ch] [ebp+8h]
  float tmp6j; // [esp+2Ch] [ebp+8h]
  float tmp6k; // [esp+2Ch] [ebp+8h]
  float tmp6l; // [esp+2Ch] [ebp+8h]
  float tmp6m; // [esp+2Ch] [ebp+8h]
  float tmp6n; // [esp+2Ch] [ebp+8h]
  float tmp6o; // [esp+2Ch] [ebp+8h]

  v2 = *data;
  v3 = data[2];
  v4 = data[1];
  v5 = v4 - data[6];
  v6 = v4 + data[6];
  tmp6 = v5;
  v7 = data[3] + data[4];
  v8 = v2 + data[7];
  v9 = v2 - data[7];
  tmp4 = data[3] - data[4];
  v10 = v7 + v8;
  v11 = v3 + data[5];
  v12 = v3 - data[5];
  v13 = v8 - v7;
  *data = (float)(v11 + v6) + v10;
  data[4] = v10 - (float)(v11 + v6);
  v14 = (float)((float)(v6 - v11) + v13) * 0.70710677;
  data[6] = v13 - v14;
  v15 = (float)((float)(tmp4 + v12) - (float)(tmp6 + v9)) * 0.38268343;
  data[2] = v14 + v13;
  z2 = (float)((float)(tmp4 + v12) * 0.54119611) + v15;
  z4 = (float)((float)(tmp6 + v9) * 1.306563) + v15;
  v16 = (float)(v12 + tmp6) * 0.70710677;
  v17 = v16 + v9;
  v18 = v9 - v16;
  v19 = data[8];
  v20 = v18 + z2;
  data[3] = v18 - z2;
  v21 = v17 + z4;
  data[7] = v17 - z4;
  v22 = v19;
  v23 = v19 - data[15];
  v24 = v22 + data[15];
  data[1] = v21;
  v25 = data[9];
  tmp7 = v23;
  v26 = v25 + data[14];
  tmp6a = v25 - data[14];
  v27 = data[10];
  data[5] = v20;
  tmp2 = v27 + data[13];
  tmp5 = v27 - data[13];
  tmp11 = data[11];
  tmp3 = tmp11 + data[12];
  tmp4a = tmp11 - data[12];
  v28 = tmp3 + v24;
  v29 = v24 - tmp3;
  v30 = tmp2 + v26;
  v31 = (float)((float)(v26 - tmp2) + v29) * 0.70710677;
  data[12] = v28 - v30;
  data[10] = v31 + v29;
  data[14] = v29 - v31;
  data[8] = v30 + v28;
  v32 = (float)((float)(tmp4a + tmp5) - (float)(tmp6a + tmp7)) * 0.38268343;
  z4a = (float)((float)(tmp6a + tmp7) * 1.306563) + v32;
  z2a = (float)((float)(tmp4a + tmp5) * 0.54119611) + v32;
  v33 = (float)((float)(tmp5 + tmp6a) * 0.70710677) + tmp7;
  v34 = data[16];
  v35 = (float)(tmp7 - (float)((float)(tmp5 + tmp6a) * 0.70710677)) - z2a;
  data[13] = (float)(tmp7 - (float)((float)(tmp5 + tmp6a) * 0.70710677)) + z2a;
  data[9] = v33 + z4a;
  v36 = data[17];
  data[15] = v33 - z4a;
  v37 = v34 + data[23];
  tmp7a = v34 - data[23];
  v38 = v36 + data[22];
  tmp6b = v36 - data[22];
  v273 = data[18];
  tmp2a = v273 + data[21];
  tmp5a = v273 - data[21];
  v274 = data[19];
  v39 = v274 + data[20];
  data[11] = v35;
  tmp3a = v39;
  tmp4b = v274 - data[20];
  v40 = v39 + v37;
  v41 = v37 - tmp3a;
  v42 = tmp2a + v38;
  v43 = (float)((float)(v38 - tmp2a) + v41) * 0.70710677;
  data[20] = v40 - v42;
  data[18] = v43 + v41;
  data[22] = v41 - v43;
  data[16] = v42 + v40;
  v44 = (float)((float)(tmp4b + tmp5a) - (float)(tmp6b + tmp7a)) * 0.38268343;
  z4b = (float)((float)(tmp6b + tmp7a) * 1.306563) + v44;
  z2b = (float)((float)(tmp4b + tmp5a) * 0.54119611) + v44;
  v45 = (float)((float)(tmp5a + tmp6b) * 0.70710677) + tmp7a;
  v46 = data[24];
  data[21] = (float)(tmp7a - (float)((float)(tmp5a + tmp6b) * 0.70710677)) + z2b;
  v47 = (float)(tmp7a - (float)((float)(tmp5a + tmp6b) * 0.70710677)) - z2b;
  data[17] = v45 + z4b;
  v48 = data[25];
  data[23] = v45 - z4b;
  v49 = v46 + data[31];
  tmp7b = v46 - data[31];
  v50 = v48 + data[30];
  tmp6c = v48 - data[30];
  v275 = data[26];
  tmp2b = v275 + data[29];
  tmp5b = v275 - data[29];
  v276 = data[27];
  tmp3b = v276 + data[28];
  tmp4c = v276 - data[28];
  data[19] = v47;
  v51 = tmp3b + v49;
  v52 = v49 - tmp3b;
  v53 = (float)(tmp2b + v50) + v51;
  data[28] = v51 - (float)(tmp2b + v50);
  v54 = (float)((float)(v50 - tmp2b) + v52) * 0.70710677;
  data[26] = v54 + v52;
  data[30] = v52 - v54;
  data[24] = v53;
  v55 = (float)((float)(tmp4c + tmp5b) - (float)(tmp6c + tmp7b)) * 0.38268343;
  z4c = (float)((float)(tmp6c + tmp7b) * 1.306563) + v55;
  z2c = (float)((float)(tmp4c + tmp5b) * 0.54119611) + v55;
  v56 = (float)((float)(tmp5b + tmp6c) * 0.70710677) + tmp7b;
  v57 = data[32];
  data[29] = (float)(tmp7b - (float)((float)(tmp5b + tmp6c) * 0.70710677)) + z2c;
  data[25] = v56 + z4c;
  v58 = data[39];
  data[27] = (float)(tmp7b - (float)((float)(tmp5b + tmp6c) * 0.70710677)) - z2c;
  v59 = data[38];
  data[31] = v56 - z4c;
  v60 = v57;
  v61 = v57 - v58;
  v62 = v60 + v58;
  v63 = data[33];
  tmp7c = v61;
  tmp6d = v63 - v59;
  v277 = data[34];
  v64 = v63 + v59;
  v65 = data[37];
  tmp2c = v277 + v65;
  v66 = v277 - v65;
  v67 = data[36];
  tmp5c = v66;
  v278 = data[35];
  v68 = (float)(v278 + v67) + v62;
  v69 = v62 - (float)(v278 + v67);
  data[32] = (float)(tmp2c + v64) + v68;
  data[36] = v68 - (float)(tmp2c + v64);
  v70 = (float)((float)(v64 - tmp2c) + v69) * 0.70710677;
  data[34] = v70 + v69;
  data[38] = v69 - v70;
  v71 = (float)((float)((float)(v278 - v67) + tmp5c) - (float)(tmp6d + tmp7c)) * 0.38268343;
  z4d = (float)((float)(tmp6d + tmp7c) * 1.306563) + v71;
  z2d = (float)((float)((float)(v278 - v67) + tmp5c) * 0.54119611) + v71;
  v72 = (float)((float)(tmp5c + tmp6d) * 0.70710677) + tmp7c;
  v73 = tmp7c - (float)((float)(tmp5c + tmp6d) * 0.70710677);
  v74 = data[40];
  data[37] = v73 + z2d;
  data[33] = v72 + z4d;
  v75 = data[47];
  data[35] = v73 - z2d;
  v76 = data[46];
  data[39] = v72 - z4d;
  v77 = v74;
  v78 = v74 - v75;
  v79 = v77 + v75;
  v80 = data[41];
  tmp7d = v78;
  tmp6e = v80 - v76;
  v279 = data[42];
  v81 = v80 + v76;
  v82 = data[45];
  tmp2d = v279 + v82;
  v83 = v279 - v82;
  v84 = data[44];
  tmp5d = v83;
  v280 = data[43];
  tmp3c = v280 + v84;
  tmp4d = v280 - v84;
  v85 = tmp2d + v81;
  v86 = tmp3c + v79;
  v87 = v79 - tmp3c;
  data[44] = v86 - (float)(tmp2d + v81);
  v88 = (float)((float)(v81 - tmp2d) + v87) * 0.70710677;
  data[40] = v85 + v86;
  data[42] = v88 + v87;
  data[46] = v87 - v88;
  v89 = (float)((float)(tmp4d + tmp5d) - (float)(tmp6e + tmp7d)) * 0.38268343;
  z4e = (float)((float)(tmp6e + tmp7d) * 1.306563) + v89;
  z2e = (float)((float)(tmp4d + tmp5d) * 0.54119611) + v89;
  v90 = (float)((float)(tmp5d + tmp6e) * 0.70710677) + tmp7d;
  v91 = tmp7d - (float)((float)(tmp5d + tmp6e) * 0.70710677);
  v92 = data[48];
  data[45] = v91 + z2e;
  data[41] = v90 + z4e;
  v93 = data[55];
  data[47] = v90 - z4e;
  v94 = v92;
  v95 = v92 - v93;
  v96 = v94 + v93;
  v97 = data[49];
  data[43] = v91 - z2e;
  v98 = data[54];
  tmp7e = v95;
  tmp6f = v97 - v98;
  v281 = data[50];
  v99 = v97 + v98;
  v100 = data[53];
  tmp2e = v281 + v100;
  v101 = v281 - v100;
  v102 = data[52];
  tmp5e = v101;
  v282 = data[51];
  tmp4e = v282 - v102;
  v103 = (float)(v282 + v102) + v96;
  v104 = v96 - (float)(v282 + v102);
  v105 = (float)(tmp2e + v99) + v103;
  data[52] = v103 - (float)(tmp2e + v99);
  v106 = (float)((float)(v99 - tmp2e) + v104) * 0.70710677;
  data[54] = v104 - v106;
  data[48] = v105;
  data[50] = v106 + v104;
  v107 = (float)((float)(tmp4e + tmp5e) - (float)(tmp6f + tmp7e)) * 0.38268343;
  z4f = (float)((float)(tmp6f + tmp7e) * 1.306563) + v107;
  z2f = (float)((float)(tmp4e + tmp5e) * 0.54119611) + v107;
  v108 = (float)((float)(tmp5e + tmp6f) * 0.70710677) + tmp7e;
  v109 = data[56];
  v110 = (float)(tmp7e - (float)((float)(tmp5e + tmp6f) * 0.70710677)) - z2f;
  data[53] = (float)(tmp7e - (float)((float)(tmp5e + tmp6f) * 0.70710677)) + z2f;
  data[49] = v108 + z4f;
  v111 = data[63];
  data[55] = v108 - z4f;
  v112 = v109;
  v113 = v109 - v111;
  v114 = v112 + v111;
  v115 = data[57];
  tmp7f = v113;
  data[51] = v110;
  v116 = data[62];
  tmp6g = v115 - v116;
  v283 = data[58];
  v117 = v115 + v116;
  v118 = data[61];
  tmp2f = v283 + v118;
  v119 = v283 - v118;
  v120 = data[60];
  tmp5f = v119;
  v284 = data[59];
  tmp4f = v284 - v120;
  v121 = (float)(v284 + v120) + v114;
  v122 = v114 - (float)(v284 + v120);
  v123 = (float)(tmp2f + v117) + v121;
  data[60] = v121 - (float)(tmp2f + v117);
  v124 = (float)((float)(v117 - tmp2f) + v122) * 0.70710677;
  data[62] = v122 - v124;
  data[56] = v123;
  data[58] = v124 + v122;
  v125 = (float)((float)(tmp4f + tmp5f) - (float)(tmp6g + tmp7f)) * 0.38268343;
  z4g = (float)((float)(tmp6g + tmp7f) * 1.306563) + v125;
  z2g = (float)((float)(tmp4f + tmp5f) * 0.54119611) + v125;
  v126 = (float)((float)(tmp5f + tmp6g) * 0.70710677) + tmp7f;
  v127 = tmp7f - (float)((float)(tmp5f + tmp6g) * 0.70710677);
  data[61] = v127 + z2g;
  data[59] = v127 - z2g;
  data[57] = v126 + z4g;
  data[63] = v126 - z4g;
  v128 = data[56];
  v129 = data[48];
  v130 = *data - v128;
  v131 = *data + v128;
  v132 = data[8];
  tmp7g = v130;
  tmp6h = v132 - v129;
  v285 = data[16];
  v133 = v132 + v129;
  v134 = data[40];
  tmp2g = v285 + v134;
  v135 = v285 - v134;
  v136 = data[32];
  tmp5g = v135;
  v286 = data[24];
  tmp4g = v286 - v136;
  v137 = (float)(v286 + v136) + v131;
  v138 = v131 - (float)(v286 + v136);
  v139 = (float)(tmp2g + v133) + v137;
  data[32] = v137 - (float)(tmp2g + v133);
  v140 = (float)((float)(v133 - tmp2g) + v138) * 0.70710677;
  data[48] = v138 - v140;
  data[16] = v140 + v138;
  *data = v139;
  v141 = (float)((float)(tmp4g + tmp5g) - (float)(tmp6h + tmp7g)) * 0.38268343;
  z2h = (float)((float)(tmp4g + tmp5g) * 0.54119611) + v141;
  z4h = (float)((float)(tmp6h + tmp7g) * 1.306563) + v141;
  v142 = (float)((float)(tmp5g + tmp6h) * 0.70710677) + tmp7g;
  v143 = data[1];
  v144 = (float)(tmp7g - (float)((float)(tmp5g + tmp6h) * 0.70710677)) - z2h;
  data[40] = (float)(tmp7g - (float)((float)(tmp5g + tmp6h) * 0.70710677)) + z2h;
  data[8] = v142 + z4h;
  v145 = data[57];
  data[56] = v142 - z4h;
  v146 = v143;
  v147 = v143 - v145;
  v148 = v146 + v145;
  v149 = data[9];
  tmp7h = v147;
  data[24] = v144;
  v150 = data[49];
  tmp6i = v149 - v150;
  v151 = v149 + v150;
  v152 = data[41];
  v287 = data[17];
  tmp2h = v287 + v152;
  v153 = v287 - v152;
  v154 = data[33];
  tmp5h = v153;
  v288 = data[25];
  tmp3d = v288 + v154;
  v155 = v288 - v154;
  v156 = tmp2h + v151;
  tmp4h = v155;
  v157 = tmp3d + v148;
  v158 = v148 - tmp3d;
  v159 = (float)((float)(v151 - tmp2h) + v158) * 0.70710677;
  data[33] = v157 - v156;
  data[49] = v158 - v159;
  data[17] = v159 + v158;
  data[1] = v156 + v157;
  v160 = (float)((float)(tmp4h + tmp5h) - (float)(tmp6i + tmp7h)) * 0.38268343;
  z4i = (float)((float)(tmp6i + tmp7h) * 1.306563) + v160;
  z2i = (float)((float)(tmp4h + tmp5h) * 0.54119611) + v160;
  v161 = (float)((float)(tmp5h + tmp6i) * 0.70710677) + tmp7h;
  v162 = data[2];
  v163 = (float)(tmp7h - (float)((float)(tmp5h + tmp6i) * 0.70710677)) - z2i;
  data[41] = (float)(tmp7h - (float)((float)(tmp5h + tmp6i) * 0.70710677)) + z2i;
  data[9] = v161 + z4i;
  v164 = data[58];
  data[57] = v161 - z4i;
  v165 = v162;
  v166 = v162 - v164;
  v167 = v165 + v164;
  v168 = data[10];
  tmp7i = v166;
  data[25] = v163;
  v169 = data[50];
  tmp6j = v168 - v169;
  v170 = v168 + v169;
  v171 = data[42];
  v289 = data[18];
  tmp2i = v289 + v171;
  v172 = v289 - v171;
  v173 = data[34];
  tmp5i = v172;
  v290 = data[26];
  tmp3e = v290 + v173;
  v174 = v290 - v173;
  v175 = tmp2i + v170;
  tmp4i = v174;
  v176 = tmp3e + v167;
  v177 = v167 - tmp3e;
  v178 = (float)((float)(v170 - tmp2i) + v177) * 0.70710677;
  data[34] = v176 - v175;
  data[50] = v177 - v178;
  data[18] = v178 + v177;
  data[2] = v175 + v176;
  v179 = (float)((float)(tmp4i + tmp5i) - (float)(tmp6j + tmp7i)) * 0.38268343;
  z4j = (float)((float)(tmp6j + tmp7i) * 1.306563) + v179;
  z2j = (float)((float)(tmp4i + tmp5i) * 0.54119611) + v179;
  v180 = (float)((float)(tmp5i + tmp6j) * 0.70710677) + tmp7i;
  v181 = (float)(tmp7i - (float)((float)(tmp5i + tmp6j) * 0.70710677)) - z2j;
  v182 = data[3];
  data[42] = (float)(tmp7i - (float)((float)(tmp5i + tmp6j) * 0.70710677)) + z2j;
  data[10] = v180 + z4j;
  v183 = data[59];
  data[58] = v180 - z4j;
  v184 = v182;
  v185 = v182 - v183;
  v186 = v184 + v183;
  v187 = data[11];
  tmp7j = v185;
  data[26] = v181;
  v188 = data[51];
  tmp6k = v187 - v188;
  v291 = data[19];
  v189 = v187 + v188;
  v190 = data[43];
  tmp2j = v291 + v190;
  v191 = v291 - v190;
  v192 = data[35];
  tmp5j = v191;
  v292 = data[27];
  tmp3f = v292 + v192;
  v193 = v292 - v192;
  v194 = tmp2j + v189;
  tmp4j = v193;
  v195 = tmp3f + v186;
  v196 = v186 - tmp3f;
  v197 = (float)((float)(v189 - tmp2j) + v196) * 0.70710677;
  data[35] = v195 - v194;
  data[51] = v196 - v197;
  data[19] = v197 + v196;
  data[3] = v194 + v195;
  v198 = (float)((float)(tmp4j + tmp5j) - (float)(tmp6k + tmp7j)) * 0.38268343;
  z4k = (float)((float)(tmp6k + tmp7j) * 1.306563) + v198;
  z2k = (float)((float)(tmp4j + tmp5j) * 0.54119611) + v198;
  v199 = (float)((float)(tmp5j + tmp6k) * 0.70710677) + tmp7j;
  data[43] = (float)(tmp7j - (float)((float)(tmp5j + tmp6k) * 0.70710677)) + z2k;
  data[27] = (float)(tmp7j - (float)((float)(tmp5j + tmp6k) * 0.70710677)) - z2k;
  v200 = data[4];
  v201 = data[52];
  data[11] = v199 + z4k;
  v202 = data[60];
  data[59] = v199 - z4k;
  v203 = v200;
  v204 = v200 - v202;
  v205 = v203 + v202;
  v206 = data[12];
  tmp7k = v204;
  tmp6l = v206 - v201;
  v293 = data[20];
  v207 = v206 + v201;
  v208 = data[44];
  tmp2k = v293 + v208;
  v209 = v293 - v208;
  v210 = data[36];
  tmp5k = v209;
  v294 = data[28];
  tmp3g = v294 + v210;
  v211 = v294 - v210;
  v212 = tmp2k + v207;
  tmp4k = v211;
  v213 = tmp3g + v205;
  v214 = v205 - tmp3g;
  v215 = (float)((float)(v207 - tmp2k) + v214) * 0.70710677;
  data[36] = v213 - v212;
  data[52] = v214 - v215;
  data[20] = v215 + v214;
  data[4] = v212 + v213;
  v216 = (float)((float)(tmp4k + tmp5k) - (float)(tmp6l + tmp7k)) * 0.38268343;
  z4l = (float)((float)(tmp6l + tmp7k) * 1.306563) + v216;
  z2l = (float)((float)(tmp4k + tmp5k) * 0.54119611) + v216;
  v217 = (float)((float)(tmp5k + tmp6l) * 0.70710677) + tmp7k;
  v218 = data[5];
  data[44] = (float)(tmp7k - (float)((float)(tmp5k + tmp6l) * 0.70710677)) + z2l;
  data[12] = v217 + z4l;
  v219 = data[61];
  data[28] = (float)(tmp7k - (float)((float)(tmp5k + tmp6l) * 0.70710677)) - z2l;
  data[60] = v217 - z4l;
  v220 = data[53];
  v221 = v218;
  v222 = v218 - v219;
  v223 = v221 + v219;
  v224 = data[13];
  tmp7l = v222;
  tmp6m = v224 - v220;
  v225 = v224 + v220;
  v226 = data[45];
  v295 = data[21];
  tmp2l = v295 + v226;
  v227 = v295 - v226;
  v228 = data[37];
  tmp5l = v227;
  v296 = data[29];
  tmp3h = v296 + v228;
  v229 = v296 - v228;
  v230 = tmp2l + v225;
  tmp4l = v229;
  v231 = tmp3h + v223;
  v232 = v223 - tmp3h;
  v233 = (float)((float)(v225 - tmp2l) + v232) * 0.70710677;
  data[37] = v231 - v230;
  data[53] = v232 - v233;
  data[21] = v233 + v232;
  data[5] = v230 + v231;
  v234 = (float)((float)(tmp4l + tmp5l) - (float)(tmp6m + tmp7l)) * 0.38268343;
  z4m = (float)((float)(tmp6m + tmp7l) * 1.306563) + v234;
  z2m = (float)((float)(tmp4l + tmp5l) * 0.54119611) + v234;
  v235 = (float)((float)(tmp5l + tmp6m) * 0.70710677) + tmp7l;
  v236 = data[6];
  data[45] = (float)(tmp7l - (float)((float)(tmp5l + tmp6m) * 0.70710677)) + z2m;
  data[61] = v235 - z4m;
  data[13] = v235 + z4m;
  v237 = data[62];
  data[29] = (float)(tmp7l - (float)((float)(tmp5l + tmp6m) * 0.70710677)) - z2m;
  v238 = data[54];
  v239 = v236 + v237;
  tmp7m = v236 - v237;
  v240 = data[14];
  tmp6n = v240 - v238;
  v241 = v240 + v238;
  v242 = data[46];
  v297 = data[22];
  tmp2m = v297 + v242;
  v243 = v297 - v242;
  v244 = data[38];
  tmp5m = v243;
  v298 = data[30];
  tmp3i = v298 + v244;
  v245 = v298 - v244;
  v246 = tmp2m + v241;
  tmp4m = v245;
  v247 = tmp3i + v239;
  v248 = v239 - tmp3i;
  v249 = (float)((float)(v241 - tmp2m) + v248) * 0.70710677;
  data[38] = v247 - v246;
  data[54] = v248 - v249;
  data[22] = v249 + v248;
  data[6] = v246 + v247;
  v250 = (float)((float)(tmp4m + tmp5m) - (float)(tmp6n + tmp7m)) * 0.38268343;
  z4n = (float)((float)(tmp6n + tmp7m) * 1.306563) + v250;
  z2n = (float)((float)(tmp4m + tmp5m) * 0.54119611) + v250;
  v251 = (float)((float)(tmp5m + tmp6n) * 0.70710677) + tmp7m;
  v252 = data[7];
  v253 = (float)(tmp7m - (float)((float)(tmp5m + tmp6n) * 0.70710677)) - z2n;
  data[46] = (float)(tmp7m - (float)((float)(tmp5m + tmp6n) * 0.70710677)) + z2n;
  data[14] = v251 + z4n;
  v254 = data[63];
  data[62] = v251 - z4n;
  v255 = v252;
  v256 = v252 - v254;
  v257 = v255 + v254;
  v258 = data[15];
  tmp7n = v256;
  data[30] = v253;
  v259 = data[55];
  v260 = v258 + v259;
  tmp6o = v258 - v259;
  v261 = data[47];
  v299 = data[23];
  tmp2n = v299 + v261;
  v262 = v299 - v261;
  v263 = data[39];
  tmp5n = v262;
  v300 = data[31];
  tmp3j = v300 + v263;
  v264 = v300 - v263;
  v265 = tmp2n + v260;
  tmp4n = v264;
  v266 = tmp3j + v257;
  v267 = v257 - tmp3j;
  v268 = (float)((float)(v260 - tmp2n) + v267) * 0.70710677;
  data[39] = v266 - v265;
  data[55] = v267 - v268;
  data[7] = v265 + v266;
  data[23] = v268 + v267;
  v269 = (float)((float)(tmp4n + tmp5n) - (float)(tmp6o + tmp7n)) * 0.38268343;
  v270 = (float)(tmp5n + tmp6o) * 0.70710677;
  v271 = (float)((float)(tmp4n + tmp5n) * 0.54119611) + v269;
  data[47] = (float)(tmp7n - v270) + v271;
  v272 = (float)((float)(tmp6o + tmp7n) * 1.306563) + v269;
  data[31] = (float)(tmp7n - v270) - v271;
  data[15] = (float)(v270 + tmp7n) + v272;
  data[63] = (float)(v270 + tmp7n) - v272;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102592E0
// Name: _jpeg_fdct_float
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_fdct_float(float *data)
{
  float v2; // xmm6_4
  float v3; // xmm5_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm6_4
  float v10; // xmm2_4
  float v11; // xmm7_4
  float v12; // xmm5_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm7_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm4_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm5_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm4_4
  float v27; // xmm6_4
  float v28; // xmm6_4
  float v29; // xmm5_4
  float v30; // xmm7_4
  float v31; // xmm4_4
  float v32; // xmm6_4
  float v33; // xmm5_4
  float v34; // xmm4_4
  float v35; // xmm7_4
  float v36; // xmm6_4
  float v37; // xmm5_4
  float v38; // xmm4_4
  float v39; // xmm6_4
  float v40; // xmm6_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm4_4
  float v44; // xmm6_4
  float v45; // xmm5_4
  float v46; // xmm4_4
  float v47; // xmm7_4
  float v48; // xmm6_4
  float v49; // xmm5_4
  float v50; // xmm4_4
  float v51; // xmm6_4
  float v52; // xmm5_4
  float v53; // xmm7_4
  float v54; // xmm4_4
  float v55; // xmm6_4
  float v56; // xmm5_4
  float v57; // xmm4_4
  float v58; // xmm6_4
  float v59; // xmm7_4
  float v60; // xmm5_4
  float v61; // xmm4_4
  float v62; // xmm5_4
  float v63; // xmm6_4
  float v64; // xmm4_4
  float v65; // xmm7_4
  float v66; // xmm6_4
  float v67; // xmm7_4
  float v68; // xmm6_4
  float v69; // xmm5_4
  float v70; // xmm4_4
  float v71; // xmm6_4
  float v72; // xmm5_4
  float v73; // xmm7_4
  float v74; // xmm4_4
  float v75; // xmm6_4
  float v76; // xmm7_4
  float v77; // xmm5_4
  float v78; // xmm4_4
  float v79; // xmm5_4
  float v80; // xmm6_4
  float v81; // xmm4_4
  float v82; // xmm7_4
  float v83; // xmm6_4
  float v84; // xmm7_4
  float v85; // xmm7_4
  float v86; // xmm6_4
  float v87; // xmm5_4
  float v88; // xmm4_4
  float v89; // xmm6_4
  float v90; // xmm5_4
  float v91; // xmm7_4
  float v92; // xmm4_4
  float v93; // xmm6_4
  float v94; // xmm5_4
  float v95; // xmm4_4
  float v96; // xmm5_4
  float v97; // xmm6_4
  float v98; // xmm7_4
  float v99; // xmm4_4
  float v100; // xmm7_4
  float v101; // xmm6_4
  float v102; // xmm7_4
  float v103; // xmm6_4
  float v104; // xmm5_4
  float v105; // xmm7_4
  float v106; // xmm4_4
  float v107; // xmm6_4
  float v108; // xmm5_4
  float v109; // xmm4_4
  float v110; // xmm7_4
  float v111; // xmm6_4
  float v112; // xmm5_4
  float v113; // xmm4_4
  float v114; // xmm5_4
  float v115; // xmm6_4
  float v116; // xmm7_4
  float v117; // xmm4_4
  float v118; // xmm7_4
  float v119; // xmm6_4
  float v120; // xmm7_4
  float v121; // xmm6_4
  float v122; // xmm5_4
  float v123; // xmm7_4
  float v124; // xmm4_4
  float v125; // xmm6_4
  float v126; // xmm5_4
  float v127; // xmm7_4
  float v128; // xmm6_4
  float v129; // xmm7_4
  float v130; // xmm4_4
  float v131; // xmm5_4
  float v132; // xmm6_4
  float v133; // xmm4_4
  float v134; // xmm7_4
  float v135; // xmm6_4
  float v136; // xmm7_4
  float v137; // xmm6_4
  float v138; // xmm5_4
  float v139; // xmm7_4
  float v140; // xmm4_4
  float v141; // xmm6_4
  float v142; // xmm5_4
  float v143; // xmm4_4
  float v144; // xmm7_4
  float v145; // xmm6_4
  float v146; // xmm5_4
  float v147; // xmm4_4
  float v148; // xmm5_4
  float v149; // xmm6_4
  float v150; // xmm7_4
  float v151; // xmm4_4
  float v152; // xmm7_4
  float v153; // xmm6_4
  float v154; // xmm7_4
  float v155; // xmm6_4
  float v156; // xmm7_4
  float v157; // xmm6_4
  float v158; // xmm5_4
  float v159; // xmm4_4
  float v160; // xmm6_4
  float v161; // xmm5_4
  float v162; // xmm4_4
  float v163; // xmm7_4
  float v164; // xmm6_4
  float v165; // xmm5_4
  float v166; // xmm4_4
  float v167; // xmm5_4
  float v168; // xmm6_4
  float v169; // xmm7_4
  float v170; // xmm4_4
  float v171; // xmm7_4
  float v172; // xmm6_4
  float v173; // xmm7_4
  float v174; // xmm6_4
  float v175; // xmm7_4
  float v176; // xmm6_4
  float v177; // xmm5_4
  float v178; // xmm4_4
  float v179; // xmm6_4
  float v180; // xmm5_4
  float v181; // xmm7_4
  float v182; // xmm4_4
  float v183; // xmm6_4
  float v184; // xmm5_4
  float v185; // xmm4_4
  float v186; // xmm5_4
  float v187; // xmm6_4
  float v188; // xmm7_4
  float v189; // xmm4_4
  float v190; // xmm7_4
  float v191; // xmm6_4
  float v192; // xmm7_4
  float v193; // xmm6_4
  float v194; // xmm7_4
  float v195; // xmm6_4
  float v196; // xmm5_4
  float v197; // xmm4_4
  float v198; // xmm6_4
  float v199; // xmm5_4
  float v200; // xmm4_4
  float v201; // xmm7_4
  float v202; // xmm6_4
  float v203; // xmm5_4
  float v204; // xmm4_4
  float v205; // xmm5_4
  float v206; // xmm6_4
  float v207; // xmm4_4
  float v208; // xmm7_4
  float v209; // xmm6_4
  float v210; // xmm7_4
  float v211; // xmm6_4
  float v212; // xmm7_4
  float v213; // xmm6_4
  float v214; // xmm5_4
  float v215; // xmm4_4
  float v216; // xmm6_4
  float v217; // xmm5_4
  float v218; // xmm4_4
  float v219; // xmm6_4
  float v220; // xmm7_4
  float v221; // xmm5_4
  float v222; // xmm4_4
  float v223; // xmm5_4
  float v224; // xmm6_4
  float v225; // xmm4_4
  float v226; // xmm7_4
  float v227; // xmm6_4
  float v228; // xmm7_4
  float v229; // xmm6_4
  float v230; // xmm7_4
  float v231; // xmm6_4
  float v232; // xmm5_4
  float v233; // xmm4_4
  float v234; // xmm6_4
  float v235; // xmm5_4
  float v236; // xmm4_4
  float v237; // xmm6_4
  float v238; // xmm7_4
  float v239; // xmm5_4
  float v240; // xmm4_4
  float v241; // xmm4_4
  float v242; // xmm7_4
  float v243; // xmm6_4
  float v244; // xmm7_4
  float v245; // xmm6_4
  float v246; // xmm7_4
  float v247; // xmm6_4
  float v248; // xmm5_4
  float v249; // xmm4_4
  float v250; // xmm6_4
  float v251; // xmm5_4
  float v252; // xmm4_4
  float v253; // xmm7_4
  float v254; // xmm6_4
  float v255; // xmm5_4
  float v256; // xmm4_4
  float v257; // xmm5_4
  float v258; // xmm6_4
  float v259; // xmm7_4
  float v260; // xmm4_4
  float v261; // xmm7_4
  float v262; // xmm6_4
  float v263; // xmm7_4
  float v264; // xmm6_4
  float v265; // xmm7_4
  float v266; // xmm6_4
  float v267; // xmm5_4
  float v268; // xmm4_4
  float v269; // xmm6_4
  float v270; // xmm1_4
  float v271; // xmm5_4
  float v272; // xmm4_4
  float v273; // [esp+0h] [ebp-24h]
  float v274; // [esp+0h] [ebp-24h]
  float v275; // [esp+0h] [ebp-24h]
  float v276; // [esp+0h] [ebp-24h]
  float v277; // [esp+0h] [ebp-24h]
  float v278; // [esp+0h] [ebp-24h]
  float v279; // [esp+0h] [ebp-24h]
  float v280; // [esp+0h] [ebp-24h]
  float v281; // [esp+0h] [ebp-24h]
  float v282; // [esp+0h] [ebp-24h]
  float v283; // [esp+0h] [ebp-24h]
  float v284; // [esp+0h] [ebp-24h]
  float v285; // [esp+0h] [ebp-24h]
  float v286; // [esp+0h] [ebp-24h]
  float v287; // [esp+0h] [ebp-24h]
  float v288; // [esp+0h] [ebp-24h]
  float v289; // [esp+0h] [ebp-24h]
  float v290; // [esp+0h] [ebp-24h]
  float v291; // [esp+0h] [ebp-24h]
  float v292; // [esp+0h] [ebp-24h]
  float v293; // [esp+0h] [ebp-24h]
  float v294; // [esp+0h] [ebp-24h]
  float v295; // [esp+0h] [ebp-24h]
  float v296; // [esp+0h] [ebp-24h]
  float v297; // [esp+0h] [ebp-24h]
  float v298; // [esp+0h] [ebp-24h]
  float v299; // [esp+0h] [ebp-24h]
  float v300; // [esp+0h] [ebp-24h]
  float tmp7; // [esp+4h] [ebp-20h]
  float tmp7a; // [esp+4h] [ebp-20h]
  float tmp7b; // [esp+4h] [ebp-20h]
  float tmp7c; // [esp+4h] [ebp-20h]
  float tmp7d; // [esp+4h] [ebp-20h]
  float tmp7e; // [esp+4h] [ebp-20h]
  float tmp7f; // [esp+4h] [ebp-20h]
  float tmp7g; // [esp+4h] [ebp-20h]
  float tmp7h; // [esp+4h] [ebp-20h]
  float tmp7i; // [esp+4h] [ebp-20h]
  float tmp7j; // [esp+4h] [ebp-20h]
  float tmp7k; // [esp+4h] [ebp-20h]
  float tmp7l; // [esp+4h] [ebp-20h]
  float tmp7m; // [esp+4h] [ebp-20h]
  float tmp7n; // [esp+4h] [ebp-20h]
  float tmp11; // [esp+8h] [ebp-1Ch]
  float tmp3; // [esp+Ch] [ebp-18h]
  float tmp3a; // [esp+Ch] [ebp-18h]
  float tmp3b; // [esp+Ch] [ebp-18h]
  float tmp3c; // [esp+Ch] [ebp-18h]
  float tmp3d; // [esp+Ch] [ebp-18h]
  float tmp3e; // [esp+Ch] [ebp-18h]
  float tmp3f; // [esp+Ch] [ebp-18h]
  float tmp3g; // [esp+Ch] [ebp-18h]
  float tmp3h; // [esp+Ch] [ebp-18h]
  float tmp3i; // [esp+Ch] [ebp-18h]
  float tmp3j; // [esp+Ch] [ebp-18h]
  float z4; // [esp+10h] [ebp-14h]
  float z4a; // [esp+10h] [ebp-14h]
  float z4b; // [esp+10h] [ebp-14h]
  float z4c; // [esp+10h] [ebp-14h]
  float z4d; // [esp+10h] [ebp-14h]
  float z4e; // [esp+10h] [ebp-14h]
  float z4f; // [esp+10h] [ebp-14h]
  float z4g; // [esp+10h] [ebp-14h]
  float z4h; // [esp+10h] [ebp-14h]
  float z4i; // [esp+10h] [ebp-14h]
  float z4j; // [esp+10h] [ebp-14h]
  float z4k; // [esp+10h] [ebp-14h]
  float z4l; // [esp+10h] [ebp-14h]
  float z4m; // [esp+10h] [ebp-14h]
  float z4n; // [esp+10h] [ebp-14h]
  float z2; // [esp+14h] [ebp-10h]
  float z2a; // [esp+14h] [ebp-10h]
  float z2b; // [esp+14h] [ebp-10h]
  float z2c; // [esp+14h] [ebp-10h]
  float z2d; // [esp+14h] [ebp-10h]
  float z2e; // [esp+14h] [ebp-10h]
  float z2f; // [esp+14h] [ebp-10h]
  float z2g; // [esp+14h] [ebp-10h]
  float z2h; // [esp+14h] [ebp-10h]
  float z2i; // [esp+14h] [ebp-10h]
  float z2j; // [esp+14h] [ebp-10h]
  float z2k; // [esp+14h] [ebp-10h]
  float z2l; // [esp+14h] [ebp-10h]
  float z2m; // [esp+14h] [ebp-10h]
  float z2n; // [esp+14h] [ebp-10h]
  float tmp4; // [esp+18h] [ebp-Ch]
  float tmp4a; // [esp+18h] [ebp-Ch]
  float tmp4b; // [esp+18h] [ebp-Ch]
  float tmp4c; // [esp+18h] [ebp-Ch]
  float tmp4d; // [esp+18h] [ebp-Ch]
  float tmp4e; // [esp+18h] [ebp-Ch]
  float tmp4f; // [esp+18h] [ebp-Ch]
  float tmp4g; // [esp+18h] [ebp-Ch]
  float tmp4h; // [esp+18h] [ebp-Ch]
  float tmp4i; // [esp+18h] [ebp-Ch]
  float tmp4j; // [esp+18h] [ebp-Ch]
  float tmp4k; // [esp+18h] [ebp-Ch]
  float tmp4l; // [esp+18h] [ebp-Ch]
  float tmp4m; // [esp+18h] [ebp-Ch]
  float tmp4n; // [esp+18h] [ebp-Ch]
  float tmp5; // [esp+1Ch] [ebp-8h]
  float tmp5a; // [esp+1Ch] [ebp-8h]
  float tmp5b; // [esp+1Ch] [ebp-8h]
  float tmp5c; // [esp+1Ch] [ebp-8h]
  float tmp5d; // [esp+1Ch] [ebp-8h]
  float tmp5e; // [esp+1Ch] [ebp-8h]
  float tmp5f; // [esp+1Ch] [ebp-8h]
  float tmp5g; // [esp+1Ch] [ebp-8h]
  float tmp5h; // [esp+1Ch] [ebp-8h]
  float tmp5i; // [esp+1Ch] [ebp-8h]
  float tmp5j; // [esp+1Ch] [ebp-8h]
  float tmp5k; // [esp+1Ch] [ebp-8h]
  float tmp5l; // [esp+1Ch] [ebp-8h]
  float tmp5m; // [esp+1Ch] [ebp-8h]
  float tmp5n; // [esp+1Ch] [ebp-8h]
  float tmp2; // [esp+20h] [ebp-4h]
  float tmp2a; // [esp+20h] [ebp-4h]
  float tmp2b; // [esp+20h] [ebp-4h]
  float tmp2c; // [esp+20h] [ebp-4h]
  float tmp2d; // [esp+20h] [ebp-4h]
  float tmp2e; // [esp+20h] [ebp-4h]
  float tmp2f; // [esp+20h] [ebp-4h]
  float tmp2g; // [esp+20h] [ebp-4h]
  float tmp2h; // [esp+20h] [ebp-4h]
  float tmp2i; // [esp+20h] [ebp-4h]
  float tmp2j; // [esp+20h] [ebp-4h]
  float tmp2k; // [esp+20h] [ebp-4h]
  float tmp2l; // [esp+20h] [ebp-4h]
  float tmp2m; // [esp+20h] [ebp-4h]
  float tmp2n; // [esp+20h] [ebp-4h]
  float tmp6; // [esp+2Ch] [ebp+8h]
  float tmp6a; // [esp+2Ch] [ebp+8h]
  float tmp6b; // [esp+2Ch] [ebp+8h]
  float tmp6c; // [esp+2Ch] [ebp+8h]
  float tmp6d; // [esp+2Ch] [ebp+8h]
  float tmp6e; // [esp+2Ch] [ebp+8h]
  float tmp6f; // [esp+2Ch] [ebp+8h]
  float tmp6g; // [esp+2Ch] [ebp+8h]
  float tmp6h; // [esp+2Ch] [ebp+8h]
  float tmp6i; // [esp+2Ch] [ebp+8h]
  float tmp6j; // [esp+2Ch] [ebp+8h]
  float tmp6k; // [esp+2Ch] [ebp+8h]
  float tmp6l; // [esp+2Ch] [ebp+8h]
  float tmp6m; // [esp+2Ch] [ebp+8h]
  float tmp6n; // [esp+2Ch] [ebp+8h]
  float tmp6o; // [esp+2Ch] [ebp+8h]

  v2 = *data;
  v3 = data[2];
  v4 = data[1];
  v5 = v4 - data[6];
  v6 = v4 + data[6];
  tmp6 = v5;
  v7 = data[3] + data[4];
  v8 = v2 + data[7];
  v9 = v2 - data[7];
  tmp4 = data[3] - data[4];
  v10 = v7 + v8;
  v11 = v3 + data[5];
  v12 = v3 - data[5];
  v13 = v8 - v7;
  *data = (float)(v11 + v6) + v10;
  data[4] = v10 - (float)(v11 + v6);
  v14 = (float)((float)(v6 - v11) + v13) * 0.70710677;
  data[6] = v13 - v14;
  v15 = (float)((float)(tmp4 + v12) - (float)(tmp6 + v9)) * 0.38268343;
  data[2] = v14 + v13;
  z2 = (float)((float)(tmp4 + v12) * 0.54119611) + v15;
  z4 = (float)((float)(tmp6 + v9) * 1.306563) + v15;
  v16 = (float)(v12 + tmp6) * 0.70710677;
  v17 = v16 + v9;
  v18 = v9 - v16;
  v19 = data[8];
  v20 = v18 + z2;
  data[3] = v18 - z2;
  v21 = v17 + z4;
  data[7] = v17 - z4;
  v22 = v19;
  v23 = v19 - data[15];
  v24 = v22 + data[15];
  data[1] = v21;
  v25 = data[9];
  tmp7 = v23;
  v26 = v25 + data[14];
  tmp6a = v25 - data[14];
  v27 = data[10];
  data[5] = v20;
  tmp2 = v27 + data[13];
  tmp5 = v27 - data[13];
  tmp11 = data[11];
  tmp3 = tmp11 + data[12];
  tmp4a = tmp11 - data[12];
  v28 = tmp3 + v24;
  v29 = v24 - tmp3;
  v30 = tmp2 + v26;
  v31 = (float)((float)(v26 - tmp2) + v29) * 0.70710677;
  data[12] = v28 - v30;
  data[10] = v31 + v29;
  data[14] = v29 - v31;
  data[8] = v30 + v28;
  v32 = (float)((float)(tmp4a + tmp5) - (float)(tmp6a + tmp7)) * 0.38268343;
  z4a = (float)((float)(tmp6a + tmp7) * 1.306563) + v32;
  z2a = (float)((float)(tmp4a + tmp5) * 0.54119611) + v32;
  v33 = (float)((float)(tmp5 + tmp6a) * 0.70710677) + tmp7;
  v34 = data[16];
  v35 = (float)(tmp7 - (float)((float)(tmp5 + tmp6a) * 0.70710677)) - z2a;
  data[13] = (float)(tmp7 - (float)((float)(tmp5 + tmp6a) * 0.70710677)) + z2a;
  data[9] = v33 + z4a;
  v36 = data[17];
  data[15] = v33 - z4a;
  v37 = v34 + data[23];
  tmp7a = v34 - data[23];
  v38 = v36 + data[22];
  tmp6b = v36 - data[22];
  v273 = data[18];
  tmp2a = v273 + data[21];
  tmp5a = v273 - data[21];
  v274 = data[19];
  v39 = v274 + data[20];
  data[11] = v35;
  tmp3a = v39;
  tmp4b = v274 - data[20];
  v40 = v39 + v37;
  v41 = v37 - tmp3a;
  v42 = tmp2a + v38;
  v43 = (float)((float)(v38 - tmp2a) + v41) * 0.70710677;
  data[20] = v40 - v42;
  data[18] = v43 + v41;
  data[22] = v41 - v43;
  data[16] = v42 + v40;
  v44 = (float)((float)(tmp4b + tmp5a) - (float)(tmp6b + tmp7a)) * 0.38268343;
  z4b = (float)((float)(tmp6b + tmp7a) * 1.306563) + v44;
  z2b = (float)((float)(tmp4b + tmp5a) * 0.54119611) + v44;
  v45 = (float)((float)(tmp5a + tmp6b) * 0.70710677) + tmp7a;
  v46 = data[24];
  data[21] = (float)(tmp7a - (float)((float)(tmp5a + tmp6b) * 0.70710677)) + z2b;
  v47 = (float)(tmp7a - (float)((float)(tmp5a + tmp6b) * 0.70710677)) - z2b;
  data[17] = v45 + z4b;
  v48 = data[25];
  data[23] = v45 - z4b;
  v49 = v46 + data[31];
  tmp7b = v46 - data[31];
  v50 = v48 + data[30];
  tmp6c = v48 - data[30];
  v275 = data[26];
  tmp2b = v275 + data[29];
  tmp5b = v275 - data[29];
  v276 = data[27];
  tmp3b = v276 + data[28];
  tmp4c = v276 - data[28];
  data[19] = v47;
  v51 = tmp3b + v49;
  v52 = v49 - tmp3b;
  v53 = (float)(tmp2b + v50) + v51;
  data[28] = v51 - (float)(tmp2b + v50);
  v54 = (float)((float)(v50 - tmp2b) + v52) * 0.70710677;
  data[26] = v54 + v52;
  data[30] = v52 - v54;
  data[24] = v53;
  v55 = (float)((float)(tmp4c + tmp5b) - (float)(tmp6c + tmp7b)) * 0.38268343;
  z4c = (float)((float)(tmp6c + tmp7b) * 1.306563) + v55;
  z2c = (float)((float)(tmp4c + tmp5b) * 0.54119611) + v55;
  v56 = (float)((float)(tmp5b + tmp6c) * 0.70710677) + tmp7b;
  v57 = data[32];
  data[29] = (float)(tmp7b - (float)((float)(tmp5b + tmp6c) * 0.70710677)) + z2c;
  data[25] = v56 + z4c;
  v58 = data[39];
  data[27] = (float)(tmp7b - (float)((float)(tmp5b + tmp6c) * 0.70710677)) - z2c;
  v59 = data[38];
  data[31] = v56 - z4c;
  v60 = v57;
  v61 = v57 - v58;
  v62 = v60 + v58;
  v63 = data[33];
  tmp7c = v61;
  tmp6d = v63 - v59;
  v277 = data[34];
  v64 = v63 + v59;
  v65 = data[37];
  tmp2c = v277 + v65;
  v66 = v277 - v65;
  v67 = data[36];
  tmp5c = v66;
  v278 = data[35];
  v68 = (float)(v278 + v67) + v62;
  v69 = v62 - (float)(v278 + v67);
  data[32] = (float)(tmp2c + v64) + v68;
  data[36] = v68 - (float)(tmp2c + v64);
  v70 = (float)((float)(v64 - tmp2c) + v69) * 0.70710677;
  data[34] = v70 + v69;
  data[38] = v69 - v70;
  v71 = (float)((float)((float)(v278 - v67) + tmp5c) - (float)(tmp6d + tmp7c)) * 0.38268343;
  z4d = (float)((float)(tmp6d + tmp7c) * 1.306563) + v71;
  z2d = (float)((float)((float)(v278 - v67) + tmp5c) * 0.54119611) + v71;
  v72 = (float)((float)(tmp5c + tmp6d) * 0.70710677) + tmp7c;
  v73 = tmp7c - (float)((float)(tmp5c + tmp6d) * 0.70710677);
  v74 = data[40];
  data[37] = v73 + z2d;
  data[33] = v72 + z4d;
  v75 = data[47];
  data[35] = v73 - z2d;
  v76 = data[46];
  data[39] = v72 - z4d;
  v77 = v74;
  v78 = v74 - v75;
  v79 = v77 + v75;
  v80 = data[41];
  tmp7d = v78;
  tmp6e = v80 - v76;
  v279 = data[42];
  v81 = v80 + v76;
  v82 = data[45];
  tmp2d = v279 + v82;
  v83 = v279 - v82;
  v84 = data[44];
  tmp5d = v83;
  v280 = data[43];
  tmp3c = v280 + v84;
  tmp4d = v280 - v84;
  v85 = tmp2d + v81;
  v86 = tmp3c + v79;
  v87 = v79 - tmp3c;
  data[44] = v86 - (float)(tmp2d + v81);
  v88 = (float)((float)(v81 - tmp2d) + v87) * 0.70710677;
  data[40] = v85 + v86;
  data[42] = v88 + v87;
  data[46] = v87 - v88;
  v89 = (float)((float)(tmp4d + tmp5d) - (float)(tmp6e + tmp7d)) * 0.38268343;
  z4e = (float)((float)(tmp6e + tmp7d) * 1.306563) + v89;
  z2e = (float)((float)(tmp4d + tmp5d) * 0.54119611) + v89;
  v90 = (float)((float)(tmp5d + tmp6e) * 0.70710677) + tmp7d;
  v91 = tmp7d - (float)((float)(tmp5d + tmp6e) * 0.70710677);
  v92 = data[48];
  data[45] = v91 + z2e;
  data[41] = v90 + z4e;
  v93 = data[55];
  data[47] = v90 - z4e;
  v94 = v92;
  v95 = v92 - v93;
  v96 = v94 + v93;
  v97 = data[49];
  data[43] = v91 - z2e;
  v98 = data[54];
  tmp7e = v95;
  tmp6f = v97 - v98;
  v281 = data[50];
  v99 = v97 + v98;
  v100 = data[53];
  tmp2e = v281 + v100;
  v101 = v281 - v100;
  v102 = data[52];
  tmp5e = v101;
  v282 = data[51];
  tmp4e = v282 - v102;
  v103 = (float)(v282 + v102) + v96;
  v104 = v96 - (float)(v282 + v102);
  v105 = (float)(tmp2e + v99) + v103;
  data[52] = v103 - (float)(tmp2e + v99);
  v106 = (float)((float)(v99 - tmp2e) + v104) * 0.70710677;
  data[54] = v104 - v106;
  data[48] = v105;
  data[50] = v106 + v104;
  v107 = (float)((float)(tmp4e + tmp5e) - (float)(tmp6f + tmp7e)) * 0.38268343;
  z4f = (float)((float)(tmp6f + tmp7e) * 1.306563) + v107;
  z2f = (float)((float)(tmp4e + tmp5e) * 0.54119611) + v107;
  v108 = (float)((float)(tmp5e + tmp6f) * 0.70710677) + tmp7e;
  v109 = data[56];
  v110 = (float)(tmp7e - (float)((float)(tmp5e + tmp6f) * 0.70710677)) - z2f;
  data[53] = (float)(tmp7e - (float)((float)(tmp5e + tmp6f) * 0.70710677)) + z2f;
  data[49] = v108 + z4f;
  v111 = data[63];
  data[55] = v108 - z4f;
  v112 = v109;
  v113 = v109 - v111;
  v114 = v112 + v111;
  v115 = data[57];
  tmp7f = v113;
  data[51] = v110;
  v116 = data[62];
  tmp6g = v115 - v116;
  v283 = data[58];
  v117 = v115 + v116;
  v118 = data[61];
  tmp2f = v283 + v118;
  v119 = v283 - v118;
  v120 = data[60];
  tmp5f = v119;
  v284 = data[59];
  tmp4f = v284 - v120;
  v121 = (float)(v284 + v120) + v114;
  v122 = v114 - (float)(v284 + v120);
  v123 = (float)(tmp2f + v117) + v121;
  data[60] = v121 - (float)(tmp2f + v117);
  v124 = (float)((float)(v117 - tmp2f) + v122) * 0.70710677;
  data[62] = v122 - v124;
  data[56] = v123;
  data[58] = v124 + v122;
  v125 = (float)((float)(tmp4f + tmp5f) - (float)(tmp6g + tmp7f)) * 0.38268343;
  z4g = (float)((float)(tmp6g + tmp7f) * 1.306563) + v125;
  z2g = (float)((float)(tmp4f + tmp5f) * 0.54119611) + v125;
  v126 = (float)((float)(tmp5f + tmp6g) * 0.70710677) + tmp7f;
  v127 = tmp7f - (float)((float)(tmp5f + tmp6g) * 0.70710677);
  data[61] = v127 + z2g;
  data[59] = v127 - z2g;
  data[57] = v126 + z4g;
  data[63] = v126 - z4g;
  v128 = data[56];
  v129 = data[48];
  v130 = *data - v128;
  v131 = *data + v128;
  v132 = data[8];
  tmp7g = v130;
  tmp6h = v132 - v129;
  v285 = data[16];
  v133 = v132 + v129;
  v134 = data[40];
  tmp2g = v285 + v134;
  v135 = v285 - v134;
  v136 = data[32];
  tmp5g = v135;
  v286 = data[24];
  tmp4g = v286 - v136;
  v137 = (float)(v286 + v136) + v131;
  v138 = v131 - (float)(v286 + v136);
  v139 = (float)(tmp2g + v133) + v137;
  data[32] = v137 - (float)(tmp2g + v133);
  v140 = (float)((float)(v133 - tmp2g) + v138) * 0.70710677;
  data[48] = v138 - v140;
  data[16] = v140 + v138;
  *data = v139;
  v141 = (float)((float)(tmp4g + tmp5g) - (float)(tmp6h + tmp7g)) * 0.38268343;
  z2h = (float)((float)(tmp4g + tmp5g) * 0.54119611) + v141;
  z4h = (float)((float)(tmp6h + tmp7g) * 1.306563) + v141;
  v142 = (float)((float)(tmp5g + tmp6h) * 0.70710677) + tmp7g;
  v143 = data[1];
  v144 = (float)(tmp7g - (float)((float)(tmp5g + tmp6h) * 0.70710677)) - z2h;
  data[40] = (float)(tmp7g - (float)((float)(tmp5g + tmp6h) * 0.70710677)) + z2h;
  data[8] = v142 + z4h;
  v145 = data[57];
  data[56] = v142 - z4h;
  v146 = v143;
  v147 = v143 - v145;
  v148 = v146 + v145;
  v149 = data[9];
  tmp7h = v147;
  data[24] = v144;
  v150 = data[49];
  tmp6i = v149 - v150;
  v151 = v149 + v150;
  v152 = data[41];
  v287 = data[17];
  tmp2h = v287 + v152;
  v153 = v287 - v152;
  v154 = data[33];
  tmp5h = v153;
  v288 = data[25];
  tmp3d = v288 + v154;
  v155 = v288 - v154;
  v156 = tmp2h + v151;
  tmp4h = v155;
  v157 = tmp3d + v148;
  v158 = v148 - tmp3d;
  v159 = (float)((float)(v151 - tmp2h) + v158) * 0.70710677;
  data[33] = v157 - v156;
  data[49] = v158 - v159;
  data[17] = v159 + v158;
  data[1] = v156 + v157;
  v160 = (float)((float)(tmp4h + tmp5h) - (float)(tmp6i + tmp7h)) * 0.38268343;
  z4i = (float)((float)(tmp6i + tmp7h) * 1.306563) + v160;
  z2i = (float)((float)(tmp4h + tmp5h) * 0.54119611) + v160;
  v161 = (float)((float)(tmp5h + tmp6i) * 0.70710677) + tmp7h;
  v162 = data[2];
  v163 = (float)(tmp7h - (float)((float)(tmp5h + tmp6i) * 0.70710677)) - z2i;
  data[41] = (float)(tmp7h - (float)((float)(tmp5h + tmp6i) * 0.70710677)) + z2i;
  data[9] = v161 + z4i;
  v164 = data[58];
  data[57] = v161 - z4i;
  v165 = v162;
  v166 = v162 - v164;
  v167 = v165 + v164;
  v168 = data[10];
  tmp7i = v166;
  data[25] = v163;
  v169 = data[50];
  tmp6j = v168 - v169;
  v170 = v168 + v169;
  v171 = data[42];
  v289 = data[18];
  tmp2i = v289 + v171;
  v172 = v289 - v171;
  v173 = data[34];
  tmp5i = v172;
  v290 = data[26];
  tmp3e = v290 + v173;
  v174 = v290 - v173;
  v175 = tmp2i + v170;
  tmp4i = v174;
  v176 = tmp3e + v167;
  v177 = v167 - tmp3e;
  v178 = (float)((float)(v170 - tmp2i) + v177) * 0.70710677;
  data[34] = v176 - v175;
  data[50] = v177 - v178;
  data[18] = v178 + v177;
  data[2] = v175 + v176;
  v179 = (float)((float)(tmp4i + tmp5i) - (float)(tmp6j + tmp7i)) * 0.38268343;
  z4j = (float)((float)(tmp6j + tmp7i) * 1.306563) + v179;
  z2j = (float)((float)(tmp4i + tmp5i) * 0.54119611) + v179;
  v180 = (float)((float)(tmp5i + tmp6j) * 0.70710677) + tmp7i;
  v181 = (float)(tmp7i - (float)((float)(tmp5i + tmp6j) * 0.70710677)) - z2j;
  v182 = data[3];
  data[42] = (float)(tmp7i - (float)((float)(tmp5i + tmp6j) * 0.70710677)) + z2j;
  data[10] = v180 + z4j;
  v183 = data[59];
  data[58] = v180 - z4j;
  v184 = v182;
  v185 = v182 - v183;
  v186 = v184 + v183;
  v187 = data[11];
  tmp7j = v185;
  data[26] = v181;
  v188 = data[51];
  tmp6k = v187 - v188;
  v291 = data[19];
  v189 = v187 + v188;
  v190 = data[43];
  tmp2j = v291 + v190;
  v191 = v291 - v190;
  v192 = data[35];
  tmp5j = v191;
  v292 = data[27];
  tmp3f = v292 + v192;
  v193 = v292 - v192;
  v194 = tmp2j + v189;
  tmp4j = v193;
  v195 = tmp3f + v186;
  v196 = v186 - tmp3f;
  v197 = (float)((float)(v189 - tmp2j) + v196) * 0.70710677;
  data[35] = v195 - v194;
  data[51] = v196 - v197;
  data[19] = v197 + v196;
  data[3] = v194 + v195;
  v198 = (float)((float)(tmp4j + tmp5j) - (float)(tmp6k + tmp7j)) * 0.38268343;
  z4k = (float)((float)(tmp6k + tmp7j) * 1.306563) + v198;
  z2k = (float)((float)(tmp4j + tmp5j) * 0.54119611) + v198;
  v199 = (float)((float)(tmp5j + tmp6k) * 0.70710677) + tmp7j;
  data[43] = (float)(tmp7j - (float)((float)(tmp5j + tmp6k) * 0.70710677)) + z2k;
  data[27] = (float)(tmp7j - (float)((float)(tmp5j + tmp6k) * 0.70710677)) - z2k;
  v200 = data[4];
  v201 = data[52];
  data[11] = v199 + z4k;
  v202 = data[60];
  data[59] = v199 - z4k;
  v203 = v200;
  v204 = v200 - v202;
  v205 = v203 + v202;
  v206 = data[12];
  tmp7k = v204;
  tmp6l = v206 - v201;
  v293 = data[20];
  v207 = v206 + v201;
  v208 = data[44];
  tmp2k = v293 + v208;
  v209 = v293 - v208;
  v210 = data[36];
  tmp5k = v209;
  v294 = data[28];
  tmp3g = v294 + v210;
  v211 = v294 - v210;
  v212 = tmp2k + v207;
  tmp4k = v211;
  v213 = tmp3g + v205;
  v214 = v205 - tmp3g;
  v215 = (float)((float)(v207 - tmp2k) + v214) * 0.70710677;
  data[36] = v213 - v212;
  data[52] = v214 - v215;
  data[20] = v215 + v214;
  data[4] = v212 + v213;
  v216 = (float)((float)(tmp4k + tmp5k) - (float)(tmp6l + tmp7k)) * 0.38268343;
  z4l = (float)((float)(tmp6l + tmp7k) * 1.306563) + v216;
  z2l = (float)((float)(tmp4k + tmp5k) * 0.54119611) + v216;
  v217 = (float)((float)(tmp5k + tmp6l) * 0.70710677) + tmp7k;
  v218 = data[5];
  data[44] = (float)(tmp7k - (float)((float)(tmp5k + tmp6l) * 0.70710677)) + z2l;
  data[12] = v217 + z4l;
  v219 = data[61];
  data[28] = (float)(tmp7k - (float)((float)(tmp5k + tmp6l) * 0.70710677)) - z2l;
  data[60] = v217 - z4l;
  v220 = data[53];
  v221 = v218;
  v222 = v218 - v219;
  v223 = v221 + v219;
  v224 = data[13];
  tmp7l = v222;
  tmp6m = v224 - v220;
  v225 = v224 + v220;
  v226 = data[45];
  v295 = data[21];
  tmp2l = v295 + v226;
  v227 = v295 - v226;
  v228 = data[37];
  tmp5l = v227;
  v296 = data[29];
  tmp3h = v296 + v228;
  v229 = v296 - v228;
  v230 = tmp2l + v225;
  tmp4l = v229;
  v231 = tmp3h + v223;
  v232 = v223 - tmp3h;
  v233 = (float)((float)(v225 - tmp2l) + v232) * 0.70710677;
  data[37] = v231 - v230;
  data[53] = v232 - v233;
  data[21] = v233 + v232;
  data[5] = v230 + v231;
  v234 = (float)((float)(tmp4l + tmp5l) - (float)(tmp6m + tmp7l)) * 0.38268343;
  z4m = (float)((float)(tmp6m + tmp7l) * 1.306563) + v234;
  z2m = (float)((float)(tmp4l + tmp5l) * 0.54119611) + v234;
  v235 = (float)((float)(tmp5l + tmp6m) * 0.70710677) + tmp7l;
  v236 = data[6];
  data[45] = (float)(tmp7l - (float)((float)(tmp5l + tmp6m) * 0.70710677)) + z2m;
  data[61] = v235 - z4m;
  data[13] = v235 + z4m;
  v237 = data[62];
  data[29] = (float)(tmp7l - (float)((float)(tmp5l + tmp6m) * 0.70710677)) - z2m;
  v238 = data[54];
  v239 = v236 + v237;
  tmp7m = v236 - v237;
  v240 = data[14];
  tmp6n = v240 - v238;
  v241 = v240 + v238;
  v242 = data[46];
  v297 = data[22];
  tmp2m = v297 + v242;
  v243 = v297 - v242;
  v244 = data[38];
  tmp5m = v243;
  v298 = data[30];
  tmp3i = v298 + v244;
  v245 = v298 - v244;
  v246 = tmp2m + v241;
  tmp4m = v245;
  v247 = tmp3i + v239;
  v248 = v239 - tmp3i;
  v249 = (float)((float)(v241 - tmp2m) + v248) * 0.70710677;
  data[38] = v247 - v246;
  data[54] = v248 - v249;
  data[22] = v249 + v248;
  data[6] = v246 + v247;
  v250 = (float)((float)(tmp4m + tmp5m) - (float)(tmp6n + tmp7m)) * 0.38268343;
  z4n = (float)((float)(tmp6n + tmp7m) * 1.306563) + v250;
  z2n = (float)((float)(tmp4m + tmp5m) * 0.54119611) + v250;
  v251 = (float)((float)(tmp5m + tmp6n) * 0.70710677) + tmp7m;
  v252 = data[7];
  v253 = (float)(tmp7m - (float)((float)(tmp5m + tmp6n) * 0.70710677)) - z2n;
  data[46] = (float)(tmp7m - (float)((float)(tmp5m + tmp6n) * 0.70710677)) + z2n;
  data[14] = v251 + z4n;
  v254 = data[63];
  data[62] = v251 - z4n;
  v255 = v252;
  v256 = v252 - v254;
  v257 = v255 + v254;
  v258 = data[15];
  tmp7n = v256;
  data[30] = v253;
  v259 = data[55];
  v260 = v258 + v259;
  tmp6o = v258 - v259;
  v261 = data[47];
  v299 = data[23];
  tmp2n = v299 + v261;
  v262 = v299 - v261;
  v263 = data[39];
  tmp5n = v262;
  v300 = data[31];
  tmp3j = v300 + v263;
  v264 = v300 - v263;
  v265 = tmp2n + v260;
  tmp4n = v264;
  v266 = tmp3j + v257;
  v267 = v257 - tmp3j;
  v268 = (float)((float)(v260 - tmp2n) + v267) * 0.70710677;
  data[39] = v266 - v265;
  data[55] = v267 - v268;
  data[7] = v265 + v266;
  data[23] = v268 + v267;
  v269 = (float)((float)(tmp4n + tmp5n) - (float)(tmp6o + tmp7n)) * 0.38268343;
  v270 = (float)(tmp5n + tmp6o) * 0.70710677;
  v271 = (float)((float)(tmp4n + tmp5n) * 0.54119611) + v269;
  data[47] = (float)(tmp7n - v270) + v271;
  v272 = (float)((float)(tmp6o + tmp7n) * 1.306563) + v269;
  data[31] = (float)(tmp7n - v270) - v271;
  data[15] = (float)(v270 + tmp7n) + v272;
  data[63] = (float)(v270 + tmp7n) - v272;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x0040D800
// Name: _jpeg_fdct_float
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_fdct_float(float *data)
{
  float v2; // xmm6_4
  float v3; // xmm5_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm6_4
  float v10; // xmm2_4
  float v11; // xmm7_4
  float v12; // xmm5_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm7_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm4_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm5_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm4_4
  float v27; // xmm6_4
  float v28; // xmm6_4
  float v29; // xmm5_4
  float v30; // xmm7_4
  float v31; // xmm4_4
  float v32; // xmm6_4
  float v33; // xmm5_4
  float v34; // xmm4_4
  float v35; // xmm7_4
  float v36; // xmm6_4
  float v37; // xmm5_4
  float v38; // xmm4_4
  float v39; // xmm6_4
  float v40; // xmm6_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm4_4
  float v44; // xmm6_4
  float v45; // xmm5_4
  float v46; // xmm4_4
  float v47; // xmm7_4
  float v48; // xmm6_4
  float v49; // xmm5_4
  float v50; // xmm4_4
  float v51; // xmm6_4
  float v52; // xmm5_4
  float v53; // xmm7_4
  float v54; // xmm4_4
  float v55; // xmm6_4
  float v56; // xmm5_4
  float v57; // xmm4_4
  float v58; // xmm6_4
  float v59; // xmm7_4
  float v60; // xmm5_4
  float v61; // xmm4_4
  float v62; // xmm5_4
  float v63; // xmm6_4
  float v64; // xmm4_4
  float v65; // xmm7_4
  float v66; // xmm6_4
  float v67; // xmm7_4
  float v68; // xmm6_4
  float v69; // xmm5_4
  float v70; // xmm4_4
  float v71; // xmm6_4
  float v72; // xmm5_4
  float v73; // xmm7_4
  float v74; // xmm4_4
  float v75; // xmm6_4
  float v76; // xmm7_4
  float v77; // xmm5_4
  float v78; // xmm4_4
  float v79; // xmm5_4
  float v80; // xmm6_4
  float v81; // xmm4_4
  float v82; // xmm7_4
  float v83; // xmm6_4
  float v84; // xmm7_4
  float v85; // xmm7_4
  float v86; // xmm6_4
  float v87; // xmm5_4
  float v88; // xmm4_4
  float v89; // xmm6_4
  float v90; // xmm5_4
  float v91; // xmm7_4
  float v92; // xmm4_4
  float v93; // xmm6_4
  float v94; // xmm5_4
  float v95; // xmm4_4
  float v96; // xmm5_4
  float v97; // xmm6_4
  float v98; // xmm7_4
  float v99; // xmm4_4
  float v100; // xmm7_4
  float v101; // xmm6_4
  float v102; // xmm7_4
  float v103; // xmm6_4
  float v104; // xmm5_4
  float v105; // xmm7_4
  float v106; // xmm4_4
  float v107; // xmm6_4
  float v108; // xmm5_4
  float v109; // xmm4_4
  float v110; // xmm7_4
  float v111; // xmm6_4
  float v112; // xmm5_4
  float v113; // xmm4_4
  float v114; // xmm5_4
  float v115; // xmm6_4
  float v116; // xmm7_4
  float v117; // xmm4_4
  float v118; // xmm7_4
  float v119; // xmm6_4
  float v120; // xmm7_4
  float v121; // xmm6_4
  float v122; // xmm5_4
  float v123; // xmm7_4
  float v124; // xmm4_4
  float v125; // xmm6_4
  float v126; // xmm5_4
  float v127; // xmm7_4
  float v128; // xmm6_4
  float v129; // xmm7_4
  float v130; // xmm4_4
  float v131; // xmm5_4
  float v132; // xmm6_4
  float v133; // xmm4_4
  float v134; // xmm7_4
  float v135; // xmm6_4
  float v136; // xmm7_4
  float v137; // xmm6_4
  float v138; // xmm5_4
  float v139; // xmm7_4
  float v140; // xmm4_4
  float v141; // xmm6_4
  float v142; // xmm5_4
  float v143; // xmm4_4
  float v144; // xmm7_4
  float v145; // xmm6_4
  float v146; // xmm5_4
  float v147; // xmm4_4
  float v148; // xmm5_4
  float v149; // xmm6_4
  float v150; // xmm7_4
  float v151; // xmm4_4
  float v152; // xmm7_4
  float v153; // xmm6_4
  float v154; // xmm7_4
  float v155; // xmm6_4
  float v156; // xmm7_4
  float v157; // xmm6_4
  float v158; // xmm5_4
  float v159; // xmm4_4
  float v160; // xmm6_4
  float v161; // xmm5_4
  float v162; // xmm4_4
  float v163; // xmm7_4
  float v164; // xmm6_4
  float v165; // xmm5_4
  float v166; // xmm4_4
  float v167; // xmm5_4
  float v168; // xmm6_4
  float v169; // xmm7_4
  float v170; // xmm4_4
  float v171; // xmm7_4
  float v172; // xmm6_4
  float v173; // xmm7_4
  float v174; // xmm6_4
  float v175; // xmm7_4
  float v176; // xmm6_4
  float v177; // xmm5_4
  float v178; // xmm4_4
  float v179; // xmm6_4
  float v180; // xmm5_4
  float v181; // xmm7_4
  float v182; // xmm4_4
  float v183; // xmm6_4
  float v184; // xmm5_4
  float v185; // xmm4_4
  float v186; // xmm5_4
  float v187; // xmm6_4
  float v188; // xmm7_4
  float v189; // xmm4_4
  float v190; // xmm7_4
  float v191; // xmm6_4
  float v192; // xmm7_4
  float v193; // xmm6_4
  float v194; // xmm7_4
  float v195; // xmm6_4
  float v196; // xmm5_4
  float v197; // xmm4_4
  float v198; // xmm6_4
  float v199; // xmm5_4
  float v200; // xmm4_4
  float v201; // xmm7_4
  float v202; // xmm6_4
  float v203; // xmm5_4
  float v204; // xmm4_4
  float v205; // xmm5_4
  float v206; // xmm6_4
  float v207; // xmm4_4
  float v208; // xmm7_4
  float v209; // xmm6_4
  float v210; // xmm7_4
  float v211; // xmm6_4
  float v212; // xmm7_4
  float v213; // xmm6_4
  float v214; // xmm5_4
  float v215; // xmm4_4
  float v216; // xmm6_4
  float v217; // xmm5_4
  float v218; // xmm4_4
  float v219; // xmm6_4
  float v220; // xmm7_4
  float v221; // xmm5_4
  float v222; // xmm4_4
  float v223; // xmm5_4
  float v224; // xmm6_4
  float v225; // xmm4_4
  float v226; // xmm7_4
  float v227; // xmm6_4
  float v228; // xmm7_4
  float v229; // xmm6_4
  float v230; // xmm7_4
  float v231; // xmm6_4
  float v232; // xmm5_4
  float v233; // xmm4_4
  float v234; // xmm6_4
  float v235; // xmm5_4
  float v236; // xmm4_4
  float v237; // xmm6_4
  float v238; // xmm7_4
  float v239; // xmm5_4
  float v240; // xmm4_4
  float v241; // xmm4_4
  float v242; // xmm7_4
  float v243; // xmm6_4
  float v244; // xmm7_4
  float v245; // xmm6_4
  float v246; // xmm7_4
  float v247; // xmm6_4
  float v248; // xmm5_4
  float v249; // xmm4_4
  float v250; // xmm6_4
  float v251; // xmm5_4
  float v252; // xmm4_4
  float v253; // xmm7_4
  float v254; // xmm6_4
  float v255; // xmm5_4
  float v256; // xmm4_4
  float v257; // xmm5_4
  float v258; // xmm6_4
  float v259; // xmm7_4
  float v260; // xmm4_4
  float v261; // xmm7_4
  float v262; // xmm6_4
  float v263; // xmm7_4
  float v264; // xmm6_4
  float v265; // xmm7_4
  float v266; // xmm6_4
  float v267; // xmm5_4
  float v268; // xmm4_4
  float v269; // xmm6_4
  float v270; // xmm1_4
  float v271; // xmm5_4
  float v272; // xmm4_4
  float v273; // [esp+0h] [ebp-24h]
  float v274; // [esp+0h] [ebp-24h]
  float v275; // [esp+0h] [ebp-24h]
  float v276; // [esp+0h] [ebp-24h]
  float v277; // [esp+0h] [ebp-24h]
  float v278; // [esp+0h] [ebp-24h]
  float v279; // [esp+0h] [ebp-24h]
  float v280; // [esp+0h] [ebp-24h]
  float v281; // [esp+0h] [ebp-24h]
  float v282; // [esp+0h] [ebp-24h]
  float v283; // [esp+0h] [ebp-24h]
  float v284; // [esp+0h] [ebp-24h]
  float v285; // [esp+0h] [ebp-24h]
  float v286; // [esp+0h] [ebp-24h]
  float v287; // [esp+0h] [ebp-24h]
  float v288; // [esp+0h] [ebp-24h]
  float v289; // [esp+0h] [ebp-24h]
  float v290; // [esp+0h] [ebp-24h]
  float v291; // [esp+0h] [ebp-24h]
  float v292; // [esp+0h] [ebp-24h]
  float v293; // [esp+0h] [ebp-24h]
  float v294; // [esp+0h] [ebp-24h]
  float v295; // [esp+0h] [ebp-24h]
  float v296; // [esp+0h] [ebp-24h]
  float v297; // [esp+0h] [ebp-24h]
  float v298; // [esp+0h] [ebp-24h]
  float v299; // [esp+0h] [ebp-24h]
  float v300; // [esp+0h] [ebp-24h]
  float tmp7; // [esp+4h] [ebp-20h]
  float tmp7a; // [esp+4h] [ebp-20h]
  float tmp7b; // [esp+4h] [ebp-20h]
  float tmp7c; // [esp+4h] [ebp-20h]
  float tmp7d; // [esp+4h] [ebp-20h]
  float tmp7e; // [esp+4h] [ebp-20h]
  float tmp7f; // [esp+4h] [ebp-20h]
  float tmp7g; // [esp+4h] [ebp-20h]
  float tmp7h; // [esp+4h] [ebp-20h]
  float tmp7i; // [esp+4h] [ebp-20h]
  float tmp7j; // [esp+4h] [ebp-20h]
  float tmp7k; // [esp+4h] [ebp-20h]
  float tmp7l; // [esp+4h] [ebp-20h]
  float tmp7m; // [esp+4h] [ebp-20h]
  float tmp7n; // [esp+4h] [ebp-20h]
  float tmp11; // [esp+8h] [ebp-1Ch]
  float tmp3; // [esp+Ch] [ebp-18h]
  float tmp3a; // [esp+Ch] [ebp-18h]
  float tmp3b; // [esp+Ch] [ebp-18h]
  float tmp3c; // [esp+Ch] [ebp-18h]
  float tmp3d; // [esp+Ch] [ebp-18h]
  float tmp3e; // [esp+Ch] [ebp-18h]
  float tmp3f; // [esp+Ch] [ebp-18h]
  float tmp3g; // [esp+Ch] [ebp-18h]
  float tmp3h; // [esp+Ch] [ebp-18h]
  float tmp3i; // [esp+Ch] [ebp-18h]
  float tmp3j; // [esp+Ch] [ebp-18h]
  float z4; // [esp+10h] [ebp-14h]
  float z4a; // [esp+10h] [ebp-14h]
  float z4b; // [esp+10h] [ebp-14h]
  float z4c; // [esp+10h] [ebp-14h]
  float z4d; // [esp+10h] [ebp-14h]
  float z4e; // [esp+10h] [ebp-14h]
  float z4f; // [esp+10h] [ebp-14h]
  float z4g; // [esp+10h] [ebp-14h]
  float z4h; // [esp+10h] [ebp-14h]
  float z4i; // [esp+10h] [ebp-14h]
  float z4j; // [esp+10h] [ebp-14h]
  float z4k; // [esp+10h] [ebp-14h]
  float z4l; // [esp+10h] [ebp-14h]
  float z4m; // [esp+10h] [ebp-14h]
  float z4n; // [esp+10h] [ebp-14h]
  float z2; // [esp+14h] [ebp-10h]
  float z2a; // [esp+14h] [ebp-10h]
  float z2b; // [esp+14h] [ebp-10h]
  float z2c; // [esp+14h] [ebp-10h]
  float z2d; // [esp+14h] [ebp-10h]
  float z2e; // [esp+14h] [ebp-10h]
  float z2f; // [esp+14h] [ebp-10h]
  float z2g; // [esp+14h] [ebp-10h]
  float z2h; // [esp+14h] [ebp-10h]
  float z2i; // [esp+14h] [ebp-10h]
  float z2j; // [esp+14h] [ebp-10h]
  float z2k; // [esp+14h] [ebp-10h]
  float z2l; // [esp+14h] [ebp-10h]
  float z2m; // [esp+14h] [ebp-10h]
  float z2n; // [esp+14h] [ebp-10h]
  float tmp4; // [esp+18h] [ebp-Ch]
  float tmp4a; // [esp+18h] [ebp-Ch]
  float tmp4b; // [esp+18h] [ebp-Ch]
  float tmp4c; // [esp+18h] [ebp-Ch]
  float tmp4d; // [esp+18h] [ebp-Ch]
  float tmp4e; // [esp+18h] [ebp-Ch]
  float tmp4f; // [esp+18h] [ebp-Ch]
  float tmp4g; // [esp+18h] [ebp-Ch]
  float tmp4h; // [esp+18h] [ebp-Ch]
  float tmp4i; // [esp+18h] [ebp-Ch]
  float tmp4j; // [esp+18h] [ebp-Ch]
  float tmp4k; // [esp+18h] [ebp-Ch]
  float tmp4l; // [esp+18h] [ebp-Ch]
  float tmp4m; // [esp+18h] [ebp-Ch]
  float tmp4n; // [esp+18h] [ebp-Ch]
  float tmp5; // [esp+1Ch] [ebp-8h]
  float tmp5a; // [esp+1Ch] [ebp-8h]
  float tmp5b; // [esp+1Ch] [ebp-8h]
  float tmp5c; // [esp+1Ch] [ebp-8h]
  float tmp5d; // [esp+1Ch] [ebp-8h]
  float tmp5e; // [esp+1Ch] [ebp-8h]
  float tmp5f; // [esp+1Ch] [ebp-8h]
  float tmp5g; // [esp+1Ch] [ebp-8h]
  float tmp5h; // [esp+1Ch] [ebp-8h]
  float tmp5i; // [esp+1Ch] [ebp-8h]
  float tmp5j; // [esp+1Ch] [ebp-8h]
  float tmp5k; // [esp+1Ch] [ebp-8h]
  float tmp5l; // [esp+1Ch] [ebp-8h]
  float tmp5m; // [esp+1Ch] [ebp-8h]
  float tmp5n; // [esp+1Ch] [ebp-8h]
  float tmp2; // [esp+20h] [ebp-4h]
  float tmp2a; // [esp+20h] [ebp-4h]
  float tmp2b; // [esp+20h] [ebp-4h]
  float tmp2c; // [esp+20h] [ebp-4h]
  float tmp2d; // [esp+20h] [ebp-4h]
  float tmp2e; // [esp+20h] [ebp-4h]
  float tmp2f; // [esp+20h] [ebp-4h]
  float tmp2g; // [esp+20h] [ebp-4h]
  float tmp2h; // [esp+20h] [ebp-4h]
  float tmp2i; // [esp+20h] [ebp-4h]
  float tmp2j; // [esp+20h] [ebp-4h]
  float tmp2k; // [esp+20h] [ebp-4h]
  float tmp2l; // [esp+20h] [ebp-4h]
  float tmp2m; // [esp+20h] [ebp-4h]
  float tmp2n; // [esp+20h] [ebp-4h]
  float tmp6; // [esp+2Ch] [ebp+8h]
  float tmp6a; // [esp+2Ch] [ebp+8h]
  float tmp6b; // [esp+2Ch] [ebp+8h]
  float tmp6c; // [esp+2Ch] [ebp+8h]
  float tmp6d; // [esp+2Ch] [ebp+8h]
  float tmp6e; // [esp+2Ch] [ebp+8h]
  float tmp6f; // [esp+2Ch] [ebp+8h]
  float tmp6g; // [esp+2Ch] [ebp+8h]
  float tmp6h; // [esp+2Ch] [ebp+8h]
  float tmp6i; // [esp+2Ch] [ebp+8h]
  float tmp6j; // [esp+2Ch] [ebp+8h]
  float tmp6k; // [esp+2Ch] [ebp+8h]
  float tmp6l; // [esp+2Ch] [ebp+8h]
  float tmp6m; // [esp+2Ch] [ebp+8h]
  float tmp6n; // [esp+2Ch] [ebp+8h]
  float tmp6o; // [esp+2Ch] [ebp+8h]

  v2 = *data;
  v3 = data[2];
  v4 = data[1];
  v5 = v4 - data[6];
  v6 = v4 + data[6];
  tmp6 = v5;
  v7 = data[3] + data[4];
  v8 = v2 + data[7];
  v9 = v2 - data[7];
  tmp4 = data[3] - data[4];
  v10 = v7 + v8;
  v11 = v3 + data[5];
  v12 = v3 - data[5];
  v13 = v8 - v7;
  *data = (float)(v11 + v6) + v10;
  data[4] = v10 - (float)(v11 + v6);
  v14 = (float)((float)(v6 - v11) + v13) * 0.70710677;
  data[6] = v13 - v14;
  v15 = (float)((float)(tmp4 + v12) - (float)(tmp6 + v9)) * 0.38268343;
  data[2] = v14 + v13;
  z2 = (float)((float)(tmp4 + v12) * 0.54119611) + v15;
  z4 = (float)((float)(tmp6 + v9) * 1.306563) + v15;
  v16 = (float)(v12 + tmp6) * 0.70710677;
  v17 = v16 + v9;
  v18 = v9 - v16;
  v19 = data[8];
  v20 = v18 + z2;
  data[3] = v18 - z2;
  v21 = v17 + z4;
  data[7] = v17 - z4;
  v22 = v19;
  v23 = v19 - data[15];
  v24 = v22 + data[15];
  data[1] = v21;
  v25 = data[9];
  tmp7 = v23;
  v26 = v25 + data[14];
  tmp6a = v25 - data[14];
  v27 = data[10];
  data[5] = v20;
  tmp2 = v27 + data[13];
  tmp5 = v27 - data[13];
  tmp11 = data[11];
  tmp3 = tmp11 + data[12];
  tmp4a = tmp11 - data[12];
  v28 = tmp3 + v24;
  v29 = v24 - tmp3;
  v30 = tmp2 + v26;
  v31 = (float)((float)(v26 - tmp2) + v29) * 0.70710677;
  data[12] = v28 - v30;
  data[10] = v31 + v29;
  data[14] = v29 - v31;
  data[8] = v30 + v28;
  v32 = (float)((float)(tmp4a + tmp5) - (float)(tmp6a + tmp7)) * 0.38268343;
  z4a = (float)((float)(tmp6a + tmp7) * 1.306563) + v32;
  z2a = (float)((float)(tmp4a + tmp5) * 0.54119611) + v32;
  v33 = (float)((float)(tmp5 + tmp6a) * 0.70710677) + tmp7;
  v34 = data[16];
  v35 = (float)(tmp7 - (float)((float)(tmp5 + tmp6a) * 0.70710677)) - z2a;
  data[13] = (float)(tmp7 - (float)((float)(tmp5 + tmp6a) * 0.70710677)) + z2a;
  data[9] = v33 + z4a;
  v36 = data[17];
  data[15] = v33 - z4a;
  v37 = v34 + data[23];
  tmp7a = v34 - data[23];
  v38 = v36 + data[22];
  tmp6b = v36 - data[22];
  v273 = data[18];
  tmp2a = v273 + data[21];
  tmp5a = v273 - data[21];
  v274 = data[19];
  v39 = v274 + data[20];
  data[11] = v35;
  tmp3a = v39;
  tmp4b = v274 - data[20];
  v40 = v39 + v37;
  v41 = v37 - tmp3a;
  v42 = tmp2a + v38;
  v43 = (float)((float)(v38 - tmp2a) + v41) * 0.70710677;
  data[20] = v40 - v42;
  data[18] = v43 + v41;
  data[22] = v41 - v43;
  data[16] = v42 + v40;
  v44 = (float)((float)(tmp4b + tmp5a) - (float)(tmp6b + tmp7a)) * 0.38268343;
  z4b = (float)((float)(tmp6b + tmp7a) * 1.306563) + v44;
  z2b = (float)((float)(tmp4b + tmp5a) * 0.54119611) + v44;
  v45 = (float)((float)(tmp5a + tmp6b) * 0.70710677) + tmp7a;
  v46 = data[24];
  data[21] = (float)(tmp7a - (float)((float)(tmp5a + tmp6b) * 0.70710677)) + z2b;
  v47 = (float)(tmp7a - (float)((float)(tmp5a + tmp6b) * 0.70710677)) - z2b;
  data[17] = v45 + z4b;
  v48 = data[25];
  data[23] = v45 - z4b;
  v49 = v46 + data[31];
  tmp7b = v46 - data[31];
  v50 = v48 + data[30];
  tmp6c = v48 - data[30];
  v275 = data[26];
  tmp2b = v275 + data[29];
  tmp5b = v275 - data[29];
  v276 = data[27];
  tmp3b = v276 + data[28];
  tmp4c = v276 - data[28];
  data[19] = v47;
  v51 = tmp3b + v49;
  v52 = v49 - tmp3b;
  v53 = (float)(tmp2b + v50) + v51;
  data[28] = v51 - (float)(tmp2b + v50);
  v54 = (float)((float)(v50 - tmp2b) + v52) * 0.70710677;
  data[26] = v54 + v52;
  data[30] = v52 - v54;
  data[24] = v53;
  v55 = (float)((float)(tmp4c + tmp5b) - (float)(tmp6c + tmp7b)) * 0.38268343;
  z4c = (float)((float)(tmp6c + tmp7b) * 1.306563) + v55;
  z2c = (float)((float)(tmp4c + tmp5b) * 0.54119611) + v55;
  v56 = (float)((float)(tmp5b + tmp6c) * 0.70710677) + tmp7b;
  v57 = data[32];
  data[29] = (float)(tmp7b - (float)((float)(tmp5b + tmp6c) * 0.70710677)) + z2c;
  data[25] = v56 + z4c;
  v58 = data[39];
  data[27] = (float)(tmp7b - (float)((float)(tmp5b + tmp6c) * 0.70710677)) - z2c;
  v59 = data[38];
  data[31] = v56 - z4c;
  v60 = v57;
  v61 = v57 - v58;
  v62 = v60 + v58;
  v63 = data[33];
  tmp7c = v61;
  tmp6d = v63 - v59;
  v277 = data[34];
  v64 = v63 + v59;
  v65 = data[37];
  tmp2c = v277 + v65;
  v66 = v277 - v65;
  v67 = data[36];
  tmp5c = v66;
  v278 = data[35];
  v68 = (float)(v278 + v67) + v62;
  v69 = v62 - (float)(v278 + v67);
  data[32] = (float)(tmp2c + v64) + v68;
  data[36] = v68 - (float)(tmp2c + v64);
  v70 = (float)((float)(v64 - tmp2c) + v69) * 0.70710677;
  data[34] = v70 + v69;
  data[38] = v69 - v70;
  v71 = (float)((float)((float)(v278 - v67) + tmp5c) - (float)(tmp6d + tmp7c)) * 0.38268343;
  z4d = (float)((float)(tmp6d + tmp7c) * 1.306563) + v71;
  z2d = (float)((float)((float)(v278 - v67) + tmp5c) * 0.54119611) + v71;
  v72 = (float)((float)(tmp5c + tmp6d) * 0.70710677) + tmp7c;
  v73 = tmp7c - (float)((float)(tmp5c + tmp6d) * 0.70710677);
  v74 = data[40];
  data[37] = v73 + z2d;
  data[33] = v72 + z4d;
  v75 = data[47];
  data[35] = v73 - z2d;
  v76 = data[46];
  data[39] = v72 - z4d;
  v77 = v74;
  v78 = v74 - v75;
  v79 = v77 + v75;
  v80 = data[41];
  tmp7d = v78;
  tmp6e = v80 - v76;
  v279 = data[42];
  v81 = v80 + v76;
  v82 = data[45];
  tmp2d = v279 + v82;
  v83 = v279 - v82;
  v84 = data[44];
  tmp5d = v83;
  v280 = data[43];
  tmp3c = v280 + v84;
  tmp4d = v280 - v84;
  v85 = tmp2d + v81;
  v86 = tmp3c + v79;
  v87 = v79 - tmp3c;
  data[44] = v86 - (float)(tmp2d + v81);
  v88 = (float)((float)(v81 - tmp2d) + v87) * 0.70710677;
  data[40] = v85 + v86;
  data[42] = v88 + v87;
  data[46] = v87 - v88;
  v89 = (float)((float)(tmp4d + tmp5d) - (float)(tmp6e + tmp7d)) * 0.38268343;
  z4e = (float)((float)(tmp6e + tmp7d) * 1.306563) + v89;
  z2e = (float)((float)(tmp4d + tmp5d) * 0.54119611) + v89;
  v90 = (float)((float)(tmp5d + tmp6e) * 0.70710677) + tmp7d;
  v91 = tmp7d - (float)((float)(tmp5d + tmp6e) * 0.70710677);
  v92 = data[48];
  data[45] = v91 + z2e;
  data[41] = v90 + z4e;
  v93 = data[55];
  data[47] = v90 - z4e;
  v94 = v92;
  v95 = v92 - v93;
  v96 = v94 + v93;
  v97 = data[49];
  data[43] = v91 - z2e;
  v98 = data[54];
  tmp7e = v95;
  tmp6f = v97 - v98;
  v281 = data[50];
  v99 = v97 + v98;
  v100 = data[53];
  tmp2e = v281 + v100;
  v101 = v281 - v100;
  v102 = data[52];
  tmp5e = v101;
  v282 = data[51];
  tmp4e = v282 - v102;
  v103 = (float)(v282 + v102) + v96;
  v104 = v96 - (float)(v282 + v102);
  v105 = (float)(tmp2e + v99) + v103;
  data[52] = v103 - (float)(tmp2e + v99);
  v106 = (float)((float)(v99 - tmp2e) + v104) * 0.70710677;
  data[54] = v104 - v106;
  data[48] = v105;
  data[50] = v106 + v104;
  v107 = (float)((float)(tmp4e + tmp5e) - (float)(tmp6f + tmp7e)) * 0.38268343;
  z4f = (float)((float)(tmp6f + tmp7e) * 1.306563) + v107;
  z2f = (float)((float)(tmp4e + tmp5e) * 0.54119611) + v107;
  v108 = (float)((float)(tmp5e + tmp6f) * 0.70710677) + tmp7e;
  v109 = data[56];
  v110 = (float)(tmp7e - (float)((float)(tmp5e + tmp6f) * 0.70710677)) - z2f;
  data[53] = (float)(tmp7e - (float)((float)(tmp5e + tmp6f) * 0.70710677)) + z2f;
  data[49] = v108 + z4f;
  v111 = data[63];
  data[55] = v108 - z4f;
  v112 = v109;
  v113 = v109 - v111;
  v114 = v112 + v111;
  v115 = data[57];
  tmp7f = v113;
  data[51] = v110;
  v116 = data[62];
  tmp6g = v115 - v116;
  v283 = data[58];
  v117 = v115 + v116;
  v118 = data[61];
  tmp2f = v283 + v118;
  v119 = v283 - v118;
  v120 = data[60];
  tmp5f = v119;
  v284 = data[59];
  tmp4f = v284 - v120;
  v121 = (float)(v284 + v120) + v114;
  v122 = v114 - (float)(v284 + v120);
  v123 = (float)(tmp2f + v117) + v121;
  data[60] = v121 - (float)(tmp2f + v117);
  v124 = (float)((float)(v117 - tmp2f) + v122) * 0.70710677;
  data[62] = v122 - v124;
  data[56] = v123;
  data[58] = v124 + v122;
  v125 = (float)((float)(tmp4f + tmp5f) - (float)(tmp6g + tmp7f)) * 0.38268343;
  z4g = (float)((float)(tmp6g + tmp7f) * 1.306563) + v125;
  z2g = (float)((float)(tmp4f + tmp5f) * 0.54119611) + v125;
  v126 = (float)((float)(tmp5f + tmp6g) * 0.70710677) + tmp7f;
  v127 = tmp7f - (float)((float)(tmp5f + tmp6g) * 0.70710677);
  data[61] = v127 + z2g;
  data[59] = v127 - z2g;
  data[57] = v126 + z4g;
  data[63] = v126 - z4g;
  v128 = data[56];
  v129 = data[48];
  v130 = *data - v128;
  v131 = *data + v128;
  v132 = data[8];
  tmp7g = v130;
  tmp6h = v132 - v129;
  v285 = data[16];
  v133 = v132 + v129;
  v134 = data[40];
  tmp2g = v285 + v134;
  v135 = v285 - v134;
  v136 = data[32];
  tmp5g = v135;
  v286 = data[24];
  tmp4g = v286 - v136;
  v137 = (float)(v286 + v136) + v131;
  v138 = v131 - (float)(v286 + v136);
  v139 = (float)(tmp2g + v133) + v137;
  data[32] = v137 - (float)(tmp2g + v133);
  v140 = (float)((float)(v133 - tmp2g) + v138) * 0.70710677;
  data[48] = v138 - v140;
  data[16] = v140 + v138;
  *data = v139;
  v141 = (float)((float)(tmp4g + tmp5g) - (float)(tmp6h + tmp7g)) * 0.38268343;
  z2h = (float)((float)(tmp4g + tmp5g) * 0.54119611) + v141;
  z4h = (float)((float)(tmp6h + tmp7g) * 1.306563) + v141;
  v142 = (float)((float)(tmp5g + tmp6h) * 0.70710677) + tmp7g;
  v143 = data[1];
  v144 = (float)(tmp7g - (float)((float)(tmp5g + tmp6h) * 0.70710677)) - z2h;
  data[40] = (float)(tmp7g - (float)((float)(tmp5g + tmp6h) * 0.70710677)) + z2h;
  data[8] = v142 + z4h;
  v145 = data[57];
  data[56] = v142 - z4h;
  v146 = v143;
  v147 = v143 - v145;
  v148 = v146 + v145;
  v149 = data[9];
  tmp7h = v147;
  data[24] = v144;
  v150 = data[49];
  tmp6i = v149 - v150;
  v151 = v149 + v150;
  v152 = data[41];
  v287 = data[17];
  tmp2h = v287 + v152;
  v153 = v287 - v152;
  v154 = data[33];
  tmp5h = v153;
  v288 = data[25];
  tmp3d = v288 + v154;
  v155 = v288 - v154;
  v156 = tmp2h + v151;
  tmp4h = v155;
  v157 = tmp3d + v148;
  v158 = v148 - tmp3d;
  v159 = (float)((float)(v151 - tmp2h) + v158) * 0.70710677;
  data[33] = v157 - v156;
  data[49] = v158 - v159;
  data[17] = v159 + v158;
  data[1] = v156 + v157;
  v160 = (float)((float)(tmp4h + tmp5h) - (float)(tmp6i + tmp7h)) * 0.38268343;
  z4i = (float)((float)(tmp6i + tmp7h) * 1.306563) + v160;
  z2i = (float)((float)(tmp4h + tmp5h) * 0.54119611) + v160;
  v161 = (float)((float)(tmp5h + tmp6i) * 0.70710677) + tmp7h;
  v162 = data[2];
  v163 = (float)(tmp7h - (float)((float)(tmp5h + tmp6i) * 0.70710677)) - z2i;
  data[41] = (float)(tmp7h - (float)((float)(tmp5h + tmp6i) * 0.70710677)) + z2i;
  data[9] = v161 + z4i;
  v164 = data[58];
  data[57] = v161 - z4i;
  v165 = v162;
  v166 = v162 - v164;
  v167 = v165 + v164;
  v168 = data[10];
  tmp7i = v166;
  data[25] = v163;
  v169 = data[50];
  tmp6j = v168 - v169;
  v170 = v168 + v169;
  v171 = data[42];
  v289 = data[18];
  tmp2i = v289 + v171;
  v172 = v289 - v171;
  v173 = data[34];
  tmp5i = v172;
  v290 = data[26];
  tmp3e = v290 + v173;
  v174 = v290 - v173;
  v175 = tmp2i + v170;
  tmp4i = v174;
  v176 = tmp3e + v167;
  v177 = v167 - tmp3e;
  v178 = (float)((float)(v170 - tmp2i) + v177) * 0.70710677;
  data[34] = v176 - v175;
  data[50] = v177 - v178;
  data[18] = v178 + v177;
  data[2] = v175 + v176;
  v179 = (float)((float)(tmp4i + tmp5i) - (float)(tmp6j + tmp7i)) * 0.38268343;
  z4j = (float)((float)(tmp6j + tmp7i) * 1.306563) + v179;
  z2j = (float)((float)(tmp4i + tmp5i) * 0.54119611) + v179;
  v180 = (float)((float)(tmp5i + tmp6j) * 0.70710677) + tmp7i;
  v181 = (float)(tmp7i - (float)((float)(tmp5i + tmp6j) * 0.70710677)) - z2j;
  v182 = data[3];
  data[42] = (float)(tmp7i - (float)((float)(tmp5i + tmp6j) * 0.70710677)) + z2j;
  data[10] = v180 + z4j;
  v183 = data[59];
  data[58] = v180 - z4j;
  v184 = v182;
  v185 = v182 - v183;
  v186 = v184 + v183;
  v187 = data[11];
  tmp7j = v185;
  data[26] = v181;
  v188 = data[51];
  tmp6k = v187 - v188;
  v291 = data[19];
  v189 = v187 + v188;
  v190 = data[43];
  tmp2j = v291 + v190;
  v191 = v291 - v190;
  v192 = data[35];
  tmp5j = v191;
  v292 = data[27];
  tmp3f = v292 + v192;
  v193 = v292 - v192;
  v194 = tmp2j + v189;
  tmp4j = v193;
  v195 = tmp3f + v186;
  v196 = v186 - tmp3f;
  v197 = (float)((float)(v189 - tmp2j) + v196) * 0.70710677;
  data[35] = v195 - v194;
  data[51] = v196 - v197;
  data[19] = v197 + v196;
  data[3] = v194 + v195;
  v198 = (float)((float)(tmp4j + tmp5j) - (float)(tmp6k + tmp7j)) * 0.38268343;
  z4k = (float)((float)(tmp6k + tmp7j) * 1.306563) + v198;
  z2k = (float)((float)(tmp4j + tmp5j) * 0.54119611) + v198;
  v199 = (float)((float)(tmp5j + tmp6k) * 0.70710677) + tmp7j;
  data[43] = (float)(tmp7j - (float)((float)(tmp5j + tmp6k) * 0.70710677)) + z2k;
  data[27] = (float)(tmp7j - (float)((float)(tmp5j + tmp6k) * 0.70710677)) - z2k;
  v200 = data[4];
  v201 = data[52];
  data[11] = v199 + z4k;
  v202 = data[60];
  data[59] = v199 - z4k;
  v203 = v200;
  v204 = v200 - v202;
  v205 = v203 + v202;
  v206 = data[12];
  tmp7k = v204;
  tmp6l = v206 - v201;
  v293 = data[20];
  v207 = v206 + v201;
  v208 = data[44];
  tmp2k = v293 + v208;
  v209 = v293 - v208;
  v210 = data[36];
  tmp5k = v209;
  v294 = data[28];
  tmp3g = v294 + v210;
  v211 = v294 - v210;
  v212 = tmp2k + v207;
  tmp4k = v211;
  v213 = tmp3g + v205;
  v214 = v205 - tmp3g;
  v215 = (float)((float)(v207 - tmp2k) + v214) * 0.70710677;
  data[36] = v213 - v212;
  data[52] = v214 - v215;
  data[20] = v215 + v214;
  data[4] = v212 + v213;
  v216 = (float)((float)(tmp4k + tmp5k) - (float)(tmp6l + tmp7k)) * 0.38268343;
  z4l = (float)((float)(tmp6l + tmp7k) * 1.306563) + v216;
  z2l = (float)((float)(tmp4k + tmp5k) * 0.54119611) + v216;
  v217 = (float)((float)(tmp5k + tmp6l) * 0.70710677) + tmp7k;
  v218 = data[5];
  data[44] = (float)(tmp7k - (float)((float)(tmp5k + tmp6l) * 0.70710677)) + z2l;
  data[12] = v217 + z4l;
  v219 = data[61];
  data[28] = (float)(tmp7k - (float)((float)(tmp5k + tmp6l) * 0.70710677)) - z2l;
  data[60] = v217 - z4l;
  v220 = data[53];
  v221 = v218;
  v222 = v218 - v219;
  v223 = v221 + v219;
  v224 = data[13];
  tmp7l = v222;
  tmp6m = v224 - v220;
  v225 = v224 + v220;
  v226 = data[45];
  v295 = data[21];
  tmp2l = v295 + v226;
  v227 = v295 - v226;
  v228 = data[37];
  tmp5l = v227;
  v296 = data[29];
  tmp3h = v296 + v228;
  v229 = v296 - v228;
  v230 = tmp2l + v225;
  tmp4l = v229;
  v231 = tmp3h + v223;
  v232 = v223 - tmp3h;
  v233 = (float)((float)(v225 - tmp2l) + v232) * 0.70710677;
  data[37] = v231 - v230;
  data[53] = v232 - v233;
  data[21] = v233 + v232;
  data[5] = v230 + v231;
  v234 = (float)((float)(tmp4l + tmp5l) - (float)(tmp6m + tmp7l)) * 0.38268343;
  z4m = (float)((float)(tmp6m + tmp7l) * 1.306563) + v234;
  z2m = (float)((float)(tmp4l + tmp5l) * 0.54119611) + v234;
  v235 = (float)((float)(tmp5l + tmp6m) * 0.70710677) + tmp7l;
  v236 = data[6];
  data[45] = (float)(tmp7l - (float)((float)(tmp5l + tmp6m) * 0.70710677)) + z2m;
  data[61] = v235 - z4m;
  data[13] = v235 + z4m;
  v237 = data[62];
  data[29] = (float)(tmp7l - (float)((float)(tmp5l + tmp6m) * 0.70710677)) - z2m;
  v238 = data[54];
  v239 = v236 + v237;
  tmp7m = v236 - v237;
  v240 = data[14];
  tmp6n = v240 - v238;
  v241 = v240 + v238;
  v242 = data[46];
  v297 = data[22];
  tmp2m = v297 + v242;
  v243 = v297 - v242;
  v244 = data[38];
  tmp5m = v243;
  v298 = data[30];
  tmp3i = v298 + v244;
  v245 = v298 - v244;
  v246 = tmp2m + v241;
  tmp4m = v245;
  v247 = tmp3i + v239;
  v248 = v239 - tmp3i;
  v249 = (float)((float)(v241 - tmp2m) + v248) * 0.70710677;
  data[38] = v247 - v246;
  data[54] = v248 - v249;
  data[22] = v249 + v248;
  data[6] = v246 + v247;
  v250 = (float)((float)(tmp4m + tmp5m) - (float)(tmp6n + tmp7m)) * 0.38268343;
  z4n = (float)((float)(tmp6n + tmp7m) * 1.306563) + v250;
  z2n = (float)((float)(tmp4m + tmp5m) * 0.54119611) + v250;
  v251 = (float)((float)(tmp5m + tmp6n) * 0.70710677) + tmp7m;
  v252 = data[7];
  v253 = (float)(tmp7m - (float)((float)(tmp5m + tmp6n) * 0.70710677)) - z2n;
  data[46] = (float)(tmp7m - (float)((float)(tmp5m + tmp6n) * 0.70710677)) + z2n;
  data[14] = v251 + z4n;
  v254 = data[63];
  data[62] = v251 - z4n;
  v255 = v252;
  v256 = v252 - v254;
  v257 = v255 + v254;
  v258 = data[15];
  tmp7n = v256;
  data[30] = v253;
  v259 = data[55];
  v260 = v258 + v259;
  tmp6o = v258 - v259;
  v261 = data[47];
  v299 = data[23];
  tmp2n = v299 + v261;
  v262 = v299 - v261;
  v263 = data[39];
  tmp5n = v262;
  v300 = data[31];
  tmp3j = v300 + v263;
  v264 = v300 - v263;
  v265 = tmp2n + v260;
  tmp4n = v264;
  v266 = tmp3j + v257;
  v267 = v257 - tmp3j;
  v268 = (float)((float)(v260 - tmp2n) + v267) * 0.70710677;
  data[39] = v266 - v265;
  data[55] = v267 - v268;
  data[7] = v265 + v266;
  data[23] = v268 + v267;
  v269 = (float)((float)(tmp4n + tmp5n) - (float)(tmp6o + tmp7n)) * 0.38268343;
  v270 = (float)(tmp5n + tmp6o) * 0.70710677;
  v271 = (float)((float)(tmp4n + tmp5n) * 0.54119611) + v269;
  data[47] = (float)(tmp7n - v270) + v271;
  v272 = (float)((float)(tmp6o + tmp7n) * 1.306563) + v269;
  data[31] = (float)(tmp7n - v270) - v271;
  data[15] = (float)(v270 + tmp7n) + v272;
  data[63] = (float)(v270 + tmp7n) - v272;
}

//------------------------------------------------------------------------------
// Address: 0x0040EE88
// Name: _XMLParser_GetNamedItem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl XMLParser_GetNamedItem(int a1, int a2)
{
  return _XMLParser_GetNamedItem(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0040EE8E
// Name: _XMLParser_Free
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl XMLParser_Free(int a1)
{
  return _XMLParser_Free(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0040EE94
// Name: _XMLParser_Parse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl XMLParser_Parse(int a1, int a2, int a3, int a4)
{
  return _XMLParser_Parse(a1, a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x0040EE9A
// Name: _XMLParser_Create
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl XMLParser_Create(int a1)
{
  return _XMLParser_Create(a1);
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x00436B10
// Name: _jpeg_fdct_float
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_fdct_float(float *data)
{
  float v2; // xmm6_4
  float v3; // xmm5_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm6_4
  float v10; // xmm2_4
  float v11; // xmm7_4
  float v12; // xmm5_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm7_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm4_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm5_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm4_4
  float v27; // xmm6_4
  float v28; // xmm6_4
  float v29; // xmm5_4
  float v30; // xmm7_4
  float v31; // xmm4_4
  float v32; // xmm6_4
  float v33; // xmm5_4
  float v34; // xmm4_4
  float v35; // xmm7_4
  float v36; // xmm6_4
  float v37; // xmm5_4
  float v38; // xmm4_4
  float v39; // xmm6_4
  float v40; // xmm6_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm4_4
  float v44; // xmm6_4
  float v45; // xmm5_4
  float v46; // xmm4_4
  float v47; // xmm7_4
  float v48; // xmm6_4
  float v49; // xmm5_4
  float v50; // xmm4_4
  float v51; // xmm6_4
  float v52; // xmm5_4
  float v53; // xmm7_4
  float v54; // xmm4_4
  float v55; // xmm6_4
  float v56; // xmm5_4
  float v57; // xmm4_4
  float v58; // xmm6_4
  float v59; // xmm7_4
  float v60; // xmm5_4
  float v61; // xmm4_4
  float v62; // xmm5_4
  float v63; // xmm6_4
  float v64; // xmm4_4
  float v65; // xmm7_4
  float v66; // xmm6_4
  float v67; // xmm7_4
  float v68; // xmm6_4
  float v69; // xmm5_4
  float v70; // xmm4_4
  float v71; // xmm6_4
  float v72; // xmm5_4
  float v73; // xmm7_4
  float v74; // xmm4_4
  float v75; // xmm6_4
  float v76; // xmm7_4
  float v77; // xmm5_4
  float v78; // xmm4_4
  float v79; // xmm5_4
  float v80; // xmm6_4
  float v81; // xmm4_4
  float v82; // xmm7_4
  float v83; // xmm6_4
  float v84; // xmm7_4
  float v85; // xmm7_4
  float v86; // xmm6_4
  float v87; // xmm5_4
  float v88; // xmm4_4
  float v89; // xmm6_4
  float v90; // xmm5_4
  float v91; // xmm7_4
  float v92; // xmm4_4
  float v93; // xmm6_4
  float v94; // xmm5_4
  float v95; // xmm4_4
  float v96; // xmm5_4
  float v97; // xmm6_4
  float v98; // xmm7_4
  float v99; // xmm4_4
  float v100; // xmm7_4
  float v101; // xmm6_4
  float v102; // xmm7_4
  float v103; // xmm6_4
  float v104; // xmm5_4
  float v105; // xmm7_4
  float v106; // xmm4_4
  float v107; // xmm6_4
  float v108; // xmm5_4
  float v109; // xmm4_4
  float v110; // xmm7_4
  float v111; // xmm6_4
  float v112; // xmm5_4
  float v113; // xmm4_4
  float v114; // xmm5_4
  float v115; // xmm6_4
  float v116; // xmm7_4
  float v117; // xmm4_4
  float v118; // xmm7_4
  float v119; // xmm6_4
  float v120; // xmm7_4
  float v121; // xmm6_4
  float v122; // xmm5_4
  float v123; // xmm7_4
  float v124; // xmm4_4
  float v125; // xmm6_4
  float v126; // xmm5_4
  float v127; // xmm7_4
  float v128; // xmm6_4
  float v129; // xmm7_4
  float v130; // xmm4_4
  float v131; // xmm5_4
  float v132; // xmm6_4
  float v133; // xmm4_4
  float v134; // xmm7_4
  float v135; // xmm6_4
  float v136; // xmm7_4
  float v137; // xmm6_4
  float v138; // xmm5_4
  float v139; // xmm7_4
  float v140; // xmm4_4
  float v141; // xmm6_4
  float v142; // xmm5_4
  float v143; // xmm4_4
  float v144; // xmm7_4
  float v145; // xmm6_4
  float v146; // xmm5_4
  float v147; // xmm4_4
  float v148; // xmm5_4
  float v149; // xmm6_4
  float v150; // xmm7_4
  float v151; // xmm4_4
  float v152; // xmm7_4
  float v153; // xmm6_4
  float v154; // xmm7_4
  float v155; // xmm6_4
  float v156; // xmm7_4
  float v157; // xmm6_4
  float v158; // xmm5_4
  float v159; // xmm4_4
  float v160; // xmm6_4
  float v161; // xmm5_4
  float v162; // xmm4_4
  float v163; // xmm7_4
  float v164; // xmm6_4
  float v165; // xmm5_4
  float v166; // xmm4_4
  float v167; // xmm5_4
  float v168; // xmm6_4
  float v169; // xmm7_4
  float v170; // xmm4_4
  float v171; // xmm7_4
  float v172; // xmm6_4
  float v173; // xmm7_4
  float v174; // xmm6_4
  float v175; // xmm7_4
  float v176; // xmm6_4
  float v177; // xmm5_4
  float v178; // xmm4_4
  float v179; // xmm6_4
  float v180; // xmm5_4
  float v181; // xmm7_4
  float v182; // xmm4_4
  float v183; // xmm6_4
  float v184; // xmm5_4
  float v185; // xmm4_4
  float v186; // xmm5_4
  float v187; // xmm6_4
  float v188; // xmm7_4
  float v189; // xmm4_4
  float v190; // xmm7_4
  float v191; // xmm6_4
  float v192; // xmm7_4
  float v193; // xmm6_4
  float v194; // xmm7_4
  float v195; // xmm6_4
  float v196; // xmm5_4
  float v197; // xmm4_4
  float v198; // xmm6_4
  float v199; // xmm5_4
  float v200; // xmm4_4
  float v201; // xmm7_4
  float v202; // xmm6_4
  float v203; // xmm5_4
  float v204; // xmm4_4
  float v205; // xmm5_4
  float v206; // xmm6_4
  float v207; // xmm4_4
  float v208; // xmm7_4
  float v209; // xmm6_4
  float v210; // xmm7_4
  float v211; // xmm6_4
  float v212; // xmm7_4
  float v213; // xmm6_4
  float v214; // xmm5_4
  float v215; // xmm4_4
  float v216; // xmm6_4
  float v217; // xmm5_4
  float v218; // xmm4_4
  float v219; // xmm6_4
  float v220; // xmm7_4
  float v221; // xmm5_4
  float v222; // xmm4_4
  float v223; // xmm5_4
  float v224; // xmm6_4
  float v225; // xmm4_4
  float v226; // xmm7_4
  float v227; // xmm6_4
  float v228; // xmm7_4
  float v229; // xmm6_4
  float v230; // xmm7_4
  float v231; // xmm6_4
  float v232; // xmm5_4
  float v233; // xmm4_4
  float v234; // xmm6_4
  float v235; // xmm5_4
  float v236; // xmm4_4
  float v237; // xmm6_4
  float v238; // xmm7_4
  float v239; // xmm5_4
  float v240; // xmm4_4
  float v241; // xmm4_4
  float v242; // xmm7_4
  float v243; // xmm6_4
  float v244; // xmm7_4
  float v245; // xmm6_4
  float v246; // xmm7_4
  float v247; // xmm6_4
  float v248; // xmm5_4
  float v249; // xmm4_4
  float v250; // xmm6_4
  float v251; // xmm5_4
  float v252; // xmm4_4
  float v253; // xmm7_4
  float v254; // xmm6_4
  float v255; // xmm5_4
  float v256; // xmm4_4
  float v257; // xmm5_4
  float v258; // xmm6_4
  float v259; // xmm7_4
  float v260; // xmm4_4
  float v261; // xmm7_4
  float v262; // xmm6_4
  float v263; // xmm7_4
  float v264; // xmm6_4
  float v265; // xmm7_4
  float v266; // xmm6_4
  float v267; // xmm5_4
  float v268; // xmm4_4
  float v269; // xmm6_4
  float v270; // xmm1_4
  float v271; // xmm5_4
  float v272; // xmm4_4
  float v273; // [esp+0h] [ebp-24h]
  float v274; // [esp+0h] [ebp-24h]
  float v275; // [esp+0h] [ebp-24h]
  float v276; // [esp+0h] [ebp-24h]
  float v277; // [esp+0h] [ebp-24h]
  float v278; // [esp+0h] [ebp-24h]
  float v279; // [esp+0h] [ebp-24h]
  float v280; // [esp+0h] [ebp-24h]
  float v281; // [esp+0h] [ebp-24h]
  float v282; // [esp+0h] [ebp-24h]
  float v283; // [esp+0h] [ebp-24h]
  float v284; // [esp+0h] [ebp-24h]
  float v285; // [esp+0h] [ebp-24h]
  float v286; // [esp+0h] [ebp-24h]
  float v287; // [esp+0h] [ebp-24h]
  float v288; // [esp+0h] [ebp-24h]
  float v289; // [esp+0h] [ebp-24h]
  float v290; // [esp+0h] [ebp-24h]
  float v291; // [esp+0h] [ebp-24h]
  float v292; // [esp+0h] [ebp-24h]
  float v293; // [esp+0h] [ebp-24h]
  float v294; // [esp+0h] [ebp-24h]
  float v295; // [esp+0h] [ebp-24h]
  float v296; // [esp+0h] [ebp-24h]
  float v297; // [esp+0h] [ebp-24h]
  float v298; // [esp+0h] [ebp-24h]
  float v299; // [esp+0h] [ebp-24h]
  float v300; // [esp+0h] [ebp-24h]
  float tmp7; // [esp+4h] [ebp-20h]
  float tmp7a; // [esp+4h] [ebp-20h]
  float tmp7b; // [esp+4h] [ebp-20h]
  float tmp7c; // [esp+4h] [ebp-20h]
  float tmp7d; // [esp+4h] [ebp-20h]
  float tmp7e; // [esp+4h] [ebp-20h]
  float tmp7f; // [esp+4h] [ebp-20h]
  float tmp7g; // [esp+4h] [ebp-20h]
  float tmp7h; // [esp+4h] [ebp-20h]
  float tmp7i; // [esp+4h] [ebp-20h]
  float tmp7j; // [esp+4h] [ebp-20h]
  float tmp7k; // [esp+4h] [ebp-20h]
  float tmp7l; // [esp+4h] [ebp-20h]
  float tmp7m; // [esp+4h] [ebp-20h]
  float tmp7n; // [esp+4h] [ebp-20h]
  float tmp11; // [esp+8h] [ebp-1Ch]
  float tmp3; // [esp+Ch] [ebp-18h]
  float tmp3a; // [esp+Ch] [ebp-18h]
  float tmp3b; // [esp+Ch] [ebp-18h]
  float tmp3c; // [esp+Ch] [ebp-18h]
  float tmp3d; // [esp+Ch] [ebp-18h]
  float tmp3e; // [esp+Ch] [ebp-18h]
  float tmp3f; // [esp+Ch] [ebp-18h]
  float tmp3g; // [esp+Ch] [ebp-18h]
  float tmp3h; // [esp+Ch] [ebp-18h]
  float tmp3i; // [esp+Ch] [ebp-18h]
  float tmp3j; // [esp+Ch] [ebp-18h]
  float z4; // [esp+10h] [ebp-14h]
  float z4a; // [esp+10h] [ebp-14h]
  float z4b; // [esp+10h] [ebp-14h]
  float z4c; // [esp+10h] [ebp-14h]
  float z4d; // [esp+10h] [ebp-14h]
  float z4e; // [esp+10h] [ebp-14h]
  float z4f; // [esp+10h] [ebp-14h]
  float z4g; // [esp+10h] [ebp-14h]
  float z4h; // [esp+10h] [ebp-14h]
  float z4i; // [esp+10h] [ebp-14h]
  float z4j; // [esp+10h] [ebp-14h]
  float z4k; // [esp+10h] [ebp-14h]
  float z4l; // [esp+10h] [ebp-14h]
  float z4m; // [esp+10h] [ebp-14h]
  float z4n; // [esp+10h] [ebp-14h]
  float z2; // [esp+14h] [ebp-10h]
  float z2a; // [esp+14h] [ebp-10h]
  float z2b; // [esp+14h] [ebp-10h]
  float z2c; // [esp+14h] [ebp-10h]
  float z2d; // [esp+14h] [ebp-10h]
  float z2e; // [esp+14h] [ebp-10h]
  float z2f; // [esp+14h] [ebp-10h]
  float z2g; // [esp+14h] [ebp-10h]
  float z2h; // [esp+14h] [ebp-10h]
  float z2i; // [esp+14h] [ebp-10h]
  float z2j; // [esp+14h] [ebp-10h]
  float z2k; // [esp+14h] [ebp-10h]
  float z2l; // [esp+14h] [ebp-10h]
  float z2m; // [esp+14h] [ebp-10h]
  float z2n; // [esp+14h] [ebp-10h]
  float tmp4; // [esp+18h] [ebp-Ch]
  float tmp4a; // [esp+18h] [ebp-Ch]
  float tmp4b; // [esp+18h] [ebp-Ch]
  float tmp4c; // [esp+18h] [ebp-Ch]
  float tmp4d; // [esp+18h] [ebp-Ch]
  float tmp4e; // [esp+18h] [ebp-Ch]
  float tmp4f; // [esp+18h] [ebp-Ch]
  float tmp4g; // [esp+18h] [ebp-Ch]
  float tmp4h; // [esp+18h] [ebp-Ch]
  float tmp4i; // [esp+18h] [ebp-Ch]
  float tmp4j; // [esp+18h] [ebp-Ch]
  float tmp4k; // [esp+18h] [ebp-Ch]
  float tmp4l; // [esp+18h] [ebp-Ch]
  float tmp4m; // [esp+18h] [ebp-Ch]
  float tmp4n; // [esp+18h] [ebp-Ch]
  float tmp5; // [esp+1Ch] [ebp-8h]
  float tmp5a; // [esp+1Ch] [ebp-8h]
  float tmp5b; // [esp+1Ch] [ebp-8h]
  float tmp5c; // [esp+1Ch] [ebp-8h]
  float tmp5d; // [esp+1Ch] [ebp-8h]
  float tmp5e; // [esp+1Ch] [ebp-8h]
  float tmp5f; // [esp+1Ch] [ebp-8h]
  float tmp5g; // [esp+1Ch] [ebp-8h]
  float tmp5h; // [esp+1Ch] [ebp-8h]
  float tmp5i; // [esp+1Ch] [ebp-8h]
  float tmp5j; // [esp+1Ch] [ebp-8h]
  float tmp5k; // [esp+1Ch] [ebp-8h]
  float tmp5l; // [esp+1Ch] [ebp-8h]
  float tmp5m; // [esp+1Ch] [ebp-8h]
  float tmp5n; // [esp+1Ch] [ebp-8h]
  float tmp2; // [esp+20h] [ebp-4h]
  float tmp2a; // [esp+20h] [ebp-4h]
  float tmp2b; // [esp+20h] [ebp-4h]
  float tmp2c; // [esp+20h] [ebp-4h]
  float tmp2d; // [esp+20h] [ebp-4h]
  float tmp2e; // [esp+20h] [ebp-4h]
  float tmp2f; // [esp+20h] [ebp-4h]
  float tmp2g; // [esp+20h] [ebp-4h]
  float tmp2h; // [esp+20h] [ebp-4h]
  float tmp2i; // [esp+20h] [ebp-4h]
  float tmp2j; // [esp+20h] [ebp-4h]
  float tmp2k; // [esp+20h] [ebp-4h]
  float tmp2l; // [esp+20h] [ebp-4h]
  float tmp2m; // [esp+20h] [ebp-4h]
  float tmp2n; // [esp+20h] [ebp-4h]
  float tmp6; // [esp+2Ch] [ebp+8h]
  float tmp6a; // [esp+2Ch] [ebp+8h]
  float tmp6b; // [esp+2Ch] [ebp+8h]
  float tmp6c; // [esp+2Ch] [ebp+8h]
  float tmp6d; // [esp+2Ch] [ebp+8h]
  float tmp6e; // [esp+2Ch] [ebp+8h]
  float tmp6f; // [esp+2Ch] [ebp+8h]
  float tmp6g; // [esp+2Ch] [ebp+8h]
  float tmp6h; // [esp+2Ch] [ebp+8h]
  float tmp6i; // [esp+2Ch] [ebp+8h]
  float tmp6j; // [esp+2Ch] [ebp+8h]
  float tmp6k; // [esp+2Ch] [ebp+8h]
  float tmp6l; // [esp+2Ch] [ebp+8h]
  float tmp6m; // [esp+2Ch] [ebp+8h]
  float tmp6n; // [esp+2Ch] [ebp+8h]
  float tmp6o; // [esp+2Ch] [ebp+8h]

  v2 = *data;
  v3 = data[2];
  v4 = data[1];
  v5 = v4 - data[6];
  v6 = v4 + data[6];
  tmp6 = v5;
  v7 = data[3] + data[4];
  v8 = v2 + data[7];
  v9 = v2 - data[7];
  tmp4 = data[3] - data[4];
  v10 = v7 + v8;
  v11 = v3 + data[5];
  v12 = v3 - data[5];
  v13 = v8 - v7;
  *data = (float)(v11 + v6) + v10;
  data[4] = v10 - (float)(v11 + v6);
  v14 = (float)((float)(v6 - v11) + v13) * 0.70710677;
  data[6] = v13 - v14;
  v15 = (float)((float)(tmp4 + v12) - (float)(tmp6 + v9)) * 0.38268343;
  data[2] = v14 + v13;
  z2 = (float)((float)(tmp4 + v12) * 0.54119611) + v15;
  z4 = (float)((float)(tmp6 + v9) * 1.306563) + v15;
  v16 = (float)(v12 + tmp6) * 0.70710677;
  v17 = v16 + v9;
  v18 = v9 - v16;
  v19 = data[8];
  v20 = v18 + z2;
  data[3] = v18 - z2;
  v21 = v17 + z4;
  data[7] = v17 - z4;
  v22 = v19;
  v23 = v19 - data[15];
  v24 = v22 + data[15];
  data[1] = v21;
  v25 = data[9];
  tmp7 = v23;
  v26 = v25 + data[14];
  tmp6a = v25 - data[14];
  v27 = data[10];
  data[5] = v20;
  tmp2 = v27 + data[13];
  tmp5 = v27 - data[13];
  tmp11 = data[11];
  tmp3 = tmp11 + data[12];
  tmp4a = tmp11 - data[12];
  v28 = tmp3 + v24;
  v29 = v24 - tmp3;
  v30 = tmp2 + v26;
  v31 = (float)((float)(v26 - tmp2) + v29) * 0.70710677;
  data[12] = v28 - v30;
  data[10] = v31 + v29;
  data[14] = v29 - v31;
  data[8] = v30 + v28;
  v32 = (float)((float)(tmp4a + tmp5) - (float)(tmp6a + tmp7)) * 0.38268343;
  z4a = (float)((float)(tmp6a + tmp7) * 1.306563) + v32;
  z2a = (float)((float)(tmp4a + tmp5) * 0.54119611) + v32;
  v33 = (float)((float)(tmp5 + tmp6a) * 0.70710677) + tmp7;
  v34 = data[16];
  v35 = (float)(tmp7 - (float)((float)(tmp5 + tmp6a) * 0.70710677)) - z2a;
  data[13] = (float)(tmp7 - (float)((float)(tmp5 + tmp6a) * 0.70710677)) + z2a;
  data[9] = v33 + z4a;
  v36 = data[17];
  data[15] = v33 - z4a;
  v37 = v34 + data[23];
  tmp7a = v34 - data[23];
  v38 = v36 + data[22];
  tmp6b = v36 - data[22];
  v273 = data[18];
  tmp2a = v273 + data[21];
  tmp5a = v273 - data[21];
  v274 = data[19];
  v39 = v274 + data[20];
  data[11] = v35;
  tmp3a = v39;
  tmp4b = v274 - data[20];
  v40 = v39 + v37;
  v41 = v37 - tmp3a;
  v42 = tmp2a + v38;
  v43 = (float)((float)(v38 - tmp2a) + v41) * 0.70710677;
  data[20] = v40 - v42;
  data[18] = v43 + v41;
  data[22] = v41 - v43;
  data[16] = v42 + v40;
  v44 = (float)((float)(tmp4b + tmp5a) - (float)(tmp6b + tmp7a)) * 0.38268343;
  z4b = (float)((float)(tmp6b + tmp7a) * 1.306563) + v44;
  z2b = (float)((float)(tmp4b + tmp5a) * 0.54119611) + v44;
  v45 = (float)((float)(tmp5a + tmp6b) * 0.70710677) + tmp7a;
  v46 = data[24];
  data[21] = (float)(tmp7a - (float)((float)(tmp5a + tmp6b) * 0.70710677)) + z2b;
  v47 = (float)(tmp7a - (float)((float)(tmp5a + tmp6b) * 0.70710677)) - z2b;
  data[17] = v45 + z4b;
  v48 = data[25];
  data[23] = v45 - z4b;
  v49 = v46 + data[31];
  tmp7b = v46 - data[31];
  v50 = v48 + data[30];
  tmp6c = v48 - data[30];
  v275 = data[26];
  tmp2b = v275 + data[29];
  tmp5b = v275 - data[29];
  v276 = data[27];
  tmp3b = v276 + data[28];
  tmp4c = v276 - data[28];
  data[19] = v47;
  v51 = tmp3b + v49;
  v52 = v49 - tmp3b;
  v53 = (float)(tmp2b + v50) + v51;
  data[28] = v51 - (float)(tmp2b + v50);
  v54 = (float)((float)(v50 - tmp2b) + v52) * 0.70710677;
  data[26] = v54 + v52;
  data[30] = v52 - v54;
  data[24] = v53;
  v55 = (float)((float)(tmp4c + tmp5b) - (float)(tmp6c + tmp7b)) * 0.38268343;
  z4c = (float)((float)(tmp6c + tmp7b) * 1.306563) + v55;
  z2c = (float)((float)(tmp4c + tmp5b) * 0.54119611) + v55;
  v56 = (float)((float)(tmp5b + tmp6c) * 0.70710677) + tmp7b;
  v57 = data[32];
  data[29] = (float)(tmp7b - (float)((float)(tmp5b + tmp6c) * 0.70710677)) + z2c;
  data[25] = v56 + z4c;
  v58 = data[39];
  data[27] = (float)(tmp7b - (float)((float)(tmp5b + tmp6c) * 0.70710677)) - z2c;
  v59 = data[38];
  data[31] = v56 - z4c;
  v60 = v57;
  v61 = v57 - v58;
  v62 = v60 + v58;
  v63 = data[33];
  tmp7c = v61;
  tmp6d = v63 - v59;
  v277 = data[34];
  v64 = v63 + v59;
  v65 = data[37];
  tmp2c = v277 + v65;
  v66 = v277 - v65;
  v67 = data[36];
  tmp5c = v66;
  v278 = data[35];
  v68 = (float)(v278 + v67) + v62;
  v69 = v62 - (float)(v278 + v67);
  data[32] = (float)(tmp2c + v64) + v68;
  data[36] = v68 - (float)(tmp2c + v64);
  v70 = (float)((float)(v64 - tmp2c) + v69) * 0.70710677;
  data[34] = v70 + v69;
  data[38] = v69 - v70;
  v71 = (float)((float)((float)(v278 - v67) + tmp5c) - (float)(tmp6d + tmp7c)) * 0.38268343;
  z4d = (float)((float)(tmp6d + tmp7c) * 1.306563) + v71;
  z2d = (float)((float)((float)(v278 - v67) + tmp5c) * 0.54119611) + v71;
  v72 = (float)((float)(tmp5c + tmp6d) * 0.70710677) + tmp7c;
  v73 = tmp7c - (float)((float)(tmp5c + tmp6d) * 0.70710677);
  v74 = data[40];
  data[37] = v73 + z2d;
  data[33] = v72 + z4d;
  v75 = data[47];
  data[35] = v73 - z2d;
  v76 = data[46];
  data[39] = v72 - z4d;
  v77 = v74;
  v78 = v74 - v75;
  v79 = v77 + v75;
  v80 = data[41];
  tmp7d = v78;
  tmp6e = v80 - v76;
  v279 = data[42];
  v81 = v80 + v76;
  v82 = data[45];
  tmp2d = v279 + v82;
  v83 = v279 - v82;
  v84 = data[44];
  tmp5d = v83;
  v280 = data[43];
  tmp3c = v280 + v84;
  tmp4d = v280 - v84;
  v85 = tmp2d + v81;
  v86 = tmp3c + v79;
  v87 = v79 - tmp3c;
  data[44] = v86 - (float)(tmp2d + v81);
  v88 = (float)((float)(v81 - tmp2d) + v87) * 0.70710677;
  data[40] = v85 + v86;
  data[42] = v88 + v87;
  data[46] = v87 - v88;
  v89 = (float)((float)(tmp4d + tmp5d) - (float)(tmp6e + tmp7d)) * 0.38268343;
  z4e = (float)((float)(tmp6e + tmp7d) * 1.306563) + v89;
  z2e = (float)((float)(tmp4d + tmp5d) * 0.54119611) + v89;
  v90 = (float)((float)(tmp5d + tmp6e) * 0.70710677) + tmp7d;
  v91 = tmp7d - (float)((float)(tmp5d + tmp6e) * 0.70710677);
  v92 = data[48];
  data[45] = v91 + z2e;
  data[41] = v90 + z4e;
  v93 = data[55];
  data[47] = v90 - z4e;
  v94 = v92;
  v95 = v92 - v93;
  v96 = v94 + v93;
  v97 = data[49];
  data[43] = v91 - z2e;
  v98 = data[54];
  tmp7e = v95;
  tmp6f = v97 - v98;
  v281 = data[50];
  v99 = v97 + v98;
  v100 = data[53];
  tmp2e = v281 + v100;
  v101 = v281 - v100;
  v102 = data[52];
  tmp5e = v101;
  v282 = data[51];
  tmp4e = v282 - v102;
  v103 = (float)(v282 + v102) + v96;
  v104 = v96 - (float)(v282 + v102);
  v105 = (float)(tmp2e + v99) + v103;
  data[52] = v103 - (float)(tmp2e + v99);
  v106 = (float)((float)(v99 - tmp2e) + v104) * 0.70710677;
  data[54] = v104 - v106;
  data[48] = v105;
  data[50] = v106 + v104;
  v107 = (float)((float)(tmp4e + tmp5e) - (float)(tmp6f + tmp7e)) * 0.38268343;
  z4f = (float)((float)(tmp6f + tmp7e) * 1.306563) + v107;
  z2f = (float)((float)(tmp4e + tmp5e) * 0.54119611) + v107;
  v108 = (float)((float)(tmp5e + tmp6f) * 0.70710677) + tmp7e;
  v109 = data[56];
  v110 = (float)(tmp7e - (float)((float)(tmp5e + tmp6f) * 0.70710677)) - z2f;
  data[53] = (float)(tmp7e - (float)((float)(tmp5e + tmp6f) * 0.70710677)) + z2f;
  data[49] = v108 + z4f;
  v111 = data[63];
  data[55] = v108 - z4f;
  v112 = v109;
  v113 = v109 - v111;
  v114 = v112 + v111;
  v115 = data[57];
  tmp7f = v113;
  data[51] = v110;
  v116 = data[62];
  tmp6g = v115 - v116;
  v283 = data[58];
  v117 = v115 + v116;
  v118 = data[61];
  tmp2f = v283 + v118;
  v119 = v283 - v118;
  v120 = data[60];
  tmp5f = v119;
  v284 = data[59];
  tmp4f = v284 - v120;
  v121 = (float)(v284 + v120) + v114;
  v122 = v114 - (float)(v284 + v120);
  v123 = (float)(tmp2f + v117) + v121;
  data[60] = v121 - (float)(tmp2f + v117);
  v124 = (float)((float)(v117 - tmp2f) + v122) * 0.70710677;
  data[62] = v122 - v124;
  data[56] = v123;
  data[58] = v124 + v122;
  v125 = (float)((float)(tmp4f + tmp5f) - (float)(tmp6g + tmp7f)) * 0.38268343;
  z4g = (float)((float)(tmp6g + tmp7f) * 1.306563) + v125;
  z2g = (float)((float)(tmp4f + tmp5f) * 0.54119611) + v125;
  v126 = (float)((float)(tmp5f + tmp6g) * 0.70710677) + tmp7f;
  v127 = tmp7f - (float)((float)(tmp5f + tmp6g) * 0.70710677);
  data[61] = v127 + z2g;
  data[59] = v127 - z2g;
  data[57] = v126 + z4g;
  data[63] = v126 - z4g;
  v128 = data[56];
  v129 = data[48];
  v130 = *data - v128;
  v131 = *data + v128;
  v132 = data[8];
  tmp7g = v130;
  tmp6h = v132 - v129;
  v285 = data[16];
  v133 = v132 + v129;
  v134 = data[40];
  tmp2g = v285 + v134;
  v135 = v285 - v134;
  v136 = data[32];
  tmp5g = v135;
  v286 = data[24];
  tmp4g = v286 - v136;
  v137 = (float)(v286 + v136) + v131;
  v138 = v131 - (float)(v286 + v136);
  v139 = (float)(tmp2g + v133) + v137;
  data[32] = v137 - (float)(tmp2g + v133);
  v140 = (float)((float)(v133 - tmp2g) + v138) * 0.70710677;
  data[48] = v138 - v140;
  data[16] = v140 + v138;
  *data = v139;
  v141 = (float)((float)(tmp4g + tmp5g) - (float)(tmp6h + tmp7g)) * 0.38268343;
  z2h = (float)((float)(tmp4g + tmp5g) * 0.54119611) + v141;
  z4h = (float)((float)(tmp6h + tmp7g) * 1.306563) + v141;
  v142 = (float)((float)(tmp5g + tmp6h) * 0.70710677) + tmp7g;
  v143 = data[1];
  v144 = (float)(tmp7g - (float)((float)(tmp5g + tmp6h) * 0.70710677)) - z2h;
  data[40] = (float)(tmp7g - (float)((float)(tmp5g + tmp6h) * 0.70710677)) + z2h;
  data[8] = v142 + z4h;
  v145 = data[57];
  data[56] = v142 - z4h;
  v146 = v143;
  v147 = v143 - v145;
  v148 = v146 + v145;
  v149 = data[9];
  tmp7h = v147;
  data[24] = v144;
  v150 = data[49];
  tmp6i = v149 - v150;
  v151 = v149 + v150;
  v152 = data[41];
  v287 = data[17];
  tmp2h = v287 + v152;
  v153 = v287 - v152;
  v154 = data[33];
  tmp5h = v153;
  v288 = data[25];
  tmp3d = v288 + v154;
  v155 = v288 - v154;
  v156 = tmp2h + v151;
  tmp4h = v155;
  v157 = tmp3d + v148;
  v158 = v148 - tmp3d;
  v159 = (float)((float)(v151 - tmp2h) + v158) * 0.70710677;
  data[33] = v157 - v156;
  data[49] = v158 - v159;
  data[17] = v159 + v158;
  data[1] = v156 + v157;
  v160 = (float)((float)(tmp4h + tmp5h) - (float)(tmp6i + tmp7h)) * 0.38268343;
  z4i = (float)((float)(tmp6i + tmp7h) * 1.306563) + v160;
  z2i = (float)((float)(tmp4h + tmp5h) * 0.54119611) + v160;
  v161 = (float)((float)(tmp5h + tmp6i) * 0.70710677) + tmp7h;
  v162 = data[2];
  v163 = (float)(tmp7h - (float)((float)(tmp5h + tmp6i) * 0.70710677)) - z2i;
  data[41] = (float)(tmp7h - (float)((float)(tmp5h + tmp6i) * 0.70710677)) + z2i;
  data[9] = v161 + z4i;
  v164 = data[58];
  data[57] = v161 - z4i;
  v165 = v162;
  v166 = v162 - v164;
  v167 = v165 + v164;
  v168 = data[10];
  tmp7i = v166;
  data[25] = v163;
  v169 = data[50];
  tmp6j = v168 - v169;
  v170 = v168 + v169;
  v171 = data[42];
  v289 = data[18];
  tmp2i = v289 + v171;
  v172 = v289 - v171;
  v173 = data[34];
  tmp5i = v172;
  v290 = data[26];
  tmp3e = v290 + v173;
  v174 = v290 - v173;
  v175 = tmp2i + v170;
  tmp4i = v174;
  v176 = tmp3e + v167;
  v177 = v167 - tmp3e;
  v178 = (float)((float)(v170 - tmp2i) + v177) * 0.70710677;
  data[34] = v176 - v175;
  data[50] = v177 - v178;
  data[18] = v178 + v177;
  data[2] = v175 + v176;
  v179 = (float)((float)(tmp4i + tmp5i) - (float)(tmp6j + tmp7i)) * 0.38268343;
  z4j = (float)((float)(tmp6j + tmp7i) * 1.306563) + v179;
  z2j = (float)((float)(tmp4i + tmp5i) * 0.54119611) + v179;
  v180 = (float)((float)(tmp5i + tmp6j) * 0.70710677) + tmp7i;
  v181 = (float)(tmp7i - (float)((float)(tmp5i + tmp6j) * 0.70710677)) - z2j;
  v182 = data[3];
  data[42] = (float)(tmp7i - (float)((float)(tmp5i + tmp6j) * 0.70710677)) + z2j;
  data[10] = v180 + z4j;
  v183 = data[59];
  data[58] = v180 - z4j;
  v184 = v182;
  v185 = v182 - v183;
  v186 = v184 + v183;
  v187 = data[11];
  tmp7j = v185;
  data[26] = v181;
  v188 = data[51];
  tmp6k = v187 - v188;
  v291 = data[19];
  v189 = v187 + v188;
  v190 = data[43];
  tmp2j = v291 + v190;
  v191 = v291 - v190;
  v192 = data[35];
  tmp5j = v191;
  v292 = data[27];
  tmp3f = v292 + v192;
  v193 = v292 - v192;
  v194 = tmp2j + v189;
  tmp4j = v193;
  v195 = tmp3f + v186;
  v196 = v186 - tmp3f;
  v197 = (float)((float)(v189 - tmp2j) + v196) * 0.70710677;
  data[35] = v195 - v194;
  data[51] = v196 - v197;
  data[19] = v197 + v196;
  data[3] = v194 + v195;
  v198 = (float)((float)(tmp4j + tmp5j) - (float)(tmp6k + tmp7j)) * 0.38268343;
  z4k = (float)((float)(tmp6k + tmp7j) * 1.306563) + v198;
  z2k = (float)((float)(tmp4j + tmp5j) * 0.54119611) + v198;
  v199 = (float)((float)(tmp5j + tmp6k) * 0.70710677) + tmp7j;
  data[43] = (float)(tmp7j - (float)((float)(tmp5j + tmp6k) * 0.70710677)) + z2k;
  data[27] = (float)(tmp7j - (float)((float)(tmp5j + tmp6k) * 0.70710677)) - z2k;
  v200 = data[4];
  v201 = data[52];
  data[11] = v199 + z4k;
  v202 = data[60];
  data[59] = v199 - z4k;
  v203 = v200;
  v204 = v200 - v202;
  v205 = v203 + v202;
  v206 = data[12];
  tmp7k = v204;
  tmp6l = v206 - v201;
  v293 = data[20];
  v207 = v206 + v201;
  v208 = data[44];
  tmp2k = v293 + v208;
  v209 = v293 - v208;
  v210 = data[36];
  tmp5k = v209;
  v294 = data[28];
  tmp3g = v294 + v210;
  v211 = v294 - v210;
  v212 = tmp2k + v207;
  tmp4k = v211;
  v213 = tmp3g + v205;
  v214 = v205 - tmp3g;
  v215 = (float)((float)(v207 - tmp2k) + v214) * 0.70710677;
  data[36] = v213 - v212;
  data[52] = v214 - v215;
  data[20] = v215 + v214;
  data[4] = v212 + v213;
  v216 = (float)((float)(tmp4k + tmp5k) - (float)(tmp6l + tmp7k)) * 0.38268343;
  z4l = (float)((float)(tmp6l + tmp7k) * 1.306563) + v216;
  z2l = (float)((float)(tmp4k + tmp5k) * 0.54119611) + v216;
  v217 = (float)((float)(tmp5k + tmp6l) * 0.70710677) + tmp7k;
  v218 = data[5];
  data[44] = (float)(tmp7k - (float)((float)(tmp5k + tmp6l) * 0.70710677)) + z2l;
  data[12] = v217 + z4l;
  v219 = data[61];
  data[28] = (float)(tmp7k - (float)((float)(tmp5k + tmp6l) * 0.70710677)) - z2l;
  data[60] = v217 - z4l;
  v220 = data[53];
  v221 = v218;
  v222 = v218 - v219;
  v223 = v221 + v219;
  v224 = data[13];
  tmp7l = v222;
  tmp6m = v224 - v220;
  v225 = v224 + v220;
  v226 = data[45];
  v295 = data[21];
  tmp2l = v295 + v226;
  v227 = v295 - v226;
  v228 = data[37];
  tmp5l = v227;
  v296 = data[29];
  tmp3h = v296 + v228;
  v229 = v296 - v228;
  v230 = tmp2l + v225;
  tmp4l = v229;
  v231 = tmp3h + v223;
  v232 = v223 - tmp3h;
  v233 = (float)((float)(v225 - tmp2l) + v232) * 0.70710677;
  data[37] = v231 - v230;
  data[53] = v232 - v233;
  data[21] = v233 + v232;
  data[5] = v230 + v231;
  v234 = (float)((float)(tmp4l + tmp5l) - (float)(tmp6m + tmp7l)) * 0.38268343;
  z4m = (float)((float)(tmp6m + tmp7l) * 1.306563) + v234;
  z2m = (float)((float)(tmp4l + tmp5l) * 0.54119611) + v234;
  v235 = (float)((float)(tmp5l + tmp6m) * 0.70710677) + tmp7l;
  v236 = data[6];
  data[45] = (float)(tmp7l - (float)((float)(tmp5l + tmp6m) * 0.70710677)) + z2m;
  data[61] = v235 - z4m;
  data[13] = v235 + z4m;
  v237 = data[62];
  data[29] = (float)(tmp7l - (float)((float)(tmp5l + tmp6m) * 0.70710677)) - z2m;
  v238 = data[54];
  v239 = v236 + v237;
  tmp7m = v236 - v237;
  v240 = data[14];
  tmp6n = v240 - v238;
  v241 = v240 + v238;
  v242 = data[46];
  v297 = data[22];
  tmp2m = v297 + v242;
  v243 = v297 - v242;
  v244 = data[38];
  tmp5m = v243;
  v298 = data[30];
  tmp3i = v298 + v244;
  v245 = v298 - v244;
  v246 = tmp2m + v241;
  tmp4m = v245;
  v247 = tmp3i + v239;
  v248 = v239 - tmp3i;
  v249 = (float)((float)(v241 - tmp2m) + v248) * 0.70710677;
  data[38] = v247 - v246;
  data[54] = v248 - v249;
  data[22] = v249 + v248;
  data[6] = v246 + v247;
  v250 = (float)((float)(tmp4m + tmp5m) - (float)(tmp6n + tmp7m)) * 0.38268343;
  z4n = (float)((float)(tmp6n + tmp7m) * 1.306563) + v250;
  z2n = (float)((float)(tmp4m + tmp5m) * 0.54119611) + v250;
  v251 = (float)((float)(tmp5m + tmp6n) * 0.70710677) + tmp7m;
  v252 = data[7];
  v253 = (float)(tmp7m - (float)((float)(tmp5m + tmp6n) * 0.70710677)) - z2n;
  data[46] = (float)(tmp7m - (float)((float)(tmp5m + tmp6n) * 0.70710677)) + z2n;
  data[14] = v251 + z4n;
  v254 = data[63];
  data[62] = v251 - z4n;
  v255 = v252;
  v256 = v252 - v254;
  v257 = v255 + v254;
  v258 = data[15];
  tmp7n = v256;
  data[30] = v253;
  v259 = data[55];
  v260 = v258 + v259;
  tmp6o = v258 - v259;
  v261 = data[47];
  v299 = data[23];
  tmp2n = v299 + v261;
  v262 = v299 - v261;
  v263 = data[39];
  tmp5n = v262;
  v300 = data[31];
  tmp3j = v300 + v263;
  v264 = v300 - v263;
  v265 = tmp2n + v260;
  tmp4n = v264;
  v266 = tmp3j + v257;
  v267 = v257 - tmp3j;
  v268 = (float)((float)(v260 - tmp2n) + v267) * 0.70710677;
  data[39] = v266 - v265;
  data[55] = v267 - v268;
  data[7] = v265 + v266;
  data[23] = v268 + v267;
  v269 = (float)((float)(tmp4n + tmp5n) - (float)(tmp6o + tmp7n)) * 0.38268343;
  v270 = (float)(tmp5n + tmp6o) * 0.70710677;
  v271 = (float)((float)(tmp4n + tmp5n) * 0.54119611) + v269;
  data[47] = (float)(tmp7n - v270) + v271;
  v272 = (float)((float)(tmp6o + tmp7n) * 1.306563) + v269;
  data[31] = (float)(tmp7n - v270) - v271;
  data[15] = (float)(v270 + tmp7n) + v272;
  data[63] = (float)(v270 + tmp7n) - v272;
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x00423920
// Name: _jpeg_fdct_float
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_fdct_float(float *data)
{
  float v2; // xmm6_4
  float v3; // xmm5_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm6_4
  float v10; // xmm2_4
  float v11; // xmm7_4
  float v12; // xmm5_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm7_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm4_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm5_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm4_4
  float v27; // xmm6_4
  float v28; // xmm6_4
  float v29; // xmm5_4
  float v30; // xmm7_4
  float v31; // xmm4_4
  float v32; // xmm6_4
  float v33; // xmm5_4
  float v34; // xmm4_4
  float v35; // xmm7_4
  float v36; // xmm6_4
  float v37; // xmm5_4
  float v38; // xmm4_4
  float v39; // xmm6_4
  float v40; // xmm6_4
  float v41; // xmm5_4
  float v42; // xmm7_4
  float v43; // xmm4_4
  float v44; // xmm6_4
  float v45; // xmm5_4
  float v46; // xmm4_4
  float v47; // xmm7_4
  float v48; // xmm6_4
  float v49; // xmm5_4
  float v50; // xmm4_4
  float v51; // xmm6_4
  float v52; // xmm5_4
  float v53; // xmm7_4
  float v54; // xmm4_4
  float v55; // xmm6_4
  float v56; // xmm5_4
  float v57; // xmm4_4
  float v58; // xmm6_4
  float v59; // xmm7_4
  float v60; // xmm5_4
  float v61; // xmm4_4
  float v62; // xmm5_4
  float v63; // xmm6_4
  float v64; // xmm4_4
  float v65; // xmm7_4
  float v66; // xmm6_4
  float v67; // xmm7_4
  float v68; // xmm6_4
  float v69; // xmm5_4
  float v70; // xmm4_4
  float v71; // xmm6_4
  float v72; // xmm5_4
  float v73; // xmm7_4
  float v74; // xmm4_4
  float v75; // xmm6_4
  float v76; // xmm7_4
  float v77; // xmm5_4
  float v78; // xmm4_4
  float v79; // xmm5_4
  float v80; // xmm6_4
  float v81; // xmm4_4
  float v82; // xmm7_4
  float v83; // xmm6_4
  float v84; // xmm7_4
  float v85; // xmm7_4
  float v86; // xmm6_4
  float v87; // xmm5_4
  float v88; // xmm4_4
  float v89; // xmm6_4
  float v90; // xmm5_4
  float v91; // xmm7_4
  float v92; // xmm4_4
  float v93; // xmm6_4
  float v94; // xmm5_4
  float v95; // xmm4_4
  float v96; // xmm5_4
  float v97; // xmm6_4
  float v98; // xmm7_4
  float v99; // xmm4_4
  float v100; // xmm7_4
  float v101; // xmm6_4
  float v102; // xmm7_4
  float v103; // xmm6_4
  float v104; // xmm5_4
  float v105; // xmm7_4
  float v106; // xmm4_4
  float v107; // xmm6_4
  float v108; // xmm5_4
  float v109; // xmm4_4
  float v110; // xmm7_4
  float v111; // xmm6_4
  float v112; // xmm5_4
  float v113; // xmm4_4
  float v114; // xmm5_4
  float v115; // xmm6_4
  float v116; // xmm7_4
  float v117; // xmm4_4
  float v118; // xmm7_4
  float v119; // xmm6_4
  float v120; // xmm7_4
  float v121; // xmm6_4
  float v122; // xmm5_4
  float v123; // xmm7_4
  float v124; // xmm4_4
  float v125; // xmm6_4
  float v126; // xmm5_4
  float v127; // xmm7_4
  float v128; // xmm6_4
  float v129; // xmm7_4
  float v130; // xmm4_4
  float v131; // xmm5_4
  float v132; // xmm6_4
  float v133; // xmm4_4
  float v134; // xmm7_4
  float v135; // xmm6_4
  float v136; // xmm7_4
  float v137; // xmm6_4
  float v138; // xmm5_4
  float v139; // xmm7_4
  float v140; // xmm4_4
  float v141; // xmm6_4
  float v142; // xmm5_4
  float v143; // xmm4_4
  float v144; // xmm7_4
  float v145; // xmm6_4
  float v146; // xmm5_4
  float v147; // xmm4_4
  float v148; // xmm5_4
  float v149; // xmm6_4
  float v150; // xmm7_4
  float v151; // xmm4_4
  float v152; // xmm7_4
  float v153; // xmm6_4
  float v154; // xmm7_4
  float v155; // xmm6_4
  float v156; // xmm7_4
  float v157; // xmm6_4
  float v158; // xmm5_4
  float v159; // xmm4_4
  float v160; // xmm6_4
  float v161; // xmm5_4
  float v162; // xmm4_4
  float v163; // xmm7_4
  float v164; // xmm6_4
  float v165; // xmm5_4
  float v166; // xmm4_4
  float v167; // xmm5_4
  float v168; // xmm6_4
  float v169; // xmm7_4
  float v170; // xmm4_4
  float v171; // xmm7_4
  float v172; // xmm6_4
  float v173; // xmm7_4
  float v174; // xmm6_4
  float v175; // xmm7_4
  float v176; // xmm6_4
  float v177; // xmm5_4
  float v178; // xmm4_4
  float v179; // xmm6_4
  float v180; // xmm5_4
  float v181; // xmm7_4
  float v182; // xmm4_4
  float v183; // xmm6_4
  float v184; // xmm5_4
  float v185; // xmm4_4
  float v186; // xmm5_4
  float v187; // xmm6_4
  float v188; // xmm7_4
  float v189; // xmm4_4
  float v190; // xmm7_4
  float v191; // xmm6_4
  float v192; // xmm7_4
  float v193; // xmm6_4
  float v194; // xmm7_4
  float v195; // xmm6_4
  float v196; // xmm5_4
  float v197; // xmm4_4
  float v198; // xmm6_4
  float v199; // xmm5_4
  float v200; // xmm4_4
  float v201; // xmm7_4
  float v202; // xmm6_4
  float v203; // xmm5_4
  float v204; // xmm4_4
  float v205; // xmm5_4
  float v206; // xmm6_4
  float v207; // xmm4_4
  float v208; // xmm7_4
  float v209; // xmm6_4
  float v210; // xmm7_4
  float v211; // xmm6_4
  float v212; // xmm7_4
  float v213; // xmm6_4
  float v214; // xmm5_4
  float v215; // xmm4_4
  float v216; // xmm6_4
  float v217; // xmm5_4
  float v218; // xmm4_4
  float v219; // xmm6_4
  float v220; // xmm7_4
  float v221; // xmm5_4
  float v222; // xmm4_4
  float v223; // xmm5_4
  float v224; // xmm6_4
  float v225; // xmm4_4
  float v226; // xmm7_4
  float v227; // xmm6_4
  float v228; // xmm7_4
  float v229; // xmm6_4
  float v230; // xmm7_4
  float v231; // xmm6_4
  float v232; // xmm5_4
  float v233; // xmm4_4
  float v234; // xmm6_4
  float v235; // xmm5_4
  float v236; // xmm4_4
  float v237; // xmm6_4
  float v238; // xmm7_4
  float v239; // xmm5_4
  float v240; // xmm4_4
  float v241; // xmm4_4
  float v242; // xmm7_4
  float v243; // xmm6_4
  float v244; // xmm7_4
  float v245; // xmm6_4
  float v246; // xmm7_4
  float v247; // xmm6_4
  float v248; // xmm5_4
  float v249; // xmm4_4
  float v250; // xmm6_4
  float v251; // xmm5_4
  float v252; // xmm4_4
  float v253; // xmm7_4
  float v254; // xmm6_4
  float v255; // xmm5_4
  float v256; // xmm4_4
  float v257; // xmm5_4
  float v258; // xmm6_4
  float v259; // xmm7_4
  float v260; // xmm4_4
  float v261; // xmm7_4
  float v262; // xmm6_4
  float v263; // xmm7_4
  float v264; // xmm6_4
  float v265; // xmm7_4
  float v266; // xmm6_4
  float v267; // xmm5_4
  float v268; // xmm4_4
  float v269; // xmm6_4
  float v270; // xmm1_4
  float v271; // xmm5_4
  float v272; // xmm4_4
  float v273; // [esp+0h] [ebp-24h]
  float v274; // [esp+0h] [ebp-24h]
  float v275; // [esp+0h] [ebp-24h]
  float v276; // [esp+0h] [ebp-24h]
  float v277; // [esp+0h] [ebp-24h]
  float v278; // [esp+0h] [ebp-24h]
  float v279; // [esp+0h] [ebp-24h]
  float v280; // [esp+0h] [ebp-24h]
  float v281; // [esp+0h] [ebp-24h]
  float v282; // [esp+0h] [ebp-24h]
  float v283; // [esp+0h] [ebp-24h]
  float v284; // [esp+0h] [ebp-24h]
  float v285; // [esp+0h] [ebp-24h]
  float v286; // [esp+0h] [ebp-24h]
  float v287; // [esp+0h] [ebp-24h]
  float v288; // [esp+0h] [ebp-24h]
  float v289; // [esp+0h] [ebp-24h]
  float v290; // [esp+0h] [ebp-24h]
  float v291; // [esp+0h] [ebp-24h]
  float v292; // [esp+0h] [ebp-24h]
  float v293; // [esp+0h] [ebp-24h]
  float v294; // [esp+0h] [ebp-24h]
  float v295; // [esp+0h] [ebp-24h]
  float v296; // [esp+0h] [ebp-24h]
  float v297; // [esp+0h] [ebp-24h]
  float v298; // [esp+0h] [ebp-24h]
  float v299; // [esp+0h] [ebp-24h]
  float v300; // [esp+0h] [ebp-24h]
  float tmp7; // [esp+4h] [ebp-20h]
  float tmp7a; // [esp+4h] [ebp-20h]
  float tmp7b; // [esp+4h] [ebp-20h]
  float tmp7c; // [esp+4h] [ebp-20h]
  float tmp7d; // [esp+4h] [ebp-20h]
  float tmp7e; // [esp+4h] [ebp-20h]
  float tmp7f; // [esp+4h] [ebp-20h]
  float tmp7g; // [esp+4h] [ebp-20h]
  float tmp7h; // [esp+4h] [ebp-20h]
  float tmp7i; // [esp+4h] [ebp-20h]
  float tmp7j; // [esp+4h] [ebp-20h]
  float tmp7k; // [esp+4h] [ebp-20h]
  float tmp7l; // [esp+4h] [ebp-20h]
  float tmp7m; // [esp+4h] [ebp-20h]
  float tmp7n; // [esp+4h] [ebp-20h]
  float tmp11; // [esp+8h] [ebp-1Ch]
  float tmp3; // [esp+Ch] [ebp-18h]
  float tmp3a; // [esp+Ch] [ebp-18h]
  float tmp3b; // [esp+Ch] [ebp-18h]
  float tmp3c; // [esp+Ch] [ebp-18h]
  float tmp3d; // [esp+Ch] [ebp-18h]
  float tmp3e; // [esp+Ch] [ebp-18h]
  float tmp3f; // [esp+Ch] [ebp-18h]
  float tmp3g; // [esp+Ch] [ebp-18h]
  float tmp3h; // [esp+Ch] [ebp-18h]
  float tmp3i; // [esp+Ch] [ebp-18h]
  float tmp3j; // [esp+Ch] [ebp-18h]
  float z4; // [esp+10h] [ebp-14h]
  float z4a; // [esp+10h] [ebp-14h]
  float z4b; // [esp+10h] [ebp-14h]
  float z4c; // [esp+10h] [ebp-14h]
  float z4d; // [esp+10h] [ebp-14h]
  float z4e; // [esp+10h] [ebp-14h]
  float z4f; // [esp+10h] [ebp-14h]
  float z4g; // [esp+10h] [ebp-14h]
  float z4h; // [esp+10h] [ebp-14h]
  float z4i; // [esp+10h] [ebp-14h]
  float z4j; // [esp+10h] [ebp-14h]
  float z4k; // [esp+10h] [ebp-14h]
  float z4l; // [esp+10h] [ebp-14h]
  float z4m; // [esp+10h] [ebp-14h]
  float z4n; // [esp+10h] [ebp-14h]
  float z2; // [esp+14h] [ebp-10h]
  float z2a; // [esp+14h] [ebp-10h]
  float z2b; // [esp+14h] [ebp-10h]
  float z2c; // [esp+14h] [ebp-10h]
  float z2d; // [esp+14h] [ebp-10h]
  float z2e; // [esp+14h] [ebp-10h]
  float z2f; // [esp+14h] [ebp-10h]
  float z2g; // [esp+14h] [ebp-10h]
  float z2h; // [esp+14h] [ebp-10h]
  float z2i; // [esp+14h] [ebp-10h]
  float z2j; // [esp+14h] [ebp-10h]
  float z2k; // [esp+14h] [ebp-10h]
  float z2l; // [esp+14h] [ebp-10h]
  float z2m; // [esp+14h] [ebp-10h]
  float z2n; // [esp+14h] [ebp-10h]
  float tmp4; // [esp+18h] [ebp-Ch]
  float tmp4a; // [esp+18h] [ebp-Ch]
  float tmp4b; // [esp+18h] [ebp-Ch]
  float tmp4c; // [esp+18h] [ebp-Ch]
  float tmp4d; // [esp+18h] [ebp-Ch]
  float tmp4e; // [esp+18h] [ebp-Ch]
  float tmp4f; // [esp+18h] [ebp-Ch]
  float tmp4g; // [esp+18h] [ebp-Ch]
  float tmp4h; // [esp+18h] [ebp-Ch]
  float tmp4i; // [esp+18h] [ebp-Ch]
  float tmp4j; // [esp+18h] [ebp-Ch]
  float tmp4k; // [esp+18h] [ebp-Ch]
  float tmp4l; // [esp+18h] [ebp-Ch]
  float tmp4m; // [esp+18h] [ebp-Ch]
  float tmp4n; // [esp+18h] [ebp-Ch]
  float tmp5; // [esp+1Ch] [ebp-8h]
  float tmp5a; // [esp+1Ch] [ebp-8h]
  float tmp5b; // [esp+1Ch] [ebp-8h]
  float tmp5c; // [esp+1Ch] [ebp-8h]
  float tmp5d; // [esp+1Ch] [ebp-8h]
  float tmp5e; // [esp+1Ch] [ebp-8h]
  float tmp5f; // [esp+1Ch] [ebp-8h]
  float tmp5g; // [esp+1Ch] [ebp-8h]
  float tmp5h; // [esp+1Ch] [ebp-8h]
  float tmp5i; // [esp+1Ch] [ebp-8h]
  float tmp5j; // [esp+1Ch] [ebp-8h]
  float tmp5k; // [esp+1Ch] [ebp-8h]
  float tmp5l; // [esp+1Ch] [ebp-8h]
  float tmp5m; // [esp+1Ch] [ebp-8h]
  float tmp5n; // [esp+1Ch] [ebp-8h]
  float tmp2; // [esp+20h] [ebp-4h]
  float tmp2a; // [esp+20h] [ebp-4h]
  float tmp2b; // [esp+20h] [ebp-4h]
  float tmp2c; // [esp+20h] [ebp-4h]
  float tmp2d; // [esp+20h] [ebp-4h]
  float tmp2e; // [esp+20h] [ebp-4h]
  float tmp2f; // [esp+20h] [ebp-4h]
  float tmp2g; // [esp+20h] [ebp-4h]
  float tmp2h; // [esp+20h] [ebp-4h]
  float tmp2i; // [esp+20h] [ebp-4h]
  float tmp2j; // [esp+20h] [ebp-4h]
  float tmp2k; // [esp+20h] [ebp-4h]
  float tmp2l; // [esp+20h] [ebp-4h]
  float tmp2m; // [esp+20h] [ebp-4h]
  float tmp2n; // [esp+20h] [ebp-4h]
  float tmp6; // [esp+2Ch] [ebp+8h]
  float tmp6a; // [esp+2Ch] [ebp+8h]
  float tmp6b; // [esp+2Ch] [ebp+8h]
  float tmp6c; // [esp+2Ch] [ebp+8h]
  float tmp6d; // [esp+2Ch] [ebp+8h]
  float tmp6e; // [esp+2Ch] [ebp+8h]
  float tmp6f; // [esp+2Ch] [ebp+8h]
  float tmp6g; // [esp+2Ch] [ebp+8h]
  float tmp6h; // [esp+2Ch] [ebp+8h]
  float tmp6i; // [esp+2Ch] [ebp+8h]
  float tmp6j; // [esp+2Ch] [ebp+8h]
  float tmp6k; // [esp+2Ch] [ebp+8h]
  float tmp6l; // [esp+2Ch] [ebp+8h]
  float tmp6m; // [esp+2Ch] [ebp+8h]
  float tmp6n; // [esp+2Ch] [ebp+8h]
  float tmp6o; // [esp+2Ch] [ebp+8h]

  v2 = *data;
  v3 = data[2];
  v4 = data[1];
  v5 = v4 - data[6];
  v6 = v4 + data[6];
  tmp6 = v5;
  v7 = data[3] + data[4];
  v8 = v2 + data[7];
  v9 = v2 - data[7];
  tmp4 = data[3] - data[4];
  v10 = v7 + v8;
  v11 = v3 + data[5];
  v12 = v3 - data[5];
  v13 = v8 - v7;
  *data = (float)(v11 + v6) + v10;
  data[4] = v10 - (float)(v11 + v6);
  v14 = (float)((float)(v6 - v11) + v13) * 0.70710677;
  data[6] = v13 - v14;
  v15 = (float)((float)(tmp4 + v12) - (float)(tmp6 + v9)) * 0.38268343;
  data[2] = v14 + v13;
  z2 = (float)((float)(tmp4 + v12) * 0.54119611) + v15;
  z4 = (float)((float)(tmp6 + v9) * 1.306563) + v15;
  v16 = (float)(v12 + tmp6) * 0.70710677;
  v17 = v16 + v9;
  v18 = v9 - v16;
  v19 = data[8];
  v20 = v18 + z2;
  data[3] = v18 - z2;
  v21 = v17 + z4;
  data[7] = v17 - z4;
  v22 = v19;
  v23 = v19 - data[15];
  v24 = v22 + data[15];
  data[1] = v21;
  v25 = data[9];
  tmp7 = v23;
  v26 = v25 + data[14];
  tmp6a = v25 - data[14];
  v27 = data[10];
  data[5] = v20;
  tmp2 = v27 + data[13];
  tmp5 = v27 - data[13];
  tmp11 = data[11];
  tmp3 = tmp11 + data[12];
  tmp4a = tmp11 - data[12];
  v28 = tmp3 + v24;
  v29 = v24 - tmp3;
  v30 = tmp2 + v26;
  v31 = (float)((float)(v26 - tmp2) + v29) * 0.70710677;
  data[12] = v28 - v30;
  data[10] = v31 + v29;
  data[14] = v29 - v31;
  data[8] = v30 + v28;
  v32 = (float)((float)(tmp4a + tmp5) - (float)(tmp6a + tmp7)) * 0.38268343;
  z4a = (float)((float)(tmp6a + tmp7) * 1.306563) + v32;
  z2a = (float)((float)(tmp4a + tmp5) * 0.54119611) + v32;
  v33 = (float)((float)(tmp5 + tmp6a) * 0.70710677) + tmp7;
  v34 = data[16];
  v35 = (float)(tmp7 - (float)((float)(tmp5 + tmp6a) * 0.70710677)) - z2a;
  data[13] = (float)(tmp7 - (float)((float)(tmp5 + tmp6a) * 0.70710677)) + z2a;
  data[9] = v33 + z4a;
  v36 = data[17];
  data[15] = v33 - z4a;
  v37 = v34 + data[23];
  tmp7a = v34 - data[23];
  v38 = v36 + data[22];
  tmp6b = v36 - data[22];
  v273 = data[18];
  tmp2a = v273 + data[21];
  tmp5a = v273 - data[21];
  v274 = data[19];
  v39 = v274 + data[20];
  data[11] = v35;
  tmp3a = v39;
  tmp4b = v274 - data[20];
  v40 = v39 + v37;
  v41 = v37 - tmp3a;
  v42 = tmp2a + v38;
  v43 = (float)((float)(v38 - tmp2a) + v41) * 0.70710677;
  data[20] = v40 - v42;
  data[18] = v43 + v41;
  data[22] = v41 - v43;
  data[16] = v42 + v40;
  v44 = (float)((float)(tmp4b + tmp5a) - (float)(tmp6b + tmp7a)) * 0.38268343;
  z4b = (float)((float)(tmp6b + tmp7a) * 1.306563) + v44;
  z2b = (float)((float)(tmp4b + tmp5a) * 0.54119611) + v44;
  v45 = (float)((float)(tmp5a + tmp6b) * 0.70710677) + tmp7a;
  v46 = data[24];
  data[21] = (float)(tmp7a - (float)((float)(tmp5a + tmp6b) * 0.70710677)) + z2b;
  v47 = (float)(tmp7a - (float)((float)(tmp5a + tmp6b) * 0.70710677)) - z2b;
  data[17] = v45 + z4b;
  v48 = data[25];
  data[23] = v45 - z4b;
  v49 = v46 + data[31];
  tmp7b = v46 - data[31];
  v50 = v48 + data[30];
  tmp6c = v48 - data[30];
  v275 = data[26];
  tmp2b = v275 + data[29];
  tmp5b = v275 - data[29];
  v276 = data[27];
  tmp3b = v276 + data[28];
  tmp4c = v276 - data[28];
  data[19] = v47;
  v51 = tmp3b + v49;
  v52 = v49 - tmp3b;
  v53 = (float)(tmp2b + v50) + v51;
  data[28] = v51 - (float)(tmp2b + v50);
  v54 = (float)((float)(v50 - tmp2b) + v52) * 0.70710677;
  data[26] = v54 + v52;
  data[30] = v52 - v54;
  data[24] = v53;
  v55 = (float)((float)(tmp4c + tmp5b) - (float)(tmp6c + tmp7b)) * 0.38268343;
  z4c = (float)((float)(tmp6c + tmp7b) * 1.306563) + v55;
  z2c = (float)((float)(tmp4c + tmp5b) * 0.54119611) + v55;
  v56 = (float)((float)(tmp5b + tmp6c) * 0.70710677) + tmp7b;
  v57 = data[32];
  data[29] = (float)(tmp7b - (float)((float)(tmp5b + tmp6c) * 0.70710677)) + z2c;
  data[25] = v56 + z4c;
  v58 = data[39];
  data[27] = (float)(tmp7b - (float)((float)(tmp5b + tmp6c) * 0.70710677)) - z2c;
  v59 = data[38];
  data[31] = v56 - z4c;
  v60 = v57;
  v61 = v57 - v58;
  v62 = v60 + v58;
  v63 = data[33];
  tmp7c = v61;
  tmp6d = v63 - v59;
  v277 = data[34];
  v64 = v63 + v59;
  v65 = data[37];
  tmp2c = v277 + v65;
  v66 = v277 - v65;
  v67 = data[36];
  tmp5c = v66;
  v278 = data[35];
  v68 = (float)(v278 + v67) + v62;
  v69 = v62 - (float)(v278 + v67);
  data[32] = (float)(tmp2c + v64) + v68;
  data[36] = v68 - (float)(tmp2c + v64);
  v70 = (float)((float)(v64 - tmp2c) + v69) * 0.70710677;
  data[34] = v70 + v69;
  data[38] = v69 - v70;
  v71 = (float)((float)((float)(v278 - v67) + tmp5c) - (float)(tmp6d + tmp7c)) * 0.38268343;
  z4d = (float)((float)(tmp6d + tmp7c) * 1.306563) + v71;
  z2d = (float)((float)((float)(v278 - v67) + tmp5c) * 0.54119611) + v71;
  v72 = (float)((float)(tmp5c + tmp6d) * 0.70710677) + tmp7c;
  v73 = tmp7c - (float)((float)(tmp5c + tmp6d) * 0.70710677);
  v74 = data[40];
  data[37] = v73 + z2d;
  data[33] = v72 + z4d;
  v75 = data[47];
  data[35] = v73 - z2d;
  v76 = data[46];
  data[39] = v72 - z4d;
  v77 = v74;
  v78 = v74 - v75;
  v79 = v77 + v75;
  v80 = data[41];
  tmp7d = v78;
  tmp6e = v80 - v76;
  v279 = data[42];
  v81 = v80 + v76;
  v82 = data[45];
  tmp2d = v279 + v82;
  v83 = v279 - v82;
  v84 = data[44];
  tmp5d = v83;
  v280 = data[43];
  tmp3c = v280 + v84;
  tmp4d = v280 - v84;
  v85 = tmp2d + v81;
  v86 = tmp3c + v79;
  v87 = v79 - tmp3c;
  data[44] = v86 - (float)(tmp2d + v81);
  v88 = (float)((float)(v81 - tmp2d) + v87) * 0.70710677;
  data[40] = v85 + v86;
  data[42] = v88 + v87;
  data[46] = v87 - v88;
  v89 = (float)((float)(tmp4d + tmp5d) - (float)(tmp6e + tmp7d)) * 0.38268343;
  z4e = (float)((float)(tmp6e + tmp7d) * 1.306563) + v89;
  z2e = (float)((float)(tmp4d + tmp5d) * 0.54119611) + v89;
  v90 = (float)((float)(tmp5d + tmp6e) * 0.70710677) + tmp7d;
  v91 = tmp7d - (float)((float)(tmp5d + tmp6e) * 0.70710677);
  v92 = data[48];
  data[45] = v91 + z2e;
  data[41] = v90 + z4e;
  v93 = data[55];
  data[47] = v90 - z4e;
  v94 = v92;
  v95 = v92 - v93;
  v96 = v94 + v93;
  v97 = data[49];
  data[43] = v91 - z2e;
  v98 = data[54];
  tmp7e = v95;
  tmp6f = v97 - v98;
  v281 = data[50];
  v99 = v97 + v98;
  v100 = data[53];
  tmp2e = v281 + v100;
  v101 = v281 - v100;
  v102 = data[52];
  tmp5e = v101;
  v282 = data[51];
  tmp4e = v282 - v102;
  v103 = (float)(v282 + v102) + v96;
  v104 = v96 - (float)(v282 + v102);
  v105 = (float)(tmp2e + v99) + v103;
  data[52] = v103 - (float)(tmp2e + v99);
  v106 = (float)((float)(v99 - tmp2e) + v104) * 0.70710677;
  data[54] = v104 - v106;
  data[48] = v105;
  data[50] = v106 + v104;
  v107 = (float)((float)(tmp4e + tmp5e) - (float)(tmp6f + tmp7e)) * 0.38268343;
  z4f = (float)((float)(tmp6f + tmp7e) * 1.306563) + v107;
  z2f = (float)((float)(tmp4e + tmp5e) * 0.54119611) + v107;
  v108 = (float)((float)(tmp5e + tmp6f) * 0.70710677) + tmp7e;
  v109 = data[56];
  v110 = (float)(tmp7e - (float)((float)(tmp5e + tmp6f) * 0.70710677)) - z2f;
  data[53] = (float)(tmp7e - (float)((float)(tmp5e + tmp6f) * 0.70710677)) + z2f;
  data[49] = v108 + z4f;
  v111 = data[63];
  data[55] = v108 - z4f;
  v112 = v109;
  v113 = v109 - v111;
  v114 = v112 + v111;
  v115 = data[57];
  tmp7f = v113;
  data[51] = v110;
  v116 = data[62];
  tmp6g = v115 - v116;
  v283 = data[58];
  v117 = v115 + v116;
  v118 = data[61];
  tmp2f = v283 + v118;
  v119 = v283 - v118;
  v120 = data[60];
  tmp5f = v119;
  v284 = data[59];
  tmp4f = v284 - v120;
  v121 = (float)(v284 + v120) + v114;
  v122 = v114 - (float)(v284 + v120);
  v123 = (float)(tmp2f + v117) + v121;
  data[60] = v121 - (float)(tmp2f + v117);
  v124 = (float)((float)(v117 - tmp2f) + v122) * 0.70710677;
  data[62] = v122 - v124;
  data[56] = v123;
  data[58] = v124 + v122;
  v125 = (float)((float)(tmp4f + tmp5f) - (float)(tmp6g + tmp7f)) * 0.38268343;
  z4g = (float)((float)(tmp6g + tmp7f) * 1.306563) + v125;
  z2g = (float)((float)(tmp4f + tmp5f) * 0.54119611) + v125;
  v126 = (float)((float)(tmp5f + tmp6g) * 0.70710677) + tmp7f;
  v127 = tmp7f - (float)((float)(tmp5f + tmp6g) * 0.70710677);
  data[61] = v127 + z2g;
  data[59] = v127 - z2g;
  data[57] = v126 + z4g;
  data[63] = v126 - z4g;
  v128 = data[56];
  v129 = data[48];
  v130 = *data - v128;
  v131 = *data + v128;
  v132 = data[8];
  tmp7g = v130;
  tmp6h = v132 - v129;
  v285 = data[16];
  v133 = v132 + v129;
  v134 = data[40];
  tmp2g = v285 + v134;
  v135 = v285 - v134;
  v136 = data[32];
  tmp5g = v135;
  v286 = data[24];
  tmp4g = v286 - v136;
  v137 = (float)(v286 + v136) + v131;
  v138 = v131 - (float)(v286 + v136);
  v139 = (float)(tmp2g + v133) + v137;
  data[32] = v137 - (float)(tmp2g + v133);
  v140 = (float)((float)(v133 - tmp2g) + v138) * 0.70710677;
  data[48] = v138 - v140;
  data[16] = v140 + v138;
  *data = v139;
  v141 = (float)((float)(tmp4g + tmp5g) - (float)(tmp6h + tmp7g)) * 0.38268343;
  z2h = (float)((float)(tmp4g + tmp5g) * 0.54119611) + v141;
  z4h = (float)((float)(tmp6h + tmp7g) * 1.306563) + v141;
  v142 = (float)((float)(tmp5g + tmp6h) * 0.70710677) + tmp7g;
  v143 = data[1];
  v144 = (float)(tmp7g - (float)((float)(tmp5g + tmp6h) * 0.70710677)) - z2h;
  data[40] = (float)(tmp7g - (float)((float)(tmp5g + tmp6h) * 0.70710677)) + z2h;
  data[8] = v142 + z4h;
  v145 = data[57];
  data[56] = v142 - z4h;
  v146 = v143;
  v147 = v143 - v145;
  v148 = v146 + v145;
  v149 = data[9];
  tmp7h = v147;
  data[24] = v144;
  v150 = data[49];
  tmp6i = v149 - v150;
  v151 = v149 + v150;
  v152 = data[41];
  v287 = data[17];
  tmp2h = v287 + v152;
  v153 = v287 - v152;
  v154 = data[33];
  tmp5h = v153;
  v288 = data[25];
  tmp3d = v288 + v154;
  v155 = v288 - v154;
  v156 = tmp2h + v151;
  tmp4h = v155;
  v157 = tmp3d + v148;
  v158 = v148 - tmp3d;
  v159 = (float)((float)(v151 - tmp2h) + v158) * 0.70710677;
  data[33] = v157 - v156;
  data[49] = v158 - v159;
  data[17] = v159 + v158;
  data[1] = v156 + v157;
  v160 = (float)((float)(tmp4h + tmp5h) - (float)(tmp6i + tmp7h)) * 0.38268343;
  z4i = (float)((float)(tmp6i + tmp7h) * 1.306563) + v160;
  z2i = (float)((float)(tmp4h + tmp5h) * 0.54119611) + v160;
  v161 = (float)((float)(tmp5h + tmp6i) * 0.70710677) + tmp7h;
  v162 = data[2];
  v163 = (float)(tmp7h - (float)((float)(tmp5h + tmp6i) * 0.70710677)) - z2i;
  data[41] = (float)(tmp7h - (float)((float)(tmp5h + tmp6i) * 0.70710677)) + z2i;
  data[9] = v161 + z4i;
  v164 = data[58];
  data[57] = v161 - z4i;
  v165 = v162;
  v166 = v162 - v164;
  v167 = v165 + v164;
  v168 = data[10];
  tmp7i = v166;
  data[25] = v163;
  v169 = data[50];
  tmp6j = v168 - v169;
  v170 = v168 + v169;
  v171 = data[42];
  v289 = data[18];
  tmp2i = v289 + v171;
  v172 = v289 - v171;
  v173 = data[34];
  tmp5i = v172;
  v290 = data[26];
  tmp3e = v290 + v173;
  v174 = v290 - v173;
  v175 = tmp2i + v170;
  tmp4i = v174;
  v176 = tmp3e + v167;
  v177 = v167 - tmp3e;
  v178 = (float)((float)(v170 - tmp2i) + v177) * 0.70710677;
  data[34] = v176 - v175;
  data[50] = v177 - v178;
  data[18] = v178 + v177;
  data[2] = v175 + v176;
  v179 = (float)((float)(tmp4i + tmp5i) - (float)(tmp6j + tmp7i)) * 0.38268343;
  z4j = (float)((float)(tmp6j + tmp7i) * 1.306563) + v179;
  z2j = (float)((float)(tmp4i + tmp5i) * 0.54119611) + v179;
  v180 = (float)((float)(tmp5i + tmp6j) * 0.70710677) + tmp7i;
  v181 = (float)(tmp7i - (float)((float)(tmp5i + tmp6j) * 0.70710677)) - z2j;
  v182 = data[3];
  data[42] = (float)(tmp7i - (float)((float)(tmp5i + tmp6j) * 0.70710677)) + z2j;
  data[10] = v180 + z4j;
  v183 = data[59];
  data[58] = v180 - z4j;
  v184 = v182;
  v185 = v182 - v183;
  v186 = v184 + v183;
  v187 = data[11];
  tmp7j = v185;
  data[26] = v181;
  v188 = data[51];
  tmp6k = v187 - v188;
  v291 = data[19];
  v189 = v187 + v188;
  v190 = data[43];
  tmp2j = v291 + v190;
  v191 = v291 - v190;
  v192 = data[35];
  tmp5j = v191;
  v292 = data[27];
  tmp3f = v292 + v192;
  v193 = v292 - v192;
  v194 = tmp2j + v189;
  tmp4j = v193;
  v195 = tmp3f + v186;
  v196 = v186 - tmp3f;
  v197 = (float)((float)(v189 - tmp2j) + v196) * 0.70710677;
  data[35] = v195 - v194;
  data[51] = v196 - v197;
  data[19] = v197 + v196;
  data[3] = v194 + v195;
  v198 = (float)((float)(tmp4j + tmp5j) - (float)(tmp6k + tmp7j)) * 0.38268343;
  z4k = (float)((float)(tmp6k + tmp7j) * 1.306563) + v198;
  z2k = (float)((float)(tmp4j + tmp5j) * 0.54119611) + v198;
  v199 = (float)((float)(tmp5j + tmp6k) * 0.70710677) + tmp7j;
  data[43] = (float)(tmp7j - (float)((float)(tmp5j + tmp6k) * 0.70710677)) + z2k;
  data[27] = (float)(tmp7j - (float)((float)(tmp5j + tmp6k) * 0.70710677)) - z2k;
  v200 = data[4];
  v201 = data[52];
  data[11] = v199 + z4k;
  v202 = data[60];
  data[59] = v199 - z4k;
  v203 = v200;
  v204 = v200 - v202;
  v205 = v203 + v202;
  v206 = data[12];
  tmp7k = v204;
  tmp6l = v206 - v201;
  v293 = data[20];
  v207 = v206 + v201;
  v208 = data[44];
  tmp2k = v293 + v208;
  v209 = v293 - v208;
  v210 = data[36];
  tmp5k = v209;
  v294 = data[28];
  tmp3g = v294 + v210;
  v211 = v294 - v210;
  v212 = tmp2k + v207;
  tmp4k = v211;
  v213 = tmp3g + v205;
  v214 = v205 - tmp3g;
  v215 = (float)((float)(v207 - tmp2k) + v214) * 0.70710677;
  data[36] = v213 - v212;
  data[52] = v214 - v215;
  data[20] = v215 + v214;
  data[4] = v212 + v213;
  v216 = (float)((float)(tmp4k + tmp5k) - (float)(tmp6l + tmp7k)) * 0.38268343;
  z4l = (float)((float)(tmp6l + tmp7k) * 1.306563) + v216;
  z2l = (float)((float)(tmp4k + tmp5k) * 0.54119611) + v216;
  v217 = (float)((float)(tmp5k + tmp6l) * 0.70710677) + tmp7k;
  v218 = data[5];
  data[44] = (float)(tmp7k - (float)((float)(tmp5k + tmp6l) * 0.70710677)) + z2l;
  data[12] = v217 + z4l;
  v219 = data[61];
  data[28] = (float)(tmp7k - (float)((float)(tmp5k + tmp6l) * 0.70710677)) - z2l;
  data[60] = v217 - z4l;
  v220 = data[53];
  v221 = v218;
  v222 = v218 - v219;
  v223 = v221 + v219;
  v224 = data[13];
  tmp7l = v222;
  tmp6m = v224 - v220;
  v225 = v224 + v220;
  v226 = data[45];
  v295 = data[21];
  tmp2l = v295 + v226;
  v227 = v295 - v226;
  v228 = data[37];
  tmp5l = v227;
  v296 = data[29];
  tmp3h = v296 + v228;
  v229 = v296 - v228;
  v230 = tmp2l + v225;
  tmp4l = v229;
  v231 = tmp3h + v223;
  v232 = v223 - tmp3h;
  v233 = (float)((float)(v225 - tmp2l) + v232) * 0.70710677;
  data[37] = v231 - v230;
  data[53] = v232 - v233;
  data[21] = v233 + v232;
  data[5] = v230 + v231;
  v234 = (float)((float)(tmp4l + tmp5l) - (float)(tmp6m + tmp7l)) * 0.38268343;
  z4m = (float)((float)(tmp6m + tmp7l) * 1.306563) + v234;
  z2m = (float)((float)(tmp4l + tmp5l) * 0.54119611) + v234;
  v235 = (float)((float)(tmp5l + tmp6m) * 0.70710677) + tmp7l;
  v236 = data[6];
  data[45] = (float)(tmp7l - (float)((float)(tmp5l + tmp6m) * 0.70710677)) + z2m;
  data[61] = v235 - z4m;
  data[13] = v235 + z4m;
  v237 = data[62];
  data[29] = (float)(tmp7l - (float)((float)(tmp5l + tmp6m) * 0.70710677)) - z2m;
  v238 = data[54];
  v239 = v236 + v237;
  tmp7m = v236 - v237;
  v240 = data[14];
  tmp6n = v240 - v238;
  v241 = v240 + v238;
  v242 = data[46];
  v297 = data[22];
  tmp2m = v297 + v242;
  v243 = v297 - v242;
  v244 = data[38];
  tmp5m = v243;
  v298 = data[30];
  tmp3i = v298 + v244;
  v245 = v298 - v244;
  v246 = tmp2m + v241;
  tmp4m = v245;
  v247 = tmp3i + v239;
  v248 = v239 - tmp3i;
  v249 = (float)((float)(v241 - tmp2m) + v248) * 0.70710677;
  data[38] = v247 - v246;
  data[54] = v248 - v249;
  data[22] = v249 + v248;
  data[6] = v246 + v247;
  v250 = (float)((float)(tmp4m + tmp5m) - (float)(tmp6n + tmp7m)) * 0.38268343;
  z4n = (float)((float)(tmp6n + tmp7m) * 1.306563) + v250;
  z2n = (float)((float)(tmp4m + tmp5m) * 0.54119611) + v250;
  v251 = (float)((float)(tmp5m + tmp6n) * 0.70710677) + tmp7m;
  v252 = data[7];
  v253 = (float)(tmp7m - (float)((float)(tmp5m + tmp6n) * 0.70710677)) - z2n;
  data[46] = (float)(tmp7m - (float)((float)(tmp5m + tmp6n) * 0.70710677)) + z2n;
  data[14] = v251 + z4n;
  v254 = data[63];
  data[62] = v251 - z4n;
  v255 = v252;
  v256 = v252 - v254;
  v257 = v255 + v254;
  v258 = data[15];
  tmp7n = v256;
  data[30] = v253;
  v259 = data[55];
  v260 = v258 + v259;
  tmp6o = v258 - v259;
  v261 = data[47];
  v299 = data[23];
  tmp2n = v299 + v261;
  v262 = v299 - v261;
  v263 = data[39];
  tmp5n = v262;
  v300 = data[31];
  tmp3j = v300 + v263;
  v264 = v300 - v263;
  v265 = tmp2n + v260;
  tmp4n = v264;
  v266 = tmp3j + v257;
  v267 = v257 - tmp3j;
  v268 = (float)((float)(v260 - tmp2n) + v267) * 0.70710677;
  data[39] = v266 - v265;
  data[55] = v267 - v268;
  data[7] = v265 + v266;
  data[23] = v268 + v267;
  v269 = (float)((float)(tmp4n + tmp5n) - (float)(tmp6o + tmp7n)) * 0.38268343;
  v270 = (float)(tmp5n + tmp6o) * 0.70710677;
  v271 = (float)((float)(tmp4n + tmp5n) * 0.54119611) + v269;
  data[47] = (float)(tmp7n - v270) + v271;
  v272 = (float)((float)(tmp6o + tmp7n) * 1.306563) + v269;
  data[31] = (float)(tmp7n - v270) - v271;
  data[15] = (float)(v270 + tmp7n) + v272;
  data[63] = (float)(v270 + tmp7n) - v272;
}

} // namespace vxconsole_ps3
