// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/cs_nav_mesh.cpp
// Functions: 9
// ============================================================

#include "game\server\cstrike15\cs_nav_mesh.h"

//------------------------------------------------------------------------------
// Address: 0x102E0860
// Name: public: CSNavMesh::CSNavMesh(void)
// Source: json
//------------------------------------------------------------------------------
CSNavMesh *__thiscall CSNavMesh::CSNavMesh(CSNavMesh *this)
{
  CNavMesh::CNavMesh(this);
  this->__vftable = (CSNavMesh_vtbl *)&CSNavMesh::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102E0880
// Name: public: virtual void CNavMesh::DestroyArea(class CNavArea __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::DestroyArea(CNavMesh *this, CNavArea *pArea)
{
  if ( pArea != nullptr )
    ((void (__thiscall *)(CNavArea *, int))pArea->dtr_CNavArea)(a1: pArea, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x102E08A0
// Name: public: virtual unsigned int CNavMesh::GetGenerationTraceMask(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNavMesh::GetGenerationTraceMask(CNavMesh *this)
{
  return 147467;
}

//------------------------------------------------------------------------------
// Address: 0x102E08B0
// Name: public: virtual class CNavArea __near * CSNavMesh::CreateArea(void)const
// Source: json
//------------------------------------------------------------------------------
CCSNavArea *__thiscall CSNavMesh::CreateArea(CSNavMesh *this)
{
  CCSNavArea *v1; // eax

  v1 = (CCSNavArea *)operator new(nSize: 0x338u);
  if ( v1 != nullptr )
    return CCSNavArea::CCSNavArea(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102E08D0
// Name: public: virtual void CSNavMesh::Reset(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CSNavMesh::Reset(CSNavMesh *this)
{
  CNavMesh::Reset(this);
}

//------------------------------------------------------------------------------
// Address: 0x102E08E0
// Name: public: virtual void CSNavMesh::Update(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CSNavMesh::Update(CSNavMesh *this)
{
  CNavMesh::Update(this);
}

//------------------------------------------------------------------------------
// Address: 0x102E08F0
// Name: public: virtual enum NavErrorType CSNavMesh::Load(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
NavErrorType __thiscall CSNavMesh::Load(CSNavMesh *this)
{
  return CNavMesh::Load(this);
}

//------------------------------------------------------------------------------
// Address: 0x102E0900
// Name: public: virtual bool CSNavMesh::Save(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CSNavMesh::Save(CSNavMesh *this)
{
  return CNavMesh::Save(this);
}

//------------------------------------------------------------------------------
// Address: 0x102E0910
// Name: public: virtual enum NavErrorType CSNavMesh::PostLoad(unsigned int)
// Source: json
//------------------------------------------------------------------------------
NavErrorType __thiscall CSNavMesh::PostLoad(CSNavMesh *this, unsigned int version)
{
  return CNavMesh::PostLoad(this, version);
}
