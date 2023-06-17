/*
 * REALTIME_PART1_antiawu_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "REALTIME_PART1_antiawu".
 *
 * Model version              : 1.28
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Apr 19 09:01:54 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "REALTIME_PART1_antiawu.h"
#include "REALTIME_PART1_antiawu_private.h"

/* Block parameters (default storage) */
P_REALTIME_PART1_antiawu_T REALTIME_PART1_antiawu_P = {
  /* Variable: ctrl
   * Referenced by:
   *   '<S1>/K_w'
   *   '<S1>/derivative gain'
   *   '<S1>/derivative gain1'
   *   '<S1>/integral gain'
   *   '<S1>/integral gain1'
   *   '<S1>/proportional gain'
   *   '<S1>/proportional gain1'
   */
  {
    0.15,
    0.1,
    6.0,
    0.59115503379889756,
    1.0226419600694172,
    33.83207256390159,

    { -0.082194052794013, -0.081886754380687307 },
    8.61899149883295,
    0.23911664249305309,
    8.373760265906629,
    0.016196068380760022,
    0.09717641028456013,
    86.170709963311879,
    0.135621993870715,
    0.00738943792248622,
    33.333333333333336
  },

  /* Variable: sens
   * Referenced by: '<Root>/pulse2deg'
   */
  {
    {
      0.5
    },

    {
      4096.0,
      0.087890625,
      0.0031415926535897933,
      5.5555555555555554,
      318.3098861837907
    },

    {
      {
        10000.0,
        5.0,
        345.0,
        6.0213859193804371
      },
      0.014492753623188406,
      0.83037361613162786,
      69.0,
      1.2042771838760873
    }
  },

  /* Variable: deg2rad
   * Referenced by:
   *   '<S1>/deg2rad'
   *   '<S1>/deg2rad1'
   */
  0.017453292519943295,

  /* Variable: degs2rpm
   * Referenced by: '<Root>/degs2rpm'
   */
  0.16666666666666666,

  /* Variable: step_size
   * Referenced by: '<Root>/Step'
   */
  360.0,

  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_InputFilter
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: EncoderInput_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output'
   */
  10.0,

  /* Mask Parameter: EncoderInput_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<Root>/Encoder Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Computed Parameter: RealDerivative_A
   * Referenced by: '<S1>/Real Derivative'
   */
  -135.32829025560636,

  /* Computed Parameter: RealDerivative_C
   * Referenced by: '<S1>/Real Derivative'
   */
  -18313.746143505643,

  /* Computed Parameter: RealDerivative_D
   * Referenced by: '<S1>/Real Derivative'
   */
  135.32829025560636,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator'
   */
  0.0,

  /* Computed Parameter: RealDerivative1_A
   * Referenced by: '<S1>/Real Derivative1'
   */
  -135.32829025560636,

  /* Computed Parameter: RealDerivative1_C
   * Referenced by: '<S1>/Real Derivative1'
   */
  -18313.746143505643,

  /* Computed Parameter: RealDerivative1_D
   * Referenced by: '<S1>/Real Derivative1'
   */
  135.32829025560636,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator1'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S1>/Saturation1'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S1>/Saturation1'
   */
  -10.0,

  /* Computed Parameter: SpeedFilter_A
   * Referenced by: '<Root>/Speed Filter'
   */
  { -177.71531752633462, -15791.367041742973 },

  /* Computed Parameter: SpeedFilter_C
   * Referenced by: '<Root>/Speed Filter'
   */
  { 15791.367041742973, 0.0 },

  /* Computed Parameter: AccelerationFilter_A
   * Referenced by: '<Root>/Acceleration Filter'
   */
  { -177.71531752633462, -15791.367041742973 },

  /* Computed Parameter: AccelerationFilter_C
   * Referenced by: '<Root>/Acceleration Filter'
   */
  { 15791.367041742973, 0.0 },

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U
};
