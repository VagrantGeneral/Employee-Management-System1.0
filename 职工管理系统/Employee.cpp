#include "Employee.h"
void Employee::showInfo() {
	std::cout << "±àºÅ" << this->m_Id << "ÐÕÃû" << this->m_Name << "²¿ÃÅ" << this->getDeptName() << std::endl;
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