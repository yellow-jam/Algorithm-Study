#include <iostream>

using namespace std;

void hanoi(int n, int start, int mid, int end) {
	// (원판 개수, 시작, 거쳐가는 막대, 끝)
	
	if (n==1) {
		cout << start << ' ' << end << '\n';	
	}
	else {
		hanoi(n-1, start, end, mid); 
		cout << start << ' ' << end << '\n';
		hanoi(n-1, mid, start, end);		
	}
	
}

int main(void) {
	
	int N;
	cin >> N;
	// 총 이동 횟수 공식: 2^n-1 
	cout << (1<<N) - 1 << '\n';
	
	hanoi(N, 1, 2, 3);
	
	return 0;
}
