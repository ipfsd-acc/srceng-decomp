// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/gamestage.cpp
// Functions: 9
// ============================================================

#include "vgui2\game_controls\gamestage.h"

//------------------------------------------------------------------------------
// Address: 0x00423AE0
// Name: public: bool CGameStage::Unserialize(class CDmxElement __near *,class CUtlDict<class CGameGraphic __near *,int> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameStage::Unserialize(
        CGameStage *this,
        CDmxElement *pElement,
        CUtlDict<CGameGraphic *,int> *unserializedGraphicMapping)
{
  char result; // al

  CDmxElement::UnpackIntoStructure(this: pElement, pData: this, pUnpack: s_GameStageUnpack);
  result = CGraphicGroup::Unserialize(this, pElement, unserializedGraphicMapping);
  if ( result != 0 )
  {
    this->SetState_2(this, a2: "default");
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423B30
// Name: public: void CGameStage::UpdateAspectRatio(struct Rect_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameStage::UpdateAspectRatio(CGameStage *this, const Rect_t *viewport)
{
  float x; // xmm2_4
  float y; // xmm3_4
  float v4; // xmm1_4
  float v5; // xmm0_4

  x = this->m_StageSize.x;
  y = this->m_StageSize.y;
  v4 = (float)viewport->width / x;
  v5 = (float)viewport->height / y;
  if ( v4 <= v5 )
    v5 = (float)viewport->width / x;
  else
    v4 = (float)viewport->height / y;
  this->m_MaintainAspectRatioStageSize.x = x * v4;
  this->m_MaintainAspectRatioStageSize.y = y * v5;
}

//------------------------------------------------------------------------------
// Address: 0x00423B80
// Name: public: void CGameStage::SetStageSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameStage::SetStageSize(CGameStage *this, int nWide, int nTall)
{
  this->m_StageSize.x = (float)nWide;
  this->m_StageSize.y = (float)nTall;
}

//------------------------------------------------------------------------------
// Address: 0x00423BA0
// Name: public: virtual void CGameStage::GetRenderTransform(struct matrix3x4_t __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameStage::GetRenderTransform(CGameStage *this, matrix3x4_t *relToScreen, bool bMaintainAspectRatio)
{
  __int64 v3; // xmm0_8

  if ( bMaintainAspectRatio )
  {
    *(_QWORD *)&relToScreen->m_flMatVal[0][0] = *(_QWORD *)&this->m_StageRenderInfo.relToScreenHoldAspectRatio.m_flMatVal[0][0];
    *(_QWORD *)&relToScreen->m_flMatVal[0][2] = *(_QWORD *)&this->m_StageRenderInfo.relToScreenHoldAspectRatio.m_flMatVal[0][2];
    *(_OWORD *)&relToScreen->m_flMatVal[1][0] = *(_OWORD *)&this->m_StageRenderInfo.relToScreenHoldAspectRatio.m_flMatVal[1][0];
    *(_QWORD *)&relToScreen->m_flMatVal[2][0] = *(_QWORD *)&this->m_StageRenderInfo.relToScreenHoldAspectRatio.m_flMatVal[2][0];
    v3 = *(_QWORD *)&this->m_StageRenderInfo.relToScreenHoldAspectRatio.m_flMatVal[2][2];
  }
  else
  {
    *(_QWORD *)&relToScreen->m_flMatVal[0][0] = *(_QWORD *)&this->m_StageRenderInfo.relToScreen.m_flMatVal[0][0];
    *(_QWORD *)&relToScreen->m_flMatVal[0][2] = *(_QWORD *)&this->m_StageRenderInfo.relToScreen.m_flMatVal[0][2];
    *(_OWORD *)&relToScreen->m_flMatVal[1][0] = *(_OWORD *)&this->m_StageRenderInfo.relToScreen.m_flMatVal[1][0];
    *(_QWORD *)&relToScreen->m_flMatVal[2][0] = *(_QWORD *)&this->m_StageRenderInfo.relToScreen.m_flMatVal[2][0];
    v3 = *(_QWORD *)&this->m_StageRenderInfo.relToScreen.m_flMatVal[2][2];
  }
  *(_QWORD *)&relToScreen->m_flMatVal[2][2] = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00423C50
// Name: public: CGameStage::CGameStage(void)
// Source: json
//------------------------------------------------------------------------------
CGameStage *__thiscall CGameStage::CGameStage(CGameStage *this)
{
  CGraphicGroup::CGraphicGroup(this);
  this->__vftable = (CGameStage_vtbl *)&CGameStage::`vftable';
  CUtlString::operator=(this: &this->m_pName, src: "stage");
  this->m_StageSize.x = 1024.0;
  this->m_StageSize.y = 768.0;
  this->m_StageRenderInfo.parentPos.x = 0.0;
  this->m_StageRenderInfo.parentPos.y = 0.0;
  this->m_StageRenderInfo.parentPos.z = 0.0;
  this->m_StageRenderInfo.parentScale.x = 0.0;
  this->m_StageRenderInfo.parentScale.y = 0.0;
  this->m_MaintainAspectRatioStageSize.x = 640.0;
  this->m_Geometry.m_bMaintainAspectRatio = false;
  this->m_StageRenderInfo.parentRot = 0;
  this->m_CurrentState = -1;
  this->m_bFullscreen = true;
  this->m_MaintainAspectRatioStageSize.y = 480.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00423D30
// Name: public: void CGameStage::UpdateRenderTransforms(struct Rect_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CGameStage::UpdateRenderTransforms(CGameStage *this, const Rect_t *viewport)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  int m_Rotation; // eax
  int v8; // ebx
  bool v9; // cc
  CGameGraphic *v10; // ecx
  float x; // [esp+0h] [ebp-150h]
  float y; // [esp+4h] [ebp-14Ch]
  color32_s m_Color; // [esp+Ch] [ebp-144h]
  float screenScaleX; // [esp+1Ch] [ebp-134h]
  float v15; // [esp+20h] [ebp-130h]
  Vector vAxisOfRot; // [esp+24h] [ebp-12Ch] BYREF
  matrix3x4_t out; // [esp+30h] [ebp-120h] BYREF
  _QWORD v18[5]; // [esp+60h] [ebp-F0h] BYREF
  _BYTE v19[9]; // [esp+88h] [ebp-C8h] OVERLAPPED BYREF
  matrix3x4_t scalemat; // [esp+BCh] [ebp-94h] BYREF
  matrix3x4_t rotmat; // [esp+ECh] [ebp-64h] BYREF
  matrix3x4_t temp; // [esp+11Ch] [ebp-34h] BYREF

  SetIdentityMatrix(matrix: (matrix3x4_t *)&v19[8]);
  v3 = this->m_Geometry.m_Center.y;
  v4 = (float)(viewport->height / 2);
  this->m_StageRenderInfo.parentPos.x = this->m_Geometry.m_Center.x + (float)(viewport->width / 2);
  this->m_StageRenderInfo.parentPos.y = v3 + v4;
  this->m_StageRenderInfo.parentPos.z = 0.0;
  MatrixSetColumn(in: &this->m_StageRenderInfo.parentPos, column: 3, out: (matrix3x4_t *)&v19[8]);
  v5 = (float)viewport->width / this->m_StageSize.x;
  v6 = (float)viewport->height / this->m_StageSize.y;
  this->m_StageRenderInfo.parentScale.x = v5;
  this->m_StageRenderInfo.parentScale.y = v6;
  v15 = v5;
  this->m_StageRenderInfo.parentScale.x = v5 * this->m_Geometry.m_Scale.x;
  this->m_StageRenderInfo.parentScale.y = this->m_Geometry.m_Scale.y * this->m_StageRenderInfo.parentScale.y;
  screenScaleX = v6;
  SetScaleMatrix(
    x: this->m_StageRenderInfo.parentScale.x,
    y: this->m_StageRenderInfo.parentScale.y,
    z: 1.0,
    dst: (matrix3x4_t *)&scalemat.m_flMatVal[0][1]);
  m_Rotation = (int)this->m_Geometry.m_Rotation;
  vAxisOfRot.x = 0.0;
  vAxisOfRot.y = 0.0;
  vAxisOfRot.z = 1.0;
  this->m_StageRenderInfo.parentRot = m_Rotation;
  MatrixBuildRotationAboutAxis(
    &vAxisOfRot,
    angleDegrees: (float)m_Rotation,
    dst: (matrix3x4_t *)&rotmat.m_flMatVal[0][1]);
  ConcatTransforms(
    in1: (matrix3x4_t *)&rotmat.m_flMatVal[0][1],
    in2: (matrix3x4_t *)&scalemat.m_flMatVal[0][1],
    out: (matrix3x4_t *)&temp.m_flMatVal[0][1]);
  ConcatTransforms(
    in1: (const matrix3x4_t *)&v19[8],
    in2: (matrix3x4_t *)&temp.m_flMatVal[0][1],
    out: (matrix3x4_t *)v18);
  *(_QWORD *)&this->m_StageRenderInfo.relToScreen.m_flMatVal[0][0] = v18[0];
  *(_QWORD *)&this->m_StageRenderInfo.relToScreen.m_flMatVal[0][2] = v18[1];
  *(_QWORD *)&this->m_StageRenderInfo.relToScreen.m_flMatVal[1][0] = v18[2];
  *(_QWORD *)&this->m_StageRenderInfo.relToScreen.m_flMatVal[1][2] = v18[3];
  *(_QWORD *)&this->m_StageRenderInfo.relToScreen.m_flMatVal[2][0] = v18[4];
  *(_QWORD *)&this->m_StageRenderInfo.relToScreen.m_flMatVal[2][2] = *(_QWORD *)v19;
  SetIdentityMatrix(matrix: (matrix3x4_t *)&v19[8]);
  MatrixSetColumn(in: &this->m_StageRenderInfo.parentPos, column: 3, out: (matrix3x4_t *)&v19[8]);
  if ( v5 <= v6 )
    screenScaleX = v5;
  else
    v15 = v6;
  y = this->m_Geometry.m_Scale.y * screenScaleX;
  x = this->m_Geometry.m_Scale.x * v15;
  SetScaleMatrix(x, y, z: 1.0, dst: (matrix3x4_t *)&scalemat.m_flMatVal[0][1]);
  vAxisOfRot.x = 0.0;
  vAxisOfRot.y = 0.0;
  vAxisOfRot.z = 1.0;
  MatrixBuildRotationAboutAxis(
    &vAxisOfRot,
    angleDegrees: (float)this->m_StageRenderInfo.parentRot,
    dst: (matrix3x4_t *)&rotmat.m_flMatVal[0][1]);
  ConcatTransforms(
    in1: (matrix3x4_t *)&rotmat.m_flMatVal[0][1],
    in2: (matrix3x4_t *)&scalemat.m_flMatVal[0][1],
    out: (matrix3x4_t *)&temp.m_flMatVal[0][1]);
  ConcatTransforms(in1: (const matrix3x4_t *)&v19[8], in2: (matrix3x4_t *)&temp.m_flMatVal[0][1], &out);
  *(_QWORD *)&this->m_StageRenderInfo.relToScreenHoldAspectRatio.m_flMatVal[0][0] = *(_QWORD *)&out.m_flMatVal[0][0];
  *(_QWORD *)&this->m_StageRenderInfo.relToScreenHoldAspectRatio.m_flMatVal[0][2] = *(_QWORD *)&out.m_flMatVal[0][2];
  *(_OWORD *)&this->m_StageRenderInfo.relToScreenHoldAspectRatio.m_flMatVal[1][0] = *(_OWORD *)&out.m_flMatVal[1][0];
  *(_QWORD *)&this->m_StageRenderInfo.relToScreenHoldAspectRatio.m_flMatVal[2][0] = *(_QWORD *)&out.m_flMatVal[2][0];
  v8 = 0;
  v9 = this->m_MemberList.m_Size <= 0;
  *(_QWORD *)&this->m_StageRenderInfo.relToScreenHoldAspectRatio.m_flMatVal[2][2] = *(_QWORD *)&out.m_flMatVal[2][2];
  if ( !v9 )
  {
    do
    {
      v10 = this->m_MemberList.m_Memory.m_pMemory[v8];
      v10->UpdateRenderTransforms(this: v10, a2: &this->m_StageRenderInfo);
      ++v8;
    }
    while ( v8 < this->m_MemberList.m_Size );
  }
  m_Color = this->m_Geometry.m_Color;
  this->m_ResultantColor = m_Color;
  CGraphicGroup::UpdateRenderData(this, parentColor: *(_DWORD *)&m_Color);
}

//------------------------------------------------------------------------------
// Address: 0x00533670
// Name: CGameStage_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *CGameStage_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<CGameStage>();
  s_pUnpack_5 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00533680
// Name: _dynamic_initializer_for__s_GameStageUnpack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__s_GameStageUnpack__()
{
  s_GameStageUnpack = s_pUnpack_5;
  return s_pUnpack_5;
}

//------------------------------------------------------------------------------
// Address: 0x00533690
// Name: _dynamic_initializer_for__g_mapScriptHandles___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_mapScriptHandles___0()
{
  return atexit(func: dynamic_atexit_destructor_for__g_mapScriptHandles___0);
}
