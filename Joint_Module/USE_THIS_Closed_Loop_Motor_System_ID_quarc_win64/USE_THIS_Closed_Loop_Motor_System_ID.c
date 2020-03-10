/*
 * USE_THIS_Closed_Loop_Motor_System_ID.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "USE_THIS_Closed_Loop_Motor_System_ID".
 *
 * Model version              : 1.232
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Thu Mar  5 17:27:47 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "USE_THIS_Closed_Loop_Motor_System_ID.h"
#include "USE_THIS_Closed_Loop_Motor_System_ID_private.h"
#include "USE_THIS_Closed_Loop_Motor_System_ID_dt.h"

/* Block signals (default storage) */
B_USE_THIS_Closed_Loop_Motor__T USE_THIS_Closed_Loop_Motor_Sy_B;

/* Block states (default storage) */
DW_USE_THIS_Closed_Loop_Motor_T USE_THIS_Closed_Loop_Motor_S_DW;

/* Real-time model */
RT_MODEL_USE_THIS_Closed_Loop_T USE_THIS_Closed_Loop_Motor_S_M_;
RT_MODEL_USE_THIS_Closed_Loop_T *const USE_THIS_Closed_Loop_Motor_S_M =
  &USE_THIS_Closed_Loop_Motor_S_M_;

/* Model output function */
void USE_THIS_Closed_Loop_Motor_System_ID_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoder_o1;
  real_T rtb_HILReadAnalog;
  real_T rtb_Saturation;
  real_T tmp;
  int32_T i;

  /* S-Function (hil_read_encoder_block): '<S1>/HIL Read Encoder' */

  /* S-Function Block: USE_THIS_Closed_Loop_Motor_System_ID/Motor/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder
      (USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card,
       USE_THIS_Closed_Loop_Motor_Sy_P.HILReadEncoder_channels, 2,
       &USE_THIS_Closed_Loop_Motor_S_DW.HILReadEncoder_Buffer[0]);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(USE_THIS_Closed_Loop_Motor_S_M, _rt_error_message);
    } else {
      rtb_HILReadEncoder_o1 =
        USE_THIS_Closed_Loop_Motor_S_DW.HILReadEncoder_Buffer[0];
      rtb_HILReadAnalog = USE_THIS_Closed_Loop_Motor_S_DW.HILReadEncoder_Buffer
        [1];
    }
  }

  /* Gain: '<S1>/Servo:  Counts to Rad' */
  USE_THIS_Closed_Loop_Motor_Sy_B.ServoCountstoRad =
    USE_THIS_Closed_Loop_Motor_Sy_P.ServoCountstoRad_Gain *
    rtb_HILReadEncoder_o1;

  /* Gain: '<S1>/Servo:  Counts to Rad1' */
  USE_THIS_Closed_Loop_Motor_Sy_B.ServoCountstoRad1 =
    USE_THIS_Closed_Loop_Motor_Sy_P.ServoCountstoRad1_Gain * rtb_HILReadAnalog;

  /* S-Function (hil_read_analog_block): '<S1>/HIL Read Analog' */

  /* S-Function Block: USE_THIS_Closed_Loop_Motor_System_ID/Motor/HIL Read Analog (hil_read_analog_block) */
  {
    t_error result = hil_read_analog
      (USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card,
       &USE_THIS_Closed_Loop_Motor_Sy_P.HILReadAnalog_channels, 1,
       &USE_THIS_Closed_Loop_Motor_S_DW.HILReadAnalog_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(USE_THIS_Closed_Loop_Motor_S_M, _rt_error_message);
    }

    rtb_HILReadAnalog = USE_THIS_Closed_Loop_Motor_S_DW.HILReadAnalog_Buffer;
  }

  /* Gain: '<S1>/Tach Dir' */
  USE_THIS_Closed_Loop_Motor_Sy_B.TachDir =
    USE_THIS_Closed_Loop_Motor_Sy_P.TachDir_Gain * rtb_HILReadAnalog;

  /* Sin: '<Root>/Sine Wave' */
  tmp = USE_THIS_Closed_Loop_Motor_S_M->Timing.t[0];

  /* Sum: '<Root>/Sum of Elements' */
  rtb_Saturation = -0.0;
  for (i = 0; i < 250; i++) {
    /* Sum: '<Root>/Sum of Elements' incorporates:
     *  Sin: '<Root>/Sine Wave'
     */
    rtb_Saturation += sin(6.2831853071795862 *
                          USE_THIS_Closed_Loop_Mot_ConstP.SineWave_rtw_collapsed_sub_expr
                          [i] / USE_THIS_Closed_Loop_Motor_Sy_P.T * tmp +
                          USE_THIS_Closed_Loop_Motor_Sy_P.SineWave_Phase[i]) *
      USE_THIS_Closed_Loop_Motor_Sy_P.a +
      USE_THIS_Closed_Loop_Motor_Sy_P.SineWave_Bias;
  }

  /* Sum: '<Root>/Sum' */
  USE_THIS_Closed_Loop_Motor_Sy_B.Sum = rtb_Saturation -
    USE_THIS_Closed_Loop_Motor_Sy_B.ServoCountstoRad;

  /* Saturate: '<S1>/Saturation' */
  if (USE_THIS_Closed_Loop_Motor_Sy_B.Sum >
      USE_THIS_Closed_Loop_Motor_Sy_P.Saturation_UpperSat) {
    tmp = USE_THIS_Closed_Loop_Motor_Sy_P.Saturation_UpperSat;
  } else if (USE_THIS_Closed_Loop_Motor_Sy_B.Sum <
             USE_THIS_Closed_Loop_Motor_Sy_P.Saturation_LowerSat) {
    tmp = USE_THIS_Closed_Loop_Motor_Sy_P.Saturation_LowerSat;
  } else {
    tmp = USE_THIS_Closed_Loop_Motor_Sy_B.Sum;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Gain: '<S1>/Motor Dir ' */
  USE_THIS_Closed_Loop_Motor_Sy_B.MotorDir =
    USE_THIS_Closed_Loop_Motor_Sy_P.MotorDir_Gain * tmp;

  /* S-Function (hil_write_block): '<S1>/HIL Write' */

  /* S-Function Block: USE_THIS_Closed_Loop_Motor_System_ID/Motor/HIL Write (hil_write_block) */
  {
    t_error result;
    result = hil_write(USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card,
                       &USE_THIS_Closed_Loop_Motor_Sy_P.HILWrite_analog_channels,
                       1U,
                       NULL, 0U,
                       NULL, 0U,
                       NULL, 0U,
                       &USE_THIS_Closed_Loop_Motor_Sy_B.MotorDir,
                       NULL,
                       NULL,
                       NULL
                       );
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(USE_THIS_Closed_Loop_Motor_S_M, _rt_error_message);
    }
  }

  /* Clock: '<Root>/Clock' */
  USE_THIS_Closed_Loop_Motor_Sy_B.Clock =
    USE_THIS_Closed_Loop_Motor_S_M->Timing.t[0];
}

/* Model update function */
void USE_THIS_Closed_Loop_Motor_System_ID_update(void)
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
  if (!(++USE_THIS_Closed_Loop_Motor_S_M->Timing.clockTick0)) {
    ++USE_THIS_Closed_Loop_Motor_S_M->Timing.clockTickH0;
  }

  USE_THIS_Closed_Loop_Motor_S_M->Timing.t[0] =
    USE_THIS_Closed_Loop_Motor_S_M->Timing.clockTick0 *
    USE_THIS_Closed_Loop_Motor_S_M->Timing.stepSize0 +
    USE_THIS_Closed_Loop_Motor_S_M->Timing.clockTickH0 *
    USE_THIS_Closed_Loop_Motor_S_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++USE_THIS_Closed_Loop_Motor_S_M->Timing.clockTick1)) {
      ++USE_THIS_Closed_Loop_Motor_S_M->Timing.clockTickH1;
    }

    USE_THIS_Closed_Loop_Motor_S_M->Timing.t[1] =
      USE_THIS_Closed_Loop_Motor_S_M->Timing.clockTick1 *
      USE_THIS_Closed_Loop_Motor_S_M->Timing.stepSize1 +
      USE_THIS_Closed_Loop_Motor_S_M->Timing.clockTickH1 *
      USE_THIS_Closed_Loop_Motor_S_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void USE_THIS_Closed_Loop_Motor_System_ID_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: USE_THIS_Closed_Loop_Motor_System_ID/Motor/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0",
                      &USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(USE_THIS_Closed_Loop_Motor_S_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(USE_THIS_Closed_Loop_Motor_S_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear
      (USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(USE_THIS_Closed_Loop_Motor_S_M, _rt_error_message);
      return;
    }

    if ((USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AIPStart && !is_switching)
        || (USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AIPEnter &&
            is_switching)) {
      USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AIMinimums[0] =
        (USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AILow);
      USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AIMinimums[1] =
        (USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AILow);
      USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AIMaximums[0] =
        USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AIHigh;
      USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AIMaximums[1] =
        USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card,
         USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AIChannels, 2U,
         &USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AIMinimums[0],
         &USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(USE_THIS_Closed_Loop_Motor_S_M, _rt_error_message);
        return;
      }
    }

    if ((USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOPStart && !is_switching)
        || (USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOPEnter &&
            is_switching)) {
      USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOMinimums[0] =
        (USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOLow);
      USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOMinimums[1] =
        (USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOLow);
      USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOMaximums[0] =
        USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOHigh;
      USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOMaximums[1] =
        USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card,
         USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOChannels, 2U,
         &USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOMinimums[0],
         &USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(USE_THIS_Closed_Loop_Motor_S_M, _rt_error_message);
        return;
      }
    }

    if ((USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOStart && !is_switching)
        || (USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOEnter &&
            is_switching)) {
      USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOVoltages[0] =
        USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOInitial;
      USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOVoltages[1] =
        USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOInitial;
      result = hil_write_analog
        (USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card,
         USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOChannels, 2U,
         &USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(USE_THIS_Closed_Loop_Motor_S_M, _rt_error_message);
        return;
      }
    }

    if (USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOReset) {
      USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOVoltages[0] =
        USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOWatchdog;
      USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOVoltages[1] =
        USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card,
         USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOChannels, 2U,
         &USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(USE_THIS_Closed_Loop_Motor_S_M, _rt_error_message);
        return;
      }
    }

    if ((USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_EIPStart && !is_switching)
        || (USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_EIPEnter &&
            is_switching)) {
      USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_QuadratureModes[0] =
        USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_EIQuadrature;
      USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_QuadratureModes[1] =
        USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card,
         USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(USE_THIS_Closed_Loop_Motor_S_M, _rt_error_message);
        return;
      }
    }

    if ((USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_EIStart && !is_switching)
        || (USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_EIEnter &&
            is_switching)) {
      USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_InitialEICounts[0] =
        USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_EIInitial;
      USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_InitialEICounts[1] =
        USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts
        (USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card,
         USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_EIChannels, 2U,
         &USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(USE_THIS_Closed_Loop_Motor_S_M, _rt_error_message);
        return;
      }
    }
  }
}

/* Model terminate function */
void USE_THIS_Closed_Loop_Motor_System_ID_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: USE_THIS_Closed_Loop_Motor_System_ID/Motor/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card);
    hil_monitor_stop_all(USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card);
    is_switching = false;
    if ((USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOTerminate &&
         !is_switching) || (USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOExit
         && is_switching)) {
      USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOVoltages[0] =
        USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOFinal;
      USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOVoltages[1] =
        USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog
        (USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card,
         USE_THIS_Closed_Loop_Motor_Sy_P.HILInitialize_AOChannels,
         num_final_analog_outputs,
         &USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(USE_THIS_Closed_Loop_Motor_S_M, _rt_error_message);
      }
    }

    hil_task_delete_all(USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card);
    hil_monitor_delete_all(USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card);
    hil_close(USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card);
    USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  USE_THIS_Closed_Loop_Motor_System_ID_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  USE_THIS_Closed_Loop_Motor_System_ID_update();
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
  USE_THIS_Closed_Loop_Motor_System_ID_initialize();
}

void MdlTerminate(void)
{
  USE_THIS_Closed_Loop_Motor_System_ID_terminate();
}

/* Registration function */
RT_MODEL_USE_THIS_Closed_Loop_T *USE_THIS_Closed_Loop_Motor_System_ID(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)USE_THIS_Closed_Loop_Motor_S_M, 0,
                sizeof(RT_MODEL_USE_THIS_Closed_Loop_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&USE_THIS_Closed_Loop_Motor_S_M->solverInfo,
                          &USE_THIS_Closed_Loop_Motor_S_M->Timing.simTimeStep);
    rtsiSetTPtr(&USE_THIS_Closed_Loop_Motor_S_M->solverInfo, &rtmGetTPtr
                (USE_THIS_Closed_Loop_Motor_S_M));
    rtsiSetStepSizePtr(&USE_THIS_Closed_Loop_Motor_S_M->solverInfo,
                       &USE_THIS_Closed_Loop_Motor_S_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&USE_THIS_Closed_Loop_Motor_S_M->solverInfo,
                          (&rtmGetErrorStatus(USE_THIS_Closed_Loop_Motor_S_M)));
    rtsiSetRTModelPtr(&USE_THIS_Closed_Loop_Motor_S_M->solverInfo,
                      USE_THIS_Closed_Loop_Motor_S_M);
  }

  rtsiSetSimTimeStep(&USE_THIS_Closed_Loop_Motor_S_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&USE_THIS_Closed_Loop_Motor_S_M->solverInfo,
                    "FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      USE_THIS_Closed_Loop_Motor_S_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    USE_THIS_Closed_Loop_Motor_S_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    USE_THIS_Closed_Loop_Motor_S_M->Timing.sampleTimes =
      (&USE_THIS_Closed_Loop_Motor_S_M->Timing.sampleTimesArray[0]);
    USE_THIS_Closed_Loop_Motor_S_M->Timing.offsetTimes =
      (&USE_THIS_Closed_Loop_Motor_S_M->Timing.offsetTimesArray[0]);

    /* task periods */
    USE_THIS_Closed_Loop_Motor_S_M->Timing.sampleTimes[0] = (0.0);
    USE_THIS_Closed_Loop_Motor_S_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    USE_THIS_Closed_Loop_Motor_S_M->Timing.offsetTimes[0] = (0.0);
    USE_THIS_Closed_Loop_Motor_S_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(USE_THIS_Closed_Loop_Motor_S_M,
             &USE_THIS_Closed_Loop_Motor_S_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = USE_THIS_Closed_Loop_Motor_S_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    USE_THIS_Closed_Loop_Motor_S_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(USE_THIS_Closed_Loop_Motor_S_M, 39.998);
  USE_THIS_Closed_Loop_Motor_S_M->Timing.stepSize0 = 0.002;
  USE_THIS_Closed_Loop_Motor_S_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  USE_THIS_Closed_Loop_Motor_S_M->Sizes.checksums[0] = (74250332U);
  USE_THIS_Closed_Loop_Motor_S_M->Sizes.checksums[1] = (3417743828U);
  USE_THIS_Closed_Loop_Motor_S_M->Sizes.checksums[2] = (2924871442U);
  USE_THIS_Closed_Loop_Motor_S_M->Sizes.checksums[3] = (1252235273U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    USE_THIS_Closed_Loop_Motor_S_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(USE_THIS_Closed_Loop_Motor_S_M->extModeInfo,
      &USE_THIS_Closed_Loop_Motor_S_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(USE_THIS_Closed_Loop_Motor_S_M->extModeInfo,
                        USE_THIS_Closed_Loop_Motor_S_M->Sizes.checksums);
    rteiSetTPtr(USE_THIS_Closed_Loop_Motor_S_M->extModeInfo, rtmGetTPtr
                (USE_THIS_Closed_Loop_Motor_S_M));
  }

  USE_THIS_Closed_Loop_Motor_S_M->solverInfoPtr =
    (&USE_THIS_Closed_Loop_Motor_S_M->solverInfo);
  USE_THIS_Closed_Loop_Motor_S_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&USE_THIS_Closed_Loop_Motor_S_M->solverInfo, 0.002);
  rtsiSetSolverMode(&USE_THIS_Closed_Loop_Motor_S_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  USE_THIS_Closed_Loop_Motor_S_M->blockIO = ((void *)
    &USE_THIS_Closed_Loop_Motor_Sy_B);

  {
    USE_THIS_Closed_Loop_Motor_Sy_B.ServoCountstoRad = 0.0;
    USE_THIS_Closed_Loop_Motor_Sy_B.ServoCountstoRad1 = 0.0;
    USE_THIS_Closed_Loop_Motor_Sy_B.TachDir = 0.0;
    USE_THIS_Closed_Loop_Motor_Sy_B.Sum = 0.0;
    USE_THIS_Closed_Loop_Motor_Sy_B.MotorDir = 0.0;
    USE_THIS_Closed_Loop_Motor_Sy_B.Clock = 0.0;
  }

  /* parameters */
  USE_THIS_Closed_Loop_Motor_S_M->defaultParam = ((real_T *)
    &USE_THIS_Closed_Loop_Motor_Sy_P);

  /* states (dwork) */
  USE_THIS_Closed_Loop_Motor_S_M->dwork = ((void *)
    &USE_THIS_Closed_Loop_Motor_S_DW);
  (void) memset((void *)&USE_THIS_Closed_Loop_Motor_S_DW, 0,
                sizeof(DW_USE_THIS_Closed_Loop_Motor_T));
  USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AIMinimums[0] = 0.0;
  USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AIMinimums[1] = 0.0;
  USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AIMaximums[0] = 0.0;
  USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AIMaximums[1] = 0.0;
  USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOMinimums[0] = 0.0;
  USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOMinimums[1] = 0.0;
  USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOMaximums[0] = 0.0;
  USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOMaximums[1] = 0.0;
  USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOVoltages[0] = 0.0;
  USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_AOVoltages[1] = 0.0;
  USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_FilterFrequency[0] = 0.0;
  USE_THIS_Closed_Loop_Motor_S_DW.HILInitialize_FilterFrequency[1] = 0.0;
  USE_THIS_Closed_Loop_Motor_S_DW.HILReadAnalog_Buffer = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    USE_THIS_Closed_Loop_Motor_S_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  USE_THIS_Closed_Loop_Motor_S_M->Sizes.numContStates = (0);/* Number of continuous states */
  USE_THIS_Closed_Loop_Motor_S_M->Sizes.numY = (0);/* Number of model outputs */
  USE_THIS_Closed_Loop_Motor_S_M->Sizes.numU = (0);/* Number of model inputs */
  USE_THIS_Closed_Loop_Motor_S_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  USE_THIS_Closed_Loop_Motor_S_M->Sizes.numSampTimes = (2);/* Number of sample times */
  USE_THIS_Closed_Loop_Motor_S_M->Sizes.numBlocks = (22);/* Number of blocks */
  USE_THIS_Closed_Loop_Motor_S_M->Sizes.numBlockIO = (6);/* Number of block outputs */
  USE_THIS_Closed_Loop_Motor_S_M->Sizes.numBlockPrms = (327);/* Sum of parameter "widths" */
  return USE_THIS_Closed_Loop_Motor_S_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
