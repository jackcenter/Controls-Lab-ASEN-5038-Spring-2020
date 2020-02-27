/*
 * State_Space_Quarc_LQI.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "State_Space_Quarc_LQI".
 *
 * Model version              : 1.238
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Thu Feb 27 14:09:58 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "State_Space_Quarc_LQI.h"
#include "State_Space_Quarc_LQI_private.h"
#include "State_Space_Quarc_LQI_dt.h"

/* Block signals (default storage) */
B_State_Space_Quarc_LQI_T State_Space_Quarc_LQI_B;

/* Block states (default storage) */
DW_State_Space_Quarc_LQI_T State_Space_Quarc_LQI_DW;

/* Real-time model */
RT_MODEL_State_Space_Quarc_LQ_T State_Space_Quarc_LQI_M_;
RT_MODEL_State_Space_Quarc_LQ_T *const State_Space_Quarc_LQI_M =
  &State_Space_Quarc_LQI_M_;

/* Model output function */
void State_Space_Quarc_LQI_output(void)
{
  /* local block i/o variables */
  real_T rtb_Sum2;
  real_T currentTime;

  /* S-Function (hil_read_encoder_block): '<S1>/HIL Read Encoder' */

  /* S-Function Block: State_Space_Quarc_LQI/Motor/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder
      (State_Space_Quarc_LQI_DW.HILInitialize_Card,
       &State_Space_Quarc_LQI_P.HILReadEncoder_channels, 1,
       &State_Space_Quarc_LQI_DW.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(State_Space_Quarc_LQI_M, _rt_error_message);
    } else {
      rtb_Sum2 = State_Space_Quarc_LQI_DW.HILReadEncoder_Buffer;
    }
  }

  /* Gain: '<S1>/Servo:  Counts to Rad' */
  State_Space_Quarc_LQI_B.ServoCountstoRad =
    State_Space_Quarc_LQI_P.ServoCountstoRad_Gain * rtb_Sum2;

  /* S-Function (hil_read_analog_block): '<S1>/HIL Read Analog' */

  /* S-Function Block: State_Space_Quarc_LQI/Motor/HIL Read Analog (hil_read_analog_block) */
  {
    t_error result = hil_read_analog(State_Space_Quarc_LQI_DW.HILInitialize_Card,
      &State_Space_Quarc_LQI_P.HILReadAnalog_channels, 1,
      &State_Space_Quarc_LQI_DW.HILReadAnalog_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(State_Space_Quarc_LQI_M, _rt_error_message);
    }

    rtb_Sum2 = State_Space_Quarc_LQI_DW.HILReadAnalog_Buffer;
  }

  /* Gain: '<S1>/Tach Dir' */
  State_Space_Quarc_LQI_B.TachDir = State_Space_Quarc_LQI_P.TachDir_Gain *
    rtb_Sum2;

  /* Step: '<Root>/Step' */
  currentTime = State_Space_Quarc_LQI_M->Timing.t[1];
  if (currentTime < State_Space_Quarc_LQI_P.Step_Time) {
    State_Space_Quarc_LQI_B.Step = State_Space_Quarc_LQI_P.Step_Y0;
  } else {
    State_Space_Quarc_LQI_B.Step = State_Space_Quarc_LQI_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Gain: '<Root>/Gain5' incorporates:
   *  Gain: '<Root>/Gain1'
   *  Sum: '<Root>/Sum'
   */
  rtb_Sum2 = (State_Space_Quarc_LQI_P.G[0] * State_Space_Quarc_LQI_B.Step -
              State_Space_Quarc_LQI_B.ServoCountstoRad) *
    State_Space_Quarc_LQI_P.K[0] + (State_Space_Quarc_LQI_P.G[1] *
    State_Space_Quarc_LQI_B.Step - State_Space_Quarc_LQI_B.TachDir) *
    State_Space_Quarc_LQI_P.K[1];

  /* Sum: '<Root>/Sum1' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain2'
   *  Trigonometry: '<Root>/Trigonometric Function'
   */
  State_Space_Quarc_LQI_B.Sum1 = (State_Space_Quarc_LQI_P.b /
    State_Space_Quarc_LQI_P.c * sin(State_Space_Quarc_LQI_B.Step) + rtb_Sum2) +
    State_Space_Quarc_LQI_P.Ki *
    State_Space_Quarc_LQI_DW.DiscreteTimeIntegrator_DSTATE;

  /* Saturate: '<S1>/Saturation' */
  if (State_Space_Quarc_LQI_B.Sum1 > State_Space_Quarc_LQI_P.Saturation_UpperSat)
  {
    rtb_Sum2 = State_Space_Quarc_LQI_P.Saturation_UpperSat;
  } else if (State_Space_Quarc_LQI_B.Sum1 <
             State_Space_Quarc_LQI_P.Saturation_LowerSat) {
    rtb_Sum2 = State_Space_Quarc_LQI_P.Saturation_LowerSat;
  } else {
    rtb_Sum2 = State_Space_Quarc_LQI_B.Sum1;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Gain: '<S1>/Motor Dir ' */
  rtb_Sum2 *= State_Space_Quarc_LQI_P.MotorDir_Gain;

  /* S-Function (hil_write_block): '<S1>/HIL Write' */

  /* S-Function Block: State_Space_Quarc_LQI/Motor/HIL Write (hil_write_block) */
  {
    t_error result;
    result = hil_write(State_Space_Quarc_LQI_DW.HILInitialize_Card,
                       &State_Space_Quarc_LQI_P.HILWrite_analog_channels, 1U,
                       NULL, 0U,
                       NULL, 0U,
                       NULL, 0U,
                       &rtb_Sum2,
                       NULL,
                       NULL,
                       NULL
                       );
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(State_Space_Quarc_LQI_M, _rt_error_message);
    }
  }

  /* Clock: '<Root>/Clock' */
  State_Space_Quarc_LQI_B.Clock = State_Space_Quarc_LQI_M->Timing.t[0];

  /* Sum: '<Root>/Sum2' */
  rtb_Sum2 = State_Space_Quarc_LQI_B.Step -
    State_Space_Quarc_LQI_B.ServoCountstoRad;

  /* DeadZone: '<Root>/Dead Zone' */
  if (rtb_Sum2 > State_Space_Quarc_LQI_P.DeadZone_End) {
    State_Space_Quarc_LQI_B.DeadZone = rtb_Sum2 -
      State_Space_Quarc_LQI_P.DeadZone_End;
  } else if (rtb_Sum2 >= State_Space_Quarc_LQI_P.DeadZone_Start) {
    State_Space_Quarc_LQI_B.DeadZone = 0.0;
  } else {
    State_Space_Quarc_LQI_B.DeadZone = rtb_Sum2 -
      State_Space_Quarc_LQI_P.DeadZone_Start;
  }

  /* End of DeadZone: '<Root>/Dead Zone' */
}

/* Model update function */
void State_Space_Quarc_LQI_update(void)
{
  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  State_Space_Quarc_LQI_DW.DiscreteTimeIntegrator_DSTATE +=
    State_Space_Quarc_LQI_P.DiscreteTimeIntegrator_gainval *
    State_Space_Quarc_LQI_B.DeadZone;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++State_Space_Quarc_LQI_M->Timing.clockTick0)) {
    ++State_Space_Quarc_LQI_M->Timing.clockTickH0;
  }

  State_Space_Quarc_LQI_M->Timing.t[0] =
    State_Space_Quarc_LQI_M->Timing.clockTick0 *
    State_Space_Quarc_LQI_M->Timing.stepSize0 +
    State_Space_Quarc_LQI_M->Timing.clockTickH0 *
    State_Space_Quarc_LQI_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++State_Space_Quarc_LQI_M->Timing.clockTick1)) {
      ++State_Space_Quarc_LQI_M->Timing.clockTickH1;
    }

    State_Space_Quarc_LQI_M->Timing.t[1] =
      State_Space_Quarc_LQI_M->Timing.clockTick1 *
      State_Space_Quarc_LQI_M->Timing.stepSize1 +
      State_Space_Quarc_LQI_M->Timing.clockTickH1 *
      State_Space_Quarc_LQI_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void State_Space_Quarc_LQI_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: State_Space_Quarc_LQI/Motor/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0",
                      &State_Space_Quarc_LQI_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(State_Space_Quarc_LQI_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (State_Space_Quarc_LQI_DW.HILInitialize_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(State_Space_Quarc_LQI_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(State_Space_Quarc_LQI_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(State_Space_Quarc_LQI_M, _rt_error_message);
      return;
    }

    if ((State_Space_Quarc_LQI_P.HILInitialize_AIPStart && !is_switching) ||
        (State_Space_Quarc_LQI_P.HILInitialize_AIPEnter && is_switching)) {
      State_Space_Quarc_LQI_DW.HILInitialize_AIMinimums[0] =
        (State_Space_Quarc_LQI_P.HILInitialize_AILow);
      State_Space_Quarc_LQI_DW.HILInitialize_AIMinimums[1] =
        (State_Space_Quarc_LQI_P.HILInitialize_AILow);
      State_Space_Quarc_LQI_DW.HILInitialize_AIMaximums[0] =
        State_Space_Quarc_LQI_P.HILInitialize_AIHigh;
      State_Space_Quarc_LQI_DW.HILInitialize_AIMaximums[1] =
        State_Space_Quarc_LQI_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (State_Space_Quarc_LQI_DW.HILInitialize_Card,
         State_Space_Quarc_LQI_P.HILInitialize_AIChannels, 2U,
         &State_Space_Quarc_LQI_DW.HILInitialize_AIMinimums[0],
         &State_Space_Quarc_LQI_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(State_Space_Quarc_LQI_M, _rt_error_message);
        return;
      }
    }

    if ((State_Space_Quarc_LQI_P.HILInitialize_AOPStart && !is_switching) ||
        (State_Space_Quarc_LQI_P.HILInitialize_AOPEnter && is_switching)) {
      State_Space_Quarc_LQI_DW.HILInitialize_AOMinimums[0] =
        (State_Space_Quarc_LQI_P.HILInitialize_AOLow);
      State_Space_Quarc_LQI_DW.HILInitialize_AOMinimums[1] =
        (State_Space_Quarc_LQI_P.HILInitialize_AOLow);
      State_Space_Quarc_LQI_DW.HILInitialize_AOMaximums[0] =
        State_Space_Quarc_LQI_P.HILInitialize_AOHigh;
      State_Space_Quarc_LQI_DW.HILInitialize_AOMaximums[1] =
        State_Space_Quarc_LQI_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (State_Space_Quarc_LQI_DW.HILInitialize_Card,
         State_Space_Quarc_LQI_P.HILInitialize_AOChannels, 2U,
         &State_Space_Quarc_LQI_DW.HILInitialize_AOMinimums[0],
         &State_Space_Quarc_LQI_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(State_Space_Quarc_LQI_M, _rt_error_message);
        return;
      }
    }

    if ((State_Space_Quarc_LQI_P.HILInitialize_AOStart && !is_switching) ||
        (State_Space_Quarc_LQI_P.HILInitialize_AOEnter && is_switching)) {
      State_Space_Quarc_LQI_DW.HILInitialize_AOVoltages[0] =
        State_Space_Quarc_LQI_P.HILInitialize_AOInitial;
      State_Space_Quarc_LQI_DW.HILInitialize_AOVoltages[1] =
        State_Space_Quarc_LQI_P.HILInitialize_AOInitial;
      result = hil_write_analog(State_Space_Quarc_LQI_DW.HILInitialize_Card,
        State_Space_Quarc_LQI_P.HILInitialize_AOChannels, 2U,
        &State_Space_Quarc_LQI_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(State_Space_Quarc_LQI_M, _rt_error_message);
        return;
      }
    }

    if (State_Space_Quarc_LQI_P.HILInitialize_AOReset) {
      State_Space_Quarc_LQI_DW.HILInitialize_AOVoltages[0] =
        State_Space_Quarc_LQI_P.HILInitialize_AOWatchdog;
      State_Space_Quarc_LQI_DW.HILInitialize_AOVoltages[1] =
        State_Space_Quarc_LQI_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (State_Space_Quarc_LQI_DW.HILInitialize_Card,
         State_Space_Quarc_LQI_P.HILInitialize_AOChannels, 2U,
         &State_Space_Quarc_LQI_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(State_Space_Quarc_LQI_M, _rt_error_message);
        return;
      }
    }

    if ((State_Space_Quarc_LQI_P.HILInitialize_EIPStart && !is_switching) ||
        (State_Space_Quarc_LQI_P.HILInitialize_EIPEnter && is_switching)) {
      State_Space_Quarc_LQI_DW.HILInitialize_QuadratureModes[0] =
        State_Space_Quarc_LQI_P.HILInitialize_EIQuadrature;
      State_Space_Quarc_LQI_DW.HILInitialize_QuadratureModes[1] =
        State_Space_Quarc_LQI_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (State_Space_Quarc_LQI_DW.HILInitialize_Card,
         State_Space_Quarc_LQI_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &State_Space_Quarc_LQI_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(State_Space_Quarc_LQI_M, _rt_error_message);
        return;
      }
    }

    if ((State_Space_Quarc_LQI_P.HILInitialize_EIStart && !is_switching) ||
        (State_Space_Quarc_LQI_P.HILInitialize_EIEnter && is_switching)) {
      State_Space_Quarc_LQI_DW.HILInitialize_InitialEICounts[0] =
        State_Space_Quarc_LQI_P.HILInitialize_EIInitial;
      State_Space_Quarc_LQI_DW.HILInitialize_InitialEICounts[1] =
        State_Space_Quarc_LQI_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts
        (State_Space_Quarc_LQI_DW.HILInitialize_Card,
         State_Space_Quarc_LQI_P.HILInitialize_EIChannels, 2U,
         &State_Space_Quarc_LQI_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(State_Space_Quarc_LQI_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  State_Space_Quarc_LQI_DW.DiscreteTimeIntegrator_DSTATE =
    State_Space_Quarc_LQI_P.DiscreteTimeIntegrator_IC;
}

/* Model terminate function */
void State_Space_Quarc_LQI_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: State_Space_Quarc_LQI/Motor/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(State_Space_Quarc_LQI_DW.HILInitialize_Card);
    hil_monitor_stop_all(State_Space_Quarc_LQI_DW.HILInitialize_Card);
    is_switching = false;
    if ((State_Space_Quarc_LQI_P.HILInitialize_AOTerminate && !is_switching) ||
        (State_Space_Quarc_LQI_P.HILInitialize_AOExit && is_switching)) {
      State_Space_Quarc_LQI_DW.HILInitialize_AOVoltages[0] =
        State_Space_Quarc_LQI_P.HILInitialize_AOFinal;
      State_Space_Quarc_LQI_DW.HILInitialize_AOVoltages[1] =
        State_Space_Quarc_LQI_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(State_Space_Quarc_LQI_DW.HILInitialize_Card,
        State_Space_Quarc_LQI_P.HILInitialize_AOChannels,
        num_final_analog_outputs,
        &State_Space_Quarc_LQI_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(State_Space_Quarc_LQI_M, _rt_error_message);
      }
    }

    hil_task_delete_all(State_Space_Quarc_LQI_DW.HILInitialize_Card);
    hil_monitor_delete_all(State_Space_Quarc_LQI_DW.HILInitialize_Card);
    hil_close(State_Space_Quarc_LQI_DW.HILInitialize_Card);
    State_Space_Quarc_LQI_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  State_Space_Quarc_LQI_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  State_Space_Quarc_LQI_update();
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
  State_Space_Quarc_LQI_initialize();
}

void MdlTerminate(void)
{
  State_Space_Quarc_LQI_terminate();
}

/* Registration function */
RT_MODEL_State_Space_Quarc_LQ_T *State_Space_Quarc_LQI(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)State_Space_Quarc_LQI_M, 0,
                sizeof(RT_MODEL_State_Space_Quarc_LQ_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&State_Space_Quarc_LQI_M->solverInfo,
                          &State_Space_Quarc_LQI_M->Timing.simTimeStep);
    rtsiSetTPtr(&State_Space_Quarc_LQI_M->solverInfo, &rtmGetTPtr
                (State_Space_Quarc_LQI_M));
    rtsiSetStepSizePtr(&State_Space_Quarc_LQI_M->solverInfo,
                       &State_Space_Quarc_LQI_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&State_Space_Quarc_LQI_M->solverInfo,
                          (&rtmGetErrorStatus(State_Space_Quarc_LQI_M)));
    rtsiSetRTModelPtr(&State_Space_Quarc_LQI_M->solverInfo,
                      State_Space_Quarc_LQI_M);
  }

  rtsiSetSimTimeStep(&State_Space_Quarc_LQI_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&State_Space_Quarc_LQI_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = State_Space_Quarc_LQI_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    State_Space_Quarc_LQI_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    State_Space_Quarc_LQI_M->Timing.sampleTimes =
      (&State_Space_Quarc_LQI_M->Timing.sampleTimesArray[0]);
    State_Space_Quarc_LQI_M->Timing.offsetTimes =
      (&State_Space_Quarc_LQI_M->Timing.offsetTimesArray[0]);

    /* task periods */
    State_Space_Quarc_LQI_M->Timing.sampleTimes[0] = (0.0);
    State_Space_Quarc_LQI_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    State_Space_Quarc_LQI_M->Timing.offsetTimes[0] = (0.0);
    State_Space_Quarc_LQI_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(State_Space_Quarc_LQI_M, &State_Space_Quarc_LQI_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = State_Space_Quarc_LQI_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    State_Space_Quarc_LQI_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(State_Space_Quarc_LQI_M, 19.998);
  State_Space_Quarc_LQI_M->Timing.stepSize0 = 0.002;
  State_Space_Quarc_LQI_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  State_Space_Quarc_LQI_M->Sizes.checksums[0] = (838232873U);
  State_Space_Quarc_LQI_M->Sizes.checksums[1] = (1131556436U);
  State_Space_Quarc_LQI_M->Sizes.checksums[2] = (1213952622U);
  State_Space_Quarc_LQI_M->Sizes.checksums[3] = (1603640715U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    State_Space_Quarc_LQI_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(State_Space_Quarc_LQI_M->extModeInfo,
      &State_Space_Quarc_LQI_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(State_Space_Quarc_LQI_M->extModeInfo,
                        State_Space_Quarc_LQI_M->Sizes.checksums);
    rteiSetTPtr(State_Space_Quarc_LQI_M->extModeInfo, rtmGetTPtr
                (State_Space_Quarc_LQI_M));
  }

  State_Space_Quarc_LQI_M->solverInfoPtr = (&State_Space_Quarc_LQI_M->solverInfo);
  State_Space_Quarc_LQI_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&State_Space_Quarc_LQI_M->solverInfo, 0.002);
  rtsiSetSolverMode(&State_Space_Quarc_LQI_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  State_Space_Quarc_LQI_M->blockIO = ((void *) &State_Space_Quarc_LQI_B);

  {
    State_Space_Quarc_LQI_B.ServoCountstoRad = 0.0;
    State_Space_Quarc_LQI_B.TachDir = 0.0;
    State_Space_Quarc_LQI_B.Step = 0.0;
    State_Space_Quarc_LQI_B.Sum1 = 0.0;
    State_Space_Quarc_LQI_B.Clock = 0.0;
    State_Space_Quarc_LQI_B.DeadZone = 0.0;
  }

  /* parameters */
  State_Space_Quarc_LQI_M->defaultParam = ((real_T *)&State_Space_Quarc_LQI_P);

  /* states (dwork) */
  State_Space_Quarc_LQI_M->dwork = ((void *) &State_Space_Quarc_LQI_DW);
  (void) memset((void *)&State_Space_Quarc_LQI_DW, 0,
                sizeof(DW_State_Space_Quarc_LQI_T));
  State_Space_Quarc_LQI_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  State_Space_Quarc_LQI_DW.HILInitialize_AIMinimums[0] = 0.0;
  State_Space_Quarc_LQI_DW.HILInitialize_AIMinimums[1] = 0.0;
  State_Space_Quarc_LQI_DW.HILInitialize_AIMaximums[0] = 0.0;
  State_Space_Quarc_LQI_DW.HILInitialize_AIMaximums[1] = 0.0;
  State_Space_Quarc_LQI_DW.HILInitialize_AOMinimums[0] = 0.0;
  State_Space_Quarc_LQI_DW.HILInitialize_AOMinimums[1] = 0.0;
  State_Space_Quarc_LQI_DW.HILInitialize_AOMaximums[0] = 0.0;
  State_Space_Quarc_LQI_DW.HILInitialize_AOMaximums[1] = 0.0;
  State_Space_Quarc_LQI_DW.HILInitialize_AOVoltages[0] = 0.0;
  State_Space_Quarc_LQI_DW.HILInitialize_AOVoltages[1] = 0.0;
  State_Space_Quarc_LQI_DW.HILInitialize_FilterFrequency[0] = 0.0;
  State_Space_Quarc_LQI_DW.HILInitialize_FilterFrequency[1] = 0.0;
  State_Space_Quarc_LQI_DW.HILReadAnalog_Buffer = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    State_Space_Quarc_LQI_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  State_Space_Quarc_LQI_M->Sizes.numContStates = (0);/* Number of continuous states */
  State_Space_Quarc_LQI_M->Sizes.numY = (0);/* Number of model outputs */
  State_Space_Quarc_LQI_M->Sizes.numU = (0);/* Number of model inputs */
  State_Space_Quarc_LQI_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  State_Space_Quarc_LQI_M->Sizes.numSampTimes = (2);/* Number of sample times */
  State_Space_Quarc_LQI_M->Sizes.numBlocks = (29);/* Number of blocks */
  State_Space_Quarc_LQI_M->Sizes.numBlockIO = (6);/* Number of block outputs */
  State_Space_Quarc_LQI_M->Sizes.numBlockPrms = (86);/* Sum of parameter "widths" */
  return State_Space_Quarc_LQI_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
