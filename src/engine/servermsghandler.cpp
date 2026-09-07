// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/servermsghandler.cpp
// Functions: 28
// ============================================================

#include "engine\servermsghandler.h"

//------------------------------------------------------------------------------
// Address: 0x101D4F80
// Name: public: void SoundInfo_t::ReadDelta(struct SoundInfo_t __near *,class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SoundInfo_t::ReadDelta(SoundInfo_t *this, SoundInfo_t *delta, bf_read *buffer)
{
  unsigned int m_nInBufWord; // ecx
  int v6; // edx
  bool v7; // zf
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int v10; // ecx
  int v11; // esi
  const unsigned int *v12; // ecx
  const unsigned int *v13; // edx
  int m_nBitsAvail; // ecx
  unsigned int v15; // edx
  int v16; // edi
  int v17; // ecx
  const unsigned int *v18; // ecx
  const unsigned int *v19; // edx
  int v20; // edx
  unsigned int v21; // edx
  int v22; // ecx
  unsigned int v23; // edx
  const unsigned int *v24; // esi
  unsigned int v25; // edi
  int v26; // edx
  const unsigned int *v27; // ecx
  unsigned int v28; // esi
  unsigned int v29; // ebx
  unsigned int v30; // ecx
  int v31; // esi
  const unsigned int *v32; // ecx
  const unsigned int *v33; // edx
  int v34; // ecx
  unsigned int v35; // edx
  int v36; // edi
  int v37; // ecx
  const unsigned int *v38; // ecx
  const unsigned int *v39; // edx
  SoundInfo_t *v40; // edx
  const unsigned int *v41; // esi
  unsigned int v42; // edi
  int v43; // edx
  const unsigned int *v44; // ecx
  unsigned int v45; // esi
  unsigned int v46; // ebx
  unsigned int v47; // ecx
  int v48; // esi
  const unsigned int *v49; // ecx
  const unsigned int *v50; // edx
  int v51; // ecx
  unsigned int v52; // edx
  int v53; // edi
  int v54; // ecx
  const unsigned int *v55; // ecx
  const unsigned int *v56; // edx
  SoundInfo_t *v57; // edx
  const unsigned int *v58; // esi
  unsigned int v59; // edi
  int v60; // edx
  const unsigned int *v61; // ecx
  unsigned int v62; // esi
  unsigned int v63; // ebx
  unsigned int v64; // ecx
  int v65; // esi
  const unsigned int *v66; // ecx
  const unsigned int *v67; // edx
  int v68; // ecx
  unsigned int v69; // edx
  int v70; // edi
  int v71; // ecx
  const unsigned int *v72; // ecx
  const unsigned int *v73; // edx
  SoundInfo_t *v74; // edx
  const unsigned int *v75; // esi
  unsigned int v76; // edi
  int v77; // edx
  const unsigned int *v78; // ecx
  unsigned int v79; // esi
  unsigned int v80; // ebx
  unsigned int v81; // ecx
  int v82; // edx
  const unsigned int *v83; // ecx
  const unsigned int *v84; // esi
  unsigned int v85; // ecx
  int v86; // edx
  const unsigned int *v87; // ecx
  const unsigned int *v88; // esi
  unsigned int v89; // ecx
  int v90; // esi
  const unsigned int *v91; // ecx
  const unsigned int *v92; // edx
  unsigned int v93; // ecx
  int v94; // esi
  const unsigned int *v95; // ecx
  const unsigned int *v96; // edx
  int v97; // ecx
  unsigned int v98; // edx
  int v99; // edi
  int v100; // ecx
  const unsigned int *v101; // ecx
  const unsigned int *v102; // edx
  unsigned int v103; // edx
  const unsigned int *v104; // esi
  unsigned int v105; // edi
  int v106; // edx
  const unsigned int *v107; // ecx
  unsigned int v108; // esi
  unsigned int v109; // ebx
  unsigned int v110; // ecx
  int v111; // esi
  const unsigned int *v112; // ecx
  const unsigned int *v113; // edx
  int v114; // ecx
  unsigned int v115; // edx
  int v116; // edi
  int v117; // ecx
  const unsigned int *v118; // ecx
  const unsigned int *v119; // edx
  unsigned int v120; // edx
  const unsigned int *v121; // esi
  unsigned int v122; // edi
  int v123; // edx
  const unsigned int *v124; // ecx
  unsigned int v125; // esi
  unsigned int v126; // ebx
  double fVolume; // st7
  unsigned int v128; // ecx
  int v129; // esi
  const unsigned int *v130; // ecx
  const unsigned int *v131; // edx
  int v132; // ecx
  unsigned int v133; // edx
  int v134; // edi
  int v135; // ecx
  const unsigned int *v136; // ecx
  const unsigned int *v137; // edx
  SoundInfo_t *v138; // edx
  const unsigned int *v139; // esi
  unsigned int v140; // edi
  int v141; // edx
  const unsigned int *v142; // ecx
  unsigned int v143; // esi
  unsigned int v144; // ebx
  unsigned int v145; // ecx
  int v146; // esi
  const unsigned int *v147; // ecx
  const unsigned int *v148; // edx
  int v149; // ecx
  unsigned int v150; // edx
  int v151; // edi
  int v152; // ecx
  const unsigned int *v153; // ecx
  const unsigned int *v154; // edx
  SoundInfo_t *v155; // edx
  const unsigned int *v156; // esi
  unsigned int v157; // edi
  int v158; // edx
  const unsigned int *v159; // ecx
  unsigned int v160; // esi
  unsigned int v161; // ebx
  unsigned int v162; // ecx
  int v163; // esi
  const unsigned int *v164; // ecx
  const unsigned int *v165; // edx
  int v166; // ecx
  unsigned int v167; // edx
  int v168; // edi
  int v169; // ecx
  const unsigned int *v170; // ecx
  const unsigned int *v171; // edx
  SoundInfo_t *v172; // edx
  const unsigned int *v173; // esi
  unsigned int v174; // edi
  int v175; // edx
  const unsigned int *v176; // ecx
  unsigned int v177; // esi
  unsigned int v178; // ebx
  unsigned int v179; // ecx
  int v180; // esi
  const unsigned int *v181; // ecx
  const unsigned int *v182; // edx
  int v183; // esi
  unsigned int v184; // ecx
  const unsigned int *v185; // edx
  const unsigned int *v186; // esi
  SoundInfo_t *v187; // edx
  unsigned int v188; // esi
  const unsigned int *v189; // ecx
  unsigned int v190; // edi
  int v191; // edx
  const unsigned int *v192; // esi
  unsigned int v193; // esi
  unsigned int v194; // ebx
  unsigned int v195; // ecx
  int v196; // esi
  const unsigned int *v197; // ecx
  const unsigned int *v198; // edx
  int v199; // ecx
  unsigned int v200; // edx
  int v201; // esi
  int v202; // ecx
  int v203; // ecx
  const unsigned int *v204; // ecx
  const unsigned int *v205; // edx
  unsigned int v206; // edx
  const unsigned int *v207; // esi
  unsigned int v208; // edi
  int v209; // edx
  const unsigned int *v210; // ecx
  unsigned int v211; // esi
  unsigned int v212; // ebx
  unsigned int v213; // ecx
  int v214; // esi
  const unsigned int *v215; // ecx
  const unsigned int *v216; // edx
  int v217; // ecx
  unsigned int v218; // edx
  int v219; // esi
  int v220; // ecx
  int v221; // ecx
  const unsigned int *v222; // ecx
  const unsigned int *v223; // edx
  unsigned int v224; // edx
  const unsigned int *v225; // esi
  unsigned int v226; // edi
  int v227; // edx
  const unsigned int *v228; // ecx
  unsigned int v229; // esi
  unsigned int v230; // ebx
  unsigned int v231; // ecx
  int v232; // esi
  const unsigned int *v233; // ecx
  const unsigned int *v234; // edx
  int v235; // ecx
  unsigned int v236; // edx
  int v237; // esi
  int v238; // ecx
  int v239; // ecx
  const unsigned int *v240; // ecx
  const unsigned int *v241; // edx
  unsigned int v242; // edx
  const unsigned int *v243; // esi
  unsigned int v244; // edi
  int v245; // edx
  const unsigned int *v246; // ecx
  unsigned int v247; // esi
  unsigned int v248; // ebx
  unsigned int v249; // ecx
  int v250; // esi
  const unsigned int *v251; // ecx
  const unsigned int *v252; // edx
  int v253; // ecx
  unsigned int v254; // edx
  int v255; // esi
  int v256; // ecx
  const unsigned int *v257; // ecx
  const unsigned int *v258; // edx
  SoundInfo_t *v259; // edx
  const unsigned int *v260; // esi
  unsigned int v261; // edi
  int v262; // edx
  const unsigned int *v263; // ecx
  unsigned int v264; // esi
  unsigned int v265; // ebx
  SoundInfo_t *v266; // [esp+Ch] [ebp-4h]
  bf_read *buffera; // [esp+1Ch] [ebp+Ch]

  m_nInBufWord = buffer->m_nInBufWord;
  v6 = m_nInBufWord & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  v266 = this;
  if ( v7 )
  {
    m_pDataIn = buffer->m_pDataIn;
    m_pBufferEnd = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      buffer->m_nInBufWord = *m_pDataIn;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = m_nInBufWord >> 1;
  }
  if ( v6 == 0 )
  {
    this->nEntityIndex = delta->nEntityIndex;
    goto LABEL_41;
  }
  v10 = buffer->m_nInBufWord;
  v11 = v10 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v12 = buffer->m_pDataIn;
    v13 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v12 == v13 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v12 + 1;
    }
    else if ( v12 <= v13 )
    {
      buffer->m_nInBufWord = *v12;
      buffer->m_pDataIn = v12 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v10 >> 1;
  }
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( v11 == 0 )
  {
    if ( m_nBitsAvail >= 11 )
    {
      v21 = buffer->m_nInBufWord;
      v16 = v21 & 0x7FF;
      v22 = m_nBitsAvail - 11;
      buffer->m_nBitsAvail = v22;
      if ( v22 != 0 )
      {
        buffer->m_nInBufWord = v21 >> 11;
        goto LABEL_40;
      }
LABEL_21:
      v18 = buffer->m_pDataIn;
      v19 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v18 == v19 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v18 + 1;
      }
      else if ( v18 <= v19 )
      {
        v23 = *v18;
        buffer->m_pDataIn = v18 + 1;
        buffer->m_nInBufWord = v23;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      goto LABEL_40;
    }
    v20 = 11;
LABEL_31:
    v24 = buffer->m_pBufferEnd;
    v25 = buffer->m_nInBufWord;
    v26 = v20 - m_nBitsAvail;
    v27 = buffer->m_pDataIn;
    if ( v27 == v24 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v27 > v24 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_37;
      }
      buffer->m_nInBufWord = *v27;
    }
    buffer->m_pDataIn = v27 + 1;
LABEL_37:
    if ( buffer->m_bOverflow )
    {
      v16 = 0;
    }
    else
    {
      v28 = buffer->m_nInBufWord;
      v29 = (v28 & CBitBuffer::s_nMaskTable[v26]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v26;
      v16 = v29 | v25;
      buffer->m_nInBufWord = v28 >> v26;
    }
    goto LABEL_40;
  }
  if ( m_nBitsAvail < 5 )
  {
    v20 = 5;
    goto LABEL_31;
  }
  v15 = buffer->m_nInBufWord;
  v16 = v15 & 0x1F;
  v17 = m_nBitsAvail - 5;
  buffer->m_nBitsAvail = v17;
  if ( v17 == 0 )
    goto LABEL_21;
  buffer->m_nInBufWord = v15 >> 5;
LABEL_40:
  v266->nEntityIndex = v16;
LABEL_41:
  v30 = buffer->m_nInBufWord;
  v31 = v30 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v32 = buffer->m_pDataIn;
    v33 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v32 == v33 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v32 + 1;
    }
    else if ( v32 <= v33 )
    {
      buffer->m_nInBufWord = *v32;
      buffer->m_pDataIn = v32 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v30 >> 1;
  }
  if ( v31 == 0 )
  {
    v266->nSoundNum = delta->nSoundNum;
    goto LABEL_68;
  }
  v34 = buffer->m_nBitsAvail;
  if ( v34 < 13 )
  {
    v41 = buffer->m_pBufferEnd;
    v42 = buffer->m_nInBufWord;
    v43 = 13 - v34;
    v44 = buffer->m_pDataIn;
    if ( v44 == v41 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v44 > v41 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_64;
      }
      buffer->m_nInBufWord = *v44;
    }
    buffer->m_pDataIn = v44 + 1;
LABEL_64:
    if ( buffer->m_bOverflow )
    {
      v266->nSoundNum = 0;
    }
    else
    {
      v45 = buffer->m_nInBufWord;
      v46 = (v45 & CBitBuffer::s_nMaskTable[v43]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v43;
      buffer->m_nInBufWord = v45 >> v43;
      v266->nSoundNum = v46 | v42;
    }
    goto LABEL_68;
  }
  v35 = buffer->m_nInBufWord;
  v36 = v35 & 0x1FFF;
  v37 = v34 - 13;
  buffer->m_nBitsAvail = v37;
  if ( v37 != 0 )
  {
    buffer->m_nInBufWord = v35 >> 13;
    v266->nSoundNum = v36;
  }
  else
  {
    v38 = buffer->m_pDataIn;
    v39 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v38 == v39 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v38 + 1;
      v266->nSoundNum = v36;
    }
    else
    {
      if ( v38 <= v39 )
      {
        buffer->m_nInBufWord = *v38;
        v40 = v266;
        buffer->m_pDataIn = v38 + 1;
      }
      else
      {
        v40 = v266;
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v40->nSoundNum = v36;
    }
  }
LABEL_68:
  v47 = buffer->m_nInBufWord;
  v48 = v47 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v49 = buffer->m_pDataIn;
    v50 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v49 == v50 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v49 + 1;
    }
    else if ( v49 <= v50 )
    {
      buffer->m_nInBufWord = *v49;
      buffer->m_pDataIn = v49 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v47 >> 1;
  }
  if ( v48 == 0 )
  {
    v266->nFlags = delta->nFlags;
    goto LABEL_95;
  }
  v51 = buffer->m_nBitsAvail;
  if ( v51 < 13 )
  {
    v58 = buffer->m_pBufferEnd;
    v59 = buffer->m_nInBufWord;
    v60 = 13 - v51;
    v61 = buffer->m_pDataIn;
    if ( v61 == v58 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v61 > v58 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_91;
      }
      buffer->m_nInBufWord = *v61;
    }
    buffer->m_pDataIn = v61 + 1;
LABEL_91:
    if ( buffer->m_bOverflow )
    {
      v266->nFlags = 0;
    }
    else
    {
      v62 = buffer->m_nInBufWord;
      v63 = (v62 & CBitBuffer::s_nMaskTable[v60]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v60;
      buffer->m_nInBufWord = v62 >> v60;
      v266->nFlags = v63 | v59;
    }
    goto LABEL_95;
  }
  v52 = buffer->m_nInBufWord;
  v53 = v52 & 0x1FFF;
  v54 = v51 - 13;
  buffer->m_nBitsAvail = v54;
  if ( v54 != 0 )
  {
    buffer->m_nInBufWord = v52 >> 13;
    v266->nFlags = v53;
  }
  else
  {
    v55 = buffer->m_pDataIn;
    v56 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v55 == v56 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v55 + 1;
      v266->nFlags = v53;
    }
    else
    {
      if ( v55 <= v56 )
      {
        buffer->m_nInBufWord = *v55;
        v57 = v266;
        buffer->m_pDataIn = v55 + 1;
      }
      else
      {
        v57 = v266;
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v57->nFlags = v53;
    }
  }
LABEL_95:
  v64 = buffer->m_nInBufWord;
  v65 = v64 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v66 = buffer->m_pDataIn;
    v67 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v66 == v67 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v66 + 1;
    }
    else if ( v66 <= v67 )
    {
      buffer->m_nInBufWord = *v66;
      buffer->m_pDataIn = v66 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v64 >> 1;
  }
  if ( v65 == 0 )
  {
    v266->nChannel = delta->nChannel;
    goto LABEL_122;
  }
  v68 = buffer->m_nBitsAvail;
  if ( v68 < 3 )
  {
    v75 = buffer->m_pBufferEnd;
    v76 = buffer->m_nInBufWord;
    v77 = 3 - v68;
    v78 = buffer->m_pDataIn;
    if ( v78 == v75 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v78 > v75 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_118;
      }
      buffer->m_nInBufWord = *v78;
    }
    buffer->m_pDataIn = v78 + 1;
LABEL_118:
    if ( buffer->m_bOverflow )
    {
      v266->nChannel = 0;
    }
    else
    {
      v79 = buffer->m_nInBufWord;
      v80 = (v79 & CBitBuffer::s_nMaskTable[v77]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v77;
      buffer->m_nInBufWord = v79 >> v77;
      v266->nChannel = v80 | v76;
    }
    goto LABEL_122;
  }
  v69 = buffer->m_nInBufWord;
  v70 = v69 & 7;
  v71 = v68 - 3;
  buffer->m_nBitsAvail = v71;
  if ( v71 != 0 )
  {
    buffer->m_nInBufWord = v69 >> 3;
    v266->nChannel = v70;
  }
  else
  {
    v72 = buffer->m_pDataIn;
    v73 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v72 == v73 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v72 + 1;
      v266->nChannel = v70;
    }
    else
    {
      if ( v72 <= v73 )
      {
        buffer->m_nInBufWord = *v72;
        v74 = v266;
        buffer->m_pDataIn = v72 + 1;
      }
      else
      {
        v74 = v266;
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v74->nChannel = v70;
    }
  }
LABEL_122:
  v81 = buffer->m_nInBufWord;
  v82 = v81 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v83 = buffer->m_pDataIn;
    v84 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v83 == v84 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v83 + 1;
    }
    else if ( v83 <= v84 )
    {
      buffer->m_nInBufWord = *v83;
      buffer->m_pDataIn = v83 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v81 >> 1;
  }
  v266->bIsAmbient = v82 != 0;
  v85 = buffer->m_nInBufWord;
  v86 = v85 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v87 = buffer->m_pDataIn;
    v88 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v87 == v88 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v87 + 1;
    }
    else if ( v87 <= v88 )
    {
      buffer->m_nInBufWord = *v87;
      buffer->m_pDataIn = v87 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v85 >> 1;
  }
  v7 = v266->nFlags == 4;
  v266->bIsSentence = v86 != 0;
  if ( v7 )
  {
    v266->Soundlevel = SNDLVL_NONE;
    v266->pszName = nullptr;
    v266->nSequenceNumber = 0;
    v266->fVolume = 0.0;
    v266->nPitch = 100;
    v266->fDelay = 0.0;
    v266->vOrigin.x = 0.0;
    v266->vOrigin.y = 0.0;
    v266->vOrigin.z = 0.0;
    v266->nSpeakerEntity = -1;
    return;
  }
  v89 = buffer->m_nInBufWord;
  v90 = v89 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v91 = buffer->m_pDataIn;
    v92 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v91 == v92 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v91 + 1;
    }
    else if ( v91 <= v92 )
    {
      buffer->m_nInBufWord = *v91;
      buffer->m_pDataIn = v91 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v89 >> 1;
  }
  if ( v90 != 0 )
  {
    v266->nSequenceNumber = delta->nSequenceNumber;
    goto LABEL_173;
  }
  v93 = buffer->m_nInBufWord;
  v94 = v93 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v95 = buffer->m_pDataIn;
    v96 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v95 == v96 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v95 + 1;
    }
    else if ( v95 <= v96 )
    {
      buffer->m_nInBufWord = *v95;
      buffer->m_pDataIn = v95 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v93 >> 1;
  }
  if ( v94 != 0 )
  {
    v266->nSequenceNumber = delta->nSequenceNumber + 1;
    goto LABEL_173;
  }
  v97 = buffer->m_nBitsAvail;
  if ( v97 < 10 )
  {
    v104 = buffer->m_pBufferEnd;
    v105 = buffer->m_nInBufWord;
    v106 = 10 - v97;
    v107 = buffer->m_pDataIn;
    if ( v107 == v104 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v107 > v104 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_169;
      }
      buffer->m_nInBufWord = *v107;
    }
    buffer->m_pDataIn = v107 + 1;
LABEL_169:
    if ( buffer->m_bOverflow )
    {
      v99 = 0;
    }
    else
    {
      v108 = buffer->m_nInBufWord;
      v109 = (v108 & CBitBuffer::s_nMaskTable[v106]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v106;
      v99 = v109 | v105;
      buffer->m_nInBufWord = v108 >> v106;
    }
    goto LABEL_172;
  }
  v98 = buffer->m_nInBufWord;
  v99 = v98 & 0x3FF;
  v100 = v97 - 10;
  buffer->m_nBitsAvail = v100;
  if ( v100 != 0 )
  {
    buffer->m_nInBufWord = v98 >> 10;
  }
  else
  {
    v101 = buffer->m_pDataIn;
    v102 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v101 == v102 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v101 + 1;
    }
    else if ( v101 <= v102 )
    {
      v103 = *v101;
      buffer->m_pDataIn = v101 + 1;
      buffer->m_nInBufWord = v103;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
LABEL_172:
  v266->nSequenceNumber = v99;
LABEL_173:
  v110 = buffer->m_nInBufWord;
  v111 = v110 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v112 = buffer->m_pDataIn;
    v113 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v112 == v113 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v112 + 1;
    }
    else if ( v112 <= v113 )
    {
      buffer->m_nInBufWord = *v112;
      buffer->m_pDataIn = v112 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v110 >> 1;
  }
  if ( v111 != 0 )
  {
    v114 = buffer->m_nBitsAvail;
    if ( v114 >= 7 )
    {
      v115 = buffer->m_nInBufWord;
      v116 = v115 & 0x7F;
      v117 = v114 - 7;
      buffer->m_nBitsAvail = v117;
      if ( v117 != 0 )
      {
        buffer->m_nInBufWord = v115 >> 7;
      }
      else
      {
        v118 = buffer->m_pDataIn;
        v119 = buffer->m_pBufferEnd;
        buffer->m_nBitsAvail = 32;
        if ( v118 == v119 )
        {
          buffer->m_nBitsAvail = 1;
          buffer->m_nInBufWord = 0;
          buffer->m_pDataIn = v118 + 1;
        }
        else if ( v118 <= v119 )
        {
          v120 = *v118;
          buffer->m_pDataIn = v118 + 1;
          buffer->m_nInBufWord = v120;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
      }
LABEL_198:
      fVolume = (double)(unsigned int)v116 * 0.0078740157;
      goto LABEL_200;
    }
    v121 = buffer->m_pBufferEnd;
    v122 = buffer->m_nInBufWord;
    v123 = 7 - v114;
    v124 = buffer->m_pDataIn;
    if ( v124 == v121 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v124 > v121 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_195;
      }
      buffer->m_nInBufWord = *v124;
    }
    buffer->m_pDataIn = v124 + 1;
LABEL_195:
    if ( buffer->m_bOverflow )
    {
      v116 = 0;
    }
    else
    {
      v125 = buffer->m_nInBufWord;
      v126 = (v125 & CBitBuffer::s_nMaskTable[v123]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v123;
      v116 = v126 | v122;
      buffer->m_nInBufWord = v125 >> v123;
    }
    goto LABEL_198;
  }
  fVolume = delta->fVolume;
LABEL_200:
  v266->fVolume = fVolume;
  v128 = buffer->m_nInBufWord;
  v129 = v128 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v130 = buffer->m_pDataIn;
    v131 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v130 == v131 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v130 + 1;
    }
    else if ( v130 <= v131 )
    {
      buffer->m_nInBufWord = *v130;
      buffer->m_pDataIn = v130 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v128 >> 1;
  }
  if ( v129 == 0 )
  {
    v266->Soundlevel = delta->Soundlevel;
    goto LABEL_228;
  }
  v132 = buffer->m_nBitsAvail;
  if ( v132 < 9 )
  {
    v139 = buffer->m_pBufferEnd;
    v140 = buffer->m_nInBufWord;
    v141 = 9 - v132;
    v142 = buffer->m_pDataIn;
    if ( v142 == v139 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v142 > v139 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_223;
      }
      buffer->m_nInBufWord = *v142;
    }
    buffer->m_pDataIn = v142 + 1;
LABEL_223:
    if ( buffer->m_bOverflow )
    {
      v266->Soundlevel = SNDLVL_NONE;
    }
    else
    {
      v143 = buffer->m_nInBufWord;
      v144 = (v143 & CBitBuffer::s_nMaskTable[v141]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v141;
      buffer->m_nInBufWord = v143 >> v141;
      v266->Soundlevel = v144 | v140;
    }
    goto LABEL_228;
  }
  v133 = buffer->m_nInBufWord;
  v134 = v133 & 0x1FF;
  v135 = v132 - 9;
  buffer->m_nBitsAvail = v135;
  if ( v135 != 0 )
  {
    buffer->m_nInBufWord = v133 >> 9;
    v266->Soundlevel = v134;
  }
  else
  {
    v136 = buffer->m_pDataIn;
    v137 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v136 == v137 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v136 + 1;
      v266->Soundlevel = v134;
    }
    else
    {
      if ( v136 <= v137 )
      {
        buffer->m_nInBufWord = *v136;
        v138 = v266;
        buffer->m_pDataIn = v136 + 1;
      }
      else
      {
        v138 = v266;
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v138->Soundlevel = v134;
    }
  }
LABEL_228:
  v145 = buffer->m_nInBufWord;
  v146 = v145 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v147 = buffer->m_pDataIn;
    v148 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v147 == v148 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v147 + 1;
    }
    else if ( v147 <= v148 )
    {
      buffer->m_nInBufWord = *v147;
      buffer->m_pDataIn = v147 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v145 >> 1;
  }
  if ( v146 == 0 )
  {
    v266->nPitch = delta->nPitch;
    goto LABEL_256;
  }
  v149 = buffer->m_nBitsAvail;
  if ( v149 < 8 )
  {
    v156 = buffer->m_pBufferEnd;
    v157 = buffer->m_nInBufWord;
    v158 = 8 - v149;
    v159 = buffer->m_pDataIn;
    if ( v159 == v156 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v159 > v156 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_251;
      }
      buffer->m_nInBufWord = *v159;
    }
    buffer->m_pDataIn = v159 + 1;
LABEL_251:
    if ( buffer->m_bOverflow )
    {
      v266->nPitch = 0;
    }
    else
    {
      v160 = buffer->m_nInBufWord;
      v161 = (v160 & CBitBuffer::s_nMaskTable[v158]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v158;
      buffer->m_nInBufWord = v160 >> v158;
      v266->nPitch = v161 | v157;
    }
    goto LABEL_256;
  }
  v150 = buffer->m_nInBufWord;
  v151 = (unsigned __int8)v150;
  v152 = v149 - 8;
  buffer->m_nBitsAvail = v152;
  if ( v152 != 0 )
  {
    buffer->m_nInBufWord = v150 >> 8;
    v266->nPitch = (unsigned __int8)v150;
  }
  else
  {
    v153 = buffer->m_pDataIn;
    v154 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v153 == v154 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v153 + 1;
      v266->nPitch = v151;
    }
    else
    {
      if ( v153 <= v154 )
      {
        buffer->m_nInBufWord = *v153;
        v155 = v266;
        buffer->m_pDataIn = v153 + 1;
      }
      else
      {
        v155 = v266;
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v155->nPitch = v151;
    }
  }
LABEL_256:
  v162 = buffer->m_nInBufWord;
  v163 = v162 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v164 = buffer->m_pDataIn;
    v165 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v164 == v165 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v164 + 1;
    }
    else if ( v164 <= v165 )
    {
      buffer->m_nInBufWord = *v164;
      buffer->m_pDataIn = v164 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v162 >> 1;
  }
  if ( v163 == 0 )
  {
    v266->nRandomSeed = delta->nRandomSeed;
    goto LABEL_284;
  }
  v166 = buffer->m_nBitsAvail;
  if ( v166 < 6 )
  {
    v173 = buffer->m_pBufferEnd;
    v174 = buffer->m_nInBufWord;
    v175 = 6 - v166;
    v176 = buffer->m_pDataIn;
    if ( v176 == v173 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v176 > v173 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_279;
      }
      buffer->m_nInBufWord = *v176;
    }
    buffer->m_pDataIn = v176 + 1;
LABEL_279:
    if ( buffer->m_bOverflow )
    {
      v266->nRandomSeed = 0;
    }
    else
    {
      v177 = buffer->m_nInBufWord;
      v178 = (v177 & CBitBuffer::s_nMaskTable[v175]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v175;
      buffer->m_nInBufWord = v177 >> v175;
      v266->nRandomSeed = v178 | v174;
    }
    goto LABEL_284;
  }
  v167 = buffer->m_nInBufWord;
  v168 = v167 & 0x3F;
  v169 = v166 - 6;
  buffer->m_nBitsAvail = v169;
  if ( v169 != 0 )
  {
    buffer->m_nInBufWord = v167 >> 6;
    v266->nRandomSeed = v168;
  }
  else
  {
    v170 = buffer->m_pDataIn;
    v171 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v170 == v171 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v170 + 1;
      v266->nRandomSeed = v168;
    }
    else
    {
      if ( v170 <= v171 )
      {
        buffer->m_nInBufWord = *v170;
        v172 = v266;
        buffer->m_pDataIn = v170 + 1;
      }
      else
      {
        v172 = v266;
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v172->nRandomSeed = v168;
    }
  }
LABEL_284:
  v179 = buffer->m_nInBufWord;
  v180 = v179 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v181 = buffer->m_pDataIn;
    v182 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v181 == v182 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v181 + 1;
    }
    else if ( v181 <= v182 )
    {
      buffer->m_nInBufWord = *v181;
      buffer->m_pDataIn = v181 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v179 >> 1;
  }
  if ( v180 == 0 )
  {
    v266->fDelay = delta->fDelay;
    goto LABEL_312;
  }
  v183 = buffer->m_nBitsAvail;
  if ( v183 >= 32 )
  {
    v184 = buffer->m_nInBufWord;
    buffer->m_nBitsAvail = v183 - 32;
    if ( v183 == 32 )
    {
      v185 = buffer->m_pDataIn;
      v186 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v185 == v186 )
      {
        buffer->m_pDataIn = v185 + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        LODWORD(v266->fDelay) = v184;
      }
      else
      {
        if ( v185 <= v186 )
        {
          v188 = *v185;
          buffer->m_pDataIn = v185 + 1;
          v187 = v266;
          buffer->m_nInBufWord = v188;
        }
        else
        {
          v187 = v266;
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        LODWORD(v187->fDelay) = v184;
      }
    }
    else
    {
      buffer->m_nInBufWord = 0;
      LODWORD(v266->fDelay) = v184;
    }
    goto LABEL_312;
  }
  v189 = buffer->m_pDataIn;
  v190 = buffer->m_nInBufWord;
  v191 = 32 - v183;
  v192 = buffer->m_pBufferEnd;
  if ( v189 == v192 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_306:
    buffer->m_pDataIn = v189 + 1;
    goto LABEL_307;
  }
  if ( v189 <= v192 )
  {
    buffer->m_nInBufWord = *v189;
    goto LABEL_306;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_307:
  if ( buffer->m_bOverflow )
  {
    buffera = nullptr;
  }
  else
  {
    v193 = buffer->m_nInBufWord;
    v194 = (v193 & CBitBuffer::s_nMaskTable[v191]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v191;
    buffera = (bf_read *)(v194 | v190);
    buffer->m_nInBufWord = v193 >> v191;
  }
  LODWORD(v266->fDelay) = buffera;
LABEL_312:
  v195 = buffer->m_nInBufWord;
  v196 = v195 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v197 = buffer->m_pDataIn;
    v198 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v197 == v198 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v197 + 1;
    }
    else if ( v197 <= v198 )
    {
      buffer->m_nInBufWord = *v197;
      buffer->m_pDataIn = v197 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v195 >> 1;
  }
  if ( v196 != 0 )
  {
    v199 = buffer->m_nBitsAvail;
    if ( v199 >= 12 )
    {
      v200 = buffer->m_nInBufWord;
      v201 = v200 & 0xFFF;
      v202 = v199 - 12;
      buffer->m_nBitsAvail = v202;
      if ( v202 != 0 )
      {
        buffer->m_nInBufWord = v200 >> 12;
        v203 = v200 & 0xFFF;
      }
      else
      {
        v204 = buffer->m_pDataIn;
        v205 = buffer->m_pBufferEnd;
        buffer->m_nBitsAvail = 32;
        if ( v204 == v205 )
        {
          buffer->m_pDataIn = v204 + 1;
          buffer->m_nBitsAvail = 1;
          buffer->m_nInBufWord = 0;
          v203 = v201;
        }
        else
        {
          if ( v204 <= v205 )
          {
            v206 = *v204;
            buffer->m_pDataIn = v204 + 1;
            buffer->m_nInBufWord = v206;
          }
          else
          {
            buffer->m_bOverflow = true;
            buffer->m_nInBufWord = 0;
          }
          v203 = v201;
        }
      }
      goto LABEL_338;
    }
    v207 = buffer->m_pBufferEnd;
    v208 = buffer->m_nInBufWord;
    v209 = 12 - v199;
    v210 = buffer->m_pDataIn;
    if ( v210 == v207 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v210 > v207 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_335;
      }
      buffer->m_nInBufWord = *v210;
    }
    buffer->m_pDataIn = v210 + 1;
LABEL_335:
    if ( buffer->m_bOverflow )
    {
      v203 = 0;
    }
    else
    {
      v211 = buffer->m_nInBufWord;
      v212 = (v211 & CBitBuffer::s_nMaskTable[v209]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v209;
      v203 = v212 | v208;
      buffer->m_nInBufWord = v211 >> v209;
    }
LABEL_338:
    v266->vOrigin.x = (float)(v203 << 20 >> 20) * 8.0;
    goto LABEL_340;
  }
  v266->vOrigin.x = delta->vOrigin.x;
LABEL_340:
  v213 = buffer->m_nInBufWord;
  v214 = v213 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v215 = buffer->m_pDataIn;
    v216 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v215 == v216 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v215 + 1;
    }
    else if ( v215 <= v216 )
    {
      buffer->m_nInBufWord = *v215;
      buffer->m_pDataIn = v215 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v213 >> 1;
  }
  if ( v214 != 0 )
  {
    v217 = buffer->m_nBitsAvail;
    if ( v217 >= 12 )
    {
      v218 = buffer->m_nInBufWord;
      v219 = v218 & 0xFFF;
      v220 = v217 - 12;
      buffer->m_nBitsAvail = v220;
      if ( v220 != 0 )
      {
        buffer->m_nInBufWord = v218 >> 12;
        v221 = v218 & 0xFFF;
      }
      else
      {
        v222 = buffer->m_pDataIn;
        v223 = buffer->m_pBufferEnd;
        buffer->m_nBitsAvail = 32;
        if ( v222 == v223 )
        {
          buffer->m_pDataIn = v222 + 1;
          buffer->m_nBitsAvail = 1;
          buffer->m_nInBufWord = 0;
          v221 = v219;
        }
        else
        {
          if ( v222 <= v223 )
          {
            v224 = *v222;
            buffer->m_pDataIn = v222 + 1;
            buffer->m_nInBufWord = v224;
          }
          else
          {
            buffer->m_bOverflow = true;
            buffer->m_nInBufWord = 0;
          }
          v221 = v219;
        }
      }
      goto LABEL_366;
    }
    v225 = buffer->m_pBufferEnd;
    v226 = buffer->m_nInBufWord;
    v227 = 12 - v217;
    v228 = buffer->m_pDataIn;
    if ( v228 == v225 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v228 > v225 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_363;
      }
      buffer->m_nInBufWord = *v228;
    }
    buffer->m_pDataIn = v228 + 1;
LABEL_363:
    if ( buffer->m_bOverflow )
    {
      v221 = 0;
    }
    else
    {
      v229 = buffer->m_nInBufWord;
      v230 = (v229 & CBitBuffer::s_nMaskTable[v227]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v227;
      v221 = v230 | v226;
      buffer->m_nInBufWord = v229 >> v227;
    }
LABEL_366:
    v266->vOrigin.y = (float)(v221 << 20 >> 20) * 8.0;
    goto LABEL_368;
  }
  v266->vOrigin.y = delta->vOrigin.y;
LABEL_368:
  v231 = buffer->m_nInBufWord;
  v232 = v231 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v233 = buffer->m_pDataIn;
    v234 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v233 == v234 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v233 + 1;
    }
    else if ( v233 <= v234 )
    {
      buffer->m_nInBufWord = *v233;
      buffer->m_pDataIn = v233 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v231 >> 1;
  }
  if ( v232 != 0 )
  {
    v235 = buffer->m_nBitsAvail;
    if ( v235 >= 12 )
    {
      v236 = buffer->m_nInBufWord;
      v237 = v236 & 0xFFF;
      v238 = v235 - 12;
      buffer->m_nBitsAvail = v238;
      if ( v238 != 0 )
      {
        buffer->m_nInBufWord = v236 >> 12;
        v239 = v236 & 0xFFF;
      }
      else
      {
        v240 = buffer->m_pDataIn;
        v241 = buffer->m_pBufferEnd;
        buffer->m_nBitsAvail = 32;
        if ( v240 == v241 )
        {
          buffer->m_pDataIn = v240 + 1;
          buffer->m_nBitsAvail = 1;
          buffer->m_nInBufWord = 0;
          v239 = v237;
        }
        else
        {
          if ( v240 <= v241 )
          {
            v242 = *v240;
            buffer->m_pDataIn = v240 + 1;
            buffer->m_nInBufWord = v242;
          }
          else
          {
            buffer->m_bOverflow = true;
            buffer->m_nInBufWord = 0;
          }
          v239 = v237;
        }
      }
      goto LABEL_394;
    }
    v243 = buffer->m_pBufferEnd;
    v244 = buffer->m_nInBufWord;
    v245 = 12 - v235;
    v246 = buffer->m_pDataIn;
    if ( v246 == v243 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v246 > v243 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_391;
      }
      buffer->m_nInBufWord = *v246;
    }
    buffer->m_pDataIn = v246 + 1;
LABEL_391:
    if ( buffer->m_bOverflow )
    {
      v239 = 0;
    }
    else
    {
      v247 = buffer->m_nInBufWord;
      v248 = (v247 & CBitBuffer::s_nMaskTable[v245]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v245;
      v239 = v248 | v244;
      buffer->m_nInBufWord = v247 >> v245;
    }
LABEL_394:
    v266->vOrigin.z = (float)(v239 << 20 >> 20) * 8.0;
    goto LABEL_396;
  }
  v266->vOrigin.z = delta->vOrigin.z;
LABEL_396:
  v249 = buffer->m_nInBufWord;
  v250 = v249 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v251 = buffer->m_pDataIn;
    v252 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v251 == v252 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v251 + 1;
    }
    else if ( v251 <= v252 )
    {
      buffer->m_nInBufWord = *v251;
      buffer->m_pDataIn = v251 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v249 >> 1;
  }
  if ( v250 == 0 )
  {
    v266->nSpeakerEntity = delta->nSpeakerEntity;
    return;
  }
  v253 = buffer->m_nBitsAvail;
  if ( v253 < 12 )
  {
    v260 = buffer->m_pBufferEnd;
    v261 = buffer->m_nInBufWord;
    v262 = 12 - v253;
    v263 = buffer->m_pDataIn;
    if ( v263 == v260 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v263 > v260 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_419;
      }
      buffer->m_nInBufWord = *v263;
    }
    buffer->m_pDataIn = v263 + 1;
LABEL_419:
    if ( buffer->m_bOverflow )
    {
      v266->nSpeakerEntity = 0;
    }
    else
    {
      v264 = buffer->m_nInBufWord;
      v265 = (v264 & CBitBuffer::s_nMaskTable[v262]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v262;
      buffer->m_nInBufWord = v264 >> v262;
      v266->nSpeakerEntity = (int)((v265 | v261) << 20) >> 20;
    }
    return;
  }
  v254 = buffer->m_nInBufWord;
  v255 = v254 & 0xFFF;
  v256 = v253 - 12;
  buffer->m_nBitsAvail = v256;
  if ( v256 != 0 )
  {
    buffer->m_nInBufWord = v254 >> 12;
    v266->nSpeakerEntity = (unsigned __int16)v254 << 20 >> 20;
  }
  else
  {
    v257 = buffer->m_pDataIn;
    v258 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v257 == v258 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v257 + 1;
      v266->nSpeakerEntity = v255 << 20 >> 20;
    }
    else
    {
      if ( v257 <= v258 )
      {
        buffer->m_nInBufWord = *v257;
        v259 = v266;
        buffer->m_pDataIn = v257 + 1;
      }
      else
      {
        v259 = v266;
        buffer->m_nInBufWord = 0;
        buffer->m_bOverflow = true;
      }
      v259->nSpeakerEntity = v255 << 20 >> 20;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D64C0
// Name: public: virtual void CClientState::ConnectionClosing(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::ConnectionClosing(CClientState *this, const char *reason)
{
  int v2; // eax

  if ( this->m_nSignonState > 0 )
  {
    ConMsg(a1: "Disconnect: %s.\n", reason);
    if ( _V_stricmp(s1: reason, s2: "Invalid STEAM UserID Ticket\n") != 0 )
    {
      if ( _V_stricmp(s1: reason, s2: "No Steam logon\n") != 0 )
      {
        if ( _V_stricmp(s1: reason, s2: "This Steam account is being used in another location\n") != 0 )
          g_eSteamLoginFailure = _V_stricmp(s1: reason, s2: "VAC banned from secure server\n") != 0 ? 0 : 3;
        else
          g_eSteamLoginFailure = 4;
      }
      else
      {
        g_eSteamLoginFailure = 2;
      }
    }
    else
    {
      g_eSteamLoginFailure = 1;
    }
    COM_ExplainDisconnection(bPrint: true, fmt: "Disconnect: %s.\n", reason);
    SCR_EndLoadingPlaque();
    Host_Disconnect(bShowMainMenu: true);
    if ( reason != nullptr && _V_stricmp(s1: reason, s2: "Server shutting down") == 0 )
    {
      v2 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-quitonservershutdown") != 0 )
        Host_Shutdown();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D65A0
// Name: public: virtual void CClientState::ConnectionCrashed(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::ConnectionCrashed(CClientState *this, const char *reason)
{
  if ( this->m_nSignonState > 0 )
  {
    COM_ExplainDisconnection(bPrint: true, fmt: "Disconnect: %s.\n", reason);
    SCR_EndLoadingPlaque();
    Host_Disconnect(bShowMainMenu: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D65D0
// Name: public: virtual void CClientState::FileReceived(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::FileReceived(
        CClientState *this,
        const char *fileName,
        unsigned int transferID,
        bool isReplayDemoFile)
{
  CL_FileReceived(filename: fileName, requestID: transferID, isReplayDemoFile);
}

//------------------------------------------------------------------------------
// Address: 0x101D65F0
// Name: public: virtual void CClientState::FileDenied(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::FileDenied(
        CClientState *this,
        const char *fileName,
        unsigned int transferID,
        bool isReplayDemoFile)
{
  CL_FileDenied(filename: fileName, requestID: transferID, isReplayDemoFile);
}

//------------------------------------------------------------------------------
// Address: 0x101D6610
// Name: public: virtual void CClientState::PacketStart(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::PacketStart(CClientState *this, int incoming_sequence, int outgoing_acknowledged)
{
  this->m_nCurrentSequence = incoming_sequence;
  this->command_ack = outgoing_acknowledged;
}

//------------------------------------------------------------------------------
// Address: 0x101D6630
// Name: public: virtual void CClientState::PacketEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::PacketEnd(CClientState *this)
{
  int m_nServerTick; // edx
  int v3; // eax

  CL_DispatchSounds();
  m_nServerTick = this->m_ClockDriftMgr.m_nServerTick;
  if ( m_nServerTick == this->m_nDeltaTick )
  {
    v3 = this->command_ack - this->last_command_ack;
    this->last_command_ack = this->command_ack;
    this->last_server_tick = m_nServerTick;
    g_pClientSidePrediction->PostNetworkDataReceived(this: g_pClientSidePrediction, a2: v3);
    demoaction->DispatchEvents(this: demoaction);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6680
// Name: public: virtual void CClientState::Disconnect(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::Disconnect(CClientState *this, bool bShowMainMenu)
{
  IEngineVGuiInternal *v3; // eax
  IEngineVGuiInternal *v4; // eax
  IEngineVGuiInternal *v5; // eax

  CBaseClientState::Disconnect(this, bShowMainMenu);
  if ( !this->m_bSplitScreenUser )
  {
    if ( (_S2_16 & 1) == 0 )
    {
      _S2_16 |= 1u;
      ConVarRef::ConVarRef(this: &map_wants_save_disable, pName: "map_wants_save_disable");
    }
    map_wants_save_disable.m_pConVar->SetValue_2(this: map_wants_save_disable.m_pConVar, a2: 0);
    demoplayer->StopPlayback(this: demoplayer);
    demorecorder->StopRecording(this: demorecorder);
    S_StopAllSounds(bClear: true);
    R_DecalTermAll();
    if ( this->m_nMaxClients > 1 )
    {
      v3 = EngineVGui();
      if ( !v3->IsConsoleVisible(this: v3) )
      {
        v4 = EngineVGui();
        v4->EnabledProgressBarForNextLoad(this: v4);
      }
    }
    CL_ClearState();
    CL_HTTPStop_f();
    if ( bShowMainMenu )
      SCR_EndLoadingPlaque();
    v5 = EngineVGui();
    v5->NotifyOfServerDisconnect(this: v5);
    HostState_OnClientDisconnected();
    if ( GetBaseLocalClient()->demonum != -1 )
      CL_NextDemo();
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6760
// Name: public: virtual bool CClientState::ProcessTick(class NET_Tick __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessTick(CClientState *this, NET_Tick *msg)
{
  int m_nTick; // esi

  m_nTick = msg->m_nTick;
  (*((void (__thiscall **)(IServerMessageHandler_vtbl *, float, float))this->dtr_INetMessageHandler + 68))(
    a1: this->CBaseClientState::IServerMessageHandler::INetMessageHandler::__vftable,
    a2: msg->m_flHostFrameTime,
    a3: msg->m_flHostFrameTimeStdDeviation);
  CClockDriftMgr::SetServerTick(this: (CClockDriftMgr *)&this->m_nServerCount, nTick: m_nTick);
  *(float *)&this->m_ClientFramePool.m_BlobHead.m_NumBytes = (float)m_nTick * host_state.interval_per_tick;
  g_ClientGlobalVariables.curtime = (float)m_nTick * host_state.interval_per_tick;
  g_ClientGlobalVariables.tickcount = m_nTick;
  g_ClientGlobalVariables.frametime = (float)(m_nTick - LODWORD(this->m_flLastServerTickTime))
                                    * host_state.interval_per_tick;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D67F0
// Name: public: virtual bool CClientState::ProcessStringCmd(class NET_StringCmd __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessStringCmd(CClientState *this, NET_StringCmd *msg)
{
  return CBaseClientState::InternalProcessStringCmd(
           this: (CClientState *)((char *)this - 8),
           msg,
           bIsHLTV: this->m_nSoundSequence);
}

//------------------------------------------------------------------------------
// Address: 0x101D6810
// Name: public: virtual bool CClientState::ProcessServerInfo(class SVC_ServerInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessServerInfo(CClientState *this, SVC_ServerInfo *msg)
{
  int v4; // ecx
  float m_fTickInterval; // xmm0_4
  int v6; // [esp+Ch] [ebp-Ch]

  CL_ClearState();
  if ( CBaseClientState::ProcessServerInfo(this, a2: (int)this, msg) == 0 )
  {
    (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 2) + 64))(a1: (char *)this - 8, a2: 1);
    return 0;
  }
  if ( demoplayer->IsPlayingBack(this: demoplayer) )
    LODWORD(this->m_flNextCmdTime) = gHostSpawnCount;
  else
    demorecorder->SetSignonState(this: demorecorder, a2: 3);
  LOBYTE(this->m_nSoundSequence) = msg->m_bIsHLTV;
  v4 = *(_DWORD *)&this->m_szLastLevelNameShort[32];
  this->m_nLastProgressPercent = msg->m_nMapCRC;
  *(_DWORD *)&this->ishltv = msg->m_nClientCRC;
  g_ClientGlobalVariables.maxClients = v4;
  g_ClientGlobalVariables.network_protocol = msg->m_nProtocol;
  v6 = *(_DWORD *)&this->m_szLastLevelNameShort[32];
  *(_DWORD *)&this->m_szEncryptionKey[2044] = networkStringTableContainerClient;
  CL_ReallocateDynamicData(maxclients: v6);
  m_fTickInterval = msg->m_fTickInterval;
  if ( sv.m_State == ss_paused )
  {
    if ( m_fTickInterval != host_state.interval_per_tick )
    {
      Host_Error(error: "Expecting interval_per_tick %f, got %f\n", host_state.interval_per_tick, m_fTickInterval);
      return 0;
    }
  }
  else
  {
    host_state.interval_per_tick = msg->m_fTickInterval;
  }
  ClientDLL_HudVidInit();
  gHostSpawnCount = LODWORD(this->m_flNextCmdTime);
  videomode->MarkClientViewRectDirty(this: videomode);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D6930
// Name: public: virtual bool CClientState::ProcessClassInfo(class SVC_ClassInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessClassInfo(CClientState *this, SVC_ClassInfo *msg)
{
  IDemoRecorder_vtbl *v3; // edi
  ServerClass *v4; // eax
  const CStandardSendProxies *v5; // eax

  if ( msg->m_bCreateOnClient )
  {
    if ( !demoplayer->IsPlayingBack(this: demoplayer) )
    {
      DataTable_CreateClientTablesFromServerTables();
      DataTable_CreateClientClassInfosFromServerClasses(pState: (CClientState *)((char *)this - 8));
      v3 = demorecorder->__vftable;
      v4 = serverGameDLL->GetAllServerClasses(this: serverGameDLL);
      v3->RecordServerClasses(this: demorecorder, a2: v4);
    }
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 2) + 100))(a1: (char *)this - 8);
  }
  else
  {
    CBaseClientState::ProcessClassInfo(this, msg);
  }
  v5 = serverGameDLL->GetStandardSendProxies(this: serverGameDLL);
  if ( RecvTable_CreateDecoders(pSendProxies: v5) )
  {
    if ( !demoplayer->IsPlayingBack(this: demoplayer) )
      CLocalNetworkBackdoor::InitFastCopy();
    return 1;
  }
  else
  {
    Host_EndGame(bShowMainMenu: true, message: "CL_ParseClassInfo_EndClasses: CreateDecoders failed.\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D69F0
// Name: public: virtual bool CClientState::ProcessSetPause(class SVC_SetPause __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessSetPause(CClientState *this, SVC_SetPause *msg)
{
  CBaseClientState::ProcessSetPause(this, msg);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D6A10
// Name: public: virtual bool CClientState::ProcessVoiceInit(class SVC_VoiceInit __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessVoiceInit(CClientState *this, SVC_VoiceInit *msg)
{
  if ( *msg->m_szVoiceCodec != 0 )
    Voice_Init(pCodecName: msg->m_szVoiceCodec);
  else
    Voice_Deinit();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D6A40
// Name: public: virtual bool CClientState::ProcessPrefetch(class SVC_Prefetch __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessPrefetch(CClientState *this, SVC_Prefetch *msg)
{
  CClientState *BaseLocalClient; // eax
  const char *SoundName; // eax
  const char *v4; // esi
  IEngineSound *v5; // eax
  int m_nSoundIndex; // [esp-4h] [ebp-8h]

  m_nSoundIndex = msg->m_nSoundIndex;
  BaseLocalClient = GetBaseLocalClient();
  SoundName = CClientState::GetSoundName(this: BaseLocalClient, index: m_nSoundIndex);
  v4 = SoundName;
  if ( SoundName != nullptr && *SoundName != 0 )
  {
    v5 = EngineSoundClient();
    v5->PrefetchSound(this: v5, a2: v4);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D6A80
// Name: public: virtual bool CClientState::ProcessCrosshairAngle(class SVC_CrosshairAngle __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessCrosshairAngle(CClientState *this, SVC_CrosshairAngle *msg)
{
  g_ClientDLL->SetCrosshairAngle(this: g_ClientDLL, a2: &msg->m_Angle);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D6AA0
// Name: public: virtual bool CClientState::ProcessBSPDecal(class SVC_BSPDecal __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessBSPDecal(CClientState *this, SVC_BSPDecal *msg)
{
  model_t *Model; // eax
  IMaterial *v3; // ecx
  const char *v4; // eax

  if ( msg->m_nEntityIndex != 0 )
  {
    Model = CClientState::GetModel(this: (CClientState *)((char *)this - 8), index: msg->m_nModelIndex);
    if ( Model == nullptr )
    {
LABEL_3:
      v3 = Draw_DecalMaterial(index: msg->m_nDecalTextureIndex);
      v4 = "???";
      if ( v3 != nullptr )
        v4 = (const char *)v3->GetName(this: v3);
      _Warning(
        a1: "Warning! Static BSP decal (%s), on NULL model index %i for entity index %i.\n",
        v4,
        msg->m_nModelIndex,
        msg->m_nEntityIndex);
      return 1;
    }
  }
  else
  {
    Model = host_state.worldmodel;
    if ( host_state.worldmodel == nullptr )
    {
      _Warning(a1: "ProcessBSPDecal:  Trying to project on world before host_state.worldmodel is set!!!\n");
      goto LABEL_3;
    }
  }
  if ( r_decals.m_pParent != nullptr && r_decals.m_pParent->m_Value.m_nValue != 0 )
    g_pEfx->DecalShoot(
      this: g_pEfx,
      a2: msg->m_nDecalTextureIndex,
      a3: msg->m_nEntityIndex,
      a4: Model,
      a5: &vec3_origin,
      a6: &vec3_angle,
      a7: &msg->m_Pos,
      a8: nullptr,
      a9: !msg->m_bLowPriority,
      a10: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D6B60
// Name: public: virtual bool CClientState::ProcessGameEvent(class SVC_GameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessGameEvent(CClientState *this, SVC_GameEvent *msg)
{
  const unsigned int *m_pData; // eax
  int m_nDataBits; // edi
  IGameEvent *v4; // eax
  const unsigned int *v5; // ecx

  m_pData = msg->m_DataIn.m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = 32 * (msg->m_DataIn.m_pDataIn - m_pData)
                - msg->m_DataIn.m_nBitsAvail
                + 8 * (msg->m_DataIn.m_nDataBytes & 3);
    if ( m_nDataBits >= msg->m_DataIn.m_nDataBits )
      m_nDataBits = msg->m_DataIn.m_nDataBits;
  }
  else
  {
    m_nDataBits = 0;
  }
  v4 = g_GameEventManager->UnserializeEvent(this: g_GameEventManager, a2: &msg->m_DataIn);
  v5 = msg->m_DataIn.m_pData;
  if ( v5 != nullptr )
  {
    v5 = (const unsigned int *)(32 * (msg->m_DataIn.m_pDataIn - v5)
                              - msg->m_DataIn.m_nBitsAvail
                              + 8 * (msg->m_DataIn.m_nDataBytes & 3));
    if ( (int)v5 >= msg->m_DataIn.m_nDataBits )
      v5 = (const unsigned int *)msg->m_DataIn.m_nDataBits;
  }
  if ( (const unsigned int *)((char *)v5 - m_nDataBits) == (const unsigned int *)msg->m_nLength )
  {
    if ( v4 != nullptr )
      g_GameEventManager->FireEventClientSide(this: g_GameEventManager, a2: v4);
    else
      DevMsg(a1: "CClientState::ProcessGameEvent: UnserializeKeyValue failed.\n");
    return 1;
  }
  else
  {
    DevMsg(a1: "CClientState::ProcessGameEvent: KeyValue length mismatch.\n");
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6C30
// Name: public: virtual bool CClientState::ProcessUserMessage(class SVC_UserMessage __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessUserMessage(CClientState *this, SVC_UserMessage *msg)
{
  unsigned int userdata[128]; // [esp+4h] [ebp-224h] BYREF
  bf_read userMsg; // [esp+204h] [ebp-24h] BYREF

  memset(userdata, 0, 511);
  userMsg.m_bOverflow = false;
  userMsg.m_nDataBits = -1;
  userMsg.m_nDataBytes = 0;
  userMsg.m_pDebugName = "UserMessage(read)";
  CBitRead::StartReading(this: &userMsg, pData: userdata, nBytes: 0x1FFu, iStartBit: 0, nBits: -1);
  CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: (char *)userdata, nBits: msg->m_nLength);
  CBitRead::StartReading(this: &userMsg, pData: userdata, nBytes: (msg->m_nLength + 7) >> 3, iStartBit: 0, nBits: -1);
  if ( g_ClientDLL->DispatchUserMessage(this: g_ClientDLL, a2: msg->m_nMsgType, a3: &userMsg) )
    return 1;
  ConMsg(a1: "Couldn't dispatch user message (%i)\n", msg->m_nMsgType);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D6D00
// Name: public: virtual bool CClientState::ProcessPacketEntities(class SVC_PacketEntities __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessPacketEntities(CClientState *this, SVC_PacketEntities *msg)
{
  char result; // al

  CL_PreprocessEntities();
  if ( msg->m_bIsDelta )
  {
    if ( this->m_ClockDriftMgr.m_nServerTick == -1 )
      return 1;
  }
  else
  {
    demorecorder->SetSignonState(this: demorecorder, a2: 6);
    if ( g_pClientSidePrediction != nullptr )
      g_pClientSidePrediction->OnReceivedUncompressedPacket(this: g_pClientSidePrediction);
  }
  if ( g_pLocalNetworkBackdoor != nullptr )
  {
    if ( LODWORD(this->m_ListenServerSteamID) == 5 )
      (*(void (__thiscall **)(char *, int, _DWORD, _DWORD))(*((_DWORD *)this - 2) + 60))(
        a1: (char *)this - 8,
        a2: 6,
        a3: LODWORD(this->m_flNextCmdTime),
        a4: 0);
    this->m_ClockDriftMgr.m_nServerTick = LODWORD(this->m_ClockDriftMgr.m_ClockOffsets[15]);
    return 1;
  }
  result = CL_ProcessPacketEntities(entmsg: msg);
  if ( result != 0 )
    return CBaseClientState::ProcessPacketEntities(this, msg);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D6DA0
// Name: public: virtual void CClientState::FileRequested(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::FileRequested(
        CClientState *this,
        const char *fileName,
        unsigned int transferID,
        BOOL isReplayDemoFile)
{
  const char *v5; // eax

  v5 = this->m_NetChannel->GetAddress(this: this->m_NetChannel);
  ConMsg(a1: "File '%s' requested from server %s.\n", fileName, v5);
  if ( cl_allowupload.m_pParent != nullptr && cl_allowupload.m_pParent->m_Value.m_nValue != 0 )
  {
    this->m_NetChannel->SendFile(this: this->m_NetChannel, a2: fileName, a3: transferID, a4: isReplayDemoFile);
  }
  else
  {
    ConMsg(a1: "File uploading disabled.\n");
    this->m_NetChannel->DenyFile(this: this->m_NetChannel, a2: fileName, a3: transferID, a4: isReplayDemoFile);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6E20
// Name: public: virtual bool CClientState::ProcessVoiceData(class SVC_VoiceData __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessVoiceData(CClientState *this, SVC_VoiceData *msg)
{
  int m_nLength; // eax
  unsigned int v3; // edi
  int v4; // esi
  char *m_pszString; // eax
  char *v6; // eax
  int Channel; // eax
  char pchData[12]; // [esp+10h] [ebp-1094h] BYREF
  _BYTE v10[8]; // [esp+1010h] [ebp-94h] BYREF
  char v11[12]; // [esp+1018h] [ebp-8Ch] BYREF
  int *v12; // [esp+10A0h] [ebp-4h]

  m_nLength = msg->m_nLength;
  v3 = (m_nLength + 7) >> 3;
  v12 = (int *)this;
  if ( v3 >= 0x1000 )
    v3 = 4096;
  CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: pchData, nBits: m_nLength);
  if ( voice_debugfeedback.m_pParent != nullptr && voice_debugfeedback.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "Received voice from: %d\n", msg->m_nFromClient + 1);
  v4 = msg->m_nFromClient + 1;
  if ( v4 == v12[52] + 1 )
    Voice_LocalPlayerTalkingAck(iSsSlot: v12[53]);
  engineClient->GetPlayerInfo(this: engineClient, a2: v4, a3: (player_info_s *)v10);
  if ( (cl_voice_filter.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = cl_voice_filter.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  if ( _V_strlen(str: m_pszString) <= 0 )
    goto LABEL_28;
  if ( (cl_voice_filter.m_nFlags & 0x1000) != 0 )
  {
    v6 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    v6 = cl_voice_filter.m_pParent->m_Value.m_pszString;
    if ( v6 == nullptr )
      v6 = (char *)defaultValue;
  }
  if ( _V_strstr(s1: v11, search: v6) != nullptr )
  {
LABEL_28:
    if ( v3 != 0 && Voice_Enabled() )
    {
      Channel = Voice_GetChannel(nEntity: v4);
      if ( Channel == -1
        && (Channel = Voice_AssignChannel(nEntity: v4, bProximity: msg->m_bProximity, timePadding: 0.2)) == -1 )
      {
        if ( S_IsInitted() )
        {
          _ConDMsg(a1: "ProcessVoiceData: Voice_AssignChannel failed for client %d!\n", v4 - 1);
          return 1;
        }
      }
      else
      {
        Voice_AddIncomingData(nChannel: Channel, pchData, nCount: v3, iSequenceNumber: v12[29], isCompressed: true);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D6FA0
// Name: public: virtual bool CClientState::ProcessSounds(class SVC_Sounds __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClientState::ProcessSounds(CClientState *this, SVC_Sounds *msg)
{
  bf_read *p_m_DataIn; // esi
  const unsigned int *m_pData; // eax
  SoundInfo_t *p_defaultSound; // edx
  int m_nDataBits; // ecx
  int v7; // eax
  const unsigned int *v8; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // esi
  int v14; // eax
  SoundInfo_t defaultSound; // [esp+0h] [ebp-C4h] BYREF
  SoundInfo_t sound; // [esp+5Ch] [ebp-68h] BYREF
  SoundInfo_t *pDeltaSound; // [esp+B8h] [ebp-Ch]
  CClientState *v18; // [esp+BCh] [ebp-8h]
  int i; // [esp+C0h] [ebp-4h]
  int startbit; // [esp+CCh] [ebp+8h]

  defaultSound.Soundlevel = SNDLVL_NORM;
  sound.Soundlevel = SNDLVL_NORM;
  defaultSound.nPitch = 100;
  sound.nPitch = 100;
  p_m_DataIn = &msg->m_DataIn;
  defaultSound.nChannel = 6;
  sound.nChannel = 6;
  m_pData = msg->m_DataIn.m_pData;
  v18 = this;
  memset(&defaultSound.fDelay, 0, 16);
  defaultSound.fVolume = 1.0;
  defaultSound.nSpeakerEntity = -1;
  defaultSound.nSoundNum = 0;
  defaultSound.nFlags = 0;
  defaultSound.nRandomSeed = 0;
  defaultSound.bLooping = false;
  *(_WORD *)&defaultSound.bIsSentence = 0;
  memset(&defaultSound, 0, 40);
  p_defaultSound = &defaultSound;
  memset(&sound.fDelay, 0, 16);
  sound.fVolume = 1.0;
  sound.nSpeakerEntity = -1;
  sound.nSoundNum = 0;
  sound.nFlags = 0;
  sound.nRandomSeed = 0;
  sound.bLooping = false;
  *(_WORD *)&sound.bIsSentence = 0;
  memset(&sound, 0, 40);
  if ( m_pData != nullptr )
  {
    m_nDataBits = msg->m_DataIn.m_nDataBits;
    startbit = 32 * (msg->m_DataIn.m_pDataIn - m_pData)
             - msg->m_DataIn.m_nBitsAvail
             + 8 * (msg->m_DataIn.m_nDataBytes & 3);
    if ( startbit >= m_nDataBits )
      startbit = m_nDataBits;
  }
  else
  {
    startbit = 0;
  }
  i = 0;
  if ( msg->m_nNumSounds > 0 )
  {
    while ( 1 )
    {
      SoundInfo_t::ReadDelta(this: &sound, delta: p_defaultSound, buffer: p_m_DataIn);
      pDeltaSound = &sound;
      if ( msg->m_bReliableSound )
      {
        v7 = ((unsigned __int16)v18->last_server_tick + 1) & 0x3FF;
        v18->last_server_tick = v7;
        sound.nSequenceNumber = v7;
      }
      CL_AddSound(&sound);
      if ( ++i >= msg->m_nNumSounds )
        break;
      p_defaultSound = pDeltaSound;
    }
  }
  v8 = p_m_DataIn->m_pData;
  if ( v8 == nullptr )
    return msg->m_nLength == -startbit;
  v10 = (char *)p_m_DataIn->m_pDataIn - (char *)v8;
  v11 = 2 * (p_m_DataIn->m_nDataBytes & 3);
  v12 = 32 * (v10 >> 2) - p_m_DataIn->m_nBitsAvail;
  v13 = p_m_DataIn->m_nDataBits;
  v14 = v12 + 4 * v11;
  if ( v14 >= v13 )
    v14 = v13;
  return msg->m_nLength == v14 - startbit;
}

//------------------------------------------------------------------------------
// Address: 0x101D7250
// Name: public: class SVC_EntityMessage __near & SVC_EntityMessage::operator=(class SVC_EntityMessage const __near &)
// Source: json
//------------------------------------------------------------------------------
SVC_EntityMessage *__thiscall SVC_EntityMessage::operator=(SVC_EntityMessage *this, const SVC_EntityMessage *__that)
{
  this->m_bReliable = __that->m_bReliable;
  this->m_NetChannel = __that->m_NetChannel;
  this->m_pMessageHandler = __that->m_pMessageHandler;
  this->m_nEntityIndex = __that->m_nEntityIndex;
  this->m_nClassID = __that->m_nClassID;
  this->m_nLength = __that->m_nLength;
  qmemcpy(&this->m_DataIn, &__that->m_DataIn, 0x3Cu);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D7500
// Name: public: virtual bool CClientState::ProcessPaintmapData(class SVC_PaintmapData __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessPaintmapData(CClientState *this, unsigned int msg)
{
  SVC_PaintmapData *v2; // edi
  int v3; // esi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > data; // [esp+Ch] [ebp-14h] BYREF

  v2 = (SVC_PaintmapData *)msg;
  v3 = (((*(_DWORD *)(msg + 16) + 7) >> 3) + 3) / 4;
  memset(&data, 0, sizeof(data));
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&data,
    elem: 0,
    num: v3);
  CBitRead::ReadBits(this: &v2->m_DataIn, pOutData: (char *)data.m_Memory.m_pMemory, nBits: v2->m_nLength);
  msg |= 3u;
  CByteswap::SwapBufferToTargetEndian<unsigned int>(
    this: (CByteswap *)&msg,
    outputBuffer: (int *)data.m_Memory.m_pMemory,
    inputBuffer: (int *)data.m_Memory.m_pMemory,
    count: v3);
  if ( data.m_Size > 0 )
    CPaintmapDataManager::LoadPaintmapDataRLE(this: &g_PaintManager, &data);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&data);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D7590
// Name: public: virtual bool CClientState::ProcessFixAngle(class SVC_FixAngle __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessFixAngle(CClientState *this, SVC_FixAngle *msg)
{
  float y; // xmm2_4
  float z; // xmm2_4
  float v4; // xmm0_4
  float v5; // eax
  CUtlMemory<ResourceEntryInfo,int> *p_y; // esi
  int m_nAllocationCount; // edi
  ResourceEntryInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // eax
  int a_4; // [esp+4h] [ebp-4h]

  if ( msg->m_Angle.x > 180.0 )
    msg->m_Angle.x = msg->m_Angle.x - 360.0;
  y = msg->m_Angle.y;
  if ( y > 180.0 )
    msg->m_Angle.y = y - 360.0;
  z = msg->m_Angle.z;
  if ( z > 180.0 )
    msg->m_Angle.z = z - 360.0;
  if ( msg->m_bRelative )
  {
    v4 = *(float *)&this->addangle.m_Size + msg->m_Angle.y;
    *(float *)&this->addangle.m_Size = v4;
    v5 = this->viewangles.z;
    p_y = (CUtlMemory<ResourceEntryInfo,int> *)&this->viewangles.y;
    m_nAllocationCount = this->addangle.m_Memory.m_nAllocationCount;
    a_4 = this->m_ClientFramePool.m_BlobHead.m_NumBytes;
    if ( m_nAllocationCount + 1 > SLODWORD(v5) )
      CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(this: p_y, num: m_nAllocationCount - LODWORD(v5) + 1);
    ++p_y[1].m_pMemory;
    m_pMemory = p_y->m_pMemory;
    v9 = (int)p_y[1].m_pMemory - m_nAllocationCount - 1;
    p_y[1].m_nAllocationCount = (int)p_y->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_nAllocationCount + 1], src: &m_pMemory[m_nAllocationCount], count: 8 * v9);
    v10 = (int)&p_y->m_pMemory[m_nAllocationCount];
    if ( v10 != 0 )
    {
      *(float *)v10 = v4;
      *(_DWORD *)(v10 + 4) = a_4;
      return 1;
    }
  }
  else
  {
    *(QAngle *)&this->m_chAreaPortalBits[20] = msg->m_Angle;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D76B0
// Name: public: virtual bool CClientState::ProcessEntityMessage(class SVC_EntityMessage __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessEntityMessage(CClientState *this, SVC_EntityMessage *msg)
{
  int v3; // ebx
  int v4; // edi
  IMDLCache *v6; // edi
  unsigned int entityData[64]; // [esp+Ch] [ebp-124h] BYREF
  bf_read entMsg; // [esp+10Ch] [ebp-24h] BYREF

  v3 = entitylist->GetClientNetworkable(this: entitylist, a2: msg->m_nEntityIndex);
  if ( v3 != 0 )
  {
    v6 = g_pMDLCache;
    g_pMDLCache->BeginLock(this: g_pMDLCache);
    memset(entityData, 0, 255);
    entMsg.m_bOverflow = false;
    entMsg.m_nDataBits = -1;
    entMsg.m_nDataBytes = 0;
    entMsg.m_pDebugName = "EntityMessage(read)";
    CBitRead::StartReading(this: &entMsg, pData: entityData, nBytes: 0xFFu, iStartBit: 0, nBits: -1);
    CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: (char *)entityData, nBits: msg->m_nLength);
    CBitRead::StartReading(this: &entMsg, pData: entityData, nBytes: (msg->m_nLength + 7) >> 3, iStartBit: 0, nBits: -1);
    (*(void (__thiscall **)(int, int, bf_read *))(*(_DWORD *)v3 + 44))(a1: v3, a2: msg->m_nClassID, a3: &entMsg);
    v6->EndLock(this: v6);
  }
  else
  {
    v4 = *(_DWORD *)&this->demos[31][24]
       + 348
       * CUtlVector<CQueuedEntityMessage,CUtlMemory<CQueuedEntityMessage,int>>::InsertBefore(
           this: (CUtlVector<CQueuedEntityMessage,CUtlMemory<CQueuedEntityMessage,int> > *)&this->demos[31][24],
           elem: this->queuedmessage.m_Memory.m_nAllocationCount);
    *(_DWORD *)(v4 + 344) = msg->m_nEntityIndex;
    SVC_EntityMessage::operator=(this: (SVC_EntityMessage *)v4, __that: msg);
    v4 += 88;
    _V_memset(dest: (void *)v4, fill: 0, count: 255);
    CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: (char *)v4, nBits: msg->m_nLength);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D77F0
// Name: public: virtual bool CClientState::ProcessTempEntities(class SVC_TempEntities __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessTempEntities(CClientState *this, SVC_TempEntities *msg)
{
  CClientState *BaseLocalClient; // eax
  bool v4; // cl
  bf_read *p_m_DataIn; // esi
  unsigned int m_nInBufWord; // eax
  int v7; // edx
  bool v8; // zf
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  int v11; // ecx
  unsigned int v12; // eax
  char v13; // dl
  int v14; // ecx
  char v15; // bl
  const unsigned int *v16; // eax
  const unsigned int *v17; // ecx
  const unsigned int *v18; // edx
  unsigned int v19; // ebx
  int v20; // eax
  const unsigned int *v21; // ecx
  unsigned int v22; // edx
  unsigned int v23; // edi
  unsigned int v24; // eax
  int v25; // edx
  const unsigned int *v26; // eax
  const unsigned int *v27; // ecx
  int m_pServerClasses; // eax
  int m_nBitsAvail; // ecx
  unsigned int v30; // edx
  unsigned int v31; // ebx
  int v32; // ecx
  unsigned int v33; // edx
  const unsigned int *v34; // eax
  const unsigned int *v35; // ecx
  const unsigned int *v36; // edx
  unsigned int v37; // ebx
  int v38; // eax
  const unsigned int *v39; // ecx
  int v40; // eax
  unsigned int v41; // edx
  unsigned int v42; // edi
  PackedEntity *v43; // ecx
  int v44; // ebx
  ClientClass *ClientClass; // eax
  RecvTable *m_pRecvTable; // eax
  CClientState *v47; // ebx
  int v48; // eax
  int v49; // edi
  int v50; // eax
  int v51; // eax
  int m_Tail; // eax
  int v53; // edx
  ClientClass *v54; // eax
  float v55; // xmm0_4
  int v56; // ebx
  void *v57; // eax
  unsigned __int8 *pData; // [esp-10h] [ebp-13Ch]
  unsigned int v60; // [esp-Ch] [ebp-138h]
  unsigned __int8 data[192]; // [esp+Ch] [ebp-120h] BYREF
  bf_read fromBuf; // [esp+CCh] [ebp-60h] BYREF
  bf_write toBuf; // [esp+F0h] [ebp-3Ch] BYREF
  int flags; // [esp+108h] [ebp-24h]
  CEventInfo *ei; // [esp+10Ch] [ebp-20h]
  CClientState *v66; // [esp+110h] [ebp-1Ch]
  float delay; // [esp+114h] [ebp-18h]
  int i; // [esp+118h] [ebp-14h]
  int classID; // [esp+11Ch] [ebp-10h]
  ClientClass *pClientClass; // [esp+120h] [ebp-Ch]
  float fire_time; // [esp+124h] [ebp-8h]
  bool bReliable; // [esp+12Bh] [ebp-1h]

  v66 = this;
  bReliable = false;
  BaseLocalClient = GetBaseLocalClient();
  fire_time = CClientState::GetTime(this: BaseLocalClient);
  if ( GetBaseLocalClient()->m_nMaxClients > 1 || demoplayer->IsPlayingBack(this: demoplayer) )
    fire_time = CClientState::GetClientInterpAmount(this: (CClientState *)((char *)this - 8)) + fire_time;
  if ( msg->m_nNumEntries != 0 )
  {
    v4 = bReliable;
  }
  else
  {
    v4 = true;
    msg->m_nNumEntries = 1;
  }
  flags = v4 ? 2 : 0;
  if ( v4 || !demoplayer->IsSkipping(this: demoplayer) )
  {
    p_m_DataIn = &msg->m_DataIn;
    classID = -1;
    pClientClass = nullptr;
    bf_write::bf_write(this: &toBuf, pData: data, nBytes: 192, nBits: -1);
    ei = nullptr;
    i = 0;
    if ( msg->m_nNumEntries > 0 )
    {
      while ( 1 )
      {
        m_nInBufWord = msg->m_DataIn.m_nInBufWord;
        v7 = m_nInBufWord & 1;
        v8 = msg->m_DataIn.m_nBitsAvail-- == 1;
        delay = 0.0;
        if ( v8 )
        {
          m_pDataIn = msg->m_DataIn.m_pDataIn;
          m_pBufferEnd = msg->m_DataIn.m_pBufferEnd;
          msg->m_DataIn.m_nBitsAvail = 32;
          if ( m_pDataIn == m_pBufferEnd )
          {
            msg->m_DataIn.m_nBitsAvail = 1;
            msg->m_DataIn.m_nInBufWord = 0;
            msg->m_DataIn.m_pDataIn = m_pDataIn + 1;
          }
          else if ( m_pDataIn <= m_pBufferEnd )
          {
            msg->m_DataIn.m_nInBufWord = *m_pDataIn;
            msg->m_DataIn.m_pDataIn = m_pDataIn + 1;
          }
          else
          {
            msg->m_DataIn.m_bOverflow = true;
            msg->m_DataIn.m_nInBufWord = 0;
          }
        }
        else
        {
          msg->m_DataIn.m_nInBufWord = m_nInBufWord >> 1;
        }
        if ( v7 != 0 )
          break;
LABEL_37:
        bf_write::Reset(this: &toBuf);
        v24 = msg->m_DataIn.m_nInBufWord;
        v25 = v24 & 1;
        v8 = msg->m_DataIn.m_nBitsAvail-- == 1;
        if ( v8 )
        {
          v26 = msg->m_DataIn.m_pDataIn;
          v27 = msg->m_DataIn.m_pBufferEnd;
          msg->m_DataIn.m_nBitsAvail = 32;
          if ( v26 == v27 )
          {
            msg->m_DataIn.m_nBitsAvail = 1;
            msg->m_DataIn.m_nInBufWord = 0;
            msg->m_DataIn.m_pDataIn = v26 + 1;
          }
          else if ( v26 <= v27 )
          {
            msg->m_DataIn.m_nInBufWord = *v26;
            msg->m_DataIn.m_pDataIn = v26 + 1;
          }
          else
          {
            msg->m_DataIn.m_bOverflow = true;
            msg->m_DataIn.m_nInBufWord = 0;
          }
        }
        else
        {
          msg->m_DataIn.m_nInBufWord = v24 >> 1;
        }
        if ( v25 == 0 )
        {
          v60 = (ei->bits + 7) >> 3;
          pData = ei->pData;
          fromBuf.m_bOverflow = false;
          fromBuf.m_pDebugName = nullptr;
          fromBuf.m_nDataBits = -1;
          fromBuf.m_nDataBytes = 0;
          CBitRead::StartReading(this: &fromBuf, (const unsigned int *)pData, nBytes: v60, iStartBit: 0, nBits: -1);
          RecvTable_MergeDeltas(
            pTable: pClientClass->m_pRecvTable,
            pOldState: &fromBuf,
            pNewState: p_m_DataIn,
            pOut: &toBuf,
            objectID: -1,
            bDebugWatchInfo: false,
            pChangedProps: nullptr);
          goto LABEL_70;
        }
        m_pServerClasses = (int)v66->m_pServerClasses;
        m_nBitsAvail = msg->m_DataIn.m_nBitsAvail;
        if ( m_nBitsAvail < m_pServerClasses )
        {
          v36 = msg->m_DataIn.m_pBufferEnd;
          v37 = msg->m_DataIn.m_nInBufWord;
          v38 = m_pServerClasses - m_nBitsAvail;
          v39 = msg->m_DataIn.m_pDataIn;
          if ( v39 == v36 )
          {
            msg->m_DataIn.m_nBitsAvail = 1;
            msg->m_DataIn.m_nInBufWord = 0;
            msg->m_DataIn.m_bOverflow = true;
            goto LABEL_58;
          }
          if ( v39 <= v36 )
          {
            msg->m_DataIn.m_nInBufWord = *v39;
LABEL_58:
            msg->m_DataIn.m_pDataIn = v39 + 1;
          }
          else
          {
            msg->m_DataIn.m_bOverflow = true;
            msg->m_DataIn.m_nInBufWord = 0;
          }
          if ( msg->m_DataIn.m_bOverflow )
          {
            v40 = 0;
            goto LABEL_64;
          }
          v41 = msg->m_DataIn.m_nInBufWord;
          v42 = (v41 & CBitBuffer::s_nMaskTable[v38]) << msg->m_DataIn.m_nBitsAvail;
          msg->m_DataIn.m_nBitsAvail = 32 - v38;
          v31 = v42 | v37;
          v33 = v41 >> v38;
          goto LABEL_62;
        }
        v30 = msg->m_DataIn.m_nInBufWord;
        v31 = v30 & CBitBuffer::s_nMaskTable[m_pServerClasses];
        v32 = m_nBitsAvail - m_pServerClasses;
        msg->m_DataIn.m_nBitsAvail = v32;
        if ( v32 == 0 )
        {
          v34 = msg->m_DataIn.m_pDataIn;
          v35 = msg->m_DataIn.m_pBufferEnd;
          msg->m_DataIn.m_nBitsAvail = 32;
          if ( v34 == v35 )
          {
            msg->m_DataIn.m_nBitsAvail = 1;
            msg->m_DataIn.m_nInBufWord = 0;
            msg->m_DataIn.m_pDataIn = v34 + 1;
          }
          else if ( v34 <= v35 )
          {
            msg->m_DataIn.m_nInBufWord = *v34;
            msg->m_DataIn.m_pDataIn = v34 + 1;
          }
          else
          {
            msg->m_DataIn.m_bOverflow = true;
            msg->m_DataIn.m_nInBufWord = 0;
          }
          goto LABEL_63;
        }
        v33 = v30 >> m_pServerClasses;
LABEL_62:
        msg->m_DataIn.m_nInBufWord = v33;
LABEL_63:
        v40 = v31;
LABEL_64:
        v43 = v66->m_pEntityBaselines[1][2046];
        classID = v40;
        if ( v43 == nullptr
          || (v44 = (int)v43 + 16 * v40 - 16, (PackedEntity *)((char *)v43 + 16 * v40) == (PackedEntity *)16) )
        {
          DevMsg(a1: "CL_QueueEvent: missing server class info for %i.\n", v40 - 1);
          return 0;
        }
        ClientClass = CBaseClientState::FindClientClass(pClassName: *(const char **)(v44 + 4));
        pClientClass = ClientClass;
        if ( ClientClass == nullptr || (m_pRecvTable = ClientClass->m_pRecvTable) == nullptr )
        {
          DevMsg(a1: "CL_QueueEvent: missing client receive table for %s.\n", *(const char **)(v44 + 4));
          return 0;
        }
        RecvTable_MergeDeltas(
          pTable: m_pRecvTable,
          pOldState: nullptr,
          pNewState: p_m_DataIn,
          pOut: &toBuf,
          objectID: -1,
          bDebugWatchInfo: false,
          pChangedProps: nullptr);
LABEL_70:
        v47 = GetBaseLocalClient();
        v48 = CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::AllocInternal(
                this: &v47->events,
                multilist: false);
        v49 = v48;
        if ( v48 != 0 )
        {
          if ( !CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>::IsIdxAfter(
                  this: &v47->events.m_Memory,
                  i: v48,
                  it: &v47->events.m_LastAlloc) )
          {
            v50 = *(_DWORD *)(v49 + 56);
            if ( v50 != v49 )
            {
              if ( v50 != 0 )
                *(_DWORD *)(v50 + 60) = *(_DWORD *)(v49 + 60);
              else
                v47->events.m_Head = *(_DWORD *)(v49 + 60);
              v51 = *(_DWORD *)(v49 + 60);
              if ( v51 != 0 )
                *(_DWORD *)(v51 + 56) = *(_DWORD *)(v49 + 56);
              else
                v47->events.m_Tail = *(_DWORD *)(v49 + 56);
              *(_DWORD *)(v49 + 60) = v49;
              *(_DWORD *)(v49 + 56) = v49;
              --v47->events.m_ElementCount;
            }
          }
          *(_DWORD *)(v49 + 60) = 0;
          m_Tail = v47->events.m_Tail;
          *(_DWORD *)(v49 + 56) = m_Tail;
          v47->events.m_Tail = v49;
          if ( m_Tail != 0 )
            *(_DWORD *)(m_Tail + 60) = v49;
          else
            v47->events.m_Head = v49;
          ++v47->events.m_ElementCount;
          CEngineRecipientFilter::CEngineRecipientFilter(this: (CEngineRecipientFilter *)(v49 + 28));
          *(_WORD *)v49 = 0;
          *(_DWORD *)(v49 + 4) = 0;
          *(_DWORD *)(v49 + 16) = 0;
          *(_DWORD *)(v49 + 24) = 0;
          *(_DWORD *)(v49 + 8) = 0;
          *(_DWORD *)(v49 + 12) = 0;
          *(_DWORD *)(v49 + 20) = 0;
        }
        GetBaseLocalClient();
        v53 = flags;
        v54 = pClientClass;
        v55 = delay + fire_time;
        v56 = toBuf.m_iCurBit + 7;
        *(_WORD *)v49 = classID;
        *(float *)(v49 + 4) = v55;
        *(_DWORD *)(v49 + 24) = v53;
        *(_DWORD *)(v49 + 12) = v54;
        v56 >>= 3;
        ei = (CEventInfo *)v49;
        *(_DWORD *)(v49 + 16) = toBuf.m_iCurBit;
        v57 = MemAlloc_Alloc(nSize: v56);
        *(_DWORD *)(v49 + 20) = v57;
        _V_memcpy(dest: v57, src: data, count: v56);
        if ( ++i >= msg->m_nNumEntries )
          return 1;
      }
      v11 = msg->m_DataIn.m_nBitsAvail;
      if ( v11 >= 8 )
      {
        v12 = msg->m_DataIn.m_nInBufWord;
        v13 = v12;
        v14 = v11 - 8;
        msg->m_DataIn.m_nBitsAvail = v14;
        if ( v14 != 0 )
        {
          msg->m_DataIn.m_nInBufWord = v12 >> 8;
          v15 = v12;
        }
        else
        {
          v16 = msg->m_DataIn.m_pDataIn;
          v17 = msg->m_DataIn.m_pBufferEnd;
          msg->m_DataIn.m_nBitsAvail = 32;
          if ( v16 == v17 )
          {
            msg->m_DataIn.m_nBitsAvail = 1;
            msg->m_DataIn.m_nInBufWord = 0;
            msg->m_DataIn.m_pDataIn = v16 + 1;
            v15 = v13;
          }
          else
          {
            if ( v16 <= v17 )
            {
              msg->m_DataIn.m_nInBufWord = *v16;
              msg->m_DataIn.m_pDataIn = v16 + 1;
            }
            else
            {
              msg->m_DataIn.m_bOverflow = true;
              msg->m_DataIn.m_nInBufWord = 0;
            }
            v15 = v13;
          }
        }
        goto LABEL_36;
      }
      v18 = msg->m_DataIn.m_pBufferEnd;
      v19 = msg->m_DataIn.m_nInBufWord;
      v20 = 8 - v11;
      v21 = msg->m_DataIn.m_pDataIn;
      if ( v21 == v18 )
      {
        msg->m_DataIn.m_nBitsAvail = 1;
        msg->m_DataIn.m_nInBufWord = 0;
        msg->m_DataIn.m_bOverflow = true;
      }
      else
      {
        if ( v21 > v18 )
        {
          msg->m_DataIn.m_bOverflow = true;
          msg->m_DataIn.m_nInBufWord = 0;
          goto LABEL_33;
        }
        msg->m_DataIn.m_nInBufWord = *v21;
      }
      msg->m_DataIn.m_pDataIn = v21 + 1;
LABEL_33:
      if ( msg->m_DataIn.m_bOverflow )
      {
        v15 = 0;
      }
      else
      {
        v22 = msg->m_DataIn.m_nInBufWord;
        v23 = (v22 & CBitBuffer::s_nMaskTable[v20]) << msg->m_DataIn.m_nBitsAvail;
        msg->m_DataIn.m_nBitsAvail = 32 - v20;
        v15 = v23 | v19;
        msg->m_DataIn.m_nInBufWord = v22 >> v20;
      }
LABEL_36:
      delay = (float)v15 * 0.0099999998;
      goto LABEL_37;
    }
  }
  return 1;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101D5300
// Name: public: void SoundInfo_t::ReadDelta(struct SoundInfo_t __near *,class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SoundInfo_t::ReadDelta(SoundInfo_t *this, SoundInfo_t *delta, bf_read *buffer)
{
  unsigned int m_nInBufWord; // ecx
  int v6; // edx
  bool v7; // zf
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int v10; // ecx
  int v11; // esi
  const unsigned int *v12; // ecx
  const unsigned int *v13; // edx
  int m_nBitsAvail; // ecx
  unsigned int v15; // edx
  int v16; // edi
  int v17; // ecx
  const unsigned int *v18; // ecx
  const unsigned int *v19; // edx
  int v20; // edx
  unsigned int v21; // edx
  int v22; // ecx
  unsigned int v23; // edx
  const unsigned int *v24; // esi
  unsigned int v25; // edi
  int v26; // edx
  const unsigned int *v27; // ecx
  unsigned int v28; // esi
  unsigned int v29; // ebx
  unsigned int v30; // ecx
  int v31; // esi
  const unsigned int *v32; // ecx
  const unsigned int *v33; // edx
  int v34; // ecx
  unsigned int v35; // edx
  int v36; // edi
  int v37; // ecx
  const unsigned int *v38; // ecx
  const unsigned int *v39; // edx
  SoundInfo_t *v40; // edx
  const unsigned int *v41; // esi
  unsigned int v42; // edi
  int v43; // edx
  const unsigned int *v44; // ecx
  unsigned int v45; // esi
  unsigned int v46; // ebx
  unsigned int v47; // ecx
  int v48; // esi
  const unsigned int *v49; // ecx
  const unsigned int *v50; // edx
  int v51; // ecx
  unsigned int v52; // edx
  int v53; // edi
  int v54; // ecx
  const unsigned int *v55; // ecx
  const unsigned int *v56; // edx
  SoundInfo_t *v57; // edx
  const unsigned int *v58; // esi
  unsigned int v59; // edi
  int v60; // edx
  const unsigned int *v61; // ecx
  unsigned int v62; // esi
  unsigned int v63; // ebx
  unsigned int v64; // ecx
  int v65; // esi
  const unsigned int *v66; // ecx
  const unsigned int *v67; // edx
  int v68; // ecx
  unsigned int v69; // edx
  int v70; // edi
  int v71; // ecx
  const unsigned int *v72; // ecx
  const unsigned int *v73; // edx
  SoundInfo_t *v74; // edx
  const unsigned int *v75; // esi
  unsigned int v76; // edi
  int v77; // edx
  const unsigned int *v78; // ecx
  unsigned int v79; // esi
  unsigned int v80; // ebx
  unsigned int v81; // ecx
  int v82; // edx
  const unsigned int *v83; // ecx
  const unsigned int *v84; // esi
  unsigned int v85; // ecx
  int v86; // edx
  const unsigned int *v87; // ecx
  const unsigned int *v88; // esi
  unsigned int v89; // ecx
  int v90; // esi
  const unsigned int *v91; // ecx
  const unsigned int *v92; // edx
  unsigned int v93; // ecx
  int v94; // esi
  const unsigned int *v95; // ecx
  const unsigned int *v96; // edx
  int v97; // ecx
  unsigned int v98; // edx
  int v99; // edi
  int v100; // ecx
  const unsigned int *v101; // ecx
  const unsigned int *v102; // edx
  unsigned int v103; // edx
  const unsigned int *v104; // esi
  unsigned int v105; // edi
  int v106; // edx
  const unsigned int *v107; // ecx
  unsigned int v108; // esi
  unsigned int v109; // ebx
  unsigned int v110; // ecx
  int v111; // esi
  const unsigned int *v112; // ecx
  const unsigned int *v113; // edx
  int v114; // ecx
  unsigned int v115; // edx
  int v116; // edi
  int v117; // ecx
  const unsigned int *v118; // ecx
  const unsigned int *v119; // edx
  unsigned int v120; // edx
  const unsigned int *v121; // esi
  unsigned int v122; // edi
  int v123; // edx
  const unsigned int *v124; // ecx
  unsigned int v125; // esi
  unsigned int v126; // ebx
  double fVolume; // st7
  unsigned int v128; // ecx
  int v129; // esi
  const unsigned int *v130; // ecx
  const unsigned int *v131; // edx
  int v132; // ecx
  unsigned int v133; // edx
  int v134; // edi
  int v135; // ecx
  const unsigned int *v136; // ecx
  const unsigned int *v137; // edx
  SoundInfo_t *v138; // edx
  const unsigned int *v139; // esi
  unsigned int v140; // edi
  int v141; // edx
  const unsigned int *v142; // ecx
  unsigned int v143; // esi
  unsigned int v144; // ebx
  unsigned int v145; // ecx
  int v146; // esi
  const unsigned int *v147; // ecx
  const unsigned int *v148; // edx
  int v149; // ecx
  unsigned int v150; // edx
  int v151; // edi
  int v152; // ecx
  const unsigned int *v153; // ecx
  const unsigned int *v154; // edx
  SoundInfo_t *v155; // edx
  const unsigned int *v156; // esi
  unsigned int v157; // edi
  int v158; // edx
  const unsigned int *v159; // ecx
  unsigned int v160; // esi
  unsigned int v161; // ebx
  unsigned int v162; // ecx
  int v163; // esi
  const unsigned int *v164; // ecx
  const unsigned int *v165; // edx
  int v166; // ecx
  unsigned int v167; // edx
  int v168; // edi
  int v169; // ecx
  const unsigned int *v170; // ecx
  const unsigned int *v171; // edx
  SoundInfo_t *v172; // edx
  const unsigned int *v173; // esi
  unsigned int v174; // edi
  int v175; // edx
  const unsigned int *v176; // ecx
  unsigned int v177; // esi
  unsigned int v178; // ebx
  unsigned int v179; // ecx
  int v180; // esi
  const unsigned int *v181; // ecx
  const unsigned int *v182; // edx
  int v183; // esi
  unsigned int v184; // ecx
  const unsigned int *v185; // edx
  const unsigned int *v186; // esi
  SoundInfo_t *v187; // edx
  unsigned int v188; // esi
  const unsigned int *v189; // ecx
  unsigned int v190; // edi
  int v191; // edx
  const unsigned int *v192; // esi
  unsigned int v193; // esi
  unsigned int v194; // ebx
  unsigned int v195; // ecx
  int v196; // esi
  const unsigned int *v197; // ecx
  const unsigned int *v198; // edx
  int v199; // ecx
  unsigned int v200; // edx
  int v201; // esi
  int v202; // ecx
  int v203; // ecx
  const unsigned int *v204; // ecx
  const unsigned int *v205; // edx
  unsigned int v206; // edx
  const unsigned int *v207; // esi
  unsigned int v208; // edi
  int v209; // edx
  const unsigned int *v210; // ecx
  unsigned int v211; // esi
  unsigned int v212; // ebx
  unsigned int v213; // ecx
  int v214; // esi
  const unsigned int *v215; // ecx
  const unsigned int *v216; // edx
  int v217; // ecx
  unsigned int v218; // edx
  int v219; // esi
  int v220; // ecx
  int v221; // ecx
  const unsigned int *v222; // ecx
  const unsigned int *v223; // edx
  unsigned int v224; // edx
  const unsigned int *v225; // esi
  unsigned int v226; // edi
  int v227; // edx
  const unsigned int *v228; // ecx
  unsigned int v229; // esi
  unsigned int v230; // ebx
  unsigned int v231; // ecx
  int v232; // esi
  const unsigned int *v233; // ecx
  const unsigned int *v234; // edx
  int v235; // ecx
  unsigned int v236; // edx
  int v237; // esi
  int v238; // ecx
  int v239; // ecx
  const unsigned int *v240; // ecx
  const unsigned int *v241; // edx
  unsigned int v242; // edx
  const unsigned int *v243; // esi
  unsigned int v244; // edi
  int v245; // edx
  const unsigned int *v246; // ecx
  unsigned int v247; // esi
  unsigned int v248; // ebx
  unsigned int v249; // ecx
  int v250; // esi
  const unsigned int *v251; // ecx
  const unsigned int *v252; // edx
  int v253; // ecx
  unsigned int v254; // edx
  int v255; // esi
  int v256; // ecx
  const unsigned int *v257; // ecx
  const unsigned int *v258; // edx
  SoundInfo_t *v259; // edx
  const unsigned int *v260; // esi
  unsigned int v261; // edi
  int v262; // edx
  const unsigned int *v263; // ecx
  unsigned int v264; // esi
  unsigned int v265; // ebx
  SoundInfo_t *v266; // [esp+Ch] [ebp-4h]
  bf_read *buffera; // [esp+1Ch] [ebp+Ch]

  m_nInBufWord = buffer->m_nInBufWord;
  v6 = m_nInBufWord & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  v266 = this;
  if ( v7 )
  {
    m_pDataIn = buffer->m_pDataIn;
    m_pBufferEnd = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      buffer->m_nInBufWord = *m_pDataIn;
      buffer->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = m_nInBufWord >> 1;
  }
  if ( v6 == 0 )
  {
    this->nEntityIndex = delta->nEntityIndex;
    goto LABEL_41;
  }
  v10 = buffer->m_nInBufWord;
  v11 = v10 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v12 = buffer->m_pDataIn;
    v13 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v12 == v13 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v12 + 1;
    }
    else if ( v12 <= v13 )
    {
      buffer->m_nInBufWord = *v12;
      buffer->m_pDataIn = v12 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v10 >> 1;
  }
  m_nBitsAvail = buffer->m_nBitsAvail;
  if ( v11 == 0 )
  {
    if ( m_nBitsAvail >= 11 )
    {
      v21 = buffer->m_nInBufWord;
      v16 = v21 & 0x7FF;
      v22 = m_nBitsAvail - 11;
      buffer->m_nBitsAvail = v22;
      if ( v22 != 0 )
      {
        buffer->m_nInBufWord = v21 >> 11;
        goto LABEL_40;
      }
LABEL_21:
      v18 = buffer->m_pDataIn;
      v19 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v18 == v19 )
      {
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        buffer->m_pDataIn = v18 + 1;
      }
      else if ( v18 <= v19 )
      {
        v23 = *v18;
        buffer->m_pDataIn = v18 + 1;
        buffer->m_nInBufWord = v23;
      }
      else
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      goto LABEL_40;
    }
    v20 = 11;
LABEL_31:
    v24 = buffer->m_pBufferEnd;
    v25 = buffer->m_nInBufWord;
    v26 = v20 - m_nBitsAvail;
    v27 = buffer->m_pDataIn;
    if ( v27 == v24 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v27 > v24 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_37;
      }
      buffer->m_nInBufWord = *v27;
    }
    buffer->m_pDataIn = v27 + 1;
LABEL_37:
    if ( buffer->m_bOverflow )
    {
      v16 = 0;
    }
    else
    {
      v28 = buffer->m_nInBufWord;
      v29 = (v28 & CBitBuffer::s_nMaskTable[v26]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v26;
      v16 = v29 | v25;
      buffer->m_nInBufWord = v28 >> v26;
    }
    goto LABEL_40;
  }
  if ( m_nBitsAvail < 5 )
  {
    v20 = 5;
    goto LABEL_31;
  }
  v15 = buffer->m_nInBufWord;
  v16 = v15 & 0x1F;
  v17 = m_nBitsAvail - 5;
  buffer->m_nBitsAvail = v17;
  if ( v17 == 0 )
    goto LABEL_21;
  buffer->m_nInBufWord = v15 >> 5;
LABEL_40:
  v266->nEntityIndex = v16;
LABEL_41:
  v30 = buffer->m_nInBufWord;
  v31 = v30 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v32 = buffer->m_pDataIn;
    v33 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v32 == v33 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v32 + 1;
    }
    else if ( v32 <= v33 )
    {
      buffer->m_nInBufWord = *v32;
      buffer->m_pDataIn = v32 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v30 >> 1;
  }
  if ( v31 == 0 )
  {
    v266->nSoundNum = delta->nSoundNum;
    goto LABEL_68;
  }
  v34 = buffer->m_nBitsAvail;
  if ( v34 < 13 )
  {
    v41 = buffer->m_pBufferEnd;
    v42 = buffer->m_nInBufWord;
    v43 = 13 - v34;
    v44 = buffer->m_pDataIn;
    if ( v44 == v41 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v44 > v41 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_64;
      }
      buffer->m_nInBufWord = *v44;
    }
    buffer->m_pDataIn = v44 + 1;
LABEL_64:
    if ( buffer->m_bOverflow )
    {
      v266->nSoundNum = 0;
    }
    else
    {
      v45 = buffer->m_nInBufWord;
      v46 = (v45 & CBitBuffer::s_nMaskTable[v43]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v43;
      buffer->m_nInBufWord = v45 >> v43;
      v266->nSoundNum = v46 | v42;
    }
    goto LABEL_68;
  }
  v35 = buffer->m_nInBufWord;
  v36 = v35 & 0x1FFF;
  v37 = v34 - 13;
  buffer->m_nBitsAvail = v37;
  if ( v37 != 0 )
  {
    buffer->m_nInBufWord = v35 >> 13;
    v266->nSoundNum = v36;
  }
  else
  {
    v38 = buffer->m_pDataIn;
    v39 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v38 == v39 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v38 + 1;
      v266->nSoundNum = v36;
    }
    else
    {
      if ( v38 <= v39 )
      {
        buffer->m_nInBufWord = *v38;
        v40 = v266;
        buffer->m_pDataIn = v38 + 1;
      }
      else
      {
        v40 = v266;
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v40->nSoundNum = v36;
    }
  }
LABEL_68:
  v47 = buffer->m_nInBufWord;
  v48 = v47 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v49 = buffer->m_pDataIn;
    v50 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v49 == v50 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v49 + 1;
    }
    else if ( v49 <= v50 )
    {
      buffer->m_nInBufWord = *v49;
      buffer->m_pDataIn = v49 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v47 >> 1;
  }
  if ( v48 == 0 )
  {
    v266->nFlags = delta->nFlags;
    goto LABEL_95;
  }
  v51 = buffer->m_nBitsAvail;
  if ( v51 < 13 )
  {
    v58 = buffer->m_pBufferEnd;
    v59 = buffer->m_nInBufWord;
    v60 = 13 - v51;
    v61 = buffer->m_pDataIn;
    if ( v61 == v58 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v61 > v58 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_91;
      }
      buffer->m_nInBufWord = *v61;
    }
    buffer->m_pDataIn = v61 + 1;
LABEL_91:
    if ( buffer->m_bOverflow )
    {
      v266->nFlags = 0;
    }
    else
    {
      v62 = buffer->m_nInBufWord;
      v63 = (v62 & CBitBuffer::s_nMaskTable[v60]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v60;
      buffer->m_nInBufWord = v62 >> v60;
      v266->nFlags = v63 | v59;
    }
    goto LABEL_95;
  }
  v52 = buffer->m_nInBufWord;
  v53 = v52 & 0x1FFF;
  v54 = v51 - 13;
  buffer->m_nBitsAvail = v54;
  if ( v54 != 0 )
  {
    buffer->m_nInBufWord = v52 >> 13;
    v266->nFlags = v53;
  }
  else
  {
    v55 = buffer->m_pDataIn;
    v56 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v55 == v56 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v55 + 1;
      v266->nFlags = v53;
    }
    else
    {
      if ( v55 <= v56 )
      {
        buffer->m_nInBufWord = *v55;
        v57 = v266;
        buffer->m_pDataIn = v55 + 1;
      }
      else
      {
        v57 = v266;
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v57->nFlags = v53;
    }
  }
LABEL_95:
  v64 = buffer->m_nInBufWord;
  v65 = v64 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v66 = buffer->m_pDataIn;
    v67 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v66 == v67 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v66 + 1;
    }
    else if ( v66 <= v67 )
    {
      buffer->m_nInBufWord = *v66;
      buffer->m_pDataIn = v66 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v64 >> 1;
  }
  if ( v65 == 0 )
  {
    v266->nChannel = delta->nChannel;
    goto LABEL_122;
  }
  v68 = buffer->m_nBitsAvail;
  if ( v68 < 3 )
  {
    v75 = buffer->m_pBufferEnd;
    v76 = buffer->m_nInBufWord;
    v77 = 3 - v68;
    v78 = buffer->m_pDataIn;
    if ( v78 == v75 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v78 > v75 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_118;
      }
      buffer->m_nInBufWord = *v78;
    }
    buffer->m_pDataIn = v78 + 1;
LABEL_118:
    if ( buffer->m_bOverflow )
    {
      v266->nChannel = 0;
    }
    else
    {
      v79 = buffer->m_nInBufWord;
      v80 = (v79 & CBitBuffer::s_nMaskTable[v77]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v77;
      buffer->m_nInBufWord = v79 >> v77;
      v266->nChannel = v80 | v76;
    }
    goto LABEL_122;
  }
  v69 = buffer->m_nInBufWord;
  v70 = v69 & 7;
  v71 = v68 - 3;
  buffer->m_nBitsAvail = v71;
  if ( v71 != 0 )
  {
    buffer->m_nInBufWord = v69 >> 3;
    v266->nChannel = v70;
  }
  else
  {
    v72 = buffer->m_pDataIn;
    v73 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v72 == v73 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v72 + 1;
      v266->nChannel = v70;
    }
    else
    {
      if ( v72 <= v73 )
      {
        buffer->m_nInBufWord = *v72;
        v74 = v266;
        buffer->m_pDataIn = v72 + 1;
      }
      else
      {
        v74 = v266;
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v74->nChannel = v70;
    }
  }
LABEL_122:
  v81 = buffer->m_nInBufWord;
  v82 = v81 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v83 = buffer->m_pDataIn;
    v84 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v83 == v84 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v83 + 1;
    }
    else if ( v83 <= v84 )
    {
      buffer->m_nInBufWord = *v83;
      buffer->m_pDataIn = v83 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v81 >> 1;
  }
  v266->bIsAmbient = v82 != 0;
  v85 = buffer->m_nInBufWord;
  v86 = v85 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v87 = buffer->m_pDataIn;
    v88 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v87 == v88 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v87 + 1;
    }
    else if ( v87 <= v88 )
    {
      buffer->m_nInBufWord = *v87;
      buffer->m_pDataIn = v87 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v85 >> 1;
  }
  v7 = v266->nFlags == 4;
  v266->bIsSentence = v86 != 0;
  if ( v7 )
  {
    v266->Soundlevel = SNDLVL_NONE;
    v266->pszName = nullptr;
    v266->nSequenceNumber = 0;
    v266->fVolume = 0.0;
    v266->nPitch = 100;
    v266->fDelay = 0.0;
    v266->vOrigin.x = 0.0;
    v266->vOrigin.y = 0.0;
    v266->vOrigin.z = 0.0;
    v266->nSpeakerEntity = -1;
    return;
  }
  v89 = buffer->m_nInBufWord;
  v90 = v89 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v91 = buffer->m_pDataIn;
    v92 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v91 == v92 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v91 + 1;
    }
    else if ( v91 <= v92 )
    {
      buffer->m_nInBufWord = *v91;
      buffer->m_pDataIn = v91 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v89 >> 1;
  }
  if ( v90 != 0 )
  {
    v266->nSequenceNumber = delta->nSequenceNumber;
    goto LABEL_173;
  }
  v93 = buffer->m_nInBufWord;
  v94 = v93 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v95 = buffer->m_pDataIn;
    v96 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v95 == v96 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v95 + 1;
    }
    else if ( v95 <= v96 )
    {
      buffer->m_nInBufWord = *v95;
      buffer->m_pDataIn = v95 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v93 >> 1;
  }
  if ( v94 != 0 )
  {
    v266->nSequenceNumber = delta->nSequenceNumber + 1;
    goto LABEL_173;
  }
  v97 = buffer->m_nBitsAvail;
  if ( v97 < 10 )
  {
    v104 = buffer->m_pBufferEnd;
    v105 = buffer->m_nInBufWord;
    v106 = 10 - v97;
    v107 = buffer->m_pDataIn;
    if ( v107 == v104 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v107 > v104 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_169;
      }
      buffer->m_nInBufWord = *v107;
    }
    buffer->m_pDataIn = v107 + 1;
LABEL_169:
    if ( buffer->m_bOverflow )
    {
      v99 = 0;
    }
    else
    {
      v108 = buffer->m_nInBufWord;
      v109 = (v108 & CBitBuffer::s_nMaskTable[v106]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v106;
      v99 = v109 | v105;
      buffer->m_nInBufWord = v108 >> v106;
    }
    goto LABEL_172;
  }
  v98 = buffer->m_nInBufWord;
  v99 = v98 & 0x3FF;
  v100 = v97 - 10;
  buffer->m_nBitsAvail = v100;
  if ( v100 != 0 )
  {
    buffer->m_nInBufWord = v98 >> 10;
  }
  else
  {
    v101 = buffer->m_pDataIn;
    v102 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v101 == v102 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v101 + 1;
    }
    else if ( v101 <= v102 )
    {
      v103 = *v101;
      buffer->m_pDataIn = v101 + 1;
      buffer->m_nInBufWord = v103;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
LABEL_172:
  v266->nSequenceNumber = v99;
LABEL_173:
  v110 = buffer->m_nInBufWord;
  v111 = v110 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v112 = buffer->m_pDataIn;
    v113 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v112 == v113 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v112 + 1;
    }
    else if ( v112 <= v113 )
    {
      buffer->m_nInBufWord = *v112;
      buffer->m_pDataIn = v112 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v110 >> 1;
  }
  if ( v111 != 0 )
  {
    v114 = buffer->m_nBitsAvail;
    if ( v114 >= 7 )
    {
      v115 = buffer->m_nInBufWord;
      v116 = v115 & 0x7F;
      v117 = v114 - 7;
      buffer->m_nBitsAvail = v117;
      if ( v117 != 0 )
      {
        buffer->m_nInBufWord = v115 >> 7;
      }
      else
      {
        v118 = buffer->m_pDataIn;
        v119 = buffer->m_pBufferEnd;
        buffer->m_nBitsAvail = 32;
        if ( v118 == v119 )
        {
          buffer->m_nBitsAvail = 1;
          buffer->m_nInBufWord = 0;
          buffer->m_pDataIn = v118 + 1;
        }
        else if ( v118 <= v119 )
        {
          v120 = *v118;
          buffer->m_pDataIn = v118 + 1;
          buffer->m_nInBufWord = v120;
        }
        else
        {
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
      }
LABEL_198:
      fVolume = (double)(unsigned int)v116 * 0.0078740157;
      goto LABEL_200;
    }
    v121 = buffer->m_pBufferEnd;
    v122 = buffer->m_nInBufWord;
    v123 = 7 - v114;
    v124 = buffer->m_pDataIn;
    if ( v124 == v121 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v124 > v121 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_195;
      }
      buffer->m_nInBufWord = *v124;
    }
    buffer->m_pDataIn = v124 + 1;
LABEL_195:
    if ( buffer->m_bOverflow )
    {
      v116 = 0;
    }
    else
    {
      v125 = buffer->m_nInBufWord;
      v126 = (v125 & CBitBuffer::s_nMaskTable[v123]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v123;
      v116 = v126 | v122;
      buffer->m_nInBufWord = v125 >> v123;
    }
    goto LABEL_198;
  }
  fVolume = delta->fVolume;
LABEL_200:
  v266->fVolume = fVolume;
  v128 = buffer->m_nInBufWord;
  v129 = v128 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v130 = buffer->m_pDataIn;
    v131 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v130 == v131 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v130 + 1;
    }
    else if ( v130 <= v131 )
    {
      buffer->m_nInBufWord = *v130;
      buffer->m_pDataIn = v130 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v128 >> 1;
  }
  if ( v129 == 0 )
  {
    v266->Soundlevel = delta->Soundlevel;
    goto LABEL_228;
  }
  v132 = buffer->m_nBitsAvail;
  if ( v132 < 9 )
  {
    v139 = buffer->m_pBufferEnd;
    v140 = buffer->m_nInBufWord;
    v141 = 9 - v132;
    v142 = buffer->m_pDataIn;
    if ( v142 == v139 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v142 > v139 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_223;
      }
      buffer->m_nInBufWord = *v142;
    }
    buffer->m_pDataIn = v142 + 1;
LABEL_223:
    if ( buffer->m_bOverflow )
    {
      v266->Soundlevel = SNDLVL_NONE;
    }
    else
    {
      v143 = buffer->m_nInBufWord;
      v144 = (v143 & CBitBuffer::s_nMaskTable[v141]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v141;
      buffer->m_nInBufWord = v143 >> v141;
      v266->Soundlevel = v144 | v140;
    }
    goto LABEL_228;
  }
  v133 = buffer->m_nInBufWord;
  v134 = v133 & 0x1FF;
  v135 = v132 - 9;
  buffer->m_nBitsAvail = v135;
  if ( v135 != 0 )
  {
    buffer->m_nInBufWord = v133 >> 9;
    v266->Soundlevel = v134;
  }
  else
  {
    v136 = buffer->m_pDataIn;
    v137 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v136 == v137 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v136 + 1;
      v266->Soundlevel = v134;
    }
    else
    {
      if ( v136 <= v137 )
      {
        buffer->m_nInBufWord = *v136;
        v138 = v266;
        buffer->m_pDataIn = v136 + 1;
      }
      else
      {
        v138 = v266;
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v138->Soundlevel = v134;
    }
  }
LABEL_228:
  v145 = buffer->m_nInBufWord;
  v146 = v145 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v147 = buffer->m_pDataIn;
    v148 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v147 == v148 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v147 + 1;
    }
    else if ( v147 <= v148 )
    {
      buffer->m_nInBufWord = *v147;
      buffer->m_pDataIn = v147 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v145 >> 1;
  }
  if ( v146 == 0 )
  {
    v266->nPitch = delta->nPitch;
    goto LABEL_256;
  }
  v149 = buffer->m_nBitsAvail;
  if ( v149 < 8 )
  {
    v156 = buffer->m_pBufferEnd;
    v157 = buffer->m_nInBufWord;
    v158 = 8 - v149;
    v159 = buffer->m_pDataIn;
    if ( v159 == v156 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v159 > v156 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_251;
      }
      buffer->m_nInBufWord = *v159;
    }
    buffer->m_pDataIn = v159 + 1;
LABEL_251:
    if ( buffer->m_bOverflow )
    {
      v266->nPitch = 0;
    }
    else
    {
      v160 = buffer->m_nInBufWord;
      v161 = (v160 & CBitBuffer::s_nMaskTable[v158]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v158;
      buffer->m_nInBufWord = v160 >> v158;
      v266->nPitch = v161 | v157;
    }
    goto LABEL_256;
  }
  v150 = buffer->m_nInBufWord;
  v151 = (unsigned __int8)v150;
  v152 = v149 - 8;
  buffer->m_nBitsAvail = v152;
  if ( v152 != 0 )
  {
    buffer->m_nInBufWord = v150 >> 8;
    v266->nPitch = (unsigned __int8)v150;
  }
  else
  {
    v153 = buffer->m_pDataIn;
    v154 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v153 == v154 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v153 + 1;
      v266->nPitch = v151;
    }
    else
    {
      if ( v153 <= v154 )
      {
        buffer->m_nInBufWord = *v153;
        v155 = v266;
        buffer->m_pDataIn = v153 + 1;
      }
      else
      {
        v155 = v266;
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v155->nPitch = v151;
    }
  }
LABEL_256:
  v162 = buffer->m_nInBufWord;
  v163 = v162 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v164 = buffer->m_pDataIn;
    v165 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v164 == v165 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v164 + 1;
    }
    else if ( v164 <= v165 )
    {
      buffer->m_nInBufWord = *v164;
      buffer->m_pDataIn = v164 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v162 >> 1;
  }
  if ( v163 == 0 )
  {
    v266->nRandomSeed = delta->nRandomSeed;
    goto LABEL_284;
  }
  v166 = buffer->m_nBitsAvail;
  if ( v166 < 6 )
  {
    v173 = buffer->m_pBufferEnd;
    v174 = buffer->m_nInBufWord;
    v175 = 6 - v166;
    v176 = buffer->m_pDataIn;
    if ( v176 == v173 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v176 > v173 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_279;
      }
      buffer->m_nInBufWord = *v176;
    }
    buffer->m_pDataIn = v176 + 1;
LABEL_279:
    if ( buffer->m_bOverflow )
    {
      v266->nRandomSeed = 0;
    }
    else
    {
      v177 = buffer->m_nInBufWord;
      v178 = (v177 & CBitBuffer::s_nMaskTable[v175]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v175;
      buffer->m_nInBufWord = v177 >> v175;
      v266->nRandomSeed = v178 | v174;
    }
    goto LABEL_284;
  }
  v167 = buffer->m_nInBufWord;
  v168 = v167 & 0x3F;
  v169 = v166 - 6;
  buffer->m_nBitsAvail = v169;
  if ( v169 != 0 )
  {
    buffer->m_nInBufWord = v167 >> 6;
    v266->nRandomSeed = v168;
  }
  else
  {
    v170 = buffer->m_pDataIn;
    v171 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v170 == v171 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v170 + 1;
      v266->nRandomSeed = v168;
    }
    else
    {
      if ( v170 <= v171 )
      {
        buffer->m_nInBufWord = *v170;
        v172 = v266;
        buffer->m_pDataIn = v170 + 1;
      }
      else
      {
        v172 = v266;
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
      }
      v172->nRandomSeed = v168;
    }
  }
LABEL_284:
  v179 = buffer->m_nInBufWord;
  v180 = v179 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v181 = buffer->m_pDataIn;
    v182 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v181 == v182 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v181 + 1;
    }
    else if ( v181 <= v182 )
    {
      buffer->m_nInBufWord = *v181;
      buffer->m_pDataIn = v181 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v179 >> 1;
  }
  if ( v180 == 0 )
  {
    v266->fDelay = delta->fDelay;
    goto LABEL_312;
  }
  v183 = buffer->m_nBitsAvail;
  if ( v183 >= 32 )
  {
    v184 = buffer->m_nInBufWord;
    buffer->m_nBitsAvail = v183 - 32;
    if ( v183 == 32 )
    {
      v185 = buffer->m_pDataIn;
      v186 = buffer->m_pBufferEnd;
      buffer->m_nBitsAvail = 32;
      if ( v185 == v186 )
      {
        buffer->m_pDataIn = v185 + 1;
        buffer->m_nBitsAvail = 1;
        buffer->m_nInBufWord = 0;
        LODWORD(v266->fDelay) = v184;
      }
      else
      {
        if ( v185 <= v186 )
        {
          v188 = *v185;
          buffer->m_pDataIn = v185 + 1;
          v187 = v266;
          buffer->m_nInBufWord = v188;
        }
        else
        {
          v187 = v266;
          buffer->m_bOverflow = true;
          buffer->m_nInBufWord = 0;
        }
        LODWORD(v187->fDelay) = v184;
      }
    }
    else
    {
      buffer->m_nInBufWord = 0;
      LODWORD(v266->fDelay) = v184;
    }
    goto LABEL_312;
  }
  v189 = buffer->m_pDataIn;
  v190 = buffer->m_nInBufWord;
  v191 = 32 - v183;
  v192 = buffer->m_pBufferEnd;
  if ( v189 == v192 )
  {
    buffer->m_nBitsAvail = 1;
    buffer->m_nInBufWord = 0;
    buffer->m_bOverflow = true;
LABEL_306:
    buffer->m_pDataIn = v189 + 1;
    goto LABEL_307;
  }
  if ( v189 <= v192 )
  {
    buffer->m_nInBufWord = *v189;
    goto LABEL_306;
  }
  buffer->m_bOverflow = true;
  buffer->m_nInBufWord = 0;
LABEL_307:
  if ( buffer->m_bOverflow )
  {
    buffera = nullptr;
  }
  else
  {
    v193 = buffer->m_nInBufWord;
    v194 = (v193 & CBitBuffer::s_nMaskTable[v191]) << buffer->m_nBitsAvail;
    buffer->m_nBitsAvail = 32 - v191;
    buffera = (bf_read *)(v194 | v190);
    buffer->m_nInBufWord = v193 >> v191;
  }
  LODWORD(v266->fDelay) = buffera;
LABEL_312:
  v195 = buffer->m_nInBufWord;
  v196 = v195 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v197 = buffer->m_pDataIn;
    v198 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v197 == v198 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v197 + 1;
    }
    else if ( v197 <= v198 )
    {
      buffer->m_nInBufWord = *v197;
      buffer->m_pDataIn = v197 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v195 >> 1;
  }
  if ( v196 != 0 )
  {
    v199 = buffer->m_nBitsAvail;
    if ( v199 >= 12 )
    {
      v200 = buffer->m_nInBufWord;
      v201 = v200 & 0xFFF;
      v202 = v199 - 12;
      buffer->m_nBitsAvail = v202;
      if ( v202 != 0 )
      {
        buffer->m_nInBufWord = v200 >> 12;
        v203 = v200 & 0xFFF;
      }
      else
      {
        v204 = buffer->m_pDataIn;
        v205 = buffer->m_pBufferEnd;
        buffer->m_nBitsAvail = 32;
        if ( v204 == v205 )
        {
          buffer->m_pDataIn = v204 + 1;
          buffer->m_nBitsAvail = 1;
          buffer->m_nInBufWord = 0;
          v203 = v201;
        }
        else
        {
          if ( v204 <= v205 )
          {
            v206 = *v204;
            buffer->m_pDataIn = v204 + 1;
            buffer->m_nInBufWord = v206;
          }
          else
          {
            buffer->m_bOverflow = true;
            buffer->m_nInBufWord = 0;
          }
          v203 = v201;
        }
      }
      goto LABEL_338;
    }
    v207 = buffer->m_pBufferEnd;
    v208 = buffer->m_nInBufWord;
    v209 = 12 - v199;
    v210 = buffer->m_pDataIn;
    if ( v210 == v207 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v210 > v207 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_335;
      }
      buffer->m_nInBufWord = *v210;
    }
    buffer->m_pDataIn = v210 + 1;
LABEL_335:
    if ( buffer->m_bOverflow )
    {
      v203 = 0;
    }
    else
    {
      v211 = buffer->m_nInBufWord;
      v212 = (v211 & CBitBuffer::s_nMaskTable[v209]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v209;
      v203 = v212 | v208;
      buffer->m_nInBufWord = v211 >> v209;
    }
LABEL_338:
    v266->vOrigin.x = (float)(v203 << 20 >> 20) * 8.0;
    goto LABEL_340;
  }
  v266->vOrigin.x = delta->vOrigin.x;
LABEL_340:
  v213 = buffer->m_nInBufWord;
  v214 = v213 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v215 = buffer->m_pDataIn;
    v216 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v215 == v216 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v215 + 1;
    }
    else if ( v215 <= v216 )
    {
      buffer->m_nInBufWord = *v215;
      buffer->m_pDataIn = v215 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v213 >> 1;
  }
  if ( v214 != 0 )
  {
    v217 = buffer->m_nBitsAvail;
    if ( v217 >= 12 )
    {
      v218 = buffer->m_nInBufWord;
      v219 = v218 & 0xFFF;
      v220 = v217 - 12;
      buffer->m_nBitsAvail = v220;
      if ( v220 != 0 )
      {
        buffer->m_nInBufWord = v218 >> 12;
        v221 = v218 & 0xFFF;
      }
      else
      {
        v222 = buffer->m_pDataIn;
        v223 = buffer->m_pBufferEnd;
        buffer->m_nBitsAvail = 32;
        if ( v222 == v223 )
        {
          buffer->m_pDataIn = v222 + 1;
          buffer->m_nBitsAvail = 1;
          buffer->m_nInBufWord = 0;
          v221 = v219;
        }
        else
        {
          if ( v222 <= v223 )
          {
            v224 = *v222;
            buffer->m_pDataIn = v222 + 1;
            buffer->m_nInBufWord = v224;
          }
          else
          {
            buffer->m_bOverflow = true;
            buffer->m_nInBufWord = 0;
          }
          v221 = v219;
        }
      }
      goto LABEL_366;
    }
    v225 = buffer->m_pBufferEnd;
    v226 = buffer->m_nInBufWord;
    v227 = 12 - v217;
    v228 = buffer->m_pDataIn;
    if ( v228 == v225 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v228 > v225 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_363;
      }
      buffer->m_nInBufWord = *v228;
    }
    buffer->m_pDataIn = v228 + 1;
LABEL_363:
    if ( buffer->m_bOverflow )
    {
      v221 = 0;
    }
    else
    {
      v229 = buffer->m_nInBufWord;
      v230 = (v229 & CBitBuffer::s_nMaskTable[v227]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v227;
      v221 = v230 | v226;
      buffer->m_nInBufWord = v229 >> v227;
    }
LABEL_366:
    v266->vOrigin.y = (float)(v221 << 20 >> 20) * 8.0;
    goto LABEL_368;
  }
  v266->vOrigin.y = delta->vOrigin.y;
LABEL_368:
  v231 = buffer->m_nInBufWord;
  v232 = v231 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v233 = buffer->m_pDataIn;
    v234 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v233 == v234 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v233 + 1;
    }
    else if ( v233 <= v234 )
    {
      buffer->m_nInBufWord = *v233;
      buffer->m_pDataIn = v233 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v231 >> 1;
  }
  if ( v232 != 0 )
  {
    v235 = buffer->m_nBitsAvail;
    if ( v235 >= 12 )
    {
      v236 = buffer->m_nInBufWord;
      v237 = v236 & 0xFFF;
      v238 = v235 - 12;
      buffer->m_nBitsAvail = v238;
      if ( v238 != 0 )
      {
        buffer->m_nInBufWord = v236 >> 12;
        v239 = v236 & 0xFFF;
      }
      else
      {
        v240 = buffer->m_pDataIn;
        v241 = buffer->m_pBufferEnd;
        buffer->m_nBitsAvail = 32;
        if ( v240 == v241 )
        {
          buffer->m_pDataIn = v240 + 1;
          buffer->m_nBitsAvail = 1;
          buffer->m_nInBufWord = 0;
          v239 = v237;
        }
        else
        {
          if ( v240 <= v241 )
          {
            v242 = *v240;
            buffer->m_pDataIn = v240 + 1;
            buffer->m_nInBufWord = v242;
          }
          else
          {
            buffer->m_bOverflow = true;
            buffer->m_nInBufWord = 0;
          }
          v239 = v237;
        }
      }
      goto LABEL_394;
    }
    v243 = buffer->m_pBufferEnd;
    v244 = buffer->m_nInBufWord;
    v245 = 12 - v235;
    v246 = buffer->m_pDataIn;
    if ( v246 == v243 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v246 > v243 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_391;
      }
      buffer->m_nInBufWord = *v246;
    }
    buffer->m_pDataIn = v246 + 1;
LABEL_391:
    if ( buffer->m_bOverflow )
    {
      v239 = 0;
    }
    else
    {
      v247 = buffer->m_nInBufWord;
      v248 = (v247 & CBitBuffer::s_nMaskTable[v245]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v245;
      v239 = v248 | v244;
      buffer->m_nInBufWord = v247 >> v245;
    }
LABEL_394:
    v266->vOrigin.z = (float)(v239 << 20 >> 20) * 8.0;
    goto LABEL_396;
  }
  v266->vOrigin.z = delta->vOrigin.z;
LABEL_396:
  v249 = buffer->m_nInBufWord;
  v250 = v249 & 1;
  v7 = buffer->m_nBitsAvail-- == 1;
  if ( v7 )
  {
    v251 = buffer->m_pDataIn;
    v252 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v251 == v252 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v251 + 1;
    }
    else if ( v251 <= v252 )
    {
      buffer->m_nInBufWord = *v251;
      buffer->m_pDataIn = v251 + 1;
    }
    else
    {
      buffer->m_bOverflow = true;
      buffer->m_nInBufWord = 0;
    }
  }
  else
  {
    buffer->m_nInBufWord = v249 >> 1;
  }
  if ( v250 == 0 )
  {
    v266->nSpeakerEntity = delta->nSpeakerEntity;
    return;
  }
  v253 = buffer->m_nBitsAvail;
  if ( v253 < 12 )
  {
    v260 = buffer->m_pBufferEnd;
    v261 = buffer->m_nInBufWord;
    v262 = 12 - v253;
    v263 = buffer->m_pDataIn;
    if ( v263 == v260 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_bOverflow = true;
    }
    else
    {
      if ( v263 > v260 )
      {
        buffer->m_bOverflow = true;
        buffer->m_nInBufWord = 0;
        goto LABEL_419;
      }
      buffer->m_nInBufWord = *v263;
    }
    buffer->m_pDataIn = v263 + 1;
LABEL_419:
    if ( buffer->m_bOverflow )
    {
      v266->nSpeakerEntity = 0;
    }
    else
    {
      v264 = buffer->m_nInBufWord;
      v265 = (v264 & CBitBuffer::s_nMaskTable[v262]) << buffer->m_nBitsAvail;
      buffer->m_nBitsAvail = 32 - v262;
      buffer->m_nInBufWord = v264 >> v262;
      v266->nSpeakerEntity = (int)((v265 | v261) << 20) >> 20;
    }
    return;
  }
  v254 = buffer->m_nInBufWord;
  v255 = v254 & 0xFFF;
  v256 = v253 - 12;
  buffer->m_nBitsAvail = v256;
  if ( v256 != 0 )
  {
    buffer->m_nInBufWord = v254 >> 12;
    v266->nSpeakerEntity = (unsigned __int16)v254 << 20 >> 20;
  }
  else
  {
    v257 = buffer->m_pDataIn;
    v258 = buffer->m_pBufferEnd;
    buffer->m_nBitsAvail = 32;
    if ( v257 == v258 )
    {
      buffer->m_nBitsAvail = 1;
      buffer->m_nInBufWord = 0;
      buffer->m_pDataIn = v257 + 1;
      v266->nSpeakerEntity = v255 << 20 >> 20;
    }
    else
    {
      if ( v257 <= v258 )
      {
        buffer->m_nInBufWord = *v257;
        v259 = v266;
        buffer->m_pDataIn = v257 + 1;
      }
      else
      {
        v259 = v266;
        buffer->m_nInBufWord = 0;
        buffer->m_bOverflow = true;
      }
      v259->nSpeakerEntity = v255 << 20 >> 20;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6840
// Name: public: virtual void CClientState::ConnectionClosing(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CClientState::ConnectionClosing(CClientState *this@<ecx>, int a2@<esi>, const char *reason)
{
  int v3; // eax

  if ( this->m_nSignonState > 0 )
  {
    ConMsg(a1: "Disconnect: %s.\n", reason);
    if ( _V_stricmp(s1: reason, s2: "Invalid STEAM UserID Ticket\n") != 0 )
    {
      if ( _V_stricmp(s1: reason, s2: "No Steam logon\n") != 0 )
      {
        if ( _V_stricmp(s1: reason, s2: "This Steam account is being used in another location\n") != 0 )
          g_eSteamLoginFailure = _V_stricmp(s1: reason, s2: "VAC banned from secure server\n") != 0 ? 0 : 3;
        else
          g_eSteamLoginFailure = 4;
      }
      else
      {
        g_eSteamLoginFailure = 2;
      }
    }
    else
    {
      g_eSteamLoginFailure = 1;
    }
    COM_ExplainDisconnection(bPrint: true, fmt: "Disconnect: %s.\n", reason);
    SCR_EndLoadingPlaque();
    Host_Disconnect(bShowMainMenu: true);
    if ( reason != nullptr && _V_stricmp(s1: reason, s2: "Server shutting down") == 0 )
    {
      v3 = _CommandLine(a1: a2);
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-quitonservershutdown") != 0 )
        Host_Shutdown();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6920
// Name: public: virtual void CClientState::ConnectionCrashed(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::ConnectionCrashed(CClientState *this, const char *reason)
{
  if ( this->m_nSignonState > 0 )
  {
    COM_ExplainDisconnection(bPrint: true, fmt: "Disconnect: %s.\n", reason);
    SCR_EndLoadingPlaque();
    Host_Disconnect(bShowMainMenu: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6950
// Name: public: virtual void CClientState::FileReceived(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::FileReceived(
        CClientState *this,
        const char *fileName,
        unsigned int transferID,
        bool isReplayDemoFile)
{
  CL_FileReceived(filename: fileName, requestID: transferID, isReplayDemoFile);
}

//------------------------------------------------------------------------------
// Address: 0x101D6970
// Name: public: virtual void CClientState::FileDenied(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::FileDenied(
        CClientState *this,
        const char *fileName,
        unsigned int transferID,
        bool isReplayDemoFile)
{
  CL_FileDenied(filename: fileName, requestID: transferID, isReplayDemoFile);
}

//------------------------------------------------------------------------------
// Address: 0x101D6990
// Name: public: virtual void CClientState::PacketStart(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::PacketStart(CClientState *this, int incoming_sequence, int outgoing_acknowledged)
{
  this->m_nCurrentSequence = incoming_sequence;
  this->command_ack = outgoing_acknowledged;
}

//------------------------------------------------------------------------------
// Address: 0x101D69B0
// Name: public: virtual void CClientState::PacketEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::PacketEnd(CClientState *this)
{
  int m_nServerTick; // edx
  int v3; // eax

  CL_DispatchSounds();
  m_nServerTick = this->m_ClockDriftMgr.m_nServerTick;
  if ( m_nServerTick == this->m_nDeltaTick )
  {
    v3 = this->command_ack - this->last_command_ack;
    this->last_command_ack = this->command_ack;
    this->last_server_tick = m_nServerTick;
    g_pClientSidePrediction->PostNetworkDataReceived(this: g_pClientSidePrediction, a2: v3);
    demoaction->DispatchEvents(this: demoaction);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6A00
// Name: public: virtual void CClientState::Disconnect(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CClientState::Disconnect(CClientState *this@<ecx>, int a2@<edi>, bool bShowMainMenu)
{
  IEngineVGuiInternal *v4; // eax
  IEngineVGuiInternal *v5; // eax
  IEngineVGuiInternal *v6; // eax

  CBaseClientState::Disconnect(this, bShowMainMenu);
  if ( !this->m_bSplitScreenUser )
  {
    if ( (_S2_16 & 1) == 0 )
    {
      _S2_16 |= 1u;
      ConVarRef::ConVarRef(this: &map_wants_save_disable, pName: "map_wants_save_disable");
    }
    map_wants_save_disable.m_pConVar->SetValue_2(this: map_wants_save_disable.m_pConVar, a2: 0);
    demoplayer->StopPlayback(this: demoplayer);
    demorecorder->StopRecording(this: demorecorder);
    S_StopAllSounds(bClear: true);
    R_DecalTermAll();
    if ( this->m_nMaxClients > 1 )
    {
      v4 = EngineVGui();
      if ( !v4->IsConsoleVisible(this: v4) )
      {
        v5 = EngineVGui();
        v5->EnabledProgressBarForNextLoad(this: v5);
      }
    }
    CL_ClearState(a1: a2);
    CL_HTTPStop_f();
    if ( bShowMainMenu )
      SCR_EndLoadingPlaque();
    v6 = EngineVGui();
    v6->NotifyOfServerDisconnect(this: v6);
    HostState_OnClientDisconnected();
    if ( GetBaseLocalClient()->demonum != -1 )
      CL_NextDemo();
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6AE0
// Name: public: virtual bool CClientState::ProcessTick(class NET_Tick __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessTick(CClientState *this, NET_Tick *msg)
{
  int m_nTick; // esi

  m_nTick = msg->m_nTick;
  (*((void (__thiscall **)(IServerMessageHandler_vtbl *, float, float))this->dtr_INetMessageHandler + 68))(
    a1: this->CBaseClientState::IServerMessageHandler::INetMessageHandler::__vftable,
    a2: msg->m_flHostFrameTime,
    a3: msg->m_flHostFrameTimeStdDeviation);
  CClockDriftMgr::SetServerTick(this: (CClockDriftMgr *)&this->m_nServerCount, nTick: m_nTick);
  *(float *)&this->m_ClientFramePool.m_BlobHead.m_NumBytes = (float)m_nTick * host_state.interval_per_tick;
  g_ClientGlobalVariables.curtime = (float)m_nTick * host_state.interval_per_tick;
  g_ClientGlobalVariables.tickcount = m_nTick;
  g_ClientGlobalVariables.frametime = (float)(m_nTick - LODWORD(this->m_flLastServerTickTime))
                                    * host_state.interval_per_tick;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D6B70
// Name: public: virtual bool CClientState::ProcessStringCmd(class NET_StringCmd __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessStringCmd(CClientState *this, NET_StringCmd *msg)
{
  return CBaseClientState::InternalProcessStringCmd(
           this: (CClientState *)((char *)this - 8),
           msg,
           bIsHLTV: this->m_nSoundSequence);
}

//------------------------------------------------------------------------------
// Address: 0x101D6B90
// Name: public: virtual bool CClientState::ProcessServerInfo(class SVC_ServerInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CClientState::ProcessServerInfo@<al>(CClientState *this@<ecx>, int a2@<edi>, SVC_ServerInfo *msg)
{
  int v5; // ecx
  float m_fTickInterval; // xmm0_4

  CL_ClearState(a1: a2);
  if ( CBaseClientState::ProcessServerInfo(this, a2: (int)this, msg) == 0 )
  {
    (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 2) + 64))(a1: (char *)this - 8, a2: 1);
    return 0;
  }
  if ( demoplayer->IsPlayingBack(this: demoplayer) )
    LODWORD(this->m_flNextCmdTime) = gHostSpawnCount;
  else
    demorecorder->SetSignonState(this: demorecorder, a2: 3);
  LOBYTE(this->m_nSoundSequence) = msg->m_bIsHLTV;
  v5 = *(_DWORD *)&this->m_szLastLevelNameShort[32];
  this->m_nLastProgressPercent = msg->m_nMapCRC;
  *(_DWORD *)&this->ishltv = msg->m_nClientCRC;
  g_ClientGlobalVariables.maxClients = v5;
  g_ClientGlobalVariables.network_protocol = msg->m_nProtocol;
  *(_DWORD *)&this->m_szEncryptionKey[2044] = networkStringTableContainerClient;
  CL_ReallocateDynamicData();
  m_fTickInterval = msg->m_fTickInterval;
  if ( sv.m_State == ss_paused )
  {
    if ( m_fTickInterval != host_state.interval_per_tick )
    {
      Host_Error(error: "Expecting interval_per_tick %f, got %f\n", host_state.interval_per_tick, m_fTickInterval);
      return 0;
    }
  }
  else
  {
    host_state.interval_per_tick = msg->m_fTickInterval;
  }
  ClientDLL_HudVidInit();
  gHostSpawnCount = LODWORD(this->m_flNextCmdTime);
  videomode->MarkClientViewRectDirty(this: videomode);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D6CB0
// Name: public: virtual bool CClientState::ProcessClassInfo(class SVC_ClassInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CClientState::ProcessClassInfo@<al>(CClientState *this@<ecx>, int a2@<edi>, SVC_ClassInfo *msg)
{
  IDemoRecorder_vtbl *v4; // edi
  ServerClass *v5; // eax

  if ( msg->m_bCreateOnClient )
  {
    if ( !demoplayer->IsPlayingBack(this: demoplayer) )
    {
      DataTable_CreateClientTablesFromServerTables();
      DataTable_CreateClientClassInfosFromServerClasses(
        a1: a2,
        a2: (int)this,
        pState: (CClientState *)((char *)this - 8));
      v4 = demorecorder->__vftable;
      v5 = serverGameDLL->GetAllServerClasses(this: serverGameDLL);
      v4->RecordServerClasses(this: demorecorder, a2: v5);
    }
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 2) + 100))(a1: (char *)this - 8);
  }
  else
  {
    CBaseClientState::ProcessClassInfo(this, msg);
  }
  serverGameDLL->GetStandardSendProxies(this: serverGameDLL);
  if ( RecvTable_CreateDecoders() != 0 )
  {
    if ( !demoplayer->IsPlayingBack(this: demoplayer) )
      CLocalNetworkBackdoor::InitFastCopy();
    return 1;
  }
  else
  {
    Host_EndGame(bShowMainMenu: true, message: "CL_ParseClassInfo_EndClasses: CreateDecoders failed.\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6D70
// Name: public: virtual bool CClientState::ProcessSetPause(class SVC_SetPause __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessSetPause(CClientState *this, SVC_SetPause *msg)
{
  CBaseClientState::ProcessSetPause(this, msg);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D6D90
// Name: public: virtual bool CClientState::ProcessVoiceInit(class SVC_VoiceInit __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CClientState::ProcessVoiceInit@<al>(CClientState *this@<ecx>, int a2@<esi>, SVC_VoiceInit *msg)
{
  if ( *msg->m_szVoiceCodec != 0 )
    Voice_Init(a1: a2, pCodecName: msg->m_szVoiceCodec);
  else
    Voice_Deinit();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D6DC0
// Name: public: virtual bool CClientState::ProcessPrefetch(class SVC_Prefetch __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessPrefetch(CClientState *this, SVC_Prefetch *msg)
{
  CClientState *BaseLocalClient; // eax
  const char *SoundName; // eax
  const char *v4; // esi
  void *v5; // eax
  int m_nSoundIndex; // [esp-4h] [ebp-8h]

  m_nSoundIndex = msg->m_nSoundIndex;
  BaseLocalClient = GetBaseLocalClient();
  SoundName = CClientState::GetSoundName(this: BaseLocalClient, index: m_nSoundIndex);
  v4 = SoundName;
  if ( SoundName != nullptr && *SoundName != 0 )
  {
    v5 = EngineSoundClient();
    (*(void (__thiscall **)(void *, const char *))(*(_DWORD *)v5 + 8))(a1: v5, a2: v4);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D6E00
// Name: public: virtual bool CClientState::ProcessCrosshairAngle(class SVC_CrosshairAngle __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessCrosshairAngle(CClientState *this, SVC_CrosshairAngle *msg)
{
  g_ClientDLL->SetCrosshairAngle(this: g_ClientDLL, a2: &msg->m_Angle);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D6EE0
// Name: public: virtual bool CClientState::ProcessGameEvent(class SVC_GameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessGameEvent(CClientState *this, SVC_GameEvent *msg)
{
  const unsigned int *m_pData; // eax
  int m_nDataBits; // edi
  IGameEvent *v4; // eax
  const unsigned int *v5; // ecx

  m_pData = msg->m_DataIn.m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = 32 * (msg->m_DataIn.m_pDataIn - m_pData)
                - msg->m_DataIn.m_nBitsAvail
                + 8 * (msg->m_DataIn.m_nDataBytes & 3);
    if ( m_nDataBits >= msg->m_DataIn.m_nDataBits )
      m_nDataBits = msg->m_DataIn.m_nDataBits;
  }
  else
  {
    m_nDataBits = 0;
  }
  v4 = g_GameEventManager->UnserializeEvent(this: g_GameEventManager, a2: &msg->m_DataIn);
  v5 = msg->m_DataIn.m_pData;
  if ( v5 != nullptr )
  {
    v5 = (const unsigned int *)(32 * (msg->m_DataIn.m_pDataIn - v5)
                              - msg->m_DataIn.m_nBitsAvail
                              + 8 * (msg->m_DataIn.m_nDataBytes & 3));
    if ( (int)v5 >= msg->m_DataIn.m_nDataBits )
      v5 = (const unsigned int *)msg->m_DataIn.m_nDataBits;
  }
  if ( (const unsigned int *)((char *)v5 - m_nDataBits) == (const unsigned int *)msg->m_nLength )
  {
    if ( v4 != nullptr )
      g_GameEventManager->FireEventClientSide(this: g_GameEventManager, a2: v4);
    else
      DevMsg(a1: "CClientState::ProcessGameEvent: UnserializeKeyValue failed.\n");
    return 1;
  }
  else
  {
    DevMsg(a1: "CClientState::ProcessGameEvent: KeyValue length mismatch.\n");
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6FC0
// Name: public: virtual bool CClientState::ProcessUserMessage(class SVC_UserMessage __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessUserMessage(CClientState *this, SVC_UserMessage *msg)
{
  unsigned __int8 userdata[511]; // [esp+4h] [ebp-224h] BYREF
  bf_read userMsg; // [esp+204h] [ebp-24h] BYREF

  memset(userdata, 0, sizeof(userdata));
  userMsg.m_bOverflow = false;
  userMsg.m_nDataBits = -1;
  userMsg.m_nDataBytes = 0;
  userMsg.m_pDebugName = "UserMessage(read)";
  CBitRead::StartReading(this: &userMsg, pData: userdata, nBytes: 511, iStartBit: 0, nBits: -1);
  CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: userdata, nBits: msg->m_nLength);
  CBitRead::StartReading(this: &userMsg, pData: userdata, nBytes: (msg->m_nLength + 7) >> 3, iStartBit: 0, nBits: -1);
  if ( g_ClientDLL->DispatchUserMessage(this: g_ClientDLL, a2: msg->m_nMsgType, a3: &userMsg) )
    return 1;
  ConMsg(a1: "Couldn't dispatch user message (%i)\n", msg->m_nMsgType);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D7090
// Name: public: virtual bool CClientState::ProcessPacketEntities(class SVC_PacketEntities __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessPacketEntities(CClientState *this, SVC_PacketEntities *msg)
{
  char result; // al
  #13526 *v4; // [esp+0h] [ebp-8h]

  CL_PreprocessEntities(a1: v4);
  if ( msg->m_bIsDelta )
  {
    if ( this->m_ClockDriftMgr.m_nServerTick == -1 )
      return 1;
  }
  else
  {
    demorecorder->SetSignonState(this: demorecorder, a2: 6);
    if ( g_pClientSidePrediction != nullptr )
      g_pClientSidePrediction->OnReceivedUncompressedPacket(this: g_pClientSidePrediction);
  }
  if ( g_pLocalNetworkBackdoor != nullptr )
  {
    if ( LODWORD(this->m_ListenServerSteamID) == 5 )
      (*(void (__thiscall **)(char *, int, _DWORD, _DWORD))(*((_DWORD *)this - 2) + 60))(
        a1: (char *)this - 8,
        a2: 6,
        a3: LODWORD(this->m_flNextCmdTime),
        a4: 0);
    this->m_ClockDriftMgr.m_nServerTick = LODWORD(this->m_ClockDriftMgr.m_ClockOffsets[15]);
    return 1;
  }
  result = CL_ProcessPacketEntities(entmsg: msg);
  if ( result != 0 )
    return CBaseClientState::ProcessPacketEntities(this, msg);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D7130
// Name: public: virtual void CClientState::FileRequested(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientState::FileRequested(
        CClientState *this,
        const char *fileName,
        unsigned int transferID,
        BOOL isReplayDemoFile)
{
  const char *v5; // eax

  v5 = this->m_NetChannel->GetAddress(this: this->m_NetChannel);
  ConMsg(a1: "File '%s' requested from server %s.\n", fileName, v5);
  if ( cl_allowupload.m_pParent != nullptr && cl_allowupload.m_pParent->m_Value.m_nValue != 0 )
  {
    this->m_NetChannel->SendFile(this: this->m_NetChannel, a2: fileName, a3: transferID, a4: isReplayDemoFile);
  }
  else
  {
    ConMsg(a1: "File uploading disabled.\n");
    this->m_NetChannel->DenyFile(this: this->m_NetChannel, a2: fileName, a3: transferID, a4: isReplayDemoFile);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D71B0
// Name: public: virtual bool CClientState::ProcessVoiceData(class SVC_VoiceData __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessVoiceData(CClientState *this, SVC_VoiceData *msg)
{
  int m_nLength; // eax
  unsigned int v3; // edi
  int v4; // esi
  char *m_pszString; // eax
  char *v6; // eax
  unsigned int Channel; // eax
  __int64 v9; // [esp-Ch] [ebp-10B0h]
  _BYTE v10[12]; // [esp+10h] [ebp-1094h] BYREF
  _BYTE v11[8]; // [esp+1010h] [ebp-94h] BYREF
  char v12[12]; // [esp+1018h] [ebp-8Ch] BYREF
  int *v13; // [esp+10A0h] [ebp-4h]

  m_nLength = msg->m_nLength;
  v3 = (m_nLength + 7) >> 3;
  v13 = (int *)this;
  if ( v3 >= 0x1000 )
    v3 = 4096;
  CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: v10, nBits: m_nLength);
  if ( voice_debugfeedback.m_pParent != nullptr && voice_debugfeedback.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "Received voice from: %d\n", msg->m_nFromClient + 1);
  v4 = msg->m_nFromClient + 1;
  if ( v4 == v13[52] + 1 )
    Voice_LocalPlayerTalkingAck(iSsSlot: v13[53]);
  engineClient->GetPlayerInfo(this: engineClient, a2: v4, a3: (player_info_s *)v11);
  if ( (cl_voice_filter.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = cl_voice_filter.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  if ( _V_strlen(str: m_pszString) <= 0 )
    goto LABEL_28;
  if ( (cl_voice_filter.m_nFlags & 0x1000) != 0 )
  {
    v6 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    v6 = cl_voice_filter.m_pParent->m_Value.m_pszString;
    if ( v6 == nullptr )
      v6 = (char *)defaultValue;
  }
  if ( _V_strstr(s1: v12, search: v6) != nullptr )
  {
LABEL_28:
    if ( v3 != 0 && Voice_Enabled() )
    {
      Channel = Voice_GetChannel(nEntity: v4);
      if ( Channel == -1
        && (Channel = Voice_AssignChannel(nEntity: v4, bProximity: msg->m_bProximity, timePadding: 0.2)) == -1 )
      {
        if ( S_IsInitted() )
        {
          _ConDMsg(a1: "ProcessVoiceData: Voice_AssignChannel failed for client %d!\n", v4 - 1);
          return 1;
        }
      }
      else
      {
        HIDWORD(v9) = v3;
        LODWORD(v9) = v10;
        Voice_AddIncomingData(nChannel: Channel, pchData: v9, iSequenceNumber: v13[29], isCompressed: true);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D7330
// Name: public: virtual bool CClientState::ProcessSounds(class SVC_Sounds __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClientState::ProcessSounds(CClientState *this, SVC_Sounds *msg)
{
  bf_read *p_m_DataIn; // esi
  const unsigned int *m_pData; // eax
  SoundInfo_t *p_defaultSound; // edx
  int m_nDataBits; // ecx
  int v7; // eax
  const unsigned int *v8; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // esi
  int v14; // eax
  SoundInfo_t defaultSound; // [esp+0h] [ebp-C4h] BYREF
  SoundInfo_t sound; // [esp+5Ch] [ebp-68h] BYREF
  SoundInfo_t *pDeltaSound; // [esp+B8h] [ebp-Ch]
  CClientState *v18; // [esp+BCh] [ebp-8h]
  int i; // [esp+C0h] [ebp-4h]
  int startbit; // [esp+CCh] [ebp+8h]

  defaultSound.Soundlevel = SNDLVL_NORM;
  sound.Soundlevel = SNDLVL_NORM;
  defaultSound.nPitch = 100;
  sound.nPitch = 100;
  p_m_DataIn = &msg->m_DataIn;
  defaultSound.nChannel = 6;
  sound.nChannel = 6;
  m_pData = msg->m_DataIn.m_pData;
  v18 = this;
  memset(&defaultSound.fDelay, 0, 16);
  defaultSound.fVolume = 1.0;
  defaultSound.nSpeakerEntity = -1;
  defaultSound.nSoundNum = 0;
  defaultSound.nFlags = 0;
  defaultSound.nRandomSeed = 0;
  defaultSound.bLooping = false;
  *(_WORD *)&defaultSound.bIsSentence = 0;
  memset(&defaultSound, 0, 40);
  p_defaultSound = &defaultSound;
  memset(&sound.fDelay, 0, 16);
  sound.fVolume = 1.0;
  sound.nSpeakerEntity = -1;
  sound.nSoundNum = 0;
  sound.nFlags = 0;
  sound.nRandomSeed = 0;
  sound.bLooping = false;
  *(_WORD *)&sound.bIsSentence = 0;
  memset(&sound, 0, 40);
  if ( m_pData != nullptr )
  {
    m_nDataBits = msg->m_DataIn.m_nDataBits;
    startbit = 32 * (msg->m_DataIn.m_pDataIn - m_pData)
             - msg->m_DataIn.m_nBitsAvail
             + 8 * (msg->m_DataIn.m_nDataBytes & 3);
    if ( startbit >= m_nDataBits )
      startbit = m_nDataBits;
  }
  else
  {
    startbit = 0;
  }
  i = 0;
  if ( msg->m_nNumSounds > 0 )
  {
    while ( 1 )
    {
      SoundInfo_t::ReadDelta(this: &sound, delta: p_defaultSound, buffer: p_m_DataIn);
      pDeltaSound = &sound;
      if ( msg->m_bReliableSound )
      {
        v7 = ((unsigned __int16)v18->last_server_tick + 1) & 0x3FF;
        v18->last_server_tick = v7;
        sound.nSequenceNumber = v7;
      }
      CL_AddSound(&sound);
      if ( ++i >= msg->m_nNumSounds )
        break;
      p_defaultSound = pDeltaSound;
    }
  }
  v8 = p_m_DataIn->m_pData;
  if ( v8 == nullptr )
    return msg->m_nLength == -startbit;
  v10 = (char *)p_m_DataIn->m_pDataIn - (char *)v8;
  v11 = 2 * (p_m_DataIn->m_nDataBytes & 3);
  v12 = 32 * (v10 >> 2) - p_m_DataIn->m_nBitsAvail;
  v13 = p_m_DataIn->m_nDataBits;
  v14 = v12 + 4 * v11;
  if ( v14 >= v13 )
    v14 = v13;
  return msg->m_nLength == v14 - startbit;
}

//------------------------------------------------------------------------------
// Address: 0x101D75E0
// Name: public: class SVC_EntityMessage __near & SVC_EntityMessage::operator=(class SVC_EntityMessage const __near &)
// Source: json
//------------------------------------------------------------------------------
SVC_EntityMessage *__thiscall SVC_EntityMessage::operator=(SVC_EntityMessage *this, const SVC_EntityMessage *__that)
{
  this->m_bReliable = __that->m_bReliable;
  this->m_NetChannel = __that->m_NetChannel;
  this->m_pMessageHandler = __that->m_pMessageHandler;
  this->m_nEntityIndex = __that->m_nEntityIndex;
  this->m_nClassID = __that->m_nClassID;
  this->m_nLength = __that->m_nLength;
  qmemcpy(&this->m_DataIn, &__that->m_DataIn, 0x3Cu);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D7890
// Name: public: virtual bool CClientState::ProcessPaintmapData(class SVC_PaintmapData __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessPaintmapData(CClientState *this, unsigned int msg)
{
  SVC_PaintmapData *v2; // edi
  int v3; // esi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > data; // [esp+Ch] [ebp-14h] BYREF

  v2 = (SVC_PaintmapData *)msg;
  v3 = (((*(_DWORD *)(msg + 16) + 7) >> 3) + 3) / 4;
  memset(&data, 0, sizeof(data));
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&data,
    elem: 0,
    num: v3);
  CBitRead::ReadBits(this: &v2->m_DataIn, pOutData: data.m_Memory.m_pMemory, nBits: v2->m_nLength);
  msg |= 3u;
  CByteswap::SwapBufferToTargetEndian<unsigned int>(
    this: (CByteswap *)&msg,
    outputBuffer: (int *)data.m_Memory.m_pMemory,
    inputBuffer: (int *)data.m_Memory.m_pMemory,
    count: v3);
  if ( data.m_Size > 0 )
    CPaintmapDataManager::LoadPaintmapDataRLE(this: &g_PaintManager, &data);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&data);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D7920
// Name: public: virtual bool CClientState::ProcessFixAngle(class SVC_FixAngle __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessFixAngle(CClientState *this, SVC_FixAngle *msg)
{
  float y; // xmm2_4
  float z; // xmm2_4
  float v4; // xmm0_4
  float v5; // eax
  CUtlMemory<ResourceEntryInfo,int> *p_y; // esi
  int m_nAllocationCount; // edi
  ResourceEntryInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // eax
  int a_4; // [esp+4h] [ebp-4h]

  if ( msg->m_Angle.x > 180.0 )
    msg->m_Angle.x = msg->m_Angle.x - 360.0;
  y = msg->m_Angle.y;
  if ( y > 180.0 )
    msg->m_Angle.y = y - 360.0;
  z = msg->m_Angle.z;
  if ( z > 180.0 )
    msg->m_Angle.z = z - 360.0;
  if ( msg->m_bRelative )
  {
    v4 = *(float *)&this->addangle.m_Size + msg->m_Angle.y;
    *(float *)&this->addangle.m_Size = v4;
    v5 = this->viewangles.z;
    p_y = (CUtlMemory<ResourceEntryInfo,int> *)&this->viewangles.y;
    m_nAllocationCount = this->addangle.m_Memory.m_nAllocationCount;
    a_4 = this->m_ClientFramePool.m_BlobHead.m_NumBytes;
    if ( m_nAllocationCount + 1 > SLODWORD(v5) )
      CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(this: p_y, num: m_nAllocationCount - LODWORD(v5) + 1);
    ++p_y[1].m_pMemory;
    m_pMemory = p_y->m_pMemory;
    v9 = (int)p_y[1].m_pMemory - m_nAllocationCount - 1;
    p_y[1].m_nAllocationCount = (int)p_y->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_nAllocationCount + 1], src: &m_pMemory[m_nAllocationCount], count: 8 * v9);
    v10 = (int)&p_y->m_pMemory[m_nAllocationCount];
    if ( v10 != 0 )
    {
      *(float *)v10 = v4;
      *(_DWORD *)(v10 + 4) = a_4;
      return 1;
    }
  }
  else
  {
    *(QAngle *)&this->m_chAreaPortalBits[20] = msg->m_Angle;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D7A40
// Name: public: virtual bool CClientState::ProcessEntityMessage(class SVC_EntityMessage __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessEntityMessage(CClientState *this, SVC_EntityMessage *msg)
{
  int v3; // ebx
  int v4; // edi
  IMDLCache *v6; // edi
  unsigned __int8 entityData[255]; // [esp+Ch] [ebp-124h] BYREF
  bf_read entMsg; // [esp+10Ch] [ebp-24h] BYREF

  v3 = entitylist->GetClientNetworkable(this: entitylist, a2: msg->m_nEntityIndex);
  if ( v3 != 0 )
  {
    v6 = g_pMDLCache;
    g_pMDLCache->BeginLock(this: g_pMDLCache);
    memset(entityData, 0, sizeof(entityData));
    entMsg.m_bOverflow = false;
    entMsg.m_nDataBits = -1;
    entMsg.m_nDataBytes = 0;
    entMsg.m_pDebugName = "EntityMessage(read)";
    CBitRead::StartReading(this: &entMsg, pData: entityData, nBytes: 255, iStartBit: 0, nBits: -1);
    CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: entityData, nBits: msg->m_nLength);
    CBitRead::StartReading(this: &entMsg, pData: entityData, nBytes: (msg->m_nLength + 7) >> 3, iStartBit: 0, nBits: -1);
    (*(void (__thiscall **)(int, int, bf_read *))(*(_DWORD *)v3 + 44))(a1: v3, a2: msg->m_nClassID, a3: &entMsg);
    v6->EndLock(this: v6);
  }
  else
  {
    v4 = *(_DWORD *)&this->demos[31][24]
       + 348
       * CUtlVector<CQueuedEntityMessage,CUtlMemory<CQueuedEntityMessage,int>>::InsertBefore(
           this: (CUtlVector<CQueuedEntityMessage,CUtlMemory<CQueuedEntityMessage,int> > *)&this->demos[31][24],
           elem: this->queuedmessage.m_Memory.m_nAllocationCount);
    *(_DWORD *)(v4 + 344) = msg->m_nEntityIndex;
    SVC_EntityMessage::operator=(this: (SVC_EntityMessage *)v4, __that: msg);
    v4 += 88;
    _V_memset(dest: (void *)v4, fill: 0, count: 255);
    CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: (void *)v4, nBits: msg->m_nLength);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D7B80
// Name: public: virtual bool CClientState::ProcessTempEntities(class SVC_TempEntities __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientState::ProcessTempEntities(CClientState *this, SVC_TempEntities *msg)
{
  CClientState *BaseLocalClient; // eax
  bool v4; // cl
  bf_read *p_m_DataIn; // esi
  unsigned int m_nInBufWord; // eax
  int v7; // edx
  bool v8; // zf
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  int v11; // ecx
  unsigned int v12; // eax
  char v13; // dl
  int v14; // ecx
  char v15; // bl
  const unsigned int *v16; // eax
  const unsigned int *v17; // ecx
  const unsigned int *v18; // edx
  unsigned int v19; // ebx
  int v20; // eax
  const unsigned int *v21; // ecx
  unsigned int v22; // edx
  unsigned int v23; // edi
  unsigned int v24; // eax
  int v25; // edx
  const unsigned int *v26; // eax
  const unsigned int *v27; // ecx
  int m_pServerClasses; // eax
  int m_nBitsAvail; // ecx
  unsigned int v30; // edx
  unsigned int v31; // ebx
  int v32; // ecx
  unsigned int v33; // edx
  const unsigned int *v34; // eax
  const unsigned int *v35; // ecx
  const unsigned int *v36; // edx
  unsigned int v37; // ebx
  int v38; // eax
  const unsigned int *v39; // ecx
  int v40; // eax
  unsigned int v41; // edx
  unsigned int v42; // edi
  PackedEntity *v43; // ecx
  int v44; // ebx
  ClientClass *ClientClass; // eax
  RecvTable *m_pRecvTable; // eax
  CClientState *v47; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *v48; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *v49; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *m_pNext; // eax
  int m_nBlockSize; // eax
  int m_Tail; // eax
  int v53; // edx
  ClientClass *v54; // eax
  int v55; // xmm0_4
  int v56; // ebx
  void *v57; // eax
  unsigned __int8 *pData; // [esp-10h] [ebp-13Ch]
  int v60; // [esp-Ch] [ebp-138h]
  unsigned __int8 data[192]; // [esp+Ch] [ebp-120h] BYREF
  bf_read fromBuf; // [esp+CCh] [ebp-60h] BYREF
  bf_write toBuf; // [esp+F0h] [ebp-3Ch] BYREF
  int flags; // [esp+108h] [ebp-24h]
  CEventInfo *ei; // [esp+10Ch] [ebp-20h]
  CClientState *v66; // [esp+110h] [ebp-1Ch]
  float delay; // [esp+114h] [ebp-18h]
  int i; // [esp+118h] [ebp-14h]
  int classID; // [esp+11Ch] [ebp-10h]
  ClientClass *pClientClass; // [esp+120h] [ebp-Ch]
  float fire_time; // [esp+124h] [ebp-8h]
  bool bReliable; // [esp+12Bh] [ebp-1h]

  v66 = this;
  bReliable = false;
  BaseLocalClient = GetBaseLocalClient();
  fire_time = CClientState::GetTime(this: BaseLocalClient);
  if ( GetBaseLocalClient()->m_nMaxClients > 1 || demoplayer->IsPlayingBack(this: demoplayer) )
    fire_time = CClientState::GetClientInterpAmount(this: (CClientState *)((char *)this - 8)) + fire_time;
  if ( msg->m_nNumEntries != 0 )
  {
    v4 = bReliable;
  }
  else
  {
    v4 = true;
    msg->m_nNumEntries = 1;
  }
  flags = v4 ? 2 : 0;
  if ( v4 || !demoplayer->IsSkipping(this: demoplayer) )
  {
    p_m_DataIn = &msg->m_DataIn;
    classID = -1;
    pClientClass = nullptr;
    bf_write::bf_write(this: &toBuf, pData: data, nBytes: 192, nBits: -1);
    ei = nullptr;
    i = 0;
    if ( msg->m_nNumEntries > 0 )
    {
      while ( 1 )
      {
        m_nInBufWord = msg->m_DataIn.m_nInBufWord;
        v7 = m_nInBufWord & 1;
        v8 = msg->m_DataIn.m_nBitsAvail-- == 1;
        delay = 0.0;
        if ( v8 )
        {
          m_pDataIn = msg->m_DataIn.m_pDataIn;
          m_pBufferEnd = msg->m_DataIn.m_pBufferEnd;
          msg->m_DataIn.m_nBitsAvail = 32;
          if ( m_pDataIn == m_pBufferEnd )
          {
            msg->m_DataIn.m_nBitsAvail = 1;
            msg->m_DataIn.m_nInBufWord = 0;
            msg->m_DataIn.m_pDataIn = m_pDataIn + 1;
          }
          else if ( m_pDataIn <= m_pBufferEnd )
          {
            msg->m_DataIn.m_nInBufWord = *m_pDataIn;
            msg->m_DataIn.m_pDataIn = m_pDataIn + 1;
          }
          else
          {
            msg->m_DataIn.m_bOverflow = true;
            msg->m_DataIn.m_nInBufWord = 0;
          }
        }
        else
        {
          msg->m_DataIn.m_nInBufWord = m_nInBufWord >> 1;
        }
        if ( v7 != 0 )
          break;
LABEL_37:
        bf_write::Reset(this: &toBuf);
        v24 = msg->m_DataIn.m_nInBufWord;
        v25 = v24 & 1;
        v8 = msg->m_DataIn.m_nBitsAvail-- == 1;
        if ( v8 )
        {
          v26 = msg->m_DataIn.m_pDataIn;
          v27 = msg->m_DataIn.m_pBufferEnd;
          msg->m_DataIn.m_nBitsAvail = 32;
          if ( v26 == v27 )
          {
            msg->m_DataIn.m_nBitsAvail = 1;
            msg->m_DataIn.m_nInBufWord = 0;
            msg->m_DataIn.m_pDataIn = v26 + 1;
          }
          else if ( v26 <= v27 )
          {
            msg->m_DataIn.m_nInBufWord = *v26;
            msg->m_DataIn.m_pDataIn = v26 + 1;
          }
          else
          {
            msg->m_DataIn.m_bOverflow = true;
            msg->m_DataIn.m_nInBufWord = 0;
          }
        }
        else
        {
          msg->m_DataIn.m_nInBufWord = v24 >> 1;
        }
        if ( v25 == 0 )
        {
          v60 = (ei->bits + 7) >> 3;
          pData = ei->pData;
          fromBuf.m_bOverflow = false;
          fromBuf.m_pDebugName = nullptr;
          fromBuf.m_nDataBits = -1;
          fromBuf.m_nDataBytes = 0;
          CBitRead::StartReading(this: &fromBuf, pData, nBytes: v60, iStartBit: 0, nBits: -1);
          RecvTable_MergeDeltas(
            a1: (const SendProp *)1,
            pTable: pClientClass->m_pRecvTable,
            pOldState: &fromBuf,
            pNewState: p_m_DataIn,
            pOut: &toBuf,
            objectID: -1,
            bDebugWatchInfo: false,
            pChangedProps: nullptr);
          goto LABEL_70;
        }
        m_pServerClasses = (int)v66->m_pServerClasses;
        m_nBitsAvail = msg->m_DataIn.m_nBitsAvail;
        if ( m_nBitsAvail < m_pServerClasses )
        {
          v36 = msg->m_DataIn.m_pBufferEnd;
          v37 = msg->m_DataIn.m_nInBufWord;
          v38 = m_pServerClasses - m_nBitsAvail;
          v39 = msg->m_DataIn.m_pDataIn;
          if ( v39 == v36 )
          {
            msg->m_DataIn.m_nBitsAvail = 1;
            msg->m_DataIn.m_nInBufWord = 0;
            msg->m_DataIn.m_bOverflow = true;
            goto LABEL_58;
          }
          if ( v39 <= v36 )
          {
            msg->m_DataIn.m_nInBufWord = *v39;
LABEL_58:
            msg->m_DataIn.m_pDataIn = v39 + 1;
          }
          else
          {
            msg->m_DataIn.m_bOverflow = true;
            msg->m_DataIn.m_nInBufWord = 0;
          }
          if ( msg->m_DataIn.m_bOverflow )
          {
            v40 = 0;
            goto LABEL_64;
          }
          v41 = msg->m_DataIn.m_nInBufWord;
          v42 = (v41 & CBitBuffer::s_nMaskTable[v38]) << msg->m_DataIn.m_nBitsAvail;
          msg->m_DataIn.m_nBitsAvail = 32 - v38;
          v31 = v42 | v37;
          v33 = v41 >> v38;
          goto LABEL_62;
        }
        v30 = msg->m_DataIn.m_nInBufWord;
        v31 = v30 & CBitBuffer::s_nMaskTable[m_pServerClasses];
        v32 = m_nBitsAvail - m_pServerClasses;
        msg->m_DataIn.m_nBitsAvail = v32;
        if ( v32 == 0 )
        {
          v34 = msg->m_DataIn.m_pDataIn;
          v35 = msg->m_DataIn.m_pBufferEnd;
          msg->m_DataIn.m_nBitsAvail = 32;
          if ( v34 == v35 )
          {
            msg->m_DataIn.m_nBitsAvail = 1;
            msg->m_DataIn.m_nInBufWord = 0;
            msg->m_DataIn.m_pDataIn = v34 + 1;
          }
          else if ( v34 <= v35 )
          {
            msg->m_DataIn.m_nInBufWord = *v34;
            msg->m_DataIn.m_pDataIn = v34 + 1;
          }
          else
          {
            msg->m_DataIn.m_bOverflow = true;
            msg->m_DataIn.m_nInBufWord = 0;
          }
          goto LABEL_63;
        }
        v33 = v30 >> m_pServerClasses;
LABEL_62:
        msg->m_DataIn.m_nInBufWord = v33;
LABEL_63:
        v40 = v31;
LABEL_64:
        v43 = v66->m_pEntityBaselines[1][2046];
        classID = v40;
        if ( v43 == nullptr
          || (v44 = (int)v43 + 16 * v40 - 16, (PackedEntity *)((char *)v43 + 16 * v40) == (PackedEntity *)16) )
        {
          DevMsg(a1: "CL_QueueEvent: missing server class info for %i.\n", v40 - 1);
          return 0;
        }
        ClientClass = CBaseClientState::FindClientClass(pClassName: *(const char **)(v44 + 4));
        pClientClass = ClientClass;
        if ( ClientClass == nullptr || (m_pRecvTable = ClientClass->m_pRecvTable) == nullptr )
        {
          DevMsg(a1: "CL_QueueEvent: missing client receive table for %s.\n", *(const char **)(v44 + 4));
          return 0;
        }
        RecvTable_MergeDeltas(
          a1: (const SendProp *)v44,
          pTable: m_pRecvTable,
          pOldState: nullptr,
          pNewState: p_m_DataIn,
          pOut: &toBuf,
          objectID: -1,
          bDebugWatchInfo: false,
          pChangedProps: nullptr);
LABEL_70:
        v47 = GetBaseLocalClient();
        v48 = CUtlLinkedList<CEventInfo,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>>::AllocInternal(
                this: &v47->events,
                multilist: false);
        v49 = v48;
        if ( v48 != nullptr )
        {
          if ( !CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>::IsIdxAfter(
                  this: &v47->events.m_Memory,
                  i: (unsigned int)v48,
                  it: &v47->events.m_LastAlloc) )
          {
            m_pNext = v49[7].m_pNext;
            if ( m_pNext != v49 )
            {
              if ( m_pNext != nullptr )
                m_pNext[7].m_nBlockSize = v49[7].m_nBlockSize;
              else
                v47->events.m_Head = v49[7].m_nBlockSize;
              m_nBlockSize = v49[7].m_nBlockSize;
              if ( m_nBlockSize != 0 )
                *(_DWORD *)(m_nBlockSize + 56) = v49[7].m_pNext;
              else
                v47->events.m_Tail = (int)v49[7].m_pNext;
              v49[7].m_nBlockSize = (int)v49;
              v49[7].m_pNext = v49;
              --v47->events.m_ElementCount;
            }
          }
          v49[7].m_nBlockSize = 0;
          m_Tail = v47->events.m_Tail;
          v49[7].m_pNext = (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)m_Tail;
          v47->events.m_Tail = (int)v49;
          if ( m_Tail != 0 )
            *(_DWORD *)(m_Tail + 60) = v49;
          else
            v47->events.m_Head = (int)v49;
          ++v47->events.m_ElementCount;
          CEngineRecipientFilter::CEngineRecipientFilter(this: (CEngineRecipientFilter *)&v49[3].m_nBlockSize);
          LOWORD(v49->m_pNext) = 0;
          v49->m_nBlockSize = 0;
          v49[2].m_pNext = nullptr;
          v49[3].m_pNext = nullptr;
          v49[1].m_pNext = nullptr;
          v49[1].m_nBlockSize = 0;
          v49[2].m_nBlockSize = 0;
        }
        GetBaseLocalClient();
        v53 = flags;
        v54 = pClientClass;
        *(float *)&v55 = delay + fire_time;
        v56 = toBuf.m_iCurBit + 7;
        LOWORD(v49->m_pNext) = classID;
        v49->m_nBlockSize = v55;
        v49[3].m_pNext = (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)v53;
        v49[1].m_nBlockSize = (int)v54;
        v56 >>= 3;
        ei = (CEventInfo *)v49;
        v49[2].m_pNext = (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)toBuf.m_iCurBit;
        v57 = MemAlloc_Alloc(nSize: v56);
        v49[2].m_nBlockSize = (int)v57;
        _V_memcpy(dest: v57, src: data, count: v56);
        if ( ++i >= msg->m_nNumEntries )
          return 1;
      }
      v11 = msg->m_DataIn.m_nBitsAvail;
      if ( v11 >= 8 )
      {
        v12 = msg->m_DataIn.m_nInBufWord;
        v13 = v12;
        v14 = v11 - 8;
        msg->m_DataIn.m_nBitsAvail = v14;
        if ( v14 != 0 )
        {
          msg->m_DataIn.m_nInBufWord = v12 >> 8;
          v15 = v12;
        }
        else
        {
          v16 = msg->m_DataIn.m_pDataIn;
          v17 = msg->m_DataIn.m_pBufferEnd;
          msg->m_DataIn.m_nBitsAvail = 32;
          if ( v16 == v17 )
          {
            msg->m_DataIn.m_nBitsAvail = 1;
            msg->m_DataIn.m_nInBufWord = 0;
            msg->m_DataIn.m_pDataIn = v16 + 1;
            v15 = v13;
          }
          else
          {
            if ( v16 <= v17 )
            {
              msg->m_DataIn.m_nInBufWord = *v16;
              msg->m_DataIn.m_pDataIn = v16 + 1;
            }
            else
            {
              msg->m_DataIn.m_bOverflow = true;
              msg->m_DataIn.m_nInBufWord = 0;
            }
            v15 = v13;
          }
        }
        goto LABEL_36;
      }
      v18 = msg->m_DataIn.m_pBufferEnd;
      v19 = msg->m_DataIn.m_nInBufWord;
      v20 = 8 - v11;
      v21 = msg->m_DataIn.m_pDataIn;
      if ( v21 == v18 )
      {
        msg->m_DataIn.m_nBitsAvail = 1;
        msg->m_DataIn.m_nInBufWord = 0;
        msg->m_DataIn.m_bOverflow = true;
      }
      else
      {
        if ( v21 > v18 )
        {
          msg->m_DataIn.m_bOverflow = true;
          msg->m_DataIn.m_nInBufWord = 0;
          goto LABEL_33;
        }
        msg->m_DataIn.m_nInBufWord = *v21;
      }
      msg->m_DataIn.m_pDataIn = v21 + 1;
LABEL_33:
      if ( msg->m_DataIn.m_bOverflow )
      {
        v15 = 0;
      }
      else
      {
        v22 = msg->m_DataIn.m_nInBufWord;
        v23 = (v22 & CBitBuffer::s_nMaskTable[v20]) << msg->m_DataIn.m_nBitsAvail;
        msg->m_DataIn.m_nBitsAvail = 32 - v20;
        v15 = v23 | v19;
        msg->m_DataIn.m_nInBufWord = v22 >> v20;
      }
LABEL_36:
      delay = (float)v15 * 0.0099999998;
      goto LABEL_37;
    }
  }
  return 1;
}

} // namespace engine_xlsp
