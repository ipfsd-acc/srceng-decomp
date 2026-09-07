// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapkeyframe.cpp
// Functions: 24
// ============================================================

#include "hammer\mapkeyframe.h"

//------------------------------------------------------------------------------
// Address: 0x1012FEF0
// Name: public: virtual char const __near * CMapKeyFrame::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapKeyFrame::GetType(CMapKeyFrame *this)
{
  return CMapKeyFrame::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1012FF00
// Name: public: virtual int CMapKeyFrame::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapKeyFrame::IsMapClass(CMapKeyFrame *this, const char *Type)
{
  return Type == CMapKeyFrame::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1012FF20
// Name: public: virtual CMapKeyFrame::~CMapKeyFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapKeyFrame::~CMapKeyFrame(CMapKeyFrame *this)
{
  IPositionInterpolator *m_pPositionInterpolator; // ecx

  this->__vftable = (CMapKeyFrame_vtbl *)&CMapKeyFrame::`vftable';
  m_pPositionInterpolator = this->m_pPositionInterpolator;
  if ( m_pPositionInterpolator != nullptr )
    m_pPositionInterpolator->Release(this: m_pPositionInterpolator);
  CMapClass::~CMapClass(this);
}

//------------------------------------------------------------------------------
// Address: 0x1012FF80
// Name: public: virtual unsigned int CMapKeyFrame::GetSize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMapKeyFrame::GetSize(CMapKeyFrame *this)
{
  return 396;
}

//------------------------------------------------------------------------------
// Address: 0x1012FFA0
// Name: public: virtual class CMapClass __near * CMapKeyFrame::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapKeyFrame *__thiscall CMapKeyFrame::CopyFrom(CMapKeyFrame *this, CMapClass *pObj, bool bUpdateDependencies)
{
  char *v4; // eax

  CMapClass::CopyFrom(this, pFrom: (CVisGroup *)pObj, bUpdateDependencies);
  v4 = (char *)__RTDynamicCast(
                 inptr: pObj,
                 VfDelta: 0,
                 SrcType: &CMapClass `RTTI Type Descriptor',
                 TargetType: &CMapKeyFrame `RTTI Type Descriptor',
                 isReference: 0);
  this->m_qAngles = *(Quaternion *)(v4 + 228);
  this->m_Angles = *(QAngle *)(v4 + 244);
  this->m_flSpeed = *((float *)v4 + 65);
  this->m_flMoveTime = *((float *)v4 + 64);
  if ( bUpdateDependencies )
    this->m_pNextKeyFrame = (CMapKeyFrame *)CMapClass::UpdateDependency(
                                              this,
                                              pOldAttached: this->m_pNextKeyFrame,
                                              pNewAttached: *((CMapClass **)v4 + 67));
  else
    this->m_pNextKeyFrame = *((CMapKeyFrame **)v4 + 67);
  this->m_bRebuildPath = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10130080
// Name: public: virtual void CMapKeyFrame::OnClone(class CMapClass __near *,class CMapWorld __near *,class CUtlReferenceVector<class CMapClass> const __near &,class CUtlReferenceVector<class CMapClass> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapKeyFrame::OnClone(
        CMapKeyFrame *this@<ecx>,
        int a2@<ebx>,
        CMapClass *pClone,
        CMapWorld *pWorld,
        const CUtlReferenceVector<CMapClass> *OriginalList,
        CUtlReferenceVector<CMapClass> *NewList)
{
  char *v7; // edi
  void *v8; // eax
  _DWORD *v9; // ebx
  const char *Value; // eax
  const char *v11; // eax
  char newName[128]; // [esp+8h] [ebp-80h] BYREF

  CMapClass::OnClone(this, pNewObj: pClone, pWorld, OriginalList, NewList);
  if ( __RTDynamicCast(
         inptr: pClone,
         VfDelta: 0,
         SrcType: &CMapClass `RTTI Type Descriptor',
         TargetType: &CMapKeyFrame `RTTI Type Descriptor',
         isReference: 0) != nullptr )
  {
    v7 = (char *)__RTDynamicCast(
                   inptr: this->m_pParent,
                   VfDelta: 0,
                   SrcType: &CMapAtom `RTTI Type Descriptor',
                   TargetType: &CMapEntity `RTTI Type Descriptor',
                   isReference: 0);
    v8 = (void *)((int (__thiscall *)(CMapClass *, _DWORD))pClone->GetParent)(a1: pClone, a2: 0);
    v9 = __RTDynamicCast(
           inptr: v8,
           VfDelta: (int)&CMapClass `RTTI Type Descriptor',
           SrcType: &CMapEntity `RTTI Type Descriptor',
           TargetType: nullptr,
           isReference: a2);
    Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
              this: (WCKeyValuesT<WCKVBase_Dict> *)(v7 + 220),
              pszKey: "NextKey",
              piIndex: nullptr);
    if ( Value != nullptr )
      (*(void (__thiscall **)(_DWORD *, const char *, const char *))(v9[54] + 4))(a1: v9 + 54, a2: "NextKey", a3: Value);
    v11 = WCKeyValuesT<WCKVBase_Dict>::GetValue(
            this: (WCKeyValuesT<WCKVBase_Dict> *)(v7 + 220),
            pszKey: "targetname",
            piIndex: nullptr);
    if ( v11 == nullptr || *v11 == 0 )
      v11 = "keyframe";
    CMapWorld::GenerateNewTargetname(
      this: pWorld,
      startName: v11,
      outputName: newName,
      newNameBufferSize: 128,
      bMakeUnique: true,
      szPrefix: nullptr,
      pRoot: nullptr);
    (*(void (__thiscall **)(_DWORD *, const char *))(v9[54] + 4))(a1: v9 + 54, a2: "targetname");
    (*(void (__thiscall **)(char *, const char *, char *))(*((_DWORD *)v7 + 54) + 4))(
      a1: v7 + 216,
      a2: "NextKey",
      a3: newName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101301B0
// Name: public: virtual void CMapKeyFrame::OnRemoveFromWorld(class CMapWorld __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapKeyFrame::OnRemoveFromWorld(CMapKeyFrame *this, CMapWorld *pWorld, bool bNotifyChildren)
{
  CMapClass::OnRemoveFromWorld(this, pWorld, bNotifyChildren);
  this->m_pNextKeyFrame = (CMapKeyFrame *)CMapClass::UpdateDependency(
                                            this,
                                            pOldAttached: this->m_pNextKeyFrame,
                                            pNewAttached: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101301E0
// Name: public: virtual void CMapKeyFrame::GetQuatAngles(class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapKeyFrame::GetQuatAngles(CMapKeyFrame *this, Quaternion *outQuat)
{
  *outQuat = this->m_qAngles;
}

//------------------------------------------------------------------------------
// Address: 0x10130210
// Name: public: virtual void CMapKeyFrame::SetOrigin(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapKeyFrame::SetOrigin(CMapKeyFrame *this, Vector *pfOrigin)
{
  CMapClass::SetOrigin(this, origin: pfOrigin);
  this->m_bRebuildPath = true;
}

//------------------------------------------------------------------------------
// Address: 0x10130230
// Name: public: class CMapKeyFrame __near * CMapKeyFrame::NextKeyFrame(void)
// Source: json
//------------------------------------------------------------------------------
CMapKeyFrame *__thiscall CMapKeyFrame::NextKeyFrame(CMapKeyFrame *this)
{
  CMapKeyFrame *result; // eax

  result = this->m_pNextKeyFrame;
  if ( result == nullptr )
    return this;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10130240
// Name: public: virtual void CMapKeyFrame::OnParentKeyChanged(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapKeyFrame::OnParentKeyChanged(CMapKeyFrame *this, const char *key, const char *value)
{
  const char *v3; // edi
  IPositionInterpolator *m_pPositionInterpolator; // ecx

  v3 = key;
  if ( _V_stricmp(s1: key, s2: "NextKey") != 0 )
  {
    if ( _V_stricmp(s1: key, s2: "NextTime") != 0 )
    {
      if ( _V_stricmp(s1: key, s2: "MoveSpeed") != 0 )
      {
        if ( _V_stricmp(s1: key, s2: "angles") == 0 )
        {
          sscanf(string: value, format: "%f %f %f", &this->m_Angles, &this->m_Angles.y, &this->m_Angles.z);
          AngleQuaternion(angles: &this->m_Angles, outQuat: &this->m_qAngles);
          v3 = key;
        }
      }
      else
      {
        this->m_flSpeed = atof(nptr: value);
        this->m_bRebuildPath = true;
      }
    }
    else
    {
      this->m_flMoveTime = atof(nptr: value);
    }
  }
  else
  {
    this->m_bRebuildPath = true;
  }
  m_pPositionInterpolator = this->m_pPositionInterpolator;
  if ( m_pPositionInterpolator != nullptr
    && m_pPositionInterpolator->ProcessKey(this: m_pPositionInterpolator, a2: v3, a3: value) )
  {
    this->m_bRebuildPath = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130330
// Name: protected: void CMapKeyFrame::RecalculateTimeFromSpeed(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMapKeyFrame::RecalculateTimeFromSpeed(CMapKeyFrame *this@<ecx>, int a2@<ebp>)
{
  CMapKeyFrame *m_pNextKeyFrame; // ecx
  __int128 v4; // xmm0
  float v5; // xmm1_4
  CMapKeyFrame *v6; // eax
  int i; // edi
  float v8; // xmm1_4
  float v9[3]; // [esp+18h] [ebp-38h] BYREF
  _QWORD v10[2]; // [esp+24h] [ebp-2Ch]
  float v11; // [esp+3Ch] [ebp-14h]
  float v12; // [esp+40h] [ebp-10h]
  int v13; // [esp+44h] [ebp-Ch]
  int v14; // [esp+48h] [ebp-8h]
  int o1_4; // [esp+50h] [ebp+0h]

  v13 = a2;
  v14 = o1_4;
  if ( this->m_flSpeed > 0.0 )
  {
    m_pNextKeyFrame = this->m_pNextKeyFrame;
    if ( m_pNextKeyFrame != nullptr )
    {
      m_pNextKeyFrame->GetOrigin(this: m_pNextKeyFrame, a2: (Vector *)v9);
      v4 = 0;
      *(float *)&v4 = fsqrt(
                        (float)((float)((float)(v9[1] - this->m_Origin.y) * (float)(v9[1] - this->m_Origin.y))
                              + (float)((float)(v9[2] - this->m_Origin.z) * (float)(v9[2] - this->m_Origin.z)))
                      + (float)((float)(v9[0] - this->m_Origin.x) * (float)(v9[0] - this->m_Origin.x)));
      *(_OWORD *)v10 = v4;
      v5 = *(float *)&v4;
      if ( *(float *)&v4 == 0.0 )
      {
        v6 = this->m_pNextKeyFrame;
        *((float *)v10 + 1) = this->m_Angles.x - v6->m_Angles.x;
        *(float *)&v10[1] = this->m_Angles.y - v6->m_Angles.y;
        *((float *)&v10[1] + 1) = this->m_Angles.z - v6->m_Angles.z;
        v12 = 0.0;
        for ( i = 0; i < 3; ++i )
        {
          v11 = *((float *)v10 + i + 1);
          fixang(a: v11);
          if ( v11 > 180.0 )
            *((float *)v10 + i + 1) = v11 - 360.0;
          v5 = v12;
          if ( COERCE_FLOAT(*((_DWORD *)v10 + i + 1) & _mask__AbsFloat_) > v12 )
          {
            LODWORD(v5) = *((_DWORD *)v10 + i + 1) & _mask__AbsFloat_;
            v12 = v5;
          }
        }
      }
      v8 = v5 / this->m_flSpeed;
      if ( this->m_flMoveTime != v8 )
      {
        this->m_flMoveTime = v8;
        this->m_bRebuildPath = true;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101304B0
// Name: protected: void CMapKeyFrame::BuildPathSegment(class CMapKeyFrame __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CMapKeyFrame::BuildPathSegment(CMapKeyFrame *this, CMapKeyFrame *pPrev)
{
  CMapAnimator *v3; // eax
  int v4; // ebx
  Vector *m_LinePoints; // edi
  float v6; // xmm1_4
  CMapKeyFrame_vtbl *v7; // edx
  CMapClass_vtbl *v8; // edx
  Quaternion newAngles; // [esp+20h] [ebp-18h] BYREF
  CMapAnimator *v10; // [esp+30h] [ebp-8h]
  _BYTE qAngles[5]; // [esp+34h] [ebp-4h] OVERLAPPED BYREF

  CMapKeyFrame::RecalculateTimeFromSpeed(this, a2: (int)&qAngles[4]);
  v3 = this->GetAnimator(this);
  v10 = v3;
  v4 = 1;
  m_LinePoints = this->m_LinePoints;
  *(_DWORD *)qAngles = 10;
  while ( 1 )
  {
    v6 = (float)((float)v4 * this->m_flMoveTime) * 0.1;
    if ( v3 != nullptr )
      CMapAnimator::GetAnimationAtTime(
        a1: v4,
        a2: (int)m_LinePoints,
        a3: (int)this,
        currentKey: this,
        pPrevKey: pPrev,
        partialTime: v6,
        newOrigin: m_LinePoints,
        &newAngles,
        posInterpolator: v3->m_iPositionInterpolator,
        rotInterpolator: v3->m_iRotationInterpolator);
    else
      CMapAnimator::GetAnimationAtTime(
        a1: v4,
        a2: (int)m_LinePoints,
        a3: (int)this,
        currentKey: this,
        pPrevKey: pPrev,
        partialTime: v6,
        newOrigin: m_LinePoints,
        &newAngles,
        posInterpolator: 0,
        rotInterpolator: 0);
    ++m_LinePoints;
    ++v4;
    if ( --*(_DWORD *)qAngles == 0 )
      break;
    v3 = v10;
  }
  v7 = this->__vftable;
  if ( this->m_pParent != nullptr )
  {
    v8 = v7->GetParent(this)->__vftable;
    ((void (__stdcall *)(int))v8->CalcBounds)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v7->CalcBounds)(a1: 0);
  }
  this->m_bRebuildPath = false;
}

//------------------------------------------------------------------------------
// Address: 0x10130590
// Name: public: virtual void CMapKeyFrame::UpdateDependencies(class CMapWorld __near *,class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapKeyFrame::UpdateDependencies(CMapKeyFrame *this, CMapWorld *pWorld, CMapWorld *pObject)
{
  this->m_bRebuildPath = true;
}

//------------------------------------------------------------------------------
// Address: 0x101305A0
// Name: public: void CMapKeyFrame::SetAnimator(class CMapAnimator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapKeyFrame::SetAnimator(CMapKeyFrame *this, CMapAnimator *pAnimator)
{
  this->m_pAnimator = (CMapAnimator *)CMapClass::UpdateDependency(
                                        this,
                                        pOldAttached: this->m_pAnimator,
                                        pNewAttached: pAnimator);
}

//------------------------------------------------------------------------------
// Address: 0x101305D0
// Name: protected: void CMapKeyFrame::SetNextKeyFrame(class CMapKeyFrame __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapKeyFrame::SetNextKeyFrame(CMapKeyFrame *this, CMapKeyFrame *pNext)
{
  this->m_pNextKeyFrame = (CMapKeyFrame *)CMapClass::UpdateDependency(
                                            this,
                                            pOldAttached: this->m_pNextKeyFrame,
                                            pNewAttached: pNext);
}

//------------------------------------------------------------------------------
// Address: 0x10130600
// Name: public: CMapKeyFrame::CMapKeyFrame(void)
// Source: json
//------------------------------------------------------------------------------
CMapKeyFrame *__thiscall CMapKeyFrame::CMapKeyFrame(CMapKeyFrame *this)
{
  CMapClass::CMapClass(this);
  this->__vftable = (CMapKeyFrame_vtbl *)&CMapHelper::`vftable';
  this->m_pAnimator = nullptr;
  this->m_pNextKeyFrame = nullptr;
  this->m_flMoveTime = 0.0;
  this->m_flSpeed = 0.0;
  this->m_bRebuildPath = false;
  this->__vftable = (CMapKeyFrame_vtbl *)&CMapKeyFrame::`vftable';
  this->m_Angles.x = 0.0;
  this->m_Angles.y = 0.0;
  this->m_Angles.z = 0.0;
  this->m_qAngles.z = 0.0;
  this->m_qAngles.y = 0.0;
  this->m_qAngles.x = 0.0;
  this->m_qAngles.w = 1.0;
  this->m_pPositionInterpolator = nullptr;
  this->m_iPositionInterpolator = -1;
  this->m_iChangeFrame = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10130740
// Name: public: virtual void CMapKeyFrame::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapKeyFrame::CalcBounds(CMapKeyFrame *this, int bFullUpdate)
{
  Vector *p_m_Origin; // ebx
  Vector *m_LinePoints; // ebx
  Vector vNextOrigin; // [esp+Ch] [ebp-10h] BYREF
  Vector *v6; // [esp+18h] [ebp-4h]
  int bFullUpdatea; // [esp+24h] [ebp+8h]

  CMapClass::CalcBounds(this, bFullUpdate);
  BoundBox::ResetBounds(this: &this->m_CullBox);
  p_m_Origin = &this->m_Origin;
  v6 = &this->m_Origin;
  BoundBox::UpdateBounds(this: &this->m_CullBox, pt: &this->m_Origin);
  if ( this->m_pNextKeyFrame != nullptr )
  {
    this->m_pNextKeyFrame->GetOrigin(this: this->m_pNextKeyFrame, a2: &vNextOrigin);
    BoundBox::UpdateBounds(this: &this->m_CullBox, pt: &vNextOrigin);
    m_LinePoints = this->m_LinePoints;
    for ( bFullUpdatea = 10; bFullUpdatea != 0; --bFullUpdatea )
      BoundBox::UpdateBounds(this: &this->m_CullBox, pt: m_LinePoints++);
    p_m_Origin = v6;
  }
  this->m_BoundingBox.bmins.x = this->m_CullBox.bmins.x;
  this->m_BoundingBox.bmins.y = this->m_CullBox.bmins.y;
  this->m_BoundingBox.bmins.z = this->m_CullBox.bmins.z;
  this->m_BoundingBox.bmaxs.x = this->m_CullBox.bmaxs.x;
  this->m_BoundingBox.bmaxs.y = this->m_CullBox.bmaxs.y;
  this->m_BoundingBox.bmaxs.z = this->m_CullBox.bmaxs.z;
  BoundBox::ResetBounds(this: &this->m_Render2DBox);
  BoundBox::UpdateBounds(this: &this->m_Render2DBox, mins: p_m_Origin, maxs: p_m_Origin);
}

//------------------------------------------------------------------------------
// Address: 0x10130800
// Name: public: virtual class CMapClass __near * CMapKeyFrame::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapKeyFrame *__thiscall CMapKeyFrame::Copy(CMapKeyFrame *this, BOOL bUpdateDependencies)
{
  CMapKeyFrame *v3; // eax
  CMapKeyFrame *v4; // esi

  v3 = (CMapKeyFrame *)operator new(nSize: 0x18Cu);
  v4 = nullptr;
  if ( v3 != nullptr )
    v4 = CMapKeyFrame::CMapKeyFrame(this: v3);
  v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10130870
// Name: public: virtual void CMapKeyFrame::OnNotifyDependent(class CMapClass __near *,enum Notify_Dependent_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapKeyFrame::OnNotifyDependent(CMapKeyFrame *this, CMapAnimator *pObject, KeyValues *eNotifyType)
{
  CMapAnimator *m_pAnimator; // eax
  CMapKeyFrame *m_pNextKeyFrame; // eax
  char *v6; // edi
  _DWORD *v7; // eax
  _DWORD *v8; // ebx
  const char *Value; // eax

  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: (int)pObject, msg: eNotifyType);
  m_pAnimator = this->m_pAnimator;
  if ( pObject == m_pAnimator && eNotifyType == (KeyValues *)1 )
    this->m_pAnimator = (CMapAnimator *)CMapClass::UpdateDependency(
                                          this,
                                          pOldAttached: m_pAnimator,
                                          pNewAttached: nullptr);
  m_pNextKeyFrame = this->m_pNextKeyFrame;
  if ( pObject == m_pNextKeyFrame && eNotifyType == (KeyValues *)1 )
  {
    v6 = (char *)__RTDynamicCast(
                   inptr: m_pNextKeyFrame->m_pParent,
                   VfDelta: 0,
                   SrcType: &CMapAtom `RTTI Type Descriptor',
                   TargetType: &CMapEntity `RTTI Type Descriptor',
                   isReference: 0);
    v7 = __RTDynamicCast(
           inptr: this->m_pParent,
           VfDelta: 0,
           SrcType: &CMapAtom `RTTI Type Descriptor',
           TargetType: &CMapEntity `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v6 != nullptr && v7 != nullptr )
    {
      Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                this: (WCKeyValuesT<WCKVBase_Dict> *)(v6 + 220),
                pszKey: "NextKey",
                piIndex: nullptr);
      (*(void (__thiscall **)(_DWORD *, const char *, const char *))(v8[54] + 4))(a1: v8 + 54, a2: "NextKey", a3: Value);
    }
  }
  this->m_bRebuildPath = true;
}

//------------------------------------------------------------------------------
// Address: 0x10130930
// Name: public: static class CMapClass __near * CMapKeyFrame::CreateMapKeyFrame(class CHelperInfo __near *,class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CMapKeyFrame *__cdecl CMapKeyFrame::CreateMapKeyFrame()
{
  CMapKeyFrame *v0; // eax

  v0 = (CMapKeyFrame *)operator new(nSize: 0x18Cu);
  if ( v0 != nullptr )
    return CMapKeyFrame::CMapKeyFrame(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10130990
// Name: public: virtual void CMapKeyFrame::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapKeyFrame::Render3D(CMapKeyFrame *this@<ecx>, int a2@<edi>, CRender3D *pRender)
{
  CMapAnimator *v4; // eax
  void (__thiscall *GetOrigin)(CMapPoint *, Vector *); // edx
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // edi
  int v8; // eax
  float *p_y; // esi
  int v10; // ebx
  float v11; // xmm0_4
  float *m_pCurrPosition; // eax
  int v13; // xmm1_4
  int v14; // xmm2_4
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-220h] BYREF
  Vector o2; // [esp+1ECh] [ebp-38h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F8h] [ebp-2Ch]
  Vector o1; // [esp+1FCh] [ebp-28h] BYREF
  IMesh *pMesh; // [esp+208h] [ebp-1Ch]
  float v21; // [esp+20Ch] [ebp-18h]
  int v22; // [esp+210h] [ebp-14h]
  float v23; // [esp+214h] [ebp-10h]
  int v24; // [esp+220h] [ebp-4h]

  if ( this->m_bRebuildPath && this->GetAnimator(this) != nullptr )
  {
    v4 = this->GetAnimator(this);
    CMapAnimator::RebuildPath(this: v4);
  }
  if ( this->m_pNextKeyFrame != nullptr && this->m_flSpeed > 0.0 && this->m_nRenderFrame != pRender->m_nFrameCount )
  {
    CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
    GetOrigin = this->GetOrigin;
    this->m_nRenderFrame = pRender->m_nFrameCount;
    ((void (__thiscall *)(CMapKeyFrame *, Vector *, int))GetOrigin)(a1: this, a2: &o1, a3: a2);
    this->m_pNextKeyFrame->GetOrigin(this: this->m_pNextKeyFrame, a2: &o2);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    v24 = 0;
    v6 = materials->GetRenderContext(this: materials);
    v7 = v6;
    pRenderContext.m_pObject = v6;
    LOBYTE(v24) = 1;
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    LOBYTE(v24) = 2;
    pMesh = v7->GetDynamicMesh(this: v7, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::Begin(this: &meshBuilder, pMesh, type: MATERIAL_LINE_STRIP, numPrimitives: 10);
    v21 = 8388608.0;
    v23 = 8388863.0;
    v22 = 1258291200;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = o1;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v8 = 0;
    p_y = &this->m_LinePoints[0].y;
    do
    {
      v10 = v8 + 1;
      v11 = (float)(v8 + 1) * 0.1;
      v22 = 1258291200;
      v23 = (float)((float)(1.0 - v11) * 255.0) + 8388608.0;
      v21 = (float)(v11 * 255.0) + 8388608.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = (LOBYTE(v23) | ((LOBYTE(v21) | 0xFFFFFF00) << 8)) << 8;
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v13 = *(_DWORD *)p_y;
      v14 = *((_DWORD *)p_y + 1);
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(p_y - 1);
      *((_DWORD *)m_pCurrPosition + 1) = v13;
      *((_DWORD *)m_pCurrPosition + 2) = v14;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v8 = v10;
      p_y += 3;
    }
    while ( v10 < 10 );
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
    CRender::PopRenderMode(this: pRender);
    LOBYTE(v24) = 3;
    v7->EndRender(this: v7);
    LOBYTE(v24) = 0;
    v7->Release(this: v7);
    v24 = -1;
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130CE0
// Name: public: class IPositionInterpolator __near * CMapKeyFrame::SetupPositionInterpolator(int)
// Source: json
//------------------------------------------------------------------------------
IPositionInterpolator *__thiscall CMapKeyFrame::SetupPositionInterpolator(
        CMapKeyFrame *this,
        CMapEntity *iInterpolator)
{
  IPositionInterpolator *m_pPositionInterpolator; // ecx
  CMapEntity *v4; // eax
  CMapEntity *v5; // ebx
  int i; // esi
  int v7; // eax
  CMapAtom *m_pParent; // [esp-1Ch] [ebp-24h]
  CMapEntity *pEnt; // [esp+10h] [ebp+8h]

  if ( iInterpolator == (CMapEntity *)this->m_iPositionInterpolator )
    return this->m_pPositionInterpolator;
  m_pPositionInterpolator = this->m_pPositionInterpolator;
  if ( m_pPositionInterpolator != nullptr )
    m_pPositionInterpolator->Release(this: m_pPositionInterpolator);
  this->m_pPositionInterpolator = Motion_GetPositionInterpolator(interpNum: (int)iInterpolator);
  m_pParent = this->m_pParent;
  this->m_iPositionInterpolator = (int)iInterpolator;
  v4 = (CMapEntity *)__RTDynamicCast(
                       inptr: m_pParent,
                       VfDelta: 0,
                       SrcType: &CMapAtom `RTTI Type Descriptor',
                       TargetType: &CMapEntity `RTTI Type Descriptor',
                       isReference: 0);
  v5 = v4;
  pEnt = v4;
  if ( v4 != nullptr )
  {
    for ( i = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &v4->m_KeyValues.m_KeyValues.m_Elements.m_Tree);
          i != 0xFFFF;
          i = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                  this: &pEnt->m_KeyValues.m_KeyValues.m_Elements.m_Tree,
                                  i) )
    {
      v7 = (int)&v5->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i];
      this->m_pPositionInterpolator->ProcessKey(
        this: this->m_pPositionInterpolator,
        a2: (const char *)(v7 + 12),
        a3: (const char *)(v7 + 92));
      v5 = pEnt;
    }
  }
  return this->m_pPositionInterpolator;
}

//------------------------------------------------------------------------------
// Address: 0x10130DC0
// Name: public: float CMapKeyFrame::GetRemainingTime(class CUtlReferenceVector<class CMapClass> __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMapKeyFrame::GetRemainingTime(CMapKeyFrame *this, CUtlReferenceVector<CMapClass> *pVisited)
{
  CUtlReferenceVector<CMapClass> *p_Visited; // edi
  CUtlReference<CMapClass> *m_pHead; // eax
  bool v5; // dl
  CUtlReference<CMapClass> *v6; // eax
  CMapKeyFrame *m_pNextKeyFrame; // ecx
  CUtlReferenceVector<CMapClass> Visited; // [esp+Ch] [ebp-2Ch] BYREF
  CUtlReference<CMapClass> src; // [esp+20h] [ebp-18h] BYREF
  int v11; // [esp+34h] [ebp-4h]
  float pVisiteda; // [esp+40h] [ebp+8h]

  memset(&Visited, 0, 12);
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &Visited.m_Memory, nGrowSize: 0, nInitSize: 0);
  Visited.m_Size = 0;
  Visited.m_pElements = nullptr;
  v11 = 3;
  p_Visited = pVisited;
  if ( pVisited == nullptr )
    p_Visited = &Visited;
  src.m_pPrev = nullptr;
  src.m_pNext = nullptr;
  src.m_pObject = this;
  if ( this != nullptr )
  {
    m_pHead = this->m_References.m_pHead;
    src.m_pNext = m_pHead;
    if ( m_pHead != nullptr )
      m_pHead->m_pPrev = &src;
    src.m_pPrev = nullptr;
    this->m_References.m_pHead = &src;
  }
  LOBYTE(v11) = 4;
  v5 = CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(this: p_Visited, &src) != -1;
  LOBYTE(v11) = 3;
  if ( src.m_pObject != nullptr )
  {
    if ( src.m_pPrev != nullptr )
    {
      src.m_pPrev->m_pNext = src.m_pNext;
      if ( src.m_pNext != nullptr )
        src.m_pNext->m_pPrev = src.m_pPrev;
    }
    else if ( src.m_pObject->m_References.m_pHead == &src )
    {
      src.m_pObject->m_References.m_pHead = src.m_pNext;
      if ( src.m_pNext != nullptr )
        src.m_pNext->m_pPrev = nullptr;
    }
    memset(&src, 0, sizeof(src));
  }
  if ( v5 )
    goto LABEL_30;
  src.m_pPrev = nullptr;
  src.m_pNext = nullptr;
  src.m_pObject = this;
  if ( this != nullptr )
  {
    v6 = this->m_References.m_pHead;
    src.m_pNext = v6;
    if ( v6 != nullptr )
      v6->m_pPrev = &src;
    src.m_pPrev = nullptr;
    this->m_References.m_pHead = &src;
  }
  LOBYTE(v11) = 7;
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
    this: p_Visited,
    elem: p_Visited->m_Size,
    &src);
  LOBYTE(v11) = 3;
  if ( src.m_pObject != nullptr )
  {
    if ( src.m_pPrev != nullptr )
    {
      src.m_pPrev->m_pNext = src.m_pNext;
      if ( src.m_pNext != nullptr )
        src.m_pNext->m_pPrev = src.m_pPrev;
    }
    else if ( src.m_pObject->m_References.m_pHead == &src )
    {
      src.m_pObject->m_References.m_pHead = src.m_pNext;
      if ( src.m_pNext != nullptr )
        src.m_pNext->m_pPrev = nullptr;
    }
    memset(&src, 0, sizeof(src));
  }
  m_pNextKeyFrame = this->m_pNextKeyFrame;
  if ( m_pNextKeyFrame == nullptr )
  {
LABEL_30:
    v11 = -1;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &Visited);
    return 0.0;
  }
  else
  {
    pVisiteda = CMapKeyFrame::GetRemainingTime(this: m_pNextKeyFrame, pVisited: p_Visited) + this->m_flMoveTime;
    v11 = -1;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &Visited);
    return pVisiteda;
  }
}
