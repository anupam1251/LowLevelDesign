#include "Observer.h"
Observer::Observer(const std::string name) : m_Name(name) {

}

void Observer::notify() const {
	std::cout << "Hello : " << m_Name << "\n";
}