#pragma once
#include <iostream>
#include <fstream>
#include <vector>

#include "Employee.h"
#include "Manager.h"
#include "Worker.h"
#include "Boss.h"

class WorkerManager{
public:
	std::vector<Worker*> m_vector;
public:
	WorkerManager() {
		std::cout << "WorkerManager has Created" << std::endl;
	}
	~WorkerManager() {
		std::cout << "WorkerManager has deleted" << std::endl;
	}

	void show_Menu();

	void exit_System();
	void add_Emp();
	void save();
	void Show_Emp();
	void Del_Emp();
	void Mod_Emp();
	void Find_Emp();
	void Sort_Emp();
	void Clean();
};

