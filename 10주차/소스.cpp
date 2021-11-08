
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct point {
	int x, y;
} Point;
typedef struct rectangle {
	Point p1, p2;
} Rectangle;

struct date {          // date ����ü�� ����
	int year;
	int month;
	int day;
};

struct student {       // student ����ü ����
	int sno;
	char name[10];
	struct date* sd;   // �����͸� ����Ͽ� ����ü ��� ����
};

int rect_area(Rectangle rect)
{
	//�Ʒ��� �ϼ��Ͻÿ�.
	int area = 0;
	area= (((rect.p1).x - (rect.p2).x) *((rect.p1).y - (rect.p2).y));
	return area;

}
void rect_points(Rectangle* rp, Point arr[])
{
	arr[0] = rp->p1;
	//�Ʒ��� �ϼ��Ͻÿ�.
	rp->p1.x = rp->p2.x;
	arr[1] = rp->p1;
	arr[2] = rp->p2;
	rp->p2.x = arr[0].x;
	arr[3] = rp->p2;

	
}
int main(void)
{
	//1��
	Point point_arr[4];
	Rectangle rect = { {10, 20}, {110, 70} };

	int area = rect_area(rect);
	rect_points(&rect, point_arr);
	printf("�簢��: ����: %d, 4���� ��:", area);
	for (int i = 0; i < 4; i++)
		printf("(%d,%d) ", point_arr[i].x, point_arr[i].y);
	printf("\n");

	//2��
	struct date d = { 2002, 05, 05 };

	// ����ü ����(������: student) ����� �ʱ�ȭ
	//�Ʒ��� �ϼ��Ͻÿ�.
	struct student student;
	student.sno = 20251234;
	strcpy(student.name, "ȫ�浿");
	student.sd = &d;


	printf("�����͸� ����ü ����� �����ϴ� ���α׷� \n");
	//�Ʒ��� �ϼ��Ͻÿ�.(���)
	printf("�й�:%d\n", student.sno);
	printf("����:%s\n", student.name);
	printf("�������:%d.%d.%d\n",student.sd->year,student.sd->month,student.sd->day);



	return 0;
}


/*���� ��°��
�簢��: ����: 5000, 4���� ��:(10,20) (110,20) (110,70) (10,70)
�����͸� ����ü ����� �����ϴ� ���α׷�
 �й� : 20251234
 ���� : ȫ�浿
 ������� : 2002. 05. 05.
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
/*���� ��°��
�簢��: ����: 5000, 4���� ��:(10,20) (110,20) (110,70) (10,70)
�����͸� ����ü ����� �����ϴ� ���α׷�
�й�:20251234
����:ȫ�浿
�������:2002.5.5

C:\Users\nicky\Desktop\3-2�б�\c���α׷���2\10����\Project1\Debug\Project1.exe(���μ��� 16324��)��(��) ����Ǿ����ϴ�(�ڵ�: 0��).
�� â�� �������� �ƹ� Ű�� ��������...


*/
