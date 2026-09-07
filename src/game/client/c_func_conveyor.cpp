// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_func_conveyor.cpp
// Functions: 11
// ============================================================

#include "game\client\c_func_conveyor.h"

//------------------------------------------------------------------------------
// Address: 0x1006F380
// Name: public: virtual class ClientClass __near * C_FuncConveyor::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_FuncConveyor::GetClientClass(C_FuncConveyor *this)
{
  return &__g_C_FuncConveyorClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1006F420
// Name: public: virtual bool CConveyorMaterialProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CConveyorMaterialProxy::Init(CConveyorMaterialProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  const char *String; // eax
  IMaterialVar *v6; // eax
  bool v7; // zf

  String = KeyValues::GetString(this: pKeyValues, keyName: "textureScrollVar", defaultValue: prType);
  if ( String == nullptr )
    return false;
  v6 = pMaterial->FindVar(this: pMaterial, a2: String, a3: (char *)&pKeyValues + 3, a4: 0);
  v7 = HIBYTE(pKeyValues) == 0;
  this->m_pTextureScrollVar = v6;
  return !v7;
}

//------------------------------------------------------------------------------
// Address: 0x1006F470
// Name: public: virtual class IMaterial __near * CConveyorMaterialProxy::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CConveyorMaterialProxy::GetMaterial(CConveyorMaterialProxy *this)
{
  if ( this->m_pTextureScrollVar != nullptr )
    return this->m_pTextureScrollVar->GetOwningMaterial(this: this->m_pTextureScrollVar);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006F500
// Name: public: virtual void CConveyorMaterialProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConveyorMaterialProxy::OnBind(CConveyorMaterialProxy *this, int (__thiscall ***pC_BaseEntity)(_DWORD))
{
  int v3; // eax
  void *v4; // eax
  float *v5; // eax
  IMaterialVar *m_pTextureScrollVar; // esi
  float v7; // xmm1_4
  int v8; // eax
  float v9; // xmm1_4
  __m128 v10; // xmm0
  __m128i v11; // xmm0
  double v12; // xmm0_8
  double v13; // xmm0_8
  float v14; // xmm1_4
  float v15; // xmm0_4
  float x; // [esp+0h] [ebp-64h]
  float y; // [esp+4h] [ebp-60h]
  VMatrix mat; // [esp+14h] [ebp-50h] BYREF
  unsigned __int64 v19; // [esp+54h] [ebp-10h]
  float sOffset; // [esp+5Ch] [ebp-8h]
  float flRate; // [esp+60h] [ebp-4h]
  float pC_BaseEntitya; // [esp+6Ch] [ebp+8h]

  if ( pC_BaseEntity != nullptr )
  {
    v3 = (**pC_BaseEntity)(a1: pC_BaseEntity);
    v4 = (void *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 28))(a1: v3);
    if ( v4 != nullptr )
    {
      v5 = (float *)__RTDynamicCast(
                      inptr: v4,
                      VfDelta: 0,
                      SrcType: &C_BaseEntity `RTTI Type Descriptor',
                      TargetType: &C_FuncConveyor `RTTI Type Descriptor',
                      isReference: 0);
      if ( v5 != nullptr )
      {
        m_pTextureScrollVar = this->m_pTextureScrollVar;
        if ( m_pTextureScrollVar != nullptr )
        {
          v7 = v5[608];
          flRate = fabs(v7) * 0.0078125;
          if ( v7 < 0.0 )
            v8 = 0;
          else
            v8 = 180;
          v9 = *(float *)(gpGlobals.m_Index + 12);
          v10 = 0;
          v10.m128_f32[0] = (float)v8;
          v11 = (__m128i)_mm_cvtps_pd(v10);
          *(double *)v11.m128i_i64 = *(double *)v11.m128i_i64 * 0.0174532925199433;
          v19 = v11.m128i_i64[0];
          pC_BaseEntitya = v9;
          __libm_sse2_cos(X: v11);
          *(float *)&v12 = v12 * v9 * flRate;
          sOffset = *(float *)&v12;
          __libm_sse2_sin(X: (__m128i)v19);
          v14 = sOffset;
          v15 = v13 * pC_BaseEntitya * flRate;
          if ( sOffset < 0.0 )
            v14 = sOffset + (float)(1.0 - (float)(int)sOffset);
          if ( v15 < 0.0 )
            v15 = v15 + (float)(1.0 - (float)(int)v15);
          y = v15 - (float)(int)v15;
          x = v14 - (float)(int)v14;
          if ( (*((_BYTE *)m_pTextureScrollVar + 28) & 0xF) == 7 )
          {
            MatrixBuildTranslation(dst: &mat, x, y, z: 0.0);
            this->m_pTextureScrollVar->SetMatrixValue(this: this->m_pTextureScrollVar, a2: &mat);
          }
          else
          {
            ((void (__thiscall *)(IMaterialVar *, float, float, _DWORD))m_pTextureScrollVar->SetVecValue_2)(
              a1: m_pTextureScrollVar,
              a2: COERCE_FLOAT(LODWORD(x)),
              a3: COERCE_FLOAT(LODWORD(y)),
              a4: 0);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006F6B0
// Name: CCConveyorMaterialProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCConveyorMaterialProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CConveyorMaterialProxy::`vftable';
  result[1].__vftable = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104120B0
// Name: DT_FuncConveyor::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncConveyor::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_FuncConveyor::g_RecvTable);
  return atexit(func: DT_FuncConveyor::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104120D0
// Name: DT_FuncConveyor::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncConveyor::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_FuncConveyor::ignored>();
  DT_FuncConveyor::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104302E0
// Name: DT_FuncConveyor::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncConveyor::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_FuncConveyor::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1006F490
// Name: _C_FuncConveyor_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_FuncConveyor_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x988u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_FuncConveyor::`vftable'{for `IClientUnknown'};
  v3[1] = &C_FuncConveyor::`vftable'{for `IClientRenderable'};
  v3[2] = &C_FuncConveyor::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_FuncConveyor::`vftable'{for `IClientThinkable'};
  v3[4] = &C_FuncConveyor::`vftable';
  v3[608] = 0;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x104120E0
// Name: _dynamic_initializer_for__g_CConveyorScrollFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CConveyorScrollFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "ConveyorScroll",
           a3: CCConveyorMaterialProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10412100
// Name: _dynamic_initializer_for____g_C_Func_DustClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_Func_DustClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_Func_DustClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_Func_DustClientClass;
  return result;
}
