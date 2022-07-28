#include <stdio.h>

// 부모 노드를 찾는 함수
int getParent(int parent[], int x) {
	if(parent[x] == x) return x;  // 부모가 자기 자신이라면 자신 리턴 
	return parent[x] = getParent(parent, parent[x]); // 부모의 부모 구하기 
}

// 두 부모 노드를 합치는 함수
int unionParent(int parent[], int a, int b) {
	a = getParent(parent, a); // 자신의 부모를 저장 
	b = getParent(parent, b); // 자신의 부모를 저장 
	if(a<b) parent[b] = a; // 더 작은 쪽으로 부모를 합침
	// (b의 부모)의 부모가 (a의 부모)가 됨 
	else parent[a] = b;
}

// 같은 부모를 가지는지 확인 (같은 그래프에 속해있는지)
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a==b) return 1;
	return 0;
} 

int main(void) {
	int parent[11];
	for (int i=1; i<=10; i++) {
		parent[i] = i;
	}
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));
	unionParent(parent, 1, 5);
	printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));
}

