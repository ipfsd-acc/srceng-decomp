// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/choreowidget.cpp
// Functions: 16
// ============================================================

#include "utils\hlfaceposer\choreowidget.h"

//------------------------------------------------------------------------------
// Address: 0x004688A0
// Name: public: virtual void CChoreoWidget::LocalToScreen(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidget::LocalToScreen(CPhonemeModeTab *this, int mx, int my)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00481A20
// Name: public: virtual class CChoreoWidget __near * CChoreoWidget::getParent(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoWidget::getParent(CTabWindow *this)
{
  return this->m_Items.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00491D70
// Name: public: static void __near * CChoreoWidget::operator new(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl CChoreoWidget::operator new(unsigned int stAllocateBlock)
{
  ++widgets;
  return calloc(count: 1u, size: stAllocateBlock);
}

//------------------------------------------------------------------------------
// Address: 0x00491D90
// Name: public: static void CChoreoWidget::operator delete(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CChoreoWidget::operator delete(void *pMem)
{
  unsigned int v1; // eax

  --widgets;
  v1 = _msize(pMem);
  memset(dst: (unsigned __int8 *)pMem, value: 0xFEu, count: v1);
  free(pMem);
}

//------------------------------------------------------------------------------
// Address: 0x00491DC0
// Name: public: CChoreoWidget::CChoreoWidget(class CChoreoWidget __near *)
// Source: json
//------------------------------------------------------------------------------
CChoreoWidget *__thiscall CChoreoWidget::CChoreoWidget(CChoreoWidget *this, CChoreoWidget *parent)
{
  this->__vftable = (CChoreoWidget_vtbl *)&CChoreoWidget::`vftable';
  this->m_pParent = parent;
  *(_WORD *)&this->m_bSelected = 256;
  this->m_rcBounds.bottom = 0;
  this->m_rcBounds.top = 0;
  this->m_rcBounds.right = 0;
  this->m_rcBounds.left = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00491DF0
// Name: public: virtual CChoreoWidget::~CChoreoWidget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidget::~CChoreoWidget(CChoreoWidget *this)
{
  this->__vftable = (CChoreoWidget_vtbl *)&CChoreoWidget::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00491E00
// Name: public: virtual int CChoreoWidget::GetItemHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoWidget::GetItemHeight(CChoreoWidget *this)
{
  return CChoreoView::GetRowHeight(this: CChoreoWidget::m_pView);
}

//------------------------------------------------------------------------------
// Address: 0x00491E10
// Name: public: virtual bool CChoreoWidget::IsSelected(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoWidget::IsSelected(CChoreoWidget *this)
{
  return this->m_bSelected;
}

//------------------------------------------------------------------------------
// Address: 0x00491E20
// Name: public: virtual void CChoreoWidget::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidget::SetSelected(CChoreoWidget *this, bool selected)
{
  this->m_bSelected = selected;
}

//------------------------------------------------------------------------------
// Address: 0x00491E30
// Name: public: virtual void CChoreoWidget::setBounds(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidget::setBounds(CChoreoWidget *this, int x, int y, int w, int h)
{
  this->m_rcBounds.left = x;
  this->m_rcBounds.right = w + x;
  this->m_rcBounds.top = y;
  this->m_rcBounds.bottom = h + y;
}

//------------------------------------------------------------------------------
// Address: 0x00491E50
// Name: public: virtual int CChoreoWidget::w(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoWidget::w(CChoreoWidget *this)
{
  return this->m_rcBounds.right - this->m_rcBounds.left;
}

//------------------------------------------------------------------------------
// Address: 0x00491E60
// Name: public: virtual int CChoreoWidget::h(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoWidget::h(CChoreoWidget *this)
{
  return this->m_rcBounds.bottom - this->m_rcBounds.top;
}

//------------------------------------------------------------------------------
// Address: 0x00491E70
// Name: public: virtual bool CChoreoWidget::getVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoWidget::getVisible(CChoreoWidget *this)
{
  return this->m_bVisible;
}

//------------------------------------------------------------------------------
// Address: 0x00491E80
// Name: public: virtual void CChoreoWidget::getBounds(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidget::getBounds(CChoreoWidget *this, tagRECT *bounds)
{
  *bounds = this->m_rcBounds;
}

//------------------------------------------------------------------------------
// Address: 0x00491EA0
// Name: public: virtual struct tagRECT __near & CChoreoWidget::getBounds(void)
// Source: json
//------------------------------------------------------------------------------
tagRECT *__thiscall CChoreoWidget::getBounds(CChoreoWidget *this)
{
  return &this->m_rcBounds;
}

//------------------------------------------------------------------------------
// Address: 0x004ACDB0
// Name: public: virtual void CChoreoWidget::setVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoWidget::setVisible(CChoreoEvent *this, CChoreoEvent::CLOSECAPTION type)
{
  this->m_ccType = type;
}
