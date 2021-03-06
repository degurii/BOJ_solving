/*
문제
문제는 통나무를 5개의 기본동작(U, D, L, R, T)만을 사용하여 처음위치(BBB)에서 최종위치(EEE)로 옮기는 프로그램을 작성하는 것이다.
단, 최소 횟수의 단위 동작을 사용해야 한다.

입력
첫째 줄에 주어진 평지의 한 변의 길이 N이 주어진다. (4<=N<=50) 주어진다.
이어서 그 지형의 정보가 0, 1, B, E로 이루어진 문자열로 주어진다.
한 줄에 입력되는 문자열의 길이는 N이며 입력 문자 사이에는 빈칸이 없다. 통나무와 최종 위치의 개수는 1개이다.

출력
첫째 줄에 최소 동작 횟수를 출력한다. 이동이 불가능하면 0만을 출력한다.
*/


/*
코드가 왜케 길어
*/
#include <iostream>
#include <queue>
using namespace std;
#define FS first
#define SD second

int n, p[51][51], dist[51][51][2], check[51][51][2]; //check(i, j, dir)dir 0은 아래쪽, 1은 오른쪽
int dx[] = { 0, 1, 0 ,-1 }, dy[] = { 1, 0, -1, 0 };
struct Node {
	int x, y;
	Node(int x = 0, int y = 0) :x(x), y(y) {}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	queue<pair<Node, int> > q;
	bool o = false;
	int sx = -1, sy = -1;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			char x;
			cin >> x;
			if (x == 'B') {
				if (!q.empty()) continue;
				if (o) {
					if (i == sx) {
						q.push({ Node(sx, sy), 1 });
						check[sx][sy][1] = true;
					}
					else {
						q.push({ Node(sx, sy), 0 });
						check[sx][sy][0] = true;
					}
				}
				else {
					o = true;
					sx = i;
					sy = j;
				}
			}
			else if (x == 'E')
				p[i][j] = 2;
			else if(x == '1')
				p[i][j] = 1;
		}
	}

	int ans = 0;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		int x = now.FS.x;
		int y = now.FS.y;
		int dir = now.SD;
		if (p[x][y] == 2) {
			if (dir == 1 && p[x][y + 1] == 2 && p[x][y+2] == 2) {
				ans = dist[x][y][1];
				break;
			}
			else if (dir == 0 && p[x + 1][y] == 2 && p[x+2][y] == 2) {
				ans = dist[x][y][0];
				break;
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (dir == 0 && 0 < nx && nx + 2 < n + 1 && 0 < ny && ny < n + 1) {
				if (!check[nx][ny][dir] && p[nx][ny] != 1 && p[nx + 1][ny] != 1 && p[nx + 2][ny] != 1) {
					check[nx][ny][dir] = true;
					q.push({ Node(nx, ny), dir });
					dist[nx][ny][dir] = dist[x][y][dir] + 1;
				}
			}
			else if (dir == 1 && 0 < nx && nx < n + 1 && 0 < ny && ny + 2 < n + 1) {
				if (!check[nx][ny][dir] && p[nx][ny] != 1 && p[nx][ny + 1] != 1 && p[nx][ny + 2] != 1) {
					check[nx][ny][dir] = true;
					q.push({ Node(nx, ny), dir });
					dist[nx][ny][dir] = dist[x][y][dir] + 1;
				}
			}
		}
		if (dir == 0 && 0 < x && x + 2 < n + 1 && 1 < y && y < n) {
			int cs = x + 1, cy = y;
			if (p[cs - 1][cy - 1] != 1 && p[cs][cy - 1] != 1 && p[cs + 1][cy - 1] != 1 && p[cs - 1][cy + 1] != 1 && p[cs][cy + 1] != 1 && p[cs + 1][cy + 1] != 1) {
				if (!check[cs][cy - 1][!dir]) {
					dist[cs][cy - 1][!dir] = dist[x][y][dir] + 1;
					check[cs][cy - 1][!dir] = true;
					q.push({ Node(cs, cy - 1), !dir });
				}
			}
		}
		if (dir == 1 && 1 < x && x < n && 0 < y && y + 2 < n + 1) {
			int cs = x, cy = y + 1;
			if (p[cs - 1][cy - 1] != 1 && p[cs - 1][cy] != 1 && p[cs - 1][cy + 1] != 1 && p[cs + 1][cy - 1] != 1 && p[cs + 1][cy] != 1 && p[cs + 1][cy + 1] != 1) {
				if (!check[cs - 1][cy][!dir]) {
					dist[cs - 1][cy][!dir] = dist[x][y][dir] + 1;
					check[cs - 1][cy][!dir] = true;
					q.push({ Node(cs - 1, cy), !dir });
				}
			}
		}
	}
	cout << ans;
}

