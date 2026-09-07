// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: responserules/runtime/response_types_internal.cpp
// Functions: 7
// ============================================================

#include "responserules\runtime\response_types_internal.h"

//------------------------------------------------------------------------------
// Address: 0x103711A0
// Name: public: unsigned int ResponseRules::ResponseRulePartition::IndexFromDictElem(class ResponseRules::CResponseDict<struct ResponseRules::Rule __near *,unsigned short> __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ResponseRules::ResponseRulePartition::IndexFromDictElem(
        ResponseRules::ResponseRulePartition *this,
        ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> *pDict,
        __int16 elem)
{
  return elem & 0xFFF | ((((char *)pDict - (char *)this) / 56) << 16);
}

//------------------------------------------------------------------------------
// Address: 0x103712D0
// Name: public: int ResponseRules::ResponseRulePartition::Count(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ResponseRules::ResponseRulePartition::Count(ResponseRules::ResponseRulePartition *this)
{
  int v1; // eax
  int v2; // edi
  int v3; // esi
  int v4; // edx
  unsigned __int16 *p_m_NumElements; // ecx
  int i; // [esp+Ch] [ebp-4h]

  v1 = 0;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  p_m_NumElements = &this->m_RuleParts[1].m_Tree.m_NumElements;
  for ( i = 64; i != 0; --i )
  {
    v1 += *(p_m_NumElements - 28);
    v4 += *p_m_NumElements;
    v3 += p_m_NumElements[28];
    v2 += p_m_NumElements[56];
    p_m_NumElements += 112;
  }
  return v4 + v3 + v2 + v1;
}

//------------------------------------------------------------------------------
// Address: 0x10371740
// Name: public: void ResponseRules::ResponseRulePartition::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::ResponseRulePartition::RemoveAll(ResponseRules::ResponseRulePartition *this)
{
  unsigned __int16 j; // si
  UtlRBTreeNode_t<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  ResponseRules::Rule *elem; // ebx
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 256; i != 0; --i )
  {
    for ( j = CUtlRBTree<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder((CUtlRBTree<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)this);
          j != 0xFFFF;
          j = CUtlRBTree<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                (CUtlRBTree<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)this,
                i: j) )
    {
      m_pMemory = this->m_RuleParts[0].m_Tree.m_Elements.m_pMemory;
      elem = m_pMemory[j].m_Data.elem;
      if ( elem != nullptr )
      {
        ResponseRules::Rule::~Rule(this: m_pMemory[j].m_Data.elem);
        free(pMem: elem);
      }
    }
    CUtlRBTree<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll((CUtlRBTree<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)this);
    this = (ResponseRules::ResponseRulePartition *)((char *)this + 56);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103717B0
// Name: public: char const __near * ResponseRules::ResponseRulePartition::GetElementName(unsigned int const __near &)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ResponseRules::ResponseRulePartition::GetElementName(
        ResponseRules::ResponseRulePartition *this,
        const unsigned int *i)
{
  CUtlRBTree<CUtlMap<unsigned int,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v2; // esi
  unsigned __int16 v3; // ax
  CUtlMap<unsigned int,char const *,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  v2 = (CUtlRBTree<CUtlMap<unsigned int,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_RuleParts[HIWORD(*i)];
  search.key = v2->m_Elements.m_pMemory[*i & 0xFFF].m_Data.key;
  v3 = CUtlRBTree<CUtlMap<unsigned int,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,char const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: v2 + 1,
         &search);
  if ( v3 == 0xFFFF )
    return locale;
  else
    return v2[1].m_Elements.m_pMemory[v3].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x10371820
// Name: public: void ResponseRules::ResponseRulePartition::GetDictsForCriteria(class CUtlVectorFixed<class ResponseRules::CResponseDict<struct ResponseRules::Rule __near *,unsigned short> __near *,2> __near *,class ResponseRules::CriteriaSet const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::ResponseRulePartition::GetDictsForCriteria(
        ResponseRules::ResponseRulePartition *this,
        ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> **pResult,
        const ResponseRules::CriteriaSet *criteria)
{
  int CriterionIndex; // eax
  int v7; // eax
  int v8; // eax
  char *Value; // eax
  int BucketForSpeakerAndConcept; // eax
  int v11; // edi
  ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> **v12; // edi
  int v13; // eax
  int v14; // edi
  ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> *v15; // ebx
  ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> **v16; // esi
  char *pszConcept; // [esp+18h] [ebp+8h]
  char *pszSpeaker; // [esp+1Ch] [ebp+Ch]

  pResult[2] = nullptr;
  pResult[3] = (ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> *)pResult;
  CriterionIndex = ResponseRules::CriteriaSet::FindCriterionIndex(this: criteria, name: "Who");
  if ( CriterionIndex == -1 )
    pszSpeaker = nullptr;
  else
    pszSpeaker = ResponseRules::CriteriaSet::GetValue(this: criteria, index: CriterionIndex);
  v7 = ResponseRules::CriteriaSet::FindCriterionIndex(this: criteria, name: "Concept");
  if ( v7 == -1 )
    pszConcept = nullptr;
  else
    pszConcept = ResponseRules::CriteriaSet::GetValue(this: criteria, index: v7);
  v8 = ResponseRules::CriteriaSet::FindCriterionIndex(this: criteria, name: "Subject");
  if ( v8 == -1 )
    Value = nullptr;
  else
    Value = ResponseRules::CriteriaSet::GetValue(this: criteria, index: v8);
  BucketForSpeakerAndConcept = ResponseRules::ResponseRulePartition::GetBucketForSpeakerAndConcept(
                                 this,
                                 pszSpeaker,
                                 pszConcept,
                                 pszSubject: Value);
  v11 = (int)pResult[2];
  pResult[2] = (ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> *)(v11 + 1);
  pResult[3] = (ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> *)pResult;
  v12 = &pResult[v11];
  if ( v12 != nullptr )
    *v12 = &this->m_RuleParts[BucketForSpeakerAndConcept];
  v13 = ResponseRules::ResponseRulePartition::GetBucketForSpeakerAndConcept(
          this,
          pszSpeaker,
          pszConcept,
          pszSubject: nullptr);
  v14 = (int)pResult[2];
  pResult[2] = (ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> *)(v14 + 1);
  v15 = &this->m_RuleParts[v13];
  pResult[3] = (ResponseRules::CResponseDict<ResponseRules::Rule *,unsigned short> *)pResult;
  v16 = &pResult[v14];
  if ( v16 != nullptr )
    *v16 = v15;
}

//------------------------------------------------------------------------------
// Address: 0x10371950
// Name: public: ResponseRules::ResponseRulePartition::~ResponseRulePartition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ResponseRules::ResponseRulePartition::~ResponseRulePartition(
        ResponseRules::ResponseRulePartition *this)
{
  ResponseRules::ResponseRulePartition *v2; // ebx
  char *v3; // esi
  int v4; // [esp+Ch] [ebp-4h]

  ResponseRules::ResponseRulePartition::RemoveAll(this);
  v2 = this + 1;
  v4 = 255;
  v3 = (char *)this + 14368;
  do
  {
    v3 -= 56;
    v2 = (ResponseRules::ResponseRulePartition *)((char *)v2 - 56);
    CUtlRBTree<CUtlMap<unsigned int,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,char const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<CUtlMap<unsigned int,char const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,char const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,char const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v3 - 4));
    *((_WORD *)v3 + 8) = -1;
    if ( *((int *)v3 + 2) >= 0 )
    {
      if ( *(_DWORD *)v3 != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
        *(_DWORD *)v3 = 0;
      }
      *((_DWORD *)v3 + 1) = 0;
    }
    *((_WORD *)v3 + 9) = -1;
    if ( *((int *)v3 + 2) >= 0 )
    {
      if ( *(_DWORD *)v3 != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
        *(_DWORD *)v3 = 0;
      }
      *((_DWORD *)v3 + 1) = 0;
    }
    CUtlRBTree<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,ResponseRules::Rule *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)v2);
    *((_WORD *)v3 - 6) = -1;
    if ( *((int *)v3 - 5) >= 0 )
    {
      if ( *((_DWORD *)v3 - 7) != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 - 7));
        *((_DWORD *)v3 - 7) = 0;
      }
      *((_DWORD *)v3 - 6) = 0;
    }
    *((_WORD *)v3 - 5) = -1;
    if ( *((int *)v3 - 5) >= 0 )
    {
      if ( *((_DWORD *)v3 - 7) != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 - 7));
        *((_DWORD *)v3 - 7) = 0;
      }
      *((_DWORD *)v3 - 6) = 0;
    }
    --v4;
  }
  while ( v4 >= 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10371A40
// Name: public: ResponseRules::ResponseRulePartition::ResponseRulePartition(void)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::ResponseRulePartition *__thiscall ResponseRules::ResponseRulePartition::ResponseRulePartition(
        ResponseRules::ResponseRulePartition *this)
{
  ResponseRules::ResponseRulePartition *result; // eax
  int v2; // edi
  int *p_m_nGrowSize; // edx

  result = this;
  v2 = 255;
  p_m_nGrowSize = &this->m_RuleParts[0].m_ReverseMap.m_Tree.m_Elements.m_nGrowSize;
  do
  {
    *(p_m_nGrowSize - 10) = (int)CDefOps<CChoreoActor *>::LessFunc;
    *(p_m_nGrowSize - 9) = 0;
    *(p_m_nGrowSize - 8) = 0;
    *(p_m_nGrowSize - 7) = 0;
    *((_WORD *)p_m_nGrowSize - 12) = -1;
    *((_WORD *)p_m_nGrowSize - 11) = 0;
    *((_WORD *)p_m_nGrowSize - 10) = -1;
    *((_WORD *)p_m_nGrowSize - 9) = -1;
    *(p_m_nGrowSize - 4) = *(p_m_nGrowSize - 9);
    *(p_m_nGrowSize - 3) = (int)CDefOps<CChoreoActor *>::LessFunc;
    *(p_m_nGrowSize - 2) = 0;
    *(p_m_nGrowSize - 1) = 0;
    *p_m_nGrowSize = 0;
    *((_WORD *)p_m_nGrowSize + 2) = -1;
    *((_WORD *)p_m_nGrowSize + 3) = 0;
    *((_WORD *)p_m_nGrowSize + 4) = -1;
    *((_WORD *)p_m_nGrowSize + 5) = -1;
    p_m_nGrowSize[3] = *(p_m_nGrowSize - 2);
    p_m_nGrowSize += 14;
    --v2;
  }
  while ( v2 >= 0 );
  return result;
}
