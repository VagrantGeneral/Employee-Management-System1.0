#include <iostream>
#include "WorkerManager.h"

int main() {
	//��������Ա���󣬵��ó�Ա����
	WorkerManager* wm = new WorkerManager();
	int choice = 0;
	//��ѭ��
	while (true) {
		//��ʾ���ܲ˵�����ѡ����
		wm->show_Menu();
		std::cout << "��ѡ��0~7��" << std::endl;
		std::cin >> choice;
		//ѡ��
		switch (choice) {
		case 0:
			wm->exit_System();
			break;
		case 1:
			wm->add_Emp();
			break;
		case 2:
			wm->Show_Emp();
			break;
		case 3:
			wm->Del_Emp();
			break;
		case 4:
			wm->Mod_Emp();
			break;
		case 5:
			wm->Find_Emp();
			break;
		case 6:
			wm->Sort_Emp();
			break;
		case 7:
			wm->Clean();
			break;
		}
	}
	delete wm;
}