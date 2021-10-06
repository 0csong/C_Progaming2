#include <stdio.h>
#include <stdlib.h>
int mult(int* pa, int* pb);
int square_by_value(int num);
void square_by_reference(int* num);
void swap(int* pa, int* pb);

int main(void)
{
	//1��
	int a = 10, b = 20;
	int result;

	printf("�־��� �� : a = 10, b = 20 \n");
	result = mult(&a, &b);
	printf("��ȯ�� �� : a * b = %d\n\n", result);

	//2��
	int num = 10;
	printf("square_by_value: %d\n", square_by_value(num));
	square_by_reference(&num);
	printf("square_by_reference: %d\n", num);

	//3��
	printf("\nswap ��: a:%d, b:%d\n", a, b);
	swap(&a, &b);
	printf("nswap ��: a:%d, b:%d\n", a, b);


	return 0;
}

//�Ʒ��� mult �Լ��� ���� �Ͻÿ�.
int mult(int* pa, int* pb) {
	return (*pa * *pb);
}
//�Ʒ��� square_by_valuedhk square_by_reference �Լ��� ���� �Ͻÿ�.
int square_by_value(int num){
	return num * num;
}
void square_by_reference(int* num) {
	*num = *num * *num;
}

//�Ʒ��� swap �Լ��� 1-4�� ���忡 ���� �޸� ���µ��� �ϼ��Ͻÿ�.
void swap(int* pa, int* pb) {
	int* ptmp; //1.
	ptmp = pa; //2.
	pa = pb;   //3.
	pb = ptmp; //4.

}

/*���� ��°��
 �־��� �� : a = 10, b = 20
 ��ȯ�� �� : a * b = 200

square_by_value: 100
square_by_reference: 100

swap ��: a:10, b:20
nswap ��: a:10, b:20
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
/*���� ��°��
�־��� �� : a = 10, b = 20
��ȯ�� �� : a * b = 200

square_by_value: 100
square_by_reference: 100

swap ��: a:10, b:20
nswap ��: a:10, b:20

C:\Users\nicky\Desktop\3-2�б�\c���α׷���2\4����\Project1\x64\Debug\Project1.exe(���μ��� 32268��)��(��) ����Ǿ����ϴ�(�ڵ�: 0��).
�� â�� �������� �ƹ� Ű�� ��������...




*/
