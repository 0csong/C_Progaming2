#pragma once

//�Ʒ��� avg()�� �����ϼ���.
double avg(int a[], int size)
{
	double sum = 0;
	for (int i=0; i<size; i++)
		sum += a[i];
	return sum / size;
}