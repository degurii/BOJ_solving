/*
문제
구사과의 위치가 (i, j)인 경우에
E가 쓰여져 있는 칸에 서 있었다면 (i, j+1)로,
S의 경우에는 (i+1, j)로,
B의 경우에는 (i, j+1) 또는 (i+1, j)로 순간이동한다
구사과가 선물을 가져가는 경로의 수를 구하는 프로그램을 작성하시오. 선물이 놓여진 칸에 구사과가 이동하면, 구사과는 항상 선물을 가져간다.

입력
첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (1 <= N, M <= 3,000, 1 < N×M <= 9,000,000)
둘째 줄부터 N개의 줄에는 구사과가 있는 곳의 지도가 주어진다. (N, M)에는 도착지임을 뜻하는 X가 주어진다.
지도에 쓰여 있는 대로 이동했을 때, 지도를 벗어나는 경우는 없다.

출력
첫째 줄에 구사과가 선물을 가져가는 경로의 수를 출력한다. 경로가 너무 많아질 수 있으므로 1,000,000,009 (109 + 9)로 나눈 나머지를 출력한다.
*/
#include <iostream>
#include <string>
using namespace std;
const int MOD = 1000000009;

int n, m, d[3001][3001];
string p[3001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	d[n - 1][m - 1] = 1;
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			ans += d[i][j] % MOD;
			ans %= MOD;
			if (i - 1 >= 0 && (p[i - 1][j] == 'S' || p[i-1][j] == 'B')) {
				d[i - 1][j] += d[i][j] %MOD;
				d[i - 1][j] %= MOD;
			}
			if (j - 1 >= 0 && (p[i][j - 1] == 'E' || p[i][j - 1] == 'B')) {
				d[i][j - 1] += d[i][j]%MOD;
				d[i][j - 1] %= MOD;
			}
		}
	}
	cout << ans;
}