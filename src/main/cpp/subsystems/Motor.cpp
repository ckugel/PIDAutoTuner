// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Motor.h"
#include "Factory.h"

Motor::Motor() {
  motor = Factory::makeMotors();
  // no memory management required because smart pointers are amazing
}

void Motor::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void Motor::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
