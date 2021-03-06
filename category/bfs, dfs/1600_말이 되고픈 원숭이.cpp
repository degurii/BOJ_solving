/*
격자판이 주어졌을 때, 원숭이가 최소한의 동작으로 시작지점에서 도착지점까지 갈 수 있는 방법을 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 K가 주어진다.
둘째 줄에 격자판의 가로길이 W, 세로길이 H가 주어진다.
그 다음 H줄에 걸쳐 W개의 숫자가 주어지는데, 0은 아무것도 없는 평지, 1은 장애물을 뜻한다.
장애물이 있는 곳으로는 움직일 수 없다. 시작점과 도착점은 항상 평지이다. W와 H는 1이상 200이하의 자연수이고, K는 0이상 30이하의 정수이다.

출력
첫째 줄에 원숭이의 동작수의 최소값을 출력한다. 시작점에서 도착점까지 갈 수 없는 경우엔 -1을 출력한다.
*/
/*
solution:
k번 뛸 수 있으므로
뛰는 횟수를 1, 2, ..., k번 사용했을때 각각을 모두 저장한다.
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int p[201][201], dist[201][201][40];
bool check[201][201][40];
int dx1[] = { 1, 2, 2, 1, -1, -2, -2, -1 }, dy1[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dx2[] = { 0, 1, 0, -1 }, dy2[] = { 1, 0, -1, 0 };
int k, w, h;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> k >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> p[i][j];
		}
	}
	memset(dist, -1, sizeof(dist));
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0, 0}, 0 });
	dist[0][0][0] = 0;
	check[0][0][0] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int l = q.front().second;
		q.pop();
		if (x == h - 1 && y == w - 1) {
			break;
		}
		if (l < k) {
			for (int i = 0; i < 8; i++) {
				int nx = x + dx1[i];
				int ny = y + dy1[i];
				if (0 <= nx && nx < h && 0 <= ny && ny < w) {
					if (!check[nx][ny][l + 1] && p[nx][ny] != 1) {
						check[nx][ny][l + 1] = true;
						dist[nx][ny][l + 1] = dist[x][y][l] + 1;
						q.push({ {nx, ny}, l + 1 });
					}
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx2[i];
			int ny = y + dy2[i];
			if (0 <= nx && nx < h && 0 <= ny && ny < w) {
				if (!check[nx][ny][l] && p[nx][ny] != 1) {
					check[nx][ny][l] = true;
					dist[nx][ny][l] = dist[x][y][l] + 1;
					q.push({ {nx, ny}, l });
				}
			}
		}
	}
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < k + 1; i++) {
		int d = dist[h - 1][w - 1][i];
		if (d != -1) {
			ans = ans < d ? ans : d;
		}
	}
	if (ans == 0x3f3f3f3f) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	
}