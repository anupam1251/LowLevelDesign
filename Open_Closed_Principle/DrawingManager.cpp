#include "DrawingManager.h"

void DrawingManager::addShapes(std::unique_ptr<Shape> shape) {
	m_vecShapes.emplace_back(std::move(shape));
}

void DrawingManager::drawAllShapes() const {
	for (const auto &x : m_vecShapes) {
		x->draw();
	}
}