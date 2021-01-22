#include<stdio.h>


int is_leap(int year){
    return  (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int main1(){

    int year=0;
    scanf("%d",&year);
    if(is_leap(year)){
        printf("%d is leap",year);
    }else {
        printf("%d is not leap",year);
    }
    
    return 0;
}
int exchange(int *x,int *y){
    int t=0;
    t=*x;
    *x=*y;
    *y=t;
    return 0;
}
int main2(){
    int a=0 ,b=1;
    printf("a is %d\n",a);
    printf("b is %d\n",b);
    exchange(&a,&b);
    printf("a is %d\n",a);
    printf("b is %d\n",b);
}
int mulit(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d * %d = %d  ",i,j,i*j);
        }
        printf("\n");
    }

}
int main(){
    int num=0;
    scanf("%d",&num);
    mulit(num);
    return 0;
}