#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
int main01(){
	
		char str0[] = "曾经沧海难为水大除却巫山不是云";	//15个汉字
		char str1[] = "##############################";//30个#号
		int left = 0;/*左下标*/
		int right = strlen(str0) - 1;/*右下标*/
		while (left <= right)
		{
			str1[left] = str0[left];//首部第一个字符位交换
			str1[left + 1] = str0[left + 1];//首部第二个字符位交换  此时完成一个汉字与两个#号的交换

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