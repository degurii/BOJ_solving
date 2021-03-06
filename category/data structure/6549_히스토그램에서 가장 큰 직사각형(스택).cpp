/*
문제
히스토그램에서 가장 큰 직사각형을 구하는 프로그램을 작성하시오.

입력
입력은 테스트 케이스 여러 개로 이루어져 있다.
각 테스트 케이스는 한 줄로 이루어져 있고, 직사각형의 수 n이 가장 처음으로 주어진다. (1 ≤ n ≤ 100,000)
그 다음 n개의 정수 h1, ..., hn (0 ≤ hi ≤ 1000000000)가 주어진다.
이 숫자들은 히스토그램에 있는 직사각형의 높이이며, 왼쪽부터 오른쪽까지 순서대로 주어진다.
모든 직사각형의 너비는 1이고, 입력의 마지막 줄에는 0이 하나 주어진다.

출력
각 테스트 케이스에 대해서, 히스토그램에서 가장 큰 직사각형의 넓이를 출력한다.
*/



#include <iostream>
#include <stack>
using namespace std;
#define FST first
#define SND second
using ll = long long;

ll max(ll a, ll b) { return (a > b) ? a : b; }
int p[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		int n;
		cin >> n;
		if (n == 0) return 0;
		stack<pair<ll, int> > s;

		for (int i = 1; i < n + 1; i++) {
			cin >> p[i];
		}
		ll ans = 0;
		s.push({ 0, 0 });
		for (int i = 1; i < n + 1; i++) {
			while (s.top().FST > p[i]) {
				ll h = s.top().FST;
				ll r = i - 1;
				s.pop();
				ll l = s.top().SND;
				ans = max(ans, (r - l)*h);
			}
			s.push({ p[i], i });
		}
		while (s.size() != 1) {
			ll r = n;
			ll h = s.top().FST;
			s.pop();
			ll l = s.top().SND;
			ans = max(ans, (r - l)*h);
		}
		cout << ans << '\n';
	}
}