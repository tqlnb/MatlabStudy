# MatlabStudy

matlab学习笔记，主要是simulink的组件开发

## Matlab Function
### 1. 模块

MATLAB Function是一个支持使用M语言编写模块功能,并能够将所编写的M语言生成C代码，用于开发桌面应用和嵌入式应用的模块。它支持的 MATLAB内建函数比 Fcn模块要广泛，除去基本的四则运算、逻辑操作符和关系操作符，还可以调用MATLAB各种工具箱里提供的内建函数，包括支持代码生成和不支持代码生成两个类型。

```ruby
模块功能：将 MATLAB 代码包含在生成可嵌入式 C 代码的模型中
库：
Simulink / User-Defined Functions
HDL Coder / User-Defined Functions
```

此模块的特殊之处在于双击之后打开的不是参数对话框,而是一个M代码编辑窗，在这里编写M代码描述输出y与输入u之间的关系。模块拥有1个输入端口u和1个输出端口y。MATLAB Function的模块的图标上绘制一个MATLAB logo图案,如图所示。

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/e35329c7-278c-4b96-886e-af85bdebf6e9)

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/fbb89e86-e843-4467-aeb0-a2a62721f76d)

模块是否有输入输出端口取决于内部M函数的定义方式。

（1）没有输出
![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/25fded62-f217-429f-b3fb-a61e9be99577)
![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/7d9ebc3d-5d40-49dd-96c1-26f834fafebf)

（2）没有输入
![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/b57b4474-33a6-4a16-9e62-be22304c9686)
![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/b4634d93-bc63-4631-80bc-a375a42c29b0)

实例1 基本操作

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/cae1c4d5-b9a4-4727-863d-dc58429d613d)

```ruby
function y = fcn(u1,u2)
y = u1*u2;
end
```

点击界面的Go to Diagram可以从脚本视图跳转回仿真视图。

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/1b58383d-3eec-4ffc-86d7-be2c1cfc74ca)

点击Edit Data，可以对输入和输出数据进行编辑，例如数据的类型、尺寸等属性。

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/33164aeb-2e6b-44cf-b560-cb704ed980aa)

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/268f758c-3b9a-4aa4-b1ed-e5d2d241b42f)

模型运行结果

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/7d8b8e1a-7acd-4268-8af3-f5872f6d56ff)

实例2 多输入和多输出

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/7fd14472-f6ea-49b6-9903-b3dac8236182)

fcn1函数

```ruby
function [y,y1] = fcn1(u1,u2)
y = u1+u2;
y1 = u1*u2;
end
```

fcn2函数

```ruby
function [y,y1] = fcn2(u)
y = u(1)+u(2);
y1 = u(1)*u(2);
end
```

### 2.MATLAB Function里面使用if和for语句

实例3 MATLAB Function里面使用if语句

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/17d95e37-3e0b-433b-a226-db31fa1f1b83)

fcn4函数内容

```ruby
function y = fcn4(u)
 if u>=5
     y = 1;
 elseif u<0
     y = -1;
 else
     y = 0;
 end
end
```

运行结果

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/5cc92972-12da-47c3-8789-359651234500)

实例4  MATLAB Function里面使用for语句

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/ef4ead8b-d070-4943-a328-ec3a8774b597)

```ruby
function y = fcn5(u)
num = length(u);
y = 0;
for i = 1:1:num
    y = y +u(i);
end
end
```

运行结果

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/9ce40860-df9c-4082-9949-6e50bd1c163f)

### 3.MATLAB Function里面使用persistent保持变量
根据Simulink的运行机制,每个采样点会调用一次MATLAB Function的函数,两次调用之间,同一个变量的前次计算的终值如何传递到当前计算周期来是个问题,可以使用persistent 变量实现函数退出和进入时内部变量值的保持。
例如使用MATLAB Function编写一个能够累积输人值作为输出的模块-─累加模块。计算累加值需要一个状态变量,在每次调用fcn 时依据上一次的值进行累加,并将累加值存储在这个变量中。使用persistent声明这个变量可以实现此目的。persistent变量是定义在某个函数内的变量类型,可在函数调用的不同次数间保持上一次退出该函数的值。它同global全局变量的类似之处在于MATLAB为它们创建永久数据区域,不同之处在于它只能被声明它的函数内部识别,目的是免除此变量被其他函数或命令行修改值而造成用户无法确保其值的困扰。声明persistent变量时它刚刚被创建,还不具有初始值,其内容为空值[],调用声明persistent变量的函数时先判断persistent变量是否为空,如果是空则初始化为0 ,非空则直接使用,它们会记得上次被调用后的值。具体代码如下:

```ruby
function  y = fcn(u)
%% u 是模块的输入
% y 是模块的输出
%函数功能：实现对输入的累加
persistent sum_total  % 函数内部声明 可持续类型变量 sum_total
% 首先要判断persistent声明的变量是否是空
if isempty(sum_total)
    sum_total  = 0;
end
sum_total = sum_total +u; %进行累加
y = sum_total;
```

仿真图

将Clock模块的信号输入MATLAB Function模块并使用Scope模块接收y端口的输出值,解算器设置为固定步长,值为1 ,仿真结果如图所示。
设置步长为1

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/5fe16552-99c5-4611-8ba9-3f3a83a58761)

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/02207072-da86-4f2b-afab-5a5b30965eb2)

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/915856ed-3532-445e-82fd-20b01379e705)

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/8301bdd6-c8ed-47d4-830a-bfddbbe4011d)

经过10 s共11个采样点后，结果累加到55,等同于sum([0 : 10])。使用persistent变量时需要注意:

```ruby
（1）persistent变量不能作为函数的输入输出参数﹐否则会报错。
（2）persistent变量不能同当前工作空间中已经存在的变量同名，否则会
     报错。
（3）persistent变量不能声明在Command Window （命令窗口）里,必须在
    函数内声明。
```

### 4.添加trigger信号

在Edit data中添加触发信号。

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/7ed45219-f00c-4e44-b1e2-de2fb700d18c)

实例5 添加触发信号

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/c3cb7761-6e80-4580-b1ef-be0711d25182)

```ruby
function y = fcn6(u)
num = length(u);
y = 0;
for i = 1:1:num
    y = y +u(i);
end
end
```

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/8210dac4-edab-450b-9181-cb503e10f167)

### 5.Extrinsic函数

MATLAB Function模块支持在M编辑器内部定义子函数并调用,但是不支持递归调用。MATLAB Function可以将MATLAB内建函数编写的M函数生成C代码,如 sum,length , sqrt等(支持代码生成的M函数详细列表请搜索MATLAB自带 Help文档的Func-tions Supported for C/C+＋Code Generation — Alphabetical List.),使用不支持代码生成功能的MATLAB内建函数时,如绘图函数系列 plot , patch , bar和 figure等,需使用eml. extrinsic( 'plot ' , 'bar')来声明为Extrinsic函数,启动仿真后这些函数只用来仿真,不进行编译，从而不生成可独立运行的C/C＋＋代码及可执行文件。

Extrinsic函数的处理方式 :

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/5b57eca9-bfb3-47c9-a696-ed6d0926f8e7)

```ruby
模型进行仿真时,MATLAB生成调用Extrinsic函数的代码,但是不生成可执行代
码,仅保证这些函数能够在MATLAB环境下执行。模块生成代码时,MATLAB会判
断Extrinsic函数是否对调用它们的函数输出值有影响,如果有则产生编译器错
误,如果没有影响,则对声明为Extrinsic函数以外的函数进行代码生成,而忽略
此Extrinsic函数。
```

Simulink 的 Scope只能显示线条图像，目前的版本还不支持3-D绘图,不能像MATLAB那样提供各种功能强大的绘图功能。可使用MATLAB Function模块自定义一个模块绘制3-D图像。结合Extrinsic函数声明和Persistent变量的使用,可以在MATLAB Function模块中调用绘图函数绘图,并将每次从 Simulink模型获取的输入保存起来,如下所示例程:

```ruby
function  fcn(u)
%% 绘制三维图形
eml.extrinsic('plot3','scatter3','delete','close');%声明不能生成c代码的函数
len = length(u);%计算输入的长度
persistent data  %声明持续性变量
if isempty(data) %判断持续性变量是否是空值
    data = zeros(3,100000);%初始化
end
persistent n  %声明采样数据次数的持续性变量 n
if isempty(n)
    n = 1;
else
    n = n +1;
end
data(:,n) = u;%存储输入的数据 3*n  每列数据是一个三维坐标(x,y,z)
persistent  h  
if isempty(h)
    h = plot3(data(1,:),data(2,:),data(3,:),'bo');
else
    delete(h);%每个采样时刻重新绘制图像以达到动态刷新的效果
     h = plot3(data(1,:),data(2,:),data(3,:),'bo');
end
```

模型建立时使用Clock模块, Fcn模块和Mux模块构成正弦、余弦和时间量3维输入。运行模型之后,会动态地绘制出每个采样时刻计算的值到坐标轴中,构成逐步上升的螺旋3-D图形，如图所示。

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/36bf99a1-aee0-48da-81bf-5dcefbd27397)

![640](https://github.com/tqlnb/MatlabStudy/assets/88382462/b2db8ee7-3714-4f3c-b52b-9d03b9822d00)

### 5.参考内容

[1] 博客园作者叮叮当当sunny的文章《Simulink仿真入门到精通（二） Simulink模块 》，文章链接如下：https://www.cnblogs.com/dingdangsunny/p/12235689.html#_label0

[2] 孙忠潇.Simulink仿真及代码生成技术入门到精通[M].北京:北京航空航天大学出版社,2015.

[3] 云龙派微信公众号文章 https://mp.weixin.qq.com/s/az5zIws8miwZpurArFGzVA


## S Function

### S Function简介

S-Function是system-function系统函数的缩写，是指采用非图形化的方式描述的一个功能模块，即用户
编写程序满足自己的模型需求

**特点:**

可以使用多种语言进行编写比如 M，C，C++;能够响应Simulink求解器，可以开发新的Simulink模块
扩展Simulink功能。M文件的S-function可以扩展图形能力，C-MEX的S-function可以提供与操作系统的接口
可以与已有的代码相结合进行仿真;采用文本方式输入复杂的系统方程

![image](https://github.com/tqlnb/MatlabStudy/assets/88382462/d54479b4-a7c7-4a65-aebd-0a405d2927b8)

![image](https://github.com/tqlnb/MatlabStudy/assets/88382462/0f409702-4a5b-49f8-a7b2-f2ad154935fa)
![image](https://github.com/tqlnb/MatlabStudy/assets/88382462/baff93d4-2269-4be7-a163-e61c4a70843c)
![image](https://github.com/tqlnb/MatlabStudy/assets/88382462/5a0067eb-62f4-490f-b6a6-7645a2c193d2)

 1. s-function name: 填入S-function的函数名称，这样就建立了S-function模块与M文件形式的S-function之间的对应关系，需将程序放到当前路径下;
 2. S-function parameters:填入S-function需要输入的外部参数的名称，如果有对各变量则变量中间用逗号隔开，如a，b，c;
 3. S-function modules;仅当S-function是用C语言编写并用MEX工具编译的C-MEX文件时才需要填写该参数

### S Function仿真流程

S-function包括主函数和6个功能子函数

```ruby
mdllnitializeSizes (初始化)
mdlDerivatives(连续状态微分)
mdlUpdate(离散状态更新)
mdlOutputs (模块输出)
mdlGetTimeOfNextVarHit (计算下次采样时刻)
mdlTerminate(仿真结束)
```

![image](https://github.com/tqlnb/MatlabStudy/assets/88382462/80049ea4-ff4f-4493-add3-69ca5f51f320)

**S Function模板**

```matlab
function [sys,x0,str,ts,simStateCompliance] = sfuntmpl(t,x,u,flag)
%% 输入量
%  t:当前时间
%  x：状态向量 
%  u：输入向量   
%  flag：标志位（默认是0）
%% 输出量
%  sys：是s-function通用的返回参数。返回值取决于flag的值。例如：flag=3，sys则包含了S-function的输出；
%  x0——状态初始值（如果系统中没有状态，则向两位空）；
%  str——默认为空，无需设置；
%  ts——采样时间，包含采样时间和偏移量；
%  simStateComplicance——附加变量；
switch flag,
  case 0,
    [sys,x0,str,ts,simStateCompliance]=mdlInitializeSizes; %初始化子函数，必须执行
  case 1,
    sys=mdlDerivatives(t,x,u); %连续状态的导数
  case 2,
    sys=mdlUpdate(t,x,u);      %对离散方程的更新，更新到x(n+1)
  case 3,
    sys=mdlOutputs(t,x,u);     %将计算结果输出到Simulink中
  case 4,
    sys=mdlGetTimeOfNextVarHit(t,x,u); %获取下一个采样时间点，通常是变步长模型才用
  case 9,
    sys=mdlTerminate(t,x,u);   %函数终止
  otherwise
    DAStudio.error('Simulink:blocks:unhandledFlag', num2str(flag));  %若是其他flag，则报警。
end
%  以上是s-function的主函数，以下六个是子函数。
%
%% 初始化函数
function [sys,x0,str,ts,simStateCompliance]=mdlInitializeSizes

sizes = simsizes;

sizes.NumContStates  = 0;  %连续状态的数量
sizes.NumDiscStates  = 0;  %离散状态的数量
sizes.NumOutputs     = 0;  %输出的数量
sizes.NumInputs      = 0;  %输入的数量
sizes.DirFeedthrough = 1;  %输出y和输入u是否是直通
sizes.NumSampleTimes = 1;  %采样时间

sys = simsizes(sizes);
x0  = []; %初始状态，没有则放空
str = []; %正常都为空
ts  = [0 0];% [0 0]表示默认采样时间 [-1 0]表示继承父层级的时间
simStateCompliance = 'UnknownSimState';

%% 连续状态的导数，有状态方程的情况下才用
function sys=mdlDerivatives(t,x,u)

sys = [];

%% 离散状态的更新 有状态方程的情况下才用
function sys=mdlUpdate(t,x,u)

sys = [];

%% 输出，直通的模型，直接只在这个模块写代码就可以
function sys=mdlOutputs(t,x,u)

sys = [];

%% 设置下一次采样时间
function sys=mdlGetTimeOfNextVarHit(t,x,u)

sampleTime = 1;    %  Example, set the next hit to be one second later.
sys = t + sampleTime;

function sys=mdlTerminate(t,x,u)

sys = [];
```


**c语言的S Function模板**

```c
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

```
























