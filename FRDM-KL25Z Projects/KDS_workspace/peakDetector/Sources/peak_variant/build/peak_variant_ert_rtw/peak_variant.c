/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: peak_variant.c
 *
 * Code generated for Simulink model 'peak_variant'.
 *
 * Model version                  : 1.117
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Thu Oct 22 18:13:35 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M0/M0+
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "peak_variant.h"
#include "rtwtypes.h"
#include <math.h>

/* Block signals (default storage) */
B_peak_variant_T peak_variant_B;

/* Block states (default storage) */
DW_peak_variant_T peak_variant_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_peak_variant_T peak_variant_Y;

/* Real-time model */
static RT_MODEL_peak_variant_T peak_variant_M_;
RT_MODEL_peak_variant_T *const peak_variant_M = &peak_variant_M_;

/* Model step function for TID0 */
void peak_variant_step0(void)          /* Sample time: [0.001s, 0.0s] */
{
  uint16_T rtb_Output;
  uint16_T rtb_Output_g;

  /* UnitDelay: '<S7>/Output' */
  rtb_Output = peak_variant_DW.Output_DSTATE;

  /* Switch: '<S9>/FixPt Switch' incorporates:
   *  Constant: '<S8>/FixPt Constant'
   *  Constant: '<S9>/Constant'
   *  Sum: '<S8>/FixPt Sum1'
   *  UnitDelay: '<S7>/Output'
   */
  if ((uint16_T)(peak_variant_DW.Output_DSTATE + 1) > 331) {
    peak_variant_DW.Output_DSTATE = 0U;
  } else {
    peak_variant_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S9>/FixPt Switch' */

  /* UnitDelay: '<S10>/Output' */
  rtb_Output_g = peak_variant_DW.Output_DSTATE_i;

  /* Switch: '<S12>/FixPt Switch' incorporates:
   *  Constant: '<S11>/FixPt Constant'
   *  Constant: '<S12>/Constant'
   *  Sum: '<S11>/FixPt Sum1'
   *  UnitDelay: '<S10>/Output'
   */
  if ((uint16_T)(peak_variant_DW.Output_DSTATE_i + 1) > 331) {
    peak_variant_DW.Output_DSTATE_i = 0U;
  } else {
    peak_variant_DW.Output_DSTATE_i++;
  }

  /* End of Switch: '<S12>/FixPt Switch' */

  /* Buffer: '<Root>/VaRawBuffer' incorporates:
   *  Constant: '<S2>/Vector'
   *  MultiPortSwitch: '<S2>/Output'
   */
  peak_variant_DW.VaRawBuffer_CircBuf[peak_variant_DW.VaRawBuffer_inBufPtrIdx] =
    peak_variant_ConstP.Vector_Value[rtb_Output];
  peak_variant_DW.VaRawBuffer_inBufPtrIdx++;
  if (peak_variant_DW.VaRawBuffer_inBufPtrIdx >= 664) {
    peak_variant_DW.VaRawBuffer_inBufPtrIdx -= 664;
  }

  /* End of Buffer: '<Root>/VaRawBuffer' */

  /* Buffer: '<Root>/VbRawBuffer' incorporates:
   *  Constant: '<S3>/Vector'
   *  MultiPortSwitch: '<S3>/Output'
   */
  peak_variant_DW.VbRawBuffer_CircBuf[peak_variant_DW.VbRawBuffer_inBufPtrIdx] =
    peak_variant_ConstP.Vector_Value_m[rtb_Output_g];
  peak_variant_DW.VbRawBuffer_inBufPtrIdx++;
  if (peak_variant_DW.VbRawBuffer_inBufPtrIdx >= 664) {
    peak_variant_DW.VbRawBuffer_inBufPtrIdx -= 664;
  }

  /* End of Buffer: '<Root>/VbRawBuffer' */
}

/* Model step function for TID1 */
void peak_variant_step1(void)          /* Sample time: [0.332s, 0.0s] */
{
  int32_T j;
  int32_T rtb_Abs_0;
  int32_T rtb_Peak_A;
  int32_T rtb_Peak_B;

  /* Buffer: '<Root>/VaRawBuffer' */
  for (rtb_Peak_A = 0; rtb_Peak_A < 332; rtb_Peak_A++) {
    peak_variant_B.VaRawBuffer[rtb_Peak_A] =
      peak_variant_DW.VaRawBuffer_CircBuf[peak_variant_DW.VaRawBuffer_outBufPtrIdx
      + rtb_Peak_A];
  }

  rtb_Peak_A = peak_variant_DW.VaRawBuffer_outBufPtrIdx + 332;
  if (peak_variant_DW.VaRawBuffer_outBufPtrIdx + 332 == 664) {
    rtb_Peak_A = 0;
  }

  peak_variant_DW.VaRawBuffer_outBufPtrIdx = rtb_Peak_A;

  /* End of Buffer: '<Root>/VaRawBuffer' */

  /* Buffer: '<Root>/VbRawBuffer' */
  for (rtb_Peak_A = 0; rtb_Peak_A < 332; rtb_Peak_A++) {
    peak_variant_B.VbRawBuffer[rtb_Peak_A] =
      peak_variant_DW.VbRawBuffer_CircBuf[peak_variant_DW.VbRawBuffer_outBufPtrIdx
      + rtb_Peak_A];
  }

  rtb_Peak_A = peak_variant_DW.VbRawBuffer_outBufPtrIdx + 332;
  if (peak_variant_DW.VbRawBuffer_outBufPtrIdx + 332 == 664) {
    rtb_Peak_A = 0;
  }

  peak_variant_DW.VbRawBuffer_outBufPtrIdx = rtb_Peak_A;

  /* End of Buffer: '<Root>/VbRawBuffer' */

  /* FunctionCallGenerator: '<Root>/Run' incorporates:
   *  SubSystem: '<Root>/Demodulation'
   */
  for (rtb_Peak_A = 0; rtb_Peak_A < 332; rtb_Peak_A++) {
    /* Abs: '<S4>/Abs' incorporates:
     *  Buffer: '<Root>/VaRawBuffer'
     *  Constant: '<S4>/Va_offset'
     *  Sum: '<S4>/Sum'
     */
    peak_variant_B.Abs[rtb_Peak_A] = (uint16_T)fabs((real_T)
      peak_variant_B.VaRawBuffer[rtb_Peak_A] - 2048.0);

    /* Abs: '<S4>/Abs1' incorporates:
     *  Buffer: '<Root>/VbRawBuffer'
     *  Constant: '<S4>/Vb_offset'
     *  Sum: '<S4>/Sum1'
     */
    peak_variant_B.Abs1[rtb_Peak_A] = (uint16_T)fabs((real_T)
      peak_variant_B.VbRawBuffer[rtb_Peak_A] - 2048.0);
  }

  /* S-Function (sdspstatminmax): '<S6>/Peak_A' incorporates:
   *  Abs: '<S4>/Abs'
   */
  rtb_Peak_A = peak_variant_B.Abs[0];

  /* S-Function (sdspstatminmax): '<S6>/Peak_B' incorporates:
   *  Abs: '<S4>/Abs1'
   */
  rtb_Peak_B = peak_variant_B.Abs1[0];
  for (j = 0; j < 331; j++) {
    /* S-Function (sdspstatminmax): '<S6>/Peak_A' incorporates:
     *  Abs: '<S4>/Abs'
     */
    rtb_Abs_0 = peak_variant_B.Abs[j + 1];
    if (rtb_Abs_0 > rtb_Peak_A) {
      rtb_Peak_A = rtb_Abs_0;
    }

    /* S-Function (sdspstatminmax): '<S6>/Peak_B' incorporates:
     *  Abs: '<S4>/Abs1'
     */
    rtb_Abs_0 = peak_variant_B.Abs1[j + 1];
    if (rtb_Abs_0 > rtb_Peak_B) {
      rtb_Peak_B = rtb_Abs_0;
    }
  }

  /* Outport: '<Root>/Position' incorporates:
   *  Gain: '<S1>/Conversion'
   *  Product: '<S5>/Divide'
   *  Sum: '<S5>/Add'
   *  Sum: '<S5>/Add1'
   */
  peak_variant_Y.Position = 1.0 / (real_T)(rtb_Peak_A + rtb_Peak_B) * (real_T)
    (rtb_Peak_A - rtb_Peak_B) * 10.0;

  /* End of Outputs for FunctionCallGenerator: '<Root>/Run' */
}

/* Model initialize function */
void peak_variant_initialize(void)
{
  /* Registration code */

  /* Set task counter limit used by the static main program */
  (peak_variant_M)->Timing.TaskCounters.cLimit[0] = 1;
  (peak_variant_M)->Timing.TaskCounters.cLimit[1] = 332;

  /* InitializeConditions for Buffer: '<Root>/VaRawBuffer' */
  peak_variant_DW.VaRawBuffer_inBufPtrIdx = 332;

  /* InitializeConditions for Buffer: '<Root>/VbRawBuffer' */
  peak_variant_DW.VbRawBuffer_inBufPtrIdx = 332;
}

/* Model terminate function */
void peak_variant_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
