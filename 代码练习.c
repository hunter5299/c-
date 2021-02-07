#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//1.����ָ������ʵ�ֶ�������ĵ��ã�������

int menu(){
	printf("************\n");
	printf("*** 1.add **\n");
	printf("*** 2.sub **\n");
	printf("*** 3.mult *\n");
	return 0;
}
int add(int x, int y){
	return x + y;
}
int sub(int x, int y){
	return x - y;
}
int mult(int x, int y){
	return x*y;
}
int main01(){
	int input = 0;
	int x, y;
	int ret = 0;
	int(*pfArr[3])(int x, int y) = { add, sub, mult };
	do{
		menu();
		scanf("%d", &input);
		printf("input two number:");
		scanf("%d %d", &x, &y);
		//ÿ�����һ�����ܶ���ʹ����case�߳�����������չά��
		/*switch (input){
		case 1: add(x, y);
		break;
		case 2: sub(x, y);
		break;
		case 3:mult(x, y);
		break
		case 0:
		printf("exit!\n");
		break;
		default:
		break;
		}*/
		if (input > 0 && input < sizeof(pfArr) / sizeof(pfArr[0])){
			ret = pfArr[input - 1](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0){
			printf("exit\n");
		}
		else{
			printf("input erro\n");
		}
	} while (input);

	return 0;
}
//2.�ص�������qsort��ð��iģ��ʵ��
int menu1(){
	printf("**********************\n");
	printf("****** 1.����KDA *****\n");
	printf("****** 0. �˳�  ******\n");
	printf("**********************\n");
	return 0;
}
//KDA = (��ɱ + ���� / 2)(���� + 1)

int main02(){
	float k, d, a;
	int input;
	float kda = 0;
	do
	{
		menu1();
		printf("������:\n");
		scanf("%d", &input);
		switch (input){
		case 1:
			printf("������K D A,�ո����\n");
			scanf("%f %f %f", &k, &d, &a);
			getchar();
			kda = (k + (a / 2))/(d + 1);
			printf("KDA: %.2f\n", kda);
			printf("\n");
			break;
		case 0:
			printf("�˳�������\n");
			break;
		}
	} while (input);
}

//�ص�ģ��ʵ��qsort��ð������
int cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}
void mySwap(char* p1, char* p2, int width){
	int i = 0;
	for (i = 0; i < width; i++){
		char t = *p1;
		*p1 = *p2;
		*p2 = t;
		p1++;
		p2++;
	}
}
void _swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
void bubble_sort(void* base, size_t sz, size_t width, int(*cmp)(const void*e1, const void*e2))
{
	size_t i = 0;
	//����
	for (i = 0; i < sz - 1; i++)
	{
		size_t j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//����2��Ԫ�صıȽ�
			//base[j] base[j+1] 
			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)
			{
				//���������˳��ͽ���
				_swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}
int callback(char *e1,char *e2){
	return *e1 - *e2;
}
//void��ָ����Խ����������͵�ָ��
int myQsort( void *base, const int len, const char width, int(*callback)(const void *e1, const void *e2)){
	for (int i = 0; i < len; i++){
		for (int j = 0; j < len - i; j++){
		//	if (callback(e1,e2)>0){
			//base[j]��base[j+1]�Ƚ�
			if (callback((char*)base + j*width, (char*)base + (j+1)*width>0)){
				//�������򽻻�
				mySwap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
	return 0;
}
void test3()
{
	//qsort ������������
	int arr[] = { 1, 5, 2, 4, 3, 9, 8, 6, 7, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//void��ָ����Խ����������͵�ָ��
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	print_arr(arr, sz);
}
