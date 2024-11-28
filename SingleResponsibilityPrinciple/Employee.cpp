#include "Employee.h"

Employee::Employee(const std::string name, const double& salary) :
	m_Name(name), m_salary(salary) {}

double Employee::getSalary() const {
	return m_salary;
}

std::string Employee::getName() const {
	return m_Name;
}