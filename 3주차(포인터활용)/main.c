#include <stdio.h>
#include <stdlib.h>

void prob_1(int *ptr, int size, int *sum_p) 
{
	
	//�Ʒ��� �ϼ��Ͻÿ�
	*sum_p = 0;

	for (int i = 0; i < size; i++) {
		*sum_p += *ptr--;
		
	}
	
}

void prob_2(int a[], int size)
{
	//�Ʒ��� �ϼ��Ͻÿ�
	*(a - 1) += 1;
	for (int i = 0; i < size-1; i++) {
		*(a + i) += 1;
	}


}

void prob_3(int* n1_p, int* n2_p, int* n3_p) {
	int tmp;

	//�Ʒ��� �ϼ��Ͻÿ�
	tmp = *n3_p;
	*n3_p = *n2_p;
	*n2_p = *n1_p;
	*n1_p = tmp;

}


int main(void){

	int a[] = { 1, 2, 3, 4, 5 }, size= 5;
	int sum;
	
	//1��
	prob_1(a+4, size, &sum);
	printf("1�� ��:%d\n", sum);

	//2��
	prob_2(a + 1, size);
	printf("2�� �� a[]: ");
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");

	//3��
	int n1 = 1, n2 = 3, n3 = 5;
	printf("3�� ��: n1:%d, n2:%d, n3:%d\n", n1, n2, n3);
	prob_3(&n1, &n2, &n3);
	printf("3�� ��: n1:%d, n2:%d, n3:%d\n", n1, n2, n3);

	
	//4��
	int c[4][4], d[4][4];

	int k = 1;
	printf("4��: 90�� ȸ�� ��\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			c[i][j] = k++;
			printf("%3d", c[i][j]);
		}
		printf("\n");
	}

	//�Ʒ��� �ϼ��Ͻÿ�
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			d[i][j] = c[3 - j][i];
		}
	}


	printf("4��: 90�� ȸ�� ��\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%3d", d[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

/*���� ��°��
1�� ��:15
2�� �� a[]: 2 3 4 5 6
3�� ��: n1:1, n2:3, n3:5
3�� ��: n1:5, n2:1, n3:3
4��: 90�� ȸ�� ��
  1  2  3  4
  5  6  7  8
  9 10 11 12
 13 14 15 16
4��: 90�� ȸ�� ��
 13  9  5  1
 14 10  6  2
 15 11  7  3
 16 12  8  4
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
/*���� ��°��
1�� ��:15
2�� �� a[]: 2 3 4 5 6
3�� ��: n1:1, n2:3, n3:5
3�� ��: n1:5, n2:1, n3:3
4��: 90�� ȸ�� ��
  1  2  3  4
  5  6  7  8
  9 10 11 12
 13 14 15 16
4��: 90�� ȸ�� ��
 13  9  5  1
 14 10  6  2
 15 11  7  3
 16 12  8  4

C:\Users\nicky\Desktop\3-2�б�\c���α׷���2\3����\Project1\Debug\Project1.exe(���μ��� 2436��)��(��) ����Ǿ����ϴ�(�ڵ�: 0��).
�� â�� �������� �ƹ� Ű�� ��������...




*/
