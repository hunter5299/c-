#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
int main01(){
	
		char str0[] = "�����׺���Ϊˮ���ȴ��ɽ������";	//15������
		char str1[] = "##############################";//30��#��
		int left = 0;/*���±�*/
		int right = strlen(str0) - 1;/*���±�*/
		while (left <= right)
		{
			str1[left] = str0[left];//�ײ���һ���ַ�λ����
			str1[left + 1] = str0[left + 1];//�ײ��ڶ����ַ�λ����  ��ʱ���һ������������#�ŵĽ���

			str1[right] = str0[right];
			str1[right - 1] = str0[right -1];
			left=left+2;
			right=right-2;
			printf("%s\n", str1);

			//Sleep(1000);
			system("cls");
		}


		system("pause");
		return 0;
	
}



int main02(){
	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int *p = arr;

	printf("%d\n", *(p++));

	printf("%d\n", *p);
	system("pause");
	return 0;
}

void* my_memcpy(void * dest, const void *src, size_t count){
	void* temp = dest;
	while (count--){
		*(char*)dest = *(char*)src;
		++(char*)dest;
		++(char*)src;
	}
	return temp;
}

int main03(){
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[10] = { 0 };
	my_memcpy(arr2, arr1, sizeof(arr1));
	printf("%d\n", arr2[0]);

	system("pause");
	return 0;
}