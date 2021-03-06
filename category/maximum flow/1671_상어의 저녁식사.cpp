/*
문제
어떤 상어는 저녁식사로 서로를 먹는다. 모든 상어는 자신과 다른 상어의 크기, 속도, 지능을 수치로 나타낸 것을 알고 있다.
만약, 상어 A의 크기, 속도, 지능이 상어 B의 크기, 속도, 지능보다 크거나 같다면 상어 A는 상어 B를 먹을 수 있다.
그러나, 상어들의 왕 김재홍은 상어들이 많이 없어지는 것을 방지하기 위해서 한 상어가 최대 두 개의 상어만 먹을 수 있게 했다.
상어들은 김재홍의 말을 모두 듣는다.

N마리 상어의 크기, 속도, 지능이 주어졌을 때, 살아남을 수 있는 상어의 최소값을 구하시오.

입력
첫째 줄에 상어의 마리 수 N이 주어진다. 이 값은 50보다 작거나 같은 자연수이다.
둘째 줄부터 각 상어의 크기, 속도, 지능의 정보가 주어진다. 이 값은 2,000,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 살아남을 수 있는 상어의 최소값을 출력한다.
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
struct shark {
	int a, b, c;
	shark(int a = 0, int b = 0, int c = 0) :a(a), b(b), c(c) {}
};
vector<vector<int>> p;
vector<shark> sharks;
bool check[51];
int match[51];
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

	cin >> n;
	sharks.resize(n + 1);
	p.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> sharks[i].a >> sharks[i].b >> sharks[i].c;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)continue;
			if (sharks[i].a == sharks[j].a && sharks[i].b == sharks[j].b && sharks[i].c == sharks[j].c) {
				if (i < j)
					p[i].push_back(j);
			}
			else if (sharks[i].a >= sharks[j].a && sharks[i].b >= sharks[j].b && sharks[i].c >= sharks[j].c) {
				p[i].push_back(j);
			}
		}
	}
	int ans = n;
	int cnt = 0;
	memset(match, -1, sizeof(match));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			memset(check, 0, sizeof(check));
			cnt += dfs(i);
		}
	}
	cout << ans - cnt;
}