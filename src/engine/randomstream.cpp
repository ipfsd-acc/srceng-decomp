// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/randomstream.cpp
// Functions: 3
// ============================================================

#include "engine\randomstream.h"

//------------------------------------------------------------------------------
// Address: 0x101CE430
// Name: public: virtual float CEngineUniformRandomStream::RandomFloat(float,float)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
double __thiscall CEngineUniformRandomStream::RandomFloat(
        CEngineUniformRandomStream *this,
        float flMinVal,
        float flMaxVal)
{
  return _RandomFloat(this, a2: flMinVal, a3: flMaxVal);
}

//------------------------------------------------------------------------------
// Address: 0x101CE450
// Name: public: virtual float CEngineUniformRandomStream::RandomFloatExp(float,float,float)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
double __thiscall CEngineUniformRandomStream::RandomFloatExp(
        CEngineUniformRandomStream *this,
        float flMinVal,
        float flMaxVal,
        float flExponent)
{
  return _RandomFloatExp(this, a2: flMinVal, a3: flMaxVal, a4: flExponent);
}

//------------------------------------------------------------------------------
// Address: 0x101CE480
// Name: public: virtual int CEngineUniformRandomStream::RandomInt(int,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __thiscall CEngineUniformRandomStream::RandomInt(
        CEngineUniformRandomStream *this,
        IUniformRandomStream *iMinVal,
        int iMaxVal)
{
  return _RandomInt(this: iMinVal, a2: (int)iMinVal, a3: iMaxVal);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101CE810
// Name: public: virtual float CEngineUniformRandomStream::RandomFloat(float,float)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
double __thiscall CEngineUniformRandomStream::RandomFloat(
        CEngineUniformRandomStream *this,
        float flMinVal,
        float flMaxVal)
{
  return _RandomFloat(this, a2: flMinVal, a3: flMaxVal);
}

//------------------------------------------------------------------------------
// Address: 0x101CE830
// Name: public: virtual float CEngineUniformRandomStream::RandomFloatExp(float,float,float)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
double __thiscall CEngineUniformRandomStream::RandomFloatExp(
        CEngineUniformRandomStream *this,
        float flMinVal,
        float flMaxVal,
        float flExponent)
{
  return _RandomFloatExp(this, a2: flMinVal, a3: flMaxVal, a4: flExponent);
}

//------------------------------------------------------------------------------
// Address: 0x101CE860
// Name: public: virtual int CEngineUniformRandomStream::RandomInt(int,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __thiscall CEngineUniformRandomStream::RandomInt(
        CEngineUniformRandomStream *this,
        IUniformRandomStream *iMinVal,
        int iMaxVal)
{
  return _RandomInt(this: iMinVal, a2: (int)iMinVal, a3: iMaxVal);
}

} // namespace engine_xlsp
