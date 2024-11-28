#include "Employee.h"
#include "SalaryCalculator.h"
#include "ReportGenerator.h"

int main() {
	Employee obj("Anupam",45000);
	SalaryCalculator cal;

	double bonus = cal.calculateBonus(obj);

	ReportGenerator report;
	report.generateReport(obj, bonus);
	return 0;
}