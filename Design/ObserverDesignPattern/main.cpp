#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class IObserver {
public:
	virtual void display() = 0;
	virtual ~IObserver() = default;
};

class TVDisplay : public IObserver {
public:
	void display(){
		cout << "Temparature displaying in TV" << '\n';
	}
};

class MobileDisplay : public IObserver {
public:
	void display(){
		cout << "Temparature displaying in Mobile" << '\n';
	}
};

class IObservable {
public:
	virtual void add(unique_ptr<IObserver> obj) = 0;
	virtual void remove(IObserver* obj) = 0;
	virtual void notify() = 0;
	virtual ~IObservable() = default;
};

class WeatherObservable : public IObservable {
	vector<unique_ptr<IObserver>> vec_Observer;
public:
	void add(unique_ptr<IObserver> obj) override{
		vec_Observer.push_back(move(obj));
	}

	void remove(IObserver* obj) override{
		vec_Observer.erase(remove_if(vec_Observer.begin(), vec_Observer.end(), 
			[&](unique_ptr<IObserver>& rem) { return rem.get() == obj; }), vec_Observer.end());
	}

	void notify() {
		for (auto& observer : vec_Observer) {
			observer->display();
		}
	}
};


int main() {

	unique_ptr<IObserver> o1 = make_unique<TVDisplay>();
	unique_ptr<IObserver> o2 = make_unique<MobileDisplay>();

	unique_ptr<IObservable> ptr = make_unique<WeatherObservable>();
	ptr->add(move(o1));
	ptr->add(move(o2));

	ptr->notify();


}
