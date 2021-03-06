/*
문제
몇 일이 지나야 백조들이 만날 수 있는 지 계산하는 프로그램을 작성한다.

입력
입력의 첫째 줄에는 R과 C가 주어진다. 단, 1 ≤ R, C ≤ 1500.
각 R줄 동안 C만큼의 문자열이 주어진다.
'.'은 물 공간, 'X'는 빙판 공간, 'L'은 백조가 있는 공간으로 나타낸다.

출력
첫째 줄에 문제에서 주어진 걸리는 날을 출력한다.
*/

/*
solution:
전처리로 빙하가 며칠째에 녹는지를 저장해놓는다.
이분탐색으로 0 ~ 2*N일 이상사이에서
lower bound를 구한다.
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int r, c, p[1501][1501];
int sx1, sx2, sy1, sy2;
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

bool canMeet(int dist) {
	queue<pair<int, int>> q;
	vector<vector<bool>> check(r + 1, vector<bool>(c + 1));
	q.push({ sx1, sy1 });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == sx2 && y == sy2)
			return true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 < nx && nx < r + 1 && 0 < ny && ny < c + 1) {
				if (!check[nx][ny] && p[nx][ny] <= dist) {
					q.push({ nx, ny });
					check[nx][ny] = true;
				}
			}
		}
	}

	return false;
}

int foo(int l, int r) {
	int ans = 0x3f3f3f3f;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (canMeet(mid)) {
			r = mid - 1;
			if (ans > mid)
				ans = mid;
		}
		else {
			l = mid + 1;
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 1; i < r + 1; i++) {
		for (int j = 1; j < c + 1; j++) {
			char x;
			cin >> x;
			if (x == '.')
				p[i][j] = 0;
			else if (x == 'X')
				p[i][j] = -1;
			else {
				if (sx1 == 0) {
					sx1 = i;
					sy1 = j;
				}
				else {
					sx2 = i;
					sy2 = j;
				}
			}
		}
	}
	
	queue<pair<int, int>> q;
	for (int i = 1; i < r + 1; i++) {
		for (int j = 1; j < c + 1; j++) {
			if (p[i][j] == 0) {
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 < nx && nx < r + 1 && 0 < ny && ny < c + 1) {
				int next = p[nx][ny];
				if (next == -1) {
					p[nx][ny] = p[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}

	cout << foo(0, 4000);
}