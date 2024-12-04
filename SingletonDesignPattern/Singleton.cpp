#include "Singleton.h"

Singleton* Singleton::instance = nullptr;

Singleton::Singleton() {
	std::cout << "Singleton Created" << std::endl;
}

Singleton* Singleton::GetInstance() {
	if (instance == nullptr) {
		instance = new Singleton;
	}
	return instance;
}