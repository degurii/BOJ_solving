/*
문제
한 파이프들의 집합을 읽고. 두개의 끝점을 가진 파이프로 만들어놓은 뒤 A부터 Z까지 흐르는 최대 유량을 계산하라.
모든 파이프들은 위의 규칙을 적용시켜 줄일 수 있다.

i번째 파이프는 두개의 다른 노드 ai와 bi와 연결돼 있고 Fi (1 ≤ Fi ≤ 1,000)만큼의 유량을 갖는다.
알파벳은 같지만, 대소문자가 다르면 다른 문자이다. 파이프는 양방향으로 흐를 수 있다.

입력
첫째 줄에 정수 N (1 ≤ N ≤ 700)이 주어진다.
둘째 줄부터 N+1번째 줄까지 파이프의 정보가 주어진다.
첫 번째, 두 번째 위치에 파이프의 이름(알파벳 대문자 또는 소문자)이 주어지고, 세 번째 위치에 파이프의 용량이 주어진다.

출력
첫째 줄에 A에서 Z까지의 최대 유량을 출력한다.
*/


/*
solution:
기본적인 맥시멈플로우 문제.
*/


#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;

struct MaximumFlow {
	struct Edge {
		int to, capacity;
		Edge *rev;
		Edge(int t = 0, int c = 0) :to(t), capacity(c), rev(NULL) {}
	};
	int n, source, sink;
	vector<vector<Edge*>> p;

	MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
		p.resize(n);
	}

	void add_edge(int u, int v, int capacity) {
		Edge *ori = new Edge(v, capacity);
		Edge *rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = ori;
		p[u].push_back(ori);
		p[v].push_back(rev);
	}

	int bfs() {
		vector<bool> check(n);
		queue<int> q;
		vector<pair<int, int>> from(n, { -1, -1 });

		q.push(source);
		check[source] = true;
		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < p[now].size(); i++) {
				int next = p[now][i]->to;
				int ncap = p[now][i]->capacity;
				if (ncap > 0 && !check[next]) {
					q.push(next);
					check[next] = true;
					from[next] = { now, i };
				}
			}
		}
		if (!check[sink])
			return 0;

		int x = sink;
		int c = INF;
		while (from[x].first != -1) {
			c = min(c, p[from[x].first][from[x].second]->capacity);
			x = from[x].first;
		}

		x = sink;
		while (from[x].first != -1) {
			Edge *e = p[from[x].first][from[x].second];
			e->capacity -= c;
			e->rev->capacity += c;
			x = from[x].first;
		}
		return c;
	}
	int flow() {
		int ans = 0;
		while (true) {
			int f = bfs();
			if (f == 0) break;
			ans += f;
		}
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	MaximumFlow mf(52, 0, 25);
	for (int i = 0; i < n; i++) {
		char u, v;
		int cap;
		cin >> u >> v >> cap;
		if ('A' <= u && u <= 'Z') u -= 'A';
		else u = u - 'a' + 26;
		if ('A' <= v && v <= 'Z') v -= 'A';
		else v = v - 'a' + 26;
		
		mf.add_edge(u, v, cap);
		mf.add_edge(v, u, cap);
	}
	cout << mf.flow();
}