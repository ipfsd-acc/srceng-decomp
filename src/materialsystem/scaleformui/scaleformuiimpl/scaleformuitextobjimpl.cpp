// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/scaleformuiimpl/scaleformuitextobjimpl.cpp
// Functions: 15
// ============================================================

#include "materialsystem\scaleformui\scaleformuiimpl\scaleformuitextobjimpl.h"

//------------------------------------------------------------------------------
// Address: 0x10013D60
// Name: public: GFxValue::GFxValue(class GFxValue const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall GFxValue::GFxValue(GFxValue *this, const GFxValue *src)
{
  CStringPool *pObjectInterface; // ecx

  this->pObjectInterface = nullptr;
  this->Type = src->Type;
  this->Value.NValue = src->Value.NValue;
  if ( (src->Type & 0x40) != 0 )
  {
    pObjectInterface = (CStringPool *)src->pObjectInterface;
    this->pObjectInterface = src->pObjectInterface;
    GFxValue::ObjectInterface::ObjectAddRef(this: pObjectInterface, val: (StringPoolCase_t)this);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10013DE0
// Name: public: virtual class ISFTextObject __near * ScaleformUIImpl::TextObject_MakeTextObjectFromMember(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
ISFTextObject *__thiscall ScaleformUIImpl::TextObject_MakeTextObjectFromMember(
        ScaleformUIImpl *this,
        CStringPool **value,
        const char *pName)
{
  ISFTextObject *v4; // esi
  GFxValue member; // [esp+4h] [ebp-1Ch] BYREF
  int v7; // [esp+1Ch] [ebp-4h]

  member.pObjectInterface = nullptr;
  member.Type = VT_Undefined;
  v7 = 0;
  if ( (unsigned __int8)GFxValue::ObjectInterface::GetMember(result: value[2]) != 0 )
  {
    v4 = this->TextObject_MakeTextObject(this, a2: &member);
    v7 = -1;
    if ( (member.Type & 0x40) != 0 )
      GFxValue::ObjectInterface::ObjectRelease(
        this: (CStringPool *)member.pObjectInterface,
        val: (StringPoolCase_t)&member);
    return v4;
  }
  else
  {
    v7 = -1;
    if ( (member.Type & 0x40) != 0 )
      GFxValue::ObjectInterface::ObjectRelease(
        this: (CStringPool *)member.pObjectInterface,
        val: (StringPoolCase_t)&member);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014060
// Name: public: virtual void TextBoxArrayVisitor::Visit(unsigned int,class GFxValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TextBoxArrayVisitor::Visit(TextBoxArrayVisitor *this, unsigned int idx, const GFxValue *val)
{
  CUtlVector<GFxValue,CUtlMemory<GFxValue,int>>::InsertBefore(
    this: this->m_pTextBoxes,
    elem: this->m_pTextBoxes->m_Size,
    src: val);
}

//------------------------------------------------------------------------------
// Address: 0x10014080
// Name: public: bool SFTextObjectImpl::Init(class GFxValue __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SFTextObjectImpl::Init(SFTextObjectImpl *this, GFxValue *value)
{
  CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *p_m_TextBoxes; // edi
  CStringPool *pString; // [esp-10h] [ebp-3Ch]
  void *boxArray_8; // [esp+10h] [ebp-1Ch]
  TextBoxArrayVisitor vis; // [esp+18h] [ebp-14h] BYREF
  int v7; // [esp+28h] [ebp-4h]

  p_m_TextBoxes = &this->m_TextBoxes;
  CUtlVector<GFxValue,CUtlMemory<GFxValue,int>>::RemoveAll(this: &this->m_TextBoxes);
  if ( (value->Type & 0x8F) != 8 )
    return 0;
  pString = (CStringPool *)value->Value.pString;
  v7 = 0;
  if ( (unsigned __int8)GFxValue::ObjectInterface::GetMember(result: pString) != 0 )
  {
    vis.__vftable = (TextBoxArrayVisitor_vtbl *)&TextBoxArrayVisitor::`vftable';
    LOBYTE(v7) = 1;
    vis.m_pTextBoxes = p_m_TextBoxes;
    GFxValue::ObjectInterface::VisitElements(this: nullptr, a2: boxArray_8, a3: &vis, a4: 0, a5: -1);
    vis.__vftable = (TextBoxArrayVisitor_vtbl *)&GFxValue::ObjectInterface::ArrVisitor::`vftable';
  }
  else
  {
    CUtlVector<GFxValue,CUtlMemory<GFxValue,int>>::InsertBefore(
      this: p_m_TextBoxes,
      elem: p_m_TextBoxes->m_Size,
      src: value);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10014170
// Name: public: virtual void SFTextObjectImpl::SetText(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFTextObjectImpl::SetText(SFTextObjectImpl *this, int value)
{
  this->SetText_2(this, a2: "%d", value);
}

//------------------------------------------------------------------------------
// Address: 0x10014190
// Name: public: virtual void SFTextObjectImpl::SetText(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFTextObjectImpl::SetText(SFTextObjectImpl *this, float value)
{
  this->SetText_2(this, a2: "%0.f", value);
}

//------------------------------------------------------------------------------
// Address: 0x100141C0
// Name: public: virtual bool SFTextObjectImpl::IsValid(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SFTextObjectImpl::IsValid(SFTextObjectImpl *this)
{
  return this->m_TextBoxes.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x100141D0
// Name: public: virtual void SFTextObjectImpl::SetText(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void SFTextObjectImpl::SetText(SFTextObjectImpl *this, const char *pFormat, ...)
{
  int v2; // esi
  int v3; // edi
  char stringBuffer[1024]; // [esp+8h] [ebp-400h] BYREF
  va_list params; // [esp+418h] [ebp+10h] BYREF

  va_start(params, pFormat);
  V_vsnprintf(pDest: stringBuffer, maxLen: 1024, pFormat, params);
  v2 = 0;
  if ( this->m_TextBoxes.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      GFxValue::ObjectInterface::SetText(result: (_ENLISTMENT_CRM_INFORMATION *)this->m_TextBoxes.m_Memory.m_pMemory[v3].Value.pString);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_TextBoxes.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014230
// Name: public: virtual void SFTextObjectImpl::SetTextHTML(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void SFTextObjectImpl::SetTextHTML(SFTextObjectImpl *this, const char *pFormat, ...)
{
  int v2; // esi
  int v3; // edi
  char stringBuffer[1024]; // [esp+8h] [ebp-400h] BYREF
  va_list params; // [esp+418h] [ebp+10h] BYREF

  va_start(params, pFormat);
  V_vsnprintf(pDest: stringBuffer, maxLen: 1024, pFormat, params);
  v2 = 0;
  if ( this->m_TextBoxes.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      GFxValue::ObjectInterface::SetText(result: (_ENLISTMENT_CRM_INFORMATION *)this->m_TextBoxes.m_Memory.m_pMemory[v3].Value.pString);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_TextBoxes.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014290
// Name: public: virtual void SFTextObjectImpl::SetText(wchar_t const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void SFTextObjectImpl::SetText(SFTextObjectImpl *this, const wchar_t *pFormat, ...)
{
  int v2; // esi
  int v3; // edi
  wchar_t stringBuffer[1024]; // [esp+8h] [ebp-800h] BYREF
  va_list params; // [esp+818h] [ebp+10h] BYREF

  va_start(params, pFormat);
  V_vsnwprintf(pDest: stringBuffer, maxLen: 1024, pFormat, params);
  v2 = 0;
  if ( this->m_TextBoxes.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      GFxValue::ObjectInterface::SetText(
        this: this->m_TextBoxes.m_Memory.m_pMemory[v3].pObjectInterface,
        a2: (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this->m_TextBoxes.m_Memory.m_pMemory[v3].Value.pString,
        a3: stringBuffer,
        a4: false);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_TextBoxes.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100142F0
// Name: public: virtual void SFTextObjectImpl::SetTextHTML(wchar_t const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void SFTextObjectImpl::SetTextHTML(SFTextObjectImpl *this, const wchar_t *pFormat, ...)
{
  int v2; // esi
  int v3; // edi
  wchar_t stringBuffer[1024]; // [esp+8h] [ebp-800h] BYREF
  va_list params; // [esp+818h] [ebp+10h] BYREF

  va_start(params, pFormat);
  V_vsnwprintf(pDest: stringBuffer, maxLen: 1024, pFormat, params);
  v2 = 0;
  if ( this->m_TextBoxes.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      GFxValue::ObjectInterface::SetText(
        this: this->m_TextBoxes.m_Memory.m_pMemory[v3].pObjectInterface,
        a2: (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)this->m_TextBoxes.m_Memory.m_pMemory[v3].Value.pString,
        a3: stringBuffer,
        a4: true);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_TextBoxes.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014350
// Name: public: virtual void SFTextObjectImpl::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFTextObjectImpl::SetVisible(SFTextObjectImpl *this, bool visible)
{
  int v3; // edi
  int v4; // ebx

  v3 = 0;
  if ( this->m_TextBoxes.m_Size > 0 )
  {
    v4 = 0;
    do
    {
      ScaleformUIImpl::SetVisible(
        this: &ScaleformUIImpl::m_Instance,
        obj: &this->m_TextBoxes.m_Memory.m_pMemory[v4],
        visible);
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_TextBoxes.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014390
// Name: public: virtual class ISFTextObject __near * ScaleformUIImpl::TextObject_MakeTextObject(void __near *)
// Source: json
//------------------------------------------------------------------------------
SFTextObjectImpl *__thiscall ScaleformUIImpl::TextObject_MakeTextObject(ScaleformUIImpl *this, GFxValue *value)
{
  SFTextObjectImpl *v2; // eax
  SFTextObjectImpl *v3; // esi

  v2 = (SFTextObjectImpl *)MemAlloc_Alloc(nSize: 0x18u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v2->__vftable = (SFTextObjectImpl_vtbl *)&SFTextObjectImpl::`vftable';
    v2->m_TextBoxes.m_Memory.m_pMemory = nullptr;
    v2->m_TextBoxes.m_Memory.m_nAllocationCount = 0;
    v2->m_TextBoxes.m_Memory.m_nGrowSize = 0;
    v2->m_TextBoxes.m_Size = 0;
    v2->m_TextBoxes.m_pElements = nullptr;
    SFTextObjectImpl::Init(this: v2, value);
  }
  else
  {
    v3 = nullptr;
  }
  if ( v3->IsValid(this: v3) )
    return v3;
  v3->Release(this: v3);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10014430
// Name: public: virtual void SFTextObjectImpl::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFTextObjectImpl::Release(SFTextObjectImpl *this)
{
  if ( this != nullptr )
  {
    CUtlVector<GFxValue,CUtlMemory<GFxValue,int>>::~CUtlVector<GFxValue,CUtlMemory<GFxValue,int>>(this: &this->m_TextBoxes);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069060
// Name: _GFxValue::ObjectInterface::VisitMembers_::_7_::VisitorProxy::Visit
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxValue::ObjectInterface::VisitMembers_::_7_::VisitorProxy::Visit(
        int this,
        _DWORD **a2,
        int a3,
        int a4)
{
  StringPoolCase_t val; // [esp+4h] [ebp-10h] BYREF
  int v6; // [esp+8h] [ebp-Ch]

  val = StringPoolCaseInsensitive;
  v6 = 0;
  GFxMovieRoot::ASValue2GFxValue(this: *(GSysAllocBase_SingletonSupport<GSysAllocMalloc,GSysAlloc> **)(this + 4));
  (*(void (__thiscall **)(_DWORD, _DWORD, StringPoolCase_t *))(**(_DWORD **)(this + 12) + 4))(
    a1: *(_DWORD *)(this + 12),
    a2: **a2,
    a3: &val);
  if ( (v6 & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)val, (StringPoolCase_t)&val);
}
