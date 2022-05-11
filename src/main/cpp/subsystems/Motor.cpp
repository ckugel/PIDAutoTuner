// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Motor.h"

Motor::Motor(std::function<TalonFX(int id)> factoryFalcon, std::function<TalonSRX(int id)> factoryTalon) {
  if (Config::usingFalcon) {
    motorToTest = std::make_shared<TalonFX>(factoryFalcon(CAN_Constants::CAN_ID_MAIN));
    if (Config::following) {
      motorFollower = std::make_shared<TalonFX>(factoryFalcon(CAN_Constants::CAN_ID_FOLLOW));
      motorFollower->Follow(*(motorToTest.get()));
    }
  }
  else {
    srx_motorToTest = std::make_shared<TalonSRX>(factoryTalon(CAN_Constants::CAN_ID_MAIN));
    if (Config::following) {
      srx_motorFollower = std::make_shared<TalonSRX>(factoryTalon(CAN_Constants::CAN_ID_FOLLOW));
      srx_motorFollower->Follow(*(motorToTest.get()));
    }
  }
  // no memory management required because smart pointers are amazing
}

void Motor::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void Motor::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
