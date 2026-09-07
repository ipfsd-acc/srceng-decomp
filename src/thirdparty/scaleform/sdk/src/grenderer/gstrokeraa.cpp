// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/grenderer/gstrokeraa.cpp
// Functions: 15
// ============================================================

#include "thirdparty\scaleform\sdk\src\grenderer\gstrokeraa.h"

//------------------------------------------------------------------------------
// Address: 0x10194320
// Name: public: GStrokerAA::JoinParamType::JoinParamType(void)
// Source: json
//------------------------------------------------------------------------------
const pcharNode *__thiscall GStrokerAA::JoinParamType::JoinParamType(float *this)
{
  *this = 0.0;
  *(this + 1) = 0.0;
  *(this + 52) = 0.0;
  *(this + 2) = 0.0;
  *(this + 53) = 0.0;
  *(this + 3) = 0.0;
  *((_WORD *)this + 108) = 0;
  *(this + 4) = 0.0;
  *((_BYTE *)this + 218) = 0;
  *(this + 5) = 0.0;
  *(this + 6) = 0.0;
  *(this + 7) = 0.0;
  *(this + 8) = 0.0;
  *(this + 9) = 0.0;
  *(this + 10) = 0.0;
  *(this + 11) = 0.0;
  *(this + 12) = 0.0;
  *(this + 13) = 0.0;
  *(this + 14) = 0.0;
  *(this + 15) = 0.0;
  *(this + 16) = 0.0;
  *(this + 17) = 0.0;
  *(this + 18) = 0.0;
  *(this + 19) = 0.0;
  *(this + 20) = 0.0;
  *(this + 21) = 0.0;
  *(this + 22) = 0.0;
  *(this + 23) = 0.0;
  *(this + 24) = 0.0;
  *(this + 25) = 0.0;
  *(this + 26) = 0.0;
  *(this + 27) = 0.0;
  *(this + 28) = 0.0;
  *(this + 29) = 0.0;
  *(this + 30) = 0.0;
  *(this + 31) = 0.0;
  *(this + 32) = 0.0;
  *(this + 33) = 0.0;
  *(this + 34) = 0.0;
  *(this + 35) = 0.0;
  *(this + 36) = 0.0;
  *(this + 37) = 0.0;
  *(this + 38) = 0.0;
  *(this + 39) = 0.0;
  *(this + 40) = 0.0;
  *(this + 41) = 0.0;
  *(this + 42) = 0.0;
  *(this + 43) = 0.0;
  *(this + 44) = 0.0;
  *(this + 45) = 0.0;
  *(this + 46) = 0.0;
  *(this + 47) = 0.0;
  *(this + 48) = 0.0;
  *(this + 49) = 0.0;
  *(this + 50) = 0.0;
  *(this + 51) = 0.0;
  return (const pcharNode *)this;
}

//------------------------------------------------------------------------------
// Address: 0x10194430
// Name: private: static bool GStrokerAA::MitersIntersect(float,float,float,float,float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GStrokerAA::MitersIntersect()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10194510
// Name: private: void GStrokerAA::calcInitialJoinParam(struct GStrokeVertexType const __near &,struct GStrokeVertexType const __near &,struct GStrokerAA::WidthsType const __near &,struct GStrokerAA::JoinParamType __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStrokerAA::calcInitialJoinParam(
        EHRegistrationNode *this,
        EHExceptionRecord *v1,
        float *dy,
        float *w,
        int w_4)
{
  float v1a; // [esp+8h] [ebp+8h]
  float dya; // [esp+Ch] [ebp+Ch]

  v1a = (dy[1] - *(float *)&v1->ExceptionFlags) / *(float *)&v1->ExceptionRecord;
  dya = (*(float *)&v1->ExceptionCode - *dy) / *(float *)&v1->ExceptionRecord;
  *(float *)(w_4 + 32) = *w * v1a;
  *(float *)(w_4 + 36) = *w * dya;
  *(float *)(w_4 + 80) = w[1] * v1a;
  *(float *)(w_4 + 84) = w[1] * dya;
  *(float *)(w_4 + 40) = w[3] * v1a;
  *(float *)(w_4 + 44) = w[3] * dya;
  *(float *)(w_4 + 88) = v1a * w[4];
  *(float *)(w_4 + 92) = dya * w[4];
  *(float *)(w_4 + 160) = *(float *)&v1->ExceptionCode - *(float *)(w_4 + 40);
  *(float *)(w_4 + 164) = *(float *)&v1->ExceptionFlags - *(float *)(w_4 + 44);
  *(float *)(w_4 + 168) = *(float *)&v1->ExceptionCode + *(float *)(w_4 + 88);
  *(float *)(w_4 + 172) = *(float *)(w_4 + 92) + *(float *)&v1->ExceptionFlags;
  *(float *)(w_4 + 176) = w[3];
  *(float *)(w_4 + 180) = w[4];
  *(_BYTE *)(w_4 + 218) = 0;
  *(_BYTE *)(w_4 + 216) = 0;
  *(_WORD *)(w_4 + 212) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101945E0
// Name: private: void GStrokerAA::calcWidths(struct GStrokerAA::WidthsType __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStrokerAA::calcWidths(GStrokerAA *this, struct GStrokerAA::WidthsType *w)
{
  double v3; // st6
  double v4; // st5
  bool v5; // c0
  bool v6; // al
  double v7; // st7
  bool v8; // al
  double v9; // st7
  bool wa; // [esp+8h] [ebp+8h]

  w->__vftable = (DNameNode_vtbl *)this->pMarkerRN;
  w->me = (char *)this->ESP;
  if ( *(float *)&w->__vftable < 0.0 )
    *(float *)&w->__vftable = 0.0;
  if ( *(float *)&w->me < 0.0 )
    *(float *)&w->me = 0.0;
  *(float *)&w[1].__vftable = *(float *)&this->EBP + *(float *)&w->__vftable;
  *(float *)&w[1].me = *(float *)&this->DidUnwind + *(float *)&w->me;
  v3 = 1.0;
  if ( 0.0 == *(float *)&w[1].__vftable )
    v4 = 1.0;
  else
    v4 = *(float *)&w->__vftable / *(float *)&w[1].__vftable;
  *(float *)&w[2].me = v4;
  if ( 0.0 != *(float *)&w[1].me )
    v3 = *(float *)&w->me / *(float *)&w[1].me;
  *(float *)&w[2].myLen = v3;
  *(float *)&w[3].__vftable = *(float *)&this->pFuncInfo * *(float *)&w->__vftable;
  *(float *)&w[3].me = *(float *)&w->me * *(float *)&this->pFuncInfo;
  *(float *)&w[3].myLen = *(float *)&this->pFuncInfo * *(float *)&w[1].__vftable;
  *(float *)&w[4].__vftable = *(float *)&w[1].me * *(float *)&this->pFuncInfo;
  *(float *)&w[1].myLen = (*(float *)&w[1].me + *(float *)&w[1].__vftable) * 0.5;
  *(float *)&w->myLen = 0.5 * (*(float *)&w->me + *(float *)&w->__vftable);
  wa = *(float *)&w->__vftable > 0.0;
  v5 = *(float *)&w->me > 0.0;
  LOBYTE(w[4].me) = wa;
  BYTE1(w[4].me) = v5;
  BYTE2(w[4].me) = *(float *)&this->EBP > 0.0;
  HIBYTE(w[4].me) = *(float *)&this->DidUnwind > 0.0;
  v6 = wa || v5 || this->pRN != (EHRegistrationNode *)this->CatchDepth;
  v7 = *(float *)&w[1].me;
  LOBYTE(w[4].myLen) = v6;
  v8 = *(float *)&w[1].__vftable < v7;
  BYTE1(w[4].myLen) = v8;
  if ( v8 )
    v9 = *(float *)&w[1].__vftable / *(float *)&w[1].me;
  else
    v9 = *(float *)&w[1].me / *(float *)&w[1].__vftable;
  *(float *)&w[2].__vftable = v9;
}

//------------------------------------------------------------------------------
// Address: 0x10194750
// Name: private: void GStrokerAA::calcJoinParam(struct GStrokeVertexType const __near &,struct GStrokeVertexType const __near &,struct GStrokeVertexType const __near &,struct GStrokerAA::WidthsType const __near &,struct GStrokerAA::JoinParamType __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GStrokerAA::calcJoinParam(
        EHExceptionRecord *result,
        float *a2,
        float *a3,
        int intersectionFailed,
        int a5)
{
  char v8; // cl
  char v9; // dl
  double v10; // st7
  char v11; // cl
  double v12; // st7
  char v13; // dl
  double v14; // st7
  double v15; // st7
  float *p_ExceptionCode; // ecx
  float *v17; // edx
  double v18; // st6
  double v19; // st7
  double v20; // st5
  double v21; // st3
  double v22; // st4
  double v23; // st2
  double v24; // st7
  double v25; // st7
  double v26; // st7
  double v27; // st6
  double v28; // st6
  double v29; // st7
  double v30; // st5
  double v31; // st3
  double v32; // st4
  double v33; // st2
  double v34; // st7
  double v35; // st7
  double v36; // st6
  char v37; // al
  double v38; // st6
  double v39; // st6
  double v40; // st6
  double v41; // st6
  double v42; // st7
  double v43; // st7
  double v44; // st7
  double v45; // st7
  bool v46; // zf
  char v47; // al
  char v48; // al
  float v49; // [esp+30h] [ebp-1Ch]
  float v50; // [esp+30h] [ebp-1Ch]
  float v51; // [esp+30h] [ebp-1Ch]
  float v52; // [esp+30h] [ebp-1Ch]
  float v53; // [esp+34h] [ebp-18h]
  float v54; // [esp+34h] [ebp-18h]
  float v55; // [esp+34h] [ebp-18h]
  float v56; // [esp+38h] [ebp-14h]
  float v57; // [esp+38h] [ebp-14h]
  float v58; // [esp+3Ch] [ebp-10h]
  float v59; // [esp+3Ch] [ebp-10h]
  float v60; // [esp+40h] [ebp-Ch]
  float v61; // [esp+40h] [ebp-Ch]
  float epsilon; // [esp+44h] [ebp-8h]
  float dyc; // [esp+48h] [ebp-4h]
  float dyd; // [esp+48h] [ebp-4h]
  float dy; // [esp+48h] [ebp-4h]
  float dye; // [esp+48h] [ebp-4h]
  float dyf; // [esp+48h] [ebp-4h]
  float dya; // [esp+48h] [ebp-4h]
  float dyg; // [esp+48h] [ebp-4h]
  float dyb; // [esp+48h] [ebp-4h]
  float v71; // [esp+58h] [ebp+Ch]
  float v72; // [esp+58h] [ebp+Ch]
  float v73; // [esp+58h] [ebp+Ch]
  float v74; // [esp+58h] [ebp+Ch]
  float v75; // [esp+58h] [ebp+Ch]
  float v76; // [esp+58h] [ebp+Ch]
  float v77; // [esp+58h] [ebp+Ch]
  float v78; // [esp+58h] [ebp+Ch]
  float v79; // [esp+58h] [ebp+Ch]
  float v80; // [esp+58h] [ebp+Ch]
  float v81; // [esp+58h] [ebp+Ch]
  float v82; // [esp+58h] [ebp+Ch]
  float v83; // [esp+58h] [ebp+Ch]
  float v84; // [esp+58h] [ebp+Ch]
  float v85; // [esp+58h] [ebp+Ch]
  float v86; // [esp+58h] [ebp+Ch]
  float v87; // [esp+58h] [ebp+Ch]
  float v88; // [esp+5Ch] [ebp+10h]
  float v89; // [esp+5Ch] [ebp+10h]
  float v90; // [esp+5Ch] [ebp+10h]
  float v91; // [esp+5Ch] [ebp+10h]
  float v92; // [esp+5Ch] [ebp+10h]
  float v93; // [esp+5Ch] [ebp+10h]
  float v94; // [esp+5Ch] [ebp+10h]
  float v95; // [esp+5Ch] [ebp+10h]
  float intersectionFaileda; // [esp+60h] [ebp+14h]
  float intersectionFailedb; // [esp+60h] [ebp+14h]
  bool intersectionFailedc; // [esp+60h] [ebp+14h]
  float v99; // [esp+64h] [ebp+18h]
  float v100; // [esp+64h] [ebp+18h]
  float v101; // [esp+64h] [ebp+18h]
  float v102; // [esp+64h] [ebp+18h]
  float v103; // [esp+64h] [ebp+18h]
  float v104; // [esp+64h] [ebp+18h]
  float v105; // [esp+64h] [ebp+18h]
  float v106; // [esp+64h] [ebp+18h]
  float v107; // [esp+64h] [ebp+18h]
  float v108; // [esp+64h] [ebp+18h]
  float v109; // [esp+64h] [ebp+18h]
  float v110; // [esp+64h] [ebp+18h]
  float v111; // [esp+64h] [ebp+18h]
  char v112; // [esp+67h] [ebp+1Bh]

  *(float *)a5 = *(float *)(a5 + 16);
  *(float *)(a5 + 4) = *(float *)(a5 + 20);
  *(float *)(a5 + 48) = *(float *)(a5 + 64);
  *(float *)(a5 + 52) = *(float *)(a5 + 68);
  *(float *)(a5 + 8) = *(float *)(a5 + 24);
  *(float *)(a5 + 12) = *(float *)(a5 + 28);
  *(float *)(a5 + 56) = *(float *)(a5 + 72);
  *(float *)(a5 + 60) = *(float *)(a5 + 76);
  *(float *)(a5 + 16) = *(float *)(a5 + 32);
  *(float *)(a5 + 20) = *(float *)(a5 + 36);
  *(float *)(a5 + 64) = *(float *)(a5 + 80);
  *(float *)(a5 + 68) = *(float *)(a5 + 84);
  *(float *)(a5 + 24) = *(float *)(a5 + 40);
  *(float *)(a5 + 28) = *(float *)(a5 + 44);
  *(float *)(a5 + 72) = *(float *)(a5 + 88);
  *(float *)(a5 + 76) = *(float *)(a5 + 92);
  v71 = (a3[1] - a2[1]) / a2[2];
  dyc = (*a2 - *a3) / a2[2];
  *(float *)(a5 + 32) = *(float *)intersectionFailed * v71;
  *(float *)(a5 + 36) = *(float *)intersectionFailed * dyc;
  *(float *)(a5 + 80) = *(float *)(intersectionFailed + 4) * v71;
  *(float *)(a5 + 84) = *(float *)(intersectionFailed + 4) * dyc;
  *(float *)(a5 + 40) = *(float *)(intersectionFailed + 12) * v71;
  *(float *)(a5 + 44) = *(float *)(intersectionFailed + 12) * dyc;
  *(float *)(a5 + 88) = v71 * *(float *)(intersectionFailed + 16);
  *(float *)(a5 + 92) = dyc * *(float *)(intersectionFailed + 16);
  *(float *)(a5 + 112) = *(float *)(a5 + 136);
  *(float *)(a5 + 116) = *(float *)(a5 + 140);
  v8 = *(_BYTE *)(a5 + 210);
  *(float *)(a5 + 120) = *(float *)(a5 + 144);
  v9 = *(_BYTE *)(a5 + 211);
  *(float *)(a5 + 124) = *(float *)(a5 + 148);
  v10 = *(float *)(a5 + 152);
  *(_BYTE *)(a5 + 208) = v8;
  *(float *)(a5 + 128) = v10;
  v11 = *(_BYTE *)(a5 + 212);
  *(float *)(a5 + 132) = *(float *)(a5 + 156);
  v12 = *(float *)(a5 + 160);
  *(_BYTE *)(a5 + 209) = v9;
  v13 = *(_BYTE *)(a5 + 213);
  *(float *)(a5 + 136) = v12;
  *(float *)(a5 + 140) = *(float *)(a5 + 164);
  v14 = *(float *)(a5 + 168);
  *(_BYTE *)(a5 + 210) = v11;
  *(float *)(a5 + 144) = v14;
  *(_BYTE *)(a5 + 211) = v13;
  v15 = *(float *)(a5 + 172);
  v112 = 1;
  *(float *)(a5 + 148) = v15;
  *(float *)(a5 + 152) = *(float *)(a5 + 176);
  *(float *)(a5 + 156) = *(float *)(a5 + 180);
  epsilon = (a3[2] + a2[2]) * 0.009999999776482582;
  if ( *(_BYTE *)(intersectionFailed + 57) != 0 )
  {
    v72 = (*(float *)(a5 + 56) + *(float *)(a5 + 72)) * 0.5;
    dyd = 0.5 * (*(float *)(a5 + 60) + *(float *)(a5 + 76));
    v73 = dyd * dyd + v72 * v72;
    v74 = sqrt(v73);
    p_ExceptionCode = (float *)&result->ExceptionCode;
    v17 = a3;
    *(float *)(a5 + 108) = v74;
    *(float *)(a5 + 104) = v74 * *(float *)(intersectionFailed + 32);
    v75 = v74 * *(float *)(intersectionFailed + 24);
    *(float *)(a5 + 100) = v75;
    *(float *)(a5 + 96) = v75 * *(float *)(intersectionFailed + 28);
    v53 = *(float *)&result->ExceptionCode + *(float *)(a5 + 72);
    v49 = *(float *)(a5 + 76) + *(float *)&result->ExceptionFlags;
    dy = *a2 + *(float *)(a5 + 72);
    v58 = a2[1] + *(float *)(a5 + 76);
    intersectionFaileda = *a2 + *(float *)(a5 + 88);
    v76 = a2[1] + *(float *)(a5 + 92);
    v60 = *a3 + *(float *)(a5 + 88);
    v56 = a3[1] + *(float *)(a5 + 92);
    v18 = v53;
    v19 = dy - v53;
    v20 = v56 - v76;
    v21 = v49;
    v22 = v58 - v49;
    v23 = v60 - intersectionFaileda;
    v54 = v20 * v19 - v23 * v22;
    v50 = fabs(v54);
    if ( epsilon <= (double)v50 )
    {
      v99 = v23 * (v21 - v76) - v20 * (v18 - intersectionFaileda);
      v100 = v99 / v54;
      *(float *)(a5 + 168) = v18 + v19 * v100;
      *(float *)(a5 + 172) = v21 + v22 * v100;
      v77 = *(float *)(a5 + 168) - *a2;
      v101 = *(float *)(a5 + 172) - a2[1];
      v102 = v101 * v101 + v77 * v77;
      v103 = sqrt(v102);
      p_ExceptionCode = (float *)&result->ExceptionCode;
      v17 = a3;
      v25 = v103;
      v112 = 0;
      *(float *)(a5 + 180) = v25;
      *(float *)(a5 + 176) = v25 * *(float *)(intersectionFailed + 24);
      *(float *)(a5 + 160) = *a2 - (*(float *)(a5 + 168) - *a2) * *(float *)(intersectionFailed + 24);
      v26 = a2[1];
      v27 = (*(float *)(a5 + 172) - v26) * *(float *)(intersectionFailed + 24);
      *(_WORD *)(a5 + 212) = 0;
      *(float *)(a5 + 164) = v26 - v27;
      goto LABEL_9;
    }
    *(float *)(a5 + 168) = v18 * 0.25 + dy * 0.25 + intersectionFaileda * 0.25 + v60 * 0.25;
    v24 = v21 * 0.25 + v58 * 0.25 + v76 * 0.25 + 0.25 * v56;
  }
  else
  {
    v78 = (*(float *)(a5 + 24) + *(float *)(a5 + 8)) * 0.5;
    dye = 0.5 * (*(float *)(a5 + 12) + *(float *)(a5 + 28));
    v79 = dye * dye + v78 * v78;
    v80 = sqrt(v79);
    *(float *)(a5 + 100) = v80;
    *(float *)(a5 + 96) = v80 * *(float *)(intersectionFailed + 28);
    v81 = *(float *)(a5 + 100) * *(float *)(intersectionFailed + 24);
    *(float *)(a5 + 108) = v81;
    *(float *)(a5 + 104) = v81 * *(float *)(intersectionFailed + 32);
    v51 = *(float *)&result->ExceptionCode - *(float *)(a5 + 24);
    dyf = *(float *)&result->ExceptionFlags - *(float *)(a5 + 28);
    v55 = *a2 - *(float *)(a5 + 24);
    v59 = a2[1] - *(float *)(a5 + 28);
    intersectionFailedb = *a2 - *(float *)(a5 + 40);
    v82 = a2[1] - *(float *)(a5 + 44);
    v57 = *a3 - *(float *)(a5 + 40);
    v61 = a3[1] - *(float *)(a5 + 44);
    v28 = v51;
    v29 = v55 - v51;
    v30 = v61 - v82;
    v31 = dyf;
    v32 = v59 - dyf;
    v33 = v57 - intersectionFailedb;
    dya = v30 * v29 - v33 * v32;
    v52 = fabs(dya);
    if ( epsilon > (double)v52 )
    {
      p_ExceptionCode = (float *)&result->ExceptionCode;
      v17 = a3;
      *(float *)(a5 + 160) = v28 * 0.25 + v55 * 0.25 + intersectionFailedb * 0.25 + v57 * 0.25;
      *(float *)(a5 + 164) = v31 * 0.25 + v59 * 0.25 + v82 * 0.25 + 0.25 * v61;
      goto LABEL_9;
    }
    v104 = v33 * (v31 - v82) - v30 * (v28 - intersectionFailedb);
    v105 = v104 / dya;
    *(float *)(a5 + 160) = v28 + v29 * v105;
    *(float *)(a5 + 164) = v31 + v32 * v105;
    v83 = *(float *)(a5 + 160) - *a2;
    v106 = *(float *)(a5 + 164) - a2[1];
    v107 = v106 * v106 + v83 * v83;
    v108 = sqrt(v107);
    p_ExceptionCode = (float *)&result->ExceptionCode;
    v17 = a3;
    v34 = v108;
    v112 = 0;
    *(float *)(a5 + 176) = v34;
    *(float *)(a5 + 180) = v34 * *(float *)(intersectionFailed + 24);
    *(float *)(a5 + 168) = *a2 - (*(float *)(a5 + 160) - *a2) * *(float *)(intersectionFailed + 24);
    v35 = a2[1];
    v36 = (*(float *)(a5 + 164) - v35) * *(float *)(intersectionFailed + 24);
    *(_WORD *)(a5 + 212) = 0;
    v24 = v35 - v36;
  }
  *(float *)(a5 + 172) = v24;
LABEL_9:
  *(_BYTE *)(a5 + 214) = *(_BYTE *)(a5 + 215);
  *(_BYTE *)(a5 + 215) = *(_BYTE *)(a5 + 216);
  v84 = (a2[1] - p_ExceptionCode[1]) * (*v17 - *a2) - (v17[1] - a2[1]) * (*a2 - *p_ExceptionCode);
  intersectionFailedc = v84 > 0.0;
  *(_BYTE *)(a5 + 216) = intersectionFailedc;
  if ( v112 != 0 )
  {
    v37 = *(_BYTE *)(intersectionFailed + 57);
    v38 = *a2;
    if ( v37 != 0 )
      v39 = v38 + *(float *)(a5 + 72);
    else
      v39 = v38 - *(float *)(a5 + 24);
    v85 = v39;
    v40 = a2[1];
    if ( v37 != 0 )
      v41 = v40 + *(float *)(a5 + 76);
    else
      v41 = v40 - *(float *)(a5 + 28);
    dyg = v41;
    v109 = (v85 - *a2) * (a2[1] - p_ExceptionCode[1]) - (dyg - a2[1]) * (*a2 - *p_ExceptionCode);
    v86 = (v85 - *v17) * (v17[1] - a2[1]) - (*v17 - *a2) * (dyg - v17[1]);
    if ( v109 < 0.0 == v86 < 0.0 )
    {
      *(float *)(a5 + 160) = *a2 - *(float *)(a5 + 24);
      *(float *)(a5 + 164) = a2[1] - *(float *)(a5 + 28);
      *(float *)(a5 + 176) = *(float *)(intersectionFailed + 44);
      *(float *)(a5 + 168) = *a2 + *(float *)(a5 + 72);
      *(float *)(a5 + 172) = a2[1] + *(float *)(a5 + 76);
      v42 = *(float *)(intersectionFailed + 48);
      *(_WORD *)(a5 + 212) = 0;
      *(float *)(a5 + 180) = v42;
    }
    else
    {
      v87 = *a2 - (*p_ExceptionCode + *a3) * 0.5;
      dyb = a2[1] - 0.5 * (a3[1] + p_ExceptionCode[1]);
      v43 = *a2;
      if ( intersectionFailedc )
      {
        *(float *)(a5 + 168) = v43 + *(float *)(a5 + 72);
        *(float *)(a5 + 172) = a2[1] + *(float *)(a5 + 76);
        v44 = *(float *)(intersectionFailed + 48);
        *(_BYTE *)(a5 + 213) = 1;
        *(float *)(a5 + 180) = v44;
        *(float *)(a5 + 160) = v87 * 1024.0 + *a2;
        v88 = 1024.0 * dyb + a2[1];
        *(float *)(a5 + 164) = v88;
        v110 = *(float *)(a5 + 160) - *a2;
        v89 = v88 - a2[1];
        v90 = v89 * v89 + v110 * v110;
        v91 = sqrt(v90);
        p_ExceptionCode = (float *)&result->ExceptionCode;
        *(float *)(a5 + 176) = v91;
        *(_BYTE *)(a5 + 212) = 0;
      }
      else
      {
        *(float *)(a5 + 160) = v43 - *(float *)(a5 + 24);
        *(float *)(a5 + 164) = a2[1] - *(float *)(a5 + 28);
        v45 = *(float *)(intersectionFailed + 44);
        *(_BYTE *)(a5 + 212) = 1;
        *(float *)(a5 + 176) = v45;
        *(float *)(a5 + 168) = v87 * 1024.0 + *a2;
        v92 = 1024.0 * dyb + a2[1];
        *(float *)(a5 + 172) = v92;
        v111 = *(float *)(a5 + 168) - *a2;
        v93 = v92 - a2[1];
        v94 = v93 * v93 + v111 * v111;
        v95 = sqrt(v94);
        p_ExceptionCode = (float *)&result->ExceptionCode;
        *(float *)(a5 + 180) = v95;
        *(_BYTE *)(a5 + 213) = 0;
      }
    }
  }
  v46 = *(_BYTE *)(a5 + 215) == 0;
  *(_BYTE *)(a5 + 217) = *(_BYTE *)(a5 + 218);
  if ( v46 )
    v47 = *(_BYTE *)(a5 + 210);
  else
    v47 = *(_BYTE *)(a5 + 211);
  *(_BYTE *)(a5 + 218) = v47;
  if ( v47 == 0 )
  {
    GStrokerAA::MitersIntersect();
    *(_BYTE *)(a5 + 218) = v48;
  }
  *(float *)(a5 + 184) = (*(float *)(a5 + 136) - *p_ExceptionCode) * *(float *)(intersectionFailed + 28)
                       + *p_ExceptionCode;
  *(float *)(a5 + 188) = (*(float *)(a5 + 140) - p_ExceptionCode[1]) * *(float *)(intersectionFailed + 28)
                       + p_ExceptionCode[1];
  *(float *)(a5 + 192) = (*(float *)(a5 + 144) - *p_ExceptionCode) * *(float *)(intersectionFailed + 32)
                       + *p_ExceptionCode;
  *(float *)(a5 + 196) = (*(float *)(a5 + 148) - p_ExceptionCode[1]) * *(float *)(intersectionFailed + 32)
                       + p_ExceptionCode[1];
  *(float *)(a5 + 200) = *(float *)(intersectionFailed + 28) * *(float *)(a5 + 152);
  *(float *)(a5 + 204) = *(float *)(a5 + 156) * *(float *)(intersectionFailed + 32);
}

//------------------------------------------------------------------------------
// Address: 0x10195150
// Name: private: unsigned int GStrokerAA::addVertex(float,float,int)
// Source: json
//------------------------------------------------------------------------------
EHRegistrationNode *__userpurge GStrokerAA::addVertex@<eax>(
        GStrokerAA *this@<ecx>,
        char a2@<dil>,
        float x,
        float y,
        int id)
{
  GStrokerAA *v5; // esi
  unsigned int v6; // edi
  int v7; // eax

  v5 = (GStrokerAA *)((char *)this + 64);
  v6 = *((_DWORD *)this + 16) >> 8;
  if ( v6 >= *((_DWORD *)this + 17) )
    GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
      this: (DName *)this + 8,
      result: *((_DWORD *)this + 16) >> 8,
      nb: a2);
  v7 = *((_DWORD *)v5->pFuncInfo + v6) + 12 * (unsigned __int8)v5->pNext;
  *(float *)v7 = x;
  *(float *)(v7 + 4) = y;
  *(_DWORD *)(v7 + 8) = id;
  return v5->pNext++;
}

//------------------------------------------------------------------------------
// Address: 0x101951B0
// Name: private: void GStrokerAA::addTriangle(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStrokerAA::addTriangle(GStrokerAA *this, unsigned int a2, unsigned int a3, unsigned int a4)
{
  GStrokerAA *v4; // esi
  unsigned int v5; // edi
  _DWORD *v6; // eax
  char v7; // [esp+0h] [ebp-Ch]

  v4 = this + 2;
  v5 = *((_DWORD *)this + 20) >> 8;
  if ( v5 >= *((_DWORD *)this + 21) )
    GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
      this: (DName *)this + 10,
      result: *((_DWORD *)this + 20) >> 8,
      nb: v7);
  v6 = (_DWORD *)(*((_DWORD *)v4->pFuncInfo + v5) + 12 * (unsigned __int8)v4->pNext);
  *v6 = a2;
  v6[1] = a3;
  v6[2] = a4;
  ++v4->pNext;
}

//------------------------------------------------------------------------------
// Address: 0x10195200
// Name: private: void GStrokerAA::calcButtCap(struct GStrokeVertexType const __near &,struct GStrokeVertexType const __near &,float,struct GStrokerAA::WidthsType const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStrokerAA::calcButtCap(
        GStrokerAA *this,
        const struct GStrokeVertexType *a2,
        const struct GStrokeVertexType *a3,
        float buttSolidR,
        const struct GStrokerAA::WidthsType *endFlag,
        bool a6)
{
  const struct GStrokerAA::WidthsType *v7; // esi
  double v8; // st7
  double v10; // st7
  double v11; // st5
  char me_high; // cl
  char v13; // al
  unsigned int v14; // ecx
  int v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // ecx
  int v18; // eax
  int v19; // eax
  unsigned int v20; // ecx
  int v21; // eax
  unsigned int v22; // ecx
  int v23; // eax
  unsigned int v24; // ecx
  int v25; // eax
  int v26; // eax
  unsigned int v27; // ecx
  int v28; // eax
  unsigned int v29; // ecx
  int v30; // eax
  int v31; // eax
  double v32; // st7
  unsigned int v33; // ebx
  int v34; // eax
  int v35; // eax
  int v36; // eax
  unsigned int v37; // ebx
  unsigned int *v38; // eax
  unsigned int v39; // ebx
  _DWORD *v40; // eax
  unsigned int v41; // ebx
  _DWORD *v42; // eax
  unsigned int v43; // ebx
  _DWORD *v44; // eax
  GStrokerAA *v45; // esi
  unsigned int v46; // ebx
  int v47; // edx
  int v48; // eax
  int v49; // eax
  int v50; // edi
  void *v51; // ebx
  _DWORD *v52; // eax
  char v53; // [esp+0h] [ebp-4Ch]
  float v54; // [esp+Ch] [ebp-40h]
  float v55; // [esp+Ch] [ebp-40h]
  float v56; // [esp+Ch] [ebp-40h]
  float v57; // [esp+Ch] [ebp-40h]
  float v58; // [esp+Ch] [ebp-40h]
  float v59; // [esp+Ch] [ebp-40h]
  float v60; // [esp+Ch] [ebp-40h]
  float v61; // [esp+Ch] [ebp-40h]
  int v62; // [esp+Ch] [ebp-40h]
  int v63; // [esp+Ch] [ebp-40h]
  int v64; // [esp+Ch] [ebp-40h]
  int v65; // [esp+Ch] [ebp-40h]
  float v66; // [esp+10h] [ebp-3Ch]
  float v67; // [esp+10h] [ebp-3Ch]
  float v68; // [esp+10h] [ebp-3Ch]
  float v69; // [esp+10h] [ebp-3Ch]
  float v70; // [esp+10h] [ebp-3Ch]
  float v71; // [esp+10h] [ebp-3Ch]
  float v72; // [esp+10h] [ebp-3Ch]
  float v73; // [esp+10h] [ebp-3Ch]
  int v74; // [esp+10h] [ebp-3Ch]
  EHRegistrationNode *pRN; // [esp+14h] [ebp-38h]
  int CatchDepth; // [esp+14h] [ebp-38h]
  unsigned int v77; // [esp+14h] [ebp-38h]
  int v78; // [esp+14h] [ebp-38h]
  int v79; // [esp+14h] [ebp-38h]
  float dySolidL; // [esp+18h] [ebp-34h]
  float dxSolidL; // [esp+1Ch] [ebp-30h]
  void *solidWidthL; // [esp+20h] [ebp-2Ch]
  float solidWidthLa; // [esp+20h] [ebp-2Ch]
  void *solidWidthR; // [esp+24h] [ebp-28h]
  float solidWidthRa; // [esp+24h] [ebp-28h]
  float dySolidR; // [esp+28h] [ebp-24h]
  float dxSolidR; // [esp+2Ch] [ebp-20h]
  void *totalWidthL; // [esp+30h] [ebp-1Ch]
  float totalWidthLa; // [esp+30h] [ebp-1Ch]
  float dxTotalL; // [esp+34h] [ebp-18h]
  float totalWidthRc; // [esp+38h] [ebp-14h]
  int totalWidthR; // [esp+38h] [ebp-14h]
  unsigned int totalWidthRa; // [esp+38h] [ebp-14h]
  unsigned int totalWidthRb; // [esp+38h] [ebp-14h]
  unsigned int buttSolidL; // [esp+3Ch] [ebp-10h]
  unsigned int buttTotalL; // [esp+40h] [ebp-Ch]
  float dya; // [esp+44h] [ebp-8h]
  float dy; // [esp+44h] [ebp-8h]
  float v99; // [esp+48h] [ebp-4h]
  float v100; // [esp+48h] [ebp-4h]
  bool aaFlagL; // [esp+57h] [ebp+Bh]
  bool aaFlagR; // [esp+5Bh] [ebp+Fh]
  unsigned int buttSolidRa; // [esp+5Ch] [ebp+10h]
  unsigned int buttSolidRb; // [esp+5Ch] [ebp+10h]
  unsigned int buttSolidRc; // [esp+5Ch] [ebp+10h]
  unsigned int v106; // [esp+64h] [ebp+18h]
  unsigned int v107; // [esp+64h] [ebp+18h]
  unsigned int v108; // [esp+64h] [ebp+18h]

  v7 = endFlag;
  if ( a6 )
  {
    solidWidthL = endFlag->me;
    solidWidthR = endFlag->__vftable;
    totalWidthL = endFlag[1].me;
    v8 = *(float *)&endFlag[1].__vftable;
  }
  else
  {
    solidWidthL = endFlag->__vftable;
    solidWidthR = endFlag->me;
    totalWidthL = endFlag[1].__vftable;
    v8 = *(float *)&endFlag[1].me;
  }
  totalWidthRc = v8;
  v10 = buttSolidR;
  v99 = (*((float *)a3 + 1) - *((float *)a2 + 1)) / buttSolidR;
  buttSolidL = 0;
  buttSolidRa = 0;
  buttTotalL = 0;
  dya = (*(float *)a2 - *(float *)a3) / v10;
  dxSolidL = v99 * *(float *)&solidWidthL;
  dySolidL = *(float *)&solidWidthL * dya;
  dxSolidR = v99 * *(float *)&solidWidthR;
  dySolidR = *(float *)&solidWidthR * dya;
  dxTotalL = v99 * *(float *)&totalWidthL;
  totalWidthLa = *(float *)&totalWidthL * dya;
  v11 = totalWidthRc;
  totalWidthR = 0;
  solidWidthRa = v99 * v11;
  solidWidthLa = v11 * dya;
  v100 = (totalWidthLa - dySolidL + solidWidthLa - dySolidR) * 0.5;
  dy = 0.5 * (dxSolidR - solidWidthRa + dxSolidL - dxTotalL);
  if ( a6 )
  {
    me_high = HIBYTE(endFlag[4].me);
    v13 = BYTE2(endFlag[4].me);
    aaFlagL = me_high;
    aaFlagR = v13;
  }
  else
  {
    v13 = BYTE2(endFlag[4].me);
    me_high = HIBYTE(endFlag[4].me);
    aaFlagL = v13;
    aaFlagR = me_high;
  }
  if ( v13 != 0 || me_high != 0 )
  {
    v14 = *((_DWORD *)this + 16) >> 8;
    buttSolidRb = v14;
    v54 = *(float *)a2 - dxSolidL + v100;
    v66 = *((float *)a2 + 1) - dySolidL + dy;
    if ( v14 >= *((_DWORD *)this + 17) )
    {
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 8,
        result: v14,
        nb: v53);
      v14 = buttSolidRb;
    }
    v15 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v14) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
    *(float *)v15 = v54;
    *(float *)(v15 + 4) = v66;
    *(_DWORD *)(v15 + 8) = -1;
    v16 = (*((_DWORD *)this + 16))++;
    buttSolidL = v16;
    if ( LOBYTE(endFlag[4].myLen) != 0 )
    {
      v17 = *((_DWORD *)this + 16) >> 8;
      buttSolidRc = v17;
      v55 = *(float *)a2 + dxSolidR + v100;
      v67 = dySolidR + *((float *)a2 + 1) + dy;
      if ( v17 >= *((_DWORD *)this + 17) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 8,
          result: v17,
          nb: v53);
        v17 = buttSolidRc;
      }
      v18 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v17) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
      *(float *)v18 = v55;
      *(float *)(v18 + 4) = v67;
      *(_DWORD *)(v18 + 8) = -1;
      ++*((_DWORD *)this + 16);
      v16 = buttSolidL;
      v19 = *((_DWORD *)this + 16) - 1;
      buttSolidRa = v19;
    }
    else
    {
      buttSolidRa = *((_DWORD *)this + 16) - 1;
      v19 = buttSolidRa;
    }
    if ( aaFlagL )
    {
      v20 = *((_DWORD *)this + 16) >> 8;
      totalWidthRa = v20;
      v56 = *(float *)a2 - dxTotalL + v100;
      v68 = *((float *)a2 + 1) - totalWidthLa + dy;
      if ( v20 >= *((_DWORD *)this + 17) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 8,
          result: v20,
          nb: v53);
        v20 = totalWidthRa;
      }
      v21 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v20) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
      *(float *)v21 = v56;
      *(float *)(v21 + 4) = v68;
      *(_DWORD *)(v21 + 8) = -1;
      buttTotalL = (*((_DWORD *)this + 16))++;
      v19 = buttSolidRa;
    }
    else
    {
      buttTotalL = v16;
    }
    if ( aaFlagR )
    {
      v22 = *((_DWORD *)this + 16) >> 8;
      totalWidthRb = v22;
      v57 = *(float *)a2 + solidWidthRa + v100;
      v69 = solidWidthLa + *((float *)a2 + 1) + dy;
      if ( v22 >= *((_DWORD *)this + 17) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 8,
          result: v22,
          nb: v53);
        v22 = totalWidthRb;
      }
      v23 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v22) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
      *(float *)v23 = v57;
      *(float *)(v23 + 4) = v69;
      *(_DWORD *)(v23 + 8) = -1;
      totalWidthR = (*((_DWORD *)this + 16))++;
      v7 = endFlag;
    }
    else
    {
      v7 = endFlag;
      totalWidthR = v19;
    }
  }
  if ( a6 )
  {
    v35 = *((_DWORD *)this + 26);
    *((_DWORD *)this + 26) = *((_DWORD *)this + 27);
    *((_DWORD *)this + 27) = v35;
    v36 = *((_DWORD *)this + 24);
    *((_DWORD *)this + 24) = *((_DWORD *)this + 25);
    *((_DWORD *)this + 25) = v36;
  }
  else
  {
    v24 = *((_DWORD *)this + 16) >> 8;
    pRN = this->pRN;
    v58 = *(float *)a2 - dxSolidL;
    v106 = v24;
    v70 = *((float *)a2 + 1) - dySolidL;
    if ( v24 >= *((_DWORD *)this + 17) )
    {
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 8,
        result: v24,
        nb: v53);
      v24 = v106;
    }
    v25 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v24) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
    *(float *)v25 = v58;
    *(float *)(v25 + 4) = v70;
    *(_DWORD *)(v25 + 8) = pRN;
    v26 = (*((_DWORD *)this + 16))++;
    *((_DWORD *)this + 24) = v26;
    if ( BYTE2(endFlag[4].me) != 0 )
    {
      v27 = *((_DWORD *)this + 16) >> 8;
      v107 = v27;
      v59 = *(float *)a2 - dxTotalL;
      v71 = *((float *)a2 + 1) - totalWidthLa;
      if ( v27 >= *((_DWORD *)this + 17) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 8,
          result: v27,
          nb: v53);
        v27 = v107;
      }
      v28 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v27) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
      *(float *)v28 = v59;
      *(float *)(v28 + 4) = v71;
      *(_DWORD *)(v28 + 8) = -1;
      v26 = (*((_DWORD *)this + 16))++;
    }
    *((_DWORD *)this + 26) = v26;
    if ( LOBYTE(endFlag[4].myLen) != 0 )
    {
      v29 = *((_DWORD *)this + 16) >> 8;
      CatchDepth = this->CatchDepth;
      v60 = *(float *)a2 + dxSolidR;
      v108 = v29;
      v72 = dySolidR + *((float *)a2 + 1);
      if ( v29 >= *((_DWORD *)this + 17) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 8,
          result: v29,
          nb: v53);
        v29 = v108;
      }
      v30 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v29) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
      *(float *)v30 = v60;
      *(float *)(v30 + 4) = v72;
      *(_DWORD *)(v30 + 8) = CatchDepth;
      v31 = (*((_DWORD *)this + 16))++;
    }
    else
    {
      v31 = *((_DWORD *)this + 24);
    }
    *((_DWORD *)this + 25) = v31;
    if ( HIBYTE(endFlag[4].me) != 0 )
    {
      v61 = *(float *)a2 + solidWidthRa;
      v32 = solidWidthLa + *((float *)a2 + 1);
      v33 = *((_DWORD *)this + 16) >> 8;
      if ( v33 >= *((_DWORD *)this + 17) )
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 8,
          result: v33,
          nb: v53);
      v34 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v33) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
      *(float *)v34 = v61;
      v73 = v32;
      *(float *)(v34 + 4) = v73;
      *(_DWORD *)(v34 + 8) = -1;
      *((_DWORD *)this + 27) = (*((_DWORD *)this + 16))++;
      v7 = endFlag;
    }
    else
    {
      *((_DWORD *)this + 27) = v31;
      v7 = endFlag;
    }
  }
  if ( (BYTE2(v7[4].me) != 0 || HIBYTE(v7[4].me) != 0) && (LOBYTE(v7[4].me) != 0 || BYTE1(v7[4].me) != 0) )
  {
    v37 = *((_DWORD *)this + 20) >> 8;
    v77 = *((_DWORD *)this + 24);
    if ( v37 >= *((_DWORD *)this + 21) )
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 10,
        result: v37,
        nb: v53);
    v38 = (unsigned int *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v37) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
    *v38 = buttSolidL;
    v38[1] = buttSolidRa;
    v38[2] = v77;
    v39 = ++*((_DWORD *)this + 20) >> 8;
    v62 = *((_DWORD *)this + 24);
    v78 = *((_DWORD *)this + 25);
    if ( v39 >= *((_DWORD *)this + 21) )
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 10,
        result: v39,
        nb: v53);
    v40 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v39) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
    *v40 = v62;
    v40[1] = buttSolidRa;
    v40[2] = v78;
    ++*((_DWORD *)this + 20);
  }
  if ( aaFlagL )
  {
    v41 = *((_DWORD *)this + 20) >> 8;
    v63 = *((_DWORD *)this + 24);
    v74 = *((_DWORD *)this + 26);
    if ( v41 >= *((_DWORD *)this + 21) )
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 10,
        result: v41,
        nb: v53);
    v42 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v41) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
    *v42 = v63;
    v42[1] = v74;
    v42[2] = buttTotalL;
    v43 = ++*((_DWORD *)this + 20) >> 8;
    v64 = *((_DWORD *)this + 24);
    if ( v43 >= *((_DWORD *)this + 21) )
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 10,
        result: v43,
        nb: v53);
    v44 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v43) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
    *v44 = v64;
    v44[1] = buttTotalL;
    v44[2] = buttSolidL;
    ++*((_DWORD *)this + 20);
  }
  if ( aaFlagR )
  {
    v45 = this + 2;
    v46 = *((_DWORD *)this + 20) >> 8;
    v65 = *((_DWORD *)this + 25);
    v79 = *((_DWORD *)this + 27);
    if ( v46 >= *((_DWORD *)this + 21) )
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 10,
        result: v46,
        nb: v53);
    v47 = 3 * (unsigned __int8)v45->pNext;
    v48 = *(_DWORD *)(*((_DWORD *)this + 23) + 4 * v46);
    *(_DWORD *)(v48 + 4 * v47) = v65;
    v49 = v48 + 4 * v47;
    *(_DWORD *)(v49 + 4) = totalWidthR;
    *(_DWORD *)(v49 + 8) = v79;
    ++v45->pNext;
    v50 = *((_DWORD *)this + 25);
    v51 = (void *)((unsigned int)v45->pNext >> 8);
    if ( v51 >= v45->pFrameHandler )
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)v45,
        result: (unsigned int)v45->pNext >> 8,
        nb: v53);
    v52 = (_DWORD *)(*((_DWORD *)v45->pFuncInfo + (_DWORD)v51) + 12 * (unsigned __int8)v45->pNext);
    *v52 = v50;
    v52[1] = buttSolidRa;
    v52[2] = totalWidthR;
    ++v45->pNext;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10195880
// Name: private: void GStrokerAA::calcRoundCap(struct GStrokeVertexType const __near &,struct GStrokeVertexType const __near &,float,struct GStrokerAA::WidthsType const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStrokerAA::calcRoundCap(
        GStrokerAA *this,
        const struct GStrokeVertexType *newSolid,
        const struct GStrokeVertexType *xSolid,
        float a1,
        const struct GStrokerAA::WidthsType *endFlag,
        bool a6)
{
  const struct GStrokerAA::WidthsType *v7; // esi
  double v8; // st7
  double v10; // st7
  double v11; // st6
  double v12; // st5
  double v13; // st6
  int v14; // eax
  int v15; // edx
  unsigned int v16; // ecx
  int v17; // eax
  int v18; // eax
  int v19; // esi
  unsigned int v20; // ecx
  int v21; // eax
  double v22; // st7
  unsigned int v23; // ebx
  int v24; // eax
  unsigned int v25; // ebx
  int v26; // eax
  unsigned int v27; // ebx
  _DWORD *v28; // eax
  unsigned int v29; // ebx
  _DWORD *v30; // eax
  unsigned int v31; // ebx
  _DWORD *v32; // eax
  unsigned int v33; // ebx
  _DWORD *v34; // eax
  unsigned int v35; // ebx
  _DWORD *v36; // eax
  unsigned int v37; // ebx
  _DWORD *v38; // eax
  bool v39; // zf
  char v40; // [esp+0h] [ebp-94h]
  int v41; // [esp+Ch] [ebp-88h]
  int v42; // [esp+18h] [ebp-7Ch]
  int v43; // [esp+30h] [ebp-64h]
  int v44; // [esp+34h] [ebp-60h]
  int v45; // [esp+3Ch] [ebp-58h]
  int v46; // [esp+40h] [ebp-54h]
  int v47; // [esp+48h] [ebp-4Ch]
  int v48; // [esp+4Ch] [ebp-48h]
  int v49; // [esp+54h] [ebp-40h]
  int v50; // [esp+5Ch] [ebp-38h]
  float dxTotalR; // [esp+60h] [ebp-34h]
  float dxTotalRa; // [esp+60h] [ebp-34h]
  float cyTotal; // [esp+64h] [ebp-30h]
  float cyTotala; // [esp+64h] [ebp-30h]
  double v55; // [esp+68h] [ebp-2Ch]
  void *totalWidthL; // [esp+6Ch] [ebp-28h]
  float totalWidthLa; // [esp+6Ch] [ebp-28h]
  float dxSolidR; // [esp+70h] [ebp-24h]
  float dxSolidRa; // [esp+70h] [ebp-24h]
  float cySolid; // [esp+74h] [ebp-20h]
  float cySolida; // [esp+74h] [ebp-20h]
  float v62; // [esp+78h] [ebp-1Ch]
  float v63; // [esp+78h] [ebp-1Ch]
  float v64; // [esp+7Ch] [ebp-18h]
  float v65; // [esp+7Ch] [ebp-18h]
  EHRegistrationNode *pRN; // [esp+80h] [ebp-14h]
  float dySolidL; // [esp+84h] [ebp-10h]
  int dySolidLa; // [esp+84h] [ebp-10h]
  void *yTotal; // [esp+88h] [ebp-Ch]
  float yTotala; // [esp+88h] [ebp-Ch]
  float yTotalb; // [esp+88h] [ebp-Ch]
  void *xTotal; // [esp+8Ch] [ebp-8h]
  unsigned int xTotala; // [esp+8Ch] [ebp-8h]
  unsigned int xTotalb; // [esp+8Ch] [ebp-8h]
  float xTotalc; // [esp+8Ch] [ebp-8h]
  float ySolidb; // [esp+90h] [ebp-4h]
  float ySolidc; // [esp+90h] [ebp-4h]
  float ySolidd; // [esp+90h] [ebp-4h]
  float ySolide; // [esp+90h] [ebp-4h]
  float ySolidf; // [esp+90h] [ebp-4h]
  int ySolid; // [esp+90h] [ebp-4h]
  float ySolida; // [esp+90h] [ebp-4h]
  float newSolidd; // [esp+9Ch] [ebp+8h]
  float newSolida; // [esp+9Ch] [ebp+8h]
  float newSolide; // [esp+9Ch] [ebp+8h]
  EHRegistrationNode *newSolidb; // [esp+9Ch] [ebp+8h]
  unsigned int newSolidc; // [esp+9Ch] [ebp+8h]
  float xSolidd; // [esp+A0h] [ebp+Ch]
  float xSolida; // [esp+A0h] [ebp+Ch]
  float xSolide; // [esp+A0h] [ebp+Ch]
  float xSolidb; // [esp+A0h] [ebp+Ch]
  unsigned int xSolidc; // [esp+A0h] [ebp+Ch]
  float a1b; // [esp+A4h] [ebp+10h]
  float a1a; // [esp+A4h] [ebp+10h]

  v7 = endFlag;
  if ( a6 )
  {
    yTotal = endFlag->me;
    xTotal = endFlag->__vftable;
    totalWidthL = endFlag[1].me;
    v8 = *(float *)&endFlag[1].__vftable;
  }
  else
  {
    yTotal = endFlag->__vftable;
    xTotal = endFlag->me;
    totalWidthL = endFlag[1].__vftable;
    v8 = *(float *)&endFlag[1].me;
  }
  ySolidb = v8;
  newSolidd = (*((float *)xSolid + 1) - *((float *)newSolid + 1)) / a1;
  xSolidd = (*(float *)newSolid - *(float *)xSolid) / a1;
  v10 = newSolidd;
  v11 = *(float *)&yTotal;
  yTotala = newSolidd * *(float *)&yTotal;
  v12 = v11 * xSolidd;
  v13 = xSolidd;
  dySolidL = v12;
  dxSolidR = newSolidd * *(float *)&xTotal;
  cySolid = *(float *)&xTotal * xSolidd;
  newSolida = newSolidd * *(float *)&totalWidthL;
  xSolida = *(float *)&totalWidthL * xSolidd;
  dxTotalR = v10 * ySolidb;
  cyTotal = ySolidb * v13;
  a1b = atan2(-xSolida, -newSolida);
  ySolidc = a1b + 3.141592741012573;
  v55 = ySolidc - a1b;
  ySolidd = *(float *)&endFlag[1].myLen / (*((float *)this + 10) * 0.25 + *(float *)&endFlag[1].myLen);
  ySolide = acos(ySolidd);
  ySolidf = ySolide + ySolide;
  v14 = (int)(v55 / ySolidf) + 1;
  ySolid = v14;
  totalWidthLa = v55 / (double)v14;
  a1a = totalWidthLa + a1b;
  if ( a6 )
  {
    v15 = *((_DWORD *)this + 27);
    *((_DWORD *)this + 24) = *((_DWORD *)this + 25);
    *((_DWORD *)this + 26) = v15;
  }
  else
  {
    v16 = *((_DWORD *)this + 16) >> 8;
    pRN = this->pRN;
    v62 = *(float *)newSolid - yTotala;
    xTotala = v16;
    v64 = *((float *)newSolid + 1) - dySolidL;
    if ( v16 >= *((_DWORD *)this + 17) )
    {
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 8,
        result: v16,
        nb: v40);
      v16 = xTotala;
    }
    v17 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v16) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
    *(float *)v17 = v62;
    *(float *)(v17 + 4) = v64;
    *(_DWORD *)(v17 + 8) = pRN;
    v18 = (*((_DWORD *)this + 16))++;
    *((_DWORD *)this + 25) = v18;
    *((_DWORD *)this + 24) = v18;
    if ( BYTE2(endFlag[4].me) != 0 || HIBYTE(endFlag[4].me) != 0 )
    {
      v20 = *((_DWORD *)this + 16) >> 8;
      xTotalb = v20;
      v63 = *(float *)newSolid - newSolida;
      v65 = *((float *)newSolid + 1) - xSolida;
      if ( v20 >= *((_DWORD *)this + 17) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 8,
          result: v20,
          nb: v40);
        v20 = xTotalb;
      }
      v21 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v20) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
      *(float *)v21 = v63;
      *(float *)(v21 + 4) = v65;
      *(_DWORD *)(v21 + 8) = -1;
      v19 = (*((_DWORD *)this + 16))++;
    }
    else
    {
      v19 = v18;
    }
    v14 = ySolid;
    *((_DWORD *)this + 27) = v19;
    *((_DWORD *)this + 26) = v19;
    v7 = endFlag;
  }
  dxTotalRa = (dxTotalR - newSolida) * 0.5 + *(float *)newSolid;
  cyTotala = (cyTotal - xSolida) * 0.5 + *((float *)newSolid + 1);
  dxSolidRa = (dxSolidR - yTotala) * 0.5 + *(float *)newSolid;
  cySolida = 0.5 * (cySolid - dySolidL) + *((float *)newSolid + 1);
  if ( v14 > 0 )
  {
    dySolidLa = v14;
    do
    {
      newSolide = cos(a1a);
      xSolide = sin(a1a);
      xTotalc = *(float *)&v7[1].myLen * newSolide + dxTotalRa;
      yTotalb = *(float *)&v7[1].myLen * xSolide + cyTotala;
      v22 = xSolide;
      xSolidb = newSolide * *(float *)&v7->myLen + dxSolidRa;
      ySolida = v22 * *(float *)&v7->myLen + cySolida;
      if ( LOBYTE(v7[4].myLen) != 0 )
      {
        if ( a6 )
          newSolidb = this->pRN;
        else
          newSolidb = (EHRegistrationNode *)this->CatchDepth;
        v23 = *((_DWORD *)this + 16) >> 8;
        if ( v23 >= *((_DWORD *)this + 17) )
          GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
            this: (DName *)this + 8,
            result: v23,
            nb: v40);
        v24 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v23) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
        *(float *)v24 = xSolidb;
        *(float *)(v24 + 4) = ySolida;
        *(_DWORD *)(v24 + 8) = newSolidb;
        newSolidc = (*((_DWORD *)this + 16))++;
        v7 = endFlag;
      }
      else
      {
        newSolidc = *((_DWORD *)this + 24);
      }
      if ( BYTE2(v7[4].me) != 0 || HIBYTE(v7[4].me) != 0 )
      {
        v25 = *((_DWORD *)this + 16) >> 8;
        if ( v25 >= *((_DWORD *)this + 17) )
          GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
            this: (DName *)this + 8,
            result: v25,
            nb: v40);
        v26 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v25) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
        *(float *)v26 = xTotalc;
        *(float *)(v26 + 4) = yTotalb;
        *(_DWORD *)(v26 + 8) = -1;
        xSolidc = (*((_DWORD *)this + 16))++;
        v7 = endFlag;
      }
      else
      {
        xSolidc = newSolidc;
      }
      if ( a6 )
      {
        if ( LOBYTE(v7[4].me) != 0 || BYTE1(v7[4].me) != 0 )
        {
          v27 = *((_DWORD *)this + 20) >> 8;
          v49 = *((_DWORD *)this + 24);
          v50 = *((_DWORD *)this + 25);
          if ( v27 >= *((_DWORD *)this + 21) )
            GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
              this: (DName *)this + 10,
              result: v27,
              nb: v40);
          v7 = endFlag;
          v28 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v27) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
          *v28 = v49;
          v28[1] = newSolidc;
          v28[2] = v50;
          ++*((_DWORD *)this + 20);
        }
        if ( BYTE2(v7[4].me) != 0 || HIBYTE(v7[4].me) != 0 )
        {
          v29 = *((_DWORD *)this + 20) >> 8;
          v43 = *((_DWORD *)this + 24);
          v44 = *((_DWORD *)this + 26);
          if ( v29 >= *((_DWORD *)this + 21) )
            GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
              this: (DName *)this + 10,
              result: v29,
              nb: v40);
          v30 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v29) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
          *v30 = v43;
          v30[1] = v44;
          v30[2] = xSolidc;
          v31 = ++*((_DWORD *)this + 20) >> 8;
          v42 = *((_DWORD *)this + 24);
          if ( v31 >= *((_DWORD *)this + 21) )
            GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
              this: (DName *)this + 10,
              result: v31,
              nb: v40);
          v7 = endFlag;
          v32 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v31) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
          *v32 = v42;
          v32[1] = xSolidc;
          v32[2] = newSolidc;
          ++*((_DWORD *)this + 20);
        }
        *((_DWORD *)this + 24) = newSolidc;
        *((_DWORD *)this + 26) = xSolidc;
      }
      else
      {
        if ( LOBYTE(v7[4].me) != 0 || BYTE1(v7[4].me) != 0 )
        {
          v33 = *((_DWORD *)this + 20) >> 8;
          v47 = *((_DWORD *)this + 24);
          v48 = *((_DWORD *)this + 25);
          if ( v33 >= *((_DWORD *)this + 21) )
            GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
              this: (DName *)this + 10,
              result: v33,
              nb: v40);
          v7 = endFlag;
          v34 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v33) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
          *v34 = v47;
          v34[1] = v48;
          v34[2] = newSolidc;
          ++*((_DWORD *)this + 20);
        }
        if ( BYTE2(v7[4].me) != 0 || HIBYTE(v7[4].me) != 0 )
        {
          v35 = *((_DWORD *)this + 20) >> 8;
          v45 = *((_DWORD *)this + 25);
          v46 = *((_DWORD *)this + 27);
          if ( v35 >= *((_DWORD *)this + 21) )
            GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
              this: (DName *)this + 10,
              result: v35,
              nb: v40);
          v36 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v35) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
          *v36 = v45;
          v36[1] = v46;
          v36[2] = xSolidc;
          v37 = ++*((_DWORD *)this + 20) >> 8;
          v41 = *((_DWORD *)this + 25);
          if ( v37 >= *((_DWORD *)this + 21) )
            GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
              this: (DName *)this + 10,
              result: v37,
              nb: v40);
          v7 = endFlag;
          v38 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v37) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
          *v38 = v41;
          v38[1] = xSolidc;
          v38[2] = newSolidc;
          ++*((_DWORD *)this + 20);
        }
        *((_DWORD *)this + 25) = newSolidc;
        *((_DWORD *)this + 27) = xSolidc;
      }
      v39 = dySolidLa-- == 1;
      a1a = totalWidthLa + a1a;
    }
    while ( !v39 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10195E60
// Name: private: void GStrokerAA::calcRoundJoin(struct GStrokeVertexType const __near &,struct GStrokerAA::WidthsType const __near &,struct GStrokerAA::JoinParamType const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStrokerAA::calcRoundJoin(
        GStrokerAA *this,
        const struct GStrokeVertexType *a2,
        FrameInfo *p,
        const struct GStrokerAA::JoinParamType *n)
{
  float *v4; // ebx
  double v6; // st7
  double v7; // st7
  unsigned int v8; // ecx
  int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ecx
  int v17; // eax
  unsigned int v18; // ecx
  _DWORD *v19; // eax
  unsigned int v20; // ecx
  _DWORD *v21; // eax
  unsigned int v22; // ecx
  _DWORD *v23; // eax
  unsigned int v24; // ecx
  _DWORD *v25; // eax
  unsigned int v26; // ecx
  _DWORD *v27; // eax
  unsigned int v28; // ecx
  _DWORD *v29; // eax
  unsigned int v30; // ecx
  int v31; // eax
  EHRegistrationNode *v32; // eax
  double v33; // st6
  double v34; // st6
  double v35; // st7
  unsigned int v36; // ebx
  int v37; // eax
  unsigned int v38; // eax
  unsigned int v39; // ebx
  int v40; // eax
  unsigned int v41; // ecx
  _DWORD *v42; // eax
  unsigned int v43; // ecx
  _DWORD *v44; // eax
  unsigned int v45; // ecx
  _DWORD *v46; // eax
  bool v47; // zf
  double v48; // st7
  double v49; // st7
  unsigned int v50; // ecx
  int v51; // eax
  unsigned int v52; // eax
  unsigned int v53; // ecx
  int v54; // eax
  unsigned int v55; // ecx
  int v56; // eax
  unsigned int v57; // eax
  unsigned int v58; // ecx
  int v59; // eax
  unsigned int v60; // ecx
  _DWORD *v61; // eax
  unsigned int v62; // ecx
  _DWORD *v63; // eax
  unsigned int v64; // ecx
  _DWORD *v65; // eax
  unsigned int v66; // ecx
  _DWORD *v67; // eax
  unsigned int v68; // ecx
  _DWORD *v69; // eax
  unsigned int v70; // ecx
  _DWORD *v71; // eax
  unsigned int v72; // ecx
  int v73; // eax
  EHRegistrationNode *v74; // eax
  double v75; // st6
  double v76; // st6
  double v77; // st7
  unsigned int v78; // ebx
  int v79; // eax
  unsigned int v80; // eax
  unsigned int v81; // ebx
  int v82; // eax
  unsigned int v83; // ecx
  _DWORD *v84; // eax
  unsigned int v85; // ecx
  _DWORD *v86; // eax
  unsigned int v87; // ecx
  _DWORD *v88; // eax
  float v89; // [esp+4h] [ebp-7Ch]
  float v90; // [esp+4h] [ebp-7Ch]
  char v91; // [esp+Ch] [ebp-74h]
  int v92; // [esp+18h] [ebp-68h]
  int v93; // [esp+18h] [ebp-68h]
  int v94; // [esp+18h] [ebp-68h]
  int v95; // [esp+18h] [ebp-68h]
  int v96; // [esp+18h] [ebp-68h]
  int v97; // [esp+24h] [ebp-5Ch]
  int v98; // [esp+24h] [ebp-5Ch]
  int v99; // [esp+24h] [ebp-5Ch]
  int v100; // [esp+24h] [ebp-5Ch]
  float v101; // [esp+24h] [ebp-5Ch]
  int v102; // [esp+24h] [ebp-5Ch]
  int v103; // [esp+24h] [ebp-5Ch]
  int v104; // [esp+24h] [ebp-5Ch]
  float v105; // [esp+24h] [ebp-5Ch]
  float v106; // [esp+28h] [ebp-58h]
  float v107; // [esp+28h] [ebp-58h]
  int v108; // [esp+2Ch] [ebp-54h]
  int v109; // [esp+2Ch] [ebp-54h]
  int v110; // [esp+2Ch] [ebp-54h]
  int v111; // [esp+2Ch] [ebp-54h]
  int v112; // [esp+30h] [ebp-50h]
  int v113; // [esp+30h] [ebp-50h]
  int v114; // [esp+34h] [ebp-4Ch]
  int v115; // [esp+38h] [ebp-48h]
  float v116; // [esp+3Ch] [ebp-44h]
  int v117; // [esp+3Ch] [ebp-44h]
  float v118; // [esp+40h] [ebp-40h]
  int v119; // [esp+40h] [ebp-40h]
  float v120; // [esp+48h] [ebp-38h]
  float v121; // [esp+48h] [ebp-38h]
  int v122; // [esp+48h] [ebp-38h]
  int v123; // [esp+48h] [ebp-38h]
  int v124; // [esp+48h] [ebp-38h]
  float v125; // [esp+48h] [ebp-38h]
  float v126; // [esp+48h] [ebp-38h]
  float v127; // [esp+48h] [ebp-38h]
  float v128; // [esp+48h] [ebp-38h]
  float v129; // [esp+48h] [ebp-38h]
  float v130; // [esp+4Ch] [ebp-34h]
  float v131; // [esp+4Ch] [ebp-34h]
  float v132; // [esp+4Ch] [ebp-34h]
  int v133; // [esp+4Ch] [ebp-34h]
  int v134; // [esp+4Ch] [ebp-34h]
  int v135; // [esp+4Ch] [ebp-34h]
  float v136; // [esp+4Ch] [ebp-34h]
  float v137; // [esp+4Ch] [ebp-34h]
  float v138; // [esp+4Ch] [ebp-34h]
  float v139; // [esp+4Ch] [ebp-34h]
  float v140; // [esp+4Ch] [ebp-34h]
  float v141; // [esp+4Ch] [ebp-34h]
  EHRegistrationNode *pRN; // [esp+50h] [ebp-30h]
  int CatchDepth; // [esp+50h] [ebp-30h]
  int v144; // [esp+50h] [ebp-30h]
  EHRegistrationNode *v145; // [esp+50h] [ebp-30h]
  int v146; // [esp+50h] [ebp-30h]
  EHRegistrationNode *v147; // [esp+50h] [ebp-30h]
  EHRegistrationNode *v148; // [esp+50h] [ebp-30h]
  int v149; // [esp+50h] [ebp-30h]
  double v150; // [esp+54h] [ebp-2Ch]
  double v151; // [esp+54h] [ebp-2Ch]
  float ySolid; // [esp+58h] [ebp-28h]
  unsigned int ySolida; // [esp+58h] [ebp-28h]
  unsigned int ySolidb; // [esp+58h] [ebp-28h]
  unsigned int ySolidc; // [esp+58h] [ebp-28h]
  unsigned int ySolidd; // [esp+58h] [ebp-28h]
  unsigned int ySolide; // [esp+58h] [ebp-28h]
  unsigned int ySolidf; // [esp+58h] [ebp-28h]
  unsigned int ySolidg; // [esp+58h] [ebp-28h]
  unsigned int ySolidh; // [esp+58h] [ebp-28h]
  unsigned int ySolidi; // [esp+58h] [ebp-28h]
  float ySolidx; // [esp+58h] [ebp-28h]
  float ySolidy; // [esp+58h] [ebp-28h]
  float ySolidz; // [esp+58h] [ebp-28h]
  float ySolidj; // [esp+58h] [ebp-28h]
  int ySolidk; // [esp+58h] [ebp-28h]
  float ySolidl; // [esp+58h] [ebp-28h]
  unsigned int ySolidm; // [esp+58h] [ebp-28h]
  unsigned int ySolidn; // [esp+58h] [ebp-28h]
  unsigned int ySolido; // [esp+58h] [ebp-28h]
  unsigned int ySolidp; // [esp+58h] [ebp-28h]
  unsigned int ySolidq; // [esp+58h] [ebp-28h]
  unsigned int ySolidr; // [esp+58h] [ebp-28h]
  unsigned int ySolids; // [esp+58h] [ebp-28h]
  unsigned int ySolidt; // [esp+58h] [ebp-28h]
  unsigned int ySolidu; // [esp+58h] [ebp-28h]
  float ySolidba; // [esp+58h] [ebp-28h]
  float ySolidbb; // [esp+58h] [ebp-28h]
  float ySolidbc; // [esp+58h] [ebp-28h]
  float ySolidv; // [esp+58h] [ebp-28h]
  int ySolidw; // [esp+58h] [ebp-28h]
  double v182; // [esp+5Ch] [ebp-24h]
  double v183; // [esp+5Ch] [ebp-24h]
  float xSolid; // [esp+60h] [ebp-20h]
  float xSolida; // [esp+60h] [ebp-20h]
  float xSolidb; // [esp+60h] [ebp-20h]
  float xSolidc; // [esp+60h] [ebp-20h]
  float dy; // [esp+64h] [ebp-1Ch]
  float dya; // [esp+64h] [ebp-1Ch]
  float dyb; // [esp+64h] [ebp-1Ch]
  float dyc; // [esp+64h] [ebp-1Ch]
  unsigned int newTotalR; // [esp+68h] [ebp-18h]
  unsigned int newTotalRa; // [esp+68h] [ebp-18h]
  unsigned int newTotalRb; // [esp+68h] [ebp-18h]
  unsigned int newTotalRc; // [esp+68h] [ebp-18h]
  unsigned int newTotalRd; // [esp+68h] [ebp-18h]
  unsigned int newTotalRe; // [esp+68h] [ebp-18h]
  unsigned int newTotalRf; // [esp+68h] [ebp-18h]
  unsigned int newTotalL; // [esp+6Ch] [ebp-14h]
  unsigned int newTotalLa; // [esp+6Ch] [ebp-14h]
  unsigned int newTotalLb; // [esp+6Ch] [ebp-14h]
  float a1; // [esp+70h] [ebp-10h]
  float a1a; // [esp+70h] [ebp-10h]
  float a1b; // [esp+70h] [ebp-10h]
  float a1c; // [esp+70h] [ebp-10h]
  float a1d; // [esp+70h] [ebp-10h]
  float a1e; // [esp+70h] [ebp-10h]
  unsigned int newSolidR; // [esp+74h] [ebp-Ch]
  unsigned int newSolidRa; // [esp+74h] [ebp-Ch]
  unsigned int newSolidL; // [esp+78h] [ebp-8h]
  unsigned int newSolidLa; // [esp+78h] [ebp-8h]
  char overlap; // [esp+7Fh] [ebp-1h]
  float ni; // [esp+90h] [ebp+10h]
  float nj; // [esp+90h] [ebp+10h]
  float nk; // [esp+90h] [ebp+10h]
  float nl; // [esp+90h] [ebp+10h]
  float nm; // [esp+90h] [ebp+10h]
  const struct GStrokerAA::JoinParamType *nn; // [esp+90h] [ebp+10h]
  float na; // [esp+90h] [ebp+10h]
  const struct GStrokerAA::JoinParamType *nb; // [esp+90h] [ebp+10h]
  const struct GStrokerAA::JoinParamType *nc; // [esp+90h] [ebp+10h]
  const struct GStrokerAA::JoinParamType *nd; // [esp+90h] [ebp+10h]
  float no; // [esp+90h] [ebp+10h]
  float np; // [esp+90h] [ebp+10h]
  float nq; // [esp+90h] [ebp+10h]
  float nr; // [esp+90h] [ebp+10h]
  float ns; // [esp+90h] [ebp+10h]
  const struct GStrokerAA::JoinParamType *nt; // [esp+90h] [ebp+10h]
  float ne; // [esp+90h] [ebp+10h]
  const struct GStrokerAA::JoinParamType *nf; // [esp+90h] [ebp+10h]
  const struct GStrokerAA::JoinParamType *ng; // [esp+90h] [ebp+10h]
  const struct GStrokerAA::JoinParamType *nh; // [esp+90h] [ebp+10h]

  v4 = (float *)a2;
  overlap = *((_BYTE *)n + 217) | *((_BYTE *)n + 218);
  if ( *((_BYTE *)n + 215) != 0 )
  {
    if ( *(_WORD *)((char *)n + 217) != 0 )
      v6 = *((float *)n + 14) + *(float *)a2;
    else
      v6 = *((float *)n + 36);
    a1 = v6;
    if ( *(_WORD *)((char *)n + 217) != 0 )
      v7 = *((float *)n + 15) + *((float *)a2 + 1);
    else
      v7 = *((float *)n + 37);
    dy = v7;
    xSolid = (a1 - *(float *)a2) * *(float *)&p[4].pExceptionObject + *(float *)a2;
    v8 = *((_DWORD *)this + 16) >> 8;
    newTotalR = v8;
    ySolid = (dy - *((float *)a2 + 1)) * *(float *)&p[4].pExceptionObject + *((float *)a2 + 1);
    v120 = *(float *)a2 - *(float *)n;
    pRN = this->pRN;
    v130 = *((float *)a2 + 1) - *((float *)n + 1);
    if ( v8 >= *((_DWORD *)this + 17) )
    {
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 8,
        result: v8,
        nb: v91);
      v8 = newTotalR;
    }
    v9 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v8) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
    *(float *)v9 = v120;
    *(float *)(v9 + 4) = v130;
    *(_DWORD *)(v9 + 8) = pRN;
    v10 = (*((_DWORD *)this + 16))++;
    newSolidL = v10;
    if ( BYTE2(p[6].pNext) != 0 )
    {
      v11 = *((_DWORD *)this + 16) >> 8;
      newTotalRa = v11;
      v121 = *(float *)a2 - *((float *)n + 2);
      v131 = *((float *)a2 + 1) - *((float *)n + 3);
      if ( v11 >= *((_DWORD *)this + 17) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 8,
          result: v11,
          nb: v91);
        v11 = newTotalRa;
      }
      v12 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v11) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
      *(float *)v12 = v121;
      *(float *)(v12 + 4) = v131;
      *(_DWORD *)(v12 + 8) = -1;
      v10 = (*((_DWORD *)this + 16))++;
    }
    newTotalL = v10;
    if ( LOBYTE(p[7].pExceptionObject) != 0 )
    {
      v13 = *((_DWORD *)this + 16) >> 8;
      v132 = ySolid;
      CatchDepth = this->CatchDepth;
      ySolida = v13;
      if ( v13 >= *((_DWORD *)this + 17) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 8,
          result: v13,
          nb: v91);
        v13 = ySolida;
      }
      v14 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v13) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
      *(float *)v14 = xSolid;
      *(float *)(v14 + 4) = v132;
      *(_DWORD *)(v14 + 8) = CatchDepth;
      v15 = (*((_DWORD *)this + 16))++;
    }
    else
    {
      v15 = newSolidL;
    }
    newSolidR = v15;
    if ( HIBYTE(p[6].pNext) != 0 )
    {
      v16 = *((_DWORD *)this + 16) >> 8;
      ySolidb = v16;
      if ( v16 >= *((_DWORD *)this + 17) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 8,
          result: v16,
          nb: v91);
        v16 = ySolidb;
      }
      v17 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v16) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
      *(float *)v17 = a1;
      *(float *)(v17 + 4) = dy;
      *(_DWORD *)(v17 + 8) = -1;
      v15 = (*((_DWORD *)this + 16))++;
    }
    newTotalRb = v15;
    if ( LOBYTE(p[6].pNext) != 0 || BYTE1(p[6].pNext) != 0 )
    {
      v18 = *((_DWORD *)this + 20) >> 8;
      v97 = *((_DWORD *)this + 24);
      ySolidc = v18;
      if ( v18 >= *((_DWORD *)this + 21) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 10,
          result: v18,
          nb: v91);
        v18 = ySolidc;
      }
      v19 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v18) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
      *v19 = v97;
      v19[1] = newSolidR;
      v19[2] = newSolidL;
      ++*((_DWORD *)this + 20);
      v133 = *((_DWORD *)this + 25);
      v20 = *((_DWORD *)this + 20) >> 8;
      v122 = *((_DWORD *)this + 24);
      ySolidd = v20;
      if ( v20 >= *((_DWORD *)this + 21) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 10,
          result: v20,
          nb: v91);
        v20 = ySolidd;
      }
      v21 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v20) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
      *v21 = v122;
      v21[1] = v133;
      v21[2] = newSolidR;
      ++*((_DWORD *)this + 20);
    }
    if ( BYTE2(p[6].pNext) != 0 )
    {
      v123 = *((_DWORD *)this + 26);
      v22 = *((_DWORD *)this + 20) >> 8;
      v134 = *((_DWORD *)this + 24);
      ySolide = v22;
      if ( v22 >= *((_DWORD *)this + 21) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 10,
          result: v22,
          nb: v91);
        v22 = ySolide;
      }
      v23 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v22) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
      *v23 = v123;
      v23[1] = v134;
      v23[2] = newSolidL;
      v24 = ++*((_DWORD *)this + 20) >> 8;
      v98 = *((_DWORD *)this + 26);
      ySolidf = v24;
      if ( v24 >= *((_DWORD *)this + 21) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 10,
          result: v24,
          nb: v91);
        v24 = ySolidf;
      }
      v4 = (float *)a2;
      v25 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v24) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
      *v25 = v98;
      v25[1] = newSolidL;
      v25[2] = newTotalL;
      ++*((_DWORD *)this + 20);
    }
    if ( HIBYTE(p[6].pNext) != 0 )
    {
      v99 = *((_DWORD *)this + 25);
      v26 = *((_DWORD *)this + 20) >> 8;
      ySolidg = v26;
      if ( v26 >= *((_DWORD *)this + 21) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 10,
          result: v26,
          nb: v91);
        v26 = ySolidg;
      }
      v27 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v26) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
      *v27 = v99;
      v27[1] = newTotalRb;
      v27[2] = newSolidR;
      ++*((_DWORD *)this + 20);
      v135 = *((_DWORD *)this + 27);
      v28 = *((_DWORD *)this + 20) >> 8;
      v124 = *((_DWORD *)this + 25);
      ySolidh = v28;
      if ( v28 >= *((_DWORD *)this + 21) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 10,
          result: v28,
          nb: v91);
        v28 = ySolidh;
      }
      v4 = (float *)a2;
      v29 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v28) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
      *v29 = v124;
      v29[1] = v135;
      v29[2] = newTotalRb;
      ++*((_DWORD *)this + 20);
    }
    *((_DWORD *)this + 24) = newSolidL;
    *((_DWORD *)this + 26) = newTotalL;
    *((_DWORD *)this + 25) = newSolidR;
    *((_DWORD *)this + 27) = newTotalRb;
    if ( overlap != 0 )
    {
      v144 = this->CatchDepth;
      v30 = *((_DWORD *)this + 16) >> 8;
      v125 = *((float *)n + 16) + *v4;
      ySolidi = v30;
      v136 = *((float *)n + 17) + v4[1];
      if ( v30 >= *((_DWORD *)this + 17) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 8,
          result: v30,
          nb: v91);
        v30 = ySolidi;
      }
      v31 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v30) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
      *(float *)v31 = v125;
      *(float *)(v31 + 4) = v136;
      *(_DWORD *)(v31 + 8) = v144;
      *((_DWORD *)this + 25) = (*((_DWORD *)this + 16))++;
      if ( HIBYTE(p[6].pNext) != 0 )
      {
        ySolidx = *((float *)n + 19) + v4[1];
        v89 = ySolidx;
        ySolidy = *((float *)n + 18) + *v4;
        v32 = GStrokerAA::addVertex(this, a2: (char)this, x: ySolidy, y: v89, id: -1);
      }
      else
      {
        v32 = (EHRegistrationNode *)newSolidR;
      }
      *((_DWORD *)this + 27) = v32;
    }
    v182 = *((float *)this + 10) * 0.25;
    ySolidz = 0.25 * v182;
    if ( ySolidz < *(float *)&p[1].pNext - *((float *)n + 25) )
    {
      ySolidj = atan2(-*((float *)n + 3), -*((float *)n + 2));
      a1a = ySolidj;
      ni = atan2(-*((float *)n + 7), -*((float *)n + 6));
      v33 = ni;
      if ( ni > (double)ySolidj )
      {
        nj = v33 - 6.283185482025146;
        v33 = nj;
      }
      v150 = ySolidj - v33;
      nk = *(float *)&p[1].pNext / (v182 + *(float *)&p[1].pNext);
      nl = acos(nk);
      nm = nl + nl;
      v34 = v150 / nm;
      nn = (const struct GStrokerAA::JoinParamType *)((int)v34 + 1);
      xSolida = v150 / (double)(int)nn;
      a1b = a1a - xSolida;
      if ( (int)nn > 0 )
      {
        ySolidk = (int)v34 + 1;
        while ( 1 )
        {
          na = cos(a1b);
          dya = sin(a1b);
          if ( LOBYTE(p[7].pExceptionObject) != 0 )
          {
            v126 = *(float *)&p->pExceptionObject * na + *v4;
            v145 = this->pRN;
            v35 = *(float *)&p->pExceptionObject * dya + v4[1];
            v36 = *((_DWORD *)this + 16) >> 8;
            if ( v36 >= *((_DWORD *)this + 17) )
              GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
                this: (DName *)this + 8,
                result: v36,
                nb: v91);
            v37 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v36) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
            *(float *)v37 = v126;
            v137 = v35;
            *(float *)(v37 + 4) = v137;
            *(_DWORD *)(v37 + 8) = v145;
            v38 = (*((_DWORD *)this + 16))++;
            newSolidL = v38;
          }
          else
          {
            v38 = newSolidL;
          }
          if ( BYTE2(p[6].pNext) != 0 )
          {
            v39 = *((_DWORD *)this + 16) >> 8;
            v116 = *(float *)&p[1].pNext * na + *(float *)a2;
            v118 = *(float *)&p[1].pNext * dya + *((float *)a2 + 1);
            if ( v39 >= *((_DWORD *)this + 17) )
              GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
                this: (DName *)this + 8,
                result: v39,
                nb: v91);
            v40 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v39) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
            *(float *)v40 = v116;
            *(float *)(v40 + 4) = v118;
            *(_DWORD *)(v40 + 8) = -1;
            v38 = (*((_DWORD *)this + 16))++;
          }
          newTotalLa = v38;
          if ( LOBYTE(p[6].pNext) != 0 )
          {
            v41 = *((_DWORD *)this + 20) >> 8;
            v112 = *((_DWORD *)this + 25);
            v115 = *((_DWORD *)this + 24);
            nb = (const struct GStrokerAA::JoinParamType *)v41;
            if ( v41 >= *((_DWORD *)this + 21) )
            {
              GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
                this: (DName *)this + 10,
                result: v41,
                nb: v91);
              v41 = (unsigned int)nb;
            }
            v42 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v41) + 12
                                                                           * (unsigned __int8)*((_DWORD *)this + 20));
            *v42 = v112;
            v42[1] = newSolidL;
            v42[2] = v115;
            ++*((_DWORD *)this + 20);
            v38 = newTotalLa;
          }
          if ( BYTE2(p[6].pNext) != 0 )
          {
            v43 = *((_DWORD *)this + 20) >> 8;
            v100 = *((_DWORD *)this + 24);
            v108 = *((_DWORD *)this + 26);
            nc = (const struct GStrokerAA::JoinParamType *)v43;
            if ( v43 >= *((_DWORD *)this + 21) )
            {
              GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
                this: (DName *)this + 10,
                result: v43,
                nb: v91);
              v43 = (unsigned int)nc;
            }
            v44 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v43) + 12
                                                                           * (unsigned __int8)*((_DWORD *)this + 20));
            *v44 = v100;
            v44[1] = newSolidL;
            v44[2] = v108;
            v45 = ++*((_DWORD *)this + 20) >> 8;
            v92 = *((_DWORD *)this + 26);
            nd = (const struct GStrokerAA::JoinParamType *)v45;
            if ( v45 >= *((_DWORD *)this + 21) )
            {
              GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
                this: (DName *)this + 10,
                result: v45,
                nb: v91);
              v45 = (unsigned int)nd;
            }
            v46 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v45) + 12
                                                                           * (unsigned __int8)*((_DWORD *)this + 20));
            *v46 = v92;
            v46[1] = newSolidL;
            v46[2] = newTotalLa;
            ++*((_DWORD *)this + 20);
            v38 = newTotalLa;
          }
          v47 = ySolidk-- == 1;
          *((_DWORD *)this + 24) = newSolidL;
          *((_DWORD *)this + 26) = v38;
          a1b = a1b - xSolida;
          if ( v47 )
            break;
          v4 = (float *)a2;
        }
      }
    }
  }
  else
  {
    if ( *(_WORD *)((char *)n + 217) != 0 )
      v48 = *(float *)a2 - *((float *)n + 2);
    else
      v48 = *((float *)n + 34);
    a1c = v48;
    if ( *(_WORD *)((char *)n + 217) != 0 )
      v49 = *((float *)a2 + 1) - *((float *)n + 3);
    else
      v49 = *((float *)n + 35);
    dyb = v49;
    v146 = this->CatchDepth;
    xSolidb = (a1c - *(float *)a2) * *(float *)&p[3].pNext + *(float *)a2;
    v50 = *((_DWORD *)this + 16) >> 8;
    newTotalRc = v50;
    ySolidl = (dyb - *((float *)a2 + 1)) * *(float *)&p[3].pNext + *((float *)a2 + 1);
    v127 = *((float *)n + 12) + *(float *)a2;
    v138 = *((float *)n + 13) + *((float *)a2 + 1);
    if ( v50 >= *((_DWORD *)this + 17) )
    {
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 8,
        result: v50,
        nb: v91);
      v50 = newTotalRc;
    }
    v51 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v50) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
    *(float *)v51 = v127;
    *(float *)(v51 + 4) = v138;
    *(_DWORD *)(v51 + 8) = v146;
    v52 = (*((_DWORD *)this + 16))++;
    newSolidRa = v52;
    if ( HIBYTE(p[6].pNext) != 0 )
    {
      v53 = *((_DWORD *)this + 16) >> 8;
      newTotalRd = v53;
      v101 = *((float *)n + 14) + *(float *)a2;
      v106 = *((float *)n + 15) + *((float *)a2 + 1);
      if ( v53 >= *((_DWORD *)this + 17) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 8,
          result: v53,
          nb: v91);
        v53 = newTotalRd;
      }
      v54 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v53) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
      *(float *)v54 = v101;
      *(float *)(v54 + 4) = v106;
      *(_DWORD *)(v54 + 8) = -1;
      v52 = (*((_DWORD *)this + 16))++;
    }
    newTotalRe = v52;
    if ( LOBYTE(p[7].pExceptionObject) != 0 )
    {
      v55 = *((_DWORD *)this + 16) >> 8;
      v139 = ySolidl;
      v147 = this->pRN;
      ySolidm = v55;
      if ( v55 >= *((_DWORD *)this + 17) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 8,
          result: v55,
          nb: v91);
        v55 = ySolidm;
      }
      v56 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v55) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
      *(float *)v56 = xSolidb;
      *(float *)(v56 + 4) = v139;
      *(_DWORD *)(v56 + 8) = v147;
      v57 = (*((_DWORD *)this + 16))++;
    }
    else
    {
      v57 = newSolidRa;
    }
    newSolidLa = v57;
    if ( BYTE2(p[6].pNext) != 0 )
    {
      v58 = *((_DWORD *)this + 16) >> 8;
      ySolidn = v58;
      if ( v58 >= *((_DWORD *)this + 17) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 8,
          result: v58,
          nb: v91);
        v58 = ySolidn;
      }
      v59 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v58) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
      *(float *)v59 = a1c;
      *(float *)(v59 + 4) = dyb;
      *(_DWORD *)(v59 + 8) = -1;
      v57 = (*((_DWORD *)this + 16))++;
    }
    newTotalLb = v57;
    if ( LOBYTE(p[6].pNext) != 0 || BYTE1(p[6].pNext) != 0 )
    {
      v60 = *((_DWORD *)this + 20) >> 8;
      v93 = *((_DWORD *)this + 25);
      ySolido = v60;
      if ( v60 >= *((_DWORD *)this + 21) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 10,
          result: v60,
          nb: v91);
        v60 = ySolido;
      }
      v61 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v60) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
      *v61 = v93;
      v61[1] = newSolidRa;
      v61[2] = newSolidLa;
      ++*((_DWORD *)this + 20);
      v109 = *((_DWORD *)this + 24);
      v62 = *((_DWORD *)this + 20) >> 8;
      v102 = *((_DWORD *)this + 25);
      ySolidp = v62;
      if ( v62 >= *((_DWORD *)this + 21) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 10,
          result: v62,
          nb: v91);
        v62 = ySolidp;
      }
      v63 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v62) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
      *v63 = v102;
      v63[1] = newSolidLa;
      v63[2] = v109;
      ++*((_DWORD *)this + 20);
    }
    if ( HIBYTE(p[6].pNext) != 0 )
    {
      v103 = *((_DWORD *)this + 27);
      v64 = *((_DWORD *)this + 20) >> 8;
      v110 = *((_DWORD *)this + 25);
      ySolidq = v64;
      if ( v64 >= *((_DWORD *)this + 21) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 10,
          result: v64,
          nb: v91);
        v64 = ySolidq;
      }
      v65 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v64) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
      *v65 = v103;
      v65[1] = newSolidRa;
      v65[2] = v110;
      v66 = ++*((_DWORD *)this + 20) >> 8;
      v94 = *((_DWORD *)this + 27);
      ySolidr = v66;
      if ( v66 >= *((_DWORD *)this + 21) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 10,
          result: v66,
          nb: v91);
        v66 = ySolidr;
      }
      v4 = (float *)a2;
      v67 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v66) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
      *v67 = v94;
      v67[1] = newTotalRe;
      v67[2] = newSolidRa;
      ++*((_DWORD *)this + 20);
    }
    if ( BYTE2(p[6].pNext) != 0 )
    {
      v95 = *((_DWORD *)this + 24);
      v68 = *((_DWORD *)this + 20) >> 8;
      ySolids = v68;
      if ( v68 >= *((_DWORD *)this + 21) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 10,
          result: v68,
          nb: v91);
        v68 = ySolids;
      }
      v69 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v68) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
      *v69 = v95;
      v69[1] = newSolidLa;
      v69[2] = newTotalLb;
      ++*((_DWORD *)this + 20);
      v111 = *((_DWORD *)this + 26);
      v70 = *((_DWORD *)this + 20) >> 8;
      v104 = *((_DWORD *)this + 24);
      ySolidt = v70;
      if ( v70 >= *((_DWORD *)this + 21) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 10,
          result: v70,
          nb: v91);
        v70 = ySolidt;
      }
      v4 = (float *)a2;
      v71 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v70) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
      *v71 = v104;
      v71[1] = newTotalLb;
      v71[2] = v111;
      ++*((_DWORD *)this + 20);
    }
    *((_DWORD *)this + 24) = newSolidLa;
    *((_DWORD *)this + 26) = newTotalLb;
    *((_DWORD *)this + 25) = newSolidRa;
    *((_DWORD *)this + 27) = newTotalRe;
    if ( overlap != 0 )
    {
      v148 = this->pRN;
      v128 = *v4 - *((float *)n + 4);
      v72 = *((_DWORD *)this + 16) >> 8;
      ySolidu = v72;
      v140 = v4[1] - *((float *)n + 5);
      if ( v72 >= *((_DWORD *)this + 17) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)this + 8,
          result: v72,
          nb: v91);
        v72 = ySolidu;
      }
      v73 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v72) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
      *(float *)v73 = v128;
      *(float *)(v73 + 4) = v140;
      *(_DWORD *)(v73 + 8) = v148;
      *((_DWORD *)this + 24) = (*((_DWORD *)this + 16))++;
      if ( BYTE2(p[6].pNext) != 0 )
      {
        ySolidba = v4[1] - *((float *)n + 7);
        v90 = ySolidba;
        ySolidbb = *v4 - *((float *)n + 6);
        v74 = GStrokerAA::addVertex(this, a2: (char)this, x: ySolidbb, y: v90, id: -1);
      }
      else
      {
        v74 = (EHRegistrationNode *)newSolidLa;
      }
      *((_DWORD *)this + 26) = v74;
    }
    v183 = *((float *)this + 10) * 0.25;
    ySolidbc = 0.25 * v183;
    if ( ySolidbc < *(float *)&p[2].pExceptionObject - *((float *)n + 27) )
    {
      ySolidv = atan2(*((float *)n + 15), *((float *)n + 14));
      a1d = ySolidv;
      no = atan2(*((float *)n + 19), *((float *)n + 18));
      v75 = no;
      if ( no < (double)ySolidv )
      {
        np = v75 + 6.283185482025146;
        v75 = np;
      }
      v151 = v75 - ySolidv;
      nq = *(float *)&p[2].pExceptionObject / (v183 + *(float *)&p[2].pExceptionObject);
      nr = acos(nq);
      ns = nr + nr;
      v76 = v151 / ns;
      nt = (const struct GStrokerAA::JoinParamType *)((int)v76 + 1);
      xSolidc = v151 / (double)(int)nt;
      a1e = xSolidc + a1d;
      if ( (int)nt > 0 )
      {
        ySolidw = (int)v76 + 1;
        while ( 1 )
        {
          ne = cos(a1e);
          dyc = sin(a1e);
          if ( LOBYTE(p[7].pExceptionObject) != 0 )
          {
            v129 = *(float *)&p->pNext * ne + *v4;
            v149 = this->CatchDepth;
            v77 = *(float *)&p->pNext * dyc + v4[1];
            v78 = *((_DWORD *)this + 16) >> 8;
            if ( v78 >= *((_DWORD *)this + 17) )
              GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
                this: (DName *)this + 8,
                result: v78,
                nb: v91);
            v79 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v78) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
            *(float *)v79 = v129;
            v141 = v77;
            *(float *)(v79 + 4) = v141;
            *(_DWORD *)(v79 + 8) = v149;
            v80 = (*((_DWORD *)this + 16))++;
            newSolidRa = v80;
          }
          else
          {
            v80 = newSolidRa;
          }
          if ( HIBYTE(p[6].pNext) != 0 )
          {
            v81 = *((_DWORD *)this + 16) >> 8;
            v105 = *(float *)&p[2].pExceptionObject * ne + *(float *)a2;
            v107 = *(float *)&p[2].pExceptionObject * dyc + *((float *)a2 + 1);
            if ( v81 >= *((_DWORD *)this + 17) )
              GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
                this: (DName *)this + 8,
                result: v81,
                nb: v91);
            v82 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v81) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
            *(float *)v82 = v105;
            *(float *)(v82 + 4) = v107;
            *(_DWORD *)(v82 + 8) = -1;
            v80 = (*((_DWORD *)this + 16))++;
          }
          newTotalRf = v80;
          if ( BYTE1(p[6].pNext) != 0 )
          {
            v83 = *((_DWORD *)this + 20) >> 8;
            v113 = *((_DWORD *)this + 24);
            v114 = *((_DWORD *)this + 25);
            nf = (const struct GStrokerAA::JoinParamType *)v83;
            if ( v83 >= *((_DWORD *)this + 21) )
            {
              GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
                this: (DName *)this + 10,
                result: v83,
                nb: v91);
              v83 = (unsigned int)nf;
            }
            v84 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v83) + 12
                                                                           * (unsigned __int8)*((_DWORD *)this + 20));
            *v84 = v113;
            v84[1] = v114;
            v84[2] = newSolidRa;
            ++*((_DWORD *)this + 20);
            v80 = newTotalRf;
          }
          if ( HIBYTE(p[6].pNext) != 0 )
          {
            v85 = *((_DWORD *)this + 20) >> 8;
            v117 = *((_DWORD *)this + 25);
            v119 = *((_DWORD *)this + 27);
            ng = (const struct GStrokerAA::JoinParamType *)v85;
            if ( v85 >= *((_DWORD *)this + 21) )
            {
              GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
                this: (DName *)this + 10,
                result: v85,
                nb: v91);
              v85 = (unsigned int)ng;
            }
            v86 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v85) + 12
                                                                           * (unsigned __int8)*((_DWORD *)this + 20));
            *v86 = v117;
            v86[1] = v119;
            v86[2] = newSolidRa;
            v87 = ++*((_DWORD *)this + 20) >> 8;
            v96 = *((_DWORD *)this + 27);
            nh = (const struct GStrokerAA::JoinParamType *)v87;
            if ( v87 >= *((_DWORD *)this + 21) )
            {
              GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
                this: (DName *)this + 10,
                result: v87,
                nb: v91);
              v87 = (unsigned int)nh;
            }
            v88 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v87) + 12
                                                                           * (unsigned __int8)*((_DWORD *)this + 20));
            *v88 = v96;
            v88[1] = newTotalRf;
            v88[2] = newSolidRa;
            ++*((_DWORD *)this + 20);
            v80 = newTotalRf;
          }
          v47 = ySolidw-- == 1;
          *((_DWORD *)this + 25) = newSolidRa;
          *((_DWORD *)this + 27) = v80;
          a1e = xSolidc + a1e;
          if ( v47 )
            break;
          v4 = (float *)a2;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10196DD0
// Name: private: void GStrokerAA::calcBevelJoin(struct GStrokeVertexType const __near &,struct GStrokerAA::WidthsType const __near &,struct GStrokerAA::JoinParamType const __near &,enum GStrokerTypes::LineJoinType)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GStrokerAA::calcBevelJoin(int a1@<ecx>, char a2@<dil>, float *a3, FrameInfo *p, int a5, int lineJoin)
{
  double v6; // st7
  char v8; // al
  bool v9; // zf
  double v11; // st6
  double v12; // st6
  double v13; // st6
  int v14; // edi
  double v15; // st6
  unsigned int v16; // ecx
  double v17; // st6
  int v18; // eax
  FrameInfo *v19; // edx
  int v20; // ecx
  unsigned int v21; // ecx
  int v22; // eax
  double v23; // st7
  unsigned int v24; // ecx
  double v25; // st5
  int v26; // eax
  unsigned int v27; // ecx
  int v28; // eax
  int v29; // eax
  unsigned int v30; // ecx
  int v31; // eax
  unsigned int v32; // ecx
  _DWORD *v33; // eax
  unsigned int v34; // ecx
  _DWORD *v35; // eax
  unsigned int v36; // ecx
  _DWORD *v37; // eax
  unsigned int v38; // ecx
  _DWORD *v39; // eax
  unsigned int v40; // ecx
  _DWORD *v41; // eax
  unsigned int v42; // ecx
  _DWORD *v43; // ecx
  unsigned int v44; // ecx
  int v45; // eax
  EHRegistrationNode *v46; // eax
  unsigned int v47; // ebx
  EHRegistrationNode *v48; // edi
  double v49; // st6
  double v50; // st6
  double v51; // st6
  int v52; // edi
  double v53; // st6
  unsigned int v54; // ecx
  double v55; // st6
  int v56; // eax
  FrameInfo *v57; // edx
  int v58; // ecx
  unsigned int v59; // ecx
  int v60; // eax
  double v61; // st7
  unsigned int v62; // ecx
  double v63; // st5
  int v64; // eax
  unsigned int v65; // ecx
  int v66; // eax
  int v67; // eax
  unsigned int v68; // ecx
  int v69; // eax
  unsigned int v70; // ecx
  _DWORD *v71; // eax
  unsigned int v72; // ecx
  _DWORD *v73; // eax
  unsigned int v74; // ecx
  _DWORD *v75; // eax
  unsigned int v76; // ecx
  _DWORD *v77; // eax
  unsigned int v78; // ecx
  _DWORD *v79; // eax
  unsigned int v80; // ecx
  _DWORD *v81; // ecx
  unsigned int v82; // ecx
  int v83; // eax
  EHRegistrationNode *v84; // eax
  unsigned int v85; // ebx
  EHRegistrationNode *v86; // edi
  float v87; // [esp+4h] [ebp-48h]
  float v88; // [esp+4h] [ebp-48h]
  float v89; // [esp+4h] [ebp-48h]
  float v90; // [esp+4h] [ebp-48h]
  float v91; // [esp+4h] [ebp-48h]
  float v92; // [esp+4h] [ebp-48h]
  float v93; // [esp+4h] [ebp-48h]
  float v94; // [esp+4h] [ebp-48h]
  char v95; // [esp+Ch] [ebp-40h]
  float v96; // [esp+18h] [ebp-34h]
  float v97; // [esp+18h] [ebp-34h]
  float v98; // [esp+18h] [ebp-34h]
  int v99; // [esp+18h] [ebp-34h]
  int v100; // [esp+18h] [ebp-34h]
  int v101; // [esp+18h] [ebp-34h]
  int v102; // [esp+18h] [ebp-34h]
  int v103; // [esp+18h] [ebp-34h]
  int v104; // [esp+18h] [ebp-34h]
  float v105; // [esp+18h] [ebp-34h]
  float v106; // [esp+18h] [ebp-34h]
  float v107; // [esp+18h] [ebp-34h]
  float v108; // [esp+18h] [ebp-34h]
  int v109; // [esp+18h] [ebp-34h]
  int v110; // [esp+18h] [ebp-34h]
  int v111; // [esp+18h] [ebp-34h]
  int v112; // [esp+18h] [ebp-34h]
  int v113; // [esp+18h] [ebp-34h]
  int v114; // [esp+18h] [ebp-34h]
  float v115; // [esp+18h] [ebp-34h]
  float v116; // [esp+1Ch] [ebp-30h]
  float v117; // [esp+1Ch] [ebp-30h]
  float v118; // [esp+1Ch] [ebp-30h]
  float v119; // [esp+1Ch] [ebp-30h]
  int v120; // [esp+1Ch] [ebp-30h]
  int v121; // [esp+1Ch] [ebp-30h]
  int v122; // [esp+1Ch] [ebp-30h]
  float v123; // [esp+1Ch] [ebp-30h]
  float v124; // [esp+1Ch] [ebp-30h]
  float v125; // [esp+1Ch] [ebp-30h]
  float v126; // [esp+1Ch] [ebp-30h]
  float v127; // [esp+1Ch] [ebp-30h]
  float v128; // [esp+1Ch] [ebp-30h]
  int v129; // [esp+20h] [ebp-2Ch]
  int v130; // [esp+20h] [ebp-2Ch]
  int v131; // [esp+20h] [ebp-2Ch]
  int v132; // [esp+20h] [ebp-2Ch]
  int v133; // [esp+20h] [ebp-2Ch]
  int v134; // [esp+20h] [ebp-2Ch]
  int v135; // [esp+20h] [ebp-2Ch]
  int v136; // [esp+20h] [ebp-2Ch]
  int v137; // [esp+20h] [ebp-2Ch]
  int v138; // [esp+20h] [ebp-2Ch]
  int v139; // [esp+20h] [ebp-2Ch]
  float ySolid; // [esp+24h] [ebp-28h]
  unsigned int ySolida; // [esp+24h] [ebp-28h]
  unsigned int ySolidb; // [esp+24h] [ebp-28h]
  unsigned int ySolidc; // [esp+24h] [ebp-28h]
  unsigned int ySolidd; // [esp+24h] [ebp-28h]
  unsigned int ySolide; // [esp+24h] [ebp-28h]
  unsigned int ySolidf; // [esp+24h] [ebp-28h]
  unsigned int ySolidg; // [esp+24h] [ebp-28h]
  unsigned int ySolidh; // [esp+24h] [ebp-28h]
  float ySolidi; // [esp+24h] [ebp-28h]
  unsigned int ySolidj; // [esp+24h] [ebp-28h]
  unsigned int ySolidk; // [esp+24h] [ebp-28h]
  unsigned int ySolidl; // [esp+24h] [ebp-28h]
  unsigned int ySolidm; // [esp+24h] [ebp-28h]
  unsigned int ySolidn; // [esp+24h] [ebp-28h]
  unsigned int ySolido; // [esp+24h] [ebp-28h]
  unsigned int ySolidp; // [esp+24h] [ebp-28h]
  unsigned int ySolidq; // [esp+24h] [ebp-28h]
  float xSolid; // [esp+28h] [ebp-24h]
  float xSolida; // [esp+28h] [ebp-24h]
  float yTotal; // [esp+2Ch] [ebp-20h]
  float yTotala; // [esp+2Ch] [ebp-20h]
  float xTotal; // [esp+30h] [ebp-1Ch]
  float xTotala; // [esp+30h] [ebp-1Ch]
  float kTotald; // [esp+34h] [ebp-18h]
  float kTotale; // [esp+34h] [ebp-18h]
  float kTotalf; // [esp+34h] [ebp-18h]
  float kTotal; // [esp+34h] [ebp-18h]
  unsigned int kTotala; // [esp+34h] [ebp-18h]
  float kTotalg; // [esp+34h] [ebp-18h]
  float kTotalh; // [esp+34h] [ebp-18h]
  float kTotali; // [esp+34h] [ebp-18h]
  float kTotalb; // [esp+34h] [ebp-18h]
  unsigned int kTotalc; // [esp+34h] [ebp-18h]
  float kSolid; // [esp+38h] [ebp-14h]
  float kSolida; // [esp+38h] [ebp-14h]
  float kSolidb; // [esp+38h] [ebp-14h]
  float x1f; // [esp+3Ch] [ebp-10h]
  unsigned int x1; // [esp+3Ch] [ebp-10h]
  float x1g; // [esp+3Ch] [ebp-10h]
  unsigned int x1a; // [esp+3Ch] [ebp-10h]
  int x1b; // [esp+3Ch] [ebp-10h]
  float x1h; // [esp+3Ch] [ebp-10h]
  float x1i; // [esp+3Ch] [ebp-10h]
  float x1j; // [esp+3Ch] [ebp-10h]
  unsigned int x1c; // [esp+3Ch] [ebp-10h]
  float x1k; // [esp+3Ch] [ebp-10h]
  unsigned int x1d; // [esp+3Ch] [ebp-10h]
  int x1e; // [esp+3Ch] [ebp-10h]
  float x1l; // [esp+3Ch] [ebp-10h]
  float x1m; // [esp+3Ch] [ebp-10h]
  unsigned int newSolidR; // [esp+40h] [ebp-Ch]
  EHRegistrationNode *newSolidRa; // [esp+40h] [ebp-Ch]
  EHRegistrationNode *newSolidL; // [esp+44h] [ebp-8h]
  unsigned int newSolidLa; // [esp+44h] [ebp-8h]
  float y1f; // [esp+48h] [ebp-4h]
  float y1; // [esp+48h] [ebp-4h]
  float y1g; // [esp+48h] [ebp-4h]
  float y1a; // [esp+48h] [ebp-4h]
  float y1h; // [esp+48h] [ebp-4h]
  int y1b; // [esp+48h] [ebp-4h]
  float y1i; // [esp+48h] [ebp-4h]
  float y1j; // [esp+48h] [ebp-4h]
  float y1k; // [esp+48h] [ebp-4h]
  float y1c; // [esp+48h] [ebp-4h]
  float y1l; // [esp+48h] [ebp-4h]
  float y1d; // [esp+48h] [ebp-4h]
  float y1m; // [esp+48h] [ebp-4h]
  int y1e; // [esp+48h] [ebp-4h]
  float y1n; // [esp+48h] [ebp-4h]
  float y1o; // [esp+48h] [ebp-4h]
  float v211; // [esp+54h] [ebp+8h]
  float v212; // [esp+54h] [ebp+8h]
  float v213; // [esp+54h] [ebp+8h]
  float v214; // [esp+54h] [ebp+8h]
  unsigned int v215; // [esp+5Ch] [ebp+10h]
  float v216; // [esp+5Ch] [ebp+10h]
  float v217; // [esp+5Ch] [ebp+10h]
  float v218; // [esp+5Ch] [ebp+10h]
  unsigned int v219; // [esp+5Ch] [ebp+10h]
  float v220; // [esp+5Ch] [ebp+10h]
  float v221; // [esp+5Ch] [ebp+10h]
  float v222; // [esp+5Ch] [ebp+10h]
  bool overlap; // [esp+5Fh] [ebp+13h]
  float lineJoina; // [esp+60h] [ebp+14h]
  float lineJoinb; // [esp+60h] [ebp+14h]
  float lineJoinc; // [esp+60h] [ebp+14h]
  float lineJoind; // [esp+60h] [ebp+14h]
  float lineJoine; // [esp+60h] [ebp+14h]
  float lineJoinf; // [esp+60h] [ebp+14h]
  float lineJoing; // [esp+60h] [ebp+14h]
  float lineJoinh; // [esp+60h] [ebp+14h]

  v6 = 0.0;
  kSolid = 0.0;
  v8 = *(_BYTE *)(a5 + 217) | *(_BYTE *)(a5 + 218);
  v9 = *(_BYTE *)(a5 + 215) == 0;
  v95 = a2;
  overlap = v8;
  if ( v9 )
  {
    if ( v8 != 0 )
      v49 = *a3 - *(float *)(a5 + 8);
    else
      v49 = *(float *)(a5 + 136);
    xTotala = v49;
    if ( v8 != 0 )
      v50 = a3[1] - *(float *)(a5 + 12);
    else
      v50 = *(float *)(a5 + 140);
    yTotala = v50;
    xSolida = (xTotala - *a3) * *(float *)&p[3].pNext + *a3;
    ySolidi = (yTotala - a3[1]) * *(float *)&p[3].pNext + a3[1];
    if ( lineJoin != 0 )
    {
      v52 = a1 + 64;
      v59 = *(_DWORD *)(a1 + 64) >> 8;
      v107 = *(float *)(a5 + 48) + *a3;
      v134 = *(_DWORD *)(a1 + 20);
      kTotalc = v59;
      v125 = *(float *)(a5 + 52) + a3[1];
      if ( v59 >= *(_DWORD *)(a1 + 68) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)(a1 + 64),
          result: v59,
          nb: v95);
        v6 = 0.0;
        v59 = kTotalc;
      }
      v60 = *(_DWORD *)(*(_DWORD *)(a1 + 76) + 4 * v59) + 12 * (unsigned __int8)*(_DWORD *)(a1 + 64);
      *(float *)v60 = v107;
      *(float *)(v60 + 4) = v125;
      *(_DWORD *)(v60 + 8) = v134;
      v58 = (*(_DWORD *)v52)++;
      newSolidRa = (EHRegistrationNode *)v58;
      y1d = *(float *)(a5 + 156) - *(float *)(a5 + 108);
      if ( y1d == v6 )
        y1d = 1.0;
      v57 = p;
      kTotalb = (*(float *)(a5 + 104) + *(float *)&p[2].pExceptionObject - *(float *)&p->pNext - *(float *)(a5 + 108))
              / y1d;
    }
    else
    {
      y1k = *(float *)(a5 + 204) - *(float *)(a5 + 104);
      v51 = y1k;
      if ( 0.0 == y1k )
        v51 = (float)1.0;
      kSolidb = *(float *)&p[6].pExceptionObject
              - *(float *)(a5 + 104)
              - *(float *)&p[2].pExceptionObject
              + *(float *)&p->pNext;
      if ( kSolidb > v51 )
        kSolidb = v51;
      kTotalg = *(float *)&p[5].pExceptionObject - *(float *)(a5 + 104);
      kSolid = (kTotalg + kSolidb) / (v51 * 2.0);
      y1c = *(float *)(a5 + 156) - *(float *)(a5 + 108);
      if ( y1c == 0.0 )
        y1c = 1.0;
      v52 = a1 + 64;
      v133 = *(_DWORD *)(a1 + 20);
      kTotalh = *(float *)&p[5].pExceptionObject
              - *(float *)(a5 + 108)
              + *(float *)&p[2].pExceptionObject
              - *(float *)&p->pNext;
      v53 = kTotalh;
      v54 = *(_DWORD *)(a1 + 64) >> 8;
      kTotali = *(float *)&p[6].pExceptionObject - *(float *)(a5 + 108);
      kTotalb = (v53 + kTotali) / (2.0 * y1c);
      x1j = *(float *)(a5 + 48) + *a3;
      y1l = *(float *)(a5 + 52) + a3[1];
      v55 = x1j;
      x1c = v54;
      v106 = v55 + (*(float *)(a5 + 192) - v55) * kSolid;
      v124 = kSolid * (*(float *)(a5 + 196) - y1l) + y1l;
      if ( v54 >= *(_DWORD *)(a1 + 68) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)(a1 + 64),
          result: v54,
          nb: v95);
        v54 = x1c;
      }
      v56 = *(_DWORD *)(*(_DWORD *)(a1 + 76) + 4 * v54) + 12 * (unsigned __int8)*(_DWORD *)(a1 + 64);
      *(float *)v56 = v106;
      *(float *)(v56 + 4) = v124;
      *(_DWORD *)(v56 + 8) = v133;
      ++*(_DWORD *)v52;
      v57 = p;
      v58 = *(_DWORD *)v52 - 1;
      newSolidRa = (EHRegistrationNode *)v58;
    }
    v61 = kTotalb;
    if ( HIBYTE(v57[6].pNext) != 0 )
    {
      v62 = *(_DWORD *)v52 >> 8;
      x1k = *(float *)(a5 + 56) + *a3;
      y1m = *(float *)(a5 + 60) + a3[1];
      v63 = x1k;
      x1d = v62;
      v108 = (*(float *)(a5 + 144) - v63) * v61 + v63;
      v126 = v61 * (*(float *)(a5 + 148) - y1m) + y1m;
      if ( v62 >= *(_DWORD *)(v52 + 4) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)v52,
          result: v62,
          nb: v95);
        v62 = x1d;
      }
      v64 = *(_DWORD *)(*(_DWORD *)(v52 + 12) + 4 * v62) + 12 * (unsigned __int8)*(_DWORD *)v52;
      *(float *)v64 = v108;
      v57 = p;
      *(float *)(v64 + 4) = v126;
      *(_DWORD *)(v64 + 8) = -1;
      ++*(_DWORD *)v52;
      v58 = (int)newSolidRa;
      y1e = *(_DWORD *)v52 - 1;
    }
    else
    {
      y1e = v58;
    }
    if ( LOBYTE(v57[7].pExceptionObject) != 0 )
    {
      v65 = *(_DWORD *)v52 >> 8;
      v127 = ySolidi;
      v135 = *(_DWORD *)(a1 + 16);
      ySolidj = v65;
      if ( v65 >= *(_DWORD *)(v52 + 4) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)v52,
          result: v65,
          nb: v95);
        v65 = ySolidj;
      }
      v66 = *(_DWORD *)(*(_DWORD *)(v52 + 12) + 4 * v65) + 12 * (unsigned __int8)*(_DWORD *)v52;
      *(float *)v66 = xSolida;
      *(float *)(v66 + 4) = v127;
      v58 = (int)newSolidRa;
      *(_DWORD *)(v66 + 8) = v135;
      ++*(_DWORD *)v52;
      v57 = p;
      v67 = *(_DWORD *)v52 - 1;
      newSolidLa = v67;
    }
    else
    {
      v67 = v58;
      newSolidLa = v58;
    }
    if ( BYTE2(v57[6].pNext) != 0 )
    {
      v68 = *(_DWORD *)v52 >> 8;
      ySolidk = v68;
      if ( v68 >= *(_DWORD *)(v52 + 4) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)v52,
          result: v68,
          nb: v95);
        v68 = ySolidk;
      }
      v69 = *(_DWORD *)(*(_DWORD *)(v52 + 12) + 4 * v68) + 12 * (unsigned __int8)*(_DWORD *)v52;
      *(float *)v69 = xTotala;
      v57 = p;
      *(float *)(v69 + 4) = yTotala;
      *(_DWORD *)(v69 + 8) = -1;
      ++*(_DWORD *)v52;
      v58 = (int)newSolidRa;
      v67 = *(_DWORD *)v52 - 1;
    }
    x1e = v67;
    if ( LOBYTE(v57[6].pNext) != 0 || BYTE1(v57[6].pNext) != 0 )
    {
      v70 = *(_DWORD *)(a1 + 80) >> 8;
      v109 = *(_DWORD *)(a1 + 100);
      ySolidl = v70;
      if ( v70 >= *(_DWORD *)(a1 + 84) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)(a1 + 80),
          result: v70,
          nb: v95);
        v70 = ySolidl;
      }
      v71 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 92) + 4 * v70) + 12 * (unsigned __int8)*(_DWORD *)(a1 + 80));
      *v71 = v109;
      v71[1] = newSolidRa;
      v71[2] = newSolidLa;
      ++*(_DWORD *)(a1 + 80);
      v136 = *(_DWORD *)(a1 + 96);
      v72 = *(_DWORD *)(a1 + 80) >> 8;
      v110 = *(_DWORD *)(a1 + 100);
      ySolidm = v72;
      if ( v72 >= *(_DWORD *)(a1 + 84) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)(a1 + 80),
          result: v72,
          nb: v95);
        v72 = ySolidm;
      }
      v73 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 92) + 4 * v72) + 12 * (unsigned __int8)*(_DWORD *)(a1 + 80));
      *v73 = v110;
      v73[1] = newSolidLa;
      v58 = (int)newSolidRa;
      v73[2] = v136;
      ++*(_DWORD *)(a1 + 80);
      v67 = x1e;
      v57 = p;
    }
    if ( HIBYTE(v57[6].pNext) != 0 )
    {
      v137 = *(_DWORD *)(a1 + 100);
      v74 = *(_DWORD *)(a1 + 80) >> 8;
      v111 = *(_DWORD *)(a1 + 108);
      ySolidn = v74;
      if ( v74 >= *(_DWORD *)(a1 + 84) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)(a1 + 80),
          result: v74,
          nb: v95);
        v74 = ySolidn;
      }
      v75 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 92) + 4 * v74) + 12 * (unsigned __int8)*(_DWORD *)(a1 + 80));
      *v75 = v111;
      v75[1] = newSolidRa;
      v75[2] = v137;
      v76 = ++*(_DWORD *)(a1 + 80) >> 8;
      v112 = *(_DWORD *)(a1 + 108);
      ySolido = v76;
      if ( v76 >= *(_DWORD *)(a1 + 84) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)(a1 + 80),
          result: v76,
          nb: v95);
        v76 = ySolido;
      }
      v77 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 92) + 4 * v76) + 12 * (unsigned __int8)*(_DWORD *)(a1 + 80));
      *v77 = v112;
      v57 = p;
      v77[1] = y1e;
      v58 = (int)newSolidRa;
      v77[2] = newSolidRa;
      ++*(_DWORD *)(a1 + 80);
      v67 = x1e;
    }
    if ( BYTE2(v57[6].pNext) != 0 )
    {
      v78 = *(_DWORD *)(a1 + 80) >> 8;
      v113 = *(_DWORD *)(a1 + 96);
      ySolidp = v78;
      if ( v78 >= *(_DWORD *)(a1 + 84) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)(a1 + 80),
          result: v78,
          nb: v95);
        v78 = ySolidp;
      }
      v79 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 92) + 4 * v78) + 12 * (unsigned __int8)*(_DWORD *)(a1 + 80));
      *v79 = v113;
      v79[1] = newSolidLa;
      v79[2] = x1e;
      ++*(_DWORD *)(a1 + 80);
      v138 = *(_DWORD *)(a1 + 104);
      v80 = *(_DWORD *)(a1 + 80) >> 8;
      v114 = *(_DWORD *)(a1 + 96);
      ySolidq = v80;
      if ( v80 >= *(_DWORD *)(a1 + 84) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)(a1 + 80),
          result: v80,
          nb: v95);
        v80 = ySolidq;
      }
      v81 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 92) + 4 * v80) + 12 * (unsigned __int8)*(_DWORD *)(a1 + 80));
      v67 = x1e;
      *v81 = v114;
      v81[1] = x1e;
      v81[2] = v138;
      ++*(_DWORD *)(a1 + 80);
      v58 = (int)newSolidRa;
    }
    *(_DWORD *)(a1 + 104) = v67;
    *(_DWORD *)(a1 + 96) = newSolidLa;
    *(_DWORD *)(a1 + 100) = v58;
    *(_DWORD *)(a1 + 108) = y1e;
    if ( overlap )
    {
      v139 = *(_DWORD *)(a1 + 16);
      v82 = *(_DWORD *)v52 >> 8;
      v115 = *a3 - *(float *)(a5 + 16);
      v219 = v82;
      v128 = a3[1] - *(float *)(a5 + 20);
      if ( v82 >= *(_DWORD *)(v52 + 4) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)v52,
          result: v82,
          nb: v95);
        v82 = v219;
      }
      v83 = *(_DWORD *)(*(_DWORD *)(v52 + 12) + 4 * v82) + 12 * (unsigned __int8)*(_DWORD *)v52;
      *(float *)v83 = v115;
      *(float *)(v83 + 4) = v128;
      *(_DWORD *)(v83 + 8) = v139;
      *(_DWORD *)(a1 + 96) = (*(_DWORD *)v52)++;
      if ( BYTE2(p[6].pNext) != 0 )
      {
        v220 = a3[1] - *(float *)(a5 + 28);
        v91 = v220;
        v221 = *a3 - *(float *)(a5 + 24);
        v84 = GStrokerAA::addVertex(this: (GStrokerAA *)a1, a2: v52, x: v221, y: v91, id: -1);
      }
      else
      {
        v84 = (EHRegistrationNode *)newSolidLa;
      }
      *(_DWORD *)(a1 + 104) = v84;
    }
    v222 = *(float *)(a1 + 40) * 0.25 * 0.25;
    if ( v222 < *(float *)&p[2].pExceptionObject - *(float *)(a5 + 108) )
    {
      if ( LOBYTE(p[7].pExceptionObject) != 0 )
      {
        if ( lineJoin != 0 )
        {
          lineJoing = *(float *)(a5 + 68) + a3[1];
          v93 = lineJoing;
          lineJoinh = *(float *)(a5 + 64) + *a3;
          newSolidRa = GStrokerAA::addVertex(
                         this: (GStrokerAA *)a1,
                         a2: v52,
                         x: lineJoinh,
                         y: v93,
                         id: *(_DWORD *)(a1 + 20));
        }
        else
        {
          x1l = *(float *)(a5 + 64) + *a3;
          y1n = *(float *)(a5 + 68) + a3[1];
          lineJoine = y1n + (*(float *)(a5 + 196) - y1n) * kSolid;
          v92 = lineJoine;
          lineJoinf = kSolid * (*(float *)(a5 + 192) - x1l) + x1l;
          newSolidRa = GStrokerAA::addVertex(
                         this: (GStrokerAA *)a1,
                         a2: v52,
                         x: lineJoinf,
                         y: v92,
                         id: *(_DWORD *)(a1 + 20));
        }
      }
      if ( HIBYTE(p[6].pNext) != 0 )
      {
        x1m = *(float *)(a5 + 72) + *a3;
        y1o = *(float *)(a5 + 76) + a3[1];
        v213 = y1o + (*(float *)(a5 + 148) - y1o) * kTotalb;
        v94 = v213;
        v214 = kTotalb * (*(float *)(a5 + 144) - x1m) + x1m;
        v85 = (unsigned int)newSolidRa;
        v86 = GStrokerAA::addVertex(this: (GStrokerAA *)a1, a2: v52, x: v214, y: v94, id: -1);
      }
      else
      {
        v85 = (unsigned int)newSolidRa;
        v86 = newSolidRa;
      }
      if ( BYTE1(p[6].pNext) != 0 )
        GStrokerAA::addTriangle(this: (GStrokerAA *)a1, a2: *(_DWORD *)(a1 + 96), a3: *(_DWORD *)(a1 + 100), a4: v85);
      if ( HIBYTE(p[6].pNext) != 0 )
      {
        GStrokerAA::addTriangle(this: (GStrokerAA *)a1, a2: *(_DWORD *)(a1 + 100), a3: *(_DWORD *)(a1 + 108), a4: v85);
        GStrokerAA::addTriangle(this: (GStrokerAA *)a1, a2: *(_DWORD *)(a1 + 108), a3: (unsigned int)v86, a4: v85);
      }
      *(_DWORD *)(a1 + 100) = v85;
      *(_DWORD *)(a1 + 108) = v86;
    }
  }
  else
  {
    if ( v8 != 0 )
      v11 = *(float *)(a5 + 56) + *a3;
    else
      v11 = *(float *)(a5 + 144);
    xTotal = v11;
    if ( v8 != 0 )
      v12 = *(float *)(a5 + 60) + a3[1];
    else
      v12 = *(float *)(a5 + 148);
    yTotal = v12;
    xSolid = (xTotal - *a3) * *(float *)&p[4].pExceptionObject + *a3;
    ySolid = (yTotal - a3[1]) * *(float *)&p[4].pExceptionObject + a3[1];
    if ( lineJoin != 0 )
    {
      v14 = a1 + 64;
      v21 = *(_DWORD *)(a1 + 64) >> 8;
      v97 = *a3 - *(float *)a5;
      v130 = *(_DWORD *)(a1 + 16);
      kTotala = v21;
      v117 = a3[1] - *(float *)(a5 + 4);
      if ( v21 >= *(_DWORD *)(a1 + 68) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)(a1 + 64),
          result: v21,
          nb: v95);
        v6 = 0.0;
        v21 = kTotala;
      }
      v22 = *(_DWORD *)(*(_DWORD *)(a1 + 76) + 4 * v21) + 12 * (unsigned __int8)*(_DWORD *)(a1 + 64);
      *(float *)v22 = v97;
      *(float *)(v22 + 4) = v117;
      *(_DWORD *)(v22 + 8) = v130;
      v20 = (*(_DWORD *)v14)++;
      newSolidL = (EHRegistrationNode *)v20;
      y1a = *(float *)(a5 + 152) - *(float *)(a5 + 100);
      if ( y1a == v6 )
        y1a = 1.0;
      v19 = p;
      kTotal = (*(float *)(a5 + 96) + *(float *)&p[1].pNext - *(float *)&p->pExceptionObject - *(float *)(a5 + 100))
             / y1a;
    }
    else
    {
      y1f = *(float *)(a5 + 200) - *(float *)(a5 + 96);
      v13 = y1f;
      if ( 0.0 == y1f )
        v13 = (float)1.0;
      kSolida = *(float *)&p[5].pNext - *(float *)(a5 + 96) - *(float *)&p[1].pNext + *(float *)&p->pExceptionObject;
      if ( kSolida > v13 )
        kSolida = v13;
      kTotald = *(float *)&p[4].pNext - *(float *)(a5 + 96);
      kSolid = (kTotald + kSolida) / (v13 * 2.0);
      y1 = *(float *)(a5 + 152) - *(float *)(a5 + 100);
      if ( y1 == 0.0 )
        y1 = 1.0;
      v14 = a1 + 64;
      v129 = *(_DWORD *)(a1 + 16);
      kTotale = *(float *)&p[4].pNext - *(float *)(a5 + 100) + *(float *)&p[1].pNext - *(float *)&p->pExceptionObject;
      v15 = kTotale;
      v16 = *(_DWORD *)(a1 + 64) >> 8;
      kTotalf = *(float *)&p[5].pNext - *(float *)(a5 + 100);
      kTotal = (v15 + kTotalf) / (2.0 * y1);
      x1f = *a3 - *(float *)a5;
      y1g = a3[1] - *(float *)(a5 + 4);
      v17 = x1f;
      x1 = v16;
      v96 = v17 + (*(float *)(a5 + 184) - v17) * kSolid;
      v116 = kSolid * (*(float *)(a5 + 188) - y1g) + y1g;
      if ( v16 >= *(_DWORD *)(a1 + 68) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)(a1 + 64),
          result: v16,
          nb: v95);
        v16 = x1;
      }
      v18 = *(_DWORD *)(*(_DWORD *)(a1 + 76) + 4 * v16) + 12 * (unsigned __int8)*(_DWORD *)(a1 + 64);
      *(float *)v18 = v96;
      *(float *)(v18 + 4) = v116;
      *(_DWORD *)(v18 + 8) = v129;
      ++*(_DWORD *)v14;
      v19 = p;
      v20 = *(_DWORD *)v14 - 1;
      newSolidL = (EHRegistrationNode *)v20;
    }
    v23 = kTotal;
    if ( BYTE2(v19[6].pNext) != 0 )
    {
      v24 = *(_DWORD *)v14 >> 8;
      x1g = *a3 - *(float *)(a5 + 8);
      y1h = a3[1] - *(float *)(a5 + 12);
      v25 = x1g;
      x1a = v24;
      v98 = (*(float *)(a5 + 136) - v25) * v23 + v25;
      v118 = v23 * (*(float *)(a5 + 140) - y1h) + y1h;
      if ( v24 >= *(_DWORD *)(v14 + 4) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)v14,
          result: v24,
          nb: v95);
        v24 = x1a;
      }
      v26 = *(_DWORD *)(*(_DWORD *)(v14 + 12) + 4 * v24) + 12 * (unsigned __int8)*(_DWORD *)v14;
      *(float *)v26 = v98;
      v19 = p;
      *(float *)(v26 + 4) = v118;
      *(_DWORD *)(v26 + 8) = -1;
      ++*(_DWORD *)v14;
      v20 = (int)newSolidL;
      x1b = *(_DWORD *)v14 - 1;
    }
    else
    {
      x1b = v20;
    }
    if ( LOBYTE(v19[7].pExceptionObject) != 0 )
    {
      v27 = *(_DWORD *)v14 >> 8;
      v119 = ySolid;
      v131 = *(_DWORD *)(a1 + 20);
      ySolida = v27;
      if ( v27 >= *(_DWORD *)(v14 + 4) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)v14,
          result: v27,
          nb: v95);
        v27 = ySolida;
      }
      v28 = *(_DWORD *)(*(_DWORD *)(v14 + 12) + 4 * v27) + 12 * (unsigned __int8)*(_DWORD *)v14;
      *(float *)v28 = xSolid;
      *(float *)(v28 + 4) = v119;
      v20 = (int)newSolidL;
      *(_DWORD *)(v28 + 8) = v131;
      ++*(_DWORD *)v14;
      v19 = p;
      v29 = *(_DWORD *)v14 - 1;
      newSolidR = v29;
    }
    else
    {
      v29 = v20;
      newSolidR = v20;
    }
    if ( HIBYTE(v19[6].pNext) != 0 )
    {
      v30 = *(_DWORD *)v14 >> 8;
      ySolidb = v30;
      if ( v30 >= *(_DWORD *)(v14 + 4) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)v14,
          result: v30,
          nb: v95);
        v30 = ySolidb;
      }
      v31 = *(_DWORD *)(*(_DWORD *)(v14 + 12) + 4 * v30) + 12 * (unsigned __int8)*(_DWORD *)v14;
      *(float *)v31 = xTotal;
      v19 = p;
      *(float *)(v31 + 4) = yTotal;
      *(_DWORD *)(v31 + 8) = -1;
      ++*(_DWORD *)v14;
      v20 = (int)newSolidL;
      v29 = *(_DWORD *)v14 - 1;
    }
    y1b = v29;
    if ( LOBYTE(v19[6].pNext) != 0 || BYTE1(v19[6].pNext) != 0 )
    {
      v32 = *(_DWORD *)(a1 + 80) >> 8;
      v99 = *(_DWORD *)(a1 + 96);
      ySolidc = v32;
      if ( v32 >= *(_DWORD *)(a1 + 84) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)(a1 + 80),
          result: v32,
          nb: v95);
        v32 = ySolidc;
      }
      v33 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 92) + 4 * v32) + 12 * (unsigned __int8)*(_DWORD *)(a1 + 80));
      *v33 = v99;
      v33[1] = newSolidR;
      v33[2] = newSolidL;
      ++*(_DWORD *)(a1 + 80);
      v120 = *(_DWORD *)(a1 + 100);
      v34 = *(_DWORD *)(a1 + 80) >> 8;
      v100 = *(_DWORD *)(a1 + 96);
      ySolidd = v34;
      if ( v34 >= *(_DWORD *)(a1 + 84) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)(a1 + 80),
          result: v34,
          nb: v95);
        v34 = ySolidd;
      }
      v35 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 92) + 4 * v34) + 12 * (unsigned __int8)*(_DWORD *)(a1 + 80));
      *v35 = v100;
      v35[1] = v120;
      v20 = (int)newSolidL;
      v35[2] = newSolidR;
      ++*(_DWORD *)(a1 + 80);
      v19 = p;
      v29 = y1b;
    }
    if ( BYTE2(v19[6].pNext) != 0 )
    {
      v121 = *(_DWORD *)(a1 + 96);
      v36 = *(_DWORD *)(a1 + 80) >> 8;
      v101 = *(_DWORD *)(a1 + 104);
      ySolide = v36;
      if ( v36 >= *(_DWORD *)(a1 + 84) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)(a1 + 80),
          result: v36,
          nb: v95);
        v36 = ySolide;
      }
      v37 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 92) + 4 * v36) + 12 * (unsigned __int8)*(_DWORD *)(a1 + 80));
      *v37 = v101;
      v37[1] = v121;
      v37[2] = newSolidL;
      v38 = ++*(_DWORD *)(a1 + 80) >> 8;
      v102 = *(_DWORD *)(a1 + 104);
      ySolidf = v38;
      if ( v38 >= *(_DWORD *)(a1 + 84) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)(a1 + 80),
          result: v38,
          nb: v95);
        v38 = ySolidf;
      }
      v39 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 92) + 4 * v38) + 12 * (unsigned __int8)*(_DWORD *)(a1 + 80));
      v20 = (int)newSolidL;
      *v39 = v102;
      v39[1] = newSolidL;
      v39[2] = x1b;
      ++*(_DWORD *)(a1 + 80);
      v19 = p;
      v29 = y1b;
    }
    if ( HIBYTE(v19[6].pNext) != 0 )
    {
      v40 = *(_DWORD *)(a1 + 80) >> 8;
      v103 = *(_DWORD *)(a1 + 100);
      ySolidg = v40;
      if ( v40 >= *(_DWORD *)(a1 + 84) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)(a1 + 80),
          result: v40,
          nb: v95);
        v40 = ySolidg;
      }
      v41 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 92) + 4 * v40) + 12 * (unsigned __int8)*(_DWORD *)(a1 + 80));
      *v41 = v103;
      v41[1] = y1b;
      v41[2] = newSolidR;
      ++*(_DWORD *)(a1 + 80);
      v122 = *(_DWORD *)(a1 + 108);
      v42 = *(_DWORD *)(a1 + 80) >> 8;
      v104 = *(_DWORD *)(a1 + 100);
      ySolidh = v42;
      if ( v42 >= *(_DWORD *)(a1 + 84) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)(a1 + 80),
          result: v42,
          nb: v95);
        v42 = ySolidh;
      }
      v43 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 92) + 4 * v42) + 12 * (unsigned __int8)*(_DWORD *)(a1 + 80));
      *v43 = v104;
      v19 = p;
      v43[1] = v122;
      v29 = y1b;
      v43[2] = y1b;
      ++*(_DWORD *)(a1 + 80);
      v20 = (int)newSolidL;
    }
    *(_DWORD *)(a1 + 96) = v20;
    *(_DWORD *)(a1 + 104) = x1b;
    *(_DWORD *)(a1 + 100) = newSolidR;
    *(_DWORD *)(a1 + 108) = v29;
    if ( overlap )
    {
      v44 = *(_DWORD *)v14 >> 8;
      v105 = *(float *)(a5 + 64) + *a3;
      v132 = *(_DWORD *)(a1 + 20);
      v215 = v44;
      v123 = *(float *)(a5 + 68) + a3[1];
      if ( v44 >= *(_DWORD *)(v14 + 4) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)v14,
          result: v44,
          nb: v95);
        v44 = v215;
      }
      v45 = *(_DWORD *)(*(_DWORD *)(v14 + 12) + 4 * v44) + 12 * (unsigned __int8)*(_DWORD *)v14;
      *(float *)v45 = v105;
      *(float *)(v45 + 4) = v123;
      *(_DWORD *)(v45 + 8) = v132;
      *(_DWORD *)(a1 + 100) = (*(_DWORD *)v14)++;
      if ( HIBYTE(p[6].pNext) != 0 )
      {
        v216 = *(float *)(a5 + 76) + a3[1];
        v87 = v216;
        v217 = *(float *)(a5 + 72) + *a3;
        v46 = GStrokerAA::addVertex(this: (GStrokerAA *)a1, a2: v14, x: v217, y: v87, id: -1);
      }
      else
      {
        v46 = (EHRegistrationNode *)newSolidR;
      }
      v19 = p;
      *(_DWORD *)(a1 + 108) = v46;
    }
    v218 = *(float *)(a1 + 40) * 0.25 * 0.25;
    if ( v218 < *(float *)&v19[1].pNext - *(float *)(a5 + 100) )
    {
      if ( LOBYTE(v19[7].pExceptionObject) != 0 )
      {
        if ( lineJoin != 0 )
        {
          lineJoinc = a3[1] - *(float *)(a5 + 20);
          v89 = lineJoinc;
          lineJoind = *a3 - *(float *)(a5 + 16);
          newSolidL = GStrokerAA::addVertex(
                        this: (GStrokerAA *)a1,
                        a2: v14,
                        x: lineJoind,
                        y: v89,
                        id: *(_DWORD *)(a1 + 16));
        }
        else
        {
          x1h = *a3 - *(float *)(a5 + 16);
          y1i = a3[1] - *(float *)(a5 + 20);
          lineJoina = y1i + (*(float *)(a5 + 188) - y1i) * kSolid;
          v88 = lineJoina;
          lineJoinb = kSolid * (*(float *)(a5 + 184) - x1h) + x1h;
          newSolidL = GStrokerAA::addVertex(
                        this: (GStrokerAA *)a1,
                        a2: v14,
                        x: lineJoinb,
                        y: v88,
                        id: *(_DWORD *)(a1 + 16));
        }
      }
      if ( BYTE2(p[6].pNext) != 0 )
      {
        x1i = *a3 - *(float *)(a5 + 24);
        y1j = a3[1] - *(float *)(a5 + 28);
        v211 = y1j + (*(float *)(a5 + 140) - y1j) * kTotal;
        v90 = v211;
        v212 = kTotal * (*(float *)(a5 + 136) - x1i) + x1i;
        v47 = (unsigned int)newSolidL;
        v48 = GStrokerAA::addVertex(this: (GStrokerAA *)a1, a2: v14, x: v212, y: v90, id: -1);
      }
      else
      {
        v47 = (unsigned int)newSolidL;
        v48 = newSolidL;
      }
      if ( LOBYTE(p[6].pNext) != 0 )
        GStrokerAA::addTriangle(this: (GStrokerAA *)a1, a2: *(_DWORD *)(a1 + 100), a3: v47, a4: *(_DWORD *)(a1 + 96));
      if ( BYTE2(p[6].pNext) != 0 )
      {
        GStrokerAA::addTriangle(this: (GStrokerAA *)a1, a2: *(_DWORD *)(a1 + 96), a3: v47, a4: *(_DWORD *)(a1 + 104));
        GStrokerAA::addTriangle(this: (GStrokerAA *)a1, a2: *(_DWORD *)(a1 + 104), a3: v47, a4: (unsigned int)v48);
      }
      *(_DWORD *)(a1 + 104) = v48;
      *(_DWORD *)(a1 + 96) = v47;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10197DC0
// Name: private: void GStrokerAA::calcButtJoin(struct GStrokeVertexType const __near &,struct GStrokeVertexType const __near &,float,struct GStrokerAA::WidthsType const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge GStrokerAA::calcButtJoin@<eax>(
        EHExceptionRecord *this@<ecx>,
        char a2@<dil>,
        EHRegistrationNode *v0,
        float *v1,
        float len,
        int w)
{
  int v8; // edi
  double v9; // st6
  unsigned int v10; // ecx
  double v11; // st5
  double v12; // st7
  int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // ecx
  int v16; // eax
  unsigned int v17; // ecx
  int v18; // eax
  unsigned int v19; // eax
  double v21; // st7
  unsigned int v22; // ecx
  int v23; // eax
  unsigned int v24; // esi
  _DWORD *v25; // eax
  unsigned int v26; // esi
  _DWORD *v27; // eax
  unsigned int v28; // esi
  _DWORD *v29; // eax
  unsigned int v30; // esi
  _DWORD *v31; // eax
  unsigned int v32; // esi
  _DWORD *v33; // eax
  unsigned int v34; // esi
  _DWORD *v35; // eax
  char v37; // [esp-4h] [ebp-F8h]
  float v38; // [esp+8h] [ebp-ECh]
  float v39; // [esp+Ch] [ebp-E8h]
  float v40; // [esp+10h] [ebp-E4h]
  float v41; // [esp+14h] [ebp-E0h]
  float v42; // [esp+38h] [ebp-BCh]
  float v43; // [esp+3Ch] [ebp-B8h]
  float v44; // [esp+40h] [ebp-B4h]
  float v45; // [esp+44h] [ebp-B0h]
  unsigned int newTotalL; // [esp+E4h] [ebp-10h]
  float v47; // [esp+E8h] [ebp-Ch]
  float v48; // [esp+E8h] [ebp-Ch]
  float v49; // [esp+E8h] [ebp-Ch]
  float v50; // [esp+E8h] [ebp-Ch]
  int v51; // [esp+E8h] [ebp-Ch]
  int v52; // [esp+E8h] [ebp-Ch]
  int v53; // [esp+E8h] [ebp-Ch]
  int v54; // [esp+E8h] [ebp-Ch]
  int v55; // [esp+E8h] [ebp-Ch]
  int v56; // [esp+E8h] [ebp-Ch]
  float v57; // [esp+ECh] [ebp-8h]
  float v58; // [esp+ECh] [ebp-8h]
  float v59; // [esp+ECh] [ebp-8h]
  float v60; // [esp+ECh] [ebp-8h]
  int v61; // [esp+ECh] [ebp-8h]
  int v62; // [esp+ECh] [ebp-8h]
  int v63; // [esp+ECh] [ebp-8h]
  unsigned int NumberParameters; // [esp+F0h] [ebp-4h]
  unsigned int magicNumber; // [esp+F0h] [ebp-4h]
  float newSolidRd; // [esp+FCh] [ebp+8h]
  unsigned int newSolidR; // [esp+FCh] [ebp+8h]
  unsigned int newSolidRa; // [esp+FCh] [ebp+8h]
  unsigned int newSolidRb; // [esp+FCh] [ebp+8h]
  unsigned int newSolidRc; // [esp+FCh] [ebp+8h]
  unsigned int newTotalR; // [esp+100h] [ebp+Ch]
  unsigned int newTotalRa; // [esp+100h] [ebp+Ch]
  float newSolidLa; // [esp+104h] [ebp+10h]
  unsigned int newSolidL; // [esp+104h] [ebp+10h]

  v37 = a2;
  v8 = w;
  newSolidRd = (v1[1] - *(float *)&v0->frameHandler) / len;
  v9 = *(float *)&v0->pNext - *v1;
  v10 = *((_DWORD *)this + 16) >> 8;
  newSolidLa = v9 / len;
  v11 = newSolidRd;
  v12 = *(float *)w * newSolidRd;
  newSolidR = v10;
  v38 = v12;
  v39 = *(float *)w * newSolidLa;
  v42 = v11 * *(float *)(w + 4);
  v43 = newSolidLa * *(float *)(w + 4);
  v40 = v11 * *(float *)(w + 12);
  v41 = newSolidLa * *(float *)(w + 12);
  v44 = v11 * *(float *)(w + 16);
  v45 = newSolidLa * *(float *)(w + 16);
  v47 = *v1 - v38;
  NumberParameters = this->NumberParameters;
  v57 = v1[1] - v39;
  if ( v10 >= *((_DWORD *)this + 17) )
  {
    GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
      this: (DName *)this + 8,
      result: v10,
      nb: v37);
    v10 = newSolidR;
  }
  v13 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v10) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
  *(float *)v13 = v47;
  *(float *)(v13 + 4) = v57;
  *(_DWORD *)(v13 + 8) = NumberParameters;
  v14 = (*((_DWORD *)this + 16))++;
  newSolidL = v14;
  if ( *(_BYTE *)(w + 54) != 0 )
  {
    v15 = *((_DWORD *)this + 16) >> 8;
    newSolidRa = v15;
    v48 = *v1 - v40;
    v58 = v1[1] - v41;
    if ( v15 >= *((_DWORD *)this + 17) )
    {
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 8,
        result: v15,
        nb: v37);
      v15 = newSolidRa;
    }
    v16 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v15) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
    *(float *)v16 = v48;
    *(float *)(v16 + 4) = v58;
    *(_DWORD *)(v16 + 8) = -1;
    v14 = (*((_DWORD *)this + 16))++;
  }
  newTotalL = v14;
  if ( *(_BYTE *)(w + 56) != 0 )
  {
    v17 = *((_DWORD *)this + 16) >> 8;
    magicNumber = this->params.magicNumber;
    v49 = *v1 + v42;
    newSolidRb = v17;
    v59 = v43 + v1[1];
    if ( v17 >= *((_DWORD *)this + 17) )
    {
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 8,
        result: v17,
        nb: v37);
      v17 = newSolidRb;
    }
    v18 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v17) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
    *(float *)v18 = v49;
    *(float *)(v18 + 4) = v59;
    *(_DWORD *)(v18 + 8) = magicNumber;
    v19 = (*((_DWORD *)this + 16))++;
  }
  else
  {
    v19 = newSolidL;
  }
  newSolidRc = v19;
  if ( *(_BYTE *)(w + 55) != 0 )
  {
    v21 = *v1 + v44;
    v22 = *((_DWORD *)this + 16) >> 8;
    newTotalR = v22;
    v60 = v45 + v1[1];
    if ( v22 >= *((_DWORD *)this + 17) )
    {
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 8,
        result: v22,
        nb: v37);
      v22 = newTotalR;
    }
    v23 = *(_DWORD *)(*((_DWORD *)this + 19) + 4 * v22) + 12 * (unsigned __int8)*((_DWORD *)this + 16);
    v50 = v21;
    *(float *)v23 = v50;
    *(float *)(v23 + 4) = v60;
    *(_DWORD *)(v23 + 8) = -1;
    newTotalRa = (*((_DWORD *)this + 16))++;
  }
  else
  {
    newTotalRa = v19;
  }
  if ( *(_BYTE *)(w + 52) != 0 || *(_BYTE *)(w + 53) != 0 )
  {
    v24 = *((_DWORD *)this + 20) >> 8;
    v51 = *((_DWORD *)this + 24);
    if ( v24 >= *((_DWORD *)this + 21) )
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 10,
        result: v24,
        nb: v37);
    v25 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v24) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
    *v25 = v51;
    v25[1] = newSolidRc;
    v25[2] = newSolidL;
    v26 = ++*((_DWORD *)this + 20) >> 8;
    v52 = *((_DWORD *)this + 24);
    v61 = *((_DWORD *)this + 25);
    if ( v26 >= *((_DWORD *)this + 21) )
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 10,
        result: v26,
        nb: v37);
    v27 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v26) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
    *v27 = v52;
    v27[1] = v61;
    v27[2] = newSolidRc;
    ++*((_DWORD *)this + 20);
  }
  if ( *(_BYTE *)(w + 54) != 0 )
  {
    v28 = *((_DWORD *)this + 20) >> 8;
    v53 = *((_DWORD *)this + 26);
    v62 = *((_DWORD *)this + 24);
    if ( v28 >= *((_DWORD *)this + 21) )
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 10,
        result: v28,
        nb: v37);
    v29 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v28) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
    *v29 = v53;
    v29[1] = v62;
    v29[2] = newSolidL;
    v30 = ++*((_DWORD *)this + 20) >> 8;
    v54 = *((_DWORD *)this + 26);
    if ( v30 >= *((_DWORD *)this + 21) )
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 10,
        result: v30,
        nb: v37);
    v8 = w;
    v31 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v30) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
    *v31 = v54;
    v31[1] = newSolidL;
    v31[2] = newTotalL;
    ++*((_DWORD *)this + 20);
  }
  if ( *(_BYTE *)(v8 + 55) != 0 )
  {
    v32 = *((_DWORD *)this + 20) >> 8;
    v55 = *((_DWORD *)this + 25);
    if ( v32 >= *((_DWORD *)this + 21) )
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 10,
        result: v32,
        nb: v37);
    v33 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v32) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
    *v33 = v55;
    v33[1] = newTotalRa;
    v33[2] = newSolidRc;
    v34 = ++*((_DWORD *)this + 20) >> 8;
    v56 = *((_DWORD *)this + 25);
    v63 = *((_DWORD *)this + 27);
    if ( v34 >= *((_DWORD *)this + 21) )
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)this + 10,
        result: v34,
        nb: v37);
    v35 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 23) + 4 * v34) + 12 * (unsigned __int8)*((_DWORD *)this + 20));
    *v35 = v56;
    v35[1] = v63;
    v35[2] = newTotalRa;
    ++*((_DWORD *)this + 20);
  }
  *((_DWORD *)this + 24) = newSolidL;
  *((_DWORD *)this + 26) = newTotalL;
  *((_DWORD *)this + 25) = newSolidRc;
  *((_DWORD *)this + 27) = newTotalRa;
  return newTotalL;
}

//------------------------------------------------------------------------------
// Address: 0x10198200
// Name: private: void GStrokerAA::calcMiterJoin(struct GStrokeVertexType const __near &,struct GStrokerAA::WidthsType const __near &,struct GStrokerAA::JoinParamType __near &,enum GStrokerTypes::LineJoinType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStrokerAA::calcMiterJoin(int this, float *v1, float *w, struct GStrokerAA::JoinParamType *n, int a5)
{
  struct GStrokerAA::JoinParamType *v5; // edi
  int v7; // eax
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  unsigned int v12; // ecx
  int v13; // eax
  float *v14; // eax
  unsigned int v15; // ecx
  int v16; // eax
  unsigned int v17; // ecx
  int v18; // eax
  unsigned int v19; // ecx
  int v20; // eax
  unsigned int v21; // ecx
  _DWORD *v22; // eax
  unsigned int v23; // ecx
  _DWORD *v24; // eax
  unsigned int v25; // ecx
  _DWORD *v26; // eax
  unsigned int v27; // ecx
  _DWORD *v28; // eax
  unsigned int v29; // ecx
  _DWORD *v30; // eax
  unsigned int v31; // ecx
  _DWORD *v32; // eax
  unsigned int v33; // ecx
  int v34; // eax
  unsigned int v35; // ecx
  int v36; // eax
  float v37; // [esp+4h] [ebp-44h]
  float v38; // [esp+4h] [ebp-44h]
  char v39; // [esp+Ch] [ebp-3Ch]
  int v40; // [esp+18h] [ebp-30h]
  int v41; // [esp+18h] [ebp-30h]
  int v42; // [esp+18h] [ebp-30h]
  int v43; // [esp+18h] [ebp-30h]
  int v44; // [esp+18h] [ebp-30h]
  int v45; // [esp+18h] [ebp-30h]
  float v46; // [esp+18h] [ebp-30h]
  float v47; // [esp+18h] [ebp-30h]
  int v48; // [esp+1Ch] [ebp-2Ch]
  int v49; // [esp+1Ch] [ebp-2Ch]
  int v50; // [esp+1Ch] [ebp-2Ch]
  float v51; // [esp+1Ch] [ebp-2Ch]
  float v52; // [esp+1Ch] [ebp-2Ch]
  int v53; // [esp+20h] [ebp-28h]
  int v54; // [esp+20h] [ebp-28h]
  int v55; // [esp+20h] [ebp-28h]
  int v56; // [esp+20h] [ebp-28h]
  float ySolidR; // [esp+24h] [ebp-24h]
  unsigned int ySolidRa; // [esp+24h] [ebp-24h]
  unsigned int ySolidRb; // [esp+24h] [ebp-24h]
  unsigned int ySolidRc; // [esp+24h] [ebp-24h]
  unsigned int ySolidRd; // [esp+24h] [ebp-24h]
  unsigned int ySolidRe; // [esp+24h] [ebp-24h]
  unsigned int ySolidRf; // [esp+24h] [ebp-24h]
  unsigned int ySolidRg; // [esp+24h] [ebp-24h]
  float xSolidR; // [esp+28h] [ebp-20h]
  float ySolidL; // [esp+2Ch] [ebp-1Ch]
  float yTotalR; // [esp+30h] [ebp-18h]
  unsigned int yTotalRa; // [esp+30h] [ebp-18h]
  float xTotalR; // [esp+34h] [ebp-14h]
  float yTotalL; // [esp+38h] [ebp-10h]
  int yTotalLa; // [esp+38h] [ebp-10h]
  float xTotalL; // [esp+3Ch] [ebp-Ch]
  float newSolidL; // [esp+40h] [ebp-8h]
  unsigned int newSolidLa; // [esp+40h] [ebp-8h]
  char overlap; // [esp+47h] [ebp-1h]
  float newSolidR; // [esp+54h] [ebp+Ch]
  float newSolidRa; // [esp+54h] [ebp+Ch]
  float newSolidRb; // [esp+54h] [ebp+Ch]
  float newSolidRc; // [esp+54h] [ebp+Ch]
  struct GStrokerAA::JoinParamType *na; // [esp+58h] [ebp+10h]
  struct GStrokerAA::JoinParamType *nb; // [esp+58h] [ebp+10h]
  unsigned int v82; // [esp+5Ch] [ebp+14h]
  unsigned int v83; // [esp+5Ch] [ebp+14h]
  unsigned int v84; // [esp+5Ch] [ebp+14h]
  unsigned int v85; // [esp+5Ch] [ebp+14h]

  v5 = n;
  overlap = *((_BYTE *)n + 217) | *((_BYTE *)n + 218);
  if ( *((_BYTE *)n + 215) == 0 )
  {
    xTotalR = *((float *)n + 36);
    yTotalR = *((float *)n + 37);
    xSolidR = (xTotalR - *v1) * w[8] + *v1;
    ySolidR = (yTotalR - v1[1]) * w[8] + v1[1];
    if ( w[12] < (double)*((float *)n + 39) )
    {
      v7 = a5;
      if ( a5 >= 0 )
      {
        if ( a5 <= 1 )
          goto LABEL_7;
        if ( a5 == 2 )
          goto LABEL_6;
      }
    }
    if ( *(_WORD *)((char *)n + 217) != 0 )
      v10 = *v1 - *((float *)n + 2);
    else
      v10 = *((float *)n + 34);
    xTotalL = v10;
    if ( *(_WORD *)((char *)n + 217) != 0 )
      v11 = v1[1] - *((float *)n + 3);
    else
      v11 = *((float *)n + 35);
    yTotalL = v11;
    newSolidL = (xTotalL - *v1) * w[7] + *v1;
    ySolidL = (yTotalL - v1[1]) * w[7] + v1[1];
    goto LABEL_26;
  }
  xTotalL = *((float *)n + 34);
  yTotalL = *((float *)n + 35);
  newSolidL = (xTotalL - *v1) * w[7] + *v1;
  ySolidL = (yTotalL - v1[1]) * w[7] + v1[1];
  if ( w[11] < (double)*((float *)n + 38) )
  {
    v7 = a5;
    if ( a5 >= 0 )
    {
      if ( a5 > 1 )
      {
        if ( a5 == 2 )
        {
LABEL_6:
          GStrokerAA::calcRoundJoin((GStrokerAA *)this, a2: (const struct GStrokeVertexType *)v1, p: (FrameInfo *)w, n);
          return;
        }
        goto LABEL_8;
      }
LABEL_7:
      GStrokerAA::calcBevelJoin(a1: this, a2: (char)n, a3: v1, p: (FrameInfo *)w, a5: (int)n, lineJoin: v7);
      return;
    }
  }
LABEL_8:
  if ( *(_WORD *)((char *)n + 217) != 0 )
    v8 = *((float *)n + 14) + *v1;
  else
    v8 = *((float *)n + 36);
  xTotalR = v8;
  if ( *(_WORD *)((char *)n + 217) != 0 )
    v9 = *((float *)n + 15) + v1[1];
  else
    v9 = *((float *)n + 37);
  yTotalR = v9;
  xSolidR = (xTotalR - *v1) * w[8] + *v1;
  ySolidR = (yTotalR - v1[1]) * w[8] + v1[1];
LABEL_26:
  v12 = *(_DWORD *)(this + 64) >> 8;
  v53 = *(_DWORD *)(this + 16);
  v82 = v12;
  if ( v12 >= *(_DWORD *)(this + 68) )
  {
    GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
      this: (DName *)(this + 64),
      result: v12,
      nb: v39);
    v12 = v82;
  }
  v13 = *(_DWORD *)(*(_DWORD *)(this + 76) + 4 * v12) + 12 * (unsigned __int8)*(_DWORD *)(this + 64);
  *(float *)v13 = newSolidL;
  *(float *)(v13 + 4) = ySolidL;
  *(_DWORD *)(v13 + 8) = v53;
  ++*(_DWORD *)(this + 64);
  v14 = w;
  newSolidLa = *(_DWORD *)(this + 64) - 1;
  if ( *((_BYTE *)w + 54) != 0 )
  {
    v15 = *(_DWORD *)(this + 64) >> 8;
    v83 = v15;
    if ( v15 >= *(_DWORD *)(this + 68) )
    {
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)(this + 64),
        result: v15,
        nb: v39);
      v15 = v83;
    }
    v16 = *(_DWORD *)(*(_DWORD *)(this + 76) + 4 * v15) + 12 * (unsigned __int8)*(_DWORD *)(this + 64);
    *(float *)v16 = xTotalL;
    *(float *)(v16 + 4) = yTotalL;
    *(_DWORD *)(v16 + 8) = -1;
    yTotalLa = (*(_DWORD *)(this + 64))++;
    v14 = w;
  }
  else
  {
    yTotalLa = *(_DWORD *)(this + 64) - 1;
  }
  if ( *((_BYTE *)v14 + 56) != 0 )
  {
    v17 = *(_DWORD *)(this + 64) >> 8;
    v54 = *(_DWORD *)(this + 20);
    v84 = v17;
    if ( v17 >= *(_DWORD *)(this + 68) )
    {
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)(this + 64),
        result: v17,
        nb: v39);
      v17 = v84;
    }
    v18 = *(_DWORD *)(*(_DWORD *)(this + 76) + 4 * v17) + 12 * (unsigned __int8)*(_DWORD *)(this + 64);
    *(float *)v18 = xSolidR;
    *(float *)(v18 + 4) = ySolidR;
    *(_DWORD *)(v18 + 8) = v54;
    v85 = (*(_DWORD *)(this + 64))++;
    v14 = w;
  }
  else
  {
    v85 = newSolidLa;
  }
  if ( *((_BYTE *)v14 + 55) != 0 )
  {
    v19 = *(_DWORD *)(this + 64) >> 8;
    ySolidRa = v19;
    if ( v19 >= *(_DWORD *)(this + 68) )
    {
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)(this + 64),
        result: v19,
        nb: v39);
      v19 = ySolidRa;
    }
    v20 = *(_DWORD *)(*(_DWORD *)(this + 76) + 4 * v19) + 12 * (unsigned __int8)*(_DWORD *)(this + 64);
    *(float *)v20 = xTotalR;
    *(float *)(v20 + 4) = yTotalR;
    *(_DWORD *)(v20 + 8) = -1;
    yTotalRa = (*(_DWORD *)(this + 64))++;
    v14 = w;
  }
  else
  {
    yTotalRa = v85;
  }
  if ( *((_BYTE *)v14 + 52) != 0 || *((_BYTE *)v14 + 53) != 0 )
  {
    v21 = *(_DWORD *)(this + 80) >> 8;
    v40 = *(_DWORD *)(this + 96);
    ySolidRb = v21;
    if ( v21 >= *(_DWORD *)(this + 84) )
    {
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)(this + 80),
        result: v21,
        nb: v39);
      v21 = ySolidRb;
    }
    v22 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 92) + 4 * v21) + 12 * (unsigned __int8)*(_DWORD *)(this + 80));
    *v22 = v40;
    v22[1] = v85;
    v22[2] = newSolidLa;
    ++*(_DWORD *)(this + 80);
    v48 = *(_DWORD *)(this + 100);
    v23 = *(_DWORD *)(this + 80) >> 8;
    v41 = *(_DWORD *)(this + 96);
    ySolidRc = v23;
    if ( v23 >= *(_DWORD *)(this + 84) )
    {
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)(this + 80),
        result: v23,
        nb: v39);
      v23 = ySolidRc;
    }
    v24 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 92) + 4 * v23) + 12 * (unsigned __int8)*(_DWORD *)(this + 80));
    *v24 = v41;
    v24[1] = v48;
    v24[2] = v85;
    ++*(_DWORD *)(this + 80);
    v14 = w;
  }
  if ( *((_BYTE *)v14 + 54) != 0 )
  {
    v49 = *(_DWORD *)(this + 96);
    v25 = *(_DWORD *)(this + 80) >> 8;
    v42 = *(_DWORD *)(this + 104);
    ySolidRd = v25;
    if ( v25 >= *(_DWORD *)(this + 84) )
    {
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)(this + 80),
        result: v25,
        nb: v39);
      v25 = ySolidRd;
    }
    v26 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 92) + 4 * v25) + 12 * (unsigned __int8)*(_DWORD *)(this + 80));
    *v26 = v42;
    v26[1] = v49;
    v26[2] = newSolidLa;
    v27 = ++*(_DWORD *)(this + 80) >> 8;
    v43 = *(_DWORD *)(this + 104);
    ySolidRe = v27;
    if ( v27 >= *(_DWORD *)(this + 84) )
    {
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)(this + 80),
        result: v27,
        nb: v39);
      v27 = ySolidRe;
    }
    v5 = n;
    v28 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 92) + 4 * v27) + 12 * (unsigned __int8)*(_DWORD *)(this + 80));
    *v28 = v43;
    v28[1] = newSolidLa;
    v28[2] = yTotalLa;
    ++*(_DWORD *)(this + 80);
    v14 = w;
  }
  if ( *((_BYTE *)v14 + 55) != 0 )
  {
    v29 = *(_DWORD *)(this + 80) >> 8;
    v44 = *(_DWORD *)(this + 100);
    ySolidRf = v29;
    if ( v29 >= *(_DWORD *)(this + 84) )
    {
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)(this + 80),
        result: v29,
        nb: v39);
      v29 = ySolidRf;
    }
    v30 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 92) + 4 * v29) + 12 * (unsigned __int8)*(_DWORD *)(this + 80));
    *v30 = v44;
    v30[1] = yTotalRa;
    v30[2] = v85;
    ++*(_DWORD *)(this + 80);
    v50 = *(_DWORD *)(this + 108);
    v31 = *(_DWORD *)(this + 80) >> 8;
    v45 = *(_DWORD *)(this + 100);
    ySolidRg = v31;
    if ( v31 >= *(_DWORD *)(this + 84) )
    {
      GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
        this: (DName *)(this + 80),
        result: v31,
        nb: v39);
      v31 = ySolidRg;
    }
    v5 = n;
    v32 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 92) + 4 * v31) + 12 * (unsigned __int8)*(_DWORD *)(this + 80));
    *v32 = v45;
    v32[1] = v50;
    v32[2] = yTotalRa;
    ++*(_DWORD *)(this + 80);
  }
  *(_DWORD *)(this + 96) = newSolidLa;
  *(_DWORD *)(this + 104) = yTotalLa;
  *(_DWORD *)(this + 100) = v85;
  *(_DWORD *)(this + 108) = yTotalRa;
  if ( overlap != 0 )
  {
    if ( *((_BYTE *)v5 + 215) != 0 )
    {
      v55 = *(_DWORD *)(this + 20);
      v33 = *(_DWORD *)(this + 64) >> 8;
      v46 = *((float *)v5 + 16) + *v1;
      na = (struct GStrokerAA::JoinParamType *)v33;
      v51 = *((float *)v5 + 17) + v1[1];
      if ( v33 >= *(_DWORD *)(this + 68) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)(this + 64),
          result: v33,
          nb: v39);
        v33 = (unsigned int)na;
      }
      v34 = *(_DWORD *)(*(_DWORD *)(this + 76) + 4 * v33) + 12 * (unsigned __int8)*(_DWORD *)(this + 64);
      *(float *)v34 = v46;
      *(float *)(v34 + 4) = v51;
      *(_DWORD *)(v34 + 8) = v55;
      *(_DWORD *)(this + 100) = (*(_DWORD *)(this + 64))++;
      if ( *((_BYTE *)w + 55) != 0 )
      {
        newSolidR = *((float *)v5 + 19) + v1[1];
        v37 = newSolidR;
        newSolidRa = *((float *)v5 + 18) + *v1;
        *(_DWORD *)(this + 108) = GStrokerAA::addVertex((GStrokerAA *)this, a2: (char)v5, x: newSolidRa, y: v37, id: -1);
      }
      else
      {
        *(_DWORD *)(this + 108) = v85;
      }
    }
    else
    {
      v35 = *(_DWORD *)(this + 64) >> 8;
      v56 = *(_DWORD *)(this + 16);
      v47 = *v1 - *((float *)v5 + 4);
      nb = (struct GStrokerAA::JoinParamType *)v35;
      v52 = v1[1] - *((float *)v5 + 5);
      if ( v35 >= *(_DWORD *)(this + 68) )
      {
        GArrayPagedBase<GStrokerAA::VertexType,8,64,GAllocatorPagedLH_POD<GStrokerAA::VertexType,137>>::allocatePage(
          this: (DName *)(this + 64),
          result: v35,
          nb: v39);
        v35 = (unsigned int)nb;
      }
      v36 = *(_DWORD *)(*(_DWORD *)(this + 76) + 4 * v35) + 12 * (unsigned __int8)*(_DWORD *)(this + 64);
      *(float *)v36 = v47;
      *(float *)(v36 + 4) = v52;
      *(_DWORD *)(v36 + 8) = v56;
      *(_DWORD *)(this + 96) = (*(_DWORD *)(this + 64))++;
      if ( *((_BYTE *)w + 54) != 0 )
      {
        newSolidRb = v1[1] - *((float *)v5 + 7);
        v38 = newSolidRb;
        newSolidRc = *v1 - *((float *)v5 + 6);
        *(_DWORD *)(this + 104) = GStrokerAA::addVertex((GStrokerAA *)this, a2: (char)v5, x: newSolidRc, y: v38, id: -1);
      }
      else
      {
        *(_DWORD *)(this + 104) = newSolidLa;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101988B0
// Name: private: void GStrokerAA::tessellate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStrokerAA::tessellate(int this)
{
  unsigned int v2; // ebx
  unsigned int v3; // ecx
  unsigned int v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // edi
  unsigned int v7; // edx
  unsigned int v8; // ecx
  EHExceptionRecord *v9; // edi
  _DWORD *v10; // eax
  unsigned int v11; // eax
  _DWORD *v12; // eax
  unsigned int v13; // eax
  _DWORD *v14; // eax
  double v15; // st7
  float *v16; // eax
  unsigned int v17; // ecx
  int v18; // edx
  int v19; // edi
  int v20; // eax
  float *v21; // eax
  int v22; // edx
  int v23; // ecx
  double v24; // st6
  float *v25; // ecx
  unsigned int *v26; // ecx
  int v27; // edx
  int v28; // edi
  unsigned int v29; // edx
  unsigned int v30; // edi
  unsigned int v31; // ebx
  int v32; // ecx
  int v33; // eax
  float *v34; // ebx
  char v35; // cl
  int v36; // edx
  int v37; // ecx
  double v38; // st7
  int v39; // ecx
  int v40; // edx
  double v41; // st7
  unsigned int v42; // ecx
  EHExceptionRecord *v43; // edi
  int v44; // ecx
  int v45; // edi
  int v46; // ecx
  int v47; // edi
  const struct GStrokeVertexType *v48; // edx
  const struct GStrokeVertexType *v49; // ecx
  int v50; // eax
  float v51[55]; // [esp+18h] [ebp-12Ch] BYREF
  float v52[3]; // [esp+F4h] [ebp-50h] BYREF
  pcharNode widths; // [esp+100h] [ebp-44h] BYREF
  float v54; // [esp+10Ch] [ebp-38h]
  float v55; // [esp+110h] [ebp-34h]
  float v56; // [esp+114h] [ebp-30h]
  float v57; // [esp+118h] [ebp-2Ch]
  float v58; // [esp+11Ch] [ebp-28h]
  float v59; // [esp+120h] [ebp-24h]
  float v60; // [esp+124h] [ebp-20h]
  float v61; // [esp+128h] [ebp-1Ch]
  float v62; // [esp+12Ch] [ebp-18h]
  float v63; // [esp+130h] [ebp-14h]
  int v64; // [esp+134h] [ebp-10h]
  __int16 v65; // [esp+138h] [ebp-Ch]
  unsigned int startTri; // [esp+13Ch] [ebp-8h]
  unsigned int end; // [esp+140h] [ebp-4h]

  *(float *)&widths.__vftable = 0.0;
  *(float *)&widths.me = 0.0;
  *(float *)&widths.myLen = 0.0;
  v54 = 0.0;
  v55 = 0.0;
  v2 = 0;
  v56 = 0.0;
  v57 = 0.0;
  *(_DWORD *)(this + 96) = -4;
  v58 = 0.0;
  *(_DWORD *)(this + 100) = -3;
  v59 = 0.0;
  *(_DWORD *)(this + 104) = -2;
  v60 = 0.0;
  *(_DWORD *)(this + 108) = -1;
  v61 = 0.0;
  v64 = 0;
  v62 = 0.0;
  v65 = 0;
  v63 = 0.0;
  GStrokerAA::calcWidths((GStrokerAA *)this, w: &widths);
  GStrokerAA::JoinParamType::JoinParamType(this: v51);
  if ( *(_BYTE *)(this + 60) != 0 )
  {
    v3 = *(_DWORD *)(this + 44);
    if ( v3 >= 3 )
    {
      GStrokerAA::calcJoinParam(
        result: (EHExceptionRecord *)(*(_DWORD *)(*(_DWORD *)(this + 56) + 4 * ((v3 - 2) >> 6)) + 12 * ((v3 - 2) & 0x3F)),
        a2: (float *)(*(_DWORD *)(*(_DWORD *)(this + 56) + 4 * ((v3 - 1) >> 6)) + 12 * ((v3 - 1) & 0x3F)),
        a3: **(float ***)(this + 56),
        intersectionFailed: (int)&widths,
        a5: (int)v51);
      GStrokerAA::calcJoinParam(
        result: (EHExceptionRecord *)(*(_DWORD *)(*(_DWORD *)(this + 56) + 4 * ((unsigned int)(*(_DWORD *)(this + 44) - 1) >> 6))
                            + 12 * ((*(_DWORD *)(this + 44) - 1) & 0x3F)),
        a2: **(float ***)(this + 56),
        a3: (float *)(**(_DWORD **)(this + 56) + 12),
        intersectionFailed: (int)&widths,
        a5: (int)v51);
      v4 = *(_DWORD *)(this + 80);
      startTri = v4;
      if ( *(_DWORD *)(this + 44) != 0 )
      {
        v5 = 1;
        do
        {
          v6 = *(_DWORD *)(this + 44);
          v7 = v5 + 1;
          end = v5 + 1;
          if ( v5 + 1 >= v6 )
            v7 -= v6;
          v8 = v5;
          if ( v5 >= v6 )
            v8 = v5 - v6;
          v9 = (EHExceptionRecord *)(*(_DWORD *)(*(_DWORD *)(this + 56) + 4 * ((v5 - 1) >> 6))
                                   + 12 * (((_BYTE)v5 - 1) & 0x3F));
          GStrokerAA::calcJoinParam(
            result: v9,
            a2: (float *)(*(_DWORD *)(*(_DWORD *)(this + 56) + 4 * (v8 >> 6)) + 12 * (v8 & 0x3F)),
            a3: (float *)(*(_DWORD *)(*(_DWORD *)(this + 56) + 4 * (v7 >> 6)) + 12 * (v7 & 0x3F)),
            intersectionFailed: (int)&widths,
            a5: (int)v51);
          switch ( *(_DWORD *)this )
          {
            case 0:
            case 1:
            case 2:
              GStrokerAA::calcMiterJoin(
                this,
                v1: (float *)&v9->ExceptionCode,
                w: (float *)&widths,
                n: (struct GStrokerAA::JoinParamType *)v51,
                a5: *(_DWORD *)this);
              break;
            case 3:
              GStrokerAA::calcRoundJoin(
                (GStrokerAA *)this,
                a2: (const struct GStrokeVertexType *)v9,
                p: (FrameInfo *)&widths,
                n: (const struct GStrokerAA::JoinParamType *)v51);
              break;
            case 4:
              GStrokerAA::calcBevelJoin(
                a1: this,
                a2: (char)v9,
                a3: (float *)&v9->ExceptionCode,
                p: (FrameInfo *)&widths,
                a5: (int)v51,
                lineJoin: 4);
              break;
            default:
              break;
          }
          v5 = end;
        }
        while ( end - 1 < *(_DWORD *)(this + 44) );
        v4 = startTri;
        v2 = 0;
      }
      do
      {
        if ( v2 + v4 >= *(_DWORD *)(this + 80) )
          break;
        v10 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 92) + 4 * ((v2 + v4) >> 8)) + 12 * (unsigned __int8)(v2 + v4));
        if ( *v10 == -4 )
          *v10 = *(_DWORD *)(this + 96);
        if ( *v10 == -3 )
          *v10 = *(_DWORD *)(this + 100);
        if ( *v10 == -2 )
          *v10 = *(_DWORD *)(this + 104);
        if ( *v10 == -1 )
          *v10 = *(_DWORD *)(this + 108);
        if ( v10[1] == -4 )
          v10[1] = *(_DWORD *)(this + 96);
        if ( v10[1] == -3 )
          v10[1] = *(_DWORD *)(this + 100);
        if ( v10[1] == -2 )
          v10[1] = *(_DWORD *)(this + 104);
        if ( v10[1] == -1 )
          v10[1] = *(_DWORD *)(this + 108);
        if ( v10[2] == -4 )
          v10[2] = *(_DWORD *)(this + 96);
        if ( v10[2] == -3 )
          v10[2] = *(_DWORD *)(this + 100);
        if ( v10[2] == -2 )
          v10[2] = *(_DWORD *)(this + 104);
        if ( v10[2] == -1 )
          v10[2] = *(_DWORD *)(this + 108);
        v11 = v2 + v4 + 1;
        if ( v11 >= *(_DWORD *)(this + 80) )
          break;
        v12 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 92) + 4 * (v11 >> 8)) + 12 * (unsigned __int8)(v2 + v4 + 1));
        if ( *v12 == -4 )
          *v12 = *(_DWORD *)(this + 96);
        if ( *v12 == -3 )
          *v12 = *(_DWORD *)(this + 100);
        if ( *v12 == -2 )
          *v12 = *(_DWORD *)(this + 104);
        if ( *v12 == -1 )
          *v12 = *(_DWORD *)(this + 108);
        if ( v12[1] == -4 )
          v12[1] = *(_DWORD *)(this + 96);
        if ( v12[1] == -3 )
          v12[1] = *(_DWORD *)(this + 100);
        if ( v12[1] == -2 )
          v12[1] = *(_DWORD *)(this + 104);
        if ( v12[1] == -1 )
          v12[1] = *(_DWORD *)(this + 108);
        if ( v12[2] == -4 )
          v12[2] = *(_DWORD *)(this + 96);
        if ( v12[2] == -3 )
          v12[2] = *(_DWORD *)(this + 100);
        if ( v12[2] == -2 )
          v12[2] = *(_DWORD *)(this + 104);
        if ( v12[2] == -1 )
          v12[2] = *(_DWORD *)(this + 108);
        v13 = v2 + v4 + 2;
        if ( v13 >= *(_DWORD *)(this + 80) )
          break;
        v14 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 92) + 4 * (v13 >> 8)) + 12 * (unsigned __int8)(v2 + v4 + 2));
        if ( *v14 == -4 )
          *v14 = *(_DWORD *)(this + 96);
        if ( *v14 == -3 )
          *v14 = *(_DWORD *)(this + 100);
        if ( *v14 == -2 )
          *v14 = *(_DWORD *)(this + 104);
        if ( *v14 == -1 )
          *v14 = *(_DWORD *)(this + 108);
        if ( v14[1] == -4 )
          v14[1] = *(_DWORD *)(this + 96);
        if ( v14[1] == -3 )
          v14[1] = *(_DWORD *)(this + 100);
        if ( v14[1] == -2 )
          v14[1] = *(_DWORD *)(this + 104);
        if ( v14[1] == -1 )
          v14[1] = *(_DWORD *)(this + 108);
        if ( v14[2] == -4 )
          v14[2] = *(_DWORD *)(this + 96);
        if ( v14[2] == -3 )
          v14[2] = *(_DWORD *)(this + 100);
        if ( v14[2] == -2 )
          v14[2] = *(_DWORD *)(this + 104);
        if ( v14[2] == -1 )
          v14[2] = *(_DWORD *)(this + 108);
        v2 += 3;
      }
      while ( v2 < 6 );
    }
  }
  else if ( *(_DWORD *)(this + 44) >= 2u )
  {
    *(float *)&end = (*(float *)(this + 28) + *(float *)(this + 24)) * 0.5;
    v15 = *(float *)&end;
    if ( *(_DWORD *)(this + 4) == 1 )
    {
      v16 = **(float ***)(this + 56);
      *v16 = *v16 - (v16[3] - *v16) * v15 / v16[2];
      v16[1] = v16[1] - (v16[4] - v16[1]) * v15 / v16[2];
      v16[2] = v16[2] + v15;
    }
    if ( *(_DWORD *)(this + 8) == 1 )
    {
      v17 = *(_DWORD *)(this + 44);
      v18 = *(_DWORD *)(this + 56);
      v19 = *(_DWORD *)(v18 + 4 * ((v17 - 2) >> 6));
      v20 = (v17 - 2) & 0x3F;
      --v17;
      v21 = (float *)(v19 + 12 * v20);
      v22 = *(_DWORD *)(v18 + 4 * (v17 >> 6));
      v23 = 3 * (v17 & 0x3F);
      v24 = *(float *)(v22 + 4 * v23);
      v25 = (float *)(v22 + 4 * v23);
      *v25 = (v24 - *v21) * v15 / v21[2] + *v25;
      v25[1] = (v25[1] - v21[1]) * v15 / v21[2] + v25[1];
      v21[2] = v15 + v21[2];
    }
    v26 = **(unsigned int ***)(this + 56);
    v27 = *(_DWORD *)(this + 4);
    startTri = v26[2];
    if ( v27 >= 0 )
    {
      if ( v27 <= 1 )
      {
        GStrokerAA::calcButtCap(
          (GStrokerAA *)this,
          a2: (const struct GStrokeVertexType *)v26,
          a3: (const struct GStrokeVertexType *)(v26 + 3),
          buttSolidR: *(float *)&startTri,
          endFlag: &widths,
          a6: false);
      }
      else if ( v27 == 2 )
      {
        GStrokerAA::calcRoundCap(
          (GStrokerAA *)this,
          newSolid: (const struct GStrokeVertexType *)v26,
          xSolid: (const struct GStrokeVertexType *)(v26 + 3),
          a1: *(float *)&startTri,
          endFlag: &widths,
          a6: false);
      }
    }
    if ( *(_DWORD *)(this + 44) > 2u )
    {
      v28 = **(_DWORD **)(this + 56);
      GStrokerAA::calcInitialJoinParam(
        (EHRegistrationNode *)this,
        v1: (EHExceptionRecord *)v28,
        dy: (float *)(v28 + 12),
        w: (float *)&widths,
        w_4: (int)v51);
      GStrokerAA::calcJoinParam(
        result: (EHExceptionRecord *)v28,
        a2: (float *)(v28 + 12),
        a3: (float *)(v28 + 24),
        intersectionFailed: (int)&widths,
        a5: (int)v51);
      v29 = *(_DWORD *)(this + 44) - 2;
      v30 = 1;
      end = v29;
      if ( v29 > 1 )
      {
        v31 = 2;
        do
        {
          v32 = *(_DWORD *)(this + 56);
          startTri = *(_DWORD *)(v32 + 4 * (v30 >> 6)) + 12 * (v30 & 0x3F);
          GStrokerAA::calcJoinParam(
            result: (EHExceptionRecord *)startTri,
            a2: (float *)(*(_DWORD *)(v32 + 4 * (v31 >> 6)) + 12 * (v31 & 0x3F)),
            a3: (float *)(*(_DWORD *)(v32 + 4 * ((v31 + 1) >> 6)) + 12 * ((v31 + 1) & 0x3F)),
            intersectionFailed: (int)&widths,
            a5: (int)v51);
          switch ( *(_DWORD *)this )
          {
            case 0:
            case 1:
            case 2:
              GStrokerAA::calcMiterJoin(
                this,
                v1: (float *)startTri,
                w: (float *)&widths,
                n: (struct GStrokerAA::JoinParamType *)v51,
                a5: *(_DWORD *)this);
              break;
            case 3:
              GStrokerAA::calcRoundJoin(
                (GStrokerAA *)this,
                a2: (const struct GStrokeVertexType *)startTri,
                p: (FrameInfo *)&widths,
                n: (const struct GStrokerAA::JoinParamType *)v51);
              break;
            case 4:
              GStrokerAA::calcBevelJoin(
                a1: this,
                a2: v30,
                a3: (float *)startTri,
                p: (FrameInfo *)&widths,
                a5: (int)v51,
                lineJoin: 4);
              break;
            default:
              break;
          }
          ++v30;
          ++v31;
        }
        while ( v30 < end );
        v29 = end;
      }
      v33 = *(_DWORD *)(this + 56);
      v34 = (float *)(*(_DWORD *)(v33 + 4 * (v29 >> 6)) + 12 * (v29 & 0x3F));
      v35 = v29 + 1;
      v36 = *(_DWORD *)(v33 + 4 * ((v29 + 1) >> 6));
      v37 = 3 * (v35 & 0x3F);
      v38 = *(float *)(v36 + 4 * v37);
      v39 = v36 + 4 * v37;
      v40 = *(_DWORD *)(v33 + 4 * (v30 >> 6));
      v52[0] = v38 * 2.0 - *v34;
      v41 = 2.0 * *(float *)(v39 + 4);
      v42 = v30 + 1;
      v43 = (EHExceptionRecord *)(v40 + 12 * (v30 & 0x3F));
      v52[1] = v41 - v34[1];
      v52[2] = v34[2];
      GStrokerAA::calcJoinParam(
        result: v43,
        a2: (float *)(*(_DWORD *)(v33 + 4 * (v42 >> 6)) + 12 * (v42 & 0x3F)),
        a3: v52,
        intersectionFailed: (int)&widths,
        a5: (int)v51);
      switch ( *(_DWORD *)this )
      {
        case 0:
        case 1:
        case 2:
          GStrokerAA::calcMiterJoin(
            this,
            v1: (float *)&v43->ExceptionCode,
            w: (float *)&widths,
            n: (struct GStrokerAA::JoinParamType *)v51,
            a5: *(_DWORD *)this);
          break;
        case 3:
          GStrokerAA::calcRoundJoin(
            (GStrokerAA *)this,
            a2: (const struct GStrokeVertexType *)v43,
            p: (FrameInfo *)&widths,
            n: (const struct GStrokerAA::JoinParamType *)v51);
          break;
        case 4:
          GStrokerAA::calcBevelJoin(
            a1: this,
            a2: (char)v43,
            a3: (float *)&v43->ExceptionCode,
            p: (FrameInfo *)&widths,
            a5: (int)v51,
            lineJoin: 4);
          break;
        default:
          break;
      }
    }
    v44 = *(_DWORD *)(this + 44);
    v45 = *(_DWORD *)(this + 56);
    GStrokerAA::calcButtJoin(
      (EHExceptionRecord *)this,
      a2: v45,
      v0: (EHRegistrationNode *)(*(_DWORD *)(v45 + 4 * ((unsigned int)(v44 - 2) >> 6)) + 12 * ((v44 - 2) & 0x3F)),
      v1: (float *)(*(_DWORD *)(v45 + 4 * ((unsigned int)(v44 - 1) >> 6)) + 12 * ((v44 - 1) & 0x3F)),
      len: *(float *)(*(_DWORD *)(v45 + 4 * ((unsigned int)(v44 - 2) >> 6)) + 12 * (((_BYTE)v44 - 2) & 0x3F) + 8),
      w: (int)&widths);
    v46 = *(_DWORD *)(this + 44);
    v47 = *(_DWORD *)(this + 56);
    end = *(unsigned int *)(*(_DWORD *)(v47 + 4 * ((unsigned int)(v46 - 2) >> 6)) + 12 * (((_BYTE)v46 - 2) & 0x3F) + 8);
    v48 = (const struct GStrokeVertexType *)(*(_DWORD *)(v47 + 4 * ((unsigned int)(v46 - 2) >> 6))
                                           + 12 * ((v46 - 2) & 0x3F));
    v49 = (const struct GStrokeVertexType *)(*(_DWORD *)(v47 + 4 * ((unsigned int)(v46 - 1) >> 6))
                                           + 12 * ((v46 - 1) & 0x3F));
    v50 = *(_DWORD *)(this + 8);
    if ( v50 >= 0 )
    {
      if ( v50 <= 1 )
      {
        GStrokerAA::calcButtCap(
          (GStrokerAA *)this,
          a2: v49,
          a3: v48,
          buttSolidR: *(float *)&end,
          endFlag: &widths,
          a6: true);
      }
      else if ( v50 == 2 )
      {
        GStrokerAA::calcRoundCap(
          (GStrokerAA *)this,
          newSolid: v49,
          xSolid: v48,
          a1: *(float *)&end,
          endFlag: &widths,
          a6: true);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101990B0
// Name: public: void GStrokerAA::Tessellate(class GCompoundShape const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStrokerAA::Tessellate(GStrokerAA *this, const struct GCompoundShape *a2, int srcStyle)
{
  unsigned int v3; // eax
  const struct GCompoundShape *v5; // ecx
  unsigned int *v6; // esi
  _DWORD *v7; // edi
  float *v8; // ecx
  int v9; // edx
  int v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // eax
  int v13; // ecx
  double v14; // st7
  int v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // ebx
  int v18; // edx
  float *v19; // ebx
  unsigned int v20; // ebx
  float *v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // eax
  int v24; // ecx
  double v25; // st7
  int v26; // eax
  unsigned int v27; // ecx
  unsigned int v28; // ebx
  int v29; // edx
  float *v30; // ebx
  unsigned int v31; // ebx
  float *v32; // eax
  float v33; // [esp+8h] [ebp-34h]
  float v34; // [esp+Ch] [ebp-30h]
  float v35; // [esp+14h] [ebp-28h]
  float v36; // [esp+18h] [ebp-24h]
  float v37; // [esp+28h] [ebp-14h]
  float v38; // [esp+28h] [ebp-14h]
  float v39; // [esp+28h] [ebp-14h]
  float v40; // [esp+28h] [ebp-14h]
  float v41; // [esp+28h] [ebp-14h]
  float v42; // [esp+28h] [ebp-14h]
  float v43; // [esp+2Ch] [ebp-10h]
  float v44; // [esp+2Ch] [ebp-10h]
  float v45; // [esp+2Ch] [ebp-10h]
  float v46; // [esp+2Ch] [ebp-10h]
  float v47; // [esp+2Ch] [ebp-10h]
  unsigned int i; // [esp+30h] [ebp-Ch]
  GStrokerAA *v49; // [esp+34h] [ebp-8h]
  float jb; // [esp+38h] [ebp-4h]
  unsigned int j; // [esp+38h] [ebp-4h]
  unsigned int ja; // [esp+38h] [ebp-4h]

  v3 = 0;
  v5 = a2;
  v6 = (unsigned int *)((char *)this + 44);
  *((_DWORD *)this + 11) = 0;
  *((_BYTE *)this + 60) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 20) = 0;
  v49 = this;
  for ( i = 0; v3 < *((_DWORD *)a2 + 6); i = v3 )
  {
    v7 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)v5 + 9) + 4 * (v3 >> 6)) + 24 * (v3 & 0x3F));
    if ( (srcStyle < 0 || v7[5] == srcStyle) && v7[1] != 0 )
    {
      if ( *v6 == 0 )
        goto LABEL_17;
      v8 = (float *)(*(_DWORD *)(*((_DWORD *)this + 14) + 4 * ((*v6 - 1) >> 6)) + 12 * ((*v6 - 1) & 0x3F));
      v9 = *(_DWORD *)(*(_DWORD *)(*v7 + 20) + 4 * (v7[2] >> 8));
      v10 = (unsigned __int8)v7[2];
      v43 = *(float *)(v9 + 8 * v10) - *v8;
      jb = *(float *)(v9 + 8 * v10 + 4) - v8[1];
      v44 = jb * jb + v43 * v43;
      v45 = sqrt(v44);
      if ( v45 > 0.00009999999747378752 )
      {
        GStrokePath::ClosePath(this: (GStrokePath *)v6, a2: false);
        GStrokerAA::tessellate(this: (int)v49);
        *v6 = 0;
        *((_BYTE *)v6 + 16) = 0;
LABEL_17:
        v22 = 0;
        for ( ja = 0; v22 < v7[1]; ja = v22 )
        {
          v23 = v22 + v7[2];
          v24 = *(_DWORD *)(*(_DWORD *)(*v7 + 20) + 4 * (v23 >> 8));
          v25 = *(float *)(v24 + 8 * (unsigned __int8)v23);
          v26 = v24 + 8 * (unsigned __int8)v23;
          v27 = *v6;
          v34 = *(float *)(v26 + 4);
          if ( *v6 > 1 )
          {
            v28 = v6[3];
            v29 = *(_DWORD *)(v28 + 4 * ((v27 - 1) >> 6));
            v30 = (float *)(*(_DWORD *)(v28 + 4 * ((v27 - 2) >> 6)) + 12 * (((_BYTE)v27 - 2) & 0x3F));
            v47 = *(float *)(v29 + 12 * ((v27 - 1) & 0x3F)) - *v30;
            v40 = *(float *)(v29 + 12 * ((v27 - 1) & 0x3F) + 4) - v30[1];
            v41 = v40 * v40 + v47 * v47;
            v42 = sqrt(v41);
            v30[2] = v42;
            if ( v42 <= 0.00009999999747378752 && *v6 != 0 )
              --*v6;
          }
          v31 = *v6 >> 6;
          if ( v31 >= v6[1] )
            GArrayPagedBase<GStrokeVertexType,6,16,GAllocatorPagedLH_POD<GStrokeVertexType,135>>::allocatePage(
              this: v6,
              nb: *v6 >> 6);
          v32 = (float *)(*(_DWORD *)(v6[3] + 4 * v31) + 12 * (*v6 & 0x3F));
          v33 = v25;
          *v32 = v33;
          v32[1] = v34;
          v32[2] = 0.0;
          ++*v6;
          v22 = ja + 1;
        }
        goto LABEL_25;
      }
      v11 = 1;
      for ( j = 1; v11 < v7[1]; j = v11 )
      {
        v12 = v11 + v7[2];
        v13 = *(_DWORD *)(*(_DWORD *)(*v7 + 20) + 4 * (v12 >> 8));
        v14 = *(float *)(v13 + 8 * (unsigned __int8)v12);
        v15 = v13 + 8 * (unsigned __int8)v12;
        v16 = *v6;
        v36 = *(float *)(v15 + 4);
        if ( *v6 > 1 )
        {
          v17 = v6[3];
          v18 = *(_DWORD *)(v17 + 4 * ((v16 - 1) >> 6));
          v19 = (float *)(*(_DWORD *)(v17 + 4 * ((v16 - 2) >> 6)) + 12 * (((_BYTE)v16 - 2) & 0x3F));
          v37 = *(float *)(v18 + 12 * ((v16 - 1) & 0x3F)) - *v19;
          v46 = *(float *)(v18 + 12 * ((v16 - 1) & 0x3F) + 4) - v19[1];
          v38 = v46 * v46 + v37 * v37;
          v39 = sqrt(v38);
          v19[2] = v39;
          if ( v39 <= 0.00009999999747378752 && *v6 != 0 )
            --*v6;
        }
        v20 = *v6 >> 6;
        if ( v20 >= v6[1] )
          GArrayPagedBase<GStrokeVertexType,6,16,GAllocatorPagedLH_POD<GStrokeVertexType,135>>::allocatePage(
            this: v6,
            nb: *v6 >> 6);
        v21 = (float *)(*(_DWORD *)(v6[3] + 4 * v20) + 12 * (*v6 & 0x3F));
        v35 = v14;
        *v21 = v35;
        v21[1] = v36;
        v21[2] = 0.0;
        ++*v6;
        v11 = j + 1;
      }
    }
LABEL_25:
    v5 = a2;
    this = v49;
    v3 = i + 1;
  }
  if ( *v6 > 1 )
  {
    GStrokePath::ClosePath(this: (GStrokePath *)v6, a2: false);
    GStrokerAA::tessellate((int)this);
  }
}
