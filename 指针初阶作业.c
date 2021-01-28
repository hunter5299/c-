#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main01(){
	int a = 3;
	int b = 5;
	//1.临时变量，效率最高
	int t = 0;
	t = a;
	a = b;
	b = t;
	//2.加减法，有溢出问题
	a = a + b;
	b = a - b;
	a = a - b;
	//3.异或操作，但是效率低
	a = a^b;
	b = a^b;
	a = a^b;
	return 0;
}
int main047(){
	//求两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
	int a, b;
	scanf("%d %d", &a, &b);
	int count = 0;
	int c = 0;
	c = a^b;
	while (c){
		if ((c & 1) == 1){
			count++;
		}
		c = c >> 1;
	}
	return 0;
}

int main55(){
	//获取一个整数二进制序列中所有的偶数位和奇数位
	//，分别打印出二进制序列
	int a = 0;
	scanf("%d", &a);
	int t = 1;
	int arrJ[16];
	int arrE[16];
	int n = 0;
	int m = 0;
	for (int i = 1; i <= 32; i++){
		if (i % 2 == 0){
			arrE[n] = a&t;
			n++;
		}
		else{
			arrJ[m] = a&t;
			m++;
		}
		a = a >> 1;
	}
	return 0;
}


int getOne(int num){
	//当num是负数时，死循环
	//int ret = 0;
	//for (int i = 0; i < 32; i++){
	//	if ((num & 1) == 1){
	//		ret++;
	//	}
	//	num = num >> 1;
	//}
	//正解
			int ret = 0;
			int flag = 1;
			while (flag != 0) {
				if ((num & flag) != 0) {
					ret++;
				}
				flag = flag << 1;
			}
			
		
	return ret;
}
int printArr(int *arr,int lenth){
	int *t = NULL;
	t = arr;
	for (int i = 0; i < lenth; i++){
		printf("%d ", *t);
		t++;
	}
}
//字符串首尾逆序
int reString(char *str){
	char *head = NULL;
	char *end = NULL;
	int lenth = strlen(str) - 1;
	head = str;
	end = str + lenth;
	char t;
	while (head<end){
		t = *head;
		*head = *end;
		*end = t;
		head++;
		end--;
	}
	return 0;
}
int main666(){
	//写一个函数返回参数二进制中 1 的个数。
	//比如： 15    0000 1111    4 个 1
	int ret = 0;
	int num = 0;
	scanf("%d", &num);
	ret=getOne(num);
	printf("%d", ret);
	return 0;
}
int main777(){
	char arr[100];
	while (gets(arr))
	{
		reString(arr);
		printf("%s", arr);
	}
	return 0;
}

int main888()
{
	int a = 0;
	int i = 0;
	int sum = 0;
	int tmp = 0;
	scanf("%d%d", &a);
	for (i = 0; i<5; i++)
	{
		tmp = tmp * 10 + a;
		sum += tmp;
	}
	printf("%d\n", sum);

	return 0;
}
//求出0～100000之间的所有“水仙花数”并输出。
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，
//如:153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数
int shui(int num ){
	int n=0;
	int t = num;
	//求有几位
	int ret = 1;
	int sum = 0;
	while (t){
		t= t /10;
		n++;
	}
	t = num;
	for (int i = 0; i < n; i++){
		int single = 0;
		single = t % 10;
		for (int j = 0; j < n; j++){
			ret = ret * single;
		}
		sum = sum + ret;
		ret = 1;
		t = t / 10;
	}
	if (sum == num){
		return 1;
	}
	return 0;
}
int main999(){
	for (int i = 0; i < 100000; i++){
		if (shui(i)==1){
			printf("%d\n", i);
		}
	}
	return 0;
}
//打印菱形
int main111()
{
	int line = 0;
	int i = 0;
	scanf("%d", &line);//7
	//打印上半部分
	for (i = 0; i<line; i++){
		//打印一行
		//打印空格
		int j = 0;
		for (j = 0; j<line - 1 - i; j++){
			printf(" ");
		}
		//打印*
		for (j = 0; j<2 * i + 1; j++){
			printf("*");
		}
		printf("\n");
	}
	//打印下半部分
	for (i = 0; i<line - 1; i++){
		//打印一行
		int j = 0;
		for (j = 0; j <= i; j++){
			printf(" ");
		}
		for (j = 0; j<2 * (line - 1 - i) - 1; j++){
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

//喝汽水问题
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水
/*
思路：
1. 20元首先可以喝20瓶，此时手中有20个空瓶子
2. 两个空瓶子可以喝一瓶，喝完之后，空瓶子剩余：empty/2(两个空瓶子换的喝完后产生的瓶子) + empty%2(不够换的瓶子)
3. 如果瓶子个数超过1个，可以继续换，即重复2
*/
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	total = money;
	empty = money;
	while (empty>1)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}


	return 0;
}


// 方法二：按照上述喝水和用瓶子换的规则的话，可以发现，其实就是个等差数列：money*2-1
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;


	scanf("%d", &money);

	//方法2
	if (money <= 0)
	{
		total = 0;
	}
	else
	{
		total = money * 2 - 1;
	}
	printf("total = %d\n", total);


	return 0;
}