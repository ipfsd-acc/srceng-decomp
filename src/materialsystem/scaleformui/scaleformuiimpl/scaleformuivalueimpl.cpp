// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/scaleformuiimpl/scaleformuivalueimpl.cpp
// Functions: 89
// ============================================================

#include "materialsystem\scaleformui\scaleformuiimpl\scaleformuivalueimpl.h"

//------------------------------------------------------------------------------
// Address: 0x10015040
// Name: public: virtual void ScaleformUIImpl::Value_SetText(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetText(
        ScaleformUIImpl *this,
        _ENLISTMENT_CRM_INFORMATION **obj,
        const char *value)
{
  GFxValue::ObjectInterface::SetText(result: obj[2]);
}

//------------------------------------------------------------------------------
// Address: 0x10015060
// Name: public: virtual void ScaleformUIImpl::Value_SetText(void __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetText(ScaleformUIImpl *this, void *obj, const wchar_t *value)
{
  GFxValue::ObjectInterface::SetText(
    this: *(GFxValue::ObjectInterface **)obj,
    a2: *((CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)obj
    + 2),
    a3: value,
    a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x10015080
// Name: public: virtual void ScaleformUIImpl::Value_SetTextHTML(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetTextHTML(
        ScaleformUIImpl *this,
        _ENLISTMENT_CRM_INFORMATION **obj,
        const char *value)
{
  GFxValue::ObjectInterface::SetText(result: obj[2]);
}

//------------------------------------------------------------------------------
// Address: 0x100150A0
// Name: public: virtual void ScaleformUIImpl::Value_SetTextHTML(void __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetTextHTML(ScaleformUIImpl *this, void *obj, const wchar_t *value)
{
  GFxValue::ObjectInterface::SetText(
    this: *(GFxValue::ObjectInterface **)obj,
    a2: *((CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> **)obj
    + 2),
    a3: value,
    a4: true);
}

//------------------------------------------------------------------------------
// Address: 0x100150C0
// Name: public: virtual int ScaleformUIImpl::Value_SetFormattedText(void __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
int ScaleformUIImpl::Value_SetFormattedText(ScaleformUIImpl *this, void *obj, const char *pFormat, ...)
{
  int v3; // ebx
  va_list params; // [esp+20h] [ebp+14h] BYREF

  va_start(params, pFormat);
  v3 = V_vsnprintf(pDest: this->m_cTemporaryBuffer, maxLen: 4086, pFormat, params);
  this->Value_SetTextHTML_2(this, a2: obj, a3: this->m_cTemporaryBuffer);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10015100
// Name: public: virtual void ScaleformUIImpl::Value_SetColor(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetColor(ScaleformUIImpl *this, GFxValue::ObjectInterface **obj, int color)
{
  GFxValue::ObjectInterface *v3; // ecx
  GFxValue::ObjectInterface *v4; // [esp-8h] [ebp-28h]
  GRenderer::Cxform cxform; // [esp+0h] [ebp-20h] BYREF

  GRenderer::Cxform::Cxform();
  cxform.M_[0][0] = 0.0;
  cxform.M_[1][0] = 0.0;
  cxform.M_[2][0] = 0.0;
  cxform.M_[3][0] = 0.0;
  cxform.M_[0][1] = (float)BYTE2(color);
  cxform.M_[1][1] = (float)BYTE1(color);
  cxform.M_[2][1] = (float)(unsigned __int8)color;
  v4 = obj[2];
  v3 = *obj;
  cxform.M_[3][1] = (float)HIBYTE(color);
  GFxValue::ObjectInterface::SetCxform(this: v3, a2: v4, a3: &cxform);
}

//------------------------------------------------------------------------------
// Address: 0x100151A0
// Name: public: virtual void ScaleformUIImpl::Value_SetColor(void __near *,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetColor(
        ScaleformUIImpl *this,
        GFxValue::ObjectInterface **obj,
        float r,
        float g,
        float b,
        float a)
{
  GFxValue::ObjectInterface *v6; // ecx
  GFxValue::ObjectInterface *v7; // ecx
  GFxValue::ObjectInterface *v8; // [esp-8h] [ebp-28h]
  GRenderer::Cxform cxform; // [esp+0h] [ebp-20h] BYREF

  GRenderer::Cxform::Cxform();
  cxform.M_[0][0] = 0.0;
  cxform.M_[1][0] = 0.0;
  cxform.M_[2][0] = 0.0;
  cxform.M_[3][0] = 0.0;
  cxform.M_[0][1] = r * 255.0;
  cxform.M_[1][1] = g * 255.0;
  v6 = obj[2];
  cxform.M_[2][1] = b * 255.0;
  v8 = v6;
  v7 = *obj;
  cxform.M_[3][1] = a * 255.0;
  GFxValue::ObjectInterface::SetCxform(this: v7, a2: v8, a3: &cxform);
}

//------------------------------------------------------------------------------
// Address: 0x10015220
// Name: public: virtual void ScaleformUIImpl::Value_SetTint(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetTint(ScaleformUIImpl *this, GFxValue::ObjectInterface **obj, int color)
{
  GFxValue::ObjectInterface *v3; // ecx
  GFxValue::ObjectInterface *v4; // [esp-8h] [ebp-28h]
  GRenderer::Cxform cxform; // [esp+0h] [ebp-20h] BYREF

  GRenderer::Cxform::Cxform();
  cxform.M_[0][0] = (float)BYTE2(color) * 0.0039215689;
  cxform.M_[1][0] = (float)BYTE1(color) * 0.0039215689;
  cxform.M_[2][0] = (float)(unsigned __int8)color * 0.0039215689;
  v4 = obj[2];
  v3 = *obj;
  cxform.M_[3][0] = (float)HIBYTE(color) * 0.0039215689;
  cxform.M_[0][1] = 0.0;
  cxform.M_[1][1] = 0.0;
  cxform.M_[2][1] = 0.0;
  cxform.M_[3][1] = 0.0;
  GFxValue::ObjectInterface::SetCxform(this: v3, a2: v4, a3: &cxform);
}

//------------------------------------------------------------------------------
// Address: 0x100152D0
// Name: public: virtual void ScaleformUIImpl::Value_SetTint(void __near *,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetTint(
        ScaleformUIImpl *this,
        GFxValue::ObjectInterface **obj,
        unsigned int r,
        unsigned int g,
        unsigned int b,
        unsigned int a)
{
  GFxValue::ObjectInterface *v6; // ecx
  GRenderer::Cxform cxform; // [esp+0h] [ebp-20h] BYREF

  GRenderer::Cxform::Cxform();
  *(_QWORD *)&cxform.M_[0][0] = r;
  *(_QWORD *)&cxform.M_[1][0] = g;
  v6 = obj[2];
  *(_QWORD *)&cxform.M_[2][0] = b;
  *(_QWORD *)&cxform.M_[3][0] = a;
  GFxValue::ObjectInterface::SetCxform(this: *obj, a2: v6, a3: &cxform);
}

//------------------------------------------------------------------------------
// Address: 0x10015340
// Name: public: virtual void ScaleformUIImpl::Value_SetColorTransform(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetColorTransform(
        ScaleformUIImpl *this,
        GFxValue::ObjectInterface **obj,
        int colorMultiply,
        int colorAdd)
{
  GFxValue::ObjectInterface *v4; // ecx
  GFxValue::ObjectInterface *v5; // [esp-8h] [ebp-28h]
  GRenderer::Cxform cxform; // [esp+0h] [ebp-20h] BYREF

  GRenderer::Cxform::Cxform();
  cxform.M_[0][0] = (float)BYTE2(colorMultiply) * 0.0039215689;
  cxform.M_[1][0] = (float)BYTE1(colorMultiply) * 0.0039215689;
  cxform.M_[2][0] = (float)(unsigned __int8)colorMultiply * 0.0039215689;
  cxform.M_[0][1] = (float)BYTE2(colorAdd);
  cxform.M_[1][1] = (float)BYTE1(colorAdd);
  cxform.M_[2][1] = (float)(unsigned __int8)colorAdd;
  v5 = obj[2];
  v4 = *obj;
  cxform.M_[3][0] = (float)HIBYTE(colorMultiply) * 0.0039215689;
  cxform.M_[3][1] = (float)HIBYTE(colorAdd);
  GFxValue::ObjectInterface::SetCxform(this: v4, a2: v5, a3: &cxform);
}

//------------------------------------------------------------------------------
// Address: 0x10015430
// Name: public: virtual void ScaleformUIImpl::Value_SetColorTransform(void __near *,float,float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetColorTransform(
        ScaleformUIImpl *this,
        GFxValue::ObjectInterface **obj,
        float r,
        float g,
        float b,
        float a,
        int colorAdd)
{
  GFxValue::ObjectInterface *v7; // ecx
  GFxValue::ObjectInterface *v8; // [esp-8h] [ebp-28h]
  GRenderer::Cxform cxform; // [esp+0h] [ebp-20h] BYREF

  GRenderer::Cxform::Cxform();
  cxform.M_[0][0] = r;
  cxform.M_[1][0] = g;
  cxform.M_[2][0] = b;
  cxform.M_[3][0] = a;
  cxform.M_[0][1] = (float)BYTE2(colorAdd);
  cxform.M_[1][1] = (float)BYTE1(colorAdd);
  cxform.M_[2][1] = (float)(unsigned __int8)colorAdd;
  v8 = obj[2];
  v7 = *obj;
  cxform.M_[3][1] = (float)HIBYTE(colorAdd);
  GFxValue::ObjectInterface::SetCxform(this: v7, a2: v8, a3: &cxform);
}

//------------------------------------------------------------------------------
// Address: 0x100154E0
// Name: public: virtual void __near * ScaleformUIImpl::ValueArray_GetElement(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall ScaleformUIImpl::ValueArray_GetElement(ScaleformUIImpl *this, char *valueArray, int index)
{
  return &valueArray[16 * index];
}

//------------------------------------------------------------------------------
// Address: 0x100154F0
// Name: public: virtual enum IScaleformUI::ValueType ScaleformUIImpl::ValueArray_GetType(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ScaleformUIImpl::ValueArray_GetType(ScaleformUIImpl *this, _DWORD *array, int index)
{
  return array[4 * index + 1] & 0x8F;
}

//------------------------------------------------------------------------------
// Address: 0x10015510
// Name: public: virtual double ScaleformUIImpl::ValueArray_GetNumber(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall ScaleformUIImpl::ValueArray_GetNumber(ScaleformUIImpl *this, double *array, int index)
{
  return array[2 * index + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10015530
// Name: public: virtual bool ScaleformUIImpl::ValueArray_GetBool(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScaleformUIImpl::ValueArray_GetBool(ScaleformUIImpl *this, _BYTE *array, int index)
{
  return array[16 * index + 8];
}

//------------------------------------------------------------------------------
// Address: 0x10015550
// Name: public: virtual wchar_t const __near * ScaleformUIImpl::ValueArray_GetStringW(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
const wchar_t *__thiscall ScaleformUIImpl::ValueArray_GetStringW(ScaleformUIImpl *this, _DWORD *array, int index)
{
  return (const wchar_t *)array[4 * index + 2];
}

//------------------------------------------------------------------------------
// Address: 0x10015570
// Name: public: virtual void ScaleformUIImpl::ValueArray_SetElementText(void __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ValueArray_SetElementText(
        ScaleformUIImpl *this,
        _ENLISTMENT_CRM_INFORMATION **array,
        int index,
        const char *value)
{
  GFxValue::ObjectInterface::SetText(result: array[4 * index + 2]);
}

//------------------------------------------------------------------------------
// Address: 0x100155A0
// Name: public: virtual void ScaleformUIImpl::ValueArray_SetElementText(void __near *,int,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ValueArray_SetElementText(
        ScaleformUIImpl *this,
        GFxValue::ObjectInterface **array,
        int index,
        const wchar_t *value)
{
  GFxValue::ObjectInterface::SetText(
    this: array[4 * index],
    a2: (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)array[4 * index + 2],
    a3: value,
    a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x100155D0
// Name: public: virtual void ScaleformUIImpl::ValueArray_SetElementTextHTML(void __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ValueArray_SetElementTextHTML(
        ScaleformUIImpl *this,
        _ENLISTMENT_CRM_INFORMATION **array,
        int index,
        const char *value)
{
  GFxValue::ObjectInterface::SetText(result: array[4 * index + 2]);
}

//------------------------------------------------------------------------------
// Address: 0x10015600
// Name: public: virtual void ScaleformUIImpl::ValueArray_SetElementTextHTML(void __near *,int,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ValueArray_SetElementTextHTML(
        ScaleformUIImpl *this,
        GFxValue::ObjectInterface **array,
        int index,
        const wchar_t *value)
{
  GFxValue::ObjectInterface::SetText(
    this: array[4 * index],
    a2: (CMemberFunctor3<CMatQueuedIndexBuffer *,void (__thiscall CMatQueuedIndexBuffer::*)(int,enum MaterialIndexFormat_t,void *),int,enum MaterialIndexFormat_t,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)array[4 * index + 2],
    a3: value,
    a4: true);
}

//------------------------------------------------------------------------------
// Address: 0x10015630
// Name: public: virtual bool ScaleformUIImpl::Value_HasMember(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall ScaleformUIImpl::Value_HasMember(ScaleformUIImpl *this, CStringPool **value, const char *name)
{
  return GFxValue::ObjectInterface::HasMember(this: *value);
}

//------------------------------------------------------------------------------
// Address: 0x10015660
// Name: public: virtual bool ScaleformUIImpl::Value_SetMember(void __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall ScaleformUIImpl::Value_SetMember(ScaleformUIImpl *this, void *obj, const char *name, void *value)
{
  return GFxValue::ObjectInterface::SetMember(this: *(CStringPool **)obj, pdata: *((_DWORD *)obj + 2));
}

//------------------------------------------------------------------------------
// Address: 0x10015690
// Name: public: virtual bool ScaleformUIImpl::Value_InvokeWithoutReturn(void __near *,char const __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScaleformUIImpl::Value_InvokeWithoutReturn(
        ScaleformUIImpl *this,
        void *obj,
        const char *methodName,
        const struct GFxValue *args,
        unsigned int numArgs)
{
  if ( args != nullptr && numArgs != 0 )
    return GFxValue::ObjectInterface::Invoke(
             this: *(GFxValue::ObjectInterface **)obj,
             a2: *((void **)obj + 2),
             a3: nullptr,
             a4: methodName,
             a5: args,
             a6: numArgs,
             a7: (*((_DWORD *)obj + 1) & 0x8F) == 8);
  else
    return GFxValue::ObjectInterface::Invoke(
             this: *(GFxValue::ObjectInterface **)obj,
             a2: *((void **)obj + 2),
             a3: nullptr,
             a4: methodName,
             a5: nullptr,
             a6: 0,
             a7: (*((_DWORD *)obj + 1) & 0x8F) == 8);
}

//------------------------------------------------------------------------------
// Address: 0x10015700
// Name: public: virtual void ScaleformUIImpl::Value_GetDisplayInfo(void __near *,class ScaleformDisplayInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_GetDisplayInfo(ScaleformUIImpl *this, void *obj, ScaleformDisplayInfo *dinfo)
{
  long double X; // xmm0_8
  bool Visible; // al
  long double YScale; // xmm0_8
  GFxValue::DisplayInfo info; // [esp+4h] [ebp-E8h] BYREF

  dinfo->m_iSetFlags = 0;
  GMatrix3D::SetIdentity(this: &info.ViewMatrix3D);
  GMatrix3D::SetIdentity(this: &info.PerspectiveMatrix3D);
  info.VarsSet = 0;
  if ( GFxValue::ObjectInterface::GetDisplayInfo(
         this: *(GFxValue::ObjectInterface **)obj,
         a2: *((void **)obj + 2),
         a3: &info) )
  {
    X = info.X;
    Visible = info.Visible;
    dinfo->m_iSetFlags |= 0x7Fu;
    dinfo->m_fX = X;
    dinfo->m_fY = info.Y;
    dinfo->m_fRotation = info.Rotation;
    dinfo->m_fAlpha = info.Alpha;
    dinfo->m_fXScale = info.XScale;
    YScale = info.YScale;
    dinfo->m_bVisibility = Visible;
    dinfo->m_fYScale = YScale;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100157B0
// Name: public: virtual enum IScaleformUI::ValueType ScaleformUIImpl::Value_GetType(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ScaleformUIImpl::Value_GetType(ScaleformUIImpl *this, _DWORD *obj)
{
  return obj[1] & 0x8F;
}

//------------------------------------------------------------------------------
// Address: 0x100157D0
// Name: public: virtual double ScaleformUIImpl::Value_GetNumber(void __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall ScaleformUIImpl::Value_GetNumber(ScaleformUIImpl *this, double *obj)
{
  return obj[1];
}

//------------------------------------------------------------------------------
// Address: 0x100157E0
// Name: public: virtual bool ScaleformUIImpl::Value_GetBool(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScaleformUIImpl::Value_GetBool(ScaleformUIImpl *this, _BYTE *obj)
{
  return obj[8];
}

//------------------------------------------------------------------------------
// Address: 0x100157F0
// Name: public: virtual wchar_t const __near * ScaleformUIImpl::Value_GetStringW(void __near *)
// Source: json
//------------------------------------------------------------------------------
const wchar_t *__thiscall ScaleformUIImpl::Value_GetStringW(ScaleformUIImpl *this, _DWORD *obj)
{
  return (const wchar_t *)obj[2];
}

//------------------------------------------------------------------------------
// Address: 0x10015800
// Name: public: virtual void ScaleformUIImpl::Value_SetArraySize(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetArraySize(ScaleformUIImpl *this, void *obj, unsigned int size)
{
  GFxValue::ObjectInterface::SetArraySize(this: *(GFxValue::ObjectInterface **)obj, a2: *((void **)obj + 2), a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x10015820
// Name: public: virtual int ScaleformUIImpl::Value_GetArraySize(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall ScaleformUIImpl::Value_GetArraySize(ScaleformUIImpl *this, void *obj)
{
  return GFxValue::ObjectInterface::GetArraySize(this: *(GFxValue::ObjectInterface **)obj, a2: *((void **)obj + 2));
}

//------------------------------------------------------------------------------
// Address: 0x10015840
// Name: public: virtual void ScaleformUIImpl::Value_ClearArrayElements(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_ClearArrayElements(ScaleformUIImpl *this, std::_Init_locks **obj)
{
  GFxValue::ObjectInterface::RemoveElements(result: obj[2]);
}

//------------------------------------------------------------------------------
// Address: 0x10015860
// Name: public: virtual void ScaleformUIImpl::Value_RemoveArrayElement(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_RemoveArrayElement(ScaleformUIImpl *this, std::_Init_locks **obj, int index)
{
  GFxValue::ObjectInterface::RemoveElements(result: obj[2]);
}

//------------------------------------------------------------------------------
// Address: 0x10015880
// Name: public: virtual void ScaleformUIImpl::Value_RemoveArrayElements(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_RemoveArrayElements(
        ScaleformUIImpl *this,
        std::_Init_locks **obj,
        int index,
        int count)
{
  GFxValue::ObjectInterface::RemoveElements(result: obj[2]);
}

//------------------------------------------------------------------------------
// Address: 0x100158A0
// Name: public: virtual void ScaleformUIImpl::Value_SetArrayElement(void __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetArrayElement(
        ScaleformUIImpl *this,
        void *obj,
        unsigned int index,
        const struct GFxValue *value)
{
  GFxValue::ObjectInterface::SetElement(
    this: *(GFxValue::ObjectInterface **)obj,
    a2: *((void **)obj + 2),
    a3: index,
    a4: value);
}

//------------------------------------------------------------------------------
// Address: 0x100158C0
// Name: public: virtual void ScaleformUIImpl::Value_SetValue(void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetValue(ScaleformUIImpl *this, CStringPool **obj, CStringPool **value)
{
  CStringPool *v3; // ecx

  if ( obj != value )
  {
    if ( ((unsigned int)obj[1] & 0x40) != 0 )
    {
      GFxValue::ObjectInterface::ObjectRelease(this: *obj, val: (StringPoolCase_t)obj);
      *obj = nullptr;
    }
    obj[1] = value[1];
    obj[2] = value[2];
    obj[3] = value[3];
    if ( ((unsigned int)value[1] & 0x40) != 0 )
    {
      v3 = *value;
      *obj = *value;
      GFxValue::ObjectInterface::ObjectAddRef(this: v3, val: (StringPoolCase_t)obj);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015920
// Name: public: virtual char const __near * ScaleformUIImpl::ValueArray_GetString(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ScaleformUIImpl::ValueArray_GetString(ScaleformUIImpl *this, char *array, int index)
{
  char *v3; // eax

  v3 = &array[16 * index];
  if ( (*((_DWORD *)v3 + 1) & 0x40) != 0 )
    return **((const char ***)v3 + 2);
  else
    return *((const char **)v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10015950
// Name: public: virtual void ScaleformUIImpl::ValueArray_SetElement(void __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ValueArray_SetElement(
        ScaleformUIImpl *this,
        char *valueArray,
        int index,
        CStringPool **value)
{
  char *v4; // esi
  CStringPool *v5; // ecx

  v4 = &valueArray[16 * index];
  if ( v4 != (char *)value )
  {
    if ( (*((_DWORD *)v4 + 1) & 0x40) != 0 )
    {
      GFxValue::ObjectInterface::ObjectRelease(
        this: *(CStringPool **)v4,
        val: (StringPoolCase_t)&valueArray[16 * index]);
      *(_DWORD *)v4 = 0;
    }
    *((_DWORD *)v4 + 1) = value[1];
    *((_DWORD *)v4 + 2) = value[2];
    *((_DWORD *)v4 + 3) = value[3];
    if ( ((unsigned int)value[1] & 0x40) != 0 )
    {
      v5 = *value;
      *(_DWORD *)v4 = *value;
      GFxValue::ObjectInterface::ObjectAddRef(this: v5, val: (StringPoolCase_t)v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100159B0
// Name: public: virtual bool ScaleformUIImpl::Value_SetMember(void __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall ScaleformUIImpl::Value_SetMember(
        ScaleformUIImpl *this,
        void *obj,
        const char *name,
        int value)
{
  return (unsigned __int8)GFxValue::ObjectInterface::SetMember(this: *(CStringPool **)obj, pdata: *((_DWORD *)obj + 2));
}

//------------------------------------------------------------------------------
// Address: 0x10015A50
// Name: public: virtual bool ScaleformUIImpl::Value_SetMember(void __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall ScaleformUIImpl::Value_SetMember(
        ScaleformUIImpl *this,
        void *obj,
        const char *name,
        float value)
{
  return (unsigned __int8)GFxValue::ObjectInterface::SetMember(this: *(CStringPool **)obj, pdata: *((_DWORD *)obj + 2));
}

//------------------------------------------------------------------------------
// Address: 0x10015AF0
// Name: public: virtual bool ScaleformUIImpl::Value_SetMember(void __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall ScaleformUIImpl::Value_SetMember(
        ScaleformUIImpl *this,
        void *obj,
        const char *name,
        bool value)
{
  return (unsigned __int8)GFxValue::ObjectInterface::SetMember(this: *(CStringPool **)obj, pdata: *((_DWORD *)obj + 2));
}

//------------------------------------------------------------------------------
// Address: 0x10015B90
// Name: public: virtual bool ScaleformUIImpl::Value_SetMember(void __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall ScaleformUIImpl::Value_SetMember(
        ScaleformUIImpl *this,
        void *obj,
        const char *name,
        const char *value)
{
  return (unsigned __int8)GFxValue::ObjectInterface::SetMember(this: *(CStringPool **)obj, pdata: *((_DWORD *)obj + 2));
}

//------------------------------------------------------------------------------
// Address: 0x10015C30
// Name: public: virtual bool ScaleformUIImpl::Value_SetMember(void __near *,char const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall ScaleformUIImpl::Value_SetMember(
        ScaleformUIImpl *this,
        void *obj,
        const char *name,
        const wchar_t *value)
{
  return (unsigned __int8)GFxValue::ObjectInterface::SetMember(this: *(CStringPool **)obj, pdata: *((_DWORD *)obj + 2));
}

//------------------------------------------------------------------------------
// Address: 0x10015CD0
// Name: public: void ScaleformUIImpl::SetVisible(class GFxValue __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::SetVisible(ScaleformUIImpl *this, void *obj, bool visible)
{
  GFxValue::DisplayInfo info; // [esp+0h] [ebp-E8h] BYREF

  GMatrix3D::SetIdentity(this: &info.ViewMatrix3D);
  GMatrix3D::SetIdentity(this: &info.PerspectiveMatrix3D);
  info.VarsSet = 64;
  info.Visible = visible;
  GFxValue::ObjectInterface::SetDisplayInfo(
    this: *(GFxValue::ObjectInterface **)obj,
    a2: *((void **)obj + 2),
    a3: &info);
}

//------------------------------------------------------------------------------
// Address: 0x10015D20
// Name: public: virtual void ScaleformUIImpl::Value_SetDisplayInfo(void __near *,class ScaleformDisplayInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetDisplayInfo(
        ScaleformUIImpl *this,
        void *obj,
        const ScaleformDisplayInfo *dinfo)
{
  long double m_fX; // xmm0_8
  int m_iSetFlags; // ecx
  long double m_fY; // xmm0_8
  long double m_fRotation; // xmm0_8
  long double m_fAlpha; // xmm0_8
  bool m_bVisibility; // dl
  long double m_fXScale; // xmm0_8
  long double m_fYScale; // xmm0_8
  GFxValue::DisplayInfo info; // [esp+0h] [ebp-E8h] BYREF

  GMatrix3D::SetIdentity(this: &info.ViewMatrix3D);
  GMatrix3D::SetIdentity(this: &info.PerspectiveMatrix3D);
  info.VarsSet = 0;
  if ( (dinfo->m_iSetFlags & 1) != 0 )
  {
    m_fX = dinfo->m_fX;
    info.VarsSet = 1;
    info.X = m_fX;
  }
  m_iSetFlags = dinfo->m_iSetFlags;
  if ( (m_iSetFlags & 2) != 0 )
  {
    m_fY = dinfo->m_fY;
    info.VarsSet |= 2u;
    info.Y = m_fY;
  }
  if ( (m_iSetFlags & 4) != 0 )
  {
    m_fRotation = dinfo->m_fRotation;
    info.VarsSet |= 4u;
    info.Rotation = m_fRotation;
  }
  if ( (m_iSetFlags & 8) != 0 )
  {
    m_fAlpha = dinfo->m_fAlpha;
    info.VarsSet |= 0x20u;
    info.Alpha = m_fAlpha;
  }
  if ( (m_iSetFlags & 0x10) != 0 )
  {
    m_bVisibility = dinfo->m_bVisibility;
    info.VarsSet |= 0x40u;
    info.Visible = m_bVisibility;
  }
  if ( (m_iSetFlags & 0x20) != 0 )
  {
    m_fXScale = dinfo->m_fXScale;
    info.VarsSet |= 8u;
    info.XScale = m_fXScale;
  }
  if ( (m_iSetFlags & 0x40) != 0 )
  {
    m_fYScale = dinfo->m_fYScale;
    info.VarsSet |= 0x10u;
    info.YScale = m_fYScale;
  }
  GFxValue::ObjectInterface::SetDisplayInfo(
    this: *(GFxValue::ObjectInterface **)obj,
    a2: *((void **)obj + 2),
    a3: &info);
}

//------------------------------------------------------------------------------
// Address: 0x10015E20
// Name: public: virtual char const __near * ScaleformUIImpl::Value_GetString(void __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ScaleformUIImpl::Value_GetString(ScaleformUIImpl *this, _DWORD **obj)
{
  if ( ((unsigned int)obj[1] & 0x40) != 0 )
    return (const char *)*obj[2];
  else
    return (const char *)obj[2];
}

//------------------------------------------------------------------------------
// Address: 0x10015E50
// Name: public: virtual void ScaleformUIImpl::Value_SetArrayElement(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetArrayElement(ScaleformUIImpl *this, void *obj, unsigned int index, int value)
{
  GFxValue gv; // [esp+0h] [ebp-1Ch] BYREF
  int v5; // [esp+18h] [ebp-4h]

  gv.pObjectInterface = nullptr;
  gv.Type = VT_Number;
  gv.Value.NValue = (double)value;
  v5 = 0;
  GFxValue::ObjectInterface::SetElement(
    this: *(GFxValue::ObjectInterface **)obj,
    a2: *((void **)obj + 2),
    a3: index,
    a4: &gv);
  v5 = -1;
  if ( (gv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gv.pObjectInterface, val: (StringPoolCase_t)&gv);
}

//------------------------------------------------------------------------------
// Address: 0x10015ED0
// Name: public: virtual void ScaleformUIImpl::Value_SetArrayElement(void __near *,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetArrayElement(
        ScaleformUIImpl *this,
        void *obj,
        unsigned int index,
        float value)
{
  GFxValue gv; // [esp+0h] [ebp-1Ch] BYREF
  int v5; // [esp+18h] [ebp-4h]

  gv.pObjectInterface = nullptr;
  gv.Type = VT_Number;
  gv.Value.NValue = value;
  v5 = 0;
  GFxValue::ObjectInterface::SetElement(
    this: *(GFxValue::ObjectInterface **)obj,
    a2: *((void **)obj + 2),
    a3: index,
    a4: &gv);
  v5 = -1;
  if ( (gv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gv.pObjectInterface, val: (StringPoolCase_t)&gv);
}

//------------------------------------------------------------------------------
// Address: 0x10015F50
// Name: public: virtual void ScaleformUIImpl::Value_SetArrayElement(void __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetArrayElement(
        ScaleformUIImpl *this,
        void *obj,
        unsigned int index,
        bool value)
{
  GFxValue gv; // [esp+0h] [ebp-1Ch] BYREF
  int v5; // [esp+18h] [ebp-4h]

  gv.pObjectInterface = nullptr;
  gv.Type = VT_Boolean;
  gv.Value.BValue = value;
  v5 = 0;
  GFxValue::ObjectInterface::SetElement(
    this: *(GFxValue::ObjectInterface **)obj,
    a2: *((void **)obj + 2),
    a3: index,
    a4: &gv);
  v5 = -1;
  if ( (gv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gv.pObjectInterface, val: (StringPoolCase_t)&gv);
}

//------------------------------------------------------------------------------
// Address: 0x10015FD0
// Name: public: virtual void ScaleformUIImpl::Value_SetArrayElement(void __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetArrayElement(
        ScaleformUIImpl *this,
        void *obj,
        unsigned int index,
        const char *value)
{
  GFxValue gv; // [esp+0h] [ebp-1Ch] BYREF
  int v5; // [esp+18h] [ebp-4h]

  gv.pObjectInterface = nullptr;
  gv.Type = VT_String;
  gv.Value.pString = value;
  v5 = 0;
  GFxValue::ObjectInterface::SetElement(
    this: *(GFxValue::ObjectInterface **)obj,
    a2: *((void **)obj + 2),
    a3: index,
    a4: &gv);
  v5 = -1;
  if ( (gv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gv.pObjectInterface, val: (StringPoolCase_t)&gv);
}

//------------------------------------------------------------------------------
// Address: 0x10016050
// Name: public: virtual void ScaleformUIImpl::Value_SetArrayElement(void __near *,int,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetArrayElement(
        ScaleformUIImpl *this,
        void *obj,
        unsigned int index,
        const wchar_t *value)
{
  GFxValue gv; // [esp+0h] [ebp-1Ch] BYREF
  int v5; // [esp+18h] [ebp-4h]

  gv.pObjectInterface = nullptr;
  gv.Type = VT_StringW;
  gv.Value.pString = (const char *)value;
  v5 = 0;
  GFxValue::ObjectInterface::SetElement(
    this: *(GFxValue::ObjectInterface **)obj,
    a2: *((void **)obj + 2),
    a3: index,
    a4: &gv);
  v5 = -1;
  if ( (gv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gv.pObjectInterface, val: (StringPoolCase_t)&gv);
}

//------------------------------------------------------------------------------
// Address: 0x10016100
// Name: public: virtual void ScaleformUIImpl::Value_SetValue(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetValue(ScaleformUIImpl *this, CStringPool **obj, int value)
{
  if ( ((unsigned int)obj[1] & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: *obj, val: (StringPoolCase_t)obj);
    *obj = nullptr;
  }
  obj[1] = (CStringPool *)3;
  *((double *)obj + 1) = (double)value;
}

//------------------------------------------------------------------------------
// Address: 0x10016140
// Name: public: virtual void ScaleformUIImpl::Value_SetValue(void __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetValue(ScaleformUIImpl *this, CStringPool **obj, float value)
{
  if ( ((unsigned int)obj[1] & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: *obj, val: (StringPoolCase_t)obj);
    *obj = nullptr;
  }
  obj[1] = (CStringPool *)3;
  *((double *)obj + 1) = value;
}

//------------------------------------------------------------------------------
// Address: 0x10016180
// Name: public: virtual void ScaleformUIImpl::Value_SetValue(void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetValue(ScaleformUIImpl *this, CStringPool **obj, bool value)
{
  if ( ((unsigned int)obj[1] & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: *obj, val: (StringPoolCase_t)obj);
    *obj = nullptr;
  }
  *((_BYTE *)obj + 8) = value;
  obj[1] = (CStringPool *)2;
}

//------------------------------------------------------------------------------
// Address: 0x100161D0
// Name: public: virtual void ScaleformUIImpl::Value_SetValue(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetValue(ScaleformUIImpl *this, CStringPool **obj, CStringPool *value)
{
  if ( ((unsigned int)obj[1] & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: *obj, val: (StringPoolCase_t)obj);
    *obj = nullptr;
  }
  obj[2] = value;
  obj[1] = (CStringPool *)4;
}

//------------------------------------------------------------------------------
// Address: 0x10016220
// Name: public: virtual void ScaleformUIImpl::Value_SetValue(void __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::Value_SetValue(ScaleformUIImpl *this, CStringPool **obj, CStringPool *value)
{
  if ( ((unsigned int)obj[1] & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: *obj, val: (StringPoolCase_t)obj);
    *obj = nullptr;
  }
  obj[2] = value;
  obj[1] = (CStringPool *)5;
}

//------------------------------------------------------------------------------
// Address: 0x10016270
// Name: public: virtual void ScaleformUIImpl::ValueArray_SetElement(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ValueArray_SetElement(ScaleformUIImpl *this, char *valueArray, int index, int value)
{
  char *v4; // esi

  v4 = &valueArray[16 * index];
  if ( (*((_DWORD *)v4 + 1) & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: *(CStringPool **)v4, val: (StringPoolCase_t)&valueArray[16 * index]);
    *(_DWORD *)v4 = 0;
  }
  *((_DWORD *)v4 + 1) = 3;
  *((double *)v4 + 1) = (double)value;
}

//------------------------------------------------------------------------------
// Address: 0x100162C0
// Name: public: virtual void ScaleformUIImpl::ValueArray_SetElement(void __near *,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ValueArray_SetElement(ScaleformUIImpl *this, char *valueArray, int index, float value)
{
  char *v4; // esi

  v4 = &valueArray[16 * index];
  if ( (*((_DWORD *)v4 + 1) & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: *(CStringPool **)v4, val: (StringPoolCase_t)&valueArray[16 * index]);
    *(_DWORD *)v4 = 0;
  }
  *((_DWORD *)v4 + 1) = 3;
  *((double *)v4 + 1) = value;
}

//------------------------------------------------------------------------------
// Address: 0x10016310
// Name: public: virtual void ScaleformUIImpl::ValueArray_SetElement(void __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ValueArray_SetElement(ScaleformUIImpl *this, char *valueArray, int index, bool value)
{
  char *v4; // esi

  v4 = &valueArray[16 * index];
  if ( (*((_DWORD *)v4 + 1) & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: *(CStringPool **)v4, val: (StringPoolCase_t)&valueArray[16 * index]);
    *(_DWORD *)v4 = 0;
  }
  v4[8] = value;
  *((_DWORD *)v4 + 1) = 2;
}

//------------------------------------------------------------------------------
// Address: 0x10016360
// Name: public: virtual void ScaleformUIImpl::ValueArray_SetElement(void __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ValueArray_SetElement(
        ScaleformUIImpl *this,
        char *valueArray,
        int index,
        const char *value)
{
  char *v4; // esi

  v4 = &valueArray[16 * index];
  if ( (*((_DWORD *)v4 + 1) & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: *(CStringPool **)v4, val: (StringPoolCase_t)&valueArray[16 * index]);
    *(_DWORD *)v4 = 0;
  }
  *((_DWORD *)v4 + 2) = value;
  *((_DWORD *)v4 + 1) = 4;
}

//------------------------------------------------------------------------------
// Address: 0x100163B0
// Name: public: virtual void ScaleformUIImpl::ValueArray_SetElement(void __near *,int,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ValueArray_SetElement(
        ScaleformUIImpl *this,
        char *valueArray,
        int index,
        const wchar_t *value)
{
  char *v4; // esi

  v4 = &valueArray[16 * index];
  if ( (*((_DWORD *)v4 + 1) & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: *(CStringPool **)v4, val: (StringPoolCase_t)&valueArray[16 * index]);
    *(_DWORD *)v4 = 0;
  }
  *((_DWORD *)v4 + 2) = value;
  *((_DWORD *)v4 + 1) = 5;
}

//------------------------------------------------------------------------------
// Address: 0x10016460
// Name: protected: class GFxValue __near * ScaleformUIImpl::CreateGFxValue(class GFxValue __near *)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::CreateGFxValue(ScaleformUIImpl *this, GFxValue *pValue)
{
  int m_Size; // eax
  GFxValue *v3; // edi
  GFxValue *result; // eax

  m_Size = this->m_ValueCache.m_Size;
  if ( m_Size == 0 )
  {
    result = (GFxValue *)MemAlloc_Alloc(nSize: 0x10u);
    if ( pValue != nullptr )
    {
      if ( result != nullptr )
        return GFxValue::GFxValue(this: result, src: pValue);
    }
    else if ( result != nullptr )
    {
      result->pObjectInterface = nullptr;
      result->Type = VT_Undefined;
      return result;
    }
    return nullptr;
  }
  v3 = this->m_ValueCache.m_Memory.m_pMemory[m_Size - 1];
  if ( m_Size > 0 )
    --this->m_ValueCache.m_Size;
  if ( pValue != nullptr )
    GFxValue::operator=(this: v3, src: pValue);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10016550
// Name: public: virtual void __near * ScaleformUIImpl::CreateValue(void __near *)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::CreateValue(ScaleformUIImpl *this, GFxValue *value)
{
  return ScaleformUIImpl::CreateGFxValue(this, pValue: value);
}

//------------------------------------------------------------------------------
// Address: 0x10016560
// Name: public: virtual void __near * ScaleformUIImpl::CreateValue(int)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::CreateValue(ScaleformUIImpl *this, int value)
{
  int m_Size; // eax
  GFxValue *v3; // esi
  GFxValue *v4; // eax

  m_Size = this->m_ValueCache.m_Size;
  if ( m_Size != 0 )
  {
    v3 = this->m_ValueCache.m_Memory.m_pMemory[m_Size - 1];
    if ( m_Size > 0 )
      --this->m_ValueCache.m_Size;
  }
  else
  {
    v4 = (GFxValue *)MemAlloc_Alloc(nSize: 0x10u);
    if ( v4 != nullptr )
    {
      v4->pObjectInterface = nullptr;
      v4->Type = VT_Undefined;
    }
    else
    {
      v4 = nullptr;
    }
    v3 = v4;
  }
  if ( (v3->Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)v3->pObjectInterface, val: (StringPoolCase_t)v3);
    v3->pObjectInterface = nullptr;
  }
  v3->Type = VT_Number;
  v3->Value.NValue = (double)value;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10016600
// Name: public: virtual void __near * ScaleformUIImpl::CreateValue(float)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::CreateValue(ScaleformUIImpl *this, float value)
{
  int m_Size; // eax
  GFxValue *v3; // esi
  GFxValue *v4; // eax

  m_Size = this->m_ValueCache.m_Size;
  if ( m_Size != 0 )
  {
    v3 = this->m_ValueCache.m_Memory.m_pMemory[m_Size - 1];
    if ( m_Size > 0 )
      --this->m_ValueCache.m_Size;
  }
  else
  {
    v4 = (GFxValue *)MemAlloc_Alloc(nSize: 0x10u);
    if ( v4 != nullptr )
    {
      v4->pObjectInterface = nullptr;
      v4->Type = VT_Undefined;
    }
    else
    {
      v4 = nullptr;
    }
    v3 = v4;
  }
  if ( (v3->Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)v3->pObjectInterface, val: (StringPoolCase_t)v3);
    v3->pObjectInterface = nullptr;
  }
  v3->Type = VT_Number;
  v3->Value.NValue = value;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100166A0
// Name: public: virtual void __near * ScaleformUIImpl::CreateValue(bool)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::CreateValue(ScaleformUIImpl *this, bool value)
{
  int m_Size; // eax
  GFxValue *v3; // esi
  GFxValue *v4; // eax

  m_Size = this->m_ValueCache.m_Size;
  if ( m_Size != 0 )
  {
    v3 = this->m_ValueCache.m_Memory.m_pMemory[m_Size - 1];
    if ( m_Size > 0 )
      --this->m_ValueCache.m_Size;
  }
  else
  {
    v4 = (GFxValue *)MemAlloc_Alloc(nSize: 0x10u);
    if ( v4 != nullptr )
    {
      v4->pObjectInterface = nullptr;
      v4->Type = VT_Undefined;
    }
    else
    {
      v4 = nullptr;
    }
    v3 = v4;
  }
  if ( (v3->Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)v3->pObjectInterface, val: (StringPoolCase_t)v3);
    v3->pObjectInterface = nullptr;
  }
  v3->Value.BValue = value;
  v3->Type = VT_Boolean;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10016730
// Name: public: virtual void __near * ScaleformUIImpl::CreateValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::CreateValue(ScaleformUIImpl *this, const char *value)
{
  int m_Size; // eax
  GFxValue *v3; // esi
  GFxValue *v4; // eax

  m_Size = this->m_ValueCache.m_Size;
  if ( m_Size != 0 )
  {
    v3 = this->m_ValueCache.m_Memory.m_pMemory[m_Size - 1];
    if ( m_Size > 0 )
      --this->m_ValueCache.m_Size;
  }
  else
  {
    v4 = (GFxValue *)MemAlloc_Alloc(nSize: 0x10u);
    if ( v4 != nullptr )
    {
      v4->pObjectInterface = nullptr;
      v4->Type = VT_Undefined;
    }
    else
    {
      v4 = nullptr;
    }
    v3 = v4;
  }
  if ( (v3->Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)v3->pObjectInterface, val: (StringPoolCase_t)v3);
    v3->pObjectInterface = nullptr;
  }
  v3->Value.pString = value;
  v3->Type = VT_String;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100167C0
// Name: public: virtual void __near * ScaleformUIImpl::CreateValue(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::CreateValue(ScaleformUIImpl *this, const wchar_t *value)
{
  int m_Size; // eax
  GFxValue *v3; // esi
  GFxValue *v4; // eax

  m_Size = this->m_ValueCache.m_Size;
  if ( m_Size != 0 )
  {
    v3 = this->m_ValueCache.m_Memory.m_pMemory[m_Size - 1];
    if ( m_Size > 0 )
      --this->m_ValueCache.m_Size;
  }
  else
  {
    v4 = (GFxValue *)MemAlloc_Alloc(nSize: 0x10u);
    if ( v4 != nullptr )
    {
      v4->pObjectInterface = nullptr;
      v4->Type = VT_Undefined;
    }
    else
    {
      v4 = nullptr;
    }
    v3 = v4;
  }
  if ( (v3->Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)v3->pObjectInterface, val: (StringPoolCase_t)v3);
    v3->pObjectInterface = nullptr;
  }
  v3->Value.pString = (const char *)value;
  v3->Type = VT_StringW;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10016850
// Name: public: virtual void __near * ScaleformUIImpl::CreateValueArray(unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::CreateValueArray(ScaleformUIImpl *this, unsigned int length)
{
  GFxValue *result; // eax
  int m_Size; // edx
  unsigned int v4; // eax
  int v5; // edx
  ScaleformUIImpl_vtbl **v6; // eax
  int v7; // esi
  unsigned int v8; // ecx
  _DWORD *v9; // eax
  _DWORD *v10; // edi

  result = nullptr;
  if ( length - 1 <= 9 )
  {
    if ( length == 1 )
    {
      m_Size = this->m_ValueCache.m_Size;
      if ( m_Size != 0 )
      {
        result = this->m_ValueCache.m_Memory.m_pMemory[m_Size - 1];
        if ( m_Size > 0 )
          --this->m_ValueCache.m_Size;
        return result;
      }
      result = (GFxValue *)MemAlloc_Alloc(nSize: 0x10u);
      if ( result != nullptr )
      {
        result->pObjectInterface = nullptr;
        result->Type = VT_Undefined;
        return result;
      }
    }
    else
    {
      v4 = 5 * length - 10;
      v5 = *(&this->m_ValueArrayCaches[0].m_Size + v4);
      v6 = &this->__vftable + v4;
      if ( v5 != 0 )
      {
        v7 = *((_DWORD *)v6[1808] + (_DWORD)v6[1811] - 1);
        CUtlVector<GFxValue *,CUtlMemory<GFxValue *,int>>::FastRemove(
          this: (CUtlVector<GFxValue *,CUtlMemory<GFxValue *,int> > *)(v6 + 1808),
          elem: v5 - 1);
        return (GFxValue *)v7;
      }
      v8 = (unsigned __int64)length >> 28 != 0 ? -1 : 16 * length;
      v9 = MemAlloc_Alloc(nSize: __CFADD__(v8, 4) ? -1 : v8 + 4);
      if ( v9 != nullptr )
      {
        v10 = v9 + 1;
        *v9 = length;
        `eh vector constructor iterator'(
          ptr: v9 + 1,
          size: 0x10u,
          count: length,
          pCtor: (void (__thiscall *)(void *))GFxResourceKey::GFxResourceKey,
          pDtor: (void (__thiscall *)(void *))GFxValue::~GFxValue);
        return (GFxValue *)v10;
      }
    }
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100169C0
// Name: public: virtual void __near * ScaleformUIImpl::Value_GetMember(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::Value_GetMember(ScaleformUIImpl *this, _DWORD *value, const char *name)
{
  GFxValue *v4; // esi
  CStringPool *v6; // [esp-10h] [ebp-34h]
  GFxValue newValue; // [esp+8h] [ebp-1Ch] BYREF
  int v8; // [esp+20h] [ebp-4h]

  newValue.pObjectInterface = nullptr;
  newValue.Type = VT_Undefined;
  v4 = nullptr;
  v6 = (CStringPool *)value[2];
  v8 = 0;
  if ( (unsigned __int8)GFxValue::ObjectInterface::GetMember(result: v6) != 0 )
    v4 = ScaleformUIImpl::CreateGFxValue(this, pValue: &newValue);
  v8 = -1;
  if ( (newValue.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(
      this: (CStringPool *)newValue.pObjectInterface,
      val: (StringPoolCase_t)&newValue);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10016A70
// Name: public: virtual void __near * ScaleformUIImpl::Value_Invoke(void __near *,char const __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::Value_Invoke(
        ScaleformUIImpl *this,
        void *obj,
        const char *methodName,
        const struct GFxValue *args,
        unsigned int numArgs)
{
  GFxValue *v5; // edi
  bool v6; // al
  GFxValue newValue; // [esp+8h] [ebp-20h] BYREF
  ScaleformUIImpl *v9; // [esp+18h] [ebp-10h]
  int v10; // [esp+24h] [ebp-4h]

  v9 = this;
  newValue.pObjectInterface = nullptr;
  newValue.Type = VT_Undefined;
  v5 = nullptr;
  v10 = 0;
  if ( args != nullptr && numArgs != 0 )
    v6 = GFxValue::ObjectInterface::Invoke(
           this: *(GFxValue::ObjectInterface **)obj,
           a2: *((void **)obj + 2),
           a3: &newValue,
           a4: methodName,
           a5: args,
           a6: numArgs,
           a7: (*((_DWORD *)obj + 1) & 0x8F) == 8);
  else
    v6 = GFxValue::ObjectInterface::Invoke(
           this: *(GFxValue::ObjectInterface **)obj,
           a2: *((void **)obj + 2),
           a3: &newValue,
           a4: methodName,
           a5: nullptr,
           a6: 0,
           a7: (*((_DWORD *)obj + 1) & 0x8F) == 8);
  if ( v6 )
    v5 = ScaleformUIImpl::CreateGFxValue(this: v9, pValue: &newValue);
  v10 = -1;
  if ( (newValue.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(
      this: (CStringPool *)newValue.pObjectInterface,
      val: (StringPoolCase_t)&newValue);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10016B50
// Name: public: void ScaleformUIImpl::AddAPIFunctionToObject(class GFxValue __near *,class GFxMovieView __near *,class ScaleformUIFunctionHandlerObject __near *,struct ScaleformUIFunctionHandlerDefinition const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::AddAPIFunctionToObject(
        ScaleformUIImpl *this,
        GFxValue *pAPI,
        GFxMovieView *pMovie,
        ScaleformUIFunctionHandlerObject *object,
        const ScaleformUIFunctionHandlerDefinition *pFunctionDef)
{
  struct GFxASUserData *v5; // esi
  void *(__thiscall *Alloc_2)(GMemoryHeap *, unsigned int, const GAllocDebugInfo *); // eax
  int v8; // eax
  __int64 v9; // xmm0_8
  __int64 v10; // xmm1_8
  GFxValue func; // [esp+Ch] [ebp-20h] BYREF
  int v12; // [esp+1Ch] [ebp-10h] BYREF
  int v13; // [esp+28h] [ebp-4h]

  v5 = nullptr;
  func.pObjectInterface = nullptr;
  func.Type = VT_Undefined;
  v12 = 2;
  Alloc_2 = GMemory::pGlobalHeap->Alloc_2;
  v13 = 0;
  v8 = (int)Alloc_2(this: GMemory::pGlobalHeap, a2: 40u, a3: (const GAllocDebugInfo *)&v12);
  if ( v8 != 0 )
  {
    v9 = *(_QWORD *)&pFunctionDef->m_pHandler;
    v10 = *((_QWORD *)&pFunctionDef->m_pHandler + 1);
    *(_DWORD *)v8 = &GRefCountImplCore::`vftable';
    *(_DWORD *)(v8 + 8) = 0;
    *(_DWORD *)(v8 + 12) = 0;
    *(_QWORD *)(v8 + 24) = v9;
    *(_DWORD *)(v8 + 4) = 1;
    *(_DWORD *)v8 = &ScaleformCallbackHolder::`vftable';
    *(_DWORD *)(v8 + 16) = object;
    *(_QWORD *)(v8 + 32) = v10;
    v5 = (struct GFxASUserData *)v8;
  }
  pMovie->CreateFunction(this: pMovie, a2: &func, a3: this->m_pFunctionAdapter.pObject, a4: v5);
  GFxValue::ObjectInterface::SetUserData(this: func.pObjectInterface, a2: func.Value.pStringManaged, a3: v5);
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)pAPI->pObjectInterface,
    pdata: (unsigned int)pAPI->Value.pString);
  v13 = -1;
  if ( (func.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)func.pObjectInterface, val: (StringPoolCase_t)&func);
}

//------------------------------------------------------------------------------
// Address: 0x10016C50
// Name: public: virtual void __near * ScaleformUIImpl::Value_GetText(void __near *)
// Source: json
//------------------------------------------------------------------------------
struct GFxValue *__thiscall ScaleformUIImpl::Value_GetText(ScaleformUIImpl *this, void *obj)
{
  int m_Size; // eax
  struct GFxValue *v3; // edi
  struct GFxValue *v4; // eax

  m_Size = this->m_ValueCache.m_Size;
  if ( m_Size != 0 )
  {
    v3 = this->m_ValueCache.m_Memory.m_pMemory[m_Size - 1];
    if ( m_Size > 0 )
      --this->m_ValueCache.m_Size;
  }
  else
  {
    v4 = (struct GFxValue *)MemAlloc_Alloc(nSize: 0x10u);
    if ( v4 != nullptr )
    {
      v4->pObjectInterface = nullptr;
      v4->Type = VT_Undefined;
    }
    else
    {
      v4 = nullptr;
    }
    v3 = v4;
  }
  GFxValue::ObjectInterface::GetText(
    this: *(GFxValue::ObjectInterface **)obj,
    a2: *((void **)obj + 2),
    a3: v3,
    a4: false);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10016CD0
// Name: public: virtual void __near * ScaleformUIImpl::Value_GetTextHTML(void __near *)
// Source: json
//------------------------------------------------------------------------------
struct GFxValue *__thiscall ScaleformUIImpl::Value_GetTextHTML(ScaleformUIImpl *this, void *obj)
{
  int m_Size; // eax
  struct GFxValue *v3; // edi
  struct GFxValue *v4; // eax

  m_Size = this->m_ValueCache.m_Size;
  if ( m_Size != 0 )
  {
    v3 = this->m_ValueCache.m_Memory.m_pMemory[m_Size - 1];
    if ( m_Size > 0 )
      --this->m_ValueCache.m_Size;
  }
  else
  {
    v4 = (struct GFxValue *)MemAlloc_Alloc(nSize: 0x10u);
    if ( v4 != nullptr )
    {
      v4->pObjectInterface = nullptr;
      v4->Type = VT_Undefined;
    }
    else
    {
      v4 = nullptr;
    }
    v3 = v4;
  }
  GFxValue::ObjectInterface::GetText(
    this: *(GFxValue::ObjectInterface **)obj,
    a2: *((void **)obj + 2),
    a3: v3,
    a4: true);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10016D50
// Name: public: virtual void __near * ScaleformUIImpl::Value_GetArrayElement(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
struct GFxValue *__thiscall ScaleformUIImpl::Value_GetArrayElement(
        ScaleformUIImpl *this,
        void *obj,
        unsigned int index)
{
  int m_Size; // eax
  struct GFxValue *v4; // edi
  struct GFxValue *v5; // eax

  m_Size = this->m_ValueCache.m_Size;
  if ( m_Size != 0 )
  {
    v4 = this->m_ValueCache.m_Memory.m_pMemory[m_Size - 1];
    if ( m_Size > 0 )
      --this->m_ValueCache.m_Size;
  }
  else
  {
    v5 = (struct GFxValue *)MemAlloc_Alloc(nSize: 0x10u);
    if ( v5 != nullptr )
    {
      v5->pObjectInterface = nullptr;
      v5->Type = VT_Undefined;
    }
    else
    {
      v5 = nullptr;
    }
    v4 = v5;
  }
  GFxValue::ObjectInterface::GetElement(
    this: *(GFxValue::ObjectInterface **)obj,
    a2: *((void **)obj + 2),
    a3: index,
    a4: v4);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10016DD0
// Name: protected: void ScaleformUIImpl::ShutdownValueImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ShutdownValueImpl(ScaleformUIImpl *this)
{
  ScaleformUIImpl *v1; // edi
  int i; // ebx
  StringPoolCase_t v3; // esi
  bool v4; // sf
  CUtlVector<GFxValue *,CUtlMemory<GFxValue *,int> > *m_ValueArrayCaches; // esi
  int k; // ebx
  GFxValue *v7; // eax
  char *v8; // edi
  IShaderAPI *pObject; // ecx
  int j; // [esp+10h] [ebp-4h]

  v1 = this;
  for ( i = this->m_ValueCache.m_Size; i != 0; --i )
  {
    v3 = (StringPoolCase_t)v1->m_ValueCache.m_Memory.m_pMemory[i - 1];
    if ( (v3 < (unsigned int)VALUE_BANK || v3 >= (unsigned int)&vec2_origin_18) && v3 != StringPoolCaseInsensitive )
    {
      if ( (*(_DWORD *)(v3 + 4) & 0x40) != 0 )
      {
        GFxValue::ObjectInterface::ObjectRelease(this: *(CStringPool **)v3, val: v3);
        *(_DWORD *)v3 = 0;
      }
      free(pMem: (void *)v3);
    }
  }
  v4 = v1->m_ValueCache.m_Memory.m_nGrowSize < 0;
  v1->m_ValueCache.m_Size = 0;
  if ( !v4 )
  {
    if ( v1->m_ValueCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_ValueCache.m_Memory.m_pMemory);
      v1->m_ValueCache.m_Memory.m_pMemory = nullptr;
    }
    v1->m_ValueCache.m_Memory.m_nAllocationCount = 0;
  }
  v1->m_ValueCache.m_pElements = v1->m_ValueCache.m_Memory.m_pMemory;
  m_ValueArrayCaches = v1->m_ValueArrayCaches;
  for ( j = 9; j != 0; --j )
  {
    for ( k = m_ValueArrayCaches->m_Size; k != 0; --k )
    {
      v7 = m_ValueArrayCaches->m_Memory.m_pMemory[k - 1];
      if ( (v7 < VALUE_ARRAY_BANK || v7 >= VALUE_BANK) && v7 != nullptr )
      {
        v8 = (char *)(&v7[-1].Value.pStringManaged + 1);
        `eh vector destructor iterator'(
          ptr: v7,
          size: 0x10u,
          count: *((_DWORD *)&v7[-1].Value.pStringManaged + 1),
          pDtor: (void (__thiscall *)(void *))GFxValue::~GFxValue);
        free(pMem: v8);
        v1 = this;
      }
    }
    v4 = m_ValueArrayCaches->m_Memory.m_nGrowSize < 0;
    m_ValueArrayCaches->m_Size = 0;
    if ( !v4 )
    {
      if ( m_ValueArrayCaches->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_ValueArrayCaches->m_Memory.m_pMemory);
        m_ValueArrayCaches->m_Memory.m_pMemory = nullptr;
      }
      m_ValueArrayCaches->m_Memory.m_nAllocationCount = 0;
    }
    m_ValueArrayCaches->m_pElements = m_ValueArrayCaches->m_Memory.m_pMemory;
    ++m_ValueArrayCaches;
  }
  pObject = (IShaderAPI *)v1->m_pFunctionAdapter.pObject;
  if ( pObject != nullptr )
    GRefCountImpl::Release(this: pObject);
  v1->m_pFunctionAdapter.pObject = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10016F40
// Name: protected: void ScaleformUIImpl::InitValueImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::InitValueImpl(ScaleformUIImpl *this)
{
  CUtlMemory<S3RGBA,int> *p_m_ValueCache; // esi
  GFxValue *v2; // ebx
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v5; // ecx
  int v6; // eax
  GFxValue **v7; // edi
  int *p_m_Size; // esi
  int v9; // edi
  int v10; // eax
  GFxValue *v11; // ebx
  int v12; // ecx
  int v13; // eax
  GFxValue **v14; // edi
  ScaleformFunctionHandlerAdapter *v15; // eax
  ScaleformFunctionHandlerAdapter *v16; // esi
  IShaderAPI *pObject; // ecx
  int i; // [esp+10h] [ebp-8h] BYREF
  int element; // [esp+14h] [ebp-4h]

  p_m_ValueCache = (CUtlMemory<S3RGBA,int> *)&this->m_ValueCache;
  v2 = VALUE_BANK;
  do
  {
    m_pMemory = p_m_ValueCache[1].m_pMemory;
    m_nAllocationCount = p_m_ValueCache->m_nAllocationCount;
    if ( (int)&m_pMemory->g > m_nAllocationCount )
      CUtlMemory<IMaterialVar *,int>::Grow(this: p_m_ValueCache, num: (int)(&m_pMemory->g - m_nAllocationCount));
    ++p_m_ValueCache[1].m_pMemory;
    v5 = p_m_ValueCache->m_pMemory;
    v6 = (char *)p_m_ValueCache[1].m_pMemory - (char *)m_pMemory - 1;
    p_m_ValueCache[1].m_nAllocationCount = (int)p_m_ValueCache->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &v5[(_DWORD)m_pMemory + 1], src: &v5[(_DWORD)m_pMemory], count: 4 * v6);
    v7 = (GFxValue **)&p_m_ValueCache->m_pMemory[(_DWORD)m_pMemory];
    if ( v7 != nullptr )
      *v7 = v2;
    ++v2;
  }
  while ( (int)v2 < (int)&vec2_origin_18 );
  element = 0;
  i = 0;
  p_m_Size = &this->m_ValueArrayCaches[0].m_Size;
  do
  {
    v9 = *p_m_Size;
    v10 = *(p_m_Size - 2);
    v11 = &VALUE_ARRAY_BANK[element];
    if ( *p_m_Size + 1 > v10 )
      CUtlMemory<IMaterialVar *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)p_m_Size - 1, num: v9 - v10 + 1);
    ++*p_m_Size;
    v12 = *(p_m_Size - 3);
    v13 = *p_m_Size - v9 - 1;
    p_m_Size[1] = v12;
    if ( v13 > 0 )
      _V_memmove(dest: (void *)(v12 + 4 * v9 + 4), src: (const void *)(v12 + 4 * v9), count: 4 * v13);
    v14 = (GFxValue **)(*(p_m_Size - 3) + 4 * v9);
    if ( v14 != nullptr )
      *v14 = v11;
    p_m_Size += 5;
    element += i + 2;
    ++i;
  }
  while ( i <= 2 );
  i = 2;
  v15 = (ScaleformFunctionHandlerAdapter *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 8, a3: &i);
  if ( v15 != nullptr )
  {
    v15->__vftable = (ScaleformFunctionHandlerAdapter_vtbl *)&GRefCountImplCore::`vftable';
    v15->RefCount = 1;
    v15->__vftable = (ScaleformFunctionHandlerAdapter_vtbl *)&ScaleformFunctionHandlerAdapter::`vftable';
    v16 = v15;
  }
  else
  {
    v16 = nullptr;
  }
  pObject = (IShaderAPI *)this->m_pFunctionAdapter.pObject;
  if ( pObject != nullptr )
    GRefCountImpl::Release(this: pObject);
  this->m_pFunctionAdapter.pObject = v16;
}

//------------------------------------------------------------------------------
// Address: 0x10017090
// Name: protected: void ScaleformUIImpl::ReleaseGFxValue(class GFxValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ReleaseGFxValue(ScaleformUIImpl *this, GFxValue *pValue)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  GFxValue **m_pMemory; // ecx
  int v6; // eax
  GFxValue **v7; // edi

  if ( (pValue->Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(
      this: (CStringPool *)pValue->pObjectInterface,
      val: (StringPoolCase_t)pValue);
    pValue->pObjectInterface = nullptr;
  }
  pValue->Type = VT_Null;
  m_Size = this->m_ValueCache.m_Size;
  m_nAllocationCount = this->m_ValueCache.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IMaterialVar *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_ValueCache,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_ValueCache.m_Size;
  m_pMemory = this->m_ValueCache.m_Memory.m_pMemory;
  v6 = this->m_ValueCache.m_Size - m_Size - 1;
  this->m_ValueCache.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_ValueCache.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pValue;
}

//------------------------------------------------------------------------------
// Address: 0x10017130
// Name: public: virtual void ScaleformUIImpl::ReleaseValue(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ReleaseValue(ScaleformUIImpl *this, GFxValue *value)
{
  if ( value != nullptr )
    ScaleformUIImpl::ReleaseGFxValue(this, pValue: value);
}

//------------------------------------------------------------------------------
// Address: 0x10017150
// Name: public: virtual void ScaleformUIImpl::ReleaseValueArray(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ReleaseValueArray(ScaleformUIImpl *this, _DWORD *valueArray, unsigned int length)
{
  _DWORD *v3; // edi
  unsigned int v4; // ebx
  StringPoolCase_t v5; // esi
  int v6; // eax
  bool v7; // zf
  int v8; // edi
  CUtlMemory<S3RGBA,int> *v9; // esi
  int v10; // eax
  S3RGBA *m_pMemory; // ecx
  int v12; // eax
  S3RGBA *v13; // eax
  ScaleformUIImpl *v14; // [esp+4h] [ebp-4h]

  v3 = valueArray;
  v14 = this;
  if ( valueArray != nullptr )
  {
    v4 = length;
    if ( length == 1 )
    {
      this->ReleaseValue(this, a2: valueArray);
    }
    else
    {
      if ( length != 0 )
      {
        do
        {
          v5 = (StringPoolCase_t)v3;
          v6 = v3[1] >> 6;
          v3 += 4;
          if ( (v6 & 1) != 0 )
          {
            GFxValue::ObjectInterface::ObjectRelease(this: *(CStringPool **)v5, val: v5);
            *(_DWORD *)v5 = 0;
          }
          v7 = length-- == 1;
          *(_DWORD *)(v5 + 4) = 1;
        }
        while ( !v7 );
        this = v14;
      }
      v8 = *(&this->m_MovieDefCache.m_Size + 5 * v4);
      v9 = (CUtlMemory<S3RGBA,int> *)(&this->m_MovieDefCache + v4);
      v10 = *(&this->m_MovieDefCache.m_Memory.m_nAllocationCount + 5 * v4);
      if ( v8 + 1 > v10 )
        CUtlMemory<IMaterialVar *,int>::Grow(this: v9, num: v8 - v10 + 1);
      ++v9[1].m_pMemory;
      m_pMemory = v9->m_pMemory;
      v12 = (int)v9[1].m_pMemory - v8 - 1;
      v9[1].m_nAllocationCount = (int)v9->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * v12);
      v13 = &v9->m_pMemory[v8];
      if ( v13 != nullptr )
        *v13 = (S3RGBA)valueArray;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028A220
// Name: _dynamic_initializer_for__ScaleformUIImpl::m_Instance__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__ScaleformUIImpl::m_Instance__()
{
  ScaleformUIImpl::ScaleformUIImpl(this: &ScaleformUIImpl::m_Instance);
  return atexit(func: dynamic_atexit_destructor_for__ScaleformUIImpl::m_Instance__);
}

//------------------------------------------------------------------------------
// Address: 0x1028C080
// Name: _dynamic_atexit_destructor_for__ScaleformUIImpl::m_Instance__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ScaleformUIImpl::m_Instance__()
{
  ScaleformUIImpl::~ScaleformUIImpl(this: &ScaleformUIImpl::m_Instance);
}

//------------------------------------------------------------------------------
// Address: 0x1028A240
// Name: _dynamic_initializer_for____g_CreateScaleformUIImplIScaleformUI_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateScaleformUIImplIScaleformUI_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateScaleformUIImplIScaleformUI_reg,
           fn: (void *(__cdecl *)())_CreateScaleformUIImplIScaleformUI_interface,
           pName: "ScaleformUI001");
}

//------------------------------------------------------------------------------
// Address: 0x1028A260
// Name: _dynamic_initializer_for__safezonex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__safezonex__()
{
  ConVar::ConVar(
    this: &safezonex,
    pName: "safezonex",
    pDefaultValue: "0.85",
    flags: 128,
    pHelpString: "The percentage of the screen width that is considered safe from overscan");
  return atexit(func: dynamic_atexit_destructor_for__safezonex__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A290
// Name: _dynamic_initializer_for__safezoney__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__safezoney__()
{
  ConVar::ConVar(
    this: &safezoney,
    pName: "safezoney",
    pDefaultValue: "0.85",
    flags: 128,
    pHelpString: "The percentage of the screen height that is considered safe from overscan");
  return atexit(func: dynamic_atexit_destructor_for__safezoney__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A2C0
// Name: _dynamic_initializer_for__sf_ui_tint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sf_ui_tint__()
{
  ConVar::ConVar(
    this: &sf_ui_tint,
    pName: "sf_ui_tint",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "The current tint applied to the Scaleform UI");
  return atexit(func: dynamic_atexit_destructor_for__sf_ui_tint__);
}

//------------------------------------------------------------------------------
// Address: 0x1028A2F0
// Name: _dynamic_initializer_for__LOG_SCALEFORM__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_SCALEFORM__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "Scaleform",
             a2: 0,
             a3: 0,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR_9);
  LOG_SCALEFORM = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028A310
// Name: _dynamic_initializer_for__LOG_SCALEFORM_SCRIPT__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_SCALEFORM_SCRIPT__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "ScaleformScript",
             a2: 0,
             a3: 0,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR_9);
  LOG_SCALEFORM_SCRIPT = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028A330
// Name: _dynamic_initializer_for__LOG_SCALEFORM_PARSE__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_SCALEFORM_PARSE__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "ScaleformParse",
             a2: 0,
             a3: 0,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR_9);
  LOG_SCALEFORM_PARSE = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028A350
// Name: _dynamic_initializer_for__LOG_SCALEFORM_AS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_SCALEFORM_AS__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "ScaleformAS",
             a2: 0,
             a3: 0,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR_9);
  LOG_SCALEFORM_AS = result;
  return result;
}
