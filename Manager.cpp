#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<string>
#include"Manager.h"
using namespace std;


//manager���еĺ���ʵ��

Manager::Manager(int id, string name, int dId){
	this->m_id = id;
	this->m_name = name;
	this->m_dId = dId;
}

void Manager::showInfo(){
	cout << "��� " << this->m_id
		<< "\t������ " << this->m_name
		<< "\tְλ��" << this->getDpart()
		<< "\tְ�� " << this->job()
		<< endl;
}
string Manager::getDpart(){
	return "����";
}

string Manager::job(){
	return "����ϰ��·�������";
}
