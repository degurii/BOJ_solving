/*
입력
첫째 줄에는 주문한 버거의 갯수 B, 사이드 메뉴의 갯수 C, 음료의 갯수 D가 공백을 사이에 두고 순서대로 주어진다. (1 ≤ B, C, D ≤ 1,000)
둘째 줄에는 각 버거의 가격이 공백을 사이에 두고 주어진다.
셋째 줄에는 각 사이드 메뉴의 가격이 공백을 사이에 두고 주어진다.
넷째 줄에는 각 음료의 가격이 공백을 사이에 두고 주어진다.
각 메뉴의 가격은 100의 배수이며, 10000원을 넘지 않는다.



출력
첫째 줄에는 세트 할인이 적용되기 전 가격을 출력한다.
둘째 줄에는 세트 할인이 적용된 후의 최소 가격을 출력한다.
*/
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

vector<int> a, b, c;
int x, y, z;
int ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> x >> y >> z;
	int k;
	for (int i = 0; i < x; i++) {
		cin >> k;
		ans += k;
		a.push_back(k);
	}
	for (int i = 0; i < y; i++) {
		cin >> k;
		ans += k;
		b.push_back(k);
	}
	for (int i = 0; i < z; i++) {
		cin >> k;
		ans += k;
		c.push_back(k);
	}
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	sort(c.begin(), c.end(), greater<int>());
	cout << ans << '\n';
	for (int i = 0; 1; i++) {
		if (!(i < x && i < y && i < z))
			break;
		ans -= a[i] / 10 + b[i] / 10 + c[i] / 10;
	}
	cout << ans;

}