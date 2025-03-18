#include <iostream>
#include <string>
#include <thread>
#include <mutex>

class Singleton {
	std::string m_str;
	static Singleton* m_ptr;
	static std::mutex m_mtx;

	Singleton(std::string str) : m_str(str){}

public:

	static Singleton* getInstance(std::string str) {
		std::lock_guard<std::mutex> lock(m_mtx);
		if (m_ptr == nullptr) {
			m_ptr = new Singleton(str);
		}
		return m_ptr;
	}

	std::string getStr() { return m_str; }
};

Singleton* Singleton::m_ptr = nullptr;
std::mutex Singleton::m_mtx;

void threadFoo() {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	Singleton* obj = Singleton::getInstance("Foo");
	std::cout << obj->getStr() << '\n';

}

void threadBar() {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	Singleton* obj = Singleton::getInstance("Bar");
	std::cout << obj->getStr() << '\n';
}
int main() {

	std::thread t1(threadFoo);
	std::thread t2(threadBar);

	t1.join();
	t2.join();

}