#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	////�׸� ����
	//int num = 10;
	//int* ptr1 = &num;
	//int* ptr2 = ptr1;

	//(*ptr1)++;
	//(*ptr2)++;

	//1��
	int num1 = 20, num2 = 30;
	int* ptr1 = &num1, * ptr2 = &num2;

	//�Ʒ��� �ϼ��Ͻÿ�
	(*ptr1) += 10;
	(*ptr2) -= 10;

	printf("num1:%d, *ptr1:%d, num2:%d, *ptr2:%d\n", num1, *ptr1, num2, *ptr2);

	//�Ʒ��� �ϼ��Ͻÿ�
	int* temp;
	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
	printf("num1:%d, *ptr1:%d, num2:%d, *ptr2:%d\n", num1, *ptr1, num2, *ptr2);

	//2��
	int arr[] = { 1, 2, 3, 4, 5 };
	int* ptr = arr; //*ptr= &(arr[0]);, *ptr= arr+0;

	//�Ʒ��� �ϼ��Ͻÿ�
	for (int i = 0; i < 5; i++) {
		*ptr+=1;
		ptr++;
	}
	

	printf("ptr++, arr[]: ");
	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");

	//3��
	ptr = arr;
	//�Ʒ��� �ϼ��Ͻÿ�
	for (int i = 0; i < 5; i++) {
		*(ptr+i) += 2;
	}



	printf("ptr+i, arr[]: ");
	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");

	ptr = arr;
	//�Ʒ��� �ϼ��Ͻÿ�
	for (int i = 0; i < 5; i++) {
		ptr[i] += 2;
	}


	printf("ptr[i], arr[]: ");
	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

/*���� ��°��
num1:30, *ptr1:30, num2:20, *ptr2:20
num1:30, *ptr1:20, num2:20, *ptr2:30
ptr++, arr[]: 2 3 4 5 6
ptr+i, arr[]: 4 5 6 7 8
ptr[i], arr[]: 6 7 8 9 10
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
/*���� ��°��

*/
