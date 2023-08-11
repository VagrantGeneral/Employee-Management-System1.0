#include "WorkerManager.h"
#include <algorithm>

//展示菜单
void WorkerManager::show_Menu() {
	std::cout << "*************************职工管理系统*************************" << std::endl;
	std::cout << "*                        0.退出系统                          *" << std::endl;
	std::cout << "*                        1.增加职工                          *" << std::endl;
	std::cout << "*                        2.显示职工                          *" << std::endl;
	std::cout << "*                        3.删除职工                          *" << std::endl;
	std::cout << "*                        4.修改职工                          *" << std::endl;
	std::cout << "*                        5.查找职工                          *" << std::endl;
	std::cout << "*                        6.排序员工                          *" << std::endl;
	std::cout << "*                        7.清空文件                          *" << std::endl;
	std::cout << "****************************选项*****************************" << std::endl;
}

//退出
void WorkerManager::exit_System() {
	for (auto iter = this->m_vector.begin(); iter != this->m_vector.end(); iter++) {
		delete (*iter);
	}
	system("pause");
	exit(0);
}

//添加
void WorkerManager::add_Emp() {
	int flag = 1;
	while (flag) {
		std::cout << "请输入编号" << std::endl;
		int id;
		std::cin >> id;
		std::cout << "请输入姓名" << std::endl;
		std::string name;
		std::cin >> name;
		std::cout << "选择部门:1.员工 2.经理 3.老板" << std::endl;
		int dept;
		std::cin >> dept;
		Worker* worker = NULL;
		if (dept == 1) {
			worker = new Employee(id, name, dept);
		}
		else if (dept == 2) {
			worker = new Manager(id, name, dept);
		}
		else if (dept == 3) { 
			worker = new Boss(id, name, dept);
		}
		else {
			std::cout << "有误" << std::endl;
		}
		(this->m_vector).push_back(worker);
		this->save();
		std::cout << "保存完毕" << std::endl;
		std::cout << "是否继续添加（y/n）?" << std::endl;
		std::string a;
		std::cin >> a;
		if (a == "n" || a == "N") {
			flag = 0;
		}
	}
	
	system("pause");
	system("cls");
}

//保存
void WorkerManager::save() {
	std::ofstream ofs;
	ofs.open("vector_Emp.txt", std::ios::out);
	if (ofs.is_open() == 0) {
		return;
	}
	for (auto iter = (this->m_vector).begin(); iter != (this->m_vector).end(); iter++) {
		ofs << (*iter)->m_Id <<"***"<< (*iter)->m_Name <<"***"<< (*iter)->m_DeptId << std::endl;
	}
	ofs.close();
}

//展示员工
void WorkerManager::Show_Emp() {
	for (auto iter = this->m_vector.begin(); iter != this->m_vector.end(); iter++) {
		(*iter)->showInfo();
	}
	system("pause");
	system("cls");
}

//删除
void WorkerManager::Del_Emp() {
	std::cout << "请输入目标编号" << std::endl;
	int id;
	std::cin >> id;
	for (auto iter = this->m_vector.begin(); iter != this->m_vector.end(); iter++) {
		if ((*iter)->m_Id == id) {
			std::cout << "找到目标值" << std::endl;
			this->m_vector.erase(iter);

			break;
		}
	}
	std::cout << "删除完毕" << std::endl;
	this->save();
	system("pause");
	system("cls");
}

//修改
void WorkerManager::Mod_Emp() {
	std::cout << "请输入目标编号" << std::endl;
	int id;
	std::cin >> id;
	for (auto iter = this->m_vector.begin(); iter != this->m_vector.end(); iter++) {
		if ((*iter)->m_Id == id) {
			std::cout << "找到目标值" << std::endl;
			std::cout << "请输入姓名" << std::endl;
			std::string name;
			std::cin >> name;
			std::cout << "选择部门:1.员工 2.经理 3.老板" << std::endl;
			int dept;
			std::cin >> dept;
			(*iter)->m_Id = id;
			(*iter)->m_Name = name;
			(*iter)->m_DeptId = dept;
		}
	}
	std::cout << "修改完毕" << std::endl;
	this->save();
	system("pause");
	system("cls");
}

//查找
void WorkerManager::Find_Emp() {
	std::cout << "选择方式:1.编号查找 2.姓名查找" << std::endl;
	int choice = 0;
	std::cin >> choice;
	if (choice == 1) {
		std::cout << "输入目标编号" << std::endl;
		int id;
		std::cin >> id;
		for (auto iter = this->m_vector.begin(); iter != this->m_vector.end(); iter++) {
			if ((*iter)->m_Id == id) {
				(*iter)->showInfo();
				break;
			}
		}
	}
	else if (choice == 2) {
		std::cout << "输入目标姓名" << std::endl;
		std::string name;
		std::cin >> name;
		for (auto iter = this->m_vector.begin(); iter != this->m_vector.end(); iter++) {
			if ((*iter)->m_Name == name) {
				(*iter)->showInfo();
				break;
			}
		}
	}
	else {
		std::cout << "输入错误" << std::endl;
	}
	std::cout << "完毕" << std::endl;
	system("pause");
	system("cls");
}

//排序
void WorkerManager::Sort_Emp() {
	for (auto iterx = this->m_vector.begin(); iterx != this->m_vector.end(); iterx++) {
		for (auto itery = iterx + 1; itery != this->m_vector.end(); itery++) {
			if ((*iterx)->m_Id < (*itery)->m_Id) {
				int a = (*iterx)->m_Id;
				(*iterx)->m_Id = (*itery)->m_Id;
				(*itery)->m_Id = a;
			}
		}
	}
	std::cout << "排序完毕" << std::endl;
	system("pause");
	system("cls");
}

//清空文件
void WorkerManager::Clean() {
	std::cout << "确认请空(y/n)" << std::endl;
	std::string a;
	std::cin >> a;
	if (a == "y" || a == "Y") {
		std::ofstream ofs("vector_Emp.txt", std::ios::trunc);
		ofs.close();
	}
	else {
		return;
	}
	std::cout << "清空完毕" << std::endl;
	system("pause");
	system("cls");
}