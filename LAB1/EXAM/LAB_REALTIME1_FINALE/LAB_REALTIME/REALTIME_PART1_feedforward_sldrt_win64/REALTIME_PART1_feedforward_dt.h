/*
 * REALTIME_PART1_feedforward_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "REALTIME_PART1_feedforward".
 *
 * Model version              : 1.17
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Jun  7 09:36:13 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(struct_tqEcQv8wI4rPb7WqAAnbuH),
  sizeof(struct_Bzrzhgs57nvppYg0nlNmiE),
  sizeof(struct_vHPMdAr9HfDgWNbG6U3SfC),
  sizeof(struct_nZqFUEOh71pPhzsMP64FWD),
  sizeof(struct_DqRrFctOcoTwJhkxMXTGZG),
  sizeof(struct_t4jfYKvXkqvqbOrnXV9flF),
  sizeof(struct_8LnTg2HasR61N4e63tMdJ)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "struct_tqEcQv8wI4rPb7WqAAnbuH",
  "struct_Bzrzhgs57nvppYg0nlNmiE",
  "struct_vHPMdAr9HfDgWNbG6U3SfC",
  "struct_nZqFUEOh71pPhzsMP64FWD",
  "struct_DqRrFctOcoTwJhkxMXTGZG",
  "struct_t4jfYKvXkqvqbOrnXV9flF",
  "struct_8LnTg2HasR61N4e63tMdJ"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&REALTIME_PART1_feedforward_B.Out), 0, 0, 11 },

  { (char_T *)(&REALTIME_PART1_feedforward_B.FixPtSwitch), 3, 0, 1 }
  ,

  { (char_T *)(&REALTIME_PART1_feedforward_DW.EncoderInput_PWORK), 11, 0, 6 },

  { (char_T *)(&REALTIME_PART1_feedforward_DW.Output_DSTATE), 3, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  4U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&REALTIME_PART1_feedforward_P.ctrl), 15, 0, 1 },

  { (char_T *)(&REALTIME_PART1_feedforward_P.sens), 20, 0, 1 },

  { (char_T *)(&REALTIME_PART1_feedforward_P.BEMF_comp), 0, 0, 22 },

  { (char_T *)(&REALTIME_PART1_feedforward_P.EncoderInput_Channels), 6, 0, 4 },

  { (char_T *)(&REALTIME_PART1_feedforward_P.LimitedCounter_uplimit), 3, 0, 1 },

  { (char_T *)(&REALTIME_PART1_feedforward_P.Integrator_IC), 0, 0, 16 },

  { (char_T *)(&REALTIME_PART1_feedforward_P.Constant_Value), 3, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] REALTIME_PART1_feedforward_dt.h */
