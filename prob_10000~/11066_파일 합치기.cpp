/*
소설의 각 장들이 수록되어 있는 파일의 크기가 주어졌을 때, 이 파일들을 하나의 파일로 합칠 때 필요한 최소비용을 계산하는 프로그램을 작성하시오.

입력
프로그램은 표준 입력에서 입력 데이터를 받는다. 프로그램의 입력은 T개의 테스트 데이터로 이루어져 있는데, T는 입력의 맨 첫 줄에 주어진다.
각 테스트 데이터는 두 개의 행으로 주어지는데, 첫 행에는 소설을 구성하는 장의 수를 나타내는 양의 정수 K (3 ≤ K ≤ 500)가 주어진다.
두 번째 행에는 1장부터 K장까지 수록한 파일의 크기를 나타내는 양의 정수 K개가 주어진다. 파일의 크기는 10,000을 초과하지 않는다.

출력
프로그램은 표준 출력에 출력한다. 각 테스트 데이터마다 정확히 한 행에 출력하는데, 모든 장을 합치는데 필요한 최소비용을 출력한다.
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

int n, p[501], d[501][501], cost[501];
int foo(int i, int j) {
	if (j - i == 0) return 0;
	if (d[i][j] != INF)
		return d[i][j];
	for (int k = i; k + 1 <= j; k++) {
		d[i][j] = min(d[i][j], foo(i, k) + foo(k + 1, j) + cost[j] - cost[i - 1]);
	}
	return d[i][j];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		memset(cost, 0, sizeof(cost));
		cin >> n;
		for (int i = 0; i < n + 1; i++)
			for (int j = 0; j < n + 1; j++)
				d[i][j] = INF;

		for (int i = 1; i < n + 1; i++) {
			cin >> p[i];
			cost[i] = cost[i - 1] + p[i];
		}

		cout << foo(1, n) << '\n';
	}
}