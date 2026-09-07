// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/keyframe/keyframe.cpp
// Functions: 36
// ============================================================

#include "public\keyframe\keyframe.h"

//------------------------------------------------------------------------------
// Address: 0x100487F0
// Name: bool Motion_SetKeyAngles(int,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Motion_SetKeyAngles(int keyNum, Quaternion *quatAngles)
{
  if ( (unsigned int)(keyNum + 3) > 6 )
    return 0;
  g_KeyFramePtr[keyNum].qRot = *quatAngles;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10048830
// Name: float TimeModifierFunc_Linear(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl TimeModifierFunc_Linear(float time)
{
  return time;
}

//------------------------------------------------------------------------------
// Address: 0x10048840
// Name: float TimeModifierFunc_Cosine(float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl TimeModifierFunc_Cosine(float time)
{
  return cos((time + 1.0) * 3.141592653589793) * 0.5 + 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x10048860
// Name: float TimeModifierFunc_TimeSquared(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl TimeModifierFunc_TimeSquared(float time)
{
  return time * time;
}

//------------------------------------------------------------------------------
// Address: 0x10048870
// Name: class IPositionInterpolator __near * GetLinearInterpolator(void)
// Source: json
//------------------------------------------------------------------------------
CPositionInterpolator_Linear *__cdecl GetLinearInterpolator()
{
  return &g_LinearInterpolator;
}

//------------------------------------------------------------------------------
// Address: 0x10048880
// Name: public: virtual void CPositionInterpolator_Linear::GetDetails(char __near * __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPositionInterpolator_Linear::GetDetails(
        CPositionInterpolator_Linear *this,
        char **outName,
        int *outMinKeyReq,
        int *outMaxKeyReq)
{
  *outName = "Linear";
  *outMinKeyReq = 0;
  *outMaxKeyReq = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100488B0
// Name: public: virtual void CPositionInterpolator_Linear::InterpolatePosition(float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPositionInterpolator_Linear::InterpolatePosition(
        CPositionInterpolator_Linear *this,
        float time,
        Vector *vOut)
{
  KeyFrame_t *v3; // eax

  v3 = g_KeyFramePtr + 1;
  vOut->x = (float)((float)(g_KeyFramePtr[1].vPos.x - g_KeyFramePtr->vPos.x) * time) + g_KeyFramePtr->vPos.x;
  vOut->y = (float)((float)(v3->vPos.y - g_KeyFramePtr->vPos.y) * time) + g_KeyFramePtr->vPos.y;
  vOut->z = (float)((float)(v3->vPos.z - g_KeyFramePtr->vPos.z) * time) + g_KeyFramePtr->vPos.z;
}

//------------------------------------------------------------------------------
// Address: 0x10048920
// Name: class IPositionInterpolator __near * GetCatmullRomInterpolator(void)
// Source: json
//------------------------------------------------------------------------------
CPositionInterpolator_CatmullRom *__cdecl GetCatmullRomInterpolator()
{
  return &g_CatmullRomInterpolator;
}

//------------------------------------------------------------------------------
// Address: 0x10048930
// Name: public: virtual void CPositionInterpolator_CatmullRom::GetDetails(char __near * __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPositionInterpolator_CatmullRom::GetDetails(
        CPositionInterpolator_CatmullRom *this,
        char **outName,
        int *outMinKeyReq,
        int *outMaxKeyReq)
{
  *outName = "Catmull-Rom Spline";
  *outMinKeyReq = -1;
  *outMaxKeyReq = 2;
}

//------------------------------------------------------------------------------
// Address: 0x10048960
// Name: public: virtual void CPositionInterpolator_Linear::SetKeyPosition(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPositionInterpolator_Linear::SetKeyPosition(
        CPositionInterpolator_CatmullRom *this,
        int keyNum,
        const Vector *vPos)
{
  g_KeyFramePtr[keyNum].vPos = *vPos;
}

//------------------------------------------------------------------------------
// Address: 0x10048990
// Name: public: virtual void CPositionInterpolator_CatmullRom::InterpolatePosition(float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPositionInterpolator_CatmullRom::InterpolatePosition(
        CPositionInterpolator_CatmullRom *this,
        float time,
        Vector *vOut)
{
  Catmull_Rom_Spline(
    p1: &g_KeyFramePtr[-1].vPos,
    p2: &g_KeyFramePtr->vPos,
    p3: &g_KeyFramePtr[1].vPos,
    p4: &g_KeyFramePtr[2].vPos,
    t: time,
    output: vOut);
}

//------------------------------------------------------------------------------
// Address: 0x100489C0
// Name: public: virtual void CRopeDelegate::GetNodeForces(class CSimplePhysics::CNode __near *,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeDelegate::GetNodeForces(
        CRopeDelegate *this,
        CSimplePhysics::CNode *pNodes,
        int iNode,
        Vector *pAccel)
{
  pAccel->x = 0.0;
  pAccel->y = 0.0;
  pAccel->z = -1500.0;
}

//------------------------------------------------------------------------------
// Address: 0x100489F0
// Name: public: virtual void CRopeDelegate::ApplyConstraints(class CSimplePhysics::CNode __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeDelegate::ApplyConstraints(CRopeDelegate *this, CSimplePhysics::CNode *pNodes, int nNodes)
{
  if ( nNodes >= 2 )
  {
    pNodes->m_vPos = this->m_CurEndPoints[0];
    pNodes[nNodes - 1].m_vPos = this->m_CurEndPoints[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048A30
// Name: public: virtual void CPositionInterpolator_Rope::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPositionInterpolator_Rope::Release(CPositionInterpolator_Rope *this)
{
  operator delete(p: this);
}

//------------------------------------------------------------------------------
// Address: 0x10048A40
// Name: public: virtual void CPositionInterpolator_Rope::GetDetails(char __near * __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPositionInterpolator_Rope::GetDetails(
        CPositionInterpolator_Rope *this,
        char **outName,
        int *outMinKeyReq,
        int *outMaxKeyReq)
{
  *outName = "Rope";
  *outMinKeyReq = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10048A60
// Name: public: virtual void CPositionInterpolator_Rope::SetKeyPosition(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPositionInterpolator_Rope::SetKeyPosition(
        CPositionInterpolator_Rope *this,
        unsigned int keyNum,
        const Vector *vPos)
{
  Vector *v3; // edx

  if ( keyNum <= 1 )
  {
    v3 = &this->m_Delegate.m_CurEndPoints[keyNum];
    if ( v3->x != vPos->x || v3->y != vPos->y || v3->z != vPos->z )
      this->m_bChange = true;
    *v3 = *vPos;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048AD0
// Name: public: virtual void CPositionInterpolator_Rope::InterpolatePosition(float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPositionInterpolator_Rope::InterpolatePosition(
        CPositionInterpolator_Rope *this,
        float time,
        Vector *vOut)
{
  int v4; // edi
  int v5; // edx
  CSimplePhysics::CNode *m_pNodes; // ecx
  float *p_x; // eax
  CSimplePhysics::CNode *v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm0_4
  CSimplePhysics::CNode *v11; // eax
  float v12; // xmm2_4
  float *v13; // eax
  float v14; // xmm0_4
  float v15; // [esp+34h] [ebp-10h]

  if ( this->m_bChange )
  {
    CBaseRopePhysics::SetNumNodes(this: &this->m_RopePhysics, nNodes: this->m_nSegments);
    v4 = 0;
    if ( this->m_RopePhysics.m_nNodes > 0 )
    {
      v5 = 0;
      do
      {
        m_pNodes = this->m_RopePhysics.m_pNodes;
        m_pNodes[v5].m_vPrevPos.x = this->m_Delegate.m_CurEndPoints[0].x;
        p_x = &m_pNodes[v5].m_vPrevPos.x;
        ++v4;
        p_x[1] = this->m_Delegate.m_CurEndPoints[0].y;
        ++v5;
        p_x[2] = this->m_Delegate.m_CurEndPoints[0].z;
        v8 = this->m_RopePhysics.m_pNodes;
        v8[v5 - 1].m_vPos.x = *p_x;
        v8[v5 - 1].m_vPos.y = p_x[1];
        v8[v5 - 1].m_vPos.z = p_x[2];
      }
      while ( v4 < this->m_RopePhysics.m_nNodes );
    }
    v9 = this->m_Delegate.m_CurEndPoints[0].x - this->m_Delegate.m_CurEndPoints[1].x;
    v15 = this->m_flSlack
        + fsqrt(
            (float)((float)((float)(this->m_Delegate.m_CurEndPoints[0].y - this->m_Delegate.m_CurEndPoints[1].y)
                          * (float)(this->m_Delegate.m_CurEndPoints[0].y - this->m_Delegate.m_CurEndPoints[1].y))
                  + (float)((float)(this->m_Delegate.m_CurEndPoints[0].z - this->m_Delegate.m_CurEndPoints[1].z)
                          * (float)(this->m_Delegate.m_CurEndPoints[0].z - this->m_Delegate.m_CurEndPoints[1].z)))
          + (float)(v9 * v9));
    CBaseRopePhysics::Restart(this: &this->m_RopePhysics);
    CBaseRopePhysics::SetupSimulation(
      this: &this->m_RopePhysics,
      flSpringDist: v15 / (float)(this->m_RopePhysics.m_nNodes - 1),
      pDelegate: &this->m_Delegate);
    CBaseRopePhysics::Simulate(this: &this->m_RopePhysics, dt: 5.0);
    this->m_bChange = false;
  }
  v10 = (float)(this->m_RopePhysics.m_nNodes - 1) * time;
  v11 = this->m_RopePhysics.m_pNodes;
  v12 = v11[(int)v10 + 1].m_vPredicted.x - v11[v10].m_vPredicted.x;
  v13 = &v11[v10].m_vPos.x;
  v14 = v10 - (float)(int)v10;
  vOut->x = (float)(v12 * v14) + v13[6];
  vOut->y = (float)((float)(v13[16] - v13[7]) * v14) + v13[7];
  vOut->z = (float)((float)(v13[17] - v13[8]) * v14) + v13[8];
}

//------------------------------------------------------------------------------
// Address: 0x10048C90
// Name: public: virtual bool CPositionInterpolator_Rope::ProcessKey(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPositionInterpolator_Rope::ProcessKey(
        CPositionInterpolator_Rope *this,
        const char *pName,
        const char *pValue)
{
  int v5; // eax
  BOOL v6; // edx

  if ( _V_stricmp(s1: pName, s2: "Slack") != 0 )
  {
    if ( _V_stricmp(s1: pName, s2: "Type") != 0 )
    {
      return 0;
    }
    else
    {
      v5 = atoi(nptr: pValue);
      if ( v5 != 0 )
      {
        v6 = v5 == 1;
        this->m_bChange = true;
        this->m_nSegments = 2 * v6 + 2;
        return 1;
      }
      else
      {
        this->m_nSegments = 10;
        this->m_bChange = true;
        return 1;
      }
    }
  }
  else
  {
    this->m_flSlack = atof(nptr: pValue) - 100.0;
    this->m_bChange = true;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048D40
// Name: void RotationInterpolatorFunc_Linear(float,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RotationInterpolatorFunc_Linear(float time, Quaternion *outRot)
{
  QuaternionSlerp(p: &g_KeyFramePtr->qRot, q: &g_KeyFramePtr[1].qRot, t: time, qt: outRot);
}

//------------------------------------------------------------------------------
// Address: 0x10048D70
// Name: bool Motion_InterpolateRotation(float,int,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Motion_InterpolateRotation(float time, int interpFuncNum, Quaternion *outQuatRotation)
{
  if ( time < 0.0 || time > 1.0 )
    return 0;
  ((void (__cdecl *)(_DWORD, Quaternion *))g_RotationInterpolators[interpFuncNum].pFunc)(
    a1: LODWORD(time),
    a2: outQuatRotation);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10048DC0
// Name: class IPositionInterpolator __near * Motion_GetPositionInterpolator(int)
// Source: json
//------------------------------------------------------------------------------
IPositionInterpolator *__cdecl Motion_GetPositionInterpolator(int interpNum)
{
  int v1; // eax

  v1 = interpNum;
  if ( interpNum >= 0 )
  {
    if ( interpNum > 2 )
      v1 = 2;
  }
  else
  {
    v1 = 0;
  }
  return g_PositionInterpolatorCreateFns[v1]();
}

//------------------------------------------------------------------------------
// Address: 0x10048DF0
// Name: public: CPositionInterpolator_Rope::CPositionInterpolator_Rope(void)
// Source: json
//------------------------------------------------------------------------------
CPositionInterpolator_Rope *__thiscall CPositionInterpolator_Rope::CPositionInterpolator_Rope(
        CPositionInterpolator_Rope *this)
{
  this->__vftable = (CPositionInterpolator_Rope_vtbl *)&CPositionInterpolator_Rope::`vftable';
  CBaseRopePhysics::CBaseRopePhysics(
    this: &this->m_RopePhysics,
    pNodes: this->m_RopePhysics.m_Nodes,
    nNodes: 10,
    pSprings: this->m_RopePhysics.m_Springs,
    flSpringDistsSqr: this->m_RopePhysics.m_SpringDistsSqr);
  this->m_RopePhysics.__vftable = (CRopePhysics<10>_vtbl *)&CRopePhysics<10>::`vftable';
  this->m_Delegate.__vftable = (CRopeDelegate_vtbl *)&CRopeDelegate::`vftable';
  this->m_flSlack = 0.0;
  this->m_bChange = false;
  this->m_nSegments = 5;
  this->m_Delegate.m_CurEndPoints[0].x = 1.0e24;
  this->m_Delegate.m_CurEndPoints[0].y = 1.0e24;
  this->m_Delegate.m_CurEndPoints[0].z = 1.0e24;
  this->m_Delegate.m_CurEndPoints[1].x = 1.0e24;
  this->m_Delegate.m_CurEndPoints[1].y = 1.0e24;
  this->m_Delegate.m_CurEndPoints[1].z = 1.0e24;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10048E80
// Name: class IPositionInterpolator __near * GetRopeInterpolator(void)
// Source: json
//------------------------------------------------------------------------------
CPositionInterpolator_Rope *__cdecl GetRopeInterpolator()
{
  CPositionInterpolator_Rope *v0; // eax

  v0 = (CPositionInterpolator_Rope *)operator new(nSize: 0x240u);
  if ( v0 != nullptr )
    return CPositionInterpolator_Rope::CPositionInterpolator_Rope(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103F2D96
// Name: protected: int CMFCRibbonBar::ProcessKey(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonBar::ProcessKey(CMFCRibbonBar *this, int nChar)
{
  int v3; // eax
  CMFCRibbonKeyTip **v5; // eax
  CMFCRibbonKeyTip *v6; // edi
  int *m_pElement; // ebx
  const char *v8; // eax
  int v9; // ecx
  int m_nCurrKeyChar; // edx
  int m_bIsMenu; // edi
  CMFCPopupMenu::ANIMATION_TYPE AnimationType; // eax
  int v13; // eax
  CMFCPopupMenu::ANIMATION_TYPE disableMenuAnimation_4; // [esp+14h] [ebp-18h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strKeys; // [esp+18h] [ebp-14h] BYREF
  int i; // [esp+1Ch] [ebp-10h]
  int v17; // [esp+28h] [ebp-4h]

  this->OnBeforeProcessKey(this, a2: &nChar);
  v3 = 0;
  i = 0;
  if ( this->m_arKeyElements.m_nSize <= 0 )
    return 0;
  while ( 1 )
  {
    if ( v3 < 0 || v3 >= this->m_arKeyElements.m_nSize )
      AfxThrowInvalidArgException();
    v5 = &this->m_arKeyElements.m_pData[v3];
    v6 = *v5;
    m_pElement = (int *)(*v5)->m_pElement;
    if ( (*v5)->m_bIsMenu != 0 )
      v8 = (const char *)m_pElement[3];
    else
      v8 = (const char *)m_pElement[2];
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &strKeys,
      pszSrc: v8);
    v17 = 0;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::MakeUpper(this: &strKeys);
    v9 = *((_DWORD *)strKeys.m_pszData - 3);
    if ( v9 != 0 )
    {
      m_nCurrKeyChar = this->m_nCurrKeyChar;
      if ( m_nCurrKeyChar == 0 )
        break;
      if ( v9 > 1 && *strKeys.m_pszData == m_nCurrKeyChar )
      {
        if ( *((int *)strKeys.m_pszData - 3) < 1 )
          goto LABEL_26;
        if ( strKeys.m_pszData[1] == nChar )
          goto LABEL_15;
      }
    }
LABEL_24:
    v17 = -1;
    ATL::CStringData::Release(this: (ATL::CStringData *)strKeys.m_pszData - 1);
    if ( ++i >= this->m_arKeyElements.m_nSize )
      return 0;
    v3 = i;
  }
  if ( v9 < 0 )
LABEL_26:
    ATL::AtlThrowImpl(hr: -2147024809);
  if ( *strKeys.m_pszData != nChar )
    goto LABEL_24;
  if ( *((int *)strKeys.m_pszData - 3) > 1 )
  {
    this->m_nCurrKeyChar = *strKeys.m_pszData;
    CMFCRibbonBar::ShowKeyTips(this, bRepos: 0);
    ATL::CStringData::Release(this: (ATL::CStringData *)strKeys.m_pszData - 1);
    return 1;
  }
LABEL_15:
  m_bIsMenu = v6->m_bIsMenu;
  v17 = -1;
  ATL::CStringData::Release(this: (ATL::CStringData *)strKeys.m_pszData - 1);
  i = (int)this->m_hWnd;
  if ( GetFocus() != (HWND)i )
    CWnd::SetFocus(this);
  AnimationType = CMFCPopupMenu::GetAnimationType(bNoSystem: 0);
  CMFCPopupMenu::m_AnimationType = NO_ANIMATION;
  disableMenuAnimation_4 = AnimationType;
  i = (int)this->m_hWnd;
  v13 = *m_pElement;
  v17 = 1;
  if ( (*(int (__thiscall **)(int *, int))(v13 + 316))(a1: m_pElement, a2: m_bIsMenu) != 0 && IsWindow(hWnd: (HWND)i) )
    CMFCRibbonBar::DeactivateKeyboardFocus(this, bSetFocus: 1);
  CMFCPopupMenu::m_AnimationType = disableMenuAnimation_4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103F2F55
// Name: public: CMFCCaptionButton::CMFCCaptionButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCCaptionButton *__thiscall CMFCCaptionButton::CMFCCaptionButton(CMFCCaptionButton *this)
{
  this->__vftable = (CMFCCaptionButton_vtbl *)&CMFCCaptionButton::`vftable';
  this->m_ptOrg.x = 0;
  this->m_ptOrg.y = 0;
  this->m_clrForeground = -1;
  this->m_bPushed = 0;
  this->m_bFocused = 0;
  this->m_bDroppedDown = 0;
  this->m_bHidden = 0;
  this->m_bEnabled = 1;
  this->m_nHit = 0;
  this->m_bLeftAlign = 0;
  this->m_bIsMiniFrameButton = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103F2F86
// Name: public: CMFCCaptionButton::CMFCCaptionButton(unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCCaptionButton *__thiscall CMFCCaptionButton::CMFCCaptionButton(
        CMFCCaptionButton *this,
        unsigned int nHit,
        int bLeftAlign)
{
  this->__vftable = (CMFCCaptionButton_vtbl *)&CMFCCaptionButton::`vftable';
  this->m_ptOrg.x = 0;
  this->m_ptOrg.y = 0;
  this->m_clrForeground = -1;
  this->m_nHit = nHit;
  this->m_bPushed = 0;
  this->m_bFocused = 0;
  this->m_bDroppedDown = 0;
  this->m_bHidden = 0;
  this->m_bEnabled = 1;
  this->m_bLeftAlign = bLeftAlign;
  this->m_bIsMiniFrameButton = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103F2FC5
// Name: public: virtual CMFCCaptionButton::~CMFCCaptionButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCaptionButton::~CMFCCaptionButton(CMFCCaptionButton *this)
{
  this->__vftable = (CMFCCaptionButton_vtbl *)&CMFCCaptionButton::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x103F2FCC
// Name: public: unsigned int CMFCCaptionButton::GetHit(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCCaptionButton::GetHit(CMFCCaptionButton *this)
{
  return this->m_nHit;
}

//------------------------------------------------------------------------------
// Address: 0x103F2FD0
// Name: public: virtual void CMFCCaptionButton::OnDraw(class CDC __near *,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCaptionButton::OnDraw(
        CMFCCaptionButton *this,
        CDC *pDC,
        int bActive,
        int __formal,
        int bMaximized,
        int bDisabled)
{
  BOOL v7; // ebx
  CMFCVisualManager *Instance; // eax

  if ( this->m_bHidden == 0 )
  {
    v7 = bDisabled != 0 || this->m_bEnabled == 0;
    Instance = CMFCVisualManager::GetInstance();
    Instance->OnDrawCaptionButton(this: Instance, a2: pDC, a3: this, a4: bActive, a5: 0, a6: bMaximized, a7: v7, a8: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F3013
// Name: public: virtual enum CMenuImages::IMAGES_IDS CMFCCaptionButton::GetIconID(int,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCCaptionButton::GetIconID(CMFCCaptionButton *this, int bHorz, int bMaximized)
{
  unsigned int m_nHit; // eax

  m_nHit = this->m_nHit;
  if ( m_nHit == 8 )
  {
    if ( bHorz != 0 )
      return 8 * (bMaximized != 0) + 1;
    else
      return bMaximized != 0 ? 13 : 7;
  }
  else if ( m_nHit == 9 )
  {
    return 16 - (bMaximized != 0);
  }
  else
  {
    if ( m_nHit > 0x12 )
    {
      if ( m_nHit <= 0x14 )
        return 5;
      switch ( m_nHit )
      {
        case 0x17u:
          return 27;
        case 0x18u:
          return 28;
        case 0x19u:
          return 13;
        default:
          break;
      }
    }
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F3088
// Name: public: CMFCCaptionButtonEx::CMFCCaptionButtonEx(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCCaptionButtonEx *__thiscall CMFCCaptionButtonEx::CMFCCaptionButtonEx(CMFCCaptionButtonEx *this, unsigned int nHit)
{
  CMFCCaptionButton::CMFCCaptionButton(this);
  this->__vftable = (CMFCCaptionButtonEx_vtbl *)&CMFCCaptionButtonEx::`vftable';
  this->m_rect.left = 0;
  this->m_rect.top = 0;
  this->m_rect.right = 0;
  this->m_rect.bottom = 0;
  this->m_nHit = nHit;
  SetRectEmpty(lprc: &this->m_rect);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103F30BF
// Name: public: virtual class CRect CMFCCaptionButtonEx::GetRect(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRect *__thiscall CMFCCaptionButtonEx::GetRect(CMFCCaptionButtonEx *this, CRect *result)
{
  *result = this->m_rect;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F30D8
// Name: public: virtual class CRect CMFCCaptionButton::GetRect(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRect *__thiscall CMFCCaptionButton::GetRect(CMFCCaptionButton *this, CRect *result)
{
  CSize *Size; // eax
  int x; // ecx
  int cx; // edi
  int cy; // ebx
  int y; // edx
  CSize v9; // [esp+Ch] [ebp-8h] BYREF

  if ( this->m_bHidden != 0 )
  {
    v9.cx = 0;
    v9.cy = 0;
    Size = &v9;
  }
  else
  {
    Size = CMFCCaptionButton::GetSize(result: &v9);
  }
  x = this->m_ptOrg.x;
  cx = Size->cx;
  cy = Size->cy;
  y = this->m_ptOrg.y;
  result->right = x + cx;
  result->bottom = y + cy;
  result->left = x;
  result->top = y;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F3145
// Name: public: virtual struct CRuntimeClass __near * CMFCToolBarsCustomizeDialog::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCToolBarsCustomizeDialog::GetRuntimeClass(CMFCToolBarsCustomizeDialog *this)
{
  return &CMFCToolBarsCustomizeDialog::classCMFCToolBarsCustomizeDialog;
}

//------------------------------------------------------------------------------
// Address: 0x103F314B
// Name: protected: void CMFCToolBarsCustomizeDialog::ShowToolBar(class CMFCToolBar __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsCustomizeDialog::ShowToolBar(
        CMFCToolBarsCustomizeDialog *this,
        CMFCToolBar *pToolBar,
        int bShow)
{
  CMFCToolBarsListPropertyPage::ShowToolBar(this: this->m_pToolbarsPage, pToolBar, bShow);
}

//------------------------------------------------------------------------------
// Address: 0x103F315C
// Name: protected: void CMFCToolBarsCustomizeDialog::OnClose(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsCustomizeDialog::OnClose(CMFCToolBarsCustomizeDialog *this)
{
  CMFCToolBarsToolsPropertyPage *m_pToolsPage; // edi

  if ( afxUserToolsManager != nullptr
    && this->m_pToolsPage != nullptr
    && this->CheckToolsValidity(this, a2: &afxUserToolsManager->m_lstUserTools) == 0 )
  {
    m_pToolsPage = this->m_pToolsPage;
    if ( CPropertySheet::GetActivePage(this) != m_pToolsPage )
      CPropertySheet::SetActivePage(this, pPage: m_pToolsPage);
  }
  else
  {
    CPropertySheet::OnClose(this);
  }
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10163FC0
// Name: float TimeModifierFunc_Linear(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl TimeModifierFunc_Linear(float time)
{
  return time;
}

//------------------------------------------------------------------------------
// Address: 0x10163FD0
// Name: float TimeModifierFunc_Cosine(float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl TimeModifierFunc_Cosine(float time)
{
  return cos((time + 1.0) * 3.141592653589793) * 0.5 + 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x10163FF0
// Name: float TimeModifierFunc_TimeSquared(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl TimeModifierFunc_TimeSquared(float time)
{
  return time * time;
}

//------------------------------------------------------------------------------
// Address: 0x10164000
// Name: class IPositionInterpolator __near * GetLinearInterpolator(void)
// Source: json
//------------------------------------------------------------------------------
CPositionInterpolator_Linear *__cdecl GetLinearInterpolator()
{
  return &g_LinearInterpolator;
}

//------------------------------------------------------------------------------
// Address: 0x10164010
// Name: public: virtual void CPositionInterpolator_Linear::GetDetails(char __near * __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPositionInterpolator_Linear::GetDetails(
        CPositionInterpolator_Linear *this,
        char **outName,
        int *outMinKeyReq,
        int *outMaxKeyReq)
{
  *outName = "Linear";
  *outMinKeyReq = 0;
  *outMaxKeyReq = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10164040
// Name: public: virtual void CPositionInterpolator_Linear::SetKeyPosition(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPositionInterpolator_Linear::SetKeyPosition(
        CPositionInterpolator_CatmullRom *this,
        int keyNum,
        const Vector *vPos)
{
  g_KeyFramePtr[keyNum].vPos = *vPos;
}

//------------------------------------------------------------------------------
// Address: 0x10164070
// Name: public: virtual void CPositionInterpolator_Linear::InterpolatePosition(float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPositionInterpolator_Linear::InterpolatePosition(
        CPositionInterpolator_Linear *this,
        float time,
        Vector *vOut)
{
  KeyFrame_t *v3; // eax

  v3 = g_KeyFramePtr + 1;
  vOut->x = (float)((float)(g_KeyFramePtr[1].vPos.x - g_KeyFramePtr->vPos.x) * time) + g_KeyFramePtr->vPos.x;
  vOut->y = (float)((float)(v3->vPos.y - g_KeyFramePtr->vPos.y) * time) + g_KeyFramePtr->vPos.y;
  vOut->z = (float)((float)(v3->vPos.z - g_KeyFramePtr->vPos.z) * time) + g_KeyFramePtr->vPos.z;
}

//------------------------------------------------------------------------------
// Address: 0x101640E0
// Name: class IPositionInterpolator __near * GetCatmullRomInterpolator(void)
// Source: json
//------------------------------------------------------------------------------
CPositionInterpolator_CatmullRom *__cdecl GetCatmullRomInterpolator()
{
  return &g_CatmullRomInterpolator;
}

//------------------------------------------------------------------------------
// Address: 0x101640F0
// Name: public: virtual void CPositionInterpolator_CatmullRom::GetDetails(char __near * __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPositionInterpolator_CatmullRom::GetDetails(
        CPositionInterpolator_CatmullRom *this,
        char **outName,
        int *outMinKeyReq,
        int *outMaxKeyReq)
{
  *outName = "Catmull-Rom Spline";
  *outMinKeyReq = -1;
  *outMaxKeyReq = 2;
}

//------------------------------------------------------------------------------
// Address: 0x10164120
// Name: public: virtual void CPositionInterpolator_CatmullRom::InterpolatePosition(float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPositionInterpolator_CatmullRom::InterpolatePosition(
        CPositionInterpolator_CatmullRom *this,
        float time,
        Vector *vOut)
{
  Catmull_Rom_Spline(
    p1: &g_KeyFramePtr[-1].vPos,
    p2: &g_KeyFramePtr->vPos,
    p3: &g_KeyFramePtr[1].vPos,
    p4: &g_KeyFramePtr[2].vPos,
    t: time,
    output: vOut);
}

//------------------------------------------------------------------------------
// Address: 0x10164150
// Name: public: virtual void CRopeDelegate::GetNodeForces(class CSimplePhysics::CNode __near *,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeDelegate::GetNodeForces(
        CRopeDelegate *this,
        CSimplePhysics::CNode *pNodes,
        int iNode,
        Vector *pAccel)
{
  pAccel->x = 0.0;
  pAccel->y = 0.0;
  pAccel->z = -1500.0;
}

//------------------------------------------------------------------------------
// Address: 0x10164180
// Name: public: virtual void CRopeDelegate::ApplyConstraints(class CSimplePhysics::CNode __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRopeDelegate::ApplyConstraints(CRopeDelegate *this, CSimplePhysics::CNode *pNodes, int nNodes)
{
  if ( nNodes >= 2 )
  {
    pNodes->m_vPos = this->m_CurEndPoints[0];
    pNodes[nNodes - 1].m_vPos = this->m_CurEndPoints[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x101641C0
// Name: public: virtual void CPositionInterpolator_Rope::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPositionInterpolator_Rope::Release(CPositionInterpolator_Rope *this)
{
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x101641D0
// Name: public: virtual void CPositionInterpolator_Rope::GetDetails(char __near * __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPositionInterpolator_Rope::GetDetails(
        CPositionInterpolator_Rope *this,
        char **outName,
        int *outMinKeyReq,
        int *outMaxKeyReq)
{
  *outName = "Rope";
  *outMinKeyReq = 1;
}

//------------------------------------------------------------------------------
// Address: 0x101641F0
// Name: public: virtual void CPositionInterpolator_Rope::SetKeyPosition(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPositionInterpolator_Rope::SetKeyPosition(
        CPositionInterpolator_Rope *this,
        unsigned int keyNum,
        const Vector *vPos)
{
  Vector *v3; // edx

  if ( keyNum <= 1 )
  {
    v3 = &this->m_Delegate.m_CurEndPoints[keyNum];
    if ( v3->x != vPos->x || v3->y != vPos->y || v3->z != vPos->z )
      this->m_bChange = true;
    *v3 = *vPos;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164260
// Name: public: virtual void CPositionInterpolator_Rope::InterpolatePosition(float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPositionInterpolator_Rope::InterpolatePosition(
        CPositionInterpolator_Rope *this,
        float time,
        Vector *vOut)
{
  int v4; // edi
  int v5; // edx
  CSimplePhysics::CNode *m_pNodes; // ecx
  float *p_x; // eax
  CSimplePhysics::CNode *v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm0_4
  CSimplePhysics::CNode *v11; // eax
  float v12; // xmm2_4
  float *v13; // eax
  float v14; // xmm0_4
  float v15; // [esp+34h] [ebp-10h]

  if ( this->m_bChange )
  {
    CBaseRopePhysics::SetNumNodes(this: &this->m_RopePhysics, nNodes: this->m_nSegments);
    v4 = 0;
    if ( this->m_RopePhysics.m_nNodes > 0 )
    {
      v5 = 0;
      do
      {
        m_pNodes = this->m_RopePhysics.m_pNodes;
        m_pNodes[v5].m_vPrevPos.x = this->m_Delegate.m_CurEndPoints[0].x;
        p_x = &m_pNodes[v5].m_vPrevPos.x;
        ++v4;
        p_x[1] = this->m_Delegate.m_CurEndPoints[0].y;
        ++v5;
        p_x[2] = this->m_Delegate.m_CurEndPoints[0].z;
        v8 = this->m_RopePhysics.m_pNodes;
        v8[v5 - 1].m_vPos.x = *p_x;
        v8[v5 - 1].m_vPos.y = p_x[1];
        v8[v5 - 1].m_vPos.z = p_x[2];
      }
      while ( v4 < this->m_RopePhysics.m_nNodes );
    }
    v9 = this->m_Delegate.m_CurEndPoints[0].x - this->m_Delegate.m_CurEndPoints[1].x;
    v15 = this->m_flSlack
        + fsqrt(
            (float)((float)((float)(this->m_Delegate.m_CurEndPoints[0].y - this->m_Delegate.m_CurEndPoints[1].y)
                          * (float)(this->m_Delegate.m_CurEndPoints[0].y - this->m_Delegate.m_CurEndPoints[1].y))
                  + (float)((float)(this->m_Delegate.m_CurEndPoints[0].z - this->m_Delegate.m_CurEndPoints[1].z)
                          * (float)(this->m_Delegate.m_CurEndPoints[0].z - this->m_Delegate.m_CurEndPoints[1].z)))
          + (float)(v9 * v9));
    CBaseRopePhysics::Restart(this: &this->m_RopePhysics);
    CBaseRopePhysics::SetupSimulation(
      this: &this->m_RopePhysics,
      flSpringDist: v15 / (float)(this->m_RopePhysics.m_nNodes - 1),
      pDelegate: &this->m_Delegate);
    CBaseRopePhysics::Simulate(this: &this->m_RopePhysics, dt: 5.0);
    this->m_bChange = false;
  }
  v10 = (float)(this->m_RopePhysics.m_nNodes - 1) * time;
  v11 = this->m_RopePhysics.m_pNodes;
  v12 = v11[(int)v10 + 1].m_vPredicted.x - v11[v10].m_vPredicted.x;
  v13 = &v11[v10].m_vPos.x;
  v14 = v10 - (float)(int)v10;
  vOut->x = (float)(v12 * v14) + v13[6];
  vOut->y = (float)((float)(v13[16] - v13[7]) * v14) + v13[7];
  vOut->z = (float)((float)(v13[17] - v13[8]) * v14) + v13[8];
}

//------------------------------------------------------------------------------
// Address: 0x10164420
// Name: public: virtual bool CPositionInterpolator_Rope::ProcessKey(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPositionInterpolator_Rope::ProcessKey(
        CPositionInterpolator_Rope *this,
        const char *pName,
        const char *pValue)
{
  int v5; // eax
  BOOL v6; // edx

  if ( _V_stricmp(s1: pName, s2: "Slack") != 0 )
  {
    if ( _V_stricmp(s1: pName, s2: "Type") != 0 )
    {
      return 0;
    }
    else
    {
      v5 = atoi(nptr: pValue);
      if ( v5 != 0 )
      {
        v6 = v5 == 1;
        this->m_bChange = true;
        this->m_nSegments = 2 * v6 + 2;
        return 1;
      }
      else
      {
        this->m_nSegments = 10;
        this->m_bChange = true;
        return 1;
      }
    }
  }
  else
  {
    this->m_flSlack = atof(nptr: pValue) - 100.0;
    this->m_bChange = true;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101644D0
// Name: void RotationInterpolatorFunc_Linear(float,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RotationInterpolatorFunc_Linear(float time, Quaternion *outRot)
{
  QuaternionSlerp(p: &g_KeyFramePtr->qRot, q: &g_KeyFramePtr[1].qRot, t: time, qt: outRot);
}

//------------------------------------------------------------------------------
// Address: 0x10164500
// Name: public: CPositionInterpolator_Rope::CPositionInterpolator_Rope(void)
// Source: json
//------------------------------------------------------------------------------
CPositionInterpolator_Rope *__thiscall CPositionInterpolator_Rope::CPositionInterpolator_Rope(
        CPositionInterpolator_Rope *this)
{
  this->__vftable = (CPositionInterpolator_Rope_vtbl *)&CPositionInterpolator_Rope::`vftable';
  CBaseRopePhysics::CBaseRopePhysics(
    this: &this->m_RopePhysics,
    pNodes: this->m_RopePhysics.m_Nodes,
    nNodes: 10,
    pSprings: this->m_RopePhysics.m_Springs,
    flSpringDistsSqr: this->m_RopePhysics.m_SpringDistsSqr);
  this->m_RopePhysics.__vftable = (CRopePhysics<10>_vtbl *)&CRopePhysics<10>::`vftable';
  this->m_Delegate.__vftable = (CRopeDelegate_vtbl *)&CRopeDelegate::`vftable';
  this->m_flSlack = 0.0;
  this->m_bChange = false;
  this->m_nSegments = 5;
  this->m_Delegate.m_CurEndPoints[0].x = 1.0e24;
  this->m_Delegate.m_CurEndPoints[0].y = 1.0e24;
  this->m_Delegate.m_CurEndPoints[0].z = 1.0e24;
  this->m_Delegate.m_CurEndPoints[1].x = 1.0e24;
  this->m_Delegate.m_CurEndPoints[1].y = 1.0e24;
  this->m_Delegate.m_CurEndPoints[1].z = 1.0e24;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10164590
// Name: class IPositionInterpolator __near * GetRopeInterpolator(void)
// Source: json
//------------------------------------------------------------------------------
CPositionInterpolator_Rope *__cdecl GetRopeInterpolator()
{
  CPositionInterpolator_Rope *v0; // eax

  v0 = (CPositionInterpolator_Rope *)operator new(nSize: 0x240u);
  if ( v0 != nullptr )
    return CPositionInterpolator_Rope::CPositionInterpolator_Rope(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10405F00
// Name: _dynamic_initializer_for__keyframe_track__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__keyframe_track__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPathKeyFrame> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &keyframe_track,
           a3: "keyframe_track");
}

//------------------------------------------------------------------------------
// Address: 0x10409650
// Name: _dynamic_initializer_for__keyframe_rope__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__keyframe_rope__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CRopeKeyframe> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &keyframe_rope,
           a3: "keyframe_rope");
}

//------------------------------------------------------------------------------
// Address: 0x10409670
// Name: _dynamic_initializer_for__g_CRopeKeyframe_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CRopeKeyframe_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CRopeKeyframe_ClassReg,
           pNetworkName: "CRopeKeyframe",
           pTable: &DT_RopeKeyframe::g_SendTable);
}

} // namespace server
