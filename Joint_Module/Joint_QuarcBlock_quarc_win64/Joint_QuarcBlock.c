/*
 * Joint_QuarcBlock.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Joint_QuarcBlock".
 *
 * Model version              : 1.240
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Tue Mar  3 14:52:17 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Joint_QuarcBlock.h"
#include "Joint_QuarcBlock_private.h"
#include "Joint_QuarcBlock_dt.h"

/* Block signals (default storage) */
B_Joint_QuarcBlock_T Joint_QuarcBlock_B;

/* Block states (default storage) */
DW_Joint_QuarcBlock_T Joint_QuarcBlock_DW;

/* Real-time model */
RT_MODEL_Joint_QuarcBlock_T Joint_QuarcBlock_M_;
RT_MODEL_Joint_QuarcBlock_T *const Joint_QuarcBlock_M = &Joint_QuarcBlock_M_;

/* Model output function */
void Joint_QuarcBlock_output(void)
{
  /* local block i/o variables */
  real_T rtb_MotorDir;
  real_T tmp;
  real_T rtb_SineWave[200];
  int32_T i;
  real_T tmp_0;

  /* S-Function (hil_read_encoder_block): '<S1>/HIL Read Encoder' */

  /* S-Function Block: Joint_QuarcBlock/Motor/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(Joint_QuarcBlock_DW.HILInitialize_Card,
      &Joint_QuarcBlock_P.HILReadEncoder_channels, 1,
      &Joint_QuarcBlock_DW.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Joint_QuarcBlock_M, _rt_error_message);
    } else {
      rtb_MotorDir = Joint_QuarcBlock_DW.HILReadEncoder_Buffer;
    }
  }

  /* Gain: '<S1>/Servo:  Counts to Rad' */
  Joint_QuarcBlock_B.ServoCountstoRad = Joint_QuarcBlock_P.ServoCountstoRad_Gain
    * rtb_MotorDir;

  /* S-Function (hil_read_analog_block): '<S1>/HIL Read Analog' */

  /* S-Function Block: Joint_QuarcBlock/Motor/HIL Read Analog (hil_read_analog_block) */
  {
    t_error result = hil_read_analog(Joint_QuarcBlock_DW.HILInitialize_Card,
      &Joint_QuarcBlock_P.HILReadAnalog_channels, 1,
      &Joint_QuarcBlock_DW.HILReadAnalog_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Joint_QuarcBlock_M, _rt_error_message);
    }

    rtb_MotorDir = Joint_QuarcBlock_DW.HILReadAnalog_Buffer;
  }

  /* Gain: '<S1>/Tach Dir' */
  Joint_QuarcBlock_B.TachDir = Joint_QuarcBlock_P.TachDir_Gain * rtb_MotorDir;

  /* S-Function (hil_read_encoder_block): '<S1>/HIL Read Encoder1' */

  /* S-Function Block: Joint_QuarcBlock/Motor/HIL Read Encoder1 (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(Joint_QuarcBlock_DW.HILInitialize_Card,
      &Joint_QuarcBlock_P.HILReadEncoder1_channels, 1,
      &Joint_QuarcBlock_DW.HILReadEncoder1_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Joint_QuarcBlock_M, _rt_error_message);
    } else {
      rtb_MotorDir = Joint_QuarcBlock_DW.HILReadEncoder1_Buffer;
    }
  }

  /* Gain: '<S1>/Servo:  Counts to Rad1' */
  Joint_QuarcBlock_B.ServoCountstoRad1 =
    Joint_QuarcBlock_P.ServoCountstoRad1_Gain * rtb_MotorDir;

  /* Sin: '<Root>/Sine Wave' */
  if (Joint_QuarcBlock_DW.systemEnable != 0) {
    tmp = 6.2831853071795862 / Joint_QuarcBlock_P.T;
    tmp_0 = Joint_QuarcBlock_M->Timing.t[1];
    for (i = 0; i < 200; i++) {
      Joint_QuarcBlock_DW.lastSin[i] = sin(tmp *
        Joint_QuarcBlock_ConstP.SineWave_rtw_collapsed_sub_expr[i] * tmp_0);
    }

    tmp = 6.2831853071795862 / Joint_QuarcBlock_P.T;
    for (i = 0; i < 200; i++) {
      Joint_QuarcBlock_DW.lastCos[i] = cos(tmp *
        Joint_QuarcBlock_ConstP.SineWave_rtw_collapsed_sub_expr[i] * tmp_0);
    }

    Joint_QuarcBlock_DW.systemEnable = 0;
  }

  tmp = Joint_QuarcBlock_P.A * 1.2;
  for (i = 0; i < 200; i++) {
    rtb_SineWave[i] = ((Joint_QuarcBlock_DW.lastSin[i] *
                        Joint_QuarcBlock_P.SineWave_PCos[i] +
                        Joint_QuarcBlock_DW.lastCos[i] *
                        Joint_QuarcBlock_P.SineWave_PSin[i]) *
                       Joint_QuarcBlock_P.SineWave_HCos[i] +
                       (Joint_QuarcBlock_DW.lastCos[i] *
                        Joint_QuarcBlock_P.SineWave_PCos[i] -
                        Joint_QuarcBlock_DW.lastSin[i] *
                        Joint_QuarcBlock_P.SineWave_PSin[i]) *
                       Joint_QuarcBlock_P.SineWave_Hsin[i]) * tmp +
      Joint_QuarcBlock_P.SineWave_Bias;
  }

  /* End of Sin: '<Root>/Sine Wave' */

  /* Sum: '<Root>/Sum of Elements' */
  tmp = -0.0;
  for (i = 0; i < 200; i++) {
    tmp += rtb_SineWave[i];
  }

  Joint_QuarcBlock_B.SumofElements = tmp;

  /* End of Sum: '<Root>/Sum of Elements' */

  /* Saturate: '<S1>/Saturation' */
  if (Joint_QuarcBlock_B.SumofElements > Joint_QuarcBlock_P.Saturation_UpperSat)
  {
    rtb_MotorDir = Joint_QuarcBlock_P.Saturation_UpperSat;
  } else if (Joint_QuarcBlock_B.SumofElements <
             Joint_QuarcBlock_P.Saturation_LowerSat) {
    rtb_MotorDir = Joint_QuarcBlock_P.Saturation_LowerSat;
  } else {
    rtb_MotorDir = Joint_QuarcBlock_B.SumofElements;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Gain: '<S1>/Motor Dir ' */
  rtb_MotorDir *= Joint_QuarcBlock_P.MotorDir_Gain;

  /* S-Function (hil_write_block): '<S1>/HIL Write' */

  /* S-Function Block: Joint_QuarcBlock/Motor/HIL Write (hil_write_block) */
  {
    t_error result;
    result = hil_write(Joint_QuarcBlock_DW.HILInitialize_Card,
                       &Joint_QuarcBlock_P.HILWrite_analog_channels, 1U,
                       NULL, 0U,
                       NULL, 0U,
                       NULL, 0U,
                       &rtb_MotorDir,
                       NULL,
                       NULL,
                       NULL
                       );
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Joint_QuarcBlock_M, _rt_error_message);
    }
  }

  /* Clock: '<Root>/Clock' */
  Joint_QuarcBlock_B.Clock = Joint_QuarcBlock_M->Timing.t[0];
}

/* Model update function */
void Joint_QuarcBlock_update(void)
{
  int32_T i;
  real_T HoldSine;

  /* Update for Sin: '<Root>/Sine Wave' */
  for (i = 0; i < 200; i++) {
    HoldSine = Joint_QuarcBlock_DW.lastSin[i];
    Joint_QuarcBlock_DW.lastSin[i] = Joint_QuarcBlock_DW.lastSin[i] *
      Joint_QuarcBlock_P.SineWave_HCos[i] + Joint_QuarcBlock_DW.lastCos[i] *
      Joint_QuarcBlock_P.SineWave_Hsin[i];
    Joint_QuarcBlock_DW.lastCos[i] = Joint_QuarcBlock_DW.lastCos[i] *
      Joint_QuarcBlock_P.SineWave_HCos[i] - HoldSine *
      Joint_QuarcBlock_P.SineWave_Hsin[i];
  }

  /* End of Update for Sin: '<Root>/Sine Wave' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Joint_QuarcBlock_M->Timing.clockTick0)) {
    ++Joint_QuarcBlock_M->Timing.clockTickH0;
  }

  Joint_QuarcBlock_M->Timing.t[0] = Joint_QuarcBlock_M->Timing.clockTick0 *
    Joint_QuarcBlock_M->Timing.stepSize0 +
    Joint_QuarcBlock_M->Timing.clockTickH0 *
    Joint_QuarcBlock_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Joint_QuarcBlock_M->Timing.clockTick1)) {
      ++Joint_QuarcBlock_M->Timing.clockTickH1;
    }

    Joint_QuarcBlock_M->Timing.t[1] = Joint_QuarcBlock_M->Timing.clockTick1 *
      Joint_QuarcBlock_M->Timing.stepSize1 +
      Joint_QuarcBlock_M->Timing.clockTickH1 *
      Joint_QuarcBlock_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void Joint_QuarcBlock_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: Joint_QuarcBlock/Motor/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &Joint_QuarcBlock_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Joint_QuarcBlock_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (Joint_QuarcBlock_DW.HILInitialize_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Joint_QuarcBlock_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Joint_QuarcBlock_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Joint_QuarcBlock_M, _rt_error_message);
      return;
    }

    if ((Joint_QuarcBlock_P.HILInitialize_AIPStart && !is_switching) ||
        (Joint_QuarcBlock_P.HILInitialize_AIPEnter && is_switching)) {
      Joint_QuarcBlock_DW.HILInitialize_AIMinimums[0] =
        (Joint_QuarcBlock_P.HILInitialize_AILow);
      Joint_QuarcBlock_DW.HILInitialize_AIMinimums[1] =
        (Joint_QuarcBlock_P.HILInitialize_AILow);
      Joint_QuarcBlock_DW.HILInitialize_AIMaximums[0] =
        Joint_QuarcBlock_P.HILInitialize_AIHigh;
      Joint_QuarcBlock_DW.HILInitialize_AIMaximums[1] =
        Joint_QuarcBlock_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (Joint_QuarcBlock_DW.HILInitialize_Card,
         Joint_QuarcBlock_P.HILInitialize_AIChannels, 2U,
         &Joint_QuarcBlock_DW.HILInitialize_AIMinimums[0],
         &Joint_QuarcBlock_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_QuarcBlock_M, _rt_error_message);
        return;
      }
    }

    if ((Joint_QuarcBlock_P.HILInitialize_AOPStart && !is_switching) ||
        (Joint_QuarcBlock_P.HILInitialize_AOPEnter && is_switching)) {
      Joint_QuarcBlock_DW.HILInitialize_AOMinimums[0] =
        (Joint_QuarcBlock_P.HILInitialize_AOLow);
      Joint_QuarcBlock_DW.HILInitialize_AOMinimums[1] =
        (Joint_QuarcBlock_P.HILInitialize_AOLow);
      Joint_QuarcBlock_DW.HILInitialize_AOMaximums[0] =
        Joint_QuarcBlock_P.HILInitialize_AOHigh;
      Joint_QuarcBlock_DW.HILInitialize_AOMaximums[1] =
        Joint_QuarcBlock_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (Joint_QuarcBlock_DW.HILInitialize_Card,
         Joint_QuarcBlock_P.HILInitialize_AOChannels, 2U,
         &Joint_QuarcBlock_DW.HILInitialize_AOMinimums[0],
         &Joint_QuarcBlock_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_QuarcBlock_M, _rt_error_message);
        return;
      }
    }

    if ((Joint_QuarcBlock_P.HILInitialize_AOStart && !is_switching) ||
        (Joint_QuarcBlock_P.HILInitialize_AOEnter && is_switching)) {
      Joint_QuarcBlock_DW.HILInitialize_AOVoltages[0] =
        Joint_QuarcBlock_P.HILInitialize_AOInitial;
      Joint_QuarcBlock_DW.HILInitialize_AOVoltages[1] =
        Joint_QuarcBlock_P.HILInitialize_AOInitial;
      result = hil_write_analog(Joint_QuarcBlock_DW.HILInitialize_Card,
        Joint_QuarcBlock_P.HILInitialize_AOChannels, 2U,
        &Joint_QuarcBlock_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_QuarcBlock_M, _rt_error_message);
        return;
      }
    }

    if (Joint_QuarcBlock_P.HILInitialize_AOReset) {
      Joint_QuarcBlock_DW.HILInitialize_AOVoltages[0] =
        Joint_QuarcBlock_P.HILInitialize_AOWatchdog;
      Joint_QuarcBlock_DW.HILInitialize_AOVoltages[1] =
        Joint_QuarcBlock_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (Joint_QuarcBlock_DW.HILInitialize_Card,
         Joint_QuarcBlock_P.HILInitialize_AOChannels, 2U,
         &Joint_QuarcBlock_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_QuarcBlock_M, _rt_error_message);
        return;
      }
    }

    if ((Joint_QuarcBlock_P.HILInitialize_EIPStart && !is_switching) ||
        (Joint_QuarcBlock_P.HILInitialize_EIPEnter && is_switching)) {
      Joint_QuarcBlock_DW.HILInitialize_QuadratureModes[0] =
        Joint_QuarcBlock_P.HILInitialize_EIQuadrature;
      Joint_QuarcBlock_DW.HILInitialize_QuadratureModes[1] =
        Joint_QuarcBlock_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (Joint_QuarcBlock_DW.HILInitialize_Card,
         Joint_QuarcBlock_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &Joint_QuarcBlock_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_QuarcBlock_M, _rt_error_message);
        return;
      }
    }

    if ((Joint_QuarcBlock_P.HILInitialize_EIStart && !is_switching) ||
        (Joint_QuarcBlock_P.HILInitialize_EIEnter && is_switching)) {
      Joint_QuarcBlock_DW.HILInitialize_InitialEICounts[0] =
        Joint_QuarcBlock_P.HILInitialize_EIInitial;
      Joint_QuarcBlock_DW.HILInitialize_InitialEICounts[1] =
        Joint_QuarcBlock_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Joint_QuarcBlock_DW.HILInitialize_Card,
        Joint_QuarcBlock_P.HILInitialize_EIChannels, 2U,
        &Joint_QuarcBlock_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_QuarcBlock_M, _rt_error_message);
        return;
      }
    }
  }

  /* Enable for Sin: '<Root>/Sine Wave' */
  Joint_QuarcBlock_DW.systemEnable = 1;
}

/* Model terminate function */
void Joint_QuarcBlock_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: Joint_QuarcBlock/Motor/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(Joint_QuarcBlock_DW.HILInitialize_Card);
    hil_monitor_stop_all(Joint_QuarcBlock_DW.HILInitialize_Card);
    is_switching = false;
    if ((Joint_QuarcBlock_P.HILInitialize_AOTerminate && !is_switching) ||
        (Joint_QuarcBlock_P.HILInitialize_AOExit && is_switching)) {
      Joint_QuarcBlock_DW.HILInitialize_AOVoltages[0] =
        Joint_QuarcBlock_P.HILInitialize_AOFinal;
      Joint_QuarcBlock_DW.HILInitialize_AOVoltages[1] =
        Joint_QuarcBlock_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(Joint_QuarcBlock_DW.HILInitialize_Card,
        Joint_QuarcBlock_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &Joint_QuarcBlock_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_QuarcBlock_M, _rt_error_message);
      }
    }

    hil_task_delete_all(Joint_QuarcBlock_DW.HILInitialize_Card);
    hil_monitor_delete_all(Joint_QuarcBlock_DW.HILInitialize_Card);
    hil_close(Joint_QuarcBlock_DW.HILInitialize_Card);
    Joint_QuarcBlock_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Joint_QuarcBlock_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Joint_QuarcBlock_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Joint_QuarcBlock_initialize();
}

void MdlTerminate(void)
{
  Joint_QuarcBlock_terminate();
}

/* Registration function */
RT_MODEL_Joint_QuarcBlock_T *Joint_QuarcBlock(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Joint_QuarcBlock_M, 0,
                sizeof(RT_MODEL_Joint_QuarcBlock_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Joint_QuarcBlock_M->solverInfo,
                          &Joint_QuarcBlock_M->Timing.simTimeStep);
    rtsiSetTPtr(&Joint_QuarcBlock_M->solverInfo, &rtmGetTPtr(Joint_QuarcBlock_M));
    rtsiSetStepSizePtr(&Joint_QuarcBlock_M->solverInfo,
                       &Joint_QuarcBlock_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Joint_QuarcBlock_M->solverInfo, (&rtmGetErrorStatus
      (Joint_QuarcBlock_M)));
    rtsiSetRTModelPtr(&Joint_QuarcBlock_M->solverInfo, Joint_QuarcBlock_M);
  }

  rtsiSetSimTimeStep(&Joint_QuarcBlock_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Joint_QuarcBlock_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Joint_QuarcBlock_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Joint_QuarcBlock_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Joint_QuarcBlock_M->Timing.sampleTimes =
      (&Joint_QuarcBlock_M->Timing.sampleTimesArray[0]);
    Joint_QuarcBlock_M->Timing.offsetTimes =
      (&Joint_QuarcBlock_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Joint_QuarcBlock_M->Timing.sampleTimes[0] = (0.0);
    Joint_QuarcBlock_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    Joint_QuarcBlock_M->Timing.offsetTimes[0] = (0.0);
    Joint_QuarcBlock_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Joint_QuarcBlock_M, &Joint_QuarcBlock_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Joint_QuarcBlock_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Joint_QuarcBlock_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Joint_QuarcBlock_M, 39.998);
  Joint_QuarcBlock_M->Timing.stepSize0 = 0.002;
  Joint_QuarcBlock_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  Joint_QuarcBlock_M->Sizes.checksums[0] = (902688086U);
  Joint_QuarcBlock_M->Sizes.checksums[1] = (1242474280U);
  Joint_QuarcBlock_M->Sizes.checksums[2] = (4200520688U);
  Joint_QuarcBlock_M->Sizes.checksums[3] = (3005918593U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Joint_QuarcBlock_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Joint_QuarcBlock_M->extModeInfo,
      &Joint_QuarcBlock_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Joint_QuarcBlock_M->extModeInfo,
                        Joint_QuarcBlock_M->Sizes.checksums);
    rteiSetTPtr(Joint_QuarcBlock_M->extModeInfo, rtmGetTPtr(Joint_QuarcBlock_M));
  }

  Joint_QuarcBlock_M->solverInfoPtr = (&Joint_QuarcBlock_M->solverInfo);
  Joint_QuarcBlock_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&Joint_QuarcBlock_M->solverInfo, 0.002);
  rtsiSetSolverMode(&Joint_QuarcBlock_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Joint_QuarcBlock_M->blockIO = ((void *) &Joint_QuarcBlock_B);

  {
    Joint_QuarcBlock_B.ServoCountstoRad = 0.0;
    Joint_QuarcBlock_B.TachDir = 0.0;
    Joint_QuarcBlock_B.ServoCountstoRad1 = 0.0;
    Joint_QuarcBlock_B.SumofElements = 0.0;
    Joint_QuarcBlock_B.Clock = 0.0;
  }

  /* parameters */
  Joint_QuarcBlock_M->defaultParam = ((real_T *)&Joint_QuarcBlock_P);

  /* states (dwork) */
  Joint_QuarcBlock_M->dwork = ((void *) &Joint_QuarcBlock_DW);
  (void) memset((void *)&Joint_QuarcBlock_DW, 0,
                sizeof(DW_Joint_QuarcBlock_T));
  Joint_QuarcBlock_DW.HILInitialize_AIMinimums[0] = 0.0;
  Joint_QuarcBlock_DW.HILInitialize_AIMinimums[1] = 0.0;
  Joint_QuarcBlock_DW.HILInitialize_AIMaximums[0] = 0.0;
  Joint_QuarcBlock_DW.HILInitialize_AIMaximums[1] = 0.0;
  Joint_QuarcBlock_DW.HILInitialize_AOMinimums[0] = 0.0;
  Joint_QuarcBlock_DW.HILInitialize_AOMinimums[1] = 0.0;
  Joint_QuarcBlock_DW.HILInitialize_AOMaximums[0] = 0.0;
  Joint_QuarcBlock_DW.HILInitialize_AOMaximums[1] = 0.0;
  Joint_QuarcBlock_DW.HILInitialize_AOVoltages[0] = 0.0;
  Joint_QuarcBlock_DW.HILInitialize_AOVoltages[1] = 0.0;
  Joint_QuarcBlock_DW.HILInitialize_FilterFrequency[0] = 0.0;
  Joint_QuarcBlock_DW.HILInitialize_FilterFrequency[1] = 0.0;
  Joint_QuarcBlock_DW.HILReadAnalog_Buffer = 0.0;

  {
    int32_T i;
    for (i = 0; i < 200; i++) {
      Joint_QuarcBlock_DW.lastSin[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 200; i++) {
      Joint_QuarcBlock_DW.lastCos[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Joint_QuarcBlock_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Joint_QuarcBlock_M->Sizes.numContStates = (0);/* Number of continuous states */
  Joint_QuarcBlock_M->Sizes.numY = (0);/* Number of model outputs */
  Joint_QuarcBlock_M->Sizes.numU = (0);/* Number of model inputs */
  Joint_QuarcBlock_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Joint_QuarcBlock_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Joint_QuarcBlock_M->Sizes.numBlocks = (22);/* Number of blocks */
  Joint_QuarcBlock_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  Joint_QuarcBlock_M->Sizes.numBlockPrms = (878);/* Sum of parameter "widths" */
  return Joint_QuarcBlock_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
