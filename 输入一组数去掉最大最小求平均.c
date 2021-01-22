#include<stdio.h>
int getScore(double *score){
    int a[7];
    int t=0;
    int fi=0;
    scanf("%d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]);
    //排序
        for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
            for(int j=1;j<sizeof(a)/sizeof(a[0])-i;j++){
                if(a[j-1]>a[j]){
                    t=a[j-1];
                    a[j-1]=a[j];
                    a[j]=t;
                }
            }
        }
        for(int i=1;i<6;i++){
            fi+=a[i];
        }
        *score=fi/5.00;
    return 0;
}
int main(){
        
    double score=0.00;
    getScore(&score);
    printf("%.2lf\n",score);
    return 0;
}