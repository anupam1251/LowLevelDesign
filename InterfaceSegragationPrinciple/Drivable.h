#pragma once
#include <iostream>
class Drivable {
public:
	virtual void drive() const = 0;
	virtual ~Drivable() = default;
};