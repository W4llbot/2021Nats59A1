#include "main.h"
#include "mech_lib.hpp"
#include "autonSets.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	Motor FL(FLPort, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
	Motor BL(BLPort, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
	Motor FR(FRPort, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
	Motor BR(BRPort, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
	Motor shooter(shooterPort, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
	Motor router(routerPort, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES);
	Motor lRoller(lRollerPort, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
	Motor rRoller(rRollerPort, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);

	Vision routerVision (routerVisionPort);
	ADIAnalogIn shooterLine(shooterLinePort);
	Imu imu(imuPort);
	imu.reset();

	Task routerControlTask(routerControl, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT);
	Task shooterControlTask(shooterControl, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT);
	Task controlTask(Control, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT);
	Task debugTask(Debug, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT);
	Task odometryTask(Odometry, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT);
	Task sensorsTask(Sensors, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	skillsRoute();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	Motor FL(FLPort);
	Motor BL(BLPort);
	Motor FR(FRPort);
	Motor BR(BRPort);
	Motor shooter(shooterPort);
	Motor router(routerPort);
	Motor lRoller(lRollerPort);
	Motor rRoller(rRollerPort);

	Controller master(E_CONTROLLER_MASTER);

	double left, right;
	bool isTank = true;
	bool autosort = false;
	while(true) {
		if(master.get_digital_new_press(DIGITAL_Y)) isTank = !isTank;

		if(isTank) {
			left = master.get_analog(ANALOG_LEFT_Y);
			right = master.get_analog(ANALOG_RIGHT_Y);
		}else {
			double power = master.get_analog(ANALOG_LEFT_Y);
			double turn = master.get_analog(ANALOG_RIGHT_X);

			left = power + turn;
			right = power - turn;
		}

		FL.move(left);
		BL.move(left);
		FR.move(right);
		BR.move(right);

		if(master.get_digital_new_press(DIGITAL_A)){
			autosort = !autosort;
			enableAutosort(autosort);
		}

		int intakePower = (master.get_digital(DIGITAL_L1) - master.get_digital(DIGITAL_L2)) * 127;
		lRoller.move(intakePower);
		rRoller.move(intakePower);

		if(autosort) {
			if(master.get_digital_new_press(DIGITAL_X)) toggleDiscardSig();
			if(master.get_digital(DIGITAL_R1)) shootBall();
		}else {
			int shooterPower = (master.get_digital(DIGITAL_R1) - master.get_digital(DIGITAL_R2)) * 127;
			if(intakePower < -10) forceOuttake(true);
			else forceOuttake(false);
			shooter.move(shooterPower);
		}
		// printf("imu rotation: %.2f\n", imu.get_rotation());
		// master.print(2, 0, "%.2f", (bL.get_position() - bR.get_position())*inPerDeg/baseWidth*toDeg);
		delay(5);
	}
}
