// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/taocrypt/src/sha.cpp
// Functions: 9
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\taocrypt\src\sha.h"

//------------------------------------------------------------------------------
// Address: 0x004248F0
// Name: public: class yaSSL::SHA __near & yaSSL::SHA::operator=(class yaSSL::SHA const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SHA::operator=(Vector2D *this, int a2)
{
  TaoCrypt::SHA::operator=(result: *(const std::exception **)(a2 + 4));
}

//------------------------------------------------------------------------------
// Address: 0x00425C70
// Name: void yaSSL::ysDelete<struct yaSSL::SHA::SHAImpl>(struct yaSSL::SHA::SHAImpl __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::ysDelete<yaSSL::SHA::SHAImpl>(CUtlEnvelope<char const *> *result)
{
  if ( result != nullptr )
    result->m_string.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)&TaoCrypt::HASH::`vftable';
  operator delete(ptr: (KeyValues *)*(unsigned __int8 *)yaSSL::ys, ptra: result);
}

//------------------------------------------------------------------------------
// Address: 0x00429140
// Name: public: virtual enum TaoCrypt::ByteOrder TaoCrypt::SHA::getByteOrder(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl TaoCrypt::SHA::getByteOrder()
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00442780
// Name: public: TaoCrypt::SHA::SHA(class TaoCrypt::SHA const __near &)
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::SHA *__thiscall TaoCrypt::SHA::SHA(TaoCrypt::SHA *this, const struct TaoCrypt::SHA *a2)
{
  TaoCrypt::HASHwithTransform::HASHwithTransform(
    (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)this,
    digSz: 5);
  this->__vftable = (std::exception_vtbl *)&TaoCrypt::SHA::`vftable';
  this->_Mywhat = a2->_Mywhat;
  *(_DWORD *)&this->_Mydofree = *(_DWORD *)&a2->_Mydofree;
  *(this + 1) = a2[1];
  *(this + 2) = a2[2];
  qmemcpy(this + 4, &a2[4], 0x40u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004427E0
// Name: private: virtual void TaoCrypt::SHA::Transform(void)
// Source: json
//------------------------------------------------------------------------------
std::exception *__thiscall TaoCrypt::SHA::Transform(std::exception *this)
{
  int v1; // edx
  int v2; // esi
  int v3; // edi
  int v4; // eax
  int v5; // edi
  int v6; // edx
  int v7; // esi
  int v8; // ebp
  int v9; // eax
  int v10; // edx
  int v11; // esi
  int v12; // edi
  int v13; // ebx
  int v14; // edx
  int v15; // esi
  int v16; // edi
  int v17; // eax
  int v18; // ebx
  int v19; // edx
  int v20; // esi
  int v21; // edi
  int v22; // eax
  int v23; // ebx
  int v24; // ebp
  int v25; // edx
  int v26; // esi
  int v27; // eax
  unsigned int v28; // edi
  int v29; // edx
  int v30; // edi
  int v31; // ebx
  int v32; // esi
  int v33; // ebx
  int v34; // ebx
  int v35; // ebp
  int v36; // eax
  int v37; // edx
  int v38; // ebx
  CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *v39; // edi
  int v40; // ebx
  int v41; // ebx
  unsigned int v42; // ebp
  int v43; // edi
  int v44; // eax
  int v45; // esi
  int v46; // edx
  char *v47; // ebp
  int v48; // ebp
  unsigned int v49; // ebp
  int v50; // ebp
  unsigned int v51; // ebp
  unsigned int v52; // ebp
  int v53; // edi
  int v54; // ebp
  int v55; // ebp
  int v56; // esi
  int v57; // ebp
  int v58; // ebx
  int v59; // eax
  int v60; // ebx
  int v61; // edx
  int v62; // ebx
  int v63; // ebx
  int v64; // ebx
  int v65; // ebx
  int v66; // edi
  int v67; // edi
  unsigned int v68; // ebp
  int v69; // esi
  int v70; // ebx
  int v71; // eax
  int v72; // esi
  int v73; // esi
  int v74; // eax
  std::exception *result; // eax
  unsigned int ea; // [esp+10h] [ebp-58h]
  unsigned int eb; // [esp+10h] [ebp-58h]
  unsigned int ec; // [esp+10h] [ebp-58h]
  unsigned int ed; // [esp+10h] [ebp-58h]
  unsigned int ee; // [esp+10h] [ebp-58h]
  unsigned int ef; // [esp+10h] [ebp-58h]
  unsigned int eg; // [esp+10h] [ebp-58h]
  unsigned int eh; // [esp+10h] [ebp-58h]
  unsigned int ei; // [esp+10h] [ebp-58h]
  unsigned int ej; // [esp+10h] [ebp-58h]
  unsigned int ek; // [esp+10h] [ebp-58h]
  unsigned int el; // [esp+10h] [ebp-58h]
  unsigned int em; // [esp+10h] [ebp-58h]
  unsigned int en; // [esp+10h] [ebp-58h]
  unsigned int eo; // [esp+10h] [ebp-58h]
  unsigned int ep; // [esp+10h] [ebp-58h]
  unsigned int eq; // [esp+10h] [ebp-58h]
  unsigned int er; // [esp+10h] [ebp-58h]
  unsigned int es; // [esp+10h] [ebp-58h]
  unsigned int et; // [esp+10h] [ebp-58h]
  unsigned int eu; // [esp+10h] [ebp-58h]
  unsigned int ev; // [esp+10h] [ebp-58h]
  unsigned int ew; // [esp+10h] [ebp-58h]
  unsigned int ex; // [esp+10h] [ebp-58h]
  unsigned int ey; // [esp+10h] [ebp-58h]
  unsigned int a; // [esp+14h] [ebp-54h]
  unsigned int aa; // [esp+14h] [ebp-54h]
  unsigned int ab; // [esp+14h] [ebp-54h]
  unsigned int ac; // [esp+14h] [ebp-54h]
  unsigned int ad; // [esp+14h] [ebp-54h]
  unsigned int ae; // [esp+14h] [ebp-54h]
  unsigned int af; // [esp+14h] [ebp-54h]
  unsigned int ag; // [esp+14h] [ebp-54h]
  unsigned int ah; // [esp+14h] [ebp-54h]
  unsigned int ai; // [esp+14h] [ebp-54h]
  unsigned int aj; // [esp+14h] [ebp-54h]
  unsigned int ak; // [esp+14h] [ebp-54h]
  unsigned int al; // [esp+14h] [ebp-54h]
  unsigned int am; // [esp+14h] [ebp-54h]
  unsigned int an; // [esp+14h] [ebp-54h]
  unsigned int ao; // [esp+14h] [ebp-54h]
  unsigned int ap; // [esp+14h] [ebp-54h]
  unsigned int aq; // [esp+14h] [ebp-54h]
  unsigned int ar; // [esp+14h] [ebp-54h]
  unsigned int as; // [esp+14h] [ebp-54h]
  unsigned int at; // [esp+14h] [ebp-54h]
  unsigned int au; // [esp+14h] [ebp-54h]
  unsigned int av; // [esp+14h] [ebp-54h]
  unsigned int aw; // [esp+14h] [ebp-54h]
  unsigned int ax; // [esp+14h] [ebp-54h]
  unsigned int d; // [esp+18h] [ebp-50h]
  unsigned int da; // [esp+18h] [ebp-50h]
  unsigned int db; // [esp+18h] [ebp-50h]
  unsigned int dc; // [esp+18h] [ebp-50h]
  unsigned int dd; // [esp+18h] [ebp-50h]
  unsigned int de; // [esp+18h] [ebp-50h]
  unsigned int df; // [esp+18h] [ebp-50h]
  unsigned int dg; // [esp+18h] [ebp-50h]
  unsigned int dh; // [esp+18h] [ebp-50h]
  unsigned int di; // [esp+18h] [ebp-50h]
  unsigned int dj; // [esp+18h] [ebp-50h]
  unsigned int dk; // [esp+18h] [ebp-50h]
  unsigned int dl; // [esp+18h] [ebp-50h]
  unsigned int dm; // [esp+18h] [ebp-50h]
  unsigned int dn; // [esp+18h] [ebp-50h]
  unsigned int dp; // [esp+18h] [ebp-50h]
  unsigned int dq; // [esp+18h] [ebp-50h]
  unsigned int dr; // [esp+18h] [ebp-50h]
  unsigned int ds; // [esp+18h] [ebp-50h]
  unsigned int dt; // [esp+18h] [ebp-50h]
  unsigned int du; // [esp+18h] [ebp-50h]
  unsigned int dv; // [esp+18h] [ebp-50h]
  unsigned int b; // [esp+1Ch] [ebp-4Ch]
  unsigned int ba; // [esp+1Ch] [ebp-4Ch]
  unsigned int bb; // [esp+1Ch] [ebp-4Ch]
  unsigned int bc; // [esp+1Ch] [ebp-4Ch]
  unsigned int bd; // [esp+1Ch] [ebp-4Ch]
  unsigned int be; // [esp+1Ch] [ebp-4Ch]
  unsigned int bf; // [esp+1Ch] [ebp-4Ch]
  unsigned int bg; // [esp+1Ch] [ebp-4Ch]
  unsigned int bh; // [esp+1Ch] [ebp-4Ch]
  unsigned int bi; // [esp+1Ch] [ebp-4Ch]
  unsigned int bj; // [esp+1Ch] [ebp-4Ch]
  unsigned int bk; // [esp+1Ch] [ebp-4Ch]
  unsigned int bl; // [esp+1Ch] [ebp-4Ch]
  unsigned int bm; // [esp+1Ch] [ebp-4Ch]
  unsigned int bn; // [esp+1Ch] [ebp-4Ch]
  unsigned int bo; // [esp+1Ch] [ebp-4Ch]
  unsigned int bp; // [esp+1Ch] [ebp-4Ch]
  unsigned int bq; // [esp+1Ch] [ebp-4Ch]
  unsigned int br; // [esp+1Ch] [ebp-4Ch]
  unsigned int bs; // [esp+1Ch] [ebp-4Ch]
  unsigned int bt; // [esp+1Ch] [ebp-4Ch]
  unsigned int bu; // [esp+1Ch] [ebp-4Ch]
  unsigned int bv; // [esp+1Ch] [ebp-4Ch]
  unsigned int c; // [esp+20h] [ebp-48h]
  unsigned int ca; // [esp+20h] [ebp-48h]
  unsigned int cb; // [esp+20h] [ebp-48h]
  unsigned int cc; // [esp+20h] [ebp-48h]
  unsigned int cd; // [esp+20h] [ebp-48h]
  unsigned int ce; // [esp+20h] [ebp-48h]
  unsigned int cf; // [esp+20h] [ebp-48h]
  unsigned int cg; // [esp+20h] [ebp-48h]
  unsigned int ch; // [esp+20h] [ebp-48h]
  unsigned int ci; // [esp+20h] [ebp-48h]
  unsigned int cj; // [esp+20h] [ebp-48h]
  unsigned int ck; // [esp+20h] [ebp-48h]
  unsigned int cl; // [esp+20h] [ebp-48h]
  unsigned int cm; // [esp+20h] [ebp-48h]
  unsigned int cn; // [esp+20h] [ebp-48h]
  unsigned int co; // [esp+20h] [ebp-48h]
  unsigned int cp; // [esp+20h] [ebp-48h]
  unsigned int cq; // [esp+20h] [ebp-48h]
  unsigned int cr; // [esp+20h] [ebp-48h]
  unsigned int cs; // [esp+20h] [ebp-48h]
  unsigned int ct; // [esp+20h] [ebp-48h]
  unsigned int cu; // [esp+20h] [ebp-48h]
  CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *W; // [esp+28h] [ebp-40h]
  CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *Wa; // [esp+28h] [ebp-40h]
  CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *Wb; // [esp+28h] [ebp-40h]
  int v196; // [esp+2Ch] [ebp-3Ch]
  int v197; // [esp+2Ch] [ebp-3Ch]
  int v198; // [esp+2Ch] [ebp-3Ch]
  int v199; // [esp+2Ch] [ebp-3Ch]
  int v200; // [esp+30h] [ebp-38h]
  int v201; // [esp+30h] [ebp-38h]
  int v202; // [esp+30h] [ebp-38h]
  int v203; // [esp+30h] [ebp-38h]
  int v204; // [esp+34h] [ebp-34h]
  int v205; // [esp+34h] [ebp-34h]
  int v206; // [esp+34h] [ebp-34h]
  int v207; // [esp+34h] [ebp-34h]
  int v208; // [esp+38h] [ebp-30h]
  int v209; // [esp+38h] [ebp-30h]
  int v210; // [esp+38h] [ebp-30h]
  int v211; // [esp+38h] [ebp-30h]
  int v212; // [esp+3Ch] [ebp-2Ch]
  int v213; // [esp+3Ch] [ebp-2Ch]
  int v214; // [esp+3Ch] [ebp-2Ch]
  int v215; // [esp+3Ch] [ebp-2Ch]
  int v216; // [esp+40h] [ebp-28h]
  int v217; // [esp+40h] [ebp-28h]
  int v218; // [esp+40h] [ebp-28h]
  int v219; // [esp+40h] [ebp-28h]
  int v220; // [esp+44h] [ebp-24h]
  int v221; // [esp+44h] [ebp-24h]
  int v222; // [esp+44h] [ebp-24h]
  int v223; // [esp+44h] [ebp-24h]
  int v224; // [esp+48h] [ebp-20h]
  int v225; // [esp+48h] [ebp-20h]
  int v226; // [esp+48h] [ebp-20h]
  int v227; // [esp+48h] [ebp-20h]
  int v228; // [esp+4Ch] [ebp-1Ch]
  int v229; // [esp+4Ch] [ebp-1Ch]
  int v230; // [esp+4Ch] [ebp-1Ch]
  int v231; // [esp+50h] [ebp-18h]
  int v232; // [esp+50h] [ebp-18h]
  int v233; // [esp+50h] [ebp-18h]
  int v234; // [esp+50h] [ebp-18h]
  int v235; // [esp+54h] [ebp-14h]
  int v236; // [esp+54h] [ebp-14h]
  int v237; // [esp+54h] [ebp-14h]
  int v238; // [esp+54h] [ebp-14h]
  int v239; // [esp+58h] [ebp-10h]
  int v240; // [esp+58h] [ebp-10h]
  int v241; // [esp+5Ch] [ebp-Ch]
  int v242; // [esp+5Ch] [ebp-Ch]
  int v243; // [esp+5Ch] [ebp-Ch]

  v1 = *((_DWORD *)this + 4);
  v2 = *((_DWORD *)this + 6);
  v3 = *((_DWORD *)this + 7);
  ea = *((_DWORD *)this + 12)
     + *((_DWORD *)this + 8)
     + __ROL4__(v1, 5)
     + (v3 ^ *((_DWORD *)this + 5) & (v2 ^ v3))
     + 1518500249;
  v4 = __ROL4__(*((_DWORD *)this + 5), 30);
  v5 = v3 + *((_DWORD *)this + 13) + __ROL4__(ea, 5) + (v2 ^ v1 & (v4 ^ v2)) + 1518500249;
  v6 = __ROL4__(v1, 30);
  v7 = v2 + *((_DWORD *)this + 14) + __ROL4__(v5, 5) + (v4 ^ ea & (v6 ^ v4)) + 1518500249;
  v8 = __ROL4__(ea, 30);
  v9 = v4 + *((_DWORD *)this + 15) + __ROL4__(v7, 5) + (v6 ^ v5 & (v6 ^ v8)) + 1518500249;
  d = __ROL4__(v5, 30);
  v10 = v6 + *((_DWORD *)this + 16) + __ROL4__(v9, 5) + (v8 ^ v7 & (d ^ v8)) + 1518500249;
  v11 = __ROL4__(v7, 30);
  v12 = v8 + *((_DWORD *)this + 17) + __ROL4__(v10, 5) + (d ^ v9 & (v11 ^ d)) + 1518500249;
  b = __ROL4__(v9, 30);
  v13 = d + *((_DWORD *)this + 18) + __ROL4__(v12, 5) + (v11 ^ v10 & (b ^ v11)) + 1518500249;
  v14 = __ROL4__(v10, 30);
  v15 = v11 + *((_DWORD *)this + 19) + __ROL4__(v13, 5) + (b ^ v12 & (v14 ^ b)) + 1518500249;
  v16 = __ROL4__(v12, 30);
  v17 = b + *((_DWORD *)this + 20) + __ROL4__(v15, 5) + (v14 ^ v13 & (v14 ^ v16)) + 1518500249;
  v18 = __ROL4__(v13, 30);
  v19 = v14 + *((_DWORD *)this + 21) + __ROL4__(v17, 5) + (v16 ^ v15 & (v18 ^ v16)) + 1518500249;
  v20 = __ROL4__(v15, 30);
  v21 = v16 + *((_DWORD *)this + 22) + __ROL4__(v19, 5) + (v18 ^ v17 & (v20 ^ v18)) + 1518500249;
  v22 = __ROL4__(v17, 30);
  v23 = v18 + *((_DWORD *)this + 23) + __ROL4__(v21, 5) + (v20 ^ v19 & (v22 ^ v20)) + 1518500249;
  v24 = __ROL4__(v19, 30);
  v25 = v20 + *((_DWORD *)this + 24) + __ROL4__(v23, 5) + (v22 ^ v21 & (v24 ^ v22)) + 1518500249;
  eb = __ROL4__(v21, 30);
  v26 = v22 + *((_DWORD *)this + 25) + __ROL4__(v25, 5) + (v24 ^ v23 & (v24 ^ eb)) + 1518500249;
  v27 = *((_DWORD *)this + 26);
  da = __ROL4__(v23, 30);
  a = v24 + v27 + __ROL4__(v26, 5) + (eb ^ v25 & (da ^ eb)) + 1518500249;
  v28 = __ROL4__(v25, 30);
  v29 = *((_DWORD *)this + 27);
  c = v28;
  v30 = eb + v29 + __ROL4__(a, 5) + (da ^ v26 & (v28 ^ da)) + 1518500249;
  v31 = __ROL4__(v26, 30);
  v32 = __ROL4__(*((_DWORD *)this + 12) ^ *((_DWORD *)this + 14) ^ *((_DWORD *)this + 20) ^ *((_DWORD *)this + 25), 1);
  db = da + v32 + __ROL4__(v30, 5) + (c ^ a & (v31 ^ c)) + 1518500249;
  aa = __ROL4__(a, 30);
  v196 = __ROL4__(*((_DWORD *)this + 13) ^ *((_DWORD *)this + 15) ^ *((_DWORD *)this + 21) ^ v27, 1);
  ca = c + v196 + __ROL4__(db, 5) + (v31 ^ v30 & (aa ^ v31)) + 1518500249;
  ec = __ROL4__(v30, 30);
  v200 = __ROL4__(*((_DWORD *)this + 14) ^ *((_DWORD *)this + 16) ^ *((_DWORD *)this + 22) ^ v29, 1);
  ba = v31 + v200 + __ROL4__(ca, 5) + (aa ^ db & (aa ^ ec)) + 1518500249;
  dc = __ROL4__(db, 30);
  v204 = __ROL4__(v32 ^ *((_DWORD *)this + 15) ^ *((_DWORD *)this + 17) ^ *((_DWORD *)this + 23), 1);
  ab = aa + v204 + __ROL4__(ba, 5) + (ec ^ ca & (dc ^ ec)) + 1518500249;
  cb = __ROL4__(ca, 30);
  v208 = __ROL4__(v196 ^ *((_DWORD *)this + 16) ^ *((_DWORD *)this + 18) ^ *((_DWORD *)this + 24), 1);
  ed = ec + v208 + __ROL4__(ab, 5) + (ba ^ cb ^ dc) + 1859775393;
  bb = __ROL4__(ba, 30);
  v212 = __ROL4__(v200 ^ *((_DWORD *)this + 17) ^ *((_DWORD *)this + 19) ^ *((_DWORD *)this + 25), 1);
  v33 = dc + v212 + __ROL4__(ed, 5) + (ab ^ bb ^ cb) + 1859775393;
  ac = __ROL4__(ab, 30);
  v216 = __ROL4__(v204 ^ *((_DWORD *)this + 18) ^ *((_DWORD *)this + 20) ^ v27, 1);
  cc = cb + v216 + __ROL4__(v33, 5) + (ac ^ bb ^ ed) + 1859775393;
  ee = __ROL4__(ed, 30);
  v220 = __ROL4__(v208 ^ *((_DWORD *)this + 19) ^ *((_DWORD *)this + 21) ^ v29, 1);
  bc = bb + v220 + __ROL4__(cc, 5) + (ac ^ v33 ^ ee) + 1859775393;
  dd = __ROL4__(v33, 30);
  v224 = __ROL4__(v32 ^ v212 ^ *((_DWORD *)this + 20) ^ *((_DWORD *)this + 22), 1);
  ad = ac + v224 + __ROL4__(bc, 5) + (cc ^ dd ^ ee) + 1859775393;
  cd = __ROL4__(cc, 30);
  v228 = __ROL4__(v196 ^ v216 ^ *((_DWORD *)this + 21) ^ *((_DWORD *)this + 23), 1);
  ef = ee + v228 + __ROL4__(ad, 5) + (bc ^ cd ^ dd) + 1859775393;
  bd = __ROL4__(bc, 30);
  v231 = __ROL4__(v200 ^ v220 ^ *((_DWORD *)this + 22) ^ *((_DWORD *)this + 24), 1);
  v34 = dd + v231 + __ROL4__(ef, 5) + (ad ^ bd ^ cd) + 1859775393;
  ae = __ROL4__(ad, 30);
  v235 = __ROL4__(v204 ^ v224 ^ *((_DWORD *)this + 23) ^ *((_DWORD *)this + 25), 1);
  ce = cd + v235 + __ROL4__(v34, 5) + (ae ^ bd ^ ef) + 1859775393;
  eg = __ROL4__(ef, 30);
  v239 = __ROL4__(v208 ^ v228 ^ *((_DWORD *)this + 24) ^ v27, 1);
  v35 = __ROL4__(v34, 30);
  be = bd + v239 + __ROL4__(ce, 5) + (ae ^ v34 ^ eg) + 1859775393;
  v241 = __ROL4__(v212 ^ v231 ^ *((_DWORD *)this + 25) ^ v29, 1);
  af = ae + v241 + __ROL4__(be, 5) + (ce ^ v35 ^ eg) + 1859775393;
  v36 = __ROL4__(v32 ^ v216 ^ v235 ^ v27, 1);
  cf = __ROL4__(ce, 30);
  eh = eg + v36 + __ROL4__(af, 5) + (be ^ cf ^ v35) + 1859775393;
  v37 = __ROL4__(v196 ^ v220 ^ v239 ^ v29, 1);
  bf = __ROL4__(be, 30);
  v38 = v35 + v37 + __ROL4__(eh, 5) + (af ^ bf ^ cf) + 1859775393;
  ag = __ROL4__(af, 30);
  v39 = (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)__ROL4__(v32 ^ v200 ^ v224 ^ v241, 1);
  cg = (unsigned int)&v39[154981282].m_nGrowSize + __ROL4__(v38, 5) + (ag ^ bf ^ eh) + cf + 1;
  ei = __ROL4__(eh, 30);
  v197 = __ROL4__(v196 ^ v204 ^ v228 ^ v36, 1);
  bg = bf + v197 + __ROL4__(cg, 5) + (ag ^ v38 ^ ei) + 1859775393;
  de = __ROL4__(v38, 30);
  W = v39;
  v201 = __ROL4__(v200 ^ v208 ^ v231 ^ v37, 1);
  ah = ag + v201 + __ROL4__(bg, 5) + (cg ^ de ^ ei) + 1859775393;
  ch = __ROL4__(cg, 30);
  v205 = __ROL4__((unsigned int)v39 ^ v204 ^ v212 ^ v235, 1);
  ej = ei + v205 + __ROL4__(ah, 5) + (bg ^ ch ^ de) + 1859775393;
  bh = __ROL4__(bg, 30);
  v209 = __ROL4__(v197 ^ v208 ^ v216 ^ v239, 1);
  v40 = de + v209 + __ROL4__(ej, 5) + (ah ^ bh ^ ch) + 1859775393;
  ai = __ROL4__(ah, 30);
  v213 = __ROL4__(v201 ^ v212 ^ v220 ^ v241, 1);
  ci = ch + v213 + __ROL4__(v40, 5) + (ai ^ bh ^ ej) + 1859775393;
  ek = __ROL4__(ej, 30);
  v217 = __ROL4__(v205 ^ v216 ^ v224 ^ v36, 1);
  bi = bh + v217 + __ROL4__(ci, 5) + (ai ^ v40 ^ ek) + 1859775393;
  df = __ROL4__(v40, 30);
  v221 = __ROL4__(v209 ^ v220 ^ v228 ^ v37, 1);
  aj = ai + v221 + __ROL4__(bi, 5) + (ci ^ df ^ ek) + 1859775393;
  cj = __ROL4__(ci, 30);
  v225 = __ROL4__((unsigned int)v39 ^ v213 ^ v224 ^ v231, 1);
  v41 = ek + v225 + (bi & cj | df & (bi | cj)) + __ROL4__(aj, 5) - 1894007588;
  bj = __ROL4__(bi, 30);
  v229 = __ROL4__(v197 ^ v217 ^ v228 ^ v235, 1);
  dg = __ROL4__(v41, 5) + df + v229 + (aj & bj | cj & (aj | bj)) - 1894007588;
  ak = __ROL4__(aj, 30);
  v232 = __ROL4__(v201 ^ v221 ^ v231 ^ v239, 1);
  el = __ROL4__(v41, 30);
  v236 = __ROL4__(v205 ^ v225 ^ v235 ^ v241, 1);
  ck = __ROL4__(dg, 5) + cj + v232 + (ak & v41 | bj & (ak | v41)) - 1894007588;
  bk = __ROL4__(ck, 5) + bj + v236 + (dg & el | ak & (dg | el)) - 1894007588;
  dh = __ROL4__(dg, 30);
  v240 = __ROL4__(v209 ^ v229 ^ v239 ^ v36, 1);
  v42 = ak + v240 + (ck & dh | el & (ck | dh));
  v242 = __ROL4__(v213 ^ v232 ^ v241 ^ v37, 1);
  cl = __ROL4__(ck, 30);
  al = __ROL4__(bk, 5) + v42 - 1894007588;
  v43 = __ROL4__(al, 5) + el + v242 + (bk & cl | dh & (bk | cl)) - 1894007588;
  bl = __ROL4__(bk, 30);
  v44 = __ROL4__((unsigned int)W ^ v217 ^ v236 ^ v36, 1);
  v45 = __ROL4__(al, 30);
  v46 = __ROL4__(v197 ^ v221 ^ v240 ^ v37, 1);
  di = __ROL4__(v43, 5) + dh + v44 + (al & bl | cl & (al | bl)) - 1894007588;
  cm = __ROL4__(di, 5) + cl + v46 + (v45 & v43 | bl & (v45 | v43)) - 1894007588;
  em = __ROL4__(v43, 30);
  Wa = (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)__ROL4__(
                                                                          (unsigned int)W ^ v201 ^ v225 ^ v242,
                                                                          1);
  v47 = (char *)Wa + (di & em | v45 & (di | em)) + bl;
  dj = __ROL4__(di, 30);
  bm = (unsigned int)&v47[__ROL4__(cm, 5) - 1894007588];
  v198 = __ROL4__(v197 ^ v205 ^ v229 ^ v44, 1);
  v48 = v45 + v198 + (cm & dj | em & (cm | dj));
  cn = __ROL4__(cm, 30);
  am = __ROL4__(bm, 5) + v48 - 1894007588;
  v202 = __ROL4__(v201 ^ v209 ^ v232 ^ v46, 1);
  v49 = em + v202 + (bm & cn | dj & (bm | cn));
  bn = __ROL4__(bm, 30);
  v206 = __ROL4__((unsigned int)Wa ^ v205 ^ v213 ^ v236, 1);
  en = __ROL4__(am, 5) + v49 - 1894007588;
  dk = __ROL4__(en, 5) + dj + v206 + (am & bn | cn & (am | bn)) - 1894007588;
  an = __ROL4__(am, 30);
  v210 = __ROL4__(v198 ^ v209 ^ v217 ^ v240, 1);
  v50 = v210 + (an & en | bn & (an | en));
  eo = __ROL4__(en, 30);
  v214 = __ROL4__(v202 ^ v213 ^ v221 ^ v242, 1);
  co = __ROL4__(dk, 5) + cn + v50 - 1894007588;
  v51 = bn + v214 + (dk & eo | an & (dk | eo));
  dl = __ROL4__(dk, 30);
  bo = __ROL4__(co, 5) + v51 - 1894007588;
  v218 = __ROL4__(v206 ^ v217 ^ v225 ^ v44, 1);
  v52 = an + v218 + (co & dl | eo & (co | dl));
  cp = __ROL4__(co, 30);
  v222 = __ROL4__(v210 ^ v221 ^ v229 ^ v46, 1);
  ao = __ROL4__(bo, 5) + v52 - 1894007588;
  v53 = __ROL4__(bo, 30);
  ep = __ROL4__(ao, 5) + eo + v222 + (bo & cp | dl & (bo | cp)) - 1894007588;
  v226 = __ROL4__((unsigned int)Wa ^ v214 ^ v225 ^ v232, 1);
  dm = __ROL4__(ep, 5) + dl + v226 + (ao & v53 | cp & (ao | v53)) - 1894007588;
  ap = __ROL4__(ao, 30);
  v230 = __ROL4__(v198 ^ v218 ^ v229 ^ v236, 1);
  v54 = v230 + (ap & ep | v53 & (ap | ep));
  eq = __ROL4__(ep, 30);
  v233 = __ROL4__(v202 ^ v222 ^ v232 ^ v240, 1);
  cq = __ROL4__(dm, 5) + cp + v54 - 1894007588;
  v55 = v53 + v233 + (dm & eq | ap & (dm | eq));
  dn = __ROL4__(dm, 30);
  v237 = __ROL4__(v206 ^ v226 ^ v236 ^ v242, 1);
  bp = __ROL4__(cq, 5) + v55 - 1894007588;
  aq = __ROL4__(bp, 5) + ap + v237 + (cq & dn | eq & (cq | dn)) - 1894007588;
  v56 = __ROL4__(v210 ^ v230 ^ v240 ^ v44, 1);
  cr = __ROL4__(cq, 30);
  v57 = __ROL4__(bp, 30);
  er = eq + v56 + (bp ^ cr ^ dn) + __ROL4__(aq, 5) - 899497514;
  v243 = __ROL4__(v214 ^ v233 ^ v242 ^ v46, 1);
  v58 = dn + v243 + (aq ^ v57 ^ cr) + __ROL4__(er, 5) - 899497514;
  ar = __ROL4__(aq, 30);
  v59 = __ROL4__((unsigned int)Wa ^ v218 ^ v237 ^ v44, 1);
  dp = v58;
  v60 = cr + v59 + (ar ^ v57 ^ er) + __ROL4__(v58, 5) - 899497514;
  es = __ROL4__(er, 30);
  v61 = __ROL4__(v198 ^ v222 ^ v56 ^ v46, 1);
  bq = v57 + v61 + (ar ^ dp ^ es) + __ROL4__(v60, 5) - 899497514;
  dq = __ROL4__(dp, 30);
  Wb = (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)__ROL4__(
                                                                          (unsigned int)Wa ^ v202 ^ v226 ^ v243,
                                                                          1);
  as = (unsigned int)&Wb[-74958126] + (v60 ^ dq ^ es) + ar + __ROL4__(bq, 5) - 2;
  cs = __ROL4__(v60, 30);
  v199 = __ROL4__(v198 ^ v206 ^ v230 ^ v59, 1);
  et = es + v199 + (bq ^ cs ^ dq) + __ROL4__(as, 5) - 899497514;
  br = __ROL4__(bq, 30);
  v203 = __ROL4__(v202 ^ v210 ^ v233 ^ v61, 1);
  v62 = dq + v203 + (as ^ br ^ cs) + __ROL4__(et, 5) - 899497514;
  at = __ROL4__(as, 30);
  dr = v62;
  v207 = __ROL4__((unsigned int)Wb ^ v206 ^ v214 ^ v237, 1);
  v63 = cs + v207 + (at ^ br ^ et) + __ROL4__(v62, 5) - 899497514;
  eu = __ROL4__(et, 30);
  v211 = __ROL4__(v199 ^ v210 ^ v218 ^ v56, 1);
  bs = __ROL4__(v63, 5) + br + v211 + (at ^ dr ^ eu) - 899497514;
  ds = __ROL4__(dr, 30);
  v215 = __ROL4__(v203 ^ v214 ^ v222 ^ v243, 1);
  au = at + v215 + (v63 ^ ds ^ eu) + __ROL4__(bs, 5) - 899497514;
  ct = __ROL4__(v63, 30);
  v219 = __ROL4__(v207 ^ v218 ^ v226 ^ v59, 1);
  ev = eu + v219 + (bs ^ ct ^ ds) + __ROL4__(au, 5) - 899497514;
  bt = __ROL4__(bs, 30);
  v223 = __ROL4__(v211 ^ v222 ^ v230 ^ v61, 1);
  v64 = ds + v223 + (au ^ bt ^ ct) + __ROL4__(ev, 5) - 899497514;
  av = __ROL4__(au, 30);
  dt = v64;
  v227 = __ROL4__((unsigned int)Wb ^ v215 ^ v226 ^ v233, 1);
  v65 = ct + v227 + (av ^ bt ^ ev) + __ROL4__(v64, 5) - 899497514;
  ew = __ROL4__(ev, 30);
  v66 = __ROL4__(v199 ^ v219 ^ v230 ^ v237, 1);
  bu = __ROL4__(v65, 5) + bt + v66 + (av ^ dt ^ ew) - 899497514;
  du = __ROL4__(dt, 30);
  v234 = __ROL4__(v203 ^ v223 ^ v233 ^ v56, 1);
  aw = av + v234 + (v65 ^ du ^ ew) + __ROL4__(bu, 5) - 899497514;
  cu = __ROL4__(v65, 30);
  v238 = __ROL4__(v207 ^ v227 ^ v237 ^ v243, 1);
  v67 = __ROL4__(v211 ^ v66 ^ v56 ^ v59, 1);
  ex = ew + v238 + (bu ^ cu ^ du) + __ROL4__(aw, 5) - 899497514;
  bv = __ROL4__(bu, 30);
  v68 = du + v67 + (aw ^ bv ^ cu);
  ax = __ROL4__(aw, 30);
  dv = __ROL4__(ex, 5) + v68 - 899497514;
  v69 = cu + __ROL4__(v215 ^ v234 ^ v243 ^ v61, 1) + (ax ^ bv ^ ex) + __ROL4__(dv, 5) - 899497514;
  ey = __ROL4__(ex, 30);
  v70 = bv + __ROL4__((unsigned int)Wb ^ v219 ^ v238 ^ v59, 1) + (ax ^ dv ^ ey) + __ROL4__(v69, 5) - 899497514;
  v71 = __ROL4__(dv, 30);
  *((_DWORD *)this + 4) += __ROL4__(v70, 5) + ax + __ROL4__(v199 ^ v223 ^ v67 ^ v61, 1) + (v69 ^ v71 ^ ey) - 899497514;
  v72 = *((_DWORD *)this + 6) + __ROL4__(v69, 30);
  *((_DWORD *)this + 5) += v70;
  *((_DWORD *)this + 6) = v72;
  v73 = v71 + *((_DWORD *)this + 7);
  v74 = *((_DWORD *)this + 8);
  *((_DWORD *)this + 7) = v73;
  result = (std::exception *)(ey + v74);
  *((_DWORD *)this + 8) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00443AA0
// Name: private: void TaoCrypt::SHA::AsmTransform(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge TaoCrypt::SHA::AsmTransform@<eax>(
        int a1@<ecx>,
        int _EBX@<ebx>,
        int _EDI@<edi>,
        int _ESI@<esi>,
        const LoggingContext_t *result,
        unsigned int times)
{
  int v16; // ebx
  int v17; // ecx
  int v18; // edx
  int v19; // ebp
  int v20; // ebx
  int v21; // ebp
  int v22; // eax
  int v23; // edx
  int v24; // ecx
  int v25; // ebp
  int v26; // ecx
  int v27; // ebx
  int v28; // edx
  int v29; // ebx
  int v30; // eax
  int v31; // ecx
  int v32; // eax
  int v33; // ebp
  int v34; // ebx
  int v35; // ebp
  int v36; // edx
  int v37; // eax
  int v38; // edx
  int v39; // ecx
  int v40; // ebp
  int v41; // ecx
  int v42; // ebx
  int v43; // edx
  int v44; // ebx
  int v45; // eax
  int v46; // ecx
  int v47; // eax
  int v48; // ebp
  int v49; // ebx
  int v50; // ebp
  int v51; // edx
  int v52; // eax
  int v53; // edx
  int v54; // ecx
  int v55; // ebp
  int v56; // ecx
  int v57; // ebx
  int v58; // edx
  int v59; // ebx
  int v60; // eax
  int v61; // ecx
  int v62; // eax
  int v63; // ebp
  int v64; // ebx
  int v65; // ebp
  int v66; // edx
  int v67; // eax
  int v68; // edx
  int v69; // ecx
  int v70; // ebp
  int v71; // ecx
  int v72; // ebx
  int v73; // edx
  int v74; // ebx
  int v75; // eax
  int v76; // ecx
  int v77; // eax
  int v78; // ebp
  int v79; // ebx
  int v80; // ebp
  int v81; // edx
  int v82; // eax
  int v83; // edx
  int v84; // ecx
  int v85; // ebp
  int v86; // ecx
  int v87; // ebx
  int v88; // edx
  int v89; // ebx
  int v90; // eax
  int v91; // ecx
  int v92; // eax
  int v93; // ebp
  int v94; // ebx
  int v95; // ebp
  int v96; // edx
  int v97; // eax
  int v98; // edx
  int v99; // ecx
  int v100; // ebp
  int v101; // ecx
  int v102; // ebx
  int v103; // edx
  int v104; // ebx
  int v105; // eax
  int v106; // ecx
  int v107; // eax
  int v108; // ebp
  int v109; // ebx
  int v110; // ebp
  int v111; // edx
  int v112; // eax
  int v113; // edx
  int v114; // ecx
  int v115; // ebp
  int v116; // ecx
  int v117; // ebx
  int v118; // edx
  int v119; // ebx
  int v120; // eax
  int v121; // ecx
  int v122; // eax
  int v123; // ebp
  int v124; // ebx
  int v125; // ebp
  int v126; // edx
  int v127; // eax
  int v128; // edx
  int v129; // ecx
  int v130; // ebp
  int v131; // ecx
  int v132; // ebx
  int v133; // edx
  int v134; // ebx
  int v135; // eax
  int v136; // ecx
  int v137; // eax
  int v141; // esi
  int v142; // ebx
  int v143; // ebp
  int v147; // esi
  int v148; // eax
  int v149; // edx
  int v153; // esi
  int v154; // ebp
  int v155; // ecx
  int v159; // esi
  int v160; // edx
  int v161; // ebx
  int v165; // esi
  int v166; // ecx
  int v167; // eax
  int v171; // esi
  int v172; // ebx
  int v173; // ebp
  int v177; // esi
  int v178; // eax
  int v179; // edx
  int v183; // esi
  int v184; // ebp
  int v185; // ecx
  int v189; // esi
  int v190; // edx
  int v191; // ebx
  int v195; // esi
  int v196; // ecx
  int v197; // eax
  int v201; // esi
  int v202; // ebx
  int v203; // ebp
  int v207; // esi
  int v208; // eax
  int v209; // edx
  int v213; // esi
  int v214; // ebp
  int v215; // ecx
  int v219; // esi
  int v220; // edx
  int v221; // ebx
  int v225; // esi
  int v226; // ecx
  int v227; // eax
  int v231; // esi
  int v232; // ebx
  int v233; // ebp
  int v237; // esi
  int v238; // eax
  int v239; // edx
  int v243; // esi
  int v244; // ebp
  int v245; // ecx
  int v249; // esi
  int v250; // edx
  int v251; // ebx
  int v255; // esi
  int v256; // ecx
  int v257; // eax
  int v258; // ebp
  int v259; // ebx
  int v260; // ebp
  int v261; // edx
  int v262; // eax
  int v263; // edx
  int v264; // ecx
  int v265; // ebp
  int v266; // ecx
  int v267; // ebx
  int v268; // edx
  int v269; // ebx
  int v270; // eax
  int v271; // ecx
  int v272; // eax
  int v273; // ebp
  int v274; // ebx
  int v275; // ebp
  int v276; // edx
  int v277; // eax
  int v278; // edx
  int v279; // ecx
  int v280; // ebp
  int v281; // ecx
  int v282; // ebx
  int v283; // edx
  int v284; // ebx
  int v285; // eax
  int v286; // ecx
  int v287; // eax
  int v288; // ebp
  int v289; // ebx
  int v290; // ebp
  int v291; // edx
  int v292; // eax
  int v293; // edx
  int v294; // ecx
  int v295; // ebp
  int v296; // ecx
  int v297; // ebx
  int v298; // edx
  int v299; // ebx
  int v300; // eax
  int v301; // ecx
  int v302; // eax
  int v303; // ebp
  int v304; // ebx
  int v305; // ebp
  int v306; // edx
  int v307; // eax
  int v308; // edx
  int v309; // ecx
  int v310; // ebp
  int v311; // ecx
  int v312; // ebx
  int v313; // edx
  int v314; // ebx
  int v315; // eax
  unsigned __int32 v321; // [esp+0h] [ebp-44h]
  int v322; // [esp+0h] [ebp-44h]
  int v323; // [esp+0h] [ebp-44h]
  int v324; // [esp+0h] [ebp-44h]
  int v325; // [esp+0h] [ebp-44h]
  unsigned __int32 v326; // [esp+4h] [ebp-40h]
  int v327; // [esp+4h] [ebp-40h]
  int v328; // [esp+4h] [ebp-40h]
  int v329; // [esp+4h] [ebp-40h]
  int v330; // [esp+4h] [ebp-40h]
  unsigned __int32 v331; // [esp+8h] [ebp-3Ch]
  int v332; // [esp+8h] [ebp-3Ch]
  int v333; // [esp+8h] [ebp-3Ch]
  int v334; // [esp+8h] [ebp-3Ch]
  int v335; // [esp+8h] [ebp-3Ch]
  unsigned __int32 v336; // [esp+Ch] [ebp-38h]
  int v337; // [esp+Ch] [ebp-38h]
  int v338; // [esp+Ch] [ebp-38h]
  int v339; // [esp+Ch] [ebp-38h]
  int v340; // [esp+Ch] [ebp-38h]
  unsigned __int32 v341; // [esp+10h] [ebp-34h]
  int v342; // [esp+10h] [ebp-34h]
  int v343; // [esp+10h] [ebp-34h]
  int v344; // [esp+10h] [ebp-34h]
  int v345; // [esp+10h] [ebp-34h]
  unsigned __int32 v346; // [esp+14h] [ebp-30h]
  int v347; // [esp+14h] [ebp-30h]
  int v348; // [esp+14h] [ebp-30h]
  int v349; // [esp+14h] [ebp-30h]
  int v350; // [esp+14h] [ebp-30h]
  unsigned __int32 v351; // [esp+18h] [ebp-2Ch]
  int v352; // [esp+18h] [ebp-2Ch]
  int v353; // [esp+18h] [ebp-2Ch]
  int v354; // [esp+18h] [ebp-2Ch]
  int v355; // [esp+18h] [ebp-2Ch]
  unsigned __int32 v356; // [esp+1Ch] [ebp-28h]
  int v357; // [esp+1Ch] [ebp-28h]
  int v358; // [esp+1Ch] [ebp-28h]
  int v359; // [esp+1Ch] [ebp-28h]
  int v360; // [esp+1Ch] [ebp-28h]
  unsigned __int32 v361; // [esp+20h] [ebp-24h]
  int v362; // [esp+20h] [ebp-24h]
  int v363; // [esp+20h] [ebp-24h]
  int v364; // [esp+20h] [ebp-24h]
  int v365; // [esp+20h] [ebp-24h]
  unsigned __int32 v366; // [esp+24h] [ebp-20h]
  int v367; // [esp+24h] [ebp-20h]
  int v368; // [esp+24h] [ebp-20h]
  int v369; // [esp+24h] [ebp-20h]
  int v370; // [esp+24h] [ebp-20h]
  unsigned __int32 v371; // [esp+28h] [ebp-1Ch]
  int v372; // [esp+28h] [ebp-1Ch]
  int v373; // [esp+28h] [ebp-1Ch]
  int v374; // [esp+28h] [ebp-1Ch]
  int v375; // [esp+28h] [ebp-1Ch]
  unsigned __int32 v376; // [esp+2Ch] [ebp-18h]
  int v377; // [esp+2Ch] [ebp-18h]
  int v378; // [esp+2Ch] [ebp-18h]
  int v379; // [esp+2Ch] [ebp-18h]
  int v380; // [esp+2Ch] [ebp-18h]
  unsigned __int32 v381; // [esp+30h] [ebp-14h]
  int v382; // [esp+30h] [ebp-14h]
  int v383; // [esp+30h] [ebp-14h]
  int v384; // [esp+30h] [ebp-14h]
  int v385; // [esp+30h] [ebp-14h]
  unsigned __int32 v386; // [esp+34h] [ebp-10h]
  int v387; // [esp+34h] [ebp-10h]
  int v388; // [esp+34h] [ebp-10h]
  int v389; // [esp+34h] [ebp-10h]
  unsigned __int32 v390; // [esp+38h] [ebp-Ch]
  int v391; // [esp+38h] [ebp-Ch]
  int v392; // [esp+38h] [ebp-Ch]
  int v393; // [esp+38h] [ebp-Ch]
  unsigned __int32 v394; // [esp+3Ch] [ebp-8h]
  int v395; // [esp+3Ch] [ebp-8h]
  int v396; // [esp+3Ch] [ebp-8h]
  int v397; // [esp+3Ch] [ebp-8h]
  std::exception *v398; // [esp+40h] [ebp-4h]
  int savedregs; // [esp+44h] [ebp+0h] BYREF

  _EBP = &savedregs;
  __asm
  {
    movd    mm3, edi
    movd    mm4, ebx
    movd    mm5, esi
    movd    mm6, ebp
  }
  _EAX = times;
  _ESI = (_DWORD *)(a1 + 16);
  __asm
  {
    movd    mm2, eax
    movd    mm1, esi
  }
  do
  {
    v321 = _byteswap_ulong(result->m_ChannelID);
    v326 = _byteswap_ulong(result->m_Flags);
    v331 = _byteswap_ulong(result->m_Severity);
    v336 = _byteswap_ulong(*(_DWORD *)&result->m_Color);
    v341 = _byteswap_ulong(result[1].m_ChannelID);
    v346 = _byteswap_ulong(result[1].m_Flags);
    v351 = _byteswap_ulong(result[1].m_Severity);
    v356 = _byteswap_ulong(*(_DWORD *)&result[1].m_Color);
    v361 = _byteswap_ulong(result[2].m_ChannelID);
    v366 = _byteswap_ulong(result[2].m_Flags);
    v371 = _byteswap_ulong(result[2].m_Severity);
    v376 = _byteswap_ulong(*(_DWORD *)&result[2].m_Color);
    v381 = _byteswap_ulong(result[3].m_ChannelID);
    v386 = _byteswap_ulong(result[3].m_Flags);
    v390 = _byteswap_ulong(result[3].m_Severity);
    v394 = _byteswap_ulong(*(_DWORD *)&result[3].m_Color);
    v398 = (std::exception *)result;
    v16 = _ESI[1];
    v17 = _ESI[2];
    v18 = _ESI[3];
    v19 = (v18 ^ v16 & (v18 ^ v17)) + _ESI[4] + 1518500249 + v321;
    v20 = __ROL4__(v16, 30);
    v21 = __ROL4__(*_ESI, 5) + v19;
    v22 = __ROL4__(*_ESI, 30);
    v23 = __ROL4__(v21, 5) + (v17 ^ *_ESI & (v17 ^ v20)) + v326 + v18 + 1518500249;
    v24 = (v20 ^ v21 & (v20 ^ v22)) + v331 + v17 + 1518500249;
    v25 = __ROL4__(v21, 30);
    v26 = __ROL4__(v23, 5) + v24;
    v27 = (v22 ^ v23 & (v22 ^ v25)) + v336 + v20 + 1518500249;
    v28 = __ROL4__(v23, 30);
    v29 = __ROL4__(v26, 5) + v27;
    v30 = (v25 ^ v26 & (v25 ^ v28)) + v341 + v22 + 1518500249;
    v31 = __ROL4__(v26, 30);
    v32 = __ROL4__(v29, 5) + v30;
    v33 = (v28 ^ v29 & (v28 ^ v31)) + v25 + 1518500249 + v346;
    v34 = __ROL4__(v29, 30);
    v35 = __ROL4__(v32, 5) + v33;
    v36 = (v31 ^ v32 & (v31 ^ v34)) + v351 + v28 + 1518500249;
    v37 = __ROL4__(v32, 30);
    v38 = __ROL4__(v35, 5) + v36;
    v39 = (v34 ^ v35 & (v34 ^ v37)) + v356 + v31 + 1518500249;
    v40 = __ROL4__(v35, 30);
    v41 = __ROL4__(v38, 5) + v39;
    v42 = (v37 ^ v38 & (v37 ^ v40)) + v361 + v34 + 1518500249;
    v43 = __ROL4__(v38, 30);
    v44 = __ROL4__(v41, 5) + v42;
    v45 = (v40 ^ v41 & (v40 ^ v43)) + v366 + v37 + 1518500249;
    v46 = __ROL4__(v41, 30);
    v47 = __ROL4__(v44, 5) + v45;
    v48 = (v43 ^ v44 & (v43 ^ v46)) + v40 + 1518500249 + v371;
    v49 = __ROL4__(v44, 30);
    v50 = __ROL4__(v47, 5) + v48;
    v51 = (v46 ^ v47 & (v46 ^ v49)) + v376 + v43 + 1518500249;
    v52 = __ROL4__(v47, 30);
    v53 = __ROL4__(v50, 5) + v51;
    v54 = (v49 ^ v50 & (v49 ^ v52)) + v381 + v46 + 1518500249;
    v55 = __ROL4__(v50, 30);
    v56 = __ROL4__(v53, 5) + v54;
    v57 = (v52 ^ v53 & (v52 ^ v55)) + v386 + v49 + 1518500249;
    v58 = __ROL4__(v53, 30);
    v59 = __ROL4__(v56, 5) + v57;
    v60 = (v55 ^ v56 & (v55 ^ v58)) + v390 + v52 + 1518500249;
    v61 = __ROL4__(v56, 30);
    v62 = __ROL4__(v59, 5) + v60;
    v63 = (v58 ^ v59 & (v58 ^ v61)) + v55 + 1518500249 + v394;
    v64 = __ROL4__(v59, 30);
    v65 = __ROL4__(v62, 5) + v63;
    v322 = __ROL4__(v386 ^ v361 ^ v331 ^ v321, 1);
    v66 = (v61 ^ v62 & (v61 ^ v64)) + v322 + v58 + 1518500249;
    v67 = __ROL4__(v62, 30);
    v68 = __ROL4__(v65, 5) + v66;
    v327 = __ROL4__(v390 ^ v366 ^ v336 ^ v326, 1);
    v69 = (v64 ^ v65 & (v64 ^ v67)) + v327 + v61 + 1518500249;
    v70 = __ROL4__(v65, 30);
    v71 = __ROL4__(v68, 5) + v69;
    v332 = __ROL4__(v394 ^ v371 ^ v341 ^ v331, 1);
    v72 = (v67 ^ v68 & (v67 ^ v70)) + v332 + v64 + 1518500249;
    v73 = __ROL4__(v68, 30);
    v74 = __ROL4__(v71, 5) + v72;
    v337 = __ROL4__(v322 ^ v376 ^ v346 ^ v336, 1);
    v75 = (v70 ^ v71 & (v70 ^ v73)) + v337 + v67 + 1518500249;
    v76 = __ROL4__(v71, 30);
    v77 = __ROL4__(v74, 5) + v75;
    v342 = __ROL4__(v327 ^ v381 ^ v351 ^ v341, 1);
    v78 = v70 + 1859775393 + (v74 ^ v73 ^ v76) + v342;
    v79 = __ROL4__(v74, 30);
    v80 = __ROL4__(v77, 5) + v78;
    v347 = __ROL4__(v332 ^ v386 ^ v356 ^ v346, 1);
    v81 = v347 + (v77 ^ v76 ^ v79) + v73 + 1859775393;
    v82 = __ROL4__(v77, 30);
    v83 = __ROL4__(v80, 5) + v81;
    v352 = __ROL4__(v337 ^ v390 ^ v361 ^ v351, 1);
    v84 = v352 + (v80 ^ v79 ^ v82) + v76 + 1859775393;
    v85 = __ROL4__(v80, 30);
    v86 = __ROL4__(v83, 5) + v84;
    v357 = __ROL4__(v342 ^ v394 ^ v366 ^ v356, 1);
    v87 = v357 + (v83 ^ v82 ^ v85) + v79 + 1859775393;
    v88 = __ROL4__(v83, 30);
    v89 = __ROL4__(v86, 5) + v87;
    v362 = __ROL4__(v347 ^ v322 ^ v371 ^ v361, 1);
    v90 = v362 + (v86 ^ v85 ^ v88) + v82 + 1859775393;
    v91 = __ROL4__(v86, 30);
    v92 = __ROL4__(v89, 5) + v90;
    v367 = __ROL4__(v352 ^ v327 ^ v376 ^ v366, 1);
    v93 = v85 + 1859775393 + (v89 ^ v88 ^ v91) + v367;
    v94 = __ROL4__(v89, 30);
    v95 = __ROL4__(v92, 5) + v93;
    v372 = __ROL4__(v357 ^ v332 ^ v381 ^ v371, 1);
    v96 = v372 + (v92 ^ v91 ^ v94) + v88 + 1859775393;
    v97 = __ROL4__(v92, 30);
    v98 = __ROL4__(v95, 5) + v96;
    v377 = __ROL4__(v362 ^ v337 ^ v386 ^ v376, 1);
    v99 = v377 + (v95 ^ v94 ^ v97) + v91 + 1859775393;
    v100 = __ROL4__(v95, 30);
    v101 = __ROL4__(v98, 5) + v99;
    v382 = __ROL4__(v367 ^ v342 ^ v390 ^ v381, 1);
    v102 = v382 + (v98 ^ v97 ^ v100) + v94 + 1859775393;
    v103 = __ROL4__(v98, 30);
    v104 = __ROL4__(v101, 5) + v102;
    v387 = __ROL4__(v372 ^ v347 ^ v394 ^ v386, 1);
    v105 = v387 + (v101 ^ v100 ^ v103) + v97 + 1859775393;
    v106 = __ROL4__(v101, 30);
    v107 = __ROL4__(v104, 5) + v105;
    v391 = __ROL4__(v377 ^ v352 ^ v322 ^ v390, 1);
    v108 = v100 + 1859775393 + (v104 ^ v103 ^ v106) + v391;
    v109 = __ROL4__(v104, 30);
    v110 = __ROL4__(v107, 5) + v108;
    v395 = __ROL4__(v382 ^ v357 ^ v327 ^ v394, 1);
    v111 = v395 + (v107 ^ v106 ^ v109) + v103 + 1859775393;
    v112 = __ROL4__(v107, 30);
    v113 = __ROL4__(v110, 5) + v111;
    v323 = __ROL4__(v387 ^ v362 ^ v332 ^ v322, 1);
    v114 = v323 + (v110 ^ v109 ^ v112) + v106 + 1859775393;
    v115 = __ROL4__(v110, 30);
    v116 = __ROL4__(v113, 5) + v114;
    v328 = __ROL4__(v391 ^ v367 ^ v337 ^ v327, 1);
    v117 = v328 + (v113 ^ v112 ^ v115) + v109 + 1859775393;
    v118 = __ROL4__(v113, 30);
    v119 = __ROL4__(v116, 5) + v117;
    v333 = __ROL4__(v395 ^ v372 ^ v342 ^ v332, 1);
    v120 = v333 + (v116 ^ v115 ^ v118) + v112 + 1859775393;
    v121 = __ROL4__(v116, 30);
    v122 = __ROL4__(v119, 5) + v120;
    v338 = __ROL4__(v323 ^ v377 ^ v347 ^ v337, 1);
    v123 = v115 + 1859775393 + (v119 ^ v118 ^ v121) + v338;
    v124 = __ROL4__(v119, 30);
    v125 = __ROL4__(v122, 5) + v123;
    v343 = __ROL4__(v328 ^ v382 ^ v352 ^ v342, 1);
    v126 = v343 + (v122 ^ v121 ^ v124) + v118 + 1859775393;
    v127 = __ROL4__(v122, 30);
    v128 = __ROL4__(v125, 5) + v126;
    v348 = __ROL4__(v333 ^ v387 ^ v357 ^ v347, 1);
    v129 = v348 + (v125 ^ v124 ^ v127) + v121 + 1859775393;
    v130 = __ROL4__(v125, 30);
    v131 = __ROL4__(v128, 5) + v129;
    v353 = __ROL4__(v338 ^ v391 ^ v362 ^ v352, 1);
    v132 = v353 + (v128 ^ v127 ^ v130) + v124 + 1859775393;
    v133 = __ROL4__(v128, 30);
    v134 = __ROL4__(v131, 5) + v132;
    v358 = __ROL4__(v343 ^ v395 ^ v367 ^ v357, 1);
    v135 = v358 + (v131 ^ v130 ^ v133) + v127 + 1859775393;
    v136 = __ROL4__(v131, 30);
    v137 = __ROL4__(v134, 5) + v135;
    _ESI = v133 & (v134 | v136);
    __asm { movd    mm0, esi }
    v363 = __ROL4__(v348 ^ v323 ^ v372 ^ v362, 1);
    __asm { movd    edi, mm0 }
    v141 = _EDI | v134 & v136;
    v142 = __ROL4__(v134, 30);
    v143 = __ROL4__(v137, 5) + v141 + v130 - 1894007588 + v363;
    _ESI = v136 & (v137 | v142);
    __asm { movd    mm0, esi }
    v368 = __ROL4__(v353 ^ v328 ^ v377 ^ v367, 1);
    __asm { movd    edi, mm0 }
    v147 = _EDI | v137 & v142;
    v148 = __ROL4__(v137, 30);
    v149 = __ROL4__(v143, 5) + v147 + v368 + v133 - 1894007588;
    _ESI = v142 & (v143 | v148);
    __asm { movd    mm0, esi }
    v373 = __ROL4__(v358 ^ v333 ^ v382 ^ v372, 1);
    __asm { movd    edi, mm0 }
    v153 = _EDI | v143 & v148;
    v154 = __ROL4__(v143, 30);
    v155 = __ROL4__(v149, 5) + v153 + v373 + v136 - 1894007588;
    _ESI = v148 & (v149 | v154);
    __asm { movd    mm0, esi }
    v378 = __ROL4__(v363 ^ v338 ^ v387 ^ v377, 1);
    __asm { movd    edi, mm0 }
    v159 = _EDI | v149 & v154;
    v160 = __ROL4__(v149, 30);
    v161 = __ROL4__(v155, 5) + v159 + v378 + v142 - 1894007588;
    _ESI = v154 & (v155 | v160);
    __asm { movd    mm0, esi }
    v383 = __ROL4__(v368 ^ v343 ^ v391 ^ v382, 1);
    __asm { movd    edi, mm0 }
    v165 = _EDI | v155 & v160;
    v166 = __ROL4__(v155, 30);
    v167 = __ROL4__(v161, 5) + v165 + v383 + v148 - 1894007588;
    _ESI = v160 & (v161 | v166);
    __asm { movd    mm0, esi }
    v388 = __ROL4__(v373 ^ v348 ^ v395 ^ v387, 1);
    __asm { movd    edi, mm0 }
    v171 = _EDI | v161 & v166;
    v172 = __ROL4__(v161, 30);
    v173 = __ROL4__(v167, 5) + v171 + v154 - 1894007588 + v388;
    _ESI = v166 & (v167 | v172);
    __asm { movd    mm0, esi }
    v392 = __ROL4__(v378 ^ v353 ^ v323 ^ v391, 1);
    __asm { movd    edi, mm0 }
    v177 = _EDI | v167 & v172;
    v178 = __ROL4__(v167, 30);
    v179 = __ROL4__(v173, 5) + v177 + v392 + v160 - 1894007588;
    _ESI = v172 & (v173 | v178);
    __asm { movd    mm0, esi }
    v396 = __ROL4__(v383 ^ v358 ^ v328 ^ v395, 1);
    __asm { movd    edi, mm0 }
    v183 = _EDI | v173 & v178;
    v184 = __ROL4__(v173, 30);
    v185 = __ROL4__(v179, 5) + v183 + v396 + v166 - 1894007588;
    _ESI = v178 & (v179 | v184);
    __asm { movd    mm0, esi }
    v324 = __ROL4__(v388 ^ v363 ^ v333 ^ v323, 1);
    __asm { movd    edi, mm0 }
    v189 = _EDI | v179 & v184;
    v190 = __ROL4__(v179, 30);
    v191 = __ROL4__(v185, 5) + v189 + v324 + v172 - 1894007588;
    _ESI = v184 & (v185 | v190);
    __asm { movd    mm0, esi }
    v329 = __ROL4__(v392 ^ v368 ^ v338 ^ v328, 1);
    __asm { movd    edi, mm0 }
    v195 = _EDI | v185 & v190;
    v196 = __ROL4__(v185, 30);
    v197 = __ROL4__(v191, 5) + v195 + v329 + v178 - 1894007588;
    _ESI = v190 & (v191 | v196);
    __asm { movd    mm0, esi }
    v334 = __ROL4__(v396 ^ v373 ^ v343 ^ v333, 1);
    __asm { movd    edi, mm0 }
    v201 = _EDI | v191 & v196;
    v202 = __ROL4__(v191, 30);
    v203 = __ROL4__(v197, 5) + v201 + v184 - 1894007588 + v334;
    _ESI = v196 & (v197 | v202);
    __asm { movd    mm0, esi }
    v339 = __ROL4__(v324 ^ v378 ^ v348 ^ v338, 1);
    __asm { movd    edi, mm0 }
    v207 = _EDI | v197 & v202;
    v208 = __ROL4__(v197, 30);
    v209 = __ROL4__(v203, 5) + v207 + v339 + v190 - 1894007588;
    _ESI = v202 & (v203 | v208);
    __asm { movd    mm0, esi }
    v344 = __ROL4__(v329 ^ v383 ^ v353 ^ v343, 1);
    __asm { movd    edi, mm0 }
    v213 = _EDI | v203 & v208;
    v214 = __ROL4__(v203, 30);
    v215 = __ROL4__(v209, 5) + v213 + v344 + v196 - 1894007588;
    _ESI = v208 & (v209 | v214);
    __asm { movd    mm0, esi }
    v349 = __ROL4__(v334 ^ v388 ^ v358 ^ v348, 1);
    __asm { movd    edi, mm0 }
    v219 = _EDI | v209 & v214;
    v220 = __ROL4__(v209, 30);
    v221 = __ROL4__(v215, 5) + v219 + v349 + v202 - 1894007588;
    _ESI = v214 & (v215 | v220);
    __asm { movd    mm0, esi }
    v354 = __ROL4__(v339 ^ v392 ^ v363 ^ v353, 1);
    __asm { movd    edi, mm0 }
    v225 = _EDI | v215 & v220;
    v226 = __ROL4__(v215, 30);
    v227 = __ROL4__(v221, 5) + v225 + v354 + v208 - 1894007588;
    _ESI = v220 & (v221 | v226);
    __asm { movd    mm0, esi }
    v359 = __ROL4__(v344 ^ v396 ^ v368 ^ v358, 1);
    __asm { movd    edi, mm0 }
    v231 = _EDI | v221 & v226;
    v232 = __ROL4__(v221, 30);
    v233 = __ROL4__(v227, 5) + v231 + v214 - 1894007588 + v359;
    _ESI = v226 & (v227 | v232);
    __asm { movd    mm0, esi }
    v364 = __ROL4__(v349 ^ v324 ^ v373 ^ v363, 1);
    __asm { movd    edi, mm0 }
    v237 = _EDI | v227 & v232;
    v238 = __ROL4__(v227, 30);
    v239 = __ROL4__(v233, 5) + v237 + v364 + v220 - 1894007588;
    _ESI = v232 & (v233 | v238);
    __asm { movd    mm0, esi }
    v369 = __ROL4__(v354 ^ v329 ^ v378 ^ v368, 1);
    __asm { movd    edi, mm0 }
    v243 = _EDI | v233 & v238;
    v244 = __ROL4__(v233, 30);
    v245 = __ROL4__(v239, 5) + v243 + v369 + v226 - 1894007588;
    _ESI = v238 & (v239 | v244);
    __asm { movd    mm0, esi }
    v374 = __ROL4__(v359 ^ v334 ^ v383 ^ v373, 1);
    __asm { movd    edi, mm0 }
    v249 = _EDI | v239 & v244;
    v250 = __ROL4__(v239, 30);
    v251 = __ROL4__(v245, 5) + v249 + v374 + v232 - 1894007588;
    _ESI = v244 & (v245 | v250);
    __asm { movd    mm0, esi }
    v379 = __ROL4__(v364 ^ v339 ^ v388 ^ v378, 1);
    __asm { movd    edi, mm0 }
    v255 = _EDI | v245 & v250;
    v256 = __ROL4__(v245, 30);
    v257 = __ROL4__(v251, 5) + v255 + v379 + v238 - 1894007588;
    v384 = __ROL4__(v369 ^ v344 ^ v392 ^ v383, 1);
    v258 = v244 - 899497514 + (v251 ^ v250 ^ v256) + v384;
    v259 = __ROL4__(v251, 30);
    v260 = __ROL4__(v257, 5) + v258;
    v389 = __ROL4__(v374 ^ v349 ^ v396 ^ v388, 1);
    v261 = v389 + (v257 ^ v256 ^ v259) + v250 - 899497514;
    v262 = __ROL4__(v257, 30);
    v263 = __ROL4__(v260, 5) + v261;
    v393 = __ROL4__(v379 ^ v354 ^ v324 ^ v392, 1);
    v264 = v393 + (v260 ^ v259 ^ v262) + v256 - 899497514;
    v265 = __ROL4__(v260, 30);
    v266 = __ROL4__(v263, 5) + v264;
    v397 = __ROL4__(v384 ^ v359 ^ v329 ^ v396, 1);
    v267 = v397 + (v263 ^ v262 ^ v265) + v259 - 899497514;
    v268 = __ROL4__(v263, 30);
    v269 = __ROL4__(v266, 5) + v267;
    v325 = __ROL4__(v389 ^ v364 ^ v334 ^ v324, 1);
    v270 = v325 + (v266 ^ v265 ^ v268) + v262 - 899497514;
    v271 = __ROL4__(v266, 30);
    v272 = __ROL4__(v269, 5) + v270;
    v330 = __ROL4__(v393 ^ v369 ^ v339 ^ v329, 1);
    v273 = v265 - 899497514 + (v269 ^ v268 ^ v271) + v330;
    v274 = __ROL4__(v269, 30);
    v275 = __ROL4__(v272, 5) + v273;
    v335 = __ROL4__(v397 ^ v374 ^ v344 ^ v334, 1);
    v276 = v335 + (v272 ^ v271 ^ v274) + v268 - 899497514;
    v277 = __ROL4__(v272, 30);
    v278 = __ROL4__(v275, 5) + v276;
    v340 = __ROL4__(v325 ^ v379 ^ v349 ^ v339, 1);
    v279 = v340 + (v275 ^ v274 ^ v277) + v271 - 899497514;
    v280 = __ROL4__(v275, 30);
    v281 = __ROL4__(v278, 5) + v279;
    v345 = __ROL4__(v330 ^ v384 ^ v354 ^ v344, 1);
    v282 = v345 + (v278 ^ v277 ^ v280) + v274 - 899497514;
    v283 = __ROL4__(v278, 30);
    v284 = __ROL4__(v281, 5) + v282;
    v350 = __ROL4__(v335 ^ v389 ^ v359 ^ v349, 1);
    v285 = v350 + (v281 ^ v280 ^ v283) + v277 - 899497514;
    v286 = __ROL4__(v281, 30);
    v287 = __ROL4__(v284, 5) + v285;
    v355 = __ROL4__(v340 ^ v393 ^ v364 ^ v354, 1);
    v288 = v280 - 899497514 + (v284 ^ v283 ^ v286) + v355;
    v289 = __ROL4__(v284, 30);
    v290 = __ROL4__(v287, 5) + v288;
    v360 = __ROL4__(v345 ^ v397 ^ v369 ^ v359, 1);
    v291 = v360 + (v287 ^ v286 ^ v289) + v283 - 899497514;
    v292 = __ROL4__(v287, 30);
    v293 = __ROL4__(v290, 5) + v291;
    v365 = __ROL4__(v350 ^ v325 ^ v374 ^ v364, 1);
    v294 = v365 + (v290 ^ v289 ^ v292) + v286 - 899497514;
    v295 = __ROL4__(v290, 30);
    v296 = __ROL4__(v293, 5) + v294;
    v370 = __ROL4__(v355 ^ v330 ^ v379 ^ v369, 1);
    v297 = v370 + (v293 ^ v292 ^ v295) + v289 - 899497514;
    v298 = __ROL4__(v293, 30);
    v299 = __ROL4__(v296, 5) + v297;
    v375 = __ROL4__(v360 ^ v335 ^ v384 ^ v374, 1);
    v300 = v375 + (v296 ^ v295 ^ v298) + v292 - 899497514;
    v301 = __ROL4__(v296, 30);
    v302 = __ROL4__(v299, 5) + v300;
    v380 = __ROL4__(v365 ^ v340 ^ v389 ^ v379, 1);
    v303 = v295 - 899497514 + (v299 ^ v298 ^ v301) + v380;
    v304 = __ROL4__(v299, 30);
    v305 = __ROL4__(v302, 5) + v303;
    v385 = __ROL4__(v370 ^ v345 ^ v393 ^ v384, 1);
    v306 = v385 + (v302 ^ v301 ^ v304) + v298 - 899497514;
    v307 = __ROL4__(v302, 30);
    v308 = __ROL4__(v305, 5) + v306;
    v309 = __ROL4__(v375 ^ v350 ^ v397 ^ v389, 1) + (v305 ^ v304 ^ v307) + v301 - 899497514;
    v310 = __ROL4__(v305, 30);
    v311 = __ROL4__(v308, 5) + v309;
    v312 = __ROL4__(v380 ^ v355 ^ v325 ^ v393, 1) + (v308 ^ v307 ^ v310) + v304 - 899497514;
    v313 = __ROL4__(v308, 30);
    v314 = __ROL4__(v311, 5) + v312;
    v315 = __ROL4__(v314, 5) + __ROL4__(v385 ^ v360 ^ v330 ^ v397, 1) + (v311 ^ v310 ^ v313) + v307 - 899497514;
    __asm { movd    esi, mm1 }
    *_ESI += v315;
    _ESI[1] += v314;
    _ESI[2] += __ROL4__(v311, 30);
    _ESI[3] += v313;
    _ESI[4] += v310;
    __asm { movd    ebp, mm2 }
    result = (const LoggingContext_t *)&v398[5]._Mywhat;
    --_EBP;
    __asm { movd    mm2, ebp }
  }
  while ( _EBP != 0 );
  __asm
  {
    movd    ebp, mm6
    movd    esi, mm5
    movd    ebx, mm4
    movd    edi, mm3
  }
  _m_empty();
  return v315;
}

//------------------------------------------------------------------------------
// Address: 0x00444A40
// Name: public: void TaoCrypt::SHA::Swap(class TaoCrypt::SHA __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::SHA::Swap(std::exception *this, std::exception *other)
{
  int v2; // edx
  std::exception_vtbl *v3; // edx
  const char *Mywhat; // edx

  v2 = *(_DWORD *)&this->_Mydofree;
  *(_DWORD *)&this->_Mydofree = *(_DWORD *)&other->_Mydofree;
  *(_DWORD *)&other->_Mydofree = v2;
  v3 = *((std::exception_vtbl **)this + 3);
  *((_DWORD *)this + 3) = other[1].__vftable;
  other[1].__vftable = v3;
  Mywhat = this->_Mywhat;
  this->_Mywhat = other->_Mywhat;
  other->_Mywhat = Mywhat;
  *((_DWORD *)this + 4) = other[1]._Mywhat;
  *((_DWORD *)this + 5) = *(_DWORD *)&other[1]._Mydofree;
  *(this + 2) = other[2];
  qmemcpy(this + 4, &other[4], 0x40u);
}

//------------------------------------------------------------------------------
// Address: 0x00444AA0
// Name: public: virtual void TaoCrypt::SHA::Update(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::SHA::Update(TaoCrypt::HASHwithTransform *this, std::exception *result, unsigned int len)
{
  int v4; // eax
  unsigned int v5; // ebp
  int v6; // ebx
  unsigned int v7; // edi
  unsigned int i; // ecx
  int v9; // edi
  unsigned int v10; // edi

  if ( TaoCrypt::isMMX )
  {
    v4 = *((_DWORD *)this + 1);
    v5 = len;
    v6 = (int)(this + 12);
    if ( v4 != 0 )
    {
      v7 = 64 - v4;
      if ( len < 64 - v4 )
        v7 = len;
      memcpy(dst: (unsigned __int8 *)(v6 + v4), src: (unsigned __int8 *)result, count: v7);
      *((_DWORD *)this + 1) += v7;
      result = (std::exception *)((char *)result + v7);
      v5 = len - v7;
      if ( *((_DWORD *)this + 1) == 64 )
      {
        for ( i = 0; i < 0x10; ++i )
          *(_DWORD *)(v6 + 4 * i) = __ROL4__(*(_DWORD *)(v6 + 4 * i), 8) & 0xFF00FF
                                  | __ROR4__(*(_DWORD *)(v6 + 4 * i), 8) & 0xFF00FF00;
        (*(void (__thiscall **)(TaoCrypt::HASHwithTransform *))(*this + 32))(a1: this);
        TaoCrypt::HASHwithTransform::AddLength(this, a2: 0x40u);
        *((_DWORD *)this + 1) = 0;
      }
    }
    if ( *((_DWORD *)this + 1) == 0 )
    {
      v9 = v5 >> 6;
      if ( v5 >> 6 != 0 )
      {
        TaoCrypt::SHA::AsmTransform(
          a1: (int)this,
          _EBX: v6,
          _EDI: v9,
          _ESI: (int)this,
          (const LoggingContext_t *)result,
          times: v5 >> 6);
        v10 = v9 << 6;
        TaoCrypt::HASHwithTransform::AddLength(this, a2: v10);
        v5 -= v10;
        result = (std::exception *)((char *)result + v10);
      }
    }
    if ( v5 != 0 )
    {
      memcpy(dst: (unsigned __int8 *)(v6 + *((_DWORD *)this + 1)), src: (unsigned __int8 *)result, count: v5);
      *((_DWORD *)this + 1) += v5;
    }
  }
  else
  {
    TaoCrypt::HASHwithTransform::Update(this, src: (const unsigned __int8 *)result, a3: len);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444B90
// Name: public: class TaoCrypt::SHA __near & TaoCrypt::SHA::operator=(class TaoCrypt::SHA const __near &)
// Source: json
//------------------------------------------------------------------------------
const std::exception *__thiscall TaoCrypt::SHA::operator=(std::exception *this, const std::exception *result)
{
  std::exception tmp; // [esp+4h] [ebp-70h] BYREF

  TaoCrypt::SHA::SHA(this: &tmp, a2: result);
  TaoCrypt::SHA::Swap(this, other: &tmp);
  return this;
}
