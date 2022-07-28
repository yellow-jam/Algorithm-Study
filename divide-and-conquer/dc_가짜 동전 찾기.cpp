#include <iostream>

using namespace std;

dcPower(int x, int n) {  // x의 n승 구하기 
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
int sorted[24]; // 정렬 배열은 반드시 전역 변수로 선언

void merge(int a[], int m, int middle, int n) {
// (정렬할 배열, 시작점, 중간점, 끝점) 
	int i = m;
	int j = middle + 1;
	int k = m;
	// 작은 순서대로 배열에 삽입
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
	// 남은 데이터도 삽입
	if(i > middle) {  // i가 먼저 끝났다면 남은 j를 넣기  
		for(int t=j; t<=n; t++) {
			sorted[k] = a[t];
			k++;
		}
	} else {
		for (int t = i; t<= middle; t++) {  // j가 먼저 끝났다면 남은 i를 넣기 
			sorted[k] = a[t];
			k++;
		}
	}
	// 정렬된 배열을 원본 배열에 복사  
	for(int t=m; t<=n; t++) {
		a[t] = sorted[t];
	}
} 

void mergeSort(int a[], int m, int n) { // (배열, 시작인덱스, 끝인덱스)
	// 배열 크기가 1보다 큰 경우
	if (m<n) {
		int middle = (m+n) / 2;
		// 분할  
		mergeSort(a, m, middle);
		mergeSort(a, middle+1, n);
		// 합병  
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
