// �������� Ư¡: �޸� 2�� �ʿ� 

#include <stdio.h>

int number = 8;
int sorted[8]; // ���� �迭�� �ݵ�� ���� ������ ����

void merge(int a[], int m, int middle, int n) {
// (������ �迭, ������, �߰���, ����) 
	int i = m;
	int j = middle + 1;
	int k = m;
	// ���� ������� �迭�� ����
	while(i<=middle && j<=n) {
		if(a[i] <= a[j]){
			sorted[k] = a[i];
			i++;
		} else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	} 
	// ���� �����͵� ����
	if(i > middle) {  // i�� ���� �����ٸ� ���� j�� �ֱ�  
		for(int t=j; t<=n; t++) {
			sorted[k] = a[t];
			k++;
		}
	} else {
		for (int t = i; t<= middle; t++) {  // j�� ���� �����ٸ� ���� i�� �ֱ� 
			sorted[k] = a[t];
			k++;
		}
	}
	// ���ĵ� �迭�� ���� �迭�� ����  
	for(int t=m; t<=n; t++) {
		a[t] = sorted[t];
	}
} 

void mergeSort(int a[], int m, int n) { // (�迭, �����ε���, ���ε���)
	// �迭 ũ�Ⱑ 1���� ū ���
	if (m<n) {
		int middle = (m+n) / 2;
		// ����  
		mergeSort(a, m, middle);
		mergeSort(a, middle+1, n);
		// �պ�  
		merge(a, m, middle, n);
	} 
}

int main(void) {
	int array[number] = {7, 6, 5, 8, 3, 5, 9, 1};
	mergeSort(array, 0, number - 1);
	for(int i=0; i<number; i++) {
		printf("%d ", array[i]);
	}
	
	return 0;
}
