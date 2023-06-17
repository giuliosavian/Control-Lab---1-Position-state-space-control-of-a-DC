/*
 * REALTIME_PARTBONUS_extended_data.c
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

/* Block parameters (default storage) */
P_REALTIME_PARTBONUS_extended_T REALTIME_PARTBONUS_extended_P = {
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

  /* Variable: Aest
   * Referenced by: '<S1>/State-Space'
   */
  { 0.0, 0.0, 0.0, 0.0, 131.67498845757819, 1.0, 0.0, -157.91367041742973, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, -14905.453934172609, -558822.58747622615,
    -8.4180604345617574E+6, -227.51772185264616, -23747.732615019602, 0.0, 0.0,
    0.0, 1.0, -25.008305614900831 },

  /* Variable: Ar
   * Referenced by: '<Root>/Sine Wave'
   */
  30.0,

  /* Variable: Best
   * Referenced by: '<S1>/State-Space'
   */
  { 0.0, 0.0, 0.0, 0.0, 131.67498845757819, 14905.453934172609,
    558822.58747622615, 8.4180604345617574E+6, 227.51772185264616,
    23747.732615019602 },

  /* Variable: Cest
   * Referenced by: '<S1>/State-Space'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Variable: Tr
   * Referenced by: '<Root>/Sine Wave'
   */
  0.5,

  /* Variable: deg2rad
   * Referenced by:
   *   '<S1>/deg2rad'
   *   '<S2>/deg2rads'
   */
  0.017453292519943295,

  /* Variable: rad2deg
   * Referenced by: '<S1>/rad2deg'
   */
  57.295779513082323,

  /* Variable: rads2rpm
   * Referenced by: '<S1>/rads2rpm'
   */
  9.5492965855137211,

  /* Variable: rpm2rads
   * Referenced by: '<S2>/rpm2rads'
   */
  0.10471975511965977,

  /* Mask Parameter: AnalogOutput1_FinalValue
   * Referenced by: '<Root>/Analog Output1'
   */
  0.0,

  /* Mask Parameter: AnalogOutput1_InitialValue
   * Referenced by: '<Root>/Analog Output1'
   */
  0.0,

  /* Mask Parameter: EncoderInput1_InputFilter
   * Referenced by: '<Root>/Encoder Input1'
   */
  0.0,

  /* Mask Parameter: AnalogOutput1_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output1'
   */
  10.0,

  /* Mask Parameter: EncoderInput1_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input1'
   */
  10.0,

  /* Mask Parameter: AnalogOutput1_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output1'
   */
  0.0,

  /* Mask Parameter: EncoderInput1_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input1'
   */
  0.0,

  /* Mask Parameter: AnalogOutput1_Channels
   * Referenced by: '<Root>/Analog Output1'
   */
  0,

  /* Mask Parameter: EncoderInput1_Channels
   * Referenced by: '<Root>/Encoder Input1'
   */
  0,

  /* Mask Parameter: AnalogOutput1_RangeMode
   * Referenced by: '<Root>/Analog Output1'
   */
  0,

  /* Mask Parameter: AnalogOutput1_VoltRange
   * Referenced by: '<Root>/Analog Output1'
   */
  0,

  /* Expression: 0
   * Referenced by: '<S1>/State-Space'
   */
  0.0,

  /* Expression: Cp.'
   * Referenced by: '<S2>/Cp_matrixGain'
   */
  { 1.0, 0.0, 0.0 },

  /* Expression: K3.'
   * Referenced by: '<S2>/State feedback'
   */
  { 8.6926845210080419, 0.11385377405921741 },

  /* Expression: 10
   * Referenced by: '<S2>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S2>/Saturation'
   */
  -10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 40
   * Referenced by: '<Root>/Constant'
   */
  40.0,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U
};
