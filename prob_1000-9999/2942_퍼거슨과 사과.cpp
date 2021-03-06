/*
퍼거슨이 사과를 나누어 주는 방법을 구하는 프로그램을 작성하시오. 훈련장에 선수는 무한히 많다.

입력
첫째 줄에 R과 G가 주어진다. (1 ≤ R, G ≤ 1,000,000,000)

출력
퍼거슨이 사과를 나누어 주는 방법을 출력한다.
방법을 출력할 때는 사과를 받게되는 선수의 수 N과 나누어 주는 빨간 사과의 수 X와 초록 사과의 수 Y를 출력한다.
각 방법은 한 번만 출력해야 한다. 나누어 주는 방법은 아무 순서로 출력해도 된다.
*/
#include <iostream>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
int main(){
	int a, b;
	cin >> a >> b;
	ll g = gcd(a, b);
	for (int i = 1; i*i <= g; i++) {
		if (g%i == 0) {
			cout << i << ' ' << a / i << ' ' << b / i << '\n';
			if (i*i < g)
				cout << g / i << ' ' << a / (g / i) << ' ' << b / (g / i) << '\n';
		}
	}
}

