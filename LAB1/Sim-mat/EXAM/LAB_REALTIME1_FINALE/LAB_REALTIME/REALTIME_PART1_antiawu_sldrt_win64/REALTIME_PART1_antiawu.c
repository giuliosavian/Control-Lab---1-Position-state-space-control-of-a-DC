/*
 * REALTIME_PART1_antiawu.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "REALTIME_PART1_antiawu".
 *
 * Model version              : 1.29
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Jun  7 09:33:25 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "REALTIME_PART1_antiawu.h"
#include "REALTIME_PART1_antiawu_private.h"
#include "REALTIME_PART1_antiawu_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  2.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCI-6221", 4294967295U, 5, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_REALTIME_PART1_antiawu_T REALTIME_PART1_antiawu_B;

/* Continuous states */
X_REALTIME_PART1_antiawu_T REALTIME_PART1_antiawu_X;

/* Block states (default storage) */
DW_REALTIME_PART1_antiawu_T REALTIME_PART1_antiawu_DW;

/* Real-time model */
static RT_MODEL_REALTIME_PART1_antiawu_T REALTIME_PART1_antiawu_M_;
RT_MODEL_REALTIME_PART1_antiawu_T *const REALTIME_PART1_antiawu_M =
  &REALTIME_PART1_antiawu_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  REALTIME_PART1_antiawu_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  REALTIME_PART1_antiawu_output();
  REALTIME_PART1_antiawu_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  REALTIME_PART1_antiawu_output();
  REALTIME_PART1_antiawu_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void REALTIME_PART1_antiawu_output(void)
{
  /* local block i/o variables */
  real_T rtb_EncoderInput;
  real_T rtb_Saturation1;
  real_T rtb_Sum2;
  real_T rtb_deg2rad_tmp;
  if (rtmIsMajorTimeStep(REALTIME_PART1_antiawu_M)) {
    /* set solver stop time */
    if (!(REALTIME_PART1_antiawu_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&REALTIME_PART1_antiawu_M->solverInfo,
                            ((REALTIME_PART1_antiawu_M->Timing.clockTickH0 + 1) *
        REALTIME_PART1_antiawu_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&REALTIME_PART1_antiawu_M->solverInfo,
                            ((REALTIME_PART1_antiawu_M->Timing.clockTick0 + 1) *
        REALTIME_PART1_antiawu_M->Timing.stepSize0 +
        REALTIME_PART1_antiawu_M->Timing.clockTickH0 *
        REALTIME_PART1_antiawu_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(REALTIME_PART1_antiawu_M)) {
    REALTIME_PART1_antiawu_M->Timing.t[0] = rtsiGetT
      (&REALTIME_PART1_antiawu_M->solverInfo);
  }

  /* Step: '<Root>/Step' */
  if (REALTIME_PART1_antiawu_M->Timing.t[0] < REALTIME_PART1_antiawu_P.Step_Time)
  {
    /* Step: '<Root>/Step' */
    REALTIME_PART1_antiawu_B.Step = REALTIME_PART1_antiawu_P.Step_Y0;
  } else {
    /* Step: '<Root>/Step' */
    REALTIME_PART1_antiawu_B.Step = REALTIME_PART1_antiawu_P.step_size;
  }

  /* End of Step: '<Root>/Step' */
  if (rtmIsMajorTimeStep(REALTIME_PART1_antiawu_M)) {
    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = REALTIME_PART1_antiawu_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &REALTIME_PART1_antiawu_P.EncoderInput_Channels,
                     &rtb_EncoderInput, &parm);
    }

    /* Gain: '<Root>/pulse2deg' */
    REALTIME_PART1_antiawu_B.pulse2deg =
      REALTIME_PART1_antiawu_P.sens.enc.pulse2deg * rtb_EncoderInput;
  }

  /* Gain: '<S1>/deg2rad' incorporates:
   *  Gain: '<S1>/deg2rad1'
   *  Sum: '<Root>/Sum1'
   */
  rtb_deg2rad_tmp = REALTIME_PART1_antiawu_P.deg2rad *
    (REALTIME_PART1_antiawu_B.Step - REALTIME_PART1_antiawu_B.pulse2deg);

  /* Gain: '<S1>/derivative gain' incorporates:
   *  Gain: '<S1>/deg2rad'
   */
  REALTIME_PART1_antiawu_B.derivativegain = REALTIME_PART1_antiawu_P.ctrl.Kd *
    rtb_deg2rad_tmp;

  /* Gain: '<S1>/derivative gain1' */
  REALTIME_PART1_antiawu_B.derivativegain1 = REALTIME_PART1_antiawu_P.ctrl.Kd *
    rtb_deg2rad_tmp;

  /* Sum: '<S1>/Sum2' incorporates:
   *  Gain: '<S1>/proportional gain1'
   *  Integrator: '<S1>/Integrator1'
   *  TransferFcn: '<S1>/Real Derivative1'
   */
  rtb_Sum2 = ((REALTIME_PART1_antiawu_P.RealDerivative1_C *
               REALTIME_PART1_antiawu_X.RealDerivative1_CSTATE +
               REALTIME_PART1_antiawu_P.RealDerivative1_D *
               REALTIME_PART1_antiawu_B.derivativegain1) +
              REALTIME_PART1_antiawu_P.ctrl.Kp * rtb_deg2rad_tmp) +
    REALTIME_PART1_antiawu_X.Integrator1_CSTATE;

  /* Saturate: '<S1>/Saturation1' */
  if (rtb_Sum2 > REALTIME_PART1_antiawu_P.Saturation1_UpperSat) {
    rtb_Saturation1 = REALTIME_PART1_antiawu_P.Saturation1_UpperSat;
  } else if (rtb_Sum2 < REALTIME_PART1_antiawu_P.Saturation1_LowerSat) {
    rtb_Saturation1 = REALTIME_PART1_antiawu_P.Saturation1_LowerSat;
  } else {
    rtb_Saturation1 = rtb_Sum2;
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* ManualSwitch: '<Root>/Manual Switch' */
  if (REALTIME_PART1_antiawu_P.ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Gain: '<S1>/deg2rad'
     *  Gain: '<S1>/proportional gain'
     *  Integrator: '<S1>/Integrator'
     *  Sum: '<S1>/Sum'
     *  TransferFcn: '<S1>/Real Derivative'
     */
    REALTIME_PART1_antiawu_B.ManualSwitch =
      ((REALTIME_PART1_antiawu_P.RealDerivative_C *
        REALTIME_PART1_antiawu_X.RealDerivative_CSTATE +
        REALTIME_PART1_antiawu_P.RealDerivative_D *
        REALTIME_PART1_antiawu_B.derivativegain) +
       REALTIME_PART1_antiawu_P.ctrl.Kp * rtb_deg2rad_tmp) +
      REALTIME_PART1_antiawu_X.Integrator_CSTATE;
  } else {
    /* ManualSwitch: '<Root>/Manual Switch' */
    REALTIME_PART1_antiawu_B.ManualSwitch = rtb_Saturation1;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */
  if (rtmIsMajorTimeStep(REALTIME_PART1_antiawu_M)) {
    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) REALTIME_PART1_antiawu_P.AnalogOutput_RangeMode;
        parm.rangeidx = REALTIME_PART1_antiawu_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &REALTIME_PART1_antiawu_P.AnalogOutput_Channels, ((real_T*)
          (&REALTIME_PART1_antiawu_B.ManualSwitch)), &parm);
      }
    }
  }

  /* Gain: '<Root>/degs2rpm' incorporates:
   *  TransferFcn: '<Root>/Speed Filter'
   */
  REALTIME_PART1_antiawu_B.wlrpm = (REALTIME_PART1_antiawu_P.SpeedFilter_C[0] *
    REALTIME_PART1_antiawu_X.SpeedFilter_CSTATE[0] +
    REALTIME_PART1_antiawu_P.SpeedFilter_C[1] *
    REALTIME_PART1_antiawu_X.SpeedFilter_CSTATE[1]) *
    REALTIME_PART1_antiawu_P.degs2rpm;

  /* TransferFcn: '<Root>/Acceleration Filter' */
  REALTIME_PART1_antiawu_B.accrpms = 0.0;
  REALTIME_PART1_antiawu_B.accrpms +=
    REALTIME_PART1_antiawu_P.AccelerationFilter_C[0] *
    REALTIME_PART1_antiawu_X.AccelerationFilter_CSTATE[0];
  REALTIME_PART1_antiawu_B.accrpms +=
    REALTIME_PART1_antiawu_P.AccelerationFilter_C[1] *
    REALTIME_PART1_antiawu_X.AccelerationFilter_CSTATE[1];
  if (rtmIsMajorTimeStep(REALTIME_PART1_antiawu_M)) {
  }

  /* Sum: '<S1>/Sum5' incorporates:
   *  Gain: '<S1>/K_w'
   *  Gain: '<S1>/integral gain1'
   *  Sum: '<S1>/Sum4'
   */
  REALTIME_PART1_antiawu_B.Sum5 = REALTIME_PART1_antiawu_P.ctrl.Ki *
    rtb_deg2rad_tmp - (rtb_Sum2 - rtb_Saturation1) *
    REALTIME_PART1_antiawu_P.ctrl.Kw;

  /* Gain: '<S1>/integral gain' incorporates:
   *  Gain: '<S1>/deg2rad'
   */
  REALTIME_PART1_antiawu_B.integralgain = REALTIME_PART1_antiawu_P.ctrl.Ki *
    rtb_deg2rad_tmp;
}

/* Model update function */
void REALTIME_PART1_antiawu_update(void)
{
  if (rtmIsMajorTimeStep(REALTIME_PART1_antiawu_M)) {
    rt_ertODEUpdateContinuousStates(&REALTIME_PART1_antiawu_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++REALTIME_PART1_antiawu_M->Timing.clockTick0)) {
    ++REALTIME_PART1_antiawu_M->Timing.clockTickH0;
  }

  REALTIME_PART1_antiawu_M->Timing.t[0] = rtsiGetSolverStopTime
    (&REALTIME_PART1_antiawu_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++REALTIME_PART1_antiawu_M->Timing.clockTick1)) {
      ++REALTIME_PART1_antiawu_M->Timing.clockTickH1;
    }

    REALTIME_PART1_antiawu_M->Timing.t[1] =
      REALTIME_PART1_antiawu_M->Timing.clockTick1 *
      REALTIME_PART1_antiawu_M->Timing.stepSize1 +
      REALTIME_PART1_antiawu_M->Timing.clockTickH1 *
      REALTIME_PART1_antiawu_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void REALTIME_PART1_antiawu_derivatives(void)
{
  XDot_REALTIME_PART1_antiawu_T *_rtXdot;
  _rtXdot = ((XDot_REALTIME_PART1_antiawu_T *) REALTIME_PART1_antiawu_M->derivs);

  /* Derivatives for TransferFcn: '<S1>/Real Derivative' */
  _rtXdot->RealDerivative_CSTATE = 0.0;
  _rtXdot->RealDerivative_CSTATE += REALTIME_PART1_antiawu_P.RealDerivative_A *
    REALTIME_PART1_antiawu_X.RealDerivative_CSTATE;
  _rtXdot->RealDerivative_CSTATE += REALTIME_PART1_antiawu_B.derivativegain;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = REALTIME_PART1_antiawu_B.integralgain;

  /* Derivatives for TransferFcn: '<S1>/Real Derivative1' */
  _rtXdot->RealDerivative1_CSTATE = 0.0;
  _rtXdot->RealDerivative1_CSTATE += REALTIME_PART1_antiawu_P.RealDerivative1_A *
    REALTIME_PART1_antiawu_X.RealDerivative1_CSTATE;
  _rtXdot->RealDerivative1_CSTATE += REALTIME_PART1_antiawu_B.derivativegain1;

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = REALTIME_PART1_antiawu_B.Sum5;

  /* Derivatives for TransferFcn: '<Root>/Speed Filter' */
  _rtXdot->SpeedFilter_CSTATE[0] = 0.0;
  _rtXdot->SpeedFilter_CSTATE[0] += REALTIME_PART1_antiawu_P.SpeedFilter_A[0] *
    REALTIME_PART1_antiawu_X.SpeedFilter_CSTATE[0];
  _rtXdot->SpeedFilter_CSTATE[1] = 0.0;
  _rtXdot->SpeedFilter_CSTATE[0] += REALTIME_PART1_antiawu_P.SpeedFilter_A[1] *
    REALTIME_PART1_antiawu_X.SpeedFilter_CSTATE[1];
  _rtXdot->SpeedFilter_CSTATE[1] += REALTIME_PART1_antiawu_X.SpeedFilter_CSTATE
    [0];
  _rtXdot->SpeedFilter_CSTATE[0] += REALTIME_PART1_antiawu_B.pulse2deg;

  /* Derivatives for TransferFcn: '<Root>/Acceleration Filter' */
  _rtXdot->AccelerationFilter_CSTATE[0] = 0.0;
  _rtXdot->AccelerationFilter_CSTATE[0] +=
    REALTIME_PART1_antiawu_P.AccelerationFilter_A[0] *
    REALTIME_PART1_antiawu_X.AccelerationFilter_CSTATE[0];
  _rtXdot->AccelerationFilter_CSTATE[1] = 0.0;
  _rtXdot->AccelerationFilter_CSTATE[0] +=
    REALTIME_PART1_antiawu_P.AccelerationFilter_A[1] *
    REALTIME_PART1_antiawu_X.AccelerationFilter_CSTATE[1];
  _rtXdot->AccelerationFilter_CSTATE[1] +=
    REALTIME_PART1_antiawu_X.AccelerationFilter_CSTATE[0];
  _rtXdot->AccelerationFilter_CSTATE[0] += REALTIME_PART1_antiawu_B.wlrpm;
}

/* Model initialize function */
void REALTIME_PART1_antiawu_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) REALTIME_PART1_antiawu_P.AnalogOutput_RangeMode;
      parm.rangeidx = REALTIME_PART1_antiawu_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &REALTIME_PART1_antiawu_P.AnalogOutput_Channels,
                     &REALTIME_PART1_antiawu_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = REALTIME_PART1_antiawu_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &REALTIME_PART1_antiawu_P.EncoderInput_Channels, NULL, &parm);
  }

  /* InitializeConditions for TransferFcn: '<S1>/Real Derivative' */
  REALTIME_PART1_antiawu_X.RealDerivative_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  REALTIME_PART1_antiawu_X.Integrator_CSTATE =
    REALTIME_PART1_antiawu_P.Integrator_IC;

  /* InitializeConditions for TransferFcn: '<S1>/Real Derivative1' */
  REALTIME_PART1_antiawu_X.RealDerivative1_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  REALTIME_PART1_antiawu_X.Integrator1_CSTATE =
    REALTIME_PART1_antiawu_P.Integrator1_IC;

  /* InitializeConditions for TransferFcn: '<Root>/Speed Filter' */
  REALTIME_PART1_antiawu_X.SpeedFilter_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Acceleration Filter' */
  REALTIME_PART1_antiawu_X.AccelerationFilter_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Speed Filter' */
  REALTIME_PART1_antiawu_X.SpeedFilter_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Acceleration Filter' */
  REALTIME_PART1_antiawu_X.AccelerationFilter_CSTATE[1] = 0.0;
}

/* Model terminate function */
void REALTIME_PART1_antiawu_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) REALTIME_PART1_antiawu_P.AnalogOutput_RangeMode;
      parm.rangeidx = REALTIME_PART1_antiawu_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &REALTIME_PART1_antiawu_P.AnalogOutput_Channels,
                     &REALTIME_PART1_antiawu_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  REALTIME_PART1_antiawu_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  REALTIME_PART1_antiawu_update();
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
  REALTIME_PART1_antiawu_initialize();
}

void MdlTerminate(void)
{
  REALTIME_PART1_antiawu_terminate();
}

/* Registration function */
RT_MODEL_REALTIME_PART1_antiawu_T *REALTIME_PART1_antiawu(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  REALTIME_PART1_antiawu_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)REALTIME_PART1_antiawu_M, 0,
                sizeof(RT_MODEL_REALTIME_PART1_antiawu_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&REALTIME_PART1_antiawu_M->solverInfo,
                          &REALTIME_PART1_antiawu_M->Timing.simTimeStep);
    rtsiSetTPtr(&REALTIME_PART1_antiawu_M->solverInfo, &rtmGetTPtr
                (REALTIME_PART1_antiawu_M));
    rtsiSetStepSizePtr(&REALTIME_PART1_antiawu_M->solverInfo,
                       &REALTIME_PART1_antiawu_M->Timing.stepSize0);
    rtsiSetdXPtr(&REALTIME_PART1_antiawu_M->solverInfo,
                 &REALTIME_PART1_antiawu_M->derivs);
    rtsiSetContStatesPtr(&REALTIME_PART1_antiawu_M->solverInfo, (real_T **)
                         &REALTIME_PART1_antiawu_M->contStates);
    rtsiSetNumContStatesPtr(&REALTIME_PART1_antiawu_M->solverInfo,
      &REALTIME_PART1_antiawu_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&REALTIME_PART1_antiawu_M->solverInfo,
      &REALTIME_PART1_antiawu_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&REALTIME_PART1_antiawu_M->solverInfo,
      &REALTIME_PART1_antiawu_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&REALTIME_PART1_antiawu_M->solverInfo,
      &REALTIME_PART1_antiawu_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&REALTIME_PART1_antiawu_M->solverInfo,
                          (&rtmGetErrorStatus(REALTIME_PART1_antiawu_M)));
    rtsiSetRTModelPtr(&REALTIME_PART1_antiawu_M->solverInfo,
                      REALTIME_PART1_antiawu_M);
  }

  rtsiSetSimTimeStep(&REALTIME_PART1_antiawu_M->solverInfo, MAJOR_TIME_STEP);
  REALTIME_PART1_antiawu_M->intgData.y = REALTIME_PART1_antiawu_M->odeY;
  REALTIME_PART1_antiawu_M->intgData.f[0] = REALTIME_PART1_antiawu_M->odeF[0];
  REALTIME_PART1_antiawu_M->intgData.f[1] = REALTIME_PART1_antiawu_M->odeF[1];
  REALTIME_PART1_antiawu_M->intgData.f[2] = REALTIME_PART1_antiawu_M->odeF[2];
  REALTIME_PART1_antiawu_M->contStates = ((real_T *) &REALTIME_PART1_antiawu_X);
  rtsiSetSolverData(&REALTIME_PART1_antiawu_M->solverInfo, (void *)
                    &REALTIME_PART1_antiawu_M->intgData);
  rtsiSetSolverName(&REALTIME_PART1_antiawu_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = REALTIME_PART1_antiawu_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    REALTIME_PART1_antiawu_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    REALTIME_PART1_antiawu_M->Timing.sampleTimes =
      (&REALTIME_PART1_antiawu_M->Timing.sampleTimesArray[0]);
    REALTIME_PART1_antiawu_M->Timing.offsetTimes =
      (&REALTIME_PART1_antiawu_M->Timing.offsetTimesArray[0]);

    /* task periods */
    REALTIME_PART1_antiawu_M->Timing.sampleTimes[0] = (0.0);
    REALTIME_PART1_antiawu_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    REALTIME_PART1_antiawu_M->Timing.offsetTimes[0] = (0.0);
    REALTIME_PART1_antiawu_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(REALTIME_PART1_antiawu_M, &REALTIME_PART1_antiawu_M->Timing.tArray
             [0]);

  {
    int_T *mdlSampleHits = REALTIME_PART1_antiawu_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    REALTIME_PART1_antiawu_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(REALTIME_PART1_antiawu_M, 5.0);
  REALTIME_PART1_antiawu_M->Timing.stepSize0 = 0.001;
  REALTIME_PART1_antiawu_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  REALTIME_PART1_antiawu_M->Sizes.checksums[0] = (1279378230U);
  REALTIME_PART1_antiawu_M->Sizes.checksums[1] = (612474177U);
  REALTIME_PART1_antiawu_M->Sizes.checksums[2] = (2278622547U);
  REALTIME_PART1_antiawu_M->Sizes.checksums[3] = (2694630852U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    REALTIME_PART1_antiawu_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(REALTIME_PART1_antiawu_M->extModeInfo,
      &REALTIME_PART1_antiawu_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(REALTIME_PART1_antiawu_M->extModeInfo,
                        REALTIME_PART1_antiawu_M->Sizes.checksums);
    rteiSetTPtr(REALTIME_PART1_antiawu_M->extModeInfo, rtmGetTPtr
                (REALTIME_PART1_antiawu_M));
  }

  REALTIME_PART1_antiawu_M->solverInfoPtr =
    (&REALTIME_PART1_antiawu_M->solverInfo);
  REALTIME_PART1_antiawu_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&REALTIME_PART1_antiawu_M->solverInfo, 0.001);
  rtsiSetSolverMode(&REALTIME_PART1_antiawu_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  REALTIME_PART1_antiawu_M->blockIO = ((void *) &REALTIME_PART1_antiawu_B);
  (void) memset(((void *) &REALTIME_PART1_antiawu_B), 0,
                sizeof(B_REALTIME_PART1_antiawu_T));

  /* parameters */
  REALTIME_PART1_antiawu_M->defaultParam = ((real_T *)&REALTIME_PART1_antiawu_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &REALTIME_PART1_antiawu_X;
    REALTIME_PART1_antiawu_M->contStates = (x);
    (void) memset((void *)&REALTIME_PART1_antiawu_X, 0,
                  sizeof(X_REALTIME_PART1_antiawu_T));
  }

  /* states (dwork) */
  REALTIME_PART1_antiawu_M->dwork = ((void *) &REALTIME_PART1_antiawu_DW);
  (void) memset((void *)&REALTIME_PART1_antiawu_DW, 0,
                sizeof(DW_REALTIME_PART1_antiawu_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    REALTIME_PART1_antiawu_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  REALTIME_PART1_antiawu_M->Sizes.numContStates = (8);/* Number of continuous states */
  REALTIME_PART1_antiawu_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  REALTIME_PART1_antiawu_M->Sizes.numY = (0);/* Number of model outputs */
  REALTIME_PART1_antiawu_M->Sizes.numU = (0);/* Number of model inputs */
  REALTIME_PART1_antiawu_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  REALTIME_PART1_antiawu_M->Sizes.numSampTimes = (2);/* Number of sample times */
  REALTIME_PART1_antiawu_M->Sizes.numBlocks = (29);/* Number of blocks */
  REALTIME_PART1_antiawu_M->Sizes.numBlockIO = (9);/* Number of block outputs */
  REALTIME_PART1_antiawu_M->Sizes.numBlockPrms = (37);/* Sum of parameter "widths" */
  return REALTIME_PART1_antiawu_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
