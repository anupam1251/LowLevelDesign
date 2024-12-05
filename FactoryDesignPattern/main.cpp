#include "IGameInterface.h"
#include "Boat.h"
#include "Plane.h"
#include <memory>
#include <string>
#include "GameFactoryObject.h"



int main() {
	
	std::unique_ptr<IGameInterFace> obj1 = GameFactoryObject::createGameObject(ObjectType::BOAT);
	std::unique_ptr<IGameInterFace> obj2 = GameFactoryObject::createGameObject(ObjectType::PLANE);
	return 0;
}