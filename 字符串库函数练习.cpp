#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;




//判断一个字符串是否为另外一个字符串旋转之后的字符串。
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

//字符串左旋
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
//作业标题
//字符串旋转结果
//
//作业内容
//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//
//
//
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//
//给定s1 = abcd和s2 = ACBD，返回0.
//
//
//
//AABCD左旋一个字符得到ABCDA
//
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC


//基于多态的管理系统练习:链表


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