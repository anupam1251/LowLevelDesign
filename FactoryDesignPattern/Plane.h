#pragma once
#ifndef PLANE_H
#define PLANE_H

#include "IGameInterface.h"

class Plane : public IGameInterFace {
public:
	Plane();
	void update() override;
	void render() override;
	~Plane();
};

#endif

