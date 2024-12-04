#pragma once
#ifndef SINGLETON_H
#define SINGLETON_H
#include <iostream>

class Singleton
{
private:
	Singleton();
	static Singleton* instance;
public:
	static Singleton* GetInstance();
};

#endif

