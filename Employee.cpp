#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<string>
#include"Employee.h"
using namespace std;


//员工类中的函数实现

Employee::Employee(int id, string name, int dId){
	this->m_id = id;
	this->m_name = name;
	this->m_dId = dId;
}

void Employee::showInfo(){
	 cout << "编号 " << this->m_id
		 << "\t姓名： " << this->m_name
		 << "\t职位：" << this->getDpart()
		 << "\t职责： " << this->job()
		 << endl;
}
string Employee::getDpart(){
	return "员工";
 }

string Employee::job(){
	return "完成经理下发的任务";
}
