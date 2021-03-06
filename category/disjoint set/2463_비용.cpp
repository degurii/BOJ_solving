/*
문제
간선(혹은 에지)에 가중치가 주어진 그래프가 있다. 정점들의 수가 N일 때, 모든 정점은 1부터 N까지 번호가 붙여져 있고, 모든 간선들의 가중치는 서로 다르다. 이때 서로 다른 두 정점 u,v에 대하여, Cost(u,v)는 다음에서 제거되는 간선들의 가중치 합이다: u와 v사이의 경로가 있으면 이 그래프의 최소 가중치 간선을 그래프에서 제거한다. 이 과정을 u와 v사이의 경로가 없을 때까지 반복한다.

예를 들어, 6개의 정점으로 이루어진 다음 그래프를 고려해 보자.

두 정점 2, 6에 대하여, Cost(2,6)을 구하는 과정에서 제거되는 간선들을 차례대로 나열하면 다음과 같다: (2, 3), (4, 5), (3, 5), (3, 4), (2, 6).
이들 간선들 중 (2, 6)이 제거될 때, 두 정점 2와 6사이의 경로가 없으므로 간선 제거가 끝나게 된다. 따라서  Cost(2,6) = 2 + 3 + 4 + 5 + 6 = 20이다.
간선에 가중치가 있는 그래프가 주어질 때, u<v인 모든 두 정점 u,v에 대한 Cost(u,v)들의 총 합을 구하는 프로그램을 작성하시오. 총 합이 10^9보다 크거나 같으면 이를 10^9으로 나눈 나머지를 출력한다.



입력
첫 번째 줄에 정점의 수 N (1<=N<=100,000)과 간선의 수 M (1<=M<=100,000)이 빈칸을 사이에 두고 주어진다.
다음 M개의 각 줄에 간선 하나에 대한 정보를 나타내는 세 개의 양의 정수 x,y,w가 빈칸을 사이에 두고 주어진다.
이는 간선 (x,y)의 가중치가w 임을 의미한다. 1<=w<=100,000이다.

출력
u<v인 모든 두 정점 에 대한 Cost(u,v)들의 총 합을 첫째 줄에 출력한다.
단, 총 합이 10^9보다 크거나 같으면 이를 10^9으로 나눈 나머지를 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000000
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

int n, m;
int par[100001];
ll s[100001], sum;

struct Edge {
	int u, v, c;
	Edge(int u, int v, int c) :u(u), v(v), c(c) {}
};
int find(int x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}

void merge(int u, int v) {
	par[v] = u;
	s[u] += s[v];
	s[v] = 1;
}
void init() {
	for (int i = 0; i < n + 1; i++) {
		par[i] = i;
		s[i] = 1;
	}
}
vector<Edge> edges;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	init();
	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);
		sum += w;
	}
	sort(all(edges), [&](const Edge &a, const Edge &b) {
		return a.c > b.c;
	});
	ll ans = 0;
	for (auto e : edges) {
		int u = find(e.u);
		int v = find(e.v);
		int c = e.c;
		if (u != v) {
			ans += (((s[u] * s[v]) % MOD)*sum) % MOD;
			ans %= MOD;
			merge(u, v);
		}
		sum -= c;
	}
	cout << ans;
}
