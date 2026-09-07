// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/cmaterialdict.cpp
// Functions: 11
// ============================================================

#include "materialsystem\cmaterialdict.h"

//------------------------------------------------------------------------------
// Address: 0x1001E610
// Name: protected: static bool CMaterialDict::MaterialLessFunc(struct CMaterialDict::MaterialLookup_t const __near &,struct CMaterialDict::MaterialLookup_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CMaterialDict::MaterialLessFunc(
        const CMaterialDict::MaterialLookup_t *src1,
        const CMaterialDict::MaterialLookup_t *src2)
{
  bool result; // al

  result = src1->m_bManuallyCreated;
  if ( result == src2->m_bManuallyCreated )
    return src1->m_Name.m_Id < src2->m_Name.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001E630
// Name: protected: static bool CMaterialDict::MissingMaterialLessFunc(struct CMaterialDict::MissingMaterial_t const __near &,struct CMaterialDict::MissingMaterial_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CMaterialDict::MissingMaterialLessFunc(
        const CMaterialDict::MissingMaterial_t *src1,
        const CMaterialDict::MissingMaterial_t *src2)
{
  return src1->m_Name.m_Id < src2->m_Name.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x10020450
// Name: public: void CMaterialDict::AddMaterialToMaterialList(class IMaterialInternal __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialDict::AddMaterialToMaterialList(CMaterialDict *this, IMaterialInternal *pMaterial)
{
  IMaterialInternal *v2; // esi
  IMaterialInternal_vtbl *v3; // edx
  const char *(__thiscall *GetName)(struct IMaterialInternal *); // eax
  const char *v6; // eax
  bool (__thiscall *IsManuallyCreated)(IMaterialInternal *); // eax
  CMaterialDict::MaterialLookup_t lookup; // [esp+8h] [ebp-8h] BYREF

  v2 = pMaterial;
  v3 = pMaterial->__vftable;
  lookup.m_Name.m_Id = -1;
  GetName = v3->GetName;
  lookup.m_pMaterial = pMaterial;
  v6 = GetName(this: pMaterial);
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pMaterial + 1, pStr: v6);
  IsManuallyCreated = v2->IsManuallyCreated;
  lookup.m_Name.m_Id = HIWORD(pMaterial);
  lookup.m_bManuallyCreated = IsManuallyCreated(this: v2);
  CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::Insert(
    this: &this->m_MaterialDict,
    insert: &lookup);
}

//------------------------------------------------------------------------------
// Address: 0x100204B0
// Name: public: void CMaterialDict::RemoveMaterialFromMaterialList(class IMaterialInternal __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialDict::RemoveMaterialFromMaterialList(CMaterialDict *this, IMaterialInternal *pMaterial)
{
  unsigned __int16 Inorder; // si
  unsigned __int16 v4; // ax
  int v5; // eax

  Inorder = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_MaterialDict);
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      v4 = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::NextInorder(
             this: &this->m_MaterialDict,
             i: Inorder);
      if ( this->m_MaterialDict.m_Elements.m_pMemory[Inorder].m_Data.m_pMaterial == pMaterial )
        break;
      Inorder = v4;
      if ( v4 == 0xFFFF )
        return;
    }
    if ( Inorder != 0xFFFF )
    {
      CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::Unlink(
        this: &this->m_MaterialDict,
        elem: Inorder);
      v5 = Inorder;
      this->m_MaterialDict.m_Elements.m_pMemory[v5].m_Left = Inorder;
      this->m_MaterialDict.m_Elements.m_pMemory[v5].m_Right = this->m_MaterialDict.m_FirstFree;
      --this->m_MaterialDict.m_NumElements;
      this->m_MaterialDict.m_FirstFree = Inorder;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020540
// Name: public: class IMaterialInternal __near * CMaterialDict::AddMaterial(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMaterial *__thiscall CMaterialDict::AddMaterial(CMaterialDict *this, const char *pName, const char *pTextureGroupName)
{
  CMaterial *Material; // esi
  CMaterial_vtbl *v5; // eax
  const char *(__thiscall *GetName)(struct CMaterial *); // edx
  const char *v7; // eax
  IMaterialInternal v8; // edx
  CMaterialDict::MaterialLookup_t insert; // [esp+8h] [ebp-8h] BYREF

  Material = IMaterialInternal::CreateMaterial(pMaterialName: pName, pTextureGroupName, pVMTKeyValues: nullptr);
  v5 = Material->__vftable;
  insert.m_Name.m_Id = -1;
  GetName = v5->GetName;
  insert.m_pMaterial = Material;
  v7 = GetName(this: Material);
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pTextureGroupName + 1, pStr: v7);
  v8.__vftable = (IMaterialInternal_vtbl *)Material->__vftable;
  insert.m_Name.m_Id = HIWORD(pTextureGroupName);
  insert.m_bManuallyCreated = v8.IsManuallyCreated(this: Material);
  CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::Insert(
    this: &this->m_MaterialDict,
    &insert);
  return Material;
}

//------------------------------------------------------------------------------
// Address: 0x100205B0
// Name: public: void CMaterialDict::RemoveMaterial(class IMaterialInternal __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialDict::RemoveMaterial(CMaterialDict *this, IMaterialInternal *pMaterial)
{
  CMaterialDict::RemoveMaterialFromMaterialList(this, pMaterial);
  IMaterialInternal::DestroyMaterial(pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x100205D0
// Name: public: class IMaterialInternal __near * CMaterialDict::AddMaterialSubRect(char const __near *,char const __near *,class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CMaterialSubRect *__thiscall CMaterialDict::AddMaterialSubRect(
        CMaterialDict *this,
        CUtlVector<void *,CUtlMemory<void *,int> > *pName,
        CUtlVector<void *,CUtlMemory<void *,int> > *pTextureGroupName,
        KeyValues *pKeyValues,
        KeyValues *pPatchKeyValues)
{
  CMaterialSubRect *MaterialSubRect; // esi
  const char *(__thiscall *GetName)(struct CMaterialSubRect *); // eax
  const char *v8; // eax
  bool (__thiscall *IsManuallyCreated)(struct CMaterialSubRect *); // eax
  CMaterialDict::MaterialLookup_t insert; // [esp+8h] [ebp-8h] BYREF

  MaterialSubRect = IMaterialInternal::CreateMaterialSubRect(
                      pMaterialName: pName,
                      pTextureGroupName,
                      pVMTKeyValues: pKeyValues,
                      pPatchKeyValues,
                      bAssumeCreateFromFile: true);
  GetName = MaterialSubRect->GetName;
  insert.m_Name.m_Id = -1;
  insert.m_pMaterial = MaterialSubRect;
  v8 = GetName(this: MaterialSubRect);
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pPatchKeyValues + 1, pStr: v8);
  IsManuallyCreated = MaterialSubRect->IsManuallyCreated;
  insert.m_Name.m_Id = HIWORD(pPatchKeyValues);
  insert.m_bManuallyCreated = IsManuallyCreated(this: MaterialSubRect);
  CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::Insert(
    this: &this->m_MaterialDict,
    &insert);
  return MaterialSubRect;
}

//------------------------------------------------------------------------------
// Address: 0x10020640
// Name: public: void CMaterialDict::RemoveMaterialSubRect(class IMaterialInternal __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialDict::RemoveMaterialSubRect(CMaterialDict *this, IMaterialInternal *pMaterial)
{
  CMaterialDict::RemoveMaterialFromMaterialList(this, pMaterial);
  IMaterialInternal::DestroyMaterialSubRect(pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x10020660
// Name: protected: void CMaterialDict::RemoveAllMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialDict::RemoveAllMaterials(CMaterialDict *this)
{
  unsigned __int16 Inorder; // di
  unsigned __int16 i; // di
  unsigned __int16 iNext; // [esp+8h] [ebp-8h]
  IMaterialInternal *pMaterial; // [esp+Ch] [ebp-4h]

  Inorder = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_MaterialDict);
  if ( Inorder != 0xFFFF )
  {
    do
    {
      iNext = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::NextInorder(
                this: &this->m_MaterialDict,
                i: Inorder);
      pMaterial = this->m_MaterialDict.m_Elements.m_pMemory[Inorder].m_Data.m_pMaterial;
      if ( ((unsigned __int8 (*)(void))pMaterial->InMaterialPage)() != 0 )
      {
        IMaterialInternal::DestroyMaterialSubRect(pMaterial);
        if ( Inorder != 0xFFFF )
        {
          CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::Unlink(
            this: &this->m_MaterialDict,
            elem: Inorder);
          this->m_MaterialDict.m_Elements.m_pMemory[Inorder].m_Left = Inorder;
          this->m_MaterialDict.m_Elements.m_pMemory[Inorder].m_Right = this->m_MaterialDict.m_FirstFree;
          --this->m_MaterialDict.m_NumElements;
          this->m_MaterialDict.m_FirstFree = Inorder;
        }
      }
      Inorder = iNext;
    }
    while ( iNext != 0xFFFF );
  }
  for ( i = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_MaterialDict);
        i != 0xFFFF;
        i = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_MaterialDict,
              i) )
  {
    IMaterialInternal::DestroyMaterial(pMaterial: this->m_MaterialDict.m_Elements.m_pMemory[i].m_Data.m_pMaterial);
  }
  CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_MaterialDict);
}

//------------------------------------------------------------------------------
// Address: 0x10020750
// Name: public: void CMaterialDict::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialDict::Shutdown(CMaterialDict *this)
{
  CMaterialDict::RemoveAllMaterials(this);
  CUtlRBTree<CMaterialDict::MissingMaterial_t,int,bool (__cdecl *)(CMaterialDict::MissingMaterial_t const &,CMaterialDict::MissingMaterial_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int>,int>>::RemoveAll(this: &this->m_MissingList);
}

//------------------------------------------------------------------------------
// Address: 0x1005AEE0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                             this: _g_pMemAlloc,
                                                                                             a2: m_pMemory,
                                                                                             a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                             this: _g_pMemAlloc,
                                                                                             a2: v7);
  }
}
