/*
문제
상렬이에게는 히스토그램 모양의 플라스틱 퍼즐 조각이 많이 있다.
퍼즐의 모양이 주어질 때 자를 수 있는 가장 큰 직사각형의 넓이를 구하는 프로그램을 작성하라.
히스토그램의 정보는 히스토그램을 구성하는 직사각형들의 높이로 주어진다.
각 직사각형의 너비는 1로 모두 같다.

입력
히스토그램을 구성하는 직사각형의 개수 N(1 ≤ N ≤ 100,000)이 주어진다.
이어 N개의 줄에 걸쳐 각 직사각형의 높이인 정수 Hi(1 ≤ Hi ≤ 1,000,000)가 주어진다.

출력
잘라낼 수 있는 직사각형의 최대 넓이를 출력하라.
*/



#include <iostream>
#include <stack>
using namespace std;
#define FST first
#define SND second
using ll = long long;

ll max(int a, int b) { return (a > b) ? a : b; }
stack<pair<ll, int> > s;
int p[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
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
	cout << ans;
}