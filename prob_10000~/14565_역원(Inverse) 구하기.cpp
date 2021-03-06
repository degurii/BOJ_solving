/*
문제
집합 Zn을 0부터 n-1까지의 정수 집합이라고 하자. Zn ∋ a, b 일 때, (a+b) mod n = 0이면 b는 a의 덧셈역이라고 하고 (a*c) mod n = 1이면 c는 a의 곱셈역이라고 한다.
정수 N, A가 주어졌을 때 Zn에서의 A의 덧셈역과 곱셈역을 구하시오.
(단, 곱셈역을 구할 수 없으면 -1을 출력한다.)

입력
첫 번째 줄에 N(2≤N≤10^12)과 A(1≤A<N)이 주어진다..

출력
첫 번째 줄에 A의 N에 대한 덧셈역과 곱셈역을 한 줄에 공백으로 구분하여 출력한다.
*/


/*
solution:
확장 유클리드 코드는
http://blog.myungwoo.kr/55?category=517571 를 참고함
*/
#include <iostream>
using namespace std;
using ll = long long;

ll exgcd(ll a, ll b, ll &s, ll &t) {
	if (b == 0) {
		s = 1, t = 0;
		return a;
	}
	ll q = a / b, r = a % b, sp = 0, tp = 0;
	ll g = exgcd(b, r, sp, tp);
	s = tp;
	t = sp - tp * q;
	return g;
}
int main() {
	ll n, a;
	cin >> n >> a;
	cout << n - a << ' ';
	ll x = 0, y = 0;
	ll g = exgcd(a, n, x, y);
	x = (x + n) % n;
	if (g != 1) cout << -1;
	else {
		cout << x;
	}
}