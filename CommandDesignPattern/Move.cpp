#include "Move.h"

void Move::execute(Character& c) {
	int randomX = rand() % 100;
	int randomY = rand() % 100;
	c.move(randomX, randomY);
	m_X = randomX;
	m_Y = randomY;
	std::cout <<c.m_name<< " Moved "<<"x : "<<m_X<<  " , y :"<<m_Y << std::endl;
}

void Move::undo(Character& c) const {
	c.move(-m_X, -m_Y);
	std::cout << c.m_name << " Undo " << "x : " << m_X << " , y :" << m_Y << std::endl;
}