#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<string>
#include"Boss.h"
using namespace std;
//BOSS类中的函数实现

Boss::Boss(int id, string name, int dId){
	this->m_id = id;
	this->m_name = name;
	this->m_dId = dId;
}

void Boss::showInfo(){
	cout << "编号 " << this->m_id
		<< "\t姓名： " << this->m_name
		<< "\t职位：" << this->getDpart()
		<< "\t职责： " << this->job()
		<< endl;
}
string Boss::getDpart(){
	return "老板";
}

string Boss::job(){
	return "管理全公司事务";
}
