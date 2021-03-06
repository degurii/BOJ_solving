/*
문제
각 왕국들의 동맹관계와 CTP 왕국의 번호, 한솔 왕국의 번호가 주어질 때 세진이를 도와 CTP 왕국의 힘의 최대값을 구하여라.
각 왕국의 번호는 1부터 N까지의 자연수로 나타내어지며, 서로 다른 두 왕국이 같은 번호를 갖는 경우는 없다.

입력
입력의 첫째 줄에 왕국의 수 N(3 ≤ N ≤ 100,000)과 동맹 관계의 수 M(1 ≤ M ≤ 200,000)이 주어진다.
이 후 M개의 줄에 X,Y가 주어진다. 이는 X 왕국과 Y 왕국이 동맹이라는 뜻이다.
입력의 마지막 줄에 CTP 왕국의 번호 C와 한솔 왕국의 번호 H와 추가 동맹의 기회 K(0 ≤ K ≤ 100)가 공백으로 구분되어 주어진다.
주어지는 입력에서 CTP 왕국과 한솔 왕국은 절대로 동맹이 되지 않게 주어진다.

출력
CTP 왕국의 힘의 최대값을 출력하라.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int n, m;
vector<vector<int>> p;
int ctp, h, k;
bool check[100001];
int dfs(int now) {
	check[now] = true;
	int child = 0;
	for (int next : p[now]) {
		if (!check[next])
			child += dfs(next);
	}
	return child + 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	p.resize(n + 1);
	while (m--) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	cin >> ctp >> h >> k;
	vector<int> g;
	dfs(h);
	int ans = dfs(ctp);
	for (int i = 1; i < n + 1; i++) {
		if (!check[i])
			g.push_back(dfs(i));
	}
	sort(g.begin(), g.end(), greater<int>());
	
	for (int i : g) {
		if (k-- == 0)
			break;
		ans += i;
	}
	cout << ans;
}