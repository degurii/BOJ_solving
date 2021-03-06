/*
가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 이동할 수 있는 경로의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 게임 판의 크기 N (4 ≤ N ≤ 100)이 주어진다.
그 다음 N개 줄에는 각 칸에 적혀져 있는 수가 N개씩 주어진다.
칸에 적혀있는 수는 0보다 크거나 같고, 9보다 작거나 같은 정수이며, 가장 오른쪽 아래 칸에는 항상 0이 주어진다.

출력
가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 문제의 규칙에 맞게 갈 수 있는 경로의 개수를 출력한다. 경로의 개수는 263-1보다 작거나 같다.
*/
#include <iostream>
using namespace std;
using ll = long long;

int n;
ll p[101][101], d[101][101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
		}
	}
	d[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (p[i][j] == 0) continue;
			if (i + p[i][j] < n) d[i + p[i][j]][j] += d[i][j];
			if (j + p[i][j] < n) d[i][j + p[i][j]] += d[i][j];
		}
	}
	cout << d[n - 1][n - 1];
}