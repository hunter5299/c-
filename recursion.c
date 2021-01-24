#include<stdio.h>

//递归打印一个整数的数字
int recursion( int n){
    if( n<9 ){
        printf("%d\n",n);
        return 0;
    }
    else
    {
        recursion(n/10);
        printf("%d ", n % 10);
    }
    
}
//递归实现strlen
int recursionLen(char *p){
    if( p == NULL){
        return -1;
    }
    if( *p == '\0'){
        return 0;
    }
    return 1+recursionLen(p+1);;
}

//自定义strlen
int myStrlen(char *p){
    if(p==NULL){
        return -1;
    }
    int len=0;
    while (*p!='\0')
    {
        /* code */
        len++;
    }
    
    return len;
}

//递归实现字符串逆序
int recurRestring(char *arr,int i){//i记录指针向后移动的距离
    if(arr == NULL){
        return -1;
    }
    char t; //临时中间变量
    if(*arr == '\0'){   //回归
        return 0;
    }
    //ret信标，找到前面需要交换的位置
    int ret=recurRestring(arr+1,++i)+1;     //递推
    char*head=arr-i+ret;
    if(head < arr){
        //交换
        t=*head;
        *head = *arr;
        *arr=t;
    }
    return ret;
}
//输入一个非负整数，求各个位之和
int recursionSum( int n){
    if( n<9 ){
        return n;
    }
    return  (n % 10)+ recursion(n/10);
}
//递归实现k的n次方
int recursionPow( int k ,int n){

    int ret=0;
    if(n==0){
        return 1;
    }
    if(n<0){
        return 1/(k*recursionPow(k,n+1));
    }
    return k*recursionPow(k,n-1);
}
//递归实现斐波那契数列
int Fac(int n){
    if(n < 3)
        return 1;
 
    return Fac(n-1) + Fac(n-2);
}
int main(){
    char arr[]="abcdefg";
    recurRestring(arr,0);
    printf("%s\n",arr);
    return 0;
}
