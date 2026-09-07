// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/dynamicrect.cpp
// Functions: 8
// ============================================================

#include "vgui2\game_controls\dynamicrect.h"

//------------------------------------------------------------------------------
// Address: 0x00427C00
// Name: public: bool CDynamicRect::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDynamicRect::Unserialize(CDynamicRect *this, CDmxElement *pGraphic)
{
  CDynamicRect *v2; // esi
  const char *v3; // eax
  const char *v4; // eax

  v2 = this;
  CGameRect::Unserialize(this, pGraphic);
  CDmxElement::UnpackIntoStructure(this: pGraphic, pData: (char *)v2, pUnpack: s_GameDynamicRectUnpack);
  v2->m_CurrentState = -1;
  v2 = (CDynamicRect *)((char *)v2 + 384);
  v3 = CUtlString::operator char const *(this: (CUtlString *)v2);
  CGameUISystemMgr::InitImageAlias(this: g_pGameUISystemMgrImpl, pAlias: v3);
  v4 = CUtlString::operator char const *(this: (CUtlString *)v2);
  CGameUISystemMgr::LoadImageAliasTexture(this: g_pGameUISystemMgrImpl, pAlias: v4, pBaseTextureName: "vguiedit/pixel");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00427C60
// Name: public: virtual class KeyValues __near * CDynamicRect::HandleScriptCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CDynamicRect::HandleScriptCommand(CDynamicRect *this, KeyValues *args)
{
  const char *Name; // eax
  CUtlString *p_m_ImageAlias; // esi
  const char *v5; // eax
  const char *String; // eax
  const char *v7; // eax

  Name = KeyValues::GetName(this: args);
  if ( _V_stricmp(s1: "SetAlias", s2: Name) != 0 )
    return CGameGraphic::HandleScriptCommand(this, args);
  p_m_ImageAlias = &this->m_ImageAlias;
  v5 = CUtlString::operator char const *(this: p_m_ImageAlias);
  CGameUISystemMgr::ReleaseImageAlias(this: g_pGameUISystemMgrImpl, pAlias: v5);
  String = KeyValues::GetString(this: args, keyName: "alias", defaultValue: "defaultImageAlias");
  CUtlString::operator=(this: p_m_ImageAlias, src: String);
  v7 = CUtlString::operator char const *(this: p_m_ImageAlias);
  CGameUISystemMgr::InitImageAlias(this: g_pGameUISystemMgrImpl, pAlias: v7);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00427CE0
// Name: public: CDynamicRect::CDynamicRect(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDynamicRect *__thiscall CDynamicRect::CDynamicRect(CDynamicRect *this, const char *pName)
{
  CGameRect::CGameRect(this, pName);
  this->__vftable = (CDynamicRect_vtbl *)&CDynamicRect::`vftable';
  CUtlString::CUtlString(this: &this->m_ImageAlias);
  CUtlString::operator=(this: &this->m_ImageAlias, src: "defaultImageAlias");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00427D20
// Name: public: virtual char const __near * CDynamicRect::GetMaterialAlias(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDynamicRect::GetMaterialAlias(CDynamicRect *this)
{
  return CUtlString::operator char const *(this: &this->m_ImageAlias);
}

//------------------------------------------------------------------------------
// Address: 0x00427D30
// Name: public: virtual CDynamicRect::~CDynamicRect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicRect::~CDynamicRect(CDynamicRect *this)
{
  CUtlString *p_m_ImageAlias; // esi
  const char *v3; // eax
  bool v4; // sf

  p_m_ImageAlias = &this->m_ImageAlias;
  this->__vftable = (CDynamicRect_vtbl *)&CDynamicRect::`vftable';
  v3 = CUtlString::operator char const *(this: &this->m_ImageAlias);
  CGameUISystemMgr::ReleaseImageAlias(this: g_pGameUISystemMgrImpl, pAlias: v3);
  v4 = p_m_ImageAlias->m_Storage.m_Memory.m_nGrowSize < 0;
  p_m_ImageAlias->m_Storage.m_nActualLength = 0;
  if ( !v4 )
  {
    if ( p_m_ImageAlias->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_ImageAlias->m_Storage.m_Memory.m_pMemory);
      p_m_ImageAlias->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    p_m_ImageAlias->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CGameRect::~CGameRect(this);
}

//------------------------------------------------------------------------------
// Address: 0x00427D90
// Name: public: virtual class CGameGraphic __near * CDynamicRectClassFactory::CreateNewGraphicClass(class KeyValues __near *,class CGameUIDefinition __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall CDynamicRectClassFactory::CreateNewGraphicClass(
        CDynamicRectClassFactory *this,
        KeyValues *kvRequest,
        CGameUIDefinition *pMenu)
{
  CUtlString *v3; // edi
  const char *String; // esi
  CGameRect *v5; // eax
  KeyValues *i; // esi

  v3 = nullptr;
  String = KeyValues::GetString(this: kvRequest, keyName: "name", defaultValue: nullptr);
  if ( String != nullptr )
  {
    v5 = (CGameRect *)MemAlloc_Alloc(nSize: 0x190u);
    v3 = (CUtlString *)v5;
    if ( v5 != nullptr )
    {
      CGameRect::CGameRect(this: v5, pName: String);
      v3->m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)&CDynamicRect::`vftable';
      CUtlString::CUtlString(this: v3 + 24);
      CUtlString::operator=(this: v3 + 24, src: "defaultImageAlias");
    }
    else
    {
      v3 = nullptr;
    }
    (*((void (__thiscall **)(CUtlString *, _DWORD, _DWORD))v3->m_Storage.m_Memory.m_pMemory + 20))(
      a1: v3,
      a2: 100.0,
      a3: 100.0);
    CGameUIDefinition::AddGraphicToLayer(this: pMenu, pGraphic: (CGameGraphic *)v3, nLayerType: 1);
    for ( i = KeyValues::GetFirstSubKey(this: kvRequest); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      (*((void (__thiscall **)(CUtlString *, KeyValues *))v3->m_Storage.m_Memory.m_pMemory + 10))(a1: v3, a2: i);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00427E60
// Name: public: virtual void CDynamicRect::UpdateRenderData(struct color32_s,class CUtlVector<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,class CUtlMemory<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDynamicRect::UpdateRenderData(
        CDynamicRect *this,
        int parentColor,
        CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,int> > *renderGeometryLists,
        int firstListIndex)
{
  int v5; // edi
  CRenderGeometry *v6; // ebx
  float y; // xmm1_4
  int m_Size; // ecx
  Vector2D *m_pMemory; // eax
  const char *v10; // eax
  int v11; // edi
  int v12; // eax
  int v13; // ebp
  CUtlMemory<ResourceEntryInfo,int> *p_m_ScreenPositions; // edi
  matrix3x4_t *p_m_RenderToScreen; // esi
  float x; // xmm1_4
  ResourceEntryInfo *v17; // ebx
  int m_nAllocationCount; // eax
  ResourceEntryInfo *v19; // ecx
  int v20; // eax
  bool v21; // zf
  Vector2D *v22; // ebx
  Vector2D v23; // [esp-Ch] [ebp-48h]
  CGeometry *p_m_Geometry; // [esp+10h] [ebp-2Ch]
  Vector2D src; // [esp+14h] [ebp-28h] BYREF
  Vector2D sheetTexCoords; // [esp+1Ch] [ebp-20h] BYREF
  float in1[2]; // [esp+24h] [ebp-18h] BYREF
  Vector screenpos; // [esp+2Ch] [ebp-10h] BYREF
  int nCount; // [esp+40h] [ebp+4h]
  int nCounta; // [esp+40h] [ebp+4h]
  int nCountb; // [esp+40h] [ebp+4h]

  if ( this->m_Geometry.m_bVisible )
  {
    p_m_Geometry = &this->m_Geometry;
    CGeometry::SetResultantColor(this: &this->m_Geometry, (color32_s)parentColor);
    v5 = 0;
    v6 = &renderGeometryLists->m_Memory.m_pMemory[firstListIndex].m_Memory.m_pMemory[CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>::InsertBefore(
                                                                                       this: &renderGeometryLists->m_Memory.m_pMemory[firstListIndex],
                                                                                       elem: renderGeometryLists->m_Memory.m_pMemory[firstListIndex].m_Size)];
    nCount = this->m_Geometry.m_RelativePositions.m_Size;
    if ( nCount > 0 )
    {
      do
      {
        y = p_m_Geometry->m_RelativePositions.m_Memory.m_pMemory[v5].y;
        in1[0] = p_m_Geometry->m_RelativePositions.m_Memory.m_pMemory[v5].x;
        in1[1] = y;
        screenpos.x = 0.0;
        VectorTransform(in1, in2: &this->m_Geometry.m_RenderToScreen, out: &screenpos.y);
        m_Size = v6->m_Positions.m_Size;
        src = *(Vector2D *)&screenpos.y;
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(this: &v6->m_Positions, elem: m_Size, &src);
        m_pMemory = this->m_Geometry.m_TextureCoords.m_Memory.m_pMemory;
        v23.x = m_pMemory[v5].x;
        v23.y = m_pMemory[v5].y;
        v10 = CUtlString::operator char const *(this: &this->m_ImageAlias);
        CGameUISystemMgr::TexCoordsToSheetTexCoords(
          this: g_pGameUISystemMgrImpl,
          pAlias: v10,
          texCoords: v23,
          &sheetTexCoords);
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
          this: &v6->m_TextureCoords,
          elem: v6->m_TextureCoords.m_Size,
          src: &sheetTexCoords);
        CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
          this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v6->m_VertexColors,
          elem: v6->m_VertexColors.m_Size,
          src: (vgui::TreeNode **)&this->m_Geometry.m_VertexColors.m_Memory.m_pMemory[v5++]);
      }
      while ( v5 < nCount );
    }
    if ( this->m_Geometry.m_Triangles.m_Size > 0 )
    {
      v11 = 0;
      nCounta = this->m_Geometry.m_Triangles.m_Size;
      do
      {
        CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
          this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v6->m_Triangles,
          elem: v6->m_Triangles.m_Size,
          src: (const CVTFTexture::ResourceMemorySection *)&this->m_Geometry.m_Triangles.m_Memory.m_pMemory[v11++]);
        --nCounta;
      }
      while ( nCounta != 0 );
    }
    v6->m_SheetSequenceNumber = this->m_Geometry.m_SheetSequenceNumber;
    v6->m_AnimationRate = this->m_Geometry.m_AnimationRate;
    v6->m_bAnimate = this->m_Geometry.m_bAnimate;
    v6->m_AnimStartTime.m_tms = this->m_Geometry.m_AnimStartTime.m_tms;
    v6->m_pImageAlias = CUtlString::operator char const *(this: &this->m_ImageAlias);
    v12 = this->m_Geometry.m_RelativePositions.m_Size;
    v13 = 0;
    p_m_ScreenPositions = (CUtlMemory<ResourceEntryInfo,int> *)&this->m_ScreenPositions;
    nCountb = v12;
    this->m_ScreenPositions.m_Size = 0;
    if ( v12 > 0 )
    {
      p_m_RenderToScreen = &this->m_Geometry.m_RenderToScreen;
      do
      {
        x = p_m_Geometry->m_RelativePositions.m_Memory.m_pMemory[v13].x;
        in1[1] = p_m_Geometry->m_RelativePositions.m_Memory.m_pMemory[v13].y;
        in1[0] = x;
        screenpos.x = 0.0;
        VectorTransform(in1, in2: p_m_RenderToScreen, out: &screenpos.y);
        v17 = p_m_ScreenPositions[1].m_pMemory;
        m_nAllocationCount = p_m_ScreenPositions->m_nAllocationCount;
        src = *(Vector2D *)&screenpos.y;
        if ( (int)&v17->eType + 1 > m_nAllocationCount )
          CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
            this: p_m_ScreenPositions,
            num: (int)&v17->___u0 - m_nAllocationCount + 1);
        ++p_m_ScreenPositions[1].m_pMemory;
        v19 = p_m_ScreenPositions->m_pMemory;
        v20 = (char *)p_m_ScreenPositions[1].m_pMemory - (char *)v17 - 1;
        v21 = (char *)p_m_ScreenPositions[1].m_pMemory - (char *)v17 == 1;
        p_m_ScreenPositions[1].m_nAllocationCount = (int)p_m_ScreenPositions->m_pMemory;
        if ( v20 >= 0 && !v21 )
          _V_memmove(dest: &v19[(int)v17 + 1], src: &v19[(_DWORD)v17], count: 8 * v20);
        v22 = (Vector2D *)&p_m_ScreenPositions->m_pMemory[(_DWORD)v17];
        if ( v22 != nullptr )
          *v22 = src;
        ++v13;
      }
      while ( v13 < nCountb );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004280F0
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class CGameRect>(class CGameRect __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<CGameRect>()
{
  if ( (_S1_4 & 1) == 0 )
  {
    _S1_4 |= 1u;
    dword_5BAC8C = 9;
    dword_5BACB8 = 9;
    dword_5BAC90 = 108;
    dword_5BAC94 = 8;
    dword_5BAC98 = -1;
    dword_5BAC9C = 0;
    dword_5BACA0 = 0;
    dword_5BACA4 = 0;
    dword_5BACA8 = 0;
    dword_5BACAC = 0;
    dword_5BACB0 = (int)"scale";
    dword_5BACB4 = (int)"0 0";
    dword_5BACBC = 116;
    dword_5BACC0 = 8;
    dword_5BACC4 = -1;
    dword_5BACC8 = 0;
    dword_5BACCC = 0;
    dword_5BACD0 = 0;
    dword_5BACD4 = 0;
    dword_5BACD8 = 0;
    dword_5BACDC = (int)"rotation";
    dword_5BACE0 = (int)"0";
    dword_5BACE4 = 3;
    dword_5BACE8 = 124;
    dword_5BACEC = 4;
    dword_5BACF0 = -1;
    dword_5BACF4 = 0;
    dword_5BACF8 = 0;
    dword_5BACFC = 0;
    dword_5BAD00 = 0;
    dword_5BAD04 = 0;
    dword_5BAD08 = (int)"maintainaspectratio";
    dword_5BAD0C = (int)"0";
    dword_5BAD10 = 4;
    dword_5BAD14 = 156;
    dword_5BAD18 = 1;
    dword_5BAD1C = -1;
    dword_5BAD20 = 0;
    dword_5BAD24 = 0;
    dword_5BAD28 = 0;
    dword_5BAD2C = 0;
    dword_5BAD30 = 0;
    dword_5BAD34 = (int)"sublayertype";
    dword_5BAD38 = (int)"0";
    dword_5BAD3C = 2;
    dword_5BAD40 = 152;
    dword_5BAD44 = 4;
    dword_5BAD48 = -1;
    dword_5BAD4C = 0;
    dword_5BAD50 = 0;
    dword_5BAD54 = 0;
    dword_5BAD58 = 0;
    dword_5BAD5C = 0;
    dword_5BAD60 = (int)"visible";
    dword_5BAD64 = (int)"1";
    dword_5BAD68 = 4;
    dword_5BAD6C = 157;
    dword_5BAD70 = 1;
    dword_5BAD74 = -1;
    dword_5BAD78 = 0;
    dword_5BAD7C = 0;
    dword_5BAD80 = 0;
    dword_5BAD84 = 0;
    dword_5BAD88 = 0;
    dword_5BAD8C = (int)"initialstate";
    dword_5BAD90 = (int)"-1";
    dword_5BAD94 = 2;
    dword_5BAD98 = 352;
    dword_5BAD9C = 4;
    dword_5BADA0 = -1;
    dword_5BADA4 = 0;
    dword_5BADA8 = 0;
    dword_5BADBC = (int)"0";
    dword_5BADE8 = (int)"255 255 255 255";
    dword_5BAE14 = (int)"255 255 255 255";
    dword_5BAE40 = (int)"255 255 255 255";
    dword_5BADEC = 8;
    dword_5BAE18 = 8;
    dword_5BAE44 = 8;
    dword_5BADAC = 0;
    dword_5BADB0 = 0;
    dword_5BADB4 = 0;
    dword_5BADB8 = (int)"horizgradient";
    dword_5BADC0 = 4;
    dword_5BADC4 = 140;
    dword_5BADC8 = 1;
    dword_5BADCC = -1;
    dword_5BADD0 = 0;
    dword_5BADD4 = 0;
    dword_5BADD8 = 0;
    dword_5BADDC = 0;
    dword_5BADE0 = 0;
    dword_5BADE4 = (int)"color";
    dword_5BADF0 = 128;
    dword_5BADF4 = 4;
    dword_5BADF8 = -1;
    dword_5BADFC = 0;
    dword_5BAE00 = 0;
    dword_5BAE04 = 0;
    dword_5BAE08 = 0;
    dword_5BAE0C = 0;
    dword_5BAE10 = (int)"topcolor";
    dword_5BAE1C = 132;
    dword_5BAE20 = 4;
    dword_5BAE24 = -1;
    dword_5BAE28 = 0;
    dword_5BAE2C = 0;
    dword_5BAE30 = 0;
    dword_5BAE34 = 0;
    dword_5BAE38 = 0;
    dword_5BAE3C = (int)"bottomcolor";
    dword_5BAE48 = 136;
    dword_5BAE4C = 4;
    dword_5BAE50 = -1;
    dword_5BAE54 = 0;
    dword_5BAE58 = 0;
    dword_5BAE5C = 0;
    dword_5BAE60 = 0;
    dword_5BAE64 = 0;
    dword_5BAE68 = 0;
    dword_5BAE6C = 0;
    dword_5BAE70 = 0;
    dword_5BAE74 = 0;
    dword_5BAE78 = 0;
    dword_5BAE7C = -1;
    dword_5BAE80 = 0;
    dword_5BAE84 = 0;
    dword_5BAE88 = 0;
    dword_5BAE8C = 0;
    dword_5BAE90 = 0;
  }
  return unpack_4;
}
