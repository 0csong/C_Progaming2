#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	//1번
	int ch;
	printf("영문자 입력:");
	while ((ch = getchar()) != EOF) {
		//아래를 완성하시오
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
			printf("알파벳이 아닙니다.\n");


		while (getchar() != '\n');

		printf("영문자 입력:");
	}

	//2번
	char str1[20], str2[20], str3[40];

	printf("str1 문자열 입력: ");
	gets_s(str1, sizeof(str1));
	printf("str2 문자열 입력: ");
	gets_s(str2, sizeof(str2));
	//아래를 sprintf  함수를 사용하여 완성하시오
	sprintf(str3,"%s,%s",str1,str2);

	printf("str3:%s\n", str3);
	int sum = 0;
	char* p = str3;
	while (*p) {
		//아래를 완성하시오
		if (isdigit(*p)) {
			sum += *p - '0';
		}
		p++;	 
	}
	printf("숫자의 합: %d\n", sum);

	//3번
	char name[3][20];
	int max_age = 0; //최대 나이
	int max_idx; //최대 나이의 인덱스
	int i_age; //비교할 나이

	for (int i = 0; i < 3; i++) {
		printf("%d. 이름 나이: ", i);
		gets_s(name[i], sizeof(name[i]));
	}
	for (int i = 0; i < 3; i++) {
		//아래를 완성하시오
		max_idx = 0;
		if (name[i+1]+4 > name[i]+4) {
			max_idx++;
			max_age =name[i + 1]+4;
		}
	}
	printf("최고령: %s\n", name[max_idx]);

	return 0;
}
/*예시 출력결과
영문자 입력:A
a
영문자 입력:b
B
영문자 입력:1
알파벳이 아닙니다.
영문자 입력:^Z
str1 문자열 입력: book20
str2 문자열 입력: sample 12
str3: book20, sample 12
숫자의 합: 5
0. 이름 나이: 이정선 20
1. 이름 나이: 한수정 27
2. 이름 나이: 오선주 17
최고령: 한수정 27
계속하려면 아무 키나 누르십시오 . . .
*/
/*실제 출력결과
영문자 입력:A
a
영문자 입력:b
B
영문자 입력:1
알파벳이 아닙니다.
영문자 입력:^Z
str1 문자열 입력: book20
str2 문자열 입력: sample 12
str3:book20,sample 12
숫자의 합: 5
0. 이름 나이: 이정선 20
1. 이름 나이: 한수정 27
2. 이름 나이: 오선주 17
최고령: 한수정 27

C:\Users\nicky\Desktop\3-2학기\c프로그래밍2\7주차\Project1\Debug\Project1.exe(프로세스 14548개)이(가) 종료되었습니다(코 드: 0개).
이 창을 닫으려면 아무 키나 누르세요...



*/
