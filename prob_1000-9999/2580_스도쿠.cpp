/*
게임 시작 전 스도쿠 판에 쓰여 있는 숫자들의 정보가 주어질 때 모든 빈 칸이 채워진 최종 모습을 출력하는 프로그램을 작성하시오.

입력
아홉 줄에 걸쳐 한 줄에 9개씩 게임 시작 전 스도쿠판 각 줄에 쓰여 있는 숫자가 한 칸씩 띄워서 차례로 주어진다.
스도쿠 판의 빈 칸의 경우에는 0이 주어진다. 스도쿠 판을 규칙대로 채울 수 없는 경우의 입력은 주어지지 않는다.

출력
모든 빈 칸이 채워진 스도쿠 판의 최종 모습을 아홉줄에 걸쳐 한 줄에 9개씩 한 칸씩 띄워서 출력한다.
스도쿠 판을 채우는 방법이 여럿인 경우는 그 중 하나만을 출력한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> pos;
vector<int> ans;
int p[10][10];
int check1[10], check2[10], check3[10]; // 1: 정사각형, 2: 행, 3: 열


bool foo(int idx) {
	if (idx == pos.size()) {
		return true;
	}
	int x = pos[idx].first, y = pos[idx].second;
	
	int d = (x / 3) * 3 + y / 3;
	
	for (int i = 1; i < 10; i++) {
		int bit = (1 << i);
		int v1 = (check1[d] & bit);
		int v2 = (check2[x] & bit);
		int v3 = (check3[y] & bit);
		if (v1 & v2 & v3) {
			ans.push_back(i);
			check1[d] &= ~bit;
			check2[x] &= ~bit;
			check3[y] &= ~bit;
			if (foo(idx + 1)) {
				return true;
			}
			check1[d] |= bit;
			check2[x] |= bit;
			check3[y] |= bit;
			ans.pop_back();
		}
	}

	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 9; i++) {
		check1[i] = check2[i] = check3[i] = (1 << 10) - 1;
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> p[i][j];
			if (!p[i][j]) {
				pos.emplace_back(i, j);
			}
			else {
				int idx = (i / 3) * 3 + j / 3;
				int bit = (1 << p[i][j]);
				check1[idx] &= ~bit;
				check2[i] &= ~bit;
				check3[j] &= ~bit;
			}
		}
	}
	foo(0);
	
	int idx = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (p[i][j]) cout << p[i][j] << ' ';
			else cout << ans[idx++] << ' ';
		}
		cout << '\n';
	}
}