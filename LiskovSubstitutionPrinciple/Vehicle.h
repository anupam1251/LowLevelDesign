#pragma once
class Vehicle {
public:
	virtual size_t getNumberofVehicle() const ;
	virtual bool hasEngine() const ;
	virtual ~Vehicle() = default;
};