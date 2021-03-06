/*
solution:
원이 접하거나 서로 포함된다면 그래프에 추가하고
dfs/bfs돌린다

union-find도 가능하다
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Node {
	int x, y, r;
	Node(int x = 0, int y = 0, int r = 0) :x(x), y(y), r(r) {}
}nodes[3001];

bool foo(Node &a, Node &b) {
	if ((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) <= (a.r + b.r)*(a.r + b.r))
		return true;
	else
		return false;
}

void dfs(int now, vector<vector<int> > &p, vector<bool> &check) {
	check[now] = true;
	for (auto &next : p[now]) {
		if (!check[next]) {
			dfs(next, p, check);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		memset(nodes, 0, sizeof(nodes));
		int n;
		cin >> n;
		vector<vector<int> > p(n);
		for (int i = 0; i < n; i++) {
			cin >> nodes[i].x >> nodes[i].y >> nodes[i].r;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if (foo(nodes[i], nodes[j])) {
					p[i].push_back(j);
					p[j].push_back(i);
				}
			}
		}
		vector<bool> check(n);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (!check[i]) {
				dfs(i, p, check);
				ans++;
			}
		}
		cout << ans << '\n';
	}
}

