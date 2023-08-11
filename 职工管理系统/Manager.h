#pragma once
#include <iostream>
#include <string>
#include "Worker.h"
class Manager : public Worker {
public:
	Manager(int id, std::string name, int dept)
		:Worker(id, name, dept) {

	}
	void showInfo() override;
	std::string getDeptName() override;
};

