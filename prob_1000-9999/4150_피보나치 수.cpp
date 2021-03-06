#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string operator +(const string &a, const string &b) {
	string ans;
	int i = a.size() - 1;
	int j = b.size() - 1;
	int carry = 0;
	while (i >= 0 && j >= 0) {
		int numa = a[i] - '0';
		int numb = b[j] - '0';
		int x = numa + numb + carry;
		carry = x / 10;
		x %= 10;
		ans += to_string(x);
		i--;
		j--;
	}
	while (i >= 0) {
		int numa = a[i] - '0';
		int x = numa + carry;
		carry = x / 10;
		x %= 10;
		ans += to_string(x);
		i--;
	}
	while (j >= 0) {
		int numb = b[j] - '0';
		int x = numb + carry;
		carry = x / 10;
		x %= 10;
		ans += to_string(x);
	}
	if (carry)
		ans += "1";
	
	reverse(ans.begin(), ans.end());
	return ans;
}

string d[100000] = { "0", "1" };
int main() {
	int n;
	cin >> n;

	for (int i = 2; i < n + 1; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	cout << d[n];
}