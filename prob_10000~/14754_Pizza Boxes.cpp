/*
입력
Your program is to read from standard input.
The input contains two integers, n and m (1 ≤ n, m ≤ 1,000), the number of rows and columns in the grid, respectively.
Each of the following n lines contain m integers, the number of pizza boxes (heights) in the corresponding row.
All heights are between 0 and 109 inclusive and the heights are all different.

출력
Your program is to write to standard output. Print exactly one line for the input. 
The line should contain the maximum number of pizza boxes that can be removed without changing the original views.
*/
#include <iostream>
using namespace std;
using ll = long long;

int n, m;
ll p[1001][1001], tmp[1001][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> p[i][j];

	for (int i = 0; i < n; i++) {
		int max = -1, pos = -1;
		for (int j = 0; j < m; j++) {
			if (max < p[i][j]) {
				max = p[i][j];
				pos = j;
			}
		}
		tmp[i][pos] = max;
	}
	for (int j = 0; j < m; j++) {
		int max = -1, pos = -1;
		for (int i = 0; i < n; i++) {
			if (max < p[i][j]) {
				max = p[i][j];
				pos = i;
			}
		}
		tmp[pos][j] = max;
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!tmp[i][j])
				ans += p[i][j];
		}
	}
	cout << ans;
}