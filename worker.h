#pragma once
#include<iostream>
#include<string>
using namespace std;

//���ࣺ������
class Worker{
public:
	int m_id;
	string m_name;
	int m_dId;
	virtual void showInfo()=0;
	virtual string getDpart()=0;
	virtual string job()=0;
};