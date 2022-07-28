// https://algosu.tistory.com/86
// 해설을 찾아본 이유: 재귀함수에 들어가야 할 미지수를 계산할 법을 모르겠어서

#include <iostream>
#include <string.h>

using namespace std; 

int N;
int map[2200][2200];
int answer[3];  // [0]: -1 종이 개수, [1]: 0 종이 개수, [2]: 1 종이 개수

// 모두 같은 숫자인지 판단
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
	// x는 세로축 시작점, y는 가로축 시작점, n은 종이의 길이 
	
	// 종이가 모두 같은 숫자일 경우 -> 해당 종이 갯수 +1, 종료
	if (allSameNumber(x, y, n)) {
		int paperNum = map[x][y];
		answer[paperNum+1]++;
		return;
	} 
	
	int div = n/3;  // div = 자른 후 종이 길이 
	
	// 9개로 나눠서 분할 정복
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			makePaper(x + div * i, y + div * j, div);  // 포인트 
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
	/* 초기화 */
	N = 0;
	memset(map, 0, sizeof(map));
	// map을 (map의 크기)만큼 0으로 초기화 
	memset(answer, 0, sizeof(answer)); 
	// answer를 (answer의 크기)만큼 0으로 초기화 
	
	/* 입력 */
	cin >> N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> map[i][j];
		}
	}
	
	/* 해법 */
	// 9개로 나누어서 분할 정복
	makePaper(0, 0, N);
	
	// 출력
	for (int i=0; i<3; i++) {
		cout << answer[i] << endl;
	} 
		
	return 0;
}


