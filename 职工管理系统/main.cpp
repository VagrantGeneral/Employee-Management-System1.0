#include <iostream>
#include "WorkerManager.h"

int main() {
	//创建管理员对象，调用成员函数
	WorkerManager* wm = new WorkerManager();
	int choice = 0;
	//主循环
	while (true) {
		//显示功能菜单，并选择功能
		wm->show_Menu();
		std::cout << "请选择（0~7）" << std::endl;
		std::cin >> choice;
		//选择
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