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

	//�ļ��Ƿ�Ϊ��
	bool m_isEmpty;

	//���캯��
	WorkManager();
	
	//�˵�
	void showMenu();

	//��ʾ������Ϣ
	void showWorker();
	//���
	void addEmp();

	//���ڸñ�ŵ�Ա��
	int isExist(int id);

	//ɾ��
	void delEmp();

	//
	void modiEmp();

	//���ļ�
	void getfile();

	//д�ļ�
	void writefile();
	//��������
	~WorkManager();
};