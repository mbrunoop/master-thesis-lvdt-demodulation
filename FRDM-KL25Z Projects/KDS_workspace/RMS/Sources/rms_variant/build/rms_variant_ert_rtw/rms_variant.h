/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rms_variant.h
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

#ifndef rms_variant_h_
#define rms_variant_h_
#ifndef rms_variant_COMMON_INCLUDES_
#define rms_variant_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* rms_variant_COMMON_INCLUDES_ */

#include "rms_variant_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmCounterLimit
#define rtmCounterLimit(rtm, idx)      ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  uint16_T VaRawBuffer[332];           /* '<Root>/VaRawBuffer' */
  uint16_T Abs[332];                   /* '<S4>/Abs' */
  uint16_T Abs1[332];                  /* '<S4>/Abs1' */
  uint16_T VbRawBuffer[332];           /* '<Root>/VbRawBuffer' */
} B_rms_variant_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T VaRawBuffer_inBufPtrIdx;     /* '<Root>/VaRawBuffer' */
  int32_T VaRawBuffer_outBufPtrIdx;    /* '<Root>/VaRawBuffer' */
  int32_T VbRawBuffer_inBufPtrIdx;     /* '<Root>/VbRawBuffer' */
  int32_T VbRawBuffer_outBufPtrIdx;    /* '<Root>/VbRawBuffer' */
  uint16_T Output_DSTATE;              /* '<S7>/Output' */
  uint16_T Output_DSTATE_p;            /* '<S10>/Output' */
  uint16_T VaRawBuffer_CircBuf[664];   /* '<Root>/VaRawBuffer' */
  uint16_T VbRawBuffer_CircBuf[664];   /* '<Root>/VbRawBuffer' */
} DW_rms_variant_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: OutValues
   * Referenced by: '<S2>/Vector'
   */
  uint16_T Vector_Value[332];

  /* Expression: OutValues
   * Referenced by: '<S3>/Vector'
   */
  uint16_T Vector_Value_d[332];
} ConstP_rms_variant_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Position;                     /* '<Root>/Position' */
} ExtY_rms_variant_T;

/* Real-time Model Data Structure */
struct tag_RTM_rms_variant_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
      uint16_T cLimit[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_rms_variant_T rms_variant_B;

/* Block states (default storage) */
extern DW_rms_variant_T rms_variant_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_rms_variant_T rms_variant_Y;

/* Constant parameters (default storage) */
extern const ConstP_rms_variant_T rms_variant_ConstP;

/* Model entry point functions */
extern void rms_variant_initialize(void);
extern void rms_variant_step0(void);   /* Sample time: [0.001s, 0.0s] */
extern void rms_variant_step1(void);   /* Sample time: [0.332s, 0.0s] */
extern void rms_variant_terminate(void);

/* Real-time Model object */
extern RT_MODEL_rms_variant_T *const rms_variant_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Data Type Propagation' : Unused code path elimination
 * Block '<S8>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S10>/Data Type Propagation' : Unused code path elimination
 * Block '<S11>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S2>/Out' : Eliminate redundant signal conversion block
 * Block '<S3>/Out' : Eliminate redundant signal conversion block
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'rms_variant'
 * '<S1>'   : 'rms_variant/Demodulation'
 * '<S2>'   : 'rms_variant/LVDT ChA'
 * '<S3>'   : 'rms_variant/LVDT ChB'
 * '<S4>'   : 'rms_variant/Demodulation/Preprocess'
 * '<S5>'   : 'rms_variant/Demodulation/Ratio'
 * '<S6>'   : 'rms_variant/Demodulation/Reference Value'
 * '<S7>'   : 'rms_variant/LVDT ChA/LimitedCounter'
 * '<S8>'   : 'rms_variant/LVDT ChA/LimitedCounter/Increment Real World'
 * '<S9>'   : 'rms_variant/LVDT ChA/LimitedCounter/Wrap To Zero'
 * '<S10>'  : 'rms_variant/LVDT ChB/LimitedCounter'
 * '<S11>'  : 'rms_variant/LVDT ChB/LimitedCounter/Increment Real World'
 * '<S12>'  : 'rms_variant/LVDT ChB/LimitedCounter/Wrap To Zero'
 */
#endif                                 /* rms_variant_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
