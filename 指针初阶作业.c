#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main01(){
	int a = 3;
	int b = 5;
	//1.��ʱ������Ч�����
	int t = 0;
	t = a;
	a = b;
	b = t;
	//2.�Ӽ��������������
	a = a + b;
	b = a - b;
	a = a - b;
	//3.������������Ч�ʵ�
	a = a^b;
	b = a^b;
	a = a^b;
	return 0;
}
int main047(){
	//������int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 
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
	//��ȡһ���������������������е�ż��λ������λ
	//���ֱ��ӡ������������
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
	//��num�Ǹ���ʱ����ѭ��
	//int ret = 0;
	//for (int i = 0; i < 32; i++){
	//	if ((num & 1) == 1){
	//		ret++;
	//	}
	//	num = num >> 1;
	//}
	//����
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
//�ַ�����β����
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
	//дһ���������ز����������� 1 �ĸ�����
	//���磺 15    0000 1111    4 �� 1
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
//���0��100000֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ�������
//��:153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ���
int shui(int num ){
	int n=0;
	int t = num;
	//���м�λ
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
//��ӡ����
int main111()
{
	int line = 0;
	int i = 0;
	scanf("%d", &line);//7
	//��ӡ�ϰ벿��
	for (i = 0; i<line; i++){
		//��ӡһ��
		//��ӡ�ո�
		int j = 0;
		for (j = 0; j<line - 1 - i; j++){
			printf(" ");
		}
		//��ӡ*
		for (j = 0; j<2 * i + 1; j++){
			printf("*");
		}
		printf("\n");
	}
	//��ӡ�°벿��
	for (i = 0; i<line - 1; i++){
		//��ӡһ��
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

//����ˮ����
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ
/*
˼·��
1. 20Ԫ���ȿ��Ժ�20ƿ����ʱ������20����ƿ��
2. ������ƿ�ӿ��Ժ�һƿ������֮�󣬿�ƿ��ʣ�ࣺempty/2(������ƿ�ӻ��ĺ���������ƿ��) + empty%2(��������ƿ��)
3. ���ƿ�Ӹ�������1�������Լ����������ظ�2
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


// ������������������ˮ����ƿ�ӻ��Ĺ���Ļ������Է��֣���ʵ���Ǹ��Ȳ����У�money*2-1
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;


	scanf("%d", &money);

	//����2
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