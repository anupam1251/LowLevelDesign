// SOLID PRINCIPLES

#include <iostream>
#include <vector>
//1. Single Responsibilty Principle -> A class should have only one reasong to change, 
		//it should have only 1 responsibility 

//Bad : Mixing Report generation and data storage

class Employee1 {
public:

	void generateReport() {
		std::cout << "Report for " << name << '\n';
	}

	void saveToDB() {
		std::cout << "Saving Record in DB for " << name << '\n';
	}
	
private:

	std::string name;
	std::string position;
	double salary;
};


// Good : Separating responsibities
class Employee {
public:
	std::string getName() const { return name; }
	std::string getPosition() const { return position; }
	double getSalary() const  { return salary; }

private:
	std::string name;
	std::string position;
	double salary;
};

class ReportGenerator {

public:
	void generateReport(const Employee& e) {
		std::cout << "Report for " << e.getName() << '\n';
	}
};


//2. Open/Closed Principle (OCP)
// Software entities/ classes should be open for extension but closed for modification


// Bad Example
/*
enum class ShapeType{Circle , Square};

class Shape {
	ShapeType type;
	double dimension1;
	double dimension2;

public:
	Shape(ShapeType t, double d1 = 0, double d2 = 0) : type(t), dimension1(d1),
		dimension2(d2) {}

	double area() {
		switch (type) {

			case ShapeType::Circle:
				return 3.14 * dimension1 * dimension1;

			case ShapeType::Square:
				return dimension1 * dimension1;
		}
		return 0;

	}
};

class AreaCalculator {
public:
	double calculateTotalArea(std::vector<Shape> &shapes) {
		double total = 0;
		for (auto& shape : shapes) {
			total += shape.area();
		}
		return total;
	}

};
*/



// Good Example


//Abstract base class - closed for modification
class Shape {
public:
	virtual double area() const = 0;
	virtual ~Shape() = default;
};


//concrete implementation - open for extension

class Circle : public Shape {
	double radius;
public:
	Circle(double r): radius(r){}
	double area() const override { 
		return 3.14 * radius * radius; 
	}
};

class Square : public Shape {
	double side;
public:
	Square(double s): side(s){}
	double area() const override {
		return side * side;
	}
};

// New shape can be added without modifying existing code

class Rectangle : public Shape {
	double height, width;
public:
	Rectangle(double h , double w): height(h), width(w){}

	double area() const override{
		return height * width;
	}

};

class AreaCalculator {
public:
	double calculateTotalArea(std::vector<std::shared_ptr<Shape>> &shapes) {
		double total = 0;
		for (const auto& shape : shapes) {
			total += shape->area();
		}
		return total;
	}
};


//4. Interface segregation principle (ISP)
// Clients should not be forced to depend on the interface they don't use

// Bad : single large interface

class IWorker {
public :
	
	virtual void work() = 0;
	virtual void eat() = 0;
	virtual void sleep() = 0;
};

// Human implements all methods

class Human : public IWorker {
public:
	void work() override {  }
	void eat()  override { }
	void sleep()  override { }

};

// Robot forced to implement eat() and sleep() which it don't need

class Robot : public IWorker {
public:
	void work() override {  }
	void eat()  override {/*.. throws exception or do nothing */ }
	void sleep()  override {/*.. throws exception or do nothing */ }
};


// Good : Split into smaller interface

class IWorkable {
public:
	virtual void work() = 0;
};

class IEatable {
public:
	virtual void eat() = 0;
};

class ISleepable {
public:
	virtual void sleep() = 0;
};

class Human : public IWorkable, public IEatable, public ISleepable {
	// implement all relevant methods
};

class Robot : public IWorkable {
public:
	// only implement work()
};





int main() {

	/*
	std::vector<Shape> shapes;
	shapes.emplace_back(ShapeType::Circle, 5);
	shapes.emplace_back(ShapeType::Square, 5);
	
	AreaCalculator calc;
	std::cout << calc.calculateTotalArea(shapes)<<'\n';  
	*/

	/*
	std::vector<std::shared_ptr<Shape>> vec_shapes;
	std::shared_ptr<Shape> shptr1 = std::make_shared<Circle>(5);
	std::shared_ptr<Shape> shptr2 = std::make_shared<Square>(5);
	std::shared_ptr<Shape> shptr3 = std::make_shared<Rectangle>(5,6);

	vec_shapes.emplace_back(shptr1);
	vec_shapes.emplace_back(shptr2);
	vec_shapes.emplace_back(shptr3);

	AreaCalculator calc;
	std::cout << calc.calculateTotalArea(vec_shapes);
	*/


}