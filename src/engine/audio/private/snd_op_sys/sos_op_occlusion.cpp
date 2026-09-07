// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_occlusion.cpp
// Functions: 6
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_occlusion.h"

//------------------------------------------------------------------------------
// Address: 0x1004B720
// Name: public: virtual void CSosOperatorOcclusion::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorOcclusion::ParseKV(
        CSosOperatorOcclusion *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    v7 = String;
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "occlusio_db_loss") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        pVoidMem[5].m_flExecute[0] = V_atof(str: v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004B7F0
// Name: public: virtual void CSosOperatorOcclusion::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorOcclusion::SetDefaults(CSosOperatorOcclusion *this, float *pVoidMem)
{
  pVoidMem[9] = 1.0;
  pVoidMem[10] = NAN;
  pVoidMem[3] = 0.0;
  pVoidMem[4] = 0.0;
  pVoidMem[5] = 0.0;
  pVoidMem[6] = NAN;
  pVoidMem[7] = NAN;
  pVoidMem[8] = NAN;
  pVoidMem[11] = 1.0;
  pVoidMem[12] = -1.0;
  pVoidMem[13] = NAN;
  pVoidMem[14] = -1.0;
  pVoidMem[15] = snd_obscured_gain_db.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x1004B850
// Name: float S_CalcOcclusion(int,struct channel_t __near *,class Vector const __near &,class Vector,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
double __usercall S_CalcOcclusion@<st0>(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        int nSlot,
        channel_t *ch,
        const Vector *vecListenerOrigin,
        Vector vSoundSource,
        float flOccludedDBLoss)
{
  int v8; // edi
  int v9; // eax
  int v10; // eax
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  const Vector *v20; // esi
  float *v21; // edi
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm0_4
  long double v26; // st7
  float v29[13]; // [esp-Ch] [ebp-1ACh] BYREF
  __int16 v30; // [esp+2Ah] [ebp-176h]
  CGameTrace tr; // [esp+44h] [ebp-15Ch] BYREF
  int v32; // [esp+98h] [ebp-108h]
  int v33; // [esp+9Ch] [ebp-104h]
  int v34; // [esp+A4h] [ebp-FCh]
  char v35; // [esp+A8h] [ebp-F8h]
  bool v36; // [esp+A9h] [ebp-F7h]
  Ray_t ray; // [esp+B4h] [ebp-ECh] BYREF
  Vector v38; // [esp+10Ch] [ebp-94h] BYREF
  Vector v39; // [esp+118h] [ebp-88h] BYREF
  Vector v40; // [esp+124h] [ebp-7Ch] BYREF
  float v41; // [esp+130h] [ebp-70h]
  float v42; // [esp+134h] [ebp-6Ch]
  float v43; // [esp+138h] [ebp-68h]
  void **v44; // [esp+13Ch] [ebp-64h] BYREF
  float v45; // [esp+140h] [ebp-60h]
  float v46; // [esp+144h] [ebp-5Ch]
  float v47; // [esp+148h] [ebp-58h] BYREF
  float v48; // [esp+14Ch] [ebp-54h]
  float v49; // [esp+150h] [ebp-50h]
  float v50; // [esp+154h] [ebp-4Ch]
  float v51; // [esp+158h] [ebp-48h]
  Vector vsrc_right; // [esp+15Ch] [ebp-44h]
  Vector vsrc_up; // [esp+168h] [ebp-38h] BYREF
  Vector vsrc_forward; // [esp+174h] [ebp-2Ch] BYREF
  float v55; // [esp+180h] [ebp-20h]
  float v56; // [esp+184h] [ebp-1Ch]
  float radius; // [esp+188h] [ebp-18h]
  CTraceFilterWorldOnly filter; // [esp+18Ch] [ebp-14h]
  _BYTE vSoundSources[12]; // [esp+190h] [ebp-10h] OVERLAPPED
  int vSoundSources_16; // [esp+1A0h] [ebp+0h]

  *(_DWORD *)&vSoundSources[4] = a1;
  *(_DWORD *)&vSoundSources[8] = vSoundSources_16;
  *(float *)&filter.__vftable = 1.0;
  v8 = 1;
  v44 = &CTraceFilterWorldOnly::`vftable';
  v9 = nSlot;
  if ( nSlot == -1 )
    v9 = 0;
  v10 = v9;
  x = g_MainViewOrigin[v10].x;
  y = g_MainViewOrigin[v10].y;
  z = g_MainViewOrigin[v10].z;
  *(float *)&tr.dispFlags = vSoundSource.y - y;
  *(float *)&tr.contents = vSoundSource.x - x;
  tr.fractionleftsolid = vSoundSource.z - z;
  v36 = (float)((float)((float)(*(float *)&tr.dispFlags * *(float *)&tr.dispFlags)
                      + (float)(*(float *)&tr.contents * *(float *)&tr.contents))
              + (float)(tr.fractionleftsolid * tr.fractionleftsolid)) != 0.0;
  v35 = 1;
  v33 = 0;
  v32 = 0;
  tr.hitbox = 0;
  v34 = 0;
  memset(&tr.surface.surfaceProps, 0, 12);
  tr.plane.normal.z = x;
  tr.plane.dist = y;
  *(float *)&tr.plane.type = z;
  ((void (__thiscall *)(IEngineTrace *, float *, int, void ***, float *, int, int))g_pEngineTraceClient->TraceRay)(
    a1: g_pEngineTraceClient,
    a2: &tr.plane.normal.z,
    a3: 16387,
    a4: &v44,
    a5: v29,
    a6: a2,
    a7: a3);
  ++g_snd_trace_count;
  if ( (v29[11] < 1.0 || v30 != 0) && v29[11] < 0.99 )
  {
    *(float *)vSoundSources = ch->dist_mult;
    if ( *(float *)vSoundSources == 0.0 )
    {
      v14 = 0.0;
    }
    else
    {
      *(float *)vSoundSources = __FYL2X__(
                                  snd_refdb_dist_mult
                                / (snd_refdist.m_pParent->m_Value.m_fValue
                                 * *(float *)vSoundSources),
                                  0.3010299956639811952)
                              * 20.0;
      v14 = *(float *)vSoundSources;
    }
    if ( ch->radius <= 0.0 )
    {
      *(_DWORD *)vSoundSources = (int)v14;
      radius = ((double)(int)v14 - 60.0) * 216.0 * 0.0125 + 24.0;
    }
    else
    {
      radius = ch->radius;
    }
    v15 = vecListenerOrigin->x - vSoundSource.x;
    v45 = vSoundSource.x;
    v48 = vSoundSource.x;
    v51 = vSoundSource.x;
    vsrc_right.z = vSoundSource.x;
    v40.y = vecListenerOrigin->y - vSoundSource.y;
    v16 = vecListenerOrigin->z - vSoundSource.z;
    v46 = vSoundSource.y;
    v47 = vSoundSource.z;
    v49 = vSoundSource.y;
    v50 = vSoundSource.z;
    vsrc_right.x = vSoundSource.y;
    vsrc_right.y = vSoundSource.z;
    vsrc_up.x = vSoundSource.y;
    vsrc_up.y = vSoundSource.z;
    v40.x = v15;
    v40.z = v16;
    VectorNormalize(vec: &v40);
    VectorVectors(forward: &v40, right: &v38, up: &v39);
    vsrc_up.z = v38.x + v39.x;
    vsrc_forward.x = v38.y + v39.y;
    v17 = v39.z;
    vsrc_forward.y = v38.z + v39.z;
    if ( vSoundSource.z > (float)(vecListenerOrigin->z + 120.0) )
    {
      LODWORD(v17) = LODWORD(v39.z) ^ _mask__NegFloat_;
      LODWORD(v39.z) ^= _mask__NegFloat_;
    }
    vsrc_forward.z = v39.x - v38.x;
    v55 = v39.y - v38.y;
    v56 = v17 - v38.z;
    VectorNormalize(vec: (Vector *)&vsrc_up.z);
    VectorNormalize(vec: (Vector *)&vsrc_forward.z);
    tr.plane.normal.y = vsrc_forward.y * radius;
    v41 = vsrc_forward.z * radius;
    v42 = v55 * radius;
    v18 = vsrc_up.z * radius;
    v43 = v56 * radius;
    vsrc_up.z = (float)(radius * 0.5) * vsrc_up.z;
    v45 = vsrc_up.z + v45;
    v46 = v46 + (float)((float)(radius * 0.5) * vsrc_forward.x);
    v47 = v47 + (float)((float)(radius * 0.5) * vsrc_forward.y);
    v48 = v48 + (float)((float)(radius * 0.5) * vsrc_forward.z);
    v49 = v49 + (float)((float)(radius * 0.5) * v55);
    v51 = v51 + v18;
    vsrc_right.x = vsrc_right.x + (float)(vsrc_forward.x * radius);
    vsrc_right.y = vsrc_right.y + (float)(vsrc_forward.y * radius);
    vsrc_right.z = vsrc_right.z + (float)(vsrc_forward.z * radius);
    v19 = vsrc_up.x + (float)(v55 * radius);
    tr.endpos.y = (float)(radius * 0.5) * vsrc_forward.y;
    vsrc_forward.x = (float)(radius * 0.5) * vsrc_forward.x;
    vsrc_forward.y = tr.endpos.y;
    vsrc_forward.z = (float)(radius * 0.5) * vsrc_forward.z;
    v55 = (float)(radius * 0.5) * v55;
    v50 = v50 + (float)((float)(radius * 0.5) * v56);
    vsrc_up.x = v19;
    vsrc_up.y = vsrc_up.y + (float)(v56 * radius);
    radius = 0.0;
    v20 = MainViewOrigin(nSlot);
    v21 = &v47;
    *(_DWORD *)vSoundSources = 4;
    do
    {
      v22 = *(v21 - 2);
      v23 = *(v21 - 1);
      v24 = *v21;
      ray.m_pWorldAxisTransform = nullptr;
      ray.m_Delta.x = v22 - v20->x;
      ray.m_Delta.y = v23 - v20->y;
      ray.m_Delta.z = v24 - v20->z;
      ray.m_IsSwept = (float)((float)((float)(ray.m_Delta.y * ray.m_Delta.y) + (float)(ray.m_Delta.x * ray.m_Delta.x))
                            + (float)(ray.m_Delta.z * ray.m_Delta.z)) != 0.0;
      ray.m_pWorldAxisTransform = nullptr;
      memset(&ray.m_Extents, 0, 12);
      ray.m_IsRay = true;
      memset(&ray.m_StartOffset, 0, 12);
      ray.m_Start.x = v20->x;
      v25 = v20->y;
      *(float *)&filter.__vftable = COERCE_FLOAT(v29);
      ray.m_Start.y = v25;
      ray.m_Start.z = v20->z;
      g_pEngineTraceClient->TraceRay(
        this: g_pEngineTraceClient,
        a2: &ray,
        a3: 16387u,
        a4: (ITraceFilter *)&v44,
        a5: (CGameTrace *)v29);
      if ( (v29[11] < 1.0 || v30 != 0) && v29[11] < 0.99 && HIBYTE(v30) == 0 )
      {
        ++LODWORD(radius);
        if ( SLODWORD(radius) > 1 )
        {
          v26 = dB_To_Gain(dB: flOccludedDBLoss);
          *(float *)&filter.__vftable = v26 * *(float *)&filter.__vftable;
        }
      }
      v21 += 3;
      --*(_DWORD *)vSoundSources;
    }
    while ( *(_DWORD *)vSoundSources != 0 );
    v8 = LODWORD(radius);
  }
  if ( snd_showstart.m_pParent != nullptr && snd_showstart.m_pParent->m_Value.m_nValue == 7 )
  {
    *(float *)vSoundSources = (float)(v8 - 1) * flOccludedDBLoss;
    if ( *(float *)vSoundSources != g_drop_prev_0 )
    {
      DevMsg(a1: "dB drop: %1.4f \n", *(float *)vSoundSources);
      g_drop_prev_0 = *(float *)vSoundSources;
    }
  }
  return *(float *)&filter.__vftable;
}

//------------------------------------------------------------------------------
// Address: 0x1004BEC0
// Name: public: virtual void CSosOperatorOcclusion::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorOcclusion::Execute(
        CSosOperatorOcclusion *this,
        Vector *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CScratchPad *pStack,
        int nOpIndex)
{
  float v8; // xmm0_4
  bool v9; // bl
  double v10; // st7
  float v11; // xmm0_4
  double v12; // st7
  float gain_new; // [esp+0h] [ebp-28h]
  float x; // [esp+20h] [ebp-8h]
  float flScalar; // [esp+24h] [ebp-4h]
  float v17; // [esp+30h] [ebp+8h]
  float v18; // [esp+30h] [ebp+8h]
  bool v19; // [esp+33h] [ebp+Bh]
  char flGain_3; // [esp+37h] [ebp+Fh]

  if ( pChannel != nullptr )
  {
    x = pVoidMem[3].x;
    if ( x == 0.0 )
    {
      pVoidMem[3].z = 1.0;
    }
    else
    {
      flScalar = g_pSoundServices->GetHostTime(this: g_pSoundServices);
      v8 = pVoidMem[4].x;
      if ( v8 >= 0.0 && (float)(flScalar - pVoidMem[4].z) >= v8 || (flGain_3 = 0, SLOBYTE(pChannel->flagsword) < 0) )
        flGain_3 = 1;
      v19 = SND_ChannelOkToTrace(ch: pChannel);
      v9 = true;
      if ( !SND_IsInGame() )
        v9 = toolframework->InToolMode(this: toolframework);
      if ( (pChannel->flagsword & 0x82) == 0 && flGain_3 == 0 || !v19 )
        v9 = false;
      if ( v9 )
      {
        gain_new = 1.0
                 - (1.0
                  - S_CalcOcclusion(
                      nSlot: 0,
                      ch: pChannel,
                      vecListenerOrigin: pScratchPad->m_vPlayerOrigin,
                      vSoundSource: pVoidMem[1],
                      flOccludedDBLoss: pVoidMem[5].x))
                 * x;
        v10 = SND_FadeToNewGain(gs: pChannel->gain, ch: pChannel, gain_new);
        if ( v10 < 0.0 )
        {
          v11 = 0.0;
        }
        else
        {
          v17 = v10;
          v11 = v17;
        }
        pVoidMem[4].z = flScalar;
      }
      else
      {
        v12 = SND_FadeToNewGain(gs: pChannel->gain, ch: pChannel, gain_new: -1.0);
        if ( v12 < 0.0 )
        {
          v11 = 0.0;
        }
        else
        {
          v18 = v12;
          v11 = v18;
        }
      }
      pVoidMem[3].z = v11;
      if ( snd_sos_show_operator_updates.m_pParent != nullptr
        && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
      {
        this->Print(this, a2: pVoidMem, a3: (CSosOperatorStack *)pStack, a4: nOpIndex, a5: 0);
      }
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Error: Sound operator %s requires valid channel pointer, being called without one\n",
      *(const char **)(LODWORD(pStack->m_vClientSourceVectors[0].y) + 24 * nOpIndex + 16));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C0E0
// Name: public: CSosOperatorOcclusion::CSosOperatorOcclusion(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorOcclusion *__thiscall CSosOperatorOcclusion::CSosOperatorOcclusion(CSosOperatorOcclusion *this)
{
  int v2; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  int v7; // [esp-8h] [ebp-28h]
  CSosOperator::OutputData_t outputData; // [esp+Ch] [ebp-14h] BYREF
  __int16 v9; // [esp+18h] [ebp-8h]
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorOcclusion_vtbl *)&CSosOperatorOcclusion::`vftable';
  m_Size = this->m_vInputs.m_Size;
  outputData.m_nOffset = 48;
  outputData.m_Type = 52;
  *(_DWORD *)&outputData.m_nCount = 0;
  v9 = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_trace_interval", element: &nIndex);
  v2 = this->m_vInputs.m_Size;
  v9 = 1;
  outputData.m_nOffset = 36;
  outputData.m_Type = 40;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v2,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_scalar", element: &nIndex);
  v6 = this->m_vInputs.m_Size;
  outputData.m_nOffset = 12;
  outputData.m_Type = 24;
  *(_DWORD *)&outputData.m_nCount = 0;
  v9 = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v6,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position", element: &nIndex);
  v9 = 1;
  v7 = this->m_vOutputs.m_Size;
  outputData.m_Type = 44;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v7,
             src: (const Vector *)&outputData.m_Type);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "calc_occlusion",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004C220
// Name: public: virtual unsigned int CSosOperatorOcclusion::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorOcclusion::GetSize(CSosOperatorOcclusion *this)
{
  return 64;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1004B510
// Name: public: virtual void CSosOperatorOcclusion::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorOcclusion::ParseKV(
        CSosOperatorOcclusion *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    v7 = String;
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "occlusio_db_loss") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        pVoidMem[5].m_flExecute[0] = V_atof(str: v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004B5E0
// Name: public: virtual void CSosOperatorOcclusion::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorOcclusion::SetDefaults(CSosOperatorOcclusion *this, float *pVoidMem)
{
  pVoidMem[9] = 1.0;
  pVoidMem[10] = NAN;
  pVoidMem[3] = 0.0;
  pVoidMem[4] = 0.0;
  pVoidMem[5] = 0.0;
  pVoidMem[6] = NAN;
  pVoidMem[7] = NAN;
  pVoidMem[8] = NAN;
  pVoidMem[11] = 1.0;
  pVoidMem[12] = -1.0;
  pVoidMem[13] = NAN;
  pVoidMem[14] = -1.0;
  pVoidMem[15] = snd_obscured_gain_db.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x1004B640
// Name: float S_CalcOcclusion(int,struct channel_t __near *,class Vector const __near &,class Vector,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
double __usercall S_CalcOcclusion@<st0>(
        float a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        int nSlot,
        channel_t *ch,
        const Vector *vecListenerOrigin,
        Vector vSoundSource,
        float flOccludedDBLoss)
{
  int x_low; // edi
  int v9; // eax
  int v10; // eax
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  const Vector *v20; // esi
  CTraceFilterWorldOnly *p_filter; // edi
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm0_4
  long double v26; // st7
  _BYTE v29[12]; // [esp+38h] [ebp-1ACh] BYREF
  CGameTrace tr; // [esp+44h] [ebp-1A0h]
  float v31; // [esp+98h] [ebp-14Ch]
  float v32; // [esp+A4h] [ebp-140h]
  _DWORD v33[3]; // [esp+A8h] [ebp-13Ch] BYREF
  Ray_t ray; // [esp+B4h] [ebp-130h] BYREF
  float v35; // [esp+108h] [ebp-DCh]
  float v36; // [esp+10Ch] [ebp-D8h]
  float v37; // [esp+110h] [ebp-D4h]
  int v38; // [esp+118h] [ebp-CCh]
  int v39; // [esp+11Ch] [ebp-C8h]
  int v40; // [esp+120h] [ebp-C4h]
  int v41; // [esp+128h] [ebp-BCh]
  int v42; // [esp+12Ch] [ebp-B8h]
  int v43; // [esp+130h] [ebp-B4h]
  int v44; // [esp+138h] [ebp-ACh]
  char v45; // [esp+13Ch] [ebp-A8h]
  bool v46; // [esp+13Dh] [ebp-A7h]
  Vector v47; // [esp+150h] [ebp-94h] BYREF
  Vector vsrc_right; // [esp+15Ch] [ebp-88h] BYREF
  Vector vsrc_up; // [esp+168h] [ebp-7Ch] BYREF
  Vector vsrc_forward; // [esp+174h] [ebp-70h]
  void **v51; // [esp+180h] [ebp-64h] BYREF
  float v52; // [esp+184h] [ebp-60h]
  float v53; // [esp+188h] [ebp-5Ch]
  CTraceFilterWorldOnly filter; // [esp+18Ch] [ebp-58h] BYREF
  Vector vSoundSources[4]; // [esp+190h] [ebp-54h] BYREF
  Vector vecl; // [esp+1C0h] [ebp-24h] BYREF
  Vector vecr; // [esp+1CCh] [ebp-18h]
  float radius; // [esp+1D8h] [ebp-Ch]
  float gain; // [esp+1DCh] [ebp-8h]
  float retaddr; // [esp+1E4h] [ebp+0h]

  radius = a1;
  gain = retaddr;
  vecr.y = 1.0;
  x_low = 1;
  v51 = &CTraceFilterWorldOnly::`vftable';
  v9 = nSlot;
  if ( nSlot == -1 )
    v9 = 0;
  v10 = v9;
  x = g_MainViewOrigin[v10].x;
  y = g_MainViewOrigin[v10].y;
  z = g_MainViewOrigin[v10].z;
  ray.m_Start.z = vSoundSource.y - y;
  ray.m_Start.y = vSoundSource.x - x;
  ray.m_Start.w = vSoundSource.z - z;
  BYTE1(ray.m_Extents.z) = (float)((float)((float)(ray.m_Start.z * ray.m_Start.z)
                                         + (float)(ray.m_Start.y * ray.m_Start.y))
                                 + (float)(ray.m_Start.w * ray.m_Start.w)) != 0.0;
  LOBYTE(ray.m_Extents.z) = 1;
  memset(&ray.m_StartOffset.y, 0, 12);
  ray.m_Extents.y = 0.0;
  memset(&ray.m_Delta.y, 0, 12);
  *(float *)v33 = x;
  *(float *)&v33[1] = y;
  *(float *)&v33[2] = z;
  ((void (__thiscall *)(IEngineTrace *, _DWORD *, int, void ***, _BYTE *, int, int))g_pEngineTraceClient->TraceRay)(
    a1: g_pEngineTraceClient,
    a2: v33,
    a3: 16387,
    a4: &v51,
    a5: v29,
    a6: a2,
    a7: a3);
  ++g_snd_trace_count;
  if ( (tr.plane.normal.z < 1.0 || tr.plane.pad[0] != 0 || tr.plane.pad[1] != 0) && tr.plane.normal.z < 0.99 )
  {
    vecr.z = ch->dist_mult;
    if ( vecr.z == 0.0 )
    {
      v14 = 0.0;
    }
    else
    {
      vecr.z = __FYL2X__(
                 snd_refdb_dist_mult / (snd_refdist.m_pParent->m_Value.m_fValue * vecr.z),
                 0.3010299956639811952)
             * 20.0;
      v14 = vecr.z;
    }
    if ( ch->radius <= 0.0 )
    {
      LODWORD(vecr.z) = (int)v14;
      vecr.x = ((double)(int)v14 - 60.0) * 216.0 * 0.0125 + 24.0;
    }
    else
    {
      vecr.x = ch->radius;
    }
    v15 = vecListenerOrigin->x - vSoundSource.x;
    v52 = vSoundSource.x;
    vSoundSources[0].x = vSoundSource.x;
    vSoundSources[1].x = vSoundSource.x;
    vSoundSources[2].x = vSoundSource.x;
    vsrc_up.y = vecListenerOrigin->y - vSoundSource.y;
    v16 = vecListenerOrigin->z - vSoundSource.z;
    v53 = vSoundSource.y;
    filter.__vftable = (CTraceFilterWorldOnly_vtbl *)LODWORD(vSoundSource.z);
    vSoundSources[0].y = vSoundSource.y;
    vSoundSources[0].z = vSoundSource.z;
    vSoundSources[1].y = vSoundSource.y;
    vSoundSources[1].z = vSoundSource.z;
    vSoundSources[2].y = vSoundSource.y;
    vSoundSources[2].z = vSoundSource.z;
    vsrc_up.x = v15;
    vsrc_up.z = v16;
    VectorNormalize(vec: &vsrc_up);
    VectorVectors(forward: &vsrc_up, right: &v47, up: &vsrc_right);
    vSoundSources[3].x = v47.x + vsrc_right.x;
    vSoundSources[3].y = v47.y + vsrc_right.y;
    v17 = vsrc_right.z;
    vSoundSources[3].z = v47.z + vsrc_right.z;
    if ( vSoundSource.z > (float)(vecListenerOrigin->z + 120.0) )
    {
      LODWORD(v17) = LODWORD(vsrc_right.z) ^ _mask__NegFloat_;
      LODWORD(vsrc_right.z) ^= _mask__NegFloat_;
    }
    vecl.x = vsrc_right.x - v47.x;
    vecl.y = vsrc_right.y - v47.y;
    vecl.z = v17 - v47.z;
    VectorNormalize(vec: &vSoundSources[3]);
    VectorNormalize(vec: &vecl);
    v32 = vSoundSources[3].z * vecr.x;
    vsrc_forward.x = vecl.x * vecr.x;
    vsrc_forward.y = vecl.y * vecr.x;
    v18 = vSoundSources[3].x * vecr.x;
    vsrc_forward.z = vecl.z * vecr.x;
    vSoundSources[3].x = (float)(vecr.x * 0.5) * vSoundSources[3].x;
    v52 = vSoundSources[3].x + v52;
    v53 = v53 + (float)((float)(vecr.x * 0.5) * vSoundSources[3].y);
    *(float *)&filter.__vftable = *(float *)&filter.__vftable + (float)((float)(vecr.x * 0.5) * vSoundSources[3].z);
    vSoundSources[0].x = vSoundSources[0].x + (float)((float)(vecr.x * 0.5) * vecl.x);
    vSoundSources[0].y = vSoundSources[0].y + (float)((float)(vecr.x * 0.5) * vecl.y);
    vSoundSources[1].x = vSoundSources[1].x + v18;
    vSoundSources[1].y = vSoundSources[1].y + (float)(vSoundSources[3].y * vecr.x);
    vSoundSources[1].z = vSoundSources[1].z + (float)(vSoundSources[3].z * vecr.x);
    vSoundSources[2].x = vSoundSources[2].x + (float)(vecl.x * vecr.x);
    v19 = vSoundSources[2].y + (float)(vecl.y * vecr.x);
    v31 = (float)(vecr.x * 0.5) * vSoundSources[3].z;
    vSoundSources[3].y = (float)(vecr.x * 0.5) * vSoundSources[3].y;
    vSoundSources[3].z = v31;
    vecl.x = (float)(vecr.x * 0.5) * vecl.x;
    vecl.y = (float)(vecr.x * 0.5) * vecl.y;
    vSoundSources[0].z = vSoundSources[0].z + (float)((float)(vecr.x * 0.5) * vecl.z);
    vSoundSources[2].y = v19;
    vSoundSources[2].z = vSoundSources[2].z + (float)(vecl.z * vecr.x);
    vecr.x = 0.0;
    v20 = MainViewOrigin(nSlot);
    p_filter = &filter;
    LODWORD(vecr.z) = 4;
    do
    {
      v22 = *(float *)&p_filter[-2].__vftable;
      v23 = *(float *)&p_filter[-1].__vftable;
      v24 = *(float *)&p_filter->__vftable;
      v44 = 0;
      v35 = v22 - v20->x;
      v36 = v23 - v20->y;
      v37 = v24 - v20->z;
      v46 = (float)((float)((float)(v36 * v36) + (float)(v35 * v35)) + (float)(v37 * v37)) != 0.0;
      v44 = 0;
      v43 = 0;
      v42 = 0;
      v41 = 0;
      v45 = 1;
      v40 = 0;
      v39 = 0;
      v38 = 0;
      *(float *)&ray.m_IsRay = v20->x;
      v25 = v20->y;
      LODWORD(vecr.y) = v29;
      *(float *)(&ray.m_IsSwept + 3) = v25;
      *(float *)(&ray.m_IsSwept + 7) = v20->z;
      g_pEngineTraceClient->TraceRay(
        this: g_pEngineTraceClient,
        a2: (const Ray_t *)&ray.m_IsRay,
        a3: 16387u,
        a4: (ITraceFilter *)&v51,
        a5: (CGameTrace *)v29);
      if ( (tr.plane.normal.z < 1.0 || tr.plane.pad[0] != 0 || tr.plane.pad[1] != 0)
        && tr.plane.normal.z < 0.99
        && tr.plane.pad[1] == 0 )
      {
        ++LODWORD(vecr.x);
        if ( SLODWORD(vecr.x) > 1 )
        {
          v26 = dB_To_Gain(dB: flOccludedDBLoss);
          vecr.y = v26 * vecr.y;
        }
      }
      p_filter += 3;
      --LODWORD(vecr.z);
    }
    while ( LODWORD(vecr.z) != 0 );
    x_low = LODWORD(vecr.x);
  }
  if ( snd_showstart.m_pParent != nullptr && snd_showstart.m_pParent->m_Value.m_nValue == 7 )
  {
    vecr.z = (float)(x_low - 1) * flOccludedDBLoss;
    if ( vecr.z != g_drop_prev_0 )
    {
      DevMsg(a1: "dB drop: %1.4f \n", vecr.z);
      g_drop_prev_0 = vecr.z;
    }
  }
  return vecr.y;
}

//------------------------------------------------------------------------------
// Address: 0x1004BCB0
// Name: public: virtual void CSosOperatorOcclusion::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorOcclusion::Execute(
        CSosOperatorOcclusion *this,
        Vector *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  float x; // xmm0_4
  bool v9; // bl
  double v10; // st7
  float v11; // xmm0_4
  double v12; // st7
  float flOccludedDBLoss; // [esp+0h] [ebp-28h]
  float flScalar; // [esp+20h] [ebp-8h]
  float flCurHostTime; // [esp+24h] [ebp-4h]
  int savedregs; // [esp+28h] [ebp+0h] BYREF
  float flGain; // [esp+30h] [ebp+8h]
  float flGaina; // [esp+30h] [ebp+8h]
  char flGain_3; // [esp+33h] [ebp+Bh]
  char flResult_3; // [esp+37h] [ebp+Fh]

  if ( pChannel != nullptr )
  {
    flScalar = pVoidMem[3].x;
    if ( flScalar == 0.0 )
    {
      pVoidMem[3].z = 1.0;
    }
    else
    {
      flCurHostTime = g_pSoundServices->GetHostTime(this: g_pSoundServices);
      x = pVoidMem[4].x;
      if ( x >= 0.0 && (float)(flCurHostTime - pVoidMem[4].z) >= x || (flResult_3 = 0, SLOBYTE(pChannel->flagsword) < 0) )
        flResult_3 = 1;
      flGain_3 = SND_ChannelOkToTrace(ch: pChannel);
      v9 = true;
      if ( !SND_IsInGame() )
        v9 = toolframework->InToolMode(this: toolframework);
      if ( (pChannel->flagsword & 0x82) == 0 && flResult_3 == 0 || flGain_3 == 0 )
        v9 = false;
      if ( v9 )
      {
        flOccludedDBLoss = 1.0
                         - (1.0
                          - S_CalcOcclusion(
                              a1: COERCE_FLOAT(&savedregs),
                              a2: (int)pChannel,
                              a3: (int)pVoidMem,
                              nSlot: 0,
                              ch: pChannel,
                              vecListenerOrigin: pScratchPad->m_vPlayerOrigin,
                              vSoundSource: pVoidMem[1],
                              flOccludedDBLoss: pVoidMem[5].x))
                         * flScalar;
        v10 = SND_FadeToNewGain(gs: pChannel->gain, ch: pChannel, gain_new: flOccludedDBLoss);
        if ( v10 < 0.0 )
        {
          v11 = 0.0;
        }
        else
        {
          flGain = v10;
          v11 = flGain;
        }
        pVoidMem[4].z = flCurHostTime;
      }
      else
      {
        v12 = SND_FadeToNewGain(gs: pChannel->gain, ch: pChannel, gain_new: -1.0);
        if ( v12 < 0.0 )
        {
          v11 = 0.0;
        }
        else
        {
          flGaina = v12;
          v11 = flGaina;
        }
      }
      pVoidMem[3].z = v11;
      if ( snd_sos_show_operator_updates.m_pParent != nullptr
        && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
      {
        this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
      }
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Error: Sound operator %s requires valid channel pointer, being called without one\n",
      pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004BED0
// Name: public: CSosOperatorOcclusion::CSosOperatorOcclusion(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorOcclusion *__thiscall CSosOperatorOcclusion::CSosOperatorOcclusion(CSosOperatorOcclusion *this)
{
  int v2; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  int v7; // [esp-8h] [ebp-28h]
  CSosOperator::OutputData_t outputData; // [esp+Ch] [ebp-14h] BYREF
  __int16 v9; // [esp+18h] [ebp-8h]
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorOcclusion_vtbl *)&CSosOperatorOcclusion::`vftable';
  m_Size = this->m_vInputs.m_Size;
  outputData.m_nOffset = 48;
  outputData.m_Type = 52;
  *(_DWORD *)&outputData.m_nCount = 0;
  v9 = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_trace_interval", element: &nIndex);
  v2 = this->m_vInputs.m_Size;
  v9 = 1;
  outputData.m_nOffset = 36;
  outputData.m_Type = 40;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v2,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_scalar", element: &nIndex);
  v6 = this->m_vInputs.m_Size;
  outputData.m_nOffset = 12;
  outputData.m_Type = 24;
  *(_DWORD *)&outputData.m_nCount = 0;
  v9 = 3;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v6,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_position", element: &nIndex);
  v9 = 1;
  v7 = this->m_vOutputs.m_Size;
  outputData.m_Type = 44;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v7,
             src: (const Vector *)&outputData.m_Type);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "calc_occlusion",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004C010
// Name: public: virtual unsigned int CSosOperatorOcclusion::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorOcclusion::GetSize(CSosOperatorOcclusion *this)
{
  return 64;
}

} // namespace engine_xlsp
