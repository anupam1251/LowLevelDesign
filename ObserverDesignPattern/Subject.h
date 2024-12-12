#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H
#include <forward_list>
#include "Observer.h"
class Subject {
public:
	Subject();
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	void notifyAll();

private:
	std::forward_list<Observer*> m_ListObserver;
};

#endif

