#include <iostream>
using namespace std;
int n;
int main() {
	int prev = -1;
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> n, n != 0) {
		prev = -1;
		while (n--) {
			int x;
			cin >> x; if (x != prev)cout << x << ' '; prev = x;
		}cout << "$\n";
	}
}