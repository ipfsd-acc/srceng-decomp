// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/loadsave_map.cpp
// Functions: 60
// ============================================================

#include "hammer\loadsave_map.h"

//------------------------------------------------------------------------------
// Address: 0x10036F00
// Name: public: __int64 std::basic_streambuf<char,struct std::char_traits<char>>::sgetn(char __near *,__int64)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall std::streambuf::sgetn(std::streambuf *this, char *_Ptr, __int64 _Count)
{
  return ((__int64 (__thiscall *)(std::streambuf *, char *, _DWORD, _DWORD))this->xsgetn)(
           a1: this,
           a2: _Ptr,
           a3: _Count,
           a4: HIDWORD(_Count));
}

//------------------------------------------------------------------------------
// Address: 0x10036F20
// Name: public: __int64 std::basic_streambuf<char,struct std::char_traits<char>>::sputn(char const __near *,__int64)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall std::streambuf::sputn(std::streambuf *this, const char *_Ptr, __int64 _Count)
{
  return ((__int64 (__thiscall *)(std::streambuf *, const char *, _DWORD, _DWORD))this->xsputn)(
           a1: this,
           a2: _Ptr,
           a3: _Count,
           a4: HIDWORD(_Count));
}

//------------------------------------------------------------------------------
// Address: 0x10037220
// Name: public: class std::locale std::ios_base::getloc(void)const
// Source: json
//------------------------------------------------------------------------------
std::locale *__thiscall std::ios_base::getloc(std::ios_base *this, std::locale *result)
{
  std::locale::_Locimp *Ptr; // esi
  unsigned int Refs; // eax
  std::_Lockit v5; // [esp+Ch] [ebp-10h] BYREF
  int v6; // [esp+18h] [ebp-4h]

  Ptr = this->_Ploc->_Ptr;
  result->_Ptr = Ptr;
  std::_Lockit::_Lockit(this: &v5, kind: 0);
  v6 = 1;
  Refs = Ptr->_Refs;
  if ( Refs != -1 )
    Ptr->_Refs = Refs + 1;
  LOBYTE(v6) = 0;
  std::_Lockit::~_Lockit(this: &v5);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100372A0
// Name: protected: __int64 std::basic_streambuf<char,struct std::char_traits<char>>::_Gnavail(void)const
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall std::streambuf::_Gnavail(std::streambuf *this)
{
  if ( *this->_IGnext != nullptr )
    return *this->_IGcount;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10037C30
// Name: public: int std::basic_streambuf<char,struct std::char_traits<char>>::sgetc(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::streambuf::sgetc(std::streambuf *this)
{
  char **IGnext; // eax

  IGnext = this->_IGnext;
  if ( *IGnext != nullptr && *this->_IGcount > 0 )
    return (unsigned __int8)**IGnext;
  else
    return this->underflow(this);
}

//------------------------------------------------------------------------------
// Address: 0x10037C50
// Name: public: int std::basic_streambuf<char,struct std::char_traits<char>>::sbumpc(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::streambuf::sbumpc(std::streambuf *this)
{
  int *IGcount; // edx
  char **IGnext; // ecx
  char *v3; // eax

  if ( *this->_IGnext == nullptr )
    return this->uflow(this);
  IGcount = this->_IGcount;
  if ( *IGcount <= 0 )
    return this->uflow(this);
  --*IGcount;
  IGnext = this->_IGnext;
  v3 = (*IGnext)++;
  return (unsigned __int8)*v3;
}

//------------------------------------------------------------------------------
// Address: 0x100382C0
// Name: public: int std::basic_streambuf<char,struct std::char_traits<char>>::snextc(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::streambuf::snextc(std::streambuf *this)
{
  char **IGnext; // esi
  char *v3; // eax
  int result; // eax
  int *IGcount; // edx
  char **v6; // eax
  char *v7; // ecx
  char **v8; // eax

  if ( *this->_IGnext == nullptr )
    goto LABEL_6;
  if ( *this->_IGcount > 1 )
  {
    --*this->_IGcount;
    IGnext = this->_IGnext;
    v3 = *IGnext + 1;
    *IGnext = v3;
    return (unsigned __int8)*v3;
  }
  IGcount = this->_IGcount;
  if ( *IGcount > 0 )
  {
    --*IGcount;
    v6 = this->_IGnext;
    v7 = (*v6)++;
    result = (unsigned __int8)*v7;
  }
  else
  {
LABEL_6:
    result = this->uflow(this);
  }
  if ( result != -1 )
  {
    v8 = this->_IGnext;
    if ( *v8 != nullptr && *this->_IGcount > 0 )
      return (unsigned __int8)**v8;
    else
      return this->underflow(this);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100397F0
// Name: public: class std::locale std::basic_streambuf<char,struct std::char_traits<char>>::getloc(void)const
// Source: json
//------------------------------------------------------------------------------
std::locale *__thiscall std::streambuf::getloc(std::streambuf *this, std::locale *result)
{
  std::locale::_Locimp *Ptr; // esi
  unsigned int Refs; // eax
  std::_Lockit v5; // [esp+Ch] [ebp-10h] BYREF
  int v6; // [esp+18h] [ebp-4h]

  Ptr = this->_Plocale->_Ptr;
  result->_Ptr = Ptr;
  std::_Lockit::_Lockit(this: &v5, kind: 0);
  v6 = 1;
  Refs = Ptr->_Refs;
  if ( Refs != -1 )
    Ptr->_Refs = Refs + 1;
  LOBYTE(v6) = 0;
  std::_Lockit::~_Lockit(this: &v5);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039870
// Name: protected: void std::basic_streambuf<char,struct std::char_traits<char>>::_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::streambuf::_Init(std::streambuf *this)
{
  this->_IGnext = &this->_Gnext;
  this->_IPnext = &this->_Pnext;
  this->_IGfirst = &this->_Gfirst;
  this->_IGcount = &this->_Gcount;
  this->_IPfirst = &this->_Pfirst;
  this->_IPcount = &this->_Pcount;
  this->_Pfirst = nullptr;
  *this->_IPnext = nullptr;
  *this->_IPcount = 0;
  *this->_IGfirst = nullptr;
  *this->_IGnext = nullptr;
  *this->_IGcount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10039A50
// Name: public: virtual std::basic_streambuf<char,struct std::char_traits<char>>::~basic_streambuf<char,struct std::char_traits<char>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::streambuf::~streambuf<char,std::char_traits<char>>(std::streambuf *this)
{
  std::locale *Plocale; // eax
  std::locale::_Locimp *Ptr; // edi
  unsigned int Refs; // eax
  int v5; // esi
  void (__thiscall ***v6)(_DWORD, int); // esi
  std::_Lockit v7; // [esp+8h] [ebp-14h] BYREF
  std::locale *v8; // [esp+Ch] [ebp-10h]
  int v9; // [esp+18h] [ebp-4h]

  this->__vftable = (std::streambuf_vtbl *)&std::streambuf::`vftable';
  v9 = 0;
  Plocale = this->_Plocale;
  v8 = Plocale;
  if ( Plocale != nullptr )
  {
    Ptr = Plocale->_Ptr;
    if ( Plocale->_Ptr != nullptr )
    {
      std::_Lockit::_Lockit(this: &v7, kind: 0);
      LOBYTE(v9) = 1;
      Refs = Ptr->_Refs;
      if ( Refs != 0 && Refs != -1 )
        Ptr->_Refs = Refs - 1;
      v5 = -(Ptr->_Refs == 0);
      LOBYTE(v9) = 0;
      std::_Lockit::~_Lockit(this: &v7);
      v6 = (void (__thiscall ***)(_DWORD, int))((unsigned int)Ptr & v5);
      if ( v6 != nullptr )
        (**v6)(a1: v6, a2: 1);
      Plocale = v8;
    }
    operator delete(p: (void *)Plocale);
  }
  v9 = -1;
  std::_Mutex::~_Mutex(this: &this->_Mylock);
}

//------------------------------------------------------------------------------
// Address: 0x10039B00
// Name: public: virtual void std::basic_streambuf<char,struct std::char_traits<char>>::_Lock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::streambuf::_Lock(std::streambuf *this)
{
  std::_Mutex::_Lock(this: &this->_Mylock);
}

//------------------------------------------------------------------------------
// Address: 0x10039B10
// Name: public: virtual void std::basic_streambuf<char,struct std::char_traits<char>>::_Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::streambuf::_Unlock(std::streambuf *this)
{
  std::_Mutex::_Unlock(this: &this->_Mylock);
}

//------------------------------------------------------------------------------
// Address: 0x10039B20
// Name: protected: virtual int std::basic_streambuf<char,struct std::char_traits<char>>::overflow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::streambuf::overflow(std::streambuf *this, int __formal)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10039B30
// Name: protected: virtual class std::basic_streambuf<char,struct std::char_traits<char>> __near * std::basic_streambuf<char,struct std::char_traits<char>>::setbuf(char __near *,__int64)
// Source: json
//------------------------------------------------------------------------------
std::streambuf *__thiscall std::streambuf::setbuf(std::streambuf *this, char *__formal, __int64 __formala)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10039B40
// Name: protected: __int64 std::basic_streambuf<char,struct std::char_traits<char>>::_Pnavail(void)const
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall std::streambuf::_Pnavail(std::streambuf *this)
{
  if ( *this->_IPnext != nullptr )
    return *this->_IPcount;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10039B60
// Name: protected: virtual int std::basic_streambuf<char,struct std::char_traits<char>>::uflow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::streambuf::uflow(std::streambuf *this)
{
  int result; // eax
  char **IGnext; // eax
  char *v4; // ecx

  result = this->underflow(this);
  if ( result != -1 )
  {
    --*this->_IGcount;
    IGnext = this->_IGnext;
    v4 = (*IGnext)++;
    return (unsigned __int8)*v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039B90
// Name: protected: virtual __int64 std::basic_streambuf<char,struct std::char_traits<char>>::xsgetn(char __near *,__int64)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall std::streambuf::xsgetn(std::streambuf *this, char *_Ptr, __int64 _Count)
{
  __int64 v4; // rax
  __int64 v5; // kr08_8
  int v6; // eax
  __int64 _Copied; // [esp+4h] [ebp-8h]

  _Copied = 0;
  while ( _Count > 0 )
  {
    v4 = std::streambuf::_Gnavail(this);
    v5 = v4;
    if ( v4 <= 0 )
    {
      v6 = this->uflow(this);
      if ( v6 == -1 )
        return _Copied;
      ++_Copied;
      *_Ptr++ = v6;
      --_Count;
    }
    else
    {
      if ( _Count < v4 )
        v5 = _Count;
      memcpy(dst: (unsigned __int8 *)_Ptr, src: *(unsigned __int8 **)this->_IGnext, count: v5);
      _Ptr += v5;
      _Copied += v5;
      _Count -= v5;
      *this->_IGcount -= v5;
      *this->_IGnext += v5;
    }
  }
  return _Copied;
}

//------------------------------------------------------------------------------
// Address: 0x10039C70
// Name: protected: virtual __int64 std::basic_streambuf<char,struct std::char_traits<char>>::xsputn(char const __near *,__int64)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall std::streambuf::xsputn(std::streambuf *this, char *_Ptr, __int64 _Count)
{
  __int64 v4; // rax
  __int64 v5; // kr00_8
  __int64 _Copied; // [esp+4h] [ebp-8h]

  _Copied = 0;
  while ( _Count > 0 )
  {
    v4 = std::streambuf::_Pnavail(this);
    v5 = v4;
    if ( v4 <= 0 )
    {
      if ( this->overflow(this, a2: (unsigned __int8)*_Ptr) == -1 )
        return _Copied;
      ++_Ptr;
      ++_Copied;
      --_Count;
    }
    else
    {
      if ( _Count < v4 )
        v5 = _Count;
      memcpy(dst: *(unsigned __int8 **)this->_IPnext, src: (unsigned __int8 *)_Ptr, count: v5);
      _Ptr += v5;
      _Copied += v5;
      _Count -= v5;
      *this->_IPcount -= v5;
      *this->_IPnext += v5;
    }
  }
  return _Copied;
}

//------------------------------------------------------------------------------
// Address: 0x10039F70
// Name: protected: std::basic_streambuf<char,struct std::char_traits<char>>::basic_streambuf<char,struct std::char_traits<char>>(void)
// Source: json
//------------------------------------------------------------------------------
std::streambuf *__thiscall std::streambuf::streambuf(std::streambuf *this)
{
  std::locale *v2; // edi
  std::locale::_Locimp *v3; // ebx
  unsigned int Refs; // eax
  std::_Lockit v6; // [esp+Ch] [ebp-10h] BYREF
  int v7; // [esp+18h] [ebp-4h]

  this->__vftable = (std::streambuf_vtbl *)&std::streambuf::`vftable';
  std::_Mutex::_Mutex(this: &this->_Mylock);
  v7 = 0;
  v2 = (std::locale *)operator new(nSize: 4u);
  if ( v2 != nullptr )
  {
    v2->_Ptr = std::locale::_Init();
    v3 = std::locale::_Getgloballocale();
    std::_Lockit::_Lockit(this: &v6, kind: 0);
    LOBYTE(v7) = 1;
    Refs = v3->_Refs;
    if ( Refs != -1 )
      v3->_Refs = Refs + 1;
    LOBYTE(v7) = 0;
    std::_Lockit::~_Lockit(this: &v6);
  }
  else
  {
    v2 = nullptr;
  }
  this->_Plocale = v2;
  this->_IGfirst = &this->_Gfirst;
  this->_IGnext = &this->_Gnext;
  this->_IPnext = &this->_Pnext;
  this->_IPfirst = &this->_Pfirst;
  this->_IGcount = &this->_Gcount;
  this->_IPcount = &this->_Pcount;
  this->_Pfirst = nullptr;
  *this->_IPnext = nullptr;
  *this->_IPcount = 0;
  *this->_IGfirst = nullptr;
  *this->_IGnext = nullptr;
  *this->_IGcount = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003A3D0
// Name: protected: virtual class std::basic_streambuf<char,struct std::char_traits<char>> __near * std::basic_filebuf<char,struct std::char_traits<char>>::setbuf(char __near *,__int64)
// Source: json
//------------------------------------------------------------------------------
std::filebuf *__thiscall std::filebuf::setbuf(std::filebuf *this, char *_Buffer, __int64 _Count)
{
  _iobuf *Myfile; // ecx
  int v5; // eax

  Myfile = this->_Myfile;
  if ( Myfile == nullptr )
    return nullptr;
  v5 = _Buffer != nullptr || _Count != 0 ? 0 : 4;
  if ( setvbuf(str: Myfile, buffer: _Buffer, type: v5, size: _Count) != 0 )
    return nullptr;
  std::filebuf::_Init(this, _File: this->_Myfile, _Which: _Openfl);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10048FC0
// Name: public: void MDkeyvalue::Set(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDkeyvalue::Set(MDkeyvalue *this, const char *pszKey, const char *pszValue)
{
  const char *v3; // eax
  int v4; // edx
  char v5; // cl

  strcpy(this->szKey, pszKey);
  v3 = pszValue;
  v4 = this->szValue - pszValue;
  do
  {
    v5 = *v3;
    v3[v4] = *v3;
    ++v3;
  }
  while ( v5 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10049030
// Name: public: void CMapFace::SetDisp(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFace::SetDisp(CMapFace *this, unsigned __int16 handle, bool bDestroyPrevious)
{
  CEditDispMgr *v4; // eax

  if ( this->m_DispHandle == 0xFFFF )
  {
    this->m_DispHandle = handle;
  }
  else if ( bDestroyPrevious )
  {
    v4 = EditDispMgr();
    v4->Destroy(this: v4, a2: this->m_DispHandle);
    this->m_DispHandle = handle;
  }
  else
  {
    this->m_DispHandle = handle;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049090
// Name: public: bool CEditGameClass::IsSolidClass(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEditGameClass::IsSolidClass(CEditGameClass *this)
{
  GDclass *m_pClass; // eax

  m_pClass = this->m_pClass;
  return m_pClass != nullptr && m_pClass->m_bSolid;
}

//------------------------------------------------------------------------------
// Address: 0x100490B0
// Name: public: int CMapEntity::IsPlaceholder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapEntity::IsPlaceholder(CMapEntity *this)
{
  return this->flags & 1;
}

//------------------------------------------------------------------------------
// Address: 0x100490C0
// Name: public: enum TEXTUREFORMAT CGameConfig::GetTextureFormat(void)
// Source: json
//------------------------------------------------------------------------------
TEXTUREFORMAT __thiscall CGameConfig::GetTextureFormat(CGameConfig *this)
{
  return this->textureformat;
}

//------------------------------------------------------------------------------
// Address: 0x100490D0
// Name: public: int CGameConfig::GetDefaultLightmapScale(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameConfig::GetDefaultLightmapScale(CGameConfig *this)
{
  return this->m_nDefaultLightmapScale;
}

//------------------------------------------------------------------------------
// Address: 0x100490E0
// Name: StuffLine
// Source: json
//------------------------------------------------------------------------------
void __cdecl StuffLine(char *buf)
{
  char v1; // dl
  char *v2; // [esp+8h] [ebp-8h]

  v2 = szStuffed;
  do
  {
    v1 = *buf;
    *v2++ = *buf++;
  }
  while ( v1 != 0 );
  bStuffed = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10049130
// Name: void SetMapFormat(enum MAPFORMAT)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetMapFormat(MAPFORMAT mf)
{
  MapFormat = mf;
}

//------------------------------------------------------------------------------
// Address: 0x10049140
// Name: public: virtual int CMapClass::SerializeMAP(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapClass::SerializeMAP(CMapClass *this, std::fstream *file, int fIsStoring)
{
  return -3;
}

//------------------------------------------------------------------------------
// Address: 0x10049160
// Name: public: virtual CMapErrorsDlg::~CMapErrorsDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapErrorsDlg::~CMapErrorsDlg(CMapErrorsDlg *this)
{
  CListBox::~CListBox(this: &this->m_cErrors);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100491E0
// Name: public: __int64 std::ios_base::width(void)const
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall std::ios_base::width(std::ios_base *this)
{
  return this->_Wide;
}

//------------------------------------------------------------------------------
// Address: 0x100491F0
// Name: public: __int64 std::ios_base::width(__int64)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall std::ios_base::width(std::ios_base *this, __int64 _Newwidth)
{
  __int64 result; // rax

  result = this->_Wide;
  this->_Wide = _Newwidth;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10049210
// Name: public: int CTextureSystem::FilesGetCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureSystem::FilesGetCount(CTextureSystem *this)
{
  return CUtlVector<tagGF,CUtlMemory<tagGF,int>>::Count(this: &this->m_GraphicsFiles);
}

//------------------------------------------------------------------------------
// Address: 0x10049360
// Name: public: int std::basic_streambuf<char,struct std::char_traits<char>>::sputc(char)
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::streambuf::sputc(std::streambuf *this, unsigned __int8 _Ch)
{
  int *IPcount; // edx
  char **IPnext; // ecx
  unsigned __int8 *v4; // eax

  if ( *this->_IPnext == nullptr )
    return this->overflow(this, a2: _Ch);
  IPcount = this->_IPcount;
  if ( *IPcount <= 0 )
    return this->overflow(this, a2: _Ch);
  --*IPcount;
  IPnext = this->_IPnext;
  v4 = (unsigned __int8 *)(*IPnext)++;
  *v4 = _Ch;
  return _Ch;
}

//------------------------------------------------------------------------------
// Address: 0x100493A0
// Name: public: void CTextureSystem::FilesGetInfo(struct tagGF __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureSystem::FilesGetInfo(CTextureSystem *this, tagGF *pFileInfo, int nIndex)
{
  if ( pFileInfo != nullptr )
    *pFileInfo = *CUtlVector<tagGF,CUtlMemory<tagGF,int>>::operator[](this: &this->m_GraphicsFiles, i: nIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10049D30
// Name: SaveSolidChildrenOf
// Source: json
//------------------------------------------------------------------------------
int __cdecl SaveSolidChildrenOf(CMapGroup *pObject, std::fstream *file, BoundBox *pIntersecting)
{
  CUtlReferenceList<CMapClass> *p_m_References; // [esp+8h] [ebp-50h]
  CMapClass *m_pObject; // [esp+Ch] [ebp-4Ch]
  CUtlReference<CMapClass> *v6; // [esp+20h] [ebp-38h]
  CUtlReference<CMapClass> v7; // [esp+2Ch] [ebp-2Ch] BYREF
  int iRvl; // [esp+38h] [ebp-20h]
  CMapClass *pChild; // [esp+3Ch] [ebp-1Ch]
  int pos; // [esp+40h] [ebp-18h]
  const CUtlReferenceVector<CMapClass> *pChildren; // [esp+44h] [ebp-14h]
  CMapWorld *pWorld; // [esp+48h] [ebp-10h]
  int v13; // [esp+54h] [ebp-4h]

  pWorld = CMapClass::GetWorldObject(pStart: pObject);
  if ( bSaveVisiblesOnly != 0 && pObject != (CMapGroup *)pWorld && !CMapGroup::IsVisibleLogical(this: pObject) )
    return -3;
  if ( pIntersecting != nullptr
    && !CMapClass::IsIntersectingCordon(this: pObject, vecMins: &pIntersecting->bmins, vecMaxs: &pIntersecting->bmaxs) )
  {
    return -3;
  }
  pChildren = CMapClass::GetChildren(this: pObject);
  for ( pos = 0; pos < pChildren->m_Size; ++pos )
  {
    iRvl = -1;
    v6 = &pChildren->m_Memory.m_pMemory[pos >> (*((int *)&pChildren->m_Memory + 2) >> 27)][pos
                                                                                         & ((32
                                                                                           * *((_DWORD *)&pChildren->m_Memory
                                                                                             + 2)) >> 5)];
    if ( v6->m_pObject != nullptr )
    {
      m_pObject = v6->m_pObject;
      v7.m_pObject = m_pObject;
      if ( m_pObject != nullptr )
      {
        p_m_References = &m_pObject->m_References;
        v7.m_pNext = m_pObject->m_References.m_pHead;
        if ( m_pObject->m_References.m_pHead != nullptr )
          p_m_References->m_pHead->m_pPrev = &v7;
        v7.m_pPrev = nullptr;
        p_m_References->m_pHead = &v7;
      }
    }
    pChild = v7.m_pObject;
    v13 = -1;
    if ( v7.m_pObject != nullptr )
    {
      IntrusiveList::RemoveFromDList<CUtlReference<CMapClass>>(head: &v7.m_pObject->m_References.m_pHead, which: &v7);
      v7.m_pObject = nullptr;
    }
    if ( pIntersecting == nullptr
      || CMapClass::IsIntersectingCordon(this: pChild, vecMins: &pIntersecting->bmins, vecMaxs: &pIntersecting->bmaxs) )
    {
      if ( pChild->IsMapClass(this: pChild, a2: CMapSolid::__Type) != 0 )
      {
        if ( bSaveVisiblesOnly == 0 || CMapGroup::IsVisibleLogical(this: (CMapGroup *)pChild) )
          iRvl = pChild->SerializeMAP(this: pChild, a2: file, a3: 1);
      }
      else if ( pChild->IsMapClass(this: pChild, a2: CMapGroup::__Type) != 0 )
      {
        iRvl = SaveSolidChildrenOf(pObject: pChild, file, pIntersecting);
      }
      if ( iRvl != -1 && iRvl != -3 )
        return iRvl;
    }
  }
  return -3;
}

//------------------------------------------------------------------------------
// Address: 0x10049FD0
// Name: SaveEntityChildrenOf
// Source: json
//------------------------------------------------------------------------------
int __cdecl SaveEntityChildrenOf(CMapGroup *pObject, std::fstream *file, BoundBox *pIntersecting)
{
  CUtlReferenceList<CMapClass> *p_m_References; // [esp+8h] [ebp-50h]
  CMapClass *m_pObject; // [esp+Ch] [ebp-4Ch]
  CUtlReference<CMapClass> *v6; // [esp+20h] [ebp-38h]
  CUtlReference<CMapClass> v7; // [esp+2Ch] [ebp-2Ch] BYREF
  int iRvl; // [esp+38h] [ebp-20h]
  CMapClass *pChild; // [esp+3Ch] [ebp-1Ch]
  int pos; // [esp+40h] [ebp-18h]
  const CUtlReferenceVector<CMapClass> *pChildren; // [esp+44h] [ebp-14h]
  CMapWorld *pWorld; // [esp+48h] [ebp-10h]
  int v13; // [esp+54h] [ebp-4h]

  pWorld = CMapClass::GetWorldObject(pStart: pObject);
  if ( bSaveVisiblesOnly != 0 && pObject != (CMapGroup *)pWorld && !CMapGroup::IsVisibleLogical(this: pObject) )
    return -3;
  if ( pIntersecting != nullptr
    && !CMapClass::IsIntersectingCordon(this: pObject, vecMins: &pIntersecting->bmins, vecMaxs: &pIntersecting->bmaxs) )
  {
    return -3;
  }
  pChildren = CMapClass::GetChildren(this: pObject);
  for ( pos = 0; pos < pChildren->m_Size; ++pos )
  {
    iRvl = -1;
    v6 = &pChildren->m_Memory.m_pMemory[pos >> (*((int *)&pChildren->m_Memory + 2) >> 27)][pos
                                                                                         & ((32
                                                                                           * *((_DWORD *)&pChildren->m_Memory
                                                                                             + 2)) >> 5)];
    if ( v6->m_pObject != nullptr )
    {
      m_pObject = v6->m_pObject;
      v7.m_pObject = m_pObject;
      if ( m_pObject != nullptr )
      {
        p_m_References = &m_pObject->m_References;
        v7.m_pNext = m_pObject->m_References.m_pHead;
        if ( m_pObject->m_References.m_pHead != nullptr )
          p_m_References->m_pHead->m_pPrev = &v7;
        v7.m_pPrev = nullptr;
        p_m_References->m_pHead = &v7;
      }
    }
    pChild = v7.m_pObject;
    v13 = -1;
    if ( v7.m_pObject != nullptr )
    {
      IntrusiveList::RemoveFromDList<CUtlReference<CMapClass>>(head: &v7.m_pObject->m_References.m_pHead, which: &v7);
      v7.m_pObject = nullptr;
    }
    if ( pIntersecting == nullptr
      || CMapClass::IsIntersectingCordon(this: pChild, vecMins: &pIntersecting->bmins, vecMaxs: &pIntersecting->bmaxs) )
    {
      if ( pChild->IsMapClass(this: pChild, a2: CMapEntity::__Type) != 0 )
      {
        if ( bSaveVisiblesOnly == 0 || CMapGroup::IsVisibleLogical(this: (CMapGroup *)pChild) )
          iRvl = pChild->SerializeMAP(this: pChild, a2: file, a3: 1);
      }
      else if ( pChild->IsMapClass(this: pChild, a2: CMapGroup::__Type) != 0 )
      {
        iRvl = SaveEntityChildrenOf(pObject: pChild, file, pIntersecting);
      }
      if ( iRvl != -1 && iRvl != -3 )
        return iRvl;
    }
  }
  return -3;
}

//------------------------------------------------------------------------------
// Address: 0x1004A310
// Name: GetLine
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetLine(std::fstream *file, char *buf)
{
  char v2; // dl
  char v3; // [esp+3h] [ebp-459h]
  char *v4; // [esp+8h] [ebp-454h]
  char *v5; // [esp+Ch] [ebp-450h]
  char *v6; // [esp+18h] [ebp-444h]
  char *v7; // [esp+1Ch] [ebp-440h]
  char szBuf[1024]; // [esp+5Ch] [ebp-400h] BYREF

  if ( bStuffed != 0 )
  {
    if ( buf != nullptr )
    {
      v7 = szStuffed;
      v6 = buf;
      do
      {
        v2 = *v7;
        *v6++ = *v7++;
      }
      while ( v2 != 0 );
    }
    bStuffed = 0;
  }
  else
  {
    while ( 1 )
    {
      std::ws(_Istr: file);
      std::istream::getline(this: file, _Str: szBuf, _Count: 512);
      if ( std::ios_base::eof(this: (std::ios_base *)&file->gap0[*(_DWORD *)(*(_DWORD *)file->gap0 + 4)]) )
        break;
      if ( strncmp(first: szBuf, last: "//", count: 2u) != 0 )
      {
        std::ws(_Istr: file);
        if ( buf != nullptr )
        {
          v5 = szBuf;
          v4 = buf;
          do
          {
            v3 = *v5;
            *v4++ = *v5++;
          }
          while ( v3 != 0 );
        }
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A490
// Name: ReadSolids
// Source: json
//------------------------------------------------------------------------------
int __cdecl ReadSolids(CMapClass *pObject, std::fstream *file)
{
  CMapSolid *v3; // [esp+8h] [ebp-B4h]
  CMapSolid *v4; // [esp+1Ch] [ebp-A0h]
  int iRvl; // [esp+28h] [ebp-94h]
  int nSolids; // [esp+2Ch] [ebp-90h]
  char szBuf[128]; // [esp+30h] [ebp-8Ch] BYREF
  int v8; // [esp+B8h] [ebp-4h]

  for ( nSolids = 0; ; ++nSolids )
  {
    GetLine(file, buf: szBuf);
    if ( szBuf[0] != 123 )
    {
      StuffLine(buf: szBuf);
      return nSolids;
    }
    v4 = (CMapSolid *)operator new(nSize: 0x240u);
    v8 = 0;
    v3 = v4 != nullptr ? CMapSolid::CMapSolid(this: v4, Parent0: nullptr) : nullptr;
    v8 = -1;
    iRvl = v3->SerializeMAP(this: v3, a2: file, a3: 0);
    if ( iRvl != -2 )
      break;
    if ( v3 != nullptr )
      ((void (__thiscall *)(CMapSolid *, int))v3->~CMapClass)(a1: v3, a2: 1);
    ++nInvalidSolids;
LABEL_16:
    ;
  }
  if ( iRvl != -1 )
  {
    pObject->AddChild(this: pObject, a2: v3);
    goto LABEL_16;
  }
  if ( v3 != nullptr )
    ((void (__thiscall *)(CMapSolid *, int))v3->~CMapClass)(a1: v3, a2: 1);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1004A670
// Name: PeekChar
// Source: json
//------------------------------------------------------------------------------
int __cdecl PeekChar(std::fstream *file)
{
  char szBuf[1024]; // [esp+0h] [ebp-400h] BYREF

  if ( bStuffed != 0 )
    return szStuffed[0];
  szBuf[0] = 0;
  GetLine(file, buf: szBuf);
  if ( szBuf[0] == 0 )
    return -1;
  StuffLine(buf: szBuf);
  return szBuf[0];
}

//------------------------------------------------------------------------------
// Address: 0x1004A6D0
// Name: public: int CMapFace::SerializeMAP(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __thiscall CMapFace::SerializeMAP(CMapFace *this, std::fstream *file, int fIsStoring)
{
  float *v3; // eax
  float *v4; // eax
  float *v5; // eax
  float *v6; // eax
  std::ostream *v7; // eax
  float *v9; // eax
  CEditDispMgr *v10; // eax
  float *v11; // eax
  float *v12; // eax
  double v13; // [esp+8h] [ebp-49Ch]
  double v14; // [esp+10h] [ebp-494h]
  double v15; // [esp+18h] [ebp-48Ch]
  double v16; // [esp+20h] [ebp-484h]
  double v17; // [esp+28h] [ebp-47Ch]
  double v18; // [esp+30h] [ebp-474h]
  double v19; // [esp+38h] [ebp-46Ch]
  double v20; // [esp+40h] [ebp-464h]
  const char *v21; // [esp+48h] [ebp-45Ch]
  float *v22; // [esp+48h] [ebp-45Ch]
  float *v23; // [esp+48h] [ebp-45Ch]
  double v24; // [esp+4Ch] [ebp-458h]
  float *v25; // [esp+4Ch] [ebp-458h]
  float *v26; // [esp+4Ch] [ebp-458h]
  float *v27; // [esp+50h] [ebp-454h]
  float *v28; // [esp+50h] [ebp-454h]
  double v29; // [esp+54h] [ebp-450h]
  float *v30; // [esp+54h] [ebp-450h]
  float *v31; // [esp+54h] [ebp-450h]
  float *v32; // [esp+58h] [ebp-44Ch]
  float *v33; // [esp+58h] [ebp-44Ch]
  double v34; // [esp+5Ch] [ebp-448h]
  float *v35; // [esp+5Ch] [ebp-448h]
  float *v36; // [esp+5Ch] [ebp-448h]
  float *v37; // [esp+60h] [ebp-444h]
  float *v38; // [esp+60h] [ebp-444h]
  float *v39; // [esp+60h] [ebp-444h]
  double v40; // [esp+64h] [ebp-440h]
  float *v41; // [esp+64h] [ebp-440h]
  float *v42; // [esp+64h] [ebp-440h]
  float *v43; // [esp+64h] [ebp-440h]
  float *v44; // [esp+68h] [ebp-43Ch]
  double v45; // [esp+6Ch] [ebp-438h]
  float *v46; // [esp+6Ch] [ebp-438h]
  float *v47; // [esp+6Ch] [ebp-438h]
  float *v48; // [esp+6Ch] [ebp-438h]
  float *v49; // [esp+70h] [ebp-434h]
  float *v50; // [esp+70h] [ebp-434h]
  float *v51; // [esp+70h] [ebp-434h]
  double v52; // [esp+74h] [ebp-430h]
  float *v53; // [esp+74h] [ebp-430h]
  float *v54; // [esp+74h] [ebp-430h]
  float *v55; // [esp+74h] [ebp-430h]
  float *v56; // [esp+78h] [ebp-42Ch]
  float *v57; // [esp+78h] [ebp-42Ch]
  float *v58; // [esp+78h] [ebp-42Ch]
  double v59; // [esp+7Ch] [ebp-428h]
  float *v60; // [esp+7Ch] [ebp-428h]
  float *v61; // [esp+7Ch] [ebp-428h]
  float *v62; // [esp+7Ch] [ebp-428h]
  float *v63; // [esp+80h] [ebp-424h]
  float *v64; // [esp+80h] [ebp-424h]
  double v65; // [esp+84h] [ebp-420h]
  float *v66; // [esp+84h] [ebp-420h]
  float *v67; // [esp+84h] [ebp-420h]
  float *v68; // [esp+84h] [ebp-420h]
  float *v69; // [esp+88h] [ebp-41Ch]
  float *v70; // [esp+88h] [ebp-41Ch]
  float *v71; // [esp+88h] [ebp-41Ch]
  double rotate; // [esp+8Ch] [ebp-418h]
  double v73; // [esp+94h] [ebp-410h]
  double v74; // [esp+9Ch] [ebp-408h]
  CEditDispMgr *v75; // [esp+C0h] [ebp-3E4h]
  std::ostream *v76; // [esp+C4h] [ebp-3E0h]
  float v77; // [esp+C8h] [ebp-3DCh]
  float v78; // [esp+CCh] [ebp-3D8h]
  float v79; // [esp+D0h] [ebp-3D4h]
  int pFace_4; // [esp+E8h] [ebp-3BCh]
  unsigned __int16 v82; // [esp+ECh] [ebp-3B8h]
  CMapDisp *v83[2]; // [esp+F0h] [ebp-3B4h] BYREF
  char pszNewTex[8]; // [esp+F8h] [ebp-3ACh] BYREF
  int v85; // [esp+180h] [ebp-324h] BYREF
  unsigned int v86; // [esp+184h] [ebp-320h] BYREF
  CMapFace *thisa; // [esp+188h] [ebp-31Ch]
  int i; // [esp+18Ch] [ebp-318h]
  signed int handle; // [esp+190h] [ebp-314h] OVERLAPPED
  _BYTE pDisp[273]; // [esp+194h] [ebp-310h] OVERLAPPED BYREF

  if ( fIsStoring != 0 )
  {
    pDisp[260] = 0;
    qmemcpy(pDisp, &this->texture, 0x104u);
    strlwr(string: pDisp);
    if ( MapFormat == mfQuake2 )
    {
      *(_DWORD *)&pDisp[268] = _V_strstr(s1: pDisp, search: ".");
      if ( *(_DWORD *)&pDisp[268] != 0 )
        **(_BYTE **)&pDisp[268] = 0;
      *(_DWORD *)&pDisp[268] = _V_strstr(s1: pDisp, search: "textures\\");
      if ( *(_DWORD *)&pDisp[268] != 0 )
        *(_DWORD *)&pDisp[268] += 9;
      else
        *(_DWORD *)&pDisp[268] = pDisp;
    }
    else
    {
      *(_DWORD *)&pDisp[268] = pDisp;
    }
    strupr(string: pDisp);
    for ( handle = strlen(*(const char **)&pDisp[268]) - 1; handle >= 0; --handle )
    {
      if ( *(_BYTE *)(handle + *(_DWORD *)&pDisp[268]) == 92 )
        *(_BYTE *)(handle + *(_DWORD *)&pDisp[268]) = 47;
    }
    for ( i = 0; i < 3; ++i )
    {
      v3 = Vector::operator[](this: &this->plane.planepts[i], i: 0);
      v79 = rint(f: *v3);
      *Vector::operator[](this: &this->plane.planepts[i], i: 0) = v79;
      v4 = Vector::operator[](this: &this->plane.planepts[i], i: 1);
      v78 = rint(f: *v4);
      *Vector::operator[](this: &this->plane.planepts[i], i: 1) = v78;
      v5 = Vector::operator[](this: &this->plane.planepts[i], i: 2);
      v77 = rint(f: *v5);
      *Vector::operator[](this: &this->plane.planepts[i], i: 2) = v77;
    }
    if ( CMapFace::CheckFace(this, pInfo: nullptr) == 0 )
      CMapFace::Fix(this);
    v74 = this->texture.scale[1];
    v73 = this->texture.scale[0];
    rotate = this->texture.rotate;
    v65 = *Vector::operator[](this: (Vector *)&this->texture.VAxis, i: 3);
    v59 = *Vector::operator[](this: (Vector *)&this->texture.VAxis, i: 2);
    v52 = *Vector::operator[](this: (Vector *)&this->texture.VAxis, i: 1);
    v45 = *Vector::operator[](this: (Vector *)&this->texture.VAxis, i: 0);
    v40 = *Vector::operator[](this: (Vector *)&this->texture.UAxis, i: 3);
    v34 = *Vector::operator[](this: (Vector *)&this->texture.UAxis, i: 2);
    v29 = *Vector::operator[](this: (Vector *)&this->texture.UAxis, i: 1);
    v24 = *Vector::operator[](this: (Vector *)&this->texture.UAxis, i: 0);
    v21 = *(const char **)&pDisp[268];
    v20 = *Vector::operator[](this: &this->plane.planepts[2], i: 2);
    v19 = *Vector::operator[](this: &this->plane.planepts[2], i: 1);
    v18 = *Vector::operator[](this: &this->plane.planepts[2], i: 0);
    v17 = *Vector::operator[](this: &this->plane.planepts[1], i: 2);
    v16 = *Vector::operator[](this: &this->plane.planepts[1], i: 1);
    v15 = *Vector::operator[](this: &this->plane.planepts[1], i: 0);
    v14 = *Vector::operator[](this: this->plane.planepts, i: 2);
    v13 = *Vector::operator[](this: this->plane.planepts, i: 1);
    v6 = Vector::operator[](this: this->plane.planepts, i: 0);
    sprintf(
      string: &pDisp[272],
      format: "( %.0f %.0f %.0f ) ( %.0f %.0f %.0f ) ( %.0f %.0f %.0f ) %s [ %g %g %g %g ] [ %g %g %g %g ] %g %g %g ",
      *v6,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v24,
      v29,
      v34,
      v40,
      v45,
      v52,
      v59,
      v65,
      rotate,
      v73,
      v74);
    if ( file != nullptr )
      v76 = (std::ostream *)file->gap10;
    else
      v76 = nullptr;
    v7 = std::operator<<<std::char_traits<char>>(_Ostr: v76, _Val: &pDisp[272]);
    std::operator<<<std::char_traits<char>>(_Ostr: v7, _Val: "\r\n");
    return -3;
  }
  else
  {
    GetLine(file, buf: &pDisp[272]);
    if ( pDisp[272] == 40 )
    {
      if ( uMapVersion < 0x154 )
      {
        if ( uMapVersion < 0xDC )
        {
          v71 = Vector::operator[](this: (Vector *)&this->texture.VAxis, i: 3);
          v68 = Vector::operator[](this: (Vector *)&this->texture.UAxis, i: 3);
          v62 = Vector::operator[](this: &this->plane.planepts[2], i: 2);
          v58 = Vector::operator[](this: &this->plane.planepts[2], i: 1);
          v55 = Vector::operator[](this: &this->plane.planepts[2], i: 0);
          v51 = Vector::operator[](this: &this->plane.planepts[1], i: 2);
          v48 = Vector::operator[](this: &this->plane.planepts[1], i: 1);
          v44 = Vector::operator[](this: &this->plane.planepts[1], i: 0);
          v43 = Vector::operator[](this: this->plane.planepts, i: 2);
          v39 = Vector::operator[](this: this->plane.planepts, i: 1);
          v12 = Vector::operator[](this: this->plane.planepts, i: 0);
          thisa = (CMapFace *)sscanf(
                                string: &pDisp[272],
                                format: "( %f %f %f ) ( %f %f %f ) ( %f %f %f ) %s %f %f %f %f %f %u %u %u",
                                v12,
                                v39,
                                v43,
                                v44,
                                v48,
                                v51,
                                v55,
                                v58,
                                v62,
                                &pszNewTex[4],
                                v68,
                                v71,
                                &this->texture.rotate,
                                this->texture.scale,
                                &this->texture.scale[1],
                                &v86,
                                pszNewTex,
                                &v83[1]);
          if ( (int)thisa >= 15 )
          {
            if ( thisa == (CMapFace *)18 )
            {
              this->texture.q2contents = v86;
              this->texture.q2surface = *(_DWORD *)pszNewTex;
            }
          }
          else
          {
            bErrors = 1;
          }
        }
        else
        {
          v70 = Vector::operator[](this: (Vector *)&this->texture.VAxis, i: 3);
          v67 = Vector::operator[](this: (Vector *)&this->texture.VAxis, i: 2);
          v64 = Vector::operator[](this: (Vector *)&this->texture.VAxis, i: 1);
          v61 = Vector::operator[](this: (Vector *)&this->texture.VAxis, i: 0);
          v57 = Vector::operator[](this: (Vector *)&this->texture.UAxis, i: 3);
          v54 = Vector::operator[](this: (Vector *)&this->texture.UAxis, i: 2);
          v50 = Vector::operator[](this: (Vector *)&this->texture.UAxis, i: 1);
          v47 = Vector::operator[](this: (Vector *)&this->texture.UAxis, i: 0);
          v42 = Vector::operator[](this: &this->plane.planepts[2], i: 2);
          v38 = Vector::operator[](this: &this->plane.planepts[2], i: 1);
          v36 = Vector::operator[](this: &this->plane.planepts[2], i: 0);
          v33 = Vector::operator[](this: &this->plane.planepts[1], i: 2);
          v31 = Vector::operator[](this: &this->plane.planepts[1], i: 1);
          v28 = Vector::operator[](this: &this->plane.planepts[1], i: 0);
          v26 = Vector::operator[](this: this->plane.planepts, i: 2);
          v23 = Vector::operator[](this: this->plane.planepts, i: 1);
          v11 = Vector::operator[](this: this->plane.planepts, i: 0);
          thisa = (CMapFace *)sscanf(
                                string: &pDisp[272],
                                format: "( %f %f %f ) ( %f %f %f ) ( %f %f %f ) %s [ %f %f %f %f ] [ %f %f %f %f ] %f %f %f %u %u %u",
                                v11,
                                v23,
                                v26,
                                v28,
                                v31,
                                v33,
                                v36,
                                v38,
                                v42,
                                &pszNewTex[4],
                                v47,
                                v50,
                                v54,
                                v57,
                                v61,
                                v64,
                                v67,
                                v70,
                                &this->texture.rotate,
                                this->texture.scale,
                                &this->texture.scale[1],
                                &v86,
                                pszNewTex,
                                &v83[1]);
          if ( (int)thisa >= 21 )
          {
            if ( thisa == (CMapFace *)24 )
            {
              this->texture.q2contents = v86;
              this->texture.q2surface = *(_DWORD *)pszNewTex;
            }
          }
          else
          {
            bErrors = 1;
          }
        }
      }
      else
      {
        v69 = Vector::operator[](this: (Vector *)&this->texture.VAxis, i: 3);
        v66 = Vector::operator[](this: (Vector *)&this->texture.VAxis, i: 2);
        v63 = Vector::operator[](this: (Vector *)&this->texture.VAxis, i: 1);
        v60 = Vector::operator[](this: (Vector *)&this->texture.VAxis, i: 0);
        v56 = Vector::operator[](this: (Vector *)&this->texture.UAxis, i: 3);
        v53 = Vector::operator[](this: (Vector *)&this->texture.UAxis, i: 2);
        v49 = Vector::operator[](this: (Vector *)&this->texture.UAxis, i: 1);
        v46 = Vector::operator[](this: (Vector *)&this->texture.UAxis, i: 0);
        v41 = Vector::operator[](this: &this->plane.planepts[2], i: 2);
        v37 = Vector::operator[](this: &this->plane.planepts[2], i: 1);
        v35 = Vector::operator[](this: &this->plane.planepts[2], i: 0);
        v32 = Vector::operator[](this: &this->plane.planepts[1], i: 2);
        v30 = Vector::operator[](this: &this->plane.planepts[1], i: 1);
        v27 = Vector::operator[](this: &this->plane.planepts[1], i: 0);
        v25 = Vector::operator[](this: this->plane.planepts, i: 2);
        v22 = Vector::operator[](this: this->plane.planepts, i: 1);
        v9 = Vector::operator[](this: this->plane.planepts, i: 0);
        thisa = (CMapFace *)sscanf(
                              string: &pDisp[272],
                              format: "( %f %f %f ) ( %f %f %f ) ( %f %f %f ) %s [ %f %f %f %f ] [ %f %f %f %f ] %f %f %f %u %u %u",
                              v9,
                              v22,
                              v25,
                              v27,
                              v30,
                              v32,
                              v35,
                              v37,
                              v41,
                              &pszNewTex[4],
                              v46,
                              v49,
                              v53,
                              v56,
                              v60,
                              v63,
                              v66,
                              v69,
                              &this->texture.rotate,
                              this->texture.scale,
                              &this->texture.scale[1],
                              &v86,
                              pszNewTex,
                              &v85);
        if ( (int)thisa >= 21 )
        {
          if ( thisa == (CMapFace *)24 )
          {
            this->texture.q2contents = v86;
            this->texture.q2surface = *(_DWORD *)pszNewTex;
            this->texture.nLightmapScale = v85;
            if ( this->texture.nLightmapScale == 0 )
              this->texture.nLightmapScale = CGameConfig::GetDefaultLightmapScale(this: g_pGameConfig);
          }
        }
        else
        {
          bErrors = 1;
        }
        if ( uMapVersion <= 0x15E && std::istream::peek(this: file) != 40 && std::istream::peek(this: file) != 125 )
        {
          v75 = EditDispMgr();
          v82 = v75->Create(this: v75);
          CMapFace::SetDisp(this, handle: v82, bDestroyPrevious: true);
          v10 = EditDispMgr();
          v83[0] = v10->GetDisp(this: v10, a2: v82);
          CMapDisp::SerializedLoadMAP(this: v83[0], file, pFace: this, version: uMapVersion);
        }
      }
      if ( CGameConfig::GetTextureFormat(this: g_pGameConfig) != tfVMT )
      {
        for ( pFace_4 = &pszNewTex[strlen(&pszNewTex[4]) + 4] - &pszNewTex[5]; pFace_4 >= 0; --pFace_4 )
        {
          if ( pszNewTex[pFace_4 + 4] == 47 )
            pszNewTex[pFace_4 + 4] = 92;
        }
      }
      CMapFace::SetTexture(this, pszNewTex: &pszNewTex[4], bRescaleTextureCoordinates: false);
      if ( std::ios_base::fail(this: (std::ios_base *)&file->gap0[*(_DWORD *)(*(_DWORD *)file->gap0 + 4)]) )
        return -1;
      else
        return -3;
    }
    else
    {
      StuffLine(buf: &pDisp[272]);
      return -4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004B430
// Name: public: int MDkeyvalue::SerializeMAP(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall MDkeyvalue::SerializeMAP(MDkeyvalue *this, std::fstream *file, int fIsStoring)
{
  const char *ActionTarget; // eax
  std::ostream *v4; // eax
  int v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  _BYTE *v9; // eax
  const char *v10; // [esp-4h] [ebp-430h]
  char v11; // [esp+3h] [ebp-429h]
  char *szValue; // [esp+8h] [ebp-424h]
  char *v13; // [esp+Ch] [ebp-420h]
  char v14; // [esp+13h] [ebp-419h]
  MDkeyvalue *v15; // [esp+18h] [ebp-414h]
  char *v16; // [esp+1Ch] [ebp-410h]
  std::ostream *_Ostr; // [esp+20h] [ebp-40Ch]
  char szBuf[1024]; // [esp+2Ch] [ebp-400h] BYREF

  if ( fIsStoring != 0 )
  {
    v10 = (const char *)MDkeyvalue::Value((CDmElementFramework *)this);
    ActionTarget = (const char *)CBaseToolSystem::GetActionTarget((CBaseToolSystem *)this);
    sprintf(string: szBuf, format: "\"%s\" \"%s\"", ActionTarget, v10);
    if ( file != nullptr )
      _Ostr = (std::ostream *)file->gap10;
    else
      _Ostr = nullptr;
    v4 = std::operator<<<std::char_traits<char>>(_Ostr, _Val: szBuf);
    std::operator<<<std::char_traits<char>>(_Ostr: v4, _Val: "\r\n");
  }
  else
  {
    GetLine(file, buf: szBuf);
    if ( szBuf[0] != 34 )
    {
      StuffLine(buf: szBuf);
      return -4;
    }
    strchr(_Str: szBuf, _Ch: 0x22u);
    strchr(_Str: (char *)(v6 + 1), _Ch: 0x22u);
    if ( v7 == nullptr )
      return -2;
    *v7 = 0;
    v16 = &szBuf[1];
    v15 = this;
    do
    {
      v14 = *v16;
      v15->szKey[0] = *v16++;
      v15 = (MDkeyvalue *)((char *)v15 + 1);
    }
    while ( v14 != 0 );
    strchr(_Str: v7 + 1, _Ch: 0x22u);
    if ( v8 == 0 )
      return -2;
    v13 = (char *)(v8 + 1);
    szValue = this->szValue;
    do
    {
      v11 = *v13;
      *szValue++ = *v13++;
    }
    while ( v11 != 0 );
    strchr(_Str: this->szValue, _Ch: 0x22u);
    if ( v9 == nullptr )
      return -2;
    *v9 = 0;
  }
  return std::ios_base::fail(this: (std::ios_base *)&file->gap0[*(_DWORD *)(*(_DWORD *)file->gap0 + 4)]) ? -1 : -3;
}

//------------------------------------------------------------------------------
// Address: 0x1004B6A0
// Name: public: virtual int CMapSolid::SerializeMAP(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapSolid::SerializeMAP(CMapSolid *this, std::fstream *file, int fIsStoring)
{
  std::ostream *v3; // eax
  CMapFace *v4; // eax
  std::ostream *v6; // eax
  CMapFace *v7; // eax
  CMapFace *v8; // eax
  CMapFace *v9; // eax
  std::ostream *v10; // [esp+0h] [ebp-18h]
  std::ostream *_Ostr; // [esp+4h] [ebp-14h]
  int iIndex; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int nFaces; // [esp+14h] [ebp-4h]

  CMapClass::SerializeMAP(this, file, fIsStoring);
  if ( fIsStoring != 0 )
  {
    if ( file != nullptr )
      _Ostr = (std::ostream *)file->gap10;
    else
      _Ostr = nullptr;
    v3 = std::operator<<<std::char_traits<char>>(_Ostr, _Val: "{");
    std::operator<<<std::char_traits<char>>(_Ostr: v3, _Val: "\r\n");
    nFaces = this->Faces.nCount;
    for ( i = 0; i < nFaces; ++i )
    {
      if ( BlockArray<CMapFace,6,86>::operator[](this: &this->Faces, iIndex: i)->Points != nullptr )
      {
        v4 = BlockArray<CMapFace,6,86>::operator[](this: &this->Faces, iIndex: i);
        if ( CMapFace::SerializeMAP(this: v4, file, fIsStoring) == -2 )
          return -2;
      }
    }
    if ( file != nullptr )
      v10 = (std::ostream *)file->gap10;
    else
      v10 = nullptr;
    v6 = std::operator<<<std::char_traits<char>>(_Ostr: v10, _Val: "}");
    std::operator<<<std::char_traits<char>>(_Ostr: v6, _Val: "\r\n");
  }
  else
  {
    BlockArray<CMapFace,6,86>::SetCount(this: &this->Faces, nObjects: 0);
    for ( iIndex = 0; ; ++iIndex )
    {
      v7 = BlockArray<CMapFace,6,86>::operator[](this: &this->Faces, iIndex);
      if ( CMapFace::SerializeMAP(this: v7, file, fIsStoring: 0) == -4 )
        break;
      v8 = BlockArray<CMapFace,6,86>::operator[](this: &this->Faces, iIndex);
      CMapFace::CalcPlane(this: v8);
    }
    GetLine(file, buf: nullptr);
    if ( std::ios_base::fail(this: (std::ios_base *)&file->gap0[*(_DWORD *)(*(_DWORD *)file->gap0 + 4)]) )
      return -1;
    if ( CMapSolid::CreateFromPlanes(this, dwFlags: 0) == 0 )
    {
      bErrors = 1;
      return -2;
    }
    if ( uMapVersion < 0xDC )
      CMapSolid::InitializeTextureAxes(this, eAlignment: TEXTURE_ALIGN_QUAKE, dwFlags: 3u);
    this->CalcBounds(this, a2: 0);
    v9 = BlockArray<CMapFace,6,86>::operator[](this: &this->Faces, iIndex: 0);
    this->m_eSolidType = CMapSolid::HL1SolidTypeFromTextureName(this, pszTexture: v9->texture.texture);
  }
  return std::ios_base::fail(this: (std::ios_base *)&file->gap0[*(_DWORD *)(*(_DWORD *)file->gap0 + 4)]) ? -1 : -3;
}

//------------------------------------------------------------------------------
// Address: 0x1004B8D0
// Name: public: int CEditGameClass::SerializeMAP(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEditGameClass::SerializeMAP(CEditGameClass *this, std::fstream *file, int fIsStoring)
{
  int v3; // eax
  char *Name; // eax
  int v7; // [esp+40h] [ebp-4E0h]
  int v8; // [esp+44h] [ebp-4DCh]
  int iIndex; // [esp+4Ch] [ebp-4D4h] BYREF
  const char *p; // [esp+50h] [ebp-4D0h]
  GDinputvariable *pVar; // [esp+54h] [ebp-4CCh]
  int i; // [esp+58h] [ebp-4C8h]
  int nVariableCount; // [esp+5Ch] [ebp-4C4h]
  MDkeyvalue *KeyValue; // [esp+60h] [ebp-4C0h]
  int z; // [esp+64h] [ebp-4BCh]
  GDclass *pGameDataClass; // [esp+68h] [ebp-4B8h]
  MDkeyvalue tmpkv; // [esp+6Ch] [ebp-4B4h] BYREF
  MDkeyvalue newkv; // [esp+2BCh] [ebp-264h] BYREF
  int iRvl; // [esp+510h] [ebp-10h]
  int v20; // [esp+51Ch] [ebp-4h]

  if ( fIsStoring != 0 )
  {
    MDkeyvalue::MDkeyvalue(this: &tmpkv);
    v20 = 1;
    if ( CEditGameClass::GetKeyValue(this, pszKey: "classname", piIndex: nullptr) == nullptr )
    {
      MDkeyvalue::Set(this: &tmpkv, pszKey: "classname", pszValue: this->m_szClass);
      MDkeyvalue::SerializeMAP(this: &tmpkv, file, fIsStoring);
    }
    pGameDataClass = nullptr;
    if ( pGD != nullptr )
      pGameDataClass = GameData::ClassForName(this: pGD, pszName: this->m_szClass, piIndex: nullptr);
    for ( z = WCKVBase_Dict::GetFirst(this: &this->m_KeyValues);
          z != WCKVBase_Dict::GetInvalidIndex();
          z = WCKVBase_Dict::GetNext(this: &this->m_KeyValues, i: z) )
    {
      KeyValue = &this->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)z].m_Data.elem;
      iRvl = MDkeyvalue::SerializeMAP(this: KeyValue, file, fIsStoring);
      if ( iRvl != -3 )
      {
        v8 = iRvl;
        v20 = -1;
        CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&tmpkv);
        return v8;
      }
    }
    if ( pGameDataClass != nullptr )
    {
      nVariableCount = (int)GDclass::GetVariableCount(this: (vgui::BuildGroup *)pGameDataClass);
      for ( i = 0; i < nVariableCount; ++i )
      {
        pVar = GDclass::GetVariableAt(this: pGameDataClass, iIndex: i);
        if ( pVar != nullptr )
        {
          Name = GDinputvariable::GetName(this: pVar);
          p = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: Name, piIndex: &iIndex);
          if ( p == nullptr )
          {
            GDinputvariable::ResetDefaults(this: pVar);
            GDinputvariable::ToKeyValue(this: pVar, pkv: &tmpkv);
            if ( tmpkv.szKey[0] != 0 && tmpkv.szValue[0] != 0 && _V_stricmp(s1: tmpkv.szValue, s2: "0") != 0 )
            {
              iRvl = MDkeyvalue::SerializeMAP(this: &tmpkv, file, fIsStoring);
              if ( iRvl != -3 )
              {
                v7 = iRvl;
                v20 = -1;
                CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&tmpkv);
                return v7;
              }
            }
          }
        }
      }
    }
    v20 = -1;
    CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&tmpkv);
  }
  else if ( PeekChar(file) == 34 )
  {
    MDkeyvalue::MDkeyvalue(this: &newkv);
    v20 = 0;
    while ( MDkeyvalue::SerializeMAP(this: &newkv, file, fIsStoring: 0) == -3 )
    {
      if ( strcmp(newkv.szKey, "classname") == 0 )
      {
        WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &this->m_KeyValues, pszKey: newkv.szKey, pszValue: newkv.szValue);
      }
      else if ( strcmp(newkv.szKey, "angle") == 0 )
      {
        v3 = atoi(nptr: newkv.szValue);
        CEditGameClass::ImportAngle(this, nAngle: v3);
      }
      else if ( strcmp(newkv.szKey, "wad") != 0 )
      {
        WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &this->m_KeyValues, pszKey: newkv.szKey, pszValue: newkv.szValue);
      }
    }
    v20 = -1;
    CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&newkv);
  }
  return std::ios_base::fail(this: (std::ios_base *)&file->gap0[*(_DWORD *)(*(_DWORD *)file->gap0 + 4)]) ? -1 : -3;
}

//------------------------------------------------------------------------------
// Address: 0x1004BE40
// Name: public: virtual int CMapWorld::SerializeMAP(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int,class BoundBox __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapWorld::SerializeMAP(CMapWorld *this, std::fstream *file, int fIsStoring, BoundBox *pIntersecting)
{
  std::ostream *v4; // eax
  TEXTUREFORMAT TextureFormat; // eax
  std::ostream *v6; // eax
  char *v7; // eax
  char *v8; // eax
  CMapDoc *ActiveMapDoc; // eax
  int *v11; // eax
  const char *v12; // eax
  char *v13; // eax
  const char *v14; // [esp+Ch] [ebp-804h]
  CMapEntity *v16; // [esp+18h] [ebp-7F8h]
  CProgressDlg *v17; // [esp+1Ch] [ebp-7F4h]
  std::ostream *v18; // [esp+20h] [ebp-7F0h]
  char v19; // [esp+27h] [ebp-7E9h]
  char *v20; // [esp+28h] [ebp-7E8h]
  char *v21; // [esp+3Ch] [ebp-7D4h]
  char v22; // [esp+43h] [ebp-7CDh]
  char *v23; // [esp+44h] [ebp-7CCh]
  char v24; // [esp+4Bh] [ebp-7C5h]
  char *v25; // [esp+50h] [ebp-7C0h]
  tagGF *p_gf; // [esp+54h] [ebp-7BCh]
  std::ostream *_Ostr; // [esp+58h] [ebp-7B8h]
  CMapEntity *v29; // [esp+B8h] [ebp-758h]
  CProgressDlg *v30; // [esp+C0h] [ebp-750h]
  void *searchReplaceFP; // [esp+C8h] [ebp-748h]
  char translationFilename[264]; // [esp+CCh] [ebp-744h] BYREF
  CMapErrorsDlg dlg; // [esp+1D4h] [ebp-63Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v34; // [esp+2DCh] [ebp-534h] BYREF
  CMapEntity *pEntity; // [esp+2E0h] [ebp-530h]
  const char *pszMapVersion; // [esp+2E4h] [ebp-52Ch]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > caption; // [esp+2E8h] [ebp-528h] BYREF
  char szBuf[132]; // [esp+2ECh] [ebp-524h] BYREF
  CMapPath *pPath; // [esp+370h] [ebp-4A0h]
  int pos; // [esp+374h] [ebp-49Ch]
  char *pszSlash; // [esp+378h] [ebp-498h]
  char szFile[264]; // [esp+37Ch] [ebp-494h] BYREF
  tagGF gf; // [esp+484h] [ebp-38Ch] BYREF
  int i; // [esp+5A0h] [ebp-270h]
  int nGraphicsFiles; // [esp+5A4h] [ebp-26Ch]
  int bFirst; // [esp+5A8h] [ebp-268h]
  MDkeyvalue tmpkv; // [esp+5ACh] [ebp-264h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+7FCh] [ebp-14h] BYREF
  int iRvl; // [esp+800h] [ebp-10h]
  int v50; // [esp+80Ch] [ebp-4h]

  bStuffed = 0;
  bErrors = 0;
  nInvalidSolids = 0;
  if ( fIsStoring != 0 )
  {
    if ( file != nullptr )
      _Ostr = (std::ostream *)file->gap10;
    else
      _Ostr = nullptr;
    v4 = std::operator<<<std::char_traits<char>>(_Ostr, _Val: "{");
    std::operator<<<std::char_traits<char>>(_Ostr: v4, _Val: "\r\n");
    CEditGameClass::SerializeMAP(this: &this->CEditGameClass, file, fIsStoring);
    if ( MapFormat != mfQuake2 )
    {
      MDkeyvalue::MDkeyvalue(this: &tmpkv);
      v50 = 0;
      strcpy(tmpkv.szKey, "mapversion");
      strcpy(tmpkv.szValue, "360");
      MDkeyvalue::SerializeMAP(this: &tmpkv, file, fIsStoring);
      strcpy(tmpkv.szKey, "wad");
      tmpkv.szValue[0] = 0;
      bFirst = 1;
      nGraphicsFiles = CTextureSystem::FilesGetCount(this: &g_Textures);
      for ( i = 0; i < nGraphicsFiles; ++i )
      {
        CTextureSystem::FilesGetInfo(this: &g_Textures, pFileInfo: &gf, nIndex: i);
        if ( gf.format != tfWAL )
        {
          TextureFormat = CGameConfig::GetTextureFormat(this: g_pGameConfig);
          if ( gf.format == TextureFormat )
          {
            p_gf = &gf;
            v25 = szFile;
            do
            {
              v24 = p_gf->filename[0];
              *v25 = p_gf->filename[0];
              p_gf = (tagGF *)((char *)p_gf + 1);
              ++v25;
            }
            while ( v24 != 0 );
            pszSlash = szFile;
            if ( szFile[1] == 58 )
              pszSlash += 2;
            if ( bFirst == 0 )
            {
              v23 = &tmpkv.szKey[79];
              do
                v22 = *++v23;
              while ( v22 != 0 );
              strcpy(v23, ";");
            }
            v21 = &pszSlash[strlen(pszSlash) + 1];
            v20 = &tmpkv.szKey[79];
            do
              v19 = *++v20;
            while ( v19 != 0 );
            qmemcpy(v20, pszSlash, v21 - pszSlash);
            bFirst = 0;
          }
        }
      }
      if ( tmpkv.szValue[0] != 0 )
        MDkeyvalue::SerializeMAP(this: &tmpkv, file, fIsStoring);
      v50 = -1;
      CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&tmpkv);
    }
    if ( SaveSolidChildrenOf(pObject: (CMapGroup *)this, file, pIntersecting) != -1 )
    {
      v18 = file != nullptr ? (std::ostream *)file->gap10 : nullptr;
      v6 = std::operator<<<std::char_traits<char>>(_Ostr: v18, _Val: "}");
      std::operator<<<std::char_traits<char>>(_Ostr: v6, _Val: "\r\n");
      if ( SaveEntityChildrenOf(pObject: (CMapGroup *)this, file, pIntersecting) != -1 )
      {
        for ( pos = 0; pos < this->m_Paths.m_Size; ++pos )
        {
          pPath = this->m_Paths.m_Memory.m_pMemory[pos];
          CMapPath::SerializeMAP(this: pPath, file, fIsStoring: 1, pIntersecting);
        }
LABEL_63:
        if ( pProgDlg != nullptr )
        {
          pProgDlg->DestroyWindow(this: pProgDlg);
          if ( pProgDlg != nullptr )
            ((void (__thiscall *)(CProgressDlg *, int))pProgDlg->dtr_CObject)(a1: pProgDlg, a2: 1);
          pProgDlg = nullptr;
        }
        if ( bErrors != 0 && fIsStoring != 0 )
          return -1;
        else
          return 0;
      }
    }
  }
  else
  {
    v30 = (CProgressDlg *)CObject::operator new(nSize: 0x120u);
    v50 = 1;
    if ( v30 != nullptr )
      v17 = CProgressDlg::CProgressDlg(this: v30, nCaptionID: 0);
    else
      v17 = nullptr;
    v50 = -1;
    pProgDlg = v17;
    CProgressDlg::Create(this: v17, pParent: nullptr);
    CProgressDlg::SetStep(this: pProgDlg, nStep: 1);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &caption);
    v50 = 2;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(this: &caption, nID: 0xA029u);
    v7 = ATL::CSimpleStringT<char,0>::operator char const *(this: &caption);
    CWnd::SetWindowTextA(this: pProgDlg, lpszString: v7);
    BoundBox::ResetBounds(this: &this->m_Render2DBox);
    GetLine(file, buf: nullptr);
    CEditGameClass::SerializeMAP(this: &this->CEditGameClass, file, fIsStoring: 0);
    pszMapVersion = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                      this: &this->m_KeyValues,
                      pszKey: "mapversion",
                      piIndex: nullptr);
    if ( pszMapVersion != nullptr )
      uMapVersion = atoi(nptr: pszMapVersion);
    else
      uMapVersion = 0;
    if ( ReadSolids(pObject: this, file) != -1 )
    {
      GetLine(file, buf: nullptr);
      while ( 1 )
      {
        GetLine(file, buf: szBuf);
        if ( szBuf[0] != 123 )
          break;
        if ( PeekChar(file) == -1 )
          goto LABEL_53;
        v29 = (CMapEntity *)operator new(nSize: 0x184u);
        LOBYTE(v50) = 3;
        if ( v29 != nullptr )
          v16 = CMapEntity::CMapEntity(this: v29);
        else
          v16 = nullptr;
        LOBYTE(v50) = 2;
        pEntity = v16;
        iRvl = v16->SerializeMAP(this: v16, a2: file, a3: 0);
        this->AddChild(this, a2: v16);
        if ( iRvl == -2 )
        {
          bErrors = 1;
        }
        else if ( iRvl == -1 )
        {
          goto LABEL_41;
        }
      }
      StuffLine(buf: szBuf);
LABEL_53:
      if ( bErrors != 0 )
      {
        if ( nInvalidSolids != 0 )
        {
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &v34);
          LOBYTE(v50) = 4;
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
            this: &v34,
            pszFormat: "For your information, %d solids were not loaded\ndue to errors in the file.",
            nInvalidSolids);
          v8 = ATL::CSimpleStringT<char,0>::operator char const *(this: &v34);
          AfxMessageBox(lpszText: v8, nType: 0, nIDHelp: 0);
          LOBYTE(v50) = 2;
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &v34);
        }
        else if ( AfxMessageBox(
                    lpszText: "There was a problem loading the MAP file. Do you\nwant to view the error report?",
                    nType: 4u,
                    nIDHelp: 0) == 6 )
        {
          CMapErrorsDlg::CMapErrorsDlg(this: &dlg, pParent: nullptr);
          LOBYTE(v50) = 5;
          CDialog::DoModal(this: &dlg);
          LOBYTE(v50) = 6;
          CListBox::~CListBox(this: &dlg.m_cErrors);
          LOBYTE(v50) = 2;
          CDialog::~CDialog(this: &dlg);
        }
      }
      CMapWorld::PostloadWorld(this);
      if ( CGameConfig::GetTextureFormat(this: g_pGameConfig) == tfVMT )
      {
        V_snprintf(pDest: translationFilename, maxLen: 260, pFormat: "materials/trans.txt");
        if ( CMapDoc::GetActiveMapDoc() != nullptr )
        {
          searchReplaceFP = g_pFileSystem->Open(this: g_pFileSystem, a2: translationFilename, a3: "r", a4: 0);
          if ( searchReplaceFP != nullptr )
          {
            ActiveMapDoc = CMapDoc::GetActiveMapDoc();
            CMapDoc::BatchReplaceTextures(this: ActiveMapDoc, fp: searchReplaceFP);
            g_pFileSystem->Close(this: g_pFileSystem, a2: searchReplaceFP);
          }
        }
      }
      v50 = -1;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &caption);
      goto LABEL_63;
    }
LABEL_41:
    v50 = -1;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &caption);
  }
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &str);
  v50 = 8;
  if ( fIsStoring != 0 )
    v14 = "saving";
  else
    v14 = "loading";
  v11 = _errno();
  v12 = strerror(errnum: *v11);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
    this: &str,
    pszFormat: "The OS reported an error %s the file: %s",
    v14,
    v12);
  v13 = ATL::CSimpleStringT<char,0>::operator char const *(this: &str);
  AfxMessageBox(lpszText: v13, nType: 0, nIDHelp: 0);
  if ( pProgDlg != nullptr )
  {
    pProgDlg->DestroyWindow(this: pProgDlg);
    if ( pProgDlg != nullptr )
      ((void (__thiscall *)(CProgressDlg *, int))pProgDlg->dtr_CObject)(a1: pProgDlg, a2: 1);
    pProgDlg = nullptr;
  }
  v50 = -1;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &str);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1004C830
// Name: public: virtual int CMapEntity::SerializeMAP(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapEntity::SerializeMAP(CMapEntity *this, __int64 file)
{
  std::ostream *v3; // eax
  float *v4; // eax
  std::ostream *v5; // eax
  double v6; // [esp+8h] [ebp-288h]
  double v7; // [esp+10h] [ebp-280h]
  std::ostream *_Ostr; // [esp+18h] [ebp-278h]
  std::ostream *_Ostr_4; // [esp+1Ch] [ebp-274h]
  CBaseToolSystem v11; // [esp+28h] [ebp-268h] BYREF
  int v12; // [esp+28Ch] [ebp-4h]

  CMapClass::SerializeMAP(this, (std::fstream *)file, fIsStoring: SHIDWORD(file));
  if ( HIDWORD(file) != 0 )
  {
    if ( CMapEntity::IsPlaceholder(this) == 0 && this->m_Children.m_Size == 0 )
      return -3;
    if ( (_DWORD)file != 0 )
      _Ostr_4 = (std::ostream *)(file + 16);
    else
      _Ostr_4 = nullptr;
    v3 = std::operator<<<std::char_traits<char>>(_Ostr: _Ostr_4, _Val: "{");
    std::operator<<<std::char_traits<char>>(_Ostr: v3, _Val: "\r\n");
    CEditGameClass::SerializeMAP(this: &this->CEditGameClass, (std::fstream *)file, fIsStoring: SHIDWORD(file));
    if ( CMapEntity::IsPlaceholder(this) != 0
      && (!CEditGameClass::IsClass(this: &this->CEditGameClass, pszClass: nullptr)
       || !CEditGameClass::IsSolidClass(this: &this->CEditGameClass)) )
    {
      MDkeyvalue::MDkeyvalue(this: (MDkeyvalue *)&v11.m_OnDelete_register);
      v12 = 0;
      strcpy((char *)&v11.m_OnDelete_register, "origin");
      CBaseToolSystem::GetActionTarget(this: &v11);
      this->GetOrigin(this, a2: (Vector *)&v11);
      v7 = *Vector::operator[](this: (Vector *)&v11, i: 2);
      v6 = *Vector::operator[](this: (Vector *)&v11, i: 1);
      v4 = Vector::operator[](this: (Vector *)&v11, i: 0);
      sprintf(string: (char *)&v11._border, format: "%.0f %.0f %.0f", *v4, v6, v7);
      MDkeyvalue::SerializeMAP(
        this: (MDkeyvalue *)&v11.m_OnDelete_register,
        (std::fstream *)file,
        fIsStoring: SHIDWORD(file));
      v12 = -1;
      CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&v11.m_OnDelete_register);
    }
    if ( CMapEntity::IsPlaceholder(this) == 0 )
      SaveSolidChildrenOf(pObject: (CMapGroup *)this, (std::fstream *)file, pIntersecting: nullptr);
    if ( (_DWORD)file != 0 )
      _Ostr = (std::ostream *)(file + 16);
    else
      _Ostr = nullptr;
    v5 = std::operator<<<std::char_traits<char>>(_Ostr, _Val: "}");
    std::operator<<<std::char_traits<char>>(_Ostr: v5, _Val: "\r\n");
  }
  else
  {
    CEditGameClass::SerializeMAP(this: &this->CEditGameClass, (std::fstream *)file, fIsStoring: 0);
    if ( ReadSolids(pObject: this, (std::fstream *)file) == 0 )
      this->flags |= 1u;
    GetLine((std::fstream *)file, buf: nullptr);
  }
  return std::ios_base::fail(this: (std::ios_base *)(*(_DWORD *)(*(_DWORD *)file + 4) + file)) ? -1 : -3;
}

//------------------------------------------------------------------------------
// Address: 0x101AAF30
// Name: public: class std::basic_streambuf<char,struct std::char_traits<char>> __near * std::basic_ios<char,struct std::char_traits<char>>::rdbuf(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::ios::rdbuf(CDataModel *this)
{
  return this->m_FormatUpdaters.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x101EBD30
// Name: public: char const __near * MDkeyvalue::Value(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *__thiscall MDkeyvalue::Value(
        CDmElementFramework *this)
{
  return &this->m_dependencyGraph.m_operators;
}

//------------------------------------------------------------------------------
// Address: 0x102A7D90
// Name: public: static unsigned int std::char_traits<char>::length(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl std::char_traits<char>::length(const char *str)
{
  return strlen(str);
}

//------------------------------------------------------------------------------
// Address: 0x102EF680
// Name: protected: virtual int std::basic_streambuf<char,struct std::char_traits<char>>::underflow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::streambuf::underflow(vgui::TreeView *this)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1043DED0
// Name: _strstr
// Source: json
//------------------------------------------------------------------------------
void __cdecl strstr(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 v2; // dl
  unsigned __int8 v4; // dh
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // esi
  char v7; // al
  unsigned __int8 v8; // ah
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al

  v2 = *str2;
  if ( *str2 != 0 )
  {
    v4 = str2[1];
    if ( v4 == 0 )
      JUMPOUT(0x1043BE06);
findnext:
    v5 = str2;
    v6 = str1 + 1;
    if ( *str1 == v2 )
      goto first_char_found;
    if ( *str1 != 0 )
    {
      while ( 2 )
      {
        v7 = *v6++;
        while ( v7 == v2 )
        {
first_char_found:
          v7 = *v6++;
          if ( v7 == v4 )
          {
            str1 = v6 - 1;
            while ( 1 )
            {
              v8 = v5[2];
              if ( v8 == 0 )
                break;
              v9 = *v6;
              v6 += 2;
              if ( v9 != v8 )
                goto findnext;
              v10 = v5[3];
              if ( v10 == 0 )
                break;
              v5 += 2;
              if ( v10 != *(v6 - 1) )
                goto findnext;
            }
            return;
          }
        }
        if ( v7 != 0 )
          continue;
        break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10460958
// Name: private: void std::ios_base::_Callfns(enum std::ios_base::event)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::ios_base::_Callfns(std::ios_base *this, std::ios_base::event _Ev)
{
  std::ios_base::_Fnarray *i; // esi

  for ( i = this->_Calls; i != nullptr; i = i->_Next )
    i->_Pfn(a1: _Ev, a2: this, a3: i->_Index);
}

//------------------------------------------------------------------------------
// Address: 0x1046097F
// Name: private: void std::ios_base::_Tidy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::ios_base::_Tidy(std::ios_base *this)
{
  std::ios_base::_Iosarray *Arr; // eax
  std::ios_base::_Iosarray *Next; // edi
  std::ios_base::_Fnarray *Calls; // eax
  std::ios_base::_Fnarray *v5; // edi

  std::ios_base::_Callfns(this, _Ev: erase_event);
  Arr = this->_Arr;
  if ( Arr != nullptr )
  {
    do
    {
      Next = Arr->_Next;
      operator delete(p: Arr);
      Arr = Next;
    }
    while ( Next != nullptr );
  }
  Calls = this->_Calls;
  this->_Arr = nullptr;
  if ( Calls != nullptr )
  {
    do
    {
      v5 = Calls->_Next;
      operator delete(p: Calls);
      Calls = v5;
    }
    while ( v5 != nullptr );
  }
  this->_Calls = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104609C3
// Name: private: static void std::ios_base::_Ios_base_dtor(class std::ios_base __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::ios_base::_Ios_base_dtor(std::ios_base *_This)
{
  char *v1; // eax
  std::locale *Ploc; // esi

  if ( _This->_Stdstr == 0 || (v1 = &stdopens[_This->_Stdstr], --*v1, *v1 <= 0) )
  {
    std::ios_base::_Tidy(this: _This);
    Ploc = _This->_Ploc;
    if ( Ploc != nullptr )
    {
      std::locale::~locale(this: Ploc);
      operator delete(p: (void *)Ploc);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1043DFBB
// Name: _strncmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strncmp(const char *first, const char *last, unsigned int count)
{
  const char *v4; // ecx
  const char *v5; // eax
  char v6; // dl
  char v7; // dl
  char v8; // dl
  char v9; // dl
  int v10; // eax
  int v11; // ecx
  unsigned int i; // esi
  unsigned int n; // [esp+4h] [ebp-4h]

  n = 0;
  if ( count == 0 )
    return 0;
  if ( count <= 4 )
  {
    v4 = last;
    v5 = first;
LABEL_20:
    for ( i = n; ; ++i )
    {
      if ( i >= count )
        return 0;
      if ( *v5 == 0 || *v5 != *v4 )
        break;
      ++v5;
      ++v4;
    }
    v10 = *(unsigned __int8 *)v5;
    v11 = *(unsigned __int8 *)v4;
  }
  else
  {
    v4 = last;
    v5 = first;
    while ( 1 )
    {
      v6 = *v5;
      v5 += 4;
      v4 += 4;
      if ( v6 == 0 || v6 != *(v4 - 4) )
        break;
      v7 = *(v5 - 3);
      if ( v7 == 0 || v7 != *(v4 - 3) )
      {
        v10 = *((unsigned __int8 *)v5 - 3);
        v11 = *((unsigned __int8 *)v4 - 3);
        return v10 - v11;
      }
      v8 = *(v5 - 2);
      if ( v8 == 0 || v8 != *(v4 - 2) )
      {
        v10 = *((unsigned __int8 *)v5 - 2);
        v11 = *((unsigned __int8 *)v4 - 2);
        return v10 - v11;
      }
      v9 = *(v5 - 1);
      if ( v9 == 0 || v9 != *(v4 - 1) )
      {
        v10 = *((unsigned __int8 *)v5 - 1);
        v11 = *((unsigned __int8 *)v4 - 1);
        return v10 - v11;
      }
      n += 4;
      if ( n >= count - 4 )
        goto LABEL_20;
    }
    v10 = *((unsigned __int8 *)v5 - 4);
    v11 = *((unsigned __int8 *)v4 - 4);
  }
  return v10 - v11;
}

//------------------------------------------------------------------------------
// Address: 0x1043E080
// Name: _acos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl acos(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp-8h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x7F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x10453768);
  }
  JUMPOUT(0x1043E10F);
}

//------------------------------------------------------------------------------
// Address: 0x1043E0C0
// Name: __CIacos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIacos(int a1, int a2)
{
  int v3; // eax
  bool v4; // zf
  char v5; // [esp-8h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIacos;
  v3 = _mm_getcsr() & 0x7F80;
  v4 = v3 == 8064;
  if ( v3 == 8064 )
    v4 = (v5 & 0x7F) == 127;
  if ( v4 )
    _CIacos_pentium4();
  else
__CIacos:
    _CIacos_default(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x1043E0FB
// Name: __CIacos_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10460A01
// Name: public: virtual std::length_error::~length_error(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall std::length_error::~length_error(std::out_of_range *this)
{
  std::exception::~exception((std::__non_rtti_object *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10460A06
// Name: public: std::logic_error::logic_error(class std::logic_error const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::logic_error *__thiscall std::logic_error::logic_error(std::logic_error *this, const std::logic_error *__that)
{
  std::exception::exception(this, _That: __that);
  this->__vftable = (std::logic_error_vtbl *)&std::logic_error::`vftable';
  return this;
}
