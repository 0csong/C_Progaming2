#pragma once

//�Ʒ��� avg()�� �����ϼ���.
double avg(int data[], int len) {
	int sum = 0;
	double result = 0.0;
	for (int i = 0; i < len; i++) {
		sum += data[i];
		result = sum / (double)len;
	}
	return result;
}