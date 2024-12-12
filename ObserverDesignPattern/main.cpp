#include "IObserver.h"
#include "ISubject.h"

int main() {
	Watcher watcher1("Anupam");
	Watcher watcher2("David");
	Watcher watcher3("Ortan");

	std::unique_ptr<ISubject> subject = std::make_unique<ISubject>();
	subject->addObserver(&watcher1);
	subject->addObserver(&watcher2);
	subject->addObserver(&watcher3);

	subject->notifyAll();
	
	std::cout << "\n\n";
	subject->removeObserver(&watcher2);
	subject->notifyAll();

	return 0;
}