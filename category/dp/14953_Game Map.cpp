/*
입력
Your program is to read from standard input.
The input starts with a line containing two integers, n and m (1 ≤ n ≤ 100,000, n-1 ≤ m ≤ 300,000),
where n is the number of cities on the game map and m is the number of roads. All cities are numbered from 0 to n-1.
In the following m lines, each line contains two integers i and j (0 ≤ i ≠ j ≤ n-1) which represent a road connecting two cities i and j.

출력
Your program is to write to standard output. Print exactly one line.
The line should contain the maximum number of cities which Chansu can conquer.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int> > p;
int degree[100001], d[100001];
vector<pair<int, int> > t;	//degree, node 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	p.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
		degree[u]++;
		degree[v]++;
	}
	for (int i = 0; i < n; i++) {
		t.push_back({ degree[i],i });
	}
	sort(t.begin(), t.end());
	int ans = 0;
	for (auto it : t) {
		int now = it.second;
		if (d[now] == 0)
			d[now] = 1;
		for (int next : p[now]) {
			if (degree[next] > degree[now] && d[next] < d[now] + 1)
				d[next] = d[now] + 1;
		}
	}
	for (int i = 0; i < n; i++)
		ans = max(ans, d[i]);
	cout << ans;
}