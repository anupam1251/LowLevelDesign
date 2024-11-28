#include "ReportGenerator.h"

void ReportGenerator::generateReport(const Employee& emp, const double& bonus) const {
	std::cout << "Employee Name : " << emp.getName()
		<< "\nSalary : " << emp.getSalary()
		<< "\nBonus : " << bonus;
}
