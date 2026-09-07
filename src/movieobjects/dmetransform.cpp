// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmetransform.cpp
// Functions: 16
// ============================================================

#include "movieobjects\dmetransform.h"

//------------------------------------------------------------------------------
// Address: 0x004B2060
// Name: public: virtual void CDmeTransform::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTransform::OnAttributeChanged(
        CDmeTransform *this@<ecx>,
        DmAttributeReferenceIterator_t a2@<edi>,
        CDmAttribute *pAttribute)
{
  DmElementHandle_t v3; // eax

  v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
  InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: v3, pChangedAttr: pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x004B2080
// Name: public: void CDmeTransform::SetTransform(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetTransform(CDmeTransform *this, const matrix3x4_t *transform)
{
  Quaternion angles; // [esp+4h] [ebp-1Ch] BYREF
  Vector origin; // [esp+14h] [ebp-Ch] BYREF

  MatrixAngles(matrix: transform, q: &angles, pos: &origin);
  CDmAttribute::SetValue<Quaternion>(this: this->m_Orientation.m_pAttribute, value: &angles);
  CDmAttribute::SetValue<Vector>(this: this->m_Position.m_pAttribute, value: &origin);
}

//------------------------------------------------------------------------------
// Address: 0x004B20C0
// Name: public: void CDmeTransform::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetPosition(CDmeTransform *this, const Vector *vecPosition)
{
  CDmAttribute::SetValue<Vector>(this: this->m_Position.m_pAttribute, value: vecPosition);
}

//------------------------------------------------------------------------------
// Address: 0x004B20D0
// Name: public: void CDmeTransform::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetOrientation(CDmeTransform *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_Orientation.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x004B20E0
// Name: public: class CDmAttribute __near * CDmeTransform::GetOrientationAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTransform::GetOrientationAttribute(CDmeTransform *this)
{
  return this->m_Orientation.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x004B20F0
// Name: public: void CDmeTransform::GetTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::GetTransform(CDmeTransform *this, matrix3x4_t *transform)
{
  QuaternionMatrix(q: &this->m_Orientation.m_Storage, pos: &this->m_Position.m_Storage, matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x004B2110
// Name: public: class Vector const __near & CDmeTransform::GetPosition(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmeTransform::GetPosition(CDmeTransform *this)
{
  return &this->m_Position;
}

//------------------------------------------------------------------------------
// Address: 0x004B2120
// Name: public: class Quaternion const __near & CDmeTransform::GetOrientation(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmeTransform::GetOrientation(CDmeTransform *this)
{
  return &this->m_Orientation;
}

//------------------------------------------------------------------------------
// Address: 0x004B21C0
// Name: public: virtual bool CDmeTransform::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransform::IsA(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B21F0
// Name: public: virtual int CDmeTransform::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransform::GetInheritanceDepth(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B22C0
// Name: protected: virtual void CDmeTransform::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::PerformConstruction(CDmeTransform *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax

  CDmeFXClip::OnDestruction();
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "position", type: AT_VECTOR3, pMemory: &this->m_Position);
  this->m_Position.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "orientation",
         type: AT_QUATERNION,
         pMemory: &this->m_Orientation);
  this->m_Orientation.m_pAttribute = v3;
  v3->m_nFlags |= 0x100u;
}

//------------------------------------------------------------------------------
// Address: 0x005ABEC0
// Name: _dynamic_initializer_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransform::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransform pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AFBC0
// Name: _dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransform::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ABEF0
// Name: _dynamic_initializer_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransform_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransform_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ABF00
// Name: _dynamic_initializer_for__g_CDmeTransform_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransform_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransform_Helper,
           classname: "DmeTransform",
           pFactory: &g_CDmeTransform_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AFBD0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransform_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransform_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004F8ED0
// Name: public: virtual void CDmeTransform::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTransform::OnAttributeChanged(
        CDmeTransform *this@<ecx>,
        DmAttributeReferenceIterator_t a2@<edi>,
        CDmAttribute *pAttribute)
{
  DmElementHandle_t BufferType; // eax

  BufferType = CCodecBuffer_Block::GetBufferType((CExpressionCalculator *)this);
  InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: BufferType, pChangedAttr: pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x004F8EF0
// Name: public: void CDmeTransform::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetPosition(CDmeTransform *this, const Vector *vecPosition)
{
  CDmAttribute::SetValue<Vector>(this: this->m_Position.m_pAttribute, value: vecPosition);
}

//------------------------------------------------------------------------------
// Address: 0x004F8F00
// Name: public: void CDmeTransform::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetOrientation(CDmeTransform *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_Orientation.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x004F8F10
// Name: public: class CDmAttribute __near * CDmeTransform::GetOrientationAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTransform::GetOrientationAttribute(CDmeTransform *this)
{
  return this->m_Orientation.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x004F8FD0
// Name: public: void CDmeTransform::GetTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::GetTransform(CDmeTransform *this, matrix3x4_t *transform)
{
  QuaternionMatrix(q: &this->m_Orientation.m_Storage, pos: &this->m_Position.m_Storage, matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x004F9090
// Name: public: class CDmeDag __near * CDmeTransform::GetDag(void)
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeTransform::GetDag(CDmeTransform *this)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx

  if ( (_S1_5 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_5 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symTransform, a3: "transform");
  }
  return FindReferringElement<CDmeDag>(
           pElement: this,
           symAttrName: symTransform,
           bMustBeInSameFile: true,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x004F9170
// Name: public: virtual bool CDmeTransform::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransform::IsA(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F91A0
// Name: public: virtual int CDmeTransform::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransform::GetInheritanceDepth(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F9270
// Name: protected: virtual void CDmeTransform::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::PerformConstruction(CDmeTransform *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "position", type: AT_VECTOR3, pMemory: &this->m_Position);
  this->m_Position.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "orientation",
         type: AT_QUATERNION,
         pMemory: &this->m_Orientation);
  this->m_Orientation.m_pAttribute = v3;
  v3->m_nFlags |= 0x100u;
}

//------------------------------------------------------------------------------
// Address: 0x005B6A40
// Name: public: class Vector const __near & CDmeTransform::GetPosition(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmeTransform::GetPosition(CDmeTransform *this)
{
  return &this->m_Position;
}

//------------------------------------------------------------------------------
// Address: 0x0067CDA0
// Name: _dynamic_initializer_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransform::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransform pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00681D60
// Name: _dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransform::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004F2850
// Name: float Clstr(unsigned long __near * const,unsigned short,unsigned char (__near * const)[2],unsigned char __near *,unsigned char,float __near *,bool,unsigned char,unsigned char,unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl Clstr(
        unsigned int *const a1,
        unsigned __int16 a2,
        unsigned __int8 (*const a3)[2],
        unsigned __int8 *a4,
        char a5,
        float *a6,
        int a7,
        unsigned __int8 a8,
        unsigned __int8 a9,
        unsigned __int8 a10,
        unsigned __int8 a11)
{
  char v11; // bl
  char v12; // bp
  unsigned int v13; // esi
  int v14; // eax
  int v15; // edi
  int v16; // ebx
  int v17; // ebp
  unsigned int v18; // edi
  int v19; // ecx
  int v20; // ecx
  int v21; // eax
  double v22; // st7
  int v23; // ecx
  unsigned int v24; // edi
  int v25; // esi
  double v26; // st7
  double v27; // st6
  unsigned __int8 *v28; // ecx
  unsigned int v29; // ebp
  float *v30; // edx
  int v31; // eax
  double v32; // rt0
  double v33; // st6
  double v34; // st7
  double v35; // rt1
  double v36; // rt2
  int v37; // eax
  double v38; // rtt
  double v39; // st6
  double v40; // st7
  double v41; // rt0
  double v42; // rt1
  int v43; // eax
  double v44; // rt2
  double v45; // st6
  double v46; // st7
  double v47; // rtt
  double v48; // rt0
  int v49; // eax
  double v50; // rt1
  double v51; // st6
  double v52; // st7
  double v53; // rt2
  double v54; // rtt
  float *v55; // eax
  int v56; // edx
  double v57; // rt0
  double v58; // st6
  double v59; // st7
  double v60; // rt1
  double v61; // rt2
  char v63; // [esp+10h] [ebp-42Ch]
  int v64; // [esp+10h] [ebp-42Ch]
  int v65; // [esp+10h] [ebp-42Ch]
  int v66; // [esp+10h] [ebp-42Ch]
  int v67; // [esp+10h] [ebp-42Ch]
  int v68; // [esp+10h] [ebp-42Ch]
  int v69; // [esp+10h] [ebp-42Ch]
  int v70; // [esp+10h] [ebp-42Ch]
  char v71; // [esp+14h] [ebp-428h]
  float v72; // [esp+14h] [ebp-428h]
  float v73; // [esp+14h] [ebp-428h]
  float v74; // [esp+14h] [ebp-428h]
  float v75; // [esp+14h] [ebp-428h]
  float v76; // [esp+14h] [ebp-428h]
  float v77[8]; // [esp+1Ch] [ebp-420h] BYREF
  int v78; // [esp+3Ch] [ebp-400h] BYREF
  _QWORD v79[126]; // [esp+40h] [ebp-3FCh] BYREF

  v11 = *((_BYTE *)&nByteBitsMask + a10);
  v12 = *((_BYTE *)&nByteBitsMask + a9);
  v71 = *((_BYTE *)&nByteBitsMask + a11);
  v63 = a11 + a10 - 8;
  v13 = ((unsigned __int8)(v71 & (*a3)[0]) >> (8 - a11))
      | ((unsigned __int8)(v12 & (*a3)[4]) << (a11 + a10 + a9 - 8))
      | ((unsigned __int8)(v11 & (*a3)[2]) << v63);
  v14 = 0;
  v15 = ((unsigned __int8)(v11 & (*a3)[3]) << v63) | ((unsigned __int8)(v71 & (*a3)[1]) >> (8 - a11));
  v16 = (unsigned __int8)(v12 & (*a3)[5]) << (a11 + a10 + a9 - 8);
  v17 = 1;
  v18 = v16 | v15;
  if ( (a5 & 1) == 0 && v13 <= v18 || (a5 & 1) != 0 && v13 > v18 )
  {
    v14 = 1;
    v17 = 0;
  }
  v19 = (*a3)[v17 + 4];
  v77[4] = (float)(*a3)[v14 + 4];
  v64 = v19;
  v20 = (*a3)[v14 + 2];
  v21 = (*a3)[v14];
  v77[5] = (float)v64;
  v22 = (double)v20;
  v65 = (*a3)[v17 + 2];
  v23 = (*a3)[v17];
  v77[2] = v22;
  v77[3] = (float)v65;
  v24 = a8 << 24;
  v25 = 0;
  v77[0] = (float)v21;
  v77[1] = (float)v23;
  v26 = 1.0;
  v27 = 0.0;
  if ( a2 >= 4u )
  {
    v28 = (unsigned __int8 *)a1 + 1;
    v29 = (((unsigned int)a2 - 4) >> 2) + 1;
    v30 = (float *)v79;
    v25 = 4 * v29;
    do
    {
      v66 = *v28;
      v31 = *(v28 - 1);
      v30[1] = (float)v28[1];
      *v30 = (float)v66;
      *(v30 - 1) = (float)v31;
      if ( (_BYTE)a7 != 0 )
      {
        if ( (*(_DWORD *)(v28 - 1) & 0xFF000000) < v24 )
        {
          v72 = v27;
          v35 = v27;
          v33 = v26;
          v34 = v35;
        }
        else
        {
          v32 = v27;
          v33 = v26;
          v34 = v32;
          v72 = v33;
        }
        v30[2] = v72;
        v36 = v33;
        v27 = v34;
        v26 = v36;
      }
      v67 = v28[4];
      v37 = v28[3];
      v30[5] = (float)v28[5];
      v30[4] = (float)v67;
      v30[3] = (float)v37;
      if ( (_BYTE)a7 != 0 )
      {
        if ( (*(_DWORD *)(v28 + 3) & 0xFF000000) < v24 )
        {
          v73 = v27;
          v41 = v27;
          v39 = v26;
          v40 = v41;
        }
        else
        {
          v38 = v27;
          v39 = v26;
          v40 = v38;
          v73 = v39;
        }
        v30[6] = v73;
        v42 = v39;
        v27 = v40;
        v26 = v42;
      }
      v68 = v28[8];
      v43 = v28[7];
      v30[9] = (float)v28[9];
      v30[8] = (float)v68;
      v30[7] = (float)v43;
      if ( (_BYTE)a7 != 0 )
      {
        if ( (*(_DWORD *)(v28 + 7) & 0xFF000000) < v24 )
        {
          v74 = v27;
          v47 = v27;
          v45 = v26;
          v46 = v47;
        }
        else
        {
          v44 = v27;
          v45 = v26;
          v46 = v44;
          v74 = v45;
        }
        v30[10] = v74;
        v48 = v45;
        v27 = v46;
        v26 = v48;
      }
      v69 = v28[12];
      v49 = v28[11];
      v30[13] = (float)v28[13];
      v30[12] = (float)v69;
      v30[11] = (float)v49;
      if ( (_BYTE)a7 != 0 )
      {
        if ( (*(_DWORD *)(v28 + 11) & 0xFF000000) < v24 )
        {
          v75 = v27;
          v53 = v27;
          v51 = v26;
          v52 = v53;
        }
        else
        {
          v50 = v27;
          v51 = v26;
          v52 = v50;
          v75 = v51;
        }
        v30[14] = v75;
        v54 = v51;
        v27 = v52;
        v26 = v54;
      }
      v28 += 16;
      v30 += 16;
      --v29;
    }
    while ( v29 != 0 );
  }
  if ( v25 < a2 )
  {
    v55 = (float *)&v79[2 * v25];
    do
    {
      v70 = BYTE1(a1[v25]);
      v56 = LOBYTE(a1[v25]);
      v55[1] = (float)BYTE2(a1[v25]);
      *v55 = (float)v70;
      *(v55 - 1) = (float)v56;
      if ( (_BYTE)a7 != 0 )
      {
        if ( (a1[v25] & 0xFF000000) < v24 )
        {
          v76 = v27;
          v60 = v27;
          v58 = v26;
          v59 = v60;
        }
        else
        {
          v57 = v27;
          v58 = v26;
          v59 = v57;
          v76 = v58;
        }
        v55[2] = v76;
        v61 = v58;
        v27 = v59;
        v26 = v61;
      }
      ++v25;
      v55 += 4;
    }
    while ( v25 < a2 );
  }
  sub_4F27A0(a1: a10, a2: (int)a4, a3: (int)&v78, a4: (float (*)[2])v77, a5: a2, a6: a5, a7: (int)a6, a8: a7, a9);
  return v27;
}

//------------------------------------------------------------------------------
// Address: 0x004F2C10
// Name: float Clstr(float __near * const,unsigned short,unsigned char (__near * const)[2],unsigned char __near *,unsigned char,float __near *,bool,float,unsigned char,unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl Clstr(
        float *const a1,
        unsigned __int16 a2,
        unsigned __int8 (*const a3)[2],
        unsigned __int8 *a4,
        char a5,
        float *a6,
        int a7,
        float a8,
        unsigned __int8 a9,
        unsigned __int8 a10,
        unsigned __int8 a11)
{
  char v11; // bl
  char v12; // di
  unsigned int v13; // edx
  int v14; // ebp
  int v15; // esi
  int v16; // ebx
  int v17; // edi
  unsigned int v18; // esi
  int v19; // ecx
  int v20; // edx
  double v21; // st7
  int v22; // ecx
  double v23; // st7
  int v24; // edx
  double result; // st7
  double v26; // st6
  int *v27; // edx
  double v28; // st5
  float *v29; // ecx
  int i; // ebx
  double v31; // rt0
  double v32; // st5
  double v33; // st6
  double v34; // rt1
  double v35; // rt2
  int v36; // [esp+10h] [ebp-42Ch]
  int v37; // [esp+10h] [ebp-42Ch]
  int v38; // [esp+10h] [ebp-42Ch]
  float v39; // [esp+10h] [ebp-42Ch]
  float v40; // [esp+14h] [ebp-428h]
  char v41; // [esp+18h] [ebp-424h]
  float v42[8]; // [esp+1Ch] [ebp-420h] BYREF
  int v43; // [esp+3Ch] [ebp-400h] BYREF
  char v44; // [esp+40h] [ebp-3FCh] BYREF
  char v45; // [esp+44h] [ebp-3F8h] BYREF

  v11 = *((_BYTE *)&nByteBitsMask + a10);
  v12 = *((_BYTE *)&nByteBitsMask + a9);
  v41 = *((_BYTE *)&nByteBitsMask + a11);
  v13 = ((unsigned __int8)(v41 & (*a3)[0]) >> (8 - a11))
      | ((unsigned __int8)(v12 & (*a3)[4]) << (a11 + a10 + a9 - 8))
      | ((unsigned __int8)(v11 & (*a3)[2]) << (a11 + a10 - 8));
  v14 = 1;
  v15 = ((unsigned __int8)(v11 & (*a3)[3]) << (a11 + a10 - 8)) | ((unsigned __int8)(v41 & (*a3)[1]) >> (8 - a11));
  v16 = (unsigned __int8)(v12 & (*a3)[5]) << (a11 + a10 + a9 - 8);
  v17 = 0;
  v18 = v16 | v15;
  if ( (a5 & 1) == 0 && v13 <= v18 || (a5 & 1) != 0 && v13 > v18 )
  {
    v17 = 1;
    v14 = 0;
  }
  v19 = (*a3)[v17 + 2];
  v36 = (*a3)[v14 + 4];
  v20 = (*a3)[v14 + 2];
  v42[4] = (float)(*a3)[v17 + 4];
  v21 = (double)v36;
  v37 = v19;
  v22 = (*a3)[v17];
  v42[5] = v21;
  v23 = (double)v37;
  v38 = v20;
  v24 = (*a3)[v14];
  v42[2] = v23;
  v42[3] = (float)v38;
  v42[0] = (float)v22;
  v42[1] = (float)v24;
  result = a8 * 255.0;
  if ( a2 != 0 )
  {
    v26 = 1.0;
    v27 = &v43;
    v28 = 0.0;
    v29 = a1 + 1;
    for ( i = a2; i != 0; --i )
    {
      *(float *)((char *)v29 + &v44 - (char *)a1) = v29[1];
      *(float *)((char *)v29 + (char *)&v43 - (char *)a1) = *v29;
      *v27 = *((int *)v29 - 1);
      if ( (_BYTE)a7 != 0 )
      {
        v39 = result;
        if ( v29[2] < (double)v39 )
        {
          v40 = v28;
          v34 = v28;
          v32 = v26;
          v33 = v34;
        }
        else
        {
          v31 = v28;
          v32 = v26;
          v33 = v31;
          v40 = v32;
        }
        *(float *)((char *)v29 + &v45 - (char *)a1) = v40;
        v35 = v32;
        v28 = v33;
        v26 = v35;
      }
      v27 += 4;
      v29 += 4;
    }
    result = v28;
  }
  sub_4F27A0(a1: a10, a2: (int)a4, a3: (int)&v43, a4: (float (*)[2])v42, a5: a2, a6: a5, a7: (int)a6, a8: a7, a9);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F2E40
// Name: sub_4F2E40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall sub_4F2E40@<st0>(int a1@<eax>, int a2@<ecx>, float *a3, int a4, float a5, float a6, float a7, int a8)
{
  double v8; // st7
  float *v9; // esi
  int v10; // edi
  double v11; // st6
  int v12; // ecx
  double v13; // rt1
  double v14; // st6
  double v15; // st7
  double v16; // st7
  double v17; // rtt
  float v19; // [esp+30h] [ebp-18h]
  float v20; // [esp+34h] [ebp-14h]
  float v21; // [esp+34h] [ebp-14h]
  float v22; // [esp+34h] [ebp-14h]
  float v23; // [esp+34h] [ebp-14h]
  float v24; // [esp+34h] [ebp-14h]
  float v25; // [esp+34h] [ebp-14h]
  float v26; // [esp+34h] [ebp-14h]
  float v27; // [esp+38h] [ebp-10h]
  float v28; // [esp+3Ch] [ebp-Ch]
  float v29; // [esp+40h] [ebp-8h]
  int v30; // [esp+44h] [ebp-4h]

  v19 = 0.0;
  v8 = a7;
  v9 = a3;
  v10 = 0;
  v11 = a6;
  v27 = (a7 - a6) / (double)(a1 - 1);
  if ( a8 <= 0 )
    return v19;
  v12 = a2 - (_DWORD)a3;
  v30 = v12;
  while ( 1 )
  {
    v20 = *v9 - v11;
    if ( v20 > 0.0 )
    {
      if ( *v9 - v8 < 0.0 )
      {
        v28 = 0.5 * v27;
        v29 = 1.0 / v27;
        v22 = (v20 + v28) * v29;
        v16 = floor(X: v22);
        v12 = v30;
        v23 = v16;
        v15 = a6;
        v21 = v23 * v27 + a6;
        v14 = a7;
      }
      else
      {
        v13 = v11;
        v14 = v8;
        v15 = v13;
        v21 = v14;
      }
      v17 = v14;
      v11 = v15;
      v8 = v17;
    }
    else
    {
      v21 = v11;
    }
    v24 = *v9 - v21;
    v25 = v24 * v24;
    v26 = v25 * *(float *)((char *)v9 + a4 - (_DWORD)a3) + *(float *)((char *)v9 + v12);
    v19 = v26 + v19;
    if ( v19 > (double)a5 )
      break;
    ++v10;
    ++v9;
    if ( v10 >= a8 )
      return v19;
  }
  return a5;
}

//------------------------------------------------------------------------------
// Address: 0x004F2FB0
// Name: sub_4F2FB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_4F2FB0(float *a1@<eax>, float *a2, float *a3, bool *a4, float *a5, int a6, int a7, int a8)
{
  float *v8; // ecx
  int v9; // ebx
  float *v10; // ebp
  int v12; // edi
  int v13; // edx
  float *v14; // ecx
  unsigned int v15; // edi
  int v16; // eax
  double v17; // st6
  int v18; // eax
  double v19; // st6
  double v20; // st6
  float *v21; // edx
  int v22; // edi
  float *v23; // eax
  int v24; // ecx
  double v25; // st5
  int v26; // ebx
  double v27; // st4
  double v28; // st4
  double v29; // st4
  double v30; // st4
  float *v31; // edx
  int v32; // eax
  double v33; // st4
  double v34; // st5
  int v35; // ebx
  double v36; // st4
  int v37; // edx
  bool v38; // zf
  int v39; // edi
  int v40; // esi
  double v41; // st4
  double v42; // st3
  double v43; // st2
  double v44; // st7
  char v45; // fps^1
  bool v46; // c0
  char v47; // c2
  bool v48; // c3
  bool v49; // al
  int v50; // ebx
  int v51; // esi
  double v52; // st7
  int v53; // esi
  int v54; // ebx
  double v55; // st7
  double v56; // st5
  double v57; // st5
  double v58; // st4
  double v59; // st5
  double v60; // st6
  float v61; // [esp+10h] [ebp-4Ch]
  float v62; // [esp+10h] [ebp-4Ch]
  float v63; // [esp+10h] [ebp-4Ch]
  float v64; // [esp+10h] [ebp-4Ch]
  float *v65; // [esp+10h] [ebp-4Ch]
  float *v66; // [esp+14h] [ebp-48h]
  float *v67; // [esp+18h] [ebp-44h]
  int v68; // [esp+1Ch] [ebp-40h]
  double v69; // [esp+1Ch] [ebp-40h]
  float v70; // [esp+24h] [ebp-38h]
  float v71; // [esp+24h] [ebp-38h]
  float v72; // [esp+24h] [ebp-38h]
  float v73; // [esp+24h] [ebp-38h]
  float v74; // [esp+24h] [ebp-38h]
  float v75; // [esp+28h] [ebp-34h]
  float v76; // [esp+28h] [ebp-34h]
  float v77; // [esp+28h] [ebp-34h]
  float v78; // [esp+2Ch] [ebp-30h]
  float v79[2]; // [esp+30h] [ebp-2Ch]
  float v80; // [esp+38h] [ebp-24h]
  float v81; // [esp+3Ch] [ebp-20h]
  float v82; // [esp+40h] [ebp-1Ch]
  float v83[2]; // [esp+44h] [ebp-18h]
  float v84[4]; // [esp+4Ch] [ebp-10h]
  float v85; // [esp+68h] [ebp+Ch]
  float v86; // [esp+68h] [ebp+Ch]
  float v87; // [esp+68h] [ebp+Ch]
  float v88; // [esp+68h] [ebp+Ch]
  float *v89; // [esp+78h] [ebp+1Ch]
  float *v90; // [esp+78h] [ebp+1Ch]
  float v91; // [esp+78h] [ebp+1Ch]
  float v92; // [esp+78h] [ebp+1Ch]
  float v93; // [esp+78h] [ebp+1Ch]
  float v94; // [esp+78h] [ebp+1Ch]
  float v95; // [esp+78h] [ebp+1Ch]
  float v96; // [esp+78h] [ebp+1Ch]

  v8 = a3;
  v9 = a6;
  v10 = a2;
  a1[2] = 0.0;
  v12 = a8;
  a1[1] = 0.0;
  *a1 = 0.0;
  v13 = 0;
  v84[2] = 0.0;
  v84[1] = 0.0;
  v84[0] = 0.0;
  v83[0] = 0.0;
  v82 = 0.0;
  v81 = 0.0;
  a3[2] = 0.0;
  a3[1] = 0.0;
  *a3 = 0.0;
  v61 = 0.0;
  if ( a8 >= 4 )
  {
    v14 = a5 + 2;
    v15 = ((unsigned int)(a8 - 4) >> 2) + 1;
    v16 = a6 + 8;
    v13 = 4 * v15;
    do
    {
      v16 += 16;
      v17 = *(v14 - 2) * *(float *)(v16 - 24);
      v14 += 16;
      --v15;
      *a1 = v17 + *a1;
      a1[1] = *(v14 - 17) * *(float *)(v16 - 24) + a1[1];
      a1[2] = *(v14 - 16) * *(float *)(v16 - 24) + a1[2];
      v62 = v61 + *(float *)(v16 - 24);
      *a1 = *(v14 - 14) * *(float *)(v16 - 20) + *a1;
      a1[1] = *(v14 - 13) * *(float *)(v16 - 20) + a1[1];
      a1[2] = *(v14 - 12) * *(float *)(v16 - 20) + a1[2];
      v63 = v62 + *(float *)(v16 - 20);
      *a1 = *(v14 - 10) * *(float *)(v16 - 16) + *a1;
      a1[1] = *(v14 - 9) * *(float *)(v16 - 16) + a1[1];
      a1[2] = *(v14 - 8) * *(float *)(v16 - 16) + a1[2];
      v64 = *(float *)(v16 - 16) + v63;
      *a1 = *(v14 - 6) * *(float *)(v16 - 12) + *a1;
      a1[1] = *(v14 - 5) * *(float *)(v16 - 12) + a1[1];
      a1[2] = *(v14 - 4) * *(float *)(v16 - 12) + a1[2];
      v61 = v64 + *(float *)(v16 - 12);
    }
    while ( v15 != 0 );
    v8 = a3;
    v12 = a8;
  }
  if ( v13 < v12 )
  {
    v18 = (int)&a5[4 * v13 + 2];
    do
    {
      ++v13;
      v19 = *(float *)(v18 - 8) * *(float *)(a6 + 4 * v13 - 4);
      v18 += 16;
      *a1 = v19 + *a1;
      a1[1] = *(float *)(v18 - 20) * *(float *)(a6 + 4 * v13 - 4) + a1[1];
      a1[2] = *(float *)(v18 - 16) * *(float *)(a6 + 4 * v13 - 4) + a1[2];
      v61 = *(float *)(a6 + 4 * v13 - 4) + v61;
    }
    while ( v13 < v12 );
    v8 = a3;
  }
  v20 = v61;
  *a1 = *a1 / v61;
  a1[1] = a1[1] / v61;
  a1[2] = a1[2] / v61;
  if ( v12 > 0 )
  {
    v21 = a5;
    v22 = 0;
    v23 = a2 + 1;
    v67 = a5;
    v66 = a2;
    v65 = a2 + 1;
    v68 = a8;
    do
    {
      *(v23 - 1) = *v21 - *a1;
      v24 = 0;
      *v23 = *(float *)((char *)v23 + (char *)a5 - (char *)a2) - a1[1];
      v23[1] = v21[2] - a1[2];
      if ( a7 >= 4 )
      {
        v25 = *(float *)(v22 + v9);
        v26 = 2;
        v89 = v66;
        do
        {
          v27 = *v89;
          *(&v81 + v24) = v27 * v27 * v25 + *(&v81 + v24);
          v24 += 4;
          *(&v81 + v24) = v27 * a2[v22 + (v26 - 1) % 3] * v25 + *(&v81 + v24);
          v28 = v89[1];
          v79[v24] = v28 * v28 * v25 + v79[v24];
          v83[v24 - 1] = v28 * a2[v22 + v26 % 3] * v25 + v83[v24 - 1];
          v29 = v89[2];
          v79[v24 + 1] = v29 * v29 * v25 + v79[v24 + 1];
          v30 = v29 * a2[v22 + (v26 + 1) % 3];
          v31 = v89;
          v32 = v26 + 2;
          v89 += 4;
          v26 += 4;
          v83[v24] = v30 * v25 + v83[v24];
          v33 = v31[3];
          *(&v80 + v24) = v33 * v33 * v25 + *(&v80 + v24);
          v10 = a2;
          v83[v24 + 1] = v33 * a2[v22 + v32 % 3] * v25 + v83[v24 + 1];
        }
        while ( v24 < a7 - 3 );
        v23 = v65;
        v9 = a6;
      }
      if ( v24 < a7 )
      {
        v34 = *(float *)(v22 + v9);
        v35 = v24 + 1;
        v90 = &v10[v24 + v22];
        do
        {
          v36 = *v90;
          v37 = v35 % 3;
          *(&v81 + v24) = v36 * v36 * v34 + *(&v81 + v24);
          v10 = a2;
          ++v90;
          ++v24;
          ++v35;
          v83[v24 + 1] = v36 * a2[v22 + v37] * v34 + v83[v24 + 1];
        }
        while ( v24 < a7 );
        v9 = a6;
        v23 = v65;
      }
      v66 += 4;
      v21 = v67 + 4;
      v23 += 4;
      v22 += 4;
      v38 = v68-- == 1;
      v67 += 4;
      v65 = v23;
    }
    while ( !v38 );
    v8 = a3;
  }
  v39 = 0;
  v91 = 0.0;
  v40 = 0;
  v70 = v20 * 0.007843137718737125 * 0.007843137718737125;
  v41 = v70;
  v42 = v81;
  if ( v81 < (double)v70 )
  {
    v81 = 0.0;
    v42 = (float)0.0;
  }
  else
  {
    v40 = 1;
  }
  if ( v42 > 0.0 )
  {
    v39 = 0;
    v91 = v42;
  }
  v43 = v82;
  if ( v82 < v41 )
  {
    v82 = 0.0;
    v43 = (float)0.0;
  }
  else
  {
    ++v40;
  }
  if ( v91 < v43 )
  {
    v39 = 1;
    v91 = v43;
  }
  if ( v83[0] < v41 )
    v83[0] = 0.0;
  else
    ++v40;
  if ( v91 < (double)v83[0] )
    v39 = 2;
  v44 = v83[0];
  *a4 = true;
  v92 = 0.007843137718737125 * (v20 * 3.0 * 0.007843137718737125);
  v47 = 0;
  v46 = v92 < v42;
  v48 = v92 == v42;
  *a4 = (v45 & 0x41) == 0;
  *a4 &= v43 < v92;
  v49 = v92 > v44;
  v38 = !v49 || !*a4;
  *a4 &= v49;
  if ( v38 )
  {
    if ( v40 == 1 )
    {
      v8[v39] = 1.0;
    }
    else if ( v40 == 2 )
    {
      v50 = (v39 + 1) % 3;
      if ( *(&v81 + v50) <= 0.0 )
        v51 = (v39 + 2) % 3;
      else
        v51 = (v39 + 1) % 3;
      if ( v51 == v50 )
        v52 = v84[v39];
      else
        v52 = v84[(v39 + 2) % 3];
      v93 = v52;
      v8[v51] = v93 / *(&v81 + v39);
      v8[v39] = 1.0;
    }
    else
    {
      v53 = 0;
      v94 = 100000.0;
      if ( a7 > 0 )
      {
        do
        {
          v54 = v53 + 1;
          v55 = *(&v81 + (v53 + 1) % 3) * *(&v81 + v53);
          v69 = v84[v53];
          v71 = v55 - v69 * v69;
          v85 = v55;
          v86 = sqrt(v85);
          v87 = v69 / v86;
          v88 = fabs(v87);
          v79[v53 - 1] = v88;
          if ( v71 > (double)v94 )
          {
            v94 = v55 - v69 * v69;
            v39 = v53;
          }
          ++v53;
        }
        while ( v54 < a7 );
        v8 = a3;
      }
      v72 = v84[(v39 + 2) % 3];
      v75 = v84[(v39 + 1) % 3];
      v78 = *(&v81 + (v39 + 1) % 3);
      v80 = *(&v81 + v39);
      v79[0] = -v84[v39];
      v56 = v72;
      v73 = v78 * v72 + v75 * v79[0];
      v76 = v79[0] * v56 + v75 * v80;
      v74 = v73 / v94;
      v77 = v76 / v94;
      v8[v39] = 1.0;
      v8[(v39 + 1) % 3] = 1.0;
      v8[(v39 + 2) % 3] = v77 + v74;
    }
    v95 = v8[1] * v8[1] + *v8 * *v8 + v8[2] * v8[2];
    v96 = sqrt(v95);
    if ( v96 <= 0.0 )
    {
      v58 = 0.0;
      v57 = 0.0;
    }
    else
    {
      v57 = *a3 / v96;
      v58 = 0.0;
    }
    *a3 = v57;
    v59 = v96;
    v60 = v58;
    if ( v96 > 0.0 )
      v58 = a3[1] / v59;
    a3[1] = v58;
    if ( v59 <= 0.0 )
      a3[2] = v60;
    else
      a3[2] = a3[2] / v59;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F36A0
// Name: sub_4F36A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl sub_4F36A0(
        float *a1,
        int a2,
        _DWORD *a3,
        float *a4,
        int a5,
        unsigned __int8 a6,
        float *a7,
        char a8,
        char a9,
        char a10,
        unsigned __int8 a11)
{
  int v11; // edx
  _DWORD *v12; // eax
  _BYTE *v13; // ecx
  double v14; // st7
  float *v15; // ebx
  float *v16; // eax
  int v17; // edi
  double v18; // st7
  float *v19; // edi
  float *v20; // esi
  int j; // ebx
  double result; // st7
  unsigned __int8 v23; // dl
  int v24; // ebx
  double v25; // st7
  int v26; // edi
  float *v27; // esi
  int v28; // eax
  double v29; // st6
  float *v30; // ecx
  double v31; // st5
  double v32; // st4
  double v33; // st2
  double v34; // st6
  double v35; // st5
  double v36; // st4
  float *v37; // ecx
  double v38; // st2
  int v39; // eax
  int v40; // eax
  int v41; // ecx
  double v42; // st7
  double v43; // st6
  double v44; // st5
  double v45; // st5
  int v46; // edi
  int v47; // esi
  float *v48; // ebx
  double v49; // st7
  int v50; // ecx
  double v51; // st5
  float *v52; // edx
  float *v53; // edx
  double v54; // st5
  float *v55; // edi
  float *v56; // esi
  int k; // ebx
  int v58; // ebx
  double v59; // st7
  int v60; // edi
  float *v61; // esi
  int v62; // eax
  double v63; // st6
  float *v64; // ecx
  double v65; // st5
  double v66; // st4
  double v67; // st2
  double v68; // st6
  double v69; // st5
  double v70; // st4
  float *v71; // ecx
  double v72; // st2
  double v73; // st7
  double v74; // st5
  double v75; // st7
  double v76; // st5
  double v77; // rtt
  int v78; // edi
  int v79; // esi
  float *v80; // ebx
  double v81; // st7
  int v82; // ecx
  double v83; // st5
  float *v84; // edx
  float *v85; // edx
  double v86; // st5
  float *v87; // edi
  float *v88; // esi
  int n; // ebx
  int v90; // ebx
  double v91; // st7
  int v92; // edi
  float *v93; // esi
  int v94; // eax
  double v95; // st6
  float *v96; // ecx
  double v97; // st5
  double v98; // st4
  double v99; // st2
  double v100; // st6
  double v101; // st5
  double v102; // st4
  float *v103; // ecx
  double v104; // st2
  double v105; // st7
  double v106; // st5
  double v107; // st7
  double v108; // st5
  double v109; // rt2
  int v110; // edi
  int v111; // esi
  float *v112; // ebx
  double v113; // st7
  int v114; // ecx
  double v115; // st5
  float *v116; // edx
  float *v117; // edx
  double v118; // st5
  double v119; // st7
  float v120; // ecx
  float v121; // edx
  float v122; // ecx
  float v123; // edx
  float v124; // [esp+18h] [ebp-15D8h]
  float v125; // [esp+18h] [ebp-15D8h]
  float v126; // [esp+18h] [ebp-15D8h]
  float v127; // [esp+18h] [ebp-15D8h]
  float v128; // [esp+18h] [ebp-15D8h]
  float v129; // [esp+18h] [ebp-15D8h]
  float v130; // [esp+18h] [ebp-15D8h]
  float v131; // [esp+18h] [ebp-15D8h]
  float v132; // [esp+18h] [ebp-15D8h]
  float v133; // [esp+18h] [ebp-15D8h]
  float v134; // [esp+18h] [ebp-15D8h]
  float v135; // [esp+18h] [ebp-15D8h]
  float v136; // [esp+18h] [ebp-15D8h]
  float v137; // [esp+18h] [ebp-15D8h]
  float v138; // [esp+18h] [ebp-15D8h]
  float v139; // [esp+18h] [ebp-15D8h]
  float v140; // [esp+18h] [ebp-15D8h]
  float v141; // [esp+18h] [ebp-15D8h]
  float v142; // [esp+18h] [ebp-15D8h]
  float v143; // [esp+18h] [ebp-15D8h]
  float v144; // [esp+18h] [ebp-15D8h]
  float v145; // [esp+18h] [ebp-15D8h]
  float v146; // [esp+18h] [ebp-15D8h]
  float v147; // [esp+18h] [ebp-15D8h]
  float v148; // [esp+18h] [ebp-15D8h]
  float v149; // [esp+18h] [ebp-15D8h]
  float v150; // [esp+18h] [ebp-15D8h]
  float v151; // [esp+18h] [ebp-15D8h]
  float v152; // [esp+18h] [ebp-15D8h]
  float v153; // [esp+18h] [ebp-15D8h]
  float v154; // [esp+18h] [ebp-15D8h]
  float v155; // [esp+18h] [ebp-15D8h]
  float v156; // [esp+18h] [ebp-15D8h]
  float v157; // [esp+18h] [ebp-15D8h]
  float v158; // [esp+18h] [ebp-15D8h]
  float v159; // [esp+18h] [ebp-15D8h]
  float v160; // [esp+18h] [ebp-15D8h]
  float v161; // [esp+18h] [ebp-15D8h]
  float v162; // [esp+18h] [ebp-15D8h]
  float v163; // [esp+18h] [ebp-15D8h]
  float v164; // [esp+18h] [ebp-15D8h]
  float v165; // [esp+18h] [ebp-15D8h]
  float v166; // [esp+18h] [ebp-15D8h]
  float v167; // [esp+18h] [ebp-15D8h]
  float v168; // [esp+18h] [ebp-15D8h]
  float v169; // [esp+1Ch] [ebp-15D4h]
  float v170; // [esp+1Ch] [ebp-15D4h]
  float v171; // [esp+1Ch] [ebp-15D4h]
  float v172; // [esp+1Ch] [ebp-15D4h]
  float v173; // [esp+1Ch] [ebp-15D4h]
  float v174; // [esp+1Ch] [ebp-15D4h]
  float v175; // [esp+1Ch] [ebp-15D4h]
  float v176; // [esp+1Ch] [ebp-15D4h]
  float v177; // [esp+1Ch] [ebp-15D4h]
  float v178; // [esp+1Ch] [ebp-15D4h]
  float v179; // [esp+1Ch] [ebp-15D4h]
  float v180; // [esp+1Ch] [ebp-15D4h]
  float v181; // [esp+1Ch] [ebp-15D4h]
  float v182; // [esp+1Ch] [ebp-15D4h]
  float v183; // [esp+1Ch] [ebp-15D4h]
  float v184; // [esp+1Ch] [ebp-15D4h]
  float v185; // [esp+1Ch] [ebp-15D4h]
  float v186; // [esp+1Ch] [ebp-15D4h]
  int i; // [esp+20h] [ebp-15D0h]
  int v188; // [esp+20h] [ebp-15D0h]
  float *v189; // [esp+20h] [ebp-15D0h]
  float v190; // [esp+20h] [ebp-15D0h]
  float *v191; // [esp+20h] [ebp-15D0h]
  float v192; // [esp+20h] [ebp-15D0h]
  float v193; // [esp+24h] [ebp-15CCh]
  int v194; // [esp+24h] [ebp-15CCh]
  int v195; // [esp+24h] [ebp-15CCh]
  int v196; // [esp+24h] [ebp-15CCh]
  float *v197; // [esp+28h] [ebp-15C8h]
  float *v198; // [esp+28h] [ebp-15C8h]
  float *v199; // [esp+28h] [ebp-15C8h]
  float v200; // [esp+2Ch] [ebp-15C4h]
  int v201; // [esp+2Ch] [ebp-15C4h]
  int v202; // [esp+2Ch] [ebp-15C4h]
  int v203; // [esp+30h] [ebp-15C0h]
  int v204; // [esp+30h] [ebp-15C0h]
  int v205; // [esp+30h] [ebp-15C0h]
  bool v206[4]; // [esp+34h] [ebp-15BCh] BYREF
  float v207; // [esp+38h] [ebp-15B8h]
  float v208; // [esp+3Ch] [ebp-15B4h]
  float v209; // [esp+40h] [ebp-15B0h]
  float v210; // [esp+44h] [ebp-15ACh]
  float v211; // [esp+48h] [ebp-15A8h]
  int v212; // [esp+4Ch] [ebp-15A4h]
  int v213; // [esp+50h] [ebp-15A0h]
  float v214; // [esp+54h] [ebp-159Ch]
  _BYTE *v215; // [esp+58h] [ebp-1598h]
  int v216; // [esp+5Ch] [ebp-1594h]
  double v217; // [esp+60h] [ebp-1590h]
  float v218[2]; // [esp+68h] [ebp-1588h] BYREF
  float v219; // [esp+70h] [ebp-1580h]
  float v220; // [esp+74h] [ebp-157Ch]
  float v221; // [esp+78h] [ebp-1578h]
  float v222; // [esp+7Ch] [ebp-1574h]
  double v223; // [esp+88h] [ebp-1568h]
  double m; // [esp+90h] [ebp-1560h]
  double v225; // [esp+98h] [ebp-1558h]
  float v226; // [esp+A4h] [ebp-154Ch]
  float v227; // [esp+A8h] [ebp-1548h]
  float v228; // [esp+ACh] [ebp-1544h]
  float v229[2]; // [esp+B0h] [ebp-1540h] BYREF
  float v230[2]; // [esp+B8h] [ebp-1538h] BYREF
  float v231[4]; // [esp+C0h] [ebp-1530h] BYREF
  float v232; // [esp+D0h] [ebp-1520h] BYREF
  float v233; // [esp+D4h] [ebp-151Ch]
  float v234; // [esp+D8h] [ebp-1518h]
  float v235; // [esp+DCh] [ebp-1514h]
  float v236; // [esp+E0h] [ebp-1510h]
  float v237[3]; // [esp+E4h] [ebp-150Ch]
  float v238[16]; // [esp+F0h] [ebp-1500h] BYREF
  float v239[16]; // [esp+130h] [ebp-14C0h] BYREF
  float v240[32]; // [esp+170h] [ebp-1480h] BYREF
  _BYTE v241[4]; // [esp+1F0h] [ebp-1400h] BYREF
  char v242; // [esp+1F4h] [ebp-13FCh] BYREF
  _BYTE v243[1272]; // [esp+1F8h] [ebp-13F8h] BYREF
  _BYTE v244[3840]; // [esp+6F0h] [ebp-F00h] BYREF

  v11 = a5;
  v12 = a3;
  if ( a5 > 0 )
  {
    v13 = (_BYTE *)(v241 - (_BYTE *)a3);
    do
    {
      *(_DWORD *)((char *)v12 + (_DWORD)v13) = *v12;
      *(_DWORD *)((char *)v12 + (_DWORD)v13 + 4) = v12[1];
      *(_DWORD *)((char *)v12 + (_DWORD)v13 + 8) = v12[2];
      v12 += 4;
      --v11;
    }
    while ( v11 != 0 );
  }
  if ( a7 != nullptr )
  {
    v207 = *a7;
    v214 = a7[1];
    v14 = a7[2];
  }
  else
  {
    v14 = 1.0;
    v207 = 1.0;
    v214 = 1.0;
  }
  v211 = v14;
  v228 = (float)(1 << (8 - a8));
  v227 = (float)(1 << (8 - a9));
  v226 = (float)(1 << (8 - a10));
  v15 = a1;
  for ( i = 2; i != 0; --i )
  {
    v16 = v15;
    v17 = 3;
    do
    {
      v18 = *(float *)((char *)v16 + a2 - (_DWORD)a1);
      v16 += 2;
      --v17;
      v193 = v18;
      *(v16 - 2) = v193;
      *(float *)((char *)v16 + (char *)v218 - (char *)a1 - 8) = v193;
      *(float *)((char *)v16 + (char *)&v232 - (char *)a1 - 8) = v193;
    }
    while ( v17 != 0 );
    ++v15;
  }
  MkWkRmpPts(a1: v206, a2: (float (*const)[2])v229, a3: (float (*const)[2])v218, a4: a8, a5: a9, a6: a10);
  v19 = v238;
  v20 = v229;
  for ( j = 3; j != 0; --j )
  {
    BldClrRmp(a1: v19, a2: v20, a3: a6);
    v20 += 2;
    v19 += 16;
  }
  v213 = a6;
  v208 = sub_4F0A40(a1: a4, a2: v238, a3: a5, a4: a6, a5: v206[0], a6: a7);
  result = v208;
  if ( v208 != 0.0 )
  {
    v23 = a11;
    if ( a11 != 0 )
    {
      v24 = 0;
      v25 = v214;
      if ( a5 > 0 )
      {
        v26 = v213;
        v27 = (float *)v241;
        v197 = (float *)v244;
        do
        {
          v28 = 0;
          if ( v26 >= 4 )
          {
            v29 = v27[1];
            v30 = v197;
            v31 = *v27;
            v32 = v211;
            do
            {
              v33 = v239[v28];
              v28 += 4;
              v30 += 256;
              v124 = v33 - v29;
              v169 = v237[v28 - 1] - v31;
              *(v30 - 320) = v124 * v124 * v25 + v169 * v169 * v32;
              v125 = v238[v28 + 13] - v29;
              v170 = v237[v28] - v31;
              *(v30 - 256) = v125 * v125 * v25 + v170 * v170 * v32;
              v126 = v238[v28 + 14] - v29;
              v171 = v237[v28 + 1] - v31;
              *(v30 - 192) = v126 * v126 * v25 + v171 * v171 * v32;
              v127 = v238[v28 + 15] - v29;
              v172 = v237[v28 + 2] - v31;
              *(v30 - 128) = v127 * v127 * v25 + v172 * v172 * v32;
            }
            while ( v28 < v26 - 3 );
            v23 = a11;
          }
          if ( v28 < v26 )
          {
            v34 = v27[1];
            v35 = *v27;
            v36 = v211;
            v37 = (float *)&v243[256 * v28 + 1016 + 4 * v24];
            do
            {
              v38 = v239[v28++];
              v37 += 64;
              v128 = v38 - v34;
              v173 = v237[v28 + 2] - v35;
              *(v37 - 64) = v128 * v128 * v25 + v173 * v173 * v36;
            }
            while ( v28 < v26 );
          }
          ++v197;
          ++v24;
          v27 += 4;
        }
        while ( v24 < a5 );
      }
      v39 = v23;
      v209 = v236;
      v210 = v237[0];
      if ( v23 >= 8u )
        v39 = 8;
      v40 = -v39;
      v216 = v40;
      v41 = v23;
      if ( v23 >= 8u )
        v41 = 8;
      v212 = v41;
      v188 = v40;
      if ( v40 <= v41 )
      {
        v42 = 255.0;
        v223 = v236;
        v217 = v228;
        v43 = 0.0;
        v225 = v237[0];
        while ( 1 )
        {
          v203 = v216;
          v44 = (double)v188 * v217 + v223;
          m = v44;
          while ( 1 )
          {
            if ( v44 > v43 && v44 >= v42 )
            {
              v44 = v42;
            }
            else if ( v44 <= v43 )
            {
              v44 = v43;
            }
            v221 = v44;
            v45 = (double)v203 * v217 + v225;
            if ( v45 <= v43 || v45 < v42 )
            {
              v42 = v45;
              if ( v43 >= v45 )
                v42 = v43;
            }
            v222 = v42;
            MkWkRmpPts(a1: v206, a2: (float (*const)[2])v229, a3: (float (*const)[2])v218, a4: a8, a5: a9, a6: a10);
            BldClrRmp(a1: v240, a2: v231, a3: a6);
            v200 = 0.0;
            v46 = 1;
            if ( !v206[0] )
              v46 = v213;
            v47 = 0;
            v194 = 0;
            if ( a5 > 0 )
            {
              v48 = a4;
              v49 = v207;
              v198 = (float *)v243;
              v215 = (_BYTE *)(v244 - (_BYTE *)a4);
              do
              {
                v50 = 0;
                v174 = 10000000.0;
                if ( v46 >= 4 )
                {
                  v51 = *v198;
                  v52 = (float *)((int)v48 + (_DWORD)v215);
                  do
                  {
                    v129 = v240[v50] - v51;
                    v130 = v129 * v129 * v49 + *(v52 - 64);
                    if ( v130 <= (double)v174 )
                      v174 = v130;
                    v131 = v240[v50 + 1] - v51;
                    v132 = v131 * v131 * v49 + *v52;
                    if ( v132 <= (double)v174 )
                      v174 = v132;
                    v133 = v240[v50 + 2] - v51;
                    v134 = v133 * v133 * v49 + v52[64];
                    if ( v134 <= (double)v174 )
                      v174 = v134;
                    v135 = v240[v50 + 3] - v51;
                    v136 = v135 * v135 * v49 + v52[128];
                    if ( v136 <= (double)v174 )
                      v174 = v136;
                    v50 += 4;
                    v52 += 256;
                  }
                  while ( v50 < v46 - 3 );
                  v47 = v194;
                }
                if ( v50 < v46 )
                {
                  v53 = (float *)&v243[256 * v50 + 1016 + 4 * v47];
                  do
                  {
                    v137 = v240[v50] - *v198;
                    v138 = v137 * v137 * v49 + *v53;
                    if ( v138 <= (double)v174 )
                      v174 = v138;
                    ++v50;
                    v53 += 64;
                  }
                  while ( v50 < v46 );
                }
                v198 += 4;
                v54 = v174 * *v48;
                ++v47;
                ++v48;
                v194 = v47;
                v200 = v54 + v200;
              }
              while ( v47 < a5 );
            }
            if ( v208 > (double)v200 )
            {
              v209 = v221;
              v210 = v222;
              v208 = v200;
            }
            if ( ++v203 > v212 )
              break;
            v42 = 255.0;
            v44 = m;
            v43 = 0.0;
          }
          if ( ++v188 > v212 )
            break;
          v42 = 255.0;
          v43 = 0.0;
        }
      }
      v221 = v209;
      v222 = v210;
      MkWkRmpPts(a1: v206, a2: (float (*const)[2])v229, a3: (float (*const)[2])v218, a4: a8, a5: a9, a6: a10);
      v55 = v238;
      v56 = v229;
      for ( k = 3; k != 0; --k )
      {
        BldClrRmp(a1: v55, a2: v56, a3: a6);
        v56 += 2;
        v55 += 16;
      }
      v58 = 0;
      if ( a5 > 0 )
      {
        v59 = v207;
        v60 = v213;
        v61 = (float *)v241;
        v189 = (float *)v244;
        do
        {
          v62 = 0;
          if ( v60 >= 4 )
          {
            v63 = v61[2];
            v64 = v189;
            v65 = *v61;
            v66 = v211;
            do
            {
              v67 = v240[v62];
              v62 += 4;
              v64 += 256;
              v175 = v67 - v63;
              v139 = v237[v62 - 1] - v65;
              *(v64 - 320) = v175 * v175 * v59 + v139 * v139 * v66;
              v176 = v239[v62 + 13] - v63;
              v140 = v237[v62] - v65;
              *(v64 - 256) = v176 * v176 * v59 + v140 * v140 * v66;
              v177 = v239[v62 + 14] - v63;
              v141 = v237[v62 + 1] - v65;
              *(v64 - 192) = v177 * v177 * v59 + v141 * v141 * v66;
              v178 = v239[v62 + 15] - v63;
              v142 = v237[v62 + 2] - v65;
              *(v64 - 128) = v178 * v178 * v59 + v142 * v142 * v66;
            }
            while ( v62 < v60 - 3 );
          }
          if ( v62 < v60 )
          {
            v68 = v61[2];
            v69 = *v61;
            v70 = v211;
            v71 = (float *)&v243[256 * v62 + 1016 + 4 * v58];
            do
            {
              v72 = v240[v62++];
              v71 += 64;
              v179 = v72 - v68;
              v143 = v237[v62 + 2] - v69;
              *(v71 - 64) = v179 * v179 * v59 + v143 * v143 * v70;
            }
            while ( v62 < v60 );
          }
          ++v189;
          ++v58;
          v61 += 4;
        }
        while ( v58 < a5 );
      }
      v209 = v234;
      v201 = v216;
      v210 = v235;
      if ( v216 <= v212 )
      {
        v225 = v234;
        v217 = v227;
        v223 = v235;
        do
        {
          v204 = v216;
          v73 = (double)v201 * v217 + v225;
          for ( m = v73; ; v73 = m )
          {
            if ( v73 <= 0.0 )
            {
              v74 = 255.0;
            }
            else
            {
              v74 = 255.0;
              if ( v73 >= 255.0 )
              {
                v75 = 255.0;
                goto LABEL_87;
              }
            }
            v77 = v74;
            v74 = v73;
            v75 = v77;
            if ( v74 <= 0.0 )
              v74 = 0.0;
LABEL_87:
            v219 = v74;
            v76 = (double)v204 * v217 + v223;
            if ( v76 <= 0.0 || v76 < v75 )
            {
              v75 = v76;
              if ( v76 <= 0.0 )
                v75 = 0.0;
            }
            v220 = v75;
            MkWkRmpPts(a1: v206, a2: (float (*const)[2])v229, a3: (float (*const)[2])v218, a4: a8, a5: a9, a6: a10);
            BldClrRmp(a1: v239, a2: v230, a3: a6);
            v190 = 0.0;
            v78 = 1;
            if ( !v206[0] )
              v78 = v213;
            v79 = 0;
            v195 = 0;
            if ( a5 > 0 )
            {
              v80 = a4;
              v81 = v214;
              v199 = (float *)&v242;
              v215 = (_BYTE *)(v244 - (_BYTE *)a4);
              do
              {
                v82 = 0;
                v180 = 10000000.0;
                if ( v78 >= 4 )
                {
                  v83 = *v199;
                  v84 = (float *)&v215[(_DWORD)v80];
                  do
                  {
                    v144 = v239[v82] - v83;
                    v145 = v144 * v144 * v81 + *(v84 - 64);
                    if ( v145 <= (double)v180 )
                      v180 = v145;
                    v146 = v239[v82 + 1] - v83;
                    v147 = v146 * v146 * v81 + *v84;
                    if ( v147 <= (double)v180 )
                      v180 = v147;
                    v148 = v239[v82 + 2] - v83;
                    v149 = v148 * v148 * v81 + v84[64];
                    if ( v149 <= (double)v180 )
                      v180 = v149;
                    v150 = v239[v82 + 3] - v83;
                    v151 = v150 * v150 * v81 + v84[128];
                    if ( v151 <= (double)v180 )
                      v180 = v151;
                    v82 += 4;
                    v84 += 256;
                  }
                  while ( v82 < v78 - 3 );
                  v79 = v195;
                }
                if ( v82 < v78 )
                {
                  v85 = (float *)&v243[256 * v82 + 1016 + 4 * v79];
                  do
                  {
                    v152 = v239[v82] - *v199;
                    v153 = v152 * v152 * v81 + *v85;
                    if ( v153 <= (double)v180 )
                      v180 = v153;
                    ++v82;
                    v85 += 64;
                  }
                  while ( v82 < v78 );
                }
                v199 += 4;
                v86 = v180 * *v80;
                ++v79;
                ++v80;
                v195 = v79;
                v190 = v86 + v190;
              }
              while ( v79 < a5 );
            }
            if ( v208 > (double)v190 )
            {
              v209 = v219;
              v210 = v220;
              v208 = v190;
            }
            if ( ++v204 > v212 )
              break;
          }
          ++v201;
        }
        while ( v201 <= v212 );
      }
      v219 = v209;
      v220 = v210;
      MkWkRmpPts(a1: v206, a2: (float (*const)[2])v229, a3: (float (*const)[2])v218, a4: a8, a5: a9, a6: a10);
      v87 = v238;
      v88 = v229;
      for ( n = 3; n != 0; --n )
      {
        BldClrRmp(a1: v87, a2: v88, a3: a6);
        v88 += 2;
        v87 += 16;
      }
      v90 = 0;
      if ( a5 > 0 )
      {
        v91 = v207;
        v92 = v213;
        v93 = (float *)&v242;
        v191 = (float *)v244;
        do
        {
          v94 = 0;
          if ( v92 >= 4 )
          {
            v95 = v93[1];
            v96 = v191;
            v97 = *v93;
            v98 = v214;
            do
            {
              v99 = v240[v94];
              v94 += 4;
              v96 += 256;
              v181 = v99 - v95;
              v154 = v238[v94 + 12] - v97;
              *(v96 - 320) = v181 * v181 * v91 + v154 * v154 * v98;
              v182 = v239[v94 + 13] - v95;
              v155 = v238[v94 + 13] - v97;
              *(v96 - 256) = v182 * v182 * v91 + v155 * v155 * v98;
              v183 = v239[v94 + 14] - v95;
              v156 = v238[v94 + 14] - v97;
              *(v96 - 192) = v183 * v183 * v91 + v156 * v156 * v98;
              v184 = v239[v94 + 15] - v95;
              v157 = v238[v94 + 15] - v97;
              *(v96 - 128) = v184 * v184 * v91 + v157 * v157 * v98;
            }
            while ( v94 < v92 - 3 );
          }
          if ( v94 < v92 )
          {
            v100 = v93[1];
            v101 = *v93;
            v102 = v214;
            v103 = (float *)&v243[256 * v94 + 1016 + 4 * v90];
            do
            {
              v104 = v240[v94++];
              v103 += 64;
              v185 = v104 - v100;
              v158 = v238[v94 + 15] - v101;
              *(v103 - 64) = v185 * v185 * v91 + v158 * v158 * v102;
            }
            while ( v94 < v92 );
          }
          ++v191;
          ++v90;
          v93 += 4;
        }
        while ( v90 < a5 );
      }
      v209 = v232;
      v202 = v216;
      v210 = v233;
      if ( v216 <= v212 )
      {
        v225 = v232;
        v217 = v226;
        v223 = v233;
        do
        {
          v205 = v216;
          v105 = (double)v202 * v217 + v225;
          for ( m = v105; ; v105 = m )
          {
            if ( v105 <= 0.0 )
            {
              v106 = 255.0;
            }
            else
            {
              v106 = 255.0;
              if ( v105 >= 255.0 )
              {
                v107 = 255.0;
                goto LABEL_138;
              }
            }
            v109 = v106;
            v106 = v105;
            v107 = v109;
            if ( v106 <= 0.0 )
              v106 = 0.0;
LABEL_138:
            v218[0] = v106;
            v108 = (double)v205 * v217 + v223;
            if ( v108 <= 0.0 || v108 < v107 )
            {
              v107 = v108;
              if ( v108 <= 0.0 )
                v107 = 0.0;
            }
            v218[1] = v107;
            MkWkRmpPts(a1: v206, a2: (float (*const)[2])v229, a3: (float (*const)[2])v218, a4: a8, a5: a9, a6: a10);
            BldClrRmp(a1: v238, a2: v229, a3: a6);
            v192 = 0.0;
            v110 = 1;
            if ( !v206[0] )
              v110 = v213;
            v111 = 0;
            v196 = 0;
            if ( a5 > 0 )
            {
              v112 = a4;
              v113 = v211;
              v207 = COERCE_FLOAT(v241);
              v215 = (_BYTE *)(v244 - (_BYTE *)a4);
              do
              {
                v114 = 0;
                v186 = 10000000.0;
                if ( v110 >= 4 )
                {
                  v115 = *(float *)LODWORD(v207);
                  v116 = (float *)&v215[(_DWORD)v112];
                  do
                  {
                    v159 = v238[v114] - v115;
                    v160 = v159 * v159 * v113 + *(v116 - 64);
                    if ( v160 <= (double)v186 )
                      v186 = v160;
                    v161 = v238[v114 + 1] - v115;
                    v162 = v161 * v161 * v113 + *v116;
                    if ( v162 <= (double)v186 )
                      v186 = v162;
                    v163 = v238[v114 + 2] - v115;
                    v164 = v163 * v163 * v113 + v116[64];
                    if ( v164 <= (double)v186 )
                      v186 = v164;
                    v165 = v238[v114 + 3] - v115;
                    v166 = v165 * v165 * v113 + v116[128];
                    if ( v166 <= (double)v186 )
                      v186 = v166;
                    v114 += 4;
                    v116 += 256;
                  }
                  while ( v114 < v110 - 3 );
                  v111 = v196;
                }
                if ( v114 < v110 )
                {
                  v117 = (float *)&v243[256 * v114 + 1016 + 4 * v111];
                  do
                  {
                    v167 = v238[v114] - *(float *)LODWORD(v207);
                    v168 = v167 * v167 * v113 + *v117;
                    if ( v168 <= (double)v186 )
                      v186 = v168;
                    ++v114;
                    v117 += 64;
                  }
                  while ( v114 < v110 );
                }
                LODWORD(v207) += 16;
                v118 = v186 * *v112;
                ++v111;
                ++v112;
                v196 = v111;
                v192 = v118 + v192;
              }
              while ( v111 < a5 );
            }
            if ( v208 > (double)v192 )
            {
              v209 = v218[0];
              v210 = v218[1];
              v208 = v192;
            }
            if ( ++v205 > v212 )
              break;
          }
          ++v202;
        }
        while ( v202 <= v212 );
      }
      v119 = v210;
      *a1 = v209;
      v120 = v219;
      v218[1] = v119;
      result = v208;
      a1[1] = v218[1];
      v121 = v220;
      a1[2] = v120;
      v122 = v221;
      a1[3] = v121;
      v123 = v222;
      a1[4] = v122;
      a1[5] = v123;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F4910
// Name: sub_4F4910
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl sub_4F4910(
        int a1,
        int a2,
        _DWORD *a3,
        float *a4,
        int a5,
        unsigned __int8 a6,
        float *a7,
        char a8,
        char a9,
        char a10,
        unsigned __int8 a11)
{
  int v11; // edx
  _DWORD *v12; // eax
  char *v13; // ecx
  double v14; // st7
  int v15; // ebx
  int v16; // eax
  int v17; // esi
  double v18; // st7
  float *v19; // edi
  float *v20; // esi
  int j; // ebx
  double result; // st7
  int v23; // eax
  int v24; // eax
  int v25; // ecx
  double v26; // st7
  double v27; // st6
  double v28; // st5
  double v29; // st5
  int v30; // esi
  double v31; // st7
  float *v32; // edi
  float *v33; // ebx
  int v34; // eax
  double v35; // st6
  float *v36; // ecx
  double v37; // st4
  double v38; // st6
  float *v39; // ecx
  double v40; // st4
  double v41; // st7
  double v42; // st6
  double v43; // st5
  double v44; // st7
  double v45; // rt0
  double v46; // st5
  int v47; // esi
  double v48; // st7
  float *v49; // edi
  int v50; // eax
  double v51; // st6
  int v52; // ecx
  double v53; // st4
  double v54; // st6
  int v55; // ecx
  double v56; // st4
  double v57; // st7
  double v58; // st6
  double v59; // st5
  double v60; // st7
  double v61; // rt1
  double v62; // st5
  int v63; // edi
  int v64; // esi
  float *v65; // ebx
  double v66; // st7
  int v67; // ecx
  double v68; // st5
  float *v69; // edx
  float *v70; // edx
  double v71; // st5
  int v72; // edx
  char *v73; // edi
  int k; // esi
  int v75; // eax
  int m; // ecx
  double v77; // st7
  float v78; // [esp+Ch] [ebp-2604h]
  float v79; // [esp+Ch] [ebp-2604h]
  float v80; // [esp+Ch] [ebp-2604h]
  float v81; // [esp+Ch] [ebp-2604h]
  float v82; // [esp+Ch] [ebp-2604h]
  float v83; // [esp+Ch] [ebp-2604h]
  float v84; // [esp+Ch] [ebp-2604h]
  float v85; // [esp+Ch] [ebp-2604h]
  float v86; // [esp+Ch] [ebp-2604h]
  float v87; // [esp+Ch] [ebp-2604h]
  float v88; // [esp+Ch] [ebp-2604h]
  float v89; // [esp+10h] [ebp-2600h]
  float v90; // [esp+10h] [ebp-2600h]
  float v91; // [esp+10h] [ebp-2600h]
  float v92; // [esp+10h] [ebp-2600h]
  float v93; // [esp+10h] [ebp-2600h]
  float v94; // [esp+10h] [ebp-2600h]
  float v95; // [esp+10h] [ebp-2600h]
  float v96; // [esp+10h] [ebp-2600h]
  float v97; // [esp+10h] [ebp-2600h]
  float v98; // [esp+10h] [ebp-2600h]
  float v99; // [esp+14h] [ebp-25FCh]
  int v100; // [esp+14h] [ebp-25FCh]
  int i; // [esp+18h] [ebp-25F8h]
  int v102; // [esp+18h] [ebp-25F8h]
  bool v103[4]; // [esp+20h] [ebp-25F0h] BYREF
  int v104; // [esp+24h] [ebp-25ECh]
  int v105; // [esp+28h] [ebp-25E8h]
  float *v106; // [esp+2Ch] [ebp-25E4h]
  float v107; // [esp+30h] [ebp-25E0h]
  int v108; // [esp+34h] [ebp-25DCh]
  int v109; // [esp+38h] [ebp-25D8h]
  int v110; // [esp+3Ch] [ebp-25D4h]
  float v111; // [esp+40h] [ebp-25D0h]
  int v112; // [esp+44h] [ebp-25CCh]
  int v113; // [esp+48h] [ebp-25C8h]
  float v114; // [esp+4Ch] [ebp-25C4h]
  float v115; // [esp+50h] [ebp-25C0h]
  float v116; // [esp+54h] [ebp-25BCh]
  double v117; // [esp+58h] [ebp-25B8h]
  float v118; // [esp+60h] [ebp-25B0h]
  _BYTE *v119; // [esp+68h] [ebp-25A8h]
  char *v120; // [esp+6Ch] [ebp-25A4h]
  double v121; // [esp+70h] [ebp-25A0h]
  double v122; // [esp+78h] [ebp-2598h]
  double v123; // [esp+80h] [ebp-2590h]
  float v124[2]; // [esp+88h] [ebp-2588h] BYREF
  float v125; // [esp+90h] [ebp-2580h]
  float v126; // [esp+94h] [ebp-257Ch]
  float v127; // [esp+98h] [ebp-2578h]
  float v128; // [esp+9Ch] [ebp-2574h]
  double v129; // [esp+A8h] [ebp-2568h]
  float v130[2]; // [esp+B0h] [ebp-2560h] BYREF
  float v131[2]; // [esp+B8h] [ebp-2558h] BYREF
  float v132[4]; // [esp+C0h] [ebp-2550h] BYREF
  double v133; // [esp+D0h] [ebp-2540h]
  double v134; // [esp+D8h] [ebp-2538h]
  double v135; // [esp+E0h] [ebp-2530h]
  double v136; // [esp+E8h] [ebp-2528h]
  float v137[5]; // [esp+F0h] [ebp-2520h] BYREF
  float v138[3]; // [esp+104h] [ebp-250Ch]
  float v139[16]; // [esp+110h] [ebp-2500h] BYREF
  float v140[16]; // [esp+150h] [ebp-24C0h] BYREF
  float v141[32]; // [esp+190h] [ebp-2480h] BYREF
  float v142; // [esp+210h] [ebp-2400h] BYREF
  char v143; // [esp+214h] [ebp-23FCh] BYREF
  _BYTE v144[1272]; // [esp+218h] [ebp-23F8h] BYREF
  _BYTE v145[4096]; // [esp+710h] [ebp-1F00h] BYREF
  _BYTE v146[3840]; // [esp+1710h] [ebp-F00h] BYREF

  v11 = a5;
  v12 = a3;
  if ( a5 > 0 )
  {
    v13 = (char *)((char *)&v142 - (char *)a3);
    do
    {
      *(_DWORD *)((char *)v12 + (_DWORD)v13) = *v12;
      *(_DWORD *)((char *)v12 + (_DWORD)v13 + 4) = v12[1];
      *(_DWORD *)((char *)v12 + (_DWORD)v13 + 8) = v12[2];
      v12 += 4;
      --v11;
    }
    while ( v11 != 0 );
  }
  if ( a7 != nullptr )
  {
    v116 = *a7;
    v114 = a7[1];
    v14 = a7[2];
  }
  else
  {
    v14 = 1.0;
    v116 = 1.0;
    v114 = 1.0;
  }
  v115 = v14;
  v118 = (float)(1 << (8 - a8));
  *((float *)&v117 + 1) = (float)(1 << (8 - a9));
  v120 = (char *)v124 - a1;
  *(float *)&v117 = (float)(1 << (8 - a10));
  v15 = a1;
  for ( i = 2; i != 0; --i )
  {
    v16 = v15;
    v17 = 3;
    do
    {
      v18 = *(float *)(a2 - a1 + v16);
      v16 += 8;
      --v17;
      v99 = v18;
      *(float *)(v16 - 8) = v99;
      *(float *)((char *)&v124[-2] + v16 - a1) = v99;
      *(float *)((char *)&v137[-2] + v16 - a1) = v99;
    }
    while ( v17 != 0 );
    v15 += 4;
  }
  MkWkRmpPts(a1: v103, a2: (float (*const)[2])v130, a3: (float (*const)[2])v124, a4: a8, a5: a9, a6: a10);
  v19 = v139;
  v20 = v130;
  for ( j = 3; j != 0; --j )
  {
    BldClrRmp(a1: v19, a2: v20, a3: a6);
    v20 += 2;
    v19 += 16;
  }
  v107 = sub_4F0A40(a1: a4, a2: v139, a3: a5, a4: a6, a5: v103[0], a6: a7);
  result = v107;
  if ( v107 != 0.0 && a11 != 0 )
  {
    v23 = a11;
    if ( a11 >= 8u )
      v23 = 8;
    v24 = -v23;
    v104 = v24;
    v25 = a11;
    if ( a11 >= 8u )
      v25 = 8;
    v105 = v25;
    v102 = v24;
    if ( v24 <= v25 )
    {
      v122 = *((float *)&v117 + 1);
      v135 = v137[2];
      v133 = v137[3];
      v134 = v137[0];
      v123 = *(float *)&v117;
      v136 = v137[1];
      v129 = v137[4];
      v121 = v118;
      v117 = v138[0];
      while ( 1 )
      {
        v26 = 0.0;
        v27 = 255.0;
        v28 = (double)v102 * v122 + v135;
        if ( v28 > 0.0 && v28 >= 255.0 )
          break;
        if ( v28 > 0.0 )
          goto LABEL_26;
        v109 = v104;
        v125 = 0.0;
LABEL_28:
        while ( 2 )
        {
          v29 = (double)v109 * v122 + v133;
          if ( v29 > v26 && v29 >= v27 || (v27 = v29, v29 > v26) )
            v26 = v27;
          v126 = v26;
          MkWkRmpPts(a1: v103, a2: (float (*const)[2])v130, a3: (float (*const)[2])v124, a4: a8, a5: a9, a6: a10);
          BldClrRmp(a1: v140, a2: v131, a3: a6);
          v30 = 0;
          if ( a5 > 0 )
          {
            v31 = v114;
            v32 = (float *)&v143;
            v33 = (float *)v145;
            do
            {
              v34 = 0;
              if ( a6 >= 4u )
              {
                v35 = *v32;
                v36 = v33;
                do
                {
                  v37 = v140[v34];
                  v34 += 4;
                  v36 += 256;
                  v78 = v37 - v35;
                  *(v36 - 320) = v78 * v78 * v31;
                  v79 = v139[v34 + 13] - v35;
                  *(v36 - 256) = v79 * v79 * v31;
                  v80 = v139[v34 + 14] - v35;
                  *(v36 - 192) = v80 * v80 * v31;
                  v81 = v139[v34 + 15] - v35;
                  *(v36 - 128) = v81 * v81 * v31;
                }
                while ( v34 < a6 - 3 );
              }
              if ( v34 < a6 )
              {
                v38 = *v32;
                v39 = (float *)&v144[256 * v34 + 1016 + 4 * v30];
                do
                {
                  v40 = v140[v34++];
                  v39 += 64;
                  v82 = v40 - v38;
                  *(v39 - 64) = v82 * v82 * v31;
                }
                while ( v34 < a6 );
              }
              ++v30;
              ++v33;
              v32 += 4;
            }
            while ( v30 < a5 );
          }
          v112 = v104;
          do
          {
            v41 = (double)v112 * v123 + v134;
            v42 = 0.0;
            if ( v41 <= 0.0 )
            {
              v43 = 255.0;
            }
            else
            {
              v43 = 255.0;
              if ( v41 >= 255.0 )
              {
                v44 = 255.0;
                goto LABEL_45;
              }
            }
            v45 = v43;
            v43 = v41;
            v44 = v45;
            if ( v43 <= 0.0 )
            {
              v108 = v104;
              v124[0] = 0.0;
              goto LABEL_50;
            }
LABEL_45:
            v124[0] = v43;
            v108 = v104;
LABEL_50:
            while ( 2 )
            {
              v46 = (double)v108 * v123 + v136;
              if ( v46 <= v42 || v46 < v44 )
              {
                v44 = v46;
                if ( v42 >= v46 )
                  v44 = v42;
              }
              v124[1] = v44;
              MkWkRmpPts(a1: v103, a2: (float (*const)[2])v130, a3: (float (*const)[2])v124, a4: a8, a5: a9, a6: a10);
              BldClrRmp(a1: v139, a2: v130, a3: a6);
              v47 = 0;
              if ( a5 > 0 )
              {
                v48 = v115;
                v49 = &v142;
                do
                {
                  v50 = 0;
                  if ( a6 >= 4u )
                  {
                    v51 = *v49;
                    v52 = 4 * v47;
                    do
                    {
                      v53 = v139[v50];
                      v50 += 4;
                      v52 += 1024;
                      v83 = v53 - v51;
                      *(float *)&v145[v52 + 2816] = v83 * v83 * v48 + *(float *)((char *)&v142 + v52);
                      v84 = v138[v50] - v51;
                      *(float *)&v145[v52 + 3072] = v84 * v84 * v48 + *(float *)&v144[v52 + 248];
                      v85 = v138[v50 + 1] - v51;
                      *(float *)&v145[v52 + 3328] = v85 * v85 * v48 + *(float *)&v144[v52 + 504];
                      v86 = v138[v50 + 2] - v51;
                      *(float *)&v145[v52 + 3584] = v86 * v86 * v48 + *(float *)&v144[v52 + 760];
                    }
                    while ( v50 < a6 - 3 );
                  }
                  if ( v50 < a6 )
                  {
                    v54 = *v49;
                    v55 = 4 * (v47 + (v50 << 6));
                    do
                    {
                      v56 = v139[v50++];
                      v55 += 256;
                      v87 = v56 - v54;
                      *(float *)&v145[v55 + 3584] = v87 * v87 * v48 + *(float *)&v144[v55 + 760];
                    }
                    while ( v50 < a6 );
                  }
                  ++v47;
                  v49 += 4;
                }
                while ( v47 < a5 );
              }
              v110 = v104;
              do
              {
                v57 = (double)v110 * v121 + v129;
                v58 = 0.0;
                if ( v57 <= 0.0 )
                {
                  v59 = 255.0;
                }
                else
                {
                  v59 = 255.0;
                  if ( v57 >= 255.0 )
                  {
                    v60 = 255.0;
LABEL_67:
                    v127 = v59;
                    v113 = v104;
                    goto LABEL_72;
                  }
                }
                v61 = v59;
                v59 = v57;
                v60 = v61;
                if ( v59 > 0.0 )
                  goto LABEL_67;
                v113 = v104;
                v127 = 0.0;
                while ( 1 )
                {
LABEL_72:
                  v62 = (double)v113 * v121 + v117;
                  if ( v62 <= v58 || v62 < v60 )
                  {
                    v60 = v62;
                    if ( v58 >= v62 )
                      v60 = v58;
                  }
                  v128 = v60;
                  MkWkRmpPts(
                    a1: v103,
                    a2: (float (*const)[2])v130,
                    a3: (float (*const)[2])v124,
                    a4: a8,
                    a5: a9,
                    a6: a10);
                  BldClrRmp(a1: v141, a2: v132, a3: a6);
                  v111 = 0.0;
                  v63 = 1;
                  if ( !v103[0] )
                    v63 = a6;
                  v64 = 0;
                  v100 = 0;
                  if ( a5 > 0 )
                  {
                    v65 = a4;
                    v66 = v116;
                    v106 = (float *)v144;
                    v119 = (_BYTE *)(v146 - (_BYTE *)a4);
                    do
                    {
                      v67 = 0;
                      v88 = 10000000.0;
                      if ( v63 >= 4 )
                      {
                        v68 = *v106;
                        v69 = (float *)((int)v65 + (_DWORD)v119);
                        do
                        {
                          v89 = v141[v67] - v68;
                          v90 = v89 * v89 * v66 + *(v69 - 64);
                          if ( v90 <= (double)v88 )
                            v88 = v90;
                          v91 = v141[v67 + 1] - v68;
                          v92 = v91 * v91 * v66 + *v69;
                          if ( v92 <= (double)v88 )
                            v88 = v92;
                          v93 = v141[v67 + 2] - v68;
                          v94 = v93 * v93 * v66 + v69[64];
                          if ( v94 <= (double)v88 )
                            v88 = v94;
                          v95 = v141[v67 + 3] - v68;
                          v96 = v95 * v95 * v66 + v69[128];
                          if ( v96 <= (double)v88 )
                            v88 = v96;
                          v67 += 4;
                          v69 += 256;
                        }
                        while ( v67 < v63 - 3 );
                        v64 = v100;
                      }
                      if ( v67 < v63 )
                      {
                        v70 = (float *)&v145[256 * v67 + 3840 + 4 * v64];
                        do
                        {
                          v97 = v141[v67] - *v106;
                          v98 = v97 * v97 * v66 + *v70;
                          if ( v98 <= (double)v88 )
                            v88 = v98;
                          ++v67;
                          v70 += 64;
                        }
                        while ( v67 < v63 );
                      }
                      v71 = *v65;
                      v106 += 4;
                      ++v64;
                      ++v65;
                      v100 = v64;
                      v111 = v71 * v88 + v111;
                    }
                    while ( v64 < a5 );
                  }
                  if ( v107 > (double)v111 )
                  {
                    v72 = a1;
                    v107 = v111;
                    v73 = v120;
                    for ( k = 2; k != 0; --k )
                    {
                      v75 = v72;
                      for ( m = 3; m != 0; --m )
                      {
                        v77 = *(float *)&v73[v75];
                        v75 += 8;
                        *(float *)(v75 - 8) = v77;
                      }
                      v72 += 4;
                    }
                  }
                  if ( ++v113 > v105 )
                    break;
                  v60 = 255.0;
                  v58 = 0.0;
                }
                ++v110;
              }
              while ( v110 <= v105 );
              if ( ++v108 <= v105 )
              {
                v44 = 255.0;
                v42 = 0.0;
                continue;
              }
              break;
            }
            ++v112;
          }
          while ( v112 <= v105 );
          if ( ++v109 <= v105 )
          {
            v26 = 0.0;
            v27 = 255.0;
            continue;
          }
          break;
        }
        if ( ++v102 > v105 )
          return v107;
      }
      v28 = 255.0;
LABEL_26:
      v125 = v28;
      v109 = v104;
      goto LABEL_28;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F5360
// Name: sub_4F5360
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall sub_4F5360@<st0>(
        float *a1@<edx>,
        int a2,
        int a3,
        __m128 *a4,
        int a5,
        unsigned __int8 a6,
        float *a7,
        char a8,
        char a9,
        char a10,
        unsigned __int8 a11)
{
  float *v12; // ebx
  float *v13; // ecx
  float *v14; // eax
  int j; // edx
  double v16; // st7
  double v17; // st7
  int v18; // ecx
  char *v19; // edx
  char *v20; // esi
  float *v21; // ebx
  float *v22; // eax
  int v23; // edi
  double v24; // st7
  float *v25; // edi
  float *v26; // esi
  int m; // ebx
  double result; // st7
  unsigned __int8 v29; // dl
  double v30; // st7
  int v31; // edi
  float *v32; // ebx
  int v33; // eax
  double v34; // st6
  double v35; // st5
  float *v36; // ecx
  double v37; // st4
  double v38; // st2
  double v39; // st6
  double v40; // st5
  float *v41; // ecx
  double v42; // st4
  double v43; // st2
  int v44; // eax
  int v45; // esi
  double v46; // st7
  double v47; // st6
  double v48; // st5
  double v49; // st5
  __m128 *v50; // esi
  __m128 v51; // xmm0
  __m128 *v52; // edi
  __m128 v53; // xmm0
  int v54; // edx
  __m128 *v55; // ecx
  __m128 *v56; // eax
  __m128 v57; // xmm0
  __m128 v58; // xmm0
  __m128 v59; // xmm2
  __m128 v60; // xmm0
  __m128 v61; // xmm5
  __m128 v62; // xmm0
  __m128 v63; // xmm2
  __m128 v64; // xmm0
  __m128 v65; // xmm2
  __m128 v66; // xmm2
  __m128 v67; // xmm3
  __m128 v68; // xmm2
  __m128 v69; // xmm6
  __m128 v70; // xmm2
  __m128 v71; // xmm3
  __m128 v72; // xmm0
  bool v73; // zf
  float *v74; // edi
  float *v75; // esi
  int ii; // ebx
  double v77; // st7
  int v78; // edi
  float *v79; // ebx
  int v80; // eax
  double v81; // st6
  double v82; // st5
  float *v83; // ecx
  double v84; // st3
  double v85; // st2
  double v86; // st6
  double v87; // st5
  float *v88; // ecx
  double v89; // st3
  double v90; // st2
  double v91; // st7
  double v92; // st5
  double v93; // st7
  double v94; // st5
  double v95; // rt2
  __m128 *v96; // esi
  __m128 v97; // xmm0
  __m128 *v98; // edi
  __m128 v99; // xmm0
  int v100; // edx
  __m128 *v101; // ecx
  __m128 *v102; // eax
  __m128 v103; // xmm0
  __m128 v104; // xmm0
  __m128 v105; // xmm2
  __m128 v106; // xmm0
  __m128 v107; // xmm5
  __m128 v108; // xmm0
  __m128 v109; // xmm2
  __m128 v110; // xmm0
  __m128 v111; // xmm2
  __m128 v112; // xmm2
  __m128 v113; // xmm3
  __m128 v114; // xmm2
  __m128 v115; // xmm6
  __m128 v116; // xmm2
  __m128 v117; // xmm3
  __m128 v118; // xmm0
  float *v119; // edi
  float *v120; // esi
  int mm; // ebx
  double v122; // st7
  int v123; // edi
  float *v124; // ebx
  int v125; // eax
  double v126; // st6
  double v127; // st5
  float *v128; // ecx
  double v129; // st4
  double v130; // st2
  double v131; // st6
  double v132; // st5
  float *v133; // ecx
  double v134; // st4
  double v135; // st2
  double v136; // st7
  double v137; // st5
  double v138; // st7
  double v139; // st5
  double v140; // rt2
  __m128 *v141; // esi
  __m128 v142; // xmm0
  __m128 *v143; // edi
  __m128 v144; // xmm0
  int v145; // edx
  __m128 *v146; // ecx
  __m128 *v147; // eax
  __m128 v148; // xmm0
  __m128 v149; // xmm0
  __m128 v150; // xmm2
  __m128 v151; // xmm0
  __m128 v152; // xmm5
  __m128 v153; // xmm0
  __m128 v154; // xmm2
  __m128 v155; // xmm0
  __m128 v156; // xmm2
  __m128 v157; // xmm2
  __m128 v158; // xmm3
  __m128 v159; // xmm2
  __m128 v160; // xmm6
  __m128 v161; // xmm2
  __m128 v162; // xmm3
  __m128 v163; // xmm0
  float *v164; // edi
  float *v165; // esi
  int i1; // ebx
  float *v167; // eax
  float v168; // edx
  float v169; // ecx
  float v170; // edx
  float v171; // ecx
  float v172; // edx
  float v173; // [esp+14h] [ebp-1A5Ch]
  float v174; // [esp+14h] [ebp-1A5Ch]
  float v175; // [esp+14h] [ebp-1A5Ch]
  float v176; // [esp+14h] [ebp-1A5Ch]
  float v177; // [esp+14h] [ebp-1A5Ch]
  float v178; // [esp+14h] [ebp-1A5Ch]
  float v179; // [esp+14h] [ebp-1A5Ch]
  float v180; // [esp+14h] [ebp-1A5Ch]
  float v181; // [esp+14h] [ebp-1A5Ch]
  float v182; // [esp+14h] [ebp-1A5Ch]
  float v183; // [esp+14h] [ebp-1A5Ch]
  float v184; // [esp+14h] [ebp-1A5Ch]
  float v185; // [esp+14h] [ebp-1A5Ch]
  float v186; // [esp+14h] [ebp-1A5Ch]
  float v187; // [esp+14h] [ebp-1A5Ch]
  float v188; // [esp+14h] [ebp-1A5Ch]
  float v189; // [esp+14h] [ebp-1A5Ch]
  float v190; // [esp+14h] [ebp-1A5Ch]
  float v191; // [esp+18h] [ebp-1A58h]
  float v192; // [esp+18h] [ebp-1A58h]
  float v193; // [esp+18h] [ebp-1A58h]
  float v194; // [esp+18h] [ebp-1A58h]
  float v195; // [esp+18h] [ebp-1A58h]
  float v196; // [esp+18h] [ebp-1A58h]
  float v197; // [esp+18h] [ebp-1A58h]
  float v198; // [esp+18h] [ebp-1A58h]
  float v199; // [esp+18h] [ebp-1A58h]
  float v200; // [esp+18h] [ebp-1A58h]
  float v201; // [esp+18h] [ebp-1A58h]
  float v202; // [esp+18h] [ebp-1A58h]
  float v203; // [esp+18h] [ebp-1A58h]
  float v204; // [esp+18h] [ebp-1A58h]
  float v205; // [esp+18h] [ebp-1A58h]
  float v206; // [esp+18h] [ebp-1A58h]
  float v207; // [esp+18h] [ebp-1A58h]
  float v208; // [esp+18h] [ebp-1A58h]
  float v209; // [esp+1Ch] [ebp-1A54h]
  float v210; // [esp+1Ch] [ebp-1A54h]
  int v211; // [esp+1Ch] [ebp-1A54h]
  float v212; // [esp+1Ch] [ebp-1A54h]
  int jj; // [esp+1Ch] [ebp-1A54h]
  int v214; // [esp+1Ch] [ebp-1A54h]
  float v215; // [esp+1Ch] [ebp-1A54h]
  int nn; // [esp+1Ch] [ebp-1A54h]
  int v217; // [esp+1Ch] [ebp-1A54h]
  float v218; // [esp+1Ch] [ebp-1A54h]
  int i; // [esp+20h] [ebp-1A50h]
  int k; // [esp+20h] [ebp-1A50h]
  int n; // [esp+20h] [ebp-1A50h]
  int v222; // [esp+20h] [ebp-1A50h]
  int v223; // [esp+20h] [ebp-1A50h]
  int v224; // [esp+20h] [ebp-1A50h]
  int v225; // [esp+24h] [ebp-1A4Ch]
  int v226; // [esp+24h] [ebp-1A4Ch]
  int v227; // [esp+24h] [ebp-1A4Ch]
  float v228; // [esp+28h] [ebp-1A48h]
  float v229; // [esp+28h] [ebp-1A48h]
  float *v230; // [esp+2Ch] [ebp-1A44h]
  bool v231[4]; // [esp+30h] [ebp-1A40h] BYREF
  int v232; // [esp+34h] [ebp-1A3Ch]
  int v233; // [esp+38h] [ebp-1A38h]
  int v234; // [esp+3Ch] [ebp-1A34h]
  unsigned int v235; // [esp+40h] [ebp-1A30h]
  int v236; // [esp+44h] [ebp-1A2Ch]
  unsigned int v237; // [esp+48h] [ebp-1A28h]
  unsigned int v238; // [esp+4Ch] [ebp-1A24h]
  double v239; // [esp+50h] [ebp-1A20h]
  float v240[2]; // [esp+58h] [ebp-1A18h] BYREF
  float v241; // [esp+60h] [ebp-1A10h]
  float v242; // [esp+64h] [ebp-1A0Ch]
  float v243; // [esp+68h] [ebp-1A08h]
  float v244; // [esp+6Ch] [ebp-1A04h]
  double kk; // [esp+78h] [ebp-19F8h]
  double v246; // [esp+80h] [ebp-19F0h]
  double v247; // [esp+88h] [ebp-19E8h]
  float v248; // [esp+90h] [ebp-19E0h]
  float v249; // [esp+94h] [ebp-19DCh]
  float v250; // [esp+98h] [ebp-19D8h]
  float *v251; // [esp+9Ch] [ebp-19D4h]
  float v252[2]; // [esp+A0h] [ebp-19D0h] BYREF
  float v253[2]; // [esp+A8h] [ebp-19C8h] BYREF
  float v254[4]; // [esp+B0h] [ebp-19C0h] BYREF
  __m128 v255; // [esp+C0h] [ebp-19B0h]
  __m128 v256; // [esp+D0h] [ebp-19A0h]
  __m128 v257; // [esp+E0h] [ebp-1990h]
  __m128 v258; // [esp+F0h] [ebp-1980h]
  __m128 v259; // [esp+100h] [ebp-1970h]
  __m128 v260; // [esp+110h] [ebp-1960h]
  __m128 v261; // [esp+120h] [ebp-1950h]
  float v262; // [esp+130h] [ebp-1940h] BYREF
  float v263; // [esp+134h] [ebp-193Ch]
  float v264; // [esp+138h] [ebp-1938h]
  float v265; // [esp+13Ch] [ebp-1934h]
  float v266; // [esp+140h] [ebp-1930h]
  float v267[3]; // [esp+144h] [ebp-192Ch]
  float v268[16]; // [esp+150h] [ebp-1920h] BYREF
  float v269[16]; // [esp+190h] [ebp-18E0h] BYREF
  float v270[32]; // [esp+1D0h] [ebp-18A0h] BYREF
  float v271[256]; // [esp+250h] [ebp-1820h] BYREF
  _BYTE v272[256]; // [esp+650h] [ebp-1420h] BYREF
  char v273; // [esp+750h] [ebp-1320h] BYREF
  _BYTE v274[516]; // [esp+850h] [ebp-1220h] BYREF
  _BYTE v275[60]; // [esp+A54h] [ebp-101Ch] BYREF
  _BYTE v276[4032]; // [esp+A90h] [ebp-FE0h] BYREF
  __m128 v277; // [esp+1A50h] [ebp-20h]
  __m128 v278; // [esp+1A60h] [ebp-10h]

  v251 = a1;
  v233 = (a5 + 3) / 4;
  if ( a5 > 0 )
  {
    v230 = (float *)v272;
    v12 = v271;
    for ( i = a5; i != 0; --i )
    {
      v13 = v230;
      v14 = v12;
      for ( j = 3; j != 0; --j )
      {
        v16 = *(float *)((char *)v14++ + a3 - (_DWORD)v271);
        v209 = v16;
        v13 += 64;
        *(v14 - 1) = v209;
        *(v13 - 64) = v209;
      }
      ++v230;
      v12 += 4;
    }
  }
  if ( a7 != nullptr )
  {
    v238 = *(unsigned int *)a7;
    v235 = *((unsigned int *)a7 + 1);
    v17 = a7[2];
  }
  else
  {
    v17 = 1.0;
    *(float *)&v238 = 1.0;
    *(float *)&v235 = 1.0;
  }
  *(float *)&v237 = v17;
  v250 = (float)(1 << (8 - a8));
  v249 = (float)(1 << (8 - a9));
  v18 = a2 - (_DWORD)a1;
  v19 = (char *)((char *)v240 - (char *)a1);
  v20 = (char *)((char *)&v262 - (char *)a1);
  v248 = (float)(1 << (8 - a10));
  v21 = a1;
  for ( k = 2; k != 0; --k )
  {
    v22 = v21;
    v23 = 3;
    do
    {
      v24 = *(float *)((char *)v22 + v18);
      v22 += 2;
      --v23;
      v210 = v24;
      *(v22 - 2) = v210;
      *(float *)((char *)v22 + (_DWORD)v19 - 8) = v210;
      *(float *)((char *)v22 + (_DWORD)v20 - 8) = v210;
    }
    while ( v23 != 0 );
    ++v21;
  }
  MkWkRmpPts(a1: v231, a2: (float (*const)[2])v252, a3: (float (*const)[2])v240, a4: a8, a5: a9, a6: a10);
  v25 = v268;
  v26 = v252;
  for ( m = 3; m != 0; --m )
  {
    BldClrRmp(a1: v25, a2: v26, a3: a6);
    v26 += 2;
    v25 += 16;
  }
  v228 = sub_4F0A40(a1: a4, a2: v268, a3: a5, a4: a6, a5: v231[0], a6: a7);
  result = v228;
  if ( v228 != 0.0 )
  {
    v29 = a11;
    if ( a11 != 0 )
    {
      v30 = *(float *)&v235;
      if ( a5 > 0 )
      {
        v31 = 0;
        v32 = (float *)v275;
        for ( n = a5; n != 0; --n )
        {
          v33 = 0;
          if ( a6 >= 4u )
          {
            v34 = v271[v31 + 1];
            v35 = v271[v31];
            v36 = v32;
            v37 = *(float *)&v237;
            do
            {
              v38 = v269[v33];
              v33 += 4;
              v36 += 4;
              v191 = v38 - v34;
              v173 = v267[v33 - 1] - v35;
              *(v36 - 5) = v191 * v191 * v30 + v173 * v173 * v37;
              v192 = v268[v33 + 13] - v34;
              v174 = v267[v33] - v35;
              *(v36 - 4) = v192 * v192 * v30 + v174 * v174 * v37;
              v193 = v268[v33 + 14] - v34;
              v175 = v267[v33 + 1] - v35;
              *(v36 - 3) = v193 * v193 * v30 + v175 * v175 * v37;
              v194 = v268[v33 + 15] - v34;
              v176 = v267[v33 + 2] - v35;
              *(v36 - 2) = v194 * v194 * v30 + v176 * v176 * v37;
            }
            while ( v33 < a6 - 3 );
            v29 = a11;
          }
          if ( v33 < a6 )
          {
            v39 = v271[v31 + 1];
            v40 = v271[v31];
            v41 = (float *)&v274[4 * v33 + 512 + 1 * v31];
            v42 = *(float *)&v237;
            do
            {
              v43 = v269[v33++];
              ++v41;
              v195 = v43 - v39;
              v177 = v267[v33 + 2] - v40;
              *(v41 - 1) = v195 * v195 * v30 + v177 * v177 * v42;
            }
            while ( v33 < a6 );
          }
          v32 += 16;
          v31 += 4;
        }
      }
      v44 = v29;
      v196 = v266;
      v178 = v267[0];
      if ( v29 >= 8u )
        v44 = 8;
      v236 = -v44;
      v45 = v29;
      if ( v29 >= 8u )
        v45 = 8;
      v234 = v45;
      v232 = (a6 + 3) / 4;
      v222 = -v44;
      if ( -v44 <= v45 )
      {
        v46 = 255.0;
        v246 = v266;
        v257 = _mm_shuffle_ps((__m128)v238, (__m128)v238, 0);
        v239 = v250;
        v47 = 0.0;
        v256 = 0;
        v247 = v267[0];
        while ( 1 )
        {
          v225 = v236;
          v48 = (double)v222 * v239 + v246;
          kk = v48;
          while ( 1 )
          {
            if ( v48 > v47 && v48 >= v46 )
            {
              v48 = v46;
            }
            else if ( v48 <= v47 )
            {
              v48 = v47;
            }
            v243 = v48;
            v49 = (double)v225 * v239 + v247;
            if ( v49 <= v47 || v49 < v46 )
            {
              v46 = v49;
              if ( v47 >= v49 )
                v46 = v47;
            }
            v244 = v46;
            MkWkRmpPts(a1: v231, a2: (float (*const)[2])v252, a3: (float (*const)[2])v240, a4: a8, a5: a9, a6: a10);
            BldClrRmp(a1: v270, a2: v254, a3: a6);
            v277 = v256;
            if ( v233 > 0 )
            {
              v50 = a4;
              v51 = _mm_shuffle_ps((__m128)0x7F7FFFFFu, (__m128)0x7F7FFFFFu, 0);
              v258 = v51;
              v52 = (__m128 *)v276;
              v211 = v233;
              while ( 1 )
              {
                v278 = v51;
                if ( v232 > 0 )
                {
                  v53 = *(__m128 *)((char *)v50 + v274 - (_BYTE *)a4);
                  v54 = v232;
                  v259 = _mm_shuffle_ps(v53, v53, 0);
                  v255 = _mm_shuffle_ps(v53, v53, 85);
                  v260 = _mm_shuffle_ps(v53, v53, 170);
                  v261 = _mm_shuffle_ps(v53, v53, 255);
                  v55 = (__m128 *)v270;
                  v56 = v52;
                  do
                  {
                    v57 = _mm_sub_ps(v259, *v55);
                    v58 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v57, v57), v257), v56[-4]);
                    v59 = _mm_min_ps(_mm_shuffle_ps(v58, v256, 254), v58);
                    v60 = _mm_sub_ps(v255, *v55);
                    v61 = _mm_min_ps(_mm_shuffle_ps(v59, v256, 253), v59);
                    v62 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v60, v60), v257), *v56);
                    v63 = _mm_min_ps(_mm_shuffle_ps(v62, v256, 254), v62);
                    v64 = _mm_min_ps(_mm_shuffle_ps(v63, v256, 243), v63);
                    v65 = _mm_sub_ps(v260, *v55);
                    v66 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v65, v65), v257), v56[4]);
                    v67 = _mm_min_ps(_mm_shuffle_ps(v256, v66, 79), v66);
                    v68 = _mm_sub_ps(v261, *v55);
                    v69 = _mm_min_ps(_mm_shuffle_ps(v256, v67, 63), v67);
                    v70 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v68, v68), v257), v56[8]);
                    v71 = _mm_min_ps(_mm_shuffle_ps(v256, v70, 79), v70);
                    ++v55;
                    ++v56;
                    --v54;
                    v278 = _mm_min_ps(
                             v278,
                             _mm_add_ps(
                               _mm_min_ps(_mm_shuffle_ps(v256, v71, 143), v71),
                               _mm_add_ps(_mm_add_ps(v64, v61), v69)));
                  }
                  while ( v54 != 0 );
                }
                v72 = _mm_add_ps(_mm_mul_ps(*v50, v278), v277);
                v52 += 16;
                ++v50;
                v73 = v211-- == 1;
                v277 = v72;
                if ( v73 )
                  break;
                v51 = v258;
              }
            }
            v212 = v277.m128_f32[1] + v277.m128_f32[0] + v277.m128_f32[2] + v277.m128_f32[3];
            if ( v228 > (double)v212 )
            {
              v196 = v243;
              v178 = v244;
              v228 = v277.m128_f32[1] + v277.m128_f32[0] + v277.m128_f32[2] + v277.m128_f32[3];
            }
            if ( ++v225 > v234 )
              break;
            v47 = 0.0;
            v48 = kk;
            v46 = 255.0;
          }
          if ( ++v222 > v234 )
            break;
          v46 = 255.0;
          v47 = 0.0;
        }
      }
      v243 = v196;
      v244 = v178;
      MkWkRmpPts(a1: v231, a2: (float (*const)[2])v252, a3: (float (*const)[2])v240, a4: a8, a5: a9, a6: a10);
      v74 = v268;
      v75 = v252;
      for ( ii = 3; ii != 0; --ii )
      {
        BldClrRmp(a1: v74, a2: v75, a3: a6);
        v75 += 2;
        v74 += 16;
      }
      if ( a5 > 0 )
      {
        v77 = *(float *)&v237;
        v78 = 0;
        v79 = (float *)v275;
        for ( jj = a5; jj != 0; --jj )
        {
          v80 = 0;
          if ( a6 >= 4u )
          {
            v81 = v271[v78 + 2];
            v82 = v271[v78];
            v83 = v79;
            v84 = *(float *)&v238;
            do
            {
              v85 = v270[v80];
              v80 += 4;
              v83 += 4;
              v179 = v85 - v81;
              v197 = v267[v80 - 1] - v82;
              *(v83 - 5) = v179 * v179 * v84 + v197 * v197 * v77;
              v180 = v269[v80 + 13] - v81;
              v198 = v267[v80] - v82;
              *(v83 - 4) = v180 * v180 * v84 + v198 * v198 * v77;
              v181 = v269[v80 + 14] - v81;
              v199 = v267[v80 + 1] - v82;
              *(v83 - 3) = v181 * v181 * v84 + v199 * v199 * v77;
              v182 = v269[v80 + 15] - v81;
              v200 = v267[v80 + 2] - v82;
              *(v83 - 2) = v182 * v182 * v84 + v200 * v200 * v77;
            }
            while ( v80 < a6 - 3 );
          }
          if ( v80 < a6 )
          {
            v86 = v271[v78 + 2];
            v87 = v271[v78];
            v88 = (float *)&v274[4 * v80 + 512 + 1 * v78];
            v89 = *(float *)&v238;
            do
            {
              v90 = v270[v80++];
              ++v88;
              v183 = v90 - v86;
              v201 = v267[v80 + 2] - v87;
              *(v88 - 1) = v183 * v183 * v89 + v201 * v201 * v77;
            }
            while ( v80 < a6 );
          }
          v79 += 16;
          v78 += 4;
        }
      }
      v202 = v264;
      v226 = v236;
      v184 = v265;
      if ( v236 <= v234 )
      {
        v247 = v264;
        v261 = _mm_shuffle_ps((__m128)v235, (__m128)v235, 0);
        v239 = v249;
        v256 = 0;
        v246 = v265;
        do
        {
          v223 = v236;
          v91 = (double)v226 * v239 + v247;
          for ( kk = v91; ; v91 = kk )
          {
            if ( v91 <= 0.0 )
            {
              v92 = 255.0;
            }
            else
            {
              v92 = 255.0;
              if ( v91 >= 255.0 )
              {
                v93 = 255.0;
                goto LABEL_74;
              }
            }
            v95 = v92;
            v92 = v91;
            v93 = v95;
            if ( v92 <= 0.0 )
              v92 = 0.0;
LABEL_74:
            v241 = v92;
            v94 = (double)v223 * v239 + v246;
            if ( v94 <= 0.0 || v94 < v93 )
            {
              v93 = v94;
              if ( v94 <= 0.0 )
                v93 = 0.0;
            }
            v242 = v93;
            MkWkRmpPts(a1: v231, a2: (float (*const)[2])v252, a3: (float (*const)[2])v240, a4: a8, a5: a9, a6: a10);
            BldClrRmp(a1: v269, a2: v253, a3: a6);
            v277 = v256;
            if ( v233 > 0 )
            {
              v96 = a4;
              v97 = _mm_shuffle_ps((__m128)0x7F7FFFFFu, (__m128)0x7F7FFFFFu, 0);
              v260 = v97;
              v98 = (__m128 *)v276;
              v214 = v233;
              while ( 1 )
              {
                v278 = v97;
                if ( v232 > 0 )
                {
                  v99 = *(__m128 *)((char *)v96 + &v273 - (char *)a4);
                  v100 = v232;
                  v255 = _mm_shuffle_ps(v99, v99, 0);
                  v259 = _mm_shuffle_ps(v99, v99, 85);
                  v258 = _mm_shuffle_ps(v99, v99, 170);
                  v257 = _mm_shuffle_ps(v99, v99, 255);
                  v101 = (__m128 *)v269;
                  v102 = v98;
                  do
                  {
                    v103 = _mm_sub_ps(v255, *v101);
                    v104 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v103, v103), v261), v102[-4]);
                    v105 = _mm_min_ps(_mm_shuffle_ps(v104, v256, 254), v104);
                    v106 = _mm_sub_ps(v259, *v101);
                    v107 = _mm_min_ps(_mm_shuffle_ps(v105, v256, 253), v105);
                    v108 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v106, v106), v261), *v102);
                    v109 = _mm_min_ps(_mm_shuffle_ps(v108, v256, 254), v108);
                    v110 = _mm_min_ps(_mm_shuffle_ps(v109, v256, 243), v109);
                    v111 = _mm_sub_ps(v258, *v101);
                    v112 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v111, v111), v261), v102[4]);
                    v113 = _mm_min_ps(_mm_shuffle_ps(v256, v112, 79), v112);
                    v114 = _mm_sub_ps(v257, *v101);
                    v115 = _mm_min_ps(_mm_shuffle_ps(v256, v113, 63), v113);
                    v116 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v114, v114), v261), v102[8]);
                    v117 = _mm_min_ps(_mm_shuffle_ps(v256, v116, 79), v116);
                    ++v101;
                    ++v102;
                    --v100;
                    v278 = _mm_min_ps(
                             v278,
                             _mm_add_ps(
                               _mm_min_ps(_mm_shuffle_ps(v256, v117, 143), v117),
                               _mm_add_ps(_mm_add_ps(v110, v107), v115)));
                  }
                  while ( v100 != 0 );
                }
                v118 = _mm_add_ps(_mm_mul_ps(*v96, v278), v277);
                v98 += 16;
                ++v96;
                v73 = v214-- == 1;
                v277 = v118;
                if ( v73 )
                  break;
                v97 = v260;
              }
            }
            v215 = v277.m128_f32[1] + v277.m128_f32[0] + v277.m128_f32[2] + v277.m128_f32[3];
            if ( v228 > (double)v215 )
            {
              v202 = v241;
              v184 = v242;
              v228 = v277.m128_f32[1] + v277.m128_f32[0] + v277.m128_f32[2] + v277.m128_f32[3];
            }
            if ( ++v223 > v234 )
              break;
          }
          ++v226;
        }
        while ( v226 <= v234 );
      }
      v241 = v202;
      v242 = v184;
      MkWkRmpPts(a1: v231, a2: (float (*const)[2])v252, a3: (float (*const)[2])v240, a4: a8, a5: a9, a6: a10);
      v119 = v268;
      v120 = v252;
      for ( mm = 3; mm != 0; --mm )
      {
        BldClrRmp(a1: v119, a2: v120, a3: a6);
        v120 += 2;
        v119 += 16;
      }
      if ( a5 > 0 )
      {
        v122 = *(float *)&v238;
        v123 = 0;
        v124 = (float *)v275;
        for ( nn = a5; nn != 0; --nn )
        {
          v125 = 0;
          if ( a6 >= 4u )
          {
            v126 = v271[v123 + 2];
            v127 = v271[v123 + 1];
            v128 = v124;
            v129 = *(float *)&v235;
            do
            {
              v130 = v270[v125];
              v125 += 4;
              v128 += 4;
              v185 = v130 - v126;
              v203 = v268[v125 + 12] - v127;
              *(v128 - 5) = v203 * v203 * v129 + v185 * v185 * v122;
              v186 = v269[v125 + 13] - v126;
              v204 = v268[v125 + 13] - v127;
              *(v128 - 4) = v204 * v204 * v129 + v186 * v186 * v122;
              v187 = v269[v125 + 14] - v126;
              v205 = v268[v125 + 14] - v127;
              *(v128 - 3) = v205 * v205 * v129 + v187 * v187 * v122;
              v188 = v269[v125 + 15] - v126;
              v206 = v268[v125 + 15] - v127;
              *(v128 - 2) = v206 * v206 * v129 + v188 * v188 * v122;
            }
            while ( v125 < a6 - 3 );
          }
          if ( v125 < a6 )
          {
            v131 = v271[v123 + 2];
            v132 = v271[v123 + 1];
            v133 = (float *)&v274[1 * v123 + 512 + 4 * v125];
            v134 = *(float *)&v235;
            do
            {
              v135 = v270[v125++];
              ++v133;
              v189 = v135 - v131;
              v207 = v268[v125 + 15] - v132;
              *(v133 - 1) = v207 * v207 * v134 + v189 * v189 * v122;
            }
            while ( v125 < a6 );
          }
          v124 += 16;
          v123 += 4;
        }
      }
      v208 = v262;
      v227 = v236;
      v190 = v263;
      if ( v236 <= v234 )
      {
        v247 = v262;
        v261 = _mm_shuffle_ps((__m128)v237, (__m128)v237, 0);
        v239 = v248;
        v256 = 0;
        v246 = v263;
        do
        {
          v224 = v236;
          v136 = (double)v227 * v239 + v247;
          for ( kk = v136; ; v136 = kk )
          {
            if ( v136 <= 0.0 )
            {
              v137 = 255.0;
            }
            else
            {
              v137 = 255.0;
              if ( v136 >= 255.0 )
              {
                v138 = 255.0;
                goto LABEL_110;
              }
            }
            v140 = v137;
            v137 = v136;
            v138 = v140;
            if ( v137 <= 0.0 )
              v137 = 0.0;
LABEL_110:
            v240[0] = v137;
            v139 = (double)v224 * v239 + v246;
            if ( v139 <= 0.0 || v139 < v138 )
            {
              v138 = v139;
              if ( v139 <= 0.0 )
                v138 = 0.0;
            }
            v240[1] = v138;
            MkWkRmpPts(a1: v231, a2: (float (*const)[2])v252, a3: (float (*const)[2])v240, a4: a8, a5: a9, a6: a10);
            BldClrRmp(a1: v268, a2: v252, a3: a6);
            v277 = v256;
            if ( v233 > 0 )
            {
              v141 = a4;
              v142 = _mm_shuffle_ps((__m128)0x7F7FFFFFu, (__m128)0x7F7FFFFFu, 0);
              v260 = v142;
              v143 = (__m128 *)v276;
              v217 = v233;
              while ( 1 )
              {
                v278 = v142;
                if ( v232 > 0 )
                {
                  v144 = *(__m128 *)((char *)v141 + v272 - (_BYTE *)a4);
                  v145 = v232;
                  v255 = _mm_shuffle_ps(v144, v144, 0);
                  v259 = _mm_shuffle_ps(v144, v144, 85);
                  v258 = _mm_shuffle_ps(v144, v144, 170);
                  v257 = _mm_shuffle_ps(v144, v144, 255);
                  v146 = (__m128 *)v268;
                  v147 = v143;
                  do
                  {
                    v148 = _mm_sub_ps(v255, *v146);
                    v149 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v148, v148), v261), v147[-4]);
                    v150 = _mm_min_ps(_mm_shuffle_ps(v149, v256, 254), v149);
                    v151 = _mm_sub_ps(v259, *v146);
                    v152 = _mm_min_ps(_mm_shuffle_ps(v150, v256, 253), v150);
                    v153 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v151, v151), v261), *v147);
                    v154 = _mm_min_ps(_mm_shuffle_ps(v153, v256, 254), v153);
                    v155 = _mm_min_ps(_mm_shuffle_ps(v154, v256, 243), v154);
                    v156 = _mm_sub_ps(v258, *v146);
                    v157 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v156, v156), v261), v147[4]);
                    v158 = _mm_min_ps(_mm_shuffle_ps(v256, v157, 79), v157);
                    v159 = _mm_sub_ps(v257, *v146);
                    v160 = _mm_min_ps(_mm_shuffle_ps(v256, v158, 63), v158);
                    v161 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v159, v159), v261), v147[8]);
                    v162 = _mm_min_ps(_mm_shuffle_ps(v256, v161, 79), v161);
                    ++v146;
                    ++v147;
                    --v145;
                    v278 = _mm_min_ps(
                             v278,
                             _mm_add_ps(
                               _mm_min_ps(_mm_shuffle_ps(v256, v162, 143), v162),
                               _mm_add_ps(_mm_add_ps(v155, v152), v160)));
                  }
                  while ( v145 != 0 );
                }
                v163 = _mm_add_ps(_mm_mul_ps(*v141, v278), v277);
                v143 += 16;
                ++v141;
                v73 = v217-- == 1;
                v277 = v163;
                if ( v73 )
                  break;
                v142 = v260;
              }
            }
            v218 = v277.m128_f32[1] + v277.m128_f32[0] + v277.m128_f32[2] + v277.m128_f32[3];
            if ( v228 > (double)v218 )
            {
              v208 = v240[0];
              v190 = v240[1];
              v228 = v277.m128_f32[1] + v277.m128_f32[0] + v277.m128_f32[2] + v277.m128_f32[3];
            }
            if ( ++v224 > v234 )
              break;
          }
          ++v227;
        }
        while ( v227 <= v234 );
      }
      v240[0] = v208;
      v240[1] = v190;
      MkWkRmpPts(a1: v231, a2: (float (*const)[2])v252, a3: (float (*const)[2])v240, a4: a8, a5: a9, a6: a10);
      v164 = v268;
      v165 = v252;
      for ( i1 = 3; i1 != 0; --i1 )
      {
        BldClrRmp(a1: v164, a2: v165, a3: a6);
        v165 += 2;
        v164 += 16;
      }
      v229 = sub_4F0A40(a1: a4, a2: v268, a3: a5, a4: a6, a5: v231[0], a6: a7);
      v167 = v251;
      v168 = v240[1];
      *v251 = v240[0];
      v169 = v241;
      v167[1] = v168;
      v170 = v242;
      v167[2] = v169;
      v171 = v243;
      v167[3] = v170;
      v172 = v244;
      v167[4] = v171;
      v167[5] = v172;
      return v229;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F66F0
// Name: sub_4F66F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall sub_4F66F0@<st0>(
        int a1@<edx>,
        int a2,
        int a3,
        __m128 *a4,
        int a5,
        unsigned __int8 a6,
        float *a7,
        char a8,
        char a9,
        char a10,
        unsigned __int8 a11)
{
  float *v12; // ebx
  float *v13; // ecx
  float *v14; // eax
  int j; // edx
  double v16; // st7
  double v17; // st7
  char *v18; // esi
  int v19; // ecx
  char *v20; // edx
  int v21; // ebx
  int v22; // eax
  int v23; // edi
  double v24; // st7
  float *v25; // edi
  float *v26; // esi
  int m; // ebx
  double result; // st7
  int v29; // eax
  int v30; // esi
  double v31; // st7
  double v32; // st6
  double v33; // st5
  double v34; // st5
  double v35; // st7
  int v36; // edi
  float *v37; // ebx
  int v38; // eax
  double v39; // st6
  float *v40; // ecx
  double v41; // st4
  double v42; // st6
  float *v43; // ecx
  double v44; // st4
  double v45; // st7
  double v46; // st6
  double v47; // st5
  double v48; // st7
  double v49; // rt0
  double v50; // st5
  int v51; // ebx
  double v52; // st7
  int v53; // edi
  int v54; // ecx
  double v55; // st6
  int v56; // eax
  double v57; // st4
  double v58; // st6
  int v59; // eax
  double v60; // st4
  double v61; // st7
  double v62; // st6
  double v63; // st5
  double v64; // st7
  double v65; // rt1
  double v66; // st5
  __m128 v67; // xmm7
  __m128 *v68; // esi
  __m128 v69; // xmm0
  __m128 *v70; // edi
  __m128 v71; // xmm0
  int v72; // edx
  __m128 *v73; // ecx
  __m128 *v74; // eax
  __m128 v75; // xmm0
  __m128 v76; // xmm0
  __m128 v77; // xmm2
  __m128 v78; // xmm0
  __m128 v79; // xmm5
  __m128 v80; // xmm0
  __m128 v81; // xmm2
  __m128 v82; // xmm0
  __m128 v83; // xmm2
  __m128 v84; // xmm2
  __m128 v85; // xmm3
  __m128 v86; // xmm2
  __m128 v87; // xmm6
  __m128 v88; // xmm2
  __m128 v89; // xmm3
  __m128 v90; // xmm0
  bool v91; // zf
  int v92; // edx
  char *v93; // esi
  int ii; // edi
  int v95; // eax
  int jj; // ecx
  double v97; // st7
  float *v98; // edi
  float *v99; // esi
  int kk; // ebx
  float v101; // [esp+Ch] [ebp-2A74h]
  float v102; // [esp+Ch] [ebp-2A74h]
  float v103; // [esp+Ch] [ebp-2A74h]
  float v104; // [esp+Ch] [ebp-2A74h]
  float v105; // [esp+Ch] [ebp-2A74h]
  float v106; // [esp+Ch] [ebp-2A74h]
  float v107; // [esp+Ch] [ebp-2A74h]
  float v108; // [esp+Ch] [ebp-2A74h]
  float v109; // [esp+Ch] [ebp-2A74h]
  float v110; // [esp+Ch] [ebp-2A74h]
  int v111; // [esp+Ch] [ebp-2A74h]
  float v112; // [esp+10h] [ebp-2A70h]
  float v113; // [esp+10h] [ebp-2A70h]
  int v114; // [esp+10h] [ebp-2A70h]
  float v115; // [esp+10h] [ebp-2A70h]
  int i; // [esp+14h] [ebp-2A6Ch]
  int k; // [esp+14h] [ebp-2A6Ch]
  float *v118; // [esp+18h] [ebp-2A68h]
  int v119; // [esp+18h] [ebp-2A68h]
  bool v120[4]; // [esp+1Ch] [ebp-2A64h] BYREF
  int n; // [esp+20h] [ebp-2A60h]
  int v122; // [esp+24h] [ebp-2A5Ch]
  int v123; // [esp+28h] [ebp-2A58h]
  int v124; // [esp+2Ch] [ebp-2A54h]
  int v125; // [esp+30h] [ebp-2A50h]
  float v126; // [esp+34h] [ebp-2A4Ch]
  int v127; // [esp+38h] [ebp-2A48h]
  unsigned int v128; // [esp+3Ch] [ebp-2A44h]
  float v129; // [esp+40h] [ebp-2A40h]
  int v130; // [esp+44h] [ebp-2A3Ch]
  float v131; // [esp+48h] [ebp-2A38h]
  int v132; // [esp+4Ch] [ebp-2A34h]
  double v133; // [esp+50h] [ebp-2A30h]
  float v134; // [esp+58h] [ebp-2A28h]
  char *v135; // [esp+60h] [ebp-2A20h]
  int v136; // [esp+64h] [ebp-2A1Ch]
  double v137; // [esp+68h] [ebp-2A18h]
  double v138; // [esp+70h] [ebp-2A10h]
  float v139[2]; // [esp+78h] [ebp-2A08h] BYREF
  float v140; // [esp+80h] [ebp-2A00h]
  float v141; // [esp+84h] [ebp-29FCh]
  float v142; // [esp+88h] [ebp-29F8h]
  float v143; // [esp+8Ch] [ebp-29F4h]
  double v144; // [esp+98h] [ebp-29E8h]
  float v145[2]; // [esp+A0h] [ebp-29E0h] BYREF
  float v146[2]; // [esp+A8h] [ebp-29D8h] BYREF
  float v147[4]; // [esp+B0h] [ebp-29D0h] BYREF
  __m128 v148; // [esp+C0h] [ebp-29C0h] BYREF
  float v149; // [esp+D0h] [ebp-29B0h]
  float v150; // [esp+D4h] [ebp-29ACh]
  double v151; // [esp+E8h] [ebp-2998h]
  double v152; // [esp+F0h] [ebp-2990h]
  double v153; // [esp+F8h] [ebp-2988h]
  double v154; // [esp+100h] [ebp-2980h]
  double v155; // [esp+108h] [ebp-2978h]
  __m128 v156; // [esp+110h] [ebp-2970h]
  __m128 v157; // [esp+120h] [ebp-2960h]
  __m128 v158; // [esp+130h] [ebp-2950h]
  __m128 v159; // [esp+140h] [ebp-2940h]
  __m128 v160; // [esp+150h] [ebp-2930h]
  float v161[16]; // [esp+160h] [ebp-2920h] BYREF
  float v162[16]; // [esp+1A0h] [ebp-28E0h] BYREF
  float v163[32]; // [esp+1E0h] [ebp-28A0h] BYREF
  float v164[272]; // [esp+260h] [ebp-2820h] BYREF
  char v165; // [esp+6A0h] [ebp-23E0h] BYREF
  char v166; // [esp+1660h] [ebp-1420h] BYREF
  _BYTE v167[516]; // [esp+1860h] [ebp-1220h] BYREF
  char v168; // [esp+1A64h] [ebp-101Ch] BYREF
  __m128 v169; // [esp+2A60h] [ebp-20h]
  __m128 v170; // [esp+2A70h] [ebp-10h]

  v136 = a1;
  v132 = (a5 + 3) / 4;
  if ( a5 > 0 )
  {
    v118 = (float *)&v166;
    v12 = v164;
    for ( i = a5; i != 0; --i )
    {
      v13 = v118;
      v14 = v12;
      for ( j = 3; j != 0; --j )
      {
        v16 = *(float *)((char *)v14++ + a3 - (_DWORD)v164);
        v112 = v16;
        v13 += 64;
        *(v14 - 1) = v112;
        *(v13 - 64) = v112;
      }
      ++v118;
      v12 += 4;
    }
  }
  if ( a7 != nullptr )
  {
    v128 = *(unsigned int *)a7;
    v129 = a7[1];
    v17 = a7[2];
  }
  else
  {
    v17 = 1.0;
    *(float *)&v128 = 1.0;
    v129 = 1.0;
  }
  v131 = v17;
  v134 = (float)(1 << (8 - a8));
  *((float *)&v133 + 1) = (float)(1 << (8 - a9));
  v18 = (char *)v139 - a1;
  v19 = a2 - a1;
  v135 = (char *)v139 - a1;
  *(float *)&v133 = (float)(1 << (8 - a10));
  v20 = (char *)&v148 - a1;
  v21 = a1;
  for ( k = 2; k != 0; --k )
  {
    v22 = v21;
    v23 = 3;
    do
    {
      v24 = *(float *)(v19 + v22);
      v22 += 8;
      --v23;
      v113 = v24;
      *(float *)(v22 - 8) = v113;
      *(float *)&v18[v22 - 8] = v113;
      *(float *)&v20[v22 - 8] = v113;
    }
    while ( v23 != 0 );
    v21 += 4;
  }
  MkWkRmpPts(a1: v120, a2: (float (*const)[2])v145, a3: (float (*const)[2])v139, a4: a8, a5: a9, a6: a10);
  v25 = v161;
  v26 = v145;
  for ( m = 3; m != 0; --m )
  {
    BldClrRmp(a1: v25, a2: v26, a3: a6);
    v26 += 2;
    v25 += 16;
  }
  v126 = sub_4F0A40(a1: a4, a2: v161, a3: a5, a4: a6, a5: v120[0], a6: a7);
  result = v126;
  if ( v126 != 0.0 && a11 != 0 )
  {
    v29 = a11;
    if ( a11 >= 8u )
      v29 = 8;
    v122 = -v29;
    v30 = a11;
    if ( a11 >= 8u )
      v30 = 8;
    v119 = v30;
    v130 = (a6 + 3) / 4;
    v123 = -v29;
    if ( -v29 > v30 )
      goto LABEL_96;
    v144 = *((float *)&v133 + 1);
    v158 = 0;
    v153 = v148.m128_f32[2];
    v154 = v148.m128_f32[3];
    v152 = v148.m128_f32[0];
    v138 = *(float *)&v133;
    v151 = v148.m128_f32[1];
    v155 = v149;
    v137 = v134;
    v133 = v150;
    while ( 1 )
    {
      v31 = 0.0;
      v32 = 255.0;
      v33 = (double)v123 * v144 + v153;
      if ( v33 > 0.0 && v33 >= 255.0 )
        break;
      if ( v33 > 0.0 )
        goto LABEL_28;
      v125 = v122;
      v140 = 0.0;
LABEL_30:
      while ( 2 )
      {
        v34 = (double)v125 * v144 + v154;
        if ( v34 > v31 && v34 >= v32 || (v32 = v34, v34 > v31) )
          v31 = v32;
        v141 = v31;
        MkWkRmpPts(a1: v120, a2: (float (*const)[2])v145, a3: (float (*const)[2])v139, a4: a8, a5: a9, a6: a10);
        BldClrRmp(a1: v162, a2: v146, a3: a6);
        if ( a5 > 0 )
        {
          v35 = v129;
          v36 = 0;
          v37 = (float *)&v168;
          for ( n = a5; n != 0; --n )
          {
            v38 = 0;
            if ( a6 >= 4u )
            {
              v39 = v164[v36 + 1];
              v40 = v37;
              do
              {
                v41 = v162[v38];
                v38 += 4;
                v40 += 4;
                v101 = v41 - v39;
                *(v40 - 5) = v101 * v101 * v35;
                v102 = v161[v38 + 13] - v39;
                *(v40 - 4) = v102 * v102 * v35;
                v103 = v161[v38 + 14] - v39;
                *(v40 - 3) = v103 * v103 * v35;
                v104 = v161[v38 + 15] - v39;
                *(v40 - 2) = v104 * v104 * v35;
              }
              while ( v38 < a6 - 3 );
            }
            if ( v38 < a6 )
            {
              v42 = v164[v36 + 1];
              v43 = (float *)&v167[4 * v38 + 512 + 1 * v36];
              do
              {
                v44 = v162[v38++];
                ++v43;
                v105 = v44 - v42;
                *(v43 - 1) = v105 * v105 * v35;
              }
              while ( v38 < a6 );
            }
            v37 += 16;
            v36 += 4;
          }
        }
        n = v122;
        do
        {
          v45 = (double)n * v138 + v152;
          v46 = 0.0;
          if ( v45 <= 0.0 )
          {
            v47 = 255.0;
          }
          else
          {
            v47 = 255.0;
            if ( v45 >= 255.0 )
            {
              v48 = 255.0;
              goto LABEL_47;
            }
          }
          v49 = v47;
          v47 = v45;
          v48 = v49;
          if ( v47 <= 0.0 )
          {
            v127 = v122;
            v139[0] = 0.0;
            goto LABEL_52;
          }
LABEL_47:
          v139[0] = v47;
          v127 = v122;
LABEL_52:
          while ( 2 )
          {
            v50 = (double)v127 * v138 + v151;
            if ( v50 <= v46 || v50 < v48 )
            {
              v48 = v50;
              if ( v46 >= v50 )
                v48 = v46;
            }
            v139[1] = v48;
            MkWkRmpPts(a1: v120, a2: (float (*const)[2])v145, a3: (float (*const)[2])v139, a4: a8, a5: a9, a6: a10);
            BldClrRmp(a1: v161, a2: v145, a3: a6);
            v51 = 0;
            if ( a5 > 0 )
            {
              v52 = v131;
              v53 = 0;
              do
              {
                v54 = 0;
                if ( a6 >= 4u )
                {
                  v55 = v164[v53];
                  v56 = v51 << 6;
                  do
                  {
                    v57 = v161[v54];
                    v54 += 4;
                    v56 += 16;
                    v106 = v57 - v55;
                    *(float *)((char *)&v164[252] + v56) = v106 * v106 * v52 + *(float *)&v167[v56 + 496];
                    v107 = v160.m128_f32[v54 + 1] - v55;
                    *(float *)((char *)&v164[253] + v56) = v107 * v107 * v52 + *(float *)&v167[v56 + 500];
                    v108 = v160.m128_f32[v54 + 2] - v55;
                    *(float *)((char *)&v164[254] + v56) = v108 * v108 * v52 + *(float *)&v167[v56 + 504];
                    v109 = v160.m128_f32[v54 + 3] - v55;
                    *(float *)((char *)&v164[255] + v56) = v109 * v109 * v52 + *(float *)&v167[v56 + 508];
                  }
                  while ( v54 < a6 - 3 );
                }
                if ( v54 < a6 )
                {
                  v58 = v164[v53];
                  v59 = v53 * 4 + v54;
                  do
                  {
                    v60 = v161[v54++];
                    ++v59;
                    v110 = v60 - v58;
                    v164[v59 + 255] = v110 * v110 * v52 + *(float *)&v167[v59 * 4 + 508];
                  }
                  while ( v54 < a6 );
                }
                ++v51;
                v53 += 4;
              }
              while ( v51 < a5 );
            }
            v124 = v122;
            do
            {
              v61 = (double)v124 * v137 + v155;
              v62 = 0.0;
              if ( v61 <= 0.0 )
              {
                v63 = 255.0;
              }
              else
              {
                v63 = 255.0;
                if ( v61 >= 255.0 )
                {
                  v64 = 255.0;
LABEL_69:
                  v142 = v63;
                  v111 = v122;
                  goto LABEL_74;
                }
              }
              v65 = v63;
              v63 = v61;
              v64 = v65;
              if ( v63 > 0.0 )
                goto LABEL_69;
              v111 = v122;
              v142 = 0.0;
              while ( 1 )
              {
LABEL_74:
                v66 = (double)v111 * v137 + v133;
                if ( v66 <= v62 || v66 < v64 )
                {
                  v64 = v66;
                  if ( v62 >= v66 )
                    v64 = v62;
                }
                v143 = v64;
                MkWkRmpPts(a1: v120, a2: (float (*const)[2])v145, a3: (float (*const)[2])v139, a4: a8, a5: a9, a6: a10);
                BldClrRmp(a1: v163, a2: v147, a3: a6);
                v169 = v158;
                v67 = _mm_shuffle_ps((__m128)v128, (__m128)v128, 0);
                if ( v132 > 0 )
                {
                  v68 = a4;
                  v69 = _mm_shuffle_ps((__m128)0x7F7FFFFFu, (__m128)0x7F7FFFFFu, 0);
                  v156 = v69;
                  v70 = (__m128 *)&v165;
                  v114 = v132;
                  while ( 1 )
                  {
                    v170 = v69;
                    if ( v130 > 0 )
                    {
                      v71 = *(__m128 *)((char *)v68 + v167 - (_BYTE *)a4);
                      v72 = v130;
                      v157 = _mm_shuffle_ps(v71, v71, 0);
                      v160 = _mm_shuffle_ps(v71, v71, 85);
                      v159 = _mm_shuffle_ps(v71, v71, 170);
                      v148 = _mm_shuffle_ps(v71, v71, 255);
                      v73 = (__m128 *)v163;
                      v74 = v70;
                      do
                      {
                        v75 = _mm_sub_ps(v157, *v73);
                        v76 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v75, v75), v67), v74[-4]);
                        v77 = _mm_min_ps(_mm_shuffle_ps(v76, v158, 254), v76);
                        v78 = _mm_sub_ps(v160, *v73);
                        v79 = _mm_min_ps(_mm_shuffle_ps(v77, v158, 253), v77);
                        v80 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v78, v78), v67), *v74);
                        v81 = _mm_min_ps(_mm_shuffle_ps(v80, v158, 254), v80);
                        v82 = _mm_min_ps(_mm_shuffle_ps(v81, v158, 243), v81);
                        v83 = _mm_sub_ps(v159, *v73);
                        v84 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v83, v83), v67), v74[4]);
                        v85 = _mm_min_ps(_mm_shuffle_ps(v158, v84, 79), v84);
                        v86 = _mm_sub_ps(v148, *v73);
                        v87 = _mm_min_ps(_mm_shuffle_ps(v158, v85, 63), v85);
                        v88 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v86, v86), v67), v74[8]);
                        v89 = _mm_min_ps(_mm_shuffle_ps(v158, v88, 79), v88);
                        ++v73;
                        ++v74;
                        --v72;
                        v170 = _mm_min_ps(
                                 v170,
                                 _mm_add_ps(
                                   _mm_min_ps(_mm_shuffle_ps(v158, v89, 143), v89),
                                   _mm_add_ps(_mm_add_ps(v82, v79), v87)));
                      }
                      while ( v72 != 0 );
                    }
                    v90 = _mm_add_ps(_mm_mul_ps(*v68, v170), v169);
                    v70 += 16;
                    ++v68;
                    v91 = v114-- == 1;
                    v169 = v90;
                    if ( v91 )
                      break;
                    v69 = v156;
                  }
                }
                v115 = v169.m128_f32[1] + v169.m128_f32[0] + v169.m128_f32[2] + v169.m128_f32[3];
                if ( v126 > (double)v115 )
                {
                  v92 = v136;
                  v126 = v169.m128_f32[1] + v169.m128_f32[0] + v169.m128_f32[2] + v169.m128_f32[3];
                  v93 = v135;
                  for ( ii = 2; ii != 0; --ii )
                  {
                    v95 = v92;
                    for ( jj = 3; jj != 0; --jj )
                    {
                      v97 = *(float *)&v93[v95];
                      v95 += 8;
                      *(float *)(v95 - 8) = v97;
                    }
                    v92 += 4;
                  }
                }
                if ( ++v111 > v119 )
                  break;
                v64 = 255.0;
                v62 = 0.0;
              }
              ++v124;
            }
            while ( v124 <= v119 );
            if ( ++v127 <= v119 )
            {
              v48 = 255.0;
              v46 = 0.0;
              continue;
            }
            break;
          }
          ++n;
        }
        while ( n <= v119 );
        if ( ++v125 <= v119 )
        {
          v31 = 0.0;
          v32 = 255.0;
          continue;
        }
        break;
      }
      if ( ++v123 > v119 )
      {
LABEL_96:
        MkWkRmpPts(a1: v120, a2: (float (*const)[2])v145, a3: (float (*const)[2])v139, a4: a8, a5: a9, a6: a10);
        v98 = v161;
        v99 = v145;
        for ( kk = 3; kk != 0; --kk )
        {
          BldClrRmp(a1: v98, a2: v99, a3: a6);
          v99 += 2;
          v98 += 16;
        }
        return sub_4F0A40(a1: a4, a2: v161, a3: a5, a4: a6, a5: v120[0], a6: a7);
      }
    }
    v33 = 255.0;
LABEL_28:
    v140 = v33;
    v125 = v122;
    goto LABEL_30;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F7210
// Name: void CompressRGBBlockXSSE2(float (__near * const)[2],float (__near * const)[4],float __near * const,int,unsigned char,bool,unsigned char,float __near *,unsigned char,unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CompressRGBBlockXSSE2(
        __m128 a1@<xmm2>,
        float (*const a2)[2],
        float (*const a3)[4],
        __m128 *a4,
        int a5,
        unsigned __int8 a6,
        bool a7,
        unsigned __int8 a8,
        float *a9,
        char a10,
        char a11,
        char a12)
{
  __m128 *v12; // esi
  float *v13; // ecx
  float *v14; // eax
  int v15; // esi
  double v16; // st6
  int v17; // ecx
  float *v18; // edx
  double v19; // st7
  double v20; // st6
  double v21; // st5
  double v22; // st4
  double v23; // st3
  double v24; // st2
  double v25; // st5
  double v26; // st0
  double v27; // st7
  double v28; // st6
  double v29; // st5
  int v30; // ecx
  double v31; // st4
  double v32; // st3
  double v33; // st3
  double v34; // st2
  double v35; // st1
  char *v36; // edx
  int *v37; // eax
  int v38; // esi
  double v39; // st0
  int v40; // edi
  double v41; // st1
  float *v42; // eax
  double v43; // st5
  double v44; // st5
  double v45; // rt1
  double v46; // st6
  double v47; // st7
  int v48; // esi
  double v49; // st6
  bool v50; // zf
  int v51; // ecx
  double v52; // rt1
  __m128 v53; // xmm0
  __m128 v54; // xmm1
  __m128 v55; // xmm3
  __m128 v56; // xmm4
  int v57; // eax
  int v58; // ecx
  float *v59; // eax
  double v60; // st5
  int v61; // esi
  double v62; // st5
  int v63; // eax
  double v64; // st7
  double v65; // st6
  double v66; // st5
  double v67; // st4
  double v68; // st3
  double v69; // st1
  float v70; // [esp+0h] [ebp-E04h]
  float v71; // [esp+2Ch] [ebp-DD8h]
  float v72; // [esp+2Ch] [ebp-DD8h]
  float v73; // [esp+2Ch] [ebp-DD8h]
  float v74; // [esp+2Ch] [ebp-DD8h]
  float v75; // [esp+2Ch] [ebp-DD8h]
  float v76; // [esp+2Ch] [ebp-DD8h]
  float v77; // [esp+30h] [ebp-DD4h]
  float v78; // [esp+30h] [ebp-DD4h]
  _BYTE *v79; // [esp+30h] [ebp-DD4h]
  float v80; // [esp+30h] [ebp-DD4h]
  int v81; // [esp+30h] [ebp-DD4h]
  float v82; // [esp+30h] [ebp-DD4h]
  char v83; // [esp+37h] [ebp-DCDh] BYREF
  __m128 *v84; // [esp+38h] [ebp-DCCh]
  double v85; // [esp+3Ch] [ebp-DC8h]
  int v86; // [esp+48h] [ebp-DBCh]
  float v87; // [esp+4Ch] [ebp-DB8h]
  float v88; // [esp+50h] [ebp-DB4h]
  int v89; // [esp+54h] [ebp-DB0h]
  float v90; // [esp+58h] [ebp-DACh]
  float v91; // [esp+5Ch] [ebp-DA8h]
  float i; // [esp+70h] [ebp-D94h]
  unsigned int v93; // [esp+74h] [ebp-D90h]
  float v94; // [esp+78h] [ebp-D8Ch]
  double v95; // [esp+7Ch] [ebp-D88h]
  float v96; // [esp+84h] [ebp-D80h]
  float v97; // [esp+88h] [ebp-D7Ch]
  float v98; // [esp+8Ch] [ebp-D78h]
  float *v99; // [esp+90h] [ebp-D74h]
  double v100; // [esp+94h] [ebp-D70h]
  float v101; // [esp+A0h] [ebp-D64h]
  float *v102; // [esp+A4h] [ebp-D60h]
  int v103; // [esp+A8h] [ebp-D5Ch] BYREF
  float v104; // [esp+ACh] [ebp-D58h]
  float v105; // [esp+B0h] [ebp-D54h]
  float v106[5]; // [esp+B4h] [ebp-D50h]
  float v107; // [esp+C8h] [ebp-D3Ch]
  float v108; // [esp+CCh] [ebp-D38h]
  int v109; // [esp+D0h] [ebp-D34h]
  int v110; // [esp+D4h] [ebp-D30h] BYREF
  float v111; // [esp+D8h] [ebp-D2Ch]
  float v112; // [esp+DCh] [ebp-D28h]
  unsigned int v113; // [esp+F4h] [ebp-D10h]
  float v114; // [esp+F8h] [ebp-D0Ch]
  double v115; // [esp+FCh] [ebp-D08h]
  float v116[64]; // [esp+104h] [ebp-D00h] BYREF
  _BYTE v117[256]; // [esp+204h] [ebp-C00h] BYREF
  float v118[64]; // [esp+304h] [ebp-B00h] BYREF
  float v119[64]; // [esp+404h] [ebp-A00h] BYREF
  float v120[64]; // [esp+504h] [ebp-900h] BYREF
  float v121; // [esp+604h] [ebp-800h] BYREF
  char v122; // [esp+608h] [ebp-7FCh] BYREF
  float v123; // [esp+A04h] [ebp-400h] BYREF
  char v124; // [esp+A08h] [ebp-3FCh] BYREF

  v12 = a4;
  v99 = (float *)a2;
  v84 = a4;
  v102 = a9;
  if ( a5 > 0 )
  {
    v13 = (float *)&v122;
    v14 = &(*a3)[2];
    v15 = a5;
    do
    {
      v13 += 4;
      v16 = *(v14 - 2) / 255.0;
      v14 += 4;
      --v15;
      *(v13 - 5) = v16;
      *(v13 - 4) = *(v14 - 5) / 255.0;
      *(float *)((char *)v14 + (char *)&v121 - (char *)a3 - 16) = *(v14 - 4) / 255.0;
    }
    while ( v15 != 0 );
    v12 = v84;
  }
  v109 = (a5 + 3) / 4;
  if ( a5 <= 2
    || (v83 = 1,
        sub_4F2FB0(
          a1: (float *)&v103,
          a2: &v123,
          a3: (float *)&v110,
          a4: (bool *)&v83,
          a5: &v121,
          a6: (int)v12,
          a7: 3,
          a8: a5),
        v83 != 0) )
  {
    v103 = SLODWORD((*a3)[0]);
    v104 = (*a3)[4 * a5 - 4];
    v105 = (*a3)[1];
    v106[0] = (*a3)[4 * a5 - 3];
    v106[1] = (*a3)[2];
    v106[2] = (*a3)[4 * a5 - 2];
  }
  else
  {
    v101 = 10000000.0;
    v89 = v110;
    v90 = v111;
    v91 = v112;
    while ( 1 )
    {
      v87 = 1000.0;
      memset(v119, 0, sizeof(v119));
      v88 = -1000.0;
      memset(v116, 0, sizeof(v116));
      memset(v120, 0, sizeof(v120));
      memset(v117, 0, sizeof(v117));
      v17 = 0;
      v18 = &v123;
      v19 = v90;
      v20 = *(float *)&v89;
      v95 = *(float *)&v89;
      v21 = v91;
      v85 = v91;
      while ( 1 )
      {
        v22 = v18[1];
        v23 = *v18;
        v24 = v20 * v23 + v19 * v22 + v21 * v18[2];
        v25 = v18[2];
        v77 = v24;
        v116[v17] = v77;
        v119[v17] = v77;
        v26 = v25;
        v21 = v85;
        v120[v17] = (v26 - v77 * v85) * (v26 - v77 * v85)
                  + (v22 - v77 * v19) * (v22 - v77 * v19)
                  + (v23 - v20 * v77) * (v23 - v20 * v77);
        if ( v87 >= (double)v77 )
          v87 = v24;
        if ( v88 <= (double)v77 )
          v88 = v24;
        ++v17;
        v18 += 4;
        if ( v17 >= a5 )
          break;
        v20 = v95;
      }
      v27 = 1.0;
      v28 = 0.0;
      v29 = v88;
      v30 = 0;
      v31 = v87;
      v32 = (v88 - v87) * 0.125;
      v107 = v87 - v32;
      v108 = v32 + v88;
      v33 = v107;
      v100 = v107;
      v115 = v108 - v107;
      *(float *)&v85 = v115 * v115;
      v78 = 1.0 / v115;
      v34 = v78;
      if ( a5 >= 4 )
      {
        v35 = *(float *)&v85;
        v36 = (char *)((char *)v116 - (char *)v12);
        v37 = &v12->m128_i32[2];
        v79 = (_BYTE *)(v117 - (_BYTE *)v12);
        v38 = (char *)&v116[1] - (char *)v84;
        v86 = &v117[4] - (_BYTE *)v84;
        do
        {
          v39 = v116[v30] - v33;
          v30 += 4;
          v37 += 4;
          *((float *)&v113 + v30) = v39 * v34;
          v116[v30 + 60] = *((float *)v37 - 6) * v35;
          *(&v114 + v30) = (*(&v114 + v30) - v33) * v34;
          v116[v30 + 61] = *((float *)v37 - 5) * v35;
          *(float *)((char *)v37 + (_DWORD)v36 - 16) = (*(float *)((char *)v37 + (_DWORD)v36 - 16) - v33) * v34;
          *(float *)((char *)v37 + (_DWORD)v79 - 16) = *((float *)v37 - 4) * v35;
          v40 = v86;
          *(float *)((char *)v37 + v38 - 16) = (*(float *)((char *)v37 + v38 - 16) - v33) * v34;
          *(float *)((char *)v37 + v40 - 16) = *((float *)v37 - 3) * v35;
        }
        while ( v30 < a5 - 3 );
        v12 = v84;
        v28 = 0.0;
      }
      if ( v30 < a5 )
      {
        v41 = *(float *)&v85;
        do
        {
          v42 = &v116[v30++];
          *v42 = (*v42 - v33) * v34;
          v116[v30 + 63] = *(float *)((char *)v42 + (char *)v12 - (char *)v116) * v41;
        }
        while ( v30 < a5 );
        v28 = 0.0;
      }
      v87 = (v31 - v33) * v34;
      v88 = (v29 - v33) * v34;
      *(float *)&v85 = 128000.0;
      v43 = v87 - 0.05000000074505806;
      if ( v43 <= 0.0 )
        v43 = 0.0;
      v80 = v43;
      v44 = v88 + 0.05000000074505806;
      if ( v44 < 1.0 )
        v27 = v44;
      v45 = v28;
      v46 = v27;
      v47 = v45;
      v48 = 8;
      *(float *)&v95 = v46;
      v49 = v80;
      v81 = 8;
      *(float *)&v86 = v49;
      for ( i = *(float *)&v95; ; i = *(float *)&v95 )
      {
        while ( 1 )
        {
          v70 = v47;
          sub_4F0FF0(a1: v70, a2: *(float *)&v86, a3: i, a4: a5, a5: a6);
          v71 = v47;
          if ( *(float *)&v85 > (double)v71 )
          {
            *(float *)&v85 = v47;
            v93 = v86;
            v94 = i;
          }
          --v48;
          i = i - 0.02500000037252903;
          if ( v48 == 0 )
            break;
          v47 = 0.0;
        }
        v50 = v81-- == 1;
        *(float *)&v86 = *(float *)&v86 + 0.02500000037252903;
        if ( v50 )
          break;
        v47 = 0.0;
        v48 = 8;
      }
      *(float *)&v93 = *(float *)&v93 * v115 + v100;
      v94 = v100 + v115 * v94;
      if ( v101 <= *(float *)&v85 + 0.001 )
        break;
      v101 = *(float *)&v85;
      v110 = v89;
      v51 = v109;
      v111 = v90;
      v112 = v91;
      v113 = v93;
      v114 = v94;
      v52 = (double)(a6 - 1);
      v72 = (v94 - *(float *)&v93) / v52;
      v73 = 1.0 / v72;
      v82 = 1.0 / v52;
      *(float *)&v95 = v52 * 0.5;
      if ( v109 > 0 )
      {
        a1.m128_f32[0] = (float)(a6 - 1);
        v53 = _mm_shuffle_ps((__m128)v93, (__m128)v93, 0);
        v54 = _mm_shuffle_ps((__m128)LODWORD(v73), (__m128)LODWORD(v73), 0);
        v55 = _mm_shuffle_ps((__m128)LODWORD(v95), (__m128)LODWORD(v95), 0);
        v56 = _mm_shuffle_ps((__m128)LODWORD(v82), (__m128)LODWORD(v82), 0);
        a1 = _mm_shuffle_ps(a1, a1, 0);
        v57 = 0;
        do
        {
          *(__m128 *)&v118[v57] = _mm_mul_ps(
                                    _mm_sub_ps(
                                      _mm_min_ps(
                                        _mm_max_ps(
                                          _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_mul_ps(_mm_sub_ps(*(__m128 *)&v119[v57], v53), v54))),
                                          (__m128)0LL),
                                        a1),
                                      v55),
                                    v56);
          v57 += 4;
          --v51;
        }
        while ( v51 != 0 );
      }
      v58 = 0;
      *(float *)&v85 = 0.0;
      v98 = 0.0;
      v97 = 0.0;
      v96 = 0.0;
      v59 = (float *)&v124;
      do
      {
        v60 = v118[v58];
        v61 = (char *)v84 - (char *)v118 + 4 * v58++;
        v59 += 4;
        v74 = *(float *)((char *)v118 + v61) * v60;
        *(float *)&v85 = v60 * v74 + *(float *)&v85;
        v96 = *(v59 - 5) * v74 + v96;
        v97 = *(v59 - 4) * v74 + v97;
        v98 = v74 * *(v59 - 3) + v98;
      }
      while ( v58 < a5 );
      v91 = 0.0;
      v90 = 0.0;
      *(float *)&v89 = 0.0;
      v62 = *(float *)&v85;
      if ( *(float *)&v85 > 0.0 )
      {
        *(float *)&v89 = v96 / v62;
        v90 = v97 / v62;
        v91 = v98 / v62;
        v100 = v90;
        v95 = *(float *)&v89;
        v85 = v91;
        v75 = v90 * v90 + *(float *)&v89 * *(float *)&v89 + v91 * v91;
        v76 = sqrt(v75);
        *(float *)&v89 = *(float *)&v89 / v76;
        v90 = v90 / v76;
        v91 = v91 / v76;
      }
      v12 = v84;
    }
    v63 = 0;
    v64 = *(float *)&v110;
    v65 = *(float *)&v103;
    v66 = v111;
    v67 = v104;
    v68 = v112;
    v100 = v105;
    do
    {
      v69 = *(float *)((char *)&v113 + v63 * 4);
      *(float *)&(&v102)[++v63] = (v64 * v69 + v65) * 255.0;
      *(float *)((char *)&v104 + v63 * 4) = (v66 * v69 + v67) * 255.0;
      v106[v63] = (v69 * v68 + v100) * 255.0;
    }
    while ( v63 < 2 );
  }
  sub_4F25D0(a1: (int)&v110, a2: (int)&v103, a3: 0.0, a4: 255.0, a5: a11, a6: a12);
  if ( a7 )
    sub_4F66F0(a1: (int)v99, a2: (int)&v110, (int)a3, a4: v84, a5, a6, a7: v102, a8: a10, a9: a11, a10: a12, a11: a8);
  else
    sub_4F5360(a1: v99, a2: (int)&v110, (int)a3, a4: v84, a5, a6, a7: v102, a8: a10, a9: a11, a10: a12, a11: a8);
}

//------------------------------------------------------------------------------
// Address: 0x004F7B00
// Name: sub_4F7B00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_4F7B00(
        float *a1,
        int a2,
        float *a3,
        int a4,
        unsigned __int8 a5,
        char a6,
        unsigned __int8 a7,
        float *a8,
        char a9,
        __int64 a10)
{
  float *v10; // ecx
  int v11; // eax
  int v12; // edi
  double v13; // st6
  int v14; // ecx
  double v15; // st7
  float *v16; // edx
  double v17; // st6
  double v18; // st5
  double v19; // st4
  double v20; // st3
  double v21; // st2
  double v22; // st5
  double v23; // st0
  double v24; // st7
  int v25; // ecx
  double v26; // st6
  double v27; // st5
  double v28; // st5
  double v29; // st4
  double v30; // st3
  float *v31; // eax
  double v32; // st0
  int v33; // edi
  float *v34; // eax
  double v35; // st7
  double v36; // st7
  int v37; // esi
  double v38; // st7
  int v39; // edi
  int v40; // edi
  double v41; // st6
  double v42; // st7
  double v43; // st5
  double v44; // st4
  int v45; // ecx
  float *v46; // eax
  double v47; // st6
  int v48; // esi
  double v49; // st7
  int v50; // eax
  double v51; // st7
  double v52; // st6
  double v53; // st5
  double v54; // st4
  double v55; // st3
  double v56; // st1
  float v57; // [esp+0h] [ebp-DE0h]
  float v58; // [esp+1Ch] [ebp-DC4h]
  float v59; // [esp+1Ch] [ebp-DC4h]
  float v60; // [esp+1Ch] [ebp-DC4h]
  float v61; // [esp+1Ch] [ebp-DC4h]
  float v62; // [esp+1Ch] [ebp-DC4h]
  float v63; // [esp+1Ch] [ebp-DC4h]
  float v64; // [esp+1Ch] [ebp-DC4h]
  float v65; // [esp+1Ch] [ebp-DC4h]
  float v66; // [esp+1Ch] [ebp-DC4h]
  int v67; // [esp+20h] [ebp-DC0h]
  float v68; // [esp+20h] [ebp-DC0h]
  float v69; // [esp+20h] [ebp-DC0h]
  float v70; // [esp+20h] [ebp-DC0h]
  float v71; // [esp+20h] [ebp-DC0h]
  char v72; // [esp+27h] [ebp-DB9h] BYREF
  double v73; // [esp+28h] [ebp-DB8h]
  float v74; // [esp+34h] [ebp-DACh]
  float v75; // [esp+38h] [ebp-DA8h]
  float v76; // [esp+3Ch] [ebp-DA4h]
  int v77; // [esp+40h] [ebp-DA0h]
  float v78; // [esp+44h] [ebp-D9Ch]
  float v79; // [esp+48h] [ebp-D98h]
  double v80; // [esp+50h] [ebp-D90h]
  float v81; // [esp+58h] [ebp-D88h]
  float v82; // [esp+5Ch] [ebp-D84h]
  float v83; // [esp+60h] [ebp-D80h]
  float v84; // [esp+64h] [ebp-D7Ch]
  float v85; // [esp+68h] [ebp-D78h]
  int v86; // [esp+6Ch] [ebp-D74h]
  double v87; // [esp+70h] [ebp-D70h]
  float v88; // [esp+7Ch] [ebp-D64h]
  int v89; // [esp+80h] [ebp-D60h] BYREF
  float v90; // [esp+84h] [ebp-D5Ch]
  float v91; // [esp+88h] [ebp-D58h]
  float v92[5]; // [esp+8Ch] [ebp-D54h]
  double v93; // [esp+A0h] [ebp-D40h]
  float v94; // [esp+A8h] [ebp-D38h]
  float v95; // [esp+ACh] [ebp-D34h]
  double v96; // [esp+B0h] [ebp-D30h]
  int v97; // [esp+B8h] [ebp-D28h] BYREF
  float v98; // [esp+BCh] [ebp-D24h]
  float v99; // [esp+C0h] [ebp-D20h]
  float v100[2]; // [esp+D0h] [ebp-D10h]
  float v101[2]; // [esp+D8h] [ebp-D08h]
  int v102[64]; // [esp+E0h] [ebp-D00h] BYREF
  float v103[64]; // [esp+1E0h] [ebp-C00h] BYREF
  int v104[128]; // [esp+2E0h] [ebp-B00h] BYREF
  float v105[64]; // [esp+4E0h] [ebp-900h] BYREF
  float v106; // [esp+5E0h] [ebp-800h] BYREF
  char v107; // [esp+5E4h] [ebp-7FCh] BYREF
  float v108; // [esp+9E0h] [ebp-400h] BYREF
  char v109; // [esp+9E4h] [ebp-3FCh] BYREF

  if ( a4 > 0 )
  {
    v10 = (float *)&v107;
    v11 = a2 + 8;
    v12 = a4;
    do
    {
      v10 += 4;
      v13 = *(float *)(v11 - 8) / 255.0;
      v11 += 16;
      --v12;
      *(v10 - 5) = v13;
      *(v10 - 4) = *(float *)(v11 - 20) / 255.0;
      *(float *)((char *)&v106 + v11 - a2 - 16) = *(float *)(v11 - 16) / 255.0;
    }
    while ( v12 != 0 );
  }
  if ( a4 <= 2
    || (v72 = 1,
        sub_4F2FB0(
          a1: (float *)&v89,
          a2: &v108,
          a3: (float *)&v97,
          a4: (bool *)&v72,
          a5: &v106,
          a6: (int)a3,
          a7: 3,
          a8: a4),
        v72 != 0) )
  {
    v89 = *(int *)a2;
    v90 = *(float *)(a2 + 16 * a4 - 16);
    v91 = *(float *)(a2 + 4);
    v92[0] = *(float *)(a2 + 16 * a4 - 12);
    v92[1] = *(float *)(a2 + 8);
    v92[2] = *(float *)(a2 + 16 * a4 - 8);
  }
  else
  {
    v88 = 10000000.0;
    v86 = a5;
    v77 = v97;
    v78 = v98;
    v79 = v99;
    while ( 1 )
    {
      v75 = 1000.0;
      v76 = -1000.0;
      memset(v102, 0, sizeof(v102));
      memset(v105, 0, sizeof(v105));
      memset(v104, 0, sizeof(v104));
      v14 = 0;
      v15 = v78;
      v16 = &v108;
      v17 = *(float *)&v77;
      v80 = *(float *)&v77;
      v18 = v79;
      v73 = v79;
      while ( 1 )
      {
        v19 = v16[1];
        v20 = *v16;
        v21 = v17 * v20 + v15 * v19 + v18 * v16[2];
        v22 = v16[2];
        *(float *)&v67 = v21;
        v102[v14] = v67;
        v104[v14 + 64] = v67;
        v23 = v22;
        v18 = v73;
        v105[v14] = (v23 - *(float *)&v67 * v73) * (v23 - *(float *)&v67 * v73)
                  + (v19 - *(float *)&v67 * v15) * (v19 - *(float *)&v67 * v15)
                  + (v20 - v17 * *(float *)&v67) * (v20 - v17 * *(float *)&v67);
        if ( v75 >= (double)*(float *)&v67 )
          v75 = v21;
        if ( v76 <= (double)*(float *)&v67 )
          v76 = v21;
        ++v14;
        v16 += 4;
        if ( v14 >= a4 )
          break;
        v17 = v80;
      }
      v24 = v76;
      v25 = 0;
      v26 = v75;
      v27 = (v76 - v75) * 0.125;
      v94 = v75 - v27;
      v95 = v27 + v76;
      v28 = v94;
      v96 = v94;
      v93 = v95 - v94;
      v68 = v93 * v93;
      *(float *)&v73 = 1.0 / v93;
      v29 = v68;
      v30 = *(float *)&v73;
      if ( a4 >= 4 )
      {
        v31 = a3 + 2;
        LODWORD(v73) = (char *)&v104[1] - (char *)a3;
        do
        {
          v32 = *(float *)&v102[v25] - v28;
          v25 += 4;
          v31 += 4;
          v100[v25] = v32 * v30;
          v103[v25 + 60] = *(v31 - 6) * v29;
          v100[v25 + 1] = (v100[v25 + 1] - v28) * v30;
          v103[v25 + 61] = *(v31 - 5) * v29;
          *(float *)((char *)v31 + (char *)v102 - (char *)a3 - 16) = (*(float *)((char *)v31
                                                                               + (char *)v102
                                                                               - (char *)a3
                                                                               - 16)
                                                                    - v28)
                                                                   * v30;
          *(float *)((char *)v31 + (char *)v104 - (char *)a3 - 16) = *(v31 - 4) * v29;
          v33 = LODWORD(v73);
          *(float *)((char *)v31 + (char *)&v102[1] - (char *)a3 - 16) = (*(float *)((char *)v31
                                                                                   + (char *)&v102[1]
                                                                                   - (char *)a3
                                                                                   - 16)
                                                                        - v28)
                                                                       * v30;
          *(float *)((char *)v31 + v33 - 16) = *(v31 - 3) * v29;
        }
        while ( v25 < a4 - 3 );
      }
      for ( ; v25 < a4; v103[v25 + 63] = *(float *)((char *)v34 + (char *)a3 - (char *)v102) * v29 )
      {
        v34 = (float *)&v102[v25++];
        *v34 = (*v34 - v28) * v30;
      }
      v75 = (v26 - v28) * v30;
      v76 = (v24 - v28) * v30;
      v74 = 128000.0;
      v35 = v75 - 0.05000000074505806;
      if ( v35 <= 0.0 )
        v35 = 0.0;
      v69 = v35;
      v36 = v76 + 0.05000000074505806;
      if ( v36 >= 1.0 )
        v36 = 1.0;
      *(float *)&v80 = v36;
      v37 = 8;
      v38 = v74;
      do
      {
        v39 = 8;
        *(float *)&v73 = *(float *)&v80;
        do
        {
          v57 = v38;
          v58 = sub_4F2E40(
                  a1: v86,
                  a2: (int)v105,
                  a3: (float *)v102,
                  a4: (int)v104,
                  a5: v57,
                  a6: v69,
                  a7: *(float *)&v73,
                  a8: a4);
          if ( v74 <= (double)v58 )
          {
            v38 = v74;
          }
          else
          {
            v74 = v58;
            v84 = v69;
            v85 = *(float *)&v73;
            v38 = v58;
          }
          --v39;
          *(float *)&v73 = *(float *)&v73 - 0.02500000037252903;
        }
        while ( v39 != 0 );
        --v37;
        v69 = v69 + 0.02500000037252903;
      }
      while ( v37 != 0 );
      v84 = v84 * v93 + v96;
      v85 = v96 + v93 * v85;
      if ( v88 <= v38 + 0.001 )
        break;
      v88 = v38;
      v97 = v77;
      v40 = 0;
      v98 = v78;
      v99 = v79;
      v101[0] = v84;
      v101[1] = v85;
      v96 = v85;
      v41 = v84;
      v42 = v85;
      v93 = v84;
      v70 = (float)(v86 - 1);
      v59 = (v85 - v84) / v70;
      *(float *)&v73 = v59 * 0.5;
      v74 = 1.0 / v59;
      *(float *)&v80 = 1.0 / v70;
      v60 = v70 * 0.5;
      v87 = v60;
      v80 = *(float *)&v80;
      v43 = 0.0;
      do
      {
        v61 = *(float *)&v104[v40 + 64] - v41;
        if ( v61 > v43 )
        {
          if ( *(float *)&v104[v40 + 64] - v42 < 0.0 )
          {
            v62 = (v61 + *(float *)&v73) * v74;
            v63 = floor(X: v62);
            v103[v40] = v63;
            v41 = v93;
            v43 = 0.0;
            v42 = v96;
          }
          else
          {
            v103[v40] = v70;
          }
        }
        else
        {
          v103[v40] = v43;
        }
        v44 = v103[v40++];
        *(float *)&v102[v40 + 63] = (v44 - v87) * v80;
      }
      while ( v40 < a4 );
      v71 = v43;
      v45 = 0;
      v83 = v71;
      v82 = v71;
      v81 = v71;
      v46 = (float *)&v109;
      do
      {
        v47 = v103[v45];
        v48 = (char *)a3 - (char *)v103 + 4 * v45++;
        v46 += 4;
        v64 = *(float *)((char *)v103 + v48) * v47;
        v71 = v47 * v64 + v71;
        v81 = *(v46 - 5) * v64 + v81;
        v82 = *(v46 - 4) * v64 + v82;
        v83 = v64 * *(v46 - 3) + v83;
      }
      while ( v45 < a4 );
      v79 = v43;
      v78 = v43;
      *(float *)&v77 = v43;
      v49 = v71;
      if ( v71 > v43 )
      {
        *(float *)&v77 = v81 / v49;
        v78 = v82 / v49;
        v79 = v83 / v49;
        v87 = v78;
        v80 = *(float *)&v77;
        v73 = v79;
        v65 = v78 * v78 + *(float *)&v77 * *(float *)&v77 + v79 * v79;
        v66 = sqrt(v65);
        *(float *)&v77 = *(float *)&v77 / v66;
        v78 = v78 / v66;
        v79 = v79 / v66;
      }
    }
    v50 = 0;
    v51 = *(float *)&v97;
    v52 = *(float *)&v89;
    v53 = v98;
    v54 = v90;
    v55 = v99;
    v87 = v91;
    do
    {
      v56 = v101[v50++];
      *(float *)((char *)&v88 + v50 * 4) = (v56 * v51 + v52) * 255.0;
      *(float *)((char *)&v90 + v50 * 4) = (v56 * v53 + v54) * 255.0;
      v92[v50] = (v56 * v55 + v87) * 255.0;
    }
    while ( v50 < 2 );
  }
  sub_4F25D0(a1: (int)&v97, a2: (int)&v89, a3: 0.0, a4: 255.0, a5: a10, a6: SBYTE4(a10));
  if ( a6 != 0 )
    sub_4F4910(
      (int)a1,
      a2: (int)&v97,
      a3: (_DWORD *)a2,
      a4: a3,
      a5: a4,
      a6: a5,
      a7: a8,
      a8: a9,
      a9: a10,
      a10: SBYTE4(a10),
      a11: a7);
  else
    sub_4F36A0(
      a1,
      a2: (int)&v97,
      a3: (_DWORD *)a2,
      a4: a3,
      a5: a4,
      a6: a5,
      a7: a8,
      a8: a9,
      a9: a10,
      a10: SBYTE4(a10),
      a11: a7);
}

//------------------------------------------------------------------------------
// Address: 0x004F83D0
// Name: float CompRGBBlock(float __near *,unsigned short,unsigned char,unsigned char,unsigned char,unsigned char (__near * const)[2],unsigned char __near *,unsigned char,bool,bool,unsigned char,float __near *,bool,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall CompRGBBlock@<st0>(
        __m128 a1@<xmm2>,
        float *a2,
        unsigned __int16 a3,
        char a4,
        __int64 a5,
        unsigned __int8 (*const a6)[2],
        unsigned __int8 *a7,
        char a8,
        bool a9,
        bool a10,
        unsigned __int8 a11,
        float *a12,
        int a13,
        float a14)
{
  double v14; // st7
  unsigned int v15; // eax
  unsigned int v16; // esi
  unsigned int v17; // edi
  float *v18; // ecx
  float *v19; // ebx
  float *v20; // edi
  float *v21; // esi
  float *p_base; // edx
  float *v23; // edx
  float *v24; // ecx
  double v26; // st7
  int v27; // ecx
  double v28; // st6
  float *v29; // ebx
  int *v30; // edi
  double v31; // rt0
  unsigned int v32; // eax
  int *v33; // ecx
  float *v34; // edx
  int v35; // esi
  unsigned int v36; // eax
  unsigned __int8 *v37; // ecx
  unsigned __int8 *v38; // edx
  unsigned int v39; // eax
  unsigned __int8 *v40; // ecx
  unsigned __int8 *v41; // edx
  unsigned __int8 *v42; // ecx
  unsigned __int8 *v43; // edx
  int v44; // eax
  double v45; // rt1
  double v46; // st6
  double v47; // st7
  int v48; // ecx
  int v49; // edx
  int v50; // eax
  int v51; // ecx
  int v52; // edx
  float v53; // ecx
  float v54; // edx
  float v55; // ecx
  float v56; // edx
  double v57; // rt2
  int v58; // ecx
  float *v59; // eax
  int v60; // edx
  double v61; // st6
  unsigned __int8 *v62; // esi
  float *v63; // edx
  int i; // edi
  int j; // ecx
  double v66; // st7
  int v67; // ebx
  float *v68; // ecx
  float *v69; // eax
  double v70; // st5
  unsigned int v71; // [esp+1Ch] [ebp-934h]
  float *v72; // [esp+1Ch] [ebp-934h]
  unsigned int v73; // [esp+20h] [ebp-930h]
  unsigned int v74; // [esp+20h] [ebp-930h]
  int v75; // [esp+20h] [ebp-930h]
  int v76; // [esp+24h] [ebp-92Ch]
  unsigned int v77; // [esp+24h] [ebp-92Ch]
  __m128 *p_dst; // [esp+2Ch] [ebp-924h]
  float v79[2]; // [esp+30h] [ebp-920h] BYREF
  float v80; // [esp+38h] [ebp-918h]
  float v81; // [esp+3Ch] [ebp-914h]
  __m128 dst; // [esp+50h] [ebp-900h] BYREF
  float base; // [esp+150h] [ebp-800h] BYREF
  float v84; // [esp+154h] [ebp-7FCh] BYREF
  float v85; // [esp+158h] [ebp-7F8h] BYREF
  float v86; // [esp+15Ch] [ebp-7F4h] BYREF
  int v87[252]; // [esp+160h] [ebp-7F0h] BYREF
  float v88[256]; // [esp+550h] [ebp-400h] BYREF

  memset((unsigned __int8 *)&dst, value: 0, count: 0x100u);
  memset(dst: (unsigned __int8 *)v88, value: 0, count: sizeof(v88));
  v14 = a14;
  v15 = a3;
  v16 = 0;
  v17 = 0;
  v71 = 0;
  if ( a3 >= 4u )
  {
    v73 = (((unsigned int)a3 - 4) >> 2) + 1;
    v18 = a2 + 2;
    v19 = &v86;
    v20 = &v85;
    v21 = &v84;
    p_base = &base;
    v76 = 4 * v73;
    do
    {
      if ( (_BYTE)a13 == 0 || v18[1] >= v14 )
      {
        ++v71;
        *p_base = *v18;
        p_base += 4;
        v21 += 4;
        *(v21 - 4) = *(v18 - 1);
        v20 += 4;
        v19 += 4;
        *(v20 - 4) = *(v18 - 2);
        *(v19 - 4) = 0.0;
      }
      if ( (_BYTE)a13 == 0 || v18[5] >= v14 )
      {
        ++v71;
        *p_base = v18[4];
        p_base += 4;
        v21 += 4;
        *(v21 - 4) = v18[3];
        v20 += 4;
        v19 += 4;
        *(v20 - 4) = v18[2];
        *(v19 - 4) = 0.0;
      }
      if ( (_BYTE)a13 == 0 || v18[9] >= v14 )
      {
        ++v71;
        *p_base = v18[8];
        p_base += 4;
        v21 += 4;
        *(v21 - 4) = v18[7];
        v20 += 4;
        v19 += 4;
        *(v20 - 4) = v18[6];
        *(v19 - 4) = 0.0;
      }
      if ( (_BYTE)a13 == 0 || v18[13] >= v14 )
      {
        ++v71;
        *p_base = v18[12];
        p_base += 4;
        v21 += 4;
        *(v21 - 4) = v18[11];
        v20 += 4;
        v19 += 4;
        *(v20 - 4) = v18[10];
        *(v19 - 4) = 0.0;
      }
      v18 += 16;
      --v73;
    }
    while ( v73 != 0 );
    v16 = v71;
    v17 = v76;
    v15 = a3;
  }
  if ( v17 < v15 )
  {
    v23 = &a2[4 * v17 + 2];
    v24 = &v84 + 4 * v16;
    v74 = v15 - v17;
    do
    {
      if ( (_BYTE)a13 == 0 || (v15 = a3, v23[1] >= v14) )
      {
        ++v16;
        *(v24 - 1) = *v23;
        v24 += 4;
        *(v24 - 4) = *(v23 - 1);
        *(v24 - 3) = *(v23 - 2);
        *(v24 - 2) = 0.0;
      }
      v23 += 4;
      --v74;
    }
    while ( v74 != 0 );
  }
  if ( v16 == 0 )
  {
    (*a6)[5] = -1;
    (*a6)[3] = -1;
    (*a6)[1] = -1;
    (*a6)[4] = 0;
    (*a6)[2] = 0;
    (*a6)[0] = 0;
    memset(dst: a7, value: 0xFFu, count: v15);
    return 0.0;
  }
  if ( v16 != v15 && (_BYTE)a13 != 0 && (a8 & 1) == 0 )
    return 3.4028235e38;
  qsort(&base, num: v16, width: 0x10u, comp: sub_4F09D0);
  v26 = 1.0;
  dst.m128_f32[0] = 1.0;
  v27 = 0;
  v75 = 0;
  v88[0] = base;
  v88[1] = v84;
  v88[2] = v85;
  v88[3] = v86;
  v79[0] = base;
  v79[1] = v84;
  v80 = v85;
  v81 = v86;
  if ( v16 > 1 )
  {
    v28 = 1.0;
    v29 = v88;
    p_dst = &dst;
    v30 = v87;
    v72 = v88;
    v77 = v16 - 1;
    while ( 2 )
    {
      v32 = 16;
      v33 = v30;
      v34 = v79;
      do
      {
        if ( *(_DWORD *)v34 != *v33 )
          goto LABEL_35;
        v32 -= 4;
        ++v33;
        ++v34;
      }
      while ( v32 >= 4 );
      if ( v32 != 0 )
      {
LABEL_35:
        v35 = *(unsigned __int8 *)v34 - *(unsigned __int8 *)v33;
        if ( v35 != 0 )
          goto LABEL_42;
        v36 = v32 - 1;
        v37 = (unsigned __int8 *)v33 + 1;
        v38 = (unsigned __int8 *)v34 + 1;
        if ( v36 != 0 )
        {
          v35 = *v38 - *v37;
          if ( v35 != 0
            || (v39 = v36 - 1, v40 = v37 + 1, v41 = v38 + 1, v39 != 0)
            && ((v35 = *v41 - *v40) != 0 || (v42 = v40 + 1, v43 = v41 + 1, v39 != 1) && (v35 = *v43 - *v42) != 0) )
          {
LABEL_42:
            v29 = v72;
            v44 = 1;
            if ( v35 <= 0 )
              v44 = -1;
LABEL_46:
            if ( v44 != 0 )
            {
              v45 = v28;
              v46 = v26;
              v47 = v45;
              v48 = *v30;
              v49 = v30[1];
              v50 = v75 + 1;
              v29 += 4;
              dst.m128_f32[v50] = v46;
              *(_DWORD *)v29 = v48;
              v51 = v30[2];
              *((_DWORD *)v29 + 1) = v49;
              v52 = v30[3];
              *((_DWORD *)v29 + 2) = v51;
              v53 = *(float *)v30;
              *((_DWORD *)v29 + 3) = v52;
              v54 = *((float *)v30 + 1);
              ++v75;
              v79[0] = v53;
              v55 = *((float *)v30 + 2);
              v79[1] = v54;
              v56 = *((float *)v30 + 3);
              v72 = v29;
              v80 = v55;
              v81 = v56;
              p_dst = (__m128 *)((char *)&dst + 4 * v50);
            }
            else
            {
              p_dst->m128_f32[0] = p_dst->m128_f32[0] + v28;
              v57 = v28;
              v46 = v26;
              v47 = v57;
            }
            v30 += 4;
            if ( --v77 != 0 )
            {
              v31 = v46;
              v28 = v47;
              v26 = v31;
              continue;
            }
            v27 = v75;
            goto LABEL_51;
          }
        }
        v29 = v72;
      }
      break;
    }
    v44 = 0;
    goto LABEL_46;
  }
LABEL_51:
  v58 = v27 + 1;
  if ( v58 != 0 )
  {
    v59 = &v88[1];
    v60 = v58;
    do
    {
      v61 = *(v59 - 1);
      v59 += 4;
      --v60;
      *(v59 - 5) = v61 * 255.0;
      *(v59 - 4) = *(v59 - 4) * 255.0;
      *(v59 - 3) = *(v59 - 3) * 255.0;
      *(v59 - 2) = *(v59 - 2) * 255.0;
    }
    while ( v60 != 0 );
  }
  if ( a9 )
    CompressRGBBlockXSSE2(
      a1,
      a2: (float (*const)[2])v79,
      a3: (float (*const)[4])v88,
      a4: &dst,
      a5: v58,
      a6: a8,
      a7: a10,
      a8: a11,
      a9: a12,
      a10: a4,
      a11: a5,
      a12: SBYTE4(a5));
  else
    sub_4F7B00(a1: v79, a2: (int)v88, a3: dst.m128_f32, a4: v58, a5: a8, a6: a10, a7: a11, a8: a12, a9: a4, a10: a5);
  v62 = (unsigned __int8 *)a6;
  v63 = v79;
  for ( i = 3; i != 0; --i )
  {
    for ( j = 0; j < 2; v62[j - 1] = (int)v66 )
    {
      v66 = *v63;
      ++j;
      ++v63;
    }
    v62 += 2;
  }
  v67 = a3;
  if ( a3 != 0 )
  {
    v68 = &base;
    v69 = a2 + 1;
    do
    {
      v68 += 4;
      v70 = v69[1] * 255.0;
      v69 += 4;
      --v67;
      *(v68 - 4) = v70;
      *(float *)((char *)v69 + (char *)&base - (char *)a2 - 16) = *(v69 - 4) * 255.0;
      *(float *)((char *)v69 + (char *)&v84 - (char *)a2 - 16) = *(v69 - 5) * 255.0;
      *(float *)((char *)v69 + (char *)&v85 - (char *)a2 - 16) = 0.0;
    }
    while ( v67 != 0 );
  }
  return Clstr(a1: &base, a2: a3, a3: a6, a4: a7, a5: a8, a6: a12, a7: a13, a8: a14, a9: a4, a10: a5, a11: BYTE4(a5));
}

//------------------------------------------------------------------------------
// Address: 0x004F8950
// Name: float CompRGBBlock(unsigned long __near *,unsigned short,unsigned char,unsigned char,unsigned char,unsigned char (__near * const)[2],unsigned char __near *,unsigned char,bool,bool,unsigned char,float __near *,bool,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall CompRGBBlock@<st0>(
        __m128 a1@<xmm2>,
        unsigned int *a2,
        unsigned __int16 a3,
        char a4,
        __int64 a5,
        unsigned __int8 (*const a6)[2],
        unsigned __int8 *a7,
        char a8,
        bool a9,
        bool a10,
        unsigned __int8 a11,
        float *a12,
        int a13,
        unsigned __int8 a14)
{
  unsigned int v14; // ebx
  unsigned int v15; // eax
  double v17; // st7
  int v18; // edx
  double v19; // st6
  int v20; // eax
  unsigned int v21; // edi
  __m128 *p_dst; // ecx
  int v23; // esi
  double v24; // rt0
  double v25; // st6
  double v26; // st7
  double v27; // rt1
  int v28; // esi
  int v29; // esi
  int v30; // esi
  double v31; // rt2
  bool v32; // zf
  unsigned int v33; // eax
  unsigned int v34; // ecx
  float *v35; // edx
  int v36; // esi
  double v37; // rtt
  int v38; // ecx
  double v39; // rt0
  double v40; // st6
  double v41; // st7
  double v42; // rt1
  unsigned __int8 *v43; // esi
  float *v44; // edx
  int i; // edi
  int j; // ecx
  double v47; // st7
  int v48; // [esp+18h] [ebp-728h]
  float v49[8]; // [esp+20h] [ebp-720h] BYREF
  __m128 dst; // [esp+40h] [ebp-700h] BYREF
  _DWORD v51[64]; // [esp+140h] [ebp-600h]
  _DWORD base[64]; // [esp+240h] [ebp-500h] BYREF
  float v53[256]; // [esp+340h] [ebp-400h] BYREF

  memset((unsigned __int8 *)&dst, value: 0, count: 0x100u);
  memset(dst: (unsigned __int8 *)v53, value: 0, count: sizeof(v53));
  v14 = 0;
  v15 = 0;
  if ( a3 == 0 )
    goto LABEL_44;
  do
  {
    if ( (_BYTE)a13 == 0 || (a2[v15] & 0xFF000000) >= a14 << 24 )
      base[v14++] = a2[v15] | 0xFF000000;
    ++v15;
  }
  while ( v15 < a3 );
  if ( v14 != 0 )
  {
    if ( v14 == a3 || (_BYTE)a13 == 0 || (a8 & 1) != 0 )
    {
      qsort(base, num: v14, width: 4u, comp: sub_4F09C0);
      v17 = 1.0;
      v18 = base[0];
      dst.m128_f32[0] = 1.0;
      v19 = 1.0;
      v20 = 0;
      v51[0] = base[0];
      v21 = 1;
      if ( (int)(v14 - 1) >= 4 )
      {
        p_dst = &dst;
        do
        {
          v23 = base[v21];
          if ( v18 == v23 )
          {
            p_dst->m128_f32[0] = p_dst->m128_f32[0] + v19;
            v27 = v19;
            v25 = v17;
            v26 = v27;
          }
          else
          {
            ++v20;
            v24 = v19;
            v25 = v17;
            v26 = v24;
            p_dst = (__m128 *)((char *)&dst + 4 * v20);
            p_dst->m128_f32[0] = v25;
            v51[v20] = v23;
            v18 = v23;
          }
          v28 = base[v21 + 1];
          if ( v18 == v28 )
          {
            p_dst->m128_f32[0] = p_dst->m128_f32[0] + v26;
          }
          else
          {
            ++v20;
            p_dst = (__m128 *)((char *)&dst + 4 * v20);
            p_dst->m128_f32[0] = v25;
            v51[v20] = v28;
            v18 = v28;
          }
          v29 = base[v21 + 2];
          if ( v18 == v29 )
          {
            p_dst->m128_f32[0] = p_dst->m128_f32[0] + v26;
          }
          else
          {
            ++v20;
            p_dst = (__m128 *)((char *)&dst + 4 * v20);
            p_dst->m128_f32[0] = v25;
            v51[v20] = v29;
            v18 = v29;
          }
          v30 = base[v21 + 3];
          if ( v18 == v30 )
          {
            p_dst->m128_f32[0] = p_dst->m128_f32[0] + v26;
          }
          else
          {
            ++v20;
            p_dst = (__m128 *)((char *)&dst + 4 * v20);
            p_dst->m128_f32[0] = v25;
            v51[v20] = v30;
            v18 = v30;
          }
          v21 += 4;
          v31 = v25;
          v19 = v26;
          v17 = v31;
        }
        while ( v21 < v14 - 3 );
      }
      if ( v21 < v14 )
      {
        while ( 1 )
        {
          v38 = base[v21];
          if ( v18 == v38 )
          {
            dst.m128_f32[v20] = dst.m128_f32[v20] + v19;
            v42 = v19;
            v40 = v17;
            v41 = v42;
          }
          else
          {
            ++v20;
            v39 = v19;
            v40 = v17;
            v41 = v39;
            dst.m128_f32[v20] = v40;
            v51[v20] = v38;
            v18 = v38;
          }
          if ( ++v21 >= v14 )
            break;
          v37 = v40;
          v19 = v41;
          v17 = v37;
        }
      }
      v32 = v20 == -1;
      v33 = v20 + 1;
      v34 = 0;
      if ( !v32 )
      {
        v35 = &v53[1];
        do
        {
          v48 = BYTE1(v51[v34]);
          v36 = LOBYTE(v51[v34]);
          v35[1] = (float)BYTE2(v51[v34++]);
          *v35 = (float)v48;
          v35 += 4;
          *(v35 - 5) = (float)v36;
          *(v35 - 2) = 255.0;
        }
        while ( v34 < v33 );
      }
      if ( a9 )
        CompressRGBBlockXSSE2(
          a1,
          a2: (float (*const)[2])v49,
          a3: (float (*const)[4])v53,
          a4: &dst,
          a5: v33,
          a6: a8,
          a7: a10,
          a8: a11,
          a9: a12,
          a10: a4,
          a11: a5,
          a12: SBYTE4(a5));
      else
        sub_4F7B00(a1: v49, a2: (int)v53, a3: dst.m128_f32, a4: v33, a5: a8, a6: a10, a7: a11, a8: a12, a9: a4, a10: a5);
      v43 = (unsigned __int8 *)a6;
      v44 = v49;
      for ( i = 3; i != 0; --i )
      {
        for ( j = 0; j < 2; v43[j - 1] = (int)v47 )
        {
          v47 = *v44;
          ++j;
          ++v44;
        }
        v43 += 2;
      }
      return Clstr(a1: a2, a2: a3, a3: a6, a4: a7, a5: a8, a6: a12, a7: a13, a8: a14, a9: a4, a10: a5, a11: BYTE4(a5));
    }
    else
    {
      return 3.4028235e38;
    }
  }
  else
  {
LABEL_44:
    (*a6)[4] = 0;
    (*a6)[2] = 0;
    (*a6)[0] = 0;
    (*a6)[5] = -1;
    (*a6)[3] = -1;
    (*a6)[1] = -1;
    memset(dst: a7, value: 0xFFu, count: a3);
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F8C90
// Name: void MkWkRmpPts(bool __near *,float (__near * const)[2],float (__near * const)[2],unsigned char,unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl MkWkRmpPts(bool *a1, float (*const a2)[2], float (*const a3)[2], char a4, char a5, char a6)
{
  float *v6; // esi
  int i; // edi
  int v8; // ebx
  double v9; // st7
  double v10; // st7
  float v11; // [esp+20h] [ebp-28h]
  float v12; // [esp+20h] [ebp-28h]
  float v13; // [esp+20h] [ebp-28h]
  float v14; // [esp+20h] [ebp-28h]
  float v15; // [esp+20h] [ebp-28h]
  double v16; // [esp+28h] [ebp-20h]
  double v17; // [esp+30h] [ebp-18h]
  float v18[3]; // [esp+3Ch] [ebp-Ch]

  v18[2] = (float)(1 << a4);
  *a1 = true;
  v18[1] = (float)(1 << a5);
  v18[0] = (float)(1 << a6);
  *a1 = (*a3)[1] == (*a3)[0];
  *a1 &= (*a3)[3] == (*a3)[2];
  v6 = (float *)a2;
  *a1 &= (*a3)[5] == (*a3)[4];
  for ( i = 0; i < 3; ++i )
  {
    v8 = 2;
    v16 = v18[i];
    do
    {
      v17 = *(float *)((char *)v6 + (char *)a3 - (char *)a2);
      v11 = v17 / v16;
      v12 = floor(X: v11);
      v13 = v12 + v17;
      *v6 = v13;
      v9 = 0.0;
      if ( v13 > 0.0 )
        v9 = v13;
      v14 = v9;
      v10 = v14;
      *v6 = v14;
      if ( v14 >= 255.0 )
        v10 = 255.0;
      v15 = v10;
      ++v6;
      --v8;
      *(v6 - 1) = v15;
    }
    while ( v8 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F8DF0
// Name: void BldClrRmp(float __near * const,float __near * const,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl BldClrRmp(float *const a1, float *const a2, unsigned __int8 a3)
{
  float *v3; // ecx
  int v4; // esi
  int v5; // [esp+34h] [ebp-14h]
  int v6; // [esp+38h] [ebp-10h]
  float v7; // [esp+38h] [ebp-10h]
  float v8; // [esp+38h] [ebp-10h]
  float v9; // [esp+44h] [ebp-4h]

  v3 = &a1[a3 - 1];
  *a1 = *a2;
  *v3 = a2[1];
  if ( (a3 & 1) != 0 )
    a1[a3] = 1000000.0;
  v4 = 1;
  v6 = 1;
  if ( a3 - 1 > 1 )
  {
    v5 = a3 - 2;
    while ( 1 )
    {
      v9 = (float)(a3 - 1);
      v7 = ((double)v6 * *v3 + (double)v5 * *a1 + (double)dwRndAmount[a3]) / v9;
      v8 = floor(X: v7);
      --v5;
      a1[v4++] = v8;
      v6 = v4;
      if ( v4 >= a3 - 1 )
        break;
      v3 = &a1[a3 - 1];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0067CDD0
// Name: _dynamic_initializer_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransform_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransform_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067CDE0
// Name: _dynamic_initializer_for__g_CDmeTransform_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransform_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransform_Helper,
           classname: "DmeTransform",
           pFactory: &g_CDmeTransform_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00681D70
// Name: _dynamic_atexit_destructor_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransform_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTransform_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104E13E0
// Name: public: virtual void CDmeTransform::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTransform::OnAttributeChanged(
        CDmeTransform *this@<ecx>,
        DmAttributeReferenceIterator_t a2@<edi>,
        CDmAttribute *pAttribute)
{
  DmElementHandle_t BufferType; // eax

  BufferType = CCodecBuffer_Block::GetBufferType((CExpressionCalculator *)this);
  InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: BufferType, pChangedAttr: pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x104E1400
// Name: public: void CDmeTransform::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetPosition(CDmeTransform *this, const Vector *vecPosition)
{
  CDmAttribute::SetValue<Vector>(this: this->m_Position.m_pAttribute, value: vecPosition);
}

//------------------------------------------------------------------------------
// Address: 0x104E1410
// Name: public: void CDmeTransform::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetOrientation(CDmeTransform *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_Orientation.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x104E1420
// Name: public: class CDmAttribute __near * CDmeTransform::GetOrientationAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTransform::GetOrientationAttribute(CDmeTransform *this)
{
  return this->m_Orientation.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x104E1430
// Name: public: void CDmeTransform::GetTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::GetTransform(CDmeTransform *this, matrix3x4_t *transform)
{
  QuaternionMatrix(q: &this->m_Orientation.m_Storage, pos: &this->m_Position.m_Storage, matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x104E1450
// Name: public: class CDmeDag __near * CDmeTransform::GetDag(void)
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeTransform::GetDag(CDmeTransform *this)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx

  if ( (_S1_52 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_52 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symTransform, a3: "transform");
  }
  return FindReferringElement<CDmeDag>(
           pElement: (CExpressionCalculator *)this,
           symAttrName: symTransform,
           bMustBeInSameFile: true,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x104E1530
// Name: public: virtual bool CDmeTransform::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransform::IsA(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x104E1560
// Name: public: virtual int CDmeTransform::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransform::GetInheritanceDepth(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x104E1630
// Name: protected: virtual void CDmeTransform::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::PerformConstruction(CDmeTransform *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax

  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "position", type: AT_VECTOR3, pMemory: &this->m_Position);
  this->m_Position.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "orientation",
         type: AT_QUATERNION,
         pMemory: &this->m_Orientation);
  this->m_Orientation.m_pAttribute = v3;
  v3->m_nFlags |= 0x100u;
}

//------------------------------------------------------------------------------
// Address: 0x104EAD70
// Name: public: class Vector const __near & CDmeTransform::GetPosition(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmeTransform::GetPosition(CDmeTransform *this)
{
  return &this->m_Position;
}

//------------------------------------------------------------------------------
// Address: 0x105C79D0
// Name: _dynamic_initializer_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransform::s_Allocator,
    blockSize: 0x68u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransform pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CD0B0
// Name: _dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransform::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C7A00
// Name: _dynamic_initializer_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransform_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransform_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C7A10
// Name: _dynamic_initializer_for__g_CDmeTransform_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransform_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransform_Helper,
           classname: "DmeTransform",
           pFactory: &g_CDmeTransform_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CD0C0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransform_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeTransform_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004AE5E0
// Name: public: virtual void CDmeTransform::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTransform::OnAttributeChanged(CDmeTransform *this@<ecx>, int a2@<edi>, CDmAttribute *pAttribute)
{
  DmElementHandle_t Handle; // eax

  Handle = CDmElement::GetHandle(this);
  InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: Handle, pChangedAttr: pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x004AE600
// Name: public: void CDmeTransform::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetPosition(CDmeTransform *this, const Vector *vecPosition)
{
  CDmAttribute::SetValue<Vector>(this: this->m_Position.m_pAttribute, value: vecPosition);
}

//------------------------------------------------------------------------------
// Address: 0x004AE610
// Name: public: void CDmeTransform::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetOrientation(CDmeTransform *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_Orientation.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x004AE620
// Name: public: void CDmeTransform::GetTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::GetTransform(CDmeTransform *this, matrix3x4_t *transform)
{
  QuaternionMatrix(q: &this->m_Orientation.m_Storage, pos: &this->m_Position.m_Storage, matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x004AE640
// Name: public: class Vector const __near & CDmeTransform::GetPosition(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmeTransform::GetPosition(CDmeTransform *this)
{
  return &this->m_Position;
}

//------------------------------------------------------------------------------
// Address: 0x004AE650
// Name: public: class Quaternion const __near & CDmeTransform::GetOrientation(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmeTransform::GetOrientation(CDmeTransform *this)
{
  return &this->m_Orientation;
}

//------------------------------------------------------------------------------
// Address: 0x004AE6F0
// Name: public: virtual bool CDmeTransform::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransform::IsA(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AE720
// Name: public: virtual int CDmeTransform::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransform::GetInheritanceDepth(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004AE7F0
// Name: protected: virtual void CDmeTransform::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::PerformConstruction(CDmeTransform *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax

  CDmeFXClip::OnDestruction();
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "position", type: AT_VECTOR3, pMemory: &this->m_Position);
  this->m_Position.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "orientation",
         type: AT_QUATERNION,
         pMemory: &this->m_Orientation);
  this->m_Orientation.m_pAttribute = v3;
  v3->m_nFlags |= 0x100u;
}

//------------------------------------------------------------------------------
// Address: 0x0059A7C0
// Name: _dynamic_initializer_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransform::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransform pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059EA40
// Name: _dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransform::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059A7F0
// Name: _dynamic_initializer_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransform_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransform_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A800
// Name: _dynamic_initializer_for__g_CDmeTransform_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransform_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransform_Helper,
           classname: "DmeTransform",
           pFactory: &g_CDmeTransform_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059EA50
// Name: _dynamic_atexit_destructor_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransform_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransform_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004F4D00
// Name: public: virtual void CDmeTransform::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTransform::OnAttributeChanged(CDmeTransform *this@<ecx>, int a2@<edi>, CDmAttribute *pAttribute)
{
  DmElementHandle_t v3; // eax

  v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
  InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: v3, pChangedAttr: pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x004F4D20
// Name: public: void CDmeTransform::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetPosition(CDmeTransform *this, const Vector *vecPosition)
{
  CDmAttribute::SetValue<Vector>(this: this->m_Position.m_pAttribute, value: vecPosition);
}

//------------------------------------------------------------------------------
// Address: 0x004F4D30
// Name: public: void CDmeTransform::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetOrientation(CDmeTransform *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_Orientation.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x004F4D40
// Name: public: void CDmeTransform::GetTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::GetTransform(CDmeTransform *this, matrix3x4_t *transform)
{
  QuaternionMatrix(q: &this->m_Orientation.m_Storage, pos: &this->m_Position.m_Storage, matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x004F4D60
// Name: public: class Vector const __near & CDmeTransform::GetPosition(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmeTransform::GetPosition(CDmeTransform *this)
{
  return &this->m_Position;
}

//------------------------------------------------------------------------------
// Address: 0x004F4D70
// Name: public: class Quaternion const __near & CDmeTransform::GetOrientation(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmeTransform::GetOrientation(CDmeTransform *this)
{
  return &this->m_Orientation;
}

//------------------------------------------------------------------------------
// Address: 0x004F4E10
// Name: public: virtual bool CDmeTransform::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransform::IsA(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F4E40
// Name: public: virtual int CDmeTransform::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransform::GetInheritanceDepth(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F4F10
// Name: protected: virtual void CDmeTransform::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::PerformConstruction(CDmeTransform *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax

  CDmeFXClip::OnDestruction();
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "position", type: AT_VECTOR3, pMemory: &this->m_Position);
  this->m_Position.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "orientation",
         type: AT_QUATERNION,
         pMemory: &this->m_Orientation);
  this->m_Orientation.m_pAttribute = v3;
  v3->m_nFlags |= 0x100u;
}

//------------------------------------------------------------------------------
// Address: 0x005EF3A0
// Name: _dynamic_initializer_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransform::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransform pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3D10
// Name: _dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransform::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EF3D0
// Name: _dynamic_initializer_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransform_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransform_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF3E0
// Name: _dynamic_initializer_for__g_CDmeTransform_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransform_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransform_Helper,
           classname: "DmeTransform",
           pFactory: &g_CDmeTransform_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3D20
// Name: _dynamic_atexit_destructor_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransform_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransform_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00466250
// Name: public: virtual void CDmeTransform::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTransform::OnAttributeChanged(
        CDmeTransform *this@<ecx>,
        DmAttributeReferenceIterator_t a2@<edi>,
        CDmAttribute *pAttribute)
{
  DmElementHandle_t v3; // eax

  v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
  InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: v3, pChangedAttr: pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x00466270
// Name: public: void CDmeTransform::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetPosition(CDmeTransform *this, const Vector *vecPosition)
{
  CDmAttribute::SetValue<Vector>(this: this->m_Position.m_pAttribute, value: vecPosition);
}

//------------------------------------------------------------------------------
// Address: 0x00466280
// Name: public: void CDmeTransform::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetOrientation(CDmeTransform *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_Orientation.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x004662A0
// Name: public: class CDmAttribute __near * CDmeTransform::GetOrientationAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTransform::GetOrientationAttribute(CDmeTransform *this)
{
  return this->m_Orientation.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x00466360
// Name: public: void CDmeTransform::GetTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::GetTransform(CDmeTransform *this, matrix3x4_t *transform)
{
  QuaternionMatrix(q: &this->m_Orientation.m_Storage, pos: &this->m_Position.m_Storage, matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x00466380
// Name: public: class Vector const __near & CDmeTransform::GetPosition(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmeTransform::GetPosition(CDmeTransform *this)
{
  return &this->m_Position;
}

//------------------------------------------------------------------------------
// Address: 0x00466390
// Name: public: class Quaternion const __near & CDmeTransform::GetOrientation(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmeTransform::GetOrientation(CDmeTransform *this)
{
  return &this->m_Orientation;
}

//------------------------------------------------------------------------------
// Address: 0x004664C0
// Name: public: virtual bool CDmeTransform::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransform::IsA(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004664F0
// Name: public: virtual int CDmeTransform::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransform::GetInheritanceDepth(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004665C0
// Name: protected: virtual void CDmeTransform::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::PerformConstruction(CDmeTransform *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax

  CDmeFXClip::OnDestruction();
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "position", type: AT_VECTOR3, pMemory: &this->m_Position);
  this->m_Position.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "orientation",
         type: AT_QUATERNION,
         pMemory: &this->m_Orientation);
  this->m_Orientation.m_pAttribute = v3;
  v3->m_nFlags |= 0x100u;
}

//------------------------------------------------------------------------------
// Address: 0x00569980
// Name: _dynamic_initializer_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransform::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransform pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056DF40
// Name: _dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransform::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004663A0
// Name: class CDmeDag __near * FindReferringElement<class CDmeDag>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDag *__cdecl FindReferringElement<CDmeDag>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeDag *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005699B0
// Name: _dynamic_initializer_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransform_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransform_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005699C0
// Name: _dynamic_initializer_for__g_CDmeTransform_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransform_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransform_Helper,
           classname: "DmeTransform",
           pFactory: &g_CDmeTransform_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056DF50
// Name: _dynamic_atexit_destructor_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransform_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransform_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00469650
// Name: public: virtual void CDmeTransform::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTransform::OnAttributeChanged(
        CDmeTransform *this@<ecx>,
        DmAttributeReferenceIterator_t a2@<edi>,
        CDmAttribute *pAttribute)
{
  DmElementHandle_t v3; // eax

  v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
  InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: v3, pChangedAttr: pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x00469670
// Name: public: void CDmeTransform::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetPosition(CDmeTransform *this, const Vector *vecPosition)
{
  CDmAttribute::SetValue<Vector>(this: this->m_Position.m_pAttribute, value: vecPosition);
}

//------------------------------------------------------------------------------
// Address: 0x00469680
// Name: public: void CDmeTransform::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetOrientation(CDmeTransform *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_Orientation.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x00469750
// Name: public: void CDmeTransform::GetTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::GetTransform(CDmeTransform *this, matrix3x4_t *transform)
{
  QuaternionMatrix(q: &this->m_Orientation.m_Storage, pos: &this->m_Position.m_Storage, matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x00469780
// Name: public: class Quaternion const __near & CDmeTransform::GetOrientation(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmeTransform::GetOrientation(CDmeTransform *this)
{
  return &this->m_Orientation;
}

//------------------------------------------------------------------------------
// Address: 0x00469820
// Name: public: class CDmeDag __near * CDmeTransform::GetDag(void)
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeTransform::GetDag(CDmeTransform *this)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx

  if ( (_S1_2 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_2 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symTransform, a3: "transform");
  }
  return FindReferringElement<CDmeDag>(
           pElement: this,
           symAttrName: symTransform,
           bMustBeInSameFile: true,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x00469900
// Name: public: virtual bool CDmeTransform::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransform::IsA(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00469930
// Name: public: virtual int CDmeTransform::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransform::GetInheritanceDepth(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00469A00
// Name: protected: virtual void CDmeTransform::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::PerformConstruction(CDmeTransform *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax

  CDmeFXClip::OnDestruction();
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "position", type: AT_VECTOR3, pMemory: &this->m_Position);
  this->m_Position.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "orientation",
         type: AT_QUATERNION,
         pMemory: &this->m_Orientation);
  this->m_Orientation.m_pAttribute = v3;
  v3->m_nFlags |= 0x100u;
}

//------------------------------------------------------------------------------
// Address: 0x00579A80
// Name: _dynamic_initializer_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransform::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransform pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E070
// Name: _dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransform::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00469790
// Name: class CDmeDag __near * FindReferringElement<class CDmeDag>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDag *__cdecl FindReferringElement<CDmeDag>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeDag *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00579AB0
// Name: _dynamic_initializer_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransform_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransform_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579AC0
// Name: _dynamic_initializer_for__g_CDmeTransform_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransform_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransform_Helper,
           classname: "DmeTransform",
           pFactory: &g_CDmeTransform_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E080
// Name: _dynamic_atexit_destructor_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransform_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransform_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005CDDF0
// Name: public: virtual void CDmeTransform::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTransform::OnAttributeChanged(CDmeTransform *this@<ecx>, int a2@<edi>, CDmAttribute *pAttribute)
{
  DmElementHandle_t BufferType; // eax

  BufferType = CCodecBuffer_Block::GetBufferType((CExpressionCalculator *)this);
  InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: BufferType, pChangedAttr: pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x005CDE10
// Name: public: void CDmeTransform::SetTransform(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetTransform(CDmeTransform *this, const matrix3x4_t *transform)
{
  Quaternion angles; // [esp+4h] [ebp-1Ch] BYREF
  Vector origin; // [esp+14h] [ebp-Ch] BYREF

  MatrixAngles(matrix: transform, q: &angles, pos: &origin);
  CDmAttribute::SetValue<Quaternion>(this: this->m_Orientation.m_pAttribute, value: &angles);
  CDmAttribute::SetValue<Vector>(this: this->m_Position.m_pAttribute, value: &origin);
}

//------------------------------------------------------------------------------
// Address: 0x005CDE50
// Name: public: void CDmeTransform::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetPosition(CDmeTransform *this, const Vector *vecPosition)
{
  CDmAttribute::SetValue<Vector>(this: this->m_Position.m_pAttribute, value: vecPosition);
}

//------------------------------------------------------------------------------
// Address: 0x005CDE60
// Name: public: void CDmeTransform::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetOrientation(CDmeTransform *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_Orientation.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x005CDE70
// Name: public: void CDmeTransform::GetTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::GetTransform(CDmeTransform *this, matrix3x4_t *transform)
{
  QuaternionMatrix(q: &this->m_Orientation.m_Storage, pos: &this->m_Position.m_Storage, matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x005CDE90
// Name: public: class Vector const __near & CDmeTransform::GetPosition(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmeTransform::GetPosition(CDmeTransform *this)
{
  return &this->m_Position;
}

//------------------------------------------------------------------------------
// Address: 0x005CDEA0
// Name: public: class CDmeDag __near * CDmeTransform::GetDag(void)
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeTransform::GetDag(CDmeTransform *this)
{
  void (__thiscall *v2)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *); // edx

  if ( (_S1_8 & 1) == 0 )
  {
    v2 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
    _S1_8 |= 1u;
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v2)(
      a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
      a2: &symTransform,
      a3: "transform");
  }
  return FindReferringElement<CDmeDag>(
           pElement: (CExpressionCalculator *)this,
           symAttrName: symTransform,
           bMustBeInSameFile: true,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x005CDF80
// Name: public: virtual bool CDmeTransform::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransform::IsA(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005CDFB0
// Name: public: virtual int CDmeTransform::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransform::GetInheritanceDepth(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005CE080
// Name: protected: virtual void CDmeTransform::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::PerformConstruction(CDmeTransform *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "position", type: AT_VECTOR3, pMemory: &this->m_Position);
  this->m_Position.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "orientation",
         type: AT_QUATERNION,
         pMemory: &this->m_Orientation);
  this->m_Orientation.m_pAttribute = v3;
  v3->m_nFlags |= 0x100u;
}

//------------------------------------------------------------------------------
// Address: 0x006B0230
// Name: _dynamic_initializer_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransform::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransform pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4FB0
// Name: _dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransform::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B0260
// Name: _dynamic_initializer_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransform_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransform_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0270
// Name: _dynamic_initializer_for__g_CDmeTransform_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransform_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransform_Helper,
           classname: "DmeTransform",
           pFactory: &g_CDmeTransform_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B4FC0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransform_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTransform_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0046A220
// Name: public: virtual void CDmeTransform::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTransform::OnAttributeChanged(
        CDmeTransform *this@<ecx>,
        DmAttributeReferenceIterator_t a2@<edi>,
        CDmAttribute *pAttribute)
{
  DmElementHandle_t v3; // eax

  v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
  InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: v3, pChangedAttr: pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x0046A240
// Name: public: void CDmeTransform::SetTransform(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetTransform(CDmeTransform *this, const matrix3x4_t *transform)
{
  Quaternion angles; // [esp+4h] [ebp-1Ch] BYREF
  Vector origin; // [esp+14h] [ebp-Ch] BYREF

  MatrixAngles(matrix: transform, q: &angles, pos: &origin);
  CDmAttribute::SetValue<Quaternion>(this: this->m_Orientation.m_pAttribute, value: &angles);
  CDmAttribute::SetValue<Vector>(this: this->m_Position.m_pAttribute, value: &origin);
}

//------------------------------------------------------------------------------
// Address: 0x0046A280
// Name: public: void CDmeTransform::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetPosition(CDmeTransform *this, const Vector *vecPosition)
{
  CDmAttribute::SetValue<Vector>(this: this->m_Position.m_pAttribute, value: vecPosition);
}

//------------------------------------------------------------------------------
// Address: 0x0046A290
// Name: public: void CDmeTransform::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetOrientation(CDmeTransform *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_Orientation.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x0046A360
// Name: public: void CDmeTransform::GetTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::GetTransform(CDmeTransform *this, matrix3x4_t *transform)
{
  QuaternionMatrix(q: &this->m_Orientation.m_Storage, pos: &this->m_Position.m_Storage, matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x0046A380
// Name: public: class Quaternion const __near & CDmeTransform::GetOrientation(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmeTransform::GetOrientation(CDmeTransform *this)
{
  return &this->m_Orientation;
}

//------------------------------------------------------------------------------
// Address: 0x0046A420
// Name: public: class CDmeDag __near * CDmeTransform::GetDag(void)
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeTransform::GetDag(CDmeTransform *this)
{
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx

  if ( (_S1_2 & 1) == 0 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_2 |= 1u;
    GetSymbol(this: g_pDataModel, result: &symTransform, a3: "transform");
  }
  return FindReferringElement<CDmeDag>(
           pElement: this,
           symAttrName: symTransform,
           bMustBeInSameFile: true,
           depth: TD_ALL);
}

//------------------------------------------------------------------------------
// Address: 0x0046A500
// Name: public: virtual bool CDmeTransform::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransform::IsA(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046A530
// Name: public: virtual int CDmeTransform::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransform::GetInheritanceDepth(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046A600
// Name: protected: virtual void CDmeTransform::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::PerformConstruction(CDmeTransform *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax

  CDmeFXClip::OnDestruction();
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "position", type: AT_VECTOR3, pMemory: &this->m_Position);
  this->m_Position.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "orientation",
         type: AT_QUATERNION,
         pMemory: &this->m_Orientation);
  this->m_Orientation.m_pAttribute = v3;
  v3->m_nFlags |= 0x100u;
}

//------------------------------------------------------------------------------
// Address: 0x0057BA70
// Name: _dynamic_initializer_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransform::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransform pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580050
// Name: _dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransform::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0046A390
// Name: class CDmeDag __near * FindReferringElement<class CDmeDag>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDag *__cdecl FindReferringElement<CDmeDag>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeDag *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057BAA0
// Name: _dynamic_initializer_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransform_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransform_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BAB0
// Name: _dynamic_initializer_for__g_CDmeTransform_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransform_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransform_Helper,
           classname: "DmeTransform",
           pFactory: &g_CDmeTransform_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580060
// Name: _dynamic_atexit_destructor_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransform_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransform_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004EDD80
// Name: public: virtual void CDmeTransform::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTransform::OnAttributeChanged(CDmeTransform *this@<ecx>, int a2@<edi>, CDmAttribute *pAttribute)
{
  DmElementHandle_t v3; // eax

  v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
  InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: v3, pChangedAttr: pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x004EDDA0
// Name: public: void CDmeTransform::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetPosition(CDmeTransform *this, const Vector *vecPosition)
{
  CDmAttribute::SetValue<Vector>(this: this->m_Position.m_pAttribute, value: vecPosition);
}

//------------------------------------------------------------------------------
// Address: 0x004EDDB0
// Name: public: void CDmeTransform::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetOrientation(CDmeTransform *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_Orientation.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x004EDDE0
// Name: public: void CDmeTransform::GetTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::GetTransform(CDmeTransform *this, matrix3x4_t *transform)
{
  QuaternionMatrix(q: &this->m_Orientation.m_Storage, pos: &this->m_Position.m_Storage, matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x004EDE00
// Name: public: class Vector const __near & CDmeTransform::GetPosition(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmeTransform::GetPosition(CDmeTransform *this)
{
  return &this->m_Position;
}

//------------------------------------------------------------------------------
// Address: 0x004EDE10
// Name: public: class Quaternion const __near & CDmeTransform::GetOrientation(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmeTransform::GetOrientation(CDmeTransform *this)
{
  return &this->m_Orientation;
}

//------------------------------------------------------------------------------
// Address: 0x004EDEB0
// Name: public: virtual bool CDmeTransform::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransform::IsA(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EDEE0
// Name: public: virtual int CDmeTransform::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransform::GetInheritanceDepth(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EDFB0
// Name: protected: virtual void CDmeTransform::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::PerformConstruction(CDmeTransform *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax

  CDmeFXClip::OnDestruction();
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "position", type: AT_VECTOR3, pMemory: &this->m_Position);
  this->m_Position.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "orientation",
         type: AT_QUATERNION,
         pMemory: &this->m_Orientation);
  this->m_Orientation.m_pAttribute = v3;
  v3->m_nFlags |= 0x100u;
}

//------------------------------------------------------------------------------
// Address: 0x005E8240
// Name: _dynamic_initializer_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransform::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransform pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ECBB0
// Name: _dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransform::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E8270
// Name: _dynamic_initializer_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransform_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransform_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8280
// Name: _dynamic_initializer_for__g_CDmeTransform_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransform_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransform_Helper,
           classname: "DmeTransform",
           pFactory: &g_CDmeTransform_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ECBC0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransform_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransform_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0047E4D0
// Name: public: virtual void CDmeTransform::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTransform::OnAttributeChanged(
        CDmeTransform *this@<ecx>,
        DmAttributeReferenceIterator_t a2@<edi>,
        CDmAttribute *pAttribute)
{
  DmElementHandle_t v3; // eax

  v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
  InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: v3, pChangedAttr: pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x0047E4F0
// Name: public: void CDmeTransform::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetPosition(CDmeTransform *this, const Vector *vecPosition)
{
  CDmAttribute::SetValue<Vector>(this: this->m_Position.m_pAttribute, value: vecPosition);
}

//------------------------------------------------------------------------------
// Address: 0x0047E500
// Name: public: void CDmeTransform::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetOrientation(CDmeTransform *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_Orientation.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x0047E510
// Name: public: class CDmAttribute __near * CDmeTransform::GetOrientationAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTransform::GetOrientationAttribute(CDmeTransform *this)
{
  return this->m_Orientation.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x0047E520
// Name: public: void CDmeTransform::GetTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::GetTransform(CDmeTransform *this, matrix3x4_t *transform)
{
  QuaternionMatrix(q: &this->m_Orientation.m_Storage, pos: &this->m_Position.m_Storage, matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x0047E540
// Name: public: class Vector const __near & CDmeTransform::GetPosition(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmeTransform::GetPosition(CDmeTransform *this)
{
  return &this->m_Position;
}

//------------------------------------------------------------------------------
// Address: 0x0047E550
// Name: public: class Quaternion const __near & CDmeTransform::GetOrientation(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmeTransform::GetOrientation(CDmeTransform *this)
{
  return &this->m_Orientation;
}

//------------------------------------------------------------------------------
// Address: 0x0047E5F0
// Name: public: virtual bool CDmeTransform::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransform::IsA(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E620
// Name: public: virtual int CDmeTransform::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransform::GetInheritanceDepth(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047E6F0
// Name: protected: virtual void CDmeTransform::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::PerformConstruction(CDmeTransform *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "position", type: AT_VECTOR3, pMemory: &this->m_Position);
  this->m_Position.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "orientation",
         type: AT_QUATERNION,
         pMemory: &this->m_Orientation);
  this->m_Orientation.m_pAttribute = v3;
  v3->m_nFlags |= 0x100u;
}

//------------------------------------------------------------------------------
// Address: 0x00579690
// Name: _dynamic_initializer_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransform::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransform pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D8F0
// Name: _dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransform::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005796C0
// Name: _dynamic_initializer_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransform_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransform_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005796D0
// Name: _dynamic_initializer_for__g_CDmeTransform_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransform_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransform_Helper,
           classname: "DmeTransform",
           pFactory: &g_CDmeTransform_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057D900
// Name: _dynamic_atexit_destructor_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransform_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransform_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00577430
// Name: public: virtual void CDmeTransform::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTransform::OnAttributeChanged(
        CDmeTransform *this@<ecx>,
        DmAttributeReferenceIterator_t a2@<edi>,
        CDmAttribute *pAttribute)
{
  DmElementHandle_t CenterVertIndex; // eax

  CenterVertIndex = CCoreDispNode::GetCenterVertIndex((CVTFTexture *)this);
  InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: CenterVertIndex, pChangedAttr: pAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x00577450
// Name: public: void CDmeTransform::SetTransform(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetTransform(CDmeTransform *this, const matrix3x4_t *transform)
{
  Quaternion angles; // [esp+4h] [ebp-1Ch] BYREF
  Vector origin; // [esp+14h] [ebp-Ch] BYREF

  MatrixAngles(matrix: transform, q: &angles, pos: &origin);
  CDmAttribute::SetValue<Quaternion>(this: this->m_Orientation.m_pAttribute, value: &angles);
  CDmAttribute::SetValue<Vector>(this: this->m_Position.m_pAttribute, value: &origin);
}

//------------------------------------------------------------------------------
// Address: 0x00577490
// Name: public: void CDmeTransform::SetPosition(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetPosition(CDmeTransform *this, const Vector *vecPosition)
{
  CDmAttribute::SetValue<Vector>(this: this->m_Position.m_pAttribute, value: vecPosition);
}

//------------------------------------------------------------------------------
// Address: 0x005774A0
// Name: public: void CDmeTransform::SetOrientation(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::SetOrientation(CDmeTransform *this, const Quaternion *orientation)
{
  CDmAttribute::SetValue<Quaternion>(this: this->m_Orientation.m_pAttribute, value: orientation);
}

//------------------------------------------------------------------------------
// Address: 0x005774B0
// Name: public: class CDmAttribute __near * CDmeTransform::GetOrientationAttribute(void)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTransform::GetOrientationAttribute(CDmeTransform *this)
{
  return this->m_Orientation.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x00577570
// Name: public: void CDmeTransform::GetTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::GetTransform(CDmeTransform *this, matrix3x4_t *transform)
{
  QuaternionMatrix(q: &this->m_Orientation.m_Storage, pos: &this->m_Position.m_Storage, matrix: transform);
}

//------------------------------------------------------------------------------
// Address: 0x00577590
// Name: public: class Vector const __near & CDmeTransform::GetPosition(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmeTransform::GetPosition(CDmeTransform *this)
{
  return &this->m_Position;
}

//------------------------------------------------------------------------------
// Address: 0x005775A0
// Name: public: class Quaternion const __near & CDmeTransform::GetOrientation(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmeTransform::GetOrientation(CDmeTransform *this)
{
  return &this->m_Orientation;
}

//------------------------------------------------------------------------------
// Address: 0x005776D0
// Name: public: virtual bool CDmeTransform::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTransform::IsA(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00577700
// Name: public: virtual int CDmeTransform::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTransform::GetInheritanceDepth(CDmeTransform *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTransform::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005777D0
// Name: protected: virtual void CDmeTransform::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTransform::PerformConstruction(CDmeTransform *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "position", type: AT_VECTOR3, pMemory: &this->m_Position);
  this->m_Position.m_pAttribute = v2;
  v2->m_nFlags |= 0x100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "orientation",
         type: AT_QUATERNION,
         pMemory: &this->m_Orientation);
  this->m_Orientation.m_pAttribute = v3;
  v3->m_nFlags |= 0x100u;
}

//------------------------------------------------------------------------------
// Address: 0x006B7230
// Name: _dynamic_initializer_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransform::s_Allocator,
    blockSize: 0x68u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransform pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BC560
// Name: _dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransform::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransform::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005775B0
// Name: class CDmeDag __near * FindReferringElement<class CDmeDag>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDag *__cdecl FindReferringElement<CDmeDag>(
        CVTFTexture *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int CenterVertIndex; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t y_low; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeDag *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    CenterVertIndex = CCoreDispNode::GetCenterVertIndex(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)CenterVertIndex);
    y_low = LODWORD(pElement->m_vecReflectivity.y);
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    y_low = DMFILEID_INVALID;
  }
  it.m_fileid = y_low;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeDag>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B7260
// Name: _dynamic_initializer_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransform_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransform_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7270
// Name: _dynamic_initializer_for__g_CDmeTransform_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransform_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransform_Helper,
           classname: "DmeTransform",
           pFactory: &g_CDmeTransform_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BC570
// Name: _dynamic_atexit_destructor_for__g_CDmeTransform_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransform_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTransform_Factory.m_CallBackList);
}

} // namespace vmap
