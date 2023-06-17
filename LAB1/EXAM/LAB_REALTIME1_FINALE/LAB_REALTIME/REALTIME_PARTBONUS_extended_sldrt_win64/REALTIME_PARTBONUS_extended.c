/*
 * REALTIME_PARTBONUS_extended.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "REALTIME_PARTBONUS_extended".
 *
 * Model version              : 1.32
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Apr 19 10:30:35 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "REALTIME_PARTBONUS_extended.h"
#include "REALTIME_PARTBONUS_extended_private.h"
#include "REALTIME_PARTBONUS_extended_dt.h"

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
B_REALTIME_PARTBONUS_extended_T REALTIME_PARTBONUS_extended_B;

/* Continuous states */
X_REALTIME_PARTBONUS_extended_T REALTIME_PARTBONUS_extended_X;

/* Block states (default storage) */
DW_REALTIME_PARTBONUS_extended_T REALTIME_PARTBONUS_extended_DW;

/* Real-time model */
static RT_MODEL_REALTIME_PARTBONUS_extended_T REALTIME_PARTBONUS_extended_M_;
RT_MODEL_REALTIME_PARTBONUS_extended_T *const REALTIME_PARTBONUS_extended_M =
  &REALTIME_PARTBONUS_extended_M_;

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
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  REALTIME_PARTBONUS_extended_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  REALTIME_PARTBONUS_extended_output();
  REALTIME_PARTBONUS_extended_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  REALTIME_PARTBONUS_extended_output();
  REALTIME_PARTBONUS_extended_derivatives();

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
void REALTIME_PARTBONUS_extended_output(void)
{
  /* local block i/o variables */
  real_T rtb_EncoderInput1;
  real_T rtb_StateSpace[5];
  real_T u0;
  int_T ci;
  int_T iy;
  if (rtmIsMajorTimeStep(REALTIME_PARTBONUS_extended_M)) {
    /* set solver stop time */
    if (!(REALTIME_PARTBONUS_extended_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&REALTIME_PARTBONUS_extended_M->solverInfo,
                            ((REALTIME_PARTBONUS_extended_M->Timing.clockTickH0
        + 1) * REALTIME_PARTBONUS_extended_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&REALTIME_PARTBONUS_extended_M->solverInfo,
                            ((REALTIME_PARTBONUS_extended_M->Timing.clockTick0 +
        1) * REALTIME_PARTBONUS_extended_M->Timing.stepSize0 +
        REALTIME_PARTBONUS_extended_M->Timing.clockTickH0 *
        REALTIME_PARTBONUS_extended_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(REALTIME_PARTBONUS_extended_M)) {
    REALTIME_PARTBONUS_extended_M->Timing.t[0] = rtsiGetT
      (&REALTIME_PARTBONUS_extended_M->solverInfo);
  }

  /* StateSpace: '<S1>/State-Space' */
  for (iy = 0; iy < 5; iy++) {
    rtb_StateSpace[iy] = 0.0;
  }

  for (ci = 0; ci < 5; ci++) {
    for (iy = 0; iy < 5; iy++) {
      rtb_StateSpace[iy] += REALTIME_PARTBONUS_extended_P.Cest[ci * 5 + iy] *
        REALTIME_PARTBONUS_extended_X.StateSpace_CSTATE[ci];
    }
  }

  /* End of StateSpace: '<S1>/State-Space' */

  /* Gain: '<S1>/rad2deg' */
  REALTIME_PARTBONUS_extended_B.rad2deg = REALTIME_PARTBONUS_extended_P.rad2deg *
    rtb_StateSpace[3];

  /* Gain: '<S1>/rads2rpm' */
  REALTIME_PARTBONUS_extended_B.rads2rpm =
    REALTIME_PARTBONUS_extended_P.rads2rpm * rtb_StateSpace[4];

  /* Sum: '<S2>/Sum1' incorporates:
   *  Gain: '<S2>/Cp_matrixGain'
   *  Gain: '<S2>/State feedback'
   *  Gain: '<S2>/deg2rads'
   *  Gain: '<S2>/rpm2rads'
   */
  u0 = (0.0 - ((rtb_StateSpace[0] *
                REALTIME_PARTBONUS_extended_P.Cp_matrixGain_Gain[0] +
                rtb_StateSpace[1] *
                REALTIME_PARTBONUS_extended_P.Cp_matrixGain_Gain[1]) +
               rtb_StateSpace[2] *
               REALTIME_PARTBONUS_extended_P.Cp_matrixGain_Gain[2])) -
    (REALTIME_PARTBONUS_extended_P.deg2rad *
     REALTIME_PARTBONUS_extended_B.rad2deg *
     REALTIME_PARTBONUS_extended_P.Statefeedback_Gain[0] +
     REALTIME_PARTBONUS_extended_P.rpm2rads *
     REALTIME_PARTBONUS_extended_B.rads2rpm *
     REALTIME_PARTBONUS_extended_P.Statefeedback_Gain[1]);

  /* Saturate: '<S2>/Saturation' */
  if (u0 > REALTIME_PARTBONUS_extended_P.Saturation_UpperSat) {
    /* Saturate: '<S2>/Saturation' */
    REALTIME_PARTBONUS_extended_B.Saturation =
      REALTIME_PARTBONUS_extended_P.Saturation_UpperSat;
  } else if (u0 < REALTIME_PARTBONUS_extended_P.Saturation_LowerSat) {
    /* Saturate: '<S2>/Saturation' */
    REALTIME_PARTBONUS_extended_B.Saturation =
      REALTIME_PARTBONUS_extended_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Saturation' */
    REALTIME_PARTBONUS_extended_B.Saturation = u0;
  }

  /* End of Saturate: '<S2>/Saturation' */
  if (rtmIsMajorTimeStep(REALTIME_PARTBONUS_extended_M)) {
    /* S-Function (sldrtao): '<Root>/Analog Output1' */
    /* S-Function Block: <Root>/Analog Output1 */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE)
          REALTIME_PARTBONUS_extended_P.AnalogOutput1_RangeMode;
        parm.rangeidx = REALTIME_PARTBONUS_extended_P.AnalogOutput1_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &REALTIME_PARTBONUS_extended_P.AnalogOutput1_Channels,
                       ((real_T*) (&REALTIME_PARTBONUS_extended_B.Saturation)),
                       &parm);
      }
    }
  }

  /* ManualSwitch: '<Root>/Manual Switch' */
  if (REALTIME_PARTBONUS_extended_P.ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Sin: '<Root>/Sine Wave'
     */
    REALTIME_PARTBONUS_extended_B.ManualSwitch = sin(6.2831853071795862 /
      REALTIME_PARTBONUS_extended_P.Tr * REALTIME_PARTBONUS_extended_M->
      Timing.t[0] + REALTIME_PARTBONUS_extended_P.SineWave_Phase) *
      REALTIME_PARTBONUS_extended_P.Ar +
      REALTIME_PARTBONUS_extended_P.SineWave_Bias;
  } else {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant'
     */
    REALTIME_PARTBONUS_extended_B.ManualSwitch =
      REALTIME_PARTBONUS_extended_P.Constant_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */
  if (rtmIsMajorTimeStep(REALTIME_PARTBONUS_extended_M)) {
    /* S-Function (sldrtei): '<Root>/Encoder Input1' */
    /* S-Function Block: <Root>/Encoder Input1 */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = REALTIME_PARTBONUS_extended_P.EncoderInput1_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &REALTIME_PARTBONUS_extended_P.EncoderInput1_Channels,
                     &rtb_EncoderInput1, &parm);
    }

    /* Gain: '<Root>/pulse2deg' */
    REALTIME_PARTBONUS_extended_B.thl_meas =
      REALTIME_PARTBONUS_extended_P.sens.enc.pulse2deg * rtb_EncoderInput1;
  }

  /* SignalConversion generated from: '<S1>/State-Space' incorporates:
   *  Gain: '<S1>/deg2rad'
   *  Sum: '<Root>/Sum2'
   */
  REALTIME_PARTBONUS_extended_B.TmpSignalConversionAtStateSpaceInport1[0] =
    REALTIME_PARTBONUS_extended_B.Saturation;
  REALTIME_PARTBONUS_extended_B.TmpSignalConversionAtStateSpaceInport1[1] =
    (REALTIME_PARTBONUS_extended_B.thl_meas -
     REALTIME_PARTBONUS_extended_B.ManualSwitch) *
    REALTIME_PARTBONUS_extended_P.deg2rad;
}

/* Model update function */
void REALTIME_PARTBONUS_extended_update(void)
{
  if (rtmIsMajorTimeStep(REALTIME_PARTBONUS_extended_M)) {
    rt_ertODEUpdateContinuousStates(&REALTIME_PARTBONUS_extended_M->solverInfo);
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
  if (!(++REALTIME_PARTBONUS_extended_M->Timing.clockTick0)) {
    ++REALTIME_PARTBONUS_extended_M->Timing.clockTickH0;
  }

  REALTIME_PARTBONUS_extended_M->Timing.t[0] = rtsiGetSolverStopTime
    (&REALTIME_PARTBONUS_extended_M->solverInfo);

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
    if (!(++REALTIME_PARTBONUS_extended_M->Timing.clockTick1)) {
      ++REALTIME_PARTBONUS_extended_M->Timing.clockTickH1;
    }

    REALTIME_PARTBONUS_extended_M->Timing.t[1] =
      REALTIME_PARTBONUS_extended_M->Timing.clockTick1 *
      REALTIME_PARTBONUS_extended_M->Timing.stepSize1 +
      REALTIME_PARTBONUS_extended_M->Timing.clockTickH1 *
      REALTIME_PARTBONUS_extended_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void REALTIME_PARTBONUS_extended_derivatives(void)
{
  XDot_REALTIME_PARTBONUS_extended_T *_rtXdot;
  int_T ci;
  int_T is;
  _rtXdot = ((XDot_REALTIME_PARTBONUS_extended_T *)
             REALTIME_PARTBONUS_extended_M->derivs);

  /* Derivatives for StateSpace: '<S1>/State-Space' */
  for (is = 0; is < 5; is++) {
    _rtXdot->StateSpace_CSTATE[is] = 0.0;
  }

  for (ci = 0; ci < 5; ci++) {
    for (is = 0; is < 5; is++) {
      _rtXdot->StateSpace_CSTATE[is] += REALTIME_PARTBONUS_extended_P.Aest[ci *
        5 + is] * REALTIME_PARTBONUS_extended_X.StateSpace_CSTATE[ci];
    }
  }

  for (ci = 0; ci < 2; ci++) {
    for (is = 0; is < 5; is++) {
      _rtXdot->StateSpace_CSTATE[is] += REALTIME_PARTBONUS_extended_P.Best[ci *
        5 + is] *
        REALTIME_PARTBONUS_extended_B.TmpSignalConversionAtStateSpaceInport1[ci];
    }
  }

  /* End of Derivatives for StateSpace: '<S1>/State-Space' */
}

/* Model initialize function */
void REALTIME_PARTBONUS_extended_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output1' */

  /* S-Function Block: <Root>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        REALTIME_PARTBONUS_extended_P.AnalogOutput1_RangeMode;
      parm.rangeidx = REALTIME_PARTBONUS_extended_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &REALTIME_PARTBONUS_extended_P.AnalogOutput1_Channels,
                     &REALTIME_PARTBONUS_extended_P.AnalogOutput1_InitialValue,
                     &parm);
    }
  }

  {
    int_T is;

    /* InitializeConditions for StateSpace: '<S1>/State-Space' */
    for (is = 0; is < 5; is++) {
      REALTIME_PARTBONUS_extended_X.StateSpace_CSTATE[is] =
        REALTIME_PARTBONUS_extended_P.StateSpace_InitialCondition;
    }

    /* End of InitializeConditions for StateSpace: '<S1>/State-Space' */

    /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input1' */

    /* S-Function Block: <Root>/Encoder Input1 */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = REALTIME_PARTBONUS_extended_P.EncoderInput1_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                     &REALTIME_PARTBONUS_extended_P.EncoderInput1_Channels, NULL,
                     &parm);
    }
  }
}

/* Model terminate function */
void REALTIME_PARTBONUS_extended_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output1' */

  /* S-Function Block: <Root>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        REALTIME_PARTBONUS_extended_P.AnalogOutput1_RangeMode;
      parm.rangeidx = REALTIME_PARTBONUS_extended_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &REALTIME_PARTBONUS_extended_P.AnalogOutput1_Channels,
                     &REALTIME_PARTBONUS_extended_P.AnalogOutput1_FinalValue,
                     &parm);
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
  REALTIME_PARTBONUS_extended_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  REALTIME_PARTBONUS_extended_update();
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
  REALTIME_PARTBONUS_extended_initialize();
}

void MdlTerminate(void)
{
  REALTIME_PARTBONUS_extended_terminate();
}

/* Registration function */
RT_MODEL_REALTIME_PARTBONUS_extended_T *REALTIME_PARTBONUS_extended(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  REALTIME_PARTBONUS_extended_P.EncoderInput1_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)REALTIME_PARTBONUS_extended_M, 0,
                sizeof(RT_MODEL_REALTIME_PARTBONUS_extended_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&REALTIME_PARTBONUS_extended_M->solverInfo,
                          &REALTIME_PARTBONUS_extended_M->Timing.simTimeStep);
    rtsiSetTPtr(&REALTIME_PARTBONUS_extended_M->solverInfo, &rtmGetTPtr
                (REALTIME_PARTBONUS_extended_M));
    rtsiSetStepSizePtr(&REALTIME_PARTBONUS_extended_M->solverInfo,
                       &REALTIME_PARTBONUS_extended_M->Timing.stepSize0);
    rtsiSetdXPtr(&REALTIME_PARTBONUS_extended_M->solverInfo,
                 &REALTIME_PARTBONUS_extended_M->derivs);
    rtsiSetContStatesPtr(&REALTIME_PARTBONUS_extended_M->solverInfo, (real_T **)
                         &REALTIME_PARTBONUS_extended_M->contStates);
    rtsiSetNumContStatesPtr(&REALTIME_PARTBONUS_extended_M->solverInfo,
      &REALTIME_PARTBONUS_extended_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&REALTIME_PARTBONUS_extended_M->solverInfo,
      &REALTIME_PARTBONUS_extended_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&REALTIME_PARTBONUS_extended_M->solverInfo,
       &REALTIME_PARTBONUS_extended_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&REALTIME_PARTBONUS_extended_M->solverInfo,
      &REALTIME_PARTBONUS_extended_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&REALTIME_PARTBONUS_extended_M->solverInfo,
                          (&rtmGetErrorStatus(REALTIME_PARTBONUS_extended_M)));
    rtsiSetRTModelPtr(&REALTIME_PARTBONUS_extended_M->solverInfo,
                      REALTIME_PARTBONUS_extended_M);
  }

  rtsiSetSimTimeStep(&REALTIME_PARTBONUS_extended_M->solverInfo, MAJOR_TIME_STEP);
  REALTIME_PARTBONUS_extended_M->intgData.y =
    REALTIME_PARTBONUS_extended_M->odeY;
  REALTIME_PARTBONUS_extended_M->intgData.f[0] =
    REALTIME_PARTBONUS_extended_M->odeF[0];
  REALTIME_PARTBONUS_extended_M->intgData.f[1] =
    REALTIME_PARTBONUS_extended_M->odeF[1];
  REALTIME_PARTBONUS_extended_M->intgData.f[2] =
    REALTIME_PARTBONUS_extended_M->odeF[2];
  REALTIME_PARTBONUS_extended_M->contStates = ((real_T *)
    &REALTIME_PARTBONUS_extended_X);
  rtsiSetSolverData(&REALTIME_PARTBONUS_extended_M->solverInfo, (void *)
                    &REALTIME_PARTBONUS_extended_M->intgData);
  rtsiSetSolverName(&REALTIME_PARTBONUS_extended_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      REALTIME_PARTBONUS_extended_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    REALTIME_PARTBONUS_extended_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    REALTIME_PARTBONUS_extended_M->Timing.sampleTimes =
      (&REALTIME_PARTBONUS_extended_M->Timing.sampleTimesArray[0]);
    REALTIME_PARTBONUS_extended_M->Timing.offsetTimes =
      (&REALTIME_PARTBONUS_extended_M->Timing.offsetTimesArray[0]);

    /* task periods */
    REALTIME_PARTBONUS_extended_M->Timing.sampleTimes[0] = (0.0);
    REALTIME_PARTBONUS_extended_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    REALTIME_PARTBONUS_extended_M->Timing.offsetTimes[0] = (0.0);
    REALTIME_PARTBONUS_extended_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(REALTIME_PARTBONUS_extended_M,
             &REALTIME_PARTBONUS_extended_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = REALTIME_PARTBONUS_extended_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    REALTIME_PARTBONUS_extended_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(REALTIME_PARTBONUS_extended_M, 5.0);
  REALTIME_PARTBONUS_extended_M->Timing.stepSize0 = 0.001;
  REALTIME_PARTBONUS_extended_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  REALTIME_PARTBONUS_extended_M->Sizes.checksums[0] = (2308754547U);
  REALTIME_PARTBONUS_extended_M->Sizes.checksums[1] = (3603525762U);
  REALTIME_PARTBONUS_extended_M->Sizes.checksums[2] = (3236981476U);
  REALTIME_PARTBONUS_extended_M->Sizes.checksums[3] = (151813276U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    REALTIME_PARTBONUS_extended_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(REALTIME_PARTBONUS_extended_M->extModeInfo,
      &REALTIME_PARTBONUS_extended_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(REALTIME_PARTBONUS_extended_M->extModeInfo,
                        REALTIME_PARTBONUS_extended_M->Sizes.checksums);
    rteiSetTPtr(REALTIME_PARTBONUS_extended_M->extModeInfo, rtmGetTPtr
                (REALTIME_PARTBONUS_extended_M));
  }

  REALTIME_PARTBONUS_extended_M->solverInfoPtr =
    (&REALTIME_PARTBONUS_extended_M->solverInfo);
  REALTIME_PARTBONUS_extended_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&REALTIME_PARTBONUS_extended_M->solverInfo, 0.001);
  rtsiSetSolverMode(&REALTIME_PARTBONUS_extended_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  REALTIME_PARTBONUS_extended_M->blockIO = ((void *)
    &REALTIME_PARTBONUS_extended_B);
  (void) memset(((void *) &REALTIME_PARTBONUS_extended_B), 0,
                sizeof(B_REALTIME_PARTBONUS_extended_T));

  /* parameters */
  REALTIME_PARTBONUS_extended_M->defaultParam = ((real_T *)
    &REALTIME_PARTBONUS_extended_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &REALTIME_PARTBONUS_extended_X;
    REALTIME_PARTBONUS_extended_M->contStates = (x);
    (void) memset((void *)&REALTIME_PARTBONUS_extended_X, 0,
                  sizeof(X_REALTIME_PARTBONUS_extended_T));
  }

  /* states (dwork) */
  REALTIME_PARTBONUS_extended_M->dwork = ((void *)
    &REALTIME_PARTBONUS_extended_DW);
  (void) memset((void *)&REALTIME_PARTBONUS_extended_DW, 0,
                sizeof(DW_REALTIME_PARTBONUS_extended_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    REALTIME_PARTBONUS_extended_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  REALTIME_PARTBONUS_extended_M->Sizes.numContStates = (5);/* Number of continuous states */
  REALTIME_PARTBONUS_extended_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  REALTIME_PARTBONUS_extended_M->Sizes.numY = (0);/* Number of model outputs */
  REALTIME_PARTBONUS_extended_M->Sizes.numU = (0);/* Number of model inputs */
  REALTIME_PARTBONUS_extended_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  REALTIME_PARTBONUS_extended_M->Sizes.numSampTimes = (2);/* Number of sample times */
  REALTIME_PARTBONUS_extended_M->Sizes.numBlocks = (20);/* Number of blocks */
  REALTIME_PARTBONUS_extended_M->Sizes.numBlockIO = (6);/* Number of block outputs */
  REALTIME_PARTBONUS_extended_M->Sizes.numBlockPrms = (90);/* Sum of parameter "widths" */
  return REALTIME_PARTBONUS_extended_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
