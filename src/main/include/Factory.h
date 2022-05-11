
#pragma once

#include "Constants.h"
#include "ctre/Phoenix.h"

class Factory {
    public:
        static std::shared_ptr<TalonFX> makeFalcon(int id);
        static std::shared_ptr<TalonSRX> makeTalon(int id);
            
        static std::shared_ptr<BaseTalon> makeMotors();
};

