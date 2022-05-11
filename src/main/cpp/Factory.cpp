#include "Factory.h"

std::shared_ptr<TalonFX> Factory::makeFalcon(int id) {
    std::shared_ptr<TalonFX> falcon = std::make_shared<TalonFX>(new TalonFX(id));

    falcon->ConfigFactoryDefault();
    falcon->ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);
    falcon->SetNeutralMode((Config::brake) ? NeutralMode::Brake : NeutralMode::Coast);
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

}

std::shared_ptr<BaseTalon> Factory::makeMotors() {
    std::shared_ptr<BaseTalon> motor;
    BaseTalon* motorFollower; // (Never let this object die)
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

    return motor;
}
