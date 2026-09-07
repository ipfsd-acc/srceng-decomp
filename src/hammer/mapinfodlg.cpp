// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapinfodlg.cpp
// Functions: 6
// ============================================================

#include "hammer\mapinfodlg.h"

//------------------------------------------------------------------------------
// Address: 0x100D3F80
// Name: public: CMapInfoDlg::CMapInfoDlg(class CMapWorld __near *,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CMapInfoDlg *__thiscall CMapInfoDlg::CMapInfoDlg(CMapInfoDlg *this, CMapWorld *pWorld, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0xC5u, pParentWnd: pParent);
  this->__vftable = (CMapInfoDlg_vtbl *)&CMapInfoDlg::`vftable';
  CWnd::CWnd(this: &this->m_Faces);
  this->m_Faces.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_Solids);
  this->m_Solids.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_SolidEntities);
  this->m_SolidEntities.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_PointEntities);
  this->m_PointEntities.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_TextureMemory);
  this->m_TextureMemory.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_UniqueTextures);
  this->m_UniqueTextures.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_WadsUsed);
  this->m_WadsUsed.__vftable = (CListBox_vtbl *)&CListBox::`vftable';
  this->pWorld = pWorld;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D40F0
// Name: public: void CMapInfoDlg::CountTexture(class IEditorTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapInfoDlg::CountTexture(CMapInfoDlg *this, IEditorTexture *pTex)
{
  unsigned int m_uUniqueTextures; // edx
  unsigned int v4; // eax
  IEditorTexture **m_pTextures; // ecx
  __int16 v6; // bx
  const char *v7; // edi

  m_uUniqueTextures = this->m_uUniqueTextures;
  v4 = 0;
  if ( m_uUniqueTextures != 0 )
  {
    m_pTextures = this->m_pTextures;
    while ( *m_pTextures != pTex )
    {
      ++v4;
      ++m_pTextures;
      if ( v4 >= m_uUniqueTextures )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    this->m_pTextures[m_uUniqueTextures] = pTex;
    ++this->m_uUniqueTextures;
    v6 = pTex->GetWidth(this: pTex);
    this->m_uTextureMemory += 3 * v6 * (__int16)pTex->GetHeight(this: pTex);
    v7 = pTex->GetFileName(this: pTex);
    if ( *v7 != 0 && SendMessageA(hWnd: this->m_WadsUsed.m_hWnd, Msg: 0x1A2u, wParam: 0, lParam: (LPARAM)v7) == -1 )
      SendMessageA(hWnd: this->m_WadsUsed.m_hWnd, Msg: 0x180u, wParam: 0, lParam: (LPARAM)v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D41A0
// Name: protected: virtual void CMapInfoDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapInfoDlg::DoDataExchange(CMapInfoDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_Faces);
  DDX_Control(pDX, nIDC: (HWND__ *)0x48C, rControl: (HWND__ *)&this->m_Solids);
  DDX_Control(pDX, nIDC: (HWND__ *)0x48E, rControl: (HWND__ *)&this->m_SolidEntities);
  DDX_Control(pDX, nIDC: (HWND__ *)0x48D, rControl: (HWND__ *)&this->m_PointEntities);
  DDX_Control(pDX, nIDC: (HWND__ *)0x58B, rControl: (HWND__ *)&this->m_UniqueTextures);
  DDX_Control(pDX, nIDC: (HWND__ *)0x58C, rControl: (HWND__ *)&this->m_TextureMemory);
  DDX_Control(pDX, nIDC: (HWND__ *)0x58D, rControl: (HWND__ *)&this->m_WadsUsed);
}

//------------------------------------------------------------------------------
// Address: 0x100D4230
// Name: public: void CMapInfoDlg::CountSolid(class CMapSolid __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapInfoDlg::CountSolid(CMapInfoDlg *this, CMapSolid *pSolid)
{
  CMapInfoDlg *v2; // ebx
  unsigned int nCount; // eax
  int v4; // edi
  BlockArray<CMapFace,6,86> *p_Faces; // esi
  int v6; // ebx
  unsigned int v7; // esi
  int v8; // ecx
  IEditorTexture *v9; // ecx
  unsigned int uFaceCount; // [esp+10h] [ebp-8h]
  BlockArray<CMapFace,6,86> *pSolida; // [esp+20h] [ebp+8h]

  v2 = this;
  ++this->m_uSolidCount;
  nCount = pSolid->Faces.nCount;
  this->m_uFaceCount += nCount;
  v4 = 0;
  uFaceCount = nCount;
  if ( nCount != 0 )
  {
    p_Faces = &pSolid->Faces;
    pSolida = &pSolid->Faces;
    do
    {
      if ( v4 >= p_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v4, p_Faces->nCount);
        v6 = v4 + 1;
        if ( v4 + 1 != p_Faces->nCount )
        {
          v7 = v6 / 6;
          if ( 6 * (v6 / 6) < v6 )
            ++v7;
          if ( v7 != pSolida->nBlocks )
          {
            if ( v7 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: pSolida, nNewBlocks: v7);
          }
          pSolida->nCount = v6;
          p_Faces = pSolida;
        }
        v2 = this;
      }
      v8 = (int)&p_Faces->Blocks[v4 / 6][v4 % 6];
      if ( v8 != 0 )
      {
        v9 = *(IEditorTexture **)(v8 + 416);
        if ( v9 != nullptr )
          CMapInfoDlg::CountTexture(this: v2, pTex: v9);
      }
      ++v4;
    }
    while ( v4 < uFaceCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4340
// Name: CountObject
// Source: json
//------------------------------------------------------------------------------
int __cdecl CountObject(CMapSolid *pobj, CMapInfoDlg *dwParam)
{
  int result; // eax
  bool v3; // zf

  if ( dwParam == nullptr )
    return 1;
  if ( pobj->IsMapClass(this: pobj, a2: CMapSolid::__Type) != 0 )
  {
    CMapInfoDlg::CountSolid(this: dwParam, pSolid: pobj);
    return 1;
  }
  else
  {
    v3 = pobj->IsMapClass(this: pobj, a2: CMapEntity::__Type) == 0;
    result = 1;
    if ( !v3 )
    {
      if ( ((int)pobj->Faces.Blocks[38] & 1) != 0 )
        ++dwParam->m_uPointEntityCount;
      else
        ++dwParam->m_uSolidEntityCount;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D43C0
// Name: protected: virtual int CMapInfoDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapInfoDlg::OnInitDialog(CMapInfoDlg *this)
{
  CMapWorld *pWorld; // ecx
  char buf[12]; // [esp+0h] [ebp-88h] BYREF
  char szBuf[128]; // [esp+Ch] [ebp-7Ch]

  CDialog::OnInitDialog(this);
  pWorld = this->pWorld;
  this->m_uSolidCount = 0;
  this->m_uPointEntityCount = 0;
  this->m_uSolidEntityCount = 0;
  this->m_uFaceCount = 0;
  this->m_uUniqueTextures = 0;
  this->m_uTextureMemory = 0;
  CMapClass::EnumChildren(
    this: pWorld,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))CountObject,
    dwParam: (unsigned int)this,
    Type: nullptr);
  ultoa(val: this->m_uSolidCount, buf: &buf[4], radix: 0xAu);
  CWnd::SetWindowTextA(this: &this->m_Solids, lpszString: &buf[4]);
  ultoa(val: this->m_uSolidEntityCount, buf: &buf[4], radix: 0xAu);
  CWnd::SetWindowTextA(this: &this->m_SolidEntities, lpszString: &buf[4]);
  ultoa(val: this->m_uPointEntityCount, buf: &buf[4], radix: 0xAu);
  CWnd::SetWindowTextA(this: &this->m_PointEntities, lpszString: &buf[4]);
  ultoa(val: this->m_uFaceCount, buf: &buf[4], radix: 0xAu);
  CWnd::SetWindowTextA(this: &this->m_Faces, lpszString: &buf[4]);
  ultoa(val: this->m_uUniqueTextures, buf: &buf[4], radix: 0xAu);
  CWnd::SetWindowTextA(this: &this->m_UniqueTextures, lpszString: &buf[4]);
  ultoa(val: this->m_uTextureMemory, buf: &buf[4], radix: 0xAu);
  *(_DWORD *)&szBuf[120] = this->m_uTextureMemory;
  sprintf(
    string: &buf[4],
    format: "%u bytes (%.2f MB)",
    *(_DWORD *)&szBuf[120],
    (double)*(unsigned int *)&szBuf[120] * 0.0000009765625);
  CWnd::SetWindowTextA(this: &this->m_TextureMemory, lpszString: &buf[4]);
  return 1;
}
