// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/lpreview_thread.cpp
// Functions: 99
// ============================================================

#include "hammer\lpreview_thread.h"

//------------------------------------------------------------------------------
// Address: 0x10017FC0
// Name: public: CUtlBlockVector<class CUtlReference<class CMapClass>>::~CUtlBlockVector<class CUtlReference<class CMapClass>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBlockVector<CUtlReference<CMapClass>>::~CUtlBlockVector<CUtlReference<CMapClass>>(
        CUtlBlockVector<CUtlReference<CMapClass> > *this)
{
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this);
}

//------------------------------------------------------------------------------
// Address: 0x10018720
// Name: protected: void CUtlBlockMemory<class CUtlReference<class CMapEntity>,int>::ChangeSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBlockMemory<CUtlReference<CMapEntity>,int>::ChangeSize(
        CUtlBlockMemory<CUtlReference<CMapClass>,int> *this,
        int nBlocks)
{
  int m_nBlocks; // ebx
  int v4; // edi
  CUtlReference<CMapClass> **v5; // eax
  int v6; // edi
  unsigned int v7; // ebx
  const char *v8; // [esp+0h] [ebp-Ch]

  m_nBlocks = this->m_nBlocks;
  v4 = nBlocks;
  for ( this->m_nBlocks = nBlocks; v4 < m_nBlocks; ++v4 )
    free(pMem: this->m_pMemory[v4]);
  if ( this->m_pMemory != nullptr )
    v5 = (CUtlReference<CMapClass> **)_realloc_crt(ptr: this->m_pMemory, size: 4 * this->m_nBlocks);
  else
    v5 = (CUtlReference<CMapClass> **)MemAlloc_Alloc(nSize: 4 * this->m_nBlocks);
  this->m_pMemory = v5;
  if ( v5 == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_105D7D84, a2: v8);
  v6 = m_nBlocks;
  if ( m_nBlocks < this->m_nBlocks )
  {
    v7 = 4 * (3 * ((32 * *((_DWORD *)this + 2)) >> 5) + 3);
    do
      this->m_pMemory[v6++] = (CUtlReference<CMapClass> *)MemAlloc_Alloc(nSize: v7);
    while ( v6 < this->m_nBlocks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018AF0
// Name: public: void CUtlBlockMemory<class CUtlReference<class CMapEntity>,int>::Init(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
        CUtlBlockMemory<CUtlReference<CMapClass>,int> *this,
        int nGrowSize,
        int nInitSize)
{
  int i; // edi
  int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  int v8; // ecx
  unsigned int v9; // eax
  CUtlReference<CMapClass> **m_pMemory; // [esp-8h] [ebp-Ch]

  if ( this->m_pMemory != nullptr )
  {
    for ( i = 0; i < this->m_nBlocks; ++i )
      free(pMem: this->m_pMemory[i]);
    m_pMemory = this->m_pMemory;
    this->m_nBlocks = 0;
    free(pMem: m_pMemory);
    this->m_pMemory = nullptr;
  }
  v5 = nGrowSize;
  if ( nGrowSize == 0 )
    v5 = 11;
  v6 = ((((unsigned int)(v5 - 1) >> 1) | (v5 - 1)) >> 2) | ((unsigned int)(v5 - 1) >> 1) | (v5 - 1);
  v7 = (v6 >> 4) | v6;
  v8 = ((v7 >> 8) | v7 | (((v7 >> 8) | v7) >> 16)) + 1;
  v9 = (v7 >> 8) | v7 & 0x7FFFFFF | (((v7 >> 8) | v7) >> 16);
  *((_DWORD *)this + 2) = v9;
  if ( v8 > 1 )
  {
    do
    {
      v8 >>= 1;
      v9 = ((v9 & 0xF8000000) + 0x8000000) ^ v9 & 0x7FFFFFF;
    }
    while ( v8 > 1 );
    *((_DWORD *)this + 2) = v9;
  }
  if ( nInitSize > 0 )
    CUtlBlockMemory<CUtlReference<CMapEntity>,int>::ChangeSize(
      this,
      nBlocks: this->m_nBlocks + (((32 * *((_DWORD *)this + 2)) >> 5) + nInitSize) / (((32 * *((_DWORD *)this + 2)) >> 5) + 1));
}

//------------------------------------------------------------------------------
// Address: 0x10019F30
// Name: public: CUtlBlockVector<class CUtlReference<class CMapEntity>>::~CUtlBlockVector<class CUtlReference<class CMapEntity>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBlockVector<CUtlReference<CMapEntity>>::~CUtlBlockVector<CUtlReference<CMapEntity>>(
        CUtlBlockVector<CUtlReference<CMapEntity> > *this)
{
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this);
}

//------------------------------------------------------------------------------
// Address: 0x1003E980
// Name: public: void CMessageQueue<struct MessageToLPreview>::QueueMessage(struct MessageToLPreview const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageQueue<MessageToLPreview>::QueueMessage(
        CMessageQueue<MessageToLPreview> *this,
        const MessageToLPreview *Msg)
{
  CMessageQueue<MessageToLPreview>::MsgNode *v3; // eax
  CMessageQueue<MessageToLPreview>::MsgNode *v4; // esi
  CMessageQueue<MessageToLPreview>::MsgNode *Tail; // eax

  v3 = (CMessageQueue<MessageToLPreview>::MsgNode *)operator new(nSize: 0x30u);
  if ( v3 != nullptr )
  {
    v3->Data.m_LightList.m_pHead = nullptr;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v4->Data = *Msg;
  v4->Next = nullptr;
  CThreadMutex::Lock(this: &this->QueueAccessMutex);
  Tail = this->Tail;
  if ( Tail != nullptr )
    Tail->Next = v4;
  else
    this->Head = v4;
  this->Tail = v4;
  CThreadEvent::Set(this: &this->SignalEvent);
  CThreadMutex::Unlock(this: &this->QueueAccessMutex);
}

//------------------------------------------------------------------------------
// Address: 0x1004E660
// Name: void __near * MemAlloc_AllocAlignedUnattributed(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_AllocAlignedUnattributed(unsigned int size, unsigned int align)
{
  unsigned int v2; // eax
  void *result; // eax
  unsigned int v4; // esi

  v2 = align;
  if ( ((align - 1) & align) != 0 )
    return nullptr;
  if ( align <= 4 )
    v2 = 4;
  v4 = v2 - 1;
  result = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size + v2 - 1 + 4);
  if ( result != nullptr )
  {
    *(_DWORD *)((~v4 & ((unsigned int)result + v4 + 4)) - 4) = result;
    return (void *)(~v4 & ((unsigned int)result + v4 + 4));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004E6B0
// Name: public: virtual CFunctor::~CFunctor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor::~CFunctor(CFunctor *this)
{
  this->__vftable = (CFunctor_vtbl *)&CFunctor::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1004E6F0
// Name: public: class Vector DirectionalSampler_t::NextValue(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall DirectionalSampler_t::NextValue(DirectionalSampler_t *this, Vector *result)
{
  int v3; // eax
  double Element; // st7
  double v5; // xmm0_8
  int seed; // [esp-4h] [ebp-14h]
  long double v8; // [esp+0h] [ebp-10h]
  long double v9; // [esp+0h] [ebp-10h]
  long double v10; // [esp+0h] [ebp-10h]
  long double v11; // [esp+0h] [ebp-10h]
  float zvalue; // [esp+4h] [ebp-Ch]
  float theta; // [esp+Ch] [ebp-4h]

  v3 = this->zdot.seed++;
  Element = HaltonSequenceGenerator_t::GetElement(this: &this->zdot, elem: v3);
  seed = this->vrot.seed;
  this->vrot.seed = seed + 1;
  *((float *)&v8 + 1) = Element + Element - 1.0;
  v5 = *((float *)&v8 + 1);
  theta = HaltonSequenceGenerator_t::GetElement(this: &this->vrot, elem: seed) * 6.283185307179586;
  __libm_sse2_acos(x: v8);
  *(float *)&v5 = v5;
  __libm_sse2_sin(x: v9);
  __libm_sse2_cos(x: v10);
  result->x = theta * *(float *)&v5;
  __libm_sse2_sin(x: v11);
  result->z = zvalue;
  result->y = theta * *(float *)&v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004E7A0
// Name: public: CIncrementalLightInfo::CIncrementalLightInfo(void)
// Source: json
//------------------------------------------------------------------------------
CIncrementalLightInfo *__thiscall CIncrementalLightInfo::CIncrementalLightInfo(CIncrementalLightInfo *this)
{
  memset(
    dst: (unsigned __int8 *)this->m_CalculatedContribution.m_nDataType,
    value: 0xFFu,
    count: sizeof(this->m_CalculatedContribution.m_nDataType));
  memset(
    dst: (unsigned __int8 *)this->m_CalculatedContribution.m_pSeparateDataMemory,
    value: 0,
    count: sizeof(this->m_CalculatedContribution.m_pSeparateDataMemory));
  this->m_CalculatedContribution.m_pConstantDataMemory = nullptr;
  this->m_CalculatedContribution.m_pDataMemory = nullptr;
  this->m_CalculatedContribution.m_nNumQuadsPerRow = 0;
  this->m_CalculatedContribution.m_nSlices = 0;
  this->m_CalculatedContribution.m_nRows = 0;
  this->m_CalculatedContribution.m_nPaddedColumns = 0;
  this->m_CalculatedContribution.m_nColumns = 0;
  this->m_CalculatedContribution.m_nFieldPresentMask = 0;
  this->m_CalculatedContribution.m_eThreadMode = SOATHREADMODE_NONE;
  *(_WORD *)&this->m_bCreatedIndirectLights = 0;
  this->m_nObjectID = -1;
  this->m_pNext = nullptr;
  this->m_eIncrState = INCR_STATE_NEW;
  this->m_fTotalContribution = 0.0;
  this->m_flLastContribution = 0.0;
  this->m_nNumLinesCalculated = 0;
  this->m_nMostRecentNonZeroContributionTimeStamp = 0;
  this->m_nMaxCalculatedLine = -1;
  this->m_nFirstCalculatedLine = 0x7FFFFFFF;
  memset(dst: this->m_nCalculationLevel, value: 0, count: sizeof(this->m_nCalculationLevel));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004E890
// Name: public: float CIncrementalLightInfo::PredictedContribution(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CIncrementalLightInfo::PredictedContribution(CIncrementalLightInfo *this)
{
  int m_nNumLinesCalculated; // [esp+4h] [ebp-4h]

  if ( this->m_fTotalContribution == 0.0 )
    return 0.0;
  m_nNumLinesCalculated = this->m_nNumLinesCalculated;
  if ( m_nNumLinesCalculated == 0 )
    return 0.0;
  else
    return 1.0
         / (double)m_nNumLinesCalculated
         * (double)this->m_CalculatedContribution.m_nRows
         * this->m_fTotalContribution;
}

//------------------------------------------------------------------------------
// Address: 0x1004E8E0
// Name: public: void CMessageQueue<struct MessageFromLPreview>::WaitMessage(struct MessageFromLPreview __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageQueue<MessageFromLPreview>::WaitMessage(
        CMessageQueue<MessageFromLPreview> *this,
        MessageFromLPreview *pMsg)
{
  CMessageQueue<MessageFromLPreview>::MsgNode *Head; // edi
  CMessageQueue<MessageFromLPreview>::MsgNode *Next; // eax

  while ( 1 )
  {
    while ( this->Head == nullptr )
      CThreadEvent::Wait(this: &this->SignalEvent, a2: 0xFFFFFFFF);
    CThreadMutex::Lock(this: &this->QueueAccessMutex);
    if ( this->Head != nullptr )
      break;
    CThreadMutex::Unlock(this: &this->QueueAccessMutex);
  }
  *pMsg = this->Head->Data;
  Head = this->Head;
  Next = Head->Next;
  this->Head = Head->Next;
  if ( Next == nullptr )
    this->Tail = nullptr;
  CThreadMutex::Unlock(this: &this->QueueAccessMutex);
  operator delete(p: Head);
}

//------------------------------------------------------------------------------
// Address: 0x1004E960
// Name: protected: void CUtlBlockMemory<struct CacheOptimizedTriangle,int>::ChangeSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBlockMemory<CacheOptimizedTriangle,int>::ChangeSize(
        CUtlBlockMemory<CacheOptimizedTriangle,int> *this,
        int nBlocks)
{
  int m_nBlocks; // ebx
  int v4; // edi
  CacheOptimizedTriangle **v5; // eax
  int v6; // edi
  unsigned int v7; // ebx
  const char *v8; // [esp+0h] [ebp-Ch]

  m_nBlocks = this->m_nBlocks;
  v4 = nBlocks;
  for ( this->m_nBlocks = nBlocks; v4 < m_nBlocks; ++v4 )
    free(pMem: this->m_pMemory[v4]);
  if ( this->m_pMemory != nullptr )
    v5 = (CacheOptimizedTriangle **)_realloc_crt(ptr: this->m_pMemory, size: 4 * this->m_nBlocks);
  else
    v5 = (CacheOptimizedTriangle **)MemAlloc_Alloc(nSize: 4 * this->m_nBlocks);
  this->m_pMemory = v5;
  if ( v5 == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_105D7D84, a2: v8);
  v6 = m_nBlocks;
  if ( m_nBlocks < this->m_nBlocks )
  {
    v7 = 16 * (3 * ((32 * *((_DWORD *)this + 2)) >> 5) + 3);
    do
      this->m_pMemory[v6++] = (CacheOptimizedTriangle *)MemAlloc_Alloc(nSize: v7);
    while ( v6 < this->m_nBlocks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004EA00
// Name: public: int CJob::Abort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::Abort(CJob *this, BOOL bDiscard)
{
  int result; // eax
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  bool v6; // bl
  int v7; // eax
  int m_status; // [esp+1Ch] [ebp+8h]

  result = this->m_status;
  if ( result == 1 || result == 2 || result == 4 )
  {
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    this->AddRef(this);
    switch ( this->m_status )
    {
      case 1:
      case 4:
        v6 = bDiscard;
        v7 = this->DoAbort(this, a2: bDiscard);
        this->m_status = v7;
        m_status = v7;
        if ( v6 )
          this->DoCleanup(this);
        CThreadEvent::Set(this: &this->m_CompleteEvent);
        break;
      default:
        m_status = this->m_status;
        break;
    }
    this->Release(this);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return m_status;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004EB00
// Name: public: CLightingPreviewThread::CLightingPreviewThread(void)
// Source: json
//------------------------------------------------------------------------------
CLightingPreviewThread *__thiscall CLightingPreviewThread::CLightingPreviewThread(CLightingPreviewThread *this)
{
  this->m_LightList.m_pHead = nullptr;
  memset(dst: (unsigned __int8 *)this->m_GBuffer.m_nDataType, value: 0xFFu, count: sizeof(this->m_GBuffer.m_nDataType));
  memset(
    dst: (unsigned __int8 *)this->m_GBuffer.m_pSeparateDataMemory,
    value: 0,
    count: sizeof(this->m_GBuffer.m_pSeparateDataMemory));
  this->m_GBuffer.m_pConstantDataMemory = nullptr;
  this->m_GBuffer.m_pDataMemory = nullptr;
  this->m_GBuffer.m_nNumQuadsPerRow = 0;
  this->m_GBuffer.m_nSlices = 0;
  this->m_GBuffer.m_nRows = 0;
  this->m_GBuffer.m_nPaddedColumns = 0;
  this->m_GBuffer.m_nColumns = 0;
  this->m_GBuffer.m_nFieldPresentMask = 0;
  this->m_GBuffer.m_eThreadMode = SOATHREADMODE_NONE;
  memset(
    dst: (unsigned __int8 *)this->m_GBufferLowRes.m_nDataType,
    value: 0xFFu,
    count: sizeof(this->m_GBufferLowRes.m_nDataType));
  memset(
    dst: (unsigned __int8 *)this->m_GBufferLowRes.m_pSeparateDataMemory,
    value: 0,
    count: sizeof(this->m_GBufferLowRes.m_pSeparateDataMemory));
  this->m_GBufferLowRes.m_pConstantDataMemory = nullptr;
  this->m_GBufferLowRes.m_pDataMemory = nullptr;
  this->m_GBufferLowRes.m_nNumQuadsPerRow = 0;
  this->m_GBufferLowRes.m_nSlices = 0;
  this->m_GBufferLowRes.m_nRows = 0;
  this->m_GBufferLowRes.m_nPaddedColumns = 0;
  this->m_GBufferLowRes.m_nColumns = 0;
  this->m_GBufferLowRes.m_nFieldPresentMask = 0;
  this->m_GBufferLowRes.m_eThreadMode = SOATHREADMODE_NONE;
  this->m_nBitmapGenerationCounter = -1;
  this->m_pRtEnv = nullptr;
  this->m_bAccStructureBuilt = false;
  this->m_pIncrementalLightInfoList = nullptr;
  this->m_fLastSendTime = -1000000.0;
  this->m_bResultChangedSinceLastSend = false;
  this->m_nContributionCounter = 1000000;
  this->m_bFirstWork = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004EC30
// Name: public: void CLightingPreviewThread::DiscardResults(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CLightingPreviewThread::DiscardResults(CLightingPreviewThread *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  CIncrementalLightInfo *i; // esi
  bool v5; // zf
  CLightingPreviewLightDescription *m_pHead; // eax
  CIncrementalLightInfo *m_pIncrementalInfo; // ecx
  float v8; // xmm0_4
  double v9; // st7
  int v12; // [esp-18h] [ebp-24h]
  int v13; // [esp-14h] [ebp-20h]
  float v14; // [esp-10h] [ebp-1Ch]

  for ( i = this->m_pIncrementalLightInfoList; i != nullptr; i = i->m_pNext )
  {
    i->m_bDisabled = false;
    CSOAContainer::Purge(this: &i->m_CalculatedContribution);
    memset(dst: i->m_nCalculationLevel, value: 0, count: sizeof(i->m_nCalculationLevel));
    v5 = i->m_eIncrState == INCR_STATE_NEW;
    i->m_nMaxCalculatedLine = -1;
    i->m_nFirstCalculatedLine = 0x7FFFFFFF;
    if ( !v5 )
      i->m_eIncrState = INCR_STATE_NO_RESULTS;
    i->m_nNumLinesCalculated = 0;
  }
  m_pHead = this->m_LightList.m_pHead;
  ++this->m_nContributionCounter;
  for ( ; m_pHead != nullptr; m_pHead = m_pHead->m_pNext )
  {
    m_pIncrementalInfo = m_pHead->m_pIncrementalInfo;
    if ( m_pHead->m_Type == MATERIAL_LIGHT_DIRECTIONAL )
    {
      m_pIncrementalInfo->m_fDistanceToEye = 0.0;
    }
    else
    {
      v8 = this->m_LastEyePosition.x - m_pHead->m_Position.x;
      v14 = fsqrt(
              (float)((float)((float)(this->m_LastEyePosition.y - m_pHead->m_Position.y)
                            * (float)(this->m_LastEyePosition.y - m_pHead->m_Position.y))
                    + (float)((float)(this->m_LastEyePosition.z - m_pHead->m_Position.z)
                            * (float)(this->m_LastEyePosition.z - m_pHead->m_Position.z)))
            + (float)(v8 * v8));
      m_pIncrementalInfo->m_fDistanceToEye = v14;
    }
  }
  this->m_bResultChangedSinceLastSend = true;
  v9 = _Plat_FloatTime(a1: a2, a2: a3, a3: v12, a4: v13, a5: LODWORD(v14));
  this->m_bFirstWork = true;
  this->m_fLastSendTime = v9 - 12.0;
}

//------------------------------------------------------------------------------
// Address: 0x1004ED60
// Name: public: class Vector CLightingPreviewThread::EstimatedUnshotAmbient(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CLightingPreviewThread::EstimatedUnshotAmbient(CLightingPreviewThread *this, Vector *result)
{
  CLightingPreviewLightDescription *i; // edx
  CIncrementalLightInfo *m_pIncrementalInfo; // ecx
  float m_fTotalContribution; // xmm0_4
  int m_nNumLinesCalculated; // eax
  float v6; // xmm0_4

  result->x = 0.000099999997;
  result->y = 0.000099999997;
  result->z = 0.000099999997;
  for ( i = this->m_LightList.m_pHead; i != nullptr; i = i->m_pNext )
  {
    m_pIncrementalInfo = i->m_pIncrementalInfo;
    if ( m_pIncrementalInfo != nullptr && m_pIncrementalInfo->m_eIncrState == INCR_STATE_HAVE_FULL_RESULTS
      || m_pIncrementalInfo->m_eIncrState == INCR_STATE_PARTIAL_RESULTS )
    {
      m_fTotalContribution = m_pIncrementalInfo->m_fTotalContribution;
      if ( m_fTotalContribution == 0.0 || (m_nNumLinesCalculated = m_pIncrementalInfo->m_nNumLinesCalculated) == 0 )
        v6 = 0.0;
      else
        v6 = 1.0
           / (double)m_nNumLinesCalculated
           * (double)m_pIncrementalInfo->m_CalculatedContribution.m_nRows
           * m_fTotalContribution;
      result->x = (float)(i->m_Color.x * v6) + result->x;
      result->y = (float)(i->m_Color.y * v6) + result->y;
      result->z = (float)(i->m_Color.z * v6) + result->z;
    }
  }
  VectorNormalize(vec: result);
  result->x = result->x * 0.050000001;
  result->y = result->y * 0.050000001;
  result->z = result->z * 0.050000001;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004EE80
// Name: public: bool CIncrementalLightInfo::IsLowerPriorityThan(class CLightingPreviewThread __near *,class CIncrementalLightInfo const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CIncrementalLightInfo::IsLowerPriorityThan(
        CIncrementalLightInfo *this,
        CLightingPreviewThread *pLPV,
        CIncrementalLightInfo *other)
{
  IncrementalLightState m_eIncrState; // ebx
  CLightingPreviewLightDescription *m_pLight; // eax
  float x; // xmm0_4
  Vector *p_m_Position; // eax
  float y; // xmm0_4
  float z; // xmm0_4
  float v10; // xmm1_4
  IncrementalLightState v11; // edi
  CLightingPreviewLightDescription *v12; // eax
  float v13; // xmm0_4
  Vector *v14; // eax
  float v15; // xmm0_4
  float v16; // xmm0_4
  bool v17; // al
  bool result; // al
  float v19; // xmm1_4
  int m_nNumLinesCalculated; // edx
  int v21; // edi
  int v22; // ebx
  int v23; // eax
  float v24; // xmm2_4
  float m_fTotalContribution; // xmm0_4
  int nMinLines; // [esp+14h] [ebp+8h]
  float nMinLinesa; // [esp+14h] [ebp+8h]
  char nMinLines_3; // [esp+17h] [ebp+Bh]

  m_eIncrState = this->m_eIncrState;
  if ( m_eIncrState != INCR_STATE_NEW
    || (m_pLight = this->m_pLight,
        x = m_pLight->m_Position.x,
        p_m_Position = &m_pLight->m_Position,
        x < pLPV->m_MinViewCoords.x)
    || pLPV->m_MaxViewCoords.x < x
    || (y = p_m_Position->y) < pLPV->m_MinViewCoords.y
    || pLPV->m_MaxViewCoords.y < y
    || (z = p_m_Position->z) < pLPV->m_MinViewCoords.z
    || (v10 = pLPV->m_MaxViewCoords.z, nMinLines_3 = 1, v10 < z) )
  {
    nMinLines_3 = 0;
  }
  v11 = other->m_eIncrState;
  v17 = false;
  if ( v11 == INCR_STATE_NEW )
  {
    v12 = other->m_pLight;
    v13 = v12->m_Position.x;
    v14 = &v12->m_Position;
    if ( v13 >= pLPV->m_MinViewCoords.x && pLPV->m_MaxViewCoords.x >= v13 )
    {
      v15 = v14->y;
      if ( v15 >= pLPV->m_MinViewCoords.y && pLPV->m_MaxViewCoords.y >= v15 )
      {
        v16 = v14->z;
        if ( v16 >= pLPV->m_MinViewCoords.z && pLPV->m_MaxViewCoords.z >= v16 )
          v17 = true;
      }
    }
  }
  if ( nMinLines_3 != 0 )
  {
    if ( !v17 )
      return false;
  }
  else if ( v17 )
  {
    return true;
  }
  switch ( m_eIncrState + 16 * v11 )
  {
    case 0:
      if ( this->m_fTotalContribution != 0.0 || other->m_fTotalContribution != 0.0 )
        goto LABEL_43;
      return other->m_nMostRecentNonZeroContributionTimeStamp > this->m_nMostRecentNonZeroContributionTimeStamp;
    case 1:
      m_fTotalContribution = other->m_fTotalContribution;
      if ( m_fTotalContribution != 0.0 )
        return true;
      if ( this->m_fTotalContribution != 0.0 || m_fTotalContribution != 0.0 )
        goto LABEL_43;
      return other->m_nMostRecentNonZeroContributionTimeStamp > this->m_nMostRecentNonZeroContributionTimeStamp;
    case 2:
      if ( other->m_fTotalContribution <= 0.0 )
        goto LABEL_25;
      return true;
    case 16:
      if ( this->m_fTotalContribution != 0.0 )
        return false;
      if ( other->m_fTotalContribution != 0.0 )
        goto LABEL_43;
      return other->m_nMostRecentNonZeroContributionTimeStamp > this->m_nMostRecentNonZeroContributionTimeStamp;
    case 17:
      v19 = this->m_fTotalContribution;
      if ( v19 == 0.0
        && other->m_fTotalContribution == 0.0
        && other->m_nMostRecentNonZeroContributionTimeStamp > this->m_nMostRecentNonZeroContributionTimeStamp )
      {
        return true;
      }
      m_nNumLinesCalculated = this->m_nNumLinesCalculated;
      v21 = other->m_nNumLinesCalculated;
      v22 = m_nNumLinesCalculated;
      if ( m_nNumLinesCalculated > v21 || (v22 = other->m_nNumLinesCalculated, m_nNumLinesCalculated >= v21) )
      {
        v23 = other->m_nNumLinesCalculated;
        nMinLines = v23;
      }
      else
      {
        v23 = this->m_nNumLinesCalculated;
        nMinLines = v23;
      }
      if ( v22 <= 16 * v23 )
      {
        v24 = other->m_fTotalContribution;
        if ( v24 == 0.0 && v19 > 0.0 )
          return false;
        if ( v19 == 0.0 && v24 > 0.0 )
          return true;
      }
      if ( v22 > 2 * nMinLines )
      {
        result = m_nNumLinesCalculated > v21;
      }
      else
      {
LABEL_43:
        nMinLinesa = CIncrementalLightInfo::PredictedContribution(this);
        if ( CIncrementalLightInfo::PredictedContribution(this: other) <= nMinLinesa )
LABEL_25:
          result = false;
        else
          result = true;
      }
      break;
    case 32:
      if ( this->m_fTotalContribution == 0.0 )
        return true;
      goto LABEL_25;
    case 33:
      return true;
    case 34:
      if ( this->m_fDistanceToEye <= other->m_fDistanceToEye )
        goto LABEL_25;
      return true;
    default:
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004F200
// Name: public: void CLightingPreviewThread::CalculateSceneBounds(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CLightingPreviewThread::CalculateSceneBounds(CLightingPreviewThread *this@<ecx>, int a2@<ebp>)
{
  __m128 v2; // xmm1
  __m128 v3; // xmm3
  __m128 v4; // xmm4
  __m128 v5; // xmm5
  int v6; // esi
  __m128 v7; // xmm6
  int m_nNumQuadsPerRow; // edi
  unsigned __int8 *v9; // eax
  int v10; // edx
  __m128 v11; // xmm0
  __m128 v12; // xmm2
  __m128 v13; // xmm7
  int v14; // eax
  float z; // xmm1_4
  float y; // xmm3_4
  float x; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  _BYTE v22[104]; // [esp-Ch] [ebp-6Ch] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+60h] [ebp+0h]

  *(_DWORD *)&v22[96] = a2;
  *(_DWORD *)&v22[100] = retaddr;
  v2 = 0;
  v2.m128_f32[0] = this->m_LastEyePosition.z;
  v3 = _mm_shuffle_ps((__m128)LODWORD(this->m_LastEyePosition.x), (__m128)LODWORD(this->m_LastEyePosition.x), 0);
  v4 = _mm_shuffle_ps((__m128)LODWORD(this->m_LastEyePosition.y), (__m128)LODWORD(this->m_LastEyePosition.y), 0);
  v5 = _mm_shuffle_ps(v2, v2, 0);
  v6 = 0;
  v7 = v3;
  *(__m128 *)v22 = v3;
  *(__m128 *)&v22[16] = v4;
  *(__m128 *)&v22[32] = v5;
  *(__m128 *)&v22[48] = v3;
  *(__m128 *)&v22[64] = v4;
  *(__m128 *)&v22[80] = v5;
  if ( this->m_GBuffer.m_nRows > 0 )
  {
    m_nNumQuadsPerRow = this->m_GBuffer.m_nNumQuadsPerRow;
    do
    {
      v9 = &this->m_GBuffer.m_pAttributePtrs[0][v6 * this->m_GBuffer.m_nRowStrideInBytes[0]];
      if ( m_nNumQuadsPerRow > 0 )
      {
        v10 = m_nNumQuadsPerRow;
        do
        {
          v11 = *(__m128 *)v9;
          v3 = _mm_min_ps(*(__m128 *)v9, v3);
          v12 = *((__m128 *)v9 + 1);
          v4 = _mm_min_ps(v12, v4);
          v13 = *((__m128 *)v9 + 2);
          v9 += 48;
          --v10;
          v5 = _mm_min_ps(v13, v5);
          v7 = _mm_max_ps(v11, v7);
          *(__m128 *)&v22[64] = _mm_max_ps(v12, *(__m128 *)&v22[64]);
          *(__m128 *)&v22[80] = _mm_max_ps(v13, *(__m128 *)&v22[80]);
        }
        while ( v10 != 0 );
      }
      ++v6;
    }
    while ( v6 < this->m_GBuffer.m_nRows );
    *(__m128 *)&v22[48] = v7;
    *(__m128 *)&v22[32] = v5;
    *(__m128 *)&v22[16] = v4;
    *(__m128 *)v22 = v3;
  }
  this->m_MinViewCoords.x = *(float *)v22;
  this->m_MinViewCoords.y = *(float *)&v22[16];
  this->m_MinViewCoords.z = *(float *)&v22[32];
  this->m_MaxViewCoords.x = *(float *)&v22[48];
  this->m_MaxViewCoords.y = *(float *)&v22[64];
  this->m_MaxViewCoords.z = *(float *)&v22[80];
  v14 = 0;
  do
  {
    z = *(float *)&v22[v14 + 36];
    y = *(float *)&v22[v14 + 20];
    if ( z > this->m_MinViewCoords.z )
      z = this->m_MinViewCoords.z;
    if ( y > this->m_MinViewCoords.y )
      y = this->m_MinViewCoords.y;
    x = this->m_MinViewCoords.x;
    if ( *(float *)&v22[v14 + 4] <= x )
      x = *(float *)&v22[v14 + 4];
    v18 = *(float *)&v22[v14 + 52];
    v19 = *(float *)&v22[v14 + 68];
    this->m_MinViewCoords.x = x;
    v20 = *(float *)&v22[v14 + 84];
    this->m_MinViewCoords.y = y;
    this->m_MinViewCoords.z = z;
    if ( this->m_MaxViewCoords.z > v20 )
      v20 = this->m_MaxViewCoords.z;
    if ( this->m_MaxViewCoords.y > v19 )
      v19 = this->m_MaxViewCoords.y;
    v21 = this->m_MaxViewCoords.x;
    if ( v21 <= v18 )
      v21 = v18;
    v14 += 4;
    this->m_MaxViewCoords.x = v21;
    this->m_MaxViewCoords.y = v19;
    this->m_MaxViewCoords.z = v20;
  }
  while ( v14 < 12 );
}

//------------------------------------------------------------------------------
// Address: 0x1004F410
// Name: public: void CLightingPreviewThread::UpdateIncrementalForNewLightList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightingPreviewThread::UpdateIncrementalForNewLightList(CLightingPreviewThread *this)
{
  CLightingPreviewLightDescription *m_pHead; // edi
  CIncrementalLightInfo *m_pIncrementalLightInfoList; // eax
  unsigned __int8 *v3; // esi
  int m_nObjectID; // eax
  CLightingPreviewThread *i; // [esp+Ch] [ebp-10h]

  m_pHead = this->m_LightList.m_pHead;
  for ( i = this; m_pHead != nullptr; m_pHead = m_pHead->m_pNext )
  {
    m_pIncrementalLightInfoList = this->m_pIncrementalLightInfoList;
    if ( m_pIncrementalLightInfoList != nullptr )
    {
      while ( m_pIncrementalLightInfoList->m_nObjectID != m_pHead->m_nObjectID )
      {
        m_pIncrementalLightInfoList = m_pIncrementalLightInfoList->m_pNext;
        if ( m_pIncrementalLightInfoList == nullptr )
          goto LABEL_7;
      }
      m_pHead->m_pIncrementalInfo = m_pIncrementalLightInfoList;
      m_pIncrementalLightInfoList->m_pLight = m_pHead;
    }
LABEL_7:
    if ( m_pHead->m_pIncrementalInfo == nullptr )
    {
      v3 = (unsigned __int8 *)operator new(nSize: 0x758u);
      if ( v3 != nullptr )
      {
        memset(dst: v3 + 172, value: 0xFFu, count: 0x80u);
        memset(dst: v3 + 692, value: 0, count: 0x80u);
        *((_DWORD *)v3 + 172) = 0;
        *((_DWORD *)v3 + 10) = 0;
        *((_DWORD *)v3 + 9) = 0;
        *((_DWORD *)v3 + 7) = 0;
        *((_DWORD *)v3 + 6) = 0;
        *((_DWORD *)v3 + 8) = 0;
        *((_DWORD *)v3 + 5) = 0;
        *((_DWORD *)v3 + 171) = 0;
        *((_DWORD *)v3 + 205) = 0;
        *((_WORD *)v3 + 938) = 0;
        *((_DWORD *)v3 + 2) = -1;
        *(_DWORD *)v3 = 0;
        *((_DWORD *)v3 + 4) = 2;
        *((_DWORD *)v3 + 206) = 0;
        *((_DWORD *)v3 + 207) = 0;
        *((_DWORD *)v3 + 3) = 0;
        *((_DWORD *)v3 + 210) = 0;
        *((_DWORD *)v3 + 467) = -1;
        *((_DWORD *)v3 + 468) = 0x7FFFFFFF;
        memset(dst: v3 + 844, value: 0, count: 0x400u);
      }
      else
      {
        v3 = nullptr;
      }
      m_nObjectID = m_pHead->m_nObjectID;
      m_pHead->m_pIncrementalInfo = (CIncrementalLightInfo *)v3;
      *((_DWORD *)v3 + 2) = m_nObjectID;
      m_pHead->m_pIncrementalInfo->m_pLight = m_pHead;
      m_pHead->m_pIncrementalInfo->m_pNext = i->m_pIncrementalLightInfoList;
      i->m_pIncrementalLightInfoList = m_pHead->m_pIncrementalInfo;
      this = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F590
// Name: public: bool CLightingPreviewThread::AnyUsefulWorkToDo(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLightingPreviewThread::AnyUsefulWorkToDo(CLightingPreviewThread *this)
{
  CLightingPreviewLightDescription *m_pHead; // ecx
  CIncrementalLightInfo *m_pIncrementalInfo; // eax

  if ( this->m_GBuffer.m_nRows == 0 )
    return 0;
  m_pHead = this->m_LightList.m_pHead;
  if ( m_pHead == nullptr )
    return 0;
  while ( 1 )
  {
    m_pIncrementalInfo = m_pHead->m_pIncrementalInfo;
    if ( !m_pIncrementalInfo->m_bDisabled && m_pIncrementalInfo->m_eIncrState != INCR_STATE_HAVE_FULL_RESULTS )
      break;
    m_pHead = m_pHead->m_pNext;
    if ( m_pHead == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004F5D0
// Name: public: void CLightingPreviewThread::AccumulateOuput(int,class CSOAContainer __near *,class CSOAContainer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightingPreviewThread::AccumulateOuput(
        CLightingPreviewThread *this,
        int nLineMask,
        CSOAContainer *rslt,
        CSOAContainer *rslt1)
{
  CLightingPreviewLightDescription *m_pHead; // eax
  __m128 v5; // xmm2
  CSOAContainer *p_m_GBuffer; // edi
  FourVectors *m_pIncrementalInfo; // edx
  int v8; // esi
  int v9; // eax
  __m128 v10; // xmm0
  int v11; // ecx
  float v12; // xmm0_4
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  int v15; // eax
  int v16; // edx
  unsigned int v17; // ecx
  unsigned __int8 *v18; // esi
  __m128 *v19; // eax
  CSOAContainer *v20; // edx
  CLightingPreviewLightDescription *v21; // ecx
  unsigned int v22; // esi
  unsigned __int8 *v23; // edi
  __m128 *v24; // edx
  __m128 *v25; // ecx
  int v26; // esi
  __m128 v27; // xmm4
  __m128 v28; // xmm5
  __m128 v29; // xmm6
  __m128 v30; // xmm2
  __m128 v31; // xmm3
  __m128 *v32; // edi
  __m128 *v33; // esi
  __m128 v34; // xmm7
  __m128 v35; // xmm0
  __m128 *v36; // edi
  __m128 v37; // xmm6
  __m128 v38; // xmm6
  __m128 v39; // xmm3
  __m128 v40; // xmm0
  __m128 v41; // xmm2
  __m128 *v42; // esi
  __m128 v43; // xmm6
  __m128 v44; // xmm1
  __m128 v45; // xmm6
  __m128 v46; // xmm2
  __m128 v47; // xmm3
  __m128 v48; // xmm1
  __m128 v49; // xmm0
  __m128 v50; // xmm0
  __m128 v51; // xmm6
  __m128 v52; // xmm3
  __m128 v53; // xmm0
  int v54; // eax
  __m128 v55; // [esp-Ch] [ebp-16Ch]
  __m128 l2_4; // [esp+34h] [ebp-12Ch]
  __m128 l2_20; // [esp+44h] [ebp-11Ch]
  __m128 l1_20; // [esp+A4h] [ebp-BCh]
  __m128 l1_36; // [esp+B4h] [ebp-ACh]
  __m128 fl4Weights_4; // [esp+C4h] [ebp-9Ch]
  __m128 fl4Weights_20; // [esp+D4h] [ebp-8Ch]
  __m128 fl4NormalFactorScale_4; // [esp+E4h] [ebp-7Ch]
  __m128 fl4DistanceScale_4; // [esp+F4h] [ebp-6Ch]
  int v64; // [esp+114h] [ebp-4Ch]
  CLightingPreviewThread *v65; // [esp+118h] [ebp-48h]
  int pCoords; // [esp+11Ch] [ebp-44h]
  __m128 *pCoords_4; // [esp+120h] [ebp-40h]
  __m128 *v68; // [esp+124h] [ebp-3Ch]
  FourVectors *dest; // [esp+128h] [ebp-38h]
  CSOAContainer *pRslts; // [esp+12Ch] [ebp-34h]
  CLightingPreviewLightDescription *pRslts_4; // [esp+130h] [ebp-30h]
  CSOAContainer *pRslt; // [esp+138h] [ebp-28h]
  CLightingPreviewLightDescription *l; // [esp+13Ch] [ebp-24h]
  int v74; // [esp+140h] [ebp-20h]
  CSOAContainer *pRsltNormals; // [esp+144h] [ebp-1Ch]
  CSOAContainer *pRsltNormals_4; // [esp+148h] [ebp-18h]
  int x; // [esp+14Ch] [ebp-14h]
  int pGB; // [esp+150h] [ebp-10h]

  m_pHead = this->m_LightList.m_pHead;
  v65 = this;
  pRslts_4 = this->m_LightList.m_pHead;
  if ( this->m_LightList.m_pHead != nullptr )
  {
    v5 = Four_Ones;
    while ( 1 )
    {
      p_m_GBuffer = &this->m_GBuffer;
      pRslts = rslt;
      pRsltNormals = &this->m_GBuffer;
      if ( m_pHead->m_bLowRes )
      {
        p_m_GBuffer = &this->m_GBufferLowRes;
        pRsltNormals = &this->m_GBufferLowRes;
        pRslts = rslt1;
      }
      m_pIncrementalInfo = (FourVectors *)m_pHead->m_pIncrementalInfo;
      dest = m_pIncrementalInfo;
      if ( m_pIncrementalInfo[17].x.m128_f32[2] > 0.0 && m_pIncrementalInfo->y.m128_i32[0] >= 1 )
      {
        v8 = m_pIncrementalInfo[39].x.m128_i32[0];
        v9 = m_pIncrementalInfo[38].z.m128_i32[3];
        pRsltNormals_4 = (CSOAContainer *)v8;
        pGB = v8;
        if ( v8 < v9 )
        {
          do
            ++v8;
          while ( m_pIncrementalInfo[17].y.m128_i8[v8 + 12] == 0 && v8 < v9 );
          pGB = v8;
        }
        fl4Weights_20 = _mm_shuffle_ps((__m128)0x40800000u, (__m128)0x40800000u, 0);
        v10 = 0;
        LOBYTE(v11) = 0;
        v10.m128_f32[0] = 0.0;
        fl4DistanceScale_4 = _mm_shuffle_ps(v10, v10, 0);
        x = 0;
        if ( p_m_GBuffer->m_nRows > 0 )
        {
          do
          {
            if ( ((1 << (v11 & 0x1F)) & nLineMask) != 0 )
            {
              if ( x < (int)pRsltNormals_4 || pRsltNormals_4 == (CSOAContainer *)v8 )
              {
                v14 = Four_Zeros;
                l1_36 = v5;
              }
              else
              {
                v12 = 1.0 / (double)(v8 - (int)pRsltNormals_4) * (double)(x - (int)pRsltNormals_4);
                v13 = 0;
                v13.m128_f32[0] = v12;
                v14 = _mm_shuffle_ps(v13, v13, 0);
                l1_36 = _mm_sub_ps(v5, v14);
              }
              v15 = m_pIncrementalInfo[8].z.m128_i32[3];
              v16 = m_pIncrementalInfo->z.m128_i32[3];
              pCoords_4 = (__m128 *)(v16 + (_DWORD)pRsltNormals_4 * v15);
              v68 = (__m128 *)(v16 + v8 * v15);
              v17 = p_m_GBuffer->m_nRowStrideInBytes[2];
              pCoords = (int)&pRslts->m_pAttributePtrs[3][x * pRslts->m_nRowStrideInBytes[3]];
              v18 = p_m_GBuffer->m_pAttributePtrs[2];
              v19 = (__m128 *)&v18[x * v17];
              v20 = (CSOAContainer *)&v18[(_DWORD)pRsltNormals_4 * v17];
              v21 = (CLightingPreviewLightDescription *)&v18[pGB * v17];
              v22 = p_m_GBuffer->m_nRowStrideInBytes[0];
              v23 = p_m_GBuffer->m_pAttributePtrs[0];
              pRslt = v20;
              l = v21;
              v24 = (__m128 *)&v23[x * v22];
              v25 = (__m128 *)&v23[(_DWORD)pRsltNormals_4 * v22];
              p_m_GBuffer = pRsltNormals;
              v26 = (int)&pRsltNormals->m_pAttributePtrs[0][pGB * v22];
              fl4Weights_4 = v14;
              fl4NormalFactorScale_4 = _mm_shuffle_ps((__m128)0x3CE38E39u, (__m128)0x3CE38E39u, 0);
              v74 = 0;
              if ( pRsltNormals->m_nNumQuadsPerRow > 0 )
              {
                while ( 1 )
                {
                  v27 = *v68;
                  v28 = v68[1];
                  v29 = *(__m128 *)v26;
                  l1_20 = v68[2];
                  v30 = _mm_sub_ps(*(__m128 *)(v26 + 16), v24[1]);
                  v31 = _mm_sub_ps(*(__m128 *)(v26 + 32), v24[2]);
                  v68 += 3;
                  v32 = (__m128 *)l;
                  l = (CLightingPreviewLightDescription *)((char *)l + 48);
                  v64 = v26 + 48;
                  v33 = v32;
                  v34 = _mm_mul_ps(v32[1], v19[1]);
                  v35 = _mm_mul_ps(*v32, *v19);
                  v36 = (__m128 *)pRslt;
                  pRslt = (CSOAContainer *)((char *)pRslt + 48);
                  v37 = _mm_sub_ps(v29, *v24);
                  v38 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v37, v37), _mm_mul_ps(v30, v30)), _mm_mul_ps(v31, v31));
                  v39 = _mm_sub_ps(v25[2], v24[2]);
                  v40 = _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_max_ps(
                              Four_Epsilons,
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_add_ps(v34, v35), _mm_mul_ps(v33[2], v19[2])),
                                  fl4DistanceScale_4),
                                fl4Weights_20)),
                            fl4Weights_4),
                          _mm_rcp_ps(_mm_add_ps(_mm_mul_ps(_mm_sqrt_ps(v38), fl4NormalFactorScale_4), Four_Ones)));
                  v41 = _mm_sub_ps(v25[1], v24[1]);
                  v42 = v19;
                  l2_4 = pCoords_4[1];
                  v55 = _mm_sub_ps(*v25, *v24);
                  v43 = *pCoords_4;
                  v19 += 3;
                  v25 += 3;
                  v24 += 3;
                  l2_20 = pCoords_4[2];
                  pCoords_4 += 3;
                  v44 = _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_max_ps(
                              Four_Epsilons,
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_mul_ps(v42[1], v36[1]), _mm_mul_ps(*v42, *v36)),
                                    _mm_mul_ps(v42[2], v36[2])),
                                  fl4DistanceScale_4),
                                fl4Weights_20)),
                            l1_36),
                          _mm_rcp_ps(
                            _mm_add_ps(
                              _mm_mul_ps(
                                _mm_sqrt_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_mul_ps(v55, v55), _mm_mul_ps(v41, v41)),
                                    _mm_mul_ps(v39, v39))),
                                fl4NormalFactorScale_4),
                              Four_Ones)));
                  v45 = _mm_add_ps(_mm_mul_ps(v43, v44), _mm_mul_ps(v27, v40));
                  v46 = _mm_add_ps(_mm_mul_ps(l2_4, v44), _mm_mul_ps(v28, v40));
                  v47 = _mm_add_ps(_mm_mul_ps(l2_20, v44), _mm_mul_ps(l1_20, v40));
                  v48 = _mm_add_ps(v44, v40);
                  v49 = _mm_rcp_ps(v48);
                  v50 = _mm_sub_ps(_mm_add_ps(v49, v49), _mm_mul_ps(_mm_mul_ps(v49, v49), v48));
                  v51 = _mm_add_ps(_mm_mul_ps(v45, v50), *(__m128 *)pCoords);
                  v52 = _mm_mul_ps(v47, v50);
                  *(__m128 *)(pCoords + 16) = _mm_add_ps(*(__m128 *)(pCoords + 16), _mm_mul_ps(v46, v50));
                  v53 = *(__m128 *)(pCoords + 32);
                  *(__m128 *)pCoords = v51;
                  *(__m128 *)(pCoords + 32) = _mm_add_ps(v53, v52);
                  pCoords += 48;
                  p_m_GBuffer = pRsltNormals;
                  if ( ++v74 >= pRsltNormals->m_nNumQuadsPerRow )
                    break;
                  v26 = v64;
                }
                v5 = Four_Ones;
              }
              m_pIncrementalInfo = dest;
              v8 = pGB;
            }
            if ( x >= v8 )
            {
              v54 = m_pIncrementalInfo[38].z.m128_i32[3];
              pRsltNormals_4 = (CSOAContainer *)v8;
              if ( v8 < v54 )
              {
                do
                  ++v8;
                while ( m_pIncrementalInfo[17].y.m128_i8[v8 + 12] == 0 && v8 < v54 );
                pGB = v8;
              }
            }
            v11 = x + 1;
            x = v11;
          }
          while ( v11 < p_m_GBuffer->m_nRows );
        }
      }
      m_pHead = pRslts_4->m_pNext;
      pRslts_4 = m_pHead;
      if ( m_pHead == nullptr )
        break;
      this = v65;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004FA50
// Name: void s_AccumulateOutput(int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl s_AccumulateOutput(int *nLineMask)
{
  CLightingPreviewThread::AccumulateOuput(
    this: s_pThis,
    nLineMask: *nLineMask,
    rslt: s_pResultBuffer,
    rslt1: s_pResultBuffer1);
}

//------------------------------------------------------------------------------
// Address: 0x1004FA80
// Name: public: void CLightingPreviewThread::AddLowresResultToHires(class CSOAContainer __near &,class CSOAContainer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightingPreviewThread::AddLowresResultToHires(
        CLightingPreviewThread *this,
        CSOAContainer *lores,
        CSOAContainer *hires)
{
  int v4; // ecx
  CSOAContainer *v5; // eax
  int v6; // edx
  int v7; // ecx
  unsigned __int8 *v8; // esi
  unsigned int v9; // eax
  __m128 v10; // xmm0
  __m128 v11; // xmm4
  __m128 v12; // xmm6
  __m128 *v13; // eax
  unsigned int v14; // esi
  unsigned __int8 *v15; // edx
  unsigned __int8 *v16; // esi
  unsigned __int8 *v17; // ecx
  __m128 v18; // xmm0
  __m128 v19; // xmm0
  unsigned int v20; // edi
  int v21; // edx
  unsigned __int8 *v22; // edi
  FourVectors *v23; // edx
  __m128 v24; // xmm0
  __m128 z; // xmm0
  __m128 v26; // xmm5
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  __m128 *v29; // eax
  __m128 *v30; // esi
  __m128 *v31; // edi
  int v32; // edx
  int v33; // ecx
  __m128 v34; // xmm3
  __m128 v35; // xmm7
  __m128 v36; // xmm5
  __m128 v37; // xmm3
  __m128 v38; // xmm1
  __m128 v39; // xmm7
  __m128 v40; // xmm1
  __m128 v41; // xmm3
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // xmm2
  __m128 v46; // xmm4
  __m128 v47; // xmm2
  __m128 v48; // xmm1
  __m128 v49; // xmm3
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  __m128 v52; // xmm6
  __m128 v53; // xmm2
  __m128 v54; // xmm7
  __m128 v55; // xmm2
  __m128 v56; // xmm1
  __m128 v57; // xmm6
  __m128 v58; // xmm2
  __m128 v59; // xmm3
  __m128 v60; // xmm4
  __m128 v61; // xmm3
  __m128 v62; // xmm6
  __m128 v63; // xmm6
  __m128 v64; // xmm4
  __m128 v65; // xmm4
  __m128 v66; // xmm4
  __m128 v67; // xmm7
  __m128 v68; // xmm4
  __m128 v69; // xmm6
  __m128 v70; // xmm4
  __m128 v71; // xmm4
  __m128 v72; // xmm4
  __m128 v73; // xmm4
  __m128 v74; // xmm6
  __m128 v75; // xmm4
  __m128 v76; // xmm4
  __m128 v77; // xmm4
  __m128 v78; // xmm0
  __m128 v79; // xmm4
  __m128 v80; // xmm6
  __m128 v81; // xmm4
  __m128 v82; // xmm0
  __m128 v83; // xmm6
  __m128 v84; // xmm0
  __m128 v85; // xmm4
  __m128 v86; // xmm4
  __m128 v87; // xmm6
  __m128 v88; // xmm1
  __m128 v89; // xmm4
  __m128 v90; // xmm6
  __m128 v91; // xmm1
  __m128 v92; // xmm2
  __m128 v93; // xmm1
  __m128 v94; // xmm6
  __m128 v95; // xmm2
  __m128 v96; // xmm6
  __m128 v97; // xmm3
  __m128 v98; // xmm7
  __m128 v99; // xmm6
  __m128 v100; // xmm3
  __m128 v101; // xmm0
  __m128 v102; // xmm4
  __m128 v103; // xmm0
  __m128 v104; // xmm3
  __m128 v105; // [esp-Ch] [ebp-5ACh]
  __m128 normFFFF_20; // [esp+14h] [ebp-58Ch]
  __m128 normFFFF_36; // [esp+24h] [ebp-57Ch]
  __m128 normBBBB_20; // [esp+44h] [ebp-55Ch]
  __m128 normBBBB_36; // [esp+54h] [ebp-54Ch]
  __m128 normEEEE_20; // [esp+74h] [ebp-52Ch]
  __m128 rsltShiftRegister0_4; // [esp+94h] [ebp-50Ch]
  __m128 rsltShiftRegister0_20; // [esp+A4h] [ebp-4FCh]
  __m128 rsltShiftRegister0_36; // [esp+B4h] [ebp-4ECh]
  __m128 normAAAA_4; // [esp+C4h] [ebp-4DCh]
  __m128 normAAAA_20; // [esp+D4h] [ebp-4CCh]
  __m128 normAAAA_36; // [esp+E4h] [ebp-4BCh]
  __m128 posAAAA_4; // [esp+F4h] [ebp-4ACh]
  __m128 posAAAA_20; // [esp+104h] [ebp-49Ch]
  __m128 v4Delta_20; // [esp+134h] [ebp-46Ch]
  __m128 v4Delta_20a; // [esp+134h] [ebp-46Ch]
  __m128 v4Delta_20b; // [esp+134h] [ebp-46Ch]
  __m128 v4Delta_36; // [esp+144h] [ebp-45Ch]
  __m128 rsltAAAA_4; // [esp+154h] [ebp-44Ch]
  __m128 rsltAAAA_20; // [esp+164h] [ebp-43Ch]
  __m128 rsltAAAA_36; // [esp+174h] [ebp-42Ch]
  __m128 rsltFFFF_4; // [esp+184h] [ebp-41Ch]
  __m128 rsltFFFF_20; // [esp+194h] [ebp-40Ch]
  __m128 rsltFFFF_36; // [esp+1A4h] [ebp-3FCh]
  __m128 posFFFF_4; // [esp+1B4h] [ebp-3ECh]
  __m128 posFFFF_20; // [esp+1C4h] [ebp-3DCh]
  __m128 out_20; // [esp+1F4h] [ebp-3ACh]
  __m128 out_20a; // [esp+1F4h] [ebp-3ACh]
  __m128 out_36; // [esp+204h] [ebp-39Ch]
  __m128 posBBBB_4; // [esp+214h] [ebp-38Ch]
  __m128 posBBBB_20; // [esp+224h] [ebp-37Ch]
  __m128 posBBBB_36; // [esp+234h] [ebp-36Ch]
  __m128 rsltEEEE_4; // [esp+244h] [ebp-35Ch]
  __m128 rsltEEEE_20; // [esp+254h] [ebp-34Ch]
  __m128 rsltEEEE_36; // [esp+264h] [ebp-33Ch]
  __m128 rsltBBBB_4; // [esp+274h] [ebp-32Ch]
  __m128 rsltBBBB_20; // [esp+284h] [ebp-31Ch]
  __m128 rsltBBBB_36; // [esp+294h] [ebp-30Ch]
  __m128 posEEEE_4; // [esp+2A4h] [ebp-2FCh]
  __m128 posEEEE_20; // [esp+2B4h] [ebp-2ECh]
  __m128 posEEEE_36; // [esp+2C4h] [ebp-2DCh]
  __m128 rsltShiftRegister1_4; // [esp+2D4h] [ebp-2CCh]
  __m128 rsltShiftRegister1_20; // [esp+2E4h] [ebp-2BCh]
  __m128 rsltShiftRegister1_36; // [esp+2F4h] [ebp-2ACh]
  __m128 normShiftRegister0_4; // [esp+304h] [ebp-29Ch]
  __m128 normShiftRegister0_20; // [esp+314h] [ebp-28Ch]
  __m128 normShiftRegister0_36; // [esp+324h] [ebp-27Ch]
  __m128 posShiftRegister1a_4; // [esp+334h] [ebp-26Ch]
  __m128 posShiftRegister1a_20; // [esp+344h] [ebp-25Ch]
  __m128 posShiftRegister1a_36; // [esp+354h] [ebp-24Ch]
  __m128 normShiftRegister0a_4; // [esp+364h] [ebp-23Ch]
  __m128 normShiftRegister0a_20; // [esp+374h] [ebp-22Ch]
  __m128 normShiftRegister0a_36; // [esp+384h] [ebp-21Ch]
  __m128 posShiftRegister0a_4; // [esp+394h] [ebp-20Ch]
  __m128 posShiftRegister0a_20; // [esp+3A4h] [ebp-1FCh]
  __m128 posShiftRegister0a_36; // [esp+3B4h] [ebp-1ECh]
  __m128 rsltShiftRegister0a_4; // [esp+3C4h] [ebp-1DCh]
  __m128 rsltShiftRegister0a_20; // [esp+3D4h] [ebp-1CCh]
  __m128 rsltShiftRegister0a_36; // [esp+3E4h] [ebp-1BCh]
  __m128 normShiftRegister1a_4; // [esp+3F4h] [ebp-1ACh]
  __m128 normShiftRegister1a_20; // [esp+404h] [ebp-19Ch]
  __m128 normShiftRegister1a_36; // [esp+414h] [ebp-18Ch]
  __m128 rsltShiftRegister1a_4; // [esp+424h] [ebp-17Ch]
  __m128 rsltShiftRegister1a_20; // [esp+434h] [ebp-16Ch]
  __m128 rsltShiftRegister1a_36; // [esp+444h] [ebp-15Ch]
  __m128 normShiftRegister1_4; // [esp+454h] [ebp-14Ch]
  __m128 normShiftRegister1_20; // [esp+464h] [ebp-13Ch]
  __m128 fl4Pos_4; // [esp+484h] [ebp-11Ch]
  __m128 fl4Pos_20; // [esp+494h] [ebp-10Ch]
  __m128 fl4Pos_36; // [esp+4A4h] [ebp-FCh]
  __m128 posShiftRegister1_4; // [esp+4B4h] [ebp-ECh]
  __m128 posShiftRegister1_20; // [esp+4C4h] [ebp-DCh]
  __m128 posShiftRegister1_36; // [esp+4D4h] [ebp-CCh]
  __m128 posShiftRegister0_4; // [esp+4E4h] [ebp-BCh]
  __m128 posShiftRegister0_20; // [esp+4F4h] [ebp-ACh]
  __m128 posShiftRegister0_36; // [esp+504h] [ebp-9Ch]
  __m128 dNorm_4; // [esp+514h] [ebp-8Ch]
  __m128 dNorm_20; // [esp+524h] [ebp-7Ch]
  __m128 dNorm_36; // [esp+534h] [ebp-6Ch]
  __m128 fl4DistanceScale_4; // [esp+544h] [ebp-5Ch]
  __m128 fl4NormalFactorScale_4; // [esp+554h] [ebp-4Ch]
  int fl4NormalBias_12; // [esp+56Ch] [ebp-34h]
  __m128 *v187; // [esp+570h] [ebp-30h]
  FourVectors *pDestPos; // [esp+574h] [ebp-2Ch]
  FourVectors *pDestNormal; // [esp+578h] [ebp-28h]
  FourVectors *pSrcNormal1; // [esp+57Ch] [ebp-24h]
  FourVectors *pSrcPos1; // [esp+580h] [ebp-20h]
  int pSrc1; // [esp+584h] [ebp-1Ch]
  CLightingPreviewThread *nIterations; // [esp+588h] [ebp-18h]
  int pDest; // [esp+58Ch] [ebp-14h]
  FourVectors *pDesta; // [esp+58Ch] [ebp-14h]
  int y; // [esp+590h] [ebp-10h]
  int ya; // [esp+590h] [ebp-10h]

  fl4DistanceScale_4 = _mm_shuffle_ps((__m128)0x40800000u, (__m128)0x40800000u, 0);
  fl4NormalFactorScale_4 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  v4 = 0;
  nIterations = this;
  dNorm_36 = _mm_shuffle_ps((__m128)0x3CE38E39u, (__m128)0x3CE38E39u, 0);
  pSrc1 = 0;
  if ( hires->m_nRows > 0 )
  {
    v5 = lores;
    do
    {
      v6 = v5->m_nRows - 1;
      v7 = v4 >> 2;
      if ( v7 >= v6 )
        v7 = v5->m_nRows - 1;
      pDest = v7;
      y = v7 + 1;
      if ( v7 + 1 >= v6 )
        y = v5->m_nRows - 1;
      v8 = v5->m_pAttributePtrs[3];
      pSrcNormal1 = (FourVectors *)hires->m_nNumQuadsPerRow;
      v9 = v5->m_nRowStrideInBytes[3];
      v10 = *(__m128 *)&v8[y * v9 + 32];
      v11 = *(__m128 *)&v8[y * v9];
      v12 = *(__m128 *)&v8[y * v9 + 16];
      pDestNormal = (FourVectors *)&v8[y * v9 + 48];
      v13 = (__m128 *)&v8[v7 * v9];
      v14 = this->m_GBufferLowRes.m_nRowStrideInBytes[2];
      v15 = &this->m_GBufferLowRes.m_pAttributePtrs[2][y * v14];
      v16 = &this->m_GBufferLowRes.m_pAttributePtrs[2][v7 * v14];
      v17 = this->m_GBufferLowRes.m_pAttributePtrs[0];
      rsltShiftRegister1_20 = v10;
      rsltShiftRegister1_36 = *(__m128 *)v16;
      normShiftRegister0_4 = *((__m128 *)v16 + 1);
      normShiftRegister0_20 = *((__m128 *)v16 + 2);
      rsltShiftRegister1a_36 = *(__m128 *)v15;
      v18 = *((__m128 *)v15 + 1);
      v15 += 48;
      normShiftRegister1_4 = v18;
      v19 = *((__m128 *)v15 - 1);
      v187 = (__m128 *)v15;
      v20 = this->m_GBufferLowRes.m_nRowStrideInBytes[0];
      v21 = y * v20;
      v22 = &v17[pDest * v20];
      v23 = (FourVectors *)&nIterations->m_GBufferLowRes.m_pAttributePtrs[0][v21];
      normShiftRegister1_20 = v19;
      posShiftRegister1_36 = *(__m128 *)v22;
      posShiftRegister0_4 = *((__m128 *)v22 + 1);
      posShiftRegister0_20 = *((__m128 *)v22 + 2);
      fl4Pos_36 = v23->x;
      v24 = v23->y;
      ++v23;
      posShiftRegister1_4 = v24;
      z = v23[-1].z;
      pDestPos = v23;
      pSrcPos1 = (FourVectors *)&hires->m_pAttributePtrs[3][pSrc1 * hires->m_nRowStrideInBytes[3]];
      v26 = *v13;
      v27 = v13[1];
      v28 = v13[2];
      fl4NormalBias_12 = (int)&nIterations->m_GBuffer.m_pAttributePtrs[2][pSrc1
                                                                        * nIterations->m_GBuffer.m_nRowStrideInBytes[2]];
      v29 = v13 + 3;
      v30 = (__m128 *)(v16 + 48);
      v31 = (__m128 *)(v22 + 48);
      v32 = (int)&nIterations->m_GBuffer.m_pAttributePtrs[0][pSrc1 * nIterations->m_GBuffer.m_nRowStrideInBytes[0]];
      posShiftRegister1_20 = z;
      pDesta = (FourVectors *)(lores->m_nNumQuadsPerRow - 1);
      ya = 0;
      if ( (int)pSrcNormal1 > 0 )
      {
        LOBYTE(v33) = 0;
        while ( 1 )
        {
          if ( (v33 & 3) == 0 && pDesta != nullptr )
          {
            posShiftRegister0a_36 = *v29;
            rsltShiftRegister0a_4 = v29[1];
            rsltShiftRegister0a_20 = v29[2];
            normShiftRegister1a_36 = pDestNormal->x;
            rsltShiftRegister1a_4 = pDestNormal->y;
            rsltShiftRegister1a_20 = pDestNormal->z;
            pDesta = (FourVectors *)((char *)pDesta - 1);
            posShiftRegister1a_36 = *v30;
            normShiftRegister0a_4 = v30[1];
            normShiftRegister0a_20 = v30[2];
            ++pDestNormal;
            rsltShiftRegister0a_36 = *v187;
            normShiftRegister1a_4 = v187[1];
            normShiftRegister1a_20 = v187[2];
            normShiftRegister0a_36 = *v31;
            posShiftRegister0a_4 = v31[1];
            v187 += 3;
            posShiftRegister0a_20 = v31[2];
            normShiftRegister0_36 = pDestPos->x;
            posShiftRegister1a_4 = pDestPos->y;
            v29 += 3;
            v30 += 3;
            v31 += 3;
            posShiftRegister1a_20 = pDestPos->z;
            ++pDestPos;
          }
          v34 = posShiftRegister0a_36;
          v4Delta_36 = _mm_shuffle_ps(v26, v26, 0);
          rsltAAAA_4 = _mm_shuffle_ps(v27, v27, 0);
          rsltAAAA_20 = _mm_shuffle_ps(v28, v28, 0);
          rsltEEEE_36 = _mm_shuffle_ps(v26, v26, 85);
          rsltBBBB_4 = _mm_shuffle_ps(v27, v27, 85);
          rsltBBBB_20 = _mm_shuffle_ps(v28, v28, 85);
          v35 = _mm_andnot_ps((__m128)xmmword_10642780, _mm_shuffle_ps(v26, v26, 57));
          v36 = _mm_shuffle_ps(v34, v34, 0);
          posShiftRegister0a_36 = _mm_shuffle_ps(v34, v34, 57);
          v37 = _mm_andnot_ps((__m128)xmmword_10642780, _mm_shuffle_ps(v27, v27, 57));
          v38 = rsltShiftRegister0a_4;
          v26 = _mm_or_ps(_mm_and_ps(v36, (__m128)xmmword_10642780), v35);
          v39 = _mm_shuffle_ps(v38, v38, 0);
          rsltShiftRegister0a_4 = _mm_shuffle_ps(v38, v38, 57);
          v40 = rsltShiftRegister0a_20;
          rsltShiftRegister0_4 = _mm_or_ps(v37, _mm_and_ps(v39, (__m128)xmmword_10642780));
          v41 = _mm_andnot_ps((__m128)xmmword_10642780, _mm_shuffle_ps(v28, v28, 57));
          v42 = _mm_shuffle_ps(v40, v40, 0);
          rsltShiftRegister0a_20 = _mm_shuffle_ps(v40, v40, 57);
          posBBBB_36 = _mm_shuffle_ps(v11, v11, 0);
          rsltEEEE_4 = _mm_shuffle_ps(v12, v12, 0);
          v43 = rsltShiftRegister1_20;
          rsltEEEE_20 = _mm_shuffle_ps(v43, v43, 0);
          rsltAAAA_36 = _mm_shuffle_ps(v11, v11, 85);
          rsltFFFF_4 = _mm_shuffle_ps(v12, v12, 85);
          rsltShiftRegister0_20 = _mm_or_ps(v41, _mm_and_ps(v42, (__m128)xmmword_10642780));
          rsltFFFF_20 = _mm_shuffle_ps(v43, v43, 85);
          v44 = normShiftRegister1a_36;
          posEEEE_36 = _mm_or_ps(
                         _mm_andnot_ps((__m128)xmmword_10642780, _mm_shuffle_ps(v11, v11, 57)),
                         _mm_and_ps(_mm_shuffle_ps(v44, v44, 0), (__m128)xmmword_10642780));
          normShiftRegister1a_36 = _mm_shuffle_ps(v44, v44, 57);
          v45 = rsltShiftRegister1a_4;
          rsltShiftRegister1a_4 = _mm_shuffle_ps(v45, v45, 57);
          v46 = normShiftRegister0_20;
          rsltShiftRegister1_4 = _mm_or_ps(
                                   _mm_andnot_ps((__m128)xmmword_10642780, _mm_shuffle_ps(v12, v12, 57)),
                                   _mm_and_ps(_mm_shuffle_ps(v45, v45, 0), (__m128)xmmword_10642780));
          v47 = _mm_andnot_ps((__m128)xmmword_10642780, _mm_shuffle_ps(v43, v43, 57));
          v48 = rsltShiftRegister1a_20;
          v49 = normShiftRegister0_4;
          rsltShiftRegister1_20 = _mm_or_ps(v47, _mm_and_ps(_mm_shuffle_ps(v48, v48, 0), (__m128)xmmword_10642780));
          v50 = rsltShiftRegister1_36;
          rsltShiftRegister1a_20 = _mm_shuffle_ps(v48, v48, 57);
          rsltShiftRegister0_36 = _mm_shuffle_ps(v50, v50, 0);
          normAAAA_4 = _mm_shuffle_ps(v49, v49, 0);
          normAAAA_20 = _mm_shuffle_ps(v46, v46, 0);
          v51 = _mm_shuffle_ps(v50, v50, 85);
          normBBBB_20 = _mm_shuffle_ps(v46, v46, 85);
          v52 = _mm_andnot_ps((__m128)xmmword_10642780, _mm_shuffle_ps(v50, v50, 57));
          v53 = posShiftRegister1a_36;
          v54 = _mm_shuffle_ps(v53, v53, 0);
          posShiftRegister1a_36 = _mm_shuffle_ps(v53, v53, 57);
          v55 = normShiftRegister0a_4;
          normFFFF_36 = v51;
          v56 = _mm_shuffle_ps(v49, v49, 85);
          rsltShiftRegister1_36 = _mm_or_ps(v52, _mm_and_ps(v54, (__m128)xmmword_10642780));
          v57 = _mm_or_ps(
                  _mm_andnot_ps((__m128)xmmword_10642780, _mm_shuffle_ps(v49, v49, 57)),
                  _mm_and_ps(_mm_shuffle_ps(v55, v55, 0), (__m128)xmmword_10642780));
          normShiftRegister0a_4 = _mm_shuffle_ps(v55, v55, 57);
          v58 = normShiftRegister0a_20;
          v59 = _mm_or_ps(
                  _mm_andnot_ps((__m128)xmmword_10642780, _mm_shuffle_ps(v46, v46, 57)),
                  _mm_and_ps(_mm_shuffle_ps(v58, v58, 0), (__m128)xmmword_10642780));
          v60 = rsltShiftRegister1a_36;
          normShiftRegister0a_20 = _mm_shuffle_ps(v58, v58, 57);
          normShiftRegister0_20 = v59;
          v61 = normShiftRegister1_4;
          normBBBB_36 = _mm_shuffle_ps(v60, v60, 0);
          normShiftRegister0_4 = v57;
          v62 = normShiftRegister1_20;
          normFFFF_20 = _mm_shuffle_ps(v62, v62, 85);
          normEEEE_20 = _mm_shuffle_ps(v62, v62, 0);
          v105 = _mm_shuffle_ps(v60, v60, 85);
          v63 = _mm_andnot_ps((__m128)xmmword_10642780, _mm_shuffle_ps(v60, v60, 57));
          v64 = rsltShiftRegister0a_36;
          rsltShiftRegister0a_36 = _mm_shuffle_ps(v64, v64, 57);
          rsltShiftRegister1a_36 = _mm_or_ps(v63, _mm_and_ps(_mm_shuffle_ps(v64, v64, 0), (__m128)xmmword_10642780));
          v65 = normShiftRegister1a_4;
          normShiftRegister1a_4 = _mm_shuffle_ps(v65, v65, 57);
          normShiftRegister1_4 = _mm_or_ps(
                                   _mm_andnot_ps(
                                     (__m128)xmmword_10642780,
                                     _mm_shuffle_ps(normShiftRegister1_4, normShiftRegister1_4, 57)),
                                   _mm_and_ps(_mm_shuffle_ps(v65, v65, 0), (__m128)xmmword_10642780));
          v66 = normShiftRegister1a_20;
          v67 = _mm_shuffle_ps(v66, v66, 0);
          normShiftRegister1a_20 = _mm_shuffle_ps(v66, v66, 57);
          v68 = posShiftRegister1_36;
          normShiftRegister1_20 = _mm_or_ps(
                                    _mm_andnot_ps(
                                      (__m128)xmmword_10642780,
                                      _mm_shuffle_ps(normShiftRegister1_20, normShiftRegister1_20, 57)),
                                    _mm_and_ps(v67, (__m128)xmmword_10642780));
          normAAAA_36 = _mm_shuffle_ps(v68, v68, 0);
          posAAAA_4 = _mm_shuffle_ps(posShiftRegister0_4, posShiftRegister0_4, 0);
          posAAAA_20 = _mm_shuffle_ps(posShiftRegister0_20, posShiftRegister0_20, 0);
          out_36 = _mm_shuffle_ps(v68, v68, 85);
          posBBBB_4 = _mm_shuffle_ps(posShiftRegister0_4, posShiftRegister0_4, 85);
          posBBBB_20 = _mm_shuffle_ps(posShiftRegister0_20, posShiftRegister0_20, 85);
          v69 = _mm_andnot_ps((__m128)xmmword_10642780, _mm_shuffle_ps(v68, v68, 57));
          v70 = normShiftRegister0a_36;
          normShiftRegister0a_36 = _mm_shuffle_ps(v70, v70, 57);
          posShiftRegister1_36 = _mm_or_ps(v69, _mm_and_ps(_mm_shuffle_ps(v70, v70, 0), (__m128)xmmword_10642780));
          v71 = posShiftRegister0a_4;
          posShiftRegister0_4 = _mm_or_ps(
                                  _mm_andnot_ps(
                                    (__m128)xmmword_10642780,
                                    _mm_shuffle_ps(posShiftRegister0_4, posShiftRegister0_4, 57)),
                                  _mm_and_ps(_mm_shuffle_ps(v71, v71, 0), (__m128)xmmword_10642780));
          posShiftRegister0a_4 = _mm_shuffle_ps(v71, v71, 57);
          v72 = posShiftRegister0a_20;
          posShiftRegister0_20 = _mm_or_ps(
                                   _mm_andnot_ps(
                                     (__m128)xmmword_10642780,
                                     _mm_shuffle_ps(posShiftRegister0_20, posShiftRegister0_20, 57)),
                                   _mm_and_ps(_mm_shuffle_ps(v72, v72, 0), (__m128)xmmword_10642780));
          posShiftRegister0a_20 = _mm_shuffle_ps(v72, v72, 57);
          v73 = fl4Pos_36;
          rsltBBBB_36 = _mm_shuffle_ps(v73, v73, 0);
          posEEEE_4 = _mm_shuffle_ps(posShiftRegister1_4, posShiftRegister1_4, 0);
          posEEEE_20 = _mm_shuffle_ps(posShiftRegister1_20, posShiftRegister1_20, 0);
          rsltFFFF_36 = _mm_shuffle_ps(v73, v73, 85);
          posFFFF_4 = _mm_shuffle_ps(posShiftRegister1_4, posShiftRegister1_4, 85);
          posFFFF_20 = _mm_shuffle_ps(posShiftRegister1_20, posShiftRegister1_20, 85);
          v74 = _mm_andnot_ps((__m128)xmmword_10642780, _mm_shuffle_ps(v73, v73, 57));
          v75 = normShiftRegister0_36;
          normShiftRegister0_36 = _mm_shuffle_ps(v75, v75, 57);
          fl4Pos_36 = _mm_or_ps(v74, _mm_and_ps(_mm_shuffle_ps(v75, v75, 0), (__m128)xmmword_10642780));
          v76 = posShiftRegister1a_4;
          posShiftRegister1a_4 = _mm_shuffle_ps(v76, v76, 57);
          posShiftRegister1_4 = _mm_or_ps(
                                  _mm_andnot_ps(
                                    (__m128)xmmword_10642780,
                                    _mm_shuffle_ps(posShiftRegister1_4, posShiftRegister1_4, 57)),
                                  _mm_and_ps(_mm_shuffle_ps(v76, v76, 0), (__m128)xmmword_10642780));
          v77 = posShiftRegister1a_20;
          posShiftRegister0_36 = *(__m128 *)fl4NormalBias_12;
          dNorm_4 = *(__m128 *)(fl4NormalBias_12 + 16);
          posShiftRegister1_20 = _mm_or_ps(
                                   _mm_andnot_ps(
                                     (__m128)xmmword_10642780,
                                     _mm_shuffle_ps(posShiftRegister1_20, posShiftRegister1_20, 57)),
                                   _mm_and_ps(_mm_shuffle_ps(v77, v77, 0), (__m128)xmmword_10642780));
          posShiftRegister1a_20 = _mm_shuffle_ps(v77, v77, 57);
          dNorm_20 = *(__m128 *)(fl4NormalBias_12 + 32);
          v78 = _mm_sub_ps(normAAAA_36, *(__m128 *)v32);
          fl4Pos_4 = *(__m128 *)(v32 + 16);
          v79 = _mm_sub_ps(posAAAA_4, fl4Pos_4);
          v80 = _mm_mul_ps(v79, v79);
          v81 = _mm_sub_ps(posAAAA_20, *(__m128 *)(v32 + 32));
          v82 = _mm_sqrt_ps(_mm_add_ps(_mm_add_ps(v80, _mm_mul_ps(v78, v78)), _mm_mul_ps(v81, v81)));
          v83 = _mm_sub_ps(posBBBB_4, fl4Pos_4);
          fl4Pos_20 = *(__m128 *)(v32 + 32);
          v84 = _mm_mul_ps(
                  _mm_rcp_ps(_mm_add_ps(_mm_mul_ps(v82, dNorm_36), Four_Ones)),
                  _mm_max_ps(
                    Four_Epsilons,
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(dNorm_4, normAAAA_4),
                            _mm_mul_ps(*(__m128 *)fl4NormalBias_12, rsltShiftRegister0_36)),
                          _mm_mul_ps(normAAAA_20, dNorm_20)),
                        fl4NormalFactorScale_4),
                      fl4DistanceScale_4)));
          v85 = _mm_sub_ps(out_36, *(__m128 *)v32);
          v4Delta_20 = _mm_sub_ps(posBBBB_20, fl4Pos_20);
          v86 = _mm_sqrt_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v83, v83), _mm_mul_ps(v85, v85)), _mm_mul_ps(v4Delta_20, v4Delta_20)));
          v87 = _mm_max_ps(
                  Four_Epsilons,
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(v56, dNorm_4), _mm_mul_ps(*(__m128 *)fl4NormalBias_12, normFFFF_36)),
                        _mm_mul_ps(normBBBB_20, dNorm_20)),
                      fl4NormalFactorScale_4),
                    fl4DistanceScale_4));
          v88 = _mm_sub_ps(rsltBBBB_36, *(__m128 *)v32);
          v89 = _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(_mm_mul_ps(v86, dNorm_36), Four_Ones)), v87);
          v90 = _mm_sub_ps(posEEEE_4, fl4Pos_4);
          v4Delta_20a = _mm_sub_ps(posEEEE_20, fl4Pos_20);
          fl4NormalBias_12 += 48;
          v91 = _mm_mul_ps(
                  _mm_sqrt_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_mul_ps(v90, v90), _mm_mul_ps(v88, v88)),
                      _mm_mul_ps(v4Delta_20a, v4Delta_20a))),
                  dNorm_36);
          v92 = _mm_sub_ps(rsltFFFF_36, *(__m128 *)v32);
          v4Delta_20b = _mm_sub_ps(posFFFF_20, fl4Pos_20);
          v93 = _mm_mul_ps(
                  _mm_rcp_ps(_mm_add_ps(v91, Four_Ones)),
                  _mm_max_ps(
                    Four_Epsilons,
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v61, v61, 0), dNorm_4),
                            _mm_mul_ps(posShiftRegister0_36, normBBBB_36)),
                          _mm_mul_ps(normEEEE_20, dNorm_20)),
                        fl4NormalFactorScale_4),
                      fl4DistanceScale_4)));
          v94 = _mm_sub_ps(posFFFF_4, fl4Pos_4);
          v95 = _mm_mul_ps(
                  _mm_rcp_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_sqrt_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_mul_ps(v94, v94), _mm_mul_ps(v92, v92)),
                            _mm_mul_ps(v4Delta_20b, v4Delta_20b))),
                        dNorm_36),
                      Four_Ones)),
                  _mm_max_ps(
                    Four_Epsilons,
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v61, v61, 85), dNorm_4),
                            _mm_mul_ps(posShiftRegister0_36, v105)),
                          _mm_mul_ps(normFFFF_20, dNorm_20)),
                        fl4NormalFactorScale_4),
                      fl4DistanceScale_4)));
          v96 = _mm_add_ps(_mm_add_ps(v95, v93), _mm_add_ps(v89, v84));
          v97 = _mm_rcp_ps(v96);
          v98 = _mm_mul_ps(_mm_mul_ps(v97, v97), v96);
          v99 = _mm_mul_ps(v84, v4Delta_36);
          v100 = _mm_sub_ps(_mm_add_ps(v97, v97), v98);
          out_20 = _mm_mul_ps(v84, rsltAAAA_20);
          v101 = _mm_add_ps(_mm_mul_ps(v89, rsltBBBB_4), _mm_mul_ps(v84, rsltAAAA_4));
          out_20a = _mm_add_ps(_mm_mul_ps(v89, rsltBBBB_20), out_20);
          v102 = _mm_mul_ps(
                   v100,
                   _mm_add_ps(
                     _mm_mul_ps(v95, rsltAAAA_36),
                     _mm_add_ps(_mm_mul_ps(v93, posBBBB_36), _mm_add_ps(_mm_mul_ps(v89, rsltEEEE_36), v99))));
          v103 = _mm_add_ps(
                   _mm_mul_ps(
                     v100,
                     _mm_add_ps(_mm_mul_ps(v95, rsltFFFF_4), _mm_add_ps(_mm_mul_ps(v93, rsltEEEE_4), v101))),
                   pSrcPos1->y);
          v104 = _mm_add_ps(
                   _mm_mul_ps(
                     v100,
                     _mm_add_ps(_mm_mul_ps(v95, rsltFFFF_20), _mm_add_ps(_mm_mul_ps(v93, rsltEEEE_20), out_20a))),
                   pSrcPos1->z);
          pSrcPos1->x = _mm_add_ps(pSrcPos1->x, v102);
          pSrcPos1->y = v103;
          pSrcPos1->z = v104;
          v33 = ya + 1;
          ++pSrcPos1;
          ya = v33;
          if ( v33 >= (int)pSrcNormal1 )
            break;
          v12 = rsltShiftRegister1_4;
          v28 = rsltShiftRegister0_20;
          v27 = rsltShiftRegister0_4;
          v11 = posEEEE_36;
          v32 += 48;
        }
      }
      this = nIterations;
      v5 = lores;
      v4 = pSrc1 + 1;
      pSrc1 = v4;
    }
    while ( v4 < hires->m_nRows );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050710
// Name: public: void CLightingPreviewThread::CalculateForLightTask(int,int,class CLightingPreviewLightDescription __near *,float __near *,class CIncrementalLightInfo __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CLightingPreviewThread::CalculateForLightTask(
        CLightingPreviewThread *this@<ecx>,
        FourVectors *a2@<ebp>,
        int a3@<edi>,
        int nLineStart,
        int nLineEnd,
        CLightingPreviewLightDescription *l,
        float *fContributionOut,
        CIncrementalLightInfo *pLInfo)
{
  CIncrementalLightInfo *m_pIncrementalInfo; // esi
  __m128 v9; // xmm0
  int *p_m_nColumns; // esi
  int SIMDRandContext; // eax
  bool v12; // zf
  int *v13; // edi
  int m_nFirstCalculatedLine; // eax
  CSOAContainer *v15; // ecx
  _OWORD *v16; // esi
  __m128 v17; // xmm2
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  int v20; // ecx
  _OWORD *v21; // edi
  bool v22; // cc
  __m128 v23; // xmm0
  __int128 v24; // xmm1
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  __m128 v29; // xmm0
  __m128 v30; // xmm0
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  __m128 v34; // xmm4
  __m128 v35; // xmm0
  __m128 v36; // xmm0
  __m128 v37; // xmm4
  RayTracingEnvironment *v38; // ecx
  int i; // eax
  CSOAContainer *v40; // eax
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 *v44; // ecx
  __m128 v45; // xmm4
  __m128 v46; // xmm0
  __m128 v47; // xmm1
  __m128 v48; // xmm2
  __m128 v49; // xmm3
  int m_nMaxCalculatedLine; // edx
  __m128 v51; // xmm2
  __m128 v52; // xmm0
  __m128 v53; // xmm1
  int v54; // [esp-24h] [ebp-294h]
  int v55; // [esp-20h] [ebp-290h]
  int v56; // [esp-1Ch] [ebp-28Ch]
  _BYTE r_rslt_36[496]; // [esp+24h] [ebp-24Ch] OVERLAPPED BYREF
  int v58; // [esp+220h] [ebp-50h]
  __m128 v59; // [esp+224h] [ebp-4Ch] OVERLAPPED
  int v60; // [esp+240h] [ebp-30h]
  __m128 *v61; // [esp+244h] [ebp-2Ch]
  int v62; // [esp+248h] [ebp-28h]
  int x; // [esp+24Ch] [ebp-24h]
  FourVectors *pAlbedo; // [esp+250h] [ebp-20h]
  int idx; // [esp+254h] [ebp-1Ch]
  CSOAContainer *rslt; // [esp+258h] [ebp-18h]
  int *v67; // [esp+25Ch] [ebp-14h]
  int nCtx; // [esp+260h] [ebp-10h]
  FourVectors *pDataOut; // [esp+264h] [ebp-Ch]
  CSOAContainer *pGB; // [esp+268h] [ebp-8h]
  CSOAContainer *retaddr; // [esp+270h] [ebp+0h]

  pDataOut = a2;
  pGB = retaddr;
  v56 = a3;
  pAlbedo = (FourVectors *)this;
  *(__m128 *)&r_rslt_36[272] = Four_Zeros;
  *(__m128 *)&r_rslt_36[432] = Four_Zeros;
  m_pIncrementalInfo = l->m_pIncrementalInfo;
  *(__m128 *)&r_rslt_36[336] = _mm_shuffle_ps((__m128)0x38CCCCCDu, (__m128)0x38CCCCCDu, 0);
  *(__m128 *)&r_rslt_36[240] = Four_Zeros;
  *(__m128 *)&r_rslt_36[400] = Four_Zeros;
  v9 = 0;
  p_m_nColumns = &m_pIncrementalInfo->m_CalculatedContribution.m_nColumns;
  v9.m128_f32[0] = l->m_flJitterAmount;
  *(__m128 *)&r_rslt_36[256] = Four_Zeros;
  *(__m128 *)&r_rslt_36[416] = Four_Zeros;
  x = (int)p_m_nColumns;
  v59 = _mm_shuffle_ps(v9, v9, 0);
  HIBYTE(nCtx) = v9.m128_f32[0] > 0.0;
  SIMDRandContext = GetSIMDRandContext();
  v12 = !l->m_bLowRes;
  idx = SIMDRandContext;
  if ( v12 )
  {
    v67 = &pAlbedo->x.m128_i32[1];
    v13 = &pAlbedo->x.m128_i32[1];
  }
  else
  {
    v13 = &pAlbedo[16].z.m128_i32[2];
    v67 = &pAlbedo[16].z.m128_i32[2];
  }
  v62 = nLineStart;
  if ( nLineStart <= nLineEnd )
  {
    while ( 1 )
    {
      m_nFirstCalculatedLine = InsideOut(nTotal: p_m_nColumns[1], nCounter: v62);
      v15 = (CSOAContainer *)(p_m_nColumns[6] + m_nFirstCalculatedLine * p_m_nColumns[102]);
      v16 = (_OWORD *)(v13[6] + m_nFirstCalculatedLine * v13[102]);
      v17 = *(__m128 *)&r_rslt_36[240];
      v18 = *(__m128 *)&r_rslt_36[256];
      v19 = *(__m128 *)&r_rslt_36[272];
      rslt = v15;
      v20 = v13[7] + m_nFirstCalculatedLine * v13[103];
      v21 = (_OWORD *)(v67[8] + m_nFirstCalculatedLine * v13[104]);
      v61 = (__m128 *)v20;
      v22 = *(_DWORD *)(x + 16) <= 0;
      v58 = m_nFirstCalculatedLine;
      *(_OWORD *)&r_rslt_36[352] = *(_OWORD *)&r_rslt_36[240];
      *(_OWORD *)&r_rslt_36[368] = *(_OWORD *)&r_rslt_36[256];
      *(_OWORD *)&r_rslt_36[384] = *(_OWORD *)&r_rslt_36[272];
      v60 = 0;
      if ( !v22 )
      {
        do
        {
          *(_OWORD *)&r_rslt_36[192] = *v16;
          *(_OWORD *)&r_rslt_36[208] = v16[1];
          *(_OWORD *)&r_rslt_36[224] = v16[2];
          *(_OWORD *)&r_rslt_36[128] = *v21;
          *(_OWORD *)&r_rslt_36[144] = v21[1];
          *(_OWORD *)&r_rslt_36[160] = v21[2];
          *(_OWORD *)&r_rslt_36[448] = *(_OWORD *)&r_rslt_36[240];
          *(_OWORD *)&r_rslt_36[464] = *(_OWORD *)&r_rslt_36[256];
          v16 += 3;
          v21 += 3;
          *(_OWORD *)&r_rslt_36[480] = *(_OWORD *)&r_rslt_36[272];
          LightDesc_t::ComputeLightAtPoints(
            this: l,
            pos: (const FourVectors *)&r_rslt_36[192],
            normal: (const FourVectors *)&r_rslt_36[128],
            color: (FourVectors *)&r_rslt_36[448],
            DoHalfLambert: false);
          v23 = *(__m128 *)&r_rslt_36[480];
          v24 = *(_OWORD *)&r_rslt_36[464];
          if ( _mm_movemask_ps(
                 _mm_cmpeq_ps(
                   _mm_or_ps(
                     _mm_or_ps(*(__m128 *)&r_rslt_36[480], *(__m128 *)&r_rslt_36[464]),
                     *(__m128 *)&r_rslt_36[448]),
                   Four_Zeros)) == 15 )
          {
            v40 = rslt;
            v44 = v61;
            *(_OWORD *)&rslt->m_nColumns = *(_OWORD *)&r_rslt_36[448];
            v17 = *(__m128 *)&r_rslt_36[352];
            *(_OWORD *)&v40->m_nNumQuadsPerRow = v24;
            v19 = *(__m128 *)&r_rslt_36[384];
            *(__m128 *)&v40->m_pAttributePtrs[2] = v23;
            v18 = *(__m128 *)&r_rslt_36[368];
          }
          else
          {
            v26 = _mm_shuffle_ps((__m128)LODWORD(l->m_Position.x), (__m128)LODWORD(l->m_Position.x), 0);
            v27 = _mm_shuffle_ps((__m128)LODWORD(l->m_Position.y), (__m128)LODWORD(l->m_Position.y), 0);
            v28 = _mm_shuffle_ps((__m128)LODWORD(l->m_Position.z), (__m128)LODWORD(l->m_Position.z), 0);
            *(__m128 *)&r_rslt_36[288] = v26;
            *(__m128 *)&r_rslt_36[304] = v27;
            *(__m128 *)&r_rslt_36[320] = v28;
            if ( HIBYTE(nCtx) != 0 )
            {
              RandSIMD(result: (__m128 *)idx, nContextIndex: v56);
              v29 = _mm_add_ps(
                      _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v23, Four_Twos), Four_Ones), v59),
                      *(__m128 *)&r_rslt_36[288]);
              *(__m128 *)&r_rslt_36[288] = v29;
              RandSIMD(result: (__m128 *)idx, nContextIndex: v55);
              v30 = _mm_add_ps(
                      _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v29, Four_Twos), Four_Ones), v59),
                      *(__m128 *)&r_rslt_36[304]);
              *(__m128 *)&r_rslt_36[304] = v30;
              RandSIMD(result: (__m128 *)idx, nContextIndex: v54);
              v27 = *(__m128 *)&r_rslt_36[304];
              v26 = *(__m128 *)&r_rslt_36[288];
              v28 = _mm_add_ps(
                      _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(Four_Twos, v30), Four_Ones), v59),
                      *(__m128 *)&r_rslt_36[320]);
            }
            v31 = _mm_sub_ps(v26, *(__m128 *)&r_rslt_36[192]);
            v32 = _mm_sub_ps(v27, *(__m128 *)&r_rslt_36[208]);
            v33 = _mm_sub_ps(v28, *(__m128 *)&r_rslt_36[224]);
            v34 = _mm_sqrt_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v31, v31), _mm_mul_ps(v32, v32)), _mm_mul_ps(v33, v33)));
            v35 = _mm_rcp_ps(v34);
            v36 = _mm_sub_ps(_mm_add_ps(v35, v35), _mm_mul_ps(_mm_mul_ps(v35, v35), v34));
            *(__m128 *)&r_rslt_36[176] = v34;
            v37 = _mm_shuffle_ps((__m128)0x3CA3D70Au, (__m128)0x3CA3D70Au, 0);
            *(__m128 *)&r_rslt_36[96] = _mm_mul_ps(v32, v36);
            *(__m128 *)&r_rslt_36[112] = _mm_mul_ps(v33, v36);
            *(__m128 *)&r_rslt_36[80] = _mm_mul_ps(v31, v36);
            v38 = (RayTracingEnvironment *)pAlbedo[33].y.m128_i32[3];
            *(__m128 *)&r_rslt_36[32] = _mm_add_ps(
                                          _mm_mul_ps(v37, *(__m128 *)&r_rslt_36[80]),
                                          *(__m128 *)&r_rslt_36[192]);
            *(__m128 *)&r_rslt_36[48] = _mm_add_ps(
                                          _mm_mul_ps(*(__m128 *)&r_rslt_36[96], v37),
                                          *(__m128 *)&r_rslt_36[208]);
            *(__m128 *)&r_rslt_36[64] = _mm_add_ps(
                                          _mm_mul_ps(*(__m128 *)&r_rslt_36[112], v37),
                                          *(__m128 *)&r_rslt_36[224]);
            RayTracingEnvironment::Trace4Rays(
              this: v38,
              TMin: Four_Zeros,
              TMax: _mm_shuffle_ps((__m128)0x4E6E6B28u, (__m128)0x4E6E6B28u, 0));
            for ( i = 0; i < 16; i += 4 )
            {
              if ( *(_DWORD *)&r_rslt_36[i] != -1 && *(float *)&r_rslt_36[i + 176] > *(float *)&r_rslt_36[i + 16] )
              {
                *(_DWORD *)&r_rslt_36[i + 448] = 0;
                *(_DWORD *)&r_rslt_36[i + 464] = 0;
                *(_DWORD *)&r_rslt_36[i + 480] = 0;
              }
            }
            v40 = rslt;
            v41 = *(__m128 *)&r_rslt_36[448];
            v42 = *(__m128 *)&r_rslt_36[464];
            v43 = *(__m128 *)&r_rslt_36[480];
            v44 = v61;
            v45 = *(__m128 *)&r_rslt_36[336];
            *(_OWORD *)&rslt->m_nColumns = *(_OWORD *)&r_rslt_36[448];
            *(__m128 *)&v40->m_nNumQuadsPerRow = v42;
            *(__m128 *)&v40->m_pAttributePtrs[2] = v43;
            v46 = _mm_mul_ps(*v44, v41);
            v47 = _mm_mul_ps(v44[1], v42);
            v48 = _mm_mul_ps(v44[2], v43);
            v49 = _mm_and_ps(_mm_cmplt_ps(v45, v46), v46);
            v18 = _mm_add_ps(_mm_and_ps(_mm_cmplt_ps(v45, v47), v47), *(__m128 *)&r_rslt_36[368]);
            v19 = _mm_add_ps(_mm_and_ps(_mm_cmplt_ps(v45, v48), v48), *(__m128 *)&r_rslt_36[384]);
            v17 = _mm_add_ps(*(__m128 *)&r_rslt_36[352], v49);
            *(__m128 *)&r_rslt_36[352] = v17;
            *(__m128 *)&r_rslt_36[368] = v18;
            *(__m128 *)&r_rslt_36[384] = v19;
          }
          rslt = (CSOAContainer *)&v40->m_pAttributePtrs[6];
          v61 = v44 + 3;
          ++v60;
        }
        while ( v60 < *(_DWORD *)(x + 16) );
        m_nFirstCalculatedLine = v58;
      }
      pLInfo->m_nCalculationLevel[m_nFirstCalculatedLine] = 1;
      m_nMaxCalculatedLine = pLInfo->m_nMaxCalculatedLine;
      if ( m_nFirstCalculatedLine > m_nMaxCalculatedLine )
        m_nMaxCalculatedLine = m_nFirstCalculatedLine;
      pLInfo->m_nMaxCalculatedLine = m_nMaxCalculatedLine;
      if ( m_nFirstCalculatedLine >= pLInfo->m_nFirstCalculatedLine )
        m_nFirstCalculatedLine = pLInfo->m_nFirstCalculatedLine;
      v51 = _mm_add_ps(v17, *(__m128 *)&r_rslt_36[400]);
      v52 = _mm_add_ps(v18, *(__m128 *)&r_rslt_36[416]);
      v53 = _mm_add_ps(v19, *(__m128 *)&r_rslt_36[432]);
      pLInfo->m_nFirstCalculatedLine = m_nFirstCalculatedLine;
      *(__m128 *)&r_rslt_36[400] = v51;
      *(__m128 *)&r_rslt_36[416] = v52;
      *(__m128 *)&r_rslt_36[432] = v53;
      if ( ++v62 > nLineEnd )
        break;
      v13 = v67;
      p_m_nColumns = (int *)x;
    }
  }
  ReleaseSIMDRandContext(nContext: idx);
  *(__m128 *)&r_rslt_36[336] = _mm_mul_ps(*(__m128 *)&r_rslt_36[416], *(__m128 *)&r_rslt_36[416]);
  v59 = _mm_sqrt_ps(
          _mm_add_ps(
            _mm_add_ps(*(__m128 *)&r_rslt_36[336], _mm_mul_ps(*(__m128 *)&r_rslt_36[400], *(__m128 *)&r_rslt_36[400])),
            _mm_mul_ps(*(__m128 *)&r_rslt_36[432], *(__m128 *)&r_rslt_36[432])));
  *fContributionOut = (float)((float)(v59.m128_f32[1] + v59.m128_f32[0]) + v59.m128_f32[2]) + v59.m128_f32[3];
}

//------------------------------------------------------------------------------
// Address: 0x10050CB0
// Name: public: void CMessageQueue<struct MessageToLPreview>::WaitMessage(struct MessageToLPreview __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageQueue<MessageToLPreview>::WaitMessage(
        CMessageQueue<MessageToLPreview> *this,
        MessageToLPreview *pMsg)
{
  CMessageQueue<MessageToLPreview>::MsgNode *Head; // edi
  CMessageQueue<MessageToLPreview>::MsgNode *Next; // eax

  while ( 1 )
  {
    while ( this->Head == nullptr )
      CThreadEvent::Wait(this: &this->SignalEvent, a2: 0xFFFFFFFF);
    CThreadMutex::Lock(this: &this->QueueAccessMutex);
    if ( this->Head != nullptr )
      break;
    CThreadMutex::Unlock(this: &this->QueueAccessMutex);
  }
  MessageToLPreview::operator=(this: pMsg, __that: &this->Head->Data);
  Head = this->Head;
  Next = Head->Next;
  this->Head = Head->Next;
  if ( Next == nullptr )
    this->Tail = nullptr;
  CThreadMutex::Unlock(this: &this->QueueAccessMutex);
  operator delete(p: Head);
}

//------------------------------------------------------------------------------
// Address: 0x10050D30
// Name: public: virtual CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::~CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::~CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  this->CFunctor::IRefCounted::__vftable = (CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >_vtbl *)&CFunctor::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10050D70
// Name: private: void CParallelProcessor<class CPresetSlider __near *,class CFuncJobItemProcessor<class CPresetSlider __near *>,1>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::DoExecute(
        CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *this)
{
  void (*m_pfnBegin)(void); // eax
  CPresetSlider **m_pLimit; // ecx
  unsigned int v4; // edx
  CPresetSlider **v5; // esi
  CPresetSlider **v6; // edi
  void (*m_pfnEnd)(void); // ebx
  unsigned int v8; // [esp+4h] [ebp-8h]
  CPresetSlider **pLimit; // [esp+8h] [ebp-4h]

  if ( this->m_pItems.m_value < this->m_pLimit )
  {
    m_pfnBegin = this->m_ItemProcessor.m_pfnBegin;
    if ( m_pfnBegin != nullptr )
      m_pfnBegin();
    m_pLimit = this->m_pLimit;
    v4 = 4 * this->m_nChunkSize;
    pLimit = m_pLimit;
    v8 = v4;
    do
    {
      v5 = (CPresetSlider **)_InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pItems, v4);
      v6 = (CPresetSlider **)((char *)v5 + v4);
      if ( m_pLimit < (CPresetSlider **)((char *)v5 + v4) )
        v6 = m_pLimit;
      if ( v5 < v6 )
      {
        do
          this->m_ItemProcessor.m_pfnProcess(a1: v5++);
        while ( v5 < v6 );
        m_pLimit = pLimit;
        v4 = v8;
      }
    }
    while ( v5 < m_pLimit );
    m_pfnEnd = this->m_ItemProcessor.m_pfnEnd;
    if ( m_pfnEnd != nullptr )
      m_pfnEnd();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050DE0
// Name: public: CUtlBlockMemory<struct CacheOptimizedTriangle,int>::~CUtlBlockMemory<struct CacheOptimizedTriangle,int>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBlockMemory<CacheOptimizedTriangle,int>::~CUtlBlockMemory<CacheOptimizedTriangle,int>(
        CUtlBlockMemory<CUtlReference<CMapClass>,int> *this)
{
  int i; // edi
  CUtlReference<CMapClass> **m_pMemory; // [esp-8h] [ebp-Ch]

  if ( this->m_pMemory != nullptr )
  {
    for ( i = 0; i < this->m_nBlocks; ++i )
      free(pMem: this->m_pMemory[i]);
    m_pMemory = this->m_pMemory;
    this->m_nBlocks = 0;
    free(pMem: m_pMemory);
    this->m_pMemory = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050E20
// Name: public: void CLightingPreviewThread::HandleGBuffersMessage(struct MessageToLPreview __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightingPreviewThread::HandleGBuffersMessage(CLightingPreviewThread *this, MessageToLPreview *msg_in)
{
  CSOAContainer *p_m_GBuffer; // esi
  FloatBitMap_t **m_pDefferedRenderingBMs; // edi
  CSOAContainer *p; // [esp+Ch] [ebp-10h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF
  int msg_ina; // [esp+24h] [ebp+8h]

  p_m_GBuffer = &this->m_GBuffer;
  CSOAContainer::Purge(this: &this->m_GBuffer);
  CSOAContainer::SetAttributeType(this: p_m_GBuffer, nAttrIdx: 0, nDataType: ATTRDATATYPE_4V, bAllocateMemory: true);
  CSOAContainer::SetAttributeType(this: p_m_GBuffer, nAttrIdx: 1, nDataType: ATTRDATATYPE_4V, bAllocateMemory: true);
  CSOAContainer::SetAttributeType(this: p_m_GBuffer, nAttrIdx: 2, nDataType: ATTRDATATYPE_4V, bAllocateMemory: true);
  CSOAContainer::AllocateData(
    this: p_m_GBuffer,
    nNCols: msg_in->m_pDefferedRenderingBMs[0]->m_nColumns,
    nNRows: msg_in->m_pDefferedRenderingBMs[0]->m_nRows,
    nSlices: 1);
  CSOAContainer::PackScalarAttributesToVectorAttribute(
    this: p_m_GBuffer,
    pInput: msg_in->m_pDefferedRenderingBMs[0],
    nVecAttributeOut: 1,
    nScalarAttributeX: 0,
    nScalarAttributeY: 1,
    nScalarAttributeZ: 2);
  CSOAContainer::PackScalarAttributesToVectorAttribute(
    this: p_m_GBuffer,
    pInput: msg_in->m_pDefferedRenderingBMs[1],
    nVecAttributeOut: 2,
    nScalarAttributeX: 0,
    nScalarAttributeY: 1,
    nScalarAttributeZ: 2);
  CSOAContainer::PackScalarAttributesToVectorAttribute(
    this: p_m_GBuffer,
    pInput: msg_in->m_pDefferedRenderingBMs[2],
    nVecAttributeOut: 0,
    nScalarAttributeX: 0,
    nScalarAttributeY: 1,
    nScalarAttributeZ: 2);
  CSOAContainer::Purge(this: &this->m_GBufferLowRes);
  CSOAContainer::SetAttributeType(
    this: &this->m_GBufferLowRes,
    nAttrIdx: 0,
    nDataType: ATTRDATATYPE_4V,
    bAllocateMemory: true);
  CSOAContainer::SetAttributeType(
    this: &this->m_GBufferLowRes,
    nAttrIdx: 1,
    nDataType: ATTRDATATYPE_4V,
    bAllocateMemory: true);
  CSOAContainer::SetAttributeType(
    this: &this->m_GBufferLowRes,
    nAttrIdx: 2,
    nDataType: ATTRDATATYPE_4V,
    bAllocateMemory: true);
  CSOAContainer::AllocateData(
    this: &this->m_GBufferLowRes,
    nNCols: msg_in->m_pDefferedRenderingBMs[0]->m_nColumns / 4,
    nNRows: msg_in->m_pDefferedRenderingBMs[0]->m_nRows / 4,
    nSlices: 1);
  CSOAContainer::ResampleAttribute(this: &this->m_GBufferLowRes, src: p_m_GBuffer, nAttr: 0);
  CSOAContainer::ResampleAttribute(this: &this->m_GBufferLowRes, src: p_m_GBuffer, nAttr: 1);
  CSOAContainer::ResampleAttribute(this: &this->m_GBufferLowRes, src: p_m_GBuffer, nAttr: 2);
  m_pDefferedRenderingBMs = msg_in->m_pDefferedRenderingBMs;
  this->m_LastEyePosition = msg_in->m_EyePosition;
  for ( msg_ina = 4; msg_ina != 0; --msg_ina )
  {
    p = *m_pDefferedRenderingBMs;
    if ( *m_pDefferedRenderingBMs != nullptr )
    {
      CSOAContainer::~CSOAContainer(this: *m_pDefferedRenderingBMs);
      operator delete(p);
    }
    ++m_pDefferedRenderingBMs;
  }
  _InterlockedExchangeAdd(&n_gbufs_queued.m_value, 0xFFFFFFFF);
  this->m_nBitmapGenerationCounter = msg_in->m_nBitmapGenerationCounter;
  CLightingPreviewThread::CalculateSceneBounds(this, a2: (int)&savedregs);
}

//------------------------------------------------------------------------------
// Address: 0x10050FE0
// Name: public: void CLightingPreviewThread::SendResultRendering(class CSOAContainer __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CLightingPreviewThread::SendResultRendering(
        CLightingPreviewThread *this@<ecx>,
        unsigned int a2@<ebx>,
        unsigned int a3@<edi>,
        CSOAContainer *rsltBuffer)
{
  int *v4; // eax
  int *v5; // esi
  CSOAContainer *v6; // edi
  int m_nRows; // ebx
  const ImageFormatInfo_t *v8; // eax
  void *v9; // eax
  int v10; // ebx
  float *v11; // eax
  int v12; // edi
  double v13; // xmm0_8
  double v14; // xmm0_8
  _BYTE *v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int m_nBitmapGenerationCounter; // edi
  char *v20; // esi
  long double v21; // [esp-8h] [ebp-44h]
  long double v22; // [esp-8h] [ebp-44h]
  long double v23; // [esp-8h] [ebp-44h]
  long double v24; // [esp+0h] [ebp-3Ch]
  long double v25; // [esp+0h] [ebp-3Ch]
  long double v26; // [esp+0h] [ebp-3Ch]
  __int64 ret_msg; // [esp+4h] [ebp-38h]
  double ret_msg_4; // [esp+8h] [ebp-34h]
  double v29; // [esp+10h] [ebp-2Ch]
  double v30; // [esp+18h] [ebp-24h]
  float p; // [esp+24h] [ebp-18h]
  float v33; // [esp+28h] [ebp-14h]
  int pRGBData; // [esp+2Ch] [ebp-10h]
  const float *pRGBDataa; // [esp+2Ch] [ebp-10h]

  v4 = (int *)operator new(nSize: 0x10u);
  if ( v4 != nullptr )
  {
    *v4 = 0;
    v4[1] = 0;
    v4[2] = -1;
    v4[3] = 0;
    v5 = v4;
  }
  else
  {
    v5 = nullptr;
  }
  v21 = COERCE_DOUBLE(__PAIR64__(a2, a3));
  v6 = rsltBuffer;
  m_nRows = rsltBuffer->m_nRows;
  pRGBData = rsltBuffer->m_nColumns;
  if ( v5[3] != 0 )
  {
    operator delete(p: (void *)v5[3]);
    v5[3] = 0;
  }
  *v5 = pRGBData;
  v5[1] = m_nRows;
  v5[2] = 0;
  v8 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888);
  v9 = operator new[](nSize: m_nRows * pRGBData * v8->m_nNumBytes);
  v10 = 0;
  v5[3] = (int)v9;
  if ( v5[1] > 0 )
  {
    while ( 1 )
    {
      v11 = (float *)&v6->m_pAttributePtrs[3][v10 * v6->m_nRowStrideInBytes[3]];
      v12 = 0;
      pRGBDataa = v11;
      if ( *v5 > 0 )
      {
        while ( 1 )
        {
          p = *v11;
          v33 = v11[4];
          v13 = v11[8];
          __libm_sse2_pow(x: v21, y: v24);
          *(float *)&v13 = v13;
          v14 = *(float *)&v13 * 255.0;
          if ( v14 <= 255.0 )
            v30 = v14;
          else
            v30 = 255.0;
          if ( v5[3] != 0 )
            v15 = (_BYTE *)(v5[3]
                          + ImageLoader::ImageFormatInfo(fmt: (ImageFormat)v5[2])->m_nNumBytes * (v12 + v10 * *v5));
          else
            v15 = nullptr;
          *v15 = (int)v30;
          __libm_sse2_pow(x: v22, y: v25);
          if ( v33 * 255.0 <= 255.0 )
            v29 = v33 * 255.0;
          else
            v29 = 255.0;
          if ( v5[3] != 0 )
            v16 = v5[3] + ImageLoader::ImageFormatInfo(fmt: (ImageFormat)v5[2])->m_nNumBytes * (v12 + v10 * *v5);
          else
            v16 = 0;
          *(_BYTE *)(v16 + 1) = (int)v29;
          __libm_sse2_pow(x: v23, y: v26);
          if ( p * 255.0 <= 255.0 )
            ret_msg_4 = p * 255.0;
          else
            ret_msg_4 = 255.0;
          if ( v5[3] != 0 )
            v17 = v5[3] + ImageLoader::ImageFormatInfo(fmt: (ImageFormat)v5[2])->m_nNumBytes * (v12 + v10 * *v5);
          else
            v17 = 0;
          *(_BYTE *)(v17 + 2) = (int)ret_msg_4;
          if ( v5[3] != 0 )
            v18 = v5[3] + ImageLoader::ImageFormatInfo(fmt: (ImageFormat)v5[2])->m_nNumBytes * (v12 + v10 * *v5);
          else
            v18 = 0;
          ++pRGBDataa;
          *(_BYTE *)(v18 + 3) = 0;
          if ( (v12 & 3) == 3 )
            pRGBDataa += 8;
          if ( ++v12 >= *v5 )
            break;
          v11 = (float *)pRGBDataa;
        }
      }
      if ( ++v10 >= v5[1] )
        break;
      v6 = rsltBuffer;
    }
  }
  m_nBitmapGenerationCounter = this->m_nBitmapGenerationCounter;
  LODWORD(ret_msg) = 0;
  HIDWORD(ret_msg) = v5;
  v20 = (char *)operator new(nSize: 0x10u);
  *(_QWORD *)(v20 + 4) = ret_msg;
  *((_DWORD *)v20 + 3) = m_nBitmapGenerationCounter;
  *(_DWORD *)v20 = 0;
  CThreadMutex::Lock(this: &g_LPreviewToHammerMsgQueue.QueueAccessMutex);
  if ( g_LPreviewToHammerMsgQueue.Tail != nullptr )
    g_LPreviewToHammerMsgQueue.Tail->Next = (CMessageQueue<MessageFromLPreview>::MsgNode *)v20;
  else
    g_LPreviewToHammerMsgQueue.Head = (CMessageQueue<MessageFromLPreview>::MsgNode *)v20;
  g_LPreviewToHammerMsgQueue.Tail = (CMessageQueue<MessageFromLPreview>::MsgNode *)v20;
  CThreadEvent::Set(this: &g_LPreviewToHammerMsgQueue.SignalEvent);
  CThreadMutex::Unlock(this: &g_LPreviewToHammerMsgQueue.QueueAccessMutex);
}

//------------------------------------------------------------------------------
// Address: 0x100512F0
// Name: void HandleLightingPreview(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HandleLightingPreview()
{
  CLightingPreviewResultsWindow *m_pLightingPreviewOutputWindow; // eax
  unsigned __int8 **p_m_pBits; // esi
  Bitmap_t *v2; // edi
  unsigned __int8 *m_pBits; // eax
  CLightingPreviewResultsWindow *v4; // esi
  CLightingPreviewResultsWindow *v5; // eax
  CMainFrame *MainWnd; // eax
  CLightingPreviewResultsWindow_vtbl *v7; // eax
  tagRECT existing_rect; // [esp+4h] [ebp-3Ch] BYREF
  CRect myRect; // [esp+14h] [ebp-2Ch] BYREF
  MessageFromLPreview msg; // [esp+24h] [ebp-1Ch] BYREF
  CLightingPreviewResultsWindow *v11; // [esp+30h] [ebp-10h]
  int v12; // [esp+3Ch] [ebp-4h]

  if ( GetMainWnd()->m_pLightingPreviewOutputWindow != nullptr && !GetMainWnd()->m_bLightingPreviewOutputWindowShowing )
  {
    m_pLightingPreviewOutputWindow = GetMainWnd()->m_pLightingPreviewOutputWindow;
    if ( m_pLightingPreviewOutputWindow != nullptr )
      ((void (__thiscall *)(CLightingPreviewResultsWindow *, int))m_pLightingPreviewOutputWindow->dtr_CObject)(
        a1: m_pLightingPreviewOutputWindow,
        a2: 1);
    GetMainWnd()->m_pLightingPreviewOutputWindow = nullptr;
  }
  while ( g_LPreviewToHammerMsgQueue.Head != nullptr )
  {
    CMessageQueue<MessageFromLPreview>::WaitMessage(this: &g_LPreviewToHammerMsgQueue, pMsg: &msg);
    if ( msg.m_MsgType == LPREVIEW_MSG_DISPLAY_RESULT )
    {
      _InterlockedExchangeAdd(&n_result_bms_queued.m_value, 0xFFFFFFFF);
      if ( g_pLPreviewOutputBitmap != nullptr )
      {
        p_m_pBits = &g_pLPreviewOutputBitmap->m_pBits;
        v2 = g_pLPreviewOutputBitmap;
        m_pBits = g_pLPreviewOutputBitmap->m_pBits;
        if ( m_pBits != nullptr )
        {
          operator delete(p: m_pBits);
          *p_m_pBits = nullptr;
        }
        operator delete(p: v2);
      }
      g_pLPreviewOutputBitmap = msg.m_pBitmapToDisplay;
      if ( msg.m_pBitmapToDisplay != nullptr && msg.m_pBitmapToDisplay->m_nWidth > 10 )
      {
        SignalUpdate(ev: 2);
        v4 = GetMainWnd()->m_pLightingPreviewOutputWindow;
        if ( !GetMainWnd()->m_bLightingPreviewOutputWindowShowing )
        {
          v5 = (CLightingPreviewResultsWindow *)operator new(nSize: 0x74u);
          v11 = v5;
          v12 = 0;
          if ( v5 != nullptr )
            v4 = CLightingPreviewResultsWindow::CLightingPreviewResultsWindow(this: v5);
          else
            v4 = nullptr;
          v12 = -1;
          GetMainWnd()->m_pLightingPreviewOutputWindow = v4;
          MainWnd = GetMainWnd();
          CLightingPreviewResultsWindow::Create(this: v4, pParentWnd: MainWnd);
          GetMainWnd()->m_bLightingPreviewOutputWindowShowing = true;
        }
        if ( !IsWindowVisible(hWnd: v4->m_hWnd) )
          CWnd::ShowWindow(this: v4, nCmdShow: 5);
        GetClientRect(hWnd: v4->m_hWnd, lpRect: &existing_rect);
        if ( existing_rect.right != g_pLPreviewOutputBitmap->m_nWidth - 1
          || existing_rect.bottom != g_pLPreviewOutputBitmap->m_nHeight - 1 )
        {
          memset(&myRect, 0, sizeof(myRect));
          myRect.right = g_pLPreviewOutputBitmap->m_nWidth - 1;
          v7 = v4->__vftable;
          myRect.bottom = g_pLPreviewOutputBitmap->m_nHeight - 1;
          v7->CalcWindowRect(this: v4, a2: &myRect, a3: 0);
          CWnd::SetWindowPos(
            this: v4,
            pWndInsertAfter: nullptr,
            x: 0,
            y: 0,
            cx: myRect.right - myRect.left,
            cy: myRect.bottom - myRect.top,
            nFlags: 6u);
        }
        InvalidateRect(hWnd: v4->m_hWnd, lpRect: nullptr, bErase: false);
        UpdateWindow(hWnd: v4->m_hWnd);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100514F0
// Name: public: void CUtlBlockMemory<struct CacheOptimizedTriangle,int>::Init(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBlockMemory<CacheOptimizedTriangle,int>::Init(
        CUtlBlockMemory<CacheOptimizedTriangle,int> *this,
        int nGrowSize,
        int nInitSize)
{
  int i; // edi
  int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  int v8; // ecx
  unsigned int v9; // eax
  CacheOptimizedTriangle **m_pMemory; // [esp-8h] [ebp-Ch]

  if ( this->m_pMemory != nullptr )
  {
    for ( i = 0; i < this->m_nBlocks; ++i )
      free(pMem: this->m_pMemory[i]);
    m_pMemory = this->m_pMemory;
    this->m_nBlocks = 0;
    free(pMem: m_pMemory);
    this->m_pMemory = nullptr;
  }
  v5 = nGrowSize;
  if ( nGrowSize == 0 )
    v5 = 3;
  v6 = ((((unsigned int)(v5 - 1) >> 1) | (v5 - 1)) >> 2) | ((unsigned int)(v5 - 1) >> 1) | (v5 - 1);
  v7 = (v6 >> 4) | v6;
  v8 = ((v7 >> 8) | v7 | (((v7 >> 8) | v7) >> 16)) + 1;
  v9 = (v7 >> 8) | v7 & 0x7FFFFFF | (((v7 >> 8) | v7) >> 16);
  *((_DWORD *)this + 2) = v9;
  if ( v8 > 1 )
  {
    do
    {
      v8 >>= 1;
      v9 = ((v9 & 0xF8000000) + 0x8000000) ^ v9 & 0x7FFFFFF;
    }
    while ( v8 > 1 );
    *((_DWORD *)this + 2) = v9;
  }
  if ( nInitSize > 0 )
    CUtlBlockMemory<CacheOptimizedTriangle,int>::ChangeSize(
      this,
      nBlocks: this->m_nBlocks + (((32 * *((_DWORD *)this + 2)) >> 5) + nInitSize) / (((32 * *((_DWORD *)this + 2)) >> 5) + 1));
}

//------------------------------------------------------------------------------
// Address: 0x100515D0
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x100515E0
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10051610
// Name: public: virtual void CMemberFunctor0<class CParallelProcessor<int,class CFuncJobItemProcessor<int>,1> __near *,void (CParallelProcessor<int,class CFuncJobItemProcessor<int>,1>::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<CParallelProcessor<int,CFuncJobItemProcessor<int>,1> *,void (__thiscall CParallelProcessor<int,CFuncJobItemProcessor<int>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10051830
// Name: public: class CJob __near * IThreadPool::QueueCall<class CParallelProcessor<class CLightingPreviewLightDescription __near *,class CFuncJobItemProcessor<class CLightingPreviewLightDescription __near *>,1>,class CParallelProcessor<class CLightingPreviewLightDescription __near *,class CFuncJobItemProcessor<class CLightingPreviewLightDescription __near *>,1>,void>(class CParallelProcessor<class CLightingPreviewLightDescription __near *,class CFuncJobItemProcessor<class CLightingPreviewLightDescription __near *>,1> __near *,void (CParallelProcessor<class CLightingPreviewLightDescription __near *,class CFuncJobItemProcessor<class CLightingPreviewLightDescription __near *>,1>::*)(void))
// Source: json
//------------------------------------------------------------------------------
CJob *__thiscall IThreadPool::QueueCall<CParallelProcessor<CLightingPreviewLightDescription *,CFuncJobItemProcessor<CLightingPreviewLightDescription *>,1>,CParallelProcessor<CLightingPreviewLightDescription *,CFuncJobItemProcessor<CLightingPreviewLightDescription *>,1>,void>(
        IThreadPool *this,
        CParallelProcessor<CLightingPreviewLightDescription *,CFuncJobItemProcessor<CLightingPreviewLightDescription *>,1> *pObject,
        void (__thiscall *pfnProxied)(CParallelProcessor<CLightingPreviewLightDescription *,CFuncJobItemProcessor<CLightingPreviewLightDescription *>,1> *this))
{
  CFunctor *v4; // eax
  CJob *pJob; // [esp+Ch] [ebp-10h] BYREF
  int v7; // [esp+18h] [ebp-4h]

  v4 = (CFunctor *)operator new(nSize: 0x18u);
  v7 = 0;
  if ( v4 != nullptr )
  {
    v4->__vftable = (CFunctor_vtbl *)&CFunctor::`vftable';
    v4[1].m_nUserID = 1;
    v4->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CLightingPreviewLightDescription *,CFuncJobItemProcessor<CLightingPreviewLightDescription *>,1> *,void (__thiscall CParallelProcessor<CLightingPreviewLightDescription *,CFuncJobItemProcessor<CLightingPreviewLightDescription *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v4[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CLightingPreviewLightDescription *,CFuncJobItemProcessor<CLightingPreviewLightDescription *>,1> *,void (__thiscall CParallelProcessor<CLightingPreviewLightDescription *,CFuncJobItemProcessor<CLightingPreviewLightDescription *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v4[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v4[2].m_nUserID = (unsigned int)pObject;
    LOBYTE(v7) = 0;
  }
  else
  {
    v4 = nullptr;
  }
  v7 = -1;
  this->AddFunctorInternal(this, a2: v4, a3: &pJob, a4: nullptr, a5: 8u);
  return pJob;
}

//------------------------------------------------------------------------------
// Address: 0x100518D0
// Name: public: class CJob __near * IThreadPool::QueueCall<class CParallelProcessor<int,class CFuncJobItemProcessor<int>,1>,class CParallelProcessor<int,class CFuncJobItemProcessor<int>,1>,void>(class CParallelProcessor<int,class CFuncJobItemProcessor<int>,1> __near *,void (CParallelProcessor<int,class CFuncJobItemProcessor<int>,1>::*)(void))
// Source: json
//------------------------------------------------------------------------------
CJob *__thiscall IThreadPool::QueueCall<CParallelProcessor<int,CFuncJobItemProcessor<int>,1>,CParallelProcessor<int,CFuncJobItemProcessor<int>,1>,void>(
        IThreadPool *this,
        CParallelProcessor<int,CFuncJobItemProcessor<int>,1> *pObject,
        void (__thiscall *pfnProxied)(CParallelProcessor<int,CFuncJobItemProcessor<int>,1> *this))
{
  CFunctor *v4; // eax
  CJob *pJob; // [esp+Ch] [ebp-10h] BYREF
  int v7; // [esp+18h] [ebp-4h]

  v4 = (CFunctor *)operator new(nSize: 0x18u);
  v7 = 0;
  if ( v4 != nullptr )
  {
    v4->__vftable = (CFunctor_vtbl *)&CFunctor::`vftable';
    v4[1].m_nUserID = 1;
    v4->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<int,CFuncJobItemProcessor<int>,1> *,void (__thiscall CParallelProcessor<int,CFuncJobItemProcessor<int>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v4[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<int,CFuncJobItemProcessor<int>,1> *,void (__thiscall CParallelProcessor<int,CFuncJobItemProcessor<int>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v4[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v4[2].m_nUserID = (unsigned int)pObject;
    LOBYTE(v7) = 0;
  }
  else
  {
    v4 = nullptr;
  }
  v7 = -1;
  this->AddFunctorInternal(this, a2: v4, a3: &pJob, a4: nullptr, a5: 8u);
  return pJob;
}

//------------------------------------------------------------------------------
// Address: 0x10051970
// Name: public: CLightingPreviewLightDescription::CLightingPreviewLightDescription(void)
// Source: json
//------------------------------------------------------------------------------
CLightingPreviewLightDescription *__thiscall CLightingPreviewLightDescription::CLightingPreviewLightDescription(
        CLightingPreviewLightDescription *this)
{
  CLightingPreviewLightDescription **m_pMemory; // esi

  this->m_TempChildren.m_Memory.m_pMemory = nullptr;
  this->m_TempChildren.m_Memory.m_nAllocationCount = 0;
  this->m_TempChildren.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_TempChildren.m_Memory.m_pMemory;
  this->m_TempChildren.m_Size = 0;
  this->m_TempChildren.m_pElements = m_pMemory;
  this->m_flJitterAmount = 0.0;
  *(_WORD *)&this->m_bLowRes = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100519E0
// Name: public: CUtlBlockVector<struct CacheOptimizedTriangle>::~CUtlBlockVector<struct CacheOptimizedTriangle>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBlockVector<CacheOptimizedTriangle>::~CUtlBlockVector<CacheOptimizedTriangle>(
        CUtlBlockVector<CacheOptimizedTriangle> *this)
{
  CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>::~CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>(this);
}

//------------------------------------------------------------------------------
// Address: 0x10051A20
// Name: public: RayTracingEnvironment::~RayTracingEnvironment(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::~RayTracingEnvironment(RayTracingEnvironment *this)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_TriangleMaterials; // esi
  CUtlVector<Vector,CUtlMemory<Vector,int> > *p_TriangleColors; // esi
  CUtlVector<LightDesc_t,CUtlMemory<LightDesc_t,int> > *p_LightList; // esi
  CUtlVector<int,CUtlMemory<int,int> > *p_TriangleIndexList; // esi
  CUtlVector<CacheOptimizedKDNode,CUtlMemory<CacheOptimizedKDNode,int> > *p_OptimizedKDTree; // esi

  p_TriangleMaterials = &this->TriangleMaterials;
  this->TriangleMaterials.m_Size = 0;
  if ( this->TriangleMaterials.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_TriangleMaterials->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_TriangleMaterials->m_Memory.m_pMemory);
      p_TriangleMaterials->m_Memory.m_pMemory = nullptr;
    }
    p_TriangleMaterials->m_Memory.m_nAllocationCount = 0;
  }
  p_TriangleMaterials->m_pElements = p_TriangleMaterials->m_Memory.m_pMemory;
  if ( p_TriangleMaterials->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_TriangleMaterials->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_TriangleMaterials->m_Memory.m_pMemory);
      p_TriangleMaterials->m_Memory.m_pMemory = nullptr;
    }
    p_TriangleMaterials->m_Memory.m_nAllocationCount = 0;
  }
  p_TriangleColors = &this->TriangleColors;
  this->TriangleColors.m_Size = 0;
  if ( this->TriangleColors.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_TriangleColors->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_TriangleColors->m_Memory.m_pMemory);
      p_TriangleColors->m_Memory.m_pMemory = nullptr;
    }
    this->TriangleColors.m_Memory.m_nAllocationCount = 0;
  }
  this->TriangleColors.m_pElements = this->TriangleColors.m_Memory.m_pMemory;
  if ( this->TriangleColors.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_TriangleColors->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_TriangleColors->m_Memory.m_pMemory);
      p_TriangleColors->m_Memory.m_pMemory = nullptr;
    }
    this->TriangleColors.m_Memory.m_nAllocationCount = 0;
  }
  p_LightList = &this->LightList;
  this->LightList.m_Size = 0;
  if ( this->LightList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_LightList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_LightList->m_Memory.m_pMemory);
      p_LightList->m_Memory.m_pMemory = nullptr;
    }
    this->LightList.m_Memory.m_nAllocationCount = 0;
  }
  this->LightList.m_pElements = this->LightList.m_Memory.m_pMemory;
  if ( this->LightList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_LightList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_LightList->m_Memory.m_pMemory);
      p_LightList->m_Memory.m_pMemory = nullptr;
    }
    this->LightList.m_Memory.m_nAllocationCount = 0;
  }
  p_TriangleIndexList = &this->TriangleIndexList;
  this->TriangleIndexList.m_Size = 0;
  if ( this->TriangleIndexList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_TriangleIndexList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_TriangleIndexList->m_Memory.m_pMemory);
      p_TriangleIndexList->m_Memory.m_pMemory = nullptr;
    }
    this->TriangleIndexList.m_Memory.m_nAllocationCount = 0;
  }
  this->TriangleIndexList.m_pElements = this->TriangleIndexList.m_Memory.m_pMemory;
  if ( this->TriangleIndexList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_TriangleIndexList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_TriangleIndexList->m_Memory.m_pMemory);
      p_TriangleIndexList->m_Memory.m_pMemory = nullptr;
    }
    this->TriangleIndexList.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>::~CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>(this: &this->OptimizedTriangleList);
  p_OptimizedKDTree = &this->OptimizedKDTree;
  this->OptimizedKDTree.m_Size = 0;
  if ( this->OptimizedKDTree.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_OptimizedKDTree->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_OptimizedKDTree->m_Memory.m_pMemory);
      p_OptimizedKDTree->m_Memory.m_pMemory = nullptr;
    }
    this->OptimizedKDTree.m_Memory.m_nAllocationCount = 0;
  }
  this->OptimizedKDTree.m_pElements = this->OptimizedKDTree.m_Memory.m_pMemory;
  if ( this->OptimizedKDTree.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_OptimizedKDTree->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_OptimizedKDTree->m_Memory.m_pMemory);
      p_OptimizedKDTree->m_Memory.m_pMemory = nullptr;
    }
    this->OptimizedKDTree.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051C00
// Name: public: void CLightingPreviewThread::CalculateForLight(class CLightingPreviewLightDescription __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CLightingPreviewThread::CalculateForLight(
        CLightingPreviewThread *this@<ecx>,
        int a2@<ebp>,
        double a3@<esi:edi>,
        CLightingPreviewLightDescription *l)
{
  CLightingPreviewLightDescription *v4; // edi
  bool v5; // zf
  int z_low; // eax
  RayTracingSingleResult *v7; // edi
  float *p_ray_length; // esi
  double Element; // st7
  double y; // xmm0_8
  double v11; // st7
  double v12; // xmm0_8
  double z; // xmm0_8
  double v14; // xmm0_8
  float x; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  RayTracingEnvironment *v18; // ecx
  float v19; // esi
  float *v20; // edi
  float v21; // xmm3_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  int v24; // xmm1_4
  int v25; // xmm2_4
  __m128 v26; // xmm3
  __m128 v27; // xmm0
  __m128 v28; // xmm0
  __m128 v29; // xmm1
  __m128 v30; // xmm0
  __m128 v31; // xmm1
  __int128 v32; // xmm1
  __int128 v33; // xmm0
  _DWORD *v34; // eax
  int v35; // esi
  _DWORD *v36; // esi
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm0_4
  float v40; // eax
  int m_nAllocationCount; // ecx
  CLightingPreviewLightDescription **m_pMemory; // edx
  int v43; // ecx
  CLightingPreviewLightDescription **v44; // eax
  CIncrementalLightInfo *m_pIncrementalInfo; // esi
  float v46; // eax
  int v47; // edi
  int m_nNumLinesCalculated; // eax
  int v49; // edi
  float v50; // xmm0_4
  float v51; // xmm0_4
  float v52; // edx
  int v53; // [esp+0h] [ebp-BD0h]
  int v54; // [esp+0h] [ebp-BD0h]
  long double v55; // [esp+4h] [ebp-BCCh]
  long double v56; // [esp+4h] [ebp-BCCh]
  long double v57; // [esp+4h] [ebp-BCCh]
  long double v58; // [esp+4h] [ebp-BCCh]
  int v59; // [esp+Ch] [ebp-BC4h] BYREF
  int v60; // [esp+14h] [ebp-BBCh] BYREF
  RayTracingSingleResult rslts[50]; // [esp+30h] [ebp-BA0h] BYREF
  Vector rayDirs[50]; // [esp+4E0h] [ebp-6F0h] BYREF
  _BYTE myStream_92[884]; // [esp+794h] [ebp-43Ch] OVERLAPPED BYREF
  _BYTE v4Color_12[84]; // [esp+B14h] [ebp-BCh] OVERLAPPED BYREF
  float v65; // [esp+B70h] [ebp-60h]
  float v66; // [esp+B74h] [ebp-5Ch]
  float v67; // [esp+B78h] [ebp-58h]
  DirectionalSampler_t sampler; // [esp+B7Ch] [ebp-54h] BYREF
  float v69; // [esp+B94h] [ebp-3Ch] BYREF
  float v70; // [esp+B98h] [ebp-38h]
  Vector vecHitPos; // [esp+B9Ch] [ebp-34h]
  Vector rayStart; // [esp+BA8h] [ebp-28h] BYREF
  float *p_lrad; // [esp+BB4h] [ebp-1Ch]
  Vector vecColorToShoot; // [esp+BB8h] [ebp-18h]
  _DWORD v75[2]; // [esp+BC4h] [ebp-Ch] BYREF
  float lrad; // [esp+BCCh] [ebp-4h] BYREF
  int vars0; // [esp+BD0h] [ebp+0h]

  v75[0] = a2;
  v75[1] = vars0;
  vecColorToShoot.z = NAN;
  LODWORD(vecColorToShoot.y) = &_ehhandler__CalculateForLight_CLightingPreviewThread__QAEXPAVCLightingPreviewLightDescription___Z;
  LODWORD(vecColorToShoot.x) = NtCurrentTeb()->NtTib.ExceptionList;
  p_lrad = &lrad;
  v55 = a3;
  v4 = l;
  v5 = !l->m_bDidIndirect;
  LODWORD(vecHitPos.z) = this;
  if ( v5 )
  {
    rayStart.x = LightDesc_t::DistanceAtWhichBrightnessIsLessThan(this: l, flAmount: 0.0020000001);
    HaltonSequenceGenerator_t::HaltonSequenceGenerator_t(this: (HaltonSequenceGenerator_t *)&v4Color_12[68], b: 2);
    HaltonSequenceGenerator_t::HaltonSequenceGenerator_t(this: (HaltonSequenceGenerator_t *)&v4Color_12[80], b: 3);
    z_low = LODWORD(l->m_Position.z);
    memset(myStream_92, 0, 32);
    *(_QWORD *)&sampler.zdot.fbase = *(_QWORD *)&l->m_Position.x;
    sampler.vrot.base = z_low;
    v7 = (RayTracingSingleResult *)&v59;
    p_ray_length = &rslts[48].ray_length;
    LODWORD(rayStart.y) = 50;
    do
    {
      v53 = (*(_DWORD *)&v4Color_12[68])++;
      Element = HaltonSequenceGenerator_t::GetElement(this: (HaltonSequenceGenerator_t *)&v4Color_12[68], elem: v53);
      vecHitPos.y = Element + Element - 1.0;
      y = vecHitPos.y;
      __libm_sse2_acos(x: v55);
      v54 = *(_DWORD *)&v4Color_12[80];
      *(float *)&y = y;
      v66 = *(float *)&y;
      ++*(_DWORD *)&v4Color_12[80];
      v11 = HaltonSequenceGenerator_t::GetElement(this: (HaltonSequenceGenerator_t *)&v4Color_12[80], elem: v54);
      v12 = v66;
      rayStart.z = v11 * 6.283185307179586;
      __libm_sse2_sin(x: v56);
      *(float *)&v12 = v12;
      v65 = *(float *)&v12;
      z = rayStart.z;
      __libm_sse2_sin(x: v57);
      *(float *)&z = z;
      sampler.vrot.fbase = *(float *)&z;
      v14 = rayStart.z;
      __libm_sse2_cos(x: v58);
      x = rayStart.x;
      *p_ray_length = vecHitPos.y;
      v16 = sampler.vrot.fbase * v65;
      *(float *)&v14 = v14;
      *(float *)&v14 = *(float *)&v14 * v65;
      *(p_ray_length - 2) = *(float *)&v14;
      v69 = (float)(*(float *)&v14 * x) + sampler.zdot.fbase;
      LODWORD(v14) = sampler.vrot.seed;
      *(p_ray_length - 1) = v16;
      v17 = *p_ray_length;
      v18 = *(RayTracingEnvironment **)(LODWORD(vecHitPos.z) + 1612);
      v70 = *(float *)&v14 + (float)(v16 * x);
      vecHitPos.x = *(float *)&sampler.vrot.base + (float)(v17 * x);
      RayTracingEnvironment::AddToRayStream(
        this: v18,
        s: (RayStream *)&rayDirs[47],
        start: (const Vector *)&sampler.zdot.fbase,
        end: (const Vector *)&v69,
        rslt_out: v7,
        cullMode: RTE_CULL_NONE);
      p_ray_length += 3;
      ++v7;
      --LODWORD(rayStart.y);
    }
    while ( LODWORD(rayStart.y) != 0 );
    RayTracingEnvironment::FinishRayStream(
      this: *(RayTracingEnvironment **)(LODWORD(vecHitPos.z) + 1612),
      s: (RayStream *)&rayDirs[47],
      cullMode: RTE_CULL_NONE);
    v19 = COERCE_FLOAT((RayTracingSingleResult *)&rslts[48].ray_length);
    v20 = (float *)&v60;
    LODWORD(rayStart.z) = &rslts[48].ray_length;
    LODWORD(vecHitPos.y) = 50;
    do
    {
      if ( *((_DWORD *)v20 + 1) != -1 )
      {
        v21 = v20[2];
        v22 = *(float *)(LODWORD(v19) - 4);
        v23 = *(float *)LODWORD(v19);
        v67 = (float)(*(float *)(LODWORD(v19) - 8) * v21) + sampler.zdot.fbase;
        *(float *)&v24 = (float)(v22 * v21) + *(float *)&sampler.vrot.seed;
        *(float *)&v25 = (float)(v23 * v21) + *(float *)&sampler.vrot.base;
        v26 = 0;
        v26.m128_f32[0] = v67;
        *(__m128 *)&myStream_92[800] = _mm_shuffle_ps(v26, v26, 0);
        v27 = 0;
        v27.m128_f32[0] = *(float *)&v24;
        *(__m128 *)&myStream_92[816] = _mm_shuffle_ps(v27, v27, 0);
        v28 = 0;
        v28.m128_f32[0] = *(float *)&v25;
        *(__m128 *)&myStream_92[832] = _mm_shuffle_ps(v28, v28, 0);
        sampler.zdot.seed = v24;
        v29 = (__m128)*((unsigned int *)v20 - 1);
        *(__m128 *)v4Color_12 = _mm_shuffle_ps(
                                  (__m128)*((unsigned int *)v20 - 2),
                                  (__m128)*((unsigned int *)v20 - 2),
                                  0);
        v30 = v29;
        v31 = (__m128)*(unsigned int *)v20;
        *(__m128 *)&v4Color_12[16] = _mm_shuffle_ps(v30, v30, 0);
        sampler.zdot.base = v25;
        *(__m128 *)&v4Color_12[32] = _mm_shuffle_ps(v31, v31, 0);
        LightDesc_t::ComputeLightAtPoints(
          this: l,
          pos: (const FourVectors *)&myStream_92[800],
          normal: (const FourVectors *)v4Color_12,
          color: (FourVectors *)&myStream_92[848],
          DoHalfLambert: false);
        v69 = (float)(*(float *)&myStream_92[848] * 0.25) * 0.02;
        v70 = (float)(*(float *)&myStream_92[864] * 0.25) * 0.02;
        vecHitPos.x = (float)(*(float *)&myStream_92[880] * 0.25) * 0.02;
        v32 = 0;
        *(float *)&v32 = (float)((float)(v69 * v69) + (float)(v70 * v70)) + (float)(vecHitPos.x * vecHitPos.x);
        v33 = v32;
        *(float *)&v33 = fsqrt(*(float *)&v32);
        *(_OWORD *)&v4Color_12[48] = v33;
        if ( *(float *)&v33 > 0.00392156862745098 )
        {
          v34 = operator new(nSize: 0x80u);
          LODWORD(rayStart.x) = v34;
          vecColorToShoot.z = 0.0;
          if ( v34 != nullptr )
          {
            LODWORD(sampler.vrot.fbase) = v34 + 23;
            v34[23] = 0;
            v34[24] = 0;
            v34[25] = 0;
            LOBYTE(vecColorToShoot.z) = 1;
            v35 = v34[23];
            v34[26] = 0;
            v34[27] = v35;
            v34[29] = 0;
            *((_WORD *)v34 + 62) = 1;
            LOBYTE(vecColorToShoot.z) = 0;
            v36 = v34;
          }
          else
          {
            v36 = nullptr;
          }
          vecColorToShoot.z = NAN;
          v36[22] = 0;
          v36[30] = 0;
          v36[28] = -268435456;
          *((_BYTE *)v36 + 125) = 0;
          v37 = *(v20 - 1);
          v38 = *v20;
          *((float *)v36 + 4) = (float)(*(v20 - 2) * 2.0) + v67;
          v39 = v69;
          *((float *)v36 + 5) = (float)(v37 * 2.0) + *(float *)&sampler.zdot.seed;
          *((float *)v36 + 6) = (float)(v38 * 2.0) + *(float *)&sampler.zdot.base;
          *v36 = 3;
          *((float *)v36 + 1) = v39;
          *((float *)v36 + 2) = v70;
          v36[3] = LODWORD(vecHitPos.x);
          *((float *)v36 + 7) = *(v20 - 2);
          *((float *)v36 + 8) = *(v20 - 1);
          *((float *)v36 + 9) = *v20;
          v36[15] = 0;
          v36[16] = 1078530011;
          LightDesc_t::RecalculateDerivedValues(this: (LightDesc_t *)v36);
          v36[11] = 1084227584;
          v36[10] = 0;
          v36[12] = 0;
          v36[13] = 0;
          v36[14] = 1065353216;
          *((_BYTE *)v36 + 125) = 1;
          v40 = *(float *)&l->m_TempChildren.m_Size;
          LODWORD(rayStart.x) = &l->m_TempChildren;
          m_nAllocationCount = l->m_TempChildren.m_Memory.m_nAllocationCount;
          rayStart.y = v40;
          if ( LODWORD(v40) + 1 > m_nAllocationCount )
          {
            CUtlMemory<CVisGroup *,int>::Grow(
              this: (CUtlMemory<CCullTreeNode *,int> *)LODWORD(rayStart.x),
              num: LODWORD(v40) - m_nAllocationCount + 1);
            v40 = rayStart.y;
          }
          m_pMemory = l->m_TempChildren.m_Memory.m_pMemory;
          ++l->m_TempChildren.m_Size;
          l->m_TempChildren.m_pElements = m_pMemory;
          v43 = l->m_TempChildren.m_Size - LODWORD(v40) - 1;
          if ( v43 > 0 )
          {
            _V_memmove(dest: &m_pMemory[LODWORD(v40) + 1], src: &m_pMemory[LODWORD(v40)], count: 4 * v43);
            v40 = rayStart.y;
          }
          v44 = &l->m_TempChildren.m_Memory.m_pMemory[LODWORD(v40)];
          if ( v44 != nullptr )
            *v44 = (CLightingPreviewLightDescription *)v36;
          v19 = rayStart.z;
        }
      }
      LODWORD(v19) += 12;
      v20 += 6;
      v5 = LODWORD(vecHitPos.y)-- == 1;
      rayStart.z = v19;
    }
    while ( !v5 );
    l->m_bDidIndirect = true;
    v4 = l;
  }
  v5 = !v4->m_bLowRes;
  m_pIncrementalInfo = v4->m_pIncrementalInfo;
  LODWORD(rayStart.z) = LODWORD(vecHitPos.z) + 4;
  if ( !v5 )
    LODWORD(rayStart.z) = LODWORD(vecHitPos.z) + 808;
  v46 = *(float *)(LODWORD(rayStart.z) + 4);
  v47 = *(_DWORD *)LODWORD(rayStart.z);
  rayStart.y = v46;
  if ( m_pIncrementalInfo->m_CalculatedContribution.m_nColumns != v47
    || m_pIncrementalInfo->m_CalculatedContribution.m_nRows != LODWORD(v46) )
  {
    CSOAContainer::Purge(this: &m_pIncrementalInfo->m_CalculatedContribution);
    if ( v47 != 0 && LODWORD(rayStart.y) != 0 )
    {
      CSOAContainer::SetAttributeType(
        this: &m_pIncrementalInfo->m_CalculatedContribution,
        nAttrIdx: 0,
        nDataType: ATTRDATATYPE_4V,
        bAllocateMemory: true);
      CSOAContainer::AllocateData(
        this: &m_pIncrementalInfo->m_CalculatedContribution,
        nNCols: v47,
        nNRows: SLODWORD(rayStart.y),
        nSlices: 1);
    }
  }
  m_nNumLinesCalculated = m_pIncrementalInfo->m_nNumLinesCalculated;
  v49 = m_nNumLinesCalculated + 8;
  if ( m_nNumLinesCalculated + 8 >= *(_DWORD *)(LODWORD(rayStart.z) + 4) - 1 )
    v49 = *(_DWORD *)(LODWORD(rayStart.z) + 4) - 1;
  CLightingPreviewThread::CalculateForLightTask(
    this: (CLightingPreviewThread *)LODWORD(vecHitPos.z),
    a2: (FourVectors *)v75,
    a3: v49,
    nLineStart: m_nNumLinesCalculated,
    nLineEnd: v49,
    l,
    fContributionOut: &rayStart.x,
    pLInfo: m_pIncrementalInfo);
  v50 = rayStart.x;
  m_pIncrementalInfo->m_flLastContribution = rayStart.x;
  v51 = v50 + m_pIncrementalInfo->m_fTotalContribution;
  m_pIncrementalInfo->m_fTotalContribution = v51;
  if ( v51 == 0.0 )
    CSOAContainer::Purge(this: &m_pIncrementalInfo->m_CalculatedContribution);
  else
    m_pIncrementalInfo->m_nMostRecentNonZeroContributionTimeStamp = *(_DWORD *)(LODWORD(vecHitPos.z) + 1648);
  v52 = rayStart.z;
  m_pIncrementalInfo->m_nNumLinesCalculated = v49 + 1;
  m_pIncrementalInfo->m_eIncrState = 2 * (v49 == *(_DWORD *)(LODWORD(v52) + 4) - 1) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x100521F0
// Name: public: CLightingPreviewLightDescription::~CLightingPreviewLightDescription(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightingPreviewLightDescription::~CLightingPreviewLightDescription(
        CLightingPreviewLightDescription *this)
{
  CUtlVector<CLightingPreviewLightDescription *,CUtlMemory<CLightingPreviewLightDescription *,int> > *p_m_TempChildren; // esi
  bool v2; // sf

  p_m_TempChildren = &this->m_TempChildren;
  v2 = this->m_TempChildren.m_Memory.m_nGrowSize < 0;
  this->m_TempChildren.m_Size = 0;
  if ( !v2 )
  {
    if ( p_m_TempChildren->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_TempChildren->m_Memory.m_pMemory);
      p_m_TempChildren->m_Memory.m_pMemory = nullptr;
    }
    p_m_TempChildren->m_Memory.m_nAllocationCount = 0;
  }
  p_m_TempChildren->m_pElements = p_m_TempChildren->m_Memory.m_pMemory;
  if ( p_m_TempChildren->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_TempChildren->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_TempChildren->m_Memory.m_pMemory);
      p_m_TempChildren->m_Memory.m_pMemory = nullptr;
    }
    p_m_TempChildren->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052290
// Name: public: void CParallelProcessor<class CLightingPreviewLightDescription __near *,class CFuncJobItemProcessor<class CLightingPreviewLightDescription __near *>,1>::Run(class CLightingPreviewLightDescription __near * __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CLightingPreviewLightDescription *,CFuncJobItemProcessor<CLightingPreviewLightDescription *>,1>::Run(
        CParallelProcessor<CLightingPreviewLightDescription *,CFuncJobItemProcessor<CLightingPreviewLightDescription *>,1> *this,
        CLightingPreviewLightDescription **pItems,
        unsigned int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  IThreadPool *v7; // ecx
  int v8; // ebx
  int v9; // eax
  void *v10; // esp
  int i; // esi
  _DWORD v12[3]; // [esp+0h] [ebp-10h]
  CParallelProcessor<CLightingPreviewLightDescription *,CFuncJobItemProcessor<CLightingPreviewLightDescription *>,1> *pObject; // [esp+Ch] [ebp-4h]

  pObject = this;
  if ( nItems != 0 )
  {
    v7 = pThreadPool;
    this->m_nChunkSize = nChunkSize;
    if ( pThreadPool == nullptr )
    {
      pThreadPool = _g_pThreadPool;
      v7 = _g_pThreadPool;
    }
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v8 = nItems - 1;
    this->m_pLimit = &pItems[nItems];
    if ( (int)(nItems - 1) > nMaxParallel )
      v8 = nMaxParallel;
    if ( v7 == nullptr )
      goto LABEL_15;
    v9 = v7->NumThreads(this: v7);
    if ( v8 > v9 )
      v8 = v9;
    if ( v8 > 0 )
    {
      v10 = alloca(4 * v8);
      for ( i = v8;
            i != 0;
            v12[i] = IThreadPool::QueueCall<CParallelProcessor<CLightingPreviewLightDescription *,CFuncJobItemProcessor<CLightingPreviewLightDescription *>,1>,CParallelProcessor<CLightingPreviewLightDescription *,CFuncJobItemProcessor<CLightingPreviewLightDescription *>,1>,void>(
                       this: pThreadPool,
                       pObject,
                       pfnProxied: (void (__thiscall *)(CParallelProcessor<CLightingPreviewLightDescription *,CFuncJobItemProcessor<CLightingPreviewLightDescription *>,1> *))CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::DoExecute) )
      {
        --i;
      }
      CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::DoExecute(this: (CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *)pObject);
      do
      {
        CJob::Abort(this: (CJob *)v12[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v12[i] + 4))(a1: v12[i]);
        ++i;
      }
      while ( i < v8 );
    }
    else
    {
LABEL_15:
      CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::DoExecute((CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *)this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052360
// Name: public: void CParallelProcessor<int,class CFuncJobItemProcessor<int>,1>::Run(int __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<int,CFuncJobItemProcessor<int>,1>::Run(
        CParallelProcessor<int,CFuncJobItemProcessor<int>,1> *this,
        int *pItems,
        unsigned int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  IThreadPool *v7; // ecx
  int v8; // ebx
  int v9; // eax
  void *v10; // esp
  int i; // esi
  _DWORD v12[3]; // [esp+0h] [ebp-10h]
  CParallelProcessor<int,CFuncJobItemProcessor<int>,1> *pObject; // [esp+Ch] [ebp-4h]

  pObject = this;
  if ( nItems != 0 )
  {
    v7 = pThreadPool;
    this->m_nChunkSize = nChunkSize;
    if ( pThreadPool == nullptr )
    {
      pThreadPool = _g_pThreadPool;
      v7 = _g_pThreadPool;
    }
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v8 = nItems - 1;
    this->m_pLimit = &pItems[nItems];
    if ( (int)(nItems - 1) > nMaxParallel )
      v8 = nMaxParallel;
    if ( v7 == nullptr )
      goto LABEL_15;
    v9 = v7->NumThreads(this: v7);
    if ( v8 > v9 )
      v8 = v9;
    if ( v8 > 0 )
    {
      v10 = alloca(4 * v8);
      for ( i = v8;
            i != 0;
            v12[i] = IThreadPool::QueueCall<CParallelProcessor<int,CFuncJobItemProcessor<int>,1>,CParallelProcessor<int,CFuncJobItemProcessor<int>,1>,void>(
                       this: pThreadPool,
                       pObject,
                       pfnProxied: (void (__thiscall *)(CParallelProcessor<int,CFuncJobItemProcessor<int>,1> *))CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::DoExecute) )
      {
        --i;
      }
      CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::DoExecute(this: (CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *)pObject);
      do
      {
        CJob::Abort(this: (CJob *)v12[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v12[i] + 4))(a1: v12[i]);
        ++i;
      }
      while ( i < v8 );
    }
    else
    {
LABEL_15:
      CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::DoExecute((CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *)this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052430
// Name: public: RayTracingEnvironment::RayTracingEnvironment(void)
// Source: json
//------------------------------------------------------------------------------
RayTracingEnvironment *__thiscall RayTracingEnvironment::RayTracingEnvironment(RayTracingEnvironment *this)
{
  CUtlVector<CacheOptimizedKDNode,CUtlMemory<CacheOptimizedKDNode,int> > *p_OptimizedKDTree; // eax
  CacheOptimizedKDNode *m_pMemory; // ecx
  int *v4; // ecx
  LightDesc_t *v5; // ecx
  Vector *v6; // ecx
  int *v7; // ecx
  __m128 v8; // xmm1

  p_OptimizedKDTree = &this->OptimizedKDTree;
  this->OptimizedKDTree.m_Memory.m_pMemory = nullptr;
  this->OptimizedKDTree.m_Memory.m_nAllocationCount = 0;
  this->OptimizedKDTree.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->OptimizedKDTree.m_Memory.m_pMemory;
  p_OptimizedKDTree->m_Size = 0;
  p_OptimizedKDTree->m_pElements = m_pMemory;
  this->OptimizedTriangleList.m_Memory.m_pMemory = nullptr;
  this->OptimizedTriangleList.m_Memory.m_nBlocks = 0;
  *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2) = 0;
  CUtlBlockMemory<CacheOptimizedTriangle,int>::Init(
    this: &this->OptimizedTriangleList.m_Memory,
    nGrowSize: 1024,
    nInitSize: 0);
  this->OptimizedTriangleList.m_Size = 0;
  this->OptimizedTriangleList.m_pElements = nullptr;
  this->TriangleIndexList.m_Memory.m_pMemory = nullptr;
  this->TriangleIndexList.m_Memory.m_nAllocationCount = 0;
  this->TriangleIndexList.m_Memory.m_nGrowSize = 0;
  v4 = this->TriangleIndexList.m_Memory.m_pMemory;
  this->TriangleIndexList.m_Size = 0;
  this->TriangleIndexList.m_pElements = v4;
  this->LightList.m_Memory.m_pMemory = nullptr;
  this->LightList.m_Memory.m_nAllocationCount = 0;
  this->LightList.m_Memory.m_nGrowSize = 0;
  v5 = this->LightList.m_Memory.m_pMemory;
  this->LightList.m_Size = 0;
  this->LightList.m_pElements = v5;
  this->TriangleColors.m_Memory.m_pMemory = nullptr;
  this->TriangleColors.m_Memory.m_nAllocationCount = 0;
  this->TriangleColors.m_Memory.m_nGrowSize = 0;
  v6 = this->TriangleColors.m_Memory.m_pMemory;
  this->TriangleColors.m_Size = 0;
  this->TriangleColors.m_pElements = v6;
  this->TriangleMaterials.m_Memory.m_pMemory = nullptr;
  this->TriangleMaterials.m_Memory.m_nAllocationCount = 0;
  this->TriangleMaterials.m_Memory.m_nGrowSize = 0;
  v7 = this->TriangleMaterials.m_Memory.m_pMemory;
  this->TriangleMaterials.m_Size = 0;
  this->TriangleMaterials.m_pElements = v7;
  this->BackgroundColor.x = _mm_shuffle_ps((__m128)0x3F800000u, (__m128)0x3F800000u, 0);
  v8 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  this->BackgroundColor.y = v8;
  this->BackgroundColor.z = v8;
  this->Flags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10052570
// Name: s_CalculateForLight
// Source: json
//------------------------------------------------------------------------------
void __usercall s_CalculateForLight(double a1@<esi:edi>, CLightingPreviewLightDescription **pLight)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  CLightingPreviewThread::CalculateForLight(this: s_pThis, a2: (int)&savedregs, a3: a1, l: *pLight);
}

//------------------------------------------------------------------------------
// Address: 0x10052590
// Name: public: void CLightingPreviewThread::HandleGeomMessage(struct MessageToLPreview __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightingPreviewThread::HandleGeomMessage(CLightingPreviewThread *this, MessageToLPreview *msg_in)
{
  CLightingPreviewThread *v2; // edi
  RayTracingEnvironment *m_pRtEnv; // ebx
  int v4; // esi
  CUtlVector<Vector,CUtlMemory<Vector,int> > *m_pShadowTriangleList; // ebx
  void *v6; // eax
  RayTracingEnvironment *v7; // ecx
  RayTracingEnvironment *v8; // eax
  int v9; // edi
  const Vector *v10; // edx
  RayTracingEnvironment *v11; // ecx
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v12; // ebx
  Vector color; // [esp+Ch] [ebp-20h] BYREF
  void *pData; // [esp+18h] [ebp-14h]
  CLightingPreviewThread *v15; // [esp+1Ch] [ebp-10h]
  int v16; // [esp+28h] [ebp-4h]

  v2 = this;
  m_pRtEnv = this->m_pRtEnv;
  v4 = 0;
  v15 = this;
  if ( m_pRtEnv != nullptr )
  {
    RayTracingEnvironment::~RayTracingEnvironment(this: m_pRtEnv);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pRtEnv & 0xFFFFFFFC) - 4));
    v2->m_pRtEnv = nullptr;
  }
  m_pShadowTriangleList = msg_in->m_pShadowTriangleList;
  if ( m_pShadowTriangleList->m_Size != 0 )
  {
    v6 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 227);
    if ( v6 != nullptr )
    {
      v7 = (RayTracingEnvironment *)(((unsigned int)v6 + 19) & 0xFFFFFFF0);
      *((_DWORD *)&v7[-1].TriangleMaterials + 6) = v6;
    }
    else
    {
      v7 = nullptr;
    }
    pData = v7;
    v16 = 0;
    v8 = v7 != nullptr ? RayTracingEnvironment::RayTracingEnvironment(this: v7) : nullptr;
    v16 = -1;
    v2->m_pRtEnv = v8;
    if ( m_pShadowTriangleList->m_Size > 0 )
    {
      v9 = 0;
      do
      {
        v10 = &m_pShadowTriangleList->m_Memory.m_pMemory[v9];
        v11 = v15->m_pRtEnv;
        color.x = 0.5;
        color.y = 0.5;
        color.z = 0.5;
        RayTracingEnvironment::AddTriangle(this: v11, id: v4, v1: v10, v2: v10 + 1, v3: v10 + 2, &color);
        v4 += 3;
        v9 += 3;
      }
      while ( v4 < m_pShadowTriangleList->m_Size );
      v2 = v15;
    }
  }
  v12 = msg_in->m_pShadowTriangleList;
  if ( v12 != nullptr )
  {
    v16 = 1;
    v12->m_Size = 0;
    if ( v12->m_Memory.m_nGrowSize >= 0 )
    {
      if ( v12->m_Memory.m_pMemory != nullptr )
      {
        free(pMem: v12->m_Memory.m_pMemory);
        v12->m_Memory.m_pMemory = nullptr;
      }
      v12->m_Memory.m_nAllocationCount = 0;
    }
    v12->m_pElements = v12->m_Memory.m_pMemory;
    v16 = -1;
    if ( v12->m_Memory.m_nGrowSize >= 0 )
    {
      if ( v12->m_Memory.m_pMemory != nullptr )
      {
        free(pMem: v12->m_Memory.m_pMemory);
        v12->m_Memory.m_pMemory = nullptr;
      }
      v12->m_Memory.m_nAllocationCount = 0;
    }
    operator delete(p: v12);
  }
  v2->m_bAccStructureBuilt = false;
  CLightingPreviewThread::DiscardResults(this: v2, a2: (int)v2, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10052710
// Name: public: void CLightingPreviewThread::DoWork(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightingPreviewThread::DoWork(CLightingPreviewThread *this)
{
  CLightingPreviewThread *v1; // ebx
  RayTracingEnvironment *m_pRtEnv; // ecx
  int v3; // eax
  bool v4; // zf
  CLightingPreviewLightDescription *m_pHead; // esi
  CIncrementalLightInfo *m_pIncrementalInfo; // edi
  double v7; // st7
  float v8; // xmm0_4
  float x; // xmm1_4
  float y; // xmm0_4
  float z; // xmm0_4
  char v12; // cl
  signed int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // ecx
  IThreadPool *v16; // eax
  CLightingPreviewLightDescription **v17; // edi
  CLightingPreviewLightDescription *v18; // ecx
  int v19; // ebx
  CLightingPreviewLightDescription *v20; // esi
  CIncrementalLightInfo *v21; // eax
  CIncrementalLightInfo *v22; // eax
  int m_nObjectID; // edx
  float v24; // ecx
  int v25; // eax
  CLightingPreviewLightDescription *v26; // esi
  bool v27; // sf
  int v28; // edx
  CLightingPreviewLightDescription *pItems[2]; // [esp+8h] [ebp-64h] BYREF
  CLightingPreviewLightDescription *pLightsToRun[8]; // [esp+10h] [ebp-5Ch] BYREF
  CParallelProcessor<CLightingPreviewLightDescription *,CFuncJobItemProcessor<CLightingPreviewLightDescription *>,1> v31; // [esp+30h] [ebp-3Ch] BYREF
  float v32; // [esp+48h] [ebp-24h]
  void *p; // [esp+4Ch] [ebp-20h]
  CLightingPreviewThread *v34; // [esp+50h] [ebp-1Ch]
  unsigned int lrad; // [esp+54h] [ebp-18h]
  CLightingPreviewLightDescription *v36; // [esp+58h] [ebp-14h]
  unsigned int nItems; // [esp+5Ch] [ebp-10h]
  int v38; // [esp+68h] [ebp-4h]

  v1 = this;
  m_pRtEnv = this->m_pRtEnv;
  v34 = v1;
  if ( m_pRtEnv != nullptr && !v1->m_bAccStructureBuilt )
  {
    v1->m_bAccStructureBuilt = true;
    RayTracingEnvironment::SetupAccelerationStructure(this: m_pRtEnv);
  }
  v3 = s_nNumThreads + 1;
  v4 = !v1->m_bFirstWork;
  nItems = 0;
  if ( !v4 )
  {
    v3 *= 2;
    v1->m_bFirstWork = false;
  }
  if ( v3 > 0 )
  {
    for ( lrad = v3; lrad != 0; --lrad )
    {
      m_pHead = v1->m_LightList.m_pHead;
      v36 = nullptr;
      if ( m_pHead != nullptr )
      {
        do
        {
          m_pIncrementalInfo = m_pHead->m_pIncrementalInfo;
          if ( !m_pIncrementalInfo->m_bDisabled )
          {
            if ( m_pHead->m_Type != MATERIAL_LIGHT_DIRECTIONAL )
            {
              v7 = LightDesc_t::DistanceAtWhichBrightnessIsLessThan(this: m_pHead, flAmount: 0.0020000001);
              *(float *)&p = v7;
              v8 = v1->m_MinViewCoords.x - *(float *)&p;
              x = m_pHead->m_Position.x;
              *(float *)&v31.m_pLimit = v1->m_MaxViewCoords.x + v7;
              *(float *)&v31.m_nChunkSize = v1->m_MaxViewCoords.y + v7;
              v32 = v1->m_MaxViewCoords.z + v7;
              *(float *)&v31.m_ItemProcessor.m_pfnEnd = v1->m_MinViewCoords.y - v7;
              *(float *)&v31.m_pItems.m_value = v1->m_MinViewCoords.z - v7;
              if ( x < v8
                || *(float *)&v31.m_pLimit < x
                || (y = m_pHead->m_Position.y) < *(float *)&v31.m_ItemProcessor.m_pfnEnd
                || *(float *)&v31.m_nChunkSize < y
                || (z = m_pHead->m_Position.z) < *(float *)&v31.m_pItems.m_value
                || v32 < z )
              {
                m_pIncrementalInfo->m_bDisabled = true;
              }
            }
            if ( !m_pIncrementalInfo->m_bDisabled )
            {
              v12 = 0;
              v13 = 0;
              if ( (int)nItems <= 0 )
                goto LABEL_55;
              do
              {
                if ( pItems[v13] == m_pHead )
                  v12 = 1;
                ++v13;
              }
              while ( v13 < (int)nItems );
              if ( v12 == 0 )
              {
LABEL_55:
                if ( m_pIncrementalInfo->m_eIncrState != INCR_STATE_HAVE_FULL_RESULTS
                  && (v36 == nullptr
                   || CIncrementalLightInfo::IsLowerPriorityThan(
                        this: v36->m_pIncrementalInfo,
                        pLPV: v1,
                        other: m_pIncrementalInfo)) )
                {
                  v36 = m_pHead;
                }
              }
            }
          }
          m_pHead = m_pHead->m_pNext;
        }
        while ( m_pHead != nullptr );
        if ( v36 != nullptr )
        {
          v14 = nItems;
          pItems[nItems] = v36;
          nItems = v14 + 1;
        }
      }
    }
    v15 = nItems;
    if ( nItems != 0 )
    {
      v16 = s_pThreadPool;
      v31.m_ItemProcessor.m_pfnBegin = nullptr;
      v31.m_ItemProcessor.m_pfnEnd = nullptr;
      _InterlockedExchange((volatile __int32 *)&v31.m_ItemProcessor.m_pfnBegin, 0);
      pLightsToRun[6] = (CLightingPreviewLightDescription *)s_CalculateForLight;
      pLightsToRun[7] = nullptr;
      v31.m_ItemProcessor.m_pfnProcess = nullptr;
      CParallelProcessor<CLightingPreviewLightDescription *,CFuncJobItemProcessor<CLightingPreviewLightDescription *>,1>::Run(
        this: (CParallelProcessor<CLightingPreviewLightDescription *,CFuncJobItemProcessor<CLightingPreviewLightDescription *>,1> *)&pLightsToRun[6],
        pItems,
        nItems: v15,
        nChunkSize: 1,
        nMaxParallel: 0x7FFFFFFF,
        pThreadPool: v16);
      if ( (int)nItems > 0 )
      {
        v17 = pItems;
        lrad = nItems;
        while ( 1 )
        {
          v18 = *v17;
          if ( (*v17)->m_pIncrementalInfo->m_flLastContribution != 0.0 )
            v1->m_bResultChangedSinceLastSend = true;
          v19 = 0;
          if ( v18->m_TempChildren.m_Size > 0 )
          {
            do
            {
              v20 = (*v17)->m_TempChildren.m_Memory.m_pMemory[v19];
              *(float *)&v21 = COERCE_FLOAT(operator new(nSize: 0x758u));
              p = v21;
              v38 = 0;
              if ( *(float *)&v21 == 0.0 )
                v22 = nullptr;
              else
                v22 = CIncrementalLightInfo::CIncrementalLightInfo(this: v21);
              v38 = -1;
              m_nObjectID = v20->m_nObjectID;
              v24 = *(float *)&v34;
              v20->m_pIncrementalInfo = v22;
              v22->m_nObjectID = m_nObjectID;
              v20->m_pIncrementalInfo->m_pLight = v20;
              v20->m_pIncrementalInfo->m_pNext = *(CIncrementalLightInfo **)(LODWORD(v24) + 1616);
              *(_DWORD *)(LODWORD(v24) + 1616) = v20->m_pIncrementalInfo;
              v20->m_pNext = nullptr;
              v25 = *(_DWORD *)LODWORD(v24);
              if ( *(_DWORD *)LODWORD(v24) != 0 )
              {
                for ( ; *(_DWORD *)(v25 + 88) != 0; v25 = *(_DWORD *)(v25 + 88) )
                  ;
                *(_DWORD *)(v25 + 88) = v20;
              }
              else
              {
                *(_DWORD *)LODWORD(v24) = v20;
              }
              ++v19;
            }
            while ( v19 < (*v17)->m_TempChildren.m_Size );
          }
          v26 = *v17;
          v27 = (*v17)->m_TempChildren.m_Memory.m_nGrowSize < 0;
          (*v17)->m_TempChildren.m_Size = 0;
          if ( !v27 )
          {
            if ( v26->m_TempChildren.m_Memory.m_pMemory != nullptr )
            {
              free(pMem: v26->m_TempChildren.m_Memory.m_pMemory);
              v26->m_TempChildren.m_Memory.m_pMemory = nullptr;
            }
            v26->m_TempChildren.m_Memory.m_nAllocationCount = 0;
          }
          v26->m_TempChildren.m_pElements = v26->m_TempChildren.m_Memory.m_pMemory;
          v28 = (int)*v17++;
          v4 = lrad-- == 1;
          *(_BYTE *)(v28 + 125) = 1;
          if ( v4 )
            break;
          v1 = v34;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052A20
// Name: public: void CLightingPreviewThread::SendResult(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CLightingPreviewThread::SendResult(CLightingPreviewThread *this@<ecx>, int a2@<edi>)
{
  CSOAContainer *p_m_GBuffer; // edi
  const Vector *v4; // eax
  CLightingPreviewLightDescription *m_pHead; // eax
  int v6; // eax
  int v7; // ecx
  IThreadPool *v8; // eax
  int v10; // [esp+0h] [ebp-710h]
  int v11; // [esp+4h] [ebp-70Ch]
  int nProcessMasks[32]; // [esp+8h] [ebp-708h] BYREF
  CSOAContainer rsltBuffer1; // [esp+88h] [ebp-688h] BYREF
  CSOAContainer rsltBuffer; // [esp+3ACh] [ebp-364h] BYREF
  Vector result; // [esp+6D0h] [ebp-40h] BYREF
  CParallelProcessor<int,CFuncJobItemProcessor<int>,1> v16; // [esp+6DCh] [ebp-34h] BYREF
  Vector vecValue; // [esp+6F4h] [ebp-1Ch] BYREF
  bool bDidLoRes; // [esp+703h] [ebp-Dh]
  int v19; // [esp+70Ch] [ebp-4h]

  if ( this->m_GBuffer.m_nRows != 0 )
  {
    p_m_GBuffer = &this->m_GBuffer;
    if ( this->m_GBuffer.m_nColumns != 0 )
    {
      memset(dst: (unsigned __int8 *)rsltBuffer.m_nDataType, value: 0xFFu, count: sizeof(rsltBuffer.m_nDataType));
      memset(&rsltBuffer, 0, 24);
      memset(&rsltBuffer.m_nFieldPresentMask, 0, 140);
      v19 = 0;
      CSOAContainer::SetAttributeType(this: &rsltBuffer, nAttrIdx: 3, nDataType: ATTRDATATYPE_4V, bAllocateMemory: true);
      CSOAContainer::AllocateData(
        this: &rsltBuffer,
        nNCols: p_m_GBuffer->m_nColumns,
        nNRows: this->m_GBuffer.m_nRows,
        nSlices: 1);
      v4 = CLightingPreviewThread::EstimatedUnshotAmbient(this, &result);
      CSOAContainer::FillAttr(this: &rsltBuffer, nAttr: 3, vecValue: v4);
      s_pResultBuffer = &rsltBuffer;
      m_pHead = this->m_LightList.m_pHead;
      for ( bDidLoRes = false; m_pHead != nullptr; m_pHead = m_pHead->m_pNext )
      {
        if ( m_pHead->m_bLowRes )
          bDidLoRes = true;
      }
      memset(dst: (unsigned __int8 *)rsltBuffer1.m_nDataType, value: 0xFFu, count: sizeof(rsltBuffer1.m_nDataType));
      memset(&rsltBuffer1, 0, 24);
      memset(&rsltBuffer1.m_nFieldPresentMask, 0, 140);
      LOBYTE(v19) = 1;
      CSOAContainer::SetAttributeType(
        this: &rsltBuffer1,
        nAttrIdx: 3,
        nDataType: ATTRDATATYPE_4V,
        bAllocateMemory: true);
      CSOAContainer::AllocateData(
        this: &rsltBuffer1,
        nNCols: this->m_GBufferLowRes.m_nColumns,
        nNRows: this->m_GBufferLowRes.m_nRows,
        nSlices: 1);
      if ( bDidLoRes )
      {
        memset(&vecValue, 0, sizeof(vecValue));
        CSOAContainer::FillAttr(this: &rsltBuffer1, nAttr: 3, &vecValue);
      }
      s_pResultBuffer1 = &rsltBuffer1;
      v6 = 0;
      v7 = 1;
      do
      {
        nProcessMasks[v6++] = v7;
        v7 = __ROL4__(v7, 1);
      }
      while ( v6 < 32 );
      v8 = s_pThreadPool;
      v16.m_pItems.m_value = nullptr;
      v16.m_pLimit = nullptr;
      _InterlockedExchange((volatile __int32 *)&v16.m_pItems, 0);
      v16.m_ItemProcessor.m_pfnProcess = s_AccumulateOutput;
      v16.m_ItemProcessor.m_pfnBegin = nullptr;
      v16.m_ItemProcessor.m_pfnEnd = nullptr;
      CParallelProcessor<int,CFuncJobItemProcessor<int>,1>::Run(
        this: &v16,
        pItems: nProcessMasks,
        nItems: 0x20u,
        nChunkSize: 1,
        nMaxParallel: 0x7FFFFFFF,
        pThreadPool: v8);
      if ( bDidLoRes )
        CLightingPreviewThread::AddLowresResultToHires(this, lores: &rsltBuffer1, hires: &rsltBuffer);
      CSOAContainer::MulAttr(this: &rsltBuffer, src: &this->m_GBuffer, nSrcAttr: 1, nDestAttr: 3);
      CLightingPreviewThread::SendResultRendering(this, a2: 0, a3: (unsigned int)p_m_GBuffer, &rsltBuffer);
      this->m_fLastSendTime = _Plat_FloatTime(a1: a2, a2: v10, a3: v11, a4: nProcessMasks[0], a5: nProcessMasks[1]);
      this->m_bResultChangedSinceLastSend = false;
      LOBYTE(v19) = 0;
      CSOAContainer::~CSOAContainer(this: &rsltBuffer1);
      v19 = -1;
      CSOAContainer::~CSOAContainer(this: &rsltBuffer);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052CC0
// Name: public: void CUtlIntrusiveList<class CLightingPreviewLightDescription>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlIntrusiveList<CLightingPreviewLightDescription>::Purge(
        CUtlIntrusiveList<CLightingPreviewLightDescription> *this)
{
  CLightingPreviewLightDescription *m_pHead; // edi
  void **p_m_pMemory; // esi
  CLightingPreviewLightDescription *tmp; // [esp+8h] [ebp-14h]
  CUtlIntrusiveList<CLightingPreviewLightDescription> *v4; // [esp+Ch] [ebp-10h]

  v4 = this;
  if ( this->m_pHead != nullptr )
  {
    do
    {
      m_pHead = this->m_pHead;
      tmp = this->m_pHead->m_pNext;
      if ( this->m_pHead != nullptr )
      {
        p_m_pMemory = (void **)&m_pHead->m_TempChildren.m_Memory.m_pMemory;
        m_pHead->m_TempChildren.m_Size = 0;
        if ( m_pHead->m_TempChildren.m_Memory.m_nGrowSize >= 0 )
        {
          if ( *p_m_pMemory != nullptr )
          {
            free(pMem: *p_m_pMemory);
            *p_m_pMemory = nullptr;
          }
          m_pHead->m_TempChildren.m_Memory.m_nAllocationCount = 0;
        }
        m_pHead->m_TempChildren.m_pElements = m_pHead->m_TempChildren.m_Memory.m_pMemory;
        if ( m_pHead->m_TempChildren.m_Memory.m_nGrowSize >= 0 )
        {
          if ( *p_m_pMemory != nullptr )
          {
            free(pMem: *p_m_pMemory);
            *p_m_pMemory = nullptr;
          }
          m_pHead->m_TempChildren.m_Memory.m_nAllocationCount = 0;
        }
        operator delete(p: m_pHead);
        this = v4;
      }
      this->m_pHead = tmp;
    }
    while ( tmp != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052D80
// Name: public: CLightingPreviewThread::~CLightingPreviewThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightingPreviewThread::~CLightingPreviewThread(CLightingPreviewThread *this)
{
  CIncrementalLightInfo *m_pNext; // ebx
  CIncrementalLightInfo *m_pIncrementalLightInfoList; // edi

  CUtlIntrusiveList<CLightingPreviewLightDescription>::Purge(this: &this->m_LightList);
  if ( this->m_pIncrementalLightInfoList != nullptr )
  {
    do
    {
      m_pNext = this->m_pIncrementalLightInfoList->m_pNext;
      m_pIncrementalLightInfoList = this->m_pIncrementalLightInfoList;
      if ( m_pIncrementalLightInfoList != nullptr )
      {
        CSOAContainer::~CSOAContainer(this: &m_pIncrementalLightInfoList->m_CalculatedContribution);
        operator delete(p: m_pIncrementalLightInfoList);
      }
      this->m_pIncrementalLightInfoList = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
  CSOAContainer::~CSOAContainer(this: &this->m_GBufferLowRes);
  CSOAContainer::~CSOAContainer(this: &this->m_GBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x10052E20
// Name: public: bool CLightingPreviewThread::HandleAMessage(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CLightingPreviewThread::HandleAMessage@<al>(CLightingPreviewThread *this@<ecx>, int a2@<edi>)
{
  bool result; // al
  float x; // xmm0_4
  MessageToLPreview msg_in; // [esp+4h] [ebp-2Ch] BYREF

  msg_in.m_LightList.m_pHead = nullptr;
  CMessageQueue<MessageToLPreview>::WaitMessage(this: &g_HammerToLPreviewMsgQueue, pMsg: &msg_in);
  switch ( msg_in.m_MsgType )
  {
    case LPREVIEW_MSG_EXIT:
      result = true;
      break;
    case LPREVIEW_MSG_GEOM_DATA:
      CLightingPreviewThread::HandleGeomMessage(this, &msg_in);
      CLightingPreviewThread::DiscardResults(this, a2, a3: (int)this);
      result = false;
      break;
    case LPREVIEW_MSG_G_BUFFERS:
      CLightingPreviewThread::HandleGBuffersMessage(this, &msg_in);
      CLightingPreviewThread::DiscardResults(this, a2, a3: (int)this);
      goto LABEL_6;
    case LPREVIEW_MSG_LIGHT_DATA:
      CUtlIntrusiveList<CLightingPreviewLightDescription>::Purge(this: &this->m_LightList);
      x = msg_in.m_EyePosition.x;
      this->m_LightList.m_pHead = msg_in.m_LightList.m_pHead;
      this->m_LastEyePosition.x = x;
      this->m_LastEyePosition.y = msg_in.m_EyePosition.y;
      this->m_LastEyePosition.z = msg_in.m_EyePosition.z;
      CLightingPreviewThread::UpdateIncrementalForNewLightList(this);
      CLightingPreviewThread::DiscardResults(this, a2, a3: (int)this);
      result = false;
      break;
    default:
LABEL_6:
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10052EF0
// Name: public: void CLightingPreviewThread::Run(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10052F80
// Name: unsigned int LightingPreviewThreadFN(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl LightingPreviewThreadFN()
{
  CLightingPreviewThread LPreviewObject; // [esp+0h] [ebp-7C8h] BYREF
  ThreadPoolStartParams_t startParams; // [esp+690h] [ebp-138h] BYREF
  CPUInformation pCPUInfo; // [esp+7A4h] [ebp-24h]
  int v4; // [esp+7C4h] [ebp-4h]

  CLightingPreviewThread::CLightingPreviewThread(this: &LPreviewObject);
  v4 = 0;
  s_pThis = &LPreviewObject;
  _ThreadSetPriority(a1: 0, a2: -2);
  s_pThreadPool = (IThreadPool *)_CreateNewThreadPool();
  pCPUInfo = *(CPUInformation *)_GetCPUInformation();
  *((_BYTE *)&startParams + 272) &= 0xFCu;
  if ( (*((_BYTE *)&startParams + 272) & 2) != 0 )
    qmemcpy(startParams.iAffinityTable, nullptr, sizeof(startParams.iAffinityTable));
  startParams.nThreads = pCPUInfo.m_nPhysicalProcessors - 1;
  s_nNumThreads = startParams.nThreads;
  startParams.nStackSize = 0x100000;
  startParams.fDistribute = TRS_TRUE;
  startParams.iThreadPriority = -2;
  s_pThreadPool->Start_2(this: s_pThreadPool, a2: &startParams);
  CLightingPreviewThread::Run(this: &LPreviewObject);
  v4 = -1;
  CLightingPreviewThread::~CLightingPreviewThread(this: &LPreviewObject);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009B9E0
// Name: public: class CUtlIntrusiveList<class CLightingPreviewLightDescription> CRender3D::BuildLightList(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlIntrusiveList<CLightingPreviewLightDescription> *__thiscall CRender3D::BuildLightList(
        CRender3D *this,
        CUtlIntrusiveList<CLightingPreviewLightDescription> *result)
{
  CMapWorld *m_pWorld; // esi
  CMapClass *i; // eax
  CMapEntity *v4; // eax
  EnumChildrenPos_t pos; // [esp+8h] [ebp-84h] BYREF

  result->m_pHead = nullptr;
  m_pWorld = this->m_pView->GetMapDoc(this: this->m_pView)->m_pWorld;
  if ( m_pWorld != nullptr )
  {
    for ( i = CMapClass::GetFirstDescendent(this: m_pWorld, &pos);
          i != nullptr;
          i = CMapClass::GetNextDescendent(this: m_pWorld, &pos) )
    {
      v4 = (CMapEntity *)__RTDynamicCast(
                           inptr: i,
                           VfDelta: 0,
                           SrcType: &CMapClass `RTTI Type Descriptor',
                           TargetType: &CMapEntity `RTTI Type Descriptor',
                           isReference: 0);
      if ( v4 != nullptr && (v4->m_EntityTypeFlags & 1) != 0 && (*((_BYTE *)&v4->CMapClass + 180) & 2) != 0 )
        AddEntityLightToLightList(e: v4, listout: result);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F8430
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x101F8440
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102B33E0
// Name: private: void CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute(
        CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *this)
{
  void (__thiscall *m_pfnBegin)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *); // eax
  int *m_pLimit; // ecx
  unsigned int v4; // edx
  int *v5; // esi
  int *v6; // ebx
  void (__thiscall *m_pfnEnd)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *); // eax
  unsigned int v8; // [esp+4h] [ebp-8h]
  int *pLimit; // [esp+8h] [ebp-4h]

  if ( this->m_pItems.m_value < this->m_pLimit )
  {
    m_pfnBegin = this->m_ItemProcessor.m_pfnBegin;
    if ( m_pfnBegin != nullptr )
      m_pfnBegin(this: this->m_ItemProcessor.m_pObject);
    m_pLimit = this->m_pLimit;
    v4 = 4 * this->m_nChunkSize;
    pLimit = m_pLimit;
    v8 = v4;
    do
    {
      v5 = (int *)_InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pItems, v4);
      v6 = (int *)((char *)v5 + v4);
      if ( m_pLimit < (int *)((char *)v5 + v4) )
        v6 = m_pLimit;
      if ( v5 < v6 )
      {
        do
          this->m_ItemProcessor.m_pfnProcess(this: this->m_ItemProcessor.m_pObject, a2: v5++);
        while ( v5 < v6 );
        m_pLimit = pLimit;
        v4 = v8;
      }
    }
    while ( v5 < m_pLimit );
    m_pfnEnd = this->m_ItemProcessor.m_pfnEnd;
    if ( m_pfnEnd != nullptr )
      m_pfnEnd(this: this->m_ItemProcessor.m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3840
// Name: public: void CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1>::Run(int __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::Run(
        CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *this,
        int *pItems,
        unsigned int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  unsigned int v6; // ebx
  IThreadPool *v8; // ecx
  int *v9; // eax
  int v10; // ebx
  int v11; // eax
  void *v12; // esp
  int i; // esi
  CFunctor *v14; // eax
  CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *v15; // ecx
  _DWORD v16[3]; // [esp+0h] [ebp-10h]
  CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *v17; // [esp+Ch] [ebp-4h]

  v6 = nItems;
  v17 = this;
  if ( nItems != 0 )
  {
    v8 = pThreadPool;
    this->m_nChunkSize = nChunkSize;
    if ( v8 == nullptr )
    {
      pThreadPool = _g_pThreadPool;
      v8 = _g_pThreadPool;
    }
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v9 = &pItems[v6];
    v10 = v6 - 1;
    this->m_pLimit = v9;
    if ( v10 > nMaxParallel )
      v10 = nMaxParallel;
    if ( v8 == nullptr )
      goto LABEL_18;
    v11 = v8->NumThreads(this: v8);
    if ( v10 > v11 )
      v10 = v11;
    if ( v10 > 0 )
    {
      v12 = alloca(4 * v10);
      for ( i = v10; i != 0; v16[i] = nItems )
      {
        --i;
        v14 = (CFunctor *)operator new(nSize: 0x18u);
        if ( v14 != nullptr )
        {
          v15 = v17;
          v14[1].m_nUserID = 1;
          v14->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v14[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v14[2].__vftable = (CFunctor_vtbl *)CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute;
          v14[2].m_nUserID = (unsigned int)v15;
        }
        else
        {
          v14 = nullptr;
        }
        pThreadPool->AddFunctorInternal(this: pThreadPool, a2: v14, a3: (CJob **)&nItems, a4: nullptr, a5: 8u);
      }
      CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute(this: v17);
      do
      {
        CJob::Abort(this: (CJob *)v16[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v16[i] + 4))(a1: v16[i]);
        ++i;
      }
      while ( i < v10 );
    }
    else
    {
LABEL_18:
      CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10338E22
// Name: public: virtual void CCmdTarget::OnFinalRelease(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCmdTarget::OnFinalRelease(CCmdTarget *this)
{
  CTypeLibCache *v2; // eax

  AfxLockGlobals(nLockType: 13);
  v2 = this->GetTypeLibCache(this);
  if ( v2 != nullptr )
    CTypeLibCache::Unlock(this: v2);
  AfxUnlockGlobals(nLockType: 13);
  ((void (__thiscall *)(CCmdTarget *, int))this->dtr_CObject)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10347770
// Name: public: virtual void CMirrorFile::Abort(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMirrorFile::Abort(CMirrorFile *this)
{
  char *m_pszData; // eax

  CFile::Abort(this);
  m_pszData = this->m_strMirrorName.m_pszData;
  if ( *((_DWORD *)m_pszData - 3) != 0 )
    CFile::Remove(lpszFileName: m_pszData, pTM: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10369D6C
// Name: public: virtual void CFile::Abort(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFile::Abort(CFile *this)
{
  if ( this->m_hFile != (void *)-1 )
  {
    CloseHandle(hObject: this->m_hFile);
    this->m_hFile = (void *)-1;
  }
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strFileName);
}

//------------------------------------------------------------------------------
// Address: 0x1036AB46
// Name: public: virtual void COleStreamFile::Abort(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COleStreamFile::Abort(COleStreamFile *this)
{
  IUnknown **p_m_lpStream; // esi

  p_m_lpStream = &this->m_lpStream;
  if ( this->m_lpStream != nullptr )
  {
    ((void (__stdcall *)(IUnknown *))(*p_m_lpStream)->__vftable[3].QueryInterface)(a1: *p_m_lpStream);
    _AfxRelease(lplpUnknown: p_m_lpStream);
  }
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strStorageName);
}

//------------------------------------------------------------------------------
// Address: 0x10401045
// Name: public: virtual void CMemFile::Abort(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemFile::Abort(CMemFile *this)
{
  this->Close(this);
}

//------------------------------------------------------------------------------
// Address: 0x1049BA20
// Name: public: virtual void CMemberFunctor0<class CParallelProcessor<class CPresetSlider __near *,class CFuncJobItemProcessor<class CPresetSlider __near *>,1> __near *,void (CParallelProcessor<class CPresetSlider __near *,class CFuncJobItemProcessor<class CPresetSlider __near *>,1>::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *,void (__thiscall CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *,void (__thiscall CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *))LODWORD(this->m_Proxy.m_pfnProxied))(a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied));
}

//------------------------------------------------------------------------------
// Address: 0x1049CAE0
// Name: public: void CParallelProcessor<class CPresetSlider __near *,class CFuncJobItemProcessor<class CPresetSlider __near *>,1>::Run(class CPresetSlider __near * __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::Run(
        CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *this,
        CPresetSlider **pItems,
        int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  IThreadPool *v7; // esi
  int v8; // eax
  int v9; // edi
  int v10; // eax
  void *v11; // esp
  CFunctor *v12; // eax
  CFunctor v13; // xmm0_8
  CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *v14; // ecx
  int i; // esi
  _DWORD v16[3]; // [esp+0h] [ebp-20h]
  CFunctor v17; // [esp+Ch] [ebp-14h]
  CFunctor v18; // [esp+14h] [ebp-Ch]
  CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *v19; // [esp+1Ch] [ebp-4h]
  int nJobs; // [esp+2Ch] [ebp+Ch]

  v19 = this;
  if ( nItems != 0 )
  {
    v7 = pThreadPool;
    this->m_nChunkSize = nChunkSize;
    if ( v7 == nullptr )
      v7 = _g_pThreadPool;
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v8 = nMaxParallel;
    v9 = nItems - 1;
    this->m_pLimit = &pItems[nItems];
    nJobs = v9;
    if ( v9 > v8 )
    {
      nJobs = v8;
      v9 = v8;
    }
    if ( v7 == nullptr )
      goto LABEL_18;
    v10 = v7->NumThreads(this: v7);
    if ( v9 > v10 )
    {
      nJobs = v10;
      v9 = v10;
    }
    if ( v9 > 0 )
    {
      v11 = alloca(4 * v9);
      v17.__vftable = (CFunctor_vtbl *)CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::DoExecute;
      v17.m_nUserID = 0;
      v18 = 0;
      do
      {
        --v9;
        v12 = (CFunctor *)operator new(nSize: 0x28u);
        if ( v12 != nullptr )
        {
          v13 = v17;
          v14 = v19;
          v12[1].m_nUserID = 1;
          v12->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *,void (__thiscall CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v12[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *,void (__thiscall CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v12[2] = v13;
          v12[3] = v18;
          v12[4].__vftable = (CFunctor_vtbl *)v14;
        }
        else
        {
          v12 = nullptr;
        }
        v7->AddFunctorInternal(this: v7, a2: v12, a3: (CJob **)&nChunkSize, a4: nullptr, a5: 8u);
        v16[v9] = nChunkSize;
      }
      while ( v9 != 0 );
      CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::DoExecute(this: v19);
      for ( i = 0; i < nJobs; ++i )
      {
        CJob::Abort(this: (CJob *)v16[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v16[i] + 4))(a1: v16[i]);
      }
    }
    else
    {
LABEL_18:
      CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::DoExecute(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10338E52
// Name: protected: virtual struct AFX_CONNECTIONMAP const __near * CCmdTarget::GetConnectionMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_CONNECTIONMAP *__thiscall CCmdTarget::GetConnectionMap(CCmdTarget *this)
{
  return &CCmdTarget::connectionMap;
}

//------------------------------------------------------------------------------
// Address: 0x10338E58
// Name: protected: virtual struct AFX_OLECMDMAP const __near * CCmdTarget::GetCommandMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_OLECMDMAP *__thiscall CCmdTarget::GetCommandMap(CCmdTarget *this)
{
  return &CCmdTarget::commandMap;
}

//------------------------------------------------------------------------------
// Address: 0x10338E5E
// Name: public: CCmdUI::CCmdUI(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCmdUI *__thiscall CCmdUI::CCmdUI(CCmdUI *this)
{
  this->__vftable = (CCmdUI_vtbl *)&CCmdUI::`vftable';
  this->m_nIndexMax = 0;
  this->m_nIndex = 0;
  this->m_nID = 0;
  this->m_pParentMenu = nullptr;
  this->m_pSubMenu = nullptr;
  this->m_pMenu = nullptr;
  this->m_pOther = nullptr;
  this->m_bContinueRouting = 0;
  this->m_bEnableChanged = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10338E84
// Name: public: int CCmdUI::DoUpdate(class CCmdTarget __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CCmdUI::DoUpdate(CCmdUI *this, CCmdTarget *pTarget, int bDisableIfNoHndler)
{
  unsigned int m_nID; // eax
  CCmdTarget_vtbl *v6; // eax
  int v7; // eax
  unsigned int v9; // [esp-14h] [ebp-24h]
  AFX_CMDHANDLERINFO info; // [esp+8h] [ebp-8h] BYREF
  int bResult; // [esp+18h] [ebp+8h]

  m_nID = this->m_nID;
  if ( m_nID == 0 || (_WORD)m_nID == 0xFFFF )
    return 1;
  if ( pTarget == nullptr )
    AfxThrowInvalidArgException();
  this->m_bEnableChanged = 0;
  bResult = pTarget->OnCmdMsg(this: pTarget, a2: m_nID, a3: -1, a4: this, a5: nullptr);
  if ( bDisableIfNoHndler != 0 && this->m_bEnableChanged == 0 )
  {
    v6 = pTarget->__vftable;
    v9 = this->m_nID;
    info.pTarget = nullptr;
    v7 = v6->OnCmdMsg(this: pTarget, a2: v9, a3: 0, a4: this, a5: &info);
    this->Enable(this, a2: v7);
  }
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x10338EF4
// Name: public: virtual struct CRuntimeClass __near * CCmdTarget::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CCmdTarget::GetRuntimeClass(CCmdTarget *this)
{
  return &CCmdTarget::classCCmdTarget;
}

//------------------------------------------------------------------------------
// Address: 0x10338EFA
// Name: public: CCmdTarget::CCmdTarget(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCmdTarget *__thiscall CCmdTarget::CCmdTarget(CCmdTarget *this)
{
  this->m_pModuleState = AfxGetModuleState();
  this->m_dwRef = 1;
  this->m_bResultExpected = 1;
  this->m_pOuterUnknown = nullptr;
  this->m_xInnerUnknown = 0;
  this->m_xDispatch.m_vtbl = 0;
  this->m_xConnPtContainer.m_vtbl = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10338F22
// Name: public: virtual CCmdTarget::~CCmdTarget(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CCmdTarget::~CCmdTarget(CCmdTarget *this)
{
  unsigned int m_vtbl; // eax

  m_vtbl = this->m_xDispatch.m_vtbl;
  if ( m_vtbl != 0 )
    (*(void (**)(void))(m_vtbl + 28))();
  this->m_pModuleState = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10338F39
// Name: public: void CCmdTarget::BeginWaitCursor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CCmdTarget::BeginWaitCursor(CCmdTarget *this)
{
  AFX_MODULE_STATE *ModuleState; // eax

  ModuleState = AfxGetModuleState();
  ModuleState->m_pCurrentWinApp->DoWaitCursor(this: ModuleState->m_pCurrentWinApp, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10338F4E
// Name: public: void CCmdTarget::EndWaitCursor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CCmdTarget::EndWaitCursor(CCmdTarget *this)
{
  AFX_MODULE_STATE *ModuleState; // eax

  ModuleState = AfxGetModuleState();
  ModuleState->m_pCurrentWinApp->DoWaitCursor(this: ModuleState->m_pCurrentWinApp, a2: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10338F63
// Name: protected: virtual struct AFX_MSGMAP const __near * CCmdTarget::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CCmdTarget::GetMessageMap(CCmdTarget *this)
{
  return &messageMap_11;
}

//------------------------------------------------------------------------------
// Address: 0x1034778D
// Name: public: virtual void CMirrorFile::Close(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMirrorFile::Close(CMirrorFile *this)
{
  const char *v2; // edi
  char *m_pszData; // eax

  v2 = (const char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)this->m_strFileName.m_pszData - 1)[1];
  CFile::Close(this);
  m_pszData = this->m_strMirrorName.m_pszData;
  if ( *((_DWORD *)m_pszData - 3) != 0
    && !ReplaceFileA(
          lpReplacedFileName: v2,
          lpReplacementFileName: m_pszData,
          lpBackupFileName: nullptr,
          dwReplaceFlags: 0,
          lpExclude: nullptr,
          lpReserved: nullptr) )
  {
    CFile::Remove(lpszFileName: v2, pTM: nullptr);
    CFile::Rename(lpszOldName: this->m_strMirrorName.m_pszData, lpszNewName: v2, pTM: nullptr);
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)v2 - 1);
}

//------------------------------------------------------------------------------
// Address: 0x103477F1
// Name: public: CMirrorFile::CMirrorFile(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMirrorFile *__thiscall CMirrorFile::CMirrorFile(CMirrorFile *this)
{
  ATL::IAtlStringMgr *StringManager; // eax

  CFile::CFile(this);
  this->__vftable = (CMirrorFile_vtbl *)&CMirrorFile::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strMirrorName, pStringMgr: StringManager);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10347813
// Name: public: virtual CMirrorFile::~CMirrorFile(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMirrorFile::~CMirrorFile(CMirrorFile *this)
{
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strMirrorName.m_pszData - 1);
  CFile::~CFile(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034782B
// Name: public: virtual long CDocument::XObjectWithSite::SetSite(struct IUnknown __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XObjectWithSite::SetSite(CDocument::XObjectWithSite *this, IUnknown *punkSite)
{
  int v2; // eax
  void (__stdcall ***v3)(_DWORD, GUID *, CDocument::XObjectWithSite *); // ebx
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+Ch] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 44));
  if ( *((IUnknown **)this - 22) != punkSite )
    ATL::AtlComPtrAssign(pp: (IUnknown **)this - 22, lp: punkSite);
  v2 = *((_DWORD *)this + 2);
  if ( v2 != 0 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(a1: *((_DWORD *)this + 2));
    *((_DWORD *)this + 2) = 0;
  }
  v3 = *((void (__stdcall ****)(_DWORD, GUID *, CDocument::XObjectWithSite *))this - 22);
  if ( v3 != nullptr )
    (**v3)(a1: v3, a2: &_GUID_fec87aaf_35f9_447a_adb7_20234491401a, a3: this + 2);
  (*(void (__thiscall **)(CDocument::XObjectWithSite *))(*((_DWORD *)this - 51) + 164))(a1: this - 51);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10369D8D
// Name: public: CFile::CFile(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFile *__thiscall CFile::CFile(CFile *this)
{
  ATL::IAtlStringMgr *StringManager; // eax

  this->__vftable = (CFile_vtbl *)&CFile::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strFileName, pStringMgr: StringManager);
  this->m_hFile = (void *)-1;
  this->m_bCloseOnDelete = 0;
  this->m_pTM = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10369DB6
// Name: public: CFile::CFile(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFile *__thiscall CFile::CFile(CFile *this, void *hFile)
{
  ATL::IAtlStringMgr *StringManager; // eax

  this->__vftable = (CFile_vtbl *)&CFile::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strFileName, pStringMgr: StringManager);
  this->m_bCloseOnDelete = 0;
  this->m_pTM = nullptr;
  this->m_hFile = hFile;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10369DE7
// Name: public: virtual class CFile __near * CFile::Duplicate(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFile *__thiscall CFile::Duplicate(CFile *this)
{
  CFile *v2; // eax
  CFile *v3; // esi
  HANDLE v4; // eax
  DWORD LastError; // eax
  void *m_hFile; // [esp-18h] [ebp-3Ch]
  HANDLE CurrentProcess; // [esp-14h] [ebp-38h]
  char *m_pszData; // [esp-4h] [ebp-28h]
  void *hFile; // [esp+14h] [ebp-10h] BYREF
  int v11; // [esp+20h] [ebp-4h]

  v2 = (CFile *)operator new(nSize: 0x14u);
  v11 = 0;
  if ( v2 != nullptr )
    v3 = CFile::CFile(this: v2);
  else
    v3 = nullptr;
  v11 = -1;
  CurrentProcess = GetCurrentProcess();
  m_hFile = this->m_hFile;
  v4 = GetCurrentProcess();
  if ( !DuplicateHandle(
          hSourceProcessHandle: v4,
          hSourceHandle: m_hFile,
          hTargetProcessHandle: CurrentProcess,
          lpTargetHandle: &hFile,
          dwDesiredAccess: 0,
          bInheritHandle: false,
          dwOptions: 2u) )
  {
    if ( v3 != nullptr )
      ((void (__thiscall *)(CFile *, int))v3->dtr_CObject)(a1: v3, a2: 1);
    m_pszData = this->m_strFileName.m_pszData;
    LastError = GetLastError();
    CFileException::ThrowOsError(lOsError: LastError, lpszFileName: m_pszData);
  }
  v3->m_hFile = hFile;
  v3->m_bCloseOnDelete = this->m_bCloseOnDelete;
  v3->m_pTM = this->m_pTM;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10369E71
// Name: int AfxGetInProcServer(char const __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall AfxGetInProcServer(
        HKEY__ *lpszCLSID,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *str)
{
  BOOL v2; // esi
  unsigned int dwType; // [esp+8h] [ebp-14h] BYREF
  char *lpsz; // [esp+Ch] [ebp-10h]
  unsigned int dwSize; // [esp+10h] [ebp-Ch] BYREF
  HKEY__ *hKey; // [esp+14h] [ebp-8h] BYREF
  HKEY__ *hKeyCLSID; // [esp+18h] [ebp-4h] BYREF

  v2 = false;
  hKey = nullptr;
  lpsz = ATL::CSimpleStringT<char,0>::PrepareWrite(this: str, nLength: 260);
  dwSize = 260;
  dwType = 0;
  if ( RegOpenKeyExW(hKey: HKEY_CLASSES_ROOT, lpSubKey: L"CLSID", ulOptions: 0, samDesired: 0x20019u, phkResult: &hKey) == 0 )
  {
    hKeyCLSID = nullptr;
    if ( RegOpenKeyExA(hKey, lpSubKey: (LPCSTR)lpszCLSID, ulOptions: 0, samDesired: 0x20019u, phkResult: &hKeyCLSID) == 0 )
    {
      lpszCLSID = nullptr;
      if ( RegOpenKeyExW(
             hKey: hKeyCLSID,
             lpSubKey: L"InProcServer32",
             ulOptions: 0,
             samDesired: 1u,
             phkResult: &lpszCLSID) == 0 )
      {
        v2 = RegQueryValueExA(
               hKey: lpszCLSID,
               lpValueName: &var,
               lpReserved: nullptr,
               lpType: &dwType,
               lpData: (LPBYTE)lpsz,
               lpcbData: &dwSize) == 0;
        RegCloseKey(hKey: lpszCLSID);
      }
      RegCloseKey(hKey: hKeyCLSID);
    }
    RegCloseKey(hKey);
  }
  ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: str, nNewLength: -1);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10369F33
// Name: void AfxGetRoot(char const __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxGetRoot(
        const char *lpszPath,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strRoot)
{
  unsigned __int8 *v2; // edi
  int v3; // eax

  v2 = (unsigned __int8 *)ATL::CSimpleStringT<char,0>::PrepareWrite(this: strRoot, nLength: 260);
  memset(dst: v2, value: 0, count: 0x104u);
  v3 = _mbsnbcpy_s(_Arg1: v2, _Arg2: 0x104u, _Arg3: (const unsigned __int8 *)lpszPath, _Arg4: 0xFFFFFFFF);
  AfxCrtErrorCheck(error: v3);
  PathStripToRootA(pszPath: (LPSTR)v2);
  ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: strRoot, nNewLength: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10369F7F
// Name: public: virtual CFile::~CFile(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CFile::~CFile(CFile *this)
{
  this->__vftable = (CFile_vtbl *)&CFile::`vftable';
  if ( this->m_hFile != (void *)-1 && this->m_bCloseOnDelete != 0 )
    CFile::Close(this);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strFileName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1036A0A7
// Name: void _AfxFillExceptionInfo(class CFileException __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _AfxFillExceptionInfo(CFileException *pException, const char *lpszFileName)
{
  DWORD LastError; // eax

  if ( pException != nullptr )
  {
    LastError = GetLastError();
    pException->m_lOsError = LastError;
    pException->m_cause = CFileException::OsErrorToException(lOsErr: LastError);
    ATL::CSimpleStringT<char,0>::SetString(this: &pException->m_strFileName, pszSrc: lpszFileName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036A0D6
// Name: int _AfxFullPath2(char __near *,char const __near *,class CFileException __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _AfxFullPath2(char *lpszPathOut, char *lpszFileIn, CFileException *pException)
{
  DWORD FullPathNameA; // eax
  int v4; // eax
  ATL::IAtlStringMgr *StringManager; // eax
  HANDLE FirstFileA; // eax
  int v8; // eax
  int v9; // eax
  unsigned __int8 *v10; // [esp-4h] [ebp-178h]
  unsigned __int8 *v11; // [esp-4h] [ebp-178h]
  DWORD MaximumComponentLength; // [esp+10h] [ebp-164h] BYREF
  DWORD FileSystemFlags; // [esp+14h] [ebp-160h] BYREF
  LPSTR FilePart; // [esp+18h] [ebp-15Ch] BYREF
  unsigned __int8 *_Arg3; // [esp+1Ch] [ebp-158h]
  ATL::CSimpleStringT<char,0> v16; // [esp+20h] [ebp-154h] BYREF
  _WIN32_FIND_DATAA FindFileData; // [esp+24h] [ebp-150h] BYREF
  int v18; // [esp+170h] [ebp-4h]

  _Arg3 = (unsigned __int8 *)lpszFileIn;
  if ( lpszPathOut == nullptr || lpszFileIn == nullptr )
    AfxThrowInvalidArgException();
  FullPathNameA = GetFullPathNameA(
                    lpFileName: lpszFileIn,
                    nBufferLength: 0x104u,
                    lpBuffer: lpszPathOut,
                    lpFilePart: &FilePart);
  if ( FullPathNameA == 0 )
  {
    v4 = _mbsnbcpy_s(_Arg1: (unsigned __int8 *)lpszPathOut, _Arg2: 0x104u, _Arg3, _Arg4: 0xFFFFFFFF);
    AfxCrtErrorCheck(error: v4);
    _AfxFillExceptionInfo(pException, lpszFileName: (const char *)_Arg3);
    return 0;
  }
  if ( FullPathNameA >= 0x104 )
  {
    if ( pException != nullptr )
    {
      v10 = _Arg3;
      pException->m_cause = 3;
      ATL::CSimpleStringT<char,0>::SetString(this: &pException->m_strFileName, pszSrc: (const char *)v10);
    }
    return 0;
  }
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v16, pStringMgr: StringManager);
  v18 = 0;
  AfxGetRoot(lpszPath: lpszPathOut, strRoot: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v16);
  if ( !PathIsUNCA(pszPath: v16.m_pszData) )
  {
    if ( !GetVolumeInformationA(
            lpRootPathName: v16.m_pszData,
            lpVolumeNameBuffer: nullptr,
            nVolumeNameSize: 0,
            lpVolumeSerialNumber: nullptr,
            lpMaximumComponentLength: &MaximumComponentLength,
            lpFileSystemFlags: &FileSystemFlags,
            lpFileSystemNameBuffer: nullptr,
            nFileSystemNameSize: 0) )
    {
LABEL_12:
      _AfxFillExceptionInfo(pException, lpszFileName: (const char *)_Arg3);
LABEL_13:
      ATL::CStringData::Release(this: (ATL::CStringData *)v16.m_pszData - 1);
      return 0;
    }
    if ( (FileSystemFlags & 2) == 0 )
      CharUpperA(lpsz: lpszPathOut);
    if ( (FileSystemFlags & 4) == 0 )
    {
      FirstFileA = FindFirstFileA(lpFileName: (LPCSTR)_Arg3, lpFindFileData: &FindFileData);
      if ( FirstFileA != (HANDLE)-1 )
      {
        FindClose(hFindFile: FirstFileA);
        if ( FilePart == nullptr || FilePart <= lpszPathOut )
          goto LABEL_12;
        v8 = lstrlenA(lpString: FindFileData.cFileName);
        if ( FilePart - lpszPathOut + v8 >= 260 )
        {
          if ( pException != nullptr )
          {
            v11 = _Arg3;
            pException->m_cause = 3;
            ATL::CSimpleStringT<char,0>::SetString(this: &pException->m_strFileName, pszSrc: (const char *)v11);
          }
          goto LABEL_13;
        }
        v9 = strcpy_s(_Dst: FilePart, _SizeInBytes: 260 - (FilePart - lpszPathOut), _Src: FindFileData.cFileName);
        AfxCrtErrorCheck(error: v9);
      }
    }
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)v16.m_pszData - 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1036A2A7
// Name: int AfxFullPath(char __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxFullPath(char *lpszPathOut, char *lpszFileIn)
{
  return _AfxFullPath2(lpszPathOut, lpszFileIn, pException: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1036A2BD
// Name: void AfxGetModuleFileName(struct HINSTANCE__ __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxGetModuleFileName(
        HINSTANCE__ *hInst,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strFileName)
{
  char szLongPathName[260]; // [esp+4h] [ebp-108h] BYREF

  GetModuleFileNameA(hModule: hInst, lpFilename: szLongPathName, nSize: 0x104u);
  ATL::CSimpleStringT<char,0>::SetString(this: strFileName, pszSrc: szLongPathName);
}

//------------------------------------------------------------------------------
// Address: 0x1036A309
// Name: void AfxGetModuleShortFileName(struct HINSTANCE__ __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxGetModuleShortFileName(
        HINSTANCE__ *hInst,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strShortName)
{
  CHAR *v2; // eax
  char szLongPathName[260]; // [esp+8h] [ebp-108h] BYREF

  GetModuleFileNameA(hModule: hInst, lpFilename: szLongPathName, nSize: 0x104u);
  v2 = ATL::CSimpleStringT<char,0>::PrepareWrite(this: strShortName, nLength: 260);
  if ( GetShortPathNameA(lpszLongPath: szLongPathName, lpszShortPath: v2, cchBuffer: 0x104u) == 0 )
    ATL::CSimpleStringT<char,0>::SetString(this: strShortName, pszSrc: szLongPathName);
  ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: strShortName, nNewLength: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1036A37C
// Name: public: virtual int CFile::Open(char const __near *,unsigned int,class CFileException __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFile::Open(CFile *this, char *lpszFileName, unsigned int nOpenFlags, CFileException *pException)
{
  CFileException *v5; // edi
  int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // eax
  unsigned int v9; // edx
  ATL::CAtlTransactionManager *m_pTM; // ecx
  HANDLE v11; // eax
  int v13; // [esp-4h] [ebp-130h]
  char *v14; // [esp-4h] [ebp-130h]
  _SECURITY_ATTRIBUTES sa; // [esp+Ch] [ebp-120h] BYREF
  CFileException *v16; // [esp+18h] [ebp-114h]
  unsigned int dwAccess; // [esp+1Ch] [ebp-110h]
  char *psz; // [esp+20h] [ebp-10Ch]
  char szTemp[260]; // [esp+24h] [ebp-108h] BYREF
  unsigned int nOpenFlagsa; // [esp+138h] [ebp+Ch]

  nOpenFlagsa = nOpenFlags & 0xFFFF7FFF;
  this->m_bCloseOnDelete = 0;
  this->m_hFile = (void *)-1;
  v5 = pException;
  psz = lpszFileName;
  v16 = pException;
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strFileName);
  if ( lpszFileName == nullptr )
  {
LABEL_38:
    if ( v5 != nullptr )
    {
      v14 = psz;
      v5->m_cause = 3;
      ATL::CSimpleStringT<char,0>::SetString(this: &v5->m_strFileName, pszSrc: v14);
    }
    return 0;
  }
  if ( _LN111_3(psz, cchMax: 0x104u, pcchLength: nullptr) < 0 )
  {
    v5 = v16;
    goto LABEL_38;
  }
  if ( _AfxFullPath2(lpszPathOut: szTemp, lpszFileIn: psz, pException: v16) == 0 )
    return 0;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strFileName, pszSrc: szTemp);
  dwAccess = 0;
  if ( (nOpenFlagsa & 3) != 0 )
  {
    if ( (nOpenFlagsa & 3) == 1 )
    {
      dwAccess = 0x40000000;
    }
    else if ( (nOpenFlagsa & 3) == 2 )
    {
      dwAccess = -1073741824;
    }
  }
  else
  {
    dwAccess = 0x80000000;
  }
  v6 = nOpenFlagsa & 0x70;
  if ( (nOpenFlagsa & 0x70) != 0 && v6 != 16 )
  {
    switch ( v6 )
    {
      case ' ':
        v7 = 1;
        goto LABEL_20;
      case '0':
        v13 = 2;
        goto LABEL_17;
      case '@':
        v13 = 3;
LABEL_17:
        v7 = v13;
LABEL_20:
        sa.nLength = 12;
        sa.lpSecurityDescriptor = nullptr;
        sa.bInheritHandle = (nOpenFlagsa & 0x80) == 0;
        if ( (nOpenFlagsa & 0x1000) != 0 )
          v8 = (nOpenFlagsa & 0x2000) != 0 ? 4 : 2;
        else
          v8 = 3;
        v9 = 128;
        if ( (nOpenFlagsa & 0x10000) != 0 )
          v9 = 536871040;
        if ( (nOpenFlagsa & 0x20000) != 0 )
          v9 |= 0x80000000;
        if ( (nOpenFlagsa & 0x40000) != 0 )
          v9 |= 0x10000000u;
        if ( (nOpenFlagsa & 0x80000) != 0 )
          v9 |= 0x8000000u;
        m_pTM = this->m_pTM;
        if ( m_pTM != nullptr )
          v11 = ATL::CAtlTransactionManager::CreateFileA(
                  this: m_pTM,
                  lpFileName: psz,
                  dwDesiredAccess: dwAccess,
                  dwShareMode: v7,
                  lpSecurityAttributes: &sa,
                  dwCreationDisposition: v8,
                  dwFlagsAndAttributes: v9,
                  hTemplateFile: nullptr);
        else
          v11 = CreateFileA(
                  lpFileName: psz,
                  dwDesiredAccess: dwAccess,
                  dwShareMode: v7,
                  lpSecurityAttributes: &sa,
                  dwCreationDisposition: v8,
                  dwFlagsAndAttributes: v9,
                  hTemplateFile: nullptr);
        if ( v11 != (HANDLE)-1 )
        {
          this->m_hFile = v11;
          this->m_bCloseOnDelete = 1;
          return 1;
        }
        _AfxFillExceptionInfo(pException: v16, lpszFileName: psz);
        return 0;
      default:
        break;
    }
  }
  v7 = 0;
  goto LABEL_20;
}

//------------------------------------------------------------------------------
// Address: 0x1036AB6C
// Name: public: virtual void COleStreamFile::Close(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleStreamFile::Close(COleStreamFile *this)
{
  IUnknown **p_m_lpStream; // edi

  p_m_lpStream = &this->m_lpStream;
  if ( this->m_lpStream != nullptr )
  {
    this->Flush(this);
    _AfxRelease(lplpUnknown: p_m_lpStream);
  }
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strStorageName);
}

//------------------------------------------------------------------------------
// Address: 0x1040104A
// Name: public: virtual void CMemFile::UnlockRange(unsigned __int64,unsigned __int64)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall __noreturn CMemFile::UnlockRange(
        CMemFile *this,
        unsigned __int64 __formal,
        unsigned __int64 __formal_4)
{
  AfxThrowNotSupportedException();
}

//------------------------------------------------------------------------------
// Address: 0x10401050
// Name: public: virtual class CFile __near * CMemFile::Duplicate(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall __noreturn CMemFile::Duplicate(CMemFile *this)
{
  AfxThrowNotSupportedException();
}

//------------------------------------------------------------------------------
// Address: 0x10401055
// Name: public: virtual unsigned int CMemFile::GetBufferPtr(unsigned int,unsigned int,void __near * __near *,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMemFile::GetBufferPtr(
        CMemFile *this,
        unsigned int nCommand,
        unsigned int nCount,
        void **ppBufStart,
        void **ppBufMax)
{
  unsigned int m_nPosition; // eax
  void **v8; // edx
  unsigned int v9; // edi
  unsigned int v10; // eax
  unsigned int v11; // ecx
  unsigned int m_nBufferSize; // eax
  unsigned int m_nFileSize; // eax
  unsigned __int8 *v14; // eax

  if ( nCommand == 3 )
    return this->m_nGrowBytes != 0;
  if ( nCommand == 2 )
  {
    this->m_nPosition += nCount;
    m_nPosition = this->m_nPosition;
    if ( m_nPosition > this->m_nFileSize )
      this->m_nFileSize = m_nPosition;
    return 0;
  }
  else if ( ppBufStart != nullptr && (v8 = ppBufMax, ppBufMax != nullptr) )
  {
    v9 = nCount;
    if ( nCommand == 1 )
    {
      v10 = this->m_nPosition;
      v11 = v10 + nCount;
      if ( v10 + nCount < v10 || v11 < nCount )
        AfxThrowInvalidArgException();
      if ( v11 > this->m_nBufferSize )
      {
        this->GrowFile(this, a2: v11);
        v8 = ppBufMax;
      }
    }
    *ppBufStart = &this->m_lpBuffer[this->m_nPosition];
    if ( nCommand == 1 )
    {
      m_nBufferSize = nCount + this->m_nPosition;
      if ( this->m_nBufferSize < m_nBufferSize )
        m_nBufferSize = this->m_nBufferSize;
      *v8 = &this->m_lpBuffer[m_nBufferSize];
    }
    else
    {
      if ( nCount == -1 )
        v9 = this->m_nBufferSize - this->m_nPosition;
      m_nFileSize = v9 + this->m_nPosition;
      if ( this->m_nFileSize < m_nFileSize )
        m_nFileSize = this->m_nFileSize;
      v14 = &this->m_lpBuffer[m_nFileSize];
      *v8 = v14;
      this->m_nPosition += v14 - (_BYTE *)*ppBufStart;
    }
    return (_BYTE *)*v8 - (_BYTE *)*ppBufStart;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10401126
// Name: public: virtual struct CRuntimeClass __near * CMemFile::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMemFile::GetRuntimeClass(CMemFile *this)
{
  return &CMemFile::classCMemFile;
}

//------------------------------------------------------------------------------
// Address: 0x1040112C
// Name: public: virtual CMemFile::~CMemFile(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMemFile::~CMemFile(CMemFile *this)
{
  this->__vftable = (CMemFile_vtbl *)&CMemFile::`vftable';
  if ( this->m_lpBuffer != nullptr )
    CMemFile::Close(this);
  this->m_nGrowBytes = 0;
  this->m_nPosition = 0;
  this->m_nBufferSize = 0;
  this->m_nFileSize = 0;
  CFile::~CFile(this);
}

//------------------------------------------------------------------------------
// Address: 0x1040116F
// Name: protected: virtual unsigned char __near * CMemFile::Memcpy(unsigned char __near *,unsigned char const __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CMemFile::Memcpy(
        CMemFile *this,
        unsigned __int8 *lpMemTarget,
        const unsigned __int8 *lpMemSource,
        unsigned int nBytes)
{
  ATL::Checked::memcpy_s(_S1: lpMemTarget, _S1max: nBytes, _S2: lpMemSource, _N: nBytes);
  return lpMemTarget;
}
