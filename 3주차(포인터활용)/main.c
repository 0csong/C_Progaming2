#include <stdio.h>
#include <stdlib.h>

void prob_1(int *ptr, int size, int *sum_p) 
{
	
	//아래를 완성하시오
	*sum_p = 0;

	for (int i = 0; i < size; i++) {
		*sum_p += *ptr--;
		
	}
	
}

void prob_2(int a[], int size)
{
	//아래를 완성하시오
	*(a - 1) += 1;
	for (int i = 0; i < size-1; i++) {
		*(a + i) += 1;
	}


}

void prob_3(int* n1_p, int* n2_p, int* n3_p) {
	int tmp;

	//아래를 완성하시오
	tmp = *n3_p;
	*n3_p = *n2_p;
	*n2_p = *n1_p;
	*n1_p = tmp;

}


int main(void){

	int a[] = { 1, 2, 3, 4, 5 }, size= 5;
	int sum;
	
	//1번
	prob_1(a+4, size, &sum);
	printf("1번 합:%d\n", sum);

	//2번
	prob_2(a + 1, size);
	printf("2번 후 a[]: ");
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");

	//3번
	int n1 = 1, n2 = 3, n3 = 5;
	printf("3번 전: n1:%d, n2:%d, n3:%d\n", n1, n2, n3);
	prob_3(&n1, &n2, &n3);
	printf("3번 후: n1:%d, n2:%d, n3:%d\n", n1, n2, n3);

	
	//4번
	int c[4][4], d[4][4];

	int k = 1;
	printf("4번: 90도 회전 전\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			c[i][j] = k++;
			printf("%3d", c[i][j]);
		}
		printf("\n");
	}

	//아래를 완성하시오
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			d[i][j] = c[3 - j][i];
		}
	}


	printf("4번: 90도 회전 후\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%3d", d[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

/*예시 출력결과
1번 합:15
2번 후 a[]: 2 3 4 5 6
3번 전: n1:1, n2:3, n3:5
3번 후: n1:5, n2:1, n3:3
4번: 90도 회전 전
  1  2  3  4
  5  6  7  8
  9 10 11 12
 13 14 15 16
4번: 90도 회전 후
 13  9  5  1
 14 10  6  2
 15 11  7  3
 16 12  8  4
계속하려면 아무 키나 누르십시오 . . .
*/
/*실제 출력결과
1번 합:15
2번 후 a[]: 2 3 4 5 6
3번 전: n1:1, n2:3, n3:5
3번 후: n1:5, n2:1, n3:3
4번: 90도 회전 전
  1  2  3  4
  5  6  7  8
  9 10 11 12
 13 14 15 16
4번: 90도 회전 후
 13  9  5  1
 14 10  6  2
 15 11  7  3
 16 12  8  4

C:\Users\nicky\Desktop\3-2학기\c프로그래밍2\3주차\Project1\Debug\Project1.exe(프로세스 2436개)이(가) 종료되었습니다(코드: 0개).
이 창을 닫으려면 아무 키나 누르세요...




*/
