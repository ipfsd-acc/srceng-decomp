// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jfdctfst.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10258C20
// Name: _jpeg_fdct_ifast
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_fdct_ifast(int *data)
{
  int *v1; // eax
  int v2; // ecx
  int v3; // edi
  int v4; // esi
  int v5; // edx
  int v6; // edi
  int v7; // ecx
  int v8; // ebx
  int v9; // ecx
  int v10; // esi
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // ecx
  int v15; // esi
  int v16; // edx
  int v17; // ecx
  int v18; // ebx
  int v19; // edi
  int v20; // ecx
  int v21; // edi
  int v22; // edx
  int v23; // ecx
  int v24; // edi
  int v25; // ebx
  int v26; // esi
  int v27; // edx
  int v28; // edi
  int v29; // ecx
  int v30; // ebx
  int v31; // ecx
  int v32; // ecx
  int v33; // esi
  int v34; // ecx
  int v35; // edx
  int v36; // ecx
  int v37; // ecx
  int v38; // esi
  int v39; // edx
  int v40; // ecx
  int v41; // ebx
  int v42; // edi
  int v43; // ecx
  int v44; // edi
  int v45; // edx
  int v46; // ecx
  int v47; // ebx
  int v48; // esi
  int v49; // edi
  int v50; // edx
  int v51; // edi
  int v52; // ecx
  int v53; // ebx
  int v54; // ecx
  int v55; // ecx
  int v56; // esi
  int v57; // ecx
  int v58; // edx
  int v59; // ecx
  int v60; // ecx
  int v61; // esi
  int v62; // edx
  int v63; // ecx
  int v64; // ebx
  int v65; // edi
  int v66; // ecx
  int v67; // edi
  int v68; // edx
  int v69; // ebx
  int v70; // esi
  int v71; // edi
  int v72; // edx
  int v73; // edi
  int v74; // ecx
  int v75; // ebx
  int v76; // ecx
  int v77; // ecx
  int v78; // esi
  int v79; // ecx
  int v80; // edx
  int v81; // ecx
  int v82; // ecx
  int v83; // edx
  int v84; // esi
  int v85; // ecx
  int v86; // ebx
  int v87; // edi
  int *v88; // eax
  int v89; // ecx
  int v90; // edi
  int v91; // esi
  int v92; // edx
  int v93; // edi
  int v94; // ecx
  int v95; // ebx
  int v96; // ecx
  int v97; // esi
  int v98; // ecx
  int v99; // edx
  int v100; // ecx
  int v101; // ecx
  int v102; // esi
  int v103; // edx
  int v104; // ecx
  int v105; // ebx
  int v106; // edi
  int v107; // ecx
  int v108; // edi
  int v109; // edx
  int v110; // ecx
  int v111; // edi
  int v112; // ebx
  int v113; // esi
  int v114; // edx
  int v115; // edi
  int v116; // ecx
  int v117; // ebx
  int v118; // ecx
  int v119; // ecx
  int v120; // esi
  int v121; // ecx
  int v122; // edx
  int v123; // ecx
  int v124; // ecx
  int v125; // esi
  int v126; // edx
  int v127; // ecx
  int v128; // ebx
  int v129; // edi
  int v130; // ecx
  int v131; // edi
  int v132; // edx
  int v133; // ecx
  int v134; // ebx
  int v135; // esi
  int v136; // edi
  int v137; // edx
  int v138; // edi
  int v139; // ecx
  int v140; // ebx
  int v141; // ecx
  int v142; // ecx
  int v143; // esi
  int v144; // ecx
  int v145; // edx
  int v146; // ecx
  int v147; // ecx
  int v148; // esi
  int v149; // edx
  int v150; // ecx
  int v151; // ebx
  int v152; // edi
  int v153; // ecx
  int v154; // edi
  int v155; // edx
  int v156; // ebx
  int v157; // esi
  int v158; // edi
  int v159; // edx
  int v160; // edi
  int v161; // ecx
  int v162; // ebx
  int v163; // ecx
  int v164; // ecx
  int v165; // esi
  int v166; // ecx
  int v167; // edx
  int v168; // ecx
  int v169; // ecx
  int v170; // edx
  int v171; // esi
  int v172; // ecx
  int v173; // ebx
  int v174; // edi
  int i; // [esp+Ch] [ebp-18h]
  int tmp6; // [esp+10h] [ebp-14h]
  int tmp6a; // [esp+10h] [ebp-14h]
  int tmp6b; // [esp+10h] [ebp-14h]
  int tmp6c; // [esp+10h] [ebp-14h]
  int tmp6d; // [esp+10h] [ebp-14h]
  int tmp6e; // [esp+10h] [ebp-14h]
  int tmp6f; // [esp+10h] [ebp-14h]
  int tmp6g; // [esp+10h] [ebp-14h]
  int tmp4; // [esp+14h] [ebp-10h]
  int tmp4a; // [esp+14h] [ebp-10h]
  int tmp4b; // [esp+14h] [ebp-10h]
  int tmp4c; // [esp+14h] [ebp-10h]
  int tmp4d; // [esp+14h] [ebp-10h]
  int tmp4e; // [esp+14h] [ebp-10h]
  int tmp4f; // [esp+14h] [ebp-10h]
  int tmp4g; // [esp+14h] [ebp-10h]
  int tmp5; // [esp+1Ch] [ebp-8h]
  int tmp5a; // [esp+1Ch] [ebp-8h]
  int tmp5b; // [esp+1Ch] [ebp-8h]
  int tmp5c; // [esp+1Ch] [ebp-8h]
  int tmp5d; // [esp+1Ch] [ebp-8h]
  int tmp5e; // [esp+1Ch] [ebp-8h]
  int tmp5f; // [esp+1Ch] [ebp-8h]
  int tmp5g; // [esp+1Ch] [ebp-8h]
  int tmp2; // [esp+20h] [ebp-4h]
  int tmp2a; // [esp+20h] [ebp-4h]
  int tmp2b; // [esp+20h] [ebp-4h]
  int tmp2c; // [esp+20h] [ebp-4h]
  int tmp2d; // [esp+20h] [ebp-4h]
  int tmp2e; // [esp+20h] [ebp-4h]
  int tmp2f; // [esp+20h] [ebp-4h]
  int tmp2g; // [esp+20h] [ebp-4h]
  int dataa; // [esp+2Ch] [ebp+8h]

  v1 = data + 2;
  for ( i = 2; i != 0; --i )
  {
    v2 = v1[5];
    v3 = *(v1 - 2);
    v4 = v1[4];
    v5 = v2 + v3;
    v6 = v3 - v2;
    v7 = *(v1 - 1);
    v8 = v7 + v4;
    tmp6 = v7 - v4;
    tmp2 = *v1 + v1[3];
    tmp5 = *v1 - v1[3];
    v9 = v1[1];
    v10 = v9 + v1[2];
    tmp4 = v9 - v1[2];
    v11 = v10 + v5;
    v12 = v5 - v10;
    *(v1 - 2) = v11 + v8 + tmp2;
    v1[2] = v11 - (v8 + tmp2);
    v13 = (181 * (v8 + v12 - tmp2)) >> 8;
    v1[4] = v12 - v13;
    *v1 = v13 + v12;
    v14 = (98 * (tmp4 + tmp5 - (tmp6 + v6))) >> 8;
    v15 = v14 + ((334 * (tmp6 + v6)) >> 8);
    v16 = v14 + ((139 * (tmp4 + tmp5)) >> 8);
    v17 = (181 * (tmp6 + tmp5)) >> 8;
    v18 = v17 + v6;
    v19 = v6 - v17;
    v20 = v19 + v16;
    v21 = v19 - v16;
    v22 = v18 + v15;
    v1[3] = v20;
    v23 = v1[13];
    v1[1] = v21;
    v24 = v1[6];
    v25 = v18 - v15;
    v26 = v1[12];
    *(v1 - 1) = v22;
    v27 = v23 + v24;
    v28 = v24 - v23;
    v29 = v1[7];
    v1[5] = v25;
    v30 = v29 + v26;
    tmp6a = v29 - v26;
    v31 = v1[8];
    tmp2a = v31 + v1[11];
    tmp5a = v31 - v1[11];
    v32 = v1[9];
    v33 = v32 + v1[10];
    tmp4a = v32 - v1[10];
    v34 = v33 + v27;
    v35 = v27 - v33;
    v1[6] = v34 + v30 + tmp2a;
    v1[10] = v34 - (v30 + tmp2a);
    v36 = (181 * (v30 + v35 - tmp2a)) >> 8;
    v1[12] = v35 - v36;
    v1[8] = v36 + v35;
    v37 = (98 * (tmp4a + tmp5a - (tmp6a + v28))) >> 8;
    v38 = v37 + ((334 * (tmp6a + v28)) >> 8);
    v39 = v37 + ((139 * (tmp4a + tmp5a)) >> 8);
    v40 = (181 * (tmp6a + tmp5a)) >> 8;
    v41 = v40 + v28;
    v42 = v28 - v40;
    v43 = v42 + v39;
    v44 = v42 - v39;
    v45 = v41 + v38;
    v1[11] = v43;
    v46 = v1[21];
    v47 = v41 - v38;
    v48 = v1[20];
    v1[9] = v44;
    v49 = v1[14];
    v1[7] = v45;
    v50 = v46 + v49;
    v51 = v49 - v46;
    v52 = v1[15];
    v1[13] = v47;
    v53 = v52 + v48;
    tmp6b = v52 - v48;
    v54 = v1[16];
    tmp2b = v54 + v1[19];
    tmp5b = v54 - v1[19];
    v55 = v1[17];
    v56 = v55 + v1[18];
    tmp4b = v55 - v1[18];
    v57 = v56 + v50;
    v58 = v50 - v56;
    v1[14] = v57 + v53 + tmp2b;
    v1[18] = v57 - (v53 + tmp2b);
    v59 = (181 * (v53 + v58 - tmp2b)) >> 8;
    v1[20] = v58 - v59;
    v1[16] = v59 + v58;
    v60 = (98 * (tmp4b + tmp5b - (tmp6b + v51))) >> 8;
    v61 = v60 + ((334 * (tmp6b + v51)) >> 8);
    v62 = v60 + ((139 * (tmp4b + tmp5b)) >> 8);
    v63 = (181 * (tmp6b + tmp5b)) >> 8;
    v64 = v63 + v51;
    v65 = v51 - v63;
    v1[19] = v65 + v62;
    v66 = v1[29];
    v67 = v65 - v62;
    v68 = v64 + v61;
    v69 = v64 - v61;
    v70 = v1[28];
    v1[15] = v68;
    v1[17] = v67;
    v71 = v1[22];
    v72 = v71 + v66;
    v73 = v71 - v66;
    v74 = v1[23];
    v1[21] = v69;
    v75 = v70 + v74;
    tmp6c = v74 - v70;
    v76 = v1[24];
    tmp2c = v76 + v1[27];
    tmp5c = v76 - v1[27];
    v77 = v1[25];
    v78 = v77 + v1[26];
    tmp4c = v77 - v1[26];
    v79 = v78 + v72;
    v80 = v72 - v78;
    v1[22] = v79 + v75 + tmp2c;
    v1[26] = v79 - (v75 + tmp2c);
    v81 = (181 * (v75 + v80 - tmp2c)) >> 8;
    v1[28] = v80 - v81;
    v1[24] = v81 + v80;
    v82 = (98 * (tmp4c + tmp5c - (tmp6c + v73))) >> 8;
    v83 = v82 + ((139 * (tmp4c + tmp5c)) >> 8);
    v84 = v82 + ((334 * (tmp6c + v73)) >> 8);
    v85 = (181 * (tmp6c + tmp5c)) >> 8;
    v86 = v85 + v73;
    v87 = v73 - v85;
    v1[27] = v87 + v83;
    v1[25] = v87 - v83;
    v1[23] = v86 + v84;
    v1[29] = v86 - v84;
    v1 += 32;
  }
  v88 = data + 16;
  for ( dataa = 2; dataa != 0; --dataa )
  {
    v89 = v88[40];
    v90 = *(v88 - 16);
    v91 = v88[32];
    v92 = v89 + v90;
    v93 = v90 - v89;
    v94 = *(v88 - 8);
    v95 = v94 + v91;
    tmp6d = v94 - v91;
    tmp2d = *v88 + v88[24];
    tmp5d = *v88 - v88[24];
    v96 = v88[8];
    v97 = v96 + v88[16];
    tmp4d = v96 - v88[16];
    v98 = v97 + v92;
    v99 = v92 - v97;
    *(v88 - 16) = v98 + v95 + tmp2d;
    v88[16] = v98 - (v95 + tmp2d);
    v100 = (181 * (v95 + v99 - tmp2d)) >> 8;
    v88[32] = v99 - v100;
    *v88 = v100 + v99;
    v101 = (98 * (tmp4d + tmp5d - (tmp6d + v93))) >> 8;
    v102 = v101 + ((334 * (tmp6d + v93)) >> 8);
    v103 = v101 + ((139 * (tmp4d + tmp5d)) >> 8);
    v104 = (181 * (tmp6d + tmp5d)) >> 8;
    v105 = v104 + v93;
    v106 = v93 - v104;
    v107 = v106 + v103;
    v108 = v106 - v103;
    v109 = v105 + v102;
    v88[24] = v107;
    v110 = v88[41];
    v88[8] = v108;
    v111 = *(v88 - 15);
    v112 = v105 - v102;
    v113 = v88[33];
    *(v88 - 8) = v109;
    v114 = v110 + v111;
    v115 = v111 - v110;
    v116 = *(v88 - 7);
    v88[40] = v112;
    v117 = v116 + v113;
    tmp6e = v116 - v113;
    v118 = v88[1];
    tmp2e = v118 + v88[25];
    tmp5e = v118 - v88[25];
    v119 = v88[9];
    v120 = v119 + v88[17];
    tmp4e = v119 - v88[17];
    v121 = v120 + v114;
    v122 = v114 - v120;
    *(v88 - 15) = v121 + v117 + tmp2e;
    v88[17] = v121 - (v117 + tmp2e);
    v123 = (181 * (v117 + v122 - tmp2e)) >> 8;
    v88[33] = v122 - v123;
    v88[1] = v123 + v122;
    v124 = (98 * (tmp4e + tmp5e - (tmp6e + v115))) >> 8;
    v125 = v124 + ((334 * (tmp6e + v115)) >> 8);
    v126 = v124 + ((139 * (tmp4e + tmp5e)) >> 8);
    v127 = (181 * (tmp6e + tmp5e)) >> 8;
    v128 = v127 + v115;
    v129 = v115 - v127;
    v130 = v129 + v126;
    v131 = v129 - v126;
    v132 = v128 + v125;
    v88[25] = v130;
    v133 = v88[42];
    v134 = v128 - v125;
    v135 = v88[34];
    v88[9] = v131;
    v136 = *(v88 - 14);
    *(v88 - 7) = v132;
    v137 = v133 + v136;
    v138 = v136 - v133;
    v139 = *(v88 - 6);
    v88[41] = v134;
    v140 = v139 + v135;
    tmp6f = v139 - v135;
    v141 = v88[2];
    tmp2f = v141 + v88[26];
    tmp5f = v141 - v88[26];
    v142 = v88[10];
    v143 = v142 + v88[18];
    tmp4f = v142 - v88[18];
    v144 = v143 + v137;
    v145 = v137 - v143;
    *(v88 - 14) = v144 + v140 + tmp2f;
    v88[18] = v144 - (v140 + tmp2f);
    v146 = (181 * (v140 + v145 - tmp2f)) >> 8;
    v88[34] = v145 - v146;
    v88[2] = v146 + v145;
    v147 = (98 * (tmp4f + tmp5f - (tmp6f + v138))) >> 8;
    v148 = v147 + ((334 * (tmp6f + v138)) >> 8);
    v149 = v147 + ((139 * (tmp4f + tmp5f)) >> 8);
    v150 = (181 * (tmp6f + tmp5f)) >> 8;
    v151 = v150 + v138;
    v152 = v138 - v150;
    v88[26] = v152 + v149;
    v153 = v88[43];
    v154 = v152 - v149;
    v155 = v151 + v148;
    v156 = v151 - v148;
    v157 = v88[35];
    *(v88 - 6) = v155;
    v88[10] = v154;
    v158 = *(v88 - 13);
    v159 = v158 + v153;
    v160 = v158 - v153;
    v161 = *(v88 - 5);
    v88[42] = v156;
    v162 = v157 + v161;
    tmp6g = v161 - v157;
    v163 = v88[3];
    tmp2g = v163 + v88[27];
    tmp5g = v163 - v88[27];
    v164 = v88[11];
    v165 = v164 + v88[19];
    tmp4g = v164 - v88[19];
    v166 = v165 + v159;
    v167 = v159 - v165;
    *(v88 - 13) = v166 + v162 + tmp2g;
    v88[19] = v166 - (v162 + tmp2g);
    v168 = (181 * (v162 + v167 - tmp2g)) >> 8;
    v88[35] = v167 - v168;
    v88[3] = v168 + v167;
    v169 = (98 * (tmp4g + tmp5g - (tmp6g + v160))) >> 8;
    v170 = v169 + ((139 * (tmp4g + tmp5g)) >> 8);
    v171 = v169 + ((334 * (tmp6g + v160)) >> 8);
    v172 = (181 * (tmp6g + tmp5g)) >> 8;
    v173 = v172 + v160;
    v174 = v160 - v172;
    v88[27] = v174 + v170;
    v88[11] = v174 - v170;
    *(v88 - 5) = v173 + v171;
    v88[43] = v173 - v171;
    v88 += 4;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10258C50
// Name: _jpeg_fdct_ifast
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_fdct_ifast(int *data)
{
  int *v1; // eax
  int v2; // ecx
  int v3; // edi
  int v4; // esi
  int v5; // edx
  int v6; // edi
  int v7; // ecx
  int v8; // ebx
  int v9; // ecx
  int v10; // esi
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // ecx
  int v15; // esi
  int v16; // edx
  int v17; // ecx
  int v18; // ebx
  int v19; // edi
  int v20; // ecx
  int v21; // edi
  int v22; // edx
  int v23; // ecx
  int v24; // edi
  int v25; // ebx
  int v26; // esi
  int v27; // edx
  int v28; // edi
  int v29; // ecx
  int v30; // ebx
  int v31; // ecx
  int v32; // ecx
  int v33; // esi
  int v34; // ecx
  int v35; // edx
  int v36; // ecx
  int v37; // ecx
  int v38; // esi
  int v39; // edx
  int v40; // ecx
  int v41; // ebx
  int v42; // edi
  int v43; // ecx
  int v44; // edi
  int v45; // edx
  int v46; // ecx
  int v47; // ebx
  int v48; // esi
  int v49; // edi
  int v50; // edx
  int v51; // edi
  int v52; // ecx
  int v53; // ebx
  int v54; // ecx
  int v55; // ecx
  int v56; // esi
  int v57; // ecx
  int v58; // edx
  int v59; // ecx
  int v60; // ecx
  int v61; // esi
  int v62; // edx
  int v63; // ecx
  int v64; // ebx
  int v65; // edi
  int v66; // ecx
  int v67; // edi
  int v68; // edx
  int v69; // ebx
  int v70; // esi
  int v71; // edi
  int v72; // edx
  int v73; // edi
  int v74; // ecx
  int v75; // ebx
  int v76; // ecx
  int v77; // ecx
  int v78; // esi
  int v79; // ecx
  int v80; // edx
  int v81; // ecx
  int v82; // ecx
  int v83; // edx
  int v84; // esi
  int v85; // ecx
  int v86; // ebx
  int v87; // edi
  int *v88; // eax
  int v89; // ecx
  int v90; // edi
  int v91; // esi
  int v92; // edx
  int v93; // edi
  int v94; // ecx
  int v95; // ebx
  int v96; // ecx
  int v97; // esi
  int v98; // ecx
  int v99; // edx
  int v100; // ecx
  int v101; // ecx
  int v102; // esi
  int v103; // edx
  int v104; // ecx
  int v105; // ebx
  int v106; // edi
  int v107; // ecx
  int v108; // edi
  int v109; // edx
  int v110; // ecx
  int v111; // edi
  int v112; // ebx
  int v113; // esi
  int v114; // edx
  int v115; // edi
  int v116; // ecx
  int v117; // ebx
  int v118; // ecx
  int v119; // ecx
  int v120; // esi
  int v121; // ecx
  int v122; // edx
  int v123; // ecx
  int v124; // ecx
  int v125; // esi
  int v126; // edx
  int v127; // ecx
  int v128; // ebx
  int v129; // edi
  int v130; // ecx
  int v131; // edi
  int v132; // edx
  int v133; // ecx
  int v134; // ebx
  int v135; // esi
  int v136; // edi
  int v137; // edx
  int v138; // edi
  int v139; // ecx
  int v140; // ebx
  int v141; // ecx
  int v142; // ecx
  int v143; // esi
  int v144; // ecx
  int v145; // edx
  int v146; // ecx
  int v147; // ecx
  int v148; // esi
  int v149; // edx
  int v150; // ecx
  int v151; // ebx
  int v152; // edi
  int v153; // ecx
  int v154; // edi
  int v155; // edx
  int v156; // ebx
  int v157; // esi
  int v158; // edi
  int v159; // edx
  int v160; // edi
  int v161; // ecx
  int v162; // ebx
  int v163; // ecx
  int v164; // ecx
  int v165; // esi
  int v166; // ecx
  int v167; // edx
  int v168; // ecx
  int v169; // ecx
  int v170; // edx
  int v171; // esi
  int v172; // ecx
  int v173; // ebx
  int v174; // edi
  int i; // [esp+Ch] [ebp-18h]
  int tmp6; // [esp+10h] [ebp-14h]
  int tmp6a; // [esp+10h] [ebp-14h]
  int tmp6b; // [esp+10h] [ebp-14h]
  int tmp6c; // [esp+10h] [ebp-14h]
  int tmp6d; // [esp+10h] [ebp-14h]
  int tmp6e; // [esp+10h] [ebp-14h]
  int tmp6f; // [esp+10h] [ebp-14h]
  int tmp6g; // [esp+10h] [ebp-14h]
  int tmp4; // [esp+14h] [ebp-10h]
  int tmp4a; // [esp+14h] [ebp-10h]
  int tmp4b; // [esp+14h] [ebp-10h]
  int tmp4c; // [esp+14h] [ebp-10h]
  int tmp4d; // [esp+14h] [ebp-10h]
  int tmp4e; // [esp+14h] [ebp-10h]
  int tmp4f; // [esp+14h] [ebp-10h]
  int tmp4g; // [esp+14h] [ebp-10h]
  int tmp5; // [esp+1Ch] [ebp-8h]
  int tmp5a; // [esp+1Ch] [ebp-8h]
  int tmp5b; // [esp+1Ch] [ebp-8h]
  int tmp5c; // [esp+1Ch] [ebp-8h]
  int tmp5d; // [esp+1Ch] [ebp-8h]
  int tmp5e; // [esp+1Ch] [ebp-8h]
  int tmp5f; // [esp+1Ch] [ebp-8h]
  int tmp5g; // [esp+1Ch] [ebp-8h]
  int tmp2; // [esp+20h] [ebp-4h]
  int tmp2a; // [esp+20h] [ebp-4h]
  int tmp2b; // [esp+20h] [ebp-4h]
  int tmp2c; // [esp+20h] [ebp-4h]
  int tmp2d; // [esp+20h] [ebp-4h]
  int tmp2e; // [esp+20h] [ebp-4h]
  int tmp2f; // [esp+20h] [ebp-4h]
  int tmp2g; // [esp+20h] [ebp-4h]
  int dataa; // [esp+2Ch] [ebp+8h]

  v1 = data + 2;
  for ( i = 2; i != 0; --i )
  {
    v2 = v1[5];
    v3 = *(v1 - 2);
    v4 = v1[4];
    v5 = v2 + v3;
    v6 = v3 - v2;
    v7 = *(v1 - 1);
    v8 = v7 + v4;
    tmp6 = v7 - v4;
    tmp2 = *v1 + v1[3];
    tmp5 = *v1 - v1[3];
    v9 = v1[1];
    v10 = v9 + v1[2];
    tmp4 = v9 - v1[2];
    v11 = v10 + v5;
    v12 = v5 - v10;
    *(v1 - 2) = v11 + v8 + tmp2;
    v1[2] = v11 - (v8 + tmp2);
    v13 = (181 * (v8 + v12 - tmp2)) >> 8;
    v1[4] = v12 - v13;
    *v1 = v13 + v12;
    v14 = (98 * (tmp4 + tmp5 - (tmp6 + v6))) >> 8;
    v15 = v14 + ((334 * (tmp6 + v6)) >> 8);
    v16 = v14 + ((139 * (tmp4 + tmp5)) >> 8);
    v17 = (181 * (tmp6 + tmp5)) >> 8;
    v18 = v17 + v6;
    v19 = v6 - v17;
    v20 = v19 + v16;
    v21 = v19 - v16;
    v22 = v18 + v15;
    v1[3] = v20;
    v23 = v1[13];
    v1[1] = v21;
    v24 = v1[6];
    v25 = v18 - v15;
    v26 = v1[12];
    *(v1 - 1) = v22;
    v27 = v23 + v24;
    v28 = v24 - v23;
    v29 = v1[7];
    v1[5] = v25;
    v30 = v29 + v26;
    tmp6a = v29 - v26;
    v31 = v1[8];
    tmp2a = v31 + v1[11];
    tmp5a = v31 - v1[11];
    v32 = v1[9];
    v33 = v32 + v1[10];
    tmp4a = v32 - v1[10];
    v34 = v33 + v27;
    v35 = v27 - v33;
    v1[6] = v34 + v30 + tmp2a;
    v1[10] = v34 - (v30 + tmp2a);
    v36 = (181 * (v30 + v35 - tmp2a)) >> 8;
    v1[12] = v35 - v36;
    v1[8] = v36 + v35;
    v37 = (98 * (tmp4a + tmp5a - (tmp6a + v28))) >> 8;
    v38 = v37 + ((334 * (tmp6a + v28)) >> 8);
    v39 = v37 + ((139 * (tmp4a + tmp5a)) >> 8);
    v40 = (181 * (tmp6a + tmp5a)) >> 8;
    v41 = v40 + v28;
    v42 = v28 - v40;
    v43 = v42 + v39;
    v44 = v42 - v39;
    v45 = v41 + v38;
    v1[11] = v43;
    v46 = v1[21];
    v47 = v41 - v38;
    v48 = v1[20];
    v1[9] = v44;
    v49 = v1[14];
    v1[7] = v45;
    v50 = v46 + v49;
    v51 = v49 - v46;
    v52 = v1[15];
    v1[13] = v47;
    v53 = v52 + v48;
    tmp6b = v52 - v48;
    v54 = v1[16];
    tmp2b = v54 + v1[19];
    tmp5b = v54 - v1[19];
    v55 = v1[17];
    v56 = v55 + v1[18];
    tmp4b = v55 - v1[18];
    v57 = v56 + v50;
    v58 = v50 - v56;
    v1[14] = v57 + v53 + tmp2b;
    v1[18] = v57 - (v53 + tmp2b);
    v59 = (181 * (v53 + v58 - tmp2b)) >> 8;
    v1[20] = v58 - v59;
    v1[16] = v59 + v58;
    v60 = (98 * (tmp4b + tmp5b - (tmp6b + v51))) >> 8;
    v61 = v60 + ((334 * (tmp6b + v51)) >> 8);
    v62 = v60 + ((139 * (tmp4b + tmp5b)) >> 8);
    v63 = (181 * (tmp6b + tmp5b)) >> 8;
    v64 = v63 + v51;
    v65 = v51 - v63;
    v1[19] = v65 + v62;
    v66 = v1[29];
    v67 = v65 - v62;
    v68 = v64 + v61;
    v69 = v64 - v61;
    v70 = v1[28];
    v1[15] = v68;
    v1[17] = v67;
    v71 = v1[22];
    v72 = v71 + v66;
    v73 = v71 - v66;
    v74 = v1[23];
    v1[21] = v69;
    v75 = v70 + v74;
    tmp6c = v74 - v70;
    v76 = v1[24];
    tmp2c = v76 + v1[27];
    tmp5c = v76 - v1[27];
    v77 = v1[25];
    v78 = v77 + v1[26];
    tmp4c = v77 - v1[26];
    v79 = v78 + v72;
    v80 = v72 - v78;
    v1[22] = v79 + v75 + tmp2c;
    v1[26] = v79 - (v75 + tmp2c);
    v81 = (181 * (v75 + v80 - tmp2c)) >> 8;
    v1[28] = v80 - v81;
    v1[24] = v81 + v80;
    v82 = (98 * (tmp4c + tmp5c - (tmp6c + v73))) >> 8;
    v83 = v82 + ((139 * (tmp4c + tmp5c)) >> 8);
    v84 = v82 + ((334 * (tmp6c + v73)) >> 8);
    v85 = (181 * (tmp6c + tmp5c)) >> 8;
    v86 = v85 + v73;
    v87 = v73 - v85;
    v1[27] = v87 + v83;
    v1[25] = v87 - v83;
    v1[23] = v86 + v84;
    v1[29] = v86 - v84;
    v1 += 32;
  }
  v88 = data + 16;
  for ( dataa = 2; dataa != 0; --dataa )
  {
    v89 = v88[40];
    v90 = *(v88 - 16);
    v91 = v88[32];
    v92 = v89 + v90;
    v93 = v90 - v89;
    v94 = *(v88 - 8);
    v95 = v94 + v91;
    tmp6d = v94 - v91;
    tmp2d = *v88 + v88[24];
    tmp5d = *v88 - v88[24];
    v96 = v88[8];
    v97 = v96 + v88[16];
    tmp4d = v96 - v88[16];
    v98 = v97 + v92;
    v99 = v92 - v97;
    *(v88 - 16) = v98 + v95 + tmp2d;
    v88[16] = v98 - (v95 + tmp2d);
    v100 = (181 * (v95 + v99 - tmp2d)) >> 8;
    v88[32] = v99 - v100;
    *v88 = v100 + v99;
    v101 = (98 * (tmp4d + tmp5d - (tmp6d + v93))) >> 8;
    v102 = v101 + ((334 * (tmp6d + v93)) >> 8);
    v103 = v101 + ((139 * (tmp4d + tmp5d)) >> 8);
    v104 = (181 * (tmp6d + tmp5d)) >> 8;
    v105 = v104 + v93;
    v106 = v93 - v104;
    v107 = v106 + v103;
    v108 = v106 - v103;
    v109 = v105 + v102;
    v88[24] = v107;
    v110 = v88[41];
    v88[8] = v108;
    v111 = *(v88 - 15);
    v112 = v105 - v102;
    v113 = v88[33];
    *(v88 - 8) = v109;
    v114 = v110 + v111;
    v115 = v111 - v110;
    v116 = *(v88 - 7);
    v88[40] = v112;
    v117 = v116 + v113;
    tmp6e = v116 - v113;
    v118 = v88[1];
    tmp2e = v118 + v88[25];
    tmp5e = v118 - v88[25];
    v119 = v88[9];
    v120 = v119 + v88[17];
    tmp4e = v119 - v88[17];
    v121 = v120 + v114;
    v122 = v114 - v120;
    *(v88 - 15) = v121 + v117 + tmp2e;
    v88[17] = v121 - (v117 + tmp2e);
    v123 = (181 * (v117 + v122 - tmp2e)) >> 8;
    v88[33] = v122 - v123;
    v88[1] = v123 + v122;
    v124 = (98 * (tmp4e + tmp5e - (tmp6e + v115))) >> 8;
    v125 = v124 + ((334 * (tmp6e + v115)) >> 8);
    v126 = v124 + ((139 * (tmp4e + tmp5e)) >> 8);
    v127 = (181 * (tmp6e + tmp5e)) >> 8;
    v128 = v127 + v115;
    v129 = v115 - v127;
    v130 = v129 + v126;
    v131 = v129 - v126;
    v132 = v128 + v125;
    v88[25] = v130;
    v133 = v88[42];
    v134 = v128 - v125;
    v135 = v88[34];
    v88[9] = v131;
    v136 = *(v88 - 14);
    *(v88 - 7) = v132;
    v137 = v133 + v136;
    v138 = v136 - v133;
    v139 = *(v88 - 6);
    v88[41] = v134;
    v140 = v139 + v135;
    tmp6f = v139 - v135;
    v141 = v88[2];
    tmp2f = v141 + v88[26];
    tmp5f = v141 - v88[26];
    v142 = v88[10];
    v143 = v142 + v88[18];
    tmp4f = v142 - v88[18];
    v144 = v143 + v137;
    v145 = v137 - v143;
    *(v88 - 14) = v144 + v140 + tmp2f;
    v88[18] = v144 - (v140 + tmp2f);
    v146 = (181 * (v140 + v145 - tmp2f)) >> 8;
    v88[34] = v145 - v146;
    v88[2] = v146 + v145;
    v147 = (98 * (tmp4f + tmp5f - (tmp6f + v138))) >> 8;
    v148 = v147 + ((334 * (tmp6f + v138)) >> 8);
    v149 = v147 + ((139 * (tmp4f + tmp5f)) >> 8);
    v150 = (181 * (tmp6f + tmp5f)) >> 8;
    v151 = v150 + v138;
    v152 = v138 - v150;
    v88[26] = v152 + v149;
    v153 = v88[43];
    v154 = v152 - v149;
    v155 = v151 + v148;
    v156 = v151 - v148;
    v157 = v88[35];
    *(v88 - 6) = v155;
    v88[10] = v154;
    v158 = *(v88 - 13);
    v159 = v158 + v153;
    v160 = v158 - v153;
    v161 = *(v88 - 5);
    v88[42] = v156;
    v162 = v157 + v161;
    tmp6g = v161 - v157;
    v163 = v88[3];
    tmp2g = v163 + v88[27];
    tmp5g = v163 - v88[27];
    v164 = v88[11];
    v165 = v164 + v88[19];
    tmp4g = v164 - v88[19];
    v166 = v165 + v159;
    v167 = v159 - v165;
    *(v88 - 13) = v166 + v162 + tmp2g;
    v88[19] = v166 - (v162 + tmp2g);
    v168 = (181 * (v162 + v167 - tmp2g)) >> 8;
    v88[35] = v167 - v168;
    v88[3] = v168 + v167;
    v169 = (98 * (tmp4g + tmp5g - (tmp6g + v160))) >> 8;
    v170 = v169 + ((139 * (tmp4g + tmp5g)) >> 8);
    v171 = v169 + ((334 * (tmp6g + v160)) >> 8);
    v172 = (181 * (tmp6g + tmp5g)) >> 8;
    v173 = v172 + v160;
    v174 = v160 - v172;
    v88[27] = v174 + v170;
    v88[11] = v174 - v170;
    *(v88 - 5) = v173 + v171;
    v88[43] = v173 - v171;
    v88 += 4;
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x0040D170
// Name: _jpeg_fdct_ifast
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_fdct_ifast(int *data)
{
  int *v1; // eax
  int v2; // ecx
  int v3; // edi
  int v4; // esi
  int v5; // edx
  int v6; // edi
  int v7; // ecx
  int v8; // ebx
  int v9; // ecx
  int v10; // esi
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // ecx
  int v15; // esi
  int v16; // edx
  int v17; // ecx
  int v18; // ebx
  int v19; // edi
  int v20; // ecx
  int v21; // edi
  int v22; // edx
  int v23; // ecx
  int v24; // edi
  int v25; // ebx
  int v26; // esi
  int v27; // edx
  int v28; // edi
  int v29; // ecx
  int v30; // ebx
  int v31; // ecx
  int v32; // ecx
  int v33; // esi
  int v34; // ecx
  int v35; // edx
  int v36; // ecx
  int v37; // ecx
  int v38; // esi
  int v39; // edx
  int v40; // ecx
  int v41; // ebx
  int v42; // edi
  int v43; // ecx
  int v44; // edi
  int v45; // edx
  int v46; // ecx
  int v47; // ebx
  int v48; // esi
  int v49; // edi
  int v50; // edx
  int v51; // edi
  int v52; // ecx
  int v53; // ebx
  int v54; // ecx
  int v55; // ecx
  int v56; // esi
  int v57; // ecx
  int v58; // edx
  int v59; // ecx
  int v60; // ecx
  int v61; // esi
  int v62; // edx
  int v63; // ecx
  int v64; // ebx
  int v65; // edi
  int v66; // ecx
  int v67; // edi
  int v68; // edx
  int v69; // ebx
  int v70; // esi
  int v71; // edi
  int v72; // edx
  int v73; // edi
  int v74; // ecx
  int v75; // ebx
  int v76; // ecx
  int v77; // ecx
  int v78; // esi
  int v79; // ecx
  int v80; // edx
  int v81; // ecx
  int v82; // ecx
  int v83; // edx
  int v84; // esi
  int v85; // ecx
  int v86; // ebx
  int v87; // edi
  int *v88; // eax
  int v89; // ecx
  int v90; // edi
  int v91; // esi
  int v92; // edx
  int v93; // edi
  int v94; // ecx
  int v95; // ebx
  int v96; // ecx
  int v97; // esi
  int v98; // ecx
  int v99; // edx
  int v100; // ecx
  int v101; // ecx
  int v102; // esi
  int v103; // edx
  int v104; // ecx
  int v105; // ebx
  int v106; // edi
  int v107; // ecx
  int v108; // edi
  int v109; // edx
  int v110; // ecx
  int v111; // edi
  int v112; // ebx
  int v113; // esi
  int v114; // edx
  int v115; // edi
  int v116; // ecx
  int v117; // ebx
  int v118; // ecx
  int v119; // ecx
  int v120; // esi
  int v121; // ecx
  int v122; // edx
  int v123; // ecx
  int v124; // ecx
  int v125; // esi
  int v126; // edx
  int v127; // ecx
  int v128; // ebx
  int v129; // edi
  int v130; // ecx
  int v131; // edi
  int v132; // edx
  int v133; // ecx
  int v134; // ebx
  int v135; // esi
  int v136; // edi
  int v137; // edx
  int v138; // edi
  int v139; // ecx
  int v140; // ebx
  int v141; // ecx
  int v142; // ecx
  int v143; // esi
  int v144; // ecx
  int v145; // edx
  int v146; // ecx
  int v147; // ecx
  int v148; // esi
  int v149; // edx
  int v150; // ecx
  int v151; // ebx
  int v152; // edi
  int v153; // ecx
  int v154; // edi
  int v155; // edx
  int v156; // ebx
  int v157; // esi
  int v158; // edi
  int v159; // edx
  int v160; // edi
  int v161; // ecx
  int v162; // ebx
  int v163; // ecx
  int v164; // ecx
  int v165; // esi
  int v166; // ecx
  int v167; // edx
  int v168; // ecx
  int v169; // ecx
  int v170; // edx
  int v171; // esi
  int v172; // ecx
  int v173; // ebx
  int v174; // edi
  int i; // [esp+Ch] [ebp-18h]
  int tmp6; // [esp+10h] [ebp-14h]
  int tmp6a; // [esp+10h] [ebp-14h]
  int tmp6b; // [esp+10h] [ebp-14h]
  int tmp6c; // [esp+10h] [ebp-14h]
  int tmp6d; // [esp+10h] [ebp-14h]
  int tmp6e; // [esp+10h] [ebp-14h]
  int tmp6f; // [esp+10h] [ebp-14h]
  int tmp6g; // [esp+10h] [ebp-14h]
  int tmp4; // [esp+14h] [ebp-10h]
  int tmp4a; // [esp+14h] [ebp-10h]
  int tmp4b; // [esp+14h] [ebp-10h]
  int tmp4c; // [esp+14h] [ebp-10h]
  int tmp4d; // [esp+14h] [ebp-10h]
  int tmp4e; // [esp+14h] [ebp-10h]
  int tmp4f; // [esp+14h] [ebp-10h]
  int tmp4g; // [esp+14h] [ebp-10h]
  int tmp5; // [esp+1Ch] [ebp-8h]
  int tmp5a; // [esp+1Ch] [ebp-8h]
  int tmp5b; // [esp+1Ch] [ebp-8h]
  int tmp5c; // [esp+1Ch] [ebp-8h]
  int tmp5d; // [esp+1Ch] [ebp-8h]
  int tmp5e; // [esp+1Ch] [ebp-8h]
  int tmp5f; // [esp+1Ch] [ebp-8h]
  int tmp5g; // [esp+1Ch] [ebp-8h]
  int tmp2; // [esp+20h] [ebp-4h]
  int tmp2a; // [esp+20h] [ebp-4h]
  int tmp2b; // [esp+20h] [ebp-4h]
  int tmp2c; // [esp+20h] [ebp-4h]
  int tmp2d; // [esp+20h] [ebp-4h]
  int tmp2e; // [esp+20h] [ebp-4h]
  int tmp2f; // [esp+20h] [ebp-4h]
  int tmp2g; // [esp+20h] [ebp-4h]
  int dataa; // [esp+2Ch] [ebp+8h]

  v1 = data + 2;
  for ( i = 2; i != 0; --i )
  {
    v2 = v1[5];
    v3 = *(v1 - 2);
    v4 = v1[4];
    v5 = v2 + v3;
    v6 = v3 - v2;
    v7 = *(v1 - 1);
    v8 = v7 + v4;
    tmp6 = v7 - v4;
    tmp2 = *v1 + v1[3];
    tmp5 = *v1 - v1[3];
    v9 = v1[1];
    v10 = v9 + v1[2];
    tmp4 = v9 - v1[2];
    v11 = v10 + v5;
    v12 = v5 - v10;
    *(v1 - 2) = v11 + v8 + tmp2;
    v1[2] = v11 - (v8 + tmp2);
    v13 = (181 * (v8 + v12 - tmp2)) >> 8;
    v1[4] = v12 - v13;
    *v1 = v13 + v12;
    v14 = (98 * (tmp4 + tmp5 - (tmp6 + v6))) >> 8;
    v15 = v14 + ((334 * (tmp6 + v6)) >> 8);
    v16 = v14 + ((139 * (tmp4 + tmp5)) >> 8);
    v17 = (181 * (tmp6 + tmp5)) >> 8;
    v18 = v17 + v6;
    v19 = v6 - v17;
    v20 = v19 + v16;
    v21 = v19 - v16;
    v22 = v18 + v15;
    v1[3] = v20;
    v23 = v1[13];
    v1[1] = v21;
    v24 = v1[6];
    v25 = v18 - v15;
    v26 = v1[12];
    *(v1 - 1) = v22;
    v27 = v23 + v24;
    v28 = v24 - v23;
    v29 = v1[7];
    v1[5] = v25;
    v30 = v29 + v26;
    tmp6a = v29 - v26;
    v31 = v1[8];
    tmp2a = v31 + v1[11];
    tmp5a = v31 - v1[11];
    v32 = v1[9];
    v33 = v32 + v1[10];
    tmp4a = v32 - v1[10];
    v34 = v33 + v27;
    v35 = v27 - v33;
    v1[6] = v34 + v30 + tmp2a;
    v1[10] = v34 - (v30 + tmp2a);
    v36 = (181 * (v30 + v35 - tmp2a)) >> 8;
    v1[12] = v35 - v36;
    v1[8] = v36 + v35;
    v37 = (98 * (tmp4a + tmp5a - (tmp6a + v28))) >> 8;
    v38 = v37 + ((334 * (tmp6a + v28)) >> 8);
    v39 = v37 + ((139 * (tmp4a + tmp5a)) >> 8);
    v40 = (181 * (tmp6a + tmp5a)) >> 8;
    v41 = v40 + v28;
    v42 = v28 - v40;
    v43 = v42 + v39;
    v44 = v42 - v39;
    v45 = v41 + v38;
    v1[11] = v43;
    v46 = v1[21];
    v47 = v41 - v38;
    v48 = v1[20];
    v1[9] = v44;
    v49 = v1[14];
    v1[7] = v45;
    v50 = v46 + v49;
    v51 = v49 - v46;
    v52 = v1[15];
    v1[13] = v47;
    v53 = v52 + v48;
    tmp6b = v52 - v48;
    v54 = v1[16];
    tmp2b = v54 + v1[19];
    tmp5b = v54 - v1[19];
    v55 = v1[17];
    v56 = v55 + v1[18];
    tmp4b = v55 - v1[18];
    v57 = v56 + v50;
    v58 = v50 - v56;
    v1[14] = v57 + v53 + tmp2b;
    v1[18] = v57 - (v53 + tmp2b);
    v59 = (181 * (v53 + v58 - tmp2b)) >> 8;
    v1[20] = v58 - v59;
    v1[16] = v59 + v58;
    v60 = (98 * (tmp4b + tmp5b - (tmp6b + v51))) >> 8;
    v61 = v60 + ((334 * (tmp6b + v51)) >> 8);
    v62 = v60 + ((139 * (tmp4b + tmp5b)) >> 8);
    v63 = (181 * (tmp6b + tmp5b)) >> 8;
    v64 = v63 + v51;
    v65 = v51 - v63;
    v1[19] = v65 + v62;
    v66 = v1[29];
    v67 = v65 - v62;
    v68 = v64 + v61;
    v69 = v64 - v61;
    v70 = v1[28];
    v1[15] = v68;
    v1[17] = v67;
    v71 = v1[22];
    v72 = v71 + v66;
    v73 = v71 - v66;
    v74 = v1[23];
    v1[21] = v69;
    v75 = v70 + v74;
    tmp6c = v74 - v70;
    v76 = v1[24];
    tmp2c = v76 + v1[27];
    tmp5c = v76 - v1[27];
    v77 = v1[25];
    v78 = v77 + v1[26];
    tmp4c = v77 - v1[26];
    v79 = v78 + v72;
    v80 = v72 - v78;
    v1[22] = v79 + v75 + tmp2c;
    v1[26] = v79 - (v75 + tmp2c);
    v81 = (181 * (v75 + v80 - tmp2c)) >> 8;
    v1[28] = v80 - v81;
    v1[24] = v81 + v80;
    v82 = (98 * (tmp4c + tmp5c - (tmp6c + v73))) >> 8;
    v83 = v82 + ((139 * (tmp4c + tmp5c)) >> 8);
    v84 = v82 + ((334 * (tmp6c + v73)) >> 8);
    v85 = (181 * (tmp6c + tmp5c)) >> 8;
    v86 = v85 + v73;
    v87 = v73 - v85;
    v1[27] = v87 + v83;
    v1[25] = v87 - v83;
    v1[23] = v86 + v84;
    v1[29] = v86 - v84;
    v1 += 32;
  }
  v88 = data + 16;
  for ( dataa = 2; dataa != 0; --dataa )
  {
    v89 = v88[40];
    v90 = *(v88 - 16);
    v91 = v88[32];
    v92 = v89 + v90;
    v93 = v90 - v89;
    v94 = *(v88 - 8);
    v95 = v94 + v91;
    tmp6d = v94 - v91;
    tmp2d = *v88 + v88[24];
    tmp5d = *v88 - v88[24];
    v96 = v88[8];
    v97 = v96 + v88[16];
    tmp4d = v96 - v88[16];
    v98 = v97 + v92;
    v99 = v92 - v97;
    *(v88 - 16) = v98 + v95 + tmp2d;
    v88[16] = v98 - (v95 + tmp2d);
    v100 = (181 * (v95 + v99 - tmp2d)) >> 8;
    v88[32] = v99 - v100;
    *v88 = v100 + v99;
    v101 = (98 * (tmp4d + tmp5d - (tmp6d + v93))) >> 8;
    v102 = v101 + ((334 * (tmp6d + v93)) >> 8);
    v103 = v101 + ((139 * (tmp4d + tmp5d)) >> 8);
    v104 = (181 * (tmp6d + tmp5d)) >> 8;
    v105 = v104 + v93;
    v106 = v93 - v104;
    v107 = v106 + v103;
    v108 = v106 - v103;
    v109 = v105 + v102;
    v88[24] = v107;
    v110 = v88[41];
    v88[8] = v108;
    v111 = *(v88 - 15);
    v112 = v105 - v102;
    v113 = v88[33];
    *(v88 - 8) = v109;
    v114 = v110 + v111;
    v115 = v111 - v110;
    v116 = *(v88 - 7);
    v88[40] = v112;
    v117 = v116 + v113;
    tmp6e = v116 - v113;
    v118 = v88[1];
    tmp2e = v118 + v88[25];
    tmp5e = v118 - v88[25];
    v119 = v88[9];
    v120 = v119 + v88[17];
    tmp4e = v119 - v88[17];
    v121 = v120 + v114;
    v122 = v114 - v120;
    *(v88 - 15) = v121 + v117 + tmp2e;
    v88[17] = v121 - (v117 + tmp2e);
    v123 = (181 * (v117 + v122 - tmp2e)) >> 8;
    v88[33] = v122 - v123;
    v88[1] = v123 + v122;
    v124 = (98 * (tmp4e + tmp5e - (tmp6e + v115))) >> 8;
    v125 = v124 + ((334 * (tmp6e + v115)) >> 8);
    v126 = v124 + ((139 * (tmp4e + tmp5e)) >> 8);
    v127 = (181 * (tmp6e + tmp5e)) >> 8;
    v128 = v127 + v115;
    v129 = v115 - v127;
    v130 = v129 + v126;
    v131 = v129 - v126;
    v132 = v128 + v125;
    v88[25] = v130;
    v133 = v88[42];
    v134 = v128 - v125;
    v135 = v88[34];
    v88[9] = v131;
    v136 = *(v88 - 14);
    *(v88 - 7) = v132;
    v137 = v133 + v136;
    v138 = v136 - v133;
    v139 = *(v88 - 6);
    v88[41] = v134;
    v140 = v139 + v135;
    tmp6f = v139 - v135;
    v141 = v88[2];
    tmp2f = v141 + v88[26];
    tmp5f = v141 - v88[26];
    v142 = v88[10];
    v143 = v142 + v88[18];
    tmp4f = v142 - v88[18];
    v144 = v143 + v137;
    v145 = v137 - v143;
    *(v88 - 14) = v144 + v140 + tmp2f;
    v88[18] = v144 - (v140 + tmp2f);
    v146 = (181 * (v140 + v145 - tmp2f)) >> 8;
    v88[34] = v145 - v146;
    v88[2] = v146 + v145;
    v147 = (98 * (tmp4f + tmp5f - (tmp6f + v138))) >> 8;
    v148 = v147 + ((334 * (tmp6f + v138)) >> 8);
    v149 = v147 + ((139 * (tmp4f + tmp5f)) >> 8);
    v150 = (181 * (tmp6f + tmp5f)) >> 8;
    v151 = v150 + v138;
    v152 = v138 - v150;
    v88[26] = v152 + v149;
    v153 = v88[43];
    v154 = v152 - v149;
    v155 = v151 + v148;
    v156 = v151 - v148;
    v157 = v88[35];
    *(v88 - 6) = v155;
    v88[10] = v154;
    v158 = *(v88 - 13);
    v159 = v158 + v153;
    v160 = v158 - v153;
    v161 = *(v88 - 5);
    v88[42] = v156;
    v162 = v157 + v161;
    tmp6g = v161 - v157;
    v163 = v88[3];
    tmp2g = v163 + v88[27];
    tmp5g = v163 - v88[27];
    v164 = v88[11];
    v165 = v164 + v88[19];
    tmp4g = v164 - v88[19];
    v166 = v165 + v159;
    v167 = v159 - v165;
    *(v88 - 13) = v166 + v162 + tmp2g;
    v88[19] = v166 - (v162 + tmp2g);
    v168 = (181 * (v162 + v167 - tmp2g)) >> 8;
    v88[35] = v167 - v168;
    v88[3] = v168 + v167;
    v169 = (98 * (tmp4g + tmp5g - (tmp6g + v160))) >> 8;
    v170 = v169 + ((139 * (tmp4g + tmp5g)) >> 8);
    v171 = v169 + ((334 * (tmp6g + v160)) >> 8);
    v172 = (181 * (tmp6g + tmp5g)) >> 8;
    v173 = v172 + v160;
    v174 = v160 - v172;
    v88[27] = v174 + v170;
    v88[11] = v174 - v170;
    *(v88 - 5) = v173 + v171;
    v88[43] = v173 - v171;
    v88 += 4;
  }
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x00436480
// Name: _jpeg_fdct_ifast
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_fdct_ifast(int *data)
{
  int *v1; // eax
  int v2; // ecx
  int v3; // edi
  int v4; // esi
  int v5; // edx
  int v6; // edi
  int v7; // ecx
  int v8; // ebx
  int v9; // ecx
  int v10; // esi
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // ecx
  int v15; // esi
  int v16; // edx
  int v17; // ecx
  int v18; // ebx
  int v19; // edi
  int v20; // ecx
  int v21; // edi
  int v22; // edx
  int v23; // ecx
  int v24; // edi
  int v25; // ebx
  int v26; // esi
  int v27; // edx
  int v28; // edi
  int v29; // ecx
  int v30; // ebx
  int v31; // ecx
  int v32; // ecx
  int v33; // esi
  int v34; // ecx
  int v35; // edx
  int v36; // ecx
  int v37; // ecx
  int v38; // esi
  int v39; // edx
  int v40; // ecx
  int v41; // ebx
  int v42; // edi
  int v43; // ecx
  int v44; // edi
  int v45; // edx
  int v46; // ecx
  int v47; // ebx
  int v48; // esi
  int v49; // edi
  int v50; // edx
  int v51; // edi
  int v52; // ecx
  int v53; // ebx
  int v54; // ecx
  int v55; // ecx
  int v56; // esi
  int v57; // ecx
  int v58; // edx
  int v59; // ecx
  int v60; // ecx
  int v61; // esi
  int v62; // edx
  int v63; // ecx
  int v64; // ebx
  int v65; // edi
  int v66; // ecx
  int v67; // edi
  int v68; // edx
  int v69; // ebx
  int v70; // esi
  int v71; // edi
  int v72; // edx
  int v73; // edi
  int v74; // ecx
  int v75; // ebx
  int v76; // ecx
  int v77; // ecx
  int v78; // esi
  int v79; // ecx
  int v80; // edx
  int v81; // ecx
  int v82; // ecx
  int v83; // edx
  int v84; // esi
  int v85; // ecx
  int v86; // ebx
  int v87; // edi
  int *v88; // eax
  int v89; // ecx
  int v90; // edi
  int v91; // esi
  int v92; // edx
  int v93; // edi
  int v94; // ecx
  int v95; // ebx
  int v96; // ecx
  int v97; // esi
  int v98; // ecx
  int v99; // edx
  int v100; // ecx
  int v101; // ecx
  int v102; // esi
  int v103; // edx
  int v104; // ecx
  int v105; // ebx
  int v106; // edi
  int v107; // ecx
  int v108; // edi
  int v109; // edx
  int v110; // ecx
  int v111; // edi
  int v112; // ebx
  int v113; // esi
  int v114; // edx
  int v115; // edi
  int v116; // ecx
  int v117; // ebx
  int v118; // ecx
  int v119; // ecx
  int v120; // esi
  int v121; // ecx
  int v122; // edx
  int v123; // ecx
  int v124; // ecx
  int v125; // esi
  int v126; // edx
  int v127; // ecx
  int v128; // ebx
  int v129; // edi
  int v130; // ecx
  int v131; // edi
  int v132; // edx
  int v133; // ecx
  int v134; // ebx
  int v135; // esi
  int v136; // edi
  int v137; // edx
  int v138; // edi
  int v139; // ecx
  int v140; // ebx
  int v141; // ecx
  int v142; // ecx
  int v143; // esi
  int v144; // ecx
  int v145; // edx
  int v146; // ecx
  int v147; // ecx
  int v148; // esi
  int v149; // edx
  int v150; // ecx
  int v151; // ebx
  int v152; // edi
  int v153; // ecx
  int v154; // edi
  int v155; // edx
  int v156; // ebx
  int v157; // esi
  int v158; // edi
  int v159; // edx
  int v160; // edi
  int v161; // ecx
  int v162; // ebx
  int v163; // ecx
  int v164; // ecx
  int v165; // esi
  int v166; // ecx
  int v167; // edx
  int v168; // ecx
  int v169; // ecx
  int v170; // edx
  int v171; // esi
  int v172; // ecx
  int v173; // ebx
  int v174; // edi
  int i; // [esp+Ch] [ebp-18h]
  int tmp6; // [esp+10h] [ebp-14h]
  int tmp6a; // [esp+10h] [ebp-14h]
  int tmp6b; // [esp+10h] [ebp-14h]
  int tmp6c; // [esp+10h] [ebp-14h]
  int tmp6d; // [esp+10h] [ebp-14h]
  int tmp6e; // [esp+10h] [ebp-14h]
  int tmp6f; // [esp+10h] [ebp-14h]
  int tmp6g; // [esp+10h] [ebp-14h]
  int tmp4; // [esp+14h] [ebp-10h]
  int tmp4a; // [esp+14h] [ebp-10h]
  int tmp4b; // [esp+14h] [ebp-10h]
  int tmp4c; // [esp+14h] [ebp-10h]
  int tmp4d; // [esp+14h] [ebp-10h]
  int tmp4e; // [esp+14h] [ebp-10h]
  int tmp4f; // [esp+14h] [ebp-10h]
  int tmp4g; // [esp+14h] [ebp-10h]
  int tmp5; // [esp+1Ch] [ebp-8h]
  int tmp5a; // [esp+1Ch] [ebp-8h]
  int tmp5b; // [esp+1Ch] [ebp-8h]
  int tmp5c; // [esp+1Ch] [ebp-8h]
  int tmp5d; // [esp+1Ch] [ebp-8h]
  int tmp5e; // [esp+1Ch] [ebp-8h]
  int tmp5f; // [esp+1Ch] [ebp-8h]
  int tmp5g; // [esp+1Ch] [ebp-8h]
  int tmp2; // [esp+20h] [ebp-4h]
  int tmp2a; // [esp+20h] [ebp-4h]
  int tmp2b; // [esp+20h] [ebp-4h]
  int tmp2c; // [esp+20h] [ebp-4h]
  int tmp2d; // [esp+20h] [ebp-4h]
  int tmp2e; // [esp+20h] [ebp-4h]
  int tmp2f; // [esp+20h] [ebp-4h]
  int tmp2g; // [esp+20h] [ebp-4h]
  int dataa; // [esp+2Ch] [ebp+8h]

  v1 = data + 2;
  for ( i = 2; i != 0; --i )
  {
    v2 = v1[5];
    v3 = *(v1 - 2);
    v4 = v1[4];
    v5 = v2 + v3;
    v6 = v3 - v2;
    v7 = *(v1 - 1);
    v8 = v7 + v4;
    tmp6 = v7 - v4;
    tmp2 = *v1 + v1[3];
    tmp5 = *v1 - v1[3];
    v9 = v1[1];
    v10 = v9 + v1[2];
    tmp4 = v9 - v1[2];
    v11 = v10 + v5;
    v12 = v5 - v10;
    *(v1 - 2) = v11 + v8 + tmp2;
    v1[2] = v11 - (v8 + tmp2);
    v13 = (181 * (v8 + v12 - tmp2)) >> 8;
    v1[4] = v12 - v13;
    *v1 = v13 + v12;
    v14 = (98 * (tmp4 + tmp5 - (tmp6 + v6))) >> 8;
    v15 = v14 + ((334 * (tmp6 + v6)) >> 8);
    v16 = v14 + ((139 * (tmp4 + tmp5)) >> 8);
    v17 = (181 * (tmp6 + tmp5)) >> 8;
    v18 = v17 + v6;
    v19 = v6 - v17;
    v20 = v19 + v16;
    v21 = v19 - v16;
    v22 = v18 + v15;
    v1[3] = v20;
    v23 = v1[13];
    v1[1] = v21;
    v24 = v1[6];
    v25 = v18 - v15;
    v26 = v1[12];
    *(v1 - 1) = v22;
    v27 = v23 + v24;
    v28 = v24 - v23;
    v29 = v1[7];
    v1[5] = v25;
    v30 = v29 + v26;
    tmp6a = v29 - v26;
    v31 = v1[8];
    tmp2a = v31 + v1[11];
    tmp5a = v31 - v1[11];
    v32 = v1[9];
    v33 = v32 + v1[10];
    tmp4a = v32 - v1[10];
    v34 = v33 + v27;
    v35 = v27 - v33;
    v1[6] = v34 + v30 + tmp2a;
    v1[10] = v34 - (v30 + tmp2a);
    v36 = (181 * (v30 + v35 - tmp2a)) >> 8;
    v1[12] = v35 - v36;
    v1[8] = v36 + v35;
    v37 = (98 * (tmp4a + tmp5a - (tmp6a + v28))) >> 8;
    v38 = v37 + ((334 * (tmp6a + v28)) >> 8);
    v39 = v37 + ((139 * (tmp4a + tmp5a)) >> 8);
    v40 = (181 * (tmp6a + tmp5a)) >> 8;
    v41 = v40 + v28;
    v42 = v28 - v40;
    v43 = v42 + v39;
    v44 = v42 - v39;
    v45 = v41 + v38;
    v1[11] = v43;
    v46 = v1[21];
    v47 = v41 - v38;
    v48 = v1[20];
    v1[9] = v44;
    v49 = v1[14];
    v1[7] = v45;
    v50 = v46 + v49;
    v51 = v49 - v46;
    v52 = v1[15];
    v1[13] = v47;
    v53 = v52 + v48;
    tmp6b = v52 - v48;
    v54 = v1[16];
    tmp2b = v54 + v1[19];
    tmp5b = v54 - v1[19];
    v55 = v1[17];
    v56 = v55 + v1[18];
    tmp4b = v55 - v1[18];
    v57 = v56 + v50;
    v58 = v50 - v56;
    v1[14] = v57 + v53 + tmp2b;
    v1[18] = v57 - (v53 + tmp2b);
    v59 = (181 * (v53 + v58 - tmp2b)) >> 8;
    v1[20] = v58 - v59;
    v1[16] = v59 + v58;
    v60 = (98 * (tmp4b + tmp5b - (tmp6b + v51))) >> 8;
    v61 = v60 + ((334 * (tmp6b + v51)) >> 8);
    v62 = v60 + ((139 * (tmp4b + tmp5b)) >> 8);
    v63 = (181 * (tmp6b + tmp5b)) >> 8;
    v64 = v63 + v51;
    v65 = v51 - v63;
    v1[19] = v65 + v62;
    v66 = v1[29];
    v67 = v65 - v62;
    v68 = v64 + v61;
    v69 = v64 - v61;
    v70 = v1[28];
    v1[15] = v68;
    v1[17] = v67;
    v71 = v1[22];
    v72 = v71 + v66;
    v73 = v71 - v66;
    v74 = v1[23];
    v1[21] = v69;
    v75 = v70 + v74;
    tmp6c = v74 - v70;
    v76 = v1[24];
    tmp2c = v76 + v1[27];
    tmp5c = v76 - v1[27];
    v77 = v1[25];
    v78 = v77 + v1[26];
    tmp4c = v77 - v1[26];
    v79 = v78 + v72;
    v80 = v72 - v78;
    v1[22] = v79 + v75 + tmp2c;
    v1[26] = v79 - (v75 + tmp2c);
    v81 = (181 * (v75 + v80 - tmp2c)) >> 8;
    v1[28] = v80 - v81;
    v1[24] = v81 + v80;
    v82 = (98 * (tmp4c + tmp5c - (tmp6c + v73))) >> 8;
    v83 = v82 + ((139 * (tmp4c + tmp5c)) >> 8);
    v84 = v82 + ((334 * (tmp6c + v73)) >> 8);
    v85 = (181 * (tmp6c + tmp5c)) >> 8;
    v86 = v85 + v73;
    v87 = v73 - v85;
    v1[27] = v87 + v83;
    v1[25] = v87 - v83;
    v1[23] = v86 + v84;
    v1[29] = v86 - v84;
    v1 += 32;
  }
  v88 = data + 16;
  for ( dataa = 2; dataa != 0; --dataa )
  {
    v89 = v88[40];
    v90 = *(v88 - 16);
    v91 = v88[32];
    v92 = v89 + v90;
    v93 = v90 - v89;
    v94 = *(v88 - 8);
    v95 = v94 + v91;
    tmp6d = v94 - v91;
    tmp2d = *v88 + v88[24];
    tmp5d = *v88 - v88[24];
    v96 = v88[8];
    v97 = v96 + v88[16];
    tmp4d = v96 - v88[16];
    v98 = v97 + v92;
    v99 = v92 - v97;
    *(v88 - 16) = v98 + v95 + tmp2d;
    v88[16] = v98 - (v95 + tmp2d);
    v100 = (181 * (v95 + v99 - tmp2d)) >> 8;
    v88[32] = v99 - v100;
    *v88 = v100 + v99;
    v101 = (98 * (tmp4d + tmp5d - (tmp6d + v93))) >> 8;
    v102 = v101 + ((334 * (tmp6d + v93)) >> 8);
    v103 = v101 + ((139 * (tmp4d + tmp5d)) >> 8);
    v104 = (181 * (tmp6d + tmp5d)) >> 8;
    v105 = v104 + v93;
    v106 = v93 - v104;
    v107 = v106 + v103;
    v108 = v106 - v103;
    v109 = v105 + v102;
    v88[24] = v107;
    v110 = v88[41];
    v88[8] = v108;
    v111 = *(v88 - 15);
    v112 = v105 - v102;
    v113 = v88[33];
    *(v88 - 8) = v109;
    v114 = v110 + v111;
    v115 = v111 - v110;
    v116 = *(v88 - 7);
    v88[40] = v112;
    v117 = v116 + v113;
    tmp6e = v116 - v113;
    v118 = v88[1];
    tmp2e = v118 + v88[25];
    tmp5e = v118 - v88[25];
    v119 = v88[9];
    v120 = v119 + v88[17];
    tmp4e = v119 - v88[17];
    v121 = v120 + v114;
    v122 = v114 - v120;
    *(v88 - 15) = v121 + v117 + tmp2e;
    v88[17] = v121 - (v117 + tmp2e);
    v123 = (181 * (v117 + v122 - tmp2e)) >> 8;
    v88[33] = v122 - v123;
    v88[1] = v123 + v122;
    v124 = (98 * (tmp4e + tmp5e - (tmp6e + v115))) >> 8;
    v125 = v124 + ((334 * (tmp6e + v115)) >> 8);
    v126 = v124 + ((139 * (tmp4e + tmp5e)) >> 8);
    v127 = (181 * (tmp6e + tmp5e)) >> 8;
    v128 = v127 + v115;
    v129 = v115 - v127;
    v130 = v129 + v126;
    v131 = v129 - v126;
    v132 = v128 + v125;
    v88[25] = v130;
    v133 = v88[42];
    v134 = v128 - v125;
    v135 = v88[34];
    v88[9] = v131;
    v136 = *(v88 - 14);
    *(v88 - 7) = v132;
    v137 = v133 + v136;
    v138 = v136 - v133;
    v139 = *(v88 - 6);
    v88[41] = v134;
    v140 = v139 + v135;
    tmp6f = v139 - v135;
    v141 = v88[2];
    tmp2f = v141 + v88[26];
    tmp5f = v141 - v88[26];
    v142 = v88[10];
    v143 = v142 + v88[18];
    tmp4f = v142 - v88[18];
    v144 = v143 + v137;
    v145 = v137 - v143;
    *(v88 - 14) = v144 + v140 + tmp2f;
    v88[18] = v144 - (v140 + tmp2f);
    v146 = (181 * (v140 + v145 - tmp2f)) >> 8;
    v88[34] = v145 - v146;
    v88[2] = v146 + v145;
    v147 = (98 * (tmp4f + tmp5f - (tmp6f + v138))) >> 8;
    v148 = v147 + ((334 * (tmp6f + v138)) >> 8);
    v149 = v147 + ((139 * (tmp4f + tmp5f)) >> 8);
    v150 = (181 * (tmp6f + tmp5f)) >> 8;
    v151 = v150 + v138;
    v152 = v138 - v150;
    v88[26] = v152 + v149;
    v153 = v88[43];
    v154 = v152 - v149;
    v155 = v151 + v148;
    v156 = v151 - v148;
    v157 = v88[35];
    *(v88 - 6) = v155;
    v88[10] = v154;
    v158 = *(v88 - 13);
    v159 = v158 + v153;
    v160 = v158 - v153;
    v161 = *(v88 - 5);
    v88[42] = v156;
    v162 = v157 + v161;
    tmp6g = v161 - v157;
    v163 = v88[3];
    tmp2g = v163 + v88[27];
    tmp5g = v163 - v88[27];
    v164 = v88[11];
    v165 = v164 + v88[19];
    tmp4g = v164 - v88[19];
    v166 = v165 + v159;
    v167 = v159 - v165;
    *(v88 - 13) = v166 + v162 + tmp2g;
    v88[19] = v166 - (v162 + tmp2g);
    v168 = (181 * (v162 + v167 - tmp2g)) >> 8;
    v88[35] = v167 - v168;
    v88[3] = v168 + v167;
    v169 = (98 * (tmp4g + tmp5g - (tmp6g + v160))) >> 8;
    v170 = v169 + ((139 * (tmp4g + tmp5g)) >> 8);
    v171 = v169 + ((334 * (tmp6g + v160)) >> 8);
    v172 = (181 * (tmp6g + tmp5g)) >> 8;
    v173 = v172 + v160;
    v174 = v160 - v172;
    v88[27] = v174 + v170;
    v88[11] = v174 - v170;
    *(v88 - 5) = v173 + v171;
    v88[43] = v173 - v171;
    v88 += 4;
  }
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x00423290
// Name: _jpeg_fdct_ifast
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_fdct_ifast(int *data)
{
  int *v1; // eax
  int v2; // ecx
  int v3; // edi
  int v4; // esi
  int v5; // edx
  int v6; // edi
  int v7; // ecx
  int v8; // ebx
  int v9; // ecx
  int v10; // esi
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // ecx
  int v15; // esi
  int v16; // edx
  int v17; // ecx
  int v18; // ebx
  int v19; // edi
  int v20; // ecx
  int v21; // edi
  int v22; // edx
  int v23; // ecx
  int v24; // edi
  int v25; // ebx
  int v26; // esi
  int v27; // edx
  int v28; // edi
  int v29; // ecx
  int v30; // ebx
  int v31; // ecx
  int v32; // ecx
  int v33; // esi
  int v34; // ecx
  int v35; // edx
  int v36; // ecx
  int v37; // ecx
  int v38; // esi
  int v39; // edx
  int v40; // ecx
  int v41; // ebx
  int v42; // edi
  int v43; // ecx
  int v44; // edi
  int v45; // edx
  int v46; // ecx
  int v47; // ebx
  int v48; // esi
  int v49; // edi
  int v50; // edx
  int v51; // edi
  int v52; // ecx
  int v53; // ebx
  int v54; // ecx
  int v55; // ecx
  int v56; // esi
  int v57; // ecx
  int v58; // edx
  int v59; // ecx
  int v60; // ecx
  int v61; // esi
  int v62; // edx
  int v63; // ecx
  int v64; // ebx
  int v65; // edi
  int v66; // ecx
  int v67; // edi
  int v68; // edx
  int v69; // ebx
  int v70; // esi
  int v71; // edi
  int v72; // edx
  int v73; // edi
  int v74; // ecx
  int v75; // ebx
  int v76; // ecx
  int v77; // ecx
  int v78; // esi
  int v79; // ecx
  int v80; // edx
  int v81; // ecx
  int v82; // ecx
  int v83; // edx
  int v84; // esi
  int v85; // ecx
  int v86; // ebx
  int v87; // edi
  int *v88; // eax
  int v89; // ecx
  int v90; // edi
  int v91; // esi
  int v92; // edx
  int v93; // edi
  int v94; // ecx
  int v95; // ebx
  int v96; // ecx
  int v97; // esi
  int v98; // ecx
  int v99; // edx
  int v100; // ecx
  int v101; // ecx
  int v102; // esi
  int v103; // edx
  int v104; // ecx
  int v105; // ebx
  int v106; // edi
  int v107; // ecx
  int v108; // edi
  int v109; // edx
  int v110; // ecx
  int v111; // edi
  int v112; // ebx
  int v113; // esi
  int v114; // edx
  int v115; // edi
  int v116; // ecx
  int v117; // ebx
  int v118; // ecx
  int v119; // ecx
  int v120; // esi
  int v121; // ecx
  int v122; // edx
  int v123; // ecx
  int v124; // ecx
  int v125; // esi
  int v126; // edx
  int v127; // ecx
  int v128; // ebx
  int v129; // edi
  int v130; // ecx
  int v131; // edi
  int v132; // edx
  int v133; // ecx
  int v134; // ebx
  int v135; // esi
  int v136; // edi
  int v137; // edx
  int v138; // edi
  int v139; // ecx
  int v140; // ebx
  int v141; // ecx
  int v142; // ecx
  int v143; // esi
  int v144; // ecx
  int v145; // edx
  int v146; // ecx
  int v147; // ecx
  int v148; // esi
  int v149; // edx
  int v150; // ecx
  int v151; // ebx
  int v152; // edi
  int v153; // ecx
  int v154; // edi
  int v155; // edx
  int v156; // ebx
  int v157; // esi
  int v158; // edi
  int v159; // edx
  int v160; // edi
  int v161; // ecx
  int v162; // ebx
  int v163; // ecx
  int v164; // ecx
  int v165; // esi
  int v166; // ecx
  int v167; // edx
  int v168; // ecx
  int v169; // ecx
  int v170; // edx
  int v171; // esi
  int v172; // ecx
  int v173; // ebx
  int v174; // edi
  int i; // [esp+Ch] [ebp-18h]
  int tmp6; // [esp+10h] [ebp-14h]
  int tmp6a; // [esp+10h] [ebp-14h]
  int tmp6b; // [esp+10h] [ebp-14h]
  int tmp6c; // [esp+10h] [ebp-14h]
  int tmp6d; // [esp+10h] [ebp-14h]
  int tmp6e; // [esp+10h] [ebp-14h]
  int tmp6f; // [esp+10h] [ebp-14h]
  int tmp6g; // [esp+10h] [ebp-14h]
  int tmp4; // [esp+14h] [ebp-10h]
  int tmp4a; // [esp+14h] [ebp-10h]
  int tmp4b; // [esp+14h] [ebp-10h]
  int tmp4c; // [esp+14h] [ebp-10h]
  int tmp4d; // [esp+14h] [ebp-10h]
  int tmp4e; // [esp+14h] [ebp-10h]
  int tmp4f; // [esp+14h] [ebp-10h]
  int tmp4g; // [esp+14h] [ebp-10h]
  int tmp5; // [esp+1Ch] [ebp-8h]
  int tmp5a; // [esp+1Ch] [ebp-8h]
  int tmp5b; // [esp+1Ch] [ebp-8h]
  int tmp5c; // [esp+1Ch] [ebp-8h]
  int tmp5d; // [esp+1Ch] [ebp-8h]
  int tmp5e; // [esp+1Ch] [ebp-8h]
  int tmp5f; // [esp+1Ch] [ebp-8h]
  int tmp5g; // [esp+1Ch] [ebp-8h]
  int tmp2; // [esp+20h] [ebp-4h]
  int tmp2a; // [esp+20h] [ebp-4h]
  int tmp2b; // [esp+20h] [ebp-4h]
  int tmp2c; // [esp+20h] [ebp-4h]
  int tmp2d; // [esp+20h] [ebp-4h]
  int tmp2e; // [esp+20h] [ebp-4h]
  int tmp2f; // [esp+20h] [ebp-4h]
  int tmp2g; // [esp+20h] [ebp-4h]
  int dataa; // [esp+2Ch] [ebp+8h]

  v1 = data + 2;
  for ( i = 2; i != 0; --i )
  {
    v2 = v1[5];
    v3 = *(v1 - 2);
    v4 = v1[4];
    v5 = v2 + v3;
    v6 = v3 - v2;
    v7 = *(v1 - 1);
    v8 = v7 + v4;
    tmp6 = v7 - v4;
    tmp2 = *v1 + v1[3];
    tmp5 = *v1 - v1[3];
    v9 = v1[1];
    v10 = v9 + v1[2];
    tmp4 = v9 - v1[2];
    v11 = v10 + v5;
    v12 = v5 - v10;
    *(v1 - 2) = v11 + v8 + tmp2;
    v1[2] = v11 - (v8 + tmp2);
    v13 = (181 * (v8 + v12 - tmp2)) >> 8;
    v1[4] = v12 - v13;
    *v1 = v13 + v12;
    v14 = (98 * (tmp4 + tmp5 - (tmp6 + v6))) >> 8;
    v15 = v14 + ((334 * (tmp6 + v6)) >> 8);
    v16 = v14 + ((139 * (tmp4 + tmp5)) >> 8);
    v17 = (181 * (tmp6 + tmp5)) >> 8;
    v18 = v17 + v6;
    v19 = v6 - v17;
    v20 = v19 + v16;
    v21 = v19 - v16;
    v22 = v18 + v15;
    v1[3] = v20;
    v23 = v1[13];
    v1[1] = v21;
    v24 = v1[6];
    v25 = v18 - v15;
    v26 = v1[12];
    *(v1 - 1) = v22;
    v27 = v23 + v24;
    v28 = v24 - v23;
    v29 = v1[7];
    v1[5] = v25;
    v30 = v29 + v26;
    tmp6a = v29 - v26;
    v31 = v1[8];
    tmp2a = v31 + v1[11];
    tmp5a = v31 - v1[11];
    v32 = v1[9];
    v33 = v32 + v1[10];
    tmp4a = v32 - v1[10];
    v34 = v33 + v27;
    v35 = v27 - v33;
    v1[6] = v34 + v30 + tmp2a;
    v1[10] = v34 - (v30 + tmp2a);
    v36 = (181 * (v30 + v35 - tmp2a)) >> 8;
    v1[12] = v35 - v36;
    v1[8] = v36 + v35;
    v37 = (98 * (tmp4a + tmp5a - (tmp6a + v28))) >> 8;
    v38 = v37 + ((334 * (tmp6a + v28)) >> 8);
    v39 = v37 + ((139 * (tmp4a + tmp5a)) >> 8);
    v40 = (181 * (tmp6a + tmp5a)) >> 8;
    v41 = v40 + v28;
    v42 = v28 - v40;
    v43 = v42 + v39;
    v44 = v42 - v39;
    v45 = v41 + v38;
    v1[11] = v43;
    v46 = v1[21];
    v47 = v41 - v38;
    v48 = v1[20];
    v1[9] = v44;
    v49 = v1[14];
    v1[7] = v45;
    v50 = v46 + v49;
    v51 = v49 - v46;
    v52 = v1[15];
    v1[13] = v47;
    v53 = v52 + v48;
    tmp6b = v52 - v48;
    v54 = v1[16];
    tmp2b = v54 + v1[19];
    tmp5b = v54 - v1[19];
    v55 = v1[17];
    v56 = v55 + v1[18];
    tmp4b = v55 - v1[18];
    v57 = v56 + v50;
    v58 = v50 - v56;
    v1[14] = v57 + v53 + tmp2b;
    v1[18] = v57 - (v53 + tmp2b);
    v59 = (181 * (v53 + v58 - tmp2b)) >> 8;
    v1[20] = v58 - v59;
    v1[16] = v59 + v58;
    v60 = (98 * (tmp4b + tmp5b - (tmp6b + v51))) >> 8;
    v61 = v60 + ((334 * (tmp6b + v51)) >> 8);
    v62 = v60 + ((139 * (tmp4b + tmp5b)) >> 8);
    v63 = (181 * (tmp6b + tmp5b)) >> 8;
    v64 = v63 + v51;
    v65 = v51 - v63;
    v1[19] = v65 + v62;
    v66 = v1[29];
    v67 = v65 - v62;
    v68 = v64 + v61;
    v69 = v64 - v61;
    v70 = v1[28];
    v1[15] = v68;
    v1[17] = v67;
    v71 = v1[22];
    v72 = v71 + v66;
    v73 = v71 - v66;
    v74 = v1[23];
    v1[21] = v69;
    v75 = v70 + v74;
    tmp6c = v74 - v70;
    v76 = v1[24];
    tmp2c = v76 + v1[27];
    tmp5c = v76 - v1[27];
    v77 = v1[25];
    v78 = v77 + v1[26];
    tmp4c = v77 - v1[26];
    v79 = v78 + v72;
    v80 = v72 - v78;
    v1[22] = v79 + v75 + tmp2c;
    v1[26] = v79 - (v75 + tmp2c);
    v81 = (181 * (v75 + v80 - tmp2c)) >> 8;
    v1[28] = v80 - v81;
    v1[24] = v81 + v80;
    v82 = (98 * (tmp4c + tmp5c - (tmp6c + v73))) >> 8;
    v83 = v82 + ((139 * (tmp4c + tmp5c)) >> 8);
    v84 = v82 + ((334 * (tmp6c + v73)) >> 8);
    v85 = (181 * (tmp6c + tmp5c)) >> 8;
    v86 = v85 + v73;
    v87 = v73 - v85;
    v1[27] = v87 + v83;
    v1[25] = v87 - v83;
    v1[23] = v86 + v84;
    v1[29] = v86 - v84;
    v1 += 32;
  }
  v88 = data + 16;
  for ( dataa = 2; dataa != 0; --dataa )
  {
    v89 = v88[40];
    v90 = *(v88 - 16);
    v91 = v88[32];
    v92 = v89 + v90;
    v93 = v90 - v89;
    v94 = *(v88 - 8);
    v95 = v94 + v91;
    tmp6d = v94 - v91;
    tmp2d = *v88 + v88[24];
    tmp5d = *v88 - v88[24];
    v96 = v88[8];
    v97 = v96 + v88[16];
    tmp4d = v96 - v88[16];
    v98 = v97 + v92;
    v99 = v92 - v97;
    *(v88 - 16) = v98 + v95 + tmp2d;
    v88[16] = v98 - (v95 + tmp2d);
    v100 = (181 * (v95 + v99 - tmp2d)) >> 8;
    v88[32] = v99 - v100;
    *v88 = v100 + v99;
    v101 = (98 * (tmp4d + tmp5d - (tmp6d + v93))) >> 8;
    v102 = v101 + ((334 * (tmp6d + v93)) >> 8);
    v103 = v101 + ((139 * (tmp4d + tmp5d)) >> 8);
    v104 = (181 * (tmp6d + tmp5d)) >> 8;
    v105 = v104 + v93;
    v106 = v93 - v104;
    v107 = v106 + v103;
    v108 = v106 - v103;
    v109 = v105 + v102;
    v88[24] = v107;
    v110 = v88[41];
    v88[8] = v108;
    v111 = *(v88 - 15);
    v112 = v105 - v102;
    v113 = v88[33];
    *(v88 - 8) = v109;
    v114 = v110 + v111;
    v115 = v111 - v110;
    v116 = *(v88 - 7);
    v88[40] = v112;
    v117 = v116 + v113;
    tmp6e = v116 - v113;
    v118 = v88[1];
    tmp2e = v118 + v88[25];
    tmp5e = v118 - v88[25];
    v119 = v88[9];
    v120 = v119 + v88[17];
    tmp4e = v119 - v88[17];
    v121 = v120 + v114;
    v122 = v114 - v120;
    *(v88 - 15) = v121 + v117 + tmp2e;
    v88[17] = v121 - (v117 + tmp2e);
    v123 = (181 * (v117 + v122 - tmp2e)) >> 8;
    v88[33] = v122 - v123;
    v88[1] = v123 + v122;
    v124 = (98 * (tmp4e + tmp5e - (tmp6e + v115))) >> 8;
    v125 = v124 + ((334 * (tmp6e + v115)) >> 8);
    v126 = v124 + ((139 * (tmp4e + tmp5e)) >> 8);
    v127 = (181 * (tmp6e + tmp5e)) >> 8;
    v128 = v127 + v115;
    v129 = v115 - v127;
    v130 = v129 + v126;
    v131 = v129 - v126;
    v132 = v128 + v125;
    v88[25] = v130;
    v133 = v88[42];
    v134 = v128 - v125;
    v135 = v88[34];
    v88[9] = v131;
    v136 = *(v88 - 14);
    *(v88 - 7) = v132;
    v137 = v133 + v136;
    v138 = v136 - v133;
    v139 = *(v88 - 6);
    v88[41] = v134;
    v140 = v139 + v135;
    tmp6f = v139 - v135;
    v141 = v88[2];
    tmp2f = v141 + v88[26];
    tmp5f = v141 - v88[26];
    v142 = v88[10];
    v143 = v142 + v88[18];
    tmp4f = v142 - v88[18];
    v144 = v143 + v137;
    v145 = v137 - v143;
    *(v88 - 14) = v144 + v140 + tmp2f;
    v88[18] = v144 - (v140 + tmp2f);
    v146 = (181 * (v140 + v145 - tmp2f)) >> 8;
    v88[34] = v145 - v146;
    v88[2] = v146 + v145;
    v147 = (98 * (tmp4f + tmp5f - (tmp6f + v138))) >> 8;
    v148 = v147 + ((334 * (tmp6f + v138)) >> 8);
    v149 = v147 + ((139 * (tmp4f + tmp5f)) >> 8);
    v150 = (181 * (tmp6f + tmp5f)) >> 8;
    v151 = v150 + v138;
    v152 = v138 - v150;
    v88[26] = v152 + v149;
    v153 = v88[43];
    v154 = v152 - v149;
    v155 = v151 + v148;
    v156 = v151 - v148;
    v157 = v88[35];
    *(v88 - 6) = v155;
    v88[10] = v154;
    v158 = *(v88 - 13);
    v159 = v158 + v153;
    v160 = v158 - v153;
    v161 = *(v88 - 5);
    v88[42] = v156;
    v162 = v157 + v161;
    tmp6g = v161 - v157;
    v163 = v88[3];
    tmp2g = v163 + v88[27];
    tmp5g = v163 - v88[27];
    v164 = v88[11];
    v165 = v164 + v88[19];
    tmp4g = v164 - v88[19];
    v166 = v165 + v159;
    v167 = v159 - v165;
    *(v88 - 13) = v166 + v162 + tmp2g;
    v88[19] = v166 - (v162 + tmp2g);
    v168 = (181 * (v162 + v167 - tmp2g)) >> 8;
    v88[35] = v167 - v168;
    v88[3] = v168 + v167;
    v169 = (98 * (tmp4g + tmp5g - (tmp6g + v160))) >> 8;
    v170 = v169 + ((139 * (tmp4g + tmp5g)) >> 8);
    v171 = v169 + ((334 * (tmp6g + v160)) >> 8);
    v172 = (181 * (tmp6g + tmp5g)) >> 8;
    v173 = v172 + v160;
    v174 = v160 - v172;
    v88[27] = v174 + v170;
    v88[11] = v174 - v170;
    *(v88 - 5) = v173 + v171;
    v88[43] = v173 - v171;
    v88 += 4;
  }
}

} // namespace vxconsole_ps3
