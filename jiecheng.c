#include<stdio.h>
int jiecheng(int n){
    if(n==0){	//递归正常结束
        return 1;
    }
    return n*jiecheng(n-1);//递归调用
}
int main(){

    int n=0;
    int ret=0;
    scanf("%d",&n);
    for( int i=1;i<=n;i++){	//分别求1！到10！阶乘并相加求和
        ret=ret+jiecheng(i);
    }
    printf("%d",ret);
    return 0;
}
