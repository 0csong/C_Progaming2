
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define SIZE 3
struct student {
	int number;	// 학번
	char name[20];	// 이름
	double gpa;	// 평점
};

int main(void)
{
	FILE* fp = NULL, *fp_tmp;
	char buf[100];

	//1번
	if ((fp = fopen("student.txt", "wt")) == NULL)
	{
		fprintf(stderr, "출력을 위한 파일을 열 수 없습니다.\n");
		exit(1);
	}
	fputs("#이름: 홍길동\n", fp);
	fclose(fp);

	//아래를 완성하시오. "#취미: 축구" 를 추가하시오.
	if ((fp = fopen("student.txt", "at")) == NULL)
	{
		fprintf(stderr, "추가를 위한 파일을 열 수 없습니다.\n");
		exit(1);
	}
	fputs("##취미: 축구\n", fp);

	fclose(fp);
	//student.txt 를 메모장으로 열어 내용이 아래와 같은지 확인해 보세요.
	//#이름: 홍길동
	//##취미: 축구
	if ((fp = fopen("student.txt", "rt")) == NULL)
	{
		fprintf(stderr, "읽기를 위한 파일을 열 수 없습니다.\n");
		exit(1);
	}
	while (fgets(buf, 100, fp)) {
		printf("%s", buf);
	}

	//2번
	struct student table[SIZE] = {
		{ 1, "Kim", 3.99 },
		{ 2, "Min", 2.68 },
		{ 3, "Lee", 4.01 }
	};
	struct student s;
	int stu_no;
	double stu_gpa;

	// 이진 파일을 쓰기 모드로 연다.
	if ((fp = fopen("student.dat", "wb+")) == NULL)
	{
		fprintf(stderr, "출력을 위한 파일을 열 수 없습니다.\n");
		exit(1);
	}
	// 배열을 파일에 저장한다.
	fwrite(table, sizeof(struct student), SIZE, fp);
	fseek(fp, 0, SEEK_SET);
	while (fread(&s, sizeof(struct student), 1, fp) == 1) {
		printf("%d, %s, %.2f\n", s.number, s.name, s.gpa);
	}

	printf("수정할 학번: ");
	scanf("%d", &stu_no);
	printf("수정할 평점: ");
	scanf("%lf", &stu_gpa);

	//아래를 완성하시오
	fseek(fp, 0, SEEK_SET);
	if ((fp_tmp = fopen("tmp.dat", "wb")) == NULL) {
		fprintf(stderr, "파일 tmp.dat를 열 수 없습니다");
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
		fprintf(stderr, "입력을 위한 파일을 열 수 없습니다");
		exit(1);
	}
	while (fread(&s, sizeof(struct student), 1, fp) == 1) {
		printf("%d, %s, %.2f\n", s.number, s.name, s.gpa);
	}

	return 0;
}


/*예시 출력결과
#이름: 홍길동
##취미: 축구
1, Kim, 3.99
2, Min, 2.68
3, Lee, 4.01
수정할 학번: 2
수정할 평점: 3.5
1, Kim, 3.99
2, Min, 3.50
3, Lee, 4.01
계속하려면 아무 키나 누르십시오 . . .
*/
/*실제 출력결과

*/
