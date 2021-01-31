#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

//boss类
class Boss :public Worker{
public:
	Boss(int id, string name, int dId);

	//重写基类的虚函数
	void showInfo();
	string getDpart();
	string job();
};