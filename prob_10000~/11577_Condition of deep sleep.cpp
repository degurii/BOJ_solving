/*
문제
준형이를 도와 최소한의 버튼 조작으로 모든 전구를 끌 수 있는 프로그램을 작성하자.

입력
입력의 첫 줄에는 특별한 전구의 개수 N(1 ≤ N ≤ 100,000)과 한 번의 버튼 조작으로 상태를 반전시킬 수 있는 전구의 개수 K(1 ≤ K ≤ N)가 주어진다.
다음 줄에는 N개의 Si가 공백을 기준으로 주어진다.
Si는 i(1 ≤ i ≤ N)번째 전구의 상태를 나타내며 1은 전구가 켜져 있는 것을, 0은 전구가 꺼져있는 것을 의미한다.

출력
모든 전구를 끌 수 있는 최소한의 버튼의 조작 횟수를 출력한다.
한 번의 조작은 정확히 연속된 K개 전구의 상태를 반전시킬 수 있음에 유의한다.
만약 어떠한 조작으로도 모든 전구를 끄는 것이 불가능하다면 “Insomnia”(따옴표는 제외)를 출력한다.
*/







/*
solution:

어떤 전구에서 버튼을 조작하면 그 전구를 포함해서 앞의 k개 전구의 상태가 바뀐다고 가정한다.
앞에서부터 k번째 전구부터 보는데,
현재 보는 전구에서 영향을 미칠 수 있는 전구중 가장 처음 전구를 끌 수 있는 방법은 오직 하나이다(처음 전구가 0이면 누르지 않고, 1이면 누른다)
버튼을 조작하는 순서는 상관이 없으므로(독립적) 왼쪽부터 순서대로 판단하면 된다

사실 이렇게 풀면 O(NK)로 tle받을 거 같았는데 통과는 된다(수행시간은 1초에 근접할 만큼 크긴 하다)
O(N)으로 수행시간 0에 가깝게 푸는 코드들도 많던데 그거보고 공부해봐야할듯
*/
#include <iostream>
using namespace std;

int p[100001], n, k;
void change(int idx, int &cnt) {
	cnt++;
	for (int i = idx - k + 1; i < idx + 1; i++) {
		p[i] ^= 1;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i < n + 1; i++) {
		cin >> p[i];
	}
	int cnt = 0;
	for (int i = k; i < n + 1; i++) {
		if (p[i - k + 1] != 0) {
			change(i, cnt);
		}
	}
	for (int i = n - k + 2; i < n + 1; i++) {
		if (p[i] != 0) {
			cout << "Insomnia";
			return 0;
		}
	}
	cout << cnt;
}