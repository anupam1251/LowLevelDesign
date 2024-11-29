#pragma once
#include "Shape.h"
#include<memory>
#include<vector>
class DrawingManager
{
	std::vector<std::unique_ptr<Shape>>m_vecShapes;
public:
	void addShapes(std::unique_ptr<Shape> shape);
	void drawAllShapes() const;
};

