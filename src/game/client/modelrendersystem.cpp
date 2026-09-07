// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/modelrendersystem.cpp
// Functions: 62
// ============================================================

#include "game\client\modelrendersystem.h"

//------------------------------------------------------------------------------
// Address: 0x100C79C0
// Name: void std::_Push_heap<struct CDetailObjectSystem::SortInfo_t __near *,int,struct CDetailObjectSystem::SortInfo_t,bool (*)(struct CDetailObjectSystem::SortInfo_t const __near &,struct CDetailObjectSystem::SortInfo_t const __near &)>(struct CDetailObjectSystem::SortInfo_t __near *,int,int,struct CDetailObjectSystem::SortInfo_t __near &&,bool (*)(struct CDetailObjectSystem::SortInfo_t const __near &,struct CDetailObjectSystem::SortInfo_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<CDetailObjectSystem::SortInfo_t *,int,CDetailObjectSystem::SortInfo_t,bool (__cdecl *)(CDetailObjectSystem::SortInfo_t const &,CDetailObjectSystem::SortInfo_t const &)>(
        CDetailObjectSystem::SortInfo_t *_First,
        int _Hole,
        int _Top,
        CDetailObjectSystem::SortInfo_t *_Val,
        bool (__cdecl *_Pred)(const CDetailObjectSystem::SortInfo_t *, const CDetailObjectSystem::SortInfo_t *))
{
  int v5; // edi
  int i; // esi
  const CDetailObjectSystem::SortInfo_t *v7; // ebx

  v5 = _Hole;
  for ( i = (_Hole - 1) / 2; _Top < v5; i = (i - 1) / 2 )
  {
    v7 = &_First[i];
    if ( !_Pred(a1: v7, a2: _Val) )
      break;
    _First[v5] = *v7;
    v5 = i;
  }
  _First[v5] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x100C8040
// Name: void std::_Adjust_heap<struct CDetailObjectSystem::SortInfo_t __near *,int,struct CDetailObjectSystem::SortInfo_t,bool (*)(struct CDetailObjectSystem::SortInfo_t const __near &,struct CDetailObjectSystem::SortInfo_t const __near &)>(struct CDetailObjectSystem::SortInfo_t __near *,int,int,struct CDetailObjectSystem::SortInfo_t __near &&,bool (*)(struct CDetailObjectSystem::SortInfo_t const __near &,struct CDetailObjectSystem::SortInfo_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<CDetailObjectSystem::SortInfo_t *,int,CDetailObjectSystem::SortInfo_t,bool (__cdecl *)(CDetailObjectSystem::SortInfo_t const &,CDetailObjectSystem::SortInfo_t const &)>(
        CDetailObjectSystem::SortInfo_t *_First,
        int _Hole,
        int _Bottom,
        CDetailObjectSystem::SortInfo_t *_Val,
        bool (__cdecl *_Pred)(const CDetailObjectSystem::SortInfo_t *, const CDetailObjectSystem::SortInfo_t *))
{
  int v5; // eax
  int v6; // ebx
  int v7; // edi
  bool v8; // zf
  int i; // edi

  v5 = _Bottom;
  v6 = _Hole;
  v7 = 2 * _Hole + 2;
  v8 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      if ( _Pred(a1: &_First[v7], a2: &_First[v7 - 1]) )
        --v7;
      _First[v6] = _First[v7];
      v6 = v7;
      v7 = 2 * v7 + 2;
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v8 = v7 == _Bottom;
  }
  if ( v8 )
  {
    _First[v6] = _First[v5 - 1];
    v6 = v5 - 1;
  }
  for ( i = (v6 - 1) / 2; _Hole < v6; i = (i - 1) / 2 )
  {
    if ( !_Pred(a1: &_First[i], a2: _Val) )
      break;
    _First[v6] = _First[i];
    v6 = i;
  }
  _First[v6] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x100C8E50
// Name: void std::_Make_heap<struct CDetailObjectSystem::SortInfo_t __near *,int,struct CDetailObjectSystem::SortInfo_t,bool (*)(struct CDetailObjectSystem::SortInfo_t const __near &,struct CDetailObjectSystem::SortInfo_t const __near &)>(struct CDetailObjectSystem::SortInfo_t __near *,struct CDetailObjectSystem::SortInfo_t __near *,bool (*)(struct CDetailObjectSystem::SortInfo_t const __near &,struct CDetailObjectSystem::SortInfo_t const __near &),int __near *,struct CDetailObjectSystem::SortInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<CDetailObjectSystem::SortInfo_t *,int,CDetailObjectSystem::SortInfo_t,bool (__cdecl *)(CDetailObjectSystem::SortInfo_t const &,CDetailObjectSystem::SortInfo_t const &)>(
        CDetailObjectSystem::SortInfo_t *_First,
        CDetailObjectSystem::SortInfo_t *_Last,
        bool (__cdecl *_Pred)(const CDetailObjectSystem::SortInfo_t *, const CDetailObjectSystem::SortInfo_t *))
{
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  CDetailObjectSystem::SortInfo_t *i; // edx
  int v8; // ebx
  int v9; // eax
  int v10; // esi
  float m_flDistance; // edx
  int v12; // ebx
  bool v13; // zf
  CDetailObjectSystem::SortInfo_t _Val; // [esp+4h] [ebp-10h] BYREF
  int v15; // [esp+Ch] [ebp-8h]
  CDetailObjectSystem::SortInfo_t *v16; // [esp+10h] [ebp-4h]
  int _Hole; // [esp+1Ch] [ebp+8h]
  int _Bottom; // [esp+20h] [ebp+Ch]

  v4 = _Last - _First;
  v5 = v4 / 2;
  _Bottom = v4;
  if ( v4 / 2 > 0 )
  {
    v6 = 2 * v5 + 2;
    for ( i = &_First[v5]; ; i = v16 )
    {
      v8 = (int)i[-1];
      v9 = v5 - 1;
      v10 = v6 - 2;
      v16 = i - 1;
      m_flDistance = i[-1].m_flDistance;
      *(_DWORD *)&_Val = v8;
      _Hole = v9;
      v15 = v10;
      _Val.m_flDistance = m_flDistance;
      v12 = v9;
      v13 = v10 == v4;
      if ( v10 < v4 )
      {
        do
        {
          if ( _Pred(a1: &_First[v10], a2: &_First[v10 - 1]) )
            --v10;
          *(_DWORD *)&_First[v12] = _First[v10];
          _First[v12].m_flDistance = _First[v10].m_flDistance;
          v12 = v10;
          v10 = 2 * v10 + 2;
        }
        while ( v10 < _Bottom );
        v4 = _Bottom;
        v9 = _Hole;
        v13 = v10 == _Bottom;
      }
      if ( v13 )
      {
        *(_DWORD *)&_First[v12] = _First[v4 - 1];
        _First[v12].m_flDistance = _First[v4 - 1].m_flDistance;
        v12 = v4 - 1;
      }
      std::_Push_heap<CDetailObjectSystem::SortInfo_t *,int,CDetailObjectSystem::SortInfo_t,bool (__cdecl *)(CDetailObjectSystem::SortInfo_t const &,CDetailObjectSystem::SortInfo_t const &)>(
        _First,
        _Hole: v12,
        _Top: v9,
        &_Val,
        _Pred);
      if ( _Hole <= 0 )
        break;
      v5 = _Hole;
      v4 = _Bottom;
      v6 = v15;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA7F0
// Name: void std::_Sort_heap<struct CDetailObjectSystem::SortInfo_t __near *,bool (*)(struct CDetailObjectSystem::SortInfo_t const __near &,struct CDetailObjectSystem::SortInfo_t const __near &)>(struct CDetailObjectSystem::SortInfo_t __near *,struct CDetailObjectSystem::SortInfo_t __near *,bool (*)(struct CDetailObjectSystem::SortInfo_t const __near &,struct CDetailObjectSystem::SortInfo_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<CDetailObjectSystem::SortInfo_t *,bool (__cdecl *)(CDetailObjectSystem::SortInfo_t const &,CDetailObjectSystem::SortInfo_t const &)>(
        CDetailObjectSystem::SortInfo_t *_First,
        CDetailObjectSystem::SortInfo_t *_Last,
        bool (__cdecl *_Pred)(const CDetailObjectSystem::SortInfo_t *, const CDetailObjectSystem::SortInfo_t *))
{
  int v3; // eax
  CDetailObjectSystem::SortInfo_t *v4; // esi
  float m_flDistance; // edx
  CDetailObjectSystem::SortInfo_t _Val; // [esp+4h] [ebp-8h] BYREF

  v3 = (char *)_Last - (char *)_First;
  if ( (int)(((char *)_Last - (char *)_First) & 0xFFFFFFF8) > 8 )
  {
    v4 = _Last - 1;
    do
    {
      m_flDistance = v4->m_flDistance;
      *(_DWORD *)&_Val = *(_DWORD *)v4;
      *(_DWORD *)v4 = *(_DWORD *)_First;
      _Val.m_flDistance = m_flDistance;
      v4->m_flDistance = _First->m_flDistance;
      std::_Adjust_heap<CDetailObjectSystem::SortInfo_t *,int,CDetailObjectSystem::SortInfo_t,bool (__cdecl *)(CDetailObjectSystem::SortInfo_t const &,CDetailObjectSystem::SortInfo_t const &)>(
        _First,
        _Hole: 0,
        _Bottom: (v3 - 8) >> 3,
        &_Val,
        _Pred);
      v3 = (char *)--v4 - (char *)_First + 8;
    }
    while ( (int)(v3 & 0xFFFFFFF8) > 8 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10121E80
// Name: public: virtual void CModelRenderSystem::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::LevelInitPostEntity(CModelRenderSystem *this)
{
  CTextureReference::Init(
    this: &this->m_DefaultCubemap,
    pTextureName: "engine/defaultcubemap",
    pTextureGroupName: "CubeMap textures",
    bComplain: true,
    nAdditionalCreationFlags: 0);
  CMaterialReference::Init(
    this: &this->m_DebugMaterial,
    pMaterialName: "debug/debugempty",
    pTextureGroupName: "Other textures",
    bComplain: true);
  CMaterialReference::Init(
    this: &this->m_ShadowBuild,
    pMaterialName: "engine/shadowbuild",
    pTextureGroupName: "Other textures",
    bComplain: true);
}

//------------------------------------------------------------------------------
// Address: 0x10121ED0
// Name: public: virtual void CModelRenderSystem::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::LevelShutdownPreEntity(CModelRenderSystem *this)
{
  CTextureReference::Shutdown(this: &this->m_DefaultCubemap, bDeleteIfUnReferenced: false);
  CMaterialReference::Shutdown(this: &this->m_DebugMaterial, bDeleteIfUnreferenced: false);
  CMaterialReference::Shutdown(this: &this->m_ShadowBuild, bDeleteIfUnreferenced: false);
}

//------------------------------------------------------------------------------
// Address: 0x10121F00
// Name: private: static bool CModelRenderSystem::DependencySortLessFunc(struct CModelRenderSystem::ModelListByType_t const __near &,struct CModelRenderSystem::ModelListByType_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CModelRenderSystem::DependencySortLessFunc(
        const CModelRenderSystem::ModelListByType_t *left,
        const CModelRenderSystem::ModelListByType_t *right)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx
  bool v4; // cf
  unsigned int v5; // edx
  unsigned int v6; // esi

  v2 = *((_DWORD *)left + 9) & 0x7FFFFFFF;
  v3 = *((_DWORD *)right + 9) & 0x7FFFFFFF;
  v4 = v2 < v3;
  if ( v2 == v3 )
  {
    v5 = *((_DWORD *)left + 9) >> 31;
    v6 = *((_DWORD *)right + 9) >> 31;
    v4 = v5 < v6;
    if ( v5 == v6 )
      return left->m_pModel < right->m_pModel;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10121F40
// Name: private: static bool CModelRenderSystem::SortLessFunc(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CModelRenderSystem::SortLessFunc(
        const CModelRenderSystem::RenderModelInfo_t *left,
        const CModelRenderSystem::RenderModelInfo_t *right)
{
  unsigned __int8 v2; // si
  int m_nSkin; // eax
  int v5; // esi

  v2 = *((_BYTE *)left + 91);
  if ( ((v2 ^ *((_BYTE *)right + 91)) & 1) != 0 )
    return (v2 & 1) == 0;
  m_nSkin = left->m_nSkin;
  v5 = right->m_nSkin;
  if ( m_nSkin != v5 )
    return m_nSkin > v5;
  if ( left->m_nLOD == right->m_nLOD )
    return left->m_nBody > right->m_nBody;
  return left->m_nLOD > right->m_nLOD;
}

//------------------------------------------------------------------------------
// Address: 0x10121FA0
// Name: private: int CModelRenderSystem::BuildLightingList(struct CModelRenderSystem::ModelListByType_t __near * __near *,unsigned char __near *,int __near *,struct CModelRenderSystem::LightingList_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelRenderSystem::BuildLightingList(
        CModelRenderSystem *this,
        CModelRenderSystem::ModelListByType_t **ppLists,
        unsigned __int8 *pFlags,
        int *pTotalModels,
        const CModelRenderSystem::LightingList_t *lightingList)
{
  int v5; // edi
  CModelRenderSystem::ModelListByType_t *i; // esi
  bool v7; // bl
  bool v8; // al
  bool bUsesEnvCubemap_3; // [esp+1Fh] [ebp+17h]

  v5 = 0;
  *pTotalModels = 0;
  for ( i = lightingList->m_pFirstModel; i != nullptr; i = i->m_pNextLightingModel )
  {
    v7 = modelinfo->IsModelVertexLit(this: modelinfo, a2: i->m_pModel);
    bUsesEnvCubemap_3 = modelinfo->UsesEnvCubemap(this: modelinfo, a2: i->m_pModel);
    v8 = modelinfo->UsesStaticLighting(this: modelinfo, a2: i->m_pModel);
    if ( v7 || bUsesEnvCubemap_3 || v8 )
    {
      ppLists[v5] = i;
      pFlags[v5] = bUsesEnvCubemap_3 | (2 * (v7 | (2 * v8)));
      *pTotalModels += i->m_nCount;
      ++v5;
    }
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10122040
// Name: private: void CModelRenderSystem::RenderBBoxDebugOverlay(int,struct CModelRenderSystem::ModelListByType_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::RenderBBoxDebugOverlay(
        CModelRenderSystem *this,
        CModelRenderSystem::ModelListByType_t *nModelTypeCount,
        CModelRenderSystem::ModelListByType_t *pModelList)
{
  int *p_m_nCount; // edi
  int v4; // ebx
  int (__thiscall ***v5)(_DWORD); // esi
  int v6; // eax
  C_BaseEntity *v7; // eax
  int nModelTypeCounta; // [esp+8h] [ebp+8h]
  CModelRenderSystem::ModelListByType_t *pModelLista; // [esp+Ch] [ebp+Ch]

  if ( (int)nModelTypeCount > 0 )
  {
    p_m_nCount = &pModelList->m_nCount;
    for ( pModelLista = nModelTypeCount;
          pModelLista != nullptr;
          pModelLista = (CModelRenderSystem::ModelListByType_t *)((char *)pModelLista - 1) )
    {
      v4 = 0;
      if ( *p_m_nCount > 0 )
      {
        nModelTypeCounta = 0;
        do
        {
          v5 = *(int (__thiscall ****)(_DWORD))(p_m_nCount[3] + nModelTypeCounta + 68);
          if ( (**v5)(a1: v5) != 0 )
          {
            v6 = (**v5)(a1: v5);
            v7 = (C_BaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 28))(a1: v6);
            if ( v7 != nullptr )
              C_BaseEntity::DrawBBoxVisualizations(this: v7);
          }
          nModelTypeCounta += 92;
          ++v4;
        }
        while ( v4 < *p_m_nCount );
      }
      p_m_nCount += 12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101220B0
// Name: void std::_Push_heap<struct CModelRenderSystem::ModelListByType_t __near *,int,struct CModelRenderSystem::ModelListByType_t,bool (*)(struct CModelRenderSystem::ModelListByType_t const __near &,struct CModelRenderSystem::ModelListByType_t const __near &)>(struct CModelRenderSystem::ModelListByType_t __near *,int,int,struct CModelRenderSystem::ModelListByType_t __near &&,bool (*)(struct CModelRenderSystem::ModelListByType_t const __near &,struct CModelRenderSystem::ModelListByType_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<CModelRenderSystem::ModelListByType_t *,int,CModelRenderSystem::ModelListByType_t,bool (__cdecl *)(CModelRenderSystem::ModelListByType_t const &,CModelRenderSystem::ModelListByType_t const &)>(
        CModelRenderSystem::ModelListByType_t *_First,
        int _Hole,
        int _Top,
        CModelRenderSystem::ModelListByType_t *_Val,
        bool (__cdecl *_Pred)(const CModelRenderSystem::ModelListByType_t *, const CModelRenderSystem::ModelListByType_t *))
{
  int v5; // ebx
  int i; // edi
  CModelRenderSystem::ModelListByType_t *v7; // esi
  CModelRenderSystem::ModelListByType_t *v8; // eax

  v5 = _Hole;
  for ( i = (_Hole - 1) / 2; _Top < v5; i = (i - 1) / 2 )
  {
    v7 = &_First[i];
    if ( !_Pred(a1: v7, a2: _Val) )
      break;
    v8 = &_First[v5];
    v5 = i;
    v8->StudioModelArrayInfo2_t = v7->StudioModelArrayInfo2_t;
    *(_QWORD *)&v8->m_pStudioHdr = *(_QWORD *)&v7->m_pStudioHdr;
    *(_QWORD *)&v8->m_nLightingModel = *(_QWORD *)&v7->m_nLightingModel;
    *(_QWORD *)&v8->m_pFirstNode = *(_QWORD *)&v7->m_pFirstNode;
    *(_QWORD *)&v8->m_nSetupBoneCount = *(_QWORD *)&v7->m_nSetupBoneCount;
    *(_QWORD *)&v8->m_pRenderModels = *(_QWORD *)&v7->m_pRenderModels;
  }
  _First[v5] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x10122190
// Name: public: int studiohwdata_t::GetLODForMetric(float)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall studiohwdata_t::GetLODForMetric(studiohwdata_t *this, float lodMetric)
{
  int result; // eax
  float m_fValue; // xmm0_4
  studioloddata_t *m_pLODs; // edx
  int m_NumLODs; // ecx
  int v7; // ecx
  float *i; // edx

  if ( (`studiohwdata_t::GetLODForMetric'::`2'::`local static guard' & 1) == 0 )
  {
    `studiohwdata_t::GetLODForMetric'::`2'::`local static guard' |= 1u;
    ConVarRef::ConVarRef(this: &`studiohwdata_t::GetLODForMetric'::`2'::r_lod_switch_scale, pName: "r_lod_switch_scale");
  }
  if ( this->m_NumLODs == 0 )
    return 0;
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&`studiohwdata_t::GetLODForMetric'::`2'::r_lod_switch_scale) )
    m_fValue = `studiohwdata_t::GetLODForMetric'::`2'::r_lod_switch_scale.m_pConVarState->m_Value.m_fValue;
  else
    m_fValue = 1.0;
  m_pLODs = this->m_pLODs;
  m_NumLODs = this->m_NumLODs - 1;
  if ( m_pLODs[this->m_NumLODs - 1].m_SwitchPoint >= 0.0 )
    m_NumLODs = this->m_NumLODs;
  result = this->m_RootLOD;
  v7 = m_NumLODs - 1;
  if ( this->m_RootLOD >= v7 )
    return v7;
  for ( i = &m_pLODs[result + 1].m_SwitchPoint; (float)(*i * m_fValue) <= lodMetric; i += 8 )
  {
    if ( ++result >= v7 )
      return v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10122230
// Name: private: void CModelRenderSystem::SlamModelLODs(int,int,struct CModelRenderSystem::ModelListByType_t __near *,struct CModelRenderSystem::ModelListNode_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::SlamModelLODs(
        CModelRenderSystem *this,
        int nLOD,
        int nModelTypeCount,
        CModelRenderSystem::ModelListByType_t *pModelList,
        CModelRenderSystem::ModelListNode_t *pModelListNode)
{
  int v5; // ebx
  studiohwdata_t **p_m_pHardwareData; // edx
  int m_NumLODs; // ecx
  int m_RootLOD; // edi
  int v9; // esi
  studiohwdata_t *i; // eax
  int v11; // ecx

  if ( nModelTypeCount > 0 )
  {
    v5 = nLOD;
    p_m_pHardwareData = &pModelList->m_pHardwareData;
    do
    {
      m_NumLODs = (*p_m_pHardwareData)->m_NumLODs;
      m_RootLOD = (*p_m_pHardwareData)->m_RootLOD;
      v9 = m_NumLODs - 2;
      if ( ((*(p_m_pHardwareData - 1))[5].m_NumStudioMeshes & 0x40) == 0 )
        v9 = m_NumLODs - 1;
      for ( i = p_m_pHardwareData[3]; i != nullptr; v5 = nLOD )
      {
        if ( v5 >= m_RootLOD )
        {
          v11 = v9;
          if ( v5 <= v9 )
            v11 = v5;
        }
        else
        {
          v11 = m_RootLOD;
        }
        i->m_NumStudioMeshes = (v11 << 25) | i->m_NumStudioMeshes & 0x1FFFFFF;
        i = (studiohwdata_t *)i->m_NumTimesRenderedThisFrame;
      }
      p_m_pHardwareData += 12;
      --nModelTypeCount;
    }
    while ( nModelTypeCount != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101222B0
// Name: private: void CModelRenderSystem::DebugDrawLightingOrigin(struct CModelRenderSystem::ModelListByType_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::DebugDrawLightingOrigin(
        CModelRenderSystem *this,
        const CModelRenderSystem::ModelListByType_t *list,
        const CModelRenderSystem::RenderModelInfo_t *model)
{
  MaterialLightingState_t *m_pLightingState; // esi
  Vector *p_m_vecLightingOrigin; // esi
  const matrix3x4_t *v5; // eax
  float z; // xmm2_4
  const matrix3x4_t *v7; // edi
  float v8; // xmm2_4
  studiohdr_t *m_pStudioHdr; // eax
  studiohdr_t *v10; // eax
  studiohdr_t *v11; // eax
  studiohdr_t *v12; // eax
  studiohdr_t *v13; // eax
  studiohdr_t *v14; // ebx
  Vector pt1; // [esp+10Ch] [ebp-18h] BYREF
  Vector pt0; // [esp+118h] [ebp-Ch] BYREF

  m_pLightingState = model->m_pLightingState;
  if ( m_pLightingState != nullptr )
  {
    p_m_vecLightingOrigin = &m_pLightingState->m_vecLightingOrigin;
    v5 = model->m_Entry.m_pRenderable->RenderableToWorldTransform(this: model->m_Entry.m_pRenderable);
    pt0 = *p_m_vecLightingOrigin;
    pt1.x = p_m_vecLightingOrigin->x;
    pt1.y = p_m_vecLightingOrigin->y;
    z = p_m_vecLightingOrigin->z;
    pt0.x = pt0.x - 4.0;
    v7 = v5;
    pt1.z = z;
    pt1.x = pt1.x + 4.0;
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, _DWORD, int, _DWORD, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: debugoverlay,
      a2: &pt0,
      a3: &pt1,
      a4: 0,
      a5: 255,
      a6: 0,
      a7: 1,
      a8: 0);
    pt0 = *p_m_vecLightingOrigin;
    pt1.x = p_m_vecLightingOrigin->x;
    pt1.y = p_m_vecLightingOrigin->y;
    v8 = p_m_vecLightingOrigin->z;
    pt0.y = pt0.y - 4.0;
    pt1.z = v8;
    pt1.y = pt1.y + 4.0;
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, _DWORD, int, _DWORD, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: debugoverlay,
      a2: &pt0,
      a3: &pt1,
      a4: 0,
      a5: 255,
      a6: 0,
      a7: 1,
      a8: 0);
    pt0 = list->m_pStudioHdr->hull_min;
    VectorTransform(in1: &pt0.x, in2: v7, out: &pt1.x);
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: debugoverlay,
      a2: p_m_vecLightingOrigin,
      a3: &pt1,
      a4: 100,
      a5: 100,
      a6: 150,
      a7: 1,
      a8: 0);
    m_pStudioHdr = list->m_pStudioHdr;
    pt0.x = m_pStudioHdr->hull_min.x;
    pt0.y = m_pStudioHdr->hull_max.y;
    pt0.z = m_pStudioHdr->hull_min.z;
    VectorTransform(in1: &pt0.x, in2: v7, out: &pt1.x);
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: debugoverlay,
      a2: p_m_vecLightingOrigin,
      a3: &pt1,
      a4: 100,
      a5: 100,
      a6: 150,
      a7: 1,
      a8: 0);
    v10 = list->m_pStudioHdr;
    pt0.x = v10->hull_max.x;
    pt0.y = v10->hull_max.y;
    pt0.z = v10->hull_min.z;
    VectorTransform(in1: &pt0.x, in2: v7, out: &pt1.x);
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: debugoverlay,
      a2: p_m_vecLightingOrigin,
      a3: &pt1,
      a4: 100,
      a5: 100,
      a6: 150,
      a7: 1,
      a8: 0);
    v11 = list->m_pStudioHdr;
    pt0.x = v11->hull_max.x;
    pt0.y = v11->hull_min.y;
    pt0.z = v11->hull_min.z;
    VectorTransform(in1: &pt0.x, in2: v7, out: &pt1.x);
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: debugoverlay,
      a2: p_m_vecLightingOrigin,
      a3: &pt1,
      a4: 100,
      a5: 100,
      a6: 150,
      a7: 1,
      a8: 0);
    v12 = list->m_pStudioHdr;
    pt0.x = v12->hull_min.x;
    pt0.y = v12->hull_min.y;
    pt0.z = v12->hull_max.z;
    VectorTransform(in1: &pt0.x, in2: v7, out: &pt1.x);
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: debugoverlay,
      a2: p_m_vecLightingOrigin,
      a3: &pt1,
      a4: 100,
      a5: 100,
      a6: 150,
      a7: 1,
      a8: 0);
    v13 = list->m_pStudioHdr;
    pt0.x = v13->hull_min.x;
    pt0.y = v13->hull_max.y;
    pt0.z = v13->hull_max.z;
    VectorTransform(in1: &pt0.x, in2: v7, out: &pt1.x);
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: debugoverlay,
      a2: p_m_vecLightingOrigin,
      a3: &pt1,
      a4: 100,
      a5: 100,
      a6: 150,
      a7: 1,
      a8: 0);
    pt0 = list->m_pStudioHdr->hull_max;
    VectorTransform(in1: &pt0.x, in2: v7, out: &pt1.x);
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: debugoverlay,
      a2: p_m_vecLightingOrigin,
      a3: &pt1,
      a4: 100,
      a5: 100,
      a6: 150,
      a7: 1,
      a8: 0);
    v14 = list->m_pStudioHdr;
    pt0.x = v14->hull_max.x;
    pt0.y = v14->hull_min.y;
    pt0.z = v14->hull_max.z;
    VectorTransform(in1: &pt0.x, in2: v7, out: &pt1.x);
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
      a1: debugoverlay,
      a2: p_m_vecLightingOrigin,
      a3: &pt1,
      a4: 100,
      a5: 100,
      a6: 150,
      a7: 1,
      a8: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101226A0
// Name: private: void CModelRenderSystem::ComputeLightingOrigin(struct CModelRenderSystem::ModelListByType_t __near &,struct LightingQuery_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::ComputeLightingOrigin(
        CModelRenderSystem *this,
        CModelRenderSystem::ModelListByType_t *list,
        LightingQuery_t *pLightingQueryBase,
        int nQueryStride)
{
  studiohdr_t *m_pStudioHdr; // ecx
  int studiohdr2index; // eax
  int v7; // ebx
  int v8; // ebx
  const mstudioattachment_t *v9; // eax
  int AttachmentBone; // eax
  const Vector *v11; // ecx
  bool *v12; // esi
  int v13; // ebx
  CModelRenderSystem::RenderModelInfo_t *m_pRenderModels; // eax
  int v15; // eax
  bool *p_m_bAmbientBoost; // ebx
  CModelRenderSystem::RenderModelInfo_t *v17; // esi
  const matrix3x4_t *v18; // eax
  int v19; // eax
  const Vector *v20; // [esp-Ch] [ebp-2Ch]
  Vector attachmentOffset; // [esp+Ch] [ebp-14h] BYREF
  const Vector *vecIllumPosition; // [esp+18h] [ebp-8h]
  int j; // [esp+1Ch] [ebp-4h]
  bool bAmbientBoost_3; // [esp+2Bh] [ebp+Bh]
  LightingQuery_t *pLightingQueryBasea; // [esp+2Ch] [ebp+Ch]

  m_pStudioHdr = list->m_pStudioHdr;
  studiohdr2index = m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0 )
    v7 = *(int *)((char *)&m_pStudioHdr->checksum + studiohdr2index);
  else
    v7 = 0;
  bAmbientBoost_3 = BYTE2(m_pStudioHdr->flags) & 1;
  if ( v7 <= 0 || v7 > studiohdr_t::GetNumAttachments(this: m_pStudioHdr) )
  {
    vecIllumPosition = &list->m_pStudioHdr->illumposition;
    j = 0;
    if ( list->m_nCount > 0 )
    {
      p_m_bAmbientBoost = &pLightingQueryBase->m_bAmbientBoost;
      pLightingQueryBasea = nullptr;
      do
      {
        v17 = (CModelRenderSystem::RenderModelInfo_t *)((char *)pLightingQueryBasea + (unsigned int)list->m_pRenderModels);
        v18 = v17->m_Entry.m_pRenderable->RenderableToWorldTransform(this: v17->m_Entry.m_pRenderable);
        v20 = vecIllumPosition;
        *((_WORD *)p_m_bAmbientBoost - 1) = v17->m_hInstance;
        VectorTransform(in1: &v20->x, in2: v18, out: (float *)(p_m_bAmbientBoost - 14));
        v19 = j;
        pLightingQueryBasea = (LightingQuery_t *)((char *)pLightingQueryBasea + 92);
        *p_m_bAmbientBoost = bAmbientBoost_3;
        p_m_bAmbientBoost += nQueryStride;
        j = v19 + 1;
      }
      while ( v19 + 1 < list->m_nCount );
    }
  }
  else
  {
    v8 = v7 - 1;
    v9 = studiohdr_t::pAttachment(this: list->m_pStudioHdr, i: v8);
    MatrixGetColumn(in: &v9->local, column: 3, out: &attachmentOffset);
    AttachmentBone = studiohdr_t::GetAttachmentBone(this: list->m_pStudioHdr, i: v8);
    j = 0;
    if ( list->m_nCount > 0 )
    {
      v11 = (const Vector *)(48 * AttachmentBone);
      v12 = &pLightingQueryBase->m_bAmbientBoost;
      vecIllumPosition = (const Vector *)(48 * AttachmentBone);
      v13 = 0;
      while ( 1 )
      {
        m_pRenderModels = list->m_pRenderModels;
        *((_WORD *)v12 - 1) = m_pRenderModels[v13].m_hInstance;
        VectorTransform(
          in1: &attachmentOffset.x,
          in2: (const matrix3x4_t *)((char *)v11 + (unsigned int)m_pRenderModels[v13].m_pBoneToWorld),
          out: (float *)(v12 - 14));
        v15 = j;
        *v12 = bAmbientBoost_3;
        v12 += nQueryStride;
        ++v13;
        j = v15 + 1;
        if ( v15 + 1 >= list->m_nCount )
          break;
        v11 = vecIllumPosition;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101227E0
// Name: private: void CModelRenderSystem::HookUpStaticLightingState(int,struct CModelRenderSystem::ModelListByType_t __near * __near *,unsigned char __near *,class ITexture __near * __near *,struct MaterialLightingState_t __near *,struct MaterialLightingState_t __near *,struct ColorMeshInfo_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::HookUpStaticLightingState(
        CModelRenderSystem *this,
        int nCount,
        CModelRenderSystem::ModelListByType_t **ppLists,
        unsigned __int8 *pFlags,
        ITexture **ppEnvCubemap,
        MaterialLightingState_t *pLightingState,
        MaterialLightingState_t *pDecalLightingState,
        ColorMeshInfo_t **ppColorMeshInfo)
{
  int v8; // ecx
  CModelRenderSystem::ModelListByType_t *v9; // eax
  int v10; // esi
  int v11; // ebx
  ITexture *m_pTexture; // edi
  int v13; // ebx
  MaterialLightingState_t *v14; // esi
  int v15; // edi
  int j; // ecx
  CModelRenderSystem::RenderModelInfo_t *m_pRenderModels; // edx
  int v18; // edx
  int v19; // esi
  int m_nCount; // eax
  int v21; // edx
  int i; // [esp+8h] [ebp-4h]

  v8 = 0;
  for ( i = 0; v8 < nCount; i = v8 )
  {
    v9 = ppLists[v8];
    if ( (pFlags[v8] & 1) != 0 )
    {
      v10 = 0;
      if ( v9->m_nCount > 0 )
      {
        v11 = 0;
        do
        {
          m_pTexture = ppEnvCubemap[v10];
          if ( m_pTexture == nullptr )
            m_pTexture = this->m_DefaultCubemap.m_pTexture;
          v9->m_pRenderModels[v11].m_pEnvCubemapTexture = m_pTexture;
          ++v10;
          ++v11;
        }
        while ( v10 < v9->m_nCount );
      }
    }
    if ( (pFlags[v8] & 2) != 0 )
    {
      v13 = 0;
      if ( v9->m_nCount > 0 )
      {
        v14 = pDecalLightingState;
        v15 = 0;
        for ( j = (char *)pLightingState - (char *)pDecalLightingState;
              ;
              j = (char *)pLightingState - (char *)pDecalLightingState )
        {
          m_pRenderModels = v9->m_pRenderModels;
          m_pRenderModels[v15].m_pDecalLightingState = v14;
          m_pRenderModels[v15].m_pLightingState = (MaterialLightingState_t *)((char *)v14 + j);
          ++v13;
          ++v15;
          ++v14;
          if ( v13 >= v9->m_nCount )
            break;
        }
        v8 = i;
      }
    }
    if ( (pFlags[v8] & 4) != 0 )
    {
      v18 = 0;
      if ( v9->m_nCount > 0 )
      {
        v19 = 0;
        do
          v9->m_pRenderModels[v19++].m_pColorMeshInfo = ppColorMeshInfo[v18++];
        while ( v18 < v9->m_nCount );
      }
    }
    m_nCount = v9->m_nCount;
    v21 = 4 * m_nCount;
    m_nCount *= 440;
    ppEnvCubemap = (ITexture **)((char *)ppEnvCubemap + v21);
    pLightingState = (MaterialLightingState_t *)((char *)pLightingState + m_nCount);
    pDecalLightingState = (MaterialLightingState_t *)((char *)pDecalLightingState + m_nCount);
    ppColorMeshInfo = (ColorMeshInfo_t **)((char *)ppColorMeshInfo + v21);
    ++v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101228E0
// Name: private: void CModelRenderSystem::SetupPerInstanceColorModulation(int,struct CModelRenderSystem::ModelListByType_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::SetupPerInstanceColorModulation(
        CModelRenderSystem *this,
        CModelRenderSystem::ModelListByType_t *nModelTypeCount,
        CModelRenderSystem::ModelListByType_t *pModelList)
{
  int *p_m_nCount; // edi
  int v4; // ebx
  int v5; // esi
  int nModelTypeCounta; // [esp+8h] [ebp+8h]
  CModelRenderSystem::ModelListByType_t *pModelLista; // [esp+Ch] [ebp+Ch]

  if ( (int)nModelTypeCount > 0 )
  {
    p_m_nCount = &pModelList->m_nCount;
    for ( pModelLista = nModelTypeCount;
          pModelLista != nullptr;
          pModelLista = (CModelRenderSystem::ModelListByType_t *)((char *)pModelLista - 1) )
    {
      v4 = 0;
      if ( *p_m_nCount > 0 )
      {
        nModelTypeCounta = 0;
        do
        {
          v5 = nModelTypeCounta + p_m_nCount[3];
          (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(v5 + 68) + 44))(a1: *(_DWORD *)(v5 + 68), a2: v5 + 52);
          nModelTypeCounta += 92;
          ++v4;
          *(float *)(v5 + 64) = (float)*(unsigned __int8 *)(v5 + 76) * 0.0039215689;
        }
        while ( v4 < *p_m_nCount );
      }
      p_m_nCount += 12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10122950
// Name: private: void CModelRenderSystem::SetupPerInstanceColorModulation(int,struct ModelRenderSystemData_t __near *,struct BrushArrayInstanceData_t __near *,enum ModelRenderMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::SetupPerInstanceColorModulation(
        CModelRenderSystem *this,
        int nCount,
        ModelRenderSystemData_t *pModels,
        BrushArrayInstanceData_t *pInstanceData,
        ModelRenderMode_t renderMode)
{
  int v5; // ebx
  float *p_w; // edi

  if ( renderMode == MODEL_RENDER_MODE_NORMAL )
  {
    v5 = nCount;
    if ( nCount > 0 )
    {
      p_w = &pInstanceData->m_DiffuseModulation.w;
      do
      {
        pModels->m_pRenderable->GetColorModulation(this: pModels->m_pRenderable, a2: p_w - 3);
        *p_w = (float)pModels->m_InstanceData.m_nAlpha * 0.0039215689;
        ++pModels;
        p_w += 7;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10122A10
// Name: public: struct StudioArrayInstanceData_t __near & StudioArrayInstanceData_t::operator=(struct StudioArrayInstanceData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
StudioArrayInstanceData_t *__thiscall StudioArrayInstanceData_t::operator=(
        StudioArrayInstanceData_t *this,
        const StudioArrayInstanceData_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10122A80
// Name: void std::swap<struct CModelRenderSystem::ModelListByType_t>(struct CModelRenderSystem::ModelListByType_t __near &,struct CModelRenderSystem::ModelListByType_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::swap<CModelRenderSystem::ModelListByType_t>(
        CModelRenderSystem::ModelListByType_t *_Left,
        CModelRenderSystem::ModelListByType_t *_Right)
{
  StudioModelArrayInfo2_t v2; // xmm0_8
  __int64 v3; // xmm1_8
  __int64 v4; // xmm2_8
  __int64 v5; // xmm3_8
  __int64 v6; // xmm4_8
  __int64 v7; // xmm5_8

  v2 = _Left->StudioModelArrayInfo2_t;
  v3 = *(_QWORD *)&_Left->m_pStudioHdr;
  v4 = *(_QWORD *)&_Left->m_nLightingModel;
  v5 = *(_QWORD *)&_Left->m_pFirstNode;
  v6 = *(_QWORD *)&_Left->m_nSetupBoneCount;
  v7 = *(_QWORD *)&_Left->m_pRenderModels;
  *_Left = *_Right;
  _Right->StudioModelArrayInfo2_t = v2;
  *(_QWORD *)&_Right->m_pStudioHdr = v3;
  *(_QWORD *)&_Right->m_nLightingModel = v4;
  *(_QWORD *)&_Right->m_pFirstNode = v5;
  *(_QWORD *)&_Right->m_nSetupBoneCount = v6;
  *(_QWORD *)&_Right->m_pRenderModels = v7;
}

//------------------------------------------------------------------------------
// Address: 0x10122B00
// Name: void std::_Adjust_heap<struct CModelRenderSystem::ModelListByType_t __near *,int,struct CModelRenderSystem::ModelListByType_t,bool (*)(struct CModelRenderSystem::ModelListByType_t const __near &,struct CModelRenderSystem::ModelListByType_t const __near &)>(struct CModelRenderSystem::ModelListByType_t __near *,int,int,struct CModelRenderSystem::ModelListByType_t __near &&,bool (*)(struct CModelRenderSystem::ModelListByType_t const __near &,struct CModelRenderSystem::ModelListByType_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<CModelRenderSystem::ModelListByType_t *,int,CModelRenderSystem::ModelListByType_t,bool (__cdecl *)(CModelRenderSystem::ModelListByType_t const &,CModelRenderSystem::ModelListByType_t const &)>(
        CModelRenderSystem::ModelListByType_t *_First,
        int _Hole,
        int _Bottom,
        CModelRenderSystem::ModelListByType_t *_Val,
        bool (__cdecl *_Pred)(const CModelRenderSystem::ModelListByType_t *, const CModelRenderSystem::ModelListByType_t *))
{
  int v5; // ecx
  int v6; // ebx
  int v7; // esi
  CModelRenderSystem::ModelListByType_t *v8; // edi
  CModelRenderSystem::ModelListByType_t *v9; // eax
  CModelRenderSystem::ModelListByType_t *v10; // ecx
  CModelRenderSystem::ModelListByType_t *v11; // eax
  int v12; // ebx
  CModelRenderSystem::ModelListByType_t *v13; // ebx
  int i; // edi
  CModelRenderSystem::ModelListByType_t *v15; // esi
  CModelRenderSystem::ModelListByType_t *v16; // eax

  v5 = _Bottom;
  v6 = _Hole;
  v7 = 2 * _Hole + 2;
  if ( v7 >= _Bottom )
  {
    v8 = _First;
  }
  else
  {
    do
    {
      v8 = _First;
      if ( _Pred(a1: &_First[v7], a2: &_First[v7 - 1]) )
        --v7;
      v9 = &_First[v7];
      _First[v6].StudioModelArrayInfo2_t = v9->StudioModelArrayInfo2_t;
      v10 = &_First[v6];
      *(_QWORD *)&v10->m_pStudioHdr = *(_QWORD *)&v9->m_pStudioHdr;
      *(_QWORD *)&v10->m_nLightingModel = *(_QWORD *)&v9->m_nLightingModel;
      *(_QWORD *)&v10->m_pFirstNode = *(_QWORD *)&v9->m_pFirstNode;
      v6 = v7;
      *(_QWORD *)&v10->m_nSetupBoneCount = *(_QWORD *)&v9->m_nSetupBoneCount;
      v7 = 2 * v7 + 2;
      *(_QWORD *)&v10->m_pRenderModels = *(_QWORD *)&v9->m_pRenderModels;
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
  }
  if ( v7 == v5 )
  {
    v11 = &v8[v5 - 1];
    v12 = v6;
    v8[v12].StudioModelArrayInfo2_t = v11->StudioModelArrayInfo2_t;
    v13 = &v8[v12];
    *(_QWORD *)&v13->m_pStudioHdr = *(_QWORD *)&v11->m_pStudioHdr;
    *(_QWORD *)&v13->m_nLightingModel = *(_QWORD *)&v11->m_nLightingModel;
    *(_QWORD *)&v13->m_pFirstNode = *(_QWORD *)&v11->m_pFirstNode;
    *(_QWORD *)&v13->m_nSetupBoneCount = *(_QWORD *)&v11->m_nSetupBoneCount;
    *(_QWORD *)&v13->m_pRenderModels = *(_QWORD *)&v11->m_pRenderModels;
    v6 = v5 - 1;
  }
  for ( i = (v6 - 1) / 2; _Hole < v6; i = (i - 1) / 2 )
  {
    v15 = &_First[i];
    if ( !_Pred(a1: v15, a2: _Val) )
      break;
    v16 = &_First[v6];
    v6 = i;
    v16->StudioModelArrayInfo2_t = v15->StudioModelArrayInfo2_t;
    *(_QWORD *)&v16->m_pStudioHdr = *(_QWORD *)&v15->m_pStudioHdr;
    *(_QWORD *)&v16->m_nLightingModel = *(_QWORD *)&v15->m_nLightingModel;
    *(_QWORD *)&v16->m_pFirstNode = *(_QWORD *)&v15->m_pFirstNode;
    *(_QWORD *)&v16->m_nSetupBoneCount = *(_QWORD *)&v15->m_nSetupBoneCount;
    *(_QWORD *)&v16->m_pRenderModels = *(_QWORD *)&v15->m_pRenderModels;
  }
  _First[v6] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x10122CB0
// Name: struct CModelRenderSystem::ModelListByType_t __near * std::_Move_backward<struct CModelRenderSystem::ModelListByType_t __near *,struct CModelRenderSystem::ModelListByType_t __near *>(struct CModelRenderSystem::ModelListByType_t __near *,struct CModelRenderSystem::ModelListByType_t __near *,struct CModelRenderSystem::ModelListByType_t __near *,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
CModelRenderSystem::ModelListByType_t *__cdecl std::_Move_backward<CModelRenderSystem::ModelListByType_t *,CModelRenderSystem::ModelListByType_t *>(
        CModelRenderSystem::ModelListByType_t *_First,
        CModelRenderSystem::ModelListByType_t *_Last,
        CModelRenderSystem::ModelListByType_t *_Dest)
{
  CModelRenderSystem::ModelListByType_t *v3; // ecx
  CModelRenderSystem::ModelListByType_t *result; // eax
  StudioModelArrayInfo2_t v5; // xmm0_8

  v3 = _Last;
  for ( result = _Dest; v3 != _First; *(_QWORD *)&result->m_pRenderModels = *(_QWORD *)&v3->m_pRenderModels )
  {
    v5 = v3[-1].StudioModelArrayInfo2_t;
    --v3;
    result[-1].StudioModelArrayInfo2_t = v5;
    --result;
    *(_QWORD *)&result->m_pStudioHdr = *(_QWORD *)&v3->m_pStudioHdr;
    *(_QWORD *)&result->m_nLightingModel = *(_QWORD *)&v3->m_nLightingModel;
    *(_QWORD *)&result->m_pFirstNode = *(_QWORD *)&v3->m_pFirstNode;
    *(_QWORD *)&result->m_nSetupBoneCount = *(_QWORD *)&v3->m_nSetupBoneCount;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10122D10
// Name: private: int CModelRenderSystem::ComputeParentDepth(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelRenderSystem::ComputeParentDepth(CModelRenderSystem *this, C_BaseEntity *pEnt)
{
  C_BaseEntity *m_pEntity; // esi
  int i; // edi
  unsigned int m_Index; // ecx
  unsigned int v6; // ecx

  m_pEntity = pEnt;
  if ( pEnt == nullptr )
    return 0;
  for ( i = 0; ; ++i )
  {
    if ( !C_BaseEntity::IsFollowingEntity(this: m_pEntity) )
    {
      m_Index = m_pEntity->m_pMoveParent.m_Index;
      if ( m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr
        || m_pEntity->m_iParentAttachment == 0 )
      {
        break;
      }
    }
    v6 = m_pEntity->m_pMoveParent.m_Index;
    if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
      m_pEntity = nullptr;
    else
      m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x10122DA0
// Name: private: void CModelRenderSystem::ComputeModelLODs(int,struct CModelRenderSystem::ModelListByType_t __near *,struct CModelRenderSystem::ModelListNode_t __near *,enum ModelRenderMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::ComputeModelLODs(
        CModelRenderSystem *this,
        int nModelTypeCount,
        CModelRenderSystem::ModelListByType_t *pModelList,
        CModelRenderSystem::ModelListNode_t *pModelListNode,
        int renderMode)
{
  CModelRenderSystem::ModelListNode_t **p_m_pFirstNode; // edx
  int i; // esi
  CModelRenderSystem::ModelListNode_t *v7; // eax
  int v8; // ecx
  int m_nValue; // eax
  studiohwdata_t **p_m_pHardwareData; // ebx
  studiohwdata_t *v11; // esi
  int v12; // edi
  const Vector *v13; // eax
  long double v14; // st7
  long double v15; // st7
  float lodMetric; // xmm0_4
  int LODForMetric; // eax
  ScreenSizeComputeInfo_t info; // [esp+14h] [ebp-50h] BYREF
  float flScreenSize; // [esp+70h] [ebp+Ch]
  int nRootLOD; // [esp+78h] [ebp+14h]

  if ( renderMode == 2 )
  {
    if ( nModelTypeCount > 0 )
    {
      p_m_pFirstNode = &pModelList->m_pFirstNode;
      for ( i = nModelTypeCount; i != 0; --i )
      {
        v7 = *p_m_pFirstNode;
        if ( *p_m_pFirstNode != nullptr )
        {
          v8 = ((int)&(*(p_m_pFirstNode - 3))->m_Entry.m_pModelRenderable[-1].__vftable + 3) << 25;
          do
          {
            *((_DWORD *)v7 + 3) = v8 | *((_DWORD *)v7 + 3) & 0x1FFFFFF;
            v7 = v7->m_pNext;
          }
          while ( v7 != nullptr );
        }
        p_m_pFirstNode += 12;
      }
    }
    return;
  }
  if ( r_lod.m_pParent == nullptr )
  {
    m_nValue = 0;
    goto LABEL_11;
  }
  m_nValue = r_lod.m_pParent->m_Value.m_nValue;
  if ( m_nValue >= 0 )
  {
LABEL_11:
    CModelRenderSystem::SlamModelLODs(this, nLOD: m_nValue, nModelTypeCount, pModelList, pModelListNode);
    return;
  }
  ComputeScreenSizeInfo(pInfo: &info);
  if ( nModelTypeCount > 0 )
  {
    p_m_pHardwareData = &pModelList->m_pHardwareData;
    do
    {
      v11 = p_m_pHardwareData[3];
      v12 = (*p_m_pHardwareData)->m_NumLODs - 1;
      for ( nRootLOD = (*p_m_pHardwareData)->m_RootLOD;
            v11 != nullptr;
            v11 = (studiohwdata_t *)v11->m_NumTimesRenderedThisFrame )
      {
        v13 = (const Vector *)(*(int (__thiscall **)(int))(*(_DWORD *)v11->m_RootLOD + 4))(a1: v11->m_RootLOD);
        v14 = ComputeScreenSize(vecOrigin: v13, flRadius: 0.5, &info);
        v15 = v14 + v14;
        if ( v15 == 0.0 )
        {
          lodMetric = 0.0;
        }
        else
        {
          flScreenSize = v15;
          lodMetric = 100.0 / flScreenSize;
        }
        LODForMetric = studiohwdata_t::GetLODForMetric(this: *p_m_pHardwareData, lodMetric);
        if ( LODForMetric >= nRootLOD )
        {
          if ( LODForMetric > v12 )
            LODForMetric = v12;
        }
        else
        {
          LODForMetric = nRootLOD;
        }
        v11->m_NumStudioMeshes = (LODForMetric << 25) | v11->m_NumStudioMeshes & 0x1FFFFFF;
      }
      p_m_pHardwareData += 12;
      --nModelTypeCount;
    }
    while ( nModelTypeCount != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10122F00
// Name: private: void CModelRenderSystem::SetupFlexes(int,struct CModelRenderSystem::ModelListByType_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CModelRenderSystem::SetupFlexes(
        CModelRenderSystem *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        int nModelTypeCount,
        CModelRenderSystem::ModelListByType_t *pModelList)
{
  int m_nValue; // eax
  int *p_m_nCount; // eax
  int v9; // ecx
  IMatRenderContext *m_pRenderContext; // edi
  int v11; // esi
  int v12; // ebx
  IMatRenderContext_vtbl *v13; // eax
  bool v14; // cc
  bool v15; // zf
  int rdFlexWeights_4; // [esp+4h] [ebp-30h]
  char rdDelayedFlexWeights_12; // [esp+1Ch] [ebp-18h]
  int v22; // [esp+24h] [ebp-10h]
  int j; // [esp+28h] [ebp-Ch]
  int v24; // [esp+2Ch] [ebp-8h]
  bool bUsesDelayedWeights; // [esp+33h] [ebp-1h]
  int *nModelTypeCounta; // [esp+3Ch] [ebp+8h]
  int nFlexCount; // [esp+40h] [ebp+Ch]

  if ( g_CV_FlexSmooth.m_pParent != nullptr )
    m_nValue = g_CV_FlexSmooth.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  bUsesDelayedWeights = m_nValue != 0;
  if ( nModelTypeCount > 0 )
  {
    p_m_nCount = &pModelList->m_nCount;
    nModelTypeCounta = &pModelList->m_nCount;
    v22 = nModelTypeCount;
    do
    {
      v9 = *(_DWORD *)(*(p_m_nCount - 5) + 260);
      nFlexCount = v9;
      if ( v9 != 0 )
      {
        j = 0;
        if ( *p_m_nCount > 0 )
        {
          v24 = 0;
          while ( 1 )
          {
            m_pRenderContext = this->m_pRenderContext;
            v11 = v24 + p_m_nCount[3];
            v12 = 0;
            rdDelayedFlexWeights_12 = 0;
            rdFlexWeights_4 = ((int (__thiscall *)(IMatRenderContext *, int, int, int, int))m_pRenderContext->LockRenderData)(
                                a1: m_pRenderContext,
                                a2: 4 * v9,
                                a3,
                                a4,
                                a5: a2);
            *(_DWORD *)(v11 + 16) = rdFlexWeights_4;
            if ( bUsesDelayedWeights )
            {
              v12 = (int)m_pRenderContext->LockRenderData(this: m_pRenderContext, a2: 4 * nFlexCount);
              rdDelayedFlexWeights_12 = 1;
              *(_DWORD *)(v11 + 20) = v12;
            }
            a2 = *(_DWORD *)(v11 + 20);
            a4 = *(_DWORD *)(v11 + 16);
            a3 = nFlexCount;
            (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(v11 + 68) + 56))(
              a1: *(_DWORD *)(v11 + 68),
              a2: *(_DWORD *)(v11 + 84));
            if ( m_pRenderContext != nullptr && v12 != 0 )
            {
              v13 = m_pRenderContext->__vftable;
              if ( rdDelayedFlexWeights_12 != 0 )
                v13->UnlockRenderData(this: m_pRenderContext, a2: (void *)v12);
              else
                v13->ReleaseRenderData(this: m_pRenderContext);
            }
            if ( rdFlexWeights_4 != 0 )
              m_pRenderContext->UnlockRenderData(this: m_pRenderContext, a2: (void *)rdFlexWeights_4);
            v24 += 92;
            v14 = ++j < *nModelTypeCounta;
            p_m_nCount = nModelTypeCounta;
            if ( !v14 )
              break;
            v9 = nFlexCount;
          }
        }
      }
      p_m_nCount += 12;
      v15 = v22-- == 1;
      nModelTypeCounta = p_m_nCount;
    }
    while ( !v15 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123040
// Name: private: void CModelRenderSystem::RenderVCollideDebugOverlay(int,struct CModelRenderSystem::ModelListByType_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::RenderVCollideDebugOverlay(
        CModelRenderSystem *this,
        int nModelTypeCount,
        CModelRenderSystem::ModelListByType_t *pModelList)
{
  int *p_m_nCount; // ecx
  int (__thiscall ***v4)(_DWORD); // ebx
  C_BaseAnimating *v5; // eax
  C_BaseAnimating *v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // esi
  vcollide_t *v10; // eax
  int v11; // edx
  IVModelInfoClient_vtbl *v12; // edi
  int v13; // eax
  vcollide_t *v14; // eax
  IVEngineClient_vtbl *v15; // edi
  int v16; // eax
  vcollide_t *v17; // esi
  int v18; // eax
  int v19; // eax
  int v20; // eax
  bool v21; // zf
  matrix3x4_t matrix; // [esp+0h] [ebp-3Ch] BYREF
  vcollide_t *pCollide; // [esp+30h] [ebp-Ch]
  int v24; // [esp+34h] [ebp-8h]
  int *v25; // [esp+38h] [ebp-4h]
  int nModelTypeCounta; // [esp+44h] [ebp+8h]
  int j; // [esp+48h] [ebp+Ch]

  if ( vcollide_wireframe.m_pParent != nullptr
    && vcollide_wireframe.m_pParent->m_Value.m_nValue != 0
    && nModelTypeCount > 0 )
  {
    p_m_nCount = &pModelList->m_nCount;
    v25 = &pModelList->m_nCount;
    v24 = nModelTypeCount;
    do
    {
      j = 0;
      if ( *p_m_nCount > 0 )
      {
        nModelTypeCounta = 0;
        do
        {
          v4 = *(int (__thiscall ****)(_DWORD))(nModelTypeCounta + p_m_nCount[3] + 68);
          v5 = (C_BaseAnimating *)__RTDynamicCast(
                                    inptr: v4,
                                    VfDelta: 0,
                                    SrcType: &IClientRenderable `RTTI Type Descriptor',
                                    TargetType: &C_BaseAnimating `RTTI Type Descriptor',
                                    isReference: 0);
          v6 = v5;
          if ( v5 != nullptr && C_BaseAnimating::IsRagdoll(this: v5) )
          {
            v6->m_pRagdoll->DrawWireframe(this: v6->m_pRagdoll);
          }
          else
          {
            v7 = (**v4)(a1: v4);
            v8 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
            v9 = v8;
            if ( v8 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 44))(a1: v8) == 6 )
            {
              v10 = (vcollide_t *)(*(int (__thiscall **)(int))(*(_DWORD *)v9 + 48))(a1: v9);
              v11 = *(_DWORD *)v9;
              pCollide = v10;
              if ( (*(int (__thiscall **)(int))(v11 + 44))(a1: v9) != 0 && ((unsigned __int8)pCollide & 4) == 0 )
              {
                v12 = modelinfo->__vftable;
                v13 = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 28))(a1: v9);
                v14 = v12->GetVCollide_2(this: modelinfo, a2: (const struct model_t *)v13);
                pCollide = v14;
                if ( v14 != nullptr && (*(_WORD *)v14 & 0x7FFF) == 1 )
                {
                  v15 = engine->__vftable;
                  v16 = (*(int (__thiscall **)(int, color32_s *))(*(_DWORD *)v9 + 40))(a1: v9, a2: &debugColor_1);
                  v17 = pCollide;
                  ((void (__thiscall *)(IVEngineClient *, struct CPhysCollide *, _DWORD, int))v15->DebugDrawPhysCollide)(
                    a1: engine,
                    a2: *pCollide->solids,
                    a3: 0,
                    a4: v16);
                  v18 = (**v4)(a1: v4);
                  v19 = (*(int (__thiscall **)(int))(*(_DWORD *)v18 + 28))(a1: v18);
                  if ( v19 != 0 )
                  {
                    v20 = *(_DWORD *)(v19 + 660);
                    if ( v20 != 0 )
                    {
                      (*(void (__thiscall **)(int, matrix3x4_t *))(*(_DWORD *)v20 + 196))(a1: v20, a2: &matrix);
                      engine->DebugDrawPhysCollide(
                        this: engine,
                        a2: *v17->solids,
                        a3: nullptr,
                        a4: &matrix,
                        a5: &debugColorPhys_0);
                    }
                  }
                }
              }
            }
          }
          p_m_nCount = v25;
          nModelTypeCounta += 92;
          ++j;
        }
        while ( j < *v25 );
      }
      p_m_nCount += 12;
      v21 = v24-- == 1;
      v25 = p_m_nCount;
    }
    while ( !v21 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123220
// Name: void std::_Make_heap<struct CModelRenderSystem::ModelListByType_t __near *,int,struct CModelRenderSystem::ModelListByType_t,bool (*)(struct CModelRenderSystem::ModelListByType_t const __near &,struct CModelRenderSystem::ModelListByType_t const __near &)>(struct CModelRenderSystem::ModelListByType_t __near *,struct CModelRenderSystem::ModelListByType_t __near *,bool (*)(struct CModelRenderSystem::ModelListByType_t const __near &,struct CModelRenderSystem::ModelListByType_t const __near &),int __near *,struct CModelRenderSystem::ModelListByType_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<CModelRenderSystem::ModelListByType_t *,int,CModelRenderSystem::ModelListByType_t,bool (__cdecl *)(CModelRenderSystem::ModelListByType_t const &,CModelRenderSystem::ModelListByType_t const &)>(
        CModelRenderSystem::ModelListByType_t *_First,
        CModelRenderSystem::ModelListByType_t *_Last,
        bool (__cdecl *_Pred)(const CModelRenderSystem::ModelListByType_t *, const CModelRenderSystem::ModelListByType_t *))
{
  int v3; // ecx
  int v4; // eax
  int v5; // esi
  CModelRenderSystem::ModelListByType_t *v6; // ebx
  StudioModelArrayInfo2_t v7; // xmm0_8
  int v8; // eax
  int v9; // esi
  __int64 v10; // xmm0_8
  int v11; // edi
  bool v12; // zf
  CModelRenderSystem::ModelListByType_t *v13; // eax
  CModelRenderSystem::ModelListByType_t *v14; // ecx
  CModelRenderSystem::ModelListByType_t *v15; // edx
  int v16; // edi
  CModelRenderSystem::ModelListByType_t *v17; // edi
  CModelRenderSystem::ModelListByType_t _Val; // [esp+4h] [ebp-38h] BYREF
  int v19; // [esp+34h] [ebp-8h]
  int _Hole; // [esp+38h] [ebp-4h]
  int _Bottom; // [esp+48h] [ebp+Ch]

  v3 = _Last - _First;
  v4 = v3 / 2;
  _Bottom = v3;
  if ( v3 / 2 > 0 )
  {
    v5 = 2 * v4 + 2;
    v6 = &_First[v4];
    while ( 1 )
    {
      v7 = v6[-1].StudioModelArrayInfo2_t;
      --v6;
      _Val.StudioModelArrayInfo2_t = v7;
      *(_QWORD *)&_Val.m_pStudioHdr = *(_QWORD *)&v6->m_pStudioHdr;
      *(_QWORD *)&_Val.m_nLightingModel = *(_QWORD *)&v6->m_nLightingModel;
      *(_QWORD *)&_Val.m_pFirstNode = *(_QWORD *)&v6->m_pFirstNode;
      v8 = v4 - 1;
      v9 = v5 - 2;
      *(_QWORD *)&_Val.m_nSetupBoneCount = *(_QWORD *)&v6->m_nSetupBoneCount;
      v10 = *(_QWORD *)&v6->m_pRenderModels;
      _Hole = v8;
      v19 = v9;
      *(_QWORD *)&_Val.m_pRenderModels = v10;
      v11 = v8;
      v12 = v9 == v3;
      if ( v9 < v3 )
      {
        do
        {
          if ( _Pred(a1: &_First[v9], a2: &_First[v9 - 1]) )
            --v9;
          v13 = &_First[v9];
          _First[v11].StudioModelArrayInfo2_t = v13->StudioModelArrayInfo2_t;
          v14 = &_First[v11];
          *(_QWORD *)&v14->m_pStudioHdr = *(_QWORD *)&v13->m_pStudioHdr;
          *(_QWORD *)&v14->m_nLightingModel = *(_QWORD *)&v13->m_nLightingModel;
          *(_QWORD *)&v14->m_pFirstNode = *(_QWORD *)&v13->m_pFirstNode;
          v11 = v9;
          *(_QWORD *)&v14->m_nSetupBoneCount = *(_QWORD *)&v13->m_nSetupBoneCount;
          v9 = 2 * v9 + 2;
          *(_QWORD *)&v14->m_pRenderModels = *(_QWORD *)&v13->m_pRenderModels;
        }
        while ( v9 < _Bottom );
        v3 = _Bottom;
        v8 = _Hole;
        v12 = v9 == _Bottom;
      }
      if ( v12 )
      {
        v15 = &_First[v3 - 1];
        v16 = v11;
        _First[v16].StudioModelArrayInfo2_t = v15->StudioModelArrayInfo2_t;
        v17 = &_First[v16];
        *(_QWORD *)&v17->m_pStudioHdr = *(_QWORD *)&v15->m_pStudioHdr;
        *(_QWORD *)&v17->m_nLightingModel = *(_QWORD *)&v15->m_nLightingModel;
        *(_QWORD *)&v17->m_pFirstNode = *(_QWORD *)&v15->m_pFirstNode;
        *(_QWORD *)&v17->m_nSetupBoneCount = *(_QWORD *)&v15->m_nSetupBoneCount;
        *(_QWORD *)&v17->m_pRenderModels = *(_QWORD *)&v15->m_pRenderModels;
        v11 = v3 - 1;
      }
      std::_Push_heap<CModelRenderSystem::ModelListByType_t *,int,CModelRenderSystem::ModelListByType_t,bool (__cdecl *)(CModelRenderSystem::ModelListByType_t const &,CModelRenderSystem::ModelListByType_t const &)>(
        _First,
        _Hole: v11,
        _Top: v8,
        &_Val,
        _Pred);
      if ( _Hole <= 0 )
        break;
      v3 = _Bottom;
      v5 = v19;
      v4 = _Hole;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101233C0
// Name: public: struct CModelRenderSystem::RenderModelInfo_t __near & CModelRenderSystem::RenderModelInfo_t::operator=(struct CModelRenderSystem::RenderModelInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CModelRenderSystem::RenderModelInfo_t *__thiscall CModelRenderSystem::RenderModelInfo_t::operator=(
        CModelRenderSystem::RenderModelInfo_t *this,
        const CModelRenderSystem::RenderModelInfo_t *__that)
{
  int v3; // eax
  int v4; // eax

  StudioArrayInstanceData_t::operator=(this, __that);
  this->m_Entry = __that->m_Entry;
  v3 = *((_DWORD *)this + 22);
  this->m_hInstance = __that->m_hInstance;
  this->m_pBoneToWorld = __that->m_pBoneToWorld;
  *((_DWORD *)this + 22) ^= (*((_DWORD *)__that + 22) ^ v3) & 0xFFFFFF;
  v4 = *((_DWORD *)this + 22) ^ (*((_DWORD *)this + 22) ^ *((_DWORD *)__that + 22)) & 0x1000000;
  *((_DWORD *)this + 22) = v4;
  *((_DWORD *)this + 22) = v4 ^ (v4 ^ *((_DWORD *)__that + 22)) & 0x2000000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10123430
// Name: void std::swap<struct CModelRenderSystem::RenderModelInfo_t>(struct CModelRenderSystem::RenderModelInfo_t __near &,struct CModelRenderSystem::RenderModelInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::swap<CModelRenderSystem::RenderModelInfo_t>(
        CModelRenderSystem::RenderModelInfo_t *_Left,
        CModelRenderSystem::RenderModelInfo_t *_Right)
{
  MaterialLightingState_t *m_pLightingState; // ebx
  ShaderStencilState_t *m_pStencilState; // eax
  float y; // xmm0_4
  int v5; // edx
  float w; // xmm0_4
  matrix3x4a_t *m_pBoneToWorld; // eax
  int v8; // edi
  int v9; // eax
  unsigned __int16 m_hInstance; // cx
  matrix3x4a_t *v11; // edx
  CModelRenderSystem::RenderModelInfo_t _Tmp; // [esp+Ch] [ebp-5Ch]

  _Tmp.m_pEnvCubemapTexture = _Left->m_pEnvCubemapTexture;
  *(_QWORD *)&_Tmp.m_nLOD = *(_QWORD *)&_Left->m_nLOD;
  *(_QWORD *)&_Tmp.m_nSkin = *(_QWORD *)&_Left->m_nSkin;
  _Tmp.m_nFlashlightUsage = _Left->m_nFlashlightUsage;
  _Tmp.m_pDecalLightingState = _Left->m_pDecalLightingState;
  m_pLightingState = _Left->m_pLightingState;
  *(_QWORD *)&_Tmp.m_pFlexWeights = *(_QWORD *)&_Left->m_pFlexWeights;
  _Tmp.m_pColorMeshInfo = _Left->m_pColorMeshInfo;
  _Tmp.m_Decals = _Left->m_Decals;
  m_pStencilState = _Left->m_pStencilState;
  _Tmp.m_DiffuseModulation.x = _Left->m_DiffuseModulation.x;
  y = _Left->m_DiffuseModulation.y;
  _Tmp.m_hInstance = _Left->m_hInstance;
  v5 = *((_DWORD *)_Left + 22);
  _Tmp.m_DiffuseModulation.y = y;
  _Tmp.m_pStencilState = m_pStencilState;
  _Tmp.m_DiffuseModulation.z = _Left->m_DiffuseModulation.z;
  w = _Left->m_DiffuseModulation.w;
  *(_DWORD *)&_Tmp.m_Entry.m_InstanceData.m_nAlpha = *(_DWORD *)&_Left->m_Entry.m_InstanceData.m_nAlpha;
  m_pBoneToWorld = _Left->m_pBoneToWorld;
  *(_QWORD *)&_Tmp.m_Entry.m_pRenderable = *(_QWORD *)&_Left->m_Entry.m_pRenderable;
  _Tmp.m_pBoneToWorld = m_pBoneToWorld;
  v8 = (*((_DWORD *)&_Tmp + 22) ^ v5) & 0x3FFFFFF ^ *((_DWORD *)&_Tmp + 22);
  CModelRenderSystem::RenderModelInfo_t::operator=(this: _Left, __that: _Right);
  _Right->StudioShadowArrayInstanceData_t = _Tmp.StudioShadowArrayInstanceData_t;
  _Right->m_pDecalLightingState = _Tmp.m_pDecalLightingState;
  _Right->m_pEnvCubemapTexture = _Tmp.m_pEnvCubemapTexture;
  _Right->m_Decals = _Tmp.m_Decals;
  _Right->m_nFlashlightUsage = _Tmp.m_nFlashlightUsage;
  v9 = *(_DWORD *)&_Tmp.m_Entry.m_InstanceData.m_nAlpha;
  _Right->m_pStencilState = _Tmp.m_pStencilState;
  m_hInstance = _Tmp.m_hInstance;
  _Right->m_pColorMeshInfo = _Tmp.m_pColorMeshInfo;
  v11 = _Tmp.m_pBoneToWorld;
  _Right->m_pLightingState = m_pLightingState;
  _Right->m_DiffuseModulation.x = _Tmp.m_DiffuseModulation.x;
  _Right->m_DiffuseModulation.y = _Tmp.m_DiffuseModulation.y;
  _Right->m_DiffuseModulation.z = _Tmp.m_DiffuseModulation.z;
  _Right->m_DiffuseModulation.w = w;
  *(_QWORD *)&_Right->m_Entry.m_pRenderable = *(_QWORD *)&_Tmp.m_Entry.m_pRenderable;
  *(_DWORD *)&_Right->m_Entry.m_InstanceData.m_nAlpha = v9;
  _Right->m_hInstance = m_hInstance;
  *((_DWORD *)_Right + 22) ^= (v8 ^ *((_DWORD *)_Right + 22)) & 0x3FFFFFF;
  _Right->m_pBoneToWorld = v11;
}

//------------------------------------------------------------------------------
// Address: 0x10123580
// Name: void std::_Push_heap<struct CModelRenderSystem::RenderModelInfo_t __near *,int,struct CModelRenderSystem::RenderModelInfo_t,bool (*)(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &)>(struct CModelRenderSystem::RenderModelInfo_t __near *,int,int,struct CModelRenderSystem::RenderModelInfo_t __near &&,bool (*)(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<CModelRenderSystem::RenderModelInfo_t *,int,CModelRenderSystem::RenderModelInfo_t,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
        CModelRenderSystem::RenderModelInfo_t *_First,
        int _Hole,
        int _Top,
        CModelRenderSystem::RenderModelInfo_t *_Val,
        bool (__cdecl *_Pred)(const CModelRenderSystem::RenderModelInfo_t *, const CModelRenderSystem::RenderModelInfo_t *))
{
  int v5; // ebx
  int v6; // eax
  CModelRenderSystem::RenderModelInfo_t *v7; // esi
  CModelRenderSystem::RenderModelInfo_t *v8; // eax
  int v9; // ecx
  int v10; // ecx
  CModelRenderSystem::RenderModelInfo_t *v11; // eax
  int v12; // ecx
  int v13; // ecx
  int _Idx; // [esp+14h] [ebp+Ch]

  v5 = _Hole;
  v6 = (_Hole - 1) / 2;
  _Idx = v6;
  if ( _Top < v5 )
  {
    while ( 1 )
    {
      v7 = &_First[v6];
      if ( !_Pred(a1: v7, a2: _Val) )
        break;
      v8 = &_First[v5];
      *(_QWORD *)&v8->m_nLOD = *(_QWORD *)&v7->m_nLOD;
      *(_QWORD *)&v8->m_nSkin = *(_QWORD *)&v7->m_nSkin;
      *(_QWORD *)&v8->m_pFlexWeights = *(_QWORD *)&v7->m_pFlexWeights;
      v8->m_pLightingState = v7->m_pLightingState;
      v8->m_pDecalLightingState = v7->m_pDecalLightingState;
      v8->m_pEnvCubemapTexture = v7->m_pEnvCubemapTexture;
      v8->m_Decals = v7->m_Decals;
      v8->m_nFlashlightUsage = v7->m_nFlashlightUsage;
      v8->m_pStencilState = v7->m_pStencilState;
      v8->m_pColorMeshInfo = v7->m_pColorMeshInfo;
      v8->m_DiffuseModulation.x = v7->m_DiffuseModulation.x;
      v5 = _Idx;
      v8->m_DiffuseModulation.y = v7->m_DiffuseModulation.y;
      v8->m_DiffuseModulation.z = v7->m_DiffuseModulation.z;
      v8->m_DiffuseModulation.w = v7->m_DiffuseModulation.w;
      *(_QWORD *)&v8->m_Entry.m_pRenderable = *(_QWORD *)&v7->m_Entry.m_pRenderable;
      *(_DWORD *)&v8->m_Entry.m_InstanceData.m_nAlpha = *(_DWORD *)&v7->m_Entry.m_InstanceData.m_nAlpha;
      v8->m_hInstance = v7->m_hInstance;
      v9 = *((_DWORD *)v8 + 22);
      v8->m_pBoneToWorld = v7->m_pBoneToWorld;
      *((_DWORD *)v8 + 22) ^= (*((_DWORD *)v7 + 22) ^ v9) & 0xFFFFFF;
      v10 = *((_DWORD *)v8 + 22) ^ (*((_DWORD *)v8 + 22) ^ *((_DWORD *)v7 + 22)) & 0x1000000;
      *((_DWORD *)v8 + 22) = v10;
      *((_DWORD *)v8 + 22) = v10 ^ (v10 ^ *((_DWORD *)v7 + 22)) & 0x2000000;
      _Idx = (_Idx - 1) / 2;
      if ( _Top >= v5 )
        break;
      v6 = _Idx;
    }
  }
  v11 = &_First[v5];
  v11->StudioArrayInstanceData_t = _Val->StudioArrayInstanceData_t;
  v11->m_Entry = _Val->m_Entry;
  v11->m_hInstance = _Val->m_hInstance;
  v12 = *((_DWORD *)v11 + 22);
  v11->m_pBoneToWorld = _Val->m_pBoneToWorld;
  *((_DWORD *)v11 + 22) ^= (*((_DWORD *)_Val + 22) ^ v12) & 0xFFFFFF;
  v13 = *((_DWORD *)v11 + 22) ^ (*((_DWORD *)v11 + 22) ^ *((_DWORD *)_Val + 22)) & 0x1000000;
  *((_DWORD *)v11 + 22) = v13;
  *((_DWORD *)v11 + 22) = v13 ^ (v13 ^ *((_DWORD *)_Val + 22)) & 0x2000000;
}

//------------------------------------------------------------------------------
// Address: 0x10123750
// Name: struct CModelRenderSystem::RenderModelInfo_t __near * std::_Move_backward<struct CModelRenderSystem::RenderModelInfo_t __near *,struct CModelRenderSystem::RenderModelInfo_t __near *>(struct CModelRenderSystem::RenderModelInfo_t __near *,struct CModelRenderSystem::RenderModelInfo_t __near *,struct CModelRenderSystem::RenderModelInfo_t __near *,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
CModelRenderSystem::RenderModelInfo_t *__cdecl std::_Move_backward<CModelRenderSystem::RenderModelInfo_t *,CModelRenderSystem::RenderModelInfo_t *>(
        CModelRenderSystem::RenderModelInfo_t *_First,
        CModelRenderSystem::RenderModelInfo_t *_Last,
        CModelRenderSystem::RenderModelInfo_t *_Dest)
{
  CModelRenderSystem::RenderModelInfo_t *result; // eax
  float *p_z; // edx
  float *v5; // ecx
  __int64 v6; // xmm0_8
  int v7; // esi

  result = _Dest;
  if ( _First != _Last )
  {
    p_z = &_Dest->m_DiffuseModulation.z;
    v5 = &_Last->m_DiffuseModulation.z;
    do
    {
      v6 = *((_QWORD *)v5 - 19);
      v5 -= 23;
      *(_QWORD *)&result[-1].m_nLOD = v6;
      *(_QWORD *)&result[-1].m_nSkin = *(_QWORD *)(v5 - 13);
      *(_QWORD *)&result[-1].m_pFlexWeights = *(_QWORD *)(v5 - 11);
      *(p_z - 32) = *(v5 - 9);
      p_z -= 23;
      *(p_z - 8) = *(v5 - 8);
      *(p_z - 7) = *(v5 - 7);
      *(p_z - 6) = *(v5 - 6);
      --result;
      *(p_z - 5) = *(v5 - 5);
      *(p_z - 4) = *(v5 - 4);
      *(p_z - 3) = *(v5 - 3);
      *(p_z - 2) = *(v5 - 2);
      *(p_z - 1) = *(v5 - 1);
      *p_z = *v5;
      p_z[1] = v5[1];
      *((_QWORD *)p_z + 1) = *((_QWORD *)v5 + 1);
      p_z[4] = v5[4];
      *((_WORD *)p_z + 10) = *((_WORD *)v5 + 10);
      p_z[6] = v5[6];
      *((_DWORD *)p_z + 7) ^= (*((_DWORD *)v5 + 7) ^ *((_DWORD *)p_z + 7)) & 0xFFFFFF;
      v7 = *((_DWORD *)p_z + 7) ^ (*((_DWORD *)p_z + 7) ^ *((_DWORD *)v5 + 7)) & 0x1000000;
      *((_DWORD *)p_z + 7) = v7;
      *((_DWORD *)p_z + 7) = v7 ^ (v7 ^ *((_DWORD *)v5 + 7)) & 0x2000000;
    }
    while ( v5 - 15 != (float *)_First );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10123840
// Name: public: virtual CModelRenderSystem::~CModelRenderSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::~CModelRenderSystem(CModelRenderSystem *this)
{
  this->CAutoGameSystem::CBaseGameSystem::IGameSystem::__vftable = (CModelRenderSystem_vtbl *)&CModelRenderSystem::`vftable'{for `CAutoGameSystem'};
  this->IModelRenderSystem::__vftable = (IModelRenderSystem_vtbl *)&CModelRenderSystem::`vftable'{for `IModelRenderSystem'};
  CMemoryStack::Term(this: &this->m_BoneToWorld);
  if ( this->m_BrushModelList.m_nGrowSize >= 0 )
  {
    if ( this->m_BrushModelList.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BrushModelList.m_pMemory);
      this->m_BrushModelList.m_pMemory = nullptr;
    }
    this->m_BrushModelList.m_nAllocationCount = 0;
  }
  CMaterialReference::~CMaterialReference(this: &this->m_ShadowBuild);
  CMaterialReference::~CMaterialReference(this: &this->m_DebugMaterial);
  CTextureReference::~CTextureReference(this: &this->m_DefaultCubemap);
  CMemoryStack::~CMemoryStack(this: &this->m_BoneToWorld);
  IGameSystem::~IGameSystem(this);
}

//------------------------------------------------------------------------------
// Address: 0x101238B0
// Name: private: int CModelRenderSystem::BucketModelsByMDL(struct CModelRenderSystem::ModelListByType_t __near *,struct CModelRenderSystem::ModelListNode_t __near *,struct ModelRenderSystemData_t __near *,int,enum ModelRenderMode_t,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelRenderSystem::BucketModelsByMDL(
        CModelRenderSystem *this,
        CModelRenderSystem::ModelListByType_t *pModelList,
        CModelRenderSystem::ModelListNode_t *pModelListNodes,
        ModelRenderSystemData_t *pEntities,
        int nCount,
        ModelRenderMode_t renderMode,
        int *pModelsRenderingStencilCountOut)
{
  int result; // eax
  int v8; // edi
  IClientModelRenderable **p_m_pModelRenderable; // esi
  int v10; // ecx
  int (__thiscall *v11)(int); // eax
  const struct model_t *v12; // ebx
  IVModelInfoClient_vtbl *v13; // edx
  const char *v14; // eax
  int v15; // esi
  RenderableLightingModel_t *p_m_nLightingModel; // eax
  studiohdr_t *v17; // eax
  unsigned __int16 v18; // ax
  studiohwdata_t *v19; // eax
  RenderableLightingModel_t v20; // edx
  CModelRenderSystem::ModelListByType_t *v21; // ecx
  studiohdr_t *v22; // edx
  int v23; // eax
  int v24; // ebx
  unsigned int v25; // eax
  int v26; // edi
  CModelRenderSystem::ModelListNode_t *v27; // esi
  int v28; // edx
  CModelRenderSystem::ModelListByType_t *v29; // edi
  IClientModelRenderable *v30; // ecx
  int v31; // edx
  int v32; // ecx
  IMatRenderContext *m_pRenderContext; // ebx
  ShaderStencilState_t *v34; // eax
  int v35; // edx
  __int64 v36; // [esp+4h] [ebp-3Ch] BYREF
  __int64 v37; // [esp+Ch] [ebp-34h]
  __int64 v38; // [esp+14h] [ebp-2Ch]
  __int64 v39; // [esp+1Ch] [ebp-24h]
  unsigned int v40; // [esp+24h] [ebp-1Ch]
  studiohdr_t *v41; // [esp+28h] [ebp-18h]
  CModelRenderSystem *v42; // [esp+2Ch] [ebp-14h]
  CModelRenderSystem::ModelListNode_t *v43; // [esp+30h] [ebp-10h]
  int nModelWantingStencil; // [esp+34h] [ebp-Ch]
  int i; // [esp+38h] [ebp-8h]
  int v46; // [esp+3Ch] [ebp-4h] BYREF
  IClientModelRenderable **pModelListNodesa; // [esp+4Ch] [ebp+Ch]
  ModelRenderSystemData_t *pEntitiesa; // [esp+50h] [ebp+10h]

  result = 0;
  v8 = 0;
  v42 = this;
  nModelWantingStencil = 0;
  i = 0;
  if ( nCount > 0 )
  {
    p_m_pModelRenderable = &pEntities->m_pModelRenderable;
    v43 = pModelListNodes;
    for ( pModelListNodesa = &pEntities->m_pModelRenderable; ; p_m_pModelRenderable = pModelListNodesa )
    {
      v10 = (int)*(p_m_pModelRenderable - 1);
      v11 = *(int (__thiscall **)(int))(*(_DWORD *)v10 + 32);
      v41 = (studiohdr_t *)v8;
      v12 = (const struct model_t *)v11(a1: v10);
      v46 = -1;
      pEntitiesa = nullptr;
      LOBYTE(v36) = 0;
      v37 = 0x100000001LL;
      HIDWORD(v36) = 1;
      v38 = 8;
      v39 = -1;
      if ( *p_m_pModelRenderable != nullptr )
      {
        (*p_m_pModelRenderable)->GetRenderData(this: *p_m_pModelRenderable, a2: &v46, a3: MODEL_DATA_LIGHTING_MODEL);
        if ( renderMode == MODEL_RENDER_MODE_NORMAL )
          pEntitiesa = (ModelRenderSystemData_t *)((*p_m_pModelRenderable)->GetRenderData(
                                                     this: *p_m_pModelRenderable,
                                                     a2: &v36,
                                                     a3: MODEL_DATA_STENCIL) != 0);
      }
      else if ( dword_10649694 < 1 )
      {
        v13 = modelinfo->__vftable;
        ++dword_10649694;
        v14 = v13->GetModelName(this: modelinfo, a2: v12);
        DevWarning(a1: "data.m_pModelRenderable is NULL for %s\n", v14);
      }
      v15 = 0;
      if ( v8 > 0 )
      {
        p_m_nLightingModel = &pModelList->m_nLightingModel;
        do
        {
          if ( *((const struct model_t **)p_m_nLightingModel + 1) == v12
            && *p_m_nLightingModel == v46
            && (ModelRenderSystemData_t *)(*((_DWORD *)p_m_nLightingModel + 5) >> 31) == pEntitiesa )
          {
            break;
          }
          ++v15;
          p_m_nLightingModel += 12;
        }
        while ( v15 < v8 );
      }
      if ( v15 == v8 )
      {
        v17 = modelinfo->GetStudiomodel(this: modelinfo, a2: v12);
        v41 = v17;
        if ( renderMode != MODEL_RENDER_MODE_NORMAL && *pModelListNodesa != nullptr && (v17->flags & 0x20000) != 0 )
          goto LABEL_33;
        v18 = modelinfo->GetCacheHandle(this: modelinfo, a2: v12);
        v19 = g_pMDLCache->GetHardwareData(this: g_pMDLCache, a2: v18);
        if ( v19 == nullptr || v19->m_pLODs == nullptr )
          goto LABEL_33;
        v20 = v46;
        v21 = &pModelList[v8];
        v21->m_pHardwareData = v19;
        v21->m_nFlashlightCount = 0;
        v21->m_pFlashlights = nullptr;
        v21->m_nCount = 0;
        v21->m_pFirstNode = nullptr;
        v21->m_pRenderModels = nullptr;
        v21->m_pNextLightingModel = nullptr;
        v21->m_nLightingModel = v20;
        v22 = v41;
        v15 = v8;
        v21->m_pModel = v12;
        v21->m_pStudioHdr = v22;
        *((_DWORD *)v21 + 9) = (_DWORD)pEntitiesa << 31;
        v41 = (studiohdr_t *)(v8 + 1);
      }
      v23 = ((int (__thiscall *)(_DWORD))(*(pModelListNodesa - 1))->GetRenderData)(a1: *(pModelListNodesa - 1));
      v24 = (*(int (__thiscall **)(int))(*(_DWORD *)v23 + 28))(a1: v23);
      v25 = CModelRenderSystem::ComputeParentDepth(this: v42, pEnt: (C_BaseEntity *)v24);
      v26 = v15;
      v27 = v43;
      v28 = i ^ *((_DWORD *)v43++ + 3);
      v29 = &pModelList[v26];
      *(_QWORD *)&v27->m_Entry.m_pRenderable = *(_QWORD *)(pModelListNodesa - 1);
      v30 = pModelListNodesa[1];
      *((_DWORD *)v27 + 3) ^= v28 & 0xFFFFFF;
      v31 = *((_DWORD *)v27 + 3);
      v40 = v25;
      *(_DWORD *)&v27->m_Entry.m_InstanceData.m_nAlpha = v30;
      v32 = v24 != 0 && (*(_BYTE *)(v24 + 232) & 1) != 0;
      *((_DWORD *)v27 + 3) = v31 ^ (v31 ^ (v32 << 24)) & 0x1000000;
      if ( pEntitiesa == nullptr || renderMode != MODEL_RENDER_MODE_NORMAL )
      {
        v27->m_pStencilState = nullptr;
      }
      else
      {
        m_pRenderContext = v42->m_pRenderContext;
        v34 = (ShaderStencilState_t *)m_pRenderContext->LockRenderData(this: m_pRenderContext, a2: 32);
        *(_QWORD *)&v34->m_bEnable = v36;
        *(_QWORD *)&v34->m_ZFailOp = v37;
        *(_QWORD *)&v34->m_CompareFunc = v38;
        *(_QWORD *)&v34->m_nTestMask = v39;
        v27->m_pStencilState = v34;
        m_pRenderContext->UnlockRenderData(this: m_pRenderContext, a2: v34);
        v25 = v40;
      }
      v27->m_pNext = v29->m_pFirstNode;
      if ( (*((_DWORD *)v29 + 9) & 0x7FFFFFFFu) > v25 )
        v25 = *((_DWORD *)v29 + 9) & 0x7FFFFFFF;
      v35 = *((_DWORD *)v29 + 9) ^ (v25 ^ *((_DWORD *)v29 + 9)) & 0x7FFFFFFF;
      ++v29->m_nCount;
      *((_DWORD *)v29 + 9) = v35;
      v29->m_pFirstNode = v27;
      v8 = (int)v41;
LABEL_33:
      nModelWantingStencil += (int)pEntitiesa;
      pModelListNodesa += 3;
      if ( ++i >= nCount )
      {
        *pModelsRenderingStencilCountOut = nModelWantingStencil;
        return v8;
      }
    }
  }
  *pModelsRenderingStencilCountOut = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10123BA0
// Name: private: void CModelRenderSystem::SetupBones(int,struct CModelRenderSystem::ModelListByType_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CModelRenderSystem::SetupBones(
        CModelRenderSystem *this@<ecx>,
        int a2@<ebp>,
        int nModelTypeCount,
        CModelRenderSystem::ModelListByType_t *pModelList)
{
  void *v4; // esp
  int v5; // xmm0_4
  studiohdr_t **p_m_pStudioHdr; // eax
  studiohdr_t *v7; // ecx
  int studiohdr2index; // esi
  int numbones; // edx
  int v10; // esi
  unsigned int v11; // edx
  _DWORD *v12; // esi
  unsigned int m_alignment; // eax
  CMemoryStack *p_m_BoneToWorld; // ecx
  int v15; // edi
  bool v16; // cc
  unsigned int v17; // edx
  int v18; // edx
  unsigned __int8 *m_pNextAlloc; // eax
  unsigned __int8 *v20; // edx
  int v21; // ecx
  int v22; // edi
  int v23; // eax
  int v24; // edi
  studiohdr_t *v25; // ecx
  int v26; // esi
  int v27; // edi
  char *v28; // esi
  int v29; // edi
  matrix3x4_t *v30; // esi
  int v31; // esi
  char *v32; // ecx
  int v33; // esi
  char *v34; // edi
  int v35; // esi
  int v36; // ecx
  IMatRenderContext *m_pRenderContext; // edi
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  char *v39; // esi
  int v40; // eax
  int v41; // edi
  bool v42; // zf
  int v43; // [esp-4h] [ebp-3064h]
  int v44; // [esp+0h] [ebp-3060h]
  _BYTE v45[12292]; // [esp+14h] [ebp-304Ch] BYREF
  IMatRenderContext *v46; // [esp+3018h] [ebp-48h]
  int v47; // [esp+301Ch] [ebp-44h]
  unsigned __int8 *v48; // [esp+3028h] [ebp-38h]
  int v49; // [esp+302Ch] [ebp-34h]
  int v50; // [esp+3030h] [ebp-30h]
  int v51; // [esp+3034h] [ebp-2Ch]
  int v52; // [esp+3038h] [ebp-28h]
  CModelRenderSystem *v53; // [esp+303Ch] [ebp-24h]
  int v54; // [esp+3040h] [ebp-20h]
  int v55; // [esp+3044h] [ebp-1Ch]
  unsigned int v56; // [esp+3048h] [ebp-18h]
  studiohdr_t **v57; // [esp+304Ch] [ebp-14h]
  int i; // [esp+3050h] [ebp-10h]
  int v59; // [esp+3054h] [ebp-Ch]
  void *v60; // [esp+3058h] [ebp-8h]
  void *retaddr; // [esp+3060h] [ebp+0h]

  v59 = a2;
  v60 = retaddr;
  v4 = alloca(12360);
  v5 = *(_DWORD *)(gpGlobals.m_Index + 12);
  v53 = this;
  v50 = v5;
  if ( nModelTypeCount > 0 )
  {
    p_m_pStudioHdr = &pModelList->m_pStudioHdr;
    v57 = &pModelList->m_pStudioHdr;
    v51 = nModelTypeCount;
    while ( 1 )
    {
      v7 = *p_m_pStudioHdr;
      studiohdr2index = (*p_m_pStudioHdr)->studiohdr2index;
      numbones = (*p_m_pStudioHdr)->numbones;
      v54 = numbones;
      if ( studiohdr2index != 0 )
        v10 = *(int *)((char *)&v7->checksum + studiohdr2index);
      else
        v10 = 0;
      v49 = v10 <= 0 ? 0 : 0x200;
      i = 0;
      if ( (int)p_m_pStudioHdr[6] > 0 )
      {
        v11 = 48 * numbones;
        v52 = v11;
        v55 = 0;
        while ( 1 )
        {
          v12 = (int *)((char *)&p_m_pStudioHdr[8]->id + v55);
          m_alignment = v53->m_BoneToWorld.m_alignment;
          p_m_BoneToWorld = &v53->m_BoneToWorld;
          v15 = v49 | (1024 << *v12);
          v56 = v11;
          v16 = v11 <= m_alignment;
          v17 = m_alignment;
          if ( !v16 )
            v17 = v56;
          v18 = ~(m_alignment - 1) & (m_alignment + v17 - 1);
          m_pNextAlloc = p_m_BoneToWorld->m_pNextAlloc;
          v20 = &p_m_BoneToWorld->m_pNextAlloc[v18];
          v56 = (unsigned int)p_m_BoneToWorld->m_pNextAlloc;
          v48 = v20;
          if ( v20 <= v53->m_BoneToWorld.m_pCommitLimit )
            goto LABEL_15;
          if ( CMemoryStack::CommitTo(this: p_m_BoneToWorld, pNextAlloc: v20) )
            break;
          m_pNextAlloc = nullptr;
LABEL_16:
          v21 = v12[17];
          v44 = v50;
          v43 = v15;
          v22 = v54;
          v12[21] = m_pNextAlloc;
          if ( (*(unsigned __int8 (__thiscall **)(int, unsigned __int8 *, int, int, int))(*(_DWORD *)v21 + 52))(
                 a1: v21,
                 a2: m_pNextAlloc,
                 a3: v22,
                 a4: v43,
                 a5: v44) == 0 )
          {
            v23 = v22;
            if ( v22 > 0 )
            {
              v24 = 0;
              v56 = v23;
              do
              {
                SetIdentityMatrix(matrix: (matrix3x4_t *)(v24 + v12[21]));
                v24 += 48;
                --v56;
              }
              while ( v56 != 0 );
            }
          }
          v55 += 92;
          v16 = ++i < (int)v57[6];
          p_m_pStudioHdr = v57;
          if ( !v16 )
          {
            numbones = v54;
            goto LABEL_22;
          }
          v11 = v52;
        }
        m_pNextAlloc = (unsigned __int8 *)v56;
        v20 = v48;
LABEL_15:
        v53->m_BoneToWorld.m_pNextAlloc = v20;
        goto LABEL_16;
      }
LABEL_22:
      if ( p_m_pStudioHdr[5] != nullptr )
        break;
LABEL_49:
      p_m_pStudioHdr += 12;
      v42 = v51-- == 1;
      v57 = p_m_pStudioHdr;
      if ( v42 )
        return;
    }
    v25 = *p_m_pStudioHdr;
    v26 = (*p_m_pStudioHdr)->studiohdr2index;
    if ( v26 != 0 && (v27 = *(_DWORD *)&v25->name[v26 + 4], v28 = (char *)v25 + v26, v27 != 0) && &v28[v27] != nullptr )
    {
      v31 = v25->studiohdr2index;
      if ( v31 != 0 && (v32 = (char *)v25 + v31, (v33 = *((_DWORD *)v32 + 4)) != 0) )
        v34 = &v32[v33];
      else
        v34 = nullptr;
      if ( numbones <= 0 )
      {
LABEL_39:
        v56 = 0;
        if ( (int)p_m_pStudioHdr[5] > 0 )
        {
          v36 = 48 * numbones;
          v52 = 48 * numbones;
          v55 = 0;
          while ( 1 )
          {
            m_pRenderContext = v53->m_pRenderContext;
            LockRenderData = m_pRenderContext->LockRenderData;
            v39 = (char *)p_m_pStudioHdr[8] + v55;
            v46 = m_pRenderContext;
            v40 = (int)LockRenderData(this: m_pRenderContext, a2: v36);
            v16 = v54 <= 0;
            v47 = v40;
            *((_DWORD *)v39 + 3) = v40;
            if ( !v16 )
            {
              v41 = 0;
              i = v54;
              do
              {
                ConcatTransforms_Aligned(
                  m0: (const matrix3x4a_t *)(v41 + *((_DWORD *)v39 + 21)),
                  m1: (const matrix3x4a_t *)&v45[v41],
                  out: (matrix3x4a_t *)(v41 + *((_DWORD *)v39 + 3)));
                v41 += 48;
                --i;
              }
              while ( i != 0 );
              m_pRenderContext = v46;
              v40 = v47;
            }
            if ( v40 != 0 )
              m_pRenderContext->UnlockRenderData(this: m_pRenderContext, a2: (void *)v40);
            v55 += 92;
            v16 = (int)++v56 < (int)v57[5];
            p_m_pStudioHdr = v57;
            if ( !v16 )
              break;
            v36 = v52;
          }
        }
        goto LABEL_49;
      }
      v35 = 0;
      for ( i = numbones; i != 0; --i )
      {
        MatrixCopy(in: (const matrix3x4_t *)&v34[v35 + *((_DWORD *)v34 + 6)], out: (matrix3x4_t *)&v45[v35]);
        v35 += 48;
      }
      p_m_pStudioHdr = v57;
    }
    else
    {
      if ( numbones <= 0 )
        goto LABEL_39;
      v29 = 0;
      v30 = (matrix3x4_t *)v45;
      for ( i = numbones; i != 0; --i )
      {
        MatrixCopy(
          in: (const matrix3x4_t *)((char *)&(*p_m_pStudioHdr)->illumposition.y + v29 + (*p_m_pStudioHdr)->boneindex),
          out: v30);
        p_m_pStudioHdr = v57;
        ++v30;
        v29 += 216;
      }
    }
    numbones = v54;
    goto LABEL_39;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123E70
// Name: private: int CModelRenderSystem::SetupStaticPropLighting(struct CModelRenderSystem::LightingList_t __near &,struct memhandle_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelRenderSystem::SetupStaticPropLighting(
        CModelRenderSystem *this,
        int lightingList,
        memhandle_t__ **pColorMeshHandle)
{
  int v3; // edi
  void *v5; // esp
  CModelRenderSystem::ModelListByType_t **v6; // esi
  void *v7; // esp
  int v8; // edi
  int v9; // ebx
  void *v10; // esp
  int v11; // edx
  CModelRenderSystem::ModelListByType_t *v12; // ecx
  int v13; // esi
  int v14; // edx
  CModelRenderSystem::ModelListByType_t **v15; // eax
  CModelRenderSystem::ModelListByType_t *m_pRenderable; // edi
  void *v17; // esp
  void *v18; // esp
  IMatRenderContext *m_pRenderContext; // ecx
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // eax
  MaterialLightingState_t *v21; // edi
  CModelRenderSystem::ModelListByType_t *v22[3]; // [esp+0h] [ebp-34h] BYREF
  CMatRenderData<MaterialLightingState_t> rdLightingState; // [esp+Ch] [ebp-28h] BYREF
  unsigned __int8 *pFlags; // [esp+1Ch] [ebp-18h]
  CModelRenderSystem *v25; // [esp+20h] [ebp-14h]
  int nSetupCount; // [esp+24h] [ebp-10h]
  CModelRenderSystem::ModelListByType_t **ppLists; // [esp+28h] [ebp-Ch]
  StaticLightingQuery_t *pLightingQuery; // [esp+2Ch] [ebp-8h]
  int i; // [esp+30h] [ebp-4h]

  v3 = *(_DWORD *)(lightingList + 4);
  v25 = this;
  if ( v3 == 0 )
    return 0;
  v5 = alloca(4 * v3);
  v6 = v22;
  ppLists = v22;
  v7 = alloca(v3);
  pFlags = (unsigned __int8 *)v22;
  v8 = CModelRenderSystem::BuildLightingList(
         this,
         ppLists: v22,
         pFlags: (unsigned __int8 *)v22,
         pTotalModels: &lightingList,
         (const CModelRenderSystem::LightingList_t *)lightingList);
  nSetupCount = v8;
  if ( v8 == 0 )
    return 0;
  v9 = lightingList;
  v10 = alloca(20 * lightingList);
  v11 = 0;
  pLightingQuery = (StaticLightingQuery_t *)v22;
  lightingList = 0;
  i = 0;
  if ( v8 > 0 )
  {
    while ( 1 )
    {
      v12 = v6[v11];
      v13 = 0;
      if ( v12->m_nCount > 0 )
      {
        v14 = 0;
        v15 = &v22[5 * lightingList + 3];
        do
        {
          m_pRenderable = (CModelRenderSystem::ModelListByType_t *)v12->m_pRenderModels[v14].m_Entry.m_pRenderable;
          ++lightingList;
          v15[1] = m_pRenderable;
          *(_WORD *)v15 = v12->m_pRenderModels[v14].m_hInstance;
          *((_BYTE *)v15 + 2) = 0;
          ++v13;
          ++v14;
          v15 += 5;
        }
        while ( v13 < v12->m_nCount );
        v8 = nSetupCount;
        v11 = i;
      }
      i = ++v11;
      if ( v11 >= v8 )
        break;
      v6 = ppLists;
    }
  }
  staticpropmgr->GetLightingOrigins(
    this: staticpropmgr,
    a2: (Vector *)v22,
    a3: 20,
    a4: v9,
    a5: (IClientRenderable **)&rdLightingState.m_pRenderData,
    a6: 20);
  v17 = alloca(4 * v9);
  lightingList = (int)v22;
  v18 = alloca(4 * v9);
  m_pRenderContext = v25->m_pRenderContext;
  LockRenderData = m_pRenderContext->LockRenderData;
  i = (int)v22;
  rdLightingState.m_pRenderContext = m_pRenderContext;
  v21 = (MaterialLightingState_t *)((int (__stdcall *)(int))LockRenderData)(a1: 880 * v9);
  memset(dst: (int)v21, value: nullptr, count: 880 * v9);
  modelrender->ComputeStaticLightingState(
    this: modelrender,
    a2: v9,
    a3: pLightingQuery,
    a4: v21,
    a5: &v21[v9],
    a6: (ColorMeshInfo_t **)lightingList,
    a7: (ITexture **)i,
    a8: pColorMeshHandle);
  CModelRenderSystem::HookUpStaticLightingState(
    this: v25,
    nCount: nSetupCount,
    ppLists,
    pFlags,
    ppEnvCubemap: (ITexture **)i,
    pLightingState: v21,
    pDecalLightingState: &v21[v9],
    ppColorMeshInfo: (ColorMeshInfo_t **)lightingList);
  if ( v21 != nullptr )
    rdLightingState.m_pRenderContext->UnlockRenderData(this: rdLightingState.m_pRenderContext, a2: (void *)v21);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10124020
// Name: private: void CModelRenderSystem::SetupStandardLighting(struct CModelRenderSystem::LightingList_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::SetupStandardLighting(
        CModelRenderSystem *this,
        CModelRenderSystem::LightingList_t *lightingList)
{
  int m_nCount; // esi
  void *v4; // esp
  void *v5; // esp
  int v6; // esi
  void *v7; // esp
  unsigned int v8; // ebx
  IMatRenderContext *m_pRenderContext; // ecx
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  int v11; // edi
  CModelRenderSystem::ModelListByType_t *v12; // ebx
  void *v13; // esp
  MaterialLightingState_t *m_pRenderData; // edi
  CModelRenderSystem::ModelListByType_t **v15; // ebx
  int v16; // ecx
  CModelRenderSystem::ModelListByType_t *v17; // eax
  int v18; // edx
  int v19; // edi
  ITexture *m_pTexture; // esi
  int v21; // esi
  MaterialLightingState_t *v22; // ecx
  int v23; // edx
  int v24; // eax
  CModelRenderSystem::ModelListByType_t *v25[3]; // [esp+0h] [ebp-34h] BYREF
  CMatRenderData<MaterialLightingState_t> rdLightingState; // [esp+Ch] [ebp-28h]
  int v27; // [esp+1Ch] [ebp-18h]
  unsigned __int8 *pFlags; // [esp+20h] [ebp-14h]
  CModelRenderSystem *v29; // [esp+24h] [ebp-10h]
  CModelRenderSystem::ModelListByType_t **ppLists; // [esp+28h] [ebp-Ch]
  int i; // [esp+2Ch] [ebp-8h]
  MaterialLightingState_t *pCurrState; // [esp+30h] [ebp-4h] BYREF
  int nSetupCount; // [esp+3Ch] [ebp+8h]

  m_nCount = lightingList->m_nCount;
  v29 = this;
  if ( m_nCount != 0 )
  {
    v4 = alloca(4 * m_nCount);
    ppLists = v25;
    v5 = alloca(m_nCount);
    v6 = 0;
    pFlags = (unsigned __int8 *)v25;
    pCurrState = nullptr;
    nSetupCount = CModelRenderSystem::BuildLightingList(
                    this,
                    ppLists: v25,
                    pFlags: (unsigned __int8 *)v25,
                    pTotalModels: (int *)&pCurrState,
                    lightingList);
    if ( nSetupCount != 0 )
    {
      v7 = alloca(16 * (_DWORD)pCurrState);
      v8 = 440 * (_DWORD)pCurrState;
      m_pRenderContext = this->m_pRenderContext;
      LockRenderData = m_pRenderContext->LockRenderData;
      i = (int)v25;
      rdLightingState.m_pRenderContext = m_pRenderContext;
      v27 = 440 * (_DWORD)pCurrState;
      v11 = 0;
      rdLightingState.m_pRenderData = (MaterialLightingState_t *)((int (__stdcall *)(int))LockRenderData)(a1: 440 * (_DWORD)pCurrState);
      if ( nSetupCount > 0 )
      {
        do
        {
          v12 = ppLists[v11];
          CModelRenderSystem::ComputeLightingOrigin(
            this: v29,
            list: v12,
            pLightingQueryBase: (LightingQuery_t *)(i + 16 * v6),
            nQueryStride: 16);
          v6 += v12->m_nCount;
          ++v11;
        }
        while ( v11 < nSetupCount );
        v8 = v27;
      }
      memset(dst: (int)rdLightingState.m_pRenderData, value: nullptr, count: v8);
      v13 = alloca(4 * (_DWORD)pCurrState);
      m_pRenderData = rdLightingState.m_pRenderData;
      v15 = v25;
      modelrender->ComputeLightingState(
        this: modelrender,
        a2: (int)pCurrState,
        a3: (const LightingQuery_t *)i,
        a4: rdLightingState.m_pRenderData,
        a5: (ITexture **)v25);
      v16 = 0;
      pCurrState = m_pRenderData;
      i = 0;
      if ( nSetupCount > 0 )
      {
        do
        {
          v17 = ppLists[v16];
          if ( (pFlags[v16] & 1) != 0 )
          {
            v18 = 0;
            if ( v17->m_nCount > 0 )
            {
              v19 = 0;
              do
              {
                m_pTexture = (ITexture *)v15[v18];
                if ( m_pTexture == nullptr )
                  m_pTexture = v29->m_DefaultCubemap.m_pTexture;
                v17->m_pRenderModels[v19].m_pEnvCubemapTexture = m_pTexture;
                ++v18;
                ++v19;
              }
              while ( v18 < v17->m_nCount );
              v16 = i;
            }
          }
          if ( (pFlags[v16] & 2) != 0 )
          {
            v21 = 0;
            if ( v17->m_nCount > 0 )
            {
              v22 = pCurrState;
              v23 = 0;
              do
              {
                v17->m_pRenderModels[v23].m_pLightingState = v22;
                ++v21;
                ++v22;
                ++v23;
              }
              while ( v21 < v17->m_nCount );
              v16 = i;
            }
          }
          v24 = v17->m_nCount;
          v15 += v24;
          pCurrState += v24;
          i = ++v16;
        }
        while ( v16 < nSetupCount );
        m_pRenderData = rdLightingState.m_pRenderData;
      }
      if ( m_pRenderData != nullptr )
        rdLightingState.m_pRenderContext->UnlockRenderData(
          this: rdLightingState.m_pRenderContext,
          a2: (void *)m_pRenderData);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101241E0
// Name: private: int CModelRenderSystem::SetupPhysicsPropLighting(struct CModelRenderSystem::LightingList_t __near &,struct memhandle_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelRenderSystem::SetupPhysicsPropLighting(
        CModelRenderSystem *this,
        CModelRenderSystem::LightingList_t *lightingList,
        memhandle_t__ **pColorMeshHandle)
{
  int m_nCount; // edi
  void *v5; // esp
  CModelRenderSystem::ModelListByType_t **v6; // esi
  void *v7; // esp
  int v8; // ebx
  void *v9; // esp
  int v10; // edi
  CModelRenderSystem::ModelListByType_t *v11; // esi
  int v12; // eax
  int v13; // ecx
  LightingQuery_t *p_m_pRenderable; // edx
  void *v15; // esp
  void *v16; // esp
  IMatRenderContext *m_pRenderContext; // ecx
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // edx
  MaterialLightingState_t *v19; // edi
  ColorMeshInfo_t *v20[3]; // [esp+0h] [ebp-38h] BYREF
  CMatRenderData<MaterialLightingState_t> rdLightingState; // [esp+Ch] [ebp-2Ch]
  unsigned __int8 *pFlags; // [esp+1Ch] [ebp-1Ch]
  StaticLightingQuery_t *v23; // [esp+20h] [ebp-18h]
  CModelRenderSystem::ModelListByType_t **ppLists; // [esp+24h] [ebp-14h]
  StaticLightingQuery_t *pLightingQuery; // [esp+28h] [ebp-10h]
  CModelRenderSystem *v26; // [esp+2Ch] [ebp-Ch]
  int nSetupCount; // [esp+30h] [ebp-8h]
  ITexture **ppEnvCubemap; // [esp+34h] [ebp-4h] BYREF
  int i; // [esp+40h] [ebp+8h]

  m_nCount = lightingList->m_nCount;
  v26 = this;
  if ( m_nCount == 0 )
    return 0;
  v5 = alloca(4 * m_nCount);
  v6 = (CModelRenderSystem::ModelListByType_t **)v20;
  ppLists = (CModelRenderSystem::ModelListByType_t **)v20;
  v7 = alloca(m_nCount);
  pFlags = (unsigned __int8 *)v20;
  ppEnvCubemap = nullptr;
  nSetupCount = CModelRenderSystem::BuildLightingList(
                  this,
                  ppLists: (CModelRenderSystem::ModelListByType_t **)v20,
                  pFlags: (unsigned __int8 *)v20,
                  pTotalModels: (int *)&ppEnvCubemap,
                  lightingList);
  if ( nSetupCount == 0 )
    return 0;
  v8 = (int)ppEnvCubemap;
  v9 = alloca(20 * (_DWORD)ppEnvCubemap);
  v10 = 0;
  pLightingQuery = (StaticLightingQuery_t *)v20;
  i = 0;
  if ( nSetupCount > 0 )
  {
    while ( 1 )
    {
      v11 = v6[i];
      v23 = &pLightingQuery[v10];
      CModelRenderSystem::ComputeLightingOrigin(this: v26, list: v11, pLightingQueryBase: v23, nQueryStride: 20);
      v12 = 0;
      if ( v11->m_nCount > 0 )
      {
        v13 = 0;
        p_m_pRenderable = (LightingQuery_t *)&v23->m_pRenderable;
        do
        {
          LODWORD(p_m_pRenderable->m_LightingOrigin.x) = v11->m_pRenderModels[v13].m_Entry.m_pRenderable;
          ++v12;
          ++v13;
          ++v10;
          p_m_pRenderable = (LightingQuery_t *)((char *)p_m_pRenderable + 20);
        }
        while ( v12 < v11->m_nCount );
        v8 = (int)ppEnvCubemap;
      }
      if ( ++i >= nSetupCount )
        break;
      v6 = ppLists;
    }
  }
  v15 = alloca(4 * v8);
  v16 = alloca(4 * v8);
  m_pRenderContext = v26->m_pRenderContext;
  LockRenderData = m_pRenderContext->LockRenderData;
  ppEnvCubemap = (ITexture **)v20;
  rdLightingState.m_pRenderContext = m_pRenderContext;
  v19 = (MaterialLightingState_t *)((int (__stdcall *)(int))LockRenderData)(a1: 880 * v8);
  modelrender->ComputeStaticLightingState(
    this: modelrender,
    a2: v8,
    a3: pLightingQuery,
    a4: v19,
    a5: &v19[v8],
    a6: v20,
    a7: ppEnvCubemap,
    a8: pColorMeshHandle);
  CModelRenderSystem::HookUpStaticLightingState(
    this: v26,
    nCount: nSetupCount,
    ppLists,
    pFlags,
    ppEnvCubemap,
    pLightingState: v19,
    pDecalLightingState: &v19[v8],
    ppColorMeshInfo: v20);
  if ( v19 != nullptr )
    rdLightingState.m_pRenderContext->UnlockRenderData(this: rdLightingState.m_pRenderContext, a2: (void *)v19);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10124370
// Name: private: int CModelRenderSystem::SetupLighting(struct CModelRenderSystem::LightingList_t __near *,int,struct CModelRenderSystem::ModelListByType_t __near *,struct memhandle_t__ __near * __near *,enum ModelRenderMode_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelRenderSystem::SetupLighting(
        CModelRenderSystem *this,
        CModelRenderSystem::LightingList_t *pLightingList,
        memhandle_t__ **nModelTypeCount,
        CModelRenderSystem::ModelListByType_t *pModelList,
        memhandle_t__ **pColorMeshHandles,
        int renderMode)
{
  int *p_m_nCount; // esi
  int v9; // edi
  int v10; // ebx
  memhandle_t__ **pColorMeshHandlesa; // [esp+1Ch] [ebp+14h]
  int nCounta; // [esp+20h] [ebp+18h]
  int nCount; // [esp+20h] [ebp+18h]

  if ( renderMode != 0 )
    return 0;
  nCounta = CModelRenderSystem::SetupStaticPropLighting(
              this,
              lightingList: (int)&pLightingList[1],
              pColorMeshHandle: pColorMeshHandles);
  CModelRenderSystem::SetupStandardLighting(this, lightingList: pLightingList);
  nCount = CModelRenderSystem::SetupPhysicsPropLighting(
             this,
             lightingList: pLightingList + 2,
             pColorMeshHandle: &pColorMeshHandles[nCounta])
         + nCounta;
  if ( r_drawmodellightorigin.m_pParent != nullptr
    && r_drawmodellightorigin.m_pParent->m_Value.m_nValue != 0
    && (int)nModelTypeCount > 0 )
  {
    p_m_nCount = &pModelList->m_nCount;
    for ( pColorMeshHandlesa = nModelTypeCount;
          pColorMeshHandlesa != nullptr;
          pColorMeshHandlesa = (memhandle_t__ **)((char *)pColorMeshHandlesa - 1) )
    {
      if ( *(p_m_nCount - 3) != -1 )
      {
        v9 = 0;
        if ( *p_m_nCount > 0 )
        {
          v10 = 0;
          do
          {
            CModelRenderSystem::DebugDrawLightingOrigin(
              this,
              list: (const CModelRenderSystem::ModelListByType_t *)(p_m_nCount - 7),
              model: (const CModelRenderSystem::RenderModelInfo_t *)(v10 + p_m_nCount[3]));
            ++v9;
            v10 += 92;
          }
          while ( v9 < *p_m_nCount );
        }
      }
      p_m_nCount += 12;
    }
  }
  return nCount;
}

//------------------------------------------------------------------------------
// Address: 0x10124420
// Name: private: void CModelRenderSystem::SetupFlashlightsAndDecals(struct StudioModelArrayInfo2_t __near *,int,struct CModelRenderSystem::ModelListByType_t __near *,int,struct CModelRenderSystem::RenderModelInfo_t __near *,enum ModelRenderMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::SetupFlashlightsAndDecals(
        CModelRenderSystem *this,
        StudioModelArrayInfo2_t *pInfo,
        ModelRenderMode_t nModelTypeCount,
        CModelRenderSystem::ModelListByType_t *pModelList,
        int nTotalModelCount,
        CModelRenderSystem::RenderModelInfo_t *pRenderModels,
        ModelRenderMode_t renderMode)
{
  int v7; // ebx
  int v8; // esi
  void *v9; // esp
  int *p_m_nCount; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  IMatRenderContext *m_pRenderContext; // ebx
  FlashlightInstance_t *v15; // edi
  int m_nFlashlightCount; // eax
  int v17; // ecx
  CModelRenderSystem::ModelListByType_t *v18; // eax
  _WORD v19[6]; // [esp+0h] [ebp-50h] BYREF
  unsigned __int16 pFlashlights[32]; // [esp+Ch] [ebp-44h] BYREF
  CModelRenderSystem *v21; // [esp+4Ch] [ebp-4h]
  ModelRenderMode_t renderModea; // [esp+6Ch] [ebp+1Ch]

  v21 = this;
  if ( renderMode == MODEL_RENDER_MODE_NORMAL )
  {
    v7 = nTotalModelCount;
    v8 = 0;
    v9 = alloca(2 * nTotalModelCount);
    if ( nModelTypeCount > MODEL_RENDER_MODE_NORMAL )
    {
      p_m_nCount = &pModelList->m_nCount;
      for ( renderModea = nModelTypeCount; renderModea != MODEL_RENDER_MODE_NORMAL; --renderModea )
      {
        v11 = 0;
        if ( *p_m_nCount > 0 )
        {
          v12 = 0;
          do
          {
            v19[v8] = *(_WORD *)(v12 + p_m_nCount[3] + 80);
            ++v11;
            ++v8;
            v12 += 92;
          }
          while ( v11 < *p_m_nCount );
          v7 = nTotalModelCount;
        }
        p_m_nCount += 12;
      }
    }
    if ( v7 != v8 )
    {
      DevWarning(
        a1: "CModelRenderSystem::SetupFlashlightsAndDecals sorted model list count incorrect! A model was probably unable to load!\n");
      v7 = v8;
    }
    modelrender->GetModelDecalHandles(this: modelrender, a2: &pRenderModels->m_Decals, a3: 92, a4: v7, a5: v19);
    v13 = shadowmgr->SetupFlashlightRenderInstanceInfo(
            this: shadowmgr,
            a2: pFlashlights,
            a3: &pRenderModels->m_nFlashlightUsage,
            a4: 92,
            a5: v7,
            a6: v19);
    pInfo->m_nFlashlightCount = v13;
    if ( v13 != 0 )
    {
      m_pRenderContext = v21->m_pRenderContext;
      v15 = (FlashlightInstance_t *)m_pRenderContext->LockRenderData(this: m_pRenderContext, a2: 324 * v13);
      m_nFlashlightCount = pInfo->m_nFlashlightCount;
      pInfo->m_pFlashlights = v15;
      shadowmgr->GetFlashlightRenderInfo(this: shadowmgr, a2: v15, a3: m_nFlashlightCount, a4: pFlashlights);
      if ( v15 != nullptr )
        m_pRenderContext->UnlockRenderData(this: m_pRenderContext, a2: v15);
    }
    else
    {
      pInfo->m_pFlashlights = nullptr;
    }
    v17 = nModelTypeCount;
    if ( nModelTypeCount > MODEL_RENDER_MODE_NORMAL )
    {
      v18 = pModelList;
      do
      {
        v18->StudioModelArrayInfo2_t = *pInfo;
        ++v18;
        --v17;
      }
      while ( v17 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124550
// Name: private: void CModelRenderSystem::RenderModels(struct StudioModelArrayInfo2_t __near *,int,struct CModelRenderSystem::ModelListByType_t __near *,int,enum ModelRenderMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::RenderModels(
        CModelRenderSystem *this,
        StudioModelArrayInfo2_t *pInfo,
        int nModelTypeCount,
        CModelRenderSystem::ModelListByType_t *pModelList,
        int nTotalModelCount,
        ModelRenderMode_t renderMode)
{
  IMatRenderContext *m_pRenderContext; // ebx
  int v8; // eax
  StudioArrayData_t *v9; // esi
  _DWORD *v10; // ecx
  studiohwdata_t **v11; // eax
  int j; // edx
  int v13; // eax
  _DWORD *v14; // ecx
  studiohwdata_t **p_m_pHardwareData; // eax
  int i; // edx

  if ( renderMode != MODEL_RENDER_MODE_NORMAL )
  {
    if ( renderMode == MODEL_RENDER_MODE_SHADOW_DEPTH )
    {
      m_pRenderContext = this->m_pRenderContext;
      v13 = (int)m_pRenderContext->LockRenderData(this: m_pRenderContext, a2: 16 * nModelTypeCount);
      v9 = (StudioArrayData_t *)v13;
      if ( nModelTypeCount > 0 )
      {
        v14 = (_DWORD *)(v13 + 8);
        p_m_pHardwareData = &pModelList->m_pHardwareData;
        for ( i = nModelTypeCount; i != 0; --i )
        {
          *(v14 - 2) = *(p_m_pHardwareData - 1);
          *(v14 - 1) = *p_m_pHardwareData;
          *v14 = p_m_pHardwareData[7];
          v14[1] = p_m_pHardwareData[4];
          p_m_pHardwareData += 12;
          v14 += 4;
        }
      }
      g_pStudioRender->DrawModelShadowArray(this: g_pStudioRender, a2: nModelTypeCount, a3: v9, a4: 92, a5: 513);
      if ( v9 != nullptr )
        goto LABEL_15;
    }
  }
  else
  {
    if ( cl_colorfastpath.m_pParent != nullptr && cl_colorfastpath.m_pParent->m_Value.m_nValue != 0 )
      g_pStudioRender->ForcedMaterialOverride(
        this: g_pStudioRender,
        a2: this->m_DebugMaterial.m_pMaterial,
        a3: OVERRIDE_NORMAL);
    m_pRenderContext = this->m_pRenderContext;
    v8 = (int)m_pRenderContext->LockRenderData(this: m_pRenderContext, a2: 16 * nModelTypeCount);
    v9 = (StudioArrayData_t *)v8;
    if ( nModelTypeCount > 0 )
    {
      v10 = (_DWORD *)(v8 + 8);
      v11 = &pModelList->m_pHardwareData;
      for ( j = nModelTypeCount; j != 0; --j )
      {
        *(v10 - 2) = *(v11 - 1);
        *(v10 - 1) = *v11;
        *v10 = v11[7];
        v10[1] = v11[4];
        v11 += 12;
        v10 += 4;
      }
    }
    g_pStudioRender->DrawModelArray(this: g_pStudioRender, a2: pInfo, a3: nModelTypeCount, a4: v9, a5: 92, a6: 1);
    g_pStudioRender->ForcedMaterialOverride(this: g_pStudioRender, a2: nullptr, a3: OVERRIDE_NORMAL);
    if ( v9 != nullptr )
LABEL_15:
      m_pRenderContext->UnlockRenderData(this: m_pRenderContext, a2: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101246B0
// Name: private: void CModelRenderSystem::SetupTranslucentData(int,struct CModelRenderSystem::ModelListByType_t __near *,int,struct TranslucentInstanceRenderData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::SetupTranslucentData(
        CModelRenderSystem *this,
        int nModelTypeCount,
        CModelRenderSystem::ModelListByType_t *pModelList,
        int nTotalModelCount,
        TranslucentInstanceRenderData_t *pRenderData)
{
  int v7; // eax
  IMatRenderContext *m_pRenderContext; // esi
  int v9; // eax
  int v10; // ecx
  _QWORD *v11; // edx
  int *p_m_nCount; // ebx
  char *i; // ecx
  _DWORD *v14; // edx
  StudioArrayInstanceData_t *v15; // eax
  TranslucentInstanceRenderData_t *v16; // ecx
  bool v17; // zf
  IMatRenderContext *instanceData; // [esp+Ch] [ebp-2Ch]
  int instanceData_4; // [esp+10h] [ebp-28h]
  IMatRenderContext *arrayInfo; // [esp+1Ch] [ebp-1Ch]
  _QWORD *arrayInfo_4; // [esp+20h] [ebp-18h]
  char *v22; // [esp+2Ch] [ebp-Ch]
  int v23; // [esp+30h] [ebp-8h]
  _QWORD *v24; // [esp+34h] [ebp-4h]
  int nCurInstance; // [esp+40h] [ebp+8h]
  int j; // [esp+44h] [ebp+Ch]
  int nTotalModelCounta; // [esp+48h] [ebp+10h]

  memset(dst: (int)pRenderData, value: nullptr, count: 8 * nTotalModelCount);
  arrayInfo = this->m_pRenderContext;
  v7 = ((int (__stdcall *)(int))arrayInfo->LockRenderData)(a1: 16 * nModelTypeCount);
  m_pRenderContext = this->m_pRenderContext;
  arrayInfo_4 = (_QWORD *)v7;
  instanceData = m_pRenderContext;
  v9 = (int)m_pRenderContext->LockRenderData(this: m_pRenderContext, a2: 68 * nTotalModelCount);
  v10 = 0;
  instanceData_4 = v9;
  nCurInstance = 0;
  if ( nModelTypeCount > 0 )
  {
    v11 = arrayInfo_4;
    v24 = arrayInfo_4;
    p_m_nCount = &pModelList->m_nCount;
    v23 = nModelTypeCount;
    do
    {
      *v11 = *(_QWORD *)(p_m_nCount - 7);
      v11[1] = *(_QWORD *)(p_m_nCount - 5);
      j = 0;
      if ( *p_m_nCount > 0 )
      {
        nTotalModelCounta = 0;
        for ( i = (char *)(v9 + 68 * v10); ; i = v22 )
        {
          v14 = (_DWORD *)(nTotalModelCounta + p_m_nCount[3]);
          ++nCurInstance;
          nTotalModelCounta += 92;
          v15 = (StudioArrayInstanceData_t *)i;
          v22 = i + 68;
          qmemcpy(i, v14, 0x44u);
          v16 = &pRenderData[v14[22] & 0xFFFFFF];
          v11 = v24;
          v16->m_pInstanceData = v15;
          v16->m_pModelInfo = (StudioModelArrayInfo_t *)v24;
          if ( ++j >= *p_m_nCount )
            break;
        }
        v9 = instanceData_4;
        m_pRenderContext = instanceData;
        v10 = nCurInstance;
      }
      v11 += 2;
      p_m_nCount += 12;
      v17 = v23-- == 1;
      v24 = v11;
    }
    while ( !v17 );
  }
  if ( v9 != 0 )
    m_pRenderContext->UnlockRenderData(this: m_pRenderContext, a2: (void *)v9);
  if ( arrayInfo_4 != nullptr )
    arrayInfo->UnlockRenderData(this: arrayInfo, a2: arrayInfo_4);
}

//------------------------------------------------------------------------------
// Address: 0x101247F0
// Name: public: virtual void CModelRenderSystem::CleanupTranslucentTempData(struct TranslucentTempData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::CleanupTranslucentTempData(
        CModelRenderSystem *this,
        TranslucentTempData_t *pTempData)
{
  IMatRenderContext *v2; // esi

  if ( pTempData->m_bReleaseRenderData )
  {
    modelrender->CleanupStaticLightingState(
      this: modelrender,
      a2: pTempData->m_nColorMeshHandleCount,
      a3: pTempData->m_pColorMeshHandles);
    v2 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    if ( v2 != nullptr )
      v2->BeginRender(this: v2);
    v2->ReleaseRenderData(this: v2);
    v2->EndRender(this: v2);
    v2->Release(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124860
// Name: private: void CModelRenderSystem::AddBrushModelToList(int,struct ModelRenderSystemData_t __near &,enum ModelRenderMode_t,struct BrushArrayInstanceData_t __near &,class matrix3x4a_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::AddBrushModelToList(
        CModelRenderSystem *this,
        int nInitialListIndex,
        ModelRenderSystemData_t *data,
        ModelRenderMode_t renderMode,
        BrushArrayInstanceData_t *instance,
        matrix3x4a_t *brushToWorld)
{
  const struct model_t *v6; // ebx
  IClientModelRenderable *m_pModelRenderable; // esi
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // eax
  ShaderStencilState_t *v9; // eax
  IVModelInfoClient_vtbl *v10; // edx
  const char *v11; // eax
  ShaderStencilState_t tempStencil; // [esp+Ch] [ebp-34h] BYREF
  CMatRenderData<ShaderStencilState_t> rdStencil; // [esp+2Ch] [ebp-14h] BYREF
  CModelRenderSystem *v14; // [esp+3Ch] [ebp-4h]

  v14 = this;
  v6 = data->m_pRenderable->GetModel(this: data->m_pRenderable);
  *brushToWorld = (matrix3x4a_t)*data->m_pRenderable->RenderableToWorldTransform(this: data->m_pRenderable);
  instance->m_pBrushToWorld = brushToWorld;
  instance->m_pBrushModel = v6;
  instance->m_pStencilState = nullptr;
  if ( data->m_pModelRenderable != nullptr )
  {
    if ( renderMode == MODEL_RENDER_MODE_NORMAL )
    {
      m_pModelRenderable = data->m_pModelRenderable;
      tempStencil.m_bEnable = false;
      tempStencil.m_nReferenceValue = 0;
      tempStencil.m_ZFailOp = SHADER_STENCILOP_KEEP;
      tempStencil.m_FailOp = SHADER_STENCILOP_KEEP;
      tempStencil.m_PassOp = SHADER_STENCILOP_KEEP;
      tempStencil.m_CompareFunc = SHADER_STENCILFUNC_ALWAYS;
      tempStencil.m_nWriteMask = -1;
      tempStencil.m_nTestMask = -1;
      if ( m_pModelRenderable->GetRenderData(this: m_pModelRenderable, a2: &tempStencil, a3: MODEL_DATA_STENCIL) != 0 )
      {
        LockRenderData = v14->m_pRenderContext->LockRenderData;
        rdStencil.m_pRenderContext = v14->m_pRenderContext;
        rdStencil.m_nCount = 1;
        v9 = (ShaderStencilState_t *)((int (__stdcall *)(int))LockRenderData)(a1: 32);
        *v9 = tempStencil;
        rdStencil.m_pRenderData = v9;
        rdStencil.m_bNeedsUnlock = true;
        instance->m_pStencilState = v9;
        CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: (CMatRenderData<CModelRenderSystem::RenderModelInfo_t> *)&rdStencil);
      }
    }
  }
  else if ( _executeCount_0 < 1 )
  {
    v10 = modelinfo->__vftable;
    ++_executeCount_0;
    v11 = v10->GetModelName(this: modelinfo, a2: v6);
    DevWarning(a1: "data.m_pModelRenderable is NULL for %s\n", v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101249B0
// Name: public: virtual void CModelRenderSystem::DrawBrushModels(struct ModelRenderSystemData_t __near *,int,enum ModelRenderMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::DrawBrushModels(
        CModelRenderSystem *this,
        ModelRenderSystemData_t *pModels,
        int nCount,
        ModelRenderMode_t renderMode)
{
  ITexture *v6; // edi
  int v7; // eax
  int v8; // edi
  ITexture *rdMatrices; // [esp+8h] [ebp-2Ch]
  int rdMatrices_4; // [esp+Ch] [ebp-28h]
  ITexture *rdInstances; // [esp+18h] [ebp-1Ch]
  BrushArrayInstanceData_t *rdInstances_4; // [esp+1Ch] [ebp-18h]
  CMatRenderContextPtr matRenderContext; // [esp+28h] [ebp-Ch]
  ModelRenderSystemData_t *data; // [esp+2Ch] [ebp-8h]
  BrushArrayInstanceData_t *instance; // [esp+30h] [ebp-4h]
  matrix3x4a_t *nCounta; // [esp+40h] [ebp+Ch]

  if ( nCount != 0 && (cl_skipfastpath.m_pParent == nullptr || cl_skipfastpath.m_pParent->m_Value.m_nValue == 0) )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CModelRenderSystem::DrawBrushModels",
      a3: 0,
      a4: "Fast Path Brush Rendering",
      a5: false,
      a6: 4);
    v6 = (ITexture *)g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    matRenderContext.m_pObject = (IMatRenderContext *)v6;
    if ( v6 != nullptr )
      v6->GetMappingHeight(this: v6);
    this->m_DefaultCubemap.m_pTexture = v6;
    v6->__vftable[3].GetActualHeight(this: v6);
    rdInstances = this->m_DefaultCubemap.m_pTexture;
    rdInstances_4 = (BrushArrayInstanceData_t *)((int (__stdcall *)(int))rdInstances->__vftable[3].GetMappingHeight)(a1: 28 * nCount);
    rdMatrices = this->m_DefaultCubemap.m_pTexture;
    v7 = ((int (__stdcall *)(int))rdMatrices->__vftable[3].GetMappingHeight)(a1: 48 * nCount);
    v8 = 0;
    rdMatrices_4 = v7;
    if ( nCount > 0 )
    {
      data = pModels;
      instance = rdInstances_4;
      nCounta = (matrix3x4a_t *)v7;
      do
        CModelRenderSystem::AddBrushModelToList(
          this: (CModelRenderSystem *)((char *)this - 12),
          nInitialListIndex: v8++,
          data: data++,
          renderMode,
          instance: instance++,
          brushToWorld: nCounta++);
      while ( v8 < nCount );
    }
    CModelRenderSystem::SetupPerInstanceColorModulation(
      this: (CModelRenderSystem *)((char *)this - 12),
      nCount,
      pModels,
      pInstanceData: rdInstances_4,
      renderMode);
    ((void (__thiscall *)(IVRenderView *, ITexture *, int, BrushArrayInstanceData_t *))render->DrawBrushModelArray)(
      a1: render,
      a2: this->m_DefaultCubemap.m_pTexture,
      a3: nCount,
      a4: rdInstances_4);
    ((void (__thiscall *)(CMatRenderContextPtr))matRenderContext.m_pObject->ReleaseRenderData)(a1: matRenderContext);
    this->m_DefaultCubemap.m_pTexture = nullptr;
    if ( rdMatrices_4 != 0 )
      ((void (__thiscall *)(ITexture *, int))rdMatrices->__vftable[3].GetActualWidth)(a1: rdMatrices, a2: rdMatrices_4);
    if ( rdInstances_4 != nullptr )
      ((void (__thiscall *)(ITexture *, BrushArrayInstanceData_t *))rdInstances->__vftable[3].GetActualWidth)(
        a1: rdInstances,
        a2: rdInstances_4);
    ((void (__thiscall *)(CMatRenderContextPtr))matRenderContext.m_pObject->EndRender)(a1: matRenderContext);
    ((void (__thiscall *)(CMatRenderContextPtr))matRenderContext.m_pObject->Release)(a1: matRenderContext);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124B50
// Name: void std::_Median<struct CModelRenderSystem::ModelListByType_t __near *,bool (*)(struct CModelRenderSystem::ModelListByType_t const __near &,struct CModelRenderSystem::ModelListByType_t const __near &)>(struct CModelRenderSystem::ModelListByType_t __near *,struct CModelRenderSystem::ModelListByType_t __near *,struct CModelRenderSystem::ModelListByType_t __near *,bool (*)(struct CModelRenderSystem::ModelListByType_t const __near &,struct CModelRenderSystem::ModelListByType_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Median<CModelRenderSystem::ModelListByType_t *,bool (__cdecl *)(CModelRenderSystem::ModelListByType_t const &,CModelRenderSystem::ModelListByType_t const &)>(
        CModelRenderSystem::ModelListByType_t *_First,
        CModelRenderSystem::ModelListByType_t *_Mid,
        CModelRenderSystem::ModelListByType_t *_Last,
        bool (__cdecl *_Pred)(const CModelRenderSystem::ModelListByType_t *, const CModelRenderSystem::ModelListByType_t *))
{
  int v4; // eax
  int v5; // eax
  unsigned int v6; // edi
  const CModelRenderSystem::ModelListByType_t *v7; // eax
  CModelRenderSystem::ModelListByType_t *v8; // edi
  unsigned int v9; // [esp+Ch] [ebp-8h]
  CModelRenderSystem::ModelListByType_t *_Left; // [esp+10h] [ebp-4h]
  CModelRenderSystem::ModelListByType_t *_Firsta; // [esp+1Ch] [ebp+8h]
  CModelRenderSystem::ModelListByType_t *_Firstb; // [esp+1Ch] [ebp+8h]

  v4 = _Last - _First;
  if ( v4 <= 40 )
  {
    if ( _Pred(a1: _Mid, a2: _First) )
      std::swap<CModelRenderSystem::ModelListByType_t>(_Left: _Mid, _Right: _First);
    if ( _Pred(a1: _Last, a2: _Mid) )
      std::swap<CModelRenderSystem::ModelListByType_t>(_Left: _Last, _Right: _Mid);
    if ( _Pred(a1: _Mid, a2: _First) )
      std::swap<CModelRenderSystem::ModelListByType_t>(_Left: _Mid, _Right: _First);
  }
  else
  {
    v5 = v4 + 1;
    v6 = 48 * (v5 / 8);
    v9 = 96 * (v5 / 8);
    _Left = &_First[v6 / 0x30];
    if ( _Pred(a1: &_First[v6 / 0x30], a2: _First) )
      std::swap<CModelRenderSystem::ModelListByType_t>(_Left, _Right: _First);
    if ( _Pred(a1: &_First[v9 / 0x30], a2: _Left) )
      std::swap<CModelRenderSystem::ModelListByType_t>(_Left: &_First[v9 / 0x30], _Right: _Left);
    if ( _Pred(a1: _Left, a2: _First) )
      std::swap<CModelRenderSystem::ModelListByType_t>(_Left, _Right: _First);
    _Firsta = &_Mid[v6 / 0xFFFFFFD0];
    if ( _Pred(a1: _Mid, a2: &_Mid[v6 / 0xFFFFFFD0]) )
      std::swap<CModelRenderSystem::ModelListByType_t>(_Left: _Mid, _Right: _Firsta);
    if ( _Pred(a1: &_Mid[v6 / 0x30], a2: _Mid) )
      std::swap<CModelRenderSystem::ModelListByType_t>(_Left: &_Mid[v6 / 0x30], _Right: _Mid);
    if ( _Pred(a1: _Mid, a2: _Firsta) )
      std::swap<CModelRenderSystem::ModelListByType_t>(_Left: _Mid, _Right: _Firsta);
    v7 = &_Last[v6 / 0xFFFFFFD0];
    v8 = &_Last[v9 / 0xFFFFFFD0];
    _Firstb = (CModelRenderSystem::ModelListByType_t *)v7;
    if ( _Pred(a1: v7, a2: &_Last[v9 / 0xFFFFFFD0]) )
      std::swap<CModelRenderSystem::ModelListByType_t>(_Left: _Firstb, _Right: v8);
    if ( _Pred(a1: _Last, a2: _Firstb) )
      std::swap<CModelRenderSystem::ModelListByType_t>(_Left: _Last, _Right: _Firstb);
    if ( _Pred(a1: _Firstb, a2: v8) )
      std::swap<CModelRenderSystem::ModelListByType_t>(_Left: _Firstb, _Right: v8);
    if ( _Pred(a1: _Mid, a2: _Left) )
      std::swap<CModelRenderSystem::ModelListByType_t>(_Left: _Mid, _Right: _Left);
    if ( _Pred(a1: _Firstb, a2: _Mid) )
      std::swap<CModelRenderSystem::ModelListByType_t>(_Left: _Firstb, _Right: _Mid);
    if ( _Pred(a1: _Mid, a2: _Left) )
      std::swap<CModelRenderSystem::ModelListByType_t>(_Left: _Mid, _Right: _Left);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124D50
// Name: void std::_Insertion_sort1<struct CModelRenderSystem::ModelListByType_t __near *,bool (*)(struct CModelRenderSystem::ModelListByType_t const __near &,struct CModelRenderSystem::ModelListByType_t const __near &),struct CModelRenderSystem::ModelListByType_t>(struct CModelRenderSystem::ModelListByType_t __near *,struct CModelRenderSystem::ModelListByType_t __near *,bool (*)(struct CModelRenderSystem::ModelListByType_t const __near &,struct CModelRenderSystem::ModelListByType_t const __near &),struct CModelRenderSystem::ModelListByType_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Insertion_sort1<CModelRenderSystem::ModelListByType_t *,bool (__cdecl *)(CModelRenderSystem::ModelListByType_t const &,CModelRenderSystem::ModelListByType_t const &),CModelRenderSystem::ModelListByType_t>(
        CModelRenderSystem::ModelListByType_t *_First,
        CModelRenderSystem::ModelListByType_t *_Last,
        bool (__cdecl *_Pred)(const CModelRenderSystem::ModelListByType_t *, const CModelRenderSystem::ModelListByType_t *))
{
  CModelRenderSystem::ModelListByType_t *v3; // esi
  CModelRenderSystem::ModelListByType_t *v4; // ebx
  CModelRenderSystem::ModelListByType_t *v5; // edi
  CModelRenderSystem::ModelListByType_t *i; // esi
  CModelRenderSystem::ModelListByType_t _Val; // [esp+4h] [ebp-34h] BYREF
  CModelRenderSystem::ModelListByType_t *v8; // [esp+34h] [ebp-4h]

  v3 = _First;
  if ( _First != _Last )
  {
    v4 = _First + 1;
    if ( &_First[1] != _Last )
    {
      v8 = _First;
      do
      {
        _Val = *v4;
        v5 = v4;
        if ( _Pred(a1: &_Val, a2: v3) )
        {
          std::_Move_backward<CModelRenderSystem::ModelListByType_t *,CModelRenderSystem::ModelListByType_t *>(
            _First: v3,
            _Last: v4,
            _Dest: v8 + 2);
          *v3 = _Val;
        }
        else
        {
          for ( i = v8; _Pred(a1: &_Val, a2: i); --i )
          {
            v5->StudioModelArrayInfo2_t = i->StudioModelArrayInfo2_t;
            *(_QWORD *)&v5->m_pStudioHdr = *(_QWORD *)&i->m_pStudioHdr;
            *(_QWORD *)&v5->m_nLightingModel = *(_QWORD *)&i->m_nLightingModel;
            *(_QWORD *)&v5->m_pFirstNode = *(_QWORD *)&i->m_pFirstNode;
            *(_QWORD *)&v5->m_nSetupBoneCount = *(_QWORD *)&i->m_nSetupBoneCount;
            *(_QWORD *)&v5->m_pRenderModels = *(_QWORD *)&i->m_pRenderModels;
            v5 = i;
          }
          v3 = _First;
          *v5 = _Val;
        }
        ++v8;
        ++v4;
      }
      while ( v4 != _Last );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124EF0
// Name: void std::_Adjust_heap<struct CModelRenderSystem::RenderModelInfo_t __near *,int,struct CModelRenderSystem::RenderModelInfo_t,bool (*)(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &)>(struct CModelRenderSystem::RenderModelInfo_t __near *,int,int,struct CModelRenderSystem::RenderModelInfo_t __near &&,bool (*)(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<CModelRenderSystem::RenderModelInfo_t *,int,CModelRenderSystem::RenderModelInfo_t,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
        CModelRenderSystem::RenderModelInfo_t *_First,
        int _Hole,
        int _Bottom,
        CModelRenderSystem::RenderModelInfo_t *_Val,
        bool (__cdecl *_Pred)(const CModelRenderSystem::RenderModelInfo_t *, const CModelRenderSystem::RenderModelInfo_t *))
{
  int v5; // eax
  int v6; // edi
  int v7; // esi
  bool v8; // zf
  CModelRenderSystem::RenderModelInfo_t *v9; // eax
  CModelRenderSystem::RenderModelInfo_t *v10; // ecx
  int v11; // edx
  int v12; // eax
  __int64 v13; // xmm0_8
  CModelRenderSystem::RenderModelInfo_t *v14; // ecx
  CModelRenderSystem::RenderModelInfo_t *v15; // eax
  int v16; // edx

  v5 = _Bottom;
  v6 = _Hole;
  v7 = 2 * _Hole + 2;
  v8 = v7 == _Bottom;
  if ( v7 < _Bottom )
  {
    do
    {
      if ( _Pred(a1: &_First[v7], a2: &_First[v7 - 1]) )
        --v7;
      v9 = &_First[v6];
      v10 = &_First[v7];
      *(_QWORD *)&v9->m_nLOD = *(_QWORD *)&v10->m_nLOD;
      *(_QWORD *)&v9->m_nSkin = *(_QWORD *)&v10->m_nSkin;
      *(_QWORD *)&v9->m_pFlexWeights = *(_QWORD *)&v10->m_pFlexWeights;
      v9->m_pLightingState = v10->m_pLightingState;
      v9->m_pDecalLightingState = v10->m_pDecalLightingState;
      v9->m_pEnvCubemapTexture = v10->m_pEnvCubemapTexture;
      v9->m_Decals = v10->m_Decals;
      v9->m_nFlashlightUsage = v10->m_nFlashlightUsage;
      v9->m_pStencilState = v10->m_pStencilState;
      v9->m_pColorMeshInfo = v10->m_pColorMeshInfo;
      v9->m_DiffuseModulation.x = v10->m_DiffuseModulation.x;
      v9->m_DiffuseModulation.y = v10->m_DiffuseModulation.y;
      v9->m_DiffuseModulation.z = v10->m_DiffuseModulation.z;
      v9->m_DiffuseModulation.w = v10->m_DiffuseModulation.w;
      *(_QWORD *)&v9->m_Entry.m_pRenderable = *(_QWORD *)&v10->m_Entry.m_pRenderable;
      *(_DWORD *)&v9->m_Entry.m_InstanceData.m_nAlpha = *(_DWORD *)&v10->m_Entry.m_InstanceData.m_nAlpha;
      v9->m_hInstance = v10->m_hInstance;
      v9->m_pBoneToWorld = v10->m_pBoneToWorld;
      *((_DWORD *)v9 + 22) ^= (*((_DWORD *)v9 + 22) ^ *((_DWORD *)v10 + 22)) & 0xFFFFFF;
      v11 = *((_DWORD *)v9 + 22) ^ (*((_DWORD *)v9 + 22) ^ *((_DWORD *)v10 + 22)) & 0x1000000;
      *((_DWORD *)v9 + 22) = v11;
      v6 = v7;
      v7 = 2 * v7 + 2;
      *((_DWORD *)v9 + 22) = v11 ^ (v11 ^ *((_DWORD *)v10 + 22)) & 0x2000000;
    }
    while ( v7 < _Bottom );
    v5 = _Bottom;
    v8 = v7 == _Bottom;
  }
  if ( v8 )
  {
    v12 = v5;
    v13 = *(_QWORD *)&_First[v12 - 1].m_nLOD;
    v14 = &_First[v12 - 1];
    v15 = &_First[v6];
    *(_QWORD *)&v15->m_nLOD = v13;
    *(_QWORD *)&v15->m_nSkin = *(_QWORD *)&v14->m_nSkin;
    *(_QWORD *)&v15->m_pFlexWeights = *(_QWORD *)&v14->m_pFlexWeights;
    v15->m_pLightingState = v14->m_pLightingState;
    v15->m_pDecalLightingState = v14->m_pDecalLightingState;
    v15->m_pEnvCubemapTexture = v14->m_pEnvCubemapTexture;
    v15->m_Decals = v14->m_Decals;
    v15->m_nFlashlightUsage = v14->m_nFlashlightUsage;
    v15->m_pStencilState = v14->m_pStencilState;
    v15->m_pColorMeshInfo = v14->m_pColorMeshInfo;
    v15->m_DiffuseModulation = v14->m_DiffuseModulation;
    v15->m_Entry = v14->m_Entry;
    v15->m_hInstance = v14->m_hInstance;
    v15->m_pBoneToWorld = v14->m_pBoneToWorld;
    *((_DWORD *)v15 + 22) ^= (*((_DWORD *)v14 + 22) ^ *((_DWORD *)v15 + 22)) & 0xFFFFFF;
    v16 = *((_DWORD *)v15 + 22) ^ (*((_DWORD *)v15 + 22) ^ *((_DWORD *)v14 + 22)) & 0x1000000;
    *((_DWORD *)v15 + 22) = v16;
    *((_DWORD *)v15 + 22) = v16 ^ (v16 ^ *((_DWORD *)v14 + 22)) & 0x2000000;
    v6 = _Bottom - 1;
  }
  std::_Push_heap<CModelRenderSystem::RenderModelInfo_t *,int,CModelRenderSystem::RenderModelInfo_t,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
    _First,
    _Hole: v6,
    _Top: _Hole,
    _Val,
    _Pred);
}

//------------------------------------------------------------------------------
// Address: 0x101250E0
// Name: public: CModelRenderSystem::CModelRenderSystem(void)
// Source: json
//------------------------------------------------------------------------------
CModelRenderSystem *__thiscall CModelRenderSystem::CModelRenderSystem(CModelRenderSystem *this)
{
  CAutoGameSystem::CAutoGameSystem(this, name: nullptr);
  this->IModelRenderSystem::__vftable = (IModelRenderSystem_vtbl *)&IModelRenderSystem::`vftable';
  this->CAutoGameSystem::CBaseGameSystem::IGameSystem::__vftable = (CModelRenderSystem_vtbl *)&CModelRenderSystem::`vftable'{for `CAutoGameSystem'};
  this->IModelRenderSystem::__vftable = (IModelRenderSystem_vtbl *)&CModelRenderSystem::`vftable'{for `IModelRenderSystem'};
  CMemoryStack::CMemoryStack(this: &this->m_BoneToWorld);
  CTextureReference::CTextureReference(this: &this->m_DefaultCubemap);
  CMaterialReference::CMaterialReference(
    this: &this->m_DebugMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_ShadowBuild,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->m_BrushModelList.m_pMemory = this->m_BrushModelList.m_pFixedMemory;
  this->m_BrushModelList.m_nAllocationCount = 512;
  this->m_BrushModelList.m_nGrowSize = -1;
  this->m_BrushModelList.m_nMallocGrowSize = 0;
  this->m_bHasInstanceData = false;
  CMemoryStack::Init(
    this: &this->m_BoneToWorld,
    pszAllocOwner: "CModelRenderSystem::m_BoneToWorld",
    maxSize: 0x100000u,
    commitSize: 0x8000u,
    initialCommit: 0,
    alignment: 0x20u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101251A0
// Name: struct std::pair<struct CModelRenderSystem::ModelListByType_t __near *,struct CModelRenderSystem::ModelListByType_t __near *> std::_Unguarded_partition<struct CModelRenderSystem::ModelListByType_t __near *,bool (*)(struct CModelRenderSystem::ModelListByType_t const __near &,struct CModelRenderSystem::ModelListByType_t const __near &)>(struct CModelRenderSystem::ModelListByType_t __near *,struct CModelRenderSystem::ModelListByType_t __near *,bool (*)(struct CModelRenderSystem::ModelListByType_t const __near &,struct CModelRenderSystem::ModelListByType_t const __near &))
// Source: json
//------------------------------------------------------------------------------
std::pair<CModelRenderSystem::ModelListByType_t *,CModelRenderSystem::ModelListByType_t *> *__cdecl std::_Unguarded_partition<CModelRenderSystem::ModelListByType_t *,bool (__cdecl *)(CModelRenderSystem::ModelListByType_t const &,CModelRenderSystem::ModelListByType_t const &)>(
        std::pair<CModelRenderSystem::ModelListByType_t *,CModelRenderSystem::ModelListByType_t *> *result,
        CModelRenderSystem::ModelListByType_t *_First,
        CModelRenderSystem::ModelListByType_t *_Last,
        bool (__cdecl *_Pred)(const CModelRenderSystem::ModelListByType_t *, const CModelRenderSystem::ModelListByType_t *))
{
  CModelRenderSystem::ModelListByType_t *v4; // esi
  unsigned int v5; // ebx
  CModelRenderSystem::ModelListByType_t *v6; // edx
  unsigned int v7; // edi
  StudioModelArrayInfo2_t v8; // xmm0_8
  __int64 v9; // xmm1_8
  __int64 v10; // xmm2_8
  __int64 v11; // xmm3_8
  __int64 v12; // xmm4_8
  __int64 v13; // xmm5_8
  bool v14; // zf
  CModelRenderSystem::ModelListByType_t *v15; // ebx
  StudioModelArrayInfo2_t v16; // xmm0_8
  __int64 v17; // xmm1_8
  __int64 v18; // xmm2_8
  __int64 v19; // xmm3_8
  __int64 v20; // xmm4_8
  __int64 v21; // xmm5_8
  StudioModelArrayInfo2_t v22; // xmm0_8
  __int64 v23; // xmm1_8
  __int64 v24; // xmm2_8
  __int64 v25; // xmm3_8
  __int64 v26; // xmm4_8
  __int64 v27; // xmm5_8
  unsigned int v28; // eax
  StudioModelArrayInfo2_t v29; // xmm0_8
  __int64 v30; // xmm1_8
  __int64 v31; // xmm2_8
  __int64 v32; // xmm3_8
  __int64 v33; // xmm4_8
  __int64 v34; // xmm5_8
  StudioModelArrayInfo2_t v35; // xmm0_8
  __int64 v36; // xmm1_8
  __int64 v37; // xmm2_8
  __int64 v38; // xmm3_8
  __int64 v39; // xmm4_8
  __int64 v40; // xmm5_8
  StudioModelArrayInfo2_t v41; // xmm6_8
  StudioModelArrayInfo2_t v42; // xmm0_8
  __int64 v43; // xmm1_8
  __int64 v44; // xmm2_8
  __int64 v45; // xmm3_8
  __int64 v46; // xmm4_8
  __int64 v47; // xmm5_8
  StudioModelArrayInfo2_t v48; // xmm0_8
  __int64 v49; // xmm1_8
  __int64 v50; // xmm2_8
  __int64 v51; // xmm3_8
  __int64 v52; // xmm4_8
  __int64 v53; // xmm5_8
  CModelRenderSystem::ModelListByType_t *_Glast; // [esp+Ch] [ebp-8h]
  CModelRenderSystem::ModelListByType_t *_Glasta; // [esp+Ch] [ebp-8h]
  CModelRenderSystem::ModelListByType_t *_Plast; // [esp+10h] [ebp-4h]

  v4 = &_First[(_Last - _First) / 2];
  std::_Median<CModelRenderSystem::ModelListByType_t *,bool (__cdecl *)(CModelRenderSystem::ModelListByType_t const &,CModelRenderSystem::ModelListByType_t const &)>(
    _First,
    _Mid: v4,
    _Last: _Last - 1,
    _Pred);
  v5 = (unsigned int)&v4[1];
  _Plast = v4 + 1;
  if ( _First < v4 )
  {
    do
    {
      _Glast = v4 - 1;
      if ( _Pred(a1: v4 - 1, a2: v4) )
        break;
      if ( _Pred(a1: v4, a2: _Glast) )
        break;
      --v4;
    }
    while ( _First < _Glast );
  }
  if ( v5 < (unsigned int)_Last )
  {
    do
    {
      if ( _Pred(a1: (const CModelRenderSystem::ModelListByType_t *)v5, a2: v4) )
        break;
      if ( _Pred(a1: v4, a2: (const CModelRenderSystem::ModelListByType_t *)v5) )
        break;
      v5 += 48;
    }
    while ( v5 < (unsigned int)_Last );
    _Plast = (CModelRenderSystem::ModelListByType_t *)v5;
  }
  v6 = v4;
  v7 = v5;
  _Glasta = v4;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v7 < (unsigned int)_Last )
      {
        do
        {
          if ( !_Pred(a1: v4, a2: (const CModelRenderSystem::ModelListByType_t *)v7) )
          {
            if ( _Pred(a1: (const CModelRenderSystem::ModelListByType_t *)v7, a2: v4) )
              break;
            v8 = *(StudioModelArrayInfo2_t *)v5;
            v9 = *(_QWORD *)(v5 + 8);
            v10 = *(_QWORD *)(v5 + 16);
            v11 = *(_QWORD *)(v5 + 24);
            v12 = *(_QWORD *)(v5 + 32);
            v13 = *(_QWORD *)(v5 + 40);
            *(_QWORD *)v5 = *(_QWORD *)v7;
            *(_QWORD *)(v5 + 8) = *(_QWORD *)(v7 + 8);
            *(_QWORD *)(v5 + 16) = *(_QWORD *)(v7 + 16);
            *(_QWORD *)(v5 + 24) = *(_QWORD *)(v7 + 24);
            *(_QWORD *)(v5 + 32) = *(_QWORD *)(v7 + 32);
            *(_QWORD *)(v5 + 40) = *(_QWORD *)(v7 + 40);
            *(StudioModelArrayInfo2_t *)v7 = v8;
            *(_QWORD *)(v7 + 8) = v9;
            *(_QWORD *)(v7 + 16) = v10;
            *(_QWORD *)(v7 + 24) = v11;
            *(_QWORD *)(v7 + 32) = v12;
            v5 += 48;
            *(_QWORD *)(v7 + 40) = v13;
          }
          v7 += 48;
        }
        while ( v7 < (unsigned int)_Last );
        v6 = _Glasta;
        _Plast = (CModelRenderSystem::ModelListByType_t *)v5;
      }
      v14 = v6 == _First;
      if ( v6 > _First )
      {
        v15 = v6 - 1;
        do
        {
          if ( !_Pred(a1: v15, a2: v4) )
          {
            if ( _Pred(a1: v4, a2: v15) )
              break;
            v16 = v4[-1].StudioModelArrayInfo2_t;
            v17 = *(_QWORD *)&v4[-1].m_pStudioHdr;
            v18 = *(_QWORD *)&v4[-1].m_nLightingModel;
            v19 = *(_QWORD *)&v4[-1].m_pFirstNode;
            v20 = *(_QWORD *)&v4[-1].m_nSetupBoneCount;
            v21 = *(_QWORD *)&v4[-1].m_pRenderModels;
            v4[-1].StudioModelArrayInfo2_t = v15->StudioModelArrayInfo2_t;
            --v4;
            *(_QWORD *)&v4->m_pStudioHdr = *(_QWORD *)&v15->m_pStudioHdr;
            *(_QWORD *)&v4->m_nLightingModel = *(_QWORD *)&v15->m_nLightingModel;
            *(_QWORD *)&v4->m_pFirstNode = *(_QWORD *)&v15->m_pFirstNode;
            *(_QWORD *)&v4->m_nSetupBoneCount = *(_QWORD *)&v15->m_nSetupBoneCount;
            *(_QWORD *)&v4->m_pRenderModels = *(_QWORD *)&v15->m_pRenderModels;
            v15->StudioModelArrayInfo2_t = v16;
            *(_QWORD *)&v15->m_pStudioHdr = v17;
            *(_QWORD *)&v15->m_nLightingModel = v18;
            *(_QWORD *)&v15->m_pFirstNode = v19;
            *(_QWORD *)&v15->m_nSetupBoneCount = v20;
            *(_QWORD *)&v15->m_pRenderModels = v21;
          }
          --v15;
          --_Glasta;
        }
        while ( _First < _Glasta );
        v6 = _Glasta;
        v5 = (unsigned int)_Plast;
        v14 = _Glasta == _First;
      }
      if ( v14 )
        break;
      _Glasta = --v6;
      if ( (CModelRenderSystem::ModelListByType_t *)v7 == _Last )
      {
        if ( v6 != --v4 )
        {
          v35 = v6->StudioModelArrayInfo2_t;
          v36 = *(_QWORD *)&v6->m_pStudioHdr;
          v37 = *(_QWORD *)&v6->m_nLightingModel;
          v38 = *(_QWORD *)&v6->m_pFirstNode;
          v39 = *(_QWORD *)&v6->m_nSetupBoneCount;
          v40 = *(_QWORD *)&v6->m_pRenderModels;
          v6->StudioModelArrayInfo2_t = v4->StudioModelArrayInfo2_t;
          *(_QWORD *)&v6->m_pStudioHdr = *(_QWORD *)&v4->m_pStudioHdr;
          *(_QWORD *)&v6->m_nLightingModel = *(_QWORD *)&v4->m_nLightingModel;
          *(_QWORD *)&v6->m_pFirstNode = *(_QWORD *)&v4->m_pFirstNode;
          *(_QWORD *)&v6->m_nSetupBoneCount = *(_QWORD *)&v4->m_nSetupBoneCount;
          *(_QWORD *)&v6->m_pRenderModels = *(_QWORD *)&v4->m_pRenderModels;
          v4->StudioModelArrayInfo2_t = v35;
          *(_QWORD *)&v4->m_pStudioHdr = v36;
          *(_QWORD *)&v4->m_nLightingModel = v37;
          *(_QWORD *)&v4->m_pFirstNode = v38;
          *(_QWORD *)&v4->m_nSetupBoneCount = v39;
          *(_QWORD *)&v4->m_pRenderModels = v40;
        }
        v41 = *(StudioModelArrayInfo2_t *)(v5 - 48);
        v42 = v4->StudioModelArrayInfo2_t;
        v43 = *(_QWORD *)&v4->m_pStudioHdr;
        v44 = *(_QWORD *)&v4->m_nLightingModel;
        v45 = *(_QWORD *)&v4->m_pFirstNode;
        v46 = *(_QWORD *)&v4->m_nSetupBoneCount;
        v47 = *(_QWORD *)&v4->m_pRenderModels;
        v5 -= 48;
        v4->StudioModelArrayInfo2_t = v41;
        *(_QWORD *)&v4->m_pStudioHdr = *(_QWORD *)(v5 + 8);
        *(_QWORD *)&v4->m_nLightingModel = *(_QWORD *)(v5 + 16);
        *(_QWORD *)&v4->m_pFirstNode = *(_QWORD *)(v5 + 24);
        *(_QWORD *)&v4->m_nSetupBoneCount = *(_QWORD *)(v5 + 32);
        *(_QWORD *)&v4->m_pRenderModels = *(_QWORD *)(v5 + 40);
        *(StudioModelArrayInfo2_t *)v5 = v42;
        *(_QWORD *)(v5 + 8) = v43;
        *(_QWORD *)(v5 + 16) = v44;
        *(_QWORD *)(v5 + 24) = v45;
        *(_QWORD *)(v5 + 32) = v46;
        _Plast = (CModelRenderSystem::ModelListByType_t *)v5;
        *(_QWORD *)(v5 + 40) = v47;
      }
      else
      {
        v48 = *(StudioModelArrayInfo2_t *)v7;
        v49 = *(_QWORD *)(v7 + 8);
        v50 = *(_QWORD *)(v7 + 16);
        v51 = *(_QWORD *)(v7 + 24);
        v52 = *(_QWORD *)(v7 + 32);
        v53 = *(_QWORD *)(v7 + 40);
        *(StudioModelArrayInfo2_t *)v7 = v6->StudioModelArrayInfo2_t;
        *(_QWORD *)(v7 + 8) = *(_QWORD *)&v6->m_pStudioHdr;
        *(_QWORD *)(v7 + 16) = *(_QWORD *)&v6->m_nLightingModel;
        *(_QWORD *)(v7 + 24) = *(_QWORD *)&v6->m_pFirstNode;
        *(_QWORD *)(v7 + 32) = *(_QWORD *)&v6->m_nSetupBoneCount;
        *(_QWORD *)(v7 + 40) = *(_QWORD *)&v6->m_pRenderModels;
        v6->StudioModelArrayInfo2_t = v48;
        *(_QWORD *)&v6->m_pStudioHdr = v49;
        *(_QWORD *)&v6->m_nLightingModel = v50;
        *(_QWORD *)&v6->m_pFirstNode = v51;
        *(_QWORD *)&v6->m_nSetupBoneCount = v52;
        *(_QWORD *)&v6->m_pRenderModels = v53;
        v7 += 48;
      }
    }
    if ( (CModelRenderSystem::ModelListByType_t *)v7 == _Last )
      break;
    if ( v5 != v7 )
    {
      v22 = v4->StudioModelArrayInfo2_t;
      v23 = *(_QWORD *)&v4->m_pStudioHdr;
      v24 = *(_QWORD *)&v4->m_nLightingModel;
      v25 = *(_QWORD *)&v4->m_pFirstNode;
      v26 = *(_QWORD *)&v4->m_nSetupBoneCount;
      v27 = *(_QWORD *)&v4->m_pRenderModels;
      v4->StudioModelArrayInfo2_t = *(StudioModelArrayInfo2_t *)v5;
      *(_QWORD *)&v4->m_pStudioHdr = *(_QWORD *)(v5 + 8);
      *(_QWORD *)&v4->m_nLightingModel = *(_QWORD *)(v5 + 16);
      *(_QWORD *)&v4->m_pFirstNode = *(_QWORD *)(v5 + 24);
      *(_QWORD *)&v4->m_nSetupBoneCount = *(_QWORD *)(v5 + 32);
      *(_QWORD *)&v4->m_pRenderModels = *(_QWORD *)(v5 + 40);
      *(StudioModelArrayInfo2_t *)v5 = v22;
      *(_QWORD *)(v5 + 8) = v23;
      *(_QWORD *)(v5 + 16) = v24;
      *(_QWORD *)(v5 + 24) = v25;
      *(_QWORD *)(v5 + 32) = v26;
      *(_QWORD *)(v5 + 40) = v27;
    }
    v28 = v7;
    v29 = v4->StudioModelArrayInfo2_t;
    v30 = *(_QWORD *)&v4->m_pStudioHdr;
    v31 = *(_QWORD *)&v4->m_nLightingModel;
    v32 = *(_QWORD *)&v4->m_pFirstNode;
    v33 = *(_QWORD *)&v4->m_nSetupBoneCount;
    v34 = *(_QWORD *)&v4->m_pRenderModels;
    v4->StudioModelArrayInfo2_t = *(StudioModelArrayInfo2_t *)v7;
    *(_QWORD *)&v4->m_pStudioHdr = *(_QWORD *)(v7 + 8);
    *(_QWORD *)&v4->m_nLightingModel = *(_QWORD *)(v7 + 16);
    *(_QWORD *)&v4->m_pFirstNode = *(_QWORD *)(v7 + 24);
    *(_QWORD *)&v4->m_nSetupBoneCount = *(_QWORD *)(v7 + 32);
    *(_QWORD *)&v4->m_pRenderModels = *(_QWORD *)(v7 + 40);
    *(StudioModelArrayInfo2_t *)v7 = v29;
    *(_QWORD *)(v7 + 8) = v30;
    *(_QWORD *)(v7 + 16) = v31;
    v5 += 48;
    *(_QWORD *)(v7 + 24) = v32;
    ++v4;
    *(_QWORD *)(v7 + 32) = v33;
    _Plast = (CModelRenderSystem::ModelListByType_t *)v5;
    v7 += 48;
    *(_QWORD *)(v28 + 40) = v34;
  }
  result->first = v4;
  result->second = (CModelRenderSystem::ModelListByType_t *)v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10125680
// Name: void std::_Sort_heap<struct CModelRenderSystem::ModelListByType_t __near *,bool (*)(struct CModelRenderSystem::ModelListByType_t const __near &,struct CModelRenderSystem::ModelListByType_t const __near &)>(struct CModelRenderSystem::ModelListByType_t __near *,struct CModelRenderSystem::ModelListByType_t __near *,bool (*)(struct CModelRenderSystem::ModelListByType_t const __near &,struct CModelRenderSystem::ModelListByType_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<CModelRenderSystem::ModelListByType_t *,bool (__cdecl *)(CModelRenderSystem::ModelListByType_t const &,CModelRenderSystem::ModelListByType_t const &)>(
        CModelRenderSystem::ModelListByType_t *_First,
        CModelRenderSystem::ModelListByType_t *_Last,
        bool (__cdecl *_Pred)(const CModelRenderSystem::ModelListByType_t *, const CModelRenderSystem::ModelListByType_t *))
{
  int v3; // ecx
  CModelRenderSystem::ModelListByType_t *v4; // esi
  CModelRenderSystem::ModelListByType_t _Val; // [esp+8h] [ebp-30h] BYREF

  v3 = (char *)_Last - (char *)_First;
  if ( _Last - _First > 1 )
  {
    v4 = _Last - 1;
    do
    {
      _Val = *v4;
      *v4 = *_First;
      std::_Adjust_heap<CModelRenderSystem::ModelListByType_t *,int,CModelRenderSystem::ModelListByType_t,bool (__cdecl *)(CModelRenderSystem::ModelListByType_t const &,CModelRenderSystem::ModelListByType_t const &)>(
        _First,
        _Hole: 0,
        _Bottom: (v3 - 48) / 48,
        &_Val,
        _Pred);
      v3 = (char *)--v4 - (char *)_First + 48;
    }
    while ( v3 / 48 > 1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125790
// Name: void std::_Median<struct CModelRenderSystem::RenderModelInfo_t __near *,bool (*)(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &)>(struct CModelRenderSystem::RenderModelInfo_t __near *,struct CModelRenderSystem::RenderModelInfo_t __near *,struct CModelRenderSystem::RenderModelInfo_t __near *,bool (*)(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Median<CModelRenderSystem::RenderModelInfo_t *,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
        CModelRenderSystem::RenderModelInfo_t *_First,
        CModelRenderSystem::RenderModelInfo_t *_Mid,
        CModelRenderSystem::RenderModelInfo_t *_Last,
        bool (__cdecl *_Pred)(const CModelRenderSystem::RenderModelInfo_t *, const CModelRenderSystem::RenderModelInfo_t *))
{
  int v4; // eax
  int v5; // eax
  unsigned int v6; // edi
  const CModelRenderSystem::RenderModelInfo_t *v7; // eax
  CModelRenderSystem::RenderModelInfo_t *v8; // edi
  unsigned int v9; // [esp+Ch] [ebp-8h]
  CModelRenderSystem::RenderModelInfo_t *_Left; // [esp+10h] [ebp-4h]
  CModelRenderSystem::RenderModelInfo_t *_Firsta; // [esp+1Ch] [ebp+8h]
  CModelRenderSystem::RenderModelInfo_t *_Firstb; // [esp+1Ch] [ebp+8h]

  v4 = _Last - _First;
  if ( v4 <= 40 )
  {
    if ( _Pred(a1: _Mid, a2: _First) )
      std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: _Mid, _Right: _First);
    if ( _Pred(a1: _Last, a2: _Mid) )
      std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: _Last, _Right: _Mid);
    if ( _Pred(a1: _Mid, a2: _First) )
      std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: _Mid, _Right: _First);
  }
  else
  {
    v5 = v4 + 1;
    v6 = 92 * (v5 / 8);
    v9 = 184 * (v5 / 8);
    _Left = &_First[v6 / 0x5C];
    if ( _Pred(a1: &_First[v6 / 0x5C], a2: _First) )
      std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left, _Right: _First);
    if ( _Pred(a1: &_First[v9 / 0x5C], a2: _Left) )
      std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: &_First[v9 / 0x5C], _Right: _Left);
    if ( _Pred(a1: _Left, a2: _First) )
      std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left, _Right: _First);
    _Firsta = &_Mid[v6 / 0xFFFFFFA4];
    if ( _Pred(a1: _Mid, a2: &_Mid[v6 / 0xFFFFFFA4]) )
      std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: _Mid, _Right: _Firsta);
    if ( _Pred(a1: &_Mid[v6 / 0x5C], a2: _Mid) )
      std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: &_Mid[v6 / 0x5C], _Right: _Mid);
    if ( _Pred(a1: _Mid, a2: _Firsta) )
      std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: _Mid, _Right: _Firsta);
    v7 = &_Last[v6 / 0xFFFFFFA4];
    v8 = &_Last[v9 / 0xFFFFFFA4];
    _Firstb = (CModelRenderSystem::RenderModelInfo_t *)v7;
    if ( _Pred(a1: v7, a2: &_Last[v9 / 0xFFFFFFA4]) )
      std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: _Firstb, _Right: v8);
    if ( _Pred(a1: _Last, a2: _Firstb) )
      std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: _Last, _Right: _Firstb);
    if ( _Pred(a1: _Firstb, a2: v8) )
      std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: _Firstb, _Right: v8);
    if ( _Pred(a1: _Mid, a2: _Left) )
      std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: _Mid, _Right: _Left);
    if ( _Pred(a1: _Firstb, a2: _Mid) )
      std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: _Firstb, _Right: _Mid);
    if ( _Pred(a1: _Mid, a2: _Left) )
      std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: _Mid, _Right: _Left);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125990
// Name: void std::_Make_heap<struct CModelRenderSystem::RenderModelInfo_t __near *,int,struct CModelRenderSystem::RenderModelInfo_t,bool (*)(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &)>(struct CModelRenderSystem::RenderModelInfo_t __near *,struct CModelRenderSystem::RenderModelInfo_t __near *,bool (*)(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &),int __near *,struct CModelRenderSystem::RenderModelInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<CModelRenderSystem::RenderModelInfo_t *,int,CModelRenderSystem::RenderModelInfo_t,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
        CModelRenderSystem::RenderModelInfo_t *_First,
        CModelRenderSystem::RenderModelInfo_t *_Last,
        bool (__cdecl *_Pred)(const CModelRenderSystem::RenderModelInfo_t *, const CModelRenderSystem::RenderModelInfo_t *))
{
  CModelRenderSystem::RenderModelInfo_t *v3; // ecx
  int v4; // edi
  float *p_z; // esi
  MaterialLightingState_t *v6; // edx
  MaterialLightingState_t *v7; // eax
  __int64 v8; // xmm0_8
  ITexture *v9; // edx
  StudioDecalHandle_t__ *v10; // eax
  unsigned int v11; // edx
  ShaderStencilState_t *v12; // eax
  ColorMeshInfo_t *v13; // edx
  int v14; // eax
  matrix3x4a_t *v15; // eax
  int v16; // edx
  CModelRenderSystem::RenderModelInfo_t _Val; // [esp+Ch] [ebp-5Ch] BYREF

  v3 = _First;
  v4 = (_Last - _First) / 2;
  if ( v4 > 0 )
  {
    p_z = &_First[v4].m_DiffuseModulation.z;
    while ( 1 )
    {
      v6 = *((MaterialLightingState_t **)p_z - 32);
      v7 = *((MaterialLightingState_t **)p_z - 31);
      p_z -= 23;
      v8 = *(_QWORD *)(p_z - 15);
      _Val.m_pLightingState = v6;
      v9 = *((ITexture **)p_z - 7);
      _Val.m_pDecalLightingState = v7;
      v10 = *((StudioDecalHandle_t__ **)p_z - 6);
      _Val.m_pEnvCubemapTexture = v9;
      v11 = *((_DWORD *)p_z - 5);
      _Val.m_Decals = v10;
      v12 = *((ShaderStencilState_t **)p_z - 4);
      _Val.m_nFlashlightUsage = v11;
      v13 = *((ColorMeshInfo_t **)p_z - 3);
      _Val.m_pStencilState = v12;
      v14 = *((_DWORD *)p_z + 4);
      _Val.m_pColorMeshInfo = v13;
      LOWORD(v13) = *((_WORD *)p_z + 10);
      *(_DWORD *)&_Val.m_Entry.m_InstanceData.m_nAlpha = v14;
      v15 = *((matrix3x4a_t **)p_z + 6);
      _Val.m_hInstance = (unsigned __int16)v13;
      v16 = *((_DWORD *)p_z + 7);
      _Val.m_pBoneToWorld = v15;
      *(_QWORD *)&_Val.m_nLOD = v8;
      *(_QWORD *)&_Val.m_nSkin = *(_QWORD *)(p_z - 13);
      *(_QWORD *)&_Val.m_pFlexWeights = *(_QWORD *)(p_z - 11);
      *(float *)&v8 = *(p_z - 2);
      *((_DWORD *)&_Val + 22) ^= (*((_DWORD *)&_Val + 22) ^ v16) & 0x3FFFFFF;
      LODWORD(_Val.m_DiffuseModulation.x) = v8;
      _Val.m_DiffuseModulation.y = *(p_z - 1);
      _Val.m_DiffuseModulation.z = *p_z;
      --v4;
      _Val.m_DiffuseModulation.w = p_z[1];
      *(_QWORD *)&_Val.m_Entry.m_pRenderable = *((_QWORD *)p_z + 1);
      std::_Adjust_heap<CModelRenderSystem::RenderModelInfo_t *,int,CModelRenderSystem::RenderModelInfo_t,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
        _First: v3,
        _Hole: v4,
        _Bottom: _Last - _First,
        &_Val,
        _Pred);
      if ( v4 <= 0 )
        break;
      v3 = _First;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125AA0
// Name: void std::_Insertion_sort1<struct CModelRenderSystem::RenderModelInfo_t __near *,bool (*)(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &),struct CModelRenderSystem::RenderModelInfo_t>(struct CModelRenderSystem::RenderModelInfo_t __near *,struct CModelRenderSystem::RenderModelInfo_t __near *,bool (*)(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &),struct CModelRenderSystem::RenderModelInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Insertion_sort1<CModelRenderSystem::RenderModelInfo_t *,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &),CModelRenderSystem::RenderModelInfo_t>(
        CModelRenderSystem::RenderModelInfo_t *_First,
        CModelRenderSystem::RenderModelInfo_t *_Last,
        bool (__cdecl *_Pred)(const CModelRenderSystem::RenderModelInfo_t *, const CModelRenderSystem::RenderModelInfo_t *))
{
  CModelRenderSystem::RenderModelInfo_t *v3; // ebx
  CModelRenderSystem::RenderModelInfo_t *v4; // esi
  char *p_z; // edi
  MaterialLightingState_t *v6; // ecx
  __int64 v7; // xmm0_8
  ITexture *v8; // edx
  StudioDecalHandle_t__ *v9; // eax
  __int64 v10; // xmm0_8
  unsigned int v11; // ecx
  ColorMeshInfo_t *v12; // eax
  __int64 v13; // xmm0_8
  int v14; // ecx
  matrix3x4a_t *v15; // eax
  ShaderStencilState_t *v16; // edx
  int v17; // ecx
  CModelRenderSystem::RenderModelInfo_t *v18; // esi
  MaterialLightingState_t *m_pLightingState; // edx
  MaterialLightingState_t *m_pDecalLightingState; // eax
  ITexture *m_pEnvCubemapTexture; // ecx
  __int64 v22; // xmm0_8
  StudioDecalHandle_t__ *m_Decals; // edx
  unsigned int m_nFlashlightUsage; // eax
  ShaderStencilState_t *m_pStencilState; // ecx
  ColorMeshInfo_t *m_pColorMeshInfo; // edx
  int v27; // eax
  matrix3x4a_t *m_pBoneToWorld; // edx
  char *v29; // ebx
  char *v30; // edi
  int v31; // eax
  int v32; // eax
  MaterialLightingState_t *v33; // eax
  MaterialLightingState_t *v34; // ecx
  ITexture *v35; // edx
  __int64 v36; // xmm0_8
  StudioDecalHandle_t__ *v37; // eax
  unsigned int v38; // ecx
  ShaderStencilState_t *v39; // edx
  ColorMeshInfo_t *v40; // eax
  int v41; // ecx
  matrix3x4a_t *v42; // eax
  int v43; // ecx
  CModelRenderSystem::RenderModelInfo_t _Val; // [esp+4h] [ebp-64h] BYREF
  char *v45; // [esp+60h] [ebp-8h]
  CModelRenderSystem::RenderModelInfo_t *_Next; // [esp+64h] [ebp-4h]

  v3 = _First;
  if ( _First != _Last )
  {
    v4 = _First + 1;
    _Next = _First + 1;
    if ( &_First[1] != _Last )
    {
      p_z = (char *)&_First[1].m_DiffuseModulation.z;
      v45 = (char *)&_First[1].m_DiffuseModulation.z;
      do
      {
        v6 = *((MaterialLightingState_t **)p_z - 8);
        v7 = *(_QWORD *)&v4->m_nLOD;
        v8 = *((ITexture **)p_z - 7);
        _Val.m_pLightingState = *((MaterialLightingState_t **)p_z - 9);
        v9 = *((StudioDecalHandle_t__ **)p_z - 6);
        *(_QWORD *)&_Val.m_nLOD = v7;
        v10 = *(_QWORD *)&v4->m_nSkin;
        _Val.m_pDecalLightingState = v6;
        v11 = *((_DWORD *)p_z - 5);
        _Val.m_Decals = v9;
        v12 = *((ColorMeshInfo_t **)p_z - 3);
        *(_QWORD *)&_Val.m_nSkin = v10;
        v13 = *(_QWORD *)&v4->m_pFlexWeights;
        _Val.m_nFlashlightUsage = v11;
        v14 = *((_DWORD *)p_z + 4);
        *(_QWORD *)&_Val.m_pFlexWeights = v13;
        LODWORD(v13) = *((_DWORD *)p_z - 2);
        _Val.m_pColorMeshInfo = v12;
        v15 = *((matrix3x4a_t **)p_z + 6);
        _Val.m_pEnvCubemapTexture = v8;
        v16 = *((ShaderStencilState_t **)p_z - 4);
        LODWORD(_Val.m_DiffuseModulation.x) = v13;
        LODWORD(v13) = *((_DWORD *)p_z - 1);
        *(_DWORD *)&_Val.m_Entry.m_InstanceData.m_nAlpha = v14;
        v17 = *((_DWORD *)p_z + 7);
        _Val.m_pBoneToWorld = v15;
        _Val.m_pStencilState = v16;
        LOWORD(v16) = *((_WORD *)p_z + 10);
        LODWORD(_Val.m_DiffuseModulation.y) = v13;
        _Val.m_DiffuseModulation.z = *(float *)p_z;
        LODWORD(v13) = *((_DWORD *)p_z + 1);
        _Val.m_hInstance = (unsigned __int16)v16;
        LODWORD(_Val.m_DiffuseModulation.w) = v13;
        *(_QWORD *)&_Val.m_Entry.m_pRenderable = *((_QWORD *)p_z + 1);
        *((_DWORD *)&_Val + 22) ^= (*((_DWORD *)&_Val + 22) ^ v17) & 0x3FFFFFF;
        if ( _Pred(a1: &_Val, a2: v3) )
        {
          v18 = _Next;
          std::_Move_backward<CModelRenderSystem::RenderModelInfo_t *,CModelRenderSystem::RenderModelInfo_t *>(
            _First: v3,
            _Last: _Next,
            _Dest: (CModelRenderSystem::RenderModelInfo_t *)(p_z + 32));
          m_pLightingState = _Val.m_pLightingState;
          m_pDecalLightingState = _Val.m_pDecalLightingState;
          m_pEnvCubemapTexture = _Val.m_pEnvCubemapTexture;
          *(_QWORD *)&v3->m_nLOD = *(_QWORD *)&_Val.m_nLOD;
          *(_QWORD *)&v3->m_nSkin = *(_QWORD *)&_Val.m_nSkin;
          v22 = *(_QWORD *)&_Val.m_pFlexWeights;
          v3->m_pLightingState = m_pLightingState;
          m_Decals = _Val.m_Decals;
          v3->m_pDecalLightingState = m_pDecalLightingState;
          m_nFlashlightUsage = _Val.m_nFlashlightUsage;
          *(_QWORD *)&v3->m_pFlexWeights = v22;
          *(float *)&v22 = _Val.m_DiffuseModulation.x;
          v3->m_pEnvCubemapTexture = m_pEnvCubemapTexture;
          m_pStencilState = _Val.m_pStencilState;
          v3->m_Decals = m_Decals;
          m_pColorMeshInfo = _Val.m_pColorMeshInfo;
          v3->m_nFlashlightUsage = m_nFlashlightUsage;
          v27 = *(_DWORD *)&_Val.m_Entry.m_InstanceData.m_nAlpha;
          v3->m_pStencilState = m_pStencilState;
          LOWORD(m_pStencilState) = _Val.m_hInstance;
          v3->m_pColorMeshInfo = m_pColorMeshInfo;
          m_pBoneToWorld = _Val.m_pBoneToWorld;
          LODWORD(v3->m_DiffuseModulation.x) = v22;
          v3->m_DiffuseModulation.y = _Val.m_DiffuseModulation.y;
          v3->m_DiffuseModulation.z = _Val.m_DiffuseModulation.z;
          v3->m_DiffuseModulation.w = _Val.m_DiffuseModulation.w;
          *(_QWORD *)&v3->m_Entry.m_pRenderable = *(_QWORD *)&_Val.m_Entry.m_pRenderable;
          *(_DWORD *)&v3->m_Entry.m_InstanceData.m_nAlpha = v27;
          *((_DWORD *)v3 + 22) ^= (*((_DWORD *)&_Val + 22) ^ *((_DWORD *)v3 + 22)) & 0x3FFFFFF;
          v3->m_hInstance = (unsigned __int16)m_pStencilState;
          v3->m_pBoneToWorld = m_pBoneToWorld;
        }
        else
        {
          v29 = p_z - 152;
          if ( _Pred(a1: &_Val, a2: (const CModelRenderSystem::RenderModelInfo_t *)(p_z - 152)) )
          {
            v30 = p_z - 92;
            do
            {
              *(_QWORD *)&v4->m_nLOD = *(_QWORD *)v29;
              *(_QWORD *)&v4->m_nSkin = *((_QWORD *)v29 + 1);
              *(_QWORD *)&v4->m_pFlexWeights = *((_QWORD *)v29 + 2);
              v4->m_pLightingState = *((MaterialLightingState_t **)v30 - 9);
              v4->m_pDecalLightingState = *((MaterialLightingState_t **)v30 - 8);
              v4->m_pEnvCubemapTexture = *((ITexture **)v30 - 7);
              v4->m_Decals = *((StudioDecalHandle_t__ **)v30 - 6);
              v4->m_nFlashlightUsage = *((_DWORD *)v30 - 5);
              v4->m_pStencilState = *((ShaderStencilState_t **)v30 - 4);
              v4->m_pColorMeshInfo = *((ColorMeshInfo_t **)v30 - 3);
              v4->m_DiffuseModulation.x = *((float *)v30 - 2);
              v30 -= 92;
              v4->m_DiffuseModulation.y = *((float *)v30 + 22);
              v4->m_DiffuseModulation.z = *((float *)v30 + 23);
              v4->m_DiffuseModulation.w = *((float *)v30 + 24);
              *(_QWORD *)&v4->m_Entry.m_pRenderable = *(_QWORD *)(v30 + 100);
              *(_DWORD *)&v4->m_Entry.m_InstanceData.m_nAlpha = *((_DWORD *)v30 + 27);
              v31 = *((_DWORD *)v4 + 22);
              v4->m_hInstance = *((_WORD *)v30 + 56);
              v4->m_pBoneToWorld = *((matrix3x4a_t **)v30 + 29);
              *((_DWORD *)v4 + 22) ^= (*((_DWORD *)v30 + 30) ^ v31) & 0xFFFFFF;
              v32 = *((_DWORD *)v4 + 22) ^ (*((_DWORD *)v4 + 22) ^ *((_DWORD *)v30 + 30)) & 0x1000000;
              *((_DWORD *)v4 + 22) = v32;
              *((_DWORD *)v4 + 22) = v32 ^ (v32 ^ *((_DWORD *)v30 + 30)) & 0x2000000;
              v4 = (CModelRenderSystem::RenderModelInfo_t *)v29;
              v29 -= 92;
            }
            while ( _Pred(a1: &_Val, a2: (const CModelRenderSystem::RenderModelInfo_t *)v29) );
            p_z = v45;
          }
          v33 = _Val.m_pLightingState;
          v34 = _Val.m_pDecalLightingState;
          v35 = _Val.m_pEnvCubemapTexture;
          *(_QWORD *)&v4->m_nLOD = *(_QWORD *)&_Val.m_nLOD;
          *(_QWORD *)&v4->m_nSkin = *(_QWORD *)&_Val.m_nSkin;
          v36 = *(_QWORD *)&_Val.m_pFlexWeights;
          v4->m_pLightingState = v33;
          v37 = _Val.m_Decals;
          v3 = _First;
          v4->m_pDecalLightingState = v34;
          v38 = _Val.m_nFlashlightUsage;
          *(_QWORD *)&v4->m_pFlexWeights = v36;
          *(float *)&v36 = _Val.m_DiffuseModulation.x;
          v4->m_pEnvCubemapTexture = v35;
          v39 = _Val.m_pStencilState;
          v4->m_Decals = v37;
          v40 = _Val.m_pColorMeshInfo;
          v4->m_nFlashlightUsage = v38;
          v41 = *(_DWORD *)&_Val.m_Entry.m_InstanceData.m_nAlpha;
          v4->m_pStencilState = v39;
          LOWORD(v39) = _Val.m_hInstance;
          v4->m_pColorMeshInfo = v40;
          v42 = _Val.m_pBoneToWorld;
          LODWORD(v4->m_DiffuseModulation.x) = v36;
          v4->m_DiffuseModulation.y = _Val.m_DiffuseModulation.y;
          v4->m_DiffuseModulation.z = _Val.m_DiffuseModulation.z;
          v4->m_DiffuseModulation.w = _Val.m_DiffuseModulation.w;
          *(_QWORD *)&v4->m_Entry.m_pRenderable = *(_QWORD *)&_Val.m_Entry.m_pRenderable;
          *(_DWORD *)&v4->m_Entry.m_InstanceData.m_nAlpha = v41;
          v43 = *((_DWORD *)&_Val + 22) ^ *((_DWORD *)v4 + 22);
          v4->m_hInstance = (unsigned __int16)v39;
          *((_DWORD *)v4 + 22) ^= v43 & 0x3FFFFFF;
          v4->m_pBoneToWorld = v42;
          v18 = _Next;
        }
        v4 = v18 + 1;
        p_z += 92;
        _Next = v4;
        v45 = p_z;
      }
      while ( v4 != _Last );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125DE0
// Name: void std::_Pop_heap_0<struct CModelRenderSystem::RenderModelInfo_t __near *,struct CModelRenderSystem::RenderModelInfo_t,bool (*)(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &)>(struct CModelRenderSystem::RenderModelInfo_t __near *,struct CModelRenderSystem::RenderModelInfo_t __near *,bool (*)(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &),struct CModelRenderSystem::RenderModelInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Pop_heap_0<CModelRenderSystem::RenderModelInfo_t *,CModelRenderSystem::RenderModelInfo_t,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
        CModelRenderSystem::RenderModelInfo_t *_First,
        CModelRenderSystem::RenderModelInfo_t *_Last,
        bool (__cdecl *_Pred)(const CModelRenderSystem::RenderModelInfo_t *, const CModelRenderSystem::RenderModelInfo_t *))
{
  MaterialLightingState_t *m_pLightingState; // eax
  __int64 v4; // xmm0_8
  StudioDecalHandle_t__ *m_Decals; // edx
  ITexture *m_pEnvCubemapTexture; // eax
  ShaderStencilState_t *m_pStencilState; // edx
  unsigned int m_nFlashlightUsage; // eax
  __int64 v9; // xmm0_8
  int v10; // edx
  ColorMeshInfo_t *m_pColorMeshInfo; // eax
  __int64 v12; // xmm0_8
  matrix3x4a_t *m_pBoneToWorld; // edx
  int v14; // edx
  CModelRenderSystem::RenderModelInfo_t _Val; // [esp+8h] [ebp-5Ch] BYREF

  m_pLightingState = _Last[-1].m_pLightingState;
  v4 = *(_QWORD *)&_Last[-1].m_nLOD;
  _Val.m_pDecalLightingState = _Last[-1].m_pDecalLightingState;
  m_Decals = _Last[-1].m_Decals;
  _Val.m_pLightingState = m_pLightingState;
  m_pEnvCubemapTexture = _Last[-1].m_pEnvCubemapTexture;
  _Val.m_Decals = m_Decals;
  m_pStencilState = _Last[-1].m_pStencilState;
  _Val.m_pEnvCubemapTexture = m_pEnvCubemapTexture;
  m_nFlashlightUsage = _Last[-1].m_nFlashlightUsage;
  *(_QWORD *)&_Val.m_nLOD = v4;
  v9 = *(_QWORD *)&_Last[-1].m_nSkin;
  _Val.m_pStencilState = m_pStencilState;
  v10 = *(_DWORD *)&_Last[-1].m_Entry.m_InstanceData.m_nAlpha;
  _Val.m_nFlashlightUsage = m_nFlashlightUsage;
  m_pColorMeshInfo = _Last[-1].m_pColorMeshInfo;
  *(_QWORD *)&_Val.m_nSkin = v9;
  v12 = *(_QWORD *)&_Last[-1].m_pFlexWeights;
  *(_DWORD *)&_Val.m_Entry.m_InstanceData.m_nAlpha = v10;
  m_pBoneToWorld = _Last[-1].m_pBoneToWorld;
  *(_QWORD *)&_Val.m_pFlexWeights = v12;
  *(float *)&v12 = _Last[-1].m_DiffuseModulation.x;
  _Val.m_pColorMeshInfo = m_pColorMeshInfo;
  LOWORD(m_pColorMeshInfo) = _Last[-1].m_hInstance;
  LODWORD(_Val.m_DiffuseModulation.x) = v12;
  *(float *)&v12 = _Last[-1].m_DiffuseModulation.y;
  _Val.m_pBoneToWorld = m_pBoneToWorld;
  v14 = *((_DWORD *)&_Last[-1] + 22);
  _Val.m_hInstance = (unsigned __int16)m_pColorMeshInfo;
  LODWORD(_Val.m_DiffuseModulation.y) = v12;
  _Val.m_DiffuseModulation.z = _Last[-1].m_DiffuseModulation.z;
  _Val.m_DiffuseModulation.w = _Last[-1].m_DiffuseModulation.w;
  *(_QWORD *)&_Val.m_Entry.m_pRenderable = *(_QWORD *)&_Last[-1].m_Entry.m_pRenderable;
  *((_DWORD *)&_Val + 22) ^= (*((_DWORD *)&_Val + 22) ^ v14) & 0x3FFFFFF;
  CModelRenderSystem::RenderModelInfo_t::operator=(this: _Last - 1, __that: _First);
  std::_Adjust_heap<CModelRenderSystem::RenderModelInfo_t *,int,CModelRenderSystem::RenderModelInfo_t,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
    _First,
    _Hole: 0,
    _Bottom: ((char *)_Last - (char *)_First - 92) / 92,
    &_Val,
    _Pred);
}

//------------------------------------------------------------------------------
// Address: 0x10125ED0
// Name: struct std::pair<struct CModelRenderSystem::RenderModelInfo_t __near *,struct CModelRenderSystem::RenderModelInfo_t __near *> std::_Unguarded_partition<struct CModelRenderSystem::RenderModelInfo_t __near *,bool (*)(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &)>(struct CModelRenderSystem::RenderModelInfo_t __near *,struct CModelRenderSystem::RenderModelInfo_t __near *,bool (*)(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &))
// Source: json
//------------------------------------------------------------------------------
std::pair<CModelRenderSystem::RenderModelInfo_t *,CModelRenderSystem::RenderModelInfo_t *> *__cdecl std::_Unguarded_partition<CModelRenderSystem::RenderModelInfo_t *,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
        std::pair<CModelRenderSystem::RenderModelInfo_t *,CModelRenderSystem::RenderModelInfo_t *> *result,
        CModelRenderSystem::RenderModelInfo_t *_First,
        CModelRenderSystem::RenderModelInfo_t *_Last,
        bool (__cdecl *_Pred)(const CModelRenderSystem::RenderModelInfo_t *, const CModelRenderSystem::RenderModelInfo_t *))
{
  CModelRenderSystem::RenderModelInfo_t *v4; // esi
  CModelRenderSystem::RenderModelInfo_t *v5; // ebx
  CModelRenderSystem::RenderModelInfo_t *v6; // eax
  CModelRenderSystem::RenderModelInfo_t *v7; // edi
  bool v8; // zf
  CModelRenderSystem::RenderModelInfo_t *v9; // ebx
  CModelRenderSystem::RenderModelInfo_t *v10; // eax
  CModelRenderSystem::RenderModelInfo_t *v12; // [esp-8h] [ebp-1Ch]
  CModelRenderSystem::RenderModelInfo_t *v13; // [esp-8h] [ebp-1Ch]
  CModelRenderSystem::RenderModelInfo_t *v14; // [esp-4h] [ebp-18h]
  CModelRenderSystem::RenderModelInfo_t *_Plast; // [esp+Ch] [ebp-8h]
  CModelRenderSystem::RenderModelInfo_t *_Glast; // [esp+10h] [ebp-4h]
  CModelRenderSystem::RenderModelInfo_t *_Glasta; // [esp+10h] [ebp-4h]

  v4 = &_First[(_Last - _First) / 2];
  std::_Median<CModelRenderSystem::RenderModelInfo_t *,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
    _First,
    _Mid: v4,
    _Last: _Last - 1,
    _Pred);
  v5 = v4 + 1;
  _Plast = v4 + 1;
  if ( _First < v4 )
  {
    do
    {
      _Glast = v4 - 1;
      if ( _Pred(a1: v4 - 1, a2: v4) )
        break;
      if ( _Pred(a1: v4, a2: _Glast) )
        break;
      --v4;
    }
    while ( _First < _Glast );
  }
  if ( v5 < _Last )
  {
    do
    {
      if ( _Pred(a1: v5, a2: v4) )
        break;
      if ( _Pred(a1: v4, a2: v5) )
        break;
      ++v5;
    }
    while ( v5 < _Last );
    _Plast = v5;
  }
  v6 = v4;
  v7 = v5;
  for ( _Glasta = v4; ; v6 = _Glasta )
  {
    while ( 1 )
    {
      if ( v7 < _Last )
      {
        do
        {
          if ( !_Pred(a1: v4, a2: v7) )
          {
            if ( _Pred(a1: v7, a2: v4) )
              break;
            v12 = v5++;
            std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: v12, _Right: v7);
          }
          ++v7;
        }
        while ( v7 < _Last );
        v6 = _Glasta;
        _Plast = v5;
      }
      v8 = v6 == _First;
      if ( v6 > _First )
      {
        v9 = v6 - 1;
        do
        {
          if ( !_Pred(a1: v9, a2: v4) )
          {
            if ( _Pred(a1: v4, a2: v9) )
              break;
            std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: --v4, _Right: v9);
          }
          --v9;
          --_Glasta;
        }
        while ( _First < _Glasta );
        v6 = _Glasta;
        v5 = _Plast;
        v8 = _Glasta == _First;
      }
      if ( v8 )
        break;
      v10 = v6 - 1;
      _Glasta = v10;
      if ( v7 == _Last )
      {
        if ( v10 != --v4 )
          std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: v10, _Right: v4);
        _Plast = --v5;
        std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: v4, _Right: v5);
        v6 = _Glasta;
      }
      else
      {
        std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: v7, _Right: v10);
        v6 = _Glasta;
        ++v7;
      }
    }
    if ( v7 == _Last )
      break;
    if ( v5 != v7 )
      std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: v4, _Right: v5);
    v14 = v7;
    ++v5;
    v13 = v4;
    _Plast = v5;
    ++v4;
    ++v7;
    std::swap<CModelRenderSystem::RenderModelInfo_t>(_Left: v13, _Right: v14);
  }
  result->first = v4;
  result->second = v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10126090
// Name: void std::_Sort<struct CModelRenderSystem::ModelListByType_t __near *,int,bool (*)(struct CModelRenderSystem::ModelListByType_t const __near &,struct CModelRenderSystem::ModelListByType_t const __near &)>(struct CModelRenderSystem::ModelListByType_t __near *,struct CModelRenderSystem::ModelListByType_t __near *,int,bool (*)(struct CModelRenderSystem::ModelListByType_t const __near &,struct CModelRenderSystem::ModelListByType_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort<CModelRenderSystem::ModelListByType_t *,int,bool (__cdecl *)(CModelRenderSystem::ModelListByType_t const &,CModelRenderSystem::ModelListByType_t const &)>(
        CModelRenderSystem::ModelListByType_t *_First,
        CModelRenderSystem::ModelListByType_t *_Last,
        int _Ideal,
        bool (__cdecl *_Pred)(const CModelRenderSystem::ModelListByType_t *, const CModelRenderSystem::ModelListByType_t *))
{
  CModelRenderSystem::ModelListByType_t *second; // ebx
  CModelRenderSystem::ModelListByType_t *first; // edi
  int v6; // eax
  std::pair<CModelRenderSystem::ModelListByType_t *,CModelRenderSystem::ModelListByType_t *> _Mid; // [esp+Ch] [ebp-8h] BYREF

  second = _First;
  first = _Last;
  v6 = _Last - _First;
  if ( v6 <= 32 )
  {
LABEL_7:
    if ( v6 > 1 )
      std::_Insertion_sort1<CModelRenderSystem::ModelListByType_t *,bool (__cdecl *)(CModelRenderSystem::ModelListByType_t const &,CModelRenderSystem::ModelListByType_t const &),CModelRenderSystem::ModelListByType_t>(
        _First: second,
        _Last: first,
        _Pred);
  }
  else
  {
    while ( _Ideal > 0 )
    {
      std::_Unguarded_partition<CModelRenderSystem::ModelListByType_t *,bool (__cdecl *)(CModelRenderSystem::ModelListByType_t const &,CModelRenderSystem::ModelListByType_t const &)>(
        result: &_Mid,
        _First: second,
        _Last: first,
        _Pred);
      _Ideal = _Ideal / 2 / 2 + _Ideal / 2;
      if ( _Mid.first - second >= first - _Mid.second )
      {
        std::_Sort<CModelRenderSystem::ModelListByType_t *,int,bool (__cdecl *)(CModelRenderSystem::ModelListByType_t const &,CModelRenderSystem::ModelListByType_t const &)>(
          _First: _Mid.second,
          _Last: first,
          _Ideal,
          _Pred);
        first = _Mid.first;
      }
      else
      {
        std::_Sort<CModelRenderSystem::ModelListByType_t *,int,bool (__cdecl *)(CModelRenderSystem::ModelListByType_t const &,CModelRenderSystem::ModelListByType_t const &)>(
          _First: second,
          _Last: _Mid.first,
          _Ideal,
          _Pred);
        second = _Mid.second;
      }
      v6 = first - second;
      if ( v6 <= 32 )
        goto LABEL_7;
    }
    if ( first - second > 1 )
      std::_Make_heap<CModelRenderSystem::ModelListByType_t *,int,CModelRenderSystem::ModelListByType_t,bool (__cdecl *)(CModelRenderSystem::ModelListByType_t const &,CModelRenderSystem::ModelListByType_t const &)>(
        _First: second,
        _Last: first,
        _Pred);
    std::_Sort_heap<CModelRenderSystem::ModelListByType_t *,bool (__cdecl *)(CModelRenderSystem::ModelListByType_t const &,CModelRenderSystem::ModelListByType_t const &)>(
      _First: second,
      _Last: first,
      _Pred);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101261D0
// Name: void std::_Sort_heap<struct CModelRenderSystem::RenderModelInfo_t __near *,bool (*)(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &)>(struct CModelRenderSystem::RenderModelInfo_t __near *,struct CModelRenderSystem::RenderModelInfo_t __near *,bool (*)(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<CModelRenderSystem::RenderModelInfo_t *,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
        CModelRenderSystem::RenderModelInfo_t *_First,
        CModelRenderSystem::RenderModelInfo_t *_Last,
        bool (__cdecl *_Pred)(const CModelRenderSystem::RenderModelInfo_t *, const CModelRenderSystem::RenderModelInfo_t *))
{
  CModelRenderSystem::RenderModelInfo_t *v3; // edi
  int i; // esi

  v3 = _Last;
  for ( i = (char *)_Last - (char *)_First; i / 92 > 1; --v3 )
  {
    std::_Pop_heap_0<CModelRenderSystem::RenderModelInfo_t *,CModelRenderSystem::RenderModelInfo_t,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
      _First,
      _Last: v3,
      _Pred,
      __formal: nullptr);
    i -= 92;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126230
// Name: private: void CModelRenderSystem::SortBucketsByDependency(int,struct CModelRenderSystem::ModelListByType_t __near *,struct CModelRenderSystem::LightingList_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::SortBucketsByDependency(
        CModelRenderSystem *this,
        int nModelTypeCount,
        CModelRenderSystem::ModelListByType_t *pModelList,
        CModelRenderSystem::LightingList_t *pLightingList)
{
  int v4; // edx
  RenderableLightingModel_t *p_m_nLightingModel; // ecx
  CModelRenderSystem::LightingList_t *v6; // eax

  std::_Sort<CModelRenderSystem::ModelListByType_t *,int,bool (__cdecl *)(CModelRenderSystem::ModelListByType_t const &,CModelRenderSystem::ModelListByType_t const &)>(
    _First: pModelList,
    _Last: &pModelList[nModelTypeCount],
    _Ideal: 48 * nModelTypeCount / 48,
    _Pred: (bool (__cdecl *)(const CModelRenderSystem::ModelListByType_t *, const CModelRenderSystem::ModelListByType_t *))CModelRenderSystem::DependencySortLessFunc);
  v4 = nModelTypeCount - 1;
  if ( nModelTypeCount - 1 >= 0 )
  {
    p_m_nLightingModel = &pModelList[v4].m_nLightingModel;
    do
    {
      if ( *p_m_nLightingModel != LIGHTING_MODEL_NONE )
      {
        v6 = &pLightingList[*p_m_nLightingModel];
        p_m_nLightingModel[7] = (RenderableLightingModel_t)v6->m_pFirstModel;
        ++v6->m_nCount;
        v6->m_pFirstModel = (CModelRenderSystem::ModelListByType_t *)(p_m_nLightingModel - 4);
        v6->m_nTotalModelCount += *((_DWORD *)p_m_nLightingModel + 3);
      }
      p_m_nLightingModel -= 12;
      --v4;
    }
    while ( v4 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101262B0
// Name: void std::_Sort<struct CModelRenderSystem::RenderModelInfo_t __near *,int,bool (*)(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &)>(struct CModelRenderSystem::RenderModelInfo_t __near *,struct CModelRenderSystem::RenderModelInfo_t __near *,int,bool (*)(struct CModelRenderSystem::RenderModelInfo_t const __near &,struct CModelRenderSystem::RenderModelInfo_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort<CModelRenderSystem::RenderModelInfo_t *,int,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
        CModelRenderSystem::RenderModelInfo_t *_First,
        CModelRenderSystem::RenderModelInfo_t *_Last,
        int _Ideal,
        bool (__cdecl *_Pred)(const CModelRenderSystem::RenderModelInfo_t *, const CModelRenderSystem::RenderModelInfo_t *))
{
  CModelRenderSystem::RenderModelInfo_t *second; // ebx
  CModelRenderSystem::RenderModelInfo_t *first; // edi
  int v6; // eax
  std::pair<CModelRenderSystem::RenderModelInfo_t *,CModelRenderSystem::RenderModelInfo_t *> _Mid; // [esp+Ch] [ebp-8h] BYREF

  second = _First;
  first = _Last;
  v6 = _Last - _First;
  if ( v6 <= 32 )
  {
LABEL_7:
    if ( v6 > 1 )
      std::_Insertion_sort1<CModelRenderSystem::RenderModelInfo_t *,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &),CModelRenderSystem::RenderModelInfo_t>(
        _First: second,
        _Last: first,
        _Pred);
  }
  else
  {
    while ( _Ideal > 0 )
    {
      std::_Unguarded_partition<CModelRenderSystem::RenderModelInfo_t *,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
        result: &_Mid,
        _First: second,
        _Last: first,
        _Pred);
      _Ideal = _Ideal / 2 / 2 + _Ideal / 2;
      if ( _Mid.first - second >= first - _Mid.second )
      {
        std::_Sort<CModelRenderSystem::RenderModelInfo_t *,int,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
          _First: _Mid.second,
          _Last: first,
          _Ideal,
          _Pred);
        first = _Mid.first;
        second = _First;
      }
      else
      {
        std::_Sort<CModelRenderSystem::RenderModelInfo_t *,int,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
          _First,
          _Last: _Mid.first,
          _Ideal,
          _Pred);
        second = _Mid.second;
        _First = _Mid.second;
      }
      v6 = first - second;
      if ( v6 <= 32 )
        goto LABEL_7;
    }
    if ( first - second > 1 )
      std::_Make_heap<CModelRenderSystem::RenderModelInfo_t *,int,CModelRenderSystem::RenderModelInfo_t,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
        _First: second,
        _Last: first,
        _Pred);
    std::_Sort_heap<CModelRenderSystem::RenderModelInfo_t *,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
      _First: second,
      _Last: first,
      _Pred);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126400
// Name: private: void CModelRenderSystem::SortModels(struct CModelRenderSystem::RenderModelInfo_t __near *,int,int,struct CModelRenderSystem::ModelListByType_t __near *,struct CModelRenderSystem::ModelListNode_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::SortModels(
        CModelRenderSystem *this,
        CModelRenderSystem::RenderModelInfo_t *pRenderModelInfo,
        int nListTotal,
        int nModelTypeCount,
        CModelRenderSystem::ModelListByType_t *pModelList,
        CModelRenderSystem::ModelListNode_t *pModelListNode)
{
  CModelRenderSystem::RenderModelInfo_t *v6; // esi
  int *p_m_nSetupBoneCount; // ebx
  _DWORD *v8; // edi
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int nListTotala; // [esp+10h] [ebp+Ch]

  v6 = pRenderModelInfo;
  memset(dst: (int)pRenderModelInfo, value: nullptr, count: 92 * nListTotal);
  if ( nModelTypeCount > 0 )
  {
    p_m_nSetupBoneCount = &pModelList->m_nSetupBoneCount;
    for ( nListTotala = nModelTypeCount; nListTotala != 0; --nListTotala )
    {
      v8 = (_DWORD *)*(p_m_nSetupBoneCount - 2);
      p_m_nSetupBoneCount[2] = (int)v6;
      for ( *p_m_nSetupBoneCount = 0; v8 != nullptr; v8 = (_DWORD *)v8[5] )
      {
        *(_QWORD *)&v6->m_Entry.m_pRenderable = *(_QWORD *)v8;
        *(_DWORD *)&v6->m_Entry.m_InstanceData.m_nAlpha = v8[2];
        v6->m_nLOD = (int)v8[3] >> 25;
        v6->m_nSkin = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v8 + 148))(a1: *v8);
        v6->m_nBody = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v8 + 40))(a1: *v8);
        v6->m_hInstance = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v8 + 124))(a1: *v8);
        v9 = *((_DWORD *)v6 + 22);
        v6->m_Decals = nullptr;
        *((_DWORD *)v6 + 22) ^= (v8[3] ^ v9) & 0xFFFFFF;
        v10 = *((_DWORD *)v6 + 22) ^ (*((_DWORD *)v6 + 22) ^ (2 * v8[3])) & 0x2000000;
        *((_DWORD *)v6++ + 22) = v10;
        *((_DWORD *)&v6[-1] + 22) = v10 ^ (v10 ^ ((v8[1] == 0) << 24)) & 0x1000000;
        LOBYTE(v10) = *((_BYTE *)&v6[-1] + 91);
        v6[-1].m_pStencilState = (ShaderStencilState_t *)v8[4];
        *p_m_nSetupBoneCount += v10 & 1;
      }
      std::_Sort<CModelRenderSystem::RenderModelInfo_t *,int,bool (__cdecl *)(CModelRenderSystem::RenderModelInfo_t const &,CModelRenderSystem::RenderModelInfo_t const &)>(
        _First: (CModelRenderSystem::RenderModelInfo_t *)p_m_nSetupBoneCount[2],
        _Last: (CModelRenderSystem::RenderModelInfo_t *)(p_m_nSetupBoneCount[2] + 92 * *(p_m_nSetupBoneCount - 1)),
        _Ideal: 92 * *(p_m_nSetupBoneCount - 1) / 92,
        _Pred: CModelRenderSystem::SortLessFunc);
      v11 = *p_m_nSetupBoneCount;
      *(p_m_nSetupBoneCount - 1) -= *p_m_nSetupBoneCount;
      *p_m_nSetupBoneCount = v11 + *(p_m_nSetupBoneCount - 1);
      p_m_nSetupBoneCount += 12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126540
// Name: public: virtual void CModelRenderSystem::DrawModels(struct ModelRenderSystemData_t __near *,int,enum ModelRenderMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::DrawModels(
        CModelRenderSystem *this,
        ModelRenderSystemData_t *pEntities,
        memhandle_t__ **nCount,
        ModelRenderMode_t renderMode)
{
  int v4; // ebx
  void (*BeginLock)(void); // edx
  IMatRenderContext *v7; // esi
  void *v8; // esp
  void *v9; // esp
  void *v10; // esp
  CModelRenderSystem *v11; // edi
  int (__thiscall *GetMappingHeight)(ITexture *); // edx
  IMatRenderContext *m_pObject; // ebx
  _BYTE v14[12]; // [esp+0h] [ebp-5Ch] BYREF
  CModelRenderSystem::LightingList_t pLightingList[3]; // [esp+Ch] [ebp-50h] BYREF
  CMatRenderData<CModelRenderSystem::RenderModelInfo_t> rdRenderModelInfo; // [esp+30h] [ebp-2Ch] BYREF
  StudioModelArrayInfo2_t info; // [esp+40h] [ebp-1Ch] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+48h] [ebp-14h]
  CMatRenderContextPtr matRenderContext; // [esp+4Ch] [ebp-10h]
  CModelRenderSystem::ModelListNode_t *pModelListNode; // [esp+50h] [ebp-Ch]
  CModelRenderSystem *v21; // [esp+54h] [ebp-8h]
  memhandle_t__ **pColorMeshHandles; // [esp+58h] [ebp-4h]
  int savedregs; // [esp+5Ch] [ebp+0h] BYREF
  int nColorMeshHandles; // [esp+64h] [ebp+8h]

  v4 = (int)nCount;
  v21 = this;
  if ( nCount != nullptr && (cl_skipfastpath.m_pParent == nullptr || cl_skipfastpath.m_pParent->m_Value.m_nValue == 0) )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CModelRenderSystem::DrawModels",
      a3: 0,
      a4: "Fast Path Model Rendering",
      a5: false,
      a6: 4);
    BeginLock = (void (*)(void))g_pMDLCache->BeginLock;
    cacheCriticalSection.m_pCache = g_pMDLCache;
    BeginLock();
    v7 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    matRenderContext.m_pObject = v7;
    if ( v7 != nullptr )
      v7->BeginRender(this: v7);
    this->m_DefaultCubemap.m_pTexture = (ITexture *)v7;
    v7->AddRefRenderData(this: v7);
    pColorMeshHandles = nullptr;
    if ( renderMode == MODEL_RENDER_MODE_NORMAL )
    {
      v8 = alloca(4 * v4);
      pColorMeshHandles = (memhandle_t__ **)v14;
    }
    v9 = alloca(48 * v4);
    v10 = alloca(24 * v4);
    v11 = (CModelRenderSystem *)((char *)this - 12);
    pModelListNode = (CModelRenderSystem::ModelListNode_t *)v14;
    nCount = (memhandle_t__ **)CModelRenderSystem::BucketModelsByMDL(
                                 this: v11,
                                 pModelList: (CModelRenderSystem::ModelListByType_t *)v14,
                                 pModelListNodes: (CModelRenderSystem::ModelListNode_t *)v14,
                                 pEntities,
                                 nCount: v4,
                                 renderMode,
                                 pModelsRenderingStencilCountOut: (int *)&nCount);
    memset(pLightingList, 0, sizeof(pLightingList));
    CModelRenderSystem::SortBucketsByDependency(
      this: v11,
      nModelTypeCount: (int)nCount,
      pModelList: (CModelRenderSystem::ModelListByType_t *)v14,
      pLightingList);
    CModelRenderSystem::ComputeModelLODs(
      this: v11,
      nModelTypeCount: (int)nCount,
      pModelList: (CModelRenderSystem::ModelListByType_t *)v14,
      pModelListNode,
      renderMode);
    GetMappingHeight = v21->m_DefaultCubemap.m_pTexture->__vftable[3].GetMappingHeight;
    rdRenderModelInfo.m_pRenderContext = (IMatRenderContext *)v21->m_DefaultCubemap.m_pTexture;
    rdRenderModelInfo.m_nCount = v4;
    rdRenderModelInfo.m_pRenderData = (CModelRenderSystem::RenderModelInfo_t *)((int (__stdcall *)(int))GetMappingHeight)(a1: 92 * v4);
    rdRenderModelInfo.m_bNeedsUnlock = true;
    CModelRenderSystem::SortModels(
      this: v11,
      pRenderModelInfo: rdRenderModelInfo.m_pRenderData,
      nListTotal: v4,
      nModelTypeCount: (int)nCount,
      pModelList: (CModelRenderSystem::ModelListByType_t *)v14,
      pModelListNode);
    CModelRenderSystem::SetupBones(
      this: v11,
      a2: (int)&savedregs,
      nModelTypeCount: (int)nCount,
      pModelList: (CModelRenderSystem::ModelListByType_t *)v14);
    if ( renderMode != MODEL_RENDER_MODE_RTT_SHADOWS )
      CModelRenderSystem::SetupFlexes(
        this: v11,
        a2: v4,
        a3: (int)v11,
        a4: (int)v14,
        nModelTypeCount: (int)nCount,
        pModelList: (CModelRenderSystem::ModelListByType_t *)v14);
    nColorMeshHandles = CModelRenderSystem::SetupLighting(
                          this: v11,
                          pLightingList,
                          nModelTypeCount: nCount,
                          pModelList: (CModelRenderSystem::ModelListByType_t *)v14,
                          pColorMeshHandles,
                          renderMode);
    CModelRenderSystem::SetupFlashlightsAndDecals(
      this: v11,
      pInfo: &info,
      nModelTypeCount: (ModelRenderMode_t)nCount,
      pModelList: (CModelRenderSystem::ModelListByType_t *)v14,
      nTotalModelCount: v4,
      pRenderModels: rdRenderModelInfo.m_pRenderData,
      renderMode);
    CModelRenderSystem::SetupPerInstanceColorModulation(
      this: v11,
      nModelTypeCount: (CModelRenderSystem::ModelListByType_t *)nCount,
      pModelList: (CModelRenderSystem::ModelListByType_t *)v14);
    CModelRenderSystem::RenderModels(
      this: v11,
      pInfo: &info,
      nModelTypeCount: (int)nCount,
      pModelList: (CModelRenderSystem::ModelListByType_t *)v14,
      nTotalModelCount: v4,
      renderMode);
    m_pObject = matRenderContext.m_pObject;
    matRenderContext.m_pObject->ReleaseRenderData(this: matRenderContext.m_pObject);
    if ( renderMode == MODEL_RENDER_MODE_NORMAL )
      modelrender->CleanupStaticLightingState(this: modelrender, a2: nColorMeshHandles, a3: pColorMeshHandles);
    CMemoryStack::FreeAll(this: (CMemoryStack *)&v21->m_pNext, bDecommit: false);
    if ( renderMode == MODEL_RENDER_MODE_NORMAL )
    {
      CModelRenderSystem::RenderVCollideDebugOverlay(
        this: v11,
        nModelTypeCount: (int)nCount,
        pModelList: (CModelRenderSystem::ModelListByType_t *)v14);
      CModelRenderSystem::RenderBBoxDebugOverlay(
        this: v11,
        nModelTypeCount: (CModelRenderSystem::ModelListByType_t *)nCount,
        pModelList: (CModelRenderSystem::ModelListByType_t *)v14);
    }
    v21->m_DefaultCubemap.m_pTexture = nullptr;
    CMatRenderData<matrix3x4_t>::~CMatRenderData<matrix3x4_t>(this: &rdRenderModelInfo);
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
    cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101267C0
// Name: public: virtual void CModelRenderSystem::ComputeTranslucentRenderData(struct ModelRenderSystemData_t __near *,int,struct TranslucentInstanceRenderData_t __near *,struct TranslucentTempData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelRenderSystem::ComputeTranslucentRenderData(
        CModelRenderSystem *this,
        ModelRenderSystemData_t *pModels,
        int nCount,
        TranslucentInstanceRenderData_t *pRenderData,
        TranslucentTempData_t *pTempData)
{
  int v5; // ebx
  TranslucentTempData_t *v7; // eax
  void (*BeginLock)(void); // edx
  IMatRenderContext *v9; // esi
  TranslucentTempData_t *v10; // eax
  void *v11; // esp
  void *v12; // esp
  CModelRenderSystem *v13; // edi
  memhandle_t__ **v14; // ebx
  void *v15; // esp
  int v16; // eax
  CModelRenderSystem::RenderModelInfo_t *v17; // edx
  IMatRenderContext *m_pObject; // esi
  _BYTE v19[12]; // [esp+0h] [ebp-48h] BYREF
  CModelRenderSystem::LightingList_t pLightingList[3]; // [esp+Ch] [ebp-3Ch] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+30h] [ebp-18h]
  CMatRenderContextPtr matRenderContext; // [esp+34h] [ebp-14h]
  memhandle_t__ **pColorMeshHandles; // [esp+38h] [ebp-10h] BYREF
  memhandle_t__ **m_pColorMeshHandles; // [esp+3Ch] [ebp-Ch]
  CModelRenderSystem *v25; // [esp+40h] [ebp-8h]
  CModelRenderSystem::ModelListNode_t *pModelListNode; // [esp+44h] [ebp-4h]
  int savedregs; // [esp+48h] [ebp+0h] BYREF

  v5 = nCount;
  v25 = this;
  if ( nCount != 0 )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CModelRenderSystem::ComputeTranslucentRenderData",
      a3: 0,
      a4: "Fast Path Model Rendering",
      a5: false,
      a6: 4);
    BeginLock = (void (*)(void))g_pMDLCache->BeginLock;
    cacheCriticalSection.m_pCache = g_pMDLCache;
    BeginLock();
    v9 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    matRenderContext.m_pObject = v9;
    if ( v9 != nullptr )
      v9->BeginRender(this: v9);
    this->m_DefaultCubemap.m_pTexture = (ITexture *)v9;
    v9->AddRefRenderData(this: v9);
    v10 = pTempData;
    pTempData->m_bReleaseRenderData = true;
    m_pColorMeshHandles = v10->m_pColorMeshHandles;
    v11 = alloca(48 * v5);
    v12 = alloca(24 * v5);
    v13 = (CModelRenderSystem *)((char *)this - 12);
    pModelListNode = (CModelRenderSystem::ModelListNode_t *)v19;
    v14 = (memhandle_t__ **)CModelRenderSystem::BucketModelsByMDL(
                              this: v13,
                              pModelList: (CModelRenderSystem::ModelListByType_t *)v19,
                              pModelListNodes: (CModelRenderSystem::ModelListNode_t *)v19,
                              pEntities: pModels,
                              nCount: v5,
                              renderMode: MODEL_RENDER_MODE_NORMAL,
                              pModelsRenderingStencilCountOut: (int *)&pModels);
    memset(pLightingList, 0, sizeof(pLightingList));
    CModelRenderSystem::SortBucketsByDependency(
      this: v13,
      nModelTypeCount: (int)v14,
      pModelList: (CModelRenderSystem::ModelListByType_t *)v19,
      pLightingList);
    CModelRenderSystem::ComputeModelLODs(
      this: v13,
      nModelTypeCount: (int)v14,
      pModelList: (CModelRenderSystem::ModelListByType_t *)v19,
      pModelListNode,
      renderMode: 0);
    v15 = alloca(92 * nCount);
    pModels = (ModelRenderSystemData_t *)v19;
    CModelRenderSystem::SortModels(
      this: v13,
      pRenderModelInfo: (CModelRenderSystem::RenderModelInfo_t *)v19,
      nListTotal: nCount,
      nModelTypeCount: (int)v14,
      pModelList: (CModelRenderSystem::ModelListByType_t *)v19,
      pModelListNode);
    CModelRenderSystem::SetupBones(
      this: v13,
      a2: (int)&savedregs,
      nModelTypeCount: (int)v14,
      pModelList: (CModelRenderSystem::ModelListByType_t *)v19);
    CModelRenderSystem::SetupFlexes(
      this: v13,
      a2: (int)v14,
      a3: (int)v13,
      a4: (int)v19,
      nModelTypeCount: (int)v14,
      pModelList: (CModelRenderSystem::ModelListByType_t *)v19);
    v16 = CModelRenderSystem::SetupLighting(
            this: v13,
            pLightingList,
            nModelTypeCount: v14,
            pModelList: (CModelRenderSystem::ModelListByType_t *)v19,
            pColorMeshHandles: m_pColorMeshHandles,
            renderMode: 0);
    v17 = (CModelRenderSystem::RenderModelInfo_t *)pModels;
    pTempData->m_nColorMeshHandleCount = v16;
    CModelRenderSystem::SetupFlashlightsAndDecals(
      this: v13,
      pInfo: (StudioModelArrayInfo2_t *)&pColorMeshHandles,
      nModelTypeCount: (ModelRenderMode_t)v14,
      pModelList: (CModelRenderSystem::ModelListByType_t *)v19,
      nTotalModelCount: nCount,
      pRenderModels: v17,
      renderMode: MODEL_RENDER_MODE_NORMAL);
    CModelRenderSystem::SetupPerInstanceColorModulation(
      this: v13,
      nModelTypeCount: (CModelRenderSystem::ModelListByType_t *)v14,
      pModelList: (CModelRenderSystem::ModelListByType_t *)v19);
    CModelRenderSystem::SetupTranslucentData(
      this: v13,
      nModelTypeCount: (int)v14,
      pModelList: (CModelRenderSystem::ModelListByType_t *)v19,
      nTotalModelCount: nCount,
      pRenderData);
    CMemoryStack::FreeAll(this: (CMemoryStack *)&v25->m_pNext, bDecommit: false);
    CModelRenderSystem::RenderVCollideDebugOverlay(
      this: v13,
      nModelTypeCount: (int)v14,
      pModelList: (CModelRenderSystem::ModelListByType_t *)v19);
    CModelRenderSystem::RenderBBoxDebugOverlay(
      this: v13,
      nModelTypeCount: (CModelRenderSystem::ModelListByType_t *)v14,
      pModelList: (CModelRenderSystem::ModelListByType_t *)v19);
    m_pObject = matRenderContext.m_pObject;
    v25->m_DefaultCubemap.m_pTexture = nullptr;
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
    cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    v7 = pTempData;
    pTempData->m_nColorMeshHandleCount = 0;
    v7->m_bReleaseRenderData = false;
  }
}
