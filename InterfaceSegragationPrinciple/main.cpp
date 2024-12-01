#include "Car.h"
#include "Boat.h"
#include "Aeroplane.h"
#include<memory>
#include<vector>

int main() {
	
	std::vector<std::unique_ptr<Drivable>> drivables;
	std::vector<std::unique_ptr<Flyable>> flyables;
	std::vector<std::unique_ptr<Sailable>> sailables;

	drivables.emplace_back(std::make_unique<Car>());
	drivables.emplace_back(std::make_unique<Car>());

	flyables.emplace_back(std::make_unique<Aeroplane>());
	flyables.emplace_back(std::make_unique<Aeroplane>());

	sailables.emplace_back(std::make_unique<Boat>());
	sailables.emplace_back(std::make_unique<Boat>());

	std::cout << "Drivable Vehicles" << std::endl;
	for (auto& x : drivables) {
		x->drive();
	}

	std::cout << "Flyable Vehicles" << std::endl;
	for (auto& x : flyables) {
		x->fly();
	}

	std::cout << "Sailable Vehicles" << std::endl;
	for (auto& x : sailables) {
		x->sail();
	}

	return 0;
}