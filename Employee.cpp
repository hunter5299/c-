#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<string>
#include"Employee.h"
using namespace std;


//Ա�����еĺ���ʵ��

Employee::Employee(int id, string name, int dId){
	this->m_id = id;
	this->m_name = name;
	this->m_dId = dId;
}

void Employee::showInfo(){
	 cout << "��� " << this->m_id
		 << "\t������ " << this->m_name
		 << "\tְλ��" << this->getDpart()
		 << "\tְ�� " << this->job()
		 << endl;
}
string Employee::getDpart(){
	return "Ա��";
 }

string Employee::job(){
	return "��ɾ����·�������";
}
