#include<stdio.h>

int my_cpy(char* dest, const char* source){
	if (dest == NULL || source == NULL){
		return -1;

	}
	while (*dest++ = *source++){
		;
	}
	return 0;
}

void swap_arr(int arr[], int sz){
	int left = 0;
	int right = sz - 1;
	int tmp = 0;
	while (left<right){
		// ��ǰ�����ҵ�һ��ż�����ҵ���ֹͣ
		while ((left<right) && (arr[left] % 2 == 1)){
			left++;
		}

		// �Ӻ���ǰ�ң���һ���������ҵ���ֹͣ
		while ((left<right) && (arr[right] % 2 == 0)){
			right--;
		}

		// ���ż�����������ҵ����������������ݵ�λ��
		// Ȼ������ң�ֱ������ָ������
		if (left<right){
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
void yangHuiTriangle(int n){	
	int data[30][30] = { 1 }; //��һ��ֱ����ã���������
	int i, j;
	for (i = 1; i < n; i++) //�ӵڶ��п�ʼ��
	{
		data[i][0] = 1; //ÿ�еĵ�һ�ж�û������ֱ�Ӹ�1����֤����Խ�硣
		for (j = 1; j <= i; j++) //�ӵڶ��п�ʼ��
		{
			data[i][j] = data[i - 1][j] + data[i - 1][j - 1]; //���Ʒ���
		}
	}
	for (i = 0; i < n; i++) //�����ӡ
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", data[i][j]);
		}
		putchar('\n');
	}
}
int maisan(){
	int a, b, c, d;
	
}
int main11()
{
	int murder[4] = { 0 }; //Ĭ��4���˶���������
	int i;
	for (i = 0; i < 4; i++) //���������ĸ����е�ĳ����������
	{
		murder[i] = 1; //����ĳ����������
		if ((murder[0] != 1) +
			(murder[2] == 1) +
			(murder[3] == 1) +
			(murder[3] != 1) == 3)
		{
			break; //����ʹ���������ˣ�
		}
		murder[i] = 0; //�����㻹�����
	}

	putchar('A' + i); //��ӡ���ֵı�š����ǵı����0 1 2 3������'A'����A B C D��
	return 0;
}
int checkData(int *p)
{
	int tmp[7] = { 0 }; //��Ǳ�ʵ���ǹ�ϣ���˼·��һ��ʼÿ��Ԫ�ض���0��

	int i;
	for (i = 0; i < 5; i++)
	{
		if (tmp[p[i]]) //������λ�õı���Ѿ���1��������ظ���ֱ�ӷ���0��
		{
			return 0;
		}
		tmp[p[i]] = 1; //������ǣ�������λ�ñ��Ϊ1��
	}
	return 1; //ȫ��������Ҳû�г����ظ������������OK��
}

int main()
{
	int p[5]; //0 1 2 3 4�ֱ����a b c d e

	for (p[0] = 1; p[0] <= 5; p[0]++)
	{
		for (p[1] = 1; p[1] <= 5; p[1]++)
		{
			for (p[2] = 1; p[2] <= 5; p[2]++)
			{
				for (p[3] = 1; p[3] <= 5; p[3]++)
				{
					for (p[4] = 1; p[4] <= 5; p[4]++) //���ѭ������
					{
						//����������˵����������ڱȽϱ��ʽֻ��0��1������������Ҫ������������ֻ��һ��Ϊ�棬������ñȽϱ��ʽ��ֵ�ܺ�Ϊ1�ķ�ʽֱ���ж��������˻�Ҫ�ж����ܲ��С�
						if ((p[1] == 2) + (p[0] == 3) == 1 && //B�ڶ����ҵ���
							(p[1] == 2) + (p[4] == 4) == 1 && //�ҵڶ���E����
							(p[2] == 1) + (p[3] == 2) == 1 && //�ҵ�һ��D�ڶ�
							(p[2] == 5) + (p[3] == 3) == 1 && //C����ҵ���
							(p[4] == 4) + (p[0] == 1) == 1 && //�ҵ��ģ�A��һ
							checkData(p) //���ܲ���
							)
						{
							for (int i = 0; i < 5; i++)
							{
								printf("%d ", p[i]);
							}
							putchar('\n');
						}
					}
				}
			}
		}
	}

	return 0;
}