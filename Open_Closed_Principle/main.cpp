#include "DrawingManager.h"
#include "Circle.h"
#include "Rectangle.h"
int main() {

	DrawingManager manager;

	manager.addShapes(std::make_unique<Circle>());
	manager.addShapes(std::make_unique<Rectangle>());

	manager.drawAllShapes();
	
	return 0;
}

// Open for Extension: New shapes can be added by creating new classes(e.g., Triangle) that inherit from Shape.
// Closed for Modification : The DrawingManager and existing shape classes don’t need changes.
