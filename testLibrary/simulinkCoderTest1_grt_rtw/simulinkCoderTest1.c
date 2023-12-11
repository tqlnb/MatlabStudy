/*
 * simulinkCoderTest1.c
 *
 * Code generation for model "simulinkCoderTest1".
 *
 * Model version              : 1.0
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Mon Dec 11 15:16:16 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "simulinkCoderTest1.h"
#include <string.h>
#include "simulinkCoderTest1_private.h"
#include "rt_nonfinite.h"

/* External inputs (root inport signals with default storage) */
ExtU_simulinkCoderTest1_T simulinkCoderTest1_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_simulinkCoderTest1_T simulinkCoderTest1_Y;

/* Real-time model */
static RT_MODEL_simulinkCoderTest1_T simulinkCoderTest1_M_;
RT_MODEL_simulinkCoderTest1_T *const simulinkCoderTest1_M =
  &simulinkCoderTest1_M_;

/* Model step function */
void simulinkCoderTest1_step(void)
{
  /* Outport: '<Root>/Out1' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   *  Sum: '<S1>/Sum'
   */
  simulinkCoderTest1_Y.Out1 = simulinkCoderTest1_U.In1 +
    simulinkCoderTest1_U.In2;

  /* Matfile logging */
  rt_UpdateTXYLogVars(simulinkCoderTest1_M->rtwLogInfo,
                      (&simulinkCoderTest1_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(simulinkCoderTest1_M)!=-1) &&
        !((rtmGetTFinal(simulinkCoderTest1_M)-
           simulinkCoderTest1_M->Timing.taskTime0) >
          simulinkCoderTest1_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(simulinkCoderTest1_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++simulinkCoderTest1_M->Timing.clockTick0)) {
    ++simulinkCoderTest1_M->Timing.clockTickH0;
  }

  simulinkCoderTest1_M->Timing.taskTime0 =
    simulinkCoderTest1_M->Timing.clockTick0 *
    simulinkCoderTest1_M->Timing.stepSize0 +
    simulinkCoderTest1_M->Timing.clockTickH0 *
    simulinkCoderTest1_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void simulinkCoderTest1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)simulinkCoderTest1_M, 0,
                sizeof(RT_MODEL_simulinkCoderTest1_T));
  rtmSetTFinal(simulinkCoderTest1_M, 10.0);
  simulinkCoderTest1_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    simulinkCoderTest1_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(simulinkCoderTest1_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(simulinkCoderTest1_M->rtwLogInfo, (NULL));
    rtliSetLogT(simulinkCoderTest1_M->rtwLogInfo, "tout");
    rtliSetLogX(simulinkCoderTest1_M->rtwLogInfo, "");
    rtliSetLogXFinal(simulinkCoderTest1_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(simulinkCoderTest1_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(simulinkCoderTest1_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(simulinkCoderTest1_M->rtwLogInfo, 0);
    rtliSetLogDecimation(simulinkCoderTest1_M->rtwLogInfo, 1);
    rtliSetLogY(simulinkCoderTest1_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(simulinkCoderTest1_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(simulinkCoderTest1_M->rtwLogInfo, (NULL));
  }

  /* external inputs */
  (void)memset(&simulinkCoderTest1_U, 0, sizeof(ExtU_simulinkCoderTest1_T));

  /* external outputs */
  simulinkCoderTest1_Y.Out1 = 0.0;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(simulinkCoderTest1_M->rtwLogInfo, 0.0,
    rtmGetTFinal(simulinkCoderTest1_M), simulinkCoderTest1_M->Timing.stepSize0,
    (&rtmGetErrorStatus(simulinkCoderTest1_M)));
}

/* Model terminate function */
void simulinkCoderTest1_terminate(void)
{
  /* (no terminate code required) */
}
