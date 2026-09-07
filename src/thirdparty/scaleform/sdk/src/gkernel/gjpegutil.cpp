// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gjpegutil.cpp
// Functions: 3
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gjpegutil.h"

//------------------------------------------------------------------------------
// Address: 0x10183530
// Name: public: virtual GJPEGInput::~GJPEGInput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GJPEGInput::~GJPEGInput(_DWORD *this)
{
  *this = &GJPEGInput::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10183540
// Name: public: virtual GJPEGOutput::~GJPEGOutput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GJPEGOutput::~GJPEGOutput(LoggingContext_t *this)
{
  this->m_ChannelID = (int)&GJPEGOutput::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10183550
// Name: public: virtual GJPEGSystem::~GJPEGSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GJPEGSystem::~GJPEGSystem(LightDesc_t *this, const LightDesc_t *a2)
{
  this->m_Type = (LightType_t)&GJPEGSystem::`vftable';
  JUMPOUT(0x10064670);
}
