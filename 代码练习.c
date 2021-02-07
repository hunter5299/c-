#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//1.函数指针数组实现多个函数的调用：计算器

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
		//每次添加一个功能都会使代码case边长，不利于扩展维护
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
//2.回调函数对qsort的冒泡i模拟实现
int menu1(){
	printf("**********************\n");
	printf("****** 1.计算KDA *****\n");
	printf("****** 0. 退出  ******\n");
	printf("**********************\n");
	return 0;
}
//KDA = (击杀 + 助攻 / 2)(死亡 + 1)

int main02(){
	float k, d, a;
	int input;
	float kda = 0;
	do
	{
		menu1();
		printf("请输入:\n");
		scanf("%d", &input);
		switch (input){
		case 1:
			printf("请输入K D A,空格隔开\n");
			scanf("%f %f %f", &k, &d, &a);
			getchar();
			kda = (k + (a / 2))/(d + 1);
			printf("KDA: %.2f\n", kda);
			printf("\n");
			break;
		case 0:
			printf("退出计算器\n");
			break;
		}
	} while (input);
}

//回调模拟实现qsort：冒泡排序
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
	//趟数
	for (i = 0; i < sz - 1; i++)
	{
		size_t j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//相邻2个元素的比较
			//base[j] base[j+1] 
			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)
			{
				//如果不满足顺序就交换
				_swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}
int callback(char *e1,char *e2){
	return *e1 - *e2;
}
//void型指针可以接收任意类型的指针
int myQsort( void *base, const int len, const char width, int(*callback)(const void *e1, const void *e2)){
	for (int i = 0; i < len; i++){
		for (int j = 0; j < len - i; j++){
		//	if (callback(e1,e2)>0){
			//base[j]与base[j+1]比较
			if (callback((char*)base + j*width, (char*)base + (j+1)*width>0)){
				//不满足则交换
				mySwap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
	return 0;
}
void test3()
{
	//qsort 排序整形数组
	int arr[] = { 1, 5, 2, 4, 3, 9, 8, 6, 7, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//void型指针可以接收任意类型的指针
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	print_arr(arr, sz);
}
