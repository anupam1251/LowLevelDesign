#include <iostream>
using namespace std;

class BasePizza {
public:
	virtual int cost() = 0;
	virtual ~BasePizza() = default;
};
class FarmHouse : public BasePizza {
public:
	int cost() override {
		return 100;
	}
};
class VegDelight : public BasePizza {
public:
	int cost() override {
		return 150;
	}
};
class Margherita : public BasePizza {
public:
	int cost() override {
		return 200;
	}
};

class ToppingDecorator : public BasePizza {
public:
	virtual int cost() = 0;
	virtual ~ToppingDecorator() = default;
};

class ExtraCheese : public ToppingDecorator {
	unique_ptr<BasePizza> obj;
public:
	ExtraCheese(unique_ptr<BasePizza> ptr) : obj(move(ptr)){}
	int cost() override{
		return obj->cost() + 15;
	}
	virtual ~ExtraCheese() = default;
};

class Mushroom : public ToppingDecorator {
	unique_ptr<BasePizza> obj;
public:
	Mushroom(unique_ptr<BasePizza> ptr) : obj(move(ptr)){}
	int cost() override{
		return obj->cost() + 25;
	}
	virtual ~Mushroom() = default;
};

int main() {

	unique_ptr<BasePizza> ptr = make_unique<ExtraCheese>(
									make_unique<Mushroom>(
										make_unique<VegDelight>()));

	cout<< ptr->cost();

}
