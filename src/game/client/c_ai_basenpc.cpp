// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_ai_basenpc.cpp
// Functions: 33
// ============================================================

#include "game\client\c_ai_basenpc.h"

//------------------------------------------------------------------------------
// Address: 0x100243B0
// Name: public: virtual class ClientClass __near * C_AI_BaseNPC::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_AI_BaseNPC::GetClientClass(C_AI_BaseNPC *this)
{
  return &__g_C_AI_BaseNPCClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10024550
// Name: bool NPC_IsImportantNPC(class C_BaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl NPC_IsImportantNPC(C_BaseAnimating *pAnimating)
{
  C_AI_BaseNPC *v1; // eax

  v1 = C_BaseEntity::MyNPCPointer(this: pAnimating);
  return v1 != nullptr && v1->m_bImportanRagdoll;
}

//------------------------------------------------------------------------------
// Address: 0x10024570
// Name: public: virtual bool C_AI_BaseNPC::AddRagdollToFadeQueue(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_AI_BaseNPC::AddRagdollToFadeQueue(C_AI_BaseNPC *this)
{
  return this->m_bFadeCorpse;
}

//------------------------------------------------------------------------------
// Address: 0x10024580
// Name: public: virtual unsigned int C_AI_BaseNPC::PhysicsSolidMaskForEntity(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_AI_BaseNPC::PhysicsSolidMaskForEntity(C_AI_BaseNPC *this)
{
  return C_BaseAnimating::IsRagdoll(this) ? 33570827 : 33701899;
}

//------------------------------------------------------------------------------
// Address: 0x100245A0
// Name: public: virtual void C_AI_BaseNPC::GetRagdollInitBoneArrays(class matrix3x4a_t __near *,class matrix3x4a_t __near *,class matrix3x4a_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_AI_BaseNPC::GetRagdollInitBoneArrays(
        C_AI_BaseNPC *this,
        matrix3x4a_t *pDeltaBones0,
        matrix3x4a_t *pDeltaBones1,
        matrix3x4a_t *pCurrentBones,
        float boneDt)
{
  float ragdollCreateTime; // [esp+24h] [ebp+14h]

  C_BaseAnimating::ForceSetupBonesAtTime(
    this,
    a2: (int)this,
    pBonesOut: pDeltaBones0,
    flTime: *(float *)(gpGlobals.m_Index + 12) - boneDt);
  GetRagdollCurSequenceWithDeathPose(
    entity: this,
    curBones: pDeltaBones1,
    flTime: *(float *)(gpGlobals.m_Index + 12),
    activity: this->m_iDeathPose,
    frame: this->m_iDeathFrame);
  ragdollCreateTime = PhysGetSyncCreateTime();
  if ( ragdollCreateTime == *(float *)(gpGlobals.m_Index + 12) )
    ((void (__stdcall *)(matrix3x4a_t *, int, int, _DWORD))this->SetupBones)(
      a1: pCurrentBones,
      a2: 256,
      a3: 524032,
      a4: *(_DWORD *)(gpGlobals.m_Index + 12));
  else
    C_BaseAnimating::ForceSetupBonesAtTime(this, a2: (int)this, pBonesOut: pCurrentBones, flTime: ragdollCreateTime);
}

//------------------------------------------------------------------------------
// Address: 0x100246F0
// Name: public: virtual void C_AI_BaseNPC::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_AI_BaseNPC::OnDataChanged(C_AI_BaseNPC *this, DataUpdateType_t type)
{
  C_BaseAnimating::OnDataChanged(this, updateType: type);
  if ( type == DATA_UPDATE_CREATED
    && (_V_stricmp(s1: (const char *)&this->m_hOwnerEntity, s2: "@glados") == 0
     || _V_stricmp(s1: (const char *)&this->m_hOwnerEntity, s2: "@actor_potatos") == 0) )
  {
    if ( this == (C_AI_BaseNPC *)8 )
      g_GLaDOSActor.m_Index = -1;
    else
      g_GLaDOSActor.m_Index = *(_DWORD *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 2) + 8))(a1: (char *)this - 8);
    *(_WORD *)(&this->m_mouth.sndcount + 1) = 1;
  }
  if ( HIBYTE(this->m_iSpeedModRadius) == 1 || *(float *)&this->m_bloodColor > *(float *)(gpGlobals.m_Index + 12) )
    (*(void (__stdcall **)(int))(*((_DWORD *)this - 2) + 456))(a1: -996040704);
}

//------------------------------------------------------------------------------
// Address: 0x10410310
// Name: DT_AI_BaseNPC::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_AI_BaseNPC::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_AI_BaseNPC::g_RecvTable);
  return atexit(func: DT_AI_BaseNPC::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10410330
// Name: DT_AI_BaseNPC::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_AI_BaseNPC::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_AI_BaseNPC::ignored>();
  DT_AI_BaseNPC::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042F9B0
// Name: DT_AI_BaseNPC::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_AI_BaseNPC::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_AI_BaseNPC::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10024650
// Name: _C_AI_BaseNPC_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_AI_BaseNPC_CreateObject(int entnum, int serialNum)
{
  C_BaseCombatCharacter *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseCombatCharacter *)C_BaseEntity::operator new(stAllocateBlock: 0x1250u);
  v3 = &v2->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseCombatCharacter::C_BaseCombatCharacter(this: v2);
  *v3 = &C_AI_BaseNPC::`vftable'{for `IClientUnknown'};
  v3[1] = &C_AI_BaseNPC::`vftable'{for `IClientRenderable'};
  v3[2] = &C_AI_BaseNPC::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_AI_BaseNPC::`vftable'{for `IClientThinkable'};
  v3[4] = &C_AI_BaseNPC::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10410340
// Name: _dynamic_initializer_for__cl_SetupAllBones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_SetupAllBones__()
{
  ConVar::ConVar(this: &cl_SetupAllBones, pName: "cl_SetupAllBones", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_SetupAllBones__);
}

//------------------------------------------------------------------------------
// Address: 0x10410370
// Name: _dynamic_initializer_for__r_sequence_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_sequence_debug__()
{
  ConVar::ConVar(this: &r_sequence_debug, pName: "r_sequence_debug", pDefaultValue: prType, flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_sequence_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x104103A0
// Name: _dynamic_initializer_for__r_debug_sequencesets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_debug_sequencesets__()
{
  ConVar::ConVar(this: &r_debug_sequencesets, pName: "r_debug_sequencesets", pDefaultValue: "-2", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_debug_sequencesets__);
}

//------------------------------------------------------------------------------
// Address: 0x104103D0
// Name: _dynamic_initializer_for__r_jiggle_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_jiggle_bones__()
{
  ConVar::ConVar(this: &r_jiggle_bones, pName: "r_jiggle_bones", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_jiggle_bones__);
}

//------------------------------------------------------------------------------
// Address: 0x10410400
// Name: _dynamic_initializer_for__RagdollImpactStrength__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__RagdollImpactStrength__()
{
  ConVar::ConVar(this: &RagdollImpactStrength, pName: "z_ragdoll_impact_strength", pDefaultValue: "500", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__RagdollImpactStrength__);
}

//------------------------------------------------------------------------------
// Address: 0x10410430
// Name: _dynamic_initializer_for__cl_disable_ragdolls__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_disable_ragdolls__()
{
  ConVar::ConVar(this: &cl_disable_ragdolls, pName: "cl_disable_ragdolls", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_disable_ragdolls__);
}

//------------------------------------------------------------------------------
// Address: 0x10410460
// Name: _dynamic_initializer_for__cl_ejectbrass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_ejectbrass__()
{
  ConVar::ConVar(this: &cl_ejectbrass, pName: "cl_ejectbrass", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_ejectbrass__);
}

//------------------------------------------------------------------------------
// Address: 0x10410490
// Name: _dynamic_initializer_for__cl_minimal_rtt_shadows__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_minimal_rtt_shadows__()
{
  ConVar::ConVar(this: &cl_minimal_rtt_shadows, pName: "cl_minimal_rtt_shadows", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__cl_minimal_rtt_shadows__);
}

//------------------------------------------------------------------------------
// Address: 0x104104C0
// Name: _dynamic_initializer_for__sfm_record_hz__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sfm_record_hz__()
{
  ConVar::ConVar(this: &sfm_record_hz, pName: "sfm_record_hz", pDefaultValue: "30", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sfm_record_hz__);
}

//------------------------------------------------------------------------------
// Address: 0x104104F0
// Name: _dynamic_initializer_for__vcollide_wireframe__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__vcollide_wireframe__()
{
  ConVar::ConVar(
    this: &vcollide_wireframe,
    pName: "vcollide_wireframe",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Render physics collision models in wireframe",
    callback: (void (__cdecl *)(IConVar *, const char *, float))VCollideWireframe_ChangeCallback);
  return atexit(func: dynamic_atexit_destructor_for__vcollide_wireframe__);
}

//------------------------------------------------------------------------------
// Address: 0x10410520
// Name: _dynamic_initializer_for__enable_skeleton_draw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__enable_skeleton_draw__()
{
  ConVar::ConVar(
    this: &enable_skeleton_draw,
    pName: "enable_skeleton_draw",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Render skeletons in wireframe");
  return atexit(func: dynamic_atexit_destructor_for__enable_skeleton_draw__);
}

//------------------------------------------------------------------------------
// Address: 0x10410550
// Name: _dynamic_initializer_for__g_ClientSideAnimationList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ClientSideAnimationList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ClientSideAnimationList__);
}

//------------------------------------------------------------------------------
// Address: 0x1042F9C0
// Name: _dynamic_atexit_destructor_for__cl_SetupAllBones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_SetupAllBones__()
{
  ConVar::~ConVar(this: &cl_SetupAllBones);
}

//------------------------------------------------------------------------------
// Address: 0x1042F9D0
// Name: _dynamic_atexit_destructor_for__r_sequence_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_sequence_debug__()
{
  ConVar::~ConVar(this: &r_sequence_debug);
}

//------------------------------------------------------------------------------
// Address: 0x1042F9E0
// Name: _dynamic_atexit_destructor_for__r_debug_sequencesets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_debug_sequencesets__()
{
  ConVar::~ConVar(this: &r_debug_sequencesets);
}

//------------------------------------------------------------------------------
// Address: 0x1042F9F0
// Name: _dynamic_atexit_destructor_for__r_jiggle_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_jiggle_bones__()
{
  ConVar::~ConVar(this: &r_jiggle_bones);
}

//------------------------------------------------------------------------------
// Address: 0x1042FA00
// Name: _dynamic_atexit_destructor_for__RagdollImpactStrength__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__RagdollImpactStrength__()
{
  ConVar::~ConVar(this: &RagdollImpactStrength);
}

//------------------------------------------------------------------------------
// Address: 0x1042FA10
// Name: _dynamic_atexit_destructor_for__cl_disable_ragdolls__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_disable_ragdolls__()
{
  ConVar::~ConVar(this: &cl_disable_ragdolls);
}

//------------------------------------------------------------------------------
// Address: 0x1042FA20
// Name: _dynamic_atexit_destructor_for__cl_ejectbrass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_ejectbrass__()
{
  ConVar::~ConVar(this: &cl_ejectbrass);
}

//------------------------------------------------------------------------------
// Address: 0x1042FA30
// Name: _dynamic_atexit_destructor_for__cl_minimal_rtt_shadows__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_minimal_rtt_shadows__()
{
  ConVar::~ConVar(this: &cl_minimal_rtt_shadows);
}

//------------------------------------------------------------------------------
// Address: 0x1042FA40
// Name: _dynamic_atexit_destructor_for__sfm_record_hz__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sfm_record_hz__()
{
  ConVar::~ConVar(this: &sfm_record_hz);
}

//------------------------------------------------------------------------------
// Address: 0x1042FA50
// Name: _dynamic_atexit_destructor_for__vcollide_wireframe__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vcollide_wireframe__()
{
  ConVar::~ConVar(this: &vcollide_wireframe);
}

//------------------------------------------------------------------------------
// Address: 0x1042FA60
// Name: _dynamic_atexit_destructor_for__enable_skeleton_draw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__enable_skeleton_draw__()
{
  ConVar::~ConVar(this: &enable_skeleton_draw);
}
