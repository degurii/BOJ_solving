/*
문제
n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다.
이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다.
그러면서 동전의 개수가 최소가 되도록 하려고 한다. (각각의 동전은 몇개라도 사용할 수 있다.)

입력
첫째줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000)
다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 자연수이다.

출력
첫째줄에 사용한 동전의 최소 개수를 출력한다. 불가능한 경우에는 -1을 출력한다.
*/
#include <iostream>
using namespace std;

int min(int a, int b) { return a < b ? a : b; }
int n, k;
int p[101], d[10001];
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 1; i < k + 1; i++) d[i] = 0x3f3f3f3f;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < k + 1; j++) {
			if (j - p[i] >= 0) {
				d[j] = min(d[j], d[j - p[i]] + 1);
			}
		}
	}
	if (d[k] == 0x3f3f3f3f) d[k] = -1;
	cout << d[k];
}