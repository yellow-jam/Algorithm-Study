#include <stdio.h>

// �θ� ��带 ã�� �Լ�
int getParent(int parent[], int x) {
	if(parent[x] == x) return x;  // �θ� �ڱ� �ڽ��̶�� �ڽ� ���� 
	return parent[x] = getParent(parent, parent[x]); // �θ��� �θ� ���ϱ� 
}

// �� �θ� ��带 ��ġ�� �Լ�
int unionParent(int parent[], int a, int b) {
	a = getParent(parent, a); // �ڽ��� �θ� ���� 
	b = getParent(parent, b); // �ڽ��� �θ� ���� 
	if(a<b) parent[b] = a; // �� ���� ������ �θ� ��ħ
	// (b�� �θ�)�� �θ� (a�� �θ�)�� �� 
	else parent[a] = b;
}

// ���� �θ� �������� Ȯ�� (���� �׷����� �����ִ���)
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
	printf("1�� 5�� ����Ǿ� �ֳ���? %d\n", findParent(parent, 1, 5));
	unionParent(parent, 1, 5);
	printf("1�� 5�� ����Ǿ� �ֳ���? %d\n", findParent(parent, 1, 5));
}

