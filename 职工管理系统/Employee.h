#pragma once
#include <iostream>
#include <string>
#include "Worker.h"
class Employee : public Worker{
public:
	Employee(int id, std::string name, int dept)
		:Worker(id, name, dept) {
		std::cout << "Employee has Created" << std::endl;
	}
	void showInfo() override;
	std::string getDeptName() override;
};

