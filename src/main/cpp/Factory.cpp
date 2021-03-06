#include "Factory.h"

std::shared_ptr<TalonFX> Factory::makeFalcon(int id) {
    std::shared_ptr<TalonFX> falcon = std::make_shared<TalonFX>(new TalonFX(id));

    falcon->ConfigFactoryDefault();
    falcon->ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);

    falcon->SetNeutralMode((Config::brake) ? NeutralMode::Brake : NeutralMode::Coast);
    falcon->ConfigVoltageCompSaturation(Config::voltageCompensation);
    falcon->EnableVoltageCompensation(true);

    falcon->SelectProfileSlot(0, 0);

    falcon->Config_kI(0, PIDF::kI);
    falcon->Config_kP(0, PIDF::kP);
    falcon->Config_kD(0, PIDF::kD);
    falcon->Config_kF(0, PIDF::kF);

    falcon->SetInverted(Config::reversed);

    return falcon;
}

std::shared_ptr<TalonSRX> Factory::makeTalon(int id) {
    std::shared_ptr<BaseTalon> talon = std::make_shared<TalonSRX>(new TalonSRX(id));
    
    talon->ConfigFactoryDefault();
    talon->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative);
    talon->SetNeutralMode((Config::brake) ? NeutralMode::Brake : NeutralMode::Coast);
    talon->ConfigVoltageCompSaturation(Config::voltageCompensation);
    talon->EnableVoltageCompensation(true);

    talon->SelectProfileSlot(0, 0);

    talon->Config_kI(0, PIDF::kI);
    talon->Config_kP(0, PIDF::kP);
    talon->Config_kD(0, PIDF::kD);
    talon->Config_kF(0, PIDF::kF);

    talon->SetInverted(Config::reversed);
}

std::shared_ptr<BaseTalon> Factory::makeMotors() {
    std::shared_ptr<BaseTalon> motor;
    BaseTalon* motorFollower; // (Never let this object die if we are following)
    if (Config::usingFalcon) {
        motor = makeFalcon(CAN_Constants::CAN_ID_MAIN);
        if (Config::following) {
            motorFollower = makeFalcon(CAN_Constants::CAN_ID_FOLLOW).get();
        }
    }
    else {
        motor = makeTalon(CAN_Constants::CAN_ID_MAIN);
        if (Config::following) {
            motorFollower = makeTalon(CAN_Constants::CAN_ID_FOLLOW).get();
        }
    }

    if (Config::following) {
        motorFollower->SetInverted(Config::reversed ^ Config::facingSameWay);
        motorFollower->Follow(*motor.get());
    }
    else {
        delete motorFollower;
    }

    return motor;
}
