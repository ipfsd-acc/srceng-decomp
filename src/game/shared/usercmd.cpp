// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/usercmd.cpp
// Functions: 8
// ============================================================

#include "game\shared\usercmd.h"

//------------------------------------------------------------------------------
// Address: 0x1017A8A0
// Name: public: void bf_write::WriteUBitLong(unsigned int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall bf_write::WriteUBitLong(bf_write *this, unsigned int curData, int numbits, bool bCheckRange)
{
  int m_iCurBit; // ecx
  int m_nDataBits; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // edx

  m_iCurBit = this->m_iCurBit;
  m_nDataBits = this->m_nDataBits;
  if ( m_iCurBit + numbits <= m_nDataBits )
  {
    v7 = m_iCurBit;
    v8 = m_iCurBit & 0x1F;
    v9 = v7 >> 5;
    *(_DWORD *)&this->m_pData[4 * v9] = (curData << v8)
                                      | *(_DWORD *)&this->m_pData[4 * v9] & g_BitWriteMasks[0][32 * v8 + v8 + numbits];
    if ( 32 - v8 < numbits )
      *(_DWORD *)&this->m_pData[4 * v9 + 4] = (curData >> (32 - v8))
                                            | *(_DWORD *)&this->m_pData[4 * v9 + 4]
                                            & g_BitWriteMasks[0][numbits - (32 - v8)];
    this->m_iCurBit += numbits;
  }
  else
  {
    this->m_iCurBit = m_nDataBits;
    this->m_bOverflow = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017A930
// Name: void ReadUsercmd(class bf_read __near *,class CUserCmd __near *,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReadUsercmd(bf_read *buf, CUserCmd *move, CUserCmd *from)
{
  CUserCmd *v3; // ebx
  unsigned int m_nInBufWord; // eax
  int v6; // ecx
  bool v7; // zf
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // edx
  int m_nBitsAvail; // ecx
  unsigned int v11; // eax
  const unsigned int *v12; // ecx
  const unsigned int *v13; // edx
  CUserCmd *v14; // edx
  const unsigned int *v15; // edx
  unsigned int v16; // edi
  int v17; // eax
  const unsigned int *v18; // ecx
  unsigned int v19; // edx
  unsigned int v20; // ebx
  int v21; // edi
  unsigned int v22; // eax
  int v23; // edx
  const unsigned int *v24; // eax
  const unsigned int *v25; // ecx
  int v26; // ecx
  unsigned int v27; // eax
  int v28; // ecx
  const unsigned int *v29; // ecx
  const unsigned int *v30; // edx
  CUserCmd *v31; // edx
  const unsigned int *v32; // edx
  unsigned int v33; // edi
  int v34; // eax
  const unsigned int *v35; // ecx
  unsigned int v36; // edx
  unsigned int v37; // ebx
  unsigned int v38; // eax
  int v39; // edx
  const unsigned int *v40; // eax
  const unsigned int *v41; // ecx
  int v42; // ecx
  unsigned int v43; // eax
  int v44; // ecx
  const unsigned int *v45; // ecx
  const unsigned int *v46; // edx
  const unsigned int *v47; // edx
  unsigned int v48; // edi
  int v49; // eax
  const unsigned int *v50; // ecx
  unsigned int v51; // edx
  unsigned int v52; // ebx
  unsigned int v53; // eax
  int v54; // edx
  const unsigned int *v55; // eax
  const unsigned int *v56; // ecx
  int v57; // ecx
  unsigned int v58; // eax
  int v59; // ecx
  const unsigned int *v60; // ecx
  const unsigned int *v61; // edx
  const unsigned int *v62; // edx
  unsigned int v63; // edi
  int v64; // eax
  const unsigned int *v65; // ecx
  unsigned int v66; // edx
  unsigned int v67; // ebx
  unsigned int v68; // eax
  int v69; // edx
  const unsigned int *v70; // eax
  const unsigned int *v71; // ecx
  int v72; // ecx
  unsigned int v73; // eax
  int v74; // ecx
  const unsigned int *v75; // ecx
  const unsigned int *v76; // edx
  const unsigned int *v77; // edx
  unsigned int v78; // edi
  int v79; // eax
  const unsigned int *v80; // ecx
  unsigned int v81; // edx
  unsigned int v82; // ebx
  unsigned int v83; // eax
  int v84; // edx
  const unsigned int *v85; // eax
  const unsigned int *v86; // ecx
  int v87; // ecx
  unsigned int v88; // eax
  int v89; // ecx
  const unsigned int *v90; // ecx
  const unsigned int *v91; // edx
  const unsigned int *v92; // edx
  unsigned int v93; // edi
  int v94; // eax
  const unsigned int *v95; // ecx
  unsigned int v96; // edx
  unsigned int v97; // ebx
  unsigned int v98; // eax
  int v99; // edx
  const unsigned int *v100; // eax
  const unsigned int *v101; // ecx
  int v102; // ecx
  unsigned int v103; // eax
  int v104; // ecx
  const unsigned int *v105; // ecx
  const unsigned int *v106; // edx
  const unsigned int *v107; // edx
  unsigned int v108; // edi
  int v109; // eax
  const unsigned int *v110; // ecx
  unsigned int v111; // edx
  unsigned int v112; // ebx
  unsigned int v113; // eax
  int v114; // edx
  const unsigned int *v115; // eax
  const unsigned int *v116; // ecx
  int v117; // ecx
  unsigned int v118; // eax
  int v119; // ecx
  const unsigned int *v120; // ecx
  const unsigned int *v121; // edx
  const unsigned int *v122; // edx
  unsigned int v123; // edi
  int v124; // eax
  const unsigned int *v125; // ecx
  unsigned int v126; // edx
  unsigned int v127; // ebx
  unsigned int v128; // eax
  int v129; // edx
  const unsigned int *v130; // eax
  const unsigned int *v131; // ecx
  int v132; // ecx
  unsigned int v133; // eax
  int v134; // ecx
  int v135; // edi
  const unsigned int *v136; // ecx
  const unsigned int *v137; // edx
  const unsigned int *v138; // edx
  unsigned int v139; // edi
  int v140; // eax
  const unsigned int *v141; // ecx
  unsigned int v142; // edx
  unsigned int v143; // ebx
  unsigned int v144; // eax
  int v145; // edx
  const unsigned int *v146; // eax
  const unsigned int *v147; // ecx
  int v148; // ecx
  unsigned int v149; // eax
  char v150; // dl
  int v151; // ecx
  const unsigned int *v152; // ecx
  unsigned int v153; // ecx
  const unsigned int *v154; // edx
  unsigned int v155; // edi
  const unsigned int *v156; // ecx
  unsigned int v157; // edx
  unsigned int v158; // ebx
  unsigned int v159; // edx
  unsigned int v160; // eax
  int v161; // edx
  const unsigned int *v162; // eax
  const unsigned int *v163; // ecx
  int v164; // ecx
  unsigned int v165; // eax
  int v166; // edx
  int v167; // ecx
  int v168; // eax
  const unsigned int *v169; // eax
  const unsigned int *v170; // ecx
  unsigned int v171; // ecx
  const unsigned int *v172; // edx
  unsigned int v173; // edi
  int v174; // eax
  const unsigned int *v175; // ecx
  unsigned int v176; // edx
  unsigned int v177; // ebx
  unsigned int v178; // edx
  unsigned int v179; // eax
  int v180; // ecx
  const unsigned int *v181; // eax
  const unsigned int *v182; // edx
  int v183; // ecx
  unsigned int v184; // eax
  int v185; // edi
  int v186; // ecx
  const unsigned int *v187; // eax
  const unsigned int *v188; // ecx
  const unsigned int *v189; // edx
  unsigned int v190; // edi
  int v191; // eax
  const unsigned int *v192; // ecx
  unsigned int v193; // edx
  unsigned int v194; // ebx
  unsigned int v195; // eax
  unsigned int *v196; // ecx
  const unsigned int *v197; // eax
  const unsigned int *v198; // edx
  int v199; // ecx
  unsigned int v200; // eax
  __int16 v201; // di
  const unsigned int *v202; // eax
  const unsigned int *v203; // edx
  unsigned int v204; // edi
  unsigned int *v205; // eax
  unsigned int v206; // edx
  unsigned int v207; // ebx
  unsigned int v208; // eax
  int v209; // edx
  const unsigned int *v210; // eax
  int v211; // ecx
  unsigned int v212; // eax
  __int16 v213; // di
  const unsigned int *v214; // eax
  const unsigned int *v215; // edx
  unsigned int v216; // edi
  unsigned int *v217; // eax
  unsigned int v218; // edx
  unsigned int v219; // ebx
  unsigned int v220; // eax
  int v221; // edx
  const unsigned int *v222; // eax
  const unsigned int *v223; // ecx
  unsigned int v224; // eax
  int v225; // edx
  const unsigned int *v226; // eax
  const unsigned int *v227; // ecx
  unsigned int v228; // eax
  int v229; // edx
  const unsigned int *v230; // eax
  const unsigned int *v231; // ecx
  unsigned int v232; // eax
  int v233; // edx
  const unsigned int *v234; // eax
  const unsigned int *v235; // ecx
  bf_read *bufa; // [esp+14h] [ebp+8h]
  bf_read *bufb; // [esp+14h] [ebp+8h]
  bf_read *bufc; // [esp+14h] [ebp+8h]
  bf_read *bufd; // [esp+14h] [ebp+8h]
  bf_read *bufe; // [esp+14h] [ebp+8h]
  bf_read *buff; // [esp+14h] [ebp+8h]

  v3 = from;
  CUserCmd::operator=(this: move, src: from);
  m_nInBufWord = buf->m_nInBufWord;
  v6 = m_nInBufWord & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    m_pDataIn = buf->m_pDataIn;
    m_pBufferEnd = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      buf->m_nInBufWord = *m_pDataIn;
      buf->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = m_nInBufWord >> 1;
  }
  if ( v6 == 0 )
  {
    move->command_number = from->command_number + 1;
    goto LABEL_28;
  }
  m_nBitsAvail = buf->m_nBitsAvail;
  if ( m_nBitsAvail < 32 )
  {
    v15 = buf->m_pBufferEnd;
    v16 = buf->m_nInBufWord;
    v17 = 32 - m_nBitsAvail;
    v18 = buf->m_pDataIn;
    if ( v18 == v15 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v18 > v15 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_24;
      }
      buf->m_nInBufWord = *v18;
    }
    buf->m_pDataIn = v18 + 1;
LABEL_24:
    if ( buf->m_bOverflow )
    {
      move->command_number = 0;
    }
    else
    {
      v19 = buf->m_nInBufWord;
      v20 = (v19 & CBitBuffer::s_nMaskTable[v17]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v17;
      v21 = v20 | v16;
      v3 = from;
      buf->m_nInBufWord = v19 >> v17;
      move->command_number = v21;
    }
    goto LABEL_28;
  }
  v11 = buf->m_nInBufWord;
  buf->m_nBitsAvail = m_nBitsAvail - 32;
  if ( m_nBitsAvail == 32 )
  {
    v12 = buf->m_pDataIn;
    v13 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v12 == v13 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v12 + 1;
      move->command_number = v11;
    }
    else
    {
      if ( v12 <= v13 )
      {
        buf->m_nInBufWord = *v12;
        v14 = move;
        buf->m_pDataIn = v12 + 1;
      }
      else
      {
        v14 = move;
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
      v14->command_number = v11;
    }
  }
  else
  {
    buf->m_nInBufWord = 0;
    move->command_number = v11;
  }
LABEL_28:
  v22 = buf->m_nInBufWord;
  v23 = v22 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v24 = buf->m_pDataIn;
    v25 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v24 == v25 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v24 + 1;
    }
    else if ( v24 <= v25 )
    {
      buf->m_nInBufWord = *v24;
      buf->m_pDataIn = v24 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v22 >> 1;
  }
  if ( v23 == 0 )
  {
    move->tick_count = v3->tick_count + 1;
    goto LABEL_55;
  }
  v26 = buf->m_nBitsAvail;
  if ( v26 < 32 )
  {
    v32 = buf->m_pBufferEnd;
    v33 = buf->m_nInBufWord;
    v34 = 32 - v26;
    v35 = buf->m_pDataIn;
    if ( v35 == v32 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v35 > v32 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_51;
      }
      buf->m_nInBufWord = *v35;
    }
    buf->m_pDataIn = v35 + 1;
LABEL_51:
    if ( buf->m_bOverflow )
    {
      move->tick_count = 0;
    }
    else
    {
      v36 = buf->m_nInBufWord;
      v37 = (v36 & CBitBuffer::s_nMaskTable[v34]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v34;
      buf->m_nInBufWord = v36 >> v34;
      move->tick_count = v37 | v33;
    }
    goto LABEL_55;
  }
  v27 = buf->m_nInBufWord;
  v28 = v26 - 32;
  buf->m_nBitsAvail = v28;
  if ( v28 != 0 )
  {
    buf->m_nInBufWord = 0;
    move->tick_count = v27;
  }
  else
  {
    v29 = buf->m_pDataIn;
    v30 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v29 == v30 )
    {
      buf->m_nInBufWord = 0;
      buf->m_nBitsAvail = 1;
      buf->m_pDataIn = v29 + 1;
      move->tick_count = v27;
    }
    else
    {
      if ( v29 <= v30 )
      {
        buf->m_nInBufWord = *v29;
        v31 = move;
        buf->m_pDataIn = v29 + 1;
      }
      else
      {
        v31 = move;
        buf->m_nInBufWord = 0;
        buf->m_bOverflow = true;
      }
      v31->tick_count = v27;
    }
  }
LABEL_55:
  v38 = buf->m_nInBufWord;
  v39 = v38 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v40 = buf->m_pDataIn;
    v41 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v40 == v41 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v40 + 1;
    }
    else if ( v40 <= v41 )
    {
      buf->m_nInBufWord = *v40;
      buf->m_pDataIn = v40 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v38 >> 1;
  }
  if ( v39 != 0 )
  {
    v42 = buf->m_nBitsAvail;
    if ( v42 >= 32 )
    {
      v43 = buf->m_nInBufWord;
      v44 = v42 - 32;
      buf->m_nBitsAvail = v44;
      if ( v44 != 0 )
      {
        buf->m_nInBufWord = 0;
        bufa = (bf_read *)v43;
      }
      else
      {
        v45 = buf->m_pDataIn;
        v46 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v45 == v46 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v45 + 1;
          bufa = (bf_read *)v43;
        }
        else
        {
          if ( v45 <= v46 )
          {
            buf->m_nInBufWord = *v45;
            buf->m_pDataIn = v45 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          bufa = (bf_read *)v43;
        }
      }
      goto LABEL_81;
    }
    v47 = buf->m_pBufferEnd;
    v48 = buf->m_nInBufWord;
    v49 = 32 - v42;
    v50 = buf->m_pDataIn;
    if ( v50 == v47 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v50 > v47 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_78;
      }
      buf->m_nInBufWord = *v50;
    }
    buf->m_pDataIn = v50 + 1;
LABEL_78:
    if ( buf->m_bOverflow )
    {
      bufa = nullptr;
    }
    else
    {
      v51 = buf->m_nInBufWord;
      v52 = (v51 & CBitBuffer::s_nMaskTable[v49]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v49;
      bufa = (bf_read *)(v52 | v48);
      buf->m_nInBufWord = v51 >> v49;
    }
LABEL_81:
    LODWORD(move->viewangles.x) = bufa;
  }
  v53 = buf->m_nInBufWord;
  v54 = v53 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v55 = buf->m_pDataIn;
    v56 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v55 == v56 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v55 + 1;
    }
    else if ( v55 <= v56 )
    {
      buf->m_nInBufWord = *v55;
      buf->m_pDataIn = v55 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v53 >> 1;
  }
  if ( v54 != 0 )
  {
    v57 = buf->m_nBitsAvail;
    if ( v57 >= 32 )
    {
      v58 = buf->m_nInBufWord;
      v59 = v57 - 32;
      buf->m_nBitsAvail = v59;
      if ( v59 != 0 )
      {
        buf->m_nInBufWord = 0;
        bufb = (bf_read *)v58;
      }
      else
      {
        v60 = buf->m_pDataIn;
        v61 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v60 == v61 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v60 + 1;
          bufb = (bf_read *)v58;
        }
        else
        {
          if ( v60 <= v61 )
          {
            buf->m_nInBufWord = *v60;
            buf->m_pDataIn = v60 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          bufb = (bf_read *)v58;
        }
      }
      goto LABEL_108;
    }
    v62 = buf->m_pBufferEnd;
    v63 = buf->m_nInBufWord;
    v64 = 32 - v57;
    v65 = buf->m_pDataIn;
    if ( v65 == v62 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v65 > v62 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_105;
      }
      buf->m_nInBufWord = *v65;
    }
    buf->m_pDataIn = v65 + 1;
LABEL_105:
    if ( buf->m_bOverflow )
    {
      bufb = nullptr;
    }
    else
    {
      v66 = buf->m_nInBufWord;
      v67 = (v66 & CBitBuffer::s_nMaskTable[v64]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v64;
      bufb = (bf_read *)(v67 | v63);
      buf->m_nInBufWord = v66 >> v64;
    }
LABEL_108:
    LODWORD(move->viewangles.y) = bufb;
  }
  v68 = buf->m_nInBufWord;
  v69 = v68 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v70 = buf->m_pDataIn;
    v71 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v70 == v71 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v70 + 1;
    }
    else if ( v70 <= v71 )
    {
      buf->m_nInBufWord = *v70;
      buf->m_pDataIn = v70 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v68 >> 1;
  }
  if ( v69 != 0 )
  {
    v72 = buf->m_nBitsAvail;
    if ( v72 >= 32 )
    {
      v73 = buf->m_nInBufWord;
      v74 = v72 - 32;
      buf->m_nBitsAvail = v74;
      if ( v74 != 0 )
      {
        buf->m_nInBufWord = 0;
        bufc = (bf_read *)v73;
      }
      else
      {
        v75 = buf->m_pDataIn;
        v76 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v75 == v76 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v75 + 1;
          bufc = (bf_read *)v73;
        }
        else
        {
          if ( v75 <= v76 )
          {
            buf->m_nInBufWord = *v75;
            buf->m_pDataIn = v75 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          bufc = (bf_read *)v73;
        }
      }
      goto LABEL_135;
    }
    v77 = buf->m_pBufferEnd;
    v78 = buf->m_nInBufWord;
    v79 = 32 - v72;
    v80 = buf->m_pDataIn;
    if ( v80 == v77 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v80 > v77 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_132;
      }
      buf->m_nInBufWord = *v80;
    }
    buf->m_pDataIn = v80 + 1;
LABEL_132:
    if ( buf->m_bOverflow )
    {
      bufc = nullptr;
    }
    else
    {
      v81 = buf->m_nInBufWord;
      v82 = (v81 & CBitBuffer::s_nMaskTable[v79]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v79;
      bufc = (bf_read *)(v82 | v78);
      buf->m_nInBufWord = v81 >> v79;
    }
LABEL_135:
    LODWORD(move->viewangles.z) = bufc;
  }
  v83 = buf->m_nInBufWord;
  v84 = v83 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v85 = buf->m_pDataIn;
    v86 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v85 == v86 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v85 + 1;
    }
    else if ( v85 <= v86 )
    {
      buf->m_nInBufWord = *v85;
      buf->m_pDataIn = v85 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v83 >> 1;
  }
  if ( v84 != 0 )
  {
    v87 = buf->m_nBitsAvail;
    if ( v87 >= 32 )
    {
      v88 = buf->m_nInBufWord;
      v89 = v87 - 32;
      buf->m_nBitsAvail = v89;
      if ( v89 != 0 )
      {
        buf->m_nInBufWord = 0;
        bufd = (bf_read *)v88;
      }
      else
      {
        v90 = buf->m_pDataIn;
        v91 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v90 == v91 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v90 + 1;
          bufd = (bf_read *)v88;
        }
        else
        {
          if ( v90 <= v91 )
          {
            buf->m_nInBufWord = *v90;
            buf->m_pDataIn = v90 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          bufd = (bf_read *)v88;
        }
      }
      goto LABEL_162;
    }
    v92 = buf->m_pBufferEnd;
    v93 = buf->m_nInBufWord;
    v94 = 32 - v87;
    v95 = buf->m_pDataIn;
    if ( v95 == v92 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v95 > v92 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_159;
      }
      buf->m_nInBufWord = *v95;
    }
    buf->m_pDataIn = v95 + 1;
LABEL_159:
    if ( buf->m_bOverflow )
    {
      bufd = nullptr;
    }
    else
    {
      v96 = buf->m_nInBufWord;
      v97 = (v96 & CBitBuffer::s_nMaskTable[v94]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v94;
      bufd = (bf_read *)(v97 | v93);
      buf->m_nInBufWord = v96 >> v94;
    }
LABEL_162:
    LODWORD(move->forwardmove) = bufd;
  }
  v98 = buf->m_nInBufWord;
  v99 = v98 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v100 = buf->m_pDataIn;
    v101 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v100 == v101 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v100 + 1;
    }
    else if ( v100 <= v101 )
    {
      buf->m_nInBufWord = *v100;
      buf->m_pDataIn = v100 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v98 >> 1;
  }
  if ( v99 != 0 )
  {
    v102 = buf->m_nBitsAvail;
    if ( v102 >= 32 )
    {
      v103 = buf->m_nInBufWord;
      v104 = v102 - 32;
      buf->m_nBitsAvail = v104;
      if ( v104 != 0 )
      {
        buf->m_nInBufWord = 0;
        bufe = (bf_read *)v103;
      }
      else
      {
        v105 = buf->m_pDataIn;
        v106 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v105 == v106 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v105 + 1;
          bufe = (bf_read *)v103;
        }
        else
        {
          if ( v105 <= v106 )
          {
            buf->m_nInBufWord = *v105;
            buf->m_pDataIn = v105 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          bufe = (bf_read *)v103;
        }
      }
      goto LABEL_189;
    }
    v107 = buf->m_pBufferEnd;
    v108 = buf->m_nInBufWord;
    v109 = 32 - v102;
    v110 = buf->m_pDataIn;
    if ( v110 == v107 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v110 > v107 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_186;
      }
      buf->m_nInBufWord = *v110;
    }
    buf->m_pDataIn = v110 + 1;
LABEL_186:
    if ( buf->m_bOverflow )
    {
      bufe = nullptr;
    }
    else
    {
      v111 = buf->m_nInBufWord;
      v112 = (v111 & CBitBuffer::s_nMaskTable[v109]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v109;
      bufe = (bf_read *)(v112 | v108);
      buf->m_nInBufWord = v111 >> v109;
    }
LABEL_189:
    LODWORD(move->sidemove) = bufe;
  }
  v113 = buf->m_nInBufWord;
  v114 = v113 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v115 = buf->m_pDataIn;
    v116 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v115 == v116 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v115 + 1;
    }
    else if ( v115 <= v116 )
    {
      buf->m_nInBufWord = *v115;
      buf->m_pDataIn = v115 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v113 >> 1;
  }
  if ( v114 != 0 )
  {
    v117 = buf->m_nBitsAvail;
    if ( v117 >= 32 )
    {
      v118 = buf->m_nInBufWord;
      v119 = v117 - 32;
      buf->m_nBitsAvail = v119;
      if ( v119 != 0 )
      {
        buf->m_nInBufWord = 0;
        buff = (bf_read *)v118;
      }
      else
      {
        v120 = buf->m_pDataIn;
        v121 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v120 == v121 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v120 + 1;
          buff = (bf_read *)v118;
        }
        else
        {
          if ( v120 <= v121 )
          {
            buf->m_nInBufWord = *v120;
            buf->m_pDataIn = v120 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          buff = (bf_read *)v118;
        }
      }
      goto LABEL_216;
    }
    v122 = buf->m_pBufferEnd;
    v123 = buf->m_nInBufWord;
    v124 = 32 - v117;
    v125 = buf->m_pDataIn;
    if ( v125 == v122 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v125 > v122 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_213;
      }
      buf->m_nInBufWord = *v125;
    }
    buf->m_pDataIn = v125 + 1;
LABEL_213:
    if ( buf->m_bOverflow )
    {
      buff = nullptr;
    }
    else
    {
      v126 = buf->m_nInBufWord;
      v127 = (v126 & CBitBuffer::s_nMaskTable[v124]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v124;
      buff = (bf_read *)(v127 | v123);
      buf->m_nInBufWord = v126 >> v124;
    }
LABEL_216:
    LODWORD(move->upmove) = buff;
  }
  v128 = buf->m_nInBufWord;
  v129 = v128 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v130 = buf->m_pDataIn;
    v131 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v130 == v131 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v130 + 1;
    }
    else if ( v130 <= v131 )
    {
      buf->m_nInBufWord = *v130;
      buf->m_pDataIn = v130 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v128 >> 1;
  }
  if ( v129 != 0 )
  {
    v132 = buf->m_nBitsAvail;
    if ( v132 >= 32 )
    {
      v133 = buf->m_nInBufWord;
      v134 = v132 - 32;
      buf->m_nBitsAvail = v134;
      if ( v134 != 0 )
      {
        buf->m_nInBufWord = 0;
        v135 = v133;
      }
      else
      {
        v136 = buf->m_pDataIn;
        v137 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v136 == v137 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v136 + 1;
          v135 = v133;
        }
        else
        {
          if ( v136 <= v137 )
          {
            buf->m_nInBufWord = *v136;
            buf->m_pDataIn = v136 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          v135 = v133;
        }
      }
      goto LABEL_243;
    }
    v138 = buf->m_pBufferEnd;
    v139 = buf->m_nInBufWord;
    v140 = 32 - v132;
    v141 = buf->m_pDataIn;
    if ( v141 == v138 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v141 > v138 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_240;
      }
      buf->m_nInBufWord = *v141;
    }
    buf->m_pDataIn = v141 + 1;
LABEL_240:
    if ( buf->m_bOverflow )
    {
      v135 = 0;
    }
    else
    {
      v142 = buf->m_nInBufWord;
      v143 = (v142 & CBitBuffer::s_nMaskTable[v140]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v140;
      v135 = v143 | v139;
      buf->m_nInBufWord = v142 >> v140;
    }
LABEL_243:
    move->buttons = v135;
  }
  v144 = buf->m_nInBufWord;
  v145 = v144 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v146 = buf->m_pDataIn;
    v147 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v146 == v147 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v146 + 1;
    }
    else if ( v146 <= v147 )
    {
      buf->m_nInBufWord = *v146;
      buf->m_pDataIn = v146 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v144 >> 1;
  }
  if ( v145 != 0 )
  {
    v148 = buf->m_nBitsAvail;
    if ( v148 >= 8 )
    {
      v149 = buf->m_nInBufWord;
      v150 = v149;
      v151 = v148 - 8;
      buf->m_nBitsAvail = v151;
      if ( v151 != 0 )
      {
        buf->m_nInBufWord = v149 >> 8;
      }
      else
      {
        v149 = (unsigned int)buf->m_pDataIn;
        v152 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( (const unsigned int *)v149 == v152 )
        {
          buf->m_pDataIn = (const unsigned int *)(v149 + 4);
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          LOBYTE(v149) = v150;
        }
        else
        {
          if ( v149 <= (unsigned int)v152 )
          {
            v153 = *(_DWORD *)v149;
            buf->m_pDataIn = (const unsigned int *)(v149 + 4);
            buf->m_nInBufWord = v153;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          LOBYTE(v149) = v150;
        }
      }
      goto LABEL_270;
    }
    v154 = buf->m_pBufferEnd;
    v155 = buf->m_nInBufWord;
    v149 = 8 - v148;
    v156 = buf->m_pDataIn;
    if ( v156 == v154 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v156 > v154 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_267;
      }
      buf->m_nInBufWord = *v156;
    }
    buf->m_pDataIn = v156 + 1;
LABEL_267:
    if ( buf->m_bOverflow )
    {
      LOBYTE(v149) = 0;
    }
    else
    {
      v157 = buf->m_nInBufWord;
      v158 = (v157 & CBitBuffer::s_nMaskTable[v149]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v149;
      v159 = v157 >> v149;
      LOBYTE(v149) = v158 | v155;
      buf->m_nInBufWord = v159;
    }
LABEL_270:
    move->impulse = v149;
  }
  v160 = buf->m_nInBufWord;
  v161 = v160 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v162 = buf->m_pDataIn;
    v163 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v162 == v163 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v162 + 1;
    }
    else if ( v162 <= v163 )
    {
      buf->m_nInBufWord = *v162;
      buf->m_pDataIn = v162 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v160 >> 1;
  }
  if ( v161 == 0 )
    goto LABEL_323;
  v164 = buf->m_nBitsAvail;
  if ( v164 < 11 )
  {
    v172 = buf->m_pBufferEnd;
    v173 = buf->m_nInBufWord;
    v174 = 11 - v164;
    v175 = buf->m_pDataIn;
    if ( v175 == v172 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v175 > v172 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_294;
      }
      buf->m_nInBufWord = *v175;
    }
    buf->m_pDataIn = v175 + 1;
LABEL_294:
    if ( buf->m_bOverflow )
    {
      v168 = 0;
    }
    else
    {
      v176 = buf->m_nInBufWord;
      v177 = (v176 & CBitBuffer::s_nMaskTable[v174]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v174;
      v178 = v176 >> v174;
      v168 = v177 | v173;
      buf->m_nInBufWord = v178;
    }
    goto LABEL_297;
  }
  v165 = buf->m_nInBufWord;
  v166 = v165 & 0x7FF;
  v167 = v164 - 11;
  buf->m_nBitsAvail = v167;
  if ( v167 != 0 )
  {
    buf->m_nInBufWord = v165 >> 11;
    v168 = v165 & 0x7FF;
  }
  else
  {
    v169 = buf->m_pDataIn;
    v170 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v169 == v170 )
    {
      buf->m_pDataIn = v169 + 1;
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      v168 = v166;
    }
    else
    {
      if ( v169 <= v170 )
      {
        v171 = *v169;
        buf->m_pDataIn = v169 + 1;
        buf->m_nInBufWord = v171;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
      v168 = v166;
    }
  }
LABEL_297:
  move->weaponselect = v168;
  v179 = buf->m_nInBufWord;
  v180 = v179 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v181 = buf->m_pDataIn;
    v182 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v181 == v182 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v181 + 1;
    }
    else if ( v181 <= v182 )
    {
      buf->m_nInBufWord = *v181;
      buf->m_pDataIn = v181 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v179 >> 1;
  }
  if ( v180 != 0 )
  {
    v183 = buf->m_nBitsAvail;
    if ( v183 >= 6 )
    {
      v184 = buf->m_nInBufWord;
      v185 = v184 & 0x3F;
      v186 = v183 - 6;
      buf->m_nBitsAvail = v186;
      if ( v186 != 0 )
      {
        buf->m_nInBufWord = v184 >> 6;
      }
      else
      {
        v187 = buf->m_pDataIn;
        v188 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v187 == v188 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v187 + 1;
        }
        else if ( v187 <= v188 )
        {
          buf->m_nInBufWord = *v187;
          buf->m_pDataIn = v187 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
LABEL_322:
      move->weaponsubtype = v185;
      goto LABEL_323;
    }
    v189 = buf->m_pBufferEnd;
    v190 = buf->m_nInBufWord;
    v191 = 6 - v183;
    v192 = buf->m_pDataIn;
    if ( v192 == v189 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v192 > v189 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_319;
      }
      buf->m_nInBufWord = *v192;
    }
    buf->m_pDataIn = v192 + 1;
LABEL_319:
    if ( buf->m_bOverflow )
    {
      v185 = 0;
    }
    else
    {
      v193 = buf->m_nInBufWord;
      v194 = (v193 & CBitBuffer::s_nMaskTable[v191]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v191;
      v185 = v194 | v190;
      buf->m_nInBufWord = v193 >> v191;
    }
    goto LABEL_322;
  }
LABEL_323:
  move->random_seed = MD5_PseudoRandom(nSeed: move->command_number) & 0x7FFFFFFF;
  v195 = buf->m_nInBufWord;
  v196 = (unsigned int *)(v195 & 1);
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v197 = buf->m_pDataIn;
    v198 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v197 == v198 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v197 + 1;
    }
    else if ( v197 <= v198 )
    {
      buf->m_nInBufWord = *v197;
      buf->m_pDataIn = v197 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v195 >> 1;
  }
  if ( v196 != nullptr )
  {
    v199 = buf->m_nBitsAvail;
    if ( v199 >= 16 )
    {
      v200 = buf->m_nInBufWord;
      v201 = v200;
      v196 = (unsigned int *)(v199 - 16);
      buf->m_nBitsAvail = (int)v196;
      if ( v196 != nullptr )
      {
        buf->m_nInBufWord = HIWORD(v200);
      }
      else
      {
        v202 = buf->m_pDataIn;
        v196 = (unsigned int *)buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v202 == v196 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v202 + 1;
        }
        else if ( v202 <= v196 )
        {
          v196 = (unsigned int *)*v202;
          buf->m_nInBufWord = *v202;
          buf->m_pDataIn = v202 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
LABEL_348:
      move->mousedx = v201;
      goto LABEL_349;
    }
    v203 = buf->m_pBufferEnd;
    v204 = buf->m_nInBufWord;
    v205 = (unsigned int *)(16 - v199);
    v196 = (unsigned int *)buf->m_pDataIn;
    if ( v196 == v203 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v196 > v203 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_345;
      }
      buf->m_nInBufWord = *v196;
    }
    buf->m_pDataIn = ++v196;
LABEL_345:
    if ( buf->m_bOverflow )
    {
      v201 = 0;
    }
    else
    {
      v206 = buf->m_nInBufWord;
      v207 = (v206 & CBitBuffer::s_nMaskTable[(_DWORD)v205]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - (_DWORD)v205;
      v196 = v205;
      v201 = v207 | v204;
      buf->m_nInBufWord = v206 >> (char)v205;
    }
    goto LABEL_348;
  }
LABEL_349:
  v208 = buf->m_nInBufWord;
  v209 = v208 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v210 = buf->m_pDataIn;
    v196 = (unsigned int *)buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v210 == v196 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v210 + 1;
    }
    else if ( v210 <= v196 )
    {
      v196 = (unsigned int *)*v210;
      buf->m_nInBufWord = *v210;
      buf->m_pDataIn = v210 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v208 >> 1;
  }
  if ( v209 != 0 )
  {
    v211 = buf->m_nBitsAvail;
    if ( v211 >= 16 )
    {
      v212 = buf->m_nInBufWord;
      v213 = v212;
      v196 = (unsigned int *)(v211 - 16);
      buf->m_nBitsAvail = (int)v196;
      if ( v196 != nullptr )
      {
        buf->m_nInBufWord = HIWORD(v212);
      }
      else
      {
        v214 = buf->m_pDataIn;
        v196 = (unsigned int *)buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v214 == v196 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v214 + 1;
        }
        else if ( v214 <= v196 )
        {
          buf->m_nInBufWord = *v214;
          buf->m_pDataIn = v214 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
LABEL_374:
      move->mousedy = v213;
      goto LABEL_375;
    }
    v215 = buf->m_pBufferEnd;
    v216 = buf->m_nInBufWord;
    v217 = (unsigned int *)(16 - v211);
    v196 = (unsigned int *)buf->m_pDataIn;
    if ( v196 == v215 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v196 > v215 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_371;
      }
      buf->m_nInBufWord = *v196;
    }
    buf->m_pDataIn = ++v196;
LABEL_371:
    if ( buf->m_bOverflow )
    {
      v213 = 0;
    }
    else
    {
      v218 = buf->m_nInBufWord;
      v219 = (v218 & CBitBuffer::s_nMaskTable[(_DWORD)v217]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - (_DWORD)v217;
      v196 = v217;
      v213 = v219 | v216;
      buf->m_nInBufWord = v218 >> (char)v217;
    }
    goto LABEL_374;
  }
LABEL_375:
  if ( IsPresetCurrentCostDebuggingEnabled(this: (vgui::ToggleButton *)v196) )
  {
    v220 = buf->m_nInBufWord;
    v221 = v220 & 1;
    v7 = buf->m_nBitsAvail-- == 1;
    if ( v7 )
    {
      v222 = buf->m_pDataIn;
      v223 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v222 == v223 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v222 + 1;
      }
      else if ( v222 <= v223 )
      {
        buf->m_nInBufWord = *v222;
        buf->m_pDataIn = v222 + 1;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    else
    {
      buf->m_nInBufWord = v220 >> 1;
    }
    if ( v221 != 0 )
      move->headangles.x = CBitRead::ReadBitAngle(this: buf, numbits: 16);
    v224 = buf->m_nInBufWord;
    v225 = v224 & 1;
    v7 = buf->m_nBitsAvail-- == 1;
    if ( v7 )
    {
      v226 = buf->m_pDataIn;
      v227 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v226 == v227 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v226 + 1;
      }
      else if ( v226 <= v227 )
      {
        buf->m_nInBufWord = *v226;
        buf->m_pDataIn = v226 + 1;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    else
    {
      buf->m_nInBufWord = v224 >> 1;
    }
    if ( v225 != 0 )
      move->headangles.y = CBitRead::ReadBitAngle(this: buf, numbits: 16);
    v228 = buf->m_nInBufWord;
    v229 = v228 & 1;
    v7 = buf->m_nBitsAvail-- == 1;
    if ( v7 )
    {
      v230 = buf->m_pDataIn;
      v231 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v230 == v231 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v230 + 1;
      }
      else if ( v230 <= v231 )
      {
        buf->m_nInBufWord = *v230;
        buf->m_pDataIn = v230 + 1;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    else
    {
      buf->m_nInBufWord = v228 >> 1;
    }
    if ( v229 != 0 )
      move->headangles.z = CBitRead::ReadBitAngle(this: buf, numbits: 8);
    v232 = buf->m_nInBufWord;
    v233 = v232 & 1;
    v7 = buf->m_nBitsAvail-- == 1;
    if ( v7 )
    {
      v234 = buf->m_pDataIn;
      v235 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v234 == v235 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v234 + 1;
      }
      else if ( v234 <= v235 )
      {
        buf->m_nInBufWord = *v234;
        buf->m_pDataIn = v234 + 1;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    else
    {
      buf->m_nInBufWord = v232 >> 1;
    }
    if ( v233 != 0 )
      CBitRead::ReadBitVec3Coord(this: buf, fa: &move->headoffset);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017BC60
// Name: WriteUserCmdDeltaInt
// Source: json
//------------------------------------------------------------------------------
char __usercall WriteUserCmdDeltaInt@<al>(
        bf_write *buf@<esi>,
        int from@<eax>,
        unsigned int to@<edi>,
        char *what,
        int bits)
{
  int v5; // ecx
  int m_iCurBit; // ecx

  if ( from == to )
  {
    m_iCurBit = buf->m_iCurBit;
    if ( m_iCurBit + 1 > buf->m_nDataBits )
      buf->m_bOverflow = true;
    if ( !buf->m_bOverflow )
    {
      buf->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++buf->m_iCurBit;
    }
    return 0;
  }
  else
  {
    if ( net_showusercmd.m_pParent != nullptr && net_showusercmd.m_pParent->m_Value.m_nValue != 0 )
      _ConDMsg(a1: "\t%s %d -> %d\n", what, from, to);
    v5 = buf->m_iCurBit;
    if ( v5 + 1 > buf->m_nDataBits )
      buf->m_bOverflow = true;
    if ( !buf->m_bOverflow )
    {
      buf->m_pData[v5 >> 3] |= 1 << (v5 & 7);
      ++buf->m_iCurBit;
    }
    bf_write::WriteUBitLong(this: buf, curData: to, numbits: bits, bCheckRange: true);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017BD00
// Name: WriteUserCmdDeltaShort
// Source: json
//------------------------------------------------------------------------------
char __usercall WriteUserCmdDeltaShort@<al>(bf_write *buf@<esi>, int from@<ecx>, int to@<edi>, char *what)
{
  int v4; // ecx
  int m_iCurBit; // ecx

  if ( from == to )
  {
    m_iCurBit = buf->m_iCurBit;
    if ( m_iCurBit + 1 > buf->m_nDataBits )
      buf->m_bOverflow = true;
    if ( !buf->m_bOverflow )
    {
      buf->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++buf->m_iCurBit;
    }
    return 0;
  }
  else
  {
    if ( net_showusercmd.m_pParent != nullptr && net_showusercmd.m_pParent->m_Value.m_nValue != 0 )
      _ConDMsg(a1: "\t%s %d -> %d\n", what, from, to);
    v4 = buf->m_iCurBit;
    if ( v4 + 1 > buf->m_nDataBits )
      buf->m_bOverflow = true;
    if ( !buf->m_bOverflow )
    {
      buf->m_pData[v4 >> 3] |= 1 << (v4 & 7);
      ++buf->m_iCurBit;
    }
    bf_write::WriteShort(this: buf, val: to);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017BD90
// Name: WriteUserCmdDeltaFloat
// Source: json
//------------------------------------------------------------------------------
char __usercall WriteUserCmdDeltaFloat@<al>(bf_write *buf@<esi>, float a2@<xmm1>, char *what, float to)
{
  float val; // xmm0_4
  int v6; // ecx
  int m_iCurBit; // ecx

  val = to;
  if ( a2 == to )
  {
    m_iCurBit = buf->m_iCurBit;
    if ( m_iCurBit + 1 > buf->m_nDataBits )
      buf->m_bOverflow = true;
    if ( !buf->m_bOverflow )
    {
      buf->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++buf->m_iCurBit;
    }
    return 0;
  }
  else
  {
    if ( net_showusercmd.m_pParent != nullptr && net_showusercmd.m_pParent->m_Value.m_nValue != 0 )
    {
      _ConDMsg(a1: "\t%s %2.2f -> %2.2f\n", what, a2, to);
      val = to;
    }
    v6 = buf->m_iCurBit;
    if ( v6 + 1 > buf->m_nDataBits )
      buf->m_bOverflow = true;
    if ( !buf->m_bOverflow )
    {
      buf->m_pData[v6 >> 3] |= 1 << (v6 & 7);
      ++buf->m_iCurBit;
    }
    bf_write::WriteFloat(this: buf, val);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017BE50
// Name: WriteUserCmdDeltaAngle
// Source: json
//------------------------------------------------------------------------------
char __usercall WriteUserCmdDeltaAngle@<al>(bf_write *buf@<esi>, float a2@<xmm1>, char *what, float to, int bits)
{
  float fAngle; // xmm0_4
  int v7; // ecx
  int m_iCurBit; // ecx

  fAngle = to;
  if ( a2 == to )
  {
    m_iCurBit = buf->m_iCurBit;
    if ( m_iCurBit + 1 > buf->m_nDataBits )
      buf->m_bOverflow = true;
    if ( !buf->m_bOverflow )
    {
      buf->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++buf->m_iCurBit;
    }
    return 0;
  }
  else
  {
    if ( net_showusercmd.m_pParent != nullptr && net_showusercmd.m_pParent->m_Value.m_nValue != 0 )
    {
      _ConDMsg(a1: "\t%s %2.2f -> %2.2f\n", what, a2, to);
      fAngle = to;
    }
    v7 = buf->m_iCurBit;
    if ( v7 + 1 > buf->m_nDataBits )
      buf->m_bOverflow = true;
    if ( !buf->m_bOverflow )
    {
      buf->m_pData[v7 >> 3] |= 1 << (v7 & 7);
      ++buf->m_iCurBit;
    }
    bf_write::WriteBitAngle(this: buf, fAngle, numbits: bits);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017BF10
// Name: WriteUserCmdDeltaVec3Coord
// Source: json
//------------------------------------------------------------------------------
char __usercall WriteUserCmdDeltaVec3Coord@<al>(
        bf_write *buf@<esi>,
        const Vector *from@<ecx>,
        const Vector *to@<edi>,
        char *what)
{
  int v4; // ecx
  int m_iCurBit; // ecx

  if ( to->x == from->x && to->y == from->y && to->z == from->z )
  {
    m_iCurBit = buf->m_iCurBit;
    if ( m_iCurBit + 1 > buf->m_nDataBits )
      buf->m_bOverflow = true;
    if ( !buf->m_bOverflow )
    {
      buf->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
      ++buf->m_iCurBit;
    }
    return 0;
  }
  else
  {
    if ( net_showusercmd.m_pParent != nullptr && net_showusercmd.m_pParent->m_Value.m_nValue != 0 )
      _ConDMsg(a1: "\t%s %2.2f -> %2.2f\n", what, from->x, to->x);
    v4 = buf->m_iCurBit;
    if ( v4 + 1 > buf->m_nDataBits )
      buf->m_bOverflow = true;
    if ( !buf->m_bOverflow )
    {
      buf->m_pData[v4 >> 3] |= 1 << (v4 & 7);
      ++buf->m_iCurBit;
    }
    bf_write::WriteBitVec3Coord(this: buf, fa: to);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017BFE0
// Name: void WriteUsercmd(class bf_write __near *,class CUserCmd const __near *,class CUserCmd const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteUsercmd(bf_write *buf, const CUserCmd *to, const CUserCmd *from)
{
  vgui::ToggleButton *v3; // ecx

  if ( net_showusercmd.m_pParent != nullptr && net_showusercmd.m_pParent->m_Value.m_nValue != 0 )
    _ConDMsg(a1: "WriteUsercmd: from=%d to=%d\n", from->command_number, to->command_number);
  WriteUserCmdDeltaInt(buf, from: from->command_number + 1, to: to->command_number, what: "command_number", bits: 32);
  WriteUserCmdDeltaInt(buf, from: from->tick_count + 1, to: to->tick_count, what: "tick_count", bits: 32);
  WriteUserCmdDeltaFloat(buf, a2: from->viewangles.x, what: "viewangles[0]", to: to->viewangles.x);
  WriteUserCmdDeltaFloat(buf, a2: from->viewangles.y, what: "viewangles[1]", to: to->viewangles.y);
  WriteUserCmdDeltaFloat(buf, a2: from->viewangles.z, what: "viewangles[2]", to: to->viewangles.z);
  WriteUserCmdDeltaFloat(buf, a2: from->forwardmove, what: "forwardmove", to: to->forwardmove);
  WriteUserCmdDeltaFloat(buf, a2: from->sidemove, what: "sidemove", to: to->sidemove);
  WriteUserCmdDeltaFloat(buf, a2: from->upmove, what: "upmove", to: to->upmove);
  WriteUserCmdDeltaInt(buf, from: from->buttons, to: to->buttons, what: "buttons", bits: 32);
  WriteUserCmdDeltaInt(buf, from: from->impulse, to: to->impulse, what: "impulse", bits: 8);
  if ( WriteUserCmdDeltaInt(buf, from: from->weaponselect, to: to->weaponselect, what: "weaponselect", bits: 11) != 0 )
    WriteUserCmdDeltaInt(buf, from: from->weaponsubtype, to: to->weaponsubtype, what: "weaponsubtype", bits: 6);
  WriteUserCmdDeltaShort(buf, from: from->mousedx, to: to->mousedx, what: "mousedx");
  WriteUserCmdDeltaShort(buf, from: from->mousedy, to: to->mousedy, what: "mousedy");
  if ( IsPresetCurrentCostDebuggingEnabled(this: v3) )
  {
    WriteUserCmdDeltaAngle(buf, a2: from->headangles.x, what: "headangles[0]", to: to->headangles.x, bits: 16);
    WriteUserCmdDeltaAngle(buf, a2: from->headangles.y, what: "headangles[1]", to: to->headangles.y, bits: 16);
    WriteUserCmdDeltaAngle(buf, a2: from->headangles.z, what: "headangles[2]", to: to->headangles.z, bits: 8);
    WriteUserCmdDeltaVec3Coord(buf, from: &from->headoffset, to: &to->headoffset, what: "headoffset");
  }
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10249AC0
// Name: void ReadUsercmd(class bf_read __near *,class CUserCmd __near *,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReadUsercmd(bf_read *buf, CUserCmd *move, CUserCmd *from)
{
  CUserCmd *v3; // ebx
  unsigned int m_nInBufWord; // eax
  int v6; // ecx
  bool v7; // zf
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // edx
  int m_nBitsAvail; // ecx
  unsigned int v11; // eax
  const unsigned int *v12; // ecx
  const unsigned int *v13; // edx
  CUserCmd *v14; // edx
  const unsigned int *v15; // edx
  unsigned int v16; // edi
  int v17; // eax
  const unsigned int *v18; // ecx
  unsigned int v19; // edx
  unsigned int v20; // ebx
  int v21; // edi
  unsigned int v22; // eax
  int v23; // edx
  const unsigned int *v24; // eax
  const unsigned int *v25; // ecx
  int v26; // ecx
  unsigned int v27; // eax
  int v28; // ecx
  const unsigned int *v29; // ecx
  const unsigned int *v30; // edx
  CUserCmd *v31; // edx
  const unsigned int *v32; // edx
  unsigned int v33; // edi
  int v34; // eax
  const unsigned int *v35; // ecx
  unsigned int v36; // edx
  unsigned int v37; // ebx
  unsigned int v38; // eax
  int v39; // edx
  const unsigned int *v40; // eax
  const unsigned int *v41; // ecx
  int v42; // ecx
  unsigned int v43; // eax
  int v44; // ecx
  const unsigned int *v45; // ecx
  const unsigned int *v46; // edx
  const unsigned int *v47; // edx
  unsigned int v48; // edi
  int v49; // eax
  const unsigned int *v50; // ecx
  unsigned int v51; // edx
  unsigned int v52; // ebx
  unsigned int v53; // eax
  int v54; // edx
  const unsigned int *v55; // eax
  const unsigned int *v56; // ecx
  int v57; // ecx
  unsigned int v58; // eax
  int v59; // ecx
  const unsigned int *v60; // ecx
  const unsigned int *v61; // edx
  const unsigned int *v62; // edx
  unsigned int v63; // edi
  int v64; // eax
  const unsigned int *v65; // ecx
  unsigned int v66; // edx
  unsigned int v67; // ebx
  unsigned int v68; // eax
  int v69; // edx
  const unsigned int *v70; // eax
  const unsigned int *v71; // ecx
  int v72; // ecx
  unsigned int v73; // eax
  int v74; // ecx
  const unsigned int *v75; // ecx
  const unsigned int *v76; // edx
  const unsigned int *v77; // edx
  unsigned int v78; // edi
  int v79; // eax
  const unsigned int *v80; // ecx
  unsigned int v81; // edx
  unsigned int v82; // ebx
  unsigned int v83; // eax
  int v84; // edx
  const unsigned int *v85; // eax
  const unsigned int *v86; // ecx
  int v87; // ecx
  unsigned int v88; // eax
  int v89; // ecx
  const unsigned int *v90; // ecx
  const unsigned int *v91; // edx
  const unsigned int *v92; // edx
  unsigned int v93; // edi
  int v94; // eax
  const unsigned int *v95; // ecx
  unsigned int v96; // edx
  unsigned int v97; // ebx
  unsigned int v98; // eax
  int v99; // edx
  const unsigned int *v100; // eax
  const unsigned int *v101; // ecx
  int v102; // ecx
  unsigned int v103; // eax
  int v104; // ecx
  const unsigned int *v105; // ecx
  const unsigned int *v106; // edx
  const unsigned int *v107; // edx
  unsigned int v108; // edi
  int v109; // eax
  const unsigned int *v110; // ecx
  unsigned int v111; // edx
  unsigned int v112; // ebx
  unsigned int v113; // eax
  int v114; // edx
  const unsigned int *v115; // eax
  const unsigned int *v116; // ecx
  int v117; // ecx
  unsigned int v118; // eax
  int v119; // ecx
  const unsigned int *v120; // ecx
  const unsigned int *v121; // edx
  const unsigned int *v122; // edx
  unsigned int v123; // edi
  int v124; // eax
  const unsigned int *v125; // ecx
  unsigned int v126; // edx
  unsigned int v127; // ebx
  unsigned int v128; // eax
  int v129; // edx
  const unsigned int *v130; // eax
  const unsigned int *v131; // ecx
  int v132; // ecx
  unsigned int v133; // eax
  int v134; // ecx
  int v135; // edi
  const unsigned int *v136; // ecx
  const unsigned int *v137; // edx
  const unsigned int *v138; // edx
  unsigned int v139; // edi
  int v140; // eax
  const unsigned int *v141; // ecx
  unsigned int v142; // edx
  unsigned int v143; // ebx
  unsigned int v144; // eax
  int v145; // edx
  const unsigned int *v146; // eax
  const unsigned int *v147; // ecx
  int v148; // ecx
  unsigned int v149; // eax
  char v150; // dl
  int v151; // ecx
  const unsigned int *v152; // ecx
  unsigned int v153; // ecx
  const unsigned int *v154; // edx
  unsigned int v155; // edi
  const unsigned int *v156; // ecx
  unsigned int v157; // edx
  unsigned int v158; // ebx
  unsigned int v159; // edx
  unsigned int v160; // eax
  int v161; // edx
  const unsigned int *v162; // eax
  const unsigned int *v163; // ecx
  int v164; // ecx
  unsigned int v165; // eax
  int v166; // edx
  int v167; // ecx
  int v168; // eax
  const unsigned int *v169; // eax
  const unsigned int *v170; // ecx
  unsigned int v171; // ecx
  const unsigned int *v172; // edx
  unsigned int v173; // edi
  int v174; // eax
  const unsigned int *v175; // ecx
  unsigned int v176; // edx
  unsigned int v177; // ebx
  unsigned int v178; // edx
  unsigned int v179; // eax
  int v180; // ecx
  const unsigned int *v181; // eax
  const unsigned int *v182; // edx
  int v183; // ecx
  unsigned int v184; // eax
  int v185; // edi
  int v186; // ecx
  const unsigned int *v187; // eax
  const unsigned int *v188; // ecx
  const unsigned int *v189; // edx
  unsigned int v190; // edi
  int v191; // eax
  const unsigned int *v192; // ecx
  unsigned int v193; // edx
  unsigned int v194; // ebx
  unsigned int v195; // eax
  unsigned int *v196; // ecx
  const unsigned int *v197; // eax
  const unsigned int *v198; // edx
  int v199; // ecx
  unsigned int v200; // eax
  __int16 v201; // di
  const unsigned int *v202; // eax
  const unsigned int *v203; // edx
  unsigned int v204; // edi
  unsigned int *v205; // eax
  unsigned int v206; // edx
  unsigned int v207; // ebx
  unsigned int v208; // eax
  int v209; // edx
  const unsigned int *v210; // eax
  int v211; // ecx
  unsigned int v212; // eax
  __int16 v213; // di
  const unsigned int *v214; // eax
  const unsigned int *v215; // edx
  unsigned int v216; // edi
  unsigned int *v217; // eax
  unsigned int v218; // edx
  unsigned int v219; // ebx
  unsigned int v220; // eax
  int v221; // edx
  const unsigned int *v222; // eax
  const unsigned int *v223; // ecx
  unsigned int v224; // eax
  int v225; // edx
  const unsigned int *v226; // eax
  const unsigned int *v227; // ecx
  unsigned int v228; // eax
  int v229; // edx
  const unsigned int *v230; // eax
  const unsigned int *v231; // ecx
  unsigned int v232; // eax
  int v233; // edx
  const unsigned int *v234; // eax
  const unsigned int *v235; // ecx
  bf_read *bufa; // [esp+14h] [ebp+8h]
  bf_read *bufb; // [esp+14h] [ebp+8h]
  bf_read *bufc; // [esp+14h] [ebp+8h]
  bf_read *bufd; // [esp+14h] [ebp+8h]
  bf_read *bufe; // [esp+14h] [ebp+8h]
  bf_read *buff; // [esp+14h] [ebp+8h]

  v3 = from;
  CUserCmd::operator=(this: move, src: from);
  m_nInBufWord = buf->m_nInBufWord;
  v6 = m_nInBufWord & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    m_pDataIn = buf->m_pDataIn;
    m_pBufferEnd = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      buf->m_nInBufWord = *m_pDataIn;
      buf->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = m_nInBufWord >> 1;
  }
  if ( v6 == 0 )
  {
    move->command_number = from->command_number + 1;
    goto LABEL_28;
  }
  m_nBitsAvail = buf->m_nBitsAvail;
  if ( m_nBitsAvail < 32 )
  {
    v15 = buf->m_pBufferEnd;
    v16 = buf->m_nInBufWord;
    v17 = 32 - m_nBitsAvail;
    v18 = buf->m_pDataIn;
    if ( v18 == v15 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v18 > v15 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_24;
      }
      buf->m_nInBufWord = *v18;
    }
    buf->m_pDataIn = v18 + 1;
LABEL_24:
    if ( buf->m_bOverflow )
    {
      move->command_number = 0;
    }
    else
    {
      v19 = buf->m_nInBufWord;
      v20 = (v19 & CBitBuffer::s_nMaskTable[v17]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v17;
      v21 = v20 | v16;
      v3 = from;
      buf->m_nInBufWord = v19 >> v17;
      move->command_number = v21;
    }
    goto LABEL_28;
  }
  v11 = buf->m_nInBufWord;
  buf->m_nBitsAvail = m_nBitsAvail - 32;
  if ( m_nBitsAvail == 32 )
  {
    v12 = buf->m_pDataIn;
    v13 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v12 == v13 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v12 + 1;
      move->command_number = v11;
    }
    else
    {
      if ( v12 <= v13 )
      {
        buf->m_nInBufWord = *v12;
        v14 = move;
        buf->m_pDataIn = v12 + 1;
      }
      else
      {
        v14 = move;
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
      v14->command_number = v11;
    }
  }
  else
  {
    buf->m_nInBufWord = 0;
    move->command_number = v11;
  }
LABEL_28:
  v22 = buf->m_nInBufWord;
  v23 = v22 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v24 = buf->m_pDataIn;
    v25 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v24 == v25 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v24 + 1;
    }
    else if ( v24 <= v25 )
    {
      buf->m_nInBufWord = *v24;
      buf->m_pDataIn = v24 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v22 >> 1;
  }
  if ( v23 == 0 )
  {
    move->tick_count = v3->tick_count + 1;
    goto LABEL_55;
  }
  v26 = buf->m_nBitsAvail;
  if ( v26 < 32 )
  {
    v32 = buf->m_pBufferEnd;
    v33 = buf->m_nInBufWord;
    v34 = 32 - v26;
    v35 = buf->m_pDataIn;
    if ( v35 == v32 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v35 > v32 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_51;
      }
      buf->m_nInBufWord = *v35;
    }
    buf->m_pDataIn = v35 + 1;
LABEL_51:
    if ( buf->m_bOverflow )
    {
      move->tick_count = 0;
    }
    else
    {
      v36 = buf->m_nInBufWord;
      v37 = (v36 & CBitBuffer::s_nMaskTable[v34]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v34;
      buf->m_nInBufWord = v36 >> v34;
      move->tick_count = v37 | v33;
    }
    goto LABEL_55;
  }
  v27 = buf->m_nInBufWord;
  v28 = v26 - 32;
  buf->m_nBitsAvail = v28;
  if ( v28 != 0 )
  {
    buf->m_nInBufWord = 0;
    move->tick_count = v27;
  }
  else
  {
    v29 = buf->m_pDataIn;
    v30 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v29 == v30 )
    {
      buf->m_nInBufWord = 0;
      buf->m_nBitsAvail = 1;
      buf->m_pDataIn = v29 + 1;
      move->tick_count = v27;
    }
    else
    {
      if ( v29 <= v30 )
      {
        buf->m_nInBufWord = *v29;
        v31 = move;
        buf->m_pDataIn = v29 + 1;
      }
      else
      {
        v31 = move;
        buf->m_nInBufWord = 0;
        buf->m_bOverflow = true;
      }
      v31->tick_count = v27;
    }
  }
LABEL_55:
  v38 = buf->m_nInBufWord;
  v39 = v38 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v40 = buf->m_pDataIn;
    v41 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v40 == v41 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v40 + 1;
    }
    else if ( v40 <= v41 )
    {
      buf->m_nInBufWord = *v40;
      buf->m_pDataIn = v40 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v38 >> 1;
  }
  if ( v39 != 0 )
  {
    v42 = buf->m_nBitsAvail;
    if ( v42 >= 32 )
    {
      v43 = buf->m_nInBufWord;
      v44 = v42 - 32;
      buf->m_nBitsAvail = v44;
      if ( v44 != 0 )
      {
        buf->m_nInBufWord = 0;
        bufa = (bf_read *)v43;
      }
      else
      {
        v45 = buf->m_pDataIn;
        v46 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v45 == v46 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v45 + 1;
          bufa = (bf_read *)v43;
        }
        else
        {
          if ( v45 <= v46 )
          {
            buf->m_nInBufWord = *v45;
            buf->m_pDataIn = v45 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          bufa = (bf_read *)v43;
        }
      }
      goto LABEL_81;
    }
    v47 = buf->m_pBufferEnd;
    v48 = buf->m_nInBufWord;
    v49 = 32 - v42;
    v50 = buf->m_pDataIn;
    if ( v50 == v47 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v50 > v47 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_78;
      }
      buf->m_nInBufWord = *v50;
    }
    buf->m_pDataIn = v50 + 1;
LABEL_78:
    if ( buf->m_bOverflow )
    {
      bufa = nullptr;
    }
    else
    {
      v51 = buf->m_nInBufWord;
      v52 = (v51 & CBitBuffer::s_nMaskTable[v49]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v49;
      bufa = (bf_read *)(v52 | v48);
      buf->m_nInBufWord = v51 >> v49;
    }
LABEL_81:
    LODWORD(move->viewangles.x) = bufa;
  }
  v53 = buf->m_nInBufWord;
  v54 = v53 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v55 = buf->m_pDataIn;
    v56 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v55 == v56 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v55 + 1;
    }
    else if ( v55 <= v56 )
    {
      buf->m_nInBufWord = *v55;
      buf->m_pDataIn = v55 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v53 >> 1;
  }
  if ( v54 != 0 )
  {
    v57 = buf->m_nBitsAvail;
    if ( v57 >= 32 )
    {
      v58 = buf->m_nInBufWord;
      v59 = v57 - 32;
      buf->m_nBitsAvail = v59;
      if ( v59 != 0 )
      {
        buf->m_nInBufWord = 0;
        bufb = (bf_read *)v58;
      }
      else
      {
        v60 = buf->m_pDataIn;
        v61 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v60 == v61 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v60 + 1;
          bufb = (bf_read *)v58;
        }
        else
        {
          if ( v60 <= v61 )
          {
            buf->m_nInBufWord = *v60;
            buf->m_pDataIn = v60 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          bufb = (bf_read *)v58;
        }
      }
      goto LABEL_108;
    }
    v62 = buf->m_pBufferEnd;
    v63 = buf->m_nInBufWord;
    v64 = 32 - v57;
    v65 = buf->m_pDataIn;
    if ( v65 == v62 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v65 > v62 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_105;
      }
      buf->m_nInBufWord = *v65;
    }
    buf->m_pDataIn = v65 + 1;
LABEL_105:
    if ( buf->m_bOverflow )
    {
      bufb = nullptr;
    }
    else
    {
      v66 = buf->m_nInBufWord;
      v67 = (v66 & CBitBuffer::s_nMaskTable[v64]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v64;
      bufb = (bf_read *)(v67 | v63);
      buf->m_nInBufWord = v66 >> v64;
    }
LABEL_108:
    LODWORD(move->viewangles.y) = bufb;
  }
  v68 = buf->m_nInBufWord;
  v69 = v68 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v70 = buf->m_pDataIn;
    v71 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v70 == v71 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v70 + 1;
    }
    else if ( v70 <= v71 )
    {
      buf->m_nInBufWord = *v70;
      buf->m_pDataIn = v70 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v68 >> 1;
  }
  if ( v69 != 0 )
  {
    v72 = buf->m_nBitsAvail;
    if ( v72 >= 32 )
    {
      v73 = buf->m_nInBufWord;
      v74 = v72 - 32;
      buf->m_nBitsAvail = v74;
      if ( v74 != 0 )
      {
        buf->m_nInBufWord = 0;
        bufc = (bf_read *)v73;
      }
      else
      {
        v75 = buf->m_pDataIn;
        v76 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v75 == v76 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v75 + 1;
          bufc = (bf_read *)v73;
        }
        else
        {
          if ( v75 <= v76 )
          {
            buf->m_nInBufWord = *v75;
            buf->m_pDataIn = v75 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          bufc = (bf_read *)v73;
        }
      }
      goto LABEL_135;
    }
    v77 = buf->m_pBufferEnd;
    v78 = buf->m_nInBufWord;
    v79 = 32 - v72;
    v80 = buf->m_pDataIn;
    if ( v80 == v77 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v80 > v77 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_132;
      }
      buf->m_nInBufWord = *v80;
    }
    buf->m_pDataIn = v80 + 1;
LABEL_132:
    if ( buf->m_bOverflow )
    {
      bufc = nullptr;
    }
    else
    {
      v81 = buf->m_nInBufWord;
      v82 = (v81 & CBitBuffer::s_nMaskTable[v79]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v79;
      bufc = (bf_read *)(v82 | v78);
      buf->m_nInBufWord = v81 >> v79;
    }
LABEL_135:
    LODWORD(move->viewangles.z) = bufc;
  }
  v83 = buf->m_nInBufWord;
  v84 = v83 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v85 = buf->m_pDataIn;
    v86 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v85 == v86 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v85 + 1;
    }
    else if ( v85 <= v86 )
    {
      buf->m_nInBufWord = *v85;
      buf->m_pDataIn = v85 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v83 >> 1;
  }
  if ( v84 != 0 )
  {
    v87 = buf->m_nBitsAvail;
    if ( v87 >= 32 )
    {
      v88 = buf->m_nInBufWord;
      v89 = v87 - 32;
      buf->m_nBitsAvail = v89;
      if ( v89 != 0 )
      {
        buf->m_nInBufWord = 0;
        bufd = (bf_read *)v88;
      }
      else
      {
        v90 = buf->m_pDataIn;
        v91 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v90 == v91 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v90 + 1;
          bufd = (bf_read *)v88;
        }
        else
        {
          if ( v90 <= v91 )
          {
            buf->m_nInBufWord = *v90;
            buf->m_pDataIn = v90 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          bufd = (bf_read *)v88;
        }
      }
      goto LABEL_162;
    }
    v92 = buf->m_pBufferEnd;
    v93 = buf->m_nInBufWord;
    v94 = 32 - v87;
    v95 = buf->m_pDataIn;
    if ( v95 == v92 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v95 > v92 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_159;
      }
      buf->m_nInBufWord = *v95;
    }
    buf->m_pDataIn = v95 + 1;
LABEL_159:
    if ( buf->m_bOverflow )
    {
      bufd = nullptr;
    }
    else
    {
      v96 = buf->m_nInBufWord;
      v97 = (v96 & CBitBuffer::s_nMaskTable[v94]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v94;
      bufd = (bf_read *)(v97 | v93);
      buf->m_nInBufWord = v96 >> v94;
    }
LABEL_162:
    LODWORD(move->forwardmove) = bufd;
  }
  v98 = buf->m_nInBufWord;
  v99 = v98 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v100 = buf->m_pDataIn;
    v101 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v100 == v101 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v100 + 1;
    }
    else if ( v100 <= v101 )
    {
      buf->m_nInBufWord = *v100;
      buf->m_pDataIn = v100 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v98 >> 1;
  }
  if ( v99 != 0 )
  {
    v102 = buf->m_nBitsAvail;
    if ( v102 >= 32 )
    {
      v103 = buf->m_nInBufWord;
      v104 = v102 - 32;
      buf->m_nBitsAvail = v104;
      if ( v104 != 0 )
      {
        buf->m_nInBufWord = 0;
        bufe = (bf_read *)v103;
      }
      else
      {
        v105 = buf->m_pDataIn;
        v106 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v105 == v106 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v105 + 1;
          bufe = (bf_read *)v103;
        }
        else
        {
          if ( v105 <= v106 )
          {
            buf->m_nInBufWord = *v105;
            buf->m_pDataIn = v105 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          bufe = (bf_read *)v103;
        }
      }
      goto LABEL_189;
    }
    v107 = buf->m_pBufferEnd;
    v108 = buf->m_nInBufWord;
    v109 = 32 - v102;
    v110 = buf->m_pDataIn;
    if ( v110 == v107 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v110 > v107 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_186;
      }
      buf->m_nInBufWord = *v110;
    }
    buf->m_pDataIn = v110 + 1;
LABEL_186:
    if ( buf->m_bOverflow )
    {
      bufe = nullptr;
    }
    else
    {
      v111 = buf->m_nInBufWord;
      v112 = (v111 & CBitBuffer::s_nMaskTable[v109]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v109;
      bufe = (bf_read *)(v112 | v108);
      buf->m_nInBufWord = v111 >> v109;
    }
LABEL_189:
    LODWORD(move->sidemove) = bufe;
  }
  v113 = buf->m_nInBufWord;
  v114 = v113 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v115 = buf->m_pDataIn;
    v116 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v115 == v116 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v115 + 1;
    }
    else if ( v115 <= v116 )
    {
      buf->m_nInBufWord = *v115;
      buf->m_pDataIn = v115 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v113 >> 1;
  }
  if ( v114 != 0 )
  {
    v117 = buf->m_nBitsAvail;
    if ( v117 >= 32 )
    {
      v118 = buf->m_nInBufWord;
      v119 = v117 - 32;
      buf->m_nBitsAvail = v119;
      if ( v119 != 0 )
      {
        buf->m_nInBufWord = 0;
        buff = (bf_read *)v118;
      }
      else
      {
        v120 = buf->m_pDataIn;
        v121 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v120 == v121 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v120 + 1;
          buff = (bf_read *)v118;
        }
        else
        {
          if ( v120 <= v121 )
          {
            buf->m_nInBufWord = *v120;
            buf->m_pDataIn = v120 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          buff = (bf_read *)v118;
        }
      }
      goto LABEL_216;
    }
    v122 = buf->m_pBufferEnd;
    v123 = buf->m_nInBufWord;
    v124 = 32 - v117;
    v125 = buf->m_pDataIn;
    if ( v125 == v122 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v125 > v122 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_213;
      }
      buf->m_nInBufWord = *v125;
    }
    buf->m_pDataIn = v125 + 1;
LABEL_213:
    if ( buf->m_bOverflow )
    {
      buff = nullptr;
    }
    else
    {
      v126 = buf->m_nInBufWord;
      v127 = (v126 & CBitBuffer::s_nMaskTable[v124]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v124;
      buff = (bf_read *)(v127 | v123);
      buf->m_nInBufWord = v126 >> v124;
    }
LABEL_216:
    LODWORD(move->upmove) = buff;
  }
  v128 = buf->m_nInBufWord;
  v129 = v128 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v130 = buf->m_pDataIn;
    v131 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v130 == v131 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v130 + 1;
    }
    else if ( v130 <= v131 )
    {
      buf->m_nInBufWord = *v130;
      buf->m_pDataIn = v130 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v128 >> 1;
  }
  if ( v129 != 0 )
  {
    v132 = buf->m_nBitsAvail;
    if ( v132 >= 32 )
    {
      v133 = buf->m_nInBufWord;
      v134 = v132 - 32;
      buf->m_nBitsAvail = v134;
      if ( v134 != 0 )
      {
        buf->m_nInBufWord = 0;
        v135 = v133;
      }
      else
      {
        v136 = buf->m_pDataIn;
        v137 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v136 == v137 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v136 + 1;
          v135 = v133;
        }
        else
        {
          if ( v136 <= v137 )
          {
            buf->m_nInBufWord = *v136;
            buf->m_pDataIn = v136 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          v135 = v133;
        }
      }
      goto LABEL_243;
    }
    v138 = buf->m_pBufferEnd;
    v139 = buf->m_nInBufWord;
    v140 = 32 - v132;
    v141 = buf->m_pDataIn;
    if ( v141 == v138 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v141 > v138 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_240;
      }
      buf->m_nInBufWord = *v141;
    }
    buf->m_pDataIn = v141 + 1;
LABEL_240:
    if ( buf->m_bOverflow )
    {
      v135 = 0;
    }
    else
    {
      v142 = buf->m_nInBufWord;
      v143 = (v142 & CBitBuffer::s_nMaskTable[v140]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v140;
      v135 = v143 | v139;
      buf->m_nInBufWord = v142 >> v140;
    }
LABEL_243:
    move->buttons = v135;
  }
  v144 = buf->m_nInBufWord;
  v145 = v144 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v146 = buf->m_pDataIn;
    v147 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v146 == v147 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v146 + 1;
    }
    else if ( v146 <= v147 )
    {
      buf->m_nInBufWord = *v146;
      buf->m_pDataIn = v146 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v144 >> 1;
  }
  if ( v145 != 0 )
  {
    v148 = buf->m_nBitsAvail;
    if ( v148 >= 8 )
    {
      v149 = buf->m_nInBufWord;
      v150 = v149;
      v151 = v148 - 8;
      buf->m_nBitsAvail = v151;
      if ( v151 != 0 )
      {
        buf->m_nInBufWord = v149 >> 8;
      }
      else
      {
        v149 = (unsigned int)buf->m_pDataIn;
        v152 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( (const unsigned int *)v149 == v152 )
        {
          buf->m_pDataIn = (const unsigned int *)(v149 + 4);
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          LOBYTE(v149) = v150;
        }
        else
        {
          if ( v149 <= (unsigned int)v152 )
          {
            v153 = *(_DWORD *)v149;
            buf->m_pDataIn = (const unsigned int *)(v149 + 4);
            buf->m_nInBufWord = v153;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
          LOBYTE(v149) = v150;
        }
      }
      goto LABEL_270;
    }
    v154 = buf->m_pBufferEnd;
    v155 = buf->m_nInBufWord;
    v149 = 8 - v148;
    v156 = buf->m_pDataIn;
    if ( v156 == v154 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v156 > v154 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_267;
      }
      buf->m_nInBufWord = *v156;
    }
    buf->m_pDataIn = v156 + 1;
LABEL_267:
    if ( buf->m_bOverflow )
    {
      LOBYTE(v149) = 0;
    }
    else
    {
      v157 = buf->m_nInBufWord;
      v158 = (v157 & CBitBuffer::s_nMaskTable[v149]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v149;
      v159 = v157 >> v149;
      LOBYTE(v149) = v158 | v155;
      buf->m_nInBufWord = v159;
    }
LABEL_270:
    move->impulse = v149;
  }
  v160 = buf->m_nInBufWord;
  v161 = v160 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v162 = buf->m_pDataIn;
    v163 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v162 == v163 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v162 + 1;
    }
    else if ( v162 <= v163 )
    {
      buf->m_nInBufWord = *v162;
      buf->m_pDataIn = v162 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v160 >> 1;
  }
  if ( v161 == 0 )
    goto LABEL_323;
  v164 = buf->m_nBitsAvail;
  if ( v164 < 11 )
  {
    v172 = buf->m_pBufferEnd;
    v173 = buf->m_nInBufWord;
    v174 = 11 - v164;
    v175 = buf->m_pDataIn;
    if ( v175 == v172 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v175 > v172 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_294;
      }
      buf->m_nInBufWord = *v175;
    }
    buf->m_pDataIn = v175 + 1;
LABEL_294:
    if ( buf->m_bOverflow )
    {
      v168 = 0;
    }
    else
    {
      v176 = buf->m_nInBufWord;
      v177 = (v176 & CBitBuffer::s_nMaskTable[v174]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v174;
      v178 = v176 >> v174;
      v168 = v177 | v173;
      buf->m_nInBufWord = v178;
    }
    goto LABEL_297;
  }
  v165 = buf->m_nInBufWord;
  v166 = v165 & 0x7FF;
  v167 = v164 - 11;
  buf->m_nBitsAvail = v167;
  if ( v167 != 0 )
  {
    buf->m_nInBufWord = v165 >> 11;
    v168 = v165 & 0x7FF;
  }
  else
  {
    v169 = buf->m_pDataIn;
    v170 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v169 == v170 )
    {
      buf->m_pDataIn = v169 + 1;
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      v168 = v166;
    }
    else
    {
      if ( v169 <= v170 )
      {
        v171 = *v169;
        buf->m_pDataIn = v169 + 1;
        buf->m_nInBufWord = v171;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
      v168 = v166;
    }
  }
LABEL_297:
  move->weaponselect = v168;
  v179 = buf->m_nInBufWord;
  v180 = v179 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v181 = buf->m_pDataIn;
    v182 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v181 == v182 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v181 + 1;
    }
    else if ( v181 <= v182 )
    {
      buf->m_nInBufWord = *v181;
      buf->m_pDataIn = v181 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v179 >> 1;
  }
  if ( v180 != 0 )
  {
    v183 = buf->m_nBitsAvail;
    if ( v183 >= 6 )
    {
      v184 = buf->m_nInBufWord;
      v185 = v184 & 0x3F;
      v186 = v183 - 6;
      buf->m_nBitsAvail = v186;
      if ( v186 != 0 )
      {
        buf->m_nInBufWord = v184 >> 6;
      }
      else
      {
        v187 = buf->m_pDataIn;
        v188 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v187 == v188 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v187 + 1;
        }
        else if ( v187 <= v188 )
        {
          buf->m_nInBufWord = *v187;
          buf->m_pDataIn = v187 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
LABEL_322:
      move->weaponsubtype = v185;
      goto LABEL_323;
    }
    v189 = buf->m_pBufferEnd;
    v190 = buf->m_nInBufWord;
    v191 = 6 - v183;
    v192 = buf->m_pDataIn;
    if ( v192 == v189 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v192 > v189 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_319;
      }
      buf->m_nInBufWord = *v192;
    }
    buf->m_pDataIn = v192 + 1;
LABEL_319:
    if ( buf->m_bOverflow )
    {
      v185 = 0;
    }
    else
    {
      v193 = buf->m_nInBufWord;
      v194 = (v193 & CBitBuffer::s_nMaskTable[v191]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v191;
      v185 = v194 | v190;
      buf->m_nInBufWord = v193 >> v191;
    }
    goto LABEL_322;
  }
LABEL_323:
  move->random_seed = MD5_PseudoRandom(nSeed: move->command_number) & 0x7FFFFFFF;
  v195 = buf->m_nInBufWord;
  v196 = (unsigned int *)(v195 & 1);
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v197 = buf->m_pDataIn;
    v198 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v197 == v198 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v197 + 1;
    }
    else if ( v197 <= v198 )
    {
      buf->m_nInBufWord = *v197;
      buf->m_pDataIn = v197 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v195 >> 1;
  }
  if ( v196 != nullptr )
  {
    v199 = buf->m_nBitsAvail;
    if ( v199 >= 16 )
    {
      v200 = buf->m_nInBufWord;
      v201 = v200;
      v196 = (unsigned int *)(v199 - 16);
      buf->m_nBitsAvail = (int)v196;
      if ( v196 != nullptr )
      {
        buf->m_nInBufWord = HIWORD(v200);
      }
      else
      {
        v202 = buf->m_pDataIn;
        v196 = (unsigned int *)buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v202 == v196 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v202 + 1;
        }
        else if ( v202 <= v196 )
        {
          v196 = (unsigned int *)*v202;
          buf->m_nInBufWord = *v202;
          buf->m_pDataIn = v202 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
LABEL_348:
      move->mousedx = v201;
      goto LABEL_349;
    }
    v203 = buf->m_pBufferEnd;
    v204 = buf->m_nInBufWord;
    v205 = (unsigned int *)(16 - v199);
    v196 = (unsigned int *)buf->m_pDataIn;
    if ( v196 == v203 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v196 > v203 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_345;
      }
      buf->m_nInBufWord = *v196;
    }
    buf->m_pDataIn = ++v196;
LABEL_345:
    if ( buf->m_bOverflow )
    {
      v201 = 0;
    }
    else
    {
      v206 = buf->m_nInBufWord;
      v207 = (v206 & CBitBuffer::s_nMaskTable[(_DWORD)v205]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - (_DWORD)v205;
      v196 = v205;
      v201 = v207 | v204;
      buf->m_nInBufWord = v206 >> (char)v205;
    }
    goto LABEL_348;
  }
LABEL_349:
  v208 = buf->m_nInBufWord;
  v209 = v208 & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v210 = buf->m_pDataIn;
    v196 = (unsigned int *)buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v210 == v196 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v210 + 1;
    }
    else if ( v210 <= v196 )
    {
      v196 = (unsigned int *)*v210;
      buf->m_nInBufWord = *v210;
      buf->m_pDataIn = v210 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v208 >> 1;
  }
  if ( v209 != 0 )
  {
    v211 = buf->m_nBitsAvail;
    if ( v211 >= 16 )
    {
      v212 = buf->m_nInBufWord;
      v213 = v212;
      v196 = (unsigned int *)(v211 - 16);
      buf->m_nBitsAvail = (int)v196;
      if ( v196 != nullptr )
      {
        buf->m_nInBufWord = HIWORD(v212);
      }
      else
      {
        v214 = buf->m_pDataIn;
        v196 = (unsigned int *)buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v214 == v196 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v214 + 1;
        }
        else if ( v214 <= v196 )
        {
          buf->m_nInBufWord = *v214;
          buf->m_pDataIn = v214 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
LABEL_374:
      move->mousedy = v213;
      goto LABEL_375;
    }
    v215 = buf->m_pBufferEnd;
    v216 = buf->m_nInBufWord;
    v217 = (unsigned int *)(16 - v211);
    v196 = (unsigned int *)buf->m_pDataIn;
    if ( v196 == v215 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v196 > v215 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_371;
      }
      buf->m_nInBufWord = *v196;
    }
    buf->m_pDataIn = ++v196;
LABEL_371:
    if ( buf->m_bOverflow )
    {
      v213 = 0;
    }
    else
    {
      v218 = buf->m_nInBufWord;
      v219 = (v218 & CBitBuffer::s_nMaskTable[(_DWORD)v217]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - (_DWORD)v217;
      v196 = v217;
      v213 = v219 | v216;
      buf->m_nInBufWord = v218 >> (char)v217;
    }
    goto LABEL_374;
  }
LABEL_375:
  if ( IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)v196) )
  {
    v220 = buf->m_nInBufWord;
    v221 = v220 & 1;
    v7 = buf->m_nBitsAvail-- == 1;
    if ( v7 )
    {
      v222 = buf->m_pDataIn;
      v223 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v222 == v223 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v222 + 1;
      }
      else if ( v222 <= v223 )
      {
        buf->m_nInBufWord = *v222;
        buf->m_pDataIn = v222 + 1;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    else
    {
      buf->m_nInBufWord = v220 >> 1;
    }
    if ( v221 != 0 )
      move->headangles.x = CBitRead::ReadBitAngle(this: buf, numbits: 16);
    v224 = buf->m_nInBufWord;
    v225 = v224 & 1;
    v7 = buf->m_nBitsAvail-- == 1;
    if ( v7 )
    {
      v226 = buf->m_pDataIn;
      v227 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v226 == v227 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v226 + 1;
      }
      else if ( v226 <= v227 )
      {
        buf->m_nInBufWord = *v226;
        buf->m_pDataIn = v226 + 1;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    else
    {
      buf->m_nInBufWord = v224 >> 1;
    }
    if ( v225 != 0 )
      move->headangles.y = CBitRead::ReadBitAngle(this: buf, numbits: 16);
    v228 = buf->m_nInBufWord;
    v229 = v228 & 1;
    v7 = buf->m_nBitsAvail-- == 1;
    if ( v7 )
    {
      v230 = buf->m_pDataIn;
      v231 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v230 == v231 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v230 + 1;
      }
      else if ( v230 <= v231 )
      {
        buf->m_nInBufWord = *v230;
        buf->m_pDataIn = v230 + 1;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    else
    {
      buf->m_nInBufWord = v228 >> 1;
    }
    if ( v229 != 0 )
      move->headangles.z = CBitRead::ReadBitAngle(this: buf, numbits: 8);
    v232 = buf->m_nInBufWord;
    v233 = v232 & 1;
    v7 = buf->m_nBitsAvail-- == 1;
    if ( v7 )
    {
      v234 = buf->m_pDataIn;
      v235 = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( v234 == v235 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_pDataIn = v234 + 1;
      }
      else if ( v234 <= v235 )
      {
        buf->m_nInBufWord = *v234;
        buf->m_pDataIn = v234 + 1;
      }
      else
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
      }
    }
    else
    {
      buf->m_nInBufWord = v232 >> 1;
    }
    if ( v233 != 0 )
      CBitRead::ReadBitVec3Coord(this: buf, fa: &move->headoffset);
  }
}

} // namespace server
