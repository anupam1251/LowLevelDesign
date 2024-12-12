#include "ISubject.h"

ISubject::ISubject() : m_ListObserver() {

}
void ISubject::addObserver(IObserver* observer) {
	m_ListObserver.emplace_front(observer);
}
void ISubject::removeObserver(IObserver* observer) {
	m_ListObserver.remove(observer);
}
void ISubject::notifyAll() {
	for (const auto& e : m_ListObserver) {
		e->notify();
	}
}