#pragma once
class Vehicle {
public:
	virtual size_t getNumberofVehicle() const = 0;
	virtual bool hasEngine() const = 0;
	virtual ~Vehicle() = default;
};