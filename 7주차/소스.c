#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	//1��
	int ch;
	printf("������ �Է�:");
	while ((ch = getchar()) != EOF) {
		//�Ʒ��� �ϼ��Ͻÿ�
		if ((ch >= 'a') && (ch <= 'z')) {
			ch = ch - 'a' + 'A';
			putchar(ch);
			printf("\n");

		}
		else if ((ch >= 'A') && (ch <= 'Z')) {
			ch = ch + 'a' - 'A';
			putchar(ch);
			printf("\n");

		}
		else
			printf("���ĺ��� �ƴմϴ�.\n");


		while (getchar() != '\n');

		printf("������ �Է�:");
	}

	//2��
	char str1[20], str2[20], str3[40];

	printf("str1 ���ڿ� �Է�: ");
	gets_s(str1, sizeof(str1));
	printf("str2 ���ڿ� �Է�: ");
	gets_s(str2, sizeof(str2));
	//�Ʒ��� sprintf  �Լ��� ����Ͽ� �ϼ��Ͻÿ�
	sprintf(str3,"%s,%s",str1,str2);

	printf("str3:%s\n", str3);
	int sum = 0;
	char* p = str3;
	while (*p) {
		//�Ʒ��� �ϼ��Ͻÿ�
		if (isdigit(*p)) {
			sum += *p - '0';
		}
		p++;	 
	}
	printf("������ ��: %d\n", sum);

	//3��
	char name[3][20];
	int max_age = 0; //�ִ� ����
	int max_idx; //�ִ� ������ �ε���
	int i_age; //���� ����

	for (int i = 0; i < 3; i++) {
		printf("%d. �̸� ����: ", i);
		gets_s(name[i], sizeof(name[i]));
	}
	for (int i = 0; i < 3; i++) {
		//�Ʒ��� �ϼ��Ͻÿ�
		max_idx = 0;
		if (name[i+1]+4 > name[i]+4) {
			max_idx++;
			max_age =name[i + 1]+4;
		}
	}
	printf("�ְ��: %s\n", name[max_idx]);

	return 0;
}
/*���� ��°��
������ �Է�:A
a
������ �Է�:b
B
������ �Է�:1
���ĺ��� �ƴմϴ�.
������ �Է�:^Z
str1 ���ڿ� �Է�: book20
str2 ���ڿ� �Է�: sample 12
str3: book20, sample 12
������ ��: 5
0. �̸� ����: ������ 20
1. �̸� ����: �Ѽ��� 27
2. �̸� ����: ������ 17
�ְ��: �Ѽ��� 27
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
/*���� ��°��
������ �Է�:A
a
������ �Է�:b
B
������ �Է�:1
���ĺ��� �ƴմϴ�.
������ �Է�:^Z
str1 ���ڿ� �Է�: book20
str2 ���ڿ� �Է�: sample 12
str3:book20,sample 12
������ ��: 5
0. �̸� ����: ������ 20
1. �̸� ����: �Ѽ��� 27
2. �̸� ����: ������ 17
�ְ��: �Ѽ��� 27

C:\Users\nicky\Desktop\3-2�б�\c���α׷���2\7����\Project1\Debug\Project1.exe(���μ��� 14548��)��(��) ����Ǿ����ϴ�(�� ��: 0��).
�� â�� �������� �ƹ� Ű�� ��������...



*/
