// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/bvh/texturepacker.cpp
// Functions: 5
// ============================================================

#include "utils\vmap\bvh\texturepacker.h"

//------------------------------------------------------------------------------
// Address: 0x0040D9B0
// Name: public: class CTextureNode __near * CTextureNode::InsertTexture(struct TextureData_t __near *)
// Source: json
//------------------------------------------------------------------------------
CTextureNode *__thiscall CTextureNode::InsertTexture(CTextureNode *this, TextureData_t *pTexture)
{
  int v3; // ebx
  int left; // edi
  int top; // eax
  int v6; // ecx
  int v7; // edx
  CTextureNode *v8; // eax
  float m_fTotalW; // xmm0_4
  float m_fTotalH; // xmm1_4
  CTextureNode *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  CTextureNode *result; // eax
  float v15; // xmm0_4
  __int64 rect1; // [esp+14h] [ebp-28h]
  __int64 rect1_8; // [esp+1Ch] [ebp-20h]
  __int64 rect0; // [esp+24h] [ebp-18h]
  __int64 rect0_8; // [esp+2Ch] [ebp-10h]
  int texHeight; // [esp+38h] [ebp-4h]

  while ( 1 )
  {
    v3 = (int)ceil(X: pTexture->m_vMaxTextureSize.x);
    texHeight = (int)ceil(X: pTexture->m_vMaxTextureSize.y);
    if ( this->m_child[0] != nullptr && this->m_child[1] != nullptr )
      break;
    if ( this->m_pTextureMap != nullptr )
      return nullptr;
    left = this->m_rect.left;
    top = this->m_rect.top;
    v6 = this->m_rect.right - left;
    v7 = this->m_rect.bottom - top;
    if ( v6 < v3 || v7 < texHeight )
      return nullptr;
    if ( v6 == v3 && v7 == texHeight )
    {
      v15 = (float)this->m_rect.left / this->m_fTotalW;
      this->m_pTextureMap = pTexture;
      pTexture->m_vAtlasMin.x = v15;
      this->m_pTextureMap->m_vAtlasMin.y = (float)this->m_rect.top / this->m_fTotalH;
      this->m_pTextureMap->m_vAtlasMax.x = (float)this->m_rect.right / this->m_fTotalW;
      this->m_pTextureMap->m_vAtlasMax.y = (float)this->m_rect.bottom / this->m_fTotalH;
      return this;
    }
    rect0 = *(_QWORD *)&this->m_rect.top;
    if ( v6 - v3 <= v7 - texHeight )
    {
      LODWORD(rect0_8) = texHeight + top;
      LODWORD(rect1) = texHeight + top;
      HIDWORD(rect0_8) = this->m_rect.right;
      HIDWORD(rect1_8) = HIDWORD(rect0_8);
    }
    else
    {
      left += v3;
      HIDWORD(rect0_8) = left;
      LODWORD(rect0_8) = this->m_rect.bottom;
      HIDWORD(rect1_8) = this->m_rect.right;
      LODWORD(rect1) = this->m_rect.top;
    }
    LODWORD(rect1_8) = this->m_rect.bottom;
    HIDWORD(rect1) = left;
    v8 = (CTextureNode *)MemAlloc_Alloc(nSize: 0x24u);
    if ( v8 != nullptr )
    {
      m_fTotalW = this->m_fTotalW;
      m_fTotalH = this->m_fTotalH;
      *(_QWORD *)&v8->m_rect.top = rect0;
      v8->m_child[0] = nullptr;
      v8->m_child[1] = nullptr;
      v8->m_pTextureMap = nullptr;
      *(_QWORD *)&v8->m_rect.bottom = rect0_8;
      v8->m_fTotalW = m_fTotalW;
      v8->m_fTotalH = m_fTotalH;
    }
    else
    {
      v8 = nullptr;
    }
    this->m_child[0] = v8;
    v11 = (CTextureNode *)MemAlloc_Alloc(nSize: 0x24u);
    if ( v11 != nullptr )
    {
      v12 = this->m_fTotalW;
      v13 = this->m_fTotalH;
      *(_QWORD *)&v11->m_rect.top = rect1;
      v11->m_child[0] = nullptr;
      v11->m_child[1] = nullptr;
      v11->m_pTextureMap = nullptr;
      *(_QWORD *)&v11->m_rect.bottom = rect1_8;
      v11->m_fTotalW = v12;
      v11->m_fTotalH = v13;
      this->m_child[1] = v11;
    }
    else
    {
      this->m_child[1] = nullptr;
    }
    this = this->m_child[0];
  }
  result = CTextureNode::InsertTexture(this: this->m_child[0], pTexture);
  if ( result == nullptr )
    return CTextureNode::InsertTexture(this: this->m_child[1], pTexture);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040DBB0
// Name: public: CTexturePacker::CTexturePacker(void)
// Source: json
//------------------------------------------------------------------------------
CTexturePacker *__thiscall CTexturePacker::CTexturePacker(CTexturePacker *this)
{
  this->m_width = 0;
  this->m_height = 0;
  this->m_pRootNode = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040DBC0
// Name: public: CTexturePacker::~CTexturePacker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexturePacker::~CTexturePacker(CTexturePacker *this)
{
  CTextureNode *m_pRootNode; // esi
  CPackNode *v2; // ecx

  m_pRootNode = this->m_pRootNode;
  if ( m_pRootNode != nullptr )
  {
    if ( m_pRootNode->m_child[0] != nullptr )
      CPackNode::`scalar deleting destructor'(this: (CPackNode *)m_pRootNode->m_child[0], a2: 1u);
    v2 = (CPackNode *)m_pRootNode->m_child[1];
    if ( v2 != nullptr )
      CPackNode::`scalar deleting destructor'(this: v2, a2: 1u);
    free(pMem: m_pRootNode);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DBF0
// Name: public: void CTexturePacker::Init(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexturePacker::Init(CTexturePacker *this, int width, int height)
{
  float *v4; // eax
  __int64 rect_8; // [esp+14h] [ebp-8h]

  this->m_width = width;
  this->m_height = height;
  v4 = (float *)MemAlloc_Alloc(nSize: 0x24u);
  if ( v4 != nullptr )
  {
    *((_QWORD *)v4 + 1) = 0;
    LODWORD(rect_8) = height - 1;
    HIDWORD(rect_8) = width - 1;
    *((_QWORD *)v4 + 2) = rect_8;
    v4[7] = (float)width;
    *v4 = 0.0;
    v4[1] = 0.0;
    v4[6] = 0.0;
    v4[8] = (float)height;
    this->m_pRootNode = (CTextureNode *)v4;
  }
  else
  {
    this->m_pRootNode = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DC80
// Name: public: bool CTexturePacker::InsertTexture(struct TextureData_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTexturePacker::InsertTexture(CTexturePacker *this, TextureData_t *pTexture)
{
  CTextureNode *m_pRootNode; // ecx

  m_pRootNode = this->m_pRootNode;
  return m_pRootNode != nullptr && CTextureNode::InsertTexture(this: m_pRootNode, pTexture) != nullptr;
}
