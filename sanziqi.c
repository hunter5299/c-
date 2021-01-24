#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
int menu(){
    printf("***********************\n");
    printf("*******  1.paly  ******\n");
    printf("*******  0.exit  ******\n");
    printf("***********************\n");
    return 0;
}
int initGame(char arr[ROW][COL],int row,int col){
    for(int i=0; i< row;i++){
        for( int j=0; j< col ;j++){
            arr[i][j]=' ';
        }
    }
    return 0;
}
int displayGame(char arr[ROW][COL],int row,int col){
    if(arr==NULL){
        return -1;
    }
    int i,j;
    for(i = 0; i< row ;i++){
        for(j =0 ;j< col;j++){
            printf(" %c ",arr[i][j]);
           if( j< col -1){
                printf("|");
            }
        }
        printf("\n");
        if(i < col -1){
            for( j=0 ;j < col ;j++){
                printf("---");
                if( j< col -1){
                    printf("|");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
int playMove(char arr[ROW][COL],int row,int col){
    int x,y;
    while (1){
        printf("玩家输入：\n");
        scanf("%d %d",&x,&y);
        if(x >= 1 && x<= row && y>=1 &&y <= col ){
            if(arr[x-1][y-1] !=' '){
                printf("位置已被占用\n");
            }else
            {
                arr[x-1][y-1] = '*';
                break;
            }
            
        }
        else{
            printf("位置不合法\n");
        }
    }
    return 0;
}
int computerMove(char arr[ROW][COL],int row,int col){
    int x,y;
    x=rand()%row;
    y=rand()%col;
    printf("电脑输入\n");
    while (1){
        if(arr[x][y] ==' '){
            arr[x][y] = '#';
            break;
        }
    }
    return 0;
}
int isFull(char arr[ROW][COL],int row,int col){
    for(int i=0; i<row ;i++){
        for(int j=0 ;j<col;j++){
            if(arr[i][j] == ' '){
                return 0;
            }
        }
    }
    return 1;
}
char checkWin(char arr[ROW][COL],int row,int col){
    int i=0;
    //行
    for( i=0;i<row ; i++){
        if(arr[i][0]==arr[i][1]&&arr[i][1]==arr[i][2]&&arr[i][0]!=' '){
            return arr[i][0];
        }
    }
    //列
    for( i=0;i<col ; i++){
        if(arr[0][i]==arr[1][i]&&arr[1][i]==arr[2][i]&&arr[0][i]!=' '){
            return arr[i][0];
        }
    }
    //对角线
    if(arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2]&&arr[0][0]!=' '){
        return arr[0][0];
    }
    if(arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0]&&arr[1][1]!=' '){
        return arr[1][1];
    }
    //平局，棋盘已满
    if(isFull(arr,row,col)==1){
        return 'q';
    }
    //继续对局
    return 'c';
}

int game(){
        char arr[ROW][COL];
        char ret=0;
        //随机数生成器
        srand((unsigned int)time(NULL));
        //初始化
        initGame(arr,ROW,COL);
        //展示
        displayGame(arr,ROW,COL);
       while (1)
       {
           //玩家走
            playMove(arr,ROW,COL);
            //检查是否结束
            ret= checkWin(arr,ROW,COL);
            if(ret!='c'){
                break;
            }
            displayGame(arr,ROW,COL);
            computerMove(arr,ROW,COL);
            ret =checkWin(arr,ROW,COL);
            if(ret != 'c'){
                break;
            }
            displayGame(arr,ROW,COL);
       }
       if(ret == '*'){
           printf("玩家胜利\n");
       }else if( ret == '#'){
           printf("电脑胜利\n");
       }else if(ret == 'q'){
           printf("平局\n");
       }
    return 0;
}

int main(){
    int input=0;
    do{
        menu();
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误\n");
            break;
        }
    }while(input);
    return 0;
}