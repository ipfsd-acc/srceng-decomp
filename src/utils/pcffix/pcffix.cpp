// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/pcffix/pcffix.cpp
// Functions: 245
// ============================================================

#include "utils\pcffix\pcffix.h"

//------------------------------------------------------------------------------
// Address: 0x00401400
// Name: public: bool Vector2D::operator!=(class Vector2D const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Vector2D::operator!=(Vector2D *this, const Vector2D *src)
{
  return this->x != src->x || this->y != src->y;
}

//------------------------------------------------------------------------------
// Address: 0x00401430
// Name: public: bool Vector::operator!=(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Vector::operator!=(Vector *this, const Vector *src)
{
  return this->x != src->x || this->y != src->y || this->z != src->z;
}

//------------------------------------------------------------------------------
// Address: 0x004014B0
// Name: public: virtual bool CTier2DmSteamApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTier2DmSteamApp::PreInit(CTier2DmSteamApp *this)
{
  void *(__cdecl *Factory)(const char *, int *); // eax
  bool result; // al
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+0h] [ebp-4h] BYREF

  pFactoryList = CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  Factory = CAppSystemGroup::GetFactory();
  result = ConnectDataModel(factory: Factory);
  if ( result )
    return InitDataModel() == INIT_OK;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401500
// Name: public: Color::Color(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall Color::Color(Color *this)
{
  *this = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401510
// Name: public: bool Vector4D::operator!=(class Vector4D const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Vector4D::operator!=(Vector4D *this, const Vector4D *src)
{
  return this->x != src->x || this->y != src->y || this->z != src->z || this->w != src->w;
}

//------------------------------------------------------------------------------
// Address: 0x00401560
// Name: SpewStdout
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl SpewStdout(SpewType_t spewType, const char *pMsg)
{
  _iobuf *v3; // eax

  if ( pMsg == nullptr )
    return true;
  printf(format: pMsg);
  v3 = __iob_func();
  fflush(stream: v3 + 1);
  return spewType != SPEW_ASSERT;
}

//------------------------------------------------------------------------------
// Address: 0x00401590
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  return AppMain(argc, (char **)argv, pAppSystemGroup: &_s_SteamApplicationObject);
}

//------------------------------------------------------------------------------
// Address: 0x004015B0
// Name: public: virtual bool CPCFFixApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPCFFixApp::Create(CPCFFixApp *this)
{
  AppSystemInfo_t appSystems[2]; // [esp+0h] [ebp-14h] BYREF
  const char *v4; // [esp+10h] [ebp-4h]

  _SpewOutputFunc(a1: SpewStdout);
  appSystems[1].m_pInterfaceName = defaultValue;
  v4 = defaultValue;
  appSystems[0].m_pInterfaceName = "p4lib.dll";
  appSystems[1].m_pModuleName = "VP4001";
  CAppSystemGroup::AddSystems(this, pSystemList: (AppSystemInfo_t *)&appSystems[0].m_pInterfaceName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401600
// Name: public: virtual bool CPCFFixApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPCFFixApp::PreInit(CPCFFixApp *this)
{
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: false,
    bAllowSSE: false,
    bAllowSSE2: false,
    bAllowMMX: false);
  if ( CTier2DmSteamApp::PreInit(this) )
  {
    if ( g_pFullFileSystem != nullptr && g_pDataModel != nullptr )
      return CSteamAppSystemGroup::SetupSearchPaths(
               this,
               pStartingDir: nullptr,
               bOnlyUseStartingDir: false,
               bIsTool: true);
    _Error(a1: "// ERROR: pcffix is missing a required interface!\n");
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00401670
// Name: public: void CPCFFixApp::PrintHelp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPCFFixApp::PrintHelp(CPCFFixApp *this)
{
  int v1; // ecx
  int v2; // ecx
  int v3; // ecx

  _Msg(a1: this, a2: "Usage: pcffix -i <in .pcf file> [-nop4]\n");
  _Msg(a1: v1, a2: "\t-i\t: Source .PCF file to fix up (eliminate copied particle system definitions.)\n");
  _Msg(a1: v2, a2: "\t-nop4\t: Disables auto perforce checkout/add.\n");
  _Msg(a1: v3, a2: "\t-vproject\t: Specifies path to a gameinfo.txt file (which mod to build for).\n");
}

//------------------------------------------------------------------------------
// Address: 0x004016A0
// Name: public: int CDmaElementArrayBase<class CDmElement,class CDmaDataExternal<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        CDmaElementArrayBase<CDmElement,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *this,
        DmElementHandle_t pValue)
{
  if ( pValue != 0 )
    pValue = CDmElement::GetHandle(this: (CDmElement *)pValue);
  else
    pValue = DMELEMENT_HANDLE_INVALID;
  return CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
           this,
           src: &pValue);
}

//------------------------------------------------------------------------------
// Address: 0x004016E0
// Name: public: void CDmrElementArray<class CDmElement>::Init(class CDmElement __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmrElementArray<CDmElement>::Init(
        CDmrElementArray<CDmElement> *this,
        CDmElement *pElement,
        const char *pAttributeName,
        bool bAddAttribute)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi

  if ( pElement == nullptr || pAttributeName == nullptr || *pAttributeName == 0 )
    goto LABEL_10;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v6 = Attribute;
  if ( !bAddAttribute )
  {
LABEL_7:
    if ( v6 == nullptr )
      goto LABEL_10;
    goto LABEL_8;
  }
  if ( Attribute == nullptr )
  {
    v6 = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_FIRST_ARRAY_TYPE);
    CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType.m_Id);
    goto LABEL_7;
  }
LABEL_8:
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    this->m_pAttribute = v6;
    this->m_pStorage = (DmElementArray_t *)v6->m_pData;
    return;
  }
LABEL_10:
  this->m_pAttribute = nullptr;
  this->m_pStorage = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00401760
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401790
// Name: public: class Color const __near & CDmAttribute::GetValue<class Color>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Color> *__thiscall CDmAttribute::GetValue<Color>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Color>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Color>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Color>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Color>'::`2'::defaultVal.m_Storage._color[0] = 0;
    `CDmAttribute::GetValue<Color>'::`2'::defaultVal.m_Storage._color[1] = 0;
    `CDmAttribute::GetValue<Color>'::`2'::defaultVal.m_Storage._color[2] = 0;
    `CDmAttribute::GetValue<Color>'::`2'::defaultVal.m_Storage._color[3] = -1;
  }
  if ( (this->m_nFlags & 0x1F) == 8 )
    return (CDmaVar<Color> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<Color>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004017E0
// Name: public: enum DmElementHandle_t const __near & CDmAttribute::GetValue<enum DmElementHandle_t>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<enum DmElementHandle_t> *__thiscall CDmAttribute::GetValue<enum DmElementHandle_t>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType = -1;
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  if ( (this->m_nFlags & 0x1F) == 1 )
    return (CDmaVar<enum DmElementHandle_t> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00401890
// Name: public: float const __near & CDmAttribute::GetValue<float>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<float> *__thiscall CDmAttribute::GetValue<float>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
    `CDmAttribute::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
  }
  if ( (this->m_nFlags & 0x1F) == 3 )
    return (CDmaVar<float> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<float>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004018D0
// Name: public: bool const __near & CDmAttribute::GetValue<bool>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<bool> *__thiscall CDmAttribute::GetValue<bool>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<bool>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
  }
  if ( (this->m_nFlags & 0x1F) == 4 )
    return (CDmaVar<bool> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<bool>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00401910
// Name: public: int const __near & CDmAttribute::GetValue<int>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<int> *__thiscall CDmAttribute::GetValue<int>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (this->m_nFlags & 0x1F) == 2 )
    return (CDmaVar<int> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00401950
// Name: public: class Vector2D const __near & CDmAttribute::GetValue<class Vector2D>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector2D> *__thiscall CDmAttribute::GetValue<Vector2D>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Vector2D>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Vector2D>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_Storage.y = 0.0;
  }
  if ( (this->m_nFlags & 0x1F) == 9 )
    return (CDmaVar<Vector2D> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00401990
// Name: public: class Vector const __near & CDmAttribute::GetValue<class Vector>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmAttribute::GetValue<Vector>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Vector>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  if ( (this->m_nFlags & 0x1F) == 0xA )
    return (CDmaVar<Vector> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<Vector>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004019E0
// Name: public: class Vector4D const __near & CDmAttribute::GetValue<class Vector4D>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector4D> *__thiscall CDmAttribute::GetValue<Vector4D>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Vector4D>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Vector4D>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_Storage.z = 0.0;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_Storage.w = 0.0;
  }
  if ( (this->m_nFlags & 0x1F) == 0xB )
    return (CDmaVar<Vector4D> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00401A30
// Name: public: class CDmElement __near * CDmAttribute::GetValueElement<class CDmElement>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmAttribute::GetValueElement<CDmElement>(CDmAttribute *this)
{
  CDmaVar<enum DmElementHandle_t> *v1; // eax
  CDmElement *v2; // esi

  if ( (this->m_nFlags & 0x1F) != 1 )
    return nullptr;
  v1 = CDmAttribute::GetValue<enum DmElementHandle_t>(this);
  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: v1->m_Storage.m_Handle);
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmElement::m_classType.m_Id) )
    return v2;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00401A80
// Name: public: enum DmElementHandle_t const __near & CDmElement::GetValue<enum DmElementHandle_t>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<enum DmElementHandle_t> *__thiscall CDmElement::GetValue<enum DmElementHandle_t>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType = -1;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    return &`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00401AD0
// Name: public: CP4AutoEditFile::CP4AutoEditFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CP4AutoEditFile *__thiscall CP4AutoEditFile::CP4AutoEditFile(CP4AutoEditFile *this, const char *szFilename)
{
  CP4File *v3; // eax

  v3 = CP4Factory::AccessFile(this: g_p4factory, szFilename);
  this->m_spImpl.m_p = v3;
  v3->Edit(this: v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401B00
// Name: public: CP4AutoEditFile::~CP4AutoEditFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4AutoEditFile::~CP4AutoEditFile(CP4AutoEditFile *this)
{
  CP4File *m_p; // ecx

  m_p = this->m_spImpl.m_p;
  this->m_spImpl.m_p = nullptr;
  if ( m_p != nullptr )
    ((void (__thiscall *)(CP4File *, int))m_p->dtr_CP4File)(a1: m_p, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00401B20
// Name: public: CDmrElementArray<class CDmElement>::CDmrElementArray<class CDmElement>(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
CDmrElementArrayConst<CDmElement> *__thiscall CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
        CDmrElementArrayConst<CDmElement> *this,
        CDmAttribute *pAttribute)
{
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>((CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)this);
  if ( pAttribute != nullptr && (pAttribute->m_nFlags & 0x1F) == 0xF )
  {
    this->m_pAttribute = pAttribute;
    this->m_pStorage = (DmElementArray_t *)pAttribute->m_pData;
    return this;
  }
  else
  {
    this->m_pAttribute = nullptr;
    this->m_pStorage = nullptr;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401B60
// Name: public: CDmrElementArray<class CDmElement>::CDmrElementArray<class CDmElement>(class CDmElement __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmrElementArray<CDmElement> *__thiscall CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
        CDmrElementArray<CDmElement> *this,
        CDmElement *pElement,
        const char *pAttributeName,
        bool bAddAttribute)
{
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>((CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)this);
  CDmrElementArray<CDmElement>::Init(this, pElement, pAttributeName, bAddAttribute);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401B90
// Name: public: class CDmElement __near * CDmElement::GetValueElement<class CDmElement>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmElement::GetValueElement<CDmElement>(CDmElement *this, const char *pAttributeName)
{
  CDmaVar<enum DmElementHandle_t> *v2; // eax
  CDmElement *v3; // esi

  v2 = CDmElement::GetValue<enum DmElementHandle_t>(this, pAttributeName);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2->m_Storage.m_Handle);
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmElement::m_classType.m_Id) )
    return v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00401BE0
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  int m_nAllocationCount; // eax
  unsigned __int16 v4; // di
  int v5; // eax
  unsigned __int16 i; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    v4 = (m_nAllocationCount > 0) - 1;
    i = v4;
    if ( m_nAllocationCount > 0 )
    {
      do
      {
        if ( v4 < m_nAllocationCount
          && v4 <= index
          && CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Left != v4 )
        {
          v5 = v4;
          this->m_Elements.m_pMemory[v5].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v5].m_Left = v4;
          this->m_FirstFree = v4;
        }
        index = this->m_LastAlloc.index;
        if ( v4 == index )
          break;
        m_nAllocationCount = this->m_Elements.m_nAllocationCount;
        ++v4;
        if ( (unsigned __int16)(i + 1) >= m_nAllocationCount )
          v4 = -1;
        i = v4;
      }
      while ( v4 != 0xFFFF );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401CA0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int v1; // ebx
  int result; // eax
  UtlRBTreeLinks_t<unsigned short> *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : &this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( v3->m_Left == 0xFFFF )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
      `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
    }
    if ( (_WORD)result == 0xFFFF )
      result = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left;
    else
      result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401D50
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  unsigned __int16 v2; // di
  int result; // eax
  int v5; // edx
  UtlRBTreeLinks_t<unsigned short> *v6; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v7; // eax
  int v8; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v9; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeLinks_t<unsigned short> *v11; // ecx

  v2 = i;
  if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i)->m_Right == 0xFFFF )
  {
    v7 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                                                                               this,
                                                                                               i);
    v8 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      result = v7->m_Parent;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v9 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v9 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v9->m_Parent;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v11 = m_Parent == 0xFFFF
          ? &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : &this->m_Elements.m_pMemory[m_Parent];
      if ( v11->m_Right != v2 )
        break;
      v2 = result;
      if ( (_WORD)result == 0xFFFF )
        break;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v7 = &this->m_Elements.m_pMemory[(unsigned __int16)result];
    }
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Right;
    v5 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v6 = (_WORD)result == 0xFFFF
         ? &`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : &this->m_Elements.m_pMemory[(unsigned __int16)result];
      if ( v6->m_Left == 0xFFFF )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( (_WORD)result == 0xFFFF )
        result = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left;
      else
        result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401F00
// Name: ReplaceChildReferences
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReplaceChildReferences(KeyValues *pElement, CDmElement *pOldVersion, CDmElement *pNewVersion)
{
  CDmAttribute *FirstSubKey; // ebp
  int i; // edi
  int v5; // eax
  CDmaVar<enum DmElementHandle_t> *m_pData; // eax
  CDmElement *v7; // esi
  CDmAttribute *m_pAttribute; // eax
  int m_nFlags; // ebx
  CDmElement *v10; // esi
  CDmElement *v11; // esi
  DmElementHandle_t value; // [esp+8h] [ebp-10h] BYREF
  CDmrElementArray<CDmElement> arr; // [esp+Ch] [ebp-Ch] BYREF
  CDmAttribute *v14; // [esp+14h] [ebp-4h]

  FirstSubKey = (CDmAttribute *)KeyValues::GetFirstSubKey(this: pElement);
  for ( i = 0; FirstSubKey != nullptr; i = 0 )
  {
    v5 = FirstSubKey->m_nFlags & 0x1F;
    if ( v5 == 1 )
    {
      if ( (`CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType = -1;
        `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
      }
      if ( (FirstSubKey->m_nFlags & 0x1F) == 1 )
        m_pData = (CDmaVar<enum DmElementHandle_t> *)FirstSubKey->m_pData;
      else
        m_pData = &`CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Storage.m_Handle);
      if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType.m_Id) )
        v7 = nullptr;
      if ( v7 == pOldVersion )
      {
        if ( (FirstSubKey->m_nFlags & 0x1F) == 1 )
        {
          if ( pNewVersion != nullptr )
            value = CDmElement::GetHandle(this: pNewVersion);
          else
            value = DMELEMENT_HANDLE_INVALID;
          CDmAttribute::SetValue<enum DmElementHandle_t>(this: FirstSubKey, &value);
        }
      }
      else
      {
        ReplaceChildReferences(pElement: v7, pOldVersion, pNewVersion);
      }
    }
    else if ( v5 == 15 )
    {
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&arr.m_pAttribute);
      if ( (FirstSubKey->m_nFlags & 0x1F) == 0xF )
      {
        v14 = FirstSubKey;
        m_pAttribute = (CDmAttribute *)FirstSubKey->m_pData;
      }
      else
      {
        v14 = nullptr;
        m_pAttribute = nullptr;
      }
      arr.m_pAttribute = m_pAttribute;
      m_nFlags = m_pAttribute->m_nFlags;
      if ( m_nFlags > 0 )
      {
        while ( 1 )
        {
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&m_pAttribute->m_pNext->m_pNext + i));
          if ( v10 == nullptr || !v10->IsA(this: v10, a2: CDmElement::m_classType.m_Id) )
            v10 = nullptr;
          if ( v10 == pOldVersion )
          {
            arr.m_pStorage = (DmElementArray_t *)(pNewVersion != nullptr ? CDmElement::GetHandle(this: pNewVersion) : -1);
            CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Set(
              this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)&arr.m_pAttribute,
              i,
              value: (const DmElementHandle_t *)&arr);
          }
          else
          {
            v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&arr.m_pAttribute->m_pNext->m_pNext + i));
            if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmElement::m_classType.m_Id) )
              v11 = nullptr;
            ReplaceChildReferences(pElement: v11, pOldVersion, pNewVersion);
          }
          if ( ++i >= m_nFlags )
            break;
          m_pAttribute = arr.m_pAttribute;
        }
      }
    }
    FirstSubKey = FirstSubKey->m_pNext;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402120
// Name: AddUniqueElementsToList
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddUniqueElementsToList(CDmElement *pElement, CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list)
{
  int m_pMemory; // edi
  int v4; // esi
  int v5; // esi
  int m_nAllocationCount; // eax
  CDmElement **v7; // ecx
  int v8; // eax
  bool v9; // zf
  CDmElement **v10; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *m_pData; // eax
  int v13; // edi
  const char *v14; // eax
  CDmElement *v15; // esi
  CDmAttribute *v16; // eax
  CDmaVar<enum DmElementHandle_t> *v17; // eax
  CDmElement *v18; // esi
  const char *v19; // [esp-4h] [ebp-1Ch]
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-Ch] BYREF
  CDmAttribute *v21; // [esp+14h] [ebp-4h]
  int nChildCount; // [esp+20h] [ebp+8h]

  m_pMemory = (int)list[1].m_pMemory;
  v4 = 0;
  if ( m_pMemory <= 0 )
  {
LABEL_4:
    v5 = (int)list[1].m_pMemory;
    m_nAllocationCount = list->m_nAllocationCount;
    if ( v5 + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v5 - m_nAllocationCount + 1);
    ++list[1].m_pMemory;
    v7 = (CDmElement **)list->m_pMemory;
    v8 = (int)list[1].m_pMemory - v5 - 1;
    v9 = (CUtlSymbolTable::StringPool_t **)((char *)list[1].m_pMemory - v5) == (CUtlSymbolTable::StringPool_t **)1;
    list[1].m_nAllocationCount = (int)list->m_pMemory;
    if ( v8 >= 0 && !v9 )
      memmove(dst: (unsigned __int8 *)&v7[v5 + 1], src: (unsigned __int8 *)&v7[v5], count: 4 * v8);
    v10 = (CDmElement **)&list->m_pMemory[v5];
    if ( v10 != nullptr )
      *v10 = pElement;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&children.m_pAttribute);
    if ( pElement != nullptr )
    {
      Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: "children");
      if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
      {
        v21 = Attribute;
        m_pData = (CDmAttribute *)Attribute->m_pData;
        children.m_pAttribute = m_pData;
        v13 = 0;
        nChildCount = m_pData->m_nFlags;
        if ( nChildCount > 0 )
        {
          while ( 1 )
          {
            v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&m_pData->m_pNext->m_pNext + v13));
            if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmElement::m_classType.m_Id) )
              v15 = nullptr;
            if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
            {
              `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
              `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType = -1;
              `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
              `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
            }
            v16 = CDmElement::FindAttribute(this: v15, pAttributeName: "child");
            if ( v16 != nullptr )
            {
              if ( (`CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
              {
                `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
                `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType = -1;
                `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
                `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
              }
              v17 = (v16->m_nFlags & 0x1F) == 1
                  ? (CDmaVar<enum DmElementHandle_t> *)v16->m_pData
                  : &`CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
            }
            else
            {
              v17 = &`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
            }
            v18 = g_pDataModel->GetElement(this: g_pDataModel, a2: v17->m_Storage.m_Handle);
            if ( v18 != nullptr && v18->IsA(this: v18, a2: CDmElement::m_classType.m_Id) )
              AddUniqueElementsToList(pElement: v18, (CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > *)list);
            if ( ++v13 >= nChildCount )
              break;
            m_pData = children.m_pAttribute;
          }
        }
      }
    }
  }
  else
  {
    while ( !IsUniqueIdEqual(id1: &pElement->m_Id, id2: (const UniqueId_t *)&list->m_pMemory[v4][4]) )
    {
      if ( ++v4 >= m_pMemory )
        goto LABEL_4;
    }
    if ( pElement != (CDmElement *)list->m_pMemory[v4] )
    {
      _Warning(a1: "Encountered two different elements with the same unique id!!\n");
      v19 = CUtlString::operator char const *(this: (CUtlString *)&list->m_pMemory[v4]->m_SpaceUsed);
      v14 = CUtlString::operator char const *(this: &pElement->m_Name.m_Storage);
      _Warning(a1: "\tElement #1: %s Element #2: %s\n", v14, v19);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402350
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004023B0
// Name: public: void CUtlDict<int,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,unsigned short>::RemoveAll(CUtlDict<int,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00402400
// Name: public: class CUtlString const __near & CDmAttribute::GetValue<class CUtlString>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlString> *__thiscall CDmAttribute::GetValue<CUtlString>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlString>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlString>'::`2'::`local static guard' |= 1u;
    CUtlString::CUtlString(this: &`CDmAttribute::GetValue<CUtlString>'::`2'::defaultVal.m_Storage);
    `CDmAttribute::GetValue<CUtlString>'::`2'::defaultVal.m_pAttribute = nullptr;
    CUtlString::Set(this: &`CDmAttribute::GetValue<CUtlString>'::`2'::defaultVal.m_Storage, pValue: nullptr);
    atexit(func: `CDmAttribute::GetValue<CUtlString>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 5 )
    return (CDmaVar<CUtlString> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlString>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00402460
// Name: public: char const __near * CDmAttribute::GetValueString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmAttribute::GetValueString(CDmAttribute *this)
{
  CDmaVar<CUtlString> *v2; // eax

  if ( (this->m_nFlags & 0x1F) != 5 )
    return nullptr;
  v2 = CDmAttribute::GetValue<CUtlString>(this);
  return CUtlString::operator char const *(this: &v2->m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x00402480
// Name: IsScalarAttributesEqual
// Source: json
//------------------------------------------------------------------------------
char __usercall IsScalarAttributesEqual@<al>(CDmElement *pElement1@<eax>, CDmElement *pElement2)
{
  int v3; // edi
  CDmAttribute *FirstSubKey; // esi
  const char *v6; // eax
  CDmAttribute *Attribute; // edi
  int v8; // eax
  CDmaVar<float> *v9; // ebx
  CDmaVar<bool> *v10; // edi
  bool v11; // zf
  CDmaVar<int> *v12; // edi
  const char *ValueString; // edi
  const char *v14; // eax
  CDmaVar<Vector2D> *v15; // eax
  CDmaVar<Vector> *v16; // eax
  CDmaVar<Vector4D> *v17; // eax
  CDmaVar<Color> *v18; // edi
  CDmaVar<Vector2D> *v19; // [esp-8h] [ebp-14h]
  CDmaVar<Vector> *v20; // [esp-8h] [ebp-14h]
  CDmaVar<Vector4D> *v21; // [esp-8h] [ebp-14h]

  v3 = CDmElement::AttributeCount(this: pElement1);
  if ( v3 != CDmElement::AttributeCount(this: pElement2) )
    return 0;
  FirstSubKey = (CDmAttribute *)KeyValues::GetFirstSubKey(this: (KeyValues *)pElement1);
  if ( FirstSubKey == nullptr )
    return 1;
  while ( 1 )
  {
    v6 = g_pDataModel->GetString(this: g_pDataModel, a2: FirstSubKey->m_Name.m_Id);
    Attribute = CDmElement::FindAttribute(this: pElement2, pAttributeName: v6);
    if ( Attribute == nullptr )
      return 0;
    v8 = FirstSubKey->m_nFlags & 0x1F;
    if ( v8 != (Attribute->m_nFlags & 0x1F) )
      return 0;
    if ( (unsigned int)(v8 - 15) > 0xD )
    {
      switch ( v8 )
      {
        case 2:
          v12 = CDmAttribute::GetValue<int>(this: Attribute);
          v11 = CDmAttribute::GetValue<int>(this: FirstSubKey)->m_Storage == v12->m_Storage;
          break;
        case 3:
          v9 = CDmAttribute::GetValue<float>(this: FirstSubKey);
          if ( CDmAttribute::GetValue<float>(this: Attribute)->m_Storage != v9->m_Storage )
            return 0;
          goto LABEL_18;
        case 4:
          v10 = CDmAttribute::GetValue<bool>(this: Attribute);
          v11 = CDmAttribute::GetValue<bool>(this: FirstSubKey)->m_Storage == v10->m_Storage;
          break;
        case 5:
          ValueString = CDmAttribute::GetValueString(this: Attribute);
          v14 = CDmAttribute::GetValueString(this: FirstSubKey);
          v11 = _stricmp(dst: v14, src: ValueString) == 0;
          break;
        case 8:
          v18 = CDmAttribute::GetValue<Color>(this: Attribute);
          v11 = *(_DWORD *)&CDmAttribute::GetValue<Color>(this: FirstSubKey)->m_Storage == *(_DWORD *)&v18->m_Storage;
          break;
        case 9:
          v19 = CDmAttribute::GetValue<Vector2D>(this: Attribute);
          v15 = CDmAttribute::GetValue<Vector2D>(this: FirstSubKey);
          v11 = !Vector2D::operator!=(this: &v15->m_Storage, src: &v19->m_Storage);
          break;
        case 10:
          v20 = CDmAttribute::GetValue<Vector>(this: Attribute);
          v16 = CDmAttribute::GetValue<Vector>(this: FirstSubKey);
          v11 = !Vector::operator!=(this: &v16->m_Storage, src: &v20->m_Storage);
          break;
        case 11:
          v21 = CDmAttribute::GetValue<Vector4D>(this: Attribute);
          v17 = CDmAttribute::GetValue<Vector4D>(this: FirstSubKey);
          v11 = !Vector4D::operator!=(this: &v17->m_Storage, src: &v21->m_Storage);
          break;
        default:
          goto LABEL_18;
      }
      if ( !v11 )
        return 0;
    }
LABEL_18:
    FirstSubKey = FirstSubKey->m_pNext;
    if ( FirstSubKey == nullptr )
      return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402630
// Name: IsArrayEqual
// Source: json
//------------------------------------------------------------------------------
char __usercall IsArrayEqual@<al>(
        CDmElement *pElement1@<ecx>,
        const char *pArrayAttribute@<eax>,
        CDmElement *pElement2)
{
  int m_nFlags; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // ecx
  CDmAttribute *m_pData; // eax
  int v10; // ecx
  int v12; // ebp
  CDmElement *v13; // esi
  CDmElement *v14; // edi
  CDmElement *v15; // eax
  CDmrElementArray<CDmElement> arr1; // [esp+Ch] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> arr2; // [esp+14h] [ebp-Ch] BYREF
  CDmAttribute *v18; // [esp+1Ch] [ebp-4h]

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&arr1.m_pAttribute);
  m_nFlags = 0;
  if ( pElement1 != nullptr
    && pArrayAttribute != nullptr
    && *pArrayAttribute != 0
    && (Attribute = CDmElement::FindAttribute(this: pElement1, pAttributeName: pArrayAttribute)) != nullptr
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    arr2.m_pStorage = (DmElementArray_t *)Attribute;
    arr1.m_pAttribute = (CDmAttribute *)Attribute->m_pData;
  }
  else
  {
    arr2.m_pStorage = nullptr;
    arr1.m_pAttribute = nullptr;
  }
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&arr2.m_pAttribute);
  if ( pElement2 != nullptr
    && pArrayAttribute != nullptr
    && *pArrayAttribute != 0
    && (v7 = CDmElement::FindAttribute(this: pElement2, pAttributeName: pArrayAttribute)) != nullptr
    && (v7->m_nFlags & 0x1F) == 0xF )
  {
    v8 = v7;
    v18 = v7;
    m_pData = (CDmAttribute *)v7->m_pData;
  }
  else
  {
    v8 = nullptr;
    v18 = nullptr;
    m_pData = nullptr;
  }
  arr2.m_pAttribute = m_pData;
  if ( arr2.m_pStorage != nullptr )
    m_nFlags = arr1.m_pAttribute->m_nFlags;
  if ( v8 != nullptr )
    v10 = m_pData->m_nFlags;
  else
    v10 = 0;
  if ( m_nFlags != v10 )
    return 0;
  v12 = 0;
  if ( m_nFlags > 0 )
  {
    while ( 1 )
    {
      v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&m_pData->m_pNext->m_pNext + v12));
      if ( v13 == nullptr || !v13->IsA(this: v13, a2: CDmElement::m_classType.m_Id) )
        v13 = nullptr;
      v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&arr1.m_pAttribute->m_pNext->m_pNext + v12));
      if ( v14 != nullptr && v14->IsA(this: v14, a2: CDmElement::m_classType.m_Id) )
        v15 = v14;
      else
        v15 = nullptr;
      if ( IsScalarAttributesEqual(pElement1: v15, pElement2: v13) == 0 )
        break;
      if ( ++v12 >= m_nFlags )
        return 1;
      m_pData = arr2.m_pAttribute;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402790
// Name: IsDefEqual
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsDefEqual(CDmElement *pElement1, CDmElement *pElement2)
{
  int v3; // ebx
  int v4; // eax
  int i; // esi
  CDmElement *v6; // eax
  CDmElement *Value; // edi
  CDmElement *v8; // eax
  CDmElement *v9; // eax
  CDmrElementArray<CDmElement> arr1; // [esp+10h] [ebp-10h] BYREF
  CDmrElementArray<CDmElement> arr2; // [esp+18h] [ebp-8h] BYREF

  if ( IsScalarAttributesEqual(pElement1, pElement2) == 0
    || IsArrayEqual(pElement1, pArrayAttribute: "renderer", pElement2) == 0
    || IsArrayEqual(pElement1, pArrayAttribute: "operator", pElement2) == 0
    || IsArrayEqual(pElement1, pArrayAttribute: "initializer", pElement2) == 0
    || IsArrayEqual(pElement1, pArrayAttribute: "emitter", pElement2) == 0
    || IsArrayEqual(pElement1, pArrayAttribute: "forcegenerator", pElement2) == 0
    || IsArrayEqual(pElement1, pArrayAttribute: "constraint", pElement2) == 0
    || IsArrayEqual(pElement1, pArrayAttribute: "children", pElement2) == 0 )
  {
    return 0;
  }
  CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
    this: &arr1,
    pElement: pElement1,
    pAttributeName: "children",
    bAddAttribute: false);
  CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
    this: &arr2,
    pElement: pElement2,
    pAttributeName: "children",
    bAddAttribute: false);
  v3 = arr1.m_pAttribute != nullptr ? arr1.m_pStorage->m_Size : 0;
  v4 = arr2.m_pAttribute != nullptr ? arr2.m_pStorage->m_Size : 0;
  if ( v3 != v4 )
    return 0;
  for ( i = 0; i < v3; ++i )
  {
    v6 = CDmaElementArrayConstBase<CDmElement,CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>>::operator[](
           this: (CDmaElementArrayConstBase<CDmElement,CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > > *)&arr1,
           i);
    Value = CDmElement::GetValueElement<CDmElement>(this: v6, pAttributeName: "child");
    v8 = CDmaElementArrayConstBase<CDmElement,CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>>::operator[](
           this: (CDmaElementArrayConstBase<CDmElement,CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > > *)&arr2,
           i);
    v9 = CDmElement::GetValueElement<CDmElement>(this: v8, pAttributeName: "child");
    if ( Value != nullptr )
    {
      if ( v9 == nullptr || !IsDefEqual(pElement1: Value, pElement2: v9) )
        return 0;
    }
    else if ( v9 != nullptr )
    {
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402910
// Name: FindOrAddDef
// Source: json
//------------------------------------------------------------------------------
CDmElement *__cdecl FindOrAddDef(CDmElement *pDef, CUtlStringMap<int> *uniqueNames)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *defs; // ecx
  CUtlStringMap<int> *v3; // ebx
  CDmElement *v4; // ebp
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v5; // esi
  int m_pMemory; // eax
  CDmaString *p_m_Name; // ebp
  const char *v8; // ebx
  const char *v9; // eax
  const char *v10; // eax
  CUtlSymbolTable::StringPool_t **v11; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v13; // ecx
  int v14; // eax
  bool v15; // zf
  CDmElement **v16; // edi
  const char *v17; // eax
  CUtlSymbol *v18; // eax
  CUtlString *p_m_Storage; // ecx
  const char *v20; // eax
  int m_Id; // esi
  int m_Size; // ecx
  const char *v24; // eax
  int v25; // edi
  int v26; // ecx
  int *v27; // eax
  const char *v28; // eax
  int v29; // [esp-4h] [ebp-338h]
  CUtlSymbol v30[2]; // [esp+10h] [ebp-324h] BYREF
  CDmElement *pElement1; // [esp+14h] [ebp-320h]
  int nCount; // [esp+18h] [ebp-31Ch]
  int v33; // [esp+1Ch] [ebp-318h]
  CUtlString value; // [esp+20h] [ebp-314h] BYREF
  char v35[124]; // [esp+30h] [ebp-304h] BYREF
  char pTemp[128]; // [esp+ACh] [ebp-288h] BYREF
  char pNewName[516]; // [esp+12Ch] [ebp-208h] BYREF

  v3 = uniqueNames;
  v4 = pDef;
  v5 = defs;
  m_pMemory = (int)defs[1].m_pMemory;
  pElement1 = pDef;
  nCount = (int)uniqueNames;
  v33 = m_pMemory;
  *(_DWORD *)&v30[0].m_Id = 0;
  if ( m_pMemory > 0 )
  {
    p_m_Name = &pDef->m_Name;
    while ( 1 )
    {
      v8 = CUtlString::operator char const *(this: (CUtlString *)&v5->m_pMemory[*(_DWORD *)&v30[0].m_Id]->m_SpaceUsed);
      v9 = CUtlString::operator char const *(this: &p_m_Name->m_Storage);
      if ( _stricmp(dst: v9, src: v8) == 0 )
      {
        if ( IsDefEqual(pElement1, pElement2: (CDmElement *)v5->m_pMemory[*(_DWORD *)&v30[0].m_Id]) != 0 )
          return (CDmElement *)v5->m_pMemory[*(_DWORD *)&v30[0].m_Id];
        UniqueIdToString(id: &pElement1->m_Id, pBuf: &pTemp[4], nMaxLen: 128);
        UniqueIdToString(id: (const UniqueId_t *)&v5->m_pMemory[*(_DWORD *)&v30[0].m_Id][4], pBuf: v35, nMaxLen: 128);
        _Warning(a1: "WARNING: Discovered duplicated systems with different values!\n");
        v10 = CUtlString::operator char const *(this: &p_m_Name->m_Storage);
        _Warning(a1: "\tName %s\n\tid #1 %s\n\tid #2 %s\n", v10, &pTemp[4], v35);
      }
      ++*(_DWORD *)&v30[0].m_Id;
      if ( *(int *)&v30[0].m_Id >= v33 )
      {
        v4 = pElement1;
        v3 = (CUtlStringMap<int> *)nCount;
        break;
      }
    }
  }
  v11 = v5[1].m_pMemory;
  m_nAllocationCount = v5->m_nAllocationCount;
  if ( (int)v11 + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v5, num: (int)v11 - m_nAllocationCount + 1);
  ++v5[1].m_pMemory;
  v13 = v5->m_pMemory;
  v14 = (char *)v5[1].m_pMemory - (char *)v11 - 1;
  v15 = (char *)v5[1].m_pMemory - (char *)v11 == 1;
  v5[1].m_nAllocationCount = (int)v5->m_pMemory;
  if ( v14 >= 0 && !v15 )
    memmove(dst: (unsigned __int8 *)&v13[(_DWORD)v11 + 1], src: (unsigned __int8 *)&v13[(_DWORD)v11], count: 4 * v14);
  v16 = (CDmElement **)&v5->m_pMemory[(_DWORD)v11];
  if ( v16 != nullptr )
    *v16 = v4;
  v17 = CUtlString::operator char const *(this: &v4->m_Name.m_Storage);
  v18 = CUtlSymbolTable::Find(this: &v3->m_SymbolTable, result: v30, pString: v17);
  p_m_Storage = &v4->m_Name.m_Storage;
  if ( v18->m_Id == 0xFFFF )
  {
    v20 = CUtlString::operator char const *(this: p_m_Storage);
    CUtlSymbolTable::AddString(this: &v3->m_SymbolTable, result: v30, pString: v20);
    m_Id = v30[0].m_Id;
    m_Size = v3->m_Vector.m_Size;
    if ( m_Size <= v30[0].m_Id && m_Size < v30[0].m_Id + 1 )
      CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        this: (CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)v3,
        elem: m_Size,
        num: v30[0].m_Id + 1 - m_Size,
        pToInsert: nullptr);
    v3->m_Vector.m_Memory.m_pMemory[m_Id] = 1;
  }
  else
  {
    v24 = CUtlString::operator char const *(this: p_m_Storage);
    CUtlSymbolTable::AddString(this: &v3->m_SymbolTable, result: v30, pString: v24);
    v25 = v30[0].m_Id;
    v26 = v3->m_Vector.m_Size;
    if ( v26 <= v30[0].m_Id && v26 < v30[0].m_Id + 1 )
      CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        this: (CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)v3,
        elem: v26,
        num: v30[0].m_Id + 1 - v26,
        pToInsert: nullptr);
    v27 = v3->m_Vector.m_Memory.m_pMemory;
    v29 = ++v27[v25];
    v28 = CUtlString::operator char const *(this: &v4->m_Name.m_Storage);
    V_snprintf(pDest: &pNewName[4], maxLen: 512, pFormat: "%s Version #%d", v28, v29);
    CUtlString::CUtlString(this: &value, pMemory: &pNewName[4], nSizeInBytes: strlen(&pNewName[4]) + 1);
    CDmAttribute::SetValue<CUtlString>(this: v4->m_Name.m_pAttribute, &value);
    if ( value.m_Storage.m_Memory.m_nGrowSize >= 0 && value.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: value.m_Storage.m_Memory.m_pMemory);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00402BC0
// Name: private: void CPCFFixApp::FixupPCFFile(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPCFFixApp::FixupPCFFile(CPCFFixApp *this, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *m_pData; // eax
  int m_nFlags; // ebp
  int v5; // edi
  CDmElement *v6; // esi
  int v7; // esi
  CDmElement **m_pElements; // ebp
  int m_nAllocationCount; // ecx
  CDmElement *v10; // eax
  CDmElement **v11; // edi
  int i; // esi
  CDmElement *v13; // ecx
  void *v14; // eax
  CDmElement **v15; // eax
  CDmrElementArray<CDmElement> rootDefs; // [esp+Ch] [ebp-80h] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > startingDefs; // [esp+14h] [ebp-78h] BYREF
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > defs; // [esp+28h] [ebp-64h] BYREF
  CUtlStringMap<int> uniqueNames; // [esp+3Ch] [ebp-50h] BYREF

  memset(&startingDefs.m_Memory.m_nAllocationCount, 0, 16);
  memset(&defs, 0, sizeof(defs));
  memset(&uniqueNames, 0, 12);
  uniqueNames.m_Vector.m_Size = 1;
  uniqueNames.m_Vector.m_pElements = nullptr;
  *(_DWORD *)&uniqueNames.m_SymbolTable.m_Lookup.m_LessFunc = 0;
  CUtlSymbolTable::CUtlSymbolTable(
    this: (CUtlSymbolTable *)&uniqueNames.m_SymbolTable.m_Lookup.m_Elements,
    growSize: 0,
    initSize: 32,
    caseInsensitive: false);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&rootDefs.m_pAttribute);
  if ( pRoot != nullptr
    && (Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "particleSystemDefinitions")) != nullptr
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    startingDefs.m_Memory.m_pMemory = (CDmElement **)Attribute;
    m_pData = (CDmAttribute *)Attribute->m_pData;
  }
  else
  {
    startingDefs.m_Memory.m_pMemory = nullptr;
    m_pData = nullptr;
  }
  rootDefs.m_pAttribute = m_pData;
  m_nFlags = m_pData->m_nFlags;
  v5 = 0;
  if ( m_nFlags > 0 )
  {
    while ( 1 )
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&m_pData->m_pNext->m_pNext + v5));
      if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmElement::m_classType.m_Id) )
        v6 = nullptr;
      AddUniqueElementsToList(
        pElement: v6,
        list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&startingDefs.m_Memory.m_nAllocationCount);
      if ( ++v5 >= m_nFlags )
        break;
      m_pData = rootDefs.m_pAttribute;
    }
  }
  v7 = 0;
  m_pElements = startingDefs.m_pElements;
  if ( (int)startingDefs.m_pElements > 0 )
  {
    m_nAllocationCount = startingDefs.m_Memory.m_nAllocationCount;
    do
    {
      v10 = FindOrAddDef(
              pDef: *(CDmElement **)(m_nAllocationCount + 4 * v7),
              uniqueNames: (CUtlStringMap<int> *)&uniqueNames.m_Vector.m_Memory.m_nAllocationCount);
      m_nAllocationCount = startingDefs.m_Memory.m_nAllocationCount;
      if ( v10 != *(CDmElement **)(startingDefs.m_Memory.m_nAllocationCount + 4 * v7) )
      {
        ReplaceChildReferences(
          pElement: (KeyValues *)pRoot,
          pOldVersion: *(CDmElement **)(startingDefs.m_Memory.m_nAllocationCount + 4 * v7),
          pNewVersion: v10);
        m_nAllocationCount = startingDefs.m_Memory.m_nAllocationCount;
      }
      ++v7;
    }
    while ( v7 < (int)m_pElements );
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)&rootDefs.m_pAttribute);
  v11 = defs.m_pElements;
  for ( i = 0; i < (int)v11; ++i )
  {
    v13 = *(CDmElement **)(defs.m_Memory.m_nAllocationCount + 4 * i);
    if ( v13 != nullptr )
      rootDefs.m_pStorage = (DmElementArray_t *)CDmElement::GetHandle(this: v13);
    else
      rootDefs.m_pStorage = (DmElementArray_t *)-1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)&rootDefs.m_pAttribute,
      src: (const DmElementHandle_t *)&rootDefs);
  }
  if ( m_pElements == v11 )
    _Warning(a1: "Removed no duplicated particle systems. This file started out ok.\n");
  else
    _Warning(a1: "*** Removed %d duplicated particle systems!\n", (char *)m_pElements - (char *)v11);
  CUtlSymbolTable::~CUtlSymbolTable(this: (CUtlSymbolTable *)&uniqueNames.m_SymbolTable.m_Lookup.m_Elements);
  v14 = (void *)uniqueNames.m_Vector.m_Memory.m_nAllocationCount;
  uniqueNames.m_Vector.m_pElements = nullptr;
  if ( uniqueNames.m_Vector.m_Size >= 0 )
  {
    if ( uniqueNames.m_Vector.m_Memory.m_nAllocationCount != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)uniqueNames.m_Vector.m_Memory.m_nAllocationCount);
      v14 = nullptr;
      uniqueNames.m_Vector.m_Memory.m_nAllocationCount = 0;
    }
    uniqueNames.m_Vector.m_Memory.m_nGrowSize = 0;
  }
  *(_DWORD *)&uniqueNames.m_SymbolTable.m_Lookup.m_LessFunc = v14;
  if ( uniqueNames.m_Vector.m_Size >= 0 )
  {
    if ( v14 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
      uniqueNames.m_Vector.m_Memory.m_nAllocationCount = 0;
    }
    uniqueNames.m_Vector.m_Memory.m_nGrowSize = 0;
  }
  if ( defs.m_Size >= 0 && defs.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)defs.m_Memory.m_nAllocationCount);
  v15 = (CDmElement **)startingDefs.m_Memory.m_nAllocationCount;
  startingDefs.m_pElements = nullptr;
  if ( startingDefs.m_Size >= 0 )
  {
    if ( startingDefs.m_Memory.m_nAllocationCount != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)startingDefs.m_Memory.m_nAllocationCount);
      v15 = nullptr;
      startingDefs.m_Memory.m_nAllocationCount = 0;
    }
    startingDefs.m_Memory.m_nGrowSize = 0;
  }
  defs.m_Memory.m_pMemory = v15;
  if ( startingDefs.m_Size >= 0 && v15 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
}

//------------------------------------------------------------------------------
// Address: 0x00402E40
// Name: public: virtual int CPCFFixApp::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPCFFixApp::Main(CPCFFixApp *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  const char *v7; // esi
  const char *v9; // eax
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  CP4AutoEditFile checkout; // [esp+64h] [ebp-8h] BYREF
  CP4AutoEditFile v14; // [esp+68h] [ebp-4h] BYREF

  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  g_pDataModel->OnlyCreateUntypedElements(this: g_pDataModel, a2: true);
  g_pDataModel->SetDefaultElementFactory(this: g_pDataModel, a2: nullptr);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: defaultValue, a3: "LOCAL", a4: PATH_ADD_TO_HEAD);
  v2 = _CommandLine_Tier0();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-h", a3: 0) != 0
    || (v4 = _CommandLine_Tier0(),
        (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-help", a3: 0) != 0) )
  {
    _Msg(a1: v3, a2: "Usage: pcffix -i <in .pcf file> [-nop4]\n");
    _Msg(a1: v10, a2: "\t-i\t: Source .PCF file to fix up (eliminate copied particle system definitions.)\n");
    _Msg(a1: v11, a2: "\t-nop4\t: Disables auto perforce checkout/add.\n");
    _Msg(a1: v12, a2: "\t-vproject\t: Specifies path to a gameinfo.txt file (which mod to build for).\n");
    return 0;
  }
  else
  {
    v5 = _CommandLine_Tier0();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-nop4") != 0 )
      CP4Factory::SetDummyMode(this: g_p4factory, bDummyMode: true);
    CP4Factory::SetOpenFileChangeList(this: g_p4factory, szChangeListName: "Fixed PCF files");
    v6 = _CommandLine_Tier0();
    v7 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 32))(a1: v6, a2: "-i", a3: 0);
    if ( v7 != nullptr )
    {
      if ( g_pDataModel->RestoreFromFile(
             this: g_pDataModel,
             a2: v7,
             a3: nullptr,
             a4: "pcf",
             a5: (CDmElement **)&checkout,
             a6: CR_DELETE_NEW,
             a7: nullptr) == DMFILEID_INVALID )
      {
        _Error(a1: "Encountered an error reading file \"%s\"!\n", v7);
        return -1;
      }
      else
      {
        CPCFFixApp::FixupPCFFile(this, pRoot: (CDmElement *)checkout.m_spImpl.m_p);
        CP4AutoEditFile::CP4AutoEditFile(this: &v14, szFilename: v7);
        v9 = g_pDataModel->GetDefaultEncoding(this: g_pDataModel, a2: "pcf");
        if ( g_pDataModel->SaveToFile(
               this: g_pDataModel,
               a2: v7,
               a3: nullptr,
               a4: v9,
               a5: "pcf",
               a6: (CDmElement *)checkout.m_spImpl.m_p) )
        {
          g_pDataModel->RemoveFileId(
            this: g_pDataModel,
            a2: (DmFileId_t)checkout.m_spImpl.m_p[3].m_sFilename.m_Storage.m_Memory.m_pMemory);
        }
        else
        {
          _Error(a1: "Encountered an error writing file \"%s\"!\n", v7);
        }
        CP4AutoEditFile::~CP4AutoEditFile(this: &v14);
        return -1;
      }
    }
    else
    {
      CPCFFixApp::PrintHelp(this);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403030
// Name: public: virtual void CTier2DmSteamApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2DmSteamApp::PostShutdown(CTier2DmSteamApp *this)
{
  ShutdownDataModel();
  DisconnectDataModel();
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x004032A0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // edi
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // eax
  IMemAlloc_vtbl *v7; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    this->m_nAllocationCount = m_nAllocationCount;
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
        {
          v6 = (v5 + this->m_nAllocationCount) / 2;
          this->m_nAllocationCount = v6;
        }
        while ( (unsigned __int16)v6 < v5 );
      }
      else
      {
        this->m_nAllocationCount = m_nAllocationCount - 1;
      }
    }
    v7 = _g_pMemAlloc->__vftable;
    if ( this->m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)((int (__stdcall *)(UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *, int))v7->Realloc_2)(a1: this->m_pMemory, a2: 16 * this->m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)((int (__stdcall *)(int))v7->Alloc_2)(a1: 16 * this->m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403360
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,int,unsigned short>::Node_t *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403470
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_FirstFree; // cx
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *p_m_LastAlloc; // ebp
  unsigned __int16 v5; // cx
  unsigned __int16 index; // di
  int v7; // ebx
  CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Iterator_t *v8; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  int result; // eax
  int v11; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v12; // ecx
  CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Iterator_t v13; // [esp+6h] [ebp-2h] BYREF

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    p_m_LastAlloc = &this->m_LastAlloc;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else if ( (unsigned __int16)(p_m_LastAlloc->index + 1) >= m_nAllocationCount )
    {
      v5 = -1;
    }
    else
    {
      v5 = p_m_LastAlloc->index + 1;
    }
    v13.index = v5;
    index = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( p_m_LastAlloc->index >= v7 )
      {
        v13.index = (v7 > 0) - 1;
        v8 = &v13;
      }
      else
      {
        v8 = CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>::Next(
               this: (CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *)&this->m_Elements,
               result: &v13,
               it: (const CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Iterator_t *)&this->m_LastAlloc);
      }
      index = v8->index;
      if ( v8->index >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    p_m_LastAlloc->index = index;
    this->m_pElements = m_pMemory;
    return index;
  }
  else
  {
    v11 = m_FirstFree;
    result = m_FirstFree;
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[v11].m_Right;
    this->m_pElements = v12;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403560
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Right; // bx
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Right = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
              this,
              i: elem)->m_Right;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Right = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                             this,
                                             i: m_Right)->m_Left;
  if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Right)->m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Right)->m_Left].m_Parent = elem;
  if ( m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                                     this,
                                                     i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else
  {
    v5 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Left == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Right;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00403650
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Left; // di
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Left = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
             this,
             i: elem)->m_Left;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Left = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                            this,
                                            i: m_Left)->m_Right;
  if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Left)->m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Left)->m_Right].m_Parent = elem;
  if ( m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                                    this,
                                                    i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Right == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004037B0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,int,unsigned short>::Node_t *search)
{
  unsigned __int16 m_Root; // bp
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x004038B0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v8; // ecx
  unsigned __int16 v9; // di
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v10; // ecx
  unsigned __int16 v11; // bp
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v12; // ecx
  unsigned __int16 v13; // cx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v14; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v15; // ecx
  unsigned __int16 m_Right; // dx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v17; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v18; // ecx
  unsigned __int16 v19; // cx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v20; // eax
  int v21; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v23; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v24; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v25; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v26; // ecx
  unsigned __int16 v27; // cx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v28; // eax
  int v29; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v30; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v31; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( m_Parent == 0xFFFF )
        v7 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v12 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v13 == 0xFFFF )
        v14 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = &this->m_Elements.m_pMemory[v13];
      if ( v14->m_Left == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v15 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( m_Right == 0xFFFF )
          v17 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = &this->m_Elements.m_pMemory[m_Right];
        if ( v17->m_Tag == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( elem == 0xFFFF )
          v18 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = &this->m_Elements.m_pMemory[elem];
        v19 = v18->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v19 == 0xFFFF )
          v20 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v19];
        if ( v20->m_Right == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v22 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = &this->m_Elements.m_pMemory[v9];
          v9 = v22->m_Parent;
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v23 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v11 = v23->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v24 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = &this->m_Elements.m_pMemory[v11];
        m_Right = v24->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( m_Right == 0xFFFF )
          v25 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v25 = &this->m_Elements.m_pMemory[m_Right];
        if ( v25->m_Tag == 0 )
        {
LABEL_81:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_105;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( elem == 0xFFFF )
          v26 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = &this->m_Elements.m_pMemory[elem];
        v27 = v26->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v27 == 0xFFFF )
          v28 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = &this->m_Elements.m_pMemory[v27];
        if ( v28->m_Left == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v30 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = &this->m_Elements.m_pMemory[v9];
          v9 = v30->m_Parent;
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v31 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = &this->m_Elements.m_pMemory[v9];
          v11 = v31->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_105:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403E90
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int v6; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    v6 = parent;
    if ( isLeft )
      m_pMemory[v6].m_Left = i;
    else
      m_pMemory[v6].m_Right = i;
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404300
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(struct CUtlMap<char const __near *,int,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<char const *,int,unsigned short>::Node_t *insert)
{
  const CUtlMap<char const *,int,unsigned short>::Node_t *v2; // ebx
  unsigned __int16 v4; // di
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int v6; // ecx
  unsigned __int16 v8[2]; // [esp+Ch] [ebp-4h] BYREF

  v2 = insert;
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    parent: v8,
    leftchild: (bool *)&insert);
  v4 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v4,
    parent: v8[0],
    isLeft: (bool)insert);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  v6 = v4;
  if ( &m_pMemory[v6] != (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)-8 )
  {
    m_pMemory[v6].m_Data.key = v2->key;
    m_pMemory[v6].m_Data.elem = v2->elem;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00405A00
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::SetSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::SetSize(CUtlVector<char,CUtlMemory<char,int> > *this, int size)
{
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  signed int v5; // eax
  bool v6; // zf

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = (unsigned __int8 *)this->m_Memory.m_pMemory;
    v5 = this->m_Size - size;
    v6 = this->m_Size == size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v5 >= 0 && !v6 && size > 0 )
      memmove(dst: &m_pMemory[size], src: m_pMemory, count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004071E0
// Name: public: class CUtlMemory<struct UtlRBTreeNode_t<class IDmeOperator __near *,unsigned short>,unsigned short>::Iterator_t CUtlMemory<struct UtlRBTreeNode_t<class IDmeOperator __near *,unsigned short>,unsigned short>::Next(class CUtlMemory<struct UtlRBTreeNode_t<class IDmeOperator __near *,unsigned short>,unsigned short>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *__thiscall CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>::Next(
        CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *this,
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *result,
        const CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Iterator_t *it)
{
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *v3; // eax

  v3 = result;
  if ( (unsigned __int16)(it->index + 1) >= this->m_nAllocationCount )
    result->index = -1;
  else
    result->index = it->index + 1;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00407220
// Name: public: void CUtlMemory<class CUtlVector<class CAttributeNode __near *,class CUtlMemory<class CAttributeNode __near *,int>>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *this,
        int num)
{
  int m_nGrowSize; // edi
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // eax
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
        {
          v6 = (v5 + this->m_nAllocationCount) / 2;
          this->m_nAllocationCount = v6;
        }
        while ( v6 < v5 );
      }
      else
      {
        this->m_nAllocationCount = -1;
      }
    }
    v7 = 20 * this->m_nAllocationCount;
    if ( this->m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CDmElement *,int> *)_g_pMemAlloc->Realloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: this->m_pMemory,
                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CDmElement *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004076F0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // edi
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // eax
  IMemAlloc_vtbl *v7; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    this->m_nAllocationCount = m_nAllocationCount;
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
        {
          v6 = (v5 + this->m_nAllocationCount) / 2;
          this->m_nAllocationCount = v6;
        }
        while ( (unsigned __int16)v6 < v5 );
      }
      else
      {
        this->m_nAllocationCount = m_nAllocationCount - 1;
      }
    }
    v7 = _g_pMemAlloc->__vftable;
    if ( this->m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)((int (__stdcall *)(UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *, int))v7->Realloc_2)(a1: this->m_pMemory, a2: 52 * this->m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)((int (__stdcall *)(int))v7->Alloc_2)(a1: 52 * this->m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407BE0
// Name: public: int CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>::Find(enum DmElementHandle_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::Find(
        CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *this,
        const DmElementHandle_t *src)
{
  int m_Size; // edx
  int result; // eax
  DmElementHandle_t *i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407E10
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    v6 = m_Root;
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407F20
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_FirstFree; // cx
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *p_m_LastAlloc; // ebp
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // ebx
  unsigned __int16 *v8; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  int result; // eax
  int v11; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v12; // ecx
  CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Iterator_t v13; // [esp+6h] [ebp-2h] BYREF

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    p_m_LastAlloc = &this->m_LastAlloc;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else if ( (unsigned __int16)(p_m_LastAlloc->index + 1) >= m_nAllocationCount )
    {
      v5 = -1;
    }
    else
    {
      v5 = p_m_LastAlloc->index + 1;
    }
    v13.index = v5;
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( p_m_LastAlloc->index >= v7 )
      {
        v13.index = (v7 > 0) - 1;
        v8 = (unsigned __int16 *)&v13;
      }
      else
      {
        v8 = (unsigned __int16 *)CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>::Next(
                                   this: (CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *)&this->m_Elements,
                                   result: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *)&v13,
                                   it: (const CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Iterator_t *)&this->m_LastAlloc);
      }
      v6 = *v8;
      if ( *v8 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    p_m_LastAlloc->index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v11 = m_FirstFree;
    result = m_FirstFree;
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[v11].m_Right;
    this->m_pElements = v12;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408010
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int,class CUtlMap<char const __near *,class IDmElementFactory __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_484818 = -1;
    dword_48481C = -1;
    dword_484820 = 1;
  }
  if ( i == -1 )
    return dword_48481C;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00408060
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int,class CUtlMap<char const __near *,class IDmElementFactory __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::LeftChild(
        CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_484818 = -1;
    dword_48481C = -1;
    dword_484820 = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004080B0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int,class CUtlMap<char const __near *,class IDmElementFactory __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::RightChild(
        CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_484818 = -1;
    dword_48481C = -1;
    dword_484820 = 1;
  }
  if ( i == -1 )
    return dword_484818;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00408100
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int,class CUtlMap<char const __near *,class IDmElementFactory __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,IDmElementFactory *,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_484818 = -1;
        dword_48481C = -1;
        dword_484820 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_484818 = -1;
        dword_48481C = -1;
        dword_484820 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004081F0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int,class CUtlMap<char const __near *,class IDmElementFactory __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::NewNode(
        CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *v11; // edx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<CDmElementDictionary::AttributeInfo_t,int>::Grow(
        this: (CUtlMemory<CDmElementDictionary::AttributeInfo_t,int> *)&this->m_Elements,
        num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[result].m_Right;
    this->m_pElements = v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004082C0
// Name: public: int CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(int,int,enum DmElementHandle_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *this,
        int elem,
        int num,
        IDmeOperator *const *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  IDmeOperator **m_pMemory; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // ecx

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    memmove(dst: (unsigned __int8 *)&(&m_pMemory[elem])[num], src: (unsigned __int8 *)&m_pMemory[elem], count: 4 * v10);
  if ( pToInsert != nullptr )
  {
    v11 = 0;
    if ( num > 0 )
    {
      v12 = elem;
      do
        this->m_Memory.m_pMemory[v12++] = pToInsert[v11++];
      while ( v11 < num );
      return elem;
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x00408360
// Name: public: int CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>>::InsertMultipleBefore(int,int,struct CDataModel::ElementIdHandlePair_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>::InsertMultipleBefore(
        CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *this,
        int elem,
        int num,
        const CDataModel::ElementIdHandlePair_t *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDataModel::ElementIdHandlePair_t *m_pMemory; // ecx
  int v9; // ebp
  int v10; // eax
  int v11; // ecx
  int i; // edx
  CDataModel::ElementIdHandlePair_t *v13; // eax
  int v14; // ebp
  unsigned __int16 *p_m_nStrongHandleCount; // edi
  CDataModel::ElementIdHandlePair_t *v16; // esi
  DmAttributeList_t *v17; // edx
  bool v18; // zf

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DmIdPair_t,int>::Grow(
      (CUtlMemory<DmIdPair_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    memmove(dst: m_pMemory[num + elem].m_id.m_Value, src: m_pMemory[elem].m_id.m_Value, count: 32 * v10);
LABEL_8:
    if ( num > 0 )
    {
      v11 = elem;
      for ( i = num; i != 0; --i )
      {
        v13 = &this->m_Memory.m_pMemory[v11];
        if ( v13 != nullptr )
        {
          v13->m_ref.m_hElement = DMELEMENT_HANDLE_INVALID;
          v13->m_ref.m_nWeakHandleCount = 0;
          v13->m_ref.m_nStrongHandleCount = 0;
          v13->m_ref.m_attributes.m_hAttribute = DMATTRIBUTE_HANDLE_INVALID;
          v13->m_ref.m_attributes.m_pNext = nullptr;
        }
        ++v11;
      }
    }
  }
  if ( pToInsert != nullptr && num > 0 )
  {
    v14 = elem;
    p_m_nStrongHandleCount = &pToInsert->m_ref.m_nStrongHandleCount;
    do
    {
      v16 = &this->m_Memory.m_pMemory[v14];
      CopyUniqueId(src: (const UniqueId_t *)(p_m_nStrongHandleCount - 11), pDest: &v16->m_id);
      v16->m_ref.m_hElement = *(_DWORD *)(p_m_nStrongHandleCount - 3);
      v16->m_ref.m_nWeakHandleCount = *(p_m_nStrongHandleCount - 1);
      v16->m_ref.m_nStrongHandleCount = *p_m_nStrongHandleCount;
      v16->m_ref.m_attributes.m_hAttribute = *(_DWORD *)(p_m_nStrongHandleCount + 1);
      v17 = *(DmAttributeList_t **)(p_m_nStrongHandleCount + 3);
      p_m_nStrongHandleCount += 16;
      ++v14;
      v18 = num-- == 1;
      v16->m_ref.m_attributes.m_pNext = v17;
    }
    while ( !v18 );
    return elem;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x00408460
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Right; // bx
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Right = CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
              this,
              i: elem)->m_Right;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Right = CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                             this,
                                             i: m_Right)->m_Left;
  if ( CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Right)->m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Right)->m_Left].m_Parent = elem;
  if ( m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                                     this,
                                                     i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else
  {
    v5 = CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Left == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Right;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00408550
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Left; // di
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Left = CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
             this,
             i: elem)->m_Left;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Left = CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                            this,
                                            i: m_Left)->m_Right;
  if ( CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Left)->m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Left)->m_Right].m_Parent = elem;
  if ( m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                                    this,
                                                    i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Right == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00408650
// Name: public: bool CUtlRBTree<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int,class CUtlMap<char const __near *,class IDmElementFactory __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int> > *this,
        int i)
{
  int v3; // eax

  v3 = CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Parent(
         this,
         i);
  if ( (`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_484818 = -1;
    dword_48481C = -1;
    dword_484820 = 1;
  }
  if ( v3 == -1 )
    return `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[v3].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x004086C0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int,class CUtlMap<char const __near *,class IDmElementFactory __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v3; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *v5; // eax

  v3 = CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::RightChild(
         this,
         i: elem);
  if ( (`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_484818 = -1;
    dword_48481C = -1;
    dword_484820 = 1;
  }
  if ( v3 == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[v3];
  this->m_Elements.m_pMemory[elem].m_Right = v4->m_Left;
  if ( (`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_484818 = -1;
    dword_48481C = -1;
    dword_484820 = 1;
  }
  if ( v3 == -1 )
    v5 = (UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v5 = &this->m_Elements.m_pMemory[v3];
  if ( v5->m_Left != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::LeftChild(
                                 this,
                                 i: v3)].m_Parent = elem;
  if ( v3 != -1 )
    this->m_Elements.m_pMemory[v3].m_Parent = CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v3;
  }
  else if ( CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = v3;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = v3;
  }
  this->m_Elements.m_pMemory[v3].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = v3;
}

//------------------------------------------------------------------------------
// Address: 0x004087F0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int,class CUtlMap<char const __near *,class IDmElementFactory __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int> > *this,
        int elem)
{
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *v3; // eax
  int m_Left; // edi
  int v5; // eax

  if ( (`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_484818 = -1;
    dword_48481C = -1;
    dword_484820 = 1;
  }
  if ( elem == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[elem];
  m_Left = v3->m_Left;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::RightChild(
                                              this,
                                              i: v3->m_Left);
  if ( CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::RightChild(
         this,
         i: m_Left) != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::RightChild(
           this,
           i: v5) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Parent(
                                   this,
                                   i: elem)].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Parent(
                                   this,
                                   i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004093A0
// Name: public: CUtlVector<struct CDmElementDictionary::DeletionInfo_t,class CUtlMemory<struct CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<struct CDmElementDictionary::DeletionInfo_t,class CUtlMemory<struct CDmElementDictionary::DeletionInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409490
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t *search)
{
  unsigned __int16 m_Root; // bp
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00409590
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int v1; // ebx
  int result; // eax
  UtlRBTreeLinks_t<unsigned short> *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
      `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : &this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( v3->m_Left == 0xFFFF )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
      `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
    }
    if ( (_WORD)result == 0xFFFF )
      result = `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left;
    else
      result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409640
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
        CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  unsigned __int16 v2; // di
  int result; // eax
  int v5; // edx
  UtlRBTreeLinks_t<unsigned short> *v6; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v7; // eax
  int v8; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v9; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeLinks_t<unsigned short> *v11; // ecx

  v2 = i;
  if ( CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
         this,
         i)->m_Right == 0xFFFF )
  {
    v7 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(this, i);
    v8 = `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      result = v7->m_Parent;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v9 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v9 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v9->m_Parent;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v11 = m_Parent == 0xFFFF
          ? &`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : &this->m_Elements.m_pMemory[m_Parent];
      if ( v11->m_Right != v2 )
        break;
      v2 = result;
      if ( (_WORD)result == 0xFFFF )
        break;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v7 = &this->m_Elements.m_pMemory[(unsigned __int16)result];
    }
  }
  else
  {
    result = CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Right;
    v5 = `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v6 = (_WORD)result == 0xFFFF
         ? &`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : &this->m_Elements.m_pMemory[(unsigned __int16)result];
      if ( v6->m_Left == 0xFFFF )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( (_WORD)result == 0xFFFF )
        result = `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left;
      else
        result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004097F0
// Name: public: int CUtlVector<struct UniqueId_t,class CUtlMemory<struct UniqueId_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int>>::InsertBefore(
        CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  UniqueId_t *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<Quaternion,int>::Grow((CUtlMemory<CUtlBinaryBlock,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    memmove(dst: m_pMemory[elem + 1].m_Value, src: m_pMemory[elem].m_Value, count: 16 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00409850
// Name: public: int CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(int,enum DmElementHandle_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this,
        int elem,
        CUtlSymbolTable::StringPool_t **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  CUtlSymbolTable::StringPool_t **v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 4 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004098C0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int,class CUtlMap<char const __near *,class IDmElementFactory __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int>,int>>::Find(struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,IDmElementFactory *,int>::Node_t *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_484818 = -1;
        dword_48481C = -1;
        dword_484820 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_484818 = -1;
        dword_48481C = -1;
        dword_484820 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x004099B0
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int,class CUtlMap<char const __near *,class IDmElementFactory __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_484818 = -1;
      dword_48481C = -1;
      dword_484820 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_484818 = -1;
      dword_48481C = -1;
      dword_484820 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409A50
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int,class CUtlMap<char const __near *,class IDmElementFactory __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // esi
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int v7; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *v8; // ecx
  int m_Parent; // ecx
  int *v10; // ecx

  v2 = i;
  if ( CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::RightChild(
         this,
         i) == -1 )
  {
    result = CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Parent(
               this,
               i);
    v7 = `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_484818 = -1;
        dword_48481C = -1;
        dword_484820 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v8->m_Parent;
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_484818 = -1;
        dword_48481C = -1;
        dword_484820 = 1;
      }
      v10 = m_Parent == -1
          ? &`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v10[1] != v2 )
        break;
      v2 = result;
      if ( result == -1 )
        break;
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_484818 = -1;
        dword_48481C = -1;
        dword_484820 = 1;
      }
      result = this->m_Elements.m_pMemory[result].m_Parent;
    }
  }
  else
  {
    result = CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_484818 = -1;
        dword_48481C = -1;
        dword_484820 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_484818 = -1;
        dword_48481C = -1;
        dword_484820 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409C90
// Name: public: int CUtlVector<struct CUtlHandleTable<class CDmAttribute,20>::EntryType_t,class CUtlMemory<struct CUtlHandleTable<class CDmAttribute,20>::EntryType_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlHandleTable<CDmAttribute,20>::EntryType_t,CUtlMemory<CUtlHandleTable<CDmAttribute,20>::EntryType_t,int>>::InsertBefore(
        CUtlVector<CUtlHandleTable<FileElementSet_t,20>::EntryType_t,CUtlMemory<CUtlHandleTable<FileElementSet_t,20>::EntryType_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlHandleTable<FileElementSet_t,20>::EntryType_t *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  CUtlHandleTable<FileElementSet_t,20>::EntryType_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,20>::EntryType_t,int>::Grow(
      (CUtlMemory<Vector2D,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 8 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    *(_DWORD *)v8 = 0;
    v8->m_pData = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00409D00
// Name: public: int CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>>::InsertBefore(int,struct CDataModel::ElementIdHandlePair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>::InsertBefore(
        CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *this,
        int elem,
        const CDataModel::ElementIdHandlePair_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDataModel::ElementIdHandlePair_t *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  CDataModel::ElementIdHandlePair_t *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DmIdPair_t,int>::Grow(
      (CUtlMemory<DmIdPair_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    memmove(dst: m_pMemory[elem + 1].m_id.m_Value, src: m_pMemory[elem].m_id.m_Value, count: 32 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
  {
    v9->m_ref = src->m_ref;
    CopyUniqueId(src: &src->m_id, pDest: &v9->m_id);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00409D90
// Name: public: void CUtlRBTree<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  int m_nAllocationCount; // eax
  unsigned __int16 v4; // di
  int v5; // eax
  unsigned __int16 i; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    v4 = (m_nAllocationCount > 0) - 1;
    i = v4;
    if ( m_nAllocationCount > 0 )
    {
      do
      {
        if ( v4 < m_nAllocationCount
          && v4 <= index
          && CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Left != v4 )
        {
          v5 = v4;
          this->m_Elements.m_pMemory[v5].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v5].m_Left = v4;
          this->m_FirstFree = v4;
        }
        index = this->m_LastAlloc.index;
        if ( v4 == index )
          break;
        m_nAllocationCount = this->m_Elements.m_nAllocationCount;
        ++v4;
        if ( (unsigned __int16)(i + 1) >= m_nAllocationCount )
          v4 = -1;
        i = v4;
      }
      while ( v4 != 0xFFFF );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409E50
// Name: public: void CUtlRBTree<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int,class CUtlMap<char const __near *,class IDmElementFactory __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int> > *this)
{
  int index; // eax
  int v3; // esi
  int v4; // eax

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 >= 0
          && v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::LeftChild(
               this,
               i: v3) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        if ( ++v3 < 0 || v3 >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
      }
      while ( v3 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409EE0
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::InsertBefore(CUtlVector<int,CUtlMemory<int,int> > *this, int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 4 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00409F40
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v8; // ecx
  unsigned __int16 v9; // di
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v10; // ecx
  unsigned __int16 v11; // bp
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v12; // ecx
  unsigned __int16 v13; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v14; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v15; // ecx
  unsigned __int16 m_Right; // dx
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v17; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v18; // ecx
  unsigned __int16 v19; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v20; // eax
  int v21; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v22; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v23; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v24; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v25; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v26; // ecx
  unsigned __int16 v27; // cx
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v28; // eax
  int v29; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v30; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v31; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v5 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( m_Parent == 0xFFFF )
        v7 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v8 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v10 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v12 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v13 == 0xFFFF )
        v14 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = &this->m_Elements.m_pMemory[v13];
      if ( v14->m_Left == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v15 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( m_Right == 0xFFFF )
          v17 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = &this->m_Elements.m_pMemory[m_Right];
        if ( v17->m_Tag == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( elem == 0xFFFF )
          v18 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = &this->m_Elements.m_pMemory[elem];
        v19 = v18->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v19 == 0xFFFF )
          v20 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v19];
        if ( v20->m_Right == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v22 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = &this->m_Elements.m_pMemory[v9];
          v9 = v22->m_Parent;
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v23 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v11 = v23->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v24 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = &this->m_Elements.m_pMemory[v11];
        m_Right = v24->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( m_Right == 0xFFFF )
          v25 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v25 = &this->m_Elements.m_pMemory[m_Right];
        if ( v25->m_Tag == 0 )
        {
LABEL_81:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_105;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( elem == 0xFFFF )
          v26 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = &this->m_Elements.m_pMemory[elem];
        v27 = v26->m_Parent;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v27 == 0xFFFF )
          v28 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = &this->m_Elements.m_pMemory[v27];
        if ( v28->m_Left == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v30 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = &this->m_Elements.m_pMemory[v9];
          v9 = v30->m_Parent;
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v9 == 0xFFFF )
            v31 = (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = &this->m_Elements.m_pMemory[v9];
          v11 = v31->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_105:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040A520
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int,class CUtlMap<char const __near *,class IDmElementFactory __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // esi
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  int *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *v10; // ecx
  int v11; // ebp
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *v15; // ecx
  int m_Right; // ecx
  int *v17; // edx
  int v18; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *v19; // ecx
  int v20; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *v21; // eax
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *v23; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *v24; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *v25; // ecx
  int m_Left; // ecx
  int *v27; // eax
  int v28; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *v29; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *v30; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_484818 = -1;
        dword_48481C = -1;
        dword_484820 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_484818 = -1;
        dword_48481C = -1;
        dword_484820 = 1;
      }
      v7 = m_Parent == -1
         ? &`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v7[3] != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_484818 = -1;
        dword_48481C = -1;
        dword_484820 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_484818 = -1;
        dword_48481C = -1;
        dword_484820 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_484818 = -1;
        dword_48481C = -1;
        dword_484820 = 1;
      }
      if ( v9 == -1 )
        v12 = (UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_484818 = -1;
        dword_48481C = -1;
        dword_484820 = 1;
      }
      v14 = v13 == -1
          ? &`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v13];
      if ( *v14 == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_484818 = -1;
          dword_48481C = -1;
          dword_484820 = 1;
        }
        if ( v11 == -1 )
          v15 = (UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_484818 = -1;
          dword_48481C = -1;
          dword_484820 = 1;
        }
        v17 = m_Right == -1
            ? &`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[m_Right];
        if ( v17[3] != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_484818 = -1;
            dword_48481C = -1;
            dword_484820 = 1;
          }
          v18 = elem;
          if ( elem == -1 )
          {
            v19 = (UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          }
          else
          {
            v19 = &this->m_Elements.m_pMemory[elem];
            v18 = elem;
          }
          v20 = v19->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_484818 = -1;
            dword_48481C = -1;
            dword_484820 = 1;
          }
          if ( v20 == -1 )
            v21 = (UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v21 = &this->m_Elements.m_pMemory[v20];
          if ( v21->m_Right == v18 )
          {
            elem = v9;
            CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::RotateLeft(
              this,
              elem: v9);
            v22 = `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
            if ( (`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                & 1) == 0 )
            {
              v22 = `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                  | 1;
              `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
              `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_484818 = -1;
              dword_48481C = -1;
              dword_484820 = 1;
            }
            if ( v9 == -1 )
              v23 = (UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v23 = &this->m_Elements.m_pMemory[v9];
            v9 = v23->m_Parent;
            if ( (v22 & 1) == 0 )
            {
              `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
              `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_484818 = -1;
              dword_48481C = -1;
              dword_484820 = 1;
            }
            if ( v9 == -1 )
              v24 = (UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v24 = &this->m_Elements.m_pMemory[v9];
            v11 = v24->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_484818 = -1;
          dword_48481C = -1;
          dword_484820 = 1;
        }
        if ( v11 == -1 )
          v25 = (UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v25 = &this->m_Elements.m_pMemory[v11];
        m_Left = v25->m_Left;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_484818 = -1;
          dword_48481C = -1;
          dword_484820 = 1;
        }
        v27 = m_Left == -1
            ? &`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[m_Left];
        if ( v27[3] != 0 )
        {
          if ( CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::IsLeftChild(
                 this,
                 i: elem) )
          {
            elem = v9;
            CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::RotateRight(
              this,
              elem: v9);
            v28 = `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
            if ( (`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                & 1) == 0 )
            {
              v28 = `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                  | 1;
              `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
              `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_484818 = -1;
              dword_48481C = -1;
              dword_484820 = 1;
            }
            if ( v9 == -1 )
              v29 = (UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v29 = &this->m_Elements.m_pMemory[v9];
            v9 = v29->m_Parent;
            if ( (v28 & 1) == 0 )
            {
              `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v28 | 1;
              `CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_484818 = -1;
              dword_48481C = -1;
              dword_484820 = 1;
            }
            if ( v9 == -1 )
              v30 = (UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v30 = &this->m_Elements.m_pMemory[v9];
            v11 = v30->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040B310
// Name: public: CUtlRBTree<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int,class CUtlMap<char const __near *,class IDmElementFactory __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int>,int>>::~CUtlRBTree<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int,class CUtlMap<char const __near *,class IDmElementFactory __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>(
        CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int> > *this)
{
  CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B370
// Name: protected: void CUtlRBTree<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int v6; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    v6 = parent;
    if ( isLeft )
      m_pMemory[v6].m_Left = i;
    else
      m_pMemory[v6].m_Right = i;
    CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B3E0
// Name: protected: void CUtlRBTree<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int,class CUtlMap<char const __near *,class IDmElementFactory __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B800
// Name: public: int CUtlDict<class IDmElementFactory __near *,int>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<IDmElementFactory *,int>::Find(CUtlDict<IDmElementFactory *,int> *this, const char *pName)
{
  CUtlMap<char const *,IDmElementFactory *,int>::Node_t search; // [esp+0h] [ebp-8h] BYREF

  if ( pName == nullptr )
    return -1;
  search.key = pName;
  return CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Find(
           this: &this->m_Elements.m_Tree,
           &search);
}

//------------------------------------------------------------------------------
// Address: 0x0040B910
// Name: public: void CUtlDict<class IDmElementFactory __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<IDmElementFactory *,int>::RemoveAll(CUtlDict<IDmElementFactory *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x0040B960
// Name: public: class CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>> __near & CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>>::operator=(class CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *__thiscall CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>::operator=(
        CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *this,
        const CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *other)
{
  int m_Size; // esi
  int v3; // ebx
  CDataModel::ElementIdHandlePair_t *v5; // edi
  CDataModel::ElementIdHandlePair_t *v6; // esi
  bool v7; // zf
  int v9; // [esp+Ch] [ebp-4h]

  m_Size = other->m_Size;
  v3 = 0;
  this->m_Size = 0;
  CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>::InsertMultipleBefore(
    this,
    elem: 0,
    num: m_Size,
    pToInsert: nullptr);
  if ( m_Size > 0 )
  {
    v9 = m_Size;
    do
    {
      v5 = &this->m_Memory.m_pMemory[v3];
      v6 = &other->m_Memory.m_pMemory[v3];
      CopyUniqueId(src: &v6->m_id, pDest: &v5->m_id);
      v5->m_ref.m_hElement = v6->m_ref.m_hElement;
      v5->m_ref.m_nWeakHandleCount = v6->m_ref.m_nWeakHandleCount;
      v5->m_ref.m_nStrongHandleCount = v6->m_ref.m_nStrongHandleCount;
      v5->m_ref.m_attributes.m_hAttribute = v6->m_ref.m_attributes.m_hAttribute;
      ++v3;
      v7 = v9-- == 1;
      v5->m_ref.m_attributes.m_pNext = v6->m_ref.m_attributes.m_pNext;
    }
    while ( !v7 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040BE20
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,class CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(struct CUtlMap<unsigned short,struct DmMemoryInfo_t,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t *insert)
{
  const CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t *v2; // edi
  unsigned __int16 v4; // bx
  UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int v6; // ecx
  unsigned __int16 v8[2]; // [esp+Ch] [ebp-4h] BYREF

  v2 = insert;
  CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    parent: v8,
    leftchild: (bool *)&insert);
  v4 = CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this);
  CUtlRBTree<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v4,
    parent: v8[0],
    isLeft: (bool)insert);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  v6 = v4;
  if ( &m_pMemory[v6] != (UtlRBTreeNode_t<CUtlMap<unsigned short,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)-8 )
  {
    m_pMemory[v6].m_Data.key = v2->key;
    qmemcpy(&m_pMemory[v6].m_Data.elem, &v2->elem, sizeof(m_pMemory[v6].m_Data.elem));
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0040BF50
// Name: public: int CUtlRBTree<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int,class CUtlMap<char const __near *,class IDmElementFactory __near *,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t,int>,int>>::Insert(struct CUtlMap<char const __near *,class IDmElementFactory __near *,int>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::Insert(
        CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int> > *this,
        const CUtlMap<char const *,IDmElementFactory *,int>::Node_t *insert)
{
  const CUtlMap<char const *,IDmElementFactory *,int>::Node_t *v2; // ebx
  int v4; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *m_pMemory; // edx
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v2 = insert;
  CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this,
    insert,
    parent: &v7,
    leftchild: (bool *)&insert);
  v4 = CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::NewNode(this);
  CUtlRBTree<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int,CUtlMap<char const *,IDmElementFactory *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int>,int>>::LinkToParent(
    this,
    i: v4,
    parent: v7,
    isLeft: (bool)insert);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlMap<char const *,IDmElementFactory *,int>::Node_t,int> *)-16 )
  {
    m_pMemory[v4].m_Data.key = v2->key;
    m_pMemory[v4].m_Data.elem = v2->elem;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0040BFB0
// Name: public: int CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>>::InsertMultipleBefore(int,int,class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>> const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> >,CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> >,int> > *this,
        int elem,
        int num,
        const CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *m_pMemory; // ecx
  int v10; // edi
  int v11; // eax
  int v12; // ecx
  int i; // edx
  CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *v14; // eax
  int v15; // edi
  const CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *v16; // ebx
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v17; // esi
  int v18; // edi
  int v19; // eax
  unsigned __int8 *v20; // ecx
  int v21; // eax
  bool v22; // zf
  int j; // eax
  int numa; // [esp+14h] [ebp+8h]
  const CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *pToInserta; // [esp+18h] [ebp+Ch]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = elem;
  v11 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v11 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + num], src: (unsigned __int8 *)&m_pMemory[elem], count: 20 * v11);
LABEL_8:
    if ( num > 0 )
    {
      v12 = elem;
      for ( i = num; i != 0; --i )
      {
        v14 = &this->m_Memory.m_pMemory[v12];
        if ( v14 != nullptr )
        {
          v14->m_Memory.m_pMemory = nullptr;
          v14->m_Memory.m_nAllocationCount = 0;
          v14->m_Memory.m_nGrowSize = 0;
          v14->m_Size = 0;
          v14->m_pElements = nullptr;
        }
        ++v12;
      }
    }
  }
  if ( pToInsert != nullptr && num > 0 )
  {
    v15 = 20 * elem;
    numa = 20 * elem;
    v16 = pToInsert;
    pToInserta = (const CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *)num;
    do
    {
      v17 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)((char *)this->m_Memory.m_pMemory + v15);
      v18 = v16->m_Size;
      v17[1].m_pMemory = nullptr;
      if ( v18 != 0 )
      {
        v19 = v17->m_nAllocationCount;
        if ( v18 > v19 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v17, num: v18 - v19);
        v17[1].m_pMemory = (CUtlSymbolTable::StringPool_t **)((char *)v17[1].m_pMemory + v18);
        v20 = (unsigned __int8 *)v17->m_pMemory;
        v21 = (int)v17[1].m_pMemory - v18;
        v22 = v17[1].m_pMemory == (CUtlSymbolTable::StringPool_t **)v18;
        v17[1].m_nAllocationCount = (int)v17->m_pMemory;
        if ( v21 >= 0 && !v22 && v18 > 0 )
          memmove(dst: &v20[4 * v18], src: v20, count: 4 * v21);
      }
      for ( j = 0; j < v18; ++j )
        v17->m_pMemory[j] = (CUtlSymbolTable::StringPool_t *)v16->m_Memory.m_pMemory[j];
      v15 = numa + 20;
      ++v16;
      v22 = pToInserta == (const CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *)1;
      pToInserta = (const CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int> > *)((char *)pToInserta - 1);
      numa += 20;
    }
    while ( !v22 );
    return elem;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x0040C100
// Name: public: int CUtlVector<class CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>>,class CUtlMemory<class CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>>,int>>::InsertMultipleBefore(int,int,class CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>> const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>,CUtlMemory<CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> >,CUtlMemory<CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> >,int> > *this,
        int elem,
        int num,
        const CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *pToInsert)
{
  int v4; // ebx
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *m_pMemory; // ecx
  int v10; // edi
  int v11; // eax
  int v12; // ecx
  int i; // edx
  CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *v14; // eax
  int v15; // edi
  const CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *v16; // ebp

  v4 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = elem;
  v11 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v11 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + num], src: (unsigned __int8 *)&m_pMemory[elem], count: 20 * v11);
LABEL_8:
    if ( num > 0 )
    {
      v12 = elem;
      for ( i = num; i != 0; --i )
      {
        v14 = &this->m_Memory.m_pMemory[v12];
        if ( v14 != nullptr )
        {
          v14->m_Memory.m_pMemory = nullptr;
          v14->m_Memory.m_nAllocationCount = 0;
          v14->m_Memory.m_nGrowSize = 0;
          v14->m_Size = 0;
          v14->m_pElements = nullptr;
        }
        ++v12;
      }
    }
  }
  if ( pToInsert != nullptr && num > 0 )
  {
    v15 = elem;
    v16 = pToInsert;
    do
    {
      CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>::operator=(
        this: &this->m_Memory.m_pMemory[v15++],
        other: v16++);
      --v4;
    }
    while ( v4 != 0 );
    return elem;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x0040E5E0
// Name: public: class CDmElement __near * CDmaElementArrayConstBase<class CDmElement,class CDmaArrayBase<enum DmElementHandle_t,class CDmaDataExternal<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>>>>::operator[](int)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmaElementArrayConstBase<CDmElement,CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>>::operator[](
        CDmaElementArrayConstBase<CDmElement,CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > > *this,
        int i)
{
  CDmElement *v2; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_pStorage->m_Memory.m_pMemory[i]);
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmElement::m_classType.m_Id) )
    return v2;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0040ED30
// Name: private: void CDmAttribute::CopyData<class QAngle>(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAttribute::CopyData<QAngle>(CDmAttribute *this, const QAngle *value)
{
  _DWORD *m_pData; // eax
  Quaternion qValue; // [esp+0h] [ebp-14h] BYREF
  int v5; // [esp+10h] [ebp-4h]

  if ( (this->m_nFlags & 0x1F) == 0xC )
  {
    *(QAngle *)this->m_pData = *value;
  }
  else if ( (this->m_nFlags & 0x1F) == 0xD )
  {
    AngleQuaternion(angles: value, outQuat: (Quaternion *)&qValue.y);
    m_pData = this->m_pData;
    *m_pData = LODWORD(qValue.y);
    m_pData[1] = LODWORD(qValue.z);
    m_pData[2] = LODWORD(qValue.w);
    m_pData[3] = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040EDA0
// Name: private: void CDmAttribute::CopyData<class Quaternion>(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAttribute::CopyData<Quaternion>(CDmAttribute *this, const Quaternion *value)
{
  float *m_pData; // esi
  QAngle aValue; // [esp+0h] [ebp-10h] BYREF
  float v5; // [esp+Ch] [ebp-4h]

  if ( (this->m_nFlags & 0x1F) == 0xC )
  {
    QuaternionAngles(q: value, angles: (QAngle *)&aValue.y);
    m_pData = (float *)this->m_pData;
    *m_pData = aValue.y;
    m_pData[1] = aValue.z;
    m_pData[2] = v5;
  }
  else if ( (this->m_nFlags & 0x1F) == 0xD )
  {
    *(Quaternion *)this->m_pData = *value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FEE0
// Name: public: struct UniqueId_t const __near & CDmAttribute::GetValue<struct UniqueId_t>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<UniqueId_t> *__thiscall CDmAttribute::GetValue<UniqueId_t>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<UniqueId_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<UniqueId_t>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<UniqueId_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    InvalidateUniqueId(pDest: &`CDmAttribute::GetValue<UniqueId_t>'::`2'::defaultVal.m_Storage);
  }
  if ( (this->m_nFlags & 0x1F) == 7 )
    return (CDmaVar<UniqueId_t> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<UniqueId_t>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0040FFC0
// Name: public: void CUtlMemory<class IDmFormatUpdater __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<IDmFormatUpdater *,int>::Grow(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this,
        int num)
{
  int m_nGrowSize; // edi
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // eax

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
        {
          v6 = (v5 + this->m_nAllocationCount) / 2;
          this->m_nAllocationCount = v6;
        }
        while ( v6 < v5 );
      }
      else
      {
        this->m_nAllocationCount = -1;
      }
    }
    if ( this->m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: this->m_pMemory,
                                                            a3: 4 * this->m_nAllocationCount);
    else
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Alloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: 4 * this->m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410120
// Name: public: void CUtlMemory<class VMatrix,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<VMatrix,int>::Grow(CUtlMemory<VMatrix,int> *this, int num)
{
  int m_nGrowSize; // edi
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // eax

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
        {
          v6 = (v5 + this->m_nAllocationCount) / 2;
          this->m_nAllocationCount = v6;
        }
        while ( v6 < v5 );
      }
      else
      {
        this->m_nAllocationCount = -1;
      }
    }
    if ( this->m_pMemory != nullptr )
      this->m_pMemory = (VMatrix *)_g_pMemAlloc->Realloc_2(
                                     this: _g_pMemAlloc,
                                     a2: this->m_pMemory,
                                     a3: this->m_nAllocationCount << 6);
    else
      this->m_pMemory = (VMatrix *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nAllocationCount << 6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004101D0
// Name: public: void CUtlMemory<class Quaternion,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<Quaternion,int>::Grow(CUtlMemory<CUtlBinaryBlock,int> *this, int num)
{
  int m_nGrowSize; // edi
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // eax

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
        {
          v6 = (v5 + this->m_nAllocationCount) / 2;
          this->m_nAllocationCount = v6;
        }
        while ( v6 < v5 );
      }
      else
      {
        this->m_nAllocationCount = -1;
      }
    }
    if ( this->m_pMemory != nullptr )
      this->m_pMemory = (CUtlBinaryBlock *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: this->m_pMemory,
                                             a3: 16 * this->m_nAllocationCount);
    else
      this->m_pMemory = (CUtlBinaryBlock *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * this->m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411360
// Name: public: void CUtlVector<float,class CUtlMemory<float,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(
        CUtlVector<Color,CUtlMemory<Color,int> > *this,
        int num)
{
  Color *m_pMemory; // eax
  unsigned int v4; // edx
  Color *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
      this->m_pElements = m_pMemory;
    }
    else
    {
      this->m_Memory.m_nAllocationCount = num;
      v4 = 4 * num;
      if ( m_pMemory != nullptr )
        v5 = (Color *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      else
        v5 = (Color *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
      this->m_Memory.m_pMemory = v5;
      this->m_pElements = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004113D0
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCapacity(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int num)
{
  bool *m_pMemory; // eax
  bool v4; // zf
  bool *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = this->m_Memory.m_pMemory;
    v4 = this->m_Memory.m_pMemory == nullptr;
    this->m_Memory.m_nAllocationCount = num;
    if ( v4 )
      v5 = (bool *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
    else
      v5 = (bool *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411430
// Name: public: void CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::EnsureCapacity(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int num)
{
  Vector2D *m_pMemory; // eax
  unsigned int v4; // edx
  Vector2D *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
      this->m_pElements = m_pMemory;
    }
    else
    {
      this->m_Memory.m_nAllocationCount = num;
      v4 = 8 * num;
      if ( m_pMemory != nullptr )
        v5 = (Vector2D *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      else
        v5 = (Vector2D *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
      this->m_Memory.m_pMemory = v5;
      this->m_pElements = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004114A0
// Name: public: void CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<QAngle,CUtlMemory<QAngle,int>>::RemoveMultiple(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int elem,
        int num)
{
  if ( this->m_Size - elem - num > 0 && num > 0 )
    memmove(
      dst: (unsigned __int8 *)&this->m_Memory.m_pMemory[elem],
      src: (unsigned __int8 *)&this->m_Memory.m_pMemory[elem + num],
      count: 12 * (this->m_Size - elem - num));
  this->m_Size -= num;
}

//------------------------------------------------------------------------------
// Address: 0x004114F0
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int num)
{
  QAngle *m_pMemory; // edx
  unsigned int v4; // eax
  QAngle *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
      this->m_pElements = m_pMemory;
    }
    else
    {
      this->m_Memory.m_nAllocationCount = num;
      v4 = 12 * num;
      if ( m_pMemory != nullptr )
        v5 = (QAngle *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      else
        v5 = (QAngle *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
      this->m_Memory.m_pMemory = v5;
      this->m_pElements = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411550
// Name: public: void CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::EnsureCapacity(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int num)
{
  VMatrix *m_pMemory; // edx
  unsigned int v4; // eax
  VMatrix *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = num << 6;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (VMatrix *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (VMatrix *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004115B0
// Name: public: void CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::EnsureCapacity(
        CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int> > *this,
        int num)
{
  UniqueId_t *m_pMemory; // edx
  unsigned int v4; // eax
  UniqueId_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 16 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (UniqueId_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (UniqueId_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004117B0
// Name: public: class QAngle const __near & CDmAttribute::GetValue<class QAngle>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<QAngle> *__thiscall CDmAttribute::GetValue<QAngle>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<QAngle>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<QAngle>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  if ( (this->m_nFlags & 0x1F) == 0xC )
    return (CDmaVar<QAngle> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<QAngle>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00411800
// Name: private: bool CDmAttribute::ShouldModify<class QAngle>(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::ShouldModify<QAngle>(CDmAttribute *this, const QAngle *value)
{
  int v3; // eax
  CDmaVar<QAngle> *v5; // eax

  v3 = this->m_nFlags & 0x1F;
  if ( v3 == 12 )
  {
    v5 = CDmAttribute::GetValue<QAngle>(this);
    if ( v5->m_Storage.x == value->x && v5->m_Storage.y == value->y && v5->m_Storage.z == value->z )
      return false;
  }
  else if ( v3 != 13 )
  {
    return false;
  }
  return CDmAttribute::MarkDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x00411860
// Name: public: class Quaternion const __near & CDmAttribute::GetValue<class Quaternion>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmAttribute::GetValue<Quaternion>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Quaternion>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Quaternion>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.z = 0.0;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.w = 1.0;
  }
  if ( (this->m_nFlags & 0x1F) == 0xD )
    return (CDmaVar<Quaternion> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004118B0
// Name: public: class VMatrix const __near & CDmAttribute::GetValue<class VMatrix>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<VMatrix> *__thiscall CDmAttribute::GetValue<VMatrix>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<VMatrix>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<VMatrix>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal.m_pAttribute = nullptr;
    MatrixSetIdentity(dst: &`CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal.m_Storage);
  }
  if ( (this->m_nFlags & 0x1F) == 0xE )
    return (CDmaVar<VMatrix> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00411900
// Name: public: int CUtlVector<class Color,class CUtlMemory<class Color,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Color,CUtlMemory<Color,int>>::InsertBefore(
        CUtlVector<Color,CUtlMemory<Color,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Color *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  Color *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 4 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = 0;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00411970
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  CUtlString *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<Quaternion,int>::Grow((CUtlMemory<CUtlBinaryBlock,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 16 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlString::CUtlString(this: v8);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004119E0
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  CUtlBinaryBlock *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<Quaternion,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 16 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: v8, growSize: 0, initSize: 0);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00417930
// Name: public: int CUtlVector<float,class CUtlMemory<float,int>>::InsertBefore(int,float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<float,CUtlMemory<float,int>>::InsertBefore(
        CUtlVector<float,CUtlMemory<float,int> > *this,
        int elem,
        float *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  float *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  float *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 4 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004179A0
// Name: public: int CUtlVector<float,class CUtlMemory<float,int>>::InsertMultipleBefore(int,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<float,CUtlMemory<float,int>>::InsertMultipleBefore(
        CUtlVector<float,CUtlMemory<float,int> > *this,
        int elem,
        int num,
        const float *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  float *m_pMemory; // ecx
  int v9; // edi
  int v10; // eax
  const float *v11; // ecx
  int v12; // edx
  int v13; // eax
  float *v14; // ecx
  unsigned int v15; // edi
  double v16; // st7
  int v17; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + num], src: (unsigned __int8 *)&m_pMemory[elem], count: 4 * v10);
  v11 = pToInsert;
  if ( pToInsert != nullptr )
  {
    v12 = 0;
    if ( num >= 4 )
    {
      v13 = elem;
      v14 = (float *)(pToInsert + 2);
      v15 = ((unsigned int)(num - 4) >> 2) + 1;
      v12 = 4 * v15;
      do
      {
        this->m_Memory.m_pMemory[v13] = *(v14 - 2);
        v13 += 4;
        this->m_Memory.m_pMemory[v13 - 3] = *(v14 - 1);
        v16 = *v14;
        v14 += 4;
        --v15;
        this->m_Memory.m_pMemory[v13 - 2] = v16;
        this->m_Memory.m_pMemory[v13 - 1] = *(v14 - 3);
      }
      while ( v15 != 0 );
      v11 = pToInsert;
      v9 = elem;
    }
    if ( v12 < num )
    {
      v17 = v12 + v9;
      do
        this->m_Memory.m_pMemory[v17++] = v11[v12++];
      while ( v12 < num );
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x00417A90
// Name: public: int CUtlVector<bool,class CUtlMemory<bool,int>>::InsertBefore(int,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::InsertBefore(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int elem,
        bool *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  bool *m_pMemory; // ecx
  signed int v7; // eax
  bool v8; // zf
  bool *v9; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00417AF0
// Name: public: int CUtlVector<bool,class CUtlMemory<bool,int>>::InsertMultipleBefore(int,int,bool const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::InsertMultipleBefore(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int elem,
        int num,
        const bool *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  bool *m_pMemory; // ecx
  signed int v9; // eax
  int i; // eax
  bool v11; // dl
  bool *v12; // ecx

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + num], src: (unsigned __int8 *)&m_pMemory[elem], count: v9);
  if ( pToInsert != nullptr )
  {
    for ( i = 0; i < num; v12[elem] = v11 )
    {
      v11 = pToInsert[i];
      v12 = &this->m_Memory.m_pMemory[i++];
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00417B80
// Name: public: int CUtlVector<class Color,class CUtlMemory<class Color,int>>::InsertMultipleBefore(int,int,class Color const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Color,CUtlMemory<Color,int>>::InsertMultipleBefore(
        CUtlVector<Color,CUtlMemory<Color,int> > *this,
        int elem,
        int num,
        const Color *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Color *m_pMemory; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // ecx
  int i; // edx
  Color *v13; // eax
  int v14; // eax
  int v15; // ecx

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + num], src: (unsigned __int8 *)&m_pMemory[elem], count: 4 * v10);
LABEL_8:
    if ( num > 0 )
    {
      v11 = elem;
      for ( i = num; i != 0; --i )
      {
        v13 = &this->m_Memory.m_pMemory[v11];
        if ( v13 != nullptr )
          *v13 = 0;
        ++v11;
      }
    }
  }
  if ( pToInsert != nullptr )
  {
    v14 = 0;
    if ( num > 0 )
    {
      v15 = elem;
      do
        this->m_Memory.m_pMemory[v15++] = pToInsert[v14++];
      while ( v14 < num );
      return elem;
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x00417C40
// Name: public: int CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::InsertBefore(int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int elem,
        const Vector2D *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector2D *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  Vector2D *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,20>::EntryType_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 8 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00417CB0
// Name: public: int CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::InsertMultipleBefore(int,int,class Vector2D const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int elem,
        int num,
        const Vector2D *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector2D *m_pMemory; // ecx
  int v9; // ebx
  int v10; // eax
  const Vector2D *v11; // edx
  int v12; // edi
  int v13; // ecx
  unsigned int v14; // ebx
  float *p_y; // eax
  Vector2D *v16; // edx
  double v17; // st7
  Vector2D *v18; // edx
  Vector2D *v19; // edx
  Vector2D *v20; // edx
  int v21; // ecx
  Vector2D *v22; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,20>::EntryType_t,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + num], src: (unsigned __int8 *)&m_pMemory[elem], count: 8 * v10);
  v11 = pToInsert;
  if ( pToInsert != nullptr )
  {
    v12 = 0;
    if ( num >= 4 )
    {
      v13 = elem;
      v14 = ((unsigned int)(num - 4) >> 2) + 1;
      p_y = &pToInsert[2].y;
      v12 = 4 * v14;
      do
      {
        v16 = this->m_Memory.m_pMemory;
        v16[v13].x = *(p_y - 5);
        v17 = *(p_y - 4);
        p_y += 8;
        v16[v13].y = v17;
        v18 = &this->m_Memory.m_pMemory[v13 + 1];
        v18->x = *(p_y - 11);
        v18->y = *(p_y - 10);
        v19 = &this->m_Memory.m_pMemory[v13 + 2];
        v19->x = *(p_y - 9);
        v19->y = *(p_y - 8);
        v20 = &this->m_Memory.m_pMemory[v13 + 3];
        v20->x = *(p_y - 7);
        v13 += 4;
        --v14;
        v20->y = *(p_y - 6);
      }
      while ( v14 != 0 );
      v11 = pToInsert;
      v9 = elem;
    }
    if ( v12 < num )
    {
      v21 = v12 + v9;
      do
      {
        v22 = &this->m_Memory.m_pMemory[v21];
        v22->x = v11[v12++].x;
        ++v21;
        v22->y = v11[v12 - 1].y;
      }
      while ( v12 < num );
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x00417DD0
// Name: public: int CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::InsertBefore(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int elem,
        const QAngle *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  QAngle *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  QAngle *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 12 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00417E50
// Name: public: int CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::InsertBefore(int,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertBefore(
        CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *this,
        int elem,
        const Vector4D *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector4D *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  Vector4D *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<Quaternion,int>::Grow((CUtlMemory<CUtlBinaryBlock,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 16 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00417ED0
// Name: public: int CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::InsertMultipleBefore(int,int,class Vector4D const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertMultipleBefore(
        CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *this,
        int elem,
        int num,
        const Vector4D *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector4D *m_pMemory; // ecx
  int v9; // edi
  int v10; // eax
  const Vector4D *v11; // eax
  int v12; // ebp
  int v13; // edx
  float *p_z; // eax
  unsigned int v15; // edi
  Vector4D *v16; // ecx
  float *p_x; // ecx
  double v18; // st7
  Vector4D *v19; // ecx
  Vector4D *v20; // ecx
  Vector4D *v21; // ecx
  int v22; // edx
  int v23; // ecx
  int v24; // ebx
  Vector4D *v25; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<Quaternion,int>::Grow((CUtlMemory<CUtlBinaryBlock,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + num], src: (unsigned __int8 *)&m_pMemory[elem], count: 16 * v10);
  v11 = pToInsert;
  if ( pToInsert != nullptr )
  {
    v12 = 0;
    if ( num >= 4 )
    {
      v13 = elem;
      p_z = &pToInsert[1].z;
      v15 = ((unsigned int)(num - 4) >> 2) + 1;
      v12 = 4 * v15;
      do
      {
        v16 = this->m_Memory.m_pMemory;
        v16[v13].x = *(p_z - 6);
        p_x = &v16[v13].x;
        v18 = *(p_z - 5);
        p_z += 16;
        p_x[1] = v18;
        p_x[2] = *(p_z - 20);
        p_x[3] = *(p_z - 19);
        v19 = &this->m_Memory.m_pMemory[v13 + 1];
        v19->x = *(p_z - 18);
        v19->y = *(p_z - 17);
        v19->z = *(p_z - 16);
        v19->w = *(p_z - 15);
        v20 = &this->m_Memory.m_pMemory[v13 + 2];
        v20->x = *(p_z - 14);
        v20->y = *(p_z - 13);
        v20->z = *(p_z - 12);
        v20->w = *(p_z - 11);
        v21 = &this->m_Memory.m_pMemory[v13 + 3];
        v21->x = *(p_z - 10);
        v13 += 4;
        --v15;
        v21->y = *(p_z - 9);
        v21->z = *(p_z - 8);
        v21->w = *(p_z - 7);
      }
      while ( v15 != 0 );
      v11 = pToInsert;
      v9 = elem;
    }
    if ( v12 < num )
    {
      v22 = v9 + v12;
      v23 = (int)&v11[v12].z;
      v24 = num - v12;
      do
      {
        v25 = &this->m_Memory.m_pMemory[v22];
        v25->x = *(float *)(v23 - 8);
        v23 += 16;
        ++v22;
        --v24;
        v25->y = *(float *)(v23 - 20);
        v25->z = *(float *)(v23 - 16);
        v25->w = *(float *)(v23 - 12);
      }
      while ( v24 != 0 );
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x00418040
// Name: public: int CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::InsertMultipleBefore(int,int,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertMultipleBefore(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int elem,
        int num,
        const QAngle *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  QAngle *m_pMemory; // ecx
  int v9; // edi
  int v10; // eax
  int v11; // ebp
  int v12; // ecx
  float *p_z; // eax
  unsigned int v14; // edi
  QAngle *v15; // edx
  QAngle *v16; // edx
  double v17; // st7
  QAngle *v18; // edx
  QAngle *v19; // edx
  QAngle *v20; // edx
  int v21; // edx
  float *v22; // ecx
  int v23; // ebx
  QAngle *v24; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + num], src: (unsigned __int8 *)&m_pMemory[elem], count: 12 * v10);
  if ( pToInsert != nullptr )
  {
    v11 = 0;
    if ( num >= 4 )
    {
      v12 = elem;
      p_z = &pToInsert[1].z;
      v14 = ((unsigned int)(num - 4) >> 2) + 1;
      v11 = 4 * v14;
      do
      {
        v15 = this->m_Memory.m_pMemory;
        v15[v12].x = *(p_z - 5);
        v16 = &v15[v12];
        v17 = *(p_z - 4);
        p_z += 12;
        v16->y = v17;
        v16->z = *(p_z - 15);
        v18 = &this->m_Memory.m_pMemory[v12 + 1];
        v18->x = *(p_z - 14);
        v18->y = *(p_z - 13);
        v18->z = *(p_z - 12);
        v19 = &this->m_Memory.m_pMemory[v12 + 2];
        v19->x = *(p_z - 11);
        v19->y = *(p_z - 10);
        v19->z = *(p_z - 9);
        v20 = &this->m_Memory.m_pMemory[v12 + 3];
        v20->x = *(p_z - 8);
        v12 += 4;
        --v14;
        v20->y = *(p_z - 7);
        v20->z = *(p_z - 6);
      }
      while ( v14 != 0 );
      v9 = elem;
    }
    if ( v11 < num )
    {
      v21 = v9 + v11;
      v22 = &pToInsert[v11].z;
      v23 = num - v11;
      do
      {
        v24 = &this->m_Memory.m_pMemory[v21];
        v24->x = *(v22 - 2);
        v22 += 3;
        ++v21;
        --v23;
        v24->y = *(v22 - 4);
        v24->z = *(v22 - 3);
      }
      while ( v23 != 0 );
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x00418190
// Name: public: int CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>::InsertMultipleBefore(int,int,class Quaternion const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertMultipleBefore(
        CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int> > *this,
        int elem,
        int num,
        const UniqueId_t *pToInsert)
{
  int v4; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  UniqueId_t *m_pMemory; // ecx
  int v10; // eax
  const UniqueId_t *v11; // ecx
  int v12; // edx
  UniqueId_t *v13; // eax
  int v14; // ebp

  v4 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<Quaternion,int>::Grow((CUtlMemory<CUtlBinaryBlock,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    memmove(dst: m_pMemory[elem + num].m_Value, src: m_pMemory[elem].m_Value, count: 16 * v10);
  v11 = pToInsert;
  if ( pToInsert != nullptr && num > 0 )
  {
    v12 = elem;
    do
    {
      v13 = &this->m_Memory.m_pMemory[v12];
      *(_DWORD *)v13->m_Value = *(_DWORD *)v11->m_Value;
      *(_DWORD *)&v13->m_Value[4] = *(_DWORD *)&v11->m_Value[4];
      *(_DWORD *)&v13->m_Value[8] = *(_DWORD *)&v11->m_Value[8];
      v14 = *(_DWORD *)&v11->m_Value[12];
      ++v11;
      ++v12;
      --v4;
      *(_DWORD *)&v13->m_Value[12] = v14;
    }
    while ( v4 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00418240
// Name: public: int CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::InsertBefore(int,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::InsertBefore(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int elem,
        const VMatrix *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VMatrix *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<VMatrix,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: v7 << 6);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004182B0
// Name: public: int CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::InsertMultipleBefore(int,int,class VMatrix const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::InsertMultipleBefore(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int elem,
        int num,
        const VMatrix *pToInsert)
{
  int v4; // ebx
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VMatrix *m_pMemory; // ecx
  int v10; // edi
  int v11; // eax
  const VMatrix *v12; // ebp
  int v13; // edi

  v4 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<VMatrix,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = elem;
  v11 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v11 > 0 && num > 0 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + num], src: (unsigned __int8 *)&m_pMemory[elem], count: v11 << 6);
  v12 = pToInsert;
  if ( pToInsert != nullptr && num > 0 )
  {
    v13 = elem << 6;
    do
    {
      VMatrix::operator=(this: (VMatrix *)((char *)this->m_Memory.m_pMemory + v13), mOther: v12++);
      v13 += 64;
      --v4;
    }
    while ( v4 != 0 );
    return elem;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x00418350
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem,
        const CUtlString *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  CUtlString *v9; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<Quaternion,int>::Grow((CUtlMemory<CUtlBinaryBlock,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 16 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    CUtlString::CUtlString(this: v9, string: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004183C0
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertMultipleBefore(int,int,class CUtlString const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertMultipleBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem,
        int num,
        const CUtlString *pToInsert)
{
  int v4; // ebx
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v10; // edi
  int v11; // eax
  int v12; // ebp
  CUtlString *v13; // ecx
  const CUtlString *v14; // ebp
  int v15; // edi

  v4 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<Quaternion,int>::Grow((CUtlMemory<CUtlBinaryBlock,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = elem;
  v11 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v11 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + num], src: (unsigned __int8 *)&m_pMemory[elem], count: 16 * v11);
LABEL_8:
    if ( num > 0 )
    {
      v12 = elem;
      do
      {
        v13 = &this->m_Memory.m_pMemory[v12];
        if ( v13 != nullptr )
          CUtlString::CUtlString(this: v13);
        ++v12;
        --num;
      }
      while ( num != 0 );
    }
  }
  v14 = pToInsert;
  if ( pToInsert != nullptr && v4 > 0 )
  {
    v15 = elem;
    do
    {
      CUtlString::operator=(this: &this->m_Memory.m_pMemory[v15++], src: v14++);
      --v4;
    }
    while ( v4 != 0 );
    return elem;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x00418490
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertBefore(int,class CUtlBinaryBlock const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        const CUtlBinaryBlock *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  CUtlBinaryBlock *v9; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<Quaternion,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 16 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: v9, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00418500
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertMultipleBefore(int,int,class CUtlBinaryBlock const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertMultipleBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        int num,
        const CUtlString *pToInsert)
{
  int v4; // ebx
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v10; // edi
  int v11; // eax
  int v12; // ebp
  CUtlBinaryBlock *v13; // ecx
  const CUtlString *v14; // ebp
  int v15; // edi

  v4 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<Quaternion,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = elem;
  v11 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v11 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + num], src: (unsigned __int8 *)&m_pMemory[elem], count: 16 * v11);
LABEL_8:
    if ( num > 0 )
    {
      v12 = elem;
      do
      {
        v13 = &this->m_Memory.m_pMemory[v12];
        if ( v13 != nullptr )
          CUtlBinaryBlock::CUtlBinaryBlock(this: v13, growSize: 0, initSize: 0);
        ++v12;
        --num;
      }
      while ( num != 0 );
    }
  }
  v14 = pToInsert;
  if ( pToInsert != nullptr && v4 > 0 )
  {
    v15 = elem;
    do
    {
      CUtlString::operator=(this: (CUtlString *)&this->m_Memory.m_pMemory[v15++], src: v14++);
      --v4;
    }
    while ( v4 != 0 );
    return elem;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x004185D0
// Name: public: int CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>::InsertBefore(int,class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertBefore(
        CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int> > *this,
        int elem,
        const UniqueId_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  UniqueId_t *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  UniqueId_t *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<Quaternion,int>::Grow((CUtlMemory<CUtlBinaryBlock,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    memmove(dst: m_pMemory[elem + 1].m_Value, src: m_pMemory[elem].m_Value, count: 16 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00424E00
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlString *v3; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      if ( v3->m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00425030
// Name: public: class CUtlBinaryBlock const __near & CDmAttribute::GetValue<class CUtlBinaryBlock>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlBinaryBlock> *__thiscall CDmAttribute::GetValue<CUtlBinaryBlock>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::`local static guard' |= 1u;
    CUtlBinaryBlock::CUtlBinaryBlock(
      this: &`CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::defaultVal.m_Storage,
      growSize: 0,
      initSize: 0);
    `CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::defaultVal.m_pAttribute = nullptr;
    CUtlBinaryBlock::Set(
      this: &`CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::defaultVal.m_Storage,
      pValue: nullptr,
      nLen: 0);
    atexit(func: `CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 6 )
    return (CDmaVar<CUtlBinaryBlock> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0042C6F0
// Name: public: class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_ElementType = -1;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0xF )
    return (CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0042C760
// Name: public: class CUtlVector<int,class CUtlMemory<int,int>> const __near & CDmAttribute::GetValue<class CUtlVector<int,class CUtlMemory<int,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<int,CUtlMemory<int,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x10 )
    return (CDmaVar<CUtlVector<int,CUtlMemory<int,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0042C7C0
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmAttribute::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<float,CUtlMemory<float,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x11 )
    return (CDmaVar<CUtlVector<float,CUtlMemory<float,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0042C820
// Name: public: class CUtlVector<bool,class CUtlMemory<bool,int>> const __near & CDmAttribute::GetValue<class CUtlVector<bool,class CUtlMemory<bool,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<bool,CUtlMemory<bool,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x12 )
    return (CDmaVar<CUtlVector<bool,CUtlMemory<bool,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0042C880
// Name: public: class CUtlVector<class Color,class CUtlMemory<class Color,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Color,class CUtlMemory<class Color,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Color,CUtlMemory<Color,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x16 )
    return (CDmaVar<CUtlVector<Color,CUtlMemory<Color,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0042C8E0
// Name: public: class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x17 )
    return (CDmaVar<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0042C940
// Name: public: class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector,CUtlMemory<Vector,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x18 )
    return (CDmaVar<CUtlVector<Vector,CUtlMemory<Vector,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0042C9A0
// Name: public: class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x19 )
    return (CDmaVar<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0042CA00
// Name: public: class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1A )
    return (CDmaVar<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0042CA60
// Name: public: class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1B )
    return (CDmaVar<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0042CAC0
// Name: public: class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1C )
    return (CDmaVar<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0042CC40
// Name: public: class CUtlVector<struct UniqueId_t,class CUtlMemory<struct UniqueId_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<struct UniqueId_t,class CUtlMemory<struct UniqueId_t,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x15 )
    return (CDmaVar<CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004311C0
// Name: public: void CUtlVector<int,class CUtlMemory<int,int>>::CopyArray(int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<int,CUtlMemory<int,int>>::CopyArray(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        const int *pArray,
        int size)
{
  int i; // eax

  this->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)this,
    elem: 0,
    num: size,
    pToInsert: nullptr);
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x00431200
// Name: public: void CUtlVector<float,class CUtlMemory<float,int>>::CopyArray(float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<float,CUtlMemory<float,int>>::CopyArray(
        CUtlVector<float,CUtlMemory<float,int> > *this,
        const float *pArray,
        int size)
{
  int v3; // ebp
  int v4; // edi
  const float *v6; // ecx
  const float *v7; // eax
  int v8; // edx
  unsigned int v9; // ecx
  int v10; // ebx
  char *v11; // edx
  double v12; // st7
  char *v13; // edx

  v3 = size;
  v4 = 0;
  this->m_Size = 0;
  CUtlVector<float,CUtlMemory<float,int>>::InsertMultipleBefore(this, elem: 0, num: size, pToInsert: nullptr);
  v6 = pArray;
  if ( size >= 4 )
  {
    v7 = pArray + 2;
    v8 = -8 - (_DWORD)pArray;
    v9 = ((unsigned int)(size - 4) >> 2) + 1;
    v10 = 2;
    v4 = 4 * v9;
    while ( 1 )
    {
      v11 = (char *)v7 + v8;
      *(float *)&v11[(unsigned int)this->m_Memory.m_pMemory] = *(v7 - 2);
      v10 += 4;
      *(float *)&v11[(unsigned int)this->m_Memory.m_pMemory + 4] = *(v7 - 1);
      this->m_Memory.m_pMemory[v10 - 4] = *v7;
      v12 = v7[1];
      v13 = (char *)v7 + 4 - (_DWORD)pArray;
      v7 += 4;
      *(float *)&v13[(unsigned int)this->m_Memory.m_pMemory] = v12;
      if ( --v9 == 0 )
        break;
      v8 = -8 - (_DWORD)pArray;
    }
    v3 = size;
    v6 = pArray;
  }
  for ( ; v4 < v3; ++v4 )
    this->m_Memory.m_pMemory[v4] = v6[v4];
}

//------------------------------------------------------------------------------
// Address: 0x004312B0
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::CopyArray(bool const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::CopyArray(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        const bool *pArray,
        int size)
{
  int m_nAllocationCount; // eax
  bool *m_pMemory; // ecx
  signed int v6; // eax
  bool v7; // zf
  int i; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = this->m_Size - size;
    v7 = this->m_Size == size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v6 >= 0 && !v7 && size > 0 )
      memmove(dst: (unsigned __int8 *)&m_pMemory[size], src: (unsigned __int8 *)m_pMemory, count: v6);
  }
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x00431320
// Name: public: void CUtlVector<class Color,class CUtlMemory<class Color,int>>::CopyArray(class Color const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Color,CUtlMemory<Color,int>>::CopyArray(
        CUtlVector<Color,CUtlMemory<Color,int> > *this,
        const Color *pArray,
        int size)
{
  int i; // eax

  this->m_Size = 0;
  CUtlVector<Color,CUtlMemory<Color,int>>::InsertMultipleBefore(this, elem: 0, num: size, pToInsert: nullptr);
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x00431360
// Name: public: void CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::CopyArray(class Vector2D const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::CopyArray(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        const Vector2D *pArray,
        int size)
{
  int v3; // edi
  int v4; // ebp
  int v7; // edx
  unsigned int v8; // edi
  float *p_y; // eax
  Vector2D *m_pMemory; // ecx
  char *v11; // edx
  float *v12; // ecx
  float *v13; // ecx
  double v14; // st7
  float *v15; // ecx
  int v16; // ecx
  Vector2D *v17; // eax
  int v18; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h]
  const Vector2D *pArraya; // [esp+1Ch] [ebp+4h]

  v3 = size;
  v4 = 0;
  this->m_Size = 0;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(this, elem: 0, num: size, pToInsert: nullptr);
  if ( size >= 4 )
  {
    v18 = -4 - (_DWORD)pArray;
    v7 = -20 - (_DWORD)pArray;
    v8 = ((unsigned int)(size - 4) >> 2) + 1;
    p_y = &pArray[2].y;
    v19 = 4 - (_DWORD)pArray;
    pArraya = (const Vector2D *)(-20 - (_DWORD)pArray);
    v4 = 4 * v8;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v11 = (char *)p_y + v7;
      *(float *)&v11[(_DWORD)m_pMemory] = *(p_y - 5);
      *(float *)((char *)&m_pMemory->y + (_DWORD)v11) = *(p_y - 4);
      v12 = (float *)&v11[(unsigned int)this->m_Memory.m_pMemory + 8];
      *v12 = *(p_y - 3);
      v12[1] = *(p_y - 2);
      v13 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_y + v18);
      *v13 = *(p_y - 1);
      v13[1] = *p_y;
      v14 = p_y[1];
      v15 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_y + v19);
      p_y += 8;
      --v8;
      *v15 = v14;
      v15[1] = *(p_y - 6);
      if ( v8 == 0 )
        break;
      v7 = (int)pArraya;
    }
    v3 = size;
  }
  for ( ; v4 < v3; v17->y = pArray[v16].y )
  {
    v16 = v4;
    v17 = &this->m_Memory.m_pMemory[v4];
    v17->x = pArray[v4++].x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431450
// Name: public: void CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::CopyArray(class Vector4D const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::CopyArray(
        CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *this,
        const Vector4D *pArray,
        int size)
{
  int v3; // edi
  int v5; // eax
  int v6; // edx
  unsigned int v7; // edi
  float *p_z; // eax
  Vector4D *m_pMemory; // ecx
  char *v10; // edx
  float *v11; // ecx
  float *v12; // ecx
  float *v13; // ecx
  float *v14; // ecx
  double v15; // st7
  float *v16; // ecx
  int v17; // edi
  float *v18; // eax
  int v19; // [esp+10h] [ebp-4h]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertMultipleBefore(this, elem: 0, num: size, pToInsert: nullptr);
  v5 = 0;
  if ( size >= 4 )
  {
    v6 = -24 - (_DWORD)pArray;
    v7 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].z;
    v19 = 4 * v7;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (char *)p_z + v6;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 6);
      v11 = (float *)((int)&m_pMemory->x + (_DWORD)v10);
      v11[1] = *(p_z - 5);
      v11[2] = *(p_z - 4);
      v11[3] = *(p_z - 3);
      v12 = (float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 16];
      *v12 = *(p_z - 2);
      v12[1] = *(p_z - 1);
      v12[2] = *p_z;
      v12[3] = p_z[1];
      v13 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 8 - (_DWORD)pArray);
      *v13 = p_z[2];
      v13[1] = p_z[3];
      v13[2] = p_z[4];
      v13[3] = p_z[5];
      v14 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 24 - (_DWORD)pArray);
      v15 = p_z[6];
      p_z += 16;
      --v7;
      *v14 = v15;
      v14[1] = *(p_z - 9);
      v14[2] = *(p_z - 8);
      v14[3] = *(p_z - 7);
      if ( v7 == 0 )
        break;
      v6 = -24 - (_DWORD)pArray;
    }
    v3 = size;
    v5 = v19;
  }
  if ( v5 < v3 )
  {
    v16 = &pArray[v5].z;
    v17 = v3 - v5;
    do
    {
      v18 = (float *)((char *)v16 + (unsigned int)this->m_Memory.m_pMemory + -8 - (_DWORD)pArray);
      *v18 = *(v16 - 2);
      v16 += 4;
      --v17;
      v18[1] = *(v16 - 5);
      v18[2] = *(v16 - 4);
      v18[3] = *(v16 - 3);
    }
    while ( v17 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431580
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::CopyArray(class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        const QAngle *pArray,
        int size)
{
  int v3; // edi
  int v5; // eax
  int v6; // edx
  unsigned int v7; // edi
  float *p_z; // eax
  QAngle *m_pMemory; // ecx
  char *v10; // edx
  float *v11; // ecx
  float *v12; // ecx
  float *v13; // ecx
  float *v14; // ecx
  double v15; // st7
  float *v16; // ecx
  int v17; // edi
  double v18; // st7
  float *v19; // eax
  int v20; // [esp+10h] [ebp-4h]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertMultipleBefore(this, elem: 0, num: size, pToInsert: nullptr);
  v5 = 0;
  if ( size >= 4 )
  {
    v6 = -20 - (_DWORD)pArray;
    v7 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].z;
    v20 = 4 * v7;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (char *)p_z + v6;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 5);
      v11 = (float *)((int)&m_pMemory->x + (_DWORD)v10);
      v11[1] = *(p_z - 4);
      v11[2] = *(p_z - 3);
      v12 = (float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 12];
      *v12 = *(p_z - 2);
      v12[1] = *(p_z - 1);
      v12[2] = *p_z;
      v13 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 4 - (_DWORD)pArray);
      *v13 = p_z[1];
      v13[1] = p_z[2];
      v13[2] = p_z[3];
      v14 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 16 - (_DWORD)pArray);
      v15 = p_z[4];
      p_z += 12;
      --v7;
      *v14 = v15;
      v14[1] = *(p_z - 7);
      v14[2] = *(p_z - 6);
      if ( v7 == 0 )
        break;
      v6 = -20 - (_DWORD)pArray;
    }
    v5 = v20;
    v3 = size;
  }
  if ( v5 < v3 )
  {
    v16 = &pArray[v5].z;
    v17 = v3 - v5;
    do
    {
      v18 = *(v16 - 2);
      v19 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)v16 - 8 - (_DWORD)pArray);
      v16 += 3;
      --v17;
      *v19 = v18;
      v19[1] = *(v16 - 4);
      v19[2] = *(v16 - 3);
    }
    while ( v17 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431690
// Name: public: void CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>::CopyArray(class Quaternion const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::CopyArray(
        CUtlVector<UniqueId_t,CUtlMemory<UniqueId_t,int> > *this,
        const UniqueId_t *pArray,
        int size)
{
  int v4; // edx
  int v5; // ecx
  UniqueId_t *v6; // eax
  int v7; // ebx

  this->m_Size = 0;
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertMultipleBefore(this, elem: 0, num: size, pToInsert: nullptr);
  if ( size > 0 )
  {
    v4 = size;
    v5 = 0;
    do
    {
      v6 = &this->m_Memory.m_pMemory[v5];
      *(_DWORD *)v6->m_Value = *(_DWORD *)pArray[v5].m_Value;
      *(_DWORD *)&v6->m_Value[4] = *(_DWORD *)&pArray[v5].m_Value[4];
      *(_DWORD *)&v6->m_Value[8] = *(_DWORD *)&pArray[v5].m_Value[8];
      v7 = *(_DWORD *)&pArray[v5++].m_Value[12];
      --v4;
      *(_DWORD *)&v6->m_Value[12] = v7;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004316F0
// Name: public: void CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::CopyArray(class VMatrix const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::CopyArray(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        const VMatrix *pArray,
        int size)
{
  int v3; // ebx
  int v4; // esi

  v3 = size;
  v4 = 0;
  this->m_Size = 0;
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::InsertMultipleBefore(this, elem: 0, num: size, pToInsert: nullptr);
  if ( size > 0 )
  {
    do
    {
      VMatrix::operator=(this: &this->m_Memory.m_pMemory[v4], mOther: &pArray[v4]);
      ++v4;
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431730
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::FastRemove(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem)
{
  CUtlString *v3; // esi
  int m_Size; // eax
  int v5; // eax
  unsigned __int8 *m_pMemory; // edx
  CUtlString *v7; // eax
  CUtlString *v8; // ecx

  v3 = &this->m_Memory.m_pMemory[elem];
  if ( v3->m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v3->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Storage.m_Memory.m_pMemory);
      v3->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    v3->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    v5 = m_Size;
    m_pMemory = this->m_Memory.m_pMemory[v5 - 1].m_Storage.m_Memory.m_pMemory;
    v7 = &this->m_Memory.m_pMemory[v5 - 1];
    v8 = &this->m_Memory.m_pMemory[elem];
    v8->m_Storage.m_Memory.m_pMemory = m_pMemory;
    v8->m_Storage.m_Memory.m_nAllocationCount = v7->m_Storage.m_Memory.m_nAllocationCount;
    v8->m_Storage.m_Memory.m_nGrowSize = v7->m_Storage.m_Memory.m_nGrowSize;
    v8->m_Storage.m_nActualLength = v7->m_Storage.m_nActualLength;
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004317A0
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::Remove(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem)
{
  CUtlString *v3; // esi

  v3 = &this->m_Memory.m_pMemory[elem];
  if ( v3->m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v3->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Storage.m_Memory.m_pMemory);
      v3->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    v3->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Size - elem - 1 > 0 )
    memmove(
      dst: (unsigned __int8 *)&this->m_Memory.m_pMemory[elem],
      src: (unsigned __int8 *)&this->m_Memory.m_pMemory[elem + 1],
      count: 16 * (this->m_Size - elem - 1));
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00431810
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveMultiple(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem,
        int num)
{
  int v5; // ecx
  int v6; // edx
  int v7; // ebp
  CUtlString *v8; // esi
  int v9; // [esp+8h] [ebp-4h]
  int elema; // [esp+10h] [ebp+4h]

  v5 = num;
  v6 = elem + num;
  v9 = elem + num;
  if ( elem + num - 1 >= elem )
  {
    v7 = elem + num - 1;
    elema = num;
    do
    {
      v8 = &this->m_Memory.m_pMemory[v7];
      if ( v8->m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v8->m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8->m_Storage.m_Memory.m_pMemory);
          v5 = num;
          v6 = v9;
          v8->m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v8->m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v7;
      --elema;
    }
    while ( elema != 0 );
  }
  if ( this->m_Size - elem - v5 > 0 && v5 > 0 )
  {
    memmove(
      dst: (unsigned __int8 *)&this->m_Memory.m_pMemory[elem],
      src: (unsigned __int8 *)&this->m_Memory.m_pMemory[v6],
      count: 16 * (this->m_Size - elem - v5));
    v5 = num;
  }
  this->m_Size -= v5;
}

//------------------------------------------------------------------------------
// Address: 0x00431AA0
// Name: public: CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::~CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  bool v2; // sf
  CUtlString *m_pMemory; // eax

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433BE0
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::CopyArray(class CUtlBinaryBlock const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::CopyArray(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        const CUtlBinaryBlock *pArray,
        int size)
{
  int v4; // ebx
  int v5; // esi

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll((CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this);
  v4 = size;
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertMultipleBefore(
    this,
    elem: this->m_Size,
    num: size,
    pToInsert: nullptr);
  if ( size > 0 )
  {
    v5 = 0;
    do
    {
      CUtlString::operator=(this: (CUtlString *)&this->m_Memory.m_pMemory[v5], src: (const CUtlString *)&pArray[v5]);
      ++v5;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435270
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::CopyArray(class CUtlString const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::CopyArray(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        const CUtlString *pArray,
        int size)
{
  int v4; // ebx
  int v5; // esi

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this);
  v4 = size;
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertMultipleBefore(
    this,
    elem: this->m_Size,
    num: size,
    pToInsert: nullptr);
  if ( size > 0 )
  {
    v5 = 0;
    do
    {
      CUtlString::operator=(this: &this->m_Memory.m_pMemory[v5], src: &pArray[v5]);
      ++v5;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004352C0
// Name: public: class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &`CDmAttribute::GetValue<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>>'::`2'::defaultVal.m_Storage);
    atexit(func: `CDmAttribute::GetValue<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x13 )
    return (CDmaVar<CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00435330
// Name: public: class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)&`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal);
    atexit(func: `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x14 )
    return (CDmaVar<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00436690
// Name: public: void CUtlMemory<class CUtlSymbol,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbol,int>::Grow(CUtlMemory<CUtlSymbol,int> *this, int num)
{
  int m_nGrowSize; // edi
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // eax

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 16;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
        {
          v6 = (v5 + this->m_nAllocationCount) / 2;
          this->m_nAllocationCount = v6;
        }
        while ( v6 < v5 );
      }
      else
      {
        this->m_nAllocationCount = -1;
      }
    }
    if ( this->m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Realloc_2(
                                        this: _g_pMemAlloc,
                                        a2: this->m_pMemory,
                                        a3: 2 * this->m_nAllocationCount);
    else
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 2 * this->m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436840
// Name: public: bool CUtlVector<class IDmNotify __near *,class CUtlMemory<class IDmNotify __near *,int>>::FindAndRemove(class IDmNotify __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
        CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *this,
        IDmNotify **src)
{
  int m_Size; // edx
  int v4; // eax
  IDmNotify **m_pMemory; // ebx
  IDmNotify **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[v4], src: (unsigned __int8 *)&m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00436A70
// Name: public: int CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>>::InsertBefore(int,class CUtlSymbol const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
        CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *this,
        int elem,
        const CUtlSymbol *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  CUtlSymbol *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlSymbol,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 2 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    v9->m_Id = src->m_Id;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00436D50
// Name: public: int CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>>::InsertBefore(int,struct UndoInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<UndoInfo_t,CUtlMemory<UndoInfo_t,int>>::InsertBefore(
        CUtlVector<UndoInfo_t,CUtlMemory<UndoInfo_t,int> > *this,
        int elem,
        const UndoInfo_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  UndoInfo_t *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  UndoInfo_t *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 20 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00437630
// Name: public: class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> __near & CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>>::operator=(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *__thiscall CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int>>::operator=(
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *other)
{
  int m_Size; // edi
  int i; // eax

  m_Size = other->m_Size;
  this->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    this,
    elem: 0,
    num: m_Size,
    pToInsert: nullptr);
  for ( i = 0; i < m_Size; ++i )
    this->m_Memory.m_pMemory[i] = other->m_Memory.m_pMemory[i];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00437B50
// Name: public: int CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>::InsertBefore(int,struct CDmElementDictionary::DmIdPair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>::InsertBefore(
        CUtlVector<DmIdPair_t,CUtlMemory<DmIdPair_t,int> > *this,
        int elem,
        const DmIdPair_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DmIdPair_t *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DmIdPair_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    memmove(dst: m_pMemory[elem + 1].m_oldId.m_Value, src: m_pMemory[elem].m_oldId.m_Value, count: 32 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004384B0
// Name: public: void CUtlRBTree<struct CDmElementSerializationDictionary::ElementInfo_t,int,bool (*)(struct CDmElementSerializationDictionary::ElementInfo_t const __near &,struct CDmElementSerializationDictionary::ElementInfo_t const __near &),class CUtlBlockMemory<struct UtlRBTreeNode_t<struct CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::RemoveAll(
        CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl*)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int> > *this)
{
  int index; // eax
  int v3; // esi

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = (this->m_Elements.m_nBlocks > 0) - 1;
    if ( this->m_Elements.m_nBlocks > 0 )
    {
      do
      {
        if ( v3 >= 0
          && v3 >> (*((int *)&this->m_Elements + 2) >> 27) < this->m_Elements.m_nBlocks
          && v3 <= index
          && CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
               this,
               i: v3)->m_Left != v3 )
        {
          this->m_Elements.m_pMemory[v3 >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v3 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v3 >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v3 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        if ( ++v3 < 0 || v3 >> (*((int *)&this->m_Elements + 2) >> 27) >= this->m_Elements.m_nBlocks )
          v3 = -1;
      }
      while ( v3 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004385F0
// Name: public: void CUtlVector<class CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>,class CUtlMemory<class CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // ebp
  CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *v3; // esi
  bool v4; // sf
  CDmElementDictionary::DmIdPair_t *m_pMemory; // eax
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v4 = v3->m_Memory.m_nGrowSize < 0;
      v3->m_Size = 0;
      if ( !v4 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          this = v6;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_Memory.m_pMemory;
      v3->m_pElements = v3->m_Memory.m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          this = v6;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438680
// Name: public: int CUtlVector<class CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>,class CUtlMemory<class CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>,int>>::InsertMultipleBefore(int,int,class CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>> const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<DmIdPair_t,CUtlMemory<DmIdPair_t,int> >,CUtlMemory<CUtlVector<DmIdPair_t,CUtlMemory<DmIdPair_t,int> >,int> > *this,
        int elem,
        int num,
        const CUtlVector<DmIdPair_t,CUtlMemory<DmIdPair_t,int> > *pToInsert)
{
  int v4; // ebx
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<DmIdPair_t,CUtlMemory<DmIdPair_t,int> > *m_pMemory; // ecx
  int v10; // edi
  int v11; // eax
  int v12; // ecx
  int i; // edx
  CUtlVector<DmIdPair_t,CUtlMemory<DmIdPair_t,int> > *v14; // eax
  int v15; // edi
  const CUtlVector<DmIdPair_t,CUtlMemory<DmIdPair_t,int> > *v16; // ebp

  v4 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = elem;
  v11 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v11 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + num], src: (unsigned __int8 *)&m_pMemory[elem], count: 20 * v11);
LABEL_8:
    if ( num > 0 )
    {
      v12 = elem;
      for ( i = num; i != 0; --i )
      {
        v14 = &this->m_Memory.m_pMemory[v12];
        if ( v14 != nullptr )
        {
          v14->m_Memory.m_pMemory = nullptr;
          v14->m_Memory.m_nAllocationCount = 0;
          v14->m_Memory.m_nGrowSize = 0;
          v14->m_Size = 0;
          v14->m_pElements = nullptr;
        }
        ++v12;
      }
    }
  }
  if ( pToInsert != nullptr && num > 0 )
  {
    v15 = elem;
    v16 = pToInsert;
    do
    {
      CUtlVector<DmIdPair_t,CUtlMemory<DmIdPair_t,int>>::operator=(this: &this->m_Memory.m_pMemory[v15++], other: v16++);
      --v4;
    }
    while ( v4 != 0 );
    return elem;
  }
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x0043D380
// Name: protected: void CUtlRBTree<class CDmAttribute __near *,unsigned short,bool (*)(class CDmAttribute __near * const __near &,class CDmAttribute __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmAttribute __near *,unsigned short>,unsigned short>>::FindInsertionPosition(class CDmAttribute __near * const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl*)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short> > *this,
        CDmAttribute *const *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043D490
// Name: public: int CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>::InsertMultipleBefore(int,int,struct CDmElementDictionary::DmIdPair_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>::InsertMultipleBefore(
        CUtlVector<DmIdPair_t,CUtlMemory<DmIdPair_t,int> > *this,
        int elem,
        int num,
        const DmIdPair_t *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DmIdPair_t *m_pMemory; // ecx
  int v9; // ebp
  int v10; // eax
  const DmIdPair_t *v11; // ebx
  int v12; // ebp
  DmIdPair_t *v13; // esi

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DmIdPair_t,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    memmove(dst: m_pMemory[num + elem].m_oldId.m_Value, src: m_pMemory[elem].m_oldId.m_Value, count: 32 * v10);
  v11 = pToInsert;
  if ( pToInsert != nullptr && num > 0 )
  {
    v12 = elem;
    do
    {
      v13 = &this->m_Memory.m_pMemory[v12];
      CopyUniqueId(src: &v11->m_oldId, pDest: &v13->m_oldId);
      CopyUniqueId(src: &v11->m_newId, pDest: &v13->m_newId);
      ++v11;
      ++v12;
      --num;
    }
    while ( num != 0 );
    return elem;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x0043D550
// Name: protected: void CUtlRBTree<class CDmAttribute __near *,unsigned short,bool (*)(class CDmAttribute __near * const __near &,class CDmAttribute __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmAttribute __near *,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl*)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Right; // bx
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Right = CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
              this,
              i: elem)->m_Right;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Right = CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
                                             this,
                                             i: m_Right)->m_Left;
  if ( CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Right)->m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Right)->m_Left].m_Parent = elem;
  if ( m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
                                                     this,
                                                     i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else
  {
    v5 = CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Left == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Right;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0043D650
// Name: protected: void CUtlRBTree<class CDmAttribute __near *,unsigned short,bool (*)(class CDmAttribute __near * const __near &,class CDmAttribute __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmAttribute __near *,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl*)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Left; // di
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Left = CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
             this,
             i: elem)->m_Left;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Left = CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
                                            this,
                                            i: m_Left)->m_Right;
  if ( CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Left)->m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Left)->m_Right].m_Parent = elem;
  if ( m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
                                                    this,
                                                    i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Right == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0043D7C0
// Name: public: unsigned short CUtlRBTree<class CDmAttribute __near *,unsigned short,bool (*)(class CDmAttribute __near * const __near &,class CDmAttribute __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmAttribute __near *,unsigned short>,unsigned short>>::Find(class CDmAttribute __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl*)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short> > *this,
        CDmAttribute *const *search)
{
  unsigned __int16 m_Root; // bp
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0043D8D0
// Name: public: int CUtlVector<struct CDmElementDictionary::AttributeInfo_t,class CUtlMemory<struct CDmElementDictionary::AttributeInfo_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::AttributeInfo_t,CUtlMemory<CDmElementDictionary::AttributeInfo_t,int>>::InsertBefore(
        CUtlVector<CDmElementDictionary::AttributeInfo_t,CUtlMemory<CDmElementDictionary::AttributeInfo_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmElementDictionary::AttributeInfo_t *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::AttributeInfo_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 24 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0043D930
// Name: public: int CUtlVector<struct CDmElementDictionary::DeletionInfo_t,class CUtlMemory<struct CDmElementDictionary::DeletionInfo_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::InsertBefore(
        CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmElementDictionary::DeletionInfo_t *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    memmove(dst: (unsigned __int8 *)&m_pMemory[elem + 1], src: (unsigned __int8 *)&m_pMemory[elem], count: 12 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0043D990
// Name: protected: void CUtlRBTree<struct CDmElementSerializationDictionary::ElementInfo_t,int,bool (*)(struct CDmElementSerializationDictionary::ElementInfo_t const __near &,struct CDmElementSerializationDictionary::ElementInfo_t const __near &),class CUtlBlockMemory<struct UtlRBTreeNode_t<struct CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::FindInsertionPosition(struct CDmElementSerializationDictionary::ElementInfo_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl*)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int> > *this,
        const CDmElementSerializationDictionary::ElementInfo_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc(
           a1: insert,
           a2: &this->m_Elements.m_pMemory[m_Root >> (*((int *)&this->m_Elements + 2) >> 27)][m_Root
                                                                                        & ((32
                                                                                          * *((_DWORD *)&this->m_Elements
                                                                                            + 2)) >> 5)].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][m_Root & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][m_Root & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043DAC0
// Name: public: int CUtlRBTree<struct CDmElementSerializationDictionary::ElementInfo_t,int,bool (*)(struct CDmElementSerializationDictionary::ElementInfo_t const __near &,struct CDmElementSerializationDictionary::ElementInfo_t const __near &),class CUtlBlockMemory<struct UtlRBTreeNode_t<struct CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::NewNode(
        CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl*)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int> > *this)
{
  int result; // eax
  int index; // eax
  CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>::Iterator_t *p_m_LastAlloc; // ebp
  int v5; // eax
  int v6; // edi
  __int64 v7; // rt2
  CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>::Iterator_t *v8; // eax
  CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>::Iterator_t v9; // [esp+8h] [ebp-4h] BYREF

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    p_m_LastAlloc = &this->m_LastAlloc;
    if ( index < 0 || index >> (*((int *)&this->m_Elements + 2) >> 27) >= this->m_Elements.m_nBlocks )
    {
      v5 = (this->m_Elements.m_nBlocks > 0) - 1;
    }
    else
    {
      v5 = p_m_LastAlloc->index + 1;
      if ( v5 < 0 || v5 >> (*((int *)&this->m_Elements + 2) >> 27) >= this->m_Elements.m_nBlocks )
        v5 = -1;
    }
    v9.index = v5;
    v6 = v5;
    if ( v5 < 0 || v9.index >> (*((int *)&this->m_Elements + 2) >> 27) >= this->m_Elements.m_nBlocks )
    {
      v7 = ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5) + 1;
      CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>::ChangeSize(
        this: &this->m_Elements,
        nBlocks: this->m_Elements.m_nBlocks + v7 / (int)v7);
      if ( p_m_LastAlloc->index < 0
        || p_m_LastAlloc->index >> (*((int *)&this->m_Elements + 2) >> 27) >= this->m_Elements.m_nBlocks )
      {
        v9.index = (this->m_Elements.m_nBlocks > 0) - 1;
        v8 = &v9;
      }
      else
      {
        v8 = CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>::Next(
               this: &this->m_Elements,
               result: &v9,
               it: &this->m_LastAlloc);
      }
      v6 = v8->index;
      if ( v8->index < 0 || v6 >> (*((int *)&this->m_Elements + 2) >> 27) >= this->m_Elements.m_nBlocks )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    p_m_LastAlloc->index = v6;
    this->m_pElements = nullptr;
    return v6;
  }
  else
  {
    this->m_FirstFree = this->m_Elements.m_pMemory[result >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][result & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Right;
    this->m_pElements = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043DC00
// Name: public: void CUtlRBTree<class CDmAttribute __near *,unsigned short,bool (*)(class CDmAttribute __near * const __near &,class CDmAttribute __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmAttribute __near *,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl*)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  int m_nAllocationCount; // eax
  unsigned __int16 v4; // di
  int v5; // eax
  unsigned __int16 i; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    v4 = (m_nAllocationCount > 0) - 1;
    i = v4;
    if ( m_nAllocationCount > 0 )
    {
      do
      {
        if ( v4 < m_nAllocationCount
          && v4 <= index
          && CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Left != v4 )
        {
          v5 = v4;
          this->m_Elements.m_pMemory[v5].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v5].m_Left = v4;
          this->m_FirstFree = v4;
        }
        index = this->m_LastAlloc.index;
        if ( v4 == index )
          break;
        m_nAllocationCount = this->m_Elements.m_nAllocationCount;
        ++v4;
        if ( (unsigned __int16)(i + 1) >= m_nAllocationCount )
          v4 = -1;
        i = v4;
      }
      while ( v4 != 0xFFFF );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043DCC0
// Name: protected: void CUtlRBTree<class CDmAttribute __near *,unsigned short,bool (*)(class CDmAttribute __near * const __near &,class CDmAttribute __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmAttribute __near *,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl*)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // dx
  int v4; // eax
  UtlRBTreeNode_t<CDmAttribute *,unsigned short> *v5; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeLinks_t<unsigned short> *v7; // ecx
  UtlRBTreeNode_t<CDmAttribute *,unsigned short> *v8; // ecx
  unsigned __int16 v9; // di
  UtlRBTreeNode_t<CDmAttribute *,unsigned short> *v10; // ecx
  unsigned __int16 v11; // cx
  UtlRBTreeNode_t<CDmAttribute *,unsigned short> *v12; // edx
  unsigned __int16 v13; // dx
  UtlRBTreeLinks_t<unsigned short> *v14; // edx
  UtlRBTreeNode_t<CDmAttribute *,unsigned short> *v15; // edx
  unsigned __int16 m_Right; // dx
  UtlRBTreeLinks_t<unsigned short> *v17; // ebp
  UtlRBTreeNode_t<CDmAttribute *,unsigned short> *v18; // edx
  unsigned __int16 v19; // dx
  UtlRBTreeLinks_t<unsigned short> *v20; // eax
  UtlRBTreeNode_t<CDmAttribute *,unsigned short> *v21; // edx
  unsigned __int16 m_Left; // dx
  UtlRBTreeLinks_t<unsigned short> *v23; // ebp
  UtlRBTreeNode_t<CDmAttribute *,unsigned short> *v24; // edx
  unsigned __int16 v25; // dx
  UtlRBTreeNode_t<CDmAttribute *,unsigned short> *v26; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v5 = (UtlRBTreeNode_t<CDmAttribute *,unsigned short> *)&`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v7 = m_Parent == 0xFFFF
         ? &`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v8 = (UtlRBTreeNode_t<CDmAttribute *,unsigned short> *)&`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v10 = (UtlRBTreeNode_t<CDmAttribute *,unsigned short> *)&`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v12 = (UtlRBTreeNode_t<CDmAttribute *,unsigned short> *)&`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v14 = v13 == 0xFFFF
          ? &`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : &this->m_Elements.m_pMemory[v13];
      if ( v14->m_Left == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v15 = (UtlRBTreeNode_t<CDmAttribute *,unsigned short> *)&`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        v17 = m_Right == 0xFFFF
            ? &`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
            : &this->m_Elements.m_pMemory[m_Right];
        if ( v17->m_Tag != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( elem == 0xFFFF )
            v18 = (UtlRBTreeNode_t<CDmAttribute *,unsigned short> *)&`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[elem];
          v19 = v18->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          v20 = v19 == 0xFFFF
              ? &`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
              : &this->m_Elements.m_pMemory[v19];
          if ( v20->m_Right == elem )
          {
            elem = v9;
            CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::RotateLeft(
              this,
              elem: v9);
            v9 = CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
                   this,
                   i: v9)->m_Parent;
            v11 = CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
                    this,
                    i: v9)->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v21 = (UtlRBTreeNode_t<CDmAttribute *,unsigned short> *)&`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[v11];
        m_Left = v21->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        v23 = m_Left == 0xFFFF
            ? &`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
            : &this->m_Elements.m_pMemory[m_Left];
        if ( v23->m_Tag != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( elem == 0xFFFF )
            v24 = (UtlRBTreeNode_t<CDmAttribute *,unsigned short> *)&`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[elem];
          v25 = v24->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v25 == 0xFFFF )
            v26 = (UtlRBTreeNode_t<CDmAttribute *,unsigned short> *)&`CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v26 = &this->m_Elements.m_pMemory[v25];
          if ( v26->m_Left == elem )
          {
            elem = v9;
            CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::RotateRight(
              this,
              elem: v9);
            v9 = CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
                   this,
                   i: v9)->m_Parent;
            v11 = CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::Links(
                    this,
                    i: v9)->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043E230
// Name: protected: void CUtlRBTree<struct CDmElementSerializationDictionary::ElementInfo_t,int,bool (*)(struct CDmElementSerializationDictionary::ElementInfo_t const __near &,struct CDmElementSerializationDictionary::ElementInfo_t const __near &),class CUtlBlockMemory<struct UtlRBTreeNode_t<struct CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::RotateLeft(
        CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl*)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int> > *this,
        int elem)
{
  int m_Right; // ebx
  const UtlRBTreeLinks_t<int> *v4; // eax
  const UtlRBTreeLinks_t<int> *v5; // eax
  const UtlRBTreeLinks_t<int> *v6; // eax
  const UtlRBTreeLinks_t<int> *v7; // eax

  m_Right = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
              this,
              i: elem)->m_Right;
  this->m_Elements.m_pMemory[elem >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][elem
                                                                                              & ((32
                                                                                                * *((_DWORD *)&this->m_Elements
                                                                                                  + 2)) >> 5)].m_Right = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(this, i: m_Right)->m_Left;
  if ( CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
         this,
         i: m_Right)->m_Left != -1 )
  {
    v4 = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
           this,
           i: m_Right);
    this->m_Elements.m_pMemory[v4->m_Left >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v4->m_Left & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][m_Right & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Parent = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(this, i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else
  {
    v5 = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
           this,
           i: v5->m_Parent)->m_Left == elem )
    {
      v6 = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
             this,
             i: elem);
      this->m_Elements.m_pMemory[v6->m_Parent >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v6->m_Parent & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Left = m_Right;
    }
    else
    {
      v7 = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
             this,
             i: elem);
      this->m_Elements.m_pMemory[v7->m_Parent >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v7->m_Parent & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Right = m_Right;
    }
  }
  this->m_Elements.m_pMemory[m_Right >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][m_Right
                                                                                                 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][elem
                                                                                                & ((32
                                                                                                  * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x0043E3A0
// Name: protected: void CUtlRBTree<struct CDmElementSerializationDictionary::ElementInfo_t,int,bool (*)(struct CDmElementSerializationDictionary::ElementInfo_t const __near &,struct CDmElementSerializationDictionary::ElementInfo_t const __near &),class CUtlBlockMemory<struct UtlRBTreeNode_t<struct CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::RotateRight(
        CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl*)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int> > *this,
        int elem)
{
  int m_Left; // ebx
  const UtlRBTreeLinks_t<int> *v4; // eax
  const UtlRBTreeLinks_t<int> *v5; // eax
  const UtlRBTreeLinks_t<int> *v6; // eax
  const UtlRBTreeLinks_t<int> *v7; // eax

  m_Left = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
             this,
             i: elem)->m_Left;
  this->m_Elements.m_pMemory[elem >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][elem
                                                                                              & ((32
                                                                                                * *((_DWORD *)&this->m_Elements
                                                                                                  + 2)) >> 5)].m_Left = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(this, i: m_Left)->m_Right;
  if ( CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
         this,
         i: m_Left)->m_Right != -1 )
  {
    v4 = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
           this,
           i: m_Left);
    this->m_Elements.m_pMemory[v4->m_Right >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v4->m_Right & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Parent = elem;
  }
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][m_Left & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Parent = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(this, i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
           this,
           i: v5->m_Parent)->m_Right == elem )
    {
      v6 = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
             this,
             i: elem);
      this->m_Elements.m_pMemory[v6->m_Parent >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v6->m_Parent & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Right = m_Left;
    }
    else
    {
      v7 = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
             this,
             i: elem);
      this->m_Elements.m_pMemory[v7->m_Parent >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v7->m_Parent & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Left = m_Left;
    }
  }
  this->m_Elements.m_pMemory[m_Left >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][m_Left
                                                                                                & ((32
                                                                                                  * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][elem
                                                                                                & ((32
                                                                                                  * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x0043E760
// Name: public: int CUtlRBTree<struct CDmElementSerializationDictionary::ElementInfo_t,int,bool (*)(struct CDmElementSerializationDictionary::ElementInfo_t const __near &,struct CDmElementSerializationDictionary::ElementInfo_t const __near &),class CUtlBlockMemory<struct UtlRBTreeNode_t<struct CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Find(struct CDmElementSerializationDictionary::ElementInfo_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Find(
        CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl*)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int> > *this,
        const CDmElementSerializationDictionary::ElementInfo_t *search)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    if ( this->m_LessFunc(
           a1: search,
           a2: &this->m_Elements.m_pMemory[m_Root >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][m_Root & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][m_Root & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(
             a1: &this->m_Elements.m_pMemory[m_Root >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][m_Root & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Data,
             a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][m_Root & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x0043E8B0
// Name: public: int CUtlRBTree<struct CDmElementSerializationDictionary::ElementInfo_t,int,bool (*)(struct CDmElementSerializationDictionary::ElementInfo_t const __near &,struct CDmElementSerializationDictionary::ElementInfo_t const __near &),class CUtlBlockMemory<struct UtlRBTreeNode_t<struct CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::FirstInorder(
        CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl*)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  UtlRBTreeLinks_t<int> *v4; // ecx

  v1 = `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
      `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
    }
    v4 = result == -1
       ? &`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel
       : &this->m_Elements.m_pMemory[result >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][result & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)];
    if ( v4->m_Left == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
      `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left;
    else
      result = this->m_Elements.m_pMemory[result >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][result & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043E990
// Name: public: int CUtlRBTree<struct CDmElementSerializationDictionary::ElementInfo_t,int,bool (*)(struct CDmElementSerializationDictionary::ElementInfo_t const __near &,struct CDmElementSerializationDictionary::ElementInfo_t const __near &),class CUtlBlockMemory<struct UtlRBTreeNode_t<struct CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::NextInorder(
        CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl*)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int> > *this,
        int i)
{
  int v2; // ebp
  int result; // eax
  int v5; // ebx
  UtlRBTreeLinks_t<int> *v6; // ecx
  UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *v7; // eax
  int v8; // ebx
  UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *v9; // ecx
  int m_Parent; // edi
  UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *v11; // ecx

  v2 = i;
  if ( CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
         this,
         i)->m_Right == -1 )
  {
    v7 = (UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *)CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
                                                                                    this,
                                                                                    i);
    v8 = `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      result = v7->m_Parent;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == -1 )
        v9 = (UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *)&`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v9 = &this->m_Elements.m_pMemory[v2 >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v2 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)];
      m_Parent = v9->m_Parent;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( m_Parent == -1 )
      {
        v11 = (UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *)&`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel;
      }
      else
      {
        v8 = `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard';
        v11 = &this->m_Elements.m_pMemory[m_Parent >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][m_Parent & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)];
      }
      if ( v11->m_Right != v2 )
        break;
      v2 = result;
      if ( result == -1 )
        break;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v7 = &this->m_Elements.m_pMemory[result >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][result & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)];
    }
  }
  else
  {
    result = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
               this,
               i)->m_Right;
    v5 = `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel
         : &this->m_Elements.m_pMemory[result >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][result & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)];
      if ( v6->m_Left == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left;
      else
        result = this->m_Elements.m_pMemory[result >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][result & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043EBB0
// Name: protected: void CUtlRBTree<class CDmAttribute __near *,unsigned short,bool (*)(class CDmAttribute __near * const __near &,class CDmAttribute __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmAttribute __near *,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl*)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CDmAttribute *,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CDmAttribute *,unsigned short> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl *)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043EC20
// Name: protected: void CUtlRBTree<struct CDmElementSerializationDictionary::ElementInfo_t,int,bool (*)(struct CDmElementSerializationDictionary::ElementInfo_t const __near &,struct CDmElementSerializationDictionary::ElementInfo_t const __near &),class CUtlBlockMemory<struct UtlRBTreeNode_t<struct CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl*)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int> > *this,
        int elem)
{
  int v2; // ebp
  int v4; // ebx
  UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *v5; // eax
  int m_Parent; // edi
  UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *v7; // eax
  UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *v8; // eax
  int v9; // ebp
  UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *v10; // eax
  int v11; // edi
  UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *v12; // eax
  int v13; // edx
  UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *v14; // ecx
  UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *v15; // eax
  int m_Right; // edx
  UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *v17; // eax
  const UtlRBTreeLinks_t<int> *v18; // eax
  UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *v19; // eax
  UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *v20; // eax
  const UtlRBTreeLinks_t<int> *v21; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *)&`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2 >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v2 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *)&`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][m_Parent & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *)&`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2 >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v2 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *)&`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9 >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v9 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == -1 )
        v12 = (UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *)&`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9 >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v9 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v13 == -1 )
      {
        v14 = (UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *)&`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel;
      }
      else
      {
        v4 = `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard';
        v14 = &this->m_Elements.m_pMemory[v13 >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v13 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)];
      }
      if ( v14->m_Left == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == -1 )
          v15 = (UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *)&`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11 >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v11 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( m_Right == -1 )
          v17 = (UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *)&`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v17 = &this->m_Elements.m_pMemory[m_Right >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][m_Right & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)];
        if ( v17->m_Tag == 0 )
          goto LABEL_61;
        v18 = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
                this,
                i: elem);
        if ( CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
               this,
               i: v18->m_Parent)->m_Right == elem )
        {
          elem = v9;
          CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
                 this,
                 i: v9)->m_Parent;
          v11 = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
                  this,
                  i: v9)->m_Parent;
        }
        this->m_Elements.m_pMemory[v9 >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v9 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Tag = 1;
        this->m_Elements.m_pMemory[v11 >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v11 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Tag = 0;
        CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == -1 )
          v19 = (UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *)&`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v19 = &this->m_Elements.m_pMemory[v11 >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v11 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)];
        m_Right = v19->m_Left;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( m_Right == -1 )
          v20 = (UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *)&`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[m_Right >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][m_Right & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)];
        if ( v20->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9 >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v9 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right >> (*((int *)&this->m_Elements + 2) >> 27)][m_Right
                                                                                       & ((32
                                                                                         * *((_DWORD *)&this->m_Elements
                                                                                           + 2)) >> 5)].m_Tag = 1;
          this->m_Elements.m_pMemory[v11 >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v11 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Tag = 0;
          elem = v11;
          goto LABEL_65;
        }
        v21 = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
                this,
                i: elem);
        if ( CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
               this,
               i: v21->m_Parent)->m_Left == elem )
        {
          elem = v9;
          CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
                 this,
                 i: v9)->m_Parent;
          v11 = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
                  this,
                  i: v9)->m_Parent;
        }
        this->m_Elements.m_pMemory[v9 >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v9 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Tag = 1;
        this->m_Elements.m_pMemory[v11 >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v11 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Tag = 0;
        CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_65:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][this->m_Root & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043F460
// Name: protected: void CUtlRBTree<struct CDmElementSerializationDictionary::ElementInfo_t,int,bool (*)(struct CDmElementSerializationDictionary::ElementInfo_t const __near &,struct CDmElementSerializationDictionary::ElementInfo_t const __near &),class CUtlBlockMemory<struct UtlRBTreeNode_t<struct CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::LinkToParent(
        CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl*)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *v5; // eax
  __int64 v6; // kr00_8
  UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *v7; // ecx

  v5 = &this->m_Elements.m_pMemory[i >> (*((int *)&this->m_Elements + 2) >> 27)][i
                                                                               & ((32
                                                                                 * *((_DWORD *)&this->m_Elements + 2)) >> 5)];
  v5->m_Parent = parent;
  v5->m_Right = -1;
  v5->m_Left = -1;
  v5->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    v6 = 32LL * *((int *)&this->m_Elements + 2);
    v7 = this->m_Elements.m_pMemory[parent >> SBYTE4(v6)];
    if ( isLeft )
      v7[parent & ((int)v6 >> 5)].m_Left = i;
    else
      v7[parent & ((int)v6 >> 5)].m_Right = i;
    CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F510
// Name: public: class CUtlVector<struct DmIdPair_t,class CUtlMemory<struct DmIdPair_t,int>> __near & CUtlVector<struct DmIdPair_t,class CUtlMemory<struct DmIdPair_t,int>>::operator=(class CUtlVector<struct DmIdPair_t,class CUtlMemory<struct DmIdPair_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<DmIdPair_t,CUtlMemory<DmIdPair_t,int> > *__thiscall CUtlVector<DmIdPair_t,CUtlMemory<DmIdPair_t,int>>::operator=(
        CUtlVector<DmIdPair_t,CUtlMemory<DmIdPair_t,int> > *this,
        const CUtlVector<DmIdPair_t,CUtlMemory<DmIdPair_t,int> > *other)
{
  int m_Size; // esi
  int v3; // ebx
  DmIdPair_t *v5; // edi
  DmIdPair_t *v6; // esi
  int i; // [esp+Ch] [ebp-4h]

  m_Size = other->m_Size;
  v3 = 0;
  this->m_Size = 0;
  CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>::InsertMultipleBefore(
    this,
    elem: 0,
    num: m_Size,
    pToInsert: nullptr);
  if ( m_Size > 0 )
  {
    for ( i = m_Size; i != 0; --i )
    {
      v5 = &this->m_Memory.m_pMemory[v3];
      v6 = &other->m_Memory.m_pMemory[v3];
      CopyUniqueId(src: &v6->m_oldId, pDest: &v5->m_oldId);
      CopyUniqueId(src: &v6->m_newId, pDest: &v5->m_newId);
      ++v3;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043FA70
// Name: public: int CUtlRBTree<struct CDmElementSerializationDictionary::ElementInfo_t,int,bool (*)(struct CDmElementSerializationDictionary::ElementInfo_t const __near &,struct CDmElementSerializationDictionary::ElementInfo_t const __near &),class CUtlBlockMemory<struct UtlRBTreeNode_t<struct CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Insert(struct CDmElementSerializationDictionary::ElementInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Insert(
        CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl*)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int> > *this,
        const CDmElementSerializationDictionary::ElementInfo_t *insert)
{
  const CDmElementSerializationDictionary::ElementInfo_t *v2; // ebx
  int v4; // edi
  CDmElementSerializationDictionary::ElementInfo_t *p_m_Data; // eax
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v2 = insert;
  CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::FindInsertionPosition(
    this,
    insert,
    parent: &v7,
    leftchild: (bool *)&insert);
  v4 = CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::NewNode(this);
  CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::LinkToParent(
    this,
    i: v4,
    parent: v7,
    isLeft: (bool)insert);
  ++this->m_NumElements;
  p_m_Data = &this->m_Elements.m_pMemory[v4 >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v4 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)].m_Data;
  if ( &this->m_Elements.m_pMemory[v4 >> ((unsigned __int64)*((int *)&this->m_Elements + 2) >> 27)][v4 & ((32 * *((_DWORD *)&this->m_Elements + 2)) >> 5)] != (UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *)-16 )
  {
    *(_DWORD *)&p_m_Data->m_bRoot = *(_DWORD *)&v2->m_bRoot;
    p_m_Data->m_pElement = v2->m_pElement;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0043FD90
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<class CDmAttribute __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // edi
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // eax
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 3;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    this->m_nAllocationCount = m_nAllocationCount;
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
        {
          v6 = (v5 + this->m_nAllocationCount) / 2;
          this->m_nAllocationCount = v6;
        }
        while ( (unsigned __int16)v6 < v5 );
      }
      else
      {
        this->m_nAllocationCount = m_nAllocationCount - 1;
      }
    }
    v7 = 12 * this->m_nAllocationCount;
    if ( this->m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: this->m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043FE50
// Name: protected: void CUtlRBTree<class IDmeOperator __near *,unsigned short,bool (*)(class IDmeOperator __near * const __near &,class IDmeOperator __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class IDmeOperator __near *,unsigned short>,unsigned short>>::FindInsertionPosition(class IDmeOperator __near * const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > *this,
        IDmeOperator *const *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043FF60
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_FirstFree; // cx
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Iterator_t *p_m_LastAlloc; // ebp
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // ebx
  unsigned __int16 *v8; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // ecx
  int result; // eax
  int v11; // edx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v12; // ecx
  CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Iterator_t v13; // [esp+6h] [ebp-2h] BYREF

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    p_m_LastAlloc = &this->m_LastAlloc;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else if ( (unsigned __int16)(p_m_LastAlloc->index + 1) >= m_nAllocationCount )
    {
      v5 = -1;
    }
    else
    {
      v5 = p_m_LastAlloc->index + 1;
    }
    v13.index = v5;
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>::Grow(this: &this->m_Elements, num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( p_m_LastAlloc->index >= v7 )
      {
        v13.index = (v7 > 0) - 1;
        v8 = (unsigned __int16 *)&v13;
      }
      else
      {
        v8 = (unsigned __int16 *)CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>::Next(
                                   this: &this->m_Elements,
                                   result: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Iterator_t *)&v13,
                                   it: &this->m_LastAlloc);
      }
      v6 = *v8;
      if ( *v8 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    p_m_LastAlloc->index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    result = m_FirstFree;
    v11 = m_FirstFree;
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[v11].m_Right;
    this->m_pElements = v12;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00440050
// Name: protected: void CUtlRBTree<class IDmeOperator __near *,unsigned short,bool (*)(class IDmeOperator __near * const __near &,class IDmeOperator __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class IDmeOperator __near *,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Right; // bx
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Right = CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
              this,
              i: elem)->m_Right;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Right = CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
                                             this,
                                             i: m_Right)->m_Left;
  if ( CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Right)->m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Right)->m_Left].m_Parent = elem;
  if ( m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
                                                     this,
                                                     i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else
  {
    v5 = CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Left == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Right;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00440150
// Name: protected: void CUtlRBTree<class IDmeOperator __near *,unsigned short,bool (*)(class IDmeOperator __near * const __near &,class IDmeOperator __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class IDmeOperator __near *,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Left; // di
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Left = CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
             this,
             i: elem)->m_Left;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Left = CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
                                            this,
                                            i: m_Left)->m_Right;
  if ( CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Left)->m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Left)->m_Right].m_Parent = elem;
  if ( m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
                                                    this,
                                                    i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Right == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00440250
// Name: public: CUtlRBTree<class IDmeOperator __near *,unsigned short,bool (*)(class IDmeOperator __near * const __near &,class IDmeOperator __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class IDmeOperator __near *,unsigned short>,unsigned short>>::CUtlRBTree<class IDmeOperator __near *,unsigned short,bool (*)(class IDmeOperator __near * const __near &,class IDmeOperator __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class IDmeOperator __near *,unsigned short>,unsigned short>>(int,int,bool (*const __near &)(class IDmeOperator __near * const __near &,class IDmeOperator __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl*)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short> > *__thiscall CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>(
        CUtlRBTree<CDmAttribute *,unsigned short,bool (__cdecl*)(CDmAttribute * const &,CDmAttribute * const &),CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short> > *this,
        int growSize,
        int initSize,
        bool (__cdecl **lessfunc)(CDmAttribute *const *, CDmAttribute *const *))
{
  this->m_LessFunc = *lessfunc;
  this->m_Elements.m_pMemory = nullptr;
  this->m_Elements.m_nAllocationCount = initSize;
  this->m_Elements.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Elements.m_pMemory = (UtlRBTreeNode_t<CDmAttribute *,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                     this: _g_pMemAlloc,
                                                                                     a2: 12 * initSize);
  this->m_Root = -1;
  this->m_FirstFree = -1;
  this->m_NumElements = 0;
  this->m_LastAlloc.index = -1;
  this->m_pElements = this->m_Elements.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004402C0
// Name: public: unsigned short CUtlRBTree<class IDmeOperator __near *,unsigned short,bool (*)(class IDmeOperator __near * const __near &,class IDmeOperator __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class IDmeOperator __near *,unsigned short>,unsigned short>>::Find(class IDmeOperator __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > *this,
        IDmeOperator *const *search)
{
  unsigned __int16 m_Root; // bp
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00440430
// Name: public: void CUtlRBTree<class IDmeOperator __near *,unsigned short,bool (*)(class IDmeOperator __near * const __near &,class IDmeOperator __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class IDmeOperator __near *,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  int m_nAllocationCount; // eax
  unsigned __int16 v4; // di
  int v5; // eax
  unsigned __int16 i; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    v4 = (m_nAllocationCount > 0) - 1;
    i = v4;
    if ( m_nAllocationCount > 0 )
    {
      do
      {
        if ( v4 < m_nAllocationCount
          && v4 <= index
          && CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Left != v4 )
        {
          v5 = v4;
          this->m_Elements.m_pMemory[v5].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v5].m_Left = v4;
          this->m_FirstFree = v4;
        }
        index = this->m_LastAlloc.index;
        if ( v4 == index )
          break;
        m_nAllocationCount = this->m_Elements.m_nAllocationCount;
        ++v4;
        if ( (unsigned __int16)(i + 1) >= m_nAllocationCount )
          v4 = -1;
        i = v4;
      }
      while ( v4 != 0xFFFF );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004404F0
// Name: protected: void CUtlRBTree<class IDmeOperator __near *,unsigned short,bool (*)(class IDmeOperator __near * const __near &,class IDmeOperator __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class IDmeOperator __near *,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl*)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // dx
  int v4; // eax
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v5; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeLinks_t<unsigned short> *v7; // ecx
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v8; // ecx
  unsigned __int16 v9; // di
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v10; // ecx
  unsigned __int16 v11; // cx
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v12; // edx
  unsigned __int16 v13; // dx
  UtlRBTreeLinks_t<unsigned short> *v14; // edx
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v15; // edx
  unsigned __int16 m_Right; // dx
  UtlRBTreeLinks_t<unsigned short> *v17; // ebp
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v18; // edx
  unsigned __int16 v19; // dx
  UtlRBTreeLinks_t<unsigned short> *v20; // eax
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v21; // edx
  unsigned __int16 m_Left; // dx
  UtlRBTreeLinks_t<unsigned short> *v23; // ebp
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v24; // edx
  unsigned __int16 v25; // dx
  UtlRBTreeNode_t<IDmeOperator *,unsigned short> *v26; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v5 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)&`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v7 = m_Parent == 0xFFFF
         ? &`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v8 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)&`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v10 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)&`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v12 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)&`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v14 = v13 == 0xFFFF
          ? &`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : &this->m_Elements.m_pMemory[v13];
      if ( v14->m_Left == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v15 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)&`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        v17 = m_Right == 0xFFFF
            ? &`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
            : &this->m_Elements.m_pMemory[m_Right];
        if ( v17->m_Tag != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( elem == 0xFFFF )
            v18 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)&`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[elem];
          v19 = v18->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          v20 = v19 == 0xFFFF
              ? &`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
              : &this->m_Elements.m_pMemory[v19];
          if ( v20->m_Right == elem )
          {
            elem = v9;
            CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RotateLeft(
              this,
              elem: v9);
            v9 = CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
                   this,
                   i: v9)->m_Parent;
            v11 = CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
                    this,
                    i: v9)->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v21 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)&`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[v11];
        m_Left = v21->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        v23 = m_Left == 0xFFFF
            ? &`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
            : &this->m_Elements.m_pMemory[m_Left];
        if ( v23->m_Tag != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( elem == 0xFFFF )
            v24 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)&`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[elem];
          v25 = v24->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v25 == 0xFFFF )
            v26 = (UtlRBTreeNode_t<IDmeOperator *,unsigned short> *)&`CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v26 = &this->m_Elements.m_pMemory[v25];
          if ( v26->m_Left == elem )
          {
            elem = v9;
            CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RotateRight(
              this,
              elem: v9);
            v9 = CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
                   this,
                   i: v9)->m_Parent;
            v11 = CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::Links(
                    this,
                    i: v9)->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<IDmeOperator *,unsigned short,bool (__cdecl *)(IDmeOperator * const &,IDmeOperator * const &),CUtlMemory<UtlRBTreeNode_t<IDmeOperator *,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00441100
// Name: public: CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(
        CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *m_pMemory; // eax

  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443A10
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(class CUtlSymbolTable::CStringPoolIndex const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: insert,
           i2: &this->m_Elements.m_pMemory[v6].m_Data) )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443B20
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Right; // bx
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Right = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
              this,
              i: elem)->m_Right;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Right = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                             this,
                                             i: m_Right)->m_Left;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Right)->m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Right)->m_Left].m_Parent = elem;
  if ( m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                                     this,
                                                     i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else
  {
    v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Left == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Right;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00443C20
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Left; // di
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Left = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
             this,
             i: elem)->m_Left;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Left = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                            this,
                                            i: m_Left)->m_Right;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Left)->m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Left)->m_Right].m_Parent = elem;
  if ( m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                                    this,
                                                    i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Right == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00443D60
// Name: public: CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(int,int,class CUtlSymbolTable::CLess const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *__thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        int growSize,
        int initSize,
        const CUtlSymbolTable::CLess *lessfunc)
{
  this->m_Elements.m_pMemory = nullptr;
  this->m_Elements.m_nAllocationCount = initSize;
  this->m_Elements.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12 * initSize);
  this->m_Root = -1;
  this->m_FirstFree = -1;
  this->m_NumElements = 0;
  this->m_LastAlloc.index = -1;
  this->m_pElements = this->m_Elements.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00443DC0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(class CUtlSymbolTable::CStringPoolIndex const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *search)
{
  unsigned __int16 m_Root; // bp
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: search,
           i2: &this->m_Elements.m_pMemory[v4].m_Data) )
    {
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( !CUtlSymbolTable::CLess::operator()(
              this: &this->m_LessFunc,
              i1: &this->m_Elements.m_pMemory[v4].m_Data,
              i2: search) )
        return m_Root;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00443ED0
// Name: public: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  int m_nAllocationCount; // eax
  unsigned __int16 v4; // di
  int v5; // eax
  unsigned __int16 i; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    v4 = (m_nAllocationCount > 0) - 1;
    i = v4;
    if ( m_nAllocationCount > 0 )
    {
      do
      {
        if ( v4 < m_nAllocationCount
          && v4 <= index
          && CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Left != v4 )
        {
          v5 = v4;
          this->m_Elements.m_pMemory[v5].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v5].m_Left = v4;
          this->m_FirstFree = v4;
        }
        index = this->m_LastAlloc.index;
        if ( v4 == index )
          break;
        m_nAllocationCount = this->m_Elements.m_nAllocationCount;
        ++v4;
        if ( (unsigned __int16)(i + 1) >= m_nAllocationCount )
          v4 = -1;
        i = v4;
      }
      while ( v4 != 0xFFFF );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443F90
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // dx
  int v4; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v5; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeLinks_t<unsigned short> *v7; // ecx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v8; // ecx
  unsigned __int16 v9; // di
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v10; // ecx
  unsigned __int16 v11; // cx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v12; // edx
  unsigned __int16 v13; // dx
  UtlRBTreeLinks_t<unsigned short> *v14; // edx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v15; // edx
  unsigned __int16 m_Right; // dx
  UtlRBTreeLinks_t<unsigned short> *v17; // ebp
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v18; // edx
  unsigned __int16 v19; // dx
  UtlRBTreeLinks_t<unsigned short> *v20; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v21; // edx
  unsigned __int16 m_Left; // dx
  UtlRBTreeLinks_t<unsigned short> *v23; // ebp
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v24; // edx
  unsigned __int16 v25; // dx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v26; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v5 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v7 = m_Parent == 0xFFFF
         ? &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v8 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v10 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v12 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v14 = v13 == 0xFFFF
          ? &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : &this->m_Elements.m_pMemory[v13];
      if ( v14->m_Left == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v15 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        v17 = m_Right == 0xFFFF
            ? &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
            : &this->m_Elements.m_pMemory[m_Right];
        if ( v17->m_Tag != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( elem == 0xFFFF )
            v18 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[elem];
          v19 = v18->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          v20 = v19 == 0xFFFF
              ? &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
              : &this->m_Elements.m_pMemory[v19];
          if ( v20->m_Right == elem )
          {
            elem = v9;
            CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
              this,
              elem: v9);
            v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                   this,
                   i: v9)->m_Parent;
            v11 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                    this,
                    i: v9)->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v21 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[v11];
        m_Left = v21->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        v23 = m_Left == 0xFFFF
            ? &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
            : &this->m_Elements.m_pMemory[m_Left];
        if ( v23->m_Tag != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( elem == 0xFFFF )
            v24 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[elem];
          v25 = v24->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v25 == 0xFFFF )
            v26 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v26 = &this->m_Elements.m_pMemory[v25];
          if ( v26->m_Left == elem )
          {
            elem = v9;
            CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
              this,
              elem: v9);
            v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                   this,
                   i: v9)->m_Parent;
            v11 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                    this,
                    i: v9)->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00444540
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444630
// Name: public: CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004446B0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(class CUtlSymbolTable::CStringPoolIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert)
{
  const CUtlSymbolTable::CStringPoolIndex *v2; // ebx
  unsigned __int16 v4; // di
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  unsigned __int16 v7[2]; // [esp+Ch] [ebp-4h] BYREF

  v2 = insert;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    parent: v7,
    leftchild: (bool *)&insert);
  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this);
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v4,
    parent: v7[0],
    isLeft: (bool)insert);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *v2;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00462340
// Name: public: int CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Parent(
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_491440 = -1;
    dword_491444 = -1;
    dword_491448 = 1;
  }
  if ( i == -1 )
    return dword_491444;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00462390
// Name: public: int CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::LeftChild(
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_491440 = -1;
    dword_491444 = -1;
    dword_491448 = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004623E0
// Name: public: int CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RightChild(
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_491440 = -1;
    dword_491444 = -1;
    dword_491448 = 1;
  }
  if ( i == -1 )
    return dword_491440;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00462430
// Name: protected: void CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>>::FindInsertionPosition(class CDmElement __near * const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *this,
        CDmElement *const *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_491440 = -1;
        dword_491444 = -1;
        dword_491448 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_491440 = -1;
        dword_491444 = -1;
        dword_491448 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462520
// Name: public: int CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NewNode(
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CDmElement *,int> *v11; // edx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[result].m_Right;
    this->m_pElements = v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004625F0
// Name: public: bool CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::IsLeftChild(
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *this,
        int i)
{
  int v3; // eax

  v3 = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Parent(
         this,
         i);
  if ( (`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_491440 = -1;
    dword_491444 = -1;
    dword_491448 = 1;
  }
  if ( v3 == -1 )
    return `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[v3].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00462660
// Name: protected: void CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RotateLeft(
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *this,
        int elem)
{
  int v3; // edi
  UtlRBTreeNode_t<CDmElement *,int> *v4; // eax
  UtlRBTreeNode_t<CDmElement *,int> *v5; // eax

  v3 = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RightChild(
         this,
         i: elem);
  if ( (`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_491440 = -1;
    dword_491444 = -1;
    dword_491448 = 1;
  }
  if ( v3 == -1 )
    v4 = (UtlRBTreeNode_t<CDmElement *,int> *)&`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[v3];
  this->m_Elements.m_pMemory[elem].m_Right = v4->m_Left;
  if ( (`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_491440 = -1;
    dword_491444 = -1;
    dword_491448 = 1;
  }
  if ( v3 == -1 )
    v5 = (UtlRBTreeNode_t<CDmElement *,int> *)&`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v5 = &this->m_Elements.m_pMemory[v3];
  if ( v5->m_Left != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::LeftChild(
                                 this,
                                 i: v3)].m_Parent = elem;
  if ( v3 != -1 )
    this->m_Elements.m_pMemory[v3].m_Parent = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v3;
  }
  else if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = v3;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = v3;
  }
  this->m_Elements.m_pMemory[v3].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00462790
// Name: protected: void CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RotateRight(
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *this,
        int elem)
{
  UtlRBTreeNode_t<CDmElement *,int> *v3; // eax
  int m_Left; // edi
  int v5; // eax

  if ( (`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_491440 = -1;
    dword_491444 = -1;
    dword_491448 = 1;
  }
  if ( elem == -1 )
    v3 = (UtlRBTreeNode_t<CDmElement *,int> *)&`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[elem];
  m_Left = v3->m_Left;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RightChild(
                                              this,
                                              i: v3->m_Left);
  if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RightChild(
         this,
         i: m_Left) != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RightChild(
           this,
           i: v5) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Parent(
                                   this,
                                   i: elem)].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Parent(
                                   this,
                                   i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00462A30
// Name: public: int CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>>::Find(class CDmElement __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Find(
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *this,
        CDmElement *const *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_491440 = -1;
        dword_491444 = -1;
        dword_491448 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_491440 = -1;
        dword_491444 = -1;
        dword_491448 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00462B20
// Name: public: int CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FirstInorder(
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_491440 = -1;
      dword_491444 = -1;
      dword_491448 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_491440 = -1;
      dword_491444 = -1;
      dword_491448 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00462BC0
// Name: public: int CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NextInorder(
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *this,
        int i)
{
  int v2; // esi
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int v7; // edx
  UtlRBTreeNode_t<CDmElement *,int> *v8; // ecx
  int m_Parent; // ecx
  int *v10; // ecx

  v2 = i;
  if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RightChild(
         this,
         i) == -1 )
  {
    result = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Parent(
               this,
               i);
    v7 = `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_491440 = -1;
        dword_491444 = -1;
        dword_491448 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CDmElement *,int> *)&`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v8->m_Parent;
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_491440 = -1;
        dword_491444 = -1;
        dword_491448 = 1;
      }
      v10 = m_Parent == -1
          ? &`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v10[1] != v2 )
        break;
      v2 = result;
      if ( result == -1 )
        break;
      if ( (v7 & 1) == 0 )
      {
        v7 |= 1u;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v7;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_491440 = -1;
        dword_491444 = -1;
        dword_491448 = 1;
      }
      result = this->m_Elements.m_pMemory[result].m_Parent;
    }
  }
  else
  {
    result = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_491440 = -1;
        dword_491444 = -1;
        dword_491448 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_491440 = -1;
        dword_491444 = -1;
        dword_491448 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00462D50
// Name: public: void CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *this)
{
  int index; // eax
  int v3; // esi
  int v4; // eax

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 >= 0
          && v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::LeftChild(
               this,
               i: v3) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        if ( ++v3 < 0 || v3 >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
      }
      while ( v3 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462DE0
// Name: protected: void CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::InsertRebalance(
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *this,
        int elem)
{
  int v2; // esi
  int v4; // eax
  UtlRBTreeNode_t<CDmElement *,int> *v5; // ecx
  int m_Parent; // ecx
  int *v7; // ecx
  UtlRBTreeNode_t<CDmElement *,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CDmElement *,int> *v10; // ecx
  int v11; // ebp
  UtlRBTreeNode_t<CDmElement *,int> *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  UtlRBTreeNode_t<CDmElement *,int> *v15; // ecx
  int m_Right; // ecx
  int *v17; // edx
  int v18; // edx
  UtlRBTreeNode_t<CDmElement *,int> *v19; // ecx
  int v20; // ecx
  UtlRBTreeNode_t<CDmElement *,int> *v21; // eax
  int v22; // eax
  UtlRBTreeNode_t<CDmElement *,int> *v23; // ecx
  UtlRBTreeNode_t<CDmElement *,int> *v24; // eax
  UtlRBTreeNode_t<CDmElement *,int> *v25; // ecx
  int m_Left; // ecx
  int *v27; // eax
  int v28; // eax
  UtlRBTreeNode_t<CDmElement *,int> *v29; // ecx
  UtlRBTreeNode_t<CDmElement *,int> *v30; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_491440 = -1;
        dword_491444 = -1;
        dword_491448 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CDmElement *,int> *)&`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_491440 = -1;
        dword_491444 = -1;
        dword_491448 = 1;
      }
      v7 = m_Parent == -1
         ? &`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v7[3] != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_491440 = -1;
        dword_491444 = -1;
        dword_491448 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CDmElement *,int> *)&`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_491440 = -1;
        dword_491444 = -1;
        dword_491448 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CDmElement *,int> *)&`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_491440 = -1;
        dword_491444 = -1;
        dword_491448 = 1;
      }
      if ( v9 == -1 )
        v12 = (UtlRBTreeNode_t<CDmElement *,int> *)&`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_491440 = -1;
        dword_491444 = -1;
        dword_491448 = 1;
      }
      v14 = v13 == -1
          ? &`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v13];
      if ( *v14 == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_491440 = -1;
          dword_491444 = -1;
          dword_491448 = 1;
        }
        if ( v11 == -1 )
          v15 = (UtlRBTreeNode_t<CDmElement *,int> *)&`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_491440 = -1;
          dword_491444 = -1;
          dword_491448 = 1;
        }
        v17 = m_Right == -1
            ? &`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[m_Right];
        if ( v17[3] != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_491440 = -1;
            dword_491444 = -1;
            dword_491448 = 1;
          }
          v18 = elem;
          if ( elem == -1 )
          {
            v19 = (UtlRBTreeNode_t<CDmElement *,int> *)&`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
          }
          else
          {
            v19 = &this->m_Elements.m_pMemory[elem];
            v18 = elem;
          }
          v20 = v19->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_491440 = -1;
            dword_491444 = -1;
            dword_491448 = 1;
          }
          if ( v20 == -1 )
            v21 = (UtlRBTreeNode_t<CDmElement *,int> *)&`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v21 = &this->m_Elements.m_pMemory[v20];
          if ( v21->m_Right == v18 )
          {
            elem = v9;
            CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RotateLeft(
              this,
              elem: v9);
            v22 = `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard';
            if ( (`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard'
                & 1) == 0 )
            {
              v22 = `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard'
                  | 1;
              `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
              `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_491440 = -1;
              dword_491444 = -1;
              dword_491448 = 1;
            }
            if ( v9 == -1 )
              v23 = (UtlRBTreeNode_t<CDmElement *,int> *)&`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v23 = &this->m_Elements.m_pMemory[v9];
            v9 = v23->m_Parent;
            if ( (v22 & 1) == 0 )
            {
              `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
              `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_491440 = -1;
              dword_491444 = -1;
              dword_491448 = 1;
            }
            if ( v9 == -1 )
              v24 = (UtlRBTreeNode_t<CDmElement *,int> *)&`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v24 = &this->m_Elements.m_pMemory[v9];
            v11 = v24->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RotateRight(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_491440 = -1;
          dword_491444 = -1;
          dword_491448 = 1;
        }
        if ( v11 == -1 )
          v25 = (UtlRBTreeNode_t<CDmElement *,int> *)&`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v25 = &this->m_Elements.m_pMemory[v11];
        m_Left = v25->m_Left;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_491440 = -1;
          dword_491444 = -1;
          dword_491448 = 1;
        }
        v27 = m_Left == -1
            ? &`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel
            : (int *)&this->m_Elements.m_pMemory[m_Left];
        if ( v27[3] != 0 )
        {
          if ( CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::IsLeftChild(
                 this,
                 i: elem) )
          {
            elem = v9;
            CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RotateRight(
              this,
              elem: v9);
            v28 = `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard';
            if ( (`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard'
                & 1) == 0 )
            {
              v28 = `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard'
                  | 1;
              `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
              `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_491440 = -1;
              dword_491444 = -1;
              dword_491448 = 1;
            }
            if ( v9 == -1 )
              v29 = (UtlRBTreeNode_t<CDmElement *,int> *)&`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v29 = &this->m_Elements.m_pMemory[v9];
            v9 = v29->m_Parent;
            if ( (v28 & 1) == 0 )
            {
              `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::`local static guard' = v28 | 1;
              `CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel = -1;
              dword_491440 = -1;
              dword_491444 = -1;
              dword_491448 = 1;
            }
            if ( v9 == -1 )
              v30 = (UtlRBTreeNode_t<CDmElement *,int> *)&`CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v30 = &this->m_Elements.m_pMemory[v9];
            v11 = v30->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RotateLeft(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00463320
// Name: protected: void CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::LinkToParent(
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CDmElement *,int> *v4; // eax
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00463390
// Name: public: CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>>::~CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::~CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>(
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *this)
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004633F0
// Name: public: int CUtlRBTree<class CDmElement __near *,int,bool (*)(class CDmElement __near * const __near &,class CDmElement __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CDmElement __near *,int>,int>>::Insert(class CDmElement __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::Insert(
        CUtlRBTree<CDmElement *,int,bool (__cdecl*)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> > *this,
        CDmElement *const *insert)
{
  CDmElement *const *v2; // ebx
  int v4; // edi
  UtlRBTreeNode_t<CDmElement *,int> *m_pMemory; // edx
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v2 = insert;
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::FindInsertionPosition(
    this,
    insert,
    parent: &v7,
    leftchild: (bool *)&insert);
  v4 = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NewNode(this);
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::LinkToParent(
    this,
    i: v4,
    parent: v7,
    isLeft: (bool)insert);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CDmElement *,int> *)-16 )
    m_pMemory[v4].m_Data = *v2;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00463CB0
// Name: public: class CDmAttribute __near * CDmElement::SetValue<class Quaternion>(char const __near *,class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<Quaternion>(
        CDmElement *this,
        const char *pAttributeName,
        const Quaternion *value)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v5 = (Attribute->m_nFlags & 0x1F) == 13 ? Attribute : nullptr;
  else
    v5 = CDmElement::CreateAttribute(this, pAttributeName, type: AT_QUATERNION);
  if ( v5 == nullptr )
    return nullptr;
  CDmAttribute::SetValue<Quaternion>(this: v5, value);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00463D10
// Name: public: class Vector const __near & CDmElement::GetValue<class Vector>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmElement::GetValue<Vector>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Vector>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<Vector>(this: Attribute);
  else
    return &`CDmElement::GetValue<Vector>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00466370
// Name: public: class CDmAttribute __near * CDmElement::SetValue<class Color>(char const __near *,class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<Color>(CDmElement *this, const char *pAttributeName, const Color *value)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v5 = (Attribute->m_nFlags & 0x1F) == 8 ? Attribute : nullptr;
  else
    v5 = CDmElement::CreateAttribute(this, pAttributeName, type: AT_COLOR);
  if ( v5 == nullptr )
    return nullptr;
  CDmAttribute::SetValue<Color>(this: v5, value);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004663D0
// Name: public: class CDmAttribute __near * CDmElement::SetValue<class Vector4D>(char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<Vector4D>(
        CDmElement *this,
        const char *pAttributeName,
        const Vector4D *value)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v5 = (Attribute->m_nFlags & 0x1F) == 11 ? Attribute : nullptr;
  else
    v5 = CDmElement::CreateAttribute(this, pAttributeName, type: AT_VECTOR4);
  if ( v5 == nullptr )
    return nullptr;
  CDmAttribute::SetValue<Vector4D>(this: v5, value);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00466430
// Name: public: class CDmAttribute __near * CDmElement::SetValue<class Vector>(char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<Vector>(
        CDmElement *this,
        const char *pAttributeName,
        const Vector *value)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v5 = (Attribute->m_nFlags & 0x1F) == 10 ? Attribute : nullptr;
  else
    v5 = CDmElement::CreateAttribute(this, pAttributeName, type: AT_VECTOR3);
  if ( v5 == nullptr )
    return nullptr;
  CDmAttribute::SetValue<Vector>(this: v5, value);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00466490
// Name: public: class CDmAttribute __near * CDmElement::SetValue<class QAngle>(char const __near *,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<QAngle>(
        CDmElement *this,
        const char *pAttributeName,
        const QAngle *value)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v5 = (Attribute->m_nFlags & 0x1F) == 12 ? Attribute : nullptr;
  else
    v5 = CDmElement::CreateAttribute(this, pAttributeName, type: AT_QANGLE);
  if ( v5 == nullptr )
    return nullptr;
  CDmAttribute::SetValue<QAngle>(this: v5, value);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00466940
// Name: public: class CDmAttribute __near * CDmElement::SetValue<char const>(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<char const>(
        CDmElement *this,
        const char *pAttributeName,
        const char *pValue)
{
  int v4; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  CUtlString str; // [esp+4h] [ebp-14h] BYREF

  if ( pValue != nullptr )
    v4 = strlen(pValue) + 1;
  else
    v4 = 0;
  CUtlString::CUtlString(
    this: (CUtlString *)&str.m_Storage.m_Memory.m_nAllocationCount,
    pMemory: pValue,
    nSizeInBytes: v4);
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) == 5 ? Attribute : nullptr;
  else
    v6 = CDmElement::CreateAttribute(this, pAttributeName, type: AT_STRING);
  if ( v6 != nullptr )
    CDmAttribute::SetValue<CUtlString>(this: v6, value: (const CUtlString *)&str.m_Storage.m_Memory.m_nAllocationCount);
  else
    v6 = nullptr;
  if ( str.m_Storage.m_nActualLength >= 0 && str.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)str.m_Storage.m_Memory.m_nAllocationCount);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x00467AB0
// Name: public: class CDmAttribute __near * CDmElement::SetValue<class Vector2D>(char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<Vector2D>(
        CDmElement *this,
        const char *pAttributeName,
        const Vector2D *value)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v5 = (Attribute->m_nFlags & 0x1F) == 9 ? Attribute : nullptr;
  else
    v5 = CDmElement::CreateAttribute(this, pAttributeName, type: AT_VECTOR2);
  if ( v5 == nullptr )
    return nullptr;
  CDmAttribute::SetValue<Vector2D>(this: v5, value);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00467B10
// Name: public: class CDmAttribute __near * CDmElement::SetValue<class VMatrix>(char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<VMatrix>(
        CDmElement *this,
        const char *pAttributeName,
        const VMatrix *value)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v5 = (Attribute->m_nFlags & 0x1F) == 14 ? Attribute : nullptr;
  else
    v5 = CDmElement::CreateAttribute(this, pAttributeName, type: AT_VMATRIX);
  if ( v5 == nullptr )
    return nullptr;
  CDmAttribute::SetValue<VMatrix>(this: v5, value);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00401830
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}
