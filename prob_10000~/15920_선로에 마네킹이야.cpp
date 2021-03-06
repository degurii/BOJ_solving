/*
당신은 이 상황을 시뮬레이션하면서 어떤 선택이 당신의 윤리관에 가장 잘 맞는지 알아 보려고 한다.
물론 묶여 있는 게 사람이 아니라 마네킹이긴 하지만...

입력
첫째 줄에 문자열의 길이 N (1 ≤ N ≤ 10) 이 주어진다.
둘째 줄에 문자열 S가 주어진다. S는 글자 “W”와 “P”로만 이루어져 있다.
이는 당신의 행동을 순서대로 나타내며, “W”는 1초 기다리는 행동, “P”는 레버를 당기는 행동을 의미한다.

출력
모든 행동이 끝난 순간까지 깔린 마네킹의 수를 출력한다.
광차가 C구역으로 이동하기 전에 행동이 끝나면 아무 마네킹도 깔리지 않음에 유의하라.
*/
#include <iostream>
#include <string>
using namespace std;

string s;
int main() {
	int n;
	cin >> n;
	cin >> s;
	int w = 0, state = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] == 'W') {
			if (++w == 2) {
				if (state == 0) cout << 5;
				else if(state == 1) cout << 1;
				else cout << 6;
				return 0;
			}
			
		}
		else if (s[i] == 'P') {
			if(state < 2) state ^= 1;
			if (w == 1) {
				state = 2;
			}
		}
	}
	cout << 0;
}