/*
입력
첫 번째 줄에는 손님이 구매하고자 하는 피자크기를 나타내는 2,000,000 이하의 자연수가 주어진다.
두 번째 줄에는 A, B 피자의 피자조각의 개수를 나타내 는 정수 m, n 이 차례로 주어진다 ( 3≤m, n≤1000).
세 번째 줄부터 차례로 m 개의 줄에는 피자 A의 미리 잘라진 피자조각의 크기를 나타내는 정수가 주어진다.
그 다음 n 개의 줄에는 차례로 피자B의 미리 잘라진 피자조각의 크기를 나타내는 정수가 주어진다.
각 종류의 피자조각의 크기는 시계방향으로 차례로 주어지며, 각 피자 조각의 크기는 1000 이하의 자연수이다.

출력
첫째 줄에는 피자를 판매하는 방법의 가지 수를 나타내는 정수를 출력한다.
피자를 판매하는 방법이 없는 경우에는 숫자 0을 출력한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> suma(1), sumb(1), a, b;
int m, n, goal;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> goal;
	cin >> n >> m;
	for (int i = 1; i < n + 1; i++) {
		int x;
		cin >> x;
		suma.push_back(suma[i - 1] + x);
	}
	for (int i = 1; i < n; i++) {
		suma.push_back(suma[n] + suma[i]);
	}
	for (int i = 1; i < m + 1; i++) {
		int x;
		cin >> x;
		sumb.push_back(sumb[i - 1] + x);
	}
	for (int i = 1; i < m; i++) {
		sumb.push_back(sumb[m] + sumb[i]);
	}

	a.push_back(suma[n]);
	b.push_back(sumb[m]);
	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			int k = i + j;
			a.push_back(suma[k] - suma[i - 1]);
		}
	}
	for (int i = 1; i < m + 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			int k = i + j;
			b.push_back(sumb[k] - sumb[i - 1]);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	long long ans = 0;
	ans += upper_bound(a.begin(), a.end(), goal) - lower_bound(a.begin(), a.end(), goal);
	ans += upper_bound(b.begin(), b.end(), goal) - lower_bound(b.begin(), b.end(), goal);
	for (int now : a) {
		int k = goal - now;
		ans += upper_bound(b.begin(), b.end(), k) - lower_bound(b.begin(), b.end(), k);
	}
	cout << ans;
}