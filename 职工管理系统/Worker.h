#pragma once
#include <iostream>
#include <string>
class Worker {
public:
	int m_Id;
	std::string m_Name;
	int m_DeptId;
public:
	Worker(int id, std::string name, int dept)
		:m_Id(id), m_Name(name), m_DeptId(dept){}
	virtual ~Worker(){}
	virtual void showInfo() = 0;
	virtual std::string getDeptName() = 0;
};

