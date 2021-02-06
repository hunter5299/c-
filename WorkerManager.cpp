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
	//文件不存在时
	if (!ifs.is_open()){
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_isEmpty = true;
		ifs.close();
		return;
	}
	//文件存在但为空
	char ch;
	//将文件尾部读走
	ifs >> ch;
	if (ifs.eof()){
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_isEmpty = true;
		ifs.close();
		return;
	}

	//文件存在且有数据
	this->getfile();
	this->m_isEmpty = false;
}
WorkManager::~WorkManager(){
	if (this->m_EmpArray != NULL){
		//释放申请的worker子类内存
		for (int i = 0; i < sizeof(this->m_EmpArray) / sizeof(this->m_EmpArray[0]); i++){
			if (this->m_EmpArray[i] != NULL){
				delete this->m_EmpArray[i];
			}
		}
		//释放整个数组的内存
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
void WorkManager::showMenu(){
	cout << "**************************************" << endl;
	cout << "******** 欢迎使用职工管理系统 ********" << endl;
	cout << "********** 1.显示职工信息 ***********" << endl;
	cout << "********** 2.添加职工信息 ***********" << endl;
	cout << "********** 3.删除职工信息 ***********" << endl;
	cout << "********** 4.修改职工信息 ***********" << endl;
	cout << "********** 5.查找职工信息 ***********" << endl;
	cout << "********** 6.按照编号排序 ***********" << endl;
	cout << "********** 7.清空所有文档 ***********" << endl;
	cout << "********** 0.退出管理系统 ***********" << endl;
	cout << "**************************************" << endl;
	cout << endl;
}

void WorkManager::addEmp(){
	cout << "请输入增加的员工数量：" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0){
		int newSize = this->m_EmpNum + addNum;

		Worker** newSpace = new Worker*[newSize];

		//将原空间下的内容放到新空间下
		if (this->m_EmpArray != NULL){
			for (int i = 0; i < this->m_EmpNum; i++){
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//完成增加功能
		for (int i = 0; i < addNum; i++){
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个新职工编号: " << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名: " << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个新职工岗位: " << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
				cout << "输入错误，清重新输入！" << endl;
				break;
			}

			//插入
			newSpace[this->m_EmpNum + i] = p;
		}

		//释放原空间
		delete[] this->m_EmpArray;

		//更改为新空间
		this->m_EmpArray = newSpace;

		//更新系统内人数
		this->m_EmpNum = newSize;
		cout << "成功添加" << addNum << "名新职工!" << endl;

		this->m_isEmpty = false;

		//写入文件
		this->writefile();
	}
	else{
		cout << "输入错误" << endl;
	}
	////按任意键后清屏
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
		cout << "文件不存在或记录为空" << endl;
	}
	else{
		int delNum,id;
		Worker*tmp = NULL;
		cout << "请输入需要删除的员工编号：" << endl;
		cin >> delNum;
		id = this->isExist(delNum);
		if (id != -1){
			tmp = this->m_EmpArray[id];
			for (int i = id; i < this->m_EmpNum; i++){
				this->m_EmpArray[i] = this->m_EmpArray[i+1];
			}
			this->m_EmpNum--;

			//将数组最后一个元素的指向改为NULL，避免了前一个指针和此指针指向同一处空间；
			this->m_EmpArray[this->m_EmpNum] = NULL;
			delete tmp;
			tmp = NULL;
			//由于数组使一块申请的连续空间，若单独对空间某一处进行释放
			//会导致释放数组时不能释放连续空间导致出错，
			//此时的逻辑仅为将数组此元素放置在最后，使用户不能访问（内存泄露？）
			//在析构时统一释放
			cout << "删除成功！" << endl;
			this->writefile();
		}
		else{
			cout << "删除失败，未找到该编号员工！" << endl;
		}
	}
	
}

void WorkManager::modiEmp(){

	if (this->m_isEmpty){
		cout << "文件不存在或记录为空！" << endl;

	}
	else{
		cout << "请输入需要修改的员工编号：" << endl;
		int id;
		int index;
		cin >> id;
		index=this->isExist(id);
		if (index != -1){
			delete this->m_EmpArray[index];
			int newid;
			string newname;
			int dSelect;

			cout << "查到：" << id << "号员工，请输入新编号： " << endl;
			cin >> newid;
			cout << "请输入新姓名: " << endl;
			cin >> newname;
			cout << "请输入岗位: " << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
				cout << "输入错误，清重新输入！" << endl;
				break;
			}

			this->m_EmpArray[index] = p;
			p = NULL;
			cout << "修改成功！" << endl;

			//写入文件；
			this->writefile();

		}
		else{
			cout << "查无此人" << endl;
		}
	}

}

void WorkManager::showWorker(){

	if (this->m_isEmpty){
	
		cout << "文件为空" << endl;
	
	}
	//遍历
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
	//统计人数
	while (ifs >> id&&ifs >> name&&ifs >> dId){
		num++;
	}
	ifs.close();

	//将数据读入
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