/*
입력
입력의 첫째 줄에 의자가 놓인 행과 열의 수 N(1 ≤ N ≤ 1000)이 주어지고 ,진서가 앉은 의자가 위치한 행 a, 열 b가 주어진다.
이후 두번째 줄부터 N+1 줄까지 강의실에 앉아있는 학생들의 매력지수 X[i][j](1 ≤ X ≤ 50000)가 주어진다. X[i][j] 는 i행 j열에 앉은 학생의 매력지수이다.

출력
진서가 자기보다 잘생긴 사람을 본다면 ANGRY, 아니라면 HAPPY를 출력한다.
*/
#include <iostream>
using namespace std;

int n, p[1001][1001];
int x, y;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	cin >> x >> y;
	x--; y--;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		if (p[i][y] > p[x][y]) {
			cout << "ANGRY";
			return 0;
		}
		if (p[x][i] > p[x][y]) {
			cout << "ANGRY";
			return 0;
		}
	}
	cout << "HAPPY";
}