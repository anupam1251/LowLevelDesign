#pragma once
#include<iostream>
class Sailable {
public:
	virtual void sail() const = 0;
	virtual ~Sailable() = default;
};
