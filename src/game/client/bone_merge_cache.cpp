// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/bone_merge_cache.cpp
// Functions: 10
// ============================================================

#include "game\client\bone_merge_cache.h"

//------------------------------------------------------------------------------
// Address: 0x10023C20
// Name: public: void CBoneMergeCache::Init(class C_BaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneMergeCache::Init(CBoneMergeCache *this, C_BaseAnimating *pOwner)
{
  this->m_pOwner = pOwner;
  this->m_pFollow = nullptr;
  this->m_pFollowHdr = nullptr;
  this->m_pOwnerHdr = nullptr;
  this->m_nFollowBoneSetupMask = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10023C40
// Name: public: class CUtlSymbol CUtlSymbolTableMT::AddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbol *__thiscall CUtlSymbolTableMT::AddString(CUtlSymbolTableMT *this, CUtlSymbol *result, const char *pString)
{
  if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)&this->m_lock, 0x10000, 0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: &this->m_lock);
  }
  else
  {
    this->m_lock.m_writerId = GetCurrentThreadId();
  }
  CUtlSymbolTable::AddString(this, result, pString);
  this->m_lock.m_writerId = 0;
  this->m_lock.m_lockInfo.m_i32 = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10023CA0
// Name: public: class CUtlSymbol CUtlSymbolTableMT::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbol *__thiscall CUtlSymbolTableMT::Find(CUtlSymbolTableMT *this, CUtlSymbol *result, const char *pString)
{
  if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)&this->m_lock, 0x10000, 0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: &this->m_lock);
  }
  else
  {
    this->m_lock.m_writerId = GetCurrentThreadId();
  }
  CUtlSymbolTable::Find(this, result, pString);
  this->m_lock.m_writerId = 0;
  this->m_lock.m_lockInfo.m_i32 = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10023D00
// Name: private: void CVarBitVecBase<unsigned short>::ReallocInts(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarBitVecBase<unsigned short>::ReallocInts(CVarBitVecBase<unsigned short> *this, int numInts)
{
  CVarBitVecBase<unsigned short> *m_pInt; // eax
  unsigned int *p_m_iBitStringStorage; // edi
  unsigned int *v5; // eax
  unsigned int v6; // ecx

  if ( numInts != 0 )
  {
    m_pInt = (CVarBitVecBase<unsigned short> *)this->m_pInt;
    p_m_iBitStringStorage = &this->m_iBitStringStorage;
    if ( m_pInt == (CVarBitVecBase<unsigned short> *)&this->m_iBitStringStorage )
    {
      if ( numInts != 1 )
      {
        v5 = (unsigned int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * numInts);
        v6 = *p_m_iBitStringStorage;
        this->m_pInt = v5;
        *v5 = v6;
      }
    }
    else if ( numInts == 1 )
    {
      *p_m_iBitStringStorage = *(_DWORD *)&m_pInt->m_numBits;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pInt);
      this->m_pInt = p_m_iBitStringStorage;
    }
    else
    {
      this->m_pInt = (unsigned int *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pInt, a3: 4 * numInts);
    }
  }
  else
  {
    if ( this->m_numInts > 1u )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pInt);
    this->m_pInt = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023DD0
// Name: public: void CVarBitVecBase<unsigned short>::Resize(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarBitVecBase<unsigned short>::Resize(
        CVarBitVecBase<unsigned short> *this,
        int resizeNumBits,
        bool bClearAll)
{
  int m_numInts; // ecx
  int v5; // edi
  unsigned int *v6; // eax
  unsigned int *p_m_iBitStringStorage; // eax
  unsigned int *m_pInt; // eax
  unsigned int *v9; // eax

  m_numInts = this->m_numInts;
  v5 = (resizeNumBits + 31) / 32;
  if ( v5 != m_numInts )
  {
    if ( this->m_pInt != nullptr )
    {
      CVarBitVecBase<unsigned short>::ReallocInts(this, numInts: (resizeNumBits + 31) / 32);
      if ( !bClearAll && resizeNumBits >= this->m_numBits )
      {
        v6 = &this->m_pInt[this->m_numInts - 1];
        *v6 &= `GetEndMask'::`2'::bitStringEndMasks[this->m_numBits & 0x1F];
        memset(dst: (int)&this->m_pInt[this->m_numInts], value: nullptr, count: 4 * (v5 - this->m_numInts));
      }
    }
    else
    {
      if ( v5 != 0 )
      {
        if ( v5 == 1 )
          p_m_iBitStringStorage = &this->m_iBitStringStorage;
        else
          p_m_iBitStringStorage = (unsigned int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * v5);
        this->m_pInt = p_m_iBitStringStorage;
      }
      bClearAll = true;
    }
    this->m_numInts = v5;
    if ( !bClearAll )
      goto LABEL_15;
    goto LABEL_13;
  }
  if ( bClearAll )
  {
LABEL_13:
    m_pInt = this->m_pInt;
    if ( m_pInt != nullptr )
      memset(dst: (int)m_pInt, value: nullptr, count: 4 * v5);
LABEL_15:
    this->m_numBits = resizeNumBits;
    return;
  }
  if ( resizeNumBits < this->m_numBits )
    goto LABEL_15;
  v9 = this->m_pInt;
  if ( v9 == nullptr )
    goto LABEL_15;
  v9[m_numInts - 1] &= `GetEndMask'::`2'::bitStringEndMasks[this->m_numBits & 0x1F];
  this->m_numBits = resizeNumBits;
}

//------------------------------------------------------------------------------
// Address: 0x10023EE0
// Name: public: CBoneMergeCache::CBoneMergeCache(void)
// Source: json
//------------------------------------------------------------------------------
CBoneMergeCache *__thiscall CBoneMergeCache::CBoneMergeCache(CBoneMergeCache *this)
{
  this->m_MergedBones.m_Memory.m_pMemory = nullptr;
  this->m_MergedBones.m_Memory.m_nAllocationCount = 0;
  this->m_MergedBones.m_Memory.m_nGrowSize = 0;
  this->m_MergedBones.m_Size = 0;
  this->m_MergedBones.m_pElements = nullptr;
  *(_QWORD *)&this->m_BoneMergeBits.m_numBits = 0;
  this->m_BoneMergeBits.m_pInt = nullptr;
  this->m_pOwner = nullptr;
  this->m_pFollow = nullptr;
  this->m_pFollowHdr = nullptr;
  this->m_pOwnerHdr = nullptr;
  this->m_nFollowBoneSetupMask = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10023F30
// Name: public: void CBoneMergeCache::UpdateCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneMergeCache::UpdateCache(CBoneMergeCache *this)
{
  C_BaseAnimating *m_pOwner; // edi
  CStudioHdr *m_pStudioHdr; // ebx
  C_BaseAnimating *FollowedEntity; // eax
  C_BaseAnimating *v5; // edi
  CStudioHdr *v6; // eax
  CStudioHdr *m_pOwnerHdr; // edx
  const char *v8; // ecx
  int m_nValue; // eax
  bool v10; // zf
  const studiohdr_t *v11; // eax
  int v12; // edi
  int v13; // ebx
  int m_Size; // ecx
  int m_nAllocationCount; // eax
  CBoneMergeCache::CMergedBone *m_pMemory; // edx
  int v17; // eax
  CBoneMergeCache::CMergedBone *v18; // ecx
  unsigned int *v19; // eax
  CStudioHdr *m_pFollowHdr; // ecx
  int j; // eax
  CStudioHdr *v22; // ecx
  const char *v23; // edi
  char *v24; // eax
  const studiohdr_t *v25; // eax
  char sz[258]; // [esp+8h] [ebp-11Ch] BYREF
  CUtlSymbol result; // [esp+10Ah] [ebp-1Ah] BYREF
  int v28; // [esp+10Ch] [ebp-18h]
  const char *v29; // [esp+110h] [ebp-14h]
  CBoneMergeCache::CMergedBone mergedBone; // [esp+114h] [ebp-10h]
  int i; // [esp+118h] [ebp-Ch]
  CStudioHdr *pTestHdr; // [esp+11Ch] [ebp-8h] BYREF
  bool bDeveloperDebugPrints; // [esp+123h] [ebp-1h]

  m_pOwner = this->m_pOwner;
  if ( this->m_pOwner != nullptr )
  {
    if ( m_pOwner->m_pStudioHdr == nullptr && m_pOwner->GetModel(this: &m_pOwner->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this: m_pOwner);
    m_pStudioHdr = m_pOwner->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      FollowedEntity = C_BaseAnimating::FindFollowedEntity(this: this->m_pOwner, a2: (int)this);
      v5 = FollowedEntity;
      pTestHdr = FollowedEntity != nullptr ? C_BaseAnimating::GetModelPtr(this: FollowedEntity) : nullptr;
      if ( v5 != this->m_pFollow || pTestHdr != this->m_pFollowHdr || m_pStudioHdr != this->m_pOwnerHdr )
      {
        CUtlVector<CBoneMergeCache::CMergedBone,CUtlMemory<CBoneMergeCache::CMergedBone,int>>::Purge(this: &this->m_MergedBones);
        if ( v5 != nullptr && (v6 = pTestHdr, pTestHdr != nullptr) )
        {
          this->m_pFollow = v5;
          this->m_pFollowHdr = v6;
          this->m_pOwnerHdr = m_pStudioHdr;
          CVarBitVecBase<unsigned short>::Resize(
            this: &this->m_BoneMergeBits,
            resizeNumBits: m_pStudioHdr->m_pStudioHdr->numbones,
            bClearAll: false);
          CBitVecT<CVarBitVecBase<unsigned short>>::ClearAll(this: &this->m_BoneMergeBits);
          m_pOwnerHdr = this->m_pOwnerHdr;
          v8 = (char *)m_pOwnerHdr->m_pStudioHdr + m_pOwnerHdr->m_pStudioHdr->boneindex;
          this->m_nFollowBoneSetupMask = 0x40000;
          if ( developer.m_pParent != nullptr )
            m_nValue = developer.m_pParent->m_Value.m_nValue;
          else
            m_nValue = 0;
          v10 = m_nValue == 0;
          v11 = m_pOwnerHdr->m_pStudioHdr;
          bDeveloperDebugPrints = !v10;
          LOWORD(v12) = 0;
          i = 0;
          if ( v11->numbones > 0 )
          {
            v29 = v8;
            do
            {
              v13 = Studio_BoneIndexByName(pStudioHdr: (mstudiobone_t *)this->m_pFollowHdr, pName: &v8[*(_DWORD *)v8]);
              if ( v13 >= 0 )
              {
                m_Size = this->m_MergedBones.m_Size;
                m_nAllocationCount = this->m_MergedBones.m_Memory.m_nAllocationCount;
                mergedBone.m_iMyBone = v12;
                mergedBone.m_iParentBone = v13;
                v28 = m_Size;
                if ( m_Size + 1 > m_nAllocationCount )
                {
                  CUtlMemory<CChoreoActor *,int>::Grow(
                    this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_MergedBones,
                    num: m_Size - m_nAllocationCount + 1);
                  m_Size = v28;
                }
                ++this->m_MergedBones.m_Size;
                m_pMemory = this->m_MergedBones.m_Memory.m_pMemory;
                v17 = this->m_MergedBones.m_Size - m_Size - 1;
                this->m_MergedBones.m_pElements = m_pMemory;
                if ( v17 > 0 )
                {
                  _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v17);
                  m_Size = v28;
                }
                v18 = &this->m_MergedBones.m_Memory.m_pMemory[m_Size];
                if ( v18 != nullptr )
                  *v18 = mergedBone;
                v19 = &this->m_BoneMergeBits.m_pInt[i >> 5];
                *v19 |= 1 << (i & 0x1F);
                m_pFollowHdr = this->m_pFollowHdr;
                if ( (m_pFollowHdr->m_boneFlags.m_Memory.m_pMemory[v13] & 0x40000) == 0 )
                {
                  for ( j = v13; j != -1; j = m_pFollowHdr->m_boneParent.m_Memory.m_pMemory[j] )
                  {
                    m_pFollowHdr->m_boneFlags.m_Memory.m_pMemory[j] |= 0x40000u;
                    m_pFollowHdr = this->m_pFollowHdr;
                  }
                  if ( bDeveloperDebugPrints )
                  {
                    v22 = this->m_pFollowHdr;
                    v23 = (char *)v22->m_pStudioHdr + 216 * v13 + v22->m_pStudioHdr->boneindex;
                    v24 = CStudioHdr::name(this: v22);
                    V_snprintf(
                      pDest: sz,
                      maxLen: 0x100u,
                      pFormat: "Performance warning: Add $bonemerge \"%s\" to QC that builds \"%s\"\n",
                      &v23[*(_DWORD *)v23],
                      v24);
                    if ( (_S5_8 & 1) == 0 )
                    {
                      _S5_8 |= 1u;
                      CUtlSymbolTable::CUtlSymbolTable(
                        this: &s_FollowerWarnings,
                        growSize: 0,
                        initSize: 32,
                        caseInsensitive: false);
                      CThreadSpinRWLock::CThreadSpinRWLock(this: &s_FollowerWarnings.m_lock);
                      atexit(func: CBoneMergeCache::UpdateCache_::_24_::_dynamic_atexit_destructor_for__s_FollowerWarnings__);
                    }
                    if ( CUtlSymbolTableMT::Find(this: &s_FollowerWarnings, &result, pString: sz)->m_Id == 0xFFFF )
                    {
                      CUtlSymbolTableMT::AddString(
                        this: &s_FollowerWarnings,
                        result: (CUtlSymbol *)&pTestHdr + 1,
                        pString: sz);
                      _Warning(a1: "%s", sz);
                    }
                  }
                }
              }
              v25 = this->m_pOwnerHdr->m_pStudioHdr;
              v12 = i + 1;
              v8 = v29 + 216;
              i = v12;
              v29 += 216;
            }
            while ( v12 < v25->numbones );
          }
          if ( this->m_MergedBones.m_Size == 0 )
            this->m_nFollowBoneSetupMask = 0;
        }
        else
        {
          this->m_pFollow = nullptr;
          this->m_pFollowHdr = nullptr;
          this->m_pOwnerHdr = nullptr;
          this->m_nFollowBoneSetupMask = 0;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024220
// Name: public: void CBoneMergeCache::MergeMatchingBones(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneMergeCache::MergeMatchingBones(CBoneMergeCache *this, int boneMask)
{
  int i; // edi
  CBoneMergeCache::CMergedBone *m_pMemory; // ecx
  int m_iMyBone; // eax
  CBoneMergeCache::CMergedBone *v6; // ecx

  CBoneMergeCache::UpdateCache(this);
  if ( this->m_pOwnerHdr != nullptr && this->m_MergedBones.m_Size != 0 )
  {
    ((void (__stdcall *)(_DWORD, int, int, _DWORD))this->m_pFollow->SetupBones)(
      a1: 0,
      a2: -1,
      a3: this->m_nFollowBoneSetupMask,
      a4: *(_DWORD *)(gpGlobals.m_Index + 12));
    for ( i = 0; i < this->m_MergedBones.m_Size; ++i )
    {
      m_pMemory = this->m_MergedBones.m_Memory.m_pMemory;
      m_iMyBone = m_pMemory[i].m_iMyBone;
      v6 = &m_pMemory[i];
      if ( (boneMask & this->m_pOwnerHdr->m_boneFlags.m_Memory.m_pMemory[m_iMyBone]) != 0 )
        MatrixCopy(
          in: &this->m_pFollow->m_BoneAccessor.m_pBones[v6->m_iParentBone],
          out: &this->m_pOwner->m_BoneAccessor.m_pBones[m_iMyBone]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100242C0
// Name: public: bool CBoneMergeCache::GetAimEntOrigin(class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBoneMergeCache::GetAimEntOrigin(CBoneMergeCache *this, Vector *pAbsOrigin, QAngle *pAbsAngles)
{
  CBoneMergeCache::CMergedBone *m_pMemory; // eax
  matrix3x4a_t *v5; // edi
  matrix3x4_t mBoneLocalInv; // [esp+Ch] [ebp-90h] BYREF
  matrix3x4_t mBoneLocal; // [esp+3Ch] [ebp-60h] BYREF
  matrix3x4_t mEntity; // [esp+6Ch] [ebp-30h] BYREF

  CBoneMergeCache::UpdateCache(this);
  if ( this->m_pOwnerHdr == nullptr || this->m_MergedBones.m_Size == 0 )
    return 0;
  ((void (__stdcall *)(_DWORD, int, int, _DWORD))this->m_pFollow->SetupBones)(
    a1: 0,
    a2: -1,
    a3: this->m_nFollowBoneSetupMask,
    a4: *(_DWORD *)(gpGlobals.m_Index + 12));
  m_pMemory = this->m_MergedBones.m_Memory.m_pMemory;
  v5 = &this->m_pFollow->m_BoneAccessor.m_pBones[m_pMemory->m_iParentBone];
  SetupSingleBoneMatrix(
    pOwnerHdr: this->m_pOwnerHdr,
    nSequence: this->m_pOwner->m_nSequence,
    iFrame: 0,
    iBone: m_pMemory->m_iMyBone,
    &mBoneLocal);
  MatrixInvert(in: &mBoneLocal, out: &mBoneLocalInv);
  ConcatTransforms(in1: v5, in2: &mBoneLocalInv, out: &mEntity);
  MatrixAngles(a1: (int)this, src: (const VMatrix *)&mEntity, vAngles: pAbsAngles);
  pAbsOrigin->x = mEntity.m_flMatVal[0][3];
  pAbsOrigin->y = mEntity.m_flMatVal[1][3];
  pAbsOrigin->z = mEntity.m_flMatVal[2][3];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1042F9A0
// Name: _CBoneMergeCache::UpdateCache_::_24_::_dynamic_atexit_destructor_for__s_FollowerWarnings__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CBoneMergeCache::UpdateCache_::_24_::_dynamic_atexit_destructor_for__s_FollowerWarnings__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_FollowerWarnings);
}
