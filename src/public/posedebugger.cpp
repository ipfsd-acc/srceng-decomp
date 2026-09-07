// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/posedebugger.cpp
// Functions: 12
// ============================================================

#include "public\posedebugger.h"

//------------------------------------------------------------------------------
// Address: 0x1014DB30
// Name: public: struct mstudioseqdesc_t __near & mstudioseqdesc_t::operator=(struct mstudioseqdesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall mstudioseqdesc_t::operator=(mstudioseqdesc_t *this, const mstudioseqdesc_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014DD10
// Name: public: void CUtlMemory<struct ModelPoseDebugInfo::InfoText,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ModelPoseDebugInfo::InfoText,int>::Grow(
        CUtlMemory<ModelPoseDebugInfo::InfoText,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ModelPoseDebugInfo::InfoText *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 1240 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ModelPoseDebugInfo::InfoText *)_g_pMemAlloc->Realloc_2(
                                                          this: _g_pMemAlloc,
                                                          a2: m_pMemory,
                                                          a3: v7);
    else
      this->m_pMemory = (ModelPoseDebugInfo::InfoText *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014DE60
// Name: public: struct ModelPoseDebugInfo::InfoText __near * ModelPoseDebugInfo::LookupInfoText(struct ModelPoseDebugInfo::InfoText __near *)
// Source: json
//------------------------------------------------------------------------------
ModelPoseDebugInfo::InfoText *__thiscall ModelPoseDebugInfo::LookupInfoText(
        ModelPoseDebugInfo *this,
        ModelPoseDebugInfo::InfoText *x)
{
  int m_iCurrentText; // eax
  int i; // ebx
  ModelPoseDebugInfo::InfoText *v5; // esi
  int k; // [esp+Ch] [ebp-4h]

  m_iCurrentText = this->m_iCurrentText;
  k = m_iCurrentText;
  if ( x == nullptr || m_iCurrentText >= this->m_arrTxt.m_Size )
    return nullptr;
  for ( i = m_iCurrentText; ; ++i )
  {
    v5 = &this->m_arrTxt.m_Memory.m_pMemory[i];
    if ( (v5->m_uiFlags & 1) != 0 )
      break;
LABEL_9:
    k = ++m_iCurrentText;
    if ( m_iCurrentText >= this->m_arrTxt.m_Size )
      return nullptr;
  }
  if ( _V_stricmp(s1: x->m_chActivity, s2: v5->m_chActivity) != 0
    || _V_stricmp(s1: x->m_chLabel, s2: v5->m_chLabel) != 0
    || x->m_iActivity != v5->m_iActivity )
  {
    m_iCurrentText = k;
    goto LABEL_9;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1014DEF0
// Name: public: void ModelPoseDebugInfo::PrintPendingInfoText(int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ModelPoseDebugInfo::PrintPendingInfoText(ModelPoseDebugInfo *this, int *rnPosPrint)
{
  float m_fValue; // xmm2_4
  int m_iCurrentText; // eax
  float v4; // xmm3_4
  int v5; // eax
  char *v6; // edi
  float v7; // xmm1_4
  float v8; // xmm2_4
  int v9; // ebx
  _BYTE *v10; // edi
  con_nprint_s nxPrn; // [esp+0h] [ebp-2Ch] BYREF
  float flFadeInTime; // [esp+18h] [ebp-14h]
  float flFadeOutTime; // [esp+1Ch] [ebp-10h]
  int k; // [esp+20h] [ebp-Ch]
  ModelPoseDebugInfo *v15; // [esp+24h] [ebp-8h]
  int v16; // [esp+28h] [ebp-4h]

  *(_DWORD *)&nxPrn.fixed_width_font = 1;
  nxPrn.index = 0;
  nxPrn.time_to_live = -1.0;
  nxPrn.color[0] = 1.0;
  nxPrn.color[1] = 1.0;
  nxPrn.color[2] = 1.0;
  m_fValue = ui_posedebug_fade_in_time.m_pParent->m_Value.m_fValue;
  m_iCurrentText = this->m_iCurrentText;
  v4 = ui_posedebug_fade_out_time.m_pParent->m_Value.m_fValue;
  v15 = this;
  flFadeInTime = m_fValue;
  flFadeOutTime = v4;
  k = m_iCurrentText;
  if ( m_iCurrentText < this->m_arrTxt.m_Size )
  {
    v5 = 1240 * m_iCurrentText;
    v16 = v5;
    while ( 1 )
    {
      v6 = (char *)this->m_arrTxt.m_Memory.m_pMemory + v5;
      switch ( *(_DWORD *)v6 & 3 )
      {
        case 0:
        case 2:
          if ( v4 <= 0.0 )
          {
            if ( *((float *)v6 + 1) <= 0.0 )
              nxPrn.color[0] = 0.0;
            else
              nxPrn.color[0] = 1.0;
          }
          else
          {
            nxPrn.color[0] = *((float *)v6 + 1) / v4;
          }
          nxPrn.color[1] = 0.0;
          goto LABEL_19;
        case 1:
          goto $LN12_9;
        case 3:
          nxPrn.color[0] = 1.0;
          nxPrn.color[1] = 1.0;
          nxPrn.color[2] = 1.0;
          if ( *((float *)v6 + 2) <= m_fValue )
          {
$LN12_9:
            if ( m_fValue <= 0.0 )
            {
              if ( *((float *)v6 + 2) <= 0.0 )
                nxPrn.color[0] = 0.0;
              else
                nxPrn.color[0] = 1.0;
              nxPrn.color[1] = 1.0;
              if ( *((float *)v6 + 2) <= 0.0 )
LABEL_19:
                nxPrn.color[2] = 0.0;
              else
                nxPrn.color[2] = 1.0;
            }
            else
            {
              v7 = 1.0 / m_fValue;
              v8 = *((float *)v6 + 2) * (float)(1.0 / m_fValue);
              nxPrn.color[1] = 1.0;
              nxPrn.color[0] = v8;
              nxPrn.color[2] = *((float *)v6 + 2) * v7;
            }
          }
          nxPrn.index = ++*rnPosPrint;
          engine->Con_NXPrintf(this: engine, a2: &nxPrn, a3: "%s", v6 + 216);
          v9 = 1;
          v10 = v6 + 472;
          do
          {
            if ( *v10 == 0 )
              break;
            nxPrn.index = ++*rnPosPrint;
            engine->Con_NXPrintf(this: engine, a2: &nxPrn, a3: "%s", v10);
            ++v9;
            v10 += 256;
          }
          while ( v9 < 4 );
          this = v15;
          v16 += 1240;
          if ( ++k >= v15->m_arrTxt.m_Size )
          {
            v15->m_iCurrentText = v15->m_arrTxt.m_Size;
            return;
          }
          v4 = flFadeOutTime;
          m_fValue = flFadeInTime;
          v5 = v16;
          break;
      }
    }
  }
  this->m_iCurrentText = this->m_arrTxt.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1014E110
// Name: public: bool CPoseDebuggerImpl::IsModelShown(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPoseDebuggerImpl::IsModelShown(CPoseDebuggerImpl *this, int iEntNum)
{
  return (unsigned int)iEntNum <= 0x7FF
      && (this->m_uiMaskShowModels.m_Ints[iEntNum >> 5] & (1 << (iEntNum & 0x1F))) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014E150
// Name: IN_PoseDebuggerStart
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_PoseDebuggerStart(const CCommand *args)
{
  int m_nArgc; // eax
  int v2; // esi
  const char **v3; // edi
  const char *v4; // eax
  int v5; // eax

  if ( args->m_nArgc > 1 )
  {
    if ( g_pPoseDebugger != &s_PoseDebuggerImpl )
      memset(
        dst: (int)&s_PoseDebuggerImpl.m_uiMaskShowModels,
        value: nullptr,
        count: sizeof(s_PoseDebuggerImpl.m_uiMaskShowModels));
    m_nArgc = args->m_nArgc;
    v2 = 1;
    if ( args->m_nArgc <= 1 )
    {
      g_pPoseDebugger = &s_PoseDebuggerImpl;
    }
    else
    {
      v3 = &args->m_ppArgv[1];
      do
      {
        if ( v2 < 0 || v2 >= m_nArgc )
          v4 = prType;
        else
          v4 = *v3;
        v5 = atoi(nptr: v4);
        if ( v5 < 2048 )
          s_PoseDebuggerImpl.m_uiMaskShowModels.m_Ints[v5 >> 5] |= 1 << (v5 & 0x1F);
        m_nArgc = args->m_nArgc;
        ++v2;
        ++v3;
      }
      while ( v2 < args->m_nArgc );
      g_pPoseDebugger = &s_PoseDebuggerImpl;
    }
  }
  else
  {
    memset(
      dst: (int)&s_PoseDebuggerImpl.m_uiMaskShowModels,
      value: (unsigned __int8 *)0xFF,
      count: sizeof(s_PoseDebuggerImpl.m_uiMaskShowModels));
    g_pPoseDebugger = &s_PoseDebuggerImpl;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E220
// Name: IN_PoseDebuggerEnd
// Source: json
//------------------------------------------------------------------------------
void __cdecl IN_PoseDebuggerEnd(const CCommand *args)
{
  int m_nArgc; // eax
  int v2; // esi
  const char **v3; // edi
  const char *v4; // eax
  int v5; // eax

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc > 1 )
  {
    v2 = 1;
    v3 = &args->m_ppArgv[1];
    do
    {
      if ( v2 < 0 || v2 >= m_nArgc )
        v4 = prType;
      else
        v4 = *v3;
      v5 = atoi(nptr: v4);
      if ( v5 < 2048 )
        s_PoseDebuggerImpl.m_uiMaskShowModels.m_Ints[v5 >> 5] &= ~(1 << (v5 & 0x1F));
      m_nArgc = args->m_nArgc;
      ++v2;
      ++v3;
    }
    while ( v2 < args->m_nArgc );
  }
  else
  {
    memset(
      dst: (int)&s_PoseDebuggerImpl.m_uiMaskShowModels,
      value: nullptr,
      count: sizeof(s_PoseDebuggerImpl.m_uiMaskShowModels));
    g_pPoseDebugger = &s_PoseDebuggerStub;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014F240
// Name: public: void ModelPoseDebugInfo::AddInfoText(struct ModelPoseDebugInfo::InfoText __near *,class ModelPoseDebugInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ModelPoseDebugInfo::AddInfoText(
        ModelPoseDebugInfo *this,
        ModelPoseDebugInfo::InfoText *x,
        ModelPoseDebugInfo *pOld)
{
  ModelPoseDebugInfo::InfoText *v3; // edx
  ModelPoseDebugInfo *v4; // esi
  int m_iCurrentText; // ebx
  int v6; // eax
  char *v7; // edi
  int v8; // eax
  int v9; // ecx
  ModelPoseDebugInfo::InfoText *m_pMemory; // ebx
  int v11; // eax
  float *v12; // ebx
  int m_Size; // esi
  int m_nAllocationCount; // eax
  ModelPoseDebugInfo::InfoText *v15; // ecx
  int v16; // eax
  ModelPoseDebugInfo::InfoText *v17; // edi
  bool v18; // zf
  int v19; // ebx
  int v20; // eax
  ModelPoseDebugInfo::InfoText *v21; // ecx
  int v22; // eax
  ModelPoseDebugInfo::InfoText *v23; // ebx
  int v25; // [esp+4h] [ebp-8h]
  int v26; // [esp+8h] [ebp-4h]
  int v27; // [esp+8h] [ebp-4h]

  v3 = x;
  if ( x != nullptr )
    x->m_uiFlags = x->m_uiFlags & 0xFFFFFFFC | 1;
  v4 = pOld;
  if ( pOld != nullptr )
  {
    m_iCurrentText = pOld->m_iCurrentText;
    if ( x != nullptr )
    {
      if ( m_iCurrentText >= pOld->m_arrTxt.m_Size )
        goto LABEL_16;
      v6 = 1240 * m_iCurrentText;
      v26 = 1240 * m_iCurrentText;
      while ( 1 )
      {
        v7 = (char *)pOld->m_arrTxt.m_Memory.m_pMemory + v6;
        if ( (*v7 & 1) != 0 )
        {
          if ( _V_stricmp(s1: v3->m_chActivity, s2: v7 + 16) == 0
            && _V_stricmp(s1: x->m_chLabel, s2: v7 + 116) == 0
            && x->m_iActivity == *((_DWORD *)v7 + 3) )
          {
            x->m_flTimeAlive = *((float *)v7 + 2);
            v3 = x;
            goto LABEL_16;
          }
          v6 = v26;
          v3 = x;
        }
        ++m_iCurrentText;
        v6 += 1240;
        v26 = v6;
        if ( m_iCurrentText >= pOld->m_arrTxt.m_Size )
          goto LABEL_16;
      }
    }
    m_iCurrentText = pOld->m_arrTxt.m_Size;
LABEL_16:
    v8 = pOld->m_iCurrentText;
    if ( m_iCurrentText == pOld->m_arrTxt.m_Size )
    {
      if ( v3 != nullptr )
        m_iCurrentText = pOld->m_iCurrentText;
      else
        pOld->m_iCurrentText = m_iCurrentText;
    }
    else
    {
      pOld->m_iCurrentText = m_iCurrentText + 1;
      if ( v3 != nullptr )
      {
        v3->m_uiFlags |= 2u;
        v3->m_flTimeAlive = *(float *)(gpGlobals.m_Index + 16) + v3->m_flTimeAlive;
      }
    }
    if ( v8 < m_iCurrentText )
    {
      v9 = 1240 * v8;
      v27 = 1240 * v8;
      v25 = m_iCurrentText - v8;
      do
      {
        m_pMemory = v4->m_arrTxt.m_Memory.m_pMemory;
        v11 = *(unsigned int *)((char *)&m_pMemory->m_uiFlags + v9);
        v12 = (float *)((char *)&m_pMemory->m_uiFlags + v9);
        if ( (v11 & 1) != 0 )
          *(_DWORD *)v12 = v11 | 2;
        *(_DWORD *)v12 &= ~1u;
        v12[1] = v12[1] - *(float *)(gpGlobals.m_Index + 16);
        v12[2] = *(float *)(gpGlobals.m_Index + 16) + v12[2];
        if ( v12[1] >= 0.0 )
        {
          m_Size = this->m_arrTxt.m_Size;
          m_nAllocationCount = this->m_arrTxt.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ModelPoseDebugInfo::InfoText,int>::Grow(
              this: &this->m_arrTxt.m_Memory,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_arrTxt.m_Size;
          v15 = this->m_arrTxt.m_Memory.m_pMemory;
          v16 = this->m_arrTxt.m_Size - m_Size - 1;
          this->m_arrTxt.m_pElements = v15;
          if ( v16 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v15[m_Size + 1],
              src: (unsigned __int8 *)&v15[m_Size],
              count: 1240 * v16);
          v17 = &this->m_arrTxt.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            qmemcpy(v17, v12, sizeof(ModelPoseDebugInfo::InfoText));
          v4 = pOld;
        }
        v9 = v27 + 1240;
        v18 = v25-- == 1;
        v27 += 1240;
      }
      while ( !v18 );
      v3 = x;
    }
  }
  if ( v3 != nullptr )
  {
    v3->m_flTimeToLive = ui_posedebug_fade_out_time.m_pParent->m_Value.m_fValue;
    v19 = this->m_arrTxt.m_Size;
    v20 = this->m_arrTxt.m_Memory.m_nAllocationCount;
    if ( v19 + 1 > v20 )
    {
      CUtlMemory<ModelPoseDebugInfo::InfoText,int>::Grow(this: &this->m_arrTxt.m_Memory, num: v19 - v20 + 1);
      v3 = x;
    }
    ++this->m_arrTxt.m_Size;
    v21 = this->m_arrTxt.m_Memory.m_pMemory;
    v22 = this->m_arrTxt.m_Size - v19 - 1;
    this->m_arrTxt.m_pElements = v21;
    if ( v22 > 0 )
    {
      _V_memmove(dest: (unsigned __int8 *)&v21[v19 + 1], src: (unsigned __int8 *)&v21[v19], count: 1240 * v22);
      v3 = x;
    }
    v23 = &this->m_arrTxt.m_Memory.m_pMemory[v19];
    if ( v23 != nullptr )
      qmemcpy(v23, v3, sizeof(ModelPoseDebugInfo::InfoText));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014F620
// Name: public: virtual void CPoseDebuggerImpl::AccumulatePose(class CStudioHdr const __near *,class CIKContext __near *,class Vector __near * const,class Quaternion __near * const,int,float,float const __near * const,int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPoseDebuggerImpl::AccumulatePose(
        CPoseDebuggerImpl *this,
        CStudioHdr *pStudioHdr,
        CIKContext *pIKContext,
        Vector *pos,
        Quaternion *q,
        float sequence,
        float cycle,
        const float *poseParameter,
        int boneMask,
        float flWeight,
        float flTime)
{
  CStudioHdr *v12; // edi
  int v13; // ebx
  UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int m_iEntNum; // ecx
  unsigned __int16 v16; // ax
  float v17; // ebx
  mstudioseqdesc_t *v18; // esi
  int NumSeq_Internal; // eax
  const mstudioseqdesc_t *v20; // eax
  int m_Size; // ecx
  ModelPoseDebugInfo::InfoText *v22; // eax
  ModelPoseDebugInfo::InfoText *v23; // eax
  float m_flTimeAlive; // xmm0_4
  int szlabelindex; // edi
  int szactivitynameindex; // ebx
  int v27; // eax
  int v28; // eax
  mstudioanimdesc_t *v29; // eax
  int v30; // edi
  int v31; // edi
  int v32; // ebx
  const char *v33; // eax
  char *v34; // ecx
  int numikrules; // esi
  ModelPoseDebugInfo *v36; // esi
  int numframes; // [esp+18h] [ebp-624h]
  double v38; // [esp+20h] [ebp-61Ch]
  ModelPoseDebugInfo::InfoText txt; // [esp+34h] [ebp-608h] BYREF
  char chBuffer[256]; // [esp+50Ch] [ebp-130h] BYREF
  CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t search; // [esp+60Ch] [ebp-30h] BYREF
  CPoseDebuggerImpl *v42; // [esp+630h] [ebp-Ch]
  ModelPoseDebugInfo *mpi; // [esp+634h] [ebp-8h]
  ModelPoseDebugInfo *pMpiOld; // [esp+638h] [ebp-4h]

  v42 = this;
  if ( (unsigned __int8)_ThreadInMainThread(a1: this) != 0 )
  {
    v12 = pStudioHdr;
    if ( pStudioHdr->m_pStudioHdr != nullptr && pStudioHdr->m_pStudioHdr->numincludemodels != 0 )
    {
      search.elem.m_iEntNum = 0;
      search.elem.m_iCurrentText = 0;
      memset(
        &search.elem.m_arrTxt.CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >,
        0,
        sizeof(search.elem.m_arrTxt.CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >));
      search.elem.m_arrTxt.__vftable = (CCopyableUtlVector<ModelPoseDebugInfo::InfoText>_vtbl *)&CCopyableUtlVector<ModelPoseDebugInfo::InfoText>::`vftable';
      search.key = pStudioHdr;
      v13 = CUtlRBTree<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short,CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
              this: &this->m_mapModel.m_Tree,
              &search);
      search.elem.m_arrTxt.__vftable = (CCopyableUtlVector<ModelPoseDebugInfo::InfoText>_vtbl *)&CCopyableUtlVector<ModelPoseDebugInfo::InfoText>::`vftable';
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&search.elem.m_arrTxt.CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >);
      if ( (_WORD)v13 != 0xFFFF )
      {
        m_pMemory = this->m_mapModel.m_Tree.m_Elements.m_pMemory;
        m_iEntNum = m_pMemory[v13].m_Data.elem.m_iEntNum;
        mpi = &m_pMemory[v13].m_Data.elem;
        if ( CPoseDebuggerImpl::IsModelShown(this, iEntNum: m_iEntNum) )
        {
          pMpiOld = nullptr;
          v16 = CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Find(
                  this: &this->m_mapModelOld,
                  key: (const CStudioHdr **)&pStudioHdr);
          if ( v16 != 0xFFFF )
            pMpiOld = &this->m_mapModelOld.m_Tree.m_Elements.m_pMemory[v16].m_Data.elem;
          v17 = sequence;
          v18 = CStudioHdr::pSeqdesc(this: v12, iSequence: SLODWORD(sequence));
          if ( v12->m_pVModel != nullptr )
            NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: v12);
          else
            NumSeq_Internal = v12->m_pStudioHdr->numlocalseq;
          if ( SLODWORD(v17) >= NumSeq_Internal )
          {
            v20 = CStudioHdr::pSeqdesc(this: v12, iSequence: 0);
            mstudioseqdesc_t::operator=(this: v18, __that: v20);
          }
          memset(dst: (int)&txt, value: nullptr, count: sizeof(txt));
          txt.m_iActivity = v18->activity;
          V_snprintf(
            pDest: txt.m_chActivity,
            maxLen: 0x64u,
            pFormat: "%s",
            (const char *)v18 + v18->szactivitynameindex);
          V_snprintf(pDest: txt.m_chLabel, maxLen: 0x64u, pFormat: "%s", (const char *)v18 + v18->szlabelindex);
          if ( txt.m_chActivity[0] == 0 )
          {
            m_Size = mpi->m_arrTxt.m_Size;
            if ( m_Size > 0 )
            {
              v22 = &mpi->m_arrTxt.m_Memory.m_pMemory[m_Size];
              while ( 1 )
              {
                --v22;
                --m_Size;
                if ( (v22->m_uiFlags & 1) != 0 && v22->m_chActivity[0] != 0 )
                  break;
                if ( m_Size <= 0 )
                  goto LABEL_21;
              }
              V_snprintf(pDest: txt.m_chActivity, maxLen: 0x64u, pFormat: "%s", v22->m_chActivity);
            }
          }
LABEL_21:
          if ( pMpiOld != nullptr && (v23 = ModelPoseDebugInfo::LookupInfoText(this: pMpiOld, x: &txt)) != nullptr )
            m_flTimeAlive = v23->m_flTimeAlive;
          else
            m_flTimeAlive = 0.0;
          szlabelindex = v18->szlabelindex;
          szactivitynameindex = v18->szactivitynameindex;
          sequence = m_flTimeAlive;
          v38 = (float)(flWeight * 100.0);
          v27 = mstudioseqdesc_t::anim(this: v18, x: 0, y: 0);
          numframes = CStudioHdr::pAnimdesc(this: pStudioHdr, i: v27)->numframes;
          v28 = mstudioseqdesc_t::anim(this: v18, x: 0, y: 0);
          v29 = CStudioHdr::pAnimdesc(this: pStudioHdr, i: v28);
          V_snprintf(
            pDest: txt.m_chTextLines[0],
            maxLen: 0x100u,
            pFormat: "%-*s  %-*s  %*.2f  %*.1f/%-*d  %*.0f%% ",
            35,
            (const char *)v18 + szactivitynameindex,
            35,
            (const char *)v18 + szlabelindex,
            7,
            sequence,
            5,
            (float)((float)(v29->numframes - 1) * cycle),
            3,
            numframes,
            6,
            v38);
          v30 = 1;
          if ( v18->numiklocks != 0 )
          {
            V_snprintf(pDest: chBuffer, maxLen: 0x100u, pFormat: "iklocks : %-2d : ", v18->numiklocks);
            v31 = 0;
            if ( v18->numiklocks > 0 )
            {
              v32 = 0;
              do
              {
                v33 = (char *)pStudioHdr->m_pStudioHdr
                    + 16 * *(int *)((char *)&v18->baseptr + v32 + v18->iklockindex)
                    + pStudioHdr->m_pStudioHdr->ikchainindex;
                sequence = COERCE_FLOAT(&chBuffer[1]);
                v34 = &chBuffer[strlen(chBuffer) + 1];
                V_snprintf(
                  pDest: &chBuffer[(_DWORD)&v34[-LODWORD(sequence)]],
                  maxLen: 256 - (_DWORD)&v34[-LODWORD(sequence)],
                  pFormat: "%s ",
                  &v33[*(_DWORD *)v33]);
                ++v31;
                v32 += 32;
              }
              while ( v31 < v18->numiklocks );
            }
            V_snprintf(pDest: txt.m_chTextLines[1], maxLen: 0x100u, pFormat: "%-*s", 60, chBuffer);
            v30 = 2;
          }
          numikrules = v18->numikrules;
          if ( numikrules != 0 )
          {
            V_snprintf(pDest: chBuffer, maxLen: 0x100u, pFormat: "ikrules : %-2d", numikrules);
            V_snprintf(pDest: txt.m_chTextLines[v30], maxLen: 0x100u, pFormat: "%-*s", 60, chBuffer);
          }
          v36 = mpi;
          ModelPoseDebugInfo::AddInfoText(this: mpi, x: &txt, pOld: pMpiOld);
          ModelPoseDebugInfo::PrintPendingInfoText(this: v36, rnPosPrint: &v42->m_nPosPrint);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014F9D0
// Name: public: class CCopyableUtlVector<struct ModelPoseDebugInfo::InfoText> __near & CCopyableUtlVector<struct ModelPoseDebugInfo::InfoText>::operator=(class CCopyableUtlVector<struct ModelPoseDebugInfo::InfoText> const __near &)
// Source: json
//------------------------------------------------------------------------------
CCopyableUtlVector<ModelPoseDebugInfo::InfoText> *__thiscall CCopyableUtlVector<ModelPoseDebugInfo::InfoText>::operator=(
        CCopyableUtlVector<ModelPoseDebugInfo::InfoText> *this,
        const CCopyableUtlVector<ModelPoseDebugInfo::InfoText> *__that)
{
  int m_Size; // esi
  CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> > *v4; // ebx
  int v5; // eax
  int i; // edx
  ModelPoseDebugInfo::InfoText *v7; // esi
  ModelPoseDebugInfo::InfoText *v8; // edi
  CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> > *__thata; // [esp+18h] [ebp+8h]

  if ( __that != nullptr )
    __thata = &__that->CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >;
  else
    __thata = nullptr;
  m_Size = __thata->m_Size;
  v4 = &this->CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >;
  this->m_Size = 0;
  CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int>>::InsertMultipleBefore(
    this: &this->CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >,
    elem: 0,
    num: m_Size);
  if ( m_Size <= 0 )
    return this;
  v5 = 0;
  for ( i = m_Size; i != 0; --i )
  {
    v7 = &__thata->m_Memory.m_pMemory[v5];
    v8 = &v4->m_Memory.m_pMemory[v5++];
    qmemcpy(v8, v7, sizeof(ModelPoseDebugInfo::InfoText));
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014FC30
// Name: public: CPoseDebuggerImpl::CPoseDebuggerImpl(void)
// Source: json
//------------------------------------------------------------------------------
CPoseDebuggerImpl *__thiscall CPoseDebuggerImpl::CPoseDebuggerImpl(CPoseDebuggerImpl *this)
{
  UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short> *v3; // eax

  this->__vftable = (CPoseDebuggerImpl_vtbl *)&CPoseDebuggerImpl::`vftable';
  this->m_mapModel.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const CStudioHdr *const *, const CStudioHdr *const *))CDefOps<C_BaseEntity *>::LessFunc;
  this->m_mapModel.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_mapModel.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_mapModel.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_mapModel.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_mapModel.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_mapModel.m_Tree.m_FirstFree = -1;
  this->m_mapModel.m_Tree.m_pElements = m_pMemory;
  this->m_mapModelOld.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const CStudioHdr *const *, const CStudioHdr *const *))CDefOps<C_BaseEntity *>::LessFunc;
  this->m_mapModelOld.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_mapModelOld.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_mapModelOld.m_Tree.m_Elements.m_nGrowSize = 0;
  v3 = this->m_mapModelOld.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_mapModelOld.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_mapModelOld.m_Tree.m_FirstFree = -1;
  this->m_mapModelOld.m_Tree.m_pElements = v3;
  this->m_nPosPrint = 0;
  if ( this != (CPoseDebuggerImpl *)-64 )
    memset(dst: (int)&this->m_uiMaskShowModels, value: nullptr, count: sizeof(this->m_uiMaskShowModels));
  this->m_pLastModel = nullptr;
  if ( this != (CPoseDebuggerImpl *)-64 )
    memset(dst: (int)&this->m_uiMaskShowModels, value: (unsigned __int8 *)0xFF, count: sizeof(this->m_uiMaskShowModels));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014FD80
// Name: public: virtual void CPoseDebuggerImpl::StartBlending(class IClientNetworkable __near *,class CStudioHdr const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPoseDebuggerImpl::StartBlending(
        CPoseDebuggerImpl *this,
        IClientNetworkable *pEntity,
        const CStudioHdr *pStudioHdr)
{
  const CStudioHdr *m_pLastModel; // eax
  char *name; // ebx
  int v6; // edi
  ModelPoseDebugInfo *p_elem; // edi
  unsigned __int16 v8; // ax
  ModelPoseDebugInfo *v9; // edi
  const CStudioHdr *v10; // eax
  const studiohdr_t *m_pStudioHdr; // edi
  int v12; // eax
  unsigned __int16 i; // ax
  int m_nPosPrint; // edx
  int studiohdr2index; // eax
  int v16; // ecx
  char *v17; // eax
  int v18; // ecx
  ModelPoseDebugInfo *v19; // [esp-Ch] [ebp-50h]
  CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t search; // [esp+4h] [ebp-40h] BYREF
  con_nprint_s nxPrn; // [esp+28h] [ebp-1Ch] BYREF
  const studiohdr_t *pRMdl; // [esp+40h] [ebp-4h]
  int iEntNum; // [esp+4Ch] [ebp+8h]

  if ( (unsigned __int8)_ThreadInMainThread(a1: this) != 0 )
  {
    m_pLastModel = this->m_pLastModel;
    name = nullptr;
    if ( pStudioHdr != m_pLastModel && m_pLastModel != nullptr )
    {
      search.key = this->m_pLastModel;
      search.elem.m_iEntNum = 0;
      search.elem.m_iCurrentText = 0;
      memset(
        &search.elem.m_arrTxt.CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >,
        0,
        sizeof(search.elem.m_arrTxt.CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >));
      search.elem.m_arrTxt.__vftable = (CCopyableUtlVector<ModelPoseDebugInfo::InfoText>_vtbl *)&CCopyableUtlVector<ModelPoseDebugInfo::InfoText>::`vftable';
      v6 = CUtlRBTree<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short,CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: &this->m_mapModel.m_Tree,
             &search);
      search.elem.m_arrTxt.__vftable = (CCopyableUtlVector<ModelPoseDebugInfo::InfoText>_vtbl *)&CCopyableUtlVector<ModelPoseDebugInfo::InfoText>::`vftable';
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&search.elem.m_arrTxt.CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >);
      if ( (_WORD)v6 != 0xFFFF )
      {
        pRMdl = (const studiohdr_t *)&this->m_mapModel.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
        p_elem = nullptr;
        v8 = CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Find(
               this: &this->m_mapModelOld,
               key: &this->m_pLastModel);
        if ( v8 != 0xFFFF )
          p_elem = &this->m_mapModelOld.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem;
        v19 = p_elem;
        v9 = (ModelPoseDebugInfo *)pRMdl;
        ModelPoseDebugInfo::AddInfoText(this: (ModelPoseDebugInfo *)pRMdl, x: nullptr, pOld: v19);
        ModelPoseDebugInfo::PrintPendingInfoText(this: v9, rnPosPrint: &this->m_nPosPrint);
      }
    }
    v10 = pStudioHdr;
    this->m_pLastModel = pStudioHdr;
    m_pStudioHdr = v10->m_pStudioHdr;
    if ( v10->m_pStudioHdr != nullptr && m_pStudioHdr->numincludemodels != 0 )
    {
      v12 = pEntity->entindex(this: pEntity);
      iEntNum = v12;
      if ( (unsigned int)v12 <= 0x7FF && ((1 << (v12 & 0x1F)) & this->m_uiMaskShowModels.m_Ints[v12 >> 5]) != 0 )
      {
        if ( CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Find(
               this: &this->m_mapModel,
               key: &pStudioHdr) == 0xFFFF )
        {
          this->m_nPosPrint += 3;
        }
        else
        {
          this->m_nPosPrint = 9;
          CUtlRBTree<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short,CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_mapModelOld.m_Tree);
          CUtlRBTree<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short,CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::Swap(
            this: &this->m_mapModelOld.m_Tree,
            that: &this->m_mapModel.m_Tree);
          for ( i = CUtlRBTree<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short,CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_mapModelOld.m_Tree);
                i != 0xFFFF;
                i = CUtlRBTree<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short,CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                      this: &this->m_mapModelOld.m_Tree,
                      i) )
          {
            this->m_mapModelOld.m_Tree.m_Elements.m_pMemory[i].m_Data.elem.m_iCurrentText = 0;
          }
        }
        search.elem.m_iCurrentText = 0;
        memset(
          &search.elem.m_arrTxt.CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >,
          0,
          sizeof(search.elem.m_arrTxt.CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >));
        search.elem.m_arrTxt.__vftable = (CCopyableUtlVector<ModelPoseDebugInfo::InfoText>_vtbl *)&CCopyableUtlVector<ModelPoseDebugInfo::InfoText>::`vftable';
        search.elem.m_iEntNum = iEntNum;
        CUtlMap<CStudioHdr const *,ModelPoseDebugInfo,unsigned short>::Insert(
          this: &this->m_mapModel,
          a2: (const char *)m_pStudioHdr,
          key: &pStudioHdr,
          insert: (int)&search.elem);
        m_nPosPrint = this->m_nPosPrint;
        nxPrn.time_to_live = -1.0;
        *(_DWORD *)&nxPrn.fixed_width_font = 0;
        nxPrn.index = m_nPosPrint;
        nxPrn.color[0] = 0.89999998;
        nxPrn.color[1] = 1.0;
        nxPrn.color[2] = 0.89999998;
        studiohdr2index = m_pStudioHdr->studiohdr2index;
        if ( studiohdr2index != 0
          && (v16 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 8],
              v17 = (char *)m_pStudioHdr + studiohdr2index,
              v16 != 0)
          && &v17[v16] != nullptr )
        {
          v18 = *((_DWORD *)v17 + 5);
          if ( v18 != 0 )
            name = &v17[v18];
        }
        else
        {
          name = m_pStudioHdr->name;
        }
        engine->Con_NXPrintf(this: engine, a2: &nxPrn, a3: "[ %2d  ]    Model: %s", iEntNum, name);
        this->m_nPosPrint += 3;
        search.elem.m_arrTxt.__vftable = (CCopyableUtlVector<ModelPoseDebugInfo::InfoText>_vtbl *)&CCopyableUtlVector<ModelPoseDebugInfo::InfoText>::`vftable';
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&search.elem.m_arrTxt.CUtlVector<ModelPoseDebugInfo::InfoText,CUtlMemory<ModelPoseDebugInfo::InfoText,int> >);
      }
    }
  }
  else if ( _executeCount_1 < 1 )
  {
    ++_executeCount_1;
  }
}
