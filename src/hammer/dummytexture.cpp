// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/dummytexture.cpp
// Functions: 7
// ============================================================

#include "hammer\dummytexture.h"

//------------------------------------------------------------------------------
// Address: 0x1014DED0
// Name: public: virtual IEditorTexture::~IEditorTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IEditorTexture::~IEditorTexture(IEditorTexture *this)
{
  this->__vftable = (IEditorTexture_vtbl *)&IEditorTexture::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1014DF20
// Name: public: virtual char const __near * CDummyTexture::GetFileName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CDummyTexture::GetFileName(CDummyTexture *this)
{
  return pszEmpty;
}

//------------------------------------------------------------------------------
// Address: 0x1014DF30
// Name: public: virtual int CDummyTexture::GetKeywords(char __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDummyTexture::GetKeywords(CDummyTexture *this, char *pszKeywords)
{
  if ( pszKeywords != nullptr )
    *pszKeywords = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014DF50
// Name: public: virtual int CDummyTexture::GetShortName(char __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDummyTexture::GetShortName(CDummyTexture *this, char *pszName)
{
  char *v2; // edi
  char *m_szName; // esi
  int v4; // eax
  char *v5; // eax
  int v6; // edx
  char v7; // cl
  _BYTE *v8; // eax
  char *v9; // eax
  int v10; // edx
  char v11; // cl
  char szBuf[260]; // [esp+4h] [ebp-104h] BYREF

  v2 = pszName;
  if ( pszName == nullptr )
    v2 = szBuf;
  if ( this->m_eTextureFormat == tfWAL )
  {
    m_szName = this->m_szName;
    strstr(str1: (unsigned __int8 *)this->m_szName, str2: "textures");
    if ( v4 != 0 )
      v5 = (char *)(v4 + 9);
    else
      v5 = m_szName;
    v6 = v2 - v5;
    do
    {
      v7 = *v5;
      v5[v6] = *v5;
      ++v5;
    }
    while ( v7 != 0 );
    strstr(str1: (unsigned __int8 *)v2, str2: ".wal");
    if ( v8 != nullptr )
      *v8 = 0;
  }
  else
  {
    v9 = this->m_szName;
    v10 = v2 - this->m_szName;
    do
    {
      v11 = *v9;
      v9[v10] = *v9;
      ++v9;
    }
    while ( v11 != 0 );
  }
  return strlen(v2);
}

//------------------------------------------------------------------------------
// Address: 0x1014DFE0
// Name: public: CDummyTexture::CDummyTexture(char const __near *,enum TEXTUREFORMAT)
// Source: json
//------------------------------------------------------------------------------
CDummyTexture *__thiscall CDummyTexture::CDummyTexture(CDummyTexture *this, const char *pszName, TEXTUREFORMAT eFormat)
{
  CDummyTexture *result; // eax
  const char *v4; // edx
  char v5; // bl

  result = this;
  this->__vftable = (CDummyTexture_vtbl *)&IEditorTexture::`vftable';
  v4 = pszName;
  this->__vftable = (CDummyTexture_vtbl *)&CDummyTexture::`vftable';
  if ( pszName != nullptr )
  {
    do
    {
      v5 = *v4;
      v4[this->m_szName - pszName] = *v4;
      ++v4;
    }
    while ( v5 != 0 );
  }
  else
  {
    strcpy(this->m_szName, "Missing texture");
  }
  this->m_eTextureFormat = eFormat;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014E0D0
// Name: public: virtual void CDummyTexture::Draw(class CDC __near *,struct tagRECT __near &,int,int,struct DrawTexData_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyTexture::Draw(
        CDummyTexture *this,
        CDC *pDC,
        tagRECT *rect,
        int iFontHeight,
        int iIconHeight,
        DrawTexData_t *DrawTexData)
{
  CFont *v7; // ebx
  HGDIOBJ StockObject; // eax
  HBRUSH v9; // eax
  unsigned int crBack; // [esp+Ch] [ebp-4h]
  unsigned int crText; // [esp+18h] [ebp+8h]

  v7 = (CFont *)pDC->SelectStockObject(this: pDC, a2: 12);
  crText = pDC->SetTextColor(this: pDC, a2: 0xFFFFFFu);
  crBack = pDC->SetBkColor(this: pDC, a2: 0);
  StockObject = GetStockObject(i: 4);
  v9 = (HBRUSH)CGdiObject::FromHandle(h: StockObject);
  if ( v9 != nullptr )
    v9 = *((HBRUSH *)v9 + 1);
  FillRect(hDC: pDC->m_hDC, lprc: rect, hbr: v9);
  pDC->TextOutA(this: pDC, a2: rect->left + 2, a3: rect->top + 2, a4: "No Image", a5: 8);
  pDC->SelectObject(this: pDC, a2: v7);
  pDC->SetTextColor(this: pDC, a2: crText);
  pDC->SetBkColor(this: pDC, a2: crBack);
}

//------------------------------------------------------------------------------
// Address: 0x10152EC0
// Name: public: virtual char const __near * CDummyTexture::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CDummyTexture::GetName(CDummyTexture *this)
{
  return this->m_szName;
}
