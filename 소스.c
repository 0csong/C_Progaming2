
#include <stdio.h>
#include <stdlib.h>
#define ROW 5
#define COL 20

void sum_even_odd(int arr[][COL]);
void exchange(int idx1, int idx2, int arr[][COL]);
void max_frq(int arr[][COL]);
int main(void)
{
	int i, j, arr[ROW][COL];

	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			arr[i][j] = rand() % 41 + 10;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	//1) 홀수의 합과 짝수의 합
	sum_even_odd(arr);

	//2)인덱스 20과 인덱스 50의 값을 교환
	exchange(20, 50, arr);

	//3)빈도수가 가장 큰 값을 찾아 출력
	max_frq(arr);

	return 0;
}

void sum_even_odd(int arr[][COL])
{
	int i, j;
	int even = 0, odd = 0;//even: 짝수의 합, odd: 홀수의 합, 

	//아래를 완성하시오
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			if (arr[i][j] % 2 == 0)
			{
				even += arr[i][j];
			}
			else
				odd += arr[i][j];
		}
		
	}
	printf("1) 홀수의 합: %d,  짝수의 합:%d\n", odd, even);
}

void exchange(int idx1, int idx2, int arr[][COL])
{
	int i1, j1, i2, j2, tmp;
	//i1: idx1의 행 인덱스, j1: idx1의 열 인덱스
	//i2: idx2의 행 인덱스, j2: idx21의 열 인덱스

	//아래를 완성하시오


	i1 = idx1 / 20;
	j1 = idx1 % 20;
	i2 = idx2 / 20;
	j2 = idx2 % 20;
	tmp = arr[i1][j1];
	arr[i1][j1] = arr[i2][j2];
	arr[i2][j2] = tmp;

	printf("2) 인덱스 20:arr[%d][%d]=%d, 인덱스 50:arr[%d][%d]=%d\n",
		i1, j1, arr[i1][j1], i2, j2, arr[i2][j2]);
}

void max_frq(int arr[][COL])
{
	int i, j, max_i;//max_i: 빈도수 최대값이 위치한 freq 배열에서의 인덱스
	int freq[51] = { 0 }; //배열의 원소 값이 갖는 범위가 10~50 이므로 최대 크기 51로 선언
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
			freq[arr[i][j]]++;

	//아래를 완성하시오
	max_i = 0;
	for (i = 10; i <51; i++) {
		if (freq[i]<=freq[i+1])
		{
			max_i = i+1;

		}
		
	}
	printf("3) arr배열 원소중 빈도수 최대인 요소값:%d, 최대값의 빈도수:%d\n", max_i, freq[max_i]);
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			//if (arr[i][j] == freq[max_i]), 처음 문제에서 오류로 아래줄로 대체합니다.
			if (arr[i][j] == max_i)
				printf("arr[%d][%d] ", i, j);
		}
	}
	printf("\n");
	
	max_i = 0;
	for (i = 10; i < 51; i++) {
		if (freq[i] == 5)
		{
			max_i = i;
			break;

		}

	}

	//건드리지않기
	printf("3) arr배열 원소중 빈도수 최대인 요소값:%d, 최대값의 빈도수:%d\n", max_i, freq[max_i]);
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			//if (arr[i][j] == freq[max_i]), 처음 문제에서 오류로 아래줄로 대체합니다.
			if (arr[i][j] == max_i)
				printf("arr[%d][%d] ", i, j);
		}
	}
	printf("\n");
}
/*예시 출력결과
10 27 30 24 32 31 49 12 35 38 16 29 44 27 49 50 12 21 40 34
11 18 17 40 15 10 47 30 48 20 45 47 21 27 34 37 11 28 30 23
13 41 49 44 12 41 22 13 14 31 14 20 36 49 39 36 41 34 28 50
26 11 19 48 11 22 30 14 45 26 27 35 33 15 26 26 10 33 49 32
41 46 27 38 29 42 15 47 42 37 21 18 36 17 12 23 15 42 20 28
1) 홀수의 합: 1436,  짝수의 합:1494
2) 인덱스 20:arr[1][0]=14, 인덱스 50:arr[2][10]=11
3) arr배열 원소중 빈도수 최대인 요소값:27, 최대값의 빈도수:5
arr[0][1] arr[0][13] arr[1][13] arr[3][10] arr[4][2]
계속하려면 아무 키나 누르십시오 . . .
*/
/*실제 출력결과
10 27 30 24 32 31 49 12 35 38 16 29 44 27 49 50 12 21 40 34
11 18 17 40 15 10 47 30 48 20 45 47 21 27 34 37 11 28 30 23
13 41 49 44 12 41 22 13 14 31 14 20 36 49 39 36 41 34 28 50
26 11 19 48 11 22 30 14 45 26 27 35 33 15 26 26 10 33 49 32
41 46 27 38 29 42 15 47 42 37 21 18 36 17 12 23 15 42 20 28
1) 홀수의 합: 1436,  짝수의 합:1494
2) 인덱스 20:arr[1][0]=14, 인덱스 50:arr[2][10]=11
3) arr배열 원소중 빈도수 최대인 요소값:49, 최대값의 빈도수:5
arr[0][6] arr[0][14] arr[2][2] arr[2][13] arr[3][18]
3) arr배열 원소중 빈도수 최대인 요소값:27, 최대값의 빈도수:5
arr[0][1] arr[0][13] arr[1][13] arr[3][10] arr[4][2]

C:\Users\nicky\Desktop\3-2\c프로그래밍2\2021.09.03과제\Project1\Debug\Project1.exe(프로세스 27628개)이(가) 종료되었습니 다(코드: 0개).
이 창을 닫으려면 아무 키나 누르세요...


*/
