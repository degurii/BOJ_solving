/*
입력
첫 번째 줄에 카드의 개수를 나타내는 수 n(2 ≤ n ≤ 1,000)과 카드 합체를 몇 번 하는지를 나타내는 수 m(0 ≤ m ≤ 15×n)이 주어진다.
두 번째 줄에 맨 처음 카드의 상태를 나타내는 n개의 자연수 a1, a2, …, an이 공백으로 구분되어 주어진다. (1 ≤ ai ≤ 1,000,000)

출력
첫 번째 줄에 만들 수 있는 가장 작은 점수를 출력한다.
*/
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	priority_queue<ll> pq;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		pq.push(-x);
	}
	while (m--) {
		ll x = pq.top();
		pq.pop();
		ll y = pq.top();
		pq.pop();
		pq.push(x + y);
		pq.push(x + y);
	}
	ll ans = 0;
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
	cout << -ans;
}