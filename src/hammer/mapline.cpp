// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapline.cpp
// Functions: 19
// ============================================================

#include "hammer\mapline.h"

//------------------------------------------------------------------------------
// Address: 0x10110A50
// Name: public: virtual void CMapLine::OnAddToWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLine::OnAddToWorld(CMapCylinder *this, CMapWorld *pWorld)
{
  CMapClass::OnAddToWorld(this, pWorld);
  this->UpdateDependencies(this, a2: pWorld, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101326F0
// Name: public: virtual char const __near * CMapLine::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapLine::GetType(CMapLine *this)
{
  return CMapLine::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10132700
// Name: public: virtual int CMapLine::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapLine::IsMapClass(CMapLine *this, const char *Type)
{
  return Type == CMapLine::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x10132720
// Name: public: virtual char const __near * CMapLine::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapLine::GetDescription(CMapLine *this)
{
  return "Line helper";
}

//------------------------------------------------------------------------------
// Address: 0x10132730
// Name: public: void CMapLine::BuildLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLine::BuildLine(CMapLine *this)
{
  void (__thiscall *SetOrigin)(CMapPoint *, Vector *); // edx
  float v3[3]; // [esp+4h] [ebp-24h] BYREF
  Vector Start; // [esp+10h] [ebp-18h] BYREF
  Vector End; // [esp+1Ch] [ebp-Ch] BYREF

  if ( this->m_pStartEntity != nullptr && this->m_pEndEntity != nullptr )
  {
    this->m_pStartEntity->GetOrigin(this: this->m_pStartEntity, a2: &Start);
    this->m_pEndEntity->GetOrigin(this: this->m_pEndEntity, a2: &End);
    SetOrigin = this->SetOrigin;
    v3[0] = (float)(End.x + Start.x) * 0.5;
    v3[1] = (float)(Start.y + End.y) * 0.5;
    v3[2] = (float)(End.z + Start.z) * 0.5;
    SetOrigin(this, a2: (Vector *)v3);
  }
  this->CalcBounds(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101327D0
// Name: public: virtual class CMapClass __near * CMapLine::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapLine *__thiscall CMapLine::CopyFrom(CMapLine *this, CVisGroup *pObject, bool bUpdateDependencies)
{
  char *v4; // edi
  CMapEntity *updated; // eax
  CMapEntity *m_pEndEntity; // edx
  char *v7; // eax
  char v8; // cl
  char *v9; // eax
  char v10; // cl
  char *v11; // eax
  char v12; // cl
  char *v13; // eax
  char v14; // cl

  v4 = (char *)__RTDynamicCast(
                 inptr: pObject,
                 VfDelta: 0,
                 SrcType: &CMapClass `RTTI Type Descriptor',
                 TargetType: &CMapLine `RTTI Type Descriptor',
                 isReference: 0);
  if ( v4 != nullptr )
  {
    CMapClass::CopyFrom(this, pFrom: pObject, bUpdateDependencies);
    if ( bUpdateDependencies )
    {
      updated = (CMapEntity *)CMapClass::UpdateDependency(
                                this,
                                pOldAttached: this->m_pStartEntity,
                                pNewAttached: *((CMapClass **)v4 + 134));
      m_pEndEntity = this->m_pEndEntity;
      this->m_pStartEntity = updated;
      this->m_pEndEntity = (CMapEntity *)CMapClass::UpdateDependency(
                                           this,
                                           pOldAttached: m_pEndEntity,
                                           pNewAttached: *((CMapClass **)v4 + 135));
    }
    else
    {
      this->m_pStartEntity = *((CMapEntity **)v4 + 134);
      this->m_pEndEntity = *((CMapEntity **)v4 + 135);
    }
    v7 = v4 + 216;
    do
    {
      v8 = *v7;
      v7[(char *)this - v4] = *v7;
      ++v7;
    }
    while ( v8 != 0 );
    v9 = v4 + 296;
    do
    {
      v10 = *v9;
      v9[(char *)this - v4] = *v9;
      ++v9;
    }
    while ( v10 != 0 );
    v11 = v4 + 376;
    do
    {
      v12 = *v11;
      v11[(char *)this - v4] = *v11;
      ++v11;
    }
    while ( v12 != 0 );
    v13 = v4 + 456;
    do
    {
      v14 = *v13;
      v13[(char *)this - v4] = *v13;
      ++v13;
    }
    while ( v14 != 0 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101328D0
// Name: public: virtual void CMapLine::OnRemoveFromWorld(class CMapWorld __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLine::OnRemoveFromWorld(CMapLine *this, CMapWorld *pWorld, bool bNotifyChildren)
{
  CMapClass::OnRemoveFromWorld(this, pWorld, bNotifyChildren);
  this->m_pStartEntity = (CMapEntity *)CMapClass::UpdateDependency(
                                         this,
                                         pOldAttached: this->m_pStartEntity,
                                         pNewAttached: nullptr);
  this->m_pEndEntity = (CMapEntity *)CMapClass::UpdateDependency(
                                       this,
                                       pOldAttached: this->m_pEndEntity,
                                       pNewAttached: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10132920
// Name: public: virtual void CMapLine::OnNotifyDependent(class CMapClass __near *,enum Notify_Dependent_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLine::OnNotifyDependent(CMapLine *this, CMapClass *pObject, KeyValues *eNotifyType)
{
  CMapWorld *WorldObject; // eax

  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: (int)pObject, msg: eNotifyType);
  WorldObject = CMapClass::GetWorldObject(pStart: this);
  this->UpdateDependencies(this, a2: WorldObject, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10132960
// Name: public: virtual void CMapLine::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLine::OnParentKeyChanged(CMapLine *this, const char *key, const char *value)
{
  CMapWorld *WorldObject; // edi
  CMapClass *v5; // eax
  CMapClass *v6; // eax

  WorldObject = CMapClass::GetWorldObject(pStart: this);
  if ( WorldObject != nullptr )
  {
    if ( _V_stricmp(s1: key, s2: this->m_szStartValueKey) != 0 )
    {
      if ( _V_stricmp(s1: key, s2: this->m_szEndValueKey) == 0 )
      {
        v6 = WorldObject->FindChildByKeyValue(
               this: WorldObject,
               a2: this->m_szEndKey,
               a3: value,
               a4: nullptr,
               a5: nullptr);
        this->m_pEndEntity = (CMapEntity *)CMapClass::UpdateDependency(
                                             this,
                                             pOldAttached: this->m_pEndEntity,
                                             pNewAttached: v6);
        CMapLine::BuildLine(this);
      }
    }
    else
    {
      v5 = WorldObject->FindChildByKeyValue(
             this: WorldObject,
             a2: this->m_szStartKey,
             a3: value,
             a4: nullptr,
             a5: nullptr);
      this->m_pStartEntity = (CMapEntity *)CMapClass::UpdateDependency(
                                             this,
                                             pOldAttached: this->m_pStartEntity,
                                             pNewAttached: v5);
      CMapLine::BuildLine(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132A20
// Name: public: virtual void CMapLine::Render2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapLine::Render2D(CMapLine *this@<ecx>, int a2@<edi>, CRender2D *pRender)
{
  unsigned __int8 r; // [esp-Ch] [ebp-28h]
  unsigned __int8 g; // [esp-8h] [ebp-24h]
  unsigned __int8 b; // [esp-4h] [ebp-20h]
  Vector Start; // [esp+4h] [ebp-18h] BYREF
  Vector End; // [esp+10h] [ebp-Ch] BYREF

  if ( this->m_pStartEntity != nullptr && this->m_pEndEntity != nullptr )
  {
    this->m_pStartEntity->GetOrigin(this: this->m_pStartEntity, a2: &Start);
    this->m_pEndEntity->GetOrigin(this: this->m_pEndEntity, a2: &End);
    if ( this->IsSelected(this) )
    {
      b = 0;
      g = 0;
      r = -36;
    }
    else
    {
      b = this->b;
      g = this->g;
      r = this->r;
    }
    CRender::SetDrawColor(this: pRender, r, g, b);
    CRender::DrawLine(this: pRender, a2, a3: (int)pRender, vStart: &Start, vEnd: &End);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132AB0
// Name: protected: virtual void CMapLine::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLine::DoTransform(CMapLine *this, const VMatrix *matrix)
{
  CMapClass::DoTransform(this, matrix);
  CMapLine::BuildLine(this);
}

//------------------------------------------------------------------------------
// Address: 0x10132AD0
// Name: public: virtual void CMapLine::UpdateDependencies(class CMapWorld __near *,class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLine::UpdateDependencies(CMapLine *this, CMapWorld *pWorld, CMapClass *pObject)
{
  char *v4; // eax
  WCKeyValuesT<WCKVBase_Dict> *v5; // ebx
  const char *Value; // eax
  CMapEntity *v7; // eax
  CMapEntity *updated; // eax
  bool v9; // zf
  const char *v10; // eax
  CMapEntity *v11; // [esp-8h] [ebp-10h]

  if ( pWorld != nullptr )
  {
    v4 = (char *)__RTDynamicCast(
                   inptr: this->m_pParent,
                   VfDelta: 0,
                   SrcType: &CMapAtom `RTTI Type Descriptor',
                   TargetType: &CMapEntity `RTTI Type Descriptor',
                   isReference: 0);
    if ( v4 != nullptr )
    {
      v5 = (WCKeyValuesT<WCKVBase_Dict> *)(v4 + 220);
      Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                this: (WCKeyValuesT<WCKVBase_Dict> *)(v4 + 220),
                pszKey: this->m_szStartValueKey,
                piIndex: nullptr);
      v7 = pWorld->FindChildByKeyValue(this: pWorld, a2: this->m_szStartKey, a3: Value, a4: 0, a5: 0);
      updated = (CMapEntity *)CMapClass::UpdateDependency(this, pOldAttached: this->m_pStartEntity, pNewAttached: v7);
      v9 = this->m_szEndValueKey[0] == 0;
      this->m_pStartEntity = updated;
      if ( v9 )
      {
        v11 = (CMapEntity *)this->GetParent(this);
      }
      else
      {
        v10 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: v5, pszKey: this->m_szEndValueKey, piIndex: nullptr);
        v11 = pWorld->FindChildByKeyValue(this: pWorld, a2: this->m_szEndKey, a3: v10, a4: 0, a5: 0);
      }
      this->m_pEndEntity = (CMapEntity *)CMapClass::UpdateDependency(
                                           this,
                                           pOldAttached: this->m_pEndEntity,
                                           pNewAttached: v11);
      CMapLine::BuildLine(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10132C10
// Name: public: CMapLine::CMapLine(char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMapLine *__thiscall CMapLine::CMapLine(
        CMapLine *this,
        const char *pszStartKey,
        const char *pszStartValueKey,
        const char *pszEndKey,
        const char *pszEndValueKey)
{
  const char *v6; // ecx
  const char *v7; // eax
  char v8; // dl
  char v9; // cl

  CMapClass::CMapClass(this);
  this->__vftable = (CMapLine_vtbl *)&CMapHelper::`vftable';
  this->m_szStartKey[0] = 0;
  this->m_szStartValueKey[0] = 0;
  this->m_szEndKey[0] = 0;
  this->m_szEndValueKey[0] = 0;
  this->m_pStartEntity = nullptr;
  this->m_pEndEntity = nullptr;
  this->__vftable = (CMapLine_vtbl *)&CMapLine::`vftable';
  strcpy(this->m_szStartKey, pszStartKey);
  strcpy(this->m_szStartValueKey, pszStartValueKey);
  v6 = pszEndKey;
  if ( pszEndKey != nullptr )
  {
    v7 = pszEndValueKey;
    if ( pszEndValueKey != nullptr )
    {
      do
      {
        v8 = *v6;
        v6[this->m_szEndKey - pszEndKey] = *v6;
        ++v6;
      }
      while ( v8 != 0 );
      do
      {
        v9 = *v7;
        v7[this->m_szEndValueKey - pszEndValueKey] = *v7;
        ++v7;
      }
      while ( v9 != 0 );
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10132CF0
// Name: public: virtual void CMapLine::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLine::CalcBounds(CMapLine *this, int bFullUpdate)
{
  Vector End; // [esp+4h] [ebp-18h] BYREF
  Vector Start; // [esp+10h] [ebp-Ch] BYREF

  CMapClass::CalcBounds(this, bFullUpdate);
  if ( this->m_pStartEntity != nullptr && this->m_pEndEntity != nullptr )
  {
    this->m_pStartEntity->GetOrigin(this: this->m_pStartEntity, a2: &Start);
    BoundBox::UpdateBounds(this: &this->m_CullBox, pt: &Start);
    this->m_pEndEntity->GetOrigin(this: this->m_pEndEntity, a2: &End);
    BoundBox::UpdateBounds(this: &this->m_CullBox, pt: &End);
  }
  this->m_BoundingBox.bmins.x = this->m_CullBox.bmins.x;
  this->m_BoundingBox.bmins.y = this->m_CullBox.bmins.y;
  this->m_BoundingBox.bmins.z = this->m_CullBox.bmins.z;
  this->m_BoundingBox.bmaxs.x = this->m_CullBox.bmaxs.x;
  this->m_BoundingBox.bmaxs.y = this->m_CullBox.bmaxs.y;
  this->m_BoundingBox.bmaxs.z = this->m_CullBox.bmaxs.z;
}

//------------------------------------------------------------------------------
// Address: 0x10132D80
// Name: public: virtual class CMapClass __near * CMapLine::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapLine::Copy(CMapLine *this, BOOL bUpdateDependencies)
{
  CMapClass *v3; // eax
  CMapClass *v4; // esi

  v3 = (CMapClass *)operator new(nSize: 0x220u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    CMapClass::CMapClass(this: v3);
    v4->__vftable = (CMapClass_vtbl *)&CMapHelper::`vftable';
    v4->__vftable = (CMapClass_vtbl *)&CMapLine::`vftable';
    LOBYTE(v4[1].m_BoundingBox.bmins.z) = 0;
    LOBYTE(v4[1].__vftable) = 0;
    LOBYTE(v4[2].m_Origin.y) = 0;
    LOBYTE(v4[1].m_Dependents.m_pElements) = 0;
    v4[2].m_Render2DBox.bmins.y = 0.0;
    v4[2].m_Render2DBox.bmins.z = 0.0;
  }
  else
  {
    v4 = nullptr;
  }
  if ( v4 != nullptr )
    v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10132E30
// Name: class CMapClass __near * CMapLine_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__cdecl CMapLine_CreateObject()
{
  CMapClass *v0; // eax
  CMapClass *v1; // esi

  v0 = (CMapClass *)operator new(nSize: 0x220u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  CMapClass::CMapClass(this: v0);
  v1->__vftable = (CMapClass_vtbl *)&CMapHelper::`vftable';
  v1->__vftable = (CMapClass_vtbl *)&CMapLine::`vftable';
  LOBYTE(v1[1].m_BoundingBox.bmins.z) = 0;
  LOBYTE(v1[1].__vftable) = 0;
  LOBYTE(v1[2].m_Origin.y) = 0;
  LOBYTE(v1[1].m_Dependents.m_pElements) = 0;
  v1[2].m_Render2DBox.bmins.y = 0.0;
  v1[2].m_Render2DBox.bmins.z = 0.0;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10132EE0
// Name: public: static class CMapClass __near * CMapLine::Create(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapLine *__cdecl CMapLine::Create(CHelperInfo *pHelperInfo, CMapEntity *pParent)
{
  const char *v3; // edi
  char **m_pMemory; // ecx
  char **v5; // edx
  int m_Size; // eax
  const char *v7; // ebx
  CMapLine *v8; // esi
  CMapLine *v9; // eax
  char chRed; // [esp+10h] [ebp-1Ch]
  char chGreen; // [esp+14h] [ebp-18h]
  char chBlue; // [esp+18h] [ebp-14h]
  const char *pszStartKey; // [esp+1Ch] [ebp-10h]
  const char *pszStartValueKey; // [esp+34h] [ebp+8h]

  v3 = nullptr;
  chRed = -1;
  chGreen = -1;
  chBlue = -1;
  if ( pHelperInfo->m_Parameters.m_Size > 0 && *pHelperInfo->m_Parameters.m_Memory.m_pMemory != nullptr )
    chRed = atoi(nptr: *(const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory);
  if ( pHelperInfo->m_Parameters.m_Size > 1 )
  {
    m_pMemory = pHelperInfo->m_Parameters.m_Memory.m_pMemory;
    if ( m_pMemory[1] != nullptr )
      chGreen = atoi(nptr: m_pMemory[1]);
  }
  if ( pHelperInfo->m_Parameters.m_Size > 2 )
  {
    v5 = pHelperInfo->m_Parameters.m_Memory.m_pMemory;
    if ( v5[2] != nullptr )
      chBlue = atoi(nptr: v5[2]);
  }
  m_Size = pHelperInfo->m_Parameters.m_Size;
  if ( m_Size > 3 )
    pszStartKey = *((const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 3);
  else
    pszStartKey = nullptr;
  if ( m_Size > 4 )
    pszStartValueKey = *((const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 4);
  else
    pszStartValueKey = nullptr;
  if ( m_Size > 5 )
    v7 = *((const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 5);
  else
    v7 = nullptr;
  if ( m_Size > 6 )
    v3 = *((const char **)pHelperInfo->m_Parameters.m_Memory.m_pMemory + 6);
  v8 = nullptr;
  if ( pszStartKey == nullptr || pszStartValueKey == nullptr )
    return nullptr;
  v9 = (CMapLine *)operator new(nSize: 0x220u);
  if ( v9 != nullptr )
    v8 = CMapLine::CMapLine(this: v9, pszStartKey, pszStartValueKey, pszEndKey: v7, pszEndValueKey: v3);
  v8->SetRenderColor_2(this: v8, a2: chRed, a3: chGreen, a4: chBlue);
  if ( v7 == nullptr || v3 == nullptr )
    v8->m_pEndEntity = pParent;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10133050
// Name: public: virtual void CMapLine::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapLine::Render3D(CMapLine *this@<ecx>, int a2@<ebx>, int a3@<edi>, CRender3D *pRender)
{
  IMatRenderContext *v5; // edi
  IMesh *v6; // ebx
  unsigned __int8 r; // al
  unsigned __int8 g; // cl
  unsigned __int8 b; // dl
  unsigned int v10; // esi
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-210h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1ECh] [ebp-28h]
  Vector End; // [esp+1F0h] [ebp-24h] BYREF
  Vector Start; // [esp+1FCh] [ebp-18h] BYREF
  int v16; // [esp+210h] [ebp-4h]

  if ( this->m_pStartEntity != nullptr && this->m_pEndEntity != nullptr )
  {
    CRender3D::BeginRenderHitTarget(this: pRender, pObject: (CMapInstance *)this, uHandle: 0);
    CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
    ((void (__thiscall *)(CMapEntity *, Vector *, int, int))this->m_pStartEntity->GetOrigin)(
      a1: this->m_pStartEntity,
      a2: &Start,
      a3,
      a4: a2);
    this->m_pEndEntity->GetOrigin(this: this->m_pEndEntity, a2: &End);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    v16 = 0;
    v5 = materials->GetRenderContext(this: materials);
    pRenderContext.m_pObject = v5;
    LOBYTE(v16) = 1;
    if ( v5 != nullptr )
      v5->BeginRender(this: v5);
    LOBYTE(v16) = 2;
    v6 = v5->GetDynamicMesh(this: v5, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    meshBuilder.m_pMesh = v6;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v6->SetPrimitiveType(this: v6, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 2, a3: 2, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v6->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 2;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v6, nMaxVertexCount: 2, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    if ( this->IsSelected(this) )
    {
      r = -1;
      g = -1;
      b = 0;
    }
    else
    {
      r = this->r;
      g = this->g;
      b = this->b;
    }
    v10 = b | ((g | ((r | 0xFFFFFF00) << 8)) << 8);
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v10;
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = Start;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v10;
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = End;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v6->Draw_2(this: v6, a2: -1, a3: 0);
    CRender3D::EndRenderHitTarget(this: pRender, a2: (int)v5);
    CRender::PopRenderMode(this: pRender);
    LOBYTE(v16) = 3;
    v5->EndRender(this: v5);
    LOBYTE(v16) = 0;
    v5->Release(this: v5);
    v16 = -1;
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013DBD0
// Name: public: virtual int CMapLine::SerializeMAP(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
CBaseTool *__thiscall CMapLine::SerializeMAP(CMapClass *this, int nHitData, bool bAttachObject)
{
  return nullptr;
}
