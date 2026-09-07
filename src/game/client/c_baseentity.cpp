// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_baseentity.cpp
// Functions: 380
// ============================================================

#include "game\client\c_baseentity.h"

//------------------------------------------------------------------------------
// Address: 0x1001B3C0
// Name: public: bool CDiscontinuousInterpolatedVar<class Vector>::GetDiscontinuityTransform(float,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDiscontinuousInterpolatedVar<Vector>::GetDiscontinuityTransform(
        CDiscontinuousInterpolatedVar<Vector> *this,
        float fCurTime,
        matrix3x4_t *matOut)
{
  int m_Size; // eax
  int m_count; // edx
  float flChangeTime; // xmm0_4
  int v7; // edx
  int m_maxElement; // esi
  CDiscontinuousInterpolatedVar<Vector>::Discontinuity_t *m_pMemory; // edx
  bool v10; // cf
  int v11; // eax
  __int64 v12; // xmm1_8
  CDiscontinuousInterpolatedVar<Vector>::Discontinuity_t *v13; // eax
  int v14; // ebx
  int v15; // esi
  int v16; // eax
  const matrix3x4_t *v17; // ecx
  matrix3x4_t matTemp; // [esp+0h] [ebp-40h] BYREF
  matrix3x4_t *pSwapMatrices[2]; // [esp+30h] [ebp-10h]
  CDiscontinuousInterpolatedVar<Vector> *v20; // [esp+38h] [ebp-8h]
  float fTargetTime; // [esp+3Ch] [ebp-4h]
  int fCurTimea; // [esp+48h] [ebp+8h]

  m_Size = this->m_Discontinuities.m_Size;
  v20 = this;
  if ( m_Size == 0 )
    return 0;
  m_count = this->m_VarHistory.m_count;
  flChangeTime = 0.0;
  if ( (_WORD)m_count != 0 )
  {
    v7 = this->m_VarHistory.m_firstElement + m_count - 1;
    m_maxElement = this->m_VarHistory.m_maxElement;
    if ( v7 >= m_maxElement )
      v7 -= m_maxElement;
    flChangeTime = this->m_VarHistory.m_pElements[v7].flChangeTime;
  }
  if ( fCurTime <= flChangeTime )
    flChangeTime = fCurTime;
  if ( (float)(fCurTime - this->m_InterpolationAmount) > flChangeTime )
    flChangeTime = fCurTime - this->m_InterpolationAmount;
  m_pMemory = this->m_Discontinuities.m_Memory.m_pMemory;
  v10 = flChangeTime < m_pMemory[m_Size - 1].fBeforeTime;
  fTargetTime = flChangeTime;
  if ( !v10 )
    return 0;
  v11 = m_Size;
  v12 = *(_QWORD *)&m_pMemory[v11 - 1].matTransform.m_flMatVal[0][0];
  v13 = &m_pMemory[v11 - 1];
  *(_QWORD *)&matOut->m_flMatVal[0][0] = v12;
  *(_QWORD *)&matOut->m_flMatVal[0][2] = *(_QWORD *)&v13->matTransform.m_flMatVal[0][2];
  *(_QWORD *)&matOut->m_flMatVal[1][0] = *(_QWORD *)&v13->matTransform.m_flMatVal[1][0];
  *(_QWORD *)&matOut->m_flMatVal[1][2] = *(_QWORD *)&v13->matTransform.m_flMatVal[1][2];
  *(_QWORD *)&matOut->m_flMatVal[2][0] = *(_QWORD *)&v13->matTransform.m_flMatVal[2][0];
  *(_QWORD *)&matOut->m_flMatVal[2][2] = *(_QWORD *)&v13->matTransform.m_flMatVal[2][2];
  v14 = 0;
  v15 = this->m_Discontinuities.m_Size - 2;
  pSwapMatrices[0] = matOut;
  pSwapMatrices[1] = &matTemp;
  if ( v15 >= 0 )
  {
    v16 = 52 * v15;
    for ( fCurTimea = 52 * v15; ; v16 = fCurTimea )
    {
      v17 = (matrix3x4_t *)((char *)&this->m_Discontinuities.m_Memory.m_pMemory->matTransform + v16);
      if ( flChangeTime > v17[1].m_flMatVal[0][0] )
        break;
      ConcatTransforms(in1: v17, in2: pSwapMatrices[v14], out: pSwapMatrices[-v14 + 1]);
      fCurTimea -= 52;
      --v15;
      v14 = 1 - v14;
      if ( v15 < 0 )
        break;
      flChangeTime = fTargetTime;
      this = v20;
    }
    if ( v14 == 1 )
      *matOut = matTemp;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10023DB0
// Name: public: void CBitVecT<class CVarBitVecBase<unsigned short>>::ClearAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitVecT<CVarBitVecBase<unsigned short>>::ClearAll(CBitVecT<CVarBitVecBase<unsigned short> > *this)
{
  unsigned int *m_pInt; // eax

  m_pInt = this->m_pInt;
  if ( m_pInt != nullptr )
    memset(dst: (int)m_pInt, value: nullptr, count: 4 * this->m_numInts);
}

//------------------------------------------------------------------------------
// Address: 0x100249A0
// Name: struct ScriptClassDesc_t __near * GetScriptDesc<class C_BaseAnimating>(class C_BaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__cdecl GetScriptDesc<C_BaseAnimating>()
{
  return &g_C_BaseAnimating_ScriptDesc;
}

//------------------------------------------------------------------------------
// Address: 0x10037970
// Name: float CoordFromCell(int,int,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl CoordFromCell(int cellwidth, int cell, float f)
{
  return (double)(cell * cellwidth - 0x4000) + f;
}

//------------------------------------------------------------------------------
// Address: 0x10037990
// Name: class CPredictableList __near * GetPredictables(int)
// Source: json
//------------------------------------------------------------------------------
CPredictableList *__cdecl GetPredictables(int nSlot)
{
  return (CPredictableList *)(&g_Predictables + nSlot);
}

//------------------------------------------------------------------------------
// Address: 0x100379E0
// Name: public: static void C_BaseEntity::RecvProxy_CellX(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::RecvProxy_CellX(const CRecvProxyData *pData, void *pStruct, int *pOut)
{
  *pOut = pData->m_Value.m_Int;
  if ( (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)pStruct + 580))(a1: pStruct) != 0 )
    *((float *)pStruct + 75) = CoordFromCell(
                                 cellwidth: *((_DWORD *)pStruct + 29),
                                 cell: *((_DWORD *)pStruct + 30),
                                 f: *((float *)pStruct + 33));
}

//------------------------------------------------------------------------------
// Address: 0x10037A50
// Name: public: static void C_BaseEntity::RecvProxy_CellY(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::RecvProxy_CellY(const CRecvProxyData *pData, void *pStruct, int *pOut)
{
  *pOut = pData->m_Value.m_Int;
  if ( (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)pStruct + 580))(a1: pStruct) != 0 )
    *((float *)pStruct + 76) = CoordFromCell(
                                 cellwidth: *((_DWORD *)pStruct + 29),
                                 cell: *((_DWORD *)pStruct + 31),
                                 f: *((float *)pStruct + 34));
}

//------------------------------------------------------------------------------
// Address: 0x10037AC0
// Name: public: static void C_BaseEntity::RecvProxy_CellZ(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::RecvProxy_CellZ(const CRecvProxyData *pData, void *pStruct, int *pOut)
{
  *pOut = pData->m_Value.m_Int;
  if ( (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)pStruct + 580))(a1: pStruct) != 0 )
    *((float *)pStruct + 77) = CoordFromCell(
                                 cellwidth: *((_DWORD *)pStruct + 29),
                                 cell: *((_DWORD *)pStruct + 32),
                                 f: *((float *)pStruct + 35));
}

//------------------------------------------------------------------------------
// Address: 0x10037B30
// Name: public: static void C_BaseEntity::RecvProxy_CellOrigin(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::RecvProxy_CellOrigin(const CRecvProxyData *pData, void *pStruct, float *pOut)
{
  int cellwidth; // [esp+1Ch] [ebp-Ch]

  *(($5FB8512C96CD1B8867E59BA5A9F6C5D6 *)pStruct + 11) = pData->m_Value.___u0;
  if ( (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)pStruct + 580))(a1: pStruct) != 0 )
  {
    cellwidth = *((_DWORD *)pStruct + 29);
    *pOut = CoordFromCell(cellwidth, cell: *((_DWORD *)pStruct + 30), f: pData->m_Value.m_Float);
    pOut[1] = CoordFromCell(cellwidth, cell: *((_DWORD *)pStruct + 31), f: pData->m_Value.m_Vector[1]);
    pOut[2] = CoordFromCell(cellwidth, cell: *((_DWORD *)pStruct + 32), f: pData->m_Value.m_Vector[2]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037C10
// Name: public: virtual class ClientClass __near * C_BaseEntity::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BaseEntity::GetClientClass(C_BaseEntity *this)
{
  return &__g_C_BaseEntityClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10037C20
// Name: void RecvProxy_EffectFlags(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_EffectFlags(const CRecvProxyData *pData, C_BaseEntity *pStruct)
{
  C_BaseEntity::SetEffects(this: pStruct, nEffects: pData->m_Value.m_Int);
}

//------------------------------------------------------------------------------
// Address: 0x10037C40
// Name: public: virtual struct ScriptClassDesc_t __near * C_BaseEntity::GetScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__thiscall C_BaseEntity::GetScriptDesc(C_BaseEntity *this)
{
  return GetScriptDesc();
}

//------------------------------------------------------------------------------
// Address: 0x10037C50
// Name: struct ScriptClassDesc_t __near * GetScriptDesc(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ScriptClassDesc_t *__cdecl GetScriptDesc()
{
  return &g_C_BaseEntity_ScriptDesc;
}

//------------------------------------------------------------------------------
// Address: 0x10037C60
// Name: public: virtual struct datamap_t __near * C_BaseEntity::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_BaseEntity::GetPredDescMap(C_BaseEntity *this)
{
  return &C_BaseEntity::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10037C80
// Name: struct datamap_t __near * PredMapInit<class C_BaseEntity>(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__cdecl PredMapInit<C_BaseEntity>()
{
  if ( (_S7_3 & 1) == 0 )
  {
    _S7_3 |= 1u;
    predDesc[19].fieldSize = 1;
    predDesc[19].flags = 2;
    predDesc[20].fieldSize = 1;
    predDesc[18].fieldSize = 1;
    predDesc[20].flags = 2;
    predDesc[17].fieldTolerance = 0.0625;
    *(_QWORD *)predDesc[18].flatOffset = 0;
    predDesc[18].flags = 1280;
    predDesc[21].fieldSize = 1;
    *(_QWORD *)predDesc[17].flatOffset = 0;
    *(_QWORD *)predDesc[19].flatOffset = 0;
    *(_DWORD *)&predDesc[17].flatGroup = 0;
    predDesc[18].fieldType = FIELD_VECTOR;
    predDesc[18].fieldName = "m_angNetworkAngles";
    predDesc[18].fieldOffset = 288;
    predDesc[18].externalName = nullptr;
    predDesc[18].pSaveRestoreOps = nullptr;
    predDesc[18].inputFunc = nullptr;
    predDesc[18].td = nullptr;
    predDesc[18].fieldSizeInBytes = 12;
    predDesc[18].override_field = nullptr;
    predDesc[18].override_count = 0;
    predDesc[18].fieldTolerance = 0.0;
    *(_DWORD *)&predDesc[18].flatGroup = 0;
    predDesc[19].fieldType = FIELD_VECTOR;
    predDesc[19].fieldName = "m_vecAbsOrigin";
    predDesc[19].fieldOffset = 156;
    predDesc[19].externalName = nullptr;
    predDesc[19].pSaveRestoreOps = nullptr;
    predDesc[19].inputFunc = nullptr;
    predDesc[19].td = nullptr;
    predDesc[19].fieldSizeInBytes = 12;
    predDesc[19].override_field = nullptr;
    predDesc[19].override_count = 0;
    predDesc[19].fieldTolerance = 0.0;
    *(_DWORD *)&predDesc[19].flatGroup = 0;
    predDesc[20].fieldType = FIELD_VECTOR;
    predDesc[20].fieldName = "m_angAbsRotation";
    predDesc[20].fieldOffset = 192;
    predDesc[20].externalName = nullptr;
    predDesc[20].pSaveRestoreOps = nullptr;
    predDesc[20].inputFunc = nullptr;
    predDesc[20].td = nullptr;
    predDesc[20].fieldSizeInBytes = 12;
    predDesc[20].override_field = nullptr;
    predDesc[20].override_count = 0;
    predDesc[20].fieldTolerance = 0.0;
    *(_QWORD *)predDesc[20].flatOffset = 0;
    *(_DWORD *)&predDesc[20].flatGroup = 0;
    predDesc[21].fieldType = FIELD_VECTOR;
    predDesc[21].fieldName = "m_vecOrigin";
    predDesc[21].fieldOffset = 168;
    predDesc[21].flags = 2;
    predDesc[21].externalName = nullptr;
    predDesc[21].pSaveRestoreOps = nullptr;
    predDesc[21].inputFunc = nullptr;
    predDesc[21].td = nullptr;
    predDesc[21].fieldSizeInBytes = 12;
    predDesc[21].override_field = nullptr;
    predDesc[21].override_count = 0;
    predDesc[21].fieldTolerance = 0.0;
    predDesc[22].fieldSize = 1;
    predDesc[24].fieldSize = 1;
    *(_QWORD *)predDesc[21].flatOffset = 0;
    predDesc[22].flags = 2;
    predDesc[24].flags = 2;
    *(_QWORD *)predDesc[22].flatOffset = 0;
    predDesc[23].fieldSize = 1;
    predDesc[25].fieldSize = 1;
    *(_QWORD *)predDesc[23].flatOffset = 0;
    predDesc[23].flags = 2;
    predDesc[25].flags = 2;
    *(_QWORD *)predDesc[24].flatOffset = 0;
    *(_DWORD *)&predDesc[21].flatGroup = 0;
    predDesc[22].fieldType = FIELD_VECTOR;
    predDesc[22].fieldName = "m_angRotation";
    predDesc[22].fieldOffset = 204;
    predDesc[22].externalName = nullptr;
    predDesc[22].pSaveRestoreOps = nullptr;
    predDesc[22].inputFunc = nullptr;
    predDesc[22].td = nullptr;
    predDesc[22].fieldSizeInBytes = 12;
    predDesc[22].override_field = nullptr;
    predDesc[22].override_count = 0;
    predDesc[22].fieldTolerance = 0.0;
    *(_DWORD *)&predDesc[22].flatGroup = 0;
    predDesc[23].fieldType = FIELD_EHANDLE;
    predDesc[23].fieldName = "m_hGroundEntity";
    predDesc[23].fieldOffset = 324;
    predDesc[23].externalName = nullptr;
    predDesc[23].pSaveRestoreOps = nullptr;
    predDesc[23].inputFunc = nullptr;
    predDesc[23].td = nullptr;
    predDesc[23].fieldSizeInBytes = 4;
    predDesc[23].override_field = nullptr;
    predDesc[23].override_count = 0;
    predDesc[23].fieldTolerance = 0.0;
    *(_DWORD *)&predDesc[23].flatGroup = 0;
    predDesc[24].fieldType = FIELD_CHARACTER;
    predDesc[24].fieldName = "m_nWaterLevel";
    predDesc[24].fieldOffset = 594;
    predDesc[24].externalName = nullptr;
    predDesc[24].pSaveRestoreOps = nullptr;
    predDesc[24].inputFunc = nullptr;
    predDesc[24].td = nullptr;
    predDesc[24].fieldSizeInBytes = 1;
    predDesc[24].override_field = nullptr;
    predDesc[24].override_count = 0;
    predDesc[24].fieldTolerance = 0.0;
    *(_DWORD *)&predDesc[24].flatGroup = 0;
    predDesc[25].fieldType = FIELD_CHARACTER;
    predDesc[25].fieldName = "m_nWaterType";
    predDesc[25].fieldOffset = 228;
    predDesc[25].externalName = nullptr;
    predDesc[25].pSaveRestoreOps = nullptr;
    predDesc[25].inputFunc = nullptr;
    predDesc[25].td = nullptr;
    predDesc[25].fieldSizeInBytes = 1;
    predDesc[25].override_field = nullptr;
    predDesc[25].override_count = 0;
    predDesc[25].fieldTolerance = 0.0;
    *(_QWORD *)predDesc[25].flatOffset = 0;
    *(_DWORD *)&predDesc[25].flatGroup = 0;
    predDesc[26].fieldType = FIELD_VECTOR;
    predDesc[26].fieldName = "m_vecAngVelocity";
    predDesc[26].fieldOffset = 180;
    predDesc[26].fieldSize = 1;
    *(_QWORD *)predDesc[26].flatOffset = 0;
    *(_QWORD *)predDesc[27].flatOffset = 0;
    predDesc[27].fieldType = FIELD_VECTOR;
    *(_QWORD *)predDesc[28].flatOffset = 0;
    predDesc[26].fieldSizeInBytes = 12;
    predDesc[27].fieldSize = 1;
    predDesc[27].fieldSizeInBytes = 12;
    *(_QWORD *)predDesc[29].flatOffset = 0;
    predDesc[26].flags = 2;
    predDesc[26].externalName = nullptr;
    predDesc[26].pSaveRestoreOps = nullptr;
    predDesc[26].inputFunc = nullptr;
    predDesc[26].td = nullptr;
    predDesc[26].override_field = nullptr;
    predDesc[26].override_count = 0;
    predDesc[26].fieldTolerance = 0.0;
    *(_DWORD *)&predDesc[26].flatGroup = 0;
    predDesc[27].fieldName = "m_vecBaseVelocity";
    predDesc[27].fieldOffset = 276;
    predDesc[27].flags = 2;
    predDesc[27].externalName = nullptr;
    predDesc[27].pSaveRestoreOps = nullptr;
    predDesc[27].inputFunc = nullptr;
    predDesc[27].td = nullptr;
    predDesc[27].override_field = nullptr;
    predDesc[27].override_count = 0;
    predDesc[27].fieldTolerance = 0.0;
    *(_DWORD *)&predDesc[27].flatGroup = 0;
    predDesc[28].fieldType = FIELD_INTEGER;
    predDesc[28].fieldName = "m_iEFlags";
    predDesc[28].fieldOffset = 224;
    *(_DWORD *)&predDesc[28].fieldSize = 131073;
    predDesc[28].externalName = nullptr;
    predDesc[28].pSaveRestoreOps = nullptr;
    predDesc[28].inputFunc = nullptr;
    predDesc[28].td = nullptr;
    predDesc[28].fieldSizeInBytes = 4;
    predDesc[28].override_field = nullptr;
    predDesc[28].override_count = 0;
    predDesc[28].fieldTolerance = 0.0;
    *(_DWORD *)&predDesc[28].flatGroup = 0;
    predDesc[29].fieldType = FIELD_FLOAT;
    predDesc[29].fieldName = "m_flGravity";
    predDesc[29].fieldOffset = 216;
    *(_DWORD *)&predDesc[29].fieldSize = 131073;
    predDesc[29].externalName = nullptr;
    predDesc[29].pSaveRestoreOps = nullptr;
    predDesc[29].inputFunc = nullptr;
    predDesc[29].td = nullptr;
    predDesc[29].fieldSizeInBytes = 4;
    predDesc[29].override_field = nullptr;
    predDesc[29].override_count = 0;
    predDesc[29].fieldTolerance = 0.0;
    *(_DWORD *)&predDesc[29].flatGroup = 0;
    predDesc[30].fieldType = FIELD_FLOAT;
    predDesc[30].fieldName = "m_flProxyRandomValue";
    predDesc[30].fieldOffset = 220;
    *(_DWORD *)&predDesc[30].fieldSize = 131073;
    predDesc[30].externalName = nullptr;
    predDesc[30].pSaveRestoreOps = nullptr;
    predDesc[30].inputFunc = nullptr;
    predDesc[30].td = nullptr;
    predDesc[30].fieldSizeInBytes = 4;
    predDesc[30].override_field = nullptr;
    predDesc[30].override_count = 0;
    predDesc[30].fieldTolerance = 0.0;
    *(_QWORD *)predDesc[30].flatOffset = 0;
    *(_DWORD *)&predDesc[30].flatGroup = 0;
    predDesc[31].fieldType = FIELD_BOOLEAN;
    predDesc[31].fieldTolerance = 0.0;
    predDesc[31].fieldName = "m_bEverHadPredictionErrorsForThisCommand";
    predDesc[31].fieldOffset = 2344;
    *(_DWORD *)&predDesc[31].fieldSize = 131073;
    predDesc[31].externalName = nullptr;
    predDesc[31].pSaveRestoreOps = nullptr;
    predDesc[31].inputFunc = nullptr;
    predDesc[31].td = nullptr;
    predDesc[31].fieldSizeInBytes = 1;
    predDesc[31].override_field = nullptr;
    predDesc[31].override_count = 0;
    *(_QWORD *)predDesc[31].flatOffset = 0;
    *(_DWORD *)&predDesc[31].flatGroup = 0;
  }
  C_BaseEntity::m_PredMap.dataNumFields = 31;
  C_BaseEntity::m_PredMap.dataDesc = &predDesc[1];
  return &C_BaseEntity::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x100382D0
// Name: public: static void C_BaseEntity::SetAbsQueriesValid(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::SetAbsQueriesValid(bool bValid)
{
  if ( (unsigned __int8)_ThreadInMainThread() != 0 )
    C_BaseEntity::s_bAbsQueriesValid = bValid;
}

//------------------------------------------------------------------------------
// Address: 0x100382F0
// Name: public: static bool C_BaseEntity::IsAbsQueriesValid(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl C_BaseEntity::IsAbsQueriesValid()
{
  bool v0; // zf
  bool result; // al

  v0 = (unsigned __int8)_ThreadInMainThread() == 0;
  result = true;
  if ( !v0 )
    return C_BaseEntity::s_bAbsQueriesValid;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10038310
// Name: public: static void C_BaseEntity::PushEnableAbsRecomputations(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::PushEnableAbsRecomputations(bool bEnable)
{
  int v1; // ecx

  if ( (unsigned __int8)_ThreadInMainThread() != 0 && g_iAbsRecomputationStackPos < 8u )
  {
    v1 = g_iAbsRecomputationStackPos++;
    g_bAbsRecomputationStack[v1] = C_BaseEntity::s_bAbsRecomputationEnabled;
    C_BaseEntity::s_bAbsRecomputationEnabled = bEnable;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038350
// Name: public: static void C_BaseEntity::PopEnableAbsRecomputations(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl C_BaseEntity::PopEnableAbsRecomputations()
{
  if ( (unsigned __int8)_ThreadInMainThread() != 0 && g_iAbsRecomputationStackPos != 0 )
    C_BaseEntity::s_bAbsRecomputationEnabled = g_bAbsRecomputationStack[--g_iAbsRecomputationStackPos];
}

//------------------------------------------------------------------------------
// Address: 0x10038390
// Name: public: static void C_BaseEntity::EnableAbsRecomputations(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::EnableAbsRecomputations(bool bEnable)
{
  if ( (unsigned __int8)_ThreadInMainThread() != 0 )
    C_BaseEntity::s_bAbsRecomputationEnabled = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100383B0
// Name: public: static bool C_BaseEntity::IsAbsRecomputationsEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl C_BaseEntity::IsAbsRecomputationsEnabled()
{
  bool v0; // zf
  bool result; // al

  v0 = (unsigned __int8)_ThreadInMainThread() == 0;
  result = true;
  if ( !v0 )
    return C_BaseEntity::s_bAbsRecomputationEnabled;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100383D0
// Name: public: int C_BaseEntity::GetTextureFrameIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::GetTextureFrameIndex(C_BaseEntity *this)
{
  return this->m_iTextureFrameIndex;
}

//------------------------------------------------------------------------------
// Address: 0x100383E0
// Name: public: void C_BaseEntity::SetTextureFrameIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetTextureFrameIndex(C_BaseEntity *this, unsigned __int8 iIndex)
{
  this->m_iTextureFrameIndex = iIndex;
}

//------------------------------------------------------------------------------
// Address: 0x100383F0
// Name: public: virtual class IClientAlphaProperty __near * C_BaseEntity::GetClientAlphaProperty(void)
// Source: json
//------------------------------------------------------------------------------
CClientAlphaProperty *__thiscall C_BaseEntity::GetClientAlphaProperty(C_BaseEntity *this)
{
  return this->m_pClientAlphaProperty;
}

//------------------------------------------------------------------------------
// Address: 0x10038400
// Name: public: virtual void C_BaseEntity::SetRefEHandle(class CBaseHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetRefEHandle(C_BaseEntity *this, const CBaseHandle *handle)
{
  this->m_RefEHandle = (CBaseHandle)handle->m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x10038420
// Name: public: virtual class CBaseHandle const __near & C_BaseEntity::GetRefEHandle(void)const
// Source: json
//------------------------------------------------------------------------------
const CBaseHandle *__thiscall C_BaseEntity::GetRefEHandle(C_BaseEntity *this)
{
  return &this->m_RefEHandle;
}

//------------------------------------------------------------------------------
// Address: 0x10038430
// Name: public: virtual void C_BaseEntity::CreateModelInstance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::CreateModelInstance(C_BaseEntity *this)
{
  if ( LOWORD(this->m_flLastMessageTime) == 0xFFFF )
    LOWORD(this->m_flLastMessageTime) = modelrender->CreateInstance(
                                          this: modelrender,
                                          a2: this != (C_BaseEntity *)4 ? (IClientRenderable *)this : nullptr,
                                          a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10038470
// Name: public: void C_BaseEntity::SetRemovalFlag(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetRemovalFlag(C_BaseEntity *this, bool bRemove)
{
  if ( bRemove )
    this->m_iEFlags |= 1u;
  else
    this->m_iEFlags &= ~1u;
}

//------------------------------------------------------------------------------
// Address: 0x10038490
// Name: public: unsigned char C_BaseEntity::GetRenderAlpha(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall C_BaseEntity::GetRenderAlpha(C_BaseEntity *this)
{
  return this->m_pClientAlphaProperty->m_nAlpha;
}

//------------------------------------------------------------------------------
// Address: 0x100384A0
// Name: public: float C_BaseEntity::GetMinFadeDist(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseEntity::GetMinFadeDist(C_BaseEntity *this)
{
  return this->m_fadeMinDist;
}

//------------------------------------------------------------------------------
// Address: 0x100384B0
// Name: public: float C_BaseEntity::GetMaxFadeDist(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseEntity::GetMaxFadeDist(C_BaseEntity *this)
{
  return this->m_fadeMaxDist;
}

//------------------------------------------------------------------------------
// Address: 0x100384C0
// Name: public: float C_BaseEntity::GetGlobalFadeScale(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseEntity::GetGlobalFadeScale(C_BaseEntity *this)
{
  return this->m_flFadeScale;
}

//------------------------------------------------------------------------------
// Address: 0x100384D0
// Name: public: virtual bool C_BaseEntity::VPhysicsIsFlesh(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::VPhysicsIsFlesh(C_BaseEntity *this)
{
  int v1; // edi
  int v2; // esi
  int v3; // eax
  int material; // eax
  _DWORD v6[1024]; // [esp+8h] [ebp-1000h] BYREF

  v1 = this->VPhysicsGetObjectList(this, a2: (IPhysicsObject **)v6, a3: 1024);
  v2 = 0;
  if ( v1 <= 0 )
    return 0;
  while ( 1 )
  {
    v3 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v6[v2] + 152))(a1: v6[v2]);
    material = physprops->GetSurfaceData(this: physprops, a2: v3)->game.material;
    if ( material == 65 || material == 70 || material == 66 || material == 72 )
      break;
    if ( ++v2 >= v1 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10038550
// Name: public: void C_BaseEntity::RenderWithViewModels(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::RenderWithViewModels(C_BaseEntity *this, BOOL bEnable)
{
  this->m_bRenderWithViewModels = bEnable;
  g_pClientLeafSystem->RenderWithViewModels(this: g_pClientLeafSystem, a2: this->m_hRender, a3: bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x10038580
// Name: public: virtual class IClientModelRenderable __near * C_BaseEntity::GetClientModelRenderable(void)
// Source: json
//------------------------------------------------------------------------------
IClientThinkable *__thiscall C_BaseEntity::GetClientModelRenderable(C_BaseEntity *this)
{
  if ( LOBYTE(this->m_VisibilityBits.m_Ints[0]) != 0 && BYTE2(this->m_iEFlags) != 0 && this != (C_BaseEntity *)4 )
    return &this->IClientThinkable;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100385A0
// Name: public: virtual bool C_BaseEntity::GetRenderData(void __near *,enum ModelDataCategory_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::GetRenderData(C_BaseEntity *this, void *pData, ModelDataCategory_t nCategory)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100385B0
// Name: public: virtual void __near * C_BaseEntity::GetDataTableBasePtr(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_BaseEntity::GetDataTableBasePtr(C_BaseEntity *this)
{
  return (char *)this - 8;
}

//------------------------------------------------------------------------------
// Address: 0x100385C0
// Name: public: virtual bool C_BaseEntity::GetShadowCastDistance(float __near *,enum ShadowType_t)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::GetShadowCastDistance(C_BaseEntity *this, float *pDistance, ShadowType_t shadowType)
{
  float m_flElasticity; // xmm0_4

  m_flElasticity = this->m_flElasticity;
  if ( m_flElasticity == 0.0 )
    return 0;
  *pDistance = m_flElasticity;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100385F0
// Name: public: class CDiscontinuousInterpolatedVar<class QAngle> __near & C_BaseEntity::GetRotationInterpolator(void)
// Source: json
//------------------------------------------------------------------------------
CDiscontinuousInterpolatedVar<QAngle> *__thiscall C_BaseEntity::GetRotationInterpolator(C_BaseEntity *this)
{
  return &this->m_iv_angRotation;
}

//------------------------------------------------------------------------------
// Address: 0x10038600
// Name: public: class CDiscontinuousInterpolatedVar<class Vector> __near & C_BaseEntity::GetOriginInterpolator(void)
// Source: json
//------------------------------------------------------------------------------
CDiscontinuousInterpolatedVar<Vector> *__thiscall C_BaseEntity::GetOriginInterpolator(C_BaseEntity *this)
{
  return &this->m_iv_vecOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x10038620
// Name: public: virtual class Vector const __near & C_BaseEntity::GetRenderOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_BaseEntity::GetRenderOrigin(C_BaseEntity *this)
{
  return (*(const Vector *(__thiscall **)(char *))(*((_DWORD *)this - 1) + 40))(a1: (char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x10038630
// Name: public: virtual class QAngle const __near & C_BaseEntity::GetRenderAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall C_BaseEntity::GetRenderAngles(C_BaseEntity *this)
{
  return (*(const QAngle *(__thiscall **)(char *))(*((_DWORD *)this - 1) + 44))(a1: (char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x10038640
// Name: public: virtual void C_BaseEntity::GetShadowRenderBounds(class Vector __near &,class Vector __near &,enum ShadowType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::GetShadowRenderBounds(
        C_BaseEntity *this,
        Vector *mins,
        Vector *maxs,
        ShadowType_t shadowType)
{
  datamap_t *(__thiscall *GetPredDescMap)(C_BaseEntity *); // eax

  GetPredDescMap = this->GetPredDescMap;
  LOWORD(this->index) |= 1u;
  ((void (__thiscall *)(C_BaseEntity *, Vector *, Vector *))GetPredDescMap)(a1: this, a2: mins, a3: maxs);
  LOWORD(this->index) &= ~1u;
}

//------------------------------------------------------------------------------
// Address: 0x10038670
// Name: public: class Vector const __near & C_BaseEntity::GetNetworkOrigin(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_BaseEntity::GetNetworkOrigin(C_BaseEntity *this)
{
  return &this->m_vecNetworkOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x10038680
// Name: public: class QAngle const __near & C_BaseEntity::GetNetworkAngles(void)const
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall C_BaseEntity::GetNetworkAngles(C_BaseEntity *this)
{
  return &this->m_angNetworkAngles;
}

//------------------------------------------------------------------------------
// Address: 0x10038690
// Name: public: virtual struct model_t const __near * C_BaseEntity::GetModel(void)const
// Source: json
//------------------------------------------------------------------------------
const struct model_t *__thiscall C_BaseEntity::GetModel(C_BaseEntity *this)
{
  return *(const struct model_t **)&this->m_EntClientFlags;
}

//------------------------------------------------------------------------------
// Address: 0x100386A0
// Name: public: int C_BaseEntity::GetModelIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::GetModelIndex(C_BaseEntity *this)
{
  return this->m_nModelIndex;
}

//------------------------------------------------------------------------------
// Address: 0x100386B0
// Name: public: void C_BaseEntity::SetMoveCollide(enum MoveCollide_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetMoveCollide(C_BaseEntity *this, MoveCollide_t val)
{
  this->m_MoveCollide = val;
}

//------------------------------------------------------------------------------
// Address: 0x100386C0
// Name: public: virtual enum RenderableTranslucencyType_t C_BaseEntity::ComputeTranslucencyType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::ComputeTranslucencyType(C_BaseEntity *this)
{
  IVModelInfoClient_vtbl *v3; // ebx
  int v4; // eax
  int v5; // eax

  if ( this->m_bIsBlurred )
    return 1;
  v3 = modelinfo->__vftable;
  v4 = this->GetBody(this: &this->IClientRenderable);
  v5 = ((int (__thiscall *)(IClientRenderable *, int))this->GetSkin)(a1: &this->IClientRenderable, a2: v4);
  return ((int (__thiscall *)(IVModelInfoClient *, const struct model_t *, int))v3->ComputeTranslucencyType)(
           a1: modelinfo,
           a2: this->model,
           a3: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10038710
// Name: public: void C_BaseEntity::OnTranslucencyTypeChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::OnTranslucencyTypeChanged(C_BaseEntity *this)
{
  IClientLeafSystem_vtbl *v2; // edi
  RenderableTranslucencyType_t v3; // eax

  if ( this->m_hRender != 0xFFFF )
  {
    v2 = g_pClientLeafSystem->IClientLeafSystemEngine::__vftable;
    v3 = this->ComputeTranslucencyType(this);
    v2->SetTranslucencyType(this: g_pClientLeafSystem, a2: this->m_hRender, a3: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038750
// Name: public: virtual int C_BaseEntity::GetRenderFlags(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BaseEntity::GetRenderFlags(C_BaseEntity *this)
{
  const struct model_t *v1; // eax

  v1 = (const struct model_t *)this->GetClientThinkable(this);
  return v1 != nullptr && render->DoesBrushModelNeedPowerOf2Framebuffer(this: render, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10038780
// Name: public: virtual float __near * C_BaseEntity::GetRenderClipPlane(void)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall C_BaseEntity::GetRenderClipPlane(C_BaseEntity *this)
{
  if ( LOBYTE(this->m_fRenderingClipPlane[3]) != 0 )
    return (float *)&this->m_nCreationTick;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100387A0
// Name: public: virtual int C_BaseEntity::DrawBrushModel(bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::DrawBrushModel(
        C_BaseEntity *this,
        int bDrawingTranslucency,
        bool bShadowDepth,
        bool bTwoPass)
{
  IVRenderView_vtbl *v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  IVRenderView_vtbl *v9; // edi
  int v10; // eax
  int v11; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_BaseEntity::DrawBrushModel",
    a3: 0,
    a4: "Brush_Model_Rendering",
    a5: false,
    a6: 4);
  if ( bShadowDepth )
  {
    v5 = render->__vftable;
    v6 = ((int (__thiscall *)(C_BaseEntity *, int))this->GetAbsAngles)(a1: this, a2: bDrawingTranslucency);
    v7 = ((int (__thiscall *)(C_BaseEntity *, int))this->GetAbsOrigin)(a1: this, a2: v6);
    ((void (__thiscall *)(IVRenderView *, C_BaseEntity *, const struct model_t *, int))v5->DrawBrushModelShadowDepth)(
      a1: render,
      a2: this,
      a3: this->model,
      a4: v7);
  }
  else
  {
    v8 = 0;
    if ( bTwoPass )
    {
      LOBYTE(v8) = (_BYTE)bDrawingTranslucency != 0;
      ++v8;
    }
    v9 = render->__vftable;
    v10 = ((int (__thiscall *)(C_BaseEntity *, int))this->GetAbsAngles)(a1: this, a2: v8);
    v11 = ((int (__thiscall *)(C_BaseEntity *, int))this->GetAbsOrigin)(a1: this, a2: v10);
    ((void (__thiscall *)(IVRenderView *, C_BaseEntity *, const struct model_t *, int))v9->DrawBrushModelEx)(
      a1: render,
      a2: this,
      a3: this->model,
      a4: v11);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10038860
// Name: protected: void C_BaseEntity::MarkMessageReceived(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::MarkMessageReceived(C_BaseEntity *this)
{
  this->m_flLastMessageTime = engine->GetLastTimeStamp(this: engine);
}

//------------------------------------------------------------------------------
// Address: 0x10038880
// Name: public: virtual class Vector const __near & C_BaseEntity::GetOldOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_BaseEntity::GetOldOrigin(C_BaseEntity *this)
{
  return &this->m_vecOldOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x10038890
// Name: public: virtual int C_BaseEntity::GetEFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::GetEFlags(C_BaseEntity *this)
{
  return this->m_iEFlags;
}

//------------------------------------------------------------------------------
// Address: 0x100388A0
// Name: public: virtual void C_BaseEntity::SetEFlags(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetEFlags(C_BaseEntity *this, int iEFlags)
{
  this->m_iEFlags = iEFlags;
}

//------------------------------------------------------------------------------
// Address: 0x100388B0
// Name: public: virtual bool C_BaseEntity::IsSubModel(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::IsSubModel(C_BaseEntity *this)
{
  const struct model_t *model; // eax

  model = this->model;
  return model != nullptr
      && modelinfo->GetModelType(this: modelinfo, a2: model) == 1
      && *modelinfo->GetModelName(this: modelinfo, a2: this->model) == 42;
}

//------------------------------------------------------------------------------
// Address: 0x100388F0
// Name: public: virtual float C_BaseEntity::GetTextureAnimationStartTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseEntity::GetTextureAnimationStartTime(C_BaseEntity *this)
{
  return this->m_flSpawnTime;
}

//------------------------------------------------------------------------------
// Address: 0x10038900
// Name: public: virtual void C_BaseEntity::OnPreDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::OnPreDataChanged(C_BaseEntity *this, DataUpdateType_t type)
{
  char m_flFadeScale_low; // dl

  m_flFadeScale_low = LOBYTE(this->m_flFadeScale);
  this->m_pMovePeer.m_Index = LODWORD(this->m_vecNetworkOrigin.z);
  BYTE1(this->m_flFadeScale) = m_flFadeScale_low;
}

//------------------------------------------------------------------------------
// Address: 0x10038920
// Name: public: virtual class CClientThinkHandlePtr __near * C_BaseEntity::GetThinkHandle(void)
// Source: json
//------------------------------------------------------------------------------
struct CClientThinkHandlePtr *__thiscall C_BaseEntity::GetThinkHandle(C_BaseEntity *this)
{
  return (struct CClientThinkHandlePtr *)LODWORD(this->m_fadeMinDist);
}

//------------------------------------------------------------------------------
// Address: 0x10038930
// Name: public: virtual void C_BaseEntity::SetThinkHandle(class CClientThinkHandlePtr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetThinkHandle(C_BaseEntity *this, struct CClientThinkHandlePtr *hThink)
{
  LODWORD(this->m_fadeMinDist) = hThink;
}

//------------------------------------------------------------------------------
// Address: 0x10038940
// Name: public: bool C_BaseEntity::IsBrushModel(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BaseEntity::IsBrushModel(C_BaseEntity *this)
{
  return modelinfo->GetModelType(this: modelinfo, a2: this->model) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x10038960
// Name: private: void C_BaseEntity::AddBrushModelDecal(struct Ray_t const __near &,class Vector const __near &,int,bool,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::AddBrushModelDecal(
        C_BaseEntity *this,
        const Ray_t *ray,
        const Vector *decalCenter,
        int decalIndex,
        bool doTrace,
        CGameTrace *tr)
{
  IVEfx_vtbl *v7; // edi
  int v8; // eax
  int v9; // eax
  Vector vecNormal; // [esp+8h] [ebp-Ch] BYREF

  if ( doTrace )
  {
    enginetrace->ClipRayToEntity(this: enginetrace, a2: ray, a3: 1174421507u, a4: this, a5: tr);
    if ( tr->fraction == 1.0 )
      return;
    vecNormal = tr->plane.normal;
  }
  else
  {
    vecNormal = ray->m_Delta.Vector;
    VectorNormalize(vec: &vecNormal);
    vecNormal.x = vecNormal.x * -1.0;
    vecNormal.y = vecNormal.y * -1.0;
    vecNormal.z = vecNormal.z * -1.0;
  }
  v7 = effects->__vftable;
  v8 = ((int (__thiscall *)(C_BaseEntity *, const Vector *, _DWORD, _DWORD, Vector *))this->GetAbsAngles)(
         a1: this,
         a2: decalCenter,
         a3: 0,
         a4: 0,
         a5: &vecNormal);
  v9 = ((int (__thiscall *)(C_BaseEntity *, int))this->GetAbsOrigin)(a1: this, a2: v8);
  ((void (__thiscall *)(IVEfx *, int, int, const struct model_t *, int))v7->DecalShoot)(
    a1: effects,
    a2: decalIndex,
    a3: this->index,
    a4: this->model,
    a5: v9);
}

//------------------------------------------------------------------------------
// Address: 0x10038A70
// Name: public: static void __near * C_BaseEntity::operator new(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl C_BaseEntity::operator new(unsigned int stAllocateBlock)
{
  void *v1; // esi

  v1 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: stAllocateBlock);
  memset(dst: (int)v1, value: nullptr, count: stAllocateBlock);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10038AA0
// Name: public: static void C_BaseEntity::operator delete(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::operator delete(void *pMem)
{
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pMem);
}

//------------------------------------------------------------------------------
// Address: 0x10038AC0
// Name: public: virtual class C_Team __near * C_BaseEntity::GetTeam(void)
// Source: json
//------------------------------------------------------------------------------
C_Team *__thiscall C_BaseEntity::GetTeam(C_BaseEntity *this)
{
  return GetGlobalTeam(iTeamNumber: this->m_iTeamNum);
}

//------------------------------------------------------------------------------
// Address: 0x10038AD0
// Name: public: virtual int C_BaseEntity::GetTeamNumber(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::GetTeamNumber(C_BaseEntity *this)
{
  return this->m_iTeamNum;
}

//------------------------------------------------------------------------------
// Address: 0x10038AE0
// Name: public: virtual int C_BaseEntity::GetRenderTeamNumber(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::GetRenderTeamNumber(C_BaseEntity *this)
{
  return this->GetTeamNumber(this);
}

//------------------------------------------------------------------------------
// Address: 0x10038AF0
// Name: public: virtual bool C_BaseEntity::InSameTeam(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::InSameTeam(C_BaseEntity *this, C_BaseEntity *pEntity)
{
  C_Team *v4; // edi

  if ( pEntity == nullptr )
    return false;
  v4 = pEntity->GetTeam(this: pEntity);
  return v4 == this->GetTeam(this);
}

//------------------------------------------------------------------------------
// Address: 0x10038B30
// Name: public: virtual bool C_BaseEntity::InLocalTeam(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::InLocalTeam(C_BaseEntity *this)
{
  C_Team *v1; // esi

  v1 = this->GetTeam(this);
  return v1 == GetLocalTeam();
}

//------------------------------------------------------------------------------
// Address: 0x10038B50
// Name: public: void C_BaseEntity::DestroyShadow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::DestroyShadow(C_BaseEntity *this)
{
  int m_ShadowHandle; // eax

  m_ShadowHandle = this->m_ShadowHandle;
  if ( (_WORD)m_ShadowHandle != 0xFFFF )
  {
    g_pClientShadowMgr->DestroyShadow(this: g_pClientShadowMgr, a2: m_ShadowHandle);
    this->m_ShadowHandle = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038B80
// Name: public: class Vector const __near & C_BaseEntity::GetLocalOrigin(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_BaseEntity::GetLocalOrigin(C_BaseEntity *this)
{
  return &this->m_vecOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x10038B90
// Name: public: float C_BaseEntity::GetLocalOriginDim(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseEntity::GetLocalOriginDim(C_BaseEntity *this, int iDim)
{
  return *(&this->m_vecOrigin.x + iDim);
}

//------------------------------------------------------------------------------
// Address: 0x10038BB0
// Name: public: void C_BaseEntity::SetLocalOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetLocalOrigin(C_BaseEntity *this, const Vector *origin)
{
  if ( origin->x != this->m_vecOrigin.x || origin->y != this->m_vecOrigin.y || origin->z != this->m_vecOrigin.z )
  {
    C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 1);
    this->m_vecOrigin = *origin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038C20
// Name: public: void C_BaseEntity::SetLocalOriginDim(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetLocalOriginDim(C_BaseEntity *this, int iDim, float flValue)
{
  if ( *(&this->m_vecOrigin.x + iDim) != flValue )
  {
    C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 1);
    *(&this->m_vecOrigin.x + iDim) = flValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038C60
// Name: public: class QAngle const __near & C_BaseEntity::GetLocalAngles(void)const
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall C_BaseEntity::GetLocalAngles(C_BaseEntity *this)
{
  return &this->m_angRotation;
}

//------------------------------------------------------------------------------
// Address: 0x10038C70
// Name: public: float C_BaseEntity::GetLocalAnglesDim(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseEntity::GetLocalAnglesDim(C_BaseEntity *this, int iDim)
{
  return *(&this->m_angRotation.x + iDim);
}

//------------------------------------------------------------------------------
// Address: 0x10038C90
// Name: public: void C_BaseEntity::SetLocalAngles(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetLocalAngles(C_BaseEntity *this, const QAngle *angles)
{
  if ( angles->x != this->m_angRotation.x || angles->y != this->m_angRotation.y || angles->z != this->m_angRotation.z )
  {
    C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 2);
    this->m_angRotation = *angles;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038D00
// Name: public: void C_BaseEntity::SetLocalAnglesDim(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetLocalAnglesDim(C_BaseEntity *this, int iDim, float flValue)
{
  long double v4; // st7
  float flValuea; // [esp+18h] [ebp+Ch]

  v4 = AngleNormalize(angle: flValue);
  if ( *(&this->m_angRotation.x + iDim) != v4 )
  {
    C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 2);
    flValuea = v4;
    *(&this->m_angRotation.x + iDim) = flValuea;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038D50
// Name: public: void C_BaseEntity::SetLocalVelocity(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetLocalVelocity(C_BaseEntity *this, const Vector *vecVelocity)
{
  if ( vecVelocity->x != this->m_vecVelocity.x
    || vecVelocity->y != this->m_vecVelocity.y
    || vecVelocity->z != this->m_vecVelocity.z )
  {
    C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 4);
    this->m_vecVelocity = *vecVelocity;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038DC0
// Name: public: void C_BaseEntity::SetLocalAngularVelocity(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetLocalAngularVelocity(C_BaseEntity *this, const QAngle *vecAngVelocity)
{
  if ( vecAngVelocity->x != this->m_vecAngVelocity.x
    || vecAngVelocity->y != this->m_vecAngVelocity.y
    || vecAngVelocity->z != this->m_vecAngVelocity.z )
  {
    this->m_vecAngVelocity = *vecAngVelocity;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038E20
// Name: public: virtual void C_BaseEntity::BoneMergeFastCullBloat(class Vector __near &,class Vector __near &,class Vector const __near &,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::BoneMergeFastCullBloat(
        C_BaseEntity *this,
        Vector *localMins,
        Vector *localMaxs,
        const Vector *thisEntityMins,
        const Vector *thisEntityMaxs)
{
  float v5; // [esp-10h] [ebp-1Ch]

  v5 = fsqrt(
         (float)((float)((float)(thisEntityMaxs->y - thisEntityMins->y) * (float)(thisEntityMaxs->y - thisEntityMins->y))
               + (float)((float)(thisEntityMaxs->z - thisEntityMins->z) * (float)(thisEntityMaxs->z - thisEntityMins->z)))
       + (float)((float)(thisEntityMaxs->x - thisEntityMins->x) * (float)(thisEntityMaxs->x - thisEntityMins->x)));
  localMins->x = localMins->x - v5;
  localMins->y = localMins->y - v5;
  localMins->z = localMins->z - v5;
  localMaxs->x = localMaxs->x + v5;
  localMaxs->y = v5 + localMaxs->y;
  localMaxs->z = v5 + localMaxs->z;
}

//------------------------------------------------------------------------------
// Address: 0x10038EF0
// Name: public: bool C_BaseEntity::GetPredictable(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::GetPredictable(C_BaseEntity *this)
{
  return this->m_bPredictable;
}

//------------------------------------------------------------------------------
// Address: 0x10038F00
// Name: public: static int C_BaseEntity::PrecacheModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl C_BaseEntity::PrecacheModel(const char *name)
{
  return modelinfo->GetModelIndex(this: modelinfo, a2: name);
}

//------------------------------------------------------------------------------
// Address: 0x10038F20
// Name: public: bool C_BaseEntity::GetPredictionEligible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::GetPredictionEligible(C_BaseEntity *this)
{
  return this->m_bPredictionEligible;
}

//------------------------------------------------------------------------------
// Address: 0x10038F30
// Name: public: char const __near * C_BaseEntity::GetClassname(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall C_BaseEntity::GetClassname(C_BaseEntity *this)
{
  ClientClass *v2; // eax
  char *result; // eax
  CClassMap *ClassMap; // ebx
  CClassMap_vtbl *v5; // esi
  datamap_t *v6; // eax
  const char *v7; // eax
  type_info *v8; // eax
  const char *v9; // eax

  outstr[0] = 0;
  v2 = this->GetClientClass(this: &this->IClientNetworkable);
  if ( v2 == nullptr || (result = (char *)v2->m_pMapClassname) == nullptr )
  {
    if ( this->GetPredDescMap(this) != nullptr
      && (ClassMap = GetClassMap(),
          v5 = ClassMap->__vftable,
          v6 = this->GetPredDescMap(this),
          (v7 = v5->Lookup(this: ClassMap, a2: v6->dataClassName)) != nullptr)
      && *v7 != 0 )
    {
      V_strncpy(pDest: outstr, pSrc: v7, maxLen: 256);
    }
    else
    {
      v8 = (type_info *)__RTtypeid(inptr: this);
      v9 = type_info::name(this: v8, __ptype_info_node: &__type_info_root_node);
      V_strncpy(pDest: outstr, pSrc: v9, maxLen: 256);
    }
    return outstr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10038FC0
// Name: public: char const __near * C_BaseEntity::GetDebugName(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
char *__thiscall C_BaseEntity::GetDebugName(C_BaseEntity *this)
{
  return C_BaseEntity::GetClassname(this);
}

//------------------------------------------------------------------------------
// Address: 0x10038FD0
// Name: class C_BaseEntity __near * CreateEntityByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CreateEntityByName(const char *className)
{
  IClassMap *ClassMap; // eax
  C_BaseEntity *result; // eax

  ClassMap = GetClassMap();
  result = ClassMap->CreateEntity(this: ClassMap, a2: className);
  if ( result == nullptr )
  {
    _Warning(a1: "Can't find factory for entity: %s\n", className);
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039000
// Name: public: virtual void C_BaseEntity::ChangeTeam(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::ChangeTeam(C_BaseEntity *this, int iTeamNum)
{
  this->m_iTeamNum = iTeamNum;
}

//------------------------------------------------------------------------------
// Address: 0x10039010
// Name: public: void C_BaseEntity::SetModelName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetModelName(C_BaseEntity *this, const char *name)
{
  this->m_ModelName = name;
}

//------------------------------------------------------------------------------
// Address: 0x10039020
// Name: public: char const __near * C_BaseEntity::GetModelName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_BaseEntity::GetModelName(C_BaseEntity *this)
{
  return this->m_ModelName;
}

//------------------------------------------------------------------------------
// Address: 0x10039030
// Name: public: void C_BaseEntity::SetPredictionEligible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetPredictionEligible(C_BaseEntity *this, bool canpredict)
{
  this->m_bPredictionEligible = canpredict;
}

//------------------------------------------------------------------------------
// Address: 0x10039040
// Name: public: bool C_BaseEntity::IsIntermediateDataAllocated(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::IsIntermediateDataAllocated(C_BaseEntity *this)
{
  return this->m_pOriginalData != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10039050
// Name: public: void C_BaseEntity::DestroyIntermediateData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::DestroyIntermediateData(C_BaseEntity *this)
{
  void **m_pIntermediateData; // esi
  int i; // edi
  void **m_pIntermediateData_FirstPredicted; // esi
  int j; // edi

  if ( this->m_pOriginalData != nullptr )
  {
    m_pIntermediateData = (void **)this->m_pIntermediateData;
    for ( i = 150; i != 0; --i )
    {
      C_BaseEntity::operator delete(pMem: *m_pIntermediateData);
      *m_pIntermediateData++ = nullptr;
    }
    m_pIntermediateData_FirstPredicted = (void **)this->m_pIntermediateData_FirstPredicted;
    if ( this->m_pIntermediateData_FirstPredicted[0] != nullptr )
    {
      for ( j = 151; j != 0; --j )
      {
        C_BaseEntity::operator delete(pMem: *m_pIntermediateData_FirstPredicted);
        *m_pIntermediateData_FirstPredicted++ = nullptr;
      }
    }
    C_BaseEntity::operator delete(pMem: this->m_pOriginalData);
    this->m_pOriginalData = nullptr;
    this->m_nIntermediateDataCount = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100390E0
// Name: public: void C_BaseEntity::ShiftIntermediateDataForward(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::ShiftIntermediateDataForward(
        C_BaseEntity *this,
        int slots_to_remove,
        int number_of_commands_run)
{
  unsigned __int8 **m_pIntermediateData; // esi
  int v5; // ecx
  int v6; // eax
  unsigned __int8 **v7; // esi
  unsigned __int8 **v8; // edi
  int v9; // eax
  unsigned __int8 *saved[150]; // [esp+4h] [ebp-258h] BYREF

  m_pIntermediateData = this->m_pIntermediateData;
  if ( this != (C_BaseEntity *)-1128 )
  {
    v5 = 0;
    if ( slots_to_remove > 0 )
    {
      qmemcpy(saved, m_pIntermediateData, 4 * slots_to_remove);
      v5 = slots_to_remove;
    }
    v6 = number_of_commands_run;
    if ( v5 < number_of_commands_run )
    {
      v7 = &this->m_pIntermediateData[v5];
      v8 = &this->m_pIntermediateData[v5 - slots_to_remove];
      v9 = number_of_commands_run - v5;
      do
      {
        *v8++ = *v7++;
        --v9;
      }
      while ( v9 != 0 );
      v6 = number_of_commands_run;
    }
    if ( slots_to_remove > 0 )
      qmemcpy(&this->m_pIntermediateData[v6 - slots_to_remove], saved, 4 * slots_to_remove);
    this->m_nIntermediateDataCount -= slots_to_remove;
    if ( this->m_nIntermediateDataCount < -1 )
      this->m_nIntermediateDataCount = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039180
// Name: public: void C_BaseEntity::ShiftFirstPredictedIntermediateDataForward(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::ShiftFirstPredictedIntermediateDataForward(C_BaseEntity *this, int slots_to_remove)
{
  int v3; // eax
  int v4; // eax
  unsigned __int8 **v5; // ecx
  unsigned __int8 **v6; // esi
  unsigned __int8 *saved_FirstPredicted[151]; // [esp+4h] [ebp-25Ch] BYREF

  if ( this->m_pIntermediateData_FirstPredicted[0] != nullptr )
  {
    v3 = this->m_nIntermediateData_FirstPredictedShiftMarker;
    if ( v3 != -1 )
    {
      if ( v3 > slots_to_remove )
      {
        v4 = 0;
        if ( slots_to_remove > 0 )
        {
          qmemcpy(saved_FirstPredicted, this->m_pIntermediateData_FirstPredicted, 4 * slots_to_remove);
          v4 = slots_to_remove;
        }
        if ( v4 <= this->m_nIntermediateData_FirstPredictedShiftMarker )
        {
          v5 = &this->m_pIntermediateData_FirstPredicted[v4];
          v6 = &this->m_pIntermediateData_FirstPredicted[v4 - slots_to_remove];
          do
          {
            *v6 = *v5;
            ++v4;
            ++v5;
            ++v6;
          }
          while ( v4 <= this->m_nIntermediateData_FirstPredictedShiftMarker );
        }
        if ( slots_to_remove > 0 )
          qmemcpy(
            &this->m_pIntermediateData_FirstPredicted[this->m_nIntermediateData_FirstPredictedShiftMarker
                                                    - slots_to_remove
                                                    + 1],
            saved_FirstPredicted,
            4 * slots_to_remove);
        this->m_nIntermediateData_FirstPredictedShiftMarker -= slots_to_remove;
      }
      else
      {
        this->m_nIntermediateData_FirstPredictedShiftMarker = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039240
// Name: public: void __near * C_BaseEntity::GetPredictedFrame(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall C_BaseEntity::GetPredictedFrame(C_BaseEntity *this, unsigned int framenumber)
{
  if ( this->m_pOriginalData != nullptr )
    return this->m_pIntermediateData[framenumber % 0x96];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10039280
// Name: public: void __near * C_BaseEntity::GetFirstPredictedFrame(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall C_BaseEntity::GetFirstPredictedFrame(C_BaseEntity *this, unsigned int framenumber)
{
  return this->m_pIntermediateData_FirstPredicted[framenumber % 0x97];
}

//------------------------------------------------------------------------------
// Address: 0x100392B0
// Name: public: void __near * C_BaseEntity::GetOriginalNetworkDataObject(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall C_BaseEntity::GetOriginalNetworkDataObject(C_BaseEntity *this)
{
  return this->m_pOriginalData;
}

//------------------------------------------------------------------------------
// Address: 0x100392C0
// Name: private: int C_BaseEntity::GetIntermediateDataSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::GetIntermediateDataSize(C_BaseEntity *this)
{
  datamap_t *v2; // eax
  int result; // eax

  v2 = this->GetPredDescMap(this);
  if ( v2 != nullptr && v2->m_pOptimizedDataMap == nullptr )
    CPredictionCopy::PrepareDataMap(dmap: v2);
  result = this->GetPredDescMap(this)->m_nPackedSize;
  if ( result <= 4 )
    return 4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039330
// Name: public: virtual struct datamap_t __near * C_BaseEntity::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_BaseEntity::GetDataDescMap(C_BaseEntity *this)
{
  return &C_BaseEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10039340
// Name: public: virtual void C_BaseEntity::SetClassname(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetClassname(C_BaseEntity *this, const char *className)
{
  this->m_iClassname = className;
}

//------------------------------------------------------------------------------
// Address: 0x10039350
// Name: public: class C_AI_BaseNPC __near * C_BaseEntity::MyNPCPointer(void)
// Source: json
//------------------------------------------------------------------------------
C_AI_BaseNPC *__thiscall C_BaseEntity::MyNPCPointer(C_BaseEntity *this)
{
  return this->IsNPC(this) ? (C_AI_BaseNPC *)this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10039370
// Name: private: static void C_BaseEntity::ToolRecordEntities(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl C_BaseEntity::ToolRecordEntities()
{
  int v0; // edi
  int i; // esi
  IClientRenderable *v2; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_BaseEntity::ToolRecordEnties",
    a3: 0,
    a4: "Tools",
    a5: false,
    a6: 4);
  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
  {
    v0 = recordinglist->Count(this: recordinglist);
    for ( i = 0; i < v0; ++i )
    {
      v2 = recordinglist->Get(this: recordinglist, a2: i);
      if ( v2 != nullptr )
        v2->RecordToolMessage(this: v2);
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10039400
// Name: public: virtual bool C_BaseEntity::PreRender(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::PreRender(C_BaseEntity *this, int nSplitScreenPlayerSlot)
{
  return this->CreateLightEffects(this);
}

//------------------------------------------------------------------------------
// Address: 0x10039420
// Name: public: bool C_BaseEntity::IsViewEntity(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::IsViewEntity(C_BaseEntity *this)
{
  IVRenderView_vtbl *v1; // esi
  int v2; // eax

  v1 = render->__vftable;
  v2 = this->entindex(this: &this->IClientNetworkable);
  return v1->IsViewEntity(this: render, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10039450
// Name: public: bool C_BaseEntity::IsAbleToHaveFireEffect(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::IsAbleToHaveFireEffect(C_BaseEntity *this)
{
  return !UTIL_IsLowViolence();
}

//------------------------------------------------------------------------------
// Address: 0x10039460
// Name: public: virtual bool C_BaseEntity::IsBlurred(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::IsBlurred(C_BaseEntity *this)
{
  return this->m_bIsBlurred;
}

//------------------------------------------------------------------------------
// Address: 0x10039470
// Name: public: bool C_BaseEntity::SetCellBits(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::SetCellBits(C_BaseEntity *this, int cellbits)
{
  if ( this->m_cellbits == cellbits )
    return 0;
  this->m_cellbits = cellbits;
  this->m_cellwidth = 1 << cellbits;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100394A0
// Name: public: char const __near * CCommand::operator[](int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCommand::operator[](CCommand *this, int nIndex)
{
  if ( nIndex < 0 || nIndex >= this->m_nArgc )
    return prType;
  else
    return this->m_ppArgv[nIndex];
}

//------------------------------------------------------------------------------
// Address: 0x100394F0
// Name: public: int CGlobalVarsBase::GetNetworkBase(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGlobalVarsBase::GetNetworkBase(CGlobalVarsBase *this, int nTick, int nEntity)
{
  return this->nTimestampNetworkingBase
       * ((nTick - nEntity % this->nTimestampRandomizeWindow)
        / this->nTimestampNetworkingBase);
}

//------------------------------------------------------------------------------
// Address: 0x10039510
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Push(struct TSLNodeBase_t __near *)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Push(CTSListBase *this, TSLNodeBase_t *pNode)
{
  TSLNodeBase_t *Next; // edi
  int DepthAndSequence; // [esp-4h] [ebp-10h]
  int v6; // [esp-4h] [ebp-10h]

  Next = this->m_Head.value.Next;
  DepthAndSequence = this->m_Head.value32.DepthAndSequence;
  pNode->Next = this->m_Head.value.Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: this,
                          a2: pNode,
                          a3: DepthAndSequence + 65537,
                          a4: Next,
                          a5: DepthAndSequence) == 0 )
  {
    do
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      v6 = this->m_Head.value32.DepthAndSequence;
      pNode->Next = this->m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNode, a3: v6 + 65537, a4: Next, a5: v6) == 0 );
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x10039570
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Pop(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Pop(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  Next = this->m_Head.value.Next;
  DepthAndSequence = this->m_Head.value32.DepthAndSequence;
  if ( this->m_Head.value.Next == nullptr )
    return nullptr;
  while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                             a1: this,
                             a2: Next->Next,
                             a3: DepthAndSequence - 1,
                             a4: Next,
                             a5: DepthAndSequence) == 0 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      return nullptr;
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x100395B0
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Detach(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Detach(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi

  while ( 1 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    if ( this->m_Head.value.Next == nullptr )
      break;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: this,
                            a2: 0,
                            a3: this->m_Head.value32.DepthAndSequence & 0xFFFF0000,
                            a4: Next,
                            a5: this->m_Head.value32.DepthAndSequence) != 0 )
      return Next;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10039810
// Name: void RecvProxy_AnimTime(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_AnimTime(const CRecvProxyData *pData, char *pStruct)
{
  int v2; // eax
  int t; // [esp+8h] [ebp-10h]
  int addt; // [esp+10h] [ebp-8h]

  addt = pData->m_Value.m_Int;
  v2 = (*(int (__thiscall **)(char *))(*((_DWORD *)pStruct + 2) + 40))(a1: pStruct + 8);
  for ( t = addt
          + CGlobalVarsBase::GetNetworkBase(
              this: (CGlobalVarsBase *)gpGlobals.m_Index,
              nTick: *(_DWORD *)(gpGlobals.m_Index + 24),
              nEntity: v2); t < *(_DWORD *)(gpGlobals.m_Index + 24) - 127; t += 256 )
    ;
  while ( t > *(_DWORD *)(gpGlobals.m_Index + 24) + 127 )
    t -= 256;
  *((float *)pStruct + 149) = (float)t * *(float *)(gpGlobals.m_Index + 28);
}

//------------------------------------------------------------------------------
// Address: 0x100398D0
// Name: public: static void C_BaseEntity::RecvProxy_CellBits(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::RecvProxy_CellBits(const CRecvProxyData *pData, C_BaseEntity *pStruct)
{
  if ( C_BaseEntity::SetCellBits(this: pStruct, cellbits: pData->m_Value.m_Int) != 0
    && pStruct->ShouldRegenerateOriginFromCellBits(this: pStruct) )
  {
    pStruct->m_vecNetworkOrigin.x = CoordFromCell(
                                      cellwidth: pStruct->m_cellwidth,
                                      cell: pStruct->m_cellX,
                                      f: pStruct->m_vecCellOrigin.x);
    pStruct->m_vecNetworkOrigin.y = CoordFromCell(
                                      cellwidth: pStruct->m_cellwidth,
                                      cell: pStruct->m_cellY,
                                      f: pStruct->m_vecCellOrigin.y);
    pStruct->m_vecNetworkOrigin.z = CoordFromCell(
                                      cellwidth: pStruct->m_cellwidth,
                                      cell: pStruct->m_cellZ,
                                      f: pStruct->m_vecCellOrigin.z);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100399B0
// Name: void RecvProxy_LocalVelocity(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_LocalVelocity(const CRecvProxyData *pData, C_BaseEntity *pStruct)
{
  Vector vecVelocity; // [esp+0h] [ebp-10h] BYREF
  C_BaseEntity *pEnt; // [esp+Ch] [ebp-4h]

  pEnt = pStruct;
  C_BasePlayer::ActivePlayerCombatCharacter(this: (CChoreoActor *)&vecVelocity);
  vecVelocity = (Vector)pData->m_Value.___u0;
  C_BaseEntity::SetLocalVelocity(this: pEnt, &vecVelocity);
}

//------------------------------------------------------------------------------
// Address: 0x10039A00
// Name: RecvProxy_MoveCollide
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_MoveCollide(const CRecvProxyData *pData, _BYTE *pStruct)
{
  pStruct[593] = LOBYTE(pData->m_Value.m_Float);
}

//------------------------------------------------------------------------------
// Address: 0x10039A90
// Name: public: void C_BaseEntity::SetDistanceFade(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetDistanceFade(C_BaseEntity *this, float flMinDist, float flMaxDist)
{
  CClientAlphaProperty *m_pClientAlphaProperty; // ecx

  m_pClientAlphaProperty = this->m_pClientAlphaProperty;
  this->m_fadeMinDist = flMinDist;
  this->m_fadeMaxDist = flMaxDist;
  ((void (__thiscall *)(CClientAlphaProperty *, _DWORD, _DWORD, _DWORD))m_pClientAlphaProperty->SetFade)(
    a1: m_pClientAlphaProperty,
    a2: LODWORD(this->m_flFadeScale),
    a3: LODWORD(flMinDist),
    a4: LODWORD(flMaxDist));
}

//------------------------------------------------------------------------------
// Address: 0x10039AE0
// Name: public: void C_BaseEntity::SetGlobalFadeScale(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_BaseEntity::SetGlobalFadeScale(
        C_BaseEntity *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        float flFadeScale)
{
  const struct model_t *model; // edx
  IMDLCache *v6; // ebx
  unsigned __int16 v7; // ax

  model = this->model;
  this->m_flFadeScale = flFadeScale;
  if ( ((int (__thiscall *)(IVModelInfoClient *, const struct model_t *, int))modelinfo->GetModelType)(
         a1: modelinfo,
         a2: model,
         a3: a2) == 3 )
  {
    v6 = mdlcache;
    mdlcache->BeginLock(this: mdlcache);
    v7 = modelinfo->GetCacheHandle(this: modelinfo, a2: this->model);
    if ( v7 != 0xFFFF )
    {
      if ( (*(_DWORD *)(((int (__thiscall *)(IMDLCache *, _DWORD, int))mdlcache->LockStudioHdr)(
                          a1: mdlcache,
                          a2: v7,
                          a3)
                      + 152)
          & 0x800) != 0 )
        flFadeScale = 0.0;
      ((void (__thiscall *)(IMDLCache *))mdlcache->UnlockStudioHdr)(a1: mdlcache);
    }
    v6->EndLock(this: v6);
  }
  ((void (__thiscall *)(CClientAlphaProperty *, _DWORD, _DWORD))this->m_pClientAlphaProperty->SetFade)(
    a1: this->m_pClientAlphaProperty,
    a2: LODWORD(flFadeScale),
    a3: LODWORD(this->m_fadeMinDist));
}

//------------------------------------------------------------------------------
// Address: 0x10039BC0
// Name: public: virtual int C_BaseEntity::VPhysicsGetObjectList(class IPhysicsObject __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::VPhysicsGetObjectList(C_BaseEntity *this, IPhysicsObject **pList, int listMax)
{
  IPhysicsObject *m_pPhysicsObject; // eax

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject == nullptr || listMax <= 0 )
    return 0;
  *pList = m_pPhysicsObject;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10039BF0
// Name: public: virtual void C_BaseEntity::VPhysicsCompensateForPredictionErrors(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::VPhysicsCompensateForPredictionErrors(
        C_BaseEntity *this,
        const unsigned __int8 *predicted_state_data)
{
  IPhysicsObject *m_pPhysicsObject; // ecx
  int v4; // edi
  const datamap_t *v5; // eax
  const typedescription_t *FlatFieldByName; // eax
  datamap_t *(__thiscall *GetPredDescMap)(C_BaseEntity *); // eax
  const datamap_t *v8; // eax
  const typedescription_t *v9; // eax
  void (__thiscall *v10)(int, Vector *); // edx
  Vector vVelocityDelta; // [esp+4h] [ebp-30h] BYREF
  Vector vOriginDelta; // [esp+10h] [ebp-24h] BYREF
  Vector vPredictedVelocity; // [esp+1Ch] [ebp-18h] BYREF
  Vector vPredictedOrigin; // [esp+28h] [ebp-Ch] BYREF

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
  {
    v4 = (int)m_pPhysicsObject->GetPredictedInterface(this: m_pPhysicsObject);
    if ( v4 != 0 )
    {
      v5 = this->GetPredDescMap(this);
      FlatFieldByName = CPredictionCopy::FindFlatFieldByName(fieldname: "m_vecNetworkOrigin", dmap: v5);
      _V_memcpy(dest: (void *)&vPredictedOrigin, src: &predicted_state_data[FlatFieldByName->flatOffset[1]], count: 12);
      GetPredDescMap = this->GetPredDescMap;
      vOriginDelta.x = this->m_vecNetworkOrigin.x - vPredictedOrigin.x;
      vOriginDelta.y = this->m_vecNetworkOrigin.y - vPredictedOrigin.y;
      vOriginDelta.z = this->m_vecNetworkOrigin.z - vPredictedOrigin.z;
      v8 = GetPredDescMap(this);
      v9 = CPredictionCopy::FindFlatFieldByName(fieldname: "m_vecAbsVelocity", dmap: v8);
      _V_memcpy(dest: (void *)&vPredictedVelocity, src: &predicted_state_data[v9->flatOffset[1]], count: 12);
      v10 = *(void (__thiscall **)(int, Vector *))(*(_DWORD *)v4 + 352);
      vVelocityDelta.x = this->m_vecAbsVelocity.x - vPredictedVelocity.x;
      vVelocityDelta.y = this->m_vecAbsVelocity.y - vPredictedVelocity.y;
      vVelocityDelta.z = this->m_vecAbsVelocity.z - vPredictedVelocity.z;
      v10(a1: v4, a2: &vOriginDelta);
      (*(void (__thiscall **)(int, Vector *))(*(_DWORD *)v4 + 356))(a1: v4, a2: &vVelocityDelta);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039D10
// Name: public: float C_BaseEntity::HealthFraction(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseEntity::HealthFraction(C_BaseEntity *this)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // [esp+4h] [ebp-4h]

  if ( this->GetMaxHealth(this) == 0 )
    return 1.0;
  v5 = (float)this->GetHealth(this);
  v3 = v5 / (float)this->GetMaxHealth(this);
  v4 = 0.0;
  if ( v3 < 0.0 )
    return v4;
  v4 = 1.0;
  if ( v3 > 1.0 )
    return v4;
  else
    return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10039D90
// Name: public: virtual bool C_BaseEntity::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::ShouldDraw(C_BaseEntity *this)
{
  CPULevel_t ActualCPULevel; // eax
  bool m_bIsPlayerSimulated; // cl
  bool m_Value; // cl
  GPULevel_t GPULevel; // eax
  bool v7; // cl
  bool v8; // cl

  if ( this->m_iName[259] == 10 )
    return false;
  ActualCPULevel = GetActualCPULevel();
  m_bIsPlayerSimulated = this->m_bIsPlayerSimulated;
  if ( m_bIsPlayerSimulated && m_bIsPlayerSimulated - 1 > ActualCPULevel )
    return false;
  m_Value = this->m_bSimulatedEveryTick.m_Value;
  if ( m_Value && m_Value - 1 < ActualCPULevel )
    return false;
  GPULevel = GetGPULevel();
  v7 = this->m_bAnimatedEveryTick.m_Value;
  if ( v7 && v7 - 1 > GPULevel )
    return false;
  v8 = this->m_bAlternateSorting.m_Value;
  if ( v8 && v8 - 1 < GPULevel )
    return false;
  return *(_DWORD *)&this->m_EntClientFlags != 0
      && (*(_DWORD *)&this->m_nWaterType & 0x20) == 0
      && HIDWORD(this->m_pfnTouch) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10039E20
// Name: public: virtual void C_BaseEntity::ReceiveMessage(int,class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::ReceiveMessage(C_BaseEntity *this, int classID, bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int v5; // edx
  int v6; // esi
  int v7; // ecx
  const unsigned int *v8; // ecx
  const unsigned int *v9; // edx
  unsigned int v10; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v13; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v15; // esi
  unsigned int v16; // ebx
  C_BaseEntity *v17; // [esp+Ch] [ebp-4h]

  m_nBitsAvail = msg->m_nBitsAvail;
  v17 = this;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v13 = 8 - m_nBitsAvail;
    m_pDataIn = msg->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
LABEL_15:
        if ( msg->m_bOverflow )
        {
          v6 = 0;
        }
        else
        {
          v15 = msg->m_nInBufWord;
          v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << msg->m_nBitsAvail;
          msg->m_nBitsAvail = 32 - v13;
          msg->m_nInBufWord = v15 >> v13;
          v6 = v16 | m_nInBufWord;
        }
        this = v17;
        goto LABEL_19;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v5 = msg->m_nInBufWord;
  v6 = (unsigned __int8)v5;
  v7 = m_nBitsAvail - 8;
  msg->m_nBitsAvail = v7;
  if ( v7 != 0 )
  {
    msg->m_nInBufWord = v5 >> 8;
  }
  else
  {
    v8 = msg->m_pDataIn;
    v9 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v8 + 1;
    }
    else if ( v8 <= v9 )
    {
      v10 = *v8;
      msg->m_pDataIn = v8 + 1;
      msg->m_nInBufWord = v10;
    }
    else
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
    }
  }
LABEL_19:
  if ( v6 == 1 && modelinfo->GetModelType(this: modelinfo, a2: (const struct model_t *)this->index) == 3 )
  {
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 120))(a1: (char *)this - 4);
    ((void (__stdcall *)(_DWORD))modelrender->RemoveAllDecals)(a1: LOWORD(this->m_flSpawnTime));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039F50
// Name: public: virtual enum ShadowType_t C_BaseEntity::ShadowCastType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::ShadowCastType(C_BaseEntity *this)
{
  if ( (this->m_nWaterType & 0x30) != 0 )
    return 0;
  else
    return modelinfo->GetModelType(this: modelinfo, a2: *(const struct model_t **)&this->m_EntClientFlags) != 3 ? 0 : 2;
}

//------------------------------------------------------------------------------
// Address: 0x10039F80
// Name: private: void C_BaseEntity::OnDisableShadowDepthRenderingChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::OnDisableShadowDepthRenderingChanged(C_BaseEntity *this)
{
  g_pClientLeafSystem->DisableShadowDepthRendering(
    this: g_pClientLeafSystem,
    a2: this->m_hRender,
    a3: (this->m_fEffects & 0x800) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10039FB0
// Name: private: void C_BaseEntity::OnShadowDepthRenderingCacheableStateChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::OnShadowDepthRenderingCacheableStateChanged(C_BaseEntity *this)
{
  g_pClientLeafSystem->DisableShadowDepthCaching(
    this: g_pClientLeafSystem,
    a2: this->m_hRender,
    a3: (this->m_fEffects & 0x1000) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10039FE0
// Name: public: virtual class C_BaseEntity __near * C_BaseEntity::GetShadowUseOtherEntity(void)const
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall C_BaseEntity::GetShadowUseOtherEntity(C_BaseEntity *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_ShadowDirUseOtherEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1003A010
// Name: public: virtual void C_BaseEntity::SetShadowUseOtherEntity(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetShadowUseOtherEntity(C_BaseEntity *this, C_BaseEntity *pEntity)
{
  if ( pEntity != nullptr )
    this->m_ShadowDirUseOtherEntity.m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
  else
    this->m_ShadowDirUseOtherEntity.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1003A040
// Name: public: virtual bool C_BaseEntity::ShouldReceiveProjectedTextures(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::ShouldReceiveProjectedTextures(C_BaseEntity *this, char flags)
{
  int v3; // ecx

  v3 = *(_DWORD *)&this->m_nWaterType;
  if ( (v3 & 0x20) != 0 || (v3 & 0x2000) != 0 )
    return false;
  if ( (flags & 5) != 0 )
    return this->m_iName[259] == 0 || *(_BYTE *)(this->m_Particles.m_iDormancyChangedAtFrame + 14) != 0;
  if ( (v3 & 0x40) != 0 )
    return false;
  return modelinfo->GetModelType(this: modelinfo, a2: *(const struct model_t **)&this->m_EntClientFlags) != 3;
}

//------------------------------------------------------------------------------
// Address: 0x1003A0B0
// Name: public: virtual bool C_BaseEntity::IsShadowDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BaseEntity::IsShadowDirty(C_BaseEntity *this)
{
  return (LODWORD(this->m_flProxyRandomValue) & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003A0C0
// Name: public: virtual void C_BaseEntity::MarkShadowDirty(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::MarkShadowDirty(C_BaseEntity *this, bool bDirty)
{
  if ( bDirty )
    LODWORD(this->m_flProxyRandomValue) |= 0x20u;
  else
    LODWORD(this->m_flProxyRandomValue) &= ~0x20u;
}

//------------------------------------------------------------------------------
// Address: 0x1003A0E0
// Name: public: int C_BaseEntity::GetSoundSourceIndex(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall C_BaseEntity::GetSoundSourceIndex(C_BaseEntity *this)
{
  unsigned int result; // eax

  result = this->GetRefEHandle(this)->m_Index;
  if ( result == -1 )
    return 0x1FFF;
  else
    return (unsigned __int16)result;
}

//------------------------------------------------------------------------------
// Address: 0x1003A100
// Name: public: virtual struct matrix3x4_t const __near & C_BaseEntity::RenderableToWorldTransform(void)
// Source: json
//------------------------------------------------------------------------------
const matrix3x4_t *__thiscall C_BaseEntity::RenderableToWorldTransform(C_BaseEntity *this)
{
  char *v1; // esi

  v1 = (char *)this - 4;
  C_BaseEntity::CalcAbsolutePosition(this: (C_BaseEntity *)((char *)this - 4));
  return (const matrix3x4_t *)(v1 + 1076);
}

//------------------------------------------------------------------------------
// Address: 0x1003A120
// Name: public: virtual void C_BaseEntity::GetRenderBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::GetRenderBounds(C_BaseEntity *this, Vector *theMins, Vector *theMaxs)
{
  int v4; // eax
  float *v5; // ebx
  float *v6; // ecx
  Vector *v7; // eax
  double x; // st7
  Vector *v9; // ecx
  const Vector *v10; // eax
  IVModelInfoClient_vtbl *v11; // esi
  int v12; // eax
  const Vector *v13; // [esp-10h] [ebp-18h]

  v4 = modelinfo->GetModelType(this: modelinfo, a2: *(const struct model_t **)&this->m_EntClientFlags);
  if ( v4 == 3 || v4 == 1 )
  {
    v11 = modelinfo->__vftable;
    v12 = ((int (__thiscall *)(C_BaseEntity *, Vector *, Vector *))this->GetClientThinkable)(
            a1: this,
            a2: theMins,
            a3: theMaxs);
    ((void (__thiscall *)(IVModelInfoClient *, int))v11->GetModelRenderBounds)(a1: modelinfo, a2: v12);
  }
  else
  {
    v5 = (float *)(*((int (__thiscall **)(const char **))this->m_ModelName + 9))(a1: &this->m_ModelName);
    v6 = (float *)this->GetRefEHandle(this);
    if ( *v5 == *v6 && v5[1] == v6[1] && v5[2] == v6[2] )
    {
      *theMins = *(Vector *)(*((int (__thiscall **)(const char **))this->m_ModelName + 1))(a1: &this->m_ModelName);
      v7 = (Vector *)(*((int (__thiscall **)(const char **))this->m_ModelName + 2))(a1: &this->m_ModelName);
      x = v7->x;
      v9 = theMaxs;
LABEL_7:
      v9->x = x;
      v9->y = v7->y;
      v9->z = v7->z;
      return;
    }
    if ( *(float *)&this->m_Collision.m_usSolidFlags.m_Value == 0.0 )
    {
      v7 = theMaxs;
      v9 = theMins;
      theMaxs->x = vec3_origin.x;
      x = theMaxs->x;
      theMaxs->y = vec3_origin.y;
      theMaxs->z = vec3_origin.z;
      goto LABEL_7;
    }
    C_BaseEntity::CalcAbsolutePosition(this: (C_BaseEntity *)((char *)this - 4));
    v13 = (const Vector *)(*((int (__thiscall **)(const char **))this->m_ModelName + 2))(a1: &this->m_ModelName);
    v10 = (const Vector *)(*((int (__thiscall **)(const char **))this->m_ModelName + 1))(a1: &this->m_ModelName);
    IRotateAABB(
      transform: (const matrix3x4_t *)&this->m_iv_angRotation.m_Discontinuities.m_pElements,
      vecMinsIn: v10,
      vecMaxsIn: v13,
      vecMinsOut: theMins,
      vecMaxsOut: theMaxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A2A0
// Name: public: void C_BaseEntity::SetNetworkOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetNetworkOrigin(C_BaseEntity *this, const Vector *org)
{
  this->m_vecNetworkOrigin = *org;
}

//------------------------------------------------------------------------------
// Address: 0x1003A2D0
// Name: public: void C_BaseEntity::SetNetworkAngles(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetNetworkAngles(C_BaseEntity *this, const QAngle *ang)
{
  this->m_angNetworkAngles = *ang;
}

//------------------------------------------------------------------------------
// Address: 0x1003A300
// Name: public: void C_BaseEntity::SetMoveType(enum MoveType_t,enum MoveCollide_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetMoveType(C_BaseEntity *this, MoveType_t val, MoveCollide_t moveCollide)
{
  this->m_MoveType = val;
  this->m_MoveCollide = moveCollide;
}

//------------------------------------------------------------------------------
// Address: 0x1003A320
// Name: public: virtual bool C_BaseEntity::GetSoundSpatialization(struct SpatializationInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::GetSoundSpatialization(C_BaseEntity *this, SpatializationInfo_t *info)
{
  const struct model_t *v4; // ebx
  Vector *pOrigin; // eax
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  QAngle *pAngles; // esi
  const QAngle *v10; // eax
  Vector mins; // [esp+8h] [ebp-18h] BYREF
  Vector maxs; // [esp+14h] [ebp-Ch] BYREF

  if ( this->entindex(this: &this->IClientNetworkable) != 0 )
  {
    if ( this->IsDormant(this: &this->IClientNetworkable) )
      return 0;
    v4 = this->GetModel(this: &this->IClientRenderable);
    if ( info->pflRadius != nullptr )
      *info->pflRadius = modelinfo->GetModelRadius(this: modelinfo, a2: v4);
    if ( info->pOrigin != nullptr )
    {
      *info->pOrigin = *this->GetAbsOrigin(this);
      if ( modelinfo->GetModelType(this: modelinfo, a2: v4) == 1 )
      {
        modelinfo->GetModelBounds(this: modelinfo, a2: v4, a3: &mins, a4: &maxs);
        pOrigin = info->pOrigin;
        v6 = (float)(maxs.z + mins.z) * 0.5;
        v7 = pOrigin->x + (float)((float)(maxs.x + mins.x) * 0.5);
        pOrigin->y = pOrigin->y + (float)((float)(maxs.y + mins.y) * 0.5);
        v8 = pOrigin->z + v6;
        pOrigin->x = v7;
        pOrigin->z = v8;
      }
    }
    pAngles = info->pAngles;
    if ( pAngles != nullptr )
    {
      v10 = this->GetAbsAngles(this);
      pAngles->x = v10->x;
      pAngles->y = v10->y;
      pAngles->z = v10->z;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003A460
// Name: public: virtual bool C_BaseEntity::GetAttachment(int,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::GetAttachment(C_BaseEntity *this, int number, Vector *origin, QAngle *angles)
{
  char *v4; // esi
  float *v5; // eax
  int (__thiscall *v6)(char *); // edx
  float *v7; // eax
  double v8; // st7

  v4 = (char *)this - 4;
  v5 = (float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 40))(a1: (char *)this - 4);
  origin->x = *v5;
  origin->y = v5[1];
  v6 = *(int (__thiscall **)(char *))(*(_DWORD *)v4 + 44);
  origin->z = v5[2];
  v7 = (float *)v6(a1: v4);
  angles->x = *v7;
  angles->y = v7[1];
  v8 = v7[2];
  angles->z = v8;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003A4B0
// Name: public: virtual bool C_BaseEntity::GetAttachment(int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::GetAttachment(C_BaseEntity *this, int number, Vector *origin)
{
  const Vector *v3; // eax
  double z; // st7

  v3 = this->GetAbsOrigin(this);
  origin->x = v3->x;
  origin->y = v3->y;
  z = v3->z;
  origin->z = z;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003A4E0
// Name: public: virtual bool C_BaseEntity::GetAttachment(int,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::GetAttachment(C_BaseEntity *this, int number, matrix3x4_t *matrix)
{
  char *v3; // esi

  v3 = (char *)this - 4;
  C_BaseEntity::CalcAbsolutePosition(this: (C_BaseEntity *)((char *)this - 4));
  MatrixCopy(in: (const matrix3x4_t *)(v3 + 1076), out: matrix);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003A510
// Name: public: virtual void C_BaseEntity::UpdatePartitionListEntry(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::UpdatePartitionListEntry(C_BaseEntity *this)
{
  CollideType_t v2; // eax
  int v3; // edx

  v2 = this->GetCollideType(this);
  v3 = 128;
  if ( v2 == ENTITY_SHOULD_COLLIDE )
  {
    v3 = 132;
  }
  else if ( v2 == ENTITY_SHOULD_RESPOND )
  {
    v3 = 136;
  }
  if ( this->m_bIsValidIKAttachment )
    v3 |= 0x200u;
  partition->RemoveAndInsert(this: partition, a2: 652, a3: v3, a4: this->m_Collision.m_Partition);
}

//------------------------------------------------------------------------------
// Address: 0x1003A570
// Name: protected: bool C_BaseEntity::IsParentChanging(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::IsParentChanging(C_BaseEntity *this)
{
  return this->m_hNetworkMoveParent.m_Index != this->m_pMoveParent.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x1003A590
// Name: public: void C_BaseEntity::CheckInitPredictable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::CheckInitPredictable(C_BaseEntity *this, const char *context)
{
  C_BasePlayer *v3; // eax

  if ( this->ShouldPredict(this)
    && cl_predict->GetInt(this: cl_predict) != 0
    && C_BasePlayer::HasAnyLocalPlayer() != 0
    && this->m_bPredictionEligible
    && !this->IsClientCreated(this)
    && this->m_pOriginalData == nullptr )
  {
    v3 = this->GetPredictionOwner(this);
    if ( v3 != nullptr )
      this->InitPredictable(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A600
// Name: public: float C_BaseEntity::GetEffectiveInterpolationCurTime(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseEntity::GetEffectiveInterpolationCurTime(C_BaseEntity *this, float currentTime)
{
  C_BasePlayer *LocalPlayer; // eax
  float currentTimea; // [esp+Ch] [ebp+8h]

  if ( this->m_bPredictable || this->IsClientCreated(this) )
  {
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: this->m_nSplitUserPlayerPredictionSlot);
    if ( LocalPlayer != nullptr )
    {
      currentTimea = C_BasePlayer::GetFinalPredictedTime(this: LocalPlayer);
      return (float)((float)(*(float *)(gpGlobals.m_Index + 32) * *(float *)(gpGlobals.m_Index + 28))
                   + (float)(currentTimea - *(float *)(gpGlobals.m_Index + 28)));
    }
  }
  return currentTime;
}

//------------------------------------------------------------------------------
// Address: 0x1003A670
// Name: protected: void C_BaseEntity::BaseInterpolatePart2(class Vector __near &,class QAngle __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::BaseInterpolatePart2(
        C_BaseEntity *this,
        Vector *oldOrigin,
        QAngle *oldAngles,
        int nChangeFlags)
{
  int v4; // esi

  if ( oldOrigin->x == this->m_vecOrigin.x && oldOrigin->y == this->m_vecOrigin.y && oldOrigin->z == this->m_vecOrigin.z )
    v4 = nChangeFlags;
  else
    v4 = nChangeFlags | 1;
  if ( oldAngles->x != this->m_angRotation.x
    || oldAngles->y != this->m_angRotation.y
    || oldAngles->z != this->m_angRotation.z )
  {
    v4 |= 2u;
  }
  if ( v4 != 0 )
    C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1003A710
// Name: public: virtual class CStudioHdr __near * C_BaseEntity::OnNewModel(void)
// Source: json
//------------------------------------------------------------------------------
CStudioHdr *__usercall C_BaseEntity::OnNewModel@<eax>(C_BaseEntity *this@<ecx>, IClientLeafSystem_vtbl *a2@<edi>)
{
  RenderableTranslucencyType_t v3; // eax
  const struct model_t *v4; // edi

  if ( this->m_hRender != 0xFFFF )
  {
    a2 = g_pClientLeafSystem->IClientLeafSystemEngine::__vftable;
    v3 = this->ComputeTranslucencyType(this);
    a2->SetTranslucencyType(this: g_pClientLeafSystem, a2: this->m_hRender, a3: v3);
  }
  ((void (__stdcall *)(_DWORD, int))g_pClientLeafSystem->SetModelType)(a1: this->m_hRender, a2: -1);
  C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 48);
  C_BaseEntity::SetGlobalFadeScale(this, (int)a2, a3: (int)this, flFadeScale: this->m_flFadeScale);
  v4 = this->GetModel(this: &this->IClientRenderable);
  if ( v4 != nullptr
    && modelinfo->GetModelType(this: modelinfo, a2: v4) == 1
    && !modelinfo->ModelHasMaterialProxy(this: modelinfo, a2: v4) )
  {
    this->m_bCanUseBrushModelFastPath = true;
    return nullptr;
  }
  else
  {
    this->m_bCanUseBrushModelFastPath = false;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A7D0
// Name: public: virtual bool C_BaseEntity::CreateLightEffects(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::CreateLightEffects(C_BaseEntity *this)
{
  IVRenderView_vtbl *v1; // esi
  char v3; // bl
  int v4; // eax
  dlight_t *v5; // esi
  const Vector *v6; // eax
  dlight_t *v7; // esi
  const Vector *v8; // eax

  v1 = render->__vftable;
  v3 = 0;
  v4 = this->entindex(this: &this->IClientNetworkable);
  if ( !v1->IsViewEntity(this: render, a2: v4) )
  {
    if ( (this->m_fEffects & 2) != 0 )
    {
      v3 = 1;
      v5 = effects->CL_AllocDlight(this: effects, a2: this->index);
      v6 = this->GetAbsOrigin(this);
      v5->origin.x = v6->x;
      v5->origin.y = v6->y;
      v5->origin.z = v6->z;
      v5->origin.z = v5->origin.z + 16.0;
      *(_WORD *)&v5->color.g = -1286;
      v5->color.r = -6;
      v5->radius = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                     a1: random,
                     a2: 1137180672,
                     a3: 1138196480);
      v5->die = *(float *)(gpGlobals.m_Index + 12) + 0.001;
    }
    if ( (this->m_fEffects & 4) != 0 )
    {
      v3 = 1;
      v7 = effects->CL_AllocDlight(this: effects, a2: this->index);
      v8 = this->GetAbsOrigin(this);
      v7->origin.x = v8->x;
      v7->origin.y = v8->y;
      v7->origin.z = v8->z;
      *(_WORD *)&v7->color.g = 25700;
      v7->color.r = 100;
      v7->radius = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                     a1: random,
                     a2: 1128792064,
                     a3: 1130823680);
      v7->die = *(float *)(gpGlobals.m_Index + 12) + 0.001;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1003A950
// Name: public: void C_BaseEntity::MoveToLastReceivedPosition(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::MoveToLastReceivedPosition(C_BaseEntity *this, bool force)
{
  if ( force || !this->m_bClientSideRagdoll )
  {
    if ( this->m_vecNetworkOrigin.x != this->m_vecOrigin.x
      || this->m_vecNetworkOrigin.y != this->m_vecOrigin.y
      || this->m_vecNetworkOrigin.z != this->m_vecOrigin.z )
    {
      C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 1);
      this->m_vecOrigin.x = this->m_vecNetworkOrigin.x;
      this->m_vecOrigin.y = this->m_vecNetworkOrigin.y;
      this->m_vecOrigin.z = this->m_vecNetworkOrigin.z;
    }
    if ( this->m_angNetworkAngles.x != this->m_angRotation.x
      || this->m_angNetworkAngles.y != this->m_angRotation.y
      || this->m_angNetworkAngles.z != this->m_angRotation.z )
    {
      C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 2);
      this->m_angRotation.x = this->m_angNetworkAngles.x;
      this->m_angRotation.y = this->m_angNetworkAngles.y;
      this->m_angRotation.z = this->m_angNetworkAngles.z;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003AA50
// Name: public: virtual void C_BaseEntity::GetAimEntOrigin(class IClientEntity __near *,class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::GetAimEntOrigin(
        C_BaseEntity *this,
        IClientEntity *pAttachedTo,
        Vector *pOrigin,
        QAngle *pAngles)
{
  const Vector *v4; // eax
  const QAngle *(__thiscall *GetAbsAngles)(IClientEntity *); // edx

  v4 = pAttachedTo->GetAbsOrigin(this: pAttachedTo);
  pOrigin->x = v4->x;
  pOrigin->y = v4->y;
  GetAbsAngles = pAttachedTo->GetAbsAngles;
  pOrigin->z = v4->z;
  *pAngles = *GetAbsAngles(this: pAttachedTo);
}

//------------------------------------------------------------------------------
// Address: 0x1003AAA0
// Name: public: virtual void C_BaseEntity::GetColorModulation(float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::GetColorModulation(C_BaseEntity *this, float *color)
{
  *color = (float)LOBYTE(this->model) * 0.0039215689;
  color[1] = (float)BYTE1(this->model) * 0.0039215689;
  color[2] = (float)BYTE2(this->model) * 0.0039215689;
}

//------------------------------------------------------------------------------
// Address: 0x1003AAF0
// Name: public: bool C_BaseEntity::SnatchModelInstance(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::SnatchModelInstance(C_BaseEntity *this, C_BaseEntity *pToEntity)
{
  IClientRenderable *v2; // eax
  IVModelRender_vtbl *v3; // ebx
  IClientRenderable *v4; // edi
  unsigned __int16 v5; // ax
  char result; // al

  if ( pToEntity != nullptr )
    v2 = &pToEntity->IClientRenderable;
  else
    v2 = nullptr;
  v3 = modelrender->__vftable;
  v4 = &this->IClientRenderable;
  v5 = ((int (__thiscall *)(IClientRenderable *, IClientRenderable *))this->GetModelInstance)(
         a1: &this->IClientRenderable,
         a2: v2);
  result = ((int (__thiscall *)(IVModelRender *, _DWORD))v3->ChangeInstance)(a1: modelrender, a2: v5);
  if ( result != 0 )
  {
    if ( pToEntity->GetModelInstance(this: &pToEntity->IClientRenderable) != 0xFFFF
      && pToEntity->m_ModelInstance != 0xFFFF )
    {
      modelrender->DestroyInstance(this: modelrender, a2: pToEntity->m_ModelInstance);
      pToEntity->m_ModelInstance = -1;
    }
    pToEntity->m_ModelInstance = v4->GetModelInstance(this: v4);
    this->m_ModelInstance = -1;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003ABA0
// Name: public: virtual void C_BaseEntity::SetNextClientThink(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetNextClientThink(C_BaseEntity *this, float nextThinkTime)
{
  CClientThinkList::SetNextClientThink(this: &g_ClientThinkList, hEnt: this->m_RefEHandle, flNextTime: nextThinkTime);
}

//------------------------------------------------------------------------------
// Address: 0x1003ABD0
// Name: public: void C_BaseEntity::RemoveFromLeafSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::RemoveFromLeafSystem(C_BaseEntity *this)
{
  int m_hRender; // eax

  m_hRender = this->m_hRender;
  if ( (_WORD)m_hRender != 0xFFFF )
  {
    g_pClientLeafSystem->RemoveRenderable(this: g_pClientLeafSystem, a2: m_hRender);
    this->m_hRender = -1;
  }
  if ( this->m_ShadowHandle != 0xFFFF )
  {
    g_pClientShadowMgr->DestroyShadow(this: g_pClientShadowMgr, a2: this->m_ShadowHandle);
    this->m_ShadowHandle = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003AC30
// Name: public: virtual bool C_BaseEntity::IsDormant(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::IsDormant(C_BaseEntity *this)
{
  if ( DWORD2(this->m_pfnTouch) == -1 )
    return false;
  else
    return BYTE1(this->m_flProxyRandomValue);
}

//------------------------------------------------------------------------------
// Address: 0x1003AC40
// Name: public: virtual void C_BaseEntity::SetDestroyedOnRecreateEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetDestroyedOnRecreateEntities(C_BaseEntity *this)
{
  CParticleProperty::StopEmissionAndDestroyImmediately(
    this: (CParticleProperty *)&this->m_Collision.m_vecSurroundingMaxs.y,
    pEffect: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1003AC50
// Name: public: virtual void C_BaseEntity::Teleport(class Vector const __near *,class QAngle const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::Teleport(
        C_BaseEntity *this,
        const Vector *newPosition,
        const QAngle *newAngles,
        const Vector *newVelocity)
{
  unsigned int m_fEffects; // ebx

  m_fEffects = this->m_fEffects;
  if ( newPosition != nullptr )
  {
    m_fEffects |= 8u;
    this->m_vecNetworkOrigin = *newPosition;
  }
  if ( newAngles != nullptr )
  {
    m_fEffects |= 8u;
    this->m_angNetworkAngles = *newAngles;
  }
  if ( newVelocity != nullptr )
  {
    if ( newVelocity->x != this->m_vecVelocity.x
      || newVelocity->y != this->m_vecVelocity.y
      || newVelocity->z != this->m_vecVelocity.z )
    {
      C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 4);
      this->m_vecVelocity = *newVelocity;
    }
    m_fEffects |= 8u;
  }
  C_BaseEntity::SetEffects(this, nEffects: m_fEffects);
}

//------------------------------------------------------------------------------
// Address: 0x1003AD20
// Name: public: void C_BaseEntity::MarkRenderHandleDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::MarkRenderHandleDirty(C_BaseEntity *this)
{
  int m_hRender; // eax

  m_hRender = this->m_hRender;
  if ( (_WORD)m_hRender != 0xFFFF )
    g_pClientLeafSystem->RenderableChanged(this: g_pClientLeafSystem, a2: m_hRender);
}

//------------------------------------------------------------------------------
// Address: 0x1003AD40
// Name: public: void C_BaseEntity::SetSize(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetSize(C_BaseEntity *this, const Vector *vecMin, const Vector *vecMax)
{
  CCollisionProperty::SetCollisionBounds(this: &this->m_Collision, mins: vecMin, maxs: vecMax);
}

//------------------------------------------------------------------------------
// Address: 0x1003AD90
// Name: public: void C_BaseEntity::SetOwnerEntity(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetOwnerEntity(C_BaseEntity *this, C_BaseEntity *pOwner)
{
  if ( pOwner != nullptr )
    this->m_hOwnerEntity.m_Index = pOwner->GetRefEHandle(this: pOwner)->m_Index;
  else
    this->m_hOwnerEntity.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1003ADC0
// Name: public: void C_BaseEntity::AllocateIntermediateData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::AllocateIntermediateData(C_BaseEntity *this)
{
  datamap_t *v2; // eax
  int m_nPackedSize; // esi
  unsigned __int8 *v4; // eax
  unsigned __int8 **m_pIntermediateData; // edi
  int i; // ebx
  unsigned __int8 *v7; // eax
  unsigned __int8 **m_pIntermediateData_FirstPredicted; // edi
  int j; // ebx
  unsigned __int8 *v10; // eax

  if ( this->m_pOriginalData == nullptr )
  {
    v2 = this->GetPredDescMap(this);
    if ( v2 != nullptr && v2->m_pOptimizedDataMap == nullptr )
      CPredictionCopy::PrepareDataMap(dmap: v2);
    m_nPackedSize = this->GetPredDescMap(this)->m_nPackedSize;
    if ( m_nPackedSize <= 4 )
      m_nPackedSize = 4;
    v4 = (unsigned __int8 *)MemAlloc_Alloc(nSize: m_nPackedSize);
    this->m_pOriginalData = v4;
    _V_memset(dest: v4, fill: 0, count: m_nPackedSize);
    m_pIntermediateData = this->m_pIntermediateData;
    for ( i = 150; i != 0; --i )
    {
      v7 = (unsigned __int8 *)MemAlloc_Alloc(nSize: m_nPackedSize);
      *m_pIntermediateData = v7;
      _V_memset(dest: v7, fill: 0, count: m_nPackedSize);
      ++m_pIntermediateData;
    }
    if ( physenv == nullptr || physenv->IsPredicted(this: physenv) )
    {
      m_pIntermediateData_FirstPredicted = this->m_pIntermediateData_FirstPredicted;
      for ( j = 151; j != 0; --j )
      {
        v10 = (unsigned __int8 *)MemAlloc_Alloc(nSize: m_nPackedSize);
        *m_pIntermediateData_FirstPredicted = v10;
        _V_memset(dest: v10, fill: 0, count: m_nPackedSize);
        ++m_pIntermediateData_FirstPredicted;
      }
      this->m_nIntermediateData_FirstPredictedShiftMarker = -1;
    }
    this->m_nIntermediateDataCount = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003AEB0
// Name: public: void C_BaseEntity::ShiftIntermediateData_TickAdjust(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::ShiftIntermediateData_TickAdjust(C_BaseEntity *this, int delta, int last_slot)
{
  C_BaseEntity *v3; // esi
  int v5; // edi
  datamap_t *v6; // eax
  int v7; // eax
  int v8; // esi
  unsigned __int8 **v9; // edi
  int v10; // edx
  int v11; // eax
  unsigned __int8 **v12; // edi
  unsigned __int8 **v13; // esi
  int v14; // ebx
  unsigned __int8 *v15; // [esp-14h] [ebp-278h]
  unsigned __int8 *v16; // [esp-14h] [ebp-278h]
  unsigned __int8 *v17; // [esp-10h] [ebp-274h]
  unsigned __int8 *saved[150]; // [esp+4h] [ebp-260h] BYREF
  unsigned __int8 *src; // [esp+25Ch] [ebp-8h]
  C_BaseEntity *v21; // [esp+260h] [ebp-4h]
  unsigned __int8 *deltaa; // [esp+26Ch] [ebp+8h]
  int allocsize; // [esp+270h] [ebp+Ch]

  v3 = this;
  v21 = this;
  src = (unsigned __int8 *)this->m_pIntermediateData;
  if ( this != (C_BaseEntity *)-1128 && last_slot != 0 )
  {
    v5 = delta;
    if ( delta <= last_slot )
    {
      if ( delta < -last_slot )
        return;
    }
    else
    {
      v5 = last_slot;
    }
    v6 = this->GetPredDescMap(this);
    if ( v6 != nullptr && v6->m_pOptimizedDataMap == nullptr )
      CPredictionCopy::PrepareDataMap(dmap: v6);
    allocsize = v3->GetPredDescMap(this: v3)->m_nPackedSize;
    if ( allocsize <= 4 )
      allocsize = 4;
    memcpy(dst: (unsigned __int8 *)saved, src, count: 4 * last_slot);
    if ( v5 >= 0 )
    {
      v10 = last_slot - v5;
      v11 = 0;
      if ( last_slot - v5 > 0 )
      {
        qmemcpy(src, &saved[v5], 4 * v10);
        v3 = v21;
        v11 = last_slot - v5;
      }
      if ( v11 < last_slot )
      {
        deltaa = saved[last_slot - 1];
        v12 = &v3->m_pIntermediateData[v11];
        v13 = &saved[v11 - v10];
        v14 = last_slot - v11;
        do
        {
          v16 = *v13;
          *v12 = *v13;
          memcpy(dst: v16, src: deltaa, count: allocsize);
          ++v13;
          ++v12;
          --v14;
        }
        while ( v14 != 0 );
      }
    }
    else
    {
      v7 = v5 + last_slot;
      v8 = 0;
      if ( v5 + last_slot > 0 )
      {
        qmemcpy(&v21->IClientEntity::IClientUnknown::IHandleEntity::__vftable + 282 - v5, saved, 4 * v7);
        v8 = v5 + last_slot;
      }
      if ( v8 < last_slot )
      {
        v9 = &v21->m_pIntermediateData[v8 - v7];
        do
        {
          v17 = saved[0];
          v15 = saved[v8];
          *v9 = v15;
          memcpy(dst: v15, src: v17, count: allocsize);
          ++v8;
          ++v9;
        }
        while ( v8 < last_slot );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B020
// Name: public: void C_BaseEntity::DrawBBoxVisualizations(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::DrawBBoxVisualizations(C_BaseEntity *this)
{
  IVDebugOverlay_vtbl *v2; // ebx
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  IClientRenderable *v7; // esi
  IVDebugOverlay_vtbl *v8; // edi
  int v9; // eax
  int v10; // eax
  Vector vecRenderMaxs; // [esp+64h] [ebp-18h] BYREF
  Vector vecRenderMins; // [esp+70h] [ebp-Ch] BYREF

  if ( (this->m_fBBoxVisFlags & 1) != 0 )
  {
    v2 = debugoverlay->__vftable;
    v3 = ((int (__thiscall *)(C_BaseEntity::NetworkVar_m_Collision *, int, int, _DWORD, _DWORD, int))this->m_Collision.GetCollisionAngles)(
           a1: &this->m_Collision,
           a2: 190,
           a3: 190,
           a4: 0,
           a5: 0,
           a6: 1008981770);
    v4 = ((int (__thiscall *)(C_BaseEntity::NetworkVar_m_Collision *, int))this->m_Collision.OBBMaxs)(
           a1: &this->m_Collision,
           a2: v3);
    v5 = ((int (__thiscall *)(C_BaseEntity::NetworkVar_m_Collision *, int))this->m_Collision.OBBMins)(
           a1: &this->m_Collision,
           a2: v4);
    v6 = ((int (__thiscall *)(C_BaseEntity::NetworkVar_m_Collision *, int))this->m_Collision.GetCollisionOrigin)(
           a1: &this->m_Collision,
           a2: v5);
    ((void (__thiscall *)(IVDebugOverlay *, int))v2->AddBoxOverlay)(a1: debugoverlay, a2: v6);
  }
  if ( (this->m_fBBoxVisFlags & 2) != 0 )
  {
    this->m_Collision.WorldSpaceSurroundingBounds(this: &this->m_Collision, a2: &vecRenderMaxs, a3: &vecRenderMins);
    ((void (__stdcall *)(Vector *, Vector *, Vector *, QAngle *, _DWORD, int, int, _DWORD, int))debugoverlay->AddBoxOverlay)(
      a1: &vec3_origin,
      a2: &vecRenderMaxs,
      a3: &vecRenderMins,
      a4: &vec3_angle,
      a5: 0,
      a6: 255,
      a7: 255,
      a8: 0,
      a9: 1008981770);
  }
  if ( (this->m_fBBoxVisFlags & 4) != 0
    || r_drawrenderboxes.m_pParent != nullptr && r_drawrenderboxes.m_pParent->m_Value.m_nValue != 0 )
  {
    v7 = &this->IClientRenderable;
    this->GetRenderBounds(this: &this->IClientRenderable, a2: &vecRenderMins, a3: &vecRenderMaxs);
    v8 = debugoverlay->__vftable;
    v9 = ((int (__thiscall *)(IClientRenderable *, int, _DWORD, int, _DWORD, int))v7->GetRenderAngles)(
           a1: v7,
           a2: 255,
           a3: 0,
           a4: 255,
           a5: 0,
           a6: 1008981770);
    v10 = ((int (__thiscall *)(IClientRenderable *, Vector *, Vector *, int))v7->GetRenderOrigin)(
            a1: v7,
            a2: &vecRenderMins,
            a3: &vecRenderMaxs,
            a4: v9);
    ((void (__thiscall *)(IVDebugOverlay *, int))v8->AddBoxOverlay)(a1: debugoverlay, a2: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B190
// Name: public: void C_BaseEntity::SetRenderMode(enum RenderMode_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetRenderMode(C_BaseEntity *this, RenderMode_t nRenderMode, bool bForceUpdate)
{
  CClientAlphaProperty *m_pClientAlphaProperty; // ecx

  if ( nRenderMode != this->m_nRenderMode )
  {
    m_pClientAlphaProperty = this->m_pClientAlphaProperty;
    this->m_nRenderMode = nRenderMode;
    ((void (__thiscall *)(CClientAlphaProperty *, _DWORD, RenderMode_t, int, _DWORD))m_pClientAlphaProperty->SetRenderFX)(
      a1: m_pClientAlphaProperty,
      a2: this->m_nRenderFX,
      a3: nRenderMode,
      a4: 2139095039,
      a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B1E0
// Name: public: void C_BaseEntity::SetRenderFX(enum RenderFx_t,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetRenderFX(
        C_BaseEntity *this,
        RenderFx_t nRenderFX,
        float flStartTime,
        float flDuration)
{
  float v4; // xmm0_4
  CClientAlphaProperty *m_pClientAlphaProperty; // eax

  v4 = flStartTime;
  if ( nRenderFX == this->m_nRenderFX )
  {
    if ( flStartTime == 3.4028235e38 )
      return;
  }
  else if ( flStartTime == 3.4028235e38 )
  {
    v4 = *(float *)(gpGlobals.m_Index + 12);
  }
  m_pClientAlphaProperty = this->m_pClientAlphaProperty;
  this->m_nRenderFX = nRenderFX;
  ((void (__thiscall *)(CClientAlphaProperty *, RenderFx_t, _DWORD, float, _DWORD))m_pClientAlphaProperty->SetRenderFX)(
    a1: m_pClientAlphaProperty,
    a2: nRenderFX,
    a3: this->m_nRenderMode,
    a4: COERCE_FLOAT(LODWORD(v4)),
    a5: LODWORD(flDuration));
}

//------------------------------------------------------------------------------
// Address: 0x1003B260
// Name: public: float C_BaseEntity::GetLastChangeTime(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseEntity::GetLastChangeTime(C_BaseEntity *this, char flags)
{
  float st; // [esp+Ch] [ebp+8h]

  if ( this->m_bPredictable || this->IsClientCreated(this) )
    return *(float *)(gpGlobals.m_Index + 12);
  if ( (flags & 1) != 0 )
    return this->m_flAnimTime;
  if ( (flags & 2) == 0 )
    return *(float *)(gpGlobals.m_Index + 12);
  st = this->m_flSimulationTime;
  if ( st == 0.0 )
    return *(float *)(gpGlobals.m_Index + 12);
  else
    return st;
}

//------------------------------------------------------------------------------
// Address: 0x1003B2E0
// Name: public: virtual int C_BaseEntity::Save(class ISave __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::Save(C_BaseEntity *this, ISave *save)
{
  datamap_t *v3; // eax

  v3 = this->GetDataDescMap(this);
  return save->WriteAll(this: save, a2: this, a3: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1003B300
// Name: public: void C_BaseEntity::SetToolRecording(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetToolRecording(C_BaseEntity *this, bool recording)
{
  IRecordingList_vtbl *v3; // edx
  unsigned int m_Index; // [esp-4h] [ebp-8h]

  this->m_bToolRecording = recording;
  m_Index = this->m_RefEHandle.m_Index;
  v3 = recordinglist->__vftable;
  if ( recording )
  {
    ((void (__stdcall *)(unsigned int))v3->AddToList)(a1: m_Index);
    this->OnToolStartRecording(this);
  }
  else
  {
    ((void (__stdcall *)(unsigned int))v3->RemoveFromList)(a1: m_Index);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B350
// Name: public: virtual void C_BaseEntity::RecordToolMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::RecordToolMessage(C_BaseEntity *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi

  if ( C_BaseEntity::IsToolRecording(this: (C_BaseEntity *)((char *)this - 4))
    && this->m_ToolHandle != *(_DWORD *)(gpGlobals.m_Index + 4) )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "entity_state");
    else
      v3 = nullptr;
    (*(void (__thiscall **)(char *, KeyValues *))(*((_DWORD *)this - 1) + 388))(a1: (char *)this - 4, a2: v3);
    ToolFramework_PostToolMessage(hEntity: *(_DWORD *)&this->m_bEnabledInToolView, msg: v3);
    (*(void (__thiscall **)(char *, KeyValues *))(*((_DWORD *)this - 1) + 392))(a1: (char *)this - 4, a2: v3);
    KeyValues::deleteThis(this: v3);
    this->m_ToolHandle = *(_DWORD *)(gpGlobals.m_Index + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B3E0
// Name: void CC_CL_Find_Ent(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_CL_Find_Ent(const CCommand *args)
{
  C_BaseEntity *i; // ebx
  const char *Classname; // eax
  const char *v3; // edi
  bool v4; // zf
  const char *v5; // eax
  int v6; // eax
  const char *v7; // [esp-Ch] [ebp-10h]
  int iCount; // [esp+0h] [ebp-4h]
  const char *argsa; // [esp+Ch] [ebp+8h]

  if ( args->m_nArgc >= 2 )
  {
    iCount = 0;
    if ( args->m_nArgc > 1 )
      argsa = args->m_ppArgv[1];
    else
      argsa = prType;
    _Msg(a1: "Searching for client entities with classname containing substring: '%s'\n", argsa);
    for ( i = CClientEntityList::NextBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, pEnt: nullptr);
          i != nullptr;
          i = CClientEntityList::NextBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, pEnt: i) )
    {
      Classname = C_BaseEntity::GetClassname(this: i);
      v3 = Classname;
      if ( Classname != nullptr && *Classname != 0 && V_stristr(pStr: Classname, pSearch: argsa) != nullptr )
      {
        ++iCount;
        v4 = !i->IsDormant(this: &i->IClientNetworkable);
        v5 = "(DORMANT)";
        if ( v4 )
          v5 = prType;
        v6 = ((int (__thiscall *)(IClientNetworkable *, const char *))i->entindex)(a1: &i->IClientNetworkable, a2: v5);
        _Msg(a1: "   '%s' (entindex %d) %s \n", v3, v6, v7);
      }
    }
    _Msg(a1: "Found %d matches.\n", iCount);
  }
  else
  {
    _Msg(a1: "Format: cl_find_ent <substring>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B4D0
// Name: void CC_CL_Find_Ent_Index(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_CL_Find_Ent_Index(const CCommand *args)
{
  const char *v1; // eax
  int v2; // edi
  C_BaseEntity *BaseEntity; // eax
  C_BaseEntity *v4; // esi
  const char *Classname; // ebx
  bool v6; // al
  const char *v7; // ecx
  const char *v8; // eax

  if ( args->m_nArgc >= 2 )
  {
    v1 = prType;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    v2 = atoi(nptr: v1);
    BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: v2);
    v4 = BaseEntity;
    if ( BaseEntity != nullptr )
    {
      Classname = C_BaseEntity::GetClassname(this: BaseEntity);
      v6 = v4->IsDormant(this: &v4->IClientNetworkable);
      v7 = "(DORMANT)";
      if ( !v6 )
        v7 = prType;
      v8 = Classname;
      if ( Classname == nullptr )
        v8 = "[NO NAME]";
      _Msg(a1: "   '%s' (entindex %d) %s \n", v8, v2, v7);
    }
    else
    {
      _Msg(a1: "Found no entity at %d.\n", v2);
    }
  }
  else
  {
    _Msg(a1: "Format: cl_find_ent_index <index>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B5C0
// Name: public: bool CBitVecT<class CFixedBitVecBase<1>>::Compare(class CBitVecT<class CFixedBitVecBase<1>> const __near &,int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBitVecT<CFixedBitVecBase<1>>::Compare(
        CBitVecT<CFixedBitVecBase<1> > *this,
        const CBitVecT<CFixedBitVecBase<1> > *other,
        int nBits)
{
  int v3; // eax
  unsigned int v4; // eax
  const CBitVecT<CFixedBitVecBase<1> > *v5; // edx
  CBitVecT<CFixedBitVecBase<1> > *v6; // esi

  v3 = nBits;
  if ( nBits == -1 )
  {
    v3 = 1;
  }
  else if ( nBits > 1 )
  {
    return false;
  }
  this->m_Ints[0] &= 1u;
  other->m_Ints[0] &= 1u;
  v4 = (8 * ((v3 + 7) / 8)) >> 3;
  v5 = other;
  v6 = this;
  if ( v4 < 4 )
  {
LABEL_7:
    if ( v4 == 0 )
      return true;
  }
  else
  {
    while ( v6->m_Ints[0] == v5->m_Ints[0] )
    {
      v4 -= 4;
      ++v5;
      ++v6;
      if ( v4 < 4 )
        goto LABEL_7;
    }
  }
  return LOBYTE(v6->m_Ints[0]) == LOBYTE(v5->m_Ints[0])
      && (v4 <= 1
       || BYTE1(v6->m_Ints[0]) == BYTE1(v5->m_Ints[0])
       && (v4 <= 2 || BYTE2(v6->m_Ints[0]) == BYTE2(v5->m_Ints[0]) && v4 <= 3));
}

//------------------------------------------------------------------------------
// Address: 0x1003B680
// Name: public: static bool CMemberScriptBinding0<class C_BaseEntity __near *,class Vector const __near & (C_BaseEntity::*)(void),class Vector const __near &>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding0<C_BaseEntity *,Vector const & (__thiscall C_BaseEntity::*)(void),Vector const &>::Call(
        int (*pFunction)(void),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  int v5; // eax
  _DWORD *v6; // eax
  int m_int; // ecx

  if ( nArguments != 0 || pReturn == nullptr || pContext == nullptr )
    return 0;
  v5 = pFunction();
  pReturn->m_type = 3;
  pReturn->m_int = v5;
  v6 = MemAlloc_Alloc(nSize: 0xCu);
  if ( v6 != nullptr )
  {
    m_int = pReturn->m_int;
    *(_QWORD *)v6 = *(_QWORD *)pReturn->m_int;
    v6[2] = *(_DWORD *)(m_int + 8);
    pReturn->m_int = (int)v6;
  }
  else
  {
    pReturn->m_int = 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003B6E0
// Name: public: static bool CMemberScriptBinding0<class C_BaseEntity __near *,int (C_BaseEntity::*)(void),int>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMemberScriptBinding0<C_BaseEntity *,int (__thiscall C_BaseEntity::*)(void),int>::Call(
        int (*pFunction)(void),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 0 || pReturn == nullptr || pContext == nullptr )
    return 0;
  pReturn->m_int = pFunction();
  pReturn->m_type = 5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003B840
// Name: public: virtual int CCollisionProperty::GetSolidFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionProperty::GetSolidFlags(CCollisionProperty *this)
{
  return this->m_usSolidFlags.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x1003BB00
// Name: public: virtual class IClientRenderable __near * CRecordingList::Get(int)
// Source: json
//------------------------------------------------------------------------------
IClientRenderable *__thiscall CRecordingList::Get(CRecordingList *this, int index)
{
  return CClientEntityList::GetClientRenderableFromHandle(
           this: (CClientEntityList *)cl_entitylist.m_Index,
           hEnt: this->m_Recording.m_Memory.m_pMemory[index]);
}

//------------------------------------------------------------------------------
// Address: 0x1003BB20
// Name: RecvProxy_MoveType
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_MoveType(const CRecvProxyData *pData, _BYTE *pStruct)
{
  pStruct[592] = LOBYTE(pData->m_Value.m_Float);
  pStruct[593] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003BB40
// Name: public: void C_BaseEntity::Interp_RestoreToLastNetworked(struct VarMapping_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::Interp_RestoreToLastNetworked(C_BaseEntity *this, VarMapping_t *map, int flags)
{
  int v4; // ebx
  IInterpolatedVar *watcher; // esi
  int v6; // eax
  int v7; // ecx
  int m_Size; // [esp+1Ch] [ebp-4h]
  QAngle oldAngles; // 0:^C.12
  Vector oldOrigin; // 0:^18.12

  oldOrigin = this->m_vecOrigin;
  oldAngles = this->m_angRotation;
  if ( map->m_Entries.m_Size > 0 )
  {
    v4 = 0;
    m_Size = map->m_Entries.m_Size;
    do
    {
      watcher = map->m_Entries.m_Memory.m_pMemory[v4].watcher;
      v6 = watcher->GetType(this: watcher);
      if ( flags == 0 || (v6 & flags) != 0 )
        watcher->RestoreToLastNetworked(this: watcher);
      ++v4;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  v7 = 0;
  if ( oldOrigin.x != this->m_vecOrigin.x || oldOrigin.y != this->m_vecOrigin.y || oldOrigin.z != this->m_vecOrigin.z )
    v7 = 1;
  if ( oldAngles.x != this->m_angRotation.x
    || oldAngles.y != this->m_angRotation.y
    || oldAngles.z != this->m_angRotation.z )
  {
    v7 |= 2u;
  }
  if ( v7 != 0 )
    C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1003BC40
// Name: public: int C_BaseEntity::Interp_Interpolate(struct VarMapping_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::Interp_Interpolate(C_BaseEntity *this, VarMapping_t *map, float currentTime)
{
  float v3; // xmm0_4
  int v5; // eax
  int v6; // ecx
  int v7; // ebx
  VarMapEntry_t *m_pMemory; // edi
  int bNoMoreChanges; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  v3 = currentTime;
  bNoMoreChanges = 1;
  if ( map->m_lastInterpolationTime > currentTime )
  {
    v5 = 0;
    if ( map->m_nInterpolatedEntries > 0 )
    {
      v6 = 0;
      do
      {
        map->m_Entries.m_Memory.m_pMemory[v6].m_bNeedsToInterpolate = 1;
        ++v5;
        ++v6;
      }
      while ( v5 < map->m_nInterpolatedEntries );
    }
  }
  v7 = 0;
  map->m_lastInterpolationTime = currentTime;
  i = 0;
  if ( map->m_nInterpolatedEntries <= 0 )
    return 1;
  while ( 1 )
  {
    m_pMemory = map->m_Entries.m_Memory.m_pMemory;
    if ( map->m_Entries.m_Memory.m_pMemory[v7].m_bNeedsToInterpolate != 0 )
    {
      if ( ((int (__stdcall *)(float))m_pMemory[v7].watcher->Interpolate)(a1: COERCE_FLOAT(LODWORD(v3))) != 0 )
        m_pMemory[v7].m_bNeedsToInterpolate = 0;
      else
        bNoMoreChanges = 0;
    }
    ++v7;
    if ( ++i >= map->m_nInterpolatedEntries )
      break;
    v3 = currentTime;
  }
  return bNoMoreChanges;
}

//------------------------------------------------------------------------------
// Address: 0x1003BCF0
// Name: public: virtual bool C_BaseEntity::ShouldDrawForSplitScreenUser(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BaseEntity::ShouldDrawForSplitScreenUser(C_BaseEntity *this, int nSlot)
{
  return (*((_DWORD *)&this->m_nOldRenderMode + (nSlot >> 5)) & (1 << (nSlot & 0x1F))) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003BD20
// Name: private: bool C_BaseEntity::ComputeIsRenderingInFastReflections(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::ComputeIsRenderingInFastReflections(C_BaseEntity *this)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax

  if ( (this->m_fEffects & 0x400) != 0 )
    return 1;
  while ( 1 )
  {
    m_Index = this->m_pMoveParent.m_Index;
    if ( m_Index == -1 )
      break;
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      break;
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity == nullptr )
      break;
    this = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( ((int)m_pEntity[58].__vftable & 0x400) != 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003BD70
// Name: public: bool C_BaseEntity::IsRenderingInFastReflections(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
char __thiscall C_BaseEntity::IsRenderingInFastReflections(C_BaseEntity *this)
{
  return C_BaseEntity::ComputeIsRenderingInFastReflections(this);
}

//------------------------------------------------------------------------------
// Address: 0x1003BD80
// Name: private: void C_BaseEntity::OnFastReflectionRenderingChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::OnFastReflectionRenderingChanged(C_BaseEntity *this)
{
  char IsRenderingInFastReflections; // bl
  int m_hRender; // eax
  unsigned int m_Index; // ecx
  C_BaseEntity *m_pEntity; // esi
  unsigned int v6; // ecx
  IHandleEntity *v7; // eax
  int bIsReflecting; // [esp+8h] [ebp-4h]

  IsRenderingInFastReflections = C_BaseEntity::ComputeIsRenderingInFastReflections(this);
  m_hRender = this->m_hRender;
  LOBYTE(bIsReflecting) = IsRenderingInFastReflections;
  if ( (_WORD)m_hRender == 0xFFFF
    || IsRenderingInFastReflections != g_pClientLeafSystem->IsRenderingInFastReflections(
                                         this: g_pClientLeafSystem,
                                         a2: m_hRender) )
  {
    ((void (__stdcall *)(_DWORD, int))g_pClientLeafSystem->RenderInFastReflections)(
      a1: this->m_hRender,
      a2: bIsReflecting);
    m_Index = this->m_pMoveChild.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
    {
      do
      {
        C_BaseEntity::OnFastReflectionRenderingChanged(this: m_pEntity);
        v6 = m_pEntity->m_pMovePeer.m_Index;
        if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
          v7 = nullptr;
        else
          v7 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
        m_pEntity = (C_BaseEntity *)v7;
      }
      while ( v7 != nullptr );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BE50
// Name: public: virtual bool C_BaseEntity::GetShadowCastDirection(class Vector __near *,enum ShadowType_t)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::GetShadowCastDirection(C_BaseEntity *this, Vector *pDirection, ShadowType_t shadowType)
{
  float m_flShadowCastDistance; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *m_pEntity; // eax

  m_flShadowCastDistance = this->m_flShadowCastDistance;
  if ( m_flShadowCastDistance == NAN )
    return false;
  v4 = LOWORD(m_flShadowCastDistance);
  v5 = &g_pEntityList->m_EntPtrArray[LOWORD(m_flShadowCastDistance)];
  v6 = HIWORD(LODWORD(m_flShadowCastDistance));
  if ( v5->m_SerialNumber != v6 || v5->m_pEntity == nullptr )
    return false;
  v7 = v4;
  v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
  v9 = &g_pEntityList->m_EntPtrArray[v7];
  if ( v8 )
    m_pEntity = v9->m_pEntity;
  else
    m_pEntity = nullptr;
  return ((bool (__thiscall *)(IHandleEntity *, Vector *, ShadowType_t))m_pEntity[1].__vftable[7].SetRefEHandle)(
           a1: &m_pEntity[1],
           a2: pDirection,
           a3: shadowType);
}

//------------------------------------------------------------------------------
// Address: 0x1003BEB0
// Name: public: virtual class IClientRenderable __near * C_BaseEntity::GetShadowParent(void)
// Source: json
//------------------------------------------------------------------------------
IClientRenderable *__thiscall C_BaseEntity::GetShadowParent(C_BaseEntity *this)
{
  unsigned int m_nSplitUserPlayerPredictionSlot; // ecx
  IHandleEntity *m_pEntity; // eax

  m_nSplitUserPlayerPredictionSlot = this->m_nSplitUserPlayerPredictionSlot;
  if ( m_nSplitUserPlayerPredictionSlot != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_nSplitUserPlayerPredictionSlot].m_SerialNumber == HIWORD(m_nSplitUserPlayerPredictionSlot)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_nSplitUserPlayerPredictionSlot].m_pEntity) != nullptr )
  {
    return (IClientRenderable *)m_pEntity->__vftable[1].GetRefEHandle(this: m_pEntity);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BEF0
// Name: public: virtual class IClientRenderable __near * C_BaseEntity::FirstShadowChild(void)
// Source: json
//------------------------------------------------------------------------------
IClientRenderable *__thiscall C_BaseEntity::FirstShadowChild(C_BaseEntity *this)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_pMoveParent.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    return (IClientRenderable *)m_pEntity->__vftable[1].GetRefEHandle(this: m_pEntity);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BF30
// Name: public: virtual class IClientRenderable __near * C_BaseEntity::NextShadowPeer(void)
// Source: json
//------------------------------------------------------------------------------
IClientRenderable *__thiscall C_BaseEntity::NextShadowPeer(C_BaseEntity *this)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_pMoveChild.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    return (IClientRenderable *)m_pEntity->__vftable[1].GetRefEHandle(this: m_pEntity);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BF70
// Name: public: virtual int C_BaseEntity::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
const struct model_t *__userpurge C_BaseEntity::DrawModel@<eax>(
        C_BaseEntity *this@<ecx>,
        int a2@<esi>,
        int flags,
        const RenderableInstance_t *instance)
{
  const struct model_t *result; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  float z; // eax
  const char *v10; // eax
  float v11; // xmm0_4
  const char *v12; // [esp+4h] [ebp-10h]

  if ( LOBYTE(this->m_VisibilityBits.m_Ints[0]) == 0 )
    return nullptr;
  result = *(const struct model_t **)&this->m_EntClientFlags;
  v6 = 0;
  if ( result != nullptr )
  {
    v7 = modelinfo->GetModelType(this: modelinfo, a2: result) - 1;
    if ( v7 != 0 )
    {
      v8 = v7 - 1;
      if ( v8 == 0 )
      {
        _Warning(a1: "ERROR:  Sprite model's not supported any more except in legacy temp ents\n");
        C_BaseEntity::DrawBBoxVisualizations(this: (C_BaseEntity *)((char *)this - 4));
        return nullptr;
      }
      if ( v8 == 1 )
      {
        if ( *(_DWORD *)(((int (__thiscall *)(IClientRenderable *, int))this->GetRenderAngles)(
                           a1: &this->IClientRenderable,
                           a2)
                       + 8) != 0 )
          z = this->GetRenderAngles(this: &this->IClientRenderable)->z;
        else
          z = COERCE_FLOAT("unknown");
        v10 = (const char *)((int (__thiscall *)(IVModelInfoClient *, _DWORD, _DWORD))modelinfo->GetModelName)(
                              a1: modelinfo,
                              a2: *(_DWORD *)&this->m_EntClientFlags,
                              a3: LODWORD(z));
        _Warning(a1: "ERROR:  Can't draw studio model %s because %s is not derived from C_BaseAnimating\n", v10, v12);
        C_BaseEntity::DrawBBoxVisualizations(this: (C_BaseEntity *)((char *)this - 4));
        return nullptr;
      }
    }
    else
    {
      if ( (flags & 0x40000000) != 0 )
        v11 = 1.0;
      else
        v11 = (float)instance->m_nAlpha * 0.0039215689;
      ((void (__stdcall *)(_DWORD))render->SetBlend)(a1: LODWORD(v11));
      v6 = (*(int (__thiscall **)(char *, bool, bool, bool))(*((_DWORD *)this - 1) + 444))(
             a1: (char *)this - 4,
             a2: flags < 0,
             a3: (flags & 0x40000000) != 0,
             a4: (flags & 8) != 0);
    }
    C_BaseEntity::DrawBBoxVisualizations(this: (C_BaseEntity *)((char *)this - 4));
    return (const struct model_t *)v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003C0B0
// Name: public: virtual void C_BaseEntity::PreDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PreDataUpdate(C_BaseEntity *this, DataUpdateType_t updateType)
{
  IMDLCache *v3; // edi
  int m_flSimulationTime_high; // eax
  char v5; // cl

  if ( AddDataChangeEvent(
         ent: this != (C_BaseEntity *)8 ? (IClientNetworkable *)this : nullptr,
         updateType,
         pStoredEvent: (int *)&this->m_bAlternateSorting.m_Value) != 0 )
    ((void (__thiscall *)(C_BaseEntity *, DataUpdateType_t))this->GetClientNetworkable)(a1: this, a2: updateType);
  if ( updateType != DATA_UPDATE_CREATED )
  {
    C_BaseEntity::Interp_RestoreToLastNetworked(
      this: (C_BaseEntity *)((char *)this - 8),
      map: (VarMapping_t *)&this->m_hScriptInstance,
      flags: 0);
  }
  else if ( (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 2) + 476))(a1: (char *)this - 8) == 0 )
  {
    *(float *)&this->m_bDormantPredictable = engine->GetLastTimeStamp(this: engine);
    v3 = mdlcache;
    mdlcache->BeginLock(this: mdlcache);
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 2) + 128))(a1: (char *)this - 8);
    v3->EndLock(this: v3);
  }
  *(float *)&this->m_ShadowDirUseOtherEntity.m_Index = this->m_angNetworkAngles.y;
  this->m_flGroundChangeTime = this->m_angNetworkAngles.z;
  this->m_vecOldOrigin.x = this->m_vecNetworkOrigin.x;
  this->m_vecOldOrigin.y = this->m_vecBaseVelocity.y;
  this->m_vecOldOrigin.z = this->m_vecBaseVelocity.z;
  this->m_vecOldAngRotation.x = this->m_angNetworkAngles.x;
  m_flSimulationTime_high = HIWORD(this->m_flSimulationTime);
  v5 = this->m_iName[255];
  *(float *)&this->m_MoveType = *(float *)&this->m_nModelIndex;
  LOBYTE(this->m_flSimulationTime) = v5;
  this->m_flOldAnimTime = this->m_flAnimTime;
  if ( (_WORD)m_flSimulationTime_high != 0xFFFF )
    g_pClientLeafSystem->EnableAlternateSorting(
      this: g_pClientLeafSystem,
      a2: m_flSimulationTime_high,
      a3: this->m_nIntermediateData_FirstPredictedShiftMarker);
}

//------------------------------------------------------------------------------
// Address: 0x1003C1F0
// Name: public: static void C_BaseEntity::MarkAimEntsDirty(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl C_BaseEntity::MarkAimEntsDirty()
{
  int m_Size; // edx
  int i; // ecx
  C_BaseEntity *v2; // eax

  m_Size = g_AimEntsList.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v2 = g_AimEntsList.m_Memory.m_pMemory[i];
    if ( (v2->m_fEffects & 0x201) != 0 )
      v2->m_iEFlags |= 0x800u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C230
// Name: public: void C_BaseEntity::OnSimulationTimeChanging(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::OnSimulationTimeChanging(
        C_BaseEntity *this,
        float flPreviousSimulationTime,
        float flNextSimulationTime)
{
  float *v4; // esi
  unsigned int m_Index; // eax
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float dtSimulationTimestamps; // [esp+20h] [ebp-8h]
  float flTimeBeforeWhichToLeaveOldSamplesa; // [esp+24h] [ebp-4h]
  float flTimeBeforeWhichToLeaveOldSamples; // [esp+24h] [ebp-4h]
  float simtime; // [esp+30h] [ebp+8h]

  if ( !this->m_bDisableSimulationFix
    && cl_simulationtimefix.m_pParent != nullptr
    && cl_simulationtimefix.m_pParent->m_Value.m_nValue != 0
    && !this->m_bPredictable
    && !this->IsClientCreated(this)
    && this->ShouldDraw(this: &this->IClientRenderable)
    && this->m_iv_vecOrigin.m_InterpolationAmount < (float)((float)(int)(float)((float)((float)(flNextSimulationTime
                                                                                              - flPreviousSimulationTime)
                                                                                      / *(float *)(gpGlobals.m_Index + 28))
                                                                              + 0.5)
                                                          * *(float *)(gpGlobals.m_Index + 28)) )
  {
    v4 = (float *)(gpGlobals.m_Index + 28);
    flTimeBeforeWhichToLeaveOldSamplesa = *(float *)(gpGlobals.m_Index + 28);
    if ( (float)((float)(int)((((double (__thiscall *)(IVEngineClient *))engine->GetLastTimeStamp)(a1: engine)
                             - this->m_flLastMessageTime)
                            / flTimeBeforeWhichToLeaveOldSamplesa
                            + 0.5)
               * flTimeBeforeWhichToLeaveOldSamplesa) < (float)((float)(int)(float)((float)((float)(flNextSimulationTime
                                                                                                  - flPreviousSimulationTime)
                                                                                          / flTimeBeforeWhichToLeaveOldSamplesa)
                                                                                  + 0.5)
                                                              * flTimeBeforeWhichToLeaveOldSamplesa) )
    {
      dtSimulationTimestamps = (float)(int)(float)((float)(0.1 / *v4) + 0.5) * *v4;
      this->m_iv_vecOrigin.RestoreToLastNetworked(this: &this->m_iv_vecOrigin);
      this->m_iv_angRotation.RestoreToLastNetworked(this: &this->m_iv_angRotation);
      m_Index = gpGlobals.m_Index;
      v6 = flNextSimulationTime;
      v7 = (float)(*(float *)(gpGlobals.m_Index + 28) * 0.5) + flPreviousSimulationTime;
      v8 = flNextSimulationTime - dtSimulationTimestamps;
      flTimeBeforeWhichToLeaveOldSamples = v7;
      for ( simtime = flNextSimulationTime - dtSimulationTimestamps; v6 > v8; simtime = v8 )
      {
        if ( v7 <= v8 )
        {
          ((void (__thiscall *)(CDiscontinuousInterpolatedVar<Vector> *, _DWORD, _DWORD, _DWORD))this->m_iv_vecOrigin.NoteChanged)(
            a1: &this->m_iv_vecOrigin,
            a2: *(_DWORD *)(m_Index + 12),
            a3: LODWORD(v8),
            a4: 0);
          ((void (__thiscall *)(CDiscontinuousInterpolatedVar<QAngle> *, _DWORD, _DWORD, _DWORD))this->m_iv_angRotation.NoteChanged)(
            a1: &this->m_iv_angRotation,
            a2: *(_DWORD *)(gpGlobals.m_Index + 12),
            a3: LODWORD(simtime),
            a4: 0);
          m_Index = gpGlobals.m_Index;
          v6 = flNextSimulationTime;
          v7 = flTimeBeforeWhichToLeaveOldSamples;
          v8 = simtime;
        }
        v8 = v8 + *(float *)(m_Index + 28);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C420
// Name: public: virtual class C_BasePlayer __near * C_BaseEntity::GetPredictionOwner(void)
// Source: json
//------------------------------------------------------------------------------
C_BasePlayer *__thiscall C_BaseEntity::GetPredictionOwner(C_BaseEntity *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v4; // eax
  IHandleEntity *m_pEntity; // edi
  C_BaseAnimating *v6; // esi
  int v7; // esi

  if ( this != nullptr && this->IsPlayer(this) )
    return (C_BasePlayer *)this;
  m_Index = this->m_hOwnerEntity.m_Index;
  if ( m_Index != -1 )
  {
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = v4->m_pEntity;
      if ( v4->m_pEntity != nullptr && m_pEntity->__vftable[48].GetRefEHandle(this: m_pEntity) != nullptr )
        return (C_BasePlayer *)m_pEntity;
    }
  }
  m_pEntity = nullptr;
  if ( this == nullptr )
    return (C_BasePlayer *)m_pEntity;
  v6 = this->GetBaseAnimating(this);
  if ( v6 == nullptr || !v6->IsViewModel(this: v6) )
    return (C_BasePlayer *)m_pEntity;
  v7 = (int)v6->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetClientRenderable(this: v6);
  if ( v7 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v7 + 584))(a1: v7) != 0 )
    return (C_BasePlayer *)v7;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003C4D0
// Name: public: void C_BaseEntity::OnStoreLastNetworkedValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::OnStoreLastNetworkedValue(C_BaseEntity *this)
{
  int v2; // ebx
  IInterpolatedVar *watcher; // edi
  QAngle saveAng; // [esp+4h] [ebp-20h]
  Vector savePos; // [esp+10h] [ebp-14h]
  int m_Size; // [esp+1Ch] [ebp-8h]
  bool bRestore; // [esp+23h] [ebp-1h]

  bRestore = false;
  if ( this->m_bClientSideRagdoll && this->m_bPredictable )
  {
    savePos = this->m_vecOrigin;
    saveAng = this->m_angRotation;
    bRestore = true;
    C_BaseEntity::MoveToLastReceivedPosition(this, force: true);
  }
  if ( this->m_VarMap.m_Entries.m_Size > 0 )
  {
    v2 = 0;
    m_Size = this->m_VarMap.m_Entries.m_Size;
    do
    {
      watcher = this->m_VarMap.m_Entries.m_Memory.m_pMemory[v2].watcher;
      if ( (watcher->GetType(this: watcher) & 4) == 0 )
        watcher->NoteLastNetworkedValue(this: watcher);
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  if ( bRestore )
  {
    if ( savePos.x != this->m_vecOrigin.x || savePos.y != this->m_vecOrigin.y || savePos.z != this->m_vecOrigin.z )
    {
      C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 1);
      this->m_vecOrigin = savePos;
    }
    if ( saveAng.x != this->m_angRotation.x || saveAng.y != this->m_angRotation.y || saveAng.z != this->m_angRotation.z )
    {
      C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 2);
      this->m_angRotation = saveAng;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C660
// Name: public: bool C_BaseEntity::Teleported(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::Teleported(C_BaseEntity *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // edi
  unsigned int v3; // edx
  IHandleEntity *v4; // eax

  m_Index = this->m_hNetworkMoveParent.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v3 = this->m_hOldMoveParent.m_Index;
  if ( v3 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber != HIWORD(v3) )
    v4 = nullptr;
  else
    v4 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity;
  return v4 != m_pEntity || this->m_iOldParentAttachment != this->m_iParentAttachment;
}

//------------------------------------------------------------------------------
// Address: 0x1003C6D0
// Name: protected: virtual bool C_BaseEntity::ShouldInterpolate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::ShouldInterpolate(C_BaseEntity *this)
{
  IVRenderView_vtbl *v2; // edi
  int v3; // eax
  int v5; // eax
  C_BaseEntity *MoveChild; // esi
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax

  v2 = render->__vftable;
  v3 = this->entindex(this: &this->IClientNetworkable);
  if ( v2->IsViewEntity(this: render, a2: v3) )
    return 1;
  if ( this->index != 0 && this->GetModel(this: &this->IClientRenderable) != nullptr )
  {
    if ( this->m_hRender != 0xFFFF )
    {
      this->m_VisibilityBits.m_Ints[0] &= 1u;
      v5 = 0;
      while ( this->m_VisibilityBits.m_Ints[v5] == 0 )
      {
        if ( --v5 < 0 )
          goto LABEL_9;
      }
      return 1;
    }
LABEL_9:
    MoveChild = C_BaseEntity::FirstMoveChild(this);
    if ( MoveChild != nullptr )
    {
      while ( !MoveChild->ShouldInterpolate(this: MoveChild) )
      {
        m_Index = MoveChild->m_pMovePeer.m_Index;
        if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
          m_pEntity = nullptr;
        else
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        MoveChild = (C_BaseEntity *)m_pEntity;
        if ( m_pEntity == nullptr )
          return 0;
      }
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003C7A0
// Name: public: bool C_BaseEntity::IsFollowingEntity(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BaseEntity::IsFollowingEntity(C_BaseEntity *this)
{
  unsigned int m_Index; // ecx
  BOOL result; // eax

  result = false;
  if ( (this->m_fEffects & 1) != 0 && this->m_MoveType == 0 )
  {
    m_Index = this->m_pMoveParent.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003C7F0
// Name: public: class C_BaseEntity __near * C_BaseEntity::GetFollowedEntity(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall C_BaseEntity::GetFollowedEntity(C_BaseEntity *this)
{
  unsigned int m_Index; // ecx
  int v2; // eax
  CEntInfo *v3; // edx
  unsigned int v4; // ecx
  int v5; // eax
  bool v6; // zf
  CEntInfo *v7; // eax

  if ( (this->m_fEffects & 1) != 0
    && this->m_MoveType == 0
    && (m_Index = this->m_pMoveParent.m_Index) != -1
    && (v2 = (unsigned __int16)m_Index,
        v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v4 = HIWORD(m_Index),
        v3->m_SerialNumber == v4)
    && v3->m_pEntity != nullptr
    && (v5 = v2, v6 = g_pEntityList->m_EntPtrArray[v5].m_SerialNumber == v4, v7 = &g_pEntityList->m_EntPtrArray[v5], v6) )
  {
    return (C_BaseEntity *)v7->m_pEntity;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C850
// Name: public: virtual enum CollideType_t C_BaseEntity::GetCollideType(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BaseEntity::GetCollideType(C_BaseEntity *this)
{
  return this->m_nModelIndex != 0
      && this->model != nullptr
      && this->m_Collision.m_nSolidType.m_Value != 0
      && (this->m_Collision.m_usSolidFlags.m_Value & 4) == 0
      && (modelinfo->GetModelType(this: modelinfo, a2: this->model) == 1
       || modelinfo->GetModelType(this: modelinfo, a2: this->model) == 3)
      && (this->m_nModelIndex == 1 || this->m_Collision.m_flRadius != 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1003C8D0
// Name: private: void C_BaseEntity::AddStudioDecal(struct Ray_t const __near &,int,int,bool,class CGameTrace __near &,int)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge C_BaseEntity::AddStudioDecal(
        C_BaseEntity *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Ray_t *ray,
        int hitbox,
        int decalIndex,
        bool doTrace,
        CGameTrace *tr,
        int maxLODToDecal)
{
  IVModelRender_vtbl *v11; // edi
  const Ray_t *v12; // eax
  _DWORD v14[3]; // [esp-Ch] [ebp-7Ch] BYREF
  Ray_t betterRay; // [esp+0h] [ebp-70h] BYREF
  float v16; // [esp+50h] [ebp-20h]
  float v17; // [esp+54h] [ebp-1Ch]
  Vector temp; // [esp+58h] [ebp-18h] BYREF
  Vector up; // [esp+64h] [ebp-Ch]
  float retaddr; // [esp+70h] [ebp+0h]

  up.x = a2;
  up.y = retaddr;
  if ( doTrace )
  {
    enginetrace->ClipRayToEntity(this: enginetrace, a2: ray, a3: 1174421507u, a4: this, a5: tr);
    if ( tr->fraction == 1.0 )
      return;
    tr->m_pEnt = (struct CBaseEntity *)this;
  }
  if ( r_drawmodeldecals.m_pParent != nullptr && r_drawmodeldecals.m_pParent->m_Value.m_nValue != 0 )
  {
    ((void (__thiscall *)(IClientRenderable *, int, int))this->CreateModelInstance)(
      a1: &this->IClientRenderable,
      a2: a3,
      a3: a4);
    temp.x = 0.0;
    temp.y = 0.0;
    temp.z = 1.0;
    if ( !doTrace || this->GetSolid(this) != SOLID_VPHYSICS || tr->startsolid || tr->allsolid )
    {
      v11 = modelrender->__vftable;
      v14[0] = ((int (__thiscall *)(C_BaseEntity *, _DWORD, int))this->GetStudioBody)(
                 a1: this,
                 a2: 0,
                 a3: maxLODToDecal);
      v12 = ray;
    }
    else
    {
      *(float *)(&betterRay.m_IsSwept + 7) = tr->endpos.x - tr->plane.normal.x;
      v16 = tr->endpos.y - tr->plane.normal.y;
      v17 = tr->endpos.z - tr->plane.normal.z;
      betterRay.m_Extents.y = 0.0;
      Ray_t::Init(this: (Ray_t *)v14, start: &tr->endpos, end: (const Vector *)(&betterRay.m_IsSwept + 7));
      v11 = modelrender->__vftable;
      v14[0] = ((int (__thiscall *)(C_BaseEntity *, int, int))this->GetStudioBody)(a1: this, a2: 1, a3: maxLODToDecal);
      v12 = (const Ray_t *)v14;
    }
    ((void (__thiscall *)(IVModelRender *, _DWORD, const Ray_t *, Vector *, int, _DWORD))v11->AddDecal)(
      a1: modelrender,
      a2: this->m_ModelInstance,
      a3: v12,
      a4: &temp,
      a5: decalIndex,
      a6: v14[0]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CA40
// Name: public: virtual void C_BaseEntity::AddDecal(class Vector const __near &,class Vector const __near &,class Vector const __near &,int,int,bool,class CGameTrace __near &,int)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge C_BaseEntity::AddDecal(
        C_BaseEntity *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *rayStart,
        const Vector *rayEnd,
        const Vector *decalCenter,
        int hitbox,
        int decalIndex,
        bool doTrace,
        CGameTrace *tr,
        int maxLODToDecal)
{
  float v13; // xmm1_4
  float v14; // xmm2_4
  const struct model_t *model; // edx
  int v16; // eax
  _BYTE v18[12]; // [esp-Ch] [ebp-5Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-50h] BYREF
  _UNKNOWN *retaddr; // [esp+50h] [ebp+0h]

  *(_DWORD *)&ray.m_IsRay = a2;
  *(_DWORD *)(&ray.m_IsSwept + 3) = retaddr;
  v13 = rayEnd->y - rayStart->y;
  v14 = rayEnd->z - rayStart->z;
  BYTE1(ray.m_Extents.z) = (float)((float)((float)(v13 * v13)
                                         + (float)((float)(rayEnd->x - rayStart->x) * (float)(rayEnd->x - rayStart->x)))
                                 + (float)(v14 * v14)) != 0.0;
  model = this->model;
  LOBYTE(ray.m_Extents.z) = 1;
  v16 = ((int (__thiscall *)(IVModelInfoClient *, const struct model_t *, int))modelinfo->GetModelType)(
          a1: modelinfo,
          a2: model,
          a3: a4)
      - 1;
  if ( v16 != 0 )
  {
    if ( v16 == 2 )
      C_BaseEntity::AddStudioDecal(
        this,
        a2: COERCE_FLOAT((Ray_t *)&ray.m_IsRay),
        a3,
        a4: (int)this,
        ray: (const Ray_t *)v18,
        hitbox,
        decalIndex,
        doTrace,
        tr,
        maxLODToDecal);
    else
      tr->fraction = 1.0;
  }
  else
  {
    C_BaseEntity::AddBrushModelDecal(this, ray: (const Ray_t *)v18, decalCenter, decalIndex, doTrace, tr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CBA0
// Name: public: void C_BaseEntity::AddToLeafSystem(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::AddToLeafSystem(C_BaseEntity *this, BOOL bRenderWithViewModels)
{
  int m_hRender; // eax
  IClientLeafSystem *v5; // edi
  int v6; // eax
  IClientLeafSystem_vtbl *bRenderWithViewModelsa; // [esp+10h] [ebp+8h]

  m_hRender = this->m_hRender;
  this->m_bRenderWithViewModels = bRenderWithViewModels;
  if ( (_WORD)m_hRender == 0xFFFF )
  {
    v5 = g_pClientLeafSystem;
    bRenderWithViewModelsa = g_pClientLeafSystem->IClientLeafSystemEngine::__vftable;
    v6 = ((int (__thiscall *)(C_BaseEntity *, int, int))this->ComputeTranslucencyType)(a1: this, a2: -1, a3: -1);
    ((void (__thiscall *)(IClientLeafSystem *, IClientRenderable *, BOOL, int))bRenderWithViewModelsa->AddRenderable)(
      a1: v5,
      a2: &this->IClientRenderable,
      a3: bRenderWithViewModels,
      a4: v6);
    ((void (__stdcall *)(_DWORD, bool))g_pClientLeafSystem->EnableAlternateSorting)(
      a1: this->m_hRender,
      a2: this->m_bAlternateSorting.m_Value);
    ((void (__stdcall *)(_DWORD, bool))g_pClientLeafSystem->DisableCachedRenderBounds)(
      a1: this->m_hRender,
      a2: this->m_bDisableCachedRenderBounds);
  }
  else
  {
    g_pClientLeafSystem->RenderWithViewModels(this: g_pClientLeafSystem, a2: m_hRender, a3: bRenderWithViewModels);
    ((void (__stdcall *)(_DWORD, int))g_pClientLeafSystem->SetModelType)(a1: this->m_hRender, a2: -1);
    ((void (__stdcall *)(_DWORD, bool))g_pClientLeafSystem->DisableCachedRenderBounds)(
      a1: this->m_hRender,
      a2: this->m_bDisableCachedRenderBounds);
  }
  C_BaseEntity::OnFastReflectionRenderingChanged(this);
  ((void (__stdcall *)(_DWORD, bool))g_pClientLeafSystem->DisableShadowDepthRendering)(
    a1: this->m_hRender,
    a2: (this->m_fEffects & 0x800) != 0);
  ((void (__stdcall *)(_DWORD, bool))g_pClientLeafSystem->DisableShadowDepthCaching)(
    a1: this->m_hRender,
    a2: (this->m_fEffects & 0x1000) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1003CCD0
// Name: public: void C_BaseEntity::SetAbsOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetAbsOrigin(C_BaseEntity *this, const Vector *absOrigin)
{
  unsigned int m_Index; // ecx
  C_BaseEntity **v4; // eax
  C_BaseEntity *v5; // ebx

  C_BaseEntity::CalcAbsolutePosition(this);
  if ( absOrigin->x != this->m_vecAbsOrigin.x
    || absOrigin->y != this->m_vecAbsOrigin.y
    || absOrigin->z != this->m_vecAbsOrigin.z )
  {
    C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 1);
    this->m_iEFlags &= ~0x800u;
    this->m_vecAbsOrigin = *absOrigin;
    MatrixSetColumn(in: absOrigin, column: 3, out: &this->m_rgflCoordinateFrame);
    m_Index = this->m_pMoveParent.m_Index;
    if ( m_Index != -1
      && (v4 = (C_BaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
      && (v5 = *v4, *v4 != nullptr) )
    {
      C_BaseEntity::CalcAbsolutePosition(this: *v4);
      VectorITransform(in1: &absOrigin->x, in2: &v5->m_rgflCoordinateFrame, out: &this->m_vecOrigin.x);
    }
    else
    {
      this->m_vecOrigin = *absOrigin;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CDD0
// Name: public: void C_BaseEntity::SetAbsAngles(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetAbsAngles(C_BaseEntity *this, const QAngle *absAngles)
{
  unsigned int m_Index; // ecx
  C_BaseEntity **v4; // eax
  C_BaseEntity *v5; // ebx
  float *v6; // ecx
  matrix3x4_t localMatrix; // [esp+8h] [ebp-60h] BYREF
  matrix3x4_t worldToParent; // [esp+38h] [ebp-30h] BYREF

  C_BaseEntity::CalcAbsolutePosition(this);
  if ( absAngles->x != this->m_angAbsRotation.x
    || absAngles->y != this->m_angAbsRotation.y
    || absAngles->z != this->m_angAbsRotation.z )
  {
    C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 2);
    this->m_iEFlags &= ~0x800u;
    this->m_angAbsRotation = *absAngles;
    AngleMatrix(angles: absAngles, matrix: &this->m_rgflCoordinateFrame);
    MatrixSetColumn(in: &this->m_vecAbsOrigin, column: 3, out: &this->m_rgflCoordinateFrame);
    m_Index = this->m_pMoveParent.m_Index;
    if ( m_Index != -1
      && (v4 = (C_BaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
      && (v5 = *v4, *v4 != nullptr) )
    {
      v6 = (float *)v5->GetAbsAngles(this: v5);
      if ( *v6 == this->m_angAbsRotation.x && v6[1] == this->m_angAbsRotation.y && v6[2] == this->m_angAbsRotation.z )
      {
        this->m_angRotation.x = 0.0;
        this->m_angRotation.y = 0.0;
        this->m_angRotation.z = 0.0;
      }
      else
      {
        C_BaseEntity::CalcAbsolutePosition(this: v5);
        MatrixInvert(in: &v5->m_rgflCoordinateFrame, out: &worldToParent);
        ConcatTransforms(in1: &worldToParent, in2: &this->m_rgflCoordinateFrame, out: &localMatrix);
        MatrixAngles(a1: (int)&this->m_angRotation, src: (const VMatrix *)&localMatrix, vAngles: &this->m_angRotation);
      }
    }
    else
    {
      this->m_angRotation = *absAngles;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CF70
// Name: private: void C_BaseEntity::MoveToAimEnt(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::MoveToAimEnt(C_BaseEntity *this)
{
  unsigned int m_Index; // ecx
  IClientEntity *m_pEntity; // eax
  QAngle vecAimEntAngles; // [esp+4h] [ebp-18h] BYREF
  Vector vecAimEntOrigin; // [esp+10h] [ebp-Ch] BYREF

  m_Index = this->m_pMoveParent.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (IClientEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  this->GetAimEntOrigin(this, a2: m_pEntity, a3: &vecAimEntOrigin, a4: &vecAimEntAngles);
  C_BaseEntity::SetAbsOrigin(this, absOrigin: &vecAimEntOrigin);
  C_BaseEntity::SetAbsAngles(this, absAngles: &vecAimEntAngles);
}

//------------------------------------------------------------------------------
// Address: 0x1003CFE0
// Name: public: struct matrix3x4_t __near & C_BaseEntity::GetParentToWorldTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__thiscall C_BaseEntity::GetParentToWorldTransform(C_BaseEntity *this, matrix3x4_t *tempMatrix)
{
  unsigned int m_Index; // edx
  C_BaseEntity **v3; // eax
  C_BaseEntity *v4; // esi
  unsigned __int8 m_iParentAttachment; // al
  QAngle vAngles; // [esp+4h] [ebp-18h] BYREF
  Vector vOrigin; // [esp+10h] [ebp-Ch] BYREF

  m_Index = this->m_pMoveParent.m_Index;
  if ( m_Index != -1
    && (v3 = (C_BaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && (v4 = *v3, *v3 != nullptr) )
  {
    m_iParentAttachment = this->m_iParentAttachment;
    if ( m_iParentAttachment != 0
      && v4->GetAttachment_2(this: &v4->IClientRenderable, a2: m_iParentAttachment, a3: &vOrigin, a4: &vAngles) )
    {
      AngleMatrix(angles: &vAngles, position: &vOrigin, matrix: tempMatrix);
      return tempMatrix;
    }
    else
    {
      C_BaseEntity::CalcAbsolutePosition(this: v4);
      return &v4->m_rgflCoordinateFrame;
    }
  }
  else
  {
    SetIdentityMatrix(matrix: tempMatrix);
    return tempMatrix;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D090
// Name: private: void C_BaseEntity::CalcAbsolutePosition(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_BaseEntity::CalcAbsolutePosition(C_BaseEntity *this@<ecx>, int a2@<ebp>)
{
  CThreadFastMutex *p_m_CalcAbsolutePositionMutex; // edi
  DWORD CurrentThreadId; // eax
  volatile signed __int32 m_ownerID; // ecx
  int m_iEFlags; // eax
  QAngle *v7; // eax
  double y; // st7
  QAngle *p_m_angAbsRotation; // esi
  bool v10; // zf
  const matrix3x4_t *ParentToWorldTransform; // eax
  C_BaseCombatWeapon *v12; // eax
  float *v13; // eax
  int v14; // [esp-Ch] [ebp-7Ch] BYREF
  matrix3x4_t scratchMatrix; // [esp+0h] [ebp-70h] BYREF
  QAngle *p_m_angRotation; // [esp+60h] [ebp-10h]
  int v17; // [esp+64h] [ebp-Ch]
  void *v18; // [esp+68h] [ebp-8h]
  void *retaddr; // [esp+70h] [ebp+0h]

  v17 = a2;
  v18 = retaddr;
  if ( C_BaseEntity::s_bAbsRecomputationEnabled && (this->m_iEFlags & 0x800) != 0 )
  {
    p_m_CalcAbsolutePositionMutex = &this->m_CalcAbsolutePositionMutex;
    CurrentThreadId = GetCurrentThreadId();
    m_ownerID = p_m_CalcAbsolutePositionMutex->m_ownerID;
    p_m_angRotation = (QAngle *)CurrentThreadId;
    if ( CurrentThreadId != m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_CalcAbsolutePositionMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_CalcAbsolutePositionMutex, a2: p_m_angRotation, a3: 0);
    }
    else
    {
      ++this->m_CalcAbsolutePositionMutex.m_depth;
    }
    m_iEFlags = this->m_iEFlags;
    if ( (m_iEFlags & 0x800) == 0 )
    {
LABEL_10:
      v10 = p_m_CalcAbsolutePositionMutex->m_depth-- == 1;
      if ( !v10 )
        return;
      goto LABEL_11;
    }
    this->m_iEFlags = m_iEFlags & 0xFFFFF7FF;
    if ( CHandle<C_BaseEntity>::operator!(this: &this->m_pMoveParent) )
    {
      p_m_angRotation = &this->m_angRotation;
      AngleMatrix(angles: &this->m_angRotation, position: &this->m_vecOrigin, matrix: &this->m_rgflCoordinateFrame);
      v7 = &this->m_angRotation;
      this->m_vecAbsOrigin.x = this->m_vecOrigin.x;
      y = this->m_vecOrigin.y;
      p_m_angAbsRotation = &this->m_angAbsRotation;
      p_m_angAbsRotation[-3].y = y;
      p_m_angAbsRotation[-3].z = p_m_angAbsRotation[-2].z;
      p_m_angAbsRotation->x = v7->x;
      p_m_angAbsRotation->y = v7->y;
      p_m_angAbsRotation->z = v7->z;
      NormalizeAngles(angles: p_m_angAbsRotation);
      goto LABEL_10;
    }
    if ( (this->m_fEffects & 1) != 0 )
    {
      C_BaseEntity::MoveToAimEnt(this);
      v10 = this->m_CalcAbsolutePositionMutex.m_depth-- == 1;
      if ( v10 )
LABEL_11:
        _InterlockedExchange((volatile __int32 *)p_m_CalcAbsolutePositionMutex, 0);
    }
    else
    {
      AngleMatrix(angles: &this->m_angRotation, matrix: (matrix3x4_t *)&scratchMatrix.m_flMatVal[2][1]);
      MatrixSetColumn(in: &this->m_vecOrigin, column: 3, out: (matrix3x4_t *)&scratchMatrix.m_flMatVal[2][1]);
      ParentToWorldTransform = C_BaseEntity::GetParentToWorldTransform(this, tempMatrix: (matrix3x4_t *)&v14);
      ConcatTransforms(
        in1: ParentToWorldTransform,
        in2: (matrix3x4_t *)&scratchMatrix.m_flMatVal[2][1],
        out: &this->m_rgflCoordinateFrame);
      MatrixGetColumn(in: &this->m_rgflCoordinateFrame, column: 3, out: &this->m_vecAbsOrigin);
      if ( !Vector::operator==(this: &this->m_angRotation, src: &vec3_angle) || this->m_iParentAttachment != 0 )
      {
        MatrixAngles(
          a1: (int)this,
          src: (const VMatrix *)&this->m_rgflCoordinateFrame,
          vAngles: &this->m_angAbsRotation);
      }
      else
      {
        v12 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_pMoveParent);
        v13 = (float *)v12->GetAbsAngles(this: v12);
        this->m_angAbsRotation.x = *v13;
        this->m_angAbsRotation.y = v13[1];
        this->m_angAbsRotation.z = v13[2];
      }
      if ( this->m_iParentAttachment != 0
        && (CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_pMoveParent)->m_fFlags
          & 8) != 0 )
      {
        this->m_iEFlags |= 0x800u;
      }
      v10 = this->m_CalcAbsolutePositionMutex.m_depth-- == 1;
      if ( v10 )
        _InterlockedExchange((volatile __int32 *)p_m_CalcAbsolutePositionMutex, 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D2C0
// Name: private: void C_BaseEntity::CalcAbsoluteVelocity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::CalcAbsoluteVelocity(C_BaseEntity *this)
{
  CThreadFastMutex *p_m_CalcAbsoluteVelocityMutex; // ebx
  DWORD CurrentThreadId; // ecx
  int m_iEFlags; // eax
  unsigned int m_Index; // ecx
  C_BaseEntity *m_pEntity; // ecx
  bool v7; // zf
  Vector *p_m_vecAbsVelocity; // esi
  unsigned __int8 m_iParentAttachment; // al
  C_BaseEntity *v10; // edi
  Quaternion vAngleVel; // [esp+4h] [ebp-20h] BYREF
  Vector vOriginVel; // [esp+14h] [ebp-10h] BYREF
  C_BaseEntity *v13; // [esp+20h] [ebp-4h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x1000) != 0 )
  {
    p_m_CalcAbsoluteVelocityMutex = &this->m_CalcAbsoluteVelocityMutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_CalcAbsoluteVelocityMutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_CalcAbsoluteVelocityMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_CalcAbsoluteVelocityMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_CalcAbsoluteVelocityMutex.m_depth;
    }
    m_iEFlags = this->m_iEFlags;
    if ( (m_iEFlags & 0x1000) != 0 )
    {
      this->m_iEFlags = m_iEFlags & 0xFFFFEFFF;
      m_Index = this->m_pMoveParent.m_Index;
      if ( m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        || (m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity,
            v13 = m_pEntity,
            m_pEntity == nullptr) )
      {
        this->m_vecAbsVelocity.x = this->m_vecVelocity.x;
        this->m_vecAbsVelocity.y = this->m_vecVelocity.y;
        this->m_vecAbsVelocity.z = this->m_vecVelocity.z;
        v7 = this->m_CalcAbsoluteVelocityMutex.m_depth-- == 1;
        if ( v7 )
          _InterlockedExchange((volatile __int32 *)p_m_CalcAbsoluteVelocityMutex, 0);
        return;
      }
      C_BaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
      p_m_vecAbsVelocity = &this->m_vecAbsVelocity;
      VectorRotate(in1: &this->m_vecVelocity.x, in2: &v13->m_rgflCoordinateFrame, out: &this->m_vecAbsVelocity.x);
      m_iParentAttachment = this->m_iParentAttachment;
      v10 = v13;
      if ( m_iParentAttachment == 0
        || !v13->GetAttachmentVelocity(this: v13, a2: m_iParentAttachment, a3: &vOriginVel, a4: &vAngleVel) )
      {
        C_BaseEntity::CalcAbsoluteVelocity(this: v10);
        p_m_vecAbsVelocity->x = v10->m_vecAbsVelocity.x + p_m_vecAbsVelocity->x;
        p_m_vecAbsVelocity->y = v10->m_vecAbsVelocity.y + p_m_vecAbsVelocity->y;
        p_m_vecAbsVelocity->z = v10->m_vecAbsVelocity.z + p_m_vecAbsVelocity->z;
        v7 = p_m_CalcAbsoluteVelocityMutex->m_depth-- == 1;
        if ( !v7 )
          return;
        goto LABEL_18;
      }
      p_m_vecAbsVelocity->x = vOriginVel.x + p_m_vecAbsVelocity->x;
      p_m_vecAbsVelocity->y = p_m_vecAbsVelocity->y + vOriginVel.y;
      p_m_vecAbsVelocity->z = p_m_vecAbsVelocity->z + vOriginVel.z;
    }
    v7 = p_m_CalcAbsoluteVelocityMutex->m_depth-- == 1;
    if ( !v7 )
      return;
LABEL_18:
    _InterlockedExchange((volatile __int32 *)p_m_CalcAbsoluteVelocityMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D470
// Name: dlight_debug
// Source: json
//------------------------------------------------------------------------------
void __cdecl dlight_debug()
{
  dlight_t *v0; // esi
  C_BasePlayer *LocalPlayer; // edi
  float v2; // xmm2_4
  float v3; // xmm3_4
  float z; // xmm1_4
  CGameTrace tr; // [esp+8h] [ebp-78h] BYREF
  Vector end; // [esp+5Ch] [ebp-24h] BYREF
  Vector start; // [esp+68h] [ebp-18h] BYREF
  Vector forward; // [esp+74h] [ebp-Ch] BYREF

  v0 = effects->CL_AllocDlight(this: effects, a2: 1);
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    LocalPlayer->EyePosition(this: LocalPlayer, result: &start);
    C_BasePlayer::EyeVectors(this: LocalPlayer, pForward: &forward, pRight: nullptr, pUp: nullptr);
    end.y = start.y + (float)(forward.y * 56755.84);
    end.x = start.x + (float)(forward.x * 56755.84);
    end.z = start.z + (float)(forward.z * 56755.84);
    UTIL_TraceLine(
      vecAbsStart: &start,
      vecAbsEnd: &end,
      mask: 0x6004003u,
      ignore: LocalPlayer,
      collisionGroup: 0,
      ptr: &tr);
    v2 = forward.z * 12.0;
    v3 = tr.endpos.x - (float)(forward.x * 12.0);
    z = tr.endpos.z;
    v0->origin.y = tr.endpos.y - (float)(forward.y * 12.0);
    v0->origin.x = v3;
    v0->origin.z = z - v2;
    v0->radius = 200.0;
    v0->decay = 40.0;
    v0->die = *(float *)(gpGlobals.m_Index + 12) + 5.0;
    v0->color = (ColorRGBExp32)88129791;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D5C0
// Name: class C_BaseEntity __near * FindEntityInFrontOfLocalPlayer(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl FindEntityInFrontOfLocalPlayer()
{
  C_BasePlayer *LocalPlayer; // esi
  Vector *(__thiscall *EyePosition)(C_BaseEntity *, Vector *); // edx
  float *v2; // eax
  Vector *(__thiscall *v3)(C_BaseEntity *, Vector *); // edx
  const Vector *v4; // eax
  CGameTrace tr; // [esp+4h] [ebp-90h] BYREF
  Vector vecAbsEnd; // [esp+58h] [ebp-3Ch] BYREF
  Vector v8; // [esp+64h] [ebp-30h] BYREF
  Vector forward; // [esp+70h] [ebp-24h] BYREF
  unsigned int mask[3]; // [esp+7Ch] [ebp-18h] BYREF
  float v11; // [esp+88h] [ebp-Ch]
  float v12; // [esp+8Ch] [ebp-8h]
  float v13; // [esp+90h] [ebp-4h]

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer == nullptr )
    return nullptr;
  C_BasePlayer::EyeVectors(this: LocalPlayer, pForward: &forward, pRight: nullptr, pUp: nullptr);
  EyePosition = LocalPlayer->EyePosition;
  v11 = forward.x * 16384.0;
  v12 = forward.y * 16384.0;
  v13 = forward.z * 16384.0;
  v2 = (float *)EyePosition(this: LocalPlayer, result: &v8);
  v3 = LocalPlayer->EyePosition;
  *(float *)mask = *v2 + v11;
  *(float *)&mask[1] = v2[1] + v12;
  *(float *)&mask[2] = v2[2] + v13;
  v4 = (const Vector *)((int (__thiscall *)(C_BasePlayer *))v3)(a1: LocalPlayer);
  UTIL_TraceLine(
    vecAbsStart: v4,
    &vecAbsEnd,
    (unsigned int)mask,
    ignore: (const IHandleEntity *)0x200400B,
    collisionGroup: (int)LocalPlayer,
    ptr: nullptr);
  if ( tr.fraction == 1.0 )
    return nullptr;
  if ( CGameTrace::DidHitNonWorldEntity(this: &tr) )
    return (C_BaseEntity *)tr.m_pEnt;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003D6C0
// Name: RemoveDecals_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveDecals_f()
{
  C_BaseEntity *EntityInFrontOfLocalPlayer; // esi

  EntityInFrontOfLocalPlayer = FindEntityInFrontOfLocalPlayer();
  if ( EntityInFrontOfLocalPlayer != nullptr
    && modelinfo->GetModelType(this: modelinfo, a2: EntityInFrontOfLocalPlayer->model) == 3 )
  {
    EntityInFrontOfLocalPlayer->CreateModelInstance(this: &EntityInFrontOfLocalPlayer->IClientRenderable);
    ((void (__stdcall *)(_DWORD))modelrender->RemoveAllDecals)(a1: EntityInFrontOfLocalPlayer->m_ModelInstance);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D710
// Name: ToggleBBoxVisualization
// Source: json
//------------------------------------------------------------------------------
void __cdecl ToggleBBoxVisualization(unsigned __int8 fVisFlags)
{
  const CCommand *args; // ecx
  const char *v2; // eax
  int v3; // eax
  C_BaseEntity *EntityInFrontOfLocalPlayer; // eax
  unsigned __int8 m_fBBoxVisFlags; // cl

  if ( args->m_nArgc < 2 )
  {
    EntityInFrontOfLocalPlayer = FindEntityInFrontOfLocalPlayer();
  }
  else
  {
    v2 = prType;
    if ( args->m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    v3 = atoi(nptr: v2);
    if ( v3 == -1 )
      EntityInFrontOfLocalPlayer = FindEntityInFrontOfLocalPlayer();
    else
      EntityInFrontOfLocalPlayer = CClientEntityList::GetBaseEntity(
                                     this: (CClientEntityList *)cl_entitylist.m_Index,
                                     entnum: v3);
  }
  if ( EntityInFrontOfLocalPlayer != nullptr )
  {
    m_fBBoxVisFlags = EntityInFrontOfLocalPlayer->m_fBBoxVisFlags;
    if ( (m_fBBoxVisFlags & fVisFlags) != 0 )
      EntityInFrontOfLocalPlayer->m_fBBoxVisFlags = m_fBBoxVisFlags & ~fVisFlags;
    else
      EntityInFrontOfLocalPlayer->m_fBBoxVisFlags = fVisFlags | m_fBBoxVisFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D780
// Name: cl_ent_bbox
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_ent_bbox(const CCommand *args)
{
  ToggleBBoxVisualization(fVisFlags: 1, args);
}

//------------------------------------------------------------------------------
// Address: 0x1003D7A0
// Name: cl_ent_absbox
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_ent_absbox(const CCommand *args)
{
  ToggleBBoxVisualization(fVisFlags: 2, args);
}

//------------------------------------------------------------------------------
// Address: 0x1003D7C0
// Name: cl_ent_rbox
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_ent_rbox(const CCommand *args)
{
  ToggleBBoxVisualization(fVisFlags: 4, args);
}

//------------------------------------------------------------------------------
// Address: 0x1003D7E0
// Name: public: void C_BaseEntity::Interp_Reset(struct VarMapping_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::Interp_Reset(C_BaseEntity *this, VarMapping_t *map)
{
  int m_Size; // edi
  int v3; // esi

  m_Size = map->m_Entries.m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    do
    {
      ((void (__stdcall *)(_DWORD))map->m_Entries.m_Memory.m_pMemory[v3++].watcher->Reset)(a1: *(_DWORD *)(gpGlobals.m_Index + 12));
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D820
// Name: public: virtual void C_BaseEntity::ResetLatched(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::ResetLatched(C_BaseEntity *this)
{
  int m_Size; // edi
  int v3; // esi

  if ( !this->IsClientCreated(this) )
  {
    m_Size = this->m_VarMap.m_Entries.m_Size;
    if ( m_Size > 0 )
    {
      v3 = 0;
      do
      {
        ((void (__stdcall *)(_DWORD))this->m_VarMap.m_Entries.m_Memory.m_pMemory[v3++].watcher->Reset)(a1: *(_DWORD *)(gpGlobals.m_Index + 12));
        --m_Size;
      }
      while ( m_Size != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D870
// Name: AdjustInterpolationAmount
// Source: json
//------------------------------------------------------------------------------
int __usercall AdjustInterpolationAmount@<xmm0>(C_BaseEntity *pEntity@<eax>, float baseInterpolation)
{
  C_BaseEntity *v2; // esi
  float m_fValue; // xmm0_4
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  float minNPCInterpolation; // [esp+4h] [ebp-4h]

  v2 = pEntity;
  m_fValue = cl_interp_npcs.m_pParent->m_Value.m_fValue;
  if ( m_fValue <= 0.0 )
    return LODWORD(baseInterpolation);
  minNPCInterpolation = (float)((int)(float)((float)(m_fValue / *(float *)(gpGlobals.m_Index + 28)) + 0.5) + 1)
                      * *(float *)(gpGlobals.m_Index + 28);
  if ( minNPCInterpolation <= baseInterpolation || pEntity == nullptr )
    return LODWORD(baseInterpolation);
  while ( !v2->IsNPC(this: v2) )
  {
    m_Index = v2->m_pMoveParent.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v2 = (C_BaseEntity *)m_pEntity;
    if ( m_pEntity == nullptr )
      return LODWORD(baseInterpolation);
  }
  return LODWORD(minNPCInterpolation);
}

//------------------------------------------------------------------------------
// Address: 0x1003D920
// Name: public: float C_BaseEntity::GetInterpolationAmount(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseEntity::GetInterpolationAmount(C_BaseEntity *this, char flags)
{
  int v2; // edi
  unsigned int m_Index; // eax
  int v5; // eax
  bool m_Value; // al
  int v8; // eax
  int serverTickMultiple; // [esp+Ch] [ebp-4h]
  int flagsa; // [esp+18h] [ebp+8h]
  int flagsb; // [esp+18h] [ebp+8h]

  v2 = 1;
  serverTickMultiple = 1;
  if ( C_BaseEntity::IsSimulatingOnAlternateTicks() )
  {
    v2 = 2;
    serverTickMultiple = 2;
  }
  if ( this->m_bPredictable || this->IsClientCreated(this) )
    return (double)serverTickMultiple * *(float *)(gpGlobals.m_Index + 28);
  m_Index = gpGlobals.m_Index;
  if ( *(int *)(gpGlobals.m_Index + 20) > 1 && *(_BYTE *)(gpGlobals.m_Index + 49) != 0 )
    goto LABEL_9;
  if ( engine->IsPlayingDemo(this: engine) )
  {
    m_Index = gpGlobals.m_Index;
LABEL_9:
    flagsa = *(int *)(m_Index + 28);
    v5 = (int)(GetClientInterpAmount() / *(float *)&flagsa + 0.5);
    return COERCE_FLOAT(AdjustInterpolationAmount(pEntity: this, baseInterpolation: (float)(v2 + v5) * *(float *)&flagsa));
  }
  m_Value = this->m_bAnimatedEveryTick.m_Value;
  if ( m_Value && this->m_bSimulatedEveryTick.m_Value )
    return (double)serverTickMultiple * *(float *)(gpGlobals.m_Index + 28);
  if ( (flags & 1) != 0 && m_Value )
    return (double)serverTickMultiple * *(float *)(gpGlobals.m_Index + 28);
  if ( (flags & 2) != 0 && this->m_bSimulatedEveryTick.m_Value )
    return (double)serverTickMultiple * *(float *)(gpGlobals.m_Index + 28);
  flagsb = *(int *)(gpGlobals.m_Index + 28);
  v8 = (int)(GetClientInterpAmount() / *(float *)&flagsb + 0.5);
  return COERCE_FLOAT(AdjustInterpolationAmount(pEntity: this, baseInterpolation: (float)(v2 + v8) * *(float *)&flagsb));
}

//------------------------------------------------------------------------------
// Address: 0x1003DA90
// Name: public: virtual void C_BaseEntity::OnSave(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_BaseEntity::OnSave(C_BaseEntity *this@<ecx>, int a2@<ebp>)
{
  C_BaseEntity::CalcAbsolutePosition(this, a2);
  C_BaseEntity::CalcAbsoluteVelocity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1003DAA0
// Name: public: virtual int C_BaseEntity::Restore(class IRestore __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::Restore(C_BaseEntity *this, IRestore *restore)
{
  datamap_t *v3; // eax
  int v4; // ebx
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  C_BaseEntity **v11; // eax

  v3 = this->GetDataDescMap(this);
  v4 = restore->ReadAll(this: restore, a2: this, a3: v3);
  MatrixSetColumn(in: &this->m_vecAbsOrigin, column: 3, out: &this->m_rgflCoordinateFrame);
  m_Index = this->m_hGroundEntity.m_Index;
  if ( m_Index != -1 )
  {
    v6 = (unsigned __int16)m_Index;
    v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v8 = HIWORD(m_Index);
    if ( v7->m_SerialNumber == v8 && v7->m_pEntity != nullptr )
    {
      v9 = v6;
      v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
      v11 = (C_BaseEntity **)&g_pEntityList->m_EntPtrArray[v9];
      if ( v10 )
      {
        C_BaseEntity::AddEntityToGroundList(this: *v11, other: this);
        return v4;
      }
      C_BaseEntity::AddEntityToGroundList(this: nullptr, other: this);
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1003DB40
// Name: public: static void C_BaseEntity::RemoveRecipientsIfNotCloseCaptioning(class C_RecipientFilter __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::RemoveRecipientsIfNotCloseCaptioning(C_RecipientFilter *filter)
{
  if ( closecaption.m_pParent == nullptr || closecaption.m_pParent->m_Value.m_nValue == 0 )
    C_RecipientFilter::Reset(this: filter);
}

//------------------------------------------------------------------------------
// Address: 0x1003DB60
// Name: public: virtual void C_BaseEntity::GetToolRecordingState(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::GetToolRecordingState(C_BaseEntity *this, KeyValues *msg)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // ebx
  IVModelInfoClient_vtbl *v5; // edi
  const struct model_t *(__thiscall *GetModel)(IClientRenderable *); // eax
  IClientRenderable *v7; // esi
  int v8; // eax
  bool v9; // al
  unsigned int v10; // ecx
  IHandleEntity *v11; // eax
  IHandleEntity_vtbl *v12; // ecx

  if ( ToolsEnabled() )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "C_BaseEntity::GetToolRecordingState",
      a3: 0,
      a4: "Tools",
      a5: false,
      a6: 4);
    m_Index = this->m_hOwnerEntity.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( (_S9_0 & 1) == 0 )
    {
      _S9_0 |= 1u;
      *((_BYTE *)&state_0 + 16) &= 0xFCu;
      state_0.m_flTime = 0.0;
      state_0.m_pModelName = nullptr;
      state_0.m_nOwner = -1;
      state_0.m_fEffects = 0;
      state_0.m_nFollowEntity = -1;
      state_0.m_numEffects = 0;
      state_0.m_pEffects = nullptr;
      state_0.m_vecRenderOrigin.x = 0.0;
      state_0.m_vecRenderOrigin.y = 0.0;
      state_0.m_vecRenderOrigin.z = 0.0;
      state_0.m_vecRenderAngles.x = 0.0;
      state_0.m_vecRenderAngles.y = 0.0;
      state_0.m_vecRenderAngles.z = 0.0;
    }
    state_0.m_flTime = *(float *)(gpGlobals.m_Index + 12);
    v5 = modelinfo->__vftable;
    GetModel = this->GetModel;
    v7 = &this->IClientRenderable;
    v8 = (int)GetModel(this: v7);
    state_0.m_pModelName = v5->GetModelName(this: modelinfo, a2: (const struct model_t *)v8);
    if ( m_pEntity != nullptr )
      state_0.m_nOwner = ((int (__thiscall *)(IHandleEntity *))m_pEntity[2].__vftable[3].SetRefEHandle)(a1: &m_pEntity[2]);
    else
      state_0.m_nOwner = -1;
    state_0.m_fEffects = this->m_fEffects;
    v9 = v7->ShouldDraw(this: v7) && !this->IsDormant(this: &this->IClientNetworkable);
    *((_BYTE *)&state_0 + 16) = *((_BYTE *)&state_0 + 16) & 0xFC | v9;
    state_0.m_vecRenderOrigin = *v7->GetRenderOrigin(this: v7);
    state_0.m_vecRenderAngles = *v7->GetRenderAngles(this: v7);
    state_0.m_numEffects = 0;
    state_0.m_pEffects = nullptr;
    if ( m_pEntity != nullptr && ((int)m_pEntity[58].__vftable & 8) != 0 )
      state_0.m_fEffects |= 8u;
    v10 = this->m_pMoveParent.m_Index;
    if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
      v11 = nullptr;
    else
      v11 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
    if ( v11 != nullptr )
    {
      while ( ((int)v11[58].__vftable & 8) == 0 )
      {
        v12 = v11[189].__vftable;
        if ( v12 == (IHandleEntity_vtbl *)-1
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != (unsigned int)v12 >> 16 )
        {
          v11 = nullptr;
        }
        else
        {
          v11 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
        }
        if ( v11 == nullptr )
          goto LABEL_31;
      }
      state_0.m_fEffects |= 8u;
    }
LABEL_31:
    KeyValues::SetPtr(this: msg, keyName: "baseentity", value: &state_0);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E990
// Name: public: virtual void CRecordingList::RemoveFromList(class CBaseHandle)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecordingList::RemoveFromList(CRecordingList *this, CBaseHandle remove)
{
  CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Recording,
    src: (vgui::TreeNode **)&remove);
}

//------------------------------------------------------------------------------
// Address: 0x1003E9B0
// Name: void RecvProxy_SimulationTime(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_SimulationTime(const CRecvProxyData *pData, C_BaseEntity *pStruct)
{
  int v2; // eax
  int t; // [esp+10h] [ebp-14h]
  int addt; // [esp+18h] [ebp-Ch]
  float simtime; // [esp+1Ch] [ebp-8h]

  addt = pData->m_Value.m_Int;
  v2 = pStruct->entindex(this: &pStruct->IClientNetworkable);
  for ( t = addt
          + CGlobalVarsBase::GetNetworkBase(
              this: (CGlobalVarsBase *)gpGlobals.m_Index,
              nTick: *(_DWORD *)(gpGlobals.m_Index + 24),
              nEntity: v2); t < *(_DWORD *)(gpGlobals.m_Index + 24) - 127; t += 256 )
    ;
  while ( t > *(_DWORD *)(gpGlobals.m_Index + 24) + 127 )
    t -= 256;
  simtime = (float)t * *(float *)(gpGlobals.m_Index + 28);
  if ( simtime != pStruct->m_flSimulationTime )
  {
    C_BaseEntity::OnSimulationTimeChanging(
      this: pStruct,
      flPreviousSimulationTime: pStruct->m_flSimulationTime,
      flNextSimulationTime: simtime);
    pStruct->m_flSimulationTime = simtime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003EAB0
// Name: public: void C_BaseEntity::Interp_SetupMappings(struct VarMapping_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::Interp_SetupMappings(C_BaseEntity *this, VarMapping_t *map)
{
  VarMapping_t *v2; // eax
  int v3; // ebx
  VarMapEntry_t *m_pMemory; // eax
  IInterpolatedVar *watcher; // esi
  IInterpolatedVar_vtbl *v6; // edi
  char v7; // al
  float InterpolationAmount; // [esp+8h] [ebp-18h]
  int m_Size; // [esp+1Ch] [ebp-4h]

  v2 = map;
  if ( map != nullptr && map->m_Entries.m_Size > 0 )
  {
    v3 = 0;
    m_Size = map->m_Entries.m_Size;
    while ( 1 )
    {
      m_pMemory = v2->m_Entries.m_Memory.m_pMemory;
      watcher = m_pMemory[v3].watcher;
      watcher->Setup(this: watcher, a2: m_pMemory[v3].data, a3: m_pMemory[v3].type);
      v6 = watcher->__vftable;
      v7 = watcher->GetType(this: watcher);
      InterpolationAmount = C_BaseEntity::GetInterpolationAmount(this, flags: v7);
      ((void (__thiscall *)(IInterpolatedVar *, _DWORD))v6->SetInterpolationAmount)(
        a1: watcher,
        a2: LODWORD(InterpolationAmount));
      ++v3;
      if ( --m_Size == 0 )
        break;
      v2 = map;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003EB20
// Name: public: void C_BaseEntity::Interp_UpdateInterpolationAmounts(struct VarMapping_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::Interp_UpdateInterpolationAmounts(C_BaseEntity *this, VarMapping_t *map)
{
  VarMapping_t *v2; // eax
  int v3; // ebx
  IInterpolatedVar *watcher; // esi
  IInterpolatedVar_vtbl *v5; // edi
  char v6; // al
  float InterpolationAmount; // [esp+0h] [ebp-18h]
  int m_Size; // [esp+14h] [ebp-4h]

  v2 = map;
  if ( map != nullptr && map->m_Entries.m_Size > 0 )
  {
    v3 = 0;
    m_Size = map->m_Entries.m_Size;
    while ( 1 )
    {
      watcher = v2->m_Entries.m_Memory.m_pMemory[v3].watcher;
      v5 = watcher->__vftable;
      v6 = watcher->GetType(this: watcher);
      InterpolationAmount = C_BaseEntity::GetInterpolationAmount(this, flags: v6);
      ((void (__thiscall *)(IInterpolatedVar *, _DWORD))v5->SetInterpolationAmount)(
        a1: watcher,
        a2: LODWORD(InterpolationAmount));
      ++v3;
      if ( --m_Size == 0 )
        break;
      v2 = map;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003EB80
// Name: public: void C_BaseEntity::Interp_HierarchyUpdateInterpolationAmounts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::Interp_HierarchyUpdateInterpolationAmounts(C_BaseEntity *this)
{
  unsigned int m_Index; // ecx
  C_BaseEntity *m_pEntity; // esi
  unsigned int v4; // ecx
  IHandleEntity *v5; // eax

  C_BaseEntity::Interp_UpdateInterpolationAmounts(this, map: &this->m_VarMap);
  m_Index = this->m_pMoveChild.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != nullptr )
  {
    do
    {
      C_BaseEntity::Interp_HierarchyUpdateInterpolationAmounts(this: m_pEntity);
      v4 = m_pEntity->m_pMovePeer.m_Index;
      if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
        v5 = nullptr;
      else
        v5 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
      m_pEntity = (C_BaseEntity *)v5;
    }
    while ( v5 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003EC00
// Name: public: virtual bool C_BaseEntity::Init(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::Init(C_BaseEntity *this, int entnum, int iSerialNum)
{
  int v3; // edi
  CClientAlphaProperty *m_pClientAlphaProperty; // ecx
  IHandleEntity *v6; // eax
  int v8; // [esp-4h] [ebp-Ch]

  v3 = entnum;
  m_pClientAlphaProperty = this->m_pClientAlphaProperty;
  this->index = entnum;
  m_pClientAlphaProperty->SetDesyncOffset(this: m_pClientAlphaProperty, a2: v3);
  v8 = iSerialNum;
  v6 = (IHandleEntity *)this->GetIClientUnknown(this: &this->IClientRenderable);
  CBaseEntityList::AddNetworkableEntity(
    this: (CBaseEntityList *)cl_entitylist.m_Index,
    result: (CBaseHandle *)&entnum,
    pEnt: v6,
    index: v3,
    iForcedSerialNum: v8);
  CCollisionProperty::CreatePartitionHandle(this: &this->m_Collision);
  this->InitSharedVars(this);
  C_BaseEntity::Interp_SetupMappings(this, map: &this->m_VarMap);
  this->m_nCreationTick = *(_DWORD *)(gpGlobals.m_Index + 24);
  this->m_hScriptInstance = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003EC80
// Name: public: void C_BaseEntity::SetRenderAlpha(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetRenderAlpha(C_BaseEntity *this, int a)
{
  if ( this->m_clrRender.m_Value.a != (_BYTE)a )
  {
    this->m_clrRender.m_Value.a = a;
    this->m_pClientAlphaProperty->SetAlphaModulation(this: this->m_pClientAlphaProperty, a2: a);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003ECA0
// Name: public: void C_BaseEntity::GetVectors(class Vector __near *,class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::GetVectors(C_BaseEntity *this, Vector *pForward, Vector *pRight, Vector *pUp)
{
  matrix3x4_t *p_m_rgflCoordinateFrame; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  C_BaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  p_m_rgflCoordinateFrame = &this->m_rgflCoordinateFrame;
  if ( pForward != nullptr )
    MatrixGetColumn(in: &this->m_rgflCoordinateFrame, column: 0, out: pForward);
  if ( pRight != nullptr )
  {
    MatrixGetColumn(in: p_m_rgflCoordinateFrame, column: 1, out: pRight);
    pRight->x = pRight->x * -1.0;
    pRight->y = pRight->y * -1.0;
    pRight->z = pRight->z * -1.0;
  }
  if ( pUp != nullptr )
    MatrixGetColumn(in: p_m_rgflCoordinateFrame, column: 2, out: pUp);
}

//------------------------------------------------------------------------------
// Address: 0x1003ED30
// Name: public: virtual class Vector const __near & C_BaseEntity::GetAbsOrigin(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__usercall C_BaseEntity::GetAbsOrigin@<eax>(C_BaseEntity *this@<ecx>, int a2@<ebp>)
{
  C_BaseEntity::CalcAbsolutePosition(this, a2);
  return &this->m_vecAbsOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x1003ED40
// Name: public: virtual class QAngle const __near & C_BaseEntity::GetAbsAngles(void)const
// Source: json
//------------------------------------------------------------------------------
const QAngle *__usercall C_BaseEntity::GetAbsAngles@<eax>(C_BaseEntity *this@<ecx>, int a2@<ebp>)
{
  C_BaseEntity::CalcAbsolutePosition(this, a2);
  return &this->m_angAbsRotation;
}

//------------------------------------------------------------------------------
// Address: 0x1003ED50
// Name: public: virtual bool C_BaseEntity::GetAttachmentVelocity(int,class Vector __near &,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::GetAttachmentVelocity(
        C_BaseEntity *this,
        int number,
        Vector *originVel,
        Quaternion *angleVel)
{
  C_BaseEntity::CalcAbsoluteVelocity(this);
  *originVel = this->m_vecAbsVelocity;
  angleVel->x = 0.0;
  angleVel->y = 0.0;
  angleVel->z = 0.0;
  angleVel->w = 0.0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003EDA0
// Name: public: static void C_BaseEntity::CalcAimEntPositions(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall C_BaseEntity::CalcAimEntPositions(int a1@<ebp>)
{
  int v1; // eax
  C_BaseEntity *v2; // esi
  CThreadFastMutex *p_m_CalcAbsolutePositionMutex; // edi
  DWORD CurrentThreadId; // eax
  volatile unsigned int m_ownerID; // edx
  int m_iEFlags; // eax
  unsigned int m_Index; // eax
  float *v8; // eax
  double y; // st7
  QAngle *p_m_angAbsRotation; // esi
  bool v11; // zf
  const matrix3x4_t *ParentToWorldTransform; // eax
  C_BaseCombatWeapon *v13; // eax
  float *v14; // eax
  matrix3x4_t v15; // [esp-70h] [ebp-7Ch] BYREF
  matrix3x4_t v16; // [esp-40h] [ebp-4Ch] BYREF
  int m_Size; // [esp-Ch] [ebp-18h]
  float *p_x; // [esp-8h] [ebp-14h]
  int i; // [esp-4h] [ebp-10h]
  int c; // [esp+0h] [ebp-Ch]
  void *v21; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  c = a1;
  v21 = retaddr;
  v1 = 0;
  m_Size = g_AimEntsList.m_Size;
  for ( i = 0; v1 < m_Size; i = v1 )
  {
    v2 = g_AimEntsList.m_Memory.m_pMemory[v1];
    if ( (v2->m_fEffects & 1) == 0 || !C_BaseEntity::s_bAbsRecomputationEnabled || (v2->m_iEFlags & 0x800) == 0 )
      goto LABEL_29;
    p_m_CalcAbsolutePositionMutex = &v2->m_CalcAbsolutePositionMutex;
    CurrentThreadId = GetCurrentThreadId();
    m_ownerID = v2->m_CalcAbsolutePositionMutex.m_ownerID;
    p_x = (float *)CurrentThreadId;
    if ( CurrentThreadId != m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_CalcAbsolutePositionMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &v2->m_CalcAbsolutePositionMutex, a2: p_x, a3: 0);
    }
    else
    {
      ++v2->m_CalcAbsolutePositionMutex.m_depth;
    }
    m_iEFlags = v2->m_iEFlags;
    if ( (m_iEFlags & 0x800) != 0 )
    {
      v2->m_iEFlags = m_iEFlags & 0xFFFFF7FF;
      m_Index = v2->m_pMoveParent.m_Index;
      if ( m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
      {
        p_x = &v2->m_angRotation.x;
        AngleMatrix(angles: &v2->m_angRotation, position: &v2->m_vecOrigin, matrix: &v2->m_rgflCoordinateFrame);
        v8 = p_x;
        v2->m_vecAbsOrigin.x = v2->m_vecOrigin.x;
        y = v2->m_vecOrigin.y;
        p_m_angAbsRotation = &v2->m_angAbsRotation;
        p_m_angAbsRotation[-3].y = y;
        p_m_angAbsRotation[-3].z = p_m_angAbsRotation[-2].z;
        p_m_angAbsRotation->x = *v8;
        p_m_angAbsRotation->y = v8[1];
        p_m_angAbsRotation->z = v8[2];
        NormalizeAngles(angles: p_m_angAbsRotation);
        v11 = p_m_CalcAbsolutePositionMutex->m_depth-- == 1;
        if ( v11 )
          goto LABEL_28;
        goto LABEL_29;
      }
      if ( (v2->m_fEffects & 1) != 0 )
      {
        C_BaseEntity::MoveToAimEnt(this: v2);
        v11 = v2->m_CalcAbsolutePositionMutex.m_depth-- == 1;
        if ( v11 )
          goto LABEL_28;
        goto LABEL_29;
      }
      AngleMatrix(angles: &v2->m_angRotation, matrix: &v16);
      MatrixSetColumn(in: &v2->m_vecOrigin, column: 3, out: &v16);
      ParentToWorldTransform = C_BaseEntity::GetParentToWorldTransform(this: v2, tempMatrix: &v15);
      ConcatTransforms(in1: ParentToWorldTransform, in2: &v16, out: &v2->m_rgflCoordinateFrame);
      MatrixGetColumn(in: &v2->m_rgflCoordinateFrame, column: 3, out: &v2->m_vecAbsOrigin);
      if ( vec3_angle.x == v2->m_angRotation.x
        && vec3_angle.y == v2->m_angRotation.y
        && vec3_angle.z == v2->m_angRotation.z
        && v2->m_iParentAttachment == 0 )
      {
        v13 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&v2->m_pMoveParent);
        v14 = (float *)v13->GetAbsAngles(this: v13);
        v2->m_angAbsRotation.x = *v14;
        v2->m_angAbsRotation.y = v14[1];
        v2->m_angAbsRotation.z = v14[2];
      }
      else
      {
        MatrixAngles(a1: (int)v2, src: (const VMatrix *)&v2->m_rgflCoordinateFrame, vAngles: &v2->m_angAbsRotation);
      }
      if ( v2->m_iParentAttachment != 0
        && (CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&v2->m_pMoveParent)->m_fFlags
          & 8) != 0 )
      {
        v2->m_iEFlags |= 0x800u;
      }
    }
    v11 = v2->m_CalcAbsolutePositionMutex.m_depth-- == 1;
    if ( v11 )
LABEL_28:
      _InterlockedExchange((volatile __int32 *)p_m_CalcAbsolutePositionMutex, 0);
LABEL_29:
    v1 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F050
// Name: public: void C_BaseEntity::RemoveFromAimEntsList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::RemoveFromAimEntsList(C_BaseEntity *this)
{
  unsigned int m_AimEntsListHandle; // esi
  C_BaseEntity *v2; // edi

  m_AimEntsListHandle = this->m_AimEntsListHandle;
  if ( m_AimEntsListHandle != -1 )
  {
    if ( g_AimEntsList.m_Size - 1 == m_AimEntsListHandle )
    {
      if ( g_AimEntsList.m_Size > 0 )
      {
        --g_AimEntsList.m_Size;
        this->m_AimEntsListHandle = -1;
        return;
      }
    }
    else
    {
      v2 = g_AimEntsList.m_Memory.m_pMemory[g_AimEntsList.m_Size - 1];
      if ( g_AimEntsList.m_Size > 0 )
        --g_AimEntsList.m_Size;
      v2->m_AimEntsListHandle = this->m_AimEntsListHandle;
      g_AimEntsList.m_Memory.m_pMemory[this->m_AimEntsListHandle] = v2;
    }
    this->m_AimEntsListHandle = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F0F0
// Name: protected: int C_BaseEntity::BaseInterpolatePart1(float __near &,class Vector __near &,class QAngle __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseEntity::BaseInterpolatePart1(
        C_BaseEntity *this,
        float *currentTime,
        Vector *oldOrigin,
        QAngle *oldAngles,
        int *bNoMoreChanges)
{
  unsigned int v7; // ecx
  C_BasePlayer *LocalPlayer; // ecx
  unsigned int m_Index; // eax
  float v10; // xmm0_4
  float bNoMoreChangesa; // [esp+24h] [ebp+14h]

  *bNoMoreChanges = 1;
  if ( (this->m_fEffects & 1) != 0
    && this->m_MoveType == 0
    && (v7 = this->m_pMoveParent.m_Index) != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity != nullptr
    || !C_BaseEntity::s_bInterpolate )
  {
    C_BaseEntity::MoveToLastReceivedPosition(this, force: false);
    return 0;
  }
  else
  {
    if ( this->m_bPredictable || this->IsClientCreated(this) )
    {
      LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: this->m_nSplitUserPlayerPredictionSlot);
      if ( LocalPlayer != nullptr && *currentTime == *(float *)(gpGlobals.m_Index + 12) )
      {
        bNoMoreChangesa = C_BasePlayer::GetFinalPredictedTime(this: LocalPlayer);
        *currentTime = bNoMoreChangesa;
        m_Index = gpGlobals.m_Index;
        v10 = bNoMoreChangesa - *(float *)(gpGlobals.m_Index + 28);
        *currentTime = v10;
        *currentTime = (float)(*(float *)(gpGlobals.m_Index + 32) * *(float *)(m_Index + 28)) + v10;
      }
    }
    *oldOrigin = this->m_vecOrigin;
    *oldAngles = this->m_angRotation;
    *bNoMoreChanges = C_BaseEntity::Interp_Interpolate(this, map: &this->m_VarMap, currentTime: *currentTime);
    if ( cl_interp_all.m_pParent != nullptr && cl_interp_all.m_pParent->m_Value.m_nValue != 0
      || (this->m_EntClientFlags & 4) != 0 )
    {
      *bNoMoreChanges = 0;
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F260
// Name: protected: static void C_BaseEntity::ProcessInterpolatedList(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl C_BaseEntity::ProcessInterpolatedList()
{
  unsigned __int16 m_Head; // ax
  C_RopeKeyframe *m_Element; // esi
  int m_Next; // edi

  m_Head = g_EntityLists.m_Head;
  if ( g_EntityLists.m_Head != 0xFFFF )
  {
    do
    {
      m_Element = g_EntityLists.m_Memory.m_pMemory[m_Head].m_Element;
      m_Next = g_EntityLists.m_Memory.m_pMemory[m_Head].m_Next;
      m_Element->m_bReadyToDraw = ((int (__thiscall *)(C_RopeKeyframe *, _DWORD))m_Element->Interpolate)(
                                    a1: m_Element,
                                    a2: *(_DWORD *)(gpGlobals.m_Index + 12));
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F2C0
// Name: public: void C_BaseEntity::SetAbsVelocity(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetAbsVelocity(C_BaseEntity *this, const Vector *vecAbsVelocity)
{
  unsigned int m_Index; // ecx
  C_BaseEntity **v4; // eax
  C_BaseEntity *v5; // ebx
  Vector relVelocity; // [esp+8h] [ebp-Ch] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  if ( vecAbsVelocity->x != this->m_vecAbsVelocity.x
    || vecAbsVelocity->y != this->m_vecAbsVelocity.y
    || vecAbsVelocity->z != this->m_vecAbsVelocity.z )
  {
    C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 4);
    this->m_iEFlags &= ~0x1000u;
    this->m_vecAbsVelocity = *vecAbsVelocity;
    m_Index = this->m_pMoveParent.m_Index;
    if ( m_Index != -1
      && (v4 = (C_BaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
      && (v5 = *v4, *v4 != nullptr) )
    {
      C_BaseEntity::CalcAbsoluteVelocity(this: *v4);
      relVelocity.x = vecAbsVelocity->x - v5->m_vecAbsVelocity.x;
      relVelocity.y = vecAbsVelocity->y - v5->m_vecAbsVelocity.y;
      relVelocity.z = vecAbsVelocity->z - v5->m_vecAbsVelocity.z;
      C_BaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&savedregs);
      VectorIRotate(in1: &relVelocity.x, in2: &v5->m_rgflCoordinateFrame, out: &this->m_vecVelocity.x);
    }
    else
    {
      this->m_vecVelocity = *vecAbsVelocity;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F3F0
// Name: public: virtual void C_BaseEntity::SetPredictable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetPredictable(C_BaseEntity *this, bool state)
{
  this->m_bPredictable = state;
  C_BaseEntity::Interp_UpdateInterpolationAmounts(this, map: &this->m_VarMap);
}

//------------------------------------------------------------------------------
// Address: 0x1003F410
// Name: public: virtual class Vector const __near & C_BaseEntity::GetPrevLocalOrigin(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_BaseEntity::GetPrevLocalOrigin(C_BaseEntity *this)
{
  unsigned int m_maxElement; // edx
  unsigned int v2; // eax

  if ( this->m_iv_vecOrigin.m_VarHistory.m_count <= 1u )
    return this->m_iv_vecOrigin.m_pValue;
  m_maxElement = this->m_iv_vecOrigin.m_VarHistory.m_maxElement;
  v2 = this->m_iv_vecOrigin.m_VarHistory.m_firstElement + 1;
  if ( v2 >= m_maxElement )
    v2 -= m_maxElement;
  return &this->m_iv_vecOrigin.m_VarHistory.m_pElements[v2].value;
}

//------------------------------------------------------------------------------
// Address: 0x1003F450
// Name: public: virtual class QAngle const __near & C_BaseEntity::GetPrevLocalAngles(void)const
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall C_BaseEntity::GetPrevLocalAngles(C_BaseEntity *this)
{
  unsigned int m_maxElement; // edx
  unsigned int v2; // eax

  if ( this->m_iv_angRotation.m_VarHistory.m_count <= 1u )
    return this->m_iv_angRotation.m_pValue;
  m_maxElement = this->m_iv_angRotation.m_VarHistory.m_maxElement;
  v2 = this->m_iv_angRotation.m_VarHistory.m_firstElement + 1;
  if ( v2 >= m_maxElement )
    v2 -= m_maxElement;
  return &this->m_iv_angRotation.m_VarHistory.m_pElements[v2].value;
}

//------------------------------------------------------------------------------
// Address: 0x1003F490
// Name: public: static void C_BaseEntity::CheckCLInterpChanged(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl C_BaseEntity::CheckCLInterpChanged()
{
  unsigned int v0; // eax
  float m_fValue; // xmm0_4
  C_BaseEntity *v2; // eax
  int v3; // ebx
  IInterpolatedVar *watcher; // esi
  IInterpolatedVar_vtbl *v5; // edi
  char v6; // al
  float InterpolationAmount; // [esp+0h] [ebp-1Ch]
  float flCurValue_Interp; // [esp+10h] [ebp-Ch]
  int flCurValue_Interpa; // [esp+10h] [ebp-Ch]
  C_BaseEntity *pEnt; // [esp+14h] [ebp-8h]
  C_BaseEntityIterator iterator; // [esp+18h] [ebp-4h] BYREF

  flCurValue_Interp = GetClientInterpAmount();
  v0 = _S10_0;
  if ( (_S10_0 & 1) == 0 )
  {
    v0 = _S10_0 | 1;
    _S10_0 |= 1u;
    flLastValue_Interp = flCurValue_Interp;
  }
  m_fValue = cl_interp_npcs.m_pParent->m_Value.m_fValue;
  if ( (v0 & 2) == 0 )
  {
    _S10_0 = v0 | 2;
    flLastValue_InterpNPCs = m_fValue;
  }
  if ( flLastValue_Interp != flCurValue_Interp || flLastValue_InterpNPCs != m_fValue )
  {
    flLastValue_Interp = flCurValue_Interp;
    flLastValue_InterpNPCs = m_fValue;
    C_BaseEntityIterator::C_BaseEntityIterator(this: &iterator);
    v2 = C_BaseEntityIterator::Next(this: &iterator);
    pEnt = v2;
    if ( v2 != nullptr )
    {
      while ( 1 )
      {
        if ( v2 != (C_BaseEntity *)-32 && v2->m_VarMap.m_Entries.m_Size > 0 )
        {
          v3 = 0;
          flCurValue_Interpa = v2->m_VarMap.m_Entries.m_Size;
          while ( 1 )
          {
            watcher = v2->m_VarMap.m_Entries.m_Memory.m_pMemory[v3].watcher;
            v5 = watcher->__vftable;
            v6 = watcher->GetType(this: watcher);
            InterpolationAmount = C_BaseEntity::GetInterpolationAmount(this: pEnt, flags: v6);
            ((void (__thiscall *)(IInterpolatedVar *, _DWORD))v5->SetInterpolationAmount)(
              a1: watcher,
              a2: LODWORD(InterpolationAmount));
            ++v3;
            if ( --flCurValue_Interpa == 0 )
              break;
            v2 = pEnt;
          }
        }
        pEnt = C_BaseEntityIterator::Next(this: &iterator);
        if ( pEnt == nullptr )
          break;
        v2 = pEnt;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F8C0
// Name: public: class Vector const __near & C_BaseEntity::ScriptGetForward(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__usercall C_BaseEntity::ScriptGetForward@<eax>(C_BaseEntity *this@<ecx>, int a2@<ebp>)
{
  if ( (`C_BaseEntity::ScriptGetForward'::`2'::`local static guard' & 1) == 0 )
    `C_BaseEntity::ScriptGetForward'::`2'::`local static guard' |= 1u;
  C_BaseEntity::CalcAbsolutePosition(this, a2);
  MatrixGetColumn(in: &this->m_rgflCoordinateFrame, column: 0, out: &`C_BaseEntity::ScriptGetForward'::`2'::vecForward);
  return &`C_BaseEntity::ScriptGetForward'::`2'::vecForward;
}

//------------------------------------------------------------------------------
// Address: 0x1003F900
// Name: public: class Vector const __near & C_BaseEntity::ScriptGetLeft(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__usercall C_BaseEntity::ScriptGetLeft@<eax>(C_BaseEntity *this@<ecx>, int a2@<ebp>)
{
  if ( (`C_BaseEntity::ScriptGetLeft'::`2'::`local static guard' & 1) == 0 )
    `C_BaseEntity::ScriptGetLeft'::`2'::`local static guard' |= 1u;
  C_BaseEntity::CalcAbsolutePosition(this, a2);
  MatrixGetColumn(in: &this->m_rgflCoordinateFrame, column: 1, out: &`C_BaseEntity::ScriptGetLeft'::`2'::vecLeft);
  `C_BaseEntity::ScriptGetLeft'::`2'::vecLeft.x = `C_BaseEntity::ScriptGetLeft'::`2'::vecLeft.x * -1.0;
  `C_BaseEntity::ScriptGetLeft'::`2'::vecLeft.y = `C_BaseEntity::ScriptGetLeft'::`2'::vecLeft.y * -1.0;
  `C_BaseEntity::ScriptGetLeft'::`2'::vecLeft.z = `C_BaseEntity::ScriptGetLeft'::`2'::vecLeft.z * -1.0;
  return &`C_BaseEntity::ScriptGetLeft'::`2'::vecLeft;
}

//------------------------------------------------------------------------------
// Address: 0x1003F980
// Name: public: class Vector const __near & C_BaseEntity::ScriptGetUp(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__usercall C_BaseEntity::ScriptGetUp@<eax>(C_BaseEntity *this@<ecx>, int a2@<ebp>)
{
  if ( (`C_BaseEntity::ScriptGetUp'::`2'::`local static guard' & 1) == 0 )
    `C_BaseEntity::ScriptGetUp'::`2'::`local static guard' |= 1u;
  C_BaseEntity::CalcAbsolutePosition(this, a2);
  MatrixGetColumn(in: &this->m_rgflCoordinateFrame, column: 2, out: &`C_BaseEntity::ScriptGetUp'::`2'::vecUp);
  return &`C_BaseEntity::ScriptGetUp'::`2'::vecUp;
}

//------------------------------------------------------------------------------
// Address: 0x1003FA70
// Name: class QAngle ExtrapolateInterpolatedVarType(class QAngle const __near &,class QAngle const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
QAngle *__cdecl ExtrapolateInterpolatedVarType(
        QAngle *result,
        const QAngle *oldVal,
        const QAngle *newVal,
        float divisor,
        float flExtrapolationAmount)
{
  float z; // ecx
  Quaternion qt; // [esp+Ch] [ebp-3Ch] BYREF
  Quaternion outQuat; // [esp+1Ch] [ebp-2Ch] BYREF
  Quaternion q; // [esp+2Ch] [ebp-1Ch] BYREF
  QAngle angles; // [esp+3Ch] [ebp-Ch] BYREF

  if ( newVal->x == oldVal->x && newVal->y == oldVal->y && newVal->z == oldVal->z )
  {
    z = oldVal->z;
    *(_QWORD *)&result->x = *(_QWORD *)&oldVal->x;
    result->z = z;
    return result;
  }
  else
  {
    AngleQuaternion(angles: oldVal, &outQuat);
    AngleQuaternion(angles: newVal, outQuat: &q);
    QuaternionSlerp(p: &outQuat, &q, t: (float)(divisor * flExtrapolationAmount) + 1.0, &qt);
    QuaternionAngles(q: &qt, &angles);
    *result = angles;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040C00
// Name: void RecvProxy_ClrRender(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_ClrRender(const CRecvProxyData *pData, _BYTE *pStruct)
{
  int m_Int; // ecx

  m_Int = pData->m_Value.m_Int;
  if ( pStruct[108] != (_BYTE)m_Int )
    pStruct[108] = m_Int;
  if ( pStruct[109] != BYTE1(m_Int) )
    pStruct[109] = BYTE1(m_Int);
  if ( pStruct[110] != BYTE2(m_Int) )
    pStruct[110] = BYTE2(m_Int);
  if ( pStruct[111] != HIBYTE(m_Int) )
  {
    pStruct[111] = HIBYTE(m_Int);
    (*(void (__thiscall **)(_DWORD, _BYTE))(**((_DWORD **)pStruct + 226) + 4))(
      a1: *((_DWORD *)pStruct + 226),
      a2: HIBYTE(m_Int));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100410B0
// Name: public: void C_BaseEntity::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::Term(C_BaseEntity *this)
{
  int m_Size; // edx
  int v3; // eax
  C_BaseEntity **m_pMemory; // ecx

  C_BaseEntity::PhysicsRemoveTouchedList(ent: this);
  C_BaseEntity::PhysicsRemoveGroundList(ent: this);
  C_BaseEntity::DestroyAllDataObjects(this);
  if ( this->m_bPredictable || this->IsClientCreated(this) )
  {
    m_Size = g_Predictables.m_Size;
    v3 = 0;
    if ( g_Predictables.m_Size > 0 )
    {
      m_pMemory = g_Predictables.m_Memory.m_pMemory;
      while ( *m_pMemory != this )
      {
        ++v3;
        ++m_pMemory;
        if ( v3 >= g_Predictables.m_Size )
          goto LABEL_12;
      }
      if ( v3 != -1 )
      {
        if ( g_Predictables.m_Size - v3 - 1 > 0 )
        {
          _V_memmove(
            dest: &g_Predictables.m_Memory.m_pMemory[v3],
            src: &g_Predictables.m_Memory.m_pMemory[v3 + 1],
            count: 4 * (g_Predictables.m_Size - v3 - 1));
          m_Size = g_Predictables.m_Size;
        }
        g_Predictables.m_Size = m_Size - 1;
      }
    }
  }
LABEL_12:
  if ( this->m_bIsPlayerSimulated )
    C_BaseEntity::UnsetPlayerSimulated(this);
  if ( this->m_RefEHandle.m_Index != -1 )
  {
    if ( this->GetThinkHandle(this: &this->IClientThinkable) != (struct CClientThinkHandlePtr *)0xFFFF )
      CClientThinkList::RemoveThinkable(this: &g_ClientThinkList, hEnt: this->m_RefEHandle);
    CBaseEntityList::RemoveEntity(this: (CBaseEntityList *)cl_entitylist.m_Index, handle: this->m_RefEHandle);
    this->m_RefEHandle.m_Index = -1;
  }
  CCollisionProperty::DestroyPartitionHandle(this: &this->m_Collision);
  if ( this->index != -1 )
    beams->KillDeadBeams(this: beams, a2: this);
  if ( this->m_ModelInstance != 0xFFFF )
  {
    modelrender->DestroyInstance(this: modelrender, a2: this->m_ModelInstance);
    this->m_ModelInstance = -1;
  }
  if ( this->m_hRender != 0xFFFF )
  {
    g_pClientLeafSystem->RemoveRenderable(this: g_pClientLeafSystem, a2: this->m_hRender);
    this->m_hRender = -1;
  }
  if ( this->m_ShadowHandle != 0xFFFF )
  {
    g_pClientShadowMgr->DestroyShadow(this: g_pClientShadowMgr, a2: this->m_ShadowHandle);
    this->m_ShadowHandle = -1;
  }
  C_BaseEntity::RemoveFromAimEntsList(this);
  if ( this->m_hScriptInstance != nullptr )
  {
    g_pScriptVM->RemoveInstance(this: g_pScriptVM, a2: this->m_hScriptInstance);
    this->m_hScriptInstance = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041260
// Name: public: void C_BaseEntity::UpdateVisibility(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::UpdateVisibility(C_BaseEntity *this)
{
  CBitVec<1> *p_m_VisibilityBits; // edi
  bool v3; // bl
  bool v4; // bl
  CSetActiveSplitScreenPlayerGuard g; // [esp+Ch] [ebp-20h] BYREF

  p_m_VisibilityBits = &this->m_VisibilityBits;
  if ( this != (C_BaseEntity *)-616 )
    p_m_VisibilityBits->m_Ints[0] = 0;
  CSetActiveSplitScreenPlayerGuard::CSetActiveSplitScreenPlayerGuard(
    this: &g,
    pchContext: "c_baseentity.cpp",
    nLine: 1744);
  v3 = this->ShouldDraw(this: &this->IClientRenderable)
    && !this->IsDormant(this: &this->IClientNetworkable)
    && (!ToolsEnabled() || this->m_bEnabledInToolView);
  CSetActiveSplitScreenPlayerGuard::~CSetActiveSplitScreenPlayerGuard(this: &g);
  if ( v3 )
  {
    v4 = engine->IsSplitScreenActive(this: engine);
    if ( !v4 )
    {
      C_BasePlayer::SetRemoteSplitScreenPlayerViewsAreLocalPlayer(bSet: true);
      IterateRemoteSplitScreenViewSlots_Push(bSet: true);
    }
    if ( !this->ShouldSuppressForSplitScreenPlayer(this, a2: 0) )
      p_m_VisibilityBits->m_Ints[0] |= 1u;
    if ( !v4 )
    {
      IterateRemoteSplitScreenViewSlots_Pop();
      C_BasePlayer::SetRemoteSplitScreenPlayerViewsAreLocalPlayer(bSet: false);
    }
    C_BaseEntity::AddToLeafSystem(this, bRenderWithViewModels: this->m_bRenderWithViewModels);
  }
  else
  {
    if ( this->m_hRender != 0xFFFF )
    {
      g_pClientLeafSystem->RemoveRenderable(this: g_pClientLeafSystem, a2: this->m_hRender);
      this->m_hRender = -1;
    }
    if ( this->m_ShadowHandle != 0xFFFF )
    {
      g_pClientShadowMgr->DestroyShadow(this: g_pClientShadowMgr, a2: this->m_ShadowHandle);
      this->m_ShadowHandle = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100413A0
// Name: public: void C_BaseEntity::SetModelPointer(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetModelPointer(C_BaseEntity *this, const struct model_t *pModel)
{
  CStudioHdr *(__thiscall *OnNewModel)(C_BaseEntity *); // eax

  if ( pModel != this->model )
  {
    if ( this->m_ModelInstance != 0xFFFF )
    {
      modelrender->DestroyInstance(this: modelrender, a2: this->m_ModelInstance);
      this->m_ModelInstance = -1;
    }
    OnNewModel = this->OnNewModel;
    this->model = pModel;
    OnNewModel(this);
    C_BaseEntity::UpdateVisibility(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041400
// Name: private: void C_BaseEntity::UnlinkChild(class C_BaseEntity __near *,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::UnlinkChild(C_BaseEntity *this, C_BaseEntity *pParent, C_BaseEntity *pChild)
{
  CBaseEntityList *v3; // edi
  unsigned int m_Index; // edx
  C_BaseEntity *m_pEntity; // eax
  unsigned int v6; // edx
  int v7; // eax
  CEntInfo *v8; // esi
  unsigned int v9; // edx
  int v10; // eax
  bool v11; // zf
  CEntInfo *v12; // eax
  IHandleEntity *v13; // eax
  unsigned int v14; // edx
  int v15; // eax
  CEntInfo *v16; // esi
  unsigned int v17; // edx
  int v18; // eax
  CEntInfo *v19; // eax
  IHandleEntity *v20; // eax
  C_BaseEntity *v21; // ecx

  v3 = g_pEntityList;
  if ( pParent != nullptr )
  {
    m_Index = pParent->m_pMoveChild.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity == pChild )
    {
      pParent->m_pMoveChild.m_Index = pChild->m_pMovePeer.m_Index;
      v3 = g_pEntityList;
    }
  }
  v6 = pChild->m_pMovePrevPeer.m_Index;
  if ( v6 != -1 )
  {
    v7 = (unsigned __int16)v6;
    v8 = &v3->m_EntPtrArray[(unsigned __int16)v6];
    v9 = HIWORD(v6);
    if ( v8->m_SerialNumber == v9 && v8->m_pEntity != nullptr )
    {
      v10 = v7;
      v11 = v3->m_EntPtrArray[v10].m_SerialNumber == v9;
      v12 = &v3->m_EntPtrArray[v10];
      if ( v11 )
        v13 = v12->m_pEntity;
      else
        v13 = nullptr;
      v13[191].__vftable = (IHandleEntity_vtbl *)pChild->m_pMovePeer.m_Index;
      v3 = g_pEntityList;
    }
  }
  v14 = pChild->m_pMovePeer.m_Index;
  if ( v14 != -1 )
  {
    v15 = (unsigned __int16)v14;
    v16 = &v3->m_EntPtrArray[(unsigned __int16)v14];
    v17 = HIWORD(v14);
    if ( v16->m_SerialNumber == v17 && v16->m_pEntity != nullptr )
    {
      v18 = v15;
      v11 = v3->m_EntPtrArray[v18].m_SerialNumber == v17;
      v19 = &v3->m_EntPtrArray[v18];
      if ( v11 )
        v20 = v19->m_pEntity;
      else
        v20 = nullptr;
      v20[192].__vftable = (IHandleEntity_vtbl *)pChild->m_pMovePrevPeer.m_Index;
    }
  }
  pChild->m_pMovePeer.m_Index = -1;
  pChild->m_pMovePrevPeer.m_Index = -1;
  pChild->m_pMoveParent.m_Index = -1;
  C_BaseEntity::RemoveFromAimEntsList(this: pChild);
  C_BaseEntity::OnFastReflectionRenderingChanged(this: v21);
  C_BaseEntity::Interp_HierarchyUpdateInterpolationAmounts(this);
}

//------------------------------------------------------------------------------
// Address: 0x10041520
// Name: private: void C_BaseEntity::UnlinkFromHierarchy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::UnlinkFromHierarchy(C_BaseEntity *this)
{
  unsigned int m_Index; // ecx
  C_BaseEntity *m_pEntity; // eax
  unsigned int v4; // ecx
  C_BaseEntity *MoveChild; // esi
  unsigned int v6; // ecx
  C_BaseEntity *v7; // eax

  m_Index = this->m_pMoveParent.m_Index;
  if ( m_Index != -1 )
  {
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    else
      m_pEntity = nullptr;
    C_BaseEntity::UnlinkChild(this, pParent: m_pEntity, pChild: this);
  }
  v4 = this->m_pMoveChild.m_Index;
  if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
    MoveChild = nullptr;
  else
    MoveChild = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
  for ( ; MoveChild != nullptr; MoveChild = C_BaseEntity::FirstMoveChild(this) )
  {
    v6 = MoveChild->m_pMoveParent.m_Index;
    if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
      v7 = nullptr;
    else
      v7 = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
    if ( v7 != this )
    {
      _Warning(a1: "C_BaseEntity::UnlinkFromHierarchy(): Entity has a child with the wrong parent!\n");
      C_BaseEntity::UnlinkChild(this, pParent: this, pChild: MoveChild);
    }
    C_BaseEntity::UnlinkFromHierarchy(this: MoveChild);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100415F0
// Name: public: void C_BaseEntity::CreateShadow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::CreateShadow(C_BaseEntity *this)
{
  CBitVec<1> *p_m_ShadowBits; // esi
  ShadowType_t v3; // ebx
  ShadowType_t v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  CBitVec<1> bvPrevBits; // [esp+Ch] [ebp-4h] BYREF

  p_m_ShadowBits = &this->m_ShadowBits;
  bvPrevBits.m_Ints[0] = this->m_ShadowBits.m_Ints[0];
  if ( this != (C_BaseEntity *)-724 )
    p_m_ShadowBits->m_Ints[0] = 0;
  v3 = SHADOWS_NONE;
  v4 = this->ShadowCastType(this: &this->IClientRenderable);
  if ( v4 != SHADOWS_NONE )
  {
    p_m_ShadowBits->m_Ints[0] |= 1u;
    if ( v4 > SHADOWS_NONE )
      v3 = v4;
  }
  p_m_ShadowBits->m_Ints[0] &= 1u;
  v5 = 0;
  while ( p_m_ShadowBits[v5].m_Ints[0] == 0 )
  {
    if ( --v5 < 0 )
      goto LABEL_11;
  }
  if ( !CBitVecT<CFixedBitVecBase<1>>::Compare(this: p_m_ShadowBits, other: &bvPrevBits, nBits: -1) )
  {
LABEL_11:
    if ( this->m_ShadowHandle != 0xFFFF )
    {
      g_pClientShadowMgr->DestroyShadow(this: g_pClientShadowMgr, a2: this->m_ShadowHandle);
      this->m_ShadowHandle = -1;
    }
  }
  p_m_ShadowBits->m_Ints[0] &= 1u;
  v6 = 0;
  while ( p_m_ShadowBits[v6].m_Ints[0] == 0 )
  {
    if ( --v6 < 0 )
      return;
  }
  if ( this->m_ShadowHandle == 0xFFFF )
  {
    v7 = 2;
    if ( v3 != SHADOWS_SIMPLE )
      v7 = 10;
    if ( v3 == SHADOWS_RENDER_TO_TEXTURE_DYNAMIC || v3 == SHADOWS_RENDER_TO_TEXTURE_DYNAMIC_CUSTOM )
    {
      v7 |= 0x10u;
      if ( v3 == SHADOWS_RENDER_TO_TEXTURE_DYNAMIC_CUSTOM )
        v7 |= 0x50u;
    }
    v8 = ((int (__thiscall *)(IClientNetworkable *, int, CBitVec<1> *))this->entindex)(
           a1: &this->IClientNetworkable,
           a2: v7,
           a3: p_m_ShadowBits);
    this->m_ShadowHandle = ((int (__thiscall *)(IClientShadowMgr *, unsigned int, int))g_pClientShadowMgr->CreateShadow)(
                             a1: g_pClientShadowMgr,
                             a2: this->m_RefEHandle.m_Index,
                             a3: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041700
// Name: public: virtual void C_BaseEntity::SetDormant(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetDormant(C_BaseEntity *this, BOOL bDormant)
{
  this->m_bDormant = bDormant;
  C_BaseEntity::UpdateVisibility(this);
  CParticleProperty::OwnerSetDormantTo(this: &this->m_Particles, bDormant);
  this->OnSetDormant(this, a2: bDormant);
  CClientEntityList::SetDormant(this: (CClientEntityList *)cl_entitylist.m_Index, entityIndex: this->index, bDormant);
}

//------------------------------------------------------------------------------
// Address: 0x10041750
// Name: public: void C_BaseEntity::ShutdownPredictable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::ShutdownPredictable(C_BaseEntity *this)
{
  int m_Size; // edx
  int v2; // eax
  C_BaseEntity **m_pMemory; // ecx

  m_Size = g_Predictables.m_Size;
  v2 = 0;
  if ( g_Predictables.m_Size > 0 )
  {
    m_pMemory = g_Predictables.m_Memory.m_pMemory;
    while ( *m_pMemory != this )
    {
      ++v2;
      ++m_pMemory;
      if ( v2 >= g_Predictables.m_Size )
        goto LABEL_10;
    }
    if ( v2 != -1 )
    {
      if ( g_Predictables.m_Size - v2 - 1 > 0 )
      {
        _V_memmove(
          dest: &g_Predictables.m_Memory.m_pMemory[v2],
          src: &g_Predictables.m_Memory.m_pMemory[v2 + 1],
          count: 4 * (g_Predictables.m_Size - v2 - 1));
        m_Size = g_Predictables.m_Size;
      }
      g_Predictables.m_Size = m_Size - 1;
    }
  }
LABEL_10:
  C_BaseEntity::DestroyIntermediateData(this);
  this->SetPredictable(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100417C0
// Name: public: virtual void C_BaseEntity::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::UpdateOnRemove(C_BaseEntity *this)
{
  this->VPhysicsDestroyObject(this);
  C_BaseEntity::UnlinkFromHierarchy(this);
  C_BaseEntity::SetGroundEntity(this, ground: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100417E0
// Name: public: virtual void C_BaseEntity::EstimateAbsVelocity(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::EstimateAbsVelocity(C_BaseEntity *this, Vector *vel)
{
  CInterpolationContext *v3; // ecx
  bool (__thiscall *IsPlayer)(C_BaseEntity *); // edx
  bool v5; // al
  CInterpolationContext context; // [esp+Ch] [ebp-Ch] BYREF

  if ( C_BasePlayer::IsLocalPlayer(pEntity: this) )
  {
    C_BaseEntity::CalcAbsoluteVelocity(this);
    *vel = this->m_vecAbsVelocity;
  }
  else
  {
    v3 = CInterpolationContext::s_pHead;
    CInterpolationContext::s_pHead = &context;
    context.m_bOldAllowExtrapolation = CInterpolationContext::s_bAllowExtrapolation;
    CInterpolationContext::s_bAllowExtrapolation = true;
    IsPlayer = this->IsPlayer;
    context.m_pNext = v3;
    context.m_flOldLastTimeStamp = CInterpolationContext::s_flLastTimeStamp;
    v5 = IsPlayer(this);
    CInterpolatedVarArrayBase<Vector,0>::GetDerivative_SmoothVelocity(
      this: &this->m_iv_vecOrigin,
      pOut: vel,
      currentTime: *(float *)(gpGlobals.m_Index + 12),
      bAllowHermiteFix: !v5);
    CInterpolationContext::s_bAllowExtrapolation = context.m_bOldAllowExtrapolation;
    CInterpolationContext::s_flLastTimeStamp = context.m_flOldLastTimeStamp;
    CInterpolationContext::s_pHead = context.m_pNext;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100418B0
// Name: public: virtual void C_BaseEntity::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::OnRestore(C_BaseEntity *this)
{
  C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 7);
  this->UpdatePartitionListEntry(this);
  CCollisionProperty::UpdatePartition(this: &this->m_Collision);
  C_BaseEntity::UpdateVisibility(this);
}

//------------------------------------------------------------------------------
// Address: 0x100418E0
// Name: public: void C_BaseEntity::EnableInToolView(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::EnableInToolView(C_BaseEntity *this, bool bEnable)
{
  this->m_bEnabledInToolView = bEnable;
  C_BaseEntity::UpdateVisibility(this);
}

//------------------------------------------------------------------------------
// Address: 0x10041900
// Name: public: void C_BaseEntity::RemoveVar(void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::RemoveVar(C_BaseEntity *this, void *data, bool bAssert)
{
  int v4; // ecx
  VarMapEntry_t *m_pMemory; // edi
  void **i; // eax

  v4 = 0;
  if ( this->m_VarMap.m_Entries.m_Size > 0 )
  {
    m_pMemory = this->m_VarMap.m_Entries.m_Memory.m_pMemory;
    for ( i = &m_pMemory->data; *i != data; i += 3 )
    {
      if ( ++v4 >= this->m_VarMap.m_Entries.m_Size )
        return;
    }
    if ( (m_pMemory[v4].type & 8) == 0 )
      --this->m_VarMap.m_nInterpolatedEntries;
    if ( this->m_VarMap.m_Entries.m_Size - v4 - 1 > 0 )
      _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 12 * (this->m_VarMap.m_Entries.m_Size - v4 - 1));
    --this->m_VarMap.m_Entries.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041970
// Name: public: static void C_BaseEntity::PurgeRemovedEntities(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl C_BaseEntity::PurgeRemovedEntities()
{
  unsigned __int16 v0; // cx
  unsigned __int16 v1; // ax
  int v2; // esi
  unsigned __int16 v3; // dx
  int v4; // ecx
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx

  v0 = word_105FD37C[0];
  v1 = word_105FD37C[0];
  if ( word_105FD37C[0] != 0xFFFF )
  {
    do
    {
      v2 = *(unsigned __int16 *)(unk_105FD370 + 8 * v1 + 6);
      (*(void (__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)(unk_105FD370 + 8 * v1) + 8) + 4))(a1: *(_DWORD *)(unk_105FD370 + 8 * v1) + 8);
      v1 = v2;
    }
    while ( v2 != 0xFFFF );
    v0 = word_105FD37C[0];
  }
  if ( unk_105FD386 != 0xFFFF )
  {
    v3 = v0;
    if ( v0 != 0xFFFF )
    {
      do
      {
        v4 = unk_105FD370 + 8 * v3;
        v5 = *(_WORD *)(v4 + 6);
        *(_WORD *)(v4 + 4) = v3;
        v6 = unk_105FD380;
        if ( v5 != 0xFFFF )
          v6 = v5;
        *(_WORD *)(v4 + 6) = v6;
        v3 = v5;
      }
      while ( v5 != 0xFFFF );
      if ( word_105FD37C[0] != 0xFFFF )
        unk_105FD380 = word_105FD37C[0];
    }
    *(_DWORD *)word_105FD37C = -1;
    unk_105FD382 = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041A30
// Name: public: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::CallQueued(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(CCallQueueT<CTSQueue<CFunctor *,0,1> > *this)
{
  CTSQueue<SProjectedTextureInfo *,0,1>::Node_t *v2; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *v3; // eax
  CFunctor *elem; // esi

  if ( this->m_queue.m_Count.m_value != 0 )
  {
    v2 = (CTSQueue<SProjectedTextureInfo *,0,1>::Node_t *)CTSListBase::Pop(this: &this->m_queue.m_FreeNodes);
    if ( v2 != nullptr )
    {
      v2->elem = nullptr;
    }
    else
    {
      v2 = (CTSQueue<SProjectedTextureInfo *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u);
      if ( v2 != nullptr )
        v2->elem = nullptr;
      else
        v2 = nullptr;
    }
    CTSQueue<CFunctor *,0,1>::Push(this: &this->m_queue, pNode: v2);
    while ( 1 )
    {
      v3 = CTSQueue<SProjectedTextureInfo *,0,1>::Pop(this: &this->m_queue);
      if ( v3 == nullptr )
        break;
      elem = v3->elem;
      CTSListBase::Push(this: &this->m_queue.m_FreeNodes, pNode: (TSLNodeBase_t *)v3);
      if ( elem == nullptr )
        break;
      elem->operator()(this: elem);
      elem->Release(this: elem);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041AB0
// Name: public: void C_BaseEntity::ClearEffects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::ClearEffects(C_BaseEntity *this)
{
  unsigned int v2; // ebx

  v2 = (unsigned int)this->m_fEffects >> 10;
  this->m_fEffects = 0;
  C_BaseEntity::UpdateVisibility(this);
  if ( (v2 & 1) != 0 )
    C_BaseEntity::OnFastReflectionRenderingChanged(this);
  ((void (__stdcall *)(_DWORD, bool))g_pClientLeafSystem->DisableShadowDepthRendering)(
    a1: this->m_hRender,
    a2: (this->m_fEffects & 0x800) != 0);
  ((void (__stdcall *)(_DWORD, bool))g_pClientLeafSystem->DisableShadowDepthCaching)(
    a1: this->m_hRender,
    a2: (this->m_fEffects & 0x1000) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10041F90
// Name: public: virtual void CRecordingList::AddToList(class CBaseHandle)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRecordingList::AddToList(CRecordingList *this, CBaseHandle add)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_Recording; // esi
  int m_Size; // ecx
  int v4; // eax
  vgui::TreeNode **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  CBaseHandle *v10; // eax

  p_m_Recording = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Recording;
  m_Size = this->m_Recording.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = p_m_Recording->m_pMemory;
  while ( *m_pMemory != (vgui::TreeNode *)add.m_Index )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_Recording->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Recording, num: m_Size - m_nAllocationCount + 1);
    ++p_m_Recording[1].m_pMemory;
    v8 = p_m_Recording->m_pMemory;
    v9 = (int)p_m_Recording[1].m_pMemory - v7 - 1;
    p_m_Recording[1].m_nAllocationCount = (int)p_m_Recording->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = (CBaseHandle *)&p_m_Recording->m_pMemory[v7];
    if ( v10 != nullptr )
      v10->m_Index = add.m_Index;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042010
// Name: public: virtual void C_BaseEntity::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::Clear(C_BaseEntity *this)
{
  int m_nRenderMode; // eax
  CClientAlphaProperty *m_pClientAlphaProperty; // ecx
  int v4; // [esp+Ch] [ebp-14h]

  this->m_hRender = -1;
  this->m_hThink = (struct CClientThinkHandlePtr *)0xFFFF;
  *(_WORD *)&this->m_bDormant = 1;
  this->m_nCreationTick = -1;
  this->m_RefEHandle.m_Index = -1;
  *(_DWORD *)&this->m_ModelInstance = -1;
  this->m_AimEntsListHandle = -1;
  this->index = -1;
  CCollisionProperty::Init(this: &this->m_Collision, pEntity: this);
  if ( this->m_pClientAlphaProperty != nullptr )
  {
    g_pClientAlphaPropertyMgr->DestroyClientAlphaProperty(
      this: g_pClientAlphaPropertyMgr,
      a2: this->m_pClientAlphaProperty);
    this->m_pClientAlphaProperty = nullptr;
  }
  this->m_pClientAlphaProperty = (CClientAlphaProperty *)g_pClientAlphaPropertyMgr->CreateClientAlphaProperty(
                                                           this: g_pClientAlphaPropertyMgr,
                                                           a2: this);
  if ( vec3_origin.x != this->m_vecOrigin.x
    || vec3_origin.y != this->m_vecOrigin.y
    || vec3_origin.z != this->m_vecOrigin.z )
  {
    C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 1);
    this->m_vecOrigin = vec3_origin;
  }
  if ( vec3_angle.x != this->m_angRotation.x
    || vec3_angle.y != this->m_angRotation.y
    || vec3_angle.z != this->m_angRotation.z )
  {
    C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 2);
    this->m_angRotation = vec3_angle;
  }
  this->model = nullptr;
  this->m_vecAbsOrigin.x = 0.0;
  this->m_vecAbsOrigin.y = 0.0;
  this->m_vecAbsOrigin.z = 0.0;
  this->m_angAbsRotation.x = 0.0;
  this->m_angAbsRotation.y = 0.0;
  this->m_angAbsRotation.z = 0.0;
  this->m_vecVelocity.x = 0.0;
  this->m_vecVelocity.y = 0.0;
  this->m_vecVelocity.z = 0.0;
  C_BaseEntity::ClearFlags(this);
  this->m_vecViewOffset.x = 0.0;
  this->m_vecViewOffset.y = 0.0;
  this->m_vecViewOffset.z = 0.0;
  this->m_vecBaseVelocity.x = 0.0;
  this->m_vecBaseVelocity.y = 0.0;
  this->m_vecBaseVelocity.z = 0.0;
  this->m_nModelIndex = 0;
  this->m_flAnimTime = 0.0;
  this->m_flSimulationTime = 0.0;
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: 0);
  *(_WORD *)&this->m_MoveType = 0;
  C_BaseEntity::ClearEffects(this);
  this->m_iEFlags = 0;
  this->m_nRenderMode = 0;
  this->m_nOldRenderMode = 0;
  if ( this->m_clrRender.m_Value.r != 0xFF )
    this->m_clrRender.m_Value.r = -1;
  if ( this->m_clrRender.m_Value.g != 0xFF )
    this->m_clrRender.m_Value.g = -1;
  if ( this->m_clrRender.m_Value.b != 0xFF )
    this->m_clrRender.m_Value.b = -1;
  if ( this->m_clrRender.m_Value.a != 0xFF )
  {
    this->m_clrRender.m_Value.a = -1;
    this->m_pClientAlphaProperty->SetAlphaModulation(this: this->m_pClientAlphaProperty, a2: 255u);
  }
  if ( this->m_nRenderFX != 0 )
  {
    m_nRenderMode = this->m_nRenderMode;
    m_pClientAlphaProperty = this->m_pClientAlphaProperty;
    v4 = *(_DWORD *)(gpGlobals.m_Index + 12);
    this->m_nRenderFX = 0;
    ((void (__thiscall *)(CClientAlphaProperty *, _DWORD, int, int, _DWORD))m_pClientAlphaProperty->SetRenderFX)(
      a1: m_pClientAlphaProperty,
      a2: 0,
      a3: m_nRenderMode,
      a4: v4,
      a5: 0);
  }
  this->m_flFriction = 0.0;
  this->m_flGravity = 0.0;
  C_BaseEntity::SetCheckUntouch(this, check: false);
  this->m_ShadowDirUseOtherEntity.m_Index = -1;
  this->m_nLastThinkTick = *(_DWORD *)(gpGlobals.m_Index + 24);
  C_BaseEntity::UpdateVisibility(this);
}

//------------------------------------------------------------------------------
// Address: 0x10042310
// Name: protected: virtual void C_BaseEntity::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::Release(C_BaseEntity *this)
{
  char *v2; // esi
  C_BaseAnimating::AutoAllowBoneAccess boneaccess; // [esp+Bh] [ebp-1h] BYREF

  C_BaseAnimating::AutoAllowBoneAccess::AutoAllowBoneAccess(
    this: &boneaccess,
    bAllowForNormalModels: true,
    bAllowForViewModels: true);
  v2 = (char *)this - 8;
  C_BaseEntity::UnlinkFromHierarchy(this: (C_BaseEntity *)((char *)this - 8));
  C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(this: &boneaccess);
  if ( this->m_pIntermediateData_FirstPredicted[149] != nullptr )
    C_BaseEntity::DestroyIntermediateData(this: (C_BaseEntity *)((char *)this - 8));
  (*(void (__thiscall **)(char *))(*(_DWORD *)v2 + 480))(a1: (char *)this - 8);
  if ( this != (C_BaseEntity *)8 )
    (**(void (__thiscall ***)(char *, int))v2)(a1: (char *)this - 8, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10042370
// Name: public: static void C_BaseEntity::UpdateVisibilityAllEntities(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall C_BaseEntity::UpdateVisibilityAllEntities(int a1@<edi>)
{
  C_BaseEntity *i; // esi
  CBitVec<1> *p_m_VisibilityBits; // edi
  bool v3; // bl
  char v4; // bl
  CSetActiveSplitScreenPlayerGuard v6; // [esp+4h] [ebp-24h] BYREF
  C_BaseEntityIterator iterator; // [esp+24h] [ebp-4h] BYREF

  C_BaseEntityIterator::C_BaseEntityIterator(this: &iterator);
  for ( i = C_BaseEntityIterator::Next(this: &iterator); i != nullptr; i = C_BaseEntityIterator::Next(this: &iterator) )
  {
    p_m_VisibilityBits = &i->m_VisibilityBits;
    if ( i != (C_BaseEntity *)-616 )
      p_m_VisibilityBits->m_Ints[0] = 0;
    CSetActiveSplitScreenPlayerGuard::CSetActiveSplitScreenPlayerGuard(
      this: &v6,
      pchContext: "c_baseentity.cpp",
      nLine: 1744);
    v3 = i->ShouldDraw(this: &i->IClientRenderable)
      && !i->IsDormant(this: &i->IClientNetworkable)
      && (!ToolsEnabled() || i->m_bEnabledInToolView);
    CSetActiveSplitScreenPlayerGuard::~CSetActiveSplitScreenPlayerGuard(this: &v6);
    if ( v3 )
    {
      v4 = ((int (__thiscall *)(IVEngineClient *, int))engine->IsSplitScreenActive)(a1: engine, a2: a1);
      if ( v4 == 0 )
      {
        C_BasePlayer::SetRemoteSplitScreenPlayerViewsAreLocalPlayer(bSet: true);
        IterateRemoteSplitScreenViewSlots_Push(bSet: true);
      }
      a1 = 0;
      if ( ((unsigned __int8 (__thiscall *)(C_BaseEntity *))i->ShouldSuppressForSplitScreenPlayer)(a1: i) == 0 )
        p_m_VisibilityBits->m_Ints[0] |= 1u;
      if ( v4 == 0 )
      {
        IterateRemoteSplitScreenViewSlots_Pop();
        C_BasePlayer::SetRemoteSplitScreenPlayerViewsAreLocalPlayer(bSet: false);
      }
      C_BaseEntity::AddToLeafSystem(this: i, bRenderWithViewModels: i->m_bRenderWithViewModels);
    }
    else
    {
      if ( i->m_hRender != 0xFFFF )
      {
        g_pClientLeafSystem->RemoveRenderable(this: g_pClientLeafSystem, a2: i->m_hRender);
        i->m_hRender = -1;
      }
      if ( i->m_ShadowHandle != 0xFFFF )
      {
        g_pClientShadowMgr->DestroyShadow(this: g_pClientShadowMgr, a2: i->m_ShadowHandle);
        i->m_ShadowHandle = -1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100424E0
// Name: public: void C_BaseEntity::SetModelIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetModelIndex(C_BaseEntity *this, __int16 index)
{
  const struct model_t *v3; // edi
  CStudioHdr *(__thiscall *OnNewModel)(C_BaseEntity *); // eax

  this->m_nModelIndex = index;
  v3 = modelinfo->GetModel(this: modelinfo, a2: index);
  if ( v3 != this->model )
  {
    if ( this->m_ModelInstance != 0xFFFF )
    {
      modelrender->DestroyInstance(this: modelrender, a2: this->m_ModelInstance);
      this->m_ModelInstance = -1;
    }
    OnNewModel = this->OnNewModel;
    this->model = v3;
    OnNewModel(this);
    C_BaseEntity::UpdateVisibility(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042550
// Name: public: virtual void C_BaseEntity::NotifyShouldTransmit(enum ShouldTransmitState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::NotifyShouldTransmit(C_BaseEntity *this, ShouldTransmitState_t state)
{
  if ( (int)this->GetAbsOrigin(this) >= 0 )
  {
    if ( state != SHOULDTRANSMIT_START )
    {
      if ( state == SHOULDTRANSMIT_END )
      {
        C_BaseEntity::UnlinkFromHierarchy(this: (C_BaseEntity *)((char *)this - 8));
        (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 2) + 212))(a1: (char *)this - 8, a2: 1);
        ((void (__stdcall *)(int, _DWORD))partition->Remove_2)(a1: 140, a2: this->m_Collision.m_usSolidFlags.m_Value);
      }
    }
    else
    {
      (*(void (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 2) + 212))(a1: (char *)this - 8, a2: 0);
      (*(void (__thiscall **)(char *))(*((_DWORD *)this - 2) + 360))(a1: (char *)this - 8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100425D0
// Name: public: void C_BaseEntity::AddToAimEntsList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::AddToAimEntsList(C_BaseEntity *this)
{
  int m_Size; // eax
  unsigned int v3; // esi
  C_BaseEntity **m_pMemory; // ecx
  int v5; // eax
  C_BaseEntity **v6; // eax

  if ( this->m_AimEntsListHandle == -1 )
  {
    m_Size = g_AimEntsList.m_Size;
    v3 = g_AimEntsList.m_Size;
    if ( g_AimEntsList.m_Size + 1 > g_AimEntsList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&g_AimEntsList,
        num: g_AimEntsList.m_Size - g_AimEntsList.m_Memory.m_nAllocationCount + 1);
      m_Size = g_AimEntsList.m_Size;
    }
    m_pMemory = g_AimEntsList.m_Memory.m_pMemory;
    g_AimEntsList.m_Size = m_Size + 1;
    v5 = m_Size - v3;
    g_AimEntsList.m_pElements = g_AimEntsList.m_Memory.m_pMemory;
    if ( v5 > 0 )
    {
      _V_memmove(
        dest: &g_AimEntsList.m_Memory.m_pMemory[v3 + 1],
        src: &g_AimEntsList.m_Memory.m_pMemory[v3],
        count: 4 * v5);
      m_pMemory = g_AimEntsList.m_Memory.m_pMemory;
    }
    v6 = &m_pMemory[v3];
    if ( v6 != nullptr )
      *v6 = this;
    this->m_AimEntsListHandle = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042650
// Name: public: void C_BaseEntity::CheckShutdownPredictable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::CheckShutdownPredictable(C_BaseEntity *this, const char *context)
{
  if ( !this->IsClientCreated(this)
    && (!this->ShouldPredict(this) || !this->m_bPredictionEligible || this->GetPredictionOwner(this) == nullptr)
    && this->m_pOriginalData != nullptr )
  {
    C_BaseEntity::ShutdownPredictable(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100426A0
// Name: public: void C_BaseEntity::SetModelByIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetModelByIndex(C_BaseEntity *this, __int16 nModelIndex)
{
  C_BaseEntity::SetModelIndex(this, index: nModelIndex);
}

//------------------------------------------------------------------------------
// Address: 0x100426B0
// Name: public: bool C_BaseEntity::SetModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::SetModel(C_BaseEntity *this, const char *pModelName)
{
  int v3; // esi

  if ( pModelName != nullptr )
  {
    v3 = modelinfo->GetModelIndex(this: modelinfo, a2: pModelName);
    C_BaseEntity::SetModelIndex(this, index: v3);
    return v3 != -1;
  }
  else
  {
    C_BaseEntity::SetModelIndex(this, index: -1);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042700
// Name: public: virtual void C_BaseEntity::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::OnDataChanged(C_BaseEntity *this, DataUpdateType_t type)
{
  C_BaseEntity::CreateShadow(this: (C_BaseEntity *)((char *)this - 8));
  if ( type == DATA_UPDATE_CREATED )
    C_BaseEntity::UpdateVisibility(this: (C_BaseEntity *)((char *)this - 8));
  ((void (__thiscall *)(ParticleEffectList_t *, _DWORD, _DWORD, int, _DWORD))this->m_Particles.m_ParticleEffects.m_pElements->pControlPoints.m_Memory.m_pMemory->iAttachmentPoint)(
    a1: this->m_Particles.m_ParticleEffects.m_pElements,
    a2: (unsigned __int8)this->m_iName[254],
    a3: (unsigned __int8)this->m_iName[255],
    a4: 2139095039,
    a5: 0);
  ((void (__thiscall *)(ParticleEffectList_t *, _DWORD))LODWORD(this->m_Particles.m_ParticleEffects.m_pElements->pControlPoints.m_Memory.m_pMemory->vecOriginOffset.y))(
    a1: this->m_Particles.m_ParticleEffects.m_pElements,
    a2: DWORD2(this->m_pfnTouch));
  ((void (__thiscall *)(ParticleEffectList_t *, _DWORD, _DWORD, unsigned int))LODWORD(this->m_Particles.m_ParticleEffects.m_pElements->pControlPoints.m_Memory.m_pMemory->vecOriginOffset.x))(
    a1: this->m_Particles.m_ParticleEffects.m_pElements,
    a2: LODWORD(this->m_fadeMinDist),
    a3: *(_DWORD *)&this->m_ModelInstance,
    a4: this->m_ShadowBits.m_Ints[0]);
}

//------------------------------------------------------------------------------
// Address: 0x100427B0
// Name: public: void C_BaseEntity::SaveData(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SaveData(C_BaseEntity *this, const char *context, unsigned int slot, int type)
{
  unsigned __int8 *m_pOriginalData; // eax
  int v6; // eax
  datamap_t *v7; // [esp-4h] [ebp-4Ch]
  CPredictionCopy copyHelper; // [esp+8h] [ebp-40h] BYREF

  if ( slot == -1 )
  {
    m_pOriginalData = this->m_pOriginalData;
  }
  else if ( this->m_pOriginalData != nullptr )
  {
    m_pOriginalData = this->m_pIntermediateData[slot % 0x96];
  }
  else
  {
    m_pOriginalData = nullptr;
  }
  if ( slot != -1 )
    this->m_nIntermediateDataCount = slot;
  CPredictionCopy::CPredictionCopy(
    this: &copyHelper,
    type,
    dest: m_pOriginalData,
    dest_packed: true,
    src: (const unsigned __int8 *)this,
    src_packed: false,
    opType: TRANSFERDATA_COPYONLY,
    func: nullptr);
  v7 = this->GetPredDescMap(this);
  v6 = this->entindex(this: &this->IClientNetworkable);
  CPredictionCopy::TransferData(this: &copyHelper, operation: "C_BaseEntity::SaveData", entindex: v6, dmap: v7);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&copyHelper.m_FieldStack);
}

//------------------------------------------------------------------------------
// Address: 0x10042850
// Name: public: void C_BaseEntity::RestoreData(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::RestoreData(C_BaseEntity *this, const char *context, unsigned int slot, int type)
{
  unsigned __int8 *m_pOriginalData; // ebx
  int v6; // edi
  int v7; // eax
  datamap_t *v8; // [esp-4h] [ebp-50h]
  CPredictionCopy copyHelper; // [esp+Ch] [ebp-40h] BYREF

  if ( slot == -1 )
  {
    m_pOriginalData = this->m_pOriginalData;
  }
  else if ( this->m_pOriginalData != nullptr )
  {
    m_pOriginalData = this->m_pIntermediateData[slot % 0x96];
  }
  else
  {
    m_pOriginalData = nullptr;
  }
  v6 = this->GetEFlags(this) & 0x8020;
  CPredictionCopy::CPredictionCopy(
    this: &copyHelper,
    type,
    dest: (unsigned __int8 *)this,
    dest_packed: false,
    src: m_pOriginalData,
    src_packed: true,
    opType: TRANSFERDATA_COPYONLY,
    func: nullptr);
  v8 = this->GetPredDescMap(this);
  v7 = this->entindex(this: &this->IClientNetworkable);
  CPredictionCopy::TransferData(this: &copyHelper, operation: "C_BaseEntity::RestoreData", entindex: v7, dmap: v8);
  this->m_iEFlags = v6 | this->m_iEFlags & 0xFFFF7FDF;
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&copyHelper.m_FieldStack);
}

//------------------------------------------------------------------------------
// Address: 0x10042910
// Name: public: void C_BaseEntity::OnPostRestoreData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::OnPostRestoreData(C_BaseEntity *this)
{
  unsigned int m_Index; // ecx
  const struct model_t *v3; // ebx
  IMDLCache *v4; // edi

  C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 7);
  m_Index = this->m_pMoveParent.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    C_BaseEntity::AddToAimEntsList(this);
  }
  v3 = modelinfo->GetModel(this: modelinfo, a2: this->m_nModelIndex);
  if ( this->GetModel(this: &this->IClientRenderable) != v3 )
  {
    v4 = mdlcache;
    mdlcache->BeginLock(this: mdlcache);
    C_BaseEntity::SetModelIndex(this, index: this->m_nModelIndex);
    v4->EndLock(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042A70
// Name: private: bool C_BaseEntity::InitializeAsClientEntityByIndex(int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::InitializeAsClientEntityByIndex(
        C_BaseEntity *this,
        __int16 iIndex,
        BOOL bRenderWithViewModels)
{
  BOOL v3; // eax
  IHandleEntity *v5; // eax
  CClientAlphaProperty *m_pClientAlphaProperty; // edx
  CClientAlphaProperty_vtbl *v7; // edi
  int v8; // eax

  v3 = bRenderWithViewModels;
  this->m_bRenderWithViewModels = bRenderWithViewModels;
  ((void (__stdcall *)(_DWORD, BOOL))g_pClientLeafSystem->RenderWithViewModels)(a1: this->m_hRender, a2: v3);
  C_BaseEntity::SetModelIndex(this, index: iIndex);
  v5 = (IHandleEntity *)this->GetIClientUnknown(this: &this->IClientRenderable);
  CBaseEntityList::AddNonNetworkableEntity(
    this: (CBaseEntityList *)cl_entitylist.m_Index,
    result: (CBaseHandle *)&bRenderWithViewModels,
    pEnt: v5);
  CCollisionProperty::CreatePartitionHandle(this: &this->m_Collision);
  m_pClientAlphaProperty = this->m_pClientAlphaProperty;
  this->index = -1;
  v7 = m_pClientAlphaProperty->__vftable;
  v8 = rand() % 1024;
  v7->SetDesyncOffset(this: this->m_pClientAlphaProperty, a2: v8);
  this->SpawnClientEntity(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10042B10
// Name: private: void C_BaseEntity::LinkChild(class C_BaseEntity __near *,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::LinkChild(C_BaseEntity *this, C_BaseEntity *pParent, C_BaseEntity *pChild)
{
  unsigned int m_Index; // eax
  unsigned int v4; // ecx
  int v5; // eax
  bool v6; // zf
  CEntInfo *v7; // eax
  IHandleEntity *m_pEntity; // ebx

  pChild->m_pMovePrevPeer.m_Index = -1;
  m_Index = pParent->m_pMoveChild.m_Index;
  pChild->m_pMovePeer.m_Index = m_Index;
  if ( m_Index != -1 )
  {
    v4 = HIWORD(m_Index);
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      v5 = (unsigned __int16)m_Index;
      v6 = g_pEntityList->m_EntPtrArray[v5].m_SerialNumber == v4;
      v7 = &g_pEntityList->m_EntPtrArray[v5];
      if ( v6 )
        m_pEntity = v7->m_pEntity;
      else
        m_pEntity = nullptr;
      m_pEntity[192].__vftable = (IHandleEntity_vtbl *)pChild->GetRefEHandle(this: pChild)->m_Index;
    }
  }
  pParent->m_pMoveChild.m_Index = pChild->GetRefEHandle(this: pChild)->m_Index;
  pChild->m_pMoveParent.m_Index = pParent->GetRefEHandle(this: pParent)->m_Index;
  C_BaseEntity::AddToAimEntsList(this: pChild);
  C_BaseEntity::OnFastReflectionRenderingChanged(this: pChild);
  C_BaseEntity::Interp_HierarchyUpdateInterpolationAmounts(this);
}

//------------------------------------------------------------------------------
// Address: 0x10042BD0
// Name: private: void C_BaseEntity::HierarchySetParent(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::HierarchySetParent(C_BaseEntity *this, C_BaseEntity *pNewParent)
{
  unsigned int m_Index; // eax
  unsigned int v4; // ecx
  C_BaseEntity *m_pEntity; // eax
  int v6; // ebx
  int v7; // edi
  _DWORD *v8; // esi
  unsigned int v9; // eax
  CBaseEntityList *v10; // edx
  IHandleEntity *v11; // eax
  IHandleEntity_vtbl *v12; // ecx
  _DWORD v13[1024]; // [esp+8h] [ebp-1000h]

  if ( pNewParent != nullptr )
    m_Index = pNewParent->GetRefEHandle(this: pNewParent)->m_Index;
  else
    m_Index = -1;
  v4 = this->m_pMoveParent.m_Index;
  if ( m_Index != v4 )
  {
    if ( v4 != -1 )
    {
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber == HIWORD(v4) )
        m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
      else
        m_pEntity = nullptr;
      C_BaseEntity::UnlinkChild(this, pParent: m_pEntity, pChild: this);
    }
    if ( pNewParent != nullptr )
      C_BaseEntity::LinkChild(this, pParent: pNewParent, pChild: this);
    C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 7);
    v6 = 0;
    v7 = 1;
    v13[0] = this;
    do
    {
      v8 = (_DWORD *)v13[v6];
      (*(void (__thiscall **)(_DWORD *))(*v8 + 324))(a1: v8);
      v9 = v8[190];
      v10 = g_pEntityList;
      v6 = ((_WORD)v6 + 1) & 0x3FF;
      if ( v9 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9) )
        v11 = nullptr;
      else
        v11 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity;
      while ( v11 != nullptr )
      {
        v12 = v11[191].__vftable;
        v13[v7] = v11;
        v7 = ((_WORD)v7 + 1) & 0x3FF;
        if ( v12 == (IHandleEntity_vtbl *)-1
          || v10->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != (unsigned int)v12 >> 16 )
        {
          v11 = nullptr;
        }
        else
        {
          v11 = v10->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
        }
      }
    }
    while ( v6 != v7 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042D00
// Name: public: void C_BaseEntity::SetParent(class C_BaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SetParent(
        C_BaseEntity *this,
        C_BaseEntity *pParentEntity,
        unsigned __int8 iParentAttachment)
{
  unsigned int m_Index; // eax
  Vector *v5; // eax
  C_BaseEntity_vtbl *v6; // edx
  bool v7; // zf
  float z; // edx
  unsigned int v9; // ecx
  C_BaseEntity *m_pEntity; // eax
  Vector vecAbsVelocity; // [esp+8h] [ebp-24h] BYREF
  QAngle angAbsRotation; // [esp+14h] [ebp-18h] BYREF
  Vector vecAbsOrigin; // [esp+20h] [ebp-Ch] BYREF

  if ( pParentEntity != nullptr )
    m_Index = pParentEntity->GetRefEHandle(this: pParentEntity)->m_Index;
  else
    m_Index = -1;
  if ( m_Index != this->m_pMoveParent.m_Index )
  {
    v5 = this->GetAbsOrigin(this);
    v6 = this->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    vecAbsOrigin = *v5;
    angAbsRotation = *v6->GetAbsAngles(this);
    C_BaseEntity::CalcAbsoluteVelocity(this);
    v7 = this->m_pMoveParent.m_Index == -1;
    z = this->m_vecAbsVelocity.z;
    *(_QWORD *)&vecAbsVelocity.x = *(_QWORD *)&this->m_vecAbsVelocity.x;
    vecAbsVelocity.z = z;
    if ( !v7 )
    {
      v9 = this->m_pMoveParent.m_Index;
      if ( v9 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9) )
        m_pEntity = nullptr;
      else
        m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity;
      C_BaseEntity::UnlinkChild(this, pParent: m_pEntity, pChild: this);
    }
    if ( pParentEntity != nullptr )
      C_BaseEntity::LinkChild(this, pParent: pParentEntity, pChild: this);
    if ( this->index == -1 )
    {
      if ( pParentEntity != nullptr )
        this->m_hNetworkMoveParent.m_Index = pParentEntity->GetRefEHandle(this: pParentEntity)->m_Index;
      else
        this->m_hNetworkMoveParent.m_Index = -1;
    }
    this->m_iParentAttachment = iParentAttachment;
    this->m_vecAbsOrigin.x = 3.4028235e38;
    this->m_vecAbsOrigin.y = 3.4028235e38;
    this->m_vecAbsOrigin.z = 3.4028235e38;
    this->m_angAbsRotation.x = 3.4028235e38;
    this->m_angAbsRotation.y = 3.4028235e38;
    this->m_angAbsRotation.z = 3.4028235e38;
    this->m_vecAbsVelocity.x = 3.4028235e38;
    this->m_vecAbsVelocity.y = 3.4028235e38;
    this->m_vecAbsVelocity.z = 3.4028235e38;
    C_BaseEntity::SetAbsOrigin(this, absOrigin: &vecAbsOrigin);
    C_BaseEntity::SetAbsAngles(this, absAngles: &angAbsRotation);
    C_BaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042E70
// Name: public: virtual void C_BaseEntity::ValidateModelIndex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::ValidateModelIndex(C_BaseEntity *this)
{
  C_BaseEntity::SetModelIndex(this, index: this->m_nModelIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10042E80
// Name: public: virtual void C_BaseEntity::OnDataUnchangedInPVS(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::OnDataUnchangedInPVS(C_BaseEntity *this)
{
  float z; // ecx
  C_BaseEntity *m_pEntity; // eax

  z = this->m_vecNetworkOrigin.z;
  if ( z == NAN || g_pEntityList->m_EntPtrArray[LOWORD(z)].m_SerialNumber != HIWORD(LODWORD(z)) )
    m_pEntity = nullptr;
  else
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(z)].m_pEntity;
  C_BaseEntity::HierarchySetParent(this: (C_BaseEntity *)((char *)this - 8), pNewParent: m_pEntity);
  *(float *)&this->m_nIncomingPacketEntityBecameDormant = engine->GetLastTimeStamp(this: engine);
}

//------------------------------------------------------------------------------
// Address: 0x10042ED0
// Name: public: void C_BaseEntity::StopFollowingEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::StopFollowingEntity(C_BaseEntity *this)
{
  C_BaseEntity::SetParent(this, pParentEntity: nullptr, iParentAttachment: 0);
  this->m_fEffects &= ~1u;
  ((void (__stdcall *)(_DWORD, bool))g_pClientLeafSystem->DisableShadowDepthRendering)(
    a1: this->m_hRender,
    a2: (this->m_fEffects & 0x800) != 0);
  ((void (__stdcall *)(_DWORD, bool))g_pClientLeafSystem->DisableShadowDepthCaching)(
    a1: this->m_hRender,
    a2: (this->m_fEffects & 0x1000) != 0);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value & 0xFFFB);
  *(_WORD *)&this->m_MoveType = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10042F60
// Name: public: void C_BaseEntity::PreEntityPacketReceived(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PreEntityPacketReceived(C_BaseEntity *this, int commands_acknowledged)
{
  if ( commands_acknowledged <= 0 )
  {
    C_BaseEntity::RestoreData(this, context: "PreEntityPacketReceived(no commands ack)", slot: 0xFFFFFFFF, type: 2);
  }
  else
  {
    C_BaseEntity::RestoreData(this, context: "PreEntityPacketReceived", slot: commands_acknowledged - 1, type: 0);
    C_BaseEntity::RestoreData(this, context: "PreEntityPacketReceived", slot: 0xFFFFFFFF, type: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042FB0
// Name: public: void C_BaseEntity::PostEntityPacketReceived(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PostEntityPacketReceived(C_BaseEntity *this)
{
  int v2; // eax
  datamap_t *v3; // [esp-4h] [ebp-4Ch]
  CPredictionCopy v4; // [esp+8h] [ebp-40h] BYREF

  CPredictionCopy::CPredictionCopy(
    this: &v4,
    type: 1,
    dest: this->m_pOriginalData,
    dest_packed: true,
    src: (const unsigned __int8 *)this,
    src_packed: false,
    opType: TRANSFERDATA_COPYONLY,
    func: nullptr);
  v3 = this->GetPredDescMap(this);
  v2 = this->entindex(this: &this->IClientNetworkable);
  CPredictionCopy::TransferData(this: &v4, operation: "C_BaseEntity::SaveData", entindex: v2, dmap: v3);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v4.m_FieldStack);
}

//------------------------------------------------------------------------------
// Address: 0x10043010
// Name: public: bool C_BaseEntity::PostNetworkDataReceived(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseEntity::PostNetworkDataReceived(C_BaseEntity *this, int commands_acknowledged)
{
  int v3; // eax
  int m_nValue; // ecx
  int v5; // ebx
  unsigned __int8 *v6; // ebx
  unsigned __int8 *v7; // edx
  int v8; // eax
  bool v9; // bl
  unsigned __int8 *m_pOriginalData; // [esp-18h] [ebp-68h]
  datamap_t *v12; // [esp-4h] [ebp-54h]
  datamap_t *v13; // [esp-4h] [ebp-54h]
  CPredictionCopy errorCheckHelper; // [esp+Ch] [ebp-44h] BYREF
  bool errorcheck; // [esp+4Eh] [ebp-2h]
  bool showthis; // [esp+4Fh] [ebp-1h]

  m_pOriginalData = this->m_pOriginalData;
  errorcheck = commands_acknowledged > 0;
  CPredictionCopy::CPredictionCopy(
    this: &errorCheckHelper,
    type: 2,
    dest: m_pOriginalData,
    dest_packed: true,
    src: (const unsigned __int8 *)this,
    src_packed: false,
    opType: TRANSFERDATA_COPYONLY,
    func: nullptr);
  v12 = this->GetPredDescMap(this);
  v3 = this->entindex(this: &this->IClientNetworkable);
  CPredictionCopy::TransferData(this: &errorCheckHelper, operation: "C_BaseEntity::SaveData", entindex: v3, dmap: v12);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&errorCheckHelper.m_FieldStack);
  if ( cl_showerror.m_pParent != nullptr )
    m_nValue = cl_showerror.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  showthis = m_nValue >= 2;
  if ( cl_showerror.m_pParent != nullptr )
  {
    v5 = cl_showerror.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
      showthis = this->entindex(this: &this->IClientNetworkable) == -v5;
  }
  if ( !errorcheck )
    return false;
  v6 = this->m_pOriginalData;
  v7 = nullptr;
  if ( v6 != nullptr )
    v7 = this->m_pIntermediateData[(commands_acknowledged - 1) % 0x96u];
  CPredictionCopy::CPredictionCopy(
    this: &errorCheckHelper,
    type: 1,
    dest: v7,
    dest_packed: true,
    src: v6,
    src_packed: true,
    opType: (CPredictionCopy::optype_t)(showthis + 1),
    func: nullptr);
  v13 = this->GetPredDescMap(this);
  v8 = this->entindex(this: &this->IClientNetworkable);
  v9 = CPredictionCopy::TransferData(this: &errorCheckHelper, operation: prType, entindex: v8, dmap: v13) > 0;
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&errorCheckHelper.m_FieldStack);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10043130
// Name: protected: void C_BaseEntity::RemoveFromEntityList(enum entity_list_ids_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::RemoveFromEntityList(C_BaseEntity *this, entity_list_ids_t listId)
{
  unsigned __int16 v2; // ax
  int v3; // edi
  CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *v4; // esi

  v2 = this->m_ListEntry[listId];
  if ( v2 != 0xFFFF )
  {
    v3 = this->m_ListEntry[listId];
    v4 = &g_EntityLists + listId;
    CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::Unlink(
      this: v4,
      elem: v2);
    v4->m_Memory.m_pMemory[v3].m_Next = v4->m_FirstFree;
    v4->m_FirstFree = v3;
    this->m_ListEntry[listId] = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100431A0
// Name: public: void C_BaseEntity::AddVar(void __near *,class IInterpolatedVar __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::AddVar(C_BaseEntity *this, void *data, IInterpolatedVar *watcher, int type, bool bSetup)
{
  int v6; // esi
  IInterpolatedVar **p_watcher; // eax
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VarMapEntry_t *m_pMemory; // eax
  int v11; // ecx
  VarMapEntry_t *v12; // esi
  IInterpolatedVar_vtbl *v13; // esi
  char v14; // al
  float InterpolationAmount; // [esp+8h] [ebp-1Ch]
  VarMapEntry_t map; // [esp+18h] [ebp-Ch] BYREF

  v6 = 0;
  if ( this->m_VarMap.m_Entries.m_Size <= 0 )
  {
LABEL_8:
    map.data = data;
    map.watcher = watcher;
    map.type = type;
    map.m_bNeedsToInterpolate = 1;
    if ( (type & 8) != 0 )
    {
      CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
        this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&this->m_VarMap,
        elem: this->m_VarMap.m_Entries.m_Size,
        src: (const QAngle *)&map);
    }
    else
    {
      m_Size = this->m_VarMap.m_Entries.m_Size;
      m_nAllocationCount = this->m_VarMap.m_Entries.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&this->m_VarMap,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_VarMap.m_Entries.m_Size;
      m_pMemory = this->m_VarMap.m_Entries.m_Memory.m_pMemory;
      v11 = this->m_VarMap.m_Entries.m_Size - 1;
      this->m_VarMap.m_Entries.m_pElements = m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &m_pMemory[1], src: m_pMemory, count: 12 * v11);
      v12 = this->m_VarMap.m_Entries.m_Memory.m_pMemory;
      if ( v12 != nullptr )
        *v12 = map;
      ++this->m_VarMap.m_nInterpolatedEntries;
    }
    goto LABEL_17;
  }
  p_watcher = &this->m_VarMap.m_Entries.m_Memory.m_pMemory->watcher;
  while ( *p_watcher != watcher )
  {
    ++v6;
    p_watcher += 3;
    if ( v6 >= this->m_VarMap.m_Entries.m_Size )
      goto LABEL_8;
  }
  if ( (((unsigned __int8)type ^ (unsigned __int8)watcher->GetType(this: watcher)) & 8) != 0 )
  {
    C_BaseEntity::RemoveVar(this, data: this->m_VarMap.m_Entries.m_Memory.m_pMemory[v6].data, bAssert: true);
    goto LABEL_8;
  }
LABEL_17:
  if ( bSetup )
  {
    watcher->Setup(this: watcher, a2: data, a3: type);
    v13 = watcher->__vftable;
    v14 = watcher->GetType(this: watcher);
    InterpolationAmount = C_BaseEntity::GetInterpolationAmount(this, flags: v14);
    ((void (__thiscall *)(IInterpolatedVar *, _DWORD))v13->SetInterpolationAmount)(
      a1: watcher,
      a2: LODWORD(InterpolationAmount));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100432C0
// Name: public: static void C_BaseEntity::SimulateEntities(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
static void __cdecl C_BaseEntity::SimulateEntities()
{
  unsigned __int16 v0; // ax
  C_RopeKeyframe *v1; // edi
  int v2; // ebx
  int v3; // esi
  unsigned __int16 m_Head; // ax
  int m_Next; // edi
  C_RopeKeyframe *m_Element; // esi
  bool v7; // zf
  int v8; // edi
  char *Classname; // eax
  int v10; // eax
  const char *v11; // [esp-4h] [ebp-44h]
  double v12; // [esp+0h] [ebp-40h]
  CFastTimer fastTimer; // [esp+2Ch] [ebp-14h] BYREF
  long double v14; // [esp+34h] [ebp-Ch] OVERLAPPED
  CFastTimer *p_fastTimer; // [esp+3Ch] [ebp-4h]

  s_bImmediateRemovesAllowed = false;
  if ( report_cliententitysim.m_pParent != nullptr && report_cliententitysim.m_pParent->m_Value.m_nValue != 0 )
  {
    m_Head = stru_105FD354.m_Head;
    fastTimer.m_Duration.m_Int64 = 0;
    if ( stru_105FD354.m_Head != 0xFFFF )
    {
      do
      {
        m_Next = stru_105FD354.m_Memory.m_pMemory[m_Head].m_Next;
        m_Element = stru_105FD354.m_Memory.m_pMemory[m_Head].m_Element;
        v7 = (m_Element->m_iEFlags & 1) == 0;
        HIDWORD(v14) = m_Next;
        if ( v7 )
        {
          p_fastTimer = &fastTimer;
          fastTimer.m_Duration.m_Int64 = __rdtsc();
          if ( !m_Element->Simulate(this: m_Element) && m_Element->m_ListEntry[3] != 0xFFFF )
          {
            v8 = m_Element->m_ListEntry[3];
            CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::Unlink(
              this: &stru_105FD354,
              elem: m_Element->m_ListEntry[3]);
            stru_105FD354.m_Memory.m_pMemory[v8].m_Next = stru_105FD354.m_FirstFree;
            stru_105FD354.m_FirstFree = v8;
            m_Next = HIDWORD(v14);
            m_Element->m_ListEntry[3] = -1;
          }
          fastTimer.m_Duration.m_Int64 = __rdtsc() - fastTimer.m_Duration.m_Int64;
          v14 = (double)fastTimer.m_Duration.m_Int64 * _g_ClockSpeedMillisecondsMultiplier;
          Classname = C_BaseEntity::GetClassname(this: m_Element);
          v10 = ((int (__thiscall *)(IClientNetworkable *, char *, _DWORD, _DWORD))m_Element->entindex)(
                  a1: &m_Element->IClientNetworkable,
                  a2: Classname,
                  a3: LODWORD(v14),
                  a4: HIDWORD(v14));
          _Msg(a1: "Entity(%d): %s - %f\n", v10, v11, v12);
        }
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    ConVar::SetValue(this: (ConVar *)&report_cliententitysim.IConVar, value: 0);
  }
  else
  {
    v0 = stru_105FD354.m_Head;
    if ( stru_105FD354.m_Head != 0xFFFF )
    {
      do
      {
        v1 = stru_105FD354.m_Memory.m_pMemory[v0].m_Element;
        v2 = stru_105FD354.m_Memory.m_pMemory[v0].m_Next;
        if ( (v1->m_iEFlags & 1) == 0 && !v1->Simulate(this: v1) && v1->m_ListEntry[3] != 0xFFFF )
        {
          v3 = v1->m_ListEntry[3];
          CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::Unlink(
            this: &stru_105FD354,
            elem: v1->m_ListEntry[3]);
          stru_105FD354.m_Memory.m_pMemory[v3].m_Next = stru_105FD354.m_FirstFree;
          stru_105FD354.m_FirstFree = v3;
          v1->m_ListEntry[3] = -1;
        }
        v0 = v2;
      }
      while ( v2 != 0xFFFF );
    }
  }
  CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(this: &s_SimulateEntitiesCallQueue);
  s_bImmediateRemovesAllowed = true;
  C_BaseEntity::PurgeRemovedEntities();
}

//------------------------------------------------------------------------------
// Address: 0x100434F0
// Name: public: static void C_BaseEntity::PreRenderEntities(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_BaseEntity::PreRenderEntities(int nSplitScreenPlayerSlot)
{
  IMDLCache *v1; // edi
  unsigned __int16 m_Head; // ax
  C_RopeKeyframe *m_Element; // esi
  int m_Next; // ebx
  int v5; // edi
  IMDLCache *cacheCriticalSection; // [esp+4h] [ebp-4h]

  v1 = mdlcache;
  cacheCriticalSection = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  m_Head = stru_105FD338.m_Head;
  if ( stru_105FD338.m_Head != 0xFFFF )
  {
    do
    {
      m_Element = stru_105FD338.m_Memory.m_pMemory[m_Head].m_Element;
      m_Next = stru_105FD338.m_Memory.m_pMemory[m_Head].m_Next;
      if ( !m_Element->PreRender(this: m_Element, a2: nSplitScreenPlayerSlot) && m_Element->m_ListEntry[2] != 0xFFFF )
      {
        v5 = m_Element->m_ListEntry[2];
        CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::Unlink(
          this: &stru_105FD338,
          elem: m_Element->m_ListEntry[2]);
        stru_105FD338.m_Memory.m_pMemory[v5].m_Next = stru_105FD338.m_FirstFree;
        stru_105FD338.m_FirstFree = v5;
        v1 = cacheCriticalSection;
        m_Element->m_ListEntry[2] = -1;
      }
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  v1->EndLock(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100435B0
// Name: public: CDiscontinuousInterpolatedVar<class Vector>::CDiscontinuousInterpolatedVar<class Vector>(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDiscontinuousInterpolatedVar<Vector> *__thiscall CDiscontinuousInterpolatedVar<Vector>::CDiscontinuousInterpolatedVar<Vector>(
        CDiscontinuousInterpolatedVar<Vector> *this,
        const char *pDebugName)
{
  CSimpleRingBuffer<CInterpolatedVarEntryBase<Vector,0> > *p_m_VarHistory; // ecx

  p_m_VarHistory = &this->m_VarHistory;
  this->__vftable = (CDiscontinuousInterpolatedVar<Vector>_vtbl *)&CInterpolatedVarArrayBase<Vector,0>::`vftable';
  p_m_VarHistory->m_pElements = nullptr;
  *(_DWORD *)&p_m_VarHistory->m_maxElement = 0;
  *(_DWORD *)&p_m_VarHistory->m_count = 0x100000;
  CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0>>::EnsureCapacity(
    this: (CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0> > *)p_m_VarHistory,
    capSize: 4);
  this->m_pDebugName = pDebugName;
  this->m_pValue = nullptr;
  this->m_InterpolationAmount = 0.0;
  *(_WORD *)&this->m_fType = 1;
  this->m_LastNetworkedTime = 0.0;
  this->m_LastNetworkedValue = nullptr;
  this->m_bLooping = nullptr;
  this->__vftable = (CDiscontinuousInterpolatedVar<Vector>_vtbl *)&CInterpolatedVar<Vector>::`vftable';
  CInterpolatedVarArrayBase<QAngle,0>::SetMaxCount(
    (CInterpolatedVarArrayBase<QAngle,0> *)this,
    flCurrentTime: 0.0,
    newmax: 1);
  this->__vftable = (CDiscontinuousInterpolatedVar<Vector>_vtbl *)&CDiscontinuousInterpolatedVar<Vector>::`vftable';
  this->m_Discontinuities.m_Memory.m_pMemory = nullptr;
  this->m_Discontinuities.m_Memory.m_nAllocationCount = 0;
  this->m_Discontinuities.m_Memory.m_nGrowSize = 0;
  this->m_Discontinuities.m_Size = 0;
  this->m_Discontinuities.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100436A0
// Name: public: virtual int CDiscontinuousInterpolatedVar<class Vector>::Interpolate(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDiscontinuousInterpolatedVar<Vector>::Interpolate(
        CDiscontinuousInterpolatedVar<Vector> *this,
        float currentTime)
{
  int result; // eax
  bool v4; // zf
  int v5; // ebx
  int v6; // esi
  int v7; // ebx
  CDiscontinuousInterpolatedVar<Vector>::Discontinuity_t *v8; // ecx
  float z; // edx
  Vector *currentTimea; // [esp+0h] [ebp-20h]
  __int64 in1; // [esp+10h] [ebp-10h] BYREF
  float v12; // [esp+18h] [ebp-8h]
  int iRetVal; // [esp+1Ch] [ebp-4h]
  float fInterpolatedTime; // [esp+28h] [ebp+8h]

  result = CInterpolatedVarArrayBase<Vector,0>::Interpolate(
             this,
             currentTime,
             interpolation_amount: this->m_InterpolationAmount);
  v4 = this->m_Discontinuities.m_Size == 0;
  v5 = result;
  iRetVal = result;
  if ( !v4 )
  {
    CDiscontinuousInterpolatedVar<Vector>::ClearOldDiscontinuities((CDiscontinuousInterpolatedVar<QAngle> *)this);
    v6 = this->m_Discontinuities.m_Size - 1;
    fInterpolatedTime = currentTime - this->m_InterpolationAmount;
    if ( v6 >= 0 )
    {
      v7 = v6;
      do
      {
        v8 = &this->m_Discontinuities.m_Memory.m_pMemory[v7];
        if ( fInterpolatedTime > v8->fBeforeTime )
          break;
        z = this->m_pValue->z;
        currentTimea = this->m_pValue;
        in1 = *(_QWORD *)&currentTimea->x;
        v12 = z;
        VectorTransform((float *)&in1, in2: &v8->matTransform, out: &currentTimea->x);
        --v7;
        --v6;
        iRetVal = 0;
      }
      while ( v6 >= 0 );
      return iRetVal;
    }
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10043740
// Name: public: virtual void CDiscontinuousInterpolatedVar<class QAngle>::Reset(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiscontinuousInterpolatedVar<QAngle>::Reset(
        CDiscontinuousInterpolatedVar<QAngle> *this,
        float flCurrentTime)
{
  CInterpolatedVarArrayBase<Vector,0>::Reset(this, flCurrentTime);
  CDiscontinuousInterpolatedVar<Vector>::ClearOldDiscontinuities(this);
}

//------------------------------------------------------------------------------
// Address: 0x10043770
// Name: public: CDiscontinuousInterpolatedVar<class QAngle>::CDiscontinuousInterpolatedVar<class QAngle>(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDiscontinuousInterpolatedVar<QAngle> *__thiscall CDiscontinuousInterpolatedVar<QAngle>::CDiscontinuousInterpolatedVar<QAngle>(
        CDiscontinuousInterpolatedVar<QAngle> *this,
        const char *pDebugName)
{
  CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0> > *p_m_VarHistory; // ecx

  p_m_VarHistory = &this->m_VarHistory;
  this->__vftable = (CDiscontinuousInterpolatedVar<QAngle>_vtbl *)&CInterpolatedVarArrayBase<QAngle,0>::`vftable';
  p_m_VarHistory->m_pElements = nullptr;
  *(_DWORD *)&p_m_VarHistory->m_maxElement = 0;
  *(_DWORD *)&p_m_VarHistory->m_count = 0x100000;
  CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0>>::EnsureCapacity(this: p_m_VarHistory, capSize: 4);
  this->m_pDebugName = pDebugName;
  this->m_pValue = nullptr;
  this->m_InterpolationAmount = 0.0;
  *(_WORD *)&this->m_fType = 1;
  this->m_LastNetworkedTime = 0.0;
  this->m_LastNetworkedValue = nullptr;
  this->m_bLooping = nullptr;
  this->__vftable = (CDiscontinuousInterpolatedVar<QAngle>_vtbl *)&CInterpolatedVar<QAngle>::`vftable';
  CInterpolatedVarArrayBase<QAngle,0>::SetMaxCount(this, flCurrentTime: 0.0, newmax: 1);
  this->__vftable = (CDiscontinuousInterpolatedVar<QAngle>_vtbl *)&CDiscontinuousInterpolatedVar<QAngle>::`vftable';
  this->m_Discontinuities.m_Memory.m_pMemory = nullptr;
  this->m_Discontinuities.m_Memory.m_nAllocationCount = 0;
  this->m_Discontinuities.m_Memory.m_nGrowSize = 0;
  this->m_Discontinuities.m_Size = 0;
  this->m_Discontinuities.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100437F0
// Name: protected: void CDiscontinuousInterpolatedVar<class Vector>::ClearOldDiscontinuities(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiscontinuousInterpolatedVar<Vector>::ClearOldDiscontinuities(
        CDiscontinuousInterpolatedVar<QAngle> *this)
{
  int m_count; // eax
  float flChangeTime; // xmm0_4
  int v4; // eax
  int m_maxElement; // ecx
  float v6; // [esp+4h] [ebp-4h]

  if ( this->m_Discontinuities.m_Size != 0 )
  {
    m_count = this->m_VarHistory.m_count;
    flChangeTime = 0.0;
    v6 = 0.0;
    if ( (_WORD)m_count != 0 )
    {
      v4 = this->m_VarHistory.m_firstElement + m_count - 1;
      m_maxElement = this->m_VarHistory.m_maxElement;
      if ( v4 >= m_maxElement )
        v4 -= m_maxElement;
      flChangeTime = this->m_VarHistory.m_pElements[v4].flChangeTime;
      v6 = flChangeTime;
    }
    if ( flChangeTime >= this->m_Discontinuities.m_Memory.m_pMemory->fBeforeTime )
    {
      do
      {
        if ( this->m_Discontinuities.m_Size - 1 > 0 )
        {
          _V_memmove(
            dest: this->m_Discontinuities.m_Memory.m_pMemory,
            src: &this->m_Discontinuities.m_Memory.m_pMemory[1],
            count: 52 * (this->m_Discontinuities.m_Size - 1));
          flChangeTime = v6;
        }
        --this->m_Discontinuities.m_Size;
      }
      while ( this->m_Discontinuities.m_Size != 0
           && flChangeTime >= this->m_Discontinuities.m_Memory.m_pMemory->fBeforeTime );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100438E0
// Name: public: virtual int CDiscontinuousInterpolatedVar<class QAngle>::Interpolate(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDiscontinuousInterpolatedVar<QAngle>::Interpolate(
        CDiscontinuousInterpolatedVar<QAngle> *this,
        float currentTime)
{
  int result; // eax
  int v4; // esi
  int v5; // edi
  int v6; // eax
  const matrix3x4_t *v7; // eax
  QAngle *m_pValue; // esi
  QAngle v9; // [esp+10h] [ebp-10h] BYREF
  float fInterpolatedTime; // [esp+1Ch] [ebp-4h]
  int currentTimea; // [esp+28h] [ebp+8h]

  result = CInterpolatedVarArrayBase<QAngle,0>::Interpolate(
             this,
             currentTime,
             interpolation_amount: this->m_InterpolationAmount);
  v4 = result;
  if ( this->m_Discontinuities.m_Size != 0 )
  {
    CDiscontinuousInterpolatedVar<Vector>::ClearOldDiscontinuities(this);
    v5 = this->m_Discontinuities.m_Size - 1;
    fInterpolatedTime = currentTime - this->m_InterpolationAmount;
    if ( v5 >= 0 )
    {
      v6 = 52 * v5;
      for ( currentTimea = 52 * v5; ; v6 = currentTimea )
      {
        v7 = (matrix3x4_t *)((char *)&this->m_Discontinuities.m_Memory.m_pMemory->matTransform + v6);
        if ( fInterpolatedTime > v7[1].m_flMatVal[0][0] )
          break;
        m_pValue = this->m_pValue;
        currentTimea -= 52;
        *m_pValue = *TransformAnglesToWorldSpace(result: &v9, angles: m_pValue, parentMatrix: v7);
        v4 = 0;
        if ( --v5 < 0 )
          break;
      }
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10043990
// Name: protected: virtual C_BaseEntity::~C_BaseEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::~C_BaseEntity(C_BaseEntity *this)
{
  CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *v2; // edi
  int v3; // ebx
  CDiscontinuousInterpolatedVar<QAngle>::Discontinuity_t *m_pMemory; // eax
  CInterpolatedVarEntryBase<QAngle,0> *m_pElements; // eax
  CDiscontinuousInterpolatedVar<Vector>::Discontinuity_t *v6; // eax
  CInterpolatedVarEntryBase<Vector,0> *v7; // eax
  thinkfunc_t *v8; // eax
  VarMapEntry_t *v9; // eax
  unsigned __int16 *m_ListEntry; // [esp+8h] [ebp-4h]

  this->IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseEntity_vtbl *)&C_BaseEntity::`vftable'{for `IClientUnknown'};
  this->IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseEntity::`vftable'{for `IClientRenderable'};
  this->IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseEntity::`vftable'{for `IClientNetworkable'};
  this->IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseEntity::`vftable'{for `IClientThinkable'};
  this->IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseEntity::`vftable';
  C_BaseEntity::Term(this);
  if ( this->m_pClientAlphaProperty != nullptr )
  {
    g_pClientAlphaPropertyMgr->DestroyClientAlphaProperty(
      this: g_pClientAlphaPropertyMgr,
      a2: this->m_pClientAlphaProperty);
    this->m_pClientAlphaProperty = nullptr;
  }
  ClearDataChangedEvent(iStoredEvent: this->m_DataChangeEventRef);
  v2 = &g_EntityLists;
  m_ListEntry = this->m_ListEntry;
  do
  {
    if ( *m_ListEntry != 0xFFFF )
    {
      v3 = *m_ListEntry;
      CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::Unlink(
        this: v2,
        elem: *m_ListEntry);
      v2->m_Memory.m_pMemory[v3].m_Next = v2->m_FirstFree;
      v2->m_FirstFree = v3;
      *m_ListEntry = -1;
    }
    ++m_ListEntry;
    ++v2;
  }
  while ( (int)v2 < (int)&g_Predictables );
  this->m_iv_angRotation.m_Discontinuities.m_Size = 0;
  if ( this->m_iv_angRotation.m_Discontinuities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_iv_angRotation.m_Discontinuities.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_iv_angRotation.m_Discontinuities.m_Memory.m_pMemory);
      this->m_iv_angRotation.m_Discontinuities.m_Memory.m_pMemory = nullptr;
    }
    this->m_iv_angRotation.m_Discontinuities.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_iv_angRotation.m_Discontinuities.m_Memory.m_pMemory;
  this->m_iv_angRotation.m_Discontinuities.m_pElements = m_pMemory;
  if ( this->m_iv_angRotation.m_Discontinuities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_iv_angRotation.m_Discontinuities.m_Memory.m_pMemory = nullptr;
    }
    this->m_iv_angRotation.m_Discontinuities.m_Memory.m_nAllocationCount = 0;
  }
  this->m_iv_angRotation.__vftable = (CDiscontinuousInterpolatedVar<QAngle>_vtbl *)&CInterpolatedVarArrayBase<QAngle,0>::`vftable';
  *(_DWORD *)&this->m_iv_angRotation.m_VarHistory.m_firstElement = 0;
  C_BaseEntity::operator delete(pMem: this->m_iv_angRotation.m_bLooping);
  C_BaseEntity::operator delete(pMem: (void *)this->m_iv_angRotation.m_LastNetworkedValue);
  m_pElements = this->m_iv_angRotation.m_VarHistory.m_pElements;
  if ( m_pElements != nullptr )
    C_BaseEntity::operator delete(pMem: &m_pElements[-1].value.z);
  this->m_iv_angRotation.m_VarHistory.m_pElements = nullptr;
  this->m_iv_angRotation.__vftable = (CDiscontinuousInterpolatedVar<QAngle>_vtbl *)&IInterpolatedVar::`vftable';
  this->m_iv_vecOrigin.m_Discontinuities.m_Size = 0;
  if ( this->m_iv_vecOrigin.m_Discontinuities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_iv_vecOrigin.m_Discontinuities.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_iv_vecOrigin.m_Discontinuities.m_Memory.m_pMemory);
      this->m_iv_vecOrigin.m_Discontinuities.m_Memory.m_pMemory = nullptr;
    }
    this->m_iv_vecOrigin.m_Discontinuities.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_iv_vecOrigin.m_Discontinuities.m_Memory.m_pMemory;
  this->m_iv_vecOrigin.m_Discontinuities.m_pElements = v6;
  if ( this->m_iv_vecOrigin.m_Discontinuities.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
      this->m_iv_vecOrigin.m_Discontinuities.m_Memory.m_pMemory = nullptr;
    }
    this->m_iv_vecOrigin.m_Discontinuities.m_Memory.m_nAllocationCount = 0;
  }
  this->m_iv_vecOrigin.__vftable = (CDiscontinuousInterpolatedVar<Vector>_vtbl *)&CInterpolatedVarArrayBase<Vector,0>::`vftable';
  *(_DWORD *)&this->m_iv_vecOrigin.m_VarHistory.m_firstElement = 0;
  C_BaseEntity::operator delete(pMem: this->m_iv_vecOrigin.m_bLooping);
  C_BaseEntity::operator delete(pMem: (void *)this->m_iv_vecOrigin.m_LastNetworkedValue);
  v7 = this->m_iv_vecOrigin.m_VarHistory.m_pElements;
  if ( v7 != nullptr )
    C_BaseEntity::operator delete(pMem: &v7[-1].value.z);
  this->m_iv_vecOrigin.m_VarHistory.m_pElements = nullptr;
  this->m_iv_vecOrigin.__vftable = (CDiscontinuousInterpolatedVar<Vector>_vtbl *)&IInterpolatedVar::`vftable';
  CParticleProperty::~CParticleProperty(this: &this->m_Particles);
  CCollisionProperty::~CCollisionProperty(this: &this->m_Collision);
  this->m_aThinkFunctions.m_Size = 0;
  if ( this->m_aThinkFunctions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aThinkFunctions.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aThinkFunctions.m_Memory.m_pMemory);
      this->m_aThinkFunctions.m_Memory.m_pMemory = nullptr;
    }
    this->m_aThinkFunctions.m_Memory.m_nAllocationCount = 0;
  }
  v8 = this->m_aThinkFunctions.m_Memory.m_pMemory;
  this->m_aThinkFunctions.m_pElements = v8;
  if ( this->m_aThinkFunctions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
      this->m_aThinkFunctions.m_Memory.m_pMemory = nullptr;
    }
    this->m_aThinkFunctions.m_Memory.m_nAllocationCount = 0;
  }
  this->m_VarMap.m_Entries.m_Size = 0;
  if ( this->m_VarMap.m_Entries.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_VarMap.m_Entries.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VarMap.m_Entries.m_Memory.m_pMemory);
      this->m_VarMap.m_Entries.m_Memory.m_pMemory = nullptr;
    }
    this->m_VarMap.m_Entries.m_Memory.m_nAllocationCount = 0;
  }
  v9 = this->m_VarMap.m_Entries.m_Memory.m_pMemory;
  this->m_VarMap.m_Entries.m_pElements = v9;
  if ( this->m_VarMap.m_Entries.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v9 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
      this->m_VarMap.m_Entries.m_Memory.m_pMemory = nullptr;
    }
    this->m_VarMap.m_Entries.m_Memory.m_nAllocationCount = 0;
  }
  this->IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseEntity_vtbl *)&IHandleEntity::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10043C90
// Name: public: virtual bool C_BaseEntity::InitializeAsClientEntity(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::InitializeAsClientEntity(
        C_BaseEntity *this,
        const char *pszModelName,
        BOOL bRenderWithViewModels)
{
  int v4; // eax
  __int16 v5; // si

  if ( pszModelName != nullptr )
  {
    v4 = modelinfo->GetModelIndex(this: modelinfo, a2: pszModelName);
    v5 = v4;
    if ( v4 == -1 )
      return 0;
  }
  else
  {
    v5 = -1;
  }
  C_BaseEntity::Interp_SetupMappings(this, map: &this->m_VarMap);
  return C_BaseEntity::InitializeAsClientEntityByIndex(this, iIndex: v5, bRenderWithViewModels);
}

//------------------------------------------------------------------------------
// Address: 0x10043CE0
// Name: public: void C_BaseEntity::HierarchyUpdateMoveParent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::HierarchyUpdateMoveParent(C_BaseEntity *this)
{
  unsigned int m_Index; // edx

  m_Index = this->m_hNetworkMoveParent.m_Index;
  if ( m_Index != this->m_pMoveParent.m_Index )
  {
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      C_BaseEntity::HierarchySetParent(this, pNewParent: nullptr);
    else
      C_BaseEntity::HierarchySetParent(
        this,
        pNewParent: (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043D30
// Name: public: virtual bool C_BaseEntity::Interpolate(float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseEntity::Interpolate(C_BaseEntity *this, float currentTime)
{
  int v3; // ebx
  unsigned __int16 v4; // ax
  int v5; // edi
  int v6; // ecx
  QAngle oldAngles; // [esp+8h] [ebp-1Ch] BYREF
  Vector oldOrigin; // [esp+14h] [ebp-10h] BYREF
  int bNoMoreChanges; // [esp+20h] [ebp-4h] BYREF

  v3 = C_BaseEntity::BaseInterpolatePart1(this, &currentTime, &oldOrigin, &oldAngles, &bNoMoreChanges);
  if ( bNoMoreChanges != 0 )
  {
    v4 = this->m_ListEntry[0];
    if ( v4 != 0xFFFF )
    {
      v5 = this->m_ListEntry[0];
      CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::Unlink(
        this: &g_EntityLists,
        elem: v4);
      g_EntityLists.m_Memory.m_pMemory[v5].m_Next = g_EntityLists.m_FirstFree;
      g_EntityLists.m_FirstFree = v5;
      this->m_ListEntry[0] = -1;
    }
  }
  if ( v3 != 0 )
  {
    v6 = 0;
    if ( oldOrigin.x != this->m_vecOrigin.x || oldOrigin.y != this->m_vecOrigin.y || oldOrigin.z != this->m_vecOrigin.z )
      v6 = 1;
    if ( oldAngles.x != this->m_angRotation.x
      || oldAngles.y != this->m_angRotation.y
      || oldAngles.z != this->m_angRotation.z )
    {
      v6 |= 2u;
    }
    if ( v6 != 0 )
      C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: v6);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10043E40
// Name: protected: static void C_BaseEntity::ProcessTeleportList(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl C_BaseEntity::ProcessTeleportList()
{
  unsigned __int16 m_Head; // ax
  C_RopeKeyframe *m_Element; // esi
  int m_Next; // ebx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // edx
  unsigned int v5; // ecx
  IHandleEntity *v6; // eax
  unsigned __int16 v7; // ax
  int v8; // edi
  unsigned __int8 m_iParentAttachment; // dl

  m_Head = stru_105FD31C.m_Head;
  if ( stru_105FD31C.m_Head != 0xFFFF )
  {
    do
    {
      m_Element = stru_105FD31C.m_Memory.m_pMemory[m_Head].m_Element;
      m_Next = stru_105FD31C.m_Memory.m_pMemory[m_Head].m_Next;
      m_Index = m_Element->m_hNetworkMoveParent.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      v5 = m_Element->m_hOldMoveParent.m_Index;
      if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
        v6 = nullptr;
      else
        v6 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
      if ( v6 == m_pEntity
        && m_Element->m_iOldParentAttachment == m_Element->m_iParentAttachment
        && (m_Element->m_fEffects & 8) == 0 )
      {
        v7 = m_Element->m_ListEntry[1];
        if ( v7 != 0xFFFF )
        {
          v8 = m_Element->m_ListEntry[1];
          CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::Unlink(
            this: &stru_105FD31C,
            elem: v7);
          stru_105FD31C.m_Memory.m_pMemory[v8].m_Next = stru_105FD31C.m_FirstFree;
          stru_105FD31C.m_FirstFree = v8;
          m_Element->m_ListEntry[1] = -1;
        }
      }
      else
      {
        m_iParentAttachment = m_Element->m_iParentAttachment;
        m_Element->m_hOldMoveParent.m_Index = m_Element->m_hNetworkMoveParent.m_Index;
        m_Element->m_iOldParentAttachment = m_iParentAttachment;
        C_BaseEntity::MoveToLastReceivedPosition(this: m_Element, force: true);
        m_Element->ResetLatched(this: m_Element);
      }
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043F90
// Name: private: static void C_BaseEntity::InterpolateServerEntities(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl C_BaseEntity::InterpolateServerEntities()
{
  int m_nValue; // eax
  bool v1; // al
  int v2; // eax
  INetChannelInfo *v3; // eax
  C_BaseEntity *i; // eax
  CInterpolationContext *v5; // eax
  C_BaseEntity *j; // eax
  CInterpolationContext context; // [esp+0h] [ebp-14h] BYREF
  C_BaseEntityIterator iterator; // [esp+Ch] [ebp-8h] BYREF
  bool bPrevInterpolate; // [esp+13h] [ebp-1h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_BaseEntity::InterpolateServerEntities",
    a3: 0,
    a4: "Interpolation",
    a5: false,
    a6: 4);
  bPrevInterpolate = C_BaseEntity::s_bInterpolate;
  if ( hermite.m_pParent != nullptr )
    m_nValue = hermite.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v1 = m_nValue != 0;
  if ( v1 != g_bHermiteFix )
    g_bHermiteFix = v1;
  if ( cl_interpolate.m_pParent != nullptr )
    v2 = cl_interpolate.m_pParent->m_Value.m_nValue;
  else
    v2 = 0;
  C_BaseEntity::s_bInterpolate = v2 != 0;
  if ( engine->IsPlayingTimeDemo(this: engine) || engine->IsPaused(this: engine) )
    C_BaseEntity::s_bInterpolate = false;
  v3 = engine->GetNetChannelInfo(this: engine);
  if ( v3 != nullptr && ((double (__thiscall *)(INetChannelInfo *))v3->GetTimeSinceLastReceived)(a1: v3) > 0.5 )
    C_BaseEntity::s_bInterpolate = false;
  if ( C_BaseEntity::IsSimulatingOnAlternateTicks() != g_bWasSkipping || IsEngineThreaded() != g_bWasThreaded )
  {
    g_bWasSkipping = C_BaseEntity::IsSimulatingOnAlternateTicks();
    g_bWasThreaded = IsEngineThreaded();
    C_BaseEntityIterator::C_BaseEntityIterator(this: &iterator);
    for ( i = C_BaseEntityIterator::Next(this: &iterator); i != nullptr; i = C_BaseEntityIterator::Next(this: &iterator) )
      C_BaseEntity::Interp_UpdateInterpolationAmounts(this: i, map: &i->m_VarMap);
  }
  v5 = CInterpolationContext::s_pHead;
  CInterpolationContext::s_pHead = &context;
  context.m_pNext = v5;
  context.m_bOldAllowExtrapolation = CInterpolationContext::s_bAllowExtrapolation;
  context.m_flOldLastTimeStamp = CInterpolationContext::s_flLastTimeStamp;
  CInterpolationContext::s_bAllowExtrapolation = false;
  CInterpolationContext::s_flLastTimeStamp = engine->GetLastTimeStamp(this: engine);
  if ( cl_extrapolate.m_pParent != nullptr
    && cl_extrapolate.m_pParent->m_Value.m_nValue != 0
    && !engine->IsPaused(this: engine) )
  {
    CInterpolationContext::s_bAllowExtrapolation = true;
  }
  if ( bPrevInterpolate != C_BaseEntity::s_bInterpolate && !C_BaseEntity::s_bInterpolate )
  {
    C_BaseEntityIterator::C_BaseEntityIterator(this: &iterator);
    for ( j = C_BaseEntityIterator::Next(this: &iterator); j != nullptr; j = C_BaseEntityIterator::Next(this: &iterator) )
      j->ResetLatched(this: j);
  }
  C_BaseEntity::ProcessTeleportList();
  C_BaseEntity::ProcessInterpolatedList();
  CInterpolationContext::s_bAllowExtrapolation = context.m_bOldAllowExtrapolation;
  CInterpolationContext::s_flLastTimeStamp = context.m_flOldLastTimeStamp;
  CInterpolationContext::s_pHead = context.m_pNext;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100441A0
// Name: public: virtual void C_BaseEntity::InitPredictable(class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::InitPredictable(C_BaseEntity *this, C_BasePlayer *pOwner)
{
  unsigned __int8 *SplitScreenSlotForPlayer; // esi
  CUtlSortVector<C_BaseEntity *,CEntIndexLessFunc> *v4; // esi
  signed int i; // esi

  this->SetPredictable(this, a2: true);
  SplitScreenSlotForPlayer = C_BasePlayer::GetSplitScreenSlotForPlayer(pl: pOwner);
  this->m_nSplitUserPlayerPredictionSlot = (int)SplitScreenSlotForPlayer;
  C_BaseEntity::AllocateIntermediateData(this);
  v4 = &g_Predictables + (_DWORD)SplitScreenSlotForPlayer;
  pOwner = (C_BasePlayer *)this;
  if ( CUtlSortVector<C_BaseEntity *,CEntIndexLessFunc>::Find(this: v4, src: &pOwner) == -1 )
    CUtlSortVector<C_BaseEntity *,CEntIndexLessFunc>::Insert(this: v4, src: &pOwner);
  C_BaseEntity::PostNetworkDataReceived(this, commands_acknowledged: 0);
  for ( i = 0; i < 150; ++i )
    C_BaseEntity::SaveData(this, context: "InitPredictable", slot: i, type: 2);
}

//------------------------------------------------------------------------------
// Address: 0x10044230
// Name: protected: void C_BaseEntity::AddToEntityList(enum entity_list_ids_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::AddToEntityList(C_BaseEntity *this, entity_list_ids_t listId)
{
  unsigned __int16 v2; // ax
  int v3; // esi
  C_BaseEntity **v4; // eax

  if ( this->m_ListEntry[listId] == 0xFFFF )
  {
    v2 = CUtlLinkedList<C_BaseEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseEntity *,unsigned short>,unsigned short>>::AllocInternal(
           this: (CUtlLinkedList<C_BaseEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseEntity *,unsigned short>,unsigned short> > *)&g_EntityLists
         + listId,
           multilist: false);
    v3 = v2;
    if ( v2 == 0xFFFF )
    {
      this->m_ListEntry[listId] = -1;
    }
    else
    {
      CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
        this: &g_EntityLists + listId,
        before: 0xFFFFu,
        elem: v2);
      v4 = (C_BaseEntity **)(*((_DWORD *)&g_EntityLists.m_Memory.m_pMemory + 7 * listId) + 8 * v3);
      if ( v4 != nullptr )
        *v4 = this;
      this->m_ListEntry[listId] = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100442C0
// Name: void cc_cl_interp_all_changed(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl cc_cl_interp_all_changed(IConVar *pConVar)
{
  C_BaseEntity *i; // edi
  unsigned __int16 v2; // ax
  int v3; // esi
  __int16 v4; // ax
  UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short> *v5; // eax
  ConVarRef var; // [esp+0h] [ebp-Ch] BYREF
  C_BaseEntityIterator iterator; // [esp+8h] [ebp-4h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  if ( var.m_pConVarState->m_Value.m_nValue != 0 )
  {
    C_BaseEntityIterator::C_BaseEntityIterator(this: &iterator);
    for ( i = C_BaseEntityIterator::Next(this: &iterator); i != nullptr; i = C_BaseEntityIterator::Next(this: &iterator) )
    {
      if ( i->ShouldInterpolate(this: i) && i->m_ListEntry[0] == 0xFFFF )
      {
        v2 = CUtlLinkedList<C_BaseEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseEntity *,unsigned short>,unsigned short>>::AllocInternal(
               this: (CUtlLinkedList<C_BaseEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseEntity *,unsigned short>,unsigned short> > *)&g_EntityLists,
               multilist: false);
        v3 = v2;
        if ( v2 == 0xFFFF )
        {
          v4 = -1;
        }
        else
        {
          CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
            this: &g_EntityLists,
            before: 0xFFFFu,
            elem: v2);
          v5 = &g_EntityLists.m_Memory.m_pMemory[v3];
          if ( v5 != nullptr )
            v5->m_Element = (C_RopeKeyframe *)i;
          v4 = v3;
        }
        i->m_ListEntry[0] = v4;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044380
// Name: public: C_BaseEntity::C_BaseEntity(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall C_BaseEntity::C_BaseEntity(C_BaseEntity *this)
{
  unsigned __int16 v2; // ax
  unsigned __int16 v3; // ax
  UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short> *v4; // eax
  unsigned __int16 v6; // [esp+Ch] [ebp-4h]

  this->IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&IClientRenderable::`vftable';
  this->IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&IClientNetworkable::`vftable';
  this->IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&IClientThinkable::`vftable';
  this->IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&IClientModelRenderable::`vftable';
  this->IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseEntity_vtbl *)&C_BaseEntity::`vftable'{for `IClientUnknown'};
  this->IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseEntity::`vftable'{for `IClientRenderable'};
  this->IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseEntity::`vftable'{for `IClientNetworkable'};
  this->IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseEntity::`vftable'{for `IClientThinkable'};
  this->IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseEntity::`vftable';
  this->m_VarMap.m_Entries.m_Memory.m_pMemory = nullptr;
  this->m_VarMap.m_Entries.m_Memory.m_nAllocationCount = 0;
  this->m_VarMap.m_Entries.m_Memory.m_nGrowSize = 0;
  this->m_VarMap.m_Entries.m_Size = 0;
  this->m_VarMap.m_Entries.m_pElements = nullptr;
  this->m_VarMap.m_nInterpolatedEntries = 0;
  this->m_hNetworkMoveParent.m_Index = -1;
  this->m_hOwnerEntity.m_Index = -1;
  this->m_hGroundEntity.m_Index = -1;
  if ( this != (C_BaseEntity *)-616 )
    this->m_VisibilityBits.m_Ints[0] = 0;
  this->m_RefEHandle.m_Index = -1;
  this->m_aThinkFunctions.m_Memory.m_pMemory = nullptr;
  this->m_aThinkFunctions.m_Memory.m_nAllocationCount = 0;
  this->m_aThinkFunctions.m_Memory.m_nGrowSize = 0;
  this->m_aThinkFunctions.m_Size = 0;
  this->m_aThinkFunctions.m_pElements = nullptr;
  if ( this != (C_BaseEntity *)-724 )
    this->m_ShadowBits.m_Ints[0] = 0;
  this->m_pMoveParent.m_Index = -1;
  this->m_pMoveChild.m_Index = -1;
  this->m_pMovePeer.m_Index = -1;
  this->m_pMovePrevPeer.m_Index = -1;
  this->m_hOldMoveParent.m_Index = -1;
  CCollisionProperty::CCollisionProperty(this: &this->m_Collision);
  this->m_Collision.__vftable = (C_BaseEntity::NetworkVar_m_Collision_vtbl *)&C_BaseEntity::NetworkVar_m_Collision::`vftable';
  CParticleProperty::CParticleProperty(this: &this->m_Particles);
  this->m_Particles.__vftable = (C_BaseEntity::NetworkVar_m_Particles_vtbl *)&C_BaseEntity::NetworkVar_m_Particles::`vftable';
  this->m_ShadowDirUseOtherEntity.m_Index = -1;
  CDiscontinuousInterpolatedVar<Vector>::CDiscontinuousInterpolatedVar<Vector>(
    this: &this->m_iv_vecOrigin,
    pDebugName: "C_BaseEntity::m_iv_vecOrigin");
  CDiscontinuousInterpolatedVar<QAngle>::CDiscontinuousInterpolatedVar<QAngle>(
    this: &this->m_iv_angRotation,
    pDebugName: "C_BaseEntity::m_iv_angRotation");
  this->m_hPlayerSimulationOwner.m_Index = -1;
  this->m_hEffectEntity.m_Index = -1;
  this->m_CalcAbsolutePositionMutex.m_ownerID = 0;
  this->m_CalcAbsolutePositionMutex.m_depth = 0;
  this->m_CalcAbsoluteVelocityMutex.m_ownerID = 0;
  this->m_CalcAbsoluteVelocityMutex.m_depth = 0;
  C_BaseEntity::AddVar(this, data: (void *)&this->m_vecOrigin, watcher: &this->m_iv_vecOrigin, type: 2, bSetup: false);
  C_BaseEntity::AddVar(
    this,
    data: (void *)&this->m_angRotation,
    watcher: &this->m_iv_angRotation,
    type: 2,
    bSetup: false);
  *(_DWORD *)&this->m_nMinCPULevel = 0;
  *(_QWORD *)&this->m_fadeMaxDist = 0;
  this->m_fadeMinDist = 0.0;
  this->m_pClientAlphaProperty = nullptr;
  this->m_nSplitUserPlayerPredictionSlot = 0;
  this->m_DataChangeEventRef = -1;
  this->m_EntClientFlags = 0;
  *(_WORD *)&this->m_bRenderWithViewModels = 0;
  this->m_iParentAttachment = 0;
  this->m_bIsValidIKAttachment = false;
  this->m_bPredictionEligible = false;
  this->m_bPredictable = false;
  if ( this->m_bSimulatedEveryTick.m_Value )
    this->m_bSimulatedEveryTick.m_Value = false;
  if ( this->m_bAnimatedEveryTick.m_Value )
    this->m_bAnimatedEveryTick.m_Value = false;
  this->m_pPhysicsObject = nullptr;
  this->m_bDisableSimulationFix = false;
  SetIdentityMatrix(matrix: &this->m_rgflCoordinateFrame);
  this->m_nSimulationTick = -1;
  this->m_bReadyToDraw = true;
  this->m_flProxyRandomValue = 0.0;
  this->m_fBBoxVisFlags = 0;
  *(_DWORD *)this->m_ListEntry = -1;
  *(_DWORD *)&this->m_ListEntry[2] = -1;
  this->m_ListEntry[4] = -1;
  if ( this->m_ListEntry[2] == 0xFFFF )
  {
    v2 = CUtlLinkedList<C_BaseEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseEntity *,unsigned short>,unsigned short>>::AllocInternal(
           this: (CUtlLinkedList<C_BaseEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseEntity *,unsigned short>,unsigned short> > *)&stru_105FD338,
           multilist: false);
    v6 = v2;
    if ( v2 == 0xFFFF )
    {
      v3 = -1;
    }
    else
    {
      CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
        this: &stru_105FD338,
        before: 0xFFFFu,
        elem: v2);
      v4 = &stru_105FD338.m_Memory.m_pMemory[v6];
      if ( v4 != nullptr )
        v4->m_Element = (C_RopeKeyframe *)this;
      v3 = v6;
    }
    this->m_ListEntry[2] = v3;
  }
  C_BaseEntity::Clear(this);
  *(_WORD *)&this->m_bEnabledInToolView = 1;
  this->m_ToolHandle = 0;
  this->m_nLastRecordedFrame = -1;
  this->m_bRecordInTools = true;
  CSceneTokenProcessor::SetBuffer(this: (CTraceFilterSimple *)&this->m_Particles, pPassEntity: this);
  this->m_spawnflags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10044690
// Name: public: virtual void C_BaseEntity::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::PostDataUpdate(C_BaseEntity *this, DataUpdateType_t updateType)
{
  C_BaseEntity *v4; // ebx
  unsigned __int8 v5; // al
  CClientAlphaProperty *m_pClientAlphaProperty; // ecx
  bool v7; // al
  bool v8; // dl
  bool v9; // al
  C_BaseEntity *v10; // ecx
  float z; // ecx
  C_BaseEntity *m_pEntity; // eax
  unsigned int v13; // ecx
  C_BaseEntity *v14; // eax
  unsigned int v15; // ecx
  C_BasePlayer **v16; // eax
  C_BasePlayer *v17; // edi
  float v18; // ecx
  IHandleEntity *v19; // ecx
  unsigned int m_Index; // esi
  IHandleEntity *v21; // eax
  bool v22; // [esp+14h] [ebp-14h]
  bool simulationChanged; // [esp+27h] [ebp-1h]
  bool animTimeChanged_3; // [esp+33h] [ebp+Bh]

  v22 = *(&this->m_nOldRenderMode + 1) != 0 && updateType == DATA_UPDATE_CREATED;
  v4 = (C_BaseEntity *)((char *)this - 8);
  C_BaseEntity::MoveToLastReceivedPosition(this: (C_BaseEntity *)((char *)this - 8), force: v22);
  if ( DWORD2(this->m_pfnTouch) == 0 )
  {
    *(_WORD *)&this->m_iName[252] = 1;
    CCollisionProperty::SetSolid(this: (CCollisionProperty *)&this->m_hOldMoveParent, val: SOLID_BSP);
    C_BaseEntity::SetAbsOrigin(this: (C_BaseEntity *)((char *)this - 8), absOrigin: &vec3_origin);
    C_BaseEntity::SetAbsAngles(this: (C_BaseEntity *)((char *)this - 8), absAngles: &vec3_angle);
  }
  v5 = this->m_iName[255];
  if ( LOBYTE(this->m_flSimulationTime) != v5 && v5 != v4->m_nRenderMode )
  {
    m_pClientAlphaProperty = v4->m_pClientAlphaProperty;
    v4->m_nRenderMode = v5;
    ((void (__thiscall *)(CClientAlphaProperty *, _DWORD, _DWORD, int, _DWORD))m_pClientAlphaProperty->SetRenderFX)(
      a1: m_pClientAlphaProperty,
      a2: v4->m_nRenderFX,
      a3: v5,
      a4: 2139095039,
      a5: 0);
  }
  animTimeChanged_3 = *(float *)&this->m_nModelIndex != *(float *)&this->m_MoveType;
  v7 = this->m_vecAbsOrigin.y != *(float *)&this->m_ShadowDirUseOtherEntity.m_Index
    || this->m_vecAbsOrigin.z != this->m_flGroundChangeTime
    || this->m_vecOrigin.x != this->m_vecOldOrigin.x;
  v8 = v7;
  v9 = this->m_angAbsRotation.y != this->m_vecOldOrigin.y
    || this->m_angAbsRotation.z != this->m_vecOldOrigin.z
    || this->m_angRotation.x != this->m_vecOldAngRotation.x;
  if ( v8 || v9 || (simulationChanged = false, this->m_flAnimTime != this->m_flOldAnimTime) )
    simulationChanged = true;
  v10 = (C_BaseEntity *)((char *)this - 8);
  if ( BYTE2(this->m_flFadeScale) != 0 )
  {
    C_BaseEntity::OnStoreLastNetworkedValue(this: v10);
  }
  else if ( !v4->IsClientCreated(this: v10) )
  {
    if ( animTimeChanged_3 )
      v4->OnLatchInterpolatedVariables(this: (C_BaseEntity *)((char *)this - 8), a2: 1);
    if ( simulationChanged )
      v4->OnLatchInterpolatedVariables(this: (C_BaseEntity *)((char *)this - 8), a2: 2);
  }
  z = this->m_vecNetworkOrigin.z;
  if ( z == NAN || g_pEntityList->m_EntPtrArray[LOWORD(z)].m_SerialNumber != HIWORD(LODWORD(z)) )
    m_pEntity = nullptr;
  else
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(z)].m_pEntity;
  C_BaseEntity::HierarchySetParent(this: (C_BaseEntity *)((char *)this - 8), pNewParent: m_pEntity);
  *(float *)&this->m_nIncomingPacketEntityBecameDormant = engine->GetLastTimeStamp(this: engine);
  v4->ValidateModelIndex(this: (C_BaseEntity *)((char *)this - 8));
  if ( updateType == DATA_UPDATE_CREATED )
  {
    this->m_angRotation.z = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                              a1: random,
                              a2: 0,
                              a3: 1065353216);
    v4->ResetLatched(this: (C_BaseEntity *)((char *)this - 8));
    this->m_fDataObjectTypes = *(_DWORD *)(gpGlobals.m_Index + 24);
  }
  if ( BYTE1(this->m_nIntermediateDataCount) != 0 )
  {
    v13 = *(_DWORD *)&this->m_nMaxGPULevel;
    if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
      v14 = nullptr;
    else
      v14 = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
    if ( C_BasePlayer::IsLocalPlayer(pEntity: v14) )
    {
      v15 = *(_DWORD *)&this->m_nMaxGPULevel;
      if ( v15 == -1
        || (v16 = (C_BasePlayer **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v15],
            g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber != HIWORD(v15))
        || (v17 = *v16, *v16 == nullptr)
        || !v17->IsPlayer(this: v17) )
      {
        v17 = nullptr;
      }
      C_BaseEntity::SetPlayerSimulated(this: (C_BaseEntity *)((char *)this - 8), pOwner: v17);
    }
  }
  v4->UpdatePartitionListEntry(this: (C_BaseEntity *)((char *)this - 8));
  if ( !v4->IsClientCreated(this: (C_BaseEntity *)((char *)this - 8))
    && (C_BaseEntity::Teleported(this: (C_BaseEntity *)((char *)this - 8)) || (this->m_iEFlags & 8) != 0) )
  {
    C_BaseEntity::AddToEntityList(this: (C_BaseEntity *)((char *)this - 8), listId: ENTITY_LIST_TELEPORT);
  }
  v18 = this->m_vecNetworkOrigin.z;
  if ( v18 == NAN || g_pEntityList->m_EntPtrArray[LOWORD(v18)].m_SerialNumber != HIWORD(LODWORD(v18)) )
    v19 = nullptr;
  else
    v19 = g_pEntityList->m_EntPtrArray[LOWORD(v18)].m_pEntity;
  m_Index = this->m_pMovePeer.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    v21 = nullptr;
  else
    v21 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( v21 != v19 )
    C_BaseEntity::UpdateVisibility(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10044A40
// Name: public: virtual void C_BaseEntity::OnLatchInterpolatedVariables(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::OnLatchInterpolatedVariables(C_BaseEntity *this, int flags)
{
  VarMapEntry_t *v3; // esi
  IInterpolatedVar *watcher; // edi
  int v5; // eax
  float changetime; // [esp+18h] [ebp-10h]
  int m_Size; // [esp+20h] [ebp-8h]
  int v8; // [esp+24h] [ebp-4h]

  changetime = C_BaseEntity::GetLastChangeTime(this, flags);
  if ( this->m_VarMap.m_Entries.m_Size > 0 )
  {
    v8 = 0;
    m_Size = this->m_VarMap.m_Entries.m_Size;
    do
    {
      v3 = &this->m_VarMap.m_Entries.m_Memory.m_pMemory[v8];
      watcher = v3->watcher;
      v5 = watcher->GetType(this: watcher);
      if ( (v5 & flags) != 0
        && (v5 & 4) == 0
        && ((unsigned __int8 (__thiscall *)(IInterpolatedVar *, _DWORD, float, bool))watcher->NoteChanged)(
             a1: watcher,
             a2: *(_DWORD *)(gpGlobals.m_Index + 12),
             a3: COERCE_FLOAT(LODWORD(changetime)),
             a4: (flags & 0x20) == 0) != 0 )
      {
        v3->m_bNeedsToInterpolate = 1;
      }
      ++v8;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  if ( this->ShouldInterpolate(this) )
    C_BaseEntity::AddToEntityList(this, listId: ENTITY_LIST_INTERPOLATE);
}

//------------------------------------------------------------------------------
// Address: 0x10044B00
// Name: public: void C_BaseEntity::Remove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::Remove(C_BaseEntity *this)
{
  if ( (this->m_iEFlags & 1) == 0 )
  {
    this->m_iEFlags |= 1u;
    if ( this->m_bPredictable || this->IsClientCreated(this) )
    {
      CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
      *(_WORD *)&this->m_MoveType = 0;
    }
    if ( s_bImmediateRemovesAllowed )
      this->Release(this: &this->IClientNetworkable);
    else
      C_BaseEntity::AddToEntityList(this, listId: ENTITY_LIST_DELETE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044B70
// Name: public: virtual void C_BaseEntity::SUB_Remove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseEntity::SUB_Remove(C_BaseEntity *this)
{
  if ( this->m_iHealth > 0 )
  {
    this->m_iHealth = 0;
    _DevWarning(a1: 2, a2: "SUB_Remove called on entity with health > 0\n");
  }
  C_BaseEntity::Remove(this);
}

//------------------------------------------------------------------------------
// Address: 0x10044C00
// Name: void InitC_BaseEntityScriptDesc(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitC_BaseEntityScriptDesc()
{
  ScriptFunctionBinding_t *v0; // eax
  ScriptFunctionBinding_t *v1; // eax
  ScriptFunctionBinding_t *v2; // eax
  ScriptFunctionBinding_t *v3; // eax
  ScriptFunctionBinding_t *v4; // eax

  if ( !bInitialized_0 )
  {
    g_C_BaseEntity_ScriptDesc.m_pszScriptName = "C_BaseEntity";
    g_C_BaseEntity_ScriptDesc.m_pszClassname = "C_BaseEntity";
    g_C_BaseEntity_ScriptDesc.m_pBaseDesc = nullptr;
    g_C_BaseEntity_ScriptDesc.pHelper = nullptr;
    bInitialized_0 = true;
    g_C_BaseEntity_ScriptDesc.m_pszDescription = "Root class of all client-side entities";
    v0 = &g_C_BaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_C_BaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_C_BaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v0->m_desc.m_pszDescription = prType;
    v0->m_desc.m_pszScriptName = "GetOrigin";
    v0->m_desc.m_pszFunction = "GetAbsOrigin";
    v0->m_desc.m_ReturnType = 3;
    v0->m_pfnBinding = CMemberScriptBinding0<C_BaseEntity *,Vector const & (__thiscall C_BaseEntity::*)(void),Vector const &>::Call;
    v0->m_pFunction =  __thiscall IGameSystem::`vcall'{40,{flat}};
    v0->m_flags = 1;
    v1 = &g_C_BaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_C_BaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_C_BaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v1->m_desc.m_pszDescription = "Get the forward vector of the entity";
    v1->m_desc.m_pszScriptName = "GetForwardVector";
    v1->m_desc.m_pszFunction = "ScriptGetForward";
    v1->m_desc.m_ReturnType = 3;
    v1->m_pfnBinding = CMemberScriptBinding0<C_BaseEntity *,Vector const & (__thiscall C_BaseEntity::*)(void),Vector const &>::Call;
    v1->m_pFunction = C_BaseEntity::ScriptGetForward;
    v1->m_flags = 1;
    v2 = &g_C_BaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_C_BaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_C_BaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v2->m_desc.m_pszDescription = "Get the left vector of the entity";
    v2->m_desc.m_pszScriptName = "GetLeftVector";
    v2->m_desc.m_pszFunction = "ScriptGetLeft";
    v2->m_desc.m_ReturnType = 3;
    v2->m_pfnBinding = CMemberScriptBinding0<C_BaseEntity *,Vector const & (__thiscall C_BaseEntity::*)(void),Vector const &>::Call;
    v2->m_pFunction = C_BaseEntity::ScriptGetLeft;
    v2->m_flags = 1;
    v3 = &g_C_BaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_C_BaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_C_BaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v3->m_desc.m_pszDescription = "Get the up vector of the entity";
    v3->m_desc.m_pszScriptName = "GetUpVector";
    v3->m_desc.m_pszFunction = "ScriptGetUp";
    v3->m_desc.m_ReturnType = 3;
    v3->m_pfnBinding = CMemberScriptBinding0<C_BaseEntity *,Vector const & (__thiscall C_BaseEntity::*)(void),Vector const &>::Call;
    v3->m_pFunction = C_BaseEntity::ScriptGetUp;
    v3->m_flags = 1;
    v4 = &g_C_BaseEntity_ScriptDesc.m_FunctionBindings.m_Memory.m_pMemory[CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
                                                                            this: &g_C_BaseEntity_ScriptDesc.m_FunctionBindings,
                                                                            elem: g_C_BaseEntity_ScriptDesc.m_FunctionBindings.m_Size)];
    v4->m_desc.m_pszDescription = "Gets this entity's team";
    v4->m_desc.m_pszScriptName = "GetTeamNumber";
    v4->m_desc.m_pszFunction = "GetTeamNumber";
    v4->m_desc.m_ReturnType = 5;
    v4->m_pfnBinding = CMemberScriptBinding0<C_BaseEntity *,int (__thiscall C_BaseEntity::*)(void),int>::Call;
    v4->m_flags = 1;
    v4->m_pFunction =  __thiscall C_BaseEntity::`vcall'{332,{flat}};
  }
}

//------------------------------------------------------------------------------
// Address: 0x10369C30
// Name: private: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::QueueFunctorInternal(class CFunctor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        CFunctor *pFunctor)
{
  CTSQueue<SProjectedTextureInfo *,0,1>::Node_t *v3; // eax

  if ( this->m_bNoQueue )
  {
    pFunctor->operator()(this: pFunctor);
    pFunctor->Release(this: pFunctor);
  }
  else
  {
    v3 = (CTSQueue<SProjectedTextureInfo *,0,1>::Node_t *)CTSListBase::Pop(this: &this->m_queue.m_FreeNodes);
    if ( v3 != nullptr || (v3 = (CTSQueue<SProjectedTextureInfo *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u)) != nullptr )
    {
      v3->elem = (SProjectedTextureInfo *)pFunctor;
      CTSQueue<CFunctor *,0,1>::Push(this: &this->m_queue, pNode: v3);
    }
    else
    {
      CTSQueue<CFunctor *,0,1>::Push(this: &this->m_queue, pNode: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10369CB0
// Name: private: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::ExecuteWrapper(int __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::ExecuteWrapper(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        int *nDummy)
{
  CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(this);
}

//------------------------------------------------------------------------------
// Address: 0x10369DE0
// Name: public: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::ParallelCallQueued(class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::ParallelCallQueued(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        IThreadPool *pPool)
{
  IThreadPool *v2; // esi
  volatile int m_value; // ebx
  volatile int v5; // eax
  CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> v6; // [esp+Ch] [ebp-1Ch] BYREF

  v2 = pPool;
  if ( pPool == nullptr )
  {
    v2 = _g_pThreadPool;
    if ( _g_pThreadPool == nullptr )
      goto LABEL_11;
  }
  if ( this->m_queue.m_Count.m_value >= 1 )
    m_value = this->m_queue.m_Count.m_value;
  else
    m_value = 1;
  if ( v2->NumThreads(this: v2) >= m_value )
  {
    if ( this->m_queue.m_Count.m_value < 1 )
    {
LABEL_11:
      CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(this);
      return;
    }
    v5 = this->m_queue.m_Count.m_value;
  }
  else
  {
    v5 = v2->NumThreads(this: v2);
  }
  if ( v5 < 2 )
    goto LABEL_11;
  v6.m_pItems.m_value = nullptr;
  v6.m_pLimit = nullptr;
  _InterlockedExchange((volatile __int32 *)&v6.m_pItems, 0);
  v6.m_ItemProcessor.m_pfnBegin = nullptr;
  v6.m_ItemProcessor.m_pfnEnd = nullptr;
  v6.m_ItemProcessor.m_pObject = this;
  v6.m_ItemProcessor.m_pfnProcess = CCallQueueT<CTSQueue<CFunctor *,0,1>>::ExecuteWrapper;
  CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::Run(
    this: &v6,
    pItems: nullptr,
    nItems: v5,
    nChunkSize: 1,
    nMaxParallel: 0x7FFFFFFF,
    pThreadPool: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10410C30
// Name: DT_AnimTimeMustBeFirst::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_AnimTimeMustBeFirst::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_AnimTimeMustBeFirst::g_RecvTable);
  return atexit(func: DT_AnimTimeMustBeFirst::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10410C50
// Name: DT_AnimTimeMustBeFirst::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_AnimTimeMustBeFirst::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_AnimTimeMustBeFirst::ignored>();
  DT_AnimTimeMustBeFirst::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410C90
// Name: DT_BaseEntity::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseEntity::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseEntity::g_RecvTable);
  return atexit(func: DT_BaseEntity::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10410CB0
// Name: DT_BaseEntity::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseEntity::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BaseEntity::ignored>();
  DT_BaseEntity::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410CC0
// Name: C_BaseEntity_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *C_BaseEntity_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  datamap_t *result; // eax

  result = PredMapInit<C_BaseEntity>();
  C_BaseEntity_PredDataDescInit::g_PredMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410E90
// Name: C_BaseEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *C_BaseEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<C_BaseEntity>();
  C_BaseEntity_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C4D0
// Name: _dynamic_initializer_for__Command_Playgamesound__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__Command_Playgamesound__()
{
  ConCommand::ConCommand(
    this: &Command_Playgamesound,
    pName: "playgamesound",
    callback: (void (__cdecl *)())Playgamesound_f,
    pHelpString: "Play a sound from the game sounds txt file",
    flags: 1342177280,
    completionFunc: GamesoundCompletion);
  return atexit(func: dynamic_atexit_destructor_for__Command_Playgamesound__);
}

//------------------------------------------------------------------------------
// Address: 0x1042FC30
// Name: DT_AnimTimeMustBeFirst::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_AnimTimeMustBeFirst::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_AnimTimeMustBeFirst::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1042FC40
// Name: DT_BaseEntity::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseEntity::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseEntity::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10433A60
// Name: _dynamic_atexit_destructor_for__Command_Playgamesound__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Command_Playgamesound__()
{
  ConCommand::~ConCommand(this: &Command_Playgamesound);
}

//------------------------------------------------------------------------------
// Address: 0x100429B0
// Name: struct datamap_t __near * DataMapInit<class C_BaseEntity>(class C_BaseEntity __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<C_BaseEntity>()
{
  if ( (_S8_2 & 1) == 0 )
  {
    _S8_2 |= 1u;
    nameHolder_2.m_pszBase = "C_BaseEntity";
    nameHolder_2.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_2.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_2.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_2.m_Names.m_Size = 0;
    nameHolder_2.m_Names.m_pElements = nullptr;
    nameHolder_2.m_nLenBase = 12;
    atexit(func: DataMapInit_C_BaseEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  C_BaseEntity::m_DataMap.baseMap = nullptr;
  C_BaseEntity::m_DataMap.dataNumFields = 5;
  C_BaseEntity::m_DataMap.dataDesc = &dataDesc_2[1];
  return &C_BaseEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10044BA0
// Name: _C_BaseEntity_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BaseEntity_CreateObject(int entnum, int serialNum)
{
  unsigned __int8 *v2; // esi
  C_BaseEntity *v3; // esi

  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 2432);
  memset(dst: v2, value: 0, count: 0x980u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_BaseEntity::C_BaseEntity(this: (C_BaseEntity *)v2);
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v3->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10410C60
// Name: _dynamic_initializer_for__g_C_BaseEntity_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_C_BaseEntity_ScriptDesc__()
{
  InitC_BaseEntityScriptDesc();
  g_C_BaseEntity_ScriptDesc.m_pNextDesc = (ScriptClassDesc_t *)`ScriptClassDesc_t::GetDescList'::`2'::pHead;
  `ScriptClassDesc_t::GetDescList'::`2'::pHead = (int)&g_C_BaseEntity_ScriptDesc;
  return atexit(func: dynamic_atexit_destructor_for__g_C_BaseEntity_ScriptDesc__);
}

//------------------------------------------------------------------------------
// Address: 0x10410CD0
// Name: _dynamic_initializer_for__cl_updatevisibility_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_updatevisibility_command__()
{
  ConCommand::ConCommand(
    this: &cl_updatevisibility_command,
    pName: "cl_updatevisibility",
    callback: (void (__cdecl *)())BuildingCubemapsChanged,
    pHelpString: "Updates visibility bits.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_updatevisibility_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10410D00
// Name: _dynamic_initializer_for__g_AimEntsList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AimEntsList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_AimEntsList__);
}

//------------------------------------------------------------------------------
// Address: 0x10410D10
// Name: _dynamic_initializer_for__cl_simulationtimefix__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_simulationtimefix__()
{
  ConVar::ConVar(this: &cl_simulationtimefix, pName: "cl_simulationtimefix", pDefaultValue: "1", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__cl_simulationtimefix__);
}

//------------------------------------------------------------------------------
// Address: 0x10410D40
// Name: _dynamic_initializer_for__hermite__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hermite__()
{
  ConVar::ConVar(
    this: &hermite,
    pName: "hermite_fix",
    pDefaultValue: "1",
    flags: 2,
    pHelpString: "Don't interpolate previous hermite sample when fixing up times.");
  return atexit(func: dynamic_atexit_destructor_for__hermite__);
}

//------------------------------------------------------------------------------
// Address: 0x10410D70
// Name: _dynamic_initializer_for__cl_interpolate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_interpolate__()
{
  ConVar::ConVar(this: &cl_interpolate, pName: "cl_interpolate", pDefaultValue: "1.0f", flags: 514);
  return atexit(func: dynamic_atexit_destructor_for__cl_interpolate__);
}

//------------------------------------------------------------------------------
// Address: 0x10410DA0
// Name: _dynamic_initializer_for__dlight_debug_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dlight_debug_command__()
{
  ConCommand::ConCommand(
    this: &dlight_debug_command,
    pName: "dlight_debug",
    callback: dlight_debug,
    pHelpString: "Creates a dlight in front of the player",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__dlight_debug_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10410DD0
// Name: _dynamic_initializer_for__cl_removedecals__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_removedecals__()
{
  ConCommand::ConCommand(
    this: &cl_removedecals,
    pName: "cl_removedecals",
    callback: RemoveDecals_f,
    pHelpString: "Remove the decals from the entity under the crosshair.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_removedecals__);
}

//------------------------------------------------------------------------------
// Address: 0x10410E00
// Name: _dynamic_initializer_for__cl_ent_bbox_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_ent_bbox_command__()
{
  ConCommand::ConCommand(
    this: &cl_ent_bbox_command,
    pName: "cl_ent_bbox",
    callback: (void (__cdecl *)())cl_ent_bbox,
    pHelpString: "Displays the client's bounding box for the entity under the crosshair.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_ent_bbox_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10410E30
// Name: _dynamic_initializer_for__cl_ent_absbox_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_ent_absbox_command__()
{
  ConCommand::ConCommand(
    this: &cl_ent_absbox_command,
    pName: "cl_ent_absbox",
    callback: (void (__cdecl *)())cl_ent_absbox,
    pHelpString: "Displays the client's absbox for the entity under the crosshair.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_ent_absbox_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10410E60
// Name: _dynamic_initializer_for__cl_ent_rbox_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_ent_rbox_command__()
{
  ConCommand::ConCommand(
    this: &cl_ent_rbox_command,
    pName: "cl_ent_rbox",
    callback: (void (__cdecl *)())cl_ent_rbox,
    pHelpString: "Displays the client's render box for the entity under the crosshair.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_ent_rbox_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10410EA0
// Name: _dynamic_initializer_for__s_SimulateEntitiesCallQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_SimulateEntitiesCallQueue__()
{
  CTSQueue<CFunctor *,0,1>::CTSQueue<CFunctor *,0,1>(this: &s_SimulateEntitiesCallQueue.m_queue);
  s_SimulateEntitiesCallQueue.m_bNoQueue = false;
  return atexit(func: dynamic_atexit_destructor_for__s_SimulateEntitiesCallQueue__);
}

//------------------------------------------------------------------------------
// Address: 0x10410EC0
// Name: _dynamic_initializer_for__cl_find_ent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_find_ent__()
{
  ConCommand::ConCommand(
    this: &cl_find_ent,
    pName: "cl_find_ent",
    callback: (void (__cdecl *)())CC_CL_Find_Ent,
    pHelpString: "Find and list all client entities with classnames that contain the specified substring.\n"
    "Format: cl_find_ent <substring>\n",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_find_ent__);
}

//------------------------------------------------------------------------------
// Address: 0x10410EF0
// Name: _dynamic_initializer_for__cl_find_ent_index__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_find_ent_index__()
{
  ConCommand::ConCommand(
    this: &cl_find_ent_index,
    pName: "cl_find_ent_index",
    callback: (void (__cdecl *)())CC_CL_Find_Ent_Index,
    pHelpString: "Display data for clientside entity matching specified index.\nFormat: cl_find_ent_index <index>\n",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_find_ent_index__);
}

//------------------------------------------------------------------------------
// Address: 0x10410F20
// Name: _dynamic_initializer_for__g_CV_PhonemeDelay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CV_PhonemeDelay__()
{
  ConVar::ConVar(
    this: &g_CV_PhonemeDelay,
    pName: "phonemedelay",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Phoneme delay to account for sound system latency.");
  return atexit(func: dynamic_atexit_destructor_for__g_CV_PhonemeDelay__);
}

//------------------------------------------------------------------------------
// Address: 0x10410F50
// Name: _dynamic_initializer_for__g_CV_PhonemeFilter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CV_PhonemeFilter__()
{
  ConVar::ConVar(
    this: &g_CV_PhonemeFilter,
    pName: "phonemefilter",
    pDefaultValue: "0.08",
    flags: 0,
    pHelpString: "Time duration of box filter to pass over phonemes.");
  return atexit(func: dynamic_atexit_destructor_for__g_CV_PhonemeFilter__);
}

//------------------------------------------------------------------------------
// Address: 0x10410F80
// Name: _dynamic_initializer_for__g_CV_FlexRules__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CV_FlexRules__()
{
  ConVar::ConVar(
    this: &g_CV_FlexRules,
    pName: "flex_rules",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Allow flex animation rules to run.");
  return atexit(func: dynamic_atexit_destructor_for__g_CV_FlexRules__);
}

//------------------------------------------------------------------------------
// Address: 0x10410FB0
// Name: _dynamic_initializer_for__g_CV_BlinkDuration__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CV_BlinkDuration__()
{
  ConVar::ConVar(
    this: &g_CV_BlinkDuration,
    pName: "blink_duration",
    pDefaultValue: "0.2",
    flags: 0,
    pHelpString: "How many seconds an eye blink will last.");
  return atexit(func: dynamic_atexit_destructor_for__g_CV_BlinkDuration__);
}

//------------------------------------------------------------------------------
// Address: 0x10410FE0
// Name: _dynamic_initializer_for__g_CV_FlexSmooth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CV_FlexSmooth__()
{
  ConVar::ConVar(
    this: &g_CV_FlexSmooth,
    pName: "flex_smooth",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Applies smoothing/decay curve to flex animation controller changes.");
  return atexit(func: dynamic_atexit_destructor_for__g_CV_FlexSmooth__);
}

//------------------------------------------------------------------------------
// Address: 0x10411010
// Name: _dynamic_initializer_for____g_C_BaseFlexClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BaseFlexClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BaseFlexClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BaseFlexClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C500
// Name: _dynamic_initializer_for__SND_PlaySounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__SND_PlaySounds__()
{
  ConCommand::ConCommand(
    this: &SND_PlaySounds,
    pName: "snd_playsounds",
    callback: (void (__cdecl *)())S_PlaySounds,
    pHelpString: "Play sounds from the game sounds txt file at a given location",
    flags: 1342177280,
    completionFunc: GamesoundCompletion2);
  return atexit(func: dynamic_atexit_destructor_for__SND_PlaySounds__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C530
// Name: _dynamic_initializer_for__SND_SetSoundParam__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__SND_SetSoundParam__()
{
  ConCommand::ConCommand(
    this: &SND_SetSoundParam,
    pName: "snd_setsoundparam",
    callback: (void (__cdecl *)())S_SetSoundParam,
    pHelpString: "Set a sound paramater",
    flags: 1342177280,
    completionFunc: GamesoundCompletion3);
  return atexit(func: dynamic_atexit_destructor_for__SND_SetSoundParam__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C560
// Name: _dynamic_initializer_for__soundpatch_captionlength__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__soundpatch_captionlength__()
{
  ConVar::ConVar(
    this: &soundpatch_captionlength,
    pName: "soundpatch_captionlength",
    pDefaultValue: "2.0",
    flags: 0x2000,
    pHelpString: "How long looping soundpatch captions should display for.");
  return atexit(func: dynamic_atexit_destructor_for__soundpatch_captionlength__);
}

//------------------------------------------------------------------------------
// Address: 0x1042FC50
// Name: _dynamic_atexit_destructor_for__cl_updatevisibility_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_updatevisibility_command__()
{
  ConCommand::~ConCommand(this: &cl_updatevisibility_command);
}

//------------------------------------------------------------------------------
// Address: 0x1042FC60
// Name: _dynamic_atexit_destructor_for__cl_simulationtimefix__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_simulationtimefix__()
{
  ConVar::~ConVar(this: &cl_simulationtimefix);
}

//------------------------------------------------------------------------------
// Address: 0x1042FC70
// Name: _dynamic_atexit_destructor_for__hermite__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hermite__()
{
  ConVar::~ConVar(this: &hermite);
}

//------------------------------------------------------------------------------
// Address: 0x1042FC80
// Name: _dynamic_atexit_destructor_for__cl_interpolate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_interpolate__()
{
  ConVar::~ConVar(this: &cl_interpolate);
}

//------------------------------------------------------------------------------
// Address: 0x1042FC90
// Name: _dynamic_atexit_destructor_for__dlight_debug_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dlight_debug_command__()
{
  ConCommand::~ConCommand(this: &dlight_debug_command);
}

//------------------------------------------------------------------------------
// Address: 0x1042FCA0
// Name: _dynamic_atexit_destructor_for__cl_removedecals__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_removedecals__()
{
  ConCommand::~ConCommand(this: &cl_removedecals);
}

//------------------------------------------------------------------------------
// Address: 0x1042FCB0
// Name: _dynamic_atexit_destructor_for__cl_ent_bbox_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_ent_bbox_command__()
{
  ConCommand::~ConCommand(this: &cl_ent_bbox_command);
}

//------------------------------------------------------------------------------
// Address: 0x1042FCC0
// Name: _dynamic_atexit_destructor_for__cl_ent_absbox_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_ent_absbox_command__()
{
  ConCommand::~ConCommand(this: &cl_ent_absbox_command);
}

//------------------------------------------------------------------------------
// Address: 0x1042FCD0
// Name: _dynamic_atexit_destructor_for__cl_ent_rbox_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_ent_rbox_command__()
{
  ConCommand::~ConCommand(this: &cl_ent_rbox_command);
}

//------------------------------------------------------------------------------
// Address: 0x1042FCE0
// Name: _dynamic_atexit_destructor_for__cl_find_ent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_find_ent__()
{
  ConCommand::~ConCommand(this: &cl_find_ent);
}

//------------------------------------------------------------------------------
// Address: 0x1042FCF0
// Name: _dynamic_atexit_destructor_for__cl_find_ent_index__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_find_ent_index__()
{
  ConCommand::~ConCommand(this: &cl_find_ent_index);
}

//------------------------------------------------------------------------------
// Address: 0x1042FD00
// Name: _dynamic_atexit_destructor_for__g_AimEntsList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AimEntsList__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_AimEntsList);
}

//------------------------------------------------------------------------------
// Address: 0x1042FD10
// Name: _DataMapInit_C_BaseEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_C_BaseEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_2);
}

//------------------------------------------------------------------------------
// Address: 0x1042FD20
// Name: _dynamic_atexit_destructor_for__g_EntityLists__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EntityLists__()
{
  CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *v0; // esi
  int i; // ebx

  v0 = (CUtlLinkedList<C_BaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseCombatWeapon *,unsigned short>,unsigned short> > *)&g_Predictables;
  for ( i = 4; i >= 0; --i )
  {
    CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: --v0);
    if ( v0->m_Memory.m_nGrowSize >= 0 )
    {
      if ( v0->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v0->m_Memory.m_pMemory);
        v0->m_Memory.m_pMemory = nullptr;
      }
      v0->m_Memory.m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042FD70
// Name: _dynamic_atexit_destructor_for__g_RecordingList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RecordingList__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_RecordingList.m_Recording);
  g_RecordingList.__vftable = (CRecordingList_vtbl *)&IRecordingList::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1042FD90
// Name: _dynamic_atexit_destructor_for__g_Predictables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Predictables__()
{
  C_BaseEntity **m_pMemory; // eax

  m_pMemory = g_Predictables.m_Memory.m_pMemory;
  g_Predictables.m_Size = 0;
  if ( g_Predictables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_Predictables.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_Predictables.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_Predictables.m_Memory.m_pMemory = nullptr;
    }
    g_Predictables.m_Memory.m_nAllocationCount = 0;
  }
  g_Predictables.m_pElements = m_pMemory;
  if ( g_Predictables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      g_Predictables.m_Memory.m_pMemory = nullptr;
    }
    g_Predictables.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042FE00
// Name: _dynamic_atexit_destructor_for__s_SimulateEntitiesCallQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_SimulateEntitiesCallQueue__()
{
  CTSQueue<CFunctor *,0,1>::Purge(this: &s_SimulateEntitiesCallQueue.m_queue);
  C_BaseEntity::operator delete(pMem: s_SimulateEntitiesCallQueue.m_queue.m_Head.value.pNode);
  CTSListBase::Detach(this: &s_SimulateEntitiesCallQueue.m_queue.m_FreeNodes);
}

//------------------------------------------------------------------------------
// Address: 0x1042FE30
// Name: _dynamic_atexit_destructor_for__g_C_BaseEntity_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_C_BaseEntity_ScriptDesc__()
{
  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::~CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>(this: &g_C_BaseEntity_ScriptDesc.m_FunctionBindings);
}

//------------------------------------------------------------------------------
// Address: 0x1042FE40
// Name: _dynamic_atexit_destructor_for__g_CV_PhonemeDelay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CV_PhonemeDelay__()
{
  ConVar::~ConVar(this: &g_CV_PhonemeDelay);
}

//------------------------------------------------------------------------------
// Address: 0x1042FE50
// Name: _dynamic_atexit_destructor_for__g_CV_PhonemeFilter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CV_PhonemeFilter__()
{
  ConVar::~ConVar(this: &g_CV_PhonemeFilter);
}

//------------------------------------------------------------------------------
// Address: 0x1042FE60
// Name: _dynamic_atexit_destructor_for__g_CV_FlexRules__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CV_FlexRules__()
{
  ConVar::~ConVar(this: &g_CV_FlexRules);
}

//------------------------------------------------------------------------------
// Address: 0x1042FE70
// Name: _dynamic_atexit_destructor_for__g_CV_BlinkDuration__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CV_BlinkDuration__()
{
  ConVar::~ConVar(this: &g_CV_BlinkDuration);
}

//------------------------------------------------------------------------------
// Address: 0x1042FE80
// Name: _dynamic_atexit_destructor_for__g_CV_FlexSmooth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CV_FlexSmooth__()
{
  ConVar::~ConVar(this: &g_CV_FlexSmooth);
}

//------------------------------------------------------------------------------
// Address: 0x10433A70
// Name: _dynamic_atexit_destructor_for__SND_PlaySounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__SND_PlaySounds__()
{
  ConCommand::~ConCommand(this: &SND_PlaySounds);
}

//------------------------------------------------------------------------------
// Address: 0x10433A80
// Name: _dynamic_atexit_destructor_for__SND_SetSoundParam__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__SND_SetSoundParam__()
{
  ConCommand::~ConCommand(this: &SND_SetSoundParam);
}

//------------------------------------------------------------------------------
// Address: 0x10433A90
// Name: _dynamic_atexit_destructor_for__soundpatch_captionlength__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__soundpatch_captionlength__()
{
  ConVar::~ConVar(this: &soundpatch_captionlength);
}

//------------------------------------------------------------------------------
// Address: 0x10433AA0
// Name: _dynamic_atexit_destructor_for__cl_report_soundpatch_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_report_soundpatch_command__()
{
  ConCommand::~ConCommand(this: &cl_report_soundpatch_command);
}
