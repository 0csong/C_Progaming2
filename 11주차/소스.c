
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void maxMin_idx(int* arr, int size, int* max_idx, int* min_idx) {
	*max_idx = *min_idx = 0;
	for (int i = 1; i < size; i++) {
		//아래를 완성하시오.
		if (*max_idx < arr[i-1])
			*max_idx = i-1;
		if (*min_idx > arr[i-1])
			*min_idx = i-1;

	}
}

void maxMin_ptr(int* arr, int size, int** max_ptr, int** min_ptr) {
	*max_ptr = *min_ptr = arr;
	for (int i = 1; i < size; i++) {
		//아래를 완성하시오.
		
		if (**max_ptr < arr[i - 1]) 
			*max_ptr =&arr[i-1];
		if (**min_ptr > arr[i - 1])
			*min_ptr =&arr[i-1];

	}
}

void get_max_1(int(*ptr)[4], int size, int* max_idx) {
	*max_idx = 0;
	for (int i = 1; i < size; i++) {
		//아래를 완성하시오.
		if (*max_idx < ptr[i - 1])
			*max_idx = i - 1;


	}
}

void get_max_2(int* ptr, int size, int** max_ptr) {
	*max_ptr = ptr;
	for (int i = 1; i < size; i++) {
		//아래를 완성하시오.
		if (**max_ptr < ptr[i - 1])
			*max_ptr = &ptr[i - 1];

	}
}

int main(void)
{
	//1번
	int max_idx, min_idx;
	int* max_ptr, * min_ptr;
	int arr[5] = { 5, 3, 8, 1, 2 };

	maxMin_idx(arr, sizeof(arr) / sizeof(int), &max_idx, &min_idx);
	printf("최대 인덱스: %d, 최소 인덱스: %d\n", max_idx, min_idx);

	//2번
	maxMin_ptr(arr, sizeof(arr) / sizeof(int), &max_ptr, &min_ptr);
	printf("최대 요소: %d, 최소 요소: %d\n", *max_ptr, *min_ptr);

	int arr_2d[][4] = { {3, 5, 1, 7}, {2, 4, 3, 0}, {8, 3, 5, 2}, {6, 2, 3, 4} };
	int row = 1;
	//3번
	get_max_1(arr_2d + row, sizeof(arr_2d[row]) / sizeof(int), &max_idx);
	printf("2차원 배열 %d행 최대 인덱스: %d\n", row, max_idx);

	//4번
	get_max_2(arr_2d[row], sizeof(arr_2d[row]) / sizeof(int), &max_ptr);
	printf("2차원 배열 %d행 최대 요소: %d\n", row, *max_ptr);

	return 0;
}


/*예시 출력결과
최대 인덱스: 2, 최소 인덱스: 3
최대 요소: 8, 최소 요소: 1
2차원 배열 1행 최대 인덱스: 1
2차원 배열 1행 최대 요소: 4
계속하려면 아무 키나 누르십시오 . . .
*/
/*실제 출력결과
최대 인덱스: 2, 최소 인덱스: 0
최대 요소: 8, 최소 요소: 1
2차원 배열 1행 최대 인덱스: 2
2차원 배열 1행 최대 요소: 4

C:\Users\nicky\Desktop\3-2학기\c프로그래밍2\11주차\Project1\Debug\Project1.exe(프로세스 31136개)이(가) 종료되었습니다(코드: 0개).
이 창을 닫으려면 아무 키나 누르세요...





*/
