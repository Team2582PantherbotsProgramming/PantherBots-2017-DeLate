// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ROBOTMAP_H
#define ROBOTMAP_H

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "WPILib.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static std::shared_ptr<SpeedController> driveTrainLeftFront;
	static std::shared_ptr<SpeedController> driveTrainLeftBack;
	static std::shared_ptr<SpeedController> driveTrainRightFront;
	static std::shared_ptr<SpeedController> driveTrainRightBack;
	static std::shared_ptr<RobotDrive> driveTrainRobotDrive;
	static std::shared_ptr<Compressor> driveTrainCompressor;
	static std::shared_ptr<AnalogInput> driveTrainUltrasonic;
	static std::shared_ptr<SpeedController> intakeGearTopRoller;
	static std::shared_ptr<SpeedController> intakeGearBottomRoller;
	static std::shared_ptr<DigitalInput> intakeGearLaser;
	static std::shared_ptr<DoubleSolenoid> moveIntakeDoubleSolenoid1;
	static std::shared_ptr<DoubleSolenoid> moveIntakeDoubleSolenoid2;
	static std::shared_ptr<DoubleSolenoid> moveBoxDoubleSolenoid1;
	static std::shared_ptr<DoubleSolenoid> moveBoxDoubleSolenoid2;
	static std::shared_ptr<SpeedController> climberClimb1;
	static std::shared_ptr<SpeedController> climberClimb2;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	static std::shared_ptr<ADXRS450_Gyro> driveTrainGyro;

	static void init();
};
#endif
