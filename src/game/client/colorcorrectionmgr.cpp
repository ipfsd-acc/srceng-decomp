// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/colorcorrectionmgr.cpp
// Functions: 11
// ============================================================

#include "game\client\colorcorrectionmgr.h"

//------------------------------------------------------------------------------
// Address: 0x100C4580
// Name: public: bool CColorCorrectionMgr::HasNonZeroColorCorrectionWeights(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CColorCorrectionMgr::HasNonZeroColorCorrectionWeights(CColorCorrectionMgr *this)
{
  return this->m_nActiveWeightCount != 0
      || mat_colcorrection_editor.m_pParent != nullptr && mat_colcorrection_editor.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C45A0
// Name: public: struct ClientCCHandle_t__ __near * CColorCorrectionMgr::AddColorCorrection(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
ClientCCHandle_t__ *__thiscall CColorCorrectionMgr::AddColorCorrection(
        CColorCorrectionMgr *this,
        const char *pName,
        const char *pFileName)
{
  const char *v3; // ebx
  int v4; // esi
  int v5; // edi

  v3 = pFileName;
  if ( pFileName == nullptr )
    v3 = pName;
  v4 = ((int (*)(void))g_pMaterialSystem->GetRenderContext)();
  if ( v4 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
  v5 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 660))(a1: v4, a2: pName);
  if ( v5 != 0 )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 668))(a1: v4, a2: v5);
    (*(void (__thiscall **)(int, int, const char *))(*(_DWORD *)v4 + 672))(a1: v4, a2: v5, a3: v3);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 676))(a1: v4, a2: v5);
  }
  else
  {
    _Warning(a1: "Cannot find color correction lookup file: '%s'\n", v3);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  return (ClientCCHandle_t__ *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x100C4640
// Name: private: void CColorCorrectionMgr::CommitColorCorrectionWeights(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionMgr::CommitColorCorrectionWeights(CColorCorrectionMgr *this)
{
  IMatRenderContext *v2; // ebx
  int v3; // edi
  CColorCorrectionMgr::SetWeightParams_t *m_pMemory; // eax
  float v5; // xmm1_4
  float v6; // xmm0_4
  int i; // [esp+10h] [ebp-8h]
  float flWeight; // [esp+14h] [ebp-4h]

  v2 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v3 = 0;
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  for ( i = 0; i < this->m_colorCorrectionWeights.m_Size; ++i )
  {
    m_pMemory = this->m_colorCorrectionWeights.m_Memory.m_pMemory;
    v5 = m_pMemory[v3].flWeight;
    v6 = v5;
    flWeight = v5;
    if ( !m_pMemory[v3].bExclusive )
    {
      v6 = (float)(1.0 - this->m_flExclusiveWeight) * v5;
      flWeight = v6;
    }
    v2->SetLookupWeight(this: v2, a2: (unsigned int)m_pMemory[v3].handle, a3: COERCE_FLOAT(LODWORD(v6)));
    if ( flWeight != 0.0 )
      ++this->m_nActiveWeightCount;
    ++v3;
  }
  this->m_colorCorrectionWeights.m_Size = 0;
  if ( v2 != nullptr )
  {
    v2->EndRender(this: v2);
    v2->Release(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C4710
// Name: public: void CColorCorrectionMgr::ResetColorCorrectionWeights(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionMgr::ResetColorCorrectionWeights(CColorCorrectionMgr *this)
{
  IMatRenderContext *v2; // esi

  v2 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v2->ResetLookupWeights(this: v2);
  this->m_nActiveWeightCount = 0;
  this->m_bHaveExclusiveWeight = false;
  this->m_flExclusiveWeight = 0.0;
  this->m_colorCorrectionWeights.m_Size = 0;
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100C4770
// Name: public: void CColorCorrectionMgr::UpdateColorCorrection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionMgr::UpdateColorCorrection(CColorCorrectionMgr *this)
{
  C_BasePlayer *LocalPlayer; // edi
  IClientMode *ClientMode; // eax
  IClientMode *v4; // esi
  float ccScale; // [esp+18h] [ebp-4h]

  CColorCorrectionMgr::ResetColorCorrectionWeights(this);
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  ClientMode = GetClientMode();
  v4 = ClientMode;
  if ( LocalPlayer != nullptr && ClientMode != nullptr )
  {
    ClientMode->OnColorCorrectionWeightsReset(this: ClientMode);
    ccScale = v4->GetColorCorrectionScale(this: v4);
    UpdateColorCorrectionEntities(
      pPlayer: LocalPlayer,
      ccScale,
      pList: g_ColorCorrectionList.m_Memory.m_pMemory,
      listCount: g_ColorCorrectionList.m_Size);
    UpdateColorCorrectionVolumes(
      pPlayer: LocalPlayer,
      ccScale,
      pList: g_ColorCorrectionVolumeList.m_Memory.m_pMemory,
      listCount: g_ColorCorrectionVolumeList.m_Size);
    CColorCorrectionMgr::CommitColorCorrectionWeights(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C4810
// Name: public: virtual char const __near * CColorCorrectionMgr::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CColorCorrectionMgr::Name(CColorCorrectionMgr *this)
{
  return "Color Correction Mgr";
}

//------------------------------------------------------------------------------
// Address: 0x100C4850
// Name: public: void CColorCorrectionMgr::RemoveColorCorrectionEntity(class C_ColorCorrection __near *,struct ClientCCHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionMgr::RemoveColorCorrectionEntity(
        CColorCorrectionMgr *this,
        C_ColorCorrection *pEntity,
        ClientCCHandle_t__ *h)
{
  IMatRenderContext *v3; // esi
  int m_Size; // ecx
  int v5; // eax

  if ( h != nullptr )
  {
    v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    v3->RemoveLookup(this: v3, a2: (unsigned int)h);
    v3->EndRender(this: v3);
    v3->Release(this: v3);
  }
  m_Size = g_ColorCorrectionList.m_Size;
  v5 = 0;
  if ( g_ColorCorrectionList.m_Size > 0 )
  {
    while ( g_ColorCorrectionList.m_Memory.m_pMemory[v5] != pEntity )
    {
      if ( ++v5 >= g_ColorCorrectionList.m_Size )
        return;
    }
    if ( v5 != -1 && g_ColorCorrectionList.m_Size > 0 )
    {
      if ( v5 != g_ColorCorrectionList.m_Size - 1 )
      {
        g_ColorCorrectionList.m_Memory.m_pMemory[v5] = g_ColorCorrectionList.m_Memory.m_pMemory[g_ColorCorrectionList.m_Size
                                                                                              - 1];
        m_Size = g_ColorCorrectionList.m_Size;
      }
      g_ColorCorrectionList.m_Size = m_Size - 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C48F0
// Name: public: void CColorCorrectionMgr::RemoveColorCorrectionVolume(class C_ColorCorrectionVolume __near *,struct ClientCCHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionMgr::RemoveColorCorrectionVolume(
        CColorCorrectionMgr *this,
        C_ColorCorrectionVolume *pVolume,
        ClientCCHandle_t__ *h)
{
  IMatRenderContext *v3; // esi
  int m_Size; // ecx
  int v5; // eax

  if ( h != nullptr )
  {
    v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    v3->RemoveLookup(this: v3, a2: (unsigned int)h);
    v3->EndRender(this: v3);
    v3->Release(this: v3);
  }
  m_Size = g_ColorCorrectionVolumeList.m_Size;
  v5 = 0;
  if ( g_ColorCorrectionVolumeList.m_Size > 0 )
  {
    while ( g_ColorCorrectionVolumeList.m_Memory.m_pMemory[v5] != pVolume )
    {
      if ( ++v5 >= g_ColorCorrectionVolumeList.m_Size )
        return;
    }
    if ( v5 != -1 && g_ColorCorrectionVolumeList.m_Size > 0 )
    {
      if ( v5 != g_ColorCorrectionVolumeList.m_Size - 1 )
      {
        g_ColorCorrectionVolumeList.m_Memory.m_pMemory[v5] = g_ColorCorrectionVolumeList.m_Memory.m_pMemory[g_ColorCorrectionVolumeList.m_Size - 1];
        m_Size = g_ColorCorrectionVolumeList.m_Size;
      }
      g_ColorCorrectionVolumeList.m_Size = m_Size - 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C4990
// Name: public: struct ClientCCHandle_t__ __near * CColorCorrectionMgr::AddColorCorrectionEntity(class C_ColorCorrection __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
ClientCCHandle_t__ *__thiscall CColorCorrectionMgr::AddColorCorrectionEntity(
        CColorCorrectionMgr *this,
        C_ColorCorrection *pEntity,
        const char *pName,
        const char *pFileName)
{
  ClientCCHandle_t__ *result; // eax
  ClientCCHandle_t__ *v5; // edi
  int m_Size; // eax
  int v7; // esi
  C_ColorCorrection **m_pMemory; // ecx
  int v9; // eax
  C_ColorCorrection **v10; // eax

  result = CColorCorrectionMgr::AddColorCorrection(this, pName, pFileName);
  v5 = result;
  if ( result != nullptr )
  {
    m_Size = g_ColorCorrectionList.m_Size;
    v7 = g_ColorCorrectionList.m_Size;
    if ( g_ColorCorrectionList.m_Size + 1 > g_ColorCorrectionList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&g_ColorCorrectionList,
        num: g_ColorCorrectionList.m_Size - g_ColorCorrectionList.m_Memory.m_nAllocationCount + 1);
      m_Size = g_ColorCorrectionList.m_Size;
    }
    m_pMemory = g_ColorCorrectionList.m_Memory.m_pMemory;
    g_ColorCorrectionList.m_Size = m_Size + 1;
    v9 = m_Size - v7;
    g_ColorCorrectionList.m_pElements = g_ColorCorrectionList.m_Memory.m_pMemory;
    if ( v9 > 0 )
    {
      _V_memmove(
        dest: &g_ColorCorrectionList.m_Memory.m_pMemory[v7 + 1],
        src: &g_ColorCorrectionList.m_Memory.m_pMemory[v7],
        count: 4 * v9);
      m_pMemory = g_ColorCorrectionList.m_Memory.m_pMemory;
    }
    v10 = &m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = pEntity;
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4A20
// Name: public: struct ClientCCHandle_t__ __near * CColorCorrectionMgr::AddColorCorrectionVolume(class C_ColorCorrectionVolume __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
ClientCCHandle_t__ *__thiscall CColorCorrectionMgr::AddColorCorrectionVolume(
        CColorCorrectionMgr *this,
        C_ColorCorrectionVolume *pVolume,
        const char *pName,
        const char *pFileName)
{
  ClientCCHandle_t__ *result; // eax
  ClientCCHandle_t__ *v5; // edi
  int m_Size; // eax
  int v7; // esi
  C_ColorCorrectionVolume **m_pMemory; // ecx
  int v9; // eax
  C_ColorCorrectionVolume **v10; // eax

  result = CColorCorrectionMgr::AddColorCorrection(this, pName, pFileName);
  v5 = result;
  if ( result != nullptr )
  {
    m_Size = g_ColorCorrectionVolumeList.m_Size;
    v7 = g_ColorCorrectionVolumeList.m_Size;
    if ( g_ColorCorrectionVolumeList.m_Size + 1 > g_ColorCorrectionVolumeList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&g_ColorCorrectionVolumeList,
        num: g_ColorCorrectionVolumeList.m_Size - g_ColorCorrectionVolumeList.m_Memory.m_nAllocationCount + 1);
      m_Size = g_ColorCorrectionVolumeList.m_Size;
    }
    m_pMemory = g_ColorCorrectionVolumeList.m_Memory.m_pMemory;
    g_ColorCorrectionVolumeList.m_Size = m_Size + 1;
    v9 = m_Size - v7;
    g_ColorCorrectionVolumeList.m_pElements = g_ColorCorrectionVolumeList.m_Memory.m_pMemory;
    if ( v9 > 0 )
    {
      _V_memmove(
        dest: &g_ColorCorrectionVolumeList.m_Memory.m_pMemory[v7 + 1],
        src: &g_ColorCorrectionVolumeList.m_Memory.m_pMemory[v7],
        count: 4 * v9);
      m_pMemory = g_ColorCorrectionVolumeList.m_Memory.m_pMemory;
    }
    v10 = &m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = pVolume;
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C4AB0
// Name: public: void CColorCorrectionMgr::SetColorCorrectionWeight(struct ClientCCHandle_t__ __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionMgr::SetColorCorrectionWeight(
        CColorCorrectionMgr *this,
        ClientCCHandle_t__ *h,
        float flWeight,
        bool bExclusive)
{
  int m_Size; // edx
  CColorCorrectionMgr::SetWeightParams_t params; // [esp+4h] [ebp-Ch] BYREF

  if ( h != nullptr )
  {
    m_Size = this->m_colorCorrectionWeights.m_Size;
    params.handle = h;
    params.flWeight = flWeight;
    params.bExclusive = bExclusive;
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&this->m_colorCorrectionWeights,
      elem: m_Size,
      src: (const QAngle *)&params);
    if ( bExclusive )
    {
      if ( this->m_bHaveExclusiveWeight && flWeight != 0.0 )
        DevWarning(a1: "Found multiple active color_correction entities with exclusive setting enabled. This is invalid.\n");
      this->m_bHaveExclusiveWeight = true;
      this->m_flExclusiveWeight = flWeight;
    }
  }
}
