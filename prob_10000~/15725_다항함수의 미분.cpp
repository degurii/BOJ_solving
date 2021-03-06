/*
문제
다항식(polynomial)은 문자의 거듭제곱의 상수 배들의 합을 표현하는 수식이다.
예를 들어 x2 - 2x + 3 같은 식을 의미한다. 그 중 변수가 하나인 것을 일변수 다항식이라고 하고 보통 다음과 같이 표현한다.

f(x) = anxn + an-1xn-1 + ... + a2x2 + a1x + a0

최대 일차 일변수 다항식이 주어졌을 때 그 함수를 미분한 결과를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 최대 일차 일변수 다항식이 주어진다. 항의 개수는 최대 2개이고, 변수는 항상 x로 주어지며, 각 항은 공백 문자로 구분되지 않는다.
주어지는 계수와 상수의 절댓값은 10,000을 넘지 않는 정수이다. 단, 계수의 절댓값이 1인 경우에는 계수를 생략한다.

다항식은 계수가 큰 것부터 작아지는 순서대로 주어진다.

출력
주어진 일변수 다항식을 미분한 결과를 출력한다.
*/
#include <iostream>
#include <string>
using namespace std;

string s;
int main() {
	cin >> s;
	int ans = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] == 'x') {
			if (s[0] == '-') {
				if (i == 1)
					ans = -1;
				else
					ans = -stoi(s.substr(1, i));
			}
			else {
				if (i == 0)
					ans = 1;
				else
					ans = stoi(s.substr(0, i));
			}
			break;
		}
	}
	cout << ans;
}