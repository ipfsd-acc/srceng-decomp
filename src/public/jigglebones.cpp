// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/jigglebones.cpp
// Functions: 3
// ============================================================

#include "public\jigglebones.h"

//------------------------------------------------------------------------------
// Address: 0x00409FA0
// Name: public: void JiggleData::Init(int,float,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall JiggleData::Init(
        JiggleData *this,
        int initBone,
        float currenttime,
        const Vector *initBasePos,
        const Vector *initTipPos)
{
  this->bone = initBone;
  this->lastUpdate = currenttime;
  this->basePos = *initBasePos;
  this->baseLastPos = this->basePos;
  this->baseVel.x = 0.0;
  this->baseVel.y = 0.0;
  this->baseVel.z = 0.0;
  this->baseAccel.x = 0.0;
  this->baseAccel.y = 0.0;
  this->baseAccel.z = 0.0;
  this->tipPos = *initTipPos;
  this->tipVel.x = 0.0;
  this->tipVel.y = 0.0;
  this->tipVel.z = 0.0;
  this->tipAccel.x = 0.0;
  this->tipAccel.y = 0.0;
  this->tipAccel.z = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x0040A390
// Name: public: struct JiggleData __near * CJiggleBones::GetJiggleData(int,float,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
UtlLinkedListElem_t<JiggleData,unsigned short> *__thiscall CJiggleBones::GetJiggleData(
        CJiggleBones *this,
        int bone,
        float currenttime,
        const Vector *initBasePos,
        const Vector *initTipPos)
{
  CJiggleBones *v5; // esi
  int m_Head; // eax
  UtlLinkedListElem_t<JiggleData,unsigned short> *m_pMemory; // edi
  int v8; // ecx
  float z; // xmm2_4
  float x; // xmm0_4
  float v11; // xmm1_4
  unsigned __int16 v12; // ax
  int v13; // ebx
  unsigned __int16 v14; // ax
  int v15; // esi
  JiggleData *p_m_Element; // edi
  JiggleData data; // [esp+Ch] [ebp-64h] BYREF
  CJiggleBones *v19; // [esp+6Ch] [ebp-4h]

  v5 = this;
  m_Head = this->m_jiggleBoneState.m_Head;
  v19 = this;
  if ( m_Head == 0xFFFF )
  {
LABEL_5:
    z = initBasePos->z;
    data.lastUpdate = currenttime;
    x = initBasePos->x;
    data.basePos.y = initBasePos->y;
    data.baseLastPos.y = data.basePos.y;
    data.tipPos.x = initTipPos->x;
    data.tipPos.y = initTipPos->y;
    v11 = initTipPos->z;
    data.id = s_id;
    data.basePos.x = x;
    data.baseLastPos.x = x;
    data.bone = bone;
    data.basePos.z = z;
    data.baseLastPos.z = z;
    memset(&data.baseVel, 0, 24);
    data.tipPos.z = v11;
    memset(&data.tipVel, 0, 24);
    ++s_id;
    v12 = CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::AllocInternal(
            this: &v5->m_jiggleBoneState,
            multilist: false);
    v13 = v12;
    if ( v12 == 0xFFFF )
    {
      v14 = -1;
    }
    else
    {
      CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::LinkAfter(
        this: &v5->m_jiggleBoneState,
        after: 0xFFFFu,
        elem: v12);
      p_m_Element = &v5->m_jiggleBoneState.m_Memory.m_pMemory[v13].m_Element;
      if ( p_m_Element != nullptr )
      {
        *p_m_Element = data;
        v5 = v19;
      }
      v14 = v13;
    }
    if ( v14 == 0xFFFF )
      return nullptr;
    else
      return &v5->m_jiggleBoneState.m_Memory.m_pMemory[v14];
  }
  else
  {
    m_pMemory = this->m_jiggleBoneState.m_Memory.m_pMemory;
    while ( 1 )
    {
      v8 = (unsigned __int16)m_Head;
      if ( m_pMemory[v8].m_Element.bone == bone )
        break;
      m_Head = m_pMemory[v8].m_Next;
      if ( m_Head == 0xFFFF )
        goto LABEL_5;
    }
    v15 = (unsigned __int16)m_Head;
    if ( (LODWORD(m_pMemory[v15].m_Element.lastUpdate) & 0x7F800000) == 0x7F800000 )
      _Warning(a1: "lastUpdate NaN\n");
    if ( (LODWORD(m_pMemory[v15].m_Element.basePos.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.basePos.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.basePos.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "basePos NaN\n");
    }
    if ( (LODWORD(m_pMemory[v15].m_Element.baseLastPos.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.baseLastPos.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.baseLastPos.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "baseLastPos NaN\n");
    }
    if ( (LODWORD(m_pMemory[v15].m_Element.baseVel.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.baseVel.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.baseVel.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "baseVel NaN\n");
    }
    if ( (LODWORD(m_pMemory[v15].m_Element.baseAccel.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.baseAccel.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.baseAccel.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "baseAccel NaN\n");
    }
    if ( (LODWORD(m_pMemory[v15].m_Element.tipPos.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.tipPos.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.tipPos.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "tipPos NaN\n");
    }
    if ( (LODWORD(m_pMemory[v15].m_Element.tipVel.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.tipVel.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.tipVel.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "tipVel NaN\n");
    }
    if ( (LODWORD(m_pMemory[v15].m_Element.tipAccel.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.tipAccel.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.tipAccel.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "tipAccel NaN\n");
    }
    return &v19->m_jiggleBoneState.m_Memory.m_pMemory[v15];
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A7B0
// Name: public: void CJiggleBones::BuildJiggleTransformations(int,float,struct mstudiojigglebone_t const __near *,struct matrix3x4_t const __near &,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJiggleBones::BuildJiggleTransformations(
        CJiggleBones *this,
        int boneIndex,
        float currenttime,
        float jiggleInfo,
        const matrix3x4_t *goalMX,
        matrix3x4_t *boneMX)
{
  const matrix3x4_t *v6; // edi
  const mstudiojigglebone_t *v8; // edi
  float v9; // xmm0_4
  UtlLinkedListElem_t<JiggleData,unsigned short> *JiggleData; // eax
  JiggleData *p_m_Element; // esi
  float v12; // xmm4_4
  float x; // xmm1_4
  float v14; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  int flags; // eax
  float v32; // xmm1_4
  float v33; // xmm3_4
  float v34; // xmm4_4
  float v35; // xmm7_4
  float v36; // xmm2_4
  float v37; // xmm7_4
  float v38; // xmm6_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm3_4
  float v42; // xmm5_4
  float v43; // xmm1_4
  float v44; // xmm5_4
  float v45; // xmm2_4
  float v46; // xmm4_4
  float v47; // xmm1_4
  float v48; // xmm7_4
  float v49; // xmm6_4
  float v50; // xmm5_4
  float v51; // xmm4_4
  float v52; // xmm3_4
  float v53; // xmm5_4
  float v54; // xmm3_4
  float v55; // xmm2_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  float v58; // xmm3_4
  float v59; // xmm1_4
  float v60; // xmm2_4
  float v61; // xmm3_4
  float v62; // xmm0_4
  int v63; // eax
  float v64; // xmm4_4
  float v65; // xmm3_4
  float v66; // xmm5_4
  float v67; // xmm0_4
  float v68; // xmm2_4
  float minYaw; // xmm1_4
  float v70; // xmm4_4
  float v71; // xmm5_4
  float v72; // xmm0_4
  float v73; // xmm3_4
  float v74; // xmm6_4
  float v75; // xmm0_4
  float v76; // xmm1_4
  float v77; // xmm2_4
  float v78; // xmm6_4
  float v79; // xmm1_4
  float v80; // xmm0_4
  float v81; // xmm2_4
  float v82; // xmm4_4
  float v83; // xmm3_4
  float v84; // xmm5_4
  float v85; // xmm7_4
  float yawFriction; // xmm0_4
  float v87; // xmm7_4
  float v88; // xmm1_4
  float v89; // xmm0_4
  float v90; // xmm6_4
  float v91; // xmm2_4
  float v92; // xmm3_4
  float v93; // xmm1_4
  float minPitch; // xmm1_4
  float v95; // xmm4_4
  float v96; // xmm5_4
  float v97; // xmm0_4
  float v98; // xmm6_4
  float v99; // xmm3_4
  float v100; // xmm0_4
  float v101; // xmm7_4
  float v102; // xmm1_4
  float v103; // xmm2_4
  float v104; // xmm0_4
  float v105; // xmm2_4
  float v106; // xmm0_4
  float v107; // xmm2_4
  float v108; // xmm1_4
  float v109; // xmm6_4
  float v110; // xmm0_4
  float v111; // xmm2_4
  float v112; // xmm1_4
  float v113; // xmm6_4
  float v114; // xmm3_4
  float pitchFriction; // xmm0_4
  float v116; // xmm5_4
  float v117; // xmm0_4
  float v118; // xmm5_4
  float v119; // xmm7_4
  float v120; // xmm0_4
  float v121; // xmm1_4
  float v122; // xmm3_4
  float v123; // xmm1_4
  float angleLimit; // xmm0_4
  float v125; // xmm3_4
  float v126; // xmm1_4
  float v127; // xmm1_4
  float v128; // xmm2_4
  float v129; // xmm2_4
  float v130; // xmm3_4
  float v131; // xmm4_4
  float length; // xmm5_4
  float v133; // xmm6_4
  float v134; // xmm1_4
  float v135; // xmm5_4
  float v136; // xmm0_4
  matrix3x4_t *v137; // ecx
  float v138; // xmm3_4
  float v139; // xmm5_4
  float v140; // xmm4_4
  float v141; // xmm6_4
  float v142; // xmm2_4
  float v143; // xmm1_4
  float v144; // xmm2_4
  float v145; // xmm0_4
  float v146; // xmm7_4
  float v147; // xmm6_4
  float baseDamping; // xmm4_4
  float *p_x; // eax
  float v150; // xmm6_4
  float v151; // xmm7_4
  float baseStiffness; // xmm4_4
  float v153; // xmm2_4
  float v154; // xmm3_4
  float v155; // xmm4_4
  float v156; // xmm2_4
  float v157; // xmm3_4
  float v158; // xmm2_4
  float v159; // xmm3_4
  float v160; // xmm1_4
  float v161; // xmm0_4
  float v162; // xmm3_4
  float v163; // xmm2_4
  float v164; // xmm4_4
  float v165; // xmm5_4
  float v166; // xmm3_4
  float v167; // xmm7_4
  float v168; // xmm0_4
  float v169; // xmm5_4
  float v170; // xmm1_4
  float v171; // xmm0_4
  float v172; // xmm1_4
  float v173; // xmm3_4
  float baseMinLeft; // xmm6_4
  float baseLeftFriction; // xmm7_4
  float v176; // xmm5_4
  float v177; // xmm7_4
  float v178; // xmm6_4
  float baseMinUp; // xmm6_4
  float baseUpFriction; // xmm7_4
  float v181; // xmm5_4
  float v182; // xmm6_4
  float v183; // xmm7_4
  float v184; // xmm3_4
  float baseMinForward; // xmm6_4
  float v186; // xmm3_4
  float v187; // xmm5_4
  float v188; // xmm6_4
  float v189; // xmm7_4
  float v190; // xmm1_4
  float baseForwardFriction; // xmm0_4
  float v192; // xmm6_4
  float v193; // xmm0_4
  float v194; // xmm1_4
  float v195; // xmm2_4
  float v196; // xmm0_4
  float v197; // xmm1_4
  float v198; // xmm2_4
  float v199; // xmm0_4
  float v200; // xmm1_4
  long double v201; // [esp+Ch] [ebp-E4h]
  long double v202; // [esp+Ch] [ebp-E4h]
  matrix3x4_t pitchMatrix; // [esp+14h] [ebp-DCh] BYREF
  matrix3x4_t limitMatrix; // [esp+44h] [ebp-ACh] BYREF
  unsigned int *p_sy; // [esp+74h] [ebp-7Ch]
  float pitch; // [esp+78h] [ebp-78h]
  Vector goalTip; // [esp+7Ch] [ebp-74h] BYREF
  float v208; // [esp+88h] [ebp-68h]
  Vector forward; // [esp+8Ch] [ebp-64h] BYREF
  unsigned int sy; // [esp+98h] [ebp-58h] BYREF
  Vector localError; // [esp+9Ch] [ebp-54h] BYREF
  Vector goalLeft; // [esp+A8h] [ebp-48h] BYREF
  Vector left; // [esp+B4h] [ebp-3Ch] BYREF
  Vector localAlong; // [esp+C0h] [ebp-30h]
  Vector goalForward; // [esp+CCh] [ebp-24h] BYREF
  Vector goalUp; // [esp+D8h] [ebp-18h] BYREF
  Vector goalBasePosition; // [esp+E4h] [ebp-Ch] BYREF
  float deltaT; // [esp+F8h] [ebp+8h]
  float maxBetween; // [esp+FCh] [ebp+Ch]
  float maxBetweenb; // [esp+FCh] [ebp+Ch]
  float maxBetweenc; // [esp+FCh] [ebp+Ch]
  float maxBetweena; // [esp+FCh] [ebp+Ch]
  float maxBetweend; // [esp+FCh] [ebp+Ch]
  float maxBetweene; // [esp+FCh] [ebp+Ch]

  v6 = goalMX;
  goalBasePosition.x = goalMX->m_flMatVal[0][3];
  goalBasePosition.y = goalMX->m_flMatVal[1][3];
  goalBasePosition.z = goalMX->m_flMatVal[2][3];
  MatrixGetColumn(in: goalMX, column: 0, out: &goalLeft);
  MatrixGetColumn(in: v6, column: 1, out: &goalUp);
  MatrixGetColumn(in: v6, column: 2, out: &goalForward);
  v8 = (const mstudiojigglebone_t *)LODWORD(jiggleInfo);
  v9 = *(float *)(LODWORD(jiggleInfo) + 4);
  goalTip.z = (float)(v9 * goalForward.z) + goalBasePosition.z;
  goalTip.x = (float)(goalForward.x * v9) + goalBasePosition.x;
  goalTip.y = (float)(v9 * goalForward.y) + goalBasePosition.y;
  JiggleData = CJiggleBones::GetJiggleData(
                 this,
                 bone: boneIndex,
                 currenttime,
                 initBasePos: &goalBasePosition,
                 initTipPos: &goalTip);
  p_m_Element = &JiggleData->m_Element;
  if ( JiggleData != nullptr )
  {
    v12 = currenttime;
    if ( (float)(currenttime - JiggleData->m_Element.lastUpdate) > 0.5 )
    {
      x = goalBasePosition.x;
      JiggleData->m_Element.bone = boneIndex;
      JiggleData->m_Element.lastUpdate = currenttime;
      JiggleData->m_Element.basePos.x = x;
      JiggleData->m_Element.basePos.y = goalBasePosition.y;
      JiggleData->m_Element.basePos.z = goalBasePosition.z;
      v14 = goalTip.x;
      JiggleData->m_Element.baseLastPos.x = JiggleData->m_Element.basePos.x;
      JiggleData->m_Element.baseLastPos.y = JiggleData->m_Element.basePos.y;
      JiggleData->m_Element.baseLastPos.z = JiggleData->m_Element.basePos.z;
      JiggleData->m_Element.baseVel.x = 0.0;
      JiggleData->m_Element.baseVel.y = 0.0;
      JiggleData->m_Element.baseVel.z = 0.0;
      JiggleData->m_Element.baseAccel.x = 0.0;
      JiggleData->m_Element.baseAccel.y = 0.0;
      JiggleData->m_Element.baseAccel.z = 0.0;
      JiggleData->m_Element.tipPos.x = v14;
      JiggleData->m_Element.tipPos.y = goalTip.y;
      JiggleData->m_Element.tipPos.z = goalTip.z;
      JiggleData->m_Element.tipVel.x = 0.0;
      JiggleData->m_Element.tipVel.y = 0.0;
      JiggleData->m_Element.tipVel.z = 0.0;
      JiggleData->m_Element.tipAccel.x = 0.0;
      JiggleData->m_Element.tipAccel.y = 0.0;
      JiggleData->m_Element.tipAccel.z = 0.0;
    }
    if ( JiggleBoneInvert.m_pParent->m_Value.m_nValue != 0 )
    {
      y = JiggleData->m_Element.basePos.y;
      z = JiggleData->m_Element.basePos.z;
      JiggleData->m_Element.basePos.x = -JiggleData->m_Element.basePos.x;
      JiggleData->m_Element.basePos.y = -y;
      JiggleData->m_Element.basePos.z = -z;
      v17 = JiggleData->m_Element.baseLastPos.y;
      v18 = JiggleData->m_Element.baseLastPos.z;
      JiggleData->m_Element.baseLastPos.x = -JiggleData->m_Element.baseLastPos.x;
      JiggleData->m_Element.baseLastPos.y = -v17;
      JiggleData->m_Element.baseLastPos.z = -v18;
      v19 = JiggleData->m_Element.baseVel.y;
      v20 = JiggleData->m_Element.baseVel.z;
      JiggleData->m_Element.baseVel.x = -JiggleData->m_Element.baseVel.x;
      JiggleData->m_Element.baseVel.y = -v19;
      JiggleData->m_Element.baseVel.z = -v20;
      v21 = JiggleData->m_Element.baseAccel.y;
      v22 = JiggleData->m_Element.baseAccel.z;
      JiggleData->m_Element.baseAccel.x = -JiggleData->m_Element.baseAccel.x;
      JiggleData->m_Element.baseAccel.y = -v21;
      JiggleData->m_Element.baseAccel.z = -v22;
      v23 = JiggleData->m_Element.tipPos.y;
      v24 = JiggleData->m_Element.tipPos.z;
      JiggleData->m_Element.tipPos.x = -JiggleData->m_Element.tipPos.x;
      JiggleData->m_Element.tipPos.y = -v23;
      JiggleData->m_Element.tipPos.z = -v24;
      v25 = JiggleData->m_Element.tipVel.y;
      v26 = JiggleData->m_Element.tipVel.z;
      JiggleData->m_Element.tipVel.x = -JiggleData->m_Element.tipVel.x;
      JiggleData->m_Element.tipVel.y = -v25;
      JiggleData->m_Element.tipVel.z = -v26;
      v27 = -JiggleData->m_Element.tipAccel.y;
      v28 = -JiggleData->m_Element.tipAccel.z;
      JiggleData->m_Element.tipAccel.x = -JiggleData->m_Element.tipAccel.x;
      JiggleData->m_Element.tipAccel.y = v27;
      JiggleData->m_Element.tipAccel.z = v28;
    }
    if ( JiggleBoneSanity.m_pParent->m_Value.m_nValue != 0 )
    {
      localError.x = goalTip.x - goalBasePosition.x;
      localError.y = goalTip.y - goalBasePosition.y;
      localError.z = goalTip.z - goalBasePosition.z;
      VectorNormalize(vec: &localError);
      left.x = p_m_Element->tipPos.x - goalBasePosition.x;
      left.y = p_m_Element->tipPos.y - goalBasePosition.y;
      left.z = p_m_Element->tipPos.z - goalBasePosition.z;
      VectorNormalize(vec: &left);
      if ( (float)((float)((float)(left.x * localError.x) + (float)(left.y * localError.y))
                 + (float)(left.z * localError.z)) < -0.89999998 )
        JiggleData::Init(
          this: p_m_Element,
          initBone: boneIndex,
          currenttime,
          initBasePos: &goalBasePosition,
          initTipPos: &goalTip);
      v12 = currenttime;
    }
    v29 = 0.001;
    v30 = v12 - p_m_Element->lastUpdate;
    if ( v30 >= 0.001 )
    {
      v29 = 0.033300001;
      if ( v30 <= 0.033300001 )
        v29 = v12 - p_m_Element->lastUpdate;
    }
    p_m_Element->lastUpdate = v12;
    deltaT = v29;
    if ( (v8->flags & 3) != 0 )
    {
      p_m_Element->tipAccel.z = p_m_Element->tipAccel.z - v8->tipMass;
      flags = v8->flags;
      if ( (v8->flags & 1) != 0 )
      {
        v32 = goalTip.y - p_m_Element->tipPos.y;
        v33 = goalTip.z - p_m_Element->tipPos.z;
        v34 = (float)((float)((float)(goalTip.x - p_m_Element->tipPos.x) * goalLeft.x) + (float)(goalLeft.y * v32))
            + (float)(goalLeft.z * v33);
        v35 = goalTip.x - p_m_Element->tipPos.x;
        v36 = p_m_Element->tipVel.z;
        localAlong.z = (float)((float)(v32 * goalForward.y) + (float)(v35 * goalForward.x))
                     + (float)(v33 * goalForward.z);
        sy = LODWORD(p_m_Element->tipVel.x);
        v37 = (float)((float)(v35 * goalUp.x) + (float)(goalUp.y * v32)) + (float)(goalUp.z * v33);
        v38 = p_m_Element->tipVel.y;
        maxBetween = v36;
        jiggleInfo = (float)(goalUp.x * *(float *)&sy) + (float)(v38 * goalUp.y);
        v39 = jiggleInfo + (float)(v36 * goalUp.z);
        v40 = (float)(v8->yawStiffness * v34)
            - (float)(v8->yawDamping
                    * (float)((float)((float)(goalLeft.x * *(float *)&sy) + (float)(v38 * goalLeft.y))
                            + (float)(v36 * goalLeft.z)));
        v41 = (float)(v8->pitchStiffness * v37) - (float)(v8->pitchDamping * v39);
        v42 = goalLeft.x * v40;
        if ( (flags & 0x20) != 0 )
        {
          v43 = (float)((float)(goalLeft.y * v40) + (float)(goalUp.y * v41)) + p_m_Element->tipAccel.y;
          v44 = v42 + (float)(goalUp.x * v41);
          v45 = (float)(goalLeft.z * v40) + (float)(goalUp.z * v41);
          p_m_Element->tipAccel.y = v43;
        }
        else
        {
          v46 = (float)(v8->alongStiffness * localAlong.z)
              - (float)((float)((float)((float)(goalForward.x * *(float *)&sy) + (float)(v38 * goalForward.y))
                              + (float)(maxBetween * goalForward.z))
                      * v8->alongDamping);
          v47 = goalForward.z * v46;
          v48 = goalForward.x * v46;
          v49 = goalForward.y * v46;
          left.x = goalUp.x * v41;
          v50 = v42 + (float)(goalUp.x * v41);
          left.y = goalUp.y * v41;
          v51 = goalUp.z * v41;
          v52 = (float)(goalLeft.y * v40) + (float)(goalUp.y * v41);
          left.z = v51;
          v44 = v50 + v48;
          v45 = (float)((float)(goalLeft.z * v40) + v51) + v47;
          p_m_Element->tipAccel.y = (float)(v52 + v49) + p_m_Element->tipAccel.y;
        }
        v53 = v44 + p_m_Element->tipAccel.x;
        p_m_Element->tipAccel.z = v45 + p_m_Element->tipAccel.z;
        p_m_Element->tipAccel.x = v53;
      }
      v54 = p_m_Element->tipAccel.z;
      v55 = p_m_Element->tipAccel.y;
      v56 = (float)(p_m_Element->tipAccel.x * v29) + p_m_Element->tipVel.x;
      p_m_Element->tipVel.x = v56;
      p_m_Element->tipVel.z = (float)(v54 * v29) + p_m_Element->tipVel.z;
      v57 = (float)(v55 * v29) + p_m_Element->tipVel.y;
      p_m_Element->tipVel.y = v57;
      v58 = v56;
      v59 = (float)(v57 * v29) + p_m_Element->tipPos.y;
      v60 = (float)(p_m_Element->tipVel.z * v29) + p_m_Element->tipPos.z;
      v61 = v58 * v29;
      v62 = p_m_Element->tipPos.x;
      p_m_Element->tipPos.y = v59;
      p_m_Element->tipPos.z = v60;
      p_m_Element->tipPos.x = v62 + v61;
      p_m_Element->tipAccel = vec3_origin;
      v63 = v8->flags;
      if ( (v8->flags & 0xC) != 0 )
      {
        v64 = p_m_Element->tipPos.y - goalBasePosition.y;
        v65 = p_m_Element->tipPos.x - goalBasePosition.x;
        v66 = p_m_Element->tipPos.z - goalBasePosition.z;
        v67 = (float)((float)(v64 * goalLeft.y) + (float)(goalLeft.x * v65)) + (float)(v66 * goalLeft.z);
        v68 = (float)((float)(v64 * goalUp.y) + (float)(goalUp.x * v65)) + (float)(v66 * goalUp.z);
        localError.y = v64;
        localError.z = v66;
        localError.x = v65;
        localAlong.y = v68;
        localAlong.z = (float)((float)(goalForward.x * v65) + (float)(v64 * goalForward.y))
                     + (float)(v66 * goalForward.z);
        if ( (v63 & 4) != 0 )
        {
          __libm_sse2_atan2(y: v201, x: *(long double *)&pitchMatrix.m_flMatVal[0][0]);
          minYaw = v8->minYaw;
          if ( minYaw <= v67 && (minYaw = v8->maxYaw, v67 <= minYaw) )
          {
            v68 = localAlong.y;
          }
          else
          {
            pitch = minYaw;
            v208 = COERCE_FLOAT(&jiggleInfo);
            p_sy = &sy;
            jiggleInfo = cos(minYaw);
            *(float *)&sy = sin(minYaw);
            *(_QWORD *)&pitchMatrix.m_flMatVal[2][0] = sy ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
            *(_QWORD *)&pitchMatrix.m_flMatVal[0][0] = LODWORD(jiggleInfo);
            *(_QWORD *)&pitchMatrix.m_flMatVal[1][0] = 0x3F80000000000000LL;
            *(_QWORD *)&pitchMatrix.m_flMatVal[0][2] = sy;
            *(_QWORD *)&pitchMatrix.m_flMatVal[1][2] = 0;
            *(_QWORD *)&pitchMatrix.m_flMatVal[2][2] = LODWORD(jiggleInfo);
            ConcatTransforms(in1: goalMX, in2: &pitchMatrix, out: &limitMatrix);
            v70 = limitMatrix.m_flMatVal[0][2];
            v71 = limitMatrix.m_flMatVal[1][2];
            v72 = (float)((float)(limitMatrix.m_flMatVal[0][2] * localError.x)
                        + (float)(localError.y * limitMatrix.m_flMatVal[1][2]))
                + (float)(localError.z * limitMatrix.m_flMatVal[2][2]);
            localAlong.z = limitMatrix.m_flMatVal[2][2] * v72;
            v73 = limitMatrix.m_flMatVal[0][2] * v72;
            v74 = limitMatrix.m_flMatVal[1][2] * v72;
            v75 = (float)((float)(limitMatrix.m_flMatVal[0][1] * localError.x)
                        + (float)(localError.y * limitMatrix.m_flMatVal[1][1]))
                + (float)(localError.z * limitMatrix.m_flMatVal[2][1]);
            v76 = (float)(limitMatrix.m_flMatVal[1][1] * v75) + goalBasePosition.y;
            v77 = (float)((float)(limitMatrix.m_flMatVal[2][1] * v75) + goalBasePosition.z) + localAlong.z;
            p_m_Element->tipPos.x = (float)(goalBasePosition.x + (float)(limitMatrix.m_flMatVal[0][1] * v75)) + v73;
            p_m_Element->tipPos.y = v76 + v74;
            p_m_Element->tipPos.z = v77;
            v78 = p_m_Element->tipVel.z;
            v79 = (float)((float)(p_m_Element->tipVel.y * v71) + (float)(p_m_Element->tipVel.x * v70))
                + (float)(v78 * limitMatrix.m_flMatVal[2][2]);
            v80 = (float)((float)(p_m_Element->tipVel.y * limitMatrix.m_flMatVal[1][1])
                        + (float)(p_m_Element->tipVel.x * limitMatrix.m_flMatVal[0][1]))
                + (float)(v78 * limitMatrix.m_flMatVal[2][1]);
            v81 = v79 * v70;
            v82 = v80 * limitMatrix.m_flMatVal[0][1];
            v83 = v79 * v71;
            v84 = v80 * limitMatrix.m_flMatVal[1][1];
            v208 = v80 * limitMatrix.m_flMatVal[2][1];
            v85 = v80 * limitMatrix.m_flMatVal[2][1];
            yawFriction = v8->yawFriction;
            jiggleInfo = v79 * limitMatrix.m_flMatVal[2][2];
            v87 = (float)(v85 + (float)(v79 * limitMatrix.m_flMatVal[2][2])) * yawFriction;
            p_m_Element->tipAccel.x = p_m_Element->tipAccel.x - (float)((float)(v82 + v81) * yawFriction);
            v88 = limitMatrix.m_flMatVal[0][0];
            p_m_Element->tipAccel.y = p_m_Element->tipAccel.y - (float)((float)(v84 + v83) * yawFriction);
            p_m_Element->tipAccel.z = p_m_Element->tipAccel.z - v87;
            v89 = v8->yawBounce * -0.0;
            v90 = v81;
            localAlong.x = v81;
            v91 = limitMatrix.m_flMatVal[1][0] * v89;
            localAlong.y = v83;
            p_m_Element->tipVel.z = (float)((float)(limitMatrix.m_flMatVal[2][0] * v89) + v208) + jiggleInfo;
            p_m_Element->tipVel.y = (float)(v91 + v84) + v83;
            p_m_Element->tipVel.x = (float)((float)(v88 * v89) + v82) + v90;
            v92 = p_m_Element->tipPos.x - goalBasePosition.x;
            v93 = p_m_Element->tipPos.z - goalBasePosition.z;
            v68 = (float)((float)((float)(p_m_Element->tipPos.y - goalBasePosition.y) * goalUp.y)
                        + (float)(goalUp.x * v92))
                + (float)(v93 * goalUp.z);
            localError.y = p_m_Element->tipPos.y - goalBasePosition.y;
            localError.x = v92;
            localError.z = v93;
          }
        }
        if ( (v8->flags & 8) != 0 )
        {
          __libm_sse2_atan2(y: v201, x: *(long double *)&pitchMatrix.m_flMatVal[0][0]);
          minPitch = v8->minPitch;
          if ( minPitch > v68 || (minPitch = v8->maxPitch, v68 > minPitch) )
          {
            pitch = minPitch;
            p_sy = (unsigned int *)&jiggleInfo;
            v208 = COERCE_FLOAT(&sy);
            jiggleInfo = cos(minPitch);
            *(float *)&sy = sin(minPitch);
            *(_QWORD *)&pitchMatrix.m_flMatVal[0][0] = 1065353216;
            pitchMatrix.m_flMatVal[2][0] = 0.0;
            pitchMatrix.m_flMatVal[1][1] = jiggleInfo;
            LODWORD(pitchMatrix.m_flMatVal[2][1]) = sy ^ _mask__NegFloat_;
            memset(&pitchMatrix.m_flMatVal[0][2], 0, 12);
            *(_QWORD *)&pitchMatrix.m_flMatVal[1][2] = sy;
            *(_QWORD *)&pitchMatrix.m_flMatVal[2][2] = LODWORD(jiggleInfo);
            ConcatTransforms(in1: goalMX, in2: &pitchMatrix, out: &limitMatrix);
            v95 = limitMatrix.m_flMatVal[1][0];
            v96 = limitMatrix.m_flMatVal[2][0];
            v97 = (float)((float)(limitMatrix.m_flMatVal[0][2] * localError.x)
                        + (float)(localError.y * limitMatrix.m_flMatVal[1][2]))
                + (float)(localError.z * limitMatrix.m_flMatVal[2][2]);
            v98 = limitMatrix.m_flMatVal[0][2] * v97;
            localAlong.y = limitMatrix.m_flMatVal[1][2] * v97;
            localAlong.z = limitMatrix.m_flMatVal[2][2] * v97;
            v99 = limitMatrix.m_flMatVal[0][0];
            v100 = (float)((float)(limitMatrix.m_flMatVal[0][0] * localError.x)
                         + (float)(localError.y * limitMatrix.m_flMatVal[1][0]))
                 + (float)(localError.z * limitMatrix.m_flMatVal[2][0]);
            v101 = limitMatrix.m_flMatVal[0][0] * v100;
            v102 = (float)((float)(limitMatrix.m_flMatVal[1][0] * v100) + goalBasePosition.y) + localAlong.y;
            v103 = limitMatrix.m_flMatVal[2][0] * v100;
            v104 = goalBasePosition.x;
            v105 = (float)(v103 + goalBasePosition.z) + localAlong.z;
            p_m_Element->tipPos.y = v102;
            p_m_Element->tipPos.x = (float)(v104 + v101) + v98;
            p_m_Element->tipPos.z = v105;
            v106 = p_m_Element->tipVel.y;
            v107 = p_m_Element->tipVel.x;
            maxBetweenb = p_m_Element->tipVel.z;
            v108 = v106 * limitMatrix.m_flMatVal[1][1];
            v109 = v107 * limitMatrix.m_flMatVal[0][1];
            v110 = (float)((float)(v106 * limitMatrix.m_flMatVal[1][2]) + (float)(v107 * limitMatrix.m_flMatVal[0][2]))
                 + (float)(maxBetweenb * limitMatrix.m_flMatVal[2][2]);
            v111 = v110 * limitMatrix.m_flMatVal[0][2];
            v112 = (float)(v108 + v109) + (float)(maxBetweenb * limitMatrix.m_flMatVal[2][1]);
            v113 = v110 * limitMatrix.m_flMatVal[1][2];
            maxBetweenc = v110 * limitMatrix.m_flMatVal[2][2];
            localError.z = v110 * limitMatrix.m_flMatVal[2][2];
            v114 = v99 * 0.0;
            pitchFriction = v8->pitchFriction;
            jiggleInfo = v95 * 0.0;
            v208 = v96 * 0.0;
            v116 = (float)((float)(v96 * 0.0) + localError.z) * pitchFriction;
            p_m_Element->tipAccel.x = p_m_Element->tipAccel.x - (float)((float)(v114 + v111) * pitchFriction);
            p_m_Element->tipAccel.y = p_m_Element->tipAccel.y
                                    - (float)((float)((float)(v95 * 0.0) + v113) * pitchFriction);
            p_m_Element->tipAccel.z = p_m_Element->tipAccel.z - v116;
            v117 = v8->pitchBounce * v112;
            v118 = limitMatrix.m_flMatVal[0][1] * v117;
            v119 = limitMatrix.m_flMatVal[1][1] * v117;
            localAlong.z = limitMatrix.m_flMatVal[2][1] * v117;
            v120 = v114;
            v121 = (float)(jiggleInfo - v119) + v113;
            v122 = (float)(v208 - localAlong.z) + maxBetweenc;
            localError.x = v111;
            localError.y = v113;
            p_m_Element->tipVel.x = (float)(v120 - v118) + v111;
            p_m_Element->tipVel.y = v121;
            p_m_Element->tipVel.z = v122;
          }
        }
      }
      forward.x = p_m_Element->tipPos.x - goalBasePosition.x;
      forward.y = p_m_Element->tipPos.y - goalBasePosition.y;
      forward.z = p_m_Element->tipPos.z - goalBasePosition.z;
      VectorNormalize(vec: &forward);
      if ( (v8->flags & 0x10) != 0 )
      {
        maxBetweena = (float)((float)(goalForward.x * forward.x) + (float)(goalForward.y * forward.y))
                    + (float)(goalForward.z * forward.z);
        __libm_sse2_acos(x: v201);
        v123 = maxBetweena;
        if ( maxBetweena < 0.0 )
          v123 = 6.283185307179586 - maxBetweena;
        angleLimit = v8->angleLimit;
        if ( v123 > angleLimit )
        {
          __libm_sse2_sin(x: v202);
          maxBetweend = angleLimit * v8->length;
          localError.x = goalTip.x - p_m_Element->tipPos.x;
          localError.y = goalTip.y - p_m_Element->tipPos.y;
          localError.z = goalTip.z - p_m_Element->tipPos.z;
          VectorNormalize(vec: &localError);
          v125 = goalTip.x - (float)(maxBetweend * localError.x);
          v126 = goalTip.z - (float)(localError.z * maxBetweend);
          p_m_Element->tipPos.y = goalTip.y - (float)(localError.y * maxBetweend);
          p_m_Element->tipPos.z = v126;
          p_m_Element->tipPos.x = v125;
          v127 = p_m_Element->tipPos.y - goalBasePosition.y;
          v128 = p_m_Element->tipPos.z - goalBasePosition.z;
          forward.x = v125 - goalBasePosition.x;
          forward.y = v127;
          forward.z = v128;
          VectorNormalize(vec: &forward);
        }
      }
      v129 = forward.z;
      v130 = forward.y;
      v131 = forward.x;
      if ( (v8->flags & 0x20) != 0 )
      {
        length = v8->length;
        v133 = forward.x * length;
        p_m_Element->tipPos.y = (float)(forward.y * length) + goalBasePosition.y;
        v134 = (float)(v129 * length) + goalBasePosition.z;
        v135 = goalBasePosition.x;
        p_m_Element->tipPos.z = v134;
        p_m_Element->tipPos.x = v135 + v133;
        v136 = (float)((float)(p_m_Element->tipVel.x * v131) + (float)(v130 * p_m_Element->tipVel.y))
             + (float)(v129 * p_m_Element->tipVel.z);
        p_m_Element->tipVel.x = p_m_Element->tipVel.x - (float)(v131 * v136);
        p_m_Element->tipVel.y = p_m_Element->tipVel.y - (float)(v130 * v136);
        p_m_Element->tipVel.z = p_m_Element->tipVel.z - (float)(v129 * v136);
      }
      left.x = (float)(goalUp.y * v129) - (float)(goalUp.z * v130);
      left.y = (float)(goalUp.z * v131) - (float)(goalUp.x * v129);
      left.z = (float)(goalUp.x * v130) - (float)(goalUp.y * v131);
      VectorNormalize(vec: &left);
      v137 = boneMX;
      v138 = forward.y;
      v139 = forward.z;
      v140 = left.z;
      v141 = left.x;
      v142 = forward.x;
      boneMX->m_flMatVal[0][1] = (float)(forward.y * left.z) - (float)(forward.z * left.y);
      v137->m_flMatVal[0][2] = forward.x;
      v137->m_flMatVal[0][3] = goalBasePosition.x;
      v143 = (float)(v139 * v141) - (float)(v142 * v140);
      v144 = forward.x * left.y;
      v137->m_flMatVal[1][3] = goalBasePosition.y;
      v145 = goalBasePosition.z;
      v146 = v138 * v141;
      v137->m_flMatVal[0][0] = v141;
      v147 = left.y;
      v137->m_flMatVal[2][3] = v145;
      v29 = deltaT;
      v137->m_flMatVal[1][0] = v147;
      v137->m_flMatVal[2][0] = v140;
      v137->m_flMatVal[1][1] = v143;
      v137->m_flMatVal[2][1] = v144 - v146;
      v137->m_flMatVal[1][2] = v138;
      v137->m_flMatVal[2][2] = v139;
    }
    else
    {
      v137 = boneMX;
    }
    if ( (v8->flags & 0x40) != 0 )
    {
      p_m_Element->baseAccel.z = p_m_Element->baseAccel.z - v8->baseMass;
      baseDamping = v8->baseDamping;
      p_x = &p_m_Element->basePos.x;
      v150 = p_m_Element->baseVel.y * baseDamping;
      v151 = p_m_Element->baseVel.z * baseDamping;
      baseStiffness = v8->baseStiffness;
      v153 = (float)(goalBasePosition.y - p_m_Element->basePos.y) * baseStiffness;
      v154 = (float)(goalBasePosition.z - p_m_Element->basePos.z) * baseStiffness;
      v155 = p_m_Element->baseAccel.x
           + (float)((float)((float)(goalBasePosition.x - p_m_Element->basePos.x) * baseStiffness)
                   - (float)(v8->baseDamping * p_m_Element->baseVel.x));
      p_m_Element->baseAccel.x = v155;
      v156 = (float)(v153 - v150) + p_m_Element->baseAccel.y;
      p_m_Element->baseAccel.y = v156;
      v157 = (float)(v154 - v151) + p_m_Element->baseAccel.z;
      p_m_Element->baseAccel.z = v157;
      v158 = (float)(v156 * v29) + p_m_Element->baseVel.y;
      p_m_Element->baseVel.y = v158;
      v159 = (float)(v157 * v29) + p_m_Element->baseVel.z;
      p_m_Element->baseVel.z = v159;
      v160 = (float)(v155 * v29) + p_m_Element->baseVel.x;
      p_m_Element->baseVel.x = v160;
      p_m_Element->basePos.y = (float)(v158 * v29) + p_m_Element->basePos.y;
      p_m_Element->basePos.x = (float)(v160 * v29) + p_m_Element->basePos.x;
      p_m_Element->basePos.z = (float)(v159 * v29) + p_m_Element->basePos.z;
      p_m_Element->baseAccel = vec3_origin;
      v161 = p_m_Element->basePos.y - goalBasePosition.y;
      v162 = p_m_Element->basePos.x - goalBasePosition.x;
      v163 = (float)((float)(v161 * goalLeft.y) + (float)(goalLeft.x * v162))
           + (float)((float)(p_m_Element->basePos.z - goalBasePosition.z) * goalLeft.z);
      v164 = (float)((float)(v161 * goalUp.y) + (float)(goalUp.x * v162))
           + (float)((float)(p_m_Element->basePos.z - goalBasePosition.z) * goalUp.z);
      v165 = goalForward.x * v162;
      v166 = p_m_Element->baseVel.y;
      v167 = goalUp.x * p_m_Element->baseVel.x;
      v168 = (float)(v161 * goalForward.y) + v165;
      v169 = goalForward.z;
      v170 = goalLeft.x * p_m_Element->baseVel.x;
      localError.z = v168 + (float)((float)(p_m_Element->basePos.z - goalBasePosition.z) * goalForward.z);
      maxBetweene = p_m_Element->baseVel.z;
      v171 = (float)((float)(v166 * goalLeft.y) + v170) + (float)(maxBetweene * goalLeft.z);
      v172 = (float)((float)(v166 * goalUp.y) + v167) + (float)(maxBetweene * goalUp.z);
      v173 = (float)((float)(v166 * goalForward.y) + (float)(goalForward.x * p_m_Element->baseVel.x))
           + (float)(maxBetweene * goalForward.z);
      baseMinLeft = v8->baseMinLeft;
      if ( baseMinLeft > v163 || (baseMinLeft = v8->baseMaxLeft, v163 > baseMinLeft) )
      {
        v163 = baseMinLeft;
        left.x = goalForward.x * v173;
        left.z = goalForward.z * v173;
        left.y = goalForward.y * v173;
        localAlong.z = (float)(goalUp.z * v172) + (float)(goalForward.z * v173);
        baseLeftFriction = v8->baseLeftFriction;
        left.y = (float)((float)(goalUp.y * v172) + (float)(goalForward.y * v173)) * baseLeftFriction;
        v176 = localAlong.z * baseLeftFriction;
        v177 = p_m_Element->baseAccel.x
             - (float)((float)((float)(goalUp.x * v172) + (float)(goalForward.x * v173)) * baseLeftFriction);
        p_m_Element->baseAccel.y = p_m_Element->baseAccel.y - left.y;
        v178 = p_m_Element->baseAccel.z - v176;
        p_m_Element->baseAccel.x = v177;
        p_m_Element->baseAccel.z = v178;
        v169 = goalForward.z;
      }
      baseMinUp = v8->baseMinUp;
      if ( baseMinUp > v164 || (baseMinUp = v8->baseMaxUp, v164 > baseMinUp) )
      {
        v164 = baseMinUp;
        localAlong.z = v169 * v173;
        baseUpFriction = v8->baseUpFriction;
        localAlong.y = goalForward.y * v173;
        v181 = (float)((float)(goalLeft.z * v171) + (float)(v169 * v173)) * baseUpFriction;
        v182 = (float)((float)(goalLeft.y * v171) + (float)(goalForward.y * v173)) * baseUpFriction;
        v183 = p_m_Element->baseAccel.x
             - (float)((float)((float)(goalLeft.x * v171) + (float)(goalForward.x * v173)) * baseUpFriction);
        p_m_Element->baseAccel.y = p_m_Element->baseAccel.y - v182;
        v184 = p_m_Element->baseAccel.z - v181;
        p_m_Element->baseAccel.x = v183;
        p_m_Element->baseAccel.z = v184;
        v169 = goalForward.z;
      }
      baseMinForward = v8->baseMinForward;
      v186 = localError.z;
      if ( baseMinForward > localError.z || (baseMinForward = v8->baseMaxForward, localError.z > baseMinForward) )
      {
        localAlong.y = goalUp.y * v172;
        localAlong.z = goalUp.z * v172;
        v187 = (float)(goalLeft.y * v171) + (float)(goalUp.y * v172);
        v186 = baseMinForward;
        v188 = (float)(goalLeft.z * v171) + (float)(goalUp.z * v172);
        v189 = goalUp.x * v172;
        v190 = goalLeft.x * v171;
        baseForwardFriction = v8->baseForwardFriction;
        p_m_Element->baseAccel.x = p_m_Element->baseAccel.x - (float)((float)(v190 + v189) * baseForwardFriction);
        p_m_Element->baseAccel.y = p_m_Element->baseAccel.y - (float)(v187 * baseForwardFriction);
        p_m_Element->baseAccel.z = p_m_Element->baseAccel.z - (float)(v188 * baseForwardFriction);
        v169 = goalForward.z;
      }
      v192 = goalForward.x * v186;
      localAlong.y = goalUp.y * v164;
      localAlong.z = goalUp.z * v164;
      v193 = (float)((float)(goalLeft.y * v163) + goalBasePosition.y) + (float)(goalUp.y * v164);
      v194 = (float)((float)(goalLeft.z * v163) + goalBasePosition.z) + (float)(goalUp.z * v164);
      v195 = (float)(goalBasePosition.x + (float)(goalLeft.x * v163)) + (float)(goalUp.x * v164);
      v196 = v193 + (float)(goalForward.y * v186);
      p_m_Element->basePos.y = v196;
      v197 = v194 + (float)(v169 * v186);
      p_m_Element->basePos.z = v197;
      v198 = v195 + v192;
      *p_x = v198;
      v199 = v196 - p_m_Element->baseLastPos.y;
      v200 = v197 - p_m_Element->baseLastPos.z;
      p_m_Element->baseVel.x = (float)(1.0 / deltaT) * (float)(v198 - p_m_Element->baseLastPos.x);
      p_m_Element->baseVel.y = v199 * (float)(1.0 / deltaT);
      p_m_Element->baseVel.z = v200 * (float)(1.0 / deltaT);
      p_m_Element->baseLastPos.x = *p_x;
      p_m_Element->baseLastPos.y = p_m_Element->basePos.y;
      p_m_Element->baseLastPos.z = p_m_Element->basePos.z;
      if ( (v8->flags & 3) == 0 )
        *v137 = *goalMX;
      MatrixSetColumn(in: &p_m_Element->basePos, column: 3, out: v137);
    }
    else if ( (v8->flags & 3) == 0 )
    {
      *v137 = *goalMX;
    }
  }
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00409400
// Name: public: bool CUtlLinkedList<struct HitboxInfo_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct HitboxInfo_t,unsigned short>,unsigned short>>::IsInList(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::IsInList(
        CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  return i < this->m_Memory.m_nAllocationCount
      && i <= this->m_LastAlloc.index
      && this->m_Memory.m_pMemory[i].m_Previous != i;
}

//------------------------------------------------------------------------------
// Address: 0x00409440
// Name: public: void CUtlLinkedList<struct HitboxInfo_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct HitboxInfo_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004094D0
// Name: protected: unsigned short CUtlLinkedList<struct HitboxInfo_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct HitboxInfo_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<VMatrix>,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<LayerEvent_t<VMatrix>,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x0040A670
// Name: public: void CUtlLinkedList<struct HitboxInfo_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct HitboxInfo_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *m_pMemory; // ebx
  unsigned int v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = elem;
  this->m_Memory.m_pMemory[v5].m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    m_pMemory[v5].m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = before;
    m_Tail = m_pMemory[v7].m_Previous;
    m_pMemory[v5].m_Previous = m_Tail;
    m_pMemory[v7].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BAD0
// Name: public: void CUtlLinkedList<struct HitboxInfo_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct HitboxInfo_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // bx
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *v2; // esi
  bool v3; // sf
  unsigned __int16 m_Next; // di
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 v6; // ax
  CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *v7; // [esp+0h] [ebp-4h]

  v7 = this;
  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        v3 = v2->m_Element.m_Name.m_Storage.m_Memory.m_nGrowSize < 0;
        m_Next = v2->m_Next;
        v2->m_Element.m_Name.m_Storage.m_nActualLength = 0;
        if ( !v3 )
        {
          if ( v2->m_Element.m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2->m_Element.m_Name.m_Storage.m_Memory.m_pMemory);
            this = v7;
            v2->m_Element.m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v2->m_Element.m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v6 = this->m_Head;
    if ( v6 != 0xFFFF )
      this->m_FirstFree = v6;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BD60
// Name: public: void CUtlLinkedList<struct HitboxInfo_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct HitboxInfo_t,unsigned short>,unsigned short>>::Remove(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::Remove(
        CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *v3; // esi
  bool v4; // sf

  CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  v3 = &this->m_Memory.m_pMemory[elem];
  v4 = v3->m_Element.m_Name.m_Storage.m_Memory.m_nGrowSize < 0;
  v3->m_Element.m_Name.m_Storage.m_nActualLength = 0;
  if ( !v4 )
  {
    if ( v3->m_Element.m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Element.m_Name.m_Storage.m_Memory.m_pMemory);
      v3->m_Element.m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    v3->m_Element.m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  v3->m_Next = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x00413480
// Name: public: void JiggleData::Init(int,float,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall JiggleData::Init(
        JiggleData *this,
        int initBone,
        float currenttime,
        const Vector *initBasePos,
        const Vector *initTipPos)
{
  this->bone = initBone;
  this->lastUpdate = currenttime;
  this->basePos = *initBasePos;
  this->baseLastPos = this->basePos;
  this->baseVel.x = 0.0;
  this->baseVel.y = 0.0;
  this->baseVel.z = 0.0;
  this->baseAccel.x = 0.0;
  this->baseAccel.y = 0.0;
  this->baseAccel.z = 0.0;
  this->tipPos = *initTipPos;
  this->tipVel.x = 0.0;
  this->tipVel.y = 0.0;
  this->tipVel.z = 0.0;
  this->tipAccel.x = 0.0;
  this->tipAccel.y = 0.0;
  this->tipAccel.z = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004135C0
// Name: protected: unsigned short CUtlLinkedList<struct JiggleData,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct JiggleData,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  unsigned int v9; // ecx
  UtlLinkedListElem_t<JiggleData,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<JiggleData,unsigned short> *v11; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = (unsigned __int16)result;
    if ( multilist )
    {
      v11 = &this->m_Memory.m_pMemory[v9];
      v11->m_Next = -1;
      v11->m_Previous = -1;
    }
    else
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pMemory[v9].m_Next = result;
      m_pMemory[v9].m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x00413740
// Name: public: void CUtlLinkedList<struct JiggleData,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct JiggleData,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<JiggleData,unsigned short> *v3; // eax
  int m_Previous; // edi
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004137D0
// Name: public: void CUtlLinkedList<struct JiggleData,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct JiggleData,unsigned short>,unsigned short>>::LinkAfter(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::LinkAfter(
        CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short> > *this,
        unsigned __int16 after,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<JiggleData,unsigned short> *v4; // edi
  UtlLinkedListElem_t<JiggleData,unsigned short> *v5; // eax
  int m_Next; // eax

  if ( elem < this->m_Memory.m_nAllocationCount
    && elem <= this->m_LastAlloc.index
    && this->m_Memory.m_pMemory[elem].m_Previous != elem )
  {
    CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::Unlink(
      this,
      elem);
  }
  v4 = &this->m_Memory.m_pMemory[elem];
  v4->m_Previous = after;
  if ( after == 0xFFFF )
  {
    v4->m_Next = this->m_Head;
    this->m_Head = elem;
  }
  else
  {
    v5 = &this->m_Memory.m_pMemory[after];
    v4->m_Next = v5->m_Next;
    v5->m_Next = elem;
  }
  m_Next = v4->m_Next;
  if ( (_WORD)m_Next == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Tail = elem;
  }
  else
  {
    this->m_Memory.m_pMemory[m_Next].m_Previous = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413870
// Name: public: struct JiggleData __near * CJiggleBones::GetJiggleData(int,float,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
UtlLinkedListElem_t<JiggleData,unsigned short> *__thiscall CJiggleBones::GetJiggleData(
        CJiggleBones *this,
        int bone,
        float currenttime,
        const Vector *initBasePos,
        const Vector *initTipPos)
{
  CJiggleBones *v5; // esi
  int m_Head; // eax
  UtlLinkedListElem_t<JiggleData,unsigned short> *m_pMemory; // edi
  int v8; // ecx
  float z; // xmm2_4
  float x; // xmm0_4
  float v11; // xmm1_4
  unsigned __int16 v12; // ax
  int v13; // ebx
  unsigned __int16 v14; // ax
  int v15; // esi
  JiggleData *p_m_Element; // edi
  JiggleData data; // [esp+Ch] [ebp-64h] BYREF
  CJiggleBones *v19; // [esp+6Ch] [ebp-4h]

  v5 = this;
  m_Head = this->m_jiggleBoneState.m_Head;
  v19 = this;
  if ( m_Head == 0xFFFF )
  {
LABEL_5:
    z = initBasePos->z;
    data.lastUpdate = currenttime;
    x = initBasePos->x;
    data.basePos.y = initBasePos->y;
    data.baseLastPos.y = data.basePos.y;
    data.tipPos.x = initTipPos->x;
    data.tipPos.y = initTipPos->y;
    v11 = initTipPos->z;
    data.id = s_id;
    data.basePos.x = x;
    data.baseLastPos.x = x;
    data.bone = bone;
    data.basePos.z = z;
    data.baseLastPos.z = z;
    memset(&data.baseVel, 0, 24);
    data.tipPos.z = v11;
    memset(&data.tipVel, 0, 24);
    ++s_id;
    v12 = CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::AllocInternal(
            this: &v5->m_jiggleBoneState,
            multilist: false);
    v13 = v12;
    if ( v12 == 0xFFFF )
    {
      v14 = -1;
    }
    else
    {
      CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::LinkAfter(
        this: &v5->m_jiggleBoneState,
        after: 0xFFFFu,
        elem: v12);
      p_m_Element = &v5->m_jiggleBoneState.m_Memory.m_pMemory[v13].m_Element;
      if ( p_m_Element != nullptr )
      {
        *p_m_Element = data;
        v5 = v19;
      }
      v14 = v13;
    }
    if ( v14 == 0xFFFF )
      return nullptr;
    else
      return &v5->m_jiggleBoneState.m_Memory.m_pMemory[v14];
  }
  else
  {
    m_pMemory = this->m_jiggleBoneState.m_Memory.m_pMemory;
    while ( 1 )
    {
      v8 = (unsigned __int16)m_Head;
      if ( m_pMemory[v8].m_Element.bone == bone )
        break;
      m_Head = m_pMemory[v8].m_Next;
      if ( m_Head == 0xFFFF )
        goto LABEL_5;
    }
    v15 = (unsigned __int16)m_Head;
    if ( (LODWORD(m_pMemory[v15].m_Element.lastUpdate) & 0x7F800000) == 0x7F800000 )
      _Warning(a1: "lastUpdate NaN\n");
    if ( (LODWORD(m_pMemory[v15].m_Element.basePos.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.basePos.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.basePos.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "basePos NaN\n");
    }
    if ( (LODWORD(m_pMemory[v15].m_Element.baseLastPos.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.baseLastPos.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.baseLastPos.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "baseLastPos NaN\n");
    }
    if ( (LODWORD(m_pMemory[v15].m_Element.baseVel.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.baseVel.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.baseVel.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "baseVel NaN\n");
    }
    if ( (LODWORD(m_pMemory[v15].m_Element.baseAccel.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.baseAccel.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.baseAccel.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "baseAccel NaN\n");
    }
    if ( (LODWORD(m_pMemory[v15].m_Element.tipPos.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.tipPos.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.tipPos.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "tipPos NaN\n");
    }
    if ( (LODWORD(m_pMemory[v15].m_Element.tipVel.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.tipVel.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.tipVel.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "tipVel NaN\n");
    }
    if ( (LODWORD(m_pMemory[v15].m_Element.tipAccel.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.tipAccel.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.tipAccel.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "tipAccel NaN\n");
    }
    return &v19->m_jiggleBoneState.m_Memory.m_pMemory[v15];
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413C90
// Name: public: void CJiggleBones::BuildJiggleTransformations(int,float,struct mstudiojigglebone_t const __near *,struct matrix3x4_t const __near &,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJiggleBones::BuildJiggleTransformations(
        CJiggleBones *this,
        int boneIndex,
        float currenttime,
        float jiggleInfo,
        const matrix3x4_t *goalMX,
        matrix3x4_t *boneMX)
{
  const matrix3x4_t *v6; // edi
  const mstudiojigglebone_t *v8; // edi
  float v9; // xmm0_4
  UtlLinkedListElem_t<JiggleData,unsigned short> *JiggleData; // eax
  JiggleData *p_m_Element; // esi
  float v12; // xmm4_4
  float x; // xmm1_4
  float v14; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  int flags; // eax
  float v32; // xmm1_4
  float v33; // xmm3_4
  float v34; // xmm7_4
  float v35; // xmm4_4
  float v36; // xmm2_4
  float v37; // xmm7_4
  float v38; // xmm6_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm3_4
  float v42; // xmm5_4
  float v43; // xmm6_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm4_4
  float v47; // xmm1_4
  float v48; // xmm7_4
  float v49; // xmm4_4
  float v50; // xmm3_4
  float v51; // xmm5_4
  float v52; // xmm3_4
  float v53; // xmm2_4
  float v54; // xmm1_4
  float v55; // xmm2_4
  float v56; // xmm3_4
  float v57; // xmm1_4
  float v58; // xmm2_4
  float v59; // xmm3_4
  float v60; // xmm0_4
  int v61; // eax
  float v62; // xmm3_4
  float v63; // xmm0_4
  float v64; // xmm4_4
  float v65; // xmm5_4
  float v66; // xmm2_4
  float minYaw; // xmm1_4
  float v68; // xmm4_4
  float v69; // xmm5_4
  float v70; // xmm0_4
  float v71; // xmm3_4
  float v72; // xmm6_4
  float v73; // xmm0_4
  float v74; // xmm1_4
  float v75; // xmm2_4
  float v76; // xmm6_4
  float v77; // xmm1_4
  float v78; // xmm0_4
  float v79; // xmm2_4
  float v80; // xmm4_4
  float v81; // xmm3_4
  float v82; // xmm5_4
  float v83; // xmm7_4
  float yawFriction; // xmm0_4
  float v85; // xmm7_4
  float v86; // xmm1_4
  float v87; // xmm0_4
  float v88; // xmm6_4
  float v89; // xmm2_4
  float v90; // xmm3_4
  float v91; // xmm1_4
  float minPitch; // xmm1_4
  float v93; // xmm4_4
  float v94; // xmm5_4
  float v95; // xmm0_4
  float v96; // xmm6_4
  float v97; // xmm3_4
  float v98; // xmm0_4
  float v99; // xmm7_4
  float v100; // xmm1_4
  float v101; // xmm2_4
  float v102; // xmm0_4
  float v103; // xmm2_4
  float v104; // xmm0_4
  float v105; // xmm2_4
  float v106; // xmm1_4
  float v107; // xmm6_4
  float v108; // xmm0_4
  float v109; // xmm2_4
  float v110; // xmm1_4
  float v111; // xmm6_4
  float v112; // xmm3_4
  float pitchFriction; // xmm0_4
  float v114; // xmm5_4
  float v115; // xmm0_4
  float v116; // xmm5_4
  float v117; // xmm7_4
  float v118; // xmm0_4
  float v119; // xmm1_4
  float v120; // xmm3_4
  float v121; // xmm1_4
  float angleLimit; // xmm0_4
  float v123; // xmm3_4
  float v124; // xmm1_4
  float v125; // xmm1_4
  float v126; // xmm2_4
  float v127; // xmm2_4
  float v128; // xmm3_4
  float v129; // xmm4_4
  float length; // xmm5_4
  float v131; // xmm6_4
  float v132; // xmm1_4
  float v133; // xmm5_4
  float v134; // xmm0_4
  matrix3x4_t *v135; // ecx
  float v136; // xmm3_4
  float v137; // xmm5_4
  float v138; // xmm4_4
  float v139; // xmm6_4
  float v140; // xmm2_4
  float v141; // xmm1_4
  float v142; // xmm2_4
  float v143; // xmm0_4
  float v144; // xmm7_4
  float v145; // xmm6_4
  float baseStiffness; // xmm7_4
  float v147; // xmm1_4
  float *p_x; // eax
  float v149; // xmm5_4
  float baseDamping; // xmm6_4
  float v151; // xmm4_4
  float v152; // xmm6_4
  float v153; // xmm2_4
  float v154; // xmm3_4
  float v155; // xmm4_4
  float v156; // xmm4_4
  float v157; // xmm2_4
  float v158; // xmm2_4
  float v159; // xmm3_4
  float v160; // xmm1_4
  float v161; // xmm0_4
  float v162; // xmm3_4
  float v163; // xmm2_4
  float v164; // xmm4_4
  float v165; // xmm0_4
  float v166; // xmm5_4
  float v167; // xmm3_4
  float v168; // xmm7_4
  float v169; // xmm1_4
  float v170; // xmm0_4
  float v171; // xmm1_4
  float v172; // xmm3_4
  float baseMinLeft; // xmm6_4
  float baseLeftFriction; // xmm7_4
  float v175; // xmm5_4
  float v176; // xmm7_4
  float v177; // xmm6_4
  float baseMinUp; // xmm6_4
  float baseUpFriction; // xmm7_4
  float v180; // xmm5_4
  float v181; // xmm6_4
  float v182; // xmm7_4
  float v183; // xmm3_4
  float baseMinForward; // xmm6_4
  float v185; // xmm3_4
  float v186; // xmm5_4
  float v187; // xmm6_4
  float v188; // xmm7_4
  float v189; // xmm1_4
  float baseForwardFriction; // xmm0_4
  float v191; // xmm6_4
  float v192; // xmm0_4
  float v193; // xmm1_4
  float v194; // xmm2_4
  float v195; // xmm0_4
  float v196; // xmm1_4
  float v197; // xmm2_4
  float v198; // xmm0_4
  float v199; // xmm1_4
  long double v200; // [esp+Ch] [ebp-E4h]
  long double v201; // [esp+Ch] [ebp-E4h]
  matrix3x4_t pitchMatrix; // [esp+14h] [ebp-DCh] BYREF
  matrix3x4_t limitMatrix; // [esp+44h] [ebp-ACh] BYREF
  unsigned int *p_sy; // [esp+74h] [ebp-7Ch]
  float pitch; // [esp+78h] [ebp-78h]
  Vector goalTip; // [esp+7Ch] [ebp-74h] BYREF
  float v207; // [esp+88h] [ebp-68h]
  Vector forward; // [esp+8Ch] [ebp-64h] BYREF
  unsigned int sy; // [esp+98h] [ebp-58h] BYREF
  Vector localError; // [esp+9Ch] [ebp-54h] BYREF
  Vector goalLeft; // [esp+A8h] [ebp-48h] BYREF
  Vector left; // [esp+B4h] [ebp-3Ch] BYREF
  Vector localAlong; // [esp+C0h] [ebp-30h]
  Vector goalForward; // [esp+CCh] [ebp-24h] BYREF
  Vector goalUp; // [esp+D8h] [ebp-18h] BYREF
  Vector goalBasePosition; // [esp+E4h] [ebp-Ch] BYREF
  float deltaT; // [esp+F8h] [ebp+8h]
  float maxBetween; // [esp+FCh] [ebp+Ch]
  float maxBetweenb; // [esp+FCh] [ebp+Ch]
  float maxBetweenc; // [esp+FCh] [ebp+Ch]
  float maxBetweena; // [esp+FCh] [ebp+Ch]
  float maxBetweend; // [esp+FCh] [ebp+Ch]
  float maxBetweene; // [esp+FCh] [ebp+Ch]

  v6 = goalMX;
  goalBasePosition.x = goalMX->m_flMatVal[0][3];
  goalBasePosition.y = goalMX->m_flMatVal[1][3];
  goalBasePosition.z = goalMX->m_flMatVal[2][3];
  MatrixGetColumn(in: goalMX, column: 0, out: &goalLeft);
  MatrixGetColumn(in: v6, column: 1, out: &goalUp);
  MatrixGetColumn(in: v6, column: 2, out: &goalForward);
  v8 = (const mstudiojigglebone_t *)LODWORD(jiggleInfo);
  v9 = *(float *)(LODWORD(jiggleInfo) + 4);
  goalTip.z = (float)(v9 * goalForward.z) + goalBasePosition.z;
  goalTip.x = (float)(goalForward.x * v9) + goalBasePosition.x;
  goalTip.y = (float)(v9 * goalForward.y) + goalBasePosition.y;
  JiggleData = CJiggleBones::GetJiggleData(
                 this,
                 bone: boneIndex,
                 currenttime,
                 initBasePos: &goalBasePosition,
                 initTipPos: &goalTip);
  p_m_Element = &JiggleData->m_Element;
  if ( JiggleData != nullptr )
  {
    v12 = currenttime;
    if ( (float)(currenttime - JiggleData->m_Element.lastUpdate) > 0.5 )
    {
      x = goalBasePosition.x;
      JiggleData->m_Element.bone = boneIndex;
      JiggleData->m_Element.lastUpdate = currenttime;
      JiggleData->m_Element.basePos.x = x;
      JiggleData->m_Element.basePos.y = goalBasePosition.y;
      JiggleData->m_Element.basePos.z = goalBasePosition.z;
      v14 = goalTip.x;
      JiggleData->m_Element.baseLastPos.x = JiggleData->m_Element.basePos.x;
      JiggleData->m_Element.baseLastPos.y = JiggleData->m_Element.basePos.y;
      JiggleData->m_Element.baseLastPos.z = JiggleData->m_Element.basePos.z;
      JiggleData->m_Element.baseVel.x = 0.0;
      JiggleData->m_Element.baseVel.y = 0.0;
      JiggleData->m_Element.baseVel.z = 0.0;
      JiggleData->m_Element.baseAccel.x = 0.0;
      JiggleData->m_Element.baseAccel.y = 0.0;
      JiggleData->m_Element.baseAccel.z = 0.0;
      JiggleData->m_Element.tipPos.x = v14;
      JiggleData->m_Element.tipPos.y = goalTip.y;
      JiggleData->m_Element.tipPos.z = goalTip.z;
      JiggleData->m_Element.tipVel.x = 0.0;
      JiggleData->m_Element.tipVel.y = 0.0;
      JiggleData->m_Element.tipVel.z = 0.0;
      JiggleData->m_Element.tipAccel.x = 0.0;
      JiggleData->m_Element.tipAccel.y = 0.0;
      JiggleData->m_Element.tipAccel.z = 0.0;
    }
    if ( JiggleBoneInvert.m_pParent != nullptr && JiggleBoneInvert.m_pParent->m_Value.m_nValue != 0 )
    {
      y = JiggleData->m_Element.basePos.y;
      z = JiggleData->m_Element.basePos.z;
      JiggleData->m_Element.basePos.x = -JiggleData->m_Element.basePos.x;
      JiggleData->m_Element.basePos.y = -y;
      JiggleData->m_Element.basePos.z = -z;
      v17 = JiggleData->m_Element.baseLastPos.y;
      v18 = JiggleData->m_Element.baseLastPos.z;
      JiggleData->m_Element.baseLastPos.x = -JiggleData->m_Element.baseLastPos.x;
      JiggleData->m_Element.baseLastPos.y = -v17;
      JiggleData->m_Element.baseLastPos.z = -v18;
      v19 = JiggleData->m_Element.baseVel.y;
      v20 = JiggleData->m_Element.baseVel.z;
      JiggleData->m_Element.baseVel.x = -JiggleData->m_Element.baseVel.x;
      JiggleData->m_Element.baseVel.y = -v19;
      JiggleData->m_Element.baseVel.z = -v20;
      v21 = JiggleData->m_Element.baseAccel.y;
      v22 = JiggleData->m_Element.baseAccel.z;
      JiggleData->m_Element.baseAccel.x = -JiggleData->m_Element.baseAccel.x;
      JiggleData->m_Element.baseAccel.y = -v21;
      JiggleData->m_Element.baseAccel.z = -v22;
      v23 = JiggleData->m_Element.tipPos.y;
      v24 = JiggleData->m_Element.tipPos.z;
      JiggleData->m_Element.tipPos.x = -JiggleData->m_Element.tipPos.x;
      JiggleData->m_Element.tipPos.y = -v23;
      JiggleData->m_Element.tipPos.z = -v24;
      v25 = JiggleData->m_Element.tipVel.y;
      v26 = JiggleData->m_Element.tipVel.z;
      JiggleData->m_Element.tipVel.x = -JiggleData->m_Element.tipVel.x;
      JiggleData->m_Element.tipVel.y = -v25;
      JiggleData->m_Element.tipVel.z = -v26;
      v27 = -JiggleData->m_Element.tipAccel.y;
      v28 = -JiggleData->m_Element.tipAccel.z;
      JiggleData->m_Element.tipAccel.x = -JiggleData->m_Element.tipAccel.x;
      JiggleData->m_Element.tipAccel.y = v27;
      JiggleData->m_Element.tipAccel.z = v28;
    }
    if ( JiggleBoneSanity.m_pParent != nullptr && JiggleBoneSanity.m_pParent->m_Value.m_nValue != 0 )
    {
      localError.x = goalTip.x - goalBasePosition.x;
      localError.y = goalTip.y - goalBasePosition.y;
      localError.z = goalTip.z - goalBasePosition.z;
      VectorNormalize(vec: &localError);
      left.x = p_m_Element->tipPos.x - goalBasePosition.x;
      left.y = p_m_Element->tipPos.y - goalBasePosition.y;
      left.z = p_m_Element->tipPos.z - goalBasePosition.z;
      VectorNormalize(vec: &left);
      if ( (float)((float)((float)(left.y * localError.y) + (float)(left.x * localError.x))
                 + (float)(left.z * localError.z)) < -0.89999998 )
        JiggleData::Init(
          this: p_m_Element,
          initBone: boneIndex,
          currenttime,
          initBasePos: &goalBasePosition,
          initTipPos: &goalTip);
      v12 = currenttime;
    }
    v29 = 0.001;
    v30 = v12 - p_m_Element->lastUpdate;
    if ( v30 >= 0.001 )
    {
      v29 = 0.033300001;
      if ( v30 <= 0.033300001 )
        v29 = v12 - p_m_Element->lastUpdate;
    }
    p_m_Element->lastUpdate = v12;
    deltaT = v29;
    if ( (v8->flags & 3) != 0 )
    {
      p_m_Element->tipAccel.z = p_m_Element->tipAccel.z - v8->tipMass;
      flags = v8->flags;
      if ( (v8->flags & 1) != 0 )
      {
        v32 = goalTip.y - p_m_Element->tipPos.y;
        v33 = goalTip.z - p_m_Element->tipPos.z;
        v34 = goalTip.x - p_m_Element->tipPos.x;
        v35 = (float)((float)(goalLeft.y * v32) + (float)(v34 * goalLeft.x)) + (float)(goalLeft.z * v33);
        v36 = p_m_Element->tipVel.z;
        localAlong.z = (float)((float)(v32 * goalForward.y) + (float)(v34 * goalForward.x))
                     + (float)(v33 * goalForward.z);
        sy = LODWORD(p_m_Element->tipVel.x);
        v37 = (float)((float)(v34 * goalUp.x) + (float)(goalUp.y * v32)) + (float)(goalUp.z * v33);
        v38 = p_m_Element->tipVel.y;
        maxBetween = v36;
        jiggleInfo = (float)(goalUp.x * *(float *)&sy) + (float)(v38 * goalUp.y);
        v39 = jiggleInfo + (float)(v36 * goalUp.z);
        v40 = (float)(v8->yawStiffness * v35)
            - (float)(v8->yawDamping
                    * (float)((float)((float)(goalLeft.x * *(float *)&sy) + (float)(v38 * goalLeft.y))
                            + (float)(v36 * goalLeft.z)));
        v41 = (float)(v8->pitchStiffness * v37) - (float)(v8->pitchDamping * v39);
        v42 = goalLeft.y * v40;
        if ( (flags & 0x20) != 0 )
        {
          v43 = goalUp.y * v41;
          v44 = (float)((float)(goalLeft.x * v40) + (float)(goalUp.x * v41)) + p_m_Element->tipAccel.x;
          v45 = (float)(goalLeft.z * v40) + (float)(goalUp.z * v41);
          p_m_Element->tipAccel.x = v44;
        }
        else
        {
          v46 = (float)(v8->alongStiffness * localAlong.z)
              - (float)((float)((float)((float)(goalForward.x * *(float *)&sy) + (float)(v38 * goalForward.y))
                              + (float)(maxBetween * goalForward.z))
                      * v8->alongDamping);
          v47 = goalForward.z * v46;
          v48 = goalForward.x * v46;
          v43 = goalForward.y * v46;
          left.x = goalUp.x * v41;
          left.y = goalUp.y * v41;
          v42 = v42 + (float)(goalUp.y * v41);
          v49 = goalUp.z * v41;
          v50 = (float)(goalLeft.x * v40) + (float)(goalUp.x * v41);
          left.z = v49;
          v45 = (float)((float)(goalLeft.z * v40) + v49) + v47;
          p_m_Element->tipAccel.x = (float)(v50 + v48) + p_m_Element->tipAccel.x;
        }
        v51 = (float)(v42 + v43) + p_m_Element->tipAccel.y;
        p_m_Element->tipAccel.z = v45 + p_m_Element->tipAccel.z;
        p_m_Element->tipAccel.y = v51;
      }
      v52 = p_m_Element->tipAccel.z;
      v53 = p_m_Element->tipAccel.y;
      v54 = (float)(p_m_Element->tipAccel.x * v29) + p_m_Element->tipVel.x;
      p_m_Element->tipVel.x = v54;
      p_m_Element->tipVel.z = (float)(v52 * v29) + p_m_Element->tipVel.z;
      v55 = (float)(v53 * v29) + p_m_Element->tipVel.y;
      p_m_Element->tipVel.y = v55;
      v56 = v54;
      v57 = (float)(v55 * v29) + p_m_Element->tipPos.y;
      v58 = (float)(p_m_Element->tipVel.z * v29) + p_m_Element->tipPos.z;
      v59 = v56 * v29;
      v60 = p_m_Element->tipPos.x;
      p_m_Element->tipPos.y = v57;
      p_m_Element->tipPos.z = v58;
      p_m_Element->tipPos.x = v60 + v59;
      p_m_Element->tipAccel = vec3_origin;
      v61 = v8->flags;
      if ( (v8->flags & 0xC) != 0 )
      {
        v62 = p_m_Element->tipPos.y - goalBasePosition.y;
        v63 = p_m_Element->tipPos.x - goalBasePosition.x;
        v64 = p_m_Element->tipPos.z - goalBasePosition.z;
        v65 = (float)((float)(goalLeft.x * v63) + (float)(v62 * goalLeft.y)) + (float)(v64 * goalLeft.z);
        v66 = (float)((float)(v62 * goalUp.y) + (float)(goalUp.x * v63)) + (float)(v64 * goalUp.z);
        localError.y = v62;
        localError.z = v64;
        localError.x = v63;
        localAlong.y = v66;
        localAlong.z = (float)((float)(goalForward.x * v63) + (float)(v62 * goalForward.y))
                     + (float)(v64 * goalForward.z);
        if ( (v61 & 4) != 0 )
        {
          __libm_sse2_atan2(y: v200, x: *(long double *)&pitchMatrix.m_flMatVal[0][0]);
          minYaw = v8->minYaw;
          if ( minYaw <= v65 && (minYaw = v8->maxYaw, v65 <= minYaw) )
          {
            v66 = localAlong.y;
          }
          else
          {
            pitch = minYaw;
            v207 = COERCE_FLOAT(&jiggleInfo);
            p_sy = &sy;
            jiggleInfo = cos(minYaw);
            *(float *)&sy = sin(minYaw);
            *(_QWORD *)&pitchMatrix.m_flMatVal[2][0] = sy ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
            *(_QWORD *)&pitchMatrix.m_flMatVal[0][0] = LODWORD(jiggleInfo);
            *(_QWORD *)&pitchMatrix.m_flMatVal[1][0] = 0x3F80000000000000LL;
            *(_QWORD *)&pitchMatrix.m_flMatVal[0][2] = sy;
            *(_QWORD *)&pitchMatrix.m_flMatVal[1][2] = 0;
            *(_QWORD *)&pitchMatrix.m_flMatVal[2][2] = LODWORD(jiggleInfo);
            ConcatTransforms(in1: goalMX, in2: &pitchMatrix, out: &limitMatrix);
            v68 = limitMatrix.m_flMatVal[0][2];
            v69 = limitMatrix.m_flMatVal[1][2];
            v70 = (float)((float)(limitMatrix.m_flMatVal[0][2] * localError.x)
                        + (float)(localError.y * limitMatrix.m_flMatVal[1][2]))
                + (float)(localError.z * limitMatrix.m_flMatVal[2][2]);
            localAlong.z = limitMatrix.m_flMatVal[2][2] * v70;
            v71 = limitMatrix.m_flMatVal[0][2] * v70;
            v72 = limitMatrix.m_flMatVal[1][2] * v70;
            v73 = (float)((float)(limitMatrix.m_flMatVal[0][1] * localError.x)
                        + (float)(localError.y * limitMatrix.m_flMatVal[1][1]))
                + (float)(localError.z * limitMatrix.m_flMatVal[2][1]);
            v74 = (float)(limitMatrix.m_flMatVal[1][1] * v73) + goalBasePosition.y;
            v75 = (float)((float)(limitMatrix.m_flMatVal[2][1] * v73) + goalBasePosition.z) + localAlong.z;
            p_m_Element->tipPos.x = (float)(goalBasePosition.x + (float)(limitMatrix.m_flMatVal[0][1] * v73)) + v71;
            p_m_Element->tipPos.y = v74 + v72;
            p_m_Element->tipPos.z = v75;
            v76 = p_m_Element->tipVel.z;
            v77 = (float)((float)(p_m_Element->tipVel.y * v69) + (float)(p_m_Element->tipVel.x * v68))
                + (float)(v76 * limitMatrix.m_flMatVal[2][2]);
            v78 = (float)((float)(p_m_Element->tipVel.y * limitMatrix.m_flMatVal[1][1])
                        + (float)(p_m_Element->tipVel.x * limitMatrix.m_flMatVal[0][1]))
                + (float)(v76 * limitMatrix.m_flMatVal[2][1]);
            v79 = v77 * v68;
            v80 = v78 * limitMatrix.m_flMatVal[0][1];
            v81 = v77 * v69;
            v82 = v78 * limitMatrix.m_flMatVal[1][1];
            v207 = v78 * limitMatrix.m_flMatVal[2][1];
            v83 = v78 * limitMatrix.m_flMatVal[2][1];
            yawFriction = v8->yawFriction;
            jiggleInfo = v77 * limitMatrix.m_flMatVal[2][2];
            v85 = (float)(v83 + (float)(v77 * limitMatrix.m_flMatVal[2][2])) * yawFriction;
            p_m_Element->tipAccel.x = p_m_Element->tipAccel.x - (float)((float)(v80 + v79) * yawFriction);
            v86 = limitMatrix.m_flMatVal[0][0];
            p_m_Element->tipAccel.y = p_m_Element->tipAccel.y - (float)((float)(v82 + v81) * yawFriction);
            p_m_Element->tipAccel.z = p_m_Element->tipAccel.z - v85;
            v87 = v8->yawBounce * -0.0;
            v88 = v79;
            localAlong.x = v79;
            v89 = limitMatrix.m_flMatVal[1][0] * v87;
            localAlong.y = v81;
            p_m_Element->tipVel.z = (float)((float)(limitMatrix.m_flMatVal[2][0] * v87) + v207) + jiggleInfo;
            p_m_Element->tipVel.y = (float)(v89 + v82) + v81;
            p_m_Element->tipVel.x = (float)((float)(v86 * v87) + v80) + v88;
            v90 = p_m_Element->tipPos.x - goalBasePosition.x;
            v91 = p_m_Element->tipPos.z - goalBasePosition.z;
            v66 = (float)((float)((float)(p_m_Element->tipPos.y - goalBasePosition.y) * goalUp.y)
                        + (float)(goalUp.x * v90))
                + (float)(v91 * goalUp.z);
            localError.y = p_m_Element->tipPos.y - goalBasePosition.y;
            localError.x = v90;
            localError.z = v91;
          }
        }
        if ( (v8->flags & 8) != 0 )
        {
          __libm_sse2_atan2(y: v200, x: *(long double *)&pitchMatrix.m_flMatVal[0][0]);
          minPitch = v8->minPitch;
          if ( minPitch > v66 || (minPitch = v8->maxPitch, v66 > minPitch) )
          {
            pitch = minPitch;
            p_sy = (unsigned int *)&jiggleInfo;
            v207 = COERCE_FLOAT(&sy);
            jiggleInfo = cos(minPitch);
            *(float *)&sy = sin(minPitch);
            *(_QWORD *)&pitchMatrix.m_flMatVal[0][0] = 1065353216;
            pitchMatrix.m_flMatVal[2][0] = 0.0;
            pitchMatrix.m_flMatVal[1][1] = jiggleInfo;
            LODWORD(pitchMatrix.m_flMatVal[2][1]) = sy ^ _mask__NegFloat_;
            memset(&pitchMatrix.m_flMatVal[0][2], 0, 12);
            *(_QWORD *)&pitchMatrix.m_flMatVal[1][2] = sy;
            *(_QWORD *)&pitchMatrix.m_flMatVal[2][2] = LODWORD(jiggleInfo);
            ConcatTransforms(in1: goalMX, in2: &pitchMatrix, out: &limitMatrix);
            v93 = limitMatrix.m_flMatVal[1][0];
            v94 = limitMatrix.m_flMatVal[2][0];
            v95 = (float)((float)(limitMatrix.m_flMatVal[0][2] * localError.x)
                        + (float)(localError.y * limitMatrix.m_flMatVal[1][2]))
                + (float)(localError.z * limitMatrix.m_flMatVal[2][2]);
            v96 = limitMatrix.m_flMatVal[0][2] * v95;
            localAlong.y = limitMatrix.m_flMatVal[1][2] * v95;
            localAlong.z = limitMatrix.m_flMatVal[2][2] * v95;
            v97 = limitMatrix.m_flMatVal[0][0];
            v98 = (float)((float)(limitMatrix.m_flMatVal[0][0] * localError.x)
                        + (float)(localError.y * limitMatrix.m_flMatVal[1][0]))
                + (float)(localError.z * limitMatrix.m_flMatVal[2][0]);
            v99 = limitMatrix.m_flMatVal[0][0] * v98;
            v100 = (float)((float)(limitMatrix.m_flMatVal[1][0] * v98) + goalBasePosition.y) + localAlong.y;
            v101 = limitMatrix.m_flMatVal[2][0] * v98;
            v102 = goalBasePosition.x;
            v103 = (float)(v101 + goalBasePosition.z) + localAlong.z;
            p_m_Element->tipPos.y = v100;
            p_m_Element->tipPos.x = (float)(v102 + v99) + v96;
            p_m_Element->tipPos.z = v103;
            v104 = p_m_Element->tipVel.y;
            v105 = p_m_Element->tipVel.x;
            maxBetweenb = p_m_Element->tipVel.z;
            v106 = v104 * limitMatrix.m_flMatVal[1][1];
            v107 = v105 * limitMatrix.m_flMatVal[0][1];
            v108 = (float)((float)(v104 * limitMatrix.m_flMatVal[1][2]) + (float)(v105 * limitMatrix.m_flMatVal[0][2]))
                 + (float)(maxBetweenb * limitMatrix.m_flMatVal[2][2]);
            v109 = v108 * limitMatrix.m_flMatVal[0][2];
            v110 = (float)(v106 + v107) + (float)(maxBetweenb * limitMatrix.m_flMatVal[2][1]);
            v111 = v108 * limitMatrix.m_flMatVal[1][2];
            maxBetweenc = v108 * limitMatrix.m_flMatVal[2][2];
            localError.z = v108 * limitMatrix.m_flMatVal[2][2];
            v112 = v97 * 0.0;
            pitchFriction = v8->pitchFriction;
            jiggleInfo = v93 * 0.0;
            v207 = v94 * 0.0;
            v114 = (float)((float)(v94 * 0.0) + localError.z) * pitchFriction;
            p_m_Element->tipAccel.x = p_m_Element->tipAccel.x - (float)((float)(v112 + v109) * pitchFriction);
            p_m_Element->tipAccel.y = p_m_Element->tipAccel.y
                                    - (float)((float)((float)(v93 * 0.0) + v111) * pitchFriction);
            p_m_Element->tipAccel.z = p_m_Element->tipAccel.z - v114;
            v115 = v8->pitchBounce * v110;
            v116 = limitMatrix.m_flMatVal[0][1] * v115;
            v117 = limitMatrix.m_flMatVal[1][1] * v115;
            localAlong.z = limitMatrix.m_flMatVal[2][1] * v115;
            v118 = v112;
            v119 = (float)(jiggleInfo - v117) + v111;
            v120 = (float)(v207 - localAlong.z) + maxBetweenc;
            localError.x = v109;
            localError.y = v111;
            p_m_Element->tipVel.x = (float)(v118 - v116) + v109;
            p_m_Element->tipVel.y = v119;
            p_m_Element->tipVel.z = v120;
          }
        }
      }
      forward.x = p_m_Element->tipPos.x - goalBasePosition.x;
      forward.y = p_m_Element->tipPos.y - goalBasePosition.y;
      forward.z = p_m_Element->tipPos.z - goalBasePosition.z;
      VectorNormalize(vec: &forward);
      if ( (v8->flags & 0x10) != 0 )
      {
        maxBetweena = (float)((float)(goalForward.x * forward.x) + (float)(goalForward.y * forward.y))
                    + (float)(goalForward.z * forward.z);
        __libm_sse2_acos(x: v200);
        v121 = maxBetweena;
        if ( maxBetweena < 0.0 )
          v121 = 6.283185307179586 - maxBetweena;
        angleLimit = v8->angleLimit;
        if ( v121 > angleLimit )
        {
          __libm_sse2_sin(x: v201);
          maxBetweend = angleLimit * v8->length;
          localError.x = goalTip.x - p_m_Element->tipPos.x;
          localError.y = goalTip.y - p_m_Element->tipPos.y;
          localError.z = goalTip.z - p_m_Element->tipPos.z;
          VectorNormalize(vec: &localError);
          v123 = goalTip.x - (float)(maxBetweend * localError.x);
          v124 = goalTip.z - (float)(localError.z * maxBetweend);
          p_m_Element->tipPos.y = goalTip.y - (float)(localError.y * maxBetweend);
          p_m_Element->tipPos.z = v124;
          p_m_Element->tipPos.x = v123;
          v125 = p_m_Element->tipPos.y - goalBasePosition.y;
          v126 = p_m_Element->tipPos.z - goalBasePosition.z;
          forward.x = v123 - goalBasePosition.x;
          forward.y = v125;
          forward.z = v126;
          VectorNormalize(vec: &forward);
        }
      }
      v127 = forward.z;
      v128 = forward.y;
      v129 = forward.x;
      if ( (v8->flags & 0x20) != 0 )
      {
        length = v8->length;
        v131 = forward.x * length;
        p_m_Element->tipPos.y = (float)(forward.y * length) + goalBasePosition.y;
        v132 = (float)(v127 * length) + goalBasePosition.z;
        v133 = goalBasePosition.x;
        p_m_Element->tipPos.z = v132;
        p_m_Element->tipPos.x = v133 + v131;
        v134 = (float)((float)(p_m_Element->tipVel.x * v129) + (float)(v128 * p_m_Element->tipVel.y))
             + (float)(v127 * p_m_Element->tipVel.z);
        p_m_Element->tipVel.x = p_m_Element->tipVel.x - (float)(v129 * v134);
        p_m_Element->tipVel.y = p_m_Element->tipVel.y - (float)(v128 * v134);
        p_m_Element->tipVel.z = p_m_Element->tipVel.z - (float)(v127 * v134);
      }
      left.x = (float)(goalUp.y * v127) - (float)(goalUp.z * v128);
      left.y = (float)(goalUp.z * v129) - (float)(goalUp.x * v127);
      left.z = (float)(goalUp.x * v128) - (float)(goalUp.y * v129);
      VectorNormalize(vec: &left);
      v135 = boneMX;
      v136 = forward.y;
      v137 = forward.z;
      v138 = left.z;
      v139 = left.x;
      v140 = forward.x;
      boneMX->m_flMatVal[0][1] = (float)(forward.y * left.z) - (float)(forward.z * left.y);
      v135->m_flMatVal[0][2] = forward.x;
      v135->m_flMatVal[0][3] = goalBasePosition.x;
      v141 = (float)(v137 * v139) - (float)(v140 * v138);
      v142 = forward.x * left.y;
      v135->m_flMatVal[1][3] = goalBasePosition.y;
      v143 = goalBasePosition.z;
      v144 = v136 * v139;
      v135->m_flMatVal[0][0] = v139;
      v145 = left.y;
      v135->m_flMatVal[2][3] = v143;
      v29 = deltaT;
      v135->m_flMatVal[1][0] = v145;
      v135->m_flMatVal[2][0] = v138;
      v135->m_flMatVal[1][1] = v141;
      v135->m_flMatVal[2][1] = v142 - v144;
      v135->m_flMatVal[1][2] = v136;
      v135->m_flMatVal[2][2] = v137;
    }
    else
    {
      v135 = boneMX;
    }
    if ( (v8->flags & 0x40) != 0 )
    {
      p_m_Element->baseAccel.z = p_m_Element->baseAccel.z - v8->baseMass;
      baseStiffness = v8->baseStiffness;
      v147 = goalBasePosition.x - p_m_Element->basePos.x;
      p_x = &p_m_Element->basePos.x;
      v149 = v8->baseDamping * p_m_Element->baseVel.x;
      baseDamping = v8->baseDamping;
      v151 = baseDamping * p_m_Element->baseVel.z;
      v152 = baseDamping * p_m_Element->baseVel.y;
      v153 = (float)(goalBasePosition.y - p_m_Element->basePos.y) * baseStiffness;
      v154 = (float)((float)((float)(goalBasePosition.z - p_m_Element->basePos.z) * baseStiffness) - v151)
           + p_m_Element->baseAccel.z;
      v155 = p_m_Element->baseAccel.x;
      p_m_Element->baseAccel.z = v154;
      v156 = v155 + (float)((float)(v147 * baseStiffness) - v149);
      p_m_Element->baseAccel.x = v156;
      v157 = (float)(v153 - v152) + p_m_Element->baseAccel.y;
      p_m_Element->baseAccel.y = v157;
      v158 = (float)(v157 * v29) + p_m_Element->baseVel.y;
      p_m_Element->baseVel.y = v158;
      v159 = (float)(v154 * v29) + p_m_Element->baseVel.z;
      p_m_Element->baseVel.z = v159;
      v160 = (float)(v156 * v29) + p_m_Element->baseVel.x;
      p_m_Element->baseVel.x = v160;
      p_m_Element->basePos.y = (float)(v158 * v29) + p_m_Element->basePos.y;
      p_m_Element->basePos.x = (float)(v160 * v29) + p_m_Element->basePos.x;
      p_m_Element->basePos.z = (float)(v159 * v29) + p_m_Element->basePos.z;
      p_m_Element->baseAccel = vec3_origin;
      v161 = p_m_Element->basePos.y - goalBasePosition.y;
      v162 = p_m_Element->basePos.x - goalBasePosition.x;
      v163 = (float)((float)(v161 * goalLeft.y) + (float)(goalLeft.x * v162))
           + (float)((float)(p_m_Element->basePos.z - goalBasePosition.z) * goalLeft.z);
      v164 = (float)((float)(v161 * goalUp.y) + (float)(goalUp.x * v162))
           + (float)((float)(p_m_Element->basePos.z - goalBasePosition.z) * goalUp.z);
      v165 = (float)(v161 * goalForward.y) + (float)(goalForward.x * v162);
      v166 = goalForward.z;
      v167 = p_m_Element->baseVel.y;
      v168 = goalUp.x * p_m_Element->baseVel.x;
      v169 = goalLeft.x * p_m_Element->baseVel.x;
      localError.z = v165 + (float)((float)(p_m_Element->basePos.z - goalBasePosition.z) * goalForward.z);
      maxBetweene = p_m_Element->baseVel.z;
      v170 = (float)((float)(v167 * goalLeft.y) + v169) + (float)(maxBetweene * goalLeft.z);
      v171 = (float)((float)(v167 * goalUp.y) + v168) + (float)(maxBetweene * goalUp.z);
      v172 = (float)((float)(v167 * goalForward.y) + (float)(goalForward.x * p_m_Element->baseVel.x))
           + (float)(maxBetweene * goalForward.z);
      baseMinLeft = v8->baseMinLeft;
      if ( baseMinLeft > v163 || (baseMinLeft = v8->baseMaxLeft, v163 > baseMinLeft) )
      {
        v163 = baseMinLeft;
        left.x = goalForward.x * v172;
        left.z = goalForward.z * v172;
        left.y = goalForward.y * v172;
        localAlong.z = (float)(goalUp.z * v171) + (float)(goalForward.z * v172);
        baseLeftFriction = v8->baseLeftFriction;
        left.y = (float)((float)(goalUp.y * v171) + (float)(goalForward.y * v172)) * baseLeftFriction;
        v175 = localAlong.z * baseLeftFriction;
        v176 = p_m_Element->baseAccel.x
             - (float)((float)((float)(goalUp.x * v171) + (float)(goalForward.x * v172)) * baseLeftFriction);
        p_m_Element->baseAccel.y = p_m_Element->baseAccel.y - left.y;
        v177 = p_m_Element->baseAccel.z - v175;
        p_m_Element->baseAccel.x = v176;
        p_m_Element->baseAccel.z = v177;
        v166 = goalForward.z;
      }
      baseMinUp = v8->baseMinUp;
      if ( baseMinUp > v164 || (baseMinUp = v8->baseMaxUp, v164 > baseMinUp) )
      {
        v164 = baseMinUp;
        localAlong.z = v166 * v172;
        baseUpFriction = v8->baseUpFriction;
        localAlong.y = goalForward.y * v172;
        v180 = (float)((float)(goalLeft.z * v170) + (float)(v166 * v172)) * baseUpFriction;
        v181 = (float)((float)(goalLeft.y * v170) + (float)(goalForward.y * v172)) * baseUpFriction;
        v182 = p_m_Element->baseAccel.x
             - (float)((float)((float)(goalLeft.x * v170) + (float)(goalForward.x * v172)) * baseUpFriction);
        p_m_Element->baseAccel.y = p_m_Element->baseAccel.y - v181;
        v183 = p_m_Element->baseAccel.z - v180;
        p_m_Element->baseAccel.x = v182;
        p_m_Element->baseAccel.z = v183;
        v166 = goalForward.z;
      }
      baseMinForward = v8->baseMinForward;
      v185 = localError.z;
      if ( baseMinForward > localError.z || (baseMinForward = v8->baseMaxForward, localError.z > baseMinForward) )
      {
        localAlong.y = goalUp.y * v171;
        localAlong.z = goalUp.z * v171;
        v186 = (float)(goalLeft.y * v170) + (float)(goalUp.y * v171);
        v185 = baseMinForward;
        v187 = (float)(goalLeft.z * v170) + (float)(goalUp.z * v171);
        v188 = goalUp.x * v171;
        v189 = goalLeft.x * v170;
        baseForwardFriction = v8->baseForwardFriction;
        p_m_Element->baseAccel.x = p_m_Element->baseAccel.x - (float)((float)(v189 + v188) * baseForwardFriction);
        p_m_Element->baseAccel.y = p_m_Element->baseAccel.y - (float)(v186 * baseForwardFriction);
        p_m_Element->baseAccel.z = p_m_Element->baseAccel.z - (float)(v187 * baseForwardFriction);
        v166 = goalForward.z;
      }
      v191 = goalForward.x * v185;
      localAlong.y = goalUp.y * v164;
      localAlong.z = goalUp.z * v164;
      v192 = (float)((float)(goalLeft.y * v163) + goalBasePosition.y) + (float)(goalUp.y * v164);
      v193 = (float)((float)(goalLeft.z * v163) + goalBasePosition.z) + (float)(goalUp.z * v164);
      v194 = (float)(goalBasePosition.x + (float)(goalLeft.x * v163)) + (float)(goalUp.x * v164);
      v195 = v192 + (float)(goalForward.y * v185);
      p_m_Element->basePos.y = v195;
      v196 = v193 + (float)(v166 * v185);
      p_m_Element->basePos.z = v196;
      v197 = v194 + v191;
      *p_x = v197;
      v198 = v195 - p_m_Element->baseLastPos.y;
      v199 = v196 - p_m_Element->baseLastPos.z;
      p_m_Element->baseVel.x = (float)(1.0 / deltaT) * (float)(v197 - p_m_Element->baseLastPos.x);
      p_m_Element->baseVel.y = v198 * (float)(1.0 / deltaT);
      p_m_Element->baseVel.z = v199 * (float)(1.0 / deltaT);
      p_m_Element->baseLastPos.x = *p_x;
      p_m_Element->baseLastPos.y = p_m_Element->basePos.y;
      p_m_Element->baseLastPos.z = p_m_Element->basePos.z;
      if ( (v8->flags & 3) == 0 )
        *v135 = *goalMX;
      MatrixSetColumn(in: &p_m_Element->basePos, column: 3, out: v135);
    }
    else if ( (v8->flags & 3) == 0 )
    {
      *v135 = *goalMX;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CC20
// Name: protected: int CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *__thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *v11; // eax
  int v12; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v13; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v14; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v15; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)this->m_FirstFree;
  if ( result != nullptr )
  {
    this->m_FirstFree = result[1].m_nBlockSize;
LABEL_36:
    if ( multilist )
    {
      result[1].m_nBlockSize = 0;
      result[1].m_pNext = nullptr;
    }
    else
    {
      result[1].m_nBlockSize = (int)result;
      result[1].m_pNext = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
           this: &this->m_Memory,
           result: &v13,
           it: &this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v15.m_pBlockHeader = this->m_Memory.m_pBlocks;
      v15.m_nIndex = 0;
    }
    else
    {
      v15.m_pBlockHeader = nullptr;
      v15.m_nIndex = -1;
    }
    v14 = v15;
    v7 = &v14;
  }
  v8 = v7->m_pBlockHeader;
  v9 = v7->m_nIndex;
  if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v10 = this->m_LastAlloc.m_nIndex) >= 0
      && v10 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v11 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
              this: &this->m_Memory,
              result: &v14,
              it: &this->m_LastAlloc);
    }
    else
    {
      if ( this->m_Memory.m_pBlocks != nullptr )
      {
        v14.m_pBlockHeader = this->m_Memory.m_pBlocks;
        v14.m_nIndex = 0;
      }
      else
      {
        v14.m_pBlockHeader = nullptr;
        v14.m_nIndex = -1;
      }
      v15 = v14;
      v11 = &v15;
    }
    v8 = v11->m_pBlockHeader;
    v9 = v11->m_nIndex;
    if ( v8 == nullptr || v9 < 0 || v9 >= v8->m_nBlockSize )
    {
      if ( `CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[2 * v9] != (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v9;
    p_m_LastAlloc->m_pBlockHeader = v8;
    v12 = this->m_LastAlloc.m_nIndex;
    if ( v12 >= 0 && v12 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = &v8[2 * v12 + 1];
    }
    else
    {
      result = nullptr;
      ++this->m_NumAlloced;
    }
    goto LABEL_36;
  }
  if ( `CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal'::`19'::__executeCount >= 10 )
    return nullptr;
  ++`CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0043D760
// Name: public: void CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::RemoveAll(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this)
{
  CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *v1; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlockHeader; // edi
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *v5; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t result; // [esp+4h] [ebp-14h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t it; // [esp+Ch] [ebp-Ch] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > *p_m_Memory; // [esp+14h] [ebp-4h]

  v1 = this;
  p_m_Memory = &this->m_Memory;
  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
                this: &v1->m_Memory,
                &result,
                &it) )
    {
      m_pBlockHeader = i->m_pBlockHeader;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( m_pBlockHeader != nullptr )
      {
        if ( m_nIndex >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
        {
          if ( &m_pBlockHeader[2 * m_nIndex] == (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::IsIdxAfter(
                 this: p_m_Memory,
                 i: (int)&m_pBlockHeader[2 * m_nIndex + 1],
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *)&p_m_Memory[2].m_nGrowSize)
            || m_pBlockHeader[2 * m_nIndex + 2].m_pNext == &m_pBlockHeader[2 * m_nIndex + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize != &m_pBlockHeader[2 * m_nIndex + 1] )
          {
            v1 = (CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *)p_m_Memory;
          }
          else
          {
            v5 = p_m_Memory;
            m_pBlockHeader[2 * m_nIndex + 2].m_pNext = &m_pBlockHeader[2 * m_nIndex + 1];
            m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize = v5[1].m_nGrowSize;
            v5[1].m_nGrowSize = (int)&m_pBlockHeader[2 * m_nIndex + 1];
            v1 = (CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *)v5;
          }
        }
      }
      else if ( m_nIndex == -1 )
      {
        break;
      }
      if ( m_pBlockHeader == v1->m_LastAlloc.m_pBlockHeader && m_nIndex == v1->m_LastAlloc.m_nIndex )
        break;
    }
    v1->m_Head = 0;
    v1->m_Tail = 0;
    v1->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043DF40
// Name: public: void CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::Purge(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::RemoveAll(this);
  m_pBlocks = this->m_Memory.m_pBlocks;
  if ( this->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_Memory.m_pBlocks = nullptr;
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_FirstFree = 0;
  this->m_NumAlloced = 0;
  this->m_pElements = nullptr;
  this->m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_LastAlloc.m_nIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0043DF90
// Name: public: void CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::LinkBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::LinkBefore(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this,
        int before,
        int elem)
{
  int v4; // eax
  int v5; // eax
  int m_Tail; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc) )
  {
    v4 = *(_DWORD *)(elem + 8);
    if ( v4 != elem )
    {
      if ( v4 != 0 )
        *(_DWORD *)(v4 + 12) = *(_DWORD *)(elem + 12);
      else
        this->m_Head = *(_DWORD *)(elem + 12);
      v5 = *(_DWORD *)(elem + 12);
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 8) = *(_DWORD *)(elem + 8);
      else
        this->m_Tail = *(_DWORD *)(elem + 8);
      *(_DWORD *)(elem + 12) = elem;
      *(_DWORD *)(elem + 8) = elem;
      --this->m_ElementCount;
    }
  }
  *(_DWORD *)(elem + 12) = before;
  if ( before != 0 )
  {
    m_Tail = *(_DWORD *)(before + 8);
    *(_DWORD *)(before + 8) = elem;
  }
  else
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  *(_DWORD *)(elem + 8) = m_Tail;
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 12) = elem;
    ++this->m_ElementCount;
  }
  else
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474E00
// Name: protected: int CUtlLinkedList<class IUndoElement __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class IUndoElement __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
        CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<IUndoElement *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( `CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00474F70
// Name: public: void CUtlLinkedList<class IUndoElement __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class IUndoElement __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(
        CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474FD0
// Name: public: void CUtlLinkedList<class IUndoElement __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class IUndoElement __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::Unlink(
        CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<IUndoElement *,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi
  int v5; // edx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        v5 = v2->m_Previous;
        --this->m_ElementCount;
        this->m_Tail = v5;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v2->m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475890
// Name: public: int CUtlLinkedList<class IUndoElement __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class IUndoElement __near *,int>,int>>::AddToTail(class IUndoElement __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
        CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> > *this,
        IUndoElement **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  unsigned int v6; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *v8; // esi

  result = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::Unlink(
      this,
      elem: result);
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = v4;
    m_pMemory[v6].m_Next = -1;
    m_Tail = this->m_Tail;
    m_pMemory[v6].m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v8 = &this->m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
      v8->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00577CC0
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00577D30
// Name: protected: unsigned short CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x00577EB0
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005780C0
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v7; // ebx

  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

} // namespace hlmv

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x101196C0
// Name: public: void JiggleData::Init(int,float,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall JiggleData::Init(
        JiggleData *this,
        int initBone,
        float currenttime,
        const Vector *initBasePos,
        const Vector *initTipPos)
{
  this->bone = initBone;
  this->lastUpdate = currenttime;
  this->basePos = *initBasePos;
  this->baseLastPos = this->basePos;
  this->baseVel.x = 0.0;
  this->baseVel.y = 0.0;
  this->baseVel.z = 0.0;
  this->baseAccel.x = 0.0;
  this->baseAccel.y = 0.0;
  this->baseAccel.z = 0.0;
  this->tipPos = *initTipPos;
  this->tipVel.x = 0.0;
  this->tipVel.y = 0.0;
  this->tipVel.z = 0.0;
  this->tipAccel.x = 0.0;
  this->tipAccel.y = 0.0;
  this->tipAccel.z = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10119AB0
// Name: public: struct JiggleData __near * CJiggleBones::GetJiggleData(int,float,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
UtlLinkedListElem_t<JiggleData,unsigned short> *__thiscall CJiggleBones::GetJiggleData(
        CJiggleBones *this,
        int bone,
        float currenttime,
        const Vector *initBasePos,
        const Vector *initTipPos)
{
  CJiggleBones *v5; // esi
  int m_Head; // eax
  UtlLinkedListElem_t<JiggleData,unsigned short> *m_pMemory; // edi
  int v8; // ecx
  float z; // xmm2_4
  float x; // xmm0_4
  float v11; // xmm1_4
  unsigned __int16 v12; // ax
  int v13; // ebx
  unsigned __int16 v14; // ax
  int v15; // esi
  JiggleData *p_m_Element; // edi
  JiggleData data; // [esp+Ch] [ebp-64h] BYREF
  CJiggleBones *v19; // [esp+6Ch] [ebp-4h]

  v5 = this;
  m_Head = this->m_jiggleBoneState.m_Head;
  v19 = this;
  if ( m_Head == 0xFFFF )
  {
LABEL_5:
    z = initBasePos->z;
    data.lastUpdate = currenttime;
    x = initBasePos->x;
    data.basePos.y = initBasePos->y;
    data.baseLastPos.y = data.basePos.y;
    data.tipPos.x = initTipPos->x;
    data.tipPos.y = initTipPos->y;
    v11 = initTipPos->z;
    data.id = s_id;
    data.basePos.x = x;
    data.baseLastPos.x = x;
    data.bone = bone;
    data.basePos.z = z;
    data.baseLastPos.z = z;
    memset((void *)&data.baseVel, 0, 24);
    data.tipPos.z = v11;
    memset((void *)&data.tipVel, 0, 24);
    ++s_id;
    v12 = CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::AllocInternal(
            this: &v5->m_jiggleBoneState,
            multilist: false);
    v13 = v12;
    if ( v12 == 0xFFFF )
    {
      v14 = -1;
    }
    else
    {
      CUtlLinkedList<JiggleData,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<JiggleData,unsigned short>,unsigned short>>::LinkAfter(
        this: &v5->m_jiggleBoneState,
        after: 0xFFFFu,
        elem: v12);
      p_m_Element = &v5->m_jiggleBoneState.m_Memory.m_pMemory[v13].m_Element;
      if ( p_m_Element != nullptr )
      {
        *p_m_Element = data;
        v5 = v19;
      }
      v14 = v13;
    }
    if ( v14 == 0xFFFF )
      return nullptr;
    else
      return &v5->m_jiggleBoneState.m_Memory.m_pMemory[v14];
  }
  else
  {
    m_pMemory = this->m_jiggleBoneState.m_Memory.m_pMemory;
    while ( 1 )
    {
      v8 = (unsigned __int16)m_Head;
      if ( m_pMemory[v8].m_Element.bone == bone )
        break;
      m_Head = m_pMemory[v8].m_Next;
      if ( m_Head == 0xFFFF )
        goto LABEL_5;
    }
    v15 = (unsigned __int16)m_Head;
    if ( (LODWORD(m_pMemory[v15].m_Element.lastUpdate) & 0x7F800000) == 0x7F800000 )
      _Warning(a1: "lastUpdate NaN\n");
    if ( (LODWORD(m_pMemory[v15].m_Element.basePos.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.basePos.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.basePos.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "basePos NaN\n");
    }
    if ( (LODWORD(m_pMemory[v15].m_Element.baseLastPos.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.baseLastPos.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.baseLastPos.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "baseLastPos NaN\n");
    }
    if ( (LODWORD(m_pMemory[v15].m_Element.baseVel.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.baseVel.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.baseVel.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "baseVel NaN\n");
    }
    if ( (LODWORD(m_pMemory[v15].m_Element.baseAccel.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.baseAccel.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.baseAccel.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "baseAccel NaN\n");
    }
    if ( (LODWORD(m_pMemory[v15].m_Element.tipPos.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.tipPos.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.tipPos.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "tipPos NaN\n");
    }
    if ( (LODWORD(m_pMemory[v15].m_Element.tipVel.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.tipVel.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.tipVel.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "tipVel NaN\n");
    }
    if ( (LODWORD(m_pMemory[v15].m_Element.tipAccel.x) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.tipAccel.y) & 0x7F800000) == 0x7F800000
      || (LODWORD(m_pMemory[v15].m_Element.tipAccel.z) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "tipAccel NaN\n");
    }
    return &v19->m_jiggleBoneState.m_Memory.m_pMemory[v15];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10119ED0
// Name: public: void CJiggleBones::BuildJiggleTransformations(int,float,struct mstudiojigglebone_t const __near *,struct matrix3x4_t const __near &,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJiggleBones::BuildJiggleTransformations(
        CJiggleBones *this,
        int boneIndex,
        float currenttime,
        const mstudiojigglebone_t *jiggleInfo,
        const matrix3x4_t *goalMX,
        matrix3x4_t *boneMX)
{
  const matrix3x4_t *v6; // edi
  const mstudiojigglebone_t *v8; // edi
  float length; // xmm0_4
  UtlLinkedListElem_t<JiggleData,unsigned short> *JiggleData; // eax
  UtlLinkedListElem_t<JiggleData,unsigned short> *v11; // esi
  int v12; // eax
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  int m_nValue; // eax
  float v29; // xmm0_4
  float v30; // xmm1_4
  bool v31; // zf
  int flags; // eax
  float v33; // xmm3_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm4_4
  float v37; // xmm7_4
  float v38; // xmm6_4
  float v39; // xmm3_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm1_4
  float v43; // xmm6_4
  float v44; // xmm2_4
  float v45; // xmm3_4
  float v46; // xmm1_4
  float v47; // xmm5_4
  float v48; // xmm2_4
  float v49; // xmm4_4
  float v50; // xmm5_4
  float v51; // xmm1_4
  float v52; // xmm3_4
  float v53; // xmm5_4
  float v54; // xmm2_4
  float v55; // xmm4_4
  float v56; // xmm3_4
  float v57; // xmm1_4
  float v58; // xmm2_4
  float v59; // xmm4_4
  float v60; // xmm2_4
  int v61; // eax
  float v62; // xmm1_4
  float v63; // xmm4_4
  float v64; // xmm3_4
  float v65; // xmm0_4
  float v66; // xmm2_4
  float minYaw; // xmm1_4
  float v68; // xmm3_4
  float v69; // xmm7_4
  float v70; // xmm4_4
  float v71; // xmm5_4
  float v72; // xmm2_4
  float v73; // xmm0_4
  float v74; // xmm0_4
  float v75; // xmm6_4
  float v76; // xmm1_4
  float v77; // xmm0_4
  float v78; // xmm1_4
  float v79; // xmm6_4
  float v80; // xmm4_4
  float v81; // xmm5_4
  float v82; // xmm1_4
  float v83; // xmm2_4
  float v84; // xmm0_4
  float yawFriction; // xmm3_4
  float v86; // xmm7_4
  float v87; // xmm2_4
  float v88; // xmm0_4
  float v89; // xmm3_4
  float v90; // xmm3_4
  float v91; // xmm2_4
  float v92; // xmm0_4
  float v93; // xmm7_4
  float v94; // xmm1_4
  float v95; // xmm0_4
  float v96; // xmm3_4
  float v97; // xmm1_4
  float minPitch; // xmm1_4
  float v99; // xmm5_4
  float v100; // xmm4_4
  float v101; // xmm2_4
  float v102; // xmm1_4
  float v103; // xmm6_4
  float v104; // xmm0_4
  float v105; // xmm0_4
  float v106; // xmm4_4
  float v107; // xmm3_4
  float v108; // xmm7_4
  float v109; // xmm6_4
  float v110; // xmm3_4
  float v111; // xmm0_4
  float v112; // xmm4_4
  float v113; // xmm1_4
  float pitchFriction; // xmm5_4
  float v115; // xmm7_4
  float v116; // xmm2_4
  float v117; // xmm5_4
  float v118; // xmm0_4
  float v119; // xmm0_4
  float v120; // xmm3_4
  float v121; // xmm1_4
  double v122; // xmm0_8
  float v123; // xmm1_4
  __m128 angleLimit_low; // xmm0
  double v125; // xmm0_8
  float v126; // xmm3_4
  float v127; // xmm1_4
  float v128; // xmm1_4
  float v129; // xmm2_4
  float v130; // xmm1_4
  float v131; // xmm0_4
  float v132; // xmm4_4
  float v133; // xmm5_4
  float v134; // xmm6_4
  float v135; // xmm2_4
  float v136; // xmm3_4
  float v137; // xmm5_4
  float v138; // xmm2_4
  matrix3x4_t *v139; // ecx
  float v140; // xmm3_4
  float v141; // xmm5_4
  float v142; // xmm4_4
  float v143; // xmm6_4
  float v144; // xmm2_4
  float v145; // xmm1_4
  float v146; // xmm2_4
  float v147; // xmm0_4
  float v148; // xmm7_4
  float v149; // xmm6_4
  float baseStiffness; // xmm7_4
  float v151; // xmm1_4
  float v152; // xmm2_4
  float v153; // xmm5_4
  float baseDamping; // xmm6_4
  float v155; // xmm4_4
  float v156; // xmm6_4
  float *p_x; // eax
  float v158; // xmm3_4
  float v159; // xmm4_4
  float v160; // xmm4_4
  float v161; // xmm2_4
  float v162; // xmm3_4
  float v163; // xmm1_4
  float v164; // xmm2_4
  float v165; // xmm6_4
  float v166; // xmm3_4
  float v167; // xmm5_4
  float v168; // xmm4_4
  float v169; // xmm6_4
  float v170; // xmm4_4
  float v171; // xmm1_4
  float v172; // xmm2_4
  float v173; // xmm0_4
  float baseMinLeft; // xmm6_4
  float v175; // xmm0_4
  float baseLeftFriction; // xmm6_4
  float v177; // xmm7_4
  float v178; // xmm6_4
  float baseMinUp; // xmm6_4
  float baseUpFriction; // xmm7_4
  float v181; // xmm6_4
  float v182; // xmm7_4
  float baseMinForward; // xmm0_4
  float v184; // xmm7_4
  float v185; // xmm0_4
  float v186; // xmm2_4
  float v187; // xmm6_4
  float baseForwardFriction; // xmm1_4
  float v189; // xmm2_4
  float v190; // xmm6_4
  float v191; // xmm1_4
  float v192; // xmm6_4
  float v193; // xmm7_4
  float v194; // xmm2_4
  float v195; // xmm0_4
  float v196; // xmm0_4
  float v197; // xmm2_4
  float v198; // xmm1_4
  float v199; // xmm3_4
  float v200; // xmm0_4
  float v201; // xmm2_4
  int v202; // eax
  char *v203; // eax
  float v204; // xmm2_4
  float v205; // xmm1_4
  float v206; // xmm1_4
  float v207; // xmm2_4
  float v208; // xmm2_4
  float v209; // xmm2_4
  float v210; // xmm4_4
  float v211; // xmm0_4
  float v212; // xmm2_4
  float v213; // xmm1_4
  float v214; // xmm1_4
  float v215; // xmm2_4
  float v216; // xmm2_4
  float v217; // xmm1_4
  float v218; // xmm2_4
  float v219; // xmm4_4
  int id; // [esp+FCh] [ebp-10Ch]
  matrix3x4_t limitMatrix; // [esp+108h] [ebp-100h] BYREF
  matrix3x4_t pitchMatrix; // [esp+138h] [ebp-D0h] BYREF
  Vector along; // [esp+168h] [ebp-A0h]
  float v224; // [esp+174h] [ebp-94h]
  Vector goalTip; // [esp+178h] [ebp-90h] BYREF
  Vector limitUp; // [esp+184h] [ebp-84h]
  float pitch; // [esp+190h] [ebp-78h]
  float v228; // [esp+194h] [ebp-74h]
  Vector left; // [esp+198h] [ebp-70h] BYREF
  Vector forward; // [esp+1A4h] [ebp-64h] BYREF
  Vector limitForward; // [esp+1B0h] [ebp-58h] BYREF
  unsigned int sy; // [esp+1BCh] [ebp-4Ch] BYREF
  Vector goalLeft; // [esp+1C0h] [ebp-48h] BYREF
  Vector goalUp; // [esp+1CCh] [ebp-3Ch] BYREF
  Vector goalForward; // [esp+1D8h] [ebp-30h] BYREF
  Vector delta; // [esp+1E4h] [ebp-24h] BYREF
  Vector goalBasePosition; // [esp+1F0h] [ebp-18h] BYREF
  Vector limitLeft; // [esp+1FCh] [ebp-Ch] BYREF

  v6 = goalMX;
  goalBasePosition.x = goalMX->m_flMatVal[0][3];
  goalBasePosition.y = goalMX->m_flMatVal[1][3];
  goalBasePosition.z = goalMX->m_flMatVal[2][3];
  MatrixGetColumn(in: goalMX, column: 0, out: &goalLeft);
  MatrixGetColumn(in: v6, column: 1, out: &goalUp);
  MatrixGetColumn(in: v6, column: 2, out: &goalForward);
  v8 = jiggleInfo;
  length = jiggleInfo->length;
  goalTip.z = (float)(length * goalForward.z) + goalBasePosition.z;
  goalTip.x = (float)(goalForward.x * length) + goalBasePosition.x;
  goalTip.y = (float)(length * goalForward.y) + goalBasePosition.y;
  JiggleData = CJiggleBones::GetJiggleData(
                 this,
                 bone: boneIndex,
                 currenttime,
                 initBasePos: &goalBasePosition,
                 initTipPos: &goalTip);
  v11 = JiggleData;
  if ( JiggleData == nullptr )
    return;
  if ( (float)(currenttime - JiggleData->m_Element.lastUpdate) > 0.5 )
  {
    v12 = boneIndex;
    v11->m_Element.lastUpdate = currenttime;
    v11->m_Element.bone = v12;
    v11->m_Element.basePos = goalBasePosition;
    x = goalTip.x;
    v11->m_Element.baseLastPos.x = v11->m_Element.basePos.x;
    v11->m_Element.baseLastPos.y = v11->m_Element.basePos.y;
    v11->m_Element.baseLastPos.z = v11->m_Element.basePos.z;
    v11->m_Element.baseVel.x = 0.0;
    v11->m_Element.baseVel.y = 0.0;
    v11->m_Element.baseVel.z = 0.0;
    v11->m_Element.baseAccel.x = 0.0;
    v11->m_Element.baseAccel.y = 0.0;
    v11->m_Element.baseAccel.z = 0.0;
    v11->m_Element.tipPos.x = x;
    v11->m_Element.tipPos.y = goalTip.y;
    v11->m_Element.tipPos.z = goalTip.z;
    v11->m_Element.tipVel.x = 0.0;
    v11->m_Element.tipVel.y = 0.0;
    v11->m_Element.tipVel.z = 0.0;
    v11->m_Element.tipAccel.x = 0.0;
    v11->m_Element.tipAccel.y = 0.0;
    v11->m_Element.tipAccel.z = 0.0;
  }
  if ( JiggleBoneInvert.m_pParent != nullptr && JiggleBoneInvert.m_pParent->m_Value.m_nValue != 0 )
  {
    y = v11->m_Element.basePos.y;
    z = v11->m_Element.basePos.z;
    v11->m_Element.basePos.x = -v11->m_Element.basePos.x;
    v11->m_Element.basePos.y = -y;
    v11->m_Element.basePos.z = -z;
    v16 = v11->m_Element.baseLastPos.y;
    v17 = v11->m_Element.baseLastPos.z;
    v11->m_Element.baseLastPos.x = -v11->m_Element.baseLastPos.x;
    v11->m_Element.baseLastPos.y = -v16;
    v11->m_Element.baseLastPos.z = -v17;
    v18 = v11->m_Element.baseVel.y;
    v19 = v11->m_Element.baseVel.z;
    v11->m_Element.baseVel.x = -v11->m_Element.baseVel.x;
    v11->m_Element.baseVel.y = -v18;
    v11->m_Element.baseVel.z = -v19;
    v20 = v11->m_Element.baseAccel.y;
    v21 = v11->m_Element.baseAccel.z;
    v11->m_Element.baseAccel.x = -v11->m_Element.baseAccel.x;
    v11->m_Element.baseAccel.y = -v20;
    v11->m_Element.baseAccel.z = -v21;
    v22 = v11->m_Element.tipPos.y;
    v23 = v11->m_Element.tipPos.z;
    v11->m_Element.tipPos.x = -v11->m_Element.tipPos.x;
    v11->m_Element.tipPos.y = -v22;
    v11->m_Element.tipPos.z = -v23;
    v24 = v11->m_Element.tipVel.y;
    v25 = v11->m_Element.tipVel.z;
    v11->m_Element.tipVel.x = -v11->m_Element.tipVel.x;
    v11->m_Element.tipVel.y = -v24;
    v11->m_Element.tipVel.z = -v25;
    v26 = -v11->m_Element.tipAccel.y;
    v27 = -v11->m_Element.tipAccel.z;
    v11->m_Element.tipAccel.x = -v11->m_Element.tipAccel.x;
    v11->m_Element.tipAccel.y = v26;
    v11->m_Element.tipAccel.z = v27;
  }
  if ( JiggleBoneDebug.m_pParent != nullptr )
    m_nValue = JiggleBoneDebug.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( v11->m_Element.id == m_nValue )
  {
    engine->Con_NPrintf(
      this: engine,
      a2: 20,
      a3: "basePos %f %f %f",
      v11->m_Element.basePos.x,
      v11->m_Element.basePos.y,
      v11->m_Element.basePos.z);
    engine->Con_NPrintf(
      this: engine,
      a2: 21,
      a3: "baseLastPos %f %f %f",
      v11->m_Element.baseLastPos.x,
      v11->m_Element.baseLastPos.y,
      v11->m_Element.baseLastPos.z);
    engine->Con_NPrintf(
      this: engine,
      a2: 22,
      a3: "baseVel %f %f %f",
      v11->m_Element.baseVel.x,
      v11->m_Element.baseVel.y,
      v11->m_Element.baseVel.z);
    engine->Con_NPrintf(
      this: engine,
      a2: 23,
      a3: "baseAccel %f %f %f",
      v11->m_Element.baseAccel.x,
      v11->m_Element.baseAccel.y,
      v11->m_Element.baseAccel.z);
    engine->Con_NPrintf(
      this: engine,
      a2: 24,
      a3: "tipPos %f %f %f",
      v11->m_Element.tipPos.x,
      v11->m_Element.tipPos.y,
      v11->m_Element.tipPos.z);
    engine->Con_NPrintf(
      this: engine,
      a2: 25,
      a3: "tipVel %f %f %f",
      v11->m_Element.tipVel.x,
      v11->m_Element.tipVel.y,
      v11->m_Element.tipVel.z);
    engine->Con_NPrintf(
      this: engine,
      a2: 26,
      a3: "tipAccel %f %f %f",
      v11->m_Element.tipAccel.x,
      v11->m_Element.tipAccel.y,
      v11->m_Element.tipAccel.z);
  }
  if ( JiggleBoneSanity.m_pParent != nullptr && JiggleBoneSanity.m_pParent->m_Value.m_nValue != 0 )
  {
    limitForward.x = goalTip.x - goalBasePosition.x;
    limitForward.y = goalTip.y - goalBasePosition.y;
    limitForward.z = goalTip.z - goalBasePosition.z;
    VectorNormalize(vec: &limitForward);
    left.x = v11->m_Element.tipPos.x - goalBasePosition.x;
    left.y = v11->m_Element.tipPos.y - goalBasePosition.y;
    left.z = v11->m_Element.tipPos.z - goalBasePosition.z;
    VectorNormalize(vec: &left);
    if ( (float)((float)((float)(left.y * limitForward.y) + (float)(left.x * limitForward.x))
               + (float)(left.z * limitForward.z)) < -0.89999998 )
      JiggleData::Init(
        this: &v11->m_Element,
        initBone: boneIndex,
        currenttime,
        initBasePos: &goalBasePosition,
        initTipPos: &goalTip);
  }
  v29 = 0.001;
  v30 = currenttime - v11->m_Element.lastUpdate;
  if ( v30 >= 0.001 )
  {
    v29 = 0.033300001;
    if ( v30 <= 0.033300001 )
      v29 = currenttime - v11->m_Element.lastUpdate;
  }
  v11->m_Element.lastUpdate = currenttime;
  v31 = (v8->flags & 3) == 0;
  currenttime = v29;
  if ( v31 )
  {
    v139 = boneMX;
  }
  else
  {
    v11->m_Element.tipAccel.z = v11->m_Element.tipAccel.z - v8->tipMass;
    flags = v8->flags;
    if ( (v8->flags & 1) != 0 )
    {
      v33 = goalTip.x - v11->m_Element.tipPos.x;
      v34 = goalTip.y - v11->m_Element.tipPos.y;
      v35 = goalTip.z - v11->m_Element.tipPos.z;
      v36 = (float)((float)(goalLeft.y * v34) + (float)(v33 * goalLeft.x)) + (float)(goalLeft.z * v35);
      *(float *)&boneIndex = goalUp.y * v34;
      v37 = (float)((float)(goalUp.y * v34) + (float)(v33 * goalUp.x)) + (float)(goalUp.z * v35);
      v38 = goalForward.x * v33;
      v39 = v11->m_Element.tipVel.x;
      v40 = (float)((float)(v34 * goalForward.y) + v38) + (float)(v35 * goalForward.z);
      v41 = v11->m_Element.tipVel.z;
      limitLeft.z = v40;
      v42 = v11->m_Element.tipVel.y;
      *(float *)&boneIndex = v39;
      pitch = v41;
      *(float *)&sy = v42;
      v43 = (float)((float)(v39 * goalUp.x) + (float)(goalUp.y * v42)) + (float)(goalUp.z * v41);
      v44 = (float)(v8->yawStiffness * v36)
          - (float)(v8->yawDamping
                  * (float)((float)((float)(v39 * goalLeft.x) + (float)(goalLeft.y * v42)) + (float)(goalLeft.z * v41)));
      v45 = (float)(v8->pitchStiffness * v37) - (float)(v8->pitchDamping * v43);
      if ( (flags & 0x20) != 0 )
      {
        v46 = (float)(v44 * goalLeft.x) + (float)(v45 * goalUp.x);
        v47 = (float)(goalLeft.y * v44) + (float)(goalUp.y * v45);
        v48 = (float)(v44 * goalLeft.z) + (float)(goalUp.z * v45);
      }
      else
      {
        v49 = (float)(v8->alongStiffness * limitLeft.z)
            - (float)((float)((float)((float)(goalForward.x * *(float *)&boneIndex)
                                    + (float)(goalForward.y * *(float *)&sy))
                            + (float)(goalForward.z * v11->m_Element.tipVel.z))
                    * v8->alongDamping);
        delta.z = goalForward.z * v49;
        limitLeft.y = goalUp.y * v45;
        limitLeft.z = goalUp.z * v45;
        v50 = (float)(goalLeft.y * v44) + (float)(goalUp.y * v45);
        v51 = v44 * goalLeft.x;
        v48 = (float)((float)(v44 * goalLeft.z) + (float)(goalUp.z * v45)) + (float)(goalForward.z * v49);
        v46 = (float)(v51 + (float)(v45 * goalUp.x)) + (float)(goalForward.x * v49);
        v47 = v50 + (float)(goalForward.y * v49);
      }
      v52 = v11->m_Element.tipAccel.x;
      v53 = v47 + v11->m_Element.tipAccel.y;
      v11->m_Element.tipAccel.z = v48 + v11->m_Element.tipAccel.z;
      v11->m_Element.tipAccel.y = v53;
      v11->m_Element.tipAccel.x = v52 + v46;
    }
    v54 = v11->m_Element.tipAccel.z;
    v55 = v11->m_Element.tipVel.x;
    v56 = v11->m_Element.tipAccel.x * v29;
    v57 = (float)(v11->m_Element.tipAccel.y * v29) + v11->m_Element.tipVel.y;
    v11->m_Element.tipVel.y = v57;
    v58 = (float)(v54 * v29) + v11->m_Element.tipVel.z;
    v11->m_Element.tipVel.z = v58;
    v59 = v55 + v56;
    v11->m_Element.tipVel.x = v59;
    v60 = (float)(v58 * v29) + v11->m_Element.tipPos.z;
    v11->m_Element.tipPos.y = (float)(v57 * v29) + v11->m_Element.tipPos.y;
    v11->m_Element.tipPos.z = v60;
    v11->m_Element.tipPos.x = v11->m_Element.tipPos.x + (float)(v59 * v29);
    v11->m_Element.tipAccel = vec3_origin;
    v61 = v8->flags;
    if ( (v8->flags & 0xC) != 0 )
    {
      v62 = v11->m_Element.tipPos.x - goalBasePosition.x;
      v63 = v11->m_Element.tipPos.y - goalBasePosition.y;
      v64 = v11->m_Element.tipPos.z - goalBasePosition.z;
      v65 = (float)((float)(v63 * goalLeft.y) + (float)(v62 * goalLeft.x)) + (float)(v64 * goalLeft.z);
      v66 = (float)((float)(v63 * goalUp.y) + (float)(v62 * goalUp.x)) + (float)(v64 * goalUp.z);
      along.y = v63;
      along.z = v64;
      along.x = v62;
      limitLeft.y = v66;
      limitLeft.z = (float)((float)(v63 * goalForward.y) + (float)(goalForward.x * v62)) + (float)(v64 * goalForward.z);
      if ( (v61 & 4) != 0 )
      {
        __libm_sse2_atan2();
        minYaw = v8->minYaw;
        if ( minYaw <= v65 && (minYaw = v8->maxYaw, v65 <= minYaw) )
        {
          v66 = limitLeft.y;
        }
        else
        {
          pitch = minYaw;
          v228 = COERCE_FLOAT(&boneIndex);
          v224 = COERCE_FLOAT(&sy);
          *(float *)&boneIndex = cos(minYaw);
          *(float *)&sy = sin(minYaw);
          *(_QWORD *)&pitchMatrix.m_flMatVal[2][0] = sy ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
          *(_QWORD *)&pitchMatrix.m_flMatVal[0][0] = (unsigned int)boneIndex;
          *(_QWORD *)&pitchMatrix.m_flMatVal[1][0] = 0x3F80000000000000LL;
          *(_QWORD *)&pitchMatrix.m_flMatVal[0][2] = sy;
          *(_QWORD *)&pitchMatrix.m_flMatVal[1][2] = 0;
          *(_QWORD *)&pitchMatrix.m_flMatVal[2][2] = (unsigned int)boneIndex;
          ConcatTransforms(in1: goalMX, in2: &pitchMatrix, out: &limitMatrix);
          v68 = limitMatrix.m_flMatVal[2][1];
          v69 = limitMatrix.m_flMatVal[0][2];
          v70 = limitMatrix.m_flMatVal[1][2];
          v71 = limitMatrix.m_flMatVal[2][2];
          limitUp.x = limitMatrix.m_flMatVal[0][1];
          v72 = limitMatrix.m_flMatVal[1][1];
          limitLeft.x = limitMatrix.m_flMatVal[0][0];
          limitLeft.y = limitMatrix.m_flMatVal[1][0];
          limitLeft.z = limitMatrix.m_flMatVal[2][0];
          limitUp.y = limitMatrix.m_flMatVal[1][1];
          limitUp.z = limitMatrix.m_flMatVal[2][1];
          limitForward.x = limitMatrix.m_flMatVal[0][2];
          limitForward.y = limitMatrix.m_flMatVal[1][2];
          limitForward.z = limitMatrix.m_flMatVal[2][2];
          if ( JiggleBoneDebugYawConstraints.m_pParent != nullptr
            && JiggleBoneDebugYawConstraints.m_pParent->m_Value.m_nValue != 0 )
          {
            delta.y = (float)(limitMatrix.m_flMatVal[1][0] * 10.0) + goalBasePosition.y;
            delta.x = goalBasePosition.x + (float)(limitMatrix.m_flMatVal[0][0] * 10.0);
            delta.z = (float)(limitMatrix.m_flMatVal[2][0] * 10.0) + goalBasePosition.z;
            ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, _DWORD, int, int, int, int))debugoverlay->AddLineOverlay)(
              a1: debugoverlay,
              a2: &goalBasePosition,
              a3: &delta,
              a4: 0,
              a5: 255,
              a6: 255,
              a7: 1,
              a8: 1008981770);
            delta.y = (float)(limitUp.y * 10.0) + goalBasePosition.y;
            delta.x = goalBasePosition.x + (float)(limitUp.x * 10.0);
            delta.z = (float)(limitUp.z * 10.0) + goalBasePosition.z;
            ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, _DWORD, int, int))debugoverlay->AddLineOverlay)(
              a1: debugoverlay,
              a2: &goalBasePosition,
              a3: &delta,
              a4: 255,
              a5: 255,
              a6: 0,
              a7: 1,
              a8: 1008981770);
            delta.y = (float)(limitForward.y * 10.0) + goalBasePosition.y;
            delta.x = goalBasePosition.x + (float)(limitForward.x * 10.0);
            delta.z = (float)(limitForward.z * 10.0) + goalBasePosition.z;
            ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, _DWORD, int, int, int))debugoverlay->AddLineOverlay)(
              a1: debugoverlay,
              a2: &goalBasePosition,
              a3: &delta,
              a4: 255,
              a5: 0,
              a6: 255,
              a7: 1,
              a8: 1008981770);
            v71 = limitForward.z;
            v70 = limitForward.y;
            v69 = limitForward.x;
            v68 = limitUp.z;
            v72 = limitUp.y;
          }
          v73 = (float)((float)(v69 * along.x) + (float)(v70 * along.y)) + (float)(v71 * along.z);
          delta.x = v73 * v69;
          delta.y = v70 * v73;
          delta.z = v71 * v73;
          v74 = (float)((float)(limitUp.x * along.x) + (float)(v72 * along.y)) + (float)(v68 * along.z);
          v75 = (float)((float)(v68 * v74) + goalBasePosition.z) + delta.z;
          v76 = (float)((float)(v72 * v74) + goalBasePosition.y) + delta.y;
          v11->m_Element.tipPos.x = (float)(goalBasePosition.x + (float)(v74 * limitUp.x)) + delta.x;
          v11->m_Element.tipPos.y = v76;
          v11->m_Element.tipPos.z = v75;
          v77 = (float)((float)(v11->m_Element.tipVel.x * limitUp.x) + (float)(v72 * v11->m_Element.tipVel.y))
              + (float)(v68 * v11->m_Element.tipVel.z);
          v78 = (float)((float)(v11->m_Element.tipVel.x * limitForward.x) + (float)(v70 * v11->m_Element.tipVel.y))
              + (float)(v71 * v11->m_Element.tipVel.z);
          v79 = v78 * limitForward.x;
          v80 = v70 * v78;
          v81 = v71 * v78;
          v82 = v77 * limitUp.x;
          v228 = v68 * v77;
          *(float *)&boneIndex = v72 * v77;
          v83 = (float)(v72 * v77) + v80;
          v84 = (float)(v68 * v77) + v81;
          yawFriction = v8->yawFriction;
          v86 = (float)(v82 + v79) * yawFriction;
          v87 = v83 * yawFriction;
          v88 = v84 * yawFriction;
          v89 = v11->m_Element.tipAccel.x;
          delta.x = v79;
          v11->m_Element.tipAccel.x = v89 - v86;
          v90 = v11->m_Element.tipAccel.y - v87;
          v11->m_Element.tipAccel.z = v11->m_Element.tipAccel.z - v88;
          v91 = limitLeft.y;
          v11->m_Element.tipAccel.y = v90;
          v92 = v8->yawBounce * -0.0;
          v11->m_Element.tipVel.y = (float)((float)(v91 * v92) + *(float *)&boneIndex) + v80;
          v93 = v82;
          v94 = v92 * limitLeft.x;
          v95 = (float)(v92 * limitLeft.z) + v228;
          v11->m_Element.tipVel.x = (float)(v94 + v93) + v79;
          v11->m_Element.tipVel.z = v95 + v81;
          v96 = v11->m_Element.tipPos.x - goalBasePosition.x;
          v97 = v11->m_Element.tipPos.z - goalBasePosition.z;
          v66 = (float)((float)((float)(v11->m_Element.tipPos.y - goalBasePosition.y) * goalUp.y)
                      + (float)(v96 * goalUp.x))
              + (float)(v97 * goalUp.z);
          along.y = v11->m_Element.tipPos.y - goalBasePosition.y;
          along.z = v97;
          along.x = v96;
        }
      }
      if ( (v8->flags & 8) != 0 )
      {
        __libm_sse2_atan2();
        minPitch = v8->minPitch;
        if ( minPitch > v66 || (minPitch = v8->maxPitch, v66 > minPitch) )
        {
          pitch = minPitch;
          v224 = COERCE_FLOAT(&boneIndex);
          v228 = COERCE_FLOAT(&sy);
          *(float *)&boneIndex = cos(minPitch);
          *(float *)&sy = sin(minPitch);
          *(_QWORD *)&pitchMatrix.m_flMatVal[0][0] = 1065353216;
          pitchMatrix.m_flMatVal[2][0] = 0.0;
          LODWORD(pitchMatrix.m_flMatVal[1][1]) = boneIndex;
          LODWORD(pitchMatrix.m_flMatVal[2][1]) = sy ^ _mask__NegFloat_;
          memset(&pitchMatrix.m_flMatVal[0][2], 0, 12);
          *(_QWORD *)&pitchMatrix.m_flMatVal[1][2] = sy;
          *(_QWORD *)&pitchMatrix.m_flMatVal[2][2] = (unsigned int)boneIndex;
          ConcatTransforms(in1: goalMX, in2: &pitchMatrix, out: &limitMatrix);
          v99 = limitMatrix.m_flMatVal[0][0];
          v100 = limitMatrix.m_flMatVal[2][0];
          v101 = limitMatrix.m_flMatVal[2][2];
          limitForward.x = limitMatrix.m_flMatVal[0][1];
          limitForward.y = limitMatrix.m_flMatVal[1][1];
          limitForward.z = limitMatrix.m_flMatVal[2][1];
          limitUp.x = limitMatrix.m_flMatVal[0][2];
          v102 = limitMatrix.m_flMatVal[1][2];
          v103 = limitMatrix.m_flMatVal[1][0];
          delta.x = limitMatrix.m_flMatVal[0][0];
          delta.y = limitMatrix.m_flMatVal[1][0];
          delta.z = limitMatrix.m_flMatVal[2][0];
          limitUp.y = limitMatrix.m_flMatVal[1][2];
          limitUp.z = limitMatrix.m_flMatVal[2][2];
          if ( JiggleBoneDebugPitchConstraints.m_pParent != nullptr
            && JiggleBoneDebugPitchConstraints.m_pParent->m_Value.m_nValue != 0 )
          {
            limitLeft.y = (float)(limitMatrix.m_flMatVal[1][0] * 10.0) + goalBasePosition.y;
            limitLeft.x = goalBasePosition.x + (float)(limitMatrix.m_flMatVal[0][0] * 10.0);
            limitLeft.z = (float)(10.0 * limitMatrix.m_flMatVal[2][0]) + goalBasePosition.z;
            ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, _DWORD, int, int, int, int))debugoverlay->AddLineOverlay)(
              a1: debugoverlay,
              a2: &goalBasePosition,
              a3: &limitLeft,
              a4: 0,
              a5: 255,
              a6: 255,
              a7: 1,
              a8: 1008981770);
            limitLeft.y = (float)(limitForward.y * 10.0) + goalBasePosition.y;
            limitLeft.x = goalBasePosition.x + (float)(limitForward.x * 10.0);
            limitLeft.z = (float)(limitForward.z * 10.0) + goalBasePosition.z;
            ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, _DWORD, int, int))debugoverlay->AddLineOverlay)(
              a1: debugoverlay,
              a2: &goalBasePosition,
              a3: &limitLeft,
              a4: 255,
              a5: 255,
              a6: 0,
              a7: 1,
              a8: 1008981770);
            limitLeft.y = (float)(limitUp.y * 10.0) + goalBasePosition.y;
            limitLeft.x = goalBasePosition.x + (float)(limitUp.x * 10.0);
            limitLeft.z = (float)(limitUp.z * 10.0) + goalBasePosition.z;
            ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, _DWORD, int, int, int))debugoverlay->AddLineOverlay)(
              a1: debugoverlay,
              a2: &goalBasePosition,
              a3: &limitLeft,
              a4: 255,
              a5: 0,
              a6: 255,
              a7: 1,
              a8: 1008981770);
            v101 = limitUp.z;
            v102 = limitUp.y;
            v100 = delta.z;
            v103 = delta.y;
            v99 = delta.x;
          }
          v104 = (float)((float)(limitUp.x * along.x) + (float)(v102 * along.y)) + (float)(v101 * along.z);
          limitLeft.x = v104 * limitUp.x;
          limitLeft.y = v102 * v104;
          limitLeft.z = v101 * v104;
          v105 = (float)((float)(v99 * along.x) + (float)(v103 * along.y)) + (float)(v100 * along.z);
          v106 = (float)((float)(v100 * v105) + goalBasePosition.z) + limitLeft.z;
          v107 = (float)((float)(v103 * v105) + goalBasePosition.y) + limitLeft.y;
          v108 = limitForward.y;
          v109 = v103 * 0.0;
          v11->m_Element.tipPos.x = (float)(goalBasePosition.x + (float)(v105 * v99)) + limitLeft.x;
          v11->m_Element.tipPos.y = v107;
          v11->m_Element.tipPos.z = v106;
          v110 = (float)((float)(v11->m_Element.tipVel.x * limitForward.x) + (float)(v108 * v11->m_Element.tipVel.y))
               + (float)(limitForward.z * v11->m_Element.tipVel.z);
          v111 = (float)((float)(v11->m_Element.tipVel.x * limitUp.x) + (float)(v102 * v11->m_Element.tipVel.y))
               + (float)(v101 * v11->m_Element.tipVel.z);
          *(float *)&boneIndex = v101 * v111;
          v112 = v111 * limitUp.x;
          v113 = v102 * v111;
          v228 = v99 * 0.0;
          pitchFriction = v8->pitchFriction;
          v224 = delta.z * 0.0;
          v115 = (float)(v109 + v113) * pitchFriction;
          v116 = (float)((float)(delta.z * 0.0) + (float)(v101 * v111)) * pitchFriction;
          v117 = v11->m_Element.tipAccel.x - (float)((float)(v228 + (float)(v111 * limitUp.x)) * pitchFriction);
          v118 = v11->m_Element.tipAccel.y;
          limitLeft.x = v112;
          v11->m_Element.tipAccel.x = v117;
          v11->m_Element.tipAccel.y = v118 - v115;
          v11->m_Element.tipAccel.z = v11->m_Element.tipAccel.z - v116;
          v119 = v8->pitchBounce * v110;
          limitLeft.y = limitForward.y * v119;
          limitLeft.z = limitForward.z * v119;
          v120 = (float)(v224 - (float)(limitForward.z * v119)) + *(float *)&boneIndex;
          v121 = (float)(v109 - (float)(limitForward.y * v119)) + v113;
          v11->m_Element.tipVel.x = (float)(v228 - (float)(v119 * limitForward.x)) + v112;
          v11->m_Element.tipVel.y = v121;
          v11->m_Element.tipVel.z = v120;
        }
      }
    }
    forward.x = v11->m_Element.tipPos.x - goalBasePosition.x;
    forward.y = v11->m_Element.tipPos.y - goalBasePosition.y;
    forward.z = v11->m_Element.tipPos.z - goalBasePosition.z;
    VectorNormalize(vec: &forward);
    if ( (v8->flags & 0x10) != 0 )
    {
      *(float *)&boneIndex = (float)((float)(goalForward.y * forward.y) + (float)(goalForward.x * forward.x))
                           + (float)(goalForward.z * forward.z);
      v122 = *(float *)&boneIndex;
      __libm_sse2_acos();
      v123 = v122;
      if ( *(float *)&boneIndex < 0.0 )
        v123 = 6.283185307179586 - v123;
      angleLimit_low = (__m128)LODWORD(v8->angleLimit);
      if ( v123 > angleLimit_low.m128_f32[0] )
      {
        __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(angleLimit_low));
        *(float *)&v125 = v125;
        *(float *)&boneIndex = *(float *)&v125 * v8->length;
        delta.x = goalTip.x - v11->m_Element.tipPos.x;
        delta.y = goalTip.y - v11->m_Element.tipPos.y;
        delta.z = goalTip.z - v11->m_Element.tipPos.z;
        VectorNormalize(vec: &delta);
        v126 = goalTip.x - (float)(*(float *)&boneIndex * delta.x);
        v127 = goalTip.z - (float)(delta.z * *(float *)&boneIndex);
        v11->m_Element.tipPos.y = goalTip.y - (float)(delta.y * *(float *)&boneIndex);
        v11->m_Element.tipPos.x = v126;
        v11->m_Element.tipPos.z = v127;
        v128 = v11->m_Element.tipPos.y - goalBasePosition.y;
        v129 = v11->m_Element.tipPos.z - goalBasePosition.z;
        forward.x = v126 - goalBasePosition.x;
        forward.y = v128;
        forward.z = v129;
        VectorNormalize(vec: &forward);
      }
    }
    v130 = forward.z;
    v131 = forward.y;
    v132 = forward.x;
    if ( (v8->flags & 0x20) != 0 )
    {
      v133 = v8->length;
      v134 = forward.x * v133;
      v135 = (float)(forward.y * v133) + goalBasePosition.y;
      v136 = (float)(forward.z * v133) + goalBasePosition.z;
      v137 = goalBasePosition.x;
      v11->m_Element.tipPos.y = v135;
      v11->m_Element.tipPos.z = v136;
      v11->m_Element.tipPos.x = v137 + v134;
      v138 = (float)((float)(v11->m_Element.tipVel.x * v132) + (float)(v131 * v11->m_Element.tipVel.y))
           + (float)(v130 * v11->m_Element.tipVel.z);
      v11->m_Element.tipVel.x = v11->m_Element.tipVel.x - (float)(v132 * v138);
      v11->m_Element.tipVel.y = v11->m_Element.tipVel.y - (float)(v131 * v138);
      v11->m_Element.tipVel.z = v11->m_Element.tipVel.z - (float)(v130 * v138);
    }
    left.x = (float)(goalUp.y * v130) - (float)(goalUp.z * v131);
    left.y = (float)(goalUp.z * v132) - (float)(v130 * goalUp.x);
    left.z = (float)(v131 * goalUp.x) - (float)(goalUp.y * v132);
    VectorNormalize(vec: &left);
    v139 = boneMX;
    v140 = forward.y;
    v141 = forward.z;
    v142 = left.z;
    v143 = left.x;
    v144 = forward.x;
    boneMX->m_flMatVal[0][1] = (float)(forward.y * left.z) - (float)(forward.z * left.y);
    v139->m_flMatVal[0][2] = forward.x;
    v139->m_flMatVal[0][3] = goalBasePosition.x;
    v145 = (float)(v141 * v143) - (float)(v144 * v142);
    v146 = forward.x * left.y;
    v139->m_flMatVal[1][3] = goalBasePosition.y;
    v147 = goalBasePosition.z;
    v148 = v140 * v143;
    v139->m_flMatVal[0][0] = v143;
    v149 = left.y;
    v139->m_flMatVal[2][3] = v147;
    v29 = currenttime;
    v139->m_flMatVal[1][0] = v149;
    v139->m_flMatVal[2][0] = v142;
    v139->m_flMatVal[1][1] = v145;
    v139->m_flMatVal[2][1] = v146 - v148;
    v139->m_flMatVal[1][2] = v140;
    v139->m_flMatVal[2][2] = v141;
  }
  if ( (v8->flags & 0x40) != 0 )
  {
    v11->m_Element.baseAccel.z = v11->m_Element.baseAccel.z - v8->baseMass;
    baseStiffness = v8->baseStiffness;
    v151 = goalBasePosition.x - v11->m_Element.basePos.x;
    v152 = goalBasePosition.y - v11->m_Element.basePos.y;
    v153 = v8->baseDamping * v11->m_Element.baseVel.x;
    baseDamping = v8->baseDamping;
    v155 = baseDamping * v11->m_Element.baseVel.z;
    v156 = baseDamping * v11->m_Element.baseVel.y;
    p_x = &v11->m_Element.basePos.x;
    v158 = (float)((float)((float)(goalBasePosition.z - v11->m_Element.basePos.z) * baseStiffness) - v155)
         + v11->m_Element.baseAccel.z;
    v159 = v11->m_Element.baseAccel.x;
    v11->m_Element.baseAccel.z = v158;
    v160 = v159 + (float)((float)(v151 * baseStiffness) - v153);
    v11->m_Element.baseAccel.x = v160;
    v161 = (float)((float)(v152 * baseStiffness) - v156) + v11->m_Element.baseAccel.y;
    v11->m_Element.baseAccel.y = v161;
    v162 = (float)(v158 * v29) + v11->m_Element.baseVel.z;
    v163 = (float)(v160 * v29) + v11->m_Element.baseVel.x;
    v11->m_Element.baseVel.z = v162;
    v11->m_Element.baseVel.x = v163;
    v164 = (float)(v161 * v29) + v11->m_Element.baseVel.y;
    v11->m_Element.baseVel.y = v164;
    v11->m_Element.basePos.z = (float)(v162 * v29) + v11->m_Element.basePos.z;
    v11->m_Element.basePos.x = (float)(v163 * v29) + v11->m_Element.basePos.x;
    v11->m_Element.basePos.y = (float)(v164 * v29) + v11->m_Element.basePos.y;
    v11->m_Element.baseAccel = vec3_origin;
    v165 = v11->m_Element.basePos.x - goalBasePosition.x;
    v166 = (float)((float)(v165 * goalLeft.x)
                 + (float)((float)(v11->m_Element.basePos.y - goalBasePosition.y) * goalLeft.y))
         + (float)((float)(v11->m_Element.basePos.z - goalBasePosition.z) * goalLeft.z);
    v167 = (float)((float)(v165 * goalUp.x) + (float)((float)(v11->m_Element.basePos.y - goalBasePosition.y) * goalUp.y))
         + (float)((float)(v11->m_Element.basePos.z - goalBasePosition.z) * goalUp.z);
    v168 = (float)(goalForward.x * v165)
         + (float)((float)(v11->m_Element.basePos.y - goalBasePosition.y) * goalForward.y);
    v169 = v11->m_Element.baseVel.y;
    v170 = v168 + (float)((float)(v11->m_Element.basePos.z - goalBasePosition.z) * goalForward.z);
    v171 = (float)((float)(goalLeft.y * v169) + (float)(v11->m_Element.baseVel.x * goalLeft.x))
         + (float)(goalLeft.z * v11->m_Element.baseVel.z);
    v172 = (float)((float)(goalUp.y * v169) + (float)(v11->m_Element.baseVel.x * goalUp.x))
         + (float)(goalUp.z * v11->m_Element.baseVel.z);
    v173 = goalForward.y * v169;
    baseMinLeft = v8->baseMinLeft;
    v175 = (float)(v173 + (float)(goalForward.x * v11->m_Element.baseVel.x))
         + (float)(goalForward.z * v11->m_Element.baseVel.z);
    if ( baseMinLeft > v166 || (baseMinLeft = v8->baseMaxLeft, v166 > baseMinLeft) )
    {
      v166 = baseMinLeft;
      limitLeft.x = goalForward.x * v175;
      limitLeft.y = goalForward.y * v175;
      limitLeft.z = goalForward.z * v175;
      left.y = goalUp.y * v172;
      delta.x = (float)(v172 * goalUp.x) + (float)(goalForward.x * v175);
      delta.y = (float)(goalUp.y * v172) + (float)(goalForward.y * v175);
      delta.z = (float)(goalUp.z * v172) + (float)(goalForward.z * v175);
      baseLeftFriction = v8->baseLeftFriction;
      left.z = goalUp.z * v172;
      limitLeft.x = delta.x * baseLeftFriction;
      limitLeft.y = delta.y * baseLeftFriction;
      v177 = delta.z * baseLeftFriction;
      v11->m_Element.baseAccel.x = v11->m_Element.baseAccel.x - (float)(delta.x * baseLeftFriction);
      v11->m_Element.baseAccel.y = v11->m_Element.baseAccel.y - limitLeft.y;
      v178 = v11->m_Element.baseAccel.z - v177;
      limitLeft.z = v177;
      v11->m_Element.baseAccel.z = v178;
    }
    baseMinUp = v8->baseMinUp;
    if ( baseMinUp > v167 || (baseMinUp = v8->baseMaxUp, v167 > baseMinUp) )
    {
      v167 = baseMinUp;
      limitLeft.x = goalForward.x * v175;
      limitLeft.y = goalForward.y * v175;
      delta.z = goalLeft.z * v171;
      limitLeft.z = (float)(goalLeft.z * v171) + (float)(goalForward.z * v175);
      baseUpFriction = v8->baseUpFriction;
      delta.y = (float)((float)(goalLeft.y * v171) + (float)(goalForward.y * v175)) * baseUpFriction;
      v181 = limitLeft.z * baseUpFriction;
      v182 = v11->m_Element.baseAccel.x
           - (float)((float)((float)(v171 * goalLeft.x) + (float)(goalForward.x * v175)) * baseUpFriction);
      v11->m_Element.baseAccel.y = v11->m_Element.baseAccel.y - delta.y;
      v11->m_Element.baseAccel.z = v11->m_Element.baseAccel.z - v181;
      v11->m_Element.baseAccel.x = v182;
    }
    baseMinForward = v8->baseMinForward;
    if ( baseMinForward > v170 || (baseMinForward = v8->baseMaxForward, v170 > baseMinForward) )
    {
      v170 = baseMinForward;
      limitLeft.y = goalUp.y * v172;
      limitLeft.z = goalUp.z * v172;
      v184 = v172;
      v185 = v171 * goalLeft.x;
      v186 = (float)(goalLeft.y * v171) + (float)(goalUp.y * v172);
      v187 = goalLeft.z * v171;
      baseForwardFriction = v8->baseForwardFriction;
      v189 = v186 * baseForwardFriction;
      v190 = (float)(v187 + limitLeft.z) * baseForwardFriction;
      v191 = v11->m_Element.baseAccel.x - (float)((float)(v185 + (float)(v184 * goalUp.x)) * baseForwardFriction);
      v11->m_Element.baseAccel.y = v11->m_Element.baseAccel.y - v189;
      v11->m_Element.baseAccel.z = v11->m_Element.baseAccel.z - v190;
      v11->m_Element.baseAccel.x = v191;
    }
    v192 = goalForward.x;
    v193 = goalForward.y;
    delta.z = goalForward.z * v170;
    limitLeft.y = goalUp.y * v167;
    v194 = (float)((float)(goalLeft.y * v166) + goalBasePosition.y) + (float)(goalUp.y * v167);
    v195 = (float)((float)(v166 * goalLeft.x) + goalBasePosition.x) + (float)(v167 * goalUp.x);
    v11->m_Element.basePos.z = (float)((float)((float)(v166 * goalLeft.z) + goalBasePosition.z)
                                     + (float)(v167 * goalUp.z))
                             + (float)(goalForward.z * v170);
    v196 = v195 + (float)(v192 * v170);
    *p_x = v196;
    v197 = v194 + (float)(v193 * v170);
    v11->m_Element.basePos.y = v197;
    v198 = v11->m_Element.basePos.z - v11->m_Element.baseLastPos.z;
    v199 = v196 - v11->m_Element.baseLastPos.x;
    v200 = v197 - v11->m_Element.baseLastPos.y;
    v201 = 1.0 / currenttime;
    v11->m_Element.baseVel.x = (float)(1.0 / currenttime) * v199;
    v11->m_Element.baseVel.y = v200 * v201;
    v11->m_Element.baseVel.z = v198 * v201;
    v11->m_Element.baseLastPos.x = *p_x;
    v11->m_Element.baseLastPos.y = v11->m_Element.basePos.y;
    v11->m_Element.baseLastPos.z = v11->m_Element.basePos.z;
    if ( (v8->flags & 3) == 0 )
      *v139 = *goalMX;
    MatrixSetColumn(in: &v11->m_Element.basePos, column: 3, out: v139);
  }
  else if ( (v8->flags & 3) == 0 )
  {
    *v139 = *goalMX;
  }
  if ( JiggleBoneDebug.m_pParent == nullptr )
  {
    v202 = 0;
    goto LABEL_69;
  }
  v202 = JiggleBoneDebug.m_pParent->m_Value.m_nValue;
  if ( v202 != 1 )
  {
LABEL_69:
    if ( v202 != v11->m_Element.id )
      return;
  }
  limitLeft.x = (float)(goalLeft.x * 5.0) + goalBasePosition.x;
  limitLeft.y = (float)(goalLeft.y * 5.0) + goalBasePosition.y;
  limitLeft.z = (float)(goalLeft.z * 5.0) + goalBasePosition.z;
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &goalBasePosition,
    a3: &limitLeft,
    a4: 255,
    a5: 0,
    a6: 0,
    a7: 1,
    a8: 1008981770);
  limitLeft.x = (float)(goalUp.x * 5.0) + goalBasePosition.x;
  limitLeft.y = (float)(goalUp.y * 5.0) + goalBasePosition.y;
  limitLeft.z = (float)(goalUp.z * 5.0) + goalBasePosition.z;
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, _DWORD, int, _DWORD, int, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &goalBasePosition,
    a3: &limitLeft,
    a4: 0,
    a5: 255,
    a6: 0,
    a7: 1,
    a8: 1008981770);
  limitLeft.x = (float)(goalForward.x * 5.0) + goalBasePosition.x;
  limitLeft.y = (float)(goalForward.y * 5.0) + goalBasePosition.y;
  limitLeft.z = (float)(goalForward.z * 5.0) + goalBasePosition.z;
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, _DWORD, _DWORD, int, int, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &goalBasePosition,
    a3: &limitLeft,
    a4: 0,
    a5: 0,
    a6: 255,
    a7: 1,
    a8: 1008981770);
  id = v11->m_Element.id;
  goalMX = (const matrix3x4_t *)debugoverlay->__vftable;
  v203 = VarArgs(format: "%d", id);
  ((void (__cdecl *)(IVDebugOverlay *, Vector *, int, char *))LODWORD(goalMX->m_flMatVal[1][2]))(
    a1: debugoverlay,
    a2: &goalBasePosition,
    a3: 1008981770,
    a4: v203);
  if ( (v8->flags & 3) != 0 )
  {
    ((void (__stdcall *)(Vector *, Vector *, int, int, _DWORD, int, int))debugoverlay->AddLineOverlay)(
      a1: &goalBasePosition,
      a2: &v11->m_Element.tipPos,
      a3: 255,
      a4: 255,
      a5: 0,
      a6: 1,
      a7: 1008981770);
    v204 = v11->m_Element.tipPos.z;
    v205 = v11->m_Element.tipPos.x + 1.0;
    delta.x = v11->m_Element.tipPos.x - 1.0;
    limitLeft.x = v205;
    limitLeft.y = v11->m_Element.tipPos.y;
    limitLeft.z = v204;
    delta.y = limitLeft.y;
    delta.z = v204;
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, _DWORD, int, int, int, int))debugoverlay->AddLineOverlay)(
      a1: debugoverlay,
      a2: &delta,
      a3: &limitLeft,
      a4: 0,
      a5: 255,
      a6: 255,
      a7: 1,
      a8: 1008981770);
    v206 = v11->m_Element.tipPos.x;
    v207 = v11->m_Element.tipPos.y;
    delta.y = v207 - 1.0;
    limitLeft.y = v207 + 1.0;
    v208 = v11->m_Element.tipPos.z;
    limitLeft.x = v206;
    limitLeft.z = v208;
    delta.x = v206;
    delta.z = v208;
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, _DWORD, int, int, int, int))debugoverlay->AddLineOverlay)(
      a1: debugoverlay,
      a2: &delta,
      a3: &limitLeft,
      a4: 0,
      a5: 255,
      a6: 255,
      a7: 1,
      a8: 1008981770);
    v209 = v11->m_Element.tipPos.y;
    v210 = v11->m_Element.tipPos.z + 1.0;
    v211 = v11->m_Element.tipPos.z - 1.0;
    limitLeft.x = v11->m_Element.tipPos.x;
    limitLeft.y = v209;
    limitLeft.z = v210;
    delta.x = limitLeft.x;
    delta.y = v209;
    delta.z = v211;
    ((void (__stdcall *)(Vector *, Vector *, _DWORD, int, int, int, int))debugoverlay->AddLineOverlay)(
      a1: &delta,
      a2: &limitLeft,
      a3: 0,
      a4: 255,
      a5: 255,
      a6: 1,
      a7: 1008981770);
    v8 = jiggleInfo;
  }
  if ( (v8->flags & 0x40) != 0 )
  {
    v212 = v11->m_Element.basePos.z;
    v213 = v11->m_Element.basePos.x;
    delta.x = v213 - 1.0;
    limitLeft.x = v213 + 1.0;
    limitLeft.y = v11->m_Element.basePos.y;
    limitLeft.z = v212;
    delta.y = limitLeft.y;
    delta.z = v212;
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, _DWORD, int, int, int))debugoverlay->AddLineOverlay)(
      a1: debugoverlay,
      a2: &delta,
      a3: &limitLeft,
      a4: 255,
      a5: 0,
      a6: 255,
      a7: 1,
      a8: 1008981770);
    v214 = v11->m_Element.basePos.x;
    v215 = v11->m_Element.basePos.y;
    delta.y = v215 - 1.0;
    limitLeft.y = v215 + 1.0;
    v216 = v11->m_Element.basePos.z;
    limitLeft.x = v214;
    limitLeft.z = v216;
    delta.x = v214;
    delta.z = v216;
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, _DWORD, int, int, int))debugoverlay->AddLineOverlay)(
      a1: debugoverlay,
      a2: &delta,
      a3: &limitLeft,
      a4: 255,
      a5: 0,
      a6: 255,
      a7: 1,
      a8: 1008981770);
    v217 = v11->m_Element.basePos.x;
    v218 = v11->m_Element.basePos.y;
    v219 = v11->m_Element.basePos.z;
    delta.z = v219 - 1.0;
    limitLeft.x = v217;
    limitLeft.y = v218;
    limitLeft.z = v219 + 1.0;
    delta.x = v217;
    delta.y = v218;
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, _DWORD, int, int, int))debugoverlay->AddLineOverlay)(
      a1: debugoverlay,
      a2: &delta,
      a3: &limitLeft,
      a4: 255,
      a5: 0,
      a6: 255,
      a7: 1,
      a8: 1008981770);
  }
}

} // namespace client
