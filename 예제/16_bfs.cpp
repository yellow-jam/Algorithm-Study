#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;  // ��� ��ü ����: 7�� 
int c[7];  // �湮 ó���� ���� �迭 (checked)
vector<int> a[8];  // ��� ��Ұ� ����<int>�� �̷���� 8ĭ¥�� �迭
// �� ����� �ε����� 1~7�̶� 8�� 
// vector<vector<int>> a(8); �̶�  �Ȱ��� �� ������ ���� ��... 

void bfs(int start) {
	queue<int> q;
	q.push(start); // ������ �ֱ� 
	c[start] = true;  // start��° ������ ���ؼ� �湮 ó�� 
	while(!q.empty()) {  // ť�� �� ������ 
		int x = q.front();  // x = �� ���� �� 
		q.pop();  // �� ���� ���� ����
		printf("%d ", x); 
		
		for(int i=0; i<a[x].size(); i++) {
		// ���� ť���� ���� �Ͱ� ������ ������ �ϳ��� �湮 
			int y = a[x][i]; 
			if (!c[y]) { // ������ ��带 �湮�� ���°� �ƴ϶��
				q.push(y);  // ť�� ����ֱ� 
				c[y]= true;  // �湮 ó�� 
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
