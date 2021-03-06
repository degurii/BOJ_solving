/*
K의 값을 찾아보도록 하자.

입력
총 불꽃의 수 N이 주어진다. (3 ≤ N ≤ 10101)

출력
K의 값을 출력한다. 이 값은 정수임이 보장되며, 불가능한 경우는 입력으로 주어지지 않는다.
*/


/*
solution:
ans = 1 + k + k^2
	= 1 + k(k+1)

k를 올려가며 찾으면 된다
*/
#include <iostream>
using namespace std;

int n;
int main() {
	cin >> n;
	for (int k = 1; 1; k++) {
		if (k*(k + 1) + 1 == n) {
			cout << k;
			return 0;
		}
	}
}