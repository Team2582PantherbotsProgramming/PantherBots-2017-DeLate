// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<SpeedController> RobotMap::driveTrainLeftFront;
std::shared_ptr<SpeedController> RobotMap::driveTrainLeftBack;
std::shared_ptr<SpeedController> RobotMap::driveTrainRightFront;
std::shared_ptr<SpeedController> RobotMap::driveTrainRightBack;
std::shared_ptr<RobotDrive> RobotMap::driveTrainRobotDrive;
std::shared_ptr<Compressor> RobotMap::driveTrainCompressor;
std::shared_ptr<AnalogInput> RobotMap::driveTrainUltrasonic;
std::shared_ptr<SpeedController> RobotMap::intakeGearTopRoller;
std::shared_ptr<SpeedController> RobotMap::intakeGearBottomRoller;
std::shared_ptr<DigitalInput> RobotMap::intakeGearLaser;
std::shared_ptr<DoubleSolenoid> RobotMap::moveIntakeDoubleSolenoid1;
std::shared_ptr<DoubleSolenoid> RobotMap::moveIntakeDoubleSolenoid2;
std::shared_ptr<DoubleSolenoid> RobotMap::moveBoxDoubleSolenoid1;
std::shared_ptr<DoubleSolenoid> RobotMap::moveBoxDoubleSolenoid2;
std::shared_ptr<SpeedController> RobotMap::climberClimb1;
std::shared_ptr<SpeedController> RobotMap::climberClimb2;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<ADXRS450_Gyro> RobotMap::driveTrainGyro;

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    driveTrainLeftFront.reset(new Spark(0));
    lw->AddActuator("DriveTrain", "LeftFront", std::static_pointer_cast<Spark>(driveTrainLeftFront));
    
    driveTrainLeftBack.reset(new Spark(1));
    lw->AddActuator("DriveTrain", "LeftBack", std::static_pointer_cast<Spark>(driveTrainLeftBack));
    
    driveTrainRightFront.reset(new Spark(2));
    lw->AddActuator("DriveTrain", "RightFront", std::static_pointer_cast<Spark>(driveTrainRightFront));
    
    driveTrainRightBack.reset(new Spark(3));
    lw->AddActuator("DriveTrain", "RightBack", std::static_pointer_cast<Spark>(driveTrainRightBack));
    
    driveTrainRobotDrive.reset(new RobotDrive(driveTrainLeftFront, driveTrainLeftBack,
              driveTrainRightFront, driveTrainRightBack));
    
    driveTrainRobotDrive->SetSafetyEnabled(false);
        driveTrainRobotDrive->SetExpiration(0.1);
        driveTrainRobotDrive->SetSensitivity(0.5);
        driveTrainRobotDrive->SetMaxOutput(1.0);

    driveTrainCompressor.reset(new Compressor(0));
    
    
    driveTrainUltrasonic.reset(new AnalogInput(0));
    lw->AddSensor("DriveTrain", "Ultrasonic", driveTrainUltrasonic);
    
    intakeGearTopRoller.reset(new Talon(6));
    lw->AddActuator("IntakeGear", "TopRoller", std::static_pointer_cast<Talon>(intakeGearTopRoller));
    
    intakeGearBottomRoller.reset(new Spark(7));
    lw->AddActuator("IntakeGear", "BottomRoller", std::static_pointer_cast<Spark>(intakeGearBottomRoller));
    
    intakeGearLaser.reset(new DigitalInput(0));
    lw->AddSensor("IntakeGear", "Laser", intakeGearLaser);
    
    //Warning, the two modules in robot builder are different!
moveIntakeDoubleSolenoid1.reset(new DoubleSolenoid(0, 0, 7));
    lw->AddActuator("MoveIntake", "Double Solenoid 1", moveIntakeDoubleSolenoid1);
    
    //Warning, the two modules in robot builder are different!
moveIntakeDoubleSolenoid2.reset(new DoubleSolenoid(1, 1, 6));
    lw->AddActuator("MoveIntake", "Double Solenoid 2", moveIntakeDoubleSolenoid2);
    
    //Warning, the two modules in robot builder are different!
moveBoxDoubleSolenoid1.reset(new DoubleSolenoid(2, 2, 5));
    lw->AddActuator("MoveBox", "Double Solenoid 1", moveBoxDoubleSolenoid1);
    
    //Warning, the two modules in robot builder are different!
moveBoxDoubleSolenoid2.reset(new DoubleSolenoid(3, 3, 4));
    lw->AddActuator("MoveBox", "Double Solenoid 2", moveBoxDoubleSolenoid2);
    
    climberClimb1.reset(new Spark(4));
    lw->AddActuator("Climber", "Climb1", std::static_pointer_cast<Spark>(climberClimb1));
    
    climberClimb2.reset(new Spark(5));
    lw->AddActuator("Climber", "Climb2", std::static_pointer_cast<Spark>(climberClimb2));
    


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    driveTrainGyro.reset(new ADXRS450_Gyro(SPI::Port::kOnboardCS0));
    lw->AddSensor("DriveTrain", "Gyro", driveTrainGyro);
}
