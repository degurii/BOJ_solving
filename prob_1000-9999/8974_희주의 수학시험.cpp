#include <iostream>
using namespace std;

int a, b;
int main() {
	cin >> a >> b;
	int ans = 0;
	for (int i = 1, cnt = 0; i < 50; i++) {
		for (int j = 0; j < i; j++) {
			++cnt;
			if (a <= cnt && cnt <= b) {
				ans += i;
			}
			else if (b < cnt) break;
		}
		if (b < cnt) break;
	}
	cout << ans;
}