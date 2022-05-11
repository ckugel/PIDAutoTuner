// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include "Constants.h"

class Motor : public frc2::SubsystemBase {
 public:
  Motor(std::function<TalonFX(int id)> factoryFalcon, std::function<TalonSRX(int id)> factorTalon);
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

 private:
    std::shared_ptr<TalonFX> motorToTest;
    std::shared_ptr<TalonFX> motorFollower;

    std::shared_ptr<TalonSRX> srx_motorToTest;
    std::shared_ptr<TalonSRX> srx_motorFollower;
};
