#pragma once

#include<iostream>
#include"worker.h"
using namespace std;
//Ա���Ĺ����ࣺ�Բ����ĳ���
class WorkManager{
public:
	//��¼�ļ��е�����
	int m_EmpNum;

	//Ա�������ָ��
	Worker** m_EmpArray;

	//���캯��
	WorkManager();
	
	//�˵�
	void showMenu();
	//���
	void addEmp();
	//��������
	~WorkManager();
};