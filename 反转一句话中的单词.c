#define _CRT_SECURE_NO_WARNINGS 1
//一句话中逆序单词
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
	//反转整句话
	reverse(arr, arr + strlen(arr)-1);
	printf("%s\n", arr);
	//反转每个单词
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
		//否则start指向了'\0'的后面，若是一个随机值，则不能退出外层循环，因此直接指向'\0'；
		else{
			start = end;
		}
	}
	printf("%s\n", arr);
	system("pause");
	return 0;
}