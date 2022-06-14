// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "subsystems/Motor.h"
#include "Factory.h"

#include <iostream>

Motor::Motor() {
  motor = Factory::makeMotors();
  // no memory management required because smart pointers are amazing

  netTablesInst = nt::NetworkTableInstance::GetDefault();
  table = netTablesInst.GetTable("tuner");

  kP = table->GetEntry("P");
  kI = table->GetEntry("I");
  kD = table->GetEntry("D");
  kF = table->GetEntry("F");

  setPoint = table->GetEntry("Setpoint");
  Error = table->GetEntry("Error");
  mode = table->GetEntry("Mode");
  errorDerviitve = table->GetEntry("Error Derivative");
  activeVelocityTrajectory = table->GetEntry("active velocity trajectory");
}

void Motor::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void Motor::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}

void Motor::updateShuffledboard() {
  setPoint.SetDouble(motor->GetClosedLoopTarget());
  Error.SetDouble(motor->GetClosedLoopError());
}

void Motor::updateValuesFromShuffleBoard() {
  PIDF::kP = kP.GetDouble(PIDF::kP);
  PIDF::kI = kI.GetDouble(PIDF::kI);
  PIDF::kD = kD.GetDouble(PIDF::kD);
  PIDF::kF = kF.GetDouble(PIDF::kF);
}

void Motor::resetPIDLoop() {
  updateValuesFromShuffleBoard();
  motor->Config_kI(0, PIDF::kI);
  motor->Config_kD(0, PIDF::kD);
  motor->Config_kF(0, PIDF::kF);
  motor->Config_kP(0, PIDF::kP);
}


void Motor::setMotorSetpoint() {
  resetPIDLoop();
  motor->Set(((int) ControlMode::MotionMagic) * Config::position + ((int) ControlMode::Velocity) * Config::velocity, Config::position * Config::posSetpoint + Config::velocitySetpoint * Config::velocity);
}


