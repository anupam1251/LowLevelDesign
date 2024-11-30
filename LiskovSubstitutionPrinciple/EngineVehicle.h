#pragma once
#include "Vehicle.h"
class EngineVehicle : public Vehicle
{	
public:
	bool hasEngine() const override;
};

