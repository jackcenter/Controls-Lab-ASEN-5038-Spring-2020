/*
 * Motor_System_ID.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Motor_System_ID".
 *
 * Model version              : 1.230
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Thu Mar  5 17:06:18 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Motor_System_ID.h"
#include "Motor_System_ID_private.h"
#include "Motor_System_ID_dt.h"

/* Block signals (default storage) */
B_Motor_System_ID_T Motor_System_ID_B;

/* Block states (default storage) */
DW_Motor_System_ID_T Motor_System_ID_DW;

/* Real-time model */
RT_MODEL_Motor_System_ID_T Motor_System_ID_M_;
RT_MODEL_Motor_System_ID_T *const Motor_System_ID_M = &Motor_System_ID_M_;

/* Model output function */
void Motor_System_ID_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalog;
  real_T tmp;
  real_T tmp_0;
  int32_T i;

  /* S-Function (hil_read_encoder_block): '<S1>/HIL Read Encoder' */

  /* S-Function Block: Motor_System_ID/Motor/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(Motor_System_ID_DW.HILInitialize_Card,
      &Motor_System_ID_P.HILReadEncoder_channels, 1,
      &Motor_System_ID_DW.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Motor_System_ID_M, _rt_error_message);
    } else {
      rtb_HILReadAnalog = Motor_System_ID_DW.HILReadEncoder_Buffer;
    }
  }

  /* Gain: '<S1>/Servo:  Counts to Rad' */
  Motor_System_ID_B.ServoCountstoRad = Motor_System_ID_P.ServoCountstoRad_Gain *
    rtb_HILReadAnalog;

  /* S-Function (hil_read_analog_block): '<S1>/HIL Read Analog' */

  /* S-Function Block: Motor_System_ID/Motor/HIL Read Analog (hil_read_analog_block) */
  {
    t_error result = hil_read_analog(Motor_System_ID_DW.HILInitialize_Card,
      &Motor_System_ID_P.HILReadAnalog_channels, 1,
      &Motor_System_ID_DW.HILReadAnalog_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Motor_System_ID_M, _rt_error_message);
    }

    rtb_HILReadAnalog = Motor_System_ID_DW.HILReadAnalog_Buffer;
  }

  /* Gain: '<S1>/Tach Dir' */
  Motor_System_ID_B.TachDir = Motor_System_ID_P.TachDir_Gain * rtb_HILReadAnalog;

  /* Sin: '<Root>/Sine Wave' */
  tmp_0 = Motor_System_ID_M->Timing.t[0];

  /* Sum: '<Root>/Sum of Elements' */
  tmp = -0.0;
  for (i = 0; i < 250; i++) {
    /* Sum: '<Root>/Sum of Elements' incorporates:
     *  Sin: '<Root>/Sine Wave'
     */
    tmp += sin(6.2831853071795862 *
               Motor_System_ID_ConstP.SineWave_rtw_collapsed_sub_expr[i] /
               Motor_System_ID_P.T * tmp_0 + Motor_System_ID_P.SineWave_Phase[i])
      * Motor_System_ID_P.a + Motor_System_ID_P.SineWave_Bias;
  }

  /* Sum: '<Root>/Sum of Elements' */
  Motor_System_ID_B.SumofElements = tmp;

  /* Saturate: '<S1>/Saturation' */
  if (Motor_System_ID_B.SumofElements > Motor_System_ID_P.Saturation_UpperSat) {
    tmp_0 = Motor_System_ID_P.Saturation_UpperSat;
  } else if (Motor_System_ID_B.SumofElements <
             Motor_System_ID_P.Saturation_LowerSat) {
    tmp_0 = Motor_System_ID_P.Saturation_LowerSat;
  } else {
    tmp_0 = Motor_System_ID_B.SumofElements;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Gain: '<S1>/Motor Dir ' */
  Motor_System_ID_B.MotorDir = Motor_System_ID_P.MotorDir_Gain * tmp_0;

  /* S-Function (hil_write_block): '<S1>/HIL Write' */

  /* S-Function Block: Motor_System_ID/Motor/HIL Write (hil_write_block) */
  {
    t_error result;
    result = hil_write(Motor_System_ID_DW.HILInitialize_Card,
                       &Motor_System_ID_P.HILWrite_analog_channels, 1U,
                       NULL, 0U,
                       NULL, 0U,
                       NULL, 0U,
                       &Motor_System_ID_B.MotorDir,
                       NULL,
                       NULL,
                       NULL
                       );
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Motor_System_ID_M, _rt_error_message);
    }
  }

  /* Clock: '<Root>/Clock' */
  Motor_System_ID_B.Clock = Motor_System_ID_M->Timing.t[0];
}

/* Model update function */
void Motor_System_ID_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Motor_System_ID_M->Timing.clockTick0)) {
    ++Motor_System_ID_M->Timing.clockTickH0;
  }

  Motor_System_ID_M->Timing.t[0] = Motor_System_ID_M->Timing.clockTick0 *
    Motor_System_ID_M->Timing.stepSize0 + Motor_System_ID_M->Timing.clockTickH0 *
    Motor_System_ID_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++Motor_System_ID_M->Timing.clockTick1)) {
      ++Motor_System_ID_M->Timing.clockTickH1;
    }

    Motor_System_ID_M->Timing.t[1] = Motor_System_ID_M->Timing.clockTick1 *
      Motor_System_ID_M->Timing.stepSize1 +
      Motor_System_ID_M->Timing.clockTickH1 *
      Motor_System_ID_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void Motor_System_ID_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: Motor_System_ID/Motor/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &Motor_System_ID_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Motor_System_ID_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(Motor_System_ID_DW.HILInitialize_Card,
      "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Motor_System_ID_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Motor_System_ID_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Motor_System_ID_M, _rt_error_message);
      return;
    }

    if ((Motor_System_ID_P.HILInitialize_AIPStart && !is_switching) ||
        (Motor_System_ID_P.HILInitialize_AIPEnter && is_switching)) {
      Motor_System_ID_DW.HILInitialize_AIMinimums[0] =
        (Motor_System_ID_P.HILInitialize_AILow);
      Motor_System_ID_DW.HILInitialize_AIMinimums[1] =
        (Motor_System_ID_P.HILInitialize_AILow);
      Motor_System_ID_DW.HILInitialize_AIMaximums[0] =
        Motor_System_ID_P.HILInitialize_AIHigh;
      Motor_System_ID_DW.HILInitialize_AIMaximums[1] =
        Motor_System_ID_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges(Motor_System_ID_DW.HILInitialize_Card,
        Motor_System_ID_P.HILInitialize_AIChannels, 2U,
        &Motor_System_ID_DW.HILInitialize_AIMinimums[0],
        &Motor_System_ID_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Motor_System_ID_M, _rt_error_message);
        return;
      }
    }

    if ((Motor_System_ID_P.HILInitialize_AOPStart && !is_switching) ||
        (Motor_System_ID_P.HILInitialize_AOPEnter && is_switching)) {
      Motor_System_ID_DW.HILInitialize_AOMinimums[0] =
        (Motor_System_ID_P.HILInitialize_AOLow);
      Motor_System_ID_DW.HILInitialize_AOMinimums[1] =
        (Motor_System_ID_P.HILInitialize_AOLow);
      Motor_System_ID_DW.HILInitialize_AOMaximums[0] =
        Motor_System_ID_P.HILInitialize_AOHigh;
      Motor_System_ID_DW.HILInitialize_AOMaximums[1] =
        Motor_System_ID_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (Motor_System_ID_DW.HILInitialize_Card,
         Motor_System_ID_P.HILInitialize_AOChannels, 2U,
         &Motor_System_ID_DW.HILInitialize_AOMinimums[0],
         &Motor_System_ID_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Motor_System_ID_M, _rt_error_message);
        return;
      }
    }

    if ((Motor_System_ID_P.HILInitialize_AOStart && !is_switching) ||
        (Motor_System_ID_P.HILInitialize_AOEnter && is_switching)) {
      Motor_System_ID_DW.HILInitialize_AOVoltages[0] =
        Motor_System_ID_P.HILInitialize_AOInitial;
      Motor_System_ID_DW.HILInitialize_AOVoltages[1] =
        Motor_System_ID_P.HILInitialize_AOInitial;
      result = hil_write_analog(Motor_System_ID_DW.HILInitialize_Card,
        Motor_System_ID_P.HILInitialize_AOChannels, 2U,
        &Motor_System_ID_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Motor_System_ID_M, _rt_error_message);
        return;
      }
    }

    if (Motor_System_ID_P.HILInitialize_AOReset) {
      Motor_System_ID_DW.HILInitialize_AOVoltages[0] =
        Motor_System_ID_P.HILInitialize_AOWatchdog;
      Motor_System_ID_DW.HILInitialize_AOVoltages[1] =
        Motor_System_ID_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (Motor_System_ID_DW.HILInitialize_Card,
         Motor_System_ID_P.HILInitialize_AOChannels, 2U,
         &Motor_System_ID_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Motor_System_ID_M, _rt_error_message);
        return;
      }
    }

    if ((Motor_System_ID_P.HILInitialize_EIPStart && !is_switching) ||
        (Motor_System_ID_P.HILInitialize_EIPEnter && is_switching)) {
      Motor_System_ID_DW.HILInitialize_QuadratureModes[0] =
        Motor_System_ID_P.HILInitialize_EIQuadrature;
      Motor_System_ID_DW.HILInitialize_QuadratureModes[1] =
        Motor_System_ID_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (Motor_System_ID_DW.HILInitialize_Card,
         Motor_System_ID_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &Motor_System_ID_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Motor_System_ID_M, _rt_error_message);
        return;
      }
    }

    if ((Motor_System_ID_P.HILInitialize_EIStart && !is_switching) ||
        (Motor_System_ID_P.HILInitialize_EIEnter && is_switching)) {
      Motor_System_ID_DW.HILInitialize_InitialEICounts[0] =
        Motor_System_ID_P.HILInitialize_EIInitial;
      Motor_System_ID_DW.HILInitialize_InitialEICounts[1] =
        Motor_System_ID_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Motor_System_ID_DW.HILInitialize_Card,
        Motor_System_ID_P.HILInitialize_EIChannels, 2U,
        &Motor_System_ID_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Motor_System_ID_M, _rt_error_message);
        return;
      }
    }
  }
}

/* Model terminate function */
void Motor_System_ID_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: Motor_System_ID/Motor/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(Motor_System_ID_DW.HILInitialize_Card);
    hil_monitor_stop_all(Motor_System_ID_DW.HILInitialize_Card);
    is_switching = false;
    if ((Motor_System_ID_P.HILInitialize_AOTerminate && !is_switching) ||
        (Motor_System_ID_P.HILInitialize_AOExit && is_switching)) {
      Motor_System_ID_DW.HILInitialize_AOVoltages[0] =
        Motor_System_ID_P.HILInitialize_AOFinal;
      Motor_System_ID_DW.HILInitialize_AOVoltages[1] =
        Motor_System_ID_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(Motor_System_ID_DW.HILInitialize_Card,
        Motor_System_ID_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &Motor_System_ID_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Motor_System_ID_M, _rt_error_message);
      }
    }

    hil_task_delete_all(Motor_System_ID_DW.HILInitialize_Card);
    hil_monitor_delete_all(Motor_System_ID_DW.HILInitialize_Card);
    hil_close(Motor_System_ID_DW.HILInitialize_Card);
    Motor_System_ID_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Motor_System_ID_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Motor_System_ID_update();
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
  Motor_System_ID_initialize();
}

void MdlTerminate(void)
{
  Motor_System_ID_terminate();
}

/* Registration function */
RT_MODEL_Motor_System_ID_T *Motor_System_ID(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Motor_System_ID_M, 0,
                sizeof(RT_MODEL_Motor_System_ID_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Motor_System_ID_M->solverInfo,
                          &Motor_System_ID_M->Timing.simTimeStep);
    rtsiSetTPtr(&Motor_System_ID_M->solverInfo, &rtmGetTPtr(Motor_System_ID_M));
    rtsiSetStepSizePtr(&Motor_System_ID_M->solverInfo,
                       &Motor_System_ID_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Motor_System_ID_M->solverInfo, (&rtmGetErrorStatus
      (Motor_System_ID_M)));
    rtsiSetRTModelPtr(&Motor_System_ID_M->solverInfo, Motor_System_ID_M);
  }

  rtsiSetSimTimeStep(&Motor_System_ID_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Motor_System_ID_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Motor_System_ID_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Motor_System_ID_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Motor_System_ID_M->Timing.sampleTimes =
      (&Motor_System_ID_M->Timing.sampleTimesArray[0]);
    Motor_System_ID_M->Timing.offsetTimes =
      (&Motor_System_ID_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Motor_System_ID_M->Timing.sampleTimes[0] = (0.0);
    Motor_System_ID_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    Motor_System_ID_M->Timing.offsetTimes[0] = (0.0);
    Motor_System_ID_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Motor_System_ID_M, &Motor_System_ID_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Motor_System_ID_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Motor_System_ID_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Motor_System_ID_M, 20.0);
  Motor_System_ID_M->Timing.stepSize0 = 0.002;
  Motor_System_ID_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  Motor_System_ID_M->Sizes.checksums[0] = (3340768136U);
  Motor_System_ID_M->Sizes.checksums[1] = (3140166842U);
  Motor_System_ID_M->Sizes.checksums[2] = (4000367284U);
  Motor_System_ID_M->Sizes.checksums[3] = (2405691216U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Motor_System_ID_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Motor_System_ID_M->extModeInfo,
      &Motor_System_ID_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Motor_System_ID_M->extModeInfo,
                        Motor_System_ID_M->Sizes.checksums);
    rteiSetTPtr(Motor_System_ID_M->extModeInfo, rtmGetTPtr(Motor_System_ID_M));
  }

  Motor_System_ID_M->solverInfoPtr = (&Motor_System_ID_M->solverInfo);
  Motor_System_ID_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&Motor_System_ID_M->solverInfo, 0.002);
  rtsiSetSolverMode(&Motor_System_ID_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Motor_System_ID_M->blockIO = ((void *) &Motor_System_ID_B);

  {
    Motor_System_ID_B.ServoCountstoRad = 0.0;
    Motor_System_ID_B.TachDir = 0.0;
    Motor_System_ID_B.SumofElements = 0.0;
    Motor_System_ID_B.MotorDir = 0.0;
    Motor_System_ID_B.Clock = 0.0;
  }

  /* parameters */
  Motor_System_ID_M->defaultParam = ((real_T *)&Motor_System_ID_P);

  /* states (dwork) */
  Motor_System_ID_M->dwork = ((void *) &Motor_System_ID_DW);
  (void) memset((void *)&Motor_System_ID_DW, 0,
                sizeof(DW_Motor_System_ID_T));
  Motor_System_ID_DW.HILInitialize_AIMinimums[0] = 0.0;
  Motor_System_ID_DW.HILInitialize_AIMinimums[1] = 0.0;
  Motor_System_ID_DW.HILInitialize_AIMaximums[0] = 0.0;
  Motor_System_ID_DW.HILInitialize_AIMaximums[1] = 0.0;
  Motor_System_ID_DW.HILInitialize_AOMinimums[0] = 0.0;
  Motor_System_ID_DW.HILInitialize_AOMinimums[1] = 0.0;
  Motor_System_ID_DW.HILInitialize_AOMaximums[0] = 0.0;
  Motor_System_ID_DW.HILInitialize_AOMaximums[1] = 0.0;
  Motor_System_ID_DW.HILInitialize_AOVoltages[0] = 0.0;
  Motor_System_ID_DW.HILInitialize_AOVoltages[1] = 0.0;
  Motor_System_ID_DW.HILInitialize_FilterFrequency[0] = 0.0;
  Motor_System_ID_DW.HILInitialize_FilterFrequency[1] = 0.0;
  Motor_System_ID_DW.HILReadAnalog_Buffer = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Motor_System_ID_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Motor_System_ID_M->Sizes.numContStates = (0);/* Number of continuous states */
  Motor_System_ID_M->Sizes.numY = (0); /* Number of model outputs */
  Motor_System_ID_M->Sizes.numU = (0); /* Number of model inputs */
  Motor_System_ID_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Motor_System_ID_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Motor_System_ID_M->Sizes.numBlocks = (19);/* Number of blocks */
  Motor_System_ID_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  Motor_System_ID_M->Sizes.numBlockPrms = (325);/* Sum of parameter "widths" */
  return Motor_System_ID_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
