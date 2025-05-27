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

class ShapeFactory {
public:
	unique_ptr<Shape> getShape(const string &str) {

		if(str == "CIRCLE")
			return make_unique<Circle>();
		else if(str == "RECTANGLE")
			return make_unique<Rectangle>();
		else if (str == "SQUARE")
			return make_unique<Square>();
		else
			return nullptr;
		}
};

int main() {
	unique_ptr<ShapeFactory> objshapeFact = make_unique<ShapeFactory>();

	unique_ptr<Shape> shape = objshapeFact->getShape("CIRCLE");
	shape->draw();
}