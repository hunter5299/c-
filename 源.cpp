#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include"WorkerManager.h"
#include"worker.h"
#include"Employee.h"
#include"Boss.h"
#include"Manager.h"
int main(){
	WorkManager wm;
	int input = 0;
	do{
		wm.showMenu();
		cout << "请输入选择" << endl;
		cin >> input;
		switch (input){
		case 1:
			Worker *p;
			p = new Employee(1, "zs", 1);
			p->showInfo();
			break;
		case 2:
			break; 
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 0:
			cout << "已退出管理系统" << endl;
			break;
		default:
			system("cls");
		}
	} while (input);
	system("pause");
	return 0;
}