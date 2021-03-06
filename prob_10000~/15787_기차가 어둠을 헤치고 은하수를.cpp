/*
문제
처음에 주어지는 기차에는 아무도 사람이 타지 않는다.
은하수를 건널 수 있는 기차의 수를 출력하시오.

입력
입력의 첫째 줄에 기차의 수 N(1 ≤ N ≤ 100000)과 명령의 수 M(1 ≤ M ≤ 100000)가 주어진다.
이후 두번째 줄부터 M+1번째 줄까지 각 줄에 명령이 주어진다.

출력
은하수를 건널 수 있는 기차의 수를 출력하시오.
*/


/*
solution:
대놓고 비트마스킹 문제
*/
#include <iostream>
using namespace std;

int n, m;
int p[100000];
bool check[3000000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	int cmd, k, x;
	for (int i = 0; i < m; i++) {
	/*
		1 i x: p[i]|=(1<<x)
		2 i x: p[i] &= ~(1<<x)
		3 i: p[i]<<=1
		4 i: p[i]>>=1
	*/
		cin >> cmd >> k;
		if (cmd == 1 || cmd == 2) {
			cin >> x;
			if (cmd == 1)
				p[k] |= (1 << (x - 1));
			else
				p[k] &= ~(1 << (x - 1));
		}
		else if (cmd == 3) {
			p[k] <<= 1;
			p[k] &= ~(1 << 20);
		}
		else {
			p[k] >>= 1;
		}
	}
	int ans = 0;
	for (int i = 1; i < n + 1; i++) {
		if (!check[p[i]])
			ans++;
		check[p[i]] = true;
	}
	cout << ans;
}
