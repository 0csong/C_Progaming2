
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

struct date {          // date 구조체의 선언
	int year;
	int month;
	int day;
};

struct student {       // student 구조체 선언
	int sno;
	char name[10];
	struct date* sd;   // 포인터를 사용하여 구조체 멤버 선언
};

int rect_area(Rectangle rect)
{
	//아래를 완성하시오.
	int area = 0;
	area= (((rect.p1).x - (rect.p2).x) *((rect.p1).y - (rect.p2).y));
	return area;

}
void rect_points(Rectangle* rp, Point arr[])
{
	arr[0] = rp->p1;
	//아래를 완성하시오.
	rp->p1.x = rp->p2.x;
	arr[1] = rp->p1;
	arr[2] = rp->p2;
	rp->p2.x = arr[0].x;
	arr[3] = rp->p2;

	
}
int main(void)
{
	//1번
	Point point_arr[4];
	Rectangle rect = { {10, 20}, {110, 70} };

	int area = rect_area(rect);
	rect_points(&rect, point_arr);
	printf("사각형: 넓이: %d, 4개의 점:", area);
	for (int i = 0; i < 4; i++)
		printf("(%d,%d) ", point_arr[i].x, point_arr[i].y);
	printf("\n");

	//2번
	struct date d = { 2002, 05, 05 };

	// 구조체 변수(변수명: student) 선언과 초기화
	//아래를 완성하시오.
	struct student student;
	student.sno = 20251234;
	strcpy(student.name, "홍길동");
	student.sd = &d;


	printf("포인터를 구조체 멤버로 선언하는 프로그램 \n");
	//아래를 완성하시오.(출력)
	printf("학번:%d\n", student.sno);
	printf("성명:%s\n", student.name);
	printf("생년월일:%d.%d.%d\n",student.sd->year,student.sd->month,student.sd->day);



	return 0;
}


/*예시 출력결과
사각형: 넓이: 5000, 4개의 점:(10,20) (110,20) (110,70) (10,70)
포인터를 구조체 멤버로 선언하는 프로그램
 학번 : 20251234
 성명 : 홍길동
 생년월일 : 2002. 05. 05.
계속하려면 아무 키나 누르십시오 . . .
*/
/*실제 출력결과
사각형: 넓이: 5000, 4개의 점:(10,20) (110,20) (110,70) (10,70)
포인터를 구조체 멤버로 선언하는 프로그램
학번:20251234
성명:홍길동
생년월일:2002.5.5

C:\Users\nicky\Desktop\3-2학기\c프로그래밍2\10주차\Project1\Debug\Project1.exe(프로세스 16324개)이(가) 종료되었습니다(코드: 0개).
이 창을 닫으려면 아무 키나 누르세요...


*/
