//Written By Prokuma, v990315 in 2016
//License : MIT
//Organization : Songdo High School RnB Clubs
#pragma userControlDuration(60)
#pragma platform(VEX)
#pragma config(Sensor, dgtl1,  sonarSensor,         sensorSONAR_cm)

#include "Vex_Competition_Include.c"

//Definition of Motor
#define frontMotor1 port1
#define frontMotor2 port2
#define backMotor1 port3
#define backMotor2 port4
//left of pully motor is frontMotor1
//Motor turn clockwise rotation is -, not +


//Definition of Button


//Definition of Sensor


//This definition for Auto Mode


void pre_auton(){
	bStopTasksBetweenModes = true;
}

int limit(int x){
	if(x> 127){return 127;}else if(x < -127){return -127;}else{return x;}
}

task autonomous() {
}

task usercontrol() {
	while(true){
		motor[frontMotor1] = limit(vexRT[Ch2] + vexRT[Ch1] + vexRT[Ch3]);
		motor[frontMotor2] = limit(-vexRT[Ch2] + vexRT[Ch1] + vexRT[Ch3]);
		motor[backMotor1] = limit(vexRT[Ch2] - vexRT[Ch1] + vexRT[Ch3]);
		motor[backMotor2] = limit(-vexRT[Ch2] - vexRT[Ch1] + vexRT[Ch3]);
	}
}
