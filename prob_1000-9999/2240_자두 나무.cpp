/*
문제
자두는 T(1≤T≤1,000)초 동안 떨어지게 된다. 자두는 최대 W(1≤W≤30)번만 움직이고 싶어 한다.
매 초마다 어느 나무에서 자두가 떨어질지에 대한 정보가 주어졌을 때, 자두가 받을 수 있는 자두의 개수를 구해내는 프로그램을 작성하시오.
자두는 1번 자두나무 아래에 위치해 있다고 한다.

입력
첫째 줄에 두 정수 T, W가 주어진다. 다음 T개의 줄에는 각 순간에 자두가 떨어지는 나무의 번호가 1 또는 2로 주어진다.

출력
첫째 줄에 자두가 받을 수 있는 자두의 최대 개수를 출력한다.
*/
#include <iostream>
#include <cstring>
using namespace std;

int t, w;
int p[1001], d[1001][31];
int max(int a, int b) { return a > b ? a : b; }
int go(int sec, int turn) {
	if (sec == t + 1 && turn <= w) return 0;
	if (turn > w) return 0;
	
	int &val = d[sec][turn];
	if (val != -1) return val;
	val = 0;
	val = max(go(sec + 1, turn), go(sec + 1, turn + 1)) + (turn % 2 + 1 == p[sec]);
	return val;
}
int main() {
	cin >> t >> w;
	memset(d, -1, sizeof(d));
	for (int i = 1; i < t + 1; i++) {
		cin >> p[i];
	}
	cout << go(0, 0);
} 