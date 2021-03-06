/*
문제
행렬 N개의 크기가 주어졌을 때, 모든 행렬을 곱하는데 필요한 곱셈 연산 횟수의 최소값을 구하는 프로그램을 작성하시오.
입력으로 주어진 행렬의 순서를 바꾸면 안된다.

입력
첫째 줄에 행렬의 개수 N(1 ≤ N ≤ 500)이 주어진다.
둘째 줄부터 N개 줄에는 행렬의 크기 r과 c가 주어진다. (1 ≤ r, c ≤ 500)
항상 순서대로 곱셈을 할 수 있는 크기만 입력으로 주어진다.

출력
첫째 줄에 입력으로 주어진 행렬을 곱하는데 필요한 곱셈 연산의 최소값을 출력한다.
정답은 231-1 보다 작거나 같은 자연수이다. 또한, 최악의 순서로 연산해도 연산 횟수가 231-1보다 작거나 같다.
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

int n, p[501], d[501][501];
int foo(int i, int j) {
	if (i == j) return 0;
	if (d[i][j] != -1) return d[i][j];
	d[i][j] = INF;
	for (int k = i; k + 1 <= j; k++) {
		d[i][j] = min(d[i][j], foo(i, k) + foo(k + 1, j) + p[i - 1] * p[k] * p[j]);
	}
	return d[i][j];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; i++) {
		cin >> p[i] >> p[i + 1];
	}
	
	cout << foo(1, n);
}