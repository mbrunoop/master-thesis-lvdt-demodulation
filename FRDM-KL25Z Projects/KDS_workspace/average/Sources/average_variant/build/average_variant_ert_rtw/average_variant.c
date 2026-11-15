/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: average_variant.c
 *
 * Code generated for Simulink model 'average_variant'.
 *
 * Model version                  : 1.94
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Thu Oct 22 18:00:43 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M0/M0+
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "average_variant.h"
#include "rtwtypes.h"
#include <math.h>

/* Block signals (default storage) */
B_average_variant_T average_variant_B;

/* Block states (default storage) */
DW_average_variant_T average_variant_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_average_variant_T average_variant_Y;

/* Real-time model */
static RT_MODEL_average_variant_T average_variant_M_;
RT_MODEL_average_variant_T *const average_variant_M = &average_variant_M_;

/* Model step function for TID0 */
void average_variant_step0(void)       /* Sample time: [0.001s, 0.0s] */
{
  uint16_T rtb_Output;
  uint16_T rtb_Output_f;

  /* UnitDelay: '<S7>/Output' */
  rtb_Output = average_variant_DW.Output_DSTATE;

  /* Switch: '<S9>/FixPt Switch' incorporates:
   *  Constant: '<S8>/FixPt Constant'
   *  Constant: '<S9>/Constant'
   *  Sum: '<S8>/FixPt Sum1'
   *  UnitDelay: '<S7>/Output'
   */
  if ((uint16_T)(average_variant_DW.Output_DSTATE + 1) > 331) {
    average_variant_DW.Output_DSTATE = 0U;
  } else {
    average_variant_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S9>/FixPt Switch' */

  /* UnitDelay: '<S10>/Output' */
  rtb_Output_f = average_variant_DW.Output_DSTATE_o;

  /* Switch: '<S12>/FixPt Switch' incorporates:
   *  Constant: '<S11>/FixPt Constant'
   *  Constant: '<S12>/Constant'
   *  Sum: '<S11>/FixPt Sum1'
   *  UnitDelay: '<S10>/Output'
   */
  if ((uint16_T)(average_variant_DW.Output_DSTATE_o + 1) > 331) {
    average_variant_DW.Output_DSTATE_o = 0U;
  } else {
    average_variant_DW.Output_DSTATE_o++;
  }

  /* End of Switch: '<S12>/FixPt Switch' */

  /* Buffer: '<Root>/VaRawBuffer' incorporates:
   *  Constant: '<S2>/Vector'
   *  MultiPortSwitch: '<S2>/Output'
   */
  average_variant_DW.VaRawBuffer_CircBuf[average_variant_DW.VaRawBuffer_inBufPtrIdx]
    = average_variant_ConstP.Vector_Value[rtb_Output];
  average_variant_DW.VaRawBuffer_inBufPtrIdx++;
  if (average_variant_DW.VaRawBuffer_inBufPtrIdx >= 664) {
    average_variant_DW.VaRawBuffer_inBufPtrIdx -= 664;
  }

  /* End of Buffer: '<Root>/VaRawBuffer' */

  /* Buffer: '<Root>/VbRawBuffer' incorporates:
   *  Constant: '<S3>/Vector'
   *  MultiPortSwitch: '<S3>/Output'
   */
  average_variant_DW.VbRawBuffer_CircBuf[average_variant_DW.VbRawBuffer_inBufPtrIdx]
    = average_variant_ConstP.Vector_Value_a[rtb_Output_f];
  average_variant_DW.VbRawBuffer_inBufPtrIdx++;
  if (average_variant_DW.VbRawBuffer_inBufPtrIdx >= 664) {
    average_variant_DW.VbRawBuffer_inBufPtrIdx -= 664;
  }

  /* End of Buffer: '<Root>/VbRawBuffer' */
}

/* Model step function for TID1 */
void average_variant_step1(void)       /* Sample time: [0.332s, 0.0s] */
{
  real_T rtb_Average_A;
  real_T rtb_Average_B;
  int32_T Average_A_AccVal;
  int32_T Average_B_AccVal;
  int32_T n;

  /* Buffer: '<Root>/VaRawBuffer' */
  for (Average_A_AccVal = 0; Average_A_AccVal < 332; Average_A_AccVal++) {
    average_variant_B.VaRawBuffer[Average_A_AccVal] =
      average_variant_DW.VaRawBuffer_CircBuf[average_variant_DW.VaRawBuffer_outBufPtrIdx
      + Average_A_AccVal];
  }

  Average_A_AccVal = average_variant_DW.VaRawBuffer_outBufPtrIdx + 332;
  if (average_variant_DW.VaRawBuffer_outBufPtrIdx + 332 == 664) {
    Average_A_AccVal = 0;
  }

  average_variant_DW.VaRawBuffer_outBufPtrIdx = Average_A_AccVal;

  /* End of Buffer: '<Root>/VaRawBuffer' */

  /* Buffer: '<Root>/VbRawBuffer' */
  for (Average_A_AccVal = 0; Average_A_AccVal < 332; Average_A_AccVal++) {
    average_variant_B.VbRawBuffer[Average_A_AccVal] =
      average_variant_DW.VbRawBuffer_CircBuf[average_variant_DW.VbRawBuffer_outBufPtrIdx
      + Average_A_AccVal];
  }

  Average_A_AccVal = average_variant_DW.VbRawBuffer_outBufPtrIdx + 332;
  if (average_variant_DW.VbRawBuffer_outBufPtrIdx + 332 == 664) {
    Average_A_AccVal = 0;
  }

  average_variant_DW.VbRawBuffer_outBufPtrIdx = Average_A_AccVal;

  /* End of Buffer: '<Root>/VbRawBuffer' */

  /* FunctionCallGenerator: '<Root>/Run' incorporates:
   *  SubSystem: '<Root>/Demodulation'
   */
  for (Average_A_AccVal = 0; Average_A_AccVal < 332; Average_A_AccVal++) {
    /* Abs: '<S4>/Abs' incorporates:
     *  Buffer: '<Root>/VaRawBuffer'
     *  Constant: '<S4>/Va_offset'
     *  Sum: '<S4>/Sum'
     */
    average_variant_B.Abs[Average_A_AccVal] = (uint16_T)fabs((real_T)
      average_variant_B.VaRawBuffer[Average_A_AccVal] - 2048.0);

    /* Abs: '<S4>/Abs1' incorporates:
     *  Buffer: '<Root>/VbRawBuffer'
     *  Constant: '<S4>/Vb_offset'
     *  Sum: '<S4>/Sum1'
     */
    average_variant_B.Abs1[Average_A_AccVal] = (uint16_T)fabs((real_T)
      average_variant_B.VbRawBuffer[Average_A_AccVal] - 2048.0);
  }

  /* S-Function (sdspstatfcns): '<S6>/Average_A' incorporates:
   *  Abs: '<S4>/Abs'
   */
  Average_A_AccVal = average_variant_B.Abs[0];

  /* S-Function (sdspstatfcns): '<S6>/Average_B' incorporates:
   *  Abs: '<S4>/Abs1'
   */
  Average_B_AccVal = average_variant_B.Abs1[0];
  for (n = 330; n >= 0; n--) {
    /* S-Function (sdspstatfcns): '<S6>/Average_A' incorporates:
     *  Abs: '<S4>/Abs'
     */
    Average_A_AccVal += average_variant_B.Abs[331 - n];

    /* S-Function (sdspstatfcns): '<S6>/Average_B' incorporates:
     *  Abs: '<S4>/Abs1'
     */
    Average_B_AccVal += average_variant_B.Abs1[331 - n];
  }

  /* S-Function (sdspstatfcns): '<S6>/Average_A' */
  rtb_Average_A = (real_T)Average_A_AccVal / 332.0;

  /* S-Function (sdspstatfcns): '<S6>/Average_B' */
  rtb_Average_B = (real_T)Average_B_AccVal / 332.0;

  /* Outport: '<Root>/Position' incorporates:
   *  Gain: '<S1>/Conversion'
   *  Product: '<S5>/Divide'
   *  Sum: '<S5>/Add'
   *  Sum: '<S5>/Add1'
   */
  average_variant_Y.Position = 1.0 / (rtb_Average_A + rtb_Average_B) *
    (rtb_Average_A - rtb_Average_B) * 10.0;

  /* End of Outputs for FunctionCallGenerator: '<Root>/Run' */
}

/* Model initialize function */
void average_variant_initialize(void)
{
  /* Registration code */

  /* Set task counter limit used by the static main program */
  (average_variant_M)->Timing.TaskCounters.cLimit[0] = 1;
  (average_variant_M)->Timing.TaskCounters.cLimit[1] = 332;

  /* InitializeConditions for Buffer: '<Root>/VaRawBuffer' */
  average_variant_DW.VaRawBuffer_inBufPtrIdx = 332;

  /* InitializeConditions for Buffer: '<Root>/VbRawBuffer' */
  average_variant_DW.VbRawBuffer_inBufPtrIdx = 332;
}

/* Model terminate function */
void average_variant_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
