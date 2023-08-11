#include "Employee.h"
void Employee::showInfo() {
	std::cout << "���" << this->m_Id << "����" << this->m_Name << "����" << this->getDeptName() << std::endl;
}
std::string Employee::getDeptName() {
	if (this->m_DeptId == 1) {
		return "Employee";
	}
	else if (this->m_DeptId == 2) {
		return "Manager";
	}
	else {
		return "Boss";
	}
}