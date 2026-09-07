// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/taocrypt/src/des.cpp
// Functions: 11
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\taocrypt\src\des.h"

//------------------------------------------------------------------------------
// Address: 0x00425CC0
// Name: void yaSSL::ysDelete<struct yaSSL::DES::DESImpl>(struct yaSSL::DES::DESImpl __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::ysDelete<yaSSL::DES::DESImpl>(_DWORD *a1)
{
  if ( a1 != nullptr )
  {
    a1[46] = &TaoCrypt::Mode_BASE::`vftable';
    *a1 = &TaoCrypt::Mode_BASE::`vftable';
  }
  operator delete(ptr: (KeyValues *)*(unsigned __int8 *)yaSSL::ys, ptra: a1);
}

//------------------------------------------------------------------------------
// Address: 0x00447790
// Name: TaoCrypt::IPERM
// Source: json
//------------------------------------------------------------------------------
_DWORD *__usercall TaoCrypt::IPERM@<eax>(_DWORD *result@<eax>, _DWORD *a2@<ecx>)
{
  int v2; // edx
  unsigned int v3; // esi
  int v4; // edx
  unsigned int v5; // edx
  int v6; // esi
  int v7; // esi
  int v8; // edx
  int v9; // edx
  int v10; // esi
  unsigned int v11; // esi

  v2 = __ROL4__(*result, 4);
  *result = v2;
  v3 = (v2 ^ *a2) & 0xF0F0F0F0;
  *a2 ^= v3;
  v4 = __ROR4__(v3 ^ *result, 20);
  *result = v4;
  v5 = (*a2 ^ v4) & 0xFFFF0000;
  *a2 ^= v5;
  v6 = __ROR4__(v5 ^ *result, 18);
  *result = v6;
  v7 = (*a2 ^ v6) & 0x33333333;
  *a2 ^= v7;
  v8 = __ROR4__(v7 ^ *result, 6);
  *result = v8;
  v9 = (*a2 ^ v8) & 0xFF00FF;
  *a2 ^= v9;
  v10 = __ROL4__(v9 ^ *result, 9);
  *result = v10;
  v11 = (*a2 ^ v10) & 0xAAAAAAAA;
  *a2 = __ROL4__(v11 ^ *a2, 1);
  *result ^= v11;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00447810
// Name: TaoCrypt::FPERM
// Source: json
//------------------------------------------------------------------------------
int __usercall TaoCrypt::FPERM@<eax>(unsigned int *a1@<eax>, _DWORD *a2@<ecx>)
{
  unsigned int v2; // edx
  unsigned int v3; // esi
  int v4; // edx
  int v5; // edx
  int v6; // esi
  int v7; // esi
  int v8; // edx
  unsigned int v9; // edx
  int v10; // esi
  unsigned int v11; // esi
  int result; // eax

  v2 = __ROR4__(*a1, 1);
  *a1 = v2;
  v3 = (v2 ^ *a2) & 0xAAAAAAAA;
  *a1 = v3 ^ v2;
  v4 = __ROR4__(v3 ^ *a2, 9);
  *a2 = v4;
  v5 = (*a1 ^ v4) & 0xFF00FF;
  *a1 ^= v5;
  v6 = __ROL4__(v5 ^ *a2, 6);
  *a2 = v6;
  v7 = (*a1 ^ v6) & 0x33333333;
  *a1 ^= v7;
  v8 = __ROL4__(v7 ^ *a2, 18);
  *a2 = v8;
  v9 = (*a1 ^ v8) & 0xFFFF0000;
  *a1 ^= v9;
  v10 = __ROL4__(v9 ^ *a2, 20);
  *a2 = v10;
  v11 = (*a1 ^ v10) & 0xF0F0F0F0;
  *a1 ^= v11;
  result = __ROR4__(v11 ^ *a2, 4);
  *a2 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00447890
// Name: public: void TaoCrypt::BasicDES::RawProcessBlock(unsigned int __near &,unsigned int __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::BasicDES::RawProcessBlock(TaoCrypt::BasicDES *this, unsigned int *rIn, unsigned int *rIn_4)
{
  unsigned int v3; // edx
  int v4; // esi
  char *v5; // ecx
  int i; // edi
  unsigned int v7; // eax
  unsigned int v8; // eax
  int v9; // esi
  int result; // eax

  v3 = *rIn;
  v4 = *rIn_4;
  v5 = (char *)this + 8;
  for ( i = 8; i != 0; --i )
  {
    v7 = *((_DWORD *)v5 - 2) ^ __ROR4__(v4, 4);
    v5 += 16;
    v3 ^= dword_47E118[(v4 ^ *((_DWORD *)v5 - 5)) & 0x3F]
        ^ dword_47DF18[(((unsigned int)v4 ^ *((_DWORD *)v5 - 5)) >> 8) & 0x3F]
        ^ dword_47DD18[(((unsigned int)v4 ^ *((_DWORD *)v5 - 5)) >> 16) & 0x3F]
        ^ dword_47DB18[(((unsigned int)v4 ^ *((_DWORD *)v5 - 5)) >> 24) & 0x3F]
        ^ dword_47E018[v7 & 0x3F]
        ^ dword_47DE18[(v7 >> 8) & 0x3F]
        ^ dword_47DC18[HIWORD(v7) & 0x3F]
        ^ *((_DWORD *)&Spbox.__vftable + (HIBYTE(v7) & 0x3F));
    v8 = *((_DWORD *)v5 - 4) ^ __ROR4__(v3, 4);
    v9 = dword_47E018[v8 & 0x3F]
       ^ dword_47DE18[(v8 >> 8) & 0x3F]
       ^ dword_47DC18[HIWORD(v8) & 0x3F]
       ^ *((_DWORD *)&Spbox.__vftable + (HIBYTE(v8) & 0x3F))
       ^ v4;
    result = (v3 ^ *((_DWORD *)v5 - 3)) & 0x3F;
    v4 = dword_47E118[result]
       ^ dword_47DF18[((v3 ^ *((_DWORD *)v5 - 3)) >> 8) & 0x3F]
       ^ dword_47DD18[((v3 ^ *((_DWORD *)v5 - 3)) >> 16) & 0x3F]
       ^ dword_47DB18[((v3 ^ *((_DWORD *)v5 - 3)) >> 24) & 0x3F]
       ^ v9;
  }
  *rIn = v3;
  *rIn_4 = v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004479D0
// Name: private: void TaoCrypt::DES_EDE3::AsmProcess(unsigned char const __near *,unsigned char __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::DES_EDE3::AsmProcess(
        TaoCrypt::DES_EDE3 *this@<ecx>,
        int _EBX@<ebx>,
        int _EDI@<edi>,
        int _ESI@<esi>,
        const LoggingContext_t *in,
        unsigned __int8 *out,
        _DWORD *box)
{
  _DWORD *v15; // edx
  unsigned __int32 v16; // eax
  int v17; // ebx
  unsigned int v18; // ecx
  int v19; // eax
  int v20; // ebx
  unsigned int v21; // ecx
  int v22; // eax
  int v23; // ebx
  int v24; // ecx
  int v25; // eax
  int v26; // ebx
  int v27; // ecx
  int v28; // eax
  int v29; // ebx
  unsigned int v30; // ecx
  int v31; // eax
  int v32; // ebx
  int v33; // ecx
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  int v37; // ecx
  int v38; // ebx
  int v39; // ecx
  int v40; // ebx
  int v41; // ecx
  int v42; // eax
  int v43; // ecx
  int v44; // eax
  int v45; // ecx
  int v46; // ebx
  int v47; // ecx
  int v48; // ebx
  int v49; // ecx
  int v50; // eax
  int v51; // ecx
  int v52; // eax
  int v53; // ecx
  int v54; // ebx
  int v55; // ecx
  int v56; // ebx
  int v57; // ecx
  int v58; // eax
  int v59; // ecx
  int v60; // eax
  int v61; // ecx
  int v62; // ebx
  int v63; // ecx
  int v64; // ebx
  int v65; // ecx
  int v66; // eax
  int v67; // ecx
  int v68; // eax
  int v69; // ecx
  int v70; // ebx
  int v71; // ecx
  int v72; // ebx
  int v73; // ecx
  int v74; // eax
  int v75; // ecx
  int v76; // eax
  int v77; // ecx
  int v78; // ebx
  int v79; // ecx
  int v80; // ebx
  int v81; // ecx
  int v82; // eax
  int v83; // ecx
  int v84; // eax
  int v85; // ecx
  int v86; // ebx
  int v87; // ecx
  int v88; // ebx
  int v89; // ecx
  int v90; // eax
  int v91; // ecx
  int v92; // eax
  int v93; // ecx
  int v94; // ebx
  int v95; // ecx
  int v96; // eax
  int v97; // et0
  int v98; // ecx
  int v99; // eax
  int v100; // ecx
  int v101; // eax
  int v102; // ecx
  int v103; // ebx
  int v104; // ecx
  int v105; // ebx
  int v106; // ecx
  int v107; // eax
  int v108; // ecx
  int v109; // eax
  int v110; // ecx
  int v111; // ebx
  int v112; // ecx
  int v113; // ebx
  int v114; // ecx
  int v115; // eax
  int v116; // ecx
  int v117; // eax
  int v118; // ecx
  int v119; // ebx
  int v120; // ecx
  int v121; // ebx
  int v122; // ecx
  int v123; // eax
  int v124; // ecx
  int v125; // eax
  int v126; // ecx
  int v127; // ebx
  int v128; // ecx
  int v129; // ebx
  int v130; // ecx
  int v131; // eax
  int v132; // ecx
  int v133; // eax
  int v134; // ecx
  int v135; // ebx
  int v136; // ecx
  int v137; // ebx
  int v138; // ecx
  int v139; // eax
  int v140; // ecx
  int v141; // eax
  int v142; // ecx
  int v143; // ebx
  int v144; // ecx
  int v145; // ebx
  int v146; // ecx
  int v147; // eax
  int v148; // ecx
  int v149; // eax
  int v150; // ecx
  int v151; // ebx
  int v152; // ecx
  int v153; // ebx
  int v154; // ecx
  int v155; // eax
  int v156; // ecx
  int v157; // eax
  int v158; // ecx
  int v159; // ebx
  int v160; // ecx
  int v161; // eax
  int v162; // et1
  int v163; // ecx
  int v164; // eax
  int v165; // ecx
  int v166; // eax
  int v167; // ecx
  int v168; // ebx
  int v169; // ecx
  int v170; // ebx
  int v171; // ecx
  int v172; // eax
  int v173; // ecx
  int v174; // eax
  int v175; // ecx
  int v176; // ebx
  int v177; // ecx
  int v178; // ebx
  int v179; // ecx
  int v180; // eax
  int v181; // ecx
  int v182; // eax
  int v183; // ecx
  int v184; // ebx
  int v185; // ecx
  int v186; // ebx
  int v187; // ecx
  int v188; // eax
  int v189; // ecx
  int v190; // eax
  int v191; // ecx
  int v192; // ebx
  int v193; // ecx
  int v194; // ebx
  int v195; // ecx
  int v196; // eax
  int v197; // ecx
  int v198; // eax
  int v199; // ecx
  int v200; // ebx
  int v201; // ecx
  int v202; // ebx
  int v203; // ecx
  int v204; // eax
  int v205; // ecx
  int v206; // eax
  int v207; // ecx
  int v208; // ebx
  int v209; // ecx
  int v210; // ebx
  int v211; // ecx
  int v212; // eax
  int v213; // ecx
  int v214; // eax
  int v215; // ecx
  int v216; // ebx
  int v217; // ecx
  int v218; // ebx
  int v219; // ecx
  int v220; // eax
  int v221; // ecx
  int v222; // eax
  int v223; // ecx
  int v224; // ebx
  int v225; // ecx
  int v226; // ebx
  unsigned int v227; // ecx
  int v228; // ebx
  int v229; // eax
  int v230; // ecx
  int v231; // ebx
  int v232; // eax
  int v233; // ecx
  int v234; // ebx
  int v235; // eax
  unsigned int v236; // ecx
  int v237; // ebx
  int v238; // eax
  unsigned int v239; // ecx
  _DWORD *v241; // esi
  int vars0; // [esp+0h] [ebp+0h] BYREF

  _EBP = &vars0;
  __asm
  {
    movd    mm3, edi
    movd    mm4, ebx
    movd    mm5, esi
    movd    mm6, ebp
  }
  _EDX = this;
  __asm { movd    mm2, edx }
  v15 = (_DWORD *)((char *)this + 56);
  v16 = _byteswap_ulong(in->m_ChannelID);
  v17 = __ROL4__(_byteswap_ulong(in->m_Flags), 4);
  v18 = (v17 ^ v16) & 0xF0F0F0F0;
  v19 = v18 ^ v16;
  v20 = __ROR4__(v18 ^ v17, 20);
  v21 = (v20 ^ v19) & 0xFFFF0000;
  v22 = v21 ^ v19;
  v23 = __ROR4__(v21 ^ v20, 18);
  v24 = (v23 ^ v22) & 0x33333333;
  v25 = v24 ^ v22;
  v26 = __ROR4__(v24 ^ v23, 6);
  v27 = (v26 ^ v25) & 0xFF00FF;
  v28 = v27 ^ v25;
  v29 = __ROL4__(v27 ^ v26, 9);
  v30 = (v29 ^ v28) & 0xAAAAAAAA;
  v31 = __ROL4__(v30 ^ v28, 1);
  v32 = v30 ^ v29;
  v33 = (*v15 ^ __ROR4__(v32, 4)) & 0x3F3F3F3F;
  v34 = box[HIBYTE(v33)] ^ box[BYTE2(v33) + 128] ^ box[BYTE1(v33) + 256] ^ box[(unsigned __int8)v33 + 384] ^ v31;
  v35 = (v15[1] ^ v32) & 0x3F3F3F3F;
  v36 = box[HIBYTE(v35) + 64] ^ box[BYTE2(v35) + 192] ^ box[BYTE1(v35) + 320] ^ box[(unsigned __int8)v35 + 448] ^ v34;
  v37 = (v15[2] ^ __ROR4__(v36, 4)) & 0x3F3F3F3F;
  v38 = box[HIBYTE(v37)] ^ box[BYTE2(v37) + 128] ^ box[BYTE1(v37) + 256] ^ box[(unsigned __int8)v37 + 384] ^ v32;
  v39 = (v15[3] ^ v36) & 0x3F3F3F3F;
  v15 += 4;
  v40 = box[HIBYTE(v39) + 64] ^ box[BYTE2(v39) + 192] ^ box[BYTE1(v39) + 320] ^ box[(unsigned __int8)v39 + 448] ^ v38;
  v41 = (*v15 ^ __ROR4__(v40, 4)) & 0x3F3F3F3F;
  v42 = box[HIBYTE(v41)] ^ box[BYTE2(v41) + 128] ^ box[BYTE1(v41) + 256] ^ box[(unsigned __int8)v41 + 384] ^ v36;
  v43 = (v15[1] ^ v40) & 0x3F3F3F3F;
  v44 = box[HIBYTE(v43) + 64] ^ box[BYTE2(v43) + 192] ^ box[BYTE1(v43) + 320] ^ box[(unsigned __int8)v43 + 448] ^ v42;
  v45 = (v15[2] ^ __ROR4__(v44, 4)) & 0x3F3F3F3F;
  v46 = box[HIBYTE(v45)] ^ box[BYTE2(v45) + 128] ^ box[BYTE1(v45) + 256] ^ box[(unsigned __int8)v45 + 384] ^ v40;
  v47 = (v15[3] ^ v44) & 0x3F3F3F3F;
  v15 += 4;
  v48 = box[HIBYTE(v47) + 64] ^ box[BYTE2(v47) + 192] ^ box[BYTE1(v47) + 320] ^ box[(unsigned __int8)v47 + 448] ^ v46;
  v49 = (*v15 ^ __ROR4__(v48, 4)) & 0x3F3F3F3F;
  v50 = box[HIBYTE(v49)] ^ box[BYTE2(v49) + 128] ^ box[BYTE1(v49) + 256] ^ box[(unsigned __int8)v49 + 384] ^ v44;
  v51 = (v15[1] ^ v48) & 0x3F3F3F3F;
  v52 = box[HIBYTE(v51) + 64] ^ box[BYTE2(v51) + 192] ^ box[BYTE1(v51) + 320] ^ box[(unsigned __int8)v51 + 448] ^ v50;
  v53 = (v15[2] ^ __ROR4__(v52, 4)) & 0x3F3F3F3F;
  v54 = box[HIBYTE(v53)] ^ box[BYTE2(v53) + 128] ^ box[BYTE1(v53) + 256] ^ box[(unsigned __int8)v53 + 384] ^ v48;
  v55 = (v15[3] ^ v52) & 0x3F3F3F3F;
  v15 += 4;
  v56 = box[HIBYTE(v55) + 64] ^ box[BYTE2(v55) + 192] ^ box[BYTE1(v55) + 320] ^ box[(unsigned __int8)v55 + 448] ^ v54;
  v57 = (*v15 ^ __ROR4__(v56, 4)) & 0x3F3F3F3F;
  v58 = box[HIBYTE(v57)] ^ box[BYTE2(v57) + 128] ^ box[BYTE1(v57) + 256] ^ box[(unsigned __int8)v57 + 384] ^ v52;
  v59 = (v15[1] ^ v56) & 0x3F3F3F3F;
  v60 = box[HIBYTE(v59) + 64] ^ box[BYTE2(v59) + 192] ^ box[BYTE1(v59) + 320] ^ box[(unsigned __int8)v59 + 448] ^ v58;
  v61 = (v15[2] ^ __ROR4__(v60, 4)) & 0x3F3F3F3F;
  v62 = box[HIBYTE(v61)] ^ box[BYTE2(v61) + 128] ^ box[BYTE1(v61) + 256] ^ box[(unsigned __int8)v61 + 384] ^ v56;
  v63 = (v15[3] ^ v60) & 0x3F3F3F3F;
  v15 += 4;
  v64 = box[HIBYTE(v63) + 64] ^ box[BYTE2(v63) + 192] ^ box[BYTE1(v63) + 320] ^ box[(unsigned __int8)v63 + 448] ^ v62;
  v65 = (*v15 ^ __ROR4__(v64, 4)) & 0x3F3F3F3F;
  v66 = box[HIBYTE(v65)] ^ box[BYTE2(v65) + 128] ^ box[BYTE1(v65) + 256] ^ box[(unsigned __int8)v65 + 384] ^ v60;
  v67 = (v15[1] ^ v64) & 0x3F3F3F3F;
  v68 = box[HIBYTE(v67) + 64] ^ box[BYTE2(v67) + 192] ^ box[BYTE1(v67) + 320] ^ box[(unsigned __int8)v67 + 448] ^ v66;
  v69 = (v15[2] ^ __ROR4__(v68, 4)) & 0x3F3F3F3F;
  v70 = box[HIBYTE(v69)] ^ box[BYTE2(v69) + 128] ^ box[BYTE1(v69) + 256] ^ box[(unsigned __int8)v69 + 384] ^ v64;
  v71 = (v15[3] ^ v68) & 0x3F3F3F3F;
  v15 += 4;
  v72 = box[HIBYTE(v71) + 64] ^ box[BYTE2(v71) + 192] ^ box[BYTE1(v71) + 320] ^ box[(unsigned __int8)v71 + 448] ^ v70;
  v73 = (*v15 ^ __ROR4__(v72, 4)) & 0x3F3F3F3F;
  v74 = box[HIBYTE(v73)] ^ box[BYTE2(v73) + 128] ^ box[BYTE1(v73) + 256] ^ box[(unsigned __int8)v73 + 384] ^ v68;
  v75 = (v15[1] ^ v72) & 0x3F3F3F3F;
  v76 = box[HIBYTE(v75) + 64] ^ box[BYTE2(v75) + 192] ^ box[BYTE1(v75) + 320] ^ box[(unsigned __int8)v75 + 448] ^ v74;
  v77 = (v15[2] ^ __ROR4__(v76, 4)) & 0x3F3F3F3F;
  v78 = box[HIBYTE(v77)] ^ box[BYTE2(v77) + 128] ^ box[BYTE1(v77) + 256] ^ box[(unsigned __int8)v77 + 384] ^ v72;
  v79 = (v15[3] ^ v76) & 0x3F3F3F3F;
  v15 += 4;
  v80 = box[HIBYTE(v79) + 64] ^ box[BYTE2(v79) + 192] ^ box[BYTE1(v79) + 320] ^ box[(unsigned __int8)v79 + 448] ^ v78;
  v81 = (*v15 ^ __ROR4__(v80, 4)) & 0x3F3F3F3F;
  v82 = box[HIBYTE(v81)] ^ box[BYTE2(v81) + 128] ^ box[BYTE1(v81) + 256] ^ box[(unsigned __int8)v81 + 384] ^ v76;
  v83 = (v15[1] ^ v80) & 0x3F3F3F3F;
  v84 = box[HIBYTE(v83) + 64] ^ box[BYTE2(v83) + 192] ^ box[BYTE1(v83) + 320] ^ box[(unsigned __int8)v83 + 448] ^ v82;
  v85 = (v15[2] ^ __ROR4__(v84, 4)) & 0x3F3F3F3F;
  v86 = box[HIBYTE(v85)] ^ box[BYTE2(v85) + 128] ^ box[BYTE1(v85) + 256] ^ box[(unsigned __int8)v85 + 384] ^ v80;
  v87 = (v15[3] ^ v84) & 0x3F3F3F3F;
  v15 += 4;
  v88 = box[HIBYTE(v87) + 64] ^ box[BYTE2(v87) + 192] ^ box[BYTE1(v87) + 320] ^ box[(unsigned __int8)v87 + 448] ^ v86;
  v89 = (*v15 ^ __ROR4__(v88, 4)) & 0x3F3F3F3F;
  v90 = box[HIBYTE(v89)] ^ box[BYTE2(v89) + 128] ^ box[BYTE1(v89) + 256] ^ box[(unsigned __int8)v89 + 384] ^ v84;
  v91 = (v15[1] ^ v88) & 0x3F3F3F3F;
  v92 = box[HIBYTE(v91) + 64] ^ box[BYTE2(v91) + 192] ^ box[BYTE1(v91) + 320] ^ box[(unsigned __int8)v91 + 448] ^ v90;
  v93 = (v15[2] ^ __ROR4__(v92, 4)) & 0x3F3F3F3F;
  v94 = box[HIBYTE(v93)] ^ box[BYTE2(v93) + 128] ^ box[BYTE1(v93) + 256] ^ box[(unsigned __int8)v93 + 384] ^ v88;
  v95 = (v15[3] ^ v92) & 0x3F3F3F3F;
  v15 += 4;
  v97 = v92;
  v96 = box[HIBYTE(v95) + 64] ^ box[BYTE2(v95) + 192] ^ box[BYTE1(v95) + 320] ^ box[(unsigned __int8)v95 + 448] ^ v94;
  v98 = (*v15 ^ __ROR4__(v97, 4)) & 0x3F3F3F3F;
  v99 = box[HIBYTE(v98)] ^ box[BYTE2(v98) + 128] ^ box[BYTE1(v98) + 256] ^ box[(unsigned __int8)v98 + 384] ^ v96;
  v100 = (v15[1] ^ v97) & 0x3F3F3F3F;
  v101 = box[HIBYTE(v100) + 64]
       ^ box[BYTE2(v100) + 192]
       ^ box[BYTE1(v100) + 320]
       ^ box[(unsigned __int8)v100 + 448]
       ^ v99;
  v102 = (v15[2] ^ __ROR4__(v101, 4)) & 0x3F3F3F3F;
  v103 = box[HIBYTE(v102)] ^ box[BYTE2(v102) + 128] ^ box[BYTE1(v102) + 256] ^ box[(unsigned __int8)v102 + 384] ^ v97;
  v104 = (v15[3] ^ v101) & 0x3F3F3F3F;
  v15 += 4;
  v105 = box[HIBYTE(v104) + 64]
       ^ box[BYTE2(v104) + 192]
       ^ box[BYTE1(v104) + 320]
       ^ box[(unsigned __int8)v104 + 448]
       ^ v103;
  v106 = (*v15 ^ __ROR4__(v105, 4)) & 0x3F3F3F3F;
  v107 = box[HIBYTE(v106)] ^ box[BYTE2(v106) + 128] ^ box[BYTE1(v106) + 256] ^ box[(unsigned __int8)v106 + 384] ^ v101;
  v108 = (v15[1] ^ v105) & 0x3F3F3F3F;
  v109 = box[HIBYTE(v108) + 64]
       ^ box[BYTE2(v108) + 192]
       ^ box[BYTE1(v108) + 320]
       ^ box[(unsigned __int8)v108 + 448]
       ^ v107;
  v110 = (v15[2] ^ __ROR4__(v109, 4)) & 0x3F3F3F3F;
  v111 = box[HIBYTE(v110)] ^ box[BYTE2(v110) + 128] ^ box[BYTE1(v110) + 256] ^ box[(unsigned __int8)v110 + 384] ^ v105;
  v112 = (v15[3] ^ v109) & 0x3F3F3F3F;
  v15 += 4;
  v113 = box[HIBYTE(v112) + 64]
       ^ box[BYTE2(v112) + 192]
       ^ box[BYTE1(v112) + 320]
       ^ box[(unsigned __int8)v112 + 448]
       ^ v111;
  v114 = (*v15 ^ __ROR4__(v113, 4)) & 0x3F3F3F3F;
  v115 = box[HIBYTE(v114)] ^ box[BYTE2(v114) + 128] ^ box[BYTE1(v114) + 256] ^ box[(unsigned __int8)v114 + 384] ^ v109;
  v116 = (v15[1] ^ v113) & 0x3F3F3F3F;
  v117 = box[HIBYTE(v116) + 64]
       ^ box[BYTE2(v116) + 192]
       ^ box[BYTE1(v116) + 320]
       ^ box[(unsigned __int8)v116 + 448]
       ^ v115;
  v118 = (v15[2] ^ __ROR4__(v117, 4)) & 0x3F3F3F3F;
  v119 = box[HIBYTE(v118)] ^ box[BYTE2(v118) + 128] ^ box[BYTE1(v118) + 256] ^ box[(unsigned __int8)v118 + 384] ^ v113;
  v120 = (v15[3] ^ v117) & 0x3F3F3F3F;
  v15 += 4;
  v121 = box[HIBYTE(v120) + 64]
       ^ box[BYTE2(v120) + 192]
       ^ box[BYTE1(v120) + 320]
       ^ box[(unsigned __int8)v120 + 448]
       ^ v119;
  v122 = (*v15 ^ __ROR4__(v121, 4)) & 0x3F3F3F3F;
  v123 = box[HIBYTE(v122)] ^ box[BYTE2(v122) + 128] ^ box[BYTE1(v122) + 256] ^ box[(unsigned __int8)v122 + 384] ^ v117;
  v124 = (v15[1] ^ v121) & 0x3F3F3F3F;
  v125 = box[HIBYTE(v124) + 64]
       ^ box[BYTE2(v124) + 192]
       ^ box[BYTE1(v124) + 320]
       ^ box[(unsigned __int8)v124 + 448]
       ^ v123;
  v126 = (v15[2] ^ __ROR4__(v125, 4)) & 0x3F3F3F3F;
  v127 = box[HIBYTE(v126)] ^ box[BYTE2(v126) + 128] ^ box[BYTE1(v126) + 256] ^ box[(unsigned __int8)v126 + 384] ^ v121;
  v128 = (v15[3] ^ v125) & 0x3F3F3F3F;
  v15 += 4;
  v129 = box[HIBYTE(v128) + 64]
       ^ box[BYTE2(v128) + 192]
       ^ box[BYTE1(v128) + 320]
       ^ box[(unsigned __int8)v128 + 448]
       ^ v127;
  v130 = (*v15 ^ __ROR4__(v129, 4)) & 0x3F3F3F3F;
  v131 = box[HIBYTE(v130)] ^ box[BYTE2(v130) + 128] ^ box[BYTE1(v130) + 256] ^ box[(unsigned __int8)v130 + 384] ^ v125;
  v132 = (v15[1] ^ v129) & 0x3F3F3F3F;
  v133 = box[HIBYTE(v132) + 64]
       ^ box[BYTE2(v132) + 192]
       ^ box[BYTE1(v132) + 320]
       ^ box[(unsigned __int8)v132 + 448]
       ^ v131;
  v134 = (v15[2] ^ __ROR4__(v133, 4)) & 0x3F3F3F3F;
  v135 = box[HIBYTE(v134)] ^ box[BYTE2(v134) + 128] ^ box[BYTE1(v134) + 256] ^ box[(unsigned __int8)v134 + 384] ^ v129;
  v136 = (v15[3] ^ v133) & 0x3F3F3F3F;
  v15 += 4;
  v137 = box[HIBYTE(v136) + 64]
       ^ box[BYTE2(v136) + 192]
       ^ box[BYTE1(v136) + 320]
       ^ box[(unsigned __int8)v136 + 448]
       ^ v135;
  v138 = (*v15 ^ __ROR4__(v137, 4)) & 0x3F3F3F3F;
  v139 = box[HIBYTE(v138)] ^ box[BYTE2(v138) + 128] ^ box[BYTE1(v138) + 256] ^ box[(unsigned __int8)v138 + 384] ^ v133;
  v140 = (v15[1] ^ v137) & 0x3F3F3F3F;
  v141 = box[HIBYTE(v140) + 64]
       ^ box[BYTE2(v140) + 192]
       ^ box[BYTE1(v140) + 320]
       ^ box[(unsigned __int8)v140 + 448]
       ^ v139;
  v142 = (v15[2] ^ __ROR4__(v141, 4)) & 0x3F3F3F3F;
  v143 = box[HIBYTE(v142)] ^ box[BYTE2(v142) + 128] ^ box[BYTE1(v142) + 256] ^ box[(unsigned __int8)v142 + 384] ^ v137;
  v144 = (v15[3] ^ v141) & 0x3F3F3F3F;
  v15 += 4;
  v145 = box[HIBYTE(v144) + 64]
       ^ box[BYTE2(v144) + 192]
       ^ box[BYTE1(v144) + 320]
       ^ box[(unsigned __int8)v144 + 448]
       ^ v143;
  v146 = (*v15 ^ __ROR4__(v145, 4)) & 0x3F3F3F3F;
  v147 = box[HIBYTE(v146)] ^ box[BYTE2(v146) + 128] ^ box[BYTE1(v146) + 256] ^ box[(unsigned __int8)v146 + 384] ^ v141;
  v148 = (v15[1] ^ v145) & 0x3F3F3F3F;
  v149 = box[HIBYTE(v148) + 64]
       ^ box[BYTE2(v148) + 192]
       ^ box[BYTE1(v148) + 320]
       ^ box[(unsigned __int8)v148 + 448]
       ^ v147;
  v150 = (v15[2] ^ __ROR4__(v149, 4)) & 0x3F3F3F3F;
  v151 = box[HIBYTE(v150)] ^ box[BYTE2(v150) + 128] ^ box[BYTE1(v150) + 256] ^ box[(unsigned __int8)v150 + 384] ^ v145;
  v152 = (v15[3] ^ v149) & 0x3F3F3F3F;
  v15 += 4;
  v153 = box[HIBYTE(v152) + 64]
       ^ box[BYTE2(v152) + 192]
       ^ box[BYTE1(v152) + 320]
       ^ box[(unsigned __int8)v152 + 448]
       ^ v151;
  v154 = (*v15 ^ __ROR4__(v153, 4)) & 0x3F3F3F3F;
  v155 = box[HIBYTE(v154)] ^ box[BYTE2(v154) + 128] ^ box[BYTE1(v154) + 256] ^ box[(unsigned __int8)v154 + 384] ^ v149;
  v156 = (v15[1] ^ v153) & 0x3F3F3F3F;
  v157 = box[HIBYTE(v156) + 64]
       ^ box[BYTE2(v156) + 192]
       ^ box[BYTE1(v156) + 320]
       ^ box[(unsigned __int8)v156 + 448]
       ^ v155;
  v158 = (v15[2] ^ __ROR4__(v157, 4)) & 0x3F3F3F3F;
  v159 = box[HIBYTE(v158)] ^ box[BYTE2(v158) + 128] ^ box[BYTE1(v158) + 256] ^ box[(unsigned __int8)v158 + 384] ^ v153;
  v160 = (v15[3] ^ v157) & 0x3F3F3F3F;
  v15 += 4;
  v162 = v157;
  v161 = box[HIBYTE(v160) + 64]
       ^ box[BYTE2(v160) + 192]
       ^ box[BYTE1(v160) + 320]
       ^ box[(unsigned __int8)v160 + 448]
       ^ v159;
  v163 = (*v15 ^ __ROR4__(v162, 4)) & 0x3F3F3F3F;
  v164 = box[HIBYTE(v163)] ^ box[BYTE2(v163) + 128] ^ box[BYTE1(v163) + 256] ^ box[(unsigned __int8)v163 + 384] ^ v161;
  v165 = (v15[1] ^ v162) & 0x3F3F3F3F;
  v166 = box[HIBYTE(v165) + 64]
       ^ box[BYTE2(v165) + 192]
       ^ box[BYTE1(v165) + 320]
       ^ box[(unsigned __int8)v165 + 448]
       ^ v164;
  v167 = (v15[2] ^ __ROR4__(v166, 4)) & 0x3F3F3F3F;
  v168 = box[HIBYTE(v167)] ^ box[BYTE2(v167) + 128] ^ box[BYTE1(v167) + 256] ^ box[(unsigned __int8)v167 + 384] ^ v162;
  v169 = (v15[3] ^ v166) & 0x3F3F3F3F;
  v15 += 4;
  v170 = box[HIBYTE(v169) + 64]
       ^ box[BYTE2(v169) + 192]
       ^ box[BYTE1(v169) + 320]
       ^ box[(unsigned __int8)v169 + 448]
       ^ v168;
  v171 = (*v15 ^ __ROR4__(v170, 4)) & 0x3F3F3F3F;
  v172 = box[HIBYTE(v171)] ^ box[BYTE2(v171) + 128] ^ box[BYTE1(v171) + 256] ^ box[(unsigned __int8)v171 + 384] ^ v166;
  v173 = (v15[1] ^ v170) & 0x3F3F3F3F;
  v174 = box[HIBYTE(v173) + 64]
       ^ box[BYTE2(v173) + 192]
       ^ box[BYTE1(v173) + 320]
       ^ box[(unsigned __int8)v173 + 448]
       ^ v172;
  v175 = (v15[2] ^ __ROR4__(v174, 4)) & 0x3F3F3F3F;
  v176 = box[HIBYTE(v175)] ^ box[BYTE2(v175) + 128] ^ box[BYTE1(v175) + 256] ^ box[(unsigned __int8)v175 + 384] ^ v170;
  v177 = (v15[3] ^ v174) & 0x3F3F3F3F;
  v15 += 4;
  v178 = box[HIBYTE(v177) + 64]
       ^ box[BYTE2(v177) + 192]
       ^ box[BYTE1(v177) + 320]
       ^ box[(unsigned __int8)v177 + 448]
       ^ v176;
  v179 = (*v15 ^ __ROR4__(v178, 4)) & 0x3F3F3F3F;
  v180 = box[HIBYTE(v179)] ^ box[BYTE2(v179) + 128] ^ box[BYTE1(v179) + 256] ^ box[(unsigned __int8)v179 + 384] ^ v174;
  v181 = (v15[1] ^ v178) & 0x3F3F3F3F;
  v182 = box[HIBYTE(v181) + 64]
       ^ box[BYTE2(v181) + 192]
       ^ box[BYTE1(v181) + 320]
       ^ box[(unsigned __int8)v181 + 448]
       ^ v180;
  v183 = (v15[2] ^ __ROR4__(v182, 4)) & 0x3F3F3F3F;
  v184 = box[HIBYTE(v183)] ^ box[BYTE2(v183) + 128] ^ box[BYTE1(v183) + 256] ^ box[(unsigned __int8)v183 + 384] ^ v178;
  v185 = (v15[3] ^ v182) & 0x3F3F3F3F;
  v15 += 4;
  v186 = box[HIBYTE(v185) + 64]
       ^ box[BYTE2(v185) + 192]
       ^ box[BYTE1(v185) + 320]
       ^ box[(unsigned __int8)v185 + 448]
       ^ v184;
  v187 = (*v15 ^ __ROR4__(v186, 4)) & 0x3F3F3F3F;
  v188 = box[HIBYTE(v187)] ^ box[BYTE2(v187) + 128] ^ box[BYTE1(v187) + 256] ^ box[(unsigned __int8)v187 + 384] ^ v182;
  v189 = (v15[1] ^ v186) & 0x3F3F3F3F;
  v190 = box[HIBYTE(v189) + 64]
       ^ box[BYTE2(v189) + 192]
       ^ box[BYTE1(v189) + 320]
       ^ box[(unsigned __int8)v189 + 448]
       ^ v188;
  v191 = (v15[2] ^ __ROR4__(v190, 4)) & 0x3F3F3F3F;
  v192 = box[HIBYTE(v191)] ^ box[BYTE2(v191) + 128] ^ box[BYTE1(v191) + 256] ^ box[(unsigned __int8)v191 + 384] ^ v186;
  v193 = (v15[3] ^ v190) & 0x3F3F3F3F;
  v15 += 4;
  v194 = box[HIBYTE(v193) + 64]
       ^ box[BYTE2(v193) + 192]
       ^ box[BYTE1(v193) + 320]
       ^ box[(unsigned __int8)v193 + 448]
       ^ v192;
  v195 = (*v15 ^ __ROR4__(v194, 4)) & 0x3F3F3F3F;
  v196 = box[HIBYTE(v195)] ^ box[BYTE2(v195) + 128] ^ box[BYTE1(v195) + 256] ^ box[(unsigned __int8)v195 + 384] ^ v190;
  v197 = (v15[1] ^ v194) & 0x3F3F3F3F;
  v198 = box[HIBYTE(v197) + 64]
       ^ box[BYTE2(v197) + 192]
       ^ box[BYTE1(v197) + 320]
       ^ box[(unsigned __int8)v197 + 448]
       ^ v196;
  v199 = (v15[2] ^ __ROR4__(v198, 4)) & 0x3F3F3F3F;
  v200 = box[HIBYTE(v199)] ^ box[BYTE2(v199) + 128] ^ box[BYTE1(v199) + 256] ^ box[(unsigned __int8)v199 + 384] ^ v194;
  v201 = (v15[3] ^ v198) & 0x3F3F3F3F;
  v15 += 4;
  v202 = box[HIBYTE(v201) + 64]
       ^ box[BYTE2(v201) + 192]
       ^ box[BYTE1(v201) + 320]
       ^ box[(unsigned __int8)v201 + 448]
       ^ v200;
  v203 = (*v15 ^ __ROR4__(v202, 4)) & 0x3F3F3F3F;
  v204 = box[HIBYTE(v203)] ^ box[BYTE2(v203) + 128] ^ box[BYTE1(v203) + 256] ^ box[(unsigned __int8)v203 + 384] ^ v198;
  v205 = (v15[1] ^ v202) & 0x3F3F3F3F;
  v206 = box[HIBYTE(v205) + 64]
       ^ box[BYTE2(v205) + 192]
       ^ box[BYTE1(v205) + 320]
       ^ box[(unsigned __int8)v205 + 448]
       ^ v204;
  v207 = (v15[2] ^ __ROR4__(v206, 4)) & 0x3F3F3F3F;
  v208 = box[HIBYTE(v207)] ^ box[BYTE2(v207) + 128] ^ box[BYTE1(v207) + 256] ^ box[(unsigned __int8)v207 + 384] ^ v202;
  v209 = (v15[3] ^ v206) & 0x3F3F3F3F;
  v15 += 4;
  v210 = box[HIBYTE(v209) + 64]
       ^ box[BYTE2(v209) + 192]
       ^ box[BYTE1(v209) + 320]
       ^ box[(unsigned __int8)v209 + 448]
       ^ v208;
  v211 = (*v15 ^ __ROR4__(v210, 4)) & 0x3F3F3F3F;
  v212 = box[HIBYTE(v211)] ^ box[BYTE2(v211) + 128] ^ box[BYTE1(v211) + 256] ^ box[(unsigned __int8)v211 + 384] ^ v206;
  v213 = (v15[1] ^ v210) & 0x3F3F3F3F;
  v214 = box[HIBYTE(v213) + 64]
       ^ box[BYTE2(v213) + 192]
       ^ box[BYTE1(v213) + 320]
       ^ box[(unsigned __int8)v213 + 448]
       ^ v212;
  v215 = (v15[2] ^ __ROR4__(v214, 4)) & 0x3F3F3F3F;
  v216 = box[HIBYTE(v215)] ^ box[BYTE2(v215) + 128] ^ box[BYTE1(v215) + 256] ^ box[(unsigned __int8)v215 + 384] ^ v210;
  v217 = (v15[3] ^ v214) & 0x3F3F3F3F;
  v15 += 4;
  v218 = box[HIBYTE(v217) + 64]
       ^ box[BYTE2(v217) + 192]
       ^ box[BYTE1(v217) + 320]
       ^ box[(unsigned __int8)v217 + 448]
       ^ v216;
  v219 = (*v15 ^ __ROR4__(v218, 4)) & 0x3F3F3F3F;
  v220 = box[HIBYTE(v219)] ^ box[BYTE2(v219) + 128] ^ box[BYTE1(v219) + 256] ^ box[(unsigned __int8)v219 + 384] ^ v214;
  v221 = (v15[1] ^ v218) & 0x3F3F3F3F;
  v222 = box[HIBYTE(v221) + 64]
       ^ box[BYTE2(v221) + 192]
       ^ box[BYTE1(v221) + 320]
       ^ box[(unsigned __int8)v221 + 448]
       ^ v220;
  v223 = (v15[2] ^ __ROR4__(v222, 4)) & 0x3F3F3F3F;
  v224 = box[HIBYTE(v223)] ^ box[BYTE2(v223) + 128] ^ box[BYTE1(v223) + 256] ^ box[(unsigned __int8)v223 + 384] ^ v218;
  v225 = (v15[3] ^ v222) & 0x3F3F3F3F;
  v226 = __ROR4__(
           box[HIBYTE(v225) + 64]
         ^ box[BYTE2(v225) + 192]
         ^ box[BYTE1(v225) + 320]
         ^ box[(unsigned __int8)v225 + 448]
         ^ v224,
           1);
  v227 = (v226 ^ v222) & 0xAAAAAAAA;
  v228 = v227 ^ v226;
  v229 = __ROR4__(v227 ^ v222, 9);
  v230 = (v229 ^ v228) & 0xFF00FF;
  v231 = v230 ^ v228;
  v232 = __ROL4__(v230 ^ v229, 6);
  v233 = (v232 ^ v231) & 0x33333333;
  v234 = v233 ^ v231;
  v235 = __ROL4__(v233 ^ v232, 18);
  v236 = (v235 ^ v234) & 0xFFFF0000;
  v237 = v236 ^ v234;
  v238 = __ROL4__(v236 ^ v235, 20);
  v239 = (v238 ^ v237) & 0xF0F0F0F0;
  __asm { movd    ebp, mm6 }
  v241 = *(_DWORD **)(_EBP + 12);
  *v241 = _byteswap_ulong(v239 ^ v237);
  v241[1] = _byteswap_ulong(__ROR4__(v239 ^ v238, 4));
  __asm
  {
    movd    edi, mm3
    movd    ebx, mm4
    movd    esi, mm5
  }
  _m_empty();
}

//------------------------------------------------------------------------------
// Address: 0x00449000
// Name: public: void TaoCrypt::BasicDES::SetKey(unsigned char const __near *,unsigned int,enum TaoCrypt::CipherDir)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::BasicDES::SetKey(_DWORD *this, const LoggingContext_t *key, unsigned int __formal, int a4)
{
  int j; // eax
  int v5; // edx
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // esi
  int v10; // esi
  int v11; // esi
  int v12; // esi
  unsigned int v13; // ecx
  unsigned int v14; // ebp
  unsigned int v15; // edi
  int v16; // esi
  _DWORD *v17; // esi
  unsigned __int8 v18; // ch
  int v19; // eax
  int result; // eax
  _DWORD *v21; // ecx
  int v22; // edx
  int v23; // edx
  unsigned int v24; // [esp+8h] [ebp-8Ch]
  unsigned int v25; // [esp+Ch] [ebp-88h]
  int i; // [esp+10h] [ebp-84h]
  _DWORD *v27; // [esp+14h] [ebp-80h]
  _BYTE v28[112]; // [esp+18h] [ebp-7Ch]
  int v29; // [esp+88h] [ebp-Ch]
  int v30; // [esp+8Ch] [ebp-8h]

  v27 = this;
  for ( j = 0; j < 56; j += 4 )
  {
    v28[j] = (*((_BYTE *)&key->m_ChannelID + ((*((unsigned __int8 *)&pc1.__vftable + j) - 1) >> 3))
            & *((_BYTE *)&loc_47D9F6 + 4 * ((*((unsigned __int8 *)&pc1.__vftable + j) - 1) & 7) + 2)) != 0;
    v28[j + 1] = (*((_BYTE *)&key->m_ChannelID + ((*((unsigned __int8 *)&pc1.__vftable + j + 1) - 1) >> 3))
                & *((_BYTE *)&loc_47D9F6 + 4 * ((*((unsigned __int8 *)&pc1.__vftable + j + 1) - 1) & 7) + 2)) != 0;
    v28[j + 2] = (*((_BYTE *)&key->m_ChannelID + ((*((unsigned __int8 *)&pc1.__vftable + j + 2) - 1) >> 3))
                & *((_BYTE *)&loc_47D9F6 + 4 * ((*((unsigned __int8 *)&pc1.__vftable + j + 2) - 1) & 7) + 2)) != 0;
    v28[j + 3] = (*((_BYTE *)&key->m_ChannelID + ((*((unsigned __int8 *)&pc1.__vftable + j + 3) - 1) >> 3))
                & *((_BYTE *)&loc_47D9F6 + 4 * ((*((unsigned __int8 *)&pc1.__vftable + j + 3) - 1) & 7) + 2)) != 0;
  }
  v5 = 0;
  i = 0;
  do
  {
    v6 = *((unsigned __int8 *)totrot + v5);
    v7 = 0;
    v29 = 0;
    v30 = 0;
    v8 = v6 - 26;
    do
    {
      v9 = v8 + 26;
      if ( v8 + 26 >= (v7 >= 28 ? 56 : 28) )
        v9 = v8 - 2;
      v28[v7 + 56] = v28[v9];
      v10 = v8 + 27;
      if ( v8 + 27 >= (v7 >= 27 ? 56 : 28) )
        v10 = v8 - 1;
      v28[v7 + 57] = v28[v10];
      v11 = v8 + 28;
      if ( v8 + 28 >= (v7 >= 26 ? 56 : 28) )
        v11 = v8;
      v28[v7 + 58] = v28[v11];
      v12 = v8 + 29;
      if ( v8 + 29 >= (v7 >= 25 ? 56 : 28) )
        v12 = v8 + 1;
      v28[v7 + 59] = v28[v12];
      v7 += 4;
      v8 += 4;
    }
    while ( v7 < 56 );
    v13 = 0;
    v25 = 5;
    v24 = 4;
    v14 = 3;
    v15 = 2;
    v16 = 1;
    do
    {
      if ( v28[*((unsigned __int8 *)&loc_47D9C3 + v16 + 4) + 55] != 0 )
        *((_BYTE *)&v29 + v13 / 6) |= *(int *)((char *)&loc_47D9F6 + 4 * (v13 % 6) + 2) >> 2;
      if ( v28[*((unsigned __int8 *)pc2 + v16) + 55] != 0 )
        *((_BYTE *)&v29 + v16 / 6u) |= *(int *)((char *)&loc_47D9FB + 4 * (v13 - 6 * (v16 / 6u)) + 1) >> 2;
      if ( v28[*((unsigned __int8 *)pc2 + v15) + 55] != 0 )
        *((_BYTE *)&v29 + v15 / 6) |= dword_47DA00[v13 - 6 * (v15 / 6)] >> 2;
      if ( v28[*((unsigned __int8 *)pc2 + v14) + 55] != 0 )
        *((_BYTE *)&v29 + v14 / 6) |= dword_47DA04[v13 - 6 * (v14 / 6)] >> 2;
      if ( v28[*((unsigned __int8 *)pc2 + v24) + 55] != 0 )
        *((_BYTE *)&v29 + v24 / 6) |= dword_47DA08[v13 - 6 * (v24 / 6)] >> 2;
      if ( v28[*((unsigned __int8 *)pc2 + v25) + 55] != 0 )
        *((_BYTE *)&v29 + v25 / 6) |= dword_47DA0C[v13 - 6 * (v25 / 6)] >> 2;
      v24 += 6;
      v25 += 6;
      v16 += 6;
      v13 += 6;
      v15 += 6;
      v14 += 6;
    }
    while ( v16 < 49 );
    v17 = v27;
    v18 = BYTE1(v30);
    v19 = BYTE1(v29) << 8;
    v27[2 * i] = BYTE2(v30) | (((unsigned __int8)v30 | ((BYTE2(v29) | ((unsigned __int8)v29 << 8)) << 8)) << 8);
    result = HIBYTE(v30) | ((v18 | ((HIBYTE(v29) | v19) << 8)) << 8);
    v17[2 * i + 1] = result;
    v5 = i + 1;
    i = v5;
  }
  while ( v5 < 16 );
  if ( a4 == 1 )
  {
    result = 0;
    v21 = v17 + 31;
    do
    {
      v22 = v17[result];
      v17[result] = *(v21 - 1);
      *(v21 - 1) = v22;
      v23 = v17[result + 1];
      v17[result + 1] = *v21;
      *v21 = v23;
      result += 2;
      v21 -= 2;
    }
    while ( result < 16 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004493B0
// Name: public: void TaoCrypt::DES_EDE3::SetKey(unsigned char const __near *,unsigned int,enum TaoCrypt::CipherDir)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::DES_EDE3::SetKey(
        CInterlockedIntT<unsigned int> *this,
        const LoggingContext_t *key,
        unsigned int sz,
        int a4)
{
  TaoCrypt::BasicDES::SetKey(
    this: (_DWORD *)this + 14,
    key: (const LoggingContext_t *)((char *)key + (a4 != 0 ? 0x10 : 0)),
    __formal: sz,
    a4);
  TaoCrypt::BasicDES::SetKey(
    this: (_DWORD *)this + 46,
    key: (const LoggingContext_t *)&key->m_Severity,
    __formal: sz,
    a4: a4 == 0);
  return TaoCrypt::BasicDES::SetKey(
           this: (_DWORD *)this + 78,
           key: (const LoggingContext_t *)((char *)key + (a4 != 1 ? 0x10 : 0)),
           __formal: sz,
           a4);
}

//------------------------------------------------------------------------------
// Address: 0x00449410
// Name: public: virtual void TaoCrypt::DES_EDE3::Process(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::DES_EDE3::Process(
        CInterlockedIntT<unsigned int> *this@<ecx>,
        unsigned int a2@<ebp>,
        unsigned __int8 *out,
        unsigned __int8 *in,
        unsigned int sz)
{
  int v6; // eax
  unsigned int v7; // ebx
  unsigned __int8 *v8; // ebp
  CInterlockedIntT<unsigned int> *v9; // edi
  unsigned __int8 *v10; // ebp
  int v11; // edi
  int v12; // edx
  const LoggingContext_t *v13; // ebp
  unsigned __int8 *v14; // edi

  if ( TaoCrypt::isMMX )
  {
    v7 = sz >> 3;
    if ( *((_DWORD *)this + 13) == 1 )
    {
      if ( *((_DWORD *)this + 12) != 0 )
      {
        if ( v7 != 0 )
        {
          v10 = in;
          v11 = (int)out;
          do
          {
            TaoCrypt::DES_EDE3::AsmProcess(
              (TaoCrypt::DES_EDE3 *)this,
              _EBX: --v7,
              _EDI: v11,
              _ESI: (int)this,
              in: (const LoggingContext_t *)v10,
              out: (unsigned __int8 *)v11,
              box: &Spbox);
            *(_DWORD *)v11 ^= *((_DWORD *)this + 4);
            *(_DWORD *)(v11 + 4) ^= *((_DWORD *)this + 5);
            *(this + 4) = *(CInterlockedIntT<unsigned int> *)v10;
            v12 = *((_DWORD *)v10 + 1);
            v11 += 8;
            v10 += 8;
            *((_DWORD *)this + 5) = v12;
          }
          while ( v7 != 0 );
        }
      }
      else if ( v7 != 0 )
      {
        v8 = in;
        v9 = this + 4;
        do
        {
          v9->m_value ^= *(_DWORD *)v8;
          *((_DWORD *)this + 5) ^= *((_DWORD *)v8 + 1);
          TaoCrypt::DES_EDE3::AsmProcess(
            (TaoCrypt::DES_EDE3 *)this,
            _EBX: --v7,
            _EDI: (int)v9,
            _ESI: (int)this,
            in: (const LoggingContext_t *)this + 1,
            out: (unsigned __int8 *)this + 16,
            box: &Spbox);
          *(CInterlockedIntT<unsigned int> *)out = (CInterlockedIntT<unsigned int>)v9->m_value;
          *((CInterlockedIntT<unsigned int> *)out + 1) = *(this + 5);
          v8 += 8;
          out += 8;
        }
        while ( v7 != 0 );
      }
    }
    else if ( v7 != 0 )
    {
      v13 = (const LoggingContext_t *)in;
      v14 = out;
      do
      {
        TaoCrypt::DES_EDE3::AsmProcess(
          (TaoCrypt::DES_EDE3 *)this,
          _EBX: --v7,
          _EDI: (int)v14,
          _ESI: (int)this,
          in: v13,
          out: v14,
          box: &Spbox);
        v14 += 8;
        v13 = (const LoggingContext_t *)((char *)v13 + 8);
      }
      while ( v7 != 0 );
    }
  }
  else
  {
    v6 = *((_DWORD *)this + 13);
    if ( v6 != 0 )
    {
      if ( v6 == 1 )
      {
        if ( *((_DWORD *)this + 12) != 0 )
          TaoCrypt::Mode_BASE::CBC_Decrypt((CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this, a2, out, in, sz);
        else
          TaoCrypt::Mode_BASE::CBC_Encrypt((CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this, a2, out, in, sz);
      }
    }
    else
    {
      TaoCrypt::Mode_BASE::ECB_Process(
        (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
        out,
        (const LoggingContext_t *)in,
        sz);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449550
// Name: public: class TaoCrypt::PutBlock<unsigned int,struct TaoCrypt::EnumToType<enum TaoCrypt::ByteOrder,1>,1> __near & TaoCrypt::PutBlock<unsigned int,struct TaoCrypt::EnumToType<enum TaoCrypt::ByteOrder,1>,1>::operator()<unsigned int>(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *__thiscall TaoCrypt::PutBlock<unsigned int,TaoCrypt::EnumToType<enum TaoCrypt::ByteOrder,1>,1>::operator()<unsigned int>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this,
        unsigned int x)
{
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *result; // eax
  unsigned int *m_nAllocationCount; // esi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx

  result = this;
  m_nAllocationCount = (unsigned int *)this->m_Memory.m_nAllocationCount;
  if ( this->m_Memory.m_pMemory != nullptr )
    *m_nAllocationCount = (int)*this->m_Memory.m_pMemory ^ (__ROL4__(x, 8) & 0xFF00FF | __ROR4__(x, 8) & 0xFF00FF00);
  else
    *m_nAllocationCount = __ROL4__(x, 8) & 0xFF00FF | __ROR4__(x, 8) & 0xFF00FF00;
  m_pMemory = this->m_Memory.m_pMemory;
  result->m_Memory.m_nAllocationCount += 4;
  if ( m_pMemory != nullptr )
    result->m_Memory.m_pMemory = m_pMemory + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004495B0
// Name: private: virtual void TaoCrypt::DES::ProcessAndXorBlock(unsigned char const __near *,unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *__thiscall TaoCrypt::DES::ProcessAndXorBlock(
        CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> *this,
        _DWORD *in,
        const LoggingContext_t *xOr,
        unsigned __int8 *out)
{
  _DWORD *v5; // edx
  unsigned int *v6; // eax
  unsigned int *v7; // ecx
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *v8; // eax
  unsigned int v10; // [esp-4h] [ebp-14h]
  unsigned int r; // [esp+4h] [ebp-Ch] BYREF
  _DWORD v12[2]; // [esp+8h] [ebp-8h] BYREF

  v5 = (_DWORD *)(__ROL4__(*in, 8) & 0xFF00FF | __ROR4__(*in, 8) & 0xFF00FF00);
  r = __ROL4__(in[1], 8) & 0xFF00FF | __ROR4__(in[1], 8) & 0xFF00FF00;
  in = v5;
  v6 = TaoCrypt::IPERM(result: &r, a2: &in);
  TaoCrypt::BasicDES::RawProcessBlock(this: (TaoCrypt::BasicDES *)((char *)this + 56), rIn: v7, rIn_4: v6);
  TaoCrypt::FPERM(a1: &r, a2: &in);
  v12[0] = xOr;
  v10 = (unsigned int)in;
  v12[1] = out;
  v8 = TaoCrypt::PutBlock<unsigned int,TaoCrypt::EnumToType<enum TaoCrypt::ByteOrder,1>,1>::operator()<unsigned int>(
         this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)v12,
         x: r);
  return TaoCrypt::PutBlock<unsigned int,TaoCrypt::EnumToType<enum TaoCrypt::ByteOrder,1>,1>::operator()<unsigned int>(
           this: v8,
           x: v10);
}

//------------------------------------------------------------------------------
// Address: 0x00449650
// Name: private: virtual void TaoCrypt::DES_EDE3::ProcessAndXorBlock(unsigned char const __near *,unsigned char const __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::DES_EDE3::ProcessAndXorBlock(
        TaoCrypt::DES_EDE3 *this,
        const unsigned __int8 *l,
        const LoggingContext_t *xOr,
        unsigned __int8 *out)
{
  const unsigned __int8 *v5; // edx
  unsigned int *v6; // eax
  unsigned int *v7; // ecx
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *v8; // eax
  const unsigned __int8 *v9; // [esp-4h] [ebp-14h]
  unsigned int r; // [esp+4h] [ebp-Ch] BYREF
  _DWORD v11[2]; // [esp+8h] [ebp-8h] BYREF

  v5 = (const unsigned __int8 *)(__ROL4__(*(_DWORD *)l, 8) & 0xFF00FF | __ROR4__(*(_DWORD *)l, 8) & 0xFF00FF00);
  r = __ROL4__(*((_DWORD *)l + 1), 8) & 0xFF00FF | __ROR4__(*((_DWORD *)l + 1), 8) & 0xFF00FF00;
  l = v5;
  v6 = TaoCrypt::IPERM(result: &r, a2: &l);
  TaoCrypt::BasicDES::RawProcessBlock(this: (TaoCrypt::BasicDES *)((char *)this + 56), rIn: v7, rIn_4: v6);
  TaoCrypt::BasicDES::RawProcessBlock(
    this: (TaoCrypt::BasicDES *)((char *)this + 184),
    rIn: &r,
    rIn_4: (unsigned int *)&l);
  TaoCrypt::BasicDES::RawProcessBlock(
    this: (TaoCrypt::BasicDES *)((char *)this + 312),
    rIn: (unsigned int *)&l,
    rIn_4: &r);
  TaoCrypt::FPERM(a1: &r, a2: &l);
  v11[0] = xOr;
  v9 = l;
  v11[1] = out;
  v8 = TaoCrypt::PutBlock<unsigned int,TaoCrypt::EnumToType<enum TaoCrypt::ByteOrder,1>,1>::operator()<unsigned int>(
         this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)v11,
         x: r);
  TaoCrypt::PutBlock<unsigned int,TaoCrypt::EnumToType<enum TaoCrypt::ByteOrder,1>,1>::operator()<unsigned int>(
    this: v8,
    x: (unsigned int)v9);
}
