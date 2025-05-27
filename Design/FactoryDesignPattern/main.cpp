#include <iostream>
using namespace std;

class Shape {
public:
	virtual void draw() = 0;
};

class Circle : public Shape {
public:
	void draw() override {
		cout << "Drawing Circle" << '\n';
	}
};
class Rectangle : public Shape {
public:
	void draw() override {
		cout << "Drawing Rectangle" << '\n';
	}
};
class Square : public Shape {
public:
	void draw() override {
		cout << "Drawing Square" << '\n';
	}
};

enum class ShapeType {
	CIRCLE,
	RECTANGLE,
	SQUARE
};

class ShapeFactory {
public:
	static unique_ptr<Shape> getShape(ShapeType type) {
		switch (type) {

			case ShapeType::CIRCLE:
				return make_unique<Circle>();
			case ShapeType::RECTANGLE:
				return make_unique<Rectangle>();
			case ShapeType::SQUARE:
				return make_unique<Square>();
			default:
				return nullptr;
		}
	}
};

int main() {
	
	unique_ptr<Shape> shape = ShapeFactory::getShape(ShapeType::CIRCLE);
	shape->draw();

	shape = ShapeFactory::getShape(ShapeType::RECTANGLE);
	shape->draw();
}