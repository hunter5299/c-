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
		cout << "������ѡ��" << endl;
		cin >> input;
		switch (input){
		case 1:
			wm.showWorker();
			break;
		case 2:
			wm.addEmp();
			break; 
		case 3:
			wm.delEmp();
			break;
		case 4:
			wm.modiEmp();
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 0:
			cout << "���˳�����ϵͳ" << endl;
			break;
		default:
			system("cls");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}