#pragma once
#ifndef GAMEFACTORYOBJECT_H
#define GAMEFACTORYOBJECT_H
#include "Boat.h"
#include "Plane.h"

enum ObjectType{PLANE, BOAT};

class GameFactoryObject {
public:

	static std::unique_ptr<IGameInterFace> createGameObject(ObjectType type);

private:

	GameFactoryObject();
	~GameFactoryObject();
};

#endif

