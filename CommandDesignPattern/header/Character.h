#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H
#include<string>

class Character {
	int m_x, m_y;
public:
	std::string m_name;
public:
	Character(std::string name);
	void move(const int &x, const int &y);

};

#endif