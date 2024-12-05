#pragma once
#ifndef IGAMEINTERFACE_H
#define IGAMEINTERFACE_H
#include <iostream>

class IGameInterFace {
public:
	virtual ~IGameInterFace() = default;
	virtual void update() = 0;
	virtual void render() = 0;
};

#endif