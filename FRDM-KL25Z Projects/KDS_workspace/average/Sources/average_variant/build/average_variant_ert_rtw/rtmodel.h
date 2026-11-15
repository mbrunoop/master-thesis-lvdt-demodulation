/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rtmodel.h
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

#ifndef rtmodel_h_
#define rtmodel_h_
#include "average_variant.h"

/* Macros generated for backwards compatibility  */
#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((void*) 0)
#endif

/* Model wrapper function */
/* Use this function only if you need to maintain compatibility with an existing static main program. */
extern void average_variant_step(int_T tid);

#endif                                 /* rtmodel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
