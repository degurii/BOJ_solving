/*
지도가 주어질 때 이와 같이 제일 왼쪽 위 지점에서 출발하여 제일 오른쪽 아래 지점까지 항상 내리막길로만 이동하는 경로의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 지도의 세로의 크기 M과 가로의 크기 N이 빈칸을 사이에 두고 주어진다.
이어 다음 M개 줄에 걸쳐 한 줄에 N개씩 위에서부터 차례로 각 지점의 높이가 빈 칸을 사이에 두고 주어진다.
M과 N은 각각 500이하의 자연수이고, 각 지점의 높이는 10000이하의 자연수이다.

출력
첫째 줄에 이동 가능한 경로의 수 H를 출력한다.
모든 입력에 대하여 H는 10억 이하의 음이 아닌 정수이다.
*/
#include <iostream>
#include <cstring>
using namespace std;

int m, n, p[501][501], d[501][501];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
int go(int x, int y) {
	if (x == m && y == n) return 1;
	
	int &val = d[x][y];
	if (val >= 0) return val;
	val = 0;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		if (0 < nx && nx < m + 1 && 0 < ny && ny < n + 1) {
			if (p[x][y] > p[nx][ny]) val += go(nx, ny);
		}
	}
	return val;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n;
	memset(d, -1, sizeof(d));
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> p[i][j];
		}
	} 
	
	cout << go(1, 1);
}