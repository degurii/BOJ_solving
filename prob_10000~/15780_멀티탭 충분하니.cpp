/*
입력
입력의 첫째 줄에 스터디에 온 학생의 수 N(1 ≤ N ≤ 100)명 콘센트의 수 K(1 ≤ K ≤ 100)가 주어진다.
이후 두번째 줄에 각 멀티탭의 구의 수 A[i](3 ≤ A[i] ≤ 8) 가 주어진다.

출력
모든 사람이 멀티탭에 코드를 꽂을 수 있는경우 “YES” 아니라면 “NO”를 출력한다.
*/
#include <iostream>
using namespace std;

int n, k;
int main() {
	cin >> n >> k;
	while (k--) {
		int x;
		cin >> x;
		n -= ((x + 1) / 2);
	}
	if (n <= 0) cout << "YES";
	else cout << "NO";
}