// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/perfvisualbenchmark.cpp
// Functions: 21
// ============================================================

#include "game\client\perfvisualbenchmark.h"

//------------------------------------------------------------------------------
// Address: 0x10105430
// Name: public: void CUtlMemory<struct CPerfVisualBenchmark::RunInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CPerfVisualBenchmark::RunInfo_t,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013C0A0
// Name: class IGameSystem __near * PerfVisualBenchmark(void)
// Source: json
//------------------------------------------------------------------------------
CPerfVisualBenchmark *__cdecl PerfVisualBenchmark()
{
  return &s_PerfVisualBenchmark;
}

//------------------------------------------------------------------------------
// Address: 0x1013C0B0
// Name: public: void CPerfVisualBenchmark::Start(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerfVisualBenchmark::Start(CPerfVisualBenchmark *this)
{
  int m_nValue; // eax
  float v3; // xmm0_4

  if ( cl_mouseenable.m_pParent != nullptr )
    m_nValue = cl_mouseenable.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  this->m_bSaveMouseEnable = m_nValue != 0;
  ConVar::SetValue(this: (ConVar *)&cl_mouseenable.IConVar, value: 0);
  this->m_iCurVar = 0;
  v3 = *(float *)gpGlobals.m_Index + 1.5;
  this->m_bWaiting = true;
  this->m_bIsOn = true;
  this->m_flTimer = v3;
  engine->ClientCmd_Unrestricted(this: engine, a2: "cancelselect");
  engine->ClientCmd_Unrestricted(this: engine, a2: "host_timescale 0.0001");
}

//------------------------------------------------------------------------------
// Address: 0x1013C130
// Name: private: void CPerfVisualBenchmark::Print(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerfVisualBenchmark::Print(CPerfVisualBenchmark *this)
{
  CPerfVisualBenchmark *v1; // edi
  int m_Size; // ecx
  int v3; // esi
  int v4; // eax
  CPerfVisualBenchmark::RunInfo_t *m_pMemory; // ebx
  int v6; // edx
  float *p_m_flFPS; // ecx
  int v8; // edi
  int v9; // edx
  int v10; // ecx
  int v11; // esi
  CPerfVisualBenchmark *v12; // [esp+18h] [ebp-10h]
  int v13; // [esp+1Ch] [ebp-Ch]
  CPerfVisualBenchmark::RunInfo_t *v14; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]

  v1 = this;
  m_Size = this->m_RunInfo.m_Size;
  v12 = v1;
  for ( i = 0; i < m_Size; ++i )
  {
    v3 = 0;
    v4 = 0;
    if ( m_Size >= 4 )
    {
      m_pMemory = v1->m_RunInfo.m_Memory.m_pMemory;
      v13 = m_Size - 3;
      v6 = 0;
      v14 = m_pMemory;
      p_m_flFPS = &m_pMemory[1].m_flFPS;
      v8 = -(int)m_pMemory;
      while ( 1 )
      {
        if ( *(p_m_flFPS - 6) > *(float *)((char *)&m_pMemory->m_flFPS + v6) )
        {
          v3 = v4;
          v6 = (int)p_m_flFPS + v8 - 44;
        }
        if ( *p_m_flFPS > *(float *)((char *)&m_pMemory->m_flFPS + v6) )
        {
          v3 = v4 + 1;
          v6 = (int)p_m_flFPS + v8 - 20;
        }
        if ( p_m_flFPS[6] > *(float *)((char *)&m_pMemory->m_flFPS + v6) )
        {
          v3 = v4 + 2;
          v6 = (int)p_m_flFPS + v8 + 4;
        }
        if ( p_m_flFPS[12] > *(float *)((char *)&m_pMemory->m_flFPS + v6) )
        {
          v3 = v4 + 3;
          v6 = (int)p_m_flFPS + v8 + 28;
        }
        v4 += 4;
        p_m_flFPS += 24;
        if ( v4 >= v13 )
          break;
        m_pMemory = v14;
      }
      v1 = v12;
    }
    if ( v4 < v1->m_RunInfo.m_Size )
    {
      v9 = 24 * v3;
      v10 = v4;
      do
      {
        if ( v1->m_RunInfo.m_Memory.m_pMemory[v10].m_flFPS > *(float *)((char *)&v1->m_RunInfo.m_Memory.m_pMemory->m_flFPS
                                                                      + v9) )
        {
          v3 = v4;
          v9 = v10 * 24;
        }
        ++v4;
        ++v10;
      }
      while ( v4 < v1->m_RunInfo.m_Size );
    }
    v11 = v3;
    _Msg(
      a1: "%.0f fps - %s\n",
      v1->m_RunInfo.m_Memory.m_pMemory[v11].m_flFPS,
      v1->m_RunInfo.m_Memory.m_pMemory[v11].m_pDescription);
    v1->m_RunInfo.m_Memory.m_pMemory[v11].m_flFPS = -1.0;
    m_Size = v1->m_RunInfo.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013C270
// Name: void usrCmd_Start(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl usrCmd_Start()
{
  CPerfVisualBenchmark::Start(this: &s_PerfVisualBenchmark);
}

//------------------------------------------------------------------------------
// Address: 0x1013C280
// Name: public: void CPerfVisualBenchmark::Stop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerfVisualBenchmark::Stop(CPerfVisualBenchmark *this)
{
  ConVar::SetValue(this: (ConVar *)&cl_mouseenable.IConVar, value: this->m_bSaveMouseEnable);
  this->m_bIsOn = false;
  CPerfVisualBenchmark::Print(this);
  engine->ClientCmd_Unrestricted(this: engine, a2: "host_timescale 0");
  engine->ClientCmd_Unrestricted(this: engine, a2: "toggleconsole");
}

//------------------------------------------------------------------------------
// Address: 0x1013C2D0
// Name: public: virtual void CPerfVisualBenchmark::PreRender(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerfVisualBenchmark::PreRender(CPerfVisualBenchmark *this)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  CPerfVisualBenchmark::RunInfo_t *v4; // eax
  int v5; // eax
  char combuffer[256]; // [esp+4h] [ebp-100h] BYREF

  if ( this->m_bIsOn )
  {
    v2 = *(float *)gpGlobals.m_Index;
    if ( this->m_flTimer <= *(float *)gpGlobals.m_Index )
    {
      if ( this->m_bWaiting )
      {
        this->m_flTimer = v2 + 2.0;
        this->m_flStartMeasureTime = *(float *)gpGlobals.m_Index;
        this->m_nStartFrameCount = *(_DWORD *)(gpGlobals.m_Index + 4);
        this->m_bWaiting = false;
      }
      else
      {
        v3 = v2 - this->m_flStartMeasureTime;
        if ( v3 == 0.0 )
          v3 = 1.0;
        this->m_RunInfo.m_Memory.m_pMemory[this->m_iCurVar].m_flFPS = (float)(*(_DWORD *)(gpGlobals.m_Index + 4)
                                                                            - this->m_nStartFrameCount)
                                                                    / v3;
        v4 = &this->m_RunInfo.m_Memory.m_pMemory[this->m_iCurVar];
        this->m_flTimer = *(float *)gpGlobals.m_Index + 1.5;
        this->m_bWaiting = true;
        if ( v4->m_pVarName != nullptr )
        {
          V_snprintf(pDest: combuffer, maxLen: 0xFFu, pFormat: "%s %s\n", v4->m_pVarName, v4->m_pOffVal);
          engine->ClientCmd_Unrestricted(this: engine, a2: combuffer);
        }
        v5 = ++this->m_iCurVar;
        if ( v5 == this->m_RunInfo.m_Size )
        {
          CPerfVisualBenchmark::Stop(this);
        }
        else
        {
          V_snprintf(
            pDest: combuffer,
            maxLen: 0xFFu,
            pFormat: "%s %s\n",
            this->m_RunInfo.m_Memory.m_pMemory[v5].m_pVarName,
            this->m_RunInfo.m_Memory.m_pMemory[v5].m_pOnVal);
          engine->ClientCmd_Unrestricted(this: engine, a2: combuffer);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013C430
// Name: void usrCmd_Abort(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl usrCmd_Abort()
{
  ConVar::SetValue(this: (ConVar *)&cl_mouseenable.IConVar, value: s_PerfVisualBenchmark.m_bSaveMouseEnable);
  s_PerfVisualBenchmark.m_bIsOn = false;
  CPerfVisualBenchmark::Print(this: &s_PerfVisualBenchmark);
  engine->ClientCmd_Unrestricted(this: engine, a2: "host_timescale 0");
  engine->ClientCmd_Unrestricted(this: engine, a2: "toggleconsole");
}

//------------------------------------------------------------------------------
// Address: 0x1013C480
// Name: public: virtual char const __near * CPerfVisualBenchmark::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPerfVisualBenchmark::Name(CPerfVisualBenchmark *this)
{
  return "CPerfVisualBenchmark";
}

//------------------------------------------------------------------------------
// Address: 0x1013C4D0
// Name: public: virtual bool CPerfVisualBenchmark::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPerfVisualBenchmark::Init(CPerfVisualBenchmark *this)
{
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int> > *p_m_RunInfo; // esi
  int v2; // ecx
  int m_Size; // [esp-14h] [ebp-30h]
  int v5; // [esp-14h] [ebp-30h]
  int v6; // [esp-14h] [ebp-30h]
  int v7; // [esp-14h] [ebp-30h]
  int v8; // [esp-14h] [ebp-30h]
  int v9; // [esp-14h] [ebp-30h]
  int v10; // [esp-14h] [ebp-30h]
  int v11; // [esp-14h] [ebp-30h]
  int v12; // [esp-14h] [ebp-30h]
  int v13; // [esp-14h] [ebp-30h]
  int v14; // [esp-14h] [ebp-30h]
  int v15; // [esp-14h] [ebp-30h]
  int v16; // [esp-14h] [ebp-30h]
  int v17; // [esp-14h] [ebp-30h]
  int v18; // [esp-14h] [ebp-30h]
  int v19; // [esp-14h] [ebp-30h]
  int v20; // [esp-14h] [ebp-30h]
  int v21; // [esp-14h] [ebp-30h]
  int v22; // [esp-14h] [ebp-30h]
  int v23; // [esp-14h] [ebp-30h]
  CPerfVisualBenchmark::RunInfo_t runInfo; // [esp+0h] [ebp-1Ch] BYREF
  CPerfVisualBenchmark *v25; // [esp+18h] [ebp-4h]

  p_m_RunInfo = (CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int> > *)&this->m_RunInfo;
  runInfo.m_pVarName = prType;
  runInfo.m_pOnVal = prType;
  runInfo.m_pOffVal = prType;
  v25 = this;
  m_Size = this->m_RunInfo.m_Size;
  runInfo.m_pDescription = "Default";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: (CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int> > *)&this->m_RunInfo,
    elem: m_Size,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v5 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "r_drawdetailprops";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "detail props";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v5,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v6 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "r_drawworld";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "world geometry";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v6,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v7 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "r_drawentities";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "entities";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v7,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v8 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "r_3dsky";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "3D skybox";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v8,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v9 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "r_drawdecals";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "decals";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v9,
    src: (const PanelAnimationMapEntry *)&runInfo);
  runInfo.m_pVarName = "mat_stub";
  v10 = p_m_RunInfo->m_Size;
  runInfo.m_pOnVal = "1";
  runInfo.m_pOffVal = "0";
  runInfo.m_pDescription = "material system and below";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v10,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v11 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "mat_viewportscale";
  runInfo.m_pOnVal = ".2";
  runInfo.m_pOffVal = "1.0";
  runInfo.m_pDescription = "fillrate";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v11,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v12 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "r_drawstaticprops";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "fillrate";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v12,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v13 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "r_drawbrushmodels";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "brush models";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v13,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v14 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "r_renderoverlayfragment";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "overlays";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v14,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v15 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "r_drawdisp";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "displacements";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v15,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v2 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "r_drawviewmodel";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "viewmodel";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v2,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v16 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "cl_drawhud";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "hud";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v16,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v17 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "r_drawparticles";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "particles";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v17,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v18 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "r_drawsprites";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "sprites";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v18,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v19 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "mat_bumpmap";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "bump mapping";
  runInfo.m_flStabilizeTime = 10.0;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v19,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v20 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "mat_specular";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "specularity";
  runInfo.m_flStabilizeTime = 10.0;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v20,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v21 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "mat_drawwater";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "water";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v21,
    src: (const PanelAnimationMapEntry *)&runInfo);
  runInfo.m_pVarName = "r_dynamic";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "dynamic lighting";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: p_m_RunInfo->m_Size,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v22 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "r_shadows";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "shadows";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v22,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v23 = p_m_RunInfo->m_Size;
  runInfo.m_pVarName = "r_drawropes";
  runInfo.m_pOnVal = "0";
  runInfo.m_pOffVal = "1";
  runInfo.m_pDescription = "ropes";
  runInfo.m_flStabilizeTime = 1.5;
  CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
    this: p_m_RunInfo,
    elem: v23,
    src: (const PanelAnimationMapEntry *)&runInfo);
  v25->m_bIsOn = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1041B200
// Name: _dynamic_initializer_for__perfvisualbenchmark__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__perfvisualbenchmark__()
{
  ConCommand::ConCommand(
    this: &perfvisualbenchmark,
    pName: "perfvisualbenchmark",
    callback: usrCmd_Start,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__perfvisualbenchmark__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B230
// Name: _dynamic_initializer_for__perfvisualbenchmark_abort__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__perfvisualbenchmark_abort__()
{
  ConCommand::ConCommand(
    this: &perfvisualbenchmark_abort,
    pName: "perfvisualbenchmark_abort",
    callback: usrCmd_Abort,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__perfvisualbenchmark_abort__);
}

//------------------------------------------------------------------------------
// Address: 0x10433290
// Name: _dynamic_atexit_destructor_for__perfvisualbenchmark__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__perfvisualbenchmark__()
{
  ConCommand::~ConCommand(this: &perfvisualbenchmark);
}

//------------------------------------------------------------------------------
// Address: 0x104332A0
// Name: _dynamic_atexit_destructor_for__perfvisualbenchmark_abort__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__perfvisualbenchmark_abort__()
{
  ConCommand::~ConCommand(this: &perfvisualbenchmark_abort);
}

//------------------------------------------------------------------------------
// Address: 0x1041B260
// Name: _dynamic_initializer_for__cl_phys_timescale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_phys_timescale__()
{
  ConVar::ConVar(
    this: &cl_phys_timescale,
    pName: "cl_phys_timescale",
    pDefaultValue: "1.0",
    flags: 0x4000,
    pHelpString: "Sets the scale of time for client-side physics (ragdolls)");
  return atexit(func: dynamic_atexit_destructor_for__cl_phys_timescale__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B290
// Name: _dynamic_initializer_for__cl_phys_maxticks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_phys_maxticks__()
{
  ConVar::ConVar(
    this: &cl_phys_maxticks,
    pName: "cl_phys_maxticks",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Sets the max number of physics ticks allowed for client-side physics (ragdolls)");
  return atexit(func: dynamic_atexit_destructor_for__cl_phys_maxticks__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B2C0
// Name: _dynamic_initializer_for__cl_ragdoll_gravity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_ragdoll_gravity__()
{
  ConVar::ConVar(
    this: &cl_ragdoll_gravity,
    pName: "cl_ragdoll_gravity",
    pDefaultValue: "386",
    flags: 0x4000,
    pHelpString: "Sets the gravity client-side ragdolls");
  return atexit(func: dynamic_atexit_destructor_for__cl_ragdoll_gravity__);
}

//------------------------------------------------------------------------------
// Address: 0x104332B0
// Name: _dynamic_atexit_destructor_for__s_PerfVisualBenchmark__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_PerfVisualBenchmark__()
{
  s_PerfVisualBenchmark.__vftable = (CPerfVisualBenchmark_vtbl *)&CPerfVisualBenchmark::`vftable';
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_PerfVisualBenchmark.m_RunInfo);
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &s_PerfVisualBenchmark);
}

//------------------------------------------------------------------------------
// Address: 0x104332D0
// Name: _dynamic_atexit_destructor_for__cl_phys_timescale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_phys_timescale__()
{
  ConVar::~ConVar(this: &cl_phys_timescale);
}

//------------------------------------------------------------------------------
// Address: 0x104332E0
// Name: _dynamic_atexit_destructor_for__cl_phys_maxticks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_phys_maxticks__()
{
  ConVar::~ConVar(this: &cl_phys_maxticks);
}

//------------------------------------------------------------------------------
// Address: 0x104332F0
// Name: _dynamic_atexit_destructor_for__cl_ragdoll_gravity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_ragdoll_gravity__()
{
  ConVar::~ConVar(this: &cl_ragdoll_gravity);
}
