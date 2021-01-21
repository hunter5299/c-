#include<stdio.h>
int getNum(int *arr){
    int num=0;
    int i=0,j=0;
    scanf("%d",&num);   //输入要存储的数据个数
    while(scanf("%d",&arr[i])!=EOF){
        i++;
        if(i==num){
            break;
        }
    }
    return num;
}
int deleteNum(int *arr,int arrLength){
    int DelNum=0;
    int i=0,j=0,delnum=0;
    scanf("%d",&DelNum);        //获得要删除数的值
    for(i=0;i<arrLength-delnum;i++){
        if(arr[i]==DelNum){
            for(j=i+1;j<arrLength;j++){
                arr[j-1]=arr[j];    //将被删除的数后的元素一一往前覆盖
            }
            delnum++;//被减去的数的数量
            i--; //重置下标重新遍历
        }
    }
    return delnum;
}
int main(){
    int arr[50];
    int len=getNum(arr);
    int delNum=0;
    delNum=deleteNum(arr,len);
    for(int i=0;i<len-delNum;i++){
        printf("%d ",arr[i]);
    }
return 0;
}