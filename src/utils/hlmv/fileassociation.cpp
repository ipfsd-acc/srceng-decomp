// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlmv/fileassociation.cpp
// Functions: 5
// ============================================================

#include "utils\hlmv\fileassociation.h"

//------------------------------------------------------------------------------
// Address: 0x004105E0
// Name: public: void FileAssociation::setAssociation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FileAssociation::setAssociation(FileAssociation *this, int index)
{
  char *v3; // edi
  int v4; // esi
  const char *v5; // edi
  mxRadioButton **indexa; // [esp+14h] [ebp+8h]

  mxChoice::select(this: this->cExtension, index);
  v3 = (char *)this + 276 * index;
  mxWidget::setLabel(this: this->leProgram, format: v3 + 56);
  v4 = 0;
  indexa = this->rbAction;
  do
    mxRadioButton::setChecked(this: *indexa++, b: v4++ == *((_DWORD *)v3 + 78));
  while ( v4 < 4 );
  mxWidget::setEnabled(this: this->leProgram, b: *((_DWORD *)v3 + 78) == 0);
  mxWidget::setEnabled(this: this->bChooseProgram, b: *((_DWORD *)v3 + 78) == 0);
  v5 = v3 + 40;
  if ( mx_strcasecmp(s1: v5, s2: "mdl") != 0
    && mx_strcasecmp(s1: v5, s2: "tga") != 0
    && mx_strcasecmp(s1: v5, s2: "wav") != 0 )
  {
    mxWidget::setEnabled(this: this->rbAction[2], b: false);
  }
  else
  {
    mxWidget::setEnabled(this: this->rbAction[2], b: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004106D0
// Name: private: void FileAssociation::saveAssociations(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FileAssociation::saveAssociations(FileAssociation *this)
{
  char *ApplicationPath; // eax
  char *v3; // edx
  char v4; // cl
  char *v5; // eax
  char v6; // cl
  _iobuf *v7; // ebx
  int v8; // edi
  int *p_association; // esi
  char v10; // [esp+7h] [ebp-101h] BYREF
  char path[256]; // [esp+8h] [ebp-100h] BYREF

  ApplicationPath = (char *)mx::getApplicationPath();
  v3 = (char *)(path - ApplicationPath);
  do
  {
    v4 = *ApplicationPath;
    ApplicationPath[(_DWORD)v3] = *ApplicationPath;
    ++ApplicationPath;
  }
  while ( v4 != 0 );
  v5 = &v10;
  do
    v6 = *++v5;
  while ( v6 != 0 );
  strcpy(v5, "/hlmv.fa");
  v7 = fopen(file: path, mode: "wt");
  if ( v7 != nullptr )
  {
    v8 = 0;
    p_association = &this->d_associations[0].association;
    do
    {
      if ( *p_association == -1 )
        break;
      fprintf(
        str: v7,
        format: "\"%s\" \"%s\" %d\n",
        (const char *)p_association - 272,
        (const char *)p_association - 256,
        *p_association);
      ++v8;
      p_association += 69;
    }
    while ( v8 < 16 );
    fclose(stream: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004107C0
// Name: public: virtual int FileAssociation::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall FileAssociation::handleEvent(FileAssociation *this, mxEvent *event)
{
  int result; // eax
  int SelectedIndex; // eax
  bool isChecked; // al
  bool v6; // al
  int v7; // eax
  int v8; // edi
  char *Label; // eax
  char *v10; // edx
  char v11; // cl
  const char *OpenFileName; // eax
  int v13; // edi
  char *v14; // eax
  char *v15; // edx
  char v16; // cl

  if ( event->event != 0 )
    return 0;
  switch ( event->action )
  {
    case 0x3E9:
      SelectedIndex = mxChoice::getSelectedIndex(this: this->cExtension);
      if ( SelectedIndex < 0 )
        goto LABEL_19;
      FileAssociation::setAssociation(this, index: SelectedIndex);
      return 1;
    case 0x3EC:
    case 0x3ED:
    case 0x3EE:
    case 0x3EF:
      isChecked = mxRadioButton::isChecked(this: this->rbAction[0]);
      mxWidget::setEnabled(this: this->leProgram, b: isChecked);
      v6 = mxRadioButton::isChecked(this: this->rbAction[0]);
      mxWidget::setEnabled(this: this->bChooseProgram, b: v6);
      v7 = mxChoice::getSelectedIndex(this: this->cExtension);
      if ( v7 < 0 )
        goto LABEL_19;
      this->d_associations[v7].association = event->action - 1004;
      return 1;
    case 0x3F0:
      v8 = mxChoice::getSelectedIndex(this: this->cExtension);
      if ( v8 < 0 )
        goto LABEL_19;
      Label = (char *)mxWidget::getLabel(this: this->leProgram);
      v10 = (char *)(this->d_associations[v8].program - Label);
      do
      {
        v11 = *Label;
        Label[(_DWORD)v10] = *Label;
        ++Label;
      }
      while ( v11 != 0 );
      return 1;
    case 0x3F1:
      OpenFileName = mxGetOpenFileName(parent: this, path: nullptr, filter: "*.exe");
      if ( OpenFileName == nullptr )
        goto LABEL_19;
      mxWidget::setLabel(this: this->leProgram, format: OpenFileName);
      v13 = mxChoice::getSelectedIndex(this: this->cExtension);
      if ( v13 < 0 )
        goto LABEL_19;
      v14 = (char *)mxWidget::getLabel(this: this->leProgram);
      v15 = (char *)(this->d_associations[v13].program - v14);
      do
      {
        v16 = *v14;
        v14[(_DWORD)v15] = *v14;
        ++v14;
      }
      while ( v16 != 0 );
      return 1;
    case 0x3F2:
      FileAssociation::saveAssociations(this);
      goto $LN1_0;
    case 0x3F3:
$LN1_0:
      mxWidget::setVisible(this, b: false);
      goto LABEL_19;
    default:
LABEL_19:
      result = 1;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00410950
// Name: private: void FileAssociation::initAssociations(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FileAssociation::initAssociations(FileAssociation *this)
{
  mxChoice *cExtension; // ecx
  int *p_association; // edi
  int *v4; // eax
  int j; // ecx
  char *ApplicationPath; // eax
  char *v7; // edx
  char v8; // cl
  char *v9; // eax
  char v10; // cl
  _iobuf *v11; // esi
  int v12; // ebx
  int v13; // eax
  char *v14; // ecx
  char v15; // dl
  int v16; // ecx
  char *v17; // ecx
  int v18; // esi
  char v19; // dl
  int v20; // eax
  FileAssociation *v21; // edx
  char v22; // [esp+Bh] [ebp-20Dh] BYREF
  char path[256]; // [esp+Ch] [ebp-20Ch] BYREF
  char line[256]; // [esp+10Ch] [ebp-10Ch] BYREF
  _iobuf *file; // [esp+20Ch] [ebp-Ch]
  int i; // [esp+210h] [ebp-8h]
  FileAssociation *v27; // [esp+214h] [ebp-4h]

  cExtension = this->cExtension;
  v27 = this;
  mxChoice::removeAll(this: cExtension);
  p_association = &this->d_associations[0].association;
  v4 = &this->d_associations[0].association;
  for ( j = 16; j != 0; --j )
  {
    *v4 = -1;
    v4 += 69;
  }
  ApplicationPath = (char *)mx::getApplicationPath();
  v7 = (char *)(path - ApplicationPath);
  do
  {
    v8 = *ApplicationPath;
    ApplicationPath[(_DWORD)v7] = *ApplicationPath;
    ++ApplicationPath;
  }
  while ( v8 != 0 );
  v9 = &v22;
  do
    v10 = *++v9;
  while ( v10 != 0 );
  strcpy(v9, "/hlmv.fa");
  v11 = fopen(file: path, mode: "rt");
  file = v11;
  if ( v11 != nullptr )
  {
    i = 0;
    v12 = (char *)this - &line[1] + 40;
    do
    {
      if ( fgets(string: line, count: 256, str: v11) == nullptr )
        break;
      v13 = 0;
      do
        ++v13;
      while ( line[v13] != 34 );
      line[v13] = 0;
      v14 = &line[1];
      do
      {
        v15 = *v14;
        v14[v12] = *v14;
        ++v14;
      }
      while ( v15 != 0 );
      do
        ++v13;
      while ( line[v13] != 34 );
      v16 = v13 + 1;
      do
        ++v13;
      while ( line[v13] != 34 );
      v17 = &line[v16];
      line[v13] = 0;
      v18 = (char *)p_association - v17;
      do
      {
        v19 = *v17;
        v17[v18 - 256] = *v17;
        ++v17;
      }
      while ( v19 != 0 );
      v20 = atoi(nptr: &line[v13 + 1]);
      v21 = v27;
      *p_association = v20;
      mxChoice::add(this: v21->cExtension, item: (const char *)p_association - 272);
      v11 = file;
      p_association += 69;
      v12 += 276;
      ++i;
    }
    while ( i < 16 );
    fclose(stream: v11);
    FileAssociation::setAssociation(this: v27, index: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410B00
// Name: public: FileAssociation::FileAssociation(void)
// Source: json
//------------------------------------------------------------------------------
FileAssociation *__thiscall FileAssociation::FileAssociation(FileAssociation *this)
{
  mxChoice *v2; // eax
  mxChoice *v3; // eax
  mxGroupBox *v4; // eax
  mxRadioButton *v5; // eax
  mxRadioButton *v6; // eax
  mxRadioButton *v7; // eax
  mxRadioButton *v8; // eax
  mxRadioButton *v9; // eax
  mxRadioButton *v10; // eax
  mxRadioButton *v11; // eax
  mxRadioButton *v12; // eax
  mxLineEdit *v13; // eax
  mxLineEdit *v14; // eax
  mxButton *v15; // eax
  mxButton *v16; // eax
  mxButton *v17; // eax
  mxButton *v18; // eax

  mxWindow::mxWindow(this, parent: nullptr, x: 100, y: 100, w: 400, h: 210, label: "File Associations", style: 2);
  this->__vftable = (FileAssociation_vtbl *)&FileAssociation::`vftable';
  v2 = (mxChoice *)operator new(nSize: 0xCu);
  if ( v2 != nullptr )
    v3 = mxChoice::mxChoice(this: v2, parent: this, x: 5, y: 5, w: 220, h: 22, id: 1001);
  else
    v3 = nullptr;
  this->cExtension = v3;
  v4 = (mxGroupBox *)operator new(nSize: 0xCu);
  if ( v4 != nullptr )
    mxGroupBox::mxGroupBox(this: v4, parent: this, x: 5, y: 30, w: 380, h: 115, label: "Assocations");
  v5 = (mxRadioButton *)operator new(nSize: 0xCu);
  if ( v5 != nullptr )
    v6 = mxRadioButton::mxRadioButton(
           this: v5,
           parent: this,
           x: 10,
           y: 50,
           w: 120,
           h: 22,
           label: "program",
           id: 1004,
           newGroup: true);
  else
    v6 = nullptr;
  this->rbAction[0] = v6;
  v7 = (mxRadioButton *)operator new(nSize: 0xCu);
  if ( v7 != nullptr )
    v8 = mxRadioButton::mxRadioButton(
           this: v7,
           parent: this,
           x: 10,
           y: 72,
           w: 120,
           h: 22,
           label: "associated program",
           id: 1005,
           newGroup: false);
  else
    v8 = nullptr;
  this->rbAction[1] = v8;
  v9 = (mxRadioButton *)operator new(nSize: 0xCu);
  if ( v9 != nullptr )
    v10 = mxRadioButton::mxRadioButton(
            this: v9,
            parent: this,
            x: 10,
            y: 94,
            w: 120,
            h: 22,
            label: "HLMV default",
            id: 1006,
            newGroup: false);
  else
    v10 = nullptr;
  this->rbAction[2] = v10;
  v11 = (mxRadioButton *)operator new(nSize: 0xCu);
  if ( v11 != nullptr )
    v12 = mxRadioButton::mxRadioButton(
            this: v11,
            parent: this,
            x: 10,
            y: 116,
            w: 120,
            h: 22,
            label: "none",
            id: 1007,
            newGroup: false);
  else
    v12 = nullptr;
  this->rbAction[3] = v12;
  v13 = (mxLineEdit *)operator new(nSize: 0xCu);
  if ( v13 != nullptr )
    v14 = mxLineEdit::mxLineEdit(
            this: v13,
            parent: this,
            x: 130,
            y: 50,
            w: 220,
            h: 22,
            label: WindowName,
            id: 1008,
            style: 0);
  else
    v14 = nullptr;
  this->leProgram = v14;
  mxWidget::setEnabled(this: v14, b: false);
  v15 = (mxButton *)operator new(nSize: 0xCu);
  if ( v15 != nullptr )
    v16 = mxButton::mxButton(this: v15, parent: this, x: 352, y: 50, w: 22, h: 22, label: ">>", id: 1009);
  else
    v16 = nullptr;
  this->bChooseProgram = v16;
  mxWidget::setEnabled(this: v16, b: false);
  mxRadioButton::setChecked(this: this->rbAction[0], b: false);
  mxRadioButton::setChecked(this: this->rbAction[1], b: true);
  v17 = (mxButton *)operator new(nSize: 0xCu);
  if ( v17 != nullptr )
    mxButton::mxButton(this: v17, parent: this, x: 110, y: 155, w: 75, h: 22, label: "Ok", id: 1010);
  v18 = (mxButton *)operator new(nSize: 0xCu);
  if ( v18 != nullptr )
    mxButton::mxButton(this: v18, parent: this, x: 215, y: 155, w: 75, h: 22, label: "Cancel", id: 1011);
  FileAssociation::initAssociations(this);
  return this;
}
