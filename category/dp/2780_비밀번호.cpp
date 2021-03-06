/*
문제
비밀번호의 길이는 N이다.
비밀번호는 위 그림에 나온 번호들을 눌러서 만든다.
비밀번호에서 인접한 수는 실제 위 기계의 번호에서도 인접해야 한다.
(ex. 15 라는 비밀번호는 불가능하다. (1과 5는 인접하지 않는다. ) 하지만 1236이라는 비밀번호는 가능하다.)

입력
첫 번째 줄에 Test case의 수 T가 주어진다. 그리고 각각의 케이스마다 입력으로 첫 번째 줄에 비밀번호의 길이 N이 주어진다.( 1 <= N <= 1,000 )

출력
각각의 Test case에 대해서 조건을 만족하는 비밀번호의 개수를 출력하라. 단, 수가 매우 커질 수 있으므로 비밀번호의 개수를 1,234,567으로 나눈 나머지를 출력하라.
*/

/*
solution:
10844번 쉬운 계단수 (https://www.acmicpc.net/problem/10844) 문제의 2차원 버전
D[N][S]: 길이가 n이고 s에서 끝나는 비밀번호의 개수
한 상태에서 갈 수 있는 상태로 가면 된다
*/
#include <iostream>
using namespace std;
#define MOD 1234567

int p[4][3] = {
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9},
	{0, -1, -1}
};
int n, d[1001][10];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < 10; i++)
		d[1][i] = 1;
	for (int i = 1; i < 1000; i++) {
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 3; y++) {
				int now = p[x][y];
				if (now == -1) continue;
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k], ny = y + dy[k];
					if (0 <= nx && nx < 4 && 0 <= ny && ny < 3 && p[nx][ny] != -1) {
						int next = p[nx][ny];
						d[i + 1][next] += d[i][now] % MOD;
						d[i + 1][next] %= MOD;
					}
				}
			}
		}
	}
	while (t--) {
		cin >> n;
		int ans = 0;
		for (int i = 0; i < 10; i++) {
			ans = ans % MOD + d[n][i] % MOD;
			ans %= MOD;
		}
		cout << ans << '\n';
	}
}

