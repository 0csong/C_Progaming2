#include <stdio.h>
#include <stdlib.h>
int mult(int* pa, int* pb);
int square_by_value(int num);
void square_by_reference(int* num);
void swap(int* pa, int* pb);

int main(void)
{
	//1번
	int a = 10, b = 20;
	int result;

	printf("주어진 값 : a = 10, b = 20 \n");
	result = mult(&a, &b);
	printf("반환된 값 : a * b = %d\n\n", result);

	//2번
	int num = 10;
	printf("square_by_value: %d\n", square_by_value(num));
	square_by_reference(&num);
	printf("square_by_reference: %d\n", num);

	//3번
	printf("\nswap 전: a:%d, b:%d\n", a, b);
	swap(&a, &b);
	printf("nswap 후: a:%d, b:%d\n", a, b);


	return 0;
}

//아래에 mult 함수를 정의 하시오.
int mult(int* pa, int* pb) {
	return (*pa * *pb);
}
//아래에 square_by_valuedhk square_by_reference 함수를 정의 하시오.
int square_by_value(int num){
	return num * num;
}
void square_by_reference(int* num) {
	*num = *num * *num;
}

//아래의 swap 함수의 1-4번 문장에 따른 메모리 상태도를 완성하시오.
void swap(int* pa, int* pb) {
	int* ptmp; //1.
	ptmp = pa; //2.
	pa = pb;   //3.
	pb = ptmp; //4.

}

/*예시 출력결과
 주어진 값 : a = 10, b = 20
 반환된 값 : a * b = 200

square_by_value: 100
square_by_reference: 100

swap 전: a:10, b:20
nswap 후: a:10, b:20
계속하려면 아무 키나 누르십시오 . . .
*/
/*실제 출력결과
주어진 값 : a = 10, b = 20
반환된 값 : a * b = 200

square_by_value: 100
square_by_reference: 100

swap 전: a:10, b:20
nswap 후: a:10, b:20

C:\Users\nicky\Desktop\3-2학기\c프로그래밍2\4주차\Project1\x64\Debug\Project1.exe(프로세스 32268개)이(가) 종료되었습니다(코드: 0개).
이 창을 닫으려면 아무 키나 누르세요...




*/
