#define _CRT_SECURE_NO_WARNINGS 1

#include"WorkerManager.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
WorkManager::WorkManager(){
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
}
WorkManager::~WorkManager(){

}
void WorkManager::showMenu(){
	cout << "**************************************" << endl;
	cout << "******** 欢迎使用职工管理系统 ********" << endl;
	cout << "********** 1.显示职工信息 ***********" << endl;
	cout << "********** 2.添加职工信息 ***********" << endl;
	cout << "********** 3.删除职工信息 ***********" << endl;
	cout << "********** 4.修改职工信息 ***********" << endl;
	cout << "********** 5.查找职工信息 ***********" << endl;
	cout << "********** 6.按照编号排序 ***********" << endl;
	cout << "********** 7.清空所有文档 ***********" << endl;
	cout << "********** 0.退出管理系统 ***********" << endl;
	cout << "**************************************" << endl;
	cout << endl;
}

void WorkManager::addEmp(){
	cout << "请输入增加的员工数量：" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0){
		int newSize = this->m_EmpNum + addNum;

		Worker** newSpace = new Worker*[newSize];

		//将原空间下的内容放到新空间下
		if (this->m_EmpArray != NULL){
			for (int i = 0; i < this->m_EmpNum; i++){
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//完成增加功能
		for (int i = 0; i < addNum; i++){
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个新职工编号: " << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名: " << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工岗位: " << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* p = NULL;
			switch (dSelect)
			{
			case 1:
				p = new Employee(id, name, 1);
			case 2:
				p = new Manager(id, name, 2);
			case 3:
				p = new Boss(id, name, 2);
			default:
				cout << "输入错误，清重新输入！" << endl;
				break;
			}

			//插入
			newSpace[this->m_EmpNum + i] = p;
		}

		//释放原空间
		delete[] this->m_EmpArray;

		//更改为新空间
		this->m_EmpArray = newSpace;

		cout << "成功添加" << addNum << "名新职工!" << endl;
	}
	else{
		cout << "输入错误" << endl;
	}

}