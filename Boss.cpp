#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<string>
#include"Boss.h"
using namespace std;
//BOSS���еĺ���ʵ��

Boss::Boss(int id, string name, int dId){
	this->m_id = id;
	this->m_name = name;
	this->m_dId = dId;
}

void Boss::showInfo(){
	cout << "��� " << this->m_id
		<< "\t������ " << this->m_name
		<< "\tְλ��" << this->getDpart()
		<< "\tְ�� " << this->job()
		<< endl;
}
string Boss::getDpart(){
	return "�ϰ�";
}

string Boss::job(){
	return "����ȫ��˾����";
}
