/*
문제
다섯 개의 자연수가 있다. 이 수의 적어도 대부분의 배수는 위의 수 중 적어도 세 개로 나누어 지는 가장 작은 자연수이다.
서로 다른 다섯 개의 자연수가 주어질 때, 적어도 대부분의 배수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 다섯 개의 자연수가 주어진다. 100보다 작거나 같은 자연수이고, 서로 다른 수이다.

출력
첫째 줄에 적어도 대부분의 배수를 출력한다.
*/
#include <iostream>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}
int p[5];
int main() {
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < 5; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				int g = gcd(p[i], p[j]);
				int l = p[i] * p[j] / g;
				g = gcd(l, p[k]);
				l = l * p[k] / g;
				ans = ans < l ? ans : l;
			}
		}
	}
	cout << ans;
}