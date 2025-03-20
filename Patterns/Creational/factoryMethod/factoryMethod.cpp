#include <iostream>

class vehicle {
public:
	vehicle(){}
	virtual void display() = 0;
	virtual ~vehicle(){}
	static vehicle* factoryMethod(std::string);
};


class TwoWheeler : public vehicle {
public:
	void display() {
		std::cout << "I am TwoWheeler" << std::endl;
	}
};

class FourWheeler : public vehicle {
public:
	void display() {
		std::cout << "I am FourWheeler" << std::endl;
	}
};

vehicle* vehicle::factoryMethod(std::string str) {
	if (str == "TwoWheeler")
		return new TwoWheeler();
	else if (str == "FourWheeler")
		return new FourWheeler();
	else
		return nullptr;
}


int main() {

	vehicle* v1 = vehicle::factoryMethod("TwoWheeler");
	v1->display();

	v1 = vehicle::factoryMethod("FourWheeler");
	v1->display();

	delete v1;

	return 0;

}