/*
문제
지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다)  이동한다.
불은 각 지점에서 네 방향으로 확산된다.
지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.
지훈이와 불은 벽이 있는 공간은 통과하지 못한다.

입력
입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다. 단, 1<= R,C <= 1000
다음 입력으로 R줄동안 각각의 미로 행이 주어진다.
각각의 문자들은 다음을 뜻한다.

#: 벽
.: 지나갈 수 있는 공간
J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
F: 불이난 공간
J는 입력에서 하나만 주어진다.

출력
지훈이가 불이 도달하기 전에 미로를 탈출 할 수 없는경우 IMPOSSIBLE 을 출력한다.
지훈이가 미로를 탈출할 수 있는경우에는 가장 빠른 탈출시간을 출력한다.
*/



/*
solution:
사람-불 순서대로 큐에 넣는다
단, 사람이 갔는데 불이 올 자리라면 갈 수 없는 자리이므로
continue로 반복문을 넘긴다
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FST first
#define SND second

int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
int r, c, p[1001][1001], dist[1001][1001];
bool check[1001][1001];
vector<pair<int, int> > f;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	queue<pair<pair<int, int>, bool> > q;
	cin >> r >> c;
	for (int i = 1; i < r + 1; i++) {
		for (int j = 1; j < c + 1; j++) {
			char x;
			cin >> x;
			if (x == '#')
				p[i][j] = -1;
			else if (x == 'J') {
				check[i][j] = true;
				q.push({ {i, j}, false });
			}
			else if(x == 'F') {
				f.push_back({ i, j });
			}
		}
	}
	for (auto &it : f) {
		q.push({ {it.FST, it.SND}, true });
		p[it.FST][it.SND] = -1;
	}
	int ans = 0;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		
		bool fire = now.SND;
		int x = now.FST.FST;
		int y = now.FST.SND;
		if (!fire && p[x][y] == -1) continue;
		if (!fire && (x == 1 || x == r || y == 1 || y == c)) {
			ans = dist[x][y] + 1;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 < nx && nx < r + 1 && 0 < ny && ny < c + 1) {
				if (fire) {
					if (p[nx][ny] == 0) {
						p[nx][ny] = -1;
						q.push({ { nx, ny }, fire });
					}

				}
				else {
					if (p[nx][ny] == 0 && !check[nx][ny]) {
						check[nx][ny] = true;
						q.push({ {nx, ny}, fire });
						dist[nx][ny] = dist[x][y] + 1;
					}
				}
			}
		}
	}
	if (ans)
		cout << ans;
	else
		cout << "IMPOSSIBLE";
}




