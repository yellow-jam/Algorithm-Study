#include <iostream>

using namespace std;

dcPower(int x, int n) {  // x�� n�� ���ϱ� 
	cout<< x << n << endl;
	if (n==0) return 1;
	if (n==1) return x;
	if (n%2==0) {  // even 
		int ret = dcPower(x, n/2);
		return ret*ret;
	}
	else {  // odd
		int ret = dcPower(x, (n-1)/2);
		return ret*ret*x;
	}
}

int number = 24;
int sorted[24]; // ���� �迭�� �ݵ�� ���� ������ ����

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
	
	int coin[number] = {7,7,8,7,8,9,
						7,7,8,7,8,9,
						7,7,8,7,8,9,
						8,7,8,6,9,7};
	
	mergeSort(coin, 0, 24);
	cout<<coin[0];
	
	return 0;
}
