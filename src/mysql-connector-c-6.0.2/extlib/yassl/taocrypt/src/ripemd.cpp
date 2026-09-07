// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/taocrypt/src/ripemd.cpp
// Functions: 4
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\taocrypt\src\ripemd.h"

//------------------------------------------------------------------------------
// Address: 0x00442750
// Name: public: virtual void TaoCrypt::RIPEMD160::Init(void)
// Source: json
//------------------------------------------------------------------------------
std::exception *__thiscall TaoCrypt::RIPEMD160::Init(std::exception *this)
{
  *((_DWORD *)this + 4) = 1732584193;
  *((_DWORD *)this + 5) = -271733879;
  *((_DWORD *)this + 6) = -1732584194;
  *((_DWORD *)this + 7) = 271733878;
  *((_DWORD *)this + 8) = -1009589776;
  this->_Mywhat = nullptr;
  *(_DWORD *)&this->_Mydofree = 0;
  *((_DWORD *)this + 3) = 0;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00444BC0
// Name: private: virtual void TaoCrypt::RIPEMD160::Transform(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::RIPEMD160::Transform(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this)
{
  int v1; // ebx
  int v2; // ebp
  int v3; // edi
  int v4; // eax
  int v5; // edx
  unsigned int v6; // esi
  int v7; // edi
  int v8; // edx
  unsigned int v9; // ebx
  int v10; // eax
  int v11; // edi
  unsigned int v12; // edx
  int v13; // esi
  unsigned int v14; // eax
  int v15; // edx
  unsigned int v16; // edi
  int v17; // ebx
  unsigned int v18; // eax
  int v19; // edi
  unsigned int v20; // edx
  int v21; // ebx
  int v22; // esi
  int v23; // eax
  int v24; // edx
  unsigned int v25; // edi
  int v26; // esi
  int v27; // ebx
  unsigned int v28; // eax
  unsigned int v29; // edx
  unsigned int v30; // edi
  unsigned int v31; // eax
  int v32; // esi
  int v33; // edi
  unsigned int v34; // eax
  int v35; // edx
  int v36; // edx
  unsigned int v37; // esi
  int v38; // eax
  int v39; // esi
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v52; // eax
  int v53; // eax
  int v54; // eax
  int v55; // eax
  int v56; // eax
  int v57; // eax
  int v58; // eax
  int v59; // eax
  int v60; // eax
  int v61; // eax
  int v62; // eax
  int v63; // eax
  int v64; // eax
  int v65; // eax
  int v66; // eax
  int v67; // eax
  int v68; // eax
  int v69; // eax
  int v70; // eax
  int v71; // eax
  int v72; // edx
  int v73; // eax
  int v74; // eax
  int v75; // eax
  int v76; // eax
  int v77; // eax
  int v78; // eax
  int v79; // eax
  int v80; // eax
  int v81; // eax
  int v82; // eax
  int v83; // eax
  int v84; // eax
  int v85; // eax
  int v86; // eax
  int v87; // eax
  int v88; // eax
  int v89; // eax
  int v90; // eax
  int v91; // eax
  int v92; // eax
  int v93; // eax
  int v94; // eax
  int v95; // eax
  int v96; // eax
  int v97; // eax
  int v98; // eax
  int v99; // eax
  int v100; // eax
  int v101; // eax
  int v102; // eax
  int v103; // eax
  int v104; // eax
  int v105; // edx
  unsigned int v106; // eax
  unsigned int v107; // edx
  unsigned int v108; // esi
  unsigned int v109; // edi
  int v110; // edx
  unsigned int v111; // ebx
  int v112; // esi
  int v113; // eax
  int v114; // edi
  int v115; // edx
  int v116; // ebx
  int v117; // esi
  int v118; // eax
  int v119; // edx
  unsigned int v120; // edi
  int v121; // ebx
  unsigned int v122; // edx
  int v123; // edi
  unsigned int v124; // esi
  int v125; // ebx
  int v126; // eax
  int v127; // edx
  int v128; // ebp
  int v129; // esi
  int v130; // edi
  unsigned int v131; // ebx
  int result; // eax
  unsigned int a2; // [esp+10h] [ebp-2Ch]
  unsigned int a2a; // [esp+10h] [ebp-2Ch]
  unsigned int a2b; // [esp+10h] [ebp-2Ch]
  unsigned int a2c; // [esp+10h] [ebp-2Ch]
  unsigned int a2d; // [esp+10h] [ebp-2Ch]
  unsigned int a2e; // [esp+10h] [ebp-2Ch]
  unsigned int a2f; // [esp+10h] [ebp-2Ch]
  unsigned int a2g; // [esp+10h] [ebp-2Ch]
  unsigned int a2h; // [esp+10h] [ebp-2Ch]
  unsigned int a2i; // [esp+10h] [ebp-2Ch]
  unsigned int a2j; // [esp+10h] [ebp-2Ch]
  unsigned int a2k; // [esp+10h] [ebp-2Ch]
  unsigned int a2l; // [esp+10h] [ebp-2Ch]
  unsigned int a2m; // [esp+10h] [ebp-2Ch]
  unsigned int a2n; // [esp+10h] [ebp-2Ch]
  unsigned int a2o; // [esp+10h] [ebp-2Ch]
  unsigned int a2p; // [esp+10h] [ebp-2Ch]
  unsigned int a2q; // [esp+10h] [ebp-2Ch]
  unsigned int a2r; // [esp+10h] [ebp-2Ch]
  unsigned int a2s; // [esp+10h] [ebp-2Ch]
  unsigned int a2t; // [esp+10h] [ebp-2Ch]
  unsigned int a2u; // [esp+10h] [ebp-2Ch]
  unsigned int a2v; // [esp+10h] [ebp-2Ch]
  unsigned int a2w; // [esp+10h] [ebp-2Ch]
  unsigned int a2x; // [esp+10h] [ebp-2Ch]
  unsigned int a2y; // [esp+10h] [ebp-2Ch]
  unsigned int e2; // [esp+14h] [ebp-28h]
  unsigned int e2a; // [esp+14h] [ebp-28h]
  unsigned int e2b; // [esp+14h] [ebp-28h]
  unsigned int e2c; // [esp+14h] [ebp-28h]
  unsigned int e2d; // [esp+14h] [ebp-28h]
  unsigned int e2e; // [esp+14h] [ebp-28h]
  unsigned int e2f; // [esp+14h] [ebp-28h]
  unsigned int e2g; // [esp+14h] [ebp-28h]
  unsigned int e2h; // [esp+14h] [ebp-28h]
  unsigned int e2i; // [esp+14h] [ebp-28h]
  unsigned int e2j; // [esp+14h] [ebp-28h]
  unsigned int e2k; // [esp+14h] [ebp-28h]
  unsigned int e2l; // [esp+14h] [ebp-28h]
  unsigned int e2m; // [esp+14h] [ebp-28h]
  unsigned int e2n; // [esp+14h] [ebp-28h]
  unsigned int e2o; // [esp+14h] [ebp-28h]
  unsigned int e2p; // [esp+14h] [ebp-28h]
  unsigned int e2q; // [esp+14h] [ebp-28h]
  unsigned int e2r; // [esp+14h] [ebp-28h]
  unsigned int e2s; // [esp+14h] [ebp-28h]
  unsigned int e2t; // [esp+14h] [ebp-28h]
  unsigned int e2u; // [esp+14h] [ebp-28h]
  unsigned int e2v; // [esp+14h] [ebp-28h]
  unsigned int e2w; // [esp+14h] [ebp-28h]
  unsigned int e2x; // [esp+14h] [ebp-28h]
  unsigned int e2y; // [esp+14h] [ebp-28h]
  unsigned int e2z; // [esp+14h] [ebp-28h]
  unsigned int d2; // [esp+18h] [ebp-24h]
  unsigned int d2a; // [esp+18h] [ebp-24h]
  unsigned int d2b; // [esp+18h] [ebp-24h]
  unsigned int d2c; // [esp+18h] [ebp-24h]
  unsigned int d2d; // [esp+18h] [ebp-24h]
  unsigned int d2e; // [esp+18h] [ebp-24h]
  unsigned int d2f; // [esp+18h] [ebp-24h]
  unsigned int d2g; // [esp+18h] [ebp-24h]
  unsigned int d2h; // [esp+18h] [ebp-24h]
  unsigned int d2i; // [esp+18h] [ebp-24h]
  unsigned int d2j; // [esp+18h] [ebp-24h]
  unsigned int d2k; // [esp+18h] [ebp-24h]
  unsigned int d2l; // [esp+18h] [ebp-24h]
  unsigned int d2m; // [esp+18h] [ebp-24h]
  unsigned int d2n; // [esp+18h] [ebp-24h]
  unsigned int d2o; // [esp+18h] [ebp-24h]
  unsigned int d2p; // [esp+18h] [ebp-24h]
  unsigned int d2q; // [esp+18h] [ebp-24h]
  unsigned int d2r; // [esp+18h] [ebp-24h]
  unsigned int d2s; // [esp+18h] [ebp-24h]
  unsigned int d2t; // [esp+18h] [ebp-24h]
  unsigned int d2u; // [esp+18h] [ebp-24h]
  unsigned int d2v; // [esp+18h] [ebp-24h]
  unsigned int d2w; // [esp+18h] [ebp-24h]
  unsigned int d2x; // [esp+18h] [ebp-24h]
  unsigned int d2y; // [esp+18h] [ebp-24h]
  unsigned int d2z; // [esp+18h] [ebp-24h]
  unsigned int c2; // [esp+1Ch] [ebp-20h]
  unsigned int c2a; // [esp+1Ch] [ebp-20h]
  unsigned int c2b; // [esp+1Ch] [ebp-20h]
  unsigned int c2c; // [esp+1Ch] [ebp-20h]
  unsigned int c2d; // [esp+1Ch] [ebp-20h]
  unsigned int c2e; // [esp+1Ch] [ebp-20h]
  unsigned int c2f; // [esp+1Ch] [ebp-20h]
  unsigned int c2g; // [esp+1Ch] [ebp-20h]
  unsigned int c2h; // [esp+1Ch] [ebp-20h]
  unsigned int c2i; // [esp+1Ch] [ebp-20h]
  unsigned int c2j; // [esp+1Ch] [ebp-20h]
  unsigned int c2k; // [esp+1Ch] [ebp-20h]
  unsigned int c2l; // [esp+1Ch] [ebp-20h]
  unsigned int c2m; // [esp+1Ch] [ebp-20h]
  unsigned int c2n; // [esp+1Ch] [ebp-20h]
  unsigned int c2o; // [esp+1Ch] [ebp-20h]
  unsigned int c2p; // [esp+1Ch] [ebp-20h]
  unsigned int c2q; // [esp+1Ch] [ebp-20h]
  unsigned int c2r; // [esp+1Ch] [ebp-20h]
  unsigned int c2s; // [esp+1Ch] [ebp-20h]
  unsigned int c2t; // [esp+1Ch] [ebp-20h]
  unsigned int c2u; // [esp+1Ch] [ebp-20h]
  unsigned int c2v; // [esp+1Ch] [ebp-20h]
  unsigned int c2w; // [esp+1Ch] [ebp-20h]
  unsigned int c2x; // [esp+1Ch] [ebp-20h]
  unsigned int c2y; // [esp+1Ch] [ebp-20h]
  unsigned int c2z; // [esp+1Ch] [ebp-20h]
  unsigned int b2; // [esp+20h] [ebp-1Ch]
  unsigned int b2a; // [esp+20h] [ebp-1Ch]
  unsigned int b2b; // [esp+20h] [ebp-1Ch]
  unsigned int b2c; // [esp+20h] [ebp-1Ch]
  unsigned int b2d; // [esp+20h] [ebp-1Ch]
  unsigned int b2e; // [esp+20h] [ebp-1Ch]
  unsigned int b2f; // [esp+20h] [ebp-1Ch]
  unsigned int b2g; // [esp+20h] [ebp-1Ch]
  unsigned int b2h; // [esp+20h] [ebp-1Ch]
  unsigned int b2i; // [esp+20h] [ebp-1Ch]
  unsigned int b2j; // [esp+20h] [ebp-1Ch]
  unsigned int b2k; // [esp+20h] [ebp-1Ch]
  unsigned int b2l; // [esp+20h] [ebp-1Ch]
  unsigned int b2m; // [esp+20h] [ebp-1Ch]
  unsigned int b2n; // [esp+20h] [ebp-1Ch]
  unsigned int b2o; // [esp+20h] [ebp-1Ch]
  unsigned int b2p; // [esp+20h] [ebp-1Ch]
  unsigned int b2q; // [esp+20h] [ebp-1Ch]
  unsigned int b2r; // [esp+20h] [ebp-1Ch]
  unsigned int b2s; // [esp+20h] [ebp-1Ch]
  unsigned int b2t; // [esp+20h] [ebp-1Ch]
  unsigned int b2u; // [esp+20h] [ebp-1Ch]
  unsigned int b2v; // [esp+20h] [ebp-1Ch]
  unsigned int b2w; // [esp+20h] [ebp-1Ch]
  unsigned int b2x; // [esp+20h] [ebp-1Ch]
  unsigned int b2y; // [esp+20h] [ebp-1Ch]
  unsigned int b2z; // [esp+20h] [ebp-1Ch]
  unsigned int b2ba; // [esp+20h] [ebp-1Ch]
  unsigned int b2bb; // [esp+20h] [ebp-1Ch]
  unsigned int b2bc; // [esp+20h] [ebp-1Ch]
  unsigned int b2bd; // [esp+20h] [ebp-1Ch]
  unsigned int b2be; // [esp+20h] [ebp-1Ch]
  unsigned int b2bf; // [esp+20h] [ebp-1Ch]
  unsigned int b2bg; // [esp+20h] [ebp-1Ch]
  unsigned int b2bh; // [esp+20h] [ebp-1Ch]
  unsigned int b2bi; // [esp+20h] [ebp-1Ch]
  unsigned int b2bj; // [esp+20h] [ebp-1Ch]
  unsigned int b2bk; // [esp+20h] [ebp-1Ch]
  unsigned int b2bl; // [esp+20h] [ebp-1Ch]
  unsigned int b2bm; // [esp+20h] [ebp-1Ch]
  unsigned int b2bn; // [esp+20h] [ebp-1Ch]
  unsigned int b2bo; // [esp+20h] [ebp-1Ch]
  unsigned int b2bp; // [esp+20h] [ebp-1Ch]
  unsigned int b2bq; // [esp+20h] [ebp-1Ch]
  unsigned int b2br; // [esp+20h] [ebp-1Ch]
  unsigned int b2bs; // [esp+20h] [ebp-1Ch]
  unsigned int b2bt; // [esp+20h] [ebp-1Ch]
  unsigned int b2bu; // [esp+20h] [ebp-1Ch]
  unsigned int b2bv; // [esp+20h] [ebp-1Ch]
  unsigned int b2bw; // [esp+20h] [ebp-1Ch]
  unsigned int b2bx; // [esp+20h] [ebp-1Ch]
  unsigned int a1; // [esp+24h] [ebp-18h]
  unsigned int a1a; // [esp+24h] [ebp-18h]
  unsigned int a1b; // [esp+24h] [ebp-18h]
  unsigned int a1c; // [esp+24h] [ebp-18h]
  unsigned int a1d; // [esp+24h] [ebp-18h]
  unsigned int a1e; // [esp+24h] [ebp-18h]
  unsigned int a1f; // [esp+24h] [ebp-18h]
  unsigned int a1g; // [esp+24h] [ebp-18h]
  unsigned int a1h; // [esp+24h] [ebp-18h]
  unsigned int a1i; // [esp+24h] [ebp-18h]
  unsigned int a1j; // [esp+24h] [ebp-18h]
  unsigned int a1k; // [esp+24h] [ebp-18h]
  unsigned int a1l; // [esp+24h] [ebp-18h]
  unsigned int a1m; // [esp+24h] [ebp-18h]
  unsigned int a1n; // [esp+24h] [ebp-18h]
  unsigned int a1o; // [esp+24h] [ebp-18h]
  unsigned int a1p; // [esp+24h] [ebp-18h]
  unsigned int a1q; // [esp+24h] [ebp-18h]
  unsigned int a1r; // [esp+24h] [ebp-18h]
  unsigned int a1s; // [esp+24h] [ebp-18h]
  unsigned int a1t; // [esp+24h] [ebp-18h]
  unsigned int a1u; // [esp+24h] [ebp-18h]
  unsigned int a1v; // [esp+24h] [ebp-18h]
  unsigned int a1w; // [esp+24h] [ebp-18h]
  unsigned int a1x; // [esp+24h] [ebp-18h]
  unsigned int e1; // [esp+28h] [ebp-14h]
  unsigned int e1a; // [esp+28h] [ebp-14h]
  unsigned int e1b; // [esp+28h] [ebp-14h]
  unsigned int e1c; // [esp+28h] [ebp-14h]
  unsigned int e1d; // [esp+28h] [ebp-14h]
  unsigned int e1e; // [esp+28h] [ebp-14h]
  unsigned int e1f; // [esp+28h] [ebp-14h]
  unsigned int e1g; // [esp+28h] [ebp-14h]
  unsigned int e1h; // [esp+28h] [ebp-14h]
  unsigned int e1i; // [esp+28h] [ebp-14h]
  unsigned int e1j; // [esp+28h] [ebp-14h]
  unsigned int e1k; // [esp+28h] [ebp-14h]
  unsigned int e1l; // [esp+28h] [ebp-14h]
  unsigned int e1m; // [esp+28h] [ebp-14h]
  unsigned int e1n; // [esp+28h] [ebp-14h]
  unsigned int e1o; // [esp+28h] [ebp-14h]
  unsigned int e1p; // [esp+28h] [ebp-14h]
  unsigned int e1q; // [esp+28h] [ebp-14h]
  unsigned int e1r; // [esp+28h] [ebp-14h]
  unsigned int e1s; // [esp+28h] [ebp-14h]
  unsigned int e1t; // [esp+28h] [ebp-14h]
  unsigned int e1u; // [esp+28h] [ebp-14h]
  unsigned int e1v; // [esp+28h] [ebp-14h]
  unsigned int e1w; // [esp+28h] [ebp-14h]
  unsigned int e1x; // [esp+28h] [ebp-14h]
  unsigned int e1y; // [esp+28h] [ebp-14h]
  unsigned int c1; // [esp+2Ch] [ebp-10h]
  unsigned int c1a; // [esp+2Ch] [ebp-10h]
  unsigned int c1b; // [esp+2Ch] [ebp-10h]
  unsigned int c1c; // [esp+2Ch] [ebp-10h]
  unsigned int c1d; // [esp+2Ch] [ebp-10h]
  unsigned int c1e; // [esp+2Ch] [ebp-10h]
  unsigned int c1f; // [esp+2Ch] [ebp-10h]
  unsigned int c1g; // [esp+2Ch] [ebp-10h]
  unsigned int c1h; // [esp+2Ch] [ebp-10h]
  unsigned int c1i; // [esp+2Ch] [ebp-10h]
  unsigned int c1j; // [esp+2Ch] [ebp-10h]
  unsigned int c1k; // [esp+2Ch] [ebp-10h]
  unsigned int c1l; // [esp+2Ch] [ebp-10h]
  unsigned int c1m; // [esp+2Ch] [ebp-10h]
  unsigned int c1n; // [esp+2Ch] [ebp-10h]
  unsigned int c1o; // [esp+2Ch] [ebp-10h]
  unsigned int c1p; // [esp+2Ch] [ebp-10h]
  unsigned int c1q; // [esp+2Ch] [ebp-10h]
  unsigned int c1r; // [esp+2Ch] [ebp-10h]
  unsigned int c1s; // [esp+2Ch] [ebp-10h]
  unsigned int c1t; // [esp+2Ch] [ebp-10h]
  unsigned int c1u; // [esp+2Ch] [ebp-10h]
  unsigned int c1v; // [esp+2Ch] [ebp-10h]
  unsigned int c1w; // [esp+2Ch] [ebp-10h]
  unsigned int c1x; // [esp+2Ch] [ebp-10h]
  unsigned int c1y; // [esp+2Ch] [ebp-10h]
  unsigned int d1; // [esp+30h] [ebp-Ch]
  unsigned int d1a; // [esp+30h] [ebp-Ch]
  unsigned int d1b; // [esp+30h] [ebp-Ch]
  unsigned int d1c; // [esp+30h] [ebp-Ch]
  unsigned int d1d; // [esp+30h] [ebp-Ch]
  unsigned int d1e; // [esp+30h] [ebp-Ch]
  unsigned int d1f; // [esp+30h] [ebp-Ch]
  unsigned int d1g; // [esp+30h] [ebp-Ch]
  unsigned int d1h; // [esp+30h] [ebp-Ch]
  unsigned int d1i; // [esp+30h] [ebp-Ch]
  unsigned int d1j; // [esp+30h] [ebp-Ch]
  unsigned int d1k; // [esp+30h] [ebp-Ch]
  unsigned int d1l; // [esp+30h] [ebp-Ch]
  unsigned int d1m; // [esp+30h] [ebp-Ch]
  unsigned int d1n; // [esp+30h] [ebp-Ch]
  unsigned int d1o; // [esp+30h] [ebp-Ch]
  unsigned int d1p; // [esp+30h] [ebp-Ch]
  unsigned int d1q; // [esp+30h] [ebp-Ch]
  unsigned int d1r; // [esp+30h] [ebp-Ch]
  unsigned int d1s; // [esp+30h] [ebp-Ch]
  unsigned int d1t; // [esp+30h] [ebp-Ch]
  unsigned int d1u; // [esp+30h] [ebp-Ch]
  unsigned int d1v; // [esp+30h] [ebp-Ch]
  unsigned int d1w; // [esp+30h] [ebp-Ch]
  unsigned int d1x; // [esp+30h] [ebp-Ch]
  unsigned int d1y; // [esp+30h] [ebp-Ch]
  int v394; // [esp+34h] [ebp-8h]
  int v395; // [esp+38h] [ebp-4h]

  v1 = *((_DWORD *)this + 6);
  v2 = *((_DWORD *)this + 12);
  v3 = *((_DWORD *)this + 5);
  v4 = *((_DWORD *)this + 8) + __ROL4__(*((_DWORD *)this + 4) + v2 + (v3 ^ v1 ^ *((_DWORD *)this + 7)), 11);
  c2 = __ROL4__(v1, 10);
  v5 = *((_DWORD *)this + 7) + __ROL4__(*((_DWORD *)this + 8) + *((_DWORD *)this + 13) + (v4 ^ v3 ^ c2), 14);
  v394 = __ROL4__(v3, 10);
  v6 = c2 + __ROL4__(*((_DWORD *)this + 7) + *((_DWORD *)this + 14) + (v4 ^ v394 ^ v5), 15);
  a1 = __ROL4__(v4, 10);
  v7 = v394 + __ROL4__(c2 + *((_DWORD *)this + 15) + (a1 ^ v6 ^ v5), 12);
  v8 = __ROL4__(v5, 10);
  v9 = a1 + __ROL4__(v394 + *((_DWORD *)this + 16) + (v7 ^ v6 ^ v8), 5);
  d1 = __ROL4__(v6, 10);
  v10 = v8 + __ROL4__(a1 + *((_DWORD *)this + 17) + (v9 ^ v7 ^ d1), 8);
  v11 = __ROL4__(v7, 10);
  v12 = d1 + __ROL4__(v8 + *((_DWORD *)this + 18) + (v10 ^ v9 ^ v11), 7);
  b2 = __ROL4__(v9, 10);
  v13 = v11 + __ROL4__(d1 + *((_DWORD *)this + 19) + (v10 ^ b2 ^ v12), 9);
  a1a = __ROL4__(v10, 10);
  v14 = b2 + __ROL4__(v11 + *((_DWORD *)this + 20) + (a1a ^ v13 ^ v12), 11);
  v15 = __ROL4__(v12, 10);
  v16 = a1a + __ROL4__(b2 + *((_DWORD *)this + 21) + (v14 ^ v13 ^ v15), 13);
  d1a = __ROL4__(v13, 10);
  v17 = v15 + __ROL4__(a1a + *((_DWORD *)this + 22) + (v16 ^ v14 ^ d1a), 14);
  c1 = __ROL4__(v14, 10);
  v18 = d1a + __ROL4__(v15 + *((_DWORD *)this + 23) + (v17 ^ v16 ^ c1), 15);
  v19 = __ROL4__(v16, 10);
  v20 = c1 + __ROL4__(d1a + *((_DWORD *)this + 24) + (v17 ^ v19 ^ v18), 6);
  v21 = __ROL4__(v17, 10);
  v22 = v19 + __ROL4__(c1 + *((_DWORD *)this + 25) + (v21 ^ v20 ^ v18), 7);
  e1 = __ROL4__(v18, 10);
  v23 = v21 + __ROL4__(v19 + *((_DWORD *)this + 26) + (v22 ^ v20 ^ e1), 9);
  v24 = __ROL4__(v20, 10);
  v25 = e1 + __ROL4__(v21 + *((_DWORD *)this + 27) + (v23 ^ v22 ^ v24), 8);
  c1a = __ROL4__(v22, 10);
  v26 = v24 + __ROL4__(*((_DWORD *)this + 19) + (c1a ^ v25 & (v23 ^ c1a)) + e1 + 1518500249, 7);
  b2a = __ROL4__(v23, 10);
  v27 = *((_DWORD *)this + 16);
  v28 = c1a + __ROL4__(v27 + (b2a ^ v26 & (v25 ^ b2a)) + v24 + 1518500249, 6);
  a1b = __ROL4__(v25, 10);
  v29 = b2a + __ROL4__(*((_DWORD *)this + 25) + (a1b ^ v28 & (a1b ^ v26)) + c1a + 1518500249, 8);
  e1a = __ROL4__(v26, 10);
  v30 = a1b + __ROL4__(*((_DWORD *)this + 13) + (e1a ^ v29 & (v28 ^ e1a)) + b2a + 1518500249, 13);
  v31 = __ROL4__(v28, 10);
  v32 = v31 ^ v30 & (v29 ^ v31);
  d1b = v31;
  b2b = v30;
  v33 = *((_DWORD *)this + 22);
  v34 = e1a + __ROL4__(v33 + v32 + a1b + 1518500249, 11);
  c1b = __ROL4__(v29, 10);
  v35 = __ROL4__(*((_DWORD *)this + 18) + (c1b ^ v34 & (b2b ^ c1b)) + e1a + 1518500249, 9);
  b2c = __ROL4__(b2b, 10);
  e1b = d1b + v35;
  v36 = __ROL4__(*((_DWORD *)this + 27) + (b2c ^ (d1b + v35) & (v34 ^ b2c)) + d1b + 1518500249, 7);
  d1c = c1b + v36;
  a1c = __ROL4__(v34, 10);
  v37 = b2c + __ROL4__(*((_DWORD *)this + 15) + (a1c ^ (c1b + v36) & (a1c ^ e1b)) + c1b + 1518500249, 15);
  e1c = __ROL4__(e1b, 10);
  v38 = e1c ^ v37 & ((c1b + v36) ^ e1c);
  c1c = v37;
  v39 = *((_DWORD *)this + 24);
  b2d = a1c + __ROL4__(v39 + v38 + b2c + 1518500249, 7);
  d1d = __ROL4__(d1c, 10);
  a1d = e1c + __ROL4__(v2 + (d1d ^ b2d & (c1c ^ d1d)) + a1c + 1518500249, 12);
  c1d = __ROL4__(c1c, 10);
  e1d = d1d + __ROL4__(*((_DWORD *)this + 21) + (c1d ^ a1d & (b2d ^ c1d)) + e1c + 1518500249, 15);
  b2e = __ROL4__(b2d, 10);
  d1e = c1d + __ROL4__(*((_DWORD *)this + 17) + (b2e ^ e1d & (a1d ^ b2e)) + d1d + 1518500249, 9);
  a1e = __ROL4__(a1d, 10);
  c1e = b2e + __ROL4__(*((_DWORD *)this + 14) + (a1e ^ d1e & (a1e ^ e1d)) + c1d + 1518500249, 11);
  e1e = __ROL4__(e1d, 10);
  b2f = a1e + __ROL4__(*((_DWORD *)this + 26) + (e1e ^ c1e & (d1e ^ e1e)) + b2e + 1518500249, 7);
  d1f = __ROL4__(d1e, 10);
  a1f = e1e + __ROL4__(*((_DWORD *)this + 23) + (d1f ^ b2f & (c1e ^ d1f)) + a1e + 1518500249, 13);
  c1f = __ROL4__(c1e, 10);
  v40 = __ROL4__(*((_DWORD *)this + 20) + (c1f ^ a1f & (b2f ^ c1f)) + e1e + 1518500249, 12);
  b2g = __ROL4__(b2f, 10);
  e1f = d1f + v40;
  v41 = __ROL4__(*((_DWORD *)this + 15) + (b2g ^ ((d1f + v40) | ~a1f)) + d1f + 1859775393, 11);
  a1g = __ROL4__(a1f, 10);
  d1g = c1f + v41;
  v42 = __ROL4__(v33 + (a1g ^ ((c1f + v41) | ~e1f)) + c1f + 1859775393, 13);
  e1g = __ROL4__(e1f, 10);
  c1g = b2g + v42;
  v43 = __ROL4__(*((_DWORD *)this + 26) + (e1g ^ ((b2g + v42) | ~d1g)) + b2g + 1859775393, 6);
  d1h = __ROL4__(d1g, 10);
  b2h = a1g + v43;
  v44 = __ROL4__(v27 + (d1h ^ ((a1g + v43) | ~c1g)) + a1g + 1859775393, 7);
  c1h = __ROL4__(c1g, 10);
  a1h = e1g + v44;
  v45 = __ROL4__(*((_DWORD *)this + 21) + (c1h ^ ((e1g + v44) | ~b2h)) + e1g + 1859775393, 14);
  b2i = __ROL4__(b2h, 10);
  e1h = d1h + v45;
  v46 = __ROL4__(*((_DWORD *)this + 27) + (b2i ^ ((d1h + v45) | ~a1h)) + d1h + 1859775393, 9);
  a1i = __ROL4__(a1h, 10);
  d1i = c1h + v46;
  v47 = __ROL4__(*((_DWORD *)this + 20) + (a1i ^ ((c1h + v46) | ~e1h)) + c1h + 1859775393, 13);
  e1i = __ROL4__(e1h, 10);
  c1i = b2i + v47;
  v48 = __ROL4__(*((_DWORD *)this + 13) + (e1i ^ ((b2i + v47) | ~d1i)) + b2i + 1859775393, 15);
  d1j = __ROL4__(d1i, 10);
  b2j = a1i + v48;
  v49 = __ROL4__(*((_DWORD *)this + 14) + (d1j ^ ((a1i + v48) | ~c1i)) + a1i + 1859775393, 14);
  c1j = __ROL4__(c1i, 10);
  a1j = e1i + v49;
  v50 = __ROL4__(*((_DWORD *)this + 19) + (c1j ^ ((e1i + v49) | ~b2j)) + e1i + 1859775393, 8);
  b2k = __ROL4__(b2j, 10);
  e1j = d1j + v50;
  v51 = __ROL4__(v2 + (b2k ^ ((d1j + v50) | ~a1j)) + d1j + 1859775393, 13);
  a1k = __ROL4__(a1j, 10);
  d1k = c1j + v51;
  v52 = __ROL4__(*((_DWORD *)this + 18) + (a1k ^ ((c1j + v51) | ~e1j)) + c1j + 1859775393, 6);
  e1k = __ROL4__(e1j, 10);
  c1k = b2k + v52;
  v53 = __ROL4__(*((_DWORD *)this + 25) + (e1k ^ ((b2k + v52) | ~d1k)) + b2k + 1859775393, 5);
  d1l = __ROL4__(d1k, 10);
  b2l = a1k + v53;
  v54 = __ROL4__(*((_DWORD *)this + 23) + (d1l ^ ((a1k + v53) | ~c1k)) + a1k + 1859775393, 12);
  c1l = __ROL4__(c1k, 10);
  a1l = e1k + v54;
  v55 = __ROL4__(*((_DWORD *)this + 17) + (c1l ^ ((e1k + v54) | ~b2l)) + e1k + 1859775393, 7);
  b2m = __ROL4__(b2l, 10);
  e1l = d1l + v55;
  v56 = __ROL4__(v39 + (b2m ^ ((d1l + v55) | ~a1l)) + d1l + 1859775393, 5);
  a1m = __ROL4__(a1l, 10);
  d1m = c1l + v56;
  v57 = __ROL4__(*((_DWORD *)this + 13) + (e1l ^ a1m & ((c1l + v56) ^ e1l)) + c1l - 1894007588, 11);
  e1m = __ROL4__(e1l, 10);
  c1m = b2m + v57;
  v58 = __ROL4__(*((_DWORD *)this + 21) + (d1m ^ e1m & ((b2m + v57) ^ d1m)) + b2m - 1894007588, 12);
  d1n = __ROL4__(d1m, 10);
  b2n = a1m + v58;
  v59 = __ROL4__(*((_DWORD *)this + 23) + (c1m ^ d1n & ((a1m + v58) ^ c1m)) + a1m - 1894007588, 14);
  c1n = __ROL4__(c1m, 10);
  a1n = e1m + v59;
  v60 = __ROL4__(v33 + (b2n ^ c1n & ((e1m + v59) ^ b2n)) + e1m - 1894007588, 15);
  e1n = d1n + v60;
  b2o = __ROL4__(b2n, 10);
  v61 = __ROL4__(v2 + (a1n ^ b2o & (a1n ^ (d1n + v60))) + d1n - 1894007588, 14);
  a1o = __ROL4__(a1n, 10);
  d1o = c1n + v61;
  v62 = __ROL4__(*((_DWORD *)this + 20) + (e1n ^ a1o & ((c1n + v61) ^ e1n)) + c1n - 1894007588, 15);
  e1o = __ROL4__(e1n, 10);
  c1o = b2o + v62;
  v63 = __ROL4__(v39 + (d1o ^ e1o & ((b2o + v62) ^ d1o)) + b2o - 1894007588, 9);
  b2p = a1o + v63;
  d1p = __ROL4__(d1o, 10);
  v64 = __ROL4__(v27 + (c1o ^ d1p & ((a1o + v63) ^ c1o)) + a1o - 1894007588, 8);
  c1p = __ROL4__(c1o, 10);
  a1p = e1o + v64;
  v65 = __ROL4__(*((_DWORD *)this + 25) + (b2p ^ c1p & ((e1o + v64) ^ b2p)) + e1o - 1894007588, 9);
  e1p = d1p + v65;
  b2q = __ROL4__(b2p, 10);
  v66 = __ROL4__(*((_DWORD *)this + 15) + (a1p ^ b2q & (a1p ^ (d1p + v65))) + d1p - 1894007588, 14);
  a1q = __ROL4__(a1p, 10);
  d1q = c1p + v66;
  v67 = __ROL4__(*((_DWORD *)this + 19) + (e1p ^ a1q & ((c1p + v66) ^ e1p)) + c1p - 1894007588, 5);
  e1q = __ROL4__(e1p, 10);
  c1q = b2q + v67;
  v68 = __ROL4__(*((_DWORD *)this + 27) + (d1q ^ e1q & ((b2q + v67) ^ d1q)) + b2q - 1894007588, 6);
  d1r = __ROL4__(d1q, 10);
  b2r = a1q + v68;
  v69 = __ROL4__(*((_DWORD *)this + 26) + (c1q ^ d1r & ((a1q + v68) ^ c1q)) + a1q - 1894007588, 8);
  c1r = __ROL4__(c1q, 10);
  a1r = e1q + v69;
  v70 = __ROL4__(*((_DWORD *)this + 17) + (b2r ^ c1r & ((e1q + v69) ^ b2r)) + e1q - 1894007588, 6);
  e1r = d1r + v70;
  b2s = __ROL4__(b2r, 10);
  v71 = __ROL4__(*((_DWORD *)this + 18) + (a1r ^ b2s & (a1r ^ (d1r + v70))) + d1r - 1894007588, 5);
  d1s = c1r + v71;
  v72 = __ROL4__(a1r, 10);
  c1s = b2s + __ROL4__(*((_DWORD *)this + 14) + (e1r ^ v72 & ((c1r + v71) ^ e1r)) + c1r - 1894007588, 12);
  e1s = __ROL4__(e1r, 10);
  b2t = v72 + __ROL4__(v27 + (c1s ^ (d1s | ~e1s)) + b2s - 1454113458, 9);
  d1t = __ROL4__(d1s, 10);
  a1s = e1s + __ROL4__(v2 + (b2t ^ (c1s | ~d1t)) + v72 - 1454113458, 15);
  c1t = __ROL4__(c1s, 10);
  e1t = d1t + __ROL4__(*((_DWORD *)this + 17) + (a1s ^ (b2t | ~c1t)) + e1s - 1454113458, 5);
  b2u = __ROL4__(b2t, 10);
  d1u = c1t + __ROL4__(*((_DWORD *)this + 21) + (e1t ^ (a1s | ~b2u)) + d1t - 1454113458, 11);
  a1t = __ROL4__(a1s, 10);
  c1u = b2u + __ROL4__(*((_DWORD *)this + 19) + (d1u ^ (e1t | ~a1t)) + c1t - 1454113458, 6);
  e1u = __ROL4__(e1t, 10);
  b2v = a1t + __ROL4__(v39 + (c1u ^ (d1u | ~e1u)) + b2u - 1454113458, 8);
  d1v = __ROL4__(d1u, 10);
  a1u = e1u + __ROL4__(*((_DWORD *)this + 14) + (b2v ^ (c1u | ~d1v)) + a1t - 1454113458, 13);
  c1v = __ROL4__(c1u, 10);
  e1v = d1v + __ROL4__(v33 + (a1u ^ (b2v | ~c1v)) + e1u - 1454113458, 12);
  b2w = __ROL4__(b2v, 10);
  d1w = c1v + __ROL4__(*((_DWORD *)this + 26) + (e1v ^ (a1u | ~b2w)) + d1v - 1454113458, 5);
  a1v = __ROL4__(a1u, 10);
  c1w = b2w + __ROL4__(*((_DWORD *)this + 13) + (d1w ^ (e1v | ~a1v)) + c1v - 1454113458, 12);
  e1w = __ROL4__(e1v, 10);
  b2x = a1v + __ROL4__(*((_DWORD *)this + 15) + (c1w ^ (d1w | ~e1w)) + b2w - 1454113458, 13);
  d1x = __ROL4__(d1w, 10);
  a1w = e1w + __ROL4__(*((_DWORD *)this + 20) + (b2x ^ (c1w | ~d1x)) + a1v - 1454113458, 14);
  c1x = __ROL4__(c1w, 10);
  e1x = d1x + __ROL4__(*((_DWORD *)this + 23) + (a1w ^ (b2x | ~c1x)) + e1w - 1454113458, 11);
  b2y = __ROL4__(b2x, 10);
  d1y = c1x + __ROL4__(*((_DWORD *)this + 18) + (e1x ^ (a1w | ~b2y)) + d1x - 1454113458, 8);
  a1x = __ROL4__(a1w, 10);
  c1y = b2y + __ROL4__(*((_DWORD *)this + 27) + (d1y ^ (e1x | ~a1x)) + c1x - 1454113458, 5);
  e1y = __ROL4__(e1x, 10);
  v395 = __ROL4__(*((_DWORD *)this + 25) + (c1y ^ (d1y | ~e1y)) + b2y - 1454113458, 6);
  a2 = *((_DWORD *)this + 8)
     + __ROL4__(
         *((_DWORD *)this + 17)
       + (*((_DWORD *)this + 5) ^ (*((_DWORD *)this + 6) | ~*((_DWORD *)this + 7)))
       + *((_DWORD *)this + 4)
       + 1352829926,
         8);
  e2 = *((_DWORD *)this + 7)
     + __ROL4__(*((_DWORD *)this + 26) + (a2 ^ (*((_DWORD *)this + 5) | ~c2)) + *((_DWORD *)this + 8) + 1352829926, 9);
  d2 = c2 + __ROL4__(*((_DWORD *)this + 19) + (e2 ^ (a2 | ~v394)) + *((_DWORD *)this + 7) + 1352829926, 9);
  a2a = __ROL4__(a2, 10);
  c2a = v394 + __ROL4__(v2 + (d2 ^ (e2 | ~a2a)) + c2 + 1352829926, 11);
  e2a = __ROL4__(e2, 10);
  b2z = a2a + __ROL4__(*((_DWORD *)this + 21) + (c2a ^ (d2 | ~e2a)) + v394 + 1352829926, 13);
  d2a = __ROL4__(d2, 10);
  a2b = e2a + __ROL4__(*((_DWORD *)this + 14) + (b2z ^ (c2a | ~d2a)) + a2a + 1352829926, 15);
  c2b = __ROL4__(c2a, 10);
  e2b = d2a + __ROL4__(*((_DWORD *)this + 23) + (a2b ^ (b2z | ~c2b)) + e2a + 1352829926, 15);
  b2ba = __ROL4__(b2z, 10);
  d2b = c2b + __ROL4__(v27 + (e2b ^ (a2b | ~b2ba)) + d2a + 1352829926, 5);
  a2c = __ROL4__(a2b, 10);
  c2c = b2ba + __ROL4__(*((_DWORD *)this + 25) + (d2b ^ (e2b | ~a2c)) + c2b + 1352829926, 7);
  e2c = __ROL4__(e2b, 10);
  b2bb = a2c + __ROL4__(*((_DWORD *)this + 18) + (c2c ^ (d2b | ~e2c)) + b2ba + 1352829926, 7);
  d2c = __ROL4__(d2b, 10);
  a2d = e2c + __ROL4__(*((_DWORD *)this + 27) + (b2bb ^ (c2c | ~d2c)) + a2c + 1352829926, 8);
  c2d = __ROL4__(c2c, 10);
  e2d = d2c + __ROL4__(*((_DWORD *)this + 20) + (a2d ^ (b2bb | ~c2d)) + e2c + 1352829926, 11);
  b2bc = __ROL4__(b2bb, 10);
  d2d = c2d + __ROL4__(*((_DWORD *)this + 13) + (e2d ^ (a2d | ~b2bc)) + d2c + 1352829926, 14);
  a2e = __ROL4__(a2d, 10);
  c2e = b2bc + __ROL4__(v33 + (d2d ^ (e2d | ~a2e)) + c2d + 1352829926, 14);
  e2e = __ROL4__(e2d, 10);
  b2bd = a2e + __ROL4__(*((_DWORD *)this + 15) + (c2e ^ (d2d | ~e2e)) + b2bc + 1352829926, 12);
  d2e = __ROL4__(d2d, 10);
  v73 = __ROL4__(v39 + (b2bd ^ (c2e | ~d2e)) + a2e + 1352829926, 6);
  c2f = __ROL4__(c2e, 10);
  a2f = e2e + v73;
  v74 = __ROL4__(*((_DWORD *)this + 18) + (b2bd ^ c2f & ((e2e + v73) ^ b2bd)) + e2e + 1548603684, 9);
  e2f = d2e + v74;
  b2be = __ROL4__(b2bd, 10);
  v75 = __ROL4__(*((_DWORD *)this + 23) + (a2f ^ b2be & (a2f ^ (d2e + v74))) + d2e + 1548603684, 13);
  a2g = __ROL4__(a2f, 10);
  d2f = c2f + v75;
  v76 = __ROL4__(*((_DWORD *)this + 15) + (e2f ^ a2g & ((c2f + v75) ^ e2f)) + c2f + 1548603684, 15);
  e2g = __ROL4__(e2f, 10);
  c2g = b2be + v76;
  v77 = __ROL4__(*((_DWORD *)this + 19) + (d2f ^ e2g & ((b2be + v76) ^ d2f)) + b2be + 1548603684, 7);
  d2g = __ROL4__(d2f, 10);
  b2bf = a2g + v77;
  v78 = __ROL4__(v2 + (c2g ^ d2g & ((a2g + v77) ^ c2g)) + a2g + 1548603684, 12);
  c2h = __ROL4__(c2g, 10);
  a2h = e2g + v78;
  v79 = __ROL4__(*((_DWORD *)this + 25) + (b2bf ^ c2h & ((e2g + v78) ^ b2bf)) + e2g + 1548603684, 8);
  e2h = d2g + v79;
  b2bg = __ROL4__(b2bf, 10);
  v80 = __ROL4__(*((_DWORD *)this + 17) + (a2h ^ b2bg & (a2h ^ (d2g + v79))) + d2g + 1548603684, 9);
  a2i = __ROL4__(a2h, 10);
  d2h = c2h + v80;
  v81 = __ROL4__(v33 + (e2h ^ a2i & ((c2h + v80) ^ e2h)) + c2h + 1548603684, 11);
  e2i = __ROL4__(e2h, 10);
  c2i = b2bg + v81;
  v82 = __ROL4__(*((_DWORD *)this + 26) + (d2h ^ e2i & ((b2bg + v81) ^ d2h)) + b2bg + 1548603684, 7);
  d2i = __ROL4__(d2h, 10);
  b2bh = a2i + v82;
  v83 = __ROL4__(*((_DWORD *)this + 27) + (c2i ^ d2i & ((a2i + v82) ^ c2i)) + a2i + 1548603684, 7);
  c2j = __ROL4__(c2i, 10);
  a2j = e2i + v83;
  v84 = __ROL4__(*((_DWORD *)this + 20) + (b2bh ^ c2j & ((e2i + v83) ^ b2bh)) + e2i + 1548603684, 12);
  e2j = d2i + v84;
  b2bi = __ROL4__(b2bh, 10);
  v85 = __ROL4__(v39 + (a2j ^ b2bi & (a2j ^ (d2i + v84))) + d2i + 1548603684, 7);
  a2k = __ROL4__(a2j, 10);
  d2j = c2j + v85;
  v86 = __ROL4__(v27 + (e2j ^ a2k & ((c2j + v85) ^ e2j)) + c2j + 1548603684, 6);
  e2k = __ROL4__(e2j, 10);
  c2k = b2bi + v86;
  v87 = __ROL4__(*((_DWORD *)this + 21) + (d2j ^ e2k & ((b2bi + v86) ^ d2j)) + b2bi + 1548603684, 15);
  d2k = __ROL4__(d2j, 10);
  b2bj = a2k + v87;
  v88 = __ROL4__(*((_DWORD *)this + 13) + (c2k ^ d2k & ((a2k + v87) ^ c2k)) + a2k + 1548603684, 13);
  c2l = __ROL4__(c2k, 10);
  a2l = e2k + v88;
  v89 = __ROL4__(*((_DWORD *)this + 14) + (b2bj ^ c2l & ((e2k + v88) ^ b2bj)) + e2k + 1548603684, 11);
  b2bk = __ROL4__(b2bj, 10);
  e2l = d2k + v89;
  v90 = __ROL4__(*((_DWORD *)this + 27) + (b2bk ^ ((d2k + v89) | ~a2l)) + d2k + 1836072691, 9);
  a2m = __ROL4__(a2l, 10);
  d2l = c2l + v90;
  v91 = __ROL4__(*((_DWORD *)this + 17) + (a2m ^ ((c2l + v90) | ~e2l)) + c2l + 1836072691, 7);
  e2m = __ROL4__(e2l, 10);
  c2m = b2bk + v91;
  v92 = __ROL4__(*((_DWORD *)this + 13) + (e2m ^ ((b2bk + v91) | ~d2l)) + b2bk + 1836072691, 15);
  d2m = __ROL4__(d2l, 10);
  b2bl = a2m + v92;
  v93 = __ROL4__(*((_DWORD *)this + 15) + (d2m ^ ((a2m + v92) | ~c2m)) + a2m + 1836072691, 11);
  c2n = __ROL4__(c2m, 10);
  a2n = e2m + v93;
  v94 = __ROL4__(*((_DWORD *)this + 19) + (c2n ^ ((e2m + v93) | ~b2bl)) + e2m + 1836072691, 8);
  b2bm = __ROL4__(b2bl, 10);
  e2n = d2m + v94;
  v95 = __ROL4__(*((_DWORD *)this + 26) + (b2bm ^ ((d2m + v94) | ~a2n)) + d2m + 1836072691, 6);
  a2o = __ROL4__(a2n, 10);
  d2n = c2n + v95;
  v96 = __ROL4__(*((_DWORD *)this + 18) + (a2o ^ ((c2n + v95) | ~e2n)) + c2n + 1836072691, 6);
  e2o = __ROL4__(e2n, 10);
  c2o = b2bm + v96;
  v97 = __ROL4__(*((_DWORD *)this + 21) + (e2o ^ ((b2bm + v96) | ~d2n)) + b2bm + 1836072691, 14);
  d2o = __ROL4__(d2n, 10);
  b2bn = a2o + v97;
  v98 = __ROL4__(*((_DWORD *)this + 23) + (d2o ^ ((a2o + v97) | ~c2o)) + a2o + 1836072691, 12);
  c2p = __ROL4__(c2o, 10);
  a2p = e2o + v98;
  v99 = __ROL4__(*((_DWORD *)this + 20) + (c2p ^ ((e2o + v98) | ~b2bn)) + e2o + 1836072691, 13);
  b2bo = __ROL4__(b2bn, 10);
  e2p = d2o + v99;
  v100 = __ROL4__(v39 + (b2bo ^ ((d2o + v99) | ~a2p)) + d2o + 1836072691, 5);
  a2q = __ROL4__(a2p, 10);
  d2p = c2p + v100;
  v101 = __ROL4__(*((_DWORD *)this + 14) + (a2q ^ ((c2p + v100) | ~e2p)) + c2p + 1836072691, 14);
  e2q = __ROL4__(e2p, 10);
  c2q = b2bo + v101;
  v102 = __ROL4__(v33 + (e2q ^ ((b2bo + v101) | ~d2p)) + b2bo + 1836072691, 13);
  d2q = __ROL4__(d2p, 10);
  b2bp = a2q + v102;
  v103 = __ROL4__(v2 + (d2q ^ ((a2q + v102) | ~c2q)) + a2q + 1836072691, 13);
  c2r = __ROL4__(c2q, 10);
  a2r = e2q + v103;
  v104 = __ROL4__(v27 + (c2r ^ ((e2q + v103) | ~b2bp)) + e2q + 1836072691, 7);
  e2r = d2q + v104;
  v105 = __ROL4__(b2bp, 10);
  d2r = c2r + __ROL4__(*((_DWORD *)this + 25) + (v105 ^ ((d2q + v104) | ~a2r)) + d2q + 1836072691, 5);
  a2s = __ROL4__(a2r, 10);
  c2s = v105 + __ROL4__(*((_DWORD *)this + 20) + (a2s ^ d2r & (a2s ^ e2r)) + c2r + 2053994217, 15);
  e2s = __ROL4__(e2r, 10);
  b2bq = a2s + __ROL4__(*((_DWORD *)this + 18) + (e2s ^ c2s & (d2r ^ e2s)) + v105 + 2053994217, 5);
  d2s = __ROL4__(d2r, 10);
  a2t = e2s + __ROL4__(v27 + (d2s ^ b2bq & (c2s ^ d2s)) + a2s + 2053994217, 8);
  c2t = __ROL4__(c2s, 10);
  e2t = d2s + __ROL4__(*((_DWORD *)this + 13) + (c2t ^ a2t & (b2bq ^ c2t)) + e2s + 2053994217, 11);
  b2br = __ROL4__(b2bq, 10);
  d2t = c2t + __ROL4__(*((_DWORD *)this + 15) + (b2br ^ e2t & (a2t ^ b2br)) + d2s + 2053994217, 14);
  a2u = __ROL4__(a2t, 10);
  c2u = b2br + __ROL4__(*((_DWORD *)this + 23) + (a2u ^ d2t & (a2u ^ e2t)) + c2t + 2053994217, 14);
  e2u = __ROL4__(e2t, 10);
  b2bs = a2u + __ROL4__(*((_DWORD *)this + 27) + (e2u ^ c2u & (d2t ^ e2u)) + b2br + 2053994217, 6);
  d2u = __ROL4__(d2t, 10);
  a2v = e2u + __ROL4__(v2 + (d2u ^ b2bs & (c2u ^ d2u)) + a2u + 2053994217, 14);
  c2v = __ROL4__(c2u, 10);
  e2v = d2u + __ROL4__(*((_DWORD *)this + 17) + (c2v ^ a2v & (b2bs ^ c2v)) + e2u + 2053994217, 6);
  b2bt = __ROL4__(b2bs, 10);
  d2v = c2v + __ROL4__(v39 + (b2bt ^ e2v & (a2v ^ b2bt)) + d2u + 2053994217, 9);
  a2w = __ROL4__(a2v, 10);
  c2w = b2bt + __ROL4__(*((_DWORD *)this + 14) + (a2w ^ d2v & (a2w ^ e2v)) + c2v + 2053994217, 12);
  e2w = __ROL4__(e2v, 10);
  b2bu = a2w + __ROL4__(*((_DWORD *)this + 25) + (e2w ^ c2w & (d2v ^ e2w)) + b2bt + 2053994217, 9);
  d2w = __ROL4__(d2v, 10);
  a2x = e2w + __ROL4__(*((_DWORD *)this + 21) + (d2w ^ b2bu & (c2w ^ d2w)) + a2w + 2053994217, 12);
  c2x = __ROL4__(c2w, 10);
  e2x = d2w + __ROL4__(*((_DWORD *)this + 19) + (c2x ^ a2x & (b2bu ^ c2x)) + e2w + 2053994217, 5);
  b2bv = __ROL4__(b2bu, 10);
  d2x = c2x + __ROL4__(v33 + (b2bv ^ e2x & (a2x ^ b2bv)) + d2w + 2053994217, 15);
  a2y = __ROL4__(a2x, 10);
  c2y = b2bv + __ROL4__(*((_DWORD *)this + 26) + (a2y ^ d2x & (a2y ^ e2x)) + c2x + 2053994217, 8);
  e2y = __ROL4__(e2x, 10);
  v106 = a2y + __ROL4__(b2bv + v39 + (c2y ^ d2x ^ e2y), 8);
  d2y = __ROL4__(d2x, 10);
  v107 = e2y + __ROL4__(a2y + *((_DWORD *)this + 27) + (v106 ^ c2y ^ d2y), 5);
  c2z = __ROL4__(c2y, 10);
  v108 = d2y + __ROL4__(e2y + v33 + (v107 ^ v106 ^ c2z), 12);
  b2bw = __ROL4__(v106, 10);
  v109 = c2z + __ROL4__(d2y + v27 + (v107 ^ b2bw ^ v108), 9);
  v110 = __ROL4__(v107, 10);
  v111 = b2bw + __ROL4__(c2z + *((_DWORD *)this + 13) + (v110 ^ v109 ^ v108), 12);
  v112 = __ROL4__(v108, 10);
  v113 = v110 + __ROL4__(b2bw + *((_DWORD *)this + 17) + (v111 ^ v109 ^ v112), 5);
  v114 = __ROL4__(v109, 10);
  v115 = v112 + __ROL4__(v110 + *((_DWORD *)this + 20) + (v113 ^ v111 ^ v114), 14);
  v116 = __ROL4__(v111, 10);
  v117 = v114 + __ROL4__(v112 + *((_DWORD *)this + 19) + (v115 ^ v113 ^ v116), 6);
  b2bx = __ROL4__(v113, 10);
  v118 = v116 + __ROL4__(v114 + *((_DWORD *)this + 18) + (v115 ^ b2bx ^ v117), 8);
  v119 = __ROL4__(v115, 10);
  v120 = b2bx + __ROL4__(v116 + *((_DWORD *)this + 14) + (v119 ^ v118 ^ v117), 13);
  e2z = __ROL4__(v117, 10);
  v121 = v119 + __ROL4__(b2bx + *((_DWORD *)this + 25) + (v120 ^ v118 ^ e2z), 6);
  d2z = __ROL4__(v118, 10);
  v122 = e2z + __ROL4__(v119 + *((_DWORD *)this + 26) + (v121 ^ v120 ^ d2z), 5);
  v123 = __ROL4__(v120, 10);
  v124 = d2z + __ROL4__(e2z + v2 + (v122 ^ v121 ^ v123), 15);
  v125 = __ROL4__(v121, 10);
  v126 = v123 + __ROL4__(d2z + *((_DWORD *)this + 15) + (v122 ^ v125 ^ v124), 13);
  v127 = __ROL4__(v122, 10);
  v128 = v125 + __ROL4__(v123 + *((_DWORD *)this + 21) + (v127 ^ v126 ^ v124), 11);
  v129 = __ROL4__(v124, 10);
  v130 = __ROL4__(v125 + *((_DWORD *)this + 23) + (v128 ^ v126 ^ v129), 11);
  v131 = *((_DWORD *)this + 5) + __ROL4__(v126, 10) + c1y;
  *((_DWORD *)this + 5) = v129 + *((_DWORD *)this + 6) + __ROL4__(d1y, 10);
  *((_DWORD *)this + 6) = v127 + e1y + *((_DWORD *)this + 7);
  *((_DWORD *)this + 7) = a1x + v127 + v130 + *((_DWORD *)this + 8);
  result = *((_DWORD *)this + 4);
  *((_DWORD *)this + 8) = a1x + v128 + result + v395;
  *((_DWORD *)this + 4) = v131;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004466A0
// Name: private: void TaoCrypt::RIPEMD160::AsmTransform(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge TaoCrypt::RIPEMD160::AsmTransform@<eax>(
        TaoCrypt::RIPEMD160 *this@<ecx>,
        int _EBX@<ebx>,
        int _EDI@<edi>,
        int _ESI@<esi>,
        const LoggingContext_t *data,
        unsigned int times)
{
  int v16; // ebx
  int v17; // edx
  int v18; // ebp
  int v19; // ecx
  int v20; // eax
  int v21; // ebx
  int v22; // ebp
  int v23; // edx
  int v24; // eax
  int v25; // edx
  int v26; // ecx
  int v27; // ebp
  int v28; // ecx
  int v29; // ebx
  int v30; // edx
  int v31; // ebx
  int v32; // eax
  int v33; // ecx
  int v34; // eax
  int v35; // ebp
  int v36; // ebx
  int v37; // ebp
  int v38; // edx
  int v39; // eax
  int v40; // edx
  int v41; // ecx
  int v42; // ebp
  int v43; // ecx
  int v44; // ebx
  int v45; // edx
  int v46; // ebx
  int v47; // eax
  int v48; // ecx
  int v49; // eax
  int v50; // ebp
  int v51; // ebx
  int v52; // ebp
  int v53; // edx
  int v54; // eax
  int v55; // edx
  int v56; // ecx
  int v57; // ebp
  int v58; // ecx
  int v59; // ebx
  int v60; // edx
  int v61; // ebx
  int v62; // eax
  int v63; // ecx
  int v64; // eax
  int v65; // ebp
  int v66; // ebx
  int v67; // ebp
  int v68; // edx
  int v69; // eax
  int v70; // edx
  int v71; // ecx
  int v72; // ebp
  int v73; // ecx
  int v74; // ebx
  int v75; // edx
  int v76; // ebx
  int v77; // eax
  int v78; // ecx
  int v79; // eax
  int v80; // ebp
  int v81; // ebx
  int v82; // ebp
  int v83; // edx
  int v84; // eax
  int v85; // edx
  int v86; // ecx
  int v87; // ebp
  int v88; // ecx
  int v89; // ebx
  int v90; // edx
  int v91; // ebx
  int v92; // eax
  int v93; // ecx
  int v94; // eax
  int v95; // ebp
  int v96; // ebx
  int v97; // ebp
  int v98; // edx
  int v99; // eax
  int v100; // edx
  int v101; // ecx
  int v102; // ebp
  int v103; // ecx
  int v104; // ebx
  int v105; // edx
  int v106; // ebx
  int v107; // eax
  int v108; // ecx
  int v109; // eax
  int v110; // ebp
  int v111; // ebx
  int v112; // ebp
  int v113; // edx
  int v114; // eax
  int v115; // edx
  int v116; // ecx
  int v117; // ebp
  int v118; // ecx
  int v119; // ebx
  int v120; // edx
  int v121; // ebx
  int v122; // eax
  int v123; // ecx
  int v124; // eax
  int v125; // ebp
  int v126; // ebx
  int v127; // ebp
  int v128; // edx
  int v129; // eax
  int v130; // edx
  int v131; // ecx
  int v132; // ebp
  int v133; // ecx
  int v134; // ebx
  int v135; // edx
  int v136; // ebx
  int v137; // eax
  int v138; // ecx
  int v139; // eax
  int v140; // ebp
  int v141; // ebx
  int v142; // ebp
  int v143; // edx
  int v144; // eax
  int v145; // edx
  int v146; // ecx
  int v147; // ebp
  int v148; // ecx
  int v149; // ebx
  int v150; // edx
  int v151; // ebx
  int v152; // eax
  int v153; // ecx
  int v154; // eax
  int v155; // ebp
  int v156; // ebx
  int v157; // ebp
  int v158; // edx
  int v159; // eax
  int v160; // edx
  int v161; // ecx
  int v162; // ebp
  int v163; // ecx
  int v164; // ebx
  int v165; // edx
  int v166; // ebx
  int v167; // eax
  int v168; // ecx
  int v169; // eax
  int v170; // ebp
  int v171; // ebx
  int v172; // ebp
  int v173; // edx
  int v174; // eax
  int v175; // edx
  int v176; // ecx
  int v177; // ebp
  int v178; // ecx
  int v179; // ebx
  int v180; // edx
  int v181; // ebx
  int v182; // eax
  int v183; // ecx
  int v184; // eax
  int v185; // ebp
  int v186; // ebx
  int v187; // ebp
  int v188; // edx
  int v189; // eax
  int v190; // edx
  int v191; // ecx
  int v192; // ebp
  int v193; // ecx
  int v194; // ebx
  int v195; // edx
  int v196; // ebx
  int v197; // eax
  int v198; // ecx
  int v199; // eax
  int v200; // ebp
  int v201; // ebx
  int v202; // ebp
  int v203; // edx
  int v204; // eax
  int v205; // edx
  int v206; // ecx
  int v207; // ebp
  int v208; // ecx
  int v209; // esi
  int v210; // edx
  int v211; // ebx
  int v212; // esi
  int v213; // ecx
  int v214; // eax
  int v215; // esi
  int v216; // ebx
  int v217; // ebp
  int v218; // esi
  int v219; // eax
  int v220; // edx
  int v221; // esi
  int v222; // ebp
  int v223; // ecx
  int v224; // esi
  int v225; // edx
  int v226; // ebx
  int v227; // esi
  int v228; // ecx
  int v229; // eax
  int v230; // esi
  int v231; // ebx
  int v232; // ebp
  int v233; // esi
  int v234; // eax
  int v235; // edx
  int v236; // esi
  int v237; // ebp
  int v238; // ecx
  int v239; // esi
  int v240; // edx
  int v241; // ebx
  int v242; // esi
  int v243; // ecx
  int v244; // eax
  int v245; // esi
  int v246; // ebx
  int v247; // ebp
  int v248; // esi
  int v249; // eax
  int v250; // edx
  int v251; // esi
  int v252; // ebp
  int v253; // ecx
  int v255; // eax
  int v256; // ebx
  int v257; // ecx
  int v258; // edx
  int v259; // ebp
  int v260; // esi
  int v261; // ecx
  int v262; // eax
  int v263; // esi
  int v264; // ebx
  int v265; // ebp
  int v266; // esi
  int v267; // eax
  int v268; // edx
  int v269; // esi
  int v270; // ebp
  int v271; // ecx
  int v272; // esi
  int v273; // edx
  int v274; // ebx
  int v275; // esi
  int v276; // ecx
  int v277; // eax
  int v278; // esi
  int v279; // ebx
  int v280; // ebp
  int v281; // esi
  int v282; // eax
  int v283; // edx
  int v284; // esi
  int v285; // ebp
  int v286; // ecx
  int v287; // esi
  int v288; // edx
  int v289; // ebx
  int v290; // esi
  int v291; // ecx
  int v292; // eax
  int v293; // esi
  int v294; // ebx
  int v295; // ebp
  int v296; // esi
  int v297; // eax
  int v298; // edx
  int v299; // esi
  int v300; // ebp
  int v301; // ecx
  int v302; // esi
  int v303; // edx
  int v304; // ebx
  int v305; // esi
  int v306; // ecx
  int v307; // eax
  int v308; // ebp
  int v309; // ebx
  int v310; // ebp
  int v311; // edx
  int v312; // eax
  int v313; // edx
  int v314; // ecx
  int v315; // ebp
  int v316; // ecx
  int v317; // ebx
  int v318; // edx
  int v319; // ebx
  int v320; // eax
  int v321; // ecx
  int v322; // eax
  int v323; // ebp
  int v324; // ebx
  int v325; // ebp
  int v326; // edx
  int v327; // eax
  int v328; // edx
  int v329; // ecx
  int v330; // ebp
  int v331; // ecx
  int v332; // ebx
  int v333; // edx
  int v334; // ebx
  int v335; // eax
  int v336; // ecx
  int v337; // eax
  int v338; // ebp
  int v339; // ebx
  int v340; // ebp
  int v341; // edx
  int v342; // eax
  int v343; // edx
  int v344; // ecx
  int v345; // ebp
  int v346; // ecx
  int v347; // ebx
  int v348; // edx
  int v349; // ebx
  int v350; // eax
  int v351; // ecx
  int v352; // eax
  int v353; // ebp
  int v354; // ebx
  int v355; // ebp
  int v356; // edx
  int v357; // eax
  int v358; // edx
  int v359; // ecx
  int v360; // ebp
  int v361; // ecx
  int v362; // ebx
  int v363; // edx
  int v364; // ebx
  int v365; // eax
  int v366; // ecx
  int v367; // eax
  int v368; // ebp
  int v369; // ebx
  int v370; // ebp
  int v371; // edx
  int v372; // eax
  int v373; // edx
  int v374; // ecx
  int v375; // ebp
  int v376; // ecx
  int v377; // ebx
  int v378; // edx
  int v379; // ebx
  int v380; // eax
  int v381; // ecx
  int v382; // eax
  int v383; // ebp
  int v384; // ebx
  int v385; // ebp
  int v386; // edx
  int v387; // eax
  int v388; // edx
  int v389; // ecx
  int v390; // ebp
  int v391; // ecx
  int v392; // ebx
  int v393; // edx
  int v394; // ebx
  int v395; // eax
  int v396; // ecx
  int v397; // eax
  int v398; // ebp
  int v399; // ebx
  int v400; // ebp
  int v401; // edx
  int v402; // eax
  int v403; // edx
  int v404; // ecx
  int v405; // ebp
  int v406; // ecx
  int v407; // ebx
  int v408; // edx
  int v409; // ebx
  int v410; // eax
  int v411; // ecx
  int v412; // eax
  int v413; // ebp
  int v414; // ebx
  int v415; // ebp
  int v416; // edx
  int v417; // eax
  int v418; // edx
  int v419; // ecx
  int v420; // ebp
  int v421; // ecx
  int v422; // ebx
  int v423; // edx
  int v424; // ebx
  int v425; // eax
  int v426; // ecx
  int v427; // eax
  int v428; // ebp
  int v429; // ebx
  int v430; // ebp
  int v431; // edx
  int v432; // eax
  int v433; // edx
  int v434; // ecx
  int v435; // ebp
  int v436; // ecx
  int v437; // ebx
  int v438; // edx
  int v439; // ebx
  int v440; // eax
  int v441; // ecx
  int v442; // eax
  int v443; // ebp
  int v444; // ebx
  int v445; // ebp
  int v446; // edx
  int v447; // eax
  int v448; // edx
  int v449; // ecx
  int v450; // ebp
  int v451; // ecx
  int v452; // ebx
  int v453; // edx
  int v454; // ebx
  int v455; // eax
  int v456; // ecx
  int v457; // eax
  int v458; // ebp
  int v459; // ebx
  int v460; // ebp
  int v461; // edx
  int v462; // eax
  int v463; // edx
  int v464; // ecx
  int v465; // ebp
  int v466; // ecx
  int v467; // ebx
  int v468; // edx
  int v469; // ebx
  int v470; // eax
  int v471; // ecx
  int v472; // eax
  int v473; // ebp
  int v474; // ebx
  int v475; // ebp
  int v476; // edx
  int v477; // eax
  int v478; // edx
  int v479; // ecx
  int v480; // ebp
  int v481; // ecx
  int v482; // ebx
  int v483; // edx
  int v484; // ebx
  int v485; // eax
  int v486; // ecx
  int v487; // eax
  int v488; // ebp
  int v489; // ebx
  int v490; // ebp
  int v491; // edx
  int result; // eax
  int v493; // edx
  int v494; // ecx
  int v495; // ebp
  int v496; // ecx
  int v497; // ebx
  int v505; // [esp+0h] [ebp-18h]
  int v506; // [esp+4h] [ebp-14h]
  int v507; // [esp+8h] [ebp-10h]
  int v508; // [esp+8h] [ebp-10h]
  int v509; // [esp+Ch] [ebp-Ch]
  int v510; // [esp+10h] [ebp-8h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  _EBP = &savedregs;
  __asm
  {
    movd    mm3, edi
    movd    mm4, ebx
    movd    mm5, esi
    movd    mm6, ebp
  }
  _EDI = data;
  _EDX = times;
  _ESI = (int *)((char *)this + 16);
  __asm { movd    mm1, esi }
  do
  {
    __asm { movd    mm2, edx }
    v16 = _ESI[1];
    v17 = _ESI[3];
    v18 = _ESI[4];
    v19 = __ROL4__(_ESI[2], 10);
    v20 = v18 + __ROL4__((v17 ^ v16 ^ _ESI[2]) + _EDI->m_ChannelID + *_ESI, 11);
    v21 = __ROL4__(v16, 10);
    v22 = v17 + __ROL4__((v19 ^ v20 ^ _ESI[1]) + _EDI->m_Flags + v18, 14);
    v23 = __ROL4__((v21 ^ v22 ^ v20) + _EDI->m_Severity + v17, 15);
    v24 = __ROL4__(v20, 10);
    v25 = v19 + v23;
    v26 = __ROL4__((v24 ^ v25 ^ v22) + *(_DWORD *)&_EDI->m_Color + v19, 12);
    v27 = __ROL4__(v22, 10);
    v28 = v21 + v26;
    v29 = __ROL4__((v27 ^ v28 ^ v25) + _EDI[1].m_ChannelID + v21, 5);
    v30 = __ROL4__(v25, 10);
    v31 = v24 + v29;
    v32 = __ROL4__((v30 ^ v31 ^ v28) + _EDI[1].m_Flags + v24, 8);
    v33 = __ROL4__(v28, 10);
    v34 = v27 + v32;
    v35 = __ROL4__((v33 ^ v34 ^ v31) + _EDI[1].m_Severity + v27, 7);
    v36 = __ROL4__(v31, 10);
    v37 = v30 + v35;
    v38 = __ROL4__((v36 ^ v37 ^ v34) + *(_DWORD *)&_EDI[1].m_Color + v30, 9);
    v39 = __ROL4__(v34, 10);
    v40 = v33 + v38;
    v41 = __ROL4__((v39 ^ v40 ^ v37) + _EDI[2].m_ChannelID + v33, 11);
    v42 = __ROL4__(v37, 10);
    v43 = v36 + v41;
    v44 = __ROL4__((v42 ^ v43 ^ v40) + _EDI[2].m_Flags + v36, 13);
    v45 = __ROL4__(v40, 10);
    v46 = v39 + v44;
    v47 = __ROL4__((v45 ^ v46 ^ v43) + _EDI[2].m_Severity + v39, 14);
    v48 = __ROL4__(v43, 10);
    v49 = v42 + v47;
    v50 = __ROL4__((v48 ^ v49 ^ v46) + *(_DWORD *)&_EDI[2].m_Color + v42, 15);
    v51 = __ROL4__(v46, 10);
    v52 = v45 + v50;
    v53 = __ROL4__((v51 ^ v52 ^ v49) + _EDI[3].m_ChannelID + v45, 6);
    v54 = __ROL4__(v49, 10);
    v55 = v48 + v53;
    v56 = __ROL4__((v54 ^ v55 ^ v52) + _EDI[3].m_Flags + v48, 7);
    v57 = __ROL4__(v52, 10);
    v58 = v51 + v56;
    v59 = __ROL4__((v57 ^ v58 ^ v55) + _EDI[3].m_Severity + v51, 9);
    v60 = __ROL4__(v55, 10);
    v61 = v54 + v59;
    v62 = __ROL4__((v60 ^ v61 ^ v58) + *(_DWORD *)&_EDI[3].m_Color + v54, 8);
    v63 = __ROL4__(v58, 10);
    v64 = v57 + v62;
    v65 = __ROL4__(v57 + 1518500249 + *(_DWORD *)&_EDI[1].m_Color + (v63 ^ v64 & (v63 ^ v61)), 7);
    v66 = __ROL4__(v61, 10);
    v67 = v60 + v65;
    v68 = __ROL4__((v66 ^ v67 & (v66 ^ v64)) + _EDI[1].m_ChannelID + v60 + 1518500249, 6);
    v69 = __ROL4__(v64, 10);
    v70 = v63 + v68;
    v71 = __ROL4__((v69 ^ v70 & (v69 ^ v67)) + _EDI[3].m_Flags + v63 + 1518500249, 8);
    v72 = __ROL4__(v67, 10);
    v73 = v66 + v71;
    v74 = __ROL4__((v72 ^ v73 & (v72 ^ v70)) + _EDI->m_Flags + v66 + 1518500249, 13);
    v75 = __ROL4__(v70, 10);
    v76 = v69 + v74;
    v77 = __ROL4__((v75 ^ v76 & (v75 ^ v73)) + _EDI[2].m_Severity + v69 + 1518500249, 11);
    v78 = __ROL4__(v73, 10);
    v79 = v72 + v77;
    v80 = __ROL4__(v72 + 1518500249 + _EDI[1].m_Severity + (v78 ^ v79 & (v78 ^ v76)), 9);
    v81 = __ROL4__(v76, 10);
    v82 = v75 + v80;
    v83 = __ROL4__((v81 ^ v82 & (v81 ^ v79)) + *(_DWORD *)&_EDI[3].m_Color + v75 + 1518500249, 7);
    v84 = __ROL4__(v79, 10);
    v85 = v78 + v83;
    v86 = __ROL4__((v84 ^ v85 & (v84 ^ v82)) + *(_DWORD *)&_EDI->m_Color + v78 + 1518500249, 15);
    v87 = __ROL4__(v82, 10);
    v88 = v81 + v86;
    v89 = __ROL4__((v87 ^ v88 & (v87 ^ v85)) + _EDI[3].m_ChannelID + v81 + 1518500249, 7);
    v90 = __ROL4__(v85, 10);
    v91 = v84 + v89;
    v92 = __ROL4__((v90 ^ v91 & (v90 ^ v88)) + _EDI->m_ChannelID + v84 + 1518500249, 12);
    v93 = __ROL4__(v88, 10);
    v94 = v87 + v92;
    v95 = __ROL4__(v87 + 1518500249 + _EDI[2].m_Flags + (v93 ^ v94 & (v93 ^ v91)), 15);
    v96 = __ROL4__(v91, 10);
    v97 = v90 + v95;
    v98 = __ROL4__((v96 ^ v97 & (v96 ^ v94)) + _EDI[1].m_Flags + v90 + 1518500249, 9);
    v99 = __ROL4__(v94, 10);
    v100 = v93 + v98;
    v101 = __ROL4__((v99 ^ v100 & (v99 ^ v97)) + _EDI->m_Severity + v93 + 1518500249, 11);
    v102 = __ROL4__(v97, 10);
    v103 = v96 + v101;
    v104 = __ROL4__((v102 ^ v103 & (v102 ^ v100)) + _EDI[3].m_Severity + v96 + 1518500249, 7);
    v105 = __ROL4__(v100, 10);
    v106 = v99 + v104;
    v107 = __ROL4__((v105 ^ v106 & (v105 ^ v103)) + *(_DWORD *)&_EDI[2].m_Color + v99 + 1518500249, 13);
    v108 = __ROL4__(v103, 10);
    v109 = v102 + v107;
    v110 = __ROL4__(v102 + 1518500249 + _EDI[2].m_ChannelID + (v108 ^ v109 & (v108 ^ v106)), 12);
    v111 = __ROL4__(v106, 10);
    v112 = v105 + v110;
    v113 = __ROL4__((v111 ^ (v112 | ~v109)) + *(_DWORD *)&_EDI->m_Color + v105 + 1859775393, 11);
    v114 = __ROL4__(v109, 10);
    v115 = v108 + v113;
    v116 = __ROL4__((v114 ^ (v115 | ~v112)) + _EDI[2].m_Severity + v108 + 1859775393, 13);
    v117 = __ROL4__(v112, 10);
    v118 = v111 + v116;
    v119 = __ROL4__((v117 ^ (v118 | ~v115)) + _EDI[3].m_Severity + v111 + 1859775393, 6);
    v120 = __ROL4__(v115, 10);
    v121 = v114 + v119;
    v122 = __ROL4__((v120 ^ (v121 | ~v118)) + _EDI[1].m_ChannelID + v114 + 1859775393, 7);
    v123 = __ROL4__(v118, 10);
    v124 = v117 + v122;
    v125 = __ROL4__(v117 + 1859775393 + _EDI[2].m_Flags + (v123 ^ (v124 | ~v121)), 14);
    v126 = __ROL4__(v121, 10);
    v127 = v120 + v125;
    v128 = __ROL4__((v126 ^ (v127 | ~v124)) + *(_DWORD *)&_EDI[3].m_Color + v120 + 1859775393, 9);
    v129 = __ROL4__(v124, 10);
    v130 = v123 + v128;
    v131 = __ROL4__((v129 ^ (v130 | ~v127)) + _EDI[2].m_ChannelID + v123 + 1859775393, 13);
    v132 = __ROL4__(v127, 10);
    v133 = v126 + v131;
    v134 = __ROL4__((v132 ^ (v133 | ~v130)) + _EDI->m_Flags + v126 + 1859775393, 15);
    v135 = __ROL4__(v130, 10);
    v136 = v129 + v134;
    v137 = __ROL4__((v135 ^ (v136 | ~v133)) + _EDI->m_Severity + v129 + 1859775393, 14);
    v138 = __ROL4__(v133, 10);
    v139 = v132 + v137;
    v140 = __ROL4__(v132 + 1859775393 + *(_DWORD *)&_EDI[1].m_Color + (v138 ^ (v139 | ~v136)), 8);
    v141 = __ROL4__(v136, 10);
    v142 = v135 + v140;
    v143 = __ROL4__((v141 ^ (v142 | ~v139)) + _EDI->m_ChannelID + v135 + 1859775393, 13);
    v144 = __ROL4__(v139, 10);
    v145 = v138 + v143;
    v146 = __ROL4__((v144 ^ (v145 | ~v142)) + _EDI[1].m_Severity + v138 + 1859775393, 6);
    v147 = __ROL4__(v142, 10);
    v148 = v141 + v146;
    v149 = __ROL4__((v147 ^ (v148 | ~v145)) + _EDI[3].m_Flags + v141 + 1859775393, 5);
    v150 = __ROL4__(v145, 10);
    v151 = v144 + v149;
    v152 = __ROL4__((v150 ^ (v151 | ~v148)) + *(_DWORD *)&_EDI[2].m_Color + v144 + 1859775393, 12);
    v153 = __ROL4__(v148, 10);
    v154 = v147 + v152;
    v155 = __ROL4__(v147 + 1859775393 + _EDI[1].m_Flags + (v153 ^ (v154 | ~v151)), 7);
    v156 = __ROL4__(v151, 10);
    v157 = v150 + v155;
    v158 = __ROL4__((v156 ^ (v157 | ~v154)) + _EDI[3].m_ChannelID + v150 + 1859775393, 5);
    v159 = __ROL4__(v154, 10);
    v160 = v153 + v158;
    v161 = __ROL4__((v157 ^ v159 & (v160 ^ v157)) + _EDI->m_Flags + v153 - 1894007588, 11);
    v162 = __ROL4__(v157, 10);
    v163 = v156 + v161;
    v164 = __ROL4__((v160 ^ v162 & (v163 ^ v160)) + _EDI[2].m_Flags + v156 - 1894007588, 12);
    v165 = __ROL4__(v160, 10);
    v166 = v159 + v164;
    v167 = __ROL4__((v163 ^ v165 & (v166 ^ v163)) + *(_DWORD *)&_EDI[2].m_Color + v159 - 1894007588, 14);
    v168 = __ROL4__(v163, 10);
    v169 = v162 + v167;
    v170 = __ROL4__(v162 - 1894007588 + _EDI[2].m_Severity + (v166 ^ v168 & (v169 ^ v166)), 15);
    v171 = __ROL4__(v166, 10);
    v172 = v165 + v170;
    v173 = __ROL4__((v169 ^ v171 & (v172 ^ v169)) + _EDI->m_ChannelID + v165 - 1894007588, 14);
    v174 = __ROL4__(v169, 10);
    v175 = v168 + v173;
    v176 = __ROL4__((v172 ^ v174 & (v175 ^ v172)) + _EDI[2].m_ChannelID + v168 - 1894007588, 15);
    v177 = __ROL4__(v172, 10);
    v178 = v171 + v176;
    v179 = __ROL4__((v175 ^ v177 & (v178 ^ v175)) + _EDI[3].m_ChannelID + v171 - 1894007588, 9);
    v180 = __ROL4__(v175, 10);
    v181 = v174 + v179;
    v182 = __ROL4__((v178 ^ v180 & (v181 ^ v178)) + _EDI[1].m_ChannelID + v174 - 1894007588, 8);
    v183 = __ROL4__(v178, 10);
    v184 = v177 + v182;
    v185 = __ROL4__(v177 - 1894007588 + _EDI[3].m_Flags + (v181 ^ v183 & (v184 ^ v181)), 9);
    v186 = __ROL4__(v181, 10);
    v187 = v180 + v185;
    v188 = __ROL4__((v184 ^ v186 & (v187 ^ v184)) + *(_DWORD *)&_EDI->m_Color + v180 - 1894007588, 14);
    v189 = __ROL4__(v184, 10);
    v190 = v183 + v188;
    v191 = __ROL4__((v187 ^ v189 & (v190 ^ v187)) + *(_DWORD *)&_EDI[1].m_Color + v183 - 1894007588, 5);
    v192 = __ROL4__(v187, 10);
    v193 = v186 + v191;
    v194 = __ROL4__((v190 ^ v192 & (v193 ^ v190)) + *(_DWORD *)&_EDI[3].m_Color + v186 - 1894007588, 6);
    v195 = __ROL4__(v190, 10);
    v196 = v189 + v194;
    v197 = __ROL4__((v193 ^ v195 & (v196 ^ v193)) + _EDI[3].m_Severity + v189 - 1894007588, 8);
    v198 = __ROL4__(v193, 10);
    v199 = v192 + v197;
    v200 = __ROL4__(v192 - 1894007588 + _EDI[1].m_Flags + (v196 ^ v198 & (v199 ^ v196)), 6);
    v201 = __ROL4__(v196, 10);
    v202 = v195 + v200;
    v203 = __ROL4__((v199 ^ v201 & (v202 ^ v199)) + _EDI[1].m_Severity + v195 - 1894007588, 5);
    v204 = __ROL4__(v199, 10);
    v205 = v198 + v203;
    v206 = __ROL4__((v202 ^ v204 & (v205 ^ v202)) + _EDI->m_Severity + v198 - 1894007588, 12);
    v207 = __ROL4__(v202, 10);
    v208 = v201 + v206;
    v209 = v208 ^ (v205 | ~v207);
    v210 = __ROL4__(v205, 10);
    v211 = v204 + __ROL4__(v209 + _EDI[1].m_ChannelID + v201 - 1454113458, 9);
    v212 = v211 ^ (v208 | ~v210);
    v213 = __ROL4__(v208, 10);
    v214 = v207 + __ROL4__(v212 + _EDI->m_ChannelID + v204 - 1454113458, 15);
    v215 = v214 ^ (v211 | ~v213);
    v216 = __ROL4__(v211, 10);
    v217 = v210 + __ROL4__(v207 - 1454113458 + _EDI[1].m_Flags + v215, 5);
    v218 = v217 ^ (v214 | ~v216);
    v219 = __ROL4__(v214, 10);
    v220 = v213 + __ROL4__(v218 + _EDI[2].m_Flags + v210 - 1454113458, 11);
    v221 = v220 ^ (v217 | ~v219);
    v222 = __ROL4__(v217, 10);
    v223 = v216 + __ROL4__(v221 + *(_DWORD *)&_EDI[1].m_Color + v213 - 1454113458, 6);
    v224 = v223 ^ (v220 | ~v222);
    v225 = __ROL4__(v220, 10);
    v226 = v219 + __ROL4__(v224 + _EDI[3].m_ChannelID + v216 - 1454113458, 8);
    v227 = v226 ^ (v223 | ~v225);
    v228 = __ROL4__(v223, 10);
    v229 = v222 + __ROL4__(v227 + _EDI->m_Severity + v219 - 1454113458, 13);
    v230 = v229 ^ (v226 | ~v228);
    v231 = __ROL4__(v226, 10);
    v232 = v225 + __ROL4__(v222 - 1454113458 + _EDI[2].m_Severity + v230, 12);
    v233 = v232 ^ (v229 | ~v231);
    v234 = __ROL4__(v229, 10);
    v235 = v228 + __ROL4__(v233 + _EDI[3].m_Severity + v225 - 1454113458, 5);
    v236 = v235 ^ (v232 | ~v234);
    v237 = __ROL4__(v232, 10);
    v238 = v231 + __ROL4__(v236 + _EDI->m_Flags + v228 - 1454113458, 12);
    v239 = v238 ^ (v235 | ~v237);
    v240 = __ROL4__(v235, 10);
    v241 = v234 + __ROL4__(v239 + *(_DWORD *)&_EDI->m_Color + v231 - 1454113458, 13);
    v242 = v241 ^ (v238 | ~v240);
    v243 = __ROL4__(v238, 10);
    v244 = v237 + __ROL4__(v242 + _EDI[2].m_ChannelID + v234 - 1454113458, 14);
    v245 = v244 ^ (v241 | ~v243);
    v246 = __ROL4__(v241, 10);
    v247 = v240 + __ROL4__(v237 - 1454113458 + *(_DWORD *)&_EDI[2].m_Color + v245, 11);
    v248 = v247 ^ (v244 | ~v246);
    v249 = __ROL4__(v244, 10);
    v250 = v243 + __ROL4__(v248 + _EDI[1].m_Severity + v240 - 1454113458, 8);
    v251 = v250 ^ (v247 | ~v249);
    v252 = __ROL4__(v247, 10);
    v253 = v246 + __ROL4__(v251 + *(_DWORD *)&_EDI[3].m_Color + v243 - 1454113458, 5);
    __asm { movd    esi, mm1 }
    v505 = v249;
    v506 = v249 + __ROL4__((v253 ^ (v250 | ~v252)) + _EDI[3].m_Flags + v246 - 1454113458, 6);
    v507 = v253;
    v509 = __ROL4__(v250, 10);
    v510 = v252;
    v255 = *_ESI;
    v256 = _ESI[1];
    v257 = _ESI[2];
    v258 = _ESI[3];
    v259 = _ESI[4];
    v260 = v256 ^ (v257 | ~v258);
    v261 = __ROL4__(v257, 10);
    v262 = v259 + __ROL4__(v260 + _EDI[1].m_Flags + v255 + 1352829926, 8);
    v263 = v262 ^ (v256 | ~v261);
    v264 = __ROL4__(v256, 10);
    v265 = v258 + __ROL4__(v259 + 1352829926 + _EDI[3].m_Severity + v263, 9);
    v266 = v265 ^ (v262 | ~v264);
    v267 = __ROL4__(v262, 10);
    v268 = v261 + __ROL4__(v266 + *(_DWORD *)&_EDI[1].m_Color + v258 + 1352829926, 9);
    v269 = v268 ^ (v265 | ~v267);
    v270 = __ROL4__(v265, 10);
    v271 = v264 + __ROL4__(v269 + _EDI->m_ChannelID + v261 + 1352829926, 11);
    v272 = v271 ^ (v268 | ~v270);
    v273 = __ROL4__(v268, 10);
    v274 = v267 + __ROL4__(v272 + _EDI[2].m_Flags + v264 + 1352829926, 13);
    v275 = v274 ^ (v271 | ~v273);
    v276 = __ROL4__(v271, 10);
    v277 = v270 + __ROL4__(v275 + _EDI->m_Severity + v267 + 1352829926, 15);
    v278 = v277 ^ (v274 | ~v276);
    v279 = __ROL4__(v274, 10);
    v280 = v273 + __ROL4__(v270 + 1352829926 + *(_DWORD *)&_EDI[2].m_Color + v278, 15);
    v281 = v280 ^ (v277 | ~v279);
    v282 = __ROL4__(v277, 10);
    v283 = v276 + __ROL4__(v281 + _EDI[1].m_ChannelID + v273 + 1352829926, 5);
    v284 = v283 ^ (v280 | ~v282);
    v285 = __ROL4__(v280, 10);
    v286 = v279 + __ROL4__(v284 + _EDI[3].m_Flags + v276 + 1352829926, 7);
    v287 = v286 ^ (v283 | ~v285);
    v288 = __ROL4__(v283, 10);
    v289 = v282 + __ROL4__(v287 + _EDI[1].m_Severity + v279 + 1352829926, 7);
    v290 = v289 ^ (v286 | ~v288);
    v291 = __ROL4__(v286, 10);
    v292 = v285 + __ROL4__(v290 + *(_DWORD *)&_EDI[3].m_Color + v282 + 1352829926, 8);
    v293 = v292 ^ (v289 | ~v291);
    v294 = __ROL4__(v289, 10);
    v295 = v288 + __ROL4__(v285 + 1352829926 + _EDI[2].m_ChannelID + v293, 11);
    v296 = v295 ^ (v292 | ~v294);
    v297 = __ROL4__(v292, 10);
    v298 = v291 + __ROL4__(v296 + _EDI->m_Flags + v288 + 1352829926, 14);
    v299 = v298 ^ (v295 | ~v297);
    v300 = __ROL4__(v295, 10);
    v301 = v294 + __ROL4__(v299 + _EDI[2].m_Severity + v291 + 1352829926, 14);
    v302 = v301 ^ (v298 | ~v300);
    v303 = __ROL4__(v298, 10);
    v304 = v297 + __ROL4__(v302 + *(_DWORD *)&_EDI->m_Color + v294 + 1352829926, 12);
    v305 = v304 ^ (v301 | ~v303);
    v306 = __ROL4__(v301, 10);
    v307 = v300 + __ROL4__(v305 + _EDI[3].m_ChannelID + v297 + 1352829926, 6);
    v308 = __ROL4__(v300 + 1548603684 + _EDI[1].m_Severity + (v304 ^ v306 & (v307 ^ v304)), 9);
    v309 = __ROL4__(v304, 10);
    v310 = v303 + v308;
    v311 = __ROL4__((v307 ^ v309 & (v310 ^ v307)) + *(_DWORD *)&_EDI[2].m_Color + v303 + 1548603684, 13);
    v312 = __ROL4__(v307, 10);
    v313 = v306 + v311;
    v314 = __ROL4__((v310 ^ v312 & (v313 ^ v310)) + *(_DWORD *)&_EDI->m_Color + v306 + 1548603684, 15);
    v315 = __ROL4__(v310, 10);
    v316 = v309 + v314;
    v317 = __ROL4__((v313 ^ v315 & (v316 ^ v313)) + *(_DWORD *)&_EDI[1].m_Color + v309 + 1548603684, 7);
    v318 = __ROL4__(v313, 10);
    v319 = v312 + v317;
    v320 = __ROL4__((v316 ^ v318 & (v319 ^ v316)) + _EDI->m_ChannelID + v312 + 1548603684, 12);
    v321 = __ROL4__(v316, 10);
    v322 = v315 + v320;
    v323 = __ROL4__(v315 + 1548603684 + _EDI[3].m_Flags + (v319 ^ v321 & (v322 ^ v319)), 8);
    v324 = __ROL4__(v319, 10);
    v325 = v318 + v323;
    v326 = __ROL4__((v322 ^ v324 & (v325 ^ v322)) + _EDI[1].m_Flags + v318 + 1548603684, 9);
    v327 = __ROL4__(v322, 10);
    v328 = v321 + v326;
    v329 = __ROL4__((v325 ^ v327 & (v328 ^ v325)) + _EDI[2].m_Severity + v321 + 1548603684, 11);
    v330 = __ROL4__(v325, 10);
    v331 = v324 + v329;
    v332 = __ROL4__((v328 ^ v330 & (v331 ^ v328)) + _EDI[3].m_Severity + v324 + 1548603684, 7);
    v333 = __ROL4__(v328, 10);
    v334 = v327 + v332;
    v335 = __ROL4__((v331 ^ v333 & (v334 ^ v331)) + *(_DWORD *)&_EDI[3].m_Color + v327 + 1548603684, 7);
    v336 = __ROL4__(v331, 10);
    v337 = v330 + v335;
    v338 = __ROL4__(v330 + 1548603684 + _EDI[2].m_ChannelID + (v334 ^ v336 & (v337 ^ v334)), 12);
    v339 = __ROL4__(v334, 10);
    v340 = v333 + v338;
    v341 = __ROL4__((v337 ^ v339 & (v340 ^ v337)) + _EDI[3].m_ChannelID + v333 + 1548603684, 7);
    v342 = __ROL4__(v337, 10);
    v343 = v336 + v341;
    v344 = __ROL4__((v340 ^ v342 & (v343 ^ v340)) + _EDI[1].m_ChannelID + v336 + 1548603684, 6);
    v345 = __ROL4__(v340, 10);
    v346 = v339 + v344;
    v347 = __ROL4__((v343 ^ v345 & (v346 ^ v343)) + _EDI[2].m_Flags + v339 + 1548603684, 15);
    v348 = __ROL4__(v343, 10);
    v349 = v342 + v347;
    v350 = __ROL4__((v346 ^ v348 & (v349 ^ v346)) + _EDI->m_Flags + v342 + 1548603684, 13);
    v351 = __ROL4__(v346, 10);
    v352 = v345 + v350;
    v353 = __ROL4__(v345 + 1548603684 + _EDI->m_Severity + (v349 ^ v351 & (v352 ^ v349)), 11);
    v354 = __ROL4__(v349, 10);
    v355 = v348 + v353;
    v356 = __ROL4__((v354 ^ (v355 | ~v352)) + *(_DWORD *)&_EDI[3].m_Color + v348 + 1836072691, 9);
    v357 = __ROL4__(v352, 10);
    v358 = v351 + v356;
    v359 = __ROL4__((v357 ^ (v358 | ~v355)) + _EDI[1].m_Flags + v351 + 1836072691, 7);
    v360 = __ROL4__(v355, 10);
    v361 = v354 + v359;
    v362 = __ROL4__((v360 ^ (v361 | ~v358)) + _EDI->m_Flags + v354 + 1836072691, 15);
    v363 = __ROL4__(v358, 10);
    v364 = v357 + v362;
    v365 = __ROL4__((v363 ^ (v364 | ~v361)) + *(_DWORD *)&_EDI->m_Color + v357 + 1836072691, 11);
    v366 = __ROL4__(v361, 10);
    v367 = v360 + v365;
    v368 = __ROL4__(v360 + 1836072691 + *(_DWORD *)&_EDI[1].m_Color + (v366 ^ (v367 | ~v364)), 8);
    v369 = __ROL4__(v364, 10);
    v370 = v363 + v368;
    v371 = __ROL4__((v369 ^ (v370 | ~v367)) + _EDI[3].m_Severity + v363 + 1836072691, 6);
    v372 = __ROL4__(v367, 10);
    v373 = v366 + v371;
    v374 = __ROL4__((v372 ^ (v373 | ~v370)) + _EDI[1].m_Severity + v366 + 1836072691, 6);
    v375 = __ROL4__(v370, 10);
    v376 = v369 + v374;
    v377 = __ROL4__((v375 ^ (v376 | ~v373)) + _EDI[2].m_Flags + v369 + 1836072691, 14);
    v378 = __ROL4__(v373, 10);
    v379 = v372 + v377;
    v380 = __ROL4__((v378 ^ (v379 | ~v376)) + *(_DWORD *)&_EDI[2].m_Color + v372 + 1836072691, 12);
    v381 = __ROL4__(v376, 10);
    v382 = v375 + v380;
    v383 = __ROL4__(v375 + 1836072691 + _EDI[2].m_ChannelID + (v381 ^ (v382 | ~v379)), 13);
    v384 = __ROL4__(v379, 10);
    v385 = v378 + v383;
    v386 = __ROL4__((v384 ^ (v385 | ~v382)) + _EDI[3].m_ChannelID + v378 + 1836072691, 5);
    v387 = __ROL4__(v382, 10);
    v388 = v381 + v386;
    v389 = __ROL4__((v387 ^ (v388 | ~v385)) + _EDI->m_Severity + v381 + 1836072691, 14);
    v390 = __ROL4__(v385, 10);
    v391 = v384 + v389;
    v392 = __ROL4__((v390 ^ (v391 | ~v388)) + _EDI[2].m_Severity + v384 + 1836072691, 13);
    v393 = __ROL4__(v388, 10);
    v394 = v387 + v392;
    v395 = __ROL4__((v393 ^ (v394 | ~v391)) + _EDI->m_ChannelID + v387 + 1836072691, 13);
    v396 = __ROL4__(v391, 10);
    v397 = v390 + v395;
    v398 = __ROL4__(v390 + 1836072691 + _EDI[1].m_ChannelID + (v396 ^ (v397 | ~v394)), 7);
    v399 = __ROL4__(v394, 10);
    v400 = v393 + v398;
    v401 = __ROL4__((v399 ^ (v400 | ~v397)) + _EDI[3].m_Flags + v393 + 1836072691, 5);
    v402 = __ROL4__(v397, 10);
    v403 = v396 + v401;
    v404 = __ROL4__((v402 ^ v403 & (v402 ^ v400)) + _EDI[2].m_ChannelID + v396 + 2053994217, 15);
    v405 = __ROL4__(v400, 10);
    v406 = v399 + v404;
    v407 = __ROL4__((v405 ^ v406 & (v405 ^ v403)) + _EDI[1].m_Severity + v399 + 2053994217, 5);
    v408 = __ROL4__(v403, 10);
    v409 = v402 + v407;
    v410 = __ROL4__((v408 ^ v409 & (v408 ^ v406)) + _EDI[1].m_ChannelID + v402 + 2053994217, 8);
    v411 = __ROL4__(v406, 10);
    v412 = v405 + v410;
    v413 = __ROL4__(v405 + 2053994217 + _EDI->m_Flags + (v411 ^ v412 & (v411 ^ v409)), 11);
    v414 = __ROL4__(v409, 10);
    v415 = v408 + v413;
    v416 = __ROL4__((v414 ^ v415 & (v414 ^ v412)) + *(_DWORD *)&_EDI->m_Color + v408 + 2053994217, 14);
    v417 = __ROL4__(v412, 10);
    v418 = v411 + v416;
    v419 = __ROL4__((v417 ^ v418 & (v417 ^ v415)) + *(_DWORD *)&_EDI[2].m_Color + v411 + 2053994217, 14);
    v420 = __ROL4__(v415, 10);
    v421 = v414 + v419;
    v422 = __ROL4__((v420 ^ v421 & (v420 ^ v418)) + *(_DWORD *)&_EDI[3].m_Color + v414 + 2053994217, 6);
    v423 = __ROL4__(v418, 10);
    v424 = v417 + v422;
    v425 = __ROL4__((v423 ^ v424 & (v423 ^ v421)) + _EDI->m_ChannelID + v417 + 2053994217, 14);
    v426 = __ROL4__(v421, 10);
    v427 = v420 + v425;
    v428 = __ROL4__(v420 + 2053994217 + _EDI[1].m_Flags + (v426 ^ v427 & (v426 ^ v424)), 6);
    v429 = __ROL4__(v424, 10);
    v430 = v423 + v428;
    v431 = __ROL4__((v429 ^ v430 & (v429 ^ v427)) + _EDI[3].m_ChannelID + v423 + 2053994217, 9);
    v432 = __ROL4__(v427, 10);
    v433 = v426 + v431;
    v434 = __ROL4__((v432 ^ v433 & (v432 ^ v430)) + _EDI->m_Severity + v426 + 2053994217, 12);
    v435 = __ROL4__(v430, 10);
    v436 = v429 + v434;
    v437 = __ROL4__((v435 ^ v436 & (v435 ^ v433)) + _EDI[3].m_Flags + v429 + 2053994217, 9);
    v438 = __ROL4__(v433, 10);
    v439 = v432 + v437;
    v440 = __ROL4__((v438 ^ v439 & (v438 ^ v436)) + _EDI[2].m_Flags + v432 + 2053994217, 12);
    v441 = __ROL4__(v436, 10);
    v442 = v435 + v440;
    v443 = __ROL4__(v435 + 2053994217 + *(_DWORD *)&_EDI[1].m_Color + (v441 ^ v442 & (v441 ^ v439)), 5);
    v444 = __ROL4__(v439, 10);
    v445 = v438 + v443;
    v446 = __ROL4__((v444 ^ v445 & (v444 ^ v442)) + _EDI[2].m_Severity + v438 + 2053994217, 15);
    v447 = __ROL4__(v442, 10);
    v448 = v441 + v446;
    v449 = __ROL4__((v447 ^ v448 & (v447 ^ v445)) + _EDI[3].m_Severity + v441 + 2053994217, 8);
    v450 = __ROL4__(v445, 10);
    v451 = v444 + v449;
    v452 = __ROL4__((v450 ^ v451 ^ v448) + _EDI[3].m_ChannelID + v444, 8);
    v453 = __ROL4__(v448, 10);
    v454 = v447 + v452;
    v455 = __ROL4__((v453 ^ v454 ^ v451) + *(_DWORD *)&_EDI[3].m_Color + v447, 5);
    v456 = __ROL4__(v451, 10);
    v457 = v450 + v455;
    v458 = __ROL4__((v456 ^ v457 ^ v454) + _EDI[2].m_Severity + v450, 12);
    v459 = __ROL4__(v454, 10);
    v460 = v453 + v458;
    v461 = __ROL4__((v459 ^ v460 ^ v457) + _EDI[1].m_ChannelID + v453, 9);
    v462 = __ROL4__(v457, 10);
    v463 = v456 + v461;
    v464 = __ROL4__((v462 ^ v463 ^ v460) + _EDI->m_Flags + v456, 12);
    v465 = __ROL4__(v460, 10);
    v466 = v459 + v464;
    v467 = __ROL4__((v465 ^ v466 ^ v463) + _EDI[1].m_Flags + v459, 5);
    v468 = __ROL4__(v463, 10);
    v469 = v462 + v467;
    v470 = __ROL4__((v468 ^ v469 ^ v466) + _EDI[2].m_ChannelID + v462, 14);
    v471 = __ROL4__(v466, 10);
    v472 = v465 + v470;
    v473 = __ROL4__((v471 ^ v472 ^ v469) + *(_DWORD *)&_EDI[1].m_Color + v465, 6);
    v474 = __ROL4__(v469, 10);
    v475 = v468 + v473;
    v476 = __ROL4__((v474 ^ v475 ^ v472) + _EDI[1].m_Severity + v468, 8);
    v477 = __ROL4__(v472, 10);
    v478 = v471 + v476;
    v479 = __ROL4__((v477 ^ v478 ^ v475) + _EDI->m_Severity + v471, 13);
    v480 = __ROL4__(v475, 10);
    v481 = v474 + v479;
    v482 = __ROL4__((v480 ^ v481 ^ v478) + _EDI[3].m_Flags + v474, 6);
    v483 = __ROL4__(v478, 10);
    v484 = v477 + v482;
    v485 = __ROL4__((v483 ^ v484 ^ v481) + _EDI[3].m_Severity + v477, 5);
    v486 = __ROL4__(v481, 10);
    v487 = v480 + v485;
    v488 = __ROL4__((v486 ^ v487 ^ v484) + _EDI->m_ChannelID + v480, 15);
    v489 = __ROL4__(v484, 10);
    v490 = v483 + v488;
    v491 = __ROL4__((v489 ^ v490 ^ v487) + *(_DWORD *)&_EDI->m_Color + v483, 13);
    result = __ROL4__(v487, 10);
    v493 = v486 + v491;
    v494 = __ROL4__((result ^ v493 ^ v490) + _EDI[2].m_Flags + v486, 11);
    v495 = __ROL4__(v490, 10);
    v496 = v489 + v494;
    v497 = __ROL4__((v495 ^ v496 ^ v493) + *(_DWORD *)&_EDI[2].m_Color + v489, 11);
    _EDI = _EDI + 4;
    __asm
    {
      movd    esi, mm1
      movd    mm0, edi
    }
    v508 = _ESI[1] + __ROL4__(v493, 10) + v507;
    _ESI[1] = v495;
    _ESI[1] += _ESI[2] + v509;
    _ESI[2] = result;
    _ESI[2] += _ESI[3] + v510;
    _ESI[3] = result + v497;
    _ESI[3] += _ESI[4] + v505;
    _ESI[4] = v496;
    _ESI[4] += *_ESI + v506;
    *_ESI = v508;
    __asm
    {
      movd    edx, mm2
      movd    edi, mm0
    }
    _EDX = _EDX - 1;
  }
  while ( _EDX != 0 );
  __asm
  {
    movd    ebp, mm6
    movd    esi, mm5
    movd    ebx, mm4
    movd    edi, mm3
  }
  _m_empty();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004476C0
// Name: public: virtual void TaoCrypt::RIPEMD160::Update(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::RIPEMD160::Update(
        TaoCrypt::HASHwithTransform *this,
        const LoggingContext_t *data,
        unsigned int len)
{
  int v4; // eax
  unsigned int v5; // ebx
  TaoCrypt::HASHwithTransform *v6; // ecx
  unsigned int v7; // edi
  const LoggingContext_t *v8; // ebp
  int v9; // edi
  unsigned int v10; // edi

  if ( TaoCrypt::isMMX )
  {
    v4 = *((_DWORD *)this + 1);
    v5 = len;
    v6 = this + 12;
    if ( v4 != 0 )
    {
      v7 = 64 - v4;
      if ( len < 64 - v4 )
        v7 = len;
      memcpy(dst: (unsigned __int8 *)v6 + v4, src: (unsigned __int8 *)data, count: v7);
      *((_DWORD *)this + 1) += v7;
      v8 = (const LoggingContext_t *)((char *)data + v7);
      v5 = len - v7;
      if ( *((_DWORD *)this + 1) == 64 )
      {
        (*(void (__thiscall **)(TaoCrypt::HASHwithTransform *))(*this + 32))(a1: this);
        TaoCrypt::HASHwithTransform::AddLength(this, a2: 0x40u);
        *((_DWORD *)this + 1) = 0;
      }
    }
    else
    {
      v8 = data;
    }
    if ( *((_DWORD *)this + 1) == 0 )
    {
      v9 = v5 >> 6;
      if ( v5 >> 6 != 0 )
      {
        TaoCrypt::RIPEMD160::AsmTransform(
          (TaoCrypt::RIPEMD160 *)this,
          _EBX: v5,
          _EDI: v9,
          _ESI: (int)this,
          data: v8,
          times: v5 >> 6);
        v10 = v9 << 6;
        TaoCrypt::HASHwithTransform::AddLength(this, a2: v10);
        v5 -= v10;
        v8 = (const LoggingContext_t *)((char *)v8 + v10);
      }
    }
    if ( v5 != 0 )
    {
      memcpy(dst: (unsigned __int8 *)this + *((_DWORD *)this + 1) + 48, src: (unsigned __int8 *)v8, count: v5);
      *((_DWORD *)this + 1) += v5;
    }
  }
  else
  {
    TaoCrypt::HASHwithTransform::Update(this, src: (unsigned __int8 *)data, a3: len);
  }
}
