/*
입력
In the first line, the number of stops (2≤n≤5000) is given.
In the second line, the coordinates A1, ..., An (0≤Ai≤32800000) of each stop are given. There is no duplicate of each number.

출력
Two integers are output, the first integer is the minimum distance and the second integer is the number of pairs of two stops with this distance.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int n;
vector<ll> p;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	p.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	ll dist = 0x3f3f3f3f;
	sort(p.begin(), p.end());
	for (auto it = p.begin(); it != p.end() - 1; it++) 
		dist = min(dist, *upper_bound(it + 1, p.end(), *it) - *it);

	int cnt = 0;
	//x  == dist + y
	for (auto it = p.begin(); it != p.end() - 1; it++) {
		ll x = *lower_bound(it + 1, p.end(), *it);
		if (x == dist + *it) cnt++;
	}
	cout << dist << ' ' << cnt;
}
