#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;  // 노드 전체 개수: 7개 
int c[7];  // 방문 처리를 위한 배열 (checked)
vector<int> a[8];  // 모든 요소가 벡터<int>로 이루어진 8칸짜리 배열
// 각 노드의 인덱스가 1~7이라서 8개 
// vector<vector<int>> a(8); 이랑  똑같은 방 개수를 갖는 것... 

void bfs(int start) {
	queue<int> q;
	q.push(start); // 시작점 넣기 
	c[start] = true;  // start번째 지점에 대해서 방문 처리 
	while(!q.empty()) {  // 큐가 빌 때까지 
		int x = q.front();  // x = 맨 앞의 것 
		q.pop();  // 맨 앞의 것을 꺼냄
		printf("%d ", x); 
		
		for(int i=0; i<a[x].size(); i++) {
		// 현재 큐에서 꺼낸 것과 인접한 노드들을 하나씩 방문 
			int y = a[x][i]; 
			if (!c[y]) { // 인접한 노드를 방문한 상태가 아니라면
				q.push(y);  // 큐에 담아주기 
				c[y]= true;  // 방문 처리 
			}
		}
	}
}

int main(void) {
	a[1].push_back(2);
	a[2].push_back(1);
	
	a[1].push_back(3);
	a[3].push_back(1);
	
	a[2].push_back(4);
	a[4].push_back(2);
	
	a[2].push_back(5);
	a[5].push_back(2);
	
	a[3].push_back(6);
	a[6].push_back(3);
	
	a[3].push_back(7);
	a[7].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);
	
	a[6].push_back(7);
	a[7].push_back(6);
	
	bfs(1);
	
	return 0;
}
