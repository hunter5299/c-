#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

//Ա����
class Manager :public Worker{
public:
	Manager(int id, string name, int dId);

	//��д������麯��
	void showInfo();
	string getDpart();
	string job();
};