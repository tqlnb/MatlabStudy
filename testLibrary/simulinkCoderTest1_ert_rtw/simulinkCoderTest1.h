/*
 * File: simulinkCoderTest1.h
 *
 * Code generated for Simulink model 'simulinkCoderTest1'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Dec 11 16:17:09 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_simulinkCoderTest1_h_
#define RTW_HEADER_simulinkCoderTest1_h_
#ifndef simulinkCoderTest1_COMMON_INCLUDES_
#define simulinkCoderTest1_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* simulinkCoderTest1_COMMON_INCLUDES_ */

/* Model entry point functions */
extern void simulinkCoderTest1_initialize(void);
extern void simulinkCoderTest1_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Global */
extern real_T k;                       /* Referenced by: '<S1>/Gain' */

/* Declaration for custom storage class: Global */
extern real_T x;                       /* '<Root>/In1' */
extern real_T y;                       /* '<Root>/In2' */
extern real_T z;                       /* '<S1>/Gain' */

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
 * '<Root>' : 'simulinkCoderTest1'
 * '<S1>'   : 'simulinkCoderTest1/Subsystem'
 */
#endif                                 /* RTW_HEADER_simulinkCoderTest1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
