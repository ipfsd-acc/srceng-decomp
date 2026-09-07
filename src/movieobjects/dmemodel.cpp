// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmemodel.cpp
// Functions: 31
// ============================================================

#include "movieobjects\dmemodel.h"

//------------------------------------------------------------------------------
// Address: 0x004AC050
// Name: protected: void CDmeModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::OnConstruction(CDmeModel *this)
{
  CDmaElementArray<CDmeDag> *p_m_JointList; // edi
  CDmAttribute *v3; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  p_m_JointList = &this->m_JointList;
  this->m_JointList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "jointList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_JointList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_JointList->m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_BaseStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "baseStates",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_BaseStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BaseStates.m_pAttribute, typeSymbol: CDmeTransformList::m_classType);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "Y");
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "upAxis", type: AT_STRING, pMemory: &this->m_UpAxis);
  this->m_UpAxis.m_pAttribute = v3;
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004AC0F0
// Name: public: int CDmeModel::GetJointCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetJointCount(CDmeModel *this)
{
  return this->m_JointList.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004AC100
// Name: private: static void CDmeModel::CleanupModelRenderState(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmeModel::CleanupModelRenderState()
{
  IMatRenderContext *v0; // esi

  v0 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v0 != nullptr )
    v0->BeginRender(this: v0);
  v0->MatrixMode(this: v0, a2: MATERIAL_MODEL);
  v0->LoadIdentity(this: v0);
  v0->EndRender(this: v0);
  v0->Release(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x004AC1D0
// Name: public: class CDmeTransform __near * CDmeTransformList::GetTransform(int)
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeTransformList::GetTransform(CDmeTransformList *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transforms.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeTransform::m_classType) )
    return (CDmeTransform *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004AC220
// Name: public: int CDmeModel::GetJointIndex(class CDmeDag __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetJointIndex(CDmeModel *this, CDmeDag *pJoint)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmeDag *v5; // esi
  int nJointCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nJointCount = this->m_JointList.m_Storage.m_Size;
  if ( nJointCount <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeDag *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeDag::m_classType) )
      v5 = nullptr;
    if ( pJoint == v5 )
      break;
    if ( ++v3 >= nJointCount )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004AC2A0
// Name: public: class CDmeDag __near * CDmeModel::GetJoint(int)
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeModel::GetJoint(CDmeModel *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeDag::m_classType) )
    return (CDmeDag *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004AC2F0
// Name: public: class CDmeTransformList __near * CDmeModel::FindBaseState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformList *__thiscall CDmeModel::FindBaseState(CDmeModel *this, const char *pBaseStateName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char *m_pAsString; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_BaseStates.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeTransformList::m_classType) )
      v5 = nullptr;
    m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    if ( _V_stricmp(s1: m_pAsString, s2: pBaseStateName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
  v9 = v8;
  if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeTransformList::m_classType) )
    return (CDmeTransformList *)v9;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004AC3C0
// Name: public: void CDmeModel::CaptureJointsToBaseState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::CaptureJointsToBaseState(CDmeModel *this, const char *pBaseStateName)
{
  CDmeTransformList *BaseState; // eax
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmeTransformList *v6; // esi
  CDmeTransformList *v7; // ecx
  int m_Size; // esi
  int v9; // ecx
  DmFileId_t m_fileId; // edi
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  const char *m_pAsString; // eax
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CExpressionCalculator *v16; // esi
  int v17; // edi
  CDmElement *v18; // eax
  CDmeDag *v19; // esi
  const char *v20; // eax
  CDmeTransform *Transform; // eax
  const char *v22; // esi
  const char *Name; // eax
  matrix3x4_t mat; // [esp+Ch] [ebp-94h] BYREF
  char pBuf[40]; // [esp+3Ch] [ebp-64h] BYREF
  char szTmpBuf1[40]; // [esp+64h] [ebp-3Ch] BYREF
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *p_m_Transforms; // [esp+8Ch] [ebp-14h]
  DmElementHandle_t src; // [esp+90h] [ebp-10h] BYREF
  int i; // [esp+94h] [ebp-Ch]
  CDmeTransformList *pTransformList; // [esp+98h] [ebp-8h]
  int nJointCount; // [esp+9Ch] [ebp-4h] BYREF

  BaseState = CDmeModel::FindBaseState(this, pBaseStateName);
  pTransformList = BaseState;
  if ( BaseState == nullptr )
  {
    v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmeTransformList::m_classType.u.m_Id,
           a3: pBaseStateName,
           a4: this->m_fileId,
           a5: nullptr);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    v6 = (CDmeTransformList *)v5;
    if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeTransformList::m_classType) )
      v7 = v6;
    else
      v7 = nullptr;
    pTransformList = v7;
    if ( v7 != nullptr )
      nJointCount = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v7);
    else
      nJointCount = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_BaseStates,
      src: (DmElementHandle_t *)&nJointCount);
    BaseState = pTransformList;
  }
  m_Size = this->m_JointList.m_Storage.m_Size;
  v9 = BaseState->m_Transforms.m_Storage.m_Size;
  nJointCount = m_Size;
  if ( m_Size <= v9 )
  {
    if ( m_Size < v9 )
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveMultiple(
        this: &BaseState->m_Transforms,
        elem: m_Size,
        num: v9 - m_Size);
  }
  else
  {
    i = v9;
    p_m_Transforms = &BaseState->m_Transforms;
    while ( 1 )
    {
      m_fileId = BaseState->m_fileId;
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[i]);
      v12 = v11;
      if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmeDag::m_classType) )
        v12 = nullptr;
      m_pAsString = v12->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      v14 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
              a1: g_pDataModel,
              a2: (CUtlSymbolLarge)CDmeTransform::m_classType.u.m_Id,
              a3: m_pAsString,
              a4: m_fileId,
              a5: nullptr);
      v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
      v16 = (CExpressionCalculator *)v15;
      if ( v15 != nullptr && v15->IsA(this: v15, a2: CDmeTransform::m_classType) )
        src = CExpressionCalculator::VariableCount(this: v16);
      else
        src = DMELEMENT_HANDLE_INVALID;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: p_m_Transforms,
        &src);
      if ( ++i >= nJointCount )
        break;
      BaseState = pTransformList;
    }
    m_Size = nJointCount;
  }
  v17 = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v18 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[v17]);
      v19 = (CDmeDag *)v18;
      if ( v18 != nullptr && v18->IsA(this: v18, a2: CDmeDag::m_classType) )
      {
        Transform = CDmeDag::GetTransform(this: v19);
        if ( Transform != nullptr )
        {
          CDmeTransform::GetTransform(this: Transform, transform: &mat);
          CDmeTransformList::SetTransform(this: pTransformList, nIndex: v17, &mat);
        }
        else
        {
          UniqueIdToString(id: &this->m_Id, pBuf, nMaxLen: 38);
          UniqueIdToString(id: &v19->m_Id, pBuf: szTmpBuf1, nMaxLen: 38);
          v22 = v19->m_Name.m_Storage.u.m_pAsString;
          if ( v22 == (const char *)-1 )
            v22 = var;
          Name = CDmElement::GetName(this);
          _Warning(
            a1: "DmeModel::CaptureJointsToBaseState( %s ) - DmeModel %s[%s].jointList[ %d ].transform ( %s[%s].transform ) is NULL\n",
            pBaseStateName,
            Name,
            pBuf,
            v17,
            v22,
            szTmpBuf1);
        }
      }
      else
      {
        UniqueIdToString(id: &this->m_Id, pBuf: szTmpBuf1, nMaxLen: 38);
        v20 = CDmElement::GetName(this);
        _Warning(
          a1: "DmeModel::CaptureJointsToBaseState( %s ): DmeModel %s[%s].jointList[ %d ] is NULL\n",
          pBaseStateName,
          v20,
          szTmpBuf1,
          v17);
      }
      ++v17;
    }
    while ( v17 < nJointCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AC670
// Name: private: void CDmeModel::LoadJointTransform(class CDmeDag __near *,class CDmeTransformList __near *,struct matrix3x4_t const __near &,struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeModel::LoadJointTransform(
        CDmeModel *this@<ecx>,
        int a2@<esi>,
        CDmeDag *pJoint,
        CDmeTransformList *pBindPose,
        const matrix3x4_t *parentToWorld,
        const matrix3x4_t *parentToBindPose,
        bool bSetHardwareState)
{
  int JointIndex; // edi
  CDmeTransform *Transform; // eax
  CDmeTransform *v9; // eax
  int v10; // eax
  int v11; // esi
  int Phase; // edi
  int i; // esi
  CDmeDag *Child; // eax
  matrix3x4_t bindPoseToJoint; // [esp+8h] [ebp-124h] BYREF
  matrix3x4_t jointToParent; // [esp+38h] [ebp-F4h] BYREF
  matrix3x4_t jointToWorld; // [esp+68h] [ebp-C4h] BYREF
  matrix3x4_t bindJointToParent; // [esp+98h] [ebp-94h] BYREF
  matrix3x4_t jointToBindPose; // [esp+C8h] [ebp-64h] BYREF
  matrix3x4_t bindPoseToWorld; // [esp+F8h] [ebp-34h] BYREF
  CDmeModel *v21; // [esp+128h] [ebp-4h]

  v21 = this;
  JointIndex = CDmeModel::GetJointIndex(this, pJoint);
  if ( JointIndex >= 0 )
  {
    Transform = CDmeDag::GetTransform(this: pJoint);
    CDmeTransform::GetTransform(this: Transform, transform: &jointToParent);
    ConcatTransforms(in1: parentToWorld, in2: &jointToParent, out: &jointToWorld);
    if ( pBindPose != nullptr )
    {
      if ( JointIndex >= pBindPose->m_Transforms.m_Storage.m_Size )
      {
        _Warning(
          a1: "Model is in an invalid state! There are different numbers of bones in the bind pose and joint transform list!\n");
        return;
      }
      v9 = CDmeTransformList::GetTransform(this: pBindPose, nIndex: JointIndex);
      CDmeTransform::GetTransform(this: v9, transform: &bindJointToParent);
    }
    else
    {
      MatrixCopy(in: &jointToParent, out: &bindJointToParent);
    }
    ConcatTransforms(in1: parentToBindPose, in2: &bindJointToParent, out: &jointToBindPose);
    MatrixInvert(in: &jointToBindPose, out: &bindPoseToJoint);
    ConcatTransforms(in1: &jointToWorld, in2: &bindPoseToJoint, out: &bindPoseToWorld);
    if ( bSetHardwareState )
    {
      v10 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
      v11 = v10;
      if ( v10 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 424))(a1: v11, a2: JointIndex);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 4))(a1: v11);
    }
    MatrixCopy(in: &bindPoseToWorld, out: &s_PoseToWorld.m_Memory.m_pMemory[JointIndex]);
    Phase = CDmElementFramework::GetPhase(this: pJoint);
    for ( i = 0; i < Phase; ++i )
    {
      Child = CDmeDag::GetChild(this: pJoint, i);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this: v21,
          pJoint: Child,
          pBindPose,
          parentToWorld: &jointToWorld,
          parentToBindPose: &jointToBindPose,
          bSetHardwareState);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AC870
// Name: public: int CDmeModel::AddJoint(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::AddJoint(CDmeModel *this, int pJoint)
{
  CExpressionCalculator *v2; // edi
  int result; // eax

  v2 = (CExpressionCalculator *)pJoint;
  result = CDmeModel::GetJointIndex(this, (CDmeDag *)pJoint);
  if ( result < 0 )
  {
    if ( v2 != nullptr )
      pJoint = CExpressionCalculator::VariableCount(this: v2);
    else
      pJoint = -1;
    return CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
             this: &this->m_JointList,
             src: (DmElementHandle_t *)&pJoint);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004AC8B0
// Name: public: virtual void CDmeModel::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::Draw(CDmeModel *this, CDmeDrawSettings *pDrawSettings)
{
  CDmeModel **v3; // eax

  if ( CDmeModel::s_ModelStack.m_Size >= CDmeModel::s_ModelStack.m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&CDmeModel::s_ModelStack,
      num: 1);
  CDmeModel::s_ModelStack.m_pElements = CDmeModel::s_ModelStack.m_Memory.m_pMemory;
  v3 = &CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size++];
  if ( v3 != nullptr )
    *v3 = this;
  CDmeDag::Draw(this, pDrawSettings);
  --CDmeModel::s_ModelStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004AC910
// Name: private: enum CDmeModel::SetupBoneRetval_t CDmeModel::SetupBoneMatrixState(struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::SetupBoneMatrixState(
        CDmeModel *this,
        const matrix3x4_t *shapeToWorld,
        bool bForceSoftwareSkin)
{
  int m_Size; // edi
  bool v6; // zf
  CDmeTransformList *BaseState; // ebx
  int v8; // edi
  CDmeDag *Child; // eax
  matrix3x4_t parentToBindPose; // [esp+8h] [ebp-34h] BYREF
  int nChildCount; // [esp+38h] [ebp-4h]
  bool bSetHardwareState; // [esp+48h] [ebp+Ch]

  m_Size = this->m_JointList.m_Storage.m_Size;
  if ( m_Size <= 0 )
    return 0;
  if ( m_Size > g_pMaterialSystemHardwareConfig->MaxVertexShaderBlendMatrices(this: g_pMaterialSystemHardwareConfig)
    || (v6 = !bForceSoftwareSkin, bSetHardwareState = true, !v6) )
  {
    bSetHardwareState = false;
  }
  if ( s_PoseToWorld.m_Size < m_Size )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: m_Size - s_PoseToWorld.m_Size);
  BaseState = CDmeModel::FindBaseState(this, pBaseStateName: "bind");
  SetIdentityMatrix(matrix: &parentToBindPose);
  v8 = 0;
  nChildCount = CDmElementFramework::GetPhase(this);
  if ( nChildCount > 0 )
  {
    do
    {
      Child = CDmeDag::GetChild(this, i: v8);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this,
          a2: (int)this,
          pJoint: Child,
          pBindPose: BaseState,
          parentToWorld: shapeToWorld,
          &parentToBindPose,
          bSetHardwareState);
      ++v8;
    }
    while ( v8 < nChildCount );
  }
  return bSetHardwareState + 1;
}

//------------------------------------------------------------------------------
// Address: 0x004AC9D0
// Name: private: static struct matrix3x4_t __near * CDmeModel::SetupModelRenderState(struct matrix3x4_t const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__cdecl CDmeModel::SetupModelRenderState(
        const matrix3x4_t *shapeToWorld,
        bool bHasSkinningData,
        bool bForceSoftwareSkin)
{
  IMatRenderContext *v3; // esi
  int v4; // eax
  matrix3x4_t *m_pMemory; // edi
  matrix3x4_t *v7; // edi

  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( bHasSkinningData && CDmeModel::s_ModelStack.m_Size > 0 )
  {
    v4 = CDmeModel::SetupBoneMatrixState(
           this: CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size - 1],
           shapeToWorld,
           bForceSoftwareSkin);
    if ( v4 == 1 )
    {
      v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
      v3->LoadIdentity(this: v3);
      m_pMemory = s_PoseToWorld.m_Memory.m_pMemory;
      v3->EndRender(this: v3);
      v3->Release(this: v3);
      return m_pMemory;
    }
    if ( v4 != 0 )
    {
      if ( v3 != nullptr )
      {
        v3->EndRender(this: v3);
        v3->Release(this: v3);
        return nullptr;
      }
      return nullptr;
    }
  }
  if ( !bForceSoftwareSkin )
  {
    v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
    v3->LoadMatrix(this: v3, a2: shapeToWorld);
    v3->EndRender(this: v3);
    v3->Release(this: v3);
    return nullptr;
  }
  v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
  v3->LoadIdentity(this: v3);
  if ( s_PoseToWorld.m_Size < 1 )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: 1 - s_PoseToWorld.m_Size);
  MatrixCopy(in: shapeToWorld, out: s_PoseToWorld.m_Memory.m_pMemory);
  v7 = s_PoseToWorld.m_Memory.m_pMemory;
  v3->EndRender(this: v3);
  v3->Release(this: v3);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x004ACB70
// Name: protected: CDmeModel::CDmeModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeModel *__thiscall CDmeModel::CDmeModel(
        CDmeModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeModel_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeModel_vtbl *)&CDmeModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_JointList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_BaseStates);
  this->m_UpAxis.m_Storage.u.m_Id = -1;
  this->m_UpAxis.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004ACC00
// Name: public: virtual bool CDmeModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeModel::IsA(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ACC30
// Name: public: virtual int CDmeModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetInheritanceDepth(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ACC80
// Name: protected: virtual void CDmeModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::PerformConstruction(CDmeModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005ABA80
// Name: _dynamic_initializer_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeModel::s_Allocator,
    blockSize: 200,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABAE0
// Name: _dynamic_initializer_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_ModelStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABF20
// Name: _dynamic_initializer_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AFA40
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AFA50
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmeModel::s_ModelStack);
}

//------------------------------------------------------------------------------
// Address: 0x005AFBE0
// Name: _dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ABAB0
// Name: _dynamic_initializer_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABAC0
// Name: _dynamic_initializer_for__g_CDmeModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeModel_Helper,
           classname: "DmeModel",
           pFactory: &g_CDmeModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ABAF0
// Name: _dynamic_initializer_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_PoseToWorld__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_PoseToWorld__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABF50
// Name: _dynamic_initializer_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABF60
// Name: _dynamic_initializer_for__g_CDmeTransformList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformList_Helper,
           classname: "DmeTransformList",
           pFactory: &g_CDmeTransformList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AFA60
// Name: _dynamic_atexit_destructor_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_PoseToWorld__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_PoseToWorld);
}

//------------------------------------------------------------------------------
// Address: 0x005AFA70
// Name: _dynamic_atexit_destructor_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AFBF0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformList_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00503490
// Name: public: bool CDmeModel::IsZUp(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeModel::IsZUp(CDmeModel *this)
{
  const char *m_pAsString; // eax

  m_pAsString = this->m_UpAxis.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  return StringAfterPrefix(str: m_pAsString, prefix: "Z") != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005034C0
// Name: protected: void CDmeModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::OnConstruction(CDmeModel *this)
{
  CDmaElementArray<CDmeDag> *p_m_JointList; // edi
  CDmAttribute *v3; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  p_m_JointList = &this->m_JointList;
  this->m_JointList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "jointList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_JointList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_JointList->m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_BaseStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "baseStates",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_BaseStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BaseStates.m_pAttribute, typeSymbol: CDmeTransformList::m_classType);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "Y");
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "upAxis", type: AT_STRING, pMemory: &this->m_UpAxis);
  this->m_UpAxis.m_pAttribute = v3;
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00503560
// Name: private: static void CDmeModel::CleanupModelRenderState(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmeModel::CleanupModelRenderState()
{
  IMatRenderContext *v0; // esi

  v0 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v0 != nullptr )
    v0->BeginRender(this: v0);
  v0->MatrixMode(this: v0, a2: MATERIAL_MODEL);
  v0->LoadIdentity(this: v0);
  v0->EndRender(this: v0);
  v0->Release(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x00503630
// Name: public: class CDmeTransform __near * CDmeTransformList::GetTransform(int)
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeTransformList::GetTransform(CDmeTransformList *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transforms.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeTransform::m_classType) )
    return (CDmeTransform *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00503680
// Name: public: int CDmeModel::GetJointIndex(class CDmeDag __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetJointIndex(CDmeModel *this, CDmeDag *pJoint)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmeDag *v5; // esi
  int nJointCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nJointCount = this->m_JointList.m_Storage.m_Size;
  if ( nJointCount <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeDag *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeDag::m_classType) )
      v5 = nullptr;
    if ( pJoint == v5 )
      break;
    if ( ++v3 >= nJointCount )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00503700
// Name: public: class CDmeTransformList __near * CDmeModel::FindBaseState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformList *__thiscall CDmeModel::FindBaseState(CDmeModel *this, const char *pBaseStateName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char *m_pAsString; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_BaseStates.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeTransformList::m_classType) )
      v5 = nullptr;
    m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: m_pAsString, s2: pBaseStateName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
  v9 = v8;
  if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeTransformList::m_classType) )
    return (CDmeTransformList *)v9;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005037D0
// Name: private: void CDmeModel::LoadJointTransform(class CDmeDag __near *,class CDmeTransformList __near *,struct matrix3x4_t const __near &,struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeModel::LoadJointTransform(
        CDmeModel *this@<ecx>,
        int a2@<esi>,
        CDmeDag *pJoint,
        CDmeTransformList *pBindPose,
        const matrix3x4_t *parentToWorld,
        const matrix3x4_t *parentToBindPose,
        bool bSetHardwareState)
{
  int JointIndex; // edi
  CDmeTransform *Transform; // eax
  CDmeTransform *v9; // eax
  int v10; // eax
  int v11; // esi
  int Phase; // edi
  int i; // esi
  CDmeDag *Child; // eax
  matrix3x4_t bindPoseToJoint; // [esp+8h] [ebp-124h] BYREF
  matrix3x4_t jointToParent; // [esp+38h] [ebp-F4h] BYREF
  matrix3x4_t jointToWorld; // [esp+68h] [ebp-C4h] BYREF
  matrix3x4_t bindJointToParent; // [esp+98h] [ebp-94h] BYREF
  matrix3x4_t jointToBindPose; // [esp+C8h] [ebp-64h] BYREF
  matrix3x4_t bindPoseToWorld; // [esp+F8h] [ebp-34h] BYREF
  CDmeModel *v21; // [esp+128h] [ebp-4h]

  v21 = this;
  JointIndex = CDmeModel::GetJointIndex(this, pJoint);
  if ( JointIndex >= 0 )
  {
    Transform = CDmeDag::GetTransform(this: pJoint);
    CDmeTransform::GetTransform(this: Transform, transform: &jointToParent);
    ConcatTransforms(in1: parentToWorld, in2: &jointToParent, out: &jointToWorld);
    if ( pBindPose != nullptr )
    {
      if ( JointIndex >= pBindPose->m_Transforms.m_Storage.m_Size )
      {
        _Warning(
          a1: "Model is in an invalid state! There are different numbers of bones in the bind pose and joint transform list!\n");
        return;
      }
      v9 = CDmeTransformList::GetTransform(this: pBindPose, nIndex: JointIndex);
      CDmeTransform::GetTransform(this: v9, transform: &bindJointToParent);
    }
    else
    {
      MatrixCopy(in: &jointToParent, out: &bindJointToParent);
    }
    ConcatTransforms(in1: parentToBindPose, in2: &bindJointToParent, out: &jointToBindPose);
    MatrixInvert(in: &jointToBindPose, out: &bindPoseToJoint);
    ConcatTransforms(in1: &jointToWorld, in2: &bindPoseToJoint, out: &bindPoseToWorld);
    if ( bSetHardwareState )
    {
      v10 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
      v11 = v10;
      if ( v10 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 424))(a1: v11, a2: JointIndex);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 4))(a1: v11);
    }
    MatrixCopy(in: &bindPoseToWorld, out: &s_PoseToWorld.m_Memory.m_pMemory[JointIndex]);
    Phase = CDmElementFramework::GetPhase(this: pJoint);
    for ( i = 0; i < Phase; ++i )
    {
      Child = CDmeDag::GetChild(this: pJoint, i);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this: v21,
          pJoint: Child,
          pBindPose,
          parentToWorld: &jointToWorld,
          parentToBindPose: &jointToBindPose,
          bSetHardwareState);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00503960
// Name: public: virtual void CDmeModel::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::Draw(CDmeModel *this, CDmeDrawSettings *pDrawSettings)
{
  CDmeModel **v3; // eax

  if ( CDmeModel::s_ModelStack.m_Size >= CDmeModel::s_ModelStack.m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&CDmeModel::s_ModelStack, num: 1);
  CDmeModel::s_ModelStack.m_pElements = CDmeModel::s_ModelStack.m_Memory.m_pMemory;
  v3 = &CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size++];
  if ( v3 != nullptr )
    *v3 = this;
  CDmeDag::Draw(this, pDrawSettings);
  --CDmeModel::s_ModelStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x005039C0
// Name: private: enum CDmeModel::SetupBoneRetval_t CDmeModel::SetupBoneMatrixState(struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::SetupBoneMatrixState(
        CDmeModel *this,
        const matrix3x4_t *shapeToWorld,
        bool bForceSoftwareSkin)
{
  int m_Size; // edi
  bool v6; // zf
  CDmeTransformList *BaseState; // ebx
  int v8; // edi
  CDmeDag *Child; // eax
  matrix3x4_t parentToBindPose; // [esp+8h] [ebp-34h] BYREF
  int nChildCount; // [esp+38h] [ebp-4h]
  bool bSetHardwareState; // [esp+48h] [ebp+Ch]

  m_Size = this->m_JointList.m_Storage.m_Size;
  if ( m_Size <= 0 )
    return 0;
  if ( m_Size > g_pMaterialSystemHardwareConfig->MaxVertexShaderBlendMatrices(this: g_pMaterialSystemHardwareConfig)
    || (v6 = !bForceSoftwareSkin, bSetHardwareState = true, !v6) )
  {
    bSetHardwareState = false;
  }
  if ( s_PoseToWorld.m_Size < m_Size )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: m_Size - s_PoseToWorld.m_Size);
  BaseState = CDmeModel::FindBaseState(this, pBaseStateName: "bind");
  SetIdentityMatrix(matrix: &parentToBindPose);
  v8 = 0;
  nChildCount = CDmElementFramework::GetPhase(this);
  if ( nChildCount > 0 )
  {
    do
    {
      Child = CDmeDag::GetChild(this, i: v8);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this,
          a2: (int)this,
          pJoint: Child,
          pBindPose: BaseState,
          parentToWorld: shapeToWorld,
          &parentToBindPose,
          bSetHardwareState);
      ++v8;
    }
    while ( v8 < nChildCount );
  }
  return bSetHardwareState + 1;
}

//------------------------------------------------------------------------------
// Address: 0x00503A80
// Name: private: static struct matrix3x4_t __near * CDmeModel::SetupModelRenderState(struct matrix3x4_t const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__cdecl CDmeModel::SetupModelRenderState(
        const matrix3x4_t *shapeToWorld,
        bool bHasSkinningData,
        bool bForceSoftwareSkin)
{
  IMatRenderContext *v3; // esi
  int v4; // eax
  matrix3x4_t *m_pMemory; // edi
  matrix3x4_t *v7; // edi

  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( bHasSkinningData && CDmeModel::s_ModelStack.m_Size > 0 )
  {
    v4 = CDmeModel::SetupBoneMatrixState(
           this: CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size - 1],
           shapeToWorld,
           bForceSoftwareSkin);
    if ( v4 == 1 )
    {
      v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
      v3->LoadIdentity(this: v3);
      m_pMemory = s_PoseToWorld.m_Memory.m_pMemory;
      v3->EndRender(this: v3);
      v3->Release(this: v3);
      return m_pMemory;
    }
    if ( v4 != 0 )
    {
      if ( v3 != nullptr )
      {
        v3->EndRender(this: v3);
        v3->Release(this: v3);
        return nullptr;
      }
      return nullptr;
    }
  }
  if ( !bForceSoftwareSkin )
  {
    v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
    v3->LoadMatrix(this: v3, a2: shapeToWorld);
    v3->EndRender(this: v3);
    v3->Release(this: v3);
    return nullptr;
  }
  v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
  v3->LoadIdentity(this: v3);
  if ( s_PoseToWorld.m_Size < 1 )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: 1 - s_PoseToWorld.m_Size);
  MatrixCopy(in: shapeToWorld, out: s_PoseToWorld.m_Memory.m_pMemory);
  v7 = s_PoseToWorld.m_Memory.m_pMemory;
  v3->EndRender(this: v3);
  v3->Release(this: v3);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00503C20
// Name: protected: CDmeModel::CDmeModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeModel *__thiscall CDmeModel::CDmeModel(
        CDmeModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeModel_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeModel_vtbl *)&CDmeModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_JointList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_BaseStates);
  this->m_UpAxis.m_Storage.u.m_Id = -1;
  this->m_UpAxis.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00503CB0
// Name: public: virtual bool CDmeModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeModel::IsA(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00503CE0
// Name: public: virtual int CDmeModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetInheritanceDepth(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00503D30
// Name: protected: virtual void CDmeModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::PerformConstruction(CDmeModel *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  CDmeModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0067CE00
// Name: _dynamic_initializer_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D1B0
// Name: _dynamic_initializer_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeModel::s_Allocator,
    blockSize: 200,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D210
// Name: _dynamic_initializer_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_ModelStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__);
}

//------------------------------------------------------------------------------
// Address: 0x00681D80
// Name: _dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00681F10
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00681F20
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&CDmeModel::s_ModelStack);
}

//------------------------------------------------------------------------------
// Address: 0x0067CE30
// Name: _dynamic_initializer_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CE40
// Name: _dynamic_initializer_for__g_CDmeTransformList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformList_Helper,
           classname: "DmeTransformList",
           pFactory: &g_CDmeTransformList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067D1E0
// Name: _dynamic_initializer_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D1F0
// Name: _dynamic_initializer_for__g_CDmeModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeModel_Helper,
           classname: "DmeModel",
           pFactory: &g_CDmeModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067D220
// Name: _dynamic_initializer_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_PoseToWorld__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_PoseToWorld__);
}

//------------------------------------------------------------------------------
// Address: 0x00681D90
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTransformList_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00681F30
// Name: _dynamic_atexit_destructor_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_PoseToWorld__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_PoseToWorld);
}

//------------------------------------------------------------------------------
// Address: 0x00681F40
// Name: _dynamic_atexit_destructor_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeModel_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104DAF30
// Name: public: bool CDmeModel::IsZUp(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeModel::IsZUp(CDmeModel *this)
{
  const char *m_pAsString; // eax

  m_pAsString = this->m_UpAxis.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &var;
  return StringAfterPrefix(str: m_pAsString, prefix: "Z") != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104DAF60
// Name: protected: void CDmeModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::OnConstruction(CDmeModel *this)
{
  CDmaElementArray<CDmeDag> *p_m_JointList; // edi
  CDmAttribute *v3; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  p_m_JointList = &this->m_JointList;
  this->m_JointList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "jointList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_JointList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_JointList->m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_BaseStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "baseStates",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_BaseStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BaseStates.m_pAttribute, typeSymbol: CDmeTransformList::m_classType);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "Y");
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "upAxis", type: AT_STRING, pMemory: &this->m_UpAxis);
  this->m_UpAxis.m_pAttribute = v3;
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x104DB000
// Name: private: static void CDmeModel::CleanupModelRenderState(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmeModel::CleanupModelRenderState()
{
  IMatRenderContext *v0; // esi

  v0 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v0 != nullptr )
    v0->BeginRender(this: v0);
  v0->MatrixMode(this: v0, a2: MATERIAL_MODEL);
  v0->LoadIdentity(this: v0);
  v0->EndRender(this: v0);
  v0->Release(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x104DB0D0
// Name: public: class CDmeTransform __near * CDmeTransformList::GetTransform(int)
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeTransformList::GetTransform(CDmeTransformList *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transforms.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeTransform::m_classType) )
    return (CDmeTransform *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104DB120
// Name: public: int CDmeModel::GetJointIndex(class CDmeDag __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetJointIndex(CDmeModel *this, CDmeDag *pJoint)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmeDag *v5; // esi
  int nJointCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nJointCount = this->m_JointList.m_Storage.m_Size;
  if ( nJointCount <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeDag *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeDag::m_classType) )
      v5 = nullptr;
    if ( pJoint == v5 )
      break;
    if ( ++v3 >= nJointCount )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x104DB1A0
// Name: public: class CDmeTransformList __near * CDmeModel::FindBaseState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformList *__thiscall CDmeModel::FindBaseState(CDmeModel *this, const char *pBaseStateName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char *m_pAsString; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_BaseStates.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeTransformList::m_classType) )
      v5 = nullptr;
    m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    if ( _V_stricmp(s1: m_pAsString, s2: pBaseStateName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
  v9 = v8;
  if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeTransformList::m_classType) )
    return (CDmeTransformList *)v9;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104DB270
// Name: private: void CDmeModel::LoadJointTransform(class CDmeDag __near *,class CDmeTransformList __near *,struct matrix3x4_t const __near &,struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeModel::LoadJointTransform(
        CDmeModel *this@<ecx>,
        int a2@<esi>,
        CDmeDag *pJoint,
        CDmeTransformList *pBindPose,
        const matrix3x4_t *parentToWorld,
        const matrix3x4_t *parentToBindPose,
        bool bSetHardwareState)
{
  int JointIndex; // edi
  CDmeTransform *Transform; // eax
  CDmeTransform *v9; // eax
  int v10; // eax
  int v11; // esi
  int Phase; // edi
  int i; // esi
  CDmeDag *Child; // eax
  matrix3x4_t bindPoseToJoint; // [esp+8h] [ebp-124h] BYREF
  matrix3x4_t jointToParent; // [esp+38h] [ebp-F4h] BYREF
  matrix3x4_t jointToWorld; // [esp+68h] [ebp-C4h] BYREF
  matrix3x4_t bindJointToParent; // [esp+98h] [ebp-94h] BYREF
  matrix3x4_t jointToBindPose; // [esp+C8h] [ebp-64h] BYREF
  matrix3x4_t bindPoseToWorld; // [esp+F8h] [ebp-34h] BYREF
  CDmeModel *v21; // [esp+128h] [ebp-4h]

  v21 = this;
  JointIndex = CDmeModel::GetJointIndex(this, pJoint);
  if ( JointIndex >= 0 )
  {
    Transform = CDmeDag::GetTransform(this: pJoint);
    CDmeTransform::GetTransform(this: Transform, transform: &jointToParent);
    ConcatTransforms(in1: parentToWorld, in2: &jointToParent, out: &jointToWorld);
    if ( pBindPose != nullptr )
    {
      if ( JointIndex >= pBindPose->m_Transforms.m_Storage.m_Size )
      {
        _Warning(
          a1: "Model is in an invalid state! There are different numbers of bones in the bind pose and joint transform list!\n");
        return;
      }
      v9 = CDmeTransformList::GetTransform(this: pBindPose, nIndex: JointIndex);
      CDmeTransform::GetTransform(this: v9, transform: &bindJointToParent);
    }
    else
    {
      MatrixCopy(in: &jointToParent, out: &bindJointToParent);
    }
    ConcatTransforms(in1: parentToBindPose, in2: &bindJointToParent, out: &jointToBindPose);
    MatrixInvert(in: &jointToBindPose, out: &bindPoseToJoint);
    ConcatTransforms(in1: &jointToWorld, in2: &bindPoseToJoint, out: &bindPoseToWorld);
    if ( bSetHardwareState )
    {
      v10 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
      v11 = v10;
      if ( v10 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 424))(a1: v11, a2: JointIndex);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 4))(a1: v11);
    }
    MatrixCopy(in: &bindPoseToWorld, out: &s_PoseToWorld.m_Memory.m_pMemory[JointIndex]);
    Phase = CDmElementFramework::GetPhase(this: pJoint);
    for ( i = 0; i < Phase; ++i )
    {
      Child = CDmeDag::GetChild(this: pJoint, i);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this: v21,
          pJoint: Child,
          pBindPose,
          parentToWorld: &jointToWorld,
          parentToBindPose: &jointToBindPose,
          bSetHardwareState);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104DB400
// Name: public: virtual void CDmeModel::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::Draw(CDmeModel *this, CDmeDrawSettings *pDrawSettings)
{
  CDmeModel **v3; // eax

  if ( CDmeModel::s_ModelStack.m_Size >= CDmeModel::s_ModelStack.m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&CDmeModel::s_ModelStack, num: 1);
  CDmeModel::s_ModelStack.m_pElements = CDmeModel::s_ModelStack.m_Memory.m_pMemory;
  v3 = &CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size++];
  if ( v3 != nullptr )
    *v3 = this;
  CDmeDag::Draw(this, pDrawSettings);
  --CDmeModel::s_ModelStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x104DB460
// Name: private: enum CDmeModel::SetupBoneRetval_t CDmeModel::SetupBoneMatrixState(struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::SetupBoneMatrixState(
        CDmeModel *this,
        const matrix3x4_t *shapeToWorld,
        bool bForceSoftwareSkin)
{
  int m_Size; // edi
  bool v6; // zf
  CDmeTransformList *BaseState; // ebx
  int v8; // edi
  CDmeDag *Child; // eax
  matrix3x4_t parentToBindPose; // [esp+8h] [ebp-34h] BYREF
  int nChildCount; // [esp+38h] [ebp-4h]
  bool bSetHardwareState; // [esp+48h] [ebp+Ch]

  m_Size = this->m_JointList.m_Storage.m_Size;
  if ( m_Size <= 0 )
    return 0;
  if ( m_Size > g_pMaterialSystemHardwareConfig->MaxVertexShaderBlendMatrices(this: g_pMaterialSystemHardwareConfig)
    || (v6 = !bForceSoftwareSkin, bSetHardwareState = true, !v6) )
  {
    bSetHardwareState = false;
  }
  if ( s_PoseToWorld.m_Size < m_Size )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: m_Size - s_PoseToWorld.m_Size);
  BaseState = CDmeModel::FindBaseState(this, pBaseStateName: "bind");
  SetIdentityMatrix(matrix: &parentToBindPose);
  v8 = 0;
  nChildCount = CDmElementFramework::GetPhase(this);
  if ( nChildCount > 0 )
  {
    do
    {
      Child = CDmeDag::GetChild(this, i: v8);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this,
          a2: (int)this,
          pJoint: Child,
          pBindPose: BaseState,
          parentToWorld: shapeToWorld,
          &parentToBindPose,
          bSetHardwareState);
      ++v8;
    }
    while ( v8 < nChildCount );
  }
  return bSetHardwareState + 1;
}

//------------------------------------------------------------------------------
// Address: 0x104DB520
// Name: private: static struct matrix3x4_t __near * CDmeModel::SetupModelRenderState(struct matrix3x4_t const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__cdecl CDmeModel::SetupModelRenderState(
        const matrix3x4_t *shapeToWorld,
        bool bHasSkinningData,
        bool bForceSoftwareSkin)
{
  IMatRenderContext *v3; // esi
  int v4; // eax
  matrix3x4_t *m_pMemory; // edi
  matrix3x4_t *v7; // edi

  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( bHasSkinningData && CDmeModel::s_ModelStack.m_Size > 0 )
  {
    v4 = CDmeModel::SetupBoneMatrixState(
           this: CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size - 1],
           shapeToWorld,
           bForceSoftwareSkin);
    if ( v4 == 1 )
    {
      v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
      v3->LoadIdentity(this: v3);
      m_pMemory = s_PoseToWorld.m_Memory.m_pMemory;
      v3->EndRender(this: v3);
      v3->Release(this: v3);
      return m_pMemory;
    }
    if ( v4 != 0 )
    {
      if ( v3 != nullptr )
      {
        v3->EndRender(this: v3);
        v3->Release(this: v3);
        return nullptr;
      }
      return nullptr;
    }
  }
  if ( !bForceSoftwareSkin )
  {
    v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
    v3->LoadMatrix(this: v3, a2: shapeToWorld);
    v3->EndRender(this: v3);
    v3->Release(this: v3);
    return nullptr;
  }
  v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
  v3->LoadIdentity(this: v3);
  if ( s_PoseToWorld.m_Size < 1 )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: 1 - s_PoseToWorld.m_Size);
  MatrixCopy(in: shapeToWorld, out: s_PoseToWorld.m_Memory.m_pMemory);
  v7 = s_PoseToWorld.m_Memory.m_pMemory;
  v3->EndRender(this: v3);
  v3->Release(this: v3);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x104DB6D0
// Name: protected: CDmeModel::CDmeModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeModel *__thiscall CDmeModel::CDmeModel(
        CDmeModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeModel_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeModel_vtbl *)&CDmeModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_JointList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_BaseStates);
  this->m_UpAxis.m_Storage.u.m_Id = -1;
  this->m_UpAxis.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104DB760
// Name: public: virtual bool CDmeModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeModel::IsA(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104DB790
// Name: public: virtual int CDmeModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetInheritanceDepth(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104DB7E0
// Name: protected: virtual void CDmeModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::PerformConstruction(CDmeModel *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeDag::OnConstruction(this);
  CDmeModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x10593DF0
// Name: protected: virtual void CDmeModel::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::PerformDestruction(CDmeRig *this)
{
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
}

//------------------------------------------------------------------------------
// Address: 0x105C7480
// Name: _dynamic_initializer_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeModel::s_Allocator,
    blockSize: 0xC8u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C74E0
// Name: _dynamic_initializer_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_ModelStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__);
}

//------------------------------------------------------------------------------
// Address: 0x105C95F0
// Name: _dynamic_initializer_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformList::s_Allocator,
    blockSize: 0x60u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CCF00
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCF10
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CDmeModel::s_ModelStack);
}

//------------------------------------------------------------------------------
// Address: 0x105CDA10
// Name: _dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C74B0
// Name: _dynamic_initializer_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C74C0
// Name: _dynamic_initializer_for__g_CDmeModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeModel_Helper,
           classname: "DmeModel",
           pFactory: &g_CDmeModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C74F0
// Name: _dynamic_initializer_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_PoseToWorld__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_PoseToWorld__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9620
// Name: _dynamic_initializer_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9630
// Name: _dynamic_initializer_for__g_CDmeTransformList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformList_Helper,
           classname: "DmeTransformList",
           pFactory: &g_CDmeTransformList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CCF20
// Name: _dynamic_atexit_destructor_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_PoseToWorld__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_PoseToWorld);
}

//------------------------------------------------------------------------------
// Address: 0x105CCF30
// Name: _dynamic_atexit_destructor_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CDA20
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeTransformList_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004B6970
// Name: public: bool CDmeModel::IsZUp(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeModel::IsZUp(CDmeModel *this)
{
  const char *m_pAsString; // eax

  m_pAsString = this->m_UpAxis.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = WindowName;
  return StringAfterPrefix(str: m_pAsString, prefix: "Z") != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004B69A0
// Name: protected: void CDmeModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::OnConstruction(CDmeModel *this)
{
  CDmaElementArray<CDmeDag> *p_m_JointList; // edi
  CDmAttribute *v3; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  p_m_JointList = &this->m_JointList;
  this->m_JointList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "jointList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_JointList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_JointList->m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_BaseStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "baseStates",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_BaseStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BaseStates.m_pAttribute, typeSymbol: CDmeTransformList::m_classType);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: "Y");
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "upAxis", type: AT_STRING, pMemory: &this->m_UpAxis);
  this->m_UpAxis.m_pAttribute = v3;
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004B6A40
// Name: private: static void CDmeModel::CleanupModelRenderState(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmeModel::CleanupModelRenderState()
{
  IMatRenderContext *v0; // esi

  v0 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v0 != nullptr )
    v0->BeginRender(this: v0);
  v0->MatrixMode(this: v0, a2: MATERIAL_MODEL);
  v0->LoadIdentity(this: v0);
  v0->EndRender(this: v0);
  v0->Release(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x004B6B10
// Name: public: int CDmeModel::GetJointIndex(class CDmeDag __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetJointIndex(CDmeModel *this, CDmeDag *pJoint)
{
  int v3; // edi
  int v4; // eax
  CDmeDag *v5; // esi
  int nJointCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nJointCount = this->m_JointList.m_Storage.m_Size;
  if ( nJointCount <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeDag *)v4;
    if ( v4 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeDag::m_classType.u) == 0 )
    {
      v5 = nullptr;
    }
    if ( pJoint == v5 )
      break;
    if ( ++v3 >= nJointCount )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004B6B90
// Name: public: class CDmeTransformList __near * CDmeModel::FindBaseState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformList *__thiscall CDmeModel::FindBaseState(CDmeModel *this, const char *pBaseStateName)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  const char *v6; // eax
  int v8; // eax
  int v9; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_BaseStates.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeTransformList::m_classType.u) == 0 )
    {
      v5 = 0;
    }
    v6 = *(const char **)(v5 + 20);
    if ( v6 == (const char *)-1 )
      v6 = WindowName;
    if ( _V_stricmp(s1: v6, s2: pBaseStateName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
  v9 = v8;
  if ( v8 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
         a1: v8,
         a2: CDmeTransformList::m_classType.u) != 0 )
  {
    return (CDmeTransformList *)v9;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B6C60
// Name: private: void CDmeModel::LoadJointTransform(class CDmeDag __near *,class CDmeTransformList __near *,struct matrix3x4_t const __near &,struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeModel::LoadJointTransform(
        CDmeModel *this@<ecx>,
        int a2@<esi>,
        CDmeDag *pJoint,
        CDmeTransformList *pBindPose,
        const matrix3x4_t *parentToWorld,
        const matrix3x4_t *parentToBindPose,
        bool bSetHardwareState)
{
  int JointIndex; // edi
  CDmeTransform *Transform; // eax
  CDmeTransform *v9; // eax
  int v10; // eax
  int v11; // esi
  int Phase; // edi
  int i; // esi
  CDmeDag *Child; // eax
  matrix3x4_t bindPoseToJoint; // [esp+8h] [ebp-124h] BYREF
  matrix3x4_t jointToParent; // [esp+38h] [ebp-F4h] BYREF
  matrix3x4_t jointToWorld; // [esp+68h] [ebp-C4h] BYREF
  matrix3x4_t bindJointToParent; // [esp+98h] [ebp-94h] BYREF
  matrix3x4_t jointToBindPose; // [esp+C8h] [ebp-64h] BYREF
  matrix3x4_t bindPoseToWorld; // [esp+F8h] [ebp-34h] BYREF
  CDmeModel *v21; // [esp+128h] [ebp-4h]

  v21 = this;
  JointIndex = CDmeModel::GetJointIndex(this, pJoint);
  if ( JointIndex >= 0 )
  {
    Transform = CDmeDag::GetTransform(this: pJoint);
    CDmeTransform::GetTransform(this: Transform, transform: &jointToParent);
    ConcatTransforms(in1: parentToWorld, in2: &jointToParent, out: &jointToWorld);
    if ( pBindPose != nullptr )
    {
      if ( JointIndex >= pBindPose->m_Transforms.m_Storage.m_Size )
      {
        _Warning(
          a1: "Model is in an invalid state! There are different numbers of bones in the bind pose and joint transform list!\n");
        return;
      }
      v9 = CDmeTransformList::GetTransform(this: pBindPose, nIndex: JointIndex);
      CDmeTransform::GetTransform(this: v9, transform: &bindJointToParent);
    }
    else
    {
      MatrixCopy(in: &jointToParent, out: &bindJointToParent);
    }
    ConcatTransforms(in1: parentToBindPose, in2: &bindJointToParent, out: &jointToBindPose);
    MatrixInvert(in: &jointToBindPose, out: &bindPoseToJoint);
    ConcatTransforms(in1: &jointToWorld, in2: &bindPoseToJoint, out: &bindPoseToWorld);
    if ( bSetHardwareState )
    {
      v10 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
      v11 = v10;
      if ( v10 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 424))(a1: v11, a2: JointIndex);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 4))(a1: v11);
    }
    MatrixCopy(in: &bindPoseToWorld, out: &s_PoseToWorld.m_Memory.m_pMemory[JointIndex]);
    Phase = CDmElementFramework::GetPhase(this: pJoint);
    for ( i = 0; i < Phase; ++i )
    {
      Child = CDmeDag::GetChild(this: pJoint, i);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this: v21,
          pJoint: Child,
          pBindPose,
          parentToWorld: &jointToWorld,
          parentToBindPose: &jointToBindPose,
          bSetHardwareState);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B6DF0
// Name: public: virtual void CDmeModel::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::Draw(CDmeModel *this, CDmeDrawSettings *pDrawSettings)
{
  CDmeModel **v3; // eax

  if ( CDmeModel::s_ModelStack.m_Size >= CDmeModel::s_ModelStack.m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&CDmeModel::s_ModelStack,
      num: 1);
  CDmeModel::s_ModelStack.m_pElements = CDmeModel::s_ModelStack.m_Memory.m_pMemory;
  v3 = &CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size++];
  if ( v3 != nullptr )
    *v3 = this;
  CDmeDag::Draw(this, pDrawSettings);
  --CDmeModel::s_ModelStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004B6E50
// Name: private: enum CDmeModel::SetupBoneRetval_t CDmeModel::SetupBoneMatrixState(struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::SetupBoneMatrixState(
        CDmeModel *this,
        const matrix3x4_t *shapeToWorld,
        bool bForceSoftwareSkin)
{
  int m_Size; // edi
  bool v6; // zf
  CDmeTransformList *BaseState; // ebx
  int v8; // edi
  CDmeDag *Child; // eax
  matrix3x4_t parentToBindPose; // [esp+8h] [ebp-34h] BYREF
  int nChildCount; // [esp+38h] [ebp-4h]
  bool bSetHardwareState; // [esp+48h] [ebp+Ch]

  m_Size = this->m_JointList.m_Storage.m_Size;
  if ( m_Size <= 0 )
    return 0;
  if ( m_Size > g_pMaterialSystemHardwareConfig->MaxVertexShaderBlendMatrices(this: g_pMaterialSystemHardwareConfig)
    || (v6 = !bForceSoftwareSkin, bSetHardwareState = true, !v6) )
  {
    bSetHardwareState = false;
  }
  if ( s_PoseToWorld.m_Size < m_Size )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: m_Size - s_PoseToWorld.m_Size);
  BaseState = CDmeModel::FindBaseState(this, pBaseStateName: "bind");
  SetIdentityMatrix(matrix: &parentToBindPose);
  v8 = 0;
  nChildCount = CDmElementFramework::GetPhase(this);
  if ( nChildCount > 0 )
  {
    do
    {
      Child = CDmeDag::GetChild(this, i: v8);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this,
          a2: (int)this,
          pJoint: Child,
          pBindPose: BaseState,
          parentToWorld: shapeToWorld,
          &parentToBindPose,
          bSetHardwareState);
      ++v8;
    }
    while ( v8 < nChildCount );
  }
  return bSetHardwareState + 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B6F10
// Name: private: static struct matrix3x4_t __near * CDmeModel::SetupModelRenderState(struct matrix3x4_t const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__cdecl CDmeModel::SetupModelRenderState(
        const matrix3x4_t *shapeToWorld,
        bool bHasSkinningData,
        bool bForceSoftwareSkin)
{
  IMatRenderContext *v3; // esi
  int v4; // eax
  matrix3x4_t *m_pMemory; // edi
  matrix3x4_t *v7; // edi

  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( bHasSkinningData && CDmeModel::s_ModelStack.m_Size > 0 )
  {
    v4 = CDmeModel::SetupBoneMatrixState(
           this: CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size - 1],
           shapeToWorld,
           bForceSoftwareSkin);
    if ( v4 == 1 )
    {
      v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
      v3->LoadIdentity(this: v3);
      m_pMemory = s_PoseToWorld.m_Memory.m_pMemory;
      v3->EndRender(this: v3);
      v3->Release(this: v3);
      return m_pMemory;
    }
    if ( v4 != 0 )
    {
      if ( v3 != nullptr )
      {
        v3->EndRender(this: v3);
        v3->Release(this: v3);
        return nullptr;
      }
      return nullptr;
    }
  }
  if ( !bForceSoftwareSkin )
  {
    v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
    v3->LoadMatrix(this: v3, a2: shapeToWorld);
    v3->EndRender(this: v3);
    v3->Release(this: v3);
    return nullptr;
  }
  v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
  v3->LoadIdentity(this: v3);
  if ( s_PoseToWorld.m_Size < 1 )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: 1 - s_PoseToWorld.m_Size);
  MatrixCopy(in: shapeToWorld, out: s_PoseToWorld.m_Memory.m_pMemory);
  v7 = s_PoseToWorld.m_Memory.m_pMemory;
  v3->EndRender(this: v3);
  v3->Release(this: v3);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x004B70B0
// Name: protected: CDmeModel::CDmeModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeModel *__thiscall CDmeModel::CDmeModel(
        CDmeModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeModel_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeModel_vtbl *)&CDmeModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_JointList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_BaseStates);
  this->m_UpAxis.m_Storage.u.m_Id = -1;
  this->m_UpAxis.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B7140
// Name: public: virtual bool CDmeModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeModel::IsA(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B7170
// Name: public: virtual int CDmeModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetInheritanceDepth(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B71C0
// Name: protected: virtual void CDmeModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::PerformConstruction(CDmeModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0059ABD0
// Name: _dynamic_initializer_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeModel::s_Allocator,
    blockSize: 200,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AC30
// Name: _dynamic_initializer_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_ModelStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__);
}

//------------------------------------------------------------------------------
// Address: 0x0059EBF0
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059EC00
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmeModel::s_ModelStack);
}

//------------------------------------------------------------------------------
// Address: 0x0059AC00
// Name: _dynamic_initializer_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AC10
// Name: _dynamic_initializer_for__g_CDmeModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeModel_Helper,
           classname: "DmeModel",
           pFactory: &g_CDmeModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059AC40
// Name: _dynamic_initializer_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_PoseToWorld__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_PoseToWorld__);
}

//------------------------------------------------------------------------------
// Address: 0x0059EC10
// Name: _dynamic_atexit_destructor_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_PoseToWorld__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_PoseToWorld);
}

//------------------------------------------------------------------------------
// Address: 0x0059EC20
// Name: _dynamic_atexit_destructor_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeModel_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004F61C0
// Name: public: bool CDmeModel::IsZUp(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeModel::IsZUp(CDmeModel *this)
{
  const char *m_pAsString; // eax

  m_pAsString = this->m_UpAxis.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = pDeltaStateName;
  return StringAfterPrefix(str: m_pAsString, prefix: "Z") != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004F61F0
// Name: protected: void CDmeModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::OnConstruction(CDmeModel *this)
{
  CDmaElementArray<CDmeDag> *p_m_JointList; // edi
  CDmAttribute *v3; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  p_m_JointList = &this->m_JointList;
  this->m_JointList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "jointList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_JointList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_JointList->m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_BaseStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "baseStates",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_BaseStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BaseStates.m_pAttribute, typeSymbol: CDmeTransformList::m_classType);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: "Y");
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "upAxis", type: AT_STRING, pMemory: &this->m_UpAxis);
  this->m_UpAxis.m_pAttribute = v3;
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004F6290
// Name: public: int CDmeModel::GetJointCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetJointCount(CDmeModel *this)
{
  return this->m_JointList.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004F62A0
// Name: private: static void CDmeModel::CleanupModelRenderState(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmeModel::CleanupModelRenderState()
{
  IMatRenderContext *v0; // esi

  v0 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v0 != nullptr )
    v0->BeginRender(this: v0);
  v0->MatrixMode(this: v0, a2: MATERIAL_MODEL);
  v0->LoadIdentity(this: v0);
  v0->EndRender(this: v0);
  v0->Release(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x004F6370
// Name: public: int CDmeModel::GetJointIndex(class CDmeDag __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetJointIndex(CDmeModel *this, CDmeDag *pJoint)
{
  int v3; // edi
  int v4; // eax
  CDmeDag *v5; // esi
  int nJointCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nJointCount = this->m_JointList.m_Storage.m_Size;
  if ( nJointCount <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeDag *)v4;
    if ( v4 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeDag::m_classType.u) == 0 )
    {
      v5 = nullptr;
    }
    if ( pJoint == v5 )
      break;
    if ( ++v3 >= nJointCount )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004F63F0
// Name: public: class CDmeTransform __near * CDmeModel::GetJointTransform(int)
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeModel::GetJointTransform(CDmeModel *this, int nIndex)
{
  int v2; // eax
  CDmeDag *v3; // esi

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = (CDmeDag *)v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeDag::m_classType.u) != 0 )
  {
    return CDmeDag::GetTransform(this: v3);
  }
  else
  {
    return CDmeDag::GetTransform(this: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F6450
// Name: public: class CDmeTransformList __near * CDmeModel::FindBaseState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformList *__thiscall CDmeModel::FindBaseState(CDmeModel *this, const char *pBaseStateName)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  const char *v6; // eax
  int v8; // eax
  int v9; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_BaseStates.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeTransformList::m_classType.u) == 0 )
    {
      v5 = 0;
    }
    v6 = *(const char **)(v5 + 20);
    if ( v6 == (const char *)-1 )
      v6 = pDeltaStateName;
    if ( _V_stricmp(s1: v6, s2: pBaseStateName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
  v9 = v8;
  if ( v8 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
         a1: v8,
         a2: CDmeTransformList::m_classType.u) != 0 )
  {
    return (CDmeTransformList *)v9;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F6520
// Name: private: void CDmeModel::LoadJointTransform(class CDmeDag __near *,class CDmeTransformList __near *,struct matrix3x4_t const __near &,struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeModel::LoadJointTransform(
        CDmeModel *this@<ecx>,
        int a2@<esi>,
        CDmeDag *pJoint,
        CDmeTransformList *pBindPose,
        const matrix3x4_t *parentToWorld,
        const matrix3x4_t *parentToBindPose,
        bool bSetHardwareState)
{
  int JointIndex; // edi
  CDmeTransform *Transform; // eax
  CDmeTransform *v9; // eax
  int v10; // eax
  int v11; // esi
  int Phase; // edi
  int i; // esi
  CDmeDag *Child; // eax
  matrix3x4_t bindPoseToJoint; // [esp+8h] [ebp-124h] BYREF
  matrix3x4_t jointToParent; // [esp+38h] [ebp-F4h] BYREF
  matrix3x4_t jointToWorld; // [esp+68h] [ebp-C4h] BYREF
  matrix3x4_t bindJointToParent; // [esp+98h] [ebp-94h] BYREF
  matrix3x4_t jointToBindPose; // [esp+C8h] [ebp-64h] BYREF
  matrix3x4_t bindPoseToWorld; // [esp+F8h] [ebp-34h] BYREF
  CDmeModel *v21; // [esp+128h] [ebp-4h]

  v21 = this;
  JointIndex = CDmeModel::GetJointIndex(this, pJoint);
  if ( JointIndex >= 0 )
  {
    Transform = CDmeDag::GetTransform(this: pJoint);
    CDmeTransform::GetTransform(this: Transform, transform: &jointToParent);
    ConcatTransforms(in1: parentToWorld, in2: &jointToParent, out: &jointToWorld);
    if ( pBindPose != nullptr )
    {
      if ( JointIndex >= pBindPose->m_Transforms.m_Storage.m_Size )
      {
        _Warning(
          a1: "Model is in an invalid state! There are different numbers of bones in the bind pose and joint transform list!\n");
        return;
      }
      v9 = CDmeTransformList::GetTransform(this: pBindPose, nIndex: JointIndex);
      CDmeTransform::GetTransform(this: v9, transform: &bindJointToParent);
    }
    else
    {
      MatrixCopy(in: &jointToParent, out: &bindJointToParent);
    }
    ConcatTransforms(in1: parentToBindPose, in2: &bindJointToParent, out: &jointToBindPose);
    MatrixInvert(in: &jointToBindPose, out: &bindPoseToJoint);
    ConcatTransforms(in1: &jointToWorld, in2: &bindPoseToJoint, out: &bindPoseToWorld);
    if ( bSetHardwareState )
    {
      v10 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
      v11 = v10;
      if ( v10 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 424))(a1: v11, a2: JointIndex);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 4))(a1: v11);
    }
    MatrixCopy(in: &bindPoseToWorld, out: &s_PoseToWorld.m_Memory.m_pMemory[JointIndex]);
    Phase = CDmElementFramework::GetPhase(this: pJoint);
    for ( i = 0; i < Phase; ++i )
    {
      Child = CDmeDag::GetChild(this: pJoint, i);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this: v21,
          pJoint: Child,
          pBindPose,
          parentToWorld: &jointToWorld,
          parentToBindPose: &jointToBindPose,
          bSetHardwareState);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F66B0
// Name: public: virtual void CDmeModel::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::Draw(CDmeModel *this, CDmeDrawSettings *pDrawSettings)
{
  CDmeModel **v3; // eax

  if ( CDmeModel::s_ModelStack.m_Size >= CDmeModel::s_ModelStack.m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&CDmeModel::s_ModelStack,
      num: 1);
  CDmeModel::s_ModelStack.m_pElements = CDmeModel::s_ModelStack.m_Memory.m_pMemory;
  v3 = &CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size++];
  if ( v3 != nullptr )
    *v3 = this;
  CDmeDag::Draw(this, pDrawSettings);
  --CDmeModel::s_ModelStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004F6710
// Name: private: enum CDmeModel::SetupBoneRetval_t CDmeModel::SetupBoneMatrixState(struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::SetupBoneMatrixState(
        CDmeModel *this,
        const matrix3x4_t *shapeToWorld,
        bool bForceSoftwareSkin)
{
  int m_Size; // edi
  bool v6; // zf
  CDmeTransformList *BaseState; // ebx
  int v8; // edi
  CDmeDag *Child; // eax
  matrix3x4_t parentToBindPose; // [esp+8h] [ebp-34h] BYREF
  int nChildCount; // [esp+38h] [ebp-4h]
  bool bSetHardwareState; // [esp+48h] [ebp+Ch]

  m_Size = this->m_JointList.m_Storage.m_Size;
  if ( m_Size <= 0 )
    return 0;
  if ( m_Size > g_pMaterialSystemHardwareConfig->MaxVertexShaderBlendMatrices(this: g_pMaterialSystemHardwareConfig)
    || (v6 = !bForceSoftwareSkin, bSetHardwareState = true, !v6) )
  {
    bSetHardwareState = false;
  }
  if ( s_PoseToWorld.m_Size < m_Size )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: m_Size - s_PoseToWorld.m_Size);
  BaseState = CDmeModel::FindBaseState(this, pBaseStateName: "bind");
  SetIdentityMatrix(matrix: &parentToBindPose);
  v8 = 0;
  nChildCount = CDmElementFramework::GetPhase(this);
  if ( nChildCount > 0 )
  {
    do
    {
      Child = CDmeDag::GetChild(this, i: v8);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this,
          a2: (int)this,
          pJoint: Child,
          pBindPose: BaseState,
          parentToWorld: shapeToWorld,
          &parentToBindPose,
          bSetHardwareState);
      ++v8;
    }
    while ( v8 < nChildCount );
  }
  return bSetHardwareState + 1;
}

//------------------------------------------------------------------------------
// Address: 0x004F67D0
// Name: private: static struct matrix3x4_t __near * CDmeModel::SetupModelRenderState(struct matrix3x4_t const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__cdecl CDmeModel::SetupModelRenderState(
        const matrix3x4_t *shapeToWorld,
        bool bHasSkinningData,
        bool bForceSoftwareSkin)
{
  IMatRenderContext *v3; // esi
  int v4; // eax
  matrix3x4_t *m_pMemory; // edi
  matrix3x4_t *v7; // edi

  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( bHasSkinningData && CDmeModel::s_ModelStack.m_Size > 0 )
  {
    v4 = CDmeModel::SetupBoneMatrixState(
           this: CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size - 1],
           shapeToWorld,
           bForceSoftwareSkin);
    if ( v4 == 1 )
    {
      v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
      v3->LoadIdentity(this: v3);
      m_pMemory = s_PoseToWorld.m_Memory.m_pMemory;
      v3->EndRender(this: v3);
      v3->Release(this: v3);
      return m_pMemory;
    }
    if ( v4 != 0 )
    {
      if ( v3 != nullptr )
      {
        v3->EndRender(this: v3);
        v3->Release(this: v3);
        return nullptr;
      }
      return nullptr;
    }
  }
  if ( !bForceSoftwareSkin )
  {
    v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
    v3->LoadMatrix(this: v3, a2: shapeToWorld);
    v3->EndRender(this: v3);
    v3->Release(this: v3);
    return nullptr;
  }
  v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
  v3->LoadIdentity(this: v3);
  if ( s_PoseToWorld.m_Size < 1 )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: 1 - s_PoseToWorld.m_Size);
  MatrixCopy(in: shapeToWorld, out: s_PoseToWorld.m_Memory.m_pMemory);
  v7 = s_PoseToWorld.m_Memory.m_pMemory;
  v3->EndRender(this: v3);
  v3->Release(this: v3);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x004F6970
// Name: protected: CDmeModel::CDmeModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeModel *__thiscall CDmeModel::CDmeModel(
        CDmeModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeModel_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeModel_vtbl *)&CDmeModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_JointList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_BaseStates);
  this->m_UpAxis.m_Storage.u.m_Id = -1;
  this->m_UpAxis.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004F6A00
// Name: public: virtual bool CDmeModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeModel::IsA(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F6A30
// Name: public: virtual int CDmeModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetInheritanceDepth(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F6A80
// Name: protected: virtual void CDmeModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::PerformConstruction(CDmeModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EF470
// Name: _dynamic_initializer_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeModel::s_Allocator,
    blockSize: 200,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF4D0
// Name: _dynamic_initializer_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_ModelStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3D60
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3D70
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmeModel::s_ModelStack);
}

//------------------------------------------------------------------------------
// Address: 0x005EF4A0
// Name: _dynamic_initializer_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF4B0
// Name: _dynamic_initializer_for__g_CDmeModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeModel_Helper,
           classname: "DmeModel",
           pFactory: &g_CDmeModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EF4E0
// Name: _dynamic_initializer_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_PoseToWorld__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_PoseToWorld__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3D80
// Name: _dynamic_atexit_destructor_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_PoseToWorld__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_PoseToWorld);
}

//------------------------------------------------------------------------------
// Address: 0x005F3D90
// Name: _dynamic_atexit_destructor_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeModel_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeModel_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0046F440
// Name: protected: void CDmeModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::OnConstruction(CDmeModel *this)
{
  CDmaElementArray<CDmeDag> *p_m_JointList; // edi
  CDmAttribute *v3; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  p_m_JointList = &this->m_JointList;
  this->m_JointList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "jointList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_JointList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_JointList->m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_BaseStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "baseStates",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_BaseStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BaseStates.m_pAttribute, typeSymbol: CDmeTransformList::m_classType);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "Y");
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "upAxis", type: AT_STRING, pMemory: &this->m_UpAxis);
  this->m_UpAxis.m_pAttribute = v3;
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0046F4E0
// Name: private: static void CDmeModel::CleanupModelRenderState(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmeModel::CleanupModelRenderState()
{
  IMatRenderContext *v0; // esi

  v0 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v0 != nullptr )
    v0->BeginRender(this: v0);
  v0->MatrixMode(this: v0, a2: MATERIAL_MODEL);
  v0->LoadIdentity(this: v0);
  v0->EndRender(this: v0);
  v0->Release(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x0046F5B0
// Name: public: class CDmeTransform __near * CDmeTransformList::GetTransform(int)
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeTransformList::GetTransform(CDmeTransformList *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transforms.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeTransform::m_classType) )
    return (CDmeTransform *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046F600
// Name: public: int CDmeModel::GetJointIndex(class CDmeDag __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetJointIndex(CDmeModel *this, CDmeDag *pJoint)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmeDag *v5; // esi
  int nJointCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nJointCount = this->m_JointList.m_Storage.m_Size;
  if ( nJointCount <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeDag *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeDag::m_classType) )
      v5 = nullptr;
    if ( pJoint == v5 )
      break;
    if ( ++v3 >= nJointCount )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0046F680
// Name: public: class CDmeTransformList __near * CDmeModel::FindBaseState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformList *__thiscall CDmeModel::FindBaseState(CDmeModel *this, const char *pBaseStateName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char *m_pAsString; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_BaseStates.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeTransformList::m_classType) )
      v5 = nullptr;
    m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = str;
    if ( _V_stricmp(s1: m_pAsString, s2: pBaseStateName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
  v9 = v8;
  if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeTransformList::m_classType) )
    return (CDmeTransformList *)v9;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046F750
// Name: private: void CDmeModel::LoadJointTransform(class CDmeDag __near *,class CDmeTransformList __near *,struct matrix3x4_t const __near &,struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeModel::LoadJointTransform(
        CDmeModel *this@<ecx>,
        int a2@<esi>,
        CDmeDag *pJoint,
        CDmeTransformList *pBindPose,
        const matrix3x4_t *parentToWorld,
        const matrix3x4_t *parentToBindPose,
        bool bSetHardwareState)
{
  int JointIndex; // edi
  CDmeTransform *Transform; // eax
  CDmeTransform *v9; // eax
  int v10; // eax
  int v11; // esi
  int Phase; // edi
  int i; // esi
  CDmeDag *Child; // eax
  matrix3x4_t bindPoseToJoint; // [esp+8h] [ebp-124h] BYREF
  matrix3x4_t jointToParent; // [esp+38h] [ebp-F4h] BYREF
  matrix3x4_t jointToWorld; // [esp+68h] [ebp-C4h] BYREF
  matrix3x4_t bindJointToParent; // [esp+98h] [ebp-94h] BYREF
  matrix3x4_t jointToBindPose; // [esp+C8h] [ebp-64h] BYREF
  matrix3x4_t bindPoseToWorld; // [esp+F8h] [ebp-34h] BYREF
  CDmeModel *v21; // [esp+128h] [ebp-4h]

  v21 = this;
  JointIndex = CDmeModel::GetJointIndex(this, pJoint);
  if ( JointIndex >= 0 )
  {
    Transform = CDmeDag::GetTransform(this: pJoint);
    CDmeTransform::GetTransform(this: Transform, transform: &jointToParent);
    ConcatTransforms(in1: parentToWorld, in2: &jointToParent, out: &jointToWorld);
    if ( pBindPose != nullptr )
    {
      if ( JointIndex >= pBindPose->m_Transforms.m_Storage.m_Size )
      {
        _Warning(
          a1: "Model is in an invalid state! There are different numbers of bones in the bind pose and joint transform list!\n");
        return;
      }
      v9 = CDmeTransformList::GetTransform(this: pBindPose, nIndex: JointIndex);
      CDmeTransform::GetTransform(this: v9, transform: &bindJointToParent);
    }
    else
    {
      MatrixCopy(in: &jointToParent, out: &bindJointToParent);
    }
    ConcatTransforms(in1: parentToBindPose, in2: &bindJointToParent, out: &jointToBindPose);
    MatrixInvert(in: &jointToBindPose, out: &bindPoseToJoint);
    ConcatTransforms(in1: &jointToWorld, in2: &bindPoseToJoint, out: &bindPoseToWorld);
    if ( bSetHardwareState )
    {
      v10 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
      v11 = v10;
      if ( v10 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 424))(a1: v11, a2: JointIndex);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 4))(a1: v11);
    }
    MatrixCopy(in: &bindPoseToWorld, out: &s_PoseToWorld.m_Memory.m_pMemory[JointIndex]);
    Phase = CDmElementFramework::GetPhase(this: pJoint);
    for ( i = 0; i < Phase; ++i )
    {
      Child = CDmeDag::GetChild(this: pJoint, i);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this: v21,
          pJoint: Child,
          pBindPose,
          parentToWorld: &jointToWorld,
          parentToBindPose: &jointToBindPose,
          bSetHardwareState);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F8E0
// Name: public: virtual void CDmeModel::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::Draw(CDmeModel *this, CDmeDrawSettings *pDrawSettings)
{
  CDmeModel **v3; // eax

  if ( CDmeModel::s_ModelStack.m_Size >= CDmeModel::s_ModelStack.m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&CDmeModel::s_ModelStack,
      num: 1);
  CDmeModel::s_ModelStack.m_pElements = CDmeModel::s_ModelStack.m_Memory.m_pMemory;
  v3 = &CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size++];
  if ( v3 != nullptr )
    *v3 = this;
  CDmeDag::Draw(this, pDrawSettings);
  --CDmeModel::s_ModelStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0046F940
// Name: private: enum CDmeModel::SetupBoneRetval_t CDmeModel::SetupBoneMatrixState(struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::SetupBoneMatrixState(
        CDmeModel *this,
        const matrix3x4_t *shapeToWorld,
        bool bForceSoftwareSkin)
{
  int m_Size; // edi
  bool v6; // zf
  CDmeTransformList *BaseState; // ebx
  int v8; // edi
  CDmeDag *Child; // eax
  matrix3x4_t parentToBindPose; // [esp+8h] [ebp-34h] BYREF
  int nChildCount; // [esp+38h] [ebp-4h]
  bool bSetHardwareState; // [esp+48h] [ebp+Ch]

  m_Size = this->m_JointList.m_Storage.m_Size;
  if ( m_Size <= 0 )
    return 0;
  if ( m_Size > g_pMaterialSystemHardwareConfig->MaxVertexShaderBlendMatrices(this: g_pMaterialSystemHardwareConfig)
    || (v6 = !bForceSoftwareSkin, bSetHardwareState = true, !v6) )
  {
    bSetHardwareState = false;
  }
  if ( s_PoseToWorld.m_Size < m_Size )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: m_Size - s_PoseToWorld.m_Size);
  BaseState = CDmeModel::FindBaseState(this, pBaseStateName: "bind");
  SetIdentityMatrix(matrix: &parentToBindPose);
  v8 = 0;
  nChildCount = CDmElementFramework::GetPhase(this);
  if ( nChildCount > 0 )
  {
    do
    {
      Child = CDmeDag::GetChild(this, i: v8);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this,
          a2: (int)this,
          pJoint: Child,
          pBindPose: BaseState,
          parentToWorld: shapeToWorld,
          &parentToBindPose,
          bSetHardwareState);
      ++v8;
    }
    while ( v8 < nChildCount );
  }
  return bSetHardwareState + 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046FA00
// Name: private: static struct matrix3x4_t __near * CDmeModel::SetupModelRenderState(struct matrix3x4_t const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__cdecl CDmeModel::SetupModelRenderState(
        const matrix3x4_t *shapeToWorld,
        bool bHasSkinningData,
        bool bForceSoftwareSkin)
{
  IMatRenderContext *v3; // esi
  int v4; // eax
  matrix3x4_t *m_pMemory; // edi
  matrix3x4_t *v7; // edi

  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( bHasSkinningData && CDmeModel::s_ModelStack.m_Size > 0 )
  {
    v4 = CDmeModel::SetupBoneMatrixState(
           this: CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size - 1],
           shapeToWorld,
           bForceSoftwareSkin);
    if ( v4 == 1 )
    {
      v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
      v3->LoadIdentity(this: v3);
      m_pMemory = s_PoseToWorld.m_Memory.m_pMemory;
      v3->EndRender(this: v3);
      v3->Release(this: v3);
      return m_pMemory;
    }
    if ( v4 != 0 )
    {
      if ( v3 != nullptr )
      {
        v3->EndRender(this: v3);
        v3->Release(this: v3);
        return nullptr;
      }
      return nullptr;
    }
  }
  if ( !bForceSoftwareSkin )
  {
    v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
    v3->LoadMatrix(this: v3, a2: shapeToWorld);
    v3->EndRender(this: v3);
    v3->Release(this: v3);
    return nullptr;
  }
  v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
  v3->LoadIdentity(this: v3);
  if ( s_PoseToWorld.m_Size < 1 )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: 1 - s_PoseToWorld.m_Size);
  MatrixCopy(in: shapeToWorld, out: s_PoseToWorld.m_Memory.m_pMemory);
  v7 = s_PoseToWorld.m_Memory.m_pMemory;
  v3->EndRender(this: v3);
  v3->Release(this: v3);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x0046FBA0
// Name: protected: CDmeModel::CDmeModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeModel *__thiscall CDmeModel::CDmeModel(
        CDmeModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeModel_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeModel_vtbl *)&CDmeModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_JointList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_BaseStates);
  this->m_UpAxis.m_Storage.u.m_Id = -1;
  this->m_UpAxis.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046FC30
// Name: public: virtual bool CDmeModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeModel::IsA(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046FC60
// Name: public: virtual int CDmeModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetInheritanceDepth(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046FCC0
// Name: protected: virtual void CDmeModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::PerformConstruction(CDmeModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005699E0
// Name: _dynamic_initializer_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00569D90
// Name: _dynamic_initializer_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeModel::s_Allocator,
    blockSize: 200,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00569DF0
// Name: _dynamic_initializer_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_ModelStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__);
}

//------------------------------------------------------------------------------
// Address: 0x0056DF60
// Name: _dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056E0F0
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056E100
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmeModel::s_ModelStack);
}

//------------------------------------------------------------------------------
// Address: 0x00569A10
// Name: _dynamic_initializer_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00569A20
// Name: _dynamic_initializer_for__g_CDmeTransformList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformList_Helper,
           classname: "DmeTransformList",
           pFactory: &g_CDmeTransformList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00569DC0
// Name: _dynamic_initializer_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00569DD0
// Name: _dynamic_initializer_for__g_CDmeModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeModel_Helper,
           classname: "DmeModel",
           pFactory: &g_CDmeModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00569E00
// Name: _dynamic_initializer_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_PoseToWorld__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_PoseToWorld__);
}

//------------------------------------------------------------------------------
// Address: 0x0056DF70
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformList_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056E110
// Name: _dynamic_atexit_destructor_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_PoseToWorld__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_PoseToWorld);
}

//------------------------------------------------------------------------------
// Address: 0x0056E120
// Name: _dynamic_atexit_destructor_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeModel_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x004730F0
// Name: protected: void CDmeModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::OnConstruction(CDmeModel *this)
{
  CDmaElementArray<CDmeDag> *p_m_JointList; // edi
  CDmAttribute *v3; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  p_m_JointList = &this->m_JointList;
  this->m_JointList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "jointList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_JointList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_JointList->m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_BaseStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "baseStates",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_BaseStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BaseStates.m_pAttribute, typeSymbol: CDmeTransformList::m_classType);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "Y");
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "upAxis", type: AT_STRING, pMemory: &this->m_UpAxis);
  this->m_UpAxis.m_pAttribute = v3;
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00473190
// Name: private: static void CDmeModel::CleanupModelRenderState(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmeModel::CleanupModelRenderState()
{
  IMatRenderContext *v0; // esi

  v0 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v0 != nullptr )
    v0->BeginRender(this: v0);
  v0->MatrixMode(this: v0, a2: MATERIAL_MODEL);
  v0->LoadIdentity(this: v0);
  v0->EndRender(this: v0);
  v0->Release(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x004732C0
// Name: public: class CDmeTransform __near * CDmeTransformList::GetTransform(int)
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeTransformList::GetTransform(CDmeTransformList *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transforms.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeTransform::m_classType) )
    return (CDmeTransform *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00473310
// Name: public: int CDmeModel::GetJointIndex(class CDmeDag __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetJointIndex(CDmeModel *this, CDmeDag *pJoint)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmeDag *v5; // esi
  int nJointCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nJointCount = this->m_JointList.m_Storage.m_Size;
  if ( nJointCount <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeDag *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeDag::m_classType) )
      v5 = nullptr;
    if ( pJoint == v5 )
      break;
    if ( ++v3 >= nJointCount )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00473390
// Name: public: class CDmeTransformList __near * CDmeModel::FindBaseState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformList *__thiscall CDmeModel::FindBaseState(CDmeModel *this, const char *pBaseStateName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char *m_pAsString; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_BaseStates.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeTransformList::m_classType) )
      v5 = nullptr;
    m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pParentName;
    if ( _V_stricmp(s1: m_pAsString, s2: pBaseStateName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
  v9 = v8;
  if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeTransformList::m_classType) )
    return (CDmeTransformList *)v9;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00473460
// Name: private: void CDmeModel::LoadJointTransform(class CDmeDag __near *,class CDmeTransformList __near *,struct matrix3x4_t const __near &,struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeModel::LoadJointTransform(
        CDmeModel *this@<ecx>,
        int a2@<esi>,
        CDmeDag *pJoint,
        CDmeTransformList *pBindPose,
        const matrix3x4_t *parentToWorld,
        const matrix3x4_t *parentToBindPose,
        bool bSetHardwareState)
{
  int JointIndex; // edi
  CDmeTransform *Transform; // eax
  CDmeTransform *v9; // eax
  int v10; // eax
  int v11; // esi
  int Phase; // edi
  int i; // esi
  CDmeDag *Child; // eax
  matrix3x4_t bindPoseToJoint; // [esp+8h] [ebp-124h] BYREF
  matrix3x4_t jointToParent; // [esp+38h] [ebp-F4h] BYREF
  matrix3x4_t jointToWorld; // [esp+68h] [ebp-C4h] BYREF
  matrix3x4_t bindJointToParent; // [esp+98h] [ebp-94h] BYREF
  matrix3x4_t jointToBindPose; // [esp+C8h] [ebp-64h] BYREF
  matrix3x4_t bindPoseToWorld; // [esp+F8h] [ebp-34h] BYREF
  CDmeModel *v21; // [esp+128h] [ebp-4h]

  v21 = this;
  JointIndex = CDmeModel::GetJointIndex(this, pJoint);
  if ( JointIndex >= 0 )
  {
    Transform = CDmeDag::GetTransform(this: pJoint);
    CDmeTransform::GetTransform(this: Transform, transform: &jointToParent);
    ConcatTransforms(in1: parentToWorld, in2: &jointToParent, out: &jointToWorld);
    if ( pBindPose != nullptr )
    {
      if ( JointIndex >= pBindPose->m_Transforms.m_Storage.m_Size )
      {
        _Warning(
          a1: "Model is in an invalid state! There are different numbers of bones in the bind pose and joint transform list!\n");
        return;
      }
      v9 = CDmeTransformList::GetTransform(this: pBindPose, nIndex: JointIndex);
      CDmeTransform::GetTransform(this: v9, transform: &bindJointToParent);
    }
    else
    {
      MatrixCopy(in: &jointToParent, out: &bindJointToParent);
    }
    ConcatTransforms(in1: parentToBindPose, in2: &bindJointToParent, out: &jointToBindPose);
    MatrixInvert(in: &jointToBindPose, out: &bindPoseToJoint);
    ConcatTransforms(in1: &jointToWorld, in2: &bindPoseToJoint, out: &bindPoseToWorld);
    if ( bSetHardwareState )
    {
      v10 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
      v11 = v10;
      if ( v10 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 424))(a1: v11, a2: JointIndex);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 4))(a1: v11);
    }
    MatrixCopy(in: &bindPoseToWorld, out: &s_PoseToWorld.m_Memory.m_pMemory[JointIndex]);
    Phase = CDmElementFramework::GetPhase(this: pJoint);
    for ( i = 0; i < Phase; ++i )
    {
      Child = CDmeDag::GetChild(this: pJoint, i);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this: v21,
          pJoint: Child,
          pBindPose,
          parentToWorld: &jointToWorld,
          parentToBindPose: &jointToBindPose,
          bSetHardwareState);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004735F0
// Name: public: virtual void CDmeModel::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::Draw(CDmeModel *this, CDmeDrawSettings *pDrawSettings)
{
  CDmeModel **v3; // eax

  if ( CDmeModel::s_ModelStack.m_Size >= CDmeModel::s_ModelStack.m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&CDmeModel::s_ModelStack,
      num: 1);
  CDmeModel::s_ModelStack.m_pElements = CDmeModel::s_ModelStack.m_Memory.m_pMemory;
  v3 = &CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size++];
  if ( v3 != nullptr )
    *v3 = this;
  CDmeDag::Draw(this, pDrawSettings);
  --CDmeModel::s_ModelStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00473650
// Name: private: enum CDmeModel::SetupBoneRetval_t CDmeModel::SetupBoneMatrixState(struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::SetupBoneMatrixState(
        CDmeModel *this,
        const matrix3x4_t *shapeToWorld,
        bool bForceSoftwareSkin)
{
  int m_Size; // edi
  bool v6; // zf
  CDmeTransformList *BaseState; // ebx
  int v8; // edi
  CDmeDag *Child; // eax
  matrix3x4_t parentToBindPose; // [esp+8h] [ebp-34h] BYREF
  int nChildCount; // [esp+38h] [ebp-4h]
  bool bSetHardwareState; // [esp+48h] [ebp+Ch]

  m_Size = this->m_JointList.m_Storage.m_Size;
  if ( m_Size <= 0 )
    return 0;
  if ( m_Size > g_pMaterialSystemHardwareConfig->MaxVertexShaderBlendMatrices(this: g_pMaterialSystemHardwareConfig)
    || (v6 = !bForceSoftwareSkin, bSetHardwareState = true, !v6) )
  {
    bSetHardwareState = false;
  }
  if ( s_PoseToWorld.m_Size < m_Size )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: m_Size - s_PoseToWorld.m_Size);
  BaseState = CDmeModel::FindBaseState(this, pBaseStateName: "bind");
  SetIdentityMatrix(matrix: &parentToBindPose);
  v8 = 0;
  nChildCount = CDmElementFramework::GetPhase(this);
  if ( nChildCount > 0 )
  {
    do
    {
      Child = CDmeDag::GetChild(this, i: v8);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this,
          a2: (int)this,
          pJoint: Child,
          pBindPose: BaseState,
          parentToWorld: shapeToWorld,
          &parentToBindPose,
          bSetHardwareState);
      ++v8;
    }
    while ( v8 < nChildCount );
  }
  return bSetHardwareState + 1;
}

//------------------------------------------------------------------------------
// Address: 0x00473710
// Name: private: static struct matrix3x4_t __near * CDmeModel::SetupModelRenderState(struct matrix3x4_t const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__cdecl CDmeModel::SetupModelRenderState(
        const matrix3x4_t *shapeToWorld,
        bool bHasSkinningData,
        bool bForceSoftwareSkin)
{
  IMatRenderContext *v3; // esi
  int v4; // eax
  matrix3x4_t *m_pMemory; // edi
  matrix3x4_t *v7; // edi

  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( bHasSkinningData && CDmeModel::s_ModelStack.m_Size > 0 )
  {
    v4 = CDmeModel::SetupBoneMatrixState(
           this: CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size - 1],
           shapeToWorld,
           bForceSoftwareSkin);
    if ( v4 == 1 )
    {
      v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
      v3->LoadIdentity(this: v3);
      m_pMemory = s_PoseToWorld.m_Memory.m_pMemory;
      v3->EndRender(this: v3);
      v3->Release(this: v3);
      return m_pMemory;
    }
    if ( v4 != 0 )
    {
      if ( v3 != nullptr )
      {
        v3->EndRender(this: v3);
        v3->Release(this: v3);
        return nullptr;
      }
      return nullptr;
    }
  }
  if ( !bForceSoftwareSkin )
  {
    v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
    v3->LoadMatrix(this: v3, a2: shapeToWorld);
    v3->EndRender(this: v3);
    v3->Release(this: v3);
    return nullptr;
  }
  v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
  v3->LoadIdentity(this: v3);
  if ( s_PoseToWorld.m_Size < 1 )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: 1 - s_PoseToWorld.m_Size);
  MatrixCopy(in: shapeToWorld, out: s_PoseToWorld.m_Memory.m_pMemory);
  v7 = s_PoseToWorld.m_Memory.m_pMemory;
  v3->EndRender(this: v3);
  v3->Release(this: v3);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x004738B0
// Name: protected: CDmeModel::CDmeModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeModel *__thiscall CDmeModel::CDmeModel(
        CDmeModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeModel_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeModel_vtbl *)&CDmeModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_JointList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_BaseStates);
  this->m_UpAxis.m_Storage.u.m_Id = -1;
  this->m_UpAxis.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00473940
// Name: public: virtual bool CDmeModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeModel::IsA(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00473970
// Name: public: virtual int CDmeModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetInheritanceDepth(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004739D0
// Name: protected: virtual void CDmeModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::PerformConstruction(CDmeModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00579AE0
// Name: _dynamic_initializer_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00579E90
// Name: _dynamic_initializer_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeModel::s_Allocator,
    blockSize: 200,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00579EF0
// Name: _dynamic_initializer_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_ModelStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E090
// Name: _dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E220
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E230
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmeModel::s_ModelStack);
}

//------------------------------------------------------------------------------
// Address: 0x004731E0
// Name: class CDmeTransform __near * CreateElement<class CDmeTransform>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransform *__cdecl CreateElement<CDmeTransform>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeTransform::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeTransform::m_classType) )
    return (CDmeTransform *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00579B10
// Name: _dynamic_initializer_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579B20
// Name: _dynamic_initializer_for__g_CDmeTransformList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformList_Helper,
           classname: "DmeTransformList",
           pFactory: &g_CDmeTransformList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579EC0
// Name: _dynamic_initializer_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579ED0
// Name: _dynamic_initializer_for__g_CDmeModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeModel_Helper,
           classname: "DmeModel",
           pFactory: &g_CDmeModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579F00
// Name: _dynamic_initializer_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_PoseToWorld__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_PoseToWorld__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E0A0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformList_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E240
// Name: _dynamic_atexit_destructor_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_PoseToWorld__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_PoseToWorld);
}

//------------------------------------------------------------------------------
// Address: 0x0057E250
// Name: _dynamic_atexit_destructor_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeModel_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00531BA0
// Name: public: bool CDmeModel::IsZUp(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeModel::IsZUp(CDmeModel *this)
{
  const char *m_pAsString; // eax

  m_pAsString = this->m_UpAxis.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  return StringAfterPrefix(str: m_pAsString, prefix: "Z") != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00531BD0
// Name: private: void CDmeModel::ReplaceMaterial(class CDmeDag __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::ReplaceMaterial(
        CDmeModel *this,
        CDmeDag *pDag,
        const char *pOldMaterialName,
        const char *pNewMaterialName)
{
  CDmeShape *Shape; // eax
  CDmeMesh *v5; // esi
  int Phase; // ebx
  int i; // esi
  CDmeDag *Child; // eax

  if ( pDag != nullptr )
  {
    Shape = CDmeDag::GetShape(this: pDag);
    v5 = (CDmeMesh *)Shape;
    if ( Shape != nullptr && Shape->IsA(this: Shape, a2: CDmeMesh::m_classType) )
      CDmeMesh::ReplaceMaterial(this: v5, pOldMaterialName, pNewMaterialName);
    Phase = CDmElementFramework::GetPhase(this: pDag);
    for ( i = 0; i < Phase; ++i )
    {
      Child = CDmeDag::GetChild(this: pDag, i);
      CDmeModel::ReplaceMaterial(this, pDag: Child, pOldMaterialName, pNewMaterialName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00531C50
// Name: public: void CDmeModel::ReplaceMaterial(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::ReplaceMaterial(CDmeModel *this, const char *pOldMaterialName, const char *pNewMaterialName)
{
  CDmeModel::ReplaceMaterial(this, pDag: this, pOldMaterialName, pNewMaterialName);
}

//------------------------------------------------------------------------------
// Address: 0x00531C70
// Name: private: void CDmeModel::ReskinMeshes(class CDmeDag __near *,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::ReskinMeshes(CDmeModel *this, CDmeDag *pDag, const int *pJointTransformIndexRemap)
{
  CDmeShape *Shape; // eax
  CDmeMesh *v4; // esi
  int Phase; // edi
  int i; // esi
  CDmeDag *Child; // eax

  if ( pDag != nullptr )
  {
    Shape = CDmeDag::GetShape(this: pDag);
    v4 = (CDmeMesh *)Shape;
    if ( Shape != nullptr && Shape->IsA(this: Shape, a2: CDmeMesh::m_classType) )
      CDmeMesh::Reskin(this: v4, pJointTransformIndexRemap);
    Phase = CDmElementFramework::GetPhase(this: pDag);
    for ( i = 0; i < Phase; ++i )
    {
      Child = CDmeDag::GetChild(this: pDag, i);
      CDmeModel::ReskinMeshes(this, pDag: Child, pJointTransformIndexRemap);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00531CF0
// Name: private: void CDmeModel::RemoveAllChildren(class CDmeDag __near *,class CDmeDag __near *,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::RemoveAllChildren(
        CDmeModel *this,
        CDmeDag *pDag,
        CDmeDag *pSubtreeRoot,
        const matrix3x4_t *jointToSubtreeRoot)
{
  CDmeTransform *Transform; // edi
  int Phase; // ebx
  int i; // edi
  CDmeDag *Child; // eax
  matrix3x4_t dagToParent; // [esp+Ch] [ebp-64h] BYREF
  matrix3x4_t curToSubtreeRoot; // [esp+3Ch] [ebp-34h] BYREF
  CDmeModel *v10; // [esp+6Ch] [ebp-4h]

  v10 = this;
  if ( pDag != nullptr )
  {
    Transform = CDmeDag::GetTransform(this: pDag);
    CDmeTransform::GetTransform(this: Transform, transform: &dagToParent);
    ConcatTransforms(in1: jointToSubtreeRoot, in2: &dagToParent, out: &curToSubtreeRoot);
    if ( !((int (__thiscall *)(_DWORD, _DWORD))pDag->IsA)(a1: pDag, a2: (CUtlSymbolLarge)CDmeJoint::m_classType.u.m_Id) )
    {
      CDmeDag::AddChild(this: pSubtreeRoot, pDag);
      CDmeTransform::SetTransform(this: Transform, transform: &curToSubtreeRoot);
    }
    Phase = CDmElementFramework::GetPhase(this: pDag);
    for ( i = 0; i < Phase; ++i )
    {
      Child = CDmeDag::GetChild(this: pDag, i);
      CDmeModel::RemoveAllChildren(this: v10, pDag: Child, pSubtreeRoot, jointToSubtreeRoot: &curToSubtreeRoot);
    }
    CDmeDag::RemoveAllChildren(this: pDag);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00531DA0
// Name: private: void CDmeModel::RemoveAllChildren(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::RemoveAllChildren(CDmeModel *this, CDmeDag *pSubtreeRoot)
{
  int v3; // ebx
  CDmeDag *Child; // eax
  CDmeDag *v5; // esi
  int i; // esi
  CDmeDag *v7; // eax
  matrix3x4_t root; // [esp+Ch] [ebp-34h] BYREF
  CDmeModel *v9; // [esp+3Ch] [ebp-4h]
  int nCount; // [esp+48h] [ebp+8h]

  v9 = this;
  SetIdentityMatrix(matrix: &root);
  v3 = 0;
  nCount = CDmElementFramework::GetPhase(this: pSubtreeRoot);
  if ( nCount > 0 )
  {
    do
    {
      Child = CDmeDag::GetChild(this: pSubtreeRoot, i: v3);
      v5 = Child;
      if ( Child != nullptr && Child->IsA(this: Child, a2: CDmeJoint::m_classType) )
        CDmeModel::RemoveAllChildren(this: v9, pDag: v5, pSubtreeRoot, jointToSubtreeRoot: &root);
      ++v3;
    }
    while ( v3 < nCount );
  }
  for ( i = CDmElementFramework::GetPhase(this: pSubtreeRoot) - 1; i >= 0; --i )
  {
    v7 = CDmeDag::GetChild(this: pSubtreeRoot, i);
    if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeJoint::m_classType) )
      CDmeDag::RemoveChild(this: pSubtreeRoot, i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00531E50
// Name: protected: void CDmeModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::OnConstruction(CDmeModel *this)
{
  CDmaElementArray<CDmeDag> *p_m_JointList; // edi
  CDmAttribute *v3; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  p_m_JointList = &this->m_JointList;
  this->m_JointList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "jointList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_JointList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_JointList->m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_BaseStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "baseStates",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_BaseStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BaseStates.m_pAttribute, typeSymbol: CDmeTransformList::m_classType);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: "Y");
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "upAxis", type: AT_STRING, pMemory: &this->m_UpAxis);
  this->m_UpAxis.m_pAttribute = v3;
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00531EF0
// Name: private: static void CDmeModel::CleanupModelRenderState(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmeModel::CleanupModelRenderState()
{
  IMatRenderContext *v0; // esi

  v0 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v0 != nullptr )
    v0->BeginRender(this: v0);
  v0->MatrixMode(this: v0, a2: MATERIAL_MODEL);
  v0->LoadIdentity(this: v0);
  v0->EndRender(this: v0);
  v0->Release(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x00531FC0
// Name: public: int CDmeModel::GetJointIndex(class CDmeDag __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetJointIndex(CDmeModel *this, CDmeDag *pJoint)
{
  int v3; // edi
  int v4; // eax
  CDmeDag *v5; // esi
  int nJointCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nJointCount = this->m_JointList.m_Storage.m_Size;
  if ( nJointCount <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeDag *)v4;
    if ( v4 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeDag::m_classType.u) == 0 )
    {
      v5 = nullptr;
    }
    if ( pJoint == v5 )
      break;
    if ( ++v3 >= nJointCount )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00532040
// Name: public: class CDmeTransformList __near * CDmeModel::FindBaseState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformList *__thiscall CDmeModel::FindBaseState(CDmeModel *this, const char *pBaseStateName)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  const char *v6; // eax
  int v8; // eax
  int v9; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_BaseStates.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeTransformList::m_classType.u) == 0 )
    {
      v5 = 0;
    }
    v6 = *(const char **)(v5 + 20);
    if ( v6 == (const char *)-1 )
      v6 = defaultValue;
    if ( _V_stricmp(s1: v6, s2: pBaseStateName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
  v9 = v8;
  if ( v8 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
         a1: v8,
         a2: CDmeTransformList::m_classType.u) != 0 )
  {
    return (CDmeTransformList *)v9;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00532110
// Name: public: void CDmeModel::CaptureJointsToBaseState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::CaptureJointsToBaseState(CDmeModel *this, const char *pBaseStateName)
{
  CDmeTransformList *BaseState; // eax
  int v4; // eax
  int v5; // eax
  CDmeTransformList *v6; // esi
  CDmeTransformList *v7; // ecx
  int m_Size; // esi
  int v9; // ecx
  DmFileId_t m_fileId; // edi
  int v11; // eax
  int v12; // esi
  const char *v13; // eax
  int v14; // eax
  int v15; // eax
  CExpressionCalculator *v16; // esi
  int v17; // edi
  int v18; // eax
  CDmeDag *v19; // esi
  const char *v20; // eax
  CDmeTransform *Transform; // eax
  const char *m_pAsString; // esi
  const char *Name; // eax
  matrix3x4_t mat; // [esp+Ch] [ebp-94h] BYREF
  char pBuf[40]; // [esp+3Ch] [ebp-64h] BYREF
  char szTmpBuf1[40]; // [esp+64h] [ebp-3Ch] BYREF
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *p_m_Transforms; // [esp+8Ch] [ebp-14h]
  DmElementHandle_t src; // [esp+90h] [ebp-10h] BYREF
  int i; // [esp+94h] [ebp-Ch]
  CDmeTransformList *pTransformList; // [esp+98h] [ebp-8h]
  int nJointCount; // [esp+9Ch] [ebp-4h] BYREF

  BaseState = CDmeModel::FindBaseState(this, pBaseStateName);
  pTransformList = BaseState;
  if ( BaseState == nullptr )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
           a1: g_pDataModel.u,
           a2: CDmeTransformList::m_classType.u,
           a3: pBaseStateName,
           a4: this->m_fileId,
           a5: 0);
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: v4);
    v6 = (CDmeTransformList *)v5;
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
           a1: v5,
           a2: CDmeTransformList::m_classType.u) != 0 )
    {
      v7 = v6;
    }
    else
    {
      v7 = nullptr;
    }
    pTransformList = v7;
    if ( v7 != nullptr )
      nJointCount = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v7);
    else
      nJointCount = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_BaseStates,
      src: (const DmElementHandle_t *)&nJointCount);
    BaseState = pTransformList;
  }
  m_Size = this->m_JointList.m_Storage.m_Size;
  v9 = BaseState->m_Transforms.m_Storage.m_Size;
  nJointCount = m_Size;
  if ( m_Size <= v9 )
  {
    if ( m_Size < v9 )
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveMultiple(
        this: &BaseState->m_Transforms,
        elem: m_Size,
        num: v9 - m_Size);
  }
  else
  {
    i = v9;
    p_m_Transforms = &BaseState->m_Transforms;
    while ( 1 )
    {
      m_fileId = BaseState->m_fileId;
      v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[i]);
      v12 = v11;
      if ( v11 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
             a1: v11,
             a2: CDmeDag::m_classType.u) == 0 )
      {
        v12 = 0;
      }
      v13 = *(const char **)(v12 + 20);
      if ( v13 == (const char *)-1 )
        v13 = defaultValue;
      v14 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
              a1: g_pDataModel.u,
              a2: CDmeTransform::m_classType.u,
              a3: v13,
              a4: m_fileId,
              a5: 0);
      v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
              a1: g_pDataModel.u,
              a2: v14);
      v16 = (CExpressionCalculator *)v15;
      if ( v15 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v15 + 16))(
             a1: v15,
             a2: CDmeTransform::m_classType.u) != 0 )
      {
        src = CCodecBuffer_Block::GetBufferType(this: v16);
      }
      else
      {
        src = DMELEMENT_HANDLE_INVALID;
      }
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: p_m_Transforms,
        &src);
      if ( ++i >= nJointCount )
        break;
      BaseState = pTransformList;
    }
    m_Size = nJointCount;
  }
  v17 = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v18 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[v17]);
      v19 = (CDmeDag *)v18;
      if ( v18 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v18 + 16))(
             a1: v18,
             a2: CDmeDag::m_classType.u) != 0 )
      {
        Transform = CDmeDag::GetTransform(this: v19);
        if ( Transform != nullptr )
        {
          CDmeTransform::GetTransform(this: Transform, transform: &mat);
          CDmeTransformList::SetTransform(this: pTransformList, nIndex: v17, &mat);
        }
        else
        {
          UniqueIdToString(id: &this->m_Id, pBuf, nMaxLen: 38);
          UniqueIdToString(id: &v19->m_Id, pBuf: szTmpBuf1, nMaxLen: 38);
          m_pAsString = v19->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = defaultValue;
          Name = CDmAttribute::GetName((CDmAttribute *)this);
          _Warning(
            a1: "DmeModel::CaptureJointsToBaseState( %s ) - DmeModel %s[%s].jointList[ %d ].transform ( %s[%s].transform ) is NULL\n",
            pBaseStateName,
            Name,
            pBuf,
            v17,
            m_pAsString,
            szTmpBuf1);
        }
      }
      else
      {
        UniqueIdToString(id: &this->m_Id, pBuf: szTmpBuf1, nMaxLen: 38);
        v20 = CDmAttribute::GetName((CDmAttribute *)this);
        _Warning(
          a1: "DmeModel::CaptureJointsToBaseState( %s ): DmeModel %s[%s].jointList[ %d ] is NULL\n",
          pBaseStateName,
          v20,
          szTmpBuf1,
          v17);
      }
      ++v17;
    }
    while ( v17 < nJointCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005323C0
// Name: private: void CDmeModel::LoadJointTransform(class CDmeDag __near *,class CDmeTransformList __near *,struct matrix3x4_t const __near &,struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeModel::LoadJointTransform(
        CDmeModel *this@<ecx>,
        int a2@<esi>,
        CDmeDag *pJoint,
        CDmeTransformList *pBindPose,
        const matrix3x4_t *parentToWorld,
        const matrix3x4_t *parentToBindPose,
        bool bSetHardwareState)
{
  int JointIndex; // edi
  CDmeTransform *Transform; // eax
  CDmeTransform *v9; // eax
  int v10; // eax
  int v11; // esi
  int Phase; // edi
  int i; // esi
  CDmeDag *Child; // eax
  matrix3x4_t bindPoseToJoint; // [esp+8h] [ebp-124h] BYREF
  matrix3x4_t jointToParent; // [esp+38h] [ebp-F4h] BYREF
  matrix3x4_t jointToWorld; // [esp+68h] [ebp-C4h] BYREF
  matrix3x4_t bindJointToParent; // [esp+98h] [ebp-94h] BYREF
  matrix3x4_t jointToBindPose; // [esp+C8h] [ebp-64h] BYREF
  matrix3x4_t bindPoseToWorld; // [esp+F8h] [ebp-34h] BYREF
  CDmeModel *v21; // [esp+128h] [ebp-4h]

  v21 = this;
  JointIndex = CDmeModel::GetJointIndex(this, pJoint);
  if ( JointIndex >= 0 )
  {
    Transform = CDmeDag::GetTransform(this: pJoint);
    CDmeTransform::GetTransform(this: Transform, transform: &jointToParent);
    ConcatTransforms(in1: parentToWorld, in2: &jointToParent, out: &jointToWorld);
    if ( pBindPose != nullptr )
    {
      if ( JointIndex >= pBindPose->m_Transforms.m_Storage.m_Size )
      {
        _Warning(
          a1: "Model is in an invalid state! There are different numbers of bones in the bind pose and joint transform list!\n");
        return;
      }
      v9 = CDmeTransformList::GetTransform(this: pBindPose, nIndex: JointIndex);
      CDmeTransform::GetTransform(this: v9, transform: &bindJointToParent);
    }
    else
    {
      MatrixCopy(in: &jointToParent, out: &bindJointToParent);
    }
    ConcatTransforms(in1: parentToBindPose, in2: &bindJointToParent, out: &jointToBindPose);
    MatrixInvert(in: &jointToBindPose, out: &bindPoseToJoint);
    ConcatTransforms(in1: &jointToWorld, in2: &bindPoseToJoint, out: &bindPoseToWorld);
    if ( bSetHardwareState )
    {
      v10 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
      v11 = v10;
      if ( v10 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 424))(a1: v11, a2: JointIndex);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 4))(a1: v11);
    }
    MatrixCopy(in: &bindPoseToWorld, out: &s_PoseToWorld.m_Memory.m_pMemory[JointIndex]);
    Phase = CDmElementFramework::GetPhase(this: pJoint);
    for ( i = 0; i < Phase; ++i )
    {
      Child = CDmeDag::GetChild(this: pJoint, i);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this: v21,
          pJoint: Child,
          pBindPose,
          parentToWorld: &jointToWorld,
          parentToBindPose: &jointToBindPose,
          bSetHardwareState);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00532550
// Name: public: class CDmeDag __near * CDmeModel::GetJoint(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeModel::GetJoint(CDmeModel *this, const char *pJointName)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  const char *v6; // eax
  int nJointCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nJointCount = this->m_JointList.m_Storage.m_Size;
  if ( nJointCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeDag::m_classType.u) != 0 )
    {
      v6 = *(const char **)(v5 + 20);
      if ( v6 == (const char *)-1 )
        v6 = defaultValue;
      if ( _V_stricmp(s1: pJointName, s2: v6) == 0 )
        break;
    }
    if ( ++v3 >= nJointCount )
      return nullptr;
  }
  return (CDmeDag *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x005325E0
// Name: public: int CDmeModel::AddJoint(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::AddJoint(CDmeModel *this, int pJoint)
{
  CExpressionCalculator *v2; // edi
  int result; // eax

  v2 = (CExpressionCalculator *)pJoint;
  result = CDmeModel::GetJointIndex(this, (CDmeDag *)pJoint);
  if ( result < 0 )
  {
    if ( v2 != nullptr )
      pJoint = CCodecBuffer_Block::GetBufferType(this: v2);
    else
      pJoint = -1;
    return CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
             this: &this->m_JointList,
             src: (const DmElementHandle_t *)&pJoint);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00532620
// Name: public: virtual void CDmeModel::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::Draw(CDmeModel *this, CDmeDrawSettings *pDrawSettings)
{
  CDmeModel **v3; // eax

  if ( CDmeModel::s_ModelStack.m_Size >= CDmeModel::s_ModelStack.m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&CDmeModel::s_ModelStack, num: 1);
  CDmeModel::s_ModelStack.m_pElements = CDmeModel::s_ModelStack.m_Memory.m_pMemory;
  v3 = &CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size++];
  if ( v3 != nullptr )
    *v3 = this;
  CDmeDag::Draw(this, pDrawSettings);
  --CDmeModel::s_ModelStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00532680
// Name: private: enum CDmeModel::SetupBoneRetval_t CDmeModel::SetupBoneMatrixState(struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::SetupBoneMatrixState(
        CDmeModel *this,
        const matrix3x4_t *shapeToWorld,
        bool bForceSoftwareSkin)
{
  int m_Size; // edi
  bool v6; // zf
  CDmeTransformList *BaseState; // ebx
  int v8; // edi
  CDmeDag *Child; // eax
  matrix3x4_t parentToBindPose; // [esp+8h] [ebp-34h] BYREF
  int nChildCount; // [esp+38h] [ebp-4h]
  bool bSetHardwareState; // [esp+48h] [ebp+Ch]

  m_Size = this->m_JointList.m_Storage.m_Size;
  if ( m_Size <= 0 )
    return 0;
  if ( m_Size > g_pMaterialSystemHardwareConfig->MaxVertexShaderBlendMatrices(this: g_pMaterialSystemHardwareConfig)
    || (v6 = !bForceSoftwareSkin, bSetHardwareState = true, !v6) )
  {
    bSetHardwareState = false;
  }
  if ( s_PoseToWorld.m_Size < m_Size )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: m_Size - s_PoseToWorld.m_Size);
  BaseState = CDmeModel::FindBaseState(this, pBaseStateName: "bind");
  SetIdentityMatrix(matrix: &parentToBindPose);
  v8 = 0;
  nChildCount = CDmElementFramework::GetPhase(this);
  if ( nChildCount > 0 )
  {
    do
    {
      Child = CDmeDag::GetChild(this, i: v8);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this,
          a2: (int)this,
          pJoint: Child,
          pBindPose: BaseState,
          parentToWorld: shapeToWorld,
          &parentToBindPose,
          bSetHardwareState);
      ++v8;
    }
    while ( v8 < nChildCount );
  }
  return bSetHardwareState + 1;
}

//------------------------------------------------------------------------------
// Address: 0x00532740
// Name: private: static struct matrix3x4_t __near * CDmeModel::SetupModelRenderState(struct matrix3x4_t const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__cdecl CDmeModel::SetupModelRenderState(
        const matrix3x4_t *shapeToWorld,
        bool bHasSkinningData,
        bool bForceSoftwareSkin)
{
  IMatRenderContext *v3; // esi
  int v4; // eax
  matrix3x4_t *m_pMemory; // edi
  matrix3x4_t *v7; // edi

  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( bHasSkinningData && CDmeModel::s_ModelStack.m_Size > 0 )
  {
    v4 = CDmeModel::SetupBoneMatrixState(
           this: CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size - 1],
           shapeToWorld,
           bForceSoftwareSkin);
    if ( v4 == 1 )
    {
      v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
      v3->LoadIdentity(this: v3);
      m_pMemory = s_PoseToWorld.m_Memory.m_pMemory;
      v3->EndRender(this: v3);
      v3->Release(this: v3);
      return m_pMemory;
    }
    if ( v4 != 0 )
    {
      if ( v3 != nullptr )
      {
        v3->EndRender(this: v3);
        v3->Release(this: v3);
        return nullptr;
      }
      return nullptr;
    }
  }
  if ( !bForceSoftwareSkin )
  {
    v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
    v3->LoadMatrix(this: v3, a2: shapeToWorld);
    v3->EndRender(this: v3);
    v3->Release(this: v3);
    return nullptr;
  }
  v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
  v3->LoadIdentity(this: v3);
  if ( s_PoseToWorld.m_Size < 1 )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: 1 - s_PoseToWorld.m_Size);
  MatrixCopy(in: shapeToWorld, out: s_PoseToWorld.m_Memory.m_pMemory);
  v7 = s_PoseToWorld.m_Memory.m_pMemory;
  v3->EndRender(this: v3);
  v3->Release(this: v3);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x005328E0
// Name: private: void CDmeModel::RemoveJoints(int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::RemoveJoints(CDmeModel *this, int nNewJointCount, char *pInvJointRemap)
{
  CDmeModel *v3; // ebx
  void *v4; // esp
  int *v5; // edi
  DmElementHandle_t v6; // eax
  int v7; // eax
  int v8; // esi
  int j; // esi
  CExpressionCalculator *v10; // ecx
  CDmeTransform **m_pFixedMemory; // eax
  int m_Size; // ecx
  int v13; // eax
  int v14; // esi
  char v15; // al
  int v16; // esi
  int v17; // eax
  int v18; // ebx
  unsigned int v19; // esi
  unsigned __int8 *v20; // edi
  int v21; // ebx
  int v22; // edi
  int v23; // eax
  CDmeTransform *v24; // esi
  int v25; // edi
  CDmeTransform **v26; // ebx
  int v27; // eax
  CDmeTransform *v28; // esi
  int v29; // edi
  int k; // esi
  CExpressionCalculator *v31; // ecx
  _BYTE v32[12]; // [esp+0h] [ebp-444h] BYREF
  CUtlVectorFixedGrowable<CDmeTransform *,256> transforms; // [esp+Ch] [ebp-438h] BYREF
  CDmeModel *v34; // [esp+424h] [ebp-20h]
  int nCount; // [esp+428h] [ebp-1Ch]
  int nOldJointTransformCount; // [esp+42Ch] [ebp-18h]
  int nStateJointCount; // [esp+430h] [ebp-14h]
  DmElementHandle_t src; // [esp+434h] [ebp-10h] BYREF
  int v39; // [esp+438h] [ebp-Ch]
  int nTransformCount; // [esp+43Ch] [ebp-8h]
  int i; // [esp+440h] [ebp-4h] BYREF

  v3 = this;
  nOldJointTransformCount = this->m_JointList.m_Storage.m_Size;
  v34 = this;
  v4 = alloca(4 * nNewJointCount);
  v5 = (int *)v32;
  nTransformCount = (int)v32;
  if ( nNewJointCount > 0 )
  {
    v6 = pInvJointRemap - v32;
    src = pInvJointRemap - v32;
    i = nNewJointCount;
    while ( 1 )
    {
      v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: v3->m_JointList.m_Storage.m_Memory.m_pMemory[*(int *)((char *)v5 + v6)]);
      v8 = v7;
      if ( v7 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
             a1: v7,
             a2: CDmeDag::m_classType.u) == 0 )
      {
        v8 = 0;
      }
      *v5++ = v8;
      if ( --i == 0 )
        break;
      v6 = src;
    }
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &v3->m_JointList);
  for ( j = 0; j < nNewJointCount; ++j )
  {
    v10 = *(CExpressionCalculator **)(nTransformCount + 4 * j);
    if ( v10 != nullptr )
      i = CCodecBuffer_Block::GetBufferType(this: v10);
    else
      i = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &v3->m_JointList,
      src: (const DmElementHandle_t *)&i);
  }
  m_pFixedMemory = transforms.m_Memory.m_pFixedMemory;
  transforms.m_pElements = transforms.m_Memory.m_pFixedMemory;
  m_Size = v3->m_BaseStates.m_Storage.m_Size;
  transforms.m_Memory.m_pMemory = transforms.m_Memory.m_pFixedMemory;
  transforms.m_Memory.m_nAllocationCount = 256;
  transforms.m_Memory.m_nGrowSize = -1;
  transforms.m_Memory.m_nMallocGrowSize = 0;
  transforms.m_Size = 0;
  nCount = m_Size;
  i = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v13 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: v3->m_BaseStates.m_Storage.m_Memory.m_pMemory[i]);
      v14 = v13;
      if ( v13 == 0
        || (v15 = (*(int (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v13 + 16))(
                    a1: v13,
                    a2: CDmeTransformList::m_classType.u),
            v39 = v14,
            v15 == 0) )
      {
        v39 = 0;
      }
      v16 = *(_DWORD *)(v39 + 80);
      v17 = 0;
      nTransformCount = v16;
      transforms.m_Size = 0;
      if ( v16 != 0 )
      {
        if ( v16 > transforms.m_Memory.m_nAllocationCount )
        {
          v18 = v16 - transforms.m_Memory.m_nAllocationCount;
          if ( transforms.m_Memory.m_nGrowSize < 0 )
          {
            transforms.m_Memory.m_nGrowSize = transforms.m_Memory.m_nMallocGrowSize;
            if ( transforms.m_Memory.m_nAllocationCount != 0 )
            {
              v19 = 4 * transforms.m_Memory.m_nAllocationCount;
              v20 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(
                                         this: _g_pMemAlloc,
                                         a2: 4 * transforms.m_Memory.m_nAllocationCount);
              memcpy(dst: v20, src: (unsigned __int8 *)transforms.m_Memory.m_pMemory, count: v19);
              v16 = nTransformCount;
              transforms.m_Memory.m_pMemory = (CDmeTransform **)v20;
            }
            else
            {
              transforms.m_Memory.m_pMemory = nullptr;
            }
          }
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&transforms, num: v18);
          v17 = transforms.m_Size;
        }
        transforms.m_Size = v16 + v17;
        transforms.m_pElements = transforms.m_Memory.m_pMemory;
        if ( v17 > 0 && v16 > 0 )
          _V_memmove(dest: &transforms.m_Memory.m_pMemory[v16], src: transforms.m_Memory.m_pMemory, count: 4 * v17);
      }
      v21 = nNewJointCount;
      v22 = 0;
      nStateJointCount = nNewJointCount;
      if ( nNewJointCount > 0 )
      {
        do
        {
          v23 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                  a1: g_pDataModel.u,
                  a2: *(_DWORD *)(*(_DWORD *)(v39 + 68) + 4 * *(_DWORD *)&pInvJointRemap[4 * v22]));
          v24 = (CDmeTransform *)v23;
          if ( v23 == 0
            || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v23 + 16))(
                 a1: v23,
                 a2: CDmeTransform::m_classType.u) == 0 )
          {
            v24 = nullptr;
          }
          transforms.m_Memory.m_pMemory[v22++] = v24;
        }
        while ( v22 < nNewJointCount );
        v16 = nTransformCount;
      }
      v25 = nOldJointTransformCount;
      if ( nOldJointTransformCount < v16 )
      {
        do
        {
          v26 = &transforms.m_Memory.m_pMemory[v21];
          v27 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                  a1: g_pDataModel.u,
                  a2: *(_DWORD *)(*(_DWORD *)(v39 + 68) + 4 * v25));
          v28 = (CDmeTransform *)v27;
          if ( v27 == 0
            || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v27 + 16))(
                 a1: v27,
                 a2: CDmeTransform::m_classType.u) == 0 )
          {
            v28 = nullptr;
          }
          ++nStateJointCount;
          ++v25;
          *v26 = v28;
          v21 = nStateJointCount;
        }
        while ( v25 < nTransformCount );
      }
      v29 = v39;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)(v39 + 68));
      for ( k = 0; k < v21; ++k )
      {
        v31 = (CExpressionCalculator *)transforms.m_Memory.m_pMemory[k];
        if ( v31 != nullptr )
          src = CCodecBuffer_Block::GetBufferType(this: v31);
        else
          src = DMELEMENT_HANDLE_INVALID;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)(v29 + 68),
          &src);
      }
      if ( ++i >= nCount )
        break;
      v3 = v34;
    }
    m_pFixedMemory = transforms.m_Memory.m_pMemory;
  }
  transforms.m_Size = 0;
  if ( transforms.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pFixedMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
      m_pFixedMemory = nullptr;
      transforms.m_Memory.m_pMemory = nullptr;
    }
    transforms.m_Memory.m_nAllocationCount = 0;
  }
  transforms.m_pElements = m_pFixedMemory;
  if ( transforms.m_Memory.m_nGrowSize >= 0 && m_pFixedMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00532C60
// Name: public: void CDmeModel::CollapseJoints(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::CollapseJoints(CDmeModel *this, const char *pJointName)
{
  int m_Size; // esi
  void *v4; // esp
  int v5; // edi
  int v6; // eax
  CExpressionCalculator *v7; // esi
  int Child; // eax
  unsigned int v9; // esi
  void *v10; // esp
  const int *v11; // edi
  void *v12; // esp
  int v13; // ecx
  int v14; // esi
  int v15; // eax
  CDmeDag *v16; // edi
  int v17; // eax
  int *v18; // edx
  int i; // eax
  CDmeShape *Shape; // eax
  CDmeMesh *v21; // esi
  int v22; // esi
  CDmeDag *v23; // eax
  _BYTE v24[12]; // [esp+0h] [ebp-28h] BYREF
  CDmeDag *pParent; // [esp+Ch] [ebp-1Ch] BYREF
  int *pInvJointRemap; // [esp+10h] [ebp-18h]
  int nCollapseJointIndex; // [esp+14h] [ebp-14h]
  int *pJointRemap; // [esp+18h] [ebp-10h]
  bool *pIsCollapsed; // [esp+1Ch] [ebp-Ch]
  CDmeDag *pJoint; // [esp+20h] [ebp-8h]
  int nNewJointCount; // [esp+24h] [ebp-4h]
  int nCount; // [esp+30h] [ebp+8h]
  int nCounta; // [esp+30h] [ebp+8h]

  pJoint = CDmeModel::GetJoint(this, pJointName);
  if ( pJoint != nullptr )
  {
    m_Size = this->m_JointList.m_Storage.m_Size;
    nCount = m_Size;
    v4 = alloca(m_Size);
    v5 = 0;
    pIsCollapsed = v24;
    if ( m_Size > 0 )
    {
      do
      {
        v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[v5]);
        v7 = (CExpressionCalculator *)v6;
        if ( v6 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
               a1: v6,
               a2: CDmeDag::m_classType.u) != 0 )
        {
          Child = CDmeDag::FindChild(this: pJoint, &pParent, pChild: v7);
          pIsCollapsed[v5] = Child >= 0;
        }
        ++v5;
      }
      while ( v5 < nCount );
      m_Size = nCount;
    }
    nNewJointCount = 0;
    nCollapseJointIndex = 0;
    v9 = (4 * m_Size + 15) & 0xFFFFFFF0;
    v10 = alloca(v9);
    v11 = (const int *)v24;
    pJointRemap = (int *)v24;
    v12 = alloca(v9);
    v13 = nCount;
    v14 = 0;
    for ( pInvJointRemap = (int *)v24; v14 < v13; ++v14 )
    {
      if ( pIsCollapsed[v14] )
      {
        v11[v14] = -1;
      }
      else
      {
        v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[v14]);
        v16 = (CDmeDag *)v15;
        if ( v15 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v15 + 16))(
               a1: v15,
               a2: CDmeDag::m_classType.u) == 0 )
        {
          v16 = nullptr;
        }
        v17 = nNewJointCount;
        if ( pJoint == v16 )
          nCollapseJointIndex = nNewJointCount;
        v18 = pJointRemap;
        pInvJointRemap[nNewJointCount] = v14;
        v13 = nCount;
        v18[v14] = v17;
        nNewJointCount = v17 + 1;
        v11 = v18;
      }
    }
    for ( i = 0; i < v13; ++i )
    {
      if ( v11[i] < 0 )
        v11[i] = nCollapseJointIndex;
    }
    Shape = CDmeDag::GetShape(this);
    v21 = (CDmeMesh *)Shape;
    if ( Shape != nullptr && Shape->IsA(this: Shape, a2: CDmeMesh::m_classType) )
      CDmeMesh::Reskin(this: v21, pJointTransformIndexRemap: v11);
    v22 = 0;
    nCounta = CDmElementFramework::GetPhase(this);
    if ( nCounta > 0 )
    {
      do
      {
        v23 = CDmeDag::GetChild(this, i: v22);
        CDmeModel::ReskinMeshes(this, pDag: v23, pJointTransformIndexRemap: v11);
        ++v22;
      }
      while ( v22 < nCounta );
    }
    CDmeModel::RemoveJoints(this, nNewJointCount, (char *)pInvJointRemap);
    CDmeModel::RemoveAllChildren(this, pSubtreeRoot: pJoint);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00532E30
// Name: protected: CDmeModel::CDmeModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeModel *__thiscall CDmeModel::CDmeModel(
        CDmeModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeModel_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeModel_vtbl *)&CDmeModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_JointList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_BaseStates);
  this->m_UpAxis.m_Storage.u.m_Id = -1;
  this->m_UpAxis.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00532EC0
// Name: public: virtual bool CDmeModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeModel::IsA(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00532EF0
// Name: public: virtual int CDmeModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetInheritanceDepth(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00532F40
// Name: protected: virtual void CDmeModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::PerformConstruction(CDmeModel *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  CDmeModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006AF2B0
// Name: _dynamic_initializer_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeModel::s_Allocator,
    blockSize: 200,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AF310
// Name: _dynamic_initializer_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_ModelStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4A70
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B4A80
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&CDmeModel::s_ModelStack);
}

//------------------------------------------------------------------------------
// Address: 0x006AF2E0
// Name: _dynamic_initializer_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AF2F0
// Name: _dynamic_initializer_for__g_CDmeModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeModel_Helper,
           classname: "DmeModel",
           pFactory: &g_CDmeModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AF320
// Name: _dynamic_initializer_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_PoseToWorld__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_PoseToWorld__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4A90
// Name: _dynamic_atexit_destructor_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_PoseToWorld__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_PoseToWorld);
}

//------------------------------------------------------------------------------
// Address: 0x006B4AA0
// Name: _dynamic_atexit_destructor_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeModel_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00473E70
// Name: protected: void CDmeModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::OnConstruction(CDmeModel *this)
{
  CDmaElementArray<CDmeDag> *p_m_JointList; // edi
  CDmAttribute *v3; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  p_m_JointList = &this->m_JointList;
  this->m_JointList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "jointList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_JointList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_JointList->m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_BaseStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "baseStates",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_BaseStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BaseStates.m_pAttribute, typeSymbol: CDmeTransformList::m_classType);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "Y");
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "upAxis", type: AT_STRING, pMemory: &this->m_UpAxis);
  this->m_UpAxis.m_pAttribute = v3;
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00473F10
// Name: private: static void CDmeModel::CleanupModelRenderState(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmeModel::CleanupModelRenderState()
{
  IMatRenderContext *v0; // esi

  v0 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v0 != nullptr )
    v0->BeginRender(this: v0);
  v0->MatrixMode(this: v0, a2: MATERIAL_MODEL);
  v0->LoadIdentity(this: v0);
  v0->EndRender(this: v0);
  v0->Release(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x00474040
// Name: public: class CDmeTransform __near * CDmeTransformList::GetTransform(int)
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeTransformList::GetTransform(CDmeTransformList *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transforms.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeTransform::m_classType) )
    return (CDmeTransform *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00474090
// Name: public: int CDmeModel::GetJointIndex(class CDmeDag __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetJointIndex(CDmeModel *this, CDmeDag *pJoint)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmeDag *v5; // esi
  int nJointCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nJointCount = this->m_JointList.m_Storage.m_Size;
  if ( nJointCount <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeDag *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeDag::m_classType) )
      v5 = nullptr;
    if ( pJoint == v5 )
      break;
    if ( ++v3 >= nJointCount )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00474110
// Name: public: class CDmeTransformList __near * CDmeModel::FindBaseState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformList *__thiscall CDmeModel::FindBaseState(CDmeModel *this, const char *pBaseStateName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char *m_pAsString; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_BaseStates.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeTransformList::m_classType) )
      v5 = nullptr;
    m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pch;
    if ( _V_stricmp(s1: m_pAsString, s2: pBaseStateName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
  v9 = v8;
  if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeTransformList::m_classType) )
    return (CDmeTransformList *)v9;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004741E0
// Name: private: void CDmeModel::LoadJointTransform(class CDmeDag __near *,class CDmeTransformList __near *,struct matrix3x4_t const __near &,struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeModel::LoadJointTransform(
        CDmeModel *this@<ecx>,
        int a2@<esi>,
        CDmeDag *pJoint,
        CDmeTransformList *pBindPose,
        const matrix3x4_t *parentToWorld,
        const matrix3x4_t *parentToBindPose,
        bool bSetHardwareState)
{
  int JointIndex; // edi
  CDmeTransform *Transform; // eax
  CDmeTransform *v9; // eax
  int v10; // eax
  int v11; // esi
  int Phase; // edi
  int i; // esi
  CDmeDag *Child; // eax
  matrix3x4_t bindPoseToJoint; // [esp+8h] [ebp-124h] BYREF
  matrix3x4_t jointToParent; // [esp+38h] [ebp-F4h] BYREF
  matrix3x4_t jointToWorld; // [esp+68h] [ebp-C4h] BYREF
  matrix3x4_t bindJointToParent; // [esp+98h] [ebp-94h] BYREF
  matrix3x4_t jointToBindPose; // [esp+C8h] [ebp-64h] BYREF
  matrix3x4_t bindPoseToWorld; // [esp+F8h] [ebp-34h] BYREF
  CDmeModel *v21; // [esp+128h] [ebp-4h]

  v21 = this;
  JointIndex = CDmeModel::GetJointIndex(this, pJoint);
  if ( JointIndex >= 0 )
  {
    Transform = CDmeDag::GetTransform(this: pJoint);
    CDmeTransform::GetTransform(this: Transform, transform: &jointToParent);
    ConcatTransforms(in1: parentToWorld, in2: &jointToParent, out: &jointToWorld);
    if ( pBindPose != nullptr )
    {
      if ( JointIndex >= pBindPose->m_Transforms.m_Storage.m_Size )
      {
        _Warning(
          a1: "Model is in an invalid state! There are different numbers of bones in the bind pose and joint transform list!\n");
        return;
      }
      v9 = CDmeTransformList::GetTransform(this: pBindPose, nIndex: JointIndex);
      CDmeTransform::GetTransform(this: v9, transform: &bindJointToParent);
    }
    else
    {
      MatrixCopy(in: &jointToParent, out: &bindJointToParent);
    }
    ConcatTransforms(in1: parentToBindPose, in2: &bindJointToParent, out: &jointToBindPose);
    MatrixInvert(in: &jointToBindPose, out: &bindPoseToJoint);
    ConcatTransforms(in1: &jointToWorld, in2: &bindPoseToJoint, out: &bindPoseToWorld);
    if ( bSetHardwareState )
    {
      v10 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
      v11 = v10;
      if ( v10 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 424))(a1: v11, a2: JointIndex);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 4))(a1: v11);
    }
    MatrixCopy(in: &bindPoseToWorld, out: &s_PoseToWorld.m_Memory.m_pMemory[JointIndex]);
    Phase = CDmElementFramework::GetPhase(this: pJoint);
    for ( i = 0; i < Phase; ++i )
    {
      Child = CDmeDag::GetChild(this: pJoint, i);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this: v21,
          pJoint: Child,
          pBindPose,
          parentToWorld: &jointToWorld,
          parentToBindPose: &jointToBindPose,
          bSetHardwareState);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474370
// Name: public: virtual void CDmeModel::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::Draw(CDmeModel *this, CDmeDrawSettings *pDrawSettings)
{
  CDmeModel **v3; // eax

  if ( CDmeModel::s_ModelStack.m_Size >= CDmeModel::s_ModelStack.m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&CDmeModel::s_ModelStack,
      num: 1);
  CDmeModel::s_ModelStack.m_pElements = CDmeModel::s_ModelStack.m_Memory.m_pMemory;
  v3 = &CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size++];
  if ( v3 != nullptr )
    *v3 = this;
  CDmeDag::Draw(this, pDrawSettings);
  --CDmeModel::s_ModelStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004743D0
// Name: private: enum CDmeModel::SetupBoneRetval_t CDmeModel::SetupBoneMatrixState(struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::SetupBoneMatrixState(
        CDmeModel *this,
        const matrix3x4_t *shapeToWorld,
        bool bForceSoftwareSkin)
{
  int m_Size; // edi
  bool v6; // zf
  CDmeTransformList *BaseState; // ebx
  int v8; // edi
  CDmeDag *Child; // eax
  matrix3x4_t parentToBindPose; // [esp+8h] [ebp-34h] BYREF
  int nChildCount; // [esp+38h] [ebp-4h]
  bool bSetHardwareState; // [esp+48h] [ebp+Ch]

  m_Size = this->m_JointList.m_Storage.m_Size;
  if ( m_Size <= 0 )
    return 0;
  if ( m_Size > g_pMaterialSystemHardwareConfig->MaxVertexShaderBlendMatrices(this: g_pMaterialSystemHardwareConfig)
    || (v6 = !bForceSoftwareSkin, bSetHardwareState = true, !v6) )
  {
    bSetHardwareState = false;
  }
  if ( s_PoseToWorld.m_Size < m_Size )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: m_Size - s_PoseToWorld.m_Size);
  BaseState = CDmeModel::FindBaseState(this, pBaseStateName: "bind");
  SetIdentityMatrix(matrix: &parentToBindPose);
  v8 = 0;
  nChildCount = CDmElementFramework::GetPhase(this);
  if ( nChildCount > 0 )
  {
    do
    {
      Child = CDmeDag::GetChild(this, i: v8);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this,
          a2: (int)this,
          pJoint: Child,
          pBindPose: BaseState,
          parentToWorld: shapeToWorld,
          &parentToBindPose,
          bSetHardwareState);
      ++v8;
    }
    while ( v8 < nChildCount );
  }
  return bSetHardwareState + 1;
}

//------------------------------------------------------------------------------
// Address: 0x00474490
// Name: private: static struct matrix3x4_t __near * CDmeModel::SetupModelRenderState(struct matrix3x4_t const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__cdecl CDmeModel::SetupModelRenderState(
        const matrix3x4_t *shapeToWorld,
        bool bHasSkinningData,
        bool bForceSoftwareSkin)
{
  IMatRenderContext *v3; // esi
  int v4; // eax
  matrix3x4_t *m_pMemory; // edi
  matrix3x4_t *v7; // edi

  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( bHasSkinningData && CDmeModel::s_ModelStack.m_Size > 0 )
  {
    v4 = CDmeModel::SetupBoneMatrixState(
           this: CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size - 1],
           shapeToWorld,
           bForceSoftwareSkin);
    if ( v4 == 1 )
    {
      v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
      v3->LoadIdentity(this: v3);
      m_pMemory = s_PoseToWorld.m_Memory.m_pMemory;
      v3->EndRender(this: v3);
      v3->Release(this: v3);
      return m_pMemory;
    }
    if ( v4 != 0 )
    {
      if ( v3 != nullptr )
      {
        v3->EndRender(this: v3);
        v3->Release(this: v3);
        return nullptr;
      }
      return nullptr;
    }
  }
  if ( !bForceSoftwareSkin )
  {
    v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
    v3->LoadMatrix(this: v3, a2: shapeToWorld);
    v3->EndRender(this: v3);
    v3->Release(this: v3);
    return nullptr;
  }
  v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
  v3->LoadIdentity(this: v3);
  if ( s_PoseToWorld.m_Size < 1 )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: 1 - s_PoseToWorld.m_Size);
  MatrixCopy(in: shapeToWorld, out: s_PoseToWorld.m_Memory.m_pMemory);
  v7 = s_PoseToWorld.m_Memory.m_pMemory;
  v3->EndRender(this: v3);
  v3->Release(this: v3);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00474630
// Name: protected: CDmeModel::CDmeModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeModel *__thiscall CDmeModel::CDmeModel(
        CDmeModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeModel_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeModel_vtbl *)&CDmeModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_JointList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_BaseStates);
  this->m_UpAxis.m_Storage.u.m_Id = -1;
  this->m_UpAxis.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004746C0
// Name: public: virtual bool CDmeModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeModel::IsA(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004746F0
// Name: public: virtual int CDmeModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetInheritanceDepth(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00474750
// Name: protected: virtual void CDmeModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::PerformConstruction(CDmeModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057BAD0
// Name: _dynamic_initializer_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BE80
// Name: _dynamic_initializer_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeModel::s_Allocator,
    blockSize: 200,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BEE0
// Name: _dynamic_initializer_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_ModelStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__);
}

//------------------------------------------------------------------------------
// Address: 0x00580070
// Name: _dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580200
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580210
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmeModel::s_ModelStack);
}

//------------------------------------------------------------------------------
// Address: 0x00473F60
// Name: class CDmeTransform __near * CreateElement<class CDmeTransform>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransform *__cdecl CreateElement<CDmeTransform>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeTransform::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeTransform::m_classType) )
    return (CDmeTransform *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0057BB00
// Name: _dynamic_initializer_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BB10
// Name: _dynamic_initializer_for__g_CDmeTransformList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformList_Helper,
           classname: "DmeTransformList",
           pFactory: &g_CDmeTransformList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057BEB0
// Name: _dynamic_initializer_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BEC0
// Name: _dynamic_initializer_for__g_CDmeModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeModel_Helper,
           classname: "DmeModel",
           pFactory: &g_CDmeModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057BEF0
// Name: _dynamic_initializer_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_PoseToWorld__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_PoseToWorld__);
}

//------------------------------------------------------------------------------
// Address: 0x00580080
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformList_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580220
// Name: _dynamic_atexit_destructor_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_PoseToWorld__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_PoseToWorld);
}

//------------------------------------------------------------------------------
// Address: 0x00580230
// Name: _dynamic_atexit_destructor_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeModel_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004EF1A0
// Name: public: bool CDmeModel::IsZUp(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeModel::IsZUp(CDmeModel *this)
{
  const char *m_pAsString; // eax

  m_pAsString = this->m_UpAxis.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = pDeltaStateName;
  return StringAfterPrefix(str: m_pAsString, prefix: "Z") != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004EF1D0
// Name: protected: void CDmeModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::OnConstruction(CDmeModel *this)
{
  CDmaElementArray<CDmeDag> *p_m_JointList; // edi
  CDmAttribute *v3; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  p_m_JointList = &this->m_JointList;
  this->m_JointList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "jointList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_JointList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_JointList->m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_BaseStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "baseStates",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_BaseStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BaseStates.m_pAttribute, typeSymbol: CDmeTransformList::m_classType);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: "Y");
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "upAxis", type: AT_STRING, pMemory: &this->m_UpAxis);
  this->m_UpAxis.m_pAttribute = v3;
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004EF270
// Name: public: int CDmeModel::GetJointCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetJointCount(CDmeModel *this)
{
  return this->m_JointList.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004EF280
// Name: private: static void CDmeModel::CleanupModelRenderState(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmeModel::CleanupModelRenderState()
{
  IMatRenderContext *v0; // esi

  v0 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v0 != nullptr )
    v0->BeginRender(this: v0);
  v0->MatrixMode(this: v0, a2: MATERIAL_MODEL);
  v0->LoadIdentity(this: v0);
  v0->EndRender(this: v0);
  v0->Release(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x004EF350
// Name: public: int CDmeModel::GetJointIndex(class CDmeDag __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetJointIndex(CDmeModel *this, CDmeDag *pJoint)
{
  int v3; // edi
  int v4; // eax
  CDmeDag *v5; // esi
  int nJointCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nJointCount = this->m_JointList.m_Storage.m_Size;
  if ( nJointCount <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeDag *)v4;
    if ( v4 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeDag::m_classType.u) == 0 )
    {
      v5 = nullptr;
    }
    if ( pJoint == v5 )
      break;
    if ( ++v3 >= nJointCount )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004EF3D0
// Name: public: class CDmeTransform __near * CDmeModel::GetJointTransform(int)
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeModel::GetJointTransform(CDmeModel *this, int nIndex)
{
  int v2; // eax
  CDmeDag *v3; // esi

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = (CDmeDag *)v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeDag::m_classType.u) != 0 )
  {
    return CDmeDag::GetTransform(this: v3);
  }
  else
  {
    return CDmeDag::GetTransform(this: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EF430
// Name: public: class CDmeTransformList __near * CDmeModel::FindBaseState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformList *__thiscall CDmeModel::FindBaseState(CDmeModel *this, const char *pBaseStateName)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  const char *v6; // eax
  int v8; // eax
  int v9; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_BaseStates.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeTransformList::m_classType.u) == 0 )
    {
      v5 = 0;
    }
    v6 = *(const char **)(v5 + 20);
    if ( v6 == (const char *)-1 )
      v6 = pDeltaStateName;
    if ( _V_stricmp(s1: v6, s2: pBaseStateName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
  v9 = v8;
  if ( v8 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
         a1: v8,
         a2: CDmeTransformList::m_classType.u) != 0 )
  {
    return (CDmeTransformList *)v9;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EF500
// Name: private: void CDmeModel::LoadJointTransform(class CDmeDag __near *,class CDmeTransformList __near *,struct matrix3x4_t const __near &,struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeModel::LoadJointTransform(
        CDmeModel *this@<ecx>,
        int a2@<esi>,
        CDmeDag *pJoint,
        CDmeTransformList *pBindPose,
        const matrix3x4_t *parentToWorld,
        const matrix3x4_t *parentToBindPose,
        bool bSetHardwareState)
{
  int JointIndex; // edi
  CDmeTransform *Transform; // eax
  CDmeTransform *v9; // eax
  int v10; // eax
  int v11; // esi
  int Phase; // edi
  int i; // esi
  CDmeDag *Child; // eax
  matrix3x4_t bindPoseToJoint; // [esp+8h] [ebp-124h] BYREF
  matrix3x4_t jointToParent; // [esp+38h] [ebp-F4h] BYREF
  matrix3x4_t jointToWorld; // [esp+68h] [ebp-C4h] BYREF
  matrix3x4_t bindJointToParent; // [esp+98h] [ebp-94h] BYREF
  matrix3x4_t jointToBindPose; // [esp+C8h] [ebp-64h] BYREF
  matrix3x4_t bindPoseToWorld; // [esp+F8h] [ebp-34h] BYREF
  CDmeModel *v21; // [esp+128h] [ebp-4h]

  v21 = this;
  JointIndex = CDmeModel::GetJointIndex(this, pJoint);
  if ( JointIndex >= 0 )
  {
    Transform = CDmeDag::GetTransform(this: pJoint);
    CDmeTransform::GetTransform(this: Transform, transform: &jointToParent);
    ConcatTransforms(in1: parentToWorld, in2: &jointToParent, out: &jointToWorld);
    if ( pBindPose != nullptr )
    {
      if ( JointIndex >= pBindPose->m_Transforms.m_Storage.m_Size )
      {
        _Warning(
          a1: "Model is in an invalid state! There are different numbers of bones in the bind pose and joint transform list!\n");
        return;
      }
      v9 = CDmeTransformList::GetTransform(this: pBindPose, nIndex: JointIndex);
      CDmeTransform::GetTransform(this: v9, transform: &bindJointToParent);
    }
    else
    {
      MatrixCopy(in: &jointToParent, out: &bindJointToParent);
    }
    ConcatTransforms(in1: parentToBindPose, in2: &bindJointToParent, out: &jointToBindPose);
    MatrixInvert(in: &jointToBindPose, out: &bindPoseToJoint);
    ConcatTransforms(in1: &jointToWorld, in2: &bindPoseToJoint, out: &bindPoseToWorld);
    if ( bSetHardwareState )
    {
      v10 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
      v11 = v10;
      if ( v10 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 424))(a1: v11, a2: JointIndex);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 4))(a1: v11);
    }
    MatrixCopy(in: &bindPoseToWorld, out: &s_PoseToWorld.m_Memory.m_pMemory[JointIndex]);
    Phase = CDmElementFramework::GetPhase(this: pJoint);
    for ( i = 0; i < Phase; ++i )
    {
      Child = CDmeDag::GetChild(this: pJoint, i);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this: v21,
          pJoint: Child,
          pBindPose,
          parentToWorld: &jointToWorld,
          parentToBindPose: &jointToBindPose,
          bSetHardwareState);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EF690
// Name: public: virtual void CDmeModel::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::Draw(CDmeModel *this, CDmeDrawSettings *pDrawSettings)
{
  CDmeModel **v3; // eax

  if ( CDmeModel::s_ModelStack.m_Size >= CDmeModel::s_ModelStack.m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&CDmeModel::s_ModelStack,
      num: 1);
  CDmeModel::s_ModelStack.m_pElements = CDmeModel::s_ModelStack.m_Memory.m_pMemory;
  v3 = &CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size++];
  if ( v3 != nullptr )
    *v3 = this;
  CDmeDag::Draw(this, pDrawSettings);
  --CDmeModel::s_ModelStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004EF6F0
// Name: private: enum CDmeModel::SetupBoneRetval_t CDmeModel::SetupBoneMatrixState(struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::SetupBoneMatrixState(
        CDmeModel *this,
        const matrix3x4_t *shapeToWorld,
        bool bForceSoftwareSkin)
{
  int m_Size; // edi
  bool v6; // zf
  CDmeTransformList *BaseState; // ebx
  int v8; // edi
  CDmeDag *Child; // eax
  matrix3x4_t parentToBindPose; // [esp+8h] [ebp-34h] BYREF
  int nChildCount; // [esp+38h] [ebp-4h]
  bool bSetHardwareState; // [esp+48h] [ebp+Ch]

  m_Size = this->m_JointList.m_Storage.m_Size;
  if ( m_Size <= 0 )
    return 0;
  if ( m_Size > g_pMaterialSystemHardwareConfig->MaxVertexShaderBlendMatrices(this: g_pMaterialSystemHardwareConfig)
    || (v6 = !bForceSoftwareSkin, bSetHardwareState = true, !v6) )
  {
    bSetHardwareState = false;
  }
  if ( s_PoseToWorld.m_Size < m_Size )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: m_Size - s_PoseToWorld.m_Size);
  BaseState = CDmeModel::FindBaseState(this, pBaseStateName: "bind");
  SetIdentityMatrix(matrix: &parentToBindPose);
  v8 = 0;
  nChildCount = CDmElementFramework::GetPhase(this);
  if ( nChildCount > 0 )
  {
    do
    {
      Child = CDmeDag::GetChild(this, i: v8);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this,
          a2: (int)this,
          pJoint: Child,
          pBindPose: BaseState,
          parentToWorld: shapeToWorld,
          &parentToBindPose,
          bSetHardwareState);
      ++v8;
    }
    while ( v8 < nChildCount );
  }
  return bSetHardwareState + 1;
}

//------------------------------------------------------------------------------
// Address: 0x004EF7B0
// Name: private: static struct matrix3x4_t __near * CDmeModel::SetupModelRenderState(struct matrix3x4_t const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__cdecl CDmeModel::SetupModelRenderState(
        const matrix3x4_t *shapeToWorld,
        bool bHasSkinningData,
        bool bForceSoftwareSkin)
{
  IMatRenderContext *v3; // esi
  int v4; // eax
  matrix3x4_t *m_pMemory; // edi
  matrix3x4_t *v7; // edi

  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( bHasSkinningData && CDmeModel::s_ModelStack.m_Size > 0 )
  {
    v4 = CDmeModel::SetupBoneMatrixState(
           this: CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size - 1],
           shapeToWorld,
           bForceSoftwareSkin);
    if ( v4 == 1 )
    {
      v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
      v3->LoadIdentity(this: v3);
      m_pMemory = s_PoseToWorld.m_Memory.m_pMemory;
      v3->EndRender(this: v3);
      v3->Release(this: v3);
      return m_pMemory;
    }
    if ( v4 != 0 )
    {
      if ( v3 != nullptr )
      {
        v3->EndRender(this: v3);
        v3->Release(this: v3);
        return nullptr;
      }
      return nullptr;
    }
  }
  if ( !bForceSoftwareSkin )
  {
    v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
    v3->LoadMatrix(this: v3, a2: shapeToWorld);
    v3->EndRender(this: v3);
    v3->Release(this: v3);
    return nullptr;
  }
  v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
  v3->LoadIdentity(this: v3);
  if ( s_PoseToWorld.m_Size < 1 )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: 1 - s_PoseToWorld.m_Size);
  MatrixCopy(in: shapeToWorld, out: s_PoseToWorld.m_Memory.m_pMemory);
  v7 = s_PoseToWorld.m_Memory.m_pMemory;
  v3->EndRender(this: v3);
  v3->Release(this: v3);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x004EF950
// Name: protected: CDmeModel::CDmeModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeModel *__thiscall CDmeModel::CDmeModel(
        CDmeModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeModel_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeModel_vtbl *)&CDmeModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_JointList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_BaseStates);
  this->m_UpAxis.m_Storage.u.m_Id = -1;
  this->m_UpAxis.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004EF9E0
// Name: public: virtual bool CDmeModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeModel::IsA(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EFA10
// Name: public: virtual int CDmeModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetInheritanceDepth(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EFA70
// Name: protected: virtual void CDmeModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::PerformConstruction(CDmeModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E8310
// Name: _dynamic_initializer_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeModel::s_Allocator,
    blockSize: 200,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8370
// Name: _dynamic_initializer_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_ModelStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__);
}

//------------------------------------------------------------------------------
// Address: 0x005ECC00
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ECC10
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmeModel::s_ModelStack);
}

//------------------------------------------------------------------------------
// Address: 0x005E8340
// Name: _dynamic_initializer_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8350
// Name: _dynamic_initializer_for__g_CDmeModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeModel_Helper,
           classname: "DmeModel",
           pFactory: &g_CDmeModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E8380
// Name: _dynamic_initializer_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_PoseToWorld__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_PoseToWorld__);
}

//------------------------------------------------------------------------------
// Address: 0x005ECC20
// Name: _dynamic_atexit_destructor_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_PoseToWorld__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_PoseToWorld);
}

//------------------------------------------------------------------------------
// Address: 0x005ECC30
// Name: _dynamic_atexit_destructor_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeModel_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeModel_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0047C650
// Name: protected: void CDmeModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::OnConstruction(CDmeModel *this)
{
  CDmaElementArray<CDmeDag> *p_m_JointList; // edi
  CDmAttribute *v3; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  p_m_JointList = &this->m_JointList;
  this->m_JointList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "jointList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_JointList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_JointList->m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_BaseStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "baseStates",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_BaseStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BaseStates.m_pAttribute, typeSymbol: CDmeTransformList::m_classType);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "Y");
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "upAxis", type: AT_STRING, pMemory: &this->m_UpAxis);
  this->m_UpAxis.m_pAttribute = v3;
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0047C6F0
// Name: private: static void CDmeModel::CleanupModelRenderState(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmeModel::CleanupModelRenderState()
{
  IMatRenderContext *v0; // esi

  v0 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v0 != nullptr )
    v0->BeginRender(this: v0);
  v0->MatrixMode(this: v0, a2: MATERIAL_MODEL);
  v0->LoadIdentity(this: v0);
  v0->EndRender(this: v0);
  v0->Release(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x0047C7C0
// Name: public: class CDmeTransform __near * CDmeTransformList::GetTransform(int)
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeTransformList::GetTransform(CDmeTransformList *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transforms.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeTransform::m_classType) )
    return (CDmeTransform *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0047C810
// Name: public: int CDmeModel::GetJointIndex(class CDmeDag __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetJointIndex(CDmeModel *this, CDmeDag *pJoint)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmeDag *v5; // esi
  int nJointCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nJointCount = this->m_JointList.m_Storage.m_Size;
  if ( nJointCount <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeDag *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeDag::m_classType) )
      v5 = nullptr;
    if ( pJoint == v5 )
      break;
    if ( ++v3 >= nJointCount )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0047C890
// Name: public: class CDmeTransformList __near * CDmeModel::FindBaseState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformList *__thiscall CDmeModel::FindBaseState(CDmeModel *this, const char *pBaseStateName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char *m_pAsString; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_BaseStates.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeTransformList::m_classType) )
      v5 = nullptr;
    m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = Ptr;
    if ( _V_stricmp(s1: m_pAsString, s2: pBaseStateName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
  v9 = v8;
  if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeTransformList::m_classType) )
    return (CDmeTransformList *)v9;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0047C960
// Name: private: void CDmeModel::LoadJointTransform(class CDmeDag __near *,class CDmeTransformList __near *,struct matrix3x4_t const __near &,struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeModel::LoadJointTransform(
        CDmeModel *this@<ecx>,
        int a2@<esi>,
        CDmeDag *pJoint,
        CDmeTransformList *pBindPose,
        const matrix3x4_t *parentToWorld,
        const matrix3x4_t *parentToBindPose,
        bool bSetHardwareState)
{
  int JointIndex; // edi
  CDmeTransform *Transform; // eax
  CDmeTransform *v9; // eax
  int v10; // eax
  int v11; // esi
  int Phase; // edi
  int i; // esi
  CDmeDag *Child; // eax
  matrix3x4_t bindPoseToJoint; // [esp+8h] [ebp-124h] BYREF
  matrix3x4_t jointToParent; // [esp+38h] [ebp-F4h] BYREF
  matrix3x4_t jointToWorld; // [esp+68h] [ebp-C4h] BYREF
  matrix3x4_t bindJointToParent; // [esp+98h] [ebp-94h] BYREF
  matrix3x4_t jointToBindPose; // [esp+C8h] [ebp-64h] BYREF
  matrix3x4_t bindPoseToWorld; // [esp+F8h] [ebp-34h] BYREF
  CDmeModel *v21; // [esp+128h] [ebp-4h]

  v21 = this;
  JointIndex = CDmeModel::GetJointIndex(this, pJoint);
  if ( JointIndex >= 0 )
  {
    Transform = CDmeDag::GetTransform(this: pJoint);
    CDmeTransform::GetTransform(this: Transform, transform: &jointToParent);
    ConcatTransforms(in1: parentToWorld, in2: &jointToParent, out: &jointToWorld);
    if ( pBindPose != nullptr )
    {
      if ( JointIndex >= pBindPose->m_Transforms.m_Storage.m_Size )
      {
        _Warning(
          a1: "Model is in an invalid state! There are different numbers of bones in the bind pose and joint transform list!\n");
        return;
      }
      v9 = CDmeTransformList::GetTransform(this: pBindPose, nIndex: JointIndex);
      CDmeTransform::GetTransform(this: v9, transform: &bindJointToParent);
    }
    else
    {
      MatrixCopy(in: &jointToParent, out: &bindJointToParent);
    }
    ConcatTransforms(in1: parentToBindPose, in2: &bindJointToParent, out: &jointToBindPose);
    MatrixInvert(in: &jointToBindPose, out: &bindPoseToJoint);
    ConcatTransforms(in1: &jointToWorld, in2: &bindPoseToJoint, out: &bindPoseToWorld);
    if ( bSetHardwareState )
    {
      v10 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
      v11 = v10;
      if ( v10 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 424))(a1: v11, a2: JointIndex);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 4))(a1: v11);
    }
    MatrixCopy(in: &bindPoseToWorld, out: &s_PoseToWorld.m_Memory.m_pMemory[JointIndex]);
    Phase = CDmElementFramework::GetPhase(this: pJoint);
    for ( i = 0; i < Phase; ++i )
    {
      Child = CDmeDag::GetChild(this: pJoint, i);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this: v21,
          pJoint: Child,
          pBindPose,
          parentToWorld: &jointToWorld,
          parentToBindPose: &jointToBindPose,
          bSetHardwareState);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047CAF0
// Name: public: virtual void CDmeModel::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::Draw(CDmeModel *this, CDmeDrawSettings *pDrawSettings)
{
  CDmeModel **v3; // eax

  if ( CDmeModel::s_ModelStack.m_Size >= CDmeModel::s_ModelStack.m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&CDmeModel::s_ModelStack,
      num: 1);
  CDmeModel::s_ModelStack.m_pElements = CDmeModel::s_ModelStack.m_Memory.m_pMemory;
  v3 = &CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size++];
  if ( v3 != nullptr )
    *v3 = this;
  CDmeDag::Draw(this, pDrawSettings);
  --CDmeModel::s_ModelStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0047CB50
// Name: private: enum CDmeModel::SetupBoneRetval_t CDmeModel::SetupBoneMatrixState(struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::SetupBoneMatrixState(
        CDmeModel *this,
        const matrix3x4_t *shapeToWorld,
        bool bForceSoftwareSkin)
{
  int m_Size; // edi
  bool v6; // zf
  CDmeTransformList *BaseState; // ebx
  int v8; // edi
  CDmeDag *Child; // eax
  matrix3x4_t parentToBindPose; // [esp+8h] [ebp-34h] BYREF
  int nChildCount; // [esp+38h] [ebp-4h]
  bool bSetHardwareState; // [esp+48h] [ebp+Ch]

  m_Size = this->m_JointList.m_Storage.m_Size;
  if ( m_Size <= 0 )
    return 0;
  if ( m_Size > g_pMaterialSystemHardwareConfig->MaxVertexShaderBlendMatrices(this: g_pMaterialSystemHardwareConfig)
    || (v6 = !bForceSoftwareSkin, bSetHardwareState = true, !v6) )
  {
    bSetHardwareState = false;
  }
  if ( s_PoseToWorld.m_Size < m_Size )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: m_Size - s_PoseToWorld.m_Size);
  BaseState = CDmeModel::FindBaseState(this, pBaseStateName: "bind");
  SetIdentityMatrix(matrix: &parentToBindPose);
  v8 = 0;
  nChildCount = CDmElementFramework::GetPhase(this);
  if ( nChildCount > 0 )
  {
    do
    {
      Child = CDmeDag::GetChild(this, i: v8);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this,
          a2: (int)this,
          pJoint: Child,
          pBindPose: BaseState,
          parentToWorld: shapeToWorld,
          &parentToBindPose,
          bSetHardwareState);
      ++v8;
    }
    while ( v8 < nChildCount );
  }
  return bSetHardwareState + 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047CC10
// Name: private: static struct matrix3x4_t __near * CDmeModel::SetupModelRenderState(struct matrix3x4_t const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__cdecl CDmeModel::SetupModelRenderState(
        const matrix3x4_t *shapeToWorld,
        bool bHasSkinningData,
        bool bForceSoftwareSkin)
{
  IMatRenderContext *v3; // esi
  int v4; // eax
  matrix3x4_t *m_pMemory; // edi
  matrix3x4_t *v7; // edi

  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( bHasSkinningData && CDmeModel::s_ModelStack.m_Size > 0 )
  {
    v4 = CDmeModel::SetupBoneMatrixState(
           this: CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size - 1],
           shapeToWorld,
           bForceSoftwareSkin);
    if ( v4 == 1 )
    {
      v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
      v3->LoadIdentity(this: v3);
      m_pMemory = s_PoseToWorld.m_Memory.m_pMemory;
      v3->EndRender(this: v3);
      v3->Release(this: v3);
      return m_pMemory;
    }
    if ( v4 != 0 )
    {
      if ( v3 != nullptr )
      {
        v3->EndRender(this: v3);
        v3->Release(this: v3);
        return nullptr;
      }
      return nullptr;
    }
  }
  if ( !bForceSoftwareSkin )
  {
    v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
    v3->LoadMatrix(this: v3, a2: shapeToWorld);
    v3->EndRender(this: v3);
    v3->Release(this: v3);
    return nullptr;
  }
  v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
  v3->LoadIdentity(this: v3);
  if ( s_PoseToWorld.m_Size < 1 )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: 1 - s_PoseToWorld.m_Size);
  MatrixCopy(in: shapeToWorld, out: s_PoseToWorld.m_Memory.m_pMemory);
  v7 = s_PoseToWorld.m_Memory.m_pMemory;
  v3->EndRender(this: v3);
  v3->Release(this: v3);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x0047CDB0
// Name: protected: CDmeModel::CDmeModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeModel *__thiscall CDmeModel::CDmeModel(
        CDmeModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeModel_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeModel_vtbl *)&CDmeModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_JointList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_BaseStates);
  this->m_UpAxis.m_Storage.u.m_Id = -1;
  this->m_UpAxis.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047CE40
// Name: public: virtual bool CDmeModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeModel::IsA(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047CE70
// Name: public: virtual int CDmeModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetInheritanceDepth(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047CEC0
// Name: protected: virtual void CDmeModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::PerformConstruction(CDmeModel *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDag::OnConstruction(this);
  CDmeModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00579490
// Name: _dynamic_initializer_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeModel::s_Allocator,
    blockSize: 200,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005794F0
// Name: _dynamic_initializer_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_ModelStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__);
}

//------------------------------------------------------------------------------
// Address: 0x005796F0
// Name: _dynamic_initializer_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D7F0
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057D800
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmeModel::s_ModelStack);
}

//------------------------------------------------------------------------------
// Address: 0x0057D910
// Name: _dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005794C0
// Name: _dynamic_initializer_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005794D0
// Name: _dynamic_initializer_for__g_CDmeModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeModel_Helper,
           classname: "DmeModel",
           pFactory: &g_CDmeModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579500
// Name: _dynamic_initializer_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_PoseToWorld__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_PoseToWorld__);
}

//------------------------------------------------------------------------------
// Address: 0x00579720
// Name: _dynamic_initializer_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579730
// Name: _dynamic_initializer_for__g_CDmeTransformList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformList_Helper,
           classname: "DmeTransformList",
           pFactory: &g_CDmeTransformList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057D810
// Name: _dynamic_atexit_destructor_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_PoseToWorld__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_PoseToWorld);
}

//------------------------------------------------------------------------------
// Address: 0x0057D820
// Name: _dynamic_atexit_destructor_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeModel_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057D920
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformList_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00580BD0
// Name: protected: void CDmeModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::OnConstruction(CDmeModel *this)
{
  CDmaElementArray<CDmeDag> *p_m_JointList; // edi
  CDmAttribute *v3; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  p_m_JointList = &this->m_JointList;
  this->m_JointList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "jointList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_JointList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_JointList->m_pAttribute, typeSymbol: CDmeDag::m_classType);
  this->m_BaseStates.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "baseStates",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_BaseStates);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BaseStates.m_pAttribute, typeSymbol: CDmeTransformList::m_classType);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "Y");
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "upAxis", type: AT_STRING, pMemory: &this->m_UpAxis);
  this->m_UpAxis.m_pAttribute = v3;
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00580C70
// Name: private: static void CDmeModel::CleanupModelRenderState(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmeModel::CleanupModelRenderState()
{
  IMatRenderContext *v0; // esi

  v0 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v0 != nullptr )
    v0->BeginRender(this: v0);
  v0->MatrixMode(this: v0, a2: MATERIAL_MODEL);
  v0->LoadIdentity(this: v0);
  v0->EndRender(this: v0);
  v0->Release(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x00580D40
// Name: public: class CDmeTransform __near * CDmeTransformList::GetTransform(int)
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeTransformList::GetTransform(CDmeTransformList *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Transforms.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeTransform::m_classType) )
    return (CDmeTransform *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00580D90
// Name: public: int CDmeModel::GetJointIndex(class CDmeDag __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetJointIndex(CDmeModel *this, CDmeDag *pJoint)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmeDag *v5; // esi
  int nJointCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nJointCount = this->m_JointList.m_Storage.m_Size;
  if ( nJointCount <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeDag *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeDag::m_classType) )
      v5 = nullptr;
    if ( pJoint == v5 )
      break;
    if ( ++v3 >= nJointCount )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00580E10
// Name: public: class CDmeTransformList __near * CDmeModel::FindBaseState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeTransformList *__thiscall CDmeModel::FindBaseState(CDmeModel *this, const char *pBaseStateName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char *m_pAsString; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_BaseStates.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeTransformList::m_classType) )
      v5 = nullptr;
    m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    if ( _V_stricmp(s1: m_pAsString, s2: pBaseStateName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_BaseStates.m_Storage.m_Memory.m_pMemory[v3]);
  v9 = v8;
  if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmeTransformList::m_classType) )
    return (CDmeTransformList *)v9;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00580EE0
// Name: public: void CDmeModel::CaptureJointsToBaseState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::CaptureJointsToBaseState(CDmeModel *this, const char *pBaseStateName)
{
  CDmeTransformList *BaseState; // eax
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmeTransformList *v6; // esi
  CDmeTransformList *v7; // ecx
  int m_Size; // esi
  int v9; // ecx
  DmFileId_t m_fileId; // edi
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  const char *m_pAsString; // eax
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CVTFTexture *v16; // esi
  int v17; // edi
  CDmElement *v18; // eax
  CDmeDag *v19; // esi
  const char *v20; // eax
  CDmeTransform *Transform; // eax
  const char *v22; // esi
  const char *Name; // eax
  matrix3x4_t mat; // [esp+Ch] [ebp-94h] BYREF
  char pBuf[40]; // [esp+3Ch] [ebp-64h] BYREF
  char szTmpBuf1[40]; // [esp+64h] [ebp-3Ch] BYREF
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *p_m_Transforms; // [esp+8Ch] [ebp-14h]
  DmElementHandle_t src; // [esp+90h] [ebp-10h] BYREF
  int i; // [esp+94h] [ebp-Ch]
  CDmeTransformList *pTransformList; // [esp+98h] [ebp-8h]
  int nJointCount; // [esp+9Ch] [ebp-4h] BYREF

  BaseState = CDmeModel::FindBaseState(this, pBaseStateName);
  pTransformList = BaseState;
  if ( BaseState == nullptr )
  {
    v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmeTransformList::m_classType.u.m_Id,
           a3: pBaseStateName,
           a4: this->m_fileId,
           a5: nullptr);
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    v6 = (CDmeTransformList *)v5;
    if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeTransformList::m_classType) )
      v7 = v6;
    else
      v7 = nullptr;
    pTransformList = v7;
    if ( v7 != nullptr )
      nJointCount = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)v7);
    else
      nJointCount = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_BaseStates,
      src: (DmElementHandle_t *)&nJointCount);
    BaseState = pTransformList;
  }
  m_Size = this->m_JointList.m_Storage.m_Size;
  v9 = BaseState->m_Transforms.m_Storage.m_Size;
  nJointCount = m_Size;
  if ( m_Size <= v9 )
  {
    if ( m_Size < v9 )
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveMultiple(
        this: &BaseState->m_Transforms,
        elem: m_Size,
        num: v9 - m_Size);
  }
  else
  {
    i = v9;
    p_m_Transforms = &BaseState->m_Transforms;
    while ( 1 )
    {
      m_fileId = BaseState->m_fileId;
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[i]);
      v12 = v11;
      if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmeDag::m_classType) )
        v12 = nullptr;
      m_pAsString = v12->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      v14 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
              a1: g_pDataModel,
              a2: (CUtlSymbolLarge)CDmeTransform::m_classType.u.m_Id,
              a3: m_pAsString,
              a4: m_fileId,
              a5: nullptr);
      v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
      v16 = (CVTFTexture *)v15;
      if ( v15 != nullptr && v15->IsA(this: v15, a2: CDmeTransform::m_classType) )
        src = CCoreDispNode::GetCenterVertIndex(this: v16);
      else
        src = DMELEMENT_HANDLE_INVALID;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: p_m_Transforms,
        &src);
      if ( ++i >= nJointCount )
        break;
      BaseState = pTransformList;
    }
    m_Size = nJointCount;
  }
  v17 = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v18 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_JointList.m_Storage.m_Memory.m_pMemory[v17]);
      v19 = (CDmeDag *)v18;
      if ( v18 != nullptr && v18->IsA(this: v18, a2: CDmeDag::m_classType) )
      {
        Transform = CDmeDag::GetTransform(this: v19);
        if ( Transform != nullptr )
        {
          CDmeTransform::GetTransform(this: Transform, transform: &mat);
          CDmeTransformList::SetTransform(this: pTransformList, nIndex: v17, &mat);
        }
        else
        {
          UniqueIdToString(id: &this->m_Id, pBuf, nMaxLen: 38);
          UniqueIdToString(id: &v19->m_Id, pBuf: szTmpBuf1, nMaxLen: 38);
          v22 = v19->m_Name.m_Storage.u.m_pAsString;
          if ( v22 == (const char *)-1 )
            v22 = var;
          Name = CDmElement::GetName(this);
          _Warning(
            a1: "DmeModel::CaptureJointsToBaseState( %s ) - DmeModel %s[%s].jointList[ %d ].transform ( %s[%s].transform ) is NULL\n",
            pBaseStateName,
            Name,
            pBuf,
            v17,
            v22,
            szTmpBuf1);
        }
      }
      else
      {
        UniqueIdToString(id: &this->m_Id, pBuf: szTmpBuf1, nMaxLen: 38);
        v20 = CDmElement::GetName(this);
        _Warning(
          a1: "DmeModel::CaptureJointsToBaseState( %s ): DmeModel %s[%s].jointList[ %d ] is NULL\n",
          pBaseStateName,
          v20,
          szTmpBuf1,
          v17);
      }
      ++v17;
    }
    while ( v17 < nJointCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00581190
// Name: private: void CDmeModel::LoadJointTransform(class CDmeDag __near *,class CDmeTransformList __near *,struct matrix3x4_t const __near &,struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeModel::LoadJointTransform(
        CDmeModel *this@<ecx>,
        int a2@<esi>,
        CDmeDag *pJoint,
        CDmeTransformList *pBindPose,
        const matrix3x4_t *parentToWorld,
        const matrix3x4_t *parentToBindPose,
        bool bSetHardwareState)
{
  int JointIndex; // edi
  CDmeTransform *Transform; // eax
  CDmeTransform *v9; // eax
  int v10; // eax
  int v11; // esi
  int Phase; // edi
  int i; // esi
  CDmeDag *Child; // eax
  matrix3x4_t bindPoseToJoint; // [esp+8h] [ebp-124h] BYREF
  matrix3x4_t jointToParent; // [esp+38h] [ebp-F4h] BYREF
  matrix3x4_t jointToWorld; // [esp+68h] [ebp-C4h] BYREF
  matrix3x4_t bindJointToParent; // [esp+98h] [ebp-94h] BYREF
  matrix3x4_t jointToBindPose; // [esp+C8h] [ebp-64h] BYREF
  matrix3x4_t bindPoseToWorld; // [esp+F8h] [ebp-34h] BYREF
  CDmeModel *v21; // [esp+128h] [ebp-4h]

  v21 = this;
  JointIndex = CDmeModel::GetJointIndex(this, pJoint);
  if ( JointIndex >= 0 )
  {
    Transform = CDmeDag::GetTransform(this: pJoint);
    CDmeTransform::GetTransform(this: Transform, transform: &jointToParent);
    ConcatTransforms(in1: parentToWorld, in2: &jointToParent, out: &jointToWorld);
    if ( pBindPose != nullptr )
    {
      if ( JointIndex >= pBindPose->m_Transforms.m_Storage.m_Size )
      {
        _Warning(
          a1: "Model is in an invalid state! There are different numbers of bones in the bind pose and joint transform list!\n");
        return;
      }
      v9 = CDmeTransformList::GetTransform(this: pBindPose, nIndex: JointIndex);
      CDmeTransform::GetTransform(this: v9, transform: &bindJointToParent);
    }
    else
    {
      MatrixCopy(in: &jointToParent, out: &bindJointToParent);
    }
    ConcatTransforms(in1: parentToBindPose, in2: &bindJointToParent, out: &jointToBindPose);
    MatrixInvert(in: &jointToBindPose, out: &bindPoseToJoint);
    ConcatTransforms(in1: &jointToWorld, in2: &bindPoseToJoint, out: &bindPoseToWorld);
    if ( bSetHardwareState )
    {
      v10 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
      v11 = v10;
      if ( v10 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v11 + 424))(a1: v11, a2: JointIndex);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 4))(a1: v11);
    }
    MatrixCopy(in: &bindPoseToWorld, out: &s_PoseToWorld.m_Memory.m_pMemory[JointIndex]);
    Phase = CDmElementFramework::GetPhase(this: pJoint);
    for ( i = 0; i < Phase; ++i )
    {
      Child = CDmeDag::GetChild(this: pJoint, i);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this: v21,
          pJoint: Child,
          pBindPose,
          parentToWorld: &jointToWorld,
          parentToBindPose: &jointToBindPose,
          bSetHardwareState);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00581320
// Name: public: int CDmeModel::AddJoint(class CDmeDag __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::AddJoint(CDmeModel *this, int pJoint)
{
  CVTFTexture *v2; // edi
  int result; // eax

  v2 = (CVTFTexture *)pJoint;
  result = CDmeModel::GetJointIndex(this, (CDmeDag *)pJoint);
  if ( result < 0 )
  {
    if ( v2 != nullptr )
      pJoint = CCoreDispNode::GetCenterVertIndex(this: v2);
    else
      pJoint = -1;
    return CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
             this: &this->m_JointList,
             src: (DmElementHandle_t *)&pJoint);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00581360
// Name: public: virtual void CDmeModel::Draw(class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::Draw(CDmeModel *this, CDmeDrawSettings *pDrawSettings)
{
  CDmeModel **v3; // eax

  if ( CDmeModel::s_ModelStack.m_Size >= CDmeModel::s_ModelStack.m_Memory.m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&CDmeModel::s_ModelStack, num: 1);
  CDmeModel::s_ModelStack.m_pElements = CDmeModel::s_ModelStack.m_Memory.m_pMemory;
  v3 = &CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size++];
  if ( v3 != nullptr )
    *v3 = this;
  CDmeDag::Draw(this, pDrawSettings);
  --CDmeModel::s_ModelStack.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x005813C0
// Name: private: enum CDmeModel::SetupBoneRetval_t CDmeModel::SetupBoneMatrixState(struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::SetupBoneMatrixState(
        CDmeModel *this,
        const matrix3x4_t *shapeToWorld,
        bool bForceSoftwareSkin)
{
  int m_Size; // edi
  bool v6; // zf
  CDmeTransformList *BaseState; // ebx
  int v8; // edi
  CDmeDag *Child; // eax
  matrix3x4_t parentToBindPose; // [esp+8h] [ebp-34h] BYREF
  int nChildCount; // [esp+38h] [ebp-4h]
  bool bSetHardwareState; // [esp+48h] [ebp+Ch]

  m_Size = this->m_JointList.m_Storage.m_Size;
  if ( m_Size <= 0 )
    return 0;
  if ( m_Size > g_pMaterialSystemHardwareConfig->MaxVertexShaderBlendMatrices(this: g_pMaterialSystemHardwareConfig)
    || (v6 = !bForceSoftwareSkin, bSetHardwareState = true, !v6) )
  {
    bSetHardwareState = false;
  }
  if ( s_PoseToWorld.m_Size < m_Size )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: m_Size - s_PoseToWorld.m_Size);
  BaseState = CDmeModel::FindBaseState(this, pBaseStateName: "bind");
  SetIdentityMatrix(matrix: &parentToBindPose);
  v8 = 0;
  nChildCount = CDmElementFramework::GetPhase(this);
  if ( nChildCount > 0 )
  {
    do
    {
      Child = CDmeDag::GetChild(this, i: v8);
      if ( Child != nullptr )
        CDmeModel::LoadJointTransform(
          this,
          a2: (int)this,
          pJoint: Child,
          pBindPose: BaseState,
          parentToWorld: shapeToWorld,
          &parentToBindPose,
          bSetHardwareState);
      ++v8;
    }
    while ( v8 < nChildCount );
  }
  return bSetHardwareState + 1;
}

//------------------------------------------------------------------------------
// Address: 0x00581480
// Name: private: static struct matrix3x4_t __near * CDmeModel::SetupModelRenderState(struct matrix3x4_t const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__cdecl CDmeModel::SetupModelRenderState(
        const matrix3x4_t *shapeToWorld,
        bool bHasSkinningData,
        bool bForceSoftwareSkin)
{
  IMatRenderContext *v3; // esi
  int v4; // eax
  matrix3x4_t *m_pMemory; // edi
  matrix3x4_t *v7; // edi

  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( bHasSkinningData && CDmeModel::s_ModelStack.m_Size > 0 )
  {
    v4 = CDmeModel::SetupBoneMatrixState(
           this: CDmeModel::s_ModelStack.m_Memory.m_pMemory[CDmeModel::s_ModelStack.m_Size - 1],
           shapeToWorld,
           bForceSoftwareSkin);
    if ( v4 == 1 )
    {
      v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
      v3->LoadIdentity(this: v3);
      m_pMemory = s_PoseToWorld.m_Memory.m_pMemory;
      v3->EndRender(this: v3);
      v3->Release(this: v3);
      return m_pMemory;
    }
    if ( v4 != 0 )
    {
      if ( v3 != nullptr )
      {
        v3->EndRender(this: v3);
        v3->Release(this: v3);
        return nullptr;
      }
      return nullptr;
    }
  }
  if ( !bForceSoftwareSkin )
  {
    v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
    v3->LoadMatrix(this: v3, a2: shapeToWorld);
    v3->EndRender(this: v3);
    v3->Release(this: v3);
    return nullptr;
  }
  v3->MatrixMode(this: v3, a2: MATERIAL_MODEL);
  v3->LoadIdentity(this: v3);
  if ( s_PoseToWorld.m_Size < 1 )
    CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertMultipleBefore(
      this: &s_PoseToWorld,
      elem: s_PoseToWorld.m_Size,
      num: 1 - s_PoseToWorld.m_Size);
  MatrixCopy(in: shapeToWorld, out: s_PoseToWorld.m_Memory.m_pMemory);
  v7 = s_PoseToWorld.m_Memory.m_pMemory;
  v3->EndRender(this: v3);
  v3->Release(this: v3);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00581620
// Name: protected: CDmeModel::CDmeModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeModel *__thiscall CDmeModel::CDmeModel(
        CDmeModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeModel_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeModel_vtbl *)&CDmeModel::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_JointList);
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_BaseStates);
  this->m_UpAxis.m_Storage.u.m_Id = -1;
  this->m_UpAxis.m_pAttribute = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005816B0
// Name: public: virtual bool CDmeModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeModel::IsA(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005816E0
// Name: public: virtual int CDmeModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeModel::GetInheritanceDepth(CDmeModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeModel::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00581730
// Name: protected: virtual void CDmeModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeModel::PerformConstruction(CDmeModel *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDag::OnConstruction(this);
  CDmeModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B7290
// Name: _dynamic_initializer_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformList::s_Allocator,
    blockSize: 0x60u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7640
// Name: _dynamic_initializer_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeModel::s_Allocator,
    blockSize: 0xC8u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B76A0
// Name: _dynamic_initializer_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeModel::s_ModelStack__()
{
  return atexit(func: dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__);
}

//------------------------------------------------------------------------------
// Address: 0x006BC580
// Name: _dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC710
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC720
// Name: _dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeModel::s_ModelStack__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&CDmeModel::s_ModelStack);
}

//------------------------------------------------------------------------------
// Address: 0x006B72C0
// Name: _dynamic_initializer_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B72D0
// Name: _dynamic_initializer_for__g_CDmeTransformList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformList_Helper,
           classname: "DmeTransformList",
           pFactory: &g_CDmeTransformList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B7670
// Name: _dynamic_initializer_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7680
// Name: _dynamic_initializer_for__g_CDmeModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeModel_Helper,
           classname: "DmeModel",
           pFactory: &g_CDmeModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B76B0
// Name: _dynamic_initializer_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_PoseToWorld__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_PoseToWorld__);
}

//------------------------------------------------------------------------------
// Address: 0x006BC590
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTransformList_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC730
// Name: _dynamic_atexit_destructor_for__s_PoseToWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_PoseToWorld__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_PoseToWorld);
}

//------------------------------------------------------------------------------
// Address: 0x006BC740
// Name: _dynamic_atexit_destructor_for__g_CDmeModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeModel_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeModel_Factory.m_CallBackList);
}

} // namespace vmap
