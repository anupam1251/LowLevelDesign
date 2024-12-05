#include "GameFactoryObject.h"


std::unique_ptr<IGameInterFace> GameFactoryObject::createGameObject(ObjectType type){

	if (ObjectType::BOAT == type)
		return std::make_unique<Boat>();
	else if (ObjectType::PLANE == type)
		return std::make_unique<Plane>();
	return nullptr;

}