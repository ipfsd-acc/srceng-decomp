// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_slideshow_display.cpp
// Functions: 13
// ============================================================

#include "game\client\c_slideshow_display.h"

//------------------------------------------------------------------------------
// Address: 0x1008A010
// Name: public: virtual class ClientClass __near * C_SlideshowDisplay::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_SlideshowDisplay::GetClientClass(C_SlideshowDisplay *this)
{
  return &__g_C_SlideshowDisplayClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1008A1B0
// Name: public: virtual void C_SlideshowDisplay::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SlideshowDisplay::Spawn(C_SlideshowDisplay *this)
{
  void (__thiscall *SetNextClientThink)(C_BaseEntity *, float); // edx

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  SetNextClientThink = this->SetNextClientThink;
  this->m_NextSlideTime = 0.0;
  ((void (__thiscall *)(C_SlideshowDisplay *, int))SetNextClientThink)(a1: this, a2: -996040704);
}

//------------------------------------------------------------------------------
// Address: 0x1008A1E0
// Name: public: int C_SlideshowDisplay::GetMaterialIndex(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_SlideshowDisplay::GetMaterialIndex(C_SlideshowDisplay *this, int iSlideIndex)
{
  SlideMaterialList_t **m_pMemory; // eax

  m_pMemory = this->m_SlideMaterialLists.m_Memory.m_pMemory;
  if ( *m_pMemory != nullptr )
    return (*m_pMemory)->iSlideMaterials.m_Memory.m_pMemory[iSlideIndex];
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008A210
// Name: public: int C_SlideshowDisplay::NumMaterials(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_SlideshowDisplay::NumMaterials(C_SlideshowDisplay *this)
{
  SlideMaterialList_t **m_pMemory; // eax

  m_pMemory = this->m_SlideMaterialLists.m_Memory.m_pMemory;
  if ( *m_pMemory != nullptr )
    return (*m_pMemory)->iSlideMaterials.m_Size;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008A230
// Name: public: virtual void C_SlideshowDisplay::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall C_SlideshowDisplay::ClientThink(C_SlideshowDisplay *this)
{
  IUniformRandomStream *v2; // ecx
  double v3; // st7
  IUniformRandomStream *m_Index; // ecx
  int v5; // edi
  float m_fMinSlideTime; // eax
  int v7; // eax
  bool v8; // cc
  float m_NextSlideTime; // ebx
  int v10; // eax
  bool v11; // zf
  float v12; // eax
  float v13; // ecx
  int v14; // edx
  _DWORD *v15; // ebx
  float v16; // eax
  int v17; // eax
  int v19; // eax

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  if ( LOBYTE(this->m_CalcAbsoluteVelocityMutex.m_depth) != 0
    && *(float *)&this->m_iCurrentSlideIndex <= *(float *)(gpGlobals.m_Index + 12) )
  {
    v3 = _RandomFloat(
           this: v2,
           a2: *(float *)&this->m_chCurrentSlideLists[12],
           a3: *(float *)&this->m_iCurrentMaterialIndex);
    m_Index = (IUniformRandomStream *)gpGlobals.m_Index;
    v5 = 0;
    *(float *)&this->m_iCurrentSlideIndex = v3 + *(float *)(gpGlobals.m_Index + 12);
    while ( *((_BYTE *)&this->m_SlideMaterialLists.m_Memory.m_nGrowSize + v5) != 0xFF )
    {
      if ( *((_BYTE *)&this->m_SlideMaterialLists.m_Memory.m_nGrowSize + v5 + 1) == 0xFF )
      {
        ++v5;
        break;
      }
      if ( *((_BYTE *)&this->m_SlideMaterialLists.m_Memory.m_nGrowSize + v5 + 2) == 0xFF )
      {
        v5 += 2;
        break;
      }
      if ( *((_BYTE *)&this->m_SlideMaterialLists.m_Memory.m_nGrowSize + v5 + 3) == 0xFF )
      {
        v5 += 3;
        break;
      }
      v5 += 4;
      if ( v5 >= 16 )
        break;
    }
    if ( v5 != 0 )
    {
      m_fMinSlideTime = this->m_fMinSlideTime;
      if ( m_fMinSlideTime == 0.0 )
      {
        m_NextSlideTime = this->m_NextSlideTime;
        v10 = _RandomInt(this: m_Index, a2: 0, a3: v5 - 1);
        v11 = LOBYTE(this->m_fMaxSlideTime) == 0;
        LODWORD(this->m_NextSlideTime) = v10;
        if ( v11 || v5 <= 1 || v10 != LODWORD(m_NextSlideTime) )
        {
LABEL_26:
          v13 = this->m_NextSlideTime;
          v14 = *(_DWORD *)&this->m_szSlideshowDirectory[119];
          v15 = *(_DWORD **)(v14
                           + 4 * *((unsigned __int8 *)&this->m_SlideMaterialLists.m_Memory.m_nGrowSize + LODWORD(v13)));
          v16 = this->m_fMinSlideTime;
          if ( v16 == 0.0 )
          {
            this->m_iCycleType = _RandomInt(this: (IUniformRandomStream *)LODWORD(v13), a2: 0, a3: v15[19] - 1);
          }
          else
          {
            v17 = LODWORD(v16) - 1;
            if ( v17 != 0 )
            {
              if ( v17 == 1 && --this->m_iCycleType < 0 )
              {
                LODWORD(this->m_NextSlideTime) = LODWORD(v13) - 1;
                if ( LODWORD(v13) - 1 < 0 )
                  LODWORD(this->m_NextSlideTime) = v5 - 1;
                v15 = *(_DWORD **)(v14
                                 + 4
                                 * *((unsigned __int8 *)&this->m_SlideMaterialLists.m_Memory.m_nGrowSize
                                   + LODWORD(this->m_NextSlideTime)));
                this->m_iCycleType = v15[19] - 1;
              }
            }
            else if ( ++this->m_iCycleType >= v15[19] )
            {
              LODWORD(this->m_NextSlideTime) = LODWORD(v13) + 1;
              if ( LODWORD(v13) + 1 >= v5 )
                this->m_NextSlideTime = 0.0;
              v15 = *(_DWORD **)(v14
                               + 4
                               * *((unsigned __int8 *)&this->m_SlideMaterialLists.m_Memory.m_nGrowSize
                                 + LODWORD(this->m_NextSlideTime)));
              this->m_iCycleType = 0;
            }
          }
          v19 = 4 * this->m_iCycleType;
          *(_DWORD *)&this->m_chCurrentSlideLists[4] = *(_DWORD *)(v19 + v15[16]);
          *(_DWORD *)&this->m_chCurrentSlideLists[8] = *(_DWORD *)(v19 + v15[21]);
          return;
        }
        LODWORD(v12) = v10 + 1;
        this->m_NextSlideTime = v12;
        v8 = SLODWORD(v12) < v5;
      }
      else
      {
        v7 = LODWORD(m_fMinSlideTime) - 1;
        if ( v7 != 0 )
        {
          if ( v7 == 1 && this->m_NextSlideTime < 0.0 )
            LODWORD(this->m_NextSlideTime) = v5 - 1;
          goto LABEL_26;
        }
        v8 = SLODWORD(this->m_NextSlideTime) < v5;
      }
      if ( !v8 )
        this->m_NextSlideTime = 0.0;
      goto LABEL_26;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A440
// Name: public: C_SlideshowDisplay::C_SlideshowDisplay(void)
// Source: json
//------------------------------------------------------------------------------
C_SlideshowDisplay *__thiscall C_SlideshowDisplay::C_SlideshowDisplay(C_SlideshowDisplay *this)
{
  int m_Size; // eax
  int v3; // edi
  C_SlideshowDisplay **m_pMemory; // ecx
  int v5; // eax
  C_SlideshowDisplay **v6; // eax

  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_SlideshowDisplay_vtbl *)&C_SlideshowDisplay::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_SlideshowDisplay::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_SlideshowDisplay::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_SlideshowDisplay::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_SlideshowDisplay::`vftable';
  this->m_SlideMaterialLists.m_Memory.m_pMemory = nullptr;
  this->m_SlideMaterialLists.m_Memory.m_nAllocationCount = 0;
  this->m_SlideMaterialLists.m_Memory.m_nGrowSize = 0;
  this->m_SlideMaterialLists.m_Size = 0;
  this->m_SlideMaterialLists.m_pElements = nullptr;
  m_Size = g_SlideshowDisplays.m_Size;
  v3 = g_SlideshowDisplays.m_Size;
  if ( g_SlideshowDisplays.m_Size + 1 > g_SlideshowDisplays.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_SlideshowDisplays,
      num: g_SlideshowDisplays.m_Size - g_SlideshowDisplays.m_Memory.m_nAllocationCount + 1);
    m_Size = g_SlideshowDisplays.m_Size;
  }
  m_pMemory = g_SlideshowDisplays.m_Memory.m_pMemory;
  g_SlideshowDisplays.m_Size = m_Size + 1;
  v5 = m_Size - v3;
  g_SlideshowDisplays.m_pElements = g_SlideshowDisplays.m_Memory.m_pMemory;
  if ( v5 > 0 )
  {
    _V_memmove(
      dest: &g_SlideshowDisplays.m_Memory.m_pMemory[v3 + 1],
      src: &g_SlideshowDisplays.m_Memory.m_pMemory[v3],
      count: 4 * v5);
    m_pMemory = g_SlideshowDisplays.m_Memory.m_pMemory;
  }
  v6 = &m_pMemory[v3];
  if ( v6 != nullptr )
    *v6 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008A5C0
// Name: private: void C_SlideshowDisplay::BuildSlideShowImagesList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SlideshowDisplay::BuildSlideShowImagesList(C_SlideshowDisplay *this)
{
  C_SlideshowDisplay *v1; // ebx
  char *v2; // eax
  char *v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  IBaseFileSystem *v6; // eax
  const char *String; // eax
  char *v8; // edx
  bool v9; // zf
  char *v10; // ecx
  char v11; // al
  char *v12; // ecx
  int m_Size; // edi
  SlideMaterialList_t *v14; // eax
  int m_nAllocationCount; // eax
  SlideMaterialList_t **m_pMemory; // ecx
  int v17; // eax
  SlideMaterialList_t **v18; // eax
  SlideMaterialList_t *v19; // esi
  int v20; // ebx
  int v21; // eax
  int *v22; // ecx
  int v23; // eax
  int *v24; // ebx
  CUtlMemory<vgui::TreeNode *,int> *v25; // esi
  vgui::TreeNode **v26; // edi
  int v27; // eax
  vgui::TreeNode **v28; // ecx
  int v29; // eax
  int *v30; // edi
  int i; // edi
  SlideMaterialList_t *v32; // eax
  SlideMaterialList_t *v33; // edi
  int v34; // eax
  int v35; // ecx
  SlideMaterialList_t **v36; // eax
  int v37; // ecx
  SlideMaterialList_t **v38; // eax
  SlideMaterialList_t *v39; // esi
  int v40; // ebx
  int v41; // eax
  int *v42; // ecx
  int v43; // eax
  int *v44; // ebx
  CUtlMemory<vgui::TreeNode *,int> *v45; // esi
  vgui::TreeNode **v46; // edi
  int v47; // eax
  vgui::TreeNode **v48; // ecx
  int v49; // eax
  int *v50; // edi
  char *v51; // eax
  char szFullFileName[260]; // [esp+4h] [ebp-534h] BYREF
  char szDirectory[260]; // [esp+108h] [ebp-430h] BYREF
  char szKeywords[256]; // [esp+20Ch] [ebp-32Ch] BYREF
  char szFileName[260]; // [esp+30Ch] [ebp-22Ch] BYREF
  char szMatFileName[260]; // [esp+410h] [ebp-128h] BYREF
  char *v57; // [esp+514h] [ebp-24h]
  int matHandle; // [esp+518h] [ebp-20h] BYREF
  SlideMaterialList_t *v59; // [esp+51Ch] [ebp-1Ch]
  int iMatIndex; // [esp+520h] [ebp-18h]
  KeyValues *pMaterialKeys; // [esp+524h] [ebp-14h]
  int iSlideIndex; // [esp+528h] [ebp-10h]
  char *pchKeyword; // [esp+52Ch] [ebp-Ch]
  C_SlideshowDisplay *v64; // [esp+530h] [ebp-8h]
  char *pNextKeyword; // [esp+534h] [ebp-4h]

  v1 = this;
  v64 = this;
  memset(szMatFileName, 0, sizeof(szMatFileName));
  V_snprintf(pDest: szDirectory, maxLen: 0x104u, pFormat: "materials/vgui/%s/*.vmt", this->m_szSlideshowDirectory);
  v2 = (char *)g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: szDirectory, a3: &matHandle);
  if ( v2 != nullptr )
    V_strncpy(pDest: szMatFileName, pSrc: v2, maxLen: 260);
  iSlideIndex = 0;
  if ( szMatFileName[0] != 0 )
  {
    v3 = &szKeywords[252];
    v57 = &szKeywords[252];
    while ( 1 )
    {
      V_snprintf(pDest: szFileName, maxLen: 0x104u, pFormat: "vgui/%s/%s", v1->m_szSlideshowDirectory, szMatFileName);
      v3[_V_strlen(str: szFileName)] = 0;
      iMatIndex = GetMaterialIndex(pMaterialName: szFileName);
      V_snprintf(
        pDest: szFullFileName,
        maxLen: 0x104u,
        pFormat: "materials/vgui/%s/%s",
        v1->m_szSlideshowDirectory,
        szMatFileName);
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
      {
        v5 = KeyValues::KeyValues(this: v4, setName: "material");
        pMaterialKeys = v5;
      }
      else
      {
        pMaterialKeys = nullptr;
        v5 = nullptr;
      }
      if ( g_pFullFileSystem != nullptr )
        v6 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v6 = nullptr;
      if ( KeyValues::LoadFromFile(
             this: v5,
             filesystem: v6,
             resourceName: szFullFileName,
             pathID: nullptr,
             pfnEvaluateSymbolProc: nullptr) )
      {
        String = KeyValues::GetString(this: v5, keyName: "%keywords", defaultValue: prType);
        _V_strcpy(dest: szKeywords, src: String);
        v8 = szKeywords;
        pchKeyword = szKeywords;
        if ( szKeywords[0] != 0 )
        {
          while ( 1 )
          {
            v9 = *v8 == 0;
            v10 = v8;
            pNextKeyword = v8;
            if ( !v9 )
            {
              do
              {
                if ( *v10 == 44 )
                  break;
                ++v10;
              }
              while ( *v10 != 0 );
              pNextKeyword = v10;
            }
            if ( *v10 != 0 )
            {
              *v10 = 0;
              v11 = v10[1];
              v12 = v10 + 1;
              pNextKeyword = v12;
              if ( v11 != 0 )
              {
                do
                {
                  if ( v11 != 44 && v11 != 32 )
                    break;
                  v11 = *++v12;
                }
                while ( v11 != 0 );
                pNextKeyword = v12;
              }
            }
            m_Size = 0;
            if ( v1->m_SlideMaterialLists.m_Size > 0 )
            {
              while ( _V_strcmp(s1: v1->m_SlideMaterialLists.m_Memory.m_pMemory[m_Size]->szSlideKeyword, s2: v8) != 0 )
              {
                if ( ++m_Size >= v1->m_SlideMaterialLists.m_Size )
                  break;
                v8 = pchKeyword;
              }
            }
            if ( m_Size >= v1->m_SlideMaterialLists.m_Size )
            {
              v14 = (SlideMaterialList_t *)MemAlloc_Alloc(nSize: 0x68u);
              if ( v14 != nullptr )
              {
                v14->iSlideMaterials.m_Memory.m_pMemory = nullptr;
                v14->iSlideMaterials.m_Memory.m_nAllocationCount = 0;
                v14->iSlideMaterials.m_Memory.m_nGrowSize = 0;
                v14->iSlideMaterials.m_Size = 0;
                v14->iSlideMaterials.m_pElements = nullptr;
                v14->iSlideIndex.m_Memory.m_pMemory = nullptr;
                v14->iSlideIndex.m_Memory.m_nAllocationCount = 0;
                v14->iSlideIndex.m_Memory.m_nGrowSize = 0;
                v14->iSlideIndex.m_Size = 0;
                v14->iSlideIndex.m_pElements = nullptr;
                v59 = v14;
              }
              else
              {
                v59 = nullptr;
              }
              m_Size = v1->m_SlideMaterialLists.m_Size;
              m_nAllocationCount = v1->m_SlideMaterialLists.m_Memory.m_nAllocationCount;
              if ( m_Size + 1 > m_nAllocationCount )
                CUtlMemory<CChoreoActor *,int>::Grow(
                  this: (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_SlideMaterialLists,
                  num: m_Size - m_nAllocationCount + 1);
              ++v1->m_SlideMaterialLists.m_Size;
              m_pMemory = v1->m_SlideMaterialLists.m_Memory.m_pMemory;
              v17 = v1->m_SlideMaterialLists.m_Size - m_Size - 1;
              v1->m_SlideMaterialLists.m_pElements = m_pMemory;
              if ( v17 > 0 )
                _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v17);
              v18 = &v1->m_SlideMaterialLists.m_Memory.m_pMemory[m_Size];
              if ( v18 != nullptr )
                *v18 = v59;
              _V_strcpy(dest: v1->m_SlideMaterialLists.m_Memory.m_pMemory[m_Size]->szSlideKeyword, src: pchKeyword);
            }
            v19 = v1->m_SlideMaterialLists.m_Memory.m_pMemory[m_Size];
            v20 = v19->iSlideMaterials.m_Size;
            v21 = v19->iSlideMaterials.m_Memory.m_nAllocationCount;
            if ( v20 + 1 > v21 )
              CUtlMemory<CChoreoActor *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&v19->iSlideMaterials,
                num: v20 - v21 + 1);
            ++v19->iSlideMaterials.m_Size;
            v22 = v19->iSlideMaterials.m_Memory.m_pMemory;
            v23 = v19->iSlideMaterials.m_Size - v20 - 1;
            v19->iSlideMaterials.m_pElements = v22;
            if ( v23 > 0 )
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
            v24 = &v19->iSlideMaterials.m_Memory.m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = iMatIndex;
            v25 = (CUtlMemory<vgui::TreeNode *,int> *)v64->m_SlideMaterialLists.m_Memory.m_pMemory[m_Size];
            v26 = v25[8].m_pMemory;
            v27 = v25[7].m_nAllocationCount;
            if ( (int)v26 + 1 > v27 )
              CUtlMemory<CChoreoActor *,int>::Grow(this: v25 + 7, num: (int)v26 - v27 + 1);
            ++v25[8].m_pMemory;
            v28 = v25[7].m_pMemory;
            v29 = (char *)v25[8].m_pMemory - (char *)v26 - 1;
            v25[8].m_nAllocationCount = (int)v28;
            if ( v29 > 0 )
              _V_memmove(dest: &v28[(_DWORD)v26 + 1], src: &v28[(_DWORD)v26], count: 4 * v29);
            v30 = (int *)&v25[7].m_pMemory[(_DWORD)v26];
            if ( v30 != nullptr )
              *v30 = iSlideIndex;
            v1 = v64;
            v9 = *pNextKeyword == 0;
            pchKeyword = pNextKeyword;
            if ( v9 )
              break;
            v8 = pchKeyword;
          }
          v5 = pMaterialKeys;
        }
      }
      KeyValues::deleteThis(this: v5);
      for ( i = 0; i < v1->m_SlideMaterialLists.m_Size; ++i )
      {
        if ( _V_strcmp(s1: v1->m_SlideMaterialLists.m_Memory.m_pMemory[i]->szSlideKeyword, s2: prType) == 0 )
          break;
      }
      if ( i >= v1->m_SlideMaterialLists.m_Size )
      {
        v32 = (SlideMaterialList_t *)MemAlloc_Alloc(nSize: 0x68u);
        if ( v32 != nullptr )
        {
          v32->iSlideMaterials.m_Memory.m_pMemory = nullptr;
          v32->iSlideMaterials.m_Memory.m_nAllocationCount = 0;
          v32->iSlideMaterials.m_Memory.m_nGrowSize = 0;
          v32->iSlideMaterials.m_Size = 0;
          v32->iSlideMaterials.m_pElements = nullptr;
          v32->iSlideIndex.m_Memory.m_pMemory = nullptr;
          v32->iSlideIndex.m_Memory.m_nAllocationCount = 0;
          v32->iSlideIndex.m_Memory.m_nGrowSize = 0;
          v32->iSlideIndex.m_Size = 0;
          v32->iSlideIndex.m_pElements = nullptr;
          v33 = v32;
        }
        else
        {
          v33 = nullptr;
        }
        v34 = v1->m_SlideMaterialLists.m_Size;
        v35 = v1->m_SlideMaterialLists.m_Memory.m_nAllocationCount;
        if ( v34 + 1 > v35 )
          CUtlMemory<CChoreoActor *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_SlideMaterialLists,
            num: v34 - v35 + 1);
        ++v1->m_SlideMaterialLists.m_Size;
        v36 = v1->m_SlideMaterialLists.m_Memory.m_pMemory;
        v37 = v1->m_SlideMaterialLists.m_Size - 1;
        v1->m_SlideMaterialLists.m_pElements = v36;
        if ( v37 > 0 )
          _V_memmove(dest: v36 + 1, src: v36, count: 4 * v37);
        v38 = v1->m_SlideMaterialLists.m_Memory.m_pMemory;
        if ( v38 != nullptr )
          *v38 = v33;
        i = 0;
        _V_strcpy(dest: *(char **)v1->m_SlideMaterialLists.m_Memory.m_pMemory, src: prType);
      }
      v39 = v1->m_SlideMaterialLists.m_Memory.m_pMemory[i];
      v40 = v39->iSlideMaterials.m_Size;
      v41 = v39->iSlideMaterials.m_Memory.m_nAllocationCount;
      if ( v40 + 1 > v41 )
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&v39->iSlideMaterials,
          num: v40 - v41 + 1);
      ++v39->iSlideMaterials.m_Size;
      v42 = v39->iSlideMaterials.m_Memory.m_pMemory;
      v43 = v39->iSlideMaterials.m_Size - v40 - 1;
      v39->iSlideMaterials.m_pElements = v42;
      if ( v43 > 0 )
        _V_memmove(dest: &v42[v40 + 1], src: &v42[v40], count: 4 * v43);
      v44 = &v39->iSlideMaterials.m_Memory.m_pMemory[v40];
      if ( v44 != nullptr )
        *v44 = iMatIndex;
      v45 = (CUtlMemory<vgui::TreeNode *,int> *)v64->m_SlideMaterialLists.m_Memory.m_pMemory[i];
      v46 = v45[8].m_pMemory;
      v47 = v45[7].m_nAllocationCount;
      if ( (int)v46 + 1 > v47 )
        CUtlMemory<CChoreoActor *,int>::Grow(this: v45 + 7, num: (int)v46 - v47 + 1);
      ++v45[8].m_pMemory;
      v48 = v45[7].m_pMemory;
      v49 = (char *)v45[8].m_pMemory - (char *)v46 - 1;
      v45[8].m_nAllocationCount = (int)v48;
      if ( v49 > 0 )
        _V_memmove(dest: &v48[(_DWORD)v46 + 1], src: &v48[(_DWORD)v46], count: 4 * v49);
      v50 = (int *)&v45[7].m_pMemory[(_DWORD)v46];
      if ( v50 != nullptr )
        *v50 = iSlideIndex;
      v51 = (char *)g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: matHandle);
      if ( v51 != nullptr )
        V_strncpy(pDest: szMatFileName, pSrc: v51, maxLen: 260);
      else
        szMatFileName[0] = 0;
      ++iSlideIndex;
      if ( szMatFileName[0] == 0 )
        break;
      v3 = v57;
      v1 = v64;
    }
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: matHandle);
}

//------------------------------------------------------------------------------
// Address: 0x1008AB70
// Name: public: virtual void C_SlideshowDisplay::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SlideshowDisplay::OnDataChanged(C_SlideshowDisplay *this, DataUpdateType_t updateType)
{
  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType != DATA_UPDATE_CREATED )
  {
    if ( updateType == DATA_UPDATE_DATATABLE_CHANGED )
    {
      this->m_iCycleType = 0;
      *(_DWORD *)&this->m_bNoListRepeats = 0;
    }
  }
  else
  {
    C_SlideshowDisplay::BuildSlideShowImagesList(this: (C_SlideshowDisplay *)((char *)this - 8));
  }
}

//------------------------------------------------------------------------------
// Address: 0x104137D0
// Name: DT_SlideshowDisplay::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SlideshowDisplay::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_SlideshowDisplay::g_RecvTable);
  return atexit(func: DT_SlideshowDisplay::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104137F0
// Name: DT_SlideshowDisplay::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SlideshowDisplay::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_SlideshowDisplay::ignored>();
  DT_SlideshowDisplay::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430B00
// Name: DT_SlideshowDisplay::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SlideshowDisplay::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_SlideshowDisplay::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1008A570
// Name: _C_SlideshowDisplay_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_SlideshowDisplay_CreateObject(int entnum, int serialNum)
{
  C_SlideshowDisplay *v2; // eax
  C_SlideshowDisplay *v3; // eax
  C_SlideshowDisplay *v4; // esi

  v2 = (C_SlideshowDisplay *)C_BaseEntity::operator new(stAllocateBlock: 0xAD0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_SlideshowDisplay::C_SlideshowDisplay(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10430B10
// Name: _dynamic_atexit_destructor_for__g_SlideshowDisplays__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SlideshowDisplays__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_SlideshowDisplays);
}
