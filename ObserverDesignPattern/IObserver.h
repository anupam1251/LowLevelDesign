#pragma once
#ifndef IOBSERVER_H
#define IOBSERVER_H
class IObserver {
public:
	virtual void notify() const = 0;
	virtual ~IObserver() = default;
};

#endif