#include "SalaryCalculator.h"
double SalaryCalculator::calculateBonus(const Employee& emp) const {
	return emp.getSalary() * 0.1;
}