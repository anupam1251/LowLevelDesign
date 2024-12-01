#pragma once
#include<iostream>
class Flyable {
public:
	virtual void fly() const = 0;
	virtual ~Flyable() = default;
};