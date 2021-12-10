
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//1��
//avg.h ���Ͽ��� avg()�� �ϼ��Ͻÿ�.
//�Ʒ��� avg()�� ���ǵ���� ������ �����ϼ���.
#include "avg.h"

int main(void)
{
	int a = 10, b = 20;

	//2. �Ʒ��� #ifndef ���� ����Ͽ� ��ũ�� �Լ��� �����Ͻÿ�.
#ifndef ADD
#define ADD(a, b) ((a) + (b))
#endif

	printf("���� ��� : %d + %d = %d \n", a, b, ADD(a, b));

	int arr[] = { 2, 4, 6, 3, 1, 8 };
	printf("��� : %.2f\n", avg(arr, sizeof(arr) / sizeof(int)));

	int sum;
#define SIZE 10
	sum = 0;
	for (int i = 1; i < SIZE; i++)
		sum += i;
	printf("1���� %d������ ��: %d\n", SIZE, sum);

	//3. �Ʒ���SIZE�� 100�� �ǵ��� ��ó���⸦ �������Ͻÿ�.
#undef SIZE
#define SIZE 100

	sum = 0;
	for (int i = 1; i < SIZE; i++)
		sum += i;
	printf("1���� %d������ ��: %d\n", SIZE, sum);


#define MULTI_5
	int n;

	//4. �Ʒ��� MULTI_5�� ���ǵǾ� ������ n=5;�� �ƴϸ� n=3; ���� ��ó���⸦ �ϼ��Ͻÿ�.
#ifdef MULTI_5
	n = 5;
#else
	n =3
#endif

	sum = 0;
	for (int i = 1; i < SIZE; i++) {
		if (i % n == 0)
			sum += i;
	}
	printf("1���� %d������ %d�� ����� ��: %d\n", SIZE, n, sum);

	return 0;
}


/*���� ��°��
���� ��� : 10 + 20 = 30
��� : 4.00
1���� 10������ ��: 45
1���� 100������ ��: 4950
1���� 100������ 5�� ����� ��: 950
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
/*���� ��°��

*/
