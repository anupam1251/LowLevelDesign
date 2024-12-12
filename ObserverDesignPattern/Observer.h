#pragma once
#ifndef OBSERVER_H
#define OBSERVER_H
#include <string>
#include <iostream>

class Observer {
public:
	Observer(const std::string name);
	void notify() const;
private:
	std::string m_Name;
};

#endif

