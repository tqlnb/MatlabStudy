/*
 * File: simulinkCoderTest1.c
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

#include "simulinkCoderTest1.h"
#include "rtwtypes.h"

/* Exported data definition */

/* Definition for custom storage class: Global */
real_T k = 5.0;                        /* Referenced by: '<S1>/Gain' */

/* Definition for custom storage class: Global */
real_T x;                              /* '<Root>/In1' */
real_T y;                              /* '<Root>/In2' */
real_T z;                              /* '<S1>/Gain' */

/* Model step function */
void simulinkCoderTest1_step(void)
{
  /* Gain: '<S1>/Gain' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   *  Sum: '<S1>/Sum'
   */
  z = (x + y) * k;
}

/* Model initialize function */
void simulinkCoderTest1_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
