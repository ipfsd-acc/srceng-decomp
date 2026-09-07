// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/physics_motioncontroller.cpp
// Functions: 26
// ============================================================

#include "vphysics\physics_motioncontroller.h"

//------------------------------------------------------------------------------
// Address: 0x100185C0
// Name: public: virtual char const __near * CPhysicsMotionController::get_controller_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPhysicsMotionController::get_controller_name(CPhysicsMotionController *this)
{
  return "vphysics:motion";
}

//------------------------------------------------------------------------------
// Address: 0x100185D0
// Name: public: virtual enum IVP_CONTROLLER_PRIORITY CPhysicsMotionController::get_controller_priority(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsMotionController::get_controller_priority(CPhysicsMotionController *this)
{
  return this->m_priority;
}

//------------------------------------------------------------------------------
// Address: 0x100185E0
// Name: public: virtual void CPhysicsMotionController::SetPriority(enum IPhysicsMotionController::priority_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsMotionController::SetPriority(
        CPhysicsMotionController *this,
        IPhysicsMotionController::priority_t priority)
{
  if ( priority != LOW_PRIORITY )
  {
    if ( priority == HIGH_PRIORITY )
      this->m_pVEnv = (CPhysicsEnvironment *)1601;
    else
      this->m_pVEnv = (CPhysicsEnvironment *)500;
  }
  else
  {
    this->m_pVEnv = (CPhysicsEnvironment *)400;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018620
// Name: public: virtual void CPredictedPhysicsMotionController::SetCallOrderRegistrar(class CPredictableControllerSimulationOrderTracker __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPhysicsMotionController::SetCallOrderRegistrar(
        CPredictedPhysicsMotionController *this,
        CPredictableControllerSimulationOrderTracker *pRegistrar)
{
  this->m_pCallOrderRegistrar = pRegistrar;
}

//------------------------------------------------------------------------------
// Address: 0x10018660
// Name: public: virtual void CPhysicsMotionController::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsMotionController::do_simulation_controller(
        CPhysicsMotionController *this@<ecx>,
        float a2@<ebp>,
        IVP_Event_Sim *event,
        IVP_U_Vector<IVP_Core> *core_list)
{
  bool v4; // zf
  float *v5; // esi
  int v6; // edi
  int (__stdcall ***v7)(int, int, _DWORD, float *, Vector *); // ecx
  IVP_Event_Sim *v8; // eax
  float v9; // xmm1_4
  float v10; // xmm5_4
  float delta_time; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm2_4
  int n_elems; // edx
  float factor; // [esp+14h] [ebp-60h]
  float factora; // [esp+14h] [ebp-60h]
  float v25; // [esp+28h] [ebp-4Ch] BYREF
  float v26; // [esp+2Ch] [ebp-48h]
  float v27; // [esp+30h] [ebp-44h]
  IVP_U_Float_Point ivpRot; // [esp+34h] [ebp-40h] BYREF
  IVP_U_Float_Point ivpSpeed; // [esp+44h] [ebp-30h] BYREF
  Vector speed; // [esp+54h] [ebp-20h] BYREF
  Vector rot; // [esp+60h] [ebp-14h]
  void *v32; // [esp+6Ch] [ebp-8h]
  void *retaddr; // [esp+74h] [ebp+0h]

  rot.z = a2;
  v32 = retaddr;
  v4 = this->m_handler == nullptr;
  LODWORD(rot.x) = this;
  if ( !v4 )
  {
    rot.y = 0.0;
    if ( core_list->n_elems != 0 )
    {
      do
      {
        v5 = (float *)core_list->elems[LODWORD(rot.y)];
        v6 = *(_DWORD *)(**((_DWORD **)v5 + 21) + 160);
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 40))(a1: v6) != 0 )
        {
          v7 = *(int (__stdcall ****)(int, int, _DWORD, float *, Vector *))(LODWORD(rot.x) + 8);
          memset(&ivpSpeed.k[1], 0, 12);
          memset(&speed, 0, sizeof(speed));
          switch ( (**v7)(
                     a1: LODWORD(rot.x) + 4,
                     a2: v6,
                     a3: LODWORD(event->delta_time),
                     a4: &ivpSpeed.k[1],
                     a5: &speed) )
          {
            case 1:
              v25 = speed.x * 0.017453292;
              v27 = speed.y * 0.017453292;
              LODWORD(ivpRot.k[2]) = COERCE_UNSIGNED_INT(ivpSpeed.hesse_val * g_PhysicsUnits.unitScaleMeters)
                                   ^ _mask__NegFloat_;
              LODWORD(v26) = COERCE_UNSIGNED_INT(speed.z * 0.017453292) ^ _mask__NegFloat_;
              v8 = event;
              ivpRot.k[1] = g_PhysicsUnits.unitScaleMeters * ivpSpeed.k[1];
              ivpRot.hesse_val = ivpSpeed.k[2] * g_PhysicsUnits.unitScaleMeters;
              v9 = (float)((float)(v5[33] * ivpRot.k[2])
                         + (float)(v5[32] * (float)(g_PhysicsUnits.unitScaleMeters * ivpSpeed.k[1])))
                 + (float)(v5[34] * (float)(ivpSpeed.k[2] * g_PhysicsUnits.unitScaleMeters));
              v10 = (float)((float)(v5[25] * ivpRot.k[2])
                          + (float)(v5[24] * (float)(g_PhysicsUnits.unitScaleMeters * ivpSpeed.k[1])))
                  + (float)(v5[26] * (float)(ivpSpeed.k[2] * g_PhysicsUnits.unitScaleMeters));
              delta_time = event->delta_time;
              ivpRot.k[2] = (float)((float)(v5[29] * ivpRot.k[2])
                                  + (float)(v5[28] * (float)(g_PhysicsUnits.unitScaleMeters * ivpSpeed.k[1])))
                          + (float)(v5[30] * (float)(ivpSpeed.k[2] * g_PhysicsUnits.unitScaleMeters));
              ivpRot.hesse_val = v9;
              v12 = ivpRot.k[2] * delta_time;
              v13 = v9 * delta_time;
              ivpRot.k[1] = v10;
              v14 = delta_time * v10;
              goto LABEL_6;
            case 2:
              v25 = speed.x * 0.017453292;
              LODWORD(v26) = COERCE_UNSIGNED_INT(speed.z * 0.017453292) ^ _mask__NegFloat_;
              v27 = speed.y * 0.017453292;
              LODWORD(ivpRot.k[2]) = COERCE_UNSIGNED_INT(ivpSpeed.hesse_val * g_PhysicsUnits.unitScaleMeters)
                                   ^ _mask__NegFloat_;
              ivpRot.k[1] = g_PhysicsUnits.unitScaleMeters * ivpSpeed.k[1];
              ivpRot.hesse_val = ivpSpeed.k[2] * g_PhysicsUnits.unitScaleMeters;
              v19 = (float)((float)(v5[29] * ivpRot.k[2])
                          + (float)(v5[28] * (float)(g_PhysicsUnits.unitScaleMeters * ivpSpeed.k[1])))
                  + (float)(v5[30] * (float)(ivpSpeed.k[2] * g_PhysicsUnits.unitScaleMeters));
              v20 = (float)((float)(v5[33] * ivpRot.k[2])
                          + (float)(v5[32] * (float)(g_PhysicsUnits.unitScaleMeters * ivpSpeed.k[1])))
                  + (float)(v5[34] * (float)(ivpSpeed.k[2] * g_PhysicsUnits.unitScaleMeters));
              factor = event->delta_time;
              ivpRot.k[1] = (float)((float)(v5[25] * ivpRot.k[2])
                                  + (float)(v5[24] * (float)(g_PhysicsUnits.unitScaleMeters * ivpSpeed.k[1])))
                          + (float)(v5[26] * (float)(ivpSpeed.k[2] * g_PhysicsUnits.unitScaleMeters));
              ivpRot.k[2] = v19;
              ivpRot.hesse_val = v20;
              IVP_Core::center_push_core_multiple_ws(
                this: (IVP_Core *)v5,
                delta_speed: (IVP_U_Float_Point *)&ivpRot.k[1],
                factor);
              IVP_Core::rot_push_core_multiple_cs(
                this: (IVP_Core *)v5,
                normized_core_axis: (const IVP_U_Float_Point *)&v25,
                rot_impulse: event->delta_time);
              break;
            case 3:
              v8 = event;
              LODWORD(v26) = COERCE_UNSIGNED_INT(speed.z * 0.017453292) ^ _mask__NegFloat_;
              v27 = speed.y * 0.017453292;
              v25 = speed.x * 0.017453292;
              v21 = event->delta_time;
              LODWORD(ivpRot.k[2]) = COERCE_UNSIGNED_INT(ivpSpeed.hesse_val * g_PhysicsUnits.unitScaleMeters)
                                   ^ _mask__NegFloat_;
              ivpRot.hesse_val = ivpSpeed.k[2] * g_PhysicsUnits.unitScaleMeters;
              v12 = ivpRot.k[2] * v21;
              v13 = (float)(ivpSpeed.k[2] * g_PhysicsUnits.unitScaleMeters) * v21;
              ivpRot.k[1] = g_PhysicsUnits.unitScaleMeters * ivpSpeed.k[1];
              v14 = v21 * (float)(g_PhysicsUnits.unitScaleMeters * ivpSpeed.k[1]);
LABEL_6:
              v15 = v13 + v5[54];
              v16 = v12 + v5[53];
              v5[52] = v14 + v5[52];
              v5[53] = v16;
              v5[54] = v15;
              v17 = (float)(v26 * v8->delta_time) + v5[49];
              v18 = (float)(v27 * v8->delta_time) + v5[50];
              v5[48] = (float)(v8->delta_time * v25) + v5[48];
              v5[49] = v17;
              v5[50] = v18;
              break;
            case 4:
              LODWORD(v26) = COERCE_UNSIGNED_INT(speed.z * 0.017453292) ^ _mask__NegFloat_;
              v27 = speed.y * 0.017453292;
              ivpRot.k[1] = g_PhysicsUnits.unitScaleMeters * ivpSpeed.k[1];
              v25 = speed.x * 0.017453292;
              factora = event->delta_time;
              LODWORD(ivpRot.k[2]) = COERCE_UNSIGNED_INT(ivpSpeed.hesse_val * g_PhysicsUnits.unitScaleMeters)
                                   ^ _mask__NegFloat_;
              ivpRot.hesse_val = ivpSpeed.k[2] * g_PhysicsUnits.unitScaleMeters;
              IVP_Core::center_push_core_multiple_ws(
                this: (IVP_Core *)v5,
                delta_speed: (IVP_U_Float_Point *)&ivpRot.k[1],
                factor: factora);
              IVP_Core::rot_push_core_multiple_cs(
                this: (IVP_Core *)v5,
                normized_core_axis: (const IVP_U_Float_Point *)&v25,
                rot_impulse: event->delta_time);
              break;
            default:
              break;
          }
          IVP_Core::apply_velocity_limit(this: (IVP_Core *)v5);
        }
        n_elems = core_list->n_elems;
        ++LODWORD(rot.y);
      }
      while ( SLODWORD(rot.y) < n_elems );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018B30
// Name: public: virtual void CPhysicsMotionController::GetObjects(class IPhysicsObject __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsMotionController::GetObjects(CPhysicsMotionController *this, IPhysicsObject **pObjectList)
{
  int i; // eax

  for ( i = 0; i < this->m_coreList.m_Memory.m_nGrowSize; ++i )
    pObjectList[i] = *(IPhysicsObject **)(*(_DWORD *)this->m_handler[i].__vftable[21].Simulate + 160);
}

//------------------------------------------------------------------------------
// Address: 0x10018B60
// Name: public: virtual void CPhysicsMotionController::WakeObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsMotionController::WakeObjects(CPhysicsMotionController *this)
{
  int i; // esi

  for ( i = 0; i < this->m_coreList.m_Memory.m_nGrowSize; ++i )
    IVP_Core::ensure_core_to_be_in_simulation(this: (IVP_Core *)this->m_handler[i].__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x10018B90
// Name: public: virtual void CPredictedPhysicsMotionController::Prediction_Resimulate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPhysicsMotionController::Prediction_Resimulate(
        CPredictedPhysicsMotionController *this,
        float fSimulationTime)
{
  CPredictedPhysicsMotionController::PredictionCommandOffsets_t *m_pReferencedBackup; // eax
  int iStartOffset; // esi
  CPredictedPhysicsObject **m_pMemory; // eax
  IMotionEvent *m_handler; // ecx
  CPredictedPhysicsObject *v7; // edi
  Vector speed; // [esp+18h] [ebp-1Ch] BYREF
  Vector rot; // [esp+24h] [ebp-10h] BYREF
  int iStop; // [esp+30h] [ebp-4h]

  if ( this->m_handler != nullptr )
  {
    m_pReferencedBackup = this->m_pReferencedBackup;
    iStartOffset = m_pReferencedBackup->iStartOffset;
    for ( iStop = iStartOffset + m_pReferencedBackup->iEntryCount; iStartOffset < iStop; ++iStartOffset )
    {
      m_pMemory = this->m_PredictionObjectBackupSets.m_Memory.m_pMemory;
      m_handler = this->m_handler;
      memset(&speed, 0, sizeof(speed));
      memset(&rot, 0, sizeof(rot));
      v7 = m_pMemory[iStartOffset];
      if ( ((int (__stdcall *)(IPhysicsMotionController *, CPredictedPhysicsObject *, _DWORD, Vector *, Vector *))m_handler->Simulate)(
             a1: &this->IPhysicsMotionController,
             a2: v7,
             a3: LODWORD(fSimulationTime),
             a4: &speed,
             a5: &rot) == 3 )
      {
        speed.x = speed.x * fSimulationTime;
        speed.y = speed.y * fSimulationTime;
        speed.z = speed.z * fSimulationTime;
        rot.x = rot.x * fSimulationTime;
        rot.y = rot.y * fSimulationTime;
        rot.z = rot.z * fSimulationTime;
        v7->AddVelocity(this: v7, a2: &speed, a3: &rot);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018C90
// Name: public: virtual void CPhysicsMotionController::core_is_going_to_be_deleted_event(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsMotionController::core_is_going_to_be_deleted_event(
        CPhysicsMotionController *this,
        IVP_Core *core)
{
  CUtlVector<IPhysicsPlayerController *,CUtlMemory<IPhysicsPlayerController *,int>>::FindAndRemove(
    this: (CUtlVector<IPhysicsEnvironment *,CUtlMemory<IPhysicsEnvironment *,int> > *)&this->m_coreList,
    src: (IPhysicsEnvironment **)&core);
}

//------------------------------------------------------------------------------
// Address: 0x10018CB0
// Name: public: void CPhysicsMotionController::RemoveCore(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsMotionController::RemoveCore(CPhysicsMotionController *this, IVP_Core *pCore)
{
  int m_Size; // edx
  int v4; // eax
  IVP_Core **i; // ecx

  m_Size = this->m_coreList.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    for ( i = this->m_coreList.m_Memory.m_pMemory; *i != pCore; ++i )
    {
      if ( ++v4 >= m_Size )
        return;
    }
    if ( v4 >= 0 && v4 < m_Size )
    {
      if ( m_Size - v4 - 1 > 0 )
        _V_memmove(
          dest: &this->m_coreList.m_Memory.m_pMemory[v4],
          src: &this->m_coreList.m_Memory.m_pMemory[v4 + 1],
          count: 4 * (m_Size - v4 - 1));
      --this->m_coreList.m_Size;
      IVP_Core::rem_core_controller(this: pCore, rem_cntrl: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018D20
// Name: public: virtual void CPhysicsMotionController::DetachObject(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsMotionController::DetachObject(CPhysicsMotionController *this, IPhysicsObject *pObject)
{
  CPhysicsMotionController::RemoveCore(
    this: (CPhysicsMotionController *)((char *)this - 4),
    pCore: (IVP_Core *)pObject[2].SetBuoyancyRatio);
}

//------------------------------------------------------------------------------
// Address: 0x10018D40
// Name: public: void CPredictedPhysicsMotionController::DoneReferencingPreviousCommands(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPhysicsMotionController::DoneReferencingPreviousCommands(
        CPredictedPhysicsMotionController *this,
        int iCommandNum)
{
  int v3; // edi
  CPredictedPhysicsMotionController::PredictionCommandOffsets_t *m_pMemory; // edx
  CPredictedPhysicsMotionController::PredictionCommandOffsets_t *i; // eax
  unsigned int v6; // ecx
  CPredictedPhysicsMotionController::PredictionCommandOffsets_t *m_pReferencedBackup; // eax
  int v8; // ebx
  int v9; // edx
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int iReferenceBackupOffset; // [esp+10h] [ebp+8h]

  v3 = 0;
  if ( this->m_PredictionBackups.m_Size != 0 )
  {
    m_pMemory = this->m_PredictionBackups.m_Memory.m_pMemory;
    for ( i = m_pMemory; i->iCommandNum < iCommandNum; ++i )
    {
      if ( ++v3 == this->m_PredictionBackups.m_Size )
        return;
    }
    if ( v3 > 0 )
    {
      v6 = v3;
      if ( m_pMemory[v3 - 1].iCommandNum != -1 )
      {
        m_pReferencedBackup = this->m_pReferencedBackup;
        v8 = m_pMemory[v6].iStartOffset + m_pMemory[v6].iEntryCount;
        if ( m_pReferencedBackup != nullptr )
        {
          v9 = (char *)m_pReferencedBackup - (char *)m_pMemory - v6 * 12;
          v10 = this->m_PredictionBackups.m_Size - v3;
          iReferenceBackupOffset = v9;
          if ( v10 > 0 )
          {
            _V_memmove(
              dest: this->m_PredictionBackups.m_Memory.m_pMemory,
              src: &this->m_PredictionBackups.m_Memory.m_pMemory[v6],
              count: 12 * v10);
            v9 = iReferenceBackupOffset;
          }
          this->m_PredictionBackups.m_Size -= v3;
          if ( v9 < 0 )
            this->m_pReferencedBackup = nullptr;
          else
            this->m_pReferencedBackup = (CPredictedPhysicsMotionController::PredictionCommandOffsets_t *)((char *)this->m_PredictionBackups.m_Memory.m_pMemory + v9);
        }
        else
        {
          if ( this->m_PredictionBackups.m_Size - v3 > 0 )
            _V_memmove(dest: m_pMemory, src: &m_pMemory[v6], count: 12 * (this->m_PredictionBackups.m_Size - v3));
          this->m_PredictionBackups.m_Size -= v3;
        }
        if ( v8 != 0 )
        {
          if ( this->m_PredictionObjectBackupSets.m_Size - v8 > 0 && v8 > 0 )
            _V_memmove(
              dest: this->m_PredictionObjectBackupSets.m_Memory.m_pMemory,
              src: &this->m_PredictionObjectBackupSets.m_Memory.m_pMemory[v8],
              count: 4 * (this->m_PredictionObjectBackupSets.m_Size - v8));
          this->m_PredictionObjectBackupSets.m_Size -= v8;
          v11 = 0;
          if ( this->m_PredictionBackups.m_Size != 0 )
          {
            v12 = 0;
            do
            {
              this->m_PredictionBackups.m_Memory.m_pMemory[v12].iStartOffset -= v8;
              ++v11;
              ++v12;
            }
            while ( v11 != this->m_PredictionBackups.m_Size );
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018F60
// Name: public: virtual CPhysicsMotionController::~CPhysicsMotionController(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsMotionController::~CPhysicsMotionController(CPhysicsMotionController *this)
{
  int v2; // edi
  IVP_Core **m_pMemory; // eax

  v2 = 0;
  this->IPredictable_Controller_Independant::IVP_Controller_Independent::IVP_Controller::__vftable = (CPhysicsMotionController_vtbl *)&CPhysicsMotionController::`vftable'{for `IPredictable_Controller_Independant'};
  for ( this->IPhysicsMotionController::__vftable = (IPhysicsMotionController_vtbl *)&CPhysicsMotionController::`vftable'{for `IPhysicsMotionController'};
        v2 < this->m_coreList.m_Size;
        ++v2 )
  {
    IVP_Core::rem_core_controller(this: this->m_coreList.m_Memory.m_pMemory[v2], rem_cntrl: this);
  }
  this->m_coreList.m_Size = 0;
  if ( this->m_coreList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_coreList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_coreList.m_Memory.m_pMemory);
      this->m_coreList.m_Memory.m_pMemory = nullptr;
    }
    this->m_coreList.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_coreList.m_Memory.m_pMemory;
  this->m_coreList.m_pElements = m_pMemory;
  if ( this->m_coreList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_coreList.m_Memory.m_pMemory = nullptr;
    }
    this->m_coreList.m_Memory.m_nAllocationCount = 0;
  }
  this->IPredictable_Controller_Independant::IVP_Controller_Independent::IVP_Controller::__vftable = (CPhysicsMotionController_vtbl *)&IVP_Controller_Dependent::`vftable';
  this->IPhysicsMotionController::__vftable = (IPhysicsMotionController_vtbl *)&IPhysicsMotionController::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10018FF0
// Name: public: virtual void CPhysicsMotionController::ClearObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsMotionController::ClearObjects(CPhysicsMotionController *this)
{
  int m_nGrowSize; // eax
  char *v3; // esi
  IVP_Core *v4; // edi
  int v5; // ecx
  int v6; // eax
  IVP_Core **v7; // edx
  int v8; // ecx

  m_nGrowSize = this->m_coreList.m_Memory.m_nGrowSize;
  if ( m_nGrowSize != 0 )
  {
    v3 = (char *)this - 4;
    do
    {
      v4 = (IVP_Core *)this->m_handler[m_nGrowSize - 1].__vftable;
      v5 = *((_DWORD *)v3 + 6);
      v6 = 0;
      if ( v5 > 0 )
      {
        v7 = *((IVP_Core ***)v3 + 3);
        while ( *v7 != v4 )
        {
          ++v6;
          ++v7;
          if ( v6 >= v5 )
            goto LABEL_13;
        }
        if ( v6 >= 0 && v6 < v5 )
        {
          v8 = v5 - v6 - 1;
          if ( v8 > 0 )
            _V_memmove(
              dest: (void *)(*((_DWORD *)v3 + 3) + 4 * v6),
              src: (const void *)(*((_DWORD *)v3 + 3) + 4 * v6 + 4),
              count: 4 * v8);
          --*((_DWORD *)v3 + 6);
          IVP_Core::rem_core_controller(this: v4, rem_cntrl: (CPhysicsMotionController *)((char *)this - 4));
        }
      }
LABEL_13:
      m_nGrowSize = this->m_coreList.m_Memory.m_nGrowSize;
    }
    while ( m_nGrowSize != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019060
// Name: public: CPredictedPhysicsMotionController::CPredictedPhysicsMotionController(class IMotionEvent __near *,class CPhysicsEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
CPredictedPhysicsMotionController *__thiscall CPredictedPhysicsMotionController::CPredictedPhysicsMotionController(
        CPredictedPhysicsMotionController *this,
        IMotionEvent *pHandler,
        CPhysicsEnvironment *pVEnv)
{
  this->CPhysicsMotionController::IPhysicsMotionController::__vftable = (IPhysicsMotionController_vtbl *)&IPhysicsMotionController::`vftable';
  this->m_coreList.m_Memory.m_pMemory = nullptr;
  this->m_coreList.m_Memory.m_nAllocationCount = 0;
  this->m_coreList.m_Memory.m_nGrowSize = 0;
  this->m_coreList.m_Size = 0;
  this->m_coreList.m_pElements = nullptr;
  this->m_handler = pHandler;
  this->m_pVEnv = pVEnv;
  this->m_priority = 500;
  this->CPhysicsMotionController::IPredictable_Controller_Independant::IVP_Controller_Independent::IVP_Controller::__vftable = (CPredictedPhysicsMotionController_vtbl *)&CPredictedPhysicsMotionController::`vftable'{for `IPredictable_Controller_Independant'};
  this->CPhysicsMotionController::IPhysicsMotionController::__vftable = (IPhysicsMotionController_vtbl *)&CPredictedPhysicsMotionController::`vftable'{for `IPhysicsMotionController'};
  this->m_PredictionObjectBackupSets.m_Memory.m_pMemory = nullptr;
  this->m_PredictionObjectBackupSets.m_Memory.m_nAllocationCount = 0;
  this->m_PredictionObjectBackupSets.m_Memory.m_nGrowSize = 0;
  this->m_PredictionObjectBackupSets.m_Size = 0;
  this->m_PredictionObjectBackupSets.m_pElements = nullptr;
  this->m_PredictionBackups.m_Memory.m_pMemory = nullptr;
  this->m_PredictionBackups.m_Memory.m_nAllocationCount = 0;
  this->m_PredictionBackups.m_Memory.m_nGrowSize = 0;
  this->m_PredictionBackups.m_Size = 0;
  this->m_PredictionBackups.m_pElements = nullptr;
  this->m_pCallOrderRegistrar = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100190E0
// Name: class IPhysicsMotionController __near * CreateMotionController(class CPhysicsEnvironment __near *,class IMotionEvent __near *,bool)
// Source: json
//------------------------------------------------------------------------------
IPhysicsMotionController *__cdecl CreateMotionController(
        CPhysicsEnvironment *pPhysEnv,
        IMotionEvent *pHandler,
        bool bPredicted)
{
  CPredictedPhysicsMotionController *v3; // eax
  CPredictedPhysicsMotionController *v4; // eax

  if ( pHandler == nullptr )
    return nullptr;
  if ( bPredicted )
  {
    v3 = (CPredictedPhysicsMotionController *)p_malloc(size: 0x58u);
    if ( v3 == nullptr )
      return nullptr;
    v4 = CPredictedPhysicsMotionController::CPredictedPhysicsMotionController(this: v3, pHandler, pVEnv: pPhysEnv);
  }
  else
  {
    v4 = (CPredictedPhysicsMotionController *)p_malloc(size: 0x28u);
    if ( v4 == nullptr )
      return nullptr;
    v4->CPhysicsMotionController::IPhysicsMotionController::__vftable = (IPhysicsMotionController_vtbl *)&IPhysicsMotionController::`vftable';
    v4->CPhysicsMotionController::IPredictable_Controller_Independant::IVP_Controller_Independent::IVP_Controller::__vftable = (CPredictedPhysicsMotionController_vtbl *)&CPhysicsMotionController::`vftable'{for `IPredictable_Controller_Independant'};
    v4->CPhysicsMotionController::IPhysicsMotionController::__vftable = (IPhysicsMotionController_vtbl *)&CPhysicsMotionController::`vftable'{for `IPhysicsMotionController'};
    v4->m_coreList.m_Memory.m_pMemory = nullptr;
    v4->m_coreList.m_Memory.m_nAllocationCount = 0;
    v4->m_coreList.m_Memory.m_nGrowSize = 0;
    v4->m_coreList.m_Size = 0;
    v4->m_coreList.m_pElements = nullptr;
    v4->m_handler = pHandler;
    v4->m_pVEnv = pPhysEnv;
    v4->m_priority = 500;
  }
  if ( v4 != nullptr )
    return &v4->IPhysicsMotionController;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10019170
// Name: bool RestorePhysicsMotionController(struct physrestoreparams_t const __near &,class IPhysicsMotionController __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RestorePhysicsMotionController(
        CPhysicsMotionController *params,
        IPhysicsMotionController **ppMotionController)
{
  IPhysicsMotionController *v2; // eax
  int v4; // esi
  IPhysicsEnvironment *m_Size; // edx
  IPhysicsMotionController *v6; // edi
  IRestore *v7; // ecx
  int v8; // ebx
  vphysics_save_motioncontroller_t controllerTemplate; // [esp+Ch] [ebp-18h] BYREF
  CPhysicsMotionController *pControllerImp; // [esp+2Ch] [ebp+8h]

  v2 = (IPhysicsMotionController *)p_malloc(size: 0x28u);
  v4 = 0;
  if ( v2 != nullptr )
  {
    m_Size = (IPhysicsEnvironment *)params->m_coreList.m_Size;
    v2[1].__vftable = (IPhysicsMotionController_vtbl *)&IPhysicsMotionController::`vftable';
    v2->__vftable = (IPhysicsMotionController_vtbl *)&CPhysicsMotionController::`vftable'{for `IPredictable_Controller_Independant'};
    v2[1].__vftable = (IPhysicsMotionController_vtbl *)&CPhysicsMotionController::`vftable'{for `IPhysicsMotionController'};
    v2[3].__vftable = nullptr;
    v2[4].__vftable = nullptr;
    v2[5].__vftable = nullptr;
    v2[6].__vftable = nullptr;
    v2[7].__vftable = nullptr;
    v6 = v2;
    v2[2].__vftable = nullptr;
    v2[8].__vftable = (IPhysicsMotionController_vtbl *)m_Size;
    v2[9].__vftable = (IPhysicsMotionController_vtbl *)500;
    pControllerImp = (CPhysicsMotionController *)v2;
  }
  else
  {
    pControllerImp = nullptr;
    v6 = nullptr;
  }
  v7 = (IRestore *)params->IPredictable_Controller_Independant::IVP_Controller_Independent::IVP_Controller::__vftable;
  memset(&controllerTemplate, 0, sizeof(controllerTemplate));
  v7->ReadAll(this: v7, a2: &controllerTemplate, a3: &vphysics_save_motioncontroller_t::m_DataMap);
  v6[9].__vftable = (IPhysicsMotionController_vtbl *)controllerTemplate.m_nPriority;
  v8 = controllerTemplate.m_objectList.m_Size;
  if ( controllerTemplate.m_objectList.m_Size > 0 )
  {
    do
      v6[1].AttachObject(this: v6 + 1, a2: controllerTemplate.m_objectList.m_Memory.m_pMemory[v4++], a3: true);
    while ( v4 < v8 );
    v6 = (IPhysicsMotionController *)pControllerImp;
  }
  *ppMotionController = v6 + 1;
  CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::~CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&controllerTemplate);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10019270
// Name: public: virtual void CPhysicsMotionController::AttachObject(class IPhysicsObject __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsMotionController::AttachObject(
        CPhysicsMotionController *this,
        IVP_Core *pObject,
        bool checkIfAlreadyAttached)
{
  int m_nGrowSize; // edx
  int v5; // eax
  IMotionEvent *m_handler; // ecx
  IVP_Core **m_pMemory; // eax
  int v8; // edi
  IMotionEvent *v9; // ecx
  int v10; // eax
  IMotionEvent *v11; // eax
  IVP_Core *pCore; // [esp+10h] [ebp+8h]

  if ( pObject != nullptr
    && (*(unsigned __int8 (__thiscall **)(IVP_Core *))(*(_DWORD *)&pObject->IVP_Core_Fast_Static + 4))(a1: pObject) == 0 )
  {
    pCore = *(IVP_Core **)(LODWORD(pObject->max_surface_deviation) + 148);
    if ( !checkIfAlreadyAttached )
      goto LABEL_8;
    m_nGrowSize = this->m_coreList.m_Memory.m_nGrowSize;
    v5 = 0;
    if ( m_nGrowSize <= 0 )
      goto LABEL_8;
    m_handler = this->m_handler;
    while ( (IVP_Core *)m_handler->__vftable != pCore )
    {
      ++v5;
      ++m_handler;
      if ( v5 >= m_nGrowSize )
        goto LABEL_8;
    }
    if ( v5 >= 0 && v5 < m_nGrowSize )
    {
      _DevMsg(a1: 1, a2: "Attached core twice!!!\n");
    }
    else
    {
LABEL_8:
      m_pMemory = this->m_coreList.m_Memory.m_pMemory;
      v8 = this->m_coreList.m_Memory.m_nGrowSize;
      if ( v8 + 1 > (int)m_pMemory )
        CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_handler,
          num: v8 - (_DWORD)m_pMemory + 1);
      ++this->m_coreList.m_Memory.m_nGrowSize;
      v9 = this->m_handler;
      v10 = this->m_coreList.m_Memory.m_nGrowSize - v8 - 1;
      this->m_coreList.m_Size = (int)v9;
      if ( v10 > 0 )
        _V_memmove(dest: &v9[v8 + 1], src: &v9[v8], count: 4 * v10);
      v11 = &this->m_handler[v8];
      if ( v11 != nullptr )
        v11->__vftable = (IMotionEvent_vtbl *)pCore;
      IVP_Core::add_core_controller(this: pCore, add_cntrl: (CPhysicsMotionController *)((char *)this - 4));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019390
// Name: public: void CPredictedPhysicsMotionController::OnPredictionCommandChanged(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPhysicsMotionController::OnPredictionCommandChanged(
        CPredictedPhysicsMotionController *this,
        int iCommandNum,
        bool bBackup)
{
  int v4; // eax
  CPredictedPhysicsMotionController::PredictionCommandOffsets_t *i; // ecx
  int m_Size; // [esp-8h] [ebp-18h]
  CPredictedPhysicsMotionController::PredictionCommandOffsets_t temp; // [esp+4h] [ebp-Ch] BYREF

  if ( bBackup )
  {
    temp.iStartOffset = this->m_PredictionObjectBackupSets.m_Size;
    temp.iCommandNum = iCommandNum;
    m_Size = this->m_PredictionBackups.m_Size;
    temp.iEntryCount = 0;
    CUtlVector<CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t,CUtlMemory<CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t,int>>::InsertBefore(
      this: (CUtlVector<CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t,CUtlMemory<CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t,int> > *)&this->m_PredictionBackups,
      elem: m_Size,
      src: (const CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t *)&temp);
    this->m_pReferencedBackup = nullptr;
  }
  else
  {
    v4 = this->m_PredictionBackups.m_Size - 1;
    if ( v4 >= 0 )
    {
      for ( i = &this->m_PredictionBackups.m_Memory.m_pMemory[v4]; i->iCommandNum > iCommandNum; --i )
      {
        if ( --v4 < 0 )
          return;
      }
      this->m_pReferencedBackup = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019400
// Name: public: virtual void CPredictedPhysicsMotionController::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPhysicsMotionController::do_simulation_controller(
        CPredictedPhysicsMotionController *this,
        IVP_Event_Sim *event,
        IVP_U_Vector<IVP_Core> *core_list)
{
  CPredictedPhysicsMotionController *v3; // esi
  IVP_U_Vector<IVP_Core> *v4; // edi
  CPredictedPhysicsObject *v5; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CPredictedPhysicsObject **m_pMemory; // ecx
  int v9; // eax
  IPhysicsObject **v10; // edi
  int j; // edi
  IPhysicsObject *pPhys; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  CPredictedPhysicsMotionController::PredictionCommandOffsets_t *pCurrentCommandSet; // [esp+1Ch] [ebp-4h]
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  v3 = this;
  if ( this->m_handler != nullptr )
  {
    v4 = core_list;
    if ( core_list->n_elems != 0 )
    {
      CPredictableControllerSimulationOrderTracker::RegisterSimulation(
        this: this->m_pCallOrderRegistrar,
        pController: this);
      pCurrentCommandSet = &v3->m_PredictionBackups.m_Memory.m_pMemory[v3->m_PredictionBackups.m_Size - 1];
      i = 0;
      if ( core_list->n_elems != 0 )
      {
        do
        {
          v5 = *(CPredictedPhysicsObject **)(**((_DWORD **)v4->elems[i] + 21) + 160);
          pPhys = v5;
          if ( v5->IsMoveable(this: v5) )
          {
            CPredictedPhysicsObject::PreAnyController(
              this: v5,
              a2: (int)v5,
              fSimulationTime: event->delta_time,
              bBackup: true);
            m_Size = v3->m_PredictionObjectBackupSets.m_Size;
            m_nAllocationCount = v3->m_PredictionObjectBackupSets.m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v3->m_PredictionObjectBackupSets,
                num: m_Size - m_nAllocationCount + 1);
            ++v3->m_PredictionObjectBackupSets.m_Size;
            m_pMemory = v3->m_PredictionObjectBackupSets.m_Memory.m_pMemory;
            v9 = v3->m_PredictionObjectBackupSets.m_Size - m_Size - 1;
            v3->m_PredictionObjectBackupSets.m_pElements = m_pMemory;
            if ( v9 > 0 )
              _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
            v10 = &v3->m_PredictionObjectBackupSets.m_Memory.m_pMemory[m_Size];
            if ( v10 != nullptr )
              *v10 = pPhys;
            ++pCurrentCommandSet->iEntryCount;
            v3 = this;
          }
          ++i;
          v4 = core_list;
        }
        while ( i < core_list->n_elems );
      }
      CPhysicsMotionController::do_simulation_controller(this: v3, a2: COERCE_FLOAT(&savedregs), event, core_list: v4);
      for ( j = 0; j < pCurrentCommandSet->iEntryCount; ++j )
        CPredictedPhysicsObject::PostAnyController(
          this: *(&v3->m_PredictionObjectBackupSets.m_Memory.m_pMemory[j] + pCurrentCommandSet->iStartOffset),
          a2: j,
          a3: (int)v3,
          fSimulationTime: event->delta_time,
          bBackup: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019550
// Name: bool SavePhysicsMotionController(struct physsaveparams_t const __near &,class IPhysicsMotionController __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SavePhysicsMotionController(const physsaveparams_t *params, IPhysicsMotionController *pMotionController)
{
  IPhysicsMotionController *v2; // eax
  int v3; // ecx
  IPhysicsMotionController *v4; // esi
  int (__thiscall *CountObjects)(IPhysicsMotionController *); // eax
  int v6; // eax
  vphysics_save_motioncontroller_t controllerTemplate; // [esp+0h] [ebp-18h] BYREF

  memset(&controllerTemplate, 0, sizeof(controllerTemplate));
  if ( pMotionController != nullptr )
    v2 = pMotionController - 1;
  else
    v2 = nullptr;
  v3 = (int)v2[9].__vftable;
  v4 = v2 + 1;
  CountObjects = v2[1].CountObjects;
  controllerTemplate.m_nPriority = v3;
  v6 = CountObjects(this: v4);
  CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::InsertMultipleBefore(
    this: (CUtlVector<int,CUtlMemory<int,int> > *)&controllerTemplate,
    elem: controllerTemplate.m_objectList.m_Size,
    num: v6);
  v4->GetObjects(this: v4, a2: controllerTemplate.m_objectList.m_Memory.m_pMemory);
  params->pSave->WriteAll(
    this: params->pSave,
    a2: &controllerTemplate,
    a3: &vphysics_save_motioncontroller_t::m_DataMap);
  CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::~CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&controllerTemplate);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100938B0
// Name: public: virtual void CPhysicsMotionController::SetEventHandler(class IMotionEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsMotionController::SetEventHandler(IVP_Template_Constraint *this, IVP_Real_Object *objR)
{
  this->objectR = objR;
}

//------------------------------------------------------------------------------
// Address: 0x100AEC20
// Name: public: void CUtlMemory<struct CPredictedPhysicsMotionController::PredictionCommandOffsets_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CPredictedPhysicsMotionController::PredictionCommandOffsets_t,int>::Grow(
        CUtlMemory<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 3;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::ListElem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6AA0
// Name: vphysics_save_motioncontroller_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vphysics_save_motioncontroller_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vphysics_save_motioncontroller_t>(__formal: nullptr);
  vphysics_save_motioncontroller_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100195D0
// Name: struct datamap_t __near * DataMapInit<struct vphysics_save_motioncontroller_t>(struct vphysics_save_motioncontroller_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vphysics_save_motioncontroller_t>()
{
  if ( (_S1_1 & 1) == 0 )
  {
    _S1_1 |= 1u;
    nameHolder_12.m_pszBase = "vphysics_save_motioncontroller_t";
    nameHolder_12.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_12.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_12.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_12.m_Names.m_Size = 0;
    nameHolder_12.m_Names.m_pElements = nullptr;
    nameHolder_12.m_nLenBase = 32;
    atexit(func: DataMapInit_vphysics_save_motioncontroller_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vphysics_save_motioncontroller_t::m_DataMap.baseMap = nullptr;
  vphysics_save_motioncontroller_t::m_DataMap.dataNumFields = 2;
  vphysics_save_motioncontroller_t::m_DataMap.dataDesc = &dataDesc_12[1];
  return &vphysics_save_motioncontroller_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100C6AB0
// Name: _dynamic_initializer_for__g_PostRestoreObjectList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PostRestoreObjectList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_PostRestoreObjectList__);
}
