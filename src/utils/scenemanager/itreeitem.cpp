// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/itreeitem.cpp
// Functions: 2
// ============================================================

#include "utils\scenemanager\itreeitem.h"

//------------------------------------------------------------------------------
// Address: 0x00408430
// Name: public: void __near * __near * ITreeItem::FindItem(class mxTreeView __near *,void __near * __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void **__thiscall ITreeItem::FindItem(ITreeItem *this, mxTreeView *tree, void **parent, bool recurse)
{
  void **result; // eax
  void **i; // esi
  ITreeItem *UserData; // eax

  if ( tree == nullptr )
    return nullptr;
  for ( i = mxTreeView::getFirstChild(this: tree, item: parent);
        i != nullptr;
        i = mxTreeView::getNextChild(this: tree, item: i) )
  {
    UserData = (ITreeItem *)mxTreeView::getUserData(this: tree, item: i);
    if ( UserData != nullptr )
    {
      if ( UserData == this )
        return i;
      if ( recurse )
      {
        result = ITreeItem::FindItem(this, tree, parent: i, recurse);
        if ( result != nullptr )
          return result;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004084A0
// Name: public: class ITreeItem __near * ITreeItem::GetParentItem(void)
// Source: json
//------------------------------------------------------------------------------
CVCDFile *__thiscall ITreeItem::GetParentItem(ITreeItem *this)
{
  bool v2; // zf
  ITreeItem_vtbl *v3; // eax
  CSoundEntry *v4; // eax
  ITreeItem_vtbl *v6; // eax
  CVCDFile *v7; // eax
  ITreeItem_vtbl *v8; // eax
  CScene *v9; // eax
  ITreeItem_vtbl *v10; // eax
  CProject *v11; // eax
  CWaveFile *v12; // eax

  v2 = this->GetSoundEntry(this) == nullptr;
  v3 = this->__vftable;
  if ( v2 )
  {
    v2 = v3->GetVCDFile(this) == nullptr;
    v6 = this->__vftable;
    if ( v2 )
    {
      v2 = v6->GetScene(this) == nullptr;
      v8 = this->__vftable;
      if ( v2 )
      {
        v2 = v8->GetProject(this) == nullptr;
        v10 = this->__vftable;
        if ( v2 )
        {
          if ( v10->GetWaveFile(this) != nullptr )
          {
            v12 = this->GetWaveFile(this);
            return (CVCDFile *)CWaveFile::GetOwnerSoundEntry(this: v12);
          }
          else
          {
            return nullptr;
          }
        }
        else
        {
          v11 = v10->GetProject(this);
          return (CVCDFile *)CProject::GetOwnerWorkspace(this: v11);
        }
      }
      else
      {
        v9 = v8->GetScene(this);
        return (CVCDFile *)CScene::GetOwnerProject(this: v9);
      }
    }
    else
    {
      v7 = v6->GetVCDFile(this);
      return (CVCDFile *)CVCDFile::GetOwnerScene(this: v7);
    }
  }
  else
  {
    v4 = v3->GetSoundEntry(this);
    return CSoundEntry::GetOwnerVCDFile(this: v4);
  }
}
