#include "Watcher.h"
Watcher::Watcher(const std::string name) : m_Name(name) {

}

void Watcher::notify() const {
	std::cout << "Hello : " << m_Name << "\n";
}