#ifndef  SystemState_H
#define  SystemState_H


#include "cmsis_os.h"
#include "stm32f4xx_hal.h"

#define OutLine_Time 50 //断线检测时间
#define Motor_Stall_Time 200
#define Motor_Stall_Spd 5

#define MyFlagSet(x,y) x=x|(0x00000001<<y) //设置标志位  y第几位
#define MyFlagClear(x,y) x=x&~(0x00000001<<y)
#define MyFlagGet(x,y) (x&(0x00000001<<y))



typedef struct{
	short Mode;//运行模式
	short Enable;//状态
	short State;//状态
	short Task;//任务
//	BEEPMode Beep;//蜂鸣器
	int Time;//System run time mm
	TIM_HandleTypeDef *htim;//时间计数器句柄
	uint16_t OutLine_Flag;//断线标志
	uint16_t task_OutLine_Flag;//断线标志	
//	RobotDistDef RobotDist;//机器人测量
}SystemStateDef;

extern SystemStateDef SystemState;
//extern SystemStateDef Remote;
//extern SystemStateDef Gimbal_Motor;
//extern SystemStateDef JY61;

typedef enum
{

		Yaw_NO,
		Pitch_NO,
  	Minipc_NO,
  Remote_NO,
	
		DeviceTotal_No	
}DeviceX_NoDEF;

typedef enum
{

	GimbalContrlTask_ON,
  vOutLineCheckTask_ON,
	MiniPC_Data_task_ON,
	RemoteDataTask_ON,
	
	TASKTotal_No	
}TASK_NoDEF;


int SystemState_Inite(void);//SystemState初始化
void RefreshSysTime(void);//刷新系统时间（mm）
uint32_t GetSystemTimer();//获取系统当前准确时间


void OutLine_Check(void);//断线检测检测
void TASK_Check(void);//任务检测
void RefreshDeviceOutLineTime(DeviceX_NoDEF DevX_No);//刷新外设通信时间时间数组
void RefreshTaskOutLineTime(TASK_NoDEF Task_No);

void vOutLineCheck_Task(void const *argument);


#endif
