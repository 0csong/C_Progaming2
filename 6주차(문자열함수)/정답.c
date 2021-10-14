
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
	//1번
	int i;
	char ch;
	char str[SIZE], str1[SIZE];
	int freq[26] = { 0 };
	printf("영문자열을 입력하시오: ");
	gets_s(str, sizeof(str));

	alph_freq(str, freq);
	for (ch = 'a', i= 0; ch <= 'z'; ch++, i++) {
		if (freq[i])
			printf("%c: %d \n", ch, freq[i]);
	}

	//2번
	char *seps = " ,\t\n";
	strcpy(str1, str);
	printf("단어의 수는 %d입니다.\n", count_word(str1, seps));
	
	//3번
	char* token;
	char find[SIZE], replace[SIZE], target[SIZE] = "";
	printf("찾을 문자열: ");
	scanf("%s", find);
	printf("바꿀 문자열: ");
	scanf("%s", replace);

	// 문자열에서 첫번째 토큰을 얻는다. 
	token = strtok(str, seps);
	while (token != NULL)
	{
		if (strcmp(token, find) == 0)
			strcat(target, replace);
		else
			strcat(target, token);
		strcat(target, " "); 

		// 다음 토큰을 얻는다. 
		token = strtok(NULL, seps);
	}
	printf("수정된 문자열: %s\n", target);

	return 0;
}


/*예시 출력결과
영문자열을 입력하시오: I meet a boy at midnight.
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
단어의 수는 6입니다.
찾을 문자열: boy
바꿀 문자열: girl
수정된 문자열: I meet a girl at midnight.
계속하려면 아무 키나 누르십시오 . . .
*/
/*실제 출력결과

*/
