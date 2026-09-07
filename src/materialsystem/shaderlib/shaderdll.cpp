// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderlib/shaderdll.cpp
// Functions: 11
// ============================================================

#include "materialsystem\shaderlib\shaderdll.h"

//------------------------------------------------------------------------------
// Address: 0x1004A020
// Name: public: virtual int CShaderDLL::ShaderComboSemanticsCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderDLL::ShaderComboSemanticsCount(CShaderDLL *this)
{
  return this->m_ShaderComboSemantics.m_ElementCount;
}

//------------------------------------------------------------------------------
// Address: 0x10252320
// Name: public: virtual bool CShaderDLL::Connect(void __near * (*)(char const __near *,int __near *),bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CShaderDLL::Connect(
        CShaderDLL *this,
        void *(__cdecl *factory)(const char *, int *),
        bool bIsMaterialSystem)
{
  g_pHardwareConfig = (IMaterialSystemHardwareConfig *)((int (__thiscall *)(CShaderDLL *, const char *, _DWORD))factory)(
                                                         a1: this,
                                                         a2: "MaterialSystemHardwareConfig013",
                                                         a3: 0);
  g_pConfig = (const MaterialSystem_Config_t *)factory(a1: "VMaterialSystemConfig004", a2: nullptr);
  g_pSLShaderSystem = (IShaderSystem *)factory(a1: "ShaderSystem002", a2: nullptr);
  if ( !bIsMaterialSystem )
  {
    ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
    InitShaderLibCVars(cvarFactory: factory);
  }
  return g_pConfig != nullptr && g_pHardwareConfig != nullptr && g_pSLShaderSystem != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102523A0
// Name: public: virtual void CShaderDLL::Disconnect(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDLL::Disconnect(CShaderDLL *this, bool bIsMaterialSystem)
{
  if ( !bIsMaterialSystem )
  {
    ConVar_Unregister();
    DisconnectTier1Libraries();
  }
  g_pHardwareConfig = nullptr;
  g_pConfig = nullptr;
  g_pSLShaderSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102523E0
// Name: public: virtual bool CShaderDLL::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderDLL::Connect(CShaderDLL *this, void *(__cdecl *factory)(const char *, int *))
{
  return this->Connect(this, a2: factory, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10252400
// Name: public: virtual void CShaderDLL::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDLL::Disconnect(CShaderDLL *this)
{
  this->Disconnect(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x102524D0
// Name: public: virtual class IShader __near * CShaderDLL::GetShader(int)
// Source: json
//------------------------------------------------------------------------------
IShader *__thiscall CShaderDLL::GetShader(CShaderDLL *this, int nShader)
{
  if ( nShader < 0 || nShader >= this->m_ShaderList.m_Size )
    return nullptr;
  else
    return this->m_ShaderList.m_Memory.m_pMemory[nShader];
}

//------------------------------------------------------------------------------
// Address: 0x102524F0
// Name: public: virtual struct ShaderComboSemantics_t const __near * CShaderDLL::GetComboSemantics(int)
// Source: json
//------------------------------------------------------------------------------
const ShaderComboSemantics_t *__thiscall CShaderDLL::GetComboSemantics(CShaderDLL *this, int n)
{
  if ( n < 0 || n >= this->m_ShaderComboSemantics.m_ElementCount )
    return nullptr;
  else
    return this->m_ShaderComboSemantics.m_Memory.m_pMemory[(unsigned __int16)n].m_Element;
}

//------------------------------------------------------------------------------
// Address: 0x102527B0
// Name: public: CShaderDLL::CShaderDLL(void)
// Source: json
//------------------------------------------------------------------------------
CShaderDLL *__thiscall CShaderDLL::CShaderDLL(CShaderDLL *this)
{
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *m_pMemory; // eax

  this->IShaderDLL::__vftable = (IShaderDLL_vtbl *)&IShaderDLL::`vftable';
  this->IShaderDLLInternal::__vftable = (CShaderDLL_vtbl *)&CShaderDLL::`vftable'{for `IShaderDLLInternal'};
  this->IShaderDLL::__vftable = (IShaderDLL_vtbl *)&CShaderDLL::`vftable'{for `IShaderDLL'};
  this->m_ShaderList.m_Memory.m_pMemory = nullptr;
  this->m_ShaderList.m_Memory.m_nAllocationCount = 0;
  this->m_ShaderList.m_Memory.m_nGrowSize = 0;
  this->m_ShaderList.m_Size = 0;
  this->m_ShaderList.m_pElements = nullptr;
  this->m_ShaderComboSemantics.m_Memory.m_pMemory = nullptr;
  this->m_ShaderComboSemantics.m_Memory.m_nAllocationCount = 0;
  this->m_ShaderComboSemantics.m_Memory.m_nGrowSize = 0;
  this->m_ShaderComboSemantics.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_ShaderComboSemantics.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_ShaderComboSemantics.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_ShaderComboSemantics.m_Head = -1;
  this->m_ShaderComboSemantics.m_NumAlloced = 0;
  this->m_ShaderComboSemantics.m_pElements = m_pMemory;
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: true,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10252840
// Name: public: virtual void CShaderDLL::InsertShader(class IShader __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDLL::InsertShader(CShaderDLL *this, IShader *pShader)
{
  IShader **m_pMemory; // eax
  CUtlMemory<S3RGBA,int> *v3; // esi
  int m_nGrowSize; // edi
  S3RGBA *v5; // ecx
  int v6; // eax
  S3RGBA *v7; // eax

  m_pMemory = this->m_ShaderList.m_Memory.m_pMemory;
  v3 = (CUtlMemory<S3RGBA,int> *)&this->IShaderDLL;
  m_nGrowSize = this->m_ShaderList.m_Memory.m_nGrowSize;
  if ( m_nGrowSize + 1 > (int)m_pMemory )
    CUtlMemory<IMaterialVar *,int>::Grow(this: v3, num: m_nGrowSize - (_DWORD)m_pMemory + 1);
  ++v3[1].m_pMemory;
  v5 = v3->m_pMemory;
  v6 = (int)v3[1].m_pMemory - m_nGrowSize - 1;
  v3[1].m_nAllocationCount = (int)v3->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &v5[m_nGrowSize + 1], src: &v5[m_nGrowSize], count: 4 * v6);
  v7 = &v3->m_pMemory[m_nGrowSize];
  if ( v7 != nullptr )
    *v7 = (S3RGBA)pShader;
}

//------------------------------------------------------------------------------
// Address: 0x102528A0
// Name: class IShaderDLLInternal __near * GetShaderDLLInternal(void)
// Source: json
//------------------------------------------------------------------------------
CShaderDLL *__cdecl GetShaderDLLInternal()
{
  CShaderDLL *result; // eax
  CShaderDLL *v1; // eax

  result = s_pShaderDLL;
  if ( s_pShaderDLL == nullptr )
  {
    v1 = (CShaderDLL *)MemAlloc_Alloc(nSize: 0x38u);
    if ( v1 != nullptr )
    {
      result = CShaderDLL::CShaderDLL(this: v1);
      s_pShaderDLL = result;
    }
    else
    {
      s_pShaderDLL = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102528D0
// Name: public: virtual void CShaderDLL::AddShaderComboInformation(struct ShaderComboSemantics_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDLL::AddShaderComboInformation(CShaderDLL *this, IShader *pSemantics)
{
  IShader ***p_m_pElements; // esi
  int v3; // edi
  IShader **v4; // eax

  p_m_pElements = &this->m_ShaderList.m_pElements;
  v3 = CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::AllocInternal(
         this: (CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> > *)&this->m_ShaderList.m_pElements,
         multilist: false);
  if ( (_WORD)v3 != 0xFFFF )
  {
    CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> > *)p_m_pElements,
      before: 0xFFFFu,
      elem: v3);
    v4 = &(*p_m_pElements)[2 * v3];
    if ( v4 != nullptr )
      *v4 = pSemantics;
  }
}

// ============================================================
// Overlay from stdshader_dbg (Missing functions)
// ============================================================
namespace stdshader_dbg {

//------------------------------------------------------------------------------
// Address: 0x100034F0
// Name: public: virtual bool CShaderDLL::Connect(void __near * (*)(char const __near *,int __near *),bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CShaderDLL::Connect(
        CShaderDLL *this,
        void *(__cdecl *factory)(const char *, int *),
        bool bIsMaterialSystem)
{
  g_pHardwareConfig = (IMaterialSystemHardwareConfig *)((int (__thiscall *)(CShaderDLL *, const char *, _DWORD))factory)(
                                                         a1: this,
                                                         a2: "MaterialSystemHardwareConfig013",
                                                         a3: 0);
  g_pConfig = (const MaterialSystem_Config_t *)factory(a1: "VMaterialSystemConfig004", a2: nullptr);
  g_pSLShaderSystem = (IShaderSystem *)factory(a1: "ShaderSystem002", a2: nullptr);
  if ( !bIsMaterialSystem )
  {
    ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
    InitShaderLibCVars(cvarFactory: factory);
  }
  return g_pConfig != nullptr && g_pHardwareConfig != nullptr && g_pSLShaderSystem != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10003570
// Name: public: virtual void CShaderDLL::Disconnect(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDLL::Disconnect(CShaderDLL *this, bool bIsMaterialSystem)
{
  if ( !bIsMaterialSystem )
  {
    ConVar_Unregister();
    DisconnectTier1Libraries();
  }
  g_pHardwareConfig = nullptr;
  g_pConfig = nullptr;
  g_pSLShaderSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100035B0
// Name: public: virtual bool CShaderDLL::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderDLL::Connect(CShaderDLL *this, void *(__cdecl *factory)(const char *, int *))
{
  return this->Connect(this, a2: factory, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100035D0
// Name: public: virtual void CShaderDLL::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDLL::Disconnect(CShaderDLL *this)
{
  this->Disconnect(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100035F0
// Name: public: virtual int CShaderDLL::ShaderComboSemanticsCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderDLL::ShaderComboSemanticsCount(CShaderDLL *this)
{
  return this->m_ShaderComboSemantics.m_ElementCount;
}

//------------------------------------------------------------------------------
// Address: 0x100036B0
// Name: public: virtual class IShader __near * CShaderDLL::GetShader(int)
// Source: json
//------------------------------------------------------------------------------
IShader *__thiscall CShaderDLL::GetShader(CShaderDLL *this, int nShader)
{
  if ( nShader < 0 || nShader >= this->m_ShaderList.m_Size )
    return nullptr;
  else
    return this->m_ShaderList.m_Memory.m_pMemory[nShader];
}

//------------------------------------------------------------------------------
// Address: 0x100036D0
// Name: public: virtual struct ShaderComboSemantics_t const __near * CShaderDLL::GetComboSemantics(int)
// Source: json
//------------------------------------------------------------------------------
const ShaderComboSemantics_t *__thiscall CShaderDLL::GetComboSemantics(CShaderDLL *this, int n)
{
  if ( n < 0 || n >= this->m_ShaderComboSemantics.m_ElementCount )
    return nullptr;
  else
    return this->m_ShaderComboSemantics.m_Memory.m_pMemory[(unsigned __int16)n].m_Element;
}

//------------------------------------------------------------------------------
// Address: 0x10003700
// Name: protected: unsigned short CUtlLinkedList<struct ShaderComboSemantics_t const __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct ShaderComboSemantics_t const __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10003880
// Name: public: void CUtlLinkedList<struct ShaderComboSemantics_t const __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct ShaderComboSemantics_t const __near *,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *m_pMemory; // eax
  int m_Previous; // edi
  unsigned __int16 *p_m_Next; // edx
  unsigned __int16 v7; // cx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_pMemory[elem].m_Previous != elem )
    {
      m_Previous = m_pMemory[elem].m_Previous;
      p_m_Next = &m_pMemory[elem].m_Next;
      v7 = *p_m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = v7;
      }
      else
      {
        m_pMemory[m_Previous].m_Next = v7;
        v2 = elem;
      }
      if ( v7 == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[v7].m_Previous = m_Previous;
      *p_m_Next = v2;
      --this->m_ElementCount;
      m_pMemory[elem].m_Previous = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003910
// Name: public: void CUtlLinkedList<struct ShaderComboSemantics_t const __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct ShaderComboSemantics_t const __near *,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *v7; // ebx

  CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003990
// Name: public: CShaderDLL::CShaderDLL(void)
// Source: json
//------------------------------------------------------------------------------
CShaderDLL *__thiscall CShaderDLL::CShaderDLL(CShaderDLL *this)
{
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *m_pMemory; // eax

  this->IShaderDLL::__vftable = (IShaderDLL_vtbl *)&IShaderDLL::`vftable';
  this->IShaderDLLInternal::__vftable = (CShaderDLL_vtbl *)&CShaderDLL::`vftable'{for `IShaderDLLInternal'};
  this->IShaderDLL::__vftable = (IShaderDLL_vtbl *)&CShaderDLL::`vftable'{for `IShaderDLL'};
  this->m_ShaderList.m_Memory.m_pMemory = nullptr;
  this->m_ShaderList.m_Memory.m_nAllocationCount = 0;
  this->m_ShaderList.m_Memory.m_nGrowSize = 0;
  this->m_ShaderList.m_Size = 0;
  this->m_ShaderList.m_pElements = nullptr;
  this->m_ShaderComboSemantics.m_Memory.m_pMemory = nullptr;
  this->m_ShaderComboSemantics.m_Memory.m_nAllocationCount = 0;
  this->m_ShaderComboSemantics.m_Memory.m_nGrowSize = 0;
  this->m_ShaderComboSemantics.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_ShaderComboSemantics.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_ShaderComboSemantics.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_ShaderComboSemantics.m_Head = -1;
  this->m_ShaderComboSemantics.m_NumAlloced = 0;
  this->m_ShaderComboSemantics.m_pElements = m_pMemory;
  MathLib_Init(gamma: 2.2, texGamma: 2.2, brightness: 0.0, overbright: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10003A20
// Name: public: virtual void CShaderDLL::InsertShader(class IShader __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDLL::InsertShader(CShaderDLL *this, IShader *pShader)
{
  IShader **m_pMemory; // eax
  CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *v3; // esi
  int m_nGrowSize; // edi
  void (__cdecl **v5)(IConVar *, const char *, float); // ecx
  int v6; // eax
  void (__cdecl **v7)(IConVar *, const char *, float); // eax

  m_pMemory = this->m_ShaderList.m_Memory.m_pMemory;
  v3 = (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&this->IShaderDLL;
  m_nGrowSize = this->m_ShaderList.m_Memory.m_nGrowSize;
  if ( m_nGrowSize + 1 > (int)m_pMemory )
    CUtlMemory<DebugDrawEnvmapMask::CShaderParam *,int>::Grow(this: v3, num: m_nGrowSize - (_DWORD)m_pMemory + 1);
  ++v3[1].m_pMemory;
  v5 = v3->m_pMemory;
  v6 = (int)v3[1].m_pMemory - m_nGrowSize - 1;
  v3[1].m_nAllocationCount = (int)v3->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &v5[m_nGrowSize + 1], src: &v5[m_nGrowSize], count: 4 * v6);
  v7 = &v3->m_pMemory[m_nGrowSize];
  if ( v7 != nullptr )
    *v7 = (void (__cdecl *)(IConVar *, const char *, float))pShader;
}

//------------------------------------------------------------------------------
// Address: 0x10003A80
// Name: class IShaderDLL __near * GetShaderDLL(void)
// Source: json
//------------------------------------------------------------------------------
IShaderDLL *__cdecl GetShaderDLL()
{
  CShaderDLL *v0; // eax
  CShaderDLL *v1; // eax

  v0 = s_pShaderDLL;
  if ( s_pShaderDLL != nullptr )
    return &v0->IShaderDLL;
  v1 = (CShaderDLL *)operator new(nSize: 0x38u);
  if ( v1 != nullptr )
  {
    v0 = CShaderDLL::CShaderDLL(this: v1);
    s_pShaderDLL = v0;
    if ( v0 != nullptr )
      return &v0->IShaderDLL;
  }
  else
  {
    s_pShaderDLL = nullptr;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10003AC0
// Name: class IShaderDLLInternal __near * GetShaderDLLInternal(void)
// Source: json
//------------------------------------------------------------------------------
CShaderDLL *__cdecl GetShaderDLLInternal()
{
  CShaderDLL *result; // eax
  CShaderDLL *v1; // eax

  result = s_pShaderDLL;
  if ( s_pShaderDLL == nullptr )
  {
    v1 = (CShaderDLL *)operator new(nSize: 0x38u);
    if ( v1 != nullptr )
    {
      result = CShaderDLL::CShaderDLL(this: v1);
      s_pShaderDLL = result;
    }
    else
    {
      s_pShaderDLL = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003AF0
// Name: public: virtual void CShaderDLL::AddShaderComboInformation(struct ShaderComboSemantics_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDLL::AddShaderComboInformation(CShaderDLL *this, IShader *pSemantics)
{
  IShader ***p_m_pElements; // esi
  int v3; // edi
  IShader **v4; // eax

  p_m_pElements = &this->m_ShaderList.m_pElements;
  v3 = (unsigned __int16)CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::AllocInternal(
                           this: (CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> > *)&this->m_ShaderList.m_pElements,
                           multilist: false);
  if ( (_WORD)v3 != 0xFFFF )
  {
    CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> > *)p_m_pElements,
      before: 0xFFFFu,
      elem: v3);
    v4 = &(*p_m_pElements)[2 * v3];
    if ( v4 != nullptr )
      *v4 = pSemantics;
  }
}

} // namespace stdshader_dbg

// ============================================================
// Overlay from stdshader_dx9 (Missing functions)
// ============================================================
namespace stdshader_dx9 {

//------------------------------------------------------------------------------
// Address: 0x10049410
// Name: public: virtual bool CShaderDLL::Connect(void __near * (*)(char const __near *,int __near *),bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CShaderDLL::Connect(
        CShaderDLL *this,
        void *(__cdecl *factory)(const char *, int *),
        bool bIsMaterialSystem)
{
  g_pHardwareConfig = (IMaterialSystemHardwareConfig *)((int (__thiscall *)(CShaderDLL *, const char *, _DWORD))factory)(
                                                         a1: this,
                                                         a2: "MaterialSystemHardwareConfig013",
                                                         a3: 0);
  g_pConfig = (const MaterialSystem_Config_t *)factory(a1: "VMaterialSystemConfig004", a2: nullptr);
  g_pSLShaderSystem = (IShaderSystem *)factory(a1: "ShaderSystem002", a2: nullptr);
  if ( !bIsMaterialSystem )
  {
    ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
    InitShaderLibCVars(cvarFactory: factory);
  }
  return g_pConfig != nullptr && g_pHardwareConfig != nullptr && g_pSLShaderSystem != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10049490
// Name: public: virtual void CShaderDLL::Disconnect(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDLL::Disconnect(CShaderDLL *this, bool bIsMaterialSystem)
{
  if ( !bIsMaterialSystem )
  {
    ConVar_Unregister();
    DisconnectTier1Libraries();
  }
  g_pHardwareConfig = nullptr;
  g_pConfig = nullptr;
  g_pSLShaderSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100494D0
// Name: public: virtual bool CShaderDLL::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderDLL::Connect(CShaderDLL *this, void *(__cdecl *factory)(const char *, int *))
{
  return this->Connect(this, a2: factory, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100494F0
// Name: public: virtual void CShaderDLL::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDLL::Disconnect(CShaderDLL *this)
{
  this->Disconnect(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10049510
// Name: public: virtual int CShaderDLL::ShaderComboSemanticsCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderDLL::ShaderComboSemanticsCount(CShaderDLL *this)
{
  return this->m_ShaderComboSemantics.m_ElementCount;
}

//------------------------------------------------------------------------------
// Address: 0x100495D0
// Name: public: virtual class IShader __near * CShaderDLL::GetShader(int)
// Source: json
//------------------------------------------------------------------------------
IShader *__thiscall CShaderDLL::GetShader(CShaderDLL *this, int nShader)
{
  if ( nShader < 0 || nShader >= this->m_ShaderList.m_Size )
    return nullptr;
  else
    return this->m_ShaderList.m_Memory.m_pMemory[nShader];
}

//------------------------------------------------------------------------------
// Address: 0x100495F0
// Name: public: virtual struct ShaderComboSemantics_t const __near * CShaderDLL::GetComboSemantics(int)
// Source: json
//------------------------------------------------------------------------------
const ShaderComboSemantics_t *__thiscall CShaderDLL::GetComboSemantics(CShaderDLL *this, int n)
{
  if ( n < 0 || n >= this->m_ShaderComboSemantics.m_ElementCount )
    return nullptr;
  else
    return this->m_ShaderComboSemantics.m_Memory.m_pMemory[(unsigned __int16)n].m_Element;
}

//------------------------------------------------------------------------------
// Address: 0x10049620
// Name: protected: unsigned short CUtlLinkedList<struct ShaderComboSemantics_t const __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct ShaderComboSemantics_t const __near *,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100497A0
// Name: public: void CUtlLinkedList<struct ShaderComboSemantics_t const __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct ShaderComboSemantics_t const __near *,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *m_pMemory; // eax
  int m_Previous; // edi
  unsigned __int16 *p_m_Next; // edx
  unsigned __int16 v7; // cx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_pMemory[elem].m_Previous != elem )
    {
      m_Previous = m_pMemory[elem].m_Previous;
      p_m_Next = &m_pMemory[elem].m_Next;
      v7 = *p_m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = v7;
      }
      else
      {
        m_pMemory[m_Previous].m_Next = v7;
        v2 = elem;
      }
      if ( v7 == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[v7].m_Previous = m_Previous;
      *p_m_Next = v2;
      --this->m_ElementCount;
      m_pMemory[elem].m_Previous = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049830
// Name: public: void CUtlLinkedList<struct ShaderComboSemantics_t const __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct ShaderComboSemantics_t const __near *,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *v7; // ebx

  CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100498B0
// Name: public: CShaderDLL::CShaderDLL(void)
// Source: json
//------------------------------------------------------------------------------
CShaderDLL *__thiscall CShaderDLL::CShaderDLL(CShaderDLL *this)
{
  UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short> *m_pMemory; // eax

  this->IShaderDLL::__vftable = (IShaderDLL_vtbl *)&IShaderDLL::`vftable';
  this->IShaderDLLInternal::__vftable = (CShaderDLL_vtbl *)&CShaderDLL::`vftable'{for `IShaderDLLInternal'};
  this->IShaderDLL::__vftable = (IShaderDLL_vtbl *)&CShaderDLL::`vftable'{for `IShaderDLL'};
  this->m_ShaderList.m_Memory.m_pMemory = nullptr;
  this->m_ShaderList.m_Memory.m_nAllocationCount = 0;
  this->m_ShaderList.m_Memory.m_nGrowSize = 0;
  this->m_ShaderList.m_Size = 0;
  this->m_ShaderList.m_pElements = nullptr;
  this->m_ShaderComboSemantics.m_Memory.m_pMemory = nullptr;
  this->m_ShaderComboSemantics.m_Memory.m_nAllocationCount = 0;
  this->m_ShaderComboSemantics.m_Memory.m_nGrowSize = 0;
  this->m_ShaderComboSemantics.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_ShaderComboSemantics.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_ShaderComboSemantics.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_ShaderComboSemantics.m_Head = -1;
  this->m_ShaderComboSemantics.m_NumAlloced = 0;
  this->m_ShaderComboSemantics.m_pElements = m_pMemory;
  MathLib_Init(gamma: 2.2, texGamma: 2.2, brightness: 0.0, overbright: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10049940
// Name: public: virtual void CShaderDLL::InsertShader(class IShader __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDLL::InsertShader(CShaderDLL *this, IShader *pShader)
{
  IShader **m_pMemory; // eax
  CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *v3; // esi
  int m_nGrowSize; // edi
  void (__cdecl **v5)(IConVar *, const char *, float); // ecx
  int v6; // eax
  void (__cdecl **v7)(IConVar *, const char *, float); // eax

  m_pMemory = this->m_ShaderList.m_Memory.m_pMemory;
  v3 = (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&this->IShaderDLL;
  m_nGrowSize = this->m_ShaderList.m_Memory.m_nGrowSize;
  if ( m_nGrowSize + 1 > (int)m_pMemory )
    CUtlMemory<ParticleSphere_DX9::CShaderParam *,int>::Grow(this: v3, num: m_nGrowSize - (_DWORD)m_pMemory + 1);
  ++v3[1].m_pMemory;
  v5 = v3->m_pMemory;
  v6 = (int)v3[1].m_pMemory - m_nGrowSize - 1;
  v3[1].m_nAllocationCount = (int)v3->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &v5[m_nGrowSize + 1], src: &v5[m_nGrowSize], count: 4 * v6);
  v7 = &v3->m_pMemory[m_nGrowSize];
  if ( v7 != nullptr )
    *v7 = (void (__cdecl *)(IConVar *, const char *, float))pShader;
}

//------------------------------------------------------------------------------
// Address: 0x100499A0
// Name: class IShaderDLL __near * GetShaderDLL(void)
// Source: json
//------------------------------------------------------------------------------
IShaderDLL *__cdecl GetShaderDLL()
{
  CShaderDLL *v0; // eax
  CShaderDLL *v1; // eax

  v0 = s_pShaderDLL;
  if ( s_pShaderDLL != nullptr )
    return &v0->IShaderDLL;
  v1 = (CShaderDLL *)operator new(nSize: 0x38u);
  if ( v1 != nullptr )
  {
    v0 = CShaderDLL::CShaderDLL(this: v1);
    s_pShaderDLL = v0;
    if ( v0 != nullptr )
      return &v0->IShaderDLL;
  }
  else
  {
    s_pShaderDLL = nullptr;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100499E0
// Name: class IShaderDLLInternal __near * GetShaderDLLInternal(void)
// Source: json
//------------------------------------------------------------------------------
CShaderDLL *__cdecl GetShaderDLLInternal()
{
  CShaderDLL *result; // eax
  CShaderDLL *v1; // eax

  result = s_pShaderDLL;
  if ( s_pShaderDLL == nullptr )
  {
    v1 = (CShaderDLL *)operator new(nSize: 0x38u);
    if ( v1 != nullptr )
    {
      result = CShaderDLL::CShaderDLL(this: v1);
      s_pShaderDLL = result;
    }
    else
    {
      s_pShaderDLL = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10049A10
// Name: public: virtual void CShaderDLL::AddShaderComboInformation(struct ShaderComboSemantics_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderDLL::AddShaderComboInformation(CShaderDLL *this, IShader *pSemantics)
{
  IShader ***p_m_pElements; // esi
  int v3; // edi
  IShader **v4; // eax

  p_m_pElements = &this->m_ShaderList.m_pElements;
  v3 = (unsigned __int16)CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::AllocInternal(
                           this: (CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> > *)&this->m_ShaderList.m_pElements,
                           multilist: false);
  if ( (_WORD)v3 != 0xFFFF )
  {
    CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<ShaderComboSemantics_t const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<ShaderComboSemantics_t const *,unsigned short>,unsigned short> > *)p_m_pElements,
      before: 0xFFFFu,
      elem: v3);
    v4 = &(*p_m_pElements)[2 * v3];
    if ( v4 != nullptr )
      *v4 = pSemantics;
  }
}

} // namespace stdshader_dx9
