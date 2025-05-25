#include <iostream>
using namespace std;

class IDriveStrategy {
public:
	virtual void drive() = 0;
	virtual ~IDriveStrategy() = default;
};

class NormalDrive : public IDriveStrategy {
public:
	void drive() override{
		cout << "Normal Drive capability" << '\n';
	}
};

class SpecialDrive : public IDriveStrategy {
public:
	void drive() override {
		cout << "Sport Drive capability" << '\n';
	}
};

class Vehicle {
	IDriveStrategy* driveStrategy;
public:
	Vehicle(IDriveStrategy* dsPtr) : driveStrategy(dsPtr) {

	}
	void drive() {
		driveStrategy->drive();
	}

	virtual ~Vehicle() = default;
};

class SportVehicle : public Vehicle {	
public:
	SportVehicle(IDriveStrategy* ptr) : Vehicle(ptr) {

	}
};

class PassengerVehicle : public Vehicle {
public:
	PassengerVehicle(IDriveStrategy* ptr) : Vehicle(ptr) {

	}
};

class OffRoadVehicle : public Vehicle {
public:
	OffRoadVehicle(IDriveStrategy* ptr) : Vehicle(ptr) {

	}
};

int main() {

	IDriveStrategy* sd1 = new SpecialDrive;
	Vehicle* v1 = new SportVehicle(sd1);
	v1->drive();

	IDriveStrategy* sd2 = new NormalDrive;
	Vehicle* v2 = new PassengerVehicle(sd2);
	v2->drive();

	delete v1;
	delete v2;

	delete sd1;
	delete sd2;

	return 0;

}