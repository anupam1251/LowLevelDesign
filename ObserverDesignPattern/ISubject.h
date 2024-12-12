#pragma once
#ifndef ISUBJECT_H
#define ISUBJECT_H
#include <forward_list>
#include "Watcher.h"
class ISubject {
public:
	ISubject();
	virtual void addObserver(IObserver* observer);
	virtual void removeObserver(IObserver* observer);
	virtual void notifyAll();

private:
	std::forward_list<IObserver*> m_ListObserver;
};

#endif

