// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/graphicgroup.cpp
// Functions: 23
// ============================================================

#include "vgui2\game_controls\graphicgroup.h"

//------------------------------------------------------------------------------
// Address: 0x00420610
// Name: public: virtual void CGraphicGroup::GetRenderTransform(struct matrix3x4_t __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphicGroup::GetRenderTransform(
        CGraphicGroup *this,
        matrix3x4_t *relToScreen,
        bool bMaintainAspectRatio)
{
  __int64 v3; // xmm0_8

  if ( bMaintainAspectRatio )
  {
    *(_QWORD *)&relToScreen->m_flMatVal[0][0] = *(_QWORD *)&this->m_RelToScreenHoldAspectRatio.m_flMatVal[0][0];
    *(_QWORD *)&relToScreen->m_flMatVal[0][2] = *(_QWORD *)&this->m_RelToScreenHoldAspectRatio.m_flMatVal[0][2];
    *(_OWORD *)&relToScreen->m_flMatVal[1][0] = *(_OWORD *)&this->m_RelToScreenHoldAspectRatio.m_flMatVal[1][0];
    *(_QWORD *)&relToScreen->m_flMatVal[2][0] = *(_QWORD *)&this->m_RelToScreenHoldAspectRatio.m_flMatVal[2][0];
    v3 = *(_QWORD *)&this->m_RelToScreenHoldAspectRatio.m_flMatVal[2][2];
  }
  else
  {
    *(_QWORD *)&relToScreen->m_flMatVal[0][0] = *(_QWORD *)&this->m_Geometry.m_RenderToScreen.m_flMatVal[0][0];
    *(_QWORD *)&relToScreen->m_flMatVal[0][2] = *(_QWORD *)&this->m_Geometry.m_RenderToScreen.m_flMatVal[0][2];
    *(_OWORD *)&relToScreen->m_flMatVal[1][0] = *(_OWORD *)&this->m_Geometry.m_RenderToScreen.m_flMatVal[1][0];
    *(_QWORD *)&relToScreen->m_flMatVal[2][0] = *(_QWORD *)&this->m_Geometry.m_RenderToScreen.m_flMatVal[2][0];
    v3 = *(_QWORD *)&this->m_Geometry.m_RenderToScreen.m_flMatVal[2][2];
  }
  *(_QWORD *)&relToScreen->m_flMatVal[2][2] = v3;
}

//------------------------------------------------------------------------------
// Address: 0x004206C0
// Name: public: virtual bool CGraphicGroup::MaintainAspectRatio(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGraphicGroup::MaintainAspectRatio(CGraphicGroup *this)
{
  if ( this->m_pGroup == nullptr || this->m_Geometry.m_bMaintainAspectRatio )
    return this->m_Geometry.m_bMaintainAspectRatio;
  else
    return this->m_pGroup->MaintainAspectRatio(this: this->m_pGroup);
}

//------------------------------------------------------------------------------
// Address: 0x004206E0
// Name: public: virtual void CGraphicGroup::UpdateGeometry(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphicGroup::UpdateGeometry(CGraphicGroup *this)
{
  int i; // edi
  CGameGraphic *v3; // ecx
  DmeTime_t result; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_CurrentState != -1 )
  {
    CGameGraphic::GetAnimationTimePassed(this, &result);
    CTypedLog<color32_s>::GetValue(
      this: &this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState]->m_ColorAnim,
      time: result,
      pOutValue: &this->m_Geometry.m_Color);
    CTypedLog<Vector2D>::GetValue(
      this: &this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState]->m_CenterPosAnim,
      time: result,
      pOutValue: &this->m_Geometry.m_Center);
    CTypedLog<Vector2D>::GetValue(
      this: &this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState]->m_ScaleAnim,
      time: result,
      pOutValue: &this->m_Geometry.m_Scale);
    CTypedLog<float>::GetValue(
      this: &this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState]->m_RotationAnim,
      time: result,
      pOutValue: &this->m_Geometry.m_Rotation);
    for ( i = 0; i < this->m_MemberList.m_Size; ++i )
    {
      v3 = this->m_MemberList.m_Memory.m_pMemory[i];
      v3->UpdateGeometry(this: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004207B0
// Name: public: void CGraphicGroup::UpdateRenderData(struct color32_s)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphicGroup::UpdateRenderData(CGraphicGroup *this, unsigned int parentColor)
{
  float v3; // xmm1_4
  float v4; // xmm1_4
  float v5; // xmm1_4
  int v6; // ecx
  float v7; // xmm0_4
  float a; // xmm1_4
  int v9; // edi
  bool v10; // cc
  CGameGraphic *v11; // ecx

  if ( this->m_Geometry.m_bVisible )
  {
    v3 = (double)(unsigned __int8)parentColor * 0.00392156862745098;
    this->m_ResultantColor.r = (int)(float)(v3 * (float)this->m_Geometry.m_Color.r);
    v4 = (double)BYTE1(parentColor) * 0.00392156862745098;
    this->m_ResultantColor.g = (int)(float)(v4 * (float)this->m_Geometry.m_Color.g);
    v5 = (double)BYTE2(parentColor) * 0.00392156862745098;
    v6 = (int)(float)(v5 * (float)this->m_Geometry.m_Color.b);
    v7 = (double)HIBYTE(parentColor) * 0.00392156862745098;
    a = (float)this->m_Geometry.m_Color.a;
    v9 = 0;
    v10 = this->m_MemberList.m_Size <= 0;
    this->m_ResultantColor.b = v6;
    this->m_ResultantColor.a = (int)(float)(v7 * a);
    if ( !v10 )
    {
      do
      {
        v11 = this->m_MemberList.m_Memory.m_pMemory[v9];
        if ( v11->IsGroup(this: v11) )
          CGraphicGroup::UpdateRenderData(
            this: (CGraphicGroup *)this->m_MemberList.m_Memory.m_pMemory[v9],
            (color32_s)parentColor);
        ++v9;
      }
      while ( v9 < this->m_MemberList.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004208C0
// Name: public: virtual void CGraphicGroup::UpdateRenderTransforms(struct StageRenderInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphicGroup::UpdateRenderTransforms(CGraphicGroup *this, const StageRenderInfo_t *stageRenderInfo)
{
  int i; // edi
  CGameGraphic *v4; // ecx
  float z; // [esp+8h] [ebp-194h]
  Vector axis; // [esp+18h] [ebp-184h] BYREF
  Vector centerVec; // [esp+24h] [ebp-178h] BYREF
  Vector position; // [esp+30h] [ebp-16Ch] BYREF
  Vector centerInScreen; // [esp+3Ch] [ebp-160h] BYREF
  matrix3x4_t transmat; // [esp+48h] [ebp-154h] BYREF
  matrix3x4_t screenScalemat; // [esp+78h] [ebp-124h] BYREF
  matrix3x4_t temp; // [esp+A8h] [ebp-F4h] BYREF
  matrix3x4_t scalemat; // [esp+D8h] [ebp-C4h] BYREF
  matrix3x4_t rawToLocal; // [esp+108h] [ebp-94h] BYREF
  matrix3x4_t rotmat; // [esp+138h] [ebp-64h] BYREF
  matrix3x4_t groupToScreen; // [esp+168h] [ebp-34h] BYREF

  CGeometry::UpdateRenderTransforms(this: &this->m_Geometry, stageRenderInfo, pGroup: this->m_pGroup);
  SetScaleMatrix(
    x: stageRenderInfo->parentScale.x,
    y: stageRenderInfo->parentScale.y,
    z: 1.0,
    dst: (matrix3x4_t *)&screenScalemat.m_flMatVal[0][1]);
  *(Vector2D *)&centerVec.y = this->m_Geometry.m_Center;
  position.x = 0.0;
  VectorTransform(in1: &centerVec.y, in2: (matrix3x4_t *)&screenScalemat.m_flMatVal[0][1], out: &centerInScreen.y);
  position.y = centerInScreen.y;
  position.z = centerInScreen.z;
  centerInScreen.x = 0.0;
  SetIdentityMatrix(matrix: (matrix3x4_t *)&transmat.m_flMatVal[0][1]);
  MatrixSetColumn(in: (Vector *)&position.y, column: 3, out: (matrix3x4_t *)&transmat.m_flMatVal[0][1]);
  SetScaleMatrix(
    x: this->m_Geometry.m_Scale.x,
    y: this->m_Geometry.m_Scale.y,
    z: 1.0,
    dst: (matrix3x4_t *)&scalemat.m_flMatVal[0][1]);
  z = this->m_Geometry.m_Rotation;
  axis.y = 0.0;
  axis.z = 0.0;
  centerVec.x = 1.0;
  MatrixBuildRotationAboutAxis(
    vAxisOfRot: (Vector *)&axis.y,
    angleDegrees: z,
    dst: (matrix3x4_t *)&rotmat.m_flMatVal[0][1]);
  ConcatTransforms(
    in1: (matrix3x4_t *)&rotmat.m_flMatVal[0][1],
    in2: (matrix3x4_t *)&scalemat.m_flMatVal[0][1],
    out: (matrix3x4_t *)&temp.m_flMatVal[0][1]);
  ConcatTransforms(
    in1: (matrix3x4_t *)&transmat.m_flMatVal[0][1],
    in2: (matrix3x4_t *)&temp.m_flMatVal[0][1],
    out: (matrix3x4_t *)&rawToLocal.m_flMatVal[0][1]);
  this->m_pGroup->GetRenderTransform(this: this->m_pGroup, a2: (matrix3x4_t *)&groupToScreen.m_flMatVal[0][1], a3: true);
  ConcatTransforms(
    in1: (matrix3x4_t *)&groupToScreen.m_flMatVal[0][1],
    in2: (matrix3x4_t *)&rawToLocal.m_flMatVal[0][1],
    out: &this->m_RelToScreenHoldAspectRatio);
  for ( i = 0; i < this->m_MemberList.m_Size; ++i )
  {
    v4 = this->m_MemberList.m_Memory.m_pMemory[i];
    v4->UpdateRenderTransforms(this: v4, a2: stageRenderInfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420A80
// Name: public: virtual bool CGraphicGroup::HasState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGraphicGroup::HasState(CGraphicGroup *this, const char *pStateName)
{
  int v4; // esi
  CGameGraphic *v5; // ecx

  if ( CGameGraphic::HasState(this, pStateName) )
    return 1;
  v4 = 0;
  if ( this->m_MemberList.m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = this->m_MemberList.m_Memory.m_pMemory[v4];
    if ( v5->HasState(this: v5, a2: pStateName) )
      break;
    if ( ++v4 >= this->m_MemberList.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00420AE0
// Name: public: virtual void CGraphicGroup::SetState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphicGroup::SetState(CGraphicGroup *this, const char *pStateName)
{
  int i; // esi
  CGameGraphic *v4; // ecx

  CGameGraphic::SetState(this, pStateName, bStartPlaying: true);
  for ( i = 0; i < this->m_MemberList.m_Size; ++i )
  {
    v4 = this->m_MemberList.m_Memory.m_pMemory[i];
    v4->SetState(this: v4, a2: pStateName, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420B30
// Name: public: virtual void CGraphicGroup::StartPlaying(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphicGroup::StartPlaying(CGraphicGroup *this)
{
  int i; // esi
  CGameGraphic *v3; // ecx

  CGameGraphic::StartPlaying(this);
  for ( i = 0; i < this->m_MemberList.m_Size; ++i )
  {
    v3 = this->m_MemberList.m_Memory.m_pMemory[i];
    v3->StartPlaying(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420B70
// Name: public: virtual void CGraphicGroup::StopPlaying(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphicGroup::StopPlaying(CGraphicGroup *this)
{
  int i; // esi
  CGameGraphic *v3; // ecx

  CGameGraphic::StopPlaying(this);
  for ( i = 0; i < this->m_MemberList.m_Size; ++i )
  {
    v3 = this->m_MemberList.m_Memory.m_pMemory[i];
    v3->StopPlaying(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420BB0
// Name: public: virtual void CGraphicGroup::AdvanceState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphicGroup::AdvanceState(CGraphicGroup *this)
{
  int i; // esi
  CGameGraphic *v3; // ecx

  CGameGraphic::AdvanceState(this);
  for ( i = 0; i < this->m_MemberList.m_Size; ++i )
  {
    v3 = this->m_MemberList.m_Memory.m_pMemory[i];
    v3->AdvanceState(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420BF0
// Name: public: class CHitArea __near * CGraphicGroup::GetKeyFocusRequestGraphic(void)
// Source: json
//------------------------------------------------------------------------------
CHitArea *__thiscall CGraphicGroup::GetKeyFocusRequestGraphic(CGraphicGroup *this)
{
  int m_Size; // edx
  int v2; // eax
  CGameGraphic **m_pMemory; // esi
  CGameGraphic **i; // ecx

  m_Size = this->m_MemberList.m_Size;
  v2 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  m_pMemory = this->m_MemberList.m_Memory.m_pMemory;
  for ( i = m_pMemory; !(*i)->m_bCanAcceptInput; ++i )
  {
    if ( ++v2 >= m_Size )
      return nullptr;
  }
  return (CHitArea *)m_pMemory[v2];
}

//------------------------------------------------------------------------------
// Address: 0x00420C30
// Name: public: virtual class CGameGraphic __near * CGraphicGroup::FindGraphicByName(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CGameGraphic *__thiscall CGraphicGroup::FindGraphicByName(CGraphicGroup *this, const char *pName)
{
  int m_Size; // ebp
  int v4; // esi
  CGameGraphic *v5; // edi

  m_Size = this->m_MemberList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = this->m_MemberList.m_Memory.m_pMemory[v4];
    if ( CGameGraphic::IsGraphicNamed(this: v5, pName) )
      break;
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00420C80
// Name: public: virtual void CGraphicGroup::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphicGroup::SetVisible(CGraphicGroup *this, BOOL bVisible)
{
  int m_Size; // ebp
  int v4; // esi
  CGameGraphic *v5; // ecx

  m_Size = this->m_MemberList.m_Size;
  v4 = 0;
  for ( this->m_Geometry.m_bVisible = bVisible; v4 < m_Size; ++v4 )
  {
    v5 = this->m_MemberList.m_Memory.m_pMemory[v4];
    v5->SetVisible(this: v5, a2: bVisible);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420CC0
// Name: public: void CGraphicGroup::RemoveFromGroup(class CGameGraphic __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphicGroup::RemoveFromGroup(CGraphicGroup *this, CGameGraphic *pGraphic)
{
  int m_Size; // edx
  int v4; // ecx
  CGameGraphic **i; // eax

  m_Size = this->m_MemberList.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    for ( i = this->m_MemberList.m_Memory.m_pMemory; *i != pGraphic; ++i )
    {
      if ( ++v4 >= m_Size )
        return;
    }
    if ( m_Size - v4 - 1 > 0 )
      _V_memmove(
        dest: &this->m_MemberList.m_Memory.m_pMemory[v4],
        src: &this->m_MemberList.m_Memory.m_pMemory[v4 + 1],
        count: 4 * (m_Size - v4 - 1));
    --this->m_MemberList.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420E20
// Name: public: CGraphicGroup::CGraphicGroup(void)
// Source: json
//------------------------------------------------------------------------------
CGraphicGroup *__thiscall CGraphicGroup::CGraphicGroup(CGraphicGroup *this)
{
  CGameGraphic::CGameGraphic(this);
  this->__vftable = (CGraphicGroup_vtbl *)&CGraphicGroup::`vftable';
  this->m_MemberList.m_Memory.m_pMemory = nullptr;
  this->m_MemberList.m_Memory.m_nAllocationCount = 0;
  this->m_MemberList.m_Memory.m_nGrowSize = 0;
  this->m_MemberList.m_Size = 0;
  this->m_MemberList.m_pElements = nullptr;
  this->m_ResultantColor.r = 0;
  this->m_ResultantColor.g = 0;
  this->m_ResultantColor.b = 0;
  this->m_ResultantColor.a = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00420E70
// Name: public: virtual void CGameGraphic::SetColor(struct color32_s)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameGraphic::SetColor(CGameGraphic *this, color32_s c)
{
  this->m_Geometry.m_Color = c;
}

//------------------------------------------------------------------------------
// Address: 0x00420E90
// Name: public: virtual CGraphicGroup::~CGraphicGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphicGroup::~CGraphicGroup(CGraphicGroup *this)
{
  this->__vftable = (CGraphicGroup_vtbl *)&CGraphicGroup::`vftable';
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_MemberList);
  CGameGraphic::~CGameGraphic(this);
}

//------------------------------------------------------------------------------
// Address: 0x00420EF0
// Name: public: void CGraphicGroup::AddToGroup(class CGameGraphic __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGraphicGroup::AddToGroup(CGraphicGroup *this, CGameGraphic *pGraphic)
{
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_MemberList,
    elem: this->m_MemberList.m_Size,
    src: (vgui::TreeNode **)&pGraphic);
}

//------------------------------------------------------------------------------
// Address: 0x00420F10
// Name: public: bool CGraphicGroup::Unserialize(class CDmxElement __near *,class CUtlDict<class CGameGraphic __near *,int> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGraphicGroup::Unserialize(
        CGraphicGroup *this,
        CDmxElement *pElement,
        CUtlDict<CGameGraphic *,int> *unserializedGraphicMapping)
{
  CDmxElement *v3; // edi
  CDmxAttribute *Attribute; // eax
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v5; // ebx
  int m_Size; // ebp
  int v7; // esi
  const UniqueId_t *Id; // eax
  CGameGraphic *elem; // eax
  int v10; // ecx
  CDmxAttribute *v11; // eax
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v12; // edi
  int v13; // ebp
  int v14; // esi
  CAnimData *v15; // eax
  char *v16; // ebx
  const UniqueId_t *v17; // eax
  CDmxElement *v19; // [esp-10h] [ebp-228h]
  CUtlMap<char const *,CGameGraphic *,int>::Node_t src; // [esp+8h] [ebp-210h] BYREF
  CUtlMap<char const *,CGameGraphic *,int>::Node_t search; // [esp+10h] [ebp-208h] BYREF
  char v23[252]; // [esp+18h] [ebp-200h] BYREF
  char pBuf[260]; // [esp+114h] [ebp-104h] BYREF

  v3 = pElement;
  CDmxElement::UnpackIntoStructure(this: pElement, pData: this, pUnpack: s_GraphicGroupUnpack);
  Attribute = (CDmxAttribute *)CDmxElement::GetAttribute(this: pElement, pAttributeName: "groupElements");
  if ( Attribute == nullptr || Attribute->m_Type != AT_FIRST_ARRAY_TYPE )
    return 0;
  v5 = CDmxAttribute::GetArray<CDmxElement *>(this: Attribute);
  m_Size = v5->m_Size;
  v7 = 0;
  if ( m_Size > 0 )
  {
    do
    {
      Id = CDmxElement::GetId(this: v5->m_Memory.m_pMemory[v7]);
      UniqueIdToString(id: Id, pBuf: v23, nMaxLen: 255);
      search.key = v23;
      elem = unserializedGraphicMapping->m_Elements.m_Tree.m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int>>::Find(
                                                                                  this: &unserializedGraphicMapping->m_Elements.m_Tree,
                                                                                  &search)].m_Data.elem;
      elem->m_pGroup = this;
      v10 = this->m_MemberList.m_Size;
      src.key = (const char *)elem;
      CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_MemberList,
        elem: v10,
        (vgui::TreeNode **)&src);
      ++v7;
    }
    while ( v7 < m_Size );
    v3 = pElement;
  }
  v11 = (CDmxAttribute *)CDmxElement::GetAttribute(this: v3, pAttributeName: "imageanims");
  if ( v11 != nullptr && v11->m_Type == AT_FIRST_ARRAY_TYPE )
  {
    v12 = CDmxAttribute::GetArray<CDmxElement *>(this: v11);
    v13 = v12->m_Size;
    v14 = 0;
    if ( v13 <= 0 )
    {
LABEL_14:
      v17 = CDmxElement::GetId(this: pElement);
      UniqueIdToString(id: v17, pBuf: &pBuf[4], nMaxLen: 255);
      src.key = MemAlloc_StrDup(pString: &pBuf[4]);
      src.elem = this;
      CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int>>::Insert(
        this: &unserializedGraphicMapping->m_Elements.m_Tree,
        insert: &src);
      this->SetState_2(this, a2: "default");
      return 1;
    }
    while ( 1 )
    {
      v15 = (CAnimData *)MemAlloc_Alloc(nSize: 0x140u);
      v16 = v15 != nullptr ? (char *)CAnimData::CAnimData(this: v15) : nullptr;
      v19 = v12->m_Memory.m_pMemory[v14];
      src.key = v16;
      if ( !CAnimData::Unserialize(this: (CAnimData *)v16, pElement: v19) )
        break;
      CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Anims,
        elem: this->m_Anims.m_Size,
        (vgui::TreeNode **)&src);
      if ( ++v14 >= v13 )
        goto LABEL_14;
    }
    if ( v16 != nullptr )
    {
      CAnimData::~CAnimData(this: (CAnimData *)v16);
      free(pMem: v16);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005335D0
// Name: CGraphicGroup_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *CGraphicGroup_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<CGraphicGroup>();
  s_pUnpack_3 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00421110
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class CHitArea>(class CHitArea __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<CHitArea>()
{
  if ( (_S1_1 & 1) == 0 )
  {
    _S1_1 |= 1u;
    dword_5BA6C4 = 9;
    dword_5BA6CC = 8;
    dword_5BA6F0 = 9;
    dword_5BA6F8 = 8;
    dword_5BA6C8 = 108;
    dword_5BA6D0 = -1;
    dword_5BA6D4 = 0;
    dword_5BA6D8 = 0;
    dword_5BA6DC = 0;
    dword_5BA6E0 = 0;
    dword_5BA6E4 = 0;
    dword_5BA6E8 = (int)"scale";
    dword_5BA6EC = (int)"0 0";
    dword_5BA6F4 = 116;
    dword_5BA6FC = -1;
    dword_5BA700 = 0;
    dword_5BA704 = 0;
    dword_5BA708 = 0;
    dword_5BA70C = 0;
    dword_5BA710 = 0;
    dword_5BA714 = (int)"rotation";
    dword_5BA718 = (int)"0";
    dword_5BA71C = 3;
    dword_5BA720 = 124;
    dword_5BA724 = 4;
    dword_5BA728 = -1;
    dword_5BA72C = 0;
    dword_5BA730 = 0;
    dword_5BA734 = 0;
    dword_5BA738 = 0;
    dword_5BA73C = 0;
    dword_5BA740 = (int)"maintainaspectratio";
    dword_5BA744 = (int)"0";
    dword_5BA748 = 4;
    dword_5BA74C = 156;
    dword_5BA750 = 1;
    dword_5BA754 = -1;
    dword_5BA758 = 0;
    dword_5BA75C = 0;
    dword_5BA760 = 0;
    dword_5BA764 = 0;
    dword_5BA768 = 0;
    dword_5BA76C = (int)"sublayertype";
    dword_5BA770 = (int)"0";
    dword_5BA774 = 2;
    dword_5BA778 = 152;
    dword_5BA77C = 4;
    dword_5BA780 = -1;
    dword_5BA784 = 0;
    dword_5BA788 = 0;
    dword_5BA78C = 0;
    dword_5BA790 = 0;
    dword_5BA794 = 0;
    dword_5BA798 = (int)"visible";
    dword_5BA79C = (int)"1";
    dword_5BA7A0 = 4;
    dword_5BA7A4 = 157;
    dword_5BA7A8 = 1;
    dword_5BA7AC = -1;
    dword_5BA7B0 = 0;
    dword_5BA7B4 = 0;
    dword_5BA7B8 = 0;
    dword_5BA7BC = 0;
    dword_5BA7C0 = 0;
    dword_5BA7C4 = (int)"initialstate";
    dword_5BA7C8 = (int)"-1";
    dword_5BA7CC = 2;
    dword_5BA7D0 = 352;
    dword_5BA7D4 = 4;
    dword_5BA7D8 = -1;
    dword_5BA7DC = 0;
    dword_5BA7E0 = 0;
    dword_5BA7E4 = 0;
    dword_5BA7F4 = (int)"0";
    dword_5BA7E8 = 0;
    dword_5BA7EC = 0;
    dword_5BA7F0 = (int)"dragenabled";
    dword_5BA7F8 = 4;
    dword_5BA7FC = 384;
    dword_5BA800 = 1;
    dword_5BA804 = -1;
    dword_5BA808 = 0;
    dword_5BA80C = 0;
    dword_5BA810 = 0;
    dword_5BA814 = 0;
    dword_5BA818 = 0;
    dword_5BA81C = (int)"on_mouse_left_clicked_cmd";
    dword_5BA820 = (int)defaultValue;
    dword_5BA824 = 5;
    dword_5BA828 = 404;
    dword_5BA82C = -1;
    dword_5BA830 = -1;
    dword_5BA834 = 0;
    dword_5BA838 = 0;
    dword_5BA83C = 0;
    dword_5BA840 = 0;
    dword_5BA844 = 0;
    dword_5BA848 = 0;
    dword_5BA84C = 0;
    dword_5BA850 = 0;
    dword_5BA854 = 0;
    dword_5BA858 = 0;
    dword_5BA85C = -1;
    dword_5BA860 = 0;
    dword_5BA864 = 0;
    dword_5BA868 = 0;
    dword_5BA86C = 0;
    dword_5BA870 = 0;
  }
  return unpack_1;
}

//------------------------------------------------------------------------------
// Address: 0x005335E0
// Name: _dynamic_initializer_for__s_GraphicGroupUnpack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__s_GraphicGroupUnpack__()
{
  s_GraphicGroupUnpack = s_pUnpack_3;
  return s_pUnpack_3;
}

//------------------------------------------------------------------------------
// Address: 0x005335F0
// Name: _dynamic_initializer_for__g_CDynamicRectClassFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDynamicRectClassFactory__()
{
  return ((int (__thiscall *)(CGameUISystemMgr *, const char *, CHitAreaClassFactory *))g_pGameUISystemMgrImpl->RegisterGraphicClassFactory)(
           a1: g_pGameUISystemMgrImpl,
           a2: "hitarea",
           a3: &g_CDynamicRectClassFactory);
}
