#define _CRT_SECURE_NO_WARNINGS 1

#include"WorkerManager.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
WorkManager::WorkManager(){
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
}
WorkManager::~WorkManager(){

}
void WorkManager::showMenu(){
	cout << "**************************************" << endl;
	cout << "******** ��ӭʹ��ְ������ϵͳ ********" << endl;
	cout << "********** 1.��ʾְ����Ϣ ***********" << endl;
	cout << "********** 2.���ְ����Ϣ ***********" << endl;
	cout << "********** 3.ɾ��ְ����Ϣ ***********" << endl;
	cout << "********** 4.�޸�ְ����Ϣ ***********" << endl;
	cout << "********** 5.����ְ����Ϣ ***********" << endl;
	cout << "********** 6.���ձ������ ***********" << endl;
	cout << "********** 7.��������ĵ� ***********" << endl;
	cout << "********** 0.�˳�����ϵͳ ***********" << endl;
	cout << "**************************************" << endl;
	cout << endl;
}

void WorkManager::addEmp(){
	cout << "���������ӵ�Ա��������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0){
		int newSize = this->m_EmpNum + addNum;

		Worker** newSpace = new Worker*[newSize];

		//��ԭ�ռ��µ����ݷŵ��¿ռ���
		if (this->m_EmpArray != NULL){
			for (int i = 0; i < this->m_EmpNum; i++){
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//������ӹ���
		for (int i = 0; i < addNum; i++){
			int id;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "����ְ�����: " << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ������: " << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ����λ: " << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;

			Worker* p = NULL;
			switch (dSelect)
			{
			case 1:
				p = new Employee(id, name, 1);
			case 2:
				p = new Manager(id, name, 2);
			case 3:
				p = new Boss(id, name, 2);
			default:
				cout << "����������������룡" << endl;
				break;
			}

			//����
			newSpace[this->m_EmpNum + i] = p;
		}

		//�ͷ�ԭ�ռ�
		delete[] this->m_EmpArray;

		//����Ϊ�¿ռ�
		this->m_EmpArray = newSpace;

		cout << "�ɹ����" << addNum << "����ְ��!" << endl;
	}
	else{
		cout << "�������" << endl;
	}

}