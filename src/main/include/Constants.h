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
    constexpr bool wpilibPID = false;
    constexpr bool following = false;
    constexpr bool brake = false;
    constexpr bool reversed = false;
    constexpr bool facingSameWay = false;
}

namespace PIDF {
    constexpr double kP;
    constexpr double kI;
    constexpr double kD;
    constexpr double kF; 
}

