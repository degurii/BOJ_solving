/*
문제
조건을 만족하면서 각 도로에 어떤 레스토랑 체인점을 세워야 하는지를 결정하는 프로그램을 작성하시오.

입력
첫째 줄에 도시의 수 N과 도로의 수 E가 주어진다. (1 ≤ N, E ≤ 100,000)

다음 E개 줄에는 도로의 정보 Ai와 Bi가 주어진다. 도시 Ai와 Bi를 연결하는 도로라는 뜻이며, Ai와 Bi는 같지 않다.
또, 두 도시를 연결하는 도로가 둘 이상인 경우는 없다.

출력
출력은 총 E줄을 해야 한다. i번째 줄에는 읿력으로 주어진 i번째 도로에 1번 레스토랑을 놓을 것이면 1을, 2번을 놓을 것이면 2를 출력한다.
만약, 문제의 조건을 만족시키게 레스토랑을 배치할 수 없다면 0을 출력한다.
*/


/*
solution:
어떤 정점 x(코드상에선 n+1 정점)을 추가하여, 차수가 홀수인 정점에 연결하면
x를 포함한 모든 정점의 차수가 짝수가 된다.(홀수 차수 정점은 항상 짝수개 있으므로)
그럼 이 그래프에서 오일러 회로를 그릴 수 있고, 정점으로 들어오는 간선과 정점에서 나가는 간선이 적어도 하나만 있으므로
오일러 회로가 그려지는 간선 순서대로 1, 2 를 반복하여 붙이면 답을 구할 수 있다.

단, x에서 시작해 회로를 그려야 한다. x가 아닌 임의의 정점 v에서 시작한다면
경로가 v -> ... -> x -> v 인 경우 x - v 간선을 제외한 나머지 간선에 모두 같은 숫자가 붙는 경우가 있다.
이때 x는 가상의 정점이고, x-v는 가상의 간선이므로 v에 연결된 간선이 모두 같은 숫자를 가지게 되므로 x에서 출발해야한다.

이를 컴포넌트마다 반복하여 구현하면 된다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n, e;
bool check[100001];
struct Edge {
	int to, road;
	Edge *rev;
	Edge(int t, int r, Edge *rev = NULL) :to(t), road(r), rev(rev) {}
};
vector<vector<int> >group;
vector<vector<Edge*> > p;
vector<pair<int, int> > order;
map<pair<int, int>, int> ans;

void dfs(int now, vector<int> &g) {
	check[now] = true;
	g.push_back(now);
	for (auto e : p[now]) {
		int next = e->to;
		if (!check[next])
			dfs(next, g);
	}
}

void euler(int now, vector<int> &circuit) {
	Edge *e = NULL;
	while (!(p[now].empty())) {
		e = p[now].back();
		if (e->road == false) {
			p[now].pop_back();
		}
		else {
			p[now].pop_back();
			e->rev->road = false;
			euler(e->to, circuit);
		}
	}
	circuit.push_back(now);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> e;
	p.resize(n + 2);
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		Edge *e1 = new Edge(v, true), *e2 = new Edge(u, true);
		e1->rev = e2;
		e2->rev = e1;
		order.push_back({ u, v });
		p[u].push_back(e1);
		p[v].push_back(e2);
	}

	for (int i = 1, g = -1; i < n + 1; i++) {
		if (!check[i]) {
			vector<int> tmp;
			dfs(i, tmp);
			if (tmp.size() > 1)
				group.push_back(tmp);
		}
	}

	for (auto g : group) {
		int maxi = -1, mini = 0x3f3f3f3f;
		vector<int> cir;
		for (auto now : g) {
			maxi = max(maxi, (int)p[now].size());
			mini = min(mini, (int)p[now].size());
		}
		if (maxi <= 2 ) {
			if (mini == 2) {
				if (g.size() % 2 != 0) {
					cout << 0;
					return 0;
				}
				else {
					euler(g[0], cir);
				}
			}
			else if (mini == 1) {
				for (auto now : g) {
					if (p[now].size() == 1) {
						euler(now, cir);
						break;
					}
				}
				
			}
		}
		else {
			int start = n + 1;
			bool c = true;
			for (auto now : g) {
				if (p[now].size() % 2 != 0) {
					Edge *e1 = new Edge(n + 1, true), *e2 = new Edge(now, true);
					e1->rev = e2;
					e2->rev = e1;
					p[now].push_back(e1);
					p[n + 1].push_back(e2);
					c = false;
				}
			}
			if (c) start = g[0];
			euler(start, cir);
		}
		int s = cir.size();
		for (int i = 0, c = 1; i < s - 1; i++) {
			ans[{cir[i], cir[i + 1]}] = c;
			ans[{cir[i + 1], cir[i]}] = c;
			if (c == 1) c = 2;
			else c = 1;
		}
	}

	for (auto it : order) {
		cout << ans[{it.first, it.second}] << '\n';
	}
}