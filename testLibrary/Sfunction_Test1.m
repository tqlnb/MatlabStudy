function [sys,x0,str,ts,simStateCompliance] = Sfunction_Test1(t,x,u,flag,gain)
% 保存的函数文件名
switch flag
%初始化函数
case 0
[sys,x0,str,ts,simStateCompliance]=mdlInitializeSizes;
%求导数
case 1
sys=mdlDerivatives(t,x,u);
%状态更新
case 2
sys=mdlUpdate(t,x,u);
%计算输出
case 3
sys=mdlOutputs(t,x,u,gain);
%计算下一个采样时间
case 4
sys=mdlGetTimeOfNextVarHit(t,x,u);
%终止仿真程序
case 9
sys=mdlTerminate(t,x,u);
%错误处理
otherwise
DAStudio.error('Simulink:blocks:unhandledFlag', num2str(flag));
end
%% mdlInitializeSizes 模型初始化函数，返回；
% sys 是系统参数
% x0 系统初始状态，若没有，则x0=[]；
% str 系统阶字串，常取 str=[];
% ts 取样时间矩阵，对于连续取样时间 ts=[0,0]
% 若使用内部取样时间，ts=[-1,0],-1表示继承输入信号的采样周期
function [sys,x0,str,ts,simStateCompliance]=mdlInitializeSizes%模型初始化函数
sizes = simsizes; %取系统默认设置
sizes.NumContStates = 0; %设置连续状态变量的个数
sizes.NumDiscStates = 0; %设置离散状态
sizes.NumOutputs = 1; %系统输出个数
sizes.NumInputs = 1; %系统输入个数
sizes.DirFeedthrough = 1; %系统是否直通，注：输入信号是否在输出段出现的标识。取 0 或 1
sizes.NumSampleTimes = 1; %采样周期个数，必须大于1或等于1；
sys = simsizes(sizes); %设置系统参数
x0 = []; %系统状态初始化
str = []; %系统阶字串总为空阶
ts = [0 0]; %初始化采用时间矩阵
simStateCompliance = 'UnknownSimState';
%% mdlDerivatives 模型计算导数——连续部分的计算，返回连续状态的导数
function sys=mdlDerivatives(t,x,u)

sys = []; %根据状态方程（微分部分） 修改此处
%% mdlUpdate 计算离散状态方程
function sys=mdlUpdate(t,x,u)
sys = []; %根据状态方程（差分方程部分）修改此处
%% mdlOutputs 计算输出信号，返回模块输出
function sys=mdlOutputs(t,x,u,gain)
sys = gain*u; %根据输出方程修改此处
%% mdlGetTimeOfNextVarHit 计算一步的仿真时刻，该函数仅当
% mdlInitializeSizes函数中的采样时间向量定义了一个可变离散采样时间 ts = [-2,0]时才被使用
function sys=mdlGetTimeOfNextVarHit(t,x,u)
sampleTime = 1; % Example, set the next hit to be one second later.
sys = t + sampleTime;
%% mdlTerminate 终止仿真设定，完成仿真终止时的任务
function sys=mdlTerminate(t,x,u)
sys = [];
%% 程序end