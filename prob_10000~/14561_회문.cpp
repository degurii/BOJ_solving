/*
문제
어떤 십진수의 수 A가 주어졌을 때, 이를 n진수로 표현하면 회문인지 아닌지 판별하는 프로그램을 만드시오.

입력
첫째 줄에 테스트 케이스의 수 T(1≤T≤1000)이 주어진다.
둘째 줄부터 T줄에 걸쳐 테스트 케이스별로 어떤 십진수의 수 A(1≤A≤100000000000)와 n(2≤n≤16)이 공백을 두고 주어진다.

출력
각 줄마다 테스트 케이스가 회문일 경우 1, 아닐 경우에는 0을 출력한다
*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int t;
ll a, n;
bool foo(ll a, ll n) {
	vector<int> p;
	while (a > 0) {
		p.push_back(a%n);
		a /= n;
	}
	bool bar = true;
	for(int i=0, l = p.size(); i<l/2; i++){
		if (p[i] != p[l - i - 1]) {
			bar = false;
			break;
		}
	}
	return bar;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> t;
	while (t--) {
		cin >> a >> n;
		if (foo(a, n)) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}