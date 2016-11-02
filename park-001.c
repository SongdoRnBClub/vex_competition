#pragma userControlDuration(60)
#pragma platform(VEX)
#pragma config(Sensor, dgtl1,  sonarSensor,         sensorSONAR_cm)

#include "Vex_Competition_Include.c"

//Definition of Motor
#define leftMotor port1
#define rightMotor port2
#define leftGrap port3
#define rightGrap port4
const char pully {port5, port6, port7}

//Definition of Button
#define leftGrapButtonIncrese Btn5U
#define rightGrapButtonIncrease Btn6U
#define leftGrapButtonDecrease Btn5D
#define rightGrapButtonDecrease Btn6D
#define upPullyButton Btn8R
#define downPullyButton Btn7L

//Definition of Sensor
#define gyroSensor in1
#define sonarSensor in2

//This definition for Auto Mode
#define pullyTime 300
#define straightTime 3000

void pre_auton(){
	bStopTasksBetweenModes = true;
}

void pully(int x){
	int i;
	for(i = 0; i < 2 ; i++){
		motor[pully[i]] = x;
	}
}

task autonomoues() {
	sensorType[gyroSensor] = sensorGyro;
	while(abs(SensorValue(gyroSensor) < 900){
		motor[leftMotor] = -25;
		motor[rightMotor] = 25;
	}
	ClearTimer(T1);
	while(time1[T1] < pullyTime){
		pully(30);
	}
	while(abs(SensorValue(gyroSensor) > 0){
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
	}
}
