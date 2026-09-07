// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmeutils/savetodmx.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00552200
// Name: void ConvertMeshToDMX(class CDmeMesh __near *,class CMesh __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConvertMeshToDMX(CDmeMesh *pDmeMeshOut, CDmeMaterial *pMeshIn, bool bForce2DTexcoords)
{
  CDmeMesh *v3; // esi
  CDmeMaterial *v4; // edi
  CDmAttribute *m_pAttribute; // ecx
  int v6; // eax
  CDmeVertexDataBase::StandardFields_t v7; // ecx
  unsigned int v8; // esi
  CMesh *v9; // eax
  int v10; // edx
  CDmeMaterial_vtbl *v11; // ecx
  bool v12; // cc
  void (__thiscall **v13)(struct CDmeMaterial *, CDmAttribute *); // ebx
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CMesh *v16; // ebx
  bool v17; // al
  const char *v18; // eax
  DmElementHandle_t v19; // eax
  CDmElement *v20; // eax
  CDmeFaceSet *v21; // ebx
  int v22; // esi
  int v23; // edi
  int v24; // esi
  int pIndex; // [esp+Ch] [ebp-1Ch]
  int pIndexa; // [esp+Ch] [ebp-1Ch]
  DmAttributeType_t at; // [esp+10h] [ebp-18h]
  float *pFieldData; // [esp+18h] [ebp-10h]
  int *v; // [esp+1Ch] [ebp-Ch]
  int va; // [esp+1Ch] [ebp-Ch]
  int a; // [esp+20h] [ebp-8h]
  CDmeVertexData *pVertexData; // [esp+24h] [ebp-4h]

  v3 = pDmeMeshOut;
  pVertexData = CDmeMesh::FindOrCreateBaseState(this: pDmeMeshOut, pStateName: (int)"bind");
  CDmeMesh::SetCurrentBaseState(this: pDmeMeshOut, pStateName: "bind");
  v4 = pMeshIn;
  CDmeVertexData::AddVertexIndices(this: pVertexData, nIndexCount: (int)pMeshIn->m_Name.m_pAttribute);
  m_pAttribute = pVertexData->m_bFlipVCoordinates.m_pAttribute;
  LOBYTE(pMeshIn) = 0;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, value: (const bool *)&pMeshIn);
  a = 0;
  if ( v4->m_Name.m_Storage.u.CDmElement::m_Id > 0 )
  {
    do
    {
      v = (int *)(*(_DWORD *)v4->m_Id.m_Value + 8 * a);
      v6 = v[1];
      v7 = g_AttribToField[v6];
      switch ( v6 )
      {
        case 0:
        case 2:
        case 6:
        case 7:
        case 12:
        case 16:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
          v8 = 12;
          break;
        case 1:
        case 3:
        case 13:
        case 17:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
          v8 = 16;
          break;
        case 4:
        case 5:
        case 8:
        case 9:
        case 10:
        case 14:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
          v8 = 4;
          break;
        case 11:
        case 15:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
          v8 = 8;
          break;
        default:
          v8 = 0;
          break;
      }
      if ( bForce2DTexcoords && v7 == FIELD_TEXCOORD )
        v8 = 8;
      at = dword_777EB4[v8 >> 2];
      pIndex = CDmeVertexDataBase::CreateField(this: pVertexData, fieldId: v7);
      CDmeVertexDataBase::AddVertexData(this: pVertexData, nFieldIndex: pIndex, nCount: *(_DWORD *)&v4->m_Id.m_Value[8]);
      v9 = (CMesh *)MemAlloc_Alloc(
                      nSize: (unsigned __int64)((v8 >> 2) * *(_DWORD *)&v4->m_Id.m_Value[8]) >> 30 != 0
                    ? -1
                    : 4 * (v8 >> 2) * *(_DWORD *)&v4->m_Id.m_Value[8]);
      v10 = *v;
      v11 = v4->__vftable;
      v12 = *(_DWORD *)&v4->m_Id.m_Value[8] <= 0;
      pFieldData = (float *)v9;
      pMeshIn = (CDmeMaterial *)v9;
      v13 = &v11->OnAttributeChanged + v10;
      va = 0;
      if ( !v12 )
      {
        do
        {
          _V_memcpy(dest: pMeshIn, src: v13, count: v8);
          pMeshIn = (CDmeMaterial *)((char *)pMeshIn + 4 * (v8 >> 2));
          v13 += *(_DWORD *)&v4->m_Id.m_Value[12];
          ++va;
        }
        while ( va < *(_DWORD *)&v4->m_Id.m_Value[8] );
        v9 = (CMesh *)pFieldData;
      }
      CDmeVertexDataBase::SetVertexData(
        this: pVertexData,
        nFieldIndex: pIndex,
        nFirstVertex: 0,
        nCount: *(_DWORD *)&v4->m_Id.m_Value[8],
        valueType: at,
        pData: v9);
      free(pMem: pFieldData);
      CDmeVertexDataBase::SetVertexIndices(
        this: pVertexData,
        nFieldIndex: pIndex,
        nFirstIndex: 0,
        nCount: (int)v4->m_Name.m_pAttribute,
        pIndices: *(const int **)&v4->m_Id.m_Value[4]);
      ++a;
    }
    while ( a < v4->m_Name.m_Storage.u.CDmElement::m_Id );
    v3 = pDmeMeshOut;
  }
  v14 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
          a1: g_pDataModel,
          a2: (CUtlSymbolLarge)CDmeMaterial::m_classType.u.m_Id,
          a3: "material",
          a4: v3->m_fileId,
          a5: nullptr);
  v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
  v16 = (CMesh *)v15;
  if ( v15 == nullptr || (v17 = v15->IsA(this: v15, a2: CDmeMaterial::m_classType), pMeshIn = (CDmeMaterial *)v16, !v17) )
    pMeshIn = nullptr;
  v18 = CUtlString::operator char const *(this: (CUtlString *)&v4->m_ref);
  CDmeMaterial::SetMaterial(this: pMeshIn, pMaterialName: v18);
  v19 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
          a1: g_pDataModel,
          a2: (CUtlSymbolLarge)CDmeFaceSet::m_classType.u.m_Id,
          a3: "faceSet",
          a4: v3->m_fileId,
          a5: nullptr);
  v20 = g_pDataModel->GetElement(this: g_pDataModel, a2: v19);
  v21 = (CDmeFaceSet *)v20;
  if ( v20 == nullptr || !v20->IsA(this: v20, a2: CDmeFaceSet::m_classType) )
    v21 = nullptr;
  pIndexa = 4 * ((int)v4->m_Name.m_pAttribute / 3);
  CDmeFaceSet::AddIndices(this: v21, nCount: pIndexa);
  v22 = 0;
  if ( pIndexa > 0 )
  {
    v23 = 2;
    do
    {
      CDmeFaceSet::SetIndex(this: v21, i: v23 - 2, nValue: v22);
      v24 = v22 + 1;
      CDmeFaceSet::SetIndex(this: v21, i: v23 - 1, nValue: v24++);
      CDmeFaceSet::SetIndex(this: v21, i: v23, nValue: v24);
      v22 = v24 + 1;
      CDmeFaceSet::SetIndex(this: v21, i: v23 + 1, nValue: -1);
      v23 += 4;
    }
    while ( v23 - 2 < pIndexa );
  }
  CDmeFaceSet::SetMaterial(this: v21, pMaterial: pMeshIn);
  CDmeMesh::AddFaceSet(this: pDmeMeshOut, faceSet: (int)v21);
}

//------------------------------------------------------------------------------
// Address: 0x00552590
// Name: bool SaveMeshesToDMX(class CUtlVector<class CMesh __near *,class CUtlMemory<class CMesh __near *,int>> __near &,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SaveMeshesToDMX(
        CUtlVector<CMesh *,CUtlMemory<CMesh *,int> > *inputMeshes,
        const char *pDMXFile,
        bool bForce2DTexcoords)
{
  DmFileId_t v3; // edi
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CDmElement *v7; // ebx
  DmElementHandle_t v8; // eax
  CDmElement *v9; // eax
  CDmeModel *v10; // esi
  CDmeModel *v11; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v13; // eax
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmeDag *v16; // esi
  CDmeDag *v17; // edi
  DmElementHandle_t v18; // eax
  CDmElement *v19; // eax
  CDmeMesh *v20; // esi
  int v21; // edi
  bool guard_4; // [esp+10h] [ebp-10h]
  int nMeshes; // [esp+14h] [ebp-Ch]
  int m; // [esp+18h] [ebp-8h] BYREF
  CDmeModel *v26; // [esp+1Ch] [ebp-4h]

  guard_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  v3 = g_pDataModel->FindOrCreateFileId(this: g_pDataModel, a2: pDMXFile);
  v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
         a3: "root",
         a4: v3,
         a5: nullptr);
  v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
  v6 = v5;
  if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
    v7 = v6;
  else
    v7 = nullptr;
  v8 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeModel::m_classType.u.m_Id,
         a3: "model",
         a4: v3,
         a5: nullptr);
  v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v8);
  v10 = (CDmeModel *)v9;
  if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmeModel::m_classType) )
  {
    v11 = v10;
    v26 = v10;
    m = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)v10);
  }
  else
  {
    v26 = nullptr;
    v11 = nullptr;
    m = -1;
  }
  Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "skeleton");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v7, pAttributeName: "skeleton", type: AT_FIRST_VALUE_TYPE)) != nullptr )
  {
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (DmElementHandle_t *)&m);
  }
  if ( v11 != nullptr )
    m = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)v11);
  else
    m = -1;
  v13 = CDmElement::FindAttribute(this: v7, pAttributeName: "model");
  if ( v13 != nullptr
    || (v13 = CDmElement::CreateAttribute(this: v7, pAttributeName: "model", type: AT_FIRST_VALUE_TYPE)) != nullptr )
  {
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: v13, value: (DmElementHandle_t *)&m);
  }
  nMeshes = inputMeshes->m_Size;
  m = 0;
  if ( nMeshes > 0 )
  {
    do
    {
      v14 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
              a1: g_pDataModel,
              a2: (CUtlSymbolLarge)CDmeDag::m_classType.u.m_Id,
              a3: "obj",
              a4: v7->m_fileId,
              a5: nullptr);
      v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
      v16 = (CDmeDag *)v15;
      if ( v15 != nullptr && v15->IsA(this: v15, a2: CDmeDag::m_classType) )
        v17 = v16;
      else
        v17 = nullptr;
      v18 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
              a1: g_pDataModel,
              a2: (CUtlSymbolLarge)CDmeMesh::m_classType.u.m_Id,
              a3: "obj",
              a4: v7->m_fileId,
              a5: nullptr);
      v19 = g_pDataModel->GetElement(this: g_pDataModel, a2: v18);
      v20 = (CDmeMesh *)v19;
      if ( v19 == nullptr || !v19->IsA(this: v19, a2: CDmeMesh::m_classType) )
        v20 = nullptr;
      CDmeDag::SetShape(this: v17, pShape: v20);
      CDmeModel::AddJoint(this: v26, pJoint: v17);
      CDmeDag::AddChild(this: v26, pDag: v17);
      v21 = m;
      ConvertMeshToDMX(pDmeMeshOut: v20, pMeshIn: (CDmeMaterial *)inputMeshes->m_Memory.m_pMemory[m], bForce2DTexcoords);
      m = v21 + 1;
    }
    while ( v21 + 1 < nMeshes );
    v11 = v26;
  }
  CDmeModel::CaptureJointsToBaseState(this: v11, pBaseStateName: "bind");
  if ( g_pDataModel->SaveToFile(this: g_pDataModel, a2: pDMXFile, a3: nullptr, a4: nullptr, a5: "model", a6: v7) )
  {
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: guard_4);
    return 1;
  }
  else
  {
    _Warning(a1: "SaveMeshesToDMX: SaveToFile \"%s\" failed!\n", pDMXFile);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: guard_4);
    return 0;
  }
}
