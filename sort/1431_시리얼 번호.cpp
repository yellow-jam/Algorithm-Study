#include <iostream>
#include <algorithm>

using namespace std;
string a[20000];
int n;

int getSum(string a) {
	int length = a.length(), sum=0;
	for (int i=0; i<length; i++) {
		// ������ ��쿡�� ���մϴ�.
		if(a[i] - '0' <= 9&& a[i] - '0' >=0) {
			sum += a[i] - '0';
		} 
	}
	return sum;
}

bool compare(string a, string b){
	// ���̰� ª�� ���� �켱
	if(a.length() < b.length()) {
		return 1;
	} else if(a.length() > b.length()) {
		return 0;
	}
	// ���̰� ���� �����
	else {
		int aSum = getSum(a);
		int bSum = getSum(b);
		// ���ڿ� ���Ե� ������ ���� �ٸ��ٸ� 
		if(aSum != bSum) {
			return aSum < bSum;
		} else {
			return a < b;
		}
	} 
} 

int main(void) {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n, compare);
	for(int i=0; i<n; i++) {
		if(i>0 && a[i] == a[i-1]) {
			continue;
		} else {
			cout << a[i] << '\n';
		}
	}
	return 0;
}
