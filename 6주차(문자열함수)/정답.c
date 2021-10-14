
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 80

void alph_freq(char *s, int f[])
{
	while (*s) {
		if (isupper(*s))
			f[*s - 'A']++;
		else if (islower(*s))
			f[*s - 'a']++;
		s++;
	}
}

int count_word(char str[], char* seps) {
	char* token;
	int count = 0;

	token = strtok(str, seps);

	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
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
		if (strcmp(token, find) == 0)
			strcat(target, replace);
		else
			strcat(target, token);
		strcat(target, " "); 

		// ���� ��ū�� ��´�. 
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

*/
