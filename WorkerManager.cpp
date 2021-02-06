#define _CRT_SECURE_NO_WARNINGS 1

#include"WorkerManager.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
#include<fstream>
#define FILENAME "empFile.txt"
WorkManager::WorkManager(){

	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//�ļ�������ʱ
	if (!ifs.is_open()){
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_isEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڵ�Ϊ��
	char ch;
	//���ļ�β������
	ifs >> ch;
	if (ifs.eof()){
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_isEmpty = true;
		ifs.close();
		return;
	}

	//�ļ�������������
	this->getfile();
	this->m_isEmpty = false;
}
WorkManager::~WorkManager(){
	if (this->m_EmpArray != NULL){
		//�ͷ������worker�����ڴ�
		for (int i = 0; i < sizeof(this->m_EmpArray) / sizeof(this->m_EmpArray[0]); i++){
			if (this->m_EmpArray[i] != NULL){
				delete this->m_EmpArray[i];
			}
		}
		//�ͷ�����������ڴ�
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
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
			cin >> name;
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
				break;
			case 2:
				p = new Manager(id, name, 2);
				break;
			case 3:
				p = new Boss(id, name, 3);
				break;
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

		//����ϵͳ������
		this->m_EmpNum = newSize;
		cout << "�ɹ����" << addNum << "����ְ��!" << endl;

		this->m_isEmpty = false;

		//д���ļ�
		this->writefile();
	}
	else{
		cout << "�������" << endl;
	}
	////�������������
	//system("pause");
	system("cls");
}

int WorkManager::isExist(int id){

	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++){
		if (this->m_EmpArray[i]->m_id == id){
			index = i;
			break;
		}
	}
	return index;
}

void WorkManager::delEmp(){

	if (this->m_isEmpty){
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else{
		int delNum,id;
		Worker*tmp = NULL;
		cout << "��������Ҫɾ����Ա����ţ�" << endl;
		cin >> delNum;
		id = this->isExist(delNum);
		if (id != -1){
			tmp = this->m_EmpArray[id];
			for (int i = id; i < this->m_EmpNum; i++){
				this->m_EmpArray[i] = this->m_EmpArray[i+1];
			}
			this->m_EmpNum--;

			//���������һ��Ԫ�ص�ָ���ΪNULL��������ǰһ��ָ��ʹ�ָ��ָ��ͬһ���ռ䣻
			this->m_EmpArray[this->m_EmpNum] = NULL;
			delete tmp;
			tmp = NULL;
			//��������ʹһ������������ռ䣬�������Կռ�ĳһ�������ͷ�
			//�ᵼ���ͷ�����ʱ�����ͷ������ռ䵼�³���
			//��ʱ���߼���Ϊ�������Ԫ�ط��������ʹ�û����ܷ��ʣ��ڴ�й¶����
			//������ʱͳһ�ͷ�
			cout << "ɾ���ɹ���" << endl;
			this->writefile();
		}
		else{
			cout << "ɾ��ʧ�ܣ�δ�ҵ��ñ��Ա����" << endl;
		}
	}
	
}

void WorkManager::modiEmp(){

	if (this->m_isEmpty){
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;

	}
	else{
		cout << "��������Ҫ�޸ĵ�Ա����ţ�" << endl;
		int id;
		int index;
		cin >> id;
		index=this->isExist(id);
		if (index != -1){
			delete this->m_EmpArray[index];
			int newid;
			string newname;
			int dSelect;

			cout << "�鵽��" << id << "��Ա�����������±�ţ� " << endl;
			cin >> newid;
			cout << "������������: " << endl;
			cin >> newname;
			cout << "�������λ: " << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			Worker* p = NULL;
			switch (dSelect)
			{
			case 1:
				p = new Employee(newid, newname, 1);
				break;
			case 2:
				p = new Manager(newid, newname, 2);
				break;
			case 3:
				p = new Boss(newid, newname, 3);
				break;
			default:
				cout << "����������������룡" << endl;
				break;
			}

			this->m_EmpArray[index] = p;
			p = NULL;
			cout << "�޸ĳɹ���" << endl;

			//д���ļ���
			this->writefile();

		}
		else{
			cout << "���޴���" << endl;
		}
	}

}

void WorkManager::showWorker(){

	if (this->m_isEmpty){
	
		cout << "�ļ�Ϊ��" << endl;
	
	}
	//����
	else{
		for (int i = 0; i < this->m_EmpNum; i++){
			this->m_EmpArray[i]->showInfo();
		}
	}
	
}

void WorkManager::getfile(){
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int dId;
	int num = 0;
	int i = 0;
	//ͳ������
	while (ifs >> id&&ifs >> name&&ifs >> dId){
		num++;
	}
	ifs.close();

	//�����ݶ���
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker* [this->m_EmpNum];
	ifs.open(FILENAME, ios::in);
	while (ifs >> id && ifs >> name && ifs >> dId){
		Worker* p = NULL;
		if (1 == dId){
			p = new Employee(id, name, dId);
		}
		else if (2 == dId){
			p = new Manager(id, name, dId);
		}
		else{
			p = new Boss(id, name, dId);
		}
		this->m_EmpArray[i] = p;
		i++;
	}
	ifs.close();
}

void WorkManager::writefile(){
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	
	for (int i = 0; i < this->m_EmpNum; i++){
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_dId << endl;
	}

	ofs.close();
}