#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

//boss��
class Boss :public Worker{
public:
	Boss(int id, string name, int dId);

	//��д������麯��
	void showInfo();
	string getDpart();
	string job();
};