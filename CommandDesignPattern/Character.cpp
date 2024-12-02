#include "Character.h"

Character::Character(std::string name): m_name(name){}

void Character::move(const int& x, const int& y) {
	m_x = x;
	m_y = y;
}