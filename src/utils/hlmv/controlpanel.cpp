// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlmv/controlpanel.cpp
// Functions: 209
// ============================================================

#include "utils\hlmv\controlpanel.h"

//------------------------------------------------------------------------------
// Address: 0x00401B80
// Name: public: struct mstudioseqdesc_t __near & CStudioHdr::pSeqdesc(int)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall CStudioHdr::pSeqdesc(CStudioHdr *this, int iSequence)
{
  int v2; // eax
  const studiohdr_t *m_pStudioHdr; // ecx

  if ( this->m_pVModel != nullptr )
    return CStudioHdr::pSeqdesc_Internal(this, i: iSequence);
  v2 = iSequence;
  m_pStudioHdr = this->m_pStudioHdr;
  if ( iSequence < 0 || iSequence >= m_pStudioHdr->numlocalseq )
    v2 = 0;
  return (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v2 + m_pStudioHdr->localseqindex);
}

//------------------------------------------------------------------------------
// Address: 0x00401BC0
// Name: public: CValveIpcMgr::Iterator::Iterator(char __near *)
// Source: json
//------------------------------------------------------------------------------
CValveIpcMgr::Iterator *__thiscall CValveIpcMgr::Iterator::Iterator(CValveIpcMgr::Iterator *this, char *m_pMemory)
{
  char *v2; // esi
  CValveIpcMgr::Iterator *result; // eax
  unsigned int v4; // edx

  v2 = m_pMemory;
  result = this;
  if ( m_pMemory == nullptr )
    v2 = (char *)WindowName;
  this->m_szServerName = v2;
  if ( *v2 != 0 )
  {
    v4 = strlen(v2);
    *(_QWORD *)&result->m_uuid.Data1 = *(_QWORD *)&v2[v4 + 1];
    *(_QWORD *)result->m_uuid.Data4 = *(_QWORD *)&v2[v4 + 9];
  }
  else
  {
    this->m_uuid = GUID_NULL;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401C30
// Name: public: int CValveIpcMgr::Iterator::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcMgr::Iterator::IsValid(CValveIpcMgr::Iterator *this)
{
  GUID *v1; // eax
  unsigned int v2; // edx
  int v3; // ecx

  if ( this->m_szServerName == nullptr || *this->m_szServerName == 0 )
    return 0;
  v1 = &GUID_NULL;
  v2 = 16;
  v3 = (char *)&this->m_uuid - (char *)&GUID_NULL;
  while ( *(unsigned int *)((char *)&v1->Data1 + v3) == v1->Data1 )
  {
    v2 -= 4;
    v1 = (GUID *)((char *)v1 + 4);
    if ( v2 < 4 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401D10
// Name: private: int CValveIpcMgr::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcMgr::Shutdown(CValveIpcMgr *this)
{
  if ( this->m_pMemory != nullptr )
  {
    UnmapViewOfFile(lpBaseAddress: this->m_pMemory);
    this->m_pMemory = nullptr;
  }
  if ( this->m_hMemorySegment != nullptr )
  {
    CloseHandle(hObject: this->m_hMemorySegment);
    this->m_hMemorySegment = nullptr;
  }
  if ( this->m_hMutex != nullptr )
  {
    ReleaseMutex(hMutex: this->m_hMutex);
    CloseHandle(hObject: this->m_hMutex);
    this->m_hMutex = nullptr;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401D60
// Name: public: int CValveIpcMgr::DiscoverServer(char const __near *,unsigned char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcMgr::DiscoverServer(
        CValveIpcMgr *this,
        const char *szServerName,
        unsigned __int8 **pszServerUID)
{
  unsigned int v3; // eax
  int i; // ecx
  CValveIpcMgr::Iterator v6; // [esp+4h] [ebp-28h] BYREF
  CValveIpcMgr::Iterator it; // [esp+18h] [ebp-14h] BYREF

  if ( szServerName == nullptr || *szServerName == 0 )
    return 0;
  CValveIpcMgr::Iterator::Iterator(this: &it, m_pMemory: this->m_pMemory);
  while ( 1 )
  {
    if ( it.m_szServerName == nullptr || *it.m_szServerName == 0 )
      return 0;
    v3 = 16;
    for ( i = 0; *(unsigned int *)((char *)&it.m_uuid.Data1 + i) == *(unsigned int *)((char *)&GUID_NULL.Data1 + i); i += 4 )
    {
      v3 -= 4;
      if ( v3 < 4 )
        return 0;
    }
    if ( _V_stricmp(s1: szServerName, s2: it.m_szServerName) == 0 )
      break;
    it = *CValveIpcMgr::Iterator::Next(this: &it, result: &v6);
  }
  if ( pszServerUID != nullptr )
    UuidToStringA(Uuid: &it.m_uuid, StringUuid: pszServerUID);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401E20
// Name: public: int CValveIpcClient::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcClient::Disconnect(CValveIpcClient *this)
{
  unsigned __int8 **p_m_szServerUID; // edi

  p_m_szServerUID = &this->m_szServerUID;
  if ( this->m_szServerUID == nullptr )
    return 0;
  if ( this->m_hClientPipe != nullptr )
  {
    CloseHandle(hObject: this->m_hClientPipe);
    this->m_hClientPipe = nullptr;
  }
  if ( *p_m_szServerUID != nullptr )
  {
    RpcStringFreeA(String: p_m_szServerUID);
    *p_m_szServerUID = nullptr;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401E70
// Name: ReadPhysicsMaterials
// Source: json
//------------------------------------------------------------------------------
void __usercall ReadPhysicsMaterials(mxChoice *plist@<edi>)
{
  int i; // esi
  const char *v2; // eax

  LoadPhysicsProperties();
  mxChoice::removeAll(this: plist);
  if ( physprop != nullptr && physprop->SurfacePropCount(this: physprop) != 0 )
  {
    for ( i = 0; i < physprop->SurfacePropCount(this: physprop); ++i )
    {
      v2 = physprop->GetPropName(this: physprop, a2: i);
      mxChoice::add(this: plist, item: v2);
    }
    mxChoice::select(this: plist, index: 0);
  }
  else
  {
    mxChoice::add(this: plist, item: "default");
    mxChoice::select(this: plist, index: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401EF0
// Name: PopulatePhysicsBoneList
// Source: json
//------------------------------------------------------------------------------
char __usercall PopulatePhysicsBoneList@<al>(mxChoice *pChoice@<edi>)
{
  int i; // esi
  const char *BoneName; // eax

  mxChoice::removeAll(this: pChoice);
  if ( StudioModel::Physics_GetBoneCount(this: g_pStudioModel) != 0 )
  {
    for ( i = 0; i < StudioModel::Physics_GetBoneCount(this: g_pStudioModel); ++i )
    {
      BoneName = StudioModel::Physics_GetBoneName(this: g_pStudioModel, index: i);
      mxChoice::add(this: pChoice, item: BoneName);
    }
    mxChoice::select(this: pChoice, index: 0);
    return 1;
  }
  else
  {
    mxChoice::add(this: pChoice, item: "None");
    mxChoice::select(this: pChoice, index: 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401F70
// Name: PopulateSoundNameList
// Source: json
//------------------------------------------------------------------------------
void __usercall PopulateSoundNameList(mxListBox *pListBox@<edi>)
{
  int i; // esi
  const char *v2; // eax

  mxListBox::removeAll(this: pListBox);
  if ( g_pSoundEmitterBase != nullptr )
  {
    for ( i = g_pSoundEmitterBase->First(this: g_pSoundEmitterBase);
          i != g_pSoundEmitterBase->InvalidIndex(this: g_pSoundEmitterBase);
          i = g_pSoundEmitterBase->Next(this: g_pSoundEmitterBase, a2: i) )
    {
      v2 = g_pSoundEmitterBase->GetSoundName(this: g_pSoundEmitterBase, a2: i);
      mxListBox::add(this: pListBox, item: v2);
    }
  }
  mxListBox::select(this: pListBox, index: 0);
  mxListBox::deselect(this: pListBox, index: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00401FF0
// Name: bool PopulateBoneList(class mxChoice __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PopulateBoneList(mxChoice *pChoice, bool bAlwaysAddNone)
{
  CStudioHdr *m_pStudioHdr; // ebx
  CStudioHdr **p_m_pStudioHdr; // esi
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  const studiohdr_t *v6; // ecx
  int v7; // esi
  int v8; // edi

  mxChoice::removeAll(this: pChoice);
  if ( bAlwaysAddNone )
    mxChoice::add(this: pChoice, item: "(None)");
  if ( g_pStudioModel == nullptr )
    goto LABEL_13;
  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    goto LABEL_13;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
    CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    v5 = *p_m_pStudioHdr;
    if ( v5->m_pStudioHdr == nullptr )
      goto LABEL_13;
    m_pStudioHdr = v5;
  }
  if ( m_pStudioHdr != nullptr )
  {
    v6 = m_pStudioHdr->m_pStudioHdr;
    if ( m_pStudioHdr->m_pStudioHdr->numbones > 0 )
    {
      v7 = 0;
      v8 = 0;
      do
      {
        mxChoice::add(
          this: pChoice,
          item: (const char *)v6 + v8 + v6->boneindex + *(int *)((char *)&v6->id + v8 + v6->boneindex));
        v6 = m_pStudioHdr->m_pStudioHdr;
        ++v7;
        v8 += 216;
      }
      while ( v7 < m_pStudioHdr->m_pStudioHdr->numbones );
      mxChoice::select(this: pChoice, index: 0);
      return 1;
    }
  }
LABEL_13:
  if ( !bAlwaysAddNone )
    mxChoice::add(this: pChoice, item: "(None)");
  mxChoice::select(this: pChoice, index: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004020D0
// Name: void SetFrameString(class mxLineEdit2 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetFrameString(mxLineEdit2 *pLineEdit, int iLayer)
{
  double v2; // st7
  char msg[16]; // [esp+0h] [ebp-10h] BYREF

  v2 = StudioModel::GetFrame(this: g_pStudioModel, iLayer) + 0.5;
  sprintf(string: msg, format: "%d", (int)v2);
  mxLineEdit2::setText(this: pLineEdit, pText: msg);
}

//------------------------------------------------------------------------------
// Address: 0x00402120
// Name: FindSurfaceProp
// Source: json
//------------------------------------------------------------------------------
int __usercall FindSurfaceProp@<eax>(const char *pSurfaceProp@<edi>)
{
  int v1; // esi
  const char *v2; // eax

  v1 = 0;
  if ( physprop->SurfacePropCount(this: physprop) <= 0 )
    return -1;
  while ( 1 )
  {
    v2 = physprop->GetPropName(this: physprop, a2: v1);
    if ( _V_stricmp(s1: v2, s2: pSurfaceProp) == 0 )
      break;
    if ( ++v1 >= physprop->SurfacePropCount(this: physprop) )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00402170
// Name: private: void CBoneControlWindow::OnBoneHighlighted(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnBoneHighlighted(CBoneControlWindow *this, bool isChecked)
{
  if ( isChecked )
    g_viewerSettings.highlightBone = this->m_Bone;
  else
    g_viewerSettings.highlightBone = -1;
}

//------------------------------------------------------------------------------
// Address: 0x004021A0
// Name: private: void CBoneControlWindow::OnHitboxHighlighted(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnHitboxHighlighted(CBoneControlWindow *this, bool isChecked)
{
  if ( isChecked )
    g_viewerSettings.highlightHitbox = this->m_Hitbox;
  else
    g_viewerSettings.highlightHitbox = -1;
}

//------------------------------------------------------------------------------
// Address: 0x004021D0
// Name: private: void CBoneControlWindow::OnAutogenerateHitboxes(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnAutogenerateHitboxes(CBoneControlWindow *this, bool isChecked)
{
  mxWidget::setEnabled(this: this->m_eHitboxGroup, b: !isChecked);
  mxWidget::setEnabled(this: this->m_eHitboxName, b: !isChecked);
  mxWidget::setEnabled(this: this->m_eOriginX, b: !isChecked);
  mxWidget::setEnabled(this: this->m_eOriginY, b: !isChecked);
  mxWidget::setEnabled(this: this->m_eOriginZ, b: !isChecked);
  mxWidget::setEnabled(this: this->m_eSizeX, b: !isChecked);
  mxWidget::setEnabled(this: this->m_eSizeY, b: !isChecked);
  mxWidget::setEnabled(this: this->m_eSizeZ, b: !isChecked);
  mxWidget::setEnabled(this: this->m_bUpdateHitbox, b: !isChecked);
  mxWidget::setEnabled(this: this->m_bAddHitbox, b: !isChecked);
  mxWidget::setEnabled(this: this->m_bDeleteHitbox, b: !isChecked);
  mxWidget::setEnabled(this: this->m_cHitboxSet, b: !isChecked);
  mxWidget::setEnabled(this: this->m_eHitboxSetName, b: !isChecked);
  mxWidget::setEnabled(this: this->m_bHitboxSetUpdateName, b: !isChecked);
  mxWidget::setEnabled(this: this->m_bAddHitboxSet, b: !isChecked);
  mxWidget::setEnabled(this: this->m_bDeleteHitboxSet, b: !isChecked);
}

//------------------------------------------------------------------------------
// Address: 0x00402280
// Name: public: void ControlPanel::SetupSequenceWindow(class mxTab __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::SetupSequenceWindow(ControlPanel *this, mxTab *pTab)
{
  mxWindow *v3; // eax
  mxWindow *v4; // edi
  int v5; // esi
  mxSlider **slSequence; // ebx
  mxChoice *v7; // eax
  mxChoice *v8; // eax
  mxSlider *v9; // eax
  mxSlider *v10; // eax
  mxRadioButton *v11; // eax
  mxRadioButton *v12; // eax
  mxLineEdit *v13; // eax
  mxLineEdit *v14; // eax
  mxLabel *v15; // eax
  mxLabel *v16; // eax
  mxSlider *v17; // ecx
  mxLabel *v18; // eax
  mxLabel *v19; // eax
  int v20; // esi
  int v21; // ebx
  mxChoice *v22; // eax
  mxChoice *v23; // eax
  mxSlider *v24; // eax
  mxSlider *v25; // eax
  mxLineEdit *v26; // eax
  mxLineEdit *v27; // eax
  bool v28; // zf
  mxSlider *v29; // eax
  mxSlider *v30; // eax
  mxLabel *v31; // eax
  mxLabel *v32; // eax
  mxCheckBox *v33; // eax
  mxButton *v34; // eax
  mxLabel *v35; // eax
  mxLabel *v36; // eax
  mxSlider *v37; // eax
  mxSlider *v38; // eax
  mxLabel *v39; // eax
  mxLabel *v40; // eax
  mxLabel *v41; // eax
  mxChoice *v42; // eax
  mxChoice *v43; // eax
  mxCheckBox *v44; // eax
  int v46; // [esp+1Ch] [ebp-8h]
  int y; // [esp+20h] [ebp-4h]
  mxSlider **ya; // [esp+20h] [ebp-4h]

  v3 = (mxWindow *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    v4 = mxWindow::mxWindow(this: v3, parent: this, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  else
    v4 = nullptr;
  mxTab::add(this: this->tab, widget: v4, text: "Sequence");
  v5 = 3005;
  y = 5;
  slSequence = this->slSequence;
  do
  {
    v7 = (mxChoice *)operator new(nSize: 0xCu);
    if ( v7 != nullptr )
      v8 = mxChoice::mxChoice(this: v7, parent: v4, x: 5, y, w: 200, h: 22, id: v5 - 5);
    else
      v8 = nullptr;
    *(slSequence - 11) = (mxSlider *)v8;
    mxToolTip::add(widget: v8, text: "Select Sequence");
    v9 = (mxSlider *)operator new(nSize: 0x18u);
    if ( v9 != nullptr )
      v10 = mxSlider::mxSlider(this: v9, parent: v4, x: 208, y, w: 80, h: 18, id: v5, style: 0);
    else
      v10 = nullptr;
    *slSequence = v10;
    mxSlider::setRange(this: v10, min: 0.0, max: 1.0, ticks: 100);
    mxSlider::setValue(this: *slSequence, value: 0.0);
    v11 = (mxRadioButton *)operator new(nSize: 0xCu);
    if ( v11 != nullptr )
      v12 = mxRadioButton::mxRadioButton(
              this: v11,
              parent: v4,
              x: 300,
              y,
              w: 35,
              h: 22,
              label: WindowName,
              id: v5 + 5,
              newGroup: v5 == 3005);
    else
      v12 = nullptr;
    slSequence[50] = (mxSlider *)v12;
    v13 = (mxLineEdit *)operator new(nSize: 0xCu);
    if ( v13 != nullptr )
      v14 = mxLineEdit::mxLineEdit(
              this: v13,
              parent: v4,
              x: 0,
              y: 0,
              w: 0,
              h: 0,
              label: WindowName,
              id: v5 + 15,
              style: 0);
    else
      v14 = nullptr;
    y += 22;
    ++v5;
    *(slSequence - 5) = (mxSlider *)v14;
    ++slSequence;
  }
  while ( v5 - 3005 < 5 );
  v15 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v15 != nullptr )
    v16 = mxLabel::mxLabel(this: v15, parent: v4, x: 0, y: 0, w: 0, h: 0, label: "Sequence Filters");
  else
    v16 = nullptr;
  v17 = this->slSequence[0];
  this->laFilters = v16;
  mxWidget::setVisible(this: v17, b: false);
  v18 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v18 != nullptr )
    v19 = mxLabel::mxLabel(this: v18, parent: v4, x: 208, y: 5, w: 80, h: 18, label: WindowName);
  else
    v19 = nullptr;
  this->laGroundSpeed = v19;
  v20 = 3100;
  ya = this->slPoseParameter;
  v46 = 8;
  do
  {
    v21 = 17 * (((_BYTE)v20 - 4) & 7) + 2;
    v22 = (mxChoice *)operator new(nSize: 0xCu);
    if ( v22 != nullptr )
      v23 = mxChoice::mxChoice(this: v22, parent: v4, x: 520, y: v21, w: 96, h: 22, id: v20 + 20);
    else
      v23 = nullptr;
    *(ya - 8) = (mxSlider *)v23;
    mxWidget::setVisible(this: v23, b: false);
    v24 = (mxSlider *)operator new(nSize: 0x18u);
    if ( v24 != nullptr )
      v25 = mxSlider::mxSlider(this: v24, parent: v4, x: 334, y: v21, w: 140, h: 16, id: v20, style: 0);
    else
      v25 = nullptr;
    *ya = v25;
    mxSlider::setRange(this: v25, min: 0.0, max: 1.0, ticks: 1000);
    mxToolTip::add(widget: *ya, text: "Parameter");
    mxWidget::setVisible(this: *ya, b: false);
    v26 = (mxLineEdit *)operator new(nSize: 0xCu);
    if ( v26 != nullptr )
      v27 = mxLineEdit::mxLineEdit(
              this: v26,
              parent: v4,
              x: 480,
              y: v21,
              w: 40,
              h: 16,
              label: "X",
              id: v20 + 40,
              style: 0);
    else
      v27 = nullptr;
    ya[8] = (mxSlider *)v27;
    mxWidget::setVisible(this: v27, b: false);
    ++v20;
    v28 = v46-- == 1;
    ++ya;
  }
  while ( !v28 );
  v29 = (mxSlider *)operator new(nSize: 0x18u);
  if ( v29 != nullptr )
    v30 = mxSlider::mxSlider(this: v29, parent: v4, x: 5, y: 115, w: 200, h: 18, id: 3201, style: 0);
  else
    v30 = nullptr;
  this->slSpeedScale = v30;
  mxSlider::setRange(this: v30, min: 0.0, max: 1.0, ticks: 100);
  mxSlider::setValue(this: this->slSpeedScale, value: 1.0);
  mxToolTip::add(widget: this->slSpeedScale, text: "Speed Scale");
  v31 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v31 != nullptr )
    v32 = mxLabel::mxLabel(this: v31, parent: v4, x: 208, y: 115, w: 128, h: 22, label: WindowName);
  else
    v32 = nullptr;
  this->laFPS = v32;
  v33 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v33 != nullptr )
    mxCheckBox::mxCheckBox(
      this: v33,
      parent: v4,
      x: 5,
      y: 142,
      w: 150,
      h: 20,
      label: "Blend Sequence Changes",
      id: 3203);
  v34 = (mxButton *)operator new(nSize: 0xCu);
  if ( v34 != nullptr )
    mxButton::mxButton(this: v34, parent: v4, x: 155, y: 142, w: 80, h: 20, label: "Blend Now", id: 3204);
  v35 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v35 != nullptr )
    v36 = mxLabel::mxLabel(this: v35, parent: v4, x: 240, y: 142, w: 60, h: 20, label: WindowName);
  else
    v36 = nullptr;
  this->laBlendAmount = v36;
  v37 = (mxSlider *)operator new(nSize: 0x18u);
  if ( v37 != nullptr )
    v38 = mxSlider::mxSlider(this: v37, parent: v4, x: 308, y: 142, w: 200, h: 18, id: 3205, style: 0);
  else
    v38 = nullptr;
  this->slBlendTime = v38;
  mxSlider::setRange(this: v38, min: 0.0, max: 1.0, ticks: 100);
  mxSlider::setValue(this: this->slBlendTime, value: 0.2);
  v39 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v39 != nullptr )
    v40 = mxLabel::mxLabel(this: v39, parent: v4, x: 540, y: 142, w: 80, h: 22, label: WindowName);
  else
    v40 = nullptr;
  this->laBlendTime = v40;
  v41 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v41 != nullptr )
    mxLabel::mxLabel(this: v41, parent: v4, x: 5, y: 170, w: 90, h: 18, label: "Activity modifiers:");
  v42 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v42 != nullptr )
    v43 = mxChoice::mxChoice(this: v42, parent: v4, x: 105, y: 166, w: 350, h: 22, id: 3206);
  else
    v43 = nullptr;
  this->cActivityModifiers = v43;
  v44 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v44 != nullptr )
    mxCheckBox::mxCheckBox(this: v44, parent: v4, x: 460, y: 166, w: 350, h: 22, label: "Animate weapons", id: 3207);
}

//------------------------------------------------------------------------------
// Address: 0x00402810
// Name: public: void ControlPanel::SetupFlexWindow(class mxTab __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::SetupFlexWindow(ControlPanel *this, mxTab *pTab)
{
  mxWindow *v3; // eax
  int v4; // edi
  mxSlider **slFlexScale; // ebx
  mxChoice *v6; // eax
  mxChoice *v7; // eax
  mxSlider *v8; // eax
  mxSlider *v9; // eax
  mxButton *v10; // eax
  mxButton *v11; // eax
  mxButton *v12; // eax
  mxButton *v13; // eax
  mxWindow *wFlex; // [esp+18h] [ebp-4h]
  int h; // [esp+24h] [ebp+8h]

  v3 = (mxWindow *)operator new(nSize: 0xCu);
  v4 = 0;
  if ( v3 != nullptr )
  {
    wFlex = mxWindow::mxWindow(this: v3, parent: this, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
    mxTab::add(this: pTab, widget: wFlex, text: "Flex");
  }
  else
  {
    wFlex = nullptr;
    mxTab::add(this: pTab, widget: nullptr, text: "Flex");
  }
  slFlexScale = this->slFlexScale;
  do
  {
    h = 20 * (v4 & 7) + 5;
    v6 = (mxChoice *)operator new(nSize: 0xCu);
    if ( v6 != nullptr )
      v7 = mxChoice::mxChoice(
             this: v6,
             parent: wFlex,
             x: 194 * ((unsigned int)v4 >> 3) + 5,
             y: h,
             w: 90,
             h: 22,
             id: v4 + 7001);
    else
      v7 = nullptr;
    *(slFlexScale - 48) = (mxSlider *)v7;
    mxToolTip::add(widget: v7, text: "Select Flex");
    v8 = (mxSlider *)operator new(nSize: 0x18u);
    if ( v8 != nullptr )
      v9 = mxSlider::mxSlider(
             this: v8,
             parent: wFlex,
             x: 194 * ((unsigned int)v4 >> 3) + 95,
             y: h,
             w: 100,
             h: 18,
             id: v4 + 7101,
             style: 0);
    else
      v9 = nullptr;
    *slFlexScale = v9;
    mxSlider::setRange(this: v9, min: 0.0, max: 1.0, ticks: 100);
    mxSlider::setValue(this: *slFlexScale, value: 0.0);
    mxToolTip::add(widget: *slFlexScale, text: "Flex Scale");
    ++v4;
    ++slFlexScale;
  }
  while ( v4 < 48 );
  v10 = (mxButton *)operator new(nSize: 0xCu);
  if ( v10 != nullptr )
    mxButton::mxButton(this: v10, parent: wFlex, x: 5, y: 166, w: 88, h: 18, label: "Reset", id: 7002);
  v11 = (mxButton *)operator new(nSize: 0xCu);
  if ( v11 != nullptr )
    mxButton::mxButton(this: v11, parent: wFlex, x: 99, y: 166, w: 88, h: 18, label: "Random", id: 7003);
  v12 = (mxButton *)operator new(nSize: 0xCu);
  if ( v12 != nullptr )
    mxButton::mxButton(this: v12, parent: wFlex, x: 198, y: 166, w: 88, h: 18, label: "Zero", id: 7004);
  v13 = (mxButton *)operator new(nSize: 0xCu);
  if ( v13 != nullptr )
    mxButton::mxButton(this: v13, parent: wFlex, x: 297, y: 166, w: 88, h: 18, label: "One", id: 7005);
}

//------------------------------------------------------------------------------
// Address: 0x00402A00
// Name: public: int ControlPanel::GetCurrentHitboxSet(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ControlPanel::GetCurrentHitboxSet(ControlPanel *this)
{
  CBoneControlWindow *m_pBoneWindow; // eax

  m_pBoneWindow = this->m_pBoneWindow;
  if ( m_pBoneWindow != nullptr )
    return m_pBoneWindow->m_nHitboxSet;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00402A20
// Name: public: virtual void ControlPanel::OnDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::OnDelete(ControlPanel *this)
{
  g_ControlPanel = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00402A30
// Name: public: void ControlPanel::BuildEventQCString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::BuildEventQCString(ControlPanel *this)
{
  const char *Label; // eax
  int SelectedIndex; // eax
  const char *ItemText; // eax
  char qcstr[256]; // [esp+4h] [ebp-100h] BYREF

  if ( g_ControlPanel != nullptr )
  {
    _V_strcpy(dest: qcstr, src: "{ event AE_CL_PLAYSOUND ");
    Label = mxWidget::getLabel(this: this->leEventSoundFrame);
    V_strncat(pDest: qcstr, pSrc: Label, destBufferSize: 0x100u, max_chars_to_copy: -1);
    V_strncat(pDest: qcstr, pSrc: " \"", destBufferSize: 0x100u, max_chars_to_copy: -1);
    SelectedIndex = mxListBox::getSelectedIndex(this: this->lbEventSoundName);
    ItemText = mxListBox::getItemText(this: this->lbEventSoundName, index: SelectedIndex);
    V_strncat(pDest: qcstr, pSrc: ItemText, destBufferSize: 0x100u, max_chars_to_copy: -1);
    V_strncat(pDest: qcstr, pSrc: "\" }", destBufferSize: 0x100u, max_chars_to_copy: -1);
    mxLineEdit2::setText(this: this->leEventQCString, pText: qcstr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402B00
// Name: public: void ControlPanel::BuildIKRuleQCString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::BuildIKRuleQCString(ControlPanel *this)
{
  const char *Label; // eax
  const char *v3; // edi
  const char *v4; // eax
  const char *v5; // eax
  int SelectedIndex; // eax
  char qcstr[256]; // [esp+4h] [ebp-114h] BYREF
  char str[20]; // [esp+104h] [ebp-14h] BYREF

  if ( g_ControlPanel != nullptr )
  {
    _V_strcpy(dest: qcstr, src: "ikrule ");
    Label = mxWidget::getLabel(this: this->cIKChain);
    V_strncat(pDest: qcstr, pSrc: Label, destBufferSize: 0x100u, max_chars_to_copy: -1);
    V_strncat(pDest: qcstr, pSrc: " ", destBufferSize: 0x100u, max_chars_to_copy: -1);
    v3 = mxWidget::getLabel(this: this->cIKType);
    V_strncat(pDest: qcstr, pSrc: v3, destBufferSize: 0x100u, max_chars_to_copy: -1);
    if ( _V_strcmp(s1: v3, s2: "touch") != 0 )
    {
      if ( _V_strcmp(s1: v3, s2: "attachment") == 0 )
      {
        V_strncat(pDest: qcstr, pSrc: " \"", destBufferSize: 0x100u, max_chars_to_copy: -1);
        v5 = mxWidget::getLabel(this: this->leIKAttachment);
        V_strncat(pDest: qcstr, pSrc: v5, destBufferSize: 0x100u, max_chars_to_copy: -1);
        V_strncat(pDest: qcstr, pSrc: "\"", destBufferSize: 0x100u, max_chars_to_copy: -1);
      }
    }
    else
    {
      V_strncat(pDest: qcstr, pSrc: " \"", destBufferSize: 0x100u, max_chars_to_copy: -1);
      if ( mxChoice::getSelectedIndex(this: this->cIKTouch) > 0 )
      {
        v4 = mxWidget::getLabel(this: this->cIKTouch);
        V_strncat(pDest: qcstr, pSrc: v4, destBufferSize: 0x100u, max_chars_to_copy: -1);
      }
      V_strncat(pDest: qcstr, pSrc: "\"", destBufferSize: 0x100u, max_chars_to_copy: -1);
    }
    if ( mxRadioButton::isChecked(this: (mxRadioButton *)this->cbIKRangeToggle) )
    {
      V_strncat(pDest: qcstr, pSrc: " range ", destBufferSize: 0x100u, max_chars_to_copy: -1);
      mxLineEdit2::getText(this: this->leIKRangeStart, pOut: str, len: 20);
      V_strncat(pDest: qcstr, pSrc: str, destBufferSize: 0x100u, max_chars_to_copy: -1);
      V_strncat(pDest: qcstr, pSrc: " ", destBufferSize: 0x100u, max_chars_to_copy: -1);
      mxLineEdit2::getText(this: this->leIKRangePeak, pOut: str, len: 20);
      V_strncat(pDest: qcstr, pSrc: str, destBufferSize: 0x100u, max_chars_to_copy: -1);
      V_strncat(pDest: qcstr, pSrc: " ", destBufferSize: 0x100u, max_chars_to_copy: -1);
      mxLineEdit2::getText(this: this->leIKRangeTail, pOut: str, len: 20);
      V_strncat(pDest: qcstr, pSrc: str, destBufferSize: 0x100u, max_chars_to_copy: -1);
      V_strncat(pDest: qcstr, pSrc: " ", destBufferSize: 0x100u, max_chars_to_copy: -1);
      mxLineEdit2::getText(this: this->leIKRangeEnd, pOut: str, len: 20);
      V_strncat(pDest: qcstr, pSrc: str, destBufferSize: 0x100u, max_chars_to_copy: -1);
    }
    if ( mxRadioButton::isChecked(this: (mxRadioButton *)this->cbIKContactToggle) )
    {
      V_strncat(pDest: qcstr, pSrc: " contact ", destBufferSize: 0x100u, max_chars_to_copy: -1);
      mxLineEdit2::getText(this: this->leIKContactFrame, pOut: str, len: 20);
      V_strncat(pDest: qcstr, pSrc: str, destBufferSize: 0x100u, max_chars_to_copy: -1);
    }
    SelectedIndex = mxChoice::getSelectedIndex(this: this->cIKUsing);
    if ( SelectedIndex > 0 )
    {
      if ( SelectedIndex == 1 )
      {
        V_strncat(pDest: qcstr, pSrc: " usesource", destBufferSize: 0x100u, max_chars_to_copy: -1);
      }
      else if ( SelectedIndex == 2 )
      {
        V_strncat(pDest: qcstr, pSrc: " usesequence", destBufferSize: 0x100u, max_chars_to_copy: -1);
      }
    }
    mxLineEdit2::setText(this: this->leIKQCString, pText: qcstr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402E50
// Name: public: void ControlPanel::UpdateIKRuleWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::UpdateIKRuleWindow(ControlPanel *this)
{
  const char *Label; // edi
  bool bIsAttachment; // [esp+8h] [ebp-8h]
  bool bIsTouch; // [esp+Ch] [ebp-4h]

  Label = mxWidget::getLabel(this: this->cIKType);
  bIsTouch = _V_strcmp(s1: Label, s2: "touch") == 0;
  bIsAttachment = _V_strcmp(s1: Label, s2: "attachment") == 0;
  mxWidget::setVisible(this: this->lIKTouch, b: bIsTouch);
  mxWidget::setVisible(this: this->cIKTouch, b: bIsTouch);
  mxWidget::setVisible(this: this->lIKAttachment, b: bIsAttachment);
  mxWidget::setVisible(this: this->leIKAttachment, b: bIsAttachment);
  ControlPanel::BuildIKRuleQCString(this);
}

//------------------------------------------------------------------------------
// Address: 0x00402EE0
// Name: public: void ControlPanel::setRenderMode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setRenderMode(ControlPanel *this, int mode)
{
  g_viewerSettings.renderMode = mode;
  this->d_MatSysWindow->redraw(this: this->d_MatSysWindow);
}

//------------------------------------------------------------------------------
// Address: 0x00402F00
// Name: public: void ControlPanel::setLODMetric(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setLODMetric(ControlPanel *this, float metric)
{
  char tmp[128]; // [esp+0h] [ebp-80h] BYREF

  if ( (int)metric != saveMetric )
  {
    saveMetric = (int)metric;
    sprintf(string: tmp, format: "%d", (int)metric);
    mxWidget::setLabel(this: this->lLODMetric, format: tmp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402F50
// Name: public: void ControlPanel::setPolycount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setPolycount(ControlPanel *this, int polycount)
{
  char tmp[128]; // [esp+4h] [ebp-80h] BYREF

  if ( polycount != savePolycount )
  {
    savePolycount = polycount;
    sprintf(string: tmp, format: "Polycount: %d", polycount);
    mxWidget::setLabel(this: this->lModelInfo3, format: tmp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402FA0
// Name: public: void ControlPanel::setTransparent(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setTransparent(ControlPanel *this, bool isTransparent)
{
  const char *v3; // eax
  char tmp[128]; // [esp+4h] [ebp-80h] BYREF

  if ( isTransparent != saveTransparent )
  {
    saveTransparent = isTransparent;
    v3 = "transparent";
    if ( !isTransparent )
      v3 = "opaque";
    sprintf(string: tmp, format: "Model is: %s", v3);
    mxWidget::setLabel(this: this->lModelInfo4, format: tmp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403000
// Name: public: void ControlPanel::updatePoseParameters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::updatePoseParameters(ControlPanel *this)
{
  mxSlider **slPoseParameter; // esi
  int i; // edi
  int SelectedIndex; // eax
  const char *Label; // eax
  float value; // [esp+10h] [ebp-4h]

  slPoseParameter = this->slPoseParameter;
  for ( i = 8; i != 0; --i )
  {
    if ( mxWidget::isEnabled(this: *slPoseParameter) )
    {
      SelectedIndex = mxChoice::getSelectedIndex(this: (mxChoice *)*(slPoseParameter - 8));
      value = StudioModel::GetPoseParameter(this: g_pStudioModel, iParameter: SelectedIndex);
      Label = mxWidget::getLabel(this: slPoseParameter[8]);
      if ( fabs(atof(nptr: Label) - value) > 0.1 )
      {
        mxSlider::setValue(this: *slPoseParameter, value);
        mxWidget::setLabel(this: slPoseParameter[8], format: "%.1f", value);
      }
    }
    ++slPoseParameter;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004030A0
// Name: public: void ControlPanel::setShowGround(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setShowGround(ControlPanel *this, bool b)
{
  g_viewerSettings.showGround = b;
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbGround, b);
}

//------------------------------------------------------------------------------
// Address: 0x004030C0
// Name: public: void ControlPanel::setAutoLOD(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setAutoLOD(ControlPanel *this, bool b)
{
  g_viewerSettings.autoLOD = b;
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbAutoLOD, b);
}

//------------------------------------------------------------------------------
// Address: 0x004030E0
// Name: public: void ControlPanel::setShowMovement(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setShowMovement(ControlPanel *this, bool b)
{
  g_viewerSettings.showMovement = b;
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbMovement, b);
}

//------------------------------------------------------------------------------
// Address: 0x00403100
// Name: public: void ControlPanel::setShowBackground(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setShowBackground(ControlPanel *this, bool b)
{
  g_viewerSettings.showBackground = b;
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbBackground, b);
}

//------------------------------------------------------------------------------
// Address: 0x00403120
// Name: public: void ControlPanel::setShowNormals(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setShowNormals(ControlPanel *this, bool b)
{
  g_viewerSettings.showNormals = b;
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbNormals, b);
}

//------------------------------------------------------------------------------
// Address: 0x00403140
// Name: public: void ControlPanel::setShowTangentFrame(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setShowTangentFrame(ControlPanel *this, bool b)
{
  g_viewerSettings.showTangentFrame = b;
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbTangentFrame, b);
}

//------------------------------------------------------------------------------
// Address: 0x00403160
// Name: public: void ControlPanel::setOverlayWireframe(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setOverlayWireframe(ControlPanel *this, bool b)
{
  g_viewerSettings.overlayWireframe = b;
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbOverlayWireframe, b);
}

//------------------------------------------------------------------------------
// Address: 0x00403180
// Name: public: void ControlPanel::setDisplacementMapping(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setDisplacementMapping(ControlPanel *this, bool b)
{
  g_viewerSettings.enableDisplacementMapping = b;
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbDisplacementMap, b);
}

//------------------------------------------------------------------------------
// Address: 0x004031A0
// Name: public: void ControlPanel::setShowShadow(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setShowShadow(ControlPanel *this, bool b)
{
  g_viewerSettings.showShadow = b;
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbShadow, b);
}

//------------------------------------------------------------------------------
// Address: 0x004031C0
// Name: public: void ControlPanel::setShowHitBoxes(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setShowHitBoxes(ControlPanel *this, bool b)
{
  g_viewerSettings.showHitBoxes = b;
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbHitBoxes, b);
}

//------------------------------------------------------------------------------
// Address: 0x004031E0
// Name: public: void ControlPanel::setShowBones(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setShowBones(ControlPanel *this, bool b)
{
  g_viewerSettings.showBones = b;
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbBones, b);
}

//------------------------------------------------------------------------------
// Address: 0x00403200
// Name: public: void ControlPanel::setShowAttachments(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setShowAttachments(ControlPanel *this, bool b)
{
  g_viewerSettings.showAttachments = b;
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbAttachments, b);
}

//------------------------------------------------------------------------------
// Address: 0x00403220
// Name: void ComposeSequenceDisplayName(class CStudioHdr __near *,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComposeSequenceDisplayName(CStudioHdr *hdr, int nSequence, char *buffer, int bufferLength)
{
  const studiohdr_t *m_pStudioHdr; // ecx
  int v5; // eax
  mstudioseqdesc_t *v6; // eax
  int szactivitynameindex; // ecx
  const studiohdr_t *v8; // ecx
  int v9; // eax
  int v10; // eax
  const studiohdr_t *v11; // ecx
  mstudioseqdesc_t *v12; // eax
  int v13; // eax
  const studiohdr_t *v14; // ecx
  mstudioseqdesc_t *v15; // eax

  if ( g_viewerSettings.showSequenceIndices )
  {
    if ( g_viewerSettings.showActivities )
    {
      if ( hdr->m_pVModel != nullptr )
      {
        v6 = CStudioHdr::pSeqdesc_Internal(this: hdr, i: nSequence);
        szactivitynameindex = v6->szactivitynameindex;
      }
      else
      {
        m_pStudioHdr = hdr->m_pStudioHdr;
        v5 = nSequence;
        if ( nSequence < 0 || nSequence >= m_pStudioHdr->numlocalseq )
          v5 = 0;
        v6 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v5 + m_pStudioHdr->localseqindex);
        szactivitynameindex = v6->szactivitynameindex;
      }
    }
    else
    {
      if ( hdr->m_pVModel != nullptr )
      {
        v6 = CStudioHdr::pSeqdesc_Internal(this: hdr, i: nSequence);
      }
      else
      {
        v8 = hdr->m_pStudioHdr;
        v9 = nSequence;
        if ( nSequence < 0 || nSequence >= v8->numlocalseq )
          v9 = 0;
        v6 = (mstudioseqdesc_t *)((char *)v8 + 212 * v9 + v8->localseqindex);
      }
      szactivitynameindex = v6->szlabelindex;
    }
    V_snprintf(
      pDest: buffer,
      maxLen: bufferLength,
      pFormat: "[%d] %s",
      nSequence,
      (const char *)v6 + szactivitynameindex);
  }
  else if ( g_viewerSettings.showActivities )
  {
    if ( hdr->m_pVModel != nullptr )
    {
      v12 = CStudioHdr::pSeqdesc_Internal(this: hdr, i: nSequence);
    }
    else
    {
      v10 = nSequence;
      v11 = hdr->m_pStudioHdr;
      if ( nSequence < 0 || nSequence >= v11->numlocalseq )
        v10 = 0;
      v12 = (mstudioseqdesc_t *)((char *)v11 + 212 * v10 + v11->localseqindex);
    }
    V_strncpy(pDest: buffer, pSrc: (const char *)v12 + v12->szactivitynameindex, maxLen: bufferLength);
  }
  else
  {
    if ( hdr->m_pVModel != nullptr )
    {
      v15 = CStudioHdr::pSeqdesc_Internal(this: hdr, i: nSequence);
    }
    else
    {
      v13 = nSequence;
      v14 = hdr->m_pStudioHdr;
      if ( nSequence < 0 || nSequence >= v14->numlocalseq )
        v13 = 0;
      v15 = (mstudioseqdesc_t *)((char *)v14 + 212 * v13 + v14->localseqindex);
    }
    V_strncpy(pDest: buffer, pSrc: (const char *)v15 + v15->szlabelindex, maxLen: bufferLength);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403360
// Name: int SortSequenceFunc(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortSequenceFunc(const void *p1, const void *p2)
{
  int v2; // eax
  int v3; // ecx

  v2 = *((_DWORD *)p1 + 65);
  v3 = *((_DWORD *)p2 + 65);
  if ( v2 < v3 )
    return -10000;
  if ( v2 <= v3 )
    return _V_stricmp(s1: (const char *)p1 + 4, s2: (const char *)p2 + 4);
  return 10000;
}

//------------------------------------------------------------------------------
// Address: 0x004033A0
// Name: public: void ControlPanel::CreateSortedSequenceList(class CStudioHdr __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::CreateSortedSequenceList(ControlPanel *this, CStudioHdr *hdr, int *pSequence)
{
  CStudioHdr *v3; // ebx
  signed int numlocalseq; // edi
  SortInfo_t *v5; // eax
  SortInfo_t *v6; // edx
  int v7; // esi
  char *p_m_nType; // edi
  const char *KeyValueText; // ebx
  KeyValues *v10; // eax
  bool v11; // al
  KeyValues *Key; // eax
  const char *String; // ebx
  signed int v14; // eax
  int *p_m_nSequence; // ecx
  SortInfo_t *pSort; // [esp+Ch] [ebp-Ch]
  int nSequenceCount; // [esp+10h] [ebp-8h]
  KeyValues *pKeyValues; // [esp+14h] [ebp-4h]

  v3 = hdr;
  if ( hdr->m_pVModel != nullptr )
  {
    nSequenceCount = CStudioHdr::GetNumSeq_Internal(this: hdr);
    numlocalseq = nSequenceCount;
  }
  else
  {
    numlocalseq = hdr->m_pStudioHdr->numlocalseq;
    nSequenceCount = numlocalseq;
  }
  v5 = (SortInfo_t *)operator new(nSize: 264 * numlocalseq);
  v6 = v5;
  v7 = 0;
  pSort = v5;
  if ( numlocalseq > 0 )
  {
    p_m_nType = (char *)&v5->m_nType;
    while ( 1 )
    {
      *((_DWORD *)p_m_nType - 65) = v7;
      ComposeSequenceDisplayName(hdr: v3, nSequence: v7, buffer: p_m_nType - 256, bufferLength: 256);
      *(_DWORD *)p_m_nType = 0;
      KeyValueText = Studio_GetKeyValueText(pStudioHdr: v3, iSequence: v7);
      if ( KeyValueText != nullptr )
      {
        v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v10 != nullptr )
        {
          pKeyValues = KeyValues::KeyValues(this: v10, setName: "sort");
          v11 = KeyValues::LoadFromBuffer(
                  this: pKeyValues,
                  resourceName: "mdl",
                  pBuffer: KeyValueText,
                  pFileSystem: nullptr,
                  pPathID: nullptr,
                  pfnEvaluateSymbolProc: nullptr);
        }
        else
        {
          pKeyValues = nullptr;
          v11 = KeyValues::LoadFromBuffer(
                  this: nullptr,
                  resourceName: "mdl",
                  pBuffer: KeyValueText,
                  pFileSystem: nullptr,
                  pPathID: nullptr,
                  pfnEvaluateSymbolProc: nullptr);
        }
        if ( v11 )
        {
          Key = KeyValues::FindKey(this: pKeyValues, keyName: "faceposer", bCreate: false);
          if ( Key != nullptr )
          {
            String = KeyValues::GetString(this: Key, keyName: "type", defaultValue: WindowName);
            if ( _V_stricmp(s1: String, s2: "posture") != 0 )
            {
              if ( _V_stricmp(s1: String, s2: "gesture") == 0 )
                *(_DWORD *)p_m_nType = 1;
            }
            else
            {
              *(_DWORD *)p_m_nType = 2;
            }
          }
        }
        KeyValues::deleteThis(this: pKeyValues);
      }
      ++v7;
      p_m_nType += 264;
      if ( v7 >= nSequenceCount )
        break;
      v3 = hdr;
    }
    numlocalseq = nSequenceCount;
    v6 = pSort;
  }
  if ( g_viewerSettings.sortSequences )
  {
    qsort(base: v6, num: numlocalseq, width: 0x108u, comp: SortSequenceFunc);
    v6 = pSort;
  }
  v14 = 0;
  if ( numlocalseq > 0 )
  {
    p_m_nSequence = &v6->m_nSequence;
    do
    {
      pSequence[v14++] = *p_m_nSequence;
      p_m_nSequence += 66;
    }
    while ( v14 < numlocalseq );
  }
  free(pMem: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00403540
// Name: public: void ControlPanel::updateGroundSpeed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::updateGroundSpeed(ControlPanel *this)
{
  double CurrentVelocity; // st7
  char sz[100]; // [esp+Ch] [ebp-64h] BYREF

  CurrentVelocity = StudioModel::GetCurrentVelocity(this: g_pStudioModel);
  sprintf(string: sz, format: "Speed: %.2f", CurrentVelocity);
  mxWidget::setLabel(this: this->laGroundSpeed, format: sz);
}

//------------------------------------------------------------------------------
// Address: 0x00403580
// Name: public: void ControlPanel::updateTransitionAmount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::updateTransitionAmount(ControlPanel *this)
{
  double TransitionAmount; // st7
  char sz[256]; // [esp+Ch] [ebp-100h] BYREF

  TransitionAmount = StudioModel::GetTransitionAmount(this: g_pStudioModel);
  sprintf(string: sz, format: "%.3f %%", TransitionAmount * 100.0);
  mxWidget::setLabel(this: this->laBlendAmount, format: sz);
}

//------------------------------------------------------------------------------
// Address: 0x004035D0
// Name: public: int ControlPanel::getFrameSelection(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ControlPanel::getFrameSelection(ControlPanel *this)
{
  int v1; // esi
  mxRadioButton **i; // edi

  v1 = 0;
  for ( i = this->rbFrameSelection; !mxRadioButton::isChecked(this: *i); ++i )
  {
    if ( ++v1 >= 5 )
      return 0;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00403600
// Name: public: void ControlPanel::setFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setFrame(ControlPanel *this, float frame)
{
  int v3; // esi
  mxRadioButton **rbFrameSelection; // edi
  int v5; // eax
  char buf[128]; // [esp+Ch] [ebp-80h] BYREF

  v3 = 0;
  rbFrameSelection = this->rbFrameSelection;
  while ( !mxRadioButton::isChecked(this: *rbFrameSelection) )
  {
    ++v3;
    ++rbFrameSelection;
    if ( v3 >= 5 )
    {
      v3 = 0;
      break;
    }
  }
  v5 = StudioModel::SetFrame(this: g_pStudioModel, iLayer: v3, (int)frame);
  sprintf(string: buf, format: "%3d", v5);
  mxWidget::setLabel(this: this->lForcedFrame, format: buf);
}

//------------------------------------------------------------------------------
// Address: 0x00403670
// Name: public: void ControlPanel::updateFrameSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::updateFrameSelection(ControlPanel *this)
{
  int v2; // esi
  mxRadioButton **rbFrameSelection; // edi
  int MaxFrame; // eax

  v2 = 0;
  rbFrameSelection = this->rbFrameSelection;
  while ( !mxRadioButton::isChecked(this: *rbFrameSelection) )
  {
    ++v2;
    ++rbFrameSelection;
    if ( v2 >= 5 )
    {
      v2 = 0;
      break;
    }
  }
  MaxFrame = StudioModel::GetMaxFrame(this: g_pStudioModel, iLayer: v2);
  mxSlider::setRange(this: this->slForceFrame, min: 0.0, max: (float)MaxFrame, ticks: MaxFrame);
  mxSlider::setSteps(this: this->slForceFrame, line: 1, page: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004036E0
// Name: public: void ControlPanel::UpdateEventHistory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::UpdateEventHistory(ControlPanel *this)
{
  int v2; // esi
  mxRadioButton **rbFrameSelection; // ebx
  StudioModel *v4; // ecx
  CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr **p_m_pStudioHdr; // ebx
  const studiohdr_t *v7; // eax
  CStudioHdr *v8; // ebx
  int v9; // esi
  int v10; // eax
  mstudioseqdesc_t *v11; // eax
  float v12; // xmm2_4
  int v13; // esi
  float m_lastEventCycle; // xmm1_4
  float v15; // xmm0_4
  char *v16; // esi
  bool v17; // cl
  const char *v18; // ebx
  int ItemCount; // eax
  char buf[128]; // [esp+1Ch] [ebp-98h] BYREF
  mstudioseqdesc_t *desc; // [esp+9Ch] [ebp-18h]
  int i; // [esp+A0h] [ebp-14h]
  float cycle; // [esp+A4h] [ebp-10h]
  int v24; // [esp+A8h] [ebp-Ch]
  int sequence; // [esp+ACh] [ebp-8h]
  CStudioHdr *hdr; // [esp+B0h] [ebp-4h]

  v2 = 0;
  rbFrameSelection = this->rbFrameSelection;
  while ( !mxRadioButton::isChecked(this: *rbFrameSelection) )
  {
    ++v2;
    ++rbFrameSelection;
    if ( v2 >= 5 )
    {
      v2 = 0;
      break;
    }
  }
  cycle = StudioModel::GetCycle(this: g_pStudioModel, iLayer: v2);
  v4 = g_pStudioModel;
  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    hdr = g_pStudioModel->m_pStudioHdr;
    v8 = m_pStudioHdr;
  }
  else
  {
    v7 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: g_pStudioModel->m_MDLHandle);
    CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v7, mdlcache: nullptr);
    v8 = *p_m_pStudioHdr;
    if ( v8->m_pStudioHdr == nullptr )
      return;
    v4 = g_pStudioModel;
    hdr = v8;
  }
  if ( v8 != nullptr )
  {
    if ( v2 != 0 )
    {
      sequence = StudioModel::GetOverlaySequence(this: v4, iLayer: v2 - 1);
      v9 = sequence;
    }
    else
    {
      v9 = StudioModel::GetSequence(this: v4);
      sequence = v9;
    }
    if ( CStudioHdr::SequencesAvailable(this: v8) && v9 >= 0 )
    {
      v10 = v8->m_pVModel != nullptr ? CStudioHdr::GetNumSeq_Internal(this: v8) : v8->m_pStudioHdr->numlocalseq;
      if ( v9 < v10 )
      {
        v11 = CStudioHdr::pSeqdesc(this: v8, iSequence: v9);
        v12 = cycle;
        desc = v11;
        i = 0;
        if ( v11->numevents > 0 )
        {
          v24 = 0;
          while ( 1 )
          {
            v13 = v24 + v11->eventindex;
            m_lastEventCycle = this->m_lastEventCycle;
            v15 = *(float *)((char *)&v11->baseptr + v13);
            v16 = (char *)v11 + v13;
            v17 = false;
            if ( v12 < m_lastEventCycle )
              break;
            if ( v15 >= m_lastEventCycle && v12 > v15 )
              goto LABEL_31;
LABEL_34:
            v24 += 80;
            if ( ++i >= v11->numevents )
              goto LABEL_35;
          }
          if ( v15 >= m_lastEventCycle )
            v17 = v15 < 1.0;
          if ( (v15 < 0.0 || v12 <= v15) && !v17 )
            goto LABEL_34;
LABEL_31:
          v18 = &v16[*((_DWORD *)v16 + 19)];
          while ( mxListBox::getItemCount(this: this->lbEventHistory) > 10 )
            mxListBox::remove(this: this->lbEventHistory, index: 0);
          sprintf(string: buf, format: "%.2f: %s %s", *(float *)v16, v18, v16 + 12);
          mxListBox::add(this: this->lbEventHistory, item: buf);
          ItemCount = mxListBox::getItemCount(this: this->lbEventHistory);
          mxListBox::select(this: this->lbEventHistory, index: ItemCount - 1);
          ComposeSequenceDisplayName(hdr, nSequence: sequence, buffer: buf, bufferLength: 128);
          mxWidget::setLabel(this: this->lEventSequence, format: "%s", buf);
          v12 = cycle;
          v11 = desc;
          goto LABEL_34;
        }
LABEL_35:
        this->m_lastEventCycle = v12;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403930
// Name: public: void ControlPanel::setBlend(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setBlend(ControlPanel *this, int index, float value)
{
  double CurrentVelocity; // st7
  char string[100]; // [esp+Ch] [ebp-64h] BYREF

  StudioModel::SetPoseParameter(this: g_pStudioModel, iParameter: index, flValue: value);
  ControlPanel::updateFrameSelection(this);
  CurrentVelocity = StudioModel::GetCurrentVelocity(this: g_pStudioModel);
  sprintf(string, format: "Speed: %.2f", CurrentVelocity);
  mxWidget::setLabel(this: this->laGroundSpeed, format: string);
}

//------------------------------------------------------------------------------
// Address: 0x004039A0
// Name: public: void ControlPanel::initBodypartChoices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::initBodypartChoices(ControlPanel *this)
{
  CStudioHdr *m_pStudioHdr; // ebx
  CStudioHdr **p_m_pStudioHdr; // esi
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  mxChoice *cBodypart; // ecx
  mstudiobodyparts_t *v7; // esi
  const studiohdr_t *v8; // edx
  int v9; // eax
  int v10; // esi
  char str[64]; // [esp+Ch] [ebp-48h] BYREF
  mstudiobodyparts_t *pbodyparts; // [esp+4Ch] [ebp-8h]
  int i; // [esp+50h] [ebp-4h]

  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
      CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
      v5 = *p_m_pStudioHdr;
      if ( v5->m_pStudioHdr == nullptr )
        return;
      m_pStudioHdr = v5;
    }
    if ( m_pStudioHdr != nullptr )
    {
      cBodypart = this->cBodypart;
      v7 = (mstudiobodyparts_t *)((char *)m_pStudioHdr->m_pStudioHdr + m_pStudioHdr->m_pStudioHdr->bodypartindex);
      pbodyparts = v7;
      mxChoice::removeAll(this: cBodypart);
      if ( m_pStudioHdr->m_pStudioHdr->numbodyparts > 0 )
      {
        i = 0;
        do
        {
          mxChoice::add(this: this->cBodypart, item: (const char *)v7 + v7->sznameindex);
          v8 = m_pStudioHdr->m_pStudioHdr;
          ++v7;
          ++i;
        }
        while ( i < v8->numbodyparts );
        mxChoice::select(this: this->cBodypart, index: 0);
        mxChoice::removeAll(this: this->cSubmodel);
        v9 = 0;
        if ( pbodyparts->nummodels > 0 )
        {
          do
          {
            v10 = v9 + 1;
            sprintf(string: str, format: "Submodel %d", v9 + 1);
            mxChoice::add(this: this->cSubmodel, item: str);
            v9 = v10;
          }
          while ( v10 < pbodyparts->nummodels );
        }
        mxChoice::select(this: this->cSubmodel, index: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403AC0
// Name: public: void ControlPanel::initPhysicsBones(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::initPhysicsBones(ControlPanel *this)
{
  int i; // esi
  const char *BoneName; // eax

  mxChoice::removeAll(this: this->cHighlightBone);
  mxChoice::add(this: this->cHighlightBone, item: "None");
  for ( i = 0; i < StudioModel::Physics_GetBoneCount(this: g_pStudioModel); ++i )
  {
    BoneName = StudioModel::Physics_GetBoneName(this: g_pStudioModel, index: i);
    mxChoice::add(this: this->cHighlightBone, item: BoneName);
  }
  mxChoice::select(this: this->cHighlightBone, index: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00403B30
// Name: public: void ControlPanel::initIncludedModels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::initIncludedModels(ControlPanel *this)
{
  int NumIncludeModels; // ebx
  int i; // edi
  const char *IncludeModelName; // eax

  mxChoice::removeAll(this: this->cIncludedModels);
  mxChoice::add(this: this->cIncludedModels, item: "Included Models");
  mxChoice::add(this: this->cIncludedModels, item: "---------------");
  NumIncludeModels = StudioModel::GetNumIncludeModels(this: g_pStudioModel);
  for ( i = 0; i < NumIncludeModels; ++i )
  {
    IncludeModelName = StudioModel::GetIncludeModelName(this: g_pStudioModel, index: i);
    mxChoice::add(this: this->cIncludedModels, item: IncludeModelName);
  }
  mxChoice::select(this: this->cIncludedModels, index: 0);
  mxWidget::setEnabled(this: this->cIncludedModels, b: NumIncludeModels > 0);
}

//------------------------------------------------------------------------------
// Address: 0x00403BB0
// Name: public: void ControlPanel::initBoneControllers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::initBoneControllers(ControlPanel *this)
{
  CStudioHdr *m_pStudioHdr; // esi
  CStudioHdr **p_m_pStudioHdr; // ebx
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // ebx
  const studiohdr_t *v6; // eax
  int v7; // ebx
  char str[32]; // [esp+1Ch] [ebp-24h] BYREF
  int v9; // [esp+3Ch] [ebp-4h]

  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
      CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
      v5 = *p_m_pStudioHdr;
      if ( v5->m_pStudioHdr == nullptr )
        return;
      m_pStudioHdr = v5;
    }
    if ( m_pStudioHdr != nullptr )
    {
      mxWidget::setEnabled(this: this->cController, b: m_pStudioHdr->m_pStudioHdr->numbonecontrollers > 0);
      mxWidget::setEnabled(this: this->slController, b: m_pStudioHdr->m_pStudioHdr->numbonecontrollers > 0);
      mxChoice::removeAll(this: this->cController);
      v6 = m_pStudioHdr->m_pStudioHdr;
      v7 = 0;
      if ( m_pStudioHdr->m_pStudioHdr->numbonecontrollers > 0 )
      {
        v9 = 0;
        do
        {
          sprintf(string: str, format: "Controller %d", *(_DWORD *)&v6->name[v9 + 8 + v6->bonecontrollerindex]);
          mxChoice::add(this: this->cController, item: str);
          v6 = m_pStudioHdr->m_pStudioHdr;
          v9 += 56;
          ++v7;
        }
        while ( v7 < v6->numbonecontrollers );
      }
      if ( m_pStudioHdr->m_pStudioHdr->numbonecontrollers > 0 )
      {
        mxChoice::select(this: this->cController, index: 0);
        mxSlider::setRange(
          this: this->slController,
          min: *(float *)((char *)&m_pStudioHdr->m_pStudioHdr->checksum + m_pStudioHdr->m_pStudioHdr->bonecontrollerindex),
          max: *(float *)&m_pStudioHdr->m_pStudioHdr->name[m_pStudioHdr->m_pStudioHdr->bonecontrollerindex],
          ticks: 100);
        mxSlider::setValue(this: this->slController, value: 0.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403D00
// Name: public: void ControlPanel::setBoneController(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setBoneController(ControlPanel *this, int index)
{
  CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr **p_m_pStudioHdr; // esi
  const studiohdr_t *v5; // eax
  CStudioHdr *v6; // esi
  const studiohdr_t *v7; // ecx
  int v8; // eax

  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
      CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
      v6 = *p_m_pStudioHdr;
      if ( v6->m_pStudioHdr == nullptr )
        return;
      m_pStudioHdr = v6;
    }
    if ( m_pStudioHdr != nullptr )
    {
      v7 = m_pStudioHdr->m_pStudioHdr;
      v8 = m_pStudioHdr->m_pStudioHdr->bonecontrollerindex + 56 * index;
      mxSlider::setRange(
        this: this->slController,
        min: *(float *)((char *)&v7->checksum + v8),
        max: *(float *)&v7->name[v8],
        ticks: 100);
      mxSlider::setValue(this: this->slController, value: 0.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403DB0
// Name: public: void ControlPanel::setBoneControllerValue(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setBoneControllerValue(ControlPanel *this, int index, float value)
{
  StudioModel *v3; // ecx
  CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr **p_m_pStudioHdr; // esi
  const studiohdr_t *v6; // eax
  CStudioHdr *v7; // esi

  v3 = g_pStudioModel;
  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v6 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: g_pStudioModel->m_MDLHandle);
      CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v6, mdlcache: nullptr);
      v7 = *p_m_pStudioHdr;
      if ( v7->m_pStudioHdr == nullptr )
        return;
      v3 = g_pStudioModel;
      m_pStudioHdr = v7;
    }
    if ( m_pStudioHdr != nullptr )
      StudioModel::SetController(
        this: v3,
        iController: *(_DWORD *)&m_pStudioHdr->m_pStudioHdr->name[56 * index + 8 + m_pStudioHdr->m_pStudioHdr->bonecontrollerindex],
        flValue: value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403E30
// Name: public: void ControlPanel::initSkinChoices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::initSkinChoices(ControlPanel *this)
{
  CStudioHdr **p_m_pStudioHdr; // esi
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  int v6; // eax
  int v7; // esi
  char str[32]; // [esp+Ch] [ebp-20h] BYREF

  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
      CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
      v5 = *p_m_pStudioHdr;
      if ( v5->m_pStudioHdr == nullptr )
        return;
      m_pStudioHdr = v5;
    }
    if ( m_pStudioHdr != nullptr )
    {
      mxWidget::setEnabled(this: this->cSkin, b: m_pStudioHdr->m_pStudioHdr->numskinfamilies > 0);
      mxChoice::removeAll(this: this->cSkin);
      v6 = 0;
      if ( m_pStudioHdr->m_pStudioHdr->numskinfamilies > 0 )
      {
        do
        {
          v7 = v6 + 1;
          sprintf(string: str, format: "Skin %d", v6 + 1);
          mxChoice::add(this: this->cSkin, item: str);
          v6 = v7;
        }
        while ( v7 < m_pStudioHdr->m_pStudioHdr->numskinfamilies );
      }
      mxChoice::select(this: this->cSkin, index: 0);
      StudioModel::SetSkin(this: g_pStudioModel, iValue: 0);
      g_viewerSettings.skin = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403F20
// Name: public: void ControlPanel::initMaterialChoices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::initMaterialChoices(ControlPanel *this)
{
  CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr **p_m_pStudioHdr; // esi
  ControlPanel *v3; // ebx
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  const studiohdr_t *v6; // esi
  int v7; // edi
  int v8; // ebx
  char str[512]; // [esp+8h] [ebp-204h] BYREF
  ControlPanel *v10; // [esp+208h] [ebp-4h]

  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  v3 = this;
  v10 = this;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
      CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
      v5 = *p_m_pStudioHdr;
      if ( v5->m_pStudioHdr == nullptr )
        return;
      m_pStudioHdr = v5;
    }
    if ( m_pStudioHdr != nullptr )
    {
      v6 = m_pStudioHdr->m_pStudioHdr;
      if ( m_pStudioHdr->m_pStudioHdr != nullptr )
      {
        mxWidget::setEnabled(this: v3->cMaterials, b: v6->numtextures > 0);
        mxChoice::removeAll(this: v3->cMaterials);
        v7 = 0;
        if ( v6->numtextures > 0 )
        {
          v8 = 0;
          do
          {
            sprintf(
              string: str,
              format: "%s",
              (const char *)v6 + v8 + v6->textureindex + *(int *)((char *)&v6->id + v8 + v6->textureindex));
            mxChoice::add(this: v10->cMaterials, item: str);
            ++v7;
            v8 += 64;
          }
          while ( v7 < v6->numtextures );
          v3 = v10;
        }
        mxChoice::select(this: v3->cMaterials, index: 0);
        g_viewerSettings.materialIndex = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404030
// Name: public: void ControlPanel::showActivityModifiers(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::showActivityModifiers(ControlPanel *this, int sequence)
{
  CStudioHdr *m_pStudioHdr; // esi
  CStudioHdr **p_m_pStudioHdr; // edi
  const studiohdr_t *v5; // eax
  int v6; // eax
  const studiohdr_t *v7; // esi
  int v8; // eax
  mstudioseqdesc_t *v9; // esi
  int i; // edi
  int activitymodifierindex; // eax
  _DWORD *v12; // eax
  const char *v13; // eax
  char str[512]; // [esp+Ch] [ebp-200h] BYREF

  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
    CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    m_pStudioHdr = (*p_m_pStudioHdr)->m_pStudioHdr != nullptr ? *p_m_pStudioHdr : nullptr;
  }
  if ( CStudioHdr::SequencesAvailable(this: m_pStudioHdr) && sequence >= 0 )
  {
    v6 = m_pStudioHdr->m_pVModel != nullptr
       ? CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr)
       : m_pStudioHdr->m_pStudioHdr->numlocalseq;
    if ( sequence < v6 )
    {
      if ( m_pStudioHdr->m_pVModel != nullptr )
      {
        v9 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: sequence);
      }
      else
      {
        v7 = m_pStudioHdr->m_pStudioHdr;
        v8 = sequence;
        if ( sequence >= v7->numlocalseq )
          v8 = 0;
        v9 = (mstudioseqdesc_t *)((char *)v7 + 212 * v8 + v7->localseqindex);
      }
      mxWidget::setEnabled(this: this->cActivityModifiers, b: v9->numactivitymodifiers > 0);
      mxChoice::removeAll(this: this->cActivityModifiers);
      for ( i = 0; i < v9->numactivitymodifiers; ++i )
      {
        activitymodifierindex = v9->activitymodifierindex;
        if ( activitymodifierindex != 0 )
          v12 = (int *)((char *)&v9->baseptr + 4 * i + activitymodifierindex);
        else
          v12 = nullptr;
        if ( *v12 != 0 )
          v13 = (char *)v12 + *v12;
        else
          v13 = nullptr;
        sprintf(string: str, format: "%s", v13);
        mxChoice::add(this: this->cActivityModifiers, item: str);
      }
      mxChoice::select(this: this->cActivityModifiers, index: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404180
// Name: public: void ControlPanel::UpdateMaterialList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::UpdateMaterialList(ControlPanel *this)
{
  studiohdr_t *v2; // eax
  int v3; // edi
  int i; // esi
  const char *v5; // [esp-14h] [ebp-318h]
  IMaterial *pMaterials[128]; // [esp+4h] [ebp-300h] BYREF
  char c_MaterialLine[256]; // [esp+204h] [ebp-100h] BYREF

  mxListBox::removeAll(this: this->cMessageList);
  v2 = (studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
  if ( v2 != nullptr )
  {
    v3 = g_pStudioRender->GetMaterialList(this: g_pStudioRender, a2: v2, a3: 128, a4: pMaterials);
    for ( i = 0; i < v3; ++i )
    {
      _V_strcpy(dest: c_MaterialLine, src: WindowName);
      if ( pMaterials[i]->IsErrorMaterial(this: pMaterials[i]) )
      {
        V_strncat(
          pDest: c_MaterialLine,
          pSrc: "*** ERROR *** Model attempted to load one or more VMTs it can't find.",
          destBufferSize: 0x100u,
          max_chars_to_copy: -1);
      }
      else
      {
        v5 = (const char *)pMaterials[i]->GetName(this: pMaterials[i]);
        V_strncat(pDest: c_MaterialLine, pSrc: v5, destBufferSize: 0x100u, max_chars_to_copy: -1);
      }
      mxListBox::add(this: this->cMessageList, item: c_MaterialLine);
    }
    this->m_bVMTInfoLoaded = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404270
// Name: public: void ControlPanel::centerVerts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::centerVerts(ControlPanel *this)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  Vector vecMin; // [esp+0h] [ebp-24h] BYREF
  Vector vecMax; // [esp+Ch] [ebp-18h] BYREF
  Vector in; // [esp+18h] [ebp-Ch] BYREF

  g_pStudioModel->m_origin.x = 0.0;
  g_pStudioModel->m_origin.y = 0.0;
  g_pStudioModel->m_origin.z = 0.0;
  AngleMatrix(angles: &g_pStudioModel->m_angles, matrix: &g_viewtransform);
  v2 = -g_pStudioModel->m_origin.y;
  v3 = -g_pStudioModel->m_origin.z;
  in.x = -g_pStudioModel->m_origin.x;
  in.y = v2;
  in.z = v3;
  MatrixSetColumn(&in, column: 3, out: &g_viewtransform);
  StudioModel::ExtractVertExtents(this: g_pStudioModel, &vecMin, &vecMax);
  g_pStudioModel->m_origin.x = vecMax.x;
  g_pStudioModel->m_origin.y = (float)(vecMin.y + vecMax.y) * 0.5;
  g_pStudioModel->m_origin.z = (float)(vecMin.z + vecMax.z) * 0.5;
  AngleMatrix(angles: &g_pStudioModel->m_angles, matrix: &g_viewtransform);
  v4 = -g_pStudioModel->m_origin.y;
  v5 = -g_pStudioModel->m_origin.z;
  in.x = -g_pStudioModel->m_origin.x;
  in.y = v4;
  in.z = v5;
  MatrixSetColumn(&in, column: 3, out: &g_viewtransform);
  this->d_MatSysWindow->redraw(this: this->d_MatSysWindow);
}

//------------------------------------------------------------------------------
// Address: 0x004043C0
// Name: public: void ControlPanel::MapExtraFlexes(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::MapExtraFlexes(ControlPanel *this, unsigned int nSlot)
{
  StudioModel *v2; // ecx
  CStudioHdr *StudioHdr; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  int v5; // edx
  int v6; // esi

  if ( nSlot < 0xC )
  {
    v2 = g_pStudioExtraModel[nSlot];
    if ( v2 != nullptr )
    {
      StudioHdr = StudioModel::GetStudioHdr(this: v2);
      if ( StudioHdr != nullptr )
      {
        m_pStudioHdr = StudioHdr->m_pStudioHdr;
        v5 = 0;
        if ( StudioHdr->m_pStudioHdr->numflexcontrollers > 0 )
        {
          v6 = 0;
          do
          {
            *(int *)((char *)&m_pStudioHdr->checksum + v6 + m_pStudioHdr->flexcontrollerindex) = v5;
            m_pStudioHdr = StudioHdr->m_pStudioHdr;
            ++v5;
            v6 += 20;
          }
          while ( v5 < StudioHdr->m_pStudioHdr->numflexcontrollers );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404420
// Name: public: void ControlPanel::initFlexes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::initFlexes(ControlPanel *this)
{
  CStudioHdr *m_pStudioHdr; // esi
  CStudioHdr **p_m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // edi
  mxChoice **cFlex; // ebx
  const studiohdr_t *v7; // ecx
  int v8; // edi
  LocalFlexController_t v9; // edi
  int v10; // ebx
  mxSlider **slFlexScale; // esi
  int i; // edi
  LocalFlexController_t SelectedIndex; // eax
  float flValue; // [esp+4h] [ebp-1Ch]
  int j; // [esp+18h] [ebp-8h]
  int v17; // [esp+1Ch] [ebp-4h]

  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
      CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
      v5 = *p_m_pStudioHdr;
      if ( v5->m_pStudioHdr == nullptr )
      {
        m_pStudioHdr = nullptr;
        goto LABEL_11;
      }
      m_pStudioHdr = v5;
    }
    if ( m_pStudioHdr != nullptr )
    {
      j = 0;
      cFlex = this->cFlex;
      do
      {
        mxChoice::removeAll(this: *cFlex);
        v7 = m_pStudioHdr->m_pStudioHdr;
        v8 = 0;
        if ( m_pStudioHdr->m_pStudioHdr->numflexcontrollers > 0 )
        {
          v17 = 0;
          do
          {
            mxChoice::add(
              this: *cFlex,
              item: (const char *)v7
            + v17
            + v7->flexcontrollerindex
            + *(int *)((char *)&v7->version + v17 + v7->flexcontrollerindex));
            v7 = m_pStudioHdr->m_pStudioHdr;
            v17 += 20;
            ++v8;
          }
          while ( v8 < m_pStudioHdr->m_pStudioHdr->numflexcontrollers );
        }
        mxChoice::select(this: *cFlex++, index: m_pStudioHdr->m_pStudioHdr->numflexcontrollers + j++ - 48);
      }
      while ( j < 48 );
    }
  }
LABEL_11:
  v9 = DUMMY_NULL_FLEX_CONTROLLER;
  if ( m_pStudioHdr->m_pStudioHdr->numflexcontrollers > 0 )
  {
    v10 = 0;
    do
    {
      StudioModel::SetFlexController(this: g_pStudioModel, iFlex: v9, flValue: 0.0);
      *(int *)((char *)&m_pStudioHdr->m_pStudioHdr->checksum + v10 + m_pStudioHdr->m_pStudioHdr->flexcontrollerindex) = v9++;
      v10 += 20;
    }
    while ( v9 < m_pStudioHdr->m_pStudioHdr->numflexcontrollers );
  }
  slFlexScale = this->slFlexScale;
  for ( i = 48; i != 0; --i )
  {
    SelectedIndex = mxChoice::getSelectedIndex(this: (mxChoice *)*(slFlexScale - 48));
    if ( SelectedIndex >= DUMMY_NULL_FLEX_CONTROLLER )
    {
      flValue = StudioModel::GetFlexControllerRaw(this: g_pStudioModel, iFlex: SelectedIndex);
      mxSlider::setValue(this: *slFlexScale, value: flValue);
    }
    ++slFlexScale;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404580
// Name: UpdateSliderLabel
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateSliderLabel(mxLabel *label)
{
  mxSlider *slider; // ecx
  double Value; // st7
  char buf[80]; // [esp+8h] [ebp-50h] BYREF

  Value = mxSlider::getValue(this: slider);
  sprintf(string: buf, format: "%0.2f", Value);
  mxWidget::setLabel(this: label, format: buf);
}

//------------------------------------------------------------------------------
// Address: 0x004045C0
// Name: public: void ControlPanel::UpdateConstraintSliders(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::UpdateConstraintSliders(ControlPanel *this, int clamp)
{
  float value; // xmm0_4
  float v4; // xmm1_4
  mxLabel *lPhysicsConMin; // edi
  double v6; // st7
  mxLabel *lPhysicsConMax; // edi
  double v8; // st7
  mxLabel *lPhysicsFriction; // edi
  double v10; // st7
  char string[80]; // [esp+10h] [ebp-58h] BYREF
  float vmin; // [esp+60h] [ebp-8h]
  float vmax; // [esp+64h] [ebp-4h]

  vmin = mxSlider::getValue(this: this->slPhysicsConMin);
  vmax = mxSlider::getValue(this: this->slPhysicsConMax);
  value = vmin;
  if ( mxRadioButton::isChecked(this: (mxRadioButton *)this->cbLinked) )
  {
    if ( clamp == 7504 && vmin <= 0.0 )
    {
      LODWORD(v4) = LODWORD(vmin) ^ _mask__NegFloat_;
      LODWORD(vmax) = LODWORD(vmin) ^ _mask__NegFloat_;
    }
    else
    {
      v4 = vmax;
      if ( vmax >= 0.0 )
        LODWORD(value) = LODWORD(vmax) ^ _mask__NegFloat_;
    }
  }
  else
  {
    v4 = vmax;
  }
  if ( value > v4 )
  {
    if ( clamp == 7504 )
      value = v4;
    else
      vmax = value;
  }
  mxSlider::setValue(this: this->slPhysicsConMin, value);
  mxSlider::setValue(this: this->slPhysicsConMax, value: vmax);
  lPhysicsConMin = this->lPhysicsConMin;
  v6 = mxSlider::getValue(this: this->slPhysicsConMin);
  sprintf(string, format: "%0.2f", v6);
  mxWidget::setLabel(this: lPhysicsConMin, format: string);
  lPhysicsConMax = this->lPhysicsConMax;
  v8 = mxSlider::getValue(this: this->slPhysicsConMax);
  sprintf(string, format: "%0.2f", v8);
  mxWidget::setLabel(this: lPhysicsConMax, format: string);
  lPhysicsFriction = this->lPhysicsFriction;
  v10 = mxSlider::getValue(this: this->slPhysicsFriction);
  sprintf(string, format: "%0.2f", v10);
  mxWidget::setLabel(this: lPhysicsFriction, format: string);
}

//------------------------------------------------------------------------------
// Address: 0x00404720
// Name: public: int ControlPanel::getPhysicsAxis(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ControlPanel::getPhysicsAxis(ControlPanel *this)
{
  int v1; // esi
  mxRadioButton **i; // edi

  v1 = 0;
  for ( i = this->rbConstraintAxis; !mxRadioButton::isChecked(this: *i); ++i )
  {
    if ( ++v1 >= 3 )
      return 0;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00404750
// Name: public: void ControlPanel::SaveSelectedSequences(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::SaveSelectedSequences(ControlPanel *this)
{
  int v1; // edi
  int **iSelectionToSequence; // esi

  v1 = 0;
  iSelectionToSequence = this->iSelectionToSequence;
  do
  {
    iSelectionToSequence[210] = (int *)(*iSelectionToSequence)[mxChoice::getSelectedIndex(this: (mxChoice *)*(iSelectionToSequence - 17))];
    if ( v1 > 0 )
      *((float *)iSelectionToSequence + 215) = mxSlider::getValue(this: (mxSlider *)*(iSelectionToSequence - 6));
    ++v1;
    ++iSelectionToSequence;
  }
  while ( v1 < 5 );
}

//------------------------------------------------------------------------------
// Address: 0x004047A0
// Name: public: void ControlPanel::SetFrameSlider(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::SetFrameSlider(ControlPanel *this, float flFrame)
{
  mxSlider::setValue(this: this->slForceFrame, value: flFrame);
}

//------------------------------------------------------------------------------
// Address: 0x004047C0
// Name: public: int CValveIpcClientUtl::ExecuteCommand(class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcClientUtl::ExecuteCommand(CValveIpcClientUtl *this, CUtlBuffer *cmd, CUtlBuffer *res)
{
  bool v3; // zf
  unsigned int m_nAllocationCount; // edx
  unsigned __int8 *m_pMemory; // esi
  DWORD m_Put; // edi
  unsigned __int8 *v7; // eax
  void *m_hClientPipe; // ecx
  unsigned int numResBytes; // [esp+8h] [ebp-4h] BYREF

  v3 = this->m_szServerUID == nullptr;
  m_nAllocationCount = res->m_Memory.m_nAllocationCount;
  m_pMemory = res->m_Memory.m_pMemory;
  m_Put = cmd->m_Put;
  v7 = cmd->m_Memory.m_pMemory;
  numResBytes = m_nAllocationCount;
  if ( v3 )
    return 0;
  m_hClientPipe = this->m_hClientPipe;
  if ( m_hClientPipe == nullptr
    || !TransactNamedPipe(
          hNamedPipe: m_hClientPipe,
          lpInBuffer: v7,
          nInBufferSize: m_Put,
          lpOutBuffer: m_pMemory,
          nOutBufferSize: m_nAllocationCount,
          lpBytesRead: &numResBytes,
          lpOverlapped: nullptr)
    && GetLastError() != 234 )
  {
    return 0;
  }
  CUtlBuffer::SeekPut(this: res, type: SEEK_HEAD, offset: numResBytes);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404830
// Name: protected: CValveIpcMgr::~CValveIpcMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CValveIpcMgr::~CValveIpcMgr(CValveIpcMgr *this)
{
  if ( this->m_pMemory != nullptr )
  {
    UnmapViewOfFile(lpBaseAddress: this->m_pMemory);
    this->m_pMemory = nullptr;
  }
  if ( this->m_hMemorySegment != nullptr )
  {
    CloseHandle(hObject: this->m_hMemorySegment);
    this->m_hMemorySegment = nullptr;
  }
  if ( this->m_hMutex != nullptr )
  {
    ReleaseMutex(hMutex: this->m_hMutex);
    CloseHandle(hObject: this->m_hMutex);
    this->m_hMutex = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404880
// Name: public: int CValveIpcMgr::Init(unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcMgr::Init(CValveIpcMgr *this, DWORD dwTimeout)
{
  HANDLE MutexA; // eax
  DWORD v5; // eax
  DWORD v6; // edi
  HANDLE FileMappingA; // eax
  char *v8; // eax

  if ( this->m_pMemory != nullptr )
    return 1;
  MutexA = CreateMutexA(lpMutexAttributes: nullptr, bInitialOwner: false, lpName: "VALVE_IPC_MGR__MTX_1");
  this->m_hMutex = MutexA;
  if ( MutexA != nullptr )
  {
    v5 = WaitForSingleObject(hHandle: MutexA, dwMilliseconds: dwTimeout);
    v6 = v5;
    if ( v5 == 0 || v5 == 128 )
    {
      FileMappingA = CreateFileMappingA(
                       hFile: (HANDLE)0xFFFFFFFF,
                       lpFileMappingAttributes: nullptr,
                       flProtect: 4u,
                       dwMaximumSizeHigh: 0,
                       dwMaximumSizeLow: 0x40000u,
                       lpName: "VALVE_IPC_MGR__MEM_1");
      this->m_hMemorySegment = FileMappingA;
      if ( FileMappingA != nullptr )
      {
        v8 = (char *)MapViewOfFile(
                       hFileMappingObject: FileMappingA,
                       dwDesiredAccess: 0xF001Fu,
                       dwFileOffsetHigh: 0,
                       dwFileOffsetLow: 0,
                       dwNumberOfBytesToMap: 0);
        if ( v8 != nullptr )
        {
          this->m_pMemory = v8;
          return 1;
        }
      }
    }
    if ( v6 == 0 || v6 == 128 )
    {
      ReleaseMutex(hMutex: this->m_hMutex);
      CloseHandle(hObject: this->m_hMutex);
      this->m_hMutex = nullptr;
    }
  }
  CValveIpcMgr::Shutdown(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00404940
// Name: public: int CValveIpcClient::Connect(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CValveIpcClient::Connect(CValveIpcClient *this)
{
  const char **p_m_szServerUID; // esi
  HANDLE v3; // eax
  HANDLE FileA; // eax
  char chPipeName[260]; // [esp+8h] [ebp-218h] BYREF
  char chAliveName[260]; // [esp+10Ch] [ebp-114h] BYREF
  unsigned int dwPipeMode; // [esp+210h] [ebp-10h] BYREF
  CValveIpcMgr mgr; // [esp+214h] [ebp-Ch] BYREF

  p_m_szServerUID = (const char **)&this->m_szServerUID;
  if ( this->m_szServerUID != nullptr )
    return 1;
  memset(&mgr, 0, sizeof(mgr));
  if ( CValveIpcMgr::Init(this: &mgr, dwTimeout: 0x1388u) == 0
    || CValveIpcMgr::DiscoverServer(
         this: &mgr,
         szServerName: this->m_szServerName,
         pszServerUID: (unsigned __int8 **)p_m_szServerUID) == 0 )
  {
LABEL_6:
    CValveIpcMgr::~CValveIpcMgr(this: &mgr);
    return 0;
  }
  sprintf(string: chAliveName, format: "%s_ALIVE_1", *p_m_szServerUID);
  v3 = OpenMutexA(dwDesiredAccess: 0x1F0001u, bInheritHandle: false, lpName: chAliveName);
  if ( v3 == nullptr
    || (CloseHandle(hObject: v3),
        sprintf(string: chPipeName, format: "\\\\.\\pipe\\%s_PIPE_1", *p_m_szServerUID),
        FileA = CreateFileA(
                  lpFileName: chPipeName,
                  dwDesiredAccess: 0xC0000000,
                  dwShareMode: 0,
                  lpSecurityAttributes: nullptr,
                  dwCreationDisposition: 3u,
                  dwFlagsAndAttributes: 0x80000000,
                  hTemplateFile: nullptr),
        this->m_hClientPipe = FileA,
        FileA == nullptr) )
  {
    CValveIpcClient::Disconnect(this);
    goto LABEL_6;
  }
  dwPipeMode = 2;
  SetNamedPipeHandleState(
    hNamedPipe: FileA,
    lpMode: &dwPipeMode,
    lpMaxCollectionCount: nullptr,
    lpCollectDataTimeout: nullptr);
  CValveIpcMgr::~CValveIpcMgr(this: &mgr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404A50
// Name: public: void CBoneControlWindow::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::Init(CBoneControlWindow *this)
{
  mxLabel *v2; // eax
  mxChoice *v3; // eax
  mxChoice *v4; // eax
  mxCheckBox *v5; // eax
  mxCheckBox *v6; // eax
  mxLabel *v7; // eax
  mxChoice *v8; // eax
  mxChoice *v9; // eax
  mxButton *v10; // eax
  mxButton *v11; // eax
  mxCheckBox *v12; // eax
  mxCheckBox *v13; // eax
  mxCheckBox *v14; // eax
  mxCheckBox *v15; // eax
  mxLabel *v16; // eax
  mxChoice *v17; // eax
  mxChoice *v18; // eax
  mxLineEdit *v19; // eax
  mxLineEdit *v20; // eax
  mxButton *v21; // eax
  mxButton *v22; // eax
  mxButton *v23; // eax
  mxButton *v24; // eax
  mxButton *v25; // eax
  mxButton *v26; // eax
  mxLabel *v27; // eax
  mxChoice *v28; // eax
  mxChoice *v29; // eax
  mxCheckBox *v30; // eax
  mxCheckBox *v31; // eax
  mxLabel *v32; // eax
  mxLineEdit *v33; // eax
  mxLineEdit *v34; // eax
  mxLabel *v35; // eax
  mxLineEdit *v36; // eax
  mxLineEdit *v37; // eax
  mxLabel *v38; // eax
  mxLabel *v39; // eax
  mxLabel *v40; // eax
  mxLabel *v41; // eax
  mxLineEdit *v42; // eax
  mxLineEdit *v43; // eax
  mxLineEdit *v44; // eax
  mxLineEdit *v45; // eax
  mxLineEdit *v46; // eax
  mxLineEdit *v47; // eax
  mxLabel *v48; // eax
  mxLabel *v49; // eax
  mxLabel *v50; // eax
  mxLabel *v51; // eax
  mxLineEdit *v52; // eax
  mxLineEdit *v53; // eax
  mxLineEdit *v54; // eax
  mxLineEdit *v55; // eax
  mxLineEdit *v56; // eax
  mxLineEdit *v57; // eax
  mxButton *v58; // eax
  mxButton *v59; // eax
  mxButton *v60; // eax
  mxButton *v61; // eax
  mxButton *v62; // eax
  mxButton *v63; // eax
  mxButton *v64; // eax
  mxButton *v65; // eax
  mxButton *v66; // eax
  mxButton *v67; // eax
  mxButton *v68; // eax
  mxButton *v69; // eax
  mxButton *m_bAddHitbox; // [esp-8h] [ebp-Ch]

  v2 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v2 != nullptr )
    mxLabel::mxLabel(this: v2, parent: this, x: 8, y: 4, w: 30, h: 18, label: "Bone");
  v3 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    v4 = mxChoice::mxChoice(this: v3, parent: this, x: 5, y: 20, w: 260, h: 22, id: 5000);
  else
    v4 = nullptr;
  this->m_cBone = v4;
  mxChoice::add(this: v4, item: "None");
  mxChoice::select(this: this->m_cBone, index: 0);
  mxToolTip::add(widget: this->m_cBone, text: "Select a bone to modify");
  v5 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v5 != nullptr )
    v6 = mxCheckBox::mxCheckBox(this: v5, parent: this, x: 5, y: 45, w: 140, h: 20, label: "Highlight Bone", id: 5002);
  else
    v6 = nullptr;
  this->m_cBoneHighlight = v6;
  mxToolTip::add(widget: v6, text: "Toggle display of the bone being modified");
  v7 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v7 != nullptr )
    mxLabel::mxLabel(this: v7, parent: this, x: 8, y: 68, w: 100, h: 18, label: "Bone Surface Prop");
  v8 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v8 != nullptr )
    v9 = mxChoice::mxChoice(this: v8, parent: this, x: 5, y: 85, w: 140, h: 22, id: 5004);
  else
    v9 = nullptr;
  this->m_cSurfaceProp = v9;
  mxToolTip::add(widget: v9, text: "Select a surface property to apply to the bone");
  ReadPhysicsMaterials(plist: this->m_cSurfaceProp);
  v10 = (mxButton *)operator new(nSize: 0xCu);
  if ( v10 != nullptr )
    v11 = mxButton::mxButton(this: v10, parent: this, x: 5, y: 115, w: 140, h: 20, label: "Apply to Children", id: 5008);
  else
    v11 = nullptr;
  mxToolTip::add(widget: v11, text: "Apply the surface property to all child bones");
  v12 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v12 != nullptr )
    v13 = mxCheckBox::mxCheckBox(
            this: v12,
            parent: this,
            x: 5,
            y: 140,
            w: 140,
            h: 20,
            label: "Autogenerate Hitboxes",
            id: 5018);
  else
    v13 = nullptr;
  this->m_cAutoHitbox = v13;
  mxToolTip::add(widget: v13, text: "When this is checked, studiomdl will automatically generate hitboxes");
  v14 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v14 != nullptr )
    v15 = mxCheckBox::mxCheckBox(
            this: v14,
            parent: this,
            x: 5,
            y: 160,
            w: 140,
            h: 20,
            label: "Show Default Pose",
            id: 5009);
  else
    v15 = nullptr;
  this->m_cShowDefaultPose = v15;
  mxToolTip::add(widget: v15, text: "Toggles display of the default physics pose");
  v16 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v16 != nullptr )
    mxLabel::mxLabel(this: v16, parent: this, x: 163, y: 50, w: 80, h: 18, label: "Hitbox Set");
  v17 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v17 != nullptr )
    v18 = mxChoice::mxChoice(this: v17, parent: this, x: 160, y: 66, w: 100, h: 22, id: 5019);
  else
    v18 = nullptr;
  this->m_cHitboxSet = v18;
  mxChoice::add(this: v18, item: "unnamed");
  mxChoice::select(this: this->m_cHitboxSet, index: 0);
  mxToolTip::add(widget: this->m_cHitboxSet, text: "Change hitbox set");
  v19 = (mxLineEdit *)operator new(nSize: 0xCu);
  if ( v19 != nullptr )
    v20 = mxLineEdit::mxLineEdit(
            this: v19,
            parent: this,
            x: 160,
            y: 96,
            w: 100,
            h: 18,
            label: WindowName,
            id: 5023,
            style: 0);
  else
    v20 = nullptr;
  this->m_eHitboxSetName = v20;
  mxToolTip::add(widget: v20, text: "Type in a name and hit the set button");
  v21 = (mxButton *)operator new(nSize: 0xCu);
  if ( v21 != nullptr )
    v22 = mxButton::mxButton(this: v21, parent: this, x: 160, y: 116, w: 100, h: 16, label: "Set Name", id: 5022);
  else
    v22 = nullptr;
  this->m_bHitboxSetUpdateName = v22;
  mxToolTip::add(widget: v22, text: "Press to set hitbox set name from above text field");
  v23 = (mxButton *)operator new(nSize: 0xCu);
  if ( v23 != nullptr )
    v24 = mxButton::mxButton(this: v23, parent: this, x: 160, y: 140, w: 100, h: 20, label: "Add set", id: 5020);
  else
    v24 = nullptr;
  this->m_bAddHitboxSet = v24;
  mxToolTip::add(widget: v24, text: "Add a hitbox set");
  v25 = (mxButton *)operator new(nSize: 0xCu);
  if ( v25 != nullptr )
    v26 = mxButton::mxButton(this: v25, parent: this, x: 160, y: 162, w: 100, h: 20, label: "Delete set", id: 5021);
  else
    v26 = nullptr;
  this->m_bDeleteHitboxSet = v26;
  mxToolTip::add(widget: v26, text: "Remove a hitbox set");
  v27 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v27 != nullptr )
    mxLabel::mxLabel(this: v27, parent: this, x: 283, y: 4, w: 30, h: 18, label: "Hitbox");
  v28 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v28 != nullptr )
    v29 = mxChoice::mxChoice(this: v28, parent: this, x: 280, y: 20, w: 100, h: 22, id: 5003);
  else
    v29 = nullptr;
  this->m_cHitbox = v29;
  mxChoice::add(this: v29, item: "None");
  mxChoice::select(this: this->m_cHitbox, index: 0);
  mxToolTip::add(widget: this->m_cHitbox, text: "Select a hitbox to modify");
  v30 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v30 != nullptr )
    v31 = mxCheckBox::mxCheckBox(
            this: v30,
            parent: this,
            x: 283,
            y: 45,
            w: 100,
            h: 20,
            label: "Highlight Hitbox",
            id: 5005);
  else
    v31 = nullptr;
  this->m_cHitboxHighlight = v31;
  mxToolTip::add(widget: v31, text: "Toggle display of the hitbox being modified");
  v32 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v32 != nullptr )
    mxLabel::mxLabel(this: v32, parent: this, x: 283, y: 80, w: 80, h: 18, label: "Hitbox Group");
  v33 = (mxLineEdit *)operator new(nSize: 0xCu);
  if ( v33 != nullptr )
    v34 = mxLineEdit::mxLineEdit(
            this: v33,
            parent: this,
            x: 360,
            y: 75,
            w: 50,
            h: 22,
            label: WindowName,
            id: 5016,
            style: 0);
  else
    v34 = nullptr;
  this->m_eHitboxGroup = v34;
  mxToolTip::add(widget: v34, text: "The group of the current hitbox");
  v35 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v35 != nullptr )
    mxLabel::mxLabel(this: v35, parent: this, x: 413, y: 80, w: 80, h: 18, label: "Hitbox Name");
  v36 = (mxLineEdit *)operator new(nSize: 0xCu);
  if ( v36 != nullptr )
    v37 = mxLineEdit::mxLineEdit(
            this: v36,
            parent: this,
            x: 493,
            y: 75,
            w: 50,
            h: 22,
            label: WindowName,
            id: 5101,
            style: 0);
  else
    v37 = nullptr;
  this->m_eHitboxName = v37;
  mxWidget::setEnabled(this: v37, b: false);
  mxToolTip::add(widget: this->m_eHitboxName, text: "The name of the current hitbox");
  v38 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v38 != nullptr )
    mxLabel::mxLabel(this: v38, parent: this, x: 283, y: 110, w: 80, h: 18, label: "Hitbox Origin");
  v39 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v39 != nullptr )
    mxLabel::mxLabel(this: v39, parent: this, x: 413, y: 110, w: 10, h: 18, label: "X");
  v40 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v40 != nullptr )
    mxLabel::mxLabel(this: v40, parent: this, x: 478, y: 110, w: 10, h: 18, label: "Y");
  v41 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v41 != nullptr )
    mxLabel::mxLabel(this: v41, parent: this, x: 543, y: 110, w: 10, h: 18, label: "Z");
  v42 = (mxLineEdit *)operator new(nSize: 0xCu);
  if ( v42 != nullptr )
    v43 = mxLineEdit::mxLineEdit(
            this: v42,
            parent: this,
            x: 360,
            y: 105,
            w: 50,
            h: 22,
            label: WindowName,
            id: 5010,
            style: 0);
  else
    v43 = nullptr;
  this->m_eOriginX = v43;
  v44 = (mxLineEdit *)operator new(nSize: 0xCu);
  if ( v44 != nullptr )
    v45 = mxLineEdit::mxLineEdit(
            this: v44,
            parent: this,
            x: 425,
            y: 105,
            w: 50,
            h: 22,
            label: WindowName,
            id: 5011,
            style: 0);
  else
    v45 = nullptr;
  this->m_eOriginY = v45;
  v46 = (mxLineEdit *)operator new(nSize: 0xCu);
  if ( v46 != nullptr )
    v47 = mxLineEdit::mxLineEdit(
            this: v46,
            parent: this,
            x: 490,
            y: 105,
            w: 50,
            h: 22,
            label: WindowName,
            id: 5012,
            style: 0);
  else
    v47 = nullptr;
  this->m_eOriginZ = v47;
  v48 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v48 != nullptr )
    mxLabel::mxLabel(this: v48, parent: this, x: 283, y: 140, w: 80, h: 18, label: "Hitbox Size");
  v49 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v49 != nullptr )
    mxLabel::mxLabel(this: v49, parent: this, x: 413, y: 140, w: 10, h: 18, label: "X");
  v50 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v50 != nullptr )
    mxLabel::mxLabel(this: v50, parent: this, x: 478, y: 140, w: 10, h: 18, label: "Y");
  v51 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v51 != nullptr )
    mxLabel::mxLabel(this: v51, parent: this, x: 543, y: 140, w: 10, h: 18, label: "Z");
  v52 = (mxLineEdit *)operator new(nSize: 0xCu);
  if ( v52 != nullptr )
    v53 = mxLineEdit::mxLineEdit(
            this: v52,
            parent: this,
            x: 360,
            y: 135,
            w: 50,
            h: 22,
            label: WindowName,
            id: 5013,
            style: 0);
  else
    v53 = nullptr;
  this->m_eSizeX = v53;
  v54 = (mxLineEdit *)operator new(nSize: 0xCu);
  if ( v54 != nullptr )
    v55 = mxLineEdit::mxLineEdit(
            this: v54,
            parent: this,
            x: 425,
            y: 135,
            w: 50,
            h: 22,
            label: WindowName,
            id: 5014,
            style: 0);
  else
    v55 = nullptr;
  this->m_eSizeY = v55;
  v56 = (mxLineEdit *)operator new(nSize: 0xCu);
  if ( v56 != nullptr )
    v57 = mxLineEdit::mxLineEdit(
            this: v56,
            parent: this,
            x: 490,
            y: 135,
            w: 50,
            h: 22,
            label: WindowName,
            id: 5015,
            style: 0);
  else
    v57 = nullptr;
  this->m_eSizeZ = v57;
  v58 = (mxButton *)operator new(nSize: 0xCu);
  if ( v58 != nullptr )
    v59 = mxButton::mxButton(this: v58, parent: this, x: 280, y: 163, w: 100, h: 20, label: "Update Hitbox", id: 5017);
  else
    v59 = nullptr;
  this->m_bUpdateHitbox = v59;
  mxToolTip::add(widget: v59, text: "Apply hitbox group, origin, and size to the hitbox");
  v60 = (mxButton *)operator new(nSize: 0xCu);
  if ( v60 != nullptr )
    v61 = mxButton::mxButton(this: v60, parent: this, x: 390, y: 163, w: 70, h: 20, label: "Load .HBX", id: 5103);
  else
    v61 = nullptr;
  mxToolTip::add(widget: v61, text: "Load hitboxes from a .hbx file");
  v62 = (mxButton *)operator new(nSize: 0xCu);
  if ( v62 != nullptr )
    v63 = mxButton::mxButton(this: v62, parent: this, x: 470, y: 163, w: 70, h: 20, label: "Save .HBX", id: 5102);
  else
    v63 = nullptr;
  mxToolTip::add(widget: v63, text: "Save hitboxes to a .hbx file");
  v64 = (mxButton *)operator new(nSize: 0xCu);
  if ( v64 != nullptr )
    v65 = mxButton::mxButton(this: v64, parent: this, x: 440, y: 10, w: 100, h: 20, label: "Generate QC", id: 5001);
  else
    v65 = nullptr;
  mxToolTip::add(widget: v65, text: "Copy a .qc file snippet to the clipboard");
  v66 = (mxButton *)operator new(nSize: 0xCu);
  if ( v66 != nullptr )
    v67 = mxButton::mxButton(this: v66, parent: this, x: 440, y: 30, w: 100, h: 20, label: "Add Hitbox", id: 5006);
  else
    v67 = nullptr;
  this->m_bAddHitbox = v67;
  v68 = (mxButton *)operator new(nSize: 0xCu);
  if ( v68 != nullptr )
    v69 = mxButton::mxButton(this: v68, parent: this, x: 440, y: 50, w: 100, h: 20, label: "Delete Hitbox", id: 5007);
  else
    v69 = nullptr;
  m_bAddHitbox = this->m_bAddHitbox;
  this->m_bDeleteHitbox = v69;
  mxToolTip::add(widget: m_bAddHitbox, text: "Create a new hitbox attached to the current bone");
  mxToolTip::add(widget: this->m_bDeleteHitbox, text: "Delete the currently selected hitbox");
  CBoneControlWindow::OnAutogenerateHitboxes(this, isChecked: false);
}

//------------------------------------------------------------------------------
// Address: 0x00405360
// Name: public: void ControlPanel::SetupRenderWindow(class mxTab __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::SetupRenderWindow(ControlPanel *this, mxTab *pTab)
{
  mxWindow *v3; // eax
  mxWindow *v4; // eax
  mxTab *tab; // ecx
  mxChoice *v6; // eax
  mxChoice *v7; // eax
  mxCheckBox *v8; // eax
  mxCheckBox *v9; // eax
  mxCheckBox *v10; // eax
  mxCheckBox *v11; // eax
  mxCheckBox *v12; // eax
  mxCheckBox *v13; // eax
  mxCheckBox *v14; // eax
  mxCheckBox *v15; // eax
  mxCheckBox *v16; // eax
  mxCheckBox *v17; // eax
  mxCheckBox *v18; // eax
  mxCheckBox *v19; // eax
  mxCheckBox *v20; // eax
  mxCheckBox *v21; // eax
  mxCheckBox *v22; // eax
  mxCheckBox *v23; // eax
  mxCheckBox *v24; // eax
  mxCheckBox *v25; // eax
  mxCheckBox *v26; // eax
  mxCheckBox *v27; // eax
  mxCheckBox *v28; // eax
  mxCheckBox *v29; // eax
  mxCheckBox *v30; // eax
  mxCheckBox *v31; // eax
  mxCheckBox *v32; // eax
  mxCheckBox *v33; // eax
  mxCheckBox *v34; // eax
  mxCheckBox *v35; // eax
  mxCheckBox *v36; // eax
  mxCheckBox *v37; // eax
  mxCheckBox *v38; // eax
  mxCheckBox *v39; // eax
  mxCheckBox *v40; // eax
  mxCheckBox *v41; // eax
  mxCheckBox *v42; // eax
  mxCheckBox *v43; // eax
  mxCheckBox *v44; // eax
  mxCheckBox *v45; // eax
  mxCheckBox *v46; // eax
  mxCheckBox *v47; // eax
  mxCheckBox *v48; // eax
  mxCheckBox *v49; // eax
  mxLabel *v50; // eax
  mxSlider *v51; // eax
  mxSlider *v52; // eax
  mxCheckBox *v53; // eax
  mxChoice *v54; // eax
  mxChoice *v55; // eax
  mxLabel *v56; // eax
  mxChoice *v57; // eax
  mxChoice *v58; // eax
  mxLabel *v59; // eax
  mxChoice *v60; // eax
  mxChoice *v61; // eax
  mxLabel *v62; // eax
  mxLineEdit *v63; // eax
  mxLineEdit *v64; // eax
  mxChoice *v65; // eax
  mxChoice *v66; // eax

  v3 = (mxWindow *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    v4 = mxWindow::mxWindow(this: v3, parent: this, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  else
    v4 = nullptr;
  tab = this->tab;
  this->wRender = v4;
  mxTab::add(this: tab, widget: v4, text: "Render");
  v6 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v6 != nullptr )
    v7 = mxChoice::mxChoice(this: v6, parent: this->wRender, x: 5, y: 2, w: 100, h: 22, id: 2001);
  else
    v7 = nullptr;
  this->cRenderMode = v7;
  mxChoice::add(this: v7, item: "Wireframe");
  mxChoice::add(this: this->cRenderMode, item: "Smoothshaded");
  mxChoice::add(this: this->cRenderMode, item: "Textured");
  mxChoice::add(this: this->cRenderMode, item: "BoneWeights");
  mxChoice::add(this: this->cRenderMode, item: "BadVertexData");
  mxChoice::add(this: this->cRenderMode, item: "UV Chart");
  mxChoice::add(this: this->cRenderMode, item: "Co-LocatedVerts");
  mxChoice::select(this: this->cRenderMode, index: 2);
  mxToolTip::add(widget: this->cRenderMode, text: "Select Render Mode");
  v8 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v8 != nullptr )
    v9 = mxCheckBox::mxCheckBox(
           this: v8,
           parent: this->wRender,
           x: 125,
           y: 5,
           w: 150,
           h: 20,
           label: "Ground (Ctrl-G)",
           id: 2003);
  else
    v9 = nullptr;
  this->cbGround = v9;
  mxWidget::setEnabled(this: v9, b: true);
  v10 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v10 != nullptr )
    v11 = mxCheckBox::mxCheckBox(
            this: v10,
            parent: this->wRender,
            x: 125,
            y: 25,
            w: 150,
            h: 20,
            label: "Movement (Ctrl-M)",
            id: 2004);
  else
    v11 = nullptr;
  this->cbMovement = v11;
  mxWidget::setEnabled(this: v11, b: true);
  v12 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v12 != nullptr )
    v13 = mxCheckBox::mxCheckBox(
            this: v12,
            parent: this->wRender,
            x: 125,
            y: 45,
            w: 150,
            h: 20,
            label: "Background (Ctrl-B)",
            id: 2005);
  else
    v13 = nullptr;
  this->cbBackground = v13;
  mxWidget::setEnabled(this: v13, b: true);
  v14 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v14 != nullptr )
    v15 = mxCheckBox::mxCheckBox(
            this: v14,
            parent: this->wRender,
            x: 125,
            y: 65,
            w: 150,
            h: 20,
            label: "Hit Boxes (Ctrl-H)",
            id: 2006);
  else
    v15 = nullptr;
  this->cbHitBoxes = v15;
  v16 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v16 != nullptr )
    v17 = mxCheckBox::mxCheckBox(
            this: v16,
            parent: this->wRender,
            x: 125,
            y: 85,
            w: 150,
            h: 20,
            label: "Seq. Boxes",
            id: 2017);
  else
    v17 = nullptr;
  this->cbSequenceBoxes = v17;
  v18 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v18 != nullptr )
    v19 = mxCheckBox::mxCheckBox(
            this: v18,
            parent: this->wRender,
            x: 125,
            y: 105,
            w: 150,
            h: 20,
            label: "Shadow (Ctrl-S)",
            id: 2024);
  else
    v19 = nullptr;
  this->cbShadow = v19;
  v20 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v20 != nullptr )
    v21 = mxCheckBox::mxCheckBox(
            this: v20,
            parent: this->wRender,
            x: 125,
            y: 125,
            w: 150,
            h: 20,
            label: "Software Skin",
            id: 2014);
  else
    v21 = nullptr;
  this->cbSoftwareSkin = v21;
  mxWidget::setEnabled(this: v21, b: true);
  v22 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v22 != nullptr )
    v23 = mxCheckBox::mxCheckBox(
            this: v22,
            parent: this->wRender,
            x: 125,
            y: 145,
            w: 150,
            h: 20,
            label: "Enable Overbrightening",
            id: 2015);
  else
    v23 = nullptr;
  this->cbOverbright2 = v23;
  mxWidget::setEnabled(this: v23, b: true);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbOverbright2, b: true);
  g_viewerSettings.overbright = true;
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbOverbright2, b: true);
  v24 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v24 != nullptr )
    v25 = mxCheckBox::mxCheckBox(
            this: v24,
            parent: this->wRender,
            x: 5,
            y: 45,
            w: 120,
            h: 20,
            label: "Attachments (Ctrl-A)",
            id: 2008);
  else
    v25 = nullptr;
  this->cbAttachments = v25;
  mxWidget::setEnabled(this: v25, b: true);
  v26 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v26 != nullptr )
    v27 = mxCheckBox::mxCheckBox(
            this: v26,
            parent: this->wRender,
            x: 5,
            y: 65,
            w: 120,
            h: 20,
            label: "Bones (Ctrl-O)",
            id: 2007);
  else
    v27 = nullptr;
  this->cbBones = v27;
  v28 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v28 != nullptr )
    v29 = mxCheckBox::mxCheckBox(
            this: v28,
            parent: this->wRender,
            x: 5,
            y: 85,
            w: 120,
            h: 20,
            label: "Normals (Ctrl-N)",
            id: 2020);
  else
    v29 = nullptr;
  this->cbNormals = v29;
  mxWidget::setEnabled(this: v29, b: true);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbNormals, b: false);
  v30 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v30 != nullptr )
    v31 = mxCheckBox::mxCheckBox(
            this: v30,
            parent: this->wRender,
            x: 5,
            y: 105,
            w: 120,
            h: 20,
            label: "Tangents (Ctrl-T)",
            id: 2021);
  else
    v31 = nullptr;
  this->cbTangentFrame = v31;
  mxWidget::setEnabled(this: v31, b: true);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbTangentFrame, b: false);
  v32 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v32 != nullptr )
    v33 = mxCheckBox::mxCheckBox(
            this: v32,
            parent: this->wRender,
            x: 5,
            y: 125,
            w: 120,
            h: 20,
            label: "Wireframe (Ctrl-W)",
            id: 2026);
  else
    v33 = nullptr;
  this->cbOverlayWireframe = v33;
  mxWidget::setEnabled(this: v33, b: true);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbOverlayWireframe, b: false);
  v34 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v34 != nullptr )
    v35 = mxCheckBox::mxCheckBox(
            this: v34,
            parent: this->wRender,
            x: 5,
            y: 145,
            w: 120,
            h: 20,
            label: "Specular",
            id: 2023);
  else
    v35 = nullptr;
  this->cbSpecular = v35;
  mxWidget::setEnabled(this: v35, b: true);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbSpecular, b: true);
  v36 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v36 != nullptr )
    v37 = mxCheckBox::mxCheckBox(
            this: v36,
            parent: this->wRender,
            x: 5,
            y: 25,
            w: 100,
            h: 20,
            label: "Normal Mapping",
            id: 2022);
  else
    v37 = nullptr;
  this->cbNormalMap = v37;
  mxWidget::setEnabled(this: v37, b: true);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbNormalMap, b: false);
  v38 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v38 != nullptr )
    v39 = mxCheckBox::mxCheckBox(
            this: v38,
            parent: this->wRender,
            x: 275,
            y: 45,
            w: 150,
            h: 20,
            label: "Displacement (Ctrl-D)",
            id: 2032);
  else
    v39 = nullptr;
  this->cbDisplacementMap = v39;
  mxWidget::setEnabled(this: v39, b: true);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbDisplacementMap, b: true);
  v40 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v40 != nullptr )
    v41 = mxCheckBox::mxCheckBox(
            this: v40,
            parent: this->wRender,
            x: 275,
            y: 65,
            w: 150,
            h: 20,
            label: "Enable IK",
            id: 2018);
  else
    v41 = nullptr;
  this->cbRunIK = v41;
  v42 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v42 != nullptr )
    v43 = mxCheckBox::mxCheckBox(
            this: v42,
            parent: this->wRender,
            x: 275,
            y: 85,
            w: 150,
            h: 20,
            label: "Head Turn",
            id: 2019);
  else
    v43 = nullptr;
  this->cbEnableHead = v43;
  v44 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v44 != nullptr )
    v45 = mxCheckBox::mxCheckBox(
            this: v44,
            parent: this->wRender,
            x: 275,
            y: 105,
            w: 150,
            h: 20,
            label: "Illum. Position",
            id: 2025);
  else
    v45 = nullptr;
  this->cbIllumPosition = v45;
  v46 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v46 != nullptr )
    v47 = mxCheckBox::mxCheckBox(
            this: v46,
            parent: this->wRender,
            x: 275,
            y: 125,
            w: 150,
            h: 20,
            label: "Play Sounds",
            id: 2027);
  else
    v47 = nullptr;
  this->cbPlaySounds = v47;
  v48 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v48 != nullptr )
    v49 = mxCheckBox::mxCheckBox(
            this: v48,
            parent: this->wRender,
            x: 275,
            y: 145,
            w: 150,
            h: 20,
            label: "Show Origin Axis",
            id: 2030);
  else
    v49 = nullptr;
  this->cbShowOriginAxis = v49;
  v50 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v50 != nullptr )
    mxLabel::mxLabel(this: v50, parent: this->wRender, x: 275, y: 170, w: 45, h: 18, label: "Axis Len:");
  v51 = (mxSlider *)operator new(nSize: 0x18u);
  if ( v51 != nullptr )
    v52 = mxSlider::mxSlider(this: v51, parent: this->wRender, x: 320, y: 165, w: 105, h: 22, id: 2031, style: 0);
  else
    v52 = nullptr;
  this->leOriginAxisLength = v52;
  mxSlider::setRange(this: v52, min: 1.0, max: 100.0, ticks: 100);
  mxSlider::setValue(this: this->leOriginAxisLength, value: 10.0);
  v53 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v53 != nullptr )
    mxCheckBox::mxCheckBox(
      this: v53,
      parent: this->wRender,
      x: 275,
      y: 5,
      w: 150,
      h: 20,
      label: "Physics Model",
      id: 2009);
  v54 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v54 != nullptr )
    v55 = mxChoice::mxChoice(this: v54, parent: this->wRender, x: 275, y: 25, w: 150, h: 22, id: 2010);
  else
    v55 = nullptr;
  this->cHighlightBone = v55;
  mxChoice::add(this: v55, item: "None");
  mxChoice::select(this: this->cHighlightBone, index: 0);
  mxToolTip::add(widget: this->cHighlightBone, text: "Select Physics Bone to highlight");
  v56 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v56 != nullptr )
    mxLabel::mxLabel(this: v56, parent: this->wRender, x: 450, y: 29, w: 60, h: 18, label: "HitBox Set:");
  v57 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v57 != nullptr )
    v58 = mxChoice::mxChoice(this: v57, parent: this->wRender, x: 510, y: 25, w: 90, h: 22, id: 2035);
  else
    v58 = nullptr;
  this->cDrawHitBoxSet = v58;
  mxChoice::add(this: v58, item: "All");
  mxChoice::select(this: this->cDrawHitBoxSet, index: 0);
  mxWidget::setEnabled(this: this->cDrawHitBoxSet, b: false);
  v59 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v59 != nullptr )
    mxLabel::mxLabel(this: v59, parent: this->wRender, x: 450, y: 48, w: 60, h: 18, label: "HitBox:");
  v60 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v60 != nullptr )
    v61 = mxChoice::mxChoice(this: v60, parent: this->wRender, x: 510, y: 48, w: 90, h: 22, id: 2036);
  else
    v61 = nullptr;
  this->cDrawHitBoxNumber = v61;
  mxWidget::setEnabled(this: v61, b: false);
  v62 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v62 != nullptr )
    mxLabel::mxLabel(this: v62, parent: this->wRender, x: 5, y: 170, w: 30, h: 18, label: "FOV:");
  v63 = (mxLineEdit *)operator new(nSize: 0xCu);
  if ( v63 != nullptr )
    v64 = mxLineEdit::mxLineEdit(
            this: v63,
            parent: this->wRender,
            x: 35,
            y: 165,
            w: 30,
            h: 22,
            label: "65",
            id: 2016,
            style: 0);
  else
    v64 = nullptr;
  this->leFOV = v64;
  v65 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v65 != nullptr )
    v66 = mxChoice::mxChoice(this: v65, parent: this->wRender, x: 450, y: 68, w: 250, h: 20, id: 2034);
  else
    v66 = nullptr;
  this->cIncludedModels = v66;
  mxChoice::add(this: v66, item: "Included Models");
  mxChoice::add(this: this->cIncludedModels, item: "---------------");
  mxWidget::setEnabled(this: this->cIncludedModels, b: false);
}

//------------------------------------------------------------------------------
// Address: 0x00405C20
// Name: public: void ControlPanel::updateSequenceSizes(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::updateSequenceSizes(ControlPanel *this, int tabWidth)
{
  int v2; // ebx
  int v3; // eax
  int v4; // esi
  mxSlider **slSequence; // edi
  int v6; // edx
  int v7; // eax
  int v8; // ebx
  mxSlider **slPoseParameter; // esi
  int v10; // [esp+Ch] [ebp-10h]
  int x; // [esp+14h] [ebp-8h]
  int xa; // [esp+14h] [ebp-8h]
  int v14; // [esp+18h] [ebp-4h]
  int v15; // [esp+18h] [ebp-4h]
  int extraWidth; // [esp+24h] [ebp+8h]
  int extraWidtha; // [esp+24h] [ebp+8h]

  v2 = tabWidth - 640;
  v3 = 0;
  extraWidth = v2;
  if ( v2 <= 200 )
  {
    if ( v2 < 0 )
    {
      extraWidth = 0;
      v2 = 0;
    }
    goto LABEL_7;
  }
  v3 = v2 - 200;
  extraWidth = 200;
  v2 = 200;
  if ( v3 >= 0 )
  {
    v14 = 200;
    if ( v3 > 200 )
      goto LABEL_8;
LABEL_7:
    v14 = v3;
    goto LABEL_8;
  }
  v14 = 0;
LABEL_8:
  x = v2 + 208;
  v4 = 5;
  slSequence = this->slSequence;
  do
  {
    mxWidget::setBounds(this: *(slSequence - 11), x: 5, y: v4, w: v2 + 200, h: 522);
    mxWidget::setBounds(this: *slSequence, x, y: v4, w: 80, h: 18);
    mxWidget::setBounds(this: slSequence[50], x: v2 + 300, y: v4, w: 35, h: 22);
    mxWidget::setBounds(this: *(slSequence - 5), x: v14 + v2 + 706, y: v4, w: 100, h: 18);
    v4 += 22;
    ++slSequence;
  }
  while ( v4 < 115 );
  mxWidget::setBounds(this: this->laFilters, x: v14 + v2 + 621, y: 5, w: 80, h: 18);
  mxWidget::setBounds(this: this->laGroundSpeed, x, y: 5, w: 80, h: 18);
  xa = v14 + 96;
  v6 = extraWidth + 334;
  v7 = extraWidth + 480;
  v8 = 0;
  extraWidtha = extraWidth + 520;
  v15 = v6;
  v10 = v7;
  slPoseParameter = this->slPoseParameter;
  do
  {
    mxWidget::setBounds(this: *(slPoseParameter - 8), x: extraWidtha, y: 17 * (v8 & 7) + 2, w: xa, h: 522);
    mxWidget::setBounds(this: *slPoseParameter, x: v15, y: 17 * (v8 & 7) + 2, w: 140, h: 16);
    mxWidget::setBounds(this: slPoseParameter[8], x: v10, y: 17 * (v8++ & 7) + 2, w: 40, h: 16);
    ++slPoseParameter;
  }
  while ( v8 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x00405DA0
// Name: public: void ControlPanel::SetupBodyWindow(class mxTab __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::SetupBodyWindow(ControlPanel *this, mxTab *pTab)
{
  mxWindow *v3; // eax
  mxWindow *v4; // esi
  mxChoice *v5; // eax
  mxChoice *v6; // eax
  mxChoice *v7; // eax
  mxChoice *v8; // eax
  mxChoice *v9; // eax
  mxChoice *v10; // eax
  mxSlider *v11; // eax
  mxSlider *v12; // eax
  mxLabel *v13; // eax
  mxLabel *v14; // eax
  mxLabel *v15; // eax
  mxLabel *v16; // eax
  mxChoice *v17; // eax
  mxChoice *v18; // eax
  mxLabel *v19; // eax
  mxChoice *v20; // eax
  mxChoice *v21; // eax
  mxLabel *v22; // eax
  mxLabel *v23; // eax
  mxLabel *v24; // eax
  mxLabel *v25; // eax
  bool v26; // zf
  mxCheckBox *v27; // eax
  mxCheckBox *v28; // eax
  mxChoice *v29; // eax
  mxChoice *v30; // eax
  mxLabel *v31; // eax
  mxLineEdit *v32; // eax
  mxLineEdit *v33; // eax
  mxLabel *v34; // eax
  mxLabel *v35; // eax
  mxLabel *v36; // eax
  mxLabel *v37; // eax
  mxListBox *v38; // eax
  mxListBox *v39; // eax
  mxLabel *v40; // eax
  mxListBox *v41; // eax
  mxListBox *v42; // eax
  char string[128]; // [esp+14h] [ebp-80h] BYREF

  v3 = (mxWindow *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    v4 = mxWindow::mxWindow(this: v3, parent: this, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  else
    v4 = nullptr;
  mxTab::add(this: pTab, widget: v4, text: "Model");
  v5 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v5 != nullptr )
    v6 = mxChoice::mxChoice(this: v5, parent: v4, x: 5, y: 5, w: 100, h: 22, id: 4001);
  else
    v6 = nullptr;
  this->cBodypart = v6;
  mxToolTip::add(widget: v6, text: "Choose a bodypart");
  v7 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v7 != nullptr )
    v8 = mxChoice::mxChoice(this: v7, parent: v4, x: 110, y: 5, w: 100, h: 22, id: 4002);
  else
    v8 = nullptr;
  this->cSubmodel = v8;
  mxToolTip::add(widget: v8, text: "Choose a submodel of current bodypart");
  v9 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v9 != nullptr )
    v10 = mxChoice::mxChoice(this: v9, parent: v4, x: 5, y: 30, w: 100, h: 22, id: 4003);
  else
    v10 = nullptr;
  this->cController = v10;
  mxToolTip::add(widget: v10, text: "Choose a bone controller");
  v11 = (mxSlider *)operator new(nSize: 0x18u);
  if ( v11 != nullptr )
    v12 = mxSlider::mxSlider(this: v11, parent: v4, x: 105, y: 32, w: 100, h: 18, id: 4004, style: 0);
  else
    v12 = nullptr;
  this->slController = v12;
  mxSlider::setRange(this: v12, min: 0.0, max: 255.0, ticks: 100);
  mxToolTip::add(widget: this->slController, text: "Change current bone controller value");
  v13 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v13 != nullptr )
    v14 = mxLabel::mxLabel(this: v13, parent: v4, x: 220, y: 5, w: 120, h: 80, label: "No Model.");
  else
    v14 = nullptr;
  this->lModelInfo1 = v14;
  v15 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v15 != nullptr )
    v16 = mxLabel::mxLabel(this: v15, parent: v4, x: 340, y: 5, w: 120, h: 130, label: WindowName);
  else
    v16 = nullptr;
  this->lModelInfo2 = v16;
  v17 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v17 != nullptr )
    v18 = mxChoice::mxChoice(this: v17, parent: v4, x: 5, y: 55, w: 100, h: 22, id: 4005);
  else
    v18 = nullptr;
  this->cSkin = v18;
  mxToolTip::add(widget: v18, text: "Choose a skin family");
  v19 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v19 != nullptr )
    mxLabel::mxLabel(this: v19, parent: v4, x: 5, y: 170, w: 90, h: 18, label: "Materials used:");
  v20 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v20 != nullptr )
    v21 = mxChoice::mxChoice(this: v20, parent: v4, x: 105, y: 166, w: 350, h: 22, id: 4006);
  else
    v21 = nullptr;
  this->cMaterials = v21;
  mxToolTip::add(widget: v21, text: "Select material for UV Chart view");
  v22 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v22 != nullptr )
    v23 = mxLabel::mxLabel(this: v22, parent: v4, x: 220, y: 100, w: 120, h: 22, label: WindowName);
  else
    v23 = nullptr;
  this->lModelInfo3 = v23;
  v24 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v24 != nullptr )
    v25 = mxLabel::mxLabel(this: v24, parent: v4, x: 220, y: 118, w: 120, h: 22, label: WindowName);
  else
    v25 = nullptr;
  v26 = saveTransparent == 0;
  this->lModelInfo4 = v25;
  if ( !v26 )
  {
    saveTransparent = 0;
    sprintf(string, format: "Model is: %s", "opaque");
    mxWidget::setLabel(this: this->lModelInfo4, format: string);
  }
  v27 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v27 != nullptr )
    v28 = mxCheckBox::mxCheckBox(this: v27, parent: v4, x: 5, y: 80, w: 100, h: 20, label: "Auto LOD", id: 2012);
  else
    v28 = nullptr;
  this->cbAutoLOD = v28;
  mxWidget::setEnabled(this: v28, b: true);
  v29 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v29 != nullptr )
    v30 = mxChoice::mxChoice(this: v29, parent: v4, x: 5, y: 101, w: 100, h: 22, id: 2011);
  else
    v30 = nullptr;
  this->cLODChoice = v30;
  mxToolTip::add(widget: v30, text: "Select model LOD to render");
  v31 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v31 != nullptr )
    mxLabel::mxLabel(this: v31, parent: v4, x: 5, y: 126, w: 60, h: 18, label: "LOD Switch:");
  v32 = (mxLineEdit *)operator new(nSize: 0xCu);
  if ( v32 != nullptr )
    v33 = mxLineEdit::mxLineEdit(
            this: v32,
            parent: v4,
            x: 70,
            y: 126,
            w: 35,
            h: 22,
            label: WindowName,
            id: 2013,
            style: 0);
  else
    v33 = nullptr;
  this->leLODSwitch = v33;
  v34 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v34 != nullptr )
    mxLabel::mxLabel(this: v34, parent: v4, x: 5, y: 151, w: 60, h: 18, label: "LOD Metric:");
  v35 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v35 != nullptr )
    v36 = mxLabel::mxLabel(this: v35, parent: v4, x: 70, y: 151, w: 35, h: 22, label: WindowName);
  else
    v36 = nullptr;
  this->lLODMetric = v36;
  v37 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v37 != nullptr )
    mxLabel::mxLabel(this: v37, parent: v4, x: 505, y: 5, w: 100, h: 18, label: "VMTs Loaded:");
  v38 = (mxListBox *)operator new(nSize: 0xCu);
  if ( v38 != nullptr )
    v39 = mxListBox::mxListBox(this: v38, parent: v4, x: 500, y: 25, w: 540, h: 160, id: 2028, style: 0);
  else
    v39 = nullptr;
  this->cMessageList = v39;
  mxListBox::add(this: v39, item: "None");
  mxListBox::select(this: this->cMessageList, index: 1);
  mxToolTip::add(widget: this->cMessageList, text: "Materials (VMT files) this model has loaded");
  v40 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v40 != nullptr )
    mxLabel::mxLabel(this: v40, parent: v4, x: 785, y: 5, w: 100, h: 18, label: "Shader:");
  v41 = (mxListBox *)operator new(nSize: 0xCu);
  if ( v41 != nullptr )
    v42 = mxListBox::mxListBox(this: v41, parent: v4, x: 830, y: 3, w: 210, h: 28, id: 2029, style: 0);
  else
    v42 = nullptr;
  this->cShaderUsed = v42;
  mxListBox::add(this: v42, item: "Select material to show shader");
  mxListBox::select(this: this->cShaderUsed, index: 0);
  mxToolTip::add(widget: this->cShaderUsed, text: "Shader Used");
}

//------------------------------------------------------------------------------
// Address: 0x004062C0
// Name: public: void ControlPanel::SetupPhysicsWindow(class mxTab __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::SetupPhysicsWindow(ControlPanel *this, mxTab *pTab)
{
  mxWindow *v3; // eax
  mxWindow *v4; // esi
  mxLabel *v5; // eax
  mxLineEdit *v6; // eax
  mxLineEdit *v7; // eax
  mxChoice *v8; // eax
  mxChoice *v9; // eax
  mxCheckBox *v10; // eax
  mxRadioButton *v11; // eax
  mxRadioButton *v12; // eax
  mxRadioButton *v13; // eax
  mxRadioButton *v14; // eax
  mxRadioButton *v15; // eax
  mxRadioButton *v16; // eax
  int v17; // ebx
  mxLabel *v18; // eax
  mxSlider *v19; // eax
  mxSlider *v20; // eax
  mxLabel *v21; // eax
  mxLabel *v22; // eax
  mxLabel *v23; // eax
  mxSlider *v24; // eax
  mxSlider *v25; // eax
  mxLabel *v26; // eax
  mxLabel *v27; // eax
  mxLabel *v28; // eax
  mxSlider *v29; // eax
  mxSlider *v30; // eax
  mxLabel *v31; // eax
  mxLabel *v32; // eax
  mxLabel *v33; // eax
  mxSlider *v34; // eax
  mxSlider *v35; // eax
  mxCheckBox *v36; // eax
  mxCheckBox *v37; // eax
  mxButton *v38; // eax
  mxLabel *v39; // eax
  mxLabel *v40; // eax
  mxLabel *v41; // eax
  mxLabel *v42; // eax
  mxLabel *v43; // eax
  mxSlider *v44; // eax
  mxSlider *v45; // eax
  mxLabel *v46; // eax
  mxLabel *v47; // eax
  mxSlider *v48; // eax
  mxSlider *v49; // eax
  mxLabel *v50; // eax
  mxLabel *v51; // eax
  mxSlider *v52; // eax
  mxSlider *v53; // eax
  mxLabel *v54; // eax
  mxLabel *v55; // eax
  mxSlider *v56; // eax
  mxSlider *v57; // eax
  mxLabel *v58; // eax
  mxLabel *v59; // eax
  mxLabel *v60; // eax
  mxRadioButton **pTaba; // [esp+1Ch] [ebp+8h]

  v3 = (mxWindow *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    v4 = mxWindow::mxWindow(this: v3, parent: this, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  else
    v4 = nullptr;
  mxTab::add(this: pTab, widget: v4, text: "Physics");
  v5 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v5 != nullptr )
    mxLabel::mxLabel(this: v5, parent: v4, x: 5, y: 33, w: 30, h: 18, label: "Mass");
  v6 = (mxLineEdit *)operator new(nSize: 0xCu);
  if ( v6 != nullptr )
    v7 = mxLineEdit::mxLineEdit(this: v6, parent: v4, x: 35, y: 30, w: 70, h: 22, label: WindowName, id: 7513, style: 0);
  else
    v7 = nullptr;
  this->leMass = v7;
  v8 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v8 != nullptr )
    v9 = mxChoice::mxChoice(this: v8, parent: v4, x: 5, y: 5, w: 345, h: 22, id: 7501);
  else
    v9 = nullptr;
  this->cPhysicsBone = v9;
  mxChoice::add(this: v9, item: "None");
  mxChoice::select(this: this->cPhysicsBone, index: 0);
  v10 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v10 != nullptr )
    mxCheckBox::mxCheckBox(this: v10, parent: v4, x: 5, y: 55, w: 100, h: 20, label: "Highlight", id: 2009);
  v11 = (mxRadioButton *)operator new(nSize: 0xCu);
  if ( v11 != nullptr )
    v12 = mxRadioButton::mxRadioButton(
            this: v11,
            parent: v4,
            x: 5,
            y: 80,
            w: 35,
            h: 22,
            label: "X",
            id: 7515,
            newGroup: true);
  else
    v12 = nullptr;
  this->rbConstraintAxis[0] = v12;
  v13 = (mxRadioButton *)operator new(nSize: 0xCu);
  if ( v13 != nullptr )
    v14 = mxRadioButton::mxRadioButton(
            this: v13,
            parent: v4,
            x: 40,
            y: 80,
            w: 35,
            h: 22,
            label: "Y",
            id: 7516,
            newGroup: false);
  else
    v14 = nullptr;
  this->rbConstraintAxis[1] = v14;
  v15 = (mxRadioButton *)operator new(nSize: 0xCu);
  if ( v15 != nullptr )
    v16 = mxRadioButton::mxRadioButton(
            this: v15,
            parent: v4,
            x: 75,
            y: 80,
            w: 35,
            h: 22,
            label: "Z",
            id: 7517,
            newGroup: false);
  else
    v16 = nullptr;
  this->rbConstraintAxis[2] = v16;
  v17 = 0;
  pTaba = this->rbConstraintAxis;
  do
    mxRadioButton::setChecked(this: *pTaba++, b: v17++ == 0);
  while ( v17 < 3 );
  v18 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v18 != nullptr )
    mxLabel::mxLabel(this: v18, parent: v4, x: 5, y: 105, w: 45, h: 18, label: "Friction");
  v19 = (mxSlider *)operator new(nSize: 0x18u);
  if ( v19 != nullptr )
    v20 = mxSlider::mxSlider(this: v19, parent: v4, x: 55, y: 105, w: 180, h: 18, id: 7508, style: 0);
  else
    v20 = nullptr;
  this->slPhysicsFriction = v20;
  mxSlider::setRange(this: v20, min: 0.0, max: 1000.0, ticks: 1000);
  mxSlider::setValue(this: this->slPhysicsFriction, value: 0.0);
  mxSlider::setSteps(this: this->slPhysicsFriction, line: 1, page: 1);
  v21 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v21 != nullptr )
    v22 = mxLabel::mxLabel(this: v21, parent: v4, x: 235, y: 105, w: 30, h: 18, label: "0");
  else
    v22 = nullptr;
  this->lPhysicsFriction = v22;
  v23 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v23 != nullptr )
    mxLabel::mxLabel(this: v23, parent: v4, x: 115, y: 30, w: 30, h: 18, label: "Min");
  v24 = (mxSlider *)operator new(nSize: 0x18u);
  if ( v24 != nullptr )
    v25 = mxSlider::mxSlider(this: v24, parent: v4, x: 135, y: 30, w: 180, h: 18, id: 7504, style: 0);
  else
    v25 = nullptr;
  this->slPhysicsConMin = v25;
  mxSlider::setRange(this: v25, min: -180.0, max: 180.0, ticks: 360);
  mxSlider::setValue(this: this->slPhysicsConMin, value: -90.0);
  mxSlider::setSteps(this: this->slPhysicsConMin, line: 1, page: 1);
  v26 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v26 != nullptr )
    v27 = mxLabel::mxLabel(this: v26, parent: v4, x: 315, y: 30, w: 30, h: 18, label: "-90");
  else
    v27 = nullptr;
  this->lPhysicsConMin = v27;
  v28 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v28 != nullptr )
    mxLabel::mxLabel(this: v28, parent: v4, x: 115, y: 55, w: 30, h: 18, label: "Max");
  v29 = (mxSlider *)operator new(nSize: 0x18u);
  if ( v29 != nullptr )
    v30 = mxSlider::mxSlider(this: v29, parent: v4, x: 135, y: 55, w: 180, h: 18, id: 7505, style: 0);
  else
    v30 = nullptr;
  this->slPhysicsConMax = v30;
  mxSlider::setRange(this: v30, min: -180.0, max: 180.0, ticks: 360);
  mxSlider::setValue(this: this->slPhysicsConMax, value: 90.0);
  mxSlider::setSteps(this: this->slPhysicsConMax, line: 1, page: 1);
  v31 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v31 != nullptr )
    v32 = mxLabel::mxLabel(this: v31, parent: v4, x: 315, y: 55, w: 30, h: 18, label: "90");
  else
    v32 = nullptr;
  this->lPhysicsConMax = v32;
  v33 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v33 != nullptr )
    mxLabel::mxLabel(this: v33, parent: v4, x: 115, y: 80, w: 30, h: 18, label: "Test");
  v34 = (mxSlider *)operator new(nSize: 0x18u);
  if ( v34 != nullptr )
    v35 = mxSlider::mxSlider(this: v34, parent: v4, x: 135, y: 80, w: 55, h: 18, id: 7506, style: 0);
  else
    v35 = nullptr;
  this->slPhysicsConTest = v35;
  mxSlider::setRange(this: v35, min: 0.0, max: 1.0, ticks: 100);
  mxSlider::setValue(this: this->slPhysicsConTest, value: 0.0);
  v36 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v36 != nullptr )
    v37 = mxCheckBox::mxCheckBox(this: v36, parent: v4, x: 200, y: 80, w: 50, h: 20, label: "Link", id: 7502);
  else
    v37 = nullptr;
  this->cbLinked = v37;
  mxToolTip::add(widget: v37, text: "Link mins/maxs to be symmetric");
  v38 = (mxButton *)operator new(nSize: 0xCu);
  if ( v38 != nullptr )
    mxButton::mxButton(this: v38, parent: v4, x: 250, y: 80, w: 80, h: 22, label: "Generate QC", id: 7514);
  v39 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v39 != nullptr )
    mxLabel::mxLabel(this: v39, parent: v4, x: 355, y: 5, w: 55, h: 18, label: "Mass Bias");
  v40 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v40 != nullptr )
    mxLabel::mxLabel(this: v40, parent: v4, x: 355, y: 30, w: 55, h: 18, label: "Inertia");
  v41 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v41 != nullptr )
    mxLabel::mxLabel(this: v41, parent: v4, x: 355, y: 55, w: 55, h: 18, label: "Damping");
  v42 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v42 != nullptr )
    mxLabel::mxLabel(this: v42, parent: v4, x: 355, y: 80, w: 55, h: 18, label: "Rot Damp");
  v43 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v43 != nullptr )
    mxLabel::mxLabel(this: v43, parent: v4, x: 355, y: 108, w: 55, h: 18, label: "Material");
  v44 = (mxSlider *)operator new(nSize: 0x18u);
  if ( v44 != nullptr )
    v45 = mxSlider::mxSlider(this: v44, parent: v4, x: 410, y: 5, w: 76, h: 18, id: 7507, style: 0);
  else
    v45 = nullptr;
  this->slPhysicsParamMassBias = v45;
  mxSlider::setRange(this: v45, min: 0.0, max: 10.0, ticks: 100);
  mxSlider::setValue(this: this->slPhysicsParamMassBias, value: 1.0);
  mxSlider::setSteps(this: this->slPhysicsParamMassBias, line: 1, page: 1);
  v46 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v46 != nullptr )
    v47 = mxLabel::mxLabel(this: v46, parent: v4, x: 490, y: 5, w: 30, h: 18, label: "1.0");
  else
    v47 = nullptr;
  this->lPhysicsParamMassBias = v47;
  v48 = (mxSlider *)operator new(nSize: 0x18u);
  if ( v48 != nullptr )
    v49 = mxSlider::mxSlider(this: v48, parent: v4, x: 410, y: 30, w: 76, h: 18, id: 7510, style: 0);
  else
    v49 = nullptr;
  this->slPhysicsParamInertia = v49;
  mxSlider::setRange(this: v49, min: 0.0, max: 10.0, ticks: 100);
  mxSlider::setValue(this: this->slPhysicsParamInertia, value: 1.0);
  mxSlider::setSteps(this: this->slPhysicsParamInertia, line: 1, page: 1);
  v50 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v50 != nullptr )
    v51 = mxLabel::mxLabel(this: v50, parent: v4, x: 490, y: 30, w: 30, h: 18, label: "1.0");
  else
    v51 = nullptr;
  this->lPhysicsParamInertia = v51;
  v52 = (mxSlider *)operator new(nSize: 0x18u);
  if ( v52 != nullptr )
    v53 = mxSlider::mxSlider(this: v52, parent: v4, x: 410, y: 55, w: 76, h: 18, id: 7511, style: 0);
  else
    v53 = nullptr;
  this->slPhysicsParamDamping = v53;
  mxSlider::setRange(this: v53, min: 0.0, max: 1.0, ticks: 100);
  mxSlider::setValue(this: this->slPhysicsParamDamping, value: 0.0099999998);
  mxSlider::setSteps(this: this->slPhysicsParamDamping, line: 1, page: 1);
  v54 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v54 != nullptr )
    v55 = mxLabel::mxLabel(this: v54, parent: v4, x: 490, y: 55, w: 30, h: 18, label: "0.5");
  else
    v55 = nullptr;
  this->lPhysicsParamDamping = v55;
  v56 = (mxSlider *)operator new(nSize: 0x18u);
  if ( v56 != nullptr )
    v57 = mxSlider::mxSlider(this: v56, parent: v4, x: 410, y: 80, w: 76, h: 18, id: 7512, style: 0);
  else
    v57 = nullptr;
  this->slPhysicsParamRotDamping = v57;
  mxSlider::setRange(this: v57, min: 0.0, max: 10.0, ticks: 200);
  mxSlider::setValue(this: this->slPhysicsParamRotDamping, value: 0.2);
  mxSlider::setSteps(this: this->slPhysicsParamRotDamping, line: 1, page: 1);
  v58 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v58 != nullptr )
    v59 = mxLabel::mxLabel(this: v58, parent: v4, x: 490, y: 80, w: 30, h: 18, label: "0.2");
  else
    v59 = nullptr;
  this->lPhysicsParamRotDamping = v59;
  v60 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v60 != nullptr )
    this->lPhysicsMaterial = mxLabel::mxLabel(this: v60, parent: v4, x: 410, y: 108, w: 110, h: 18, label: "default");
  else
    this->lPhysicsMaterial = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00406BC0
// Name: public: void ControlPanel::SetupIKRuleWindow(class mxTab __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::SetupIKRuleWindow(ControlPanel *this, mxTab *pTab)
{
  mxWindow *v3; // eax
  mxWindow *v4; // esi
  mxLabel *v5; // eax
  mxChoice *v6; // eax
  mxChoice *v7; // eax
  mxLabel *v8; // eax
  mxChoice *v9; // eax
  mxChoice *v10; // eax
  mxLabel *v11; // eax
  mxLabel *v12; // eax
  mxChoice *v13; // eax
  mxChoice *v14; // eax
  mxLabel *v15; // eax
  mxLabel *v16; // eax
  mxLineEdit *v17; // eax
  mxLineEdit *v18; // eax
  mxCheckBox *v19; // eax
  mxCheckBox *v20; // eax
  mxButton *v21; // eax
  mxLineEdit2 *v22; // eax
  mxLineEdit2 *v23; // eax
  mxButton *v24; // eax
  mxLineEdit2 *v25; // eax
  mxLineEdit2 *v26; // eax
  mxButton *v27; // eax
  mxLineEdit2 *v28; // eax
  mxLineEdit2 *v29; // eax
  mxButton *v30; // eax
  mxLineEdit2 *v31; // eax
  mxLineEdit2 *v32; // eax
  mxCheckBox *v33; // eax
  mxCheckBox *v34; // eax
  mxButton *v35; // eax
  mxLineEdit2 *v36; // eax
  mxLineEdit2 *v37; // eax
  mxLabel *v38; // eax
  mxChoice *v39; // eax
  mxChoice *v40; // eax
  mxLabel *v41; // eax
  mxLineEdit2 *v42; // eax

  v3 = (mxWindow *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    v4 = mxWindow::mxWindow(this: v3, parent: this, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  else
    v4 = nullptr;
  mxTab::add(this: pTab, widget: v4, text: "IKRule");
  v5 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v5 != nullptr )
    mxLabel::mxLabel(this: v5, parent: v4, x: 5, y: 5, w: 80, h: 20, label: "Chain:");
  v6 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v6 != nullptr )
    v7 = mxChoice::mxChoice(this: v6, parent: v4, x: 90, y: 5, w: 50, h: 20, id: 9000);
  else
    v7 = nullptr;
  this->cIKChain = v7;
  mxChoice::add(this: v7, item: "lfoot");
  mxChoice::add(this: this->cIKChain, item: "rfoot");
  mxChoice::add(this: this->cIKChain, item: "lhand");
  mxChoice::add(this: this->cIKChain, item: "rhand");
  mxChoice::select(this: this->cIKChain, index: 0);
  mxToolTip::add(widget: this->cIKChain, text: "Select IK Chain");
  v8 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v8 != nullptr )
    mxLabel::mxLabel(this: v8, parent: v4, x: 145, y: 5, w: 80, h: 20, label: "Type:");
  v9 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v9 != nullptr )
    v10 = mxChoice::mxChoice(this: v9, parent: v4, x: 230, y: 5, w: 80, h: 20, id: 9001);
  else
    v10 = nullptr;
  this->cIKType = v10;
  mxChoice::add(this: v10, item: "footstep");
  mxChoice::add(this: this->cIKType, item: "touch");
  mxChoice::add(this: this->cIKType, item: "release");
  mxChoice::add(this: this->cIKType, item: "attachment");
  mxChoice::add(this: this->cIKType, item: "unlatch");
  mxChoice::select(this: this->cIKType, index: 0);
  mxToolTip::add(widget: this->cIKType, text: "Select IK Type");
  v11 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v11 != nullptr )
    v12 = mxLabel::mxLabel(this: v11, parent: v4, x: 315, y: 5, w: 80, h: 20, label: "Bone:");
  else
    v12 = nullptr;
  this->lIKTouch = v12;
  v13 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v13 != nullptr )
    v14 = mxChoice::mxChoice(this: v13, parent: v4, x: 400, y: 5, w: 200, h: 20, id: 9002);
  else
    v14 = nullptr;
  this->cIKTouch = v14;
  PopulateBoneList(pChoice: v14, bAlwaysAddNone: false);
  mxToolTip::add(widget: this->cIKTouch, text: "Select Touched Bone");
  v15 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v15 != nullptr )
    v16 = mxLabel::mxLabel(this: v15, parent: v4, x: 315, y: 5, w: 80, h: 20, label: "Attachment:");
  else
    v16 = nullptr;
  this->lIKAttachment = v16;
  v17 = (mxLineEdit *)operator new(nSize: 0xCu);
  if ( v17 != nullptr )
    v18 = mxLineEdit::mxLineEdit(
            this: v17,
            parent: v4,
            x: 400,
            y: 5,
            w: 80,
            h: 20,
            label: WindowName,
            id: 9003,
            style: 0);
  else
    v18 = nullptr;
  this->leIKAttachment = v18;
  v19 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v19 != nullptr )
    v20 = mxCheckBox::mxCheckBox(this: v19, parent: v4, x: 5, y: 30, w: 80, h: 20, label: "Range", id: 9004);
  else
    v20 = nullptr;
  this->cbIKRangeToggle = v20;
  mxToolTip::add(widget: v20, text: "Toggle range option");
  v21 = (mxButton *)operator new(nSize: 0xCu);
  if ( v21 != nullptr )
    mxButton::mxButton(this: v21, parent: v4, x: 90, y: 30, w: 30, h: 20, label: "start", id: 9009);
  v22 = (mxLineEdit2 *)operator new(nSize: 0xCu);
  if ( v22 != nullptr )
    v23 = mxLineEdit2::mxLineEdit2(this: v22, parent: v4, x: 120, y: 30, w: 35, h: 20, label: "..", id: 9005, style: 0);
  else
    v23 = nullptr;
  this->leIKRangeStart = v23;
  v24 = (mxButton *)operator new(nSize: 0xCu);
  if ( v24 != nullptr )
    mxButton::mxButton(this: v24, parent: v4, x: 160, y: 30, w: 30, h: 20, label: "peak", id: 9010);
  v25 = (mxLineEdit2 *)operator new(nSize: 0xCu);
  if ( v25 != nullptr )
    v26 = mxLineEdit2::mxLineEdit2(this: v25, parent: v4, x: 190, y: 30, w: 35, h: 20, label: "..", id: 9006, style: 0);
  else
    v26 = nullptr;
  this->leIKRangePeak = v26;
  v27 = (mxButton *)operator new(nSize: 0xCu);
  if ( v27 != nullptr )
    mxButton::mxButton(this: v27, parent: v4, x: 230, y: 30, w: 30, h: 20, label: "tail", id: 9011);
  v28 = (mxLineEdit2 *)operator new(nSize: 0xCu);
  if ( v28 != nullptr )
    v29 = mxLineEdit2::mxLineEdit2(this: v28, parent: v4, x: 260, y: 30, w: 35, h: 20, label: "..", id: 9007, style: 0);
  else
    v29 = nullptr;
  this->leIKRangeTail = v29;
  v30 = (mxButton *)operator new(nSize: 0xCu);
  if ( v30 != nullptr )
    mxButton::mxButton(this: v30, parent: v4, x: 300, y: 30, w: 30, h: 20, label: "end", id: 9012);
  v31 = (mxLineEdit2 *)operator new(nSize: 0xCu);
  if ( v31 != nullptr )
    v32 = mxLineEdit2::mxLineEdit2(this: v31, parent: v4, x: 330, y: 30, w: 35, h: 20, label: "..", id: 9008, style: 0);
  else
    v32 = nullptr;
  this->leIKRangeEnd = v32;
  v33 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v33 != nullptr )
    v34 = mxCheckBox::mxCheckBox(this: v33, parent: v4, x: 5, y: 55, w: 80, h: 20, label: "Contact", id: 9013);
  else
    v34 = nullptr;
  this->cbIKContactToggle = v34;
  mxToolTip::add(widget: v34, text: "Toggle contact option");
  v35 = (mxButton *)operator new(nSize: 0xCu);
  if ( v35 != nullptr )
    mxButton::mxButton(this: v35, parent: v4, x: 90, y: 55, w: 30, h: 20, label: "frame", id: 9014);
  v36 = (mxLineEdit2 *)operator new(nSize: 0xCu);
  if ( v36 != nullptr )
    v37 = mxLineEdit2::mxLineEdit2(
            this: v36,
            parent: v4,
            x: 120,
            y: 55,
            w: 35,
            h: 20,
            label: WindowName,
            id: 9015,
            style: 0);
  else
    v37 = nullptr;
  this->leIKContactFrame = v37;
  v38 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v38 != nullptr )
    mxLabel::mxLabel(this: v38, parent: v4, x: 5, y: 80, w: 80, h: 20, label: "Transform using:");
  v39 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v39 != nullptr )
    v40 = mxChoice::mxChoice(this: v39, parent: v4, x: 90, y: 80, w: 80, h: 20, id: 9016);
  else
    v40 = nullptr;
  this->cIKUsing = v40;
  mxChoice::add(this: v40, item: "neither");
  mxChoice::add(this: this->cIKUsing, item: "source");
  mxChoice::add(this: this->cIKUsing, item: "sequence");
  mxChoice::select(this: this->cIKUsing, index: 0);
  mxToolTip::add(widget: this->cIKUsing, text: "Choose Transform To Use");
  v41 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v41 != nullptr )
    mxLabel::mxLabel(this: v41, parent: v4, x: 5, y: 105, w: 80, h: 20, label: "QC String:");
  v42 = (mxLineEdit2 *)operator new(nSize: 0xCu);
  if ( v42 != nullptr )
    this->leIKQCString = mxLineEdit2::mxLineEdit2(
                           this: v42,
                           parent: v4,
                           x: 90,
                           y: 105,
                           w: 500,
                           h: 20,
                           label: WindowName,
                           id: 9017,
                           style: 0);
  else
    this->leIKQCString = nullptr;
  ControlPanel::UpdateIKRuleWindow(this);
}

//------------------------------------------------------------------------------
// Address: 0x004071C0
// Name: public: void ControlPanel::SetupEventWindow(class mxTab __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::SetupEventWindow(ControlPanel *this, mxTab *pTab)
{
  mxWindow *v3; // eax
  mxWindow *v4; // esi
  mxLabel *v5; // eax
  mxButton *v6; // eax
  mxButton *v7; // eax
  mxLineEdit2 *v8; // eax
  mxLineEdit2 *v9; // eax
  mxListBox *v10; // eax
  mxListBox *v11; // eax
  mxLabel *v12; // eax
  mxLineEdit2 *v13; // eax
  mxLineEdit2 *v14; // eax
  mxLabel *v15; // eax
  mxLabel *v16; // eax
  mxListBox *v17; // eax
  mxListBox *v18; // eax

  v3 = (mxWindow *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    v4 = mxWindow::mxWindow(this: v3, parent: this, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  else
    v4 = nullptr;
  mxTab::add(this: pTab, widget: v4, text: "Events");
  v5 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v5 != nullptr )
    mxLabel::mxLabel(this: v5, parent: v4, x: 5, y: 5, w: 80, h: 20, label: "Sound:");
  v6 = (mxButton *)operator new(nSize: 0xCu);
  if ( v6 != nullptr )
    v7 = mxButton::mxButton(this: v6, parent: v4, x: 90, y: 5, w: 30, h: 20, label: "frame", id: 6000);
  else
    v7 = nullptr;
  mxToolTip::add(widget: v7, text: "Set sound start at the current frame");
  v8 = (mxLineEdit2 *)operator new(nSize: 0xCu);
  if ( v8 != nullptr )
    v9 = mxLineEdit2::mxLineEdit2(this: v8, parent: v4, x: 120, y: 5, w: 35, h: 20, label: "0", id: 6001, style: 0);
  else
    v9 = nullptr;
  this->leEventSoundFrame = v9;
  v10 = (mxListBox *)operator new(nSize: 0xCu);
  if ( v10 != nullptr )
    v11 = mxListBox::mxListBox(this: v10, parent: v4, x: 160, y: 5, w: 300, h: 170, id: 6002, style: 0);
  else
    v11 = nullptr;
  this->lbEventSoundName = v11;
  PopulateSoundNameList(pListBox: v11);
  mxToolTip::add(widget: this->lbEventSoundName, text: "Select Sound Name");
  v12 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v12 != nullptr )
    mxLabel::mxLabel(this: v12, parent: v4, x: 5, y: 170, w: 80, h: 20, label: "QC String:");
  v13 = (mxLineEdit2 *)operator new(nSize: 0xCu);
  if ( v13 != nullptr )
    v14 = mxLineEdit2::mxLineEdit2(
            this: v13,
            parent: v4,
            x: 90,
            y: 170,
            w: 450,
            h: 20,
            label: WindowName,
            id: 6003,
            style: 0);
  else
    v14 = nullptr;
  this->leEventQCString = v14;
  ControlPanel::BuildEventQCString(this);
  v15 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v15 != nullptr )
    v16 = mxLabel::mxLabel(this: v15, parent: v4, x: 460, y: 5, w: 300, h: 20, label: WindowName);
  else
    v16 = nullptr;
  this->lEventSequence = v16;
  v17 = (mxListBox *)operator new(nSize: 0xCu);
  if ( v17 != nullptr )
    v18 = mxListBox::mxListBox(this: v17, parent: v4, x: 460, y: 25, w: 300, h: 150, id: 0, style: 0);
  else
    v18 = nullptr;
  this->lbEventHistory = v18;
  this->m_lastEventCycle = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004073C0
// Name: public: void ControlPanel::setSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setSequence(ControlPanel *this, int index)
{
  double CurrentVelocity; // st7
  char string[100]; // [esp+10h] [ebp-64h] BYREF

  mxChoice::select(this: this->cSequence[0], index: this->iSequenceToSelection[0][index]);
  StudioModel::SetSequence(this: g_pStudioModel, iSequence: index);
  ControlPanel::updateFrameSelection(this);
  CurrentVelocity = StudioModel::GetCurrentVelocity(this: g_pStudioModel);
  sprintf(string, format: "Speed: %.2f", CurrentVelocity);
  mxWidget::setLabel(this: this->laGroundSpeed, format: string);
}

//------------------------------------------------------------------------------
// Address: 0x00407430
// Name: public: void ControlPanel::setOverlaySequence(int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setOverlaySequence(ControlPanel *this, int num, int index, float weight)
{
  mxChoice::select(this: this->cSequence[num], index: this->iSequenceToSelection[0][index]);
  StudioModel::SetOverlaySequence(this: g_pStudioModel, iLayer: num - 1, iSequence: index, flWeight: weight);
  mxSlider::setValue(this: this->slSequence[num], value: weight);
  ControlPanel::updateFrameSelection(this);
}

//------------------------------------------------------------------------------
// Address: 0x004074A0
// Name: public: void ControlPanel::updateFrameSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::updateFrameSlider(ControlPanel *this)
{
  int v2; // esi
  mxRadioButton **rbFrameSelection; // edi
  double Frame; // st7
  char buf[128]; // [esp+14h] [ebp-84h] BYREF
  float flFrame; // [esp+94h] [ebp-4h]

  v2 = 0;
  rbFrameSelection = this->rbFrameSelection;
  while ( !mxRadioButton::isChecked(this: *rbFrameSelection) )
  {
    ++v2;
    ++rbFrameSelection;
    if ( v2 >= 5 )
    {
      v2 = 0;
      break;
    }
  }
  Frame = StudioModel::GetFrame(this: g_pStudioModel, iLayer: v2);
  flFrame = Frame;
  sprintf(string: buf, format: "%3.1f", Frame);
  mxWidget::setLabel(this: this->lForcedFrame, format: buf);
  mxSlider::setValue(this: this->slForceFrame, value: flFrame);
  ControlPanel::UpdateEventHistory(this);
}

//------------------------------------------------------------------------------
// Address: 0x00407530
// Name: public: void ControlPanel::setSpeedScale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setSpeedScale(ControlPanel *this, float scale)
{
  double FPS; // st7
  char string[32]; // [esp+14h] [ebp-20h] BYREF

  mxSlider::setValue(this: this->slSpeedScale, value: scale);
  g_viewerSettings.speedScale = scale;
  FPS = StudioModel::GetFPS(this: g_pStudioModel);
  sprintf(string, format: "x %.2f = %.1f fps", g_viewerSettings.speedScale, FPS * g_viewerSettings.speedScale);
  mxWidget::setLabel(this: this->laFPS, format: string);
}

//------------------------------------------------------------------------------
// Address: 0x004075B0
// Name: public: void ControlPanel::setModelInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setModelInfo(ControlPanel *this)
{
  StudioModel *v1; // eax
  CStudioHdr *m_pStudioHdr; // esi
  CStudioHdr **p_m_pStudioHdr; // edi
  ControlPanel *v4; // ebx
  const studiohdr_t *v5; // eax
  const studiohdr_t *v6; // ecx
  int numhitboxsets; // eax
  int v8; // edi
  int v9; // edx
  int i; // ebx
  char *v11; // eax
  int NumSeq_Internal; // eax
  int numbodyparts; // edi
  int numskinfamilies; // ebx
  int NumAttachments; // eax

  v1 = g_pStudioModel;
  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  v4 = this;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
      CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
      m_pStudioHdr = *p_m_pStudioHdr;
      if ( (*p_m_pStudioHdr)->m_pStudioHdr == nullptr )
        return;
      v1 = g_pStudioModel;
    }
    if ( m_pStudioHdr != nullptr )
    {
      if ( v1 != nullptr && !v4->m_bVMTInfoLoaded )
        ControlPanel::UpdateMaterialList(this: v4);
      v6 = m_pStudioHdr->m_pStudioHdr;
      if ( checkSum != m_pStudioHdr->m_pStudioHdr->checksum
        || boneLODCount != g_DrawModelResults.m_NumHardwareBones
        || numBatches != g_DrawModelResults.m_NumBatches )
      {
        checkSum = m_pStudioHdr->m_pStudioHdr->checksum;
        numhitboxsets = v6->numhitboxsets;
        boneLODCount = g_DrawModelResults.m_NumHardwareBones;
        v8 = 0;
        numBatches = g_DrawModelResults.m_NumBatches;
        if ( numhitboxsets > 0 )
        {
          v9 = 0;
          for ( i = numhitboxsets; i != 0; --i )
          {
            v11 = (char *)v6 + v9 + v6->hitboxsetindex;
            if ( v11 != nullptr )
              v11 = *((char **)v11 + 1);
            v8 += (int)v11;
            v9 += 12;
          }
          v4 = this;
        }
        if ( m_pStudioHdr->m_pVModel != nullptr )
          NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr);
        else
          NumSeq_Internal = v6->numlocalseq;
        sprintf(
          string: str,
          format: "Total bones: %d\nHW Bones: %d\nBatches: %d\nBone Controllers: %d\nHit Boxes: %d in %d sets\nSequences: %d\n",
          m_pStudioHdr->m_pStudioHdr->numbones,
          boneLODCount,
          numBatches,
          m_pStudioHdr->m_pStudioHdr->numbonecontrollers,
          v8,
          m_pStudioHdr->m_pStudioHdr->numhitboxsets,
          NumSeq_Internal);
        mxWidget::setLabel(this: v4->lModelInfo1, format: str);
        numbodyparts = m_pStudioHdr->m_pStudioHdr->numbodyparts;
        numskinfamilies = m_pStudioHdr->m_pStudioHdr->numskinfamilies;
        NumAttachments = CStudioHdr::GetNumAttachments(this: m_pStudioHdr);
        sprintf(
          string: str,
          format: "Materials: %d\nSkin Families: %d\nBodyparts: %d\nAttachments: %d\n",
          g_DrawModelResults.m_NumMaterials,
          numskinfamilies,
          numbodyparts,
          NumAttachments);
        mxWidget::setLabel(this: this->lModelInfo2, format: str);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407740
// Name: public: void ControlPanel::viewmodelView(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ControlPanel::viewmodelView(ControlPanel *this@<ecx>, int a2@<esi>)
{
  char string[64]; // [esp+Ch] [ebp-40h] BYREF

  g_pStudioModel->m_origin.x = 0.0;
  g_pStudioModel->m_origin.y = 0.0;
  g_pStudioModel->m_origin.z = 0.0;
  g_pStudioModel->m_angles.x = 0.0;
  g_pStudioModel->m_angles.y = 180.0;
  g_pStudioModel->m_angles.z = 0.0;
  g_viewerSettings.lightrot.x = 0.0;
  g_viewerSettings.lightrot.z = 0.0;
  g_viewerSettings.fov = 54.0;
  g_viewerSettings.lightrot.y = 180.0;
  sprintf(string, format: "%.0f", 54.0);
  mxWidget::setLabel(this: this->leFOV, format: string);
  ((void (__thiscall *)(MatSysWindow *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->d_MatSysWindow->redraw)(
    a1: this->d_MatSysWindow,
    a2,
    a3: *(_DWORD *)string,
    a4: *(_DWORD *)&string[4],
    a5: *(_DWORD *)&string[8],
    a6: *(_DWORD *)&string[12],
    a7: *(_DWORD *)&string[16],
    a8: *(_DWORD *)&string[20],
    a9: *(_DWORD *)&string[24],
    a10: *(_DWORD *)&string[28],
    a11: *(_DWORD *)&string[32],
    a12: *(_DWORD *)&string[36],
    a13: *(_DWORD *)&string[40],
    a14: *(_DWORD *)&string[44],
    a15: *(_DWORD *)&string[48],
    a16: *(_DWORD *)&string[52],
    a17: *(_DWORD *)&string[56]);
}

//------------------------------------------------------------------------------
// Address: 0x00407800
// Name: public: void ControlPanel::dotaView(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ControlPanel::dotaView(ControlPanel *this@<ecx>, int a2@<esi>)
{
  char string[64]; // [esp+Ch] [ebp-40h] BYREF

  g_pStudioModel->m_origin.x = 1334.0;
  g_pStudioModel->m_origin.y = 0.0;
  g_pStudioModel->m_origin.z = 0.0;
  g_pStudioModel->m_angles.x = -60.0;
  g_pStudioModel->m_angles.y = 180.0;
  g_pStudioModel->m_angles.z = 0.0;
  g_viewerSettings.lightrot.x = 0.0;
  g_viewerSettings.lightrot.z = 0.0;
  g_viewerSettings.fov = 65.0;
  g_viewerSettings.lightrot.y = 180.0;
  sprintf(string, format: "%.0f", 65.0);
  mxWidget::setLabel(this: this->leFOV, format: string);
  ((void (__thiscall *)(MatSysWindow *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->d_MatSysWindow->redraw)(
    a1: this->d_MatSysWindow,
    a2,
    a3: *(_DWORD *)string,
    a4: *(_DWORD *)&string[4],
    a5: *(_DWORD *)&string[8],
    a6: *(_DWORD *)&string[12],
    a7: *(_DWORD *)&string[16],
    a8: *(_DWORD *)&string[20],
    a9: *(_DWORD *)&string[24],
    a10: *(_DWORD *)&string[28],
    a11: *(_DWORD *)&string[32],
    a12: *(_DWORD *)&string[36],
    a13: *(_DWORD *)&string[40],
    a14: *(_DWORD *)&string[44],
    a15: *(_DWORD *)&string[48],
    a16: *(_DWORD *)&string[52],
    a17: *(_DWORD *)&string[56]);
}

//------------------------------------------------------------------------------
// Address: 0x004078D0
// Name: public: void ControlPanel::setupPhysicsAxis(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setupPhysicsAxis(ControlPanel *this, int boneIndex, int axis)
{
  int v4; // ebx
  mxSlider *slPhysicsConMin; // ebx
  double Value; // st7
  mxSlider *slPhysicsConMax; // ebx
  double v8; // st7
  mxSlider *slPhysicsFriction; // ebx
  double v10; // st7
  constraint_ragdollparams_t constraint; // [esp+14h] [ebp-104h] BYREF
  char string[80]; // [esp+C8h] [ebp-50h] BYREF
  mxRadioButton **boneIndexa; // [esp+120h] [ebp+8h]
  mxLabel *boneIndexb; // [esp+120h] [ebp+8h]
  mxLabel *boneIndexc; // [esp+120h] [ebp+8h]
  mxLabel *boneIndexd; // [esp+120h] [ebp+8h]

  StudioModel::Physics_GetData(this: g_pStudioModel, boneIndex, psolid: nullptr, pConstraint: &constraint);
  v4 = 0;
  boneIndexa = this->rbConstraintAxis;
  do
    mxRadioButton::setChecked(this: *boneIndexa++, b: v4++ == axis);
  while ( v4 < 3 );
  slPhysicsConMin = this->slPhysicsConMin;
  boneIndexb = this->lPhysicsConMin;
  mxSlider::setValue(this: slPhysicsConMin, value: constraint.axes[axis].minRotation);
  Value = mxSlider::getValue(this: slPhysicsConMin);
  sprintf(string, format: "%0.2f", Value);
  mxWidget::setLabel(this: boneIndexb, format: string);
  slPhysicsConMax = this->slPhysicsConMax;
  boneIndexc = this->lPhysicsConMax;
  mxSlider::setValue(this: slPhysicsConMax, value: constraint.axes[axis].maxRotation);
  v8 = mxSlider::getValue(this: slPhysicsConMax);
  sprintf(string, format: "%0.2f", v8);
  mxWidget::setLabel(this: boneIndexc, format: string);
  slPhysicsFriction = this->slPhysicsFriction;
  boneIndexd = this->lPhysicsFriction;
  mxSlider::setValue(this: slPhysicsFriction, value: constraint.axes[axis].torque);
  v10 = mxSlider::getValue(this: slPhysicsFriction);
  sprintf(string, format: "%0.2f", v10);
  mxWidget::setLabel(this: boneIndexd, format: string);
  StudioModel::Physics_SetPreview(this: g_pStudioModel, previewBone: -1, axis: 0, t: 0.0);
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00407A40
// Name: public: void ControlPanel::writePhysicsData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::writePhysicsData(ControlPanel *this)
{
  int v2; // edi
  mxRadioButton **rbConstraintAxis; // ebx
  int v4; // ebx
  const char *Label; // eax
  float v6; // xmm0_4
  int v7; // edi
  mxSlider *slPhysicsParamInertia; // ecx
  hlmvsolid_t solid; // [esp+10h] [ebp-700h] BYREF
  constraint_ragdollparams_t constraint; // [esp+658h] [ebp-B8h] BYREF
  float mass; // [esp+70Ch] [ebp-4h]

  mass = COERCE_FLOAT(mxChoice::getSelectedIndex(this: this->cPhysicsBone));
  v2 = 0;
  rbConstraintAxis = this->rbConstraintAxis;
  while ( !mxRadioButton::isChecked(this: *rbConstraintAxis) )
  {
    ++v2;
    ++rbConstraintAxis;
    if ( v2 >= 3 )
    {
      v2 = 0;
      break;
    }
  }
  v4 = LODWORD(mass);
  StudioModel::Physics_GetData(
    this: g_pStudioModel,
    boneIndex: SLODWORD(mass),
    psolid: &solid,
    pConstraint: &constraint);
  Label = mxWidget::getLabel(this: this->leMass);
  v6 = 0.0;
  if ( Label != nullptr )
  {
    mass = atof(nptr: Label);
    v6 = mass;
  }
  StudioModel::Physics_SetMass(this: g_pStudioModel, mass: v6);
  v7 = v2;
  constraint.axes[v7].minRotation = mxSlider::getValue(this: this->slPhysicsConMin);
  constraint.axes[v7].maxRotation = mxSlider::getValue(this: this->slPhysicsConMax);
  constraint.axes[v7].torque = mxSlider::getValue(this: this->slPhysicsFriction);
  solid.massBias = mxSlider::getValue(this: this->slPhysicsParamMassBias);
  slPhysicsParamInertia = this->slPhysicsParamInertia;
  solid.index = v4;
  solid.params.inertia = mxSlider::getValue(this: slPhysicsParamInertia);
  solid.params.damping = mxSlider::getValue(this: this->slPhysicsParamDamping);
  solid.params.rotdamping = mxSlider::getValue(this: this->slPhysicsParamRotDamping);
  StudioModel::Physics_SetData(this: g_pStudioModel, boneIndex: v4, psolid: &solid, pConstraint: &constraint);
}

//------------------------------------------------------------------------------
// Address: 0x00407B70
// Name: public: void ControlPanel::RestoreSelectedSequences(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::RestoreSelectedSequences(ControlPanel *this)
{
  int i; // edi
  int v3; // ebx
  double CurrentVelocity; // st7
  mxChoice *v5; // ecx
  int flWeight_4; // [esp+4h] [ebp-78h]
  char string[100]; // [esp+14h] [ebp-68h] BYREF
  float value; // [esp+78h] [ebp-4h]

  for ( i = 0; i < 5; ++i )
  {
    v3 = this->m_iSavedSequences[i];
    if ( i != 0 )
    {
      v5 = this->cSequence[i];
      flWeight_4 = this->iSequenceToSelection[0][v3];
      value = this->m_flSavedWeights[i];
      mxChoice::select(this: v5, index: flWeight_4);
      StudioModel::SetOverlaySequence(this: g_pStudioModel, iLayer: i - 1, iSequence: v3, flWeight: value);
      mxSlider::setValue(this: this->slSequence[i], value);
      ControlPanel::updateFrameSelection(this);
    }
    else
    {
      mxChoice::select(this: this->cSequence[0], index: this->iSequenceToSelection[0][v3]);
      StudioModel::SetSequence(this: g_pStudioModel, iSequence: v3);
      ControlPanel::updateFrameSelection(this);
      CurrentVelocity = StudioModel::GetCurrentVelocity(this: g_pStudioModel);
      sprintf(string, format: "Speed: %.2f", CurrentVelocity);
      mxWidget::setLabel(this: this->laGroundSpeed, format: string);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407CF0
// Name: public: char const __near * CDmElement::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmElement::GetName(CDmElement *this)
{
  const char *result; // eax

  result = this->m_Name.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return WindowName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407D00
// Name: private: void CBoneControlWindow::ComputeHitboxSetList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::ComputeHitboxSetList(CBoneControlWindow *this)
{
  StudioModel *v2; // eax
  int v3; // esi
  int v4; // edi
  const char *v5; // eax

  mxChoice::removeAll(this: this->m_cHitboxSet);
  v2 = g_pStudioModel;
  v3 = 0;
  if ( g_pStudioModel->m_HitboxSets.m_Size > 0 )
  {
    v4 = 0;
    do
    {
      v5 = CUtlString::operator char const *(this: &v2->m_HitboxSets.m_Memory.m_pMemory[v4].m_Name);
      mxChoice::add(this: this->m_cHitboxSet, item: v5);
      v2 = g_pStudioModel;
      ++v3;
      ++v4;
    }
    while ( v3 < g_pStudioModel->m_HitboxSets.m_Size );
  }
  mxChoice::select(this: this->m_cHitboxSet, index: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00407D60
// Name: private: void CBoneControlWindow::RefreshHitbox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::RefreshHitbox(CBoneControlWindow *this)
{
  int m_nHitboxSet; // ecx
  StudioModel *v3; // eax
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *m_pMemory; // ecx
  int m_Hitbox_low; // eax
  float x; // xmm0_4
  float v7; // xmm1_4
  float y; // xmm2_4
  int group; // edx
  float z; // xmm6_4
  float *p_bone; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  const char *v14; // eax
  float size; // [esp+Ch] [ebp-18h]
  float size_4; // [esp+10h] [ebp-14h]
  float origin; // [esp+18h] [ebp-Ch]
  float origin_4; // [esp+1Ch] [ebp-8h]
  float origin_8; // [esp+20h] [ebp-4h]

  m_nHitboxSet = this->m_nHitboxSet;
  if ( m_nHitboxSet < 0 || (v3 = g_pStudioModel, m_nHitboxSet >= g_pStudioModel->m_HitboxSets.m_Size) )
  {
    this->m_nHitboxSet = 0;
    v3 = g_pStudioModel;
  }
  if ( this->m_Hitbox < 0 || v3->m_HitboxSets.m_Size <= 0 )
  {
    mxWidget::setLabel(this: this->m_eHitboxGroup, format: WindowName);
    mxWidget::setLabel(this: this->m_eHitboxName, format: WindowName);
    mxWidget::setLabel(this: this->m_eOriginX, format: WindowName);
    mxWidget::setLabel(this: this->m_eOriginY, format: WindowName);
    mxWidget::setLabel(this: this->m_eOriginZ, format: WindowName);
    mxWidget::setLabel(this: this->m_eSizeX, format: WindowName);
    mxWidget::setLabel(this: this->m_eSizeY, format: WindowName);
    mxWidget::setLabel(this: this->m_eSizeZ, format: WindowName);
  }
  else
  {
    m_pMemory = v3->m_HitboxSets.m_Memory.m_pMemory[this->m_nHitboxSet].m_Hitboxes.m_Memory.m_pMemory;
    m_Hitbox_low = LOWORD(this->m_Hitbox);
    x = m_pMemory[m_Hitbox_low].m_Element.m_BBox.bbmin.x;
    v7 = m_pMemory[m_Hitbox_low].m_Element.m_BBox.bbmax.x;
    y = m_pMemory[m_Hitbox_low].m_Element.m_BBox.bbmax.y;
    group = m_pMemory[m_Hitbox_low].m_Element.m_BBox.group;
    z = m_pMemory[m_Hitbox_low].m_Element.m_BBox.bbmax.z;
    p_bone = (float *)&m_pMemory[m_Hitbox_low].m_Element.m_BBox.bone;
    size = v7 - x;
    v12 = p_bone[3];
    size_4 = y - v12;
    v13 = p_bone[4];
    origin = (float)(x + p_bone[5]) * 0.5;
    origin_4 = (float)(v12 + p_bone[6]) * 0.5;
    origin_8 = (float)(v13 + p_bone[7]) * 0.5;
    mxWidget::setLabel(this: this->m_eHitboxGroup, format: "%i", group);
    v14 = CUtlString::operator char const *(this: &g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory[this->m_nHitboxSet].m_Hitboxes.m_Memory.m_pMemory[LOWORD(this->m_Hitbox)].m_Element.m_Name);
    mxWidget::setLabel(this: this->m_eHitboxName, format: v14);
    mxWidget::setLabel(this: this->m_eOriginX, format: "%.3f", origin);
    mxWidget::setLabel(this: this->m_eOriginY, format: "%.3f", origin_4);
    mxWidget::setLabel(this: this->m_eOriginZ, format: "%.3f", origin_8);
    mxWidget::setLabel(this: this->m_eSizeX, format: "%.3f", size);
    mxWidget::setLabel(this: this->m_eSizeY, format: "%.3f", size_4);
    mxWidget::setLabel(this: this->m_eSizeZ, format: "%.3f", (float)(z - v13));
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407FC0
// Name: private: void CBoneControlWindow::OnHitboxSelected(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnHitboxSelected(CBoneControlWindow *this, int hitbox)
{
  int m_nHitboxSet; // eax
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *v4; // ecx
  int m_Bone; // eax
  int v6; // edx
  CUtlVector<int,CUtlMemory<int,int> > *v7; // eax
  mxCheckBox *m_cHitboxHighlight; // ecx
  CStudioHdr *m_pStudioHdr; // esi
  CStudioHdr **p_m_pStudioHdr; // ebx
  const studiohdr_t *v11; // eax

  m_nHitboxSet = this->m_nHitboxSet;
  if ( m_nHitboxSet < 0 || m_nHitboxSet >= g_pStudioModel->m_HitboxSets.m_Size )
    this->m_nHitboxSet = 0;
  mxChoice::select(this: this->m_cHitbox, index: hitbox);
  if ( this->m_SetBoneHitBoxes.m_Size != 0
    && (v4 = &this->m_SetBoneHitBoxes.m_Memory.m_pMemory[this->m_nHitboxSet], m_Bone = this->m_Bone, v4->m_Size > m_Bone)
    && (v6 = m_Bone, v7 = &v4->m_Memory.m_pMemory[m_Bone], v4->m_Memory.m_pMemory[v6].m_Size > hitbox) )
  {
    m_cHitboxHighlight = this->m_cHitboxHighlight;
    this->m_Hitbox = v7->m_Memory.m_pMemory[hitbox];
    if ( mxRadioButton::isChecked(this: (mxRadioButton *)m_cHitboxHighlight) )
    {
      g_viewerSettings.highlightHitbox = this->m_Hitbox;
      CBoneControlWindow::RefreshHitbox(this);
      return;
    }
  }
  else
  {
    this->m_Hitbox = -1;
    m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
    p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v11 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
      CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v11, mdlcache: nullptr);
      m_pStudioHdr = (*p_m_pStudioHdr)->m_pStudioHdr != nullptr ? *p_m_pStudioHdr : nullptr;
    }
    if ( mxRadioButton::isChecked(this: (mxRadioButton *)this->m_cHitboxHighlight) )
    {
      if ( m_pStudioHdr != nullptr )
      {
        g_viewerSettings.highlightHitbox = m_pStudioHdr->m_pStudioHdr->numbones + 1;
        CBoneControlWindow::RefreshHitbox(this);
        return;
      }
      g_viewerSettings.highlightHitbox = 1;
    }
  }
  CBoneControlWindow::RefreshHitbox(this);
}

//------------------------------------------------------------------------------
// Address: 0x004080F0
// Name: private: void CBoneControlWindow::OnHitboxChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnHitboxChanged(CBoneControlWindow *this)
{
  int m_nHitboxSet; // eax
  const char *Label; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  mstudiobbox_t *p_m_BBox; // edi
  const char *v10; // eax
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *v11; // edi
  const char *v12; // eax
  float origin; // [esp+4h] [ebp-18h]
  float origin_4; // [esp+8h] [ebp-14h]
  float origin_8; // [esp+Ch] [ebp-10h]
  float size; // [esp+10h] [ebp-Ch]
  float size_4; // [esp+14h] [ebp-8h]
  float size_8; // [esp+18h] [ebp-4h]

  m_nHitboxSet = this->m_nHitboxSet;
  if ( m_nHitboxSet < 0 || m_nHitboxSet >= g_pStudioModel->m_HitboxSets.m_Size )
    this->m_nHitboxSet = 0;
  if ( this->m_Hitbox >= 0 && g_pStudioModel->m_HitboxSets.m_Size > 0 )
  {
    Label = mxWidget::getLabel(this: this->m_eOriginX);
    if ( Label != nullptr )
    {
      origin = atof(nptr: Label);
      v4 = mxWidget::getLabel(this: this->m_eOriginY);
      if ( v4 != nullptr )
      {
        origin_4 = atof(nptr: v4);
        v5 = mxWidget::getLabel(this: this->m_eOriginZ);
        if ( v5 != nullptr )
        {
          origin_8 = atof(nptr: v5);
          v6 = mxWidget::getLabel(this: this->m_eSizeX);
          if ( v6 != nullptr )
          {
            size = atof(nptr: v6);
            v7 = mxWidget::getLabel(this: this->m_eSizeY);
            if ( v7 != nullptr )
            {
              size_4 = atof(nptr: v7);
              v8 = mxWidget::getLabel(this: this->m_eSizeZ);
              if ( v8 != nullptr )
              {
                size_8 = atof(nptr: v8);
                p_m_BBox = &g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory[this->m_nHitboxSet].m_Hitboxes.m_Memory.m_pMemory[LOWORD(this->m_Hitbox)].m_Element.m_BBox;
                p_m_BBox->bbmin.x = origin - (float)(size * 0.5);
                p_m_BBox->bbmin.y = origin_4 - (float)(size_4 * 0.5);
                p_m_BBox->bbmin.z = origin_8 - (float)(size_8 * 0.5);
                p_m_BBox->bbmax.x = (float)(size * 0.5) + origin;
                p_m_BBox->bbmax.y = (float)(size_4 * 0.5) + origin_4;
                p_m_BBox->bbmax.z = (float)(size_8 * 0.5) + origin_8;
                v10 = mxWidget::getLabel(this: this->m_eHitboxGroup);
                if ( v10 != nullptr )
                  p_m_BBox->group = atol(nptr: v10);
                v11 = &g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory[this->m_nHitboxSet].m_Hitboxes.m_Memory.m_pMemory[LOWORD(this->m_Hitbox)];
                v12 = mxWidget::getLabel(this: this->m_eHitboxName);
                CUtlString::operator=(this: &v11->m_Element.m_Name, src: v12);
              }
            }
          }
        }
      }
    }
  }
  CBoneControlWindow::RefreshHitbox(this);
}

//------------------------------------------------------------------------------
// Address: 0x004082D0
// Name: private: void CBoneControlWindow::OnSurfaceProp(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnSurfaceProp(CBoneControlWindow *this, int propIndex)
{
  const char *v3; // eax

  if ( g_pStudioModel->m_MDLHandle != 0xFFFF )
  {
    v3 = physprop->GetPropName(this: physprop, a2: propIndex);
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&propIndex, pStr: v3);
    g_pStudioModel->m_SurfaceProps.m_Memory.m_pMemory[this->m_Bone].m_Id = propIndex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408330
// Name: private: void CBoneControlWindow::OnSurfacePropApplyToChildren_R(int,class CUtlSymbol)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnSurfacePropApplyToChildren_R(CBoneControlWindow *this, int bone, CUtlSymbol prop)
{
  CStudioHdr *m_pStudioHdr; // esi
  CStudioHdr **p_m_pStudioHdr; // edi
  const studiohdr_t *v5; // eax
  const studiohdr_t *v6; // eax
  int v7; // edi
  int v8; // ebx

  g_pStudioModel->m_SurfaceProps.m_Memory.m_pMemory[bone] = prop;
  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
    CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    m_pStudioHdr = (*p_m_pStudioHdr)->m_pStudioHdr != nullptr ? *p_m_pStudioHdr : nullptr;
  }
  v6 = m_pStudioHdr->m_pStudioHdr;
  v7 = 0;
  if ( m_pStudioHdr->m_pStudioHdr->numbones > 0 )
  {
    v8 = 0;
    do
    {
      if ( *(int *)((char *)&v6->version + v8 + v6->boneindex) == bone )
        CBoneControlWindow::OnSurfacePropApplyToChildren_R(this, bone: v7, prop);
      v6 = m_pStudioHdr->m_pStudioHdr;
      ++v7;
      v8 += 216;
    }
    while ( v7 < m_pStudioHdr->m_pStudioHdr->numbones );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004083E0
// Name: private: void CBoneControlWindow::OnSurfacePropApplyToChildren(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnSurfacePropApplyToChildren(CBoneControlWindow *this)
{
  if ( g_pStudioModel != nullptr )
    CBoneControlWindow::OnSurfacePropApplyToChildren_R(
      this,
      bone: this->m_Bone,
      prop: g_pStudioModel->m_SurfaceProps.m_Memory.m_pMemory[this->m_Bone]);
}

//------------------------------------------------------------------------------
// Address: 0x00408410
// Name: public: void ControlPanel::resetControlPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::resetControlPanel(ControlPanel *this)
{
  int Sequence; // eax
  int v3; // eax
  int OverlaySequence; // edi
  int v5; // edi
  int v6; // edi
  int v7; // edi
  mxSlider *slSpeedScale; // ecx
  double FPS; // st7
  int SolveHeadTurn; // eax
  char string[32]; // [esp+18h] [ebp-24h] BYREF
  float value; // [esp+38h] [ebp-4h]

  Sequence = StudioModel::GetSequence(this: g_pStudioModel);
  ControlPanel::setSequence(this, index: Sequence);
  v3 = StudioModel::GetSequence(this: g_pStudioModel);
  ControlPanel::showActivityModifiers(this, sequence: v3);
  value = StudioModel::GetOverlaySequenceWeight(this: g_pStudioModel, iLayer: 0);
  OverlaySequence = StudioModel::GetOverlaySequence(this: g_pStudioModel, iLayer: 0);
  mxChoice::select(this: this->cSequence[1], index: this->iSequenceToSelection[0][OverlaySequence]);
  StudioModel::SetOverlaySequence(this: g_pStudioModel, iLayer: 0, iSequence: OverlaySequence, flWeight: value);
  mxSlider::setValue(this: this->slSequence[1], value);
  ControlPanel::updateFrameSelection(this);
  value = StudioModel::GetOverlaySequenceWeight(this: g_pStudioModel, iLayer: 1);
  v5 = StudioModel::GetOverlaySequence(this: g_pStudioModel, iLayer: 1);
  mxChoice::select(this: this->cSequence[2], index: this->iSequenceToSelection[0][v5]);
  StudioModel::SetOverlaySequence(this: g_pStudioModel, iLayer: 1, iSequence: v5, flWeight: value);
  mxSlider::setValue(this: this->slSequence[2], value);
  ControlPanel::updateFrameSelection(this);
  value = StudioModel::GetOverlaySequenceWeight(this: g_pStudioModel, iLayer: 2);
  v6 = StudioModel::GetOverlaySequence(this: g_pStudioModel, iLayer: 2);
  mxChoice::select(this: this->cSequence[3], index: this->iSequenceToSelection[0][v6]);
  StudioModel::SetOverlaySequence(this: g_pStudioModel, iLayer: 2, iSequence: v6, flWeight: value);
  mxSlider::setValue(this: this->slSequence[3], value);
  ControlPanel::updateFrameSelection(this);
  value = StudioModel::GetOverlaySequenceWeight(this: g_pStudioModel, iLayer: 3);
  v7 = StudioModel::GetOverlaySequence(this: g_pStudioModel, iLayer: 3);
  mxChoice::select(this: this->cSequence[4], index: this->iSequenceToSelection[0][v7]);
  StudioModel::SetOverlaySequence(this: g_pStudioModel, iLayer: 3, iSequence: v7, flWeight: value);
  mxSlider::setValue(this: this->slSequence[4], value);
  ControlPanel::updateFrameSelection(this);
  slSpeedScale = this->slSpeedScale;
  value = g_viewerSettings.speedScale;
  mxSlider::setValue(this: slSpeedScale, value: g_viewerSettings.speedScale);
  g_viewerSettings.speedScale = value;
  FPS = StudioModel::GetFPS(this: g_pStudioModel);
  sprintf(string, format: "x %.2f = %.1f fps", g_viewerSettings.speedScale, FPS * g_viewerSettings.speedScale);
  mxWidget::setLabel(this: this->laFPS, format: string);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbGround, b: g_viewerSettings.showGround);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbMovement, b: g_viewerSettings.showMovement);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbShadow, b: g_viewerSettings.showShadow);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbNormalMap, b: g_viewerSettings.enableNormalMapping);
  mxRadioButton::setChecked(
    this: (mxRadioButton *)this->cbDisplacementMap,
    b: g_viewerSettings.enableDisplacementMapping);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbIllumPosition, b: g_viewerSettings.showIllumPosition);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbHitBoxes, b: g_viewerSettings.showHitBoxes);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbBones, b: g_viewerSettings.showBones);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbPlaySounds, b: g_viewerSettings.playSounds);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbShowOriginAxis, b: g_viewerSettings.showOriginAxis);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbSequenceBoxes, b: g_viewerSettings.showSequenceBoxes);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbRunIK, b: g_viewerSettings.enableIK);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbBackground, b: g_viewerSettings.showBackground);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbSoftwareSkin, b: g_viewerSettings.softwareSkin);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbOverbright2, b: g_viewerSettings.overbright);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbAttachments, b: g_viewerSettings.showAttachments);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbNormals, b: g_viewerSettings.showNormals);
  SolveHeadTurn = StudioModel::GetSolveHeadTurn(this: g_pStudioModel);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbEnableHead, b: SolveHeadTurn != 0);
  mxRadioButton::setChecked(this: (mxRadioButton *)this->cbShowOriginAxis, b: g_viewerSettings.showOriginAxis);
  mxSlider::setValue(this: this->leOriginAxisLength, value: g_viewerSettings.originAxisLength);
}

//------------------------------------------------------------------------------
// Address: 0x004087C0
// Name: public: void ControlPanel::setLOD(int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setLOD(ControlPanel *this, int index, bool setLODchoice, bool force)
{
  double LODSwitchValue; // st7
  HWND Handle; // ebx
  char tmp[128]; // [esp+14h] [ebp-80h] BYREF

  if ( force || g_viewerSettings.lod != index )
  {
    g_viewerSettings.lod = index;
    LODSwitchValue = StudioModel::GetLODSwitchValue(this: g_pStudioModel, lod: index);
    sprintf(string: tmp, format: "%0.0f", LODSwitchValue);
    mxWidget::setLabel(this: this->leLODSwitch, format: tmp);
    Handle = (HWND)mxWidget::getHandle(this: this->leLODSwitch);
    if ( setLODchoice )
      mxChoice::select(this: this->cLODChoice, index);
    ControlPanel::setModelInfo(this);
    InvalidateRect(hWnd: Handle, lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: Handle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408860
// Name: public: void ControlPanel::initSequenceChoices(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::initSequenceChoices(ControlPanel *this, int iOnlyInitSlot)
{
  CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr **p_m_pStudioHdr; // edi
  const studiohdr_t *v5; // eax
  CStudioHdr *v6; // edi
  int v7; // ebx
  int v8; // edi
  unsigned int v9; // ebx
  int *v10; // eax
  int *v11; // eax
  int v12; // ebx
  const studiohdr_t *v13; // ecx
  int v14; // edx
  mstudioseqdesc_t *v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // ebx
  int v19; // ebx
  int v20; // eax
  double CurrentVelocity; // st7
  int v22; // ebx
  int MaxFrame; // eax
  mxChoice **cPoseParameter; // edi
  bool PoseParameterRange; // al
  mxChoice *v26; // ecx
  int k; // ebx
  const mstudioposeparamdesc_t *v28; // eax
  const mstudioposeparamdesc_t *v29; // eax
  int v30; // ebx
  int v31; // eax
  double v32; // st7
  int v33; // edi
  mxRadioButton **rbFrameSelection; // ebx
  int v35; // eax
  double v36; // st7
  unsigned int value_4; // [esp+8h] [ebp-1C8h]
  char composedName[256]; // [esp+18h] [ebp-1B8h] BYREF
  char string[100]; // [esp+118h] [ebp-B8h] BYREF
  char filter[64]; // [esp+17Ch] [ebp-54h] BYREF
  int *flMax; // [esp+1BCh] [ebp-14h] BYREF
  int nSequenceCount; // [esp+1C0h] [ebp-10h]
  int flMin; // [esp+1C4h] [ebp-Ch] BYREF
  CStudioHdr *hdr; // [esp+1C8h] [ebp-8h]
  int j; // [esp+1CCh] [ebp-4h]
  int i; // [esp+1D8h] [ebp+8h]
  int ia; // [esp+1D8h] [ebp+8h]

  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    hdr = g_pStudioModel->m_pStudioHdr;
    v6 = m_pStudioHdr;
  }
  else
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
    CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    v6 = *p_m_pStudioHdr;
    if ( v6->m_pStudioHdr == nullptr )
    {
      hdr = nullptr;
      goto LABEL_53;
    }
    hdr = v6;
  }
  if ( v6 != nullptr )
  {
    if ( v6->m_pVModel != nullptr )
      nSequenceCount = CStudioHdr::GetNumSeq_Internal(this: v6);
    else
      nSequenceCount = v6->m_pStudioHdr->numlocalseq;
    v7 = nSequenceCount;
    value_4 = 4 * nSequenceCount;
    this->m_iLastSequenceCount = nSequenceCount;
    flMax = (int *)operator new(nSize: value_4);
    ControlPanel::CreateSortedSequenceList(this, hdr: v6, pSequence: flMax);
    v8 = 0;
    while ( 1 )
    {
      if ( iOnlyInitSlot < 0 || v8 == iOnlyInitSlot )
      {
        if ( this->iSelectionToSequence[v8] != nullptr )
          free(pMem: this->iSelectionToSequence[v8]);
        v9 = 4 * v7;
        v10 = (int *)operator new(nSize: v9);
        this->iSelectionToSequence[v8] = v10;
        memset(dst: (unsigned __int8 *)v10, value: 0, count: v9);
        if ( this->iSequenceToSelection[v8] != nullptr )
          free(pMem: this->iSequenceToSelection[v8]);
        v11 = (int *)operator new(nSize: v9);
        this->iSequenceToSelection[v8] = v11;
        memset(dst: (unsigned __int8 *)v11, value: 0, count: v9);
        if ( v8 < 0 )
          filter[0] = 0;
        mxLineEdit::getText(this: this->leSequenceFilter[v8], buf: filter, bufsize: 0x40u);
        mxChoice::removeAll(this: this->cSequence[v8]);
        flMin = 0;
        *(float *)&j = 0.0;
        if ( nSequenceCount > 0 )
        {
          do
          {
            v12 = flMax[j];
            ComposeSequenceDisplayName(hdr, nSequence: v12, buffer: composedName, bufferLength: 256);
            if ( filter[0] != 0 && V_stristr(pStr: composedName, pSearch: filter) == nullptr )
              goto LABEL_33;
            if ( g_viewerSettings.showHidden )
              goto LABEL_32;
            if ( hdr->m_pVModel != nullptr )
            {
              v15 = CStudioHdr::pSeqdesc_Internal(this: hdr, i: v12);
            }
            else
            {
              v13 = hdr->m_pStudioHdr;
              v14 = v12;
              if ( v12 < 0 || v12 >= v13->numlocalseq )
                v14 = 0;
              v15 = (mstudioseqdesc_t *)((char *)v13 + 212 * v14 + v13->localseqindex);
            }
            if ( (v15->flags & 0x400) != 0 )
            {
LABEL_33:
              if ( flMin <= 0 )
                v17 = 0;
              else
                v17 = flMin - 1;
              this->iSequenceToSelection[v8][v12] = v17;
            }
            else
            {
LABEL_32:
              mxChoice::add(this: this->cSequence[v8], item: composedName);
              v16 = flMin;
              this->iSelectionToSequence[v8][flMin] = v12;
              this->iSequenceToSelection[v8][v12] = v16;
              flMin = v16 + 1;
            }
            ++j;
          }
          while ( j < nSequenceCount );
        }
        mxChoice::select(this: this->cSequence[v8], index: 0);
        if ( iOnlyInitSlot == -1 )
          mxSlider::setValue(this: this->slSequence[v8], value: 0.0);
        v18 = *this->iSelectionToSequence[v8];
        flMin = v18;
        if ( v8 != 0 )
        {
          *(float *)&j = mxSlider::getValue(this: this->slSequence[v8]);
          mxChoice::select(this: this->cSequence[v8], index: this->iSequenceToSelection[0][v18]);
          StudioModel::SetOverlaySequence(this: g_pStudioModel, iLayer: v8 - 1, iSequence: v18, flWeight: *(float *)&j);
          mxSlider::setValue(this: this->slSequence[v8], value: *(float *)&j);
          v22 = 0;
          j = (int)this->rbFrameSelection;
          while ( !mxRadioButton::isChecked(this: *(mxRadioButton **)j) )
          {
            j += 4;
            if ( ++v22 >= 5 )
            {
              v22 = 0;
              break;
            }
          }
          MaxFrame = StudioModel::GetMaxFrame(this: g_pStudioModel, iLayer: v22);
          mxSlider::setRange(this: this->slForceFrame, min: 0.0, max: (float)MaxFrame, ticks: MaxFrame);
          mxSlider::setSteps(this: this->slForceFrame, line: 1, page: 1);
        }
        else
        {
          mxChoice::select(this: this->cSequence[0], index: this->iSequenceToSelection[0][v18]);
          StudioModel::SetSequence(this: g_pStudioModel, iSequence: v18);
          v19 = 0;
          j = (int)this->rbFrameSelection;
          while ( !mxRadioButton::isChecked(this: *(mxRadioButton **)j) )
          {
            j += 4;
            if ( ++v19 >= 5 )
            {
              v19 = 0;
              break;
            }
          }
          v20 = StudioModel::GetMaxFrame(this: g_pStudioModel, iLayer: v19);
          mxSlider::setRange(this: this->slForceFrame, min: 0.0, max: (float)v20, ticks: v20);
          mxSlider::setSteps(this: this->slForceFrame, line: 1, page: 1);
          CurrentVelocity = StudioModel::GetCurrentVelocity(this: g_pStudioModel);
          sprintf(string, format: "Speed: %.2f", CurrentVelocity);
          mxWidget::setLabel(this: this->laGroundSpeed, format: string);
          ControlPanel::showActivityModifiers(this, sequence: flMin);
        }
      }
      if ( ++v8 >= 5 )
        break;
      v7 = nSequenceCount;
    }
    free(pMem: flMax);
  }
LABEL_53:
  if ( iOnlyInitSlot == -1 )
  {
    i = 0;
    cPoseParameter = this->cPoseParameter;
    do
    {
      PoseParameterRange = StudioModel::GetPoseParameterRange(
                             this: g_pStudioModel,
                             iParameter: i,
                             pflMin: (float *)&flMin,
                             pflMax: (float *)&flMax);
      v26 = *cPoseParameter;
      if ( PoseParameterRange )
      {
        mxChoice::removeAll(this: v26);
        for ( k = 0; k < CStudioHdr::GetNumPoseParameters(this: hdr); ++k )
        {
          v28 = CStudioHdr::pPoseParameter(this: hdr, i: k);
          mxChoice::add(this: *cPoseParameter, item: (const char *)v28 + v28->sznameindex);
        }
        mxChoice::select(this: *cPoseParameter, index: i);
        mxWidget::setEnabled(this: *cPoseParameter, b: true);
        mxWidget::setVisible(this: *cPoseParameter, b: true);
        mxWidget::setEnabled(this: cPoseParameter[8], b: true);
        mxSlider::setRange(
          this: (mxSlider *)cPoseParameter[8],
          min: *(float *)&flMin,
          max: *(float *)&flMax,
          ticks: 1000);
        v29 = CStudioHdr::pPoseParameter(this: hdr, i);
        mxToolTip::add(widget: cPoseParameter[8], text: (const char *)v29 + v29->sznameindex);
        mxWidget::setVisible(this: cPoseParameter[8], b: true);
        mxWidget::setVisible(this: cPoseParameter[16], b: true);
        mxWidget::setLabel(this: cPoseParameter[16], format: "%.1f", 0.0);
      }
      else
      {
        mxWidget::setEnabled(this: v26, b: false);
        mxWidget::setVisible(this: *cPoseParameter, b: false);
        mxWidget::setEnabled(this: cPoseParameter[8], b: false);
        mxWidget::setVisible(this: cPoseParameter[8], b: false);
        mxWidget::setVisible(this: cPoseParameter[16], b: false);
      }
      mxSlider::setValue(this: (mxSlider *)cPoseParameter[8], value: 0.0);
      StudioModel::SetPoseParameter(this: g_pStudioModel, iParameter: i, flValue: 0.0);
      v30 = 0;
      j = (int)this->rbFrameSelection;
      while ( !mxRadioButton::isChecked(this: *(mxRadioButton **)j) )
      {
        j += 4;
        if ( ++v30 >= 5 )
        {
          v30 = 0;
          break;
        }
      }
      v31 = StudioModel::GetMaxFrame(this: g_pStudioModel, iLayer: v30);
      mxSlider::setRange(this: this->slForceFrame, min: 0.0, max: (float)v31, ticks: v31);
      mxSlider::setSteps(this: this->slForceFrame, line: 1, page: 1);
      v32 = StudioModel::GetCurrentVelocity(this: g_pStudioModel);
      sprintf(string, format: "Speed: %.2f", v32);
      mxWidget::setLabel(this: this->laGroundSpeed, format: string);
      ++cPoseParameter;
      ++i;
    }
    while ( i < 8 );
    if ( hdr != nullptr )
    {
      for ( ia = 0; ia < CStudioHdr::GetNumPoseParameters(this: hdr); ++ia )
      {
        StudioModel::SetPoseParameter(this: g_pStudioModel, iParameter: ia, flValue: 0.0);
        v33 = 0;
        rbFrameSelection = this->rbFrameSelection;
        while ( !mxRadioButton::isChecked(this: *rbFrameSelection) )
        {
          ++v33;
          ++rbFrameSelection;
          if ( v33 >= 5 )
          {
            v33 = 0;
            break;
          }
        }
        v35 = StudioModel::GetMaxFrame(this: g_pStudioModel, iLayer: v33);
        mxSlider::setRange(this: this->slForceFrame, min: 0.0, max: (float)v35, ticks: v35);
        mxSlider::setSteps(this: this->slForceFrame, line: 1, page: 1);
        v36 = StudioModel::GetCurrentVelocity(this: g_pStudioModel);
        sprintf(string, format: "Speed: %.2f", v36);
        mxWidget::setLabel(this: this->laGroundSpeed, format: string);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408F80
// Name: public: void ControlPanel::setBodypart(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setBodypart(ControlPanel *this, int index)
{
  CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr **p_m_pStudioHdr; // esi
  const studiohdr_t *v5; // eax
  CStudioHdr *v6; // esi
  CStudioHdr *v7; // edi
  int v8; // edi
  int v9; // eax
  bool v10; // cc
  _DWORD *v11; // edi
  int v12; // esi
  char str[64]; // [esp+Ch] [ebp-40h] BYREF

  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    v7 = g_pStudioModel->m_pStudioHdr;
  }
  else
  {
    v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
    CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
    v6 = *p_m_pStudioHdr;
    if ( v6->m_pStudioHdr == nullptr )
      goto LABEL_11;
    v7 = v6;
  }
  if ( v7 != nullptr )
  {
    mxChoice::select(this: this->cBodypart, index);
    if ( index < v7->m_pStudioHdr->numbodyparts )
    {
      v8 = (int)v7->m_pStudioHdr + v7->m_pStudioHdr->bodypartindex;
      mxChoice::removeAll(this: this->cSubmodel);
      v9 = 0;
      v10 = *(_DWORD *)(v8 + 16 * index + 4) <= 0;
      v11 = (_DWORD *)(v8 + 16 * index + 4);
      if ( !v10 )
      {
        do
        {
          v12 = v9 + 1;
          sprintf(string: str, format: "Submodel %d", v9 + 1);
          mxChoice::add(this: this->cSubmodel, item: str);
          v9 = v12;
        }
        while ( v12 < *v11 );
      }
      mxChoice::select(this: this->cSubmodel, index: 0);
    }
  }
LABEL_11:
  ControlPanel::setModelInfo(this);
}

//------------------------------------------------------------------------------
// Address: 0x00409060
// Name: public: void ControlPanel::setSubmodel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setSubmodel(ControlPanel *this, int index)
{
  int SelectedIndex; // eax

  SelectedIndex = mxChoice::getSelectedIndex(this: this->cBodypart);
  StudioModel::SetBodygroup(this: g_pStudioModel, iGroup: SelectedIndex, iValue: index);
  ControlPanel::setModelInfo(this);
}

//------------------------------------------------------------------------------
// Address: 0x00409090
// Name: public: void ControlPanel::initLODs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::initLODs(ControlPanel *this)
{
  int i; // edi
  double LODSwitchValue; // st7
  HWND Handle; // edi
  char string[128]; // [esp+10h] [ebp-8Ch] BYREF
  char tmp[12]; // [esp+90h] [ebp-Ch] BYREF

  mxChoice::removeAll(this: this->cLODChoice);
  for ( i = 0; i < StudioModel::GetNumLODs(this: g_pStudioModel); ++i )
  {
    sprintf(string: tmp, format: "%d", i);
    mxChoice::add(this: this->cLODChoice, item: tmp);
  }
  g_viewerSettings.lod = 0;
  LODSwitchValue = StudioModel::GetLODSwitchValue(this: g_pStudioModel, lod: 0);
  sprintf(string, format: "%0.0f", LODSwitchValue);
  mxWidget::setLabel(this: this->leLODSwitch, format: string);
  Handle = (HWND)mxWidget::getHandle(this: this->leLODSwitch);
  mxChoice::select(this: this->cLODChoice, index: 0);
  ControlPanel::setModelInfo(this);
  InvalidateRect(hWnd: Handle, lpRect: nullptr, bErase: true);
  UpdateWindow(hWnd: Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00409170
// Name: public: void ControlPanel::setupPhysicsBone(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setupPhysicsBone(ControlPanel *this, int boneIndex)
{
  int v3; // edi
  mxRadioButton **rbConstraintAxis; // ebx
  mxSlider *slPhysicsParamMassBias; // edi
  mxLabel *lPhysicsParamMassBias; // ebx
  double Value; // st7
  mxSlider *slPhysicsParamInertia; // edi
  mxLabel *lPhysicsParamInertia; // ebx
  double v10; // st7
  mxSlider *slPhysicsParamDamping; // edi
  mxLabel *lPhysicsParamDamping; // ebx
  double v13; // st7
  mxSlider *slPhysicsParamRotDamping; // edi
  mxLabel *lPhysicsParamRotDamping; // ebx
  double v16; // st7
  CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr **p_m_pStudioHdr; // edi
  const studiohdr_t *v19; // eax
  CStudioHdr *v20; // edi
  const studiohdr_t *v21; // ecx
  int v22; // ebx
  const char *v23; // eax
  hlmvsolid_t solid; // [esp+14h] [ebp-69Ch] BYREF
  char string[80]; // [esp+65Ch] [ebp-54h] BYREF
  int v26; // [esp+6ACh] [ebp-4h]

  if ( g_pStudioModel->m_pPhysics != nullptr )
  {
    v3 = 0;
    rbConstraintAxis = this->rbConstraintAxis;
    while ( !mxRadioButton::isChecked(this: *rbConstraintAxis) )
    {
      ++v3;
      ++rbConstraintAxis;
      if ( v3 >= 3 )
      {
        v3 = 0;
        break;
      }
    }
    ControlPanel::setupPhysicsAxis(this, boneIndex, axis: v3);
    StudioModel::Physics_GetData(this: g_pStudioModel, boneIndex, psolid: &solid, pConstraint: nullptr);
    slPhysicsParamMassBias = this->slPhysicsParamMassBias;
    lPhysicsParamMassBias = this->lPhysicsParamMassBias;
    mxSlider::setValue(this: slPhysicsParamMassBias, value: solid.massBias);
    Value = mxSlider::getValue(this: slPhysicsParamMassBias);
    sprintf(string, format: "%0.2f", Value);
    mxWidget::setLabel(this: lPhysicsParamMassBias, format: string);
    slPhysicsParamInertia = this->slPhysicsParamInertia;
    lPhysicsParamInertia = this->lPhysicsParamInertia;
    mxSlider::setValue(this: slPhysicsParamInertia, value: solid.params.inertia);
    v10 = mxSlider::getValue(this: slPhysicsParamInertia);
    sprintf(string, format: "%0.2f", v10);
    mxWidget::setLabel(this: lPhysicsParamInertia, format: string);
    slPhysicsParamDamping = this->slPhysicsParamDamping;
    lPhysicsParamDamping = this->lPhysicsParamDamping;
    mxSlider::setValue(this: slPhysicsParamDamping, value: solid.params.damping);
    v13 = mxSlider::getValue(this: slPhysicsParamDamping);
    sprintf(string, format: "%0.2f", v13);
    mxWidget::setLabel(this: lPhysicsParamDamping, format: string);
    slPhysicsParamRotDamping = this->slPhysicsParamRotDamping;
    lPhysicsParamRotDamping = this->lPhysicsParamRotDamping;
    mxSlider::setValue(this: slPhysicsParamRotDamping, value: solid.params.rotdamping);
    v16 = mxSlider::getValue(this: slPhysicsParamRotDamping);
    sprintf(string, format: "%0.2f", v16);
    mxWidget::setLabel(this: lPhysicsParamRotDamping, format: string);
    m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
    p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      v20 = g_pStudioModel->m_pStudioHdr;
    }
    else
    {
      v19 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
      CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v19, mdlcache: nullptr);
      v20 = (*p_m_pStudioHdr)->m_pStudioHdr != nullptr ? *p_m_pStudioHdr : nullptr;
    }
    v21 = v20->m_pStudioHdr;
    v22 = 0;
    if ( v20->m_pStudioHdr->numbones > 0 )
    {
      v26 = 0;
      while ( _V_stricmp(
                s1: (const char *)v21 + v26 + v21->boneindex + *(int *)((char *)&v21->id + v26 + v21->boneindex),
                s2: solid.name) != 0 )
      {
        v21 = v20->m_pStudioHdr;
        v26 += 216;
        if ( ++v22 >= v21->numbones )
          goto LABEL_16;
      }
      v23 = CUtlSymbol::String(this: &g_pStudioModel->m_SurfaceProps.m_Memory.m_pMemory[v22]);
      mxWidget::setLabel(this: this->lPhysicsMaterial, format: v23);
    }
LABEL_16:
    if ( boneIndex + 1 >= 0 )
      g_viewerSettings.highlightPhysicsBone = boneIndex + 1;
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004093C0
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409650
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004096A0
// Name: public: void CUtlBuffer::PutChar(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutChar(CUtlBuffer *this, char c)
{
  int m_Put; // eax

  if ( (this->m_Flags & 1) != 0 )
  {
    m_Put = this->m_Put;
    if ( m_Put != 0 && this->m_Memory.m_pMemory[m_Put - this->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this);
  }
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409700
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
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
// Address: 0x00409730
// Name: private: void CBoneControlWindow::ComputeHitboxList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::ComputeHitboxList(CBoneControlWindow *this)
{
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *v2; // ecx
  int m_Bone; // eax
  int m_Size; // ebx
  int i; // edi
  char buf[32]; // [esp+Ch] [ebp-20h] BYREF

  mxChoice::removeAll(this: this->m_cHitbox);
  if ( this->m_SetBoneHitBoxes.m_Size <= 0
    || (v2 = &this->m_SetBoneHitBoxes.m_Memory.m_pMemory[this->m_nHitboxSet], m_Bone = this->m_Bone,
                                                                              v2->m_Size <= m_Bone)
    || (m_Size = v2->m_Memory.m_pMemory[m_Bone].m_Size) <= 0 )
  {
    mxChoice::add(this: this->m_cHitbox, item: "None");
    CBoneControlWindow::OnHitboxSelected(this, hitbox: 0);
  }
  else
  {
    for ( i = 0; i < m_Size; ++i )
    {
      sprintf(
        string: buf,
        format: "%d",
        this->m_SetBoneHitBoxes.m_Memory.m_pMemory[this->m_nHitboxSet].m_Memory.m_pMemory[this->m_Bone].m_Memory.m_pMemory[i]);
      mxChoice::add(this: this->m_cHitbox, item: buf);
    }
    CBoneControlWindow::OnHitboxSelected(this, hitbox: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004097F0
// Name: private: void CBoneControlWindow::OnBoneSelected(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnBoneSelected(CBoneControlWindow *this, int boneIndex)
{
  const char *v3; // eax
  int SurfaceProp; // eax
  mxCheckBox *m_cBoneHighlight; // ecx

  if ( g_pStudioModel != nullptr )
  {
    if ( physprop != nullptr && g_pStudioModel->m_SurfaceProps.m_Size != 0 )
    {
      v3 = CUtlSymbol::String(this: &g_pStudioModel->m_SurfaceProps.m_Memory.m_pMemory[boneIndex]);
      SurfaceProp = FindSurfaceProp(pSurfaceProp: v3);
      if ( SurfaceProp < 0 )
      {
        SurfaceProp = FindSurfaceProp(pSurfaceProp: "default");
        if ( SurfaceProp < 0 )
          SurfaceProp = 0;
      }
      mxChoice::select(this: this->m_cSurfaceProp, index: SurfaceProp);
    }
    else
    {
      mxChoice::select(this: this->m_cSurfaceProp, index: 0);
    }
    m_cBoneHighlight = this->m_cBoneHighlight;
    this->m_Bone = boneIndex;
    if ( mxRadioButton::isChecked(this: (mxRadioButton *)m_cBoneHighlight) )
      g_viewerSettings.highlightBone = this->m_Bone;
    CBoneControlWindow::ComputeHitboxList(this);
    this->m_pControlPanel->redraw(this: this->m_pControlPanel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409890
// Name: private: void CBoneControlWindow::OnHitboxGroupChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnHitboxGroupChanged(CBoneControlWindow *this)
{
  const char *Label; // eax
  int m_nHitboxSet; // ecx
  const char *v4; // ebx
  HitboxSet_t *m_pMemory; // eax
  CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *p_m_Hitboxes; // edi
  int m_Hitbox_low; // esi
  int p_m_BBox; // esi

  if ( this->m_Hitbox >= 0 && g_pStudioModel->m_HitboxSets.m_Size > 0 )
  {
    Label = mxWidget::getLabel(this: this->m_eHitboxGroup);
    m_nHitboxSet = this->m_nHitboxSet;
    v4 = Label;
    m_pMemory = g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory;
    p_m_Hitboxes = &m_pMemory[m_nHitboxSet].m_Hitboxes;
    if ( v4 != nullptr )
    {
      m_Hitbox_low = LOWORD(this->m_Hitbox);
      if ( CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::IsInList(
             this: &m_pMemory[m_nHitboxSet].m_Hitboxes,
             i: m_Hitbox_low) )
      {
        p_m_BBox = (int)&p_m_Hitboxes->m_Memory.m_pMemory[m_Hitbox_low].m_Element.m_BBox;
        *(_DWORD *)(p_m_BBox + 4) = atol(nptr: v4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409900
// Name: private: bool CBoneControlWindow::SerializeQC(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBoneControlWindow::SerializeQC(CBoneControlWindow *this, CUtlBuffer *buf)
{
  CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr **p_m_pStudioHdr; // esi
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  CUtlBuffer *v7; // ebx
  const char *v8; // eax
  StudioModel *v9; // edx
  int v10; // edi
  int v11; // esi
  int v12; // ecx
  _DWORD *v13; // esi
  CUtlSymbol *m_pMemory; // eax
  const char *v15; // eax
  CUtlSymbol *v16; // ecx
  const char *v17; // edi
  const char *v18; // eax
  StudioModel *v19; // ecx
  int v20; // esi
  HitboxSet_t *v21; // edx
  unsigned __int16 v22; // ax
  _DWORD *v23; // edi
  int v24; // esi
  int v25; // eax
  int v26; // ecx
  const char *v27; // [esp+2Ch] [ebp-24h]
  CUtlSymbol *v29; // [esp+40h] [ebp-10h]
  int v30; // [esp+44h] [ebp-Ch]
  int v31; // [esp+44h] [ebp-Ch]
  CStudioHdr *hdr; // [esp+48h] [ebp-8h]
  int i; // [esp+4Ch] [ebp-4h]
  int ia; // [esp+4Ch] [ebp-4h]

  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    hdr = g_pStudioModel->m_pStudioHdr;
  }
  else
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
    CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    v5 = *p_m_pStudioHdr;
    if ( v5->m_pStudioHdr == nullptr )
      return 0;
    hdr = v5;
  }
  if ( hdr == nullptr )
    return 0;
  v7 = buf;
  CUtlBuffer::Printf(this: buf, pFmt: "// .qc block generated by HLMV begins.\n\n");
  v8 = CUtlSymbol::String(this: g_pStudioModel->m_SurfaceProps.m_Memory.m_pMemory);
  CUtlBuffer::Printf(this: buf, pFmt: "$surfaceprop \"%s\"\n", v8);
  v9 = g_pStudioModel;
  v10 = 1;
  i = 1;
  if ( g_pStudioModel->m_SurfaceProps.m_Size > 1 )
  {
    v30 = 216;
    while ( 1 )
    {
      v11 = v30 + hdr->m_pStudioHdr->boneindex;
      v12 = *(int *)((char *)&hdr->m_pStudioHdr->version + v11);
      v13 = (int *)((char *)&hdr->m_pStudioHdr->id + v11);
      if ( v12 < 0 )
        goto LABEL_13;
      m_pMemory = v9->m_SurfaceProps.m_Memory.m_pMemory;
      v29 = &m_pMemory[v10];
      v27 = CUtlSymbol::String(this: &m_pMemory[v12]);
      v15 = CUtlSymbol::String(this: v29);
      if ( _V_stricmp(s1: v15, s2: v27) != 0 )
        break;
LABEL_14:
      v9 = g_pStudioModel;
      v30 += 216;
      i = ++v10;
      if ( v10 >= g_pStudioModel->m_SurfaceProps.m_Size )
        goto LABEL_15;
    }
    v9 = g_pStudioModel;
LABEL_13:
    v16 = &v9->m_SurfaceProps.m_Memory.m_pMemory[v10];
    v17 = (char *)v13 + *v13;
    v18 = CUtlSymbol::String(this: v16);
    CUtlBuffer::Printf(this: buf, pFmt: "$jointsurfaceprop \"%s\"\t \"%s\"\n", v17, v18);
    v10 = i;
    goto LABEL_14;
  }
LABEL_15:
  if ( !mxRadioButton::isChecked(this: (mxRadioButton *)this->m_cAutoHitbox) )
  {
    CUtlBuffer::Printf(this: buf, pFmt: "\n");
    v19 = g_pStudioModel;
    v20 = 0;
    ia = 0;
    if ( g_pStudioModel->m_HitboxSets.m_Size > 0 )
    {
      v31 = 0;
      do
      {
        CUtlBuffer::Printf(
          this: v7,
          pFmt: "\n$hboxset \"%s\"\n\n",
          *(const char **)((char *)&v19->m_HitboxSets.m_Memory.m_pMemory->m_Name.m_Storage.m_Memory.m_pMemory + v20));
        v19 = g_pStudioModel;
        v21 = g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory;
        v22 = *(unsigned __int16 *)((char *)&v21->m_Hitboxes.m_Head + v20);
        v23 = (UtlLinkedListElem_t<HitboxInfo_t,unsigned short> **)((char *)&v21->m_Hitboxes.m_Memory.m_pMemory + v20);
        if ( v22 != 0xFFFF )
        {
          do
          {
            v24 = 88 * v22;
            v25 = *v23 + v24 + 16;
            v26 = 216 * *(_DWORD *)v25 + hdr->m_pStudioHdr->boneindex;
            v7 = buf;
            CUtlBuffer::Printf(
              this: buf,
              pFmt: "$hbox %d \"%s\"\t  %7.2f %7.2f %7.2f  %7.2f %7.2f %7.2f",
              *(_DWORD *)(v25 + 4),
              (const char *)hdr->m_pStudioHdr + v26 + *(int *)((char *)&hdr->m_pStudioHdr->id + v26),
              *(float *)(v25 + 8),
              *(float *)(v25 + 12),
              *(float *)(v25 + 16),
              *(float *)(v25 + 20),
              *(float *)(v25 + 24),
              *(float *)(*v23 + v24 + 44));
            if ( CUtlString::Length(this: (CUtlString *)(v24 + *v23)) != 0 )
              CUtlBuffer::Printf(this: buf, pFmt: " \"%s\"", *(const char **)(*v23 + v24));
            CUtlBuffer::Printf(this: buf, pFmt: "\n");
            v22 = *(_WORD *)(*v23 + v24 + 86);
          }
          while ( v22 != 0xFFFF );
          v19 = g_pStudioModel;
          v20 = v31;
        }
        v20 += 44;
        ++ia;
        v31 = v20;
      }
      while ( ia < v19->m_HitboxSets.m_Size );
    }
  }
  CUtlBuffer::Printf(this: v7, pFmt: "\n// .qc block generated by HLMV ends.\n\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409C00
// Name: private: void CBoneControlWindow::OnGenerateQC(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnGenerateQC(CBoneControlWindow *this)
{
  CUtlBuffer outbuf; // [esp+4h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &outbuf, growSize: 0, initSize: 0, nFlags: 1);
  CBoneControlWindow::SerializeQC(this, buf: &outbuf);
  if ( outbuf.m_Put != 0 )
  {
    if ( (outbuf.m_Flags & 1) != 0 && outbuf.m_Memory.m_pMemory[outbuf.m_Put - outbuf.m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: &outbuf);
    if ( CUtlBuffer::CheckPut(this: &outbuf, nSize: 1) )
    {
      outbuf.m_Memory.m_pMemory[outbuf.m_Put++ - outbuf.m_nOffset] = 0;
      CUtlBuffer::AddNullTermination(this: &outbuf, nPut: outbuf.m_Put);
    }
    Sys_CopyStringToClipboard(pOut: (const char *)outbuf.m_Memory.m_pMemory);
  }
  if ( outbuf.m_Memory.m_nGrowSize >= 0 && outbuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outbuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00409CB0
// Name: GenerateHitboxFileElements
// Source: json
//------------------------------------------------------------------------------
CDmElement *__cdecl GenerateHitboxFileElements()
{
  CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr **p_m_pStudioHdr; // esi
  int v2; // ebx
  const studiohdr_t *v3; // eax
  CStudioHdr *v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // esi
  char v8; // al
  int m_Size; // eax
  const char *v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // esi
  CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *v14; // ecx
  unsigned __int16 m_Next; // ax
  int v16; // ebx
  int v17; // esi
  const char *v18; // eax
  _DWORD *v19; // edi
  int v20; // eax
  CDmElement *v21; // eax
  CDmElement *v22; // edi
  const char *v23; // eax
  bool v24; // zf
  CUtlSymbolLarge v26; // [esp+Ch] [ebp-2Ch] BYREF
  CUtlSymbolLarge value; // [esp+10h] [ebp-28h] BYREF
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *v28; // [esp+14h] [ebp-24h]
  int v29; // [esp+18h] [ebp-20h]
  int v30; // [esp+1Ch] [ebp-1Ch]
  CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *list; // [esp+20h] [ebp-18h]
  DmElementHandle_t Handle; // [esp+24h] [ebp-14h] BYREF
  DmElementHandle_t src; // [esp+28h] [ebp-10h] BYREF
  int v34; // [esp+2Ch] [ebp-Ch]
  CStudioHdr *pHdr; // [esp+30h] [ebp-8h]
  CDmElement *v36; // [esp+34h] [ebp-4h]

  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  v2 = 0;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    pHdr = g_pStudioModel->m_pStudioHdr;
    v4 = m_pStudioHdr;
  }
  else
  {
    v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
    CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
    v4 = (*p_m_pStudioHdr)->m_pStudioHdr != nullptr ? *p_m_pStudioHdr : nullptr;
    pHdr = v4;
  }
  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeHitboxSetList::m_classType.u,
         a3: "hitboxSetList",
         a4: -1,
         a5: 0);
  v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v5);
  v7 = v6;
  if ( v6 == 0
    || (v8 = (*(int (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
               a1: v6,
               a2: CDmeHitboxSetList::m_classType.u),
        v34 = v7,
        v8 == 0) )
  {
    v34 = 0;
  }
  m_Size = g_pStudioModel->m_HitboxSets.m_Size;
  if ( m_Size > 0 )
  {
    v30 = 0;
    v29 = m_Size;
    do
    {
      v10 = CUtlString::operator char const *(this: (CUtlString *)((char *)&g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory->m_Name
                                                                 + v2));
      v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
              a1: g_pDataModel.u,
              a2: CDmeHitboxSet::m_classType.u,
              a3: v10,
              a4: -1,
              a5: 0);
      v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
              a1: g_pDataModel.u,
              a2: v11);
      v13 = v12;
      if ( v12 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v12 + 16))(
             a1: v12,
             a2: CDmeHitboxSet::m_classType.u) != 0 )
      {
        src = CDmElement::GetHandle(this: (CDmElement *)v13);
      }
      else
      {
        v13 = 0;
        src = DMELEMENT_HANDLE_INVALID;
      }
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)(v34 + 68),
        &src);
      v14 = (CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *)((char *)&g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory->m_Hitboxes + v2);
      m_Next = *(unsigned __int16 *)((char *)&g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory->m_Hitboxes.m_Head + v2);
      list = v14;
      if ( m_Next != 0xFFFF )
      {
        v28 = (CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)(v13 + 68);
        while ( 1 )
        {
          v16 = m_Next;
          v17 = (int)&v14->m_Memory.m_pMemory[v16];
          v18 = CUtlString::operator char const *(this: (CUtlString *)v17);
          v19 = (int *)((char *)&v4->m_pStudioHdr->id + 216 * *(_DWORD *)(v17 + 16) + v4->m_pStudioHdr->boneindex);
          v20 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
                  a1: g_pDataModel.u,
                  a2: CDmeHitbox::m_classType.u,
                  a3: v18,
                  a4: -1,
                  a5: 0);
          v21 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
                                a1: g_pDataModel.u,
                                a2: v20);
          v36 = v21;
          if ( v21 != nullptr && v21->IsA(this: v21, a2: CDmeHitbox::m_classType) )
          {
            Handle = CDmElement::GetHandle(this: v36);
          }
          else
          {
            v36 = nullptr;
            Handle = DMELEMENT_HANDLE_INVALID;
          }
          CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
            this: v28,
            src: &Handle);
          CDmAttribute::SetValue<Vector>(
            this: (CDmAttribute *)v36[1].m_Name.m_Storage.u.m_Id,
            value: (const Vector *)(v17 + 24));
          CDmAttribute::SetValue<Vector>(this: *((CDmAttribute **)&v36[1].m_ref + 2), value: (const Vector *)(v17 + 36));
          (*(void (__stdcall **)(CUtlSymbolLarge *, int))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
            a1: &value,
            a2: (int)v19 + *v19);
          v22 = v36;
          CDmAttribute::SetValue<CUtlSymbolLarge>(this: *((CDmAttribute **)&v36[1] + 15), &value);
          CDmAttribute::SetValue<int>(this: (CDmAttribute *)v22[1].m_Type.u.m_Id, value: (const int *)(v17 + 20));
          v23 = CUtlSymbol::String(this: &g_pStudioModel->m_SurfaceProps.m_Memory.m_pMemory[*(_DWORD *)(v17 + 16)]);
          (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
            a1: g_pDataModel.u,
            a2: &v26,
            a3: v23);
          CDmAttribute::SetValue<CUtlSymbolLarge>(this: (CDmAttribute *)v22[1].m_ref.m_attributes.m_pNext, value: &v26);
          m_Next = list->m_Memory.m_pMemory[v16].m_Next;
          v4 = pHdr;
          if ( m_Next == 0xFFFF )
            break;
          v14 = list;
        }
        v2 = v30;
      }
      v2 += 44;
      v24 = v29-- == 1;
      v30 = v2;
    }
    while ( !v24 );
  }
  return (CDmElement *)v34;
}

//------------------------------------------------------------------------------
// Address: 0x00409F90
// Name: private: void CBoneControlWindow::OnSaveHitboxes(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBoneControlWindow::OnSaveHitboxes(CBoneControlWindow *this@<ecx>, int a2@<edi>)
{
  const char *SaveFileName; // eax
  CP4File *v3; // esi
  CDmElement *HitboxFileElements; // edi
  char v5; // bl
  char pActualFileName[260]; // [esp+0h] [ebp-104h] BYREF

  SaveFileName = mxGetSaveFileName(parent: this, path: nullptr, filter: "*.hbx");
  if ( SaveFileName != nullptr )
  {
    V_strncpy(pDest: pActualFileName, pSrc: SaveFileName, maxLen: 260);
    V_DefaultExtension(path: pActualFileName, extension: ".hbx", pathStringLength: 260);
    v3 = CP4Factory::AccessFile(this: g_p4factory, szFilename: pActualFileName);
    ((void (__thiscall *)(CP4File *, int))v3->Edit)(a1: v3, a2);
    HitboxFileElements = GenerateHitboxFileElements();
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char *, _DWORD, _DWORD, const char *, CDmElement *))(*(_DWORD *)g_pDataModel.u.m_Id + 184))(
           a1: g_pDataModel.u,
           a2: pActualFileName,
           a3: 0,
           a4: 0,
           a5: "hitbox",
           a6: HitboxFileElements);
    DestroyElement(pElement: HitboxFileElements, depth: TD_ALL);
    if ( v5 == 0 )
      _Warning(a1: "Error serializing hitbox file \"%s\"!\n", pActualFileName);
    v3->Add(this: v3);
    ((void (__thiscall *)(CP4File *, int))v3->dtr_CP4File)(a1: v3, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A070
// Name: public: void ControlPanel::centerView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::centerView(ControlPanel *this)
{
  ControlPanel *v1; // esi
  HitboxSet_t *m_pMemory; // ebx
  unsigned __int16 m_Head; // ax
  int v4; // esi
  int p_m_BBox; // edi
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  matrix3x4_t rootxform; // [esp+10h] [ebp-A4h] BYREF
  char string[16]; // [esp+40h] [ebp-74h] BYREF
  matrix3x4_t bonesetup; // [esp+50h] [ebp-64h] BYREF
  Vector tmpmax; // [esp+80h] [ebp-34h] BYREF
  Vector tmpmin; // [esp+8Ch] [ebp-28h] BYREF
  ControlPanel *v17; // [esp+98h] [ebp-1Ch]
  Vector min; // [esp+9Ch] [ebp-18h] BYREF
  Vector max; // [esp+A8h] [ebp-Ch] BYREF

  v1 = this;
  min.x = 999999.0;
  min.y = 999999.0;
  min.z = 999999.0;
  v17 = this;
  max.x = -999999.0;
  max.y = -999999.0;
  max.z = -999999.0;
  MatrixInvert(in: &g_viewtransform, out: &rootxform);
  m_pMemory = g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory;
  m_Head = m_pMemory->m_Hitboxes.m_Head;
  if ( m_Head == 0xFFFF )
  {
    z = max.z;
    y = max.y;
    x = max.x;
  }
  else
  {
    do
    {
      v4 = m_Head;
      p_m_BBox = (int)&m_pMemory->m_Hitboxes.m_Memory.m_pMemory[v4].m_Element.m_BBox;
      ConcatTransforms(in1: &rootxform, in2: &g_pStudioModel->m_pBoneToWorld[*(_DWORD *)p_m_BBox], out: &bonesetup);
      TransformAABB(
        transform: &bonesetup,
        vecMinsIn: (const Vector *)(p_m_BBox + 8),
        vecMaxsIn: (const Vector *)(p_m_BBox + 20),
        vecMinsOut: &tmpmin,
        vecMaxsOut: &tmpmax);
      if ( min.x > tmpmin.x )
        min.x = tmpmin.x;
      if ( min.y > tmpmin.y )
        min.y = tmpmin.y;
      if ( min.z > tmpmin.z )
        min.z = tmpmin.z;
      x = max.x;
      if ( tmpmax.x > max.x )
      {
        x = tmpmax.x;
        max.x = tmpmax.x;
      }
      y = max.y;
      if ( tmpmax.y > max.y )
      {
        y = tmpmax.y;
        max.y = tmpmax.y;
      }
      z = max.z;
      if ( tmpmax.z > max.z )
      {
        z = tmpmax.z;
        max.z = tmpmax.z;
      }
      m_Head = m_pMemory->m_Hitboxes.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != 0xFFFF );
    v1 = v17;
  }
  if ( min.x > x )
  {
    StudioModel::ExtractBbox(this: g_pStudioModel, mins: &min, maxs: &max);
    z = max.z;
    y = max.y;
    x = max.x;
  }
  v9 = y - min.y;
  v10 = x - min.x;
  v11 = z - min.z;
  if ( v9 > v10 )
    v10 = v9;
  if ( v11 > v10 )
    v10 = v11;
  g_pStudioModel->m_origin.x = v10 * 1.34;
  g_pStudioModel->m_origin.y = 0.0;
  g_pStudioModel->m_origin.z = (float)(v11 * 0.5) + min.z;
  g_pStudioModel->m_angles.x = 0.0;
  g_pStudioModel->m_angles.y = 0.0;
  g_pStudioModel->m_angles.z = 0.0;
  g_viewerSettings.lightrot.y = 180.0;
  g_viewerSettings.fov = 65.0;
  g_viewerSettings.lightrot.x = 0.0;
  g_viewerSettings.lightrot.z = 0.0;
  sprintf(string, format: "%.0f", 65.0);
  mxWidget::setLabel(this: v1->leFOV, format: string);
  v1->d_MatSysWindow->redraw(this: v1->d_MatSysWindow);
}

//------------------------------------------------------------------------------
// Address: 0x0040A300
// Name: public: int ControlPanel::handlePhysicsEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ControlPanel::handlePhysicsEvent(ControlPanel *this, mxEvent *event)
{
  int action; // eax
  int SelectedIndex; // eax
  int v6; // eax
  int v7; // eax
  const char *v8; // eax
  char *v9; // esi
  int PhysicsAxis; // [esp-4h] [ebp-Ch]
  int t; // [esp+0h] [ebp-8h]
  float ta; // [esp+0h] [ebp-8h]

  action = event->action;
  switch ( action )
  {
    case 7501:
      SelectedIndex = mxChoice::getSelectedIndex(this: this->cPhysicsBone);
      ControlPanel::setupPhysicsBone(this, boneIndex: SelectedIndex);
      ControlPanel::writePhysicsData(this);
      return 1;
    case 7504:
    case 7505:
    case 7508:
      ControlPanel::UpdateConstraintSliders(this, clamp: event->action);
      ControlPanel::writePhysicsData(this);
      return 1;
    case 7506:
      ta = mxSlider::getValue(this: this->slPhysicsConTest);
      PhysicsAxis = ControlPanel::getPhysicsAxis(this);
      v7 = mxChoice::getSelectedIndex(this: this->cPhysicsBone);
      StudioModel::Physics_SetPreview(this: g_pStudioModel, previewBone: v7, axis: PhysicsAxis, t: ta);
      ControlPanel::writePhysicsData(this);
      return 1;
    case 7507:
      UpdateSliderLabel(label: this->lPhysicsParamMassBias);
      goto LABEL_7;
    case 7510:
      UpdateSliderLabel(label: this->lPhysicsParamInertia);
      goto LABEL_7;
    case 7511:
      UpdateSliderLabel(label: this->lPhysicsParamDamping);
      goto LABEL_7;
    case 7512:
      UpdateSliderLabel(label: this->lPhysicsParamRotDamping);
      goto LABEL_7;
    case 7514:
      ControlPanel::writePhysicsData(this);
      v8 = StudioModel::Physics_DumpQC(this: g_pStudioModel);
      v9 = (char *)v8;
      if ( v8 != nullptr )
        Sys_CopyStringToClipboard(pOut: v8);
      free(pMem: v9);
      return 1;
    case 7515:
    case 7516:
    case 7517:
      t = action - 7515;
      v6 = mxChoice::getSelectedIndex(this: this->cPhysicsBone);
      ControlPanel::setupPhysicsAxis(this, boneIndex: v6, axis: t);
      ControlPanel::writePhysicsData(this);
      return 1;
    default:
LABEL_7:
      ControlPanel::writePhysicsData(this);
      return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A4A0
// Name: public: void ControlPanel::handlePhysicsKey(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::handlePhysicsKey(ControlPanel *this, mxEvent *event)
{
  int key; // eax
  int SelectedIndex; // edi
  int ItemCount; // eax
  int v6; // esi
  mxRadioButton **rbConstraintAxis; // ebx
  int v8; // ebx
  int v9; // edx
  mxRadioButton **v10; // edi
  int i; // esi
  mxRadioButton **v13; // [esp+8h] [ebp-Ch]
  int boneCount; // [esp+Ch] [ebp-8h]
  int boneIndex; // [esp+10h] [ebp-4h]

  key = event->key;
  if ( key == 91 || key == 93 )
  {
    SelectedIndex = mxChoice::getSelectedIndex(this: this->cPhysicsBone);
    boneIndex = SelectedIndex;
    ItemCount = mxChoice::getItemCount(this: this->cPhysicsBone);
    v6 = 0;
    rbConstraintAxis = this->rbConstraintAxis;
    boneCount = ItemCount;
    v13 = rbConstraintAxis;
    while ( !mxRadioButton::isChecked(this: *rbConstraintAxis) )
    {
      ++v6;
      ++rbConstraintAxis;
      if ( v6 >= 3 )
      {
        v6 = 0;
        break;
      }
    }
    if ( event->key == 91 )
    {
      v8 = (v6 + 2) % 3;
      if ( v8 != 2 )
        goto LABEL_13;
      v9 = (boneCount + SelectedIndex - 1) % boneCount;
    }
    else
    {
      v8 = (v6 + 1) % 3;
      if ( v8 != 0 )
        goto LABEL_13;
      v9 = (SelectedIndex + 1) % boneCount;
    }
    boneIndex = v9;
LABEL_13:
    v10 = v13;
    for ( i = 0; i < 3; ++i )
      mxRadioButton::setChecked(this: *v10++, b: i == v8);
    mxChoice::select(this: this->cPhysicsBone, index: boneIndex);
    ControlPanel::setupPhysicsBone(this, boneIndex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A590
// Name: public: void ControlPanel::setupPhysics(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::setupPhysics(ControlPanel *this)
{
  int v2; // esi
  mxRadioButton **rbConstraintAxis; // edi
  double Mass; // st7
  char buf[64]; // [esp+14h] [ebp-40h] BYREF

  if ( PopulatePhysicsBoneList(pChoice: this->cPhysicsBone) != 0 )
  {
    mxChoice::select(this: this->cPhysicsBone, index: 0);
    v2 = 0;
    rbConstraintAxis = this->rbConstraintAxis;
    do
      mxRadioButton::setChecked(this: *rbConstraintAxis++, b: v2++ == 0);
    while ( v2 < 3 );
    ControlPanel::setupPhysicsBone(this, boneIndex: 0);
    Mass = StudioModel::Physics_GetMass(this: g_pStudioModel);
    sprintf(string: buf, format: "%.2f", Mass);
    mxWidget::setLabel(this: this->leMass, format: buf);
    g_viewerSettings.highlightPhysicsBone = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A630
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CUtlString *this)
{
  bool v2; // sf

  v2 = this->m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Storage.m_Memory.m_pMemory);
      this->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A700
// Name: public: void CBoneControlWindow::OnTabSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnTabSelected(CBoneControlWindow *this)
{
  int SelectedIndex; // eax

  SelectedIndex = mxChoice::getSelectedIndex(this: this->m_cBone);
  CBoneControlWindow::OnBoneSelected(this, boneIndex: SelectedIndex);
  if ( mxRadioButton::isChecked(this: (mxRadioButton *)this->m_cBoneHighlight) )
    g_viewerSettings.highlightBone = this->m_Bone;
  else
    g_viewerSettings.highlightBone = -1;
  if ( mxRadioButton::isChecked(this: (mxRadioButton *)this->m_cHitboxHighlight) )
    g_viewerSettings.highlightHitbox = this->m_Hitbox;
  else
    g_viewerSettings.highlightHitbox = -1;
  g_viewerSettings.showPhysicsPreview = mxRadioButton::isChecked(this: (mxRadioButton *)this->m_cShowDefaultPose);
}

//------------------------------------------------------------------------------
// Address: 0x0040A780
// Name: public: virtual int ControlPanel::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge ControlPanel::handleEvent@<eax>(
        ControlPanel *this@<ecx>,
        void *(__cdecl **a2)(const char *, int *)@<edi>,
        int event)
{
  IMDLCache *v3; // ebx
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  int v7; // edi
  int v8; // eax
  int v9; // eax
  int SelectedIndex; // edi
  const char *Label; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  bool v14; // cc
  int v15; // ebx
  int v16; // edi
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  const char *v21; // eax
  int v22; // eax
  const char *v23; // eax
  bool isChecked; // al
  mxCheckBox *cbOverbright2; // ecx
  mxCheckBox *cbBackground; // ecx
  bool v27; // al
  mxCheckBox *cbShowOriginAxis; // ecx
  int v29; // edi
  studiohdr_t *v30; // eax
  int v31; // ecx
  char *v32; // edi
  const char *v33; // eax
  int v34; // ebx
  int v35; // eax
  int *v36; // ecx
  int v37; // edi
  mxChoice *v38; // ecx
  int v39; // ebx
  int v40; // eax
  mxEvent *v41; // eax
  double v42; // st7
  double v43; // st7
  int v44; // eax
  int v45; // edi
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // edi
  CStudioHdr *v50; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  int v52; // eax
  float v53; // xmm0_4
  int v54; // eax
  int v55; // edi
  int v56; // eax
  int v57; // eax
  CStudioHdr *StudioHdr; // ebx
  LocalFlexController_t i; // edi
  mxSlider **slFlexScale; // esi
  int j; // edi
  LocalFlexController_t v62; // eax
  int FrameSelection; // eax
  int v64; // eax
  int v65; // eax
  int v66; // eax
  int v67; // eax
  CStudioHdr *v68; // ebx
  LocalFlexController_t k; // edi
  float v70; // xmm0_4
  mxSlider **v71; // esi
  int m; // edi
  LocalFlexController_t v73; // eax
  CStudioHdr *v74; // ebx
  LocalFlexController_t n; // edi
  mxSlider **v76; // esi
  int ii; // edi
  LocalFlexController_t v78; // eax
  CStudioHdr *v79; // ebx
  LocalFlexController_t jj; // edi
  mxSlider **v81; // esi
  int kk; // edi
  LocalFlexController_t v83; // eax
  LocalFlexController_t v84; // eax
  LocalFlexController_t v85; // esi
  int v86; // esi
  int v87; // edi
  mxEvent *v88; // eax
  mxSlider *v89; // ecx
  double switchValue; // [esp+4h] [ebp-27Ch]
  double switchValuea; // [esp+4h] [ebp-27Ch]
  float switchValue_4; // [esp+8h] [ebp-278h]
  float switchValue_4a; // [esp+8h] [ebp-278h]
  float switchValue_4b; // [esp+8h] [ebp-278h]
  float switchValue_4c; // [esp+8h] [ebp-278h]
  float switchValue_4d; // [esp+8h] [ebp-278h]
  float switchValue_4e; // [esp+8h] [ebp-278h]
  int switchValue_4f; // [esp+8h] [ebp-278h]
  float switchValue_4g; // [esp+8h] [ebp-278h]
  float switchValue_4h; // [esp+8h] [ebp-278h]
  float switchValue_4i; // [esp+8h] [ebp-278h]
  float switchValue_4j; // [esp+8h] [ebp-278h]
  float switchValue_4k; // [esp+8h] [ebp-278h]
  float switchValue_4l; // [esp+8h] [ebp-278h]
  float switchValue_4m; // [esp+8h] [ebp-278h]
  float switchValue_4n; // [esp+8h] [ebp-278h]
  int v108; // [esp+10h] [ebp-270h]
  char sz[256]; // [esp+18h] [ebp-268h] BYREF
  char string[256]; // [esp+118h] [ebp-168h] BYREF
  CUtlBuffer res; // [esp+218h] [ebp-68h] BYREF
  CUtlBuffer cmd; // [esp+248h] [ebp-38h] BYREF
  float flMin; // [esp+278h] [ebp-8h] BYREF
  float value; // [esp+27Ch] [ebp-4h]

  v3 = g_pMDLCache;
  BeginLock = g_pMDLCache->BeginLock;
  value = *(float *)&g_pMDLCache;
  BeginLock(this: g_pMDLCache);
  if ( g_ControlPanel == nullptr )
  {
LABEL_2:
    v3->EndLock(this: v3);
    return 1;
  }
  v7 = event;
  v8 = *(_DWORD *)(event + 4);
  if ( v8 == 1 )
  {
    mxWidget::setBounds(
      this: this->tab,
      x: 0,
      y: 0,
      w: *(_DWORD *)(event + 16),
      h: *(_DWORD *)(event + 20) - 20 < 0 ? 0 : *(_DWORD *)(event + 20) - 20);
    ControlPanel::updateSequenceSizes(this, tabWidth: *(_DWORD *)(v7 + 16));
    v3->EndLock(this: v3);
    return 1;
  }
  if ( v8 == 11 )
  {
    if ( mxTab::getSelectedIndex(this: this->tab) == 4 )
      ControlPanel::handlePhysicsKey(this, event: (mxEvent *)v7);
    v9 = *(int *)(v7 + 12);
    event = v9;
    if ( v9 < 3140 || v9 >= 3148 )
    {
      switch ( *(_DWORD *)(v7 + 36) )
      {
        case 0x1B:
          if ( mxWidget::getParent(this) != nullptr )
            goto LABEL_2;
          mx::quit();
          v3->EndLock(this: v3);
          return 1;
        case 0x2B:
          v12 = g_viewerSettings.speedScale + 0.1;
          v13 = 5.0;
          v14 = (float)(g_viewerSettings.speedScale + 0.1) <= 5.0;
          goto LABEL_18;
        case 0x2D:
          v12 = g_viewerSettings.speedScale - 0.1;
          v13 = 0.0;
          v14 = (float)(g_viewerSettings.speedScale - 0.1) >= 0.0;
LABEL_18:
          g_viewerSettings.speedScale = v12;
          if ( !v14 )
            g_viewerSettings.speedScale = v13;
          goto LABEL_2;
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
          if ( mxTab::getSelectedIndex(this: this->tab) >= 4 )
            goto LABEL_2;
          g_viewerSettings.renderMode = *(_DWORD *)(v7 + 36) - 49;
          v3->EndLock(this: v3);
          return 1;
        default:
          v3->EndLock(this: v3);
          return 0;
      }
    }
    SelectedIndex = mxChoice::getSelectedIndex(this: *((mxChoice **)this + v9 - 3073));
    Label = mxWidget::getLabel(this: *((mxWidget **)this + event - 3057));
    value = atof(nptr: Label);
    ControlPanel::setBlend(this, index: SelectedIndex, value);
    switchValue_4 = StudioModel::GetPoseParameter(this: g_pStudioModel, iParameter: SelectedIndex);
    mxSlider::setValue(this: *((mxSlider **)this + event - 3065), value: switchValue_4);
    v3->EndLock(this: v3);
    return 1;
  }
  else
  {
    v15 = *(_DWORD *)(event + 12);
    if ( v15 > 3004 )
    {
      if ( v15 > 4001 )
      {
        if ( v15 > 6000 )
        {
          if ( v15 > 9001 )
          {
            switch ( v15 )
            {
              case 9002:
              case 9003:
                ControlPanel::BuildIKRuleQCString(this);
                goto $LN1;
              case 9004:
              case 9005:
              case 9006:
              case 9007:
              case 9008:
              case 9013:
              case 9015:
              case 9016:
                goto $LN55;
              case 9009:
                FrameSelection = ControlPanel::getFrameSelection(this);
                SetFrameString(pLineEdit: this->leIKRangeStart, iLayer: FrameSelection);
                goto $LN1;
              case 9010:
                v64 = ControlPanel::getFrameSelection(this);
                SetFrameString(pLineEdit: this->leIKRangePeak, iLayer: v64);
                goto $LN1;
              case 9011:
                v65 = ControlPanel::getFrameSelection(this);
                SetFrameString(pLineEdit: this->leIKRangeTail, iLayer: v65);
                goto $LN1;
              case 9012:
                v66 = ControlPanel::getFrameSelection(this);
                SetFrameString(pLineEdit: this->leIKRangeEnd, iLayer: v66);
                goto $LN1;
              case 9014:
                v67 = ControlPanel::getFrameSelection(this);
                SetFrameString(pLineEdit: this->leIKContactFrame, iLayer: v67);
                goto $LN1;
              case 9017:
                goto $LN1;
              default:
                goto LABEL_117;
            }
          }
          if ( v15 >= 9000 )
          {
$LN55:
            ControlPanel::UpdateIKRuleWindow(this);
          }
          else if ( v15 <= 6002 )
          {
            ControlPanel::BuildEventQCString(this);
          }
          else if ( v15 != 6003 )
          {
LABEL_117:
            switch ( v15 )
            {
              case 7002:
                StudioHdr = StudioModel::GetStudioHdr(this: g_pStudioModel);
                for ( i = DUMMY_NULL_FLEX_CONTROLLER; i < StudioHdr->m_pStudioHdr->numflexcontrollers; ++i )
                  StudioModel::SetFlexController(this: g_pStudioModel, iFlex: i, flValue: 0.0);
                slFlexScale = this->slFlexScale;
                for ( j = 48; j != 0; --j )
                {
                  v62 = mxChoice::getSelectedIndex(this: (mxChoice *)*(slFlexScale - 48));
                  switchValue_4g = StudioModel::GetFlexControllerRaw(this: g_pStudioModel, iFlex: v62);
                  mxSlider::setValue(this: *slFlexScale++, value: switchValue_4g);
                }
                break;
              case 7003:
                v68 = StudioModel::GetStudioHdr(this: g_pStudioModel);
                for ( k = DUMMY_NULL_FLEX_CONTROLLER; k < v68->m_pStudioHdr->numflexcontrollers; ++k )
                {
                  v70 = (float)rand() * 0.000030518509;
                  StudioModel::SetFlexController(this: g_pStudioModel, iFlex: k, flValue: v70);
                }
                v71 = this->slFlexScale;
                for ( m = 48; m != 0; --m )
                {
                  v73 = mxChoice::getSelectedIndex(this: (mxChoice *)*(v71 - 48));
                  switchValue_4h = StudioModel::GetFlexControllerRaw(this: g_pStudioModel, iFlex: v73);
                  mxSlider::setValue(this: *v71++, value: switchValue_4h);
                }
                break;
              case 7004:
                v74 = StudioModel::GetStudioHdr(this: g_pStudioModel);
                for ( n = DUMMY_NULL_FLEX_CONTROLLER; n < v74->m_pStudioHdr->numflexcontrollers; ++n )
                  StudioModel::SetFlexController(this: g_pStudioModel, iFlex: n, flValue: 0.0);
                v76 = this->slFlexScale;
                for ( ii = 48; ii != 0; --ii )
                {
                  v78 = mxChoice::getSelectedIndex(this: (mxChoice *)*(v76 - 48));
                  switchValue_4i = StudioModel::GetFlexControllerRaw(this: g_pStudioModel, iFlex: v78);
                  mxSlider::setValue(this: *v76++, value: switchValue_4i);
                }
                break;
              case 7005:
                v79 = StudioModel::GetStudioHdr(this: g_pStudioModel);
                for ( jj = DUMMY_NULL_FLEX_CONTROLLER; jj < v79->m_pStudioHdr->numflexcontrollers; ++jj )
                  StudioModel::SetFlexController(this: g_pStudioModel, iFlex: jj, flValue: 1.0);
                v81 = this->slFlexScale;
                for ( kk = 48; kk != 0; --kk )
                {
                  v83 = mxChoice::getSelectedIndex(this: (mxChoice *)*(v81 - 48));
                  switchValue_4j = StudioModel::GetFlexControllerRaw(this: g_pStudioModel, iFlex: v83);
                  mxSlider::setValue(this: *v81++, value: switchValue_4j);
                }
                break;
              default:
                if ( v15 < 7001 || v15 >= 7049 )
                {
                  if ( v15 < 7101 || v15 >= 7149 )
                  {
                    if ( v15 >= 7501 && v15 <= 7599 )
                    {
                      v86 = ControlPanel::handlePhysicsEvent(this, (mxEvent *)event);
                      (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(value) + 124))(a1: COERCE_FLOAT(LODWORD(value)));
                      return v86;
                    }
                    if ( v15 < 3120 || v15 >= 3128 )
                    {
                      if ( v15 >= 3100 && v15 < 3108 )
                      {
                        *(float *)&v88 = COERCE_FLOAT(mxChoice::getSelectedIndex(this: *((mxChoice **)this + v15 - 3033)));
                        v89 = *(mxSlider **)(v7 + 8);
                        event = (int)v88;
                        switchValue_4n = mxSlider::getValue(this: v89);
                        ControlPanel::setBlend(this, index: event, value: switchValue_4n);
                        switchValuea = mxSlider::getValue(this: *(mxSlider **)(v7 + 8));
                        mxWidget::setLabel(this: *((mxWidget **)this + v15 - 3017), format: "%.1f", switchValuea);
                      }
                    }
                    else
                    {
                      v87 = mxChoice::getSelectedIndex(this: *((mxChoice **)this + v15 - 3053));
                      if ( StudioModel::GetPoseParameterRange(
                             this: g_pStudioModel,
                             iParameter: v87,
                             pflMin: &flMin,
                             pflMax: (float *)&event) )
                      {
                        mxSlider::setRange(
                          this: *((mxSlider **)this + v15 - 3045),
                          min: flMin,
                          max: *(float *)&event,
                          ticks: 1000);
                        switchValue_4m = StudioModel::GetPoseParameter(this: g_pStudioModel, iParameter: v87);
                        mxSlider::setValue(this: *((mxSlider **)this + v15 - 3045), value: switchValue_4m);
                        switchValue = StudioModel::GetPoseParameter(this: g_pStudioModel, iParameter: v87);
                        mxWidget::setLabel(this: *((mxWidget **)this + v15 - 3037), format: "%.1f", switchValue);
                      }
                    }
                  }
                  else
                  {
                    v85 = mxChoice::getSelectedIndex(this: *((mxChoice **)this + v15 - 6985));
                    switchValue_4l = mxSlider::getValue(this: *(mxSlider **)(v7 + 8));
                    StudioModel::SetFlexControllerRaw(this: g_pStudioModel, iFlex: v85, flValue: switchValue_4l);
                  }
                }
                else
                {
                  v84 = mxChoice::getSelectedIndex(this: *((mxChoice **)this + v15 - 6885));
                  if ( v84 >= DUMMY_NULL_FLEX_CONTROLLER )
                  {
                    switchValue_4k = StudioModel::GetFlexControllerRaw(this: g_pStudioModel, iFlex: v84);
                    mxSlider::setValue(this: *((mxSlider **)this + v15 - 6837), value: switchValue_4k);
                  }
                }
                break;
            }
          }
        }
        else
        {
          if ( v15 != 6000 )
          {
            switch ( v15 )
            {
              case 4002:
                v47 = mxChoice::getSelectedIndex(this: this->cSubmodel);
                if ( v47 >= 0 )
                  ControlPanel::setSubmodel(this, index: v47);
                goto $LN1;
              case 4003:
                v48 = mxChoice::getSelectedIndex(this: this->cController);
                if ( v48 >= 0 )
                  ControlPanel::setBoneController(this, index: v48);
                goto $LN1;
              case 4004:
                v49 = mxChoice::getSelectedIndex(this: this->cController);
                if ( v49 >= 0 )
                {
                  *(float *)&event = mxSlider::getValue(this: this->slController);
                  v50 = StudioModel::GetStudioHdr(this: g_pStudioModel);
                  m_pStudioHdr = v50->m_pStudioHdr;
                  v52 = v50->m_pStudioHdr->bonecontrollerindex + 56 * v49;
                  v53 = *(float *)&event;
                  if ( *(float *)((char *)&m_pStudioHdr->checksum + v52) > *(float *)&m_pStudioHdr->name[v52] )
                    v53 = *(float *)&event * -1.0;
                  ControlPanel::setBoneControllerValue(this, index: v49, value: v53);
                }
                goto $LN1;
              case 4005:
                v54 = mxChoice::getSelectedIndex(this: this->cSkin);
                v55 = v54;
                if ( v54 >= 0 )
                {
                  StudioModel::SetSkin(this: g_pStudioModel, iValue: v54);
                  g_viewerSettings.skin = v55;
                  this->d_MatSysWindow->redraw(this: this->d_MatSysWindow);
                }
                goto $LN1;
              case 4006:
                v56 = mxChoice::getSelectedIndex(this: this->cMaterials);
                if ( v56 >= 0 )
                  g_viewerSettings.materialIndex = v56;
                goto $LN1;
              default:
                goto LABEL_117;
            }
          }
          v57 = ControlPanel::getFrameSelection(this);
          SetFrameString(pLineEdit: this->leEventSoundFrame, iLayer: v57);
        }
      }
      else
      {
        if ( v15 != 4001 )
        {
          switch ( v15 )
          {
            case 3005:
            case 3006:
            case 3007:
            case 3008:
            case 3009:
              v38 = *((mxChoice **)this + v15 - 2969);
              v39 = v15 - 3005;
              v40 = mxChoice::getSelectedIndex(this: v38);
              if ( v40 >= 0 )
              {
                v41 = (mxEvent *)this->iSelectionToSequence[v39][v40];
                event = (int)v41;
                if ( v39 != 0 )
                {
                  switchValue_4b = mxSlider::getValue(this: *(mxSlider **)(v7 + 8));
                  ControlPanel::setOverlaySequence(this, num: v39, index: event, weight: switchValue_4b);
                }
                else
                {
                  ControlPanel::setSequence(this, index: (int)v41);
                  ControlPanel::showActivityModifiers(this, sequence: event);
                }
              }
              goto $LN1;
            case 3010:
            case 3011:
            case 3012:
            case 3013:
            case 3014:
              ControlPanel::updateFrameSelection(this);
              goto $LN1;
            case 3020:
            case 3021:
            case 3022:
            case 3023:
            case 3024:
              ControlPanel::initSequenceChoices(this, iOnlyInitSlot: v15 - 3020);
              goto $LN1;
            case 3201:
              switchValue_4d = mxSlider::getValue(this: *(mxSlider **)(event + 8));
              ControlPanel::setSpeedScale(this, scale: switchValue_4d);
              goto $LN1;
            case 3202:
              switchValue_4e = mxSlider::getValue(this: *(mxSlider **)(event + 8));
              ControlPanel::setFrame(this, frame: switchValue_4e);
              ControlPanel::setSpeedScale(this, scale: 0.0);
              if ( g_bHlmvMaster && CValveIpcClient::Connect(this: &g_HlmvIpcClient) != 0 )
              {
                CUtlBuffer::CUtlBuffer(this: &cmd, growSize: 0, initSize: 0, nFlags: 0);
                CUtlBuffer::CUtlBuffer(this: &res, growSize: 0, initSize: 0, nFlags: 0);
                v43 = mxSlider::getValue(this: *(mxSlider **)(v7 + 8));
                CUtlBuffer::Printf(this: &cmd, pFmt: "%s %f", "hlmvForceFrame", v43);
                CValveIpcClientUtl::ExecuteCommand(this: &g_HlmvIpcClient, &cmd, &res);
                CValveIpcClient::Disconnect(this: &g_HlmvIpcClient);
                CUtlBuffer::~CUtlBuffer(this: &res);
                CUtlBuffer::~CUtlBuffer(this: &cmd);
              }
              goto $LN1;
            case 3203:
              g_viewerSettings.blendSequenceChanges = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
              goto $LN1;
            case 3204:
              StudioModel::StartBlending(this: g_pStudioModel);
              goto $LN1;
            case 3205:
              v42 = mxSlider::getValue(this: *(mxSlider **)(event + 8));
              sprintf(string, format: "%.2f s", v42);
              switchValue_4c = mxSlider::getValue(this: *(mxSlider **)(v7 + 8));
              StudioModel::SetBlendTime(this: g_pStudioModel, blendtime: switchValue_4c);
              mxWidget::setLabel(this: this->laBlendTime, format: string);
              goto $LN1;
            case 3207:
              g_viewerSettings.animateWeapons = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
              goto $LN1;
            default:
              goto LABEL_117;
          }
        }
        v44 = mxChoice::getSelectedIndex(this: this->cBodypart);
        v45 = v44;
        if ( v44 >= 0 )
        {
          switchValue_4f = v44;
          v46 = mxChoice::getSelectedIndex(this: this->cBodypart);
          StudioModel::SetBodygroup(this: g_pStudioModel, iGroup: v46, iValue: switchValue_4f);
          ControlPanel::setBodypart(this, index: v45);
        }
      }
    }
    else if ( v15 >= 3000 )
    {
      v34 = v15 - 3000;
      v35 = mxChoice::getSelectedIndex(this: *(mxChoice **)(event + 8));
      if ( v35 >= 0 )
      {
        v36 = this->iSelectionToSequence[v34];
        v37 = v36[v35];
        if ( v34 != 0 )
        {
          switchValue_4a = mxSlider::getValue(this: this->slSequence[v34]);
          ControlPanel::setOverlaySequence(this, num: v34, index: v37, weight: switchValue_4a);
        }
        else
        {
          ControlPanel::setSequence(this, index: v36[v35]);
          ControlPanel::showActivityModifiers(this, sequence: v37);
        }
      }
    }
    else
    {
      switch ( v15 )
      {
        case 1901:
          v16 = mxTab::getSelectedIndex(this: this->tab);
          g_viewerSettings.highlightHitbox = -1;
          g_viewerSettings.showTexture = v16 == 3;
          g_viewerSettings.showPhysicsPreview = v16 == 4;
          v17 = mxChoice::getSelectedIndex(this: this->cHighlightBone);
          if ( v17 >= 0 )
            g_viewerSettings.highlightPhysicsBone = v17;
          if ( v16 == 4 )
          {
            v18 = mxChoice::getSelectedIndex(this: this->cPhysicsBone);
            ControlPanel::setupPhysicsBone(this, boneIndex: v18);
          }
          else if ( v16 == 5 )
          {
            CBoneControlWindow::OnTabSelected(this: this->m_pBoneWindow);
            CDmeFXClip::OnDestruction(pFactoryList: a2, nFactoryCount: v108);
            break;
          }
          CDmeFXClip::OnDestruction(pFactoryList: a2, nFactoryCount: v108);
          break;
        case 2001:
          v19 = mxChoice::getSelectedIndex(this: this->cRenderMode);
          if ( v19 >= 0 )
            ControlPanel::setRenderMode(this, mode: v19);
          break;
        case 2003:
          LOBYTE(event) = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          g_viewerSettings.showGround = event;
          mxRadioButton::setChecked(this: (mxRadioButton *)this->cbGround, b: event);
          break;
        case 2004:
          LOBYTE(event) = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          g_viewerSettings.showMovement = event;
          mxRadioButton::setChecked(this: (mxRadioButton *)this->cbMovement, b: event);
          break;
        case 2005:
          g_viewerSettings.showBackground = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          cbBackground = this->cbBackground;
          LOBYTE(event) = g_viewerSettings.showBackground;
          mxRadioButton::setChecked(this: (mxRadioButton *)cbBackground, b: g_viewerSettings.showBackground);
          break;
        case 2006:
          if ( StudioModel::GetStudioHdr(this: g_pStudioModel) == nullptr )
            mxRadioButton::setChecked(this: *(mxRadioButton **)(v7 + 8), b: false);
          g_viewerSettings.showHitBoxes = mxRadioButton::isChecked(this: *(mxRadioButton **)(v7 + 8));
          mxChoice::select(this: this->cDrawHitBoxSet, index: 0);
          mxChoice::select(this: this->cDrawHitBoxNumber, index: 0);
          g_viewerSettings.showHitBoxSet = -1;
          g_viewerSettings.showHitBoxNumber = -1;
          mxWidget::setEnabled(this: this->cDrawHitBoxSet, b: g_viewerSettings.showHitBoxes);
          if ( !g_viewerSettings.showHitBoxes || g_viewerSettings.showHitBoxSet == -1 )
            mxWidget::setEnabled(this: this->cDrawHitBoxNumber, b: false);
          else
            mxWidget::setEnabled(this: this->cDrawHitBoxNumber, b: true);
          break;
        case 2007:
          g_viewerSettings.showBones = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          break;
        case 2008:
          g_viewerSettings.showAttachments = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          break;
        case 2009:
          g_viewerSettings.showPhysicsModel = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          break;
        case 2010:
          v20 = mxChoice::getSelectedIndex(this: this->cHighlightBone);
          if ( v20 >= 0 )
            g_viewerSettings.highlightPhysicsBone = v20;
          break;
        case 2011:
          v22 = mxChoice::getSelectedIndex(this: this->cLODChoice);
          if ( v22 >= 0 )
            ControlPanel::setLOD(this, index: v22, setLODchoice: false, force: false);
          break;
        case 2012:
          isChecked = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          ControlPanel::setAutoLOD(this, b: isChecked);
          break;
        case 2013:
          v23 = mxWidget::getLabel(this: *(mxWidget **)(event + 8));
          *(float *)&event = atof(nptr: v23);
          StudioModel::SetLODSwitchValue(this: g_pStudioModel, lod: g_viewerSettings.lod, switchValue: *(float *)&event);
          break;
        case 2014:
          LOBYTE(event) = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          g_viewerSettings.softwareSkin = event;
          mxRadioButton::setChecked(this: (mxRadioButton *)this->cbSoftwareSkin, b: event);
          break;
        case 2015:
          g_viewerSettings.overbright = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          cbOverbright2 = this->cbOverbright2;
          LOBYTE(event) = g_viewerSettings.overbright;
          mxRadioButton::setChecked(this: (mxRadioButton *)cbOverbright2, b: g_viewerSettings.overbright);
          break;
        case 2016:
          v21 = mxWidget::getLabel(this: *(mxWidget **)(event + 8));
          g_viewerSettings.fov = atof(nptr: v21);
          break;
        case 2017:
          g_viewerSettings.showSequenceBoxes = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          break;
        case 2018:
          g_viewerSettings.enableIK = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          g_viewerSettings.enableTargetIK = mxRadioButton::isChecked(this: *(mxRadioButton **)(v7 + 8));
          break;
        case 2019:
          v27 = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          StudioModel::SetSolveHeadTurn(this: g_pStudioModel, solve: v27);
          break;
        case 2020:
          g_viewerSettings.showNormals = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          break;
        case 2021:
          g_viewerSettings.showTangentFrame = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          break;
        case 2022:
          g_viewerSettings.enableNormalMapping = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          break;
        case 2023:
          g_viewerSettings.enableSpecular = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          break;
        case 2024:
          g_viewerSettings.showShadow = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          break;
        case 2025:
          g_viewerSettings.showIllumPosition = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          break;
        case 2026:
          g_viewerSettings.overlayWireframe = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          break;
        case 2027:
          g_viewerSettings.playSounds = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          break;
        case 2028:
          v29 = mxListBox::getSelectedIndex(this: this->cMessageList);
          if ( v29 >= 0 )
          {
            v30 = (studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
            if ( v30 != nullptr )
            {
              g_pStudioRender->GetMaterialList(this: g_pStudioRender, a2: v30, a3: 128, a4: (IMaterial **)sz);
              mxListBox::removeAll(this: this->cShaderUsed);
              v31 = *(_DWORD *)&sz[4 * v29];
              v32 = &sz[4 * v29];
              if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v31 + 168))(a1: v31) != 0 )
              {
                mxListBox::add(this: this->cShaderUsed, item: "*** ERROR *** Can't load VMT");
              }
              else
              {
                v33 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)v32 + 196))(a1: *(_DWORD *)v32);
                mxListBox::add(this: this->cShaderUsed, item: v33);
              }
            }
          }
          break;
        case 2030:
          g_viewerSettings.showOriginAxis = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          cbShowOriginAxis = this->cbShowOriginAxis;
          LOBYTE(event) = g_viewerSettings.showOriginAxis;
          mxRadioButton::setChecked(this: (mxRadioButton *)cbShowOriginAxis, b: g_viewerSettings.showOriginAxis);
          break;
        case 2031:
          g_viewerSettings.originAxisLength = mxSlider::getValue(this: *(mxSlider **)(event + 8));
          break;
        case 2032:
          g_viewerSettings.enableDisplacementMapping = mxRadioButton::isChecked(this: *(mxRadioButton **)(event + 8));
          break;
        case 2034:
          break;
        default:
          goto LABEL_117;
      }
    }
$LN1:
    (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(value) + 124))(a1: COERCE_FLOAT(LODWORD(value)));
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BB80
// Name: private: void CBoneControlWindow::OnAddHitbox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnAddHitbox(CBoneControlWindow *this)
{
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *m_pMemory; // ecx
  bool v3; // cc
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *v4; // ecx
  CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *p_m_Hitboxes; // ebx
  unsigned __int16 v6; // ax
  int v7; // edi
  unsigned __int16 v8; // ax
  CUtlString *p_m_Name; // ecx
  int m_nHitboxSet; // edx
  HitboxSet_t *v11; // ecx
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *v12; // eax
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *v13; // edx
  int v14; // eax
  CUtlVector<int,CUtlMemory<int,int> > *v15; // ecx
  int m_Size; // ebx
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v17; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v19; // ecx
  int v20; // eax
  int *v21; // ebx
  char buf[32]; // [esp+4h] [ebp-24h] BYREF
  int i; // [esp+24h] [ebp-4h]

  if ( g_pStudioModel != nullptr )
  {
    m_pMemory = this->m_SetBoneHitBoxes.m_Memory.m_pMemory;
    v3 = m_pMemory[this->m_nHitboxSet].m_Size <= 0;
    v4 = &m_pMemory[this->m_nHitboxSet];
    if ( !v3 && v4->m_Memory.m_pMemory[this->m_Bone].m_Size == 0 )
      mxChoice::removeAll(this: this->m_cHitbox);
    p_m_Hitboxes = &g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory[this->m_nHitboxSet].m_Hitboxes;
    v6 = CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::AllocInternal(
           this: p_m_Hitboxes,
           multilist: false);
    v7 = v6;
    if ( v6 == 0xFFFF )
    {
      v8 = -1;
    }
    else
    {
      CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::LinkBefore(
        this: p_m_Hitboxes,
        before: 0xFFFFu,
        elem: v6);
      p_m_Name = &p_m_Hitboxes->m_Memory.m_pMemory[v7].m_Element.m_Name;
      if ( p_m_Name != nullptr )
        CUtlString::CUtlString(this: p_m_Name);
      v8 = v7;
    }
    m_nHitboxSet = this->m_nHitboxSet;
    v11 = g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory;
    i = v8;
    v12 = &v11[m_nHitboxSet].m_Hitboxes.m_Memory.m_pMemory[v8];
    v12->m_Element.m_BBox.bone = this->m_Bone;
    v12->m_Element.m_BBox.group = 0;
    v12->m_Element.m_BBox.bbmin.x = -8.0;
    v12->m_Element.m_BBox.bbmin.y = -8.0;
    v12->m_Element.m_BBox.bbmin.z = -8.0;
    v12->m_Element.m_BBox.bbmax.x = 8.0;
    v12->m_Element.m_BBox.bbmax.y = 8.0;
    v12->m_Element.m_BBox.bbmax.z = 8.0;
    v12->m_Element.m_BBox.szhitboxnameindex = 0;
    v13 = this->m_SetBoneHitBoxes.m_Memory.m_pMemory;
    v14 = this->m_Bone + 1;
    if ( v13[this->m_nHitboxSet].m_Size < v14 )
      CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
        this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&v13[this->m_nHitboxSet],
        elem: v13[this->m_nHitboxSet].m_Size,
        num: v14 - v13[this->m_nHitboxSet].m_Size);
    v15 = this->m_SetBoneHitBoxes.m_Memory.m_pMemory[this->m_nHitboxSet].m_Memory.m_pMemory;
    m_Size = v15[this->m_Bone].m_Size;
    v17 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v15[this->m_Bone];
    m_nAllocationCount = v17->m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v17, num: m_Size - m_nAllocationCount + 1);
    ++v17[1].m_pMemory;
    v19 = v17->m_pMemory;
    v20 = (int)v17[1].m_pMemory - m_Size - 1;
    v17[1].m_nAllocationCount = (int)v17->m_pMemory;
    if ( v20 > 0 )
      _V_memmove(dest: &v19[m_Size + 1], src: &v19[m_Size], count: 4 * v20);
    v21 = (int *)&v17->m_pMemory[m_Size];
    if ( v21 != nullptr )
      *v21 = i;
    sprintf(string: buf, format: "%d", i);
    mxChoice::add(this: this->m_cHitbox, item: buf);
    CBoneControlWindow::OnHitboxSelected(
      this,
      hitbox: this->m_SetBoneHitBoxes.m_Memory.m_pMemory[this->m_nHitboxSet].m_Memory.m_pMemory[this->m_Bone].m_Size - 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BDC0
// Name: public: HitboxSet_t::~HitboxSet_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall HitboxSet_t::~HitboxSet_t(HitboxSet_t *this)
{
  bool v2; // sf

  CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Hitboxes);
  if ( this->m_Hitboxes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Hitboxes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Hitboxes.m_Memory.m_pMemory);
      this->m_Hitboxes.m_Memory.m_pMemory = nullptr;
    }
    this->m_Hitboxes.m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Name.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Name.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Name.m_Storage.m_Memory.m_pMemory);
      this->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BE30
// Name: private: void CBoneControlWindow::OnDeleteHitbox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnDeleteHitbox(CBoneControlWindow *this)
{
  CUtlVector<int,CUtlMemory<int,int> > *v2; // edi
  int v3; // eax
  int *v4; // ecx

  if ( g_pStudioModel != nullptr && this->m_Hitbox >= 0 )
  {
    CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::Remove(
      this: &g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory[this->m_nHitboxSet].m_Hitboxes,
      elem: this->m_Hitbox);
    v2 = &this->m_SetBoneHitBoxes.m_Memory.m_pMemory[this->m_nHitboxSet].m_Memory.m_pMemory[this->m_Bone];
    v3 = v2->m_Size - 1;
    if ( v3 >= 0 )
    {
      v4 = &v2->m_Memory.m_pMemory[v3];
      while ( *v4 != this->m_Hitbox )
      {
        --v4;
        if ( --v3 < 0 )
          goto LABEL_11;
      }
      if ( v2->m_Size - v3 - 1 > 0 )
        _V_memmove(
          dest: &v2->m_Memory.m_pMemory[v3],
          src: &v2->m_Memory.m_pMemory[v3 + 1],
          count: 4 * (v2->m_Size - v3 - 1));
      --v2->m_Size;
    }
LABEL_11:
    CBoneControlWindow::ComputeHitboxList(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C0C0
// Name: private: void CBoneControlWindow::PopulateHitboxLists(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::PopulateHitboxLists(CBoneControlWindow *this)
{
  CUtlVector<CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> >,CUtlMemory<CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> >,int> > *p_m_SetBoneHitBoxes; // edi
  CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *p_m_Hitboxes; // ecx
  unsigned __int16 m_Head; // ax
  int v4; // ebx
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *m_pMemory; // eax
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *v6; // ecx
  int v7; // ebx
  mstudiobbox_t *p_m_BBox; // esi
  int v9; // eax
  CUtlVector<int,CUtlMemory<int,int> > *v10; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v13; // esi
  CUtlSymbolTable::StringPool_t **v14; // ecx
  int v15; // eax
  CUtlSymbolTable::StringPool_t **v16; // edi
  CUtlSymbolTable::StringPool_t *v17; // [esp+4h] [ebp-18h]
  int set; // [esp+8h] [ebp-14h]
  CUtlVector<CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> >,CUtlMemory<CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> >,int> > *v19; // [esp+Ch] [ebp-10h]
  CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *list; // [esp+10h] [ebp-Ch]
  int v21; // [esp+14h] [ebp-8h]
  int v22; // [esp+18h] [ebp-4h]

  if ( g_pStudioModel != nullptr )
  {
    p_m_SetBoneHitBoxes = &this->m_SetBoneHitBoxes;
    v19 = &this->m_SetBoneHitBoxes;
    CUtlVector<CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>,CUtlMemory<CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>,int>>::RemoveAll(this: &this->m_SetBoneHitBoxes);
    set = 0;
    if ( g_pStudioModel->m_HitboxSets.m_Size > 0 )
    {
      v22 = 0;
      v21 = 0;
      do
      {
        CUtlVector<CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>,CUtlMemory<CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>,int>>::InsertBefore(
          this: p_m_SetBoneHitBoxes,
          elem: p_m_SetBoneHitBoxes->m_Size);
        p_m_Hitboxes = &g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory[v21].m_Hitboxes;
        m_Head = g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory[v21].m_Hitboxes.m_Head;
        list = p_m_Hitboxes;
        if ( m_Head != 0xFFFF )
        {
          while ( 1 )
          {
            v4 = m_Head;
            m_pMemory = p_m_Hitboxes->m_Memory.m_pMemory;
            v6 = (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&p_m_SetBoneHitBoxes->m_Memory.m_pMemory[v22];
            v17 = (CUtlSymbolTable::StringPool_t *)v4;
            v7 = v4;
            p_m_BBox = &m_pMemory[v7].m_Element.m_BBox;
            v9 = p_m_BBox->bone + 1;
            if ( v6->m_Size < v9 )
              CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
                this: v6,
                elem: v6->m_Size,
                num: v9 - v6->m_Size);
            v10 = p_m_SetBoneHitBoxes->m_Memory.m_pMemory[v22].m_Memory.m_pMemory;
            m_Size = v10[p_m_BBox->bone].m_Size;
            m_nAllocationCount = v10[p_m_BBox->bone].m_Memory.m_nAllocationCount;
            v13 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v10[p_m_BBox->bone];
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v13, num: m_Size - m_nAllocationCount + 1);
            ++v13[1].m_pMemory;
            v14 = v13->m_pMemory;
            v15 = (int)v13[1].m_pMemory - m_Size - 1;
            v13[1].m_nAllocationCount = (int)v13->m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &v14[m_Size + 1], src: &v14[m_Size], count: 4 * v15);
            v16 = &v13->m_pMemory[m_Size];
            if ( v16 != nullptr )
              *v16 = v17;
            m_Head = list->m_Memory.m_pMemory[v7].m_Next;
            p_m_SetBoneHitBoxes = v19;
            if ( m_Head == 0xFFFF )
              break;
            p_m_Hitboxes = list;
          }
        }
        ++v21;
        ++v22;
        ++set;
      }
      while ( set < g_pStudioModel->m_HitboxSets.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C210
// Name: public: void CBoneControlWindow::OnLoadModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnLoadModel(CBoneControlWindow *this)
{
  CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr **p_m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  bool isChecked; // al

  ReadPhysicsMaterials(plist: this->m_cSurfaceProp);
  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
    CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = (*p_m_pStudioHdr)->m_pStudioHdr != nullptr ? *p_m_pStudioHdr : nullptr;
  }
  mxRadioButton::setChecked(this: (mxRadioButton *)this->m_cAutoHitbox, b: m_pStudioHdr->m_pStudioHdr->flags & 1);
  isChecked = mxRadioButton::isChecked(this: (mxRadioButton *)this->m_cAutoHitbox);
  CBoneControlWindow::OnAutogenerateHitboxes(this, isChecked);
  PopulateBoneList(pChoice: this->m_cBone, bAlwaysAddNone: false);
  CBoneControlWindow::ComputeHitboxSetList(this);
  CBoneControlWindow::PopulateHitboxLists(this);
  CBoneControlWindow::OnBoneSelected(this, boneIndex: 0);
  g_bDrawModelInfoValid = false;
}

//------------------------------------------------------------------------------
// Address: 0x0040C2C0
// Name: private: void CBoneControlWindow::OnHitboxSetChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnHitboxSetChanged(CBoneControlWindow *this)
{
  mxChoice *m_cHitboxSet; // ecx

  m_cHitboxSet = this->m_cHitboxSet;
  this->m_Hitbox = 0;
  this->m_nHitboxSet = mxChoice::getSelectedIndex(this: m_cHitboxSet);
  CBoneControlWindow::PopulateHitboxLists(this);
  CBoneControlWindow::ComputeHitboxList(this);
  CBoneControlWindow::RefreshHitbox(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040C300
// Name: LoadHitboxesFromFile
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadHitboxesFromFile(CDmElement *pRoot@<eax>)
{
  CStudioHdr **p_m_pStudioHdr; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  CDmAttribute *Attribute; // eax
  int v6; // edi
  int v7; // eax
  _DWORD *v8; // esi
  HitboxSet_t *v9; // ebx
  const char *v10; // eax
  CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *p_m_Hitboxes; // ebx
  int v12; // eax
  int v13; // edi
  unsigned __int16 v14; // ax
  int v15; // esi
  unsigned __int16 v16; // ax
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *m_pMemory; // eax
  int v18; // edx
  unsigned __int16 v19; // ax
  UtlLinkedListElem_t<HitboxInfo_t,unsigned short> *v20; // ecx
  CUtlString *p_m_Name; // ecx
  int v22; // esi
  const char *v23; // eax
  int v24; // esi
  CStudioHdr *v25; // ecx
  const studiohdr_t *v26; // ecx
  double v27; // st7
  int v28; // ebx
  const char *v29; // edx
  const char *v30; // edi
  _BYTE *v31; // eax
  CDmrElementArray<CDmeHitboxSet> hitboxSetList; // [esp+Ch] [ebp-2Ch] BYREF
  int nCount; // [esp+14h] [ebp-24h]
  int i; // [esp+18h] [ebp-20h]
  int m_Size; // [esp+1Ch] [ebp-1Ch]
  int j; // [esp+20h] [ebp-18h]
  CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short> > *v37; // [esp+24h] [ebp-14h]
  int k; // [esp+28h] [ebp-10h]
  CStudioHdr *pHdr; // [esp+2Ch] [ebp-Ch]
  _DWORD *v40; // [esp+30h] [ebp-8h]
  CUtlSymbol prop; // [esp+34h] [ebp-4h] BYREF

  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
    CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = (*p_m_pStudioHdr)->m_pStudioHdr != nullptr ? *p_m_pStudioHdr : nullptr;
  }
  pHdr = m_pStudioHdr;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&hitboxSetList);
  if ( pRoot != nullptr
    && (Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "hitboxsets")) != nullptr
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    hitboxSetList.m_pAttribute = Attribute;
    hitboxSetList.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>::RemoveAll(this: &g_pStudioModel->m_HitboxSets);
    if ( hitboxSetList.m_pAttribute != nullptr )
      m_Size = hitboxSetList.m_pStorage->m_Size;
    else
      m_Size = 0;
    v6 = 0;
    for ( i = 0; v6 < m_Size; i = v6 )
    {
      v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: hitboxSetList.m_pStorage->m_Memory.m_pMemory[v6]);
      v8 = (_DWORD *)v7;
      if ( v7 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
             a1: v7,
             a2: CDmeHitboxSet::m_classType.u) != 0 )
      {
        v40 = v8;
      }
      else
      {
        v40 = nullptr;
        v8 = nullptr;
      }
      v9 = &g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory[CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>::InsertBefore(
                                                              this: &g_pStudioModel->m_HitboxSets,
                                                              elem: g_pStudioModel->m_HitboxSets.m_Size)];
      v10 = (const char *)v8[5];
      if ( v10 == (const char *)-1 )
        v10 = WindowName;
      CUtlString::operator=(this: &v9->m_Name, src: v10);
      nCount = v8[20];
      j = 0;
      if ( nCount > 0 )
      {
        p_m_Hitboxes = &v9->m_Hitboxes;
        v37 = p_m_Hitboxes;
        while ( 1 )
        {
          v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                  a1: g_pDataModel.u,
                  a2: *(_DWORD *)(v8[17] + 4 * j));
          v13 = v12;
          if ( v12 == 0
            || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v12 + 16))(
                 a1: v12,
                 a2: CDmeHitbox::m_classType.u) == 0 )
          {
            v13 = 0;
          }
          v14 = CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::AllocInternal(
                  this: p_m_Hitboxes,
                  multilist: false);
          v15 = v14;
          if ( v14 == 0xFFFF )
          {
            v16 = -1;
          }
          else
          {
            CUtlLinkedList<HitboxInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<HitboxInfo_t,unsigned short>,unsigned short>>::Unlink(
              this: p_m_Hitboxes,
              elem: v14);
            m_pMemory = p_m_Hitboxes->m_Memory.m_pMemory;
            v18 = v15;
            m_pMemory[v18].m_Next = -1;
            k = p_m_Hitboxes->m_Tail;
            m_pMemory[v18].m_Previous = p_m_Hitboxes->m_Tail;
            v19 = k;
            p_m_Hitboxes->m_Tail = v15;
            if ( v19 == 0xFFFF )
              p_m_Hitboxes->m_Head = v15;
            else
              p_m_Hitboxes->m_Memory.m_pMemory[v19].m_Next = v15;
            v20 = p_m_Hitboxes->m_Memory.m_pMemory;
            ++p_m_Hitboxes->m_ElementCount;
            p_m_Name = &v20[v18].m_Element.m_Name;
            if ( p_m_Name != nullptr )
              CUtlString::CUtlString(this: p_m_Name);
            v16 = v15;
          }
          v22 = v16;
          v23 = *(const char **)(v13 + 20);
          v24 = (int)&p_m_Hitboxes->m_Memory.m_pMemory[v22];
          if ( v23 == (const char *)-1 )
            v23 = WindowName;
          CUtlString::operator=(this: (CUtlString *)v24, src: v23);
          v25 = pHdr;
          *(_DWORD *)(v24 + 48) = 0;
          *(_DWORD *)(v24 + 20) = *(_DWORD *)(v13 + 116);
          v26 = v25->m_pStudioHdr;
          *(float *)(v24 + 24) = *(float *)(v13 + 76);
          v27 = *(float *)(v13 + 80);
          k = 0;
          *(float *)(v24 + 28) = v27;
          *(float *)(v24 + 32) = *(float *)(v13 + 84);
          *(float *)(v24 + 36) = *(float *)(v13 + 92);
          *(float *)(v24 + 40) = *(float *)(v13 + 96);
          *(float *)(v24 + 44) = *(float *)(v13 + 100);
          if ( v26->numbones <= 0 )
          {
LABEL_41:
            v30 = *(const char **)(v13 + 124);
            if ( v30 == (const char *)-1 )
              v30 = WindowName;
            _Warning(a1: "HB file contained a reference to an unknown bone \"%s\"!\n", v30);
          }
          else
          {
            v28 = 0;
            while ( 1 )
            {
              v29 = *(const char **)(v13 + 124);
              if ( v29 == (const char *)-1 )
                v29 = WindowName;
              if ( _V_stricmp(
                     s1: (const char *)v26 + v28 + v26->boneindex + *(int *)((char *)&v26->id + v28 + v26->boneindex),
                     s2: v29) == 0 )
                break;
              v26 = pHdr->m_pStudioHdr;
              v28 += 216;
              if ( ++k >= v26->numbones )
              {
                p_m_Hitboxes = v37;
                goto LABEL_41;
              }
            }
            *(_DWORD *)(v24 + 16) = k;
            v31 = *(_BYTE **)(v13 + 108);
            if ( v31 != (_BYTE *)-1 && v31 != nullptr && *v31 != 0 )
            {
              CUtlSymbol::CUtlSymbol(this: &prop, pStr: *(const char **)(v13 + 108));
              g_pStudioModel->m_SurfaceProps.m_Memory.m_pMemory[*(_DWORD *)(v24 + 16)] = prop;
            }
            p_m_Hitboxes = v37;
          }
          if ( ++j >= nCount )
            break;
          v8 = v40;
        }
        v6 = i;
      }
      ++v6;
    }
  }
  else
  {
    hitboxSetList.m_pAttribute = nullptr;
    hitboxSetList.m_pStorage = nullptr;
    _Warning(a1: "Hitbox file contains no hitbox sets!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C660
// Name: private: void CBoneControlWindow::OnLoadHitboxes(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBoneControlWindow::OnLoadHitboxes(CBoneControlWindow *this@<ecx>, int a2@<esi>)
{
  const char *OpenFileName; // eax
  char pActualFileName[260]; // [esp+0h] [ebp-108h] BYREF
  CDmElement *pRoot; // [esp+104h] [ebp-4h] BYREF

  OpenFileName = mxGetOpenFileName(parent: this, path: nullptr, filter: "*.hbx");
  if ( OpenFileName != nullptr )
  {
    V_strncpy(pDest: pActualFileName, pSrc: OpenFileName, maxLen: 260);
    V_DefaultExtension(path: pActualFileName, extension: ".hbx", pathStringLength: 260);
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char *, _DWORD, _DWORD, CDmElement **, int, _DWORD, int))(*(_DWORD *)g_pDataModel.u.m_Id + 188))(
           a1: g_pDataModel.u,
           a2: pActualFileName,
           a3: 0,
           a4: 0,
           a5: &pRoot,
           a6: 3,
           a7: 0,
           a8: a2) == -1 )
    {
      _Warning(a1: "Unable to read hitbox file \"%s\"\n", pActualFileName);
    }
    else
    {
      LoadHitboxesFromFile(pRoot);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 360))(a1: g_pDataModel.u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C710
// Name: private: void CBoneControlWindow::OnHitboxAddSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnHitboxAddSet(CBoneControlWindow *this)
{
  int v2; // edi
  mxChoice *m_cHitboxSet; // ecx
  char sz[32]; // [esp+8h] [ebp-20h] BYREF

  sprintf(string: sz, format: "set%02i", g_pStudioModel->m_HitboxSets.m_Size + 1);
  v2 = CUtlVector<HitboxSet_t,CUtlMemory<HitboxSet_t,int>>::InsertBefore(
         this: &g_pStudioModel->m_HitboxSets,
         elem: g_pStudioModel->m_HitboxSets.m_Size);
  CUtlString::operator=(this: &g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory[v2].m_Name, src: sz);
  CBoneControlWindow::ComputeHitboxSetList(this);
  mxChoice::select(this: this->m_cHitboxSet, index: v2);
  m_cHitboxSet = this->m_cHitboxSet;
  this->m_Hitbox = 0;
  this->m_nHitboxSet = mxChoice::getSelectedIndex(this: m_cHitboxSet);
  CBoneControlWindow::PopulateHitboxLists(this);
  CBoneControlWindow::ComputeHitboxList(this);
  CBoneControlWindow::RefreshHitbox(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040C7B0
// Name: private: void CBoneControlWindow::OnHitboxDeleteSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnHitboxDeleteSet(CBoneControlWindow *this)
{
  int m_nHitboxSet; // esi
  unsigned int v3; // esi
  StudioModel *v4; // edi
  mxChoice *m_cHitboxSet; // ecx
  int v6; // [esp+8h] [ebp-4h]

  m_nHitboxSet = this->m_nHitboxSet;
  v6 = m_nHitboxSet;
  if ( m_nHitboxSet != 0 )
  {
    v3 = m_nHitboxSet;
    v4 = g_pStudioModel;
    HitboxSet_t::~HitboxSet_t(this: &g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory[v3]);
    if ( v4->m_HitboxSets.m_Size - v6 - 1 > 0 )
      _V_memmove(
        dest: &v4->m_HitboxSets.m_Memory.m_pMemory[v3],
        src: &v4->m_HitboxSets.m_Memory.m_pMemory[v3 + 1],
        count: 44 * (v4->m_HitboxSets.m_Size - v6 - 1));
    --v4->m_HitboxSets.m_Size;
    CBoneControlWindow::ComputeHitboxSetList(this);
    mxChoice::select(this: this->m_cHitboxSet, index: 0);
    m_cHitboxSet = this->m_cHitboxSet;
    this->m_Hitbox = 0;
    this->m_nHitboxSet = mxChoice::getSelectedIndex(this: m_cHitboxSet);
    CBoneControlWindow::PopulateHitboxLists(this);
    CBoneControlWindow::ComputeHitboxList(this);
    CBoneControlWindow::RefreshHitbox(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C860
// Name: private: void CBoneControlWindow::OnHitboxSetChangeName(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneControlWindow::OnHitboxSetChangeName(CBoneControlWindow *this)
{
  char *Label; // eax
  char *v3; // edx
  char v4; // cl
  int m_nHitboxSet; // edi
  mxChoice *m_cHitboxSet; // ecx
  char newname[512]; // [esp+4h] [ebp-200h] BYREF

  if ( g_pStudioModel->m_HitboxSets.m_Size > 0 )
  {
    Label = (char *)mxWidget::getLabel(this: this->m_eHitboxSetName);
    v3 = (char *)(newname - Label);
    do
    {
      v4 = *Label;
      Label[(_DWORD)v3] = *Label;
      ++Label;
    }
    while ( v4 != 0 );
    if ( newname[0] != 0 )
    {
      CUtlString::operator=(
        this: &g_pStudioModel->m_HitboxSets.m_Memory.m_pMemory[this->m_nHitboxSet].m_Name,
        src: newname);
      m_nHitboxSet = this->m_nHitboxSet;
      CBoneControlWindow::ComputeHitboxSetList(this);
      mxChoice::select(this: this->m_cHitboxSet, index: m_nHitboxSet);
      m_cHitboxSet = this->m_cHitboxSet;
      this->m_Hitbox = 0;
      this->m_nHitboxSet = mxChoice::getSelectedIndex(this: m_cHitboxSet);
      CBoneControlWindow::PopulateHitboxLists(this);
      CBoneControlWindow::ComputeHitboxList(this);
      CBoneControlWindow::RefreshHitbox(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C910
// Name: public: virtual int CBoneControlWindow::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBoneControlWindow::handleEvent(CBoneControlWindow *this, mxEvent *event)
{
  IMDLCache *v2; // edi
  int result; // eax
  int SelectedIndex; // eax
  bool isChecked; // al
  bool v7; // al
  int v8; // eax
  bool v9; // al
  int v10; // eax

  v2 = g_pMDLCache;
  g_pMDLCache->BeginLock(this: g_pMDLCache);
  if ( event->event == 11 )
  {
LABEL_2:
    v2->EndLock(this: v2);
    return 1;
  }
  else
  {
    switch ( event->action )
    {
      case 0x1388:
        if ( g_pStudioModel->m_MDLHandle == 0xFFFF )
          goto LABEL_2;
        CBoneControlWindow::OnHitboxGroupChanged(this);
        SelectedIndex = mxChoice::getSelectedIndex(this: this->m_cBone);
        CBoneControlWindow::OnBoneSelected(this, boneIndex: SelectedIndex);
        v2->EndLock(this: v2);
        result = 1;
        break;
      case 0x1389:
        if ( g_pStudioModel->m_MDLHandle == 0xFFFF )
          goto LABEL_2;
        CBoneControlWindow::OnHitboxGroupChanged(this);
        CBoneControlWindow::OnGenerateQC(this);
        v2->EndLock(this: v2);
        result = 1;
        break;
      case 0x138A:
        isChecked = mxRadioButton::isChecked(this: (mxRadioButton *)event->widget);
        CBoneControlWindow::OnBoneHighlighted(this, isChecked);
        v2->EndLock(this: v2);
        result = 1;
        break;
      case 0x138B:
        CBoneControlWindow::OnHitboxGroupChanged(this);
        v8 = mxChoice::getSelectedIndex(this: this->m_cHitbox);
        CBoneControlWindow::OnHitboxSelected(this, hitbox: v8);
        v2->EndLock(this: v2);
        result = 1;
        break;
      case 0x138C:
        v10 = mxChoice::getSelectedIndex(this: this->m_cSurfaceProp);
        CBoneControlWindow::OnSurfaceProp(this, propIndex: v10);
        v2->EndLock(this: v2);
        result = 1;
        break;
      case 0x138D:
        v7 = mxRadioButton::isChecked(this: (mxRadioButton *)event->widget);
        CBoneControlWindow::OnHitboxHighlighted(this, isChecked: v7);
        v2->EndLock(this: v2);
        result = 1;
        break;
      case 0x138E:
        CBoneControlWindow::OnHitboxGroupChanged(this);
        CBoneControlWindow::OnAddHitbox(this);
        v2->EndLock(this: v2);
        result = 1;
        break;
      case 0x138F:
        CBoneControlWindow::OnDeleteHitbox(this);
        v2->EndLock(this: v2);
        result = 1;
        break;
      case 0x1390:
        if ( g_pStudioModel->m_MDLHandle == 0xFFFF )
          goto LABEL_2;
        CBoneControlWindow::OnSurfacePropApplyToChildren(this);
        v2->EndLock(this: v2);
        result = 1;
        break;
      case 0x1391:
        g_viewerSettings.showPhysicsPreview = mxRadioButton::isChecked(this: (mxRadioButton *)event->widget);
        v2->EndLock(this: v2);
        result = 1;
        break;
      case 0x1399:
        CBoneControlWindow::OnHitboxChanged(this);
        v2->EndLock(this: v2);
        result = 1;
        break;
      case 0x139A:
        if ( g_pStudioModel->m_MDLHandle == 0xFFFF )
          goto LABEL_2;
        v9 = mxRadioButton::isChecked(this: (mxRadioButton *)this->m_cAutoHitbox);
        CBoneControlWindow::OnAutogenerateHitboxes(this, isChecked: v9);
        v2->EndLock(this: v2);
        result = 1;
        break;
      case 0x139B:
        CBoneControlWindow::OnHitboxSetChanged(this);
        v2->EndLock(this: v2);
        result = 1;
        break;
      case 0x139C:
        CBoneControlWindow::OnHitboxAddSet(this);
        v2->EndLock(this: v2);
        result = 1;
        break;
      case 0x139D:
        CBoneControlWindow::OnHitboxDeleteSet(this);
        v2->EndLock(this: v2);
        result = 1;
        break;
      case 0x139E:
        CBoneControlWindow::OnHitboxSetChangeName(this);
        v2->EndLock(this: v2);
        result = 1;
        break;
      case 0x13EE:
        if ( g_pStudioModel->m_MDLHandle == 0xFFFF
          || mxRadioButton::isChecked(this: (mxRadioButton *)this->m_cAutoHitbox) )
        {
          goto LABEL_2;
        }
        CBoneControlWindow::OnHitboxGroupChanged(this);
        CBoneControlWindow::OnSaveHitboxes(this, a2: (int)v2);
        v2->EndLock(this: v2);
        result = 1;
        break;
      case 0x13EF:
        if ( g_pStudioModel->m_MDLHandle != 0xFFFF )
        {
          CBoneControlWindow::OnLoadHitboxes(this, a2: (int)this);
          CBoneControlWindow::OnHitboxGroupChanged(this);
        }
        goto LABEL_2;
      default:
        v2->EndLock(this: v2);
        result = 0;
        break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040CD10
// Name: public: void ControlPanel::OnLoadModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::OnLoadModel(ControlPanel *this)
{
  const char *v2; // eax
  char *v3; // ebx
  int v4; // edi
  StudioModel *v5; // ecx
  StudioModel *v6; // ebx
  char *v7; // [esp+8h] [ebp-8h]
  bool bNoModelSettings; // [esp+Fh] [ebp-1h]

  this->m_bVMTInfoLoaded = false;
  if ( StudioModel::HasModel(this: g_pStudioModel) )
  {
    ControlPanel::initSequenceChoices(this, iOnlyInitSlot: -1);
    ControlPanel::initBodypartChoices(this);
    ControlPanel::initBoneControllers(this);
    ControlPanel::initSkinChoices(this);
    ControlPanel::initMaterialChoices(this);
    ControlPanel::initPhysicsBones(this);
    ControlPanel::initIncludedModels(this);
    ControlPanel::initLODs(this);
    ControlPanel::initFlexes(this);
    ControlPanel::setModelInfo(this);
    bNoModelSettings = LoadViewerSettings(filename: g_pStudioModel->m_pModelName, pModel: g_pStudioModel);
    if ( !bNoModelSettings )
    {
      InitViewerSettings(subkey: "hlmv");
      ControlPanel::setSequence(this, index: 0);
      ControlPanel::showActivityModifiers(this, sequence: 0);
      ControlPanel::setSpeedScale(this, scale: 1.0);
    }
    ControlPanel::resetControlPanel(this);
    ControlPanel::setupPhysics(this);
    CBoneControlWindow::OnLoadModel(this: this->m_pBoneWindow);
    CAttachmentsWindow::OnLoadModel(this: this->m_pAttachmentsWindow);
    PopulateBoneList(pChoice: this->cIKTouch, bAlwaysAddNone: true);
    v2 = mx_getpath(filename: g_pStudioModel->m_pModelName);
    mx_setcwd(path: v2);
    v3 = g_viewerSettings.mergeModelFile[0];
    v4 = 0;
    v7 = g_viewerSettings.mergeModelFile[0];
    do
    {
      v5 = g_pStudioExtraModel[v4];
      if ( v5 != nullptr )
      {
        StudioModel::FreeModel(this: v5, bReleasing: false);
        v6 = g_pStudioExtraModel[v4];
        if ( v6 != nullptr )
        {
          StudioModel::~StudioModel(this: g_pStudioExtraModel[v4]);
          StudioModel::operator delete(pMem: v6);
        }
        v3 = v7;
        g_pStudioExtraModel[v4] = nullptr;
      }
      if ( strlen(v3) != 0 )
        ControlPanel::loadModel(this, filename: v3, slot: v4);
      ++v4;
      v3 += 256;
      v7 = v3;
    }
    while ( v4 < 12 );
    if ( !bNoModelSettings )
    {
      ControlPanel::centerView(this);
      ControlPanel::centerView(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CF10
// Name: public: void ControlPanel::SetupBoneControlWindow(class mxTab __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ControlPanel::SetupBoneControlWindow(ControlPanel *this, mxTab *pTab)
{
  mxWindow *v3; // eax
  CBoneControlWindow *v4; // esi

  v3 = (mxWindow *)operator new(nSize: 0x8Cu);
  v4 = (CBoneControlWindow *)v3;
  if ( v3 != nullptr )
  {
    mxWindow::mxWindow(this: v3, parent: this, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
    v4->__vftable = (CBoneControlWindow_vtbl *)&CBoneControlWindow::`vftable';
    v4->m_SetBoneHitBoxes.m_Memory.m_pMemory = nullptr;
    v4->m_SetBoneHitBoxes.m_Memory.m_nAllocationCount = 0;
    v4->m_SetBoneHitBoxes.m_Memory.m_nGrowSize = 0;
    v4->m_SetBoneHitBoxes.m_Size = 0;
    v4->m_SetBoneHitBoxes.m_pElements = nullptr;
    v4->m_pControlPanel = this;
    v4->m_nHitboxSet = 0;
  }
  else
  {
    v4 = nullptr;
  }
  this->m_pBoneWindow = v4;
  mxTab::add(this: pTab, widget: v4, text: "Bones");
  CBoneControlWindow::Init(this: this->m_pBoneWindow);
}

//------------------------------------------------------------------------------
// Address: 0x0040CF90
// Name: public: enum LoadModelResult_t ControlPanel::loadModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ControlPanel::loadModel(ControlPanel *this, const char *filename)
{
  SaveViewerSettings(filename: g_pStudioModel->m_pModelName, pModel: g_pStudioModel);
  StudioModel::FreeModel(this: g_pStudioModel, bReleasing: false);
  if ( !StudioModel::LoadModel(this: g_pStudioModel, pModelName: filename) )
    return 1;
  if ( !g_pStudioModel->PostLoadModel(this: g_pStudioModel, a2: filename) )
    return 3;
  if ( !StudioModel::HasModel(this: g_pStudioModel) )
    return 2;
  ControlPanel::OnLoadModel(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040D020
// Name: public: enum LoadModelResult_t ControlPanel::loadModel(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ControlPanel::loadModel(ControlPanel *this, const char *filename, unsigned int slot)
{
  StudioModel *v5; // ecx
  StudioModel *v6; // eax
  mxMenuBar *mb; // ecx

  if ( slot == -1 )
    return ControlPanel::loadModel(this, filename);
  v5 = g_pStudioExtraModel[slot];
  if ( v5 != nullptr )
  {
    StudioModel::FreeModel(this: v5, bReleasing: false);
  }
  else
  {
    v6 = (StudioModel *)StudioModel::operator new(stAllocateBlock: 0x1460u);
    if ( v6 != nullptr )
      g_pStudioExtraModel[slot] = StudioModel::StudioModel(this: v6);
    else
      g_pStudioExtraModel[slot] = nullptr;
  }
  if ( !StudioModel::LoadModel(this: g_pStudioExtraModel[slot], pModelName: filename) )
    return 1;
  if ( !g_pStudioExtraModel[slot]->PostLoadModel(this: g_pStudioExtraModel[slot], a2: filename) )
    return 3;
  ControlPanel::MapExtraFlexes(this, nSlot: slot);
  if ( g_MDLViewer != nullptr )
  {
    mb = g_MDLViewer->mb;
    if ( mb != nullptr )
    {
      mxMenuBar::modify(this: mb, id: slot + 1414, newId: slot + 1414, newItem: filename);
      mxMenu::setEnabled(this: g_MDLViewer->mb, id: slot + 1414, b: true);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040D130
// Name: public: ControlPanel::ControlPanel(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
ControlPanel *__thiscall ControlPanel::ControlPanel(ControlPanel *this, mxWindow *parent)
{
  mxLabel *v3; // eax
  mxSlider *v4; // eax
  mxSlider *v5; // eax
  mxLabel *v6; // eax
  mxLabel *v7; // eax
  mxTab *v8; // eax
  mxTab *v9; // eax
  HWND Handle; // eax
  mxTab *tab; // edi
  CAttachmentsWindow *v12; // eax
  CAttachmentsWindow *v13; // eax

  mxWindow::mxWindow(this, parent, x: 0, y: 0, w: 0, h: 0, label: "Control Panel", style: 0);
  this->__vftable = (ControlPanel_vtbl *)&ControlPanel::`vftable';
  InitViewerSettings(subkey: "hlmv");
  v3 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    mxLabel::mxLabel(this: v3, parent: this, x: 5, y: 220, w: 50, h: 18, label: "Frame");
  v4 = (mxSlider *)operator new(nSize: 0x18u);
  if ( v4 != nullptr )
    v5 = mxSlider::mxSlider(this: v4, parent: this, x: 55, y: 220, w: 450, h: 18, id: 3202, style: 0);
  else
    v5 = nullptr;
  this->slForceFrame = v5;
  mxSlider::setRange(this: v5, min: 0.0, max: 1.0, ticks: 100);
  mxSlider::setValue(this: this->slForceFrame, value: 0.0);
  mxSlider::setSteps(this: this->slForceFrame, line: 1, page: 1);
  mxToolTip::add(widget: this->slForceFrame, text: "Force To Frame");
  v6 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v6 != nullptr )
    v7 = mxLabel::mxLabel(this: v6, parent: this, x: 505, y: 220, w: 30, h: 18, label: "0");
  else
    v7 = nullptr;
  this->lForcedFrame = v7;
  v8 = (mxTab *)operator new(nSize: 0xCu);
  if ( v8 != nullptr )
    v9 = mxTab::mxTab(this: v8, parent: this, x: 0, y: 20, w: 0, h: 0, id: 1901);
  else
    v9 = nullptr;
  this->tab = v9;
  Handle = (HWND)mxWidget::getHandle(this: v9);
  SetWindowLongA(hWnd: Handle, nIndex: -20, dwNewLong: 512);
  ControlPanel::SetupRenderWindow(this, pTab: this->tab);
  ControlPanel::SetupSequenceWindow(this, pTab: this->tab);
  ControlPanel::SetupBodyWindow(this, pTab: this->tab);
  ControlPanel::SetupFlexWindow(this, pTab: this->tab);
  ControlPanel::SetupPhysicsWindow(this, pTab: this->tab);
  ControlPanel::SetupBoneControlWindow(this, pTab: this->tab);
  tab = this->tab;
  v12 = (CAttachmentsWindow *)operator new(nSize: 0x24u);
  if ( v12 != nullptr )
    v13 = CAttachmentsWindow::CAttachmentsWindow(this: v12, pParent: this);
  else
    v13 = nullptr;
  this->m_pAttachmentsWindow = v13;
  mxTab::add(this: tab, widget: v13, text: "Attachments");
  CAttachmentsWindow::Init(this: this->m_pAttachmentsWindow);
  ControlPanel::SetupIKRuleWindow(this, pTab: this->tab);
  ControlPanel::SetupEventWindow(this, pTab: this->tab);
  g_ControlPanel = this;
  *(_QWORD *)this->iSelectionToSequence = 0;
  *(_QWORD *)&this->iSelectionToSequence[2] = 0;
  this->iSelectionToSequence[4] = nullptr;
  *(_QWORD *)this->iSequenceToSelection = 0;
  *(_QWORD *)&this->iSequenceToSelection[2] = 0;
  this->iSequenceToSelection[4] = nullptr;
  *(_QWORD *)this->m_iSavedSequences = 0;
  *(_QWORD *)&this->m_iSavedSequences[2] = 0;
  this->m_iSavedSequences[4] = 0;
  *(_QWORD *)this->m_flSavedWeights = 0;
  *(_QWORD *)&this->m_flSavedWeights[2] = 0;
  this->m_flSavedWeights[4] = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004827D0
// Name: public: class CDmAttribute __near * CDmElement::AddAttributeElementArray<class CDmElement>(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::AddAttributeElementArray<CDmElement>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v4 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v4 = CDmElement::CreateAttribute(this, pAttributeName, type: AT_FIRST_ARRAY_TYPE);
  if ( v4 == nullptr )
    return nullptr;
  CDmAttribute::SetElementTypeSymbol(this: v4, typeSymbol: CDmElement::m_classType);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004828D0
// Name: public: class CDmAttribute __near * CDmElement::SetValue<char const>(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<char const>(
        CDmElement *this,
        const char *pAttributeName,
        const char *pValue,
        char bCreateIfNotFound)
{
  CDmAttribute *Attribute; // esi

  if ( bCreateIfNotFound == 0 && !CDmElement::HasAttribute(this, pAttributeName, type: AT_STRING) )
    return nullptr;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
    a1: g_pDataModel.u,
    a2: &bCreateIfNotFound,
    a3: pValue);
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_STRING);
    if ( Attribute == nullptr )
      return nullptr;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&bCreateIfNotFound);
  return Attribute;
}

//------------------------------------------------------------------------------
// Address: 0x00482950
// Name: public: class CDmAttribute __near * CDmElement::InitValue<char const>(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::InitValue<char const>(
        CDmElement *this,
        const char *pAttributeName,
        const char *pValue)
{
  CDmAttribute *result; // eax
  CDmAttribute *Attribute; // esi

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 200))(
    a1: g_pDataModel.u,
    a2: &pValue,
    a3: pValue);
  result = CDmElement::FindAttribute(this, pAttributeName);
  if ( result == nullptr )
  {
    Attribute = CDmElement::FindAttribute(this, pAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pValue);
      return Attribute;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00482CB0
// Name: public: class CDmAttribute __near * CDmElement::SetValue<class CDmElement>(char const __near *,class CDmElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<CDmElement>(
        CDmElement *this,
        const char *pAttributeName,
        DmElementHandle_t pElement,
        bool bCreateIfNotFound)
{
  CDmAttribute *Attribute; // esi

  if ( pElement != 0 )
    pElement = CDmElement::GetHandle(this: (CDmElement *)pElement);
  else
    pElement = DMELEMENT_HANDLE_INVALID;
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
  {
    if ( !bCreateIfNotFound )
      return nullptr;
    Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_FIRST_VALUE_TYPE);
    if ( Attribute == nullptr )
      return nullptr;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: &pElement);
  return Attribute;
}

//------------------------------------------------------------------------------
// Address: 0x00483A90
// Name: public: class CDmElement __near * CDmElement::GetValueElement<class CDmElement>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmElement::GetValueElement<CDmElement>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  int *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_7D8E60 = -1;
    dword_7D8E64 = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = (int *)CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: *v3);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return (CDmElement *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483B20
// Name: public: class Vector const __near & CDmElement::GetValue<class Vector>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmElement::GetValue<Vector>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Vector>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return (CDmaVar<Vector> *)CDmAttribute::GetValue<Vector>(this: Attribute);
  else
    return &`CDmElement::GetValue<Vector>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00483B80
// Name: public: class Quaternion const __near & CDmElement::GetValue<class Quaternion>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmElement::GetValue<Quaternion>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<Quaternion>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Quaternion>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.z = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.w = 1.0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return (CDmaVar<Quaternion> *)CDmAttribute::GetValue<Quaternion>(this: Attribute);
  else
    return &`CDmElement::GetValue<Quaternion>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00483C40
// Name: public: class Color const __near & CDmElement::GetValue<class Color>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Color> *__thiscall CDmElement::GetValue<Color>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<Color>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Color>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Color>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Color>'::`2'::defaultVal.m_Storage = (Color)-16777216;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return (CDmaVar<Color> *)CDmAttribute::GetValue<Color>(this: Attribute);
  else
    return &`CDmElement::GetValue<Color>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004A7DB0
// Name: public: class CDmeSequenceList __near * CDmElement::GetValueElement<class CDmeSequenceList>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeSequenceList *__thiscall CDmElement::GetValueElement<CDmeSequenceList>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  int *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_7D8E60 = -1;
    dword_7D8E64 = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = (int *)CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: *v3);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeSequenceList::m_classType.u) != 0 )
  {
    return (CDmeSequenceList *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5D80
// Name: public: class CDmeDag __near * CDmElement::GetValueElement<class CDmeDag>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmElement::GetValueElement<CDmeDag>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  int *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_7D8E60 = -1;
    dword_7D8E64 = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = (int *)CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: *v3);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeDag::m_classType.u) != 0 )
  {
    return (CDmeDag *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C06B0
// Name: public: class CDmeLog __near * CDmElement::GetValueElement<class CDmeLog>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeLog *__thiscall CDmElement::GetValueElement<CDmeLog>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  int *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    dword_7D8E60 = -1;
    dword_7D8E64 = 0;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = (int *)CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: *v3);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeLog::m_classType.u) != 0 )
  {
    return (CDmeLog *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00597C60
// Name: _dynamic_initializer_for__CDmElement::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmElement::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmElement::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmElement pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmElement::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059DC20
// Name: _dynamic_atexit_destructor_for__CDmElement::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmElement::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmElement::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00597C90
// Name: _dynamic_initializer_for__g_CDmElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmElement_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmElement_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00597CA0
// Name: _dynamic_initializer_for__g_CDmElement_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmElement_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmElement_Helper,
           classname: "DmElement",
           pFactory: &g_CDmElement_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00597CC0
// Name: _dynamic_initializer_for__g_CDmeElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeElement_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeElement_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00597CD0
// Name: _dynamic_initializer_for__g_CDmeElement_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeElement_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeElement_Helper,
           classname: "DmeElement",
           pFactory: &g_CDmeElement_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00597CF0
// Name: _dynamic_initializer_for__g_DataAlloc4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DataAlloc4__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_DataAlloc4,
    blockSize: 4,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "4-byte data pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_DataAlloc4__);
}

//------------------------------------------------------------------------------
// Address: 0x00597D20
// Name: _dynamic_initializer_for__g_DataAlloc8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DataAlloc8__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_DataAlloc8,
    blockSize: 8,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "8-byte data pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_DataAlloc8__);
}

//------------------------------------------------------------------------------
// Address: 0x00597D50
// Name: _dynamic_initializer_for__g_AttrAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AttrAlloc__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_AttrAlloc,
    blockSize: 24,
    numElements: 4096,
    growMode: 2,
    pszAllocOwner: "CDmAttribute pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_AttrAlloc__);
}

//------------------------------------------------------------------------------
// Address: 0x00597D80
// Name: _dynamic_initializer_for____s_AttrDmUnknownAttribute_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrDmUnknownAttribute_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<DmUnknownAttribute_t>::`vftable';
    s_pAttrInfo[0] = result;
  }
  else
  {
    s_pAttrInfo[0] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00597DB0
// Name: _dynamic_initializer_for____s_Attrint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_Attrint__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<int>::`vftable';
    s_pAttrInfo[2] = result;
  }
  else
  {
    s_pAttrInfo[2] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00597DE0
// Name: _dynamic_initializer_for____s_AttrArrayint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayint__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<int>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[16] = result;
  }
  else
  {
    s_pAttrInfo[16] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00597E10
// Name: _dynamic_initializer_for____s_Attrfloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_Attrfloat__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<float>::`vftable';
    s_pAttrInfo[3] = result;
  }
  else
  {
    s_pAttrInfo[3] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00597E40
// Name: _dynamic_initializer_for____s_AttrArrayfloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayfloat__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<float>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[17] = result;
  }
  else
  {
    s_pAttrInfo[17] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00597E70
// Name: _dynamic_initializer_for____s_Attrbool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_Attrbool__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<bool>::`vftable';
    s_pAttrInfo[4] = result;
  }
  else
  {
    s_pAttrInfo[4] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00597EA0
// Name: _dynamic_initializer_for____s_AttrArraybool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArraybool__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<bool>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[18] = result;
  }
  else
  {
    s_pAttrInfo[18] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00597ED0
// Name: _dynamic_initializer_for____s_AttrColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrColor__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Color>::`vftable';
    s_pAttrInfo[8] = result;
  }
  else
  {
    s_pAttrInfo[8] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00597F00
// Name: _dynamic_initializer_for____s_AttrArrayColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayColor__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Color>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[22] = result;
  }
  else
  {
    s_pAttrInfo[22] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00597F30
// Name: _dynamic_initializer_for____s_AttrVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVector2D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Vector2D>::`vftable';
    s_pAttrInfo[9] = result;
  }
  else
  {
    s_pAttrInfo[9] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00597F60
// Name: _dynamic_initializer_for____s_AttrArrayVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVector2D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Vector2D>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[23] = result;
  }
  else
  {
    s_pAttrInfo[23] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00597F90
// Name: _dynamic_initializer_for____s_AttrVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVector__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Vector>::`vftable';
    s_pAttrInfo[10] = result;
  }
  else
  {
    s_pAttrInfo[10] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00597FC0
// Name: _dynamic_initializer_for____s_AttrArrayVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVector__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Vector>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[24] = result;
  }
  else
  {
    s_pAttrInfo[24] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00597FF0
// Name: _dynamic_initializer_for____s_AttrVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVector4D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Vector4D>::`vftable';
    s_pAttrInfo[11] = result;
  }
  else
  {
    s_pAttrInfo[11] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00598020
// Name: _dynamic_initializer_for____s_AttrArrayVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVector4D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Vector4D>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[25] = result;
  }
  else
  {
    s_pAttrInfo[25] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00598050
// Name: _dynamic_initializer_for____s_AttrQAngle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrQAngle__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<QAngle>::`vftable';
    s_pAttrInfo[12] = result;
  }
  else
  {
    s_pAttrInfo[12] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00598080
// Name: _dynamic_initializer_for____s_AttrArrayQAngle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayQAngle__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<QAngle>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[26] = result;
  }
  else
  {
    s_pAttrInfo[26] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005980B0
// Name: _dynamic_initializer_for____s_AttrQuaternion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrQuaternion__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Quaternion>::`vftable';
    s_pAttrInfo[13] = result;
  }
  else
  {
    s_pAttrInfo[13] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005980E0
// Name: _dynamic_initializer_for____s_AttrArrayQuaternion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayQuaternion__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Quaternion>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[27] = result;
  }
  else
  {
    s_pAttrInfo[27] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00598110
// Name: _dynamic_initializer_for____s_AttrVMatrix__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVMatrix__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<VMatrix>::`vftable';
    s_pAttrInfo[14] = result;
  }
  else
  {
    s_pAttrInfo[14] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00598140
// Name: _dynamic_initializer_for____s_AttrArrayVMatrix__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVMatrix__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<VMatrix>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[28] = result;
  }
  else
  {
    s_pAttrInfo[28] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00598170
// Name: _dynamic_initializer_for____s_AttrCUtlSymbolLarge__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrCUtlSymbolLarge__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<CUtlSymbolLarge>::`vftable';
    s_pAttrInfo[5] = result;
  }
  else
  {
    s_pAttrInfo[5] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005981A0
// Name: _dynamic_initializer_for____s_AttrArrayCUtlSymbolLarge__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayCUtlSymbolLarge__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<CUtlSymbolLarge>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[19] = result;
  }
  else
  {
    s_pAttrInfo[19] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005981D0
// Name: _dynamic_initializer_for____s_AttrCUtlBinaryBlock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrCUtlBinaryBlock__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<CUtlBinaryBlock>::`vftable';
    s_pAttrInfo[6] = result;
  }
  else
  {
    s_pAttrInfo[6] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00598200
// Name: _dynamic_initializer_for____s_AttrArrayCUtlBinaryBlock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayCUtlBinaryBlock__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<CUtlBinaryBlock>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[20] = result;
  }
  else
  {
    s_pAttrInfo[20] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00598230
// Name: _dynamic_initializer_for____s_AttrDmeTime_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrDmeTime_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<DmeTime_t>::`vftable';
    s_pAttrInfo[7] = result;
  }
  else
  {
    s_pAttrInfo[7] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00598260
// Name: _dynamic_initializer_for____s_AttrArrayDmeTime_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayDmeTime_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<DmeTime_t>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[21] = result;
  }
  else
  {
    s_pAttrInfo[21] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00598290
// Name: _dynamic_initializer_for____s_AttrDmElementHandle_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrDmElementHandle_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<enum DmElementHandle_t>::`vftable';
    s_pAttrInfo[1] = result;
  }
  else
  {
    s_pAttrInfo[1] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005982C0
// Name: _dynamic_initializer_for____s_AttrArrayDmElementHandle_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayDmElementHandle_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<enum DmElementHandle_t>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[15] = result;
  }
  else
  {
    s_pAttrInfo[15] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005982F0
// Name: _dynamic_initializer_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DataModel__()
{
  CDataModel::CDataModel(this: &g_DataModel);
  return atexit(func: dynamic_atexit_destructor_for__g_DataModel__);
}

//------------------------------------------------------------------------------
// Address: 0x00598310
// Name: _dynamic_initializer_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DmElementFramework__()
{
  CDependencyGraph::CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
  g_DmElementFramework.m_dirtyElements.m_Memory.m_pMemory = nullptr;
  g_DmElementFramework.m_dirtyElements.m_Memory.m_nAllocationCount = 256;
  g_DmElementFramework.m_dirtyElements.m_Memory.m_nGrowSize = 128;
  g_DmElementFramework.m_dirtyElements.m_Memory.m_pMemory = (DmElementHandle_t *)_g_pMemAlloc->Alloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: 1024);
  g_DmElementFramework.m_dirtyElements.m_Size = 0;
  g_DmElementFramework.m_dirtyElements.m_pElements = g_DmElementFramework.m_dirtyElements.m_Memory.m_pMemory;
  g_DmElementFramework.m_phase = PH_EDIT;
  return atexit(func: dynamic_atexit_destructor_for__g_DmElementFramework__);
}

//------------------------------------------------------------------------------
// Address: 0x00598380
// Name: _dynamic_initializer_for__g_KeyValues2ErrorStack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValues2ErrorStack__()
{
  memset(&g_KeyValues2ErrorStack, 0xFFu, 0x100u);
  g_KeyValues2ErrorStack.m_pFilename = "NULL";
  g_KeyValues2ErrorStack.m_nFileLine = 1;
  g_KeyValues2ErrorStack.m_errorIndex = 0;
  g_KeyValues2ErrorStack.m_maxErrorIndex = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005983C0
// Name: _dynamic_initializer_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMSerializerKeyValues2__()
{
  CDmElementDictionary::CDmElementDictionary(this: &s_DMSerializerKeyValues2.m_ElementDict);
  s_DMSerializerKeyValues2.m_bFlatMode = false;
  return atexit(func: dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__);
}

//------------------------------------------------------------------------------
// Address: 0x005983E0
// Name: _dynamic_initializer_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMSerializerKeyValues2Flat__()
{
  CDmElementDictionary::CDmElementDictionary(this: &s_DMSerializerKeyValues2Flat.m_ElementDict);
  s_DMSerializerKeyValues2Flat.m_bFlatMode = true;
  return atexit(func: dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__);
}

//------------------------------------------------------------------------------
// Address: 0x00598400
// Name: _dynamic_initializer_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMSerializerKeyValues__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_DMSerializerKeyValues__);
}

//------------------------------------------------------------------------------
// Address: 0x00598410
// Name: _dynamic_initializer_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AttrNodePool__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_AttrNodePool,
    blockSize: 28,
    numElements: 1000,
    growMode: 1,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_AttrNodePool__);
}

//------------------------------------------------------------------------------
// Address: 0x00598440
// Name: _dynamic_initializer_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_OperatorNodePool,
    blockSize: 32,
    numElements: 1000,
    growMode: 1,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_OperatorNodePool__);
}

//------------------------------------------------------------------------------
// Address: 0x00598470
// Name: _dynamic_initializer_for__s_ImportSFMV9__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV9__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV9, formatName: "sfm_v9", nextFormatName: "sfm_v10");
  s_ImportSFMV9.__vftable = (CImportSFMV9_vtbl *)&CImportSFMV9::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00598490
// Name: _dynamic_initializer_for__s_ImportSFMV8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV8__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV8, formatName: "sfm_v8", nextFormatName: "sfm_v9");
  s_ImportSFMV8.__vftable = (CImportSFMV8_vtbl *)&CImportSFMV8::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005984B0
// Name: _dynamic_initializer_for__s_ImportSFMV7__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV7__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV7, formatName: "sfm_v7", nextFormatName: "sfm_v8");
  s_ImportSFMV7.__vftable = (CImportSFMV7_vtbl *)&CImportSFMV7::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005984D0
// Name: _dynamic_initializer_for__s_ImportSFMV6__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV6__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV6, formatName: "sfm_v6", nextFormatName: "sfm_v7");
  s_ImportSFMV6.__vftable = (CImportSFMV6_vtbl *)&CImportSFMV6::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005984F0
// Name: _dynamic_initializer_for__s_ImportSFMV5__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV5__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV5, formatName: "sfm_v5", nextFormatName: "sfm_v6");
  s_ImportSFMV5.__vftable = (CImportSFMV5_vtbl *)&CImportSFMV5::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00598510
// Name: _dynamic_initializer_for__s_ImportSFMV4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV4__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV4, formatName: "sfm_v4", nextFormatName: "sfm_v5");
  s_ImportSFMV4.__vftable = (CImportSFMV4_vtbl *)&CImportSFMV4::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00598530
// Name: _dynamic_initializer_for__s_ImportSFMV3__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV3__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV3, formatName: "sfm_v3", nextFormatName: "sfm_v4");
  s_ImportSFMV3.__vftable = (CImportSFMV3_vtbl *)&CImportSFMV3::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00598550
// Name: _dynamic_initializer_for__s_ImportSFMV2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV2__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV2, formatName: "sfm_v2", nextFormatName: "sfm_v3");
  s_ImportSFMV2.__vftable = (CImportSFMV2_vtbl *)&CImportSFMV2::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00598570
// Name: _dynamic_initializer_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ImportDmxV1__()
{
  CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportDmxV1, formatName: "sfm_v1", nextFormatName: "sfm_v2");
  s_ImportDmxV1.__vftable = (CImportSFMV1_vtbl *)&CImportSFMV1::`vftable';
  s_ImportDmxV1.m_fixedElements.m_Elements.m_pMemory = nullptr;
  s_ImportDmxV1.m_fixedElements.m_Elements.m_nAllocationCount = 0;
  s_ImportDmxV1.m_fixedElements.m_Elements.m_nGrowSize = 0;
  s_ImportDmxV1.m_fixedElements.m_Root = -1;
  s_ImportDmxV1.m_fixedElements.m_NumElements = 0;
  s_ImportDmxV1.m_fixedElements.m_FirstFree = -1;
  s_ImportDmxV1.m_fixedElements.m_LastAlloc.index = -1;
  s_ImportDmxV1.m_fixedElements.m_pElements = nullptr;
  s_ImportDmxV1.m_fixedElements.m_LessFunc = CDefOps<CDmAttribute *>::LessFunc;
  return atexit(func: dynamic_atexit_destructor_for__s_ImportDmxV1__);
}

//------------------------------------------------------------------------------
// Address: 0x0059DC30
// Name: _dynamic_atexit_destructor_for__g_CDmeElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeElement_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeElement_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059DC40
// Name: _dynamic_atexit_destructor_for__g_CDmElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmElement_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmElement_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059DC50
// Name: _dynamic_atexit_destructor_for__g_DataAlloc4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc4__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc4);
}

//------------------------------------------------------------------------------
// Address: 0x0059DC60
// Name: _dynamic_atexit_destructor_for__g_DataAlloc8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc8__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc8);
}

//------------------------------------------------------------------------------
// Address: 0x0059DC70
// Name: _dynamic_atexit_destructor_for__g_AttrAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrAlloc__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrAlloc);
}
