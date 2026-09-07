// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/func_instance_io_proxy.cpp
// Functions: 35
// ============================================================

#include "game\server\func_instance_io_proxy.h"

//------------------------------------------------------------------------------
// Address: 0x10138AA0
// Name: public: virtual struct datamap_t __near * CFuncInstanceIoProxy::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncInstanceIoProxy::GetDataDescMap(CFuncInstanceIoProxy *this)
{
  return &CFuncInstanceIoProxy::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10138AB0
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay1(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay1(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay1,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138AE0
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay2(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay2(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay2,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138B10
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay3(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay3(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay3,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138B40
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay4(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay4(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay4,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138B70
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay5(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay5(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay5,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138BA0
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay6(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay6(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay6,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138BD0
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay7(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay7(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay7,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138C00
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay8(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay8(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay8,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138C30
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay9(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay9(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay9,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138C60
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay10(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay10(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay10,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138C90
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay11(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay11(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay11,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138CC0
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay12(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay12(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay12,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138CF0
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay13(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay13(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay13,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138D20
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay14(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay14(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay14,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138D50
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay15(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay15(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay15,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138D80
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay16(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay16(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay16,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138DB0
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay17(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay17(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay17,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138DE0
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay18(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay18(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay18,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138E10
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay19(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay19(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay19,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138E40
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay20(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay20(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay20,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138E70
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay21(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay21(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay21,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138EA0
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay22(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay22(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay22,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138ED0
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay23(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay23(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay23,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138F00
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay24(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay24(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay24,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138F30
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay25(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay25(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay25,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138F60
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay26(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay26(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay26,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138F90
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay27(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay27(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay27,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138FC0
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay28(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay28(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay28,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10138FF0
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay29(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay29(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay29,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10139020
// Name: public: void CFuncInstanceIoProxy::InputProxyRelay30(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::InputProxyRelay30(CFuncInstanceIoProxy *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(
    this: &this->m_OnProxyRelay30,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    fDelay: 0.0);
  DevWarning(a1: "Maximun Proxy Messages used - ask a programmer for more.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10139070
// Name: public: CFuncInstanceIoProxy::CFuncInstanceIoProxy(void)
// Source: json
//------------------------------------------------------------------------------
CFuncInstanceIoProxy *__thiscall CFuncInstanceIoProxy::CFuncInstanceIoProxy(CFuncInstanceIoProxy *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CFuncInstanceIoProxy_vtbl *)&CFuncInstanceIoProxy::`vftable';
  this->m_OnProxyRelay1.m_Value.iVal = 0;
  this->m_OnProxyRelay1.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay1.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay2.m_Value.iVal = 0;
  this->m_OnProxyRelay2.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay2.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay3.m_Value.iVal = 0;
  this->m_OnProxyRelay3.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay3.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay4.m_Value.iVal = 0;
  this->m_OnProxyRelay4.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay4.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay5.m_Value.iVal = 0;
  this->m_OnProxyRelay5.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay5.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay6.m_Value.iVal = 0;
  this->m_OnProxyRelay6.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay6.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay7.m_Value.iVal = 0;
  this->m_OnProxyRelay7.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay7.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay8.m_Value.iVal = 0;
  this->m_OnProxyRelay8.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay8.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay9.m_Value.iVal = 0;
  this->m_OnProxyRelay9.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay9.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay10.m_Value.iVal = 0;
  this->m_OnProxyRelay10.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay10.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay11.m_Value.iVal = 0;
  this->m_OnProxyRelay11.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay11.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay12.m_Value.iVal = 0;
  this->m_OnProxyRelay12.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay12.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay13.m_Value.iVal = 0;
  this->m_OnProxyRelay13.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay13.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay14.m_Value.iVal = 0;
  this->m_OnProxyRelay14.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay14.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay15.m_Value.iVal = 0;
  this->m_OnProxyRelay15.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay15.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay16.m_Value.iVal = 0;
  this->m_OnProxyRelay16.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay16.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay17.m_Value.iVal = 0;
  this->m_OnProxyRelay17.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay17.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay18.m_Value.iVal = 0;
  this->m_OnProxyRelay18.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay18.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay19.m_Value.iVal = 0;
  this->m_OnProxyRelay19.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay19.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay20.m_Value.iVal = 0;
  this->m_OnProxyRelay20.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay20.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay21.m_Value.iVal = 0;
  this->m_OnProxyRelay21.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay21.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay22.m_Value.iVal = 0;
  this->m_OnProxyRelay22.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay22.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay23.m_Value.iVal = 0;
  this->m_OnProxyRelay23.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay23.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay24.m_Value.iVal = 0;
  this->m_OnProxyRelay24.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay24.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay25.m_Value.iVal = 0;
  this->m_OnProxyRelay25.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay25.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay26.m_Value.iVal = 0;
  this->m_OnProxyRelay26.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay26.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay27.m_Value.iVal = 0;
  this->m_OnProxyRelay27.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay27.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay28.m_Value.iVal = 0;
  this->m_OnProxyRelay28.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay28.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay29.m_Value.iVal = 0;
  this->m_OnProxyRelay29.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay29.m_Value.fieldType = FIELD_VOID;
  this->m_OnProxyRelay30.m_Value.iVal = 0;
  this->m_OnProxyRelay30.m_Value.eVal.m_Index = -1;
  this->m_OnProxyRelay30.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101392B0
// Name: public: virtual CFuncInstanceIoProxy::~CFuncInstanceIoProxy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncInstanceIoProxy::~CFuncInstanceIoProxy(CFuncInstanceIoProxy *this)
{
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay30);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay29);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay28);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay27);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay26);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay25);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay24);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay23);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay22);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay21);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay20);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay19);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay18);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay17);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay16);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay15);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay14);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay13);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay12);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay11);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay10);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay9);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay8);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay7);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay6);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay5);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay4);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay3);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay2);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnProxyRelay1);
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10403DF0
// Name: CFuncInstanceIoProxy_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncInstanceIoProxy_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncInstanceIoProxy>();
  CFuncInstanceIoProxy_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403E00
// Name: _dynamic_initializer_for__sv_showladders__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_showladders__()
{
  ConVar::ConVar(
    this: &sv_showladders,
    pName: "sv_showladders",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show bbox and dismount points for all ladders (must be set before level load.)\n");
  return atexit(func: dynamic_atexit_destructor_for__sv_showladders__);
}
