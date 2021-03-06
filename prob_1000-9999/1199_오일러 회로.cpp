/*
문제는 그래프가 주어졌을 때 오일러 회로 경로를 출력하는 것이다

입력
첫 줄에는 정점의 수 N(1 ≤ N ≤ 1,000)이 주어진다.
그리고 다음 N개의 줄에 대해 인접행렬의 정보가 주어진다. i+1번째 줄에는 i번 정점에 대한 인접행렬이 주어진다.
두 정점 사이에 간선이 여러 개 있을 수 있다. 인접행렬의 값은 두 정점 사이의 간선 개수를 의미하며, 0보다 크거나 같고, 10보다 작거나 같은 정수이다.
입력으로 주어지는 그래프에는 루프 (양 끝점이 같은 간선)는 없다. 또, 입력으로 주어지는 그래프는 모두 연결되어 있다.

출력
첫 줄에 방문하는 점 순서를 공백으로 구분하여 출력한다. 단, 시작점은 어느 위치에서든 상관없고 아무 경로만 하나 찍으면 된다. 불가능한 경우에는 -1을 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, p[1001][1001];
void dfs(int now, vector<int> &ans) {
	for (int next = 1; next < n + 1; next++) {
		if (p[now][next] > 0) {
			p[now][next]--;
			p[next][now]--;
			dfs(next, ans);
		}
	}
	ans.push_back(now);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> p[i][j];
		}
	}
	for (int i = 1; i < n + 1; i++) {
		int cnt = 0;
		for (int j = 1; j < n + 1; j++) {
			cnt += p[i][j];
		}
		if (cnt % 2 != 0) {
			cout << -1;
			return 0;
		}
	}
	vector<int> ans;
	for(int i=1; i<n+1; i++){
		for (int j = 1; j < n + 1; j++) {
			if (p[i][j] > 0) {
				dfs(j, ans);
				reverse(ans.begin(), ans.end());
				for (auto i : ans) cout << i << ' ';
				return 0;
			}
		}
	}
}
