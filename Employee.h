#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

//员工类
class Employee :public Worker{
public:
	Employee(int id, string name, int dId);

	//重写基类的虚函数
	void showInfo();
	string getDpart();
	string job();
};