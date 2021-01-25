#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//计算器普通与多态的区别，体验多态的优势
//普通
class Calculate{
public:
	int getCount(string operat){
		if (operat == "+"){
			return m_Num1 + m_num2;
		}
		else if (operat == "-"){
			return m_Num1 - m_num2;
		}
		else if (operat == "*"){
			return m_Num1 * m_num2;
		}
	}
private:
	int m_Num1;
	int m_num2;
};
//多态
class CalculateBase{
public:
	int m_num1;
	int m_num2;
	int virtual getCount(){	//设置父类虚函数，此时父类结构为两个int 数据和一个vfptr指针
		return 0;
	}
};
//加法多态
class AddCalcu :public CalculateBase{	//继承
	int getCount(){				//重写父类虚函数，使vfptr指向的虚函数指针表指向的父类虚函数被子类虚函数覆盖
		return m_num1 + m_num2;
	}
};
//减法
class SubCalcu : public CalculateBase{
	int getCount(){		//重写
		return m_num1 - m_num2;
	}
};
class MultCalcu : public CalculateBase{
	int getCount(){		//重写
		return m_num1 * m_num2;
	}
};

int test1(){
	CalculateBase *p;	//父类指针
	p = new AddCalcu;		//创建子类实例
	p->m_num1 = 100;
	p->m_num2 = 20;
	cout << "num1" << "+" << "num2" << "=" << p->getCount() << endl;
	delete p;


	p = new SubCalcu;		//创建子类实例
	p->m_num1 = 100;
	p->m_num2 = 20;
	cout << "num1" << "-" << "num2" << "=" << p->getCount() << endl;
	delete p;


	p = new MultCalcu;		//创建子类实例
	p->m_num1 = 100;
	p->m_num2 = 20;
	cout << "num1" << "*" << "num2" << "=" << p->getCount() << endl;
	delete p;
	return 0;
}

//冒泡排序
int BubleSort(int *arr,int lenth){
	if (arr == NULL){
		return -1;
	}
	int i, j,temp;
	for (i = 0; i < lenth; i++){
		for (j = 1; j < lenth - i; j++){
			if (arr[j-1]>arr[j]){
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return 0;
}

int initArr(int *arr,int lenth){
	for (int i = 0; i < lenth; i++){
		arr[i] = 0;
	}
	return 0;
}
int printArr(int *arr,int lenth){
	for (int i = 0; i < lenth; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
int reverse(int *arr ,int lenth){
	int left = 0;
	int right = lenth - 1;
	while (left<right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
	return 0;
}
int exchange(int *arr1,int len1,int *arr2,int len2){
	int temp = 0;
	for (int i = 0; i < len1 || i< len2; i++){
		if (i < len2 && i< len2){
			temp = arr1[i];
			arr1[i] = arr2[i];
			arr2[i] = temp;
		}
		else if (len1 <= i && len1 < len2){
			arr1[i]=arr2[i];
		}
		else if (len2 <= i && len2 < len1){
			arr2[i] = arr1[i];
		}
	}
	return 0;
}
int main(){
	int arr[5] = { 5, 4, 2, 6, 8 };
	BubleSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < 5; i++){
		cout << arr[i]<< endl;
	}
	system("pause");
	return 0;
}