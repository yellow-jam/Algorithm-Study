// https://algosu.tistory.com/86
// �ؼ��� ã�ƺ� ����: ����Լ��� ���� �� �������� ����� ���� �𸣰ھ

#include <iostream>
#include <string.h>

using namespace std; 

int N;
int map[2200][2200];
int answer[3];  // [0]: -1 ���� ����, [1]: 0 ���� ����, [2]: 1 ���� ����

// ��� ���� �������� �Ǵ�
bool allSameNumber(int x, int y, int n) {
	
	int check = map[x][y];
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if(map[x+i][y+j] != check) {
				return false;
			}
		}
	}
	return true;
} 

void makePaper(int x, int y, int n) {
	// x�� ������ ������, y�� ������ ������, n�� ������ ���� 
	
	// ���̰� ��� ���� ������ ��� -> �ش� ���� ���� +1, ����
	if (allSameNumber(x, y, n)) {
		int paperNum = map[x][y];
		answer[paperNum+1]++;
		return;
	} 
	
	int div = n/3;  // div = �ڸ� �� ���� ���� 
	
	// 9���� ������ ���� ����
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			makePaper(x + div * i, y + div * j, div);  // ����Ʈ 
		}
	} 
} 

// 0, 0, 3
// 0, 3, 3
// 0, 6, 3
// 3, 0, 3
// 3, 3, 3
// 3, 6, 3

// 6, 0, 3
	//div = 1
	// 6, 0, 1
	// 6, 1, 1
	// 6, 2, 1
	// 7, 0, 1
	// 7, 1, 1
	// 7, 2, 1
	// 8, 0, 1
	// 8, 1, 1
	// 8, 2, 1
// 6, 3, 3
	// ...
// 6, 6, 3
	// ...

int main() {
	/* �ʱ�ȭ */
	N = 0;
	memset(map, 0, sizeof(map));
	// map�� (map�� ũ��)��ŭ 0���� �ʱ�ȭ 
	memset(answer, 0, sizeof(answer)); 
	// answer�� (answer�� ũ��)��ŭ 0���� �ʱ�ȭ 
	
	/* �Է� */
	cin >> N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> map[i][j];
		}
	}
	
	/* �ع� */
	// 9���� ����� ���� ����
	makePaper(0, 0, N);
	
	// ���
	for (int i=0; i<3; i++) {
		cout << answer[i] << endl;
	} 
		
	return 0;
}


