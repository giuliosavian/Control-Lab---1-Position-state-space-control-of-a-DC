/*
 * REALTIME_PART2_nominal.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "REALTIME_PART2_nominal".
 *
 * Model version              : 1.8
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Apr 19 09:14:10 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "REALTIME_PART2_nominal.h"
#include "REALTIME_PART2_nominal_private.h"
#include "REALTIME_PART2_nominal_dt.h"

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
B_REALTIME_PART2_nominal_T REALTIME_PART2_nominal_B;

/* Continuous states */
X_REALTIME_PART2_nominal_T REALTIME_PART2_nominal_X;

/* Block states (default storage) */
DW_REALTIME_PART2_nominal_T REALTIME_PART2_nominal_DW;

/* Real-time model */
static RT_MODEL_REALTIME_PART2_nominal_T REALTIME_PART2_nominal_M_;
RT_MODEL_REALTIME_PART2_nominal_T *const REALTIME_PART2_nominal_M =
  &REALTIME_PART2_nominal_M_;

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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  REALTIME_PART2_nominal_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  REALTIME_PART2_nominal_output();
  REALTIME_PART2_nominal_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  REALTIME_PART2_nominal_output();
  REALTIME_PART2_nominal_derivatives();

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
void REALTIME_PART2_nominal_output(void)
{
  /* local block i/o variables */
  real_T rtb_EncoderInput;
  real_T rtb_Sum;
  if (rtmIsMajorTimeStep(REALTIME_PART2_nominal_M)) {
    /* set solver stop time */
    if (!(REALTIME_PART2_nominal_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&REALTIME_PART2_nominal_M->solverInfo,
                            ((REALTIME_PART2_nominal_M->Timing.clockTickH0 + 1) *
        REALTIME_PART2_nominal_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&REALTIME_PART2_nominal_M->solverInfo,
                            ((REALTIME_PART2_nominal_M->Timing.clockTick0 + 1) *
        REALTIME_PART2_nominal_M->Timing.stepSize0 +
        REALTIME_PART2_nominal_M->Timing.clockTickH0 *
        REALTIME_PART2_nominal_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(REALTIME_PART2_nominal_M)) {
    REALTIME_PART2_nominal_M->Timing.t[0] = rtsiGetT
      (&REALTIME_PART2_nominal_M->solverInfo);
  }

  /* Step: '<Root>/Step' */
  if (REALTIME_PART2_nominal_M->Timing.t[0] < REALTIME_PART2_nominal_P.Step_Time)
  {
    /* Step: '<Root>/Step' */
    REALTIME_PART2_nominal_B.thl_ref = REALTIME_PART2_nominal_P.Step_Y0;
  } else {
    /* Step: '<Root>/Step' */
    REALTIME_PART2_nominal_B.thl_ref = REALTIME_PART2_nominal_P.step_size;
  }

  /* End of Step: '<Root>/Step' */

  /* Gain: '<S2>/deg2rad' */
  rtb_Sum = REALTIME_PART2_nominal_P.deg2rad * REALTIME_PART2_nominal_B.thl_ref;
  if (rtmIsMajorTimeStep(REALTIME_PART2_nominal_M)) {
    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = REALTIME_PART2_nominal_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &REALTIME_PART2_nominal_P.EncoderInput_Channels,
                     &rtb_EncoderInput, &parm);
    }

    /* Gain: '<Root>/pulse2deg' */
    REALTIME_PART2_nominal_B.thl_meas =
      REALTIME_PART2_nominal_P.sens.enc.pulse2deg * rtb_EncoderInput;

    /* Gain: '<S2>/deg2rads' */
    REALTIME_PART2_nominal_B.deg2rads = REALTIME_PART2_nominal_P.deg2rad *
      REALTIME_PART2_nominal_B.thl_meas;
  }

  /* Gain: '<S1>/degs2rpm' incorporates:
   *  TransferFcn: '<S1>/High-pass filter'
   */
  REALTIME_PART2_nominal_B.degs2rpm =
    (REALTIME_PART2_nominal_P.Highpassfilter_C[0] *
     REALTIME_PART2_nominal_X.Highpassfilter_CSTATE[0] +
     REALTIME_PART2_nominal_P.Highpassfilter_C[1] *
     REALTIME_PART2_nominal_X.Highpassfilter_CSTATE[1]) *
    REALTIME_PART2_nominal_P.degs2rpm;

  /* Sum: '<S2>/Sum' incorporates:
   *  Gain: '<S2>/Input feedforward'
   *  Gain: '<S2>/State feedback'
   *  Gain: '<S2>/State feedforward	'
   *  Gain: '<S2>/rpm2rads'
   *  Sum: '<S2>/Sum2'
   */
  rtb_Sum = ((rtb_Sum * REALTIME_PART2_nominal_P.N_x[0] -
              REALTIME_PART2_nominal_B.deg2rads) *
             REALTIME_PART2_nominal_P.Statefeedback_Gain[0] + (rtb_Sum *
              REALTIME_PART2_nominal_P.N_x[1] -
              REALTIME_PART2_nominal_P.rpm2rads *
              REALTIME_PART2_nominal_B.degs2rpm) *
             REALTIME_PART2_nominal_P.Statefeedback_Gain[1]) +
    REALTIME_PART2_nominal_P.N_u * rtb_Sum;

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Sum > REALTIME_PART2_nominal_P.Saturation_UpperSat) {
    /* Saturate: '<S2>/Saturation' */
    REALTIME_PART2_nominal_B.Saturation =
      REALTIME_PART2_nominal_P.Saturation_UpperSat;
  } else if (rtb_Sum < REALTIME_PART2_nominal_P.Saturation_LowerSat) {
    /* Saturate: '<S2>/Saturation' */
    REALTIME_PART2_nominal_B.Saturation =
      REALTIME_PART2_nominal_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Saturation' */
    REALTIME_PART2_nominal_B.Saturation = rtb_Sum;
  }

  /* End of Saturate: '<S2>/Saturation' */
  if (rtmIsMajorTimeStep(REALTIME_PART2_nominal_M)) {
    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) REALTIME_PART2_nominal_P.AnalogOutput_RangeMode;
        parm.rangeidx = REALTIME_PART2_nominal_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &REALTIME_PART2_nominal_P.AnalogOutput_Channels, ((real_T*)
          (&REALTIME_PART2_nominal_B.Saturation)), &parm);
      }
    }
  }
}

/* Model update function */
void REALTIME_PART2_nominal_update(void)
{
  if (rtmIsMajorTimeStep(REALTIME_PART2_nominal_M)) {
    rt_ertODEUpdateContinuousStates(&REALTIME_PART2_nominal_M->solverInfo);
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
  if (!(++REALTIME_PART2_nominal_M->Timing.clockTick0)) {
    ++REALTIME_PART2_nominal_M->Timing.clockTickH0;
  }

  REALTIME_PART2_nominal_M->Timing.t[0] = rtsiGetSolverStopTime
    (&REALTIME_PART2_nominal_M->solverInfo);

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
    if (!(++REALTIME_PART2_nominal_M->Timing.clockTick1)) {
      ++REALTIME_PART2_nominal_M->Timing.clockTickH1;
    }

    REALTIME_PART2_nominal_M->Timing.t[1] =
      REALTIME_PART2_nominal_M->Timing.clockTick1 *
      REALTIME_PART2_nominal_M->Timing.stepSize1 +
      REALTIME_PART2_nominal_M->Timing.clockTickH1 *
      REALTIME_PART2_nominal_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void REALTIME_PART2_nominal_derivatives(void)
{
  XDot_REALTIME_PART2_nominal_T *_rtXdot;
  _rtXdot = ((XDot_REALTIME_PART2_nominal_T *) REALTIME_PART2_nominal_M->derivs);

  /* Derivatives for TransferFcn: '<S1>/High-pass filter' */
  _rtXdot->Highpassfilter_CSTATE[0] = 0.0;
  _rtXdot->Highpassfilter_CSTATE[0] +=
    REALTIME_PART2_nominal_P.Highpassfilter_A[0] *
    REALTIME_PART2_nominal_X.Highpassfilter_CSTATE[0];
  _rtXdot->Highpassfilter_CSTATE[1] = 0.0;
  _rtXdot->Highpassfilter_CSTATE[0] +=
    REALTIME_PART2_nominal_P.Highpassfilter_A[1] *
    REALTIME_PART2_nominal_X.Highpassfilter_CSTATE[1];
  _rtXdot->Highpassfilter_CSTATE[1] +=
    REALTIME_PART2_nominal_X.Highpassfilter_CSTATE[0];
  _rtXdot->Highpassfilter_CSTATE[0] += REALTIME_PART2_nominal_B.thl_meas;
}

/* Model initialize function */
void REALTIME_PART2_nominal_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) REALTIME_PART2_nominal_P.AnalogOutput_RangeMode;
      parm.rangeidx = REALTIME_PART2_nominal_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &REALTIME_PART2_nominal_P.AnalogOutput_Channels,
                     &REALTIME_PART2_nominal_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = REALTIME_PART2_nominal_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &REALTIME_PART2_nominal_P.EncoderInput_Channels, NULL, &parm);
  }

  /* InitializeConditions for TransferFcn: '<S1>/High-pass filter' */
  REALTIME_PART2_nominal_X.Highpassfilter_CSTATE[0] = 0.0;
  REALTIME_PART2_nominal_X.Highpassfilter_CSTATE[1] = 0.0;
}

/* Model terminate function */
void REALTIME_PART2_nominal_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) REALTIME_PART2_nominal_P.AnalogOutput_RangeMode;
      parm.rangeidx = REALTIME_PART2_nominal_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &REALTIME_PART2_nominal_P.AnalogOutput_Channels,
                     &REALTIME_PART2_nominal_P.AnalogOutput_FinalValue, &parm);
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
  REALTIME_PART2_nominal_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  REALTIME_PART2_nominal_update();
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
  REALTIME_PART2_nominal_initialize();
}

void MdlTerminate(void)
{
  REALTIME_PART2_nominal_terminate();
}

/* Registration function */
RT_MODEL_REALTIME_PART2_nominal_T *REALTIME_PART2_nominal(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  REALTIME_PART2_nominal_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)REALTIME_PART2_nominal_M, 0,
                sizeof(RT_MODEL_REALTIME_PART2_nominal_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&REALTIME_PART2_nominal_M->solverInfo,
                          &REALTIME_PART2_nominal_M->Timing.simTimeStep);
    rtsiSetTPtr(&REALTIME_PART2_nominal_M->solverInfo, &rtmGetTPtr
                (REALTIME_PART2_nominal_M));
    rtsiSetStepSizePtr(&REALTIME_PART2_nominal_M->solverInfo,
                       &REALTIME_PART2_nominal_M->Timing.stepSize0);
    rtsiSetdXPtr(&REALTIME_PART2_nominal_M->solverInfo,
                 &REALTIME_PART2_nominal_M->derivs);
    rtsiSetContStatesPtr(&REALTIME_PART2_nominal_M->solverInfo, (real_T **)
                         &REALTIME_PART2_nominal_M->contStates);
    rtsiSetNumContStatesPtr(&REALTIME_PART2_nominal_M->solverInfo,
      &REALTIME_PART2_nominal_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&REALTIME_PART2_nominal_M->solverInfo,
      &REALTIME_PART2_nominal_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&REALTIME_PART2_nominal_M->solverInfo,
      &REALTIME_PART2_nominal_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&REALTIME_PART2_nominal_M->solverInfo,
      &REALTIME_PART2_nominal_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&REALTIME_PART2_nominal_M->solverInfo,
                          (&rtmGetErrorStatus(REALTIME_PART2_nominal_M)));
    rtsiSetRTModelPtr(&REALTIME_PART2_nominal_M->solverInfo,
                      REALTIME_PART2_nominal_M);
  }

  rtsiSetSimTimeStep(&REALTIME_PART2_nominal_M->solverInfo, MAJOR_TIME_STEP);
  REALTIME_PART2_nominal_M->intgData.y = REALTIME_PART2_nominal_M->odeY;
  REALTIME_PART2_nominal_M->intgData.f[0] = REALTIME_PART2_nominal_M->odeF[0];
  REALTIME_PART2_nominal_M->intgData.f[1] = REALTIME_PART2_nominal_M->odeF[1];
  REALTIME_PART2_nominal_M->intgData.f[2] = REALTIME_PART2_nominal_M->odeF[2];
  REALTIME_PART2_nominal_M->contStates = ((real_T *) &REALTIME_PART2_nominal_X);
  rtsiSetSolverData(&REALTIME_PART2_nominal_M->solverInfo, (void *)
                    &REALTIME_PART2_nominal_M->intgData);
  rtsiSetSolverName(&REALTIME_PART2_nominal_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = REALTIME_PART2_nominal_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    REALTIME_PART2_nominal_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    REALTIME_PART2_nominal_M->Timing.sampleTimes =
      (&REALTIME_PART2_nominal_M->Timing.sampleTimesArray[0]);
    REALTIME_PART2_nominal_M->Timing.offsetTimes =
      (&REALTIME_PART2_nominal_M->Timing.offsetTimesArray[0]);

    /* task periods */
    REALTIME_PART2_nominal_M->Timing.sampleTimes[0] = (0.0);
    REALTIME_PART2_nominal_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    REALTIME_PART2_nominal_M->Timing.offsetTimes[0] = (0.0);
    REALTIME_PART2_nominal_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(REALTIME_PART2_nominal_M, &REALTIME_PART2_nominal_M->Timing.tArray
             [0]);

  {
    int_T *mdlSampleHits = REALTIME_PART2_nominal_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    REALTIME_PART2_nominal_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(REALTIME_PART2_nominal_M, 5.0);
  REALTIME_PART2_nominal_M->Timing.stepSize0 = 0.001;
  REALTIME_PART2_nominal_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  REALTIME_PART2_nominal_M->Sizes.checksums[0] = (3898950216U);
  REALTIME_PART2_nominal_M->Sizes.checksums[1] = (2227489279U);
  REALTIME_PART2_nominal_M->Sizes.checksums[2] = (2054598775U);
  REALTIME_PART2_nominal_M->Sizes.checksums[3] = (3311413394U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    REALTIME_PART2_nominal_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(REALTIME_PART2_nominal_M->extModeInfo,
      &REALTIME_PART2_nominal_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(REALTIME_PART2_nominal_M->extModeInfo,
                        REALTIME_PART2_nominal_M->Sizes.checksums);
    rteiSetTPtr(REALTIME_PART2_nominal_M->extModeInfo, rtmGetTPtr
                (REALTIME_PART2_nominal_M));
  }

  REALTIME_PART2_nominal_M->solverInfoPtr =
    (&REALTIME_PART2_nominal_M->solverInfo);
  REALTIME_PART2_nominal_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&REALTIME_PART2_nominal_M->solverInfo, 0.001);
  rtsiSetSolverMode(&REALTIME_PART2_nominal_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  REALTIME_PART2_nominal_M->blockIO = ((void *) &REALTIME_PART2_nominal_B);
  (void) memset(((void *) &REALTIME_PART2_nominal_B), 0,
                sizeof(B_REALTIME_PART2_nominal_T));

  /* parameters */
  REALTIME_PART2_nominal_M->defaultParam = ((real_T *)&REALTIME_PART2_nominal_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &REALTIME_PART2_nominal_X;
    REALTIME_PART2_nominal_M->contStates = (x);
    (void) memset((void *)&REALTIME_PART2_nominal_X, 0,
                  sizeof(X_REALTIME_PART2_nominal_T));
  }

  /* states (dwork) */
  REALTIME_PART2_nominal_M->dwork = ((void *) &REALTIME_PART2_nominal_DW);
  (void) memset((void *)&REALTIME_PART2_nominal_DW, 0,
                sizeof(DW_REALTIME_PART2_nominal_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    REALTIME_PART2_nominal_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  REALTIME_PART2_nominal_M->Sizes.numContStates = (2);/* Number of continuous states */
  REALTIME_PART2_nominal_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  REALTIME_PART2_nominal_M->Sizes.numY = (0);/* Number of model outputs */
  REALTIME_PART2_nominal_M->Sizes.numU = (0);/* Number of model inputs */
  REALTIME_PART2_nominal_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  REALTIME_PART2_nominal_M->Sizes.numSampTimes = (2);/* Number of sample times */
  REALTIME_PART2_nominal_M->Sizes.numBlocks = (16);/* Number of blocks */
  REALTIME_PART2_nominal_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  REALTIME_PART2_nominal_M->Sizes.numBlockPrms = (29);/* Sum of parameter "widths" */
  return REALTIME_PART2_nominal_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
