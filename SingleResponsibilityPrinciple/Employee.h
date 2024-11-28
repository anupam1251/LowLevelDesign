#pragma once
#include<string>
#include<iostream>
class Employee {

	std::string m_Name;
	double m_salary;

public:
	Employee(const std::string name, const double& salary);
	double getSalary() const;
	std::string getName() const;
	~Employee(){}

};