/*
 * sfuntmpl_basic.c: Level 2 S-Function的基本'C'模板。
 *
 * 版权所有 1990-2018 The MathWorks, Inc.
 */


/*
 * 必须将S_FUNCTION_NAME指定为您的S-Function的名称
 * （即用您的S-Function的名称替换sfuntmpl_basic）。
 */

#define S_FUNCTION_NAME  Test2
#define S_FUNCTION_LEVEL 2

/*
 * 需要包含simstruc.h以获取SimStruct及其相关宏定义的定义。
 */
#include "simstruc.h"



/* 错误处理
 * --------------
 *
 * 您应该使用以下技术报告在S-Function中遇到的错误：
 *
 *       ssSetErrorStatus(S, "Error encountered due to ...");
 *       return;
 *
 * 请注意，ssSetErrorStatus的第二个参数必须是持久内存。
 * 它不能是局部变量。例如，以下内容将导致不可预测的错误：
 *
 *      mdlOutputs()
 *      {
 *         char msg[256];         {非法：要修复，请使用"static char msg[256];"}
 *         sprintf(msg, "Error due to %s", string);
 *         ssSetErrorStatus(S, msg);
 *         return;
 *      }
 *
 */

/*====================*
 * S-Function方法    *
 *====================*/

/* Function: mdlInitializeSizes ===============================================
 * 摘要：
 *    大小信息用于确定S-Function块的特性（输入、输出、状态等）。
 */
static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumSFcnParams(S, 1);  /* 期望的参数个数 */
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        /* 如果期望的参数个数!=实际参数个数，则返回 */
        return;
    }

    ssSetNumContStates(S, 0); // 连续状态个数
    ssSetNumDiscStates(S, 0); // 离散状态个数

    if (!ssSetNumInputPorts(S, 1)) return; // 输入个数
    ssSetInputPortWidth(S, 0, 1); // 输入维度（1维，2维 。。）
    ssSetInputPortRequiredContiguous(S, 0, true); /*直接访问输入信号*/
    /*
     * 设置直接通行标志（1=yes，0=no）。
     * 如果在mdlOutputs或mdlGetTimeOfNextVarHit函数中使用了输入，则端口具有直通。
     */
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    if (!ssSetNumOutputPorts(S, 1)) return; // 输出个数
    ssSetOutputPortWidth(S, 0, 1); // 第一个输出 括号里最后的1表示维度
    // ssSetOutputPortWidth(S, 1, 1); // 如果有第多个输出

    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, 0);
    ssSetNumIWork(S, 0);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    /* 指定操作点保存/恢复的合规性与内置块相同 */
    ssSetOperatingPointCompliance(S, USE_DEFAULT_OPERATING_POINT);

    ssSetRuntimeThreadSafetyCompliance(S, RUNTIME_THREAD_SAFETY_COMPLIANCE_TRUE);
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
}



/* Function: mdlInitializeSampleTimes =========================================
 * 摘要：
 *    此函数用于指定S-Function的采样时间。必须注册与
 *    ssSetNumSampleTimes中指定的样本时间相同的样本时间。
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, CONTINUOUS_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}



#define MDL_INITIALIZE_CONDITIONS   /* 将其更改为＃undef以删除该函数 */
#if defined(MDL_INITIALIZE_CONDITIONS)
  /* Function: mdlInitializeConditions ========================================
   * 摘要：
   *    在此函数中，应初始化S-Function块的连续和离散状态。
   *    初始状态放置在状态向量ssGetContStates(S)或ssGetRealDiscStates(S)中。
   *    您还可以执行S-Function可能需要的任何其他初始化活动。请注意，此例程将在
   *    仿真开始时调用，如果存在于配置为重置状态的已启用子系统中，
   *    则在启用子系统重新启动执行以重置状态时也将调用此例程。
   */
  static void mdlInitializeConditions(SimStruct *S)
  {
  }
#endif /* MDL_INITIALIZE_CONDITIONS */



#define MDL_START  /* 将其更改为＃undef以删除该函数 */
#if defined(MDL_START) 
  /* Function: mdlStart =======================================================
   * 摘要：
   *    此函数在模型执行开始时调用一次。如果有应该初始化一次的状态，
   *    则可以在此处执行。
   */
  static void mdlStart(SimStruct *S)
  {
  }
#endif /*  MDL_START */



/* Function: mdlOutputs =======================================================
 * 摘要：
 *    在此函数中，计算S-Function块的输出。
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
    const real_T *u = (const real_T*) ssGetInputPortSignal(S, 0); // 获取输入
    real_T       *y = ssGetOutputPortSignal(S, 0); // 获取输出
    // real_T       *y1 = ssGetOutputPortSignal(S, 2); -- 如果有第多个输出，这样获取
    real_T *param1 = mxGetPr(ssGetSFcnParam(S,0)); // 获取输入参数
    y[0] = param1[0] * u[0];
}



#define MDL_UPDATE  /* 将其更改为＃undef以删除该函数 */
#if defined(MDL_UPDATE)
  /* Function: mdlUpdate ======================================================
   * 摘要：
   *    此函数每个主要的积分时间步调用一次。
   *    通常在此更新离散状态，但此函数对于执行每个积分步骤仅需执行一次的任何任务都很有用。
   */
  static void mdlUpdate(SimStruct *S, int_T tid)
  {
  }
#endif /* MDL_UPDATE */



#define MDL_DERIVATIVES  /* 将其更改为＃undef以删除该函数 */
#if defined(MDL_DERIVATIVES)
  /* Function: mdlDerivatives =================================================
   * 摘要：
   *    在此函数中，计算S-Function块的导数。
   *    导数放置在导数向量ssGetdX(S)中。
   */
  static void mdlDerivatives(SimStruct *S)
  {
  }
#endif /* MDL_DERIVATIVES */



/* Function: mdlTerminate =====================================================
 * 摘要：
 *    在此函数中，应执行在仿真终止时必要的任何操作。
 *    例如，如果在mdlStart中分配了内存，这是释放它的地方。
 */
static void mdlTerminate(SimStruct *S)
{
}


/*=============================*
 * 必需的S-Function尾部       *
 *=============================*/

#ifdef  MATLAB_MEX_FILE    /* 是否正在编译为MEX文件？ */
#include "simulink.c"      /* MEX文件接口机制 */
#else
#include "cg_sfun.h"       /* 代码生成注册函数 */
#endif
