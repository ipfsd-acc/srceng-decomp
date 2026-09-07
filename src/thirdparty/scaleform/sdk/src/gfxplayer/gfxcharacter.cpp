// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxcharacter.cpp
// Functions: 152
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxcharacter.h"

//------------------------------------------------------------------------------
// Address: 0x1001BE10
// Name: public: virtual class GFxCharacterDef __near * GFxGenericCharacter::GetCharacterDef(void)const
// Source: json
//------------------------------------------------------------------------------
CFunctor *__thiscall GFxGenericCharacter::GetCharacterDef(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this)
{
  return *((CFunctor **)this + 30);
}

//------------------------------------------------------------------------------
// Address: 0x1003BBA0
// Name: public: virtual bool GFxASCharacter::OnLosingKeyboardFocus(class GFxASCharacter __near *,unsigned int,enum GFxFocusMovedType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::OnLosingKeyboardFocus(
        CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        int a2,
        IMesh *__formal,
        unsigned int controllerIdx)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10066100
// Name: public: GFxASCharacter::GeomDataType::GeomDataType(void)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall GFxASCharacter::GeomDataType::GeomDataType(
        CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  const CMaterialDict::MissingMaterial_t *v3; // [esp+0h] [ebp-4h]

  GMatrix2D::SetIdentity(result: v3);
  *((double *)&this->m_Proxy.m_pfnProxied + 1) = 0.0;
  this->m_nUserID = 0;
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = nullptr;
  *(double *)&this->m_Proxy.m_pfnProxied = 100.0;
  *(double *)&this->CRefCountServiceDestruct<CRefST> = 100.0;
  *((double *)this + 8) = 100.0;
  *((double *)this + 10) = 0.0;
  *((double *)this + 9) = 0.0;
  *((double *)this + 7) = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100685F0
// Name: public: GASFnCall::GASFnCall(class GASValue __near *,class GASObjectInterface __near *,class GASEnvironment __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
GASFnCall *__thiscall GASFnCall::GASFnCall(
        GASFnCall *this,
        tagALTTABINFO *a2,
        tagALTTABINFO *NargsIn,
        tagALTTABINFO *a4,
        tagALTTABINFO *a5,
        tagALTTABINFO *FirstIn)
{
  *(this + 1) = a2;
  *(this + 2) = NargsIn;
  *this = (GASFnCall)&GASFnCall::`vftable';
  *((_BYTE *)this + 20) = 0;
  *(this + 3) = nullptr;
  *(this + 4) = nullptr;
  *(this + 6) = a4;
  *(this + 7) = a5;
  *(this + 8) = FirstIn;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10082AE0
// Name: public: void GFxFilterDesc::SetIdentity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFilterDesc::SetIdentity(char *this)
{
  float *v2; // edi

  v2 = (float *)(this + 76);
  *this = 6;
  memset(dst: (unsigned __int8 *)this + 76, value: 0, count: 0x50u);
  *v2 = 1.0;
  *((float *)this + 24) = 1.0;
  *((float *)this + 29) = 1.0;
  *((float *)this + 34) = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10082B10
// Name: protected: void GFxCharacter::SetTopmostLevelFlag(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxCharacter::SetTopmostLevelFlag(
        CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *this,
        bool v)
{
  int result; // eax

  if ( v )
  {
    *((_WORD *)this + 59) |= 2u;
  }
  else
  {
    *((_WORD *)this + 59) &= ~2u;
    return 65533;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10082B30
// Name: public: void GFxASCharacter::SetNoAdvanceLocalFlag(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::SetNoAdvanceLocalFlag(
        CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v)
{
  if ( (_BYTE)v != 0 )
    *((_DWORD *)this + 40) |= 4u;
  else
    *((_DWORD *)this + 40) &= ~4u;
}

//------------------------------------------------------------------------------
// Address: 0x10082B50
// Name: protected: void GFxASCharacter::SetTrackAsMenuFlag(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::SetTrackAsMenuFlag(
        CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v)
{
  if ( (_BYTE)v != 0 )
    *((_DWORD *)this + 40) |= 0x2000u;
  else
    *((_DWORD *)this + 40) &= ~0x2000u;
}

//------------------------------------------------------------------------------
// Address: 0x10082B80
// Name: protected: void GFxASCharacter::SetEnabledFlag(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::SetEnabledFlag(
        CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v)
{
  if ( (_BYTE)v != 0 )
    *((_DWORD *)this + 40) |= 0x10u;
  else
    *((_DWORD *)this + 40) &= ~0x10u;
}

//------------------------------------------------------------------------------
// Address: 0x10082BA0
// Name: protected: void GFxASCharacter::SetTabEnabledFlag(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::SetTabEnabledFlag(
        CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v)
{
  if ( (_BYTE)v != 0 )
    *((_DWORD *)this + 40) |= 0x60u;
  else
    *((_DWORD *)this + 40) = *((_DWORD *)this + 40) & 0xFFFFFF9F | 0x40;
}

//------------------------------------------------------------------------------
// Address: 0x10082BD0
// Name: protected: void GFxASCharacter::SetFocusRectFlag(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::SetFocusRectFlag(
        CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v)
{
  if ( (_BYTE)v != 0 )
    *((_DWORD *)this + 40) |= 0x180u;
  else
    *((_DWORD *)this + 40) = *((_DWORD *)this + 40) & 0xFFFFFE7F | 0x100;
}

//------------------------------------------------------------------------------
// Address: 0x10082C10
// Name: protected: void GFxASCharacter::SetUseHandCursorFlag(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::SetUseHandCursorFlag(
        CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v)
{
  if ( (_BYTE)v != 0 )
    *((_DWORD *)this + 40) |= 0x600u;
  else
    *((_DWORD *)this + 40) = *((_DWORD *)this + 40) & 0xFFFFF9FF | 0x400;
}

//------------------------------------------------------------------------------
// Address: 0x10082C50
// Name: public: class GFxKeyboardState __near * GFxMovieRoot::GetKeyboardState(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const GRenderer::FillTexture *__thiscall GFxMovieRoot::GetKeyboardState(char *this, unsigned int result)
{
  if ( result >= 4 )
    return nullptr;
  else
    return (const GRenderer::FillTexture *)(this + 1660 * result + 2516);
}

//------------------------------------------------------------------------------
// Address: 0x10082C80
// Name: public: class GFxMouseState const __near * GFxMovieRoot::GetMouseState(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMovieRoot::GetMouseState(
        ScaleformRenderer *this@<ecx>,
        ScaleformRenderer::VertexDeclType mouseIndex,
        bool a3)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10082CA0
// Name: public: float GFxCharacter::GetPerspectiveFOV(bool)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxCharacter::GetPerspectiveFOV(GFxCharacter *this, bool a2)
{
  GFxCharacter *v2; // esi
  int v3; // eax

  v2 = this;
  if ( 0.0 == *((float *)this + 26) )
  {
    while ( a2 )
    {
      v3 = *((_DWORD *)v2 + 8);
      if ( v3 == 0 )
      {
        if ( (*(int (__thiscall **)(GFxCharacter *))(*(_DWORD *)v2 + 84))(a1: v2) != 0 )
          return *(float *)((*(int (__thiscall **)(GFxCharacter *))(*(_DWORD *)v2 + 84))(a1: v2) + 236);
        else
          return *((float *)v2 + 26);
      }
      v2 = *((GFxCharacter **)v2 + 8);
      if ( 0.0 != *(float *)(v3 + 104) )
        return *((float *)v2 + 26);
    }
  }
  return *((float *)v2 + 26);
}

//------------------------------------------------------------------------------
// Address: 0x10082D20
// Name: public: virtual void GFxCharacter::UpdateViewAndPerspective(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlMemory<unsigned char,int> *__thiscall GFxCharacter::UpdateViewAndPerspective(_DWORD *this)
{
  const CUtlMemory<unsigned char,int> *v2; // eax

  v2 = (const CUtlMemory<unsigned char,int> *)(*(int (__thiscall **)(_DWORD *))(*this + 84))(a1: this);
  if ( v2 != nullptr && *(this + 25) != 0 && *(this + 24) != 0 )
    return GRenderer::MakeViewAndPersp3D(result: v2 + 12);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10082D60
// Name: public: void GFxCharacter::GetWorldMatrix(class GMatrix2D __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::GetWorldMatrix(GFxCharacter *this, CMaterialDict *pmat)
{
  GFxCharacter *v3; // ecx

  v3 = *((GFxCharacter **)this + 8);
  if ( v3 != nullptr )
  {
    GFxCharacter::GetWorldMatrix(this: v3, a2: (struct GMatrix2D *)pmat);
    GMatrix2D::Prepend(this: (GMatrix2D *)pmat, a2: (const struct GMatrix2D *)((char *)this + 68));
  }
  else
  {
    *(struct GMatrix2D *)&pmat->m_MaterialDict.m_LessFunc = *(struct GMatrix2D *)((char *)this + 68);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082DC0
// Name: public: void GFxCharacter::GetLevelMatrix(class GMatrix2D __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::GetLevelMatrix(GFxCharacter *this, CMaterialDict *pmat)
{
  GFxCharacter *v3; // ecx
  const CMaterialDict::MissingMaterial_t *v4; // [esp+0h] [ebp-24h]
  struct GMatrix2D v10; // 0:^C.24

  v3 = *((GFxCharacter **)this + 8);
  if ( v3 != nullptr )
  {
    GFxCharacter::GetLevelMatrix(this: v3, a2: (struct GMatrix2D *)pmat);
    GMatrix2D::Prepend(this: (GMatrix2D *)pmat, a2: (const struct GMatrix2D *)((char *)this + 68));
  }
  else
  {
    GMatrix2D::SetIdentity(result: v4);
    *(struct GMatrix2D *)&pmat->m_MaterialDict.m_LessFunc = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082E40
// Name: public: void GFxCharacter::GetWorldCxform(class GRenderer::Cxform __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::GetWorldCxform(
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pcxform)
{
  CMatRenderContextBase *m_pObject; // ecx

  m_pObject = this->m_Proxy.m_pObject;
  if ( m_pObject != nullptr )
  {
    GFxCharacter::GetWorldCxform(
      this: (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)m_pObject,
      pcxform);
    GRenderer::Cxform::Concatenate(
      this: (GRenderer::Cxform *)pcxform,
      a2: (const struct GRenderer::Cxform *)(&this->m_Proxy.m_pObject + 1));
  }
  else
  {
    qmemcpy(pcxform, &this->m_Proxy.m_pObject + 1, 0x20u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082E80
// Name: public: bool GFxCharacter::Is3D(bool)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxCharacter::Is3D(
        _DWORD *this,
        CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *result)
{
  if ( (_BYTE)result == 0 )
    return *(this + 23) != 0;
  while ( *(this + 23) == 0 )
  {
    if ( *(this + 8) == 0 )
      return *(this + 23) != 0;
    this = (_DWORD *)*(this + 8);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10082EC0
// Name: public: class GMatrix3D GFxCharacter::GetLocalMatrix3D(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::GetLocalMatrix3D(
        CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *this,
        CBasePerMaterialContextData *a2)
{
  int (__cdecl *v2)(CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *); // esi
  GMatrix3D v3; // [esp+Ch] [ebp-84h] BYREF
  _BYTE v4[64]; // [esp+4Ch] [ebp-44h] BYREF

  v2 = *((int (__cdecl **)(CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *))this + 23);
  if ( v2 == nullptr )
    v2 = GMatrix3D::Identity;
  qmemcpy(a2, v2, 0x40u);
  GMatrix3D::GMatrix3D(this: &v3, a2: (const struct GMatrix2D *)((char *)this + 68));
  qmemcpy(v4, a2, sizeof(v4));
  GMatrix3D::MultiplyMatrix(this: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10082F30
// Name: public: void GFxCharacter::GetWorldMatrix3D(class GMatrix3D __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::GetWorldMatrix3D(
        CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *this,
        CMatQueuedMesh::MST_MeshInfo_t *pmat)
{
  CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *v3; // ecx
  int (__cdecl *v4)(CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *); // eax
  int (__cdecl *v5)(CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *); // esi
  GMatrix3D v6; // [esp+10h] [ebp-104h] BYREF
  _BYTE v7[64]; // [esp+50h] [ebp-C4h]
  _BYTE v8[64]; // [esp+90h] [ebp-84h] BYREF
  _QWORD v9[8]; // [esp+D0h] [ebp-44h] BYREF

  v3 = *((CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> **)this
       + 8);
  if ( v3 != nullptr )
  {
    GFxCharacter::GetWorldMatrix3D(this: v3, pmat);
    v4 = *((int (__cdecl **)(CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *))this + 23);
    if ( v4 == nullptr )
      v4 = GMatrix3D::Identity;
    qmemcpy(v9, v4, sizeof(v9));
    GMatrix3D::GMatrix3D(this: &v6, a2: (const struct GMatrix2D *)((char *)this + 68));
    qmemcpy(v7, v9, sizeof(v7));
    GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)v9);
    qmemcpy(v8, pmat, sizeof(v8));
    GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)pmat);
  }
  else
  {
    v5 = *((int (__cdecl **)(CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *))this + 23);
    if ( v5 == nullptr )
      v5 = GMatrix3D::Identity;
    qmemcpy(v9, v5, sizeof(v9));
    GMatrix3D::GMatrix3D(this: &v6, a2: (const struct GMatrix2D *)((char *)this + 68));
    qmemcpy(v8, v9, sizeof(v8));
    GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)v9);
    qmemcpy(pmat, v9, 64);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083050
// Name: public: class GMatrix3D const __near * GFxCharacter::GetPerspective3D(bool)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxCharacter::GetPerspective3D(_DWORD *this, bool checkAncestors)
{
  _DWORD *v2; // esi
  int v3; // eax

  v2 = this;
  if ( *(this + 24) == 0 )
  {
    while ( checkAncestors )
    {
      v3 = v2[8];
      if ( v3 == 0 )
      {
        if ( (*(int (__thiscall **)(_DWORD *))(*v2 + 84))(a1: v2) != 0 )
          return *(_DWORD *)((*(int (__thiscall **)(_DWORD *))(*v2 + 84))(a1: v2) + 200);
        else
          return 0;
      }
      v2 = (_DWORD *)v2[8];
      if ( *(_DWORD *)(v3 + 96) != 0 )
        return v2[24];
    }
  }
  return v2[24];
}

//------------------------------------------------------------------------------
// Address: 0x100830B0
// Name: public: class GMatrix3D const __near * GFxCharacter::GetView3D(bool)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxCharacter::GetView3D(_DWORD *this, bool checkAncestors)
{
  _DWORD *v2; // esi
  int v3; // eax

  v2 = this;
  if ( *(this + 25) == 0 )
  {
    while ( checkAncestors )
    {
      v3 = v2[8];
      if ( v3 == 0 )
      {
        if ( (*(int (__thiscall **)(_DWORD *))(*v2 + 84))(a1: v2) != 0 )
          return *(_DWORD *)((*(int (__thiscall **)(_DWORD *))(*v2 + 84))(a1: v2) + 204);
        else
          return 0;
      }
      v2 = (_DWORD *)v2[8];
      if ( *(_DWORD *)(v3 + 100) != 0 )
        return v2[25];
    }
  }
  return v2[25];
}

//------------------------------------------------------------------------------
// Address: 0x10083110
// Name: public: enum GRenderer::BlendType GFxCharacter::GetActiveBlendMode(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::GetActiveBlendMode(
        CMemberFuncProxy2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CFuncMemPolicyNone> *this)
{
  CMemberFuncProxy2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CFuncMemPolicyNone> *i; // esi

  for ( i = this;
        i != nullptr;
        i = (CMemberFuncProxy2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CFuncMemPolicyNone> *)DWORD2(i[1].m_pfnProxied) )
  {
    if ( (*(int (__thiscall **)(CMemberFuncProxy2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CFuncMemPolicyNone> *))(LODWORD(i->m_pfnProxied) + 20))(a1: i) > 2 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083140
// Name: public: unsigned int GFxCharacter::GetVersion(void)const
// Source: json
//------------------------------------------------------------------------------
const void *__thiscall GFxCharacter::GetVersion(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *this)
{
  int v1; // eax

  v1 = (*(int (__thiscall **)(CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 92))(a1: this);
  return (*(const void *(__thiscall **)(int))(*(_DWORD *)v1 + 16))(a1: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10083150
// Name: public: virtual class GASEnvironment __near * GFxCharacter::GetASEnvironment(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::GetASEnvironment(
        CMemberFunctor0<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  CMatQueuedRenderContext *m_pObject; // esi
  _TAPE_WMI_OPERATIONS *v2; // eax
  _TAPE_WMI_OPERATIONS *v3; // [esp+0h] [ebp-4h]

  m_pObject = this->m_Proxy.m_pObject;
  if ( m_pObject != nullptr )
  {
    while ( (*(int (__thiscall **)(int *))(m_pObject->m_MatrixStacks[0].m_Memory.m_nGrowSize + 8))(a1: &m_pObject->m_MatrixStacks[0].m_Memory.m_nGrowSize) != 2 )
    {
      m_pObject = (CMatQueuedRenderContext *)m_pObject->m_pCurrentFrameBufferCopyTexture[0];
      if ( m_pObject == nullptr )
        return;
    }
    v2 = GASObjectInterface::ToSprite(result: v3);
    (*(void (__thiscall **)(_TAPE_WMI_OPERATIONS *))(v2->Method + 112))(a1: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100831A0
// Name: public: virtual class GASEnvironment const __near * GFxCharacter::GetASEnvironment(void)const
// Source: json
//------------------------------------------------------------------------------
const struct GASEnvironment *__thiscall GFxCharacter::GetASEnvironment(GFxCharacter *this)
{
  return (*(const struct GASEnvironment *(__thiscall **)(GFxCharacter *))(*(_DWORD *)this + 112))(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x100831B0
// Name: public: bool GFxCharacter::CheckLastHitResult(float,float)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxCharacter::CheckLastHitResult(int this, float x, float y)
{
  return (*(_BYTE *)(this + 118) & 0xC) != 0 && *(float *)(this + 108) == x && *(float *)(this + 112) == y;
}

//------------------------------------------------------------------------------
// Address: 0x100831F0
// Name: public: void GFxCharacter::SetLastHitResult(float,float,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::SetLastHitResult(GFxCharacter *this, float x, float y, bool result)
{
  __int16 v4; // dx

  v4 = *((_WORD *)this + 59);
  *((float *)this + 27) = x;
  *((float *)this + 28) = y;
  *((_WORD *)this + 59) = v4 & 0xFFF3 | (4 * result + 4);
}

//------------------------------------------------------------------------------
// Address: 0x10083230
// Name: public: void GFxCharacter::InvalidateHitResult(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::InvalidateHitResult(GFxCharacter *this)
{
  *((_WORD *)this + 59) &= 0xFFF3u;
}

//------------------------------------------------------------------------------
// Address: 0x10083240
// Name: public: GFxCharacterHandle::~GFxCharacterHandle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacterHandle::~GFxCharacterHandle(GFxCharacterHandle *this)
{
  int v2; // ecx
  bool v3; // zf
  int v4; // ecx
  int v5; // ecx

  v2 = (int)*(this + 4);
  v3 = (*(_DWORD *)(v2 + 8))-- == 1;
  if ( v3 )
    GASStringNode::ReleaseNode();
  v4 = (int)*(this + 3);
  v3 = (*(_DWORD *)(v4 + 8))-- == 1;
  if ( v3 )
    GASStringNode::ReleaseNode();
  v5 = (int)*(this + 2);
  v3 = (*(_DWORD *)(v5 + 8))-- == 1;
  if ( v3 )
    GASStringNode::ReleaseNode();
}

//------------------------------------------------------------------------------
// Address: 0x10083270
// Name: public: class GFxASCharacter __near * GFxCharacterHandle::ResolveCharacter(class GFxMovieRoot __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacterHandle::ResolveCharacter(
        CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        GFxMovieRoot *a2)
{
  if ( this->m_nUserID == 0 )
    GFxMovieRoot::FindTarget(this: a2, a2: (const struct GASString *)&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x10083290
// Name: public: class GFxASCharacter __near * GFxCharacterHandle::ForceResolveCharacter(class GFxMovieRoot __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacterHandle::ForceResolveCharacter(
        CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        GFxMovieRoot *a2)
{
  GFxMovieRoot::FindTarget(this: a2, a2: (const struct GASString *)&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x100832B0
// Name: public: unsigned short GFxASCharacter::GetFocusGroupMask(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::GetFocusGroupMask(
        CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  CMatQueuedRenderContext *m_pObject; // ecx
  __int16 v3; // ax

  if ( *((_WORD *)this + 83) == 0 )
  {
    m_pObject = this->m_Proxy.m_pObject;
    if ( m_pObject != nullptr )
    {
      GFxASCharacter::GetFocusGroupMask(this: (CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)m_pObject);
      *((_WORD *)this + 83) = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100832E0
// Name: public: virtual bool GFxASCharacter::IsFocusAllowed(class GFxMovieRoot __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxASCharacter::IsFocusAllowed(GFxASCharacter *this, struct GFxMovieRoot *a2, unsigned int a3)
{
  GFxASCharacter *v3; // edx
  char v4; // si
  CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v5; // ecx
  __int16 v6; // ax

  v3 = this;
  v4 = *((_BYTE *)a2 + a3 + 10228);
  if ( *((_WORD *)this + 83) == 0 )
  {
    v5 = *((CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)this
         + 8);
    if ( v5 != nullptr )
    {
      GFxASCharacter::GetFocusGroupMask(this: v5);
      *((_WORD *)v3 + 83) = v6;
    }
  }
  return (*((unsigned __int16 *)v3 + 83) & (1 << v4)) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10083330
// Name: protected: virtual void GFxASCharacter::UpdateAlphaFlag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::UpdateAlphaFlag(GFxASCharacter *this)
{
  float v1; // [esp+0h] [ebp-4h]
  float v2; // [esp+0h] [ebp-4h]

  v1 = fabs(*((float *)this + 15));
  if ( v1 >= 0.001 || (v2 = fabs(*((float *)this + 16))) >= 1.0 )
    *((_DWORD *)this + 40) &= ~2u;
  else
    *((_DWORD *)this + 40) |= 2u;
}

//------------------------------------------------------------------------------
// Address: 0x10083380
// Name: public: static void GFxASCharacter::CharacterGetDepth(class GASFnCall const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GFxASCharacter::CharacterGetDepth(GASObjectInterface **fn)
{
  struct GFxASCharacter *v1; // eax
  GASObjectInterface *v2; // esi
  int v3; // edi

  v1 = GASObjectInterface::ToASCharacter(this: fn[2]);
  if ( v1 == nullptr )
    v1 = *((struct GFxASCharacter **)fn[6] + 29);
  v2 = fn[1];
  v3 = *((_DWORD *)v1 + 5);
  if ( *(_BYTE *)v2 >= 5u )
    GASValue::DropRefs(this: (GASValue *)v2);
  *((_DWORD *)v2 + 1) = v3 - 0x4000;
  *(_BYTE *)v2 = 4;
}

//------------------------------------------------------------------------------
// Address: 0x100833C0
// Name: void GFxASCharacter_MatrixScaleAndRotate2x2(class GMatrix2D __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
float *__stdcall GFxASCharacter_MatrixScaleAndRotate2x2(float *x11, float sx, float sy, float x01)
{
  float *result; // eax
  float sinAngle; // [esp+0h] [ebp-10h]
  float x10; // [esp+4h] [ebp-Ch]
  float cosAngle; // [esp+8h] [ebp-8h]
  float x00; // [esp+Ch] [ebp-4h]
  float x00a; // [esp+Ch] [ebp-4h]
  float x11a; // [esp+18h] [ebp+8h]
  float x01a; // [esp+24h] [ebp+14h]
  float x01b; // [esp+24h] [ebp+14h]

  x00 = cos(x01);
  cosAngle = x00;
  x01a = sin(x01);
  result = x11;
  sinAngle = x01a;
  x00a = *x11;
  x01b = x11[1];
  x10 = x11[3];
  x11a = x11[4];
  *result = (x00a * cosAngle - x10 * sinAngle) * sx;
  result[1] = (x01b * cosAngle - x11a * sinAngle) * sy;
  result[3] = (x10 * cosAngle + x00a * sinAngle) * sx;
  result[4] = sy * (sinAngle * x01b + cosAngle * x11a);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10083470
// Name: public: void GFxASCharacter::RemoveDisplayObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::RemoveDisplayObject(GFxASCharacter *this)
{
  GMemoryFile *v2; // eax
  _TAPE_WMI_OPERATIONS *v3; // [esp+0h] [ebp-4h]

  if ( *((_DWORD *)this + 8) != 0 )
  {
    v2 = (GMemoryFile *)GASObjectInterface::ToSprite(result: v3);
    if ( v2 != nullptr )
      GFxSprite::RemoveDisplayObject(this: v2, depth: *((GFile **)this + 5), id: *((_DWORD *)this + 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100834A0
// Name: public: void GFxASCharacter::SetProtoToPrototypeOf(class GASObjectInterface __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::SetProtoToPrototypeOf(
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        unsigned int psrcObj)
{
  int (__thiscall *AddRef)(struct CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *); // edx
  _DWORD *v4; // esi
  int v5; // ebx
  struct GASObject *v6; // eax
  GASValue prototype[4]; // [esp+Ch] [ebp-10h] BYREF

  AddRef = this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable[7].AddRef;
  LOBYTE(prototype[0]) = 0;
  v4 = (_DWORD *)(AddRef(this) + 120);
  if ( (*(unsigned __int8 (__thiscall **)(unsigned int, _DWORD *, int, GASValue *))(*(_DWORD *)psrcObj + 44))(
         a1: psrcObj,
         a2: v4,
         a3: *v4 + 316,
         a4: prototype) != 0 )
  {
    v5 = *((_DWORD *)this + 30);
    v6 = GASValue::ToObject(this: prototype, a2: nullptr);
    (*(void (__thiscall **)(char *, _DWORD *, struct GASObject *))(v5 + 52))(a1: (char *)this + 120, a2: v4, a3: v6);
  }
  GASValue::~GASValue(this: prototype);
}

//------------------------------------------------------------------------------
// Address: 0x10083500
// Name: public: virtual bool GFxASCharacter::IsFocusRectEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxASCharacter::IsFocusRectEnabled(GFxASCharacter *this)
{
  GFxASCharacter *v3; // eax

  if ( (*((_DWORD *)this + 40) & 0x180) != 0 )
    return (*((_DWORD *)this + 40) & 0x180) == 384;
  v3 = (GFxASCharacter *)(*(int (__thiscall **)(GFxASCharacter *, int))(*(_DWORD *)this + 104))(a1: this, a2: 1);
  return v3 == this || (*(bool (__thiscall **)(GFxASCharacter *))(*(_DWORD *)v3 + 216))(a1: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10083540
// Name: public: void GFxASCharacter::RemoveFromPreDisplayList(class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *__thiscall GFxASCharacter::RemoveFromPreDisplayList(
        _DWORD *this,
        const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *result)
{
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v3; // eax

  v3 = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)(*(this + 40) >> 21);
  if ( (*(this + 40) & 0x200000) != 0 )
  {
    v3 = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)GFxMovieRoot::RemoveFromPreDisplayList();
    *(this + 40) &= ~0x200000u;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10083570
// Name: public: virtual bool GFxGenericCharacter::PointTestLocal(class GPoint<float> const __near &,unsigned char)const
// Source: json
//------------------------------------------------------------------------------
CFunctor *__userpurge GFxGenericCharacter::PointTestLocal@<eax>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this@<ecx>,
        CMatRenderContextBase *pt,
        __int128 hitTestMask,
        const MaterialFogMode_t *a4)
{
  return (*(CFunctor *(__thiscall **)(_DWORD, CMatRenderContextBase *, _DWORD, CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *))(**((_DWORD **)this + 30) + 20))(
           a1: *((_DWORD *)this + 30),
           a2: pt,
           a3: hitTestMask & 1,
           a4: this);
}

//------------------------------------------------------------------------------
// Address: 0x100835A0
// Name: public: bool GFxCharacter::IsUnloading(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::IsUnloading(
        CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100835C0
// Name: public: class GMatrix2D GFxCharacter::GetWorldMatrix(void)const
// Source: json
//------------------------------------------------------------------------------
CMaterialDict *__thiscall GFxCharacter::GetWorldMatrix(int this, CMaterialDict *result)
{
  GFxCharacter *v3; // ecx
  const CMaterialDict::MissingMaterial_t *v5; // [esp+0h] [ebp-8h]

  GMatrix2D::SetIdentity(result: v5);
  v3 = *(GFxCharacter **)(this + 32);
  if ( v3 != nullptr )
  {
    GFxCharacter::GetWorldMatrix(this: v3, pmat: result);
    GMatrix2D::Prepend(this: (GMatrix2D *)result, a2: (const struct GMatrix2D *)(this + 68));
  }
  else
  {
    *(CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > *)&result->m_MaterialDict.m_LessFunc = *(CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > *)(this + 68);
    *(float *)&result->m_MaterialDict.m_Root = *(float *)(this + 84);
    *(float *)&result->m_MaterialDict.m_FirstFree = *(float *)(this + 88);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10083620
// Name: public: virtual GFxCharacter::~GFxCharacter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::~GFxCharacter(
        void *this,
        CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *result)
{
  void *v3; // eax

  v3 = *((void **)this + 23);
  *(_DWORD *)this = &GFxCharacter::`vftable'{for `GRefCountBaseWeakSupport<GFxCharacter,322>'};
  *((_DWORD *)this + 3) = &GFxCharacter::`vftable'{for `GFxLogBase<GFxCharacter>'};
  if ( v3 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
    *((_DWORD *)this + 23) = 0;
  }
  if ( *((_DWORD *)this + 24) != 0 )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 24));
    *((_DWORD *)this + 24) = 0;
  }
  if ( *((_DWORD *)this + 25) != 0 )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 25));
    *((_DWORD *)this + 25) = 0;
  }
  *((_DWORD *)this + 3) = &GFxLogBase<GFxLoadProcess>::`vftable';
  JUMPOUT(0x100646D0);
}

//------------------------------------------------------------------------------
// Address: 0x100836A0
// Name: public: virtual void GFxCharacter::SetOriginalName(class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxCharacter::SetOriginalName(
        CMemberFuncProxy2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CFuncMemPolicyNone> *this,
        _IMAGE_SYMBOL_EX *name)
{
  return (*(void *(__thiscall **)(CMemberFuncProxy2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CFuncMemPolicyNone> *, _IMAGE_SYMBOL_EX *))(LODWORD(this->m_pfnProxied) + 40))(
           a1: this,
           a2: name);
}

//------------------------------------------------------------------------------
// Address: 0x100836B0
// Name: public: virtual void GFxCharacter::GetBounds(class GPoint<float> __near *,class GMatrix3D const __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::GetBounds(
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        int pts,
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *a3,
        int bDivideByW)
{
  _BYTE v4[16]; // [esp+0h] [ebp-10h] BYREF

  ((void (__thiscall *)(CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *, _BYTE *, GMatrix2D *))this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable[3].Release)(
    a1: this,
    a2: v4,
    a3: &GMatrix2D::Identity);
  GMatrix3D::EncloseTransform(this: a3, pts);
}

//------------------------------------------------------------------------------
// Address: 0x100836E0
// Name: public: virtual class GFxMovieRoot __near * GFxCharacter::GetMovieRoot(void)const
// Source: json
//------------------------------------------------------------------------------
struct GFxMovieRoot *__thiscall GFxCharacter::GetMovieRoot(GFxCharacter *this)
{
  if ( *((_DWORD *)this + 8) != 0 )
    return (*(struct GFxMovieRoot *(__thiscall **)(_DWORD))(**((_DWORD **)this + 8) + 84))(a1: *((_DWORD *)this + 8));
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10083700
// Name: public: virtual class GFxMovieDefImpl __near * GFxCharacter::GetResourceMovieDef(void)const
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor0<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall GFxCharacter::GetResourceMovieDef(
        _DWORD **this,
        CMemberFunctor0<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result)
{
  return (*(CMemberFunctor0<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *(__thiscall **)(_DWORD, CMemberFunctor0<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *))(**(this + 8) + 92))(
           a1: *(this + 8),
           a2: result);
}

//------------------------------------------------------------------------------
// Address: 0x10083710
// Name: public: virtual class GFxFontManager __near * GFxCharacter::GetFontManager(void)const
// Source: json
//------------------------------------------------------------------------------
struct GFxFontManager *__thiscall GFxCharacter::GetFontManager(GFxCharacter *this)
{
  return (*(struct GFxFontManager *(__thiscall **)(_DWORD))(**((_DWORD **)this + 8) + 96))(a1: *((_DWORD *)this + 8));
}

//------------------------------------------------------------------------------
// Address: 0x10083720
// Name: public: virtual class GFxASCharacter __near * GFxCharacter::GetLevelMovie(int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::GetLevelMovie(
        CMemberFunctor0<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const matrix3x4_t *level)
{
  this->m_Proxy.m_pObject->MultMatrix(this: this->m_Proxy.m_pObject, a2: level);
}

//------------------------------------------------------------------------------
// Address: 0x10083730
// Name: public: virtual class GFxASCharacter __near * GFxCharacter::GetASRootMovie(bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::GetASRootMovie(
        CMemberFunctor0<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        CMatQueuedRenderContext *ignoreLockRoot,
        __int128 a3)
{
  ((void (__thiscall *)(CMatQueuedRenderContext *, CMatQueuedRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD))this->m_Proxy.m_pObject->MultMatrix_2)(
    a1: this->m_Proxy.m_pObject,
    a2: ignoreLockRoot,
    a3,
    a4: DWORD1(a3),
    a5: DWORD2(a3),
    a6: HIDWORD(a3));
}

//------------------------------------------------------------------------------
// Address: 0x10083740
// Name: public: virtual void GFxCharacter::OnEventLoad(void)
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *__thiscall GFxCharacter::OnEventLoad(
        void *this)
{
  CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *(__thiscall *v1)(void *, _DWORD *); // eax
  _DWORD v3[2]; // [esp+0h] [ebp-10h] BYREF
  __int16 v4; // [esp+8h] [ebp-8h]
  int v5; // [esp+Ah] [ebp-6h]

  v3[1] = 0;
  v1 = *(CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *(__thiscall **)(void *, _DWORD *))(*(_DWORD *)this + 128);
  v4 = 0;
  v3[0] = 1;
  v5 = 65280;
  return v1(a1: this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10083780
// Name: public: virtual bool GFxCharacter::OnKeyEvent(class GFxEventId const __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::OnKeyEvent(
        CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(MaterialLightingState_t const &),MaterialLightingState_t,CFuncMemPolicyNone> *this,
        const MaterialLightingState_t *id,
        int *pkeyMask)
{
  (*(void (__thiscall **)(CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(MaterialLightingState_t const &),MaterialLightingState_t,CFuncMemPolicyNone> *, const MaterialLightingState_t *))(LODWORD(this->m_pfnProxied) + 128))(
    a1: this,
    a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x100837A0
// Name: public: virtual void GFxCharacter::PropagateMouseEvent(class GFxEventId const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::PropagateMouseEvent(GFxCharacter *this, const struct GFxEventId *a2)
{
  (*(void (__thiscall **)(GFxCharacter *, const struct GFxEventId *))(*(_DWORD *)this + 128))(a1: this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x100837B0
// Name: public: virtual void GFxCharacter::PropagateKeyEvent(class GFxEventId const __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *,IMaterial *),IMesh *,IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall GFxCharacter::PropagateKeyEvent(
        void *this,
        CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *,IMaterial *),IMesh *,IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result)
{
  return (*(CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *,IMaterial *),IMesh *,IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *(__thiscall **)(void *, CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *,IMaterial *),IMesh *,IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *))(*(_DWORD *)this + 148))(
           a1: this,
           a2: result);
}

//------------------------------------------------------------------------------
// Address: 0x100837D0
// Name: public: virtual bool GFxCharacter::Has3D(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::Has3D(
        CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100837E0
// Name: public: void GFxCharacter::CreateMatrix3D(class GMatrix3DNewable __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::CreateMatrix3D(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *this,
        unsigned int pmat)
{
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *v2; // edi
  int v3; // ecx
  int (__thiscall *v4)(int, int, unsigned int *); // eax
  GMatrix3D *v5; // eax
  GMatrix3D *v6; // esi

  v2 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)pmat;
  if ( pmat == 0 )
    v2 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)((char *)this + 92);
  if ( LODWORD(v2->m_pfnProxied) == 0 )
  {
    v3 = *(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 84))(a1: this)
                   + 32);
    v4 = *(int (__thiscall **)(int, int, unsigned int *))(*(_DWORD *)v3 + 40);
    pmat = 322;
    v5 = (GMatrix3D *)v4(a1: v3, a2: 64, a3: &pmat);
    v6 = v5;
    if ( v5 != nullptr )
    {
      GMatrix3D::SetIdentity(this: v5);
      LODWORD(v2->m_pfnProxied) = v6;
    }
    else
    {
      LODWORD(v2->m_pfnProxied) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083840
// Name: protected: void GFxCharacter::SetDirtyFlag(void)
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *__thiscall GFxCharacter::SetDirtyFlag(
        void *this)
{
  CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *v1; // eax

  v1 = (CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *)(*(int (__thiscall **)(void *))(*(_DWORD *)this + 84))(a1: this);
  *((_DWORD *)&v1[388].m_pObject + 1) |= 0x400u;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10083860
// Name: public: void GFxCharacter::GetProjectedBounds(class GPoint<float> __near *,class GMatrix3D const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxCharacter::GetProjectedBounds(
        CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *this,
        float *a2,
        GMatrix3D *a3)
{
  CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *v3; // edi
  _DWORD *v4; // ecx
  _DWORD *v5; // ecx
  float v6; // esi
  int v7; // edx
  int (__thiscall *v8)(_DWORD); // eax
  int v9; // eax
  int v10; // eax
  int result; // eax
  double v12; // st7
  double v13; // st4
  double v14; // st3
  double v15; // st2
  float v16[13]; // [esp+Ch] [ebp-CCh] BYREF
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> visFrameRect; // [esp+40h] [ebp-98h] BYREF
  float v18; // [esp+4Ch] [ebp-8Ch]
  float v19; // [esp+50h] [ebp-88h]
  GMatrix3D v20; // [esp+54h] [ebp-84h]
  GMatrix3D pmat; // [esp+94h] [ebp-44h] BYREF

  v3 = this;
  v19 = *(float *)&this;
  GMatrix3D::SetIdentity(this: &pmat);
  if ( a3 != nullptr )
  {
    pmat = *a3;
    v3 = (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)LODWORD(v19);
  }
  else
  {
    GFxCharacter::GetWorldMatrix3D(this: v3, (CMatQueuedMesh::MST_MeshInfo_t *)&pmat);
  }
  if ( DWORD1(v3[4].m_pfnProxied) == 0 )
  {
    v4 = (_DWORD *)DWORD2(v3[1].m_pfnProxied);
    if ( v4 != nullptr )
    {
      GFxCharacter::GetView3D(this: v4, checkAncestors: true);
    }
    else if ( (*(int (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))(LODWORD(v3->m_pfnProxied) + 84))(a1: v3) != 0 )
    {
      (*(void (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))(LODWORD(v3->m_pfnProxied) + 84))(a1: v3);
    }
  }
  v20 = pmat;
  GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&pmat);
  if ( *(_DWORD *)(LODWORD(v19) + 96) == 0 )
  {
    v5 = *(_DWORD **)(LODWORD(v19) + 32);
    if ( v5 != nullptr )
    {
      GFxCharacter::GetPerspective3D(this: v5, checkAncestors: true);
    }
    else if ( (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v19) + 84))(a1: COERCE_FLOAT(LODWORD(v19))) != 0 )
    {
      (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v19) + 84))(a1: COERCE_FLOAT(LODWORD(v19)));
    }
  }
  v20 = pmat;
  GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&pmat);
  v6 = v19;
  v7 = *(_DWORD *)LODWORD(v19);
  v16[11] = 1.0;
  memset(v16, 0, 16);
  v16[10] = 1.0;
  memset(&v16[6], 0, 16);
  v16[12] = 0.0;
  v8 = *(int (__thiscall **)(_DWORD))(v7 + 84);
  LODWORD(v16[5]) = 1;
  LODWORD(v16[4]) = 1;
  v9 = v8(a1: LODWORD(v19));
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v9 + 104))(a1: v9, a2: v16);
  v10 = (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v6) + 84))(a1: COERCE_FLOAT(LODWORD(v6)));
  (*(void (__thiscall **)(int, CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *))(*(_DWORD *)v10 + 124))(
    a1: v10,
    a2: &visFrameRect);
  result = (*(int (__thiscall **)(float, float *, GMatrix3D *, int))(*(_DWORD *)LODWORD(v6) + 56))(
             a1: COERCE_FLOAT(LODWORD(v6)),
             a2,
             a3: &pmat,
             a4: 1);
  v12 = *(float *)&visFrameRect.m_pMemory;
  v19 = *(float *)&visFrameRect.m_nGrowSize - *(float *)&visFrameRect.m_pMemory;
  v13 = v19;
  *a2 = (*a2 + 1.0) * v19 * 0.5 + *(float *)&visFrameRect.m_pMemory;
  v14 = *(float *)&visFrameRect.m_nAllocationCount;
  v19 = v18 - *(float *)&visFrameRect.m_nAllocationCount;
  v15 = v19;
  a2[1] = (1.0 - a2[1]) * v19 * 0.5 + *(float *)&visFrameRect.m_nAllocationCount;
  a2[2] = (a2[2] + 1.0) * v13 * 0.5 + v12;
  a2[3] = (1.0 - a2[3]) * v15 * 0.5 + v14;
  a2[4] = (a2[4] + 1.0) * v13 * 0.5 + v12;
  a2[5] = (1.0 - a2[5]) * v15 * 0.5 + v14;
  a2[6] = v12 + v13 * (a2[6] + 1.0) * 0.5;
  a2[7] = v14 + 0.5 * ((1.0 - a2[7]) * v15);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10083AE0
// Name: public: virtual bool GFxCharacter::IsVerboseAction(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::IsVerboseAction(
        CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *this)
{
  (*(void (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 84))(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x10083B00
// Name: public: virtual bool GFxCharacter::IsVerboseActionErrors(void)const
// Source: json
//------------------------------------------------------------------------------
const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *,IMaterial *),IMesh *,IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall GFxCharacter::IsVerboseActionErrors(
        _DWORD *this)
{
  return (const CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *,IMaterial *),IMesh *,IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)((*(_DWORD *)((*(int (__thiscall **)(_DWORD *))(*(this - 3) + 84))(a1: this - 3) + 9332) & 0x40) == 0);
}

//------------------------------------------------------------------------------
// Address: 0x10083B20
// Name: public: struct GFxScale9GridInfo __near * GFxCharacter::CreateScale9Grid(float)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxCharacter::CreateScale9Grid(
        int a1@<ecx>,
        const CMaterialDict::MissingMaterial_t *a2@<edi>,
        const CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int,Rect_t *,Rect_t *),ITexture *,int,Rect_t *,Rect_t *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result)
{
  int v4; // esi
  CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> *v5; // edi
  CMatRenderContextBase *v6; // eax
  __int128 v7; // [esp+Ch] [ebp-64h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> bounds; // [esp+24h] [ebp-4Ch] BYREF
  int v10; // [esp+34h] [ebp-3Ch] BYREF
  const CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int,Rect_t *,Rect_t *),ITexture *,int,Rect_t *,Rect_t *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v11; // [esp+38h] [ebp-38h]
  _BYTE v12[24]; // [esp+3Ch] [ebp-34h] BYREF
  GMatrix2D v13; // [esp+54h] [ebp-1Ch] BYREF

  v11 = result;
  v4 = *(_DWORD *)(a1 + 32);
  v13.M_[0][0] = *(float *)(a1 + 68);
  v13.M_[0][1] = *(float *)(a1 + 72);
  v13.M_[0][2] = *(float *)(a1 + 76);
  v13.M_[1][0] = *(float *)(a1 + 80);
  v13.M_[1][1] = *(float *)(a1 + 84);
  v13.M_[1][2] = *(float *)(a1 + 88);
  if ( v4 != 0 )
  {
    while ( (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 76))(a1: v4) == 0 )
    {
      GMatrix2D::Append(this: &v13, a2: (const struct GMatrix2D *)(v4 + 68));
      v4 = *(_DWORD *)(v4 + 32);
      if ( v4 == 0 )
        return;
    }
    GMatrix2D::SetIdentity(result: a2);
    (*(void (__thiscall **)(int, CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *, _BYTE *))(*(_DWORD *)v4 + 64))(
      a1: v4,
      a2: &bounds,
      a3: v12);
    v10 = 265;
    v5 = (CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: a1, a3: 364, a4: &v10);
    if ( v5 != nullptr )
    {
      HIDWORD(v7) = &bounds;
      *((float *)&v7 + 2) = *(float *)&v11;
      DWORD1(v7) = &v13;
      LODWORD(v7) = v4 + 68;
      v6 = (CMatRenderContextBase *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 76))(a1: v4);
      GFxScale9GridInfo::GFxScale9GridInfo(this: v5, gr: v6, s9gMtx: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083C10
// Name: public: virtual void GFxCharacter::OnEventUnload(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxCharacter::OnEventUnload(_BYTE *this)
{
  __int16 v2; // ax
  GFxMovieRoot *v3; // eax
  char v4; // al
  int (__thiscall *v5)(_BYTE *, _DWORD *); // edx
  _DWORD v6[2]; // [esp+4h] [ebp-10h] BYREF
  __int16 v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+Eh] [ebp-6h]

  v2 = *((_WORD *)this + 59) | 0x100;
  *((_WORD *)this + 59) = v2;
  if ( (v2 & 2) != 0 )
  {
    v3 = (GFxMovieRoot *)(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 84))(a1: this);
    GFxMovieRoot::RemoveTopmostLevelCharacter(this: v3, a2: (struct GFxCharacter *)this);
  }
  v4 = *(this + 118) >> 4;
  if ( (*(this + 118) & 0x10) == 0 )
  {
    v5 = *(int (__thiscall **)(_BYTE *, _DWORD *))(*(_DWORD *)this + 128);
    v6[1] = 0;
    v7 = 0;
    v6[0] = 4;
    v8 = 65280;
    v4 = v5(a1: this, a2: v6);
    *((_WORD *)this + 59) |= 0x10u;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10083C80
// Name: public: virtual bool GFxASCharacter::IsFocusAllowed(class GFxMovieRoot __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxASCharacter::IsFocusAllowed(
        GFxASCharacter *this,
        struct GFxMovieRoot *a2,
        unsigned int controllerIdx)
{
  char v3; // si
  int v4; // edx
  CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v5; // ecx
  __int16 v6; // ax
  unsigned __int16 v7; // dx

  v3 = *((_BYTE *)a2 + controllerIdx + 10228);
  if ( *((_WORD *)this + 83) != 0 )
  {
    v7 = *((_WORD *)this + 83);
  }
  else
  {
    v4 = *((_DWORD *)this + 8);
    if ( *(_WORD *)(v4 + 166) == 0 )
    {
      v5 = *(CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(v4 + 32);
      if ( v5 != nullptr )
      {
        GFxASCharacter::GetFocusGroupMask(this: v5);
        *(_WORD *)(v4 + 166) = v6;
      }
    }
    v7 = *(_WORD *)(v4 + 166);
  }
  return (v7 & (1 << v3)) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10083CF0
// Name: public: void GFxASCharacter::AddToPlayList(class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *__thiscall GFxASCharacter::AddToPlayList(
        _DWORD *this,
        const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *result)
{
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v2; // eax
  int v3; // edx

  v2 = result;
  v3 = *((_DWORD *)&result[426].m_pObject + 1);
  if ( v3 != 0 )
  {
    *(_DWORD *)(v3 + 136) = this;
    *(this + 33) = *((_DWORD *)&result[426].m_pObject + 1);
  }
  *((_DWORD *)&result[426].m_pObject + 1) = this;
  *((_DWORD *)&result[388].m_pObject + 1) |= 0x400u;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10083D30
// Name: public: void GFxASCharacter::AddToOptimizedPlayList(class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
CMatQueuedMesh *__thiscall GFxASCharacter::AddToOptimizedPlayList(
        int this,
        const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *result)
{
  CMatQueuedMesh *m_pfnProxied; // eax

  m_pfnProxied = (CMatQueuedMesh *)(*(_DWORD *)(this + 160) >> 19);
  if ( (*(_DWORD *)(this + 160) & 0x80000) == 0 && ((int)*(&result[388].m_pObject + 1) & 0x80000) == 0 )
  {
    m_pfnProxied = (CMatQueuedMesh *)*(unsigned __int16 *)(this + 118);
    if ( (*(_WORD *)(this + 118) & 0x10) == 0
      && ((unsigned __int16)m_pfnProxied & 0x100) == 0
      && *(int *)(this + 20) >= -1 )
    {
      m_pfnProxied = *(CMatQueuedMesh **)(this + 136);
      if ( m_pfnProxied != nullptr )
      {
        while ( ((int)m_pfnProxied[2].IMesh::IVertexBuffer::__vftable & 0x80000) == 0 )
        {
          m_pfnProxied = *(CMatQueuedMesh **)&m_pfnProxied[1].m_VertexSize;
          if ( m_pfnProxied == nullptr )
            goto LABEL_9;
        }
        *(_DWORD *)(this + 140) = *(_DWORD *)&m_pfnProxied[1].m_bExternalIB;
        *(_DWORD *)&m_pfnProxied[1].m_bExternalIB = this;
      }
      else
      {
LABEL_9:
        m_pfnProxied = (CMatQueuedMesh *)result[427].m_pfnProxied;
        *(_DWORD *)(this + 140) = m_pfnProxied;
        LODWORD(result[427].m_pfnProxied) = this;
      }
      *(_DWORD *)(this + 160) |= 0x80000u;
      *((_DWORD *)&result[388].m_pObject + 1) |= 0x400u;
    }
  }
  return m_pfnProxied;
}

//------------------------------------------------------------------------------
// Address: 0x10083DE0
// Name: public: void GFxASCharacter::RemoveFromOptimizedPlaylist(class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
CMatQueuedMesh *__thiscall GFxASCharacter::RemoveFromOptimizedPlaylist(
        CMatQueuedMesh **this,
        const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *result)
{
  CMatQueuedMesh *v2; // eax

  v2 = (CMatQueuedMesh *)((unsigned int)*(this + 40) >> 19);
  if ( ((unsigned int)*(this + 40) & 0x80000) != 0 )
  {
    if ( ((int)*(&result[388].m_pObject + 1) & 0x80000) == 0 )
    {
      v2 = *(this + 34);
      if ( v2 != nullptr )
      {
        while ( ((int)v2[2].IMesh::IVertexBuffer::__vftable & 0x80000) == 0 )
        {
          v2 = *(CMatQueuedMesh **)&v2[1].m_VertexSize;
          if ( v2 == nullptr )
            goto LABEL_6;
        }
        *(_DWORD *)&v2[1].m_bExternalIB = *(this + 35);
      }
      else
      {
LABEL_6:
        v2 = *(this + 35);
        LODWORD(result[427].m_pfnProxied) = v2;
      }
    }
    *(this + 40) = (CMatQueuedMesh *)((unsigned int)*(this + 40) & 0xFFF7FFFF);
    *(this + 35) = nullptr;
    *((_DWORD *)&result[388].m_pObject + 1) |= 0x400u;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10083E70
// Name: public: virtual class GASGlobalContext __near * GFxASCharacter::GetGC(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::GetGC(
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialFogMode_t),enum MaterialFogMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable[5].Release(this);
}

//------------------------------------------------------------------------------
// Address: 0x10083E80
// Name: public: static bool GFxASCharacter::IsStandardMember(class GASString const __near &,class GASString __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::IsStandardMember(
        const MaterialPrimitiveType_t *memberName,
        _IMAGE_SYMBOL_EX *pcaseInsensitiveName,
        int *lowerCase)
{
  _IMAGE_SYMBOL_EX *v3; // esi
  int v4; // eax
  _IMAGE_SYMBOL_EX *v5; // eax
  int *v6; // esi
  bool v7; // zf
  _IMAGE_SYMBOL_EX *v8; // edi

  v3 = pcaseInsensitiveName;
  if ( (*(_DWORD *)(pcaseInsensitiveName->N.Name.Short + 12) & 0x20000000) == 0
    && GASString::GetLength(this: (GASString *)pcaseInsensitiveName) != 0 )
  {
    LOWORD(v4) = GASString::GetCharAt();
    if ( v4 == 95 )
    {
      GASString::ToLower(a1: v3, a2: &pcaseInsensitiveName);
      v5 = pcaseInsensitiveName;
      if ( (pcaseInsensitiveName->SectionNumber & 0x10000000) != 0 )
      {
        v6 = lowerCase;
        if ( lowerCase != nullptr )
        {
          ++pcaseInsensitiveName->Value;
          v7 = (*(_DWORD *)(*v6 + 8))-- == 1;
          v8 = v5;
          if ( v7 )
            GASStringNode::ReleaseNode();
          v5 = pcaseInsensitiveName;
          *v6 = (int)v8;
        }
        v7 = v5->Value-- == 1;
        if ( v7 )
          GASStringNode::ReleaseNode();
      }
      else
      {
        v7 = pcaseInsensitiveName->Value-- == 1;
        if ( v7 )
          GASStringNode::ReleaseNode();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083F10
// Name: public: struct GFxASCharacter::GeomDataType __near & GFxASCharacter::GetGeomData(struct GFxASCharacter::GeomDataType __near &)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxASCharacter::GetGeomData(
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *this@<ecx>,
        double a2@<st0>,
        _DWORD *fX)
{
  float v4; // esi
  int v5; // ecx
  float fY; // [esp+8h] [ebp-4h]

  if ( *((_DWORD *)this + 38) != 0 )
  {
    GFxASCharacter::GeomDataType::GeomDataType(result: *((CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)this
                                                       + 38));
  }
  else
  {
    CMaterial_QueueFriendly::GetAlphaModulation(this: (CMaterialDict::MaterialLookup_t *)((char *)this + 68));
    v4 = *(float *)&fX;
    *fX = (int)a2;
    GMatrix2D::GetY(this: (CMaterialDict::MaterialLookup_t *)((char *)this + 68));
    *(_DWORD *)(LODWORD(v4) + 4) = (int)a2;
    *(double *)(LODWORD(v4) + 8) = GMatrix2D::GetXScale(this: (GMatrix2D *)((char *)this + 68)) * 100.0;
    *(double *)(LODWORD(v4) + 16) = GMatrix2D::GetYScale(this: (GMatrix2D *)((char *)this + 68)) * 100.0;
    *(double *)(LODWORD(v4) + 24) = GMatrix2D::GetRotation(this: (GMatrix2D *)((char *)this + 68))
                                  * 180.0
                                  / 3.141592653589793;
    *(float *)(LODWORD(v4) + 32) = *((float *)this + 17);
    *(float *)(LODWORD(v4) + 36) = *((float *)this + 18);
    *(float *)(LODWORD(v4) + 40) = *((float *)this + 19);
    *(float *)(LODWORD(v4) + 44) = *((float *)this + 20);
    *(float *)(LODWORD(v4) + 48) = *((float *)this + 21);
    *(float *)(LODWORD(v4) + 52) = *((float *)this + 22);
    v5 = *((_DWORD *)this + 23);
    if ( v5 != 0 )
    {
      *(double *)(LODWORD(v4) + 56) = *(float *)(v5 + 56);
      *(double *)(LODWORD(v4) + 64) = *(float *)(v5 + 40) * 100.0;
      GMatrix3D::GetEulerAngles(this: (CBasePerMaterialContextData *)v5, eX: (const CBasePerMaterialContextData *)&fX);
      *(double *)(LODWORD(v4) + 72) = *(float *)&fX * 180.0 / 3.141592653589793;
      *(double *)(LODWORD(v4) + 80) = 180.0 * fY / 3.141592653589793;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084010
// Name: public: GFxASCharacter::GeomDataType::GeomDataType(struct GFxASCharacter::GeomDataType const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall GFxASCharacter::GeomDataType::GeomDataType(
        CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result)
{
  *this = *result;
  *((_OWORD *)this + 3) = result[1].CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >;
  *(CMemberFuncProxy2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CFuncMemPolicyNone> *)((char *)this + 64) = result[1].m_Proxy;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10084080
// Name: public: void GFxASCharacter::AddToPreDisplayList(class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *__fastcall GFxASCharacter::AddToPreDisplayList(
        const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *a1,
        int a2,
        const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *result)
{
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v3; // esi
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *i; // eax
  char v5; // cl

  v3 = a1;
  i = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)((unsigned int)a1[6].m_pObject >> 21);
  if ( ((int)a1[6].m_pObject & 0x200000) == 0 )
  {
LABEL_2:
    GFxMovieRoot::AddToPreDisplayList();
    v3[6].m_pObject = (CMatQueuedMesh *)((int)v3[6].m_pObject | 0x200000);
    for ( i = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)DWORD2(v3[1].m_pfnProxied);
          i != nullptr;
          i = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)DWORD2(i[1].m_pfnProxied) )
    {
      v5 = *((_BYTE *)&i[4].m_pObject + 6) >> 7;
      v3 = v5 != 0 ? i : nullptr;
      if ( v3 != nullptr && ((int)*(v5 != 0 ? &i[6].m_pObject : (CMatQueuedMesh **)160) & 0x200000) != 0 )
      {
        i = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)GFxMovieRoot::RemoveFromPreDisplayList();
        v3[6].m_pObject = (CMatQueuedMesh *)((int)v3[6].m_pObject & ~0x200000u);
        if ( ((int)v3[6].m_pObject & 0x200000) == 0 )
          goto LABEL_2;
        return i;
      }
    }
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x10084110
// Name: public: virtual class GFxASCharacter __near * GFxGenericCharacter::GetTopMostMouseEntity(class GPoint<float> const __near &,struct GFxCharacter::TopMostParams const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__userpurge GFxGenericCharacter::GetTopMostMouseEntity@<eax>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this@<ecx>,
        CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int,Rect_t *,Rect_t *),ITexture *,int,Rect_t *,Rect_t *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pt,
        __int128 params,
        const char *const *m)
{
  bool v5; // zf
  _DWORD *v6; // ecx
  int Perspective3D; // eax
  _DWORD *v8; // ecx
  int v9; // ebx
  int View3D; // edi
  _DWORD *v11; // ecx
  int v12; // eax
  int v13; // esi
  GFxSprite *v14; // ecx
  int v15; // eax
  int v17; // [esp+0h] [ebp-6Ch]
  CCountedStringPoolBase<unsigned int>::hash_item_t v18; // [esp+8h] [ebp-64h] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v19; // [esp+50h] [ebp-1Ch] BYREF
  float v20; // [esp+64h] [ebp-8h]

  if ( (*(unsigned __int8 (__thiscall **)(CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *))&this->m_pAllocator->m_bRegisteredAllocation)(a1: this) == 0 )
    return nullptr;
  v5 = *((_DWORD *)this + 23) == 0;
  v19.m_Memory.m_pMemory = *((CCountedStringPoolBase<unsigned int>::hash_item_t **)this + 17);
  v19.m_Memory.m_nAllocationCount = *((int *)this + 18);
  v19.m_Memory.m_nGrowSize = *((int *)this + 19);
  v19.m_Size = *((int *)this + 20);
  v19.m_pElements = *((CCountedStringPoolBase<unsigned int>::hash_item_t **)this + 21);
  v20 = *((float *)this + 22);
  if ( v5 )
  {
    v6 = *((_DWORD **)this + 8);
    if ( v6 == nullptr
      || GFxCharacter::Is3D(
           this: v6,
           result: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)1) == 0 )
    {
      GMatrix2D::TransformByInverse(this: &v19, result: &v18, p: (int)pt, a4: v17);
      goto LABEL_24;
    }
  }
  Perspective3D = *((_DWORD *)this + 24);
  if ( Perspective3D == 0 )
  {
    v8 = *((_DWORD **)this + 8);
    if ( v8 == nullptr )
    {
      if ( ((int (__thiscall *)(CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *))this->m_pAllocator[2].m_pCommitLimit)(a1: this) != 0 )
        v9 = *(_DWORD *)(((int (__thiscall *)(CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *))this->m_pAllocator[2].m_pCommitLimit)(a1: this)
                       + 200);
      else
        v9 = 0;
      goto LABEL_9;
    }
    Perspective3D = GFxCharacter::GetPerspective3D(this: v8, checkAncestors: true);
  }
  v9 = Perspective3D;
LABEL_9:
  View3D = *((_DWORD *)this + 25);
  if ( View3D == 0 )
  {
    v11 = *((_DWORD **)this + 8);
    if ( v11 != nullptr )
    {
      View3D = GFxCharacter::GetView3D(this: v11, checkAncestors: true);
    }
    else if ( ((int (__thiscall *)(CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *))this->m_pAllocator[2].m_pCommitLimit)(a1: this) != 0 )
    {
      View3D = *(_DWORD *)(((int (__thiscall *)(CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *))this->m_pAllocator[2].m_pCommitLimit)(a1: this)
                         + 204);
    }
    else
    {
      View3D = 0;
    }
  }
  if ( v9 != 0 )
    *(_DWORD *)(((int (__thiscall *)(CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *))this->m_pAllocator[2].m_pCommitLimit)(a1: this)
              + 224) = v9;
  if ( View3D != 0 )
    *(_DWORD *)(((int (__thiscall *)(CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *))this->m_pAllocator[2].m_pCommitLimit)(a1: this)
              + 228) = View3D;
  GMatrix3D::SetIdentity(this: (GMatrix3D *)&v18.nReferenceCount);
  GFxCharacter::GetWorldMatrix3D(
    (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)this,
    pmat: (CMatQueuedMesh::MST_MeshInfo_t *)&v18.nReferenceCount);
  *(_DWORD *)(((int (__thiscall *)(CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *))this->m_pAllocator[2].m_pCommitLimit)(a1: this)
            + 232) = &v18.nReferenceCount;
  v12 = ((int (__thiscall *)(CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *, CCountedStringPoolBase<unsigned int>::hash_item_t *))this->m_pAllocator[2].m_pCommitLimit)(
          a1: this,
          a2: &v18);
  GScreenToWorld::GetWorldPoint(this: (CUtlBuffer *)(v12 + 208));
LABEL_24:
  if ( *((_WORD *)this + 58) == 0
    && (*(unsigned __int8 (__thiscall **)(_DWORD, CCountedStringPoolBase<unsigned int>::hash_item_t *, int, CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *))(**((_DWORD **)this + 30) + 20))(
         a1: *((_DWORD *)this + 30),
         a2: &v18,
         a3: 1,
         a4: this) != 0 )
  {
    v13 = *((_DWORD *)this + 8);
    if ( v13 != 0 )
    {
      while ( (*(int (__thiscall **)(int))(*(_DWORD *)(v13 + 120) + 8))(a1: v13 + 120) == 2 )
      {
        if ( *(_BYTE *)(params + 12) != 0
          || GFxSprite::ActsAsButton(this: (GFxSprite *)v13)
          || (v14 = *(GFxSprite **)(v13 + 472)) != nullptr && GFxSprite::ActsAsButton(this: v14) )
        {
          v15 = *(_DWORD *)(params + 4);
          if ( v15 == 0 || v15 != v13 )
            return (CFunctor *)v13;
        }
        v13 = *(_DWORD *)(v13 + 32);
        if ( v13 == 0 )
          return nullptr;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10084530
// Name: public: void GFxASCharacter::ModifyOptimizedPlayList(class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *__thiscall GFxASCharacter::ModifyOptimizedPlayList(
        CMatQueuedMesh **this,
        const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *result)
{
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v3; // eax
  int v4; // [esp+4h] [ebp-4h]

  LOBYTE(v4) = ((unsigned int)*(this + 40) & 0x80000) != 0;
  v3 = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)((int (__stdcall *)(int))(*this)[3].m_nIndices)(a1: v4);
  if ( v3 == (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)-1 )
    return (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)GFxASCharacter::RemoveFromOptimizedPlaylist(this, result);
  if ( v3 == (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)1 )
    return (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)GFxASCharacter::AddToOptimizedPlayList((int)this, result);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10084590
// Name: public: class GFxLog __near * GFxMovieRoot::GetCachedLog(void)const
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxMovieRoot::GetCachedLog(ScaleformRenderer *this@<ecx>, VertexShaderHandle_t__ *a2@<esi>)
{
  IShaderDevice *v3; // eax
  IShaderAPI *v4; // esi
  IShaderAPI *v5; // ecx

  if ( (*((_DWORD *)this + 2333) & 2) == 0 )
  {
    v3 = (IShaderDevice *)((int (__thiscall *)(GList<GRendererEventHandler> *, int))this->Handlers.Root.pPrev->pRenderer)(
                            a1: &this->Handlers,
                            a2: 4);
    v4 = (IShaderAPI *)v3;
    if ( v3 != nullptr )
      GRefCountImpl::AddRef(this: v3, a2);
    v5 = (IShaderAPI *)LODWORD(this->m_projection.M_[0][1]);
    if ( v5 != nullptr )
      GRefCountImpl::Release(this: v5);
    LODWORD(this->m_projection.M_[0][1]) = v4;
    if ( v4 != nullptr )
      GRefCountImpl::Release(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100845F0
// Name: public: GFxFilterDesc::GFxFilterDesc(void)
// Source: json
//------------------------------------------------------------------------------
IStorage *__thiscall GFxFilterDesc::GFxFilterDesc(IStorage *this)
{
  *((float *)this + 3) = 5.0;
  *((_DWORD *)this + 2) = 0;
  *((float *)this + 4) = 5.0;
  *((_DWORD *)this + 5) = 1;
  *((float *)this + 6) = 0.0;
  *((float *)this + 7) = 0.0;
  *((float *)this + 10) = 1.0;
  GRenderer::Cxform::Cxform();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10084660
// Name: public: void GFxCharacter::SetPerspectiveFOV(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCharacter::SetPerspectiveFOV(GFxCharacter *this, float fov)
{
  const CUtlMemory<unsigned char,int> *v3; // edi
  GMatrix3D v4; // [esp+10h] [ebp-84h] BYREF
  GMatrix3D v5; // [esp+50h] [ebp-44h] BYREF

  v3 = (const CUtlMemory<unsigned char,int> *)(*(int (__thiscall **)(GFxCharacter *))(*(_DWORD *)this + 84))(a1: this);
  if ( *((float *)this + 26) != fov && v3 != nullptr )
  {
    *((float *)this + 26) = fov;
    GMatrix3D::SetIdentity(this: &v4);
    GMatrix3D::SetIdentity(this: &v5);
    GRenderer::MakeViewAndPersp3D(result: v3 + 12);
    GFxCharacter::SetPerspective3D(this, a2: &v5);
    GFxCharacter::SetView3D(this, a2: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084710
// Name: public: virtual class GFxLog __near * GFxCharacter::GetLog(void)const
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxCharacter::GetLog(GFxCharacter *this@<ecx>, VertexShaderHandle_t__ *a2@<esi>)
{
  ScaleformRenderer *v2; // eax

  v2 = (ScaleformRenderer *)(*(int (__thiscall **)(GFxCharacter *))(*(_DWORD *)this + 84))(a1: this);
  GFxMovieRoot::GetCachedLog(this: v2, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10084720
// Name: public: void GFxASCharacter::RemoveFromPlaylist(class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *__thiscall GFxASCharacter::RemoveFromPlaylist(
        int this,
        const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *result)
{
  int v3; // eax
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v4; // eax

  if ( (*(_DWORD *)(this + 160) & 0x200000) != 0 )
  {
    GFxMovieRoot::RemoveFromPreDisplayList();
    *(_DWORD *)(this + 160) &= ~0x200000u;
  }
  GFxASCharacter::RemoveFromOptimizedPlaylist((CMatQueuedMesh **)this, result);
  v3 = *(_DWORD *)(this + 132);
  if ( v3 != 0 )
    *(_DWORD *)(v3 + 136) = *(_DWORD *)(this + 136);
  v4 = *(const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> **)(this + 136);
  if ( v4 != nullptr )
  {
    HIDWORD(v4[5].m_pfnProxied) = *(_DWORD *)(this + 132);
  }
  else if ( *((_DWORD *)&result[426].m_pObject + 1) == this )
  {
    v4 = *(const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> **)(this + 132);
    *((_DWORD *)&result[426].m_pObject + 1) = v4;
  }
  *(_DWORD *)(this + 136) = 0;
  *(_DWORD *)(this + 132) = 0;
  *((_DWORD *)&result[388].m_pObject + 1) |= 0x400u;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100847C0
// Name: public: void GFxASCharacter::SetGeomData(struct GFxASCharacter::GeomDataType const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall GFxASCharacter::SetGeomData(
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *this,
        CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *gd)
{
  CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v3; // ecx
  CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result; // eax
  CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v5; // eax
  int v6; // [esp+4h] [ebp-4h] BYREF

  v3 = *((CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)this
       + 38);
  if ( v3 != nullptr )
    return GFxASCharacter::GeomDataType::GeomDataType(this: v3, result: gd);
  v6 = 323;
  v5 = (CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 88, a4: &v6);
  if ( v5 != nullptr )
  {
    result = GFxASCharacter::GeomDataType::GeomDataType(this: v5, result: gd);
    *((_DWORD *)this + 38) = result;
  }
  else
  {
    *((_DWORD *)this + 38) = 0;
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10084830
// Name: public: void GFxASCharacter::EnsureGeomDataCreated(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::EnsureGeomDataCreated(
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *this)
{
  CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v2; // eax
  const CMaterialDict::MissingMaterial_t *v3; // [esp+0h] [ebp-60h]
  _DWORD v4[2]; // [esp+4h] [ebp-5Ch] BYREF
  double v5; // [esp+Ch] [ebp-54h]
  double v6; // [esp+14h] [ebp-4Ch]
  double v7; // [esp+1Ch] [ebp-44h]
  double v8; // [esp+3Ch] [ebp-24h]
  double v9; // [esp+44h] [ebp-1Ch]
  double v10; // [esp+4Ch] [ebp-14h]
  double v11; // [esp+54h] [ebp-Ch]

  if ( *((_DWORD *)this + 38) == 0 )
  {
    GMatrix2D::SetIdentity(result: v3);
    v7 = 0.0;
    v6 = 100.0;
    v5 = 100.0;
    v4[1] = 0;
    v9 = 100.0;
    v4[0] = 0;
    v11 = 0.0;
    v10 = 0.0;
    v8 = 0.0;
    GFxASCharacter::GetGeomData(this, a2: 0.0, fX: v4);
    GFxASCharacter::SetGeomData(this, gd: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100848B0
// Name: public: virtual void GFxASCharacter::SetAcceptAnimMoves(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::SetAcceptAnimMoves(
        CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *accept)
{
  int v3; // edi

  if ( (_BYTE)accept == 0 )
    GFxASCharacter::EnsureGeomDataCreated((CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this);
  v3 = this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable[5].Release(this);
  if ( (_BYTE)accept != 0 )
    *((_DWORD *)this + 40) |= 0x1000u;
  else
    *((_DWORD *)this + 40) &= ~0x1000u;
  if ( (*(_DWORD *)(v3 + 9332) & 0x200000) != 0 )
    *((_DWORD *)this + 40) |= 0x100000u;
  else
    *((_DWORD *)this + 40) &= ~0x100000u;
  if ( (*(_DWORD *)(v3 + 9332) & 0x200000) != 0 && (_BYTE)accept != 0 )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 38));
    *((_DWORD *)this + 38) = 0;
  }
  *(_DWORD *)(v3 + 9332) |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x100849D0
// Name: public: GFxFilterDesc::GFxFilterDesc(struct GFxFilterDesc const __near &)
// Source: json
//------------------------------------------------------------------------------
IStorage *__thiscall GFxFilterDesc::GFxFilterDesc(IStorage *this, IStorage *result)
{
  IStorage *v4; // esi
  IStorage_vtbl *v5; // [esp+10h] [ebp+8h]

  LOBYTE(this->__vftable) = result->__vftable;
  HIWORD(this->__vftable) = HIWORD(result->__vftable);
  *((_WORD *)this + 2) = result[1].__vftable;
  *(this + 2) = result[2];
  *(this + 3) = result[3];
  v4 = result + 11;
  *(this + 4) = result[4];
  *(this + 5) = result[5];
  v5 = result[7].__vftable;
  *(this + 6) = result[6];
  *(this + 7) = (IStorage)v5;
  *(this + 8) = result[8];
  *(this + 9) = result[9];
  *(this + 10) = result[10];
  qmemcpy(this + 11, v4, 0x20u);
  qmemcpy(this + 19, &result[19], 0x50u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10084C30
// Name: public: void GFxMovieRoot::GetDragState(class GFxMovieRoot::DragState __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::GetDragState(GFxMovieRoot *this, struct GFxMovieRoot::DragState *a2)
{
  float v3; // [esp+8h] [ebp+8h]
  float v4; // [esp+8h] [ebp+8h]
  float v5; // [esp+8h] [ebp+8h]

  *(_DWORD *)a2 = *((_DWORD *)this + 2297);
  *((_BYTE *)a2 + 4) = *((_BYTE *)this + 9192);
  *((_BYTE *)a2 + 5) = *((_BYTE *)this + 9193);
  v3 = *((float *)this + 2300);
  *((float *)a2 + 2) = *((float *)this + 2299);
  *((float *)a2 + 3) = v3;
  v4 = *((float *)this + 2302);
  *((float *)a2 + 4) = *((float *)this + 2301);
  *((float *)a2 + 5) = v4;
  v5 = *((float *)this + 2304);
  *((float *)a2 + 6) = *((float *)this + 2303);
  *((float *)a2 + 7) = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10084CA0
// Name: public: struct GFxFilterDesc __near & GFxFilterDesc::operator=(struct GFxFilterDesc const __near &)
// Source: json
//------------------------------------------------------------------------------
_WORD *__thiscall GFxFilterDesc::operator=(_WORD *this, int a2)
{
  _WORD *result; // eax
  int v4; // edx
  float *v5; // ecx
  int v6; // ebx
  int v7; // esi
  double v8; // st7
  float v9; // [esp+14h] [ebp+8h]

  result = this;
  *(_BYTE *)this = *(_BYTE *)a2;
  *(this + 1) = *(_WORD *)(a2 + 2);
  *(this + 2) = *(_WORD *)(a2 + 4);
  *((_DWORD *)this + 2) = *(_DWORD *)(a2 + 8);
  *((float *)this + 3) = *(float *)(a2 + 12);
  *((float *)this + 4) = *(float *)(a2 + 16);
  *((_DWORD *)this + 5) = *(_DWORD *)(a2 + 20);
  v9 = *(float *)(a2 + 28);
  *((float *)this + 6) = *(float *)(a2 + 24);
  *((float *)this + 7) = v9;
  *((_DWORD *)this + 8) = *(_DWORD *)(a2 + 32);
  *((_DWORD *)this + 9) = *(_DWORD *)(a2 + 36);
  *((float *)this + 10) = *(float *)(a2 + 40);
  qmemcpy(this + 22, (const void *)(a2 + 44), 0x20u);
  v4 = a2 + 84;
  v5 = (float *)(this + 38);
  v6 = a2 - (_DWORD)result;
  v7 = 2;
  do
  {
    v8 = *(float *)((char *)v5 + v6);
    v5 += 10;
    *(v5 - 10) = v8;
    v4 += 40;
    --v7;
    *(v5 - 9) = *(float *)(v4 - 44);
    *(v5 - 8) = *(float *)(v4 - 40);
    *(v5 - 7) = *(float *)(v4 - 36);
    *(v5 - 6) = *(float *)(v4 - 32);
    *(v5 - 5) = *(float *)(v4 - 28);
    *(v5 - 4) = *(float *)(v4 - 24);
    *(v5 - 3) = *(float *)(v4 - 20);
    *(v5 - 2) = *(float *)(v4 - 16);
    *(v5 - 1) = *(float *)(v4 - 12);
  }
  while ( v7 != 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10084D70
// Name: public: GFxCharacter::GFxCharacter(class GFxASCharacter __near *,class GFxResourceId)
// Source: json
//------------------------------------------------------------------------------
GFxCharacter *__thiscall GFxCharacter::GFxCharacter(
        GFxCharacter *this,
        struct GFxASCharacter *a2,
        struct GFxResourceId a3)
{
  const CMaterialDict::MissingMaterial_t *v5; // [esp+0h] [ebp-8h]

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = &GFxLogBase<GFxLoadProcess>::`vftable';
  *(_DWORD *)this = &GFxCharacter::`vftable'{for `GRefCountBaseWeakSupport<GFxCharacter,322>'};
  *((_DWORD *)this + 3) = &GFxCharacter::`vftable'{for `GFxLogBase<GFxCharacter>'};
  *((struct GFxResourceId *)this + 4) = a3;
  *((float *)this + 7) = 0.0;
  *((_DWORD *)this + 8) = a2;
  *((_DWORD *)this + 5) = -1;
  *((_DWORD *)this + 6) = 0;
  GRenderer::Cxform::Cxform();
  GMatrix2D::SetIdentity(result: v5);
  *((_DWORD *)this + 23) = 0;
  *((float *)this + 26) = 0.0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 29) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10084DF0
// Name: public: virtual void GFxASCharacter::OnEventUnload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::OnEventUnload(GFxASCharacter *this)
{
  int v2; // edx
  int v3; // edi
  int v4; // esi

  v2 = *(_DWORD *)this;
  *((_WORD *)this + 59) |= 0x100u;
  v3 = (*(int (**)(void))(v2 + 84))();
  GFxASCharacter::RemoveFromPlaylist(
    (int)this,
    result: (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)v3);
  if ( *(GFxASCharacter **)(v3 + 9188) == this )
    *(_DWORD *)(v3 + 9188) = 0;
  GFxCharacter::OnEventUnload(this);
  GFxMovieRoot::ResetFocusForChar();
  v4 = *((_DWORD *)this + 37);
  if ( v4 != 0 )
    *(_DWORD *)(v4 + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10084E50
// Name: public: virtual bool GFxASCharacter::OnUnloading(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxASCharacter::OnUnloading(GFxASCharacter *this)
{
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v2; // eax

  v2 = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)(*(int (__thiscall **)(GFxASCharacter *))(*(_DWORD *)this + 84))(a1: this);
  GFxASCharacter::RemoveFromPlaylist((int)this, result: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10084E70
// Name: public: void GFxASCharacter::DoMouseDrag(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxASCharacter::DoMouseDrag(
        GFxASCharacter *this@<ecx>,
        const CMaterialDict::MissingMaterial_t *a2@<edi>)
{
  int v3; // eax
  int (__thiscall *v4)(GFxASCharacter *); // edx
  int v5; // ebx
  int v6; // edi
  int v7; // ecx
  CMaterialDict *WorldMatrix; // eax
  _DWORD *v9; // ecx
  int Perspective3D; // eax
  _DWORD *v11; // ecx
  int View3D; // edi
  _DWORD *v13; // ecx
  CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *v14; // edi
  int v15; // eax
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19; // st7
  void (__thiscall *v20)(GFxASCharacter *, _DWORD, GASValue *, _DWORD); // edx
  void (__thiscall *v21)(GFxASCharacter *, int, GASValue *, _DWORD); // edx
  int v23; // [esp-4h] [ebp-B4h]
  int p[2]; // [esp+8h] [ebp-A8h] BYREF
  GFxASCharacter *v25; // [esp+10h] [ebp-A0h] BYREF
  __int16 v26; // [esp+14h] [ebp-9Ch]
  float v27; // [esp+18h] [ebp-98h]
  float v28; // [esp+1Ch] [ebp-94h]
  float v29; // [esp+20h] [ebp-90h]
  float v30; // [esp+24h] [ebp-8Ch]
  float v31; // [esp+28h] [ebp-88h]
  float v32; // [esp+2Ch] [ebp-84h]
  float v33; // [esp+30h] [ebp-80h]
  CCountedStringPoolBase<unsigned int>::hash_item_t result; // [esp+34h] [ebp-7Ch] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v35; // [esp+7Ch] [ebp-34h] BYREF
  float v36; // [esp+90h] [ebp-20h]
  char v37; // [esp+94h] [ebp-1Ch] BYREF
  GASValue v38; // [esp+9Ch] [ebp-14h] BYREF
  double v39; // [esp+A0h] [ebp-10h]

  v28 = 0.0;
  v27 = 0.0;
  v3 = *(_DWORD *)this;
  v30 = 0.0;
  v4 = *(int (__thiscall **)(GFxASCharacter *))(v3 + 84);
  v29 = 0.0;
  v5 = 0;
  v32 = 0.0;
  v31 = 0.0;
  v25 = nullptr;
  v26 = 0;
  v6 = v4(a1: this);
  GFxMovieRoot::GetDragState(this: (GFxMovieRoot *)v6, a2: (struct GFxMovieRoot::DragState *)&v25);
  if ( this != v25 )
    return;
  p[0] = *(int *)(v6 + 2376);
  p[1] = *(int *)(v6 + 2380);
  GMatrix2D::SetIdentity(result: a2);
  v7 = *((_DWORD *)this + 8);
  if ( v7 != 0 )
  {
    WorldMatrix = GFxCharacter::GetWorldMatrix(this: v7, result: (CMaterialDict *)&v37);
    v35.m_Memory.m_pMemory = (CCountedStringPoolBase<unsigned int>::hash_item_t *)WorldMatrix->m_MaterialDict.m_LessFunc;
    v35.m_Memory.m_nAllocationCount = (int)WorldMatrix->m_MaterialDict.m_Elements.m_pMemory;
    v35.m_Memory.m_nGrowSize = WorldMatrix->m_MaterialDict.m_Elements.m_nAllocationCount;
    v35.m_Size = WorldMatrix->m_MaterialDict.m_Elements.m_nGrowSize;
    v35.m_pElements = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)&WorldMatrix->m_MaterialDict.m_Root;
    v36 = *(float *)&WorldMatrix->m_MaterialDict.m_FirstFree;
  }
  GMatrix2D::TransformByInverse(this: &v35, &result, (int)p, a4: v23);
  if ( *((_DWORD *)this + 23) != 0
    || (v9 = *((_DWORD **)this + 8)) != nullptr
    && GFxCharacter::Is3D(
         this: v9,
         result: (CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *)1) != 0 )
  {
    Perspective3D = *((_DWORD *)this + 24);
    if ( Perspective3D == 0 )
    {
      v11 = *((_DWORD **)this + 8);
      if ( v11 == nullptr )
      {
        if ( (*(int (__thiscall **)(GFxASCharacter *))(*(_DWORD *)this + 84))(a1: this) != 0 )
          v5 = *(_DWORD *)((*(int (__thiscall **)(GFxASCharacter *))(*(_DWORD *)this + 84))(a1: this) + 200);
        goto LABEL_11;
      }
      Perspective3D = GFxCharacter::GetPerspective3D(this: v11, checkAncestors: true);
    }
    v5 = Perspective3D;
LABEL_11:
    View3D = *((_DWORD *)this + 25);
    if ( View3D == 0 )
    {
      v13 = *((_DWORD **)this + 8);
      if ( v13 != nullptr )
      {
        View3D = GFxCharacter::GetView3D(this: v13, checkAncestors: true);
      }
      else if ( (*(int (__thiscall **)(GFxASCharacter *))(*(_DWORD *)this + 84))(a1: this) != 0 )
      {
        View3D = *(_DWORD *)((*(int (__thiscall **)(GFxASCharacter *))(*(_DWORD *)this + 84))(a1: this) + 204);
      }
      else
      {
        View3D = 0;
      }
    }
    if ( v5 != 0 )
      *(_DWORD *)((*(int (__thiscall **)(GFxASCharacter *))(*(_DWORD *)this + 84))(a1: this) + 224) = v5;
    if ( View3D != 0 )
      *(_DWORD *)((*(int (__thiscall **)(GFxASCharacter *))(*(_DWORD *)this + 84))(a1: this) + 228) = View3D;
    v14 = *((CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> **)this
          + 8);
    GMatrix3D::SetIdentity(this: (GMatrix3D *)&result.nReferenceCount);
    GFxCharacter::GetWorldMatrix3D(this: v14, pmat: (CMatQueuedMesh::MST_MeshInfo_t *)&result.nReferenceCount);
    *(_DWORD *)((*(int (__thiscall **)(GFxASCharacter *))(*(_DWORD *)this + 84))(a1: this) + 232) = &result.nReferenceCount;
    v15 = (*(int (__thiscall **)(GFxASCharacter *, CCountedStringPoolBase<unsigned int>::hash_item_t *))(*(_DWORD *)this + 84))(
            a1: this,
            a2: &result);
    GScreenToWorld::GetWorldPoint(this: (CUtlBuffer *)(v15 + 208));
  }
  *(float *)&result.pString = v31 + *(float *)&result.pString;
  *(float *)&result.nNextElement = v32 + *(float *)&result.nNextElement;
  if ( HIBYTE(v26) != 0 )
  {
    v16 = *(float *)&result.pString;
    if ( v29 <= (double)*(float *)&result.pString )
      v16 = v29;
    v33 = v16;
    v17 = v33;
    if ( v27 > (double)v33 )
      v17 = v27;
    *(float *)&result.pString = v17;
    v18 = *(float *)&result.nNextElement;
    if ( v30 <= (double)*(float *)&result.nNextElement )
      v18 = v30;
    v33 = v18;
    v19 = v33;
    if ( v28 > (double)v33 )
      v19 = v28;
    *(float *)&result.nNextElement = v19;
  }
  (*(void (__thiscall **)(GFxASCharacter *, _DWORD))(*(_DWORD *)this + 32))(a1: this, a2: 0);
  v20 = *(void (__thiscall **)(GFxASCharacter *, _DWORD, GASValue *, _DWORD))(*(_DWORD *)this + 284);
  LOBYTE(v38) = 3;
  v39 = *(float *)&result.pString / 20.0;
  v20(a1: this, a2: 0, a3: &v38, a4: 0);
  GASValue::~GASValue(this: &v38);
  v21 = *(void (__thiscall **)(GFxASCharacter *, int, GASValue *, _DWORD))(*(_DWORD *)this + 284);
  LOBYTE(v38) = 3;
  v39 = *(float *)&result.nNextElement / 20.0;
  v21(a1: this, a2: 1, a3: &v38, a4: 0);
  GASValue::~GASValue(this: &v38);
}

//------------------------------------------------------------------------------
// Address: 0x10085140
// Name: public: void GFxASCharacter::MoveNameHandle(class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxASCharacter::MoveNameHandle(
        CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *this@<ecx>,
        CMatQueuedMesh *poldChar,
        __int128 a3)
{
  CMatQueuedMesh *v4; // ecx
  IMesh *m_pVertexOverride; // eax
  _DWORD *v6; // esi
  int v7; // ecx
  bool v8; // zf
  int v9; // ecx
  int v10; // ecx
  _DWORD *v11; // esi
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // eax

  v4 = poldChar;
  m_pVertexOverride = poldChar[1].m_pVertexOverride;
  if ( m_pVertexOverride != nullptr )
    ++m_pVertexOverride->IVertexBuffer::__vftable;
  v6 = *((_DWORD **)this + 37);
  if ( v6 != nullptr && (int)--*v6 <= 0 )
  {
    v7 = v6[4];
    v8 = (*(_DWORD *)(v7 + 8))-- == 1;
    if ( v8 )
      GASStringNode::ReleaseNode();
    v9 = v6[3];
    v8 = (*(_DWORD *)(v9 + 8))-- == 1;
    if ( v8 )
      GASStringNode::ReleaseNode();
    v10 = v6[2];
    v8 = (*(_DWORD *)(v10 + 8))-- == 1;
    if ( v8 )
      GASStringNode::ReleaseNode();
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
    v4 = poldChar;
  }
  *((_DWORD *)this + 37) = v4[1].m_pVertexOverride;
  v11 = &v4[1].m_pVertexOverride->__vftable;
  if ( v11 != nullptr && (int)--*v11 <= 0 )
  {
    v12 = v11[4];
    v8 = (*(_DWORD *)(v12 + 8))-- == 1;
    if ( v8 )
      GASStringNode::ReleaseNode();
    v13 = v11[3];
    v8 = (*(_DWORD *)(v13 + 8))-- == 1;
    if ( v8 )
      GASStringNode::ReleaseNode();
    v14 = v11[2];
    v8 = (*(_DWORD *)(v14 + 8))-- == 1;
    if ( v8 )
      GASStringNode::ReleaseNode();
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
    v4 = poldChar;
  }
  v4[1].m_pVertexOverride = nullptr;
  v15 = *((_DWORD *)this + 37);
  if ( v15 != 0 )
    *(_DWORD *)(v15 + 4) = this;
}

//------------------------------------------------------------------------------
// Address: 0x10085220
// Name: public: GFxGenericCharacter::GFxGenericCharacter(class GFxCharacterDef __near *,class GFxASCharacter __near *,class GFxResourceId)
// Source: json
//------------------------------------------------------------------------------
CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *__userpurge GFxGenericCharacter::GFxGenericCharacter@<eax>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this@<ecx>,
        CMatRenderContextBase *pdef,
        __int128 pparent,
        IMaterial *const *id,
        void *const *a5)
{
  GFxCharacter::GFxCharacter(
    (GFxCharacter *)this,
    a2: (struct GFxASCharacter *)pparent,
    a3: *(struct GFxResourceId *)((char *)&pparent + 4));
  *((_DWORD *)this + 30) = pdef;
  this->m_pAllocator = (CMemoryStack *)&GFxGenericCharacter::`vftable'{for `GRefCountBaseWeakSupport<GFxCharacter,322>'};
  *((_DWORD *)this + 3) = &GFxCharacter::`vftable'{for `GFxLogBase<GFxCharacter>'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10085260
// Name: public: virtual void GFxGenericCharacter::Display(class GFxDisplayContext __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor *__userpurge GFxGenericCharacter::Display@<eax>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this@<ecx>,
        CMatRenderContextBase *context,
        __int128 context_4,
        const Vector *context_20)
{
  return (*(CFunctor *(__thiscall **)(_DWORD, CMatRenderContextBase *, CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *))(**((_DWORD **)this + 30) + 16))(
           a1: *((_DWORD *)this + 30),
           a2: context,
           a3: this);
}

//------------------------------------------------------------------------------
// Address: 0x100857E0
// Name: public: void GMsgFormat::FormatD1<int>(int const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GMsgFormat::FormatD1<int>(int this, CUtlSymbolTable::StringPool_t *result)
{
  bool Formatter; // al
  GMemoryHeap **v4; // esi
  BGR888_t *v5; // eax
  unsigned int v6; // edx
  GMemoryHeap *v7; // ecx
  struct GFormatter *v8; // eax

  Formatter = GMsgFormat::NextFormatter((GMsgFormat *)this);
  if ( Formatter )
  {
    v4 = (GMemoryHeap **)(this + 244);
    do
    {
      if ( *(_DWORD *)(this + 764) < 0x50u )
      {
        v7 = *v4;
        if ( *v4 == nullptr )
          v7 = GMemory::pGlobalHeap;
        v5 = (BGR888_t *)v7->Alloc(this: v7, a2: 80u, a3: 4u, a4: nullptr);
      }
      else
      {
        v5 = *(BGR888_t **)(this + 760);
        *(_DWORD *)(this + 760) = ((unsigned int)&v5[26].g & 0xFFFFFFFC) + 4;
        v6 = ((unsigned int)&v5[26].g & 0xFFFFFFFC) - (_DWORD)v4;
        if ( v6 >= 0x200 )
          *(_DWORD *)(this + 764) = 0;
        else
          *(_DWORD *)(this + 764) = 512 - v6;
      }
      if ( v5 != nullptr )
        GLongFormatter::GLongFormatter(this: v5, f: this);
      else
        v8 = nullptr;
      GMsgFormat::Bind((GMsgFormat *)this, a2: v8, a3: true);
      Formatter = GMsgFormat::NextFormatter((GMsgFormat *)this);
    }
    while ( Formatter );
  }
  ++*(_BYTE *)(this + 5);
  return Formatter;
}

//------------------------------------------------------------------------------
// Address: 0x100858A0
// Name: public: virtual void GFxCharacter::SetFilters(class GArray<struct GFxFilterDesc,2,struct GArrayDefaultPolicy>)
// Source: json
//------------------------------------------------------------------------------
int __stdcall GFxCharacter::SetFilters(_LocaleUpdate *const f, int a2, int a3)
{
  return ((int (__thiscall *)(GMemoryHeap *, _LocaleUpdate *const))GMemory::pGlobalHeap->Free)(
           a1: GMemory::pGlobalHeap,
           a2: f);
}

//------------------------------------------------------------------------------
// Address: 0x10085C90
// Name: public: GASFnCall::GASFnCall(class GASValue __near *,class GASValue const __near &,class GASEnvironment __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
PPM_IDLE_STATE_ACCOUNTING *__thiscall GASFnCall::GASFnCall(
        _DWORD *this,
        PPM_IDLE_STATE_ACCOUNTING *result,
        tagWNDCLASSW *ThisIn,
        _SERVICE_STATUS *a4,
        int NargsIn,
        int FirstIn)
{
  const struct GASFunctionRefBase *v7; // eax
  _DWORD v9[2]; // [esp+Ch] [ebp-Ch] BYREF
  char v10; // [esp+14h] [ebp-4h]

  *this = &GASFnCall::`vftable';
  *(this + 1) = result;
  *(this + 2) = GASValue::ToObjectInterface(result: a4);
  *((_BYTE *)this + 20) = 0;
  *(this + 3) = 0;
  *(this + 4) = 0;
  *(this + 7) = NargsIn;
  *(this + 6) = a4;
  *(this + 8) = FirstIn;
  if ( LOBYTE(ThisIn->style) == 8 || LOBYTE(ThisIn->style) == 11 )
  {
    v7 = (const struct GASFunctionRefBase *)GASValue::ToFunction(a1: v9, a2: a4);
    GASFunctionRefBase::Assign(this: (GASFunctionRefBase *)(this + 3), a2: v7);
    if ( (v10 & 2) == 0 && v9[0] != 0 )
      GRefCountBaseGC<323>::Release();
    v9[0] = 0;
    if ( (v10 & 1) == 0 && v9[1] != 0 )
      GRefCountBaseGC<323>::Release();
  }
  return (PPM_IDLE_STATE_ACCOUNTING *)this;
}

//------------------------------------------------------------------------------
// Address: 0x10085D30
// Name: public: void GFxASCharacter::GetAbsolutePath(class GString __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::GetAbsolutePath(
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *this,
        CUtlMemory<CImagePacker,int> *a2)
{
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v3; // ecx
  int v4; // eax
  CMatRenderContextBase *v5; // [esp+0h] [ebp-31Ch]
  unsigned __int16 v6; // [esp+0h] [ebp-31Ch]
  __int128 v7; // [esp+4h] [ebp-318h] BYREF
  CUtlSymbolTable::StringPool_t result; // [esp+14h] [ebp-308h] BYREF

  v3 = *((CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> **)this
       + 8);
  if ( v3 != nullptr )
  {
    GFxASCharacter::GetAbsolutePath(this: v3, a2);
    GString::AppendString(this: a2, putf8str: (int)&stru_1029E6EC.m_Elements.m_nGrowSize);
    v4 = *((_DWORD *)this + 37);
    if ( v4 == 0 )
    {
      GFxASCharacter::CreateCharacterHandle(this, name: v5, a3: v7);
      if ( v4 == 0 )
        v4 = *(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 108))(a1: this)
                       + 120);
    }
    GString::AppendString(this: a2, putf8str: **(_DWORD **)(v4 + 8));
  }
  else if ( (*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(*((_DWORD *)this + 30) + 8))(a1: this + 5) == 2 )
  {
    result.m_TotalLen = *((_DWORD *)this + 111);
    DWORD1(v7) = 0;
    DWORD2(v7) = a2;
    GMsgFormat::GMsgFormat(
      this: (GMsgFormat *)&result.m_SpaceUsed,
      a2: (const struct GMsgFormat::Sink *)((char *)&v7 + 4));
    GMsgFormat::Parse(result: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&stru_1029E6EC);
    GMsgFormat::FormatD1<int>(this: (int)&result.m_SpaceUsed, &result);
    GMsgFormat::FinishFormatD(
      this: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&result.m_SpaceUsed,
      a2: (unsigned __int16)v5);
    GMsgFormat::~GMsgFormat(
      this: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&result.m_SpaceUsed,
      data_size: v6);
  }
  else
  {
    GString::Clear(this: (GString *)a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085E50
// Name: public: virtual bool GFxASCharacter::GetStandardMember(enum GFxASCharacter::StandardMember,class GASValue __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
char __userpurge GFxASCharacter::GetStandardMember@<al>(
        int a1@<ecx>,
        double a2@<st0>,
        int a3,
        GASValue *a4,
        bool opcodeFlag)
{
  GASEnvironment *v6; // eax
  int *v8; // eax
  double v9; // st7
  double v10; // st7
  int v11; // eax
  int v12; // eax
  int v13; // eax
  double v14; // st7
  int v15; // eax
  char v16; // bl
  int v17; // eax
  char *v18; // eax
  char *v19; // esi
  bool v20; // zf
  int v21; // eax
  int v22; // ebx
  int v23; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v24; // ebx
  int v25; // eax
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *v26; // ebx
  int v27; // eax
  struct GASStringNode *StringNode; // esi
  tagBITMAPCOREHEADER *v29; // esi
  GASValue *v30; // ecx
  GASEnvironment *v31; // eax
  struct GFxMovieRoot *MovieRoot; // eax
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *TopMostEntity; // ebx
  int v34; // eax
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *m_pfnProxied; // ebx
  int v36; // eax
  struct GASStringNode *v37; // esi
  int (__thiscall *v38)(int); // eax
  int v39; // eax
  const char *v40; // eax
  unsigned int v41; // ebx
  char *v42; // eax
  char *v43; // edx
  char v44; // cl
  int v45; // eax
  struct GASStringNode *v46; // esi
  int v47; // eax
  char *v48; // eax
  int v49; // esi
  int v50; // eax
  int v51; // eax
  int v52; // esi
  int v53; // esi
  unsigned int v54; // ebx
  int v55; // ecx
  int (__thiscall *v56)(int, int, int *); // edx
  int v57; // esi
  char *v58; // eax
  int v59; // ebx
  struct GASObject *v60; // eax
  struct GASObject *v61; // esi
  int v62; // esi
  const char *X; // [esp+8h] [ebp-2B4h]
  tagLOCALETAB *X_4; // [esp+Ch] [ebp-2B0h]
  CMatRenderContextBase *v65; // [esp+10h] [ebp-2ACh]
  __int128 v66; // [esp+14h] [ebp-2A8h] BYREF
  float v67; // [esp+28h] [ebp-294h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> boundRect; // [esp+2Ch] [ebp-290h] BYREF
  GASValue v69[4]; // [esp+3Ch] [ebp-280h] BYREF
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> v70; // [esp+4Ch] [ebp-270h] BYREF
  CCountedStringPoolBase<unsigned int>::hash_item_t v71; // [esp+64h] [ebp-258h] BYREF
  char *v72; // [esp+70h] [ebp-24Ch]
  CCountedStringPoolBase<unsigned int>::hash_item_t v73; // [esp+84h] [ebp-238h] BYREF
  char *szName; // [esp+90h] [ebp-22Ch]
  GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> v75; // [esp+94h] [ebp-228h] BYREF
  int p[2]; // [esp+9Ch] [ebp-220h] BYREF
  struct GASStringNode *v77; // [esp+A4h] [ebp-218h] BYREF
  int v78; // [esp+A8h] [ebp-214h] BYREF
  tagLOCALETAB urlArray[23]; // [esp+ACh] [ebp-210h] BYREF
  CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> v80; // [esp+180h] [ebp-13Ch] BYREF
  CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> v81; // [esp+1D8h] [ebp-E4h] BYREF
  CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> v82; // [esp+230h] [ebp-8Ch] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v83; // [esp+288h] [ebp-34h] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v84; // [esp+2A0h] [ebp-1Ch] BYREF

  if ( opcodeFlag && (unsigned int)a3 >= 0x16 )
  {
    v6 = (GASEnvironment *)(*(int (__thiscall **)(int, UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short> **, int))(*(_DWORD *)a1 + 108))(
                             a1,
                             a2: &stru_1029E6EC.m_pElements,
                             a3);
    GASEnvironment::LogScriptError(this: v6, a2: X);
    return 0;
  }
  if ( a3 == -1 || a3 > 31 || ((*(int (__thiscall **)(int))(*(_DWORD *)a1 + 280))(a1) & (1 << a3)) == 0 )
    return 0;
  switch ( a3 )
  {
    case 0:
      GFxASCharacter::GeomDataType::GeomDataType(this: (CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)urlArray[4].chAbbrev);
      GFxASCharacter::GetGeomData(
        this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)a1,
        a2,
        fX: urlArray[4].chAbbrev);
      v9 = (double)*v8;
      goto LABEL_10;
    case 1:
      GFxASCharacter::GeomDataType::GeomDataType(this: &v80);
      GFxASCharacter::GetGeomData(
        this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)a1,
        a2,
        fX: &v80);
      v9 = (double)*(int *)(v11 + 4);
LABEL_10:
      v10 = v9 / 20.0;
      goto LABEL_11;
    case 2:
      GFxASCharacter::GeomDataType::GeomDataType(this: (CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)urlArray[15].chAbbrev);
      GFxASCharacter::GetGeomData(
        this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)a1,
        a2,
        fX: urlArray[15].chAbbrev);
      v10 = *(double *)(v12 + 8);
      goto LABEL_11;
    case 3:
      GFxASCharacter::GeomDataType::GeomDataType(this: &v82);
      GFxASCharacter::GetGeomData(
        this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)a1,
        a2,
        fX: &v82);
      v10 = *(double *)(v13 + 16);
      goto LABEL_11;
    case 6:
      v10 = *(float *)(a1 + 60) * 100.0;
      goto LABEL_11;
    case 7:
      v16 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 16))(a1);
      GASValue::DropRefs(this: a4);
      *(_BYTE *)a4 = 2;
      *((_BYTE *)a4 + 4) = v16;
      return 1;
    case 8:
      (*(void (__thiscall **)(int, CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *, int))(*(_DWORD *)a1 + 52))(
        a1,
        a2: &boundRect,
        a3: a1 + 68);
      *(float *)&urlArray[4].szName = *(float *)&boundRect.m_nGrowSize - *(float *)&boundRect.m_pMemory;
      v14 = *(float *)&urlArray[4].szName;
      goto LABEL_17;
    case 9:
      (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a1 + 52))(a1, a2: (char *)&v66 + 8, a3: a1 + 68);
      *(float *)&urlArray[4].szName = v67 - *((float *)&v66 + 3);
      v14 = *(float *)&urlArray[4].szName;
      goto LABEL_17;
    case 10:
      GFxASCharacter::GeomDataType::GeomDataType(this: &v81);
      GFxASCharacter::GetGeomData(
        this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)a1,
        a2,
        fX: &v81);
      v10 = *(double *)(v15 + 24);
      goto LABEL_11;
    case 11:
      GStringBuffer::GStringBuffer(result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GMemory::pGlobalHeap);
      v23 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)a1 + 104))(a1, a2: 0);
      *(_DWORD *)urlArray[3].chAbbrev = v23;
      if ( v23 != 0 )
        ++*(_DWORD *)(v23 + 4);
      v24 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)a1;
      do
      {
        if ( v24 == *(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> **)urlArray[3].chAbbrev )
          break;
        if ( DWORD1(v24[6].m_pfnProxied) == 0 )
        {
          GFxASCharacter::CreateCharacterHandle(this: v24, name: v65, a3: v66);
          if ( v25 == 0 )
            (*(void (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(v24->m_pfnProxied) + 108))(a1: v24);
        }
        GStringBuffer::Insert();
        GStringBuffer::Insert();
        v24 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)DWORD2(v24[1].m_pfnProxied);
      }
      while ( v24 != nullptr );
      v26 = *(CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > **)&v71.nReferenceCount;
      urlArray[4].szName = v72;
      if ( *(_DWORD *)&v71.nReferenceCount == 0 )
        v26 = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&pMem;
      v27 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 108))(a1);
      StringNode = GASStringManager::CreateStringNode(
                     this: *(GASStringManager **)(*(_DWORD *)(v27 + 120) + 636),
                     result: v26,
                     length: (unsigned int)urlArray[4].szName);
      ++*((_DWORD *)StringNode + 2);
      urlArray[2].szName = (char *)StringNode;
      GASValue::SetString(this: a4, a2: (const struct GASString *)&urlArray[2]);
      v20 = (*((_DWORD *)StringNode + 2))-- == 1;
      if ( v20 )
        GASStringNode::ReleaseNode();
      if ( *(_DWORD *)urlArray[3].chAbbrev != 0 )
        GRefCountNTSImpl::Release(this: *(GRefCountNTSImpl **)urlArray[3].chAbbrev);
      GStringBuffer::~GStringBuffer(
        this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)&v71.nReferenceCount,
        a2: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)v65);
      return 1;
    case 13:
      v21 = *(_DWORD *)(a1 + 148);
      if ( v21 == 0 )
      {
        GFxASCharacter::CreateCharacterHandle(
          this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)a1,
          name: v65,
          a3: v66);
        if ( v21 == 0 )
          v21 = *(_DWORD *)((*(int (__thiscall **)(int))(*(_DWORD *)a1 + 108))(a1) + 120);
      }
      GASValue::SetString(this: a4, a2: (const struct GASString *)(v21 + 8));
      return 1;
    case 14:
      GASValue::DropRefs(this: a4);
      *(_BYTE *)a4 = 0;
      v31 = (GASEnvironment *)(*(int (__thiscall **)(int))(*(_DWORD *)a1 + 108))(a1);
      MovieRoot = GASEnvironment::GetMovieRoot(this: v31);
      urlArray[2].szName = *((char **)MovieRoot + 595);
      v75.__vftable = *((GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>_vtbl **)MovieRoot + 594);
      v75.pContainer = (GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc>::SysAllocContainer *)urlArray[2].szName;
      TopMostEntity = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GFxMovieRoot::GetTopMostEntity(result: &v75);
      GStringBuffer::GStringBuffer(result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)GMemory::pGlobalHeap);
      for ( ;
            TopMostEntity != nullptr;
            TopMostEntity = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)DWORD2(TopMostEntity[1].m_pfnProxied) )
      {
        if ( DWORD1(TopMostEntity[6].m_pfnProxied) == 0 )
        {
          GFxASCharacter::CreateCharacterHandle(this: TopMostEntity, name: v65, a3: v66);
          if ( v34 == 0 )
            (*(void (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(TopMostEntity->m_pfnProxied) + 108))(a1: TopMostEntity);
        }
        GStringBuffer::Insert();
        GStringBuffer::Insert();
      }
      urlArray[2].szName = (char *)DWORD1(v70.m_pfnProxied);
      m_pfnProxied = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)v70.m_pfnProxied;
      if ( LODWORD(v70.m_pfnProxied) == 0 )
        m_pfnProxied = (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)&pMem;
      v36 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 108))(a1);
      v37 = GASStringManager::CreateStringNode(
              this: *(GASStringManager **)(*(_DWORD *)(v36 + 120) + 636),
              result: m_pfnProxied,
              length: (unsigned int)urlArray[2].szName);
      ++*((_DWORD *)v37 + 2);
      *(_DWORD *)urlArray[1].chAbbrev = v37;
      GASValue::SetString(this: a4, a2: (const struct GASString *)urlArray[1].chAbbrev);
      v20 = (*((_DWORD *)v37 + 2))-- == 1;
      if ( v20 )
        GASStringNode::ReleaseNode();
      GStringBuffer::~GStringBuffer(
        this: &v70,
        a2: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)v65);
      return 1;
    case 15:
      v38 = *(int (__thiscall **)(int))(*(_DWORD *)a1 + 92);
      memset(urlArray, 0, 12);
      v39 = v38(a1);
      v40 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v39 + 48))(a1: v39);
      *(_DWORD *)urlArray[1].chAbbrev = v40;
      if ( v40 != nullptr )
        v41 = strlen(v40);
      else
        v41 = 0;
      GArrayBase<GArrayData<char,GAllocatorGH<char,2>,GArrayDefaultPolicy>>::Resize(this: urlArray, newSize: v41 + 1);
      if ( v41 != 0 )
      {
        v42 = *(char **)urlArray[1].chAbbrev;
        v43 = &urlArray[0].szName[-*(_DWORD *)urlArray[1].chAbbrev];
        *(_DWORD *)urlArray[3].chAbbrev = v41;
        do
        {
          v44 = *v42;
          if ( *v42 == 92 )
            v44 = 47;
          (v42++)[(_DWORD)v43] = v44;
          --*(_DWORD *)urlArray[3].chAbbrev;
        }
        while ( *(_DWORD *)urlArray[3].chAbbrev != 0 );
      }
      urlArray[0].szName[v41] = 0;
      GString::GString(this: (CUtlMemory<CImagePacker,int> *)urlArray[2].chAbbrev);
      GASGlobalContext::EscapePath(a1: urlArray[0].szName, a2: v41, a3: (struct GString *)urlArray[2].chAbbrev);
      v45 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 108))(a1);
      v46 = GASStringManager::CreateStringNode(
              this: *(GASStringManager **)(*(_DWORD *)(v45 + 120) + 636),
              result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((*(_DWORD *)urlArray[2].chAbbrev
                                                                                        & 0xFFFFFFFC)
                                                                                       + 8),
              length: *(_DWORD *)(*(_DWORD *)urlArray[2].chAbbrev & 0xFFFFFFFC) & 0x7FFFFFFF);
      ++*((_DWORD *)v46 + 2);
      v77 = v46;
      GASValue::SetString(this: a4, a2: (const struct GASString *)&v77);
      v20 = (*((_DWORD *)v46 + 2))-- == 1;
      if ( v20 )
        GASStringNode::ReleaseNode();
      GString::~GString(this: (GString *)urlArray[2].chAbbrev);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: urlArray[0].szName);
      return 1;
    case 16:
      GASValue::DropRefs(this: a4);
      *(_BYTE *)a4 = 2;
      *((_BYTE *)a4 + 4) = 1;
      return 1;
    case 17:
      v49 = *(_DWORD *)(a1 + 160) & 0x180;
      GASValue::DropRefs(this: a4);
      if ( v49 != 0 )
      {
        *(_BYTE *)a4 = 2;
        *((_BYTE *)a4 + 4) = v49 == 384;
      }
      else
      {
        *(_BYTE *)a4 = 1;
      }
      return 1;
    case 18:
      if ( *(_BYTE *)a4 >= 5u )
        GASValue::DropRefs(this: a4);
      *(_BYTE *)a4 = 3;
      *(double *)(a4 + 1) = 0.0;
      return 1;
    case 19:
      v47 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 108))(a1);
      GASStringManager::CreateStringNode(this: *(const char **)(*(_DWORD *)(v47 + 120) + 636));
      v19 = v48;
      urlArray[3].szName = v48;
      X_4 = &urlArray[3];
      goto LABEL_23;
    case 20:
      v50 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 84))(a1);
      urlArray[3].szName = *(char **)(v50 + 2380);
      p[0] = *(int *)(v50 + 2376);
      p[1] = (int)urlArray[3].szName;
      GFxCharacter::GetWorldMatrix(this: a1, result: (CMaterialDict *)&v83);
      GMatrix2D::TransformByInverse(this: &v83, result: &v71, (int)p, a4: (int)v65);
      v14 = *(float *)&v71.pString + 0.5;
      goto LABEL_17;
    case 21:
      v51 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 84))(a1);
      urlArray[3].szName = *(char **)(v51 + 2380);
      *(float *)&v73.nReferenceCount = *(float *)(v51 + 2376);
      szName = urlArray[3].szName;
      GFxCharacter::GetWorldMatrix(this: a1, result: (CMaterialDict *)&v84);
      GMatrix2D::TransformByInverse(this: &v84, result: &v73, p: (int)&v73.nReferenceCount, a4: (int)v65);
      v14 = *(float *)&v73.nNextElement + 0.5;
LABEL_17:
      v10 = floor(X: v14) / 20.0;
      goto LABEL_11;
    case 22:
      v29 = *(tagBITMAPCOREHEADER **)(a1 + 32);
      v30 = a4;
      if ( v29 == nullptr )
        goto LABEL_49;
      GASValue::SetAsCharacter(result: v29);
      break;
    case 23:
      (*(void (__thiscall **)(int))(*(_DWORD *)a1 + 20))(a1);
      v17 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 108))(a1);
      GASStringManager::CreateStringNode(this: *(const char **)(*(_DWORD *)(v17 + 120) + 636));
      v19 = v18;
      urlArray[4].szName = v18;
      X_4 = &urlArray[4];
LABEL_23:
      ++*((_DWORD *)v19 + 2);
      GASValue::SetString(this: a4, a2: (const struct GASString *)X_4);
      v20 = (*((_DWORD *)v19 + 2))-- == 1;
      if ( v20 )
        GASStringNode::ReleaseNode();
      return 1;
    case 25:
      v54 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 108))(a1);
      v55 = *(_DWORD *)(*(_DWORD *)(v54 + 120) + 656);
      v56 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v55 + 40);
      urlArray[3].szName = (char *)v54;
      v78 = 323;
      if ( v56(a1: v55, a2: 76, a3: &v78) != 0 )
        *(_DWORD *)urlArray[3].chAbbrev = GASArrayObject::GASArrayObject(
                                            penv: v54,
                                            a2: (GMemoryHeap *)v65,
                                            a3: (const char *)v66,
                                            a4: SDWORD1(v66));
      else
        *(_DWORD *)urlArray[3].chAbbrev = 0;
      v57 = *(_DWORD *)(a1 + 172);
      *(_DWORD *)urlArray[2].chAbbrev = v57;
      if ( v57 != 0 && *(_BYTE *)(v57 + 12) != 0 )
      {
        v58 = *(char **)(v57 + 4);
        if ( *(_BYTE *)(v57 + 13) != 0 )
          --v58;
        if ( v58 != nullptr )
        {
          v59 = 0;
          urlArray[4].szName = v58;
          do
          {
            GASBitmapFilterObject::CreateFromDesc(penv: *(const GFxAmpCurrentState **)urlArray[2].chAbbrev);
            v61 = v60;
            if ( v60 != nullptr )
            {
              GASValue::GASValue(this: v69, a2: v60);
              GASArrayObject::PushBack(this: *(GASArrayObject **)urlArray[3].chAbbrev, a2: (const struct GASValue *)v69);
              GASValue::~GASValue(this: v69);
              GRefCountBaseGC<323>::Release(a1: v61);
            }
            v59 += 156;
            --urlArray[4].szName;
          }
          while ( urlArray[4].szName != nullptr );
        }
      }
      v62 = *(_DWORD *)urlArray[3].chAbbrev;
      GASValue::SetAsObject(this: a4, a2: *(struct GASObject **)urlArray[3].chAbbrev);
      if ( v62 != 0 )
        GRefCountBaseGC<323>::Release(a1: v62);
      return 1;
    case 26:
      v22 = *(_DWORD *)(a1 + 160) >> 4;
      goto LABEL_30;
    case 27:
      v22 = *(_DWORD *)(a1 + 160) >> 13;
LABEL_30:
      GASValue::DropRefs(this: a4);
      *(_BYTE *)a4 = 2;
      *((_BYTE *)a4 + 4) = v22 & 1;
      break;
    case 29:
      v52 = *(_DWORD *)(a1 + 160) & 0x60;
      v30 = a4;
      if ( v52 != 0 )
      {
        GASValue::DropRefs(this: a4);
        *(_BYTE *)a4 = 2;
        *((_BYTE *)a4 + 4) = v52 == 96;
      }
      else
      {
LABEL_49:
        GASValue::DropRefs(this: v30);
        *(_BYTE *)a4 = 0;
      }
      break;
    case 30:
      urlArray[3].szName = (char *)*(__int16 *)(a1 + 164);
      v10 = (double)(int)urlArray[3].szName;
LABEL_11:
      GASValue::SetNumber(this: a4, a2: v10);
      break;
    case 31:
      v53 = *(_DWORD *)(a1 + 160) & 0x600;
      if ( v53 == 0 )
        return 0;
      GASValue::DropRefs(this: a4);
      *(_BYTE *)a4 = 2;
      *((_BYTE *)a4 + 4) = v53 == 1536;
      break;
    default:
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100867B0
// Name: public: class GFxASCharacter __near * GFxASCharacter::CloneDisplayObject(class GASString const __near &,int,class GASObjectInterface const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxASCharacter::CloneDisplayObject(
        CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *this,
        _IMAGE_SYMBOL_EX *newname,
        unsigned int depth,
        int a4)
{
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v5; // edi
  int v6; // eax
  int v7; // esi
  __int128 v9; // [esp-14h] [ebp-90h]
  _TAPE_WMI_OPERATIONS *v10; // [esp+10h] [ebp-6Ch]
  CMemberFunctor1<CMatRenderContextBase *,bool (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> pos; // [esp+24h] [ebp-58h] BYREF

  v5 = (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)GASObjectInterface::ToSprite(result: v10);
  if ( v5 != nullptr && depth <= 0x7EFFFFFD )
  {
    HIDWORD(v9) = 1;
    DWORD2(v9) = (char *)this + 36;
    *(_QWORD *)&v9 = depth | 0x100000000LL;
    GFxCharPosInfo::GFxCharPosInfo(
      this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *,IMaterial *),IMesh *,IMaterial *,CFuncMemPolicyNone> *)&pos,
      chId: (CMatRenderContextBase *)this->m_pObject,
      depth: v9);
    v6 = GFxSprite::AddDisplayObject(
           this: v5,
           name: (_IMAGE_SYMBOL_EX *)&pos,
           a3: (int)newname,
           a4: 0,
           a5: a4,
           createFrame: 0xFFFFFFFF,
           addFlags: 1u,
           rh: nullptr,
           a9: (int)this);
    if ( v6 != 0 )
    {
      v7 = *(_BYTE *)(v6 + 118) >> 7 != 0 ? v6 : 0;
      ((void (__stdcall *)(CMemberFunctor1<CMatRenderContextBase *,bool (__thiscall IMatRenderContext::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *))GMemory::pGlobalHeap->Free)(a1: pos.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable);
      return v7;
    }
    GMemory::pGlobalHeap->Free(
      this: GMemory::pGlobalHeap,
      a2: pos.CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100868A0
// Name: public: bool GFxASCharacter::HasClipEventHandler(class GFxEventId const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxASCharacter::HasClipEventHandler(GFxASCharacter *this, const struct GFxEventId *a2)
{
  int v2; // edx
  int v3; // eax
  int v4; // esi
  int v5; // eax
  int Index; // eax
  int v7; // eax
  int v9; // [esp+8h] [ebp-10h] BYREF
  int v10; // [esp+Ch] [ebp-Ch]
  __int64 v11; // [esp+10h] [ebp-8h]

  v2 = *(_DWORD *)a2;
  if ( *(_DWORD *)a2 == 64 || v2 == 128 )
  {
    v10 = 0;
    LOWORD(v11) = 0;
    *(_DWORD *)((char *)&v11 + 2) = 65280;
  }
  else
  {
    v10 = *((_DWORD *)a2 + 1);
    v3 = *((_DWORD *)a2 + 3);
    LODWORD(v11) = *((_DWORD *)a2 + 2);
    HIDWORD(v11) = v3;
  }
  v4 = *((_DWORD *)this + 39);
  v9 = v2;
  if ( v4 == 0 )
    return false;
  v5 = v2;
  if ( (v2 & 0x20000) != 0 )
    v5 = v2 ^ (__int16)v11;
  Index = GHashSetBase<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeHashF,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeAltHashF,GAllocatorLH<GFxEventId,323>,GHashsetCachedNodeEntry<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeHashF>>::findIndexCore<GFxEventId>(
            a1: &v9,
            a2: v5 & *(_DWORD *)(v4 + 4));
  return Index >= 0 && (v7 = v4 + 36 * Index + 16) != 0 && v7 != -16;
}

//------------------------------------------------------------------------------
// Address: 0x10086950
// Name: public: bool GFxASCharacter::InvokeClipEventHandlers(class GASEnvironment __near *,class GFxEventId const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxASCharacter::InvokeClipEventHandlers(
        GFxASCharacter *this,
        struct GASEnvironment *a2,
        const struct GFxEventId *a3)
{
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int Index; // eax
  int v9; // eax
  bool v10; // zf
  _DWORD *v11; // eax
  int v12; // edi
  int v14; // [esp+8h] [ebp-18h] BYREF
  int v15; // [esp+Ch] [ebp-14h]
  __int64 v16; // [esp+10h] [ebp-10h]
  GFxASCharacter *v17; // [esp+18h] [ebp-8h]
  _DWORD *v18; // [esp+1Ch] [ebp-4h]
  const struct GFxEventId *v19; // [esp+2Ch] [ebp+Ch]

  v4 = *(_DWORD *)a3;
  v17 = this;
  if ( v4 == 64 || v4 == 128 )
  {
    v15 = 0;
    LOWORD(v16) = 0;
    *(_DWORD *)((char *)&v16 + 2) = 65280;
  }
  else
  {
    v15 = *((_DWORD *)a3 + 1);
    v5 = *((_DWORD *)a3 + 3);
    LODWORD(v16) = *((_DWORD *)a3 + 2);
    HIDWORD(v16) = v5;
  }
  v6 = *((_DWORD *)this + 39);
  v14 = v4;
  if ( v6 == 0 )
    return 0;
  v7 = v4;
  if ( (v4 & 0x20000) != 0 )
    v7 = v4 ^ (__int16)v16;
  Index = GHashSetBase<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeHashF,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeAltHashF,GAllocatorLH<GFxEventId,323>,GHashsetCachedNodeEntry<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeHashF>>::findIndexCore<GFxEventId>(
            a1: &v14,
            a2: v7 & *(_DWORD *)(v6 + 4));
  if ( Index < 0 )
    return 0;
  v9 = v6 + 36 * Index + 16;
  if ( v9 == 0 )
    return 0;
  v10 = v9 == -16;
  v11 = (_DWORD *)(v9 + 16);
  v18 = v11;
  if ( v10 )
    return 0;
  if ( v11[1] != 0 )
  {
    v12 = 0;
    v19 = (const struct GFxEventId *)v11[1];
    while ( 1 )
    {
      GAS_Invoke(result: (_LOAD_DLL_DEBUG_INFO *)(v12 + *v11));
      v12 += 16;
      v19 = (const struct GFxEventId *)((char *)v19 - 1);
      if ( v19 == nullptr )
        break;
      v11 = v18;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10086A50
// Name: public: virtual void GFxASCharacter::VisitMembers(class GASStringContext __near *,struct GASObjectInterface::MemberVisitor __near *,unsigned int,class GASObjectInterface const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::VisitMembers(
        GFxASCharacter *this,
        struct GASStringContext *pvisitor,
        struct GASObjectInterface::MemberVisitor *pvisitor_4,
        unsigned int visitFlags,
        const struct GASObjectInterface *a5)
{
  int v6; // eax
  int v7; // esi

  v6 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 30) + 256))(a1: (char *)this - 120);
  v7 = v6;
  if ( v6 != 0 )
  {
    *(_DWORD *)(v6 + 8) = (*(_DWORD *)(v6 + 8) + 1) & 0x8FFFFFFF;
    (*(void (__thiscall **)(int, struct GASStringContext *, struct GASObjectInterface::MemberVisitor *, unsigned int, GFxASCharacter *))(*(_DWORD *)(v6 + 16) + 32))(
      a1: v6 + 16,
      a2: pvisitor,
      a3: pvisitor_4,
      a4: visitFlags,
      a5: this != (GFxASCharacter *)120 ? this : nullptr);
    GRefCountBaseGC<323>::Release(a1: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086AB0
// Name: public: virtual bool GFxASCharacter::SetMemberFlags(class GASStringContext __near *,class GASString const __near &,unsigned char)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxASCharacter::SetMemberFlags(
        GFxASCharacter *this,
        struct GASStringContext *a2,
        const struct GASString *a3,
        int a4)
{
  int v4; // eax
  int v5; // esi
  char v6; // bl

  v4 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 30) + 260))(a1: (char *)this - 120);
  v5 = v4;
  if ( v4 == 0 )
    return 0;
  *(_DWORD *)(v4 + 8) = (*(_DWORD *)(v4 + 8) + 1) & 0x8FFFFFFF;
  v6 = (*(int (__thiscall **)(int, struct GASStringContext *, const struct GASString *, int))(*(_DWORD *)(v4 + 16) + 28))(
         a1: v4 + 16,
         a2,
         a3,
         a4);
  GRefCountBaseGC<323>::Release(a1: v5);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10086B10
// Name: public: virtual bool GFxASCharacter::FindMember(class GASStringContext __near *,class GASString const __near &,class GASMember __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxASCharacter::FindMember(
        GFxASCharacter *this,
        struct GASStringContext *a2,
        const struct GASString *a3,
        struct GASMember *a4)
{
  int v4; // eax
  int v5; // esi
  char v6; // bl

  v4 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 30) + 260))(a1: (char *)this - 120);
  v5 = v4;
  if ( v4 == 0 )
    return 0;
  *(_DWORD *)(v4 + 8) = (*(_DWORD *)(v4 + 8) + 1) & 0x8FFFFFFF;
  v6 = (*(int (__thiscall **)(int, struct GASStringContext *, const struct GASString *, struct GASMember *))(*(_DWORD *)(v4 + 16) + 20))(
         a1: v4 + 16,
         a2,
         a3,
         a4);
  GRefCountBaseGC<323>::Release(a1: v5);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10086B70
// Name: public: virtual void GFxASCharacter::Set__proto__(class GASStringContext __near *,class GASObject __near *)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall GFxASCharacter::Set__proto__(
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *psc,
        CRefCountServiceDestruct<CRefST>_vtbl *psc_4)
{
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result; // eax
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v5; // esi
  CRefCountServiceDestruct<CRefST>_vtbl *v6; // ecx

  result = (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 30) + 260))(a1: (char *)this - 120);
  v5 = result;
  if ( result != nullptr )
  {
    result->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = (CRefCountServiceDestruct<CRefST>_vtbl *)(((int)&result->dtr_CRefCountServiceDestruct<CRefST> + 1) & 0x8FFFFFFF);
    result = (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(*(int (__thiscall **)(CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CFuncMemPolicyNone> *, const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *, CRefCountServiceDestruct<CRefST>_vtbl *))(LODWORD(result->m_Proxy.m_pfnProxied) + 52))(a1: &result->m_Proxy, a2: psc, a3: psc_4);
  }
  if ( psc_4 != nullptr )
  {
    result = (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(((int)psc_4[2].dtr_CRefCountServiceDestruct<CRefST> + 1) & 0x8FFFFFFF);
    psc_4[2].dtr_CRefCountServiceDestruct<CRefST> = (void (__thiscall *)(CRefCountServiceDestruct<CRefST> *))result;
  }
  v6 = this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable;
  if ( v6 != nullptr )
    result = (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GRefCountBaseGC<323>::Release(a1: v6);
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = psc_4;
  if ( v5 != nullptr )
    return (CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GRefCountBaseGC<323>::Release(a1: v5);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10086BE0
// Name: public: virtual bool GFxASCharacter::InstanceOf(class GASEnvironment __near *,class GASObject const __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::InstanceOf(
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        int a2,
        int inclInterfaces,
        int a4)
{
  int v4; // eax
  int v5; // esi

  v4 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 30) + 256))(a1: (char *)this - 120);
  v5 = v4;
  if ( v4 != 0 )
  {
    *(_DWORD *)(v4 + 8) = (*(_DWORD *)(v4 + 8) + 1) & 0x8FFFFFFF;
    (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)(v4 + 16) + 72))(a1: v4 + 16, a2, a3: inclInterfaces, a4);
    GRefCountBaseGC<323>::Release(a1: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086C40
// Name: public: virtual bool GFxASCharacter::Watch(class GASStringContext __near *,class GASString const __near &,class GASFunctionRef const __near &,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxASCharacter::Watch(_DWORD *this, _IMAGE_SYMBOL_EX *result, int a3, int a4, tagWNDCLASSW *userData)
{
  int v5; // eax
  int v6; // esi
  char v7; // bl

  v5 = (*(int (__thiscall **)(_DWORD *))(*(this - 30) + 260))(a1: this - 30);
  v6 = v5;
  if ( v5 == 0 )
    return 0;
  *(_DWORD *)(v5 + 8) = (*(_DWORD *)(v5 + 8) + 1) & 0x8FFFFFFF;
  v7 = (*(int (__thiscall **)(int, _IMAGE_SYMBOL_EX *, int, int, tagWNDCLASSW *))(*(_DWORD *)(v5 + 16) + 76))(
         a1: v5 + 16,
         a2: result,
         a3,
         a4,
         a5: userData);
  GRefCountBaseGC<323>::Release(a1: v6);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10086CA0
// Name: public: virtual bool GFxASCharacter::Unwatch(class GASStringContext __near *,class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxASCharacter::Unwatch(_DWORD *this, _IMAGE_SYMBOL_EX *result, int a3)
{
  int v3; // eax
  int v4; // esi
  char v5; // bl

  v3 = (*(int (__thiscall **)(_DWORD *))(*(this - 30) + 260))(a1: this - 30);
  v4 = v3;
  if ( v3 == 0 )
    return 0;
  *(_DWORD *)(v3 + 8) = (*(_DWORD *)(v3 + 8) + 1) & 0x8FFFFFFF;
  v5 = (*(int (__thiscall **)(int, _IMAGE_SYMBOL_EX *, int))(*(_DWORD *)(v3 + 16) + 80))(a1: v3 + 16, a2: result, a3);
  GRefCountBaseGC<323>::Release(a1: v4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10086DE0
// Name: public: GFxCharacterHandle::GFxCharacterHandle(class GASString const __near &,class GFxASCharacter __near *,class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
GFxCharacterHandle *__thiscall GFxCharacterHandle::GFxCharacterHandle(
        GFxCharacterHandle *this,
        CUtlMemory<CImagePacker,int> a2)
{
  CImagePacker *m_pMemory; // edi
  int m_MaxLightmapWidth; // eax
  const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v5; // eax
  int v6; // eax
  const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *m_nGrowSize; // eax
  const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *StringNode; // edi
  int v9; // ecx
  bool v10; // zf
  void *v11; // edi

  m_pMemory = a2.m_pMemory;
  m_MaxLightmapWidth = a2.m_pMemory->m_MaxLightmapWidth;
  *(this + 2) = (GFxCharacterHandle)a2.m_pMemory->m_MaxLightmapWidth;
  ++*(_DWORD *)(m_MaxLightmapWidth + 8);
  v5 = *(const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(*(_DWORD *)(m_pMemory->m_MaxLightmapWidth & 0xFFFFFC00) + 32);
  *(this + 3) = v5;
  ++v5->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable;
  v6 = m_pMemory->m_MaxLightmapWidth;
  *(this + 4) = (GFxCharacterHandle)m_pMemory->m_MaxLightmapWidth;
  ++*(_DWORD *)(v6 + 8);
  m_nGrowSize = (const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)a2.m_nGrowSize;
  *this = (GFxCharacterHandle)1;
  *(this + 1) = m_nGrowSize;
  GString::GString(this: &a2);
  if ( a2.m_nAllocationCount != 0 )
  {
    GFxASCharacter::GetAbsolutePath(
      this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)a2.m_nAllocationCount,
      &a2);
    GString::AppendString(this: &a2, putf8str: (int)&stru_1029E6EC.m_Elements.m_nGrowSize);
  }
  GString::AppendString(
    this: &a2,
    putf8str: (int)(*(this + 2))->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable);
  StringNode = (const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GASStringManager::CreateStringNode(this: *(GASStringManager **)(m_pMemory->m_MaxLightmapWidth & 0xFFFFFC00), result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(((int)a2.m_pMemory & 0xFFFFFFFC) + 8), length: *(_DWORD *)((int)a2.m_pMemory & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = (CRefCountServiceDestruct<CRefST>_vtbl *)((char *)StringNode->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable + 2);
  v9 = (int)*(this + 3);
  v10 = (*(_DWORD *)(v9 + 8))-- == 1;
  if ( v10 )
    GASStringNode::ReleaseNode();
  *(this + 3) = StringNode;
  v10 = StringNode->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable-- == (CRefCountServiceDestruct<CRefST>_vtbl *)1;
  if ( v10 )
    GASStringNode::ReleaseNode();
  v11 = (void *)((int)a2.m_pMemory & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)(((int)a2.m_pMemory & 0xFFFFFFFC) + 4), Value: -1) == 1 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v11);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10086ED0
// Name: public: void GFxCharacterHandle::ChangeName(class GASString const __near &,class GFxASCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxCharacterHandle::ChangeName(
        CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        _IMAGE_SYMBOL_EX *name,
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *a3)
{
  _IMAGE_SYMBOL_EX *v3; // ebx
  CRefCountServiceDestruct<CRefST>_vtbl *Short; // esi
  CRefCountServiceDestruct<CRefST>_vtbl *v6; // ecx
  bool v7; // zf
  struct GASStringNode *StringNode; // esi
  int m_iRefs; // ecx
  unsigned int v10; // esi
  void *result; // eax

  v3 = name;
  Short = (CRefCountServiceDestruct<CRefST>_vtbl *)name->N.Name.Short;
  ++*(_DWORD *)(name->N.Name.Short + 8);
  v6 = this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable;
  v7 = v6[2].dtr_CRefCountServiceDestruct<CRefST>-- == (void (__thiscall *)(CRefCountServiceDestruct<CRefST> *))1;
  if ( v7 )
    GASStringNode::ReleaseNode();
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = Short;
  GString::GString(this: (CUtlMemory<CImagePacker,int> *)&name);
  if ( a3 != nullptr )
  {
    GFxASCharacter::GetAbsolutePath(this: a3, a2: (CUtlMemory<CImagePacker,int> *)&name);
    GString::AppendString(
      this: (CUtlMemory<CImagePacker,int> *)&name,
      putf8str: (int)&stru_1029E6EC.m_Elements.m_nGrowSize);
  }
  GString::AppendString(
    this: (CUtlMemory<CImagePacker,int> *)&name,
    putf8str: (int)this->dtr_CRefCountServiceDestruct<CRefST>);
  StringNode = GASStringManager::CreateStringNode(
                 this: *(GASStringManager **)(v3->N.Name.Short & 0xFFFFFC00),
                 result: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)(((unsigned int)name
                                                                                           & 0xFFFFFFFC)
                                                                                          + 8),
                 length: *(_DWORD *)((unsigned int)name & 0xFFFFFFFC) & 0x7FFFFFFF);
  *((_DWORD *)StringNode + 2) += 2;
  m_iRefs = this->m_iRefs;
  v7 = (*(_DWORD *)(m_iRefs + 8))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode();
  this->m_iRefs = (int)StringNode;
  v7 = (*((_DWORD *)StringNode + 2))-- == 1;
  if ( v7 )
    GASStringNode::ReleaseNode();
  v10 = (unsigned int)name & 0xFFFFFFFC;
  result = (void *)(InterlockedExchangeAdd(Addend: (volatile LONG *)(((unsigned int)name & 0xFFFFFFFC) + 4), Value: -1)
                  - 1);
  if ( result == nullptr )
    return ((void *(__thiscall *)(GMemoryHeap *, unsigned int))GMemory::pGlobalHeap->Free)(
             a1: GMemory::pGlobalHeap,
             a2: v10);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10086FA0
// Name: public: virtual void GFxASCharacter::SetName(class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::SetName(GFxASCharacter *this, int name)
{
  _IMAGE_SYMBOL_EX *v2; // esi
  CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v4; // ecx
  GFxCharacterHandle *v5; // eax
  _DWORD *v6; // esi
  int v7; // ecx
  bool v8; // zf
  int v9; // ecx
  int v10; // ecx
  CUtlMemory<CImagePacker,int> v11; // [esp-Ch] [ebp-14h]

  v2 = (_IMAGE_SYMBOL_EX *)name;
  if ( *(_DWORD *)(*(_DWORD *)name + 16) != 0 )
    *((_DWORD *)this + 40) &= ~0x4000u;
  v4 = *((CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)this
       + 37);
  if ( v4 != nullptr )
  {
    GFxCharacterHandle::ChangeName(
      this: v4,
      name: v2,
      a3: *((CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> **)this
      + 8));
  }
  else
  {
    name = 323;
    v5 = (GFxCharacterHandle *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                 this: GMemory::pGlobalHeap,
                                 a2: this,
                                 a3: 20,
                                 a4: &name);
    if ( v5 != nullptr )
    {
      v11.m_nGrowSize = (int)this;
      v11.m_nAllocationCount = *((_DWORD *)this + 8);
      v11.m_pMemory = (CImagePacker *)v2;
      name = (int)GFxCharacterHandle::GFxCharacterHandle(this: v5, a2: v11);
    }
    else
    {
      name = 0;
    }
    v6 = *((_DWORD **)this + 37);
    if ( v6 != nullptr && (int)--*v6 <= 0 )
    {
      v7 = v6[4];
      v8 = (*(_DWORD *)(v7 + 8))-- == 1;
      if ( v8 )
        GASStringNode::ReleaseNode();
      v9 = v6[3];
      v8 = (*(_DWORD *)(v9 + 8))-- == 1;
      if ( v8 )
        GASStringNode::ReleaseNode();
      v10 = v6[2];
      v8 = (*(_DWORD *)(v10 + 8))-- == 1;
      if ( v8 )
        GASStringNode::ReleaseNode();
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
    }
    *((_DWORD *)this + 37) = name;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087070
// Name: protected: class GFxCharacterHandle __near * GFxASCharacter::CreateCharacterHandle(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::CreateCharacterHandle(
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *this)
{
  int v2; // esi
  int v3; // ecx
  int (__thiscall *v4)(int, int, int *); // edx
  GFxCharacterHandle *v5; // esi
  _DWORD *v6; // esi
  int v7; // ecx
  bool v8; // zf
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int (__thiscall *v12)(int, int, int *); // edx
  GFxCharacterHandle *v13; // eax
  _DWORD *v14; // esi
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx
  CUtlMemory<CImagePacker,int> v18; // [esp-Ch] [ebp-20h]
  CUtlMemory<CImagePacker,int> v19; // [esp-Ch] [ebp-20h]
  GPtr<IDirect3DVertexShader9> result; // [esp+Ch] [ebp-8h] BYREF
  int v21; // [esp+10h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 37) == 0 )
  {
    v2 = (*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 84))(a1: this);
    if ( (*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(*((_DWORD *)this + 30) + 8))(a1: this + 5) == 2
      && (*((_BYTE *)this + 118) & 0x10) != 0 )
    {
      v3 = *(_DWORD *)(v2 + 32);
      v4 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v3 + 40);
      v21 = 323;
      v5 = (GFxCharacterHandle *)v4(a1: v3, a2: 20, a3: &v21);
      if ( v5 != nullptr )
      {
        *(_QWORD *)&v18.m_nAllocationCount = 0;
        v18.m_pMemory = (CImagePacker *)(*(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 108))(a1: this)
                                                   + 120)
                                       + 8);
        v21 = (int)GFxCharacterHandle::GFxCharacterHandle(this: v5, a2: v18);
      }
      else
      {
        v21 = 0;
      }
      v6 = *((_DWORD **)this + 37);
      if ( v6 != nullptr && (int)--*v6 <= 0 )
      {
        v7 = v6[4];
        v8 = (*(_DWORD *)(v7 + 8))-- == 1;
        if ( v8 )
          GASStringNode::ReleaseNode();
        v9 = v6[3];
        v8 = (*(_DWORD *)(v9 + 8))-- == 1;
        if ( v8 )
          GASStringNode::ReleaseNode();
        v10 = v6[2];
        v8 = (*(_DWORD *)(v10 + 8))-- == 1;
        if ( v8 )
          GASStringNode::ReleaseNode();
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
      }
      *((_DWORD *)this + 37) = v21;
    }
    else
    {
      GFxMovieRoot::CreateNewInstanceName(&result);
      v11 = *(_DWORD *)(v2 + 32);
      v12 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v11 + 40);
      v21 = 323;
      v13 = (GFxCharacterHandle *)v12(a1: v11, a2: 20, a3: &v21);
      if ( v13 != nullptr )
      {
        v19.m_nGrowSize = (int)this;
        v19.m_nAllocationCount = *((_DWORD *)this + 8);
        v19.m_pMemory = (CImagePacker *)&result;
        v21 = (int)GFxCharacterHandle::GFxCharacterHandle(this: v13, a2: v19);
      }
      else
      {
        v21 = 0;
      }
      v14 = *((_DWORD **)this + 37);
      if ( v14 != nullptr && (int)--*v14 <= 0 )
      {
        v15 = v14[4];
        v8 = (*(_DWORD *)(v15 + 8))-- == 1;
        if ( v8 )
          GASStringNode::ReleaseNode();
        v16 = v14[3];
        v8 = (*(_DWORD *)(v16 + 8))-- == 1;
        if ( v8 )
          GASStringNode::ReleaseNode();
        v17 = v14[2];
        v8 = (*(_DWORD *)(v17 + 8))-- == 1;
        if ( v8 )
          GASStringNode::ReleaseNode();
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v14);
      }
      *((_DWORD *)this + 37) = v21;
      v8 = result.pObject[2].__vftable-- == (IDirect3DVertexShader9_vtbl *)1;
      if ( v8 )
        GASStringNode::ReleaseNode();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087200
// Name: public: virtual bool GFxASCharacter::ExecuteFunction(class GASFunctionRef const __near &,class GArray<class GASValue,2,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxASCharacter::ExecuteFunction(
        CMemberFuncProxy1<IMesh *,void (__thiscall IMesh::*)(enum MaterialPrimitiveType_t),enum MaterialPrimitiveType_t,CFuncMemPolicyNone> *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int *a4,
        int *a5)
{
  bool v5; // zf
  CMemberFuncProxy1<IMesh *,void (__thiscall IMesh::*)(enum MaterialPrimitiveType_t),enum MaterialPrimitiveType_t,CFuncMemPolicyNone> *v6; // esi
  int (__thiscall *v7)(CMemberFuncProxy1<IMesh *,void (__thiscall IMesh::*)(enum MaterialPrimitiveType_t),enum MaterialPrimitiveType_t,CFuncMemPolicyNone> *, int, int); // eax
  __vc_attributes::iid_isAttribute *v8; // eax
  int v9; // edi
  __vc_attributes::iid_isAttribute *v10; // esi
  int v11; // ebx
  int v12; // edi
  const struct GASValue *v13; // edi
  CMemberFuncProxy1<IMesh *,void (__thiscall IMesh::*)(enum MaterialPrimitiveType_t),enum MaterialPrimitiveType_t,CFuncMemPolicyNone> *v14; // ecx
  __vc_attributes::iid_isAttribute *v15; // esi
  int v16; // edx
  int v17; // ecx
  const char *v18; // eax
  const char *v19; // [esp-8h] [ebp-50h]
  const char *v20; // [esp+0h] [ebp-48h]
  _DWORD v21[3]; // [esp+4h] [ebp-44h] BYREF
  int v22; // [esp+10h] [ebp-38h]
  int v23; // [esp+14h] [ebp-34h]
  char v24; // [esp+18h] [ebp-30h]
  __vc_attributes::iid_isAttribute *v25; // [esp+1Ch] [ebp-2Ch]
  int v26; // [esp+20h] [ebp-28h]
  int v27; // [esp+24h] [ebp-24h]
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *result; // [esp+28h] [ebp-20h] BYREF
  int nArgs; // [esp+38h] [ebp-10h]
  __vc_attributes::iid_isAttribute *v30; // [esp+3Ch] [ebp-Ch]
  CMemberFuncProxy1<IMesh *,void (__thiscall IMesh::*)(enum MaterialPrimitiveType_t),enum MaterialPrimitiveType_t,CFuncMemPolicyNone> *v31; // [esp+40h] [ebp-8h]
  int i; // [esp+44h] [ebp-4h]

  v5 = *a4 == 0;
  v6 = this;
  v31 = this;
  if ( !v5 )
  {
    v7 = *(int (__thiscall **)(CMemberFuncProxy1<IMesh *,void (__thiscall IMesh::*)(enum MaterialPrimitiveType_t),enum MaterialPrimitiveType_t,CFuncMemPolicyNone> *, int, int))(LODWORD(this->m_pfnProxied) + 112);
    LOBYTE(result) = 0;
    v8 = (__vc_attributes::iid_isAttribute *)v7(a1: this, a2: a3, a3: a2);
    v9 = a5[1];
    v30 = v8;
    nArgs = v9;
    if ( v9 > 0 )
    {
      i = v9 - 1;
      v10 = v8 + 2;
      v11 = 16 * (v9 - 1);
      do
      {
        v12 = *a5;
        v10->limited_expression += 16;
        v13 = (const struct GASValue *)(v11 + v12);
        if ( v10->limited_expression >= v10[2].limited_expression )
          GASPagedStack<GASValue,32>::PushPage(this: v10, a2: v20);
        if ( v10->limited_expression != nullptr )
          GASValue::GASValue(this: (GASValue *)v10->limited_expression, a2: v13);
        v11 -= 16;
        --i;
      }
      while ( i >= 0 );
      v6 = v31;
      v8 = v30;
      v9 = nArgs;
    }
    v14 = v6 + 5;
    v15 = v8 + 2;
    v16 = ((v8[2].limited_expression - v8[3].limited_expression) >> 4) + 32 * (int)v8[7].limited_expression - 32;
    v25 = v8;
    v21[1] = &result;
    v21[2] = v14;
    v17 = *a4;
    v18 = (const char *)a4[1];
    v27 = v16;
    v19 = v18;
    v21[0] = &GASFnCall::`vftable';
    v24 = 0;
    v22 = 0;
    v23 = 0;
    v26 = v9;
    (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v17 + 40))(a1: v17, a2: v21);
    v21[0] = &GASFnCall::`vftable';
    if ( (v24 & 2) == 0 && v22 != 0 )
      GRefCountBaseGC<323>::Release(a1: v22);
    v22 = 0;
    if ( (v24 & 1) == 0 && v23 != 0 )
      GRefCountBaseGC<323>::Release(a1: v23);
    if ( v9 > 0 )
    {
      do
      {
        GASValue::~GASValue(this: (GASValue *)v15->limited_expression);
        v15->limited_expression -= 16;
        if ( v15->limited_expression < v15[1].limited_expression )
          GASPagedStack<GASValue,32>::PopPage(this: v15, a2: v19);
        --v9;
      }
      while ( v9 != 0 );
    }
    GASValue::~GASValue(this: &result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087340
// Name: public: virtual bool GFxASCharacter::ExecuteCFunction(void (*const)(class GASFnCall const __near &),class GArray<class GASValue,2,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GFxASCharacter::ExecuteCFunction@<al>(
        int a1@<ecx>,
        const char *a2@<edi>,
        void (__cdecl *a3)(_DWORD *),
        int *a4)
{
  int v4; // esi
  int (__thiscall *v5)(int); // edx
  __vc_attributes::iid_isAttribute *v6; // eax
  int v7; // edi
  __vc_attributes::iid_isAttribute *v8; // esi
  int v9; // ebx
  int v10; // edi
  const struct GASValue *v11; // edi
  int v12; // ecx
  __vc_attributes::iid_isAttribute *v13; // esi
  int v14; // edx
  const char *v16; // [esp-8h] [ebp-50h]
  _DWORD v17[3]; // [esp+4h] [ebp-44h] BYREF
  int v18; // [esp+10h] [ebp-38h]
  int v19; // [esp+14h] [ebp-34h]
  char v20; // [esp+18h] [ebp-30h]
  __vc_attributes::iid_isAttribute *v21; // [esp+1Ch] [ebp-2Ch]
  int v22; // [esp+20h] [ebp-28h]
  int v23; // [esp+24h] [ebp-24h]
  GASValue v24[4]; // [esp+28h] [ebp-20h] BYREF
  int v25; // [esp+38h] [ebp-10h]
  __vc_attributes::iid_isAttribute *v26; // [esp+3Ch] [ebp-Ch]
  int v27; // [esp+40h] [ebp-8h]
  int v28; // [esp+44h] [ebp-4h]

  v4 = a1;
  v27 = a1;
  if ( a3 == nullptr )
    return 0;
  v5 = *(int (__thiscall **)(int))(*(_DWORD *)a1 + 112);
  v16 = a2;
  LOBYTE(v24[0]) = 0;
  v6 = (__vc_attributes::iid_isAttribute *)v5(a1);
  v7 = a4[1];
  v26 = v6;
  v25 = v7;
  if ( v7 > 0 )
  {
    v28 = v7 - 1;
    v8 = v6 + 2;
    v9 = 16 * (v7 - 1);
    do
    {
      v10 = *a4;
      v8->limited_expression += 16;
      v11 = (const struct GASValue *)(v9 + v10);
      if ( v8->limited_expression >= v8[2].limited_expression )
        GASPagedStack<GASValue,32>::PushPage(this: v8, a2: v16);
      if ( v8->limited_expression != nullptr )
        GASValue::GASValue(this: (GASValue *)v8->limited_expression, a2: v11);
      v9 -= 16;
      --v28;
    }
    while ( v28 >= 0 );
    v4 = v27;
    v6 = v26;
    v7 = v25;
  }
  v12 = v4 + 120;
  v13 = v6 + 2;
  v14 = ((v6[2].limited_expression - v6[3].limited_expression) >> 4) + 32 * (int)v6[7].limited_expression - 32;
  v21 = v6;
  v17[1] = v24;
  v17[0] = &GASFnCall::`vftable';
  v17[2] = v12;
  v20 = 0;
  v18 = 0;
  v19 = 0;
  v22 = v7;
  v23 = v14;
  a3(a1: v17);
  v17[0] = &GASFnCall::`vftable';
  if ( (v20 & 2) == 0 && v18 != 0 )
    GRefCountBaseGC<323>::Release(a1: v18);
  v18 = 0;
  if ( (v20 & 1) == 0 && v19 != 0 )
    GRefCountBaseGC<323>::Release(a1: v19);
  if ( v7 > 0 )
  {
    do
    {
      GASValue::~GASValue(this: (GASValue *)v13->limited_expression);
      v13->limited_expression -= 16;
      if ( v13->limited_expression < v13[1].limited_expression )
        GASPagedStack<GASValue,32>::PopPage(this: v13, a2: v16);
      --v7;
    }
    while ( v7 != 0 );
  }
  GASValue::~GASValue(this: v24);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10087480
// Name: public: virtual void GFxASCharacter::OnFocus(enum GFxASCharacter::FocusEventType,class GFxASCharacter __near *,unsigned int,enum GFxFocusMovedType)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxASCharacter::OnFocus(
        tagAXISINFOA *a1@<ecx>,
        char *a2@<esi>,
        struct GASValue *a3,
        tagAXISINFOA *result,
        unsigned int a5,
        int a6)
{
  int (__fastcall *v7)(tagAXISINFOA *); // edx
  int v8; // eax
  int v9; // ebx
  int v10; // esi
  unsigned int v11; // ecx
  int v12; // edi
  int v13; // esi
  double v14; // st7
  tagAXISINFOA *v15; // eax
  int v16; // esi
  tagWNDCLASSW *v17; // eax
  PPM_IDLE_STATE_ACCOUNTING *v18; // eax
  int v20; // [esp-8h] [ebp-78h]
  char *v21; // [esp-4h] [ebp-74h]
  const char *v22; // [esp-4h] [ebp-74h]
  int v23[9]; // [esp+8h] [ebp-68h] BYREF
  PPM_IDLE_STATE_ACCOUNTING v24; // [esp+2Ch] [ebp-44h] BYREF
  double v25; // [esp+60h] [ebp-10h]
  tagAXISINFOA *v26; // [esp+68h] [ebp-8h]
  int v27; // [esp+6Ch] [ebp-4h] BYREF
  struct GASValue *v28; // [esp+78h] [ebp+8h]

  v7 = *(int (__fastcall **)(tagAXISINFOA *))(a1->axMinValue + 112);
  v26 = a1;
  LOBYTE(v24.TotalTime) = 0;
  v8 = v7(a1);
  v9 = v8;
  if ( v8 != 0 )
  {
    v21 = a2;
    v10 = v8 + 120;
    v27 = *(_DWORD *)(*(_DWORD *)(v8 + 120) + 4 * (a3 != (struct GASValue *)1) + 360);
    ++*(_DWORD *)(v27 + 8);
    if ( (*(unsigned __int8 (__thiscall **)(tagAXISINFOA *, int, int *, unsigned __int64 *))(a1[5].axMinValue + 44))(
           a1: a1 + 5,
           a2: v8 + 120,
           a3: &v27,
           a4: &v24.TotalTime) != 0 )
    {
      GASValue::ToFunction(a1: &v24.IdleTimeBuckets[2], a2: 0);
      v11 = v24.IdleTimeBuckets[2];
      if ( v24.IdleTimeBuckets[2] != 0 )
      {
        v12 = 1;
        if ( *(_BYTE *)(*(_DWORD *)v10 + 684) == 1 )
        {
          *(_DWORD *)(v9 + 8) += 16;
          v25 = (double)a5;
          if ( *(_DWORD *)(v9 + 8) >= *(_DWORD *)(v9 + 16) )
            GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(v9 + 8), a2: v21);
          v13 = *(_DWORD *)(v9 + 8);
          if ( v13 != 0 )
          {
            v14 = v25;
            *(_BYTE *)v13 = 3;
            *(double *)(v13 + 4) = v14;
          }
          v12 = 2;
        }
        if ( result != nullptr )
        {
          v15 = GASValue::GASValue(result);
          *(_DWORD *)(v9 + 8) += 16;
          v16 = v9 + 8;
          v28 = (struct GASValue *)v15;
          if ( *(_DWORD *)(v9 + 8) >= *(_DWORD *)(v9 + 16) )
            GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(v9 + 8), a2: v21);
          if ( *(_DWORD *)v16 != 0 )
            GASValue::GASValue(this: *(GASValue **)v16, a2: v28);
          GASValue::~GASValue(this: (GASValue *)&v24.IdleTimeBuckets[5]);
        }
        else
        {
          *(_DWORD *)(v9 + 8) += 16;
          v16 = v9 + 8;
          if ( *(_DWORD *)(v9 + 8) >= *(_DWORD *)(v9 + 16) )
            GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(v9 + 8), a2: v21);
          if ( *(_DWORD *)v16 != 0 )
            **(_BYTE **)v16 = 1;
        }
        v20 = ((*(_DWORD *)v16 - *(_DWORD *)(v16 + 4)) >> 4) + 32 * *(_DWORD *)(v16 + 20) - 32;
        LOBYTE(v24.IdleTransitions) = 0;
        v17 = (tagWNDCLASSW *)GASValue::GASValue(result: v26);
        v18 = GASFnCall::GASFnCall(
                this: v23,
                result: &v24,
                ThisIn: v17,
                a4: (_SERVICE_STATUS *)v9,
                NargsIn: v12,
                FirstIn: v20);
        (*(void (__thiscall **)(unsigned int, PPM_IDLE_STATE_ACCOUNTING *, unsigned int, _DWORD))(*(_DWORD *)v24.IdleTimeBuckets[2]
                                                                                                + 40))(
          a1: v24.IdleTimeBuckets[2],
          a2: v18,
          a3: v24.IdleTimeBuckets[3],
          a4: 0);
        GASFnCall::~GASFnCall(result: (tagMOUSEHOOKSTRUCTEX *)v21);
        GASValue::~GASValue(this: (GASValue *)&v24.IdleTimeBuckets[5]);
        do
        {
          GASValue::~GASValue(this: *(GASValue **)v16);
          *(_DWORD *)v16 -= 16;
          if ( *(_DWORD *)v16 < *(_DWORD *)(v16 + 4) )
            GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)v16, a2: v22);
          --v12;
        }
        while ( v12 != 0 );
        GASValue::~GASValue(this: (GASValue *)&v24);
        v11 = v24.IdleTimeBuckets[2];
      }
      if ( (v24.IdleTimeBuckets[4] & 2) == 0 && v11 != 0 )
        GRefCountBaseGC<323>::Release(a1: v11);
      v24.IdleTimeBuckets[2] = 0;
      if ( (v24.IdleTimeBuckets[4] & 1) == 0 && v24.IdleTimeBuckets[3] != 0 )
        GRefCountBaseGC<323>::Release(a1: v24.IdleTimeBuckets[3]);
    }
    if ( (*(_DWORD *)(v27 + 8))-- == 1 )
      GASStringNode::ReleaseNode();
  }
  GASValue::~GASValue(this: (GASValue *)&v24.TotalTime);
}

//------------------------------------------------------------------------------
// Address: 0x10087860
// Name: public: virtual void GFxASCharacter::SetOriginalName(class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::SetOriginalName(
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *this,
        const struct GASString *name)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  int v6; // ecx

  GFxASCharacter::SetName((GFxASCharacter *)this, (int)name);
  v3 = *((_DWORD *)this + 37);
  if ( v3 != 0 || (GFxASCharacter::CreateCharacterHandle(this), v3 = v4, v4 != 0) )
  {
    v5 = *(_DWORD *)name;
    ++*(_DWORD *)(*(_DWORD *)name + 8);
    v6 = *(_DWORD *)(v3 + 16);
    if ( (*(_DWORD *)(v6 + 8))-- == 1 )
      GASStringNode::ReleaseNode();
    *(_DWORD *)(v3 + 16) = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100878B0
// Name: public: class GASString const __near & GFxASCharacter::GetOriginalName(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::GetOriginalName(
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialFogMode_t),enum MaterialFogMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  int v2; // eax
  int v3; // eax

  if ( *((_DWORD *)this + 37) == 0 )
  {
    GFxASCharacter::CreateCharacterHandle((CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this);
    if ( v2 == 0 && *((_DWORD *)this + 37) == 0 )
    {
      GFxASCharacter::CreateCharacterHandle((CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this);
      if ( v3 == 0 )
        this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable[6].operator()(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087900
// Name: public: enum GFxASCharacter::StandardMember GFxASCharacter::GetStandardMemberConstant(class GASString const __near &)const
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *__thiscall GFxASCharacter::GetStandardMemberConstant(
        void *this,
        _IMAGE_SYMBOL_EX *result)
{
  int (__thiscall *v3)(void *); // edx
  int v4; // eax
  const MaterialPrimitiveType_t *v5; // ecx
  int v6; // edi
  char v7; // al
  bool v8; // zf
  int v9; // esi
  int lowerCase; // [esp+Ch] [ebp-8h] BYREF
  char memberConstant; // [esp+13h] [ebp-1h] BYREF

  v3 = *(int (__thiscall **)(void *))(*(_DWORD *)this + 208);
  memberConstant = -1;
  v4 = *(_DWORD *)(v3(a1: this) + 8);
  ++*(_DWORD *)(v4 + 8);
  lowerCase = v4;
  GFxASCharacter::IsStandardMember(memberName: v5, pcaseInsensitiveName: result, &lowerCase);
  v6 = lowerCase;
  if ( v7 != 0 )
  {
    (*(void (__thiscall **)(void *))(*(_DWORD *)this + 208))(a1: this);
    GASStringHashBase<char,GHashUncachedLH<GASString,char,GASStringHashFunctor,323>>::GetCaseCheck(
      ikey: (_EXIT_THREAD_DEBUG_INFO *)result,
      pvalue: &memberConstant,
      a3: *(_DWORD *)(v6 + 16) == 0);
  }
  v8 = (*(_DWORD *)(v6 + 8))-- == 1;
  v9 = memberConstant;
  if ( v8 )
    GASStringNode::ReleaseNode();
  return (CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *)v9;
}

//------------------------------------------------------------------------------
// Address: 0x10087980
// Name: public: virtual bool GFxASCharacter::ExecuteEvent(class GFxEventId const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxASCharacter::ExecuteEvent(
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *this,
        const struct GFxEventId *a2)
{
  int v3; // edi
  GRefCountNTSImpl *v4; // eax
  struct GFxMovieRoot *MovieRoot; // eax
  unsigned int v6; // ecx
  GFxKeyboardState *v7; // ecx
  bool v8; // zf
  int v9; // ecx
  int v10; // eax
  char v11; // al
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v12; // eax
  unsigned int v13; // eax
  GASValue *v14; // ecx
  int v15; // eax
  int v16; // ebx
  unsigned int v17; // eax
  GASValue *v18; // ecx
  char *v19; // ecx
  unsigned int v20; // eax
  GASValue *v21; // ecx
  CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *v22; // edx
  unsigned int v23; // eax
  GASValue *v24; // ecx
  char v25; // al
  const char *v26; // edx
  unsigned int v27; // eax
  GASValue *v28; // ecx
  int v29; // ebx
  char v30; // al
  const wchar_t *lpszMenuName; // ecx
  char v32; // al
  char v33; // al
  bool v34; // bl
  const char *v36; // [esp+0h] [ebp-CCh]
  const char *v37; // [esp+0h] [ebp-CCh]
  const char *v38; // [esp+0h] [ebp-CCh]
  const char *v39; // [esp+4h] [ebp-C8h]
  const char *v40; // [esp+4h] [ebp-C8h]
  const char *v41; // [esp+4h] [ebp-C8h]
  const char *v42; // [esp+8h] [ebp-C4h]
  const char *v43; // [esp+8h] [ebp-C4h]
  const char *v44; // [esp+8h] [ebp-C4h]
  GASValue v45; // [esp+Ch] [ebp-C0h] BYREF
  const char *v46; // [esp+10h] [ebp-BCh]
  int v47; // [esp+14h] [ebp-B8h]
  int v48; // [esp+18h] [ebp-B4h]
  char v49[4]; // [esp+1Ch] [ebp-B0h] BYREF
  BOOL v50; // [esp+20h] [ebp-ACh]
  GASValue v51[4]; // [esp+2Ch] [ebp-A0h] BYREF
  GASValue v52[4]; // [esp+3Ch] [ebp-90h] BYREF
  char v53[4]; // [esp+4Ch] [ebp-80h] BYREF
  int v54; // [esp+50h] [ebp-7Ch]
  tagWNDCLASSW v; // [esp+5Ch] [ebp-70h] BYREF
  _DWORD v56[2]; // [esp+84h] [ebp-48h] BYREF
  char v57; // [esp+8Ch] [ebp-40h]
  GRefCountNTSImpl *v58; // [esp+90h] [ebp-3Ch]
  int v59; // [esp+94h] [ebp-38h] BYREF
  int v60; // [esp+98h] [ebp-34h]
  char v61; // [esp+9Ch] [ebp-30h]
  int v62; // [esp+A0h] [ebp-2Ch] BYREF
  int v63; // [esp+A4h] [ebp-28h]
  char v64; // [esp+A8h] [ebp-24h]
  _LOAD_DLL_DEBUG_INFO v65; // [esp+ACh] [ebp-20h] BYREF
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *v66; // [esp+C4h] [ebp-8h]
  char v67; // [esp+CBh] [ebp-1h]

  v66 = this;
  if ( this != nullptr )
    ++DWORD1(this->m_pfnProxied);
  v3 = (*(int (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 112))(a1: this);
  v4 = *(GRefCountNTSImpl **)(v3 + 116);
  v58 = v4;
  if ( v4 != nullptr )
    ++v4->RefCount;
  if ( *(_DWORD *)a2 == 64 || *(_DWORD *)a2 == 128 )
  {
    MovieRoot = GASEnvironment::GetMovieRoot(this: (GASEnvironment *)v3);
    if ( MovieRoot != nullptr )
    {
      v6 = *((char *)a2 + 11);
      if ( v6 >= 4 )
        v7 = nullptr;
      else
        v7 = (GFxKeyboardState *)((char *)MovieRoot + 1660 * v6 + 2516);
      GFxKeyboardState::UpdateListeners(
        this: v7,
        code: *((_WORD *)a2 + 4),
        ascii: *((_BYTE *)a2 + 10),
        a4: *((_DWORD *)a2 + 1));
    }
  }
  v65.lpImageName = nullptr;
  LOBYTE(v65.hFile) = 0;
  if ( GFxASCharacter::HasClipEventHandler((GFxASCharacter *)this, a2) && *((_BYTE *)a2 + 12) == 0 )
  {
    GFxASCharacter::InvokeClipEventHandlers((GFxASCharacter *)this, a2: (struct GASEnvironment *)v3, a3: a2);
    v65.lpImageName = (void *)1;
  }
  GFxEventId::GetFunctionName(a1: a2, a2: &v65.fUnicode, a3: v3 + 120);
  if ( *(_DWORD *)(*(_DWORD *)&v65.fUnicode + 16) == 0
    || (*(unsigned __int8 (__thiscall **)(CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *, int, unsigned __int16 *, _LOAD_DLL_DEBUG_INFO *))(LODWORD(v66[5].m_pfnProxied) + 44))(
         a1: v66 + 5,
         a2: v3 + 120,
         a3: &v65.fUnicode,
         a4: &v65) == 0 )
  {
    goto LABEL_108;
  }
  if ( LOBYTE(v65.hFile) == 9 )
  {
    LOBYTE(v.style) = 0;
    GASValue::GetPropertyValue(
      this: (GASValue *)&v65,
      a2: (struct GASEnvironment *)v3,
      a3: (struct GASObjectInterface *)&v66[5],
      a4: (struct GASValue *)&v);
    GASValue::operator=(&v);
    GASValue::~GASValue(this: (GASValue *)&v);
  }
  if ( LOBYTE(v65.hFile) == 1 )
    goto LABEL_108;
  if ( *(_BYTE *)(*(_DWORD *)(v3 + 120) + 684) == 1 )
  {
    v8 = *((_BYTE *)a2 + 12) == 0;
    v67 = 1;
    if ( !v8 )
    {
      GASValue::ToFunction(a1: &v62, a2: v3);
      v9 = v62;
      if ( v62 != 0 )
      {
        v10 = (*(int (__thiscall **)(int))(*(_DWORD *)v62 + 64))(a1: v62);
        v9 = v62;
        if ( v10 < 2 )
          v67 = 0;
      }
      if ( (v64 & 2) == 0 && v9 != 0 )
        GRefCountBaseGC<323>::Release(a1: v9);
      v62 = 0;
      if ( (v64 & 1) == 0 && v63 != 0 )
        GRefCountBaseGC<323>::Release(a1: v63);
      if ( v67 == 0 )
        goto LABEL_108;
    }
    ++v65.lpImageName;
    GASEnvironment::IsVerboseAction(
      this: (__vc_attributes::idl_moduleAttribute *)v3,
      a2: v36,
      a3: v39,
      a4: v42,
      a5: (const char *)v45,
      a6: v46,
      a7: v47,
      a8: v48,
      a9: v49[0],
      a10: v50);
    if ( v11 != 0 )
    {
      if ( DWORD1(v66[6].m_pfnProxied) == 0 )
        GFxASCharacter::CreateCharacterHandle(this: v66);
      GASValue::ToFunction(a1: &v.hInstance, a2: v3);
      CDummyMaterialSystem::EndBatch();
      if ( ((int)v.hCursor & 2) == 0 && v.hInstance != nullptr )
        GRefCountBaseGC<323>::Release(a1: v.hInstance);
      v.hInstance = nullptr;
      if ( ((int)v.hCursor & 1) == 0 && v.hIcon != nullptr )
        GRefCountBaseGC<323>::Release(a1: v.hIcon);
    }
    v12 = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *)*((unsigned __int8 *)a2 + 10);
    *(_DWORD *)(v3 + 8) += 16;
    v52[1] = v12;
    v13 = *(_DWORD *)(v3 + 8);
    LOBYTE(v52[0]) = 4;
    if ( v13 >= *(_DWORD *)(v3 + 16) )
      GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(v3 + 8), a2: v37);
    v14 = *(GASValue **)(v3 + 8);
    if ( v14 != nullptr )
      GASValue::GASValue(this: v14, a2: (const struct GASValue *)v52);
    GASValue::~GASValue(this: v52);
    v15 = *(_DWORD *)a2;
    v16 = 1;
    if ( *(_DWORD *)a2 == 0x2000
      || v15 == 0x4000
      || v15 == 0x8000
      || v15 == 0x10000
      || v15 == 0x400000
      || v15 == 0x800000 )
    {
      v22 = (CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> *)*((unsigned __int8 *)a2 + 12);
      *(_DWORD *)(v3 + 8) += 16;
      v23 = *(_DWORD *)(v3 + 8);
      LOBYTE(v51[0]) = 4;
      v51[1] = v22;
      if ( v23 >= *(_DWORD *)(v3 + 16) )
        GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(v3 + 8), a2: v37);
      v24 = *(GASValue **)(v3 + 8);
      if ( v24 != nullptr )
        GASValue::GASValue(this: v24, a2: (const struct GASValue *)v51);
      v19 = (char *)v51;
    }
    else
    {
      if ( v15 != 1024 && v15 != 2048 && v15 != 0x80000 && v15 != 0x100000 )
      {
LABEL_72:
        v25 = *((_BYTE *)a2 + 11);
        *(_DWORD *)(v3 + 8) += 16;
        v26 = (const char *)v25;
        v27 = *(_DWORD *)(v3 + 8);
        LOBYTE(v45) = 4;
        v46 = v26;
        if ( v27 >= *(_DWORD *)(v3 + 16) )
          GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(v3 + 8), a2: v37);
        v28 = *(GASValue **)(v3 + 8);
        if ( v28 != nullptr )
          GASValue::GASValue(this: v28, a2: (const struct GASValue *)&v45);
        GASValue::~GASValue(this: &v45);
        v29 = v16 + 1;
        GAS_Invoke(result: &v65);
        for ( ; v29 != 0; --v29 )
        {
          GASValue::~GASValue(this: *(GASValue **)(v3 + 8));
          *(_DWORD *)(v3 + 8) -= 16;
          if ( *(_DWORD *)(v3 + 8) < *(_DWORD *)(v3 + 12) )
            GASPagedStack<GASValue,32>::PopPage(this: (__vc_attributes::iid_isAttribute *)(v3 + 8), a2: v37);
        }
        GASEnvironment::IsVerboseAction(
          this: (__vc_attributes::idl_moduleAttribute *)v3,
          a2: v37,
          a3: v40,
          a4: v43,
          a5: (const char *)v45,
          a6: v46,
          a7: v47,
          a8: v48,
          a9: v49[0],
          a10: v50);
        if ( v30 != 0 )
        {
          if ( DWORD1(v66[6].m_pfnProxied) == 0 )
            GFxASCharacter::CreateCharacterHandle(this: v66);
          GASValue::ToFunction(a1: &v.hbrBackground, a2: v3);
          CDummyMaterialSystem::EndBatch();
          if ( ((int)v.lpszClassName & 2) == 0 && v.hbrBackground != nullptr )
            GRefCountBaseGC<323>::Release(a1: v.hbrBackground);
          v.hbrBackground = nullptr;
          if ( ((int)v.lpszClassName & 1) == 0 )
          {
            lpszMenuName = v.lpszMenuName;
            goto LABEL_106;
          }
        }
        goto LABEL_108;
      }
      if ( *((_WORD *)a2 + 4) != 0 )
      {
        *(_DWORD *)(v3 + 8) += 16;
        v20 = *(_DWORD *)(v3 + 8);
        v53[0] = 4;
        v54 = -1;
        if ( v20 >= *(_DWORD *)(v3 + 16) )
          GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(v3 + 8), a2: v37);
        v21 = *(GASValue **)(v3 + 8);
        if ( v21 != nullptr )
          GASValue::GASValue(this: v21, a2: (const struct GASValue *)v53);
        v19 = v53;
      }
      else
      {
        *(_DWORD *)(v3 + 8) += 16;
        v17 = *(_DWORD *)(v3 + 8);
        v49[0] = 4;
        v50 = false;
        if ( v17 >= *(_DWORD *)(v3 + 16) )
          GASPagedStack<GASValue,32>::PushPage(this: (__vc_attributes::iid_isAttribute *)(v3 + 8), a2: v37);
        v18 = *(GASValue **)(v3 + 8);
        if ( v18 != nullptr )
          GASValue::GASValue(this: v18, a2: (const struct GASValue *)v49);
        v19 = v49;
      }
    }
    GASValue::~GASValue(this: (GASValue *)v19);
    v16 = 2;
    goto LABEL_72;
  }
  if ( *((_BYTE *)a2 + 12) == 0 )
  {
    ++v65.lpImageName;
    GASEnvironment::IsVerboseAction(
      this: (__vc_attributes::idl_moduleAttribute *)v3,
      a2: v36,
      a3: v39,
      a4: v42,
      a5: (const char *)v45,
      a6: v46,
      a7: v47,
      a8: v48,
      a9: v49[0],
      a10: v50);
    if ( v32 != 0 )
    {
      if ( DWORD1(v66[6].m_pfnProxied) == 0 )
        GFxASCharacter::CreateCharacterHandle(this: v66);
      GASValue::ToFunction(a1: &v59, a2: v3);
      CDummyMaterialSystem::EndBatch();
      if ( (v61 & 2) == 0 && v59 != 0 )
        GRefCountBaseGC<323>::Release(a1: v59);
      v59 = 0;
      if ( (v61 & 1) == 0 && v60 != 0 )
        GRefCountBaseGC<323>::Release(a1: v60);
    }
    GAS_Invoke(result: &v65);
    GASEnvironment::IsVerboseAction(
      this: (__vc_attributes::idl_moduleAttribute *)v3,
      a2: v38,
      a3: v41,
      a4: v44,
      a5: (const char *)v45,
      a6: v46,
      a7: v47,
      a8: v48,
      a9: v49[0],
      a10: v50);
    if ( v33 != 0 )
    {
      if ( DWORD1(v66[6].m_pfnProxied) == 0 )
        GFxASCharacter::CreateCharacterHandle(this: v66);
      GASValue::ToFunction(a1: v56, a2: v3);
      CDummyMaterialSystem::EndBatch();
      if ( (v57 & 2) == 0 && v56[0] != 0 )
        GRefCountBaseGC<323>::Release(a1: v56[0]);
      v56[0] = 0;
      if ( (v57 & 1) == 0 )
      {
        lpszMenuName = (const wchar_t *)v56[1];
LABEL_106:
        if ( lpszMenuName != nullptr )
          GRefCountBaseGC<323>::Release(a1: lpszMenuName);
      }
    }
  }
LABEL_108:
  v34 = v65.lpImageName != nullptr;
  v8 = (*(_DWORD *)(*(_DWORD *)&v65.fUnicode + 8))-- == 1;
  if ( v8 )
    GASStringNode::ReleaseNode();
  GASValue::~GASValue(this: (GASValue *)&v65);
  if ( v58 != nullptr )
    GRefCountNTSImpl::Release(this: v58);
  GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v66);
  return v34;
}

//------------------------------------------------------------------------------
// Address: 0x10087F70
// Name: public: virtual bool GFxASCharacter::DeleteMember(class GASStringContext __near *,class GASString const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxASCharacter::DeleteMember(
        _DWORD *this,
        _IMAGE_SYMBOL_EX *result,
        CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *a3)
{
  _IMAGE_SYMBOL_EX *v3; // ebx
  int v5; // eax
  bool v6; // zf
  CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *StandardMemberConstant; // eax
  CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *v8; // edi
  int v10; // eax
  int v11; // esi

  v3 = (_IMAGE_SYMBOL_EX *)a3;
  if ( (*(_DWORD *)(LODWORD(a3->m_pfnProxied) + 12) & 0x20000000) == 0 )
  {
    if ( GASString::GetLength(this: (GASString *)a3) == 0 )
      goto LABEL_14;
    LOWORD(v5) = GASString::GetCharAt();
    if ( v5 != 95 )
      goto LABEL_14;
    GASString::ToLower(a1: v3, a2: &a3);
    if ( (HIDWORD(a3->m_pfnProxied) & 0x10000000) == 0 )
    {
      v6 = DWORD2(a3->m_pfnProxied)-- == 1;
      if ( v6 )
        GASStringNode::ReleaseNode();
      goto LABEL_14;
    }
    v6 = DWORD2(a3->m_pfnProxied)-- == 1;
    if ( v6 )
      GASStringNode::ReleaseNode();
  }
  StandardMemberConstant = GFxASCharacter::GetStandardMemberConstant(this: this - 30, result: v3);
  v8 = StandardMemberConstant;
  if ( StandardMemberConstant != (CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *)-1
    && (int)StandardMemberConstant <= 31
    && ((*(int (__thiscall **)(_DWORD *))(*(this - 30) + 280))(a1: this - 30) & (1 << (char)StandardMemberConstant)) != 0 )
  {
    if ( v8 == (CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *)31 )
    {
      *(this + 10) &= 0xFFFFF9FF;
      return 1;
    }
    return 0;
  }
LABEL_14:
  v10 = (*(int (__thiscall **)(_DWORD *))(*(this - 30) + 260))(a1: this - 30);
  v11 = v10;
  if ( v10 != 0 )
  {
    *(_DWORD *)(v10 + 8) = (*(_DWORD *)(v10 + 8) + 1) & 0x8FFFFFFF;
    if ( (*(unsigned __int8 (__thiscall **)(int, _IMAGE_SYMBOL_EX *, _IMAGE_SYMBOL_EX *))(*(_DWORD *)(v10 + 16) + 24))(
           a1: v10 + 16,
           a2: result,
           a3: v3) != 0 )
    {
      GRefCountBaseGC<323>::Release(a1: v11);
      return 1;
    }
    GRefCountBaseGC<323>::Release(a1: v11);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10088080
// Name: public: virtual bool GFxASCharacter::SetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxASCharacter::SetMember(
        CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *this,
        struct GASEnvironment *a2,
        _IMAGE_SYMBOL_EX *name,
        tagWNDCLASSW *val,
        const struct GASPropFlags *flags)
{
  GASValue *v6; // edi
  int v7; // eax
  bool v8; // zf
  GFxCharacter *v9; // ebx
  CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *StandardMemberConstant; // eax
  int v11; // edx
  tagPOLYTEXTW *v13; // eax
  unsigned __int8 v14; // al
  void (__thiscall *v15)(CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *, struct GFxCharacter *); // edx
  CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *v16; // ecx
  GFxMovieRoot *v17; // eax
  tagPOLYTEXTW *v18; // eax
  unsigned __int8 v19; // al
  char v20; // cl
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v21; // eax
  int v22; // eax
  struct GASEnvironment *v23; // eax
  GViewport *v24; // ecx
  GViewport *v25; // ecx
  char v26; // al
  GViewport *v27; // ecx
  char v28; // al
  char v29; // al
  long double v30; // st7
  struct GASEnvironment *v31; // eax
  GViewport *v32; // ecx
  GViewport *v33; // ecx
  char v34; // al
  GViewport *v35; // ecx
  char v36; // al
  char v37; // al
  struct GASEnvironment *v38; // eax
  struct GASEnvironment *v39; // eax
  GViewport *v40; // ecx
  GViewport *v41; // ecx
  char v42; // al
  GViewport *v43; // ecx
  char v44; // al
  char v45; // al
  struct GASObject *v46; // eax
  const CUtlDict<int,unsigned short> *v47; // ecx
  int v48; // edi
  struct GASEnvironment *v49; // eax
  GViewport *v50; // ecx
  char v51; // al
  long double v52; // st7
  double *v53; // eax
  struct GASEnvironment *v54; // eax
  unsigned __int16 v55; // ax
  void (__thiscall *v56)(CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *, _DWORD); // edx
  int m_pfnProxied; // ebx
  struct GASObject *v58; // eax
  int v59; // eax
  struct GFxCharacter *fov_4; // [esp+10h] [ebp-1B8h]
  int v61; // [esp+14h] [ebp-1B4h]
  struct GASObject *v62; // [esp+30h] [ebp-198h]
  int n; // [esp+34h] [ebp-194h]
  float na; // [esp+34h] [ebp-194h]
  float nb; // [esp+34h] [ebp-194h]
  float nc; // [esp+34h] [ebp-194h]
  float nd; // [esp+34h] [ebp-194h]
  float ne; // [esp+34h] [ebp-194h]
  GASValue *noAdv; // [esp+38h] [ebp-190h] BYREF
  long double rval; // [esp+3Ch] [ebp-18Ch]
  GMatrix3D v71; // [esp+44h] [ebp-184h] BYREF
  GMatrix3D v72; // [esp+84h] [ebp-144h] BYREF
  GMatrix3D v73; // [esp+C4h] [ebp-104h]
  GMatrix3D v74; // [esp+104h] [ebp-C4h] BYREF
  GMatrix3D v75; // [esp+144h] [ebp-84h] BYREF
  GMatrix3D v76; // [esp+184h] [ebp-44h] BYREF

  v6 = (GASValue *)val;
  if ( (*(_DWORD *)(name->N.Name.Short + 12) & 0x20000000) == 0 )
  {
    if ( GASString::GetLength(this: (GASString *)name) == 0 )
      goto LABEL_38;
    LOWORD(v7) = GASString::GetCharAt();
    if ( v7 != 95 )
      goto LABEL_38;
    GASString::ToLower(a1: name, a2: &noAdv);
    if ( ((int)noAdv[3] & 0x10000000) == 0 )
    {
      v8 = (*((_DWORD *)noAdv + 2))-- == 1;
      if ( v8 )
        GASStringNode::ReleaseNode();
      goto LABEL_38;
    }
    v8 = (*((_DWORD *)noAdv + 2))-- == 1;
    if ( v8 )
      GASStringNode::ReleaseNode();
  }
  v9 = (GFxCharacter *)(this - 5);
  StandardMemberConstant = GFxASCharacter::GetStandardMemberConstant(this: this - 5, result: name);
  v11 = *((_DWORD *)this - 30);
  noAdv = (GASValue *)StandardMemberConstant;
  if ( (*(unsigned __int8 (__thiscall **)(char *, CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, tagWNDCLASSW *, _DWORD))(v11 + 284))(
         a1: (char *)this - 120,
         a2: StandardMemberConstant,
         a3: val,
         a4: 0) != 0 )
    return true;
  switch ( (unsigned int)noAdv )
  {
    case 'W':
      if ( *(_BYTE *)(*(_DWORD *)((*(int (__thiscall **)(char *))(*(_DWORD *)v9 + 112))(a1: (char *)this - 120) + 120)
                    + 684) == 1 )
      {
        v13 = (tagPOLYTEXTW *)(*(int (__thiscall **)(char *))(*(_DWORD *)v9 + 112))(a1: (char *)this - 120);
        v14 = (unsigned __int8)GASValue::ToBool(result: v13);
        GFxCharacter::SetTopmostLevelFlag(this: this - 5, v: v14);
        v15 = *(void (__thiscall **)(CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *, struct GFxCharacter *))(*(_DWORD *)v9 + 84);
        fov_4 = (struct GFxCharacter *)(this - 5);
        v16 = this - 5;
        if ( (*((_BYTE *)this - 2) & 2) != 0 )
        {
          v15(a1: v16, a2: fov_4);
          GFxMovieRoot::AddTopmostLevelCharacter();
        }
        else
        {
          v17 = (GFxMovieRoot *)((int (__thiscall *)(CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *))v15)(a1: v16);
          GFxMovieRoot::RemoveTopmostLevelCharacter(this: v17, a2: fov_4);
        }
      }
      break;
    case 'X':
      if ( *(_BYTE *)(*(_DWORD *)((*(int (__thiscall **)(char *))(*(_DWORD *)v9 + 112))(a1: (char *)this - 120) + 120)
                    + 684) == 1 )
      {
        v18 = (tagPOLYTEXTW *)(*(int (__thiscall **)(char *))(*(_DWORD *)v9 + 112))(a1: (char *)this - 120);
        v19 = (unsigned __int8)GASValue::ToBool(result: v18);
        v20 = (*((_DWORD *)this + 10) & 4) != 0;
        LOBYTE(noAdv) = v19;
        if ( v19 != v20 )
        {
          GFxASCharacter::SetNoAdvanceLocalFlag(
            this: (CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(this - 5),
            v: (const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)noAdv);
          v21 = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)(*(int (__thiscall **)(char *))(*(_DWORD *)v9 + 84))(a1: (char *)this - 120);
          GFxASCharacter::ModifyOptimizedPlayList(this: (CMatQueuedMesh **)this - 30, result: v21);
          v22 = *((_DWORD *)this - 22);
          if ( v22 != 0 && (*(_DWORD *)(v22 + 160) & 4) == 0 )
            (*(void (__thiscall **)(char *))(*(_DWORD *)v9 + 300))(a1: (char *)this - 120);
        }
      }
      break;
    case 'Y':
      if ( *(_BYTE *)(*(_DWORD *)((*(int (__thiscall **)(char *))(*(_DWORD *)v9 + 112))(a1: (char *)this - 120) + 120)
                    + 684) == 1
        && LOBYTE(GASValue::IsUndefined().usPreferredNode) == 0 )
      {
        v54 = (struct GASEnvironment *)(*(int (__thiscall **)(char *))(*(_DWORD *)v9 + 112))(a1: (char *)this - 120);
        v55 = GASValue::ToUInt32(this: (GASValue *)val, a2: v54);
        v56 = *(void (__thiscall **)(CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *, _DWORD))(*(_DWORD *)v9 + 304);
        *((_WORD *)this + 23) = v55;
        v56(a1: this - 5, a2: v55);
      }
      break;
    case 'l':
      if ( *(_BYTE *)(*(_DWORD *)((*(int (__thiscall **)(char *))(*(_DWORD *)v9 + 112))(a1: (char *)this - 120) + 120)
                    + 684) == 1 )
      {
        v31 = (struct GASEnvironment *)(*(int (__thiscall **)(char *))(*(_DWORD *)v9 + 112))(a1: (char *)this - 120);
        rval = GASValue::ToNumber(this: (GASValue *)val, a2: v31);
        if ( LOBYTE(GASValue::IsUndefined().usPreferredNode) == 0 )
        {
          GASNumberUtil::IsNaN(v: v32);
          if ( v34 == 0 )
          {
            GASNumberUtil::IsNEGATIVE_INFINITY(v: v33);
            if ( v36 != 0 || (GASNumberUtil::IsPOSITIVE_INFINITY(v: v35), v37 != 0) )
              rval = 0.0;
            GFxASCharacter::EnsureGeomDataCreated(
              this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this
            - 5);
            GFxCharacter::CreateMatrix3D(
              this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)this
            - 5,
              pmat: 0);
            v76 = *(GMatrix3D *)*((_DWORD *)this - 7);
            *(long double *)(*((_DWORD *)this + 8) + 56) = rval;
            v76.M_[3][2] = *(double *)(*((_DWORD *)this + 8) + 56);
            if ( (unsigned __int8)GMatrix3D::IsValid(this: (CBitVecT<CVarBitVecBase<unsigned short> > *)&v76, a2: v61) == 0 )
              goto LABEL_37;
            goto LABEL_36;
          }
        }
      }
      break;
    case 'm':
      if ( *(_BYTE *)(*(_DWORD *)((*(int (__thiscall **)(char *))(*(_DWORD *)v9 + 112))(a1: (char *)this - 120) + 120)
                    + 684) == 1 )
      {
        v39 = (struct GASEnvironment *)(*(int (__thiscall **)(char *))(*(_DWORD *)v9 + 112))(a1: (char *)this - 120);
        rval = GASValue::ToNumber(this: (GASValue *)val, a2: v39);
        if ( LOBYTE(GASValue::IsUndefined().usPreferredNode) == 0 )
        {
          GASNumberUtil::IsNaN(v: v40);
          if ( v42 == 0 )
          {
            GASNumberUtil::IsNEGATIVE_INFINITY(v: v41);
            if ( v44 == 0 )
            {
              GASNumberUtil::IsPOSITIVE_INFINITY(v: v43);
              if ( v45 == 0 )
              {
                GFxASCharacter::EnsureGeomDataCreated(
                  this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this
                - 5);
                GFxCharacter::CreateMatrix3D(
                  this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)this
                - 5,
                  pmat: 0);
                v74 = *(GMatrix3D *)*((_DWORD *)this - 7);
                GMatrix3D::SetIdentity(this: &v76);
                GMatrix3D::SetIdentity(this: &v76);
                v76.M_[0][0] = 1.0;
                v76.M_[1][1] = 1.0;
                v75 = v74;
                *(float *)&noAdv = rval;
                v72 = v74;
                v76.M_[2][2] = *(float *)&noAdv / 100.0;
                GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&v75);
                *(long double *)(*((_DWORD *)this + 8) + 64) = rval;
                if ( (unsigned __int8)GMatrix3D::IsValid(
                                        this: (CBitVecT<CVarBitVecBase<unsigned short> > *)&v75,
                                        a2: v61) != 0 )
                  GFxCharacter::SetMatrix3D(this: v9, a2: &v75);
                goto LABEL_37;
              }
            }
          }
        }
      }
      break;
    case 'n':
    case 'o':
      if ( *(_BYTE *)(*(_DWORD *)((*(int (__thiscall **)(char *))(*(_DWORD *)v9 + 112))(a1: (char *)this - 120) + 120)
                    + 684) == 1 )
      {
        v49 = (struct GASEnvironment *)(*(int (__thiscall **)(char *))(*(_DWORD *)v9 + 112))(a1: (char *)this - 120);
        rval = GASValue::ToNumber(this: (GASValue *)val, a2: v49);
        if ( LOBYTE(GASValue::IsUndefined().usPreferredNode) == 0 )
        {
          GASNumberUtil::IsNaN(v: v50);
          if ( v51 == 0 )
          {
            GFxASCharacter::EnsureGeomDataCreated(
              this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this
            - 5);
            v52 = fmod(rval, 360.0);
            rval = v52;
            if ( v52 <= 180.0 )
            {
              if ( v52 < -180.0 )
                rval = v52 + 360.0;
            }
            else
            {
              rval = v52 - 360.0;
            }
            GMatrix3D::SetIdentity(this: &v71);
            GMatrix3D::SetIdentity(this: &v72);
            GMatrix3D::SetIdentity(this: &v75);
            GMatrix3D::SetIdentity(this: &v74);
            GFxCharacter::CreateMatrix3D(
              this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)this
            - 5,
              pmat: 0);
            v53 = *((double **)this + 8);
            v72.M_[3][2] = v53[7];
            na = v53[8];
            v75.M_[2][2] = na / 100.0;
            if ( noAdv == (GASValue *)110 )
            {
              nb = rval * 3.141592653589793 / 180.0;
              GMatrix3D::RotateX(this: &v71, a2: nb);
              nc = *(double *)(*((_DWORD *)this + 8) + 80) * 3.141592653589793 / 180.0;
              GMatrix3D::RotateY(this: &v74, a2: nc);
              *(long double *)(*((_DWORD *)this + 8) + 72) = rval;
            }
            else
            {
              nd = v53[9] * 3.141592653589793 / 180.0;
              GMatrix3D::RotateX(this: &v71, a2: nd);
              ne = rval * 3.141592653589793 / 180.0;
              GMatrix3D::RotateY(this: &v74, a2: ne);
              *(long double *)(*((_DWORD *)this + 8) + 80) = rval;
            }
            v76 = v75;
            v73 = v75;
            GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&v76);
            v73 = v76;
            GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&v76);
            v73 = v76;
            GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&v76);
            if ( (unsigned __int8)GMatrix3D::IsValid(this: (CBitVecT<CVarBitVecBase<unsigned short> > *)&v76, a2: v61) != 0 )
LABEL_36:
              GFxCharacter::SetMatrix3D(this: v9, a2: &v76);
            goto LABEL_37;
          }
        }
      }
      break;
    case 'p':
      if ( *(_BYTE *)(*(_DWORD *)((*(int (__thiscall **)(char *))(*(_DWORD *)v9 + 112))(a1: (char *)this - 120) + 120)
                    + 684) == 1 )
      {
        v46 = GASValue::ToObject(this: (GASValue *)val, a2);
        v62 = v46;
        if ( v46 != nullptr )
        {
          if ( ((int (__thiscall *)(struct GASObject *))v46[2].pNode[1].pNext)(a1: &v46[2]) == 7 )
          {
            GMatrix3D::SetIdentity(this: &v75);
            v48 = 0;
            n = v62[7].sequence;
            if ( n > 0 )
            {
              do
              {
                noAdv = *((GASValue **)&v62[7].pNode->pNext + v48);
                if ( *(float *)&noAdv != 0.0 && LOBYTE(GASValue::IsNumber().usPreferredNode) != 0 )
                  v75.M_[0][v48] = GASValue::ToNumber(this: noAdv, a2);
                ++v48;
              }
              while ( v48 < n );
            }
            GFxASCharacter::EnsureGeomDataCreated(
              this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this
            - 5);
            GFxCharacter::CreateMatrix3D(
              this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)this
            - 5,
              pmat: 0);
            if ( (unsigned __int8)GMatrix3D::IsValid(this: (CBitVecT<CVarBitVecBase<unsigned short> > *)&v75, a2: v61) != 0 )
              GFxCharacter::SetMatrix3D(this: (GFxCharacter *)(this - 5), a2: &v75);
LABEL_37:
            v6 = (GASValue *)val;
          }
        }
        else if ( *((_DWORD *)this - 7) != 0 )
        {
          GNewOverrideBase<65>::operator delete(p: v47, pa: *((void **)this - 7));
          *((_DWORD *)this - 7) = 0;
          GFxASCharacter::EnsureGeomDataCreated(
            this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this
          - 5);
        }
      }
      break;
    case 'q':
      if ( *(_BYTE *)(*(_DWORD *)((*(int (__thiscall **)(char *))(*(_DWORD *)v9 + 112))(a1: (char *)this - 120) + 120)
                    + 684) == 1 )
      {
        v23 = (struct GASEnvironment *)(*(int (__thiscall **)(char *))(*(_DWORD *)v9 + 112))(a1: (char *)this - 120);
        rval = GASValue::ToNumber(this: (GASValue *)val, a2: v23);
        if ( LOBYTE(GASValue::IsUndefined().usPreferredNode) == 0 )
        {
          GASNumberUtil::IsNaN(v: v24);
          if ( v26 == 0 )
          {
            GASNumberUtil::IsNEGATIVE_INFINITY(v: v25);
            if ( v28 != 0 || (GASNumberUtil::IsPOSITIVE_INFINITY(v: v27), v29 != 0) )
              v30 = 0.0;
            else
              v30 = rval;
            *(float *)&noAdv = v30;
            GFxCharacter::SetPerspectiveFOV(this: (GFxCharacter *)(this - 5), fov: *(float *)&noAdv);
          }
        }
      }
      break;
    default:
      break;
  }
LABEL_38:
  v38 = a2;
  if ( *((_BYTE *)a2 + 124) <= 6u )
  {
    if ( *(_DWORD *)(name->N.Name.Short + 4) == 0 )
    {
      GASStringNode::ResolveLowercase_Impl();
      v38 = a2;
    }
    if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v38 + 30) + 320) + 4) != *(_DWORD *)(name->N.Name.Short + 4)
      || *(_BYTE *)v6 == 10 )
    {
      goto LABEL_81;
    }
  }
  else if ( name->N.Name.Short != *(_DWORD *)(*((_DWORD *)a2 + 30) + 320) || *(_BYTE *)v6 == 10 )
  {
    goto LABEL_81;
  }
  m_pfnProxied = this->m_pfnProxied;
  v58 = GASValue::ToObject(this: v6, a2: nullptr);
  (*(void (__thiscall **)(CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *, char *, struct GASObject *))(m_pfnProxied + 52))(
    a1: this,
    a2: (char *)a2 + 120,
    a3: v58);
LABEL_81:
  v59 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 30) + 260))(a1: (char *)this - 120);
  return v59 != 0
      && (*(bool (__thiscall **)(int, struct GASEnvironment *, _IMAGE_SYMBOL_EX *, GASValue *, const struct GASPropFlags *))(*(_DWORD *)(v59 + 16) + 12))(
           a1: v59 + 16,
           a2,
           a3: name,
           a4: v6,
           a5: flags);
}

//------------------------------------------------------------------------------
// Address: 0x10088A60
// Name: public: virtual bool GFxASCharacter::HasMember(class GASStringContext __near *,class GASString const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::HasMember(
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        _IMAGE_SYMBOL_EX *psc,
        CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *result,
        int inclPrototypes)
{
  _IMAGE_SYMBOL_EX *v4; // ebx
  int v6; // eax
  bool v7; // zf
  CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *StandardMemberConstant; // eax
  int v9; // eax
  int v10; // esi

  v4 = (_IMAGE_SYMBOL_EX *)result;
  if ( (*(_DWORD *)(LODWORD(result->m_pfnProxied) + 12) & 0x20000000) == 0 )
  {
    if ( GASString::GetLength(this: (GASString *)result) == 0 )
      goto LABEL_13;
    LOWORD(v6) = GASString::GetCharAt();
    if ( v6 != 95 )
      goto LABEL_13;
    GASString::ToLower(a1: v4, a2: &result);
    if ( (HIDWORD(result->m_pfnProxied) & 0x10000000) == 0 )
    {
      v7 = DWORD2(result->m_pfnProxied)-- == 1;
      if ( v7 )
        GASStringNode::ReleaseNode();
      goto LABEL_13;
    }
    v7 = DWORD2(result->m_pfnProxied)-- == 1;
    if ( v7 )
      GASStringNode::ReleaseNode();
  }
  StandardMemberConstant = GFxASCharacter::GetStandardMemberConstant(this: (char *)this - 120, result: v4);
  if ( StandardMemberConstant == (CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *)-1
    || (int)StandardMemberConstant > 31
    || ((*(int (__thiscall **)(char *))(*((_DWORD *)this - 30) + 280))(a1: (char *)this - 120)
      & (1 << (char)StandardMemberConstant)) == 0 )
  {
LABEL_13:
    v9 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 30) + 260))(a1: (char *)this - 120);
    v10 = v9;
    if ( v9 != 0 )
    {
      *(_DWORD *)(v9 + 8) = (*(_DWORD *)(v9 + 8) + 1) & 0x8FFFFFFF;
      (*(void (__thiscall **)(int, _IMAGE_SYMBOL_EX *, _IMAGE_SYMBOL_EX *, int))(*(_DWORD *)(v9 + 16) + 36))(
        a1: v9 + 16,
        a2: psc,
        a3: v4,
        a4: inclPrototypes);
      GRefCountBaseGC<323>::Release(a1: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088C50
// Name: public: static void GFxASCharacter::InitStandardMembers(class GASGlobalContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::InitStandardMembers(CMatRenderContextBase *pcontext, __int128 pstrManager)
{
  BaseSlot *v2; // edi
  _DWORD *v3; // eax
  CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > **v4; // esi
  BaseSlot::CVAR_TYPE_WANTED v6; // [esp+0h] [ebp-18h]
  int v7[2]; // [esp+8h] [ebp-10h] BYREF
  tagPOINTFX pstrManagera; // [esp+10h] [ebp-8h] BYREF

  v2 = (BaseSlot *)(pstrManager + 688);
  pstrManagera.x = *(_FIXED *)(pstrManager + 636);
  v3 = *(_DWORD **)(pstrManager + 688);
  if ( v3 == nullptr || *v3 < 0x8Fu )
    GHashSetBase<GHashNode<GASString,char,GASStringHashFunctor>,GHashNode<GASString,char,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,char,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,char,GASStringHashFunctor>,GHashNode<GASString,char,GASStringHashFunctor>::NodeHashF>>::setRawCapacity(
      this: (BaseSlot *)(pstrManager + 688),
      pheapAddr: (IScaleformUI *)(pstrManager + 688),
      newSize: (GFxFunctionHandler::Params *)0x8F,
      newHash: v6);
  v4 = &GFxASCharacter::MemberTable;
  if ( GFxASCharacter::MemberTable != nullptr )
  {
    v7[0] = (int)&pstrManagera.y;
    v7[1] = (int)&pstrManager + 3;
    do
    {
      pstrManagera.y = (_FIXED)GASStringManager::CreateConstStringNode(
                                 this: *(GASStringManager **)&pstrManagera.x,
                                 result: *v4,
                                 a3: strlen((const char *)*v4),
                                 a4: (*((_BYTE *)v4 + 8) != 0 ? 0x10000000 : 0) | 0x20000000);
      ++*(_DWORD *)(*(_DWORD *)&pstrManagera.y + 8);
      BYTE3(pstrManager) = *((_BYTE *)v4 + 4);
      GHashSetBase<GHashNode<GASString,char,GASStringHashFunctor>,GHashNode<GASString,char,GASStringHashFunctor>::NodeHashF,GHashNode<GASString,char,GASStringHashFunctor>::NodeAltHashF,GAllocatorLH<GASString,323>,GHashsetNodeEntry<GHashNode<GASString,char,GASStringHashFunctor>,GHashNode<GASString,char,GASStringHashFunctor>::NodeHashF>>::add<GHashNode<GASString,char,GASStringHashFunctor>::NodeRef>(
        this: v2,
        pheapAddr: (IScaleformUI *)v2,
        a3: (int)v7,
        a4: *(_DWORD *)(*(_DWORD *)&pstrManagera.y + 12));
      if ( (*(_DWORD *)(*(_DWORD *)&pstrManagera.y + 8))-- == 1 )
        GASStringNode::ReleaseNode();
      v4 += 3;
    }
    while ( *v4 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088D10
// Name: public: virtual bool GFxASCharacter::SetStandardMember(enum GFxASCharacter::StandardMember,class GASValue const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxASCharacter::SetStandardMember(
        CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *this,
        signed int member,
        tagWNDCLASSW *val,
        bool opcodeFlag)
{
  struct GASEnvironment *v6; // esi
  GViewport *v7; // ecx
  GViewport *v8; // ecx
  char v9; // al
  GViewport *v10; // ecx
  char v11; // al
  char v12; // al
  char v13; // al
  GViewport *v14; // ecx
  GViewport *v15; // ecx
  char v16; // al
  GViewport *v17; // ecx
  char v18; // al
  char v19; // al
  char v20; // al
  GViewport *v21; // ecx
  GViewport *v22; // ecx
  char v23; // al
  GViewport *v24; // ecx
  char v25; // al
  char v26; // al
  float *v27; // eax
  long double XScale; // st7
  int v29; // ecx
  long double v30; // st6
  int v31; // esi
  double v32; // st7
  char v33; // al
  GViewport *v34; // ecx
  GViewport *v35; // ecx
  char v36; // al
  GViewport *v37; // ecx
  char v38; // al
  char v39; // al
  float *v40; // eax
  long double YScale; // st7
  int v42; // ecx
  long double v43; // st6
  int v44; // esi
  double v45; // st7
  VertexDesc_t *v46; // ecx
  GViewport *v47; // ecx
  char v48; // al
  long double v49; // st7
  float *v50; // eax
  double v51; // st7
  int v52; // esi
  double v53; // st7
  int v54; // ecx
  double v55; // st7
  VertexDesc_t *v56; // ecx
  char v57; // al
  GViewport *v58; // ecx
  GViewport *v59; // ecx
  char v60; // al
  GViewport *v61; // ecx
  char v62; // al
  char v63; // al
  int v64; // eax
  float *v65; // eax
  double v66; // st7
  long double v67; // st7
  long double v68; // st7
  int v69; // eax
  int v70; // esi
  double Rotation; // st7
  double v72; // st7
  char v73; // al
  GViewport *v74; // ecx
  GViewport *v75; // ecx
  char v76; // al
  GViewport *v77; // ecx
  char v78; // al
  char v79; // al
  int v80; // eax
  int v81; // eax
  double v82; // st7
  long double v83; // st7
  long double v84; // st7
  int v85; // eax
  int v86; // esi
  double v87; // st7
  double v88; // st7
  VertexDesc_t *v89; // ecx
  GViewport *v90; // ecx
  char v91; // al
  unsigned __int8 v92; // al
  int v93; // esi
  int v94; // eax
  int v96; // eax
  unsigned __int8 v97; // al
  unsigned __int8 v98; // al
  int v99; // eax
  tagPOLYTEXTW *v100; // eax
  unsigned __int8 v101; // al
  struct GASEnvironment *v102; // eax
  tagPOLYTEXTW *v103; // eax
  unsigned __int8 v104; // al
  tagPOLYTEXTW *v105; // eax
  unsigned __int8 v106; // al
  vc_attributes::InvalidCheckAttribute *Prototype; // eax
  int v108; // edi
  int v109; // eax
  int v110; // eax
  GASValue *v111; // ecx
  IStream *v112; // edi
  vc_attributes::InvalidCheckAttribute *v113; // eax
  float X; // [esp+Ch] [ebp-B0h] BYREF
  long double X_4; // [esp+10h] [ebp-ACh]
  __int128 v116; // [esp+18h] [ebp-A4h] BYREF
  char v117[16]; // [esp+34h] [ebp-88h] BYREF
  int v118; // [esp+44h] [ebp-78h] BYREF
  bool hasfilters; // [esp+4Bh] [ebp-71h]
  _LocaleUpdate *newfilters; // [esp+4Ch] [ebp-70h] BYREF
  long double aval; // [esp+50h] [ebp-6Ch]
  long double i; // [esp+58h] [ebp-64h] BYREF
  long double oldWidth; // [esp+60h] [ebp-5Ch] BYREF
  struct GRenderer::Cxform v124; // [esp+68h] [ebp-54h] BYREF
  GMatrix2D v125; // [esp+88h] [ebp-34h] BYREF
  GMatrix2D v126; // [esp+A0h] [ebp-1Ch] BYREF

  HIDWORD(oldWidth) = member;
  if ( opcodeFlag && (unsigned int)member >= 0x16 )
  {
    GFxLogBase<GFxCharacter>::LogScriptError(
      a1: (int)&this->m_pfnProxied + 12,
      a2: (int)"Invalid SetProperty request, property number %d\n",
      member);
    return 0;
  }
  if ( member == -1
    || member > 31
    || ((*(int (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 280))(a1: this)
      & (1 << member)) == 0 )
  {
    return 0;
  }
  v6 = (struct GASEnvironment *)(*(int (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 112))(a1: this);
  switch ( HIDWORD(oldWidth) )
  {
    case 0:
      oldWidth = GASValue::ToNumber(this: (GASValue *)val, a2: v6);
      if ( LOBYTE(GASValue::IsUndefined().usPreferredNode) == 0 )
      {
        X_4 = oldWidth;
        GASNumberUtil::IsNaN(v: v7);
        if ( v9 == 0 )
        {
          X_4 = oldWidth;
          GASNumberUtil::IsNEGATIVE_INFINITY(v: v8);
          if ( v11 != 0 || (X_4 = oldWidth, GASNumberUtil::IsPOSITIVE_INFINITY(v: v10), v12 != 0) )
            oldWidth = 0.0;
          (*(void (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, _DWORD))(LODWORD(this->m_pfnProxied) + 32))(
            a1: this,
            a2: 0);
          v126.M_[0][0] = *((float *)this + 17);
          v126.M_[0][1] = *((float *)this + 18);
          v126.M_[0][2] = *((float *)this + 19);
          v126.M_[1][0] = *((float *)this + 20);
          v126.M_[1][1] = *((float *)this + 21);
          v126.M_[1][2] = *((float *)this + 22);
          **((_DWORD **)this + 38) = (int)floor(X: oldWidth * 20.0);
          v126.M_[0][2] = (float)**((int **)this + 38);
          GMatrix2D::IsValid(
            this: (CMaterialDict::MaterialLookup_t *)&v126,
            a2: (const CMaterialDict::MaterialLookup_t *)v116);
          if ( v13 != 0 )
            GFxCharacter::SetMatrix(
              (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)this,
              m: (CMatRenderContextBase *)&v126,
              a3: v116);
        }
      }
      return 1;
    case 1:
      oldWidth = GASValue::ToNumber(this: (GASValue *)val, a2: v6);
      if ( LOBYTE(GASValue::IsUndefined().usPreferredNode) != 0 )
        return 1;
      X_4 = oldWidth;
      GASNumberUtil::IsNaN(v: v14);
      if ( v16 != 0 )
        return 1;
      X_4 = oldWidth;
      GASNumberUtil::IsNEGATIVE_INFINITY(v: v15);
      if ( v18 != 0 || (X_4 = oldWidth, GASNumberUtil::IsPOSITIVE_INFINITY(v: v17), v19 != 0) )
        oldWidth = 0.0;
      (*(void (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, _DWORD))(LODWORD(this->m_pfnProxied) + 32))(
        a1: this,
        a2: 0);
      v126.M_[0][0] = *((float *)this + 17);
      v126.M_[0][1] = *((float *)this + 18);
      v126.M_[0][2] = *((float *)this + 19);
      v126.M_[1][0] = *((float *)this + 20);
      v126.M_[1][1] = *((float *)this + 21);
      v126.M_[1][2] = *((float *)this + 22);
      *(_DWORD *)(*((_DWORD *)this + 38) + 4) = (int)floor(X: oldWidth * 20.0);
      v126.M_[1][2] = (float)*(int *)(*((_DWORD *)this + 38) + 4);
      GMatrix2D::IsValid(
        this: (CMaterialDict::MaterialLookup_t *)&v126,
        a2: (const CMaterialDict::MaterialLookup_t *)v116);
      if ( v20 == 0 )
        return 1;
      GFxCharacter::SetMatrix(
        (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)this,
        m: (CMatRenderContextBase *)&v126,
        a3: v116);
      return 1;
    case 2:
      i = GASValue::ToNumber(this: (GASValue *)val, a2: v6);
      if ( LOBYTE(GASValue::IsUndefined().usPreferredNode) != 0 )
        return 1;
      X_4 = i;
      GASNumberUtil::IsNaN(v: v21);
      if ( v23 != 0 )
        return 1;
      X_4 = i;
      GASNumberUtil::IsNEGATIVE_INFINITY(v: v22);
      if ( v25 != 0 )
        return 1;
      X_4 = i;
      GASNumberUtil::IsPOSITIVE_INFINITY(v: v24);
      if ( v26 != 0 )
        return 1;
      (*(void (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, _DWORD))(LODWORD(this->m_pfnProxied) + 32))(
        a1: this,
        a2: 0);
      v27 = *((float **)this + 38);
      v126.M_[0][0] = v27[8];
      v126.M_[0][1] = v27[9];
      v126.M_[0][2] = v27[10];
      v126.M_[1][0] = v27[11];
      v126.M_[1][1] = v27[12];
      v126.M_[0][2] = *((float *)this + 19);
      v126.M_[1][2] = *((float *)this + 22);
      XScale = GMatrix2D::GetXScale(this: &v126);
      v29 = *((_DWORD *)this + 38);
      aval = XScale;
      v30 = i;
      *(long double *)(v29 + 8) = i;
      if ( 0.0 == XScale || v30 > 1.0e16 )
      {
        i = 0.0;
        aval = 1.0;
      }
      v31 = *((_DWORD *)this + 38);
      oldWidth = *(double *)(v31 + 24) * 3.141592653589793 / 180.0;
      *((float *)&oldWidth + 1) = oldWidth - GMatrix2D::GetRotation(this: &v126);
      *((float *)&X_4 + 1) = *((float *)&oldWidth + 1);
      *((float *)&oldWidth + 1) = *(double *)(v31 + 16) / (GMatrix2D::GetYScale(this: &v126) * 100.0);
      *(float *)&X_4 = *((float *)&oldWidth + 1);
      *((float *)&oldWidth + 1) = i / (100.0 * aval);
      v32 = *((float *)&oldWidth + 1);
      goto LABEL_31;
    case 3:
      i = GASValue::ToNumber(this: (GASValue *)val, a2: v6);
      if ( LOBYTE(GASValue::IsUndefined().usPreferredNode) != 0 )
        return 1;
      X_4 = i;
      GASNumberUtil::IsNaN(v: v34);
      if ( v36 != 0 )
        return 1;
      X_4 = i;
      GASNumberUtil::IsNEGATIVE_INFINITY(v: v35);
      if ( v38 != 0 )
        return 1;
      X_4 = i;
      GASNumberUtil::IsPOSITIVE_INFINITY(v: v37);
      if ( v39 != 0 )
        return 1;
      (*(void (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, _DWORD))(LODWORD(this->m_pfnProxied) + 32))(
        a1: this,
        a2: 0);
      v40 = *((float **)this + 38);
      v126.M_[0][0] = v40[8];
      v126.M_[0][1] = v40[9];
      v126.M_[0][2] = v40[10];
      v126.M_[1][0] = v40[11];
      v126.M_[1][1] = v40[12];
      v126.M_[0][2] = *((float *)this + 19);
      v126.M_[1][2] = *((float *)this + 22);
      YScale = GMatrix2D::GetYScale(this: &v126);
      v42 = *((_DWORD *)this + 38);
      aval = YScale;
      v43 = i;
      *(long double *)(v42 + 16) = i;
      if ( 0.0 == YScale || v43 > 1.0e16 )
      {
        i = 0.0;
        aval = 1.0;
      }
      v44 = *((_DWORD *)this + 38);
      oldWidth = *(double *)(v44 + 24) * 3.141592653589793 / 180.0;
      *((float *)&oldWidth + 1) = oldWidth - GMatrix2D::GetRotation(this: &v126);
      *((float *)&X_4 + 1) = *((float *)&oldWidth + 1);
      *((float *)&oldWidth + 1) = i / (aval * 100.0);
      *(float *)&X_4 = *((float *)&oldWidth + 1);
      v45 = GMatrix2D::GetXScale(this: &v126);
      X = *(float *)&v46;
      *((float *)&oldWidth + 1) = *(double *)(v44 + 8) / (v45 * 100.0);
      v32 = *((float *)&oldWidth + 1);
LABEL_31:
      X = v32;
      GFxASCharacter_MatrixScaleAndRotate2x2(x11: (float *)&v126, sx: X, sy: *(float *)&X_4, x01: *((float *)&X_4 + 1));
      GMatrix2D::IsValid(
        this: (CMaterialDict::MaterialLookup_t *)&v126,
        a2: (const CMaterialDict::MaterialLookup_t *)v116);
      if ( v33 == 0 )
        return 1;
      HIDWORD(X_4) = &v126;
      goto LABEL_33;
    case 4:
    case 5:
    case 0xB:
    case 0xC:
    case 0xE:
    case 0xF:
    case 0x14:
    case 0x15:
    case 0x16:
      v99 = *((_DWORD *)this + 37);
      if ( v99 == 0 )
      {
        GFxASCharacter::CreateCharacterHandle((CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this);
        if ( v99 == 0 )
          v99 = *(_DWORD *)((*(int (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 108))(a1: this)
                          + 120);
      }
      GASEnvironment::LogScriptWarning(
        this: (GASEnvironment *)v6,
        a2: "Attempt to write read-only property %s.%s, ignored\n",
        **(const char ***)(v99 + 8),
        (const char *)*(&GFxASCharacter::MemberTable + 3 * HIDWORD(oldWidth)));
      return 1;
    case 6:
      aval = GASValue::ToNumber(this: (GASValue *)val, a2: v6);
      if ( LOBYTE(GASValue::IsUndefined().usPreferredNode) != 0 )
        return 1;
      X_4 = aval;
      GASNumberUtil::IsNaN(v: v90);
      if ( v91 != 0 )
        return 1;
      v124 = *(struct GRenderer::Cxform *)((char *)this + 36);
      v124.M_[3][0] = aval / 100.0;
      GFxCharacter::SetCxform((GFxCharacter *)this, a2: &v124);
      (*(void (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, _DWORD))(LODWORD(this->m_pfnProxied) + 32))(
        a1: this,
        a2: 0);
      return 1;
    case 7:
      HIDWORD(oldWidth) = LODWORD(this->m_pfnProxied) + 204;
      v92 = (unsigned __int8)GASValue::ToBool(result: (tagPOLYTEXTW *)v6);
      (*(void (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, _DWORD))HIDWORD(oldWidth))(
        a1: this,
        a2: v92);
      return 1;
    case 8:
      aval = GASValue::ToNumber(this: (GASValue *)val, a2: v6);
      if ( LOBYTE(GASValue::IsUndefined().usPreferredNode) != 0 )
        return 1;
      X_4 = aval;
      GASNumberUtil::IsNaN(v: v58);
      if ( v60 != 0 )
        return 1;
      X_4 = aval;
      GASNumberUtil::IsNEGATIVE_INFINITY(v: v59);
      if ( v62 != 0 )
        return 1;
      X_4 = aval;
      GASNumberUtil::IsPOSITIVE_INFINITY(v: v61);
      if ( v63 != 0 )
        aval = 0.0;
      (*(void (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, _DWORD))(LODWORD(this->m_pfnProxied) + 32))(
        a1: this,
        a2: 0);
      v64 = *((_DWORD *)this + 38);
      v126.M_[0][0] = *(float *)(v64 + 32);
      v126.M_[0][1] = *(float *)(v64 + 36);
      v126.M_[0][2] = *(float *)(v64 + 40);
      v126.M_[1][0] = *(float *)(v64 + 44);
      v126.M_[1][1] = *(float *)(v64 + 48);
      v126.M_[0][2] = *((float *)this + 19);
      v126.M_[1][2] = *((float *)this + 22);
      v125.M_[0][0] = v126.M_[0][0];
      v125.M_[0][1] = v126.M_[0][1];
      v125.M_[0][2] = v126.M_[0][2];
      v125.M_[1][0] = v126.M_[1][0];
      v125.M_[1][1] = v126.M_[1][1];
      v125.M_[1][2] = v126.M_[1][2];
      oldWidth = *(double *)(v64 + 24) * 3.141592653589793 / 180.0;
      *((float *)&oldWidth + 1) = oldWidth - GMatrix2D::GetRotation(this: &v126);
      *((float *)&i + 1) = cos(*((float *)&oldWidth + 1));
      *((float *)&oldWidth + 1) = sin(*((float *)&oldWidth + 1));
      v124.M_[1][0] = *((float *)&i + 1);
      v124.M_[1][1] = -*((float *)&oldWidth + 1);
      v124.M_[2][0] = 0.0;
      v124.M_[3][1] = 0.0;
      v124.M_[2][1] = *((float *)&oldWidth + 1);
      v124.M_[3][0] = *((float *)&i + 1);
      GMatrix2D::Append(this: &v125, a2: (const struct GMatrix2D *)v124.M_[1]);
      v65 = (float *)(*(int (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, char *, GMatrix2D *))(LODWORD(this->m_pfnProxied) + 52))(
                       a1: this,
                       a2: (char *)&v116 + 12,
                       a3: &v125);
      *((float *)&oldWidth + 1) = v65[2] - *v65;
      v66 = *((float *)&oldWidth + 1);
      *((float *)&oldWidth + 1) = fabs(*((float *)&oldWidth + 1));
      if ( *((float *)&oldWidth + 1) <= 0.000001 )
      {
        v67 = 0.0;
      }
      else
      {
        *((float *)&oldWidth + 1) = aval * 20.0;
        v67 = *((float *)&oldWidth + 1) / v66;
      }
      aval = v67;
      v68 = GMatrix2D::GetXScale(this: &v126);
      i = v68;
      v69 = *((_DWORD *)this + 38);
      *((float *)&oldWidth + 1) = aval;
      aval = *((float *)&oldWidth + 1) * v68 * 100.0;
      *(long double *)(v69 + 8) = aval;
      if ( 0.0 == v68 )
      {
        aval = 0.0;
        i = 1.0;
      }
      v70 = *((_DWORD *)this + 38);
      oldWidth = *(double *)(v70 + 24) * 3.141592653589793 / 180.0;
      Rotation = GMatrix2D::GetRotation(this: &v126);
      *((float *)&oldWidth + 1) = oldWidth - Rotation;
      *((float *)&X_4 + 1) = *((float *)&oldWidth + 1);
      *((float *)&oldWidth + 1) = fabs(*(double *)(v70 + 16) / (GMatrix2D::GetYScale(this: &v126) * 100.0));
      *(float *)&X_4 = *((float *)&oldWidth + 1);
      *((float *)&oldWidth + 1) = fabs(aval / (100.0 * i));
      v72 = *((float *)&oldWidth + 1);
      goto LABEL_64;
    case 9:
      aval = GASValue::ToNumber(this: (GASValue *)val, a2: v6);
      if ( LOBYTE(GASValue::IsUndefined().usPreferredNode) != 0 )
        return 1;
      X_4 = aval;
      GASNumberUtil::IsNaN(v: v74);
      if ( v76 != 0 )
        return 1;
      X_4 = aval;
      GASNumberUtil::IsNEGATIVE_INFINITY(v: v75);
      if ( v78 != 0 )
        return 1;
      X_4 = aval;
      GASNumberUtil::IsPOSITIVE_INFINITY(v: v77);
      if ( v79 != 0 )
        aval = 0.0;
      (*(void (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, _DWORD))(LODWORD(this->m_pfnProxied) + 32))(
        a1: this,
        a2: 0);
      v80 = *((_DWORD *)this + 38);
      v126.M_[0][0] = *(float *)(v80 + 32);
      v126.M_[0][1] = *(float *)(v80 + 36);
      v126.M_[0][2] = *(float *)(v80 + 40);
      v126.M_[1][0] = *(float *)(v80 + 44);
      v126.M_[1][1] = *(float *)(v80 + 48);
      v126.M_[0][2] = *((float *)this + 19);
      v126.M_[1][2] = *((float *)this + 22);
      v125.M_[0][0] = v126.M_[0][0];
      v125.M_[0][1] = v126.M_[0][1];
      v125.M_[0][2] = v126.M_[0][2];
      v125.M_[1][0] = v126.M_[1][0];
      v125.M_[1][1] = v126.M_[1][1];
      v125.M_[1][2] = v126.M_[1][2];
      oldWidth = *(double *)(v80 + 24) * 3.141592653589793 / 180.0;
      *((float *)&oldWidth + 1) = oldWidth - GMatrix2D::GetRotation(this: &v126);
      *((float *)&i + 1) = cos(*((float *)&oldWidth + 1));
      *((float *)&oldWidth + 1) = sin(*((float *)&oldWidth + 1));
      v124.M_[1][0] = *((float *)&i + 1);
      v124.M_[1][1] = -*((float *)&oldWidth + 1);
      v124.M_[2][0] = 0.0;
      v124.M_[3][1] = 0.0;
      v124.M_[2][1] = *((float *)&oldWidth + 1);
      v124.M_[3][0] = *((float *)&i + 1);
      GMatrix2D::Append(this: &v125, a2: (const struct GMatrix2D *)v124.M_[1]);
      v81 = (*(int (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, char *, GMatrix2D *))(LODWORD(this->m_pfnProxied) + 52))(
              a1: this,
              a2: v117,
              a3: &v125);
      *((float *)&oldWidth + 1) = *(float *)(v81 + 12) - *(float *)(v81 + 4);
      v82 = *((float *)&oldWidth + 1);
      *((float *)&oldWidth + 1) = fabs(*((float *)&oldWidth + 1));
      if ( *((float *)&oldWidth + 1) <= 0.000001 )
      {
        v83 = 0.0;
      }
      else
      {
        *((float *)&oldWidth + 1) = aval * 20.0;
        v83 = *((float *)&oldWidth + 1) / v82;
      }
      aval = v83;
      v84 = GMatrix2D::GetYScale(this: &v126);
      i = v84;
      v85 = *((_DWORD *)this + 38);
      *((float *)&oldWidth + 1) = aval;
      aval = *((float *)&oldWidth + 1) * v84 * 100.0;
      *(long double *)(v85 + 16) = aval;
      if ( 0.0 == v84 )
      {
        aval = 0.0;
        i = 1.0;
      }
      v86 = *((_DWORD *)this + 38);
      oldWidth = *(double *)(v86 + 24) * 3.141592653589793 / 180.0;
      v87 = GMatrix2D::GetRotation(this: &v126);
      *((float *)&oldWidth + 1) = oldWidth - v87;
      *((float *)&X_4 + 1) = *((float *)&oldWidth + 1);
      *((float *)&oldWidth + 1) = fabs(aval / (i * 100.0));
      *(float *)&X_4 = *((float *)&oldWidth + 1);
      v88 = GMatrix2D::GetXScale(this: &v126);
      X = *(float *)&v89;
      *((float *)&oldWidth + 1) = fabs(*(double *)(v86 + 8) / (v88 * 100.0));
      v72 = *((float *)&oldWidth + 1);
LABEL_64:
      X = v72;
      GFxASCharacter_MatrixScaleAndRotate2x2(x11: (float *)&v126, sx: X, sy: *(float *)&X_4, x01: *((float *)&X_4 + 1));
      *(long double *)(*((_DWORD *)this + 38) + 8) = fabs(*(double *)(*((_DWORD *)this + 38) + 8));
      *(long double *)(*((_DWORD *)this + 38) + 16) = fabs(*(double *)(*((_DWORD *)this + 38) + 16));
      GMatrix2D::IsValid(
        this: (CMaterialDict::MaterialLookup_t *)&v126,
        a2: (const CMaterialDict::MaterialLookup_t *)v116);
      if ( v73 == 0 )
        return 1;
      HIDWORD(X_4) = &v126;
      goto LABEL_33;
    case 0xA:
      aval = GASValue::ToNumber(this: (GASValue *)val, a2: v6);
      if ( LOBYTE(GASValue::IsUndefined().usPreferredNode) != 0 )
        return 1;
      X_4 = aval;
      GASNumberUtil::IsNaN(v: v47);
      if ( v48 != 0 )
        return 1;
      (*(void (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, _DWORD))(LODWORD(this->m_pfnProxied) + 32))(
        a1: this,
        a2: 0);
      v49 = fmod(aval, 360.0);
      aval = v49;
      if ( v49 <= 180.0 )
      {
        if ( v49 >= -180.0 )
          goto LABEL_51;
        v49 = v49 + 360.0;
      }
      else
      {
        v49 = v49 - 360.0;
      }
      aval = v49;
LABEL_51:
      *(long double *)(*((_DWORD *)this + 38) + 24) = v49;
      v50 = *((float **)this + 38);
      v126.M_[0][0] = v50[8];
      v126.M_[0][1] = v50[9];
      v126.M_[0][2] = v50[10];
      v126.M_[1][0] = v50[11];
      v126.M_[1][1] = v50[12];
      v126.M_[0][2] = *((float *)this + 19);
      v126.M_[1][2] = *((float *)this + 22);
      v51 = GMatrix2D::GetRotation(this: &v126);
      v52 = *((_DWORD *)this + 38);
      *((float *)&oldWidth + 1) = aval * 3.141592653589793 / 180.0 - v51;
      *((float *)&X_4 + 1) = *((float *)&oldWidth + 1);
      v53 = GMatrix2D::GetYScale(this: &v126);
      LODWORD(X_4) = v54;
      *((float *)&oldWidth + 1) = *(double *)(v52 + 16) / (v53 * 100.0);
      *(float *)&X_4 = *((float *)&oldWidth + 1);
      v55 = GMatrix2D::GetXScale(this: &v126);
      X = *(float *)&v56;
      *((float *)&oldWidth + 1) = *(double *)(v52 + 8) / (v55 * 100.0);
      GFxASCharacter_MatrixScaleAndRotate2x2(
        x11: (float *)&v126,
        sx: *((float *)&oldWidth + 1),
        sy: *(float *)&X_4,
        x01: *((float *)&X_4 + 1));
      GMatrix2D::IsValid(
        this: (CMaterialDict::MaterialLookup_t *)&v126,
        a2: (const CMaterialDict::MaterialLookup_t *)v116);
      if ( v57 == 0 )
        return 1;
      HIDWORD(X_4) = &v126;
LABEL_33:
      GFxCharacter::SetMatrix(
        (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(char const *),CFuncMemPolicyNone> *)this,
        m: (CMatRenderContextBase *)HIDWORD(X_4),
        a3: v116);
      return 1;
    case 0xD:
      GASValue::ToStringImpl(a1: val, a2: &v118, a3: v6, a4: -1, a5: 0);
      (*(void (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, int *))(LODWORD(this->m_pfnProxied) + 40))(
        a1: this,
        a2: &v118);
      v94 = v118;
      goto LABEL_88;
    case 0x10:
    case 0x12:
    case 0x13:
      return 1;
    case 0x11:
      if ( LOBYTE(GASValue::IsUndefined().usPreferredNode) != 0 )
      {
        *((_DWORD *)this + 40) &= 0xFFFFFE7F;
      }
      else
      {
        v103 = (tagPOLYTEXTW *)(*(int (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 112))(a1: this);
        v104 = (unsigned __int8)GASValue::ToBool(result: v103);
        GFxASCharacter::SetFocusRectFlag(
          (CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this,
          v: (const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v104);
      }
      GFxCharacter::SetDirtyFlag(this);
      return 1;
    case 0x17:
      if ( LOBYTE(val->style) != 5 )
      {
        v96 = (int)GASValue::ToNumber(this: (GASValue *)val, a2: v6);
        if ( v96 < 14 )
        {
          if ( v96 <= 1 )
            v96 = 1;
          (*(void (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, int))(LODWORD(this->m_pfnProxied) + 36))(
            a1: this,
            a2: v96);
        }
        else
        {
          (*(void (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, int))(LODWORD(this->m_pfnProxied) + 36))(
            a1: this,
            a2: 14);
        }
        return 1;
      }
      GASValue::ToStringImpl(a1: val, a2: (char *)&oldWidth + 4, a3: v6, a4: -1, a5: 0);
      GString::GString(this: (GString *)&i + 1, a2: *(const char **)HIDWORD(oldWidth));
      v93 = 1;
      break;
    case 0x19:
      HIDWORD(oldWidth) = GASValue::ToObject(this: (GASValue *)val, a2: v6);
      if ( HIDWORD(oldWidth) != 0 )
      {
        Prototype = GASGlobalContext::GetPrototype(result: (vc_attributes::InvalidCheckAttribute *)2);
        v108 = HIDWORD(oldWidth);
        if ( (*(unsigned __int8 (__thiscall **)(int, struct GASEnvironment *, vc_attributes::InvalidCheckAttribute *, int))(*(_DWORD *)(HIDWORD(oldWidth) + 16) + 72))(
               a1: HIDWORD(oldWidth) + 16,
               a2: v6,
               a3: Prototype,
               a4: 1) != 0 )
        {
          v109 = *((_DWORD *)this + 43);
          newfilters = nullptr;
          aval = 0.0;
          if ( v109 == 0 || (hasfilters = true, *(_BYTE *)(v109 + 12) == 0) )
            hasfilters = false;
          v110 = 0;
          HIDWORD(i) = 0;
          if ( *(int *)(HIDWORD(oldWidth) + 60) > 0 )
          {
            do
            {
              v111 = *(GASValue **)(*(_DWORD *)(v108 + 56) + 4 * v110);
              if ( v111 != nullptr )
              {
                v112 = (IStream *)GASValue::ToObject(this: v111, a2: v6);
                if ( v112 != nullptr )
                {
                  v113 = GASGlobalContext::GetPrototype(result: (vc_attributes::InvalidCheckAttribute *)0x25);
                  if ( ((unsigned __int8 (__thiscall *)(IStream *, struct GASEnvironment *, vc_attributes::InvalidCheckAttribute *, int))v112[4].__vftable[1].Write)(
                         a1: &v112[4],
                         a2: v6,
                         a3: v113,
                         a4: 1) != 0 )
                    GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::PushBack(
                      this: (CMatQueuedMesh *)&newfilters,
                      result: v112 + 13);
                }
                v108 = HIDWORD(oldWidth);
              }
              v110 = HIDWORD(i) + 1;
              HIDWORD(i) = v110;
            }
            while ( v110 < *(_DWORD *)(v108 + 60) );
          }
          GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>(
            this: (CMatQueuedMesh *)&X,
            a: (int *)&newfilters,
            a3: (VertexDesc_t *)LODWORD(X));
          (*(void (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, float, _DWORD, _DWORD))(LODWORD(this->m_pfnProxied) + 48))(
            a1: this,
            a2: COERCE_FLOAT(LODWORD(X)),
            a3: LODWORD(X_4),
            a4: HIDWORD(X_4));
          if ( LODWORD(aval) != 0 || hasfilters )
            GFxCharacter::SetDirtyFlag(this);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: newfilters);
        }
      }
      return 1;
    case 0x1A:
      v97 = (unsigned __int8)GASValue::ToBool(result: (tagPOLYTEXTW *)v6);
      GFxASCharacter::SetEnabledFlag(
        (CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this,
        v: (const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v97);
      return 1;
    case 0x1B:
      v98 = (unsigned __int8)GASValue::ToBool(result: (tagPOLYTEXTW *)v6);
      GFxASCharacter::SetTrackAsMenuFlag(
        (CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this,
        v: (const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v98);
      return 1;
    case 0x1D:
      if ( LOBYTE(GASValue::IsUndefined().usPreferredNode) != 0 )
      {
        *((_DWORD *)this + 40) &= 0xFFFFFF9F;
      }
      else
      {
        v100 = (tagPOLYTEXTW *)(*(int (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 112))(a1: this);
        v101 = (unsigned __int8)GASValue::ToBool(result: v100);
        GFxASCharacter::SetTabEnabledFlag(
          (CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this,
          v: (const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v101);
      }
      return 1;
    case 0x1E:
      v102 = (struct GASEnvironment *)(*(int (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 112))(a1: this);
      *((_WORD *)this + 82) = (int)GASValue::ToNumber(this: (GASValue *)val, a2: v102);
      return 1;
    case 0x1F:
      if ( LOBYTE(GASValue::IsUndefined().usPreferredNode) != 0 )
      {
        *((_DWORD *)this + 40) &= 0xFFFFF9FF;
      }
      else
      {
        v105 = (tagPOLYTEXTW *)(*(int (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *))(LODWORD(this->m_pfnProxied) + 112))(a1: this);
        v106 = (unsigned __int8)GASValue::ToBool(result: v105);
        GFxASCharacter::SetUseHandCursorFlag(
          (CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this,
          v: (const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v106);
      }
      return 1;
    default:
      return 0;
  }
  while ( 1 )
  {
    HIDWORD(X_4) = *(&GFx_BlendModeNames.tm_sec + v93);
    if ( (unsigned __int8)GString::operator==(this: (CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *)((char *)&i + 4)) != 0 )
      break;
    if ( (unsigned int)++v93 >= 0xF )
      goto LABEL_87;
  }
  (*(void (__thiscall **)(CMemberFuncProxy3<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialPrimitiveType_t,int,int),enum MaterialPrimitiveType_t,int,int,CFuncMemPolicyNone> *, int))(LODWORD(this->m_pfnProxied) + 36))(
    a1: this,
    a2: v93);
LABEL_87:
  GString::~GString(this: (GString *)&i + 1);
  v94 = HIDWORD(oldWidth);
LABEL_88:
  if ( (*(_DWORD *)(v94 + 8))-- == 1 )
    GASStringNode::ReleaseNode();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10089C00
// Name: public: virtual void GFxASCharacter::SetFilters(class GArray<struct GFxFilterDesc,2,struct GArrayDefaultPolicy>)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GFxASCharacter::SetFilters@<eax>(
        CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *a1@<ecx>,
        VertexDesc_t *a2@<edi>,
        _LocaleUpdate *f,
        int a4,
        int a5)
{
  int v6; // eax
  CMatQueuedMesh *v7; // ecx
  int v8; // ebx
  CMatQueuedMesh *v10; // eax
  CMatQueuedMesh *v11; // edi
  int v12; // eax
  bool v13; // al
  int v14; // eax
  int v15; // eax
  _BYTE *v16; // edx
  int v17; // edx
  _ULARGE_INTEGER v19; // [esp+0h] [ebp-B0h]
  CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v20; // [esp+8h] [ebp-A8h]
  bool oldPrePass; // [esp+Fh] [ebp-A1h]
  int (__cdecl *null[39])(int, char *, int *); // [esp+10h] [ebp-A0h] BYREF

  v6 = (*(int (__thiscall **)(CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *))(LODWORD(a1->m_pfnProxied) + 84))(a1);
  v7 = (CMatQueuedMesh *)DWORD1(a1[7].m_pfnProxied);
  v8 = v6;
  v20 = (CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)v6;
  if ( v7 != nullptr )
  {
    GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::operator=(
      a1: v7,
      this: (IStream *)&f,
      a: v19);
  }
  else
  {
    if ( a4 == 0 )
      return ((int (__thiscall *)(GMemoryHeap *, _LocaleUpdate *))GMemory::pGlobalHeap->Free)(
               a1: GMemory::pGlobalHeap,
               a2: f);
    v10 = (CMatQueuedMesh *)MemAlloc_Alloc(nSize: 0x38u);
    v11 = v10;
    if ( v10 != nullptr )
    {
      GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>(
        this: v10,
        a: (int *)&f,
        a3: a2);
      *(float *)&v11->m_pOwner = 0.0;
      *(float *)&v11->m_pCallQueue = 0.0;
      v11->m_pLateBoundMesh.m_ppObject = nullptr;
      *(float *)&v11->m_pHardwareContext = 0.0;
      *(float *)&v11->m_VertexFormat = 0.0;
      v11->m_pIndexData = nullptr;
      v11->m_nVerts = 0;
      v11->m_nIndices = 0;
      DWORD1(a1[7].m_pfnProxied) = v11;
    }
    else
    {
      DWORD1(a1[7].m_pfnProxied) = 0;
    }
  }
  *(_BYTE *)(DWORD1(a1[7].m_pfnProxied) + 13) = 0;
  v12 = *(_DWORD *)(v8 + 264);
  v13 = (v12 == 0 || (*(_BYTE *)(v12 + 28) & 0x20) != 0) && a4 != 0;
  *(_BYTE *)(DWORD1(a1[7].m_pfnProxied) + 12) = v13;
  v14 = DWORD1(a1[7].m_pfnProxied);
  if ( *(_BYTE *)(v14 + 12) != 0 )
    return ((int (__thiscall *)(GMemoryHeap *, _LocaleUpdate *))GMemory::pGlobalHeap->Free)(
             a1: GMemory::pGlobalHeap,
             a2: f);
  if ( a4 != 0 )
  {
    oldPrePass = ((int)a1[6].m_pObject & 0x200000) != 0;
    if ( (*(_BYTE *)(LODWORD(v20[11].m_pfnProxied) + 28) & 0x40) == 0 )
    {
      if ( ((int)a1[6].m_pObject & 0x200000) != 0 )
        GFxASCharacter::RemoveFromPreDisplayList(this: a1, result: v20);
      return ((int (__thiscall *)(GMemoryHeap *, _LocaleUpdate *))GMemory::pGlobalHeap->Free)(
               a1: GMemory::pGlobalHeap,
               a2: f);
    }
    *(_BYTE *)(v14 + 12) = 1;
    GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::Clear(this: (ITypeInfo *)v19.LowPart);
    v15 = a4;
    v16 = (char *)&f[-9] + 156 * a4 - 12;
    if ( (*v16 & 0xFu) <= 4 )
    {
      if ( ((*(int (__thiscall **)(_DWORD, _BYTE *))(**(_DWORD **)(LODWORD(v20[11].m_pfnProxied) + 12) + 168))(
              a1: *(_DWORD *)(LODWORD(v20[11].m_pfnProxied) + 12),
              a2: v16 + 8)
          & 2) != 0 )
      {
        GFxFilterDesc::GFxFilterDesc(this: (IStorage *)null);
        GFxFilterDesc::SetIdentity(this: (char *)null);
        GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::PushBack(
          this: (CMatQueuedMesh *)(DWORD1(a1[7].m_pfnProxied) + 44),
          result: (IStream *)null);
        GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::PushBack(
          this: (CMatQueuedMesh *)DWORD1(a1[7].m_pfnProxied),
          result: (IStream *)null);
        v17 = DWORD1(a1[7].m_pfnProxied);
        *(_BYTE *)(v17 + 13) = 1;
        goto LABEL_20;
      }
      v15 = a4;
    }
    GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::PushBack(
      this: (CMatQueuedMesh *)(DWORD1(a1[7].m_pfnProxied) + 44),
      result: (IStream *)&f[-9] + 39 * v15 - 3);
LABEL_20:
    if ( !oldPrePass )
      GFxASCharacter::AddToPreDisplayList(a1, a2: v17, result: v20);
  }
  return ((int (__thiscall *)(GMemoryHeap *, _LocaleUpdate *))GMemory::pGlobalHeap->Free)(
           a1: GMemory::pGlobalHeap,
           a2: f);
}

//------------------------------------------------------------------------------
// Address: 0x10089E40
// Name: public: virtual void GFxASCharacter::OnRendererChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::OnRendererChanged(GFxASCharacter *this)
{
  int v2; // ecx
  _DWORD v3[4]; // [esp-Ch] [ebp-10h] BYREF

  v2 = *((_DWORD *)this + 43);
  if ( v2 != 0 )
  {
    if ( *(_BYTE *)(v2 + 13) != 0 )
      GArrayBase<GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>>::PopBack(this: (ITypeInfo *)v3[3]);
    GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>::GArrayData<GFxFilterDesc,GAllocatorGH<GFxFilterDesc,2>,GArrayDefaultPolicy>(
      this: (CMatQueuedMesh *)v3,
      a: *((int **)this + 43),
      a3: (VertexDesc_t *)v3[0]);
    (*(void (__thiscall **)(GFxASCharacter *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this + 48))(
      a1: this,
      a2: v3[0],
      a3: v3[1],
      a4: v3[2]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A3A0
// Name: public: GFxASCharacter::GFxASCharacter(class GFxMovieDefImpl __near *,class GFxASCharacter __near *,class GFxResourceId)
// Source: json
//------------------------------------------------------------------------------
GFxASCharacter *__thiscall GFxASCharacter::GFxASCharacter(GFxASCharacter *this, _IMAGE_SECTION_HEADER::<unnamed_type_Misc> pbindingDefImpl, struct GFxASCharacter *a3, struct GFxResourceId a4)
{
  VertexShaderHandle_t__ *v6; // [esp+0h] [ebp-Ch]

  GFxCharacter::GFxCharacter((GFxCharacter *)this, a2: a3, a3: a4);
  GASObjectInterface::GASObjectInterface(this: (GASObjectInterface *)((char *)this + 120));
  *(_DWORD *)this = &GFxASCharacter::`vftable'{for `GRefCountBaseWeakSupport<GFxCharacter,322>'};
  *((_DWORD *)this + 3) = &GFxASCharacter::`vftable'{for `GFxLogBase<GFxCharacter>'};
  *((_DWORD *)this + 30) = &GFxASCharacter::`vftable';
  if ( pbindingDefImpl.PhysicalAddress != 0 )
    GRefCountImpl::AddRef(this: (IShaderDevice *)pbindingDefImpl.PhysicalAddress, a2: v6);
  *((_IMAGE_SECTION_HEADER::<unnamed_type_Misc> *)this + 36) = pbindingDefImpl;
  *((_DWORD *)this + 37) = 0;
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 39) = 0;
  *((_DWORD *)this + 41) = 0;
  *((_WORD *)this + 59) |= 0x80u;
  *((_DWORD *)this + 44) = 0;
  *((_DWORD *)this + 45) = 0;
  *((_DWORD *)this + 34) = 0;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 35) = 0;
  *((_WORD *)this + 84) = 0;
  *((_DWORD *)this + 43) = 0;
  *((_DWORD *)this + 40) = 20497;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008A450
// Name: protected: virtual bool GFxASCharacter::GetContinueAnimationFlag(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxASCharacter::GetContinueAnimationFlag(GFxASCharacter *this)
{
  return (*((_DWORD *)this + 40) & 0x100000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008A460
// Name: protected: virtual bool GFxASCharacter::IsUsedAsMask(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxASCharacter::IsUsedAsMask(GFxASCharacter *this)
{
  return (*((_DWORD *)this + 40) & 0x8000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008A470
// Name: public: virtual enum GRenderer::BlendType GFxASCharacter::GetBlendMode(void)const
// Source: json
//------------------------------------------------------------------------------
enum GRenderer::BlendType __thiscall GFxASCharacter::GetBlendMode(GFxASCharacter *this)
{
  return *((unsigned __int8 *)this + 168);
}

//------------------------------------------------------------------------------
// Address: 0x1008A480
// Name: public: virtual bool GFxASCharacter::GetVisible(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxASCharacter::GetVisible(GFxASCharacter *this)
{
  return *((_DWORD *)this + 40) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008A490
// Name: public: virtual bool GFxASCharacter::GetAcceptAnimMoves(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxASCharacter::GetAcceptAnimMoves(GFxASCharacter *this)
{
  return (*((_DWORD *)this + 40) & 0x1000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008A4F0
// Name: public: virtual void GFxASCharacter::SetDisplayCallback(void (*)(void __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::SetDisplayCallback(GFxASCharacter *this, void (__cdecl *a2)(void *), void *a3)
{
  *((_DWORD *)this + 44) = a2;
  *((_DWORD *)this + 45) = a3;
}

//------------------------------------------------------------------------------
// Address: 0x1008A510
// Name: public: virtual void GFxASCharacter::DoDisplayCallback(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::DoDisplayCallback(GFxASCharacter *this)
{
  void (__cdecl *v1)(_DWORD); // eax

  v1 = *((void (__cdecl **)(_DWORD))this + 44);
  if ( v1 != nullptr )
    v1(a1: *((_DWORD *)this + 45));
}

//------------------------------------------------------------------------------
// Address: 0x1008A530
// Name: public: virtual bool GFxASCharacter::GetMember(class GASEnvironment __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::GetMember(
        GRefCountBaseNTS<GFxKeyboardState,326> *this,
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *pt,
        int a3,
        int prototype)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1008A540
// Name: public: virtual bool GFxASCharacter::SetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue const __near &,class GASPropFlags const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxASCharacter::SetMemberRaw(
        GFxASCharacter *this,
        struct GASStringContext *a2,
        const struct GASString *a3,
        const struct GASValue *a4,
        const struct GASPropFlags *a5)
{
  int v6; // edi
  int v7; // eax

  v6 = *(_DWORD *)this;
  v7 = (*(int (__thiscall **)(char *, const struct GASString *, const struct GASValue *, const struct GASPropFlags *))(*((_DWORD *)this - 30) + 112))(
         a1: (char *)this - 120,
         a2: a3,
         a3: a4,
         a4: a5);
  return (*(bool (__thiscall **)(GFxASCharacter *, int))(v6 + 12))(a1: this, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1008A570
// Name: public: virtual bool GFxASCharacter::GetMemberRaw(class GASStringContext __near *,class GASString const __near &,class GASValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxASCharacter::GetMemberRaw(
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this@<ecx>,
        _IMAGE_SYMBOL_EX *psc,
        __int128 name,
        const VMatrix *val)
{
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *v5; // edi
  int v6; // eax

  v5 = this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable;
  v6 = (*(int (__thiscall **)(char *, _DWORD, _DWORD))(*((_DWORD *)this - 30) + 112))(
         a1: (char *)this - 120,
         a2: name,
         a3: DWORD1(name));
  ((void (__thiscall *)(CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *, int))v5[1].AddRef)(
    a1: this,
    a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1008A5A0
// Name: public: virtual void GFxASCharacter::SetStateChangeFlags(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::SetStateChangeFlags(GFxASCharacter *this, unsigned __int8 flags)
{
  *((_DWORD *)this + 40) ^= (*((_DWORD *)this + 40) ^ (flags << 16)) & 0x30000;
}

//------------------------------------------------------------------------------
// Address: 0x1008A5C0
// Name: public: virtual unsigned char GFxASCharacter::GetStateChangeFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxASCharacter::GetStateChangeFlags(GFxASCharacter *this)
{
  return *((_WORD *)this + 81) & 3;
}

//------------------------------------------------------------------------------
// Address: 0x1008A600
// Name: public: virtual void GFxASCharacter::SetBlendMode(enum GRenderer::BlendType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::SetBlendMode(
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialFogMode_t),enum MaterialFogMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialFogMode_t),enum MaterialFogMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *blend)
{
  CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialFogMode_t),enum MaterialFogMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *v2; // edx
  int v3; // eax

  v2 = this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable;
  *((_BYTE *)this + 168) = (_BYTE)blend;
  v3 = ((int (*)(void))v2[5].Release)();
  *(_DWORD *)(v3 + 9332) |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x1008A630
// Name: public: virtual void GFxASCharacter::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::SetVisible(
        CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(int,MeshInstanceData_t const *),int,MeshInstanceData_t const *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *visible)
{
  int v2; // eax

  if ( (_BYTE)visible != 0 )
    *((_DWORD *)this + 40) |= 1u;
  else
    *((_DWORD *)this + 40) &= ~1u;
  v2 = this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable[5].Release(this);
  *(_DWORD *)(v2 + 9332) |= 0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x1008A660
// Name: public: virtual GFxASCharacter::~GFxASCharacter(void)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxASCharacter::~GFxASCharacter(
        GFxASCharacter *this@<ecx>,
        GFxMovie *a2@<esi>,
        CMemberFuncProxyBase<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),CFuncMemPolicyNone> *a3)
{
  int v4; // eax
  GFxMovie **v5; // ebx
  GFxMovie *v6; // esi
  _DWORD *v7; // esi
  int v8; // ecx
  bool v9; // zf
  int v10; // ecx
  int v11; // ecx
  IShaderDevice *v12; // ecx
  GFxMovie *v13; // [esp-8h] [ebp-Ch]

  v4 = *((_DWORD *)this + 37);
  *(_DWORD *)this = &GFxASCharacter::`vftable'{for `GRefCountBaseWeakSupport<GFxCharacter,322>'};
  *((_DWORD *)this + 3) = &GFxASCharacter::`vftable'{for `GFxLogBase<GFxCharacter>'};
  *((_DWORD *)this + 30) = &GFxASCharacter::`vftable';
  if ( v4 != 0 )
    *(_DWORD *)(v4 + 4) = 0;
  if ( *((_DWORD *)this + 38) != 0 )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 38));
  v5 = *((GFxMovie ***)this + 43);
  v13 = a2;
  if ( v5 != nullptr )
  {
    ((void (__thiscall *)(GMemoryHeap *, GFxMovie *, GFxMovie *))GMemory::pGlobalHeap->Free)(
      a1: GMemory::pGlobalHeap,
      a2: v5[11],
      a3: a2);
    v6 = v5[4];
    if ( v6 != nullptr && InterlockedExchangeAdd(Addend: &v6->RefCount, Value: -1) == 1 )
      ((void (__thiscall *)(GFxMovie *, int))v6->dtr_GRefCountImplCore)(a1: v6, a2: 1);
    v13 = *v5;
    ((void (__thiscall *)(GMemoryHeap *))GMemory::pGlobalHeap->Free)(a1: GMemory::pGlobalHeap);
    free(pMem: v5);
  }
  GHashSetBase<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeHashF,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeAltHashF,GAllocatorLH<GFxEventId,323>,GHashsetCachedNodeEntry<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeHashF>>::~GHashSetBase<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeHashF,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeAltHashF,GAllocatorLH<GFxEventId,323>,GHashsetCachedNodeEntry<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeHashF>>(result: v13);
  v7 = *((_DWORD **)this + 37);
  if ( v7 != nullptr && (int)--*v7 <= 0 )
  {
    v8 = v7[4];
    v9 = (*(_DWORD *)(v8 + 8))-- == 1;
    if ( v9 )
      GASStringNode::ReleaseNode();
    v10 = v7[3];
    v9 = (*(_DWORD *)(v10 + 8))-- == 1;
    if ( v9 )
      GASStringNode::ReleaseNode();
    v11 = v7[2];
    v9 = (*(_DWORD *)(v11 + 8))-- == 1;
    if ( v9 )
      GASStringNode::ReleaseNode();
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v7);
  }
  v12 = *((IShaderDevice **)this + 36);
  if ( v12 != nullptr )
    GFxResource::Release(this: v12);
  GASObjectInterface::~GASObjectInterface(this: (GASObjectInterface *)((char *)this + 120));
  GFxCharacter::~GFxCharacter(this, result: a3);
}

//------------------------------------------------------------------------------
// Address: 0x1008A870
// Name: public: void GFxASCharacter::SetSingleClipEventHandler(class GFxEventId const __near &,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::SetSingleClipEventHandler(
        GFxASCharacter *this,
        const struct GFxEventId *a2,
        tagWNDCLASSW *method)
{
  int v3; // eax
  GFxASCharacter *v4; // edx
  int v5; // ecx
  int v6; // esi
  char *v7; // edi
  int v8; // eax
  int Index; // eax
  IGameEventManager2 *v10; // eax
  _DWORD *v11; // esi
  IGameEventManager2 *v12; // eax
  IGameEventManager2 *v13; // esi
  GASValue *v14; // edi
  IGameEventManager2_vtbl *v15; // ebx
  int v16; // [esp+Ch] [ebp-14h] BYREF
  int v17; // [esp+10h] [ebp-10h]
  unsigned __int64 v18; // [esp+14h] [ebp-Ch]
  int v19; // [esp+1Ch] [ebp-4h] BYREF

  v3 = *(_DWORD *)a2;
  v4 = this;
  v19 = (int)this;
  if ( v3 == 64 || v3 == 128 )
  {
    v5 = v3;
    v17 = 0;
    LOWORD(v18) = 0;
    *(_DWORD *)((char *)&v18 + 2) = 65280;
  }
  else
  {
    v5 = v3;
    v17 = *((_DWORD *)a2 + 1);
    v18 = *((_QWORD *)a2 + 1);
  }
  v6 = *((_DWORD *)v4 + 39);
  v7 = (char *)v4 + 156;
  v16 = v5;
  if ( v6 == 0 )
    goto LABEL_12;
  v8 = v5;
  if ( (v5 & 0x20000) != 0 )
    v8 = v5 ^ (__int16)v18;
  Index = GHashSetBase<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeHashF,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeAltHashF,GAllocatorLH<GFxEventId,323>,GHashsetCachedNodeEntry<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeHashF>>::findIndexCore<GFxEventId>(
            a1: &v16,
            a2: v8 & *(_DWORD *)(v6 + 4));
  if ( Index < 0
    || (v10 = (IGameEventManager2 *)(v6 + 36 * Index + 16)) == nullptr
    || (v11 = &v10[4].__vftable, v10 == (IGameEventManager2 *)-16) )
  {
    v4 = (GFxASCharacter *)v19;
LABEL_12:
    v19 = 323;
    v12 = (IGameEventManager2 *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                  this: GMemory::pGlobalHeap,
                                  a2: v4,
                                  a3: 12,
                                  a4: &v19);
    if ( v12 != nullptr )
    {
      v12->__vftable = nullptr;
      v12[1].__vftable = nullptr;
      v12[2].__vftable = nullptr;
      v13 = v12;
    }
    else
    {
      v13 = nullptr;
    }
    GArrayDataBase<GASValue,GAllocatorLH<GASValue,323>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: v13,
      pheapAddr: (IGameEvent *)v13,
      newSize: (unsigned int)&v13[1].dtr_IBaseInterface + 1);
    if ( (IGameEventManager2_vtbl *)((char *)v13->__vftable + 16 * (int)v13[1].__vftable) != (IGameEventManager2_vtbl *)16 )
      GASValue::GASValue(
        this: (GASValue *)v13->__vftable + 4 * (int)v13[1].__vftable - 4,
        a2: (const struct GASValue *)method);
    v18 = __PAIR64__((unsigned int)v13, (unsigned int)a2);
    GHashSetBase<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeHashF,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeAltHashF,GAllocatorLH<GFxEventId,323>,GHashsetCachedNodeEntry<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeHashF>>::Set<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeRef>(
      this: v7,
      pmemAddr: v7);
    v14 = (GASValue *)((char *)v13->__vftable + 16 * (int)v13[1].__vftable - 16);
    if ( v13[1].__vftable != nullptr )
    {
      v15 = v13[1].__vftable;
      do
      {
        GASValue::~GASValue(this: v14);
        v14 -= 4;
        v15 = (IGameEventManager2_vtbl *)((char *)v15 - 1);
      }
      while ( v15 != nullptr );
    }
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v13->__vftable);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v13);
    return;
  }
  GArrayDataBase<GASValue,GAllocatorLH<GASValue,323>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: v10 + 4,
    pheapAddr: (IGameEvent *)&v10[4],
    newSize: (unsigned int)&v10[5].dtr_IBaseInterface + 1);
  if ( *v11 + 16 * v11[1] != 16 )
    GASValue::GASValue(this: (GASValue *)(*v11 + 16 * v11[1] - 16), a2: (const struct GASValue *)method);
}

//------------------------------------------------------------------------------
// Address: 0x1008A9F0
// Name: public: void GFxASCharacter::SetClipEventHandlers(class GFxEventId const __near &,class GASValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxASCharacter::SetClipEventHandlers(
        GFxASCharacter *this,
        const struct GFxEventId *i,
        tagWNDCLASSW *method)
{
  unsigned int v4; // ebx
  unsigned __int8 v5; // dl
  unsigned int v6; // edi
  const struct GFxEventId *v7; // eax
  int v8; // ebx
  int v9; // edx
  int v10; // eax
  int v11; // ecx
  _COMMTIMEOUTS *copied; // [esp+Ch] [ebp-14h] BYREF
  int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  int v15; // [esp+18h] [ebp-8h]
  GFxASCharacter *v16; // [esp+1Ch] [ebp-4h]
  const struct GFxEventId *ia; // [esp+28h] [ebp+8h]

  v16 = this;
  v4 = (((((*(_DWORD *)i & 0x55555555) + ((*(_DWORD *)i >> 1) & 0x55555555)) & 0x33333333)
       + ((((*(_DWORD *)i & 0x55555555) + ((*(_DWORD *)i >> 1) & 0x55555555u)) >> 2) & 0x33333333))
      & 0xF0F0F0F)
     + ((((((*(_DWORD *)i & 0x55555555) + ((*(_DWORD *)i >> 1) & 0x55555555)) & 0x33333333)
        + ((((*(_DWORD *)i & 0x55555555) + ((*(_DWORD *)i >> 1) & 0x55555555u)) >> 2) & 0x33333333)) >> 4)
      & 0x70F0F0F);
  v5 = v4 + v4 / 0xFF;
  v6 = v5;
  if ( v5 == 1 )
  {
    GFxASCharacter::SetSingleClipEventHandler(this: v16, a2: i, method);
  }
  else
  {
    v7 = nullptr;
    v8 = 1;
    if ( v5 != 0 )
    {
      do
      {
        if ( (v8 & *(_DWORD *)i) != 0 )
        {
          v9 = *((_DWORD *)i + 1);
          ia = (const struct GFxEventId *)((char *)v7 + 1);
          v10 = *((_DWORD *)i + 2);
          copied = *(_COMMTIMEOUTS **)i;
          v11 = *((_DWORD *)i + 3);
          v13 = v9;
          v14 = v10;
          v15 = v11;
          copied = (_COMMTIMEOUTS *)v8;
          GFxASCharacter::SetSingleClipEventHandler(this: v16, a2: (const struct GFxEventId *)&copied, method);
          v7 = ia;
        }
        v8 *= 2;
      }
      while ( (unsigned int)v7 < v6 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008AAC0
// Name: public: virtual void GFxASCharacter::CloneInternalData(class GFxASCharacter const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxASCharacter::CloneInternalData(
        CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        unsigned int src)
{
  if ( *(_DWORD *)(src + 152) != 0 )
    GFxASCharacter::SetGeomData(
      (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this,
      gd: *(CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(src + 152));
  return GHashSetBase<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeHashF,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeAltHashF,GAllocatorLH<GFxEventId,323>,GHashsetCachedNodeEntry<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeHashF>>::Assign(
           this: (GFxMovie *)((char *)this + 156),
           pmemAddr: (const char *)this + 156,
           src: src + 156);
}

//------------------------------------------------------------------------------
// Address: 0x1008AB00
// Name: public: void GFxASCharacter::CopyPhysicalProperties(class GFxASCharacter const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GFxASCharacter::CopyPhysicalProperties(
        CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        unsigned int poldChar)
{
  CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *v3; // edx
  int (__thiscall *Release)(struct CMemberFunctor3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *); // eax
  unsigned __int8 result; // al
  CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v6; // esi

  v3 = this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable;
  DWORD1(this->m_Proxy.m_pfnProxied) = *(_DWORD *)(poldChar + 20);
  Release = v3->Release;
  qmemcpy(&this->m_Proxy.m_pObject + 1, (const void *)(poldChar + 36), 0x20u);
  Release(this);
  *((float *)this + 17) = *(float *)(poldChar + 68);
  *((CMemberFuncProxy3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CFuncMemPolicyNone> *)this
  + 3) = *(CMemberFuncProxy3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CFuncMemPolicyNone> *)(poldChar + 72);
  result = GHashSetBase<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeHashF,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeAltHashF,GAllocatorLH<GFxEventId,323>,GHashsetCachedNodeEntry<GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>,GHashNode<GFxEventId,GArrayLH<GASValue,323,GArrayDefaultPolicy>,GFxEventIdHashFunctor>::NodeHashF>>::Assign(
             this: (GFxMovie *)((char *)this + 156),
             pmemAddr: (const char *)this + 156,
             src: poldChar + 156);
  v6 = *(CMemberFunctor2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)(poldChar + 152);
  if ( v6 != nullptr )
    return (unsigned __int8)GFxASCharacter::SetGeomData(
                              (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(FlashlightState_t const &,VMatrix const &),FlashlightState_t,VMatrix,CFuncMemPolicyNone> *)this,
                              gd: v6);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B2B00
// Name: public: void GFxASCharacter::ModifyOptimizedPlayListLocal<class GFxSprite>(class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *__thiscall GFxASCharacter::ModifyOptimizedPlayListLocal<GFxSprite>(
        int this,
        const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *result)
{
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v3; // eax

  v3 = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)GFxSprite::CheckAdvanceStatus((GFxSprite *)this, a2: (*(_DWORD *)(this + 160) & 0x80000) != 0);
  if ( v3 == (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)-1 )
    return (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)GFxASCharacter::RemoveFromOptimizedPlaylist((CMatQueuedMesh **)this, result);
  if ( v3 == (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)1 )
    return (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)GFxASCharacter::AddToOptimizedPlayList(this, result);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100C0040
// Name: public: virtual void GFxMovieRoot::GetMouseState(unsigned int,float __near *,float __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMovieRoot::GetMouseState(
        GFxMovieRoot *this,
        unsigned int a2,
        float *a3,
        float *a4,
        unsigned int *a5)
{
  unsigned int v6; // eax
  float v7; // [esp+0h] [ebp-8h]
  float v8; // [esp+4h] [ebp-4h]
  float v9; // [esp+10h] [ebp+8h]
  float v10; // [esp+10h] [ebp+8h]

  if ( a2 < *((_DWORD *)this + 625) )
  {
    v6 = 9 * a2 + 594;
    v9 = *((float *)this + v6) / 20.0;
    v7 = (v9 - *((float *)this + 32)) / *((float *)this + 30);
    v10 = *((float *)this + v6 + 1) / 20.0;
    v8 = (v10 - *((float *)this + 33)) / *((float *)this + 31);
    if ( a3 != nullptr )
      *a3 = v7;
    if ( a4 != nullptr )
      *a4 = v8;
    if ( a5 != nullptr )
      *a5 = *((_DWORD *)this + 9 * a2 + 592);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED3D0
// Name: public: void GFxASCharacter::ModifyOptimizedPlayListLocal<class GFxEditTextCharacter>(class GFxMovieRoot __near *)
// Source: json
//------------------------------------------------------------------------------
const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *__thiscall GFxASCharacter::ModifyOptimizedPlayListLocal<GFxEditTextCharacter>(
        ScaleformRenderer::VertexShaderType this,
        const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *result)
{
  const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *v3; // eax

  v3 = (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)GFxEditTextCharacter::CheckAdvanceStatus(ch: this, a2: (*(_DWORD *)(this + 160) & 0x80000) != 0);
  if ( v3 == (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)-1 )
    return (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)GFxASCharacter::RemoveFromOptimizedPlaylist((CMatQueuedMesh **)this, result);
  if ( v3 == (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)1 )
    return (const CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CFuncMemPolicyNone> *)GFxASCharacter::AddToOptimizedPlayList(this, result);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1010C440
// Name: public: void GASValue::SetInt(int)
// Source: json
//------------------------------------------------------------------------------
tagCOMPAREITEMSTRUCT *__thiscall GASValue::SetInt(int this, tagCOMPAREITEMSTRUCT *result)
{
  tagCOMPAREITEMSTRUCT *v3; // eax

  if ( *(_BYTE *)this >= 5u )
  {
    GASValue::DropRefs((GASValue *)this);
    v3 = result;
  }
  *(_DWORD *)(this + 4) = result;
  *(_BYTE *)this = 4;
  return v3;
}
