#include "Vehicle.h"
#include "MotorCycle.h"
#include "Car.h"
#include "Bicycle.h"
#include <iostream>
#include <memory>
#include <vector>
int main() {
	
	std::vector<std::unique_ptr<Vehicle>> vec;

	vec.emplace_back(std::make_unique<MotorCycle>());
	vec.emplace_back(std::make_unique<Car>());
	vec.emplace_back(std::make_unique<Bicycle>());

	for (auto& obj : vec) {
		if (obj->hasEngine()) {
			std::cout << "Its Engine Vehicle and No. of Vehicles : " << obj->getNumberofVehicle() << std::endl;
		}
		else {
			std::cout << "Not a Engine Vehicle and No. of Vehicles : "<<obj->getNumberofVehicle() << std::endl;
		}
	}
	return 0;
}