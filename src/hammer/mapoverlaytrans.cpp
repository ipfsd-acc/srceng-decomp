// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapoverlaytrans.cpp
// Functions: 14
// ============================================================

#include "hammer\mapoverlaytrans.h"

//------------------------------------------------------------------------------
// Address: 0x1013BBC0
// Name: public: virtual void CMapOverlayTransition::OnAddToWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlayTransition::OnAddToWorld(CMapOverlayTransition *this, CMapWorld *pWorld)
{
  this->OnApply(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013BBD0
// Name: public: virtual class CMapClass __near * CMapOverlayTransition::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapOverlayTransition *__thiscall CMapOverlayTransition::CopyFrom(
        CMapOverlayTransition *this,
        CMapClass *pObject,
        bool bUpdateDependencies)
{
  CMapOverlayTransition *result; // eax

  result = this;
  if ( pObject != nullptr )
    this->m_ShoreData = *(ShoreEntityData_t *)&pObject[1].m_nObjectID;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013BC40
// Name: public: virtual void CMapOverlayTransition::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlayTransition::OnParentKeyChanged(
        CMapOverlayTransition *this,
        const char *szKey,
        const char *szValue)
{
  IEditorTexture *ActiveTexture; // eax

  if ( _V_stricmp(s1: szKey, s2: "material") == 0 )
  {
    ActiveTexture = CTextureSystem::FindActiveTexture(
                      this: &g_Textures,
                      pszInputName: szValue,
                      piIndex: nullptr,
                      bDummy: 1);
    if ( ActiveTexture != nullptr )
      this->m_ShoreData.m_pTexture = ActiveTexture;
  }
  if ( _V_stricmp(s1: szKey, s2: "LengthTexcoordStart") == 0 )
    this->m_ShoreData.m_vecLengthTexcoord.x = atof(nptr: szValue);
  if ( _V_stricmp(s1: szKey, s2: "LengthTexcoordEnd") == 0 )
    this->m_ShoreData.m_vecLengthTexcoord.y = atof(nptr: szValue);
  if ( _V_stricmp(s1: szKey, s2: "WidthTexcoordStart") == 0 )
    this->m_ShoreData.m_vecWidthTexcoord.x = atof(nptr: szValue);
  if ( _V_stricmp(s1: szKey, s2: "WidthTexcoordEnd") == 0 )
    this->m_ShoreData.m_vecWidthTexcoord.y = atof(nptr: szValue);
  if ( _V_stricmp(s1: szKey, s2: "Width1") == 0 )
    this->m_ShoreData.m_flWidths[0] = atof(nptr: szValue);
  if ( _V_stricmp(s1: szKey, s2: "Width2") == 0 )
    this->m_ShoreData.m_flWidths[1] = atof(nptr: szValue);
  if ( _V_stricmp(s1: szKey, s2: "DebugDraw") == 0 )
  {
    this->m_bDebugDraw = true;
    if ( atoi(nptr: szValue) == 0 )
      this->m_bDebugDraw = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013BD80
// Name: public: virtual void CMapOverlayTransition::OnRemoveFromWorld(class CMapWorld __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlayTransition::OnRemoveFromWorld(
        CMapOverlayTransition *this,
        CMapWorld *pWorld,
        bool bNotifyChildren)
{
  CDispShoreManager *ShoreManager; // ebx
  CDispShoreManager_vtbl *v5; // esi
  CMapClass *v6; // eax

  ShoreManager = GetShoreManager();
  v5 = ShoreManager->__vftable;
  v6 = this->GetParent(this);
  v5->RemoveShoreline(this: ShoreManager, a2: (int)v6);
}

//------------------------------------------------------------------------------
// Address: 0x1013BDB0
// Name: public: virtual void CMapOverlayTransition::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlayTransition::Render3D(CMapOverlayTransition *this, CRender3D *pRender)
{
  CDispShoreManager *ShoreManager; // eax
  CDispShoreManager *v4; // eax

  ShoreManager = GetShoreManager();
  ShoreManager->Draw(this: ShoreManager, a2: pRender);
  if ( this->m_bDebugDraw )
  {
    v4 = GetShoreManager();
    v4->DebugDraw(this: v4, a2: pRender);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013BDF0
// Name: public: virtual void CMapOverlayTransition::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlayTransition::CalcBounds(CMapOverlayTransition *this, int bFullUpdate)
{
  CDispShoreManager *ShoreManager; // esi
  CDispShoreManager_vtbl *v4; // ebx
  CMapClass *v5; // eax
  int v6; // ebx
  int v7; // ecx
  float z; // xmm2_4
  float y; // xmm4_4
  float x; // xmm6_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm5_4
  float *v14; // eax
  Vector vecMins; // [esp+Ch] [ebp-18h] BYREF
  Vector vecMaxs; // [esp+18h] [ebp-Ch] BYREF

  CMapClass::CalcBounds(this, bFullUpdate);
  ShoreManager = GetShoreManager();
  v4 = ShoreManager->__vftable;
  v5 = this->GetParent(this);
  v6 = (int)v4->GetShoreline(this: ShoreManager, a2: (int)v5);
  if ( v6 != 0 )
  {
    vecMins.x = 99999.0;
    vecMins.y = 99999.0;
    vecMins.z = 99999.0;
    vecMaxs.x = -99999.0;
    vecMaxs.y = -99999.0;
    vecMaxs.z = -99999.0;
    BoundBox::ResetBounds(this: &this->m_Render2DBox);
    BoundBox::ResetBounds(this: &this->m_CullBox);
    v7 = *(_DWORD *)(v6 + 16);
    if ( v7 > 0 )
    {
      z = vecMins.z;
      y = vecMins.y;
      x = vecMins.x;
      v11 = vecMaxs.z;
      v12 = vecMaxs.y;
      v13 = vecMaxs.x;
      v14 = (float *)(*(_DWORD *)(v6 + 4) + 4);
      do
      {
        if ( x > *(v14 - 1) )
        {
          x = *(v14 - 1);
          vecMins.x = x;
        }
        if ( x > v14[2] )
        {
          x = v14[2];
          vecMins.x = x;
        }
        if ( *(v14 - 1) > v13 )
        {
          v13 = *(v14 - 1);
          vecMaxs.x = v13;
        }
        if ( v14[2] > v13 )
        {
          v13 = v14[2];
          vecMaxs.x = v13;
        }
        if ( y > *v14 )
        {
          y = *v14;
          vecMins.y = *v14;
        }
        if ( y > v14[3] )
        {
          y = v14[3];
          vecMins.y = y;
        }
        if ( *v14 > v12 )
        {
          v12 = *v14;
          vecMaxs.y = *v14;
        }
        if ( v14[3] > v12 )
        {
          v12 = v14[3];
          vecMaxs.y = v12;
        }
        if ( z > v14[1] )
        {
          z = v14[1];
          vecMins.z = z;
        }
        if ( z > v14[4] )
        {
          z = v14[4];
          vecMins.z = z;
        }
        if ( v14[1] > v11 )
        {
          v11 = v14[1];
          vecMaxs.z = v11;
        }
        if ( v14[4] > v11 )
        {
          v11 = v14[4];
          vecMaxs.z = v11;
        }
        v14 += 77;
        --v7;
      }
      while ( v7 != 0 );
    }
    BoundBox::UpdateBounds(this: &this->m_Render2DBox, mins: &vecMins, maxs: &vecMaxs);
    this->m_CullBox.bmins.x = this->m_Render2DBox.bmins.x;
    this->m_CullBox.bmins.y = this->m_Render2DBox.bmins.y;
    this->m_CullBox.bmins.z = this->m_Render2DBox.bmins.z;
    this->m_CullBox.bmaxs.x = this->m_Render2DBox.bmaxs.x;
    this->m_CullBox.bmaxs.y = this->m_Render2DBox.bmaxs.y;
    this->m_CullBox.bmaxs.z = this->m_Render2DBox.bmaxs.z;
    this->m_BoundingBox.bmins.x = this->m_CullBox.bmins.x;
    this->m_BoundingBox.bmins.y = this->m_CullBox.bmins.y;
    this->m_BoundingBox.bmins.z = this->m_CullBox.bmins.z;
    this->m_BoundingBox.bmaxs.x = this->m_CullBox.bmaxs.x;
    this->m_BoundingBox.bmaxs.y = this->m_CullBox.bmaxs.y;
    this->m_BoundingBox.bmaxs.z = this->m_CullBox.bmaxs.z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013BFE0
// Name: public: virtual enum ChunkFileResult_t CMapOverlayTransition::SaveVMF(class CChunkFile __near *,class CSaveInfo __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapOverlayTransition::SaveVMF(
        CMapOverlayTransition *this,
        CChunkFile *pFile,
        CChunkFile *pSaveInfo)
{
  ChunkFileResult_t v4; // ebx
  CDispShoreManager *ShoreManager; // eax
  int v6; // eax
  int v7; // edi
  int v8; // esi
  int v9; // ebx
  CMapOverlay *v10; // ecx
  ChunkFileResult_t eResult; // [esp+Ch] [ebp-4h]

  v4 = CChunkFile::BeginChunk(this: pFile, pszChunkName: "overlaytransition");
  eResult = v4;
  this->m_nShorelineId = (int)this->GetParent(this);
  ShoreManager = GetShoreManager();
  v6 = (int)ShoreManager->GetShoreline(this: ShoreManager, a2: this->m_nShorelineId);
  v7 = v6;
  if ( v6 != 0 && *(int *)(v6 + 56) > 0 )
  {
    v8 = 0;
    v9 = *(_DWORD *)(v6 + 56);
    do
    {
      v10 = (CMapOverlay *)(v8 + *(_DWORD *)(v7 + 44));
      if ( v10 != nullptr )
        CMapOverlay::SaveDataToVMF(this: v10, pFile, pSaveInfo);
      v8 += 532;
      --v9;
    }
    while ( v9 != 0 );
    v4 = eResult;
  }
  if ( v4 != ChunkFile_Ok )
    return v4;
  else
    return CChunkFile::EndChunk(this: pFile);
}

//------------------------------------------------------------------------------
// Address: 0x1013C070
// Name: public: CMapOverlayTransition::CMapOverlayTransition(void)
// Source: json
//------------------------------------------------------------------------------
CMapOverlayTransition *__thiscall CMapOverlayTransition::CMapOverlayTransition(CMapOverlayTransition *this)
{
  CMapFace **m_pMemory; // ecx
  CMapFace **v3; // ecx
  CMapEntity **v4; // ecx

  CMapClass::CMapClass(this);
  this->__vftable = (CMapOverlayTransition_vtbl *)&CMapHelper::`vftable';
  this->__vftable = (CMapOverlayTransition_vtbl *)&CMapOverlayTransition::`vftable';
  this->m_aFaceCache1.m_Memory.m_pMemory = nullptr;
  this->m_aFaceCache1.m_Memory.m_nAllocationCount = 0;
  this->m_aFaceCache1.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_aFaceCache1.m_Memory.m_pMemory;
  this->m_aFaceCache1.m_Size = 0;
  this->m_aFaceCache1.m_pElements = m_pMemory;
  this->m_aFaceCache2.m_Memory.m_pMemory = nullptr;
  this->m_aFaceCache2.m_Memory.m_nAllocationCount = 0;
  this->m_aFaceCache2.m_Memory.m_nGrowSize = 0;
  v3 = this->m_aFaceCache2.m_Memory.m_pMemory;
  this->m_aFaceCache2.m_Size = 0;
  this->m_aFaceCache2.m_pElements = v3;
  this->m_aOverlayChildren.m_Memory.m_pMemory = nullptr;
  this->m_aOverlayChildren.m_Memory.m_nAllocationCount = 0;
  this->m_aOverlayChildren.m_Memory.m_nGrowSize = 0;
  v4 = this->m_aOverlayChildren.m_Memory.m_pMemory;
  this->m_aOverlayChildren.m_Size = 0;
  this->m_aOverlayChildren.m_pElements = v4;
  this->m_ShoreData.m_pTexture = nullptr;
  this->m_ShoreData.m_vecLengthTexcoord.x = 0.0;
  this->m_ShoreData.m_vecLengthTexcoord.y = 0.0;
  this->m_ShoreData.m_vecWidthTexcoord.x = 0.0;
  this->m_ShoreData.m_vecWidthTexcoord.y = 0.0;
  this->m_ShoreData.m_flWidths[0] = 0.0;
  this->m_ShoreData.m_flWidths[1] = 0.0;
  this->m_bIsWater = true;
  this->m_aFaceCache1.m_Size = 0;
  if ( this->m_aFaceCache1.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aFaceCache1.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_aFaceCache1.m_Memory.m_pMemory);
      this->m_aFaceCache1.m_Memory.m_pMemory = nullptr;
    }
    this->m_aFaceCache1.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aFaceCache1.m_pElements = this->m_aFaceCache1.m_Memory.m_pMemory;
  this->m_aFaceCache2.m_Size = 0;
  if ( this->m_aFaceCache2.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aFaceCache2.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_aFaceCache2.m_Memory.m_pMemory);
      this->m_aFaceCache2.m_Memory.m_pMemory = nullptr;
    }
    this->m_aFaceCache2.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aFaceCache2.m_pElements = this->m_aFaceCache2.m_Memory.m_pMemory;
  this->m_bDebugDraw = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013C1F0
// Name: public: virtual char const __near * CMapOverlayTransition::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapOverlayTransition::GetDescription(CMapOverlayTransition *this)
{
  return "Overlay Transition";
}

//------------------------------------------------------------------------------
// Address: 0x1013C200
// Name: public: virtual CMapOverlayTransition::~CMapOverlayTransition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapOverlayTransition::~CMapOverlayTransition(CMapOverlayTransition *this)
{
  CUtlVector<CMapEntity *,CUtlMemory<CMapEntity *,int> > *p_m_aOverlayChildren; // esi
  CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > *p_m_aFaceCache2; // esi
  CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > *p_m_aFaceCache1; // esi

  this->__vftable = (CMapOverlayTransition_vtbl *)&CMapOverlayTransition::`vftable';
  p_m_aOverlayChildren = &this->m_aOverlayChildren;
  this->m_aOverlayChildren.m_Size = 0;
  if ( this->m_aOverlayChildren.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aOverlayChildren->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aOverlayChildren->m_Memory.m_pMemory);
      p_m_aOverlayChildren->m_Memory.m_pMemory = nullptr;
    }
    p_m_aOverlayChildren->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aOverlayChildren->m_pElements = p_m_aOverlayChildren->m_Memory.m_pMemory;
  if ( p_m_aOverlayChildren->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aOverlayChildren->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aOverlayChildren->m_Memory.m_pMemory);
      p_m_aOverlayChildren->m_Memory.m_pMemory = nullptr;
    }
    p_m_aOverlayChildren->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aFaceCache2 = &this->m_aFaceCache2;
  this->m_aFaceCache2.m_Size = 0;
  if ( this->m_aFaceCache2.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aFaceCache2->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aFaceCache2->m_Memory.m_pMemory);
      p_m_aFaceCache2->m_Memory.m_pMemory = nullptr;
    }
    this->m_aFaceCache2.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aFaceCache2.m_pElements = this->m_aFaceCache2.m_Memory.m_pMemory;
  if ( this->m_aFaceCache2.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aFaceCache2->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aFaceCache2->m_Memory.m_pMemory);
      p_m_aFaceCache2->m_Memory.m_pMemory = nullptr;
    }
    this->m_aFaceCache2.m_Memory.m_nAllocationCount = 0;
  }
  p_m_aFaceCache1 = &this->m_aFaceCache1;
  this->m_aFaceCache1.m_Size = 0;
  if ( this->m_aFaceCache1.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aFaceCache1->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aFaceCache1->m_Memory.m_pMemory);
      p_m_aFaceCache1->m_Memory.m_pMemory = nullptr;
    }
    this->m_aFaceCache1.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aFaceCache1.m_pElements = this->m_aFaceCache1.m_Memory.m_pMemory;
  if ( this->m_aFaceCache1.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aFaceCache1->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aFaceCache1->m_Memory.m_pMemory);
      p_m_aFaceCache1->m_Memory.m_pMemory = nullptr;
    }
    this->m_aFaceCache1.m_Memory.m_nAllocationCount = 0;
  }
  CMapClass::~CMapClass(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013C340
// Name: public: static class CMapClass __near * CMapOverlayTransition::Create(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapOverlayTransition *__cdecl CMapOverlayTransition::Create()
{
  CMapOverlayTransition *v0; // eax

  v0 = (CMapOverlayTransition *)operator new(nSize: 0x13Cu);
  if ( v0 != nullptr )
    return CMapOverlayTransition::CMapOverlayTransition(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1013C3A0
// Name: public: virtual class CMapClass __near * CMapOverlayTransition::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapOverlayTransition *__thiscall CMapOverlayTransition::Copy(CMapOverlayTransition *this, BOOL bUpdateDependencies)
{
  CMapOverlayTransition *v3; // eax
  CMapOverlayTransition *v4; // esi

  v3 = (CMapOverlayTransition *)operator new(nSize: 0x13Cu);
  if ( v3 != nullptr )
    v4 = CMapOverlayTransition::CMapOverlayTransition(this: v3);
  else
    v4 = nullptr;
  if ( v4 != nullptr )
    v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1013C450
// Name: private: bool CMapOverlayTransition::BuildFaceCaches(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapOverlayTransition::BuildFaceCaches(CMapOverlayTransition *this)
{
  int v1; // ebx
  CMapOverlayTransition *v2; // edi
  CMapClass *(__thiscall *GetParent)(CMapClass *); // edx
  void *v4; // eax
  CMapEntity *v5; // eax
  CMapEntity *v6; // edx
  int v7; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v9; // ecx
  void *v10; // edx
  CMapSideList *v11; // eax
  CMapSideList *v12; // edi
  CMapOverlayTransition *v13; // esi
  CMapFace **v14; // edx
  int v15; // edi
  int v16; // eax
  CMapFace **v17; // ecx
  int v18; // eax
  int *v19; // eax
  CMapOverlayTransition *v20; // esi
  int v21; // ecx
  int v22; // edx
  int v23; // edi
  int m_nAllocationCount; // eax
  CMapFace **m_pMemory; // ecx
  int v26; // eax
  int *v27; // eax
  int v28; // edi
  int v29; // eax
  CMapFace **v30; // ecx
  int v31; // eax
  int *v32; // eax
  CUtlReference<CMapClass> *m_pHead; // [esp+8h] [ebp-30h] BYREF
  CUtlReference<CMapClass> *v35; // [esp+Ch] [ebp-2Ch]
  void *inptr; // [esp+10h] [ebp-28h]
  CMapEntity *pEntity; // [esp+14h] [ebp-24h]
  int nFaceCount; // [esp+18h] [ebp-20h]
  int m_Size; // [esp+1Ch] [ebp-1Ch]
  int pos; // [esp+20h] [ebp-18h]
  CMapOverlayTransition *v41; // [esp+24h] [ebp-14h]
  CMapSideList *pSideList; // [esp+28h] [ebp-10h]
  int v43; // [esp+34h] [ebp-4h]

  v1 = 0;
  v2 = this;
  GetParent = this->GetParent;
  v41 = this;
  v4 = (void *)((int (__fastcall *)(CMapOverlayTransition *))GetParent)(a1: this);
  v5 = (CMapEntity *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CMapClass `RTTI Type Descriptor',
                       TargetType: &CMapEntity `RTTI Type Descriptor',
                       isReference: 0);
  v6 = v5;
  pEntity = v5;
  if ( v5 != nullptr )
  {
    v7 = 0;
    pos = 0;
    if ( v5->m_Children.m_Size > 0 )
    {
      while ( 1 )
      {
        m_pObject = v6->m_Children.m_Memory.m_pMemory[v7 >> ((unsigned __int64)*((int *)&v6->m_Children.m_Memory + 2) >> 27)][v7 & ((32 * *((_DWORD *)&v6->m_Children.m_Memory + 2)) >> 5)].m_pObject;
        if ( m_pObject != nullptr )
        {
          inptr = v6->m_Children.m_Memory.m_pMemory[v7 >> ((unsigned __int64)*((int *)&v6->m_Children.m_Memory + 2) >> 27)][v7 & ((32 * *((_DWORD *)&v6->m_Children.m_Memory + 2)) >> 5)].m_pObject;
          m_pHead = m_pObject->m_References.m_pHead;
          v9 = m_pObject->m_References.m_pHead;
          if ( v9 != nullptr )
            v9->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
          v35 = nullptr;
          m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
        }
        v10 = inptr;
        v43 = -1;
        if ( inptr != nullptr )
        {
          if ( v35 != nullptr )
          {
            v35->m_pNext = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = v35;
          }
          else if ( *((CUtlReference<CMapClass> ***)inptr + 8) == &m_pHead )
          {
            *((_DWORD *)inptr + 8) = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = nullptr;
          }
          v35 = nullptr;
          m_pHead = nullptr;
          inptr = nullptr;
        }
        v11 = (CMapSideList *)__RTDynamicCast(
                                inptr: v10,
                                VfDelta: 0,
                                SrcType: &CMapClass `RTTI Type Descriptor',
                                TargetType: &CMapSideList `RTTI Type Descriptor',
                                isReference: 0);
        v12 = v11;
        pSideList = v11;
        if ( v11 == nullptr )
          goto LABEL_46;
        if ( _V_stricmp(s1: "sides", s2: v11->m_szKeyName) != 0 )
        {
          if ( _V_stricmp(s1: "sides2", s2: v12->m_szKeyName) == 0 )
          {
            m_Size = v12->m_Faces.m_Size;
            if ( m_Size > 0 )
            {
              do
              {
                v20 = v41;
                v21 = (int)v12->m_Faces.m_Memory.m_pMemory[v1];
                if ( v41->m_bIsWater )
                {
                  if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(v21 + 416) + 92))(a1: *(_DWORD *)(v21 + 416)) != 0 )
                  {
                    v22 = (int)v12->m_Faces.m_Memory.m_pMemory[v1];
                    v23 = v20->m_aFaceCache2.m_Size;
                    m_nAllocationCount = v20->m_aFaceCache2.m_Memory.m_nAllocationCount;
                    nFaceCount = v22;
                    if ( v23 + 1 > m_nAllocationCount )
                      CUtlMemory<CVisGroup *,int>::Grow(
                        this: (CUtlMemory<CCullTreeNode *,int> *)&v20->m_aFaceCache2,
                        num: v23 - m_nAllocationCount + 1);
                    ++v20->m_aFaceCache2.m_Size;
                    m_pMemory = v20->m_aFaceCache2.m_Memory.m_pMemory;
                    v26 = v20->m_aFaceCache2.m_Size - v23 - 1;
                    v20->m_aFaceCache2.m_pElements = m_pMemory;
                    if ( v26 > 0 )
                      _V_memmove(dest: &m_pMemory[v23 + 1], src: &m_pMemory[v23], count: 4 * v26);
                    v27 = (int *)&v20->m_aFaceCache2.m_Memory.m_pMemory[v23];
                    v12 = pSideList;
                    if ( v27 != nullptr )
                      *v27 = nFaceCount;
                  }
                }
                else
                {
                  v28 = v41->m_aFaceCache2.m_Size;
                  v29 = v41->m_aFaceCache2.m_Memory.m_nAllocationCount;
                  nFaceCount = v21;
                  if ( v28 + 1 > v29 )
                    CUtlMemory<CVisGroup *,int>::Grow(
                      this: (CUtlMemory<CCullTreeNode *,int> *)&v41->m_aFaceCache2,
                      num: v28 - v29 + 1);
                  ++v20->m_aFaceCache2.m_Size;
                  v30 = v20->m_aFaceCache2.m_Memory.m_pMemory;
                  v31 = v20->m_aFaceCache2.m_Size - v28 - 1;
                  v20->m_aFaceCache2.m_pElements = v30;
                  if ( v31 > 0 )
                    _V_memmove(dest: &v30[v28 + 1], src: &v30[v28], count: 4 * v31);
                  v32 = (int *)&v20->m_aFaceCache2.m_Memory.m_pMemory[v28];
                  v12 = pSideList;
                  if ( v32 != nullptr )
                    *v32 = nFaceCount;
                }
                ++v1;
              }
              while ( v1 < m_Size );
            }
            goto LABEL_45;
          }
        }
        else
        {
          nFaceCount = v12->m_Faces.m_Size;
          if ( nFaceCount > 0 )
          {
            v13 = v41;
            while ( 1 )
            {
              v14 = v12->m_Faces.m_Memory.m_pMemory;
              v15 = v13->m_aFaceCache1.m_Size;
              m_Size = (int)v14[v1];
              v16 = v13->m_aFaceCache1.m_Memory.m_nAllocationCount;
              if ( v15 + 1 > v16 )
                CUtlMemory<CVisGroup *,int>::Grow(
                  this: (CUtlMemory<CCullTreeNode *,int> *)&v13->m_aFaceCache1,
                  num: v15 - v16 + 1);
              ++v13->m_aFaceCache1.m_Size;
              v17 = v13->m_aFaceCache1.m_Memory.m_pMemory;
              v18 = v13->m_aFaceCache1.m_Size - v15 - 1;
              v13->m_aFaceCache1.m_pElements = v17;
              if ( v18 > 0 )
                _V_memmove(dest: &v17[v15 + 1], src: &v17[v15], count: 4 * v18);
              v19 = (int *)&v13->m_aFaceCache1.m_Memory.m_pMemory[v15];
              if ( v19 != nullptr )
                *v19 = m_Size;
              if ( ++v1 >= nFaceCount )
                break;
              v12 = pSideList;
            }
LABEL_45:
            v1 = 0;
          }
        }
LABEL_46:
        v6 = pEntity;
        v7 = pos + 1;
        pos = v7;
        if ( v7 >= pEntity->m_Children.m_Size )
        {
          v2 = v41;
          return v2->m_aFaceCache1.m_Size > 0 && v2->m_aFaceCache2.m_Size > 0;
        }
      }
    }
  }
  return v2->m_aFaceCache1.m_Size > 0 && v2->m_aFaceCache2.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013C7D0
// Name: public: virtual bool CMapOverlayTransition::OnApply(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapOverlayTransition::OnApply(CMapOverlayTransition *this)
{
  CDispShoreManager *ShoreManager; // eax
  CDispShoreManager *v3; // eax
  CDispShoreManager *v4; // eax
  int v5; // eax
  IEditorTexture *m_pTexture; // ecx
  double y; // st7
  CDispShoreManager *v8; // eax
  CDispShoreManager *v9; // eax

  if ( this->m_bIsWater )
  {
    ShoreManager = GetShoreManager();
    if ( ShoreManager->Init(this: ShoreManager) != 0 )
    {
      if ( CMapOverlayTransition::BuildFaceCaches(this) )
      {
        this->m_nShorelineId = (int)this->GetParent(this);
        v3 = GetShoreManager();
        v3->AddShoreline(this: v3, a2: this->m_nShorelineId);
        v4 = GetShoreManager();
        v5 = (int)v4->GetShoreline(this: v4, a2: this->m_nShorelineId);
        m_pTexture = this->m_ShoreData.m_pTexture;
        *(float *)(v5 + 72) = this->m_ShoreData.m_vecLengthTexcoord.x;
        y = this->m_ShoreData.m_vecLengthTexcoord.y;
        *(_DWORD *)(v5 + 68) = m_pTexture;
        *(float *)(v5 + 76) = y;
        *(float *)(v5 + 80) = this->m_ShoreData.m_vecWidthTexcoord.x;
        *(float *)(v5 + 84) = this->m_ShoreData.m_vecWidthTexcoord.y;
        *(float *)(v5 + 88) = this->m_ShoreData.m_flWidths[0];
        *(float *)(v5 + 92) = this->m_ShoreData.m_flWidths[1];
        v8 = GetShoreManager();
        v8->BuildShoreline(this: v8, a2: this->m_nShorelineId, a3: &this->m_aFaceCache1, a4: &this->m_aFaceCache2);
        CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int>>::Purge(this: &this->m_aFaceCache1);
        CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int>>::Purge(this: &this->m_aFaceCache2);
      }
      v9 = GetShoreManager();
      v9->Shutdown(this: v9);
    }
    this->PostUpdate(this, a2: Notify_Changed);
  }
  return 1;
}
