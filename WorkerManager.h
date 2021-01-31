#pragma once

#include<iostream>
#include"worker.h"
using namespace std;
//员工的管理类：对操作的抽象
class WorkManager{
public:
	//记录文件中的人数
	int m_EmpNum;

	//员工数组的指针
	Worker** m_EmpArray;

	//构造函数
	WorkManager();
	
	//菜单
	void showMenu();
	//添加
	void addEmp();
	//析构函数
	~WorkManager();
};