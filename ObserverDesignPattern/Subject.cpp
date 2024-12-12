#include "Subject.h"

Subject::Subject() : m_ListObserver() {

}
void Subject::addObserver(Observer* observer) {
	m_ListObserver.emplace_front(observer);
}
void Subject::removeObserver(Observer* observer) {
	m_ListObserver.remove(observer);
}
void Subject::notifyAll() {
	for (const auto& e : m_ListObserver) {
		e->notify();
	}
}