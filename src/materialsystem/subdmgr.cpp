// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/subdmgr.cpp
// Functions: 10
// ============================================================

#include "materialsystem\subdmgr.h"

//------------------------------------------------------------------------------
// Address: 0x1001A740
// Name: public: virtual int CSubDMgr::SubDTexture(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSubDMgr::SubDTexture(CMaterial *this)
{
  return this->m_minLightmapPageID;
}

//------------------------------------------------------------------------------
// Address: 0x10058260
// Name: public: virtual int CSubDMgr::GetWidth(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSubDMgr::GetWidth(CSubDMgr *this)
{
  return 30;
}

//------------------------------------------------------------------------------
// Address: 0x10058270
// Name: public: virtual int CSubDMgr::GetHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSubDMgr::GetHeight(CSubDMgr *this)
{
  return 0x2000;
}

//------------------------------------------------------------------------------
// Address: 0x10058280
// Name: public: virtual void CSubDMgr::AllocateTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubDMgr::AllocateTextures(CSubDMgr *this)
{
  this->ReacquireResources(this);
}

//------------------------------------------------------------------------------
// Address: 0x10058290
// Name: public: virtual void CSubDMgr::FreeTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubDMgr::FreeTextures(CSubDMgr *this)
{
  this->ReleaseResources(this);
}

//------------------------------------------------------------------------------
// Address: 0x100582A0
// Name: public: virtual void CSubDMgr::ReleaseResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubDMgr::ReleaseResources(CSubDMgr *this)
{
  if ( g_pShaderAPI->IsTexture(this: g_pShaderAPI, a2: this->m_hSysMem) )
  {
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_hSysMem);
    this->m_hSysMem = 0;
  }
  if ( g_pShaderAPI->IsTexture(this: g_pShaderAPI, a2: this->m_hDefaultPool) )
  {
    g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_hDefaultPool);
    this->m_hDefaultPool = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058310
// Name: public: virtual void CSubDMgr::ReacquireResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubDMgr::ReacquireResources(CSubDMgr *this)
{
  int *v1; // esi

  v1 = (int *)this;
  g_pShaderAPI->CreateTextures(
    this: g_pShaderAPI,
    a2: &this->m_hSysMem,
    a3: 1,
    a4: 30,
    a5: 0x2000,
    a6: 0,
    a7: IMAGE_FORMAT_RGBA32323232F,
    a8: 1,
    a9: 1,
    a10: 0x10000,
    a11: "_SubDSysMemTexture",
    a12: "SubD Textures");
  v1 += 2;
  g_pShaderAPI->CreateTextures(
    this: g_pShaderAPI,
    a2: v1,
    a3: 1,
    a4: 30,
    a5: 0x2000,
    a6: 0,
    a7: IMAGE_FORMAT_RGBA32323232F,
    a8: 1,
    a9: 1,
    a10: 2112,
    a11: "_SubDVidMemTexture",
    a12: "SubD Textures");
  g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: *v1);
  g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_NEAREST);
  g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_NEAREST);
}

//------------------------------------------------------------------------------
// Address: 0x100583C0
// Name: public: virtual float __near * CSubDMgr::Lock(int)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CSubDMgr::Lock(CSubDMgr *this, int nRows)
{
  this->m_nRowsLocked = nRows;
  return (float *)g_pShaderAPI->LockTex(this: g_pShaderAPI, a2: this->m_hSysMem);
}

//------------------------------------------------------------------------------
// Address: 0x100583F0
// Name: public: virtual void CSubDMgr::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubDMgr::Unlock(CSubDMgr *this)
{
  g_pShaderAPI->UnlockTex(this: g_pShaderAPI, a2: this->m_hSysMem);
  g_pShaderAPI->UpdateTexture(
    this: g_pShaderAPI,
    a2: 0,
    a3: 0,
    a4: 30,
    a5: this->m_nRowsLocked,
    a6: this->m_hDefaultPool,
    a7: this->m_hSysMem);
}

//------------------------------------------------------------------------------
// Address: 0x1007A980
// Name: public: virtual int CSubDMgr::GetOffsetGeometry(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSubDMgr::GetOffsetGeometry(CVTFTexture *this)
{
  return this->m_nHeight;
}
