/*
문제
위 조건을 지키면서 절약할 수 있는 최대 액수를 구하시오.

입력
입력은 여러 개의 테스트 케이스로 구분되어 있다.
각 테스트 케이스의 첫째 줄에는 집의 수 m과 길의 수 n이 주어진다. (1 ≤ m ≤ 200000, m-1 ≤ n ≤ 200000)
이어서 n개의 줄에 각 길에 대한 정보 x, y, z가 주어지는데,
이는 x번 집과 y번 집 사이에 양방향 도로가 있으며 그 거리가 z미터라는 뜻이다. (0 ≤ x, y < m, x ≠ y)
도시는 항상 연결 그래프의 형태이고(즉, 어떤 두 집을 골라도 서로 왕래할 수 있는 경로가 있다), 도시상의 모든 길의 거리 합은 231미터보다 작다.
입력의 끝에서는 첫 줄에 0이 2개 주어진다.

출력
각 테스트 케이스마다 한 줄에 걸쳐 절약할 수 있는 최대 비용을 출력한다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int par[200001];
struct Edge {
	int to, from, cost;
	Edge(int t = 0, int f = 0, int c = 0) :to(t), from(f), cost(c) {}
	bool operator < (const Edge &o) const{
		return (cost > o.cost);
	}
};

int find(int x) {
	if (par[x] == x)
		return x;
	return par[x] = find(par[x]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> m, n != 0) {
		for (int i = 0; i < n; i++)
			par[i] = i;
		priority_queue<Edge> q;
		int x, y, z;
		int ans = 0;
		for (int i = 0; i < m; i++) {
			cin >> x >> y >> z;
			q.push(Edge(x, y, z));
			ans += z;
		}
		while (!q.empty()) {
			auto e = q.top();
			q.pop();
			int u = e.from, v = e.to, c = e.cost;
			u = find(u);
			v = find(v);
			if (u != v) {
				ans -= c;
				par[v] = u;
			}
		}
		cout << ans << '\n';
	}
}
