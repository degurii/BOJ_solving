/*
문제
상근이네 반에는 총 K명의 학생이 있다. 그 중 일부는 서로를 엄청나게 싫어한다. 서로 싫어하는 친구는 교실 밖에서 절대 마주치지 않는 경로를 이용해 교실로 이동하려고 한다. 이런 경로를 찾아보자.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다.
각 테스트 케이스의 첫째 줄에는 찾아야하는 경로의 수 K와 교차로의 수 N이 주어진다. 교차로는 1번부터 N번까지 번호가 매겨져 있다.
다음 N개 줄에는 각 교차로가 어떤 교차로와 연결되어 있는지 주어지며, 교차로 번호가 증가하는 순서로 주어진다.
모든 교차로는 적어도 한 교차로와 연결되어 있다.
입력의 마지막 줄에는 0 0이 주어진다.

1 ≤ K ≤ 100, 2 ≤ N ≤ 5000이며 모든 학생은 1번 교차로에서 시작하고, 교실은 2번 교차로에 있다.

출력
각 테스트 케이스마다 "Case #:" 형식으로 케이스 번호를 출력한다.
그 다음, K개의 겹치지 않는 경로 (1번에서 출발해 2번으로 도착하는 경로)가 존재하면 K개 줄에 각 경로를 출력한다.
없는 경우에는 "Impossible"을 출력한다.

각 테스트 케이스의 정답을 출력한 다음에는 빈 줄을 하나 출력한다.
*/




/*
solution:
정점을 한 번씩 지나야 하니 정점을 쪼갠다.
간선도 한 번씩 지나야 하므로 용량을 1로 준다.
맥시멈 플로우를 구한 뒤 플로우가 k 이상이라면 경로를 출력하는데,
각 간선에 흐르는 유량을 저장한 뒤 source부터 탐색하며 유량이 흐르는 간선을 따라 답을 출력한다.
*/
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

struct MaxFlow {
	struct Edge {
		int to, cap, flow;
		Edge *rev;
		Edge(int t, int c) :to(t), cap(c), flow(0), rev(NULL) {}
	};
	int n, src, sink;
	vector<vector<Edge*>> p;
	vector<int> level, work;

	MaxFlow(int n, int src, int sink) :n(n), src(src), sink(sink) {
		p.resize(n * 2);
		for (int i = 1; i < n; i++) {
			int u = i * 2, v = i * 2 + 1;
			add_edge(u, v, 1);
		}
	}

	void add_edge(int u, int v, int cap) {
		Edge *ori = new Edge(v, 1);
		Edge *rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = ori;
		p[u].push_back(ori);
		p[v].push_back(rev);
	}

	void split_vertex_add_edge(int u, int v, int cap) {
		int u_in = u * 2, u_out = u * 2 + 1;
		int v_in = v * 2, v_out = v * 2 + 1;
		add_edge(u_out, v_in, cap);
	}

	bool bfs() {
		level = vector<int>(n * 2, -1);
		level[src] = 0;
		queue<int> q;
		q.push(src);

		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (auto e : p[now]) {
				int next = e->to;
				int ncap = e->cap;
				if (level[next] == -1 && ncap > 0) {
					level[next] = level[now] + 1;
					q.push(next);
				}
			}
		}
		return (level[sink] != -1);
	}

	int dfs(int now, int c) {
		if (now == sink) return c;
		for(int &i = work[now];i<p[now].size(); i++){
			auto e = p[now][i];
			int next = e->to;
			int ncap = e->cap;
			if (level[next] == level[now] + 1 && ncap > 0) {
				int f = dfs(next, min(c, ncap));
				if (f) {
					e->cap -= f;
					e->rev->cap += f;
					e->flow += f;
					e->rev->flow -= f;
					return f;
				}
			}
		}
		return 0;
	}
	int flow() {
		int ans = 0;
		while (bfs()) {
			work = vector<int>(n * 2);
			int f = 0;
			while (f = dfs(src, INF))
				ans += f;
		}
		return ans;
	}

	void printPath(int k) {
		while (k--) {
			cout << src / 2<< ' ';
			work = vector<int>(n * 2);
			for (int now = src; now != sink;) {
				for(int &i = work[now]; i<p[now].size(); i++){
					auto e = p[now][i];
					if (e->flow > 0) {
						now = e->to;
						e->flow = 0;
						if (e->to % 2 == 0)
							cout << e->to / 2 << ' ';
						break;
					}
				}
			}
			cout << '\n';
		}
	}
	~MaxFlow() {
		for (auto &i : p) {
			for (auto &e : i) {
				delete e;
			}
		}
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k, n;
	for (int tc = 1; cin >> k >> n, k; tc++) {
		MaxFlow mf(n + 1, 1 * 2 + 1, 2 * 2);
		cin.ignore();

		for (int i = 1; i < n + 1; i++) {
			string s;
			getline(cin, s);
			istringstream iss(s);
			do
			{
				string sub;
				iss >> sub;
				if (sub == "") break;

				int u = stoi(sub);
				mf.split_vertex_add_edge(i, u, 1);
			} while (iss);
		}

		cout << "Case " << tc << ":\n";
		if (mf.flow() >= k) {
			mf.printPath(k);
		}
		else cout << "Impossible\n";
		cout << '\n';
	}
}
*/
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

struct MaxFlow {
	struct Edge {
		int to, cap, flow;
		Edge *rev;
		Edge(int t, int c) :to(t), cap(c), flow(0), rev(NULL) {}
	};
	int n, src, sink;
	vector<vector<Edge*>> p;
	vector<int> level, work;

	MaxFlow(int n, int src, int sink) :n(n), src(src), sink(sink) {
		p.resize(n * 2);
		for (int i = 1; i < n; i++) {
			int u = i * 2, v = i * 2 + 1;
			add_edge(u, v, 1);
		}
	}

	void add_edge(int u, int v, int cap) {
		Edge *ori = new Edge(v, 1);
		Edge *rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = ori;
		p[u].push_back(ori);
		p[v].push_back(rev);
	}

	void split_vertex_add_edge(int u, int v, int cap) {
		int u_in = u * 2, u_out = u * 2 + 1;
		int v_in = v * 2, v_out = v * 2 + 1;
		add_edge(u_out, v_in, cap);
	}

	bool bfs() {
		level = vector<int>(n * 2, -1);
		level[src] = 0;
		queue<int> q;
		q.push(src);

		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (auto e : p[now]) {
				int next = e->to;
				int ncap = e->cap;
				if (level[next] == -1 && ncap > 0) {
					level[next] = level[now] + 1;
					q.push(next);
				}
			}
		}
		return (level[sink] != -1);
	}

	int dfs(int now, int c) {
		if (now == sink) return c;
		for(int &i = work[now];i<p[now].size(); i++){
			auto e = p[now][i];
			int next = e->to;
			int ncap = e->cap;
			if (level[next] == level[now] + 1 && ncap > 0) {
				int f = dfs(next, min(c, ncap));
				if (f) {
					e->cap -= f;
					e->rev->cap += f;
					e->flow += f;
					e->rev->flow -= f;
					return f;
				}
			}
		}
		return 0;
	}
	int flow() {
		int ans = 0;
		while (bfs()) {
			work = vector<int>(n * 2);
			int f = 0;
			while (f = dfs(src, INF))
				ans += f;
		}
		return ans;
	}

	void printPath(int k) {
		while (k--) {
			cout << src / 2<< ' ';
			work = vector<int>(n * 2);
			for (int now = src; now != sink;) {
				for(int &i = work[now]; i<p[now].size(); i++){
					auto e = p[now][i];
					if (e->flow > 0) {
						now = e->to;
						e->flow = 0;
						if (e->to % 2 == 0)
							cout << e->to / 2 << ' ';
						break;
					}
				}
			}
			cout << '\n';
		}
	}
	~MaxFlow() {
		for (auto &i : p) {
			for (auto &e : i) {
				delete e;
			}
		}
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k, n;
	for (int tc = 1; cin >> k >> n, k; tc++) {
		MaxFlow mf(n + 1, 1 * 2 + 1, 2 * 2);
		cin.ignore();

		for (int i = 1; i < n + 1; i++) {
			string s;
			getline(cin, s);
			istringstream iss(s);
			do
			{
				string sub;
				iss >> sub;
				if (sub == "") break;

				int u = stoi(sub);
				mf.split_vertex_add_edge(i, u, 1);
			} while (iss);
		}

		cout << "Case " << tc << ":\n";
		if (mf.flow() >= k) {
			mf.printPath(k);
		}
		else cout << "Impossible\n";
		cout << '\n';
	}
}