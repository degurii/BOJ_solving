/*
입력
첫째 줄에 음이 아닌 정수로 이루어진 수식이 주어진다. 이 수식은 괄호가 올바르게 쳐져있다.
숫자, '+', '*', '-', '/', '(', ')'로만 이루어져 있다. 수식의 길이는 최대 200이고, 괄호 쌍은 적어도 1개, 많아야 10개이다.

출력
올바른 괄호 쌍을 제거해서 나올 수 있는 서로 다른 식을 사전 순으로 출력한다.
*/
#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

string s;
vector<pair<int, int>> brackets;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;
	stack<int> st;
	for (int i = 0; s[i]; i++) {
		if (s[i] == '(')
			st.push(i);
		else if (s[i] == ')') {
			brackets.push_back({ st.top(), i });
			st.pop();
		}
	}
	sort(brackets.begin(), brackets.end());
	reverse(brackets.begin(), brackets.end());
	
	set<string> ans;
	for (int i = 1, n = brackets.size(); i < (1 << n); i++) {
		int p[300] = { 0, };
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				p[brackets[j].first] = p[brackets[j].second] = 1;
			}
		}
		string a;
		for (int i = 0; s[i]; i++) {
			if (!p[i])
				a = a + s[i];
		}
		ans.insert(a);
	}
	for (string a : ans) {
		cout << a << '\n';
	}
}