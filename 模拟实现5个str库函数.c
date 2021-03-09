#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//模拟实现strstr
char* myStrstr(char*src, char* dest){
	assert(src&&dest);
	char* temps,*tempd ;
	tempd = dest;
	while (*src!='\0'){
		temps = src;
		dest = tempd;
		while(*temps == *dest){
			temps++;
			dest++;
		}
		if (*dest == '\0'){
			return src;
		}
		src++;
	}
	temps = NULL;
	return temps;
}

//答案
char *my_strstr(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);

	char *cp = (char*)str1;
	char *substr = (char *)str2;
	char *s1 = NULL;

	if (*str2 == '\0')
		return NULL;

	while (*cp)
	{
		s1 = cp;
		substr = str2;
		while (*s1 && *substr && (*s1 == *substr))
		{
			s1++;
			substr++;
		}
		if (*substr == '\0')
			return cp;
		cp++;
	}
	return NULL;
}

//模拟实现strcat
char* myCat(const char*dest,const char*src){
	assert(dest&&src);
	char *ts =(char*) src;
	char *td = (char*) dest;
	while (*td){
		td++;
	}
	while ((*td++ = *ts++)!='\0'); 
	return dest;
}

//模拟实现strcmp
int myCmp(const char *str1,const char *str2){
	assert(str1&&str2);
	char* t1 = (char*)str1;
	char* t2 = (char*)str2;

	while (*t1++ == *t2++){
		if (*t1 == '\0'&&*t2 == '\0'){
			return 0;
		}
	}
	return *t2 - *t1;
}

//模拟实现strcpy

char* mycpy(char* dest, const char* src){
	assert(dest&&src);
	char* td = dest;
	char* ts = (char*)src;

	while ((*td++ = *ts++) != '\0');
	return dest;
}
//模拟实现strlen
unsigned int mystrlen(char* p){
	assert(p);
	char* t = p;
	while (*p){
		p++;
	}
	return p - t;
}
int main(){
	/*char*a = "bbbbbbbccabc";
	char* b = "ab";
	char* c= myStrstr(a, b);
	printf("%s\n", c);
	*/
	/*
	char arr1[20] = { "12345" };
	char *p = "abc";
	myCat(arr1, p);
	printf("%s\n", arr1);
	*/
	/*
	char* a = "abc";
	char* b = "abc";
	int ret=myCmp(a, b);
	printf("%d\n", ret);*/
	/*
	char arr[20] = { 0 };
	char* p = "abcd";
	mycpy(arr, p);
	printf("%s\n", arr);
	*/
	int ret = 0;
	char*p = "abcd";
	ret=mystrlen(p);
	printf("%d\n", ret);
	system("pause");
	return 0;
}