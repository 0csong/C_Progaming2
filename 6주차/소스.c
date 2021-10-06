#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 80

void alph_freq(char *s, int f[])
{
	while (*s) {
		//아래를 완성하시오
		//s에 특정 알파벳이 존재하면 해당하는 freq[i]증가
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

	token = strtok(str, seps); //token은 seps기준으로 잘린 문자열

	while (token != NULL)
	{
		//아래를 완성하시오
		
		count++;
		token = strtok(NULL, seps);



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
		//아래를 완성하시오
		if (strcmp(token, find) == 0)
			strcat(target, replace); 
		else
			strcat(target, token);
		strcat(target, " ");


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
수정된 문자열: i meet a girl at midnight.

C:\Users\nicky\Desktop\3-2학기\c프로그래밍2\6주차\Project1\Debug\Project1.exe(프로세스 10316개)이(가) 종료되었습니다(코 드: 0개).
이 창을 닫으려면 아무 키나 누르세요...




*/
