#define _CRT_SECURE_NO_WARNINGS 1
//һ�仰�����򵥴�
//i like beijing. -> beijing. like i

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
int reverse(char* left, char* right){
	assert(left&&right);
	while (left < right){
		char t = *left;
		*left = *right;
		*right = t;
		left++;
		right--;
	}
	return 0;
}

int main(){
	char arr[64] = { "i like beijing." };
	//gets(arr);
	//��ת���仰
	reverse(arr, arr + strlen(arr)-1);
	printf("%s\n", arr);
	//��תÿ������
	char *start = NULL;
	char *end = NULL;
	start = arr;
	while (*start != '\0'){
		end = start;
		while (*end != ' '&& *end!='\0'){
			end++;
		}
		reverse(start, end - 1);
		if (*end == ' '){
			start = end + 1;
		}
		//����startָ����'\0'�ĺ��棬����һ�����ֵ�������˳����ѭ�������ֱ��ָ��'\0'��
		else{
			start = end;
		}
	}
	printf("%s\n", arr);
	system("pause");
	return 0;
}