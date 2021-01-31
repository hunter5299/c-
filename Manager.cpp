#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<string>
#include"Manager.h"
using namespace std;


//manager类中的函数实现

Manager::Manager(int id, string name, int dId){
	this->m_id = id;
	this->m_name = name;
	this->m_dId = dId;
}

void Manager::showInfo(){
	cout << "编号 " << this->m_id
		<< "\t姓名： " << this->m_name
		<< "\t职位：" << this->getDpart()
		<< "\t职责： " << this->job()
		<< endl;
}
string Manager::getDpart(){
	return "经理";
}

string Manager::job(){
	return "完成老板下发的任务";
}
