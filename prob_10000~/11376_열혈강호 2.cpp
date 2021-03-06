/*
문제
강호네 회사에는 직원이 N명이 있고, 해야할 일이 M개가 있다. 직원은 1번부터 N번까지 번호가 매겨져 있고, 일은 1번부터 M번까지 번호가 매겨져 있다.
각 직원은 최대 두 개의 일을 할 수 있고, 각각의 일을 담당하는 사람은 1명이어야 한다.
각각의 직원이 할 수 있는 일의 목록이 주어졌을 때, M개의 일 중에서 최대 몇 개를 할 수 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 직원의 수 N과 일의 개수 M이 주어진다. (1 ≤ N, M ≤ 1,000)
둘째 줄부터 N개의 줄의 i번째 줄에는 i번 직원이 할 수 있는 일의 개수와 할 수 있는 일의 번호가 주어진다.

출력
첫째 줄에 강호네 회사에서 할 수 있는 일의 개수를 출력한다.
*/


/*
solution:
11375번 열혈강호 문제와 똑같은데, 직원이 할 수 있는 일의 수가 2개이다.
source에서 사람과 연결된 간선의 용량을 2로 생각해서 dfs를 한 정점당 두번씩 돌리면 된다.
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
bool check[1001];
int match[1001];
vector<vector<int>> p;
int dfs(int now) {
	if (now == -1) return 1;
	for (int next : p[now]) {
		if (check[next])continue;
		check[next] = true;
		if (dfs(match[next])) {
			match[next] = now;
			return 1;
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	p.resize(n + 1);
	for (int i = 1; i < n + 1; i++) {
		int x;
		cin >> x;
		while (x--) {
			int j;
			cin >> j;
			p[i].push_back(j);
		}
	}
	memset(match, -1, sizeof(match));
	int ans = 0;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < 2; j++) {
			memset(check, false, sizeof(check));
			ans += dfs(i);
		}
	}
	cout << ans;
}