#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
//BFS로 탐색할거기 때문에 queue사용//
#define MAX 100
#define INF 1000000000

using namespace std;
int c[MAX][MAX], f[MAX][MAX], d[MAX];
//c배열=용량,f배열=유량 ,d배열은=//
vector<int> a[MAX];
int n = 6, result=0;

void MaximumFlow(int begin, int end) {
	while (1) {
		fill(d, d + MAX, -1);
		queue<int> q;
		q.push(begin);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < a[x].size(); i++) {
				int y = a[x][i];
				if ((c[x][y] - f[x][y]) > 0 && (d[y] == -1)) {
					q.push(y);
					d[y] = x;
					if (y == end) break;
				}
			}
		}
		if (d[end] == -1) break;
		int flow = INF;
		for (int i = end; i != begin; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		for (int i = end; i != begin; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;

		}
		result += flow;
	}
}

int main() {
	a[1].push_back(2);
	a[2].push_back(1);
	c[1][2] = 12;

	a[1].push_back(4);
	a[4].push_back(1);
	c[1][4] = 11;

	a[2].push_back(3);
	a[3].push_back(2);
	c[2][3] = 6;

	a[2].push_back(4);
	a[4].push_back(2);
	c[2][4] = 3;
    
	a[2].push_back(5);
	a[5].push_back(2);
	c[2][5] = 5;

	a[2].push_back(6);
	a[6].push_back(2);
	c[2][6] = 9;

	a[3].push_back(6);
	a[6].push_back(3);
	c[3][6] = 8;

	a[4].push_back(5);
	a[5].push_back(4);
	c[4][5] = 9;

	a[5].push_back(3);
	a[3].push_back(5);
	a[5][3] = 3;

	a[5].push_back(6);
	a[6].push_back(5);
	c[5][6] = 4;

	MaximumFlow(1,6);
	printf("%d", result);
    return 0;
}