/*
입력
첫째 줄에 도시의 개수 n(1≤n≤10,000)이 주어지고 둘째 줄에는 도로의 개수 m(1≤m≤100,000)이 주어진다.
그리고 셋째 줄부터 m+2줄까지 다음과 같은 도로의 정보가 주어진다.
처음에는 도로의 출발 도시의 번호가 주어지고 그 다음에는 도착 도시의 번호, 그리고 마지막에는 이 도로를 지나는데 걸리는 시간이 주어진다.
도로를 지나가는 시간은 10,000보다 작거나 같은 자연수이다.

그리고 m+3째 줄에는 지도를 그리는 사람들이 출발하는 출발 도시와 도착 도시가 주어진다.

출력
첫째 줄에는 이들이 만나는 시간을, 둘째 줄에는 1분도 쉬지 않고 달려야 하는 도로의 수가 몇 개인지 출력하여라.
*/




/*
solution:
일반적인 위상정렬 후에
간선의 방향을 뒤집은 역그래프에서
dist[now] - ncost == dist[next] 라면 가장 오래걸리는 경로이다
이러한 간선의 개수를 세어준다.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
struct Node {
	int to, cost;
	Node(int t, int c) :to(t), cost(c) {}
};
vector<vector<Node> > ori, rev;
int indeg[10001];
int dist[10001];
int numAns;
int st, ed;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	ori.resize(n + 1);
	rev.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		ori[u].push_back(Node(v, c));
		rev[v].push_back(Node(u, c));
		indeg[v]++;
	}
	cin >> st >> ed;
	queue<int> q;
	q.push(st);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto it : ori[now]) {
			int next = it.to;
			int ncost = it.cost;
			if (dist[next] < dist[now] + ncost)
				dist[next] = dist[now] + ncost;
			if (--indeg[next] == 0)
				q.push(next);
		}
	}
	
	vector<bool> check(n + 1);
	q.push(ed);
	check[ed] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto it : rev[now]) {
			int next = it.to;
			int ncost = it.cost;
			if (dist[now] - ncost == dist[next] ){
				if(!check[next])
					q.push(next);
				numAns++;
				check[next] = true;
			}
		}
	}
	cout << dist[ed] << '\n' << numAns;
}