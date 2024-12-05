#pragma once
#ifndef BOAT_H
#define BOAT_H

#include "IGameInterface.h"
class Boat : public IGameInterFace{
public:
	Boat();
	void update() override;
	void render() override;
	~Boat();
};

#endif

