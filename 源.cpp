#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//��������ͨ���̬�����������̬������
//��ͨ
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
//��̬
class CalculateBase{
public:
	int m_num1;
	int m_num2;
	int virtual getCount(){	//���ø����麯������ʱ����ṹΪ����int ���ݺ�һ��vfptrָ��
		return 0;
	}
};
//�ӷ���̬
class AddCalcu :public CalculateBase{	//�̳�
	int getCount(){				//��д�����麯����ʹvfptrָ����麯��ָ���ָ��ĸ����麯���������麯������
		return m_num1 + m_num2;
	}
};
//����
class SubCalcu : public CalculateBase{
	int getCount(){		//��д
		return m_num1 - m_num2;
	}
};
class MultCalcu : public CalculateBase{
	int getCount(){		//��д
		return m_num1 * m_num2;
	}
};

int test1(){
	CalculateBase *p;	//����ָ��
	p = new AddCalcu;		//��������ʵ��
	p->m_num1 = 100;
	p->m_num2 = 20;
	cout << "num1" << "+" << "num2" << "=" << p->getCount() << endl;
	delete p;


	p = new SubCalcu;		//��������ʵ��
	p->m_num1 = 100;
	p->m_num2 = 20;
	cout << "num1" << "-" << "num2" << "=" << p->getCount() << endl;
	delete p;


	p = new MultCalcu;		//��������ʵ��
	p->m_num1 = 100;
	p->m_num2 = 20;
	cout << "num1" << "*" << "num2" << "=" << p->getCount() << endl;
	delete p;
	return 0;
}

//ð������
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