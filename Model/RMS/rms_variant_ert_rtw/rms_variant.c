/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rms_variant.c
 *
 * Code generated for Simulink model 'rms_variant'.
 *
 * Model version                  : 1.94
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Thu Oct 22 18:15:16 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M0/M0+
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "rms_variant.h"
#include "rtwtypes.h"
#include <math.h>

/* Block signals (default storage) */
B_rms_variant_T rms_variant_B;

/* Block states (default storage) */
DW_rms_variant_T rms_variant_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_rms_variant_T rms_variant_Y;

/* Real-time model */
static RT_MODEL_rms_variant_T rms_variant_M_;
RT_MODEL_rms_variant_T *const rms_variant_M = &rms_variant_M_;

/* Model step function for TID0 */
void rms_variant_step0(void)           /* Sample time: [0.001s, 0.0s] */
{
  uint16_T rtb_Output;
  uint16_T rtb_Output_b;

  /* UnitDelay: '<S7>/Output' */
  rtb_Output = rms_variant_DW.Output_DSTATE;

  /* Switch: '<S9>/FixPt Switch' incorporates:
   *  Constant: '<S8>/FixPt Constant'
   *  Constant: '<S9>/Constant'
   *  Sum: '<S8>/FixPt Sum1'
   *  UnitDelay: '<S7>/Output'
   */
  if ((uint16_T)(rms_variant_DW.Output_DSTATE + 1) > 331) {
    rms_variant_DW.Output_DSTATE = 0U;
  } else {
    rms_variant_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S9>/FixPt Switch' */

  /* UnitDelay: '<S10>/Output' */
  rtb_Output_b = rms_variant_DW.Output_DSTATE_p;

  /* Switch: '<S12>/FixPt Switch' incorporates:
   *  Constant: '<S11>/FixPt Constant'
   *  Constant: '<S12>/Constant'
   *  Sum: '<S11>/FixPt Sum1'
   *  UnitDelay: '<S10>/Output'
   */
  if ((uint16_T)(rms_variant_DW.Output_DSTATE_p + 1) > 331) {
    rms_variant_DW.Output_DSTATE_p = 0U;
  } else {
    rms_variant_DW.Output_DSTATE_p++;
  }

  /* End of Switch: '<S12>/FixPt Switch' */

  /* Buffer: '<Root>/VaRawBuffer' incorporates:
   *  Constant: '<S2>/Vector'
   *  MultiPortSwitch: '<S2>/Output'
   */
  rms_variant_DW.VaRawBuffer_CircBuf[rms_variant_DW.VaRawBuffer_inBufPtrIdx] =
    rms_variant_ConstP.Vector_Value[rtb_Output];
  rms_variant_DW.VaRawBuffer_inBufPtrIdx++;
  if (rms_variant_DW.VaRawBuffer_inBufPtrIdx >= 664) {
    rms_variant_DW.VaRawBuffer_inBufPtrIdx -= 664;
  }

  /* End of Buffer: '<Root>/VaRawBuffer' */

  /* Buffer: '<Root>/VbRawBuffer' incorporates:
   *  Constant: '<S3>/Vector'
   *  MultiPortSwitch: '<S3>/Output'
   */
  rms_variant_DW.VbRawBuffer_CircBuf[rms_variant_DW.VbRawBuffer_inBufPtrIdx] =
    rms_variant_ConstP.Vector_Value_d[rtb_Output_b];
  rms_variant_DW.VbRawBuffer_inBufPtrIdx++;
  if (rms_variant_DW.VbRawBuffer_inBufPtrIdx >= 664) {
    rms_variant_DW.VbRawBuffer_inBufPtrIdx -= 664;
  }

  /* End of Buffer: '<Root>/VbRawBuffer' */
}

/* Model step function for TID1 */
void rms_variant_step1(void)           /* Sample time: [0.332s, 0.0s] */
{
  real_T RMS_A_SqData;
  real_T RMS_B_SqData;
  int32_T i;
  int32_T n;
  int32_T str;

  /* Buffer: '<Root>/VaRawBuffer' */
  for (i = 0; i < 332; i++) {
    rms_variant_B.VaRawBuffer[i] =
      rms_variant_DW.VaRawBuffer_CircBuf[rms_variant_DW.VaRawBuffer_outBufPtrIdx
      + i];
  }

  i = rms_variant_DW.VaRawBuffer_outBufPtrIdx + 332;
  if (rms_variant_DW.VaRawBuffer_outBufPtrIdx + 332 == 664) {
    i = 0;
  }

  rms_variant_DW.VaRawBuffer_outBufPtrIdx = i;

  /* End of Buffer: '<Root>/VaRawBuffer' */

  /* Buffer: '<Root>/VbRawBuffer' */
  for (i = 0; i < 332; i++) {
    rms_variant_B.VbRawBuffer[i] =
      rms_variant_DW.VbRawBuffer_CircBuf[rms_variant_DW.VbRawBuffer_outBufPtrIdx
      + i];
  }

  i = rms_variant_DW.VbRawBuffer_outBufPtrIdx + 332;
  if (rms_variant_DW.VbRawBuffer_outBufPtrIdx + 332 == 664) {
    i = 0;
  }

  rms_variant_DW.VbRawBuffer_outBufPtrIdx = i;

  /* End of Buffer: '<Root>/VbRawBuffer' */

  /* FunctionCallGenerator: '<Root>/Run' incorporates:
   *  SubSystem: '<Root>/Demodulation'
   */
  for (i = 0; i < 332; i++) {
    /* Abs: '<S4>/Abs' incorporates:
     *  Buffer: '<Root>/VaRawBuffer'
     *  Constant: '<S4>/Va_offset'
     *  Sum: '<S4>/Sum'
     */
    rms_variant_B.Abs[i] = (uint16_T)fabs((real_T)rms_variant_B.VaRawBuffer[i] -
      2048.0);

    /* Abs: '<S4>/Abs1' incorporates:
     *  Buffer: '<Root>/VbRawBuffer'
     *  Constant: '<S4>/Vb_offset'
     *  Sum: '<S4>/Sum1'
     */
    rms_variant_B.Abs1[i] = (uint16_T)fabs((real_T)rms_variant_B.VbRawBuffer[i]
      - 2048.0);
  }

  /* S-Function (sdspstatfcns): '<S6>/RMS_A' incorporates:
   *  Abs: '<S4>/Abs'
   */
  RMS_A_SqData = (uint32_T)rms_variant_B.Abs[0] * rms_variant_B.Abs[0];
  i = 1;

  /* S-Function (sdspstatfcns): '<S6>/RMS_B' incorporates:
   *  Abs: '<S4>/Abs1'
   */
  RMS_B_SqData = (uint32_T)rms_variant_B.Abs1[0] * rms_variant_B.Abs1[0];
  str = 1;
  for (n = 330; n >= 0; n--) {
    /* S-Function (sdspstatfcns): '<S6>/RMS_A' incorporates:
     *  Abs: '<S4>/Abs'
     */
    RMS_A_SqData += (real_T)((uint32_T)rms_variant_B.Abs[i] *
      rms_variant_B.Abs[i]);
    i++;

    /* S-Function (sdspstatfcns): '<S6>/RMS_B' incorporates:
     *  Abs: '<S4>/Abs1'
     */
    RMS_B_SqData += (real_T)((uint32_T)rms_variant_B.Abs1[str] *
      rms_variant_B.Abs1[str]);
    str++;
  }

  /* S-Function (sdspstatfcns): '<S6>/RMS_A' */
  RMS_A_SqData = sqrt(RMS_A_SqData / 332.0);

  /* S-Function (sdspstatfcns): '<S6>/RMS_B' */
  RMS_B_SqData = sqrt(RMS_B_SqData / 332.0);

  /* Outport: '<Root>/Position' incorporates:
   *  Gain: '<S1>/Conversion'
   *  Product: '<S5>/Divide'
   *  Sum: '<S5>/Add'
   *  Sum: '<S5>/Add1'
   */
  rms_variant_Y.Position = 1.0 / (RMS_A_SqData + RMS_B_SqData) * (RMS_A_SqData -
    RMS_B_SqData) * 10.0;

  /* End of Outputs for FunctionCallGenerator: '<Root>/Run' */
}

/* Model initialize function */
void rms_variant_initialize(void)
{
  /* Registration code */

  /* Set task counter limit used by the static main program */
  (rms_variant_M)->Timing.TaskCounters.cLimit[0] = 1;
  (rms_variant_M)->Timing.TaskCounters.cLimit[1] = 332;

  /* InitializeConditions for Buffer: '<Root>/VaRawBuffer' */
  rms_variant_DW.VaRawBuffer_inBufPtrIdx = 332;

  /* InitializeConditions for Buffer: '<Root>/VbRawBuffer' */
  rms_variant_DW.VbRawBuffer_inBufPtrIdx = 332;
}

/* Model terminate function */
void rms_variant_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
