#include "Observer.h"
#include "Subject.h"

int main() {
	Observer observer1("Anupam");
	Observer observer2("David");
	Observer observer3("Ortan");

	std::unique_ptr<Subject> subject = std::make_unique<Subject>();
	subject->addObserver(&observer1);
	subject->addObserver(&observer2);
	subject->addObserver(&observer3);

	subject->notifyAll();
	
	std::cout << "\n\n";
	subject->removeObserver(&observer2);
	subject->notifyAll();

	return 0;
}