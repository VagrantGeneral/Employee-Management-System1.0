#include "WorkerManager.h"
#include <algorithm>

//չʾ�˵�
void WorkerManager::show_Menu() {
	std::cout << "*************************ְ������ϵͳ*************************" << std::endl;
	std::cout << "*                        0.�˳�ϵͳ                          *" << std::endl;
	std::cout << "*                        1.����ְ��                          *" << std::endl;
	std::cout << "*                        2.��ʾְ��                          *" << std::endl;
	std::cout << "*                        3.ɾ��ְ��                          *" << std::endl;
	std::cout << "*                        4.�޸�ְ��                          *" << std::endl;
	std::cout << "*                        5.����ְ��                          *" << std::endl;
	std::cout << "*                        6.����Ա��                          *" << std::endl;
	std::cout << "*                        7.����ļ�                          *" << std::endl;
	std::cout << "****************************ѡ��*****************************" << std::endl;
}

//�˳�
void WorkerManager::exit_System() {
	for (auto iter = this->m_vector.begin(); iter != this->m_vector.end(); iter++) {
		delete (*iter);
	}
	system("pause");
	exit(0);
}

//���
void WorkerManager::add_Emp() {
	int flag = 1;
	while (flag) {
		std::cout << "��������" << std::endl;
		int id;
		std::cin >> id;
		std::cout << "����������" << std::endl;
		std::string name;
		std::cin >> name;
		std::cout << "ѡ����:1.Ա�� 2.���� 3.�ϰ�" << std::endl;
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
			std::cout << "����" << std::endl;
		}
		(this->m_vector).push_back(worker);
		this->save();
		std::cout << "�������" << std::endl;
		std::cout << "�Ƿ������ӣ�y/n��?" << std::endl;
		std::string a;
		std::cin >> a;
		if (a == "n" || a == "N") {
			flag = 0;
		}
	}
	
	system("pause");
	system("cls");
}

//����
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

//չʾԱ��
void WorkerManager::Show_Emp() {
	for (auto iter = this->m_vector.begin(); iter != this->m_vector.end(); iter++) {
		(*iter)->showInfo();
	}
	system("pause");
	system("cls");
}

//ɾ��
void WorkerManager::Del_Emp() {
	std::cout << "������Ŀ����" << std::endl;
	int id;
	std::cin >> id;
	for (auto iter = this->m_vector.begin(); iter != this->m_vector.end(); iter++) {
		if ((*iter)->m_Id == id) {
			std::cout << "�ҵ�Ŀ��ֵ" << std::endl;
			this->m_vector.erase(iter);

			break;
		}
	}
	std::cout << "ɾ�����" << std::endl;
	this->save();
	system("pause");
	system("cls");
}

//�޸�
void WorkerManager::Mod_Emp() {
	std::cout << "������Ŀ����" << std::endl;
	int id;
	std::cin >> id;
	for (auto iter = this->m_vector.begin(); iter != this->m_vector.end(); iter++) {
		if ((*iter)->m_Id == id) {
			std::cout << "�ҵ�Ŀ��ֵ" << std::endl;
			std::cout << "����������" << std::endl;
			std::string name;
			std::cin >> name;
			std::cout << "ѡ����:1.Ա�� 2.���� 3.�ϰ�" << std::endl;
			int dept;
			std::cin >> dept;
			(*iter)->m_Id = id;
			(*iter)->m_Name = name;
			(*iter)->m_DeptId = dept;
		}
	}
	std::cout << "�޸����" << std::endl;
	this->save();
	system("pause");
	system("cls");
}

//����
void WorkerManager::Find_Emp() {
	std::cout << "ѡ��ʽ:1.��Ų��� 2.��������" << std::endl;
	int choice = 0;
	std::cin >> choice;
	if (choice == 1) {
		std::cout << "����Ŀ����" << std::endl;
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
		std::cout << "����Ŀ������" << std::endl;
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
		std::cout << "�������" << std::endl;
	}
	std::cout << "���" << std::endl;
	system("pause");
	system("cls");
}

//����
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
	std::cout << "�������" << std::endl;
	system("pause");
	system("cls");
}

//����ļ�
void WorkerManager::Clean() {
	std::cout << "ȷ�����(y/n)" << std::endl;
	std::string a;
	std::cin >> a;
	if (a == "y" || a == "Y") {
		std::ofstream ofs("vector_Emp.txt", std::ios::trunc);
		ofs.close();
	}
	else {
		return;
	}
	std::cout << "������" << std::endl;
	system("pause");
	system("cls");
}