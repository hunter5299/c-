#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

//Ա����
class Employee :public Worker{
public:
	Employee(int id, string name, int dId);

	//��д������麯��
	void showInfo();
	string getDpart();
	string job();
};