
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define SIZE 3
struct student {
	int number;	// �й�
	char name[20];	// �̸�
	double gpa;	// ����
};

int main(void)
{
	FILE* fp = NULL, *fp_tmp;
	char buf[100];

	//1��
	if ((fp = fopen("student.txt", "wt")) == NULL)
	{
		fprintf(stderr, "����� ���� ������ �� �� �����ϴ�.\n");
		exit(1);
	}
	fputs("#�̸�: ȫ�浿\n", fp);
	fclose(fp);

	//�Ʒ��� �ϼ��Ͻÿ�. "#���: �౸" �� �߰��Ͻÿ�.
	if ((fp = fopen("student.txt", "at")) == NULL)
	{
		fprintf(stderr, "�߰��� ���� ������ �� �� �����ϴ�.\n");
		exit(1);
	}
	fputs("##���: �౸\n", fp);

	fclose(fp);
	//student.txt �� �޸������� ���� ������ �Ʒ��� ������ Ȯ���� ������.
	//#�̸�: ȫ�浿
	//##���: �౸
	if ((fp = fopen("student.txt", "rt")) == NULL)
	{
		fprintf(stderr, "�б⸦ ���� ������ �� �� �����ϴ�.\n");
		exit(1);
	}
	while (fgets(buf, 100, fp)) {
		printf("%s", buf);
	}

	//2��
	struct student table[SIZE] = {
		{ 1, "Kim", 3.99 },
		{ 2, "Min", 2.68 },
		{ 3, "Lee", 4.01 }
	};
	struct student s;
	int stu_no;
	double stu_gpa;

	// ���� ������ ���� ���� ����.
	if ((fp = fopen("student.dat", "wb+")) == NULL)
	{
		fprintf(stderr, "����� ���� ������ �� �� �����ϴ�.\n");
		exit(1);
	}
	// �迭�� ���Ͽ� �����Ѵ�.
	fwrite(table, sizeof(struct student), SIZE, fp);
	fseek(fp, 0, SEEK_SET);
	while (fread(&s, sizeof(struct student), 1, fp) == 1) {
		printf("%d, %s, %.2f\n", s.number, s.name, s.gpa);
	}

	printf("������ �й�: ");
	scanf("%d", &stu_no);
	printf("������ ����: ");
	scanf("%lf", &stu_gpa);

	//�Ʒ��� �ϼ��Ͻÿ�
	fseek(fp, 0, SEEK_SET);
	if ((fp_tmp = fopen("tmp.dat", "wb")) == NULL) {
		fprintf(stderr, "���� tmp.dat�� �� �� �����ϴ�");
		exit(1);
	}
	while (fread(&s, sizeof(struct student), 1, fp) == 1) {
		if (s.number == stu_no)
			s.gpa = stu_gpa;
		fwrite(&s, sizeof(struct student), 1, fp_tmp);
	}

	fclose(fp);
	fclose(fp_tmp);
	remove("student.dat");
	rename("tmp.dat", "student.dat");

	if ((fp = fopen("student.dat", "rb")) == NULL) {
		fprintf(stderr, "�Է��� ���� ������ �� �� �����ϴ�");
		exit(1);
	}
	while (fread(&s, sizeof(struct student), 1, fp) == 1) {
		printf("%d, %s, %.2f\n", s.number, s.name, s.gpa);
	}

	return 0;
}


/*���� ��°��
#�̸�: ȫ�浿
##���: �౸
1, Kim, 3.99
2, Min, 2.68
3, Lee, 4.01
������ �й�: 2
������ ����: 3.5
1, Kim, 3.99
2, Min, 3.50
3, Lee, 4.01
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
/*���� ��°��

*/
