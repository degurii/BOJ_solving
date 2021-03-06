/*
자연수 N개와 질문 M개가 모두 주어졌을 때, 명우의 대답을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수열의 크기 N (1 ≤ N ≤ 2,000)이 주어진다.
둘째 줄에는 홍준이가 칠판에 적은 수 N개가 순서대로 주어진다. 칠판에 적은 수는 100,000보다 작거나 같은 자연수이다.
셋째 줄에는 홍준이가 한 질문의 개수 M (1 ≤ M ≤ 1,000,000)이 주어진다.
넷째 줄부터 M개의 줄에는 홍준이가 명우에게 한 질문 S와 E가 한 줄에 하나씩 주어진다.

출력
총 M개의 줄에 걸쳐 홍준이의 질문에 대한 명우의 답을 입력으로 주어진 순서에 따라서 출력한다.
팰린드롬인 경우에는 1, 아닌 경우에는 0을 출력한다.
*/
#include <iostream>
using namespace std;

int n, m, p[2001], d[2001][2001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		d[i][i] = 1;
	}
	for (int i = 0; i < n - 1; i++)
		if (p[i] == p[i + 1]) d[i][i + 1] = 1;
	
	for (int k = 3; k < n + 1; k++) {
		for (int i = 0; i + k - 1 < n; i++) {
			int j = i + k - 1;
			if (d[i + 1][j - 1] == 1 && p[i] == p[j]) d[i][j] = 1;
		}
	}
	
	cin >> m;
	int s, e;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << d[s-1][e-1] << '\n';
	}
}