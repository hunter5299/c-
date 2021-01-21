#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int menu(){
        printf("***********************\n");
        printf("****** 请猜数字  ******\n");
        printf("****** 1.play    ******\n");
        printf("****** 2.exit    *******\n");
        printf("***********************\n");
    return 0;
}
int game(){
    int ret = rand()%100+1;//生成一个伪随机数
    int guess=0;
    while(1){
        printf("please enter guess number :>");
        scanf("%d",&guess);
        if(guess > ret){
            printf("大了\n");
        }else if(guess < ret){
            printf("小了\n");
        }else{
            printf("答对了\n");
            break;
        }
    }
    return 0;
}
int main (){
    int did;
    srand((unsigned int)time(NULL));//设置时间戳为伪随机数生成器参数
    do{
        menu();
        scanf("%d",&did);
        switch (did)
        {
        case 1:
            game();
            break;
        case 2:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误\n");
            break;
        }
    }while(did!=2);
    return 0;
}