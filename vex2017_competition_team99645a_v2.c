#pragma platform(VEX)
#pragma config(Sensor, in1,    armangle,       sensorPotentiometer)
#pragma config(Motor,  port1,           frontright,    tmotorVex393, openLoop)
#pragma config(Motor,  port2,           rearright,     tmotorVex393, openLoop)
#pragma config(Motor,  port3,           gear1,         tmotorVex393, openLoop)
#pragma config(Motor,  port4,           chain1,        tmotorVex393, openLoop)
#pragma config(Motor,  port5,            claw1,         tmotorVex393, openLoop)
#pragma config(Motor,  port6,           claw2,         tmotorVex393, openLoop)
#pragma config(Motor,  port7,           chain2,        tmotorVex393, openLoop)
#pragma config(Motor,  port8,           gear2,         tmotorVex393, openLoop)
#pragma config(Motor,  port9,           rearleft,      tmotorVex393, openLoop)
#pragma config(Motor,  port10,          frontleft,     tmotorVex393, openLoop)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!    


void pre_auton()
{
  bStopTasksBetweenModes = true;
}



task autonomous()
{
  ClearTimer(T1);
	while(time1[T1] < 500){
		motor[port1] = 75;
		motor[port10] = 75;
		motor[port2] = -75;
		motor[port9] = -75;
	}//move foward
	ClearTimer(T1);
	while(time1[T1]<3000){
		motor[port3]=127;
		motor[port4]=127;
		motor[port7]=127;
		motor[port8]=127;
 }//move arm
 ClearTimer(T1);
 while(time1[T1]<1100){
		motor[port5]=100;
		motor[port6]=100;

		motor[port3]=25;
		motor[port4]=25;
		motor[port7]=25;
		motor[port8]=25;

 }//keep arm,open claw
 ClearTimer(T1);
 while(time1[T1]<1500){
		motor[port1]=75;
		motor[port10]=75;
		motor[port2]=-75;
		motor[port9]=-75;
 }//go front
 ClearTimer(T1);
 while(time1[T1]<1500){
		motor[port1]=75;
		motor[port10]=75;
		motor[port2]=75;
		motor[port9]=75;

		motor[port3]=-100;
		motor[port4]=-100;
		motor[port7]=-100;
		motor[port8]=-100;
	}//turn 108~120 right,down arm
	ClearTimer(T1);
 while(time1[T1]<1500){
		motor[port1]=85;
		motor[port10]=85;
		motor[port2]=-85;
		motor[port9]=-85;
 }//go front
 ClearTimer(T1);
	while(time1[T1]<2500){
		motor[port5]=-127;
		motor[port6]=-127;
 }//close claw
 ClearTimer(T1);
 while(time1[T1]<500){
		motor[port3]=95;
		motor[port4]=95;
		motor[port7]=95;
		motor[port8]=95;
 }//arm half up
}

int limit(int x){
	if(x> 127){
		return 127;
		}
		else if(x < -127){
			return -127;
		}
		else{
			return x;
		}
}

task usercontrol()
{
  while (true)
	{
	  motor[port1] = limit(-vexRT[Ch2] - vexRT[Ch1] + vexRT[Ch4])/1.4;
		motor[port2] = limit(vexRT[Ch2] - vexRT[Ch1] + vexRT[Ch4])/1.4;
		motor[port9] = limit(-vexRT[Ch2] + vexRT[Ch1] + vexRT[Ch4])/1.4;
		motor[port10] = limit(vexRT[Ch2] + vexRT[Ch1] + vexRT[Ch4])/1.4;

		int fixedangle;
		int movingangle;


		SensorValue[in1]=movingangle;//semiautomatic control
		if(vexRT[Btn5D]==0&&Btn5U==0){
			SensorValue[in1]=fixedangle;//how it works:save movingangle in var-> no input btn->save fixedangle->
			                            //gravity down->move motor to fixedangle

			if(fixedangle>movingangle){
				while(fixedangle=movingangle){
				motor[port3]=50;
				motor[port8]=50;
				motor[port4]=50;
				motor[port7]=50;
			}
		}
		else if(fixedangle<movingangle){
			while(fixedangle=movingangle){
				motor[port3]=-50;
				motor[port8]=-50;
				motor[port4]=-50;
				motor[port7]=-50;
			}
		}
		else{
			motor[port3]=0;
			motor[port8]=0;
			motor[port4]=0;
			motor[port7]=0;
		}

	}//automatic control

	if(vexRT[Btn5U]==1){
		motor[port3]=-127;
		motor[port8]=-127;
		motor[port4]=-127;
		motor[port7]=-127;
	}
	else if(vexRT[Btn5D]==1){
		motor[port3]=127;
		motor[port8]=127;
		motor[port4]=127;
		motor[port7]=127;
	}
	else if(vexRT[Btn6U]==1){
		motor[port5]=-127;
		motor[port6]=-127;


	}

	else if(vexRT[Btn6D]==1){
		motor[port5]=127;
		motor[port6]=127;


	}
	else {
		motor[port3]=0;
		motor[port8]=0;
		motor[port4]=0;
		motor[port7]=0;
		motor[port6]=-10;
		motor[port5]=-10;
	}

	}//while end

}
