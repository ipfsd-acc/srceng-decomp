// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapanimator.cpp
// Functions: 17
// ============================================================

#include "hammer\mapanimator.h"

//------------------------------------------------------------------------------
// Address: 0x1010C9C0
// Name: public: virtual char const __near * CMapAnimator::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapAnimator::GetType(CMapAnimator *this)
{
  return CMapAnimator::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1010C9D0
// Name: public: virtual int CMapAnimator::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapAnimator::IsMapClass(CMapAnimator *this, const char *Type)
{
  return Type == CMapAnimator::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1010C9F0
// Name: public: CMapAnimator::CMapAnimator(void)
// Source: json
//------------------------------------------------------------------------------
CMapAnimator *__thiscall CMapAnimator::CMapAnimator(CMapAnimator *this)
{
  CMapKeyFrame::CMapKeyFrame(this);
  this->__vftable = (CMapAnimator_vtbl *)&CMapAnimator::`vftable';
  MatrixSetIdentity(dst: &this->m_CoordFrame);
  this->m_bCurrentlyAnimating = false;
  this->m_pCurrentKeyFrame = this;
  this->m_iTimeModifier = 0;
  this->m_iRotationInterpolator = 0;
  this->m_iPositionInterpolator = 0;
  this->m_nKeysChanged = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010CA70
// Name: public: virtual class CMapClass __near * CMapAnimator::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapAnimator *__thiscall CMapAnimator::Copy(CMapAnimator *this, BOOL bUpdateDependencies)
{
  CMapAnimator *v3; // eax
  CMapAnimator *v4; // esi

  v3 = (CMapAnimator *)operator new(nSize: 0x1E4u);
  v4 = nullptr;
  if ( v3 != nullptr )
    v4 = CMapAnimator::CMapAnimator(this: v3);
  v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1010CAE0
// Name: public: virtual class CMapClass __near * CMapAnimator::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapAnimator *__thiscall CMapAnimator::CopyFrom(CMapAnimator *this, CMapClass *pObj, bool bUpdateDependencies)
{
  int *v4; // eax

  CMapKeyFrame::CopyFrom(this, pObj, bUpdateDependencies);
  v4 = (int *)__RTDynamicCast(
                inptr: pObj,
                VfDelta: 0,
                SrcType: &CMapClass `RTTI Type Descriptor',
                TargetType: &CMapAnimator `RTTI Type Descriptor',
                isReference: 0);
  qmemcpy(&this->m_CoordFrame, v4 + 100, sizeof(this->m_CoordFrame));
  this->m_bCurrentlyAnimating = false;
  this->m_pCurrentKeyFrame = nullptr;
  this->m_iTimeModifier = v4[118];
  this->m_iPositionInterpolator = v4[119];
  this->m_iRotationInterpolator = v4[120];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1010CB60
// Name: public: virtual bool CMapAnimator::GetTransformMatrix(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapAnimator::GetTransformMatrix(CMapAnimator *this, VMatrix *matrix)
{
  if ( !this->m_bCurrentlyAnimating )
    return 0;
  VMatrix::operator=(this: matrix, mOther: &this->m_CoordFrame);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1010CB90
// Name: public: virtual void CMapAnimator::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAnimator::OnParentKeyChanged(CMapAnimator *this, const char *key, const char *value)
{
  if ( _V_stricmp(s1: key, s2: "TimeModifier") != 0 )
  {
    if ( _V_stricmp(s1: key, s2: "PositionInterpolator") != 0 )
    {
      if ( _V_stricmp(s1: key, s2: "RotationInterpolator") == 0 )
        this->m_iRotationInterpolator = atoi(nptr: value);
    }
    else
    {
      this->m_iPositionInterpolator = atoi(nptr: value);
      CMapClass::UpdateAllDependencies(pObject: this);
    }
  }
  else
  {
    this->m_iTimeModifier = atoi(nptr: value);
  }
  ++this->m_nKeysChanged;
  CMapKeyFrame::OnParentKeyChanged(this, key, value);
}

//------------------------------------------------------------------------------
// Address: 0x1010CC20
// Name: public: float CMapAnimator::GetKeyFramesAtTime(float,class CMapKeyFrame __near * __near &,class CMapKeyFrame __near * __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMapAnimator::GetKeyFramesAtTime(
        CMapAnimator *this,
        float time,
        CMapAnimator **pKeyFrame,
        CMapKeyFrame **pPrevKeyFrame)
{
  float v4; // xmm1_4
  bool v6; // zf
  float m_flMoveTime; // xmm0_4
  CMapKeyFrame *KeyFrame; // eax
  float outTime; // [esp+Ch] [ebp+Ch]

  v4 = time;
  *pKeyFrame = this;
  *pPrevKeyFrame = this;
  v6 = *pKeyFrame == nullptr;
  outTime = time;
  if ( !v6 )
  {
    while ( 1 )
    {
      m_flMoveTime = (*pKeyFrame)->m_flMoveTime;
      if ( m_flMoveTime > v4 )
        break;
      if ( m_flMoveTime < 0.0099999998 )
        return 0.0;
      *pPrevKeyFrame = *pKeyFrame;
      outTime = v4 - m_flMoveTime;
      KeyFrame = CMapKeyFrame::NextKeyFrame(this: *pKeyFrame);
      *pKeyFrame = (CMapAnimator *)KeyFrame;
      if ( KeyFrame == nullptr )
        return outTime;
      v4 = v4 - m_flMoveTime;
    }
  }
  return outTime;
}

//------------------------------------------------------------------------------
// Address: 0x1010CCA0
// Name: public: virtual void CMapAnimator::OnClone(class CMapClass __near *,class CMapWorld __near *,class CUtlReferenceVector<class CMapClass> const __near &,class CUtlReferenceVector<class CMapClass> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAnimator::OnClone(
        CMapAnimator *this,
        CMapClass *pClone,
        CMapWorld *pWorld,
        const CUtlReferenceVector<CMapClass> *OriginalList,
        CUtlReferenceVector<CMapClass> *NewList)
{
  CMapClass::OnClone(this, pNewObj: pClone, pWorld, OriginalList, NewList);
}

//------------------------------------------------------------------------------
// Address: 0x1010CCB0
// Name: public: static void CMapAnimator::GetAnimationAtTime(class CMapKeyFrame __near *,class CMapKeyFrame __near *,float,class Vector __near &,class Quaternion __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall CMapAnimator::GetAnimationAtTime(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        CMapKeyFrame *currentKey,
        CMapKeyFrame *pPrevKey,
        float partialTime,
        Vector *newOrigin,
        Quaternion *newAngles,
        int posInterpolator,
        int rotInterpolator)
{
  float m_flMoveTime; // xmm1_4
  float v11; // xmm0_4
  IPositionInterpolator *v12; // esi
  void (__thiscall *SetKeyPosition)(IPositionInterpolator *, int, const Vector *); // edx
  void (__thiscall *v14)(IPositionInterpolator *, int, const Vector *); // edx
  CMapKeyFrame *KeyFrame; // eax
  CMapKeyFrame *v16; // eax
  void (__thiscall *v17)(IPositionInterpolator *, int, const Vector *); // edx
  CMapKeyFrame *v18; // eax
  CMapKeyFrame *v19; // eax
  CMapKeyFrame *v20; // eax
  CMapKeyFrame *v21; // eax
  void (__thiscall *v22)(IPositionInterpolator *, int, const Vector *); // edx
  Quaternion quatAngles; // [esp+0h] [ebp-28h] BYREF
  Vector time; // [esp+10h] [ebp-18h] BYREF
  Vector v26; // [esp+1Ch] [ebp-Ch] BYREF

  m_flMoveTime = currentKey->m_flMoveTime;
  if ( m_flMoveTime >= 0.01 )
    v11 = partialTime / m_flMoveTime;
  else
    v11 = 1.0;
  v12 = CMapKeyFrame::SetupPositionInterpolator(this: currentKey, iInterpolator: posInterpolator);
  ((void (__thiscall *)(CMapKeyFrame *, Vector *, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))pPrevKey->GetOrigin)(
    a1: pPrevKey,
    a2: &v26,
    a3: a2,
    a4: a3,
    a5: a1,
    a6: LODWORD(quatAngles.x),
    a7: LODWORD(quatAngles.y),
    a8: LODWORD(quatAngles.z),
    a9: LODWORD(quatAngles.w),
    a10: LODWORD(time.x),
    a11: LODWORD(time.y),
    a12: LODWORD(time.z));
  pPrevKey->GetQuatAngles(this: pPrevKey, a2: &quatAngles);
  SetKeyPosition = v12->SetKeyPosition;
  LODWORD(v26.y) = &v26;
  ((void (__thiscall *)(IPositionInterpolator *, int))SetKeyPosition)(a1: v12, a2: -1);
  Motion_SetKeyAngles(keyNum: -1, &quatAngles);
  currentKey->GetOrigin(this: currentKey, a2: &v26);
  currentKey->GetQuatAngles(this: currentKey, a2: &quatAngles);
  v14 = v12->SetKeyPosition;
  LODWORD(v26.y) = &v26;
  ((void (__thiscall *)(IPositionInterpolator *, _DWORD))v14)(a1: v12, a2: 0);
  Motion_SetKeyAngles(keyNum: 0, &quatAngles);
  KeyFrame = CMapKeyFrame::NextKeyFrame(this: currentKey);
  KeyFrame->GetOrigin(this: KeyFrame, a2: &v26);
  v16 = CMapKeyFrame::NextKeyFrame(this: currentKey);
  v16->GetQuatAngles(this: v16, a2: &quatAngles);
  v17 = v12->SetKeyPosition;
  LODWORD(v26.y) = &v26;
  ((void (__thiscall *)(IPositionInterpolator *, int))v17)(a1: v12, a2: 1);
  Motion_SetKeyAngles(keyNum: 1, &quatAngles);
  v18 = CMapKeyFrame::NextKeyFrame(this: currentKey);
  v19 = CMapKeyFrame::NextKeyFrame(this: v18);
  v19->GetOrigin(this: v19, a2: &v26);
  v20 = CMapKeyFrame::NextKeyFrame(this: currentKey);
  v21 = CMapKeyFrame::NextKeyFrame(this: v20);
  v21->GetQuatAngles(this: v21, a2: &quatAngles);
  v22 = v12->SetKeyPosition;
  LODWORD(v26.y) = &v26;
  ((void (__thiscall *)(IPositionInterpolator *, int))v22)(a1: v12, a2: 2);
  Motion_SetKeyAngles(keyNum: 2, &quatAngles);
  v12->InterpolatePosition(this: v12, a2: COERCE_FLOAT(LODWORD(v11)), a3: &time);
  *newOrigin = time;
  Motion_InterpolateRotation(time: v11, interpFuncNum: rotInterpolator, outQuatRotation: newAngles);
}

//------------------------------------------------------------------------------
// Address: 0x1010CE70
// Name: public: static class CMapClass __near * CMapAnimator::CreateMapAnimator(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapAnimator *__cdecl CMapAnimator::CreateMapAnimator()
{
  CMapAnimator *v0; // eax

  v0 = (CMapAnimator *)operator new(nSize: 0x1E4u);
  if ( v0 != nullptr )
    return CMapAnimator::CMapAnimator(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1010CF30
// Name: public: void CMapAnimator::GetAnimationAtTime(float,class Vector __near &,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapAnimator::GetAnimationAtTime(
        CMapAnimator *this@<ecx>,
        int a2@<ebx>,
        __int64 animTime,
        Quaternion *newAngles)
{
  double RemainingTime; // st7
  float v6; // [esp-Ch] [ebp-18h]
  CMapKeyFrame *time; // [esp+8h] [ebp-4h] BYREF

  RemainingTime = CMapKeyFrame::GetRemainingTime(this, pVisited: nullptr);
  v6 = RemainingTime * (*(float *)&animTime / RemainingTime);
  *(float *)&animTime = CMapAnimator::GetKeyFramesAtTime(
                          this,
                          time: v6,
                          pKeyFrame: (CMapAnimator **)&this->m_pCurrentKeyFrame,
                          pPrevKeyFrame: &time);
  CMapAnimator::GetAnimationAtTime(
    a1: a2,
    a2: (int)&this->m_pCurrentKeyFrame,
    a3: (int)this,
    currentKey: this->m_pCurrentKeyFrame,
    pPrevKey: time,
    partialTime: *(float *)&animTime,
    newOrigin: (Vector *)HIDWORD(animTime),
    newAngles,
    posInterpolator: this->m_iPositionInterpolator,
    rotInterpolator: this->m_iRotationInterpolator);
}

//------------------------------------------------------------------------------
// Address: 0x1010CFA0
// Name: public: virtual void CMapAnimator::UpdateAnimation(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapAnimator::UpdateAnimation(CMapAnimator *this@<ecx>, int a2@<ebx>, unsigned int animTime)
{
  const VMatrix *v4; // eax
  const VMatrix *v5; // eax
  VMatrix result; // [esp+14h] [ebp-A8h] BYREF
  VMatrix vm; // [esp+54h] [ebp-68h] BYREF
  Quaternion v8; // [esp+94h] [ebp-28h] BYREF
  Quaternion newAngles; // [esp+A4h] [ebp-18h] BYREF
  Vector newOrigin; // [esp+B4h] [ebp-8h]

  if ( CMapDoc::m_pMapDoc->m_bIsAnimating && this->m_pParent->IsSelected(this: this->m_pParent) )
  {
    this->m_bCurrentlyAnimating = true;
    CMapAnimator::GetAnimationAtTime(this, a2, animTime: __SPAIR64__(&newAngles, animTime), newAngles: &v8);
    this->GetOrigin(this, a2: (Vector *)&newAngles.w);
    MatrixSetIdentity(dst: &vm);
    MatrixSetIdentity(dst: &this->m_CoordFrame);
    this->m_CoordFrame.m[0][3] = -newAngles.w;
    this->m_CoordFrame.m[1][3] = -newOrigin.x;
    this->m_CoordFrame.m[2][3] = -newOrigin.y;
    QuaternionMatrix(q: &v8, matrix: (matrix3x4_t *)&vm);
    v4 = VMatrix::operator*(this: &this->m_CoordFrame, &result, &vm);
    VMatrix::operator=(this: &this->m_CoordFrame, mOther: v4);
    MatrixSetIdentity(dst: &vm);
    vm.m[0][3] = newAngles.x;
    vm.m[1][3] = newAngles.y;
    vm.m[2][3] = newAngles.z;
    v5 = VMatrix::operator*(this: &this->m_CoordFrame, &result, &vm);
    VMatrix::operator=(this: &this->m_CoordFrame, mOther: v5);
  }
  else
  {
    this->m_bCurrentlyAnimating = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010D130
// Name: public: void CMapAnimator::RebuildPath(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAnimator::RebuildPath(CMapAnimator *this)
{
  CMapAnimator *v1; // edi
  CMapKeyFrame *v2; // esi
  CUtlReference<CMapClass> *m_pHead; // eax
  CMapClass *v4; // eax
  char *v5; // eax
  char *Value; // eax
  CMapEntity *EntityByName; // eax
  CMapKeyFrame *ChildOf; // edi
  CUtlReference<CMapClass> *v9; // eax
  int v10; // edx
  bool v11; // dl
  bool v12; // zf
  CMapKeyFrame *v13; // esi
  CUtlReference<CMapClass> *v14; // eax
  CUtlReference<CMapClass> *v15; // eax
  bool v16; // dl
  CMapKeyFrame *v17; // [esp-8h] [ebp-58h]
  CUtlReferenceVector<CMapClass> VisitedList; // [esp+8h] [ebp-48h] BYREF
  CUtlReference<CMapClass> v19; // [esp+1Ch] [ebp-34h] BYREF
  CUtlReference<CMapClass> src; // [esp+28h] [ebp-28h] BYREF
  CMapWorld *pWorld; // [esp+34h] [ebp-1Ch]
  CMapKeyFrame *pCurKey; // [esp+38h] [ebp-18h]
  CMapAnimator *v23; // [esp+3Ch] [ebp-14h]
  CMapKeyFrame *pNextKey; // [esp+40h] [ebp-10h]
  int v25; // [esp+4Ch] [ebp-4h]

  v1 = this;
  v23 = this;
  pWorld = CMapClass::GetWorldObject(pStart: this);
  if ( pWorld != nullptr )
  {
    memset(&VisitedList, 0, 12);
    CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &VisitedList.m_Memory, nGrowSize: 0, nInitSize: 0);
    VisitedList.m_Size = 0;
    VisitedList.m_pElements = nullptr;
    v25 = 3;
    v2 = v1;
    if ( v1 != nullptr )
    {
      while ( 1 )
      {
        src.m_pPrev = nullptr;
        src.m_pNext = nullptr;
        src.m_pObject = v2;
        if ( v2 != nullptr )
        {
          m_pHead = v2->m_References.m_pHead;
          src.m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = &src;
          src.m_pPrev = nullptr;
          v2->m_References.m_pHead = &src;
        }
        LOBYTE(v25) = 4;
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
          this: &VisitedList,
          elem: VisitedList.m_Size,
          &src);
        LOBYTE(v25) = 3;
        if ( src.m_pObject != nullptr )
        {
          if ( src.m_pPrev != nullptr )
          {
            src.m_pPrev->m_pNext = src.m_pNext;
            if ( src.m_pNext != nullptr )
              src.m_pNext->m_pPrev = src.m_pPrev;
          }
          else if ( src.m_pObject->m_References.m_pHead == &src )
          {
            src.m_pObject->m_References.m_pHead = src.m_pNext;
            if ( src.m_pNext != nullptr )
              src.m_pNext->m_pPrev = nullptr;
          }
          memset(&src, 0, sizeof(src));
        }
        CMapKeyFrame::SetAnimator(this: v2, pAnimator: v1);
        v4 = v2->GetParent(this: v2);
        v5 = (char *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CMapClass `RTTI Type Descriptor',
                       TargetType: &CMapEntity `RTTI Type Descriptor',
                       isReference: 0);
        if ( v5 == nullptr )
          break;
        Value = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(
                          this: (WCKeyValuesT<WCKVBase_Dict> *)(v5 + 220),
                          pszKey: "NextKey",
                          piIndex: nullptr);
        EntityByName = CMapWorld::FindEntityByName(
                         this: pWorld,
                         pszName: Value,
                         bVisiblesOnly: false,
                         bSearchInstanceParms: false);
        ChildOf = nullptr;
        pNextKey = nullptr;
        v17 = nullptr;
        if ( EntityByName != nullptr )
        {
          ChildOf = CMapEntity::GetChildOfType<CMapKeyFrame>(this: EntityByName, ignoredArg: nullptr);
          pNextKey = ChildOf;
          v17 = ChildOf;
        }
        CMapKeyFrame::SetNextKeyFrame(this: v2, pNext: v17);
        v2 = ChildOf;
        pCurKey = ChildOf;
        v19.m_pPrev = nullptr;
        v19.m_pNext = nullptr;
        v19.m_pObject = ChildOf;
        if ( ChildOf != nullptr )
        {
          v9 = ChildOf->m_References.m_pHead;
          v19.m_pNext = v9;
          if ( v9 != nullptr )
            v9->m_pPrev = &v19;
          v19.m_pPrev = nullptr;
          ChildOf->m_References.m_pHead = &v19;
        }
        LOBYTE(v25) = 7;
        v10 = 0;
        if ( VisitedList.m_Size <= 0 )
        {
LABEL_26:
          v10 = -1;
        }
        else
        {
          while ( v19.m_pObject != VisitedList.m_Memory.m_pMemory[v10 >> (*((int *)&VisitedList.m_Memory + 2) >> 27)][v10 & ((32 * *((_DWORD *)&VisitedList.m_Memory + 2)) >> 5)].m_pObject )
          {
            if ( ++v10 >= VisitedList.m_Size )
            {
              ChildOf = pNextKey;
              v2 = pCurKey;
              goto LABEL_26;
            }
          }
          ChildOf = pNextKey;
          v2 = pCurKey;
        }
        v11 = v10 != -1;
        LOBYTE(v25) = 3;
        if ( v19.m_pObject != nullptr )
        {
          if ( v19.m_pPrev != nullptr )
          {
            v19.m_pPrev->m_pNext = v19.m_pNext;
            if ( v19.m_pNext != nullptr )
              v19.m_pNext->m_pPrev = v19.m_pPrev;
          }
          else if ( v19.m_pObject->m_References.m_pHead == &v19 )
          {
            v19.m_pObject->m_References.m_pHead = v19.m_pNext;
            if ( v19.m_pNext != nullptr )
              v19.m_pNext->m_pPrev = nullptr;
          }
          memset(&v19, 0, sizeof(v19));
        }
        if ( v11 )
        {
          v1 = v23;
          goto LABEL_41;
        }
        v12 = ChildOf == nullptr;
        v1 = v23;
        if ( v12 )
          goto LABEL_41;
      }
    }
    else
    {
LABEL_41:
      CUtlReferenceVector<CMapClass>::RemoveAll(this: &VisitedList);
      v13 = v1;
      if ( v1 != nullptr )
      {
        do
        {
          v19.m_pPrev = nullptr;
          v19.m_pNext = nullptr;
          v19.m_pObject = v13;
          if ( v13 != nullptr )
          {
            v14 = v13->m_References.m_pHead;
            v19.m_pNext = v14;
            if ( v14 != nullptr )
              v14->m_pPrev = &v19;
            v19.m_pPrev = nullptr;
            v13->m_References.m_pHead = &v19;
          }
          LOBYTE(v25) = 8;
          CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
            this: &VisitedList,
            elem: VisitedList.m_Size,
            src: &v19);
          LOBYTE(v25) = 3;
          if ( v19.m_pObject != nullptr )
          {
            if ( v19.m_pPrev != nullptr )
            {
              v19.m_pPrev->m_pNext = v19.m_pNext;
              if ( v19.m_pNext != nullptr )
                v19.m_pNext->m_pPrev = v19.m_pPrev;
            }
            else if ( v19.m_pObject->m_References.m_pHead == &v19 )
            {
              v19.m_pObject->m_References.m_pHead = v19.m_pNext;
              if ( v19.m_pNext != nullptr )
                v19.m_pNext->m_pPrev = nullptr;
            }
            memset(&v19, 0, sizeof(v19));
          }
          CMapKeyFrame::BuildPathSegment(this: v13, pPrev: v1);
          v1 = (CMapAnimator *)v13;
          v13 = v13->m_pNextKeyFrame;
          src.m_pPrev = nullptr;
          src.m_pNext = nullptr;
          src.m_pObject = v13;
          if ( v13 != nullptr )
          {
            v15 = v13->m_References.m_pHead;
            src.m_pNext = v15;
            if ( v15 != nullptr )
              v15->m_pPrev = &src;
            src.m_pPrev = nullptr;
            v13->m_References.m_pHead = &src;
          }
          LOBYTE(v25) = 9;
          v16 = CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
                  this: &VisitedList,
                  &src) != -1;
          LOBYTE(v25) = 3;
          if ( src.m_pObject != nullptr )
          {
            if ( src.m_pPrev != nullptr )
            {
              src.m_pPrev->m_pNext = src.m_pNext;
              if ( src.m_pNext != nullptr )
                src.m_pNext->m_pPrev = src.m_pPrev;
            }
            else if ( src.m_pObject->m_References.m_pHead == &src )
            {
              src.m_pObject->m_References.m_pHead = src.m_pNext;
              if ( src.m_pNext != nullptr )
                src.m_pNext->m_pPrev = nullptr;
            }
            memset(&src, 0, sizeof(src));
          }
        }
        while ( !v16 && v13 != nullptr );
      }
    }
    v25 = -1;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &VisitedList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DDF60
// Name: public: virtual unsigned int CMapAnimator::GetSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapAnimator::GetSize(CDmeFilmClip *this)
{
  return 484;
}

//------------------------------------------------------------------------------
// Address: 0x105C1F10
// Name: _dynamic_initializer_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__anim_3wayblend__()
{
  ConVar::ConVar(
    this: &anim_3wayblend,
    pName: "anim_3wayblend",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Toggle the 3-way animation blending code.");
  return atexit(func: dynamic_atexit_destructor_for__anim_3wayblend__);
}

//------------------------------------------------------------------------------
// Address: 0x105CBA40
// Name: _dynamic_atexit_destructor_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__anim_3wayblend__()
{
  ConVar::~ConVar(this: &anim_3wayblend);
}
