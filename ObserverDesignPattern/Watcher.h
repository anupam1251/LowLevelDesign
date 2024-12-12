#pragma once
#ifndef WATCHER_H
#define WATCHER_H
#include <string>
#include <iostream>
#include "IObserver.h"

class Watcher : public IObserver{
public:
	explicit Watcher(const std::string name);
	void notify() const;
private:
	std::string m_Name;
};

#endif

