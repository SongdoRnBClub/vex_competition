//Written By Prokuma, v990315 in 2016
//License : MIT
//Organization : Songdo High School RnB Club
#pragma userControlDuration(60)
#pragma platform(VEX)
#pragma config(Sensor, dgtl1,  sonarSensor,         sensorSONAR_cm)

#include "Vex_Competition_Include.c"

//Definition of Motor
#define leftMotor port1
#define rightMotor port2
#define leftGrap port3
#define rightGrap port4
const char pully {port5, port6, port7, port8, port9, port10}

//Definition of Button
#define leftGrapButtonIncrease Btn5U
#define rightGrapButtonIncrease Btn6U
#define leftGrapButtonDecrease Btn5D
#define rightGrapButtonDecrease Btn6D
#define upPullyButton Btn8R
#define downPullyButton Btn7L

//This definition for Auto Mode
#define spinTime 3000
#define pullyTime 3000
#define straightTime 3000

void pre_auton(){
	bStopTasksBetweenModes = true;
}

void pully(int x){
	int i;
	for(i = 0; i < 9 ; i++){
		motor[pully[i]] = x;
	}
}

task autonomous() {
	ClearTimer(T1);
	while(time1[T1] < spinTime){
		motor[leftMotor] = -25;
		motor[rightMotor] = 25;
	}
	ClearTimer(T1);
	while(time1[T1] < pullyTime){
		pully(30);
	}
	ClearTimer(T1);
	while(time1[T1] < spinTime){
		motor[leftMotor] = 25;
		motor[rightMotor] = -25;
	}
	ClearTimer(T1);
	while(time1[T1] < straightTime){
		motor[leftMotor] = 30;
		motor[rightMotor] = 30;
	}
	ClearTimer(T1);
	while(time1[T1] < pullyTime){
		pully(30);
  }
}

task usercontrol(){
	while(true){
		motor[leftMotor] = vexRT[Ch3];
		motor[rightMotor] = vexRT[Ch2];
		if(vexRT[leftGrapButtonIncrese] == 1){motor[leftGrap] = 30;}else{motor[leftGrap] = 0;}
		if(vexRT[rightGrapButtonIncrese] == 1){motor[rightGrap] = 30;}else{motor[rightGrap] = 0;}
		if(vexRT[leftGrapButtonDecrese] == 1){motor[leftGrap] = -30;}else{motor[leftGrap] = 0;}
		if(vexRT[rightGrapButtonDecrese] == 1){motor[rightGrap] = -30;}else{motor[rightGrap] = 0;}
		if(vexRT[upPullyButton] == 1){motor[upPully] = 80;}else{motor[upPully] = 0;}
		if(vexRT[downPullyButton] == 1){motor[downPully] = -80;}else{motor[downPully] = 0;}
	}
}
