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

	//文件是否为空
	bool m_isEmpty;

	//构造函数
	WorkManager();
	
	//菜单
	void showMenu();

	//显示所有信息
	void showWorker();
	//添加
	void addEmp();

	//存在该编号的员工
	int isExist(int id);

	//删除
	void delEmp();

	//
	void modiEmp();

	//读文件
	void getfile();

	//写文件
	void writefile();
	//析构函数
	~WorkManager();
};