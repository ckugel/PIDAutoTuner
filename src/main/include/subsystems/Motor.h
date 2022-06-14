// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include "Constants.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

class Motor : public frc2::SubsystemBase {
 public:
  Motor();
  ~Motor();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

  void updateShuffledboard();

  void updateValuesFromShuffleBoard();

  void resetPIDLoop();

  void setMotorSetpoint();

 protected:
    std::shared_ptr<BaseTalon> motor;
    bool atSetpoint;

    nt::NetworkTableInstance netTablesInst;
    std::shared_ptr<nt::NetworkTable> table;

    nt::NetworkTableEntry& kP;
    nt::NetworkTableEntry& kI;
    nt::NetworkTableEntry& kD;
    nt::NetworkTableEntry& kF;
    
    nt::NetworkTableEntry& setPoint;
    nt::NetworkTableEntry& Error;
    nt::NetworkTableEntry& mode;
    nt::NetworkTableEntry& errorDerviitve;
    nt::NetworkTableEntry& activeVelocityTrajectory;
};

