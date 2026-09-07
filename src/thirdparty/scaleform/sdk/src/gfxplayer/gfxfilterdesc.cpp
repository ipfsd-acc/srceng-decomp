// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxfilterdesc.cpp
// Functions: 3
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxfilterdesc.h"

//------------------------------------------------------------------------------
// Address: 0x10142090
// Name: public: void GFxTextFilter::LoadFilterDesc(struct GFxFilterDesc const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextFilter::LoadFilterDesc(GFxTextFilter *this, const struct GFxFilterDesc *a2)
{
  char v2; // bl
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned __int8 v6; // al
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax

  v2 = *(_BYTE *)a2 & 0xF;
  if ( v2 == 1 )
  {
    v3 = (__int64)(*((float *)a2 + 3) * 16.0 + 0.5);
    if ( v3 >= 0xFF )
      LOBYTE(v3) = -1;
    *((_BYTE *)this + 8) = v3;
    v4 = (__int64)(*((float *)a2 + 4) * 16.0 + 0.5);
    if ( v4 >= 0xFF )
      LOBYTE(v4) = -1;
    *((_BYTE *)this + 9) = v4;
    v5 = (__int64)(16.0 * *((float *)a2 + 10) + 0.5);
    if ( v5 >= 0xFF )
      LOBYTE(v5) = -1;
    *((_BYTE *)this + 10) = v5;
  }
  else if ( v2 == 0 || v2 == 2 )
  {
    if ( *((_DWORD *)this + 7) != 0 && *((_WORD *)this + 10) != 0 )
    {
      if ( v2 == 2 )
      {
        *((_DWORD *)this + 8) = *((_DWORD *)a2 + 8);
        v6 = *((_BYTE *)this + 13);
        if ( v6 < *((_BYTE *)this + 12) )
          v6 = *((_BYTE *)this + 12);
        *((_BYTE *)this + 16) = v6;
      }
    }
    else
    {
      *((_BYTE *)this + 11) = *(_BYTE *)a2 & 0xF0;
      v7 = (__int64)(*((float *)a2 + 3) * 16.0 + 0.5);
      if ( v7 >= 0xFF )
        LOBYTE(v7) = -1;
      *((_BYTE *)this + 12) = v7;
      v8 = (__int64)(*((float *)a2 + 4) * 16.0 + 0.5);
      if ( v8 >= 0xFF )
        LOBYTE(v8) = -1;
      *((_BYTE *)this + 13) = v8;
      v9 = (__int64)(16.0 * *((float *)a2 + 10) + 0.5);
      if ( v9 >= 0xFF )
        LOBYTE(v9) = -1;
      *((_BYTE *)this + 14) = v9;
      *((_BYTE *)this + 15) = *((_BYTE *)a2 + 35);
      *((_WORD *)this + 9) = *((_WORD *)a2 + 1);
      *((_WORD *)this + 10) = *((_WORD *)a2 + 2);
      *((_WORD *)this + 11) = 0;
      *((_WORD *)this + 12) = 0;
      *((_DWORD *)this + 7) = *((_DWORD *)a2 + 8);
      GFxTextFilter::UpdateShadowOffset((CDummyTexture *)this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10142280
// Name: unsigned int GFx_LoadFilters<class GFxStream>(class GFxStream __near *,struct GFxFilterDesc __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
unsigned int __cdecl GFx_LoadFilters<GFxStream>(GFxStream *a1, int a2, unsigned int filterssz)
{
  int v3; // ecx
  _LUID_AND_ATTRIBUTES *v4; // eax
  unsigned __int8 v5; // bl
  unsigned int result; // eax
  int v7; // eax
  _LUID_AND_ATTRIBUTES *v8; // edi
  unsigned __int8 v9; // al
  _LUID_AND_ATTRIBUTES *v10; // edi
  int v11; // ebx
  int v12; // ecx
  _LUID_AND_ATTRIBUTES *v13; // edx
  int v14; // eax
  int v15; // edx
  _LUID_AND_ATTRIBUTES *v16; // edx
  int v17; // eax
  int v18; // edx
  _LUID_AND_ATTRIBUTES *v19; // ecx
  int v20; // ecx
  _LUID_AND_ATTRIBUTES *v21; // ecx
  int v22; // ecx
  _LUID_AND_ATTRIBUTES *v23; // eax
  int v24; // ecx
  _LUID_AND_ATTRIBUTES *v25; // eax
  char v26; // cl
  char v27; // al
  char v28; // dl
  char v29; // cl
  char v30; // dl
  int v31; // ecx
  int v32; // eax
  _LUID_AND_ATTRIBUTES *v33; // edx
  int v34; // eax
  int v35; // edx
  _LUID_AND_ATTRIBUTES *v36; // edx
  int v37; // eax
  int v38; // edx
  _LUID_AND_ATTRIBUTES *v39; // eax
  unsigned __int8 v40; // cl
  int v41; // ecx
  _LUID_AND_ATTRIBUTES *v42; // edx
  int v43; // eax
  int v44; // edx
  _LUID_AND_ATTRIBUTES *v45; // edx
  int v46; // eax
  int v47; // edx
  _LUID_AND_ATTRIBUTES *v48; // eax
  int v49; // ecx
  _LUID_AND_ATTRIBUTES *v50; // eax
  char v51; // cl
  char v52; // al
  char v53; // dl
  char v54; // cl
  char v55; // dl
  int v56; // ecx
  int v57; // eax
  _LUID_AND_ATTRIBUTES *v58; // edx
  int v59; // eax
  int v60; // edx
  _LUID_AND_ATTRIBUTES *v61; // edx
  int v62; // eax
  int v63; // edx
  _LUID_AND_ATTRIBUTES *v64; // ecx
  int v65; // ecx
  _LUID_AND_ATTRIBUTES *v66; // ecx
  int v67; // ecx
  _LUID_AND_ATTRIBUTES *v68; // eax
  int v69; // ecx
  _LUID_AND_ATTRIBUTES *v70; // eax
  char v71; // cl
  char v72; // al
  char v73; // dl
  char v74; // cl
  char v75; // dl
  int v76; // ecx
  int v77; // edx
  _LUID_AND_ATTRIBUTES *v78; // eax
  unsigned __int8 v79; // cl
  int v80; // edx
  int v81; // edi
  _LUID_AND_ATTRIBUTES *v82; // eax
  unsigned __int8 v83; // cl
  _LUID_AND_ATTRIBUTES *v84; // eax
  int v85; // edi
  unsigned int v86; // edi
  int v87; // eax
  _LUID_AND_ATTRIBUTES *v88; // ecx
  float v89; // edx
  int v90; // ecx
  _WORD *v91; // ecx
  _LUID_AND_ATTRIBUTES *v92; // eax
  unsigned __int8 v93; // cl
  int v94; // edx
  float v95; // [esp+8h] [ebp-120h]
  float v96; // [esp+Ch] [ebp-11Ch]
  float v97; // [esp+10h] [ebp-118h]
  float v98; // [esp+14h] [ebp-114h]
  double v99; // [esp+18h] [ebp-110h]
  double v100; // [esp+18h] [ebp-110h]
  unsigned __int8 filterCount; // [esp+27h] [ebp-101h]
  unsigned int numFilters; // [esp+28h] [ebp-100h]
  int v103; // [esp+2Ch] [ebp-FCh]
  float v104; // [esp+2Ch] [ebp-FCh]
  float v105; // [esp+2Ch] [ebp-FCh]
  int v106; // [esp+2Ch] [ebp-FCh]
  float v107; // [esp+2Ch] [ebp-FCh]
  int v108; // [esp+2Ch] [ebp-FCh]
  float v109; // [esp+2Ch] [ebp-FCh]
  float v110; // [esp+2Ch] [ebp-FCh]
  bool done; // [esp+33h] [ebp-F5h]
  float v112; // [esp+34h] [ebp-F4h]
  float v113; // [esp+34h] [ebp-F4h]
  int v114; // [esp+34h] [ebp-F4h]
  int v115; // [esp+34h] [ebp-F4h]
  float v116; // [esp+34h] [ebp-F4h]
  float v117; // [esp+34h] [ebp-F4h]
  int v118; // [esp+34h] [ebp-F4h]
  float v119; // [esp+34h] [ebp-F4h]
  int v120; // [esp+34h] [ebp-F4h]
  float v121; // [esp+34h] [ebp-F4h]
  float v122; // [esp+34h] [ebp-F4h]
  _BYTE filterDesc[6]; // [esp+38h] [ebp-F0h] OVERLAPPED BYREF
  int v124; // [esp+40h] [ebp-E8h]
  float v125; // [esp+44h] [ebp-E4h]
  float v126; // [esp+48h] [ebp-E0h]
  unsigned int v127; // [esp+4Ch] [ebp-DCh]
  float v128; // [esp+50h] [ebp-D8h]
  float v129; // [esp+54h] [ebp-D4h]
  struct GColor v130; // [esp+58h] [ebp-D0h] BYREF
  struct GColor v131; // [esp+5Ch] [ebp-CCh] BYREF
  float v132; // [esp+60h] [ebp-C8h]
  float v133[8]; // [esp+64h] [ebp-C4h] BYREF
  float dst[20]; // [esp+84h] [ebp-A4h] BYREF
  _DWORD v135[20]; // [esp+D4h] [ebp-54h]

  v3 = (char *)a1[12] - (char *)a1[11];
  *((_BYTE *)a1 + 21) = 0;
  if ( v3 < 1 )
    GFxStream::PopulateBuffer1(this: a1);
  v4 = (_LUID_AND_ATTRIBUTES *)a1[11];
  v5 = *((_BYTE *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v4);
  v125 = 5.0;
  v126 = 5.0;
  v128 = 0.0;
  filterCount = v5;
  v129 = 0.0;
  a1[11] = (GFxStream)((char *)&v4->Luid.LowPart + 1);
  v124 = 0;
  v132 = 1.0;
  v127 = 1;
  GRenderer::Cxform::Cxform(this: v133);
  result = 0;
  numFilters = 0;
  done = false;
  if ( v5 != 0 )
  {
    while ( 2 )
    {
      v7 = (char *)a1[12] - (char *)a1[11];
      --filterCount;
      *((_BYTE *)a1 + 21) = 0;
      if ( v7 < 1 )
        GFxStream::PopulateBuffer1(this: a1);
      v8 = (_LUID_AND_ATTRIBUTES *)a1[11];
      v9 = *((_BYTE *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v8);
      v10 = (_LUID_AND_ATTRIBUTES *)((char *)&v8->Luid.LowPart + 1);
      a1[11] = (GFxStream)v10;
      v11 = v9;
      memset((unsigned __int8 *)dst, value: 0, count: sizeof(dst));
      dst[0] = 1.0;
      dst[5] = 1.0;
      v124 = 0;
      dst[10] = 1.0;
      v127 = 0;
      dst[15] = 1.0;
      *(_DWORD *)&filterDesc[2] = 0;
      v130 = 0;
      v126 = 0.0;
      filterDesc[0] = v11;
      v125 = 0.0;
      v132 = 1.0;
      v129 = 0.0;
      v128 = 0.0;
      switch ( v11 )
      {
        case 0:
          GFxStream::ReadRgba(this: a1, a2: &v130);
          v12 = (char *)a1[12] - (char *)a1[11];
          *((_BYTE *)a1 + 21) = 0;
          if ( v12 < 4 )
            GFxStream::PopulateBuffer(this: (int)a1, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
          v13 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v14 = *((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v13)
              | ((*((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v13 + 1)
                | ((*((unsigned __int8 *)&v13->Luid.LowPart + (_DWORD)a1[15] + 2)
                  | (*((unsigned __int8 *)&v13->Luid.LowPart + (_DWORD)a1[15] + 3) << 8)) << 8)) << 8);
          a1[11] = (GFxStream)&v13->Luid.HighPart;
          v15 = (char *)a1[12] - (char *)&v13->Luid.HighPart;
          *((_BYTE *)a1 + 21) = 0;
          v125 = (double)(unsigned int)v14 * 0.0000152587890625;
          if ( v15 < 4 )
            GFxStream::PopulateBuffer(this: (int)a1, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
          v16 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v17 = *((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v16)
              | ((*((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v16 + 1)
                | ((*((unsigned __int8 *)&v16->Luid.LowPart + (_DWORD)a1[15] + 2)
                  | (*((unsigned __int8 *)&v16->Luid.LowPart + (_DWORD)a1[15] + 3) << 8)) << 8)) << 8);
          a1[11] = (GFxStream)&v16->Luid.HighPart;
          v18 = (char *)a1[12] - (char *)&v16->Luid.HighPart;
          *((_BYTE *)a1 + 21) = 0;
          v126 = (double)(unsigned int)v17 * 0.0000152587890625;
          if ( v18 < 4 )
            GFxStream::PopulateBuffer(this: (int)a1, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
          v19 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v103 = *((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v19)
               | ((*((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v19 + 1)
                 | ((*((unsigned __int8 *)&v19->Luid.LowPart + (_DWORD)a1[15] + 2)
                   | (*((unsigned __int8 *)&v19->Luid.LowPart + (_DWORD)a1[15] + 3) << 8)) << 8)) << 8);
          a1[11] = (GFxStream)&v19->Luid.HighPart;
          v104 = (double)v103 * 0.0000152587890625;
          v105 = v104 * 1800.0 / 3.141592741012573;
          v20 = (char *)a1[12] - (char *)&v19->Luid.HighPart;
          *(_WORD *)&filterDesc[2] = (int)fmod(v105, 3600.0);
          *((_BYTE *)a1 + 21) = 0;
          if ( v20 < 4 )
            GFxStream::PopulateBuffer(this: (int)a1, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
          v21 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v106 = *((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v21)
               | ((*((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v21 + 1)
                 | ((*((unsigned __int8 *)&v21->Luid.LowPart + (_DWORD)a1[15] + 2)
                   | (*((unsigned __int8 *)&v21->Luid.LowPart + (_DWORD)a1[15] + 3) << 8)) << 8)) << 8);
          a1[11] = (GFxStream)&v21->Luid.HighPart;
          v107 = (double)v106 * 0.0000152587890625;
          v22 = (char *)a1[12] - (char *)&v21->Luid.HighPart;
          *(_WORD *)&filterDesc[4] = (int)(v107 * 20.0);
          *((_BYTE *)a1 + 21) = 0;
          if ( v22 < 2 )
            GFxStream::PopulateBuffer(this: (int)a1, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
          v23 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v108 = *(unsigned __int16 *)((char *)&v23->Luid.LowPart + (_DWORD)a1[15]);
          v23 = (_LUID_AND_ATTRIBUTES *)((char *)v23 + 2);
          v24 = (char *)a1[12] - (char *)v23;
          a1[11] = (GFxStream)v23;
          *((_BYTE *)a1 + 21) = 0;
          v132 = (double)v108 * 0.00390625;
          if ( v24 < 1 )
            GFxStream::PopulateBuffer1(this: a1);
          v25 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v26 = *((_BYTE *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v25);
          a1[11] = (GFxStream)((char *)&v25->Luid.LowPart + 1);
          v27 = v26;
          v28 = v26;
          v29 = 0;
          v30 = v28 & 0x40;
          if ( v30 != 0 )
            v29 = 32;
          if ( (v27 & 0x20) == 0 )
            v29 |= 0x40u;
          if ( (v27 & 0xFu) > 1 )
            v29 |= 0x80u;
          filterDesc[0] |= v29;
          v127 = v27 & 0x1F;
          v31 = 0;
          if ( v27 < 0 )
            v31 = 512;
          if ( v30 != 0 )
            v31 |= 0x100u;
          if ( (v27 & 0x20) == 0 )
            v31 |= 0x400u;
          v124 = v31 | 2;
          v109 = (double)*(__int16 *)&filterDesc[2] * 3.141592741012573 / 1800.0;
          v99 = (double)*(__int16 *)&filterDesc[4];
          v112 = cos(v109);
          v97 = v112 * v99 * 0.05000000074505806;
          v113 = sin(v109);
          v98 = v113 * v99 * 0.05000000074505806;
          v128 = v97;
          v129 = v98;
          if ( !done )
          {
            if ( a2 == 0 || numFilters >= 4 )
              goto LABEL_118;
            goto LABEL_109;
          }
          goto LABEL_120;
        case 1:
          *((_BYTE *)a1 + 21) = 0;
          v32 = (char *)a1[12] - (char *)v10;
          v124 = 1;
          if ( v32 < 4 )
            GFxStream::PopulateBuffer(this: (int)a1, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
          v33 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v34 = *((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v33)
              | ((*((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v33 + 1)
                | ((*((unsigned __int8 *)&v33->Luid.LowPart + (_DWORD)a1[15] + 2)
                  | (*((unsigned __int8 *)&v33->Luid.LowPart + (_DWORD)a1[15] + 3) << 8)) << 8)) << 8);
          a1[11] = (GFxStream)&v33->Luid.HighPart;
          v35 = (char *)a1[12] - (char *)&v33->Luid.HighPart;
          *((_BYTE *)a1 + 21) = 0;
          v125 = (double)(unsigned int)v34 * 0.0000152587890625;
          if ( v35 < 4 )
            GFxStream::PopulateBuffer(this: (int)a1, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
          v36 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v37 = *((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v36)
              | ((*((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v36 + 1)
                | ((*((unsigned __int8 *)&v36->Luid.LowPart + (_DWORD)a1[15] + 2)
                  | (*((unsigned __int8 *)&v36->Luid.LowPart + (_DWORD)a1[15] + 3) << 8)) << 8)) << 8);
          a1[11] = (GFxStream)&v36->Luid.HighPart;
          v38 = (char *)a1[12] - (char *)&v36->Luid.HighPart;
          *((_BYTE *)a1 + 21) = 0;
          v126 = (double)(unsigned int)v37 * 0.0000152587890625;
          if ( v38 < 1 )
            GFxStream::PopulateBuffer1(this: a1);
          v39 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v40 = *((_BYTE *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v39);
          a1[11] = (GFxStream)((char *)&v39->Luid.LowPart + 1);
          v127 = v40 >> 3;
          filterDesc[0] |= v127 > 1 ? 0x80 : 0;
          if ( !done )
          {
            if ( a2 == 0 || numFilters >= 4 )
              goto LABEL_118;
            goto LABEL_109;
          }
          goto LABEL_120;
        case 2:
          GFxStream::ReadRgba(this: a1, a2: &v130);
          v41 = (char *)a1[12] - (char *)a1[11];
          *((_BYTE *)a1 + 21) = 0;
          if ( v41 < 4 )
            GFxStream::PopulateBuffer(this: (int)a1, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
          v42 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v43 = *((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v42)
              | ((*((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v42 + 1)
                | ((*((unsigned __int8 *)&v42->Luid.LowPart + (_DWORD)a1[15] + 2)
                  | (*((unsigned __int8 *)&v42->Luid.LowPart + (_DWORD)a1[15] + 3) << 8)) << 8)) << 8);
          a1[11] = (GFxStream)&v42->Luid.HighPart;
          v44 = (char *)a1[12] - (char *)&v42->Luid.HighPart;
          *((_BYTE *)a1 + 21) = 0;
          v125 = (double)(unsigned int)v43 * 0.0000152587890625;
          if ( v44 < 4 )
            GFxStream::PopulateBuffer(this: (int)a1, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
          v45 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v46 = *((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v45)
              | ((*((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v45 + 1)
                | ((*((unsigned __int8 *)&v45->Luid.LowPart + (_DWORD)a1[15] + 2)
                  | (*((unsigned __int8 *)&v45->Luid.LowPart + (_DWORD)a1[15] + 3) << 8)) << 8)) << 8);
          a1[11] = (GFxStream)&v45->Luid.HighPart;
          v47 = (char *)a1[12] - (char *)&v45->Luid.HighPart;
          *((_BYTE *)a1 + 21) = 0;
          v126 = (double)(unsigned int)v46 * 0.0000152587890625;
          if ( v47 < 2 )
            GFxStream::PopulateBuffer(this: (int)a1, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
          v48 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v114 = *(unsigned __int16 *)((char *)&v48->Luid.LowPart + (_DWORD)a1[15]);
          v48 = (_LUID_AND_ATTRIBUTES *)((char *)v48 + 2);
          v49 = (char *)a1[12] - (char *)v48;
          a1[11] = (GFxStream)v48;
          *((_BYTE *)a1 + 21) = 0;
          v132 = (double)v114 * 0.00390625;
          if ( v49 < 1 )
            GFxStream::PopulateBuffer1(this: a1);
          v50 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v51 = *((_BYTE *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v50);
          a1[11] = (GFxStream)((char *)&v50->Luid.LowPart + 1);
          v52 = v51;
          v53 = v51;
          v54 = 0;
          v55 = v53 & 0x40;
          if ( v55 != 0 )
            v54 = 32;
          if ( (v52 & 0x20) == 0 )
            v54 |= 0x40u;
          if ( (v52 & 0xFu) > 1 )
            v54 |= 0x80u;
          filterDesc[0] |= v54;
          v56 = 0;
          if ( v52 < 0 )
            v56 = 512;
          if ( v55 != 0 )
            v56 |= 0x100u;
          if ( (v52 & 0x20) == 0 )
            v56 |= 0x400u;
          v124 = v56 | 2;
          v127 = v52 & 0x1F;
          if ( !done )
          {
            if ( a2 == 0 || numFilters >= 4 )
              goto LABEL_118;
            goto LABEL_109;
          }
          goto LABEL_120;
        case 3:
          GFxStream::ReadRgba(this: a1, a2: &v130);
          GFxStream::ReadRgba(this: a1, a2: &v131);
          v57 = (char *)a1[12] - (char *)a1[11];
          *((_BYTE *)a1 + 21) = 0;
          if ( v57 < 4 )
            GFxStream::PopulateBuffer(this: (int)a1, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
          v58 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v59 = *((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v58)
              | ((*((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v58 + 1)
                | ((*((unsigned __int8 *)&v58->Luid.LowPart + (_DWORD)a1[15] + 2)
                  | (*((unsigned __int8 *)&v58->Luid.LowPart + (_DWORD)a1[15] + 3) << 8)) << 8)) << 8);
          a1[11] = (GFxStream)&v58->Luid.HighPart;
          v60 = (char *)a1[12] - (char *)&v58->Luid.HighPart;
          *((_BYTE *)a1 + 21) = 0;
          v125 = (double)(unsigned int)v59 * 0.0000152587890625;
          if ( v60 < 4 )
            GFxStream::PopulateBuffer(this: (int)a1, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
          v61 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v62 = *((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v61)
              | ((*((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v61 + 1)
                | ((*((unsigned __int8 *)&v61->Luid.LowPart + (_DWORD)a1[15] + 2)
                  | (*((unsigned __int8 *)&v61->Luid.LowPart + (_DWORD)a1[15] + 3) << 8)) << 8)) << 8);
          a1[11] = (GFxStream)&v61->Luid.HighPart;
          v63 = (char *)a1[12] - (char *)&v61->Luid.HighPart;
          *((_BYTE *)a1 + 21) = 0;
          v126 = (double)(unsigned int)v62 * 0.0000152587890625;
          if ( v63 < 4 )
            GFxStream::PopulateBuffer(this: (int)a1, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
          v64 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v115 = *((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v64)
               | ((*((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v64 + 1)
                 | ((*((unsigned __int8 *)&v64->Luid.LowPart + (_DWORD)a1[15] + 2)
                   | (*((unsigned __int8 *)&v64->Luid.LowPart + (_DWORD)a1[15] + 3) << 8)) << 8)) << 8);
          a1[11] = (GFxStream)&v64->Luid.HighPart;
          v116 = (double)v115 * 0.0000152587890625;
          v117 = v116 * 1800.0 / 3.141592741012573;
          v65 = (char *)a1[12] - (char *)&v64->Luid.HighPart;
          *(_WORD *)&filterDesc[2] = (int)fmod(v117, 3600.0);
          *((_BYTE *)a1 + 21) = 0;
          if ( v65 < 4 )
            GFxStream::PopulateBuffer(this: (int)a1, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
          v66 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v118 = *((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v66)
               | ((*((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v66 + 1)
                 | ((*((unsigned __int8 *)&v66->Luid.LowPart + (_DWORD)a1[15] + 2)
                   | (*((unsigned __int8 *)&v66->Luid.LowPart + (_DWORD)a1[15] + 3) << 8)) << 8)) << 8);
          a1[11] = (GFxStream)&v66->Luid.HighPart;
          v119 = (double)v118 * 0.0000152587890625;
          v67 = (char *)a1[12] - (char *)&v66->Luid.HighPart;
          *(_WORD *)&filterDesc[4] = (int)(v119 * 20.0);
          *((_BYTE *)a1 + 21) = 0;
          if ( v67 < 2 )
            GFxStream::PopulateBuffer(this: (int)a1, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
          v68 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v120 = *(unsigned __int16 *)((char *)&v68->Luid.LowPart + (_DWORD)a1[15]);
          v68 = (_LUID_AND_ATTRIBUTES *)((char *)v68 + 2);
          v69 = (char *)a1[12] - (char *)v68;
          a1[11] = (GFxStream)v68;
          *((_BYTE *)a1 + 21) = 0;
          v132 = (double)v120 * 0.00390625;
          if ( v69 < 1 )
            GFxStream::PopulateBuffer1(this: a1);
          v70 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v71 = *((_BYTE *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v70);
          a1[11] = (GFxStream)((char *)&v70->Luid.LowPart + 1);
          v72 = v71;
          v73 = v71;
          v74 = 0;
          v75 = v73 & 0x40;
          if ( v75 != 0 )
            v74 = 32;
          if ( (v72 & 0x20) == 0 )
            v74 |= 0x40u;
          if ( (v72 & 0xFu) > 1 )
            v74 |= 0x80u;
          filterDesc[0] |= v74;
          v127 = v72 & 0xF;
          v76 = 0;
          if ( v72 < 0 )
            v76 = 512;
          if ( v75 != 0 )
            v76 |= 0x100u;
          if ( (v72 & 0x20) == 0 )
            v76 |= 0x400u;
          v124 = v76 | 6;
          v110 = (double)*(__int16 *)&filterDesc[2] * 3.141592741012573 / 1800.0;
          v100 = (double)*(__int16 *)&filterDesc[4];
          v121 = cos(v110);
          v95 = v121 * v100 * 0.05000000074505806;
          v122 = sin(v110);
          v96 = v122 * v100 * 0.05000000074505806;
          v128 = v95;
          v129 = v96;
          if ( !done )
          {
            if ( a2 == 0 || numFilters >= 4 )
              goto LABEL_118;
            goto LABEL_109;
          }
          goto LABEL_120;
        case 4:
        case 7:
          *((_BYTE *)a1 + 21) = 0;
          if ( (char *)a1[12] - (char *)v10 < 1 )
            GFxStream::PopulateBuffer1(this: a1);
          v92 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v93 = *((_BYTE *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v92);
          v84 = (_LUID_AND_ATTRIBUTES *)((char *)&v92->Luid.LowPart + 1);
          v85 = 5 * v93 + 19;
          goto LABEL_113;
        case 5:
          v77 = (char *)a1[12] - (char *)v10;
          *((_BYTE *)a1 + 21) = 0;
          if ( v77 < 1 )
            GFxStream::PopulateBuffer1(this: a1);
          v78 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v79 = *((_BYTE *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v78);
          v78 = (_LUID_AND_ATTRIBUTES *)((char *)v78 + 1);
          v80 = (char *)a1[12] - (char *)v78;
          a1[11] = (GFxStream)v78;
          v81 = v79;
          *((_BYTE *)a1 + 21) = 0;
          if ( v80 < 1 )
            GFxStream::PopulateBuffer1(this: a1);
          v82 = (_LUID_AND_ATTRIBUTES *)a1[11];
          v83 = *((_BYTE *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v82);
          v84 = (_LUID_AND_ATTRIBUTES *)((char *)&v82->Luid.LowPart + 1);
          v85 = 4 * v81 * v83 + 13;
LABEL_113:
          for ( a1[11] = (GFxStream)v84; v85 != 0; v84 = (_LUID_AND_ATTRIBUTES *)a1[11] )
          {
            v94 = (char *)a1[12] - (char *)v84;
            --v85;
            *((_BYTE *)a1 + 21) = 0;
            if ( v94 < 1 )
              GFxStream::PopulateBuffer1(this: a1);
            a1[11] = (GFxStream)((char *)a1[11] + 1);
          }
          goto LABEL_117;
        case 6:
          v86 = 0;
          v135[0] = 0;
          v135[1] = 1;
          v135[2] = 2;
          v135[3] = 3;
          v135[4] = 16;
          v135[5] = 4;
          v135[6] = 5;
          v135[7] = 6;
          v135[8] = 7;
          v135[9] = 17;
          v135[10] = 8;
          v135[11] = 9;
          v135[12] = 10;
          v135[13] = 11;
          v135[14] = 18;
          v135[15] = 12;
          v135[16] = 13;
          v135[17] = 14;
          v135[18] = 15;
          v135[19] = 19;
          do
          {
            v87 = (char *)a1[12] - (char *)a1[11];
            *((_BYTE *)a1 + 21) = 0;
            if ( v87 < 4 )
              GFxStream::PopulateBuffer(this: (int)a1, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
            v88 = (_LUID_AND_ATTRIBUTES *)a1[11];
            LODWORD(v89) = *((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v88)
                         | ((*((unsigned __int8 *)&(*a1[15])[0].Luid.LowPart + (_DWORD)v88 + 1)
                           | ((*((unsigned __int8 *)&v88->Luid.LowPart + (_DWORD)a1[15] + 2)
                             | (*((unsigned __int8 *)&v88->Luid.LowPart + (_DWORD)a1[15] + 3) << 8)) << 8)) << 8);
            a1[11] = (GFxStream)&v88->Luid.HighPart;
            v90 = v135[v86++];
            dst[v90] = v89;
          }
          while ( v86 < 0x14 );
          dst[16] = dst[16] * 0.003921568859368563;
          dst[17] = dst[17] * 0.003921568859368563;
          dst[18] = dst[18] * 0.003921568859368563;
          dst[19] = 0.003921568859368563 * dst[19];
          if ( done )
            goto LABEL_120;
          if ( a2 != 0 && numFilters < 4 )
          {
LABEL_109:
            v91 = (_WORD *)(a2 + 156 * numFilters++);
            GFxFilterDesc::operator=(this: v91, a2: (int)filterDesc);
          }
          goto LABEL_118;
        default:
LABEL_117:
          if ( !done )
          {
LABEL_118:
            if ( numFilters == filterssz )
              done = true;
          }
LABEL_120:
          if ( filterCount != 0 )
            continue;
          result = numFilters;
          break;
      }
      break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10143110
// Name: unsigned int GFx_LoadFilters<struct GFxStreamContext>(struct GFxStreamContext __near *,struct GFxFilterDesc __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl GFx_LoadFilters<GFxStreamContext>(int *a1, _WORD *a2, int a3)
{
  int v3; // eax
  int v4; // ecx
  char v5; // dl
  unsigned int result; // eax
  int v7; // edi
  int v8; // eax
  unsigned __int8 v9; // cl
  char v10; // cl
  char v11; // cl
  char v12; // cl
  char v13; // dl
  int v14; // eax
  double v15; // st7
  char v16; // al
  int v17; // edx
  int v18; // eax
  int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  char v22; // cl
  char v23; // cl
  char v24; // cl
  char v25; // dl
  int v26; // eax
  char v27; // cl
  char v28; // al
  char v29; // dl
  char v30; // cl
  int v31; // ecx
  char v32; // cl
  char v33; // cl
  char v34; // cl
  char v35; // cl
  char v36; // cl
  char v37; // cl
  char v38; // cl
  char v39; // dl
  int v40; // eax
  double v41; // st7
  char v42; // al
  char v43; // dl
  int v44; // edx
  unsigned __int8 v45; // cl
  unsigned __int8 v46; // dl
  int v47; // eax
  int v48; // eax
  int v49; // ecx
  int v50; // edx
  int v51; // edi
  int v52; // ecx
  int v53; // edx
  int v54; // edx
  int v55; // edi
  int v56; // edi
  int v57; // edi
  double v58; // st7
  int v59; // edi
  int v60; // edi
  int v61; // edi
  double v62; // st7
  int v63; // edi
  double v64; // st7
  int v65; // edi
  double v66; // st7
  _WORD *v67; // ecx
  int v68; // ecx
  float v69; // [esp+Ch] [ebp-12Ch]
  float v70; // [esp+10h] [ebp-128h]
  float v71; // [esp+14h] [ebp-124h]
  float v72; // [esp+18h] [ebp-120h]
  double v73; // [esp+20h] [ebp-118h]
  double v74; // [esp+20h] [ebp-118h]
  int v75; // [esp+24h] [ebp-114h]
  int v76; // [esp+24h] [ebp-114h]
  int v77; // [esp+24h] [ebp-114h]
  _WORD *v78; // [esp+28h] [ebp-110h]
  unsigned int v79; // [esp+2Ch] [ebp-10Ch]
  char v80; // [esp+32h] [ebp-106h]
  int v81; // [esp+34h] [ebp-104h]
  float v82; // [esp+34h] [ebp-104h]
  float v83; // [esp+34h] [ebp-104h]
  float v84; // [esp+34h] [ebp-104h]
  float v85; // [esp+34h] [ebp-104h]
  char v86; // [esp+3Bh] [ebp-FDh]
  int v87; // [esp+3Ch] [ebp-FCh]
  int v88; // [esp+3Ch] [ebp-FCh]
  float v89; // [esp+3Ch] [ebp-FCh]
  float v90; // [esp+3Ch] [ebp-FCh]
  float v91; // [esp+3Ch] [ebp-FCh]
  int v92; // [esp+3Ch] [ebp-FCh]
  float v93; // [esp+3Ch] [ebp-FCh]
  float v94; // [esp+3Ch] [ebp-FCh]
  int v95; // [esp+3Ch] [ebp-FCh]
  int v96; // [esp+3Ch] [ebp-FCh]
  float v97; // [esp+3Ch] [ebp-FCh]
  float v98; // [esp+3Ch] [ebp-FCh]
  float v99; // [esp+3Ch] [ebp-FCh]
  int v100; // [esp+3Ch] [ebp-FCh]
  float v101; // [esp+3Ch] [ebp-FCh]
  float v102; // [esp+3Ch] [ebp-FCh]
  unsigned int i; // [esp+3Ch] [ebp-FCh]
  float v104; // [esp+40h] [ebp-F8h]
  float v105; // [esp+40h] [ebp-F8h]
  int v106; // [esp+40h] [ebp-F8h]
  int v107; // [esp+40h] [ebp-F8h]
  char v108; // [esp+47h] [ebp-F1h]
  char v109; // [esp+47h] [ebp-F1h]
  char v110[2]; // [esp+48h] [ebp-F0h] BYREF
  int v111; // [esp+4Ah] [ebp-EEh]
  int v112; // [esp+50h] [ebp-E8h]
  float v113; // [esp+54h] [ebp-E4h]
  float v114; // [esp+58h] [ebp-E0h]
  int v115; // [esp+5Ch] [ebp-DCh]
  float v116; // [esp+60h] [ebp-D8h]
  float v117; // [esp+64h] [ebp-D4h]
  int v118; // [esp+68h] [ebp-D0h]
  char v119; // [esp+6Ch] [ebp-CCh]
  char v120; // [esp+6Dh] [ebp-CBh]
  char v121; // [esp+6Eh] [ebp-CAh]
  char v122; // [esp+6Fh] [ebp-C9h]
  float v123; // [esp+70h] [ebp-C8h]
  float v124[8]; // [esp+74h] [ebp-C4h] BYREF
  float dst[20]; // [esp+94h] [ebp-A4h] BYREF
  int v126; // [esp+E4h] [ebp-54h]
  int v127; // [esp+E8h] [ebp-50h]
  int v128; // [esp+ECh] [ebp-4Ch]
  int v129; // [esp+F0h] [ebp-48h]
  int v130; // [esp+F4h] [ebp-44h]
  int v131; // [esp+F8h] [ebp-40h]
  int v132; // [esp+FCh] [ebp-3Ch]
  int v133; // [esp+100h] [ebp-38h]
  int v134; // [esp+104h] [ebp-34h]
  _DWORD v135[11]; // [esp+108h] [ebp-30h]

  if ( a1[3] != 0 )
    ++a1[2];
  v3 = a1[2];
  v4 = *a1;
  a1[3] = 0;
  v5 = *(_BYTE *)(v3 + v4);
  v113 = 5.0;
  v114 = 5.0;
  v116 = 0.0;
  v80 = v5;
  v117 = 0.0;
  a1[2] = v3 + 1;
  v112 = 0;
  v123 = 1.0;
  v115 = 1;
  GRenderer::Cxform::Cxform(this: v124);
  result = 0;
  v79 = 0;
  v86 = 0;
  if ( v80 != 0 )
  {
    v78 = a2;
    while ( 2 )
    {
      --v80;
      if ( a1[3] != 0 )
        ++a1[2];
      v7 = *a1;
      v8 = a1[2] + 1;
      a1[3] = 0;
      v9 = *(_BYTE *)(v7 + v8 - 1);
      v81 = v8;
      a1[2] = v8;
      v87 = v9;
      memset((unsigned __int8 *)dst, value: 0, count: sizeof(dst));
      dst[0] = 1.0;
      dst[5] = 1.0;
      v112 = 0;
      dst[10] = 1.0;
      v115 = 0;
      dst[15] = 1.0;
      v111 = 0;
      v118 = 0;
      v114 = 0.0;
      v110[0] = v87;
      v113 = 0.0;
      v123 = 1.0;
      v117 = 0.0;
      v116 = 0.0;
      switch ( v87 )
      {
        case 0:
          a1[3] = 0;
          v10 = *(_BYTE *)(v7 + v81);
          a1[2] = v81 + 1;
          a1[3] = 0;
          BYTE2(v118) = v10;
          v11 = *(_BYTE *)(v7 + v81 + 1);
          a1[2] = v81 + 2;
          BYTE1(v118) = v11;
          a1[3] = 0;
          v12 = *(_BYTE *)(v7 + v81 + 3 - 1);
          a1[2] = v81 + 3;
          LOBYTE(v118) = v12;
          HIBYTE(v118) = -1;
          a1[3] = 0;
          v13 = *(_BYTE *)(v7 + v81 + 3);
          a1[2] = v81 + 4;
          HIBYTE(v118) = v13;
          a1[3] = 0;
          v75 = *(unsigned __int8 *)(v7 + v81 + 4)
              | ((*(unsigned __int8 *)(v7 + v81 + 4 + 1) | (*(unsigned __int16 *)(v7 + v81 + 4 + 2) << 8)) << 8);
          a1[2] = v81 + 8;
          a1[3] = 0;
          v113 = (double)(unsigned int)v75 * 0.0000152587890625;
          v14 = *(unsigned __int8 *)(v7 + v81 + 12 - 4)
              | ((*(unsigned __int8 *)(v7 + v81 + 12 - 3) | (*(unsigned __int16 *)(v7 + v81 + 12 - 2) << 8)) << 8);
          a1[2] = v81 + 12;
          a1[3] = 0;
          v114 = (double)(unsigned int)v14 * 0.0000152587890625;
          v88 = *(unsigned __int8 *)(v7 + v81 + 12)
              | ((*(unsigned __int8 *)(v7 + v81 + 16 - 3) | (*(unsigned __int16 *)(v7 + v81 + 16 - 2) << 8)) << 8);
          a1[2] = v81 + 16;
          v89 = 0.0000152587890625 * (double)v88;
          v90 = v89 * 1800.0 / 3.141592741012573;
          LOWORD(v111) = (int)fmod(v90, 3600.0);
          a1[3] = 0;
          v15 = (double)(*(unsigned __int8 *)(v7 + v81 + 16)
                       | ((*(unsigned __int8 *)(v7 + v81 + 16 + 1) | (*(unsigned __int16 *)(v7 + v81 + 16 + 2) << 8)) << 8));
          a1[2] = v81 + 20;
          v91 = v15 * 0.0000152587890625;
          HIWORD(v111) = (int)(v91 * 20.0);
          a1[3] = 0;
          v92 = *(unsigned __int16 *)(v7 + v81 + 20);
          a1[2] = v81 + 22;
          a1[3] = 0;
          v108 = 0;
          v123 = (double)v92 * 0.00390625;
          v16 = *(_BYTE *)(v7 + v81 + 23 - 1);
          a1[2] = v81 + 23;
          if ( (v16 & 0x40) != 0 )
            v108 = 32;
          if ( (v16 & 0x20) == 0 )
            v108 |= 0x40u;
          if ( (v16 & 0xFu) > 1 )
            v108 |= 0x80u;
          v110[0] = v108;
          v115 = v16 & 0x1F;
          v17 = 0;
          if ( v16 < 0 )
            v17 = 512;
          if ( (v16 & 0x40) != 0 )
            v17 |= 0x100u;
          if ( (v16 & 0x20) == 0 )
            v17 |= 0x400u;
          v112 = v17 | 2;
          v93 = (double)(__int16)v111 * 3.141592741012573 / 1800.0;
          v73 = (double)SHIWORD(v111);
          v104 = cos(v93);
          v71 = v104 * v73 * 0.05000000074505806;
          v94 = sin(v93);
          v72 = v94 * v73 * 0.05000000074505806;
          v116 = v71;
          v117 = v72;
          if ( v86 == 0 )
          {
            if ( a2 == nullptr || v79 >= 4 )
              goto LABEL_69;
            goto LABEL_62;
          }
          goto LABEL_71;
        case 1:
          v112 = 1;
          a1[3] = 0;
          v18 = *(unsigned __int8 *)(v7 + v81)
              | ((*(unsigned __int8 *)(v7 + v81 + 1) | (*(unsigned __int16 *)(v7 + v81 + 2) << 8)) << 8);
          a1[2] = v81 + 4;
          a1[3] = 0;
          v113 = (double)(unsigned int)v18 * 0.0000152587890625;
          v19 = *(unsigned __int8 *)(v7 + v81 + 8 - 4)
              | ((*(unsigned __int8 *)(v7 + v81 + 8 - 3) | (*(unsigned __int16 *)(v7 + v81 + 8 - 2) << 8)) << 8);
          a1[2] = v81 + 8;
          a1[3] = 0;
          v114 = 0.0000152587890625 * (double)(unsigned int)v19;
          v20 = *(unsigned __int8 *)(v7 + v81 + 9 - 1);
          a1[2] = v81 + 9;
          v21 = v20 >> 3;
          v110[0] = (v21 > 1 ? 0x80 : 0) | 1;
          goto LABEL_25;
        case 2:
          a1[3] = 0;
          v22 = *(_BYTE *)(v7 + v81);
          a1[2] = v81 + 1;
          a1[3] = 0;
          BYTE2(v118) = v22;
          v23 = *(_BYTE *)(v7 + v81 + 1);
          a1[2] = v81 + 2;
          BYTE1(v118) = v23;
          a1[3] = 0;
          v24 = *(_BYTE *)(v7 + v81 + 3 - 1);
          a1[2] = v81 + 3;
          LOBYTE(v118) = v24;
          HIBYTE(v118) = -1;
          a1[3] = 0;
          v25 = *(_BYTE *)(v7 + v81 + 3);
          a1[2] = v81 + 4;
          HIBYTE(v118) = v25;
          a1[3] = 0;
          v76 = *(unsigned __int8 *)(v7 + v81 + 4)
              | ((*(unsigned __int8 *)(v7 + v81 + 4 + 1) | (*(unsigned __int16 *)(v7 + v81 + 4 + 2) << 8)) << 8);
          a1[2] = v81 + 8;
          a1[3] = 0;
          v113 = (double)(unsigned int)v76 * 0.0000152587890625;
          v26 = *(unsigned __int8 *)(v7 + v81 + 12 - 4)
              | ((*(unsigned __int8 *)(v7 + v81 + 12 - 3) | (*(unsigned __int16 *)(v7 + v81 + 12 - 2) << 8)) << 8);
          a1[2] = v81 + 12;
          a1[3] = 0;
          v114 = 0.0000152587890625 * (double)(unsigned int)v26;
          v95 = *(unsigned __int16 *)(v7 + v81 + 12);
          a1[2] = v81 + 14;
          a1[3] = 0;
          v123 = (double)v95 * 0.00390625;
          v27 = *(_BYTE *)(v81 + 15 + v7 - 1);
          a1[2] = v81 + 15;
          v28 = v27;
          v29 = v27;
          v30 = 0;
          if ( (v29 & 0x40) != 0 )
            v30 = 32;
          if ( (v28 & 0x20) == 0 )
            v30 |= 0x40u;
          if ( (v28 & 0xFu) > 1 )
            v30 |= 0x80u;
          v110[0] = v30 | 2;
          v31 = 0;
          if ( v28 < 0 )
            v31 = 512;
          if ( (v29 & 0x40) != 0 )
            v31 |= 0x100u;
          if ( (v28 & 0x20) == 0 )
            v31 |= 0x400u;
          v112 = v31 | 2;
          v21 = v28 & 0x1F;
LABEL_25:
          v115 = v21;
          if ( v86 != 0 )
            goto LABEL_71;
          if ( a2 != nullptr && v79 < 4 )
            goto LABEL_62;
          goto LABEL_69;
        case 3:
          a1[3] = 0;
          v32 = *(_BYTE *)(v7 + v81);
          a1[2] = v81 + 1;
          a1[3] = 0;
          BYTE2(v118) = v32;
          v33 = *(_BYTE *)(v7 + v81 + 1);
          a1[2] = v81 + 2;
          a1[3] = 0;
          BYTE1(v118) = v33;
          v34 = *(_BYTE *)(v7 + v81 + 2);
          a1[2] = v81 + 3;
          a1[3] = 0;
          LOBYTE(v118) = v34;
          HIBYTE(v118) = -1;
          v35 = *(_BYTE *)(v7 + v81 + 4 - 1);
          a1[2] = v81 + 4;
          a1[3] = 0;
          HIBYTE(v118) = v35;
          v36 = *(_BYTE *)(v7 + v81 + 4);
          a1[2] = v81 + 5;
          a1[3] = 0;
          v121 = v36;
          v37 = *(_BYTE *)(v81 + 5 + v7);
          a1[2] = v81 + 6;
          v120 = v37;
          a1[3] = 0;
          v38 = *(_BYTE *)(v81 + 7 + v7 - 1);
          a1[2] = v81 + 7;
          v119 = v38;
          v122 = -1;
          a1[3] = 0;
          v39 = *(_BYTE *)(v81 + 7 + v7);
          a1[2] = v81 + 8;
          v122 = v39;
          a1[3] = 0;
          v77 = *(unsigned __int8 *)(v81 + 8 + v7)
              | ((*(unsigned __int8 *)(v81 + 8 + v7 + 1) | (*(unsigned __int16 *)(v81 + 8 + v7 + 2) << 8)) << 8);
          a1[2] = v81 + 12;
          a1[3] = 0;
          v113 = (double)(unsigned int)v77 * 0.0000152587890625;
          v40 = *(unsigned __int8 *)(v81 + 16 + v7 - 4)
              | ((*(unsigned __int8 *)(v81 + 16 + v7 - 3) | (*(unsigned __int16 *)(v81 + 16 + v7 - 2) << 8)) << 8);
          a1[2] = v81 + 16;
          a1[3] = 0;
          v114 = (double)(unsigned int)v40 * 0.0000152587890625;
          v96 = *(unsigned __int8 *)(v81 + 16 + v7)
              | ((*(unsigned __int8 *)(v81 + 20 + v7 - 3) | (*(unsigned __int16 *)(v81 + 20 + v7 - 2) << 8)) << 8);
          a1[2] = v81 + 20;
          v97 = 0.0000152587890625 * (double)v96;
          v98 = v97 * 1800.0 / 3.141592741012573;
          LOWORD(v111) = (int)fmod(v98, 3600.0);
          a1[3] = 0;
          v41 = (double)(*(unsigned __int8 *)(v81 + 20 + v7)
                       | ((*(unsigned __int8 *)(v81 + 20 + v7 + 1) | (*(unsigned __int16 *)(v81 + 20 + v7 + 2) << 8)) << 8));
          a1[2] = v81 + 24;
          v99 = v41 * 0.0000152587890625;
          HIWORD(v111) = (int)(v99 * 20.0);
          a1[3] = 0;
          v100 = *(unsigned __int16 *)(v81 + 24 + v7);
          a1[2] = v81 + 26;
          a1[3] = 0;
          v109 = 0;
          v123 = (double)v100 * 0.00390625;
          v42 = *(_BYTE *)(v81 + 27 + v7 - 1);
          a1[2] = v81 + 27;
          if ( (v42 & 0x40) != 0 )
            v109 = 32;
          if ( (v42 & 0x20) == 0 )
            v109 |= 0x40u;
          v43 = v109;
          if ( (v42 & 0xFu) > 1 )
            v43 = v109 | 0x80;
          v110[0] = v43 | 3;
          v115 = v42 & 0xF;
          v44 = 0;
          if ( v42 < 0 )
            v44 = 512;
          if ( (v42 & 0x40) != 0 )
            v44 |= 0x100u;
          if ( (v42 & 0x20) == 0 )
            v44 |= 0x400u;
          v112 = v44 | 6;
          v101 = (double)(__int16)v111 * 3.141592741012573 / 1800.0;
          v74 = (double)SHIWORD(v111);
          v105 = cos(v101);
          v69 = v105 * v74 * 0.05000000074505806;
          v102 = sin(v101);
          v70 = v102 * v74 * 0.05000000074505806;
          v116 = v69;
          v117 = v70;
          goto LABEL_59;
        case 4:
        case 7:
          a1[3] = 0;
          v47 = 5 * *(unsigned __int8 *)(v7 + v81) + 19;
          a1[2] = v81 + 1;
          goto LABEL_64;
        case 5:
          a1[3] = 0;
          v45 = *(_BYTE *)(v7 + v81);
          a1[2] = v81 + 1;
          a1[3] = 0;
          v46 = *(_BYTE *)(v7 + v81 + 2 - 1);
          a1[2] = v81 + 2;
          v47 = 4 * v45 * v46 + 13;
LABEL_64:
          if ( v47 != 0 )
          {
            v68 = a1[2];
            do
            {
              --v47;
              ++v68;
            }
            while ( v47 != 0 );
            a1[3] = 0;
            a1[2] = v68;
          }
          goto LABEL_68;
        case 6:
          v48 = *a1;
          v49 = a1[2];
          v126 = 0;
          v127 = 1;
          v128 = 2;
          v129 = 3;
          v130 = 16;
          v131 = 4;
          v132 = 5;
          v133 = 6;
          v134 = 7;
          v135[0] = 17;
          v135[1] = 8;
          v135[2] = 9;
          v135[3] = 10;
          v135[4] = 11;
          v135[5] = 18;
          v135[6] = 12;
          v135[7] = 13;
          v135[8] = 14;
          v135[9] = 15;
          v135[10] = 19;
          for ( i = 0; i < 0x14; i += 10 )
          {
            a1[3] = 0;
            v50 = *(unsigned __int8 *)(v49 + v48 + 1) | (*(unsigned __int16 *)(v49 + v48 + 2) << 8);
            v51 = *(unsigned __int8 *)(v49 + v48);
            v52 = v49 + 4;
            a1[2] = v52;
            LODWORD(v82) = v51 | (v50 << 8);
            v53 = *(&v126 + i);
            a1[3] = 0;
            v52 += 4;
            dst[v53] = v82;
            v54 = *(unsigned __int8 *)(v52 + v48 - 3) | (*(unsigned __int16 *)(v52 + v48 - 2) << 8);
            v55 = *(unsigned __int8 *)(v52 + v48 - 4);
            a1[2] = v52;
            a1[3] = 0;
            dst[*(&v127 + i)] = COERCE_FLOAT(v55 | (v54 << 8));
            LODWORD(v83) = *(unsigned __int8 *)(v52 + v48)
                         | ((*(unsigned __int8 *)(v52 + v48 + 1) | (*(unsigned __int16 *)(v52 + v48 + 2) << 8)) << 8);
            v56 = *(&v128 + i);
            a1[2] = v52 + 4;
            dst[v56] = v83;
            v106 = v52 + 4;
            a1[3] = 0;
            v57 = *(&v129 + i);
            v52 += 8;
            v58 = COERCE_FLOAT(
                    *(unsigned __int8 *)(v106 + v48)
                  | ((*(unsigned __int8 *)(v106 + v48 + 1) | (*(unsigned __int16 *)(v106 + v48 + 2) << 8)) << 8));
            a1[2] = v106 + 4;
            dst[v57] = v58;
            a1[3] = 0;
            LODWORD(v84) = *(unsigned __int8 *)(v52 + v48)
                         | ((*(unsigned __int8 *)(v52 + v48 + 1)
                           | ((*(unsigned __int8 *)(v52 + v48 + 2) | (*(unsigned __int8 *)(v52 + v48 + 3) << 8)) << 8)) << 8);
            v59 = *(&v130 + i);
            v52 += 4;
            a1[2] = v52;
            dst[v59] = v84;
            a1[3] = 0;
            LODWORD(v85) = *(unsigned __int8 *)(v52 + v48)
                         | ((*(unsigned __int8 *)(v52 + v48 + 1) | (*(unsigned __int16 *)(v52 + v48 + 2) << 8)) << 8);
            v60 = *(&v131 + i);
            a1[2] = v52 + 4;
            dst[v60] = v85;
            a1[3] = 0;
            v61 = *(&v132 + i);
            v62 = COERCE_FLOAT(
                    *(unsigned __int8 *)(v52 + 4 + v48)
                  | ((*(unsigned __int8 *)(v52 + 4 + v48 + 1) | (*(unsigned __int16 *)(v52 + 4 + v48 + 2) << 8)) << 8));
            a1[2] = v52 + 8;
            dst[v61] = v62;
            a1[3] = 0;
            v63 = *(&v133 + i);
            v64 = COERCE_FLOAT(
                    *(unsigned __int8 *)(v52 + 8 + v48)
                  | ((*(unsigned __int8 *)(v52 + 8 + v48 + 1) | (*(unsigned __int16 *)(v52 + 8 + v48 + 2) << 8)) << 8));
            a1[2] = v52 + 12;
            dst[v63] = v64;
            a1[3] = 0;
            v65 = v135[i - 1];
            v66 = COERCE_FLOAT(
                    *(unsigned __int8 *)(v52 + 12 + v48)
                  | ((*(unsigned __int8 *)(v52 + 12 + v48 + 1) | (*(unsigned __int16 *)(v52 + 12 + v48 + 2) << 8)) << 8));
            a1[2] = v52 + 16;
            dst[v65] = v66;
            v107 = v52 + 16;
            a1[3] = 0;
            v49 = v52 + 20;
            dst[v135[i]] = COERCE_FLOAT(
                             *(unsigned __int8 *)(v48 + v107)
                           | ((*(unsigned __int8 *)(v48 + v107 + 1) | (*(unsigned __int16 *)(v48 + v107 + 2) << 8)) << 8));
            a1[2] = v49;
          }
          dst[16] = dst[16] * 0.003921568859368563;
          dst[17] = dst[17] * 0.003921568859368563;
          dst[18] = dst[18] * 0.003921568859368563;
          dst[19] = 0.003921568859368563 * dst[19];
LABEL_59:
          if ( v86 != 0 )
            goto LABEL_71;
          if ( a2 != nullptr && v79 < 4 )
          {
LABEL_62:
            ++v79;
            v67 = v78;
            v78 += 78;
            GFxFilterDesc::operator=(this: v67, a2: (int)v110);
          }
          goto LABEL_69;
        default:
LABEL_68:
          if ( v86 == 0 )
          {
LABEL_69:
            if ( v79 == a3 )
              v86 = 1;
          }
LABEL_71:
          if ( v80 != 0 )
            continue;
          result = v79;
          break;
      }
      break;
    }
  }
  return result;
}
