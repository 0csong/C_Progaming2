#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 80

void alph_freq(char *s, int f[])
{
	while (*s) {
		//�Ʒ��� �ϼ��Ͻÿ�
		//s�� Ư�� ���ĺ��� �����ϸ� �ش��ϴ� freq[i]����
		strlwr(s);
		for (int i = 0; s[i] != NULL; i++) {
			if (s[i] == 'a')
				f[0]++;
			if (s[i] == 'b')
				f[1]++;
			if (s[i] == 'c')
				f[2]++;
			if (s[i] == 'd')
				f[3]++;
			if (s[i] == 'e')
				f[4]++;
			if (s[i] == 'f')
				f[5]++;
			if (s[i] == 'g')
				f[6]++;
			if (s[i] == 'h')
				f[7]++;
			if (s[i] == 'i')
				f[8]++;
			if (s[i] == 'j')
				f[9]++;
			if (s[i] == 'k')
				f[10]++;
			if (s[i] == 'l')
				f[11]++;
			if (s[i] == 'm')
				f[12]++;
			if (s[i] == 'n')
				f[13]++;
			if (s[i] == 'o')
				f[14]++;
			if (s[i] == 'p')
				f[15]++;
			if (s[i] == 'q')
				f[16]++;
			if (s[i] == 'r')
				f[17]++;
			if (s[i] == 's')
				f[18]++;
			if (s[i] == 't')
				f[19]++;
			if (s[i] == 'u')
				f[20]++;
			if (s[i] == 'v')
				f[21]++;
			if (s[i] == 'w')
				f[22]++;
			if (s[i] == 'x')
				f[23]++;
			if (s[i] == 'y')
				f[24]++;
			if (s[i] == 'z')
				f[25]++;
		}break;

	}
}

int count_word(char str[], char* seps) {
	char* token;
	int count = 0;

	token = strtok(str, seps); //token�� seps�������� �߸� ���ڿ�

	while (token != NULL)
	{
		//�Ʒ��� �ϼ��Ͻÿ�
		
		count++;
		token = strtok(NULL, seps);



	}
	return count;
}

int main(void)
{
	//1��
	int i;
	char ch;
	char str[SIZE], str1[SIZE];
	int freq[26] = { 0 };
	printf("�����ڿ��� �Է��Ͻÿ�: ");
	gets_s(str, sizeof(str));

	alph_freq(str, freq);
	for (ch = 'a', i= 0; ch <= 'z'; ch++, i++) {
		if (freq[i])
			printf("%c: %d \n", ch, freq[i]);
	}

	//2��
	char *seps = " ,\t\n";
	strcpy(str1, str);
	printf("�ܾ��� ���� %d�Դϴ�.\n", count_word(str1, seps));
	
	//3��
	char* token;
	char find[SIZE], replace[SIZE], target[SIZE] = "";
	printf("ã�� ���ڿ�: ");
	scanf("%s", find);
	printf("�ٲ� ���ڿ�: ");
	scanf("%s", replace);

	// ���ڿ����� ù��° ��ū�� ��´�. 
	token = strtok(str, seps);
	while (token != NULL)
	{
		//�Ʒ��� �ϼ��Ͻÿ�
		if (strcmp(token, find) == 0)
			strcat(target, replace); 
		else
			strcat(target, token);
		strcat(target, " ");


		token = strtok(NULL, seps);
	}
	printf("������ ���ڿ�: %s\n", target);

	return 0;
}


/*���� ��°��
�����ڿ��� �Է��Ͻÿ�: I meet a boy at midnight.
a: 2
b: 1
d: 1
e: 2
g: 1
h: 1
i: 3
m: 2
n: 1
o: 1
t: 3
y: 1
�ܾ��� ���� 6�Դϴ�.
ã�� ���ڿ�: boy
�ٲ� ���ڿ�: girl
������ ���ڿ�: I meet a girl at midnight.
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
/*���� ��°��
�����ڿ��� �Է��Ͻÿ�: I meet a boy at midnight.
a: 2
b: 1
d: 1
e: 2
g: 1
h: 1
i: 3
m: 2
n: 1
o: 1
t: 3
y: 1
�ܾ��� ���� 6�Դϴ�.
ã�� ���ڿ�: boy
�ٲ� ���ڿ�: girl
������ ���ڿ�: i meet a girl at midnight.

C:\Users\nicky\Desktop\3-2�б�\c���α׷���2\6����\Project1\Debug\Project1.exe(���μ��� 10316��)��(��) ����Ǿ����ϴ�(�� ��: 0��).
�� â�� �������� �ƹ� Ű�� ��������...




*/
