#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;




//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
int isLeftReverse(char *arr, char *arr2){
	char temp;
	char* tempH = arr;
	char tempArr[1024];
	strcpy(tempArr, arr);
	while (*tempH != '\0'){
		temp = *tempArr;
		for (int j = 0; j < strlen(tempArr) - 1; j++){
			tempArr[j] = tempArr[j + 1];
		}
		tempArr[strlen(tempArr) - 1] = temp;
		tempH++;
		if (strcmp(tempArr, arr2) == 0){
			return 1;
		}
	}
	return 0;
}
int isRightReverse(char *arr, char *arr2){
	char temp;
	char* tempH = arr;
	char tempArr[1024];
	strcpy(tempArr, arr);
	while (*tempH != '\0'){
		temp = *(tempArr+strlen(tempArr)-1);
		for (int j = strlen(tempArr) - 1; j>=0; j--){
			tempArr[j] = tempArr[j - 1];
		}
		tempArr[strlen(tempArr) - 1] = temp;
		tempH++;
		if (strcmp(tempArr, arr2) == 0){
			return 1;
		}
	}
	return 0;
}
int isReverse(char *arr, char *arr2){
	if (isLeftReverse(arr,arr2)||isRightReverse(arr,arr2)){
		return 1;
	}
	return 0;
}

int main03(){
	char arr[] = "abcd";
	char arr2[] = "bcda";
	int ret = isReverse(arr, arr2);
	cout << ret << endl;
	system("pause");
	return 0;
}

//�ַ�������
int LeftReverse(char *arr,int k){
	char temp;
	for (int i = 0; i < k;i++){
		temp = *arr;
		for (int j = 0; j < strlen(arr) - 1; j++){
			arr[j] = arr[j + 1];
		}
		arr[strlen(arr) - 1] = temp;
	}
	return 0;
}
int main(){
	char arr[] = "abcd";
	LeftReverse(arr, 2);
	cout << arr << endl;
	system("pause");
	return 0;
}
//��ҵ����
//�ַ�����ת���
//
//��ҵ����
//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//
//
//
//���磺����s1 = AABCD��s2 = BCDAA������1
//
//����s1 = abcd��s2 = ACBD������0.
//
//
//
//AABCD����һ���ַ��õ�ABCDA
//
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAABC


//���ڶ�̬�Ĺ���ϵͳ��ϰ:����


class Worker{
public:
	string name;
	int age;
	int position;

	void virtual showMesa() = 0;
};

class Employee :public Worker{
public:
	string dowork(){
		return "employee";
	}
	void showMesa(){
		cout << this->name << "  " <<
			this->age << "  " <<
			this->dowork() << endl;
	}
};
class Manager :public Worker{
public:
	string dowork(){
		return "Manager";
	}
	void showMesa(){
		cout << this->name << "  " <<
			this->age << "  " <<
			this->dowork() << endl;
	}
};
class Boss :public Worker{
public:
	string dowork(){
		return "boss";
	}
	void showMesa(){
		cout << this->name << "  " <<
			this->age << "  " <<
			this->dowork() << endl;
	}
};

class WorkManager{
public:
	int lenth;
	Worker *p;
};
int main02(){

	return 0;
}