/*
문제
어느날 모든 학생들은 한명이 한개의 노트북을 가지고 공부하던 도중, 자리를 바꾸다가 그만 노트북이 뒤섞이고 말았다.
대다수의 학생들은 자신의 노트북을 잘 알고 있어서 자신의 노트북을 받을 수 있었지만, 애석하게도 N명의 학생들이 정확히 자신의 노트북이 어떤것인지 알지 못했다.
왜냐하면 그들은 노트북을 구입한게 바로 어제였기 때문이다.

어짜피 새것인 노트북, 바뀐들 어떠하랴.
그들에게 자신의 노트북이라고 생각되는 노트북들을 얘기해 보라고 했다.
이번에는 정말 신기하게도 그들 각각이 노트북을 여러개 선택한 것이었다! “이것 아니면 이것 아니면 이것 아니면 이것 일거 같아요”라카더라.
우리의 목적은 이들의 요구를 가장 많이 만족시키는 것이다.
요컨데, 자신이 자신의 것 같다라고 얘기한 노트북을 갖는 사람을 최대화 하라는 소리다.

입력
첫째 줄에는 노트북이 섞인 날 어제 노트북을 구입한 사람의 수 N(1 ≤ N ≤ 100)과 노트북 예상의 개수 M(0 ≤ M ≤ 5,000) 주어진다.
둘쨋줄에서 M+1번째 줄 까지는 각각 한 줄마다 a b가 주어지는데, 이는 a번 사람이 b번 노트북을 자신의 것 이라고 생각한다는 의미를 갖는다.
노트북과 사람의 번호는 1보다 크거나 같고, N보다 작거나 같다. 두 사람 또는 두 노트북이 같은 번호를 갖는 경우는 없다.

출력
최대로 만족될 수 있는 사람 수를 출력한다.
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
vector<vector<int>> p;
bool check[5001];
int match[5001];
int dfs(int now) {
	if (now == -1) return 1;
	for (int next : p[now]) {
		if (check[next]) continue;
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
	for (int i = 1; i < m + 1; i++) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
	}
	memset(match, -1, sizeof(match));
	int ans = 0;
	for (int i = 1; i < n + 1; i++) {
		memset(check, 0, sizeof(check));
		ans += dfs(i);
	}
	cout << ans;
}