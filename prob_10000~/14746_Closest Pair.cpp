/*
입력
Your program is to read from standard input. The input consists of four lines.
The first line contains two integers, n (1 ≤ n ≤ 500,000) and m (1 ≤ m ≤ 500,000),
where n is the number of points in set P and m is the number of points in set Q.
In the second line, two integers c1 and c2 (-108 ≤ c1, c2 ≤ 108) are given in order, separated by a single space.
In the third line, n distinct integers between -108 and 108, inclusively, are given, separated by a single space,
that are the x-coordinates of the points in set P, while their y- coordinates are all the same as c1.
In the fourth line, m distinct integers between -108 and 108, inclusively, are given, separated by a single space,
that are the x-coordinates of the points in set Q, while their y- coordinates are all the same as c2.

출력
Your program is to write to standard output. Print exactly one line for the input.
The line should contain two integers, separated by a single space,
that represent the distance between a closest pair of P and Q and the number of closest pairs of P and Q in this order.
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

int a[500001], b[500001];
int n, m, c1, c2;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m >> c1 >> c2;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	int ans = 0x3f3f3f3f, num = 0;
	for (int i = 0, j = 0; i < n && j < m;) {
		if (ans > abs(a[i] - b[j])) {
			ans = abs(a[i] - b[j]);
			num = 1;
		}
		else if (ans == abs(a[i] - b[j]))
			num++;
		if (a[i] < b[j])
			i++;
		else
			j++;
	}
	cout << ans + abs(c1 - c2) << ' ' << num;
}