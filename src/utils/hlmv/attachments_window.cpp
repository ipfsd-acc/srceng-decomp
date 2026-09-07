// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlmv/attachments_window.cpp
// Functions: 11
// ============================================================

#include "utils\hlmv\attachments_window.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: public: class CStudioHdr __near * StudioModel::GetStudioHdr(void)const
// Source: json
//------------------------------------------------------------------------------
CStudioHdr *__thiscall StudioModel::GetStudioHdr(StudioModel *this)
{
  CStudioHdr *result; // eax
  const studiohdr_t *v3; // eax

  result = this->m_pStudioHdr;
  if ( result != nullptr && result->m_pStudioHdr == nullptr )
  {
    v3 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: this->m_MDLHandle);
    CStudioHdr::Init(this: this->m_pStudioHdr, pStudioHdr: v3, mdlcache: nullptr);
    return this->m_pStudioHdr->m_pStudioHdr != nullptr ? this->m_pStudioHdr : nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401040
// Name: public: CAttachmentsWindow::CAttachmentsWindow(class ControlPanel __near *)
// Source: json
//------------------------------------------------------------------------------
CAttachmentsWindow *__thiscall CAttachmentsWindow::CAttachmentsWindow(CAttachmentsWindow *this, ControlPanel *pParent)
{
  mxWindow::mxWindow(this, parent: pParent, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  this->m_pControlPanel = pParent;
  this->__vftable = (CAttachmentsWindow_vtbl *)&CAttachmentsWindow::`vftable';
  g_viewerSettings.m_iEditAttachment = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401080
// Name: public: void CAttachmentsWindow::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttachmentsWindow::Init(CAttachmentsWindow *this)
{
  mxLabel *v2; // eax
  mxListBox *v3; // eax
  mxListBox *v4; // eax
  mxLabel *v5; // eax
  mxListBox *v6; // eax
  mxListBox *v7; // eax
  mxLabel *v8; // eax
  mxLineEdit2 *v9; // eax
  mxLineEdit2 *v10; // eax
  mxLabel *v11; // eax
  mxLineEdit2 *v12; // eax
  mxLineEdit2 *v13; // eax
  mxLabel *v14; // eax
  mxLineEdit2 *v15; // eax

  v2 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v2 != nullptr )
    mxLabel::mxLabel(this: v2, parent: this, x: 8, y: 4, w: 60, h: 18, label: "Attachment");
  v3 = (mxListBox *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    v4 = mxListBox::mxListBox(this: v3, parent: this, x: 5, y: 20, w: 260, h: 100, id: 5024, style: 0);
  else
    v4 = nullptr;
  this->m_cAttachmentList = v4;
  mxListBox::add(this: v4, item: "None");
  mxListBox::select(this: this->m_cAttachmentList, index: 0);
  mxToolTip::add(widget: this->m_cAttachmentList, text: "Select an attachment to modify");
  v5 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v5 != nullptr )
    mxLabel::mxLabel(this: v5, parent: this, x: 283, y: 4, w: 60, h: 18, label: "Attach To Bone");
  v6 = (mxListBox *)operator new(nSize: 0xCu);
  if ( v6 != nullptr )
    v7 = mxListBox::mxListBox(this: v6, parent: this, x: 280, y: 20, w: 260, h: 100, id: 5025, style: 0);
  else
    v7 = nullptr;
  this->m_cBoneList = v7;
  mxListBox::add(this: v7, item: "None");
  mxListBox::select(this: this->m_cBoneList, index: 0);
  mxToolTip::add(widget: this->m_cBoneList, text: "Select a bone to attach to");
  v8 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v8 != nullptr )
    mxLabel::mxLabel(this: v8, parent: this, x: 8, y: 124, w: 60, h: 18, label: "Translation");
  v9 = (mxLineEdit2 *)operator new(nSize: 0xCu);
  if ( v9 != nullptr )
    v10 = mxLineEdit2::mxLineEdit2(
            this: v9,
            parent: this,
            x: 75,
            y: 120,
            w: 90,
            h: 25,
            label: "10 20 30",
            id: 5026,
            style: 0);
  else
    v10 = nullptr;
  this->m_cTranslation = v10;
  v11 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v11 != nullptr )
    mxLabel::mxLabel(this: v11, parent: this, x: 173, y: 124, w: 60, h: 18, label: "Rotation");
  v12 = (mxLineEdit2 *)operator new(nSize: 0xCu);
  if ( v12 != nullptr )
    v13 = mxLineEdit2::mxLineEdit2(
            this: v12,
            parent: this,
            x: 240,
            y: 120,
            w: 90,
            h: 25,
            label: "0 90 180",
            id: 5027,
            style: 0);
  else
    v13 = nullptr;
  this->m_cRotation = v13;
  v14 = (mxLabel *)operator new(nSize: 0xCu);
  if ( v14 != nullptr )
    mxLabel::mxLabel(this: v14, parent: this, x: 5, y: 145, w: 60, h: 18, label: "QC String");
  v15 = (mxLineEdit2 *)operator new(nSize: 0xCu);
  if ( v15 != nullptr )
    this->m_cQCString = mxLineEdit2::mxLineEdit2(
                          this: v15,
                          parent: this,
                          x: 75,
                          y: 145,
                          w: 400,
                          h: 25,
                          label: "$attachment \"controlpanel0_ur\" \"Vgui\" -22 -15 4 rotate 0 0 0",
                          id: 5028,
                          style: 0);
  else
    this->m_cQCString = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00401290
// Name: private: void CAttachmentsWindow::PopulateBoneList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttachmentsWindow::PopulateBoneList(CAttachmentsWindow *this)
{
  CStudioHdr *m_pStudioHdr; // esi
  CStudioHdr **p_m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  const studiohdr_t *v5; // ecx
  int numbones; // eax
  int v7; // edi
  int v8; // ebx

  mxListBox::removeAll(this: this->m_cBoneList);
  if ( g_pStudioModel == nullptr )
    goto LABEL_10;
  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
    CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = (*p_m_pStudioHdr)->m_pStudioHdr != nullptr ? *p_m_pStudioHdr : nullptr;
  }
  v5 = m_pStudioHdr->m_pStudioHdr;
  numbones = m_pStudioHdr->m_pStudioHdr->numbones;
  if ( numbones == 0 )
  {
LABEL_10:
    mxListBox::add(this: this->m_cBoneList, item: "None");
    goto LABEL_11;
  }
  v7 = 0;
  if ( numbones <= 0 )
  {
LABEL_11:
    mxListBox::select(this: this->m_cBoneList, index: 0);
    return;
  }
  v8 = 0;
  do
  {
    mxListBox::add(
      this: this->m_cBoneList,
      item: (const char *)v5 + v8 + v5->boneindex + *(int *)((char *)&v5->id + v8 + v5->boneindex));
    v5 = m_pStudioHdr->m_pStudioHdr;
    ++v7;
    v8 += 216;
  }
  while ( v7 < m_pStudioHdr->m_pStudioHdr->numbones );
  mxListBox::select(this: this->m_cBoneList, index: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00401360
// Name: private: class Vector CAttachmentsWindow::GetCurrentTranslation(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAttachmentsWindow::GetCurrentTranslation(CAttachmentsWindow *this, Vector *result)
{
  CStudioHdr *m_pStudioHdr; // esi
  CStudioHdr **p_m_pStudioHdr; // edi
  const studiohdr_t *v5; // eax
  int v6; // edi
  float *v7; // eax

  if ( g_pStudioModel != nullptr )
  {
    m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
    p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
      CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
      m_pStudioHdr = (*p_m_pStudioHdr)->m_pStudioHdr != nullptr ? *p_m_pStudioHdr : nullptr;
    }
  }
  else
  {
    m_pStudioHdr = nullptr;
  }
  v6 = mxListBox::getSelectedIndex(this: this->m_cAttachmentList) - 1;
  if ( m_pStudioHdr != nullptr && v6 >= 0 && v6 < CStudioHdr::GetNumAttachments(this: m_pStudioHdr) )
  {
    v7 = (float *)CStudioHdr::pAttachment(this: m_pStudioHdr, i: v6);
    result->x = v7[6];
    result->y = v7[10];
    result->z = v7[14];
    return result;
  }
  else
  {
    *result = vec3_origin;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401410
// Name: private: class Vector CAttachmentsWindow::GetCurrentRotation(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAttachmentsWindow::GetCurrentRotation(CAttachmentsWindow *this, Vector *result)
{
  CStudioHdr *m_pStudioHdr; // esi
  CStudioHdr **p_m_pStudioHdr; // edi
  const studiohdr_t *v5; // eax
  int v6; // edi
  const mstudioattachment_t *v7; // eax
  Vector angles; // [esp+Ch] [ebp-Ch] BYREF

  if ( g_pStudioModel != nullptr )
  {
    m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
    p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
    if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
      CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v5, mdlcache: nullptr);
      m_pStudioHdr = (*p_m_pStudioHdr)->m_pStudioHdr != nullptr ? *p_m_pStudioHdr : nullptr;
    }
  }
  else
  {
    m_pStudioHdr = nullptr;
  }
  v6 = mxListBox::getSelectedIndex(this: this->m_cAttachmentList) - 1;
  if ( m_pStudioHdr != nullptr && v6 >= 0 && v6 < CStudioHdr::GetNumAttachments(this: m_pStudioHdr) )
  {
    v7 = CStudioHdr::pAttachment(this: m_pStudioHdr, i: v6);
    MatrixAngles(matrix: &v7->local, angles: &angles.x);
    *result = angles;
    return result;
  }
  else
  {
    *result = vec3_origin;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004014E0
// Name: private: void CAttachmentsWindow::UpdateStrings(bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttachmentsWindow::UpdateStrings(
        CAttachmentsWindow *this,
        bool bUpdateQC,
        bool bUpdateTranslation,
        bool bUpdateRotation)
{
  CStudioHdr *m_pStudioHdr; // esi
  CStudioHdr **p_m_pStudioHdr; // edi
  const studiohdr_t *v7; // eax
  int v8; // edi
  int AttachmentBone; // edi
  char str[1024]; // [esp+40h] [ebp-41Ch] BYREF
  mstudioattachment_t *pAttachment; // [esp+440h] [ebp-1Ch]
  Vector vRotation; // [esp+444h] [ebp-18h] BYREF
  Vector vTranslation; // [esp+450h] [ebp-Ch] BYREF

  if ( g_pStudioModel == nullptr )
    goto LABEL_8;
  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v7 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
    CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v7, mdlcache: nullptr);
    m_pStudioHdr = (*p_m_pStudioHdr)->m_pStudioHdr != nullptr ? *p_m_pStudioHdr : nullptr;
  }
  v8 = mxListBox::getSelectedIndex(this: this->m_cAttachmentList) - 1;
  if ( v8 >= 0 && v8 < CStudioHdr::GetNumAttachments(this: m_pStudioHdr) && v8 != -1 )
  {
    pAttachment = (mstudioattachment_t *)CStudioHdr::pAttachment(this: m_pStudioHdr, i: v8);
    AttachmentBone = CStudioHdr::GetAttachmentBone(this: m_pStudioHdr, i: v8);
    CAttachmentsWindow::GetCurrentTranslation(this, result: &vTranslation);
    CAttachmentsWindow::GetCurrentRotation(this, result: &vRotation);
    if ( bUpdateQC )
    {
      sprintf(
        string: str,
        format: "$attachment \"%s\" \"%s\" %.2f %.2f %.2f rotate %.0f %.0f %.0f",
        (const char *)pAttachment + pAttachment->sznameindex,
        (const char *)m_pStudioHdr->m_pStudioHdr
      + 216 * AttachmentBone
      + m_pStudioHdr->m_pStudioHdr->boneindex
      + *(int *)((char *)&m_pStudioHdr->m_pStudioHdr->id + 216 * AttachmentBone + m_pStudioHdr->m_pStudioHdr->boneindex),
        vTranslation.x,
        vTranslation.y,
        vTranslation.z,
        vRotation.x,
        vRotation.y,
        vRotation.z);
      mxLineEdit2::setText(this: this->m_cQCString, pText: str);
    }
    if ( bUpdateTranslation )
    {
      sprintf(string: str, format: "%.2f %.2f %.2f", vTranslation.x, vTranslation.y, vTranslation.z);
      mxLineEdit2::setText(this: this->m_cTranslation, pText: str);
    }
    if ( bUpdateRotation )
    {
      sprintf(string: str, format: "%.0f %.0f %.0f", vRotation.x, vRotation.y, vRotation.z);
      mxLineEdit2::setText(this: this->m_cRotation, pText: str);
    }
  }
  else
  {
LABEL_8:
    mxLineEdit2::setText(this: this->m_cTranslation, pText: "(none)");
    mxLineEdit2::setText(this: this->m_cRotation, pText: "(none)");
    mxLineEdit2::setText(this: this->m_cQCString, pText: "(none)");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401730
// Name: private: void CAttachmentsWindow::OnSelChangeAttachmentList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttachmentsWindow::OnSelChangeAttachmentList(CAttachmentsWindow *this)
{
  CStudioHdr *m_pStudioHdr; // esi
  CStudioHdr **p_m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  int v5; // edi
  CStudioHdr *StudioHdr; // eax
  int AttachmentBone; // eax

  if ( g_pStudioModel != nullptr )
  {
    m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
    p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr )
      return;
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
      CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
      m_pStudioHdr = (*p_m_pStudioHdr)->m_pStudioHdr != nullptr ? *p_m_pStudioHdr : nullptr;
    }
  }
  else
  {
    m_pStudioHdr = nullptr;
  }
  if ( m_pStudioHdr != nullptr )
  {
    v5 = mxListBox::getSelectedIndex(this: this->m_cAttachmentList) - 1;
    if ( v5 < 0 || v5 >= CStudioHdr::GetNumAttachments(this: m_pStudioHdr) )
    {
      g_viewerSettings.m_iEditAttachment = -1;
      CAttachmentsWindow::UpdateStrings(this, bUpdateQC: true, bUpdateTranslation: true, bUpdateRotation: true);
    }
    else
    {
      g_viewerSettings.m_iEditAttachment = v5;
      StudioHdr = StudioModel::GetStudioHdr(this: g_pStudioModel);
      AttachmentBone = CStudioHdr::GetAttachmentBone(this: StudioHdr, i: v5);
      mxListBox::select(this: this->m_cBoneList, index: AttachmentBone);
      CAttachmentsWindow::UpdateStrings(this, bUpdateQC: true, bUpdateTranslation: true, bUpdateRotation: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004017F0
// Name: private: void CAttachmentsWindow::PopulateAttachmentsList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttachmentsWindow::PopulateAttachmentsList(CAttachmentsWindow *this)
{
  CStudioHdr *m_pStudioHdr; // esi
  CStudioHdr **p_m_pStudioHdr; // edi
  const studiohdr_t *v4; // eax
  int i; // edi
  const mstudioattachment_t *v6; // eax

  mxListBox::removeAll(this: this->m_cAttachmentList);
  mxListBox::add(this: this->m_cAttachmentList, item: "(none)");
  if ( g_pStudioModel == nullptr )
    goto LABEL_9;
  m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
  p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
    CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
    m_pStudioHdr = (*p_m_pStudioHdr)->m_pStudioHdr != nullptr ? *p_m_pStudioHdr : nullptr;
  }
  if ( CStudioHdr::GetNumAttachments(this: m_pStudioHdr) != 0 )
  {
    for ( i = 0; i < CStudioHdr::GetNumAttachments(this: m_pStudioHdr); ++i )
    {
      v6 = CStudioHdr::pAttachment(this: m_pStudioHdr, i);
      mxListBox::add(this: this->m_cAttachmentList, item: (const char *)v6 + v6->sznameindex);
    }
    mxListBox::select(this: this->m_cAttachmentList, index: 0);
    CAttachmentsWindow::OnSelChangeAttachmentList(this);
  }
  else
  {
LABEL_9:
    mxListBox::select(this: this->m_cAttachmentList, index: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004018B0
// Name: public: virtual int CAttachmentsWindow::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAttachmentsWindow::handleEvent(CAttachmentsWindow *this, mxEvent *event)
{
  IMDLCache *v2; // ebx
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  CStudioHdr *m_pStudioHdr; // ecx
  CStudioHdr **p_m_pStudioHdr; // esi
  const studiohdr_t *v7; // eax
  CStudioHdr *v8; // esi
  int m_iEditAttachment; // ebx
  int v11; // ebx
  const mstudioattachment_t *v12; // eax
  mxLineEdit2 *m_cTranslation; // ecx
  float *p_sznameindex; // esi
  int v15; // ebx
  const mstudioattachment_t *v16; // eax
  mxLineEdit2 *m_cRotation; // ecx
  const mstudioattachment_t *v18; // esi
  char curText[512]; // [esp+8h] [ebp-21Ch] BYREF
  Vector v20; // [esp+208h] [ebp-1Ch] BYREF
  QAngle vRotation; // [esp+214h] [ebp-10h] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+220h] [ebp-4h]
  int iBone; // [esp+22Ch] [ebp+8h]

  v2 = g_pMDLCache;
  BeginLock = g_pMDLCache->BeginLock;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock(this: g_pMDLCache);
  if ( g_pStudioModel != nullptr )
  {
    m_pStudioHdr = g_pStudioModel->m_pStudioHdr;
    p_m_pStudioHdr = &g_pStudioModel->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      v8 = g_pStudioModel->m_pStudioHdr;
    }
    else
    {
      v7 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pStudioModel->m_MDLHandle);
      CStudioHdr::Init(this: *p_m_pStudioHdr, pStudioHdr: v7, mdlcache: nullptr);
      v8 = (*p_m_pStudioHdr)->m_pStudioHdr != nullptr ? *p_m_pStudioHdr : nullptr;
    }
    switch ( event->action )
    {
      case 0x13A0:
        CAttachmentsWindow::OnSelChangeAttachmentList(this);
        v2->EndLock(this: v2);
        return 1;
      case 0x13A1:
        m_iEditAttachment = g_viewerSettings.m_iEditAttachment;
        iBone = mxListBox::getSelectedIndex(this: this->m_cBoneList);
        if ( m_iEditAttachment >= 0
          && m_iEditAttachment < CStudioHdr::GetNumAttachments(this: v8)
          && iBone >= 0
          && iBone < v8->m_pStudioHdr->numbones )
        {
          CStudioHdr::SetAttachmentBone(this: v8, iAttachment: m_iEditAttachment, iBone);
          CAttachmentsWindow::UpdateStrings(this, bUpdateQC: true, bUpdateTranslation: true, bUpdateRotation: true);
        }
        goto LABEL_20;
      case 0x13A2:
        v11 = g_viewerSettings.m_iEditAttachment;
        if ( g_viewerSettings.m_iEditAttachment < 0 || v11 >= CStudioHdr::GetNumAttachments(this: v8) )
          goto LABEL_20;
        v12 = CStudioHdr::pAttachment(this: v8, i: v11);
        m_cTranslation = this->m_cTranslation;
        p_sznameindex = (float *)&v12->sznameindex;
        memset(&vRotation, 0, sizeof(vRotation));
        mxLineEdit2::getText(this: m_cTranslation, pOut: curText, len: 512);
        sscanf(string: curText, format: "%f %f %f", &vRotation, &vRotation.y, &vRotation.z);
        p_sznameindex[6] = vRotation.x;
        p_sznameindex[10] = vRotation.y;
        p_sznameindex[14] = vRotation.z;
        break;
      case 0x13A3:
        v15 = g_viewerSettings.m_iEditAttachment;
        if ( g_viewerSettings.m_iEditAttachment < 0 || v15 >= CStudioHdr::GetNumAttachments(this: v8) )
          goto LABEL_20;
        v16 = CStudioHdr::pAttachment(this: v8, i: v15);
        m_cRotation = this->m_cRotation;
        v18 = v16;
        memset(&vRotation, 0, sizeof(vRotation));
        mxLineEdit2::getText(this: m_cRotation, pOut: curText, len: 512);
        sscanf(string: curText, format: "%f %f %f", &vRotation, &vRotation.y, &vRotation.z);
        CAttachmentsWindow::GetCurrentTranslation(this, result: &v20);
        AngleMatrix(angles: &vRotation, position: &v20, matrix: &v18->local);
        break;
      default:
        goto LABEL_21;
    }
    CAttachmentsWindow::UpdateStrings(this, bUpdateQC: true, bUpdateTranslation: false, bUpdateRotation: false);
LABEL_20:
    cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
    return 1;
  }
  else
  {
LABEL_21:
    v2->EndLock(this: v2);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401B20
// Name: public: void CAttachmentsWindow::OnLoadModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttachmentsWindow::OnLoadModel(CAttachmentsWindow *this)
{
  int m_iEditAttachment; // edi

  m_iEditAttachment = g_viewerSettings.m_iEditAttachment;
  CAttachmentsWindow::PopulateBoneList(this);
  CAttachmentsWindow::PopulateAttachmentsList(this);
  if ( m_iEditAttachment >= 0 && m_iEditAttachment < mxListBox::getItemCount(this: this->m_cAttachmentList) )
    mxListBox::select(this: this->m_cAttachmentList, index: m_iEditAttachment + 1);
  g_viewerSettings.m_iEditAttachment = m_iEditAttachment;
  CAttachmentsWindow::UpdateStrings(this, bUpdateQC: true, bUpdateTranslation: true, bUpdateRotation: true);
}
