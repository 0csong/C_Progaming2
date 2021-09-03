
#include <stdio.h>
#include <stdlib.h>
#define ROW 5
#define COL 20

void sum_even_odd(int arr[][COL]);
void exchange(int idx1, int idx2, int arr[][COL]);
void max_frq(int arr[][COL]);
int main(void)
{
	int i, j, arr[ROW][COL];

	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			arr[i][j] = rand() % 41 + 10;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	//1) Ȧ���� �հ� ¦���� ��
	sum_even_odd(arr);

	//2)�ε��� 20�� �ε��� 50�� ���� ��ȯ
	exchange(20, 50, arr);

	//3)�󵵼��� ���� ū ���� ã�� ���
	max_frq(arr);

	return 0;
}

void sum_even_odd(int arr[][COL])
{
	int i, j;
	int even = 0, odd = 0;//even: ¦���� ��, odd: Ȧ���� ��, 

	//�Ʒ��� �ϼ��Ͻÿ�
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			if (arr[i][j] % 2 == 0)
			{
				even += arr[i][j];
			}
			else
				odd += arr[i][j];
		}
		
	}
	printf("1) Ȧ���� ��: %d,  ¦���� ��:%d\n", odd, even);
}

void exchange(int idx1, int idx2, int arr[][COL])
{
	int i1, j1, i2, j2, tmp;
	//i1: idx1�� �� �ε���, j1: idx1�� �� �ε���
	//i2: idx2�� �� �ε���, j2: idx21�� �� �ε���

	//�Ʒ��� �ϼ��Ͻÿ�


	i1 = idx1 / 20;
	j1 = idx1 % 20;
	i2 = idx2 / 20;
	j2 = idx2 % 20;
	tmp = arr[i1][j1];
	arr[i1][j1] = arr[i2][j2];
	arr[i2][j2] = tmp;

	printf("2) �ε��� 20:arr[%d][%d]=%d, �ε��� 50:arr[%d][%d]=%d\n",
		i1, j1, arr[i1][j1], i2, j2, arr[i2][j2]);
}

void max_frq(int arr[][COL])
{
	int i, j, max_i;//max_i: �󵵼� �ִ밪�� ��ġ�� freq �迭������ �ε���
	int freq[51] = { 0 }; //�迭�� ���� ���� ���� ������ 10~50 �̹Ƿ� �ִ� ũ�� 51�� ����
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
			freq[arr[i][j]]++;

	//�Ʒ��� �ϼ��Ͻÿ�
	max_i = 0;
	for (i = 10; i <51; i++) {
		if (freq[i]<=freq[i+1])
		{
			max_i = i+1;

		}
		
	}
	printf("3) arr�迭 ������ �󵵼� �ִ��� ��Ұ�:%d, �ִ밪�� �󵵼�:%d\n", max_i, freq[max_i]);
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			//if (arr[i][j] == freq[max_i]), ó�� �������� ������ �Ʒ��ٷ� ��ü�մϴ�.
			if (arr[i][j] == max_i)
				printf("arr[%d][%d] ", i, j);
		}
	}
	printf("\n");
	
	max_i = 0;
	for (i = 10; i < 51; i++) {
		if (freq[i] == 5)
		{
			max_i = i;
			break;

		}

	}

	//�ǵ帮���ʱ�
	printf("3) arr�迭 ������ �󵵼� �ִ��� ��Ұ�:%d, �ִ밪�� �󵵼�:%d\n", max_i, freq[max_i]);
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			//if (arr[i][j] == freq[max_i]), ó�� �������� ������ �Ʒ��ٷ� ��ü�մϴ�.
			if (arr[i][j] == max_i)
				printf("arr[%d][%d] ", i, j);
		}
	}
	printf("\n");
}
/*���� ��°��
10 27 30 24 32 31 49 12 35 38 16 29 44 27 49 50 12 21 40 34
11 18 17 40 15 10 47 30 48 20 45 47 21 27 34 37 11 28 30 23
13 41 49 44 12 41 22 13 14 31 14 20 36 49 39 36 41 34 28 50
26 11 19 48 11 22 30 14 45 26 27 35 33 15 26 26 10 33 49 32
41 46 27 38 29 42 15 47 42 37 21 18 36 17 12 23 15 42 20 28
1) Ȧ���� ��: 1436,  ¦���� ��:1494
2) �ε��� 20:arr[1][0]=14, �ε��� 50:arr[2][10]=11
3) arr�迭 ������ �󵵼� �ִ��� ��Ұ�:27, �ִ밪�� �󵵼�:5
arr[0][1] arr[0][13] arr[1][13] arr[3][10] arr[4][2]
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
/*���� ��°��
10 27 30 24 32 31 49 12 35 38 16 29 44 27 49 50 12 21 40 34
11 18 17 40 15 10 47 30 48 20 45 47 21 27 34 37 11 28 30 23
13 41 49 44 12 41 22 13 14 31 14 20 36 49 39 36 41 34 28 50
26 11 19 48 11 22 30 14 45 26 27 35 33 15 26 26 10 33 49 32
41 46 27 38 29 42 15 47 42 37 21 18 36 17 12 23 15 42 20 28
1) Ȧ���� ��: 1436,  ¦���� ��:1494
2) �ε��� 20:arr[1][0]=14, �ε��� 50:arr[2][10]=11
3) arr�迭 ������ �󵵼� �ִ��� ��Ұ�:49, �ִ밪�� �󵵼�:5
arr[0][6] arr[0][14] arr[2][2] arr[2][13] arr[3][18]
3) arr�迭 ������ �󵵼� �ִ��� ��Ұ�:27, �ִ밪�� �󵵼�:5
arr[0][1] arr[0][13] arr[1][13] arr[3][10] arr[4][2]

C:\Users\nicky\Desktop\3-2\c���α׷���2\2021.09.03����\Project1\Debug\Project1.exe(���μ��� 27628��)��(��) ����Ǿ����� ��(�ڵ�: 0��).
�� â�� �������� �ƹ� Ű�� ��������...


*/
