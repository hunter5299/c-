#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define EASY_COUNT 10
void menu();
void game();
void InitBoard(char board[ROWS][COLS], int row, int col, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char mine[ROWS][COLS], int row, int col, int count);
void FindMine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col, int count);
int CountMine(char board[ROWS][COLS], int x, int y);
void show_recusion(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
int checkwin(char mine[ROWS][COLS], int row, int col);
int main()
{
    srand((unsigned int)time(NULL));
    int input = 0;
    do
    {
        menu();
        printf("��ѡ��:>\n");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("��Ϸ��ʼ!\n");
            game();
            break;
        case 0:
            printf("�˳���Ϸ��\n");
            break;
        default:
            printf("�����������������!\n");
            break;
        }
    } while (input);
    return 0;
}
void menu()
{
    printf("****************\n");
    printf("*****1.play*****\n");
    printf("*****0.exit*****\n");
    printf("****************\n");
}
void InitBoard(char board[ROWS][COLS], int row, int col, char set)
{
    int i = 0, j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            board[i][j] = set;
        }
    }
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)//��ӡ����ʱ ע�����Ի���Ʊ��ڶ�ȡ����
{
    int i = 0, j = 0;
    printf("-------------ɨ����Ϸ---------------\n");
    for (i = 0; i <= col; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        printf("%d ", i);
        for (j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("-------------ɨ����Ϸ---------------\n");
}
void SetMine(char mine[ROWS][COLS], int row, int col, int count)
{
    while (count >= 1)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        if (mine[x][y] == '0')
        {
            mine[x][y] = '1';
            count--;
        }
    }
}
int CountMine(char board[ROWS][COLS], int x, int y)
{
    int i = 0, j = 0;
    int sum = 0;
    for (i = x - 1; i <= x + 1; i++)
    {
        for (j = y - 1; j <= y + 1; j++)
        {
            sum += board[i][j];
        }
    }
    return sum - 9 * '0';//��������1 0��ƣ����ַ���ת��Ϊ�������
}
void show_recusion(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
    int i = 0, j = 0;

    for (i = x - 1; i <= x + 1; i++)
    {
        for (j = y - 1; j <= y + 1; j++)
        {
            if (show[i][j] != ' ' && i >= 1 && i <=ROW && j >= 1 && j <=COL)
            {
                int temp = CountMine(mine, i, j);
                show[i][j] = temp + '0';
                if (show[i][j] == '0')
                {
                    show[x][y] = ' ';
                    show_recusion(mine, show, i, j);//�ݹ�ʵ��ɨ�׵���չ
                }
            }
        }
    }
}
int checkwin(char show[ROWS][COLS], int row, int col)
{
    int i = 0, j = 0;
    int count = row * col - EASY_COUNT;
    for (i = 1; i <= row; i++)
    {
        for (j = 0; j <= col; j++)
        {
            if (show[i][j] != '*' && show[i][j] != 'B')
            {
                count--;//��������Ƿ�ȫ���������ѱ��ж�
            }
        }
    }
    if (count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void FindMine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col, int count) //
{
    while (1)
    {
        int input = 0;
        printf("******1 ������� *****\n");//ʵ��ɨ���еı�ǹ���
        printf("******2 �������� *****\n");//ʵ��ɨ���е����빦��
        scanf("%d", &input);
        if(input==1){
            printf("������Ҫѡ�������:>\n");
            int x, y;
            scanf("%d%d", &x, &y);
            if (x >= 1 && x <= row && y >= 1 && y <= col)
            {
                if (show[x][y] == '*')
                {
                    show[x][y] = 'B';
                    DisplayBoard(show, ROW, COL);
                }
                else
                {
                    printf("�Ƿ����룡���������룡\n");
                }
            }
            else
            {
                printf("���������룡\n");
            }
        }
        else if(input==2)
        {
            printf("������Ҫѡ�������:>\n");
            int x, y;
            scanf("%d%d", &x, &y);
            if (x >= 1 && x <= row && y >= 1 && y <= col)
            {
                if (show[x][y] == '*' || show[x][y]=='B')
                {
                    if (mine[x][y] == '1')
                    {
                        printf("boom!���ź������ˣ�\n");
                        break;
                    }
                    else
                    {
                        show[x][y] = CountMine(mine, x, y) + '0';
                        if (show[x][y] == '0')
                        {
                            show[x][y] = ' ';
                            show_recusion(mine, show, x, y);
                        }
                        DisplayBoard(show, row, col);
                        if (checkwin(show, ROW, COL) == 1)
                        {
                            printf("��ϲ����ʤ�ˣ�\n");
                            break;
                        }
                    }
                }
                else
                {
                    printf("�ظ����룡���������룡\n");
                }
            }
            else
            {
                printf("���������룡\n");
            }
        }else{
            printf("�������\n");
        }
    }
}
void game()
    {
        char mine[ROWS][COLS];
        char show[ROWS][COLS];
        InitBoard(mine, ROWS, COLS, '0');
        InitBoard(show, ROWS, COLS, '*');
        // DisplayBoard(mine, ROW, COL); //�˴�����Ϊ������
        DisplayBoard(show, ROW, COL);
        SetMine(mine, ROW, COL, EASY_COUNT);
        // DisplayBoard(mine, ROW, COL); //�˴�����Ϊ������
        // DisplayBoard(show, ROW, COL);//�˴�����Ϊ������
        FindMine(show, mine, ROW, COL, EASY_COUNT);
    }