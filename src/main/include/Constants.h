// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace CAN_Constants {
    constexpr int CAN_ID_MAIN = 0;
    constexpr int CAN_ID_FOLLOW = 1;
}

namespace Config {
    constexpr bool usingFalcon = true;
    constexpr bool position = false;
    constexpr bool velocity = !position;
    constexpr bool wpilibPID = false;
    constexpr bool following = false;
    constexpr bool brake = false;
    constexpr bool reversed = false;
    constexpr bool facingSameWay = false;
    constexpr double voltageCompensation = 9;

    constexpr double kFalconTicksPerRevolution = 2048;
    constexpr double kMotorTicksPerRevolution = 1024;

    constexpr double nonFalconRPM = 2000;

    constexpr double gearRatio = 1;

    constexpr double metersToTicks = 1 / ((kFalconTicksPerRevolution * !usingFalcon + kMotorTicksPerRevolution * usingFalcon) / gearRatio); 

    constexpr double posSetpoint = 3 * metersToTicks;

    constexpr double RPMToTicks = ((kFalconTicksPerRevolution * usingFalcon + kMotorTicksPerRevolution * !usingFalcon) / (10 * 60) / gearRatio);

    constexpr double velocitySetpoint = (usingFalcon * 3000 + !usingFalcon * nonFalconRPM) * RPMToTicks;
}

namespace PIDF {
    double kP;
    double kI;
    double kD;
    double kF; 
}

