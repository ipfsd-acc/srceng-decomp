// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gmsgformat.cpp
// Functions: 59
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gmsgformat.h"

//------------------------------------------------------------------------------
// Address: 0x1007A880
// Name: public: GStringDataPtr::GStringDataPtr(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStringDataPtr::GStringDataPtr(std::bad_exception *this, std::bad_exception_vtbl *pstr)
{
  this->__vftable = pstr;
  if ( pstr != nullptr )
    this->_Mywhat = (const char *)strlen((const char *)pstr);
  else
    this->_Mywhat = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007A8B0
// Name: public: class GStringDataPtr GStringDataPtr::GetNextToken(char)const
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GStringDataPtr::GetNextToken(_DWORD *this, _DWORD *a2, char separator)
{
  int v3; // esi
  unsigned int v4; // edi
  unsigned int i; // edx
  char v6; // al

  v3 = *this;
  v4 = *(this + 1);
  for ( i = 0; i < v4; ++i )
  {
    v6 = *(_BYTE *)(v3 + i);
    if ( v6 == 0 )
      break;
    if ( v6 == separator )
      break;
  }
  *a2 = v3;
  a2[1] = i;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x1007A8F0
// Name: public: virtual class GStringDataPtr GSwitchFormatter::GetResult(void)const
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GSwitchFormatter::GetResult(_DWORD *this, _DWORD *a2)
{
  int v2; // edx
  int v4; // ecx

  v2 = *(this + 5);
  v4 = *(this + 6);
  *a2 = v2;
  a2[1] = v4;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x1007A920
// Name: public: virtual GFormatter::~GFormatter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFormatter::~GFormatter(CMeshReader *this)
{
  this->m_VertexSize_Position = (int)&GFmtResource::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1007A930
// Name: public: virtual class GStringDataPtr GFormatter::GetNextStr(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlMemory<unsigned short,int>::Iterator_t *__thiscall GFormatter::GetNextStr(
        CUtlMemory<unsigned short,int> *this,
        const CUtlMemory<unsigned short,int>::Iterator_t *p)
{
  *(_DWORD *)p = 0;
  *((_DWORD *)p + 1) = 0;
  return p;
}

//------------------------------------------------------------------------------
// Address: 0x1007A950
// Name: public: virtual void GStrFormatter::Convert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStrFormatter::Convert(GStrFormatter *this)
{
  *((_BYTE *)this + 8) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1007A960
// Name: public: virtual class GStringDataPtr GStrFormatter::GetResult(void)const
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GStrFormatter::GetResult(GStrFormatter *this, _DWORD *a2)
{
  int v2; // edx
  int v4; // ecx

  v2 = *((_DWORD *)this + 3);
  v4 = *((_DWORD *)this + 4);
  *a2 = v2;
  a2[1] = v4;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x1007A990
// Name: public: virtual void GBoolFormatter::Convert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GBoolFormatter::Convert(int this)
{
  char v1; // al

  if ( *(_BYTE *)(this + 8) == 0 )
  {
    v1 = *(_BYTE *)(this + 12);
    if ( (v1 & 2) == 0 )
    {
      if ( (v1 & 1) != 0 )
      {
        *(_DWORD *)(this + 16) = "true";
        *(_DWORD *)(this + 20) = 4;
        *(_BYTE *)(this + 8) = 1;
        return;
      }
      *(_DWORD *)(this + 16) = "false";
      *(_DWORD *)(this + 20) = 5;
    }
    *(_BYTE *)(this + 8) = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A9F0
// Name: public: virtual class GStringDataPtr GBoolFormatter::GetResult(void)const
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GBoolFormatter::GetResult(GBoolFormatter *this, _DWORD *a2)
{
  int v2; // edx
  int v4; // ecx

  v2 = *((_DWORD *)this + 4);
  v4 = *((_DWORD *)this + 5);
  *a2 = v2;
  a2[1] = v4;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x1007AA10
// Name: AppendCharLeft
// Source: json
//------------------------------------------------------------------------------
char *__usercall AppendCharLeft@<eax>(char *a1@<eax>, RGB888_t *a2@<edi>, unsigned int a3)
{
  char *v3; // esi
  int v5; // [esp+4h] [ebp-4h] BYREF

  v3 = a1;
  if ( a2 != nullptr )
  {
    v3 = (char *)(a1 - (char *)GUTF8Util::GetEncodeCharSize(retstr: a2));
    if ( a3 > (unsigned int)v3 )
      return nullptr;
    v5 = 0;
    GUTF8Util::EncodeChar(a1: v3, a2: &v5, a3: (unsigned int)a2);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1007AA50
// Name: protected: void GNumericBase::ULongLong2String(char __near *,unsigned __int64,bool,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GNumericBase::ULongLong2String(
        GNumericBase *this,
        char *a2,
        unsigned __int64 a3,
        bool a4,
        unsigned int a5)
{
  int v7; // edi
  unsigned __int64 v8; // rcx
  _BYTE *v9; // ecx
  char v10; // bl
  unsigned __int8 v11; // [esp+14h] [ebp+Ch]
  const char *v12; // [esp+1Ch] [ebp+14h]

  if ( !a4 || a5 != 10 || (v7 = 3, (*((_BYTE *)this + 5) & 0x7F) == 0) )
    v7 = 1000;
  v12 = "0123456789ABCDEF";
  if ( (*((_BYTE *)this + 6) & 1) == 0 )
    v12 = "0123456789abcdef";
  if ( a5 - 2 <= 0xE )
  {
    do
    {
      if ( a2 == *((char **)this + 2) )
        break;
      v8 = a3 % a5;
      a3 /= a5;
      v11 = v8;
      if ( v7 == 0 )
      {
        v9 = (_BYTE *)(*((_DWORD *)this + 2) - 1);
        v10 = (char)(2 * *((_BYTE *)this + 5)) >> 1;
        *((_DWORD *)this + 2) = v9;
        v7 = 3;
        *v9 = v10;
      }
      *(_BYTE *)--*((_DWORD *)this + 2) = v12[v11];
      --v7;
    }
    while ( a3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007AB00
// Name: protected: void GNumericBase::ULong2String(char __near *,unsigned long,bool,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GNumericBase::ULong2String(
        GNumericBase *this,
        char *buff,
        unsigned int value,
        bool separator,
        unsigned int base)
{
  unsigned int v6; // ebx
  int v7; // esi
  char *v8; // edi
  unsigned __int8 v9; // dl
  unsigned int v10; // et2
  char *v11; // edi
  char v12; // bl
  const char *separatora; // [esp+18h] [ebp+10h]

  v6 = base;
  if ( !separator || base != 10 || (v7 = 3, (*((_BYTE *)this + 5) & 0x7F) == 0) )
    v7 = 1000;
  separatora = "0123456789ABCDEF";
  if ( (*((_BYTE *)this + 6) & 1) == 0 )
    separatora = "0123456789abcdef";
  if ( base - 2 <= 0xE )
  {
    while ( 1 )
    {
      v8 = *((char **)this + 2);
      if ( buff == v8 )
        break;
      v10 = value % v6;
      value /= v6;
      v9 = v10;
      if ( v7 == 0 )
      {
        v11 = v8 - 1;
        v12 = (char)(2 * *((_BYTE *)this + 5)) >> 1;
        *((_DWORD *)this + 2) = v11;
        v7 = 3;
        *v11 = v12;
      }
      --*((_DWORD *)this + 2);
      --v7;
      **((_BYTE **)this + 2) = separatora[v9];
      if ( value == 0 )
        break;
      v6 = base;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007AB90
// Name: public: virtual class GStringDataPtr GDoubleFormatter::GetResult(void)const
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GDoubleFormatter::GetResult(_DWORD *this, _DWORD *a2)
{
  int v3; // ecx

  v3 = (*(int (__thiscall **)(_DWORD *))(*this + 20))(a1: this);
  *a2 = *(this + 6);
  a2[1] = v3;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x1007ABB0
// Name: public: virtual unsigned int GLongFormatter::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GLongFormatter::GetSize(GLongFormatter *this)
{
  return (unsigned int)this - *((_DWORD *)this + 6) + 76;
}

//------------------------------------------------------------------------------
// Address: 0x1007ABC0
// Name: private: void GLongFormatter::AppendSignCharLeft(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GLongFormatter::AppendSignCharLeft(GLongFormatter *this, int a2)
{
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  char *v6; // edi
  unsigned int v7; // ebx

  v3 = *((_DWORD *)this + 1);
  if ( v3 != 0 && (v4 = *(_DWORD *)(v3 + 20)) != 0 )
  {
    v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    if ( (_BYTE)a2 != 0 )
    {
      v6 = *((char **)this + 6);
      v7 = *(_DWORD *)(v5 + 24);
      if ( v7 != 0 )
      {
        v6 -= (int)GUTF8Util::GetEncodeCharSize(retstr: *(RGB888_t **)(v5 + 24));
        if ( (char *)this + 48 > v6 )
        {
          *((_DWORD *)this + 6) = 0;
          return;
        }
        a2 = 0;
        GUTF8Util::EncodeChar(a1: v6, &a2, a3: v7);
      }
      *((_DWORD *)this + 6) = v6;
    }
    else if ( *((char *)this + 21) < 0 )
    {
      *((_DWORD *)this + 6) = AppendCharLeft(
                                a1: *((char **)this + 6),
                                a2: *(RGB888_t **)(v5 + 20),
                                a3: (unsigned int)this + 48);
    }
  }
  else if ( (_BYTE)a2 != 0 )
  {
    *(_BYTE *)--*((_DWORD *)this + 6) = 45;
  }
  else if ( *((char *)this + 21) < 0 )
  {
    *(_BYTE *)--*((_DWORD *)this + 6) = 43;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007AC70
// Name: public: virtual void GDoubleFormatter::Convert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDoubleFormatter::Convert(type_info *this)
{
  int v2; // eax
  char v3; // dl
  int v4; // eax
  bool v5; // zf
  char *v6; // eax
  char v7; // cl
  unsigned int v8; // ecx
  int v9; // edi
  __int16 v10; // cx
  unsigned __int16 v11; // cx
  int v12; // eax
  _BYTE *v13; // eax
  _BYTE *v14; // eax
  double v15; // [esp+0h] [ebp-54h]
  char destsize[32]; // [esp+10h] [ebp-44h] BYREF
  unsigned __int16 dest; // [esp+30h] [ebp-24h] BYREF
  char v18; // [esp+32h] [ebp-22h] BYREF
  char v19; // [esp+33h] [ebp-21h] BYREF

  if ( this->_M_d_name[0] == 0 )
  {
    v2 = *((_DWORD *)this + 7);
    v3 = 32;
    if ( v2 != 0 )
    {
      v4 = v2 - 1;
      if ( v4 != 0 )
      {
        if ( v4 == 1 )
          v3 = (32 * ((*((_BYTE *)this + 22) & 1) == 0)) | 0x47;
      }
      else
      {
        v3 = (32 * ((*((_BYTE *)this + 22) & 1) == 0)) | 0x45;
      }
    }
    else
    {
      v3 = 102;
    }
    v5 = *((_BYTE *)this + 21) >= 0;
    dest = 9509;
    v6 = &v18;
    if ( !v5 )
    {
      v18 = 43;
      v6 = &v19;
    }
    v7 = *((_BYTE *)this + 22);
    if ( (v7 & 8) != 0 )
      *v6++ = 35;
    if ( (v7 & 2) != 0 )
      *v6++ = 32;
    if ( (v7 & 4) != 0 )
      *v6++ = 45;
    if ( (*((_BYTE *)this + 20) & 0x7F) == 0x30 )
      *v6++ = 48;
    v8 = *((_DWORD *)this + 4);
    v9 = (v8 >> 5) & 0x1F;
    v10 = v8 & 0x1F;
    if ( v9 == 1 )
    {
      *(_WORD *)v6 = 9518;
      v6[2] = 100;
      v6[3] = v3;
      v6[4] = 0;
      G_sprintf((unsigned __int16)&dest, destsize, destsizea: 0x20u, format: (char *)&dest, ap: v10);
    }
    else
    {
      *(_WORD *)v6 = 25637;
      *((_WORD *)v6 + 1) = 9518;
      v6[4] = 100;
      v6[5] = v3;
      v6[6] = 0;
      G_sprintf(dest: v10, destsize, destsizea: 0x20u, format: (char *)&dest, ap: v9);
    }
    v15 = *((double *)this + 4);
    G_sprintf(dest: v11, destsize: (char *)this + 44, destsizea: 0x15Cu, format: destsize, ap: SLOBYTE(v15));
    *((_DWORD *)this + 10) = v12;
    *((_DWORD *)this + 6) = (char *)this + 44;
    if ( *((_BYTE *)this + 44) != 0 )
    {
      while ( 1 )
      {
        v13 = *((_BYTE **)this + 6);
        if ( *v13 == 44 )
          break;
        v14 = v13 + 1;
        *((_DWORD *)this + 6) = v14;
        if ( *v14 == 0 )
          goto LABEL_26;
      }
      *v13 = 46;
    }
LABEL_26:
    *((_DWORD *)this + 6) = (char *)this + 44;
    this->_M_d_name[0] = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007ADD0
// Name: public: virtual void GDoubleFormatter::InitString(char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDoubleFormatter::InitString(unsigned __int8 **this, type_info *result, unsigned int size)
{
  if ( *((_BYTE *)this - 4) != 0 )
    memcpy(dst: (unsigned __int8 *)result, src: *(this + 3), count: size);
}

//------------------------------------------------------------------------------
// Address: 0x1007AE00
// Name: public: virtual void GResourceFormatter::Convert(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GResourceFormatter::Convert(CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int> *this)
{
  int result; // eax
  int v3; // ecx
  __int64 v4; // [esp+4h] [ebp-10h] BYREF
  _DWORD v5[2]; // [esp+Ch] [ebp-8h] BYREF

  result = 0;
  if ( LOBYTE(this->m_nGrowSize) == 0 )
  {
    v3 = *((_DWORD *)this + 6);
    v5[0] = 0;
    v5[1] = 0;
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, __int64 *, CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int> *, _DWORD *))(*(_DWORD *)v3 + 8))(
        a1: v3,
        a2: &v4,
        a3: this + 1,
        a4: v5);
      result = v4;
      *(_QWORD *)((char *)this + 28) = v4;
    }
    else
    {
      *((_DWORD *)this + 7) = 0;
      *((_DWORD *)this + 8) = 0;
    }
    LOBYTE(this->m_nGrowSize) = 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007AE60
// Name: public: virtual class GStringDataPtr GResourceFormatter::GetResult(void)const
// Source: json
//------------------------------------------------------------------------------
const CMatRenderContextBase::RenderTargetStackElement_t *__thiscall GResourceFormatter::GetResult(
        CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int> *this,
        _DWORD *a2)
{
  int v2; // edx
  int v4; // ecx

  v2 = *((_DWORD *)this + 7);
  v4 = *((_DWORD *)this + 8);
  *a2 = v2;
  a2[1] = v4;
  return (const CMatRenderContextBase::RenderTargetStackElement_t *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x1007AE80
// Name: bool IsSpace(class GStringDataPtr)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsSpace(struct GStringDataPtr a1)
{
  unsigned int Char; // eax
  int v2; // ecx
  int v3; // edx
  CUtlMap<char const *,int,unsigned short>::CKeyLess putf8Buffer; // [esp+Ch] [ebp-4h] BYREF

  putf8Buffer.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))a1.pStr;
  if ( a1.pStr == &a1.pStr[a1.Size] )
    return 1;
  while ( 1 )
  {
    Char = GUTF8Util::DecodeNextChar((const CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer);
    if ( Char == 0 )
      break;
    v2 = BYTE1(Char);
    v3 = *((unsigned __int16 *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + v2);
    if ( *((_WORD *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + v2) == 0
      || v3 != 1
      && (*((unsigned __int16 *)&G_UnicodeSpaceBits.m_ConCommandAccessor.__vftable + v3 + ((unsigned __int8)Char >> 4))
        & (1 << (Char & 0xF))) == 0 )
    {
      break;
    }
    if ( (const char *)putf8Buffer.m_LessFunc >= &a1.pStr[a1.Size] )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007AF00
// Name: public: GStrFormatter::GStrFormatter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
GStrFormatter *__thiscall GStrFormatter::GStrFormatter(GStrFormatter *this, const char *a2)
{
  GStrFormatter *result; // eax

  result = this;
  *((_DWORD *)this + 1) = 0;
  *((_BYTE *)this + 8) = 0;
  *(_DWORD *)this = &GStrFormatter::`vftable';
  *((_DWORD *)this + 3) = a2;
  if ( a2 != nullptr )
    *((_DWORD *)this + 4) = strlen(a2);
  else
    *((_DWORD *)this + 4) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007AF70
// Name: public: GStrFormatter::GStrFormatter(class GMsgFormat __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
GStrFormatter *__thiscall GStrFormatter::GStrFormatter(GStrFormatter *this, struct GMsgFormat *a2, const char *a3)
{
  GStrFormatter *result; // eax

  result = this;
  *((_DWORD *)this + 1) = a2;
  *((_BYTE *)this + 8) = 0;
  *(_DWORD *)this = &GStrFormatter::`vftable';
  *((_DWORD *)this + 3) = a3;
  if ( a3 != nullptr )
    *((_DWORD *)this + 4) = strlen(a3);
  else
    *((_DWORD *)this + 4) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007AFB0
// Name: public: GStrFormatter::GStrFormatter(class GMsgFormat __near &,class GStringDataPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStrFormatter::GStrFormatter(
        CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *this,
        int f,
        _DWORD *v)
{
  this->m_nAllocationCount = f;
  LOBYTE(this->m_nGrowSize) = 0;
  this->m_pMemory = (void (__cdecl **)(IConVar *, const char *, float))&GStrFormatter::`vftable';
  *((_DWORD *)this + 3) = *v;
  *((_DWORD *)this + 4) = v[1];
}

//------------------------------------------------------------------------------
// Address: 0x1007AFE0
// Name: public: GStrFormatter::GStrFormatter(class GMsgFormat __near &,class GString const __near &)
// Source: json
//------------------------------------------------------------------------------
GStrFormatter *__thiscall GStrFormatter::GStrFormatter(GStrFormatter *this, struct GMsgFormat *a2, const struct GString *a3)
{
  *((_DWORD *)this + 1) = a2;
  *((_BYTE *)this + 8) = 0;
  *(_DWORD *)this = &GStrFormatter::`vftable';
  *((_DWORD *)this + 3) = (a3->HeapTypeBits & 0xFFFFFFFC) + 8;
  *((_DWORD *)this + 4) = *(_DWORD *)(a3->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007B020
// Name: public: GBoolFormatter::GBoolFormatter(class GMsgFormat __near &,bool)
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxy0<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *__thiscall GBoolFormatter::GBoolFormatter(
        CMemberFuncProxy0<CMatRenderContextBase *,void (__thiscall IMatRenderContextInternal::*)(void),CFuncMemPolicyNone> *this,
        unsigned int f,
        bool v)
{
  char v4; // dl

  v4 = BYTE12(this->m_pfnProxied);
  DWORD1(this->m_pfnProxied) = f;
  BYTE8(this->m_pfnProxied) = 0;
  LODWORD(this->m_pfnProxied) = &GBoolFormatter::`vftable';
  BYTE12(this->m_pfnProxied) = v | v4 & 0xFC;
  this->m_pObject = nullptr;
  *((_DWORD *)&this->m_pObject + 1) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007B060
// Name: public: GLongFormatter::GLongFormatter(int)
// Source: json
//------------------------------------------------------------------------------
CUtlFixedLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t> *__thiscall GLongFormatter::GLongFormatter(
        _DWORD *this,
        int result)
{
  char v2; // dl
  char v3; // al
  unsigned int v4; // edx

  *this = &GFormatter::`vftable';
  *(this + 1) = 0;
  *((_BYTE *)this + 8) = 0;
  v2 = *((_BYTE *)this + 20);
  *(this + 4) = *(this + 4) & 0xFFFFFC00 | 0x21;
  v3 = *((_BYTE *)this + 22);
  *((_BYTE *)this + 21) = 0;
  *(this + 6) = 0;
  *((_BYTE *)this + 22) = v3 & 0xF0 | 1;
  *((_BYTE *)this + 20) = v2 & 0x80 | 0x20;
  *(this + 3) = &GString::InitStruct::`vftable';
  v4 = *(this + 7) & 0xFFFFFFE0 | 0xA;
  *((_BYTE *)this + 32) = *(_BYTE *)(this + 8) & 0xFC | 1;
  *(this + 7) = v4;
  *(this + 10) = result;
  *((_BYTE *)this + 76) = 0;
  *(this + 6) = this + 19;
  *this = &GLongFormatter::`vftable'{for `GFormatter'};
  *(this + 3) = &GLongFormatter::`vftable'{for `GString::InitStruct'};
  *(this + 11) = result >> 31;
  return (CUtlFixedLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t> *)this;
}

//------------------------------------------------------------------------------
// Address: 0x1007B130
// Name: public: GLongFormatter::GLongFormatter(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge GLongFormatter::GLongFormatter@<eax>(int a1@<ecx>, const char *const *v, const char *const *a3)
{
  int result; // eax
  char v4; // cl
  unsigned int v5; // ecx

  result = a1;
  *(_DWORD *)a1 = &GFormatter::`vftable';
  *(_DWORD *)(a1 + 4) = 0;
  *(_BYTE *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 16) = *(_DWORD *)(a1 + 16) & 0xFFFFFC00 | 0x21;
  *(_BYTE *)(a1 + 20) = *(_BYTE *)(a1 + 20) & 0x80 | 0x20;
  v4 = *(_BYTE *)(a1 + 22) & 0xF1;
  *(_BYTE *)(result + 21) = 0;
  *(_DWORD *)(result + 24) = 0;
  *(_BYTE *)(result + 22) = v4 | 1;
  *(_DWORD *)(result + 12) = &GString::InitStruct::`vftable';
  v5 = *(_DWORD *)(result + 28) & 0xFFFFFFE0 | 0xA;
  *(_BYTE *)(result + 32) &= 0xFCu;
  *(_DWORD *)(result + 28) = v5;
  *(_DWORD *)(result + 40) = v;
  *(_DWORD *)result = &GLongFormatter::`vftable'{for `GFormatter'};
  *(_DWORD *)(result + 12) = &GLongFormatter::`vftable'{for `GString::InitStruct'};
  *(_DWORD *)(result + 44) = 0;
  *(_DWORD *)(result + 24) = result + 76;
  *(_BYTE *)(result + 76) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B1B0
// Name: public: GLongFormatter::GLongFormatter(__int64)
// Source: json
//------------------------------------------------------------------------------
GLongFormatter *__thiscall GLongFormatter::GLongFormatter(GLongFormatter *this, __int64 v)
{
  GLongFormatter *result; // eax
  char v3; // cl
  unsigned int v4; // ecx

  result = this;
  *(_DWORD *)this = &GFormatter::`vftable';
  *((_DWORD *)this + 1) = 0;
  *((_BYTE *)this + 8) = 0;
  *((_DWORD *)this + 4) = *((_DWORD *)this + 4) & 0xFFFFFC00 | 0x21;
  *((_BYTE *)this + 20) = *((_BYTE *)this + 20) & 0x80 | 0x20;
  v3 = *((_BYTE *)this + 22) & 0xF1;
  *((_BYTE *)result + 21) = 0;
  *((_BYTE *)result + 22) = v3 | 1;
  *((_DWORD *)result + 6) = 0;
  *((_DWORD *)result + 3) = &GString::InitStruct::`vftable';
  v4 = *((_DWORD *)result + 7) & 0xFFFFFFE0 | 0xA;
  *((_BYTE *)result + 32) |= 3u;
  *((_DWORD *)result + 7) = v4;
  *((_QWORD *)result + 5) = v;
  *(_DWORD *)result = &GLongFormatter::`vftable'{for `GFormatter'};
  *((_DWORD *)result + 3) = &GLongFormatter::`vftable'{for `GString::InitStruct'};
  *((_DWORD *)result + 6) = (char *)result + 76;
  *((_BYTE *)result + 76) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B230
// Name: public: GLongFormatter::GLongFormatter(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
GLongFormatter *__thiscall GLongFormatter::GLongFormatter(GLongFormatter *this, unsigned __int64 a2)
{
  *(_DWORD *)this = &GFormatter::`vftable';
  *((_DWORD *)this + 1) = 0;
  *((_BYTE *)this + 8) = 0;
  *((_DWORD *)this + 4) = *((_DWORD *)this + 4) & 0xFFFFFC00 | 0x21;
  *((_BYTE *)this + 20) = *((_BYTE *)this + 20) & 0x80 | 0x20;
  *((_BYTE *)this + 22) = *((_BYTE *)this + 22) & 0xF0 | 1;
  *((_BYTE *)this + 21) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 3) = &GString::InitStruct::`vftable';
  *((_DWORD *)this + 7) = *((_DWORD *)this + 7) & 0xFFFFFFE0 | 0xA;
  *((_BYTE *)this + 32) = *((_BYTE *)this + 32) & 0xFC | 2;
  *((_QWORD *)this + 5) = a2;
  *(_DWORD *)this = &GLongFormatter::`vftable'{for `GFormatter'};
  *((_DWORD *)this + 3) = &GLongFormatter::`vftable'{for `GString::InitStruct'};
  *((_DWORD *)this + 6) = (char *)this + 76;
  *((_BYTE *)this + 76) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007B2C0
// Name: public: GLongFormatter::GLongFormatter(class GMsgFormat __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GLongFormatter::GLongFormatter(BGR888_t *this, int f, int v)
{
  char v3; // al
  char v4; // dl
  char v5; // dl

  *((_DWORD *)this + 1) = f;
  *(_DWORD *)&this->b = &GFormatter::`vftable';
  *((_BYTE *)this + 8) = 0;
  v3 = *((_BYTE *)this + 20);
  *((_DWORD *)this + 4) = *((_DWORD *)this + 4) & 0xFFFFFC00 | 0x21;
  v4 = *((_BYTE *)this + 22);
  *((_BYTE *)this + 20) = v3 & 0x80 | 0x20;
  *((_BYTE *)this + 21) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_BYTE *)this + 22) = v4 & 0xF0 | 1;
  *((_DWORD *)this + 3) = &GString::InitStruct::`vftable';
  v5 = *((_BYTE *)this + 32);
  *((_DWORD *)this + 7) = *((_DWORD *)this + 7) & 0xFFFFFFE0 | 0xA;
  *((_BYTE *)this + 32) = v5 & 0xFC | 1;
  *((_DWORD *)this + 10) = v;
  *((_DWORD *)this + 6) = (char *)this + 76;
  *((_BYTE *)this + 76) = 0;
  *(_DWORD *)&this->b = &GLongFormatter::`vftable'{for `GFormatter'};
  *((_DWORD *)this + 3) = &GLongFormatter::`vftable'{for `GString::InitStruct'};
  *((_DWORD *)this + 11) = v >> 31;
}

//------------------------------------------------------------------------------
// Address: 0x1007B350
// Name: public: GLongFormatter::GLongFormatter(class GMsgFormat __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
BGR888_t *__thiscall GLongFormatter::GLongFormatter(BGR888_t *this, int a2, unsigned int v)
{
  BGR888_t *result; // eax
  char v4; // cl
  unsigned int v5; // ecx

  result = this;
  *((_DWORD *)this + 1) = a2;
  *(_DWORD *)&this->b = &GFormatter::`vftable';
  *((_BYTE *)this + 8) = 0;
  *((_DWORD *)this + 4) = *((_DWORD *)this + 4) & 0xFFFFFC00 | 0x21;
  *((_BYTE *)this + 20) = *((_BYTE *)this + 20) & 0x80 | 0x20;
  v4 = *((_BYTE *)this + 22) & 0xF1;
  result[7].b = 0;
  *(_DWORD *)&result[8].b = 0;
  result[7].g = v4 | 1;
  *(_DWORD *)&result[4].b = &GString::InitStruct::`vftable';
  v5 = *(_DWORD *)&result[9].g & 0xFFFFFFE0 | 0xA;
  result[10].r &= 0xFCu;
  *(_DWORD *)&result[9].g = v5;
  *(_DWORD *)&result[13].g = v;
  *(_DWORD *)&result->b = &GLongFormatter::`vftable'{for `GFormatter'};
  *(_DWORD *)&result[4].b = &GLongFormatter::`vftable'{for `GString::InitStruct'};
  *(_DWORD *)&result[14].r = 0;
  *(_DWORD *)&result[8].b = (char *)result + 76;
  result[25].g = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B3D0
// Name: public: virtual void GLongFormatter::Convert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GLongFormatter::Convert(GLongFormatter *this)
{
  char v2; // al
  char *i; // eax
  int v4; // ecx
  BOOL v5; // ecx
  char v6; // dl
  bool v7; // zf
  unsigned __int8 *v8; // ecx
  unsigned int v9; // ebx
  unsigned int v10; // eax
  unsigned __int8 *v11; // edi
  int v12; // edx
  unsigned __int8 *v13; // edi
  char v14; // al
  int v15; // ecx
  _BYTE *v16; // eax

  if ( *((_BYTE *)this + 8) != 0 )
    return;
  if ( (*((_BYTE *)this + 16) & 0x1F) != 0 || *((_QWORD *)this + 5) != 0 )
  {
    v2 = *((_BYTE *)this + 32);
    if ( (v2 & 2) != 0 )
    {
      GNumericBase::ULongLong2String(
        this: (GNumericBase *)((char *)this + 16),
        a2: (char *)this + 48,
        a3: abs64(*((_QWORD *)this + 5)),
        a4: true,
        a5: *((_DWORD *)this + 7) & 0x1F);
    }
    else if ( (v2 & 1) != 0 )
    {
      GNumericBase::ULong2String(
        this: (GNumericBase *)((char *)this + 16),
        buff: (char *)this + 48,
        value: abs32(*((_DWORD *)this + 10)),
        separator: true,
        base: *((_DWORD *)this + 7) & 0x1F);
    }
    else
    {
      GNumericBase::ULong2String(
        this: (GNumericBase *)((char *)this + 16),
        buff: (char *)this + 48,
        value: *((_DWORD *)this + 10),
        separator: true,
        base: *((_DWORD *)this + 7) & 0x1F);
    }
  }
  for ( i = (char *)this - *((_DWORD *)this + 6) + 76; (unsigned int)i < (*((_DWORD *)this + 4) & 0x1Fu); ++i )
    *(_BYTE *)--*((_DWORD *)this + 6) = 48;
  if ( (*((_BYTE *)this + 16) & 0x1F) == 0 || *((_QWORD *)this + 5) == 0 )
    *((_BYTE *)this + 20) = *((_BYTE *)this + 20) & 0x80 | 0x20;
  v4 = *((_DWORD *)this + 7) & 0x1F;
  if ( v4 == 10 )
  {
    if ( (*((_BYTE *)this + 20) & 0x7F) == 0x30 )
    {
      for ( i = (char *)this - *((_DWORD *)this + 6) + 76; ; ++i )
      {
        v5 = (*((_BYTE *)this + 21) & 0x80) != 0 || (*((_BYTE *)this + 22) & 2) != 0;
        if ( (unsigned int)i >= ((*((_DWORD *)this + 4) >> 5) & 0x1Fu) - v5 )
          break;
        v6 = *((_BYTE *)this + 20);
        *(_BYTE *)--*((_DWORD *)this + 6) = (char)(2 * v6) >> 1;
      }
    }
    LOBYTE(i) = *((int *)this + 11) < 0;
    GLongFormatter::AppendSignCharLeft(this, a2: (int)i);
  }
  else if ( (v4 == 8 || v4 == 16) && *((_QWORD *)this + 5) != 0 )
  {
    v14 = *((_BYTE *)this + 22);
    if ( (v14 & 8) != 0 )
    {
      if ( v4 == 16 )
        *(_BYTE *)--*((_DWORD *)this + 6) = (32 * ((v14 & 1) == 0)) | 0x58;
      *(_BYTE *)--*((_DWORD *)this + 6) = 48;
    }
  }
  if ( (*((_BYTE *)this + 22) & 2) != 0 && (*((_BYTE *)this + 21) & 0x80) == 0 )
  {
    v7 = (*((_BYTE *)this + 32) & 1) == 0;
    *((_BYTE *)this + 20) = *((_BYTE *)this + 20) & 0x80 | 0x20;
    if ( !v7 && *((int *)this + 11) >= 0 )
      *(_BYTE *)--*((_DWORD *)this + 6) = 32;
  }
  v8 = *((unsigned __int8 **)this + 6);
  v9 = this - (GLongFormatter *)v8 + 76;
  v10 = (*((_DWORD *)this + 4) >> 5) & 0x1F;
  if ( (*((_BYTE *)this + 22) & 4) == 0 )
  {
    if ( v9 < v10 )
    {
      do
      {
        v15 = *((_DWORD *)this + 7);
        v16 = (_BYTE *)--*((_DWORD *)this + 6);
        if ( (v15 & 0x1F) == 0xA )
          *v16 = 32;
        else
          *v16 = (char)(2 * *((_BYTE *)this + 20)) >> 1;
        ++v9;
      }
      while ( v9 < ((*((_DWORD *)this + 4) >> 5) & 0x1Fu) );
    }
    goto LABEL_49;
  }
  if ( v9 >= v10
    || (v11 = (unsigned __int8 *)((char *)this - v10 + 76),
        memmove(dst: v11, src: v8, count: this - (GLongFormatter *)v8 + 76),
        v12 = *((_DWORD *)this + 4) >> 5,
        *((_DWORD *)this + 6) = v11,
        v13 = &v11[v9],
        v9 >= (v12 & 0x1Fu)) )
  {
LABEL_49:
    *((_BYTE *)this + 8) = 1;
    return;
  }
  do
  {
    if ( (*((_BYTE *)this + 28) & 0x1F) == 0xA )
      *v13 = 32;
    else
      *v13 = (char)(2 * *((_BYTE *)this + 20)) >> 1;
    ++v9;
    ++v13;
  }
  while ( v9 < ((*((_DWORD *)this + 4) >> 5) & 0x1Fu) );
  *((_BYTE *)this + 8) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1007B640
// Name: public: GDoubleFormatter::GDoubleFormatter(double)
// Source: json
//------------------------------------------------------------------------------
GDoubleFormatter *__thiscall GDoubleFormatter::GDoubleFormatter(GDoubleFormatter *this, double v)
{
  GDoubleFormatter *result; // eax
  char v3; // cl

  result = this;
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable = (CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >_vtbl *)&GFormatter::`vftable';
  this->m_nUserID = 0;
  LOBYTE(this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable) = 0;
  LODWORD(this->m_Proxy.m_pfnProxied) = (__int64)this->m_Proxy.m_pfnProxied & 0xFFFFFC00 | 0x21;
  BYTE4(this->m_Proxy.m_pfnProxied) = BYTE4(this->m_Proxy.m_pfnProxied) & 0x80 | 0x20;
  v3 = BYTE6(this->m_Proxy.m_pfnProxied);
  BYTE5(result->m_Proxy.m_pfnProxied) = 0;
  BYTE6(result->m_Proxy.m_pfnProxied) = v3 & 0xF0 | 1;
  result->m_iRefs = (int)&GString::InitStruct::`vftable';
  *((_DWORD *)&result->m_Proxy.m_pObject + 1) = 0;
  result[1].CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = nullptr;
  *(double *)&result[1].CFunctor = v;
  HIBYTE(result[12].m_nUserID) = 0;
  result->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable = (CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >_vtbl *)&GDoubleFormatter::`vftable'{for `GFormatter'};
  result->m_iRefs = (int)&GLongFormatter::`vftable'{for `GString::InitStruct'};
  result->m_Proxy.m_pObject = (CJob *)((char *)&result[12].m_nUserID + 3);
  LODWORD(result->m_Proxy.m_pfnProxied) = (__int64)result->m_Proxy.m_pfnProxied & 0xFFFFFFE0 | 6;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B6C0
// Name: public: GDoubleFormatter::GDoubleFormatter(class GMsgFormat __near &,double)
// Source: json
//------------------------------------------------------------------------------
type_info *__thiscall GDoubleFormatter::GDoubleFormatter(type_info *this, type_info *f, double v)
{
  type_info *result; // eax
  char v4; // cl

  result = this;
  this->_M_data = f;
  this->__vftable = (type_info_vtbl *)&GFormatter::`vftable';
  this->_M_d_name[0] = 0;
  *((_DWORD *)this + 4) = *((_DWORD *)this + 4) & 0xFFFFFC00 | 0x21;
  *((_BYTE *)this + 20) = *((_BYTE *)this + 20) & 0x80 | 0x20;
  v4 = *((_BYTE *)this + 22);
  result[1]._M_d_name[1] = 0;
  result[1]._M_d_name[2] = v4 & 0xF0 | 1;
  result[1].__vftable = (type_info_vtbl *)&GString::InitStruct::`vftable';
  result[2]._M_data = nullptr;
  result[3]._M_data = nullptr;
  *(double *)result[2]._M_d_name = v;
  HIBYTE(result[32]._M_data) = 0;
  result->__vftable = (type_info_vtbl *)&GDoubleFormatter::`vftable'{for `GFormatter'};
  result[1].__vftable = (type_info_vtbl *)&GLongFormatter::`vftable'{for `GString::InitStruct'};
  result[2].__vftable = (type_info_vtbl *)((char *)&result[32]._M_data + 3);
  result[1]._M_data = (void *)((int)result[1]._M_data & 0xFFFFFFE0 | 6);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B740
// Name: int G_ReadInteger(class GStringDataPtr __near &,int,char)
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_ReadInteger(struct GStringDataPtr *nptr, int defaultValue, char separator)
{
  const char *pStr; // edi
  unsigned int v5; // esi
  char v6; // al
  unsigned int i; // edi
  unsigned int Size; // eax
  unsigned int v9; // ecx
  char *nptra; // [esp+14h] [ebp+8h]

  pStr = nptr->pStr;
  v5 = 0;
  for ( nptra = (char *)nptr->pStr; v5 < nptr->Size; ++v5 )
  {
    v6 = pStr[v5];
    if ( v6 == 0 )
      break;
    if ( v6 == separator )
      break;
  }
  if ( v5 == 0 || pStr == nullptr || isdigit(c: *pStr) == 0 )
    return defaultValue;
  for ( i = 1; i < v5; ++i )
  {
    if ( isdigit(c: nptra[i]) == 0 )
      break;
  }
  Size = nptr->Size;
  v9 = i;
  if ( Size < i )
    v9 = nptr->Size;
  nptr->pStr += v9;
  nptr->Size = Size - v9;
  return atoi(nptr: nptra);
}

//------------------------------------------------------------------------------
// Address: 0x1007B8D0
// Name: protected: void GNumericBase::ReadWidth(class GStringDataPtr)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GNumericBase::ReadWidth(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float,float),CFuncMemPolicyNone> *this@<ecx>,
        CMatRenderContextBase *token,
        __int128 a3)
{
  int v4; // eax
  int v5; // edi
  int v6; // edx
  unsigned int v7; // eax
  BOOL v8; // ecx

  if ( (_DWORD)a3 != 0 )
  {
    v4 = 0;
    while ( *((_BYTE *)&token->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable
            + v4) != 46 )
    {
      if ( ++v4 >= (unsigned int)a3 )
      {
        v5 = -1;
        goto LABEL_6;
      }
    }
    v5 = v4;
LABEL_6:
    LODWORD(this->m_pfnProxied) ^= (LODWORD(this->m_pfnProxied)
                                  ^ (32
                                   * G_ReadInteger(
                                       nptr: (struct GStringDataPtr *)&token,
                                       defaultValue: (LODWORD(this->m_pfnProxied) >> 5) & 0x1F,
                                       separator: 58)))
                                 & 0x3E0;
    if ( v5 >= 0 )
    {
      v6 = a3;
      v7 = this->m_pfnProxied & 0xFFFFFFE0;
      LODWORD(this->m_pfnProxied) = v7;
      v8 = v6 != 0;
      token = (CMatRenderContextBase *)((char *)token + v8);
      LODWORD(a3) = v6 - v8;
      LODWORD(this->m_pfnProxied) ^= ((unsigned __int8)G_ReadInteger(
                                                         nptr: (struct GStringDataPtr *)&token,
                                                         defaultValue: v7 & 0x1F,
                                                         separator: 58)
                                    ^ (unsigned __int8)LODWORD(this->m_pfnProxied))
                                   & 0x1F;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B960
// Name: public: bool GMsgFormat::ReplaceFormatter(class GFormatter __near *,class GFormatter __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GMsgFormat::ReplaceFormatter(GMsgFormat *this, struct GFormatter *a2, struct GFormatter *a3, bool a4)
{
  unsigned int v4; // edi
  unsigned int v5; // edx
  int i; // esi
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> *v7; // eax
  int v9; // [esp+10h] [ebp-4h]

  v4 = (unsigned int)*(this + 9);
  v5 = 0;
  if ( v4 == 0 )
    return 0;
  for ( i = -192; ; i += 12 )
  {
    v7 = v5 >= 0x10
       ? (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> *)((char *)*(this + 10) + i)
       : (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> *)((char *)this + i + 244);
    if ( v7->m_pMemory == (UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short> *)2
      && (struct GFormatter *)v7->m_nAllocationCount == a2 )
    {
      break;
    }
    if ( ++v5 >= v4 )
      return 0;
  }
  LOBYTE(v9) = a4;
  v7->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short> *)2;
  v7->m_nAllocationCount = (int)a3;
  v7->m_nGrowSize = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1007B9E0
// Name: private: bool GMsgFormat::NextFormatter(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GMsgFormat::NextFormatter(GMsgFormat *this)
{
  unsigned int v1; // eax
  unsigned int v2; // esi
  char v3; // bl
  int i; // edi
  char *v5; // edx

  v1 = (unsigned int)*(this + 9);
  v2 = *((unsigned __int16 *)this + 4);
  v3 = 1;
  *(this + 4) = (GMsgFormat)-1;
  if ( v2 >= v1 )
    return 0;
  for ( i = 4 * (3 * v2 - 48); ; i += 12 )
  {
    if ( v2 >= 0x10 )
      v5 = (char *)*(this + 10) + i;
    else
      v5 = (char *)this + i + 244;
    if ( *(_DWORD *)v5 != 1 )
    {
      if ( v3 != 0 )
        ++*((_WORD *)this + 4);
      goto LABEL_12;
    }
    if ( BYTE1(*((_DWORD *)v5 + 2)) == *((_BYTE *)this + 5) )
      break;
    if ( v3 != 0 )
      v3 = 0;
LABEL_12:
    if ( ++v2 >= (unsigned int)*(this + 9) )
      return 0;
  }
  if ( v3 != 0 )
    ++*((_WORD *)this + 4);
  *(this + 4) = (GMsgFormat)v2;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1007BA70
// Name: private: void GMsgFormat::Bind(class GFormatter __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMsgFormat::Bind(GMsgFormat *this, struct GFormatter *a2, bool a3)
{
  unsigned int v4; // eax
  GMsgFormat *v5; // edx
  GMsgFormat v6; // ecx
  GMsgFormat v7; // edx
  const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> *v8; // ebx
  GMsgFormat *v9; // eax
  void (__thiscall *v10)(struct GFormatter *, GMsgFormat *); // eax
  GMsgFormat v11; // [esp+14h] [ebp-8h] BYREF
  const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> *v12; // [esp+18h] [ebp-4h]

  v4 = (unsigned int)*(this + 4);
  if ( v4 >= 0x10 )
    v5 = (GMsgFormat *)&(*(this + 10))[v4 - 16];
  else
    v5 = this + 3 * v4 + 13;
  v6 = v5[1];
  v7 = v5[2];
  LOBYTE(v12) = a3;
  v8 = v12;
  if ( v4 >= 0x10 )
    v9 = (GMsgFormat *)&(*(this + 10))[v4 - 16];
  else
    v9 = this + 3 * v4 + 13;
  *v9 = (GMsgFormat)2;
  v9[1] = (GMsgFormat)a2;
  v9[2] = v8;
  if ( (_BYTE)v7 != 0 )
  {
    v11 = v6;
    v10 = *(void (__thiscall **)(struct GFormatter *, GMsgFormat *))(*(_DWORD *)a2 + 8);
    v12 = (const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> *)(unsigned __int8)v7;
    v10(a1: a2, a2: &v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007BB00
// Name: private: void GMsgFormat::Evaluate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GMsgFormat::Evaluate@<al>(
        CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this@<ecx>,
        unsigned int ind,
        bool req)
{
  int v3; // eax
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v5; // ecx
  char *v6; // eax
  _BYTE *v7; // edi
  int (__thiscall *v8)(_BYTE *); // eax
  int v9; // esi
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v10; // eax
  bool (__cdecl *m_LessFunc)(const char *const *, const char *const *); // eax
  char *v12; // eax
  int v13; // esi
  void (__thiscall *v14)(_BYTE *, bool *); // edx
  unsigned int v15; // esi
  int v16; // edi
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v17; // eax
  int v18; // esi
  int v19; // eax
  int v20; // edi
  int v21; // eax
  char *v22; // eax
  ICommandCompletionCallback_vtbl *v23; // ecx
  unsigned int v24; // eax
  bool (__cdecl *v25)(const char *const *, const char *const *); // eax
  char *v26; // eax
  int v27; // esi
  void (__thiscall *v28)(int); // eax
  int v29; // edi
  int v30; // eax
  int (__thiscall *v31)(_BYTE *, bool *); // edx
  ICommandCompletionCallback_vtbl *v32; // ecx
  unsigned int v33; // esi
  int v34; // edi
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v35; // eax
  char *v36; // eax
  ICommandCompletionCallback_vtbl *v37; // ecx
  unsigned int v38; // eax
  bool (__cdecl *v39)(const char *const *, const char *const *); // eax
  char *v40; // eax
  int v41; // esi
  void (__thiscall *v42)(int); // eax
  int v43; // edi
  int v44; // eax
  int (__thiscall *v45)(_BYTE *, bool *); // edx
  unsigned int v46; // edx
  unsigned int v47; // esi
  int v48; // edi
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v49; // ecx
  char *v50; // eax
  int v51; // ecx
  unsigned int v52; // eax
  int v53; // edi
  unsigned int v54; // edx
  int v55; // ecx
  int v56; // ecx
  char *v57; // eax
  struct GStringDataPtr v59; // [esp-8h] [ebp-44h] BYREF
  BOOL v60; // [esp+0h] [ebp-3Ch]
  bool v61; // [esp+4h] [ebp-38h]
  _BYTE v62[8]; // [esp+Ch] [ebp-30h] BYREF
  std::bad_exception v63; // [esp+14h] [ebp-28h] BYREF
  int v64; // [esp+20h] [ebp-1Ch]
  unsigned int v65; // [esp+24h] [ebp-18h] BYREF
  ICommandCompletionCallback data_size; // [esp+28h] [ebp-14h]
  unsigned int next_ind; // [esp+2Ch] [ebp-10h]
  unsigned int prev_ind; // [esp+30h] [ebp-Ch]
  _BYTE *v69; // [esp+34h] [ebp-8h]
  unsigned __int8 reqa; // [esp+3Ah] [ebp-2h]
  bool found; // [esp+3Bh] [ebp-1h]
  char param_position_3; // [esp+47h] [ebp+Bh]

  LOBYTE(v3) = ind;
  if ( ind >= 0x10 )
    v5 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(*((_DWORD *)this + 10) + 4 * (3 * ind - 48));
  else
    v5 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)((char *)this + 12 * ind + 52);
  if ( v5->m_LessFunc.m_LessFunc != (bool (__cdecl *)(const char *const *, const char *const *))2 )
    return v3;
  if ( ind >= 0x10 )
    v6 = (char *)(*((_DWORD *)this + 10) + 4 * (3 * ind - 48));
  else
    v6 = (char *)this + 12 * ind + 52;
  v7 = *((_BYTE **)v6 + 1);
  v8 = *(int (__thiscall **)(_BYTE *))(*(_DWORD *)v7 + 24);
  v69 = v7;
  LOBYTE(v3) = v8(a1: v7);
  reqa = v3;
  if ( (_BYTE)v3 == 0 )
  {
    if ( v7[8] == 0 )
      LOBYTE(v3) = (*(unsigned __int16 (__thiscall **)(_BYTE *))(*(_DWORD *)v7 + 12))(a1: v7);
    return v3;
  }
  if ( (reqa & 2) != 0 )
  {
    v3 = ind - 1;
    prev_ind = ind - 1;
    found = false;
    if ( ind != 0 )
    {
      v9 = 4 * (3 * v3 - 48);
      next_ind = v9;
      while ( 1 )
      {
        if ( found )
          goto LABEL_30;
        if ( prev_ind >= 0x10 )
          v10 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v9 + *((_DWORD *)this + 10));
        else
          v10 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)((char *)this + v9 + 244);
        m_LessFunc = v10->m_LessFunc.m_LessFunc;
        if ( m_LessFunc == nullptr )
        {
          if ( prev_ind >= 0x10 )
            v22 = (char *)(v9 + *((_DWORD *)this + 10));
          else
            v22 = (char *)this + v9 + 244;
          v23 = (ICommandCompletionCallback_vtbl *)(unsigned __int8)v22[8];
          v24 = *((_DWORD *)v22 + 1);
          data_size.__vftable = v23;
          v65 = v24;
          if ( IsSpace(a1: (struct GStringDataPtr)__PAIR64__((unsigned int)v23, v24)) == 0 )
          {
            (*(void (__thiscall **)(_BYTE *, unsigned int *))(*(_DWORD *)v7 + 28))(a1: v7, a2: &v65);
            found = true;
          }
          goto LABEL_27;
        }
        if ( m_LessFunc == (bool (__cdecl *)(const char *const *, const char *const *))2 )
          break;
LABEL_27:
        v3 = prev_ind - 1;
        v9 -= 12;
        prev_ind = v3;
        next_ind = v9;
        if ( v3 == -1 )
        {
          if ( found )
            goto LABEL_30;
          goto LABEL_29;
        }
      }
      if ( prev_ind >= 0x10 )
        v12 = (char *)(v9 + *((_DWORD *)this + 10));
      else
        v12 = (char *)this + v9 + 244;
      v13 = *((_DWORD *)v12 + 1);
      if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v13 + 24))(a1: v13) & 4) != 0 )
      {
        v14 = *(void (__thiscall **)(_BYTE *, bool *))(*(_DWORD *)v7 + 28);
        *(_DWORD *)&v63._Mydofree = &pstr;
        v64 = 4;
        v14(a1: v7, a2: &v63._Mydofree);
      }
      else if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v13 + 24))(a1: v13) & 8) != 0
             && (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 44))(a1: v13) == 2 )
      {
        v18 = *(_DWORD *)v7;
        GStringDataPtr::GStringDataPtr(this: &v63, pstr: (std::bad_exception_vtbl *)&pstr);
        (*(void (__thiscall **)(_BYTE *, int))(v18 + 28))(a1: v7, a2: v19);
      }
      else
      {
        GMsgFormat::Evaluate(this, ind: prev_ind, req: v60);
        (*(void (__thiscall **)(int, struct GStringDataPtr *))(*(_DWORD *)v13 + 16))(a1: v13, a2: &v59);
        if ( IsSpace(a1: v59) != 0 )
          goto LABEL_26;
        v20 = *(_DWORD *)v69;
        v21 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v13 + 16))(a1: v13, a2: v62);
        (*(void (__thiscall **)(_BYTE *, int))(v20 + 28))(a1: v69, a2: v21);
        v7 = v69;
      }
      found = true;
LABEL_26:
      v9 = next_ind;
      goto LABEL_27;
    }
LABEL_29:
    *(_DWORD *)&v63._Mydofree = 0;
    v64 = 0;
    LOBYTE(v3) = (*(int (__thiscall **)(_BYTE *, bool *))(*(_DWORD *)v7 + 28))(a1: v7, a2: &v63._Mydofree);
  }
LABEL_30:
  if ( (reqa & 1) != 0 )
  {
    v3 = ind - 1;
    next_ind = ind - 1;
    found = false;
    if ( ind != 0 )
    {
      v15 = ind - 1;
      v16 = 4 * (3 * v3 - 48);
      prev_ind = v16;
      while ( !found )
      {
        if ( v15 >= 0x10 )
          v17 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v16 + *((_DWORD *)this + 10));
        else
          v17 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)((char *)this + v16 + 244);
        v25 = v17->m_LessFunc.m_LessFunc;
        if ( v25 != nullptr )
        {
          v3 = (int)v25 - 2;
          if ( v3 == 0 )
          {
            if ( v15 >= 0x10 )
              v26 = (char *)(v16 + *((_DWORD *)this + 10));
            else
              v26 = (char *)this + v16 + 244;
            v27 = *((_DWORD *)v26 + 1);
            (*(void (__thiscall **)(int, BOOL))(*(_DWORD *)v27 + 24))(a1: v27, a2: v60);
            GMsgFormat::Evaluate(this, ind: next_ind, req: v61);
            v28 = *(void (__thiscall **)(int))(*(_DWORD *)v27 + 16);
            v59.pStr = (const char *)&v59.Size;
            v28(a1: v27);
            LOBYTE(v3) = IsSpace(a1: v59);
            if ( (_BYTE)v3 == 0 )
            {
              v29 = *(_DWORD *)v69;
              v30 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v27 + 16))(a1: v27, a2: v62);
              LOBYTE(v3) = (*(int (__thiscall **)(_BYTE *, int))(v29 + 28))(a1: v69, a2: v30);
              v16 = prev_ind;
              found = true;
            }
            v15 = next_ind;
          }
        }
        else
        {
          if ( v15 >= 0x10 )
            v36 = (char *)(v16 + *((_DWORD *)this + 10));
          else
            v36 = (char *)this + v16 + 244;
          v37 = (ICommandCompletionCallback_vtbl *)(unsigned __int8)v36[8];
          v38 = *((_DWORD *)v36 + 1);
          data_size.__vftable = v37;
          v65 = v38;
          LOBYTE(v3) = IsSpace(a1: (struct GStringDataPtr)__PAIR64__((unsigned int)v37, v38));
          if ( (_BYTE)v3 == 0 )
          {
            LOBYTE(v3) = (*(int (__thiscall **)(_BYTE *, unsigned int *))(*(_DWORD *)v69 + 28))(a1: v69, a2: &v65);
            found = true;
          }
        }
        --v15;
        v16 -= 12;
        next_ind = v15;
        prev_ind = v16;
        if ( v15 == -1 )
        {
          if ( found )
            break;
          v7 = v69;
          goto LABEL_58;
        }
      }
    }
    else
    {
LABEL_58:
      v31 = *(int (__thiscall **)(_BYTE *, bool *))(*(_DWORD *)v7 + 28);
      *(_DWORD *)&v63._Mydofree = 0;
      v64 = 0;
      LOBYTE(v3) = v31(a1: v7, a2: &v63._Mydofree);
    }
  }
  if ( (reqa & 4) != 0 )
  {
    v32 = *((ICommandCompletionCallback_vtbl **)this + 9);
    v3 = ind + 1;
    next_ind = ind + 1;
    found = false;
    data_size.__vftable = v32;
    if ( ind + 1 >= (unsigned int)v32 )
    {
LABEL_81:
      v45 = *(int (__thiscall **)(_BYTE *, bool *))(*(_DWORD *)v69 + 36);
      *(_DWORD *)&v63._Mydofree = 0;
      v64 = 0;
      LOBYTE(v3) = v45(a1: v69, a2: &v63._Mydofree);
    }
    else
    {
      v33 = ind + 1;
      v34 = 4 * (3 * v3 - 48);
      prev_ind = v34;
      while ( !found )
      {
        if ( v33 >= 0x10 )
          v35 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v34 + *((_DWORD *)this + 10));
        else
          v35 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)((char *)this + v34 + 244);
        v39 = v35->m_LessFunc.m_LessFunc;
        if ( v39 != nullptr )
        {
          v3 = (int)v39 - 2;
          if ( v3 == 0 )
          {
            if ( v33 >= 0x10 )
              v40 = (char *)(v34 + *((_DWORD *)this + 10));
            else
              v40 = (char *)this + v34 + 244;
            v41 = *((_DWORD *)v40 + 1);
            (*(void (__thiscall **)(int, BOOL))(*(_DWORD *)v41 + 24))(a1: v41, a2: v60);
            GMsgFormat::Evaluate(this, ind: next_ind, req: v61);
            v42 = *(void (__thiscall **)(int))(*(_DWORD *)v41 + 16);
            v59.pStr = (const char *)&v59.Size;
            v42(a1: v41);
            LOBYTE(v3) = IsSpace(a1: v59);
            if ( (_BYTE)v3 == 0 )
            {
              v43 = *(_DWORD *)v69;
              v44 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v41 + 16))(a1: v41, a2: v62);
              LOBYTE(v3) = (*(int (__thiscall **)(_BYTE *, int))(v43 + 36))(a1: v69, a2: v44);
              v34 = prev_ind;
              found = true;
            }
            v33 = next_ind;
          }
        }
        else
        {
          if ( v33 >= 0x10 )
            v50 = (char *)(v34 + *((_DWORD *)this + 10));
          else
            v50 = (char *)this + v34 + 244;
          v51 = (unsigned __int8)v50[8];
          v52 = *((_DWORD *)v50 + 1);
          v64 = v51;
          *(_DWORD *)&v63._Mydofree = v52;
          LOBYTE(v3) = IsSpace(a1: (struct GStringDataPtr)__PAIR64__(v51, v52));
          if ( (_BYTE)v3 == 0 )
          {
            LOBYTE(v3) = (*(int (__thiscall **)(_BYTE *, bool *))(*(_DWORD *)v69 + 36))(a1: v69, a2: &v63._Mydofree);
            found = true;
          }
        }
        ++v33;
        v34 += 12;
        next_ind = v33;
        prev_ind = v34;
        if ( v33 >= (unsigned int)data_size.__vftable )
        {
          if ( found )
            break;
          goto LABEL_81;
        }
      }
    }
  }
  if ( (reqa & 8) != 0 )
  {
    v3 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)v69 + 44))(a1: v69) - 1;
    if ( v3 != 0 )
    {
      if ( --v3 != 0 )
      {
        if ( --v3 == 0 )
        {
          LOBYTE(v3) = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)v69 + 48))(a1: v69);
          v46 = *((_DWORD *)this + 9);
          param_position_3 = v3;
          LOBYTE(v3) = 0;
          v47 = 0;
          if ( v46 != 0 )
          {
            v48 = -192;
            while ( 1 )
            {
              if ( v47 >= 0x10 )
                v49 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v48 + *((_DWORD *)this + 10));
              else
                v49 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)((char *)this + v48 + 244);
              if ( v49->m_LessFunc.m_LessFunc == (bool (__cdecl *)(const char *const *, const char *const *))2 )
              {
                if ( (_BYTE)v3 == param_position_3 )
                {
                  if ( v47 >= 0x10 )
                    v53 = *(_DWORD *)(*((_DWORD *)this + 10) + 4 * (3 * v47 - 48) + 4);
                  else
                    v53 = *((_DWORD *)this + 3 * v47 + 14);
                  goto LABEL_124;
                }
                LOBYTE(v3) = v3 + 1;
              }
              ++v47;
              v48 += 12;
              if ( v47 >= v46 )
                goto LABEL_125;
            }
          }
        }
        goto LABEL_125;
      }
      v54 = *((_DWORD *)this + 9);
      v47 = ind + 1;
      if ( ind + 1 < v54 )
      {
        v55 = 4 * (3 * v47 - 48);
        while ( 1 )
        {
          v3 = v47 >= 0x10 ? v55 + *((_DWORD *)this + 10) : (int)this + v55 + 244;
          if ( *(_DWORD *)v3 == 2 )
            break;
          ++v47;
          v55 += 12;
          if ( v47 >= v54 )
            goto LABEL_125;
        }
LABEL_120:
        if ( v47 >= 0x10 )
          v57 = (char *)(*((_DWORD *)this + 10) + 4 * (3 * v47 - 48));
        else
          v57 = (char *)this + 12 * v47 + 52;
        v53 = *((_DWORD *)v57 + 1);
        (*(void (__thiscall **)(int))(*(_DWORD *)v53 + 24))(a1: v53);
LABEL_124:
        GMsgFormat::Evaluate(this, ind: v47, req: v60);
        LOBYTE(v3) = (*(int (__thiscall **)(_BYTE *, int))(*(_DWORD *)v69 + 52))(a1: v69, a2: v53);
      }
    }
    else
    {
      v47 = ind - 1;
      if ( ind != 0 )
      {
        v56 = 4 * (3 * v47 - 48);
        do
        {
          v3 = v47 >= 0x10 ? v56 + *((_DWORD *)this + 10) : (int)this + v56 + 244;
          if ( *(_DWORD *)v3 == 2 )
            goto LABEL_120;
          --v47;
          v56 -= 12;
        }
        while ( v47 != -1 );
      }
    }
  }
LABEL_125:
  if ( v69[8] == 0 )
    LOBYTE(v3) = (*(unsigned __int16 (__thiscall **)(_BYTE *))(*(_DWORD *)v69 + 12))(a1: v69);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1007C120
// Name: private: void GMsgFormat::MakeString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMsgFormat::MakeString(
        CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  ICommandCompletionCallback_vtbl *v2; // eax
  unsigned int v3; // edi
  int v4; // ecx
  char *v5; // ebx
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v6; // eax
  bool (__cdecl *m_LessFunc)(const char *const *, const char *const *); // eax
  int v8; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short> *m_pElements; // eax
  char *v10; // eax
  int v11; // edi
  unsigned int m_nGrowSize; // eax
  unsigned int v13; // esi
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v14; // ecx
  ICommandCompletionCallback_vtbl *v15; // edi
  unsigned int v16; // ebx
  int v17; // edi
  char *v18; // ecx
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v19; // eax
  bool (__cdecl *v20)(const char *const *, const char *const *); // eax
  int v21; // ecx
  unsigned int v22; // [esp-4h] [ebp-20h]
  bool v23; // [esp+0h] [ebp-1Ch]
  char *v24[2]; // [esp+Ch] [ebp-10h] BYREF
  ICommandCompletionCallback data_sizea; // [esp+14h] [ebp-8h]
  CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *buffer; // [esp+18h] [ebp-4h]

  v2 = *((ICommandCompletionCallback_vtbl **)this + 9);
  v3 = 0;
  this->m_Elements.m_nGrowSize = 0;
  data_sizea.__vftable = v2;
  if ( v2 != nullptr )
  {
    v4 = -192;
    buffer = (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)-192;
    do
    {
      if ( v3 >= 0x10 )
        v5 = (char *)(v4 + *((_DWORD *)this + 10));
      else
        v5 = (char *)this + v4 + 244;
      if ( v3 >= 0x10 )
        v6 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v4 + *((_DWORD *)this + 10));
      else
        v6 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)((char *)this + v4 + 244);
      m_LessFunc = v6->m_LessFunc.m_LessFunc;
      if ( m_LessFunc != nullptr )
      {
        if ( m_LessFunc == (bool (__cdecl *)(const char *const *, const char *const *))2 )
        {
          GMsgFormat::Evaluate(this, ind: v3, req: v23);
          v8 = *((_DWORD *)v5 + 1);
          if ( v8 != 0 )
            this->m_Elements.m_nGrowSize += (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 20))(a1: v8);
          v4 = (int)buffer;
        }
      }
      else
      {
        this->m_Elements.m_nGrowSize += (unsigned __int8)v5[8];
      }
      ++v3;
      v4 += 12;
      buffer = (CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v4;
    }
    while ( v3 < (unsigned int)data_sizea.__vftable );
  }
  m_pElements = this->m_pElements;
  if ( m_pElements != nullptr )
  {
    v10 = (char *)&m_pElements[-1].m_Data.elem + 3;
    if ( v10 != nullptr )
    {
      if ( v10 == (char *)1 )
      {
        v11 = *((_DWORD *)this + 7);
        (*((void (__thiscall **)(CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *, int, _DWORD))this->m_LessFunc.m_LessFunc
         + 1))(
          a1: this,
          a2: v11,
          a3: *((_DWORD *)this + 8));
        m_nGrowSize = this->m_Elements.m_nGrowSize;
        v13 = *((_DWORD *)this + 8) - 1;
        if ( v13 < m_nGrowSize )
          m_nGrowSize = v13;
        *(_BYTE *)(m_nGrowSize + v11) = 0;
      }
    }
    else
    {
      v14 = *((CMemberFunctor2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)this
            + 7);
      v15 = *((ICommandCompletionCallback_vtbl **)this + 9);
      v22 = this->m_Elements.m_nGrowSize + v14->m_nUserID;
      buffer = v14;
      data_sizea.__vftable = v15;
      GStringBuffer::Reserve(this: (GStringBuffer *)v14, a2: v22);
      v16 = 0;
      if ( v15 != nullptr )
      {
        v17 = -192;
        do
        {
          if ( v16 >= 0x10 )
            v18 = (char *)(v17 + *((_DWORD *)this + 10));
          else
            v18 = (char *)this + v17 + 244;
          if ( v16 >= 0x10 )
            v19 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v17 + *((_DWORD *)this + 10));
          else
            v19 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)((char *)this + v17 + 244);
          v20 = v19->m_LessFunc.m_LessFunc;
          if ( v20 != nullptr )
          {
            if ( v20 == (bool (__cdecl *)(const char *const *, const char *const *))2 )
            {
              v21 = *((_DWORD *)v18 + 1);
              if ( v21 != 0 )
              {
                (*(void (__thiscall **)(int, char **))(*(_DWORD *)v21 + 16))(a1: v21, a2: v24);
                GStringBuffer::AppendString(
                  this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)buffer,
                  putf8str: v24[0],
                  utf8StrSz: (int)v24[1]);
              }
            }
          }
          else
          {
            GStringBuffer::AppendString(
              this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMesh *),CFuncMemPolicyNone> *)buffer,
              putf8str: *((char **)v18 + 1),
              utf8StrSz: (unsigned __int8)v18[8]);
          }
          ++v16;
          v17 += 12;
        }
        while ( v16 < (unsigned int)data_sizea.__vftable );
      }
    }
  }
  else
  {
    GString::AssignString(
      this: *((CUtlMemory<CImagePacker,int> **)this + 7),
      a2: (int)this,
      size: this->m_Elements.m_nGrowSize);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C2A0
// Name: private: virtual void GMsgFormat::InitString(char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GMsgFormat::InitString(
        CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this@<ecx>,
        CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t *pbuffer,
        unsigned __int16 *size,
        bool *data_size)
{
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v4; // edx
  ICommandCompletionCallback_vtbl *v5; // eax
  unsigned int v7; // esi
  int v8; // ebx
  int v9; // ecx
  int *v10; // eax
  int v11; // eax
  int v12; // ecx
  unsigned int v13; // esi
  unsigned __int8 *v14; // [esp+8h] [ebp-10h] BYREF
  unsigned int v15; // [esp+Ch] [ebp-Ch]
  ICommandCompletionCallback data_sizea; // [esp+10h] [ebp-8h]
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v17; // [esp+14h] [ebp-4h]
  unsigned int i; // [esp+24h] [ebp+Ch]

  v4 = this;
  v5 = *((ICommandCompletionCallback_vtbl **)this + 9);
  v7 = 0;
  v17 = this;
  data_sizea.__vftable = v5;
  i = 0;
  if ( size != nullptr )
  {
    v8 = -192;
    do
    {
      if ( v7 >= (unsigned int)data_sizea.__vftable )
        return;
      if ( v7 >= 0x10 )
        v9 = v8 + v4[1].m_Elements.m_nGrowSize;
      else
        v9 = (int)&v4[8].m_FirstFree + v8;
      if ( v7 >= 0x10 )
        v10 = (int *)(v8 + v4[1].m_Elements.m_nGrowSize);
      else
        v10 = (int *)((char *)&v4[8].m_FirstFree + v8);
      v11 = *v10;
      if ( v11 != 0 )
      {
        if ( v11 != 2 )
          goto LABEL_20;
        v12 = *(_DWORD *)(v9 + 4);
        if ( v12 == 0 )
          goto LABEL_20;
        (*(void (__thiscall **)(int, unsigned __int8 **))(*(_DWORD *)v12 + 16))(a1: v12, a2: &v14);
        v13 = v15;
        if ( (unsigned int)size < v15 )
          v13 = (unsigned int)size;
        memcpy(dst: (unsigned __int8 *)pbuffer, src: v14, count: v13);
      }
      else
      {
        v13 = *(unsigned __int8 *)(v9 + 8);
        if ( (unsigned int)size < v13 )
          v13 = (unsigned int)size;
        memcpy(dst: (unsigned __int8 *)pbuffer, src: *(unsigned __int8 **)(v9 + 4), count: v13);
      }
      v4 = v17;
      size = (unsigned __int16 *)((char *)size - v13);
      pbuffer = (CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t *)((char *)pbuffer + v13);
      v7 = i;
LABEL_20:
      ++v7;
      v8 += 12;
      i = v7;
    }
    while ( size != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C370
// Name: public: virtual void GStrFormatter::Parse(class GStringDataPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStrFormatter::Parse(GStrFormatter *this, const struct GStringDataPtr *a2)
{
  const char *pStr; // edx
  unsigned int Size; // esi
  unsigned int i; // eax
  char v6; // cl
  int v7; // eax
  struct GFormatter *v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // ecx
  _DWORD v11[3]; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD v12[2]; // [esp+18h] [ebp-10h] BYREF
  const char *v13; // [esp+20h] [ebp-8h] BYREF
  unsigned int v14; // [esp+24h] [ebp-4h]

  pStr = a2->pStr;
  Size = a2->Size;
  for ( i = 0; i < Size; ++i )
  {
    v6 = pStr[i];
    if ( v6 == 0 )
      break;
    if ( v6 == 58 )
      break;
  }
  v14 = i;
  v7 = *((_DWORD *)this + 1);
  v13 = pStr;
  if ( v7 != 0 && *(_DWORD *)(v7 + 20) != 0 )
  {
    v11[1] = &v13;
    v11[2] = v11;
    v11[0] = v7;
    v8 = (struct GFormatter *)(*(int (__thiscall **)(_DWORD, _DWORD *))(**(_DWORD **)(v7 + 20) + 4))(
                                a1: *(_DWORD *)(v7 + 20),
                                a2: v11);
    if ( v8 != nullptr )
    {
      v9 = a2->Size;
      v10 = v14 + 1;
      if ( v9 < v14 + 1 )
        v10 = a2->Size;
      v12[0] = &a2->pStr[v10];
      v12[1] = v9 - v10;
      if ( v9 != v10 )
        (*(void (__thiscall **)(struct GFormatter *, _DWORD *))(*(_DWORD *)v8 + 8))(a1: v8, a2: v12);
      GMsgFormat::ReplaceFormatter(this: *((GMsgFormat **)this + 1), a2: (struct GFormatter *)this, a3: v8, a4: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C420
// Name: public: virtual void GBoolFormatter::Parse(class GStringDataPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GBoolFormatter::Parse(GBoolFormatter *this, const struct GStringDataPtr *a2)
{
  unsigned int Size; // eax
  unsigned int v4; // ecx
  const char *i; // edi
  char v6; // dl
  unsigned int v7; // ecx
  unsigned int v8; // edi
  _DWORD *NextToken; // eax
  char v10; // bl
  int v11; // edx
  unsigned int v12; // eax
  _DWORD *v13; // eax
  int v14; // eax
  struct GFormatter *v15; // edi
  unsigned int v16; // eax
  unsigned int v17; // ecx
  int v18; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD v19[2]; // [esp+10h] [ebp-18h] BYREF
  const char *pStr; // [esp+18h] [ebp-10h] BYREF
  unsigned int v21; // [esp+1Ch] [ebp-Ch]
  const char *v22; // [esp+20h] [ebp-8h] BYREF
  unsigned int v23; // [esp+24h] [ebp-4h]

  Size = a2->Size;
  v4 = 0;
  for ( i = a2->pStr; v4 < Size; ++v4 )
  {
    v6 = i[v4];
    if ( v6 == 0 )
      break;
    if ( v6 == 58 )
      break;
  }
  pStr = a2->pStr;
  v21 = v4;
  if ( i != nullptr && v4 != 0 )
  {
    if ( *i == 115 && i[1] == 119 )
    {
      v7 = v4 + 1;
      if ( Size < v7 )
        v7 = Size;
      v22 = &i[v7];
      v8 = Size - v7;
      v23 = Size - v7;
      NextToken = GStringDataPtr::GetNextToken(this: &v22, a2: v19, separator: 58);
      v10 = *((_BYTE *)this + 12);
      *((_DWORD *)this + 4) = *NextToken;
      v11 = NextToken[1];
      *((_DWORD *)this + 5) = v11;
      if ( (v10 & 1) == 0 )
      {
        v12 = v11 + 1;
        if ( v8 < v11 + 1 )
          v12 = v8;
        v22 += v12;
        v23 = v8 - v12;
        v13 = GStringDataPtr::GetNextToken(this: &v22, a2: v19, separator: 58);
        *((_DWORD *)this + 4) = *v13;
        *((_DWORD *)this + 5) = v13[1];
      }
      *((_BYTE *)this + 12) = v10 | 2;
    }
    else
    {
      v14 = *((_DWORD *)this + 1);
      if ( *(_DWORD *)(v14 + 20) != 0 )
      {
        v19[0] = &pStr;
        v19[1] = &v18;
        v18 = v14;
        v15 = (struct GFormatter *)(*(int (__thiscall **)(_DWORD, int *))(**(_DWORD **)(v14 + 20) + 4))(
                                     a1: *(_DWORD *)(v14 + 20),
                                     a2: &v18);
        if ( v15 != nullptr )
        {
          v16 = a2->Size;
          v17 = v21 + 1;
          if ( v16 < v21 + 1 )
            v17 = a2->Size;
          v22 = &a2->pStr[v17];
          v23 = v16 - v17;
          if ( v16 != v17 )
            (*(void (__thiscall **)(struct GFormatter *, const char **))(*(_DWORD *)v15 + 8))(a1: v15, a2: &v22);
          GMsgFormat::ReplaceFormatter(this: *((GMsgFormat **)this + 1), a2: this, a3: v15, a4: true);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C550
// Name: protected: void GNumericBase::ReadPrintFormat(class GStringDataPtr)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GNumericBase::ReadPrintFormat(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float,float),CFuncMemPolicyNone> *this@<ecx>,
        CMatRenderContextBase *token,
        __int128 a3)
{
  int v3; // eax
  CMatRenderContextBase *v5; // ecx
  BOOL v6; // edx
  int m_pfnProxied; // edx
  BOOL v8; // edi
  __int128 _FFFFFFFC; // [esp-4h] [ebp-Ch]

  v3 = a3;
  if ( (_DWORD)a3 != 0 )
  {
    v5 = token;
    if ( token != nullptr )
    {
      switch ( LOBYTE(token->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable) )
      {
        case ' ':
          BYTE6(this->m_pfnProxied) |= 2u;
          goto LABEL_7;
        case '#':
          BYTE6(this->m_pfnProxied) |= 8u;
          goto LABEL_7;
        case '+':
          BYTE5(this->m_pfnProxied) |= 0x80u;
          goto LABEL_7;
        case '-':
          BYTE6(this->m_pfnProxied) |= 4u;
          goto LABEL_7;
        case '.':
          LODWORD(this->m_pfnProxied) &= 0xFFFFFFE0;
          m_pfnProxied = this->m_pfnProxied;
          v8 = v3 != 0;
          LODWORD(a3) = v3 - v8;
          token = (CMatRenderContextBase *)((char *)v5 + v8);
          LODWORD(this->m_pfnProxied) ^= ((unsigned __int8)G_ReadInteger(
                                                             nptr: (struct GStringDataPtr *)&token,
                                                             defaultValue: m_pfnProxied & 0x1F,
                                                             separator: 58)
                                        ^ (unsigned __int8)LODWORD(this->m_pfnProxied))
                                       & 0x1F;
          return;
        case '0':
          BYTE4(this->m_pfnProxied) = BYTE4(this->m_pfnProxied) & 0x80 | 0x30;
LABEL_7:
          v6 = v3 != 0;
          LODWORD(a3) = v3 - v6;
          token = (CMatRenderContextBase *)((char *)v5 + v6);
          LODWORD(_FFFFFFFC) = v3 - v6;
          GNumericBase::ReadPrintFormat(this, token: (CMatRenderContextBase *)((char *)v5 + v6), a3: _FFFFFFFC);
          break;
        default:
          LODWORD(_FFFFFFFC) = a3;
          GNumericBase::ReadWidth(this, token, a3: _FFFFFFFC);
          break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C6A0
// Name: public: virtual void GResourceFormatter::Parse(class GStringDataPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GResourceFormatter::Parse(
        CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int> *this,
        const CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int>::Iterator_t *str)
{
  int v2; // edx
  unsigned int v3; // esi
  unsigned int v4; // eax
  char v6; // cl
  int m_nAllocationCount; // eax
  struct GFormatter *v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // eax
  _DWORD v13[3]; // [esp+Ch] [ebp-1Ch] BYREF
  int v14; // [esp+18h] [ebp-10h] BYREF
  unsigned int v15; // [esp+1Ch] [ebp-Ch]
  unsigned int v16; // [esp+20h] [ebp-8h] BYREF
  unsigned int i; // [esp+24h] [ebp-4h]

  v2 = *(_DWORD *)str;
  v3 = *((_DWORD *)str + 1);
  v4 = 0;
  v16 = 0;
  for ( i = 0; v4 < v3; ++v4 )
  {
    v6 = *(_BYTE *)(v2 + v4);
    if ( v6 == 0 )
      break;
    if ( v6 == 58 )
      break;
  }
  v15 = v4;
  m_nAllocationCount = this->m_nAllocationCount;
  v8 = nullptr;
  v14 = v2;
  if ( *(_DWORD *)(m_nAllocationCount + 20) != 0 )
  {
    v13[1] = &v14;
    v13[2] = this + 1;
    v13[0] = m_nAllocationCount;
    v8 = (struct GFormatter *)(*(int (__thiscall **)(_DWORD, _DWORD *))(**(_DWORD **)(m_nAllocationCount + 20) + 4))(
                                a1: *(_DWORD *)(m_nAllocationCount + 20),
                                a2: v13);
  }
  v9 = *((_DWORD *)str + 1);
  v10 = v15 + 1;
  if ( v9 < v15 + 1 )
    v10 = *((_DWORD *)str + 1);
  v11 = v9 - v10;
  v16 = v10 + *(_DWORD *)str;
  i = v11;
  if ( v8 != nullptr )
  {
    if ( v11 != 0 )
      (*(void (__thiscall **)(struct GFormatter *, unsigned int *))(*(_DWORD *)v8 + 8))(a1: v8, a2: &v16);
    LOBYTE(v11) = GMsgFormat::ReplaceFormatter(
                    this: (GMsgFormat *)this->m_nAllocationCount,
                    a2: (struct GFormatter *)this,
                    a3: v8,
                    a4: true);
  }
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x1007C750
// Name: private: void GMsgFormat::BindNonPos(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMsgFormat::BindNonPos(
        CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int v2; // ecx
  unsigned __int16 v4; // [esp+0h] [ebp-38h]
  _DWORD v5[2]; // [esp+8h] [ebp-30h] BYREF
  char v6; // [esp+10h] [ebp-28h]
  int v7; // [esp+14h] [ebp-24h]
  int v8; // [esp+18h] [ebp-20h]
  int v9; // [esp+1Ch] [ebp-1Ch]
  int v10; // [esp+20h] [ebp-18h]
  int v11; // [esp+24h] [ebp-14h]
  int v12; // [esp+28h] [ebp-10h]
  int v13; // [esp+30h] [ebp-8h]

  v7 = 0;
  LOBYTE(v13) = 1;
  v5[1] = this;
  v6 = 0;
  v5[0] = &GResourceFormatter::`vftable';
  v8 = v13;
  v9 = 0;
  v11 = 0;
  v12 = 0;
  v10 = 0;
  v2 = *(_DWORD *)&this->m_FirstFree;
  if ( v2 != 0 )
    v10 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 12))(a1: v2);
  if ( GMsgFormat::NextFormatter((GMsgFormat *)this) != 0 )
    GMsgFormat::Bind((GMsgFormat *)this, a2: (struct GFormatter *)v5, a3: false);
  if ( HIWORD(this->m_Elements.m_pMemory)-- == 1 )
    GMsgFormat::MakeString(this);
  else
    GMsgFormat::BindNonPos(this, fr: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1007C7E0
// Name: public: void GMsgFormat::FinishFormatD(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMsgFormat::FinishFormatD(
        CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  if ( HIWORD(this->m_Elements.m_pMemory) != 0 )
  {
    BYTE1(this->m_Elements.m_pMemory) = -1;
    GMsgFormat::BindNonPos(this);
  }
  else
  {
    GMsgFormat::MakeString(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C9B0
// Name: public: virtual void GLongFormatter::Parse(class GStringDataPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GLongFormatter::Parse(
        int this,
        const CUtlFixedLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t> *result)
{
  CMatRenderContextBase *m_pBlocks; // edx
  unsigned int m_nAllocationCount; // eax
  unsigned int v5; // ebx
  char v6; // cl
  CMatRenderContextBase *v7; // edi
  unsigned int v8; // ecx
  unsigned int Size; // ebx
  CMatRenderContextBase *pStr; // edi
  unsigned int i; // eax
  char v12; // cl
  unsigned int v13; // ebx
  char v14; // cl
  unsigned int v15; // ecx
  int v16; // eax
  _DWORD *v17; // eax
  int v18; // edx
  struct GFormatter *v19; // edi
  unsigned int v20; // eax
  int v21; // ecx
  __int128 v23; // [esp-4h] [ebp-40h]
  _DWORD v24[3]; // [esp+Ch] [ebp-30h] BYREF
  int v25; // [esp+18h] [ebp-24h] BYREF
  char v26; // [esp+1Ch] [ebp-20h]
  int v27; // [esp+20h] [ebp-1Ch]
  _BYTE *v28; // [esp+24h] [ebp-18h] BYREF
  unsigned int v29; // [esp+28h] [ebp-14h]
  struct GStringDataPtr v30; // [esp+2Ch] [ebp-10h] BYREF
  struct GFormatter *v31; // [esp+34h] [ebp-8h]
  unsigned int v32; // [esp+38h] [ebp-4h]

  m_pBlocks = (CMatRenderContextBase *)result->m_Memory.m_pBlocks;
  m_nAllocationCount = result->m_Memory.m_nAllocationCount;
  v30.pStr = (const char *)result->m_Memory.m_pBlocks;
  v30.Size = m_nAllocationCount;
  v31 = nullptr;
  if ( m_nAllocationCount == 0 )
    return m_nAllocationCount;
  while ( 2 )
  {
    v5 = 0;
    v32 = 0;
    do
    {
      v6 = *((_BYTE *)&m_pBlocks->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable
           + v5);
      if ( v6 == 0 )
        break;
      if ( v6 == 58 )
        break;
      ++v5;
    }
    while ( v5 < m_nAllocationCount );
    v32 = v5;
    v7 = m_pBlocks;
    if ( m_pBlocks == nullptr || v5 == 0 )
      return m_nAllocationCount;
    v8 = v5 + 1;
    if ( m_nAllocationCount < v5 + 1 )
      v8 = m_nAllocationCount;
    v30.pStr = (char *)m_pBlocks + v8;
    v30.Size = m_nAllocationCount - v8;
    if ( isdigit(c: SLOBYTE(m_pBlocks->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable)) != 0 )
    {
$LN16_7:
      LODWORD(v23) = v5;
      GNumericBase::ReadPrintFormat(
        this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float,float),CFuncMemPolicyNone> *)(this + 16),
        token: v7,
        a3: v23);
LABEL_36:
      m_nAllocationCount = v30.Size;
      goto LABEL_37;
    }
    switch ( LOBYTE(v7->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable) )
    {
      case ' ':
      case '#':
      case '+':
      case '-':
      case '.':
        goto $LN16_7;
      case 'X':
        goto $LN92;
      case 'b':
        if ( strncmp(first: (const char *)v7, last: "base", count: 4u) == 0 )
          *(_DWORD *)(this + 28) ^= ((unsigned __int8)G_ReadInteger(nptr: &v30, defaultValue: 10, separator: 58)
                                   ^ (unsigned __int8)*(_DWORD *)(this + 28))
                                  & 0x1F;
        goto LABEL_36;
      case 'o':
        Size = v30.Size;
        pStr = (CMatRenderContextBase *)v30.pStr;
        i = 0;
        for ( *(_DWORD *)(this + 28) = *(_DWORD *)(this + 28) & 0xFFFFFFE0 | 8; i < Size; ++i )
        {
          v12 = *((_BYTE *)&pStr->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable
                + i);
          if ( v12 == 0 )
            break;
          if ( v12 == 58 )
            break;
        }
        goto LABEL_20;
      case 's':
        if ( BYTE1(v7->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable) != 119 )
        {
          if ( strncmp(first: (const char *)v7, last: "sep", count: 3u) != 0 )
            goto LABEL_36;
          GStringDataPtr::GetNextToken(this: &v30, a2: &v28, separator: 58);
          v15 = v29;
          if ( v29 != 0 )
            *(_BYTE *)(this + 21) ^= (*(_BYTE *)(this + 21) ^ *v28) & 0x7F;
          if ( v30.Size < v15 )
            v15 = v30.Size;
          v30.pStr += v15;
          m_nAllocationCount = v30.Size - v15;
          v30.Size -= v15;
LABEL_37:
          if ( m_nAllocationCount == 0 )
            goto LABEL_43;
          m_pBlocks = (CMatRenderContextBase *)v30.pStr;
          continue;
        }
        v17 = GStackMemPool<512,4,GMemPoolImmediateFree>::Alloc(
                this: (GMemoryHeap **)(*(_DWORD *)(this + 4) + 244),
                nbytes: 0x24u);
        if ( v17 != nullptr )
        {
          v18 = *(_DWORD *)(this + 40);
          v17[1] = *(_DWORD *)(this + 4);
          *((_BYTE *)v17 + 8) = 0;
          *v17 = &pstr._Mydofree;
          v17[3] = v18;
          v17[4] = 0;
          v17[5] = 0;
          v17[6] = 0;
          v17[7] = 0;
          v17[8] = 0;
          v31 = (struct GFormatter *)v17;
        }
        else
        {
          v31 = nullptr;
        }
        LOBYTE(m_nAllocationCount) = v30.Size;
        v30.pStr += v30.Size;
        v30.Size = 0;
LABEL_43:
        v19 = v31;
        if ( v31 != nullptr )
        {
          v20 = result->m_Memory.m_nAllocationCount;
          v21 = v5 + 1;
          if ( v20 < v5 + 1 )
            v21 = result->m_Memory.m_nAllocationCount;
          v28 = (char *)result->m_Memory.m_pBlocks + v21;
          v29 = v20 - v21;
          if ( v20 != v21 )
            (*(void (__thiscall **)(struct GFormatter *, _BYTE **))(*(_DWORD *)v31 + 8))(a1: v31, a2: &v28);
          LOBYTE(m_nAllocationCount) = GMsgFormat::ReplaceFormatter(
                                         this: *(GMsgFormat **)(this + 4),
                                         a2: (struct GFormatter *)this,
                                         a3: v19,
                                         a4: true);
        }
        return m_nAllocationCount;
      case 'x':
        *(_BYTE *)(this + 22) &= ~1u;
$LN92:
        v13 = v30.Size;
        pStr = (CMatRenderContextBase *)v30.pStr;
        *(_DWORD *)(this + 28) = *(_DWORD *)(this + 28) & 0xFFFFFFE0 | 0x10;
        for ( i = 0; i < v13; ++i )
        {
          v14 = *((_BYTE *)&pStr->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable
                + i);
          if ( v14 == 0 )
            break;
          if ( v14 == 58 )
            break;
        }
LABEL_20:
        LODWORD(v23) = i;
        GNumericBase::ReadPrintFormat(
          this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float,float),CFuncMemPolicyNone> *)(this + 16),
          token: pStr,
          a3: v23);
        v5 = v32;
        goto LABEL_36;
      default:
        v16 = *(_DWORD *)(this + 4);
        if ( *(_DWORD *)(v16 + 20) != 0 )
        {
          v25 = *(_DWORD *)(this + 40);
          v24[0] = v16;
          v24[1] = &v30;
          v26 = 0;
          v27 = 0;
          v24[2] = &v25;
          v31 = (struct GFormatter *)(*(int (__thiscall **)(_DWORD, _DWORD *))(**(_DWORD **)(v16 + 20) + 4))(
                                       a1: *(_DWORD *)(v16 + 20),
                                       a2: v24);
        }
        goto LABEL_36;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CCC0
// Name: public: virtual void GDoubleFormatter::Parse(class GStringDataPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDoubleFormatter::Parse(GDoubleFormatter *this, const struct GStringDataPtr *a2)
{
  const char *pStr; // edx
  unsigned int Size; // ecx
  unsigned int v5; // esi
  char v6; // al
  char *v7; // edi
  unsigned int v8; // eax
  unsigned int v9; // esi
  CMatRenderContextBase *v10; // edx
  unsigned int v11; // eax
  char v12; // cl
  unsigned int v13; // esi
  CMatRenderContextBase *v14; // edi
  unsigned int v15; // eax
  char v16; // cl
  unsigned int v17; // esi
  char v18; // cl
  unsigned int m_nUserID; // edi
  double v20; // st7
  double v21; // st7
  _DWORD *v22; // esi
  double v23; // st7
  double v24; // st7
  struct GFormatter *v25; // edi
  unsigned int v26; // eax
  unsigned int v27; // ecx
  __int128 v28; // [esp-4h] [ebp-40h]
  _DWORD v29[3]; // [esp+Ch] [ebp-30h] BYREF
  int v30; // [esp+18h] [ebp-24h] BYREF
  char v31; // [esp+1Ch] [ebp-20h]
  int v32; // [esp+20h] [ebp-1Ch]
  const char *v33; // [esp+24h] [ebp-18h] BYREF
  unsigned int v34; // [esp+28h] [ebp-14h]
  const char *v35; // [esp+2Ch] [ebp-10h] BYREF
  unsigned int v36; // [esp+30h] [ebp-Ch]
  struct GFormatter *v37; // [esp+34h] [ebp-8h]
  unsigned int v38; // [esp+38h] [ebp-4h]

  pStr = a2->pStr;
  Size = a2->Size;
  v35 = a2->pStr;
  v36 = Size;
  v37 = nullptr;
  if ( Size == 0 )
    return;
  while ( 2 )
  {
    v5 = 0;
    v38 = 0;
    if ( Size != 0 )
    {
      do
      {
        v6 = pStr[v5];
        if ( v6 == 0 )
          break;
        if ( v6 == 58 )
          break;
        ++v5;
      }
      while ( v5 < Size );
      v38 = v5;
    }
    v7 = (char *)pStr;
    if ( pStr == nullptr || v5 == 0 )
      return;
    v8 = v5 + 1;
    if ( Size < v5 + 1 )
      v8 = Size;
    v35 = &pStr[v8];
    v36 = Size - v8;
    if ( isdigit(c: *pStr) != 0 )
    {
LABEL_13:
      LODWORD(v28) = v5;
      GNumericBase::ReadPrintFormat(
        this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float,float),CFuncMemPolicyNone> *)&this->m_Proxy,
        token: (CMatRenderContextBase *)v7,
        a3: v28);
      goto LABEL_40;
    }
    switch ( *v7 )
    {
      case ' ':
      case '#':
      case '+':
      case '-':
      case '.':
        goto LABEL_13;
      case 'E':
        goto LABEL_20;
      case 'G':
        goto LABEL_26;
      case 'e':
        BYTE6(this->m_Proxy.m_pfnProxied) &= ~1u;
LABEL_20:
        v13 = v36;
        v14 = (CMatRenderContextBase *)v35;
        v15 = 0;
        for ( *((_DWORD *)&this->m_Proxy.m_pObject + 1) = 1; v15 < v13; ++v15 )
        {
          v16 = *((_BYTE *)&v14->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable
                + v15);
          if ( v16 == 0 )
            break;
          if ( v16 == 58 )
            break;
        }
        goto LABEL_24;
      case 'f':
        v9 = v36;
        v10 = (CMatRenderContextBase *)v35;
        v11 = 0;
        for ( *((_DWORD *)&this->m_Proxy.m_pObject + 1) = 0; v11 < v9; ++v11 )
        {
          v12 = *((_BYTE *)&v10->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable
                + v11);
          if ( v12 == 0 )
            break;
          if ( v12 == 58 )
            break;
        }
        LODWORD(v28) = v11;
        GNumericBase::ReadPrintFormat(
          this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float,float),CFuncMemPolicyNone> *)&this->m_Proxy,
          token: v10,
          a3: v28);
        v5 = v38;
        goto LABEL_40;
      case 'g':
        BYTE6(this->m_Proxy.m_pfnProxied) &= ~1u;
LABEL_26:
        v17 = v36;
        v14 = (CMatRenderContextBase *)v35;
        v15 = 0;
        for ( *((_DWORD *)&this->m_Proxy.m_pObject + 1) = 2; v15 < v17; ++v15 )
        {
          v18 = *((_BYTE *)&v14->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable
                + v15);
          if ( v18 == 0 )
            break;
          if ( v18 == 58 )
            break;
        }
LABEL_24:
        LODWORD(v28) = v15;
        GNumericBase::ReadPrintFormat(
          this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,float,float,float,float),CFuncMemPolicyNone> *)&this->m_Proxy,
          token: v14,
          a3: v28);
        v5 = v38;
        goto LABEL_40;
      case 's':
        if ( v7[1] != 119 )
        {
          if ( strncmp(first: v7, last: "sep", count: 3u) == 0 )
          {
            GStringDataPtr::GetNextToken(this: &v35, a2: &v33, separator: 58);
            if ( v34 != 0 )
              BYTE5(this->m_Proxy.m_pfnProxied) ^= (BYTE5(this->m_Proxy.m_pfnProxied) ^ *v33) & 0x7F;
          }
LABEL_40:
          Size = v36;
          if ( v36 == 0 )
            goto LABEL_49;
          pStr = v35;
          continue;
        }
        v22 = GStackMemPool<512,4,GMemPoolImmediateFree>::Alloc(
                this: (GMemoryHeap **)(this->m_nUserID + 244),
                nbytes: 0x24u);
        if ( v22 != nullptr )
        {
          v23 = *((double *)this + 4);
          if ( v23 <= 0.0 )
            v24 = v23 - 0.5;
          else
            v24 = v23 + 0.5;
          v22[1] = this->m_nUserID;
          *((_BYTE *)v22 + 8) = 0;
          *v22 = &pstr._Mydofree;
          v22[3] = (int)v24;
          v22[4] = 0;
          v22[5] = 0;
          v22[6] = 0;
          v22[7] = 0;
          v22[8] = 0;
          v37 = (struct GFormatter *)v22;
        }
        else
        {
          v37 = nullptr;
        }
        v35 += v36;
        v5 = v38;
        v36 = 0;
LABEL_49:
        v25 = v37;
        if ( v37 != nullptr )
        {
          v26 = a2->Size;
          v27 = v5 + 1;
          if ( v26 < v5 + 1 )
            v27 = a2->Size;
          v33 = &a2->pStr[v27];
          v34 = v26 - v27;
          if ( v26 != v27 )
            (*(void (__thiscall **)(struct GFormatter *, const char **))(*(_DWORD *)v37 + 8))(a1: v37, a2: &v33);
          GMsgFormat::ReplaceFormatter(
            this: (GMsgFormat *)this->m_nUserID,
            a2: (struct GFormatter *)this,
            a3: v25,
            a4: true);
        }
        return;
      default:
        m_nUserID = this->m_nUserID;
        if ( *(_DWORD *)(m_nUserID + 20) != 0 )
        {
          v20 = *((double *)this + 4);
          if ( v20 <= 0.0 )
            v21 = v20 - 0.5;
          else
            v21 = v20 + 0.5;
          v30 = (int)v21;
          v29[1] = &v35;
          v29[2] = &v30;
          v31 = 1;
          v32 = 0;
          v29[0] = m_nUserID;
          v37 = (struct GFormatter *)(*(int (__thiscall **)(_DWORD, _DWORD *))(**(_DWORD **)(m_nUserID + 20) + 4))(
                                       a1: *(_DWORD *)(m_nUserID + 20),
                                       a2: v29);
        }
        goto LABEL_40;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CFF0
// Name: public: virtual GMsgFormat::~GMsgFormat(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMsgFormat::~GMsgFormat(
        CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  ICommandCompletionCallback_vtbl *v2; // eax
  unsigned int v3; // ebx
  int v4; // ecx
  char *v5; // eax
  char *v6; // esi
  ICommandCompletionCallback data_sizea; // [esp+8h] [ebp-8h]
  int v8; // [esp+Ch] [ebp-4h]

  v2 = *((ICommandCompletionCallback_vtbl **)this + 9);
  v3 = 0;
  this->m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))&GMsgFormat::`vftable';
  data_sizea.__vftable = v2;
  if ( v2 != nullptr )
  {
    v4 = -192;
    v8 = -192;
    do
    {
      if ( v3 >= 0x10 )
        v5 = (char *)(v4 + *((_DWORD *)this + 10));
      else
        v5 = (char *)this + v4 + 244;
      if ( *(_DWORD *)v5 == 2 && v5[8] != 0 )
      {
        v6 = *((char **)v5 + 1);
        if ( v6 != nullptr )
        {
          (**(void (__thiscall ***)(void *, _DWORD))v6)(a1: v6, a2: 0);
          if ( v6 < (char *)this + 248 || v6 >= (char *)this + 760 )
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
        }
      }
      ++v3;
      v4 = v8 + 12;
      v8 += 12;
    }
    while ( v3 < (unsigned int)data_sizea.__vftable );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 10));
  this->m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))&GString::InitStruct::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1007D220
// Name: public: virtual void GSwitchFormatter::Convert(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GSwitchFormatter::Convert(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this@<ecx>,
        unsigned int *a2@<ebx>)
{
  unsigned __int16 *p_m_FirstFree; // edi
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v5; // ecx

  if ( LOBYTE(this->m_Elements.m_nAllocationCount) == 0 )
  {
    p_m_FirstFree = &this->m_FirstFree;
    GHashSetBase<GHashNode<int,GStringDataPtr,GFixedSizeHash<int>>,GHashNode<int,GStringDataPtr,GFixedSizeHash<int>>::NodeHashF,GHashNode<int,GStringDataPtr,GFixedSizeHash<int>>::NodeAltHashF,GAllocatorGH<int,2>,GHashsetCachedNodeEntry<GHashNode<int,GStringDataPtr,GFixedSizeHash<int>>,GHashNode<int,GStringDataPtr,GFixedSizeHash<int>>::NodeHashF>>::GetAlt<int>(
      this: (IFileSystem *)&this->m_Root,
      a2,
      a3: (unsigned int *)this,
      key: (void *(__thiscall **)(IAppSystem *, const char *))&this->m_Elements.m_nGrowSize);
    if ( v4 != 0 )
    {
      if ( this != (CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *)-20 )
      {
        *(_DWORD *)p_m_FirstFree = *(_DWORD *)(v4 + 4);
        this->m_pElements = *(UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> **)(v4 + 8);
        LOBYTE(this->m_Elements.m_nAllocationCount) = 1;
        return;
      }
    }
    else
    {
      v5 = *((UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> **)this + 8);
      *(_DWORD *)p_m_FirstFree = *((_DWORD *)this + 7);
      this->m_pElements = v5;
    }
    LOBYTE(this->m_Elements.m_nAllocationCount) = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D270
// Name: public: GMsgFormat::GMsgFormat(class GMsgFormat::Sink const __near &)
// Source: json
//------------------------------------------------------------------------------
GMsgFormat *__thiscall GMsgFormat::GMsgFormat(GMsgFormat *this, const struct GMsgFormat::Sink *a2)
{
  const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> *v3; // edx

  *(this + 3) = nullptr;
  *(this + 5) = nullptr;
  *this = (GMsgFormat)&GMsgFormat::`vftable';
  *(this + 1) = (GMsgFormat)37;
  *((_WORD *)this + 4) = -1;
  *(this + 6) = *(GMsgFormat *)a2;
  *(this + 7) = *((GMsgFormat *)a2 + 1);
  *(this + 8) = *((GMsgFormat *)a2 + 2);
  *(this + 9) = nullptr;
  *(this + 10) = nullptr;
  *(this + 11) = nullptr;
  *(this + 12) = nullptr;
  *(this + 61) = nullptr;
  v3 = (const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> *)((((unsigned int)this + 247) & 0xFFFFFFFC) + 4);
  *(this + 191) = (GMsgFormat)((char *)(this + 61) - (char *)v3 + 516);
  *(this + 190) = v3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007D320
// Name: private: void GMsgFormat::AddStringRecord(class GStringDataPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall GMsgFormat::AddStringRecord(int this, int *a2)
{
  int v3; // ecx
  unsigned int v4; // eax
  _DWORD *result; // eax
  unsigned int v6; // esi
  int v7; // ecx
  int v8; // [esp+Ch] [ebp-10h]
  int v9; // [esp+18h] [ebp-4h]

  v3 = *a2;
  LOBYTE(v9) = *((_BYTE *)a2 + 4);
  v4 = *(_DWORD *)(this + 36);
  v8 = *a2;
  if ( v4 >= 0x10 )
  {
    v6 = *(_DWORD *)(this + 44) + 1;
    if ( v6 >= *(_DWORD *)(this + 44) )
    {
      if ( v6 >= *(_DWORD *)(this + 48) )
        GArrayDataBase<CSSToken<wchar_t>,GAllocatorGH<CSSToken<wchar_t>,2>,GArrayDefaultPolicy>::Reserve(
          this: (void **)(this + 40),
          pheapAddr: (ButtonCode_t)(this + 40),
          newCapacity: v6 + (v6 >> 2));
    }
    else if ( v6 < *(_DWORD *)(this + 48) >> 1 )
    {
      GArrayDataBase<CSSToken<wchar_t>,GAllocatorGH<CSSToken<wchar_t>,2>,GArrayDefaultPolicy>::Reserve(
        this: (void **)(this + 40),
        pheapAddr: (ButtonCode_t)(this + 40),
        newCapacity: v6);
    }
    v7 = *(_DWORD *)(this + 40);
    *(_DWORD *)(this + 44) = v6;
    result = (_DWORD *)(v7 + 12 * v6 - 12);
    *result = 0;
    result[1] = v8;
    result[2] = v9;
    ++*(_DWORD *)(this + 36);
  }
  else
  {
    result = (_DWORD *)(this + 12 * v4 + 52);
    *result = 0;
    result[1] = v3;
    result[2] = v9;
    ++*(_DWORD *)(this + 36);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007D3C0
// Name: private: void GMsgFormat::AddFormatterRecord(class GFormatter __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMsgFormat::AddFormatterRecord(GMsgFormat *this, struct GFormatter *a2, bool a3)
{
  unsigned int v4; // eax
  GMsgFormat *v5; // eax
  unsigned int v6; // esi
  int v7; // ecx
  _DWORD *v8; // eax
  const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> *v9; // [esp+18h] [ebp-4h]

  v4 = (unsigned int)*(this + 9);
  LOBYTE(v9) = a3;
  if ( v4 >= 0x10 )
  {
    v6 = (unsigned int)&(*(this + 11))->m_pMemory + 1;
    if ( v6 >= (unsigned int)*(this + 11) )
    {
      if ( v6 >= (unsigned int)*(this + 12) )
        GArrayDataBase<CSSToken<wchar_t>,GAllocatorGH<CSSToken<wchar_t>,2>,GArrayDefaultPolicy>::Reserve(
          this: (void **)this + 10,
          pheapAddr: (ButtonCode_t)(this + 10),
          newCapacity: v6 + (v6 >> 2));
    }
    else if ( v6 < (unsigned int)*(this + 12) >> 1 )
    {
      GArrayDataBase<CSSToken<wchar_t>,GAllocatorGH<CSSToken<wchar_t>,2>,GArrayDefaultPolicy>::Reserve(
        this: (void **)this + 10,
        pheapAddr: (ButtonCode_t)(this + 10),
        newCapacity: v6);
    }
    v7 = (int)*(this + 10);
    *(this + 11) = (GMsgFormat)v6;
    v8 = (_DWORD *)(v7 + 12 * v6 - 12);
    *v8 = 2;
    v8[1] = a2;
    v8[2] = v9;
    *(this + 9) = (GMsgFormat)((char *)*(this + 9) + 1);
  }
  else
  {
    v5 = this + 3 * v4 + 13;
    *v5 = (GMsgFormat)2;
    v5[1] = (GMsgFormat)a2;
    v5[2] = v9;
    *(this + 9) = (GMsgFormat)((char *)*(this + 9) + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D460
// Name: public: void GMsgFormat::Parse(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *__thiscall GMsgFormat::Parse(
        _WORD *this,
        CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *result)
{
  int v3; // esi
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v4; // eax
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v5; // ebx
  int v6; // ecx
  char v7; // al
  char m_LessFunc; // cl
  unsigned int v9; // eax
  int v10; // ecx
  char *v11; // eax
  ButtonCode_t v12; // ebx
  unsigned int v13; // esi
  char *v14; // eax
  int v15; // edx
  unsigned int v16; // eax
  int v17; // ecx
  ButtonCode_t v18; // ebx
  unsigned int v19; // esi
  char *v20; // ecx
  int v21; // eax
  _WORD *v22; // esi
  int v23; // ecx
  int m_LessFunc_low; // [esp-4h] [ebp-40h]
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v25; // [esp+10h] [ebp-2Ch]
  UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short> *v26; // [esp+10h] [ebp-2Ch]
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v27; // [esp+18h] [ebp-24h] BYREF
  char *v28; // [esp+1Ch] [ebp-20h]
  int v29[3]; // [esp+20h] [ebp-1Ch] BYREF
  int v30; // [esp+2Ch] [ebp-10h]
  _WORD *v31; // [esp+30h] [ebp-Ch]
  int v32; // [esp+34h] [ebp-8h]
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v33; // [esp+38h] [ebp-4h]
  bool escape; // [esp+47h] [ebp+Bh]

  v3 = (int)this;
  v4 = result;
  v31 = this;
  v32 = 0;
  v33 = result;
  v5 = result;
  *(this + 4) = -1;
  escape = false;
  if ( v4 == nullptr )
    return v4;
  *(this + 3) = 0;
  if ( LOBYTE(result->m_LessFunc.m_LessFunc) == 0 )
    return v4;
  do
  {
    if ( v32 != 0 )
    {
      if ( v32 != 1 )
        continue;
      if ( LOBYTE(v4->m_LessFunc.m_LessFunc) == 125 )
      {
        if ( v5 != v4 )
        {
          m_LessFunc_low = SLOBYTE(v5->m_LessFunc.m_LessFunc);
          v32 = 255;
          if ( isspace(c: m_LessFunc_low) != 0 )
          {
            do
            {
              v6 = SBYTE1(v5->m_LessFunc.m_LessFunc);
              v5 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)((char *)v5 + 1);
            }
            while ( isspace(c: v6) != 0 );
          }
          if ( isdigit(c: SLOBYTE(v5->m_LessFunc.m_LessFunc)) != 0 )
          {
            v7 = atoi(nptr: (const char *)v5);
            m_LessFunc = (char)v5->m_LessFunc.m_LessFunc;
            if ( LOBYTE(v5->m_LessFunc.m_LessFunc) != 0 )
            {
              while ( m_LessFunc != 58 && m_LessFunc != 125 )
              {
                m_LessFunc = BYTE1(v5->m_LessFunc.m_LessFunc);
                v5 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)((char *)v5 + 1);
                if ( m_LessFunc == 0 )
                  goto LABEL_18;
              }
              if ( LOBYTE(v5->m_LessFunc.m_LessFunc) == 58 )
                v5 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)((char *)v5 + 1);
            }
          }
          else
          {
            ++*(_WORD *)(v3 + 6);
            v7 = v32;
          }
LABEL_18:
          BYTE1(v30) = v7;
          v9 = *(_DWORD *)(v3 + 36);
          LOBYTE(v30) = (_BYTE)v33 - (_BYTE)v5;
          v10 = v30;
          v25 = v5;
          if ( v9 >= 0x10 )
          {
            v12 = v3 + 40;
            v13 = *(_DWORD *)(v3 + 44) + 1;
            if ( v13 >= *(_DWORD *)(v12 + 4) )
            {
              if ( v13 >= *(_DWORD *)(v12 + 8) )
                GArrayDataBase<CSSToken<wchar_t>,GAllocatorGH<CSSToken<wchar_t>,2>,GArrayDefaultPolicy>::Reserve(
                  this: (void **)v12,
                  pheapAddr: v12,
                  newCapacity: v13 + (v13 >> 2));
            }
            else if ( v13 < *(_DWORD *)(v12 + 8) >> 1 )
            {
              GArrayDataBase<CSSToken<wchar_t>,GAllocatorGH<CSSToken<wchar_t>,2>,GArrayDefaultPolicy>::Reserve(
                this: (void **)v12,
                pheapAddr: v12,
                newCapacity: v13);
            }
            v14 = *(char **)v12;
            v15 = 3 * v13;
            *(_DWORD *)(v12 + 4) = v13;
            v3 = (int)v31;
            v11 = &v14[4 * v15 - 12];
            *(_DWORD *)v11 = 1;
            *((_DWORD *)v11 + 1) = v25;
            v10 = v30;
          }
          else
          {
            v11 = (char *)(v3 + 12 * v9 + 52);
            *(_DWORD *)v11 = 1;
            *((_DWORD *)v11 + 1) = v5;
          }
          *((_DWORD *)v11 + 2) = v10;
          ++*(_DWORD *)(v3 + 36);
          if ( *(_WORD *)(v3 + 8) == 0xFFFF )
            *(_WORD *)(v3 + 8) = *(_WORD *)(v3 + 36) - 1;
          v4 = v33;
        }
        v4 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)((char *)v4 + 1);
        v5 = v4;
        v32 = 0;
      }
      else
      {
        v4 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)((char *)v4 + 1);
      }
      goto LABEL_34;
    }
    if ( escape )
    {
      escape = false;
LABEL_33:
      v4 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)((char *)v4 + 1);
LABEL_34:
      v33 = v4;
      continue;
    }
    if ( LOBYTE(v4->m_LessFunc.m_LessFunc) == 123 )
    {
      if ( v5 != v4 )
      {
        v29[0] = (int)v5;
        v29[1] = (char *)v4 - (char *)v5;
        GMsgFormat::AddStringRecord(this: v3, a2: v29);
        v4 = v33;
      }
      v4 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)((char *)v4 + 1);
      v5 = v4;
      v32 = 1;
      goto LABEL_34;
    }
    if ( SLOBYTE(v4->m_LessFunc.m_LessFunc) != *(unsigned __int8 *)(v3 + 4) || BYTE1(v4->m_LessFunc.m_LessFunc) == 0 )
      goto LABEL_33;
    if ( v5 != v4 )
    {
      v27 = v5;
      v28 = (char *)((char *)v4 - (char *)v5);
      GMsgFormat::AddStringRecord(this: v3, a2: (int *)&v27);
      v4 = v33;
    }
    v4 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)((char *)v4 + 1);
    v33 = v4;
    v5 = v4;
    escape = true;
  }
  while ( LOBYTE(v4->m_LessFunc.m_LessFunc) != 0 );
  if ( v32 == 0 && v5 != v4 )
  {
    LOBYTE(v28) = (_BYTE)v4 - (_BYTE)v5;
    v16 = *(_DWORD *)(v3 + 36);
    v17 = (int)v28;
    v26 = (UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short> *)v5;
    if ( v16 >= 0x10 )
    {
      v18 = v3 + 40;
      v19 = *(_DWORD *)(v3 + 44) + 1;
      if ( v19 >= *(_DWORD *)(v18 + 4) )
      {
        if ( v19 >= *(_DWORD *)(v18 + 8) )
          GArrayDataBase<CSSToken<wchar_t>,GAllocatorGH<CSSToken<wchar_t>,2>,GArrayDefaultPolicy>::Reserve(
            this: (void **)v18,
            pheapAddr: v18,
            newCapacity: v19 + (v19 >> 2));
      }
      else if ( v19 < *(_DWORD *)(v18 + 8) >> 1 )
      {
        GArrayDataBase<CSSToken<wchar_t>,GAllocatorGH<CSSToken<wchar_t>,2>,GArrayDefaultPolicy>::Reserve(
          this: (void **)v18,
          pheapAddr: v18,
          newCapacity: v19);
      }
      v20 = *(char **)v18;
      *(_DWORD *)(v18 + 4) = v19;
      v21 = 3 * v19;
      v22 = v31;
      v4 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&v20[4 * v21 - 12];
      v23 = (int)v28;
      v4->m_LessFunc.m_LessFunc = nullptr;
      v4->m_Elements.m_pMemory = v26;
      v4->m_Elements.m_nAllocationCount = v23;
      ++*((_DWORD *)v22 + 9);
    }
    else
    {
      v4 = (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v3 + 12 * v16 + 52);
      v4->m_LessFunc.m_LessFunc = nullptr;
      v4->m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short> *)v5;
      v4->m_Elements.m_nAllocationCount = v17;
      ++*(_DWORD *)(v3 + 36);
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1007D700
// Name: unsigned int G_SPrintF(class GMsgFormat::Sink const __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
const IFileSystem *__usercall G_SPrintF@<eax>(const char *const *a1@<edi>, const IFileSystem *result, const char *a3)
{
  const char *v3; // edx
  unsigned int v4; // eax
  unsigned int v5; // ebx
  const char **v6; // esi
  int v7; // edi
  int v8; // eax
  int v9; // esi
  bool v11; // zf
  unsigned int v12; // ecx
  unsigned int v13; // edx
  const char *const *v14; // ebx
  int v15; // eax
  _DWORD *v16; // eax
  GLongFormatter *v17; // edi
  _DWORD *v18; // eax
  unsigned int v19; // eax
  GLongFormatter *v20; // eax
  GDoubleFormatter *v21; // eax
  int v22; // ecx
  GStrFormatter *v23; // eax
  struct GFormatter *v24; // eax
  unsigned int v25; // ecx
  const char *const *v26; // [esp+8h] [ebp-364h]
  int v27[2]; // [esp+14h] [ebp-358h] BYREF
  _DWORD v28[2]; // [esp+1Ch] [ebp-350h] BYREF
  int v29[2]; // [esp+24h] [ebp-348h] BYREF
  _DWORD v30[2]; // [esp+2Ch] [ebp-340h] BYREF
  _DWORD v31[2]; // [esp+34h] [ebp-338h] BYREF
  unsigned int v32; // [esp+3Ch] [ebp-330h]
  int v33; // [esp+40h] [ebp-32Ch]
  int v34; // [esp+44h] [ebp-328h]
  int v35; // [esp+48h] [ebp-324h]
  unsigned int v36; // [esp+4Ch] [ebp-320h]
  const char *v37; // [esp+50h] [ebp-31Ch] BYREF
  unsigned int v38; // [esp+54h] [ebp-318h]
  double v39; // [esp+58h] [ebp-314h]
  const IFileSystem **p_result; // [esp+60h] [ebp-30Ch]
  char v41; // [esp+66h] [ebp-306h]
  char v42; // [esp+67h] [ebp-305h]
  const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> *parsed_format; // [esp+68h] [ebp-304h] BYREF
  int v44; // [esp+74h] [ebp-2F8h]
  GMemoryHeap *v45[131]; // [esp+15Ch] [ebp-210h] BYREF

  GMsgFormat::GMsgFormat(this: &parsed_format, a2: (const struct GMsgFormat::Sink *)result);
  v3 = a3;
  if ( a3 != nullptr )
    v4 = strlen(a3);
  else
    v4 = 0;
  if ( v4 != 0 )
  {
    v5 = v4;
    v26 = a1;
    v37 = a3;
    v38 = v4;
    p_result = &result;
    v6 = &a3;
    while ( 1 )
    {
      v7 = 0;
      v8 = 0;
      while ( v3[v8] != 37 )
      {
        if ( ++v8 >= v5 )
          goto LABEL_9;
      }
      if ( v8 < 0 )
        break;
      v36 = v8;
      if ( v5 <= v8 + 1 )
      {
        GMsgFormat::AddStringRecord(this: (int)&parsed_format, a2: (int *)&v37);
      }
      else
      {
        v11 = v3[v8 + 1] == 37;
        v36 = v8 + 1;
        if ( !v11 )
        {
          v34 = 10;
          v41 = 0;
          v42 = 0;
          v33 = 0;
          v12 = v5 - v8;
          if ( v5 < v8 )
            v12 = v5;
          v27[0] = (int)v3;
          v27[1] = v5 - v12;
          GMsgFormat::AddStringRecord(this: (int)&parsed_format, a2: v27);
          v13 = v36;
          v14 = nullptr;
          v15 = 0;
          v32 = v36;
          LODWORD(v39) = 0;
          v35 = 0;
          if ( v36 < v38 )
          {
            while ( 2 )
            {
              switch ( v37[v13] )
              {
                case 'E':
                  v41 = 1;
                  goto $LN28_3;
                case 'G':
                  v41 = 1;
                  goto $LN26_5;
                case 'I':
                  v15 = 3;
                  goto LABEL_22;
                case 'X':
                  v41 = 1;
                  goto $LN31_4;
                case 'd':
                case 'i':
                  ++p_result;
                  ++v6;
                  if ( v15 == 2 )
                  {
                    v7 = 2;
                    v14 = (const char *const *)*v6;
                    LODWORD(v39) = *v6;
                    *(_QWORD *)&v39 = SLODWORD(v39);
                  }
                  else
                  {
                    v14 = (const char *const *)*v6;
                    v7 = 1;
                    LODWORD(v39) = *v6;
                  }
                  break;
                case 'e':
$LN28_3:
                  v33 = 1;
                  goto LABEL_42;
                case 'f':
                  v33 = 0;
                  goto LABEL_42;
                case 'g':
$LN26_5:
                  v33 = 2;
LABEL_42:
                  v6 += 2;
                  v39 = *((double *)p_result + 1);
                  v14 = (const char *const *)LODWORD(v39);
                  v7 = 3;
                  p_result += 2;
                  break;
                case 'h':
                  v15 = 1;
                  goto LABEL_22;
                case 'l':
                  v15 = 2;
LABEL_22:
                  ++v35;
                  goto LABEL_23;
                case 'n':
                  v14 = *(const char *const **)v6[1];
                  ++v6;
                  ++p_result;
                  v7 = 1;
                  LODWORD(v39) = v14;
                  break;
                case 'o':
                  v14 = (const char *const *)v6[1];
                  ++v6;
                  ++p_result;
                  v7 = 1;
                  v34 = 8;
                  v42 = 1;
                  LODWORD(v39) = v14;
                  break;
                case 'p':
                  v14 = *(const char *const **)v6[1];
                  ++v6;
                  ++p_result;
                  v7 = 1;
                  v42 = 1;
                  LODWORD(v39) = v14;
                  v34 = 16;
                  break;
                case 's':
                  v7 = 4;
                  v14 = (const char *const *)v6[1];
                  ++v6;
                  ++p_result;
                  LODWORD(v39) = v14;
                  break;
                case 'u':
                  ++p_result;
                  v14 = (const char *const *)v6[1];
                  ++v6;
                  v42 = 1;
                  LODWORD(v39) = v14;
                  if ( v15 == 2 )
                    v7 = 2;
                  else
                    v7 = 1;
                  break;
                case 'x':
$LN31_4:
                  v14 = (const char *const *)v6[1];
                  ++v6;
                  ++p_result;
                  v7 = 1;
                  v42 = 1;
                  LODWORD(v39) = v14;
                  v34 = 16;
                  break;
                default:
LABEL_23:
                  v36 = ++v13;
                  if ( v13 >= v38 )
                    break;
                  continue;
              }
              break;
            }
          }
          switch ( v7 )
          {
            case 1:
              v30[0] = &v37[v32];
              v30[1] = v36 - v35 - v32;
              v16 = GStackMemPool<512,4,GMemPoolImmediateFree>::Alloc(this: v45, nbytes: 0x50u);
              if ( v42 != 0 )
              {
                if ( v16 != nullptr )
                {
                  v17 = (GLongFormatter *)GLongFormatter::GLongFormatter(a1: (int)v16, v: v14, a3: v26);
LABEL_50:
                  *((_DWORD *)v17 + 7) ^= ((unsigned __int8)v34 ^ (unsigned __int8)*((_DWORD *)v17 + 7)) & 0x1F;
                  v18 = v30;
                  goto LABEL_51;
                }
              }
              else if ( v16 != nullptr )
              {
                v17 = (GLongFormatter *)GLongFormatter::GLongFormatter(this: v16, result: (int)v14);
                goto LABEL_50;
              }
              v17 = nullptr;
              goto LABEL_50;
            case 2:
              v28[0] = &v37[v32];
              v28[1] = v36 - v35 - v32;
              v20 = (GLongFormatter *)GStackMemPool<512,4,GMemPoolImmediateFree>::Alloc(this: v45, nbytes: 0x50u);
              if ( v42 != 0 )
              {
                if ( v20 != nullptr )
                {
                  v17 = GLongFormatter::GLongFormatter(this: v20, a2: __PAIR64__(HIDWORD(v39), (unsigned int)v14));
                  *((_DWORD *)v17 + 7) ^= ((unsigned __int8)v34 ^ (unsigned __int8)*((_DWORD *)v17 + 7)) & 0x1F;
                  v18 = v28;
                  goto LABEL_51;
                }
              }
              else if ( v20 != nullptr )
              {
                v17 = GLongFormatter::GLongFormatter(this: v20, v: __SPAIR64__(HIDWORD(v39), (unsigned int)v14));
                *((_DWORD *)v17 + 7) ^= ((unsigned __int8)v34 ^ (unsigned __int8)*((_DWORD *)v17 + 7)) & 0x1F;
                v18 = v28;
                goto LABEL_51;
              }
              v17 = nullptr;
              MEMORY[0x1C] ^= ((unsigned __int8)v34 ^ MEMORY[0x1C]) & 0x1F;
              v18 = v28;
LABEL_51:
              *((_BYTE *)v17 + 22) ^= (v41 ^ *((_BYTE *)v17 + 22)) & 1;
LABEL_52:
              (*(void (__thiscall **)(GLongFormatter *, _DWORD *))(*(_DWORD *)v17 + 8))(a1: v17, a2: v18);
              GMsgFormat::AddFormatterRecord(this: &parsed_format, a2: v17, a3: true);
LABEL_53:
              v5 = v38;
              goto LABEL_54;
            case 3:
              v21 = (GDoubleFormatter *)GStackMemPool<512,4,GMemPoolImmediateFree>::Alloc(this: v45, nbytes: 0x188u);
              if ( v21 != nullptr )
                v17 = (GLongFormatter *)GDoubleFormatter::GDoubleFormatter(this: v21, v: v39);
              else
                v17 = nullptr;
              v31[0] = &v37[v32];
              v22 = v33;
              v31[1] = v36 - v32;
              *((_BYTE *)v17 + 22) ^= (v41 ^ *((_BYTE *)v17 + 22)) & 1;
              *((_DWORD *)v17 + 7) = v22;
              v18 = v31;
              goto LABEL_52;
            case 4:
              v23 = (GStrFormatter *)GStackMemPool<512,4,GMemPoolImmediateFree>::Alloc(this: v45, nbytes: 0x14u);
              if ( v23 != nullptr )
              {
                v24 = (struct GFormatter *)GStrFormatter::GStrFormatter(this: v23, a2: (const char *)v14);
                GMsgFormat::AddFormatterRecord(this: &parsed_format, a2: v24, a3: true);
              }
              else
              {
                GMsgFormat::AddFormatterRecord(this: &parsed_format, a2: nullptr, a3: true);
              }
              goto LABEL_53;
            default:
              goto LABEL_53;
          }
        }
        v25 = v5 - v8 - 1;
        if ( v5 < v25 )
          v25 = v5;
        v29[0] = (int)v3;
        v29[1] = v5 - v25;
        GMsgFormat::AddStringRecord(this: (int)&parsed_format, a2: v29);
      }
LABEL_54:
      v19 = v36 + 1;
      if ( v5 < v36 + 1 )
        v19 = v5;
      v37 += v19;
      v5 -= v19;
      v38 = v5;
      if ( v5 == 0 )
        goto LABEL_10;
      v3 = v37;
    }
LABEL_9:
    GMsgFormat::AddStringRecord(this: (int)&parsed_format, a2: (int *)&v37);
LABEL_10:
    GMsgFormat::MakeString(this: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&parsed_format);
  }
  v9 = v44;
  GMsgFormat::~GMsgFormat(this: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&parsed_format);
  return (const IFileSystem *)v9;
}

//------------------------------------------------------------------------------
// Address: 0x1007DE80
// Name: public: virtual void GSwitchFormatter::Parse(class GStringDataPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall GSwitchFormatter::Parse(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        int *str)
{
  const char *v2; // ebx
  int v3; // edx
  unsigned int v4; // edi
  unsigned int i; // eax
  char v6; // cl
  unsigned int v7; // ecx
  const char *v8; // esi
  int *result; // eax
  unsigned int v10; // edx
  int j; // eax
  int v12; // esi
  int v13; // edx
  bool v14; // [esp+0h] [ebp-20h]
  bool v15; // [esp+4h] [ebp-1Ch]
  FSAsyncControl_t__ **v16; // [esp+8h] [ebp-18h]
  _DWORD v17[2]; // [esp+Ch] [ebp-14h] BYREF
  IBaseFileSystem_vtbl *v18; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v19; // [esp+18h] [ebp-8h]
  IFileSystem *v20; // [esp+1Ch] [ebp-4h]
  _UNKNOWN *retaddr; // [esp+24h] [ebp+4h]

  v2 = (const char *)*str;
  v3 = 0;
  v4 = str[1];
  v20 = (IFileSystem *)this;
  v18 = nullptr;
  v19 = 0;
  str = nullptr;
  while ( 1 )
  {
    for ( i = 0; i < v4; ++i )
    {
      v6 = v2[i];
      if ( v6 == 0 )
        break;
      if ( v6 == 58 )
        break;
    }
    v7 = i + 1;
    v8 = v2;
    v18 = (IBaseFileSystem_vtbl *)v2;
    v19 = i;
    if ( v4 < i + 1 )
      v7 = v4;
    v2 += v7;
    v4 -= v7;
    if ( v3 != 0 )
    {
      v17[0] = &str;
      v17[1] = &v18;
      v10 = 5381;
      for ( j = 4; j != 0; --j )
      {
        v12 = *((unsigned __int8 *)&retaddr + j + 3);
        v10 = v12 + 65599 * v10;
      }
      result = GHashSetBase<GHashNode<int,GStringDataPtr,GFixedSizeHash<int>>,GHashNode<int,GStringDataPtr,GFixedSizeHash<int>>::NodeHashF,GHashNode<int,GStringDataPtr,GFixedSizeHash<int>>::NodeAltHashF,GAllocatorGH<int,2>,GHashsetCachedNodeEntry<GHashNode<int,GStringDataPtr,GFixedSizeHash<int>>,GHashNode<int,GStringDataPtr,GFixedSizeHash<int>>::NodeHashF>>::add<GHashNode<int,GStringDataPtr,GFixedSizeHash<int>>::NodeRef>(
                 this: v20 + 2,
                 pmemAddr: (const char *)&v20[2],
                 key: (const CUtlBuffer *)v17,
                 hashValue: v10,
                 a5: v14,
                 a6: v15,
                 a7: v16);
      v3 = 0;
      goto LABEL_16;
    }
    if ( i == 0 || v8 == nullptr || isdigit(c: *v8) == 0 )
      break;
    result = (int *)atoi(nptr: v8);
    str = result;
    v3 = 1;
LABEL_16:
    if ( v4 == 0 )
      return result;
  }
  result = (int *)v20;
  v13 = v19;
  v20[3].IBaseFileSystem::__vftable = v18;
  result[8] = v13;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10144F50
// Name: public: virtual unsigned int GFmtResource::Reflect(struct GFmtResource::TAttrs const __near * __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFmtResource::Reflect(GFmtResource *this, const struct GFmtResource::TAttrs **pstylesNum)
{
  *pstylesNum = nullptr;
  return 0;
}
