var dataJson = {"arch":{"ispc":true,"isunix":false,"ismac":false},"build":"simulinkCoderTest1","ref":false,"files":[{"name":"ert_main.c","type":"source","group":"main","path":"G:\\matlab_workspace\\testLibrary\\simulinkCoderTest1_ert_rtw","tag":"","groupDisplay":"主文件","code":"/*\r\n * File: ert_main.c\r\n *\r\n * Code generated for Simulink model 'simulinkCoderTest1'.\r\n *\r\n * Model version                  : 1.4\r\n * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022\r\n * C/C++ source code generated on : Mon Dec 11 16:17:09 2023\r\n *\r\n * Target selection: ert.tlc\r\n * Embedded hardware selection: Intel->x86-64 (Windows64)\r\n * Code generation objectives:\r\n *    1. Execution efficiency\r\n *    2. RAM efficiency\r\n * Validation result: Not run\r\n */\r\n\r\n#include <stddef.h>\r\n#include <stdio.h>            /* This example main program uses printf/fflush */\r\n#include \"simulinkCoderTest1.h\"        /* Model header file */\r\n\r\n/*\r\n * Associating rt_OneStep with a real-time clock or interrupt service routine\r\n * is what makes the generated code \"real-time\".  The function rt_OneStep is\r\n * always associated with the base rate of the model.  Subrates are managed\r\n * by the base rate from inside the generated code.  Enabling/disabling\r\n * interrupts and floating point context switches are target specific.  This\r\n * example code indicates where these should take place relative to executing\r\n * the generated code step function.  Overrun behavior should be tailored to\r\n * your application needs.  This example simply sets an error status in the\r\n * real-time model and returns from rt_OneStep.\r\n */\r\nvoid rt_OneStep(void);\r\nvoid rt_OneStep(void)\r\n{\r\n  static boolean_T OverrunFlag = false;\r\n\r\n  /* Disable interrupts here */\r\n\r\n  /* Check for overrun */\r\n  if (OverrunFlag) {\r\n    return;\r\n  }\r\n\r\n  OverrunFlag = true;\r\n\r\n  /* Save FPU context here (if necessary) */\r\n  /* Re-enable timer or interrupt here */\r\n  /* Set model inputs here */\r\n\r\n  /* Step the model */\r\n  simulinkCoderTest1_step();\r\n\r\n  /* Get model outputs here */\r\n\r\n  /* Indicate task complete */\r\n  OverrunFlag = false;\r\n\r\n  /* Disable interrupts here */\r\n  /* Restore FPU context here (if necessary) */\r\n  /* Enable interrupts here */\r\n}\r\n\r\n/*\r\n * The example main function illustrates what is required by your\r\n * application code to initialize, execute, and terminate the generated code.\r\n * Attaching rt_OneStep to a real-time clock is target specific. This example\r\n * illustrates how you do this relative to initializing the model.\r\n */\r\nint_T main(int_T argc, const char *argv[])\r\n{\r\n  /* Unused arguments */\r\n  (void)(argc);\r\n  (void)(argv);\r\n\r\n  /* Initialize model */\r\n  simulinkCoderTest1_initialize();\r\n\r\n  /* Attach rt_OneStep to a timer or interrupt service routine with\r\n   * period 0.01 seconds (base rate of the model) here.\r\n   * The call syntax for rt_OneStep is\r\n   *\r\n   *  rt_OneStep();\r\n   */\r\n  printf(\"Warning: The simulation will run forever. \"\r\n         \"Generated ERT main won't simulate model step behavior. \"\r\n         \"To change this behavior select the 'MAT-file logging' option.\\n\");\r\n  fflush((NULL));\r\n  while (1) {\r\n    /*  Perform application tasks here */\r\n  }\r\n\r\n  /* The option 'Remove error status field in real-time model data structure'\r\n   * is selected, therefore the following code does not need to execute.\r\n   */\r\n  return 0;\r\n}\r\n\r\n/*\r\n * File trailer for generated code.\r\n *\r\n * [EOF]\r\n */\r\n"},{"name":"simulinkCoderTest1.c","type":"source","group":"model","path":"G:\\matlab_workspace\\testLibrary\\simulinkCoderTest1_ert_rtw","tag":"","groupDisplay":"模型文件","code":"/*\r\n * File: simulinkCoderTest1.c\r\n *\r\n * Code generated for Simulink model 'simulinkCoderTest1'.\r\n *\r\n * Model version                  : 1.4\r\n * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022\r\n * C/C++ source code generated on : Mon Dec 11 16:17:09 2023\r\n *\r\n * Target selection: ert.tlc\r\n * Embedded hardware selection: Intel->x86-64 (Windows64)\r\n * Code generation objectives:\r\n *    1. Execution efficiency\r\n *    2. RAM efficiency\r\n * Validation result: Not run\r\n */\r\n\r\n#include \"simulinkCoderTest1.h\"\r\n#include \"rtwtypes.h\"\r\n\r\n/* Exported data definition */\r\n\r\n/* Definition for custom storage class: Global */\r\nreal_T k = 5.0;                        /* Referenced by: '<S1>/Gain' */\r\n\r\n/* Definition for custom storage class: Global */\r\nreal_T x;                              /* '<Root>/In1' */\r\nreal_T y;                              /* '<Root>/In2' */\r\nreal_T z;                              /* '<S1>/Gain' */\r\n\r\n/* Model step function */\r\nvoid simulinkCoderTest1_step(void)\r\n{\r\n  /* Gain: '<S1>/Gain' incorporates:\r\n   *  Inport: '<Root>/In1'\r\n   *  Inport: '<Root>/In2'\r\n   *  Sum: '<S1>/Sum'\r\n   */\r\n  z = (x + y) * k;\r\n}\r\n\r\n/* Model initialize function */\r\nvoid simulinkCoderTest1_initialize(void)\r\n{\r\n  /* (no initialization code required) */\r\n}\r\n\r\n/*\r\n * File trailer for generated code.\r\n *\r\n * [EOF]\r\n */\r\n"},{"name":"simulinkCoderTest1.h","type":"header","group":"model","path":"G:\\matlab_workspace\\testLibrary\\simulinkCoderTest1_ert_rtw","tag":"","groupDisplay":"模型文件","code":"/*\r\n * File: simulinkCoderTest1.h\r\n *\r\n * Code generated for Simulink model 'simulinkCoderTest1'.\r\n *\r\n * Model version                  : 1.4\r\n * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022\r\n * C/C++ source code generated on : Mon Dec 11 16:17:09 2023\r\n *\r\n * Target selection: ert.tlc\r\n * Embedded hardware selection: Intel->x86-64 (Windows64)\r\n * Code generation objectives:\r\n *    1. Execution efficiency\r\n *    2. RAM efficiency\r\n * Validation result: Not run\r\n */\r\n\r\n#ifndef RTW_HEADER_simulinkCoderTest1_h_\r\n#define RTW_HEADER_simulinkCoderTest1_h_\r\n#ifndef simulinkCoderTest1_COMMON_INCLUDES_\r\n#define simulinkCoderTest1_COMMON_INCLUDES_\r\n#include \"rtwtypes.h\"\r\n#endif                                 /* simulinkCoderTest1_COMMON_INCLUDES_ */\r\n\r\n/* Model entry point functions */\r\nextern void simulinkCoderTest1_initialize(void);\r\nextern void simulinkCoderTest1_step(void);\r\n\r\n/* Exported data declaration */\r\n\r\n/* Declaration for custom storage class: Global */\r\nextern real_T k;                       /* Referenced by: '<S1>/Gain' */\r\n\r\n/* Declaration for custom storage class: Global */\r\nextern real_T x;                       /* '<Root>/In1' */\r\nextern real_T y;                       /* '<Root>/In2' */\r\nextern real_T z;                       /* '<S1>/Gain' */\r\n\r\n/*-\r\n * The generated code includes comments that allow you to trace directly\r\n * back to the appropriate location in the model.  The basic format\r\n * is <system>/block_name, where system is the system number (uniquely\r\n * assigned by Simulink) and block_name is the name of the block.\r\n *\r\n * Use the MATLAB hilite_system command to trace the generated code back\r\n * to the model.  For example,\r\n *\r\n * hilite_system('<S3>')    - opens system 3\r\n * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3\r\n *\r\n * Here is the system hierarchy for this model\r\n *\r\n * '<Root>' : 'simulinkCoderTest1'\r\n * '<S1>'   : 'simulinkCoderTest1/Subsystem'\r\n */\r\n#endif                                 /* RTW_HEADER_simulinkCoderTest1_h_ */\r\n\r\n/*\r\n * File trailer for generated code.\r\n *\r\n * [EOF]\r\n */\r\n"},{"name":"rtwtypes.h","type":"header","group":"utility","path":"G:\\matlab_workspace\\testLibrary\\simulinkCoderTest1_ert_rtw","tag":"","groupDisplay":"实用工具文件","code":"/*\r\n * File: rtwtypes.h\r\n *\r\n * Code generated for Simulink model 'simulinkCoderTest1'.\r\n *\r\n * Model version                  : 1.4\r\n * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022\r\n * C/C++ source code generated on : Mon Dec 11 16:17:09 2023\r\n *\r\n * Target selection: ert.tlc\r\n * Embedded hardware selection: Intel->x86-64 (Windows64)\r\n * Code generation objectives:\r\n *    1. Execution efficiency\r\n *    2. RAM efficiency\r\n * Validation result: Not run\r\n */\r\n\r\n#ifndef RTWTYPES_H\r\n#define RTWTYPES_H\r\n\r\n/* Logical type definitions */\r\n#if (!defined(__cplusplus))\r\n#ifndef false\r\n#define false                          (0U)\r\n#endif\r\n\r\n#ifndef true\r\n#define true                           (1U)\r\n#endif\r\n#endif\r\n\r\n/*=======================================================================*\r\n * Target hardware information\r\n *   Device type: Intel->x86-64 (Windows64)\r\n *   Number of bits:     char:   8    short:   16    int:  32\r\n *                       long:  32    long long:  64\r\n *                       native word size:  64\r\n *   Byte ordering: LittleEndian\r\n *   Signed integer division rounds to: Zero\r\n *   Shift right on a signed integer as arithmetic shift: on\r\n *=======================================================================*/\r\n\r\n/*=======================================================================*\r\n * Fixed width word size data types:                                     *\r\n *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *\r\n *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *\r\n *   real32_T, real64_T           - 32 and 64 bit floating point numbers *\r\n *=======================================================================*/\r\ntypedef signed char int8_T;\r\ntypedef unsigned char uint8_T;\r\ntypedef short int16_T;\r\ntypedef unsigned short uint16_T;\r\ntypedef int int32_T;\r\ntypedef unsigned int uint32_T;\r\ntypedef long long int64_T;\r\ntypedef unsigned long long uint64_T;\r\ntypedef float real32_T;\r\ntypedef double real64_T;\r\n\r\n/*===========================================================================*\r\n * Generic type definitions: boolean_T, char_T, byte_T, int_T, uint_T,       *\r\n *                           real_T, time_T, ulong_T, ulonglong_T.           *\r\n *===========================================================================*/\r\ntypedef double real_T;\r\ntypedef double time_T;\r\ntypedef unsigned char boolean_T;\r\ntypedef int int_T;\r\ntypedef unsigned int uint_T;\r\ntypedef unsigned long ulong_T;\r\ntypedef unsigned long long ulonglong_T;\r\ntypedef char char_T;\r\ntypedef unsigned char uchar_T;\r\ntypedef char_T byte_T;\r\n\r\n/*=======================================================================*\r\n * Min and Max:                                                          *\r\n *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *\r\n *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *\r\n *=======================================================================*/\r\n#define MAX_int8_T                     ((int8_T)(127))\r\n#define MIN_int8_T                     ((int8_T)(-128))\r\n#define MAX_uint8_T                    ((uint8_T)(255U))\r\n#define MAX_int16_T                    ((int16_T)(32767))\r\n#define MIN_int16_T                    ((int16_T)(-32768))\r\n#define MAX_uint16_T                   ((uint16_T)(65535U))\r\n#define MAX_int32_T                    ((int32_T)(2147483647))\r\n#define MIN_int32_T                    ((int32_T)(-2147483647-1))\r\n#define MAX_uint32_T                   ((uint32_T)(0xFFFFFFFFU))\r\n#define MAX_int64_T                    ((int64_T)(9223372036854775807LL))\r\n#define MIN_int64_T                    ((int64_T)(-9223372036854775807LL-1LL))\r\n#define MAX_uint64_T                   ((uint64_T)(0xFFFFFFFFFFFFFFFFULL))\r\n\r\n/* Block D-Work pointer type */\r\ntypedef void * pointer_T;\r\n\r\n#endif                                 /* RTWTYPES_H */\r\n\r\n/*\r\n * File trailer for generated code.\r\n *\r\n * [EOF]\r\n */\r\n"}],"coverage":[{"id":"SimulinkCoverage","name":"Simulink Coverage","files":[]},{"id":"Bullseye","name":"Bullseye Coverage","files":[]},{"id":"LDRA","name":"LDRA Testbed","files":[]}],"features":{"annotation":false,"coverage":true,"profiling":true,"tooltip":true,"coverageTooltip":true,"showJustificationLinks":true,"useMWTable":false,"showProfilingInfo":true,"showTaskSummary":true}};